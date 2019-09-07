/**
*   @file    IoDal.c
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component
*   @details This file implements the IODAL interface to application layer.
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

/*===================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
====================================================================================================================*/
#include "Mcal.h"
#include "Compiler.h"
#include "IoDal_Drv_Cfg.h"
#include "IoDal_Types.h"
#include "IoDal_Cfg.h"
#include "IoDal_Ani.h"
#include "IoDal_Pwm.h"
#include "IoDal_Dio.h"
#include "IoDal.h"
#if (IODAL_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */


/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define IODAL_VENDOR_ID_C                       43

#define IODAL_AR_RELEASE_MAJOR_VERSION_C        4
#define IODAL_AR_RELEASE_MINOR_VERSION_C        2
#define IODAL_AR_RELEASE_REVISION_VERSION_C     2

#define IODAL_SW_MAJOR_VERSION_C                1
#define IODAL_SW_MINOR_VERSION_C                0
#define IODAL_SW_PATCH_VERSION_C                1

/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if source file and IODAL header file are of the same vendor */
#if (IODAL_VENDOR_ID_C != IODAL_VENDOR_ID)
    #error "IoDal.c and IoDal.h have different vendor ids"
#endif

/* Check if source file and IODAL header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != IODAL_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_C != IODAL_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_C != IODAL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal.h are different"
#endif

/* Check if source file and IODAL header file are of the same Software version */
#if ((IODAL_SW_MAJOR_VERSION_C != IODAL_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_C != IODAL_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_C != IODAL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.c and IoDal.h are different"
#endif

/* Check if source file and IODAL IPW header file are from the same vendor */
#if (IODAL_VENDOR_ID_C != IODAL_TYPES_VENDOR_ID)
    #error "IoDal.c and IoDal_Types.h have different vendor ids"
#endif

/* Check if source file and IODAL types header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != IODAL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_C != IODAL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_C != IODAL_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Types.h are different"
#endif

/* Check if source file and IODAL types header file are of the same Software version */
#if ((IODAL_SW_MAJOR_VERSION_C != IODAL_TYPES_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_C != IODAL_TYPES_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_C != IODAL_TYPES_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of IoDal.c and IoDal_Types.h are different"
#endif


 /* Check if source file and DET header file are of the same version */
#if (IODAL_DEV_ERROR_DETECT == STD_ON)
    #if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (IODAL_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of IoDal.c and Det.h are different"
    #endif
#endif


/* Check if source file and IODAL configuration header file are of the same vendor */
#if (IODAL_VENDOR_ID_C != IODAL_CFG_VENDOR_ID)
    #error "IoDal.c and IoDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and IODAL configuration header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != IODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_C != IODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_C != IODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IODAL configuration header file are of the same software version */
#if ((IODAL_SW_MAJOR_VERSION_C != IODAL_CFG_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_C != IODAL_CFG_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_C != IODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IoDal Types header file are of the same vendor */
#if (IODAL_VENDOR_ID_C != IODAL_ANI_VENDOR_ID)
    #error "IoDal.c and IoDal_Ani.h have different vendor ids"
#endif

/* Check if source file and IoDal Types header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != IODAL_ANI_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_C != IODAL_ANI_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_C != IODAL_ANI_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Ani.h are different"
#endif

/* Check if source file and IoDal Types header file are of the same software version */
#if ((IODAL_SW_MAJOR_VERSION_C != IODAL_ANI_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_C != IODAL_ANI_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_C != IODAL_ANI_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.c and IoDal_Ani.h are different"
#endif


/* Check if source file and IoDal Types header file are of the same vendor */
#if (IODAL_VENDOR_ID_C != IODAL_DIO_VENDOR_ID)
    #error "IoDal.c and IoDal_Dio.h have different vendor ids"
#endif

/* Check if source file and IoDal Types header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != IODAL_DIO_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_C != IODAL_DIO_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_C != IODAL_DIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Dio.h are different"
#endif

/* Check if source file and IoDal Types header file are of the same software version */
#if ((IODAL_SW_MAJOR_VERSION_C != IODAL_DIO_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_C != IODAL_DIO_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_C != IODAL_DIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.c and IoDal_Dio.h are different"
#endif

