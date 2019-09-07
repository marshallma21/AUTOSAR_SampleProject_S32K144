/**
*   @file    Reg_eSys_SIM.h
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


#ifndef REG_ESYS_SIM_H
#define REG_ESYS_SIM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_SIM_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, : The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*
* @section Reg_eSys_SIM_h_REF_2
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

#define REG_ESYS_SIM_VENDOR_ID                       43
#define REG_ESYS_SIM_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_SIM_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_SIM_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_SIM_SW_MAJOR_VERSION                1
#define REG_ESYS_SIM_SW_MINOR_VERSION                0
#define REG_ESYS_SIM_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_SIM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_SIM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_SIM.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/********** SIM Registers **********/

/* SIM_CHIPCTL - Chip Control register */
#define SIM_CHIPCTL_ADDR32                  ((uint32)(SIM_BASEADDR + (uint32)0x00000004U))
/* SIM_FTMOPT0 - FTM Option Register 0 */
#define SIM_FTMOPT0_ADDR32                  ((uint32)(SIM_BASEADDR + (uint32)0x0000000CU))
/* SIM_LPOCLKS - LPO Clock Select Register */
#define SIM_LPOCLKS_ADDR32                  ((uint32)(SIM_BASEADDR + (uint32)0x00000010U))
/* SIM_ADCOPT - ADC Options Register */
#define SIM_ADCOPT_ADDR32                   ((uint32)(SIM_BASEADDR + (uint32)0x00000018U))
/* SIM_FTMOPT1 - FTM Option Register 1 */
#define SIM_FTMOPT1_ADDR32                  ((uint32)(SIM_BASEADDR + (uint32)0x0000001CU))
/* SIM_MISCTRL0 - Miscellaneous control register 0 */
#define SIM_MISCTRL0_ADDR32                 ((uint32)(SIM_BASEADDR + (uint32)0x00000020U))
/* SIM_SDID - System Device Identification Register */
#define SIM_SDID_ADDR32                     ((uint32)(SIM_BASEADDR + (uint32)0x00000024U))
/* SIM_PLATCGC - Platform Clock Gating Control Register */
#define SIM_PLATCGC_ADDR32                  ((uint32)(SIM_BASEADDR + (uint32)0x00000040U))
/* SIM_FCFG1 - Flash Configuration Register 1 */
#define SIM_FCFG1_ADDR32                    ((uint32)(SIM_BASEADDR + (uint32)0x0000004CU))
/* SIM_FCFG2 - Flash Configuration Register 2 */
#define SIM_FCFG2_ADDR32                    ((uint32)(SIM_BASEADDR + (uint32)0x00000050U))
/* SIM_UIDH - Unique Identification Register High */
#define SIM_UIDH_ADDR32                     ((uint32)(SIM_BASEADDR + (uint32)0x00000054U))
/* SIM_UIDMH - Unique Identification Register Mid-High */
#define SIM_UIDMH_ADDR32                    ((uint32)(SIM_BASEADDR + (uint32)0x00000058U))
/* SIM_UIDML - Unique Identification Register Mid Low */
#define SIM_UIDML_ADDR32                    ((uint32)(SIM_BASEADDR + (uint32)0x0000005CU))
/* SIM_UIDL - Unique Identification Register Low */
#define SIM_UIDL_ADDR32                     ((uint32)(SIM_BASEADDR + (uint32)0x00000060U))
/* SIM_CLKDIV4 - System Clock Divider Register 4 */
#define SIM_CLKDIV4_ADDR32                  ((uint32)(SIM_BASEADDR + (uint32)0x00000068U))
/* SIM_MISCTRL1 - Miscellaneous Control register 1 */
#define SIM_MISCTRL1_ADDR32                 ((uint32)(SIM_BASEADDR + (uint32)0x0000006CU))

/****************************************************/
/***              SIM_CHIPCTL                     ***/
/****************************************************/
#define SIM_CHIPCTL_RWBITS_MASK32               ((uint32)0x003F3FFFU)
#define SIM_CHIPCTL_INIT_MASK32                 ((uint32)0x000F200FU)
#define SIM_CHIPCTL_CLOCK_MASK32                ((uint32)0x00001FF0U)

