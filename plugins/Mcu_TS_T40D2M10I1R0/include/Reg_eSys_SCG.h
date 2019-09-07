/**
*   @file    Reg_eSys_SCG.h
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


#ifndef REG_ESYS_SCG_H
#define REG_ESYS_SCG_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_SCG_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, : The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*
* @section Reg_eSys_SCG_h_REF_2
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

#define REG_ESYS_SCG_VENDOR_ID                       43
#define REG_ESYS_SCG_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_SCG_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_SCG_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_SCG_SW_MAJOR_VERSION                1
#define REG_ESYS_SCG_SW_MINOR_VERSION                0
#define REG_ESYS_SCG_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_SCG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_SCG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_SCG.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/********** SCG Registers **********/

/* SCG_VERID - Version ID Register */
#define SCG_VERID_ADDR32                    ((uint32)(SCG_BASEADDR + (uint32)0x00000000U))
/* SCG_PARAM - Parameter Register */
#define SCG_PARAM_ADDR32                    ((uint32)(SCG_BASEADDR + (uint32)0x00000004U))
/* SCG_CSR - Clock Status Register */
#define SCG_CSR_ADDR32                      ((uint32)(SCG_BASEADDR + (uint32)0x00000010U))
/* SCG_RCCR - Run Clock Control Register */
#define SCG_RCCR_ADDR32                     ((uint32)(SCG_BASEADDR + (uint32)0x00000014U))
/* SCG_VCCR - VLPR Clock Control Register */
#define SCG_VCCR_ADDR32                     ((uint32)(SCG_BASEADDR + (uint32)0x00000018U))
/* SCG_HCCR - HSRUN Clock Control Register */
#define SCG_HCCR_ADDR32                     ((uint32)(SCG_BASEADDR + (uint32)0x0000001CU))
/* SCG_CLKOUTCNFG - SCG CLKOUT Configuration Register */
#define SCG_CLKOUTCNFG_ADDR32               ((uint32)(SCG_BASEADDR + (uint32)0x00000020U))
/* SCG_SOSCCSR - System OSC Control Status Register */
#define SCG_SOSCCSR_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000100U))
/* SCG_SOSCDIV - System OSC Divide Register */
#define SCG_SOSCDIV_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000104U))
/* SCG_SOSCCFG - System Oscillator Configuration Register */
#define SCG_SOSCCFG_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000108U))
/* SCG_SIRCCSR - Slow IRC Control Status Register */
#define SCG_SIRCCSR_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000200U))
/* SCG_SIRCDIV - Slow IRC Divide Register */
#define SCG_SIRCDIV_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000204U))
/* SCG_SIRCCFG - Slow IRC Configuration Register */
#define SCG_SIRCCFG_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000208U))
/* SCG_FIRCCSR - Fast IRC Control Status Register */
#define SCG_FIRCCSR_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000300U))
/* SCG_FIRCDIV - Fast IRC Divide Register */
#define SCG_FIRCDIV_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000304U))
/* SCG_FIRCCFG - Fast IRC Configuration Register */
#define SCG_FIRCCFG_ADDR32                  ((uint32)(SCG_BASEADDR + (uint32)0x00000308U))
/* SCG_FIRCTCFG - Fast IRC Trim Configuration Register */
#define SCG_FIRCTCFG_ADDR32                 ((uint32)(SCG_BASEADDR + (uint32)0x0000030CU))
/* SCG_FIRCSTAT - Fast IRC Status Register */
#define SCG_FIRCSTAT_ADDR32                 ((uint32)(SCG_BASEADDR + (uint32)0x00000318U))
/* SCG_SPLLCSR - System PLL Control Status Register */
#define SCG_SPLLCSR_ADDR32                 ((uint32)(SCG_BASEADDR + (uint32)0x00000600U))
/* SCG_SPLLDIV - System PLL Divide Register */
#define SCG_SPLLDIV_ADDR32                 ((uint32)(SCG_BASEADDR + (uint32)0x00000604U))
/* SCG_SPLLCFG - System PLL Configuration Register */
#define SCG_SPLLCFG_ADDR32                 ((uint32)(SCG_BASEADDR + (uint32)0x00000608U))


