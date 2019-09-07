/**
*   @file    Eep.h
*   @implements Eep.h_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Include all external API declarations and definitions of all pre-compile parameters.
*
*   @addtogroup EEP
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

#ifndef EEP_H
#define EEP_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section eep_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section eep_h_REF_2
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by smcal coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to EEP.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Eep_Cfg.h"
#include "Std_Types.h"
#include "Eep_Api.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_AR_RELEASE_MAJOR_VERSION     4
#define EEP_AR_RELEASE_MINOR_VERSION     2
/*
* @violates @ref eep_h_REF_1 The compiler/linker
* shall be checked to ensure that 31 character significance and case sensitivity are supported
* for external identifiers
* @violates @ref eep_h_REF_2 Identifiers (internal and external)
* shall not rely on the significance of more than 31 characters. 
*/
#define EEP_AR_RELEASE_REVISION_VERSION  2
#define EEP_SW_MAJOR_VERSION             1
#define EEP_SW_MINOR_VERSION             0
#define EEP_SW_PATCH_VERSION             1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Mcal.h header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep.h and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Eep_Cfg.h header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION != EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
         (EEP_AR_RELEASE_MINOR_VERSION != EEP_AR_RELEASE_MINOR_VERSION_CFG))
        #error "AutoSar Version Numbers of Eep.h and Eep_Cfg.h are different"
    #endif
#endif
/* Check if header file and Eep_Cfg.h header file are of the same vendor */
#if (EEP_VENDOR_ID != EEP_VENDOR_ID_CFG)
    #error "Eep.h and Eep_Cfg.h have different vendor ids"
#endif
/* Check if header file and Eep_Cfg.h header file are of the same software version */
#if ((EEP_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION_CFG) || \
     (EEP_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION_CFG) || \
     (EEP_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Eep.h and Eep_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Eep_Api.h header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION != EEP_API_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION != EEP_API_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep.h and Eep_Api.h are different"
    #endif
#endif
/* Check if header file and Eep_Api.h header file are of the same vendor */
#if (EEP_VENDOR_ID != EEP_API_VENDOR_ID)
    #error "Eep.h and Eep_Api.h have different vendor ids"
#endif
/* Check if header file and Eep_Api.h header file are of the same software version */
#if ((EEP_SW_MAJOR_VERSION != EEP_API_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION != EEP_API_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION != EEP_API_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eep.h and Eep_Api.h are different"
#endif

#ifdef __cplusplus
}
#endif

#endif /* EEP_H */

/** @} */

