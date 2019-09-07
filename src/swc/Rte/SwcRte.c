/**
    @file        SwcRte.c
*   @version     1.0.1
*
*   @brief       Integration Framework - SW component RTE file
*
*   @details     This file implements SwcRte file.  
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup SWCRTE
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
==================================================================================================*/
#include "typedefs.h"
#include "Std_Types.h"
#include "SwcRte.h"
#include "SwcRte_Types.h"
#include "SwcSensors.h"
#include "SwcActuators.h"


#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)
#include "SwcLighting.h"
#endif

#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)
#include "SwcMotorCtrl.h"
#endif

#if (SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)
#include "SwcVdr.h"
#endif

#if (SWCRTE_USE_IODAL == SWCRTE_STD_ON)
#include "IoDal.h"	
#endif

#if (SWCRTE_USE_SYSDAL == SWCRTE_STD_ON)
#include "SysDal.h"	
#endif

#if (SWCRTE_USE_MEMDAL == SWCRTE_STD_ON)
	
#endif

#if (SWCRTE_USE_COMDAL == SWCRTE_STD_ON)

#endif

/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCRTE_VENDOR_ID_C                          43

#define SWCRTE_SW_MAJOR_VERSION_C                   1
#define SWCRTE_SW_MINOR_VERSION_C                   0
#define SWCRTE_SW_PATCH_VERSION_C                   1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if SwcRte.c source file and SwcRte.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCRTE_VENDOR_ID)
    #error "SwcRte.c and SwcRte.h have different vendor ids"
#endif

/* Check if SwcRte.c source file and SwcRte.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCRTE_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcRte.h are different"
#endif

/* Check if SwcRte.c source file and  SwcRte_Types.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcRte.c and SwcRte_Types.h have different vendor ids"
#endif

/* Check if SwcRte.c source file and SwcRte_Types.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCRTE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcRte_Types.h are different"
#endif

/* Check if SwcRte.c source file and SwcSensors.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCSENSORS_VENDOR_ID)
    #error "SwcRte.c and SwcSensors.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcSensors.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCSENSORS_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCSENSORS_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCSENSORS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcSensors.h are different"
#endif

/* Check if SwcRte.c source file and SwcActuators.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCACTUATORS_VENDOR_ID)
    #error "SwcRte.c and SwcActuators.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcActuators.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCACTUATORS_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCACTUATORS_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCACTUATORS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcActuators.h are different"
#endif

#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)
/* Check if SwcRte.c source file and SwcLighting.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCLIGHTING_VENDOR_ID)
    #error "SwcRte.c and SwcLighting.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcLighting.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCLIGHTING_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCLIGHTING_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCLIGHTING_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcLighting.h are different"
#endif
#endif

#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)
/* Check if SwcRte.c source file and SwcMotorCtrl.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCMOTORCTRL_TYPES_VENDOR_ID)
    #error "SwcRte.c and SwcMotorCtrl.h have different vendor ids"
#endif

/* Check if SwcRte.c source file and SwcMotorCtrl.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCMOTORCTRL_TYPES_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCMOTORCTRL_TYPES_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCMOTORCTRL_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcMotorCtrl.h are different"
#endif
#endif

#if (SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)
/* Check if SwcRte.c source file and SwcVdr.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID_C != SWCVDR_TYPES_VENDOR_ID)
    #error "SwcRte.c and SwcVdr.h have different vendor ids"
#endif

/* Check if SwcRte.c source file and SwcVdr.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_C != SWCVDR_TYPES_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_C != SWCVDR_TYPES_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_C != SWCVDR_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.c and SwcVdr.h are different"
#endif
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
const SwcRte_GlobalConfigType * SwcRte_pGlobalCfgPtr = NULL_PTR;

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)
#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)
/*Global variable holding Lighting Actuator Data*/
AppLightingActuatorValueType   SwcRte_aLightingActuatorData[SWCRTE_MAX_LIGHTING_INSTANCES];

