/**
*   @file       Ocu_Types.h
*   @version    1.0.1
*
*   @brief      AUTOSAR Ocu - Ocu generic types file.
*   @details    Contains generic Ocu types and structures.
*
*   @addtogroup OCU_MODULE
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

#ifndef OCU_TYPES_H
#define OCU_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define OCU_TYPES_VENDOR_ID                         43
#define OCU_TYPES_MODULE_ID                         121
#define OCU_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define OCU_TYPES_AR_RELEASE_MINOR_VERSION          2
#define OCU_TYPES_AR_RELEASE_REVISION_VERSION       2
#define OCU_TYPES_SW_MAJOR_VERSION                  1
#define OCU_TYPES_SW_MINOR_VERSION                  0
#define OCU_TYPES_SW_PATCH_VERSION                  1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((OCU_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ocu_Types.h and Std_Types.h are different"
#endif
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


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief      Ocu channel type
* @implements Ocu_ChannelType_typedef
*/
typedef uint16 Ocu_ChannelType;

/**
* @brief      Channel notification typedef
*/
typedef void (*Ocu_NotifyType)(void);

/**
* @brief      Ocu Return Type
* @details    Return information after setting a new threshold value.
* 
* @implements Ocu_ReturnType_enumeration
*/
typedef enum
{
    /** @brief The compare match will occur inside the current Reference Interval. */
    OCU_CM_IN_REF_INTERVAL = 0,
    /** @brief The compare match will not occur inside the current Reference Interval. */
    OCU_CM_OUT_REF_INTERVAL
} Ocu_ReturnType;

/**
* @brief      Edge Pin Action type
* @details    Automatic action (by hardware) to be performed on a pin attached to an OCU channel.
* @implements Ocu_PinActionType_enumeration
*/
typedef enum
{
    /** @brief The channel pin will be set HIGH upon compare match. */
    OCU_SET_LOW = 0,   
   /** @brief The channel pin will be set LOW upon compare match. */
    OCU_SET_HIGH = 1,
    /** @brief The channel pin will be set to the opposite of its current level HIGH upon compare match. */
    OCU_TOGGLE = 2,
    /** @brief The channel pin will remain at its current level upon compare match. */
    OCU_DISABLE = 3
} Ocu_PinActionType;


/**
* @brief      Pin State level
* @details    Output state of the pin linked to an OCU channel.
* 
* @implements Ocu_PinStateType_enumeration
*/
typedef enum
{
    /** @brief Ocu Pin level is logic low */
    OCU_LOW = 0,
    /** @brief Ocu Pin level is logic high */
    OCU_HIGH
} Ocu_PinStateType;


/**
* @brief      Ocu Count direction
* @details    This enum specifies the count direction for the whole OCU driver.
* 
*/
typedef enum
{
    OCU_UPCOUNTING = 0, /** @brief Counter in UP Counting */
    OCU_DOWNCOUNTING    /** @brief Counter in DOWN Counting. */
} Ocu_CountDirectionType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /*OCU_TYPES_H*/

/** @} */