#define SIM_CHIPCTL_SRAML_RETEN_MASK32          ((uint32)0x00200000U)
#define SIM_CHIPCTL_SRAMU_RETEN_MASK32          ((uint32)0x00100000U)
#define SIM_CHIPCTL_ADC_SUPPLYEN_MASK32         ((uint32)0x00080000U)
#define SIM_CHIPCTL_ADC_SUPPLY_MASK32           ((uint32)0x00070000U)
#define SIM_CHIPCTL_PDB_BB_SEL_MASK32           ((uint32)0x00002000U)
#define SIM_CHIPCTL_TRACECLK_SEL_MASK32         ((uint32)0x00001000U)
#define SIM_CHIPCTL_CLKOUTEN_MASK32             ((uint32)0x00000800U)
#define SIM_CHIPCTL_CLKOUTDIV_MASK32            ((uint32)0x00000700U)
#define SIM_CHIPCTL_CLKOUTDIV_SHIFT32           ((uint32)8U)
#define SIM_CHIPCTL_CLKOUTSEL_MASK32            ((uint32)0x000000F0U)
#define SIM_CHIPCTL_ADC_INTERLEAVE_SEL_MASK32   ((uint32)0x0000000FU)

#define SIM_CHIPCTL_SRAML_CONTENT_RETAINED_U32  ((uint32)0x00000000U)
#define SIM_CHIPCTL_NO_SRAML_RETENTION_U32      (SIM_CHIPCTL_SRAML_RETEN_MASK32)

#define SIM_CHIPCTL_SRAMU_CONTENT_RETAINED_U32  ((uint32)0x00000000U)
#define SIM_CHIPCTL_NO_SRAMU_RETENTION_U32      (SIM_CHIPCTL_SRAMU_RETEN_MASK32)

#define SIM_CHIPCTL_DISABLE_ADC_SUPPLY_MON_U32  ((uint32)0x00000000U)
#define SIM_CHIPCTL_ENABLE_ADC_SUPPLY_MON_U32   (SIM_CHIPCTL_ADC_SUPPLYEN_MASK32)

#define SIM_CHIPCTL_ADC_SUPPLY_VDD_U32          ((uint32)0x00000000U)
#define SIM_CHIPCTL_ADC_SUPPLY_VDDA_U32         ((uint32)0x00010000U)
#define SIM_CHIPCTL_ADC_SUPPLY_VREFH_U32        ((uint32)0x00020000U)
#define SIM_CHIPCTL_ADC_SUPPLY_VDD_3V_U32       ((uint32)0x00030000U)
#define SIM_CHIPCTL_ADC_SUPPLY_VDD_FLASH_3V_U32 ((uint32)0x00040000U)
#define SIM_CHIPCTL_ADC_SUPPLY_VDD_LV_U32       ((uint32)0x00050000U)

#define SIM_CHIPCTL_TRACECLK_CORE_CLK_U32       ((uint32)0x00000000U)
#define SIM_CHIPCTL_TRACECLK_PLATFORM_CLK_U32   (SIM_CHIPCTL_TRACECLK_SEL_MASK32)

#define SIM_CHIPCTL_CLKOUT_DISABLE_U32          ((uint32)0x00000000U)
#define SIM_CHIPCTL_CLKOUT_ENABLE_U32           (SIM_CHIPCTL_CLKOUTEN_MASK32)

/** @violates @ref Reg_eSys_SIM_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SIM_CHIPCTL_CLKOUTDIV_U32(value)   ((uint32)((uint32)((uint32)(value) << SIM_CHIPCTL_CLKOUTDIV_SHIFT32) & SIM_CHIPCTL_CLKOUTDIV_MASK32))

#define SIM_CHIPCTL_CLKOUTSEL_SCG_CLKOUT_U32            ((uint32)0x00000000U)
#define SIM_CHIPCTL_CLKOUTSEL_SOSC_DIV2_U32             ((uint32)0x00000020U)
#define SIM_CHIPCTL_CLKOUTSEL_SIRC_DIV2_U32             ((uint32)0x00000040U)
/** @violates @ref Reg_eSys_SIM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_SFIF_CLK_HYP_U32     ((uint32)0x00000050U)
#define SIM_CHIPCTL_CLKOUTSEL_FIRC_DIV2_U32             ((uint32)0x00000060U)
#define SIM_CHIPCTL_CLKOUTSEL_HCLK_U32                  ((uint32)0x00000070U)
#define SIM_CHIPCTL_CLKOUTSEL_SPLL_DIV2_U32             ((uint32)0x00000080U)
#define SIM_CHIPCTL_CLKOUTSEL_BUS_CLK_U32               ((uint32)0x00000090U)
#define SIM_CHIPCTL_CLKOUTSEL_LPO_CLK_128K_U32          ((uint32)0x000000A0U)
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_IPG_CLK_U32          ((uint32)0x000000B0U)
#define SIM_CHIPCTL_CLKOUTSEL_LPO_CLK_U32               ((uint32)0x000000C0U)
/** @violates @ref Reg_eSys_SIM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_IPG_CLK_SFIF_U32     ((uint32)0x000000D0U)
#define SIM_CHIPCTL_CLKOUTSEL_RTC_CLK_U32               ((uint32)0x000000E0U)
/** @violates @ref Reg_eSys_SIM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define SIM_CHIPCTL_CLKOUTSEL_QSPI_IPG_CLK_2XSFIF_U32   (SIM_CHIPCTL_CLKOUTSEL_MASK32)

#define SIM_CHIPCTL_NO_INTERLEAVE_CHANNEL_U32   ((uint32)0x00000000U)
#define SIM_PTB14_TO_ADC1_SE9_AND_ADC0_SE9_U32  ((uint32)0x00000008U)
#define SIM_PTB13_TO_ADC1_SE8_AND_ADC0_SE8_U32  ((uint32)0x00000004U)
#define SIM_PTB1_TO_ADC0_SE4_AND_ADC1_SE15_U32  ((uint32)0x00000002U)
#define SIM_PTB0_TO_ADC0_SE4_AND_ADC1_SE14_U32  ((uint32)0x00000001U)


/****************************************************/
/***              SIM_FTMOPT0                     ***/
/****************************************************/
#define SIM_FTMOPT0_RWBITS_MASK32           ((uint32)0xFFFF7777U)

#define SIM_FTMOPT0_FTM3CLKSEL_MASK32       ((uint32)0xC0000000U)
#define SIM_FTMOPT0_FTM2CLKSEL_MASK32       ((uint32)0x30000000U)
#define SIM_FTMOPT0_FTM1CLKSEL_MASK32       ((uint32)0x0C000000U)
#define SIM_FTMOPT0_FTM0CLKSEL_MASK32       ((uint32)0x03000000U)
#define SIM_FTMOPT0_FTM7CLKSEL_MASK32       ((uint32)0x00C00000U)
#define SIM_FTMOPT0_FTM6CLKSEL_MASK32       ((uint32)0x00300000U)
#define SIM_FTMOPT0_FTM5CLKSEL_MASK32       ((uint32)0x000C0000U)
#define SIM_FTMOPT0_FTM4CLKSEL_MASK32       ((uint32)0x00030000U)

#define SIM_FTMOPT0_FTM3FLTXSEL_MASK32      ((uint32)0x00007000U)
#define SIM_FTMOPT0_FTM2FLTXSEL_MASK32      ((uint32)0x00000700U)
#define SIM_FTMOPT0_FTM1FLTXSEL_MASK32      ((uint32)0x00000070U)
#define SIM_FTMOPT0_FTM0FLTXSEL_MASK32      ((uint32)0x00000007U)

#define SIM_FTM3CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM3CLKSEL_TCLK1_PIN_U32        ((uint32)0x40000000U)
#define SIM_FTM3CLKSEL_TCLK2_PIN_U32        ((uint32)0x80000000U)
#define SIM_FTM3CLKSEL_NO_CLOCK_U32         ((uint32)0xC0000000U)

#define SIM_FTM2CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM2CLKSEL_TCLK1_PIN_U32        ((uint32)0x10000000U)
#define SIM_FTM2CLKSEL_TCLK2_PIN_U32        ((uint32)0x20000000U)
#define SIM_FTM2CLKSEL_NO_CLOCK_U32         ((uint32)0x30000000U)