/*Global variable holding Lighting Sensor Data*/
AppLightingSensorValueType     SwcRte_aLightingSensorData[SWCRTE_MAX_LIGHTING_INSTANCES];

#if (SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)
/*Global variable holding Lighting COM Data*/
AppLightingComDataType         SwcRte_aLightingComData[SWCRTE_MAX_LIGHTING_INSTANCES];

/*Global variable holding Lighting Info Data*/
AppInfoType                    SwcRte_aLightingInfoData[SWCRTE_MAX_LIGHTING_INSTANCES];
#endif /*(SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)*/
#endif /*(SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)*/

#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)
/*Global variable holding Lighting Actuator Data*/
AppMotorCtrlActuatorValueType  SwcRte_aMotorCtrlActuatorData[SWCRTE_MAX_MOTORCTRL_INSTANCES];

/*Global variable holding Lighting Sensor Data*/
AppMotorCtrlSensorValueType    SwcRte_aMotorCtrlSensorData[SWCRTE_MAX_MOTORCTRL_INSTANCES];

#if (SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)
/*Global variable holding Lighting COM Data*/
AppMotorCtrlComDataType        SwcRte_aMotorCtrlComData[SWCRTE_MAX_MOTORCTRL_INSTANCES];

/*Global variable holding Lighting Info Data*/
AppInfoType                    SwcRte_aMotorCtrlInfoData[SWCRTE_MAX_MOTORCTRL_INSTANCES];
#endif  /*(SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)*/
#endif /*(SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)*/
#endif /*(SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*=================================================================================================*/
/**
@brief      SwcSensors_Init - Initialization function for Rte
@details    This function shall be used to initialize global data used by SwcRte

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all SWC components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*===================================================================================================*/
void SwcRte_Init(const SwcRte_GlobalConfigType * ConfigPtr)
{
    uint8_t InstanceIdx = 0;
    
    if(NULL_PTR != ConfigPtr) 
    {    
        SwcRte_pGlobalCfgPtr = ConfigPtr;
        
        SwcSensors_Init(ConfigPtr);        

#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)
        SwcLighting_Init(ConfigPtr);
#endif

#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)
        SwcMotorCtrl_Init(ConfigPtr);
#endif

#if (SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)
        SwcVdr_Init(ConfigPtr);
#endif
    
        SwcActuators_Init(ConfigPtr);

#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)        
#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)    
        for (InstanceIdx = 0; InstanceIdx < SWCRTE_MAX_LIGHTING_INSTANCES; InstanceIdx++)
        {
            /*initialize all lighting data*/
        }
#endif

#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)        
        for (InstanceIdx = 0; InstanceIdx < SWCRTE_MAX_MOTORCTRL_INSTANCES; InstanceIdx++)
        {
            /*initialize all mc data*/
        }
#endif 
#endif/*SWCRTE_USE_RTE_BUFFERS*/      
    }
}

#if (SWCRTE_SINGLE_TASK_APPLICATION == SWCRTE_STD_ON)        
/*===================================================================================================*/
/**
@brief      SwcRte_MainRunnable - main processing function for Rte
@details    This function is called periodically by the OS or by the main() function.
            On each entry, the RTE runnable will process all other application runnables.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*===================================================================================================*/
void SwcRte_MainRunnable()
{
    uint8_t InstanceIdx = 0;

    SwcSensors_MainRunnable();
        
#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)        
    for (InstanceIdx = 0; InstanceIdx < SWCRTE_MAX_LIGHTING_INSTANCES; InstanceIdx++)
    {
        SwcLighting_MainRunnable(InstanceIdx);
    }
#endif

    SwcActuators_MainRunnable();
}
#endif/*SWCRTE_SINGLE_TASK_APPLICATION*/

#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)        
#if (SWCRTE_VDR_APP_ENABLED  ==SWCRTE_STD_ON)   
	
