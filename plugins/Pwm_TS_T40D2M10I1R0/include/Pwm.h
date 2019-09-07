/**
*   @file           Pwm.h
*   @implements     Pwm.h_Artifact
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Pwm module API header.
*   @details        Pwm module API header.
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

#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Pwm.h
*/
/*
* @violates @ref Pwm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"
/*
* @violates @ref Pwm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Cfg.h"
#include "Pwm_Ipw_Types.h"
#include "Mcal.h"
/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm.h
*/
#define PWM_VENDOR_ID                       43
#define PWM_MODULE_ID                       121
#define PWM_AR_RELEASE_MAJOR_VERSION        4
#define PWM_AR_RELEASE_MINOR_VERSION        2
#define PWM_AR_RELEASE_REVISION_VERSION     2
#define PWM_SW_MAJOR_VERSION                1
#define PWM_SW_MINOR_VERSION                0
#define PWM_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm.h and Std_Types.h are different"
#endif

/* Check if header file and Mcal.h are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm.h and Mcal.h are different"
#endif

#endif


/* Check if header file and Pwm_Ipw_Types header file are of the same vendor */
#if (PWM_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm.h and Pwm_Ipw_Types.h have different vendor ids"
#endif
/* Check if header file and Pwm_Ipw_Types header file are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm.h and Pwm_Ipw_Types.h are different"
#endif
/* Check if header file and Pwm_Ipw_Types header file are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm.h and Pwm_Ipw_Types.h are different"
#endif


/* Check if header file and Pwm_Cfg header file are of the same vendor */
#if (PWM_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if header file and Pwm_Cfg header file are of the same Autosar version */
#if ((PWM_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif
/* Check if header file and Pwm_Cfg header file are of the same software version */
#if ((PWM_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm.h and Pwm_Cfg.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/
/**
* @brief            100% dutycycle
* @details          Errors and exceptions that will be detected by the PWM driver generated when
*                   Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value for dutycyle
*                   out of valid range [0x0000, 0x8000]
*/
#define PWM_DUTY_CYCLE_100              ((uint16)0x8000U)


/**
* @brief            API Pwm_Init service called with wrong parameter
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_INIT_FAILED               (0x10U)
/**
* @brief            API service used without module initialization
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_UNINIT                    (0x11U)

/**
* @brief            API service used with an invalid channel Identifier
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_PARAM_CHANNEL             (0x12U)

/**
* @brief            Usage of unauthorized PWM service on PWM channel configured a fixed period
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_PERIOD_UNCHANGEABLE       (0x13U)

/**
* @brief            API Pwm_Init service called while the PWM driver has already been initialised
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_ALREADY_INITIALIZED       (0x14U)
/**
* @brief            Generated when a NULL pointer is passed to Pwm_GetVersionInfo function
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_PARAM_POINTER             (0x15U)

/**
* @brief            Generated when Pwm_SetPowerState is called while the PWM module is still in use.
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_NOT_DISENGAGED             (0x16U)

/**
* @brief            The requested power state is not supported by the PWM module.
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_POWER_STATE_NOT_SUPPORTED  (0x17U)

/**
* @brief            Generated The requested power state is not reachable from the current one.
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_TRANSITION_NOT_POSSIBLE             (0x18U)

/**
* @brief            Generated when Pwm_SetPowerState has been called without having called the API
*                   Pwm_PreparePowerState before.
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_PERIPHERAL_NOT_PREPARED             (0x19U)

/**
* @brief            Invalid polarity selected for edge notification
* @details          Will be generated when an invalid polarity, edge notification is requested for one pwm channel.
*                   Due to the limitations that are present in the eMIOS implementation not all
*                   the polarity notifications combinations can be supported.
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_PARAM_NOTIFICATION        (0x30U)

/**
* @brief            NULL function is configured as notification callback
* @details          Will be generated when a NULL function is configured as notification callback for
*                   one pwm channel and Pwm_EnableNotification is called for that channel
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_PARAM_NOTIFICATION_NULL   (0x31U)

/**
* @brief            Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty called with invalid dutycycle range
* @details          Generated when Pwm_SetDutyCycle or Pwm_SetPeriodAndDuty are called with a value
*                   for dutycyle out of valid range [0x0000, 0x8000]
* @implements       Pwm_ErrorIds_define AUTOSAR
*/
#define PWM_E_DUTYCYCLE_RANGE           (0x32U)