/****************************************************/
/***              SCG_PARAM                       ***/
/****************************************************/
#define SCG_PARAM_RWBITS_MASK32               ((uint32)0x00000000U)

#define SCG_PARAM_DIVPRES_MASK32              ((uint32)0xF0000000U)
#define SCG_PARAM_CLKPRES_MASK32              ((uint32)0x000000FFU)

#define SCG_PARAM_DIVPRES_DIVSLOW_U32         ((uint32)0x10000000U)
#define SCG_PARAM_DIVPRES_DIVBUS_U32          ((uint32)0x20000000U)
#define SCG_PARAM_DIVPRES_DIVPLAT_U32         ((uint32)0x40000000U)
#define SCG_PARAM_DIVPRES_DIVCORE_U32         ((uint32)0x80000000U)

#define SCG_PARAM_CLKPRES_SOSC_U32          ((uint32)0x00000002U)
#define SCG_PARAM_CLKPRES_SIRC_U32          ((uint32)0x00000004U)
#define SCG_PARAM_CLKPRES_FIRC_U32          ((uint32)0x00000008U)
#define SCG_PARAM_CLKPRES_SPLL_U32          ((uint32)0x00000040U)

/****************************************************/
/***              SCG_CSR                         ***/
/****************************************************/
#define SCG_CSR_RWBITS_MASK32               ((uint32)0x00000000U)

#define SCG_CSR_SCS_MASK32                  ((uint32)0x0F000000U)
#define SCG_CSR_DIVCORE_MASK32              ((uint32)0x000F0000U)
#define SCG_CSR_DIVBUS_MASK32               ((uint32)0x000000F0U)
#define SCG_CSR_DIVSLOW_MASK32              ((uint32)0x0000000FU)

#define SCG_CSR_SCS_SOSC_U32                ((uint32)0x01000000U)
#define SCG_CSR_SCS_SIRC_U32                ((uint32)0x02000000U)
#define SCG_CSR_SCS_FIRC_U32                ((uint32)0x03000000U)
#define SCG_CSR_SCS_SPLL_U32                ((uint32)0x06000000U)

/****************************************************/
/***              SCG_RCCR                        ***/
/****************************************************/
#define SCG_RCCR_RWBITS_MASK32                ((uint32)0x0F0F00FFU)

#define SCG_RCCR_SCS_MASK32                   ((uint32)0x0F000000U)
#define SCG_RCCR_DIVCORE_MASK32               ((uint32)0x000F0000U)
#define SCG_RCCR_DIVCORE_SHIFT32              ((uint32)16U)
#define SCG_RCCR_DIVBUS_MASK32                ((uint32)0x000000F0U)
#define SCG_RCCR_DIVBUS_SHIFT32               ((uint32)4U)
#define SCG_RCCR_DIVSLOW_MASK32               ((uint32)0x0000000FU)

#define SCG_SCS_SOSC_U32                ((uint32)0x01000000U)
#define SCG_SCS_SIRC_U32                ((uint32)0x02000000U)
#define SCG_SCS_FIRC_U32                ((uint32)0x03000000U)
#define SCG_SCS_SPLL_U32                ((uint32)0x06000000U)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_DIVCORE_U32(value)          ((uint32)((uint32)((value) << SCG_RCCR_DIVCORE_SHIFT32) & SCG_RCCR_DIVCORE_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_DIVBUS_U32(value)           ((uint32)((uint32)((value) << SCG_RCCR_DIVBUS_SHIFT32) & SCG_RCCR_DIVBUS_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_DIVSLOW_U32(value)          (((value) & SCG_RCCR_DIVSLOW_MASK32))

/****************************************************/
/***              SCG_VCCR                        ***/
/****************************************************/
#define SCG_VCCR_RWBITS_MASK32                ((uint32)0x0F0F00FFU)

