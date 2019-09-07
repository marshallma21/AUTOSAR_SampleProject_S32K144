/**
*   @file       Pwm_Cfg.h
*   @version    1.0.1
*
*   @brief      AUTOSAR Pwm - Pwm configuration file.
*   @details    Precompile parameters and extern configuration.
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


#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer,
* a constant, a paranthesised expression, a type qualifier, a storage class specifier or 
* a  do-while-zero construct. 
* Macro used to define external constant in order to reduce code complexity.*
*
* @section Pwm_Cfg_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
* are accessed from within a sigle function.
* These symbols are used in the entire driver.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref Pwm_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Pwm_EnvCfg.h"
#include "Pwm_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Cfg.h
*/
#define PWM_CFG_VENDOR_ID                         43
#define PWM_CFG_MODULE_ID                         121

#define PWM_CFG_AR_RELEASE_MAJOR_VERSION          4
#define PWM_CFG_AR_RELEASE_MINOR_VERSION          2
#define PWM_CFG_AR_RELEASE_REVISION_VERSION       2
#define PWM_CFG_SW_MAJOR_VERSION                  1
#define PWM_CFG_SW_MINOR_VERSION                  0
#define PWM_CFG_SW_PATCH_VERSION                  1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PWM_CFG_VENDOR_ID != PWM_CFG_ENV_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_CfgEnv.h have different vendor ids"
#endif
/* Check if current file and Pwm_CfgEnv header file are of the same Autosar version */
#if (( PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_CFG_ENV_AR_RELEASE_MAJOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_CFG_ENV_AR_RELEASE_MINOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_REVISION_VERSION !=  PWM_CFG_ENV_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_CfgEnv.h are different"
#endif
/* Check if current file and Pwm_CfgEnv header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_CFG_ENV_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_CFG_ENV_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_CFG_ENV_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pwm_Cfg.h and Pwm_CfgEnv.h are different"
#endif

#if (PWM_CFG_VENDOR_ID != PWM_TYPES_VENDOR_ID)
    #error "Pwm_Cfg.h and Pwm_Types.h have different vendor ids"
#endif
/* Check if current file and Pwm_Types header file are of the same Autosar version */
#if (( PWM_CFG_AR_RELEASE_MAJOR_VERSION != PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_MINOR_VERSION != PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     ( PWM_CFG_AR_RELEASE_REVISION_VERSION !=  PWM_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Pwm_Cfg.h and Pwm_Types.h are different"
#endif
/* Check if current file and Pwm_Types header file are of the same software version */
#if ((PWM_CFG_SW_MAJOR_VERSION != PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_CFG_SW_MINOR_VERSION != PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_CFG_SW_PATCH_VERSION != PWM_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Pwm_Cfg.h and Pwm_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          API service ID
*/
#define PWM_PROCESSNOTIFICATION_ID        (0x0AU)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/



/**
* @brief      Pwm Pre Compile Switch
*/
/**
 *   @brief Pre-compile configuration constants 
 */

#define PWM_PRECOMPILE_SUPPORT          (STD_OFF)


/**
* @brief      Switch to indicate that Pwm_DeInit API is supported
*
*/
#define PWM_DE_INIT_API                   (STD_ON)

/**
* @brief      Switch to indicate that Pwm_GetOutputState API is supported
*
*/
#define PWM_GET_OUTPUT_STATE_API          (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetDutyCycle API is supported
*
*/
#define PWM_SET_DUTY_CYCLE_API            (STD_ON)

/**
* @brief      Switch to indicate that Pwm_SetOutputToIdle API is supported
*
*/
#define PWM_SET_OUTPUT_TO_IDLE_API        (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetPeriodAndDuty API is supported
*
*/
#define PWM_SET_PERIOD_AND_DUTY_API       (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_GetVersionInfo API is supported
*
*/
#define PWM_VERSION_INFO_API              (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_GetChannelState API is supported
*
*/
#define PWM_GET_CHANNEL_STATE_API         (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_ForceOutputToZero API is supported
*
*/
#define PWM_FORCE_OUTPUT_TO_ZERO_API       (STD_OFF)

