/**
*     @file Icu_Ipw_Types.h
*     @version 1.0.1
* 
*     @brief   AUTOSAR Icu - Brief description.
*     @details Detailed description.
*     
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform ARM
*     Peripheral FTM PORT_CI LPIT LPTMR
*     Dependencies none
* 
*     Autosar Version 4.2.2
*     Autosar Revision ASR_REL_4_2_REV_0002
*     Autosar ConfVariant
*     SWVersion 1.0.1
*     BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
* 
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_IPW_TYPES_H
#define ICU_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_IPW_Types_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* @section Icu_IPW_Types_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to IP functions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Icu_IPW_Types_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "StdRegMacros.h"
#include "Icu_Types.h"
#include "Icu_Ftm_Types.h"
#include "Icu_Port_Ci_Types.h"
#include "Icu_LPit_Types.h" 
#include "Icu_Lptmr_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_TYPES_VENDOR_ID                       43

#define ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2
#define ICU_IPW_TYPES_SW_MAJOR_VERSION                1
#define ICU_IPW_TYPES_SW_MINOR_VERSION                0
#define ICU_IPW_TYPES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Ipw_Types.h and StdRegMacros.h are different"
    #endif
#endif

/* Check if Icu_Ipw header and Icu_Types header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Types header file are of the same Autosar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_Types.h are different"
#endif
/* Check if header file and Icu_Types header file are of the same software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw_Types.h and Icu_Types.h are different"
#endif

/* Check if Icu_Ipw_Types file and Icu_Ftm_Types header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_FTM_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_Ftm_Types.h have different vendor IDs"
#endif
/*  Check if Icu_Ipw_Types file and Icu_Ftm_Types header file are of the same AutoSar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ICU_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_Ftm_Types.h are different"
#endif
/*  Check if Icu_Ipw_Types.h file and Icu_Ftm_Types header file are of the same Software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_FTM_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_FTM_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_FTM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw_Types.h and Icu_Ftm_Types.h are different"
#endif

/* Check if Icu_Ipw_Types header and Icu_Port_Ci_Types file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_PORT_CI_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_Port_Ci_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Port_Ci_Types file are of the same Autosar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_PORT_CI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ICU_PORT_CI_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_PORT_CI_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_Port_Ci_Types.h are different"
#endif
/* Check if header file and Icu_Port_Ci_Types file are of the same software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_PORT_CI_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_PORT_CI_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_PORT_CI_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw_Types.h and Icu_Port_Ci_Types.h are different"
#endif

/* Check if Icu_Ipw_Types header and Icu_LPit_Types file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_LPIT_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_LPit_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_LPit_Types file are of the same Autosar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ICU_LPIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_LPIT_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_LPit_Types.h are different"
#endif
/* Check if header file and Icu_LPit_Types file are of the same software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_LPIT_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_LPIT_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_LPIT_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw_Types.h and Icu_LPit_Types.h are different"
#endif

/* Check if Icu_Ipw_Types header and Icu_Lptmr_Types file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_LPTMR_TYPES_VENDOR_ID)
    #error "Icu_Ipw_Types.h and Icu_Lptmr_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Lptmr_Types file are of the same Autosar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ICU_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw_Types.h and Icu_Lptmr_Types.h are different"
#endif
/* Check if header file and Icu_Lptmr_Types file are of the same software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_LPTMR_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_LPTMR_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_LPTMR_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw_Types.h and Icu_Lptmr_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/** @brief Symbolic name for Ftm channels */
#define ICU_FTM_CHANNEL         ((Icu_ChannelIpType)0)

/** @brief Symbolic name for Port_Ci channels */
#define ICU_PORT_CI_CHANNEL     ((Icu_ChannelIpType)1)

/** @brief Symbolic name for LPIT channels */
#define ICU_LPIT_CHANNEL        ((Icu_ChannelIpType)2)

/** @brief Symbolic name for LPTMR channels */
#define ICU_LPTMR_CHANNEL       ((Icu_ChannelIpType)3)

/* Macros to name the HW channels (FTM, PORT_CI, LPIT, LPTMR) */
/**
* @{
* @brief      FTM Channelss
* @details    FTM Hardware Channels
*/
#define ICU_FTM_0_CH_0        (0U)
#define ICU_FTM_0_CH_1        (ICU_FTM_0_CH_0 +  1U)
#define ICU_FTM_0_CH_2        (ICU_FTM_0_CH_0 +  2U)
#define ICU_FTM_0_CH_3        (ICU_FTM_0_CH_0 +  3U)
#define ICU_FTM_0_CH_4        (ICU_FTM_0_CH_0 +  4U)
#define ICU_FTM_0_CH_5        (ICU_FTM_0_CH_0 +  5U)
#define ICU_FTM_0_CH_6        (ICU_FTM_0_CH_0 +  6U)
#define ICU_FTM_0_CH_7        (ICU_FTM_0_CH_0 +  7U)

