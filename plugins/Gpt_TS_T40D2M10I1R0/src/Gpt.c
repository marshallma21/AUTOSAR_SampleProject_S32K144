/**
*   @file           Gpt.c
*   @implements     Gpt.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt  - GPT driver source file.
*   @details GPT driver source file, containing the C implementation of Autosar API specification
*            and other variables and functions that are exported by the GPT driver.
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
* @section GPT_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include"This violation is not fixed since the inclusion of MemMap.h is as per
* Autosar requirement.
*
* @section GPT_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section GPT_C_REF_6
* Violates MISRA 2004 Required Rule 1.2, In order receive data from a callee function, it needs
* that a pointer to a local variable shall be passed as parameter to that function.
*
* @section GPT_C_REF_7
* Violates MISRA 2004 Required Rule 8.7, Global variables containing the generated configuration
* shall be defined in a separate source file and can't be defined inside a function although it is
* accessed by a single function.
*
* @section GPT_C_REF_8
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall
* not be permitted.
*
* @section GPT_C_REF_9
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall
* be the only allowed form of pointer
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Gpt.h"
#include "Gpt_Irq.h"
#include "Gpt_Ipw.h"

#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_C                      43
#define GPT_AR_RELEASE_MAJOR_VERSION_C       4
#define GPT_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref GPT_C_REF_3 The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_REVISION_VERSION_C    2
#define GPT_SW_MAJOR_VERSION_C               1
#define GPT_SW_MINOR_VERSION_C               0
#define GPT_SW_PATCH_VERSION_C               1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Gpt.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt.c and Gpt.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.c and Gpt.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt.h are different"
#endif

#if (GPT_VENDOR_ID_C != GPT_IPW_VENDOR_ID)
    #error "Gpt.c and Gpt_Ipw.h have different vendor ids"
#endif
/* Check if source file and GPT Ipw header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt.c and Gpt_Ipw.h are different"
#endif
/* Check if source file and GPT Ipw header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt_Ipw.h are different"
#endif

/* Check if source file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_IRQ_VENDOR_ID)
    #error "Gpt.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Gpt.c and Gpt_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt.c and Gpt_Irq.h are different"
#endif

/* Check if source file and DET header file are of the same version */
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((GPT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (GPT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of Gpt.c and Det.h are different"
        #endif
    #endif
#endif /* GPT_DEV_ERROR_DETECT */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief This enumerated type allows the selection of channel status type.
*
*/
typedef enum
{
    GPT_STATUS_UNINITIALIZED = 0,               /**< @brief GPT channel status - uninitialized */
    GPT_STATUS_INITIALIZED = 1,                 /**< @brief GPT channel status - initialized */
    GPT_STATUS_STOPPED = 2,                     /**< @brief GPT channel status - stopped */
    GPT_STATUS_EXPIRED = 3,                     /**< @brief GPT channel status - expired */
    GPT_STATUS_RUNNING = 4                      /**< @brief GPT channel status - running */
} Gpt_ChannelStatusType;


/**
* @brief Gpt runtime status type - this is the type of the data structure including the
* runtime status informations of a channel.
*
*/
typedef struct
{
    /**< @brief GPT channel runtime status */
    VAR(Gpt_ChannelStatusType,GPT_VAR) eChannelStatus;
    /**< @brief GPT channel has notification enabled at runtime */
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    VAR(boolean,GPT_VAR) bNotificationEnabled;
#endif

#if((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && \
    (GPT_REPORT_WAKEUP_SOURCE == STD_ON) \
   )
    /**< @brief GPT channel has wakeup enabled at runtime*/
    VAR(boolean,GPT_VAR) bWakeupEnabled;
    /**< @brief GPT channel executed wakeup */
    VAR(boolean,GPT_VAR) bWakeupGenerated;
#endif
} Gpt_ChannelInfoType;


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define GPT_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief          Global variable used for indicating the current GPT driver mode.
*/
/** @violates @ref GPT_C_REF_7 MISRA 2004 Rule 8.7, Global variables containing configuration */
static volatile VAR(Gpt_ModeType,GPT_VAR) Gpt_eMode = GPT_MODE_NORMAL;

/**
* @brief          Global variable (pointer) used for storing the GPT driver configuration data.
*/
static P2CONST(Gpt_ConfigType, GPT_VAR,  GPT_APPL_CONST)  Gpt_pConfig  = NULL_PTR;

#define GPT_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief         Global array variable used to store runtime internal context of each logic channel.
*/
static VAR(Gpt_ChannelInfoType, GPT_VAR) Gpt_aChannelInfo[GPT_HW_CHANNEL_NUM];

/**
* @brief         Global array variable used to store for each channel the time value when it is
*                stopped
*/
static volatile VAR(Gpt_ValueType,GPT_VAR) Gpt_aStopTime[GPT_HW_CHANNEL_NUM];

#define GPT_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
#if (GPT_PRECOMPILE_SUPPORT == STD_ON)
/* Extern declarations of GPT Pre compile configuration from Gpt_Cfg.c */
/** @violates @ref GPT_C_REF_7 MISRA 2004 Rule 8.7, Global variables containing configuration */
extern CONST(Gpt_ConfigType, GPT_CONST) Gpt_PBCfgVariantPredefined;
#endif
#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelCall
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
);
#endif

#if(GPT_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateGlobalCall(VAR(uint8, AUTOMATIC) u8ServiceId);
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelNotification
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
);
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) &&(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelWakeup
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
);
#endif

#if (GPT_VALIDATE_STATE == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelStatus
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
);
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) &&(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamMode(VAR(Gpt_ModeType, AUTOMATIC) eMode);
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamValue
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel,
    VAR(Gpt_ValueType, AUTOMATIC) value
);
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamPtrInit
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr
);
#endif

#if (GPT_SET_CLOCK_MODE == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamSetClockMode
(
    VAR(Gpt_ClockModeType, AUTOMATIC) eClkMode
);
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
#if (GPT_VALIDATE_PARAM == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamTypePredefTimer
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) u32PredefTimer
);

LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidatePointerGetPredefTimer
(
    P2CONST(uint32, AUTOMATIC, GPT_APPL_CONST) ParamPtr
);
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateMode
(
    VAR(uint8, AUTOMATIC) u8ServiceId
);
#endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
/**
 * @brief       This function validates the call for a specific channel
 * @details     This service is a non re entrant function on channel used for validating the calls
 *              for functions that use one channel
 *
 * @param[in]   Channel          Numeric identifier of the GPT channel
 * @param[in]   u8ServiceId        The service id of the caller function
 * @return      The validity of the function call
 * @retval      E_OK             The function call is valid
 * @retval      E_NOT_OK         The function call is invalid
 *
 * @implements Gpt_ValidateChannelCall_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelCall
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    /* If driver is not initialized report error */
    if (NULL_PTR == Gpt_pConfig)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_UNINIT\
        );
    }
    else
    {
        /* Check if the channel is in valid range */
        if (channel >= Gpt_pConfig->Gpt_uChannelCount)
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_PARAM_CHANNEL\
            );
        }
        else
        {
            returnValue = (Std_ReturnType)E_OK;
        }
    }

    return returnValue;
}
#endif

#if(GPT_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non re-entrant function used for validating the calls for functions
 *             that uses all the channels - Gpt_Init, Gpt_DeInit, Gpt_SetMode.
 *
 * @param[in]  u8ServiceId The service id of the caller function
 *
 * @return     The validity of the function call
 * @retval      E_OK     The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Gpt_ValidateGlobalCall_Activity
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateGlobalCall(VAR(uint8, AUTOMATIC) u8ServiceId)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    /* If caller is the initialization function, error */
    if (NULL_PTR == Gpt_pConfig)
    {
        /* If caller is the initialization function, OK */
        if (GPT_INIT_ID == u8ServiceId)
        {
            returnValue = (Std_ReturnType)E_OK;
        }
        else
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_UNINIT\
            );
        }
    }
    else
    {
        if (GPT_INIT_ID == u8ServiceId)
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_ALREADY_INITIALIZED\
            );
        }
        else
        {
            returnValue = (Std_ReturnType)E_OK;
        }
    }

    return returnValue;
}
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) && (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON))
/**
 * @brief           This function validate the channel notification capability for a
 *                  specific channel.
 *
 * @param[in]       u8ServiceId   The service id of the caller function
 * @param[in]       channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @retval          E_OK     The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 *
 * @implements      Gpt_ValidateChannelNotification_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelNotification
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_pfNotification)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_PARAM_CHANNEL\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;

}
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) &&(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief           This function validate the channel wakeup capability for a specific channel.
 *
 * @param[in]   u8ServiceId   The service id of the caller function
 * @param[in]   channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @retval          E_OK     The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 *
 * @implements      Gpt_ValidateChannelWakeup_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelWakeup
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    if ((boolean)FALSE == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_bEnableWakeup)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_PARAM_CHANNEL\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;

}
#endif

#if (GPT_VALIDATE_STATE == STD_ON)
/**
 * @brief           This function validate the channel status related to the caller function
 *                  and to a specific channel.
 *
 * @param[in]   u8ServiceId   The service id of the caller function
 * @param[in]   channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @retval          E_OK     The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateChannelStatus
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    /* Do not start a not enabled wakeup channel in sleep mode */
    if ((GPT_MODE_SLEEP == Gpt_eMode) && ((boolean)FALSE == Gpt_aChannelInfo[channel].bWakeupEnabled) && (GPT_STARTTIMER_ID == u8ServiceId))
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_INVALID_CALL\
        );
    }
    else
    {
#endif
#endif

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
        if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID == u8ServiceId) && \
            (GPT_STATUS_RUNNING != Gpt_aChannelInfo[channel].eChannelStatus)
           )
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_INVALID_CALL\
            );
        }
        else if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID == u8ServiceId) && \
                 (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                )
        {
            (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_PARAM_CHANNEL\
            );
        }
        else if ((GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID != u8ServiceId) && \
                 (GPT_STATUS_RUNNING == Gpt_aChannelInfo[channel].eChannelStatus)
                )
        {
             (void)Det_ReportError\
            (\
                (uint16)GPT_MODULE_ID,\
                (uint8)GPT_INSTANCE_ID,\
                (uint8)u8ServiceId,\
                (uint8)GPT_E_BUSY\
            );
         }
        else
        {
#else
            if (GPT_STATUS_RUNNING == Gpt_aChannelInfo[channel].eChannelStatus)
            {
                 (void)Det_ReportError\
                (\
                    (uint16)GPT_MODULE_ID,\
                    (uint8)GPT_INSTANCE_ID,\
                    (uint8)u8ServiceId,\
                    (uint8)GPT_E_BUSY\
                );
             }
            else
            {
#endif
                returnValue = (Std_ReturnType)E_OK;
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_OFF)
            }
#endif
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
        }
#endif
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    }
#endif
#endif
    return returnValue;

}
#endif

