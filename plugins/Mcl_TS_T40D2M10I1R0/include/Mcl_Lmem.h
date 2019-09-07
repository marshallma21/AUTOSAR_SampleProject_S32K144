/**
*   @file    Mcl_Lmem.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LMEM low level header.
*   @details Low level header for LMEM module.
*
*   @addtogroup MCL_LMEM_DRIVER
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


#ifndef MCL_LMEM_H
#define MCL_LMEM_H


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_Lmem_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice.
*          All header files are protected against multiple inclusions
*
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcl_Lmem_h_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"
#include "Mcal.h"
#include "Mcl_Lmem_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_LMEM_VENDOR_ID                    43

#define MCL_LMEM_AR_RELEASE_MAJOR_VERSION     4
#define MCL_LMEM_AR_RELEASE_MINOR_VERSION     2
#define MCL_LMEM_AR_RELEASE_REVISION_VERSION  2
#define MCL_LMEM_SW_MAJOR_VERSION             1
#define MCL_LMEM_SW_MINOR_VERSION             0
#define MCL_LMEM_SW_PATCH_VERSION             1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/                                                                              
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl.c and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Lmem.h and Std_Types.h are different"
    #endif
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h header file are of the same vendor */
    #if (MCL_LMEM_VENDOR_ID != STD_VENDOR_ID)
        #error "Mcl_Lmem.h and Std_Types.h have different vendor ids"
    #endif
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h header file are of the same software version */
    #if ((MCL_LMEM_SW_MAJOR_VERSION != STD_SW_MAJOR_VERSION) || \
     (MCL_LMEM_SW_MINOR_VERSION != STD_SW_MINOR_VERSION) || \
     (MCL_LMEM_SW_PATCH_VERSION != STD_SW_PATCH_VERSION))
        #error "Software Version Numbers of Mcl_Lmem.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and Reg_eSys_Lmem.h header file are of the same Autosar version */
#if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION != MCL_LMEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION != MCL_LMEM_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Lmem.h and Mcl_Lmem_Types.h are different"
#endif
/* Check if source file and Reg_eSys_Lmem.h header file are of the same vendor */
#if (MCL_LMEM_VENDOR_ID != MCL_LMEM_TYPES_VENDOR_ID)
    #error "Mcl_Lmem.h and Reg_eSys_Lmem.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_Lmem.h header file are of the same software version */
#if ((MCL_LMEM_SW_MAJOR_VERSION != MCL_LMEM_TYPES_SW_MAJOR_VERSION) || \
     (MCL_LMEM_SW_MINOR_VERSION != MCL_LMEM_TYPES_SW_MINOR_VERSION) || \
     (MCL_LMEM_SW_PATCH_VERSION != MCL_LMEM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Lmem.h and Mcl_Lmem_Types.h are different"
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
#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_Lmem_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheEnable(Mcl_LmemCacheInstanceType cacheInstance); 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheDisable(Mcl_LmemCacheInstanceType cacheInstance); 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlush(Mcl_LmemCacheInstanceType cacheInstance); 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidate(Mcl_LmemCacheInstanceType cacheInstance);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClear(Mcl_LmemCacheInstanceType cacheInstance);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushMultiLines(Mcl_LmemCacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length); 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_InvalidateMultiLines(Mcl_LmemCacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length); 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearMultiLines(Mcl_LmemCacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length); 
#endif /* #if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)  */
#endif /* #ifdef MCL_LMEM_ENABLE_CACHE_API  */
     
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_Lmem_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCL_LMEM_H */

/** @} */