#define ICU_FTM_0_MAX         (ICU_FTM_0_CH_0 +  7U)

#define ICU_FTM_1_CH_0        (ICU_FTM_0_MAX  +  1U)
#define ICU_FTM_1_CH_1        (ICU_FTM_1_CH_0 +  1U)
#define ICU_FTM_1_CH_2        (ICU_FTM_1_CH_0 +  2U)
#define ICU_FTM_1_CH_3        (ICU_FTM_1_CH_0 +  3U)
#define ICU_FTM_1_CH_4        (ICU_FTM_1_CH_0 +  4U)
#define ICU_FTM_1_CH_5        (ICU_FTM_1_CH_0 +  5U)
#define ICU_FTM_1_CH_6        (ICU_FTM_1_CH_0 +  6U)
#define ICU_FTM_1_CH_7        (ICU_FTM_1_CH_0 +  7U)

#define ICU_FTM_1_MAX         (ICU_FTM_1_CH_0 +  7U)

#define ICU_FTM_2_CH_0        (ICU_FTM_1_MAX  +  1U)
#define ICU_FTM_2_CH_1        (ICU_FTM_2_CH_0 +  1U)
#define ICU_FTM_2_CH_2        (ICU_FTM_2_CH_0 +  2U)
#define ICU_FTM_2_CH_3        (ICU_FTM_2_CH_0 +  3U)
#define ICU_FTM_2_CH_4        (ICU_FTM_2_CH_0 +  4U)
#define ICU_FTM_2_CH_5        (ICU_FTM_2_CH_0 +  5U)
#define ICU_FTM_2_CH_6        (ICU_FTM_2_CH_0 +  6U)
#define ICU_FTM_2_CH_7        (ICU_FTM_2_CH_0 +  7U)
                
#define ICU_FTM_2_MAX         (ICU_FTM_2_CH_0 +  7U)

#define ICU_FTM_3_CH_0        (ICU_FTM_2_MAX  +  1U)
#define ICU_FTM_3_CH_1        (ICU_FTM_3_CH_0 +  1U)
#define ICU_FTM_3_CH_2        (ICU_FTM_3_CH_0 +  2U)
#define ICU_FTM_3_CH_3        (ICU_FTM_3_CH_0 +  3U)
#define ICU_FTM_3_CH_4        (ICU_FTM_3_CH_0 +  4U)
#define ICU_FTM_3_CH_5        (ICU_FTM_3_CH_0 +  5U)
#define ICU_FTM_3_CH_6        (ICU_FTM_3_CH_0 +  6U)
#define ICU_FTM_3_CH_7        (ICU_FTM_3_CH_0 +  7U)

#define ICU_FTM_3_MAX         (ICU_FTM_3_CH_0 +  7U)

#define ICU_FTM_4_CH_0        (ICU_FTM_3_MAX  +  1U)
#define ICU_FTM_4_CH_1        (ICU_FTM_4_CH_0 +  1U)
#define ICU_FTM_4_CH_2        (ICU_FTM_4_CH_0 +  2U)
#define ICU_FTM_4_CH_3        (ICU_FTM_4_CH_0 +  3U)
#define ICU_FTM_4_CH_4        (ICU_FTM_4_CH_0 +  4U)
#define ICU_FTM_4_CH_5        (ICU_FTM_4_CH_0 +  5U)
#define ICU_FTM_4_CH_6        (ICU_FTM_4_CH_0 +  6U)
#define ICU_FTM_4_CH_7        (ICU_FTM_4_CH_0 +  7U)

#define ICU_FTM_4_MAX         (ICU_FTM_4_CH_0 +  7U)

#define ICU_FTM_5_CH_0        (ICU_FTM_4_MAX  +  1U)
#define ICU_FTM_5_CH_1        (ICU_FTM_5_CH_0 +  1U)
#define ICU_FTM_5_CH_2        (ICU_FTM_5_CH_0 +  2U)
#define ICU_FTM_5_CH_3        (ICU_FTM_5_CH_0 +  3U)
#define ICU_FTM_5_CH_4        (ICU_FTM_5_CH_0 +  4U)
#define ICU_FTM_5_CH_5        (ICU_FTM_5_CH_0 +  5U)
#define ICU_FTM_5_CH_6        (ICU_FTM_5_CH_0 +  6U)
#define ICU_FTM_5_CH_7        (ICU_FTM_5_CH_0 +  7U)

#define ICU_FTM_5_MAX         (ICU_FTM_5_CH_0 +  7U)