/* Check if source file and IoDal Types header file are of the same vendor */
#if (IODAL_VENDOR_ID_C != IODAL_PWM_VENDOR_ID)
    #error "IoDal.c and IoDal_Pwm.h have different vendor ids"
#endif

/* Check if source file and IoDal Types header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION_C != IODAL_PWM_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION_C != IODAL_PWM_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION_C != IODAL_PWM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Pwm.h are different"
#endif

/* Check if source file and IoDal Types header file are of the same software version */
#if ((IODAL_SW_MAJOR_VERSION_C != IODAL_PWM_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION_C != IODAL_PWM_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION_C != IODAL_PWM_SW_PATCH_VERSION) \
    )
   #error "Software Version Numbers of IoDal.c and IoDal_Pwm.h are different"
#endif


/*===================================================================================================================
                                   LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================================*/
typedef enum
{
    IODAL_INIT  = 0U,        /**< @brief mark No error detected for analog descriptor. */
    IODAL_DEINIT         = 1U,     /**< @brief mark conversion on-going for analog descriptor. */
    IODAL_UNINIT,           /**< @brief mark conversion error detected for analog descriptor. */ 
}IoDal_ModuleStateType;

/*===================================================================================================================
                                                 LOCAL CONSTANTS
====================================================================================================================*/

/*===================================================================================================================
                                                 LOCAL VARIABLES
====================================================================================================================*/

/*===================================================================================================================
                                                 GLOBAL CONSTANTS
====================================================================================================================*/

/*===================================================================================================================
                                                  GLOBAL VARIABLES
====================================================================================================================*/
/**
* @brief          Global Configuration Pointer.
* @details        Data structure containing the set of configuration parameters required for
*                 initializing the IODAL components.
*
*/
P2CONST(IoDal_BswIoConfigType, IODAL_VAR, IODAL_APP_CONST) IoDal_pGlobalCfgPtr = NULL_PTR;


/**
* @brief          Variable storing IoDal module state 
* @details        Possible values: UNIT, INIT, DEINIT
*/
static VAR(IoDal_ModuleStateType,      AUTOMATIC) IoDal_ModuleState = IODAL_UNINIT;

/*===================================================================================================================
                                             LOCAL FUNCTION PROTOTYPES
====================================================================================================================*/
static inline FUNC(Std_ReturnType, IODAL_APP_CODE) IoDal_ValidateIoChannel(IoDal_BswChannelIdType BswIoChannel);

/*=====================================================================================================================
                                                 LOCAL FUNCTIONS
=====================================================================================================================*/
static inline FUNC(Std_ReturnType, IODAL_APP_CODE) IoDal_ValidateIoChannel(IoDal_BswChannelIdType BswIoChannel)
{
    Std_ReturnType RetVal = E_OK;
    uint8 MaxIoChannels =  IoDal_pGlobalCfgPtr->AdcDescriptorsCount + IoDal_pGlobalCfgPtr->PwmChannelCount + \
                           IoDal_pGlobalCfgPtr->DioChannelCount  + IoDal_pGlobalCfgPtr->OcuChannelCount + \
                           IoDal_pGlobalCfgPtr->IcuChannelCount;
                           
    if(BswIoChannel > MaxIoChannels)
    {
        RetVal = E_NOT_OK;        
    }        
    return RetVal;
}
/*=====================================================================================================================
                                                 GLOBAL FUNCTIONS
=====================================================================================================================*/

/*=====================================================================================================================*/
/**
@brief      IoDal_Init - Initialize the IODAL
@details    

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all IODAL components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*=====================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Init(P2CONST(IoDal_BswIoConfigType, AUTOMATIC, IODAL_APP_CONST) ConfigPtr)
{

    if(IODAL_INIT != IoDal_ModuleState)
    {    
        if(NULL_PTR != ConfigPtr)
        {            
            IoDal_pGlobalCfgPtr = ConfigPtr;
            
#if IODAL_MAX_ANI_DESCRIPTORS > 0U
            /*initialize analog components if ADC channels are used */ 
            if (IoDal_pGlobalCfgPtr->AdcDescriptorsCount != 0)
            {    
                IoDal_Ani_Init(IoDal_pGlobalCfgPtr); 
            }