/*======================================================================================================
                                            GOBAL FUNCTIONS FOR LIGHTING APP
=======================================================================================================*/

/*======================================================================================================*/
/**
@brief      SwcRte_ReadLightingComData – shall read any COM data provided by the VDR application. 

@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data read from COM for that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void  SwcRte_ReadLightingComData (SwcRte_AppInstanceIdType LightingInstance, AppLightingComDataType * Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t ChIndex = 0;
     
    Value->u8LightingOutputChannels =  SwcRte_aLightingComData[LightingInstance].u8LightingOutputChannels;
     
    for(ChIndex = 0; ChIndex < SWCRTE_MAX_LIGHTING_CHANNELS; ChIndex++)
    {
        if (0 != ((Value->u8LightingOutputChannels) & (1 << ChIndex)))
        {     
            Value->aLightingOutputIntesity[ChIndex] = SwcRte_aLightingComData[LightingInstance].aLightingOutputIntesity[ChIndex];
        }
    }
#endif 
}

/*==========================================================================================================*/
/**
@brief      SwcRte_WriteLightingComData - shall write a value required to update a state of the light
            source associated to the given Lighting application instance, which was requested by a COM message.

@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data written to COM by that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void  SwcRte_WriteLightingComData(SwcRte_AppInstanceIdType LightingInstance, AppLightingComDataType * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)   
    uint8_t ChIndex = 0;
     
    SwcRte_aLightingComData[LightingInstance].u8LightingOutputChannels = Value->u8LightingOutputChannels;
     
    for(ChIndex = 0; ChIndex < SWCRTE_MAX_LIGHTING_CHANNELS; ChIndex++)
    {
        if (0 != ((Value->u8LightingOutputChannels) & (1 << ChIndex)))
        {    
            SwcRte_aLightingComData[LightingInstance].aLightingOutputIntesity[ChIndex] = Value->aLightingOutputIntesity[ChIndex];
        }
    }
#endif
}

/*==========================================================================================================*/
/**
@brief      SwcRte_ReadLightingComInfo - shall read any COM data provided by the VDR application. 

@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data read from COM by that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void  SwcRte_ReadLightingComInfo(SwcRte_AppInstanceIdType LightingInstance, AppInfoType * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;
    
    Value->u8NoOfInfoChars =  SwcRte_aLightingInfoData[LightingInstance].u8NoOfInfoChars;
    Value->eComChannel     =  SwcRte_aLightingInfoData[LightingInstance].eComChannel;     
    
    for(CharsIndex = 0; CharsIndex < Value->u8NoOfInfoChars; CharsIndex++)
    {
        Value->pComInfoString[CharsIndex] = SwcRte_aLightingInfoData[LightingInstance].pComInfoString[CharsIndex];
    }
#endif
}

/*==========================================================================================================*/
/**
@brief      SwcRte_WriteLightingComInfo  - shall write the data containing request to send relevant 
            status information regarding the light sources associated to current instance, 
			to any connected communication port.
			
@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data written to COM by that instance.
			
@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteLightingComInfo (SwcRte_AppInstanceIdType LightingInstance,  AppInfoType * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;

    SwcRte_aLightingInfoData[LightingInstance].u8NoOfInfoChars = Value->u8NoOfInfoChars;
    SwcRte_aLightingInfoData[LightingInstance].eComChannel     = Value->eComChannel;
     
    for(CharsIndex = 0; CharsIndex < Value.u8LightingOutputChannels; CharsIndex++)
    {
        SwcRte_aLightingInfoData[LightingInstance].pComInfoString[CharsIndex] = Value->pComInfoString[CharsIndex];
    }
#endif
}
#endif /*SWCRTE_VDR_APP_ENABLED*/