#define ICU_FTM_6_CH_0        (ICU_FTM_5_MAX  +  1U)
#define ICU_FTM_6_CH_1        (ICU_FTM_6_CH_0 +  1U)
#define ICU_FTM_6_CH_2        (ICU_FTM_6_CH_0 +  2U)
#define ICU_FTM_6_CH_3        (ICU_FTM_6_CH_0 +  3U)
#define ICU_FTM_6_CH_4        (ICU_FTM_6_CH_0 +  4U)
#define ICU_FTM_6_CH_5        (ICU_FTM_6_CH_0 +  5U)
#define ICU_FTM_6_CH_6        (ICU_FTM_6_CH_0 +  6U)
#define ICU_FTM_6_CH_7        (ICU_FTM_6_CH_0 +  7U)

#define ICU_FTM_6_MAX         (ICU_FTM_6_CH_0 +  7U)

#define ICU_FTM_7_CH_0        (ICU_FTM_6_MAX  +  1U)
#define ICU_FTM_7_CH_1        (ICU_FTM_7_CH_0 +  1U)
#define ICU_FTM_7_CH_2        (ICU_FTM_7_CH_0 +  2U)
#define ICU_FTM_7_CH_3        (ICU_FTM_7_CH_0 +  3U)
#define ICU_FTM_7_CH_4        (ICU_FTM_7_CH_0 +  4U)
#define ICU_FTM_7_CH_5        (ICU_FTM_7_CH_0 +  5U)
#define ICU_FTM_7_CH_6        (ICU_FTM_7_CH_0 +  6U)
#define ICU_FTM_7_CH_7        (ICU_FTM_7_CH_0 +  7U)

#define ICU_FTM_7_MAX         (ICU_FTM_7_CH_0 +  7U)
/**@}*/
/**
* @{
* @brief      External Interrupt Channels
* @details    Port_Ci  Channels
*/
#define   ICU_PORT_0_CH_0        (ICU_FTM_7_MAX  + 1U)
#define   ICU_PORT_0_CH_1        (ICU_PORT_0_CH_0 + 1U)
#define   ICU_PORT_0_CH_2        (ICU_PORT_0_CH_0 + 2U)
#define   ICU_PORT_0_CH_3        (ICU_PORT_0_CH_0 + 3U)
#define   ICU_PORT_0_CH_4        (ICU_PORT_0_CH_0 + 4U)
#define   ICU_PORT_0_CH_5        (ICU_PORT_0_CH_0 + 5U)
#define   ICU_PORT_0_CH_6        (ICU_PORT_0_CH_0 + 6U)
#define   ICU_PORT_0_CH_7        (ICU_PORT_0_CH_0 + 7U)
#define   ICU_PORT_0_CH_8        (ICU_PORT_0_CH_0 + 8U)
#define   ICU_PORT_0_CH_9        (ICU_PORT_0_CH_0 + 9U)
#define   ICU_PORT_0_CH_10       (ICU_PORT_0_CH_0 + 10U)
#define   ICU_PORT_0_CH_11       (ICU_PORT_0_CH_0 + 11U)
#define   ICU_PORT_0_CH_12       (ICU_PORT_0_CH_0 + 12U)
#define   ICU_PORT_0_CH_13       (ICU_PORT_0_CH_0 + 13U)
#define   ICU_PORT_0_CH_14       (ICU_PORT_0_CH_0 + 14U)
#define   ICU_PORT_0_CH_15       (ICU_PORT_0_CH_0 + 15U)
#define   ICU_PORT_0_CH_16       (ICU_PORT_0_CH_0 + 16U)
#define   ICU_PORT_0_CH_17       (ICU_PORT_0_CH_0 + 17U)
#define   ICU_PORT_0_CH_18       (ICU_PORT_0_CH_0 + 18U)
#define   ICU_PORT_0_CH_19       (ICU_PORT_0_CH_0 + 19U)
#define   ICU_PORT_0_CH_20       (ICU_PORT_0_CH_0 + 20U)
#define   ICU_PORT_0_CH_21       (ICU_PORT_0_CH_0 + 21U)
#define   ICU_PORT_0_CH_22       (ICU_PORT_0_CH_0 + 22U)
#define   ICU_PORT_0_CH_23       (ICU_PORT_0_CH_0 + 23U)
#define   ICU_PORT_0_CH_24       (ICU_PORT_0_CH_0 + 24U)
#define   ICU_PORT_0_CH_25       (ICU_PORT_0_CH_0 + 25U)
#define   ICU_PORT_0_CH_26       (ICU_PORT_0_CH_0 + 26U)
#define   ICU_PORT_0_CH_27       (ICU_PORT_0_CH_0 + 27U)
#define   ICU_PORT_0_CH_28       (ICU_PORT_0_CH_0 + 28U)
#define   ICU_PORT_0_CH_29       (ICU_PORT_0_CH_0 + 29U)
#define   ICU_PORT_0_CH_30       (ICU_PORT_0_CH_0 + 30U)
#define   ICU_PORT_0_CH_31       (ICU_PORT_0_CH_0 + 31U)