#define SCG_VCCR_SCS_MASK32                   ((uint32)0x0F000000U)
#define SCG_VCCR_DIVCORE_MASK32               ((uint32)0x000F0000U)
#define SCG_VCCR_DIVCORE_SHIFT32              ((uint32)16U)
#define SCG_VCCR_DIVBUS_MASK32                ((uint32)0x000000F0U)
#define SCG_VCCR_DIVBUS_SHIFT32               ((uint32)4U)
#define SCG_VCCR_DIVSLOW_MASK32               ((uint32)0x0000000FU)

/****************************************************/
/***              SCG_HCCR                        ***/
/****************************************************/
#define SCG_HCCR_RWBITS_MASK32                ((uint32)0x0F0FF0FFU)

#define SCG_HCCR_SCS_MASK32                   ((uint32)0x0F000000U)
#define SCG_HCCR_DIVCORE_MASK32               ((uint32)0x000F0000U)
#define SCG_HCCR_DIVCORE_SHIFT32              ((uint32)16U)
#define SCG_HCCR_DIVPLAT_MASK32               ((uint32)0x0000F000U)
#define SCG_HCCR_DIVPLAT_SHIFT32              ((uint32)12U)
#define SCG_HCCR_DIVBUS_MASK32                ((uint32)0x000000F0U)
#define SCG_HCCR_DIVBUS_SHIFT32               ((uint32)4U)
#define SCG_HCCR_DIVSLOW_MASK32               ((uint32)0x0000000FU)

/****************************************************/
/***              SCG_CLKOUTCNFG                  ***/
/****************************************************/
#define SCG_CLKOUTCNFG_RWBITS_MASK32                     ((uint32)0x0F000000U)

#define SCG_CLKOUTCNFG_CLKOUTSEL_MASK32                  ((uint32)0x0F000000U)

#define SCG_CLKOUTCNFG_CLKOUTSEL_SCG_SLOW_CLK_U32        ((uint32)0x00000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_SOSC_U32                ((uint32)0x01000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_SIRC_U32                ((uint32)0x02000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_FIRC_U32                ((uint32)0x03000000U)
#define SCG_CLKOUTCNFG_CLKOUTSEL_SPLL_U32                ((uint32)0x06000000U)

/****************************************************/
/***              SCG_SOSCCSR                     ***/
/****************************************************/
#define SCG_SOSCCSR_RWBITS_MASK32               ((uint32)0x04830001U)

#define SCG_SOSCCSR_SOSCERR_MASK32              ((uint32)0x04000000U)
#define SCG_SOSCCSR_SOSCVLD_MASK32              ((uint32)0x01000000U)
#define SCG_SOSCCSR_LK_MASK32                   ((uint32)0x00800000U)
#define SCG_SOSCCSR_SOSCCMRE_MASK32             ((uint32)0x00020000U)
#define SCG_SOSCCSR_SOSCCM_MASK32               ((uint32)0x00010000U)
#define SCG_SOSCCSR_SOSCERCLKEN_MASK32          ((uint32)0x00000008U)
#define SCG_SOSCCSR_SOSCEN_MASK32               ((uint32)0x00000001U)

#define SCG_SOSCCSR_LK_UNLOCK_U32               ((uint32)0x00000000U) 
#define SCG_SOSCCSR_LK_LOCK_U32                 (SCG_SOSCCSR_LK_MASK32)

#define SCG_SOSCCSR_SOSCCMRE_ISR_U32            ((uint32)0x00000000U)
#define SCG_SOSCCSR_SOSCCMRE_RESET_U32          (SCG_SOSCCSR_SOSCCMRE_MASK32)

#define SCG_SOSCCSR_SOSCCM_DIS_U32              ((uint32)0x00000000U)
#define SCG_SOSCCSR_SOSCCM_ENA_U32              (SCG_SOSCCSR_SOSCCM_MASK32)

#define SCG_SOSCCSR_SOSCERCLKEN_ERCLK_DIS_U32   ((uint32)0x00000000U)
#define SCG_SOSCCSR_SOSCERCLKEN_ERCLK_ENA_U32   (SCG_SOSCCSR_SOSCERCLKEN_MASK32)

#define SCG_SOSCCSR_SOSC_DISABLE_U32            ((uint32)0x00000000U)
#define SCG_SOSCCSR_SOSC_ENABLE_U32             (SCG_SOSCCSR_SOSCEN_MASK32)

