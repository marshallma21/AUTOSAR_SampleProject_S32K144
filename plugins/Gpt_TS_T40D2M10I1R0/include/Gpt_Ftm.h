    /**
*   @file    Gpt_Ftm.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Ftm driver header file.
*   @details Ftm driver interface.
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

#ifndef GPT_FTM_H
#define GPT_FTM_H

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
* @section GPT_FTM_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_FTM_H_REF_2
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
#include "Gpt_Ftm_Types.h"
#include "Gpt_Cfg.h"
/** @violates @ref GPT_FTM_H_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_EnvCfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Gpt_Ftm.h
*/
#define GPT_FTM_VENDOR_ID                       43
#define GPT_FTM_AR_RELEASE_MAJOR_VERSION        4
#define GPT_FTM_AR_RELEASE_MINOR_VERSION        2
#define GPT_FTM_AR_RELEASE_REVISION_VERSION     2
#define GPT_FTM_SW_MAJOR_VERSION                1
#define GPT_FTM_SW_MINOR_VERSION                0
#define GPT_FTM_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_FTM_VENDOR_ID != GPT_FTM_TYPES_VENDOR_ID)
    #error "Gpt_Ftm.h and Gpt_Ftm_Types.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION != GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION != GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION != GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ftm.h and Gpt_Ftm_Types.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_FTM_SW_MAJOR_VERSION != GPT_FTM_TYPES_SW_MAJOR_VERSION) || \
     (GPT_FTM_SW_MINOR_VERSION != GPT_FTM_TYPES_SW_MINOR_VERSION) || \
     (GPT_FTM_SW_PATCH_VERSION != GPT_FTM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ftm.h and Gpt_Ftm_Types.h are different"
#endif

#if (GPT_FTM_VENDOR_ID!= GPT_VENDOR_ID_CFG)
    #error "Gpt_Ftm.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Gpt_Ftm.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_FTM_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_FTM_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_FTM_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) )
    #error "Software Version Numbers of Gpt_Ftm.h and Gpt_Cfg.h are different"
#endif


#if ( GPT_FTM_VENDOR_ID!= GPT_ENVCFG_VENDOR_ID)
    #error "Gpt_Ftm.h and Gpt_EnvCfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ftm.h and Gpt_EnvCfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_FTM_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
     (GPT_FTM_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
     (GPT_FTM_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Ftm.h and Gpt_EnvCfg.h are different"
#endif

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
/** @violates @ref GPT_FTM_H_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_FTM_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


FUNC(void, GPT_CODE) Gpt_Ftm_Init(VAR(uint8, AUTOMATIC) u8HwChannel,
                                                VAR(boolean, AUTOMATIC) bFreezeEnable,
                                                VAR(uint8, AUTOMATIC) u8ClockSource,
                                                VAR(uint8, AUTOMATIC) u8Prescaler
                                                );
                                      
#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Ftm_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

FUNC (void, GPT_CODE) Gpt_Ftm_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel,
                                            VAR(uint32, AUTOMATIC) u32Value);

FUNC (void, GPT_CODE) Gpt_Ftm_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel);


FUNC (uint32, GPT_CODE) Gpt_Ftm_GetTimeElapsed(VAR(uint8, AUTOMATIC) u8HwChannel,
                                                  P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelOverflow,
                                                  P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue);

#if (GPT_FTM_USED == STD_ON)
FUNC (void, GPT_CODE) Gpt_Ftm_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ftm_SetClockMode(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint8, AUTOMATIC) u8ChPrescaler);
#endif

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ftm_ChangeNextTimeoutValue(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_Ftm_StartPredefTimer
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(boolean, AUTOMATIC) bFreezeEnable,
    VAR(uint8, AUTOMATIC) u8ClockSource,
    VAR(uint8, AUTOMATIC) u8Prescaler
);
FUNC(uint32, GPT_CODE) Gpt_Ftm_GetPredefTimerValue (VAR(uint8, AUTOMATIC) u8HwChannel, VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType);
FUNC(void, GPT_CODE) Gpt_Ftm_StopPredefTimer (VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_FTM_H_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_FTM_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_FTM_H*/

/** @} */