#define   ICU_PORT_0_MAX         (ICU_PORT_0_CH_0 + 31U)

#define   ICU_PORT_1_CH_0        (ICU_PORT_0_MAX + 1U)
#define   ICU_PORT_1_CH_1        (ICU_PORT_1_CH_0 + 1U)
#define   ICU_PORT_1_CH_2        (ICU_PORT_1_CH_0 + 2U)
#define   ICU_PORT_1_CH_3        (ICU_PORT_1_CH_0 + 3U)
#define   ICU_PORT_1_CH_4        (ICU_PORT_1_CH_0 + 4U)
#define   ICU_PORT_1_CH_5        (ICU_PORT_1_CH_0 + 5U)
#define   ICU_PORT_1_CH_6        (ICU_PORT_1_CH_0 + 6U)
#define   ICU_PORT_1_CH_7        (ICU_PORT_1_CH_0 + 7U)
#define   ICU_PORT_1_CH_8        (ICU_PORT_1_CH_0 + 8U)
#define   ICU_PORT_1_CH_9        (ICU_PORT_1_CH_0 + 9U)
#define   ICU_PORT_1_CH_10       (ICU_PORT_1_CH_0 + 10U)
#define   ICU_PORT_1_CH_11       (ICU_PORT_1_CH_0 + 11U)
#define   ICU_PORT_1_CH_12       (ICU_PORT_1_CH_0 + 12U)
#define   ICU_PORT_1_CH_13       (ICU_PORT_1_CH_0 + 13U)
#define   ICU_PORT_1_CH_14       (ICU_PORT_1_CH_0 + 14U)
#define   ICU_PORT_1_CH_15       (ICU_PORT_1_CH_0 + 15U)
#define   ICU_PORT_1_CH_16       (ICU_PORT_1_CH_0 + 16U)
#define   ICU_PORT_1_CH_17       (ICU_PORT_1_CH_0 + 17U)
#define   ICU_PORT_1_CH_18       (ICU_PORT_1_CH_0 + 18U)
#define   ICU_PORT_1_CH_19       (ICU_PORT_1_CH_0 + 19U)
#define   ICU_PORT_1_CH_20       (ICU_PORT_1_CH_0 + 20U)
#define   ICU_PORT_1_CH_21       (ICU_PORT_1_CH_0 + 21U)
#define   ICU_PORT_1_CH_22       (ICU_PORT_1_CH_0 + 22U)
#define   ICU_PORT_1_CH_23       (ICU_PORT_1_CH_0 + 23U)
#define   ICU_PORT_1_CH_24       (ICU_PORT_1_CH_0 + 24U)
#define   ICU_PORT_1_CH_25       (ICU_PORT_1_CH_0 + 25U)
#define   ICU_PORT_1_CH_26       (ICU_PORT_1_CH_0 + 26U)
#define   ICU_PORT_1_CH_27       (ICU_PORT_1_CH_0 + 27U)
#define   ICU_PORT_1_CH_28       (ICU_PORT_1_CH_0 + 28U)
#define   ICU_PORT_1_CH_29       (ICU_PORT_1_CH_0 + 29U)
#define   ICU_PORT_1_CH_30       (ICU_PORT_1_CH_0 + 30U)
#define   ICU_PORT_1_CH_31       (ICU_PORT_1_CH_0 + 31U)

#define   ICU_PORT_1_MAX         (ICU_PORT_1_CH_0 + 31U)