#if ((GPT_VALIDATE_PARAM == STD_ON) &&(GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
/**
 * @brief           This function validate the mode that will be set in the driver.
 *
 * @param[in]       mode        Specifies the operation mode
 *
 * @return          The validity of the function call
 * @retval          E_OK     The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 *
 * @implements      Gpt_ValidateParamMode_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamMode(VAR(Gpt_ModeType, AUTOMATIC) eMode)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    if((GPT_MODE_SLEEP != eMode) && (GPT_MODE_NORMAL != eMode))
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_SETMODE_ID,\
            (uint8)GPT_E_PARAM_MODE\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;
}
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
/**
 * @brief           This function validate the time value parameter related to a specific GPT channel.
 *
 * @param[in]   u8ServiceId   The service id of the caller function
 * @param[in]   value       The time value which is verified
 * @param[in]   channel     Numeric identifier of the GPT channel
 *
 * @return          The validity of the function call
 * @retval          E_OK     The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 *
 * @implements      Gpt_ValidateParamValue_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamValue
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Gpt_ChannelType, AUTOMATIC) channel,
    VAR(Gpt_ValueType, AUTOMATIC) value
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    if ((value > (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_uChannelTickValueMax) || \
        ((Gpt_ValueType)0 == value )
       )
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            u8ServiceId,\
            (uint8)GPT_E_PARAM_VALUE\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }

    return returnValue;

}
#endif

#if (GPT_VALIDATE_PARAM == STD_ON)
/**
 * @brief      This function validate the initialization pointer.
 *
 * @param[in]      configPtr        Pointer to a selected configuration structure.
 *
 * @return      The validity of the function call
 * @retval      E_OK     The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Gpt_ValidateParamPtrInit_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamPtrInit
(
    P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

#if (GPT_PRECOMPILE_SUPPORT == STD_OFF)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == configPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_INIT_ID,\

            (uint8)GPT_E_INIT_FAILED \
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }
#endif
#elif (GPT_PRECOMPILE_SUPPORT == STD_ON)
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != configPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_INIT_ID,\

            (uint8)GPT_E_INIT_FAILED \
        );
    }
    else
    {
        returnValue=(Std_ReturnType)E_OK;
    }
#endif
#endif

    return returnValue;
}
#endif

#if (GPT_SET_CLOCK_MODE == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamSetClockMode
(
    VAR(Gpt_ClockModeType, AUTOMATIC) eClkMode
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

    if((GPT_CLOCKMODE_NORMAL != eClkMode) && (GPT_CLOCKMODE_ALTERNATE != eClkMode))
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_SET_CLOCK_MODE_ID,\
            (uint8)GPT_E_PARAM_CLOCK_MODE\
        );
    }
    else
    {
        returnValue=(Std_ReturnType)E_OK;
    }

    return returnValue;
}
#endif
#if((GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON) && (GPT_VALIDATE_PARAM == STD_ON))
/**
 * @brief       This function validates parameter
 * @details
 *
 * @retval      E_OK             The function call is valid
 * @retval      E_NOT_OK         The function call is invalid
 *
 * @implements Gpt_ValidateParamTypePredefTimer_Activity
 *
 **/
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateParamTypePredefTimer
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) u32PredefTimer
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    /** @violates @ref GPT_C_REF_8 MISRA 2004 Rule 13.7,Boolean operations whose results are invariant shall not be permitted  */
    if (u32PredefTimer > GPT_PREDEF_TIMER_100US_32BIT)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GET_PREDEF_TIMERVALUE_ID,\
            (uint8)GPT_E_PARAM_PREDEF_TIMER\
        );
    }
    else
    {
       /** @violates @ref GPT_C_REF_9 MISRA 2004 Rule 17.4, Array indexing shall be the only allowed form of pointer */
       if(NULL_PTR == (*((Gpt_pConfig->Gpt_pChannelPredefConfigType)+u32PredefTimer)))
       {
           (void)Det_ReportError\
           (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GET_PREDEF_TIMERVALUE_ID,\
            (uint8)GPT_E_PARAM_PREDEF_TIMER\
           );
       }
       else
       {
            returnValue = (Std_ReturnType)E_OK;
       }

    }
    return returnValue;
}
/**
 * @brief      This function validate the initialization pointer.
 *
 * @param[in]      configPtr        Pointer to a selected configuration structure.
 *
 * @return      The validity of the function call
 * @retval      E_OK     The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Gpt_ValidatePointerGetPredefTimer_Activity
 *
 **/
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidatePointerGetPredefTimer
(
    P2CONST(uint32, AUTOMATIC, GPT_APPL_CONST) ParamPtr
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    if(NULL_PTR == ParamPtr)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GET_PREDEF_TIMERVALUE_ID,\
            (uint8)GPT_E_PARAM_POINTER\
        );
    }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }
    return returnValue;
}
#if (GPT_VALIDATE_STATE == STD_ON)
/**
 * @brief      This function validate the initialization mode.
 *
 * @param[in]      u8ServiceId
 *
 * @return      The validity of the function call
 * @retval      E_OK     The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Gpt_ValidateMode_Activity
 *
 **/
LOCAL_INLINE FUNC(Std_ReturnType,GPT_CODE) Gpt_ValidateMode
(
    VAR(uint8, AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    if (GPT_MODE_SLEEP == Gpt_eMode)
    {
         (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)u8ServiceId,\
            (uint8)GPT_E_MODE\
        );
     }
    else
    {
        returnValue = (Std_ReturnType)E_OK;
    }
    return returnValue;
}
#endif
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if (GPT_VERSION_INFO_API == STD_ON)
/**
* @brief   This function returns the version information of this module.
* @details This service returns the version information of this module. The version information
*          includes:
*                   Module Id
*                   Vendor Id
*                   Vendor specific version numbers
*
* @param[out]     versioninfo - pointer to location to store version info
*
* @api
*
* @implements     Gpt_GetVersionInfo_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, GPT_APPL_DATA) versioninfo
)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError\
        (\
            (uint16)GPT_MODULE_ID,\
            (uint8)GPT_INSTANCE_ID,\
            (uint8)GPT_GETVERSIONINFO_ID,\
            (uint8)GPT_E_PARAM_POINTER\
        );
    }
    else
#endif
    {
        versioninfo->vendorID         = (uint16)GPT_VENDOR_ID;
        versioninfo->moduleID         = (uint16)GPT_MODULE_ID;
        versioninfo->sw_major_version = (uint8)GPT_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)GPT_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)GPT_SW_PATCH_VERSION;
    }
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver initialization function.
* @details Service for driver initialization. The Initialization function shall initialize all
*          relevant registers of the configured hardware with the values of the structure referenced
*          by the parameter ConfigPtr.
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          This function shall only initialize the configured resources. Resources that are
*          not configured in the configuration file shall not be touched.
*          The following rules regarding initialization of controller registers shall apply
*          to the GPT Driver implementation:
*          [1] If the hardware allows for only one usage of the register, the driver
*              module implementing that functionality is responsible for initializing the register
*          [2] If the register can affect several hardware modules and if it is an IO register it
*              shall be initialized by the PORT driver
*          [3] If the register can affect several hardware modules and if it is not an IO register
*              it shall be initialized by the MCU driver
*          [4] One-time writable registers that require initialization directly after reset shall be
*              initialized by the startup code
*          [5] All other registers shall be initialized by the startup code
*
* @param[in]     configPtr    Pointer to a selected configuration structure
*
* @api
*
* @implements     Gpt_Init_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Init(P2CONST(Gpt_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channel;

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate the calling context*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_INIT_ID))
    {
#endif
#if (GPT_VALIDATE_PARAM  == STD_ON)
        /*Validate configuration pointer parameter.*/
        if((Std_ReturnType)E_OK == Gpt_ValidateParamPtrInit(configPtr))
        {
#endif

#if (GPT_PRECOMPILE_SUPPORT == STD_ON)

            Gpt_pConfig = &Gpt_PBCfgVariantPredefined;
            (void)configPtr;
#else
            Gpt_pConfig = configPtr;
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            /*Initialize and Start Predef Timers.*/
            Gpt_Ipw_StartPredefTimer(Gpt_pConfig);
#endif
            /*Initialize for each channel the runtime status informations.*/
            for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
            {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                /*Disable notification*/
                Gpt_aChannelInfo[channel].bNotificationEnabled = (boolean)FALSE;
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
                /*Disable wakeup*/
                Gpt_aChannelInfo[channel].bWakeupEnabled = (boolean)FALSE;
                /*Clear wakeup generation status*/
                Gpt_aChannelInfo[channel].bWakeupGenerated = (boolean)FALSE;
#endif

                /* Initialize the running information of the channel*/
                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_INITIALIZED;
                Gpt_aStopTime[channel] = 0U;

                /*Initialize hardware timer channel.*/
                Gpt_Ipw_Init(&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig));
            }

            /*Set the driver to normal mode*/
            Gpt_eMode = GPT_MODE_NORMAL;
