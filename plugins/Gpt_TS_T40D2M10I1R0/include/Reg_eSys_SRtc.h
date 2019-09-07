/**
*   @file    Reg_eSys_SRtc.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - SRTC driver header file.
*   @details SRTC module register description.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
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

#ifndef REG_ESYS_SRTC_H
#define REG_ESYS_SRTC_H

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
* @section REG_ESYS_SRTC_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.

* @section REG_ESYS_SRTC_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section REG_ESYS_SRTC_H_REF_3
* Violates MISRA 2004 Required Rule 8.12, Array size not defined
* This violation is  due to the fact that this file is shared by multiple drivers: GPT, PWM and ICU.
* The array size depends by the number of eTimer modules used by all drivers. The eTimer common component
* driver doesn't have yet its own plugin which could be used to generate the common parameters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_SRtc.h
*/
#define REG_ESYS_SRTC_VENDOR_ID                       43
#define REG_ESYS_SRTC_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_SRTC_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_SRTC_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_SRTC_SW_MAJOR_VERSION                1
#define REG_ESYS_SRTC_SW_MINOR_VERSION                0
#define REG_ESYS_SRTC_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_SRTC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_SRTC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_SRtc.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* SRTC Registers */
#define SRTC_TSR_ADDR32                         (RTC_BASEADDR + (uint32)0x00UL)
#define SRTC_TPR_ADDR32                         (RTC_BASEADDR + (uint32)0x04UL)
#define SRTC_TAR_ADDR32                         (RTC_BASEADDR + (uint32)0x08UL)
#define SRTC_TCR_ADDR32                         (RTC_BASEADDR + (uint32)0x0CUL)
#define SRTC_CR_ADDR32                          (RTC_BASEADDR + (uint32)0x10UL)
#define SRTC_SR_ADDR32                          (RTC_BASEADDR + (uint32)0x14UL)
#define SRTC_LR_ADDR32                          (RTC_BASEADDR + (uint32)0x18UL)
#define SRTC_IER_ADDR32                         (RTC_BASEADDR + (uint32)0x1CUL)
#define SRTC_WAR_ADDR32                         (RTC_BASEADDR + (uint32)0x0800UL)
#define SRTC_RAR_ADDR32                         (RTC_BASEADDR + (uint32)0x0804UL)
/**
 * @{
 * @brief Bit mask for SRTC Time Compensation Register
 */
#define SRTC_TCR_CIC_MASK_U32                   ((uint32)(BIT31|BIT30|BIT29|BIT28|BIT27|BIT26|BIT25|BIT24))
#define SRTC_TCR_CIC_SHIFT                      ((uint32)(24U))
#define SRTC_TCR_TCV_MASK_U32                   ((uint32)(BIT23|BIT22|BIT21|BIT20|BIT19|BIT18|BIT17|BIT16))
#define SRTC_TCR_TCV_SHIFT                      ((uint32)(16U))
#define SRTC_TCR_CIR_MASK_U32                   ((uint32)(BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8))
#define SRTC_TCR_CIR_SHIFT                      ((uint32)(8U))
#define SRTC_TCR_TCR_MASK_U32                   ((uint32)(BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))

/**
 * @{
 * @brief Bit mask for SRTC Control Register
 */
#define SRTC_CR_CPE_U32                         ((uint32)(BIT25|BIT24))
#define SRTC_CR_CPE_SHIFT                       ((uint32)(24U))
#define SRTC_CR_SC2P_U32                        ((uint32)(BIT13))
#define SRTC_CR_SC2P_SHIFT                      ((uint32)(13U))
#define SRTC_CR_SC4P_U32                        ((uint32)(BIT12))
#define SRTC_CR_SC4P_SHIFT                      ((uint32)(12U))
#define SRTC_CR_SC8P_U32                        ((uint32)(BIT11))
#define SRTC_CR_SC8P_SHIFT                      ((uint32)(11U))
#define SRTC_CR_SC16P_U32                       ((uint32)(BIT10))
#define SRTC_CR_SC16P_SHIFT                     ((uint32)(10U))
#define SRTC_CR_CLKO_U32                        ((uint32)(BIT9))
#define SRTC_CR_CLKO_SHIFT                      ((uint32)(9U))
#define SRTC_CR_OSCE_U32                        ((uint32)(BIT8))
#define SRTC_CR_OSCE_SHIFT                      ((uint32)(8U))
#define SRTC_CR_LPOS_U32                        ((uint32)(BIT7))
#define SRTC_CR_LPOS_SHIFT                      ((uint32)(7U))
#define SRTC_CR_CPS_U32                         ((uint32)(BIT5))
#define SRTC_CR_CPS_SHIFT                       ((uint32)(5U))
#define SRTC_CR_WPS_U32                         ((uint32)(BIT4))
#define SRTC_CR_WPS_SHIFT                       ((uint32)(4U))
#define SRTC_CR_UM_U32                          ((uint32)(BIT3))
#define SRTC_CR_UM_SHIFT                        ((uint32)(3U))
#define SRTC_CR_SUP_U32                         ((uint32)(BIT2))
#define SRTC_CR_SUP_SHIFT                       ((uint32)(2U))
#define SRTC_CR_WPE_U32                         ((uint32)(BIT1))
#define SRTC_CR_WPE_SHIFT                       ((uint32)(1U))
#define SRTC_CR_SWR_U32                         ((uint32)(BIT0))

