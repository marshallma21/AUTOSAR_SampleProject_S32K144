/**
*   @file           SysDal.h
*   @version        1.0.1
*
*   @brief          Integration Framework - SysDal high level interface implementation.
*   @details        SysDal high level interface implementation.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup SYSDAL
*   @{
*/
/*==================================================================================================
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
==================================================================================================*/

#ifndef SYSDAL_H
#define SYSDAL_H

#ifdef __cplusplus
extern "C"{
#endif
/*===================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
====================================================================================================================*/
#include "SysDal_Cfg.h"
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
/**
* @file          SysDal.h
*/
#define SYSDAL_VENDOR_ID                           43
#define SYSDAL_MODULE_ID                           100

#define SYSDAL_AR_RELEASE_MAJOR_VERSION            4
#define SYSDAL_AR_RELEASE_MINOR_VERSION            2
#define SYSDAL_AR_RELEASE_REVISION_VERSION         2

#define SYSDAL_SW_MAJOR_VERSION                    1
#define SYSDAL_SW_MINOR_VERSION                    0
#define SYSDAL_SW_PATCH_VERSION                    1
/*===================================================================================================================
*                                       FILE VERSION CHECKS
====================================================================================================================*/
/**
* @file           SysDal.h
*/
/* Check if source file and SYSDAL header file are of the same vendor */
#if (SYSDAL_VENDOR_ID != SYSDAL_CFG_VENDOR_ID)
    #error "SysDal.h and SysDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and SYSDAL header file are of the same Autosar version */
#if ((SYSDAL_AR_RELEASE_MAJOR_VERSION != SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_AR_RELEASE_MINOR_VERSION != SYSDAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_AR_RELEASE_REVISION_VERSION != SYSDAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal.h and SysDal_Cfg.h are different"
#endif

/* Check if source file and SYSDAL header file are of the same Software version */
#if ((SYSDAL_SW_MAJOR_VERSION != SYSDAL_CFG_SW_MAJOR_VERSION) || \
     (SYSDAL_SW_MINOR_VERSION != SYSDAL_CFG_SW_MINOR_VERSION) || \
     (SYSDAL_SW_PATCH_VERSION != SYSDAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal.h and SysDal_Cfg.h are different"
#endif

typedef enum
{
    SYSDAL_STATE_STARTUP = 0,
    SYSDAL_STATE_UP,
    SYSDAL_STATE_SLEEP
}SysDal_EcuModeType;

typedef uint8 SysDal_EcuModeUsersType;

typedef void (*SysDal_CalloutType)(void);

typedef struct
{
    CONST(SysDal_CalloutType, SAMPLE_APP_CONST) InitDriversCallout;
    CONST(SysDal_CalloutType, SAMPLE_APP_CONST) SetProgrammableInterruptsCallout;
    CONST(SysDal_CalloutType, SAMPLE_APP_CONST) DeinitDriversCallout;
#if (SYSDAL_LOW_POWER_MODE == STD_ON)
    CONST(SysDal_CalloutType, SAMPLE_APP_CONST) SetWakeupEventsCallout;
    CONST(SysDal_CalloutType, SAMPLE_APP_CONST) ClearWakeupEventsCallout;	
#endif
}SysDal_ConfigType;

FUNC (void, SAMPLE_APP_CODE) SysDal_Init(void) ;
FUNC (void, SAMPLE_APP_CODE) SysDal_MainFunction(void) ;
FUNC (void, SAMPLE_APP_CODE) SysDal_WriteModeRequest(uint8 UserId, SysDal_EcuModeType Mode);

#ifdef __cplusplus
}
#endif

#endif /*SYSDAL_H*/
