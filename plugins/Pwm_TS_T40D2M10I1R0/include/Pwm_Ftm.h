/**
*   @file           Pwm_Ftm.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Pwm Ftm API.
*   @details        Pwm Ftm API.
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

#ifndef PWM_FTM_H
#define PWM_FTM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Ftm_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_Ftm_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Pwm_Ipw_Types.h"


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ftm.h
*/
#define PWM_FTM_VENDOR_ID                         43
#define PWM_FTM_MODULE_ID                         121
/* @violates @ref Pwm_Ftm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_Ftm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_Ftm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_AR_RELEASE_REVISION_VERSION       2
#define PWM_FTM_SW_MAJOR_VERSION                  1
#define PWM_FTM_SW_MINOR_VERSION                  0
#define PWM_FTM_SW_PATCH_VERSION                  1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if source file and PWM header file are of the same vendor */
#if (PWM_FTM_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_Ftm.h and Pwm_Ipw_Types.h have different vendor ids"
#endif

/* Check if source file and PWM header file are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.h and Pwm_Ipw_Types.h are different"
#endif

/* Check if source file and PWM header file are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_FTM_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Pwm_Ftm.h and Pwm_Ipw_Types.h are different"
#endif


/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/**
* @brief          Defines the value for 100% duty.
*/
#define PWM_FTM_DUTY_100   ((uint16)0x8000)

/**
* @brief          Defines the mask for the value of (100% - 1) duty.
*/
#define PWM_FTM_UPPER_LIMIT_DUTY_MASK   ((uint16)0x7FFF)


/**
* @brief          Defines the value for 0% duty.
*/
#define PWM_FTM_DUTY_0   ((uint16)0)


/**
* @brief          Defines the value for the running state of each FTM channel
*/
#define PWM_CHANNEL_RUNNING  ((uint8)1)


/**
* @brief          Defines the value for the idle state of each FTM channel
*/
#define PWM_CHANNEL_IDLE  ((uint8)0)

/**
* @brief          Defines the value for the idle state of each FTM channel
*/
#define PWM_CHANNEL_OUTPUT_FORCED  ((uint8)2)

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
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_Ftm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

FUNC (void, PWM_CODE) Pwm_Ftm_Init
(   
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);

#if (PWM_DE_INIT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_DeInit
(   
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
FUNC (void, PWM_CODE) Pwm_Ftm_SetDutyCycle
(
    VAR         (uint8,                     AUTOMATIC)                  u8IdxChannelConfig,
    VAR         (uint16,                    AUTOMATIC)                  u16DutyCycle,
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    VAR         (Pwm_DataUdateType,         AUTOMATIC)                  eSyncUpdate,
#endif
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
);
#endif

#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
FUNC (void, PWM_CODE) Pwm_Ftm_SetPeriodAndDuty
(
    VAR         (uint8,                     AUTOMATIC)                  u8IdxChannelConfig,
    VAR         (Pwm_PeriodType,            AUTOMATIC)                  nPeriod,
    VAR         (uint16,                    AUTOMATIC)                  u16DutyCycle,
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    VAR         (Pwm_DataUdateType,         AUTOMATIC)                  eSyncUpdate,
#endif
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */



#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_SetOutputToIdle
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif /* ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_DE_INIT_API == STD_ON)) */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC(Pwm_OutputStateType,PWM_CODE) Pwm_Ftm_GetOutputState
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif /* PWM_GET_OUTPUT_STATE_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

FUNC (void, PWM_CODE) Pwm_Ftm_DisableNotification
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);

FUNC (void, PWM_CODE) Pwm_Ftm_EnableNotification
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC(uint16, PWM_CODE) Pwm_Ftm_GetChannelState
( 
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif /* PWM_GET_CHANNEL_STATE_API */

#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_ForceOutputToZero
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (boolean,                   AUTOMATIC)                 bForce,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif

#if (PWM_SET_CLOCK_MODE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_SetClockMode
(
    VAR         (Pwm_PrescalerType,        AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,     AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
#endif
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ftm_ValidateIdleState
(
    P2CONST(Pwm_Ftm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
);
FUNC(void, PWM_CODE) Pwm_Ftm_SetPowerState
(
    P2CONST(Pwm_Ftm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST)   pFtmIpConfig,
    VAR    (Pwm_PowerStateType,          AUTOMATIC)                 nPowerState
);
#endif
#if (PWM_SELECT_COMMON_TIMEBASE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_Ftm_SelectCommonTimebase
(
    VAR (uint8,                            AUTOMATIC)                u8FtmModule,
    VAR (uint16,                           AUTOMATIC)                u16ElementSyncList
);
#endif

#if (PWM_SYNC_UPDATE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_Ftm_SyncUpdate
( 
    VAR(uint8,              AUTOMATIC) u8HwModule
);
#endif /* PWM_SYNC_UPDATE_API */

#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
FUNC (void, PWM_CODE) Pwm_Ftm_SetPhaseShift
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (uint16,                    AUTOMATIC)                 u16Period,
    VAR         (uint16,                    AUTOMATIC)                 u16PhaseShift,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)     pFtmIpConfig,
    VAR         (boolean,                 AUTOMATIC)                     bLoad
);
#endif

#if (PWM_ENABLE_TRIGEER_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_EnableTrigger 
(
    VAR(uint8, AUTOMATIC)              u8TriggerHostId,
    VAR(uint16,AUTOMATIC)              u16TriggerMask
);
#endif /*#if (PWM_ENABLE_TRIGEER_API == STD_ON)*/

#if (PWM_DISABLE_TRIGEER_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_DisableTrigger 
(
    VAR(uint8, AUTOMATIC)              u8TriggerHostId,
    VAR(uint16,AUTOMATIC)              u16TriggerMask
);
#endif /*PWM_DISABLE_TRIGEER_API*/
#if (PWM_RESET_COUNTER_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_ResetCounterEnable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
);

FUNC (void, PWM_CODE) Pwm_Ftm_ResetCounterDisable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
);

#endif /*PWM_RESET_COUNTER_API*/

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ftm_MaskOutputs 
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 , AUTOMATIC)             u8ChannelMask
);

FUNC (void, PWM_CODE) Pwm_Ftm_UnMaskOutputs 
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 , AUTOMATIC)             u8ChannelMask
);
#endif /*PWM_ENABLE_MASKING_OPERATIONS*/

#if (PWM_PARAM_CHECK == STD_ON)
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ftm_ValidateNotification
(
    VAR         (uint8,                   AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
);
#endif

#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
FUNC(uint8, PWM_CODE) Pwm_Ftm_ValidateChannelSetPhaseShift
/* @violates @ref Pwm_Ftm_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (uint8,                   AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
);
#endif
#if ((PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
FUNC(uint8, PWM_CODE) Pwm_Ftm_ValidateChannelSync
/* @violates @ref Pwm_Ftm_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (uint8,                   AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
);
#endif
#if ((PWM_DISABLE_TRIGEER_API == STD_ON) || (PWM_ENABLE_TRIGEER_API == STD_ON))
FUNC(uint8, PWM_CODE) Pwm_Ftm_ValidateTriggerMask
/* @violates @ref Pwm_Ftm_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR(uint32,                         AUTOMATIC) u32TriggerMask
);
#endif

#endif /*(PWM_PARAM_CHECK == STD_ON)*/

#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_Ftm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* PWM_FTM_H */
/** @} */
