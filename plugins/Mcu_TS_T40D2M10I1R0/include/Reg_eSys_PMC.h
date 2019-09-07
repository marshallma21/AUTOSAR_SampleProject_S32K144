/**
*   @file    Reg_eSys_PMC.h
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


#ifndef REG_ESYS_PMC_H
#define REG_ESYS_PMC_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Reg_eSys_PMC_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Mcu_PMC_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_PMC_VENDOR_ID                       43
#define REG_ESYS_PMC_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_PMC_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_PMC_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_PMC_SW_MAJOR_VERSION                1
#define REG_ESYS_PMC_SW_MINOR_VERSION                0
#define REG_ESYS_PMC_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_PMC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_PMC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_PMC.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_PMC_IPVersion header file are from the same vendor */
#if (REG_ESYS_PMC_VENDOR_ID != MCU_PMC_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_PMC.h and Mcu_PMC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_PMC_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_PMC_AR_RELEASE_MAJOR_VERSION != MCU_PMC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_PMC_AR_RELEASE_MINOR_VERSION != MCU_PMC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_PMC_AR_RELEASE_REVISION_VERSION != MCU_PMC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_PMC.h and Mcu_PMC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_PMC_IPVersion header file are of the same Software version */
#if ((REG_ESYS_PMC_SW_MAJOR_VERSION != MCU_PMC_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_PMC_SW_MINOR_VERSION != MCU_PMC_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_PMC_SW_PATCH_VERSION != MCU_PMC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_PMC.h and Mcu_PMC_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/***************************************************************************************************/
/***                                        PMC Registers                                        ***/
/***************************************************************************************************/
#if (IPV_PMC == IPV_PMC_01_00_02_05)
    /* Configuration Register (PMC_MCR). */
    #define PMC_MCR_ADDR32                     ((uint32)(PMC_BASEADDR + (uint32)0x00000000U))
    /* Trimming Register (PMC_TRIMR). */
    #define PMC_TRIMR_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x00000004U))
    /* Status Register (PMC_SR). */
    #define PMC_SR_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x00000008U))
#endif

#if (IPV_PMC == IPV_PMC_03_00_01_00)
    /* PMC - Supply Status Register. */
    #define PMC_LVDSC1_ADDR8                   ((uint8)(PMC_BASEADDR + (uint8)0x00U))
    /* PMC - Control Register. */
    #define PMC_LVDSC2_ADDR8                   ((uint8)(PMC_BASEADDR + (uint8)0x01U))
    /* PMC - Regulator Status and Control Register. */
    #define PMC_REGSC_ADDR8                    ((uint8)(PMC_BASEADDR + (uint8)0x02U))
    /* PMC - Low Power Oscillator Trim Register 8 bits. */
    #define PMC_LPOTRIM_ADDR8                  ((uint8)(PMC_BASEADDR + (uint8)0x04U))
    /* PMC - Low Power Oscillator Trim Register 32 bits */
    #define PMC_LPOTRIM_ADDR32                 ((uint32)(PMC_BASEADDR + (uint32)0x00000004U))    
#endif

#if (IPV_PMC == IPV_PMC_00_00_01_20)

    /* PMC - Supply Status Register. */
    #define PMC_SSR_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x00000000U))
    /* PMC - Control Register. */
    #define PMC_CR_ADDR32                       ((uint32)(PMC_BASEADDR + (uint32)0x00000004U))
    /* PMC - Reset Event Enable. */
    #define PMC_REE_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x00000008U))
    /* PMC - Fault Event Enable. */
    #define PMC_FEE_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x0000000CU))
    /* PMC - Interrupt Event Enable. */
    #define PMC_IEE_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x00000010U))
#endif

