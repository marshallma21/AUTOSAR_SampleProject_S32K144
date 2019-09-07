/**
*   @file    Adc_Reg_eSys_Adc12bsarv2.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Adc module registers, and macrodefinitions used to manipulate the module registers.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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

#ifndef REG_ESYS_ADC12BSARV2_H
#define REG_ESYS_ADC12BSARV2_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Reg_eSys_Adc12bsarv2_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
* 
* @section Adc_Reg_eSys_Adc12bsarv2_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_Reg_eSys_Adc12bsarv2_h_REF_6
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* All used compilers/linkers support 31 character significance and case sensitivity
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Adc_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_REG                      43
#define ADC_AR_RELEASE_MAJOR_VERSION_REG       4
#define ADC_AR_RELEASE_MINOR_VERSION_REG       2
/** @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_6 MISRA-C:2004 Rule 1.4: 31 character significance */
#define ADC_AR_RELEASE_REVISION_VERSION_REG    2
#define ADC_SW_MAJOR_VERSION_REG               1
#define ADC_SW_MINOR_VERSION_REG               0
#define ADC_SW_PATCH_VERSION_REG               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/** @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_6 MISRA-C:2004 Rule 1.4: 31 character significance */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Reg_eSys.h are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Reg_eSys_Adc12bsarv2.h and Reg_eSys.h are different"
#endif
#endif


/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID_REG != ADC_VENDOR_ID_CFG)
#error "Adc_Reg_eSys_Adc12bsarv2.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_REG != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_REG != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_REG != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc_Reg_eSys_Adc12bsarv2.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_REG != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION_REG != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION_REG != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc_Reg_eSys_Adc12bsarv2.h and Adc_Cfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONST_32
/** @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_3 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/**
* @brief Base address array for ADC12BSARV2
*/
extern CONST(uint32, ADC_CONST) ADC12BSARV2_BASE_ADDR32[ADC_MAX_HW_UNITS];

#define ADC_STOP_SEC_CONST_32
/** @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_3 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* The offset for SC1 registers */
#define ADC12BSAR_SC1_OFFSET_ADDR32     (ADC_SC1_OFFSET_ADDR32)
/* The offset for Rn registers */
#define ADC12BSAR_Rn_OFFSET_ADDR32      (ADC_Rn_OFFSET_ADDR32)