#if (GPT_VALIDATE_PARAM  == STD_ON)
        }
#endif
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   GPT driver de-initialization function.
* @details Service for de initializing all hardware timer channels to their power on reset
*          state.
*          The state of the peripheral after DeInit shall be the same as after power on
*          reset.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of Gpt_Init()
*          The driver needs to be initialized before calling Gpt_DeInit(). Otherwise, the
*          function Gpt_DeInit shall raise the development error GPT_E_UNINIT and leave the desired
*          de initialization functionality without any action.
*
* @api
*
* @implements   Gpt_DeInit_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_DeInit(void)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channel;
#if (GPT_VALIDATE_STATE  == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) allChannelStatus = (Std_ReturnType)E_OK;
#endif

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate if the calling context is valid*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_DEINIT_ID))
    {
#endif

#if (GPT_VALIDATE_STATE  == STD_ON)
        /* Initialize for each channel the runtime status informations.*/
        for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
        {
            /*Check if the channel is not running.*/
            if((Std_ReturnType)E_NOT_OK == Gpt_ValidateChannelStatus(GPT_DEINIT_ID,channel))
            {
                allChannelStatus = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
        if((Std_ReturnType)E_OK == allChannelStatus)
        {
#endif
            for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
            {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                /*Disable notification*/
                Gpt_aChannelInfo[channel].bNotificationEnabled = (boolean)FALSE;
#endif

#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
                /*Disable wakeup*/
                Gpt_aChannelInfo[channel].bWakeupEnabled = (boolean)FALSE;
                /*Clear wakeup generation status*/
                Gpt_aChannelInfo[channel].bWakeupGenerated = (boolean)FALSE;
#endif
                /* De initialize the running information of the channel*/
                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_UNINITIALIZED;

                Gpt_aStopTime[channel] = 0U;

                /*Initialize hardware timer channel.*/
                Gpt_Ipw_DeInit
                (
                    &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                );
            }
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
            /* Deinitialize and stop Predef timers.*/
            Gpt_Ipw_StopPredefTimer(Gpt_pConfig);
#endif

            /* Writing NULL to configuration pointer is mandatory because that variable
            is used to test the initialization of the driver */
            Gpt_pConfig = NULL_PTR;

#if (GPT_VALIDATE_STATE  == STD_ON)
        }
#endif

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
    return;
}
#endif

/*================================================================================================*/
#if (GPT_TIME_ELAPSED_API == STD_ON)
/**
* @brief   GPT driver function for fetching the elapsed timer value.
* @details Service for querying the time already elapsed.
*          In one shot mode, this is the value relative to the point in time, the channel has been
*          started with Gpt_StartTimer (calculated by the normal operation function by subtracting
*          the current minus the initial timer value and returning the absolute value).
*          In continuous mode, the function returns the timer value relative to the last timeout or
*          the start of the channel.
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator frequency, pre
*          prescalers and so on. Since these settings are made in MCU and(or) in other modules it is
*          not possible to calculate such times. Hence the conversions between time and ticks shall
*          be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_GetTimeElapsed(). Otherwise, the
*          function shall raise the development error GPT_E_UNINIT and return 0.
*
* @param[in]  channel - channel id
*
* @return  Gpt_ValueType - Elapsed Time in number of ticks
*
* @api
*
* @implements Gpt_GetTimeElapsed_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeElapsed(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_HwChannelInfoType, AUTOMATIC) returnHwChannelInfo;
    VAR(Gpt_ValueType, AUTOMATIC) returnValue = (Gpt_ValueType)0;

    returnHwChannelInfo.bChannelRollover =(boolean)FALSE;
    returnHwChannelInfo.uTargetTime =(Gpt_ValueType)0;

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_TIMEELAPSED_ID,channel))
    {
#endif
        /*Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs can change
        the logical channel state between the checking of logical channel state and timestamp
        retrieval*/
        /** @violates @ref GPT_C_REF_6  pointer to local variable used as function parameter*/
        returnValue = Gpt_Ipw_GetTimeElapsed((&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)), &returnHwChannelInfo);

        /*Check the channel status*/
        switch(Gpt_aChannelInfo[channel].eChannelStatus)
        {
            case GPT_STATUS_RUNNING:
            {
                /*Check if channel counter has already rollover*/
                if (((boolean)TRUE == returnHwChannelInfo.bChannelRollover) && \
                    (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                   )
                {
                    /*The timer has already expired.The hardware timer status is not yet
                    synchronised with the logical timer status*/
                    returnValue = returnHwChannelInfo.uTargetTime;
                }
            }
            break;
            case GPT_STATUS_INITIALIZED:
            {
                returnValue = (Gpt_ValueType)0;
            }
            break;
            case GPT_STATUS_STOPPED:
            {
                /*Return elapsed time at the when the channel was stopped*/
                returnValue = Gpt_aStopTime[channel];
            }
            break;
            case GPT_STATUS_EXPIRED:
            {
                returnValue = returnHwChannelInfo.uTargetTime;
            }
            break;
            default:
                /*Only the above four channel states are allowed when this function is called*/
                break;
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif

    return (returnValue);
}
#endif

/*================================================================================================*/
#if (GPT_TIME_REMAINING_API == STD_ON)
/**
* @brief   GPT driver function for fetching the remaining timer value.
* @details This function returns the timer value remaining until the next timeout period will
*          expire (calculated by the normal operation function by subtracting the timeout minus
*          the current timer value and returning the absolute value)
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          Usage of re-entrant capability is only allowed if the callers take care that there is no
*          simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator frequency,
*          pre-scalers and so on. Since these settings are made in MCU and(or) in other modules it is
*          not possible to calculate such times. Hence the conversions between time and ticks shall
*          be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_GetTimeRemaining(). Otherwise, the
*          function shall raise the development error GPT_E_UNINIT and return 0.
*
* @param[in]     channel - channel id
*
* @return  Gpt_ValueType - Remaining Time in number of ticks
*
* @api
*
* @implements    Gpt_GetTimeRemaining_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

FUNC(Gpt_ValueType, GPT_CODE) Gpt_GetTimeRemaining(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_HwChannelInfoType, AUTOMATIC) returnHwChannelInfo;
    VAR(Gpt_ValueType, AUTOMATIC) returnValue = (Gpt_ValueType)0;

    returnHwChannelInfo.bChannelRollover =(boolean)FALSE;
    returnHwChannelInfo.uTargetTime =(Gpt_ValueType)0;

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_TIMEREMAINING_ID,channel))
    {
#endif

        /* Calculate the remaining time from the elapsed time*/
        /* Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs can
        change the logical channel state between the checking of logical channel state
        and timestamps retrieval*/
        /** @violates @ref GPT_C_REF_6 pointer to local variable used as function parameter*/
        returnValue = Gpt_Ipw_GetTimeElapsed((&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)), &returnHwChannelInfo);

        /*Check the channel status*/
        switch(Gpt_aChannelInfo[channel].eChannelStatus)
        {
            case GPT_STATUS_RUNNING:
            {
                /*Check if channel counter has already roll-over*/
                if(((boolean)TRUE == returnHwChannelInfo.bChannelRollover) && \
                   (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                  )
                {
                    /*The timer has already expired.The hardware timer status is not yet
                    synchronised with the logical timer status*/
                    returnValue = (Gpt_ValueType)0;
                }
                else
                {
                    /*Calculate remaining time from elapsed time*/
                    returnValue = returnHwChannelInfo.uTargetTime - returnValue;
                }
            }
            break;
            case GPT_STATUS_INITIALIZED:
            {
                returnValue = (Gpt_ValueType)0;
            }
            break;
            case GPT_STATUS_STOPPED:
            {
                returnValue = returnHwChannelInfo.uTargetTime-Gpt_aStopTime[channel];
            }
            break;
            case GPT_STATUS_EXPIRED:
            {
                returnValue = (Gpt_ValueType)0;
            }
            break;
            default:
                /*Only the above four channel states are allowed when this function is called*/
                break;
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif

    return(returnValue);
}
#endif

/*================================================================================================*/
/**
* @brief   GPT driver function for starting a timer channel.
* @details The function Gpt_StartTimer shall start the selected timer channel with a defined
*          time-out period.
*          The function Gpt_StartTimer shall invoke the configured notification for that channel
*          (see also GPT292) after the time-out period referenced via the parameter value (if
*          enabled).
*          All time units used within the API services of the GPT driver shall be of the unit ticks.
*          In production mode no error is generated. The rational is that it adds no
*          additional functionality to the driver. In this case the timer will be restarted with the
*          time-out value, given as a parameter to the service.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          To get times out of register values it is necessary to know the oscillator
*          frequency, pre-scalers and so on. Since these settings are made in MCU and(or) in other
*          modules it is not possible to calculate such times. Hence the conversions between time
*          and ticks shall be part of an upper layer.
*          The driver needs to be initialized before calling Gpt_StartTimer(). Otherwise, the
*          function Gpt_StartTimer shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel channel id
* @param[in]     value   time-out period (in number of ticks) after a notification or a
*                        wakeup event shall occur
*
* @api
*
* @implements    Gpt_StartTimer_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_StartTimer
(
    VAR(Gpt_ChannelType,    AUTOMATIC) channel,
    VAR(Gpt_ValueType,      AUTOMATIC) value
)
{
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_STARTTIMER_ID,channel))
    {
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateChannelStatus(GPT_STARTTIMER_ID,channel))
        {
#endif
#if (GPT_VALIDATE_PARAM  == STD_ON)
            if ((Std_ReturnType)E_OK == Gpt_ValidateParamValue(GPT_STARTTIMER_ID,channel,value))
            {
#endif
                /*Enable hardware interrupts for the one-shot mode to set the status of  channel*/
                if (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                {
                    Gpt_Ipw_EnableInterrupt
                    (
                        &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                    );
                }

                /* Change GPT channel status.Channel status change shall be made before to start
                the hardware in order to not change the channel status from EXPIRED to RUNNING*/
                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_RUNNING;
                /* Call low level start timer */
                Gpt_Ipw_StartTimer
                (
                    &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig),value
                );

#if (GPT_VALIDATE_PARAM  == STD_ON)
            }
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return;
}
/*================================================================================================*/
/**
* @brief   GPT driver function for stopping a timer channel.
* @details Service for stopping the selected timer channel
*          Stopping a timer channel, not been started before will not return a development error
*          Timer channels configured in one shot mode are stopped automatically, when the
*          time-out period has expired.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_StopTimer(). Otherwise,
*          the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @implements   Gpt_StopTimer_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_StopTimer(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
    VAR(Gpt_HwChannelInfoType, AUTOMATIC) returnHwChannelInfo;
    VAR(Gpt_ValueType, AUTOMATIC) uElapsedTime;

    returnHwChannelInfo.bChannelRollover =(boolean)FALSE;
    returnHwChannelInfo.uTargetTime =(Gpt_ValueType)0;

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_STOPTIMER_ID,channel))
    {
#endif
        /*Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs can change
        the logical channel state between the checking of logical channel state and timestamps
        retrieval*/
        /* Get the elapsed  time  for later use by other API calls*/

        /** @violates @ref GPT_C_REF_6 pointer to local variable used as function parameter*/
        uElapsedTime = Gpt_Ipw_GetTimeElapsed((&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)), &returnHwChannelInfo);

        /*Check the logical cchannel status*/
        if (GPT_STATUS_RUNNING == Gpt_aChannelInfo[channel].eChannelStatus)
        {
            /* Call low level stop timer */
            Gpt_Ipw_StopTimer(&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig));
            
            if (((boolean)TRUE == returnHwChannelInfo.bChannelRollover) && \
                (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
            )
            {
                /*This action could be executed only when the function is called during a critical
                section implemented by disabling all interrupts*/
                /*Set channel status to EXPIRED*/
                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_EXPIRED;
            }
            else
            {
                /* Store the stopping time for later use by other API calls*/
                Gpt_aStopTime[channel] = uElapsedTime;

                /* Set GPT channel status to stopped*/
                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_STOPPED;
            }
        }
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return;
}