#define   ICU_PORT_2_CH_0        (ICU_PORT_1_MAX + 1U)
#define   ICU_PORT_2_CH_1        (ICU_PORT_2_CH_0 + 1U)
#define   ICU_PORT_2_CH_2        (ICU_PORT_2_CH_0 + 2U)
#define   ICU_PORT_2_CH_3        (ICU_PORT_2_CH_0 + 3U)
#define   ICU_PORT_2_CH_4        (ICU_PORT_2_CH_0 + 4U)
#define   ICU_PORT_2_CH_5        (ICU_PORT_2_CH_0 + 5U)
#define   ICU_PORT_2_CH_6        (ICU_PORT_2_CH_0 + 6U)
#define   ICU_PORT_2_CH_7        (ICU_PORT_2_CH_0 + 7U)
#define   ICU_PORT_2_CH_8        (ICU_PORT_2_CH_0 + 8U)
#define   ICU_PORT_2_CH_9        (ICU_PORT_2_CH_0 + 9U)
#define   ICU_PORT_2_CH_10       (ICU_PORT_2_CH_0 + 10U)
#define   ICU_PORT_2_CH_11       (ICU_PORT_2_CH_0 + 11U)
#define   ICU_PORT_2_CH_12       (ICU_PORT_2_CH_0 + 12U)
#define   ICU_PORT_2_CH_13       (ICU_PORT_2_CH_0 + 13U)
#define   ICU_PORT_2_CH_14       (ICU_PORT_2_CH_0 + 14U)
#define   ICU_PORT_2_CH_15       (ICU_PORT_2_CH_0 + 15U)
#define   ICU_PORT_2_CH_16       (ICU_PORT_2_CH_0 + 16U)
#define   ICU_PORT_2_CH_17       (ICU_PORT_2_CH_0 + 17U)
#define   ICU_PORT_2_CH_18       (ICU_PORT_2_CH_0 + 18U)
#define   ICU_PORT_2_CH_19       (ICU_PORT_2_CH_0 + 19U)
#define   ICU_PORT_2_CH_20       (ICU_PORT_2_CH_0 + 20U)
#define   ICU_PORT_2_CH_21       (ICU_PORT_2_CH_0 + 21U)
#define   ICU_PORT_2_CH_22       (ICU_PORT_2_CH_0 + 22U)
#define   ICU_PORT_2_CH_23       (ICU_PORT_2_CH_0 + 23U)
#define   ICU_PORT_2_CH_24       (ICU_PORT_2_CH_0 + 24U)
#define   ICU_PORT_2_CH_25       (ICU_PORT_2_CH_0 + 25U)
#define   ICU_PORT_2_CH_26       (ICU_PORT_2_CH_0 + 26U)
#define   ICU_PORT_2_CH_27       (ICU_PORT_2_CH_0 + 27U)
#define   ICU_PORT_2_CH_28       (ICU_PORT_2_CH_0 + 28U)
#define   ICU_PORT_2_CH_29       (ICU_PORT_2_CH_0 + 29U)
#define   ICU_PORT_2_CH_30       (ICU_PORT_2_CH_0 + 30U)
#define   ICU_PORT_2_CH_31       (ICU_PORT_2_CH_0 + 31U)

#define   ICU_PORT_2_MAX         (ICU_PORT_2_CH_0 + 31U)

#define   ICU_PORT_3_CH_0        (ICU_PORT_2_MAX + 1U)
#define   ICU_PORT_3_CH_1        (ICU_PORT_3_CH_0 + 1U)
#define   ICU_PORT_3_CH_2        (ICU_PORT_3_CH_0 + 2U)
#define   ICU_PORT_3_CH_3        (ICU_PORT_3_CH_0 + 3U)
#define   ICU_PORT_3_CH_4        (ICU_PORT_3_CH_0 + 4U)
#define   ICU_PORT_3_CH_5        (ICU_PORT_3_CH_0 + 5U)
#define   ICU_PORT_3_CH_6        (ICU_PORT_3_CH_0 + 6U)
#define   ICU_PORT_3_CH_7        (ICU_PORT_3_CH_0 + 7U)
#define   ICU_PORT_3_CH_8        (ICU_PORT_3_CH_0 + 8U)
#define   ICU_PORT_3_CH_9        (ICU_PORT_3_CH_0 + 9U)
#define   ICU_PORT_3_CH_10       (ICU_PORT_3_CH_0 + 10U)
#define   ICU_PORT_3_CH_11       (ICU_PORT_3_CH_0 + 11U)
#define   ICU_PORT_3_CH_12       (ICU_PORT_3_CH_0 + 12U)
#define   ICU_PORT_3_CH_13       (ICU_PORT_3_CH_0 + 13U)
#define   ICU_PORT_3_CH_14       (ICU_PORT_3_CH_0 + 14U)
#define   ICU_PORT_3_CH_15       (ICU_PORT_3_CH_0 + 15U)
#define   ICU_PORT_3_CH_16       (ICU_PORT_3_CH_0 + 16U)
#define   ICU_PORT_3_CH_17       (ICU_PORT_3_CH_0 + 17U)
#define   ICU_PORT_3_CH_18       (ICU_PORT_3_CH_0 + 18U)
#define   ICU_PORT_3_CH_19       (ICU_PORT_3_CH_0 + 19U)
#define   ICU_PORT_3_CH_20       (ICU_PORT_3_CH_0 + 20U)
#define   ICU_PORT_3_CH_21       (ICU_PORT_3_CH_0 + 21U)
#define   ICU_PORT_3_CH_22       (ICU_PORT_3_CH_0 + 22U)
#define   ICU_PORT_3_CH_23       (ICU_PORT_3_CH_0 + 23U)
#define   ICU_PORT_3_CH_24       (ICU_PORT_3_CH_0 + 24U)
#define   ICU_PORT_3_CH_25       (ICU_PORT_3_CH_0 + 25U)
#define   ICU_PORT_3_CH_26       (ICU_PORT_3_CH_0 + 26U)
#define   ICU_PORT_3_CH_27       (ICU_PORT_3_CH_0 + 27U)
#define   ICU_PORT_3_CH_28       (ICU_PORT_3_CH_0 + 28U)
#define   ICU_PORT_3_CH_29       (ICU_PORT_3_CH_0 + 29U)
#define   ICU_PORT_3_CH_30       (ICU_PORT_3_CH_0 + 30U)
#define   ICU_PORT_3_CH_31       (ICU_PORT_3_CH_0 + 31U)

