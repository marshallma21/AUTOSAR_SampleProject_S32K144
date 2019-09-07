/**
*   @file    Reg_eSys_Lmem.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LMEM Registers and Macros Definitions.
*   @details LMEM Registers and Macros Definitions.
*
*   @addtogroup LMEM_DRIVER
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

/**
@file        Reg_eSys_Lmem.h
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section  Reg_eSys_LMEM_REF_1
*           Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*           contents of a header file being included twice
*           This is not a violation since all header files are protected against multiple inclusions
*
* @section  Reg_eSys_LMEM_REF_2
*           Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*           This violation is due to function like macros defined for register operations.
*           Function like macros are used to reduce code complexity.
*/


#ifndef REG_ESYS_LMEM_H
#define REG_ESYS_LMEM_H


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
* @violates @ref Reg_eSys_LMEM_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Reg_eSys.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Lmem.h
* @requirements   
*/
#define LMEM_VENDOR_ID_REG                       43
#define LMEM_AR_RELEASE_MAJOR_VERSION_REG        4
#define LMEM_AR_RELEASE_MINOR_VERSION_REG        2
#define LMEM_AR_RELEASE_REVISION_VERSION_REG     2
#define LMEM_SW_MAJOR_VERSION_REG                1
#define LMEM_SW_MINOR_VERSION_REG                0
#define LMEM_SW_PATCH_VERSION_REG                1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((LMEM_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (LMEM_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys.h and Reg_eSys_Lmem.h are different"
    #endif
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS                                                  
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief LMEM registers base address
*/
/** @violates @ref Reg_eSys_LMEM_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define LMEM_PCCCR_ADDR32              ((uint32)(LMEM_BASEADDR + (uint32)0x000UL))
/** @violates @ref Reg_eSys_LMEM_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define LMEM_PCCLCR_ADDR32             ((uint32)(LMEM_BASEADDR + (uint32)0x004UL))
/** @violates @ref Reg_eSys_LMEM_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define LMEM_PCCSAR_ADDR32             ((uint32)(LMEM_BASEADDR + (uint32)0x008UL))

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/** @violates @ref Reg_eSys_LMEM_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define LMEM_PSCCR_ADDR32              ((uint32)(LMEM_BASEADDR + (uint32)0x800UL))
/** @violates @ref Reg_eSys_LMEM_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define LMEM_PSCLCR_ADDR32             ((uint32)(LMEM_BASEADDR + (uint32)0x804UL))
/** @violates @ref Reg_eSys_LMEM_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define LMEM_PSCSAR_ADDR32             ((uint32)(LMEM_BASEADDR + (uint32)0x808UL))
#endif

/** 
* @brief LMEM PxCCR registers bit masks, Cache control register.
*/
#define LMEM_CCR_ENCACHE_MASK_U32          (0x00000001UL)
#define LMEM_CCR_ENWRBUF_MASK_U32          (0x00000002UL)
#define LMEM_CCR_INVW0_MASK_U32            (0x01000000UL)
#define LMEM_CCR_PUSHW0_MASK_U32           (0x02000000UL)
#define LMEM_CCR_INVW1_MASK_U32            (0x04000000UL)
#define LMEM_CCR_PUSHW1_MASK_U32           (0x08000000UL)
#define LMEM_CCR_GO_MASK_U32               (0x80000000UL)

/** 
* @brief LMEM PxCLCR registers bit masks, Cache line control register.
*/
#define LMEM_CLCR_LINE_CMD_MASK_U32         (0x0F000000UL)  /* Cache Line Command mask, PxCLCR[LACC|LADSEL|LCMD] bits */
/** 
* @brief Cache Line Commands
*/
#define LMEM_CLCR_LINE_INVAL_PHY_ADDR_U32   (0x05000000UL)  /* "Invalidate by physical address" cache line command */
#define LMEM_CLCR_LINE_FLUSH_PHY_ADDR_U32   (0x06000000UL)  /* "Flush by physical address" cache line command */
#define LMEM_CLCR_LINE_CLEAR_PHY_ADDR_U32   (0x07000000UL)  /* "Clear by physical address" cache line command */
/** 
* @brief Tag/Data Select
*/
#define LMEM_CLCR_LINE_TDSEL_MASK_U32       (0x00010000UL)  /* Tag/Data Select PxCLCR[TDSEL] */

/** 
* @brief LMEM PxCSAR registers bit masks, Cache search address register.
*/
#define LMEM_CSAR_PHYADDR_MASK_U32          (0xFFFFFFFCUL)  /* Physical Address, PxCSAR[PHYADDR] */
#define LMEM_CSAR_LGO_MASK_U32              (0x00000001UL)  /* Initiate Cache Line Command, PxCSAR[LGO] */

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


#endif /* REG_ESYS_LMEM_H */

/** @} */
