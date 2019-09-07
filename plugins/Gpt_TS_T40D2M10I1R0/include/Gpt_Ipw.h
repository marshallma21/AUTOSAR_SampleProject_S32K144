/**
*   @file    Gpt_Ipw.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar specific and are not exported by the GPT driver.
*            - are not related to the GPT driver related IPs.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef GPT_IPW_H
#define GPT_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_IPW_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_IPW_VENDOR_ID                      43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION       2
#define GPT_IPW_AR_RELEASE_REVISION_VERSION    2
#define GPT_IPW_SW_MAJOR_VERSION               1
#define GPT_IPW_SW_MINOR_VERSION               0
#define GPT_IPW_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Gpt channel hardware runtime information. This is the type of the data structure used by the Autosar layer to
*        receive runtime information specific to hardware IP
*
*/
typedef struct
{
    VAR(boolean, GPT_VAR) bChannelRollover;                 /**<@brief GPT channel rollover information*/
    VAR(Gpt_ValueType, GPT_VAR) uTargetTime;                /**<@brief GPT channel target value*/
} Gpt_HwChannelInfoType;
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/** @violates @ref GPT_IPW_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

FUNC (void, GPT_CODE) Gpt_Ipw_Init(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig);

FUNC (Gpt_ValueType, GPT_CODE) Gpt_Ipw_GetTimeElapsed(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,
                                                      P2VAR(Gpt_HwChannelInfoType, AUTOMATIC,GPT_APPL_DATA) pReturnHwChannelInfo);

FUNC (void, GPT_CODE) Gpt_Ipw_StartTimer(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,
                                                   VAR(Gpt_ValueType, AUTOMATIC) uValue);

FUNC (void, GPT_CODE) Gpt_Ipw_StopTimer(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig);

FUNC (void, GPT_CODE) Gpt_Ipw_EnableInterrupt(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)|| (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Ipw_DisableInterrupt(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig);
#endif

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Ipw_DeInit(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig);
#endif

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
FUNC (Std_ReturnType, GPT_CODE) Gpt_Ipw_ChangeNextTimeoutValue(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig,
                                                               VAR(Gpt_ValueType, AUTOMATIC) value);
#endif

#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ipw_SetClockMode(P2CONST(Gpt_HwChannelConfigType,AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,VAR(Gpt_ClockModeType,AUTOMATIC)eClkMode);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Ipw_StartPredefTimer
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr
);
FUNC (void, GPT_CODE) Gpt_Ipw_GetPredefTimerValue
(
    P2CONST(Gpt_HwPredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig,
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) TimeValuePtr
);
FUNC (void, GPT_CODE) Gpt_Ipw_StopPredefTimer
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr
);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_IPW_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_IPW_H*/

/** @} */
