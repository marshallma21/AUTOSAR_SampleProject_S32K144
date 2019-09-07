/**
*   @file           Mcl_Lmem_Types.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Mcl - Dma data types header file.
*   @details        Dma defines, types used by MCL driver.
*
*   @addtogroup     MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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

#ifndef MCL_LMEM_TYPES_H
#define MCL_LMEM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*           Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*           on the significance of more than 31 characters. 
*           The used compilers use more than 31 chars for identifiers.
*/

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "CDD_Mcl_Cfg.h"

/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Mcl_Lmem_Types.h
* @requirements   
*/
#define MCL_LMEM_TYPES_VENDOR_ID                        43
#define MCL_LMEM_TYPES_MODULE_ID                        255
#define MCL_LMEM_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define MCL_LMEM_TYPES_AR_RELEASE_MINOR_VERSION         2
#define MCL_LMEM_TYPES_AR_RELEASE_REVISION_VERSION      2
#define MCL_LMEM_TYPES_SW_MAJOR_VERSION                 1
#define MCL_LMEM_TYPES_SW_MINOR_VERSION                 0
#define MCL_LMEM_TYPES_SW_PATCH_VERSION                 1
/** @} */
/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and CDD_Mcl_Cfg.h are of the same Autosar version */
    #if ((MCL_LMEM_TYPES_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
         (MCL_LMEM_TYPES_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
         (MCL_LMEM_TYPES_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
        #error "AutoSar Version Numbers of Mcl_Lmem_Types.h and CDD_Mcl_Cfg.h are different"
    #endif
#endif
/* Check if header file and CDD_Mcl_Cfg.h header file are of the same vendor */
#if (MCL_LMEM_TYPES_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "Mcl_Lmem_Types.h and CDD_Mcl_Cfg.h have different vendor ids"
#endif
/* Check if header file and CDD_Mcl_Cfg.h header file are of the same software version */
#if ((MCL_LMEM_TYPES_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_LMEM_TYPES_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_LMEM_TYPES_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Mcl_Lmem_Types.h and CDD_Mcl_Cfg.h are different"
#endif

/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
                                             ENUMS
===============================================================================================*/
typedef enum 
{
    /** @brief PC Cache (Cache attached to Processor Code bus) */
    MCL_LMEM_CACHE_PC = 0,
    #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
    /** @brief PS Cache (Cache attached to Processor System bus) */
    MCL_LMEM_CACHE_PS,
    #endif
    /** @brief PC and PS Cache (Both caches, attached to Processor Code bus and Processor System bus) */
    MCL_LMEM_CACHE_ALL
} Mcl_LmemCacheInstanceType;

/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/


/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* MCL_LMEM_TYPES_H */
/** @} */
