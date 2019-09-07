/**
*   @file       SwcSensors.c
*   @version    1.0.1
*
*   @brief      Integration Framework - Sensors SW component.
*
*   @details    This file implements application level handling of all inputs data coming 
*               from either analog or digital sources. 
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup SWCSENSORS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===================================================================================================*/
#include "typedefs.h"
#include "SwcSensors.h"
#include "SwcRte_Types.h"
#include "SwcRte.h"
#include "SwcRte_Cfg.h"

/*===================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCSENSORS_VENDOR_ID_C                          43

#define SWCSENSORS_SW_MAJOR_VERSION_C                   1
#define SWCSENSORS_SW_MINOR_VERSION_C                   0
#define SWCSENSORS_SW_PATCH_VERSION_C                   1
/*==================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================*/
/* Check if SwcSensors.c source file and SwcSensors.h header file are of the same vendor */
#if (SWCSENSORS_VENDOR_ID_C != SWCSENSORS_VENDOR_ID)
    #error "SwcSensors.c and SwcSensors.h have different vendor ids"
#endif

/* Check if SwcSensors.c source file and SwcSensors.h header file are of the same Software version */
#if ((SWCSENSORS_SW_MAJOR_VERSION_C != SWCSENSORS_SW_MAJOR_VERSION) || \
     (SWCSENSORS_SW_MINOR_VERSION_C != SWCSENSORS_SW_MINOR_VERSION) || \
     (SWCSENSORS_SW_PATCH_VERSION_C != SWCSENSORS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcSensors.c and SwcSensors.h are different"
#endif


/* Check if SwcSensors.c source file and  SwcRte.h header file are of the same vendor */
#if (SWCSENSORS_VENDOR_ID_C != SWCRTE_VENDOR_ID)
    #error "SwcSensors.c and SwcRte.h have different vendor ids"
#endif

/* Check if SwcSensors.c source file and SwcRte.h header file are of the same Software version */
#if ((SWCSENSORS_SW_MAJOR_VERSION_C != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCSENSORS_SW_MINOR_VERSION_C != SWCRTE_SW_MINOR_VERSION) || \
     (SWCSENSORS_SW_PATCH_VERSION_C != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcSensors.c and SwcRte.h are different"
#endif


/* Check if SwcSensors.c source file and SwcRte_Cfg.h header file are of the same vendor */
#if (SWCSENSORS_VENDOR_ID_C != SWCRTE_CFG_VENDOR_ID)
    #error "SwcSensors.c and SwcRte_Cfg.h have different vendor ids"
#endif


/* Check if SwcSensors.c source file and SwcRte_Cfg.h header file are of the same Software version */
#if ((SWCSENSORS_SW_MAJOR_VERSION_C != SWCRTE_CFG_SW_MAJOR_VERSION) || \
     (SWCSENSORS_SW_MINOR_VERSION_C != SWCRTE_CFG_SW_MINOR_VERSION) || \
     (SWCSENSORS_SW_PATCH_VERSION_C != SWCRTE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcSensors.c and SwcRte_Cfg.h are different"
#endif

/* Check if SwcSensors.c source file and SwcRte_Types.h header file are of the same vendor */
#if (SWCSENSORS_VENDOR_ID_C != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcSensors.c and SwcRte_Types.h have different vendor ids"
#endif


/* Check if SwcSensors.c source file and SwcRte_Types.h header file are of the same Software version */
#if ((SWCSENSORS_SW_MAJOR_VERSION_C != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCSENSORS_SW_MINOR_VERSION_C != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCSENSORS_SW_PATCH_VERSION_C != SWCRTE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcSensors.c and SwcRte_Types.h are different"
#endif


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#define  SWCSENSORS_MAX_DEBOUNCE  3U

/*==================================================================================================
                                      FILE VERSION CHECKS
===================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
===================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
===================================================================================================*/
#if SWCRTE_MAX_ANSENS_INSTANCES > 0
/*array of variable holding the current low count debounce value for channels using analog inputs
 (potentiometer) as main control devices */
/* array size is given by the number of instances using an analog input as main sensor*/
uint8_t SwcSensors_AnalogDebounceCounter[SWCRTE_MAX_APP_INSTANCES];
#endif 

#if SWCRTE_MAX_DISENS_INSTANCES > 0
/*array of variable holding the current high count debounce value for channels using digital inputs
 (buttons) as main control devices*/
 /* array size is given by the number of instances using a digital inputsas main sensor*/
uint8_t SwcSensors_DioSensorHighValueCounter[SWCRTE_MAX_APP_INSTANCES];

/*array of variable holding the current low count debounce value for channels using digital inputs
 (buttons) as main control devices*/
/* array size is given by the number of instances using a digital inputsas main sensor*/
uint8_t SwcSensors_DioSensorLowValueCounter[SWCRTE_MAX_APP_INSTANCES];
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
===================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
===================================================================================================*/

 
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
===================================================================================================*/
static const SwcRte_GlobalConfigType * SwcSensors_ConfigPtr;

/*===================================================================================================
                                       LOCAL FUNCTIONS
====================================================================================================*/


/*===================================================================================================
                                       GLOBAL FUNCTIONS
====================================================================================================*/

/*===================================================================================================*/
/**
@brief      SwcSensors_Init - Initialization function for Sensors
@details    This function shall be used to initialize global data used by SwcSensor

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all SWC components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*===================================================================================================*/
void SwcSensors_Init(const SwcRte_GlobalConfigType * ConfigPtr)
{
    SwcRte_AppInputSensorType SensorType;
    SwcRte_AppInstanceIdType RteAppInstance;
        
    SwcSensors_ConfigPtr = ConfigPtr;

    for (RteAppInstance=0; RteAppInstance < SWCRTE_MAX_APP_INSTANCES; RteAppInstance++)
    {
        SensorType = SwcSensors_ConfigPtr[RteAppInstance].pInstanceInputSensor[0].eInputType;
        
    #if SWCRTE_MAX_DISENS_INSTANCES > 0
        if(SWCRTE_DIGITAL_SENS == SensorType)
        {                
            SwcSensors_DioSensorHighValueCounter[RteAppInstance] = 0U;
            SwcSensors_DioSensorLowValueCounter[RteAppInstance] = 0U;
        }
    #endif
    #if SWCRTE_MAX_ANSENS_INSTANCES > 0
        if(SWCRTE_ANALOG_POT_SENS == SensorType)
        {    
            SwcSensors_AnalogDebounceCounter[RteAppInstance] = 0U;
        }    
    #endif
    }
}

/*===================================================================================================*/
/**
@brief      SwcSensors_MainRunnable - main processing function for Sensors
@details    This function is called periodically by the OS or by the main() function.
            On each entry, the Sensors runnable will process only the instance that is given as parameter.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*===================================================================================================*/
void SwcSensors_MainRunnable()
{
    SwcRte_AppChannelIdType SensorChannelId;
    SwcRte_AppInstanceIdType RteAppInstance;
    SwcRte_AppInputSensorType SensorType;
    SwcRte_AppInputValueType InputValue;
#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)        
    AppLightingSensorValueType  AppLightingWriteValue;
#endif
#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)    
   AppMotorCtrlSensorValueType  AppMotorCtrlWriteValue;
#endif

#if SWCRTE_MAX_DISENS_INSTANCES > 0    
    uint16_t SensorValue = 0;
#endif
    InputValue.Value =0;
    InputValue.Status = SWCRTE_MEAS_NOT_OK;
    
    for (RteAppInstance = 0; RteAppInstance < SWCRTE_MAX_APP_INSTANCES; RteAppInstance++)
    {
    #if SWCRTE_MAX_DISENS_INSTANCES > 0        
        AppLightingWriteValue.bSensorValueUpdated = SWCRTE_FALSE;
		AppLightingWriteValue.u8NoLightFeedbackChannels  = 0;
    #endif
        /*for all available inputs */        
        for (SensorChannelId = 0; SensorChannelId < SwcSensors_ConfigPtr[RteAppInstance].u8NoInputChannel; SensorChannelId++)
        {                   
            /*get the sensor channel id base on type of channel  */            
            SensorType = SwcSensors_ConfigPtr[RteAppInstance].pInstanceInputSensor[SensorChannelId].eInputType;       
            
            SwcRte_ReadInputs(RteAppInstance, SensorChannelId,  &InputValue);
 
        #if SWCRTE_MAX_DISENS_INSTANCES > 0   
            AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorValue = 0;
        #endif    
                       
            /*process values differently depending on their type*/
            switch (SensorType)
            {                
            #if SWCRTE_MAX_DISENS_INSTANCES > 0
                case SWCRTE_DIGITAL_SENS:
                {                                
                    if (SWCRTE_BUTTON_ON == (SwcRte_InputStateType)InputValue.Value) 
                    {    
                        /*increment ON counter*/
                        SwcSensors_DioSensorHighValueCounter[RteAppInstance]++;
                        
                        /*decrement OFF counter*/
                        SwcSensors_DioSensorLowValueCounter[RteAppInstance] = 0U;
                      
                        /*is ON counter max value?*/
                        if (SwcSensors_DioSensorHighValueCounter[RteAppInstance] > SWCSENSORS_MAX_DEBOUNCE)
                        {    
                            SensorValue = (uint16_t)SWCRTE_BUTTON_ON;
                            SwcSensors_DioSensorHighValueCounter[RteAppInstance] = 0U;
                            AppLightingWriteValue.bSensorValueUpdated = SWCRTE_TRUE;                              
                        }                        
                    }
                    else
                    {    
                        /*increment ON counter*/
                        SwcSensors_DioSensorHighValueCounter[RteAppInstance]= 0U;
                        
                        /*decrement OFF counter*/
                        SwcSensors_DioSensorLowValueCounter[RteAppInstance]++;
                                                
                        /*is ON counter max value?*/
                        if (SwcSensors_DioSensorLowValueCounter[RteAppInstance] > SWCSENSORS_MAX_DEBOUNCE)
                        {    
                            SensorValue = (uint16_t)SWCRTE_BUTTON_OFF;
                            SwcSensors_DioSensorLowValueCounter[RteAppInstance] = 0U;
                            AppLightingWriteValue.bSensorValueUpdated = SWCRTE_TRUE;  
                        }    
                    }
                    
                    #if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)                        
                    if(SWCRTE_LIGHTING == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                    {                        
                        AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorType = SensorType;
                        
                        AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorValue = SensorValue;                 
                    }
                    #endif    
                    
                    #if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)                
                    if(SWCRTE_MOTORCTRL == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                    {
                        AppMotorCtrlWriteValue.u32MotorCtrlSensorValue = SensorValue;
                    }    
                    #endif                    
                }
                break;
            #endif
                
            #if SWCRTE_MAX_ANSENS_INSTANCES > 0
                case SWCRTE_ANALOG_POT_SENS:
                {    
                    if(SWCRTE_MEAS_OK == InputValue.Status)
                    {
                        #if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)                            
                        if(SWCRTE_LIGHTING == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                        {    
                            AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorType = SensorType;
                            
                            AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorValue = InputValue.Value;
                            
                            AppLightingWriteValue.bSensorValueUpdated = SWCRTE_TRUE;
                        }
                        #endif                    
                        #if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)        
                        if(SWCRTE_MOTORCTRL == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                        {
                            AppMotorCtrlWriteValue.u32MotorCtrlSensorValue = InputValue.Value;
                        }
                        #endif

                        /*reset Debounce counter*/
                        SwcSensors_AnalogDebounceCounter[RteAppInstance] = 0U;
                    }
                    else
                    {
                        /*increment debounce read variable from that channel*/
                        SwcSensors_AnalogDebounceCounter[RteAppInstance]++;                                

                        /*check if debaunce continuation occurred*/
                        if (SwcSensors_AnalogDebounceCounter[RteAppInstance] > SWCSENSORS_MAX_DEBOUNCE)
                        {
                            SwcSensors_AnalogDebounceCounter[RteAppInstance] = 0U;
                            /*inform user about invalid sensor input*/    
                            /*TODO:  call VDR to log error info*/
                        }
                        else
                        {
                            /*do nothing*/
                        }        
                    }
                }
                break;                    
                    
                case SWCRTE_ANALOG_FDBK_SENS:            
                {
                    #if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)    
                    if(SWCRTE_LIGHTING == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                    {
                        AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorValue = InputValue.Value;
                        
                        AppLightingWriteValue.aLightOutputSensorData[SensorChannelId].u32LightingSensorType = SensorType;
                        
                        if(InputValue.Status == SWCRTE_MEAS_OK)
                        {
                            AppLightingWriteValue.u8NoLightFeedbackChannels |= (1 << SensorChannelId);    
                        }
                    }
                    #endif
                    #if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)                    
                    if(SWCRTE_MOTORCTRL == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                    {
                        AppMotorCtrlWriteValue.aMotorCtrlOutputFeedback[SensorChannelId] = InputValue.Value;    
                                                            
                        if(InputValue.Status == SWCRTE_MEAS_OK)
                        {    
                            AppMotorCtrlWriteValue.u8NoMotorCtrlFbkChannels |= (1 << SensorChannelId);
                        }                        
                    }
                    #endif
                }
                break;
            #endif
                                    
                case SWCRTE_INPUT_CAPTURE_SENS:
                {
                    #if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)
                    if(SWCRTE_MOTORCTRL == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
                    {
                        AppMotorCtrlWriteValue.aMotorCtrlOutputFeedback[SensorChannelId] = InputValue.Value;        
                    }
                    else
                    {
                        /*do nothing*/
                    }      
                    #endif                    
                }
                break;
                    
                case SWCRTE_NO_SENS:

                break;  
                default:

                break;                
            }       
        }          
   
    #if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)    
        if(SWCRTE_LIGHTING == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
        {                
             SwcRte_WriteLightingSensorData(RteAppInstance, &AppLightingWriteValue);            
        }
    #endif    
    #if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)    
        if(SWCRTE_MOTORCTRL == SwcSensors_ConfigPtr[RteAppInstance].eInstanceType)
        {
             SwcRte_WriteMotorCtrlSensorData((RteAppInstance - SWCRTE_MOTORCTRL_INSTANCE_OFFSET), &AppMotorCtrlWriteValue);    
        }
    #endif    
    }  
}


/*================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */