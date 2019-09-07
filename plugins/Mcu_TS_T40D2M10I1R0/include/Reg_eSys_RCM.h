/**
*   @file    Reg_eSys_RCM.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef REG_ESYS_RCM_H
#define REG_ESYS_RCM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_RCM_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_RCM_VENDOR_ID                       43
#define REG_ESYS_RCM_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_RCM_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_RCM_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_RCM_SW_MAJOR_VERSION                1
#define REG_ESYS_RCM_SW_MINOR_VERSION                0
#define REG_ESYS_RCM_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_RCM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_RCM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_RCM.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/********** RCM Registers **********/

/* RCM_VERID - Version ID Register */
#define RCM_VERID_ADDR32                     ((uint32)(RCM_BASEADDR + (uint32)0x00000000U))
/* RCM_PARAM - Parameter Register */
#define RCM_PARAM_ADDR32                     ((uint32)(RCM_BASEADDR + (uint32)0x00000004U))
/* RCM_SRS - System Reset Status Register */
#define RCM_SRS_ADDR32                       ((uint32)(RCM_BASEADDR + (uint32)0x00000008U))
/* RCM_RPC - Reset Pin Control register */
#define RCM_RPC_ADDR32                       ((uint32)(RCM_BASEADDR + (uint32)0x0000000CU))
/* RCM_SSRS - Sticky System Reset Status Register */
#define RCM_SSRS_ADDR32                      ((uint32)(RCM_BASEADDR + (uint32)0x00000018U))
/* RCM_SRIE - System Reset Interrupt Enable Register */
#define RCM_SRIE_ADDR32                      ((uint32)(RCM_BASEADDR + (uint32)0x0000001CU))

/****************************************************/
/***              RCM_SRS                         ***/
/****************************************************/
#define RCM_SRS_RWBITS_MASK32                ((uint32)0x00000000U)
#define RCM_SRS_STATUS_MASK32                ((uint32)0x00002FEEU)

#define RCM_SRS_SACKERR_MASK32               ((uint32)0x00002000U)
#define RCM_SRS_MDM_AP_MASK32                ((uint32)0x00000800U)
#define RCM_SRS_SW_MASK32                    ((uint32)0x00000400U)
#define RCM_SRS_LOCKUP_MASK32                ((uint32)0x00000200U)
#define RCM_SRS_JTAG_MASK32                  ((uint32)0x00000100U)
#define RCM_SRS_POR_MASK32                   ((uint32)0x00000080U)
#define RCM_SRS_PIN_MASK32                   ((uint32)0x00000040U)
#define RCM_SRS_WDOG_MASK32                  ((uint32)0x00000020U)
#define RCM_SRS_LOL_MASK32                   ((uint32)0x00000008U)
#define RCM_SRS_LOC_MASK32                   ((uint32)0x00000004U)
#define RCM_SRS_LVD_MASK32                   ((uint32)0x00000002U)

/****************************************************/
/***              RCM_RPC                         ***/
/****************************************************/
#define RCM_RPC_RWBITS_MASK32                ((uint32)0x00001F07U)

#define RCM_RPC_RSTFLTSEL_MASK32             ((uint32)0x00001F00U)
#define RCM_RPC_RSTFLTSEL_SHIFT32            ((uint32)8U)
#define RCM_RPC_RSTFLTSS_MASK32              ((uint32)0x00000004U)
#define RCM_RPC_RSTFLTSRW_MASK32             ((uint32)0x00000003U)

/** @violates @ref Reg_eSys_RCM_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define RCM_RPC_RSTFLTSEL_U32(value)          ((uint32)((uint32)((value) << RCM_RPC_RSTFLTSEL_SHIFT32) & RCM_RPC_RSTFLTSEL_MASK32))

#define RCM_RPC_STOP_ALL_FILTERING_DISABLE_U32     ((uint32)0x00000000U)
#define RCM_RPC_STOP_LPO_CLOCK_FILTER_ENABLE_U32     (RCM_RPC_RSTFLTSS_MASK32)

#define RCM_RPC_NORMAL_ALL_FILTERING_DISABLE_U32   ((uint32)0x00000000U)
#define RCM_RPC_NORMAL_BUS_CLOCK_FILTER_ENABLE_U32   ((uint32)0x00000001U)
#define RCM_RPC_NORMAL_LPO_CLOCK_FILTER_ENABLE_U32   ((uint32)0x00000002U)

/****************************************************/
/***              RCM_SSRS                        ***/
/****************************************************/
#define RCM_SSRS_RWBITS_MASK32              ((uint32)0x00002FFEU)

