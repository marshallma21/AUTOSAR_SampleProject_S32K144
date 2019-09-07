/**
    @file        SwcRte_Types.h
*   @version     1.0.1
*
*   @brief       Integration Framework - SW component RTE TYPES header file
*
*   @details     This file implements SwcRte types header file.  
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
#ifndef SWCRTE_TYPES_H
#define SWCRTE_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "typedefs.h"


/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCRTE_TYPES_VENDOR_ID                          43

#define SWCRTE_TYPES_SW_MAJOR_VERSION                   1
#define SWCRTE_TYPES_SW_MINOR_VERSION                   0
#define SWCRTE_TYPES_SW_PATCH_VERSION                   1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
 

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define SWCRTE_MEAS_OK       0U
#define SWCRTE_MEAS_NOT_OK   1U
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
	SWCRTE_BUTTON_OFF = 0U,
	SWCRTE_BUTTON_ON  = 1U
}SwcRte_InputStateType;


typedef enum
{
	SWCRTE_CHANNEL_ACTIVE = 0U,
	SWCRTE_CHANNEL_STOPPED  = 1U,
	SWCRTE_CHANNEL_SHORT2GND = 4U,
	SWCRTE_CHANNEL_OPEN_LOAD = 8U
}SwcRte_ChannelStateType;


typedef enum
{
	SWCRTE_READINPUTS = 0U,
	SWCRTE_PROCESSFEEDBACK  = 1U
}SwcRte_InstanceStateType;


typedef enum
{
    SWCRTE_MC_CW  = 0U,    /**< @brief Motor rotation direction is Clock-Wise. */
    SWCRTE_MC_CCW,         /**< @brief Motor rotation direction is Counter Clock-Wise.  */
    SWCRTE_MC_STOP         /**< @brief Motor Stopped  */
} SwcRte_AppMotorDirectionType;


typedef enum
{
    SWCRTE_LIGHTING  = 0U,    /**< @brief Motor rotation direction is Clock-Wise. */
    SWCRTE_MOTORCTRL,         /**< @brief Motor rotation direction is Counter Clock-Wise.  */
    SWCRTE_VDR                /**< @brief Motor Stopped  */
} SwcRte_AppInstanceType;


typedef enum
{
    SWCRTE_DIGITAL_SENS  = 0U,   /**< @brief Application uses digital buttons (inputs) as sensor. */
    SWCRTE_ANALOG_POT_SENS,      /**< @brief Application uses analog potentiometer as sensor. */
	SWCRTE_ANALOG_FDBK_SENS,
	SWCRTE_INPUT_CAPTURE_SENS,
	SWCRTE_NO_SENS,
    SWCRTE_COM_DATA_INPUT       /**< @brief Application uses a communication channel as 'sensor'. */	
} SwcRte_AppInputSensorType;


typedef enum
{
    SWCRTE_DIGITAL_OUT  = 0U,      /**< @brief Application uses full-on/full-off actuator. */
    SWCRTE_PWM_OUT,                /**< @brief Application uses PWM controlled actuator. */
	SWCRTE_EXTDEV_OUT              /**< @brief Application uses external device controlled actuator. */
} SwcRte_AppActuatorType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8_t SwcRte_AppInstanceIdType;                /**< @brief Number of instances of each application */

typedef uint8_t SwcRte_AppChannelIdType;                /**< @brief Number of channels of each application */

typedef uint16_t SwcRte_OutputValueType;                 /**< @brief Application output value request type */

/**< @brief Type used to define all output channels of a given application instance*/
typedef struct 
{
	const SwcRte_AppChannelIdType  u8OutputChannel;              /**< @brief Id of used the BSW output channel */
} SwcRte_OutputChannelConfigType; 

/**< @brief Type used to define all input channels of a given application instance*/
typedef struct 
{
	const SwcRte_AppChannelIdType   u8InputChannel;               /**< @brief Id of used the BSW input channel */
	const SwcRte_AppInputSensorType eInputType;                   /**< @brief Type of the input channel*/
} SwcRte_InputChannelConfigType; 


 /**< @brief Global Application configuration structure type*/
typedef struct 
{
	const SwcRte_AppInstanceType   eInstanceType;          /**< @brief Type of the current instance */
	const SwcRte_AppActuatorType   eOutputType;                  /**< @brief Type of the output channel*/
	const uint8_t                  u8NoInputChannel;       /**< @brief Number of input channels for current instance */
	const uint8_t                  u8NoOutputChannel;      /**< @brief Number of output channels for current instance */
	const SwcRte_InputChannelConfigType  * pInstanceInputSensor;      /**< @brief Pointer to the input channel configuration  */
	const SwcRte_OutputChannelConfigType * pInstanceActuator;   /**< @brief Pointer to the output channel configuration */
} SwcRte_GlobalConfigType; 

 /**< @brief RTE abstraction type used to pass sensor information from lower layer to application layer.*/
typedef struct
{
	uint16_t  Value;
    uint8_t   Status;		
}SwcRte_AppInputValueType;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/




/*================================================================================================*/
/*================================================================================================*/
#ifdef __cplusplus
}
#endif
#endif /*SWCRTE_TYPES_H*/