/**
* @brief            Generated when Pwm_SetCounterBus is called with an invalid Bus
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
#define PWM_E_COUNTERBUS                (0x33U)

/**
* @brief            Generated when the configured offset for the OPWMB channel is more than the period
*                   of the associated MCB channel
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
#define PWM_E_CHANNEL_OFFSET_VALUE      (0x34U)


/**
* @brief            Generated when the requested offset value plus the current requested dutycycle leads to
*                   programming event B over the Period value leading to unexpected behavior of the pwm signal
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE     (0x35U)

/**
* @brief            Generated when the module id is more than the number of module that supported by
*                   this platform
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
#define PWM_E_PARAM_INSTANCE            (0x36U)

/**
* @brief            Generated when the configured trigger value for the OPWMTchannel is >= than the period
*                   of the channel
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR 
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_E_OPWMT_CHANNEL_TRIGGER_RANGE              (0x37U)


/**
* @brief            Generated when the ouput state value for the SetChannelOutput
*                   of the channel
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR 
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_E_OUTPUT_STATE                          (0x38U)

/**
* @brief            Generated when an ISR has been triggered 
*                    1. when the driver is not initialized
*                    2. for a Hw channel that is not used by any logic channel
*                    3. for a logic channel that has no notification configured
* @details          Errors and exceptions that will be detected by the PWM driver
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
#define PWM_E_UNEXPECTED_ISR                        (0x39U)
/**
* @brief            Generated when requested phase shift value greater than 0x4000 (50%)
* @details          Pwm_SetPhaseShift only works with Combine channel (COMBINED_SYNCED or COMBINED_COMPLEMENTARY)
*                   Which do not support matching at next cycle.
*                   The duty cycle is always fixed value at 50%, so Phase Shift cannot greater than 50%
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
#define PWM_E_PARAM_PHASESHIFT_RANGE                        (0x3AU)

/**
* @brief            Generated when given channel other than combine channel edge setup
*                   (COMBINED_SYNCED and COMBINED_COMPLEMENTARY)
* @details          Modified Combine mode also supports change phase shift runtime but updating is asynchronous,
*                   Therefore only normal Combine mode (COMBINED_SYNCED and COMBINED_COMPLEMENTARY) is supported
*                   by Pwm_SetPhaseShift
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_E_CHANNEL_PHASE_SHIFT_WITHOUT_COMBINE                        (0x3BU)

/**
* @brief            Generated when given channel is Modified Combine channel edge setup
*                   (PHASE_SHIFTED_SYNCED and PHASE_SHIFTED_COMPLEMENTARY)
* @details          Please note that Modified Combine mode does not support synchronous update Cn
*                   Therefore Pwm_SetDutyCycle_NoUpdate and Pwm_SetPeriodAndDuty_NoUpdate should not 
*                   be called in this case.
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_E_PARAM_SYNCHRONOUS_MODIFIED_COMBINE                        (0x3CU)

/**
* @brief            Generated when bit mask is not compatible with  hardware register
*                   
* @details          
* @implements       Pwm_ErrorIds_define Non-AUTOSAR
*/
#define PWM_E_TRIGGER_MASK                        (0x3DU)
/**
* @brief            API service ID of Pwm_Init function
* @details          Parameters used when raising an error/exception
*/
#define PWM_INIT_ID                (0x00U)

