/**
*   @file        SwcRte.h
*   @version     1.0.1
*
*   @brief       Integration Framework - SW component RTE header file
*
*   @details     This file implements SwcRte header file.  
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
#ifndef SWCRTE_H
#define SWCRTE_H

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
#include "SwcRte_Types.h"
#include "SwcRte_Cfg.h"


/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCRTE_VENDOR_ID                          43

#define SWCRTE_SW_MAJOR_VERSION                   1
#define SWCRTE_SW_MINOR_VERSION                   0
#define SWCRTE_SW_PATCH_VERSION                   1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if SwcRte.h header file and SwcRte_Types.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcRte.h and SwcRte_Types.h have different vendor ids"
#endif


/* Check if SwcRte.h header file and SwcRte_Types.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION != SWCRTE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.h and SwcRte_Types.h are different"
#endif

/* Check if SwcRte.h header file and  SwcRte_Cfg.h header file are of the same vendor */
#if (SWCRTE_VENDOR_ID != SWCRTE_CFG_VENDOR_ID)
    #error "SwcRte.h and SwcRte_Cfg.h have different vendor ids"
#endif


/* Check if SwcRte.h header file and SwcRte_Cfg.h header file are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION != SWCRTE_CFG_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION != SWCRTE_CFG_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION != SWCRTE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcRte.h and SwcRte_Cfg.h are different"
#endif



/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/



/*================================================================================================*/
void SwcRte_Init( const SwcRte_GlobalConfigType * ConfigPtr);
#if (SWCRTE_SINGLE_TASK_APPLICATION == SWCRTE_STD_ON)	
void SwcRte_MainRunnable(void);
#endif
/*==================================================================================================
                                 GOBAL FUNCTIONS FOR LIGHTING APP
==================================================================================================*/

#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)
	
#if (SWCRTE_VDR_APP_ENABLED  == SWCRTE_STD_ON)
void SwcRte_ReadLightingComData(SwcRte_AppInstanceIdType LightingInstance, AppLightingComDataType * Value);

void SwcRte_WriteLightingComData(SwcRte_AppInstanceIdType LightingInstance, AppLightingComDataType Value);

void SwcRte_ReadLightingComInfo(SwcRte_AppInstanceIdType LightingInstance, AppInfoType * Value);

void SwcRte_WriteLightingComInfo (SwcRte_AppInstanceIdType LightingInstance,  AppInfoType OututValue);
#endif

void SwcRte_ReadLightingSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType *OutputValue) ;

void SwcRte_WriteLightingSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType *InputValue) ;

void SwcRte_ReadLightingOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType * OutputValue);

void SwcRte_WriteLightingOutputRequest(SwcRte_AppInstanceIdType LightingInstance,  AppLightingActuatorValueType * OututValue); 
#endif
/*==================================================================================================
                                 GOBAL FUNCTIONS FOR MOTOR CONTROL APP
==================================================================================================*/
#if (SWCRTE_MOTORCTRL_APP_ENABLED ==SWCRTE_STD_ON)
#if (SWCRTE_VDR_APP_ENABLED  ==SWCRTE_STD_ON)
void SwcRte_ReadMotorCtrlComData(SwcRte_AppInstanceIdType MCInstance, AppMotorCtrlComDataType * Value);

void SwcRte_WriteMotorCtrlComData(SwcRte_AppInstanceIdType MCInstance, AppMotorCtrlComDataType Value);

void SwcRte_ReadMotorCtrlComInfo(SwcRte_AppInstanceIdType MCInstance,  AppInfoType * Value);

void SwcRte_WriteMotorCtrlComInfo(SwcRte_AppInstanceIdType MCInstance,  AppInfoType OututValue);
#endif

void SwcRte_ReadMotorCtrlSensorData(SwcRte_AppInstanceIdType MCInstance, AppMotorCtrlSensorValueType * Value);

void SwcRte_WriteMotorCtrlSensorData(SwcRte_AppInstanceIdType MCInstance, AppMotorCtrlSensorValueType Value);

void SwcRte_ReadMotorCtrlOutputRequest(SwcRte_AppInstanceIdType MCInstance, AppMotorCtrlActuatorValueType  *OutputValue);

void SwcRte_WriteMotorCtrlOutputRequest(SwcRte_AppInstanceIdType MCInstance,  AppMotorCtrlActuatorValueType * OututValue);
#endif

/*==================================================================================================
                                 GOBAL FUNCTIONS FOR BSW INTERFACE
==================================================================================================*/
#if (SWCRTE_VDR_APP_ENABLED  ==SWCRTE_STD_ON)
void SwcRte_ReadComData(SwcRte_AppInstanceIdType ComChannel, ComDalValueType * Value);

void SwcRte_WriteComData(SwcRte_AppInstanceIdType ComChannel, ComDalValueType Value);
#endif

void SwcRte_ReadInputs(SwcRte_AppInstanceIdType AppInstance, SwcRte_AppChannelIdType SensorChannel, SwcRte_AppInputValueType * InputValue);

void SwcRte_WriteOutputs(SwcRte_AppInstanceIdType AppInstance, SwcRte_AppChannelIdType ActuatorChannel, SwcRte_OutputValueType OutputValue);

/*================================================================================================*/
/*================================================================================================*/
#ifdef __cplusplus
}
#endif
#endif /*SWCRTE_H*/