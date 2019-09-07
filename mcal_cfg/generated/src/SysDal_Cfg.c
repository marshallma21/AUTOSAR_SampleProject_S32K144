/**
*   @file           SysDal_Cfg.c
*   @version        1.0.1
*
*   @brief          Integration Framework - SysDal Abstraction Layer component
*   @details        This file implements the SysDal interface to application layer.
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
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
============================================================================================================================*/
/*============================================================================================================================
==============================================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*===================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
====================================================================================================================*/
#include "SysDal.h"
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define SYSDAL_CFG_VENDOR_ID_C                       43

#define SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define SYSDAL_CFG_AR_RELEASE_MINOR_VERSION_C        2
#define SYSDAL_CFG_AR_RELEASE_REVISION_VERSION_C     2

#define SYSDAL_CFG_SW_MAJOR_VERSION_C                1
#define SYSDAL_CFG_SW_MINOR_VERSION_C                0
#define SYSDAL_CFG_SW_PATCH_VERSION_C                1
#include "Port.h"
#include "Adc.h"
#include "Det.h"
#include "Gpt.h"
#include "Ocu.h"
#include "Pwm.h"
#include "IoDal.h"
#include "SwcRte.h"

#if defined(AUTOSAR_OS_NOT_USED)
#include "sys_init.h"
extern ISR (Adc_Adc12bsarv2_EndGroupConvUnit0);
extern ISR (FTM_1_CH_0_CH_1_ISR);
extern ISR (LPIT_0_CH_0_ISR);
extern ISR (LPIT_0_CH_1_ISR);

FUNC(void, SAMPLE_APP_CODE)SysDal_SetAllProgrammableInterrupts(void)
{
    sys_disableAllInterrupts();
    sys_enableIsrSource(39, ((5) << 4));	
    sys_registerIsrHandler(39, (uint32) & Adc_Adc12bsarv2_EndGroupConvUnit0);
    sys_enableIsrSource(105, ((6) << 4));	
    sys_registerIsrHandler(105, (uint32) & FTM_1_CH_0_CH_1_ISR);
    sys_enableIsrSource(48, ((7) << 4));	
    sys_registerIsrHandler(48, (uint32) & LPIT_0_CH_0_ISR);
    sys_enableIsrSource(49, ((2) << 4));	
    sys_registerIsrHandler(49, (uint32) & LPIT_0_CH_1_ISR);
    sys_enableAllInterrupts();
}
#endif

FUNC (void, SAMPLE_APP_CODE)SysDal_AllDriverInit(void)
{
    Port_Init(&PortConfigSet);
    Adc_Init(&AdcConfigSet);
    Det_Init();
    Det_Start();
    Gpt_Init(&GptChannelConfigSet);
    Gpt_EnableNotification(1);
    Ocu_Init(&OcuConfigSet);
    Pwm_Init(&PwmChannelConfigSet);
    Pwm_SelectCommonTimebase(0, 3);
    IoDal_Init(&IoDal_Config[0]);
}

#if (SYSDAL_LOW_POWER_MODE == STD_ON)
FUNC (void, SAMPLE_APP_CODE)SysDal_SetWakeupEventsCallout(void)
{
}
FUNC (void, SAMPLE_APP_CODE)SysDal_ClearWakeupEventsCallout(void)
{
}
#endif
FUNC (void, SAMPLE_APP_CODE)SysDal_AllDriverDeinit(void)
{
}

#if defined(AUTOSAR_OS_NOT_USED)
void INTAPP_TASK_2(void)
{

IoDal_MainFunction();

}
void INTAPP_TASK_3(void)
{

SwcRte_MainRunnable();

}
void INTAPP_PREHOOK_TASK(void)
{

SwcRte_Init(&SwcRte_AppInstanceMapPB[0]);

}
void INTAPP_TASK_1(void)
{

SysDal_MainFunction();

}
#endif
const SysDal_ConfigType SysDal_Config=
{
    &SysDal_AllDriverInit,
    &SysDal_SetAllProgrammableInterrupts,
    &SysDal_AllDriverDeinit
#if (SYSDAL_LOW_POWER_MODE == STD_ON)     
    ,
    &SysDal_SetWakeupEventsCallout,
    &SysDal_ClearWakeupEventsCallout
#endif
};

#ifdef __cplusplus
}
#endif