/**
* @brief            API service ID of Pwm_DeInit function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DEINIT_ID              (0x01U)

/**
* @brief            API service ID of Pwm_SetDutyCycle function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETDUTYCYCLE_ID        (0x02U)

/**
* @brief            API service ID of Pwm_SetPeriodAndDuty function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPERIODANDDUTY_ID    (0x03U)

/**
* @brief            API service ID of Pwm_SetOutputToIdle function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETOUTPUTTOIDLE_ID     (0x04U)

/**
* @brief            API service ID of Pwm_GetOutputState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETOUTPUTSTATE_ID      (0x05U)

/**
* @brief            API service ID of Pwm_DisableNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLENOTIFICATION_ID (0x06U)

/**
* @brief            API service ID of Pwm_EnableNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLENOTIFICATION_ID  (0x07U)

/**
* @brief            API service ID of Pwm_GetVersionInfo function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETVERSIONINFO_ID      (0x08U)

/**
* @brief            API service ID of Pwm_SetPowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPOWERSTATE_ID      (0x09U)

/**
* @brief            API service ID of Pwm_GetCurrentPowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETCURRENTPOWERSTATE_ID (0x0AU)

/**
* @brief            API service ID of Pwm_GetTargetPowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETTARGETPOWERSTATE_ID  (0x0BU)

/**
* @brief            API service ID of Pwm_PreparePowerState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_PREPAREPOWERSTATE_ID    (0x0CU)

/**
* @brief            API service ID of Pwm_Main_PowerTransitionManager function
* @details          Parameters used when raising an error/exception
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_MAIN_POWERTRTANSITIONMANAGER (0x0DU)


/**
* @brief            API service ID of Pwm_GetChannelState function
* @details          Parameters used when raising an error/exception
*/
#define PWM_GETCHANNELSTATE_ID     (0x20U)

/* @brief            API service ID of Pwm_ForceOutputToZero function
* @details          Parameters used when raising an error/exception
*/
#define PWM_FORCEOUTPUTTOZERO_ID   (0x21U)

/**
* @brief            API service ID of Pwm_SetCounterBus function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCOUNTERBUS_ID       (0x22U)

/**
* @brief            API service ID of Pwm_SetChannelOutput function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCHANNELOUTPUT_ID    (0x23U)

/**
* @brief            API service ID of Pwm_SetTriggerDelay function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETTRIGGERDELAY_ID     (0x24U)

/**
* @brief            API service ID of Pwm_BufferTransferEnableDisable function
* @details          Parameters used when raising an error/exception
*/
#define PWM_BUFFERTRANSFERENDIS_ID      (0x26U)

/**
* @brief            API service ID of Pwm_SetClockMode function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETCLOCKMODE_ID      (0x27U)

/**
* @brief            API service ID of Pwm_SyncUpdate function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SYNCUPDATE_ID      (0x28U)

/**
* @brief            API service ID of Pwm_SetPeriodAndDuty_NoUpdate function
* @details          Parameters used when raising an error/exception
*/
/* @violates @ref Pwm_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_SETPERIODANDDUTY_NO_UPDATE_ID      (0x29U)


/**
* @brief            API service ID of Pwm_SetDutyCycle_NoUpdate function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETDUTYCYCLE_NO_UPDATE_ID      (0x2AU)

/**
* @brief            API service ID of Pwm_SelectCommonTimebase function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SELECTCOMMONTIMEBASE_ID      (0x2BU)

/**
* @brief            API service ID of Pwm_SetPhaseShift function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPHASESHIFT_ID      (0x2CU)
/**
* @brief            API service ID of Pwm_SetPhaseShift function
* @details          Parameters used when raising an error/exception
*/
#define PWM_SETPHASESHIFTNOUPDATE_ID      (0x2DU)

/**
* @brief            API service ID of Pwm_EnableTrigger function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLETRIGGER_ID      (0x2EU)

/**
* @brief            API service ID of Pwm_DisableTrigger function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLETRIGGER_ID      (0x2FU)

/**
* @brief            API service ID of Pwm_ResetCounterEnable function
* @details          Parameters used when raising an error/exception
*/
#define PWM_RESETCOUNTERENABLE_ID      (0x30U)

/**
* @brief            API service ID of Pwm_ResetCounterDisable function
* @details          Parameters used when raising an error/exception
*/
#define PWM_RESETCOUNTERDISABLE_ID     (0x31U)

