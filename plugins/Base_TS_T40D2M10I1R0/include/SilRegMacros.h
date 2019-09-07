/**
*   @file    SilRegMacros.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - IP module versions.
*   @details Gathers all macros for register access, soft and hard lock on ARM 
*            hardware platform and also macros for handling redundant variables. 
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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

/** 
* @page misra_violations MISRA-C:2004 violations
*
* @section SilRegMacros_h_REF_1 
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Functions like macros are used to reduce code complexity.
* @section SilRegMacros_h_REF_2 
*          Violates MISRA 2004 Advisory Rule 19.13, '#/##' operator used in macro.
*          This rule could not be avoided as there is no other way to create a redundant
*          replica for each given variable without over increasing code complexity.
* @section SilRegMacros_h_REF_3
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/

#ifndef SILREGMACROS_H
#define SILREGMACROS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StdRegMacros.h"
#include "RegLockMacros.h"
#if 0
    /* not needed for this release */
    #include "RedundantMemMacros.h"
#endif
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SILREGMACROS_VENDOR_ID                    43
#define SILREGMACROS_MODULE_ID                    0
#define SILREGMACROS_AR_RELEASE_MAJOR_VERSION     4
#define SILREGMACROS_AR_RELEASE_MINOR_VERSION     2
#define SILREGMACROS_AR_RELEASE_REVISION_VERSION  2
#define SILREGMACROS_SW_MAJOR_VERSION             1
#define SILREGMACROS_SW_MINOR_VERSION             0
#define SILREGMACROS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and StdRegMacros.h header file have same versions */
#if (SILREGMACROS_VENDOR_ID != STDREGMACROS_VENDOR_ID)
#error "SilRegMacros.h and StdRegMacros.h have different vendor IDs"
#endif
#if ((SILREGMACROS_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (SILREGMACROS_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (SILREGMACROS_AR_RELEASE_REVISION_VERSION != STDREGMACROS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SilRegMacros.h and StdRegMacros.h are different"
#endif
#if ((SILREGMACROS_SW_MAJOR_VERSION != STDREGMACROS_SW_MAJOR_VERSION) || \
     (SILREGMACROS_SW_MINOR_VERSION != STDREGMACROS_SW_MINOR_VERSION) || \
     (SILREGMACROS_SW_PATCH_VERSION != STDREGMACROS_SW_PATCH_VERSION))
#error "Software Version Numbers of SilRegMacros.h and StdRegMacros.h are different"
#endif

/* Check if source file and RegLockMacros.h header file have same versions */
#if (SILREGMACROS_VENDOR_ID != REGLOCKMACROS_VENDOR_ID)
#error "SilRegMacros.h and RegLockMacros.h have different vendor IDs"
#endif
#if ((SILREGMACROS_AR_RELEASE_MAJOR_VERSION != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (SILREGMACROS_AR_RELEASE_MINOR_VERSION != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION) || \
     (SILREGMACROS_AR_RELEASE_REVISION_VERSION != REGLOCKMACROS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of SilRegMacros.h and RegLockMacros.h are different"
#endif
#if ((SILREGMACROS_SW_MAJOR_VERSION != REGLOCKMACROS_SW_MAJOR_VERSION) || \
     (SILREGMACROS_SW_MINOR_VERSION != REGLOCKMACROS_SW_MINOR_VERSION) || \
     (SILREGMACROS_SW_PATCH_VERSION != REGLOCKMACROS_SW_PATCH_VERSION))
#error "Software Version Numbers of SilRegMacros.h and RegLockMacros.h are different"
#endif

#if 0
    /* not needed for this release */
    /* Check if source file and RedundantMemMacros.h header file have same versions */
    #if (SILREGMACROS_VENDOR_ID != REDUNDANTMEMMACROS_VENDOR_ID)
    #error "SilRegMacros.h and RedundantMemMacros.h have different vendor IDs"
    #endif
    #if ((SILREGMACROS_AR_RELEASE_MAJOR_VERSION != REDUNDANTMEMMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (SILREGMACROS_AR_RELEASE_MINOR_VERSION != REDUNDANTMEMMACROS_AR_RELEASE_MINOR_VERSION) || \
         (SILREGMACROS_AR_RELEASE_REVISION_VERSION != REDUNDANTMEMMACROS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of SilRegMacros.h and RedundantMemMacros.h are different"
    #endif
    #if ((SILREGMACROS_SW_MAJOR_VERSION != REDUNDANTMEMMACROS_SW_MAJOR_VERSION) || \
         (SILREGMACROS_SW_MINOR_VERSION != REDUNDANTMEMMACROS_SW_MINOR_VERSION) || \
         (SILREGMACROS_SW_PATCH_VERSION != REDUNDANTMEMMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of SilRegMacros.h and RedundantMemMacros.h are different"
    #endif
#endif
    
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef SILREGMACROS_H */

/** @} */