#define SIM_FTM1CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM1CLKSEL_TCLK1_PIN_U32        ((uint32)0x04000000U)
#define SIM_FTM1CLKSEL_TCLK2_PIN_U32        ((uint32)0x08000000U)
#define SIM_FTM1CLKSEL_NO_CLOCK_U32         ((uint32)0x0C000000U)

#define SIM_FTM0CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM0CLKSEL_TCLK1_PIN_U32        ((uint32)0x01000000U)
#define SIM_FTM0CLKSEL_TCLK2_PIN_U32        ((uint32)0x02000000U)
#define SIM_FTM0CLKSEL_NO_CLOCK_U32         ((uint32)0x03000000U)

#define SIM_FTM7CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM7CLKSEL_TCLK1_PIN_U32        ((uint32)0x00400000U)
#define SIM_FTM7CLKSEL_TCLK2_PIN_U32        ((uint32)0x00800000U)
#define SIM_FTM7CLKSEL_NO_CLOCK_U32         ((uint32)0x00C00000U)

#define SIM_FTM6CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM6CLKSEL_TCLK1_PIN_U32        ((uint32)0x00100000U)
#define SIM_FTM6CLKSEL_TCLK2_PIN_U32        ((uint32)0x00200000U)
#define SIM_FTM6CLKSEL_NO_CLOCK_U32         ((uint32)0x00300000U)

#define SIM_FTM5CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM5CLKSEL_TCLK1_PIN_U32        ((uint32)0x00040000U)
#define SIM_FTM5CLKSEL_TCLK2_PIN_U32        ((uint32)0x00080000U)
#define SIM_FTM5CLKSEL_NO_CLOCK_U32         ((uint32)0x000C0000U)

#define SIM_FTM4CLKSEL_TCLK0_PIN_U32        ((uint32)0x00000000U)
#define SIM_FTM4CLKSEL_TCLK1_PIN_U32        ((uint32)0x00010000U)
#define SIM_FTM4CLKSEL_TCLK2_PIN_U32        ((uint32)0x00020000U)
#define SIM_FTM4CLKSEL_NO_CLOCK_U32         ((uint32)0x00030000U)

#define SIM_FTM3_FLT0_PIN_FLT0_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM3_OUT_FLT0_U32        ((uint32)0x00001000U)

#define SIM_FTM3_FLT1_PIN_FLT1_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM3_OUT_FLT1_U32        ((uint32)0x00002000U)

#define SIM_FTM3_FLT2_PIN_FLT2_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM3_OUT_FLT2_U32        ((uint32)0x00004000U)

#define SIM_FTM2_FLT0_PIN_FLT0_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM2_OUT_FLT0_U32        ((uint32)0x00000100U)

#define SIM_FTM2_FLT1_PIN_FLT1_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM2_OUT_FLT1_U32        ((uint32)0x00000200U)

#define SIM_FTM2_FLT2_PIN_FLT2_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM2_OUT_FLT2_U32        ((uint32)0x00000400U)

#define SIM_FTM1_FLT0_PIN_FLT0_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM1_OUT_FLT0_U32        ((uint32)0x00000010U)

#define SIM_FTM1_FLT1_PIN_FLT1_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM1_OUT_FLT1_U32        ((uint32)0x00000020U)

#define SIM_FTM1_FLT2_PIN_FLT2_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM1_OUT_FLT2_U32        ((uint32)0x00000040U)

#define SIM_FTM0_FLT0_PIN_FLT0_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM0_OUT_FLT0_U32        ((uint32)0x00000001U)

#define SIM_FTM0_FLT1_PIN_FLT1_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM0_OUT_FLT1_U32        ((uint32)0x00000002U)

#define SIM_FTM0_FLT2_PIN_FLT2_U32          ((uint32)0x00000000U)
#define SIM_TRGMUX_FTM0_OUT_FLT2_U32        ((uint32)0x00000004U)

/****************************************************/
/***              SIM_LPOCLKS                     ***/
/****************************************************/
#define SIM_LPOCLKS_RWBITS_MASK32           ((uint32)0x0000003FU)

