/**
*   @file    IoDal_Ani.c
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component for analog
*                                      input channels
*   @details This file implements the IODAL interface to application layer to lower layers                  
*            ADC
*            
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup IODAL
*   @{
*/
/*=========================================================================================================================
*   Platform             : ARM
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
============================================================================================================================*/
/*============================================================================================================================
==============================================================================================================================*/


#ifdef __cplusplus
extern "C"{
#endif

/*====================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=====================================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
#include "IoDal_Types.h"
#include "IoDal_Cfg.h"
#include "IoDal_Ani.h"

#ifdef IFRW_DEBUG_PIN		
#include "Dio.h"
#endif
/*====================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=====================================================================================================================*/
#define IODAL_VENDOR_ID_ANI_C                       43

#define IODAL_AR_RELEASE_MAJOR_VERSION_ANI_C        4

#define IODAL_AR_RELEASE_MINOR_VERSION_ANI_C        2

#define IODAL_AR_RELEASE_REVISION_VERSION_ANI_C     2

#define IODAL_SW_MAJOR_VERSION_ANI_C                1
#define IODAL_SW_MINOR_VERSION_ANI_C                0
#define IODAL_SW_PATCH_VERSION_ANI_C                1

/*====================================================================================================================
*                                     FILE VERSION CHECKS
=====================================================================================================================*/
/* Check if source file and IODAL header file are of the same vendor */
#if (IODAL_VENDOR_ID_ANI_C != IODAL_CFG_VENDOR_ID)
    #error "IoDal_Ani.c and IoDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and IODAL header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_ANI_C != IODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_ANI_C != IODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_ANI_C != IODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Ani.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IODAL header file are of the same Software version */
#if ((IODAL_SW_MAJOR_VERSION_ANI_C != IODAL_CFG_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_ANI_C != IODAL_CFG_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_ANI_C != IODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal_Ani.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IODAL IPW header file are from the same vendor */
#if (IODAL_VENDOR_ID_ANI_C != IODAL_ANI_VENDOR_ID)
    #error "IoDal_Ani.c and IoDal_Ani.h have different vendor ids"
#endif

/* Check if source file and IODAL types header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_ANI_C != IODAL_ANI_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_ANI_C != IODAL_ANI_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_ANI_C != IODAL_ANI_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Ani.c and IoDal_Ani.h are different"
#endif

/* Check if source file and IODAL types header file are of the same Software version */
#if ((IODAL_SW_MAJOR_VERSION_ANI_C != IODAL_ANI_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_ANI_C != IODAL_ANI_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_ANI_C != IODAL_ANI_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of IoDal_Ani.c and IoDal_Ani.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((IODAL_AR_RELEASE_MAJOR_VERSION_ANI_C != STD_AR_RELEASE_MAJOR_VERSION) || \
      (IODAL_AR_RELEASE_MINOR_VERSION_ANI_C != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of IoDal_Ani.c and Std_Types.h are different"
 #endif
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((IODAL_AR_RELEASE_MAJOR_VERSION_ANI_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (IODAL_AR_RELEASE_MINOR_VERSION_ANI_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of IoDal_Ani.c and Mcal.h are different"
 #endif 
#endif


typedef enum
{
    ADC_START_STATE  = 0U,        /**< @brief mark No error detected for analog descriptor. */
    ADC_READ_STATE   = 1U,     /**< @brief mark conversion on-going for analog descriptor. */
    ADC_INVALID_STATE               /**< @brief mark conversion as invalid for analog descriptor. */ 
}IoDal_AnalogConvState;


#if IODAL_MAX_ANI_DESCRIPTORS > 0U
/*====================================================================================================================
                                          LOCAL CONSTANTS
=====================================================================================================================*/
P2CONST(IoDal_BswIoConfigType, IODAL_VAR, IODAL_APPL_CONST) IoDal_pAniGlobalCfgPtr = NULL_PTR;

/*====================================================================================================================
                                          LOCAL VARIABLES
=====================================================================================================================*/
/**
* @brief          Data array storing the conversion result for each analog descriptor.
*
*/
static VAR(Adc_ValueGroupType, AUTOMATIC) IoDal_AdcResultDescriptorBuffer[IODAL_MAX_ANI_DESCRIPTORS];

/**
* @brief          Data array storing the status of the conversion for each analog descriptor.
*
*/
static VAR(Adc_ValueGroupType, AUTOMATIC) IoDal_AdcStatusDescriptorBuffer[IODAL_MAX_ANI_DESCRIPTORS];

/**
* @brief          Variable holds the index of the current ADC channel that is being in use.
*
*/
static VAR(Adc_GroupType,          AUTOMATIC) IoDal_CurrentDescriptorIndex = 0;

/**
* @brief          Variable holds the index of the Ocu trigger channel used in current configuration.
*
*/
static VAR(Ocu_ChannelType, AUTOMATIC) IoDal_SwTriggerChannel = 0U;

/**
* @brief          Variable holds the current state used by the analog conversion state-machine.
*
*/

static VAR(IoDal_AnalogConvState, AUTOMATIC) IoDal_AniLogicalState = ADC_START_STATE;

/**
* @brief          Variable holds the pointer to the Time Trigger table used for all descriptors in current configuration.
*
*/
P2VAR(Ocu_ValueType, AUTOMATIC, IODAL_APPL_DATA)  IoDal_pTimeTableEventsList = NULL_PTR; 
/*====================================================================================================================
                                         GLOBAL CONSTANTS
=====================================================================================================================*/


/*====================================================================================================================
                                         GLOBAL VARIABLES
=====================================================================================================================*/

/*====================================================================================================================
                                        LOCAL FUNCTION PROTOTYPES
=====================================================================================================================*/
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_SetNextAdcStartState(VAR(Adc_GroupType, AUTOMATIC) CurrentGroupId);
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_SetNextAdcReadState(void);
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_WriteChannelValueBuffers(VAR(Adc_GroupType, AUTOMATIC) AdcGroupId);
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_SetNextUsableDescriptor(VAR(Adc_ValueGroupType, AUTOMATIC) State);
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_ResetAdcStartState(void);
/*====================================================================================================================
                                             LOCAL FUNCTIONS
=====================================================================================================================*/

                    
/*===================================================================================================================*/
/**
@brief      IoDal_Ani_WriteChannelValueBuffers - Write the result buffers for all channels belonging to a certain group 
@details    An Ani descriptor is a unique combination of Adc Group and channel and because coversion is done at group 
            level we might have the situation where multiple descriptor channels have valid results stored in the ADC 
			buffers, results that need to be copied to application buffer.

@param[in]  AdcGroupId    Adc group id.

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/                        
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_WriteChannelValueBuffers(Adc_GroupType AdcGroupId)
{
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) AniDescriptorId = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) ChannelIndex = 0U;
    VAR(Adc_GroupType, AUTOMATIC) CurrentGroupId = 0U;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, IODAL_APPL_CONST) AdcResultBufferPointer;
    
    
    /*go through all descriptors */
    for(AniDescriptorId = 0U; AniDescriptorId < (IoDal_pAniGlobalCfgPtr->AdcDescriptorsCount); AniDescriptorId++)
    {
        CurrentGroupId = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[AniDescriptorId]).AdcGroupId;
        
        /*check if the group ids for the next descriptors are the same with the one from the global indexing descriptor*/        
        if (CurrentGroupId == AdcGroupId)
        {
            /*IoDal_AdcResultDescriptorBuffer[IoDal_CurrentDescriptorIndex] = AdcResultBufferPointer[AdcChannelIndex];*/
            AdcResultBufferPointer = ((((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[AniDescriptorId]).pAdConvResultsPtr);
           
            /*get AD channel ID associate to this descriptor*/
            ChannelIndex = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[AniDescriptorId]).AdcChannelId;
            
            /*all mark descriptors having the same group ans IDLE*/
            IoDal_AdcResultDescriptorBuffer[AniDescriptorId] = AdcResultBufferPointer[ChannelIndex];
        }
    }
}


/*===================================================================================================================*/
/**
@brief      IoDal_Ani_SetNextAdcReadState - Sets the event for reading the Adc result on the current Adc group.
@details    Adc uses group conversion and because it is possible to have different Ani descriptors using the same group 
            (but with different channels from that group), we need to make sure that any measurement that we do is done once for each GROUP.
            Basically we have to skip treating descriptors that have the same group once measurement was executed for that group.
            
            Due to the fact that conversion is done at group level it means that only one TT entry is needed for a group and one estimated conversion time.  This means that setting the next compare match event (that we either trigger a Start Conversion or a read result event ) has to be done once for each descriptor that contains an unique group ID. Descriptors that contain the 'other' channels in the group shall only be considerer when passing result from Adc internal buffer to IoDal read buffers.

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_SetNextAdcReadState(void)
{
    VAR(Ocu_ValueType, AUTOMATIC)  NextEventTime = 0U;
   
   /*set next compare match by adding the conversion time for all channels (belonging to the given group) to the current time value */
    NextEventTime = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[IoDal_CurrentDescriptorIndex]).EstimatedConvTime;    
        
   /*set next compare match as a relative value to the current Ocu counter value*/
   (void)Ocu_SetRelativeThreshold(IoDal_SwTriggerChannel, NextEventTime);

   IoDal_AniLogicalState = ADC_READ_STATE;    
}

/*===================================================================================================================*/
/**
@brief      IoDal_Ani_SetNextAdcStartState - Sets the next Ani descriptor to be used when starting the next 
            measurements
@details    This function shall be used to setup the next start conversion event on next ADC group in the list.
            When last group in list was reached this function shall set the first group as the next to be converted.
            Adc uses group conversion and, because it is possible to have different Ani descriptors using 
            the same group (but with different channels from that group), we need to make sure that any 
			measurement that we do is done once for each GROUP.
            Basically we have to skip treating descriptors that have the same group once measurement was executed 
			for that group.
            
            Due to the fact that conversion is done at group level it means that only one TT entry is needed for a 
			group and one estimated conversion time.  This means that setting the next compare match event (that we 
			either trigger a Start Conversion or a read result event ) has to be done once for each descriptor that
			contains an unique group ID. 
			Descriptors that contain the 'other' channels in the group shall only be considerer when passing result
			from Adc internal buffer to IoDal read buffers.

@param[in]  CurrentGroupId    Adc group id.			
			
@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_SetNextAdcStartState(VAR(Adc_GroupType, AUTOMATIC) CurrentGroupId)
{
    VAR(Adc_GroupType, AUTOMATIC) NextGroupId = 0U;
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) AniDescriptorId = 0U;
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) CommonGroupDescrId = 0U;
    VAR(Ocu_ValueType, AUTOMATIC)  NextEventTime = 0U;
    VAR(Ocu_ValueType, AUTOMATIC)  PrevEventTime = 0U;
    
    PrevEventTime = IoDal_pTimeTableEventsList[IoDal_CurrentDescriptorIndex];

    /*get group ID from current Descriptor*/
    for(AniDescriptorId = IoDal_CurrentDescriptorIndex; AniDescriptorId < (IoDal_pAniGlobalCfgPtr->AdcDescriptorsCount); AniDescriptorId++)
    {
        NextGroupId = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[AniDescriptorId]).AdcGroupId;
            
        /*check if the group ids for the next descriptors are the same with the one from the global indexing descriptor*/        
        if (CurrentGroupId == NextGroupId)
        {
            /*all mark descriptors having the same group ans IDLE*/
            IoDal_AdcStatusDescriptorBuffer[AniDescriptorId] = IODAL_AD_CONV_NO_ERROR; 
                
            /*increment no of descriptors using same group id*/
            CommonGroupDescrId++;
        }            
    }
    
    /*add descriptors with same group to the current index (these descriptors need to be skipped)*/
    IoDal_CurrentDescriptorIndex = IoDal_CurrentDescriptorIndex + (CommonGroupDescrId - 1U);
    
    /*increment current index*/
    IoDal_CurrentDescriptorIndex++;
        
    if (IoDal_CurrentDescriptorIndex >= (IoDal_pAniGlobalCfgPtr->AdcDescriptorsCount))
    {
        IoDal_CurrentDescriptorIndex = 0;            
    }
        
    IoDal_AniLogicalState = ADC_START_STATE;  
    
    NextEventTime = IoDal_pTimeTableEventsList[IoDal_CurrentDescriptorIndex];
    
    (void)Ocu_SetAbsoluteThreshold(IoDal_SwTriggerChannel, PrevEventTime, NextEventTime);
    
}