#define   ICU_PORT_3_MAX         (ICU_PORT_3_CH_0 + 31U)

#define   ICU_PORT_4_CH_0        (ICU_PORT_3_MAX + 1U)
#define   ICU_PORT_4_CH_1        (ICU_PORT_4_CH_0 + 1U)
#define   ICU_PORT_4_CH_2        (ICU_PORT_4_CH_0 + 2U)
#define   ICU_PORT_4_CH_3        (ICU_PORT_4_CH_0 + 3U)
#define   ICU_PORT_4_CH_4        (ICU_PORT_4_CH_0 + 4U)
#define   ICU_PORT_4_CH_5        (ICU_PORT_4_CH_0 + 5U)
#define   ICU_PORT_4_CH_6        (ICU_PORT_4_CH_0 + 6U)
#define   ICU_PORT_4_CH_7        (ICU_PORT_4_CH_0 + 7U)
#define   ICU_PORT_4_CH_8        (ICU_PORT_4_CH_0 + 8U)
#define   ICU_PORT_4_CH_9        (ICU_PORT_4_CH_0 + 9U)
#define   ICU_PORT_4_CH_10       (ICU_PORT_4_CH_0 + 10U)
#define   ICU_PORT_4_CH_11       (ICU_PORT_4_CH_0 + 11U)
#define   ICU_PORT_4_CH_12       (ICU_PORT_4_CH_0 + 12U)
#define   ICU_PORT_4_CH_13       (ICU_PORT_4_CH_0 + 13U)
#define   ICU_PORT_4_CH_14       (ICU_PORT_4_CH_0 + 14U)
#define   ICU_PORT_4_CH_15       (ICU_PORT_4_CH_0 + 15U)
#define   ICU_PORT_4_CH_16       (ICU_PORT_4_CH_0 + 16U)
#define   ICU_PORT_4_CH_17       (ICU_PORT_4_CH_0 + 17U)
#define   ICU_PORT_4_CH_18       (ICU_PORT_4_CH_0 + 18U)
#define   ICU_PORT_4_CH_19       (ICU_PORT_4_CH_0 + 19U)
#define   ICU_PORT_4_CH_20       (ICU_PORT_4_CH_0 + 20U)
#define   ICU_PORT_4_CH_21       (ICU_PORT_4_CH_0 + 21U)
#define   ICU_PORT_4_CH_22       (ICU_PORT_4_CH_0 + 22U)
#define   ICU_PORT_4_CH_23       (ICU_PORT_4_CH_0 + 23U)
#define   ICU_PORT_4_CH_24       (ICU_PORT_4_CH_0 + 24U)
#define   ICU_PORT_4_CH_25       (ICU_PORT_4_CH_0 + 25U)
#define   ICU_PORT_4_CH_26       (ICU_PORT_4_CH_0 + 26U)
#define   ICU_PORT_4_CH_27       (ICU_PORT_4_CH_0 + 27U)
#define   ICU_PORT_4_CH_28       (ICU_PORT_4_CH_0 + 28U)
#define   ICU_PORT_4_CH_29       (ICU_PORT_4_CH_0 + 29U)
#define   ICU_PORT_4_CH_30       (ICU_PORT_4_CH_0 + 30U)
#define   ICU_PORT_4_CH_31       (ICU_PORT_4_CH_0 + 31U)

#define   ICU_PORT_4_MAX         (ICU_PORT_4_CH_0 + 31U)

#define ICU_LPIT_0_CH_0           (ICU_PORT_4_MAX  +  1U)
#define ICU_LPIT_0_CH_1           (ICU_LPIT_0_CH_0  +  1U)
#define ICU_LPIT_0_CH_2           (ICU_LPIT_0_CH_0  +  2U)
#define ICU_LPIT_0_CH_3           (ICU_LPIT_0_CH_0  +  3U)
                                  
