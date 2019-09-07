/**
*   @file    Icu_LPit_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - LPIT driver header file.
*   @details LPIT driver defines which need to be exported to external application
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FTM PORT_CI LPIT LPTMR
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

#ifndef ICU_LPIT_TYPES_H
#define ICU_LPIT_TYPES_H

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
* @section ICU_LPIT_TYPES_H_REF_1
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Icu_LPit_Types.h
* @{
*/
#define ICU_LPIT_TYPES_VENDOR_ID                       43
#define ICU_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_LPIT_TYPES_AR_RELEASE_MINOR_VERSION        2
#define ICU_LPIT_TYPES_AR_RELEASE_REVISION_VERSION     2
#define ICU_LPIT_TYPES_SW_MAJOR_VERSION                1
#define ICU_LPIT_TYPES_SW_MINOR_VERSION                0
#define ICU_LPIT_TYPES_SW_PATCH_VERSION                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @{
* @brief          LPIT channels defines
* @details        There are defines used for the LPIT channel encoding -> channel_id
*
* @note           A LPIT module generally has 4 channels so by using this method
*                 there will be 6 bits for the LPIT module and 2 bits for the LPIT channel
*                 [               6 bit | 2 bit               ]
*                 [ module id: 63 ... 0 | channel id: 1 ... 0 ]
*/
#define LPIT_MOD_MASK_U8                         ((uint8)0xFC)
#define LPIT_MOD_SHIFT                           ((uint8)2U)
#define LPIT_CH_MASK_U8                          ((uint8)0x3)
#define LPIT_CH_SHIFT                            ((uint8)0U)
/** @} */


/**
* @{
* @brief LPIT Channels defines
*/

#define ICU_LPIT_FREEZE_MASK                     ((uint32)(BIT0))
#define ICU_LPIT_FREEZE_SHIFT                    ((uint32)0U)
#define ICU_LPIT_TRG_SRC_MASK                    ((uint32)(BIT1))
#define ICU_LPIT_TRG_SRC_SHIFT                   ((uint32)1U)
#define ICU_LPIT_TRG_SEL_MASK                    ((uint32)(BIT5|BIT4|BIT3|BIT2))
#define ICU_LPIT_TRG_SEL_SHIFT                   ((uint32)2U)

#define ICU_LPIT_TRG_CH0                         ((uint32)0U)
#define ICU_LPIT_TRG_CH1                         ((uint32)1U)
#define ICU_LPIT_TRG_CH2                         ((uint32)2U)
#define ICU_LPIT_TRG_CH3                         ((uint32)3U)
/** @} */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8  Icu_LPit_ChannelType;
typedef uint8  Icu_LPit_ControlType;

typedef struct
{
    /** @brief Assigned LPit channel id*/
    CONST(Icu_LPit_ChannelType,  ICU_CONST) nHwChannel;
    /** @brief LPit channel parameters */
    CONST(Icu_LPit_ControlType,  ICU_CONST) nControlValue;
} Icu_LPit_ChannelConfigType;

/**
* @brief      LPit IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of LPit channels in the Icu configuration */
    CONST(Icu_LPit_ChannelType,       ICU_CONST) nNumChannels;
    /** @brief Pointer to the configured channels for LPit */
    CONST(Icu_LPit_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[];
} Icu_LPit_IpConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*ICU_LPIT_TYPES_H*/

/** @} */