#endif            

#if IODAL_MAX_PWM_DESCRIPTORS > 0U
            /*initialize pwm components if PWM channels are used */ 
            if (IoDal_pGlobalCfgPtr->PwmChannelCount != 0)
            {            
                IoDal_Pwm_Init(IoDal_pGlobalCfgPtr);
            }
#endif            

#if (IODAL_MAX_DIO_DESCRIPTORS > 0U) || (IODAL_MAX_ICU_DESCRIPTORS > 0U)  
            /*initialize digital i/o components if DIO, OCU or ICU channels are used */ 
            if ((IoDal_pGlobalCfgPtr->DioChannelCount != 0) || (IoDal_pGlobalCfgPtr->OcuChannelCount != 0) || (IoDal_pGlobalCfgPtr->IcuChannelCount != 0))
            {    
                IoDal_Dio_Init(IoDal_pGlobalCfgPtr);
            }
#endif            
            
            IoDal_ModuleState = IODAL_INIT;        
        }
        else
        {
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_INIT_API_ID, IODAL_E_PARAM_CONFIG);
#endif            
        }    
    }
    else
    {
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_INIT_API_ID, IODAL_E_ALREADY_INITIALIZED);
#endif    
    }    

}

/*=====================================================================================================================*/
/**
@brief      IoDal_DeInit - DeInitialize the IODAL
@details    After calling this function the task containing IODAL should be de-initialize

@return     void
@retval     

@pre None
@post None
*/
/*=====================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_DeInit(void)
{    
    if(IODAL_INIT == IoDal_ModuleState)
    {
   
#if IODAL_MAX_ANI_DESCRIPTORS > 0U   
        if (IoDal_pGlobalCfgPtr->AdcDescriptorsCount != 0)
        {    
            IoDal_Ani_DeInit();        
        }
#endif  
 
#if IODAL_MAX_PWM_DESCRIPTORS > 0U        
        if (IoDal_pGlobalCfgPtr->PwmChannelCount != 0)
        {            
            IoDal_Pwm_DeInit();
        }
#endif 
        
#if (IODAL_MAX_DIO_DESCRIPTORS > 0U) || (IODAL_MAX_ICU_DESCRIPTORS > 0U)      
        if ((IoDal_pGlobalCfgPtr->DioChannelCount != 0) ||
            (IoDal_pGlobalCfgPtr->OcuChannelCount != 0) || 
            (IoDal_pGlobalCfgPtr->IcuChannelCount != 0))
        {    
            IoDal_Dio_DeInit();
        }        
#endif         
        IoDal_pGlobalCfgPtr = NULL_PTR;
        
        IoDal_ModuleState = IODAL_DEINIT;
    }
    else
    {
#if (IODAL_DEV_ERROR_DETECT == STD_ON)            
        /*Call DET module allready initialized*/
        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_DEINIT_API_ID, IODAL_E_UNINIT);
#endif        
    }
}



