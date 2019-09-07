/**
*   @file       Pwm_Types.h
*   @version    1.0.1
*
*   @brief      AUTOSAR Pwm - Pwm generic types file.
*   @details    Contains generic Pwm types and structures.
*
*   @addtogroup PWM_MODULE
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

#ifndef PWM_TYPES_H
#define PWM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Types_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_Types_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref Pwm_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Std_Types.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Types.h
*/
#define PWM_TYPES_VENDOR_ID                         43
#define PWM_TYPES_MODULE_ID                         121
/* @violates @ref Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_TYPES_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_TYPES_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_TYPES_AR_RELEASE_REVISION_VERSION       2
#define PWM_TYPES_SW_MAJOR_VERSION                  1
#define PWM_TYPES_SW_MINOR_VERSION                  0
#define PWM_TYPES_SW_PATCH_VERSION                  1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((PWM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm_Types.h and Std_Types.h are different"
#endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief      Output signal level
* @details    This enum specifies the return type of Pwm_GetOutputState
* 
* @implements Pwm_OutputStateType_enumeration
*/
typedef enum
{
    /** @brief Pwm level is logic low */
    PWM_LOW = 0,
    /** @brief Pwm level is logic high */
    PWM_HIGH
} Pwm_OutputStateType;


/**
* @brief      Prescaler type
* @details    This enum specifies the possible types of prescallers used to configure base-clock timers
*
*/
typedef enum
{
    /** @brief Selected value is the default/primary prescaler */
    PWM_PRIMARY_PRESCALER = 0,
    /** @brief Selected value is the alternative configured prescaler */
    PWM_ALTERNATIVE_PRESCALER
} Pwm_PrescalerType;


/**
* @brief      Edge notification type
* @details    This enum defines the type of edge tranzition that can  generate a notification
* @implements Pwm_EdgeNotificationType_enumeration
*/
typedef enum
{
    /** @brief A notification will be generated on the rising edge */
    PWM_RISING_EDGE = 1,
    /** @brief A notification will be generated on the falling edge */
    PWM_FALLING_EDGE,
    /** @brief A notification will be generated on any state transition */
    PWM_BOTH_EDGES
} Pwm_EdgeNotificationType;

/**
* @brief      Power state type
* @details    Power state currently active or set as target power state.
* @implements Pwm_PowerStateType_enumeration
* 
*/
typedef enum
{
    /** @brief Pwm full power mode */
    PWM_FULL_POWER = 0,
    /** @brief Pwm low power mode */
    PWM_LOW_POWER,
    /** @brief Pwm no define power mode */
    PWM_NODEFINE_POWER
} Pwm_PowerStateType;

/**
* @brief      Result of power state type
* @details    Result of the requests related to power state transitions.
* @implements Pwm_PowerStateRequestResultType_enumeration
* 
*/
typedef enum
{
    /** @brief Power state change executed.*/
    PWM_SERVICE_ACCEPTED = 0,
    /** @brief Module not initialized.*/
    PWM_NOT_INIT,
    /** @brief Wrong API call sequence.*/
    PWM_SEQUENCE_ERROR,
    /** @brief The HW module has a  failure which prevents  it  to enter the required power state.*/
    PWM_HW_FAILURE,
    /** @brief Module  does  not  support  the  requested power state.*/
    PWM_POWER_STATE_NOT_SUPP,
    /** @brief Module  cannot  transition  directly  from  the current power state to the requested power state*/
    PWM_TRANS_NOT_POSSIBLE
} Pwm_PowerStateRequestResultType;



/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief      Pwm channel type
* @implements Pwm_ChannelType_typedef
*/
typedef uint8 Pwm_ChannelType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /*PWM_TYPES_H*/

/** @} */
