/**
*   @file    Mcu_CMU_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPV_CMU.
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


#ifndef MCU_CMU_TYPES_H
#define MCU_CMU_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_CMU_Types_h_REF_1
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
#include "Soc_Ips.h"

#include "Reg_eSys_CMU.h"
#include "Mcu_CMU_IPVersion.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_CMU_TYPES_VENDOR_ID                    43
#define MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION     2
#define MCU_CMU_TYPES_AR_RELEASE_REVISION_VERSION  2
#define MCU_CMU_TYPES_SW_MAJOR_VERSION             1
#define MCU_CMU_TYPES_SW_MINOR_VERSION             0
#define MCU_CMU_TYPES_SW_PATCH_VERSION             1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_CMU_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_CMU_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CMU_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_CMU_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_CMU_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_CMU_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_CMU_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_CMU_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_CMU_Types.h and Soc_Ips.h are different"
    #endif
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_CMU_TYPES_VENDOR_ID != REG_ESYS_CMU_VENDOR_ID)
    #error "Mcu_CMU_Types.h and Reg_eSys_CMU.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_CMU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_CMU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CMU_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_CMU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_CMU_Types.h and Reg_eSys_CMU.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_CMU_TYPES_SW_MAJOR_VERSION != REG_ESYS_CMU_SW_MAJOR_VERSION) || \
     (MCU_CMU_TYPES_SW_MINOR_VERSION != REG_ESYS_CMU_SW_MINOR_VERSION) || \
     (MCU_CMU_TYPES_SW_PATCH_VERSION != REG_ESYS_CMU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_CMU_Types.h and Reg_eSys_CMU.h are different"
#endif

/* Check if current file and Mcu_CMU_IPVersion header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CMU_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CMU_IPVERSION_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_CMU.h and Mcu_CMU_IPVersion.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* various exported defines */

/* for CMU_CSR */

#if (IPV_CMU == IPV_CMU_00_00_00_01)
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)

#define CMU_GCR_CMU_ENA_U32              ((uint32)0x00000001U)
#define CMU_GCR_CMU_DIS_U32              ((uint32)0x00000000U)

#define CMU0_IER_FHH_ENA_U32             ((uint32)0x00000008U)
#define CMU0_IER_FHH_DIS_U32             ((uint32)0x00000000U)

#define CMU0_IER_FLL_ENA_U32             ((uint32)0x00000004U)
#define CMU0_IER_FLL_DIS_U32             ((uint32)0x00000000U)

#define CMU1_IER_FHH_ENA_U32             ((uint32)0x00000002U)
#define CMU1_IER_FHH_DIS_U32             ((uint32)0x00000000U)

#define CMU1_IER_FLL_ENA_U32             ((uint32)0x00000001U)
#define CMU1_IER_FLL_DIS_U32             ((uint32)0x00000000U)

/* for CMU_IER */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_IER_VALUE_U32(value)      ((uint32)( ((value) & CMU_IER_RWBITS_MASK32 ) | CMU_IER_RESBITS_MASK32))

/* for CMU_RCCR */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_RCCR_VALUE_U32(value)      ((uint32)( ((value) & CMU_RCCR_RWBITS_MASK32 ) | CMU_RCCR_RESBITS_MASK32))

/* for CMU_HTCR */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_HTCR_VALUE_U32(value)      ((uint32)( ((value) & CMU_HTCR_RWBITS_MASK32 ) | CMU_HTCR_RESBITS_MASK32))

/* for CMU_LTCR */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_LTCR_VALUE_U32(value)      ((uint32)( ((value) & CMU_LTCR_RWBITS_MASK32 ) | CMU_LTCR_RESBITS_MASK32))

#endif
#endif
#else

/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_CSR_U32(value)               ((uint32)( ((value) & CMU_CSR_RWBITS_MASK32) | CMU_CSR_RESBITS_MASK32))

#define CMU_CSR_SFM_ENA_U32              (CMU_CSR_SFM_MASK32)