/*=====================================================================================================================*/
/**
@brief      IoDal_MainFunction - main function of the IODAL
@details    This function shall be called cyclically from any BSW task and shall be used to handle synchronous 
            input/output requests (PWM sync outputs, handling of SPI or I2C external IO devices)

@return     void
@retval     

@pre None
@post None
*/
/*=====================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_MainFunction(void)
{
    uint8 BswIoChannel;
    IoDal_BswChannelType ChannelType;
    uint8 MaxIoChannels =  IoDal_pGlobalCfgPtr->AdcDescriptorsCount + IoDal_pGlobalCfgPtr->PwmChannelCount + \
                           IoDal_pGlobalCfgPtr->DioChannelCount  + IoDal_pGlobalCfgPtr->OcuChannelCount + \
                           IoDal_pGlobalCfgPtr->IcuChannelCount;
    
    if (IODAL_INIT == IoDal_ModuleState)
    {
        
        for (BswIoChannel = 0U;  BswIoChannel < MaxIoChannels; BswIoChannel++ )
        {    
            ChannelType = ((IoDal_pGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
            
            switch (ChannelType)
            {
#if IODAL_MAX_ANI_DESCRIPTORS > 0U                   
                case IODAL_ANALOG_SW_TRIG:
                break;
                
                case IODAL_ANALOG_HW_TRIG:
                {
                    IoDal_Ani_AdcHwTriggerHandler();
                }break;
#endif                
                
#if IODAL_MAX_DIO_DESCRIPTORS > 0U                     
                /*Dio write/read operations are asynchronous*/
                case IODAL_DIO_INPUT:
                case IODAL_DIO_OUTPUT:
                break;                
#if (IODAL_DIO_EXT_DEV == STD_ON)                 
                case IODAL_EXT_DEV_INPUT:
                case IODAL_EXT_DEV_OUTPUT:    
                {                    
                    IoDal_Dio_ExtDevHandler(BswIoChannel);
                }break;  
#endif                
#endif                
                case IODAL_TIMER_CAPTURE:
                break;
                
                case IODAL_TIMER_OUTPUT:
                break;
                
#if IODAL_MAX_PWM_DESCRIPTORS > 0U                    
                /*Dio write/read operations are asynchronous*/
                case IODAL_PWM_VARIBLE_PERIOD_OUTPUT:
                case IODAL_PWM_FIXED_PERIOD_OUTPUT: 
                break;
   
#if (IODAL_PWM_EXT_DEV == STD_ON)   
                case IODAL_PWM_EXT_DEV_OUTPUT:
                {
                    IoDal_Pwm_ExtDevHandler(BswIoChannel);
                }break;
#endif
#if (IODAL_PWM_SYNC == STD_ON)   
                case IODAL_PWM_SYNC_OUTPUT:                 
                {
                    IoDal_Pwm_OutputResync(BswIoChannel);                    
                }break;    
#endif    
#endif       
                default:
                {
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
                    Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_MAINFUNCTION_API_ID, IODAL_E_INVALID_CHANNEL_TYPE);
#endif            
                }
            }
        }        
    }
    else
    {
        /*call Det: module not initialized*/
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_MAINFUNCTION_API_ID, IODAL_E_UNINIT);
#endif    
    }    
}



/*=====================================================================================================================*/
/**
@brief      IoDal_ReadInputs - Read the Processed Inputs from ADC, DIO or ICU
@details    This function shall be called from SWCRTE to provide application with the current value of the given input 
            channel

@param[in]  BswIoChannel    Logical BSW input channel id.
@param[out] InputValue      Value read from the assigned input channel.

@return     void
@retval     

@pre None
@post None
*/
/*=====================================================================================================================*/
FUNC(Std_ReturnType, IODAL_APP_CODE) IoDal_ReadInputs(IoDal_BswChannelIdType BswIoChannel, IoDal_BswValueType  * InputValue) 
{
    IoDal_BswChannelType SensorType;
    Std_ReturnType RetVal = E_NOT_OK;
    volatile uint8 skipStupidOptimization =0; 
    if (IODAL_INIT == IoDal_ModuleState)
    {
        if(NULL_PTR != InputValue)
        {    
        
            if (E_OK == IoDal_ValidateIoChannel(BswIoChannel))
            {
                SensorType = ((IoDal_pGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
              
                switch(SensorType)
                {
#if IODAL_MAX_ANI_DESCRIPTORS > 0U    
                    case IODAL_ANALOG_HW_TRIG: 
                    break;
                    
                    case IODAL_ANALOG_SW_TRIG:
                    {
                       RetVal = IoDal_Ani_ReadInputs(BswIoChannel,   InputValue);                    
                    }break;
#endif                    
#if IODAL_MAX_DIO_DESCRIPTORS > 0U           
                    case IODAL_DIO_INPUT:
                    {                    
                       RetVal = IoDal_Dio_ReadInputs(BswIoChannel,  InputValue);
                       skipStupidOptimization++;
                    }break;    
#endif
                    case IODAL_TIMER_CAPTURE:
                    break;
                    
                    case IODAL_EXT_DEV_INPUT:
                    break;
                    
                    default :
                    {
    #if (IODAL_DEV_ERROR_DETECT == STD_ON)        
                        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_READINPUTS_API_ID, IODAL_E_INVALID_CHANNEL_TYPE);
    #endif            
                    }
                }    
            }            
            else
            {
    #if (IODAL_DEV_ERROR_DETECT == STD_ON)        
            Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_READINPUTS_API_ID, IODAL_E_INVALID_CHANNEL_ID);
    #endif    
            }
        }
        else
        {
    #if (IODAL_DEV_ERROR_DETECT == STD_ON)        
            Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_READINPUTS_API_ID, IODAL_E_PARAM_POINTER);
    #endif            
        }        
    }
    else
    {
        /*call Det: module not initialized*/
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_READINPUTS_API_ID, IODAL_E_UNINIT);
#endif    
    }    
    
    return RetVal;
}