/**
* @brief      Switch for enabling the development error detection.
*
*/
#define PWM_DEV_ERROR_DETECT              (STD_ON)

/**
* @brief      Switch for enabling the update of the duty cycle parameter at the end of 
*             the current period
*
*/
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD   (STD_ON)

/**
* @brief      Switch for enabling the update of the period parameter at the end of the current period
*
*/
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD (STD_ON)

/**
* @brief      Switch to indicate that the notifications are supported
*
*/
#define PWM_NOTIFICATION_SUPPORTED        (STD_ON)

/**
* @brief      Switch to indicate that the Reload notifications are supported
*
*/
#define PWM_RELOAD_NOTIF_SUPPORTED        (STD_OFF)

/**
* @brief      Switch for enabling the fault functionality
*
*/
#define PWM_FAULT_SUPPORTED               (STD_OFF)


/**
* @brief      Switch to indicate that Pwm_SetChannelOutput API is supported
*
*/
#define PWM_SET_CHANNEL_OUTPUT_API         (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetTriggerDelay API is supported
*
*/
#define PWM_SET_TRIGGER_DELAY_API          (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_BufferTransferEnableDisable API is supported
*
*/
#define PWM_BUFFER_TRANSFER_EN_DIS_API     (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SetCounterBus API is supported
*
*/
#define PWM_SET_COUNTER_BUS_API            (STD_OFF)

/**
* @brief      Switch for enabling the dual clock functionality (Pwm_SetClockMode API)
*
*/
#define PWM_SET_CLOCK_MODE_API            (STD_OFF)

/**
* @brief      Switch for enabling Pwm_SetPhaseShift API
*
*/
#define PWM_SET_PHASE_SHIFT_API            (STD_OFF)
/**
* @brief      Switch for enabling Pwm_SetPhaseShift_NoUpdate API
*
*/
#define PWM_SET_PHASE_SHIFT_NO_UPDATE_API            (STD_OFF)

/**
* @brief      Switch for enabling Pwm_EnableTrigger API
*
*/
#define PWM_ENABLE_TRIGEER_API            (STD_OFF)

/**
* @brief      Switch for enabling Pwm_DisableTrigger API
*
*/
#define PWM_DISABLE_TRIGEER_API            (STD_OFF)

/**
* @brief      Switch for enabling Pwm_SwResetCounter API
*
*/
#define PWM_RESET_COUNTER_API            (STD_OFF)

/**
* @brief      Switch for enabling MaskOutput API
*
*/
#define PWM_ENABLE_MASKING_OPERATIONS            (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SyncUpdate API is supported
*
*/
#define PWM_SYNC_UPDATE_API                    (STD_OFF)

/**
* @brief      Switch to indicate that the notifications are supported
*
*/
#define PWM_UPDATE_DUTY_SYNCHRONOUS       (STD_OFF)

/**
* @brief      Switch to indicate that PwmSetDutyCycle_NoUpdate API is supported
*
*/
#define PWM_SET_DUTY_CYCLE_NO_UPDATE_API       (STD_OFF)


/**
* @brief      Switch to indicate that PwmSetPeriodAndDuty_NoUpdate API is supported
*
*/
#define PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API  (STD_OFF)

/**
* @brief      Switch to indicate that Pwm_SelectCommonTimebase API is supported
*
*/
#define PWM_SELECT_COMMON_TIMEBASE_API         (STD_ON)

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'TRUE' the Pwm driver code can be executed from both supervisor and user mode.
*
*/  
#define PWM_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

/* @brief common interrupt */
#define PWM_FTM_MODULE_SINGLE_INTERRUPT  (STD_OFF)

/**
* @brief      Specifies the InstanceId of this module instance.
* @details    Specifies the InstanceId of this module instance.
*             If only one instance is present it shall have the Id 0.
*             Not used in the current implementation
*
*/
#define PWM_INDEX                         (0U)