#if (IPV_PMC == IPV_PMC_00_00_00_15)

    /* PMC - Interrupt Enable Register. */
    #define PMC_TS_IER_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x00000088U))
    /* PMC - Temperature Event Status Register. */
    #define PMC_ESR_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x0000008CU))
    /* PMC - Temperature Reset Event Enable Register. */
    #define PMC_REE_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x00000090U))
    /* PMC - Temperature Reset Event Selection Register. */
    #define PMC_RES_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x00000094U))
    /* PMC - Temperature Detector Configuration Register. */
    #define PMC_CTL_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x00000098U))
    /* PMC - Temperature Sensor Fault Injection Register. */
    #define PMC_TS_FIR_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x000000A4U))
    /* PMC - Voltage Detect User Mode Test Register. */
    #define PMC_SELF_TEST_UM_VD_REG_ADDR32      ((uint32)(PMC_BASEADDR + (uint32)0x000000B4U))
    /* PMC - FCCU Fault Injection Register. */
    #define PMC_FIR_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x000000B8U))
    /* PMC - LVD/HVD Interrupt Enable Control Register. */
    #define PMC_LVD_HVD_INTR_ENB_ADDR32         ((uint32)(PMC_BASEADDR + (uint32)0x000000BCU))
    /* PMC - LVD/HVD Event Status Register. */
    #define PMC_LVD_HVD_EVENT_STATUS_ADDR32     ((uint32)(PMC_BASEADDR + (uint32)0x000000C0U))
    /* PMC - ADC Channel Select Register. */
    #define PMC_ADC_CS_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x000000C4U))
    /* PMC - LVD/HVD Event Status Register. */
    #define PMC_REE_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x000000D0U))
#endif


/***************************************************************************************************/
/***                                        PMC BitFields                                        ***/
/***************************************************************************************************/

#if (IPV_PMC == IPV_PMC_01_00_02_05)

    /***                  PMC_MCR              ***/
    #define PMC_MCR_RWBITS_MASK32                   ((uint32)0xFCFD0000U)
    #define PMC_MCR_RESBITS_MASK32                  ((uint32)0x00000000U)

    #define PMC_MCR_LVRER_MASK32                    ((uint32)0x80000000U)
    #define PMC_MCR_LVREH_MASK32                    ((uint32)0x40000000U)
    #define PMC_MCR_LVRE50_MASK32                   ((uint32)0x20000000U)
    #define PMC_MCR_LVRE33_MASK32                   ((uint32)0x10000000U)
    #define PMC_MCR_LVREC_MASK32                    ((uint32)0x08000000U)
    #define PMC_MCR_LVREA_MASK32                    ((uint32)0x04000000U)
    #define PMC_MCR_LVIER_MASK32                    ((uint32)0x00800000U)
    #define PMC_MCR_LVIEH_MASK32                    ((uint32)0x00400000U)
    #define PMC_MCR_LVIE50_MASK32                   ((uint32)0x00200000U)
    #define PMC_MCR_LVIE33_MASK32                   ((uint32)0x00100000U)
    #define PMC_MCR_LVIEC_MASK32                    ((uint32)0x00080000U)
    #define PMC_MCR_LVIEA_MASK32                    ((uint32)0x00040000U)
    #define PMC_MCR_TLK_MASK32                      ((uint32)0x00010000U)

    #define PMC_MCR_LVIE_MASK32                     ((uint32)0x00FC0000U)


    /***                 PMC_TRIMR              ***/
    #define PMC_TRIMR_RWBITS_MASK32                 ((uint32)0x00FFFFFFU)
    #define PMC_TRIMR_RESBITS_MASK32                ((uint32)0x00000000U)

    #define PMC_TRIMR_LVDATRIM_MASK32               ((uint32)0x00F00000U)
    #define PMC_TRIMR_LVDREGTRIM_MASK32             ((uint32)0x000F0000U)
    #define PMC_TRIMR_VDD33TRIM_MASK32              ((uint32)0x0000F000U)
    #define PMC_TRIMR_LVD33TRIM_MASK32              ((uint32)0x00000F00U)
    #define PMC_TRIMR_VDDCTRIM_MASK32               ((uint32)0x000000F0U)
    #define PMC_TRIMR_LVDCTRIM_MASK32               ((uint32)0x0000000FU)

    #define PMC_TRIMR_LVDATRIM_SHIFT32              ((uint32)0x00000014U)
    #define PMC_TRIMR_LVDREGTRIM_SHIFT32            ((uint32)0x00000010U)
    #define PMC_TRIMR_VDD33TRIM_SHIFT32             ((uint32)0x0000000CU)
    #define PMC_TRIMR_LVD33TRIM_SHIFT32             ((uint32)0x00000008U)
    #define PMC_TRIMR_VDDCTRIM_SHIFT32              ((uint32)0x00000004U)
    #define PMC_TRIMR_LVDCTRIM_SHIFT32              ((uint32)0x00000000U)


    /***                  PMC_SR              ***/
    #define PMC_SR_RWBITS_MASK32                    ((uint32)0x0004FC00U)
    #define PMC_SR_RESBITS_MASK32                   ((uint32)0x02000000U)

    #define PMC_SR_LVFSTBY_MASK32                   ((uint32)0x80000000U)
    #define PMC_SR_BGRDY_MASK32                     ((uint32)0x40000000U)
    #define PMC_SR_BGTS_MASK32                      ((uint32)0x20000000U)
    #define PMC_SR_LVFCSTBY_MASK32                  ((uint32)0x10000000U)
    #define PMC_SR_LVFCR_MASK32                     ((uint32)0x08000000U)
    #define PMC_SR_LVFCH_MASK32                     ((uint32)0x04000000U)
    #define PMC_SR_LVFC50_MASK32                    ((uint32)0x00000000U)
    #define PMC_SR_LVFC33_MASK32                    ((uint32)0x00000000U)
    #define PMC_SR_LVFCC_MASK32                     ((uint32)0x00000000U)
    #define PMC_SR_LVFCA_MASK32                     ((uint32)0x00000000U)
    #define PMC_SR_LVFR_MASK32                      ((uint32)0x00000000U)
    #define PMC_SR_LVFH_MASK32                      ((uint32)0x00000000U)
    #define PMC_SR_LVF50_MASK32                     ((uint32)0x00000000U)
    #define PMC_SR_LVF33_MASK32                     ((uint32)0x00000000U)
    #define PMC_SR_LVFC_MASK32                      ((uint32)0x00000000U)
    #define PMC_SR_LVFA_MASK32                      ((uint32)0x00000000U)

    #define PMC_SR_LVIS_MASK32                      (PMC_SR_RWBITS_MASK32)