#define SIM_LPOCLKS_RTCCLKSEL_MASK32        ((uint32)0x00000030U)
#define SIM_LPOCLKS_LPOCLKSEL_MASK32        ((uint32)0x0000000CU)
#define SIM_LPOCLKS_LPO32KCLKEN_MASK32      ((uint32)0x00000002U)
#define SIM_LPOCLKS_LPO1KCLKEN_MASK32       ((uint32)0x00000001U)

#define SIM_RTCCLKSEL_SOSCDIV1_CLK_U32      ((uint32)0x00000000U)
#define SIM_RTCCLKSEL_LPO_CLK_32K_U32       ((uint32)0x00000010U)
#define SIM_RTCCLKSEL_RTC_CLKIN_CLK_U32     ((uint32)0x00000020U)
#define SIM_RTCCLKSEL_FIRCDIV1_CLK_U32      ((uint32)0x00000030U)

#define SIM_LPOCLKSEL_LPO_CLK_128K_U32    ((uint32)0x00000000U)
#define SIM_LPOCLKSEL_NO_CLOCK_U32        ((uint32)0x00000004U)
#define SIM_LPOCLKSEL_LPO_CLK_32K_U32     ((uint32)0x00000008U)
#define SIM_LPOCLKSEL_LPO_CLK_1K_U32      ((uint32)0x0000000CU)

#define SIM_DISABLE_32KHZ_LPO_CLK_U32       ((uint32)0x00000000U)
#define SIM_ENABLE_32KHZ_LPO_CLK_U32        (SIM_LPOCLKS_LPO32KCLKEN_MASK32)

#define SIM_DISABLE_1KHZ_LPO_CLK_U32        ((uint32)0x00000000U)
#define SIM_ENABLE_1KHZ_LPO_CLK_U32         (SIM_LPOCLKS_LPO1KCLKEN_MASK32)

/****************************************************/
/***              SIM_ADCOPT                      ***/
/****************************************************/
#define SIM_ADCOPT_RWBITS_MASK32            ((uint32)0x00003F3FU)

#define SIM_ADCOPT_ADC1PRETRGSEL_MASK32     ((uint32)0x00003000U)
#define SIM_ADCOPT_ADC1SWPRETRG_MASK32      ((uint32)0x00000E00U)
#define SIM_ADCOPT_ADC1TRGSEL_MASK32        ((uint32)0x00000100U)

#define SIM_ADCOPT_ADC0PRETRGSEL_MASK32     ((uint32)0x00000030U)
#define SIM_ADCOPT_ADC0SWPRETRG_MASK32      ((uint32)0x0000000EU)
#define SIM_ADCOPT_ADC0TRGSEL_MASK32        ((uint32)0x00000001U)

#define SIM_ADC1_PDB_PRE_TRIGGER_U32        ((uint32)0x00000000U)
#define SIM_ADC1_TRGMUX_PRE_TRIGGER_U32     ((uint32)0x00001000U)
#define SIM_ADC1_SOFTWARE_PRE_TRIGGER_U32   ((uint32)0x00002000U)

#define SIM_ADC1_SW_PRE_TRIGGER_DISABLE_U32 ((uint32)0x00000000U)
#define SIM_ADC1_SW_PRE_TRIGGER_0_U32       ((uint32)0x00000800U)
#define SIM_ADC1_SW_PRE_TRIGGER_1_U32       ((uint32)0x00000A00U)
#define SIM_ADC1_SW_PRE_TRIGGER_2_U32       ((uint32)0x00000C00U)
#define SIM_ADC1_SW_PRE_TRIGGER_3_U32       ((uint32)0x00000E00U)

#define SIM_ADC1_PDB_TRIGGER_SOURCE_U32     ((uint32)0x00000000U)
#define SIM_ADC1_TRGMUX_TRIGGER_SOURCE_U32  (SIM_ADCOPT_ADC1TRGSEL_MASK32)

#define SIM_ADC0_PDB_PRE_TRIGGER_U32        ((uint32)0x00000000U)
#define SIM_ADC0_TRGMUX_PRE_TRIGGER_U32     ((uint32)0x00000010U)
#define SIM_ADC0_SOFTWARE_PRE_TRIGGER_U32   ((uint32)0x00000020U)