/**
* @brief            API service ID of Pwm_MaskOutputs function
* @details          Parameters used when raising an error/exception
*/
#define PWM_MASKOUTPUT_ID      (0x32U)

/**
* @brief            API service ID of Pwm_UnMaskOutputs function
* @details          Parameters used when raising an error/exception
*/
#define PWM_UNMASKOUTPUT_ID      (0x33U)

/**
* @brief            API service ID of Pwm_DisableReloadNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_DISABLERELOADNOTIF_ID      (0x34U)

/**
* @brief            API service ID of Pwm_EnableReloadNotification function
* @details          Parameters used when raising an error/exception
*/
#define PWM_ENABLERELOADNOTIF_ID      (0x35U)

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/
/**
* @brief      Pwm channel type
* @details    This field will specify what parameters can be altered for the selected channel
* @implements Pwm_ChannelClassType_enumeration
*/
typedef enum
{
    /** @brief The period and duty cycle can be altered */
    PWM_VARIABLE_PERIOD = 0,
    /** @brief Only the duty cycle can be altered */
    PWM_FIXED_PERIOD,
    /** @brief Only the duty cycle can be altered */
    PWM_FIXED_PERIOD_SHIFTED
} Pwm_ChannelClassType;

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/
/**
* @brief      Channel notification typedef
*/
typedef void (*Pwm_NotifyType)(void);


/**
* @brief      Pwm channel high level configuration structure
* @implements Pwm_ChannelConfigType_struct
*/
typedef struct 
{
    /** @brief Channel class type: Variable/Fixed period */
    CONST(Pwm_ChannelClassType, PWM_CONST) ePwmChannelClass;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief Pointer to notification function */
    CONST(Pwm_NotifyType,       PWM_CONST) pfPwmChannelNotification;
#endif /*(PWM_NOTIFICATION_SUPPORTED == STD_ON)*/

} Pwm_ChannelConfigType;


/**
* @brief      Pwm high level configuration structure
* @implements Pwm_ConfigType_struct
*/
typedef struct 
{
    /** @brief Number of Pwm configured channels */
    CONST   (Pwm_ChannelType,       PWM_CONST)   nNumChannels;   
    /** @brief Pointer to the list of Pwm configured channels */
    CONST   (Pwm_ChannelConfigType, PWM_CONST)   (*pPwmChannelsConfig)[]; 
    /** @brief Combined IP specific configuration structure */       
    CONST   (Pwm_IpConfigType,      PWM_CONST)   IpConfig;       
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief Index table to translate HW channels to logical used 
    to process interrupts for notifications */
    CONST   (Pwm_ChannelType,       PWM_CONST)  HwToLogicChannelMap[PWM_HW_CHANNELS_NO_U8];
#endif
} Pwm_ConfigType;


/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"
#if (PWM_PRECOMPILE_SUPPORT != STD_ON)
PWM_CONF_PB
#endif
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Pwm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

/*===============================================================================================*/

FUNC (void, PWM_CODE) Pwm_Init
(
    P2CONST(Pwm_ConfigType, AUTOMATIC, PWM_APPL_CONST) ConfigPtr
);

/*===============================================================================================*/

#if (PWM_DE_INIT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_DeInit
(   
    void
);
#endif

/*===============================================================================================*/

#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetDutyCycle
(
    VAR(Pwm_ChannelType,            AUTOMATIC) ChannelNumber,
    VAR(uint16,                     AUTOMATIC) u16DutyCycle
);
#endif

/*===============================================================================================*/

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetPeriodAndDuty
(
    VAR(Pwm_ChannelType,            AUTOMATIC) ChannelNumber,
    VAR(Pwm_PeriodType,             AUTOMATIC) Period,
    VAR(uint16,                     AUTOMATIC) u16DutyCycle
);
#endif

/*===============================================================================================*/

#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetOutputToIdle
(
    VAR(Pwm_ChannelType,            AUTOMATIC) ChannelNumber
);
#endif