#endif /* (IPV_PMC == IPV_PMC_01_00_02_05) */

#if (IPV_PMC == IPV_PMC_03_00_01_00)

    #define PMC_LVDSC1_LVD_ENABLE_U8           ((uint8)(0x20))
    #define PMC_LVDSC1_LVD_DISABLE_U8          ((uint8)(0x00))

    #define PMC_LVDSC1_LVDRE_ENABLE_U8         ((uint8)(0x10))
    #define PMC_LVDSC1_LVDRE_DISABLE_U8        ((uint8)(0x00))

    #define PMC_LVDSC2_LVW_ENABLE_U8           ((uint8)(0x20))
    #define PMC_LVDSC2_LVW_DISABLE_U8          ((uint8)(0x00))

    #define PMC_LVDSC1_LVDIE_MASK8             (PMC_LVDSC1_LVD_ENABLE_U8)
    #define PMC_LVDSC1_LVDF_MASK8              ((uint8)(0x80))
    #define PMC_LVDSC1_LVDACK_MASK8            ((uint8)(0x40))

    #define PMC_REG_RWBITS_MASK32              ((uint32)(0x1F832030))

    #define PMC_LVDSC1_LVDSC2_RWBITS_MASK32    ((uint32)(0x30200000))

    #define PMC_REGSC_LPO_ENABLE_U8            ((uint8)(0x00))
    #define PMC_REGSC_LPO_DISABLE_U8           ((uint8)(0x80))

    #define PMC_REGSC_BIAS_ENABLE_U8           ((uint8)(0x01))
    #define PMC_REGSC_BIAS_DISABLE_U8          ((uint8)(0x00))

    #define PMC_REGSC_CLKBIAS_DISABLE_U8       ((uint8)(0x02))
    #define PMC_REGSC_CLKBIAS_ENABLE_U8        ((uint8)(0x00))
    
    #define PMC_REGSC_LPOSTAT_MASK8            ((uint8)(0x40))
    #define PMC_REGSC_REGFPM_MASK8             ((uint8)(0x04))

    #define PMC_LPOTRIM_RWBITS_MASK8           ((uint8)(0x1F))
    /** @violates @ref Reg_eSys_PMC_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
    #define PMC_LPOTRIM_LPOTRIM_U8(value)      ((uint8)((uint8)(value) & PMC_LPOTRIM_RWBITS_MASK8))
#endif /* (IPV_PMC == IPV_PMC_03_00_01_00) */