#define SIM_ADC0_SW_PRE_TRIGGER_DISABLE_U32 ((uint32)0x00000000U)
#define SIM_ADC0_SW_PRE_TRIGGER_0_U32       ((uint32)0x00000008U)
#define SIM_ADC0_SW_PRE_TRIGGER_1_U32       ((uint32)0x0000000AU)
#define SIM_ADC0_SW_PRE_TRIGGER_2_U32       ((uint32)0x0000000CU)
#define SIM_ADC0_SW_PRE_TRIGGER_3_U32       ((uint32)0x0000000EU)

#define SIM_ADC0_PDB_TRIGGER_SOURCE_U32     ((uint32)0x00000000U)
#define SIM_ADC0_TRGMUX_TRIGGER_SOURCE_U32  (SIM_ADCOPT_ADC0TRGSEL_MASK32)

/****************************************************/
/***              SIM_FTMOPT1                     ***/
/****************************************************/
#define SIM_FTMOPT1_RWBITS_MASK32           ((uint32)0xFFFFF9FFU)

#define SIM_FTMOPT1_FTM3OUTSEL_MASK32       ((uint32)0xFF000000U)
#define SIM_FTMOPT1_FTM3OUTSEL_SHIFT32      ((uint32)24U)
#define SIM_FTMOPT1_FTM0OUTSEL_MASK32       ((uint32)0x00FF0000U)
#define SIM_FTMOPT1_FTM0OUTSEL_SHIFT32      ((uint32)16U)
#define SIM_FTMOPT1_FTMGLDOK_MASK32         ((uint32)0x00008000U)
#define SIM_FTMOPT1_FTM7SYNCBIT_MASK32      ((uint32)0x00004000U)
#define SIM_FTMOPT1_FTM6SYNCBIT_MASK32      ((uint32)0x00002000U)
#define SIM_FTMOPT1_FTM5SYNCBIT_MASK32      ((uint32)0x00001000U)
#define SIM_FTMOPT1_FTM4SYNCBIT_MASK32      ((uint32)0x00000800U)
#define SIM_FTMOPT1_FTM2CH1SEL_MASK32       ((uint32)0x00000100U)
#define SIM_FTMOPT1_FTM2CH0SEL_MASK32       ((uint32)0x000000C0U)
#define SIM_FTMOPT1_FTM1CH0SEL_MASK32       ((uint32)0x00000030U)
#define SIM_FTMOPT1_FTM3SYNCBIT_MASK32      ((uint32)0x00000008U)
#define SIM_FTMOPT1_FTM2SYNCBIT_MASK32      ((uint32)0x00000004U)
#define SIM_FTMOPT1_FTM1SYNCBIT_MASK32      ((uint32)0x00000002U)
#define SIM_FTMOPT1_FTM0SYNCBIT_MASK32      ((uint32)0x00000001U)

#define SIM_MODULATION_WITH_FTMX_CH0_U32    ((uint32)0x00000001U)
#define SIM_MODULATION_WITH_FTMX_CH1_U32    ((uint32)0x00000002U)
#define SIM_MODULATION_WITH_FTMX_CH2_U32    ((uint32)0x00000004U)
#define SIM_MODULATION_WITH_FTMX_CH3_U32    ((uint32)0x00000008U)
#define SIM_MODULATION_WITH_FTMX_CH4_U32    ((uint32)0x00000010U)
#define SIM_MODULATION_WITH_FTMX_CH5_U32    ((uint32)0x00000020U)
#define SIM_MODULATION_WITH_FTMX_CH6_U32    ((uint32)0x00000040U)
#define SIM_MODULATION_WITH_FTMX_CH7_U32    ((uint32)0x00000080U)

#define SIM_NO_MODULATION_FOR_FTMX_CH_U32   ((uint32)0x00000000U)

#define SIM_FTM_GLOBAL_LOAD_DISABLED_U32    ((uint32)0x00000000U)
#define SIM_FTM_GLOBAL_LOAD_ENABLED_U32     (SIM_FTMOPT1_FTMGLDOK_MASK32)