/*===============================================================================================*/

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC (Pwm_OutputStateType, PWM_CODE) Pwm_GetOutputState
(
    VAR(Pwm_ChannelType,            AUTOMATIC) ChannelNumber
);
#endif

/*===============================================================================================*/

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, PWM_CODE) Pwm_EnableNotification
(
    VAR(Pwm_ChannelType,            AUTOMATIC) ChannelNumber,
    VAR(Pwm_EdgeNotificationType,   AUTOMATIC) Notification
);
#endif

/*===============================================================================================*/

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, PWM_CODE) Pwm_DisableNotification
(
    VAR(Pwm_ChannelType,            AUTOMATIC) ChannelNumber
);
#endif

/*===============================================================================================*/

#if (PWM_VERSION_INFO_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType ,     AUTOMATIC, PWM_APPL_DATA) pVersioninfo
);
#endif

/*===============================================================================================*/

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC(uint16, PWM_CODE) Pwm_GetChannelState
(
   VAR(Pwm_ChannelType,             AUTOMATIC) ChannelNumber
);
#endif

/*===============================================================================================*/

#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_ForceOutputToZero
(
    VAR(Pwm_ChannelType,        AUTOMATIC) ChannelNumber,
    VAR(boolean,                AUTOMATIC) bForce
);
#endif

/*===============================================================================================*/

#ifdef PWM_SET_COUNTER_BUS_API
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetCounterBus
(
    VAR(Pwm_ChannelType,        AUTOMATIC) ChannelNumber,
    VAR(uint32,                 AUTOMATIC) u32Bus
);
#endif
#endif /* PWM_SET_COUNTER_BUS_API */


/*===============================================================================================*/
#ifdef PWM_SET_CHANNEL_OUTPUT_API
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetChannelOutput
(
    VAR(Pwm_ChannelType,        AUTOMATIC) ChannelNumber,
    VAR(Pwm_StateType,          AUTOMATIC) nState
);
#endif
#endif /* PWM_SET_CHANNEL_OUTPUT_API */

/*===============================================================================================*/
#ifdef PWM_SET_TRIGGER_DELAY_API
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_SetTriggerDelay
(
    VAR(Pwm_ChannelType,        AUTOMATIC) ChannelNumber,
    VAR(Pwm_PeriodType,         AUTOMATIC) nTriggerDelay
);
#endif
#endif/*PWM_SET_TRIGGER_DELAY_API*/

/*===============================================================================================*/

#ifdef PWM_BUFFER_TRANSFER_EN_DIS_API 
#if (PWM_BUFFER_TRANSFER_EN_DIS_API  == STD_ON)
FUNC (void, PWM_CODE) Pwm_BufferTransferEnableDisable
(
    VAR(uint8,                  AUTOMATIC) u8ModuleIndex,
    VAR(uint32,                 AUTOMATIC) u32ChannelMasks
);
#endif
#endif

/*===============================================================================================*/

#ifdef PWM_SET_CLOCK_MODE_API
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SetClockMode
(
    VAR(Pwm_PrescalerType, AUTOMATIC) ePrescaler
);
#endif /*PWM_SET_CLOCK_MODE_API*/
#endif


#if (PWM_UPDATE_DUTY_SYNCHRONOUS == STD_ON)
/*===============================================================================================*/
#ifdef  PWM_SET_DUTY_CYCLE_NO_UPDATE_API
#if (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SetDutyCycle_NoUpdate
(
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint16,          AUTOMATIC) u16DutyCycle
);
#endif /*PWM_SET_DUTY_CYCLE_NO_UPDATE_API*/
#endif


/*===============================================================================================*/

