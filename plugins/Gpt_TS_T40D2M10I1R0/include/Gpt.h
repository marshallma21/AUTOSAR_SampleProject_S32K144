/**
*   @file    Gpt.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing the Autosar API specification and other variables
*            and functions that are exported by the GPT driver.
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

#ifndef GPT_H
#define GPT_H

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
* @section GPT_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Ipw_Types.h"

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    #include "EcuM_Cbk.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID                       43
#define GPT_MODULE_ID                       100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref GPT_H_REF_1 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define GPT_AR_RELEASE_REVISION_VERSION     2
#define GPT_SW_MAJOR_VERSION                1
#define GPT_SW_MINOR_VERSION                0
#define GPT_SW_PATCH_VERSION                1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Gpt.h and Std_Types.h are different"
    #endif
#endif
/* Check if header file and EcuM_Cbk.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
        #if ((GPT_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Gpt.h and EcuM_Cbk.h are different"
        #endif
    #endif
#endif

#if (GPT_VENDOR_ID != GPT_IPW_TYPES_VENDOR_ID)
    #error "Gpt.h and Gpt_Ipw_Types.h have different vendor ids"
#endif
/* Check if this header file and GPT IPW header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION != GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION != GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.h and Gpt_Ipw_Types.h are different"
#endif
/* Check if this header file and GPT IPW header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION != GPT_IPW_TYPES_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION != GPT_IPW_TYPES_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION != GPT_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.h and Gpt_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/

/*==================================================================================================*/
/**
* @brief function Gpt_StartTimer is called when the driver is in sleep mode for a channel which
* is not wakeup enabled
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_INVALID_CALL    ((uint8)0xA0U)


/**
* @brief function called without module initialization
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_UNINIT        ((uint8)0x0AU)

/**
* @brief function called when timer channel is still running
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_BUSY          ((uint8)0x0BU)

/**
* @brief initialization called when already initialized
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_ALREADY_INITIALIZED   ((uint8)0x0DU)

/**
* @brief function called for invalid channel
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)

/**
* @brief function called with parameter value out of range
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_VALUE   ((uint8)0x15U)

/**
* @brief function called with NULL pointer
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_POINTER  ((uint8)0x16U)

/**
* @brief function called with invalid the parameter in function Gpt_GetPredefTimerValue
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_MODE                                ((uint8)0x0C)
/**
* @brief function called with invalid the parameter in function Gpt_GetPredefTimerValue
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_PREDEF_TIMER                  ((uint8)0x17)
/**
* @brief function called with invalid the parameter in function Gpt_Init
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_INIT_FAILED                  ((uint8)0x0E)
/**
* @brief   API Gpt_SetClockMode service called with wrong parameter
* @details Parameters used when raising an error/exception
*/
#define GPT_E_PARAM_CLOCK_MODE                    ((uint8)0x17U)

/**
* @brief function  called with invalid mode param.
* @details Errors and exceptions that will be detected by the GPT driver
*
* @implements     Gpt_Det_ErrorCodes_define
*/
#define GPT_E_PARAM_MODE    ((uint8)0x1FU)

/* API SERVICE IDs */

/**
* @brief API service ID for Gpt_GetVersionInfo  function
* @details Parameters used when raising an error/exception
*/
#define GPT_GETVERSIONINFO_ID       ((uint8)0x00U)

/**
* @brief API service ID for Gpt_Init function
* @details Parameters used when raising an error/exception
*/
#define GPT_INIT_ID                 ((uint8)0x01U)

/**
* @brief API service ID for Gpt_DeInit function
* @details Parameters used when raising an error/exception
*/
#define GPT_DEINIT_ID               ((uint8)0x02U)

/**
* @brief API service ID for Gpt_GetTimeElapsed function
* @details Parameters used when raising an error/exception
*/
#define GPT_TIMEELAPSED_ID          ((uint8)0x03U)

/**
* @brief API service ID for Gpt_GetTimeRemaining function
* @details Parameters used when raising an error/exception
*/
#define GPT_TIMEREMAINING_ID        ((uint8)0x04U)

