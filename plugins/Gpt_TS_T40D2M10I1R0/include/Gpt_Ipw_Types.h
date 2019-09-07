/**
*   @file    Gpt_Ipw_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar independent.
*            - are platform dependent.
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

#ifndef GPT_IPW_TYPES_H
#define GPT_IPW_TYPES_H

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
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_LPit_Types.h"
#include "Gpt_Lptmr_Types.h"
#include "Gpt_Ftm_Types.h"
#include "Gpt_SRtc_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_IPW_TYPES_VENDOR_ID                      43
#define GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION       2
#define GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION    2
#define GPT_IPW_TYPES_SW_MAJOR_VERSION               1
#define GPT_IPW_TYPES_SW_MINOR_VERSION               0
#define GPT_IPW_TYPES_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_LPIT_TYPES_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_LPit_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_LPIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_LPIT_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_LPit_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_LPIT_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_LPIT_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_LPIT_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_LPit_Types.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_LPTMR_TYPES_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_Lptmr_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Lptmr_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_LPTMR_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_LPTMR_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_LPTMR_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Lptmr_Types.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_FTM_TYPES_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_Ftm_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Ftm_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_FTM_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_FTM_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_FTM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Ftm_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Gpt prescaler data type
*/
typedef uint8 Gpt_PrescalerType;

/**
* @brief Gpt clock source data type
*/
typedef uint8 Gpt_ClockSourceType;



/**
* @brief Low level configuration for channel specific parameters
*/
typedef struct
{
    VAR(uint8, GPT_VAR) Gpt_uHwChannel;                           /**<@brief GPT hw channel ID */
    VAR(uint8, GPT_VAR) Gpt_uHwModule;                            /**<@brief GPT hw module used */
    VAR(boolean, GPT_VAR) Gpt_bFreezeEnable;                      /**<@brief Channel freeze enable */
    VAR(Gpt_ClockSourceType, GPT_VAR) Gpt_uClockSource;           /**<@brief Ftm channel clock source*/
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uPrescaler;               /**<@brief Ftm channel prescaler value*/
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uLptmrPrescaler;          /**<@brief Lptmr channel prescaler value*/
    VAR(Gpt_ClockSourceType, GPT_VAR) Gpt_uLptmrClock;            /**<@brief Lptmr channel clock source*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uFtmPrescaler_Alternate;  /**<@brief Ftm channel prescaler alternate value*/
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uLptmrPrescaler_Alternate;  /**<@brief Low Power Timer channel prescaler alternate value*/
#endif /* GPT_DUAL_CLOCK_MODE */
    VAR(Gpt_ClockSourceType, GPT_VAR) Gpt_uSRtcClock;             /**<@brief SRTC channel clock source*/
#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
    VAR(uint32, GPT_VAR) Gpt_uTimerTriggerConfig;                 /**<@brief Trigger source configure for LPIT Timer*/
#endif
} Gpt_HwChannelConfigType;

/**
* @brief Low level configuration for channel specific parameters
*/
typedef struct
{
    VAR(uint8, GPT_VAR) Gpt_u8HwChannel;                    /**<@brief GPT hw channel ID */
    VAR(uint8, GPT_VAR) Gpt_u8HwModule;                     /**<@brief GPT hw module used */
    VAR(boolean, GPT_VAR) Gpt_bFreezeEnable;                /**<@brief Channel freeze enable */
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uPrescaler;         /**<@brief Channel prescaler value */
    VAR(Gpt_ClockSourceType, GPT_VAR) Gpt_uClockSource;     /**<@brief Channel clock source */
} Gpt_HwPredefChannelConfigType;


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*GPT_IPW_TYPES_H*/

/** @} */