/****************************************************/
/***              SCG_SOSCDIV                     ***/
/****************************************************/
#define SCG_SOSCDIV_RWBITS_MASK32               ((uint32)0x00000707U)

#define SCG_SOSCDIV_SOSCDIV2_MASK32             ((uint32)0x00000700U)
#define SCG_SOSCDIV_SOSCDIV2_SHIFT32            ((uint32)8U)
#define SCG_SOSCDIV_SOSCDIV1_MASK32             ((uint32)0x00000007U)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SOSCDIV_SOSCDIV2_U32(value)           ((uint32)((uint32)((value) << SCG_SOSCDIV_SOSCDIV2_SHIFT32) & SCG_SOSCDIV_SOSCDIV2_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SOSCDIV_SOSCDIV1_U32(value)          (((value) & SCG_SOSCDIV_SOSCDIV1_MASK32))

/****************************************************/
/***              SCG_SOSCCFG                     ***/
/****************************************************/
#define SCG_SOSCCFG_RWBITS_MASK32               ((uint32)0x0000003CU)

#define SCG_SOSCCFG_RANGE_MASK32                ((uint32)0x00000030U)
#define SCG_SOSCCFG_HG0_MASK32                  ((uint32)0x00000008U)
#define SCG_SOSCCFG_EREFS_MASK32                ((uint32)0x00000004U)
#define SCG_SOSCCSR_SOSCEN_MASK32                   ((uint32)0x00000001U)

#define SCG_SOSCCFG_LOW_FREQ_RANGE_U32          ((uint32)0x00000010U)
#define SCG_SOSCCFG_MEDIUM_FREQ_RANGE_U32       ((uint32)0x00000020U)
#define SCG_SOSCCFG_HIGH_FREQ_RANGE_U32         (SCG_SOSCCFG_RANGE_MASK32)

#define SCG_SOSCCFG_LOW_POWER_OPERATION_U32     ((uint32)0x00000000U)
#define SCG_SOSCCFG_HIGH_GAIN_OPERATION_U32     (SCG_SOSCCFG_HG0_MASK32)

#define SCG_SOSCCFG_EXTERNAL_REFERENCE_U32      ((uint32)0x00000000U)
#define SCG_SOSCCFG_INTERNAL_OSCILLATOR_U32     (SCG_SOSCCFG_EREFS_MASK32)

#define SCG_SOSCCSR_SOSC_DISABLE_U32            ((uint32)0x00000000U)
#define SCG_SOSCCSR_SOSC_ENABLE_U32             (SCG_SOSCCSR_SOSCEN_MASK32)

/****************************************************/
/***              SCG_SIRCCSR                     ***/
/****************************************************/
#define SCG_SIRCCSR_RWBITS_MASK32               ((uint32)0x00800007U)
#define SCG_SIRCCSR_RESBITS_MASK32              ((uint32)0x03000000U)

#define SCG_SIRCCSR_LK_MASK32                   ((uint32)0x00800000U)
#define SCG_SIRCCSR_SIRCLPEN_MASK32             ((uint32)0x00000004U)
#define SCG_SIRCCSR_SIRCSTEN_MASK32             ((uint32)0x00000002U)
#define SCG_SIRCCSR_SIRCEN_MASK32               ((uint32)0x00000001U)

#define SCG_SIRCCSR_SIRCVLD_MASK32              ((uint32)0x01000000U)

#define SCG_SIRCCSR_LK_UNLOCK_U32               ((uint32)0x00000000U) 
#define SCG_SIRCCSR_LK_LOCK_U32                 (SCG_SIRCCSR_LK_MASK32)

#define SCG_SIRCCSR_SIRCLPEN_VLP_DIS_U32        ((uint32)0x00000000U)
#define SCG_SIRCCSR_SIRCLPEN_VLP_ENA_U32        (SCG_SIRCCSR_SIRCLPEN_MASK32)