/**
* @brief API service ID for Gpt_StartTimer function
* @details Parameters used when raising an error/exception
*/
#define GPT_STARTTIMER_ID           ((uint8)0x05U)

/**
* @brief API service ID for Gpt_StopTimer function
* @details Parameters used when raising an error/exception
*/
#define GPT_STOPTIMER_ID            ((uint8)0x06U)

/**
* @brief API service ID for Gpt_EnableNotification function
* @details Parameters used when raising an error/exception
*/
#define GPT_ENABLENOTIFICATION_ID   ((uint8)0x07U)

/**
* @brief API service ID for Gpt_DisableNotification function
* @details Parameters used when raising an error/exception
*/
#define GPT_DISABLENOTIFICATION_ID  ((uint8)0x08U)

/**
* @brief API service ID for Gpt_SetMode function
* @details Parameters used when raising an error/exception
*/
#define GPT_SETMODE_ID              ((uint8)0x09U)

/**
* @brief API service ID for Gpt_DisableWakeup function
* @details Parameters used when raising an error/exception
*/
#define GPT_DISABLEWAKEUP_ID        ((uint8)0x0AU)

/**
* @brief API service ID for Gpt_EnableWakeup function
* @details Parameters used when raising an error/exception
*/
#define GPT_ENABLEWAKEUP_ID         ((uint8)0x0BU)

/**
* @brief API service ID for Gpt_CheckWakeup function
* @details Parameters used when raising an error/exception
*/
#define GPT_CHECKWAKEUP_ID          ((uint8)0x0CU)

/**
* @brief API service ID for Gpt_ProcessCommonInterrupt generic ISR handler
* @details Parameters used when raising an error/exception
*/
#define GPT_PROCESSCOMMONINTERRUPT_ID          ((uint8)0x0DU)


/**
* @brief API service ID for Gpt_ChangeNextTimeoutValue function
* @details Parameters used when raising an error/exception
*/
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID         ((uint8)0x0FU)


/**
* @brief   API service ID for Gpt_SetClockMode function
* @details Parameters used when raising an error/exception
*/
#define GPT_SET_CLOCK_MODE_ID                      ((uint8)0x10U)

/**
* @brief   API service ID for Gpt_GetPredefTimerValue function
* @details Parameters used when raising an error/exception
*/
#define GPT_GET_PREDEF_TIMERVALUE_ID                  ((uint8)0x11U)
/**
* @brief Instance ID of this GPT driver.
*
*/
#define GPT_INSTANCE_ID   ((uint8)0U)



/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief This enumerated type allows the selection of different power modes.
*
* @implements Gpt_ModeType_enumeration
*/
typedef enum
{
    GPT_MODE_NORMAL = 0U,                    /**< @brief GPT Normal operation mode of the GPT */
    GPT_MODE_SLEEP = 1U                     /**< @brief GPT sleep mode */
} Gpt_ModeType;


/**
* @brief Gpt channel mode type. Indicates of whether the channel mode is "CONTINUOUS" or "ONE SHOT".
*
*/
typedef enum
{
    GPT_CH_MODE_CONTINUOUS = 0U,        /**< @brief GPT channel mode -  countinous mode */
    GPT_CH_MODE_ONESHOT    = 1U         /**< @brief GPT channel mode -  one-shot mode. */
} Gpt_ChannelModeType;


/**
* @brief Pre-scaler type. Indicates of whether the clock channel mode is
* "GPT_NORMAL" or "GPT_ALTERNATE".
*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
typedef enum
{
    GPT_CLOCKMODE_NORMAL    = 0x0U,
    GPT_CLOCKMODE_ALTERNATE = 0x1U
}Gpt_ClockModeType;
#endif /* GPT_SET_CLOCK_MODE */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Gpt channel ID data type
*
* @implements Gpt_ChannelType_typedef
*/
typedef uint8 Gpt_ChannelType;

/**
* @brief Gpt timeout value type.Used for reading and setting the timer value in number of ticks.
*
* @implements Gpt_ValueType_typedef
*/
typedef uint32 Gpt_ValueType;

