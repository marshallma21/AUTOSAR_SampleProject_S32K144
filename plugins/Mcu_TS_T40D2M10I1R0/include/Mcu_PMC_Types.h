/**
*   @file    Mcu_PMC_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from MC_PCU.
*   @details Public data types exported outside of the Mcu driver.
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


#ifndef MCU_PMC_TYPES_H
#define MCU_PMC_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_PMC_Types_h_REF_1
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
#include "Mcu_Cfg.h"
#include "Reg_eSys_PMC.h"
#include "Soc_Ips.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_PMC_TYPES_VENDOR_ID                        43
#define MCU_PMC_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define MCU_PMC_TYPES_AR_RELEASE_MINOR_VERSION         2
#define MCU_PMC_TYPES_AR_RELEASE_REVISION_VERSION      2
#define MCU_PMC_TYPES_SW_MAJOR_VERSION                 1
#define MCU_PMC_TYPES_SW_MINOR_VERSION                 0
#define MCU_PMC_TYPES_SW_PATCH_VERSION                 1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_PMC_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_PMC_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_PMC_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PMC_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PMC_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_PMC_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_PMC_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_PMC_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_PMC_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMC_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_PMC header file are from the same vendor */
#if (MCU_PMC_TYPES_VENDOR_ID != REG_ESYS_PMC_VENDOR_ID)
    #error "Mcu_PMC_Types.h and Reg_eSys_PMC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_PMC header file are of the same Autosar version */