/*==========================================================================================================*/
/**
@brief      SwcRte_WriteLightingSensorData – shall write the sensor value for the given instance 
            of the Lighting application.

@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data written to Lighting application by Sensors for that instance.
			
@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteLightingSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType *Value) 
{   
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;    

    SwcRte_aLightingSensorData[LightingInstance].u8NoLightFeedbackChannels = Value->u8NoLightFeedbackChannels;    
    SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorValue =  Value->aLightOutputSensorData[0].u32LightingSensorValue;
    SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorType  =  Value->aLightOutputSensorData[0].u32LightingSensorType;
    SwcRte_aLightingSensorData[LightingInstance].bSensorValueUpdated = Value->bSensorValueUpdated;
    
    for(CharsIndex = 1; CharsIndex < SwcRte_pGlobalCfgPtr[LightingInstance].u8NoInputChannel; CharsIndex++)
    {
        if (0 != ((Value->u8NoLightFeedbackChannels) & (1 << ChIndex)))
        {
            SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[SensorChannelId].u32LightingSensorValue =  Value->aLightOutputSensorData[SensorChannelId].u32LightingSensorValue;
			
            SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[SensorChannelId].u32LightingSensorType  =  Value->aLightOutputSensorData[SensorChannelId].u32LightingSensorType;
        }
    }  
#endif
    
   SwcLighting_WriteSensorData(LightingInstance, Value);
}

/*==========================================================================================================*/
/**
@brief      SwcRte_ReadLightingOutputRequest – shall write the sensor value for the given instance 
            of the Lighting application.

@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data read from Sensors application by that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_ReadLightingSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType *Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;    

    Value->u8NoLightFeedbackChannels = SwcRte_aLightingSensorData[LightingInstance].u8NoLightFeedbackChannels;    
    Value->aLightOutputSensorData[0].u32LightingSensorValue = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorValue;
    Value->aLightOutputSensorData[0].u32LightingSensorType = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorType;
    Value->bSensorValueUpdated = SwcRte_aLightingSensorData[LightingInstance].bSensorValueUpdated;
    
    for(CharsIndex = 1; CharsIndex < SwcRte_pGlobalCfgPtr[LightingInstance].u8NoInputChannel; CharsIndex++)
    {
        if (0 != ((Value->u8NoLightFeedbackChannels) & (1 << ChIndex)))
        {
            Value->aLightOutputSensorData[SensorChannelId].u32LightingSensorValue = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[SensorChannelId].u32LightingSensorValue;
            Value->aLightOutputSensorData[SensorChannelId].u32LightingSensorType = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[SensorChannelId].u32LightingSensorType;
        }
    }  
#endif

   SwcLighting_ReadSensorData(LightingInstance, Value);
}

/*==========================================================================================================*/
/**
@brief      SwcRte_ReadLightingOutputRequest – shall read the sensor value for the given instance of 
            the Lighting application.

@param[in]  LightingInstance    Instance Index.
@param[out] Value               Data read from Lighting application by that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_ReadLightingOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType *Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t ChIndex = 0;

    for(ChIndex = 0; ChIndex < SwcRte_pGlobalCfgPtr[LightingInstance].u8NoOutputChannel; ChIndex++)
    { 
        Value->aLightingOutputIntesity[ChIndex] = SwcRte_aLightingActuatorData[LightingInstance].aLightingOutputIntesity[ChIndex];
    }
#endif

   SwcLighting_ReadOutputRequest(LightingInstance, Value);
}

/*==========================================================================================================*/
/**
@brief      SwcRte_WriteLightingOutputRequest – shall write the sensor value for the given instance of the
            Lighting application.

@param[in]  LightingInstance    Instance Index.
@param[out] Value          Data written by Lighting for Actuators application for that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteLightingOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType *Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t ChIndex = 0;     
     
    for(ChIndex = 0; ChIndex < SwcRte_pGlobalCfgPtr[LightingInstance].u8NoOutputChannel; ChIndex++)
    { 
        SwcRte_aLightingActuatorData[LightingInstance].aLightingOutputIntesity[ChIndex] = Value->aLightingOutputIntesity[ChIndex];
    }
#endif

   SwcLighting_WriteOutputRequest(LightingInstance, Value);
}
#endif/*SWCRTE_LIGTHING_APP_ENABLED*/