/**
* @brief Gpt channel notification type.  The callback notifications shall be configurable
* as pointers to user defined functions within the configuration structure.
*
* @implements Gpt_Notification_interface
*/
typedef P2FUNC(void, GPT_APPL_CODE, Gpt_NotificationType)(void);



/**
* @brief Gpt channel configuration type.
*
*/
typedef struct
{
    /**<@brief GPT ch WakeUp enable */
    VAR(boolean, GPT_VAR) Gpt_bEnableWakeup;
    /**<@brief Pointer to external callback*/
    VAR(Gpt_NotificationType, GPT_VAR) Gpt_pfNotification;
    /**<@brief EcuM wake up source Id */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
    VAR(EcuM_WakeupSourceType, GPT_VAR) Gpt_uWakeupSource;
#endif
    /**<@brief Channel max tick value */
    VAR(Gpt_ValueType, GPT_VAR) Gpt_uChannelTickValueMax;
    /**<@brief GPT channel mode */
    VAR(Gpt_ChannelModeType, GPT_VAR) Gpt_eChannelMode;
    /**<@brief Hardware dependent channel configuration*/
    VAR(Gpt_HwChannelConfigType,GPT_VAR) Gpt_HwChannelConfig;
} Gpt_ChannelConfigType;

/**
* @brief Gpt configuration type. This is the type of the data structure including the configuration
*        set required for initializing the GPT driver.
*
* @implements   Gpt_ConfigType_structure
*/
typedef struct
{
    /**< @brief Number of GPT channels (configured in tresos plugin builder)*/
    CONST(Gpt_ChannelType, GPT_CONST) Gpt_uChannelCount;
    /**< @brief Pointer to the GPT channel configuration */
    CONST(Gpt_ChannelConfigType, GPT_CONST) (*Gpt_pChannelConfig)[];
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    /**< @brief Pointer to the GPT channel predef timer configuration */
    CONSTP2CONST(Gpt_HwPredefChannelConfigType, GPT_CONST, GPT_APPL_CONST) (*Gpt_pChannelPredefConfigType);
#endif  
    /**< @brief Hardware to logic channel map table*/
    CONST(Gpt_ChannelType, GPT_CONST) Gpt_aHw2LogicChannelMap[GPT_CHANNEL_IDX_NUM];
} Gpt_ConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if header file and MemMap.h file are of the same Autosar version */
 #if ((GPT_AR_RELEASE_MAJOR_VERSION != GPT_MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
      (GPT_AR_RELEASE_MINOR_VERSION != GPT_MEMMAP_AR_RELEASE_MINOR_VERSION))
     #error "AutoSar Version Numbers of Gpt.h and Gpt_MemMap.h are different"
 #endif
#endif
/* Import extern declarations of GPT configuration from Gpt_Cfg.h */
GPT_CONF_PB

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/** @violates @ref GPT_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


#if (GPT_VERSION_INFO_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) versioninfo
);
#endif

FUNC(void, GPT_CODE)Gpt_Init (P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr);

#if (GPT_DEINIT_API == STD_ON)
FUNC(void, GPT_CODE)Gpt_DeInit(void);
#endif

#if (GPT_TIME_ELAPSED_API == STD_ON)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

FUNC(void, GPT_CODE) Gpt_StartTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) channel,
    VAR(Gpt_ValueType, AUTOMATIC) value
);

FUNC(void, GPT_CODE) Gpt_StopTimer
(
    VAR(Gpt_ChannelType, AUTOMATIC) channel
);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC(void, GPT_CODE) Gpt_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel);
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_SetMode(VAR(Gpt_ModeType, AUTOMATIC) eMode);

FUNC(void, GPT_CODE) Gpt_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC(void, GPT_CODE) Gpt_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel);

FUNC(void, GPT_CODE) Gpt_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource);
#endif


#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
FUNC (void, GPT_CODE) Gpt_ChangeNextTimeoutValue
(
    VAR(Gpt_ChannelType, AUTOMATIC) channel,
    VAR(Gpt_ValueType, AUTOMATIC) value
);
#endif

#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Gpt_SetClockMode(VAR(Gpt_ClockModeType, AUTOMATIC) eClkMode);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer, 
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) TimeValuePtr
);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /*GPT_H*/

/** @} */