/**
* @brief          ADC Base address definition.
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_ADDR32(HwUnit)          (ADC12BSARV2_BASE_ADDR32[(HwUnit)])   

/**
* @brief          ADC Status and Control Register 1 (ADCx_SC1n).
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_SC1_REG_ADDR32(HwUnit, Index)           (ADC12BSARV2_ADDR32(HwUnit) + ADC12BSAR_SC1_OFFSET_ADDR32+ ((Index) << 2))

/**
* @brief          ADC Configuration Register 1 (ADCx_CFG1).
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CFG1_REG_ADDR32(HwUnit)           (ADC12BSARV2_ADDR32(HwUnit) + 0x0040UL)

/**
* @brief          ADC Configuration Register 2 (ADCx_CFG2).
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CFG2_REG_ADDR32(HwUnit)           (ADC12BSARV2_ADDR32(HwUnit) + 0x0044UL)

/**
* @brief          ADC data result register (ADCx_Rn)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_Rn_REG_ADDR32(HwUnit, Index)       (ADC12BSARV2_ADDR32(HwUnit) + ADC12BSAR_Rn_OFFSET_ADDR32 + ((Index) << 2))

/**
* @brief          Compare value register (ADCx_CVn)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CVn_REG_ADDR32(HwUnit, Index)       (ADC12BSARV2_ADDR32(HwUnit) + 0x0088UL + ((Index) << 2))

/**
* @brief          Status and Control Register 2 (ADCx_SC2) 
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_SC2_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x0090UL)

/**
* @brief          Status and Control Register 3 (ADCx_SC3) 
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_SC3_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x0094UL)

/**
* @brief          ADC Offset Correction Register (ADCx_BASE_OFS) 
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_BASE_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x0098UL)

/**
* @brief          ADC Offset Correction Register (ADCx_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x009CUL)

/**
* @brief          ADC USER Offset Correction Register (ADCx_USR_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_USR_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00A0UL)

/**
* @brief          ADC X Offset Correction Register (ADCx_XOFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_XOFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00A4UL)

/**
* @brief          ADC Y Offset Correction Register (ADCx_YOFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_YOFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00A8UL)

/**
* @brief          ADC Gain Register (ADCx_G) 
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_G_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00ACUL)

/**
* @brief          ADC User Gain Register (ADCx_UG)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_UG_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00B0UL)

/**
* @brief          ADC General Calibration Value Register (ADCx_CLPS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLPS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00B4UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register (ADCx_CLP3)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP3_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00B8UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register (ADCx_CLP2)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP2_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00BCUL)

/**
* @brief          ADC Plus-Side General Calibration Value Register (ADCx_CLP1)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP1_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00C0UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register (ADCx_CLP0)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP0_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00C4UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register (ADCx_CLPX)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLPX_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00C8UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLP9)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP9_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00CCUL)

/**
* @brief          ADC General Calibration Value Register (ADCx_CLPS_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLPS_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00D0UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLP3_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP3_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00D4UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLP2_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP2_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00D8UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLP1_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP1_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00DCUL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLP0_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP0_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00E0UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLPX_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLPX_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00E4UL)

/**
* @brief          ADC Plus-Side General Calibration Value Register(ADCx_CLP9_OFS)
*
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP9_OFS_REG_ADDR32(HwUnit)       (ADC12BSARV2_ADDR32(HwUnit) + 0x00E8UL)

/**********************************************************************************
***************             Register for calibration feature             **********
**********************************************************************************/
/**
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP3_LIMIT_REG_ADDR32(HwUnit)     (ADC12BSARV2_ADDR32(HwUnit) + 0x00F4UL)
/**
* @violates @ref Adc_Reg_eSys_Adc12bsarv2_h_REF_1 Function-like macro defined
*/
#define ADC12BSARV2_CLP2_LIMIT_REG_ADDR32(HwUnit)     (ADC12BSARV2_ADDR32(HwUnit) + 0x00F8UL)
/**********************************************************************************
***************    ADC Status and Control Registers 1 (ADCx_SC1n)        **********
**********************************************************************************/
/**
* @brief          COCO: Conversion Complete Flag
*/
#define ADC12BSARV2_SC1n_CONV_COMPLETE_U32                   (0x00000080UL)
/**
* @brief          SC1n reset value: Conversion Complete Flag
*/
#define ADC12BSARV2_SC1n_RESET_VALUE_U32                     (0x0000001FUL)
/**
* @brief          AIEN: Conversion Complete Interrupt Enable/Disable Control.
* @details        An interrupt is generated whenever ADC12BSARV2_SC1n_REG_ADDR32[COCO]=1 (conversion ADC12BSARV2_SC1n_REG_ADDR32 * completed), provided the corresponding interrupt is enabled.
*/
#define ADC12BSARV2_CONV_COMPLETE_INT_EN_U32                 (0x00000040UL)
#define ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32                (0x00000000UL)
#define ADC12BSARV2_CONV_COMPLETE_MASK_U32                   (0x00000080UL)

/**
* @brief          ADCH: Input Channel Select
* @details        This 5-bit field selects one of the input channels. The successive approximation
*  converter subsystem is turned off when the channel select bits are all set (ADCH = 11111b)
*/
#define ADC12BSARV2_ADCH_MASK_U32                            (ADC_ADCH_MASK_U32)
#define ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32              (ADC_ADCH_MASK_U32)

/**********************************************************************************
***************        ADC Configuration Register 1 (ADCx_CFG1)          **********
**********************************************************************************/
/**
* @brief          ADIV: Clock Divide Select.
* @details        Selects the divide ratio used by the ADC to generate the internal clock ADCK.
*/
#define ADC12BSARV2_CFG1_CLOCK_DIV1_U32                (0x00000000UL)
#define ADC12BSARV2_CFG1_CLOCK_DIV2_U32                (0x00000020UL)
#define ADC12BSARV2_CFG1_CLOCK_DIV4_U32                (0x00000040UL)
#define ADC12BSARV2_CFG1_CLOCK_DIV8_U32                (0x00000060UL)

/**
* @brief          CFG1 clock divide mask
*/
#define ADC12BSARV2_CFG1_CLOCK_DIV_MASK_U32            (0x00000060UL)

/**
* @brief          MODE: Conversion mode selection.
* @details        Conversion mode selection.
*/
#define ADC12BSARV2_CFG1_8_BITS_RESOLUTION_U32         (0x00000000UL)
#define ADC12BSARV2_CFG1_10_BITS_RESOLUTION_U32        (0x00000008UL)
#define ADC12BSARV2_CFG1_12_BITS_RESOLUTION_U32        (0x00000004UL)

