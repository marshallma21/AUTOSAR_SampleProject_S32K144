/**
*   @file    IoDal_Pwm.c
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component for PWM output channels
*   @details This file implements the IODAL interface to application layer to lower layers: PWM
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

/*===============================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
================================================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
#include "IoDal_Drv_Cfg.h"
#include "IoDal_Types.h"
#include "IoDal_Cfg.h"
#include "IoDal_Pwm.h"
#include "Pwm.h"
/*===============================================================================================================================
                                       SOURCE FILE VERSION INFORMATION
================================================================================================================================*/
#define IODAL_PWM_VENDOR_ID_C                       43

#define IODAL_PWM_AR_RELEASE_MAJOR_VERSION_C        4

#define IODAL_PWM_AR_RELEASE_MINOR_VERSION_C        2

#define IODAL_PWM_AR_RELEASE_REVISION_VERSION_C     2

#define IODAL_PWM_SW_MAJOR_VERSION_C                1
#define IODAL_PWM_SW_MINOR_VERSION_C                0
#define IODAL_PWM_SW_PATCH_VERSION_C                1

/*===============================================================================================================================
                                           FILE VERSION CHECKS
================================================================================================================================*/
/* Check if IoDal_Pwm.c source file and IoDal_Cfg.h header file are of the same vendor */
#if (IODAL_PWM_VENDOR_ID_C != IODAL_CFG_VENDOR_ID)
    #error "IoDal_Pwm.c and IoDal_Cfg.h have different vendor ids"
#endif

/* Check if IoDal_Pwm.c source file and IoDal_Cfg.h header file are of the same Autosar version */
#if ((IODAL_PWM_AR_RELEASE_MAJOR_VERSION_C != IODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_PWM_AR_RELEASE_MINOR_VERSION_C != IODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_PWM_AR_RELEASE_REVISION_VERSION_C != IODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Pwm.c and IoDal_Cfg.h are different"
#endif