/*=====================================================================================================================*/
/**
@brief      IoDal_WriteOutputs - Write the processed output commands to PWM, DIO or OCU
@details    This function shall be called from SWCRTE to provide application with the possibility to write 
            output channels with either HIGH or LOW for DIO channels or PWM modulation value.
            

@param[in]  BswIoChannel    Logical BSW output channel id.
@param[out] OutputValue      Value to be written to output channel.

@return     void
@retval     

@pre None
@post None
*/
/*=====================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_WriteOutputs(IoDal_BswChannelIdType BswIoChannel,  IoDal_BswValueType  OutputValue) 
{
    IoDal_BswChannelType ActuatorType;
       
    if (IODAL_INIT == IoDal_ModuleState)
    {
        if (E_OK == IoDal_ValidateIoChannel(BswIoChannel))
        {
            ActuatorType = ((IoDal_pGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
            
            switch(ActuatorType)
            {
#if IODAL_MAX_PWM_DESCRIPTORS > 0U    
                case IODAL_PWM_VARIBLE_PERIOD_OUTPUT:
                    IoDal_Pwm_WriteDuty(BswIoChannel,   OutputValue);
                break; 
                
                case IODAL_PWM_FIXED_PERIOD_OUTPUT: 
                    IoDal_Pwm_WriteDuty(BswIoChannel,   OutputValue);
                break; 
                
                case IODAL_PWM_EXT_DEV_OUTPUT: 
                break; 
                
                case IODAL_PWM_SYNC_OUTPUT:                 
                {
                    IoDal_Pwm_WriteDuty(BswIoChannel,   OutputValue);                    
                }break;    
#endif   

                case IODAL_EXT_DEV_OUTPUT:
                break;
                
                
                case IODAL_TIMER_OUTPUT:
                break;
 
#if IODAL_MAX_DIO_DESCRIPTORS > 0U     
                case IODAL_DIO_OUTPUT:                
                {                    
                    IoDal_Dio_WriteOutputs(BswIoChannel,  OutputValue);
                }break;    
#endif                
                default :
                {
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
                    Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_WRITEOUTPUTS_API_ID, IODAL_E_INVALID_CHANNEL_TYPE);
#endif            
                }
            }    
        }
        else
        {
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
            Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_WRITEOUTPUTS_API_ID, IODAL_E_INVALID_CHANNEL_ID);
#endif    
        }        
    }
    else
    {
        /*call Det: module not initialized*/
#if (IODAL_DEV_ERROR_DETECT == STD_ON)        
        Det_ReportError((uint16)IODAL_MODULE_ID, (uint8)0U, IODAL_WRITEOUTPUTS_API_ID, IODAL_E_UNINIT);
#endif    
    }    
}

/*=====================================================================================================================*/
/*=====================================================================================================================*/
#ifdef __cplusplus
}
#endif
/** @} */