/**
* @brief          ADCLK: Input Clock Select.
* @details        Input Clock Select.
*/
#define ADC12BSARV2_CFG1_ALTCLK1_U32                   (0x00000000UL)
#define ADC12BSARV2_CFG1_ALTCLK2_U32                   (0x00000001UL)
#define ADC12BSARV2_CFG1_ALTCLK3_U32                   (0x00000002UL)
#define ADC12BSARV2_CFG1_ALTCLK4_U32                   (0x00000003UL)

/**
* @brief          CFG1 reset value
*/
#define ADC12BSARV2_CFG1_RESET_VALUE_U32               (0x00000000UL)

/**
* @brief          CFG1 clock mask
*/
#define ADC12BSARV2_CFG1_SET_CLOCKMODE_MASK_U32        (0x00000063UL)

/**********************************************************************************
***************        ADC Configuration Register 2 (ADCx_CFG2)          **********
**********************************************************************************/
/**
* @brief          SMPLTS: Sample Time Select.
* @details        Selects a sample time of 2 to 256 ADCK clock cycles. The value written to this register 
* is the desired sample time minus 1. A sample time of 1 is not supported. Allows higher impedance inputs 
* to be accurately sampled or to maximize conversion speed for lower impedance inputs. Longer sample times
* can also be used to lower overall power consumption when continuous conversions are enabled if high
* conversion rates are not required.
*/
#define ADC12BSARV2_CFG2_SAMPLE_TIME_MASK_U32                (0x000000FFUL)

/**
* @brief          CFG2 reset value
*/
#define ADC12BSARV2_CFG2_RESET_VALUE_U32                     (0x0000000CUL)

/**********************************************************************************
***************           ADC Data Result Register (ADCx_Rn)             **********
**********************************************************************************/
#define ADC12BSARV2_RESULT_DATA_MASK_8_BIT_U32               (0x000000FFUL)
#define ADC12BSARV2_RESULT_DATA_MASK_10_BIT_U32              (0x000003FFUL)
#define ADC12BSARV2_RESULT_DATA_MASK_12_BIT_U32              (0x00000FFFUL)

/**********************************************************************************
***************           Compare Value Registers (ADCx_CVn)             **********
**********************************************************************************/
/**
* @brief          CV: Compare Value.
*/
#define ADC12BSARV2_COMPARE_VALUE_MASK_U32                   (0x00000FFFUL)
#define ADC12BSARV2_CV_RESET_VALUE_U32                       (0x00000000UL)
/**********************************************************************************
***************         Status and Control Register 2 (ADCx_SC2)         **********
**********************************************************************************/
/**
* @brief          ADACT: Conversion Active.
* @details        Indicates that a conversion or hardware averaging is in progress. ADACT is set when a conversion is
* initiated and cleared when a conversion is completed or aborted.      
*/
#define ADC12BSARV2_SC2_ADACT_U32                       (0x00000080UL)
/**
* @brief          ADTRG: Conversion Trigger Select.
* @details        Two types of trigger are selectable: software trigger and hardware trigger.
*/
#define ADC12BSARV2_SC2_ADTRG_HW_U32                    (0x00000040UL)
#define ADC12BSARV2_SC2_ADTRG_SW_U32                    (0x00000000UL)
/**
* @brief          ACFE: Compare Function Enable.
* @details        Enables the compare function.      
*/
#define ADC12BSARV2_SC2_ACFE_EN_U32                     (0x00000020UL)
#define ADC12BSARV2_SC2_ACFE_DIS_U32                    (0x00000000UL)
/**
* @brief          ACFGT: Compare Function Greater Than Enable.
* @details        Configures the compare function to check the conversion result relative to the CV1 and CV2 based upon
* the value of ACREN. ACFE must be set for ACFGT to have any effect.      
*/
#define ADC12BSARV2_SC2_ACFGT_GREATER_U32               (0x00000010UL)
#define ADC12BSARV2_SC2_ACFGT_LESS_U32                  (0x00000000UL)
/**
* @brief          ACREN: Compare Function Range Enable.
* @details        Configures the compare function to check if the conversion result of the input being monitored is either
* between or outside the range formed by CV1 and CV2 determined by the value of ACFGT. ACFE must be set for ACFGT to have any effect.      
*/
#define ADC12BSARV2_SC2_ACREN_EN_U32                    (0x00000008UL)
#define ADC12BSARV2_SC2_ACREN_DIS_U32                   (0x00000000UL)
/**
* @brief          DMAEN: DMA Enable.
*/
#define ADC12BSARV2_SC2_DMA_EN_U32                       (0x00000004UL)
#define ADC12BSARV2_SC2_DMA_DIS_U32                      (0x00000000UL)
/**
* @brief          REFSEL: Voltage Reference Selection.
* @details        Selects the voltage reference source used for conversions.
*/
#define ADC12BSARV2_SC2_REFSEL_VREFH_VREFL_U32                      (0x00000000UL)
#define ADC12BSARV2_SC2_REFSEL_VALTH_VALTL_U32                      (0x00000001UL)