#define ICU_LPIT_0_MAX            (ICU_LPIT_0_CH_0  +  3U)
                                  
#define ICU_LPTMR_0_CH_0          (ICU_LPIT_0_MAX  +  1U)

#define ICU_LPTMR_0_MAX           (ICU_LPIT_0_MAX  +  1U)

/**@}*/
/*
* Macros regarding the maximum number of HW channels from different IP modules
*/
/**
* @{
* @brief      ICU_MAX_FTM_CHANNELS - the maximum number of FTM channels
* @details    Represents the maximum number of FTM channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_FTM_CHANNELS             (ICU_PORT_0_CH_0)
/**@}*/

/**
* @{
* @brief      ICU_MAX_PORT_CI_CHANNELS - the maximum number of Port_Ci channels
* @details    Represents the maximum number of Port_Ci channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_PORT_CI_CHANNELS        (ICU_PORT_4_MAX - ICU_FTM_7_MAX)
/**@}*/


/**
* @{
* @brief      ICU_MAX_LPIT_CHANNELS - the maximum number of LPIT channels
* @details    Represents the maximum number of LPIT channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_LPIT_CHANNELS           (ICU_LPIT_0_MAX - ICU_PORT_4_MAX)
/**@}*/

/**
* @{
* @brief      ICU_MAX_LPTMR_CHANNELS - the maximum number of LPTMR channels
* @details    Represents the maximum number of LPTMR channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_LPTMR_CHANNELS          (ICU_LPTMR_0_MAX - ICU_LPIT_0_MAX)
/**@}*/

/**
* @{
* @brief      ICU_MAX_HW_CHANNELS - the highest ICU hardware channel number
* @details    Represents the maximum number of IRQ channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_HW_CHANNELS             (ICU_LPTMR_0_MAX + 1U)
/**@}*/

/**
* @{
* @brief      ICU_VALID_CHANNEL_INPUT_LEVEL - the maximum number of eTiemr channels
* @details    Represents the maximum number of Ftm channels, To get the status of
*             input pin using an API Icu_GetInputLevel the channel should be an eTimer
*             Channel.
*/

#define ICU_VALID_CHANNEL_INPUT_LEVEL         (ICU_MAX_FTM_CHANNELS)
/**@}*/

/**
* @{
* @brief Macros to translate ICU generic channels to specific hardware channels
*
* @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
*/
#define ICU_FTM_CHANNELS(ch)      (ch)
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define ICU_PORT_CI_CHANNELS(ch)  ((ch) - ICU_PORT_0_CH_0)
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define ICU_LPIT_CHANNELS(ch)  ((ch) - ICU_LPIT_0_CH_0)
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define ICU_LPTMR_CHANNELS(ch)  ((ch) - ICU_LPTMR_0_CH_0)
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define FTM_ICU_CHANNEL(ch)     ((ch))
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define PORT_CI_ICU_CHANNEL(ch)     ((ch) + ICU_PORT_0_CH_0)
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define LPIT_ICU_CHANNEL(ch)     ((ch) + ICU_LPIT_0_CH_0)
/*
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define LPTMR_ICU_CHANNEL(ch)     ((ch) + ICU_LPTMR_0_CH_0)
/**@}*/

/**
* @{
* @brief   Macros for handling the actual states of the ICU Channels
* @remarks These bitfields are used to set Icu_aChannelState array
*/

/**
* @{
* @brief Wakeup feature is currently enabled
*/
#define ICU_CHANNEL_STATE_WKUP                  ((Icu_ChannelStateType)BIT0)
#define ICU_CHANNEL_STATE_WKUP_SHIFT            (0U)
#define ICU_CHANNEL_STATE_WKUP_MASK             ((Icu_ChannelStateType)BIT0)
/**@}*/

/**
* @{
* @brief The current channel status - IDLE / ACTIVE
*/
#define ICU_CHANNEL_STATE_IDLE                  ((Icu_ChannelStateType)BIT1)
#define ICU_CHANNEL_STATE_IDLE_SHIFT            (1U)
#define ICU_CHANNEL_STATE_IDLE_MASK             ((Icu_ChannelStateType)BIT1)
/**@}*/

/**
* @{
* @brief Notification is enabled
*/
#define ICU_CHANNEL_STATE_NOTIFICATION          ((Icu_ChannelStateType)BIT2)
#define ICU_CHANNEL_STATE_NOTIF_SHIFT           (2U)
#define ICU_CHANNEL_STATE_NOTIF_MASK            ((Icu_ChannelStateType)BIT2)
/**@}*/

