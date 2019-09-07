/**
*   @file    Gpt_Lptmr.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
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

#ifndef GPT_LPTMR_H
#define GPT_LPTMR_H

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
* @section GPT_LPTMR_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_LPTMR_H_REF_2
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
/**
* @file           Gpt_Lptmr.h
*/
#include "Gpt_Lptmr_Types.h"
#include "Gpt_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Lptmr.h
*/
#define GPT_LPTMR_VENDOR_ID                       43
#define GPT_LPTMR_AR_RELEASE_MAJOR_VERSION        4
#define GPT_LPTMR_AR_RELEASE_MINOR_VERSION        2
#define GPT_LPTMR_AR_RELEASE_REVISION_VERSION     2
#define GPT_LPTMR_SW_MAJOR_VERSION                1
#define GPT_LPTMR_SW_MINOR_VERSION                0
#define GPT_LPTMR_SW_PATCH_VERSION                1

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h file are of the same Autosar version */

#if (GPT_LPTMR_VENDOR_ID != GPT_LPTMR_TYPES_VENDOR_ID)
    #error "Gpt_Lptmr.h and Gpt_Lptmr_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION != GPT_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_MINOR_VERSION != GPT_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_REVISION_VERSION != GPT_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Lptmr.h and Gpt_Lptmr_Types.h are different"
#endif
/* Check if header file and Gpt header file are of the same software version */
#if ((GPT_LPTMR_SW_MAJOR_VERSION != GPT_LPTMR_TYPES_SW_MAJOR_VERSION) || \
     (GPT_LPTMR_SW_MINOR_VERSION != GPT_LPTMR_TYPES_SW_MINOR_VERSION) || \
     (GPT_LPTMR_SW_PATCH_VERSION != GPT_LPTMR_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Lptmr.h and Gpt_Lptmr_Types.h are different"
#endif

#if ( GPT_LPTMR_VENDOR_ID!= GPT_VENDOR_ID_CFG)
    #error "Gpt_Lptmr.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_LPTMR_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_LPTMR_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Gpt_Lptmr.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_LPTMR_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_LPTMR_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_LPTMR_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) )
    #error "Software Version Numbers of Gpt_Lptmr.h and Gpt_Cfg.h are different"
#endif

#if (GPT_LPTMR_USED == STD_ON)
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_LPTMR_H_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_LPTMR_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

FUNC(void, GPT_CODE) Gpt_Lptmr_Init(VAR(uint8, AUTOMATIC) u8ClockSource,
                                    VAR(uint8, AUTOMATIC) u8Prescaler
                                   );

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Lptmr_DeInit(void);
#endif

FUNC (void, GPT_CODE) Gpt_Lptmr_StartTimer(VAR(uint16, AUTOMATIC) u16Value);

FUNC (void, GPT_CODE) Gpt_Lptmr_StopTimer(void);

FUNC(uint32, GPT_CODE) Gpt_Lptmr_GetTimeElapsed(P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                                P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                               );

FUNC(void, GPT_CODE) Gpt_Lptmr_EnableInterrupt(void);

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC(void, GPT_CODE) Gpt_Lptmr_DisableInterrupt(void);
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API || GPT_WAKEUP_FUNCTIONALITY_API */

#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC(void, GPT_CODE) Gpt_Lptmr_SetClockMode(VAR(uint8, AUTOMATIC) u8Prescaler);
#endif /*GPT_SET_CLOCK_MODE == STD_ON*/

#if (defined GPT_LPTMR_0_CH_0_ISR_USED)
FUNC (void, GPT_CODE) Gpt_Lptmr_ProcessCommonInterrupt(void);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_Lptmr_StartPredefTimer (
    VAR(uint8, AUTOMATIC) u8ClockSource, 
    VAR(uint8, AUTOMATIC) u8Prescaler
);
FUNC(uint32, GPT_CODE) Gpt_Lptmr_GetPredefTimerValue (VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType);
FUNC(void, GPT_CODE) Gpt_Lptmr_StopPredefTimer (void);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_LPTMR_H_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_LPTMR_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif /*GPT_LPTMR_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

#endif /*GPT_LPTMR_H*/

/** @} */