/* Check if IoDal_Pwm.c source file and IoDal_Cfg.h header file are of the same Software version */
#if ((IODAL_PWM_SW_MAJOR_VERSION_C != IODAL_CFG_SW_MAJOR_VERSION) || \
     (IODAL_PWM_SW_MINOR_VERSION_C != IODAL_CFG_SW_MINOR_VERSION) || \
     (IODAL_PWM_SW_PATCH_VERSION_C != IODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal_Pwm.c and IoDal_Cfg.h are different"
#endif

/* Check if IoDal_Pwm.c source file and IoDal_Pwm.h header file are from the same vendor */
#if (IODAL_PWM_VENDOR_ID_C != IODAL_PWM_VENDOR_ID)
    #error "IoDal_Pwm.c and IoDal_Pwm.h have different vendor ids"
#endif

/* Check if IoDal_Pwm.c source file and IoDal_Pwm.h header file are of the same Autosar version */
#if ((IODAL_PWM_AR_RELEASE_MAJOR_VERSION_C != IODAL_PWM_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_PWM_AR_RELEASE_MINOR_VERSION_C != IODAL_PWM_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_PWM_AR_RELEASE_REVISION_VERSION_C != IODAL_PWM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Pwm.c and IoDal_Pwm.h are different"
#endif

/* Check if IoDal_Pwm.c source file and IoDal_Pwm.h header file are of the same Software version */
#if ((IODAL_PWM_SW_MAJOR_VERSION_C != IODAL_PWM_SW_MAJOR_VERSION) || \
     (IODAL_PWM_SW_MINOR_VERSION_C != IODAL_PWM_SW_MINOR_VERSION) || \
     (IODAL_PWM_SW_PATCH_VERSION_C != IODAL_PWM_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of IoDal_Pwm.c and IoDal_Pwm.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if IoDal_Pwm.c source file and Std_Types header file are of the same AutoSar version */
 #if ((IODAL_PWM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
      (IODAL_PWM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of IoDal_Pwm.c and Std_Types.h are different"
 #endif
 /* Check if IoDal_Pwm.c source file and Mcal header file are of the same AutoSar version */
 #if ((IODAL_PWM_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (IODAL_PWM_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of IoDal_Pwm.c and Mcal.h are different"
 #endif 
#endif

/*===============================================================================================================================
                                                LOCAL MACROS
================================================================================================================================*/
#define PWM_DUTY_CYCLE_MAX_VALUE 0x8000U


/*===============================================================================================================================
                                             FILE VERSION CHECKS
================================================================================================================================*/


/*===============================================================================================================================
                                              LOCAL CONSTANTS
===============================================================================================================================*/
/**
@brief This constant defines the maximum value of the Pwm's duty cycle
*/
static P2CONST(IoDal_BswIoConfigType, IODAL_VAR,  IODAL_APPL_CONST) IoDal_pPwmGlobalCfgPtr=NULL_PTR;



/*===============================================================================================================================
                                                LOCAL VARIABLES
================================================================================================================================*/
#if (IODAL_PWM_EXT_DEV == STD_ON) || (IODAL_PWM_SYNC == STD_ON)
/**
* @brief          Data array storing the state of any output-change request.
*
*/
static VAR(boolean, AUTOMATIC) IoDal_PwmResyncRequest[IODAL_MAX_PWM_DESCRIPTORS];

/**
* @brief          Data array storing the digital output level (duty cycle) which was requested by application.
*
*/
static VAR(uint16,  AUTOMATIC) IoDal_PwmDutyValue[IODAL_MAX_PWM_DESCRIPTORS];
#endif


#if (IODAL_VARIABLE_PERIOD == STD_ON)
/**
* @brief          Data array storing the digital output level (period) which was requested by application.
*
*/
static VAR(Pwm_PeriodType, AUTOMATIC) IoDal_PwmPeriodValue[IODAL_MAX_PWM_DESCRIPTORS]; 
#endif


/*===============================================================================================================================
                                                LOCAL FUNCTION PROTOTYPES
================================================================================================================================*/

/*==============================================================================================================================*/
/**
@brief      IoDal_Pwm_Init - Initialize the IODAL
@details    

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all IODAL components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==============================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Pwm_Init(P2CONST(IoDal_BswIoConfigType, AUTOMATIC, IODAL_APP_CODE) ConfigPtr)
{
    VAR(uint8, AUTOMATIC) PwmDescriptorId;
    #if (IODAL_PWM_EXT_DEV == STD_ON)    
    VAR(IoDal_Pwm_InitCalloutType, AUTOMATIC)   pfInitCallout;
    P2CONST(IoDal_Pwm_ExtDev_Config, AUTOMATIC, IODAL_APPL_CONST)   pcInitData;
    #endif
    IoDal_pPwmGlobalCfgPtr = ConfigPtr;

    
    for(PwmDescriptorId = 0U; PwmDescriptorId < (IoDal_pPwmGlobalCfgPtr->PwmChannelCount); PwmDescriptorId++)
    {            

    #if (IODAL_PWM_EXT_DEV == STD_ON)   
       /*get external device handler function*/    
        pfInitCallout    =  (*(((IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorId]).pExtPwmChannelCfg).pfPwm_ExtDev_DeInitHandler;
        
        pcInitData =  (*(((*(IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorId]).pExtPwmChannelCfg))->pExtPwmChannelCfg;
    
        /*call de-initialization routine for current PWM channel descriptor*/    
        if((NULL_PTR != pfInitCallout) && (NULL_PTR != pcInitData))
        {
            pfInitCallout(pcInitData);            
        }
    #endif    
    
    #if (IODAL_PWM_EXT_DEV == STD_ON) || (IODAL_PWM_SYNC == STD_ON)
        IoDal_PwmResyncRequest[PwmDescriptorId] = FALSE;          
    #endif
    
    #if (IODAL_PWM_EXT_DEV == STD_ON)
        IoDal_PwmDutyValue[PwmDescriptorId] = 0;
    #endif
    
    #if (IODAL_VARIABLE_PERIOD == STD_ON)
        IoDal_PwmPeriodValue[PwmDescriptorId] = 0;     
    #endif

    }        
}

/*==============================================================================================================================*/
/**
@brief      IoDal_Pwm_DeInit - DeInitialize the IODAL
@details    After calling this function the task containing ADC should be initialize

@return     void
@retval     

@pre None
@post None
*/
/*==============================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Pwm_DeInit(void)
{
    VAR(uint8, AUTOMATIC) PwmDescriptorId;
    
    #if (IODAL_PWM_EXT_DEV == STD_ON)
    VAR(IoDal_Pwm_DeInitCalloutType, AUTOMATIC)   pfDeInitCallout;
    #endif
    
    for(PwmDescriptorId = 0U; PwmDescriptorId < (IoDal_pPwmGlobalCfgPtr->PwmChannelCount); PwmDescriptorId++)
    {        
    #if (IODAL_PWM_EXT_DEV == STD_ON)
        /*get external device handler function*/    
        pfDeInitCallout    =  (*(((*(IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorId]).pExtPwmChannelCfg)).pfPwm_ExtDev_DeInitHandler;
    
        /*call deinitialization routine for current PWM channel descriptor*/    
        if(NULL_PTR != pfDeInitCallout)
        {
            pfDeInitCallout();
        }
    #endif    
    
    #if (IODAL_PWM_EXT_DEV == STD_ON) || (IODAL_PWM_SYNC == STD_ON)
        IoDal_PwmResyncRequest[PwmDescriptorId] = FALSE;
    #endif
    
    #if (IODAL_VARIABLE_PERIOD == STD_ON)
        IoDal_PwmPeriodValue[PwmDescriptorId] = 0; 
    #endif    
    
    #if (IODAL_PWM_EXT_DEV == STD_ON)
        IoDal_PwmDutyValue[PwmDescriptorId] = 0;
    #endif
    
    }
    
    IoDal_pPwmGlobalCfgPtr = NULL_PTR;

}


#if (IODAL_PWM_SYNC == STD_ON)
/*==============================================================================================================================*/
/**
@brief      IoDal_Pwm_OutputResync - IoDal function used for Output Resynchronization
@details    This function shall be called from the main function to trigger a resync event for all 
            channels belonging to the HW units which need to run in sync.

@return     void
@retval     

@pre None
@post None
*/
/*==============================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Pwm_OutputResync(IoDal_BswChannelIdType BswIoChannel)
{        
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    VAR(uint8, AUTOMATIC)                PwmDescriptorIndex;
    VAR(uint8, AUTOMATIC)                PwmSyncTimer;
    VAR(uint16, AUTOMATIC)               PwmSyncMask;
    

    PwmDescriptorIndex    =  ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
        
    if(NULL_PTR != IoDal_pPwmGlobalCfgPtr)
    {
                
        if(TRUE == IoDal_PwmResyncRequest[PwmDescriptorIndex])
        {    
                
            IoDal_PwmResyncRequest[PwmDescriptorIndex] = FALSE;

            /*get sync information from Pwm descriptor*/
            PwmSyncTimer    =  (*((((IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorIndex]).pIntPwmChannelCfg))->UsedSyncPwmTimer;
            PwmSyncMask    =  (*((((IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorIndex]).pIntPwmChannelCfg))->SubmoduleMask;
            Pwm_SyncUpdate(PwmSyncTimer, PwmSyncMask);            
        }
    }
}
#endif

#if (IODAL_PWM_EXT_DEV == STD_ON)
/*==============================================================================================================================*/
/**
@brief      IoDal_Pwm_ExtDevHandler - IoDal function used for handling PWM compatible external devices
@details    

@return     void
@retval     

@pre None
@post None
*/
/*==============================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Pwm_ExtDevHandler(IoDal_BswChannelIdType BswIoChannel)
{        
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    VAR(uint8, AUTOMATIC)                PwmDescriptorIndex;
    
    VAR(uint8, AUTOMATIC)                ExtDeviceOutputChannel;

    VAR(IoDal_Pwm_UpdateCalloutType, AUTOMATIC)   pfCallout;
    
    if(NULL_PTR != IoDal_pPwmGlobalCfgPtr)
    {

        PwmDescriptorIndex    =  ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
        
        if(TRUE == IoDal_PwmResyncRequest[PwmDescriptorIndex])
        {    
                
            IoDal_PwmResyncRequest[PwmDescriptorIndex] = FALSE;
                        
            /*get external device configuration data*/            
            ExtDeviceOutputChannel    =  (((*(IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorIndex]).PwmChannel); 
            
            /*get external device handler function*/    
            pfCallout    =  (*(((*(IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorIndex]).pExtPwmChannelCfg)).pfPwm_ExtDev_UpdateHandler;
    
            
            if(NULL_PTR != pfCallout)
            {
                pfCallout(ExtDeviceOutputChannel, &IoDal_PwmDutyValue[PwmDescriptorIndex]);   
            }
        }    
    }
}
#endif