/*===================================================================================================================*/
/**
@brief      IoDal_Ani_SetNextUsableDescriptor - Sets the next Ani descriptor to be used for measurements
@details    This function is called when ever errors are detected, in order to skip the current group measurement and
            start measurements on the next group which has a valid timer stamp attached to it.
			All channels beloging to the group that had conversion error shall be marked with the same error information.

@param[in]  State    Adc group id.				
			
@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_SetNextUsableDescriptor(VAR(Adc_ValueGroupType, AUTOMATIC) State)
{
    VAR(Adc_GroupType, AUTOMATIC) NextGroupId = 0U;
    VAR(Adc_GroupType, AUTOMATIC) CurrentGroupId = 0U;
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) AniDescriptorId = 0U;
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) CommonGroupDescrId = 0U;

    /*TODO: this function should be made reentrant by protecting global data*/
    CurrentGroupId = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[IoDal_CurrentDescriptorIndex]).AdcGroupId;
        
    /*get group ID from current Descriptor*/
    for(AniDescriptorId = IoDal_CurrentDescriptorIndex; AniDescriptorId < (IoDal_pAniGlobalCfgPtr->AdcDescriptorsCount); AniDescriptorId++)
    {
        NextGroupId = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[AniDescriptorId]).AdcGroupId;
            
        /*check if the group ids for the next descriptors are the same with the one from the global indexing descriptor*/        
        if (CurrentGroupId == NextGroupId)
        {
            /*all mark descriptors having the same group as IODAL_AD_CONV_INVALID*/
            IoDal_AdcStatusDescriptorBuffer[AniDescriptorId] = State; 
                
            /*increment no of descriptors using same group id*/
            CommonGroupDescrId++;
        }            
    }
    
    /*IoDal_CurrentDescriptorIndex = IoDal_CurrentDescriptorIndex + (CommonGroupDescrId -1U);*/ 
}