#define SCG_SIRCCSR_SIRCSTEN_STOP_DIS_U32       ((uint32)0x00000000U)
#define SCG_SIRCCSR_SIRCSTEN_STOP_ENA_U32       (SCG_SIRCCSR_SIRCSTEN_MASK32)

#define SCG_SIRCCSR_SIRC_DISABLE_U32            ((uint32)0x00000000U)
#define SCG_SIRCCSR_SIRC_ENABLE_U32             (SCG_SIRCCSR_SIRCEN_MASK32)

/****************************************************/
/***             SCG_SIRCDIV                      ***/
/****************************************************/
#define SCG_SIRCDIV_RWBITS_MASK32               ((uint32)0x00000707U)

#define SCG_SIRCDIV_SIRCDIV2_MASK32             ((uint32)0x00000700U)
#define SCG_SIRCDIV_SIRCDIV2_SHIFT32            ((uint32)8U)
#define SCG_SIRCDIV_SIRCDIV1_MASK32             ((uint32)0x00000007U)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SIRCDIV_SIRCDIV2_U32(value)           ((uint32)((uint32)((uint32)(value) << SCG_SIRCDIV_SIRCDIV2_SHIFT32) & SCG_SIRCDIV_SIRCDIV2_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SIRCDIV_SIRCDIV1_U32(value)          (((uint32)(value) & SCG_SIRCDIV_SIRCDIV1_MASK32))

/****************************************************/
/***         SCG_SIRCCFG                          ***/
/****************************************************/
#define SCG_SIRCCFG_RWBITS_MASK32                   ((uint32)0x00000001U)

#define SCG_SIRCCFG_RANGE_MASK32                    ((uint32)0x00000001U)

#define SCG_SIRCCFG_LOW_RANGE_CLOCK_U32             ((uint32)0x00000000U)
#define SCG_SIRCCFG_HIGH_RANGE_CLOCK_U32            ((uint32)0x00000001U)

/****************************************************/
/***            SCG_FIRCCSR                       ***/
/****************************************************/
#define SCG_FIRCCSR_RWBITS_MASK32                   ((uint32)0x04800009U)

#define SCG_FIRCCSR_FIRCERR_MASK32                  ((uint32)0x04000000U)
#define SCG_FIRCCSR_LK_MASK32                       ((uint32)0x00800000U)
#define SCG_FIRCCSR_FIRCTRUP_MASK32                 ((uint32)0x00000200U)
#define SCG_FIRCCSR_FIRCTREN_MASK32                 ((uint32)0x00000100U)
#define SCG_FIRCCSR_FIRCREGOFF_MASK32               ((uint32)0x00000008U)
#define SCG_FIRCCSR_FIRCEN_MASK32                   ((uint32)0x00000001U)

#define SCG_FIRCCSR_FIRCVLD_MASK32                  ((uint32)0x01000000U)

#define SCG_FIRCCSR_LK_UNLOCK_U32                   ((uint32)0x00000000U)
#define SCG_FIRCCSR_LK_LOCK_U32                     (SCG_FIRCCSR_LK_MASK32)

#define SCG_FIRCCSR_FIRCTRUP_DIS_U32                ((uint32)0x00000000U)
#define SCG_FIRCCSR_FIRCTRUP_ENA_U32                (SCG_FIRCCSR_FIRCTRUP_MASK32)

#define SCG_FIRCCSR_FIRCTREN_DIS_U32                ((uint32)0x00000000U)
#define SCG_FIRCCSR_FIRCTREN_ENA_U32                (SCG_FIRCCSR_FIRCTREN_MASK32)

#define SCG_FIRCCSR_REGULATOR_ENABLE_U32            ((uint32)0x00000000U)
#define SCG_FIRCCSR_REGULATOR_DISABLE_U32           (SCG_FIRCCSR_FIRCREGOFF_MASK32)

#define SCG_FIRCCSR_FIRC_DISABLE_U32                ((uint32)0x00000000U)
#define SCG_FIRCCSR_FIRC_ENABLE_U32                 (SCG_FIRCCSR_FIRCEN_MASK32)

#define SCG_FIRCCSR_CONFIG_REG                      (2U)

