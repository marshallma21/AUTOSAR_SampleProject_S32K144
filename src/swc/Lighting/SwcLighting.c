/**
*    @file        SwcLighting.c
*    @version     1.0.1
*
*    @brief       Integration Framework - Lighting SW component.
*
*    @details     Implementation from the lighting application.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup SWCLIGHTING
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
#include "SwcLighting.h"
#include "SwcRte_Types.h"
#include "SwcRte.h"
#include "SwcRte_Cfg.h"

/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCLIGHTING_VENDOR_ID_C                          43

#define SWCLIGHTING_SW_MAJOR_VERSION_C                   1
#define SWCLIGHTING_SW_MINOR_VERSION_C                   0
#define SWCLIGHTING_SW_PATCH_VERSION_C                   1
/*==================================================================================================
*                                     FILE VERSION CHECKS
===================================================================================================*/
/* Check if SwcLighting.c source file and SwcLighting.h header file are of the same vendor */
#if (SWCLIGHTING_VENDOR_ID_C != SWCLIGHTING_VENDOR_ID)
    #error "SwcLighting.c and SwcLighting.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcLighting.h header file are of the same Software version */
#if ((SWCLIGHTING_SW_MAJOR_VERSION_C != SWCLIGHTING_SW_MAJOR_VERSION) || \
     (SWCLIGHTING_SW_MINOR_VERSION_C != SWCLIGHTING_SW_MINOR_VERSION) || \
     (SWCLIGHTING_SW_PATCH_VERSION_C != SWCLIGHTING_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcLighting.c and SwcLighting.h are different"
#endif

/* Check if SwcLighting.c source file and  SwcRte.h header file are of the same vendor */
#if (SWCLIGHTING_VENDOR_ID_C != SWCRTE_VENDOR_ID)
    #error "SwcLighting.c and SwcRte.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcRte.h header file are of the same Software version */
#if ((SWCLIGHTING_SW_MAJOR_VERSION_C != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCLIGHTING_SW_MINOR_VERSION_C != SWCRTE_SW_MINOR_VERSION) || \
     (SWCLIGHTING_SW_PATCH_VERSION_C != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcLighting.c and SwcRte.h are different"
#endif


/* Check if SwcLighting.c source file and SwcRte_Cfg.h header file are of the same vendor */
#if (SWCLIGHTING_VENDOR_ID_C != SWCRTE_CFG_VENDOR_ID)
    #error "SwcLighting.c and SwcRte_Cfg.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcRte_Cfg.h header file are of the same Software version */
#if ((SWCLIGHTING_SW_MAJOR_VERSION_C != SWCRTE_CFG_SW_MAJOR_VERSION) || \
     (SWCLIGHTING_SW_MINOR_VERSION_C != SWCRTE_CFG_SW_MINOR_VERSION) || \
     (SWCLIGHTING_SW_PATCH_VERSION_C != SWCRTE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcLighting.c and SwcRte_Cfg.h are different"
#endif


/* Check if SwcLighting.c source file and SwcRte_Types.h header file are of the same vendor */
#if (SWCLIGHTING_VENDOR_ID_C != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcLighting.c and SwcRte_Types.h have different vendor ids"
#endif

/* Check if SwcLighting.c source file and SwcRte_Types.h header file are of the same Software version */
#if ((SWCLIGHTING_SW_MAJOR_VERSION_C != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCLIGHTING_SW_MINOR_VERSION_C != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCLIGHTING_SW_PATCH_VERSION_C != SWCRTE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcLighting.c and SwcRte_Types.h are different"
#endif



/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#define SWCLIGHTING_DIMMING_FACTOR           (4096U)
#define SWCLIGHTING_FIRST_BUTTON_PRESS       (1U)
#define SWCLIGHTING_SECOND_BUTTON_PRESS      (2U)
#define SWCLIGHTING_MAX_DIMMING_INCREMENT    (8U)
#define SWCLIGHTING_PWM_MAX_DUTY_CYCLE       (0x8000U) 
#define SWCLIGHTING_AVG_SUM_COUNT             4U
#define SWCLIGHTING_AVG_DENOMINATOR_SHIFT     2U
#define SWCLIGHTING_MAX_TRANSIENT_ERR_COUNT   2U
#define SWCLIGHTING_MAX_FBK_ERR_VALUE         100U
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
static const SwcRte_GlobalConfigType * SwcLighting_ConfigPtr;
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
/*Global variable holding Lighting Actuator Data*/
AppLightingActuatorValueType    SwcRte_aLightingActuatorData[SWCRTE_MAX_LIGHTING_INSTANCES];

/*Global variable holding Lighting Sensor Data*/
AppLightingSensorValueType      SwcRte_aLightingSensorData[SWCRTE_MAX_LIGHTING_INSTANCES];


#if (SWCRTE_VDR_APP_ENABLED == SWCRTE_STD_ON)
/*Global variable holding Lighting Info Data*/
AppInfoType                     SwcRte_aLightingInfoData[SWCRTE_MAX_LIGHTING_INSTANCES];

/*Global variable holding Lighting COM Data*/
AppLightingComDataType          SwcRte_aLightingComData[SWCRTE_MAX_LIGHTING_INSTANCES];
#endif


static SwcRte_ChannelStateType  SwcLighting_ChannelState[SWCRTE_MAX_LIGHTING_INSTANCES][SWCRTE_MAX_LIGHTING_CHANNELS];
static SwcRte_InstanceStateType SwcLightning_InstanceState[SWCRTE_MAX_LIGHTING_INSTANCES];



static SwcRte_InputStateType    SwcLighting_PreviosButtonState[SWCRTE_MAX_LIGHTING_INSTANCES];
static SwcRte_InputStateType    SwcLighting_ButtonState[SWCRTE_MAX_LIGHTING_INSTANCES];
static uint16_t                 SwcLighting_OutputValue[SWCRTE_MAX_LIGHTING_INSTANCES];
static uint32_t                 SwcLighting_SumFeedbackValue[SWCRTE_MAX_LIGHTING_INSTANCES][SWCRTE_MAX_LIGHTING_CHANNELS];
static uint8_t                  SwcLighting_AvgValueCounter[SWCRTE_MAX_LIGHTING_INSTANCES][SWCRTE_MAX_LIGHTING_CHANNELS];
static uint16_t                 SwcLighting_AvgFeedbackValue[SWCRTE_MAX_LIGHTING_INSTANCES][SWCRTE_MAX_LIGHTING_CHANNELS];
static uint8_t                  SwcLighting_CountTransientError[SWCRTE_MAX_LIGHTING_INSTANCES][SWCRTE_MAX_LIGHTING_CHANNELS];
static uint8_t                  SwcLighting_CountButtonPressed[SWCRTE_MAX_LIGHTING_INSTANCES];
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void SwcLighting_CalculateOuputValue(SwcRte_AppInstanceIdType RteAppInstance);
static void SwcLighting_ProcessFeedback(SwcRte_AppInstanceIdType RteAppInstance);
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
@brief      SwcLighting_CalculateOuputValue - calculate the next output value for all channels
            of a given instance
@details    Depending on the channels type this function shall calculate the next output value for 
            all channels of the given instance.
            			
@param[in]  RteAppInstance    Instance Index.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
static void SwcLighting_CalculateOuputValue(SwcRte_AppInstanceIdType RteAppInstance)
{
    uint8_t ChIndex = 0;
    uint32_t PotValue   = 0;
    
	/*get sensor type*/
    switch(SwcLighting_ConfigPtr[RteAppInstance].pInstanceInputSensor[0].eInputType)
    {
        case SWCRTE_DIGITAL_SENS:  /*if sensor is digital buttons*/
        {
            /*if button was pressed and than released */
            SwcLighting_ButtonState[RteAppInstance] = (SwcRte_InputStateType)SwcRte_aLightingSensorData[RteAppInstance].aLightOutputSensorData[0].u32LightingSensorValue;

            if(SWCRTE_BUTTON_ON == SwcLighting_ButtonState[RteAppInstance])
            {
                if(SWCRTE_BUTTON_ON == SwcLighting_PreviosButtonState[RteAppInstance])
                {    
                    SwcLighting_CountButtonPressed[RteAppInstance]++;
                    SwcLighting_PreviosButtonState[RteAppInstance] = SWCRTE_BUTTON_OFF;
                }
            }
            else
            {
                if(SWCRTE_BUTTON_OFF == SwcLighting_PreviosButtonState[RteAppInstance])
                {                        
                    SwcLighting_PreviosButtonState[RteAppInstance] = SWCRTE_BUTTON_ON;                                
                }                    
            }

            if(SwcLighting_ConfigPtr[RteAppInstance].eOutputType == SWCRTE_PWM_OUT)
            {                
                if(SwcLighting_CountButtonPressed[RteAppInstance] > SWCLIGHTING_MAX_DIMMING_INCREMENT)
                {
                    SwcLighting_CountButtonPressed[RteAppInstance] = 0;
                    SwcLighting_OutputValue[RteAppInstance] = SWCRTE_BUTTON_OFF;
                }
                else
                {
                    SwcLighting_OutputValue[RteAppInstance] = (SwcLighting_CountButtonPressed[RteAppInstance] * SWCLIGHTING_DIMMING_FACTOR);
                }                
            }
            else
            {
                if(SWCLIGHTING_FIRST_BUTTON_PRESS == SwcLighting_CountButtonPressed[RteAppInstance])
                {    
                    SwcLighting_OutputValue[RteAppInstance] = SWCRTE_BUTTON_ON;
                }
                
                if(SWCLIGHTING_SECOND_BUTTON_PRESS == SwcLighting_CountButtonPressed[RteAppInstance])
                {    
                    SwcLighting_OutputValue[RteAppInstance] = SWCRTE_BUTTON_OFF;
                    SwcLighting_CountButtonPressed[RteAppInstance] = 0U;
                }    
            }            
        } break;
        
        case SWCRTE_ANALOG_POT_SENS: /*if sensor is analog potentiometer*/
        {
            /*calculate dimming based of sensor_value*/
            PotValue = SwcRte_aLightingSensorData[RteAppInstance].aLightOutputSensorData[0].u32LightingSensorValue;

            SwcLighting_OutputValue[RteAppInstance] = ((PotValue * SWCLIGHTING_PWM_MAX_DUTY_CYCLE) >> SWCRTE_ADC_RESOLUTION);

        } break;

        case SWCRTE_COM_DATA_INPUT:
        {
           /*TODO: Read COM data from VDR */
        } break;
    }
       
    /*TODO:  ALL THE output requests need to be marked as atomic operations*/
    
    /*The output are handled based on the previos feedback result*/
    /*If any error was detected/reported on an output channle than that output channel shall be removed from output update table*/
    for (ChIndex=0; ChIndex < SwcLighting_ConfigPtr[RteAppInstance].u8NoOutputChannel; ChIndex++)
    {
        if (SwcLighting_OutputValue[RteAppInstance] != 0)
        {
            if(SwcLighting_ChannelState[RteAppInstance][ChIndex] == SWCRTE_CHANNEL_STOPPED)
            {        
                SwcLighting_ChannelState[RteAppInstance][ChIndex] = SWCRTE_CHANNEL_ACTIVE;
            }
        }
        else
        {
            if(SwcLighting_ChannelState[RteAppInstance][ChIndex] == SWCRTE_CHANNEL_ACTIVE)
            {    
                SwcLighting_ChannelState[RteAppInstance][ChIndex] = SWCRTE_CHANNEL_STOPPED;
            }    
        }
        SwcRte_aLightingActuatorData[RteAppInstance].aLightingOutputIntesity[ChIndex] = SwcLighting_OutputValue[RteAppInstance];
    }    
}

/*================================================================================================*/
/**
@brief      SwcLighting_ProcessFeedback - shall process feedback information for all channels 
            of a given instance that have analog feedback


@param[in]  RteAppInstance    Instance Index.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
static void SwcLighting_ProcessFeedback(SwcRte_AppInstanceIdType RteAppInstance)
{
    uint16_t ChFbkValue = 0;
    uint8_t ChIndex =0;
    
    /*get current fdbk value (amperes) for each feedback channel*/

    for (ChIndex=0; ChIndex < SwcLighting_ConfigPtr[RteAppInstance].u8NoOutputChannel; ChIndex++)
    {
        /*declare/define all varialbe in application*/
        if(SWCRTE_CHANNEL_ACTIVE == SwcLighting_ChannelState[RteAppInstance][ChIndex])
        {
            ChFbkValue = SwcRte_aLightingSensorData[RteAppInstance].aLightOutputSensorData[ChIndex].u32LightingSensorValue;


            if(ChFbkValue > SWCLIGHTING_MAXIMUM_ANALOG_FDBK_VALUE) /*if value over maximum limit and channel is used and operational*/
            {
                /*mark output channel as having: short circuit to gnd*/
                SwcLighting_ChannelState[RteAppInstance][ChIndex] = SWCRTE_CHANNEL_SHORT2GND;

                /*set output to OFF*/
                SwcRte_aLightingActuatorData[RteAppInstance].aLightingOutputIntesity[ChIndex] = SWCRTE_BUTTON_OFF;

                /*TODO: Send Com info regarding issue via VDR */
            }
            else if(ChFbkValue < SWCLIGHTING_MINIMUM_ANALOG_FDBK_VALUE) /*if value is 0 and channel is used and operational*/
            {
                /*mark output channel as having: open load*/
                SwcLighting_ChannelState[RteAppInstance][ChIndex] = SWCRTE_CHANNEL_OPEN_LOAD;


                /*set output to OFF*/
                SwcRte_aLightingActuatorData[RteAppInstance].aLightingOutputIntesity[ChIndex] = SWCRTE_BUTTON_OFF;
                
                /*TODO: Send Com info regarding issue via VDR*/
            }
            else
            {
                /*calculate avarage feedback for each channel*/
                SwcLighting_SumFeedbackValue[RteAppInstance][ChIndex] = SwcLighting_SumFeedbackValue[RteAppInstance][ChIndex] + ChFbkValue;
                
                SwcLighting_AvgValueCounter[RteAppInstance][ChIndex]++;                
                
                if(SwcLighting_AvgValueCounter[RteAppInstance][ChIndex] > SWCLIGHTING_AVG_SUM_COUNT)
                {
                    SwcLighting_AvgFeedbackValue[RteAppInstance][ChIndex] = (SwcLighting_SumFeedbackValue[RteAppInstance][ChIndex] >> SWCLIGHTING_AVG_DENOMINATOR_SHIFT);
                    SwcLighting_AvgValueCounter[RteAppInstance][ChIndex] = 0;

                    /*update sum value with avarage feedback for each channel*/
                    SwcLighting_SumFeedbackValue[RteAppInstance][ChIndex] = SwcLighting_AvgFeedbackValue[RteAppInstance][ChIndex];                    

                    if (((ChFbkValue > (SwcLighting_AvgFeedbackValue[RteAppInstance][ChIndex] + SWCLIGHTING_MAX_FBK_ERR_VALUE))) || 
                        (ChFbkValue < (SwcLighting_AvgFeedbackValue[RteAppInstance][ChIndex] - SWCLIGHTING_MAX_FBK_ERR_VALUE)))
                    {
                        SwcLighting_CountTransientError[RteAppInstance][ChIndex]++;
                    }
                    else
                    {
                        SwcLighting_CountTransientError[RteAppInstance][ChIndex] = 0;
                    }
                }
                
                if(SwcLighting_CountTransientError[RteAppInstance][ChIndex] > SWCLIGHTING_MAX_TRANSIENT_ERR_COUNT)
                {
                    /*TODO: Send Com info regarding transient issue via VDR*/
                    
                    /*reset transient error counter*/
                    SwcLighting_CountTransientError[RteAppInstance][ChIndex] = 0;
                }
            }
        }
    }    
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
@brief      SwcLighting_Init - Initialization function for Lighting
@details    This function shall be used to initialize global data used by SwcSensor

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all SWC components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcLighting_Init(const SwcRte_GlobalConfigType * ConfigPtr)
{
    SwcRte_AppInstanceIdType InstanceId;
    SwcRte_AppChannelIdType  CharsIndex;
    
    SwcLighting_ConfigPtr = ConfigPtr;

    for(InstanceId = 0; InstanceId < SWCRTE_MAX_LIGHTING_INSTANCES; InstanceId++)
    {
        SwcLightning_InstanceState[InstanceId] = SWCRTE_READINPUTS;
        SwcLighting_PreviosButtonState[InstanceId] = SWCRTE_BUTTON_OFF;
        SwcLighting_ButtonState[InstanceId] = SWCRTE_BUTTON_OFF;
        SwcLighting_OutputValue[InstanceId]  = SWCRTE_BUTTON_OFF;
		SwcLighting_CountButtonPressed[InstanceId]  = 0;
		
        for(CharsIndex = 0; CharsIndex < SWCRTE_MAX_LIGHTING_CHANNELS; CharsIndex++)
        {
            /*initialize channel state*/
            SwcLighting_ChannelState[InstanceId][CharsIndex] = SWCRTE_CHANNEL_STOPPED;
            
            /*initialize actuator request data*/
            SwcRte_aLightingActuatorData[InstanceId].aLightingOutputIntesity[CharsIndex] = 0;
            
            /*initialize sensor data*/
            SwcRte_aLightingSensorData[InstanceId].u8NoLightFeedbackChannels = 0;  
            SwcRte_aLightingSensorData[InstanceId].aLightOutputSensorData[CharsIndex].u32LightingSensorValue =  0;
            SwcRte_aLightingSensorData[InstanceId].aLightOutputSensorData[CharsIndex].u32LightingSensorType  =  SWCRTE_NO_SENS;
            
            SwcLighting_SumFeedbackValue[InstanceId][CharsIndex] = 0U;
            SwcLighting_AvgValueCounter[InstanceId][CharsIndex] = 0U;
            SwcLighting_AvgFeedbackValue[InstanceId][CharsIndex] = 0U;
            SwcLighting_CountTransientError[InstanceId][CharsIndex] = 0U;            
        }        
    }    
}

/*================================================================================================*/
/**
@brief      SwcLighting_WriteSensorData – shall write the sensor value for the given instance
            of the Lighting application.

@param[in]  LightingInstance    Instance Index.
@param[out] InputValue          Data read from Sensors that has to be written for this instance.

@return     Returns the value of success of executing the code 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcLighting_WriteSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType  * InputValue) 
{    
    uint8_t CharsIndex = 0; 
     
    SwcRte_aLightingSensorData[LightingInstance].u8NoLightFeedbackChannels = InputValue->u8NoLightFeedbackChannels;    
    SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorValue =  InputValue->aLightOutputSensorData[0].u32LightingSensorValue;
    SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorType  =  InputValue->aLightOutputSensorData[0].u32LightingSensorType;
    SwcRte_aLightingSensorData[LightingInstance].bSensorValueUpdated =  InputValue->bSensorValueUpdated;
    
    for(CharsIndex = 1; CharsIndex < SwcLighting_ConfigPtr[LightingInstance].u8NoInputChannel; CharsIndex++)
    {
        if (0 != ((InputValue->u8NoLightFeedbackChannels) & (1 << CharsIndex)))
        {
            SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[CharsIndex].u32LightingSensorValue =  InputValue->aLightOutputSensorData[CharsIndex].u32LightingSensorValue;
            SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[CharsIndex].u32LightingSensorType  =  InputValue->aLightOutputSensorData[CharsIndex].u32LightingSensorType;
        }
    }
}

/*================================================================================================*/
/**
@brief      SwcLighting_ReadSensorData – shall write the sensor value for the given instance 
            of the Lighting application.

@param[in]  LightingInstance    Instance Index.
@param[out] OutputValue          Data read from Lighting that has to be provided for other applications
                                 for this instance.

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcLighting_ReadSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType  * OutputValue) 
{    
    uint8_t CharsIndex = 0;
     
    OutputValue->u8NoLightFeedbackChannels = SwcRte_aLightingSensorData[LightingInstance].u8NoLightFeedbackChannels;    
    OutputValue->aLightOutputSensorData[0].u32LightingSensorValue = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorValue;    
    OutputValue->aLightOutputSensorData[0].u32LightingSensorType = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[0].u32LightingSensorType;       
    OutputValue->bSensorValueUpdated = SwcRte_aLightingSensorData[LightingInstance].bSensorValueUpdated;
    
    for(CharsIndex = 1; CharsIndex < SwcLighting_ConfigPtr[LightingInstance].u8NoInputChannel; CharsIndex++)
    {
        if (0 != ((OutputValue->u8NoLightFeedbackChannels) & (1 << CharsIndex)))
        {
            OutputValue->aLightOutputSensorData[CharsIndex].u32LightingSensorValue = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[CharsIndex].u32LightingSensorValue;
            
            OutputValue->aLightOutputSensorData[CharsIndex].u32LightingSensorType = SwcRte_aLightingSensorData[LightingInstance].aLightOutputSensorData[CharsIndex].u32LightingSensorType;
        }
    }
}

/*================================================================================================*/
/**
@brief      SwcRte_WriteLightingOutputRequest - This function shall read any output change request 
            coming from the Lighting Application, process these request and store the values in 
			the internal data so it will be sent to IoDal via SwcActuator_WriteOutputs().

@param[in]  LightingInstance    Instance Index.
@param[out] OutputValue         Value of the output request that is sent to Actuators for this instance

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcLighting_ReadOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType * OutputValue)
{    
    uint8_t ChIndex = 0;     
     
    for(ChIndex = 0; ChIndex < SwcLighting_ConfigPtr[LightingInstance].u8NoOutputChannel; ChIndex++)
    { 
        OutputValue->aLightingOutputIntesity[ChIndex] = SwcRte_aLightingActuatorData[LightingInstance].aLightingOutputIntesity[ChIndex];
    }
}

/*================================================================================================*/
/**
@brief      SwcRte_WriteLightingOutputRequest - This function shall read any output change request coming from the Lighting Application,
                                                 process these request and store the values in the internal data so it will be sent to IoDal via SwcActuator_WriteOutputs().
												 
@param[in]  LightingInstance    Instance Index.
@param[out] OutputValue         Value of the (forced) output written in Lighting instance by other application

@return     Returns the value of success of executing the - 
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcLighting_WriteOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType * InputValue)
{    
    uint8_t ChIndex = 0;     
     
    for(ChIndex = 0; ChIndex < SwcLighting_ConfigPtr[LightingInstance].u8NoOutputChannel; ChIndex++)
    { 
        SwcRte_aLightingActuatorData[LightingInstance].aLightingOutputIntesity[ChIndex] = InputValue->aLightingOutputIntesity[ChIndex];
    }    
}

/*================================================================================================*/
/**
@brief      SwcLighting_MainRunnable - main processing function for VDR
@details    This function is called periodically by the OS or by the main() function.

@param[in]  LightingInstance    Instance Index.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcLighting_MainRunnable(SwcRte_AppInstanceIdType RteAppInstance)
{
    switch(SwcLightning_InstanceState[RteAppInstance])
    {
        case  SWCRTE_READINPUTS: 
        {
            if (SwcRte_aLightingSensorData[RteAppInstance].bSensorValueUpdated == SWCRTE_TRUE)
            {    
                /*read all inputs and calculate possible outputs*/
                SwcLighting_CalculateOuputValue(RteAppInstance);

                SwcRte_aLightingSensorData[RteAppInstance].bSensorValueUpdated = SWCRTE_FALSE;

                SwcLightning_InstanceState[RteAppInstance] = SWCRTE_PROCESSFEEDBACK;
            }
        } break;

        case SWCRTE_PROCESSFEEDBACK:
        {                         
            /*process feedback values and reset state machine*/
            SwcLighting_ProcessFeedback(RteAppInstance);

            SwcLightning_InstanceState[RteAppInstance] = SWCRTE_READINPUTS; 
        } break;

        default :
           SwcLightning_InstanceState[RteAppInstance] = SWCRTE_READINPUTS; 
           break;
    }
}
#endif


/*================================================================================================*/

#ifdef __cplusplus
}
#endif
