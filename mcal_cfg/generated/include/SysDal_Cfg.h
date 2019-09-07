/**
*   @file           SysDal_Cfg.h
*   @version        1.0.1
*
*   @brief          AUTOSAR IntegrationFramework - SysDal pre configuration file.
*   @details        Pre configuration structure instances
*
*This file contains sample code only. It is not part of the production code deliverables.
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPit
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
#ifndef SYSDAL_CFG_H
#define SYSDAL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/*===================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
====================================================================================================================*/
#include "Std_Types.h"
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
/**
* @file          SysDal_Cfg.h
*/
#define SYSDAL_CFG_VENDOR_ID                           43
#define SYSDAL_CFG_MODULE_ID                           100

#define SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION            4
#define SYSDAL_CFG_AR_RELEASE_MINOR_VERSION            2
#define SYSDAL_CFG_AR_RELEASE_REVISION_VERSION         2

#define SYSDAL_CFG_SW_MAJOR_VERSION                    1
#define SYSDAL_CFG_SW_MINOR_VERSION                    0
#define SYSDAL_CFG_SW_PATCH_VERSION                    1
/*===================================================================================================================
*                                       FILE VERSION CHECKS
====================================================================================================================*/
/**
* @file          SysDal_Cfg.h
*/
/* Check if source file and SYSDAL header file are of the same vendor */
#if (SYSDAL_CFG_VENDOR_ID != STD_VENDOR_ID)
    #error "SysDal_Cfg.h and Std_Types.h have different vendor ids"
#endif

/* Check if source file and SYSDAL header file are of the same Autosar version */
#if ((SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_CFG_AR_RELEASE_REVISION_VERSION != STD_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal_Cfg.h and Std_Types.h are different"
#endif

/* Check if source file and SYSDAL header file are of the same Software version */
#if ((SYSDAL_CFG_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
     (SYSDAL_CFG_SW_MINOR_VERSION != STD_SW_MINOR_VERSION) || \
     (SYSDAL_CFG_SW_PATCH_VERSION != STD_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal_Cfg.h and Std_Types.h are different"
#endif

#define SYSDAL_LOW_POWER_MODE(STD_OFF)
#if defined(AUTOSAR_OS_NOT_USED)
#define GPT_SCH_TICKS                       4000U
#define SYSDAL_SCH_GPT_TIMER_CHANNEL        1U
#define SYSDAL_USERS                        1U
#define INTAPP_TASK_2_ACTIVATION_TIME        10
#define INTAPP_TASK_3_ACTIVATION_TIME        20
#define INTAPP_PREHOOK_TASK_ACTIVATION_TIME        0

#define    INTAPP_TASK_2_ENABLE    STD_ON
#define    INTAPP_TASK_3_ENABLE    STD_ON
#define    INTAPP_PREHOOK_TASK_ENABLE    STD_ON
#define    INTAPP_TASK_1_ENABLE    STD_OFF
#define    INTAPP_TASK_4_ENABLE    STD_OFF
#define    INTAPP_TASK_5_ENABLE    STD_OFF
#define    INTAPP_TASK_6_ENABLE    STD_OFF
#define    INTAPP_TASK_7_ENABLE    STD_OFF


extern void INTAPP_TASK_2(void);
extern void INTAPP_TASK_3(void);
extern void INTAPP_PREHOOK_TASK(void);
#endif

FUNC (void, SAMPLE_APP_CODE)SysDal_AllDriverInit(void);
FUNC (void, SAMPLE_APP_CODE)SysDal_SetAllProgrammableInterrupts(void);
FUNC (void, SAMPLE_APP_CODE) SysDal_AllDriverDeinit(void);
#if (SYSDAL_LOW_POWER_MODE == STD_ON)  
FUNC (void, SAMPLE_APP_CODE) SysDal_SetWakeupEventsCallout(void);
FUNC (void, SAMPLE_APP_CODE) SysDal_ClearWakeupEventsCallout(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* SYSDAL_CFG_H */
