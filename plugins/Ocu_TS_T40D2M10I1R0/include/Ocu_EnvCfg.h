/**
*   @file       Ocu_EnvCfg.h
*   @version    1.0.1
*
*   @brief      AUTOSAR Ocu - Ocu environment configuration file.
*   @details    Ocu environment configuration header.
*
*   @addtogroup OCU_MODULE
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

#ifndef OCU_ENV_CFG_H
#define OCU_ENV_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_EnvCfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Ocu_EnvCfg_H_REF_2
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
* @file           Ocu_EnvCfg.h
*/
/*
* @violates @ref Ocu_EnvCfg_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Ocu_EnvCfg.h
*/
#define OCU_ENVCFG_VENDOR_ID                       43
#define OCU_ENVCFG_MODULE_ID                       121
/* @violates @ref Ocu_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_ENVCFG_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Ocu_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_ENVCFG_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Ocu_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_ENVCFG_AR_RELEASE_REVISION_VERSION     2
#define OCU_ENVCFG_SW_MAJOR_VERSION                1
#define OCU_ENVCFG_SW_MINOR_VERSION                0
#define OCU_ENVCFG_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((OCU_ENVCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_ENVCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ocu_EnvCfg.h and Std_Types.h are different"
#endif
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/* External environment the Ocu driver currently supports */
#define OCU_ENV_QM    (STD_OFF)
#define OCU_ENV_FTE   (STD_ON)
#define OCU_ENV_GTE   (STD_OFF)
#define OCU_ENV_NTE   (STD_OFF)

#if (OCU_ENV_FTE == STD_ON)
    /* FTE environment */
    #define OCU_PARAM_CHECK                  (OCU_DEV_ERROR_DETECT)
    #define OCU_USER_MODE_SOFT_LOCKING       (STD_OFF)
    #define OCU_REPORT_UNEXPECTED_ISR        (STD_ON)

    /* @violates @ref Ocu_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
    #define OCU_VALIDATE_GLOBAL_CONFIG_CALL  (OCU_DEV_ERROR_DETECT)
    /* @violates @ref Ocu_EnvCfg_H_REF_2 Identifier exceeds 31 chars. */
    #define OCU_VALIDATE_CHANNEL_CONFIG_CALL (OCU_DEV_ERROR_DETECT)
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

#endif /* OCU_ENV_CFG_H */

/** @} */