/*===================================================================================================================*/
/**
@brief      IoDal_Ani_ResetAdcStartState - Sets the first compare match event used for triggering measurements on the first descriptor
@details    This internal function shall be called to reset the HW unit logical state and restart measurement when ever an error was detected
            or when the first ever measurement is queued.

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
static inline FUNC(void, IODAL_APP_CODE) IoDal_Ani_ResetAdcStartState(void)
{
    VAR(Ocu_ValueType, AUTOMATIC)  NextEventTime = 0U;         
    
    NextEventTime = (Ocu_ValueType)IoDal_pTimeTableEventsList[IoDal_CurrentDescriptorIndex]; 
        
     /*set absolute value for the first compare match event */
    (void)Ocu_SetAbsoluteThreshold(IoDal_SwTriggerChannel, 0, NextEventTime);
        
    IoDal_AniLogicalState = ADC_START_STATE;    
}




/*====================================================================================================================
                                             GLOBAL FUNCTIONS
=====================================================================================================================*/

/*===================================================================================================================*/
/**
@brief      IoDal_Ani_AdcSwTriggerTable - Adc Sw Time Trigger Table Process function
@details    This function shall be called by the OCU channel interrupt whenever a match compare event occurs. 
            The triggering of the ADC is done the following the state-machine given by IoDal_AniLogicalState:
            1) ADC_START_STATE: will trigger Start AD conversion if Adc group is not busy (i.e. previous conversion did not finish) 
            2) ADC_READ_STATE: will copy Adc result from ADC buffers to IoDal buffers if Adc group is not busy (i.e. previous conversion did not finish) 
            During normal function it is expected that for each descriptor containing an unique group ID the two operations describe above will execute in the order described above. 
            After the last descriptor was 'triggered', the state machine will reset itself and restart conversions starting with the first (zero)  descriptor (in the conditions described above)
            Error cases: 
             - IODAL_AD_CONV_NOT_STARTED - if state machine is in START and the ADC unit is still busy
             - IODAL_AD_CONV_INVALID     - if state machine is in READ but the ADC unit is still busy
             Whenever an error occurs it is expected that the state-machine will skip the handling that descriptor and move to next descriptor starting new AD conversion for its given group.
			
@return     void

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC (void, IODAL_APP_CODE) IoDal_Ani_AdcSwTriggerTable(void)
{     
    VAR(uint8, AUTOMATIC) AdcGroupIndex;

        
    if(NULL_PTR != IoDal_pAniGlobalCfgPtr)
    {
        AdcGroupIndex    = (((IoDal_pAniGlobalCfgPtr->pAnGroupDescriptor))[IoDal_CurrentDescriptorIndex]).AdcGroupId;
                
        switch(IoDal_AniLogicalState)
        {
            case ADC_START_STATE:
            {
                /*if no conversion is on-going*/
                if (ADC_IDLE == Adc_GetGroupStatus(AdcGroupIndex))
                {      
                    Adc_StartGroupConversion(AdcGroupIndex);
                #ifdef IFRW_DEBUG_PIN							
                    Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, 1);
                #endif
                    IoDal_Ani_SetNextAdcReadState();    
                }
                else
                {
                    /*reset the table but starting from next descriptor index*/
                    IoDal_Ani_SetNextUsableDescriptor(IODAL_AD_CONV_NOT_STARTED);
                    
                    IoDal_Ani_ResetAdcStartState();              
                }    
                
            } break;

            case ADC_READ_STATE:
            {
                /* pass data from external Adc buffer to Ani descriptor data array*/
                IoDal_Ani_WriteChannelValueBuffers(AdcGroupIndex);
                    
                Adc_StopGroupConversion(AdcGroupIndex);
			#ifdef IFRW_DEBUG_PIN			
                Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, 0);
			#endif	
                if (ADC_IDLE == Adc_GetGroupStatus(AdcGroupIndex))
                {            
                     /*mark conversion as completed and move to next descriptor*/                
                    IoDal_Ani_SetNextAdcStartState(AdcGroupIndex);
                }
                else
                {
                    IoDal_Ani_SetNextUsableDescriptor(IODAL_AD_CONV_ERROR_STATE);
                   
                    IoDal_Ani_ResetAdcStartState(); 
                }
                
            } break;
                
            default:
            {

#if (IODAL_ENABLE_DEM_REPORT_ERROR_STATUS == STD_ON)    
                    /*call DEM: Invalid state -- memory corruption*/
                Dem_ReportErrorStatus((Dem_EventIdType)IODAL_DEM_INVALID_STATE, DEM_EVENT_STATUS_FAILED);                
#endif
            
                IoDal_Ani_SetNextUsableDescriptor(IODAL_AD_CONV_NOT_INIT);
                    
                IoDal_Ani_ResetAdcStartState();    
      
            }        
        }
    }
}