/*================================================================================================*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
* @brief   GPT driver function for enabling the notification for a timer channel.
* @details Service for enabling the notification for a channel during runtime.
*          This function can be called, while the timer is already running.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_EnableNotification(). Otherwise,
*          the function Gpt_EnableNotification shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @implements   Gpt_EnableNotification_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

FUNC(void, GPT_CODE) Gpt_EnableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_ENABLENOTIFICATION_ID,channel))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateChannelNotification(GPT_ENABLENOTIFICATION_ID,channel))
        {
#endif
            /* Set the enable notification attribute */
            Gpt_aChannelInfo[channel].bNotificationEnabled = (boolean)TRUE;

            if (GPT_MODE_NORMAL == Gpt_eMode)
            {
                /*Enable hardware interrupts*/
                Gpt_Ipw_EnableInterrupt(&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig));
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif

    return;
}
#endif
/*================================================================================================*/
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/**
* @brief   GPT driver function for disabling the notification for a timer channel.
* @details Service for disabling the notification for a channel during runtime.
*          This function can be called, while the timer is already running
*          When disabled, no notification will be sent. When re-enabled again, the user
*          will not be notified of events, occurred while notifications have been disabled.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_DisableNotification().
*          Otherwise, the function shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @implements   Gpt_DisableNotification_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

FUNC(void, GPT_CODE) Gpt_DisableNotification(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_DISABLENOTIFICATION_ID,channel))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateChannelNotification(GPT_DISABLENOTIFICATION_ID,channel))
        {
#endif
            /* Set the enable notification attribute */
            Gpt_aChannelInfo[channel].bNotificationEnabled = (boolean)FALSE;

            /* Disable hardware interrupts if the channel is not running in the ONE-SHUT mode.
            This is needed because the channel state is updated by ISR for ONE-SHOT mode */
            if ((GPT_MODE_NORMAL == Gpt_eMode) && \
                ((GPT_CH_MODE_CONTINUOUS == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode) \
                 || (GPT_STATUS_RUNNING != Gpt_aChannelInfo[channel].eChannelStatus)
                )
               )
            {
                /*Disable hardware interrupts*/
                Gpt_Ipw_DisableInterrupt
                (
                    &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief   GPT driver function for setting the operation mode.
* @details Service for GPT mode selection. This service shall set the operation mode to the given
*          mode parameter .
*          When sleep mode is requested, the ECU State Manager calls Gpt_SetMode with mode
*          parameter "GPT_MODE_SLEEP" and prepares the GPT for sleep mode. The MCU Driver is then
*          putting the controller into SLEEP mode
*          The driver needs to be initialized before calling Gpt_SetMode(). Otherwise, the
*          function Gpt_SetMode shall raise the development error GPT_E_UNINIT.
*
* @param[in]     eMode        operation mode
*
* @api
*
* @implements     Gpt_SetMode_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_SetMode(VAR(Gpt_ModeType, AUTOMATIC) eMode)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)eMode;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    VAR(Gpt_HwChannelInfoType, AUTOMATIC) returnHwChannelInfo;
    VAR(Gpt_ValueType, AUTOMATIC) uElapsedTime = 0U;
    VAR(Gpt_ChannelType, AUTOMATIC) channel;

    returnHwChannelInfo.bChannelRollover =(boolean)FALSE;
    returnHwChannelInfo.uTargetTime =(Gpt_ValueType)0;

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate the driver calling context*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_SETMODE_ID))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if((Std_ReturnType)E_OK == Gpt_ValidateParamMode(eMode))
        {
#endif
            /*Implements the behaviour for the sleep mode*/
            if(GPT_MODE_SLEEP == eMode)
            {
                for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
                {
                    /* Check for wakeup enabled channel*/
                    if ((boolean)TRUE == Gpt_aChannelInfo[channel].bWakeupEnabled)
                    {
                        /*Enable hardware interrupts*/
                        Gpt_Ipw_EnableInterrupt
                        (
                            &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                        );
                    }
                    /* Disable interrupts and stop the channel*/
                    else
                    {
                        /*Disable hardware interrupts*/
                        Gpt_Ipw_DisableInterrupt
                        (
                            (&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig))
                        );

                        /*Gpt_Ipw_GetTimeElapsed() shall be called first, because the occurred ISRs
                        can change the logical channel state between the checking of logical channel
                        state and timestamp retrieval*/
                        /* Get the elapsed  time  for later use by other API calls*/

                        /** @violates @ref GPT_C_REF_6  pointer to local variable used
                        as function parameter*/
                        uElapsedTime = Gpt_Ipw_GetTimeElapsed((&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)), &returnHwChannelInfo);

                        /*Stop  the running timer*/
                        if (GPT_STATUS_RUNNING == Gpt_aChannelInfo[channel].eChannelStatus)
                        {
                            if (((boolean)TRUE == returnHwChannelInfo.bChannelRollover) && \
                                (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                            )
                            {
                                /*This action could be executed only when the function is called
                                during a critical section implemented by disabling all interrupts*/
                                /*Set the channel status to EXPIRED*/
                                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_EXPIRED;
                            }
                            else
                            {
                                /* Store the stopping time for later use by other API calls*/
                                Gpt_aStopTime[channel] = uElapsedTime;
                                /* Set the channel status to STOPPED*/
                                Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_STOPPED;
                            }
                                
                            /* Call low level stop timer */
                            Gpt_Ipw_StopTimer
                            (
                                &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                            );
                        }
                    }
                }

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
                /* Deinitialize and Stop Predef Timers. */
                Gpt_Ipw_StopPredefTimer(Gpt_pConfig);
#endif

                /*Set the driver mode to sleep */
                Gpt_eMode = GPT_MODE_SLEEP;
            }
            else if (GPT_MODE_NORMAL == eMode)
            {
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
                if ((Gpt_ModeType)GPT_MODE_SLEEP == Gpt_eMode)
                {
                    /* Start for each predef timer status informations. */
                    Gpt_Ipw_StartPredefTimer(Gpt_pConfig);
                }
#endif
                /*Implements the behavior for normal mode*/
                for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
                {
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                    if ((boolean)TRUE == Gpt_aChannelInfo[channel].bNotificationEnabled)
                    {
                        /*Enable hardware interrupts*/
                        Gpt_Ipw_EnableInterrupt
                        (
                            &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                        );
                    }
                    else
                    {
#endif
                        /* Disable hardware interrupts if the channel is not running in the ONE-SHUT mode.
                        This is needed because the channel state is updated by ISR for ONE-SHOT mode */
                        if((GPT_STATUS_RUNNING != Gpt_aChannelInfo[channel].eChannelStatus) || \
                           (GPT_CH_MODE_CONTINUOUS == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                          )
                        {
                            /*Disable hardware interrupts*/
                            Gpt_Ipw_DisableInterrupt
                            (
                                &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                            );
                        }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
                    }
#endif
                }

                /*Set the driver mode to normal mode*/
                Gpt_eMode = GPT_MODE_NORMAL;
            }
            else
            {
                /* This else clause is required due to MISRA rules */
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif

#endif /*GPT_REPORT_WAKEUP_SOURCE*/
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief   GPT driver function for disabling the wakeup interrupt invocation for a timer channel.
* @details This service shall disable the wakeup interrupt invocation of a single GPT
*          channel.
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*          The driver needs to be initialized before calling Gpt_DisableWakeup(). Otherwise, the
*          function Gpt_DisableWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]     channel        channel id
*
* @api
*
* @implements   Gpt_DisableWakeup_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

FUNC(void, GPT_CODE) Gpt_DisableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{

#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)channel;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_DISABLEWAKEUP_ID,channel))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if((Std_ReturnType)E_OK == Gpt_ValidateChannelWakeup(GPT_DISABLEWAKEUP_ID,channel))
        {
#endif
            /* Set the enable wakeup attribute */
            Gpt_aChannelInfo[channel].bWakeupEnabled = (boolean)FALSE;

            /* Disable hardware interrupts if the channel is not running in the ONE-SHUT mode.
            This is needed because the channel state is updated by ISR for ONE-SHOT mode */
            if ((GPT_MODE_SLEEP == Gpt_eMode) && \
                ((GPT_CH_MODE_CONTINUOUS == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
                 || (GPT_STATUS_RUNNING != Gpt_aChannelInfo[channel].eChannelStatus)
                )
               )
            {
                /*Disable hardware interrupts*/
                Gpt_Ipw_DisableInterrupt
                (
                    &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/**
* @brief   GPT driver function for enabling the wakeup interrupt invocation for a timer channel.
* @details This service shall re-enable the wakeup interrupt invocation of a single GPT
*          channel.
*          If supported by hardware and enabled, an internal hardware timer can serve as a
*          wakeup source
*          Usage of re-entrant capability is only allowed if the callers take care that
*          there is no simultaneous usage of the same channel.
*
* @param[in]     channel        channel id
*
* @api
*
* @implements   Gpt_EnableWakeup_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

FUNC(void, GPT_CODE) Gpt_EnableWakeup(VAR(Gpt_ChannelType, AUTOMATIC) channel)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void)channel;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_ENABLEWAKEUP_ID,channel))
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if((Std_ReturnType)E_OK == Gpt_ValidateChannelWakeup(GPT_ENABLEWAKEUP_ID,channel))
        {
#endif
            /* Functionality implementation */
            /* Set the enable wakeup attribute */
            Gpt_aChannelInfo[channel].bWakeupEnabled = (boolean)TRUE;

            if (GPT_MODE_SLEEP == Gpt_eMode)
            {
                /*Enable hardware interrupts*/
                Gpt_Ipw_EnableInterrupt
                (
                    &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig)
                );
            }
#if (GPT_VALIDATE_PARAM == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
#endif /*GPT_REPORT_WAKEUP_SOURCE*/
    return;
}
#endif

/*================================================================================================*/
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)

/**
* @brief   GPT driver function for checking if a wakeup capable GPT channel is the source for a
*          wakeup event.
* @details Checks if a wakeup capable GPT channel is the source for a wakeup event and calls the ECU
*          state manager service EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.
*          The driver needs to be initialized before calling Gpt_CheckWakeup(). Otherwise, the
*          function Gpt_CheckWakeup shall raise the development error GPT_E_UNINIT.
*
* @param[in]     wakeupSource        wakeup source
*
* @api
*
* @implements   Gpt_CheckWakeup_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) wakeupSource)
{
#if (GPT_REPORT_WAKEUP_SOURCE == STD_OFF)
    (void) wakeupSource;
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    VAR(Gpt_ChannelType, AUTOMATIC) channel;

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    /*Validate the driver calling context*/
    if((Std_ReturnType)E_OK == Gpt_ValidateGlobalCall(GPT_CHECKWAKEUP_ID))
    {
#endif
        for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
        {
            if (((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_uWakeupSource == wakeupSource) && \
                ((boolean)TRUE == Gpt_aChannelInfo[channel].bWakeupGenerated)
               )
            {
                /*Reset the wakeup flag */
                Gpt_aChannelInfo[channel].bWakeupGenerated = (boolean)FALSE;

                /* Calling EcuM_SetWakeupEvent and exit*/
                EcuM_SetWakeupEvent(wakeupSource);

                break;
            }
        } /*for*/
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
#endif /* GPT_REPORT_WAKEUP_SOURCE */
    return;
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */


/*================================================================================================*/
/**
* @brief   Gpt common handler to implements generic part of the ISR.
* @details Generic function used by all interrupt service routines to call notification
*          functions  and wakeup the EcuM
*
* @param[in]     u8MapTableIndex      generic index used to access the map table
*
* @implements   Gpt_ProcessCommonInterrupt_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8MapTableIndex)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channel;

    if (Gpt_pConfig != NULL_PTR)
    {
        /* Extract the logical channel from the hardware to logic map table */
        channel = Gpt_pConfig->Gpt_aHw2LogicChannelMap[u8MapTableIndex];

        /*Stop the timer for one-shot mode*/
        if (GPT_CH_MODE_ONESHOT == (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_eChannelMode)
        {
            /*Stop channel*/
            Gpt_Ipw_StopTimer(&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig));
            
            /* Change the channel status to expired */
            Gpt_aChannelInfo[channel].eChannelStatus = GPT_STATUS_EXPIRED;
        }
#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
        if ((GPT_MODE_NORMAL == Gpt_eMode) && ((boolean)TRUE == Gpt_aChannelInfo[channel].bNotificationEnabled))
        {
            (*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_pfNotification();
        }
#endif

#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
        if ((GPT_MODE_SLEEP == Gpt_eMode) && ((boolean)TRUE == Gpt_aChannelInfo[channel].bWakeupEnabled))
        {
            Gpt_aChannelInfo[channel].bWakeupGenerated =(boolean)TRUE;
            EcuM_CheckWakeup((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_uWakeupSource);
        }
#endif
#endif
    }
    return;
}
/*================================================================================================*/
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief     The function changes the time out period value of the requested running channel.
* @details   The function changes the time out period (in number of ticks) of the channel is
             running which will be used after the first compare matching.
*            This is a non-autosar function.
* @param[in]     channel        channel id
* @param[in]     value          time out period (in number of ticks) after a notification shall occur
*
* @pre     Gpt_Init and Gpt_StartTimer must be called before.
*
* @violates @ref GPT_C_REF_5 Declarations and definitions of Objects or Functions at File scope
*/
FUNC(void, GPT_CODE) Gpt_ChangeNextTimeoutValue(VAR(Gpt_ChannelType, AUTOMATIC) channel, VAR(Gpt_ValueType, AUTOMATIC) value)
{
#if (GPT_DEV_ERROR_DETECT == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) returnValue;
#endif

#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Gpt_ValidateChannelCall(GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID,channel))
    {
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateChannelStatus(GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID,channel))
        {
#endif
#if (GPT_VALIDATE_PARAM  == STD_ON)
            if ((Std_ReturnType)E_OK == Gpt_ValidateParamValue(GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID,channel,value))
            {
#endif
#if (GPT_DEV_ERROR_DETECT == STD_ON)
                /* Call low level API */
                returnValue = Gpt_Ipw_ChangeNextTimeoutValue(&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig),value);

                if((Std_ReturnType)E_OK != returnValue)
                {
                    (void)Det_ReportError\
                    (\
                        (uint16)GPT_MODULE_ID,\
                        (uint8)GPT_INSTANCE_ID,\
                        (uint8)GPT_CHANGE_NEXT_TIMEOUT_VALUE_ID,\
                        (uint8)GPT_E_PARAM_CHANNEL\
                    );
                }
#else
                /* Call low level API */
                (void)Gpt_Ipw_ChangeNextTimeoutValue(&((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig),value);
#endif

#if (GPT_VALIDATE_PARAM  == STD_ON)
            }
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
        }
#endif
#if (GPT_VALIDATE_CHANNEL_CALL == STD_ON)
    }
#endif
    return;
}
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */


#if (GPT_SET_CLOCK_MODE == STD_ON)

/*================================================================================================*/
/**
* @brief     This function changes the channel pre scaler.
* @details   This function sets all channels pre scalers based on the input mode.
*
* @param[in] clkMode   pre scaler setting ( NORMAL or ALTERNATE )
*
* @pre     Gpt_Init must be called before.
* @implements     Gpt_SetClockMode_Activity
* @violates @ref GPT_C_REF_5 Declarations and definitions of Objects or Functions at File scope
*/
FUNC(void, GPT_CODE) Gpt_SetClockMode(VAR(Gpt_ClockModeType, AUTOMATIC) eClkMode)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channel;
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)

    VAR(Std_ReturnType, AUTOMATIC)returnValue;

    returnValue = Gpt_ValidateGlobalCall(GPT_SET_CLOCK_MODE_ID);
    if((Std_ReturnType)E_OK == returnValue)
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        if ((Std_ReturnType)E_OK == Gpt_ValidateParamSetClockMode(eClkMode))
        {
#endif
            for (channel = 0U; channel < (Gpt_ChannelType)Gpt_pConfig->Gpt_uChannelCount; channel++)
            {
                Gpt_Ipw_SetClockMode ( &((*(Gpt_pConfig->Gpt_pChannelConfig))[channel].Gpt_HwChannelConfig), eClkMode);
            }
#if (GPT_VALIDATE_PARAM  == STD_ON)
        }
#endif
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* GPT_SET_CLOCK_MODE */


#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief     Provides the current value of the given predefined free-running timer
* @details   This function provides the current value of the given predefined free-running timer.
*
* @param[in] PredefTimer: Gpt_PredefTimerType ( GPT_PREDEF_TIMER_1US_16BIT,
                                                GPT_PREDEF_TIMER_1US_24BIT,
                                                GPT_PREDEF_TIMER_1US_32BIT
                                                GPT_PREDEF_TIMER_100US_32BIT)
*            TimeValuePtr: Pointer to time value destination data in RAM
* @pre            Gpt_Init must be called before.
* @implements     Gpt_GetPredefTimerValue_Activity
* @violates @ref GPT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(Std_ReturnType, GPT_CODE) Gpt_GetPredefTimerValue
(
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) TimeValuePtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;
    VAR(Gpt_ChannelType, AUTOMATIC) channel;

#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    returnValue = Gpt_ValidateGlobalCall(GPT_GET_PREDEF_TIMERVALUE_ID);
    if((Std_ReturnType)E_OK == returnValue)
    {
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
        returnValue = Gpt_ValidatePointerGetPredefTimer(TimeValuePtr);
        if((Std_ReturnType)E_OK == returnValue)
        {
            returnValue = Gpt_ValidateParamTypePredefTimer(PredefTimer);
            if((Std_ReturnType)E_OK == returnValue)
            {
#endif
#if (GPT_VALIDATE_STATE == STD_ON)
               returnValue = Gpt_ValidateMode(GPT_GET_PREDEF_TIMERVALUE_ID);
               if((Std_ReturnType)E_OK ==returnValue)
               {
#endif
                        channel = (Gpt_ChannelType)PredefTimer;
                        /** @violates @ref GPT_C_REF_9 MISRA 2004 Rule 17.4, Array indexing shall be the only allowed form of pointer */
                        Gpt_Ipw_GetPredefTimerValue(*((Gpt_pConfig->Gpt_pChannelPredefConfigType)+channel), PredefTimer, TimeValuePtr);
#if (GPT_VALIDATE_STATE == STD_ON)
               }
               else
               {
                   *TimeValuePtr = 0U;
               }
#endif
#if (GPT_VALIDATE_PARAM == STD_ON)
            }
            else
            {
                *TimeValuePtr = 0U;
            }

        }
        else
        {
            /* This else clause is required due to MISRA rules */
        }
#endif
#if (GPT_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
    return returnValue;
}
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
