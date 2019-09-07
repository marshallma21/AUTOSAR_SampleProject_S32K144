/**
*   @file           Ocu_Ipw_Types.h
*
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - OCU driver Ipw header file.
*   @details        Ipw defines, types used by OCU driver.
*
*   @addtogroup     OCU_MODULE
*   @{
*/
/*===================================================================================================
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
=====================================================================================================*/
/*=====================================================================================================
======================================================================================================*/



#ifndef OCU_IPW_TYPES_H
#define OCU_IPW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_IPW_Types_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocu_Types.h"

#include "Ocu_Ftm_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ocu_Ipw_Types.h
*/
#define OCU_IPW_TYPES_VENDOR_ID                         43
#define OCU_IPW_TYPES_MODULE_ID                         121
/* @violates @ref Ocu_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Ocu_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Ocu_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION       2
#define OCU_IPW_TYPES_SW_MAJOR_VERSION                  1
#define OCU_IPW_TYPES_SW_MINOR_VERSION                  0
#define OCU_IPW_TYPES_SW_PATCH_VERSION                  1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if included Ocu_Ftm_Types.h header file has same vendor */
#if (OCU_IPW_TYPES_VENDOR_ID != OCU_FTM_TYPES_VENDOR_ID)
    #error "Ocu_Ipw_Types.h and Ocu_Ftm_Types.h have different vendor ids"
#endif

/* Check if included Ocu_Ftm_Types.h header file has same AUTOSAR version */
#if ((OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw_Types.h and Ocu_Ftm_Types.h are different"
#endif

/* Check if included Ocu_Ftm_Types.h header file has same software version */
#if ((OCU_IPW_TYPES_SW_MAJOR_VERSION !=  OCU_FTM_TYPES_SW_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_SW_MINOR_VERSION !=  OCU_FTM_TYPES_SW_MINOR_VERSION) || \
     (OCU_IPW_TYPES_SW_PATCH_VERSION !=  OCU_FTM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw_Types.h and Ocu_Ftm_Types.h are different"
#endif

/* Check if included Ocu_Types.h header file has same vendor */
#if (OCU_IPW_TYPES_VENDOR_ID != OCU_TYPES_VENDOR_ID)
    #error "Ocu_Ipw_Types.h and Ocu_Types.h have different vendor ids"
#endif

/* Check if included Ocu_Types.h header file has same AUTOSAR version */
#if ((OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  OCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  OCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  OCU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw_Types.h and Ocu_Types.h are different"
#endif

/* Check if included Ocu_Types.h header file has same software version */
#if ((OCU_IPW_TYPES_SW_MAJOR_VERSION !=  OCU_TYPES_SW_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_SW_MINOR_VERSION !=  OCU_TYPES_SW_MINOR_VERSION) || \
     (OCU_IPW_TYPES_SW_PATCH_VERSION !=  OCU_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw_Types.h and Ocu_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief      Prescaler type
* @details    This enum specifies the possible types of prescallers used to configure base-clock timers
*
*/
typedef enum
{
    /** @brief Selected value is the default/primary prescaler */
    OCU_PRIMARY_PRESCALER = 0,
    /** @brief Selected value is the alternative configured prescaler */
    OCU_ALTERNATIVE_PRESCALER
} Ocu_SelectPrescalerType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief      IP type used to implement a Ocu channel
*/
typedef uint8 Ocu_ChannelIpType;

typedef struct 
{
    /** @brief Index in the IP specific configuration table */
    CONST(uint8, OCU_CONST) u8IdxChannelConfig;
} Ocu_IpChannelConfigType;

/**
* @brief   IP specific configuration structure
* 
*/
typedef struct
{
    /* @brief pointer to the configured channels for FTM */
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST) pFtmIpConfig;
    /* @brief Pointer to Array containing IP type and index in the IP configuration table for each Ocu channel */
    CONST(Ocu_IpChannelConfigType,  OCU_CONST)  (*pIpChannelsConfig)[];
} Ocu_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
      

#ifdef __cplusplus
}
#endif

#endif    /* OCU_IPW_TYPES_H */

/** @} */