/** @violates @ref Reg_eSys_SIM_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SIM_FTMOPT1_FTM3OUTSEL_U32(value)   ((uint32)((uint32)((uint32)(value) << SIM_FTMOPT1_FTM3OUTSEL_SHIFT32) & SIM_FTMOPT1_FTM3OUTSEL_MASK32))

/** @violates @ref Reg_eSys_SIM_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SIM_FTMOPT1_FTM0OUTSEL_U32(value)   ((uint32)((uint32)((uint32)(value) << SIM_FTMOPT1_FTM0OUTSEL_SHIFT32) & SIM_FTMOPT1_FTM0OUTSEL_MASK32))

#define SIM_FTM2CH1SEL_FTM2_CH1_U32         ((uint32)0x00000000U)
#define SIM_FTM2CH1SEL_XOR_U32              (SIM_FTMOPT1_FTM2CH1SEL_MASK32)

#define SIM_FTM2CH0SEL_FTM2_CH0_INPUT_U32   ((uint32)0x00000000U)
#define SIM_FTM2CH0SEL_CMP0_OUTPUT_U32      ((uint32)0x00000040U)

#define SIM_FTM1CH0SEL_FTM1_CH0_INPUT_U32   ((uint32)0x00000000U)
#define SIM_FTM1CH0SEL_CMP0_OUTPUT_U32      ((uint32)0x00000010U)

/****************************************************/
/***              SIM_MISCTRL0                    ***/
/****************************************************/
#define SIM_MISCTRL0_RWBITS_MASK32          ((uint32)0x07FF4000U)

#define SIM_QSPI_CLK_REFERENCE_EN_U32       ((uint32)0x04000000U)
#define SIM_QSPI_CLK_REFERENCE_DIS_U32      ((uint32)0x00000000U)

#define SIM_RMII_CLK_SEL_SOSCDIV1_DIS_U32   ((uint32)0x00000000U)
#define SIM_RMII_CLK_SEL_SOSCDIV1_EN_U32    ((uint32)0x02000000U)

#define SIM_RMII_CLK_OBE_EN_U32             ((uint32)0x01000000U)
#define SIM_RMII_CLK_OBE_DIS_U32            ((uint32)0x00000000U)

#define SIM_MISCTRL0_FTM7_OBE_CTRL_MASK32   ((uint32)0x00800000U)
#define SIM_MISCTRL0_FTM6_OBE_CTRL_MASK32   ((uint32)0x00400000U)
#define SIM_MISCTRL0_FTM5_OBE_CTRL_MASK32   ((uint32)0x00200000U)
#define SIM_MISCTRL0_FTM4_OBE_CTRL_MASK32   ((uint32)0x00100000U)
#define SIM_MISCTRL0_FTM3_OBE_CTRL_MASK32   ((uint32)0x00080000U)
#define SIM_MISCTRL0_FTM2_OBE_CTRL_MASK32   ((uint32)0x00040000U)
#define SIM_MISCTRL0_FTM1_OBE_CTRL_MASK32   ((uint32)0x00020000U)
#define SIM_MISCTRL0_FTM0_OBE_CTRL_MASK32   ((uint32)0x00010000U)

#define SIM_FTM7_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM7_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM7_OBE_CTRL_MASK32)

#define SIM_FTM6_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM6_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM6_OBE_CTRL_MASK32)

#define SIM_FTM5_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM5_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM5_OBE_CTRL_MASK32)

#define SIM_FTM4_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM4_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM4_OBE_CTRL_MASK32)

#define SIM_FTM3_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM3_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM3_OBE_CTRL_MASK32)

#define SIM_FTM2_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM2_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM2_OBE_CTRL_MASK32)

#define SIM_FTM1_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM1_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM1_OBE_CTRL_MASK32)

#define SIM_FTM0_OUTPUT_SAFE_STATE_U32      ((uint32)0x00000000U)
#define SIM_FTM0_OUTPUT_TRISTATE_U32        (SIM_MISCTRL0_FTM0_OBE_CTRL_MASK32)

#define SIM_FTM_GTB_SPLIT_EN_U32            ((uint32)0x00004000U)
#define SIM_FTM_GTB_SPLIT_DIS_U32           ((uint32)0x00000000U)