/**
* @brief      Switch to indicate that platform-specific validations of the notification function are supported
*
*/
#define PWM_NOTIFICATON_PLAUSABILITY          (STD_ON)

/**
* @brief      Switch to indicate that platform-specific validation of the offset (phase shift) of duty-cycle is supported
*
*/
#define PWM_OFFSET_PLAUSABILITY               (STD_OFF)

/**
* @brief      Switch to indicate that platform-specific validation of the period is supported
*
*/
#define PWM_MAX_PERIOD_PLAUSABILITY           (STD_OFF)
/**
* @brief      Switch for enabling external trigger generation
*
*/
#define PWM_FTM_ENABLE_EXT_TRIGGERS            (STD_OFF)

/**
* @brief      Switch for enabling phase shift feature
*
*/
#define PWM_ENABLE_PHASE_SHIFT                  (STD_OFF)

/**
* @brief      FTM is not supported
*
*/
#define PWM_ALLOW_SUBMODULE_SYNC            (STD_OFF)

/**
* @brief Symbolic Names for configured channels - legacy
*/
#define PwmChannel_0         ((Pwm_ChannelType)0U)
#define PwmChannel_1         ((Pwm_ChannelType)1U)
#define PwmChannel_2         ((Pwm_ChannelType)2U)

/** 
* @brief           Symbolic Names for configured channels - ecuc 2108 compliant.
*/

 #define  PwmConf_PwmChannelConfigSet_PwmChannel_0         ((Pwm_ChannelType)0U)
 #define  PwmConf_PwmChannelConfigSet_PwmChannel_1         ((Pwm_ChannelType)1U)
 #define  PwmConf_PwmChannelConfigSet_PwmChannel_2         ((Pwm_ChannelType)2U)

/** @brief Macros used to lock for Pwm mode Ftm modules in current configuration */
#define PWM_FTM_0_USED
#define PWM_FTM_2_USED

/**
* @brief ISRs configured for Pwm channels
*
@{
*/
#define PWM_FTM_0_CH_0_CH_1_ISR_USED
#define PWM_FTM_0_CH_2_CH_3_ISR_USED


/**
* @brief ISRs configured for OVF
*
@{
*/




/*@brief This define specifies the number of fault channels per module */
#define PWM_FTM_MODULE_FAULT_NO         4U

/* @brief maximum number of FTM modules configurable on this platform */
#define PWM_FTM_MODULE_NO  (4UL)

/* @brief This define specifies the number of channels per each module */
#define PWM_FTM_MODULE_CHANNELS_NO   8U

/* @brief maximum number of FTM hardware channels */
#define PWM_FTM_CHANNELS_NO        (PWM_FTM_MODULE_CHANNELS_NO * PWM_FTM_MODULE_NO)

/* @brief maximum number of hardware channels and modules configurable on this platform = modules * channels */
#define PWM_HW_CHANNELS_NO_U8        (PWM_FTM_CHANNELS_NO)

#define PWM_HW_MODULES_CFG_U8        (PWM_FTM_MODULE_NO)

/** @brief Symbolic Name for period det error */
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
    #define PWM_E_PERIODVALUE       (0x1AU)
#endif

/** @brief Defines the maximum value of the period - this value is hardware/platform dependent */
#define PWM_MAX_PERIOD              (0xFFFFU)

/** @brief Maximum number of FTM channels configured */

#define PWM_FTM_CHANNELS_MAX_U8    (5U)


/**
* @brief   Switch to enable that power state mode is supported
*
*/

#define PWM_POWER_STATE_SUPPORTED  (STD_OFF)

#define PWM_POWER_STATE_ASYNCH_MODE_SUPPORTED  (STD_OFF)

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
/* @violates @ref Pwm_Cfg_H_REF_3 MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer */
#define PWM_CONF_PB \
 extern CONST(Pwm_ConfigType, PWM_CONST) PwmChannelConfigSet;

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief      Pwm Period type (the value of the period is platform dependent and thus configurable)
* @implements Pwm_PeriodType_typedef
*/
typedef uint16 Pwm_PeriodType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /*PWM_CFG_H*/

/** @} */

