/**
*   @file           Ocu.h
*   @implements     Ocu.h_Artifact
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - Ocu module API header.
*   @details        Ocu module API header.
*
*   @addtogroup     OCU_MODULE
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

#ifndef OCU_H
#define OCU_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Ocu.h
*/
/*
* @violates @ref Ocu_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Std_Types.h"


#include "Ocu_Ipw_Types.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Ocu.h
*/
#define OCU_VENDOR_ID                       43
#define OCU_MODULE_ID                       121
#define OCU_AR_RELEASE_MAJOR_VERSION        4
#define OCU_AR_RELEASE_MINOR_VERSION        2
#define OCU_AR_RELEASE_REVISION_VERSION     2
#define OCU_SW_MAJOR_VERSION                1
#define OCU_SW_MINOR_VERSION                0
#define OCU_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ocu.h and Std_Types.h are different"
#endif

#endif


/* Check if header file and Ocu_Ipw_Types header file are of the same vendor */
#if (OCU_VENDOR_ID != OCU_IPW_TYPES_VENDOR_ID)
    #error "Ocu.h and Ocu_Ipw_Types.h have different vendor ids"
#endif
/* Check if header file and Ocu_Ipw_Types header file are of the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION    != OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION    != OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION != OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.h and Ocu_Ipw_Types.h are different"
#endif
/* Check if header file and Ocu_Ipw_Types header file are of the same software version */
#if ((OCU_SW_MAJOR_VERSION != OCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION != OCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION != OCU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu.h and Ocu_Ipw_Types.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/
/**
* @brief Instance ID of this OCU driver.
*
*/
#define OCU_INDEX               ((uint8)0U)

/**
* @brief            API service used without module initialization
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_UNINIT                    (0x02U)

/**
* @brief            API service used with an invalid channel Identifier
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_INVALID_CHANNEL     (0x03U)

/**
* @brief            API Ocu_SetPinState() called with an invalid pin state or when the channel is in the RUNNING state..
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_INVALID_STATE      (0x04U)

/**
* @brief            API Ocu_SetPinAction() called with an invalid pin action.
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_INVALID_ACTION     (0x05U)

/**
* @brief            Usage of Ocu_DisableNotification() or Ocu_EnableNotification() on a channel where a NULL pointer 
*                   is configured as the notification function.
* @details          Errors and exceptions that will be detected by the OCU driver.
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_NO_VALID_NOTIF           (0x06U)

/**
* @brief            API Ocu_Init() called while the OCU driver has already been initialized
* @details          Errors and exceptions that will be detected by the OCU driver.
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_ALREADY_INITIALIZED      (0x07U)

/**
* @brief            API Ocu_GetVersionInfo() is called with a NULL parameter.
* @details          Errors and exceptions that will be detected by the OCU driver.
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_POINTER            (0x08U)

/**
* @brief            API Ocu_StartChannel() called on a channel that is in state RUNNING.
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_BUSY                      (0x09U)

/**
* @brief            Ocu_SetPinState() or Ocu_SetPinAction() called for a channel that doesn’t 
*                   have an associated output pin.
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_NO_PIN              (0x0AU)


/**
* @brief            API Ocu_Init service called with wrong parameter
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_INIT_FAILED               (0x0BU)

/**
* @brief            Ocu_SetAbsoluteThreshold() or Ocu_SetRelativeThreshold() called for with a compare 
*                   match parameter greater than maximum supported counter value for a given channel
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define Non-AUTOSAR
*/
#define OCU_E_PARAM_INVALID_VALUE       (0x1BU)

/**
* @brief            Generated when the module id is more than the number of module that supported by
*                   this platform
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define Non-AUTOSAR
*/
#define OCU_E_PARAM_INSTANCE            (0x1DU)


/**
* @brief            API service ID of Ocu_Init function
* @details          Parameters used when raising an error/exception
*/
#define OCU_INIT_ID                (0x00U)

/**
* @brief            API service ID of Ocu_DeInit function
* @details          Parameters used when raising an error/exception
*/
#define OCU_DEINIT_ID              (0x01U)

/**
* @brief            API service ID of Ocu_StartChannel function
* @details          Parameters used when raising an error/exception
*/
#define OCU_STARTCHANNEL_ID        (0x02U)

/**
* @brief            API service ID of Ocu_StopChannel function
* @details          Parameters used when raising an error/exception
*/
#define OCU_STOPCHANNEL_ID         (0x03U)
/**
* @brief            API service ID of Ocu_SetPinState function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETPINSTATE_ID          (0x04U)

/**
* @brief            API service ID of Ocu_SetPinAction function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETPINACTION_ID         (0x05U)

/**
* @brief            API service ID of Ocu_GetCounter function
* @details          Parameters used when raising an error/exception
*/
#define OCU_GETCOUNTER_ID           (0x06U)

/**
* @brief            API service ID of Ocu_SetAbsoluteThreshold function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETABSOLUTETHRESHOLD_ID  (0x07U)

/**
* @brief            API service ID of Ocu_SetRelativeThreshold function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETRELATIVETHRESHOLD_ID  (0x08U)

/**
* @brief            API service ID of Ocu_DisableNotification function
* @details          Parameters used when raising an error/exception
*/
#define OCU_DISABLENOTIFICATION_ID   (0x0AU)

/**
* @brief            API service ID of Ocu_EnableNotification function
* @details          Parameters used when raising an error/exception
*/
#define OCU_ENABLENOTIFICATION_ID    (0x0BU)


/**
* @brief            API service ID of Ocu_GetVersionInfo function
* @details          Parameters used when raising an error/exception
*/
#define OCU_GETVERSIONINFO_ID        (0x09U)