/****************************************************/
/***              SIM_PLATGC                      ***/
/****************************************************/
#ifdef MCU_PLATGC_GPIO_CLK_SUPPORT
    #if (MCU_PLATGC_GPIO_CLK_SUPPORT == STD_OFF)
        #define SIM_PLATGC_RWBITS_MASK32            ((uint32)0x0000001FU)
    #else
        #define SIM_PLATGC_RWBITS_MASK32            ((uint32)0x0000002FU)
    #endif
#else
    #define SIM_PLATGC_RWBITS_MASK32            ((uint32)0x0000001FU)
#endif
    
    

#define SIM_PLATGC_CGCGPIO_MASK32           ((uint32)0x00000020U)
#define SIM_PLATGC_CGCEIM_MASK32            ((uint32)0x00000010U)
#define SIM_PLATGC_CGCERM_MASK32            ((uint32)0x00000008U)
#define SIM_PLATGC_CGCDMA_MASK32            ((uint32)0x00000004U)
#define SIM_PLATGC_CGCMPU_MASK32            ((uint32)0x00000002U)
#define SIM_PLATGC_CGCMSCM_MASK32           ((uint32)0x00000001U)

#define SIM_PLATGC_EIM_CLK_ENABLE_U32       (SIM_PLATGC_CGCEIM_MASK32)
#define SIM_PLATGC_EIM_CLK_DISABLE_U32      ((uint32)0x00000000U)

#define SIM_PLATGC_ERM_CLK_ENABLE_U32       (SIM_PLATGC_CGCERM_MASK32)
#define SIM_PLATGC_ERM_CLK_DISABLE_U32      ((uint32)0x00000000U)

#define SIM_PLATGC_DMA_CLK_ENABLE_U32       (SIM_PLATGC_CGCDMA_MASK32)
#define SIM_PLATGC_DMA_CLK_DISABLE_U32      ((uint32)0x00000000U)

#define SIM_PLATGC_MPU_CLK_ENABLE_U32       (SIM_PLATGC_CGCMPU_MASK32)
#define SIM_PLATGC_MPU_CLK_DISABLE_U32      ((uint32)0x00000000U)

#define SIM_PLATGC_MSCM_CLK_ENABLE_U32      (SIM_PLATGC_CGCMSCM_MASK32)
#define SIM_PLATGC_MSCM_CLK_DISABLE_U32     ((uint32)0x00000000U)

#define SIM_PLATGC_GPIO_CLK_ENABLE_U32      (SIM_PLATGC_CGCGPIO_MASK32)
#define SIM_PLATGC_GPIO_CLK_DISABLE_U32     ((uint32)0x00000000U)

/****************************************************/
/***              SIM_CLKDIV4                     ***/
/****************************************************/
#define SIM_CLKDIV4_RWBITS_MASK32               ((uint32)0x1000000FU)

#define SIM_CLKDIV4_TRACEDIVEN_MASK32           ((uint32)0x10000000U)
#define SIM_CLKDIV4_TRACEDIV_MASK32             ((uint32)0x0000000EU)
#define SIM_CLKDIV4_TRACEDIV_SHIFT32            ((uint32)1U)
#define SIM_CLKDIV4_TRACEFRAC_MASK32            ((uint32)0x00000001U)

#define SIM_DEBUG_TRACE_DIVIDER_DISABLED_U32    ((uint32)0x00000000U)
#define SIM_DEBUG_TRACE_DIVIDER_ENABLED_U32     (SIM_CLKDIV4_TRACEDIVEN_MASK32)

#define SIM_CLKDIV4_TRACEFRAC_0_U32            ((uint32)0x00000000U)
#define SIM_CLKDIV4_TRACEFRAC_1_U32            (SIM_CLKDIV4_TRACEFRAC_MASK32)

/** @violates @ref Reg_eSys_SIM_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define SIM_CLKDIV4_TRACEDIV_U32(value)         ((uint32)((uint32)((value) << SIM_CLKDIV4_TRACEDIV_SHIFT32) & SIM_CLKDIV4_TRACEDIV_MASK32))


/****************************************************/
/***              SIM_MISCTRL1                    ***/
/****************************************************/
#define SIM_MISCTRL1_RWBITS_MASK32              ((uint32)0x00000001U)

#define SIM_MISCTRL1_SW_TRG_MASK32              ((uint32)0x00000001U)

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

#endif /* REG_ESYS_SIM_H */

/** @} */