#if ((MCU_PMC_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_PMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PMC_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_PMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PMC_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_PMC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_PMC_Types.h and Reg_eSys_PMC.h are different"
#endif
/* Check if source file and Reg_eSys_PMC header file are of the same Software version */
#if ((MCU_PMC_TYPES_SW_MAJOR_VERSION != REG_ESYS_PMC_SW_MAJOR_VERSION) || \
     (MCU_PMC_TYPES_SW_MINOR_VERSION != REG_ESYS_PMC_SW_MINOR_VERSION) || \
     (MCU_PMC_TYPES_SW_PATCH_VERSION != REG_ESYS_PMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMC_Types.h and Reg_eSys_PMC.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PMC_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PMC_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_PMC_Types.h and Soc_Ips.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#if (IPV_PMC == IPV_PMC_01_00_02_05)

    /****************************************************/
    /***                  PMC_MCR                     ***/
    /****************************************************/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_MCR_U32(value)                  ((uint32)(((value) & PMC_MCR_RWBITS_MASK32) | PMC_MCR_RESBITS_MASK32))

    #define PMC_MCR_LVRER_EN_U32                    (PMC_MCR_LVRER_MASK32)
    #define PMC_MCR_LVREH_EN_U32                    (PMC_MCR_LVREH_MASK32)
    #define PMC_MCR_LVRE50_EN_U32                   (PMC_MCR_LVRE50_MASK32)
    #define PMC_MCR_LVRE33_EN_U32                   (PMC_MCR_LVRE33_MASK32)
    #define PMC_MCR_LVREC_EN_U32                    (PMC_MCR_LVREC_MASK32)
    #define PMC_MCR_LVREA_EN_U32                    (PMC_MCR_LVREA_MASK32)
    #define PMC_MCR_LVIER_EN_U32                    (PMC_MCR_LVIER_MASK32)
    #define PMC_MCR_LVIEH_EN_U32                    (PMC_MCR_LVIEH_MASK32)
    #define PMC_MCR_LVIE50_EN_U32                   (PMC_MCR_LVIE50_MASK32)
    #define PMC_MCR_LVIE33_EN_U32                   (PMC_MCR_LVIE33_MASK32)
    #define PMC_MCR_LVIEC_EN_U32                    (PMC_MCR_LVIEC_MASK32)
    #define PMC_MCR_LVIEA_EN_U32                    (PMC_MCR_LVIEA_MASK32)
    #define PMC_MCR_TLK_EN_U32                      (PMC_MCR_TLK_MASK32)

    #define PMC_MCR_LVRER_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVREH_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVRE50_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_MCR_LVRE33_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_MCR_LVREC_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVREA_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVIER_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVIEH_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVIE50_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_MCR_LVIE33_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_MCR_LVIEC_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_LVIEA_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_MCR_TLK_DIS_U32                     ((uint32)0x00000000U)


    /****************************************************/
    /***                 PMC_TRIMR                    ***/
    /****************************************************/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_U32(value)                ((uint32)(((value) & PMC_TRIMR_RWBITS_MASK32) | PMC_TRIMR_RESBITS_MASK32))
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_LVDATRIM_U32(value)       ((uint32)(( (value) << PMC_TRIMR_LVDATRIM_SHIFT32 ) & PMC_TRIMR_LVDATRIM_MASK32))
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_LVDREGTRIM_U32(value)     ((uint32)(( (value) << PMC_TRIMR_LVDREGTRIM_SHIFT32 ) & PMC_TRIMR_LVDREGTRIM_MASK32))
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_VDD33TRIM_U32(value)      ((uint32)(( (value) << PMC_TRIMR_VDD33TRIM_SHIFT32 ) & PMC_TRIMR_VDD33TRIM_MASK32))
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_LVD33TRIM_U32(value)      ((uint32)(( (value) << PMC_TRIMR_LVD33TRIM_SHIFT32 ) & PMC_TRIMR_LVD33TRIM_MASK32))
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_VDDCTRIM_U32(value)       ((uint32)(( (value) << PMC_TRIMR_VDDCTRIM_SHIFT32 ) & PMC_TRIMR_VDDCTRIM_MASK32))
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_PMC_TRIMR_LVDCTRIM_U32(value)       ((uint32)(( (value) << PMC_TRIMR_LVDCTRIM_SHIFT32 ) & PMC_TRIMR_LVDCTRIM_MASK32))

#endif /* (IPV_PMC == IPV_PMC_01_00_02_05) */


#if (IPV_PMC == IPV_PMC_00_00_01_20)

    /***              PMC_SSR                         ***/
    #define PMC_SSR_VOLTAGE_BITS_MASK32      ((uint32)0x0000007EU)

    /***              PMC_CR                          ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CR_CONFIG_U32(value)           (((value) & PMC_CR_RWBITS_MASK32))

    #define PMC_CR_LVD_VDDOSC_ENABLE_U32       (PMC_CR_LVD_VDDOSC_ENABLE_MASK32)
    #define PMC_CR_LVD_VDDOSC_DISABLE_U32      ((uint32)0x00000000U)
    #define PMC_CR_LVD_VDD3p3_ENABLE_U32       (PMC_CR_LVD_VDD3p3_ENABLE_MASK32)
    #define PMC_CR_LVD_VDD3p3_DISABLE_U32      ((uint32)0x00000000U)
    #define PMC_CR_HVD_VDDPMC_ENABLE_U32       (PMC_CR_HVD_VDDPMC_ENABLE_MASK32)
    #define PMC_CR_HVD_VDDPMC_DISABLE_U32      ((uint32)0x00000000U)
    #define PMC_CR_LVD_VDDPMC_ENABLE_U32       (PMC_CR_LVD_VDDPMC_ENABLE_MASK32)
    #define PMC_CR_LVD_VDDPMC_DISABLE_U32      ((uint32)0x00000000U)
    #define PMC_CR_HVD_HPVDD_ENABLE_U32        (PMC_CR_HVD_HPVDD_ENABLE_MASK32)
    #define PMC_CR_HVD_HPVDD_DISABLE_U32       ((uint32)0x00000000U)
    #define PMC_CR_LVD_HPVDD_ENABLE_U32        (PMC_CR_LVD_HPVDD_ENABLE_MASK32)
    #define PMC_CR_LVD_HPVDD_DISABLE_U32       ((uint32)0x00000000U)

    /***              PMC_REE                         ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_CONFIG_U32(value)       (((value) & PMC_REE_RWBITS_MASK32))

    #define PMC_REE_LVD_VDDOSC_RST_EN_U32       (PMC_REE_LVD_VDDOSC_RST_EN_MASK32)
    #define PMC_REE_LVD_VDDOSC_RST_DIS_U32      ((uint32)0x00000000U)
    #define PMC_REE_LVD_VDD3p3_RST_EN_U32       (PMC_REE_LVD_VDD3p3_RST_EN_MASK32)
    #define PMC_REE_LVD_VDD3p3_RST_DIS_U32      ((uint32)0x00000000U)
    #define PMC_REE_HVD_VDDPMC_RST_EN_U32       (PMC_REE_HVD_VDDPMC_RST_EN_MASK32)
    #define PMC_REE_HVD_VDDPMC_RST_DIS_U32      ((uint32)0x00000000U)
    #define PMC_REE_LVD_VDDPMC_RST_EN_U32       (PMC_REE_LVD_VDDPMC_RST_EN_MASK32)
    #define PMC_REE_LVD_VDDPMC_RST_DIS_U32      ((uint32)0x00000000U)
    #define PMC_REE_HVD_HPVDD_RST_EN_U32        (PMC_REE_HVD_HPVDD_RST_EN_MASK32)
    #define PMC_REE_HVD_HPVDD_RST_DIS_U32       ((uint32)0x00000000U)
    #define PMC_REE_LVD_HPVDD_RST_EN_U32        (PMC_REE_LVD_HPVDD_RST_EN_MASK32)
    #define PMC_REE_LVD_HPVDD_RST_DIS_U32       ((uint32)0x00000000U)

    /***              PMC_FEE                         ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_CONFIG_U32(value)           (((value) & PMC_FEE_RWBITS_MASK32))

    #define PMC_FEE_LVD_VDDOSC_FAULT_EN_U32     (PMC_FEE_LVD_VDDOSC_FAULT_EN_MASK32)
    #define PMC_FEE_LVD_VDDOSC_FAULT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_FEE_LVD_VDD3p3_FAULT_EN_U32     (PMC_FEE_LVD_VDD3p3_FAULT_EN_MASK32)
    #define PMC_FEE_LVD_VDD3p3_FAULT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_FEE_HVD_VDDPMC_FAULT_EN_U32     (PMC_FEE_HVD_VDDPMC_FAULT_EN_MASK32)
    #define PMC_FEE_HVD_VDDPMC_FAULT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_FEE_LVD_VDDPMC_FAULT_EN_U32     (PMC_FEE_LVD_VDDPMC_FAULT_EN_MASK32)
    #define PMC_FEE_LVD_VDDPMC_FAULT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_FEE_HVD_HPVDD_FAULT_EN_U32      (PMC_FEE_HVD_HPVDD_FAULT_EN_MASK32)
    #define PMC_FEE_HVD_HPVDD_FAULT_DIS_U32     ((uint32)0x00000000U)
    #define PMC_FEE_LVD_HPVDD_FAULT_EN_U32      (PMC_FEE_LVD_HPVDD_FAULT_EN_MASK32)
    #define PMC_FEE_LVD_HPVDD_FAULT_DIS_U32     ((uint32)0x00000000U)

    /***              PMC_IEE                         ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_IEE_CONFIG_U32(value)           (((value) & PMC_IEE_RWBITS_MASK32))

    #define PMC_IEEE_LVD_VDDOSC_INT_EN_U32     (PMC_IEEE_LVD_VDDOSC_INT_EN_MASK32)
    #define PMC_IEEE_LVD_VDDOSC_INT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_IEEE_LVD_VDD3p3_INT_EN_U32     (PMC_IEEE_LVD_VDD3p3_INT_EN_MASK32)
    #define PMC_IEEE_LVD_VDD3p3_INT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_IEEE_HVD_VDDPMC_INT_EN_U32     (PMC_IEEE_HVD_VDDPMC_INT_EN_MASK32)
    #define PMC_IEEE_HVD_VDDPMC_INT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_IEEE_LVD_VDDPMC_INT_EN_U32     (PMC_IEEE_LVD_VDDPMC_INT_EN_MASK32)
    #define PMC_IEEE_LVD_VDDPMC_INT_DIS_U32    ((uint32)0x00000000U)
    #define PMC_IEEE_HVD_HPVDD_INT_EN_U32      (PMC_IEEE_HVD_HPVDD_INT_EN_MASK32)
    #define PMC_IEEE_HVD_HPVDD_INT_DIS_U32     ((uint32)0x00000000U)
    #define PMC_IEEE_LVD_HPVDD_INT_EN_U32      (PMC_IEEE_LVD_HPVDD_INT_EN_MASK32)
    #define PMC_IEEE_LVD_HPVDD_INT_DIS_U32     ((uint32)0x00000000U)
#endif

#if (IPV_PMC == IPV_PMC_00_00_00_15)

    /***              PMC_TS_IER              ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_TS_IER_CONFIG_U32(value)                (((value) & PMC_TS_IER_RWBITS_USR_MASK32) | PMC_TS_IER_RESBITS_MASK32)
                                                        
    #define PMC_TS_IER_TS1_2IE_ENA_U32                  (PMC_TS_IER_TS1_2IE_MASK32)
    #define PMC_TS_IER_TS1_2IE_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_TS_IER_TS1_0IE_ENA_U32                  (PMC_TS_IER_TS1_0IE_MASK32)
    #define PMC_TS_IER_TS1_0IE_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_TS_IER_TS0_2IE_ENA_U32                  (PMC_TS_IER_TS0_2IE_MASK32)
    #define PMC_TS_IER_TS0_2IE_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_TS_IER_TS0_0IE_ENA_U32                  (PMC_TS_IER_TS0_0IE_MASK32)
    #define PMC_TS_IER_TS0_0IE_DIS_U32                  ((uint32)0x00000000U)

    /***              PMC_REE_TD              ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_TD_CONFIG_U32(value)                (((value) & PMC_REE_TD_RWBITS_MASK32) | PMC_REE_TD_RESBITS_MASK32)

    #define PMC_REE_TD_TEMP1_2_ENA_U32                  (PMC_REE_TD_TEMP1_2_MASK32)
    #define PMC_REE_TD_TEMP1_2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP1_0_ENA_U32                  (PMC_REE_TD_TEMP1_0_MASK32)
    #define PMC_REE_TD_TEMP1_0_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP0_2_ENA_U32                  (PMC_REE_TD_TEMP0_2_MASK32)
    #define PMC_REE_TD_TEMP0_2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP0_0_ENA_U32                  (PMC_REE_TD_TEMP0_0_MASK32)
    #define PMC_REE_TD_TEMP0_0_DIS_U32                  ((uint32)0x00000000U)


    /***              PMC_RES_TD              ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_TD_CONFIG_U32(value)                (((value) & PMC_RES_TD_RWBITS_MASK32) | PMC_RES_TD_RESBITS_MASK32)

    #define PMC_RES_TD_TEMP1_2_NO_RESET_GENERATED_U32        (PMC_REE_TD_TEMP1_2_MASK32)
    #define PMC_RES_TD_TEMP1_2_POR_GENERATED_U32             ((uint32)0x00000000U)
    
    #define PMC_RES_TD_TEMP1_0_NO_RESET_GENERATED_U32        (PMC_REE_TD_TEMP1_0_MASK32)
    #define PMC_RES_TD_TEMP1_0_POR_GENERATED_U32             ((uint32)0x00000000U)
    
    #define PMC_RES_TD_TEMP0_2_NO_RESET_GENERATED_U32        (PMC_REE_TD_TEMP0_2_MASK32)
    #define PMC_RES_TD_TEMP0_2_POR_GENERATED_U32             ((uint32)0x00000000U)
    
    #define PMC_RES_TD_TEMP0_0_NO_RESET_GENERATED_U32        (PMC_REE_TD_TEMP0_0_MASK32)
    #define PMC_RES_TD_TEMP0_0_POR_GENERATED_U32             ((uint32)0x00000000U)

    /***              PMC_CTL_TD                      ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_CONFIG_U32(value)                (((value) & PMC_CTL_TD_RWBITS_MASK32) | PMC_CTL_TD_RESBITS_MASK32)
        
    #define PMC_CTL_TD_TS1_ENA_U32                      (PMC_CTL_TD_TS1_EN_MASK32)
    #define PMC_CTL_TD_TS1_DIS_U32                      ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0_ENA_U32                      (PMC_CTL_TD_TS0_EN_MASK32)
    #define PMC_CTL_TD_TS0_DIS_U32                      ((uint32)0x00000000U)
    
    /***              PMC_LVD_HVD_INTR_ENB              ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_LVD_HVD_INTR_ENB_U32(value)             (((value) & PMC_LVD_HVD_INTR_ENB_RWBITS_MASK32) | PMC_LVD_HVD_INTR_ENB_RESBITS_MASK32)
        
    #define PMC_LVD_HVD_INTR_ENB_WRITE_ENABLED_U32      (PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32)
    #define PMC_LVD_HVD_INTR_ENB_WRITE_DISABLED_U32     ((uint32)0x00000000U)
    
    #define PMC_HVD_FLASH_INT_ENABLED_U32               (PMC_LVD_HVD_INTR_ENB_HVD_FLASH_MASK32)
    #define PMC_HVD_FLASH_INT_DISABLED_U32              ((uint32)0x00000000U)
    
    #define PMC_HVD_HV_INT_ENABLED_U32                  (PMC_LVD_HVD_INTR_ENB_HVD_HV_MASK32)
    #define PMC_HVD_HV_INT_DISABLED_U32                 ((uint32)0x00000000U)
    
    #define PMC_HVD_CORE_INT_ENABLED_U32                (PMC_LVD_HVD_INTR_ENB_HVD_CORE_MASK32)
    #define PMC_HVD_CORE_INT_DISABLED_U32               ((uint32)0x00000000U)
    
    #define PMC_LVD_CORE_COLD_INT_ENABLED_U32           (PMC_LVD_HVD_INTR_ENB_LVD_CORE_COLD_MASK32)
    #define PMC_LVD_CORE_COLD_INT_DISABLED_U32          ((uint32)0x00000000U)

    /***              PMC_ADC_CS              ***/
    #define PMC_ADC_CS_ADC_CHANNEL_OFF_U32              ((uint32)0x00000000U)
    #define PMC_ADC_CS_POR098_SENSE_U32                 ((uint32)0x0000001CU)
    #define PMC_ADC_CS_POR098_REFERENCE_U32             ((uint32)0x0000001BU)
    #define PMC_ADC_CS_LVD_CORE_COLD_SENSE_U32          ((uint32)0x00000016U)
    #define PMC_ADC_CS_LVD_CORE_COLD_REFERENCE_U32      ((uint32)0x00000015U)
    #define PMC_ADC_CS_LVD_CORE_HOT_SENSE_U32           ((uint32)0x00000014U)
    #define PMC_ADC_CS_LVD_CORE_HOT_REFERENCE_U32       ((uint32)0x00000013U)
    #define PMC_ADC_CS_HVD_CORE_SENSE_U32               ((uint32)0x00000012U)
    #define PMC_ADC_CS_HVD_CORE_REFERENCE_U32           ((uint32)0x00000011U)
    #define PMC_ADC_CS_POR_HV_DIVIDER_TAP_U32           ((uint32)0x00000010U)
    #define PMC_ADC_CS_POR_HV_REFERENCE_U32             ((uint32)0x0000000FU)
    #define PMC_ADC_CS_LVD_HV_DIVIDER_TAP_U32           ((uint32)0x0000000CU)
    #define PMC_ADC_CS_LVD_HV_REFERENCE_U32             ((uint32)0x0000000BU)
    #define PMC_ADC_CS_HVD_HV_DIVIDER_TAP_U32           ((uint32)0x0000000AU)
    #define PMC_ADC_CS_HVD_HV_REFERENCE_U32             ((uint32)0x00000009U)
    #define PMC_ADC_CS_LVD_FLASH_DIVIDER_TAP_U32        ((uint32)0x00000008U)
    #define PMC_ADC_CS_LVD_FLASH_REFERENCE_U32          ((uint32)0x00000007U)
    #define PMC_ADC_CS_HVD_FLASH_DIVIDER_TAP_U32        ((uint32)0x00000006U)
    #define PMC_ADC_CS_HVD_FLASH_REFERENCE_U32          ((uint32)0x00000005U)
    #define PMC_ADC_CS_LVD_IO_DIVIDER_TAP_U32           ((uint32)0x00000004U)
    #define PMC_ADC_CS_LVD_IO_REFERENCE_U32             ((uint32)0x00000003U)
    
    /***              PMC_REE              ***/
    /** @violates @ref Mcu_PMC_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_U32(value)                            (((value) & PMC_REE_RWBITS_MASK32) | PMC_REE_RESBITS_MASK32)
    
    #define PMC_HVD_FLASH_RESET_ENABLED_U32               (PMC_REE_HVD_FLASH_MASK32)
    #define PMC_HVD_FLASH_RESET_DISABLED_U32              ((uint32)0x00000000U)
    
    #define PMC_HVD_HV_RESET_ENABLED_U32                  (PMC_REE_HVD_HV_MASK32)
    #define PMC_HVD_HV_RESET_DISABLED_U32                 ((uint32)0x00000000U)
    
    #define PMC_HVD_CORE_RESET_ENABLED_U32                (PMC_REE_HVD_CORE_MASK32)
    #define PMC_HVD_CORE_RESET_DISABLED_U32               ((uint32)0x00000000U)
    
    #define PMC_LVD_CORE_COLD_RESET_ENABLED_U32           (PMC_REE_LVD_CORE_COLD_MASK32)
    #define PMC_LVD_CORE_COLD_RESET_DISABLED_U32          ((uint32)0x00000000U)
    
    
    
#endif /* (IPV_PMC == IPV_PMC_01_00_02_05) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration for PMC.
* @details          The power control unit (PMC) acts as a bridge for mapping the PMC peripheral
 *                  to the PMC address space.
*/
typedef struct
{
#if (IPV_PMC == IPV_PMC_00_00_01_20)
    VAR( uint32, MCU_VAR) u32ControlConfig;          /**< @brief Control Register Register. PMC_CR register. */
    VAR( uint32, MCU_VAR) u32ResetEventEn;           /**< @brief Reset Event Enable Register. PMC_REE register. */
    VAR( uint32, MCU_VAR) u32FaultEventEn;           /**< @brief Fault Event Enable Register. PMC_FEE register. */
    VAR( uint32, MCU_VAR) u32InterruptEventEn;       /**< @brief Interrupt Enable Register. PMC_IEE register. */
#elif (IPV_PMC == IPV_PMC_00_00_00_15)               
    VAR( uint32, MCU_VAR) u32TempInterruptEn;   /**< @brief Temperature Sensor Interrupt Enable Register. PMC_TS_TS_IER register. */
    VAR( uint32, MCU_VAR) u32TempResEventEn;         /**< @brief Temperature reset event enable register. PMC_REE_TD register. */
    VAR( uint32, MCU_VAR) u32TempResEventSel;        /**< @brief Temperature reset event selection register. PMC_RES_TD register. */
    VAR( uint32, MCU_VAR) u32TempDetConfig;          /**< @brief Temperature detector configuration register. PMC_CTL_TD register. */
    VAR( uint32, MCU_VAR) u32LvdHvdInterruptConfig;  /**< @brief LVD/HVD Interrupt Enable Control Register. PMC_LVD_HVD_INTR_ENB register. */
    VAR( uint32, MCU_VAR) u32AdcChannelSelectConfig; /**< @brief ADC Channel Select Register. PMC_ADC_CS register. */
    VAR( uint32, MCU_VAR) u32ResetEventEnableConfig; /**< @brief Reset Event Enable Register. PMC_REE register. */
#elif (IPV_PMC == IPV_PMC_03_00_01_00)
    VAR( uint8, MCU_VAR) u8Lvdsc1;                   /**< @brief Trimming Register (PMC_LVDSC1). */
    VAR( uint8, MCU_VAR) u8Lvdsc2;                   /**< @brief Trimming Register (PMC_LVDSC2). */
    VAR( uint8, MCU_VAR) u8Regsc;                    /**< @brief Trimming Register (PMC_REGSC). */
    VAR( uint8, MCU_VAR) u8LpoTrim;                  /**< @brief Trimming Register (PMC_LPOTRIM). */
#elif (IPV_PMC == IPV_PMC_01_00_02_05)
    VAR( uint32, MCU_VAR) u32PowerCtrl;             /**< @brief Configuration Register (PMC_MCR). */
    VAR( uint32, MCU_VAR) u32PowerTrim;             /**< @brief Trimming Register (PMC_TRIMR). */
#endif
} Mcu_PMC_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_PMC_TYPES_H */

/** @} */