#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)
/*===========================================================================================================
                                 GOBAL FUNCTIONS FOR MOTOR CONTROL APP
============================================================================================================*/

/*==========================================================================================================*/
/**
@brief      SwcRte_ReadMotorCtrlSensorData – shall read the sensors value associated to the Motor Control application

@details    The Data provided by Sensor Application shall contain two distinct types of information:
              -  Output update requests coming from HW buttons or potentiometers needed to change the output of the motor
              -  Feedback information coming from the motor. 

@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data read by MotorControl from Sensors application for that instance.			  
			  
@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_ReadMotorCtrlSensorData(SwcRte_AppInstanceIdType MotorCtrlInstance, AppMotorCtrlSensorValueType * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t ChIndex = 0;
     
    Value->u8NoMotorCtrlFbkChannels   =  SwcRte_aMotorCtrlSensorData[LightingInstance].u8NoMotorCtrlFbkChannels;
    Value->u32MotorCtrlSensorValue    =  SwcRte_aMotorCtrlSensorData[LightingInstance].u32MotorCtrlSensorValue;
     
    for(ChIndex = 0; ChIndex < SWCRTE_MOTORCTRL_FBK_LINES; ChIndex++)
    {
        if (0 != ((Value->u8NoMotorCtrlFbkChannels) & (1 << ChIndex)))
        {        
            Value->aMotorCtrlOutputFeedback[ChIndex] = SwcRte_aMotorCtrlSensorData[LightingInstance].aMotorCtrlOutputFeedback[ChIndex];
        }
    }
#endif
}

/*==========================================================================================================*/
/**
@brief      SwcRte_WriteMotorCtrlSensorData – shall write the sensor value for the given instance of the 
            Motor Control application.


@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data written by Sensors for MotorControl application for that instance.	

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteMotorCtrlSensorData (SwcRte_AppInstanceIdType MotorCtrlInstance, AppMotorCtrlSensorValueType * Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;
     
    SwcRte_aMotorCtrlSensorData[LightingInstance].u8NoMotorCtrlFbkChannels = Value->u8NoMotorCtrlFbkChannels;
    SwcRte_aMotorCtrlSensorData[LightingInstance].u32MotorCtrlSensorValue   = Value->u32MotorCtrlSensorValue;
         
    for(CharsIndex = 0; CharsIndex < SWCRTE_MOTORCTRL_FBK_LINES; CharsIndex++)
    {
        if (0 != ((Value->u8NoMotorCtrlFbkChannels) & (1 << ChIndex)))
        {
            SwcRte_aMotorCtrlSensorData[LightingInstance].aMotorCtrlOutputFeedback[ChIndex] = Value->aMotorCtrlOutputFeedback[ChIndex];
        }
    }
#endif
}

/*==========================================================================================================*/
/**
@brief      SwcRte_ReadMotorCtrlOutputRequest – This function shall read any output change request coming from the 
            Motor-Control Application, process these request and store the values in the internal data 
			so it will be sent to IoDal via SwcActuator_WriteOutputs().

@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data read by Actuators from MotorControl application for that instance.	

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_ReadMotorCtrlOutputRequest(SwcRte_AppInstanceIdType MotorCtrlInstance, AppMotorCtrlActuatorValueType  * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)
    Value->u32MotorCtrlOutputSpeed =  SwcRte_aMotorCtrlActuatorData[MotorCtrlInstance].u32MotorCtrlOutputSpeed;
    Value->u32MotorCtrlOutputSpeed =  SwcRte_aMotorCtrlActuatorData[MotorCtrlInstance].eMotorCtrlOutputDirection;
#endif
    
    SwcMotorCtrl_ReadOutputRequest(MotorCtrlInstance, Value);    
}


/*==========================================================================================================*/
/**
@brief      SwcRte_WriteMotorCtrlOutputRequest - shall write the data containing request to change the output values for the 
                                                 motor associated to current application  instance.

@details    Any output request should contain the following information:
                -    “Direction for rotation” (CW/CCW) or “Stop”      
                -    New Motor Speed (percent from maximum value) if command is not “Stop”

@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data written by Actuators from MotorControl application for that instance.	
				
@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteMotorCtrlOutputRequest (SwcRte_AppInstanceIdType MotorCtrlInstance,  AppMotorCtrlActuatorValueType * Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)      
    SwcRte_aMotorCtrlActuatorData[MotorCtrlInstance].u32MotorCtrlOutputSpeed   = Value->u32MotorCtrlOutputSpeed;
    SwcRte_aMotorCtrlActuatorData[MotorCtrlInstance].eMotorCtrlOutputDirection = Value->u32MotorCtrlOutputSpeed;
#endif    
}

#if (SWCRTE_VDR_APP_ENABLED  ==SWCRTE_STD_ON)
/*==========================================================================================================*/
/**
@brief      SwcRte_ReadMotorCtrlComData  –  shall read any COM data provided by the VDR application required by Motor Control
                                            to update the output parameter of the motor associated to the current instance. 

@param[in]  MotorCtrlInstance    Instance Index.
@param[out] OutputValue          Data read by COM for that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_ReadMotorCtrlComData (SwcRte_AppInstanceIdType MotorCtrlInstance, AppMotorCtrlComDataType * OutputValue) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    OutputValue->u32MotorCtrlOutputSpeed =  SwcRte_aMotorCtrlComData[MotorCtrlInstance].u32MotorCtrlOutputSpeed;
    OutputValue->u32MotorCtrlOutputSpeed =  SwcRte_aMotorCtrlComData[MotorCtrlInstance].eMotorCtrlOutputDirection;
#endif    
}

/*==========================================================================================================*/
/**
@brief      SwcRte_WriteMotorCtrlComData shall write a value required to update a state of the light source associated to the given
             Motor-control application instance, which was requested by a COM message.
			 
@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data written to COM by that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteMotorCtrlComData(SwcRte_AppInstanceIdType MotorCtrlInstance, AppMotorCtrlComDataType * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    SwcRte_aMotorCtrlComData[MotorCtrlInstance].u32MotorCtrlOutputSpeed   = Value->u32MotorCtrlOutputSpeed;
    SwcRte_aMotorCtrlComData[MotorCtrlInstance].eMotorCtrlOutputDirection = Value->u32MotorCtrlOutputSpeed;
#endif    
}

/*==========================================================================================================*/
/**
@brief      SwcRte_ReadMotorCtrlComInfo - shall write the data containing request to change the output values 
            for the light sourcecs (LEDs) associated to current application instance. 
			
@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data read by COM for that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_ReadMotorCtrlComInfo (SwcRte_AppInstanceIdType MotorCtrlInstance,  AppInfoType * Value)
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;
    
    Value->u8NoOfInfoChars =  SwcRte_aMotorCtrlInfoData[LightingInstance].u8NoOfInfoChars;
    Value->eComChannel     =  SwcRte_aMotorCtrlInfoData[LightingInstance].eComChannel;     
    
    for(CharsIndex = 0; CharsIndex < Value->u8NoOfInfoChars; CharsIndex++)
    {
        Value->pComInfoString[CharsIndex] = SwcRte_aMotorCtrlInfoData[LightingInstance].pComInfoString[CharsIndex];
    }
#endif
}


/*==========================================================================================================*/
/**
@brief      SwcRte_WriteMotorCtrlSensorData  - shall write the data containing request to send relevant 
            status information regarding the motor associated to current instance,
			to any connected communication port.

@param[in]  MotorCtrlInstance    Instance Index.
@param[out] Value                Data written by COM for that instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==========================================================================================================*/
void SwcRte_WriteMotorCtrlComInfo (SwcRte_AppInstanceIdType MotorCtrlInstance,  AppInfoType * Value) 
{    
#if (SWCRTE_USE_RTE_BUFFERS == SWCRTE_STD_ON)  
    uint8_t CharsIndex = 0;

    SwcRte_aLightingInfoData[LightingInstance].u8NoOfInfoChars = Value->u8NoOfInfoChars;
    SwcRte_aLightingInfoData[LightingInstance].eComChannel     = Value->eComChannel;
     
     
    for(CharsIndex = 0; CharsIndex < Value.u8LightingOutputChannels; CharsIndex++)
    {
        SwcRte_aLightingInfoData[LightingInstance].pComInfoString[CharsIndex] = Value->pComInfoString[CharsIndex];
    }    
#endif
}
#endif /*SWCRTE_VDR_APP_ENABLED*/
#endif /*SWCRTE_MOTORCTRL_APP_ENABLED*/