/**
* @brief          SC2 reset value
*/
#define ADC12BSARV2_SC2_RESET_VALUE_U32                 (0x00000000UL)

/**********************************************************************************
***************         Status and Control Register 3 (ADCx_SC3)         **********
**********************************************************************************/
/**
* @brief          CAL: Calibration.
* @details        Begins the calibration sequence when set. This field stays set while the calibration is in progress and is
* cleared when the calibration sequence is completed. CALF must be checked to determine the result of the
* calibration sequence. Once started, the calibration routine cannot be interrupted by writes to the ADC
* registers or the results will be invalid and CALF will set. Setting CAL will abort any current conversion.      
*/
#define ADC12BSARV2_SC3_CAL_EN_U32                      (0x00000080UL)
#define ADC12BSARV2_SC3_CAL_DIS_U32                     (0x00000000UL)
/**
* @brief          ADCO: Continuous Conversion Enable.
* @details        Enables continuous conversions.
*/
#define ADC12BSARV2_SC3_CONTINUOUS_U32               (0x00000008UL)
#define ADC12BSARV2_SC3_ONESHOT_U32                  (0x00000000UL)
/**
* @brief          AVGE: Hardware Average Enable.
* @details        Enables the hardware average function of the ADC.
*/
#define ADC12BSARV2_SC3_AVGE_EN_U32                     (0x00000004UL)
#define ADC12BSARV2_SC3_AVGE_DIS_U32                    (0x00000000UL)
#define ADC12BSARV2_SC3_AVG_MASK_U32                    (0x00000007UL)
/**
* @brief          AVGS: Hardware Average Select.
* @details        Determines how many ADC conversions will be averaged to create the ADC average result.
*/
#define ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32                     (0x00000000UL)
#define ADC12BSARV2_SC3_AVGS_8_SAMPLES_U32                     (0x00000001UL)
#define ADC12BSARV2_SC3_AVGS_16_SAMPLES_U32                    (0x00000002UL)
#define ADC12BSARV2_SC3_AVGS_32_SAMPLES_U32                    (0x00000003UL)

/**
* @brief          SC3 reset value
*/
#define ADC12BSARV2_SC3_RESET_VALUE_U32              (0x00000000UL)
/**********************************************************************************
**********        ADC Offset Correction Register (ADCx_BASE_OFS)         **********
**********************************************************************************/
/**
* @brief          BA_OFS: Base Offset Error Correction Value.
*/
#define ADC12BSARV2_BASE_OFS_U32                     (0x000000FFUL)

/**********************************************************************************
***************        ADC Offset Correction Register (ADCx_OFS)         **********
**********************************************************************************/
/**
* @brief          OFS: Offset Error Correction Value.
*/
#define ADC12BSARV2_OFS_U32                          (0x00000FFFUL)

/**********************************************************************************
*************     ADC USER Offset Correction Register (ADCx_USR_OFS)     **********
**********************************************************************************/
/**
* @brief          USR_OFS: USER Offset Error Correction Value.
*/
#define ADC12BSARV2_USR_OFS_U32                      (0x000000FFUL)

/**********************************************************************************
***************         ADC X Offset Correction Register (ADCx_XOFS)     **********
**********************************************************************************/
/**
* @brief          XOFS: Offset Error Correction Value.
*/
#define ADC12BSARV2_XOFS_U32                         (0x0000003FUL)

/**********************************************************************************
***************         ADC Y Offset Correction Register (ADCx_YOFS)     **********
**********************************************************************************/
/**
* @brief          YOFS: Offset Error Correction Value.
*/
#define ADC12BSARV2_YOFS_U32                         (0x000000FFUL)

/**********************************************************************************
***************         ADC Gain Register (ADCx_G)                       **********
**********************************************************************************/
/**
* @brief          G: Gain.
*/
#define ADC12BSARV2_G_U32                           (0x00000FFFUL)

/**********************************************************************************
***************         ADC User Gain Register (ADCx_UG)                 **********
**********************************************************************************/
/**
* @brief          UG: User Gain.
*/
#define ADC12BSARV2_UG_U32                          (0x000003FFUL)

/**********************************************************************************
***************     ADC General Calibration Value Register (ADCx_CLPS)   **********
**********************************************************************************/
/**
* @brief          CLPS: Calibration Value.
*/
#define ADC12BSARV2_CLPS_U32                        (0x0000007FUL)