#ifdef PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API
#if (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SetPeriodAndDuty_NoUpdate
(
    VAR(Pwm_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(Pwm_PeriodType,  AUTOMATIC) Period,
    VAR(uint16,          AUTOMATIC) u16DutyCycle
);
#endif /*PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API*/
#endif

/*===============================================================================================*/

#ifdef PWM_SYNC_UPDATE_API
#if (PWM_SYNC_UPDATE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SyncUpdate
(
    VAR(uint8, AUTOMATIC) ModuleId
#if (PWM_ALLOW_SUBMODULE_SYNC == STD_ON)
    ,
    VAR(uint16,         AUTOMATIC) u16SubmoduleMask
#endif
);
#endif /*PWM_SYNC_UPDATE_API*/
#endif

#endif  /*PWM_UPDATE_DUTY_SYNCHRONOUS*/

#if (PWM_SELECT_COMMON_TIMEBASE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SelectCommonTimebase
(
    VAR(uint8,          AUTOMATIC) ModuleId,
    VAR(uint16,         AUTOMATIC) u16ElementSyncList
);
#endif /* PWM_SELECT_COMMON_TIMEBASE_API */
#if (PWM_SET_PHASE_SHIFT_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SetPhaseShift
(
    VAR(Pwm_ChannelType, AUTOMATIC) u8ChannelNumber,
    VAR(Pwm_PeriodType,          AUTOMATIC) nPeriod,
    VAR(uint16,          AUTOMATIC) u16PhaseShift
);
#endif
#if (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_SetPhaseShift_NoUpdate
(
    VAR(Pwm_ChannelType, AUTOMATIC) u8ChannelNumber,
    VAR(Pwm_PeriodType,          AUTOMATIC) nPeriod,
    VAR(uint16,          AUTOMATIC) u16PhaseShift
);
#endif
#if ( PWM_ENABLE_TRIGEER_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_EnableTrigger
(
    VAR(uint8, AUTOMATIC) u8TriggerHostId,
    VAR(uint16,AUTOMATIC) u16TriggerMask
);
#endif
#if (PWM_DISABLE_TRIGEER_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_DisableTrigger
(
    VAR(uint8, AUTOMATIC) u8TriggerHostId,
    VAR(uint16,AUTOMATIC) u16TriggerMask
);
#endif

#if (PWM_RESET_COUNTER_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_ResetCounterEnable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
);

FUNC(void, PWM_CODE) Pwm_ResetCounterDisable
(
    VAR(uint8, AUTOMATIC) u8ModuleId
);
#endif

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
FUNC(void, PWM_CODE) Pwm_MaskOutputs
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 ,         AUTOMATIC)     u8ChannelMask
);
FUNC(void, PWM_CODE) Pwm_UnMaskOutputs
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId,
    VAR(uint8 ,         AUTOMATIC)     u8ChannelMask
);
#endif

#if (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_EnableReloadNotification
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId
);
FUNC(void, PWM_CODE) Pwm_DisableReloadNotification
(
    VAR(uint8 , AUTOMATIC)     u8ModuleId
);
#endif

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_SetPowerState
(
    P2VAR(Pwm_PowerStateRequestResultType,   AUTOMATIC, PWM_APPL_DATA) pResult
);

FUNC(Std_ReturnType, PWM_CODE) Pwm_GetCurrentPowerState
(
    P2VAR(Pwm_PowerStateType,                AUTOMATIC, PWM_APPL_DATA) pCurrentPowerState,
    P2VAR(Pwm_PowerStateRequestResultType,   AUTOMATIC, PWM_APPL_DATA) pResult
);

FUNC(Std_ReturnType, PWM_CODE) Pwm_GetTargetPowerState
(
    P2VAR(Pwm_PowerStateType,                AUTOMATIC, PWM_APPL_DATA) pTargetPowerState,
    P2VAR(Pwm_PowerStateRequestResultType,   AUTOMATIC, PWM_APPL_DATA) pResult
);

FUNC(Std_ReturnType, PWM_CODE) Pwm_PreparePowerState
(
    VAR(Pwm_PowerStateType,                  AUTOMATIC)                ePowerState,
    P2VAR(Pwm_PowerStateRequestResultType,   AUTOMATIC, PWM_APPL_DATA) pResult
);

FUNC(void, PWM_CODE) Pwm_Main_PowerTransitionManager
(
    void
);
#endif /*PWM_POWER_STATE_SUPPORTED*/


#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* PWM_H */

/** @} */