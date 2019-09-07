/**
*    @file        SwcLighting.h
*    @version     1.0.1
*
*    @brief       Integration Framework - Lighting SW component.
*
*    @details     Implementation of the header file for the lighting application.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef SWCLIGHTING_H
#define SWCLIGHTING_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "SwcRte.h"
/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCLIGHTING_VENDOR_ID                          43

#define SWCLIGHTING_SW_MAJOR_VERSION                   1
#define SWCLIGHTING_SW_MINOR_VERSION                   0
#define SWCLIGHTING_SW_PATCH_VERSION                   1
/*==================================================================================================
*                                     FILE VERSION CHECKS
===================================================================================================*/
/* Check if header file and SWCRTE TYPES header file are of the same vendor */
#if (SWCLIGHTING_VENDOR_ID != SWCRTE_VENDOR_ID)
    #error "SwcLighting.h and SwcRte.h have different vendor ids"
#endif


/* Check if header file and SWCRTE TYPES header file are of the same Software version */
#if ((SWCLIGHTING_SW_MAJOR_VERSION != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCLIGHTING_SW_MINOR_VERSION != SWCRTE_SW_MINOR_VERSION) || \
     (SWCLIGHTING_SW_PATCH_VERSION != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcLighting.h and SwcRte.h are different"
#endif



/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
extern void  SwcLighting_Init(const SwcRte_GlobalConfigType * ConfigPtr);
extern void  SwcLighting_WriteSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType  * InputValue);
extern void  SwcLighting_ReadSensorData(SwcRte_AppInstanceIdType LightingInstance, AppLightingSensorValueType  * OutputValue); 
extern void  SwcLighting_ReadOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType * OutputValue);
extern void  SwcLighting_WriteOutputRequest(SwcRte_AppInstanceIdType LightingInstance, AppLightingActuatorValueType * InputValue);
extern void  SwcLighting_MainRunnable(SwcRte_AppInstanceIdType LightingInstance);


/*================================================================================================*/

#ifdef __cplusplus
}
#endif
#endif /*SWCLIGHTING_H*/
/** @} */