/****************************************************/
/***          SCG_FIRCDIV                         ***/
/****************************************************/
#define SCG_FIRCDIV_RWBITS_MASK32               ((uint32)0x00000707U)

#define SCG_FIRCDIV_FIRCDIV2_MASK32             ((uint32)0x00000700U)
#define SCG_FIRCDIV_FIRCDIV2_SHIFT32            ((uint32)8U)
#define SCG_FIRCDIV_FIRCDIV1_MASK32             ((uint32)0x00000007U)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_FIRCDIV_FIRCDIV2_U32(value)           ((uint32)((uint32)((uint32)(value) << SCG_FIRCDIV_FIRCDIV2_SHIFT32) & SCG_FIRCDIV_FIRCDIV2_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_FIRCDIV_FIRCDIV1_U32(value)          (((uint32)(value) & SCG_FIRCDIV_FIRCDIV1_MASK32))

/****************************************************/
/***                   SCG_FIRCCFG                ***/
/****************************************************/
#define SCG_FIRCCFG_RWBITS_MASK32                 ((uint32)0x00000003U)

#define SCG_FIRCCFG_RANGE_MASK32                  ((uint32)0x00000003U)

#define SCG_FIRCCFG_48MHZ_U32                 ((uint32)0x00000000U)
#define SCG_FIRCCFG_52MHZ_U32                 ((uint32)0x00000001U)
#define SCG_FIRCCFG_56MHZ_U32                 ((uint32)0x00000002U)
#define SCG_FIRCCFG_60MHZ_U32                 ((uint32)0x00000003U)

/****************************************************/
/***                   SCG_FIRCTCFG               ***/
/****************************************************/
#define SCG_FIRCTCFG_RWBITS_MASK32                 ((uint32)0x00000073U)

#define SCG_FIRCTCFG_TRIMDIV_MASK32                ((uint32)0x00000070U)
#define SCG_FIRCTCFG_TRIMSRC_MASK32                ((uint32)0x00000003U)
/** @violates @ref Reg_eSys_SCG_h_REF_1 MISRA 2004 Required Rule 1.4*/
#define SCG_FIRCTCFG_TRIMDIV_DIVIDE_BY_1_U32       ((uint32)0x00000000U)
/** @violates @ref Reg_eSys_SCG_h_REF_1 MISRA 2004 Required Rule 1.4*/
#define SCG_FIRCTCFG_TRIMDIV_DIVIDE_BY_128_U32     ((uint32)0x00000100U)
/** @violates @ref Reg_eSys_SCG_h_REF_1 MISRA 2004 Required Rule 1.4*/
#define SCG_FIRCTCFG_TRIMDIV_DIVIDE_BY_256_U32     ((uint32)0x00000200U)
/** @violates @ref Reg_eSys_SCG_h_REF_1 MISRA 2004 Required Rule 1.4*/
#define SCG_FIRCTCFG_TRIMDIV_DIVIDE_BY_512_U32     ((uint32)0x00000300U)
/** @violates @ref Reg_eSys_SCG_h_REF_1 MISRA 2004 Required Rule 1.4*/
#define SCG_FIRCTCFG_TRIMDIV_DIVIDE_BY_1024_U32    ((uint32)0x00000400U)
/** @violates @ref Reg_eSys_SCG_h_REF_1 MISRA 2004 Required Rule 1.4*/
#define SCG_FIRCTCFG_TRIMDIV_DIVIDE_BY_2048_U32    ((uint32)0x00000500U)

#define SCG_FIRCTCFG_TRIMSRC_SOSC_U32              ((uint32)0x00000002U)

/****************************************************/
/***                   SCG_FIRCSTAT               ***/
/****************************************************/
#define SCG_FIRCSTAT_RWBITS_MASK32                 ((uint32)0x00003F7FU)

#define SCG_FIRCSTAT_TRIMCOAR_MASK32               ((uint32)0x00003F00U)
#define SCG_FIRCSTAT_TRIMCOAR_SHIFT32              ((uint32)8U)
#define SCG_FIRCSTAT_TRIMFINE_MASK32               ((uint32)0x0000007FU)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_FIRCSTAT_TRIMCOAR_U32(value)          ((uint32)((uint32)((value) << SCG_FIRCSTAT_TRIMCOAR_SHIFT32) & SCG_FIRCSTAT_TRIMCOAR_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_FIRCSTAT_TRIMFINE_U32(value)          (((value) & SCG_FIRCSTAT_TRIMFINE_MASK32))