/**
* @brief            API Ocu_SetClockMode service called with wrong parameter
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETCLOCKMODE_ID          (0x7AU)

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/**
* @brief This enumerated type allows the selection of channel status type.
*
*/
typedef enum
{
    OCU_STATUS_UNINITIALIZED = 0,           /**< @brief OCU channel status - uninitialized */
    OCU_STATUS_INITIALIZED,                 /**< @brief OCU channel status - initialized */
    OCU_STATUS_STOPPED,                     /**< @brief OCU channel status - stopped */
    OCU_STATUS_RUNNING                      /**< @brief OCU channel status - expired */
} Ocu_ChannelStatusType;  /* PRQA S 3448*/



/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/
typedef struct
{
    /** @brief Channel output pin enable */
    VAR(boolean,                OCU_VAR)  bOcuOutputPinEnable;
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief Pointer to notification function */
    CONST(Ocu_NotifyType,       OCU_CONST) pfOcuChannelNotification;
#endif /*(OCU_NOTIFICATION_SUPPORTED == STD_ON)*/
} Ocu_ChannelConfigType;


/**
* @brief      Ocu high level configuration structure
* @implements Ocu_ConfigType_struct
*/
typedef struct
{
    /** @brief Number of OCU channels (configured in tresos plugin builder)*/
    CONST(Ocu_ChannelType, OCU_CONST) nNumChannels;
    /** @brief Pointer to the OCU channel configuration */
    CONST(Ocu_ChannelConfigType, OCU_CONST) (*pOcuChannelsConfig)[];
    /** @brief Combined IP specific configuration structure */       
    CONST   (Ocu_IpConfigType,   OCU_CONST)   IpConfig;
#ifdef OCU_DOWNCOUNTING_SUPPORED
#if (OCU_DOWNCOUNTING_SUPPORED == STD_ON)    
    /** @brief Counting direction  */
    CONST(Ocu_CountDirectionType,   OCU_CONST)   eCountDir;
#endif
#endif 
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief Index table to translate HW channels to logical used 
    to process interrupts for notifications */
    CONST(Ocu_ChannelType, OCU_CONST) (*HwToLogicChannelMap)[];
#endif    
} Ocu_ConfigType;


/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/
#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Ocu_H_REF_1 Precautions shall be taken in order to prevent the contents of a 
* header file being included twice 
*/
#include "Ocu_MemMap.h"

#if (OCU_PRECOMPILE_SUPPORT != STD_ON)
OCU_CONF_PB
#endif

/* @violates @ref Ocu_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Ocu_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define OCU_START_SEC_CODE
/*
* @violates @ref Ocu_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*===============================================================================================*/

FUNC (void, OCU_CODE) Ocu_Init
(
    P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) ConfigPtr
);

/*===============================================================================================*/

#if (OCU_DEINIT_API == STD_ON)
FUNC (void, OCU_CODE) Ocu_DeInit
(   
    void
);
#endif

/*===============================================================================================*/
FUNC (void, OCU_CODE) Ocu_StartChannel
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber
);

/*===============================================================================================*/
FUNC (void, OCU_CODE) Ocu_StopChannel
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber
);

/*===============================================================================================*/

#if (OCU_SET_PIN_STATE_API == STD_ON)
FUNC (void, OCU_CODE) Ocu_SetPinState
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber,
    VAR(Ocu_PinStateType,           AUTOMATIC) PinState
);
#endif

/*===============================================================================================*/


#if (OCU_SET_PIN_ACTION_API == STD_ON)
FUNC (void, OCU_CODE) Ocu_SetPinAction
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber,
    VAR(Ocu_PinActionType,          AUTOMATIC) PinAction
);
#endif

/*===============================================================================================*/

#if (OCU_GET_COUNTER_API == STD_ON)
FUNC (Ocu_ValueType, OCU_CODE) Ocu_GetCounter
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber
);
#endif


/*===============================================================================================*/

#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
FUNC(Ocu_ReturnType, OCU_CODE) Ocu_SetAbsoluteThreshold
(
   VAR(Ocu_ChannelType,             AUTOMATIC) ChannelNumber,
   VAR(Ocu_ValueType,               AUTOMATIC) ReferenceValue,
   VAR(Ocu_ValueType,               AUTOMATIC) AbsoluteValue
);
#endif

/*===============================================================================================*/

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
FUNC(Ocu_ReturnType, OCU_CODE) Ocu_SetRelativeThreshold
(
   VAR(Ocu_ChannelType,             AUTOMATIC) ChannelNumber,
   VAR(Ocu_ValueType,               AUTOMATIC) RelativeValue   
);
#endif

/*===============================================================================================*/

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, OCU_CODE) Ocu_DisableNotification
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber
);
#endif


/*===============================================================================================*/

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, OCU_CODE) Ocu_EnableNotification
(
    VAR(Ocu_ChannelType,            AUTOMATIC) ChannelNumber
);
#endif

/*===============================================================================================*/

#if (OCU_VERSION_INFO_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_GetVersionInfo
(
    P2VAR(Std_VersionInfoType ,     AUTOMATIC, OCU_APPL_DATA) versioninfo
);
#endif

/*===============================================================================================*/

#ifdef OCU_SET_CLOCK_MODE_API
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_SetClockMode
(
    VAR(Ocu_SelectPrescalerType, AUTOMATIC) ePrescaler
);
#endif /*OCU_SET_CLOCK_MODE_API*/
#endif

/*===============================================================================================*/


#define OCU_STOP_SEC_CODE
/*
* @violates @ref Ocu_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* OCU_H */

/** @} */