#if (IPV_PMC == IPV_PMC_00_00_01_20)

    /***              PMC_SSR              ***/
    #define PMC_SSR_RWBITS_MASK32               ((uint32)0x0000007FU)
    #define PMC_SSR_LVD_VDDOSC_MASK32           ((uint32)0x00000040U)
    #define PMC_SSR_LVD_VDD3p3_MASK32           ((uint32)0x00000020U)
    #define PMC_SSR_HVD_VDDPMC_MASK32           ((uint32)0x00000010U)
    #define PMC_SSR_LVD_VDDPMC_MASK32           ((uint32)0x00000008U)
    #define PMC_SSR_HVD_HPVDD_MASK32            ((uint32)0x00000004U)
    #define PMC_SSR_LVD_HPVDD_MASK32            ((uint32)0x00000002U)
    #define PMC_SSR_POR_MASK32                  ((uint32)0x00000001U)

    /***              PMC_CR              ***/
    #define PMC_CR_RWBITS_MASK32                ((uint32)0x8000003FU)
    #define PMC_CR_VM_PMC_ENABLE_MASK32         ((uint32)0x80000000U)
    #define PMC_CR_LVD_VDDOSC_ENABLE_MASK32     ((uint32)0x00000020U)
    #define PMC_CR_LVD_VDD3p3_ENABLE_MASK32     ((uint32)0x00000010U)
    #define PMC_CR_HVD_VDDPMC_ENABLE_MASK32     ((uint32)0x00000008U)
    #define PMC_CR_LVD_VDDPMC_ENABLE_MASK32     ((uint32)0x00000004U)
    #define PMC_CR_HVD_HPVDD_ENABLE_MASK32      ((uint32)0x00000002U)
    #define PMC_CR_LVD_HPVDD_ENABLE_MASK32      ((uint32)0x00000001U)


    /***              PMC_REE              ***/
    #define PMC_REE_RWBITS_MASK32                ((uint32)0x8000003FU)
    
    #define PMC_REE_VM_PMC_RST_EN_MASK32         ((uint32)0x80000000U)
    #define PMC_REE_LVD_VDDOSC_RST_EN_MASK32     ((uint32)0x00000020U)
    #define PMC_REE_LVD_VDD3p3_RST_EN_MASK32     ((uint32)0x00000010U)
    #define PMC_REE_HVD_VDDPMC_RST_EN_MASK32     ((uint32)0x00000008U)
    #define PMC_REE_LVD_VDDPMC_RST_EN_MASK32     ((uint32)0x00000004U)
    #define PMC_REE_HVD_HPVDD_RST_EN_MASK32      ((uint32)0x00000002U)
    #define PMC_REE_LVD_HPVDD_RST_EN_MASK32      ((uint32)0x00000001U)
    
    /***              PMC_FEE              ***/
    #define PMC_FEE_RWBITS_MASK32                  ((uint32)0x0000003FU)
    #define PMC_FEE_LVD_VDDOSC_FAULT_EN_MASK32     ((uint32)0x00000020U)
    #define PMC_FEE_LVD_VDD3p3_FAULT_EN_MASK32     ((uint32)0x00000010U)
    #define PMC_FEE_HVD_VDDPMC_FAULT_EN_MASK32     ((uint32)0x00000008U)
    #define PMC_FEE_LVD_VDDPMC_FAULT_EN_MASK32     ((uint32)0x00000004U)
    #define PMC_FEE_HVD_HPVDD_FAULT_EN_MASK32      ((uint32)0x00000002U)
    #define PMC_FEE_LVD_HPVDD_FAULT_EN_MASK32      ((uint32)0x00000001U)
        
    /***              PMC_IEE              ***/
    #define PMC_IEE_RWBITS_MASK32                ((uint32)0x0000003FU)
    #define PMC_IEE_LVD_VDDOSC_INT_EN_MASK32     ((uint32)0x00000020U)
    #define PMC_IEE_LVD_VDD3p3_INT_EN_MASK32     ((uint32)0x00000010U)
    #define PMC_IEE_HVD_VDDPMC_INT_EN_MASK32     ((uint32)0x00000008U)
    #define PMC_IEE_LVD_VDDPMC_INT_EN_MASK32     ((uint32)0x00000004U)
    #define PMC_IEE_HVD_HPVDD_INT_EN_MASK32      ((uint32)0x00000002U)
    #define PMC_IEE_LVD_HPVDD_INT_EN_MASK32      ((uint32)0x00000001U)
