/**
*   @file    Fls.h
*   @implements Fls.h_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Include all external API declarations and definitions of all pre-compile parameters.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
*   Dependencies         : 
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

#ifndef FLS_H
#define FLS_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_h_REF_2
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fls_Cfg.h"
#include "Fls_Api.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_AR_RELEASE_MAJOR_VERSION     4
#define FLS_AR_RELEASE_MINOR_VERSION     2
/*
* @violates @ref fls_h_REF_1 The compiler/linker
* shall be checked to ensure that 31 character significance and case sensitivity are supported
* for external identifiers
* @violates @ref fls_h_REF_2 Identifiers (internal and external)
* shall not rely on the significance of more than 31 characters. 
*/
#define FLS_AR_RELEASE_REVISION_VERSION  2
#define FLS_SW_MAJOR_VERSION             1
#define FLS_SW_MINOR_VERSION             0
#define FLS_SW_PATCH_VERSION             1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Mcal.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fls.h and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Fls_Cfg.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
         (FLS_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION_CFG))
        #error "AutoSar Version Numbers of Fls.h and Fls_Cfg.h are different"
    #endif
#endif
/* Check if header file and Fls_Cfg.h header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_VENDOR_ID_CFG)
    #error "Fls.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if header file and Fls_Cfg.h header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Fls_Api.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != FLS_API_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION != FLS_API_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fls.h and Fls_Api.h are different"
    #endif
#endif
/* Check if header file and Fls_Api.h header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_API_VENDOR_ID)
    #error "Fls.h and Fls_Api.h have different vendor ids"
#endif
/* Check if header file and Fls_Api.h header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_API_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION != FLS_API_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION != FLS_API_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fls.h and Fls_Api.h are different"
#endif

#ifdef __cplusplus
}
#endif

#endif /* FLS_H */

/** @} */