#define CMU_CSR_CHKSEL_RMN_U32           (CMU_CSR_CHKSEL_MASK32)

#define CMU_CSR_RCDIV_1_U32              ((uint32)0x00000000U)
#define CMU_CSR_RCDIV_2_U32              ((uint32)0x00000002U)
#define CMU_CSR_RCDIV_4_U32              ((uint32)0x00000004U)
#define CMU_CSR_RCDIV_8_U32              ((uint32)0x00000006U)

#define CMU_CSR_CMU_ENA_U32              ((uint32)0x00000001U)
#define CMU_CSR_CMU_DIS_U32              ((uint32)0x00000000U)

/* for CMU_HFREFR */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_HFREFR_VALUE_U32(value)      ((uint32)( ((value) & CMU_HFREFR_RWBITS_MASK32 ) | CMU_HFREFR_RESBITS_MASK32))

/* for CMU_LFREFR */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_LFREFR_VALUE_U32(value)      ((uint32)( ((value) & CMU_LFREFR_RWBITS_MASK32 ) | CMU_LFREFR_RESBITS_MASK32))

/* for CMU_MDR */
/** @violates @ref Mcu_CMU_Types_h_REF_1 Function-like macro defined.*/
#define CMU_MDR_VALUE_U32(value)         ((uint32)( ((value) & CMU_MDR_RWBITS_MASK32 ) | CMU_MDR_RESBITS_MASK32))


/* for Mcu_CMU_SelfTest */
/* test types */
#define MCU_SELF_TEST_CMU_HIGHER_U8      ((uint8)0xAAU)
#define MCU_SELF_TEST_CMU_LOWER_U8       ((uint8)0x55U)
/* min / max values for low and high comparators: (xFREF/16) * (fCLKMT0_RMN /4). */
/* this values are chosen to ensure that only the requested type of event will be triggered */
/* minimum working freq. is higher than this */
#define MCU_SELF_TEST_XFER_MIN_U32       ((uint32)0x0000000FU)
/* max. working freq can not reach this */
#define MCU_SELF_TEST_XFER_MAX_U32       ((uint32)0x00000FFFU)

#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief   MC_CGM IP configuration.
* @details This structure contains information for IRCOSC, XOSC, PLL, Output Clocks, CMUs
*          The definitions for each Clock setting within the structure Mcu_ConfigType shall contain:
*          - MCU specific properties as, e.g., clock safety features and special clock distribution
*            settings
*          - PLL settings /start lock options
*          - Internal oscillator setting
*/

#if (IPV_CMU == IPV_CMU_00_00_00_01)
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
typedef struct
{
    /**< @brief CMU Interrupt register. */
    VAR (uint32, MCU_VAR) au32CmuInterrupt[MCU_CMU_UNITS];
    /**< @brief CMU count register. */
    VAR (uint32, MCU_VAR) au32CmuCount[MCU_CMU_UNITS];
    /**< @brief CMU High frequency reference value. */
    VAR (uint32, MCU_VAR) au32CmuHTCR[MCU_CMU_UNITS];
    /**< @brief CMU Low  frequency reference value. */
    VAR (uint32, MCU_VAR) au32CmuLTCR[MCU_CMU_UNITS];

} Mcu_CMU_ConfigType;
#endif
#endif
#else 
typedef struct
{
    /**< @brief CMU configuration register. */
    VAR (uint32, MCU_VAR) au32CmuConfig[MCU_CMU_UNITS];
    /**< @brief CMU High frequency reference value. */
    VAR (uint32, MCU_VAR) au32CmuHfRef[MCU_CMU_UNITS];
    /**< @brief CMU Low  frequency reference value. */
    VAR (uint32, MCU_VAR) au32CmuLfRef[MCU_CMU_UNITS];

} Mcu_CMU_ConfigType;
#endif

#endif /* MCU_INIT_CLOCK == STD_ON */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_CMU_TYPES_H */

/** @} */