#endif

#if (IPV_PMC == IPV_PMC_00_00_00_15)

    /***              PMC_TS_IER              ***/
    #define PMC_TS_IER_RWBITS_MASK32                    ((uint32)0x8000001BU)
    #define PMC_TS_IER_RWBITS_USR_MASK32                ((uint32)0x0000001BU)
                                                        
    #define PMC_TS_IER_RESBITS_MASK32                   ((uint32)0x00000000U)
                                                        
    #define PMC_TS_IER_TS_EN_MASK32                     ((uint32)0x80000000U)
    #define PMC_TS_IER_TS1_2IE_MASK32                   ((uint32)0x00000010U)
    #define PMC_TS_IER_TS1_0IE_MASK32                   ((uint32)0x00000008U)
    #define PMC_TS_IER_TS0_2IE_MASK32                   ((uint32)0x00000002U)
    #define PMC_TS_IER_TS0_0IE_MASK32                   ((uint32)0x00000001U)

    /***              PMC_ESR_TD              ***/
    #define PMC_ESR_TD_RWBITS_MASK32                    ((uint32)0x0000001BU)
    #define PMC_ESR_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_ESR_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_ESR_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_ESR_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_ESR_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /***              PMC_REE_TD              ***/
    #define PMC_REE_TD_RWBITS_MASK32                    ((uint32)0x0000001BU)
    #define PMC_REE_TD_RESBITS_MASK32                   ((uint32)0x00000024U)

    #define PMC_REE_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_REE_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_REE_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_REE_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /***              PMC_RES_TD              ***/
    #define PMC_RES_TD_RWBITS_MASK32                    ((uint32)0x0000001BU)
    #define PMC_RES_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_RES_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_RES_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_RES_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_RES_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /***              PMC_CTL_TD              ***/
    #define PMC_CTL_TD_RWBITS_MASK32                    ((uint32)0x00000101U)
    #define PMC_CTL_TD_RESBITS_MASK32                   ((uint32)0x00000202U)

    #define PMC_CTL_TD_TS1_EN_MASK32                    ((uint32)0x00000100U)
    #define PMC_CTL_TD_TS0_EN_MASK32                    ((uint32)0x00000001U)

    /***             PMC_TS_FIR              ***/
    #define PMC_TS_FIR_TSNS_FAULT_MASK32                ((uint32)0x00000001U)

    /***         PMC_SELF_TEST_UM_VD_REG              ***/
    #define PMC_SELF_TEST_UM_VD_REG_RWBITS_MASK32       ((uint32)0x000200FFU)
    #define PMC_SELF_TEST_UM_VD_REG_RESBITS_MASK32      ((uint32)0x00000000U)

    #define PMC_SELF_TEST_UM_VD_REG_ST_RESULT_MASK32    ((uint32)0x00020000U)
    #define PMC_SELF_TEST_UM_VD_REG_ST_DONE_MASK32      ((uint32)0x00010000U)
    #define PMC_SELF_TEST_UM_VD_REG_ST_MODE_MASK32      ((uint32)0x000000C0U)
    #define PMC_SELF_TEST_UM_VD_REG_VD_ST_CTRL_MASK32   ((uint32)0x0000003FU)
        
    /***              PMC_FIR              ***/
    #define PMC_FIR_STEST_FAULT_MASK32                  ((uint32)0x00000008U)
    #define PMC_FIR_HVD_FAULT_MASK32                    ((uint32)0x00000002U)
    #define PMC_FIR_LVD_FAULT_MASK32                    ((uint32)0x00000001U)

    /***            PMC_LVD_HVD_INTR_ENB              ***/
    #define PMC_LVD_HVD_INTR_ENB_RWBITS_MASK32          ((uint32)0x8000002DU)
    #define PMC_LVD_HVD_INTR_ENB_RWBITS_USR_MASK32      ((uint32)0x0000002DU)
    #define PMC_LVD_HVD_INTR_ENB_RESBITS_MASK32         ((uint32)0x00000000U)

    #define PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32      ((uint32)0x80000000U)
    #define PMC_LVD_HVD_INTR_ENB_HVD_FLASH_MASK32       ((uint32)0x00000020U)
    #define PMC_LVD_HVD_INTR_ENB_HVD_HV_MASK32          ((uint32)0x00000008U)
    #define PMC_LVD_HVD_INTR_ENB_HVD_CORE_MASK32        ((uint32)0x00000004U)
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_COLD_MASK32   ((uint32)0x00000001U)

    /***          PMC_LVD_HVD_EVENT_STATUS              ***/
    #define PMC_LVD_HVD_EVENT_STATUS_RWBITS_MASK32      ((uint32)0x0000002DU)
    #define PMC_LVD_HVD_EVENT_STATUS_RESBITS_MASK32     ((uint32)0x00000000U)

    #define PMC_LVD_HVD_EVENT_HVD_FLASH_MASK32          ((uint32)0x00000020U)
    #define PMC_LVD_HVD_EVENT_HVD_HV_MASK32             ((uint32)0x00000008U)
    #define PMC_LVD_HVD_EVENT_HVD_CORE_MASK32           ((uint32)0x00000004U)
    #define PMC_LVD_HVD_EVENT_LVD_CORE_COLD_MASK32      ((uint32)0x00000001U)

    /***                   PMC_ADC_CS              ***/
    #define PMC_ADC_CS_RWBITS_MASK32                    ((uint32)0x0000033FU)
    #define PMC_ADC_CS_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_ADC_CS_STND_BY_RAM_BO_CLR_MASK32        ((uint32)0x00000200U)
    #define PMC_ADC_CS_STND_BY_RAM_BR_DETCT_MASK32      ((uint32)0x00000100U)
    #define PMC_ADC_CS_ADC_CS_MASK32                    ((uint32)0x0000003FU)

    /***              PMC_REE              ***/
    #define PMC_REE_RWBITS_MASK32                       ((uint32)0x0000002DU)
    #define PMC_REE_RESBITS_MASK32                      ((uint32)0x000000D2U)
                                                        
    #define PMC_REE_HVD_FLASH_MASK32                    ((uint32)0x00000020U)
    #define PMC_REE_HVD_HV_MASK32                       ((uint32)0x00000008U)
    #define PMC_REE_HVD_CORE_MASK32                     ((uint32)0x00000004U)
    #define PMC_REE_LVD_CORE_COLD_MASK32                ((uint32)0x00000001U)
#endif


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

#endif /* REG_ESYS_PMC_H */

/** @} */