/****************************************************/
/***              SCG_SPLLCSR                     ***/
/****************************************************/
#define SCG_SPLLCSR_RWBITS_MASK32               ((uint32)0x04830001U)

#define SCG_SPLLCSR_SPLLERR_MASK32              ((uint32)0x04000000U)
#define SCG_SPLLCSR_SPLLVLD_MASK32              ((uint32)0x01000000U)
#define SCG_SPLLCSR_LK_MASK32                   ((uint32)0x00800000U)
#define SCG_SPLLCSR_SPLLCMRE_MASK32             ((uint32)0x00020000U)
#define SCG_SPLLCSR_SPLLCM_MASK32               ((uint32)0x00010000U)
#define SCG_SPLLCSR_SPLLEN_MASK32               ((uint32)0x00000001U)

#define SCG_SPLLCSR_LK_UNLOCK_U32               ((uint32)0x00000000U) 
#define SCG_SPLLCSR_LK_LOCK_U32                 (SCG_SPLLCSR_LK_MASK32)

#define SCG_SPLLCSR_SPLLCMRE_ISR_U32            ((uint32)0x00000000U)
#define SCG_SPLLCSR_SPLLCMRE_RESET_U32          (SCG_SPLLCSR_SPLLCMRE_MASK32)

#define SCG_SPLLCSR_SPLLCM_DIS_U32              ((uint32)0x00000000U)
#define SCG_SPLLCSR_SPLLCM_ENA_U32              (SCG_SPLLCSR_SPLLCM_MASK32)

#define SCG_SPLLCSR_SPLL_DISABLE_U32            ((uint32)0x00000000U)
#define SCG_SPLLCSR_SPLL_ENABLE_U32             (SCG_SPLLCSR_SPLLEN_MASK32)

/****************************************************/
/***             SCG_SPLLDIV                      ***/
/****************************************************/
#define SCG_SPLLDIV_RWBITS_MASK32               ((uint32)0x00000707U)

#define SCG_SPLLDIV_SPLLDIV2_MASK32             ((uint32)0x00000700U)
#define SCG_SPLLDIV_SPLLDIV2_SHIFT32            ((uint32)8U)
#define SCG_SPLLDIV_SPLLDIV1_MASK32             ((uint32)0x00000007U)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SPLLDIV_SPLLDIV2_U32(value)           ((uint32)((uint32)((value) << SCG_SPLLDIV_SPLLDIV2_SHIFT32) & SCG_SPLLDIV_SPLLDIV2_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SPLLDIV_SPLLDIV1_U32(value)          (((value) & SCG_SPLLDIV_SPLLDIV1_MASK32))

/****************************************************/
/***         SCG_SPLLCFG                          ***/
/****************************************************/
#define SCG_SPLLCFG_RWBITS_MASK32                   ((uint32)0x001F0700U)

#define SCG_SPLLCFG_MULT_MASK32                     ((uint32)0x001F0000U)
#define SCG_SPLLCFG_MULT_SHIFT32                    ((uint32)16U)
#define SCG_SPLLCFG_PREDIV_MASK32                   ((uint32)0x00000700U)
#define SCG_SPLLCFG_PREDIV_SHIFT32                  ((uint32)8U)

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SPLLCFG_MULT_U32(value)                 ((uint32)((uint32)((value) << SCG_SPLLCFG_MULT_SHIFT32) & SCG_SPLLCFG_MULT_MASK32))

/** @violates @ref Reg_eSys_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SCG_SPLLCFG_PREDIV_U32(value)               ((uint32)((uint32)((value) << SCG_SPLLCFG_PREDIV_SHIFT32) & SCG_SPLLCFG_PREDIV_MASK32))

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

#endif /* REG_ESYS_SCG_H */

/** @} */
