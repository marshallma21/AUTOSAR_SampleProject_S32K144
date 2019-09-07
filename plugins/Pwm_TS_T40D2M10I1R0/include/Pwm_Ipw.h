/**
*   @file           Pwm_Ipw.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Pwm IPW API.
*   @details        Pwm IPW API.
*
*   @addtogroup     PWM_MODULE
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

#ifndef PWM_IPW_H
#define PWM_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_IPW_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_IPW_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section Pwm_IPW_H_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer,
* a constant, a paranthesised expression, a type qualifier, a storage class specifier or 
* a  do-while-zero construct. 
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @violates @ref Pwm_IPW_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Ipw_Types.h"
#include "Pwm_Ftm.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ipw.h
*/
#define PWM_IPW_VENDOR_ID                         43
#define PWM_IPW_MODULE_ID                         121
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_REVISION_VERSION       2
#define PWM_IPW_SW_MAJOR_VERSION                  1
#define PWM_IPW_SW_MINOR_VERSION                  0
#define PWM_IPW_SW_PATCH_VERSION                  1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if header file and Pwm_Ipw_Types header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_Ipw.h and Pwm_Ipw_Types.h have different vendor ids"
#endif
/* Check if header file and Pwm_Ipw_Types header file are of the same Autosar version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different"
#endif
/* Check if header file and Pwm_Ipw_Types header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/
/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/




/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/
/*
* @violates Pwm_IPW_H_REF_2 Only preprocessor statements and comments before "#include"
*/

#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_IPW_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

FUNC (void, PWM_CODE) Pwm_Ipw_Init
(   
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);


#if (PWM_DE_INIT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_DeInit
(
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_DE_INIT_API */


#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetDutyCycle
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,                AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_DUTY_CYCLE_API */


#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetPeriodAndDuty
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,        AUTOMATIC)                 nPeriod,
    VAR         (uint16,                AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)

FUNC (void, PWM_CODE) Pwm_Ipw_SetOutputToIdle
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);

#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC(Pwm_OutputStateType,PWM_CODE) Pwm_Ipw_GetOutputState
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_GET_OUTPUT_STATE_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

FUNC (void, PWM_CODE) Pwm_Ipw_DisableNotification
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);

FUNC (void, PWM_CODE) Pwm_Ipw_EnableNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
    
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC(uint16, PWM_CODE) Pwm_Ipw_GetChannelState
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
   CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_GET_CHANNEL_STATE_API */

#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_ForceOutputToZero
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR(boolean,                            AUTOMATIC) bForce,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif


#if (PWM_SET_CLOCK_MODE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetClockMode
(
    VAR         (Pwm_PrescalerType,         AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateIdleState
(
    P2CONST     (Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);

FUNC(void, PWM_CODE) Pwm_Ipw_SetPowerState
(
    P2CONST     (Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pIpConfig,
    VAR         (Pwm_PowerStateType,AUTOMATIC)                 nPowerState
);
#endif

#if (PWM_SELECT_COMMON_TIMEBASE_API == STD_ON)
/**
 * @brief Mapping macro between get select global timebase functionality and high level function
 *
 */
 /*
* @violates @ref Pwm_IPW_H_REF_4 A function should be used in preference to a 
* function-like  macro.
*
* @violates @ref Pwm_IPW_H_REF_3 Function like macro. 
*/
#define Pwm_Ipw_SelectCommonTimebase(ModuleId, u16ElementSyncList)   Pwm_Ftm_SelectCommonTimebase((ModuleId), (u16ElementSyncList))

#endif /*PWM_SELECT_COMMON_TIMEBASE_API*/
#if (PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON)
#if (PWM_SYNC_UPDATE_API == STD_ON)

FUNC (void, PWM_CODE) Pwm_Ipw_SyncUpdate
(
    VAR(uint8, AUTOMATIC)  u8ModuleId
);
#endif /*PWM_SYNC_UPDATE_API*/
#if (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetPeriodAndDuty_NoUpdate
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,   AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API */
#if (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetDutyCycle_NoUpdate
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_DUTY_CYCLE_NO_UPDATE_API */
#endif /*PWM_UPDATE_DUTY_SYNCHRONOUS*/

#if (PWM_SET_PHASE_SHIFT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetPhaseShift
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16PhaseShift,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /*PWM_SET_PHASE_SHIFT_API*/
#if (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetPhaseShift_NoUpdate
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16PhaseShift,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_PHASE_SHIFT_NO_UPDATE_API */

#if (PWM_ENABLE_TRIGEER_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_EnableTrigger
(
    VAR(uint8, AUTOMATIC) u8TriggerHostId,
    VAR(uint16,AUTOMATIC) u16TriggerMask
);
#endif /*#if (PWM_ENABLE_TRIGEER_API == STD_ON)*/

#if (PWM_DISABLE_TRIGEER_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_DisableTrigger
(
    VAR(uint8, AUTOMATIC) u8TriggerHostId,
    VAR(uint16,AUTOMATIC) u16TriggerMask
);
#endif /*PWM_DISABLE_TRIGEER_API*/
#if (PWM_RESET_COUNTER_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_ResetCounterEnable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
);

FUNC (void, PWM_CODE) Pwm_Ipw_ResetCounterDisable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
);
#endif /*PWM_RESET_COUNTER_API*/
#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_MaskOutputs
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 ,         AUTOMATIC)     u8ChannelMask
);
FUNC (void, PWM_CODE) Pwm_Ipw_UnMaskOutputs
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 ,         AUTOMATIC)     u8ChannelMask
);
#endif /*PWM_ENABLE_MASKING_OPERATIONS*/   
#if (PWM_PARAM_CHECK == STD_ON) 
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8ChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateParamsPhaseShift
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR(uint16,          AUTOMATIC) u16PhaseShift
);
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateChannelSetPhaseShift
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 u8ChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#if ((PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
FUNC (uint8, PWM_CODE) Pwm_Ipw_ValidateChannelSync
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 u8ChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#if ((PWM_DISABLE_TRIGEER_API == STD_ON) || (PWM_ENABLE_TRIGEER_API == STD_ON))
FUNC (uint8, PWM_CODE) Pwm_Ipw_ValidateTriggerMask
(
    VAR(uint32,                         AUTOMATIC) u32TriggerMask
);
#endif

#endif /*(PWM_PARAM_CHECK == STD_ON)*/
/*
* @violates Pwm_IPW_H_REF_2 Only preprocessor statements and comments before "#include"
*/
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_IPW_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_IPW_H */

/** @} */