/*==============================================================================================================================*/
/**
@brief      IoDal_Pwm_WriteDuty - IoDal Pwm function used to set a new value for the duty cycle
@details    For channels that don't require synchronization or are not connected on external devices,
            this function shall call the PWM driver directly.
            For external devices this function shall buffer the requested output value and 
			the handling of the device shall be done on the next call of the Main function.
			For channels that are synchronized, this function shall call PWM to write the new
			duty value in the driver's internal buffers and the resync command shall be executed by the main
			function.            			


@param[in]  BswIoChannel    Logical BSW output channel id.
@param[out] OutputValue     Value to be written to a pwm output channel.

@return     void
@retval     

@pre None
@post None
*/
/*==============================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Pwm_WriteDuty(IoDal_BswChannelIdType BswIoChannel, IoDal_BswDutyType OutputDutyValue)
{
    VAR(Pwm_ChannelType, AUTOMATIC)      PwmChannel;
    VAR(uint8, AUTOMATIC)                PwmDescriptorIndex;
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    
    PwmDescriptorIndex    =  ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
    

    PwmChannel    = (((IoDal_pPwmGlobalCfgPtr->pPwmChanDescriptor))[PwmDescriptorIndex]).PwmChannel;
    ChannelType = ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;    
     
    switch (ChannelType)
    {
        case IODAL_PWM_FIXED_PERIOD_OUTPUT:
            Pwm_SetDutyCycle(PwmChannel, OutputDutyValue);                
        break;
            
#if (IODAL_PWM_EXT_DEV == STD_ON)
        case IODAL_PWM_EXT_DEV_OUTPUT:
             IoDal_PwmDutyValue[PwmDescriptorIndex] = OutputDutyValue;
             IoDal_PwmResyncRequest[PwmDescriptorIndex] = TRUE;
 
        break;
#endif

#if (IODAL_VARIABLE_PERIOD == STD_ON)
        case IODAL_PWM_VARIBLE_PERIOD_OUTPUT:
            Pwm_SetPeriodAndDuty(PwmChannel, IoDal_PwmPeriodValue[PwmDescriptorIndex], OutputDutyValue);                
        break;
#endif        
            
#if (IODAL_PWM_SYNC == STD_ON)            
        case IODAL_PWM_SYNC_OUTPUT:
             Pwm_SetDutyCycle_NoUpdate(PwmChannel, OutputDutyValue);    
             IoDal_PwmResyncRequest[PwmDescriptorIndex] = TRUE;
        break;
#endif        
    }        
}

#if (IODAL_VARIABLE_PERIOD == STD_ON)
/*==============================================================================================================================*/
/**
@brief      IoDal_Pwm_WritePeriod - IoDal Pwm function used to set a new value for the period
@details    The Period value shall be buffered and the output waveform shall only be updated by 
            IoDal_Pwm_WriteDuty when this function is called from the upper layers.

@param[in]  BswIoChannel    Logical BSW output channel id.
@param[out] OutputValue     Value to be written to a digital output channel.

@return     void
@retval     

@pre None
@post None
*/
/*==============================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Pwm_WritePeriod(IoDal_BswChannelIdType BswIoChannel, IoDal_BswPeriodType OutputPeriodValue)
{
    VAR(Pwm_ChannelType, AUTOMATIC)       PwmChannel;
    VAR(uint8, AUTOMATIC)                 PwmDescriptorIndex;
    VAR(IoDal_BswChannelType, AUTOMATIC)  ChannelType;
    
    ChannelType = ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
    PwmDescriptorIndex    =  ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
    
    
    if(IODAL_PWM_VARIBLE_PERIOD_OUTPUT == ChannelType)
    {
        IoDal_PwmPeriodValue[PwmDescriptorIndex] = OutputPeriodValue;
    }
}    
#endif

/*==============================================================================================================================*/
#ifdef __cplusplus
}
#endif
/** @} */