/*===================================================================================================================*/
/**
@brief      IoDal_Ani_Init - Initialize the IODAL
@details    After global data is initialized this function shall also start OCU trigger channel and sets the 
            first compare match event.

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all IODAL components)		

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Ani_Init(P2CONST(IoDal_BswIoConfigType, AUTOMATIC, IODAL_APP_CONST) ConfigPtr)
{
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) AniDescriptorId = 0U;
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) TriggerDescrId  = 0U;

    
    if(NULL_PTR != ConfigPtr)
    {
        IoDal_pAniGlobalCfgPtr = ConfigPtr;        

        for(AniDescriptorId = 0U; AniDescriptorId < (IoDal_pAniGlobalCfgPtr->AdcDescriptorsCount); AniDescriptorId++)
        {          
            IoDal_AdcResultDescriptorBuffer[AniDescriptorId] = 0U;
            
            IoDal_AdcStatusDescriptorBuffer[AniDescriptorId] = IODAL_AD_CONV_INIT;         
        }
        
        IoDal_pAniGlobalCfgPtr->pfAdcBufferSetupCallout();

        /*Start SW trigger channel if trigger channel was not started before*/
        TriggerDescrId = ConfigPtr->AdcSwTriggerDescriptorIndex;
            
        IoDal_SwTriggerChannel = (((IoDal_pAniGlobalCfgPtr->pOcuChanDescriptor))[TriggerDescrId]).OcuChannel;
            
        /*get time trigger table */
        IoDal_pTimeTableEventsList = (Ocu_ValueType *)((((IoDal_pAniGlobalCfgPtr->pOcuChanDescriptor))[IoDal_SwTriggerChannel]).pTimeTableEventsList);

            
        IoDal_CurrentDescriptorIndex = 0;   
            
        IoDal_Ani_ResetAdcStartState();    
        
