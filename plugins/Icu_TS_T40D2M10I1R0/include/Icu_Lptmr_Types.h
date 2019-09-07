/**
*   @file    Icu_Lptmr_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - LPTMR driver header file.
*   @details LPTMR driver defines which need to be exported to external application
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

#ifndef ICU_LPTMR_TYPES_H
#define ICU_LPTMR_TYPES_H

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
* @section ICU_LPTMR_TYPES_H_REF_1
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
* @file           Icu_Lptmr_Types.h
* @{
*/
#define ICU_LPTMR_TYPES_VENDOR_ID                       43
#define ICU_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION        2
#define ICU_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION     2
#define ICU_LPTMR_TYPES_SW_MAJOR_VERSION                1
#define ICU_LPTMR_TYPES_SW_MINOR_VERSION                0
#define ICU_LPTMR_TYPES_SW_PATCH_VERSION                1
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

#define ICU_LPTMR_CSR_TPS_MASK_U32                  ((uint32)BIT5|BIT14)
#define ICU_LPTMR_CSR_TPS_SHIFT_U32                     ((uint32)4U)
#define ICU_LPTMR_PSR_PBYP_MASK_U32                 ((uint32)BIT2)
#define ICU_LPTMR_PSR_PBYP_SHIFT_U32                    ((uint32)2U)
#define ICU_LPTMR_PSR_PCS_MASK_U32                  ((uint32)BIT1|BIT0)
#define ICU_LPTMR_PSR_PCS_SHIFT_U32                     ((uint32)0U)
#define ICU_LPTMR_PSR_PRESCALE_MASK_U32             ((uint32)BIT6|BIT5|BIT4|BIT3)
#define ICU_LPTMR_PSR_PRESCALE_SHIFT_U32                ((uint32)3U)

#define ICU_LPTMR_GLITCH_FILTER_2_U16                   ((uint16)1U)
#define ICU_LPTMR_GLITCH_FILTER_4_U16                   ((uint16)2U)
#define ICU_LPTMR_GLITCH_FILTER_8_U16                   ((uint16)3U)
#define ICU_LPTMR_GLITCH_FILTER_16_U16                  ((uint16)4U)
#define ICU_LPTMR_GLITCH_FILTER_32_U16                  ((uint16)5U)
#define ICU_LPTMR_GLITCH_FILTER_64_U16                  ((uint16)6U)
#define ICU_LPTMR_GLITCH_FILTER_128_U16                 ((uint16)7U)
#define ICU_LPTMR_GLITCH_FILTER_256_U16                 ((uint16)8U)
#define ICU_LPTMR_GLITCH_FILTER_512_U16                 ((uint16)9U)
#define ICU_LPTMR_GLITCH_FILTER_1024_U16                ((uint16)10U)
#define ICU_LPTMR_GLITCH_FILTER_2048_U16                ((uint16)11U)
#define ICU_LPTMR_GLITCH_FILTER_4096_U16                ((uint16)12U)
#define ICU_LPTMR_GLITCH_FILTER_8192_U16                ((uint16)13U)
#define ICU_LPTMR_GLITCH_FILTER_16384_U16               ((uint16)14U)
#define ICU_LPTMR_GLITCH_FILTER_32768_U16               ((uint16)15U)

/**
* @{
* @brief          Lpmtr channels defines
* @details        There are defines used for the Lptmr channel encoding -> channel_id
*
*/
#define LPTMR_0_CH_0                  ((uint8)0)
/** @} */
/** @} */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8  Icu_Lptmr_ChannelType;

typedef uint8 Icu_Lptmr_ControlType;

typedef uint16 Icu_Lptmr_GlobalConfigurationType;

typedef struct
{
    /** @brief Assigned Lptmr channel id*/
    CONST(Icu_Lptmr_ChannelType,  ICU_CONST) nHwChannel;
    /** @brief Lptmr channel parameters */
    CONST(Icu_Lptmr_ControlType,  ICU_CONST) nControlValue;
    /** @brief Lptmr Default Start Edge */
    CONST(uint8,  ICU_CONST) nDefaultStartEdge;
    /** @brief Lptmr MeasurementMode */
    CONST(uint8,  ICU_CONST) nMeasurementModeType;
} Icu_Lptmr_ChannelConfigType;

/**
* @brief      Lptmr IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of Lptmr channels in the Icu configuration */
    CONST(Icu_Lptmr_ChannelType,       ICU_CONST) nNumChannels;
    /** @brief The Lptmr global configuration paramters */
    P2CONST(Icu_Lptmr_GlobalConfigurationType, AUTOMATIC, ICU_APPL_CONST) Icu_GlobalConfiguration;
    /** @brief Pointer to the configured channels for Lptmr */
    CONST(Icu_Lptmr_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[];
} Icu_Lptmr_IpConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*ICU_LPTMR_TYPES_H*/

/** @} */