/**
 * @{
 * @brief Bit mask for SRTC Status Register
 */
#define SRTC_SR_TCE_U32                         ((uint32)(BIT4))
#define SRTC_SR_TCE_SHIFT                       ((uint32)(4U))
#define SRTC_SR_TAF_U32                         ((uint32)(BIT2))
#define SRTC_SR_TAF_SHIFT                       ((uint32)(2U))
#define SRTC_SR_TOF_U32                         ((uint32)(BIT1))
#define SRTC_SR_TOF_SHIFT                       ((uint32)(1U))
#define SRTC_SR_TIF_U32                         ((uint32)(BIT0))

/**
 * @{
 * @brief Bit mask for SRTC Status Register
 */
#define SRTC_LR_LRL_U32                         ((uint32)(BIT6))
#define SRTC_LR_LRL_SHIFT                       ((uint32)(6U))
#define SRTC_LR_SRL_U32                         ((uint32)(BIT5))
#define SRTC_LR_SRL_SHIFT                       ((uint32)(5U))
#define SRTC_LR_CRL_U32                         ((uint32)(BIT4))
#define SRTC_LR_CRL_SHIFT                       ((uint32)(4U))
#define SRTC_LR_TCL_U32                         ((uint32)(BIT3))
#define SRTC_LR_TCL_SHIFT                       ((uint32)(3U))

/**
 * @{
 * @brief Bit mask for SRTC Interrupt Enable Register
 */
#define SRTC_IER_TSIC_U32                       ((uint32)(BIT18|BIT17|BIT16))
#define SRTC_IER_TSIC_SHIFT                     ((uint32)(16U))
#define SRTC_IER_WPON_U32                       ((uint32)(BIT7))
#define SRTC_IER_WPON_SHIFT                     ((uint32)(7U))
#define SRTC_IER_TSIE_U32                       ((uint32)(BIT4))
#define SRTC_IER_TSIE_SHIFT                     ((uint32)(4U))
#define SRTC_IER_TAIE_U32                       ((uint32)(BIT2))
#define SRTC_IER_TAIE_SHIFT                     ((uint32)(2U))
#define SRTC_IER_TOIE_U32                       ((uint32)(BIT1))
#define SRTC_IER_TOIE_SHIFT                     ((uint32)(1U))
#define SRTC_IER_TIIE_U32                       ((uint32)(BIT0))

/**
 * @{
 * @brief Bit mask for SRTC Write Access Register
 */
#define SRTC_WAR_IERW_U32                       ((uint32)(BIT7))
#define SRTC_WAR_IERW_SHIFT                     ((uint32)(7U))
#define SRTC_WAR_LRW_U32                        ((uint32)(BIT6))
#define SRTC_WAR_LRW_SHIFT                      ((uint32)(6U))
#define SRTC_WAR_SRW_U32                        ((uint32)(BIT5))
#define SRTC_WAR_SRW_SHIFT                      ((uint32)(5U))
#define SRTC_WAR_CRW_U32                        ((uint32)(BIT4))
#define SRTC_WAR_CRW_SHIFT                      ((uint32)(4U))
#define SRTC_WAR_TCRW_U32                       ((uint32)(BIT3))
#define SRTC_WAR_TCRW_SHIFT                     ((uint32)(3U))
#define SRTC_WAR_TARW_U32                       ((uint32)(BIT2))
#define SRTC_WAR_TARW_SHIFT                     ((uint32)(2U))
#define SRTC_WAR_TPRW_U32                       ((uint32)(BIT1))
#define SRTC_WAR_TPRW_SHIFT                     ((uint32)(1U))
#define SRTC_WAR_TSRW_U32                       ((uint32)(BIT0))

/**
 * @{
 * @brief Bit mask for SRTC Read Access Register
 */
#define SRTC_RAR_IERR_U32                       ((uint32)(BIT7))
#define SRTC_RAR_IERR_SHIFT                     ((uint32)(7U))
#define SRTC_RAR_LRR_U32                        ((uint32)(BIT6))
#define SRTC_RAR_LRR_SHIFT                      ((uint32)(6U))
#define SRTC_RAR_SRR_U32                        ((uint32)(BIT5))
#define SRTC_RAR_SRR_SHIFT                      ((uint32)(5U))
#define SRTC_RAR_CRR_U32                        ((uint32)(BIT4))
#define SRTC_RAR_CRR_SHIFT                      ((uint32)(4U))
#define SRTC_RAR_TCRR_U32                       ((uint32)(BIT3))
#define SRTC_RAR_TCRR_SHIFT                     ((uint32)(3U))
#define SRTC_RAR_TARR_U32                       ((uint32)(BIT2))
#define SRTC_RAR_TARR_SHIFT                     ((uint32)(2U))
#define SRTC_RAR_TPRR_U32                       ((uint32)(BIT1))
#define SRTC_RAR_TPRR_SHIFT                     ((uint32)(1U))
#define SRTC_RAR_TSRR_U32                       ((uint32)(BIT0))
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_SRTC_H*/

/** @} */