/**********************************************************************************
********   ADC Plus-Side General Calibration Value Register (ADCx_CLP3   **********
**********************************************************************************/
/**
* @brief          CLP3: Calibration Value.
*/
#define ADC12BSARV2_CLP3_U32                        (0x0000003FFUL)

/**********************************************************************************
********   ADC Plus-Side General Calibration Value Register(ADCx_CLP2)   **********
**********************************************************************************/
/**
* @brief          CLP2: Calibration Value.
*/
#define ADC12BSARV2_CLP2_U32                        (0x0000001FFUL)

/**********************************************************************************
********   ADC Plus-Side General Calibration Value Register(ADCx_CLP1)   **********
**********************************************************************************/
/**
* @brief          CLP1: Calibration Value.
*/
#define ADC12BSARV2_CLP1_U32                        (0x0000001FFUL)

/**********************************************************************************
********   ADC Plus-Side General Calibration Value Register(ADCx_CLP0)   **********
**********************************************************************************/
/**
* @brief          CLP0: Calibration Value.
*/
#define ADC12BSARV2_CLP0_U32                        (0x0000000FFUL)

/**********************************************************************************
********   ADC Plus-Side General Calibration Value Register(ADCx_CLPX)   **********
**********************************************************************************/
/**
* @brief          CLPXEN: CLPX compare bit.
* @details        Controls how comparison of CLPX is evaluated to be a pass or fail.
*/
#define ADC12BSARV2_CLPXEN_U32                      (0x000000080UL)
/**
* @brief          CLPX: Calibration Value.
*/
#define ADC12BSARV2_CLPX_U32                        (0x00000007FUL)

/**********************************************************************************
********   ADC Plus-Side General Calibration Value Register(ADCx_CLP9)   **********
**********************************************************************************/
/**
* @brief          CLP9EN: CLP9 compare bit.
* @details        Controls how comparison of CLP9 is evaluated to be a pass or fail.
*/
#define ADC12BSARV2_CLP9EN_U32                      (0x000000080UL)
/**
* @brief          CLP9: Calibration Value.
*/
#define ADC12BSARV2_CLP9_U32                        (0x00000007FUL)

/**********************************************************************************
********   ADC General Calibration Value Register (ADCx_CLPS_OFS)        **********
**********************************************************************************/
/**
* @brief          CLPS_OFS: CLPS Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLPS_OFS_U32                    (0x00000000FUL)

/**********************************************************************************
********  ADC Plus-Side General Calibration Value Register(ADCx_CLP3_OFS) *********
**********************************************************************************/
/**
* @brief          CLP3_OFS: CLP3 Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLP3_OFS_U32                    (0x000000000FUL)

/**********************************************************************************
********  ADC Plus-Side General Calibration Value Register(ADCx_CLP2_OFS) *********
**********************************************************************************/
/**
* @brief          CLP2_OFS: CLP2 Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLP2_OFS_U32                    (0x00000000FUL)

/**********************************************************************************
********  ADC Plus-Side General Calibration Value Register(ADCx_CLP1_OFS) *********
**********************************************************************************/
/**
* @brief          CLP1_OFS: CLP1 Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLP1_OFS_U32                    (0x00000000FUL)

/**********************************************************************************
********  ADC Plus-Side General Calibration Value Register(ADCx_CLP0_OFS) *********
**********************************************************************************/
/**
* @brief          CLP0_OFS: CLP1 Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLP0_OFS_U32                    (0x00000000FUL)

/**********************************************************************************
********  ADC Plus-Side General Calibration Value Register(ADCx_CLPX_OFS)  *********
**********************************************************************************/
/**
* @brief          CLPX_OFS: CLPX Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLPX_OFS_U32                    (0x000000FFFUL)

/**********************************************************************************
********  ADC Plus-Side General Calibration Value Register(ADCx_CLP9_OFS)  *********
**********************************************************************************/
/**
* @brief          CLP9_OFS: CLP9 Offset.
* @details        Capacitor offset correction value.
*/
#define ADC12BSARV2_CLP9_OFS_U32                    (0x000000FFFUL)

/**********************************************************************************
********            Mask for CLP3_LIMIT and CLP2_LIMIT register           *********
**********************************************************************************/
#define ADC12BSARV2_CLP3_LIMIT_MASK_U32                 (0x000001D2UL)
#define ADC12BSARV2_CLP2_LIMIT_MASK_U32                 (0x000000E9UL)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_ADC12BSARV2_H */

/** @} */