#define RCM_SSRS_SSACKERR_MASK32            ((uint32)0x00002000U)
#define RCM_SSRS_SMDM_AP_MASK32             ((uint32)0x00000800U)
#define RCM_SSRS_SSW_MASK32                 ((uint32)0x00000400U)
#define RCM_SSRS_SLOCKUP_MASK32             ((uint32)0x00000200U)
#define RCM_SSRS_SJTAG_MASK32               ((uint32)0x00000100U)
#define RCM_SSRS_SPOR_MASK32                ((uint32)0x00000080U)
#define RCM_SSRS_SPIN_MASK32                ((uint32)0x00000040U)
#define RCM_SSRS_SWDOG_MASK32               ((uint32)0x00000020U)
#define RCM_SSRS_SLOL_MASK32                ((uint32)0x00000008U)
#define RCM_SSRS_SLOC_MASK32                ((uint32)0x00000004U)
#define RCM_SSRS_SLVD_MASK32                ((uint32)0x00000002U)

/****************************************************/
/***              RCM_SRIE                        ***/
/****************************************************/
#define RCM_SRIE_RWBITS_MASK32              ((uint32)0x00002FEFU)
#define RCM_SRIE_RESET_MASK32               ((uint32)0x00000000U)

#define RCM_SRIE_SACKERR_MASK32             ((uint32)0x00002000U)
#define RCM_SRIE_MDM_AP_MASK32              ((uint32)0x00000800U)
#define RCM_SRIE_SSW_MASK32                 ((uint32)0x00000400U)
#define RCM_SRIE_LOCKUP_MASK32              ((uint32)0x00000200U)
#define RCM_SRIE_JTAG_MASK32                ((uint32)0x00000100U)
#define RCM_SRIE_GIE_MASK32                 ((uint32)0x00000080U)
#define RCM_SRIE_PIN_MASK32                 ((uint32)0x00000040U)
#define RCM_SRIE_WDOG_MASK32                ((uint32)0x00000020U)
#define RCM_SRIE_CMU_MASK32                 ((uint32)0x00000010U)
#define RCM_SRIE_LOL_MASK32                 ((uint32)0x00000008U)
#define RCM_SRIE_LOC_MASK32                 ((uint32)0x00000004U)
#define RCM_SRIE_DELAY_MASK32               ((uint32)0x00000003U)

#define RCM_SRIE_SACKERR_INT_EN_U32         (RCM_SRIE_SACKERR_MASK32)
#define RCM_SRIE_SACKERR_INT_DIS_U32        ((uint32)0x00000000U)

#define RCM_SRIE_MDM_AP_INT_EN_U32          (RCM_SRIE_MDM_AP_MASK32)
#define RCM_SRIE_MDM_AP_INT_DIS_U32         ((uint32)0x00000000U)

#define RCM_SRIE_SSW_INT_EN_U32             (RCM_SRIE_SSW_MASK32)
#define RCM_SRIE_SSW_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_LOCKUP_INT_EN_U32          (RCM_SRIE_LOCKUP_MASK32)
#define RCM_SRIE_LOCKUP_INT_DIS_U32         ((uint32)0x00000000U)

#define RCM_SRIE_JTAG_INT_EN_U32            (RCM_SRIE_JTAG_MASK32)
#define RCM_SRIE_JTAG_INT_DIS_U32           ((uint32)0x00000000U)

#define RCM_SRIE_GIE_INT_EN_U32             (RCM_SRIE_GIE_MASK32)
#define RCM_SRIE_GIE_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_PIN_INT_EN_U32             (RCM_SRIE_PIN_MASK32)
#define RCM_SRIE_PIN_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_WDOG_INT_EN_U32            (RCM_SRIE_WDOG_MASK32)
#define RCM_SRIE_WDOG_INT_DIS_U32           ((uint32)0x00000000U)

#define RCM_SRIE_CMU_INT_EN_U32             (RCM_SRIE_CMU_MASK32)
#define RCM_SRIE_CMU_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_LOL_INT_EN_U32             (RCM_SRIE_LOL_MASK32)
#define RCM_SRIE_LOL_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_LOC_INT_EN_U32             (RCM_SRIE_LOC_MASK32)
#define RCM_SRIE_LOC_INT_DIS_U32            ((uint32)0x00000000U)

#define RCM_SRIE_DELAY_10_LPO_CYCLES_U32    ((uint32)0x00000000U)
#define RCM_SRIE_DELAY_34_LPO_CYCLES_U32    ((uint32)0x00000001U)
#define RCM_SRIE_DELAY_130_LPO_CYCLES_U32   ((uint32)0x00000002U)
#define RCM_SRIE_DELAY_514_LPO_CYCLES_U32   (RCM_SRIE_DELAY_MASK32)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_RCM_H */

/** @} */
