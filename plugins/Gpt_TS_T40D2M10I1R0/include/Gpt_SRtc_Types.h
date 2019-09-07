/**
*   @file    Gpt_SRtc_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - SRTC driver header file.
*   @details SRTC driver defines which need to be exported to external application
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

#ifndef GPT_SRTC_TYPES_H
#define GPT_SRTC_TYPES_H

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
* @section GPT_SRTC_TYPES_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref GPT_SRTC_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_Cfg.h"
/** @violates @ref GPT_SRTC_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_EnvCfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_SRtc_Types.h
* @{
*/
#define GPT_SRTC_TYPES_VENDOR_ID                       43
#define GPT_SRTC_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define GPT_SRTC_TYPES_AR_RELEASE_MINOR_VERSION        2
#define GPT_SRTC_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_SRTC_TYPES_SW_MAJOR_VERSION                1
#define GPT_SRTC_TYPES_SW_MINOR_VERSION                0
#define GPT_SRTC_TYPES_SW_PATCH_VERSION                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_SRTC_TYPES_VENDOR_ID != GPT_VENDOR_ID_CFG)
    #error "Gpt_SRtc_Types.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_SRTC_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_SRTC_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_SRTC_TYPES_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt_SRtc_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_SRTC_TYPES_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SRTC_TYPES_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SRTC_TYPES_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) )
    #error "Software Version Numbers of Gpt_SRtc_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_SRTC_TYPES_VENDOR_ID!= GPT_ENVCFG_VENDOR_ID)
    #error "Gpt_SRtc_Types.h and Gpt_EnvCfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_SRTC_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_SRTC_TYPES_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (GPT_SRTC_TYPES_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_SRtc_Types.h and Gpt_EnvCfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_SRTC_TYPES_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
     (GPT_SRTC_TYPES_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
     (GPT_SRTC_TYPES_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_SRtc_Types.h and Gpt_EnvCfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief SRTC Channels defines
*/
#define SRTC_0_CH_0                  ((uint8)0)
/** @} */

/*==================================================================================================
*                                            ENUMS
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

#endif /*GPT_SRTC_TYPES_H*/

/** @} */