#ifdef IFRW_DEBUG_PIN		
        Dio_WriteChannel(DioConf_DioChannel_DioChannel_0, 0);          
#endif		 
        Ocu_StartChannel(IoDal_SwTriggerChannel);
                    
        Ocu_EnableNotification(IoDal_SwTriggerChannel);
    }    
}


/*===================================================================================================================*/
/**
@brief      IoDal_Ani_DeInit - DeInitialize the IODAL Analog input component

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Ani_DeInit(void)
{
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) AniDescriptorId;
    
    if(NULL_PTR != IoDal_pAniGlobalCfgPtr)
    {
        for(AniDescriptorId = 0; AniDescriptorId  < (IoDal_pAniGlobalCfgPtr->AdcDescriptorsCount); AniDescriptorId++)
        {    
            /*de-initialize all used data*/    
            IoDal_AdcStatusDescriptorBuffer[AniDescriptorId] = IODAL_AD_CONV_INIT;
            IoDal_AdcResultDescriptorBuffer[AniDescriptorId] = 0U;
        }   
              
        /*stop trigger channels if the trigger channel was not previously stopped*/
        Ocu_DisableNotification(IoDal_SwTriggerChannel);
        
        Ocu_StopChannel(IoDal_SwTriggerChannel);  
        
        IoDal_CurrentDescriptorIndex = 0;        
            
        IoDal_AniLogicalState = ADC_START_STATE;       
     
        IoDal_pAniGlobalCfgPtr = NULL_PTR;
    }    
}



