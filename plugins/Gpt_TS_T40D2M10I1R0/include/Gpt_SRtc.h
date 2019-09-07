/**
*   @file    Gpt_SRtc.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - SRTC driver header file.
*   @details SRTC driver interface.
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

#ifndef GPT_SRTC_H
#define GPT_SRTC_H

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
* @section GPT_SRTC_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_SRTC_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_SRtc_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_SRtc.h
*/
#define GPT_SRTC_VENDOR_ID                       43
#define GPT_SRTC_MODULE_ID                       100
#define GPT_SRTC_AR_RELEASE_MAJOR_VERSION        4
#define GPT_SRTC_AR_RELEASE_MINOR_VERSION        2
#define GPT_SRTC_AR_RELEASE_REVISION_VERSION     2
#define GPT_SRTC_SW_MAJOR_VERSION                1
#define GPT_SRTC_SW_MINOR_VERSION                0
#define GPT_SRTC_SW_PATCH_VERSION                1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_SRTC_VENDOR_ID!= GPT_SRTC_TYPES_VENDOR_ID)
    #error "Gpt_SRtc.h and Gpt_SRtc_Types.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_SRTC_AR_RELEASE_MAJOR_VERSION != GPT_SRTC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_MINOR_VERSION != GPT_SRTC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_REVISION_VERSION != GPT_SRTC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_SRtc.h and Gpt_SRtc_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SRTC_SW_MAJOR_VERSION != GPT_SRTC_TYPES_SW_MAJOR_VERSION) || \
     (GPT_SRTC_SW_MINOR_VERSION != GPT_SRTC_TYPES_SW_MINOR_VERSION) || \
     (GPT_SRTC_SW_PATCH_VERSION != GPT_SRTC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_SRtc.h and Gpt_SRtc_Types.h are different"
#endif

#if (GPT_SRTC_USED == STD_ON)
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
/** @violates @ref GPT_SRTC_H_REF_1 Repeated include file MemMap.h */
/** @violates @ref GPT_SRTC_H_REF_2 Only preprocessor statements and comments before "#include" */
#include "Gpt_MemMap.h"

#ifdef GPT_SRTC_SUPERVISER_BIT_AVAILABLE
/**
* @brief        Enables SRTC registers writing in User Mode
* @details      Sets the SUP (Supervisor access) bit of the SRTC IP allowing SRTC registers writing in User Mode
*
* @param[in]    none
*
* @return       none
*
* @pre          Should be executed in supervisor mode
* @post         none
*/

FUNC( void, GPT_CODE) Gpt_SRtc_SetUserAccessAllowed(void);
#endif /* GPT_SRTC_SUPERVISER_BIT_AVAILABLE */

FUNC (void, GPT_CODE) Gpt_SRtc_Init(VAR(uint8, AUTOMATIC) u8ClockSource);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_SRtc_DeInit(void);
#endif

FUNC (void, GPT_CODE) Gpt_SRtc_StartTimer(VAR(uint32, AUTOMATIC) u32Value);

FUNC (void, GPT_CODE) Gpt_SRtc_StopTimer(void);

FUNC (uint32, GPT_CODE) Gpt_SRtc_GetTimeElapsed(P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                                P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                               );

FUNC (void, GPT_CODE) Gpt_SRtc_EnableInterrupt(void);

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC (void, GPT_CODE) Gpt_SRtc_DisableInterrupt(void);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_SRTC_H_REF_1 Repeated include file MemMap.h */
/** @violates @ref GPT_SRTC_H_REF_2 Only preprocessor statements and comments before "#include" */
#include "Gpt_MemMap.h"

#endif /*GPT_SRTC_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

#endif /*GPT_SRTC_H*/

/** @} */
