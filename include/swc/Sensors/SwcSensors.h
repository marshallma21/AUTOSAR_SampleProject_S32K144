/**
*   @file        SwcSensors.h
*   @version     1.0.1
*
*   @brief       Integration Framework - Header for the Sensors SW component.
*
*   @details     This file implements header file for sensors component. 
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

#ifndef SWCSENSORS_H
#define SWCSENSORS_H

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
#define SWCSENSORS_VENDOR_ID                          43

#define SWCSENSORS_SW_MAJOR_VERSION                   1
#define SWCSENSORS_SW_MINOR_VERSION                   0
#define SWCSENSORS_SW_PATCH_VERSION                   1

/*==================================================================================================
*                                     FILE VERSION CHECKS
===================================================================================================*/
/* Check if header file and SwcRte.h header file are of the same vendor */
#if (SWCSENSORS_VENDOR_ID != SWCRTE_VENDOR_ID)
    #error "SwcSensors.h and SwcRte.h have different vendor ids"
#endif


/* Check if header file and  SwcRte.h header file are of the same Software version */
#if ((SWCSENSORS_SW_MAJOR_VERSION != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCSENSORS_SW_MINOR_VERSION != SWCRTE_SW_MINOR_VERSION) || \
     (SWCSENSORS_SW_PATCH_VERSION != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcSensors.h and  SwcRte.h are different"
#endif


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
extern void SwcSensors_Init(const SwcRte_GlobalConfigType * ConfigPtr );
extern void SwcSensors_MainRunnable(void);


/*================================================================================================*/

#ifdef __cplusplus
}
#endif
#endif /*SWCSENSORS_H*/
/** @} */