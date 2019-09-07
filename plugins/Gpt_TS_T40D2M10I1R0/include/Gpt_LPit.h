/**
*   @file    Gpt_LPit.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - LPIT driver header file.
*   @details LPIT driver interface.
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

#ifndef GPT_LPIT_H
#define GPT_LPIT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section GPT_LPIT_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_LPit_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_LPit.h
*/
#define GPT_LPIT_VENDOR_ID                       43
#define GPT_LPIT_MODULE_ID                       100
#define GPT_LPIT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_LPIT_AR_RELEASE_MINOR_VERSION        2
#define GPT_LPIT_AR_RELEASE_REVISION_VERSION     2
#define GPT_LPIT_SW_MAJOR_VERSION                1
#define GPT_LPIT_SW_MINOR_VERSION                0
#define GPT_LPIT_SW_PATCH_VERSION                1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_LPIT_VENDOR_ID!= GPT_LPIT_TYPES_VENDOR_ID)
    #error "Gpt_LPit.h and Gpt_LPit_Types.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPIT_AR_RELEASE_MAJOR_VERSION != GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_MINOR_VERSION != GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_REVISION_VERSION != GPT_LPIT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit.h and Gpt_LPit_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPIT_SW_MAJOR_VERSION != GPT_LPIT_TYPES_SW_MAJOR_VERSION) || \
     (GPT_LPIT_SW_MINOR_VERSION != GPT_LPIT_TYPES_SW_MINOR_VERSION) || \
     (GPT_LPIT_SW_PATCH_VERSION != GPT_LPIT_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_LPit.h and Gpt_LPit_Types.h are different"
#endif

#if (GPT_LPIT_USED == STD_ON)
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_LPIT_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


FUNC (void, GPT_CODE) Gpt_LPit_Init(
        VAR(uint8, AUTOMATIC) u8HwChannel, 
#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
        VAR(uint32, AUTOMATIC) uTimerTriggerConfig,
#endif
        VAR(boolean, AUTOMATIC) bFreezeEnable);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_LPit_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

FUNC (void, GPT_CODE) Gpt_LPit_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value);

FUNC (void, GPT_CODE) Gpt_LPit_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel);

FUNC (uint32, GPT_CODE) Gpt_LPit_GetTimeElapsed(VAR(uint8, AUTOMATIC) u8HwChannel,
                                                P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                                P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                               );

FUNC (void, GPT_CODE) Gpt_LPit_EnableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC (void, GPT_CODE) Gpt_LPit_DisableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

#if ((GPT_LPIT_USED == STD_ON) || (defined GPT_LPIT_0_ISR_USED))
FUNC (void, GPT_CODE) Gpt_LPit_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_LPIT_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif /*GPT_LPIT_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

#endif /*GPT_LPIT_H*/

/** @} */
