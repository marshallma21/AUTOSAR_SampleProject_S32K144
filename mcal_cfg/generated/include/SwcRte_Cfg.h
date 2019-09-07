/**
*   @file    SwcRte_Cfg.h
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component configuration file
*   @details This file implements the IODAL configuration header.
*
*   @addtogroup IODAL
*   @{
*/
/*===================================================================================================================
*   Platform             : ARM
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*
*   All Rights Reserved.
*
*   This file contains sample code only. It is not part of the production code deliverables.
====================================================================================================================*/
/*===================================================================================================================
====================================================================================================================*/
#ifndef SWCRTE_CFG_H
#define SWCRTE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "SwcRte_Types.h"

/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/

#define SWCRTE_CFG_VENDOR_ID                      43

#define SWCRTE_CFG_SW_MAJOR_VERSION               1
#define SWCRTE_CFG_SW_MINOR_VERSION               0
#define SWCRTE_CFG_SW_PATCH_VERSION               1


/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if SwcRte_Cfg.h header file and SwcRte_Types.h header file are of the same vendor */
#if (SWCRTE_CFG_VENDOR_ID != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcRte_Cfg.h and SwcRte_Types.h have different vendor ids"
#endif


/* Check if SwcRte_Cfg.h header file and SwcRte_Types.h header file are of the same Software version */
#if ((SWCRTE_CFG_SW_MAJOR_VERSION != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCRTE_CFG_SW_MINOR_VERSION != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCRTE_CFG_SW_PATCH_VERSION != SWCRTE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte_Types.h and SwcRte_Cfg.h are different"
#endif



/*==================================================================================================
                                       GLOBAL MACROS
==================================================================================================*/


#define SWCRTE_LIGTHING_APP_ENABLED      (SWCRTE_STD_ON) 

#define SWCRTE_MOTORCTRL_APP_ENABLED      (SWCRTE_STD_OFF)  

#define SWCRTE_VDR_APP_ENABLED            (SWCRTE_STD_OFF)  

#define SWCRTE_USE_RTE_BUFFERS            (SWCRTE_STD_OFF)  

#define SWCRTE_SINGLE_TASK_APPLICATION   (SWCRTE_STD_ON)  



#define SWCRTE_MAX_LIGHTING_CHANNELS        2U
#define SWCRTE_MAX_LIGHTING_INSTANCES       3U 

#define SWCRTE_MAX_MOTORCTRL_INSTANCES      0U 
#define SWCRTE_MOTORCTRL_INSTANCE_OFFSET    3U
#define SWCRTE_MOTORCTRL_FBK_LINES          0U

#define SWCRTE_MAX_VDR_INSTANCES            0U 
#define SWCRTE_VDR_INSTANCE_OFFSET          3U

#define SWCRTE_MAX_APP_INSTANCES            (SWCRTE_MAX_LIGHTING_INSTANCES + SWCRTE_MAX_MOTORCTRL_INSTANCES + SWCRTE_MAX_VDR_INSTANCES)    

#define SWCLIGHTING_MAXIMUM_ANALOG_FDBK_VALUE   3000U 
#define SWCLIGHTING_MINIMUM_ANALOG_FDBK_VALUE   500U



#define SWCRTE_MAX_ANSENS_INSTANCES         1
#define SWCRTE_MAX_DISENS_INSTANCES         2

#define SWCRTE_ADC_RESOLUTION               12U	

#define SWCRTE_USE_IODAL       (SWCRTE_STD_ON) 

#define SWCRTE_USE_SYSDAL     (SWCRTE_STD_ON) 

#define SWCRTE_USE_MEMDAL    (SWCRTE_STD_OFF) 

#define SWCRTE_USE_COMDAL    (SWCRTE_STD_OFF) 


        


/*==================================================================================================
                                       GLOBAL RUN-TIME VARIABLE TYPES
==================================================================================================*/
#if SWCRTE_MAX_LIGHTING_INSTANCES > 0
typedef struct 
{
	SwcRte_AppInputSensorType  u32LightingSensorType;         /**< @brief  Input sensor type */ 
	uint32_t                   u32LightingSensorValue;         /**< @brief Value measured by input sensor */
} AppLightingSensorChannelType; 


typedef struct 
{
    boolean_t bSensorValueUpdated;      /**< @brief Mask of Indexes used for Feedback Channels*/
    uint8_t   u8NoLightFeedbackChannels;  	
    AppLightingSensorChannelType aLightOutputSensorData[SWCRTE_MAX_LIGHTING_CHANNELS]; /**< @brief Values for each FBK Channel*/
} AppLightingSensorValueType; 


typedef struct 
{
    uint32_t aLightingOutputIntesity[SWCRTE_MAX_LIGHTING_CHANNELS]; /**< @brief Values for the output light intesity*/
} AppLightingActuatorValueType; 



#if SWCRTE_MAX_VDR_INSTANCES > 0
typedef AppLightingActuatorValueType AppLightingComDataType; 
#endif

#endif /*SWCRTE_MAX_LIGHTING_INSTANCES*/


#if SWCRTE_MAX_MOTORCTRL_INSTANCES > 0
typedef struct 
{
    uint8_t  u8NoMotorCtrlFbkChannels;      /**< @brief Mask of Indexes used for Feedback Channels*/
    uint32_t u32MotorCtrlSensorValue;         /**< @brief Value measured by input sensor */   
    uint32_t aMotorCtrlOutputFeedback[SWCRTE_MAX_MOTORCTRL_FBK_LINES]; /**< @brief Values for each FBK Channel*/
} AppMotorCtrlSensorValueType; 


typedef struct 
{
    AppMotorDirectionType   eMotorCtrlOutputDirection; /**< @brief Values for each FBK Channel*/
	uint32_t                u32MotorCtrlOutputSpeed;      /**< @brief Expected motor speed*/    
} AppMotorCtrlActuatorValueType; 


#if SWCRTE_MAX_VDR_INSTANCES > 0
typedef AppMotorCtrlActuatorValueType AppMotorCtrlComDataType; 
#endif
#endif /*SWCRTE_MAX_MOTORCTRL_INSTANCES*/


#if SWCRTE_MAX_VDR_INSTANCES > 0
typedef struct 
{
    uint8_t        u8NoOfInfoChars;              /**< @brief No of written chars*/
	AppChannelType eComChannel;          /**< @brief channel used for comunication*/
	char           * pComInfoString;             /**< @brief string of chars containing data*/    
} AppInfoType; 
#endif


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
extern const SwcRte_GlobalConfigType SwcRte_AppInstanceMapPB[SWCRTE_MAX_APP_INSTANCES];







/*================================================================================================*/
/*================================================================================================*/
#ifdef __cplusplus
}
#endif
#endif /*SWCRTE_CFG_H*/