#if (SWCRTE_VDR_APP_ENABLED  ==SWCRTE_STD_ON)    
/*==============================================================================================================
                                 GOBAL FUNCTIONS FOR BSW INTERFACE
===============================================================================================================*/

/*=============================================================================================================*/
/**
@brief      SwcRte_ReadComData - shall read the value associated to a Actuator channel which determined by the ComDal component. 

@details

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*=============================================================================================================*/
void SwcRte_ReadComData (SwcRte_AppInstanceIdType AppInstance, AppComChannelType ComChannel, ComDalValueType * Value)
{    
    /*TODO*/
}

/*==============================================================================================================*/
/**
@brief      SwcRte_WriteComData - shall write the value associated to a Actuator channel which determined by the ComDal component. 

@details

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==============================================================================================================*/
void SwcRte_WriteComData (SwcRte_AppInstanceIdType AppInstance, AppComChannelType ComChannel, ComDalValueType Value)
{    
    /*TODO*/
}
#endif


/*==============================================================================================================*/
/**
@brief      SwcRte_ReadLightingComInfo - shall read the value associated to a Sensor channel which determined by the IoDal component. 

@details

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==============================================================================================================*/
void SwcRte_ReadInputs(SwcRte_AppInstanceIdType AppInstance, SwcRte_AppChannelIdType SensorChannel, SwcRte_AppInputValueType * InputValue) 
{        
    SwcRte_AppChannelIdType InputSensor;
    Std_ReturnType Ret_Val = E_NOT_OK;
    IoDal_BswValueType IoDalInputValue = 0;
    
    InputSensor = (SwcRte_pGlobalCfgPtr[AppInstance].pInstanceInputSensor[SensorChannel]).u8InputChannel;
    
    Ret_Val = IoDal_ReadInputs(InputSensor, &IoDalInputValue);    
    
    if (E_OK == Ret_Val)
    {    
        InputValue->Status = SWCRTE_MEAS_OK;    
        InputValue->Value =  (uint16)IoDalInputValue;
    }
    else
    {
        InputValue->Status = SWCRTE_MEAS_NOT_OK;        
        InputValue->Value = 0U;
    }
}

/*==============================================================================================================*/
/**
@brief      SwcRte_ReadLightingComInfo - shall write the value associated to a Actuator channel which is determined by the IoDal component. 


@details

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*==============================================================================================================*/
void SwcRte_WriteOutputs(SwcRte_AppInstanceIdType AppInstance, SwcRte_AppChannelIdType ActuatorChannel, SwcRte_OutputValueType OutputValue) 
{    
    SwcRte_AppChannelIdType OutputChannel;
    
    /*get output channel from the actuator channel in configuration */ 
    OutputChannel = SwcRte_pGlobalCfgPtr[AppInstance].pInstanceActuator[ActuatorChannel].u8OutputChannel;
    IoDal_WriteOutputs(OutputChannel, OutputValue);
}

/*================================================================================================*/
/*================================================================================================*/
#ifdef __cplusplus
}
#endif