/**
* @{
* @brief The current channel state
*/
#define ICU_CHANNEL_STATE_RUNNING               ((Icu_ChannelStateType)BIT3)
#define ICU_CHANNEL_STATE_RUNNING_SHIFT         (3U)
#define ICU_CHANNEL_STATE_RUNNING_MASK          ((Icu_ChannelStateType)BIT3)
/**@}*/

/**
* @{
* @brief Overflow flag
*/
#define ICU_CHANNEL_STATE_OVERFLOW              ((Icu_ChannelStateType)BIT4)
#define ICU_CHANNEL_STATE_OVERFLOW_SHIFT        (4U)
#define ICU_CHANNEL_STATE_OVERFLOW_MASK         ((Icu_ChannelStateType)BIT4)
/**@}*/

/**
* @{
* @brief Rising edge
*/
#define ICU_CHANNEL_STATE_RISING                ((Icu_ChannelStateType)BIT5)
#define ICU_CHANNEL_STATE_RISING_SHIFT          (5U)
#define ICU_CHANNEL_STATE_RISING_MASK           ((Icu_ChannelStateType)BIT5)
/**@}*/

/**
* @{
* @brief Falling edge
*/
#define ICU_CHANNEL_STATE_FALLING               ((Icu_ChannelStateType)BIT6)
#define ICU_CHANNEL_STATE_FALLING_SHIFT         (6U)
#define ICU_CHANNEL_STATE_FALLING_MASK          ((Icu_ChannelStateType)BIT6)
/**@}*/

/**
* @{
* @brief Both edges
*/
#define ICU_CHANNEL_STATE_BOTH_EDGES            ((Icu_ChannelStateType)(BIT6|BIT5))
#define ICU_CHANNEL_STATE_BOTH_EDGES_SHIFT      (5U)
#define ICU_CHANNEL_STATE_BOTH_EDGES_MASK       ((Icu_ChannelStateType)(BIT6|BIT5))
/**@}*/

/**
* @{
* @brief Wakeup source
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE            ((Icu_ChannelStateType)BIT7)
#define ICU_CHANNEL_IS_WAKEUP_SOURCE_SHIFT      (7U)
#define ICU_CHANNEL_IS_WAKEUP_SOURCE_MASK       ((Icu_ChannelStateType)BIT7)
/**@}*/

/**
 * @brief  Definition of bit mask to isolate the wake up capability  bitfield
 */
#define ICU_WAKEUP_MASK         ((uint32)BIT31)
/**
 * @brief  Definition wake up capability bitfield position
 */
#define ICU_WAKEUP_SHIFT        ((uint32)31U)

/**
 * @brief  Definition of bit mask to isolate the configured edge activation type
 */
#define ICU_EDGE_PARAM_MASK     ((uint32)(BIT30|BIT29))
/**
 * @brief  Definition edge activation type bitfield position
 */
#define ICU_EDGE_PARAM_SHIFT    ((uint32)29U)
/**@}*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   ICU Channel state type
*
*/
typedef uint8 Icu_ChannelStateType;

typedef uint8 Icu_Ipw_ChannelType;

/**
* @brief      IP type used to implement a Icu channel
*/
typedef uint8 Icu_ChannelIpType;


/**
* @brief      Icu channel high level configuration structure
*/
typedef struct 
{
    /** @brief The IP used to implement this specific Icu channel */
    CONST(Icu_ChannelIpType,    ICU_CONST) nChannelIp;
    /** @brief Index in the IP specific configuration table */
    CONST(uint8,                ICU_CONST) u8IdxChannelConfig;
} Icu_IpChannelConfigType;


/**
* @brief      Combined IP specific configuration structure
*/
typedef struct 
{
    /** @brief Pointer to the structure containing Ftm configuration */
    CONSTP2CONST(Icu_Ftm_IpConfigType, ICU_CONST, ICU_APPL_CONST) pFtmIpConfig;
    /** @brief Pointer to the structure containing PORT_CI configuration */
    CONSTP2CONST(Icu_Port_Ci_IpConfigType, ICU_CONST, ICU_APPL_CONST) pPort_CiIpConfig;
    /** @brief Pointer to the structure containing LPit configuration */
    CONSTP2CONST(Icu_LPit_IpConfigType, ICU_CONST, ICU_APPL_CONST) pLPitIpConfig;
    /** @brief Pointer to the structure containing Lptmr configuration */
    CONSTP2CONST(Icu_Lptmr_IpConfigType, ICU_CONST, ICU_APPL_CONST) pLptmrIpConfig;
    /** @brief Pointer to Array containing IP type and index in the IP configuration table 
    for each Icu channel */
    CONST       (Icu_IpChannelConfigType,  ICU_CONST)                 (*pIpChannelsConfig)[];
} Icu_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* ICU_IPW_TYPES_H */
/** @} */

