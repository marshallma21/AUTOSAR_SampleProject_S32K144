/**
*   @file       Pwm_EnvCfg.h
*   @version    1.0.1
*
*   @brief      AUTOSAR Pwm - Pwm environment configuration file.
*   @details    Pwm environment configuration header.
*
*   @addtogroup PWM_MODULE
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

#ifndef PWM_ENV_CFG_H
#define PWM_ENV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_EnvCfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_EnvCfg_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Pwm_EnvCfg.h
*/
/*
* @violates @ref Pwm_EnvCfg_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Pwm_EnvCfg.h
*/
#define PWM_CFG_ENV_VENDOR_ID                       43
#define PWM_CFG_ENV_MODULE_ID                       121
/* @violates @ref Pwm_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_CFG_ENV_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Pwm_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_CFG_ENV_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Pwm_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_CFG_ENV_AR_RELEASE_REVISION_VERSION     2
#define PWM_CFG_ENV_SW_MAJOR_VERSION                1
#define PWM_CFG_ENV_SW_MINOR_VERSION                0
#define PWM_CFG_ENV_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((PWM_CFG_ENV_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_CFG_ENV_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm_EnvCfg.h and Std_Types.h are different"
#endif
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/* External environment the Pwm driver currently supports */
#define PWM_ENV_QM    (STD_OFF)
#define PWM_ENV_FTE   (STD_ON)
#define PWM_ENV_GTE   (STD_OFF)
#define PWM_ENV_NTE   (STD_OFF)

#if (PWM_ENV_FTE == STD_ON)
    /* FTE environment */
    #define PWM_PARAM_CHECK                  (PWM_DEV_ERROR_DETECT)
    #define PWM_REGISTER_PROTECTION          (STD_OFF)
    #define PWM_REPORT_UNEXPECTED_ISR        (STD_ON)

    /* @violates @ref Pwm_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
    #define PWM_VALIDATE_GLOBAL_CONFIG_CALL  (PWM_DEV_ERROR_DETECT)
    /* @violates @ref Pwm_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
    #define PWM_VALIDATE_CHANNEL_CONFIG_CALL (PWM_DEV_ERROR_DETECT)
#endif

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PWM_ENV_CFG_H */

/** @} */