/*===================================================================================================================*/
/**
@brief      IoDal_Ani_AdcHwTriggerHandler - Adc Hw Trigger handler for IODAL
@details    

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Ani_AdcHwTriggerHandler(void)
{
    /*TODO: Add support for HW trigger handling*/
}



/*===================================================================================================================*/
/**
@brief      IoDal_Ani_ReadInputs - Read the Processed Adc Inputs
@details    Provides ADC output information as both value and status for the layers above IODAL.
            Each BswIoChannel is described by an unique descriptor ID (a unique combination of Adc group and channel )

@param[in]  BswIoChannel    Logical BSW input channel id.
@param[out] InputValue      Value read from the assigned adc input channel.			
			
@return     Std_ReturnType  Status of the latest measurement on the given Adc channel.
@retval     E_OK            Conversion was successful.  
@retval     E_NOT_OK        Conversion failed.

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(Std_ReturnType, IODAL_APP_CODE) IoDal_Ani_ReadInputs(IoDal_BswChannelIdType BswIoChannel, IoDal_BswValueType  * InputValue)
{
    Std_ReturnType RetVal = E_NOT_OK;
    VAR(IoDal_BswDescriptorIdType, AUTOMATIC) AniDescriptorId = 0;;

    if(NULL_PTR != IoDal_pAniGlobalCfgPtr)
    {
        AniDescriptorId   =  ((IoDal_pAniGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
    
        *InputValue =  IoDal_AdcResultDescriptorBuffer[AniDescriptorId];
    
        if (IODAL_AD_CONV_NO_ERROR == IoDal_AdcStatusDescriptorBuffer[AniDescriptorId])
        {
            RetVal = E_OK;
        }
    }

    return RetVal;    
}
#endif

/*======================================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
