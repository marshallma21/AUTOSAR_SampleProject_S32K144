/**
*   @file    Mcl_IPW_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Exported data outside of the Mcl from IPW.
*   @details Public data types exported outside of the Mcl driver.
*
*   @addtogroup MCL
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


#ifndef MCL_IPW_TYPES_H
#define MCL_IPW_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)
    #include "Mcl_Dma_Types.h"
    #include "Mcl_DmaMux_Types.h"
#endif 

#if (MCL_ENABLE_TRGMUX == STD_ON)
    #include "Mcl_TrgMux_Types.h"
#endif 
#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (MCL_LMEM_ENABLE_CACHE_API == STD_ON)
    #include "Mcl_Lmem_Types.h"
#endif
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_IPW_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCL_IPW_TYPES_VENDOR_ID                       43
#define MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2

#define MCL_IPW_TYPES_SW_MAJOR_VERSION                1
#define MCL_IPW_TYPES_SW_MINOR_VERSION                0
#define MCL_IPW_TYPES_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)

/* Check if header file and Mcl_Dma_Types.h header file are of the same vendor */
#if (MCL_IPW_TYPES_VENDOR_ID != MCL_DMA_TYPES_VENDOR_ID)
    #error "Mcl_IPW_Types.h and Mcl_Dma_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_Dma_Types.h header file are of the same Autosar version */
#if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_DMA_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_Dma_Types.h are different"
#endif
/* Check if header file and Mcl_Dma_Types.h header file are of the same software version */
#if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_DMA_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_DMA_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_DMA_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_Dma_Types.h are different"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same vendor */
#if (MCL_IPW_TYPES_VENDOR_ID != MCL_DMAMUX_TYPES_VENDOR_ID)
    #error "Mcl_IPW_Types.h and Mcl_DmaMux_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same Autosar version */
#if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_DMAMUX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_DMAMUX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_DMAMUX_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_DmaMux_Types.h are different"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same software version */
#if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_DMAMUX_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_DMAMUX_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_DMAMUX_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_DmaMux_Types.h are different"
#endif
#endif

#if (MCL_ENABLE_TRGMUX == STD_ON)
    /* Check if header file and Mcl_TrgMux_Types.h header file are of the same vendor */
    #if (MCL_IPW_TYPES_VENDOR_ID != MCL_TRGMUX_TYPES_VENDOR_ID)
        #error "Mcl_IPW_Types.h and Mcl_TrgMux_Types.h have different vendor ids"
    #endif
    /* Check if header file and Mcl_TrgMux_Types.h header file are of the same Autosar version */
    #if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_TRGMUX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_TRGMUX_TYPES_AR_RELEASE_MINOR_VERSION) || \
         (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_TRGMUX_TYPES_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_TrgMux_Types.h are different"
    #endif
    /* Check if header file and Mcl_TrgMux_Types.h header file are of the same software version */
    #if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_TRGMUX_TYPES_SW_MAJOR_VERSION) || \
         (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_TRGMUX_TYPES_SW_MINOR_VERSION) || \
         (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_TRGMUX_TYPES_SW_PATCH_VERSION))
        #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_TrgMux_Types.h are different"
    #endif
#endif 

#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (MCL_LMEM_ENABLE_CACHE_API == STD_ON)
    
/* Check if header file and Mcl_Lmem_Types.h header file are of the same vendor */
#if (MCL_IPW_TYPES_VENDOR_ID != MCL_LMEM_TYPES_VENDOR_ID)
    #error "Mcl_IPW_Types.h and Mcl_Lmem_Types.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Mcl_Lmem_Types.h header file are of the same Autosar version */
#if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_LMEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_LMEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_LMEM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_Lmem_Types.h are different"
#endif
#endif
/* Check if header file and Mcl_Lmem_Types.h header file are of the same software version */
#if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_LMEM_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_LMEM_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_LMEM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_Lmem_Types.h are different"
#endif

#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)
/**
* @brief            Mcl driver configuration structure.
* @details          Configuration for DMA_MUX and eDMA modules.
*                   Used by "Mcl_ConfigType" structure.
*
*/
typedef struct
{
    P2CONST( Mcl_DmaConfigType, MCL_VAR, MCL_APPL_CONST) pDma_Config;         /**< @brief Configuration for eDMA (Enhanced Direct Memory Access) hardware IP. */ 
    P2CONST( Mcl_DmaMuxConfigType, MCL_VAR, MCL_APPL_CONST) pDmaMux_Config;   /**< @brief Configuration for DMA_MUX (eDMA Channel Mux) hardware IP. */ 
} Mcl_DmaHwIpsConfigType;

#endif /* (MCL_ENABLE_DMA == STD_ON) */


#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (MCL_LMEM_ENABLE_CACHE_API == STD_ON)
    /** Mcl Cache instance type */
    typedef Mcl_LmemCacheInstanceType  Mcl_CacheInstanceType;
#endif
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCL_IPW_TYPES_H */


/** @} */

