/**
*   @file           Ocu.c
*   @implements     Ocu.c_Artifact
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - Ocu high level interface implementation.
*   @details        Ocu high level interface implementation.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* Ocu_MemMap.h included after each section define in order to set the current memory section
*
* @section Ocu_C_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Ocu_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Ocu_C_REF_4
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Ocu_C_REF_5
* Violates MISRA 2004 Required Rule 14.2, All non-null statements shall either: 
* a) have at least one side efect however executed, or
* b) cause control flow to change.
* The function might be empty for certain driver environments
*
* @section Ocu_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Ocu_C_REF_7
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
* are accessed from within a sigle function.
* These symbols are used in the entire driver.
*
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Ocu.c
*/
#include "Ocu.h"
#include "Ocu_Ipw.h"
#include "Ocu_Irq.h"
#include "Ocu_Ipw_Types.h"
#include "Mcal.h"

#if (OCU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Ocu.c
*/
#define OCU_VENDOR_ID_C                         43
#define OCU_AR_RELEASE_MAJOR_VERSION_C          4
#define OCU_AR_RELEASE_MINOR_VERSION_C          2
/*
* @violates @ref Ocu_C_REF_3 Identifier clash.
*/
/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_AR_RELEASE_REVISION_VERSION_C       2
#define OCU_SW_MAJOR_VERSION_C                  1
#define OCU_SW_MINOR_VERSION_C                  0
#define OCU_SW_PATCH_VERSION_C                  1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    /* Check if source file and DET header file are of the same version */
    #if ((OCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (OCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ocu.c and Det.h are different"
    #endif
#endif

/* Check if source file and Mcal header file are of the same version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (OCU_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Mcal.h are different"
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if source file and OCU header file are of the same vendor */
#if (OCU_VENDOR_ID_C != OCU_VENDOR_ID)
    #error "Ocu.c and Ocu.h have different vendor ids"
#endif
/* Check if source file and OCU header file are of the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C    != OCU_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION_C    != OCU_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION_C != OCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Ocu.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION_C != OCU_SW_MAJOR_VERSION)  || \
     (OCU_SW_MINOR_VERSION_C != OCU_SW_MINOR_VERSION)  || \
     (OCU_SW_PATCH_VERSION_C != OCU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu.c and Ocu.h are different"
#endif

/* Check if source file and Ocu_Ipw.h file are of the same vendor */
#if (OCU_VENDOR_ID_C != OCU_IPW_VENDOR_ID)
    #error "Ocu.c and Ocu_Ipw.h have different vendor ids"
#endif
/* Check if source file and Ocu_Ipw.h file are of the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C    != OCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION_C    != OCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION_C != OCU_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Ocu_Ipw.h are different"
#endif
/* Check if source file and Ocu_Ipw.h file are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION_C != OCU_IPW_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION_C != OCU_IPW_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION_C != OCU_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu.c and Ocu_Ipw.h are different"
#endif

/* Check if source file and Ocu_Irq.h file are of the same vendor */
#if (OCU_VENDOR_ID_C != OCU_IRQ_VENDOR_ID)
    #error "Ocu.c and Ocu_Irq.h have different vendor ids"
#endif
/* Check if source file and Ocu_Irq.h file are of the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C    != OCU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION_C    != OCU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION_C != OCU_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Ocu_Irq.h are different"
#endif
/* Check if source file and Ocu_Irq.h file are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION_C != OCU_IRQ_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION_C != OCU_IRQ_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION_C != OCU_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu.c and Ocu_Irq.h are different"
#endif

/* Check if source file and Ocu_Ipw_Types.h file are of the same vendor */
#if (OCU_VENDOR_ID_C != OCU_IPW_TYPES_VENDOR_ID)
    #error "Ocu.c and Ocu_Ipw_Types.h have different vendor ids"
#endif
/* Check if source file and Ocu_Ipw_Types.h file are of the same Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C    != OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION_C    != OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION_C != OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Ocu_Ipw_Types.h are different"
#endif
/* Check if source file and Ocu_Ipw_Types.h file are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION_C != OCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION_C != OCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION_C != OCU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu.c and Ocu_Ipw_Types.h are different"
#endif

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/
/**
@brief Enum containing the possible states of the Ocu driver
*/
typedef enum
{
    OCU_STATE_UNINIT = 0x00,
    OCU_STATE_IDLE
} Ocu_GlobalStateType;


/*===============================================================================================
*                                       LOCAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/
/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/**
@brief Pointer to the top level configuration structure - valid only when the driver is in the
       initialized state
* @violates @ref Ocu_C_REF_7 Objects shall be defined at block scope 
*/
static P2CONST(Ocu_ConfigType, OCU_VAR, OCU_APPL_CONST) Ocu_pConfig = NULL_PTR;

#if ((OCU_VALIDATE_GLOBAL_CONFIG_CALL  == STD_ON) || \
     (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON))
/**
@brief Variable storing the current state of the Ocu driver
* @violates @ref Ocu_C_REF_7 Objects shall be defined at block scope 
*/
static VAR(Ocu_GlobalStateType, OCU_VAR) Ocu_eGlobalState = OCU_STATE_UNINIT;
#endif

/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"


/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/**
* @brief    This arrays shall be used to store the internal running state of each OCU channel.
* @details  This array shall be initialized by Ocu_eTimer_Init() function and shall be used by all APIs' which 
            require a certain mode to function.
            Possible values for each channel: OCU_STATUS_UNINITIALIZED, OCU_STATUS_INITIALIZED, 
            OCU_STATUS_STOPPED, OCU_STATUS_RUNNING  
*/
/* @violates @ref Ocu_C_REF_7 Objects shall be defined at block scope
*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
VAR(Ocu_ChannelStatusType, OCU_VAR) aOcu_ChannelState[OCU_MAX_CHANNELS];

/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"


#define OCU_START_SEC_VAR_NO_INIT_BOOLEAN
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/**
* @brief    This arrays shall be used to store the Notification enabled information of all channels
* @details  This array shall be initialized by Ocu_eTimer_Init() function and shall be set / reset
*           by Ocu_EnableNotification and Ocu_DisableNotification functions.
*           Possible values for each channel: TRUE, FALSE
*/
/* @violates @ref Ocu_C_REF_7 Objects shall be defined at block scope 
*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
 VAR(boolean, OCU_VAR) Ocu_bNotificationEnabled[OCU_MAX_CHANNELS];

#define OCU_STOP_SEC_VAR_NO_INIT_BOOLEAN
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/
/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

#if (OCU_PRECOMPILE_SUPPORT == STD_ON)
    /* @violates @ref Ocu_C_REF_7 External declaration required. */
extern CONST(Ocu_ConfigType, OCU_CONST) Ocu_PBCfgVariantPredefined;
#endif

/* @violates @ref Ocu_C_REF_6 Identifier exceeds 31 chars. */
#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/
#define OCU_START_SEC_CODE
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    
LOCAL_INLINE FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateGlobalConfigCall
(
    VAR(uint8, AUTOMATIC) u8ServiceId
);

LOCAL_INLINE  FUNC(void, OCU_CODE) Ocu_EndValidateGlobalConfigCall
(
    VAR(Std_ReturnType, AUTOMATIC) ValidCall,
    VAR(uint8,          AUTOMATIC) u8ServiceId
);
    
#endif /* (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON) */

#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)

LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateChannelConfigCall
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId
);
#endif /* (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON) */

#if (OCU_PARAM_CHECK == STD_ON)

LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateParamPtrInit
(
    P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) ConfigPtr
);
    
#if (OCU_SET_PIN_STATE_API == STD_ON)    
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidatePinState
(
    VAR(Ocu_PinStateType, AUTOMATIC) PinState
);
#endif

LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateRunningState
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId  
);

#if (OCU_SET_PIN_ACTION_API == STD_ON)    
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidatePinAction
(
    VAR(Ocu_PinActionType, AUTOMATIC) PinAction
);    
#endif    

#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateCompareValue
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(Ocu_ValueType,   AUTOMATIC) CompareValue,
    VAR(uint8,           AUTOMATIC) u8ServiceId
);
#endif
    
#if ((OCU_SET_PIN_ACTION_API == STD_ON) || (OCU_SET_PIN_STATE_API == STD_ON))
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidatePinSetup
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId
);
#endif    
    
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)    
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateParamNotification
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId
);
#endif    

#endif /* (OCU_PARAM_CHECK == STD_ON) */
/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)

/**
* @brief          Validate the call of a function impacting the configuration of the entire driver.
* @details        Before executing, a function which changes the configuration of the entire driver
*                 shall check if:
*                 1. It is not preempting itself
*                 2. It is not preempting another function that changes the configuration of the 
*                    entire driver
*                 3. It is not preempting a function that changes the configuration of one of the
*                    driver's channels
*                 In any of the above cases, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      u8ServiceId       Id of the service calling this function
*
* @return         Std_ReturnType  Call is valid or not  
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
*
* @note           .
*/
LOCAL_INLINE FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateGlobalConfigCall
(
    VAR(uint8, AUTOMATIC) u8ServiceId
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    if (OCU_STATE_UNINIT == Ocu_eGlobalState)
    {
        if (OCU_INIT_ID != u8ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) OCU_MODULE_ID,
                (uint8)  OCU_INDEX,
                (uint8)  u8ServiceId,
                (uint8)  OCU_E_UNINIT
            );
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if (OCU_INIT_ID == u8ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) OCU_MODULE_ID,
                (uint8)  OCU_INDEX,
                (uint8)  u8ServiceId,
                (uint8)  OCU_E_ALREADY_INITIALIZED
            );
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    return retVal;
}


/**
* @brief          Completes the execution of a function impacting the configuration of the entire driver.
* @details        Performs actions in order to ensure that after it's caller has completed the execution
*                 the driver will remain in a state allowing execution of other functions updating the 
*                 configuration of the entire driver or of a single channel
*
* @param[in]      u8ServiceId  The service id of the caller function
* @param[in]      ValidCall    The function call was previously validated
* @return void
*
*
* @note           .
*/
LOCAL_INLINE  FUNC(void, OCU_CODE) Ocu_EndValidateGlobalConfigCall
(
    VAR(Std_ReturnType, AUTOMATIC) ValidCall,
    VAR(uint8,          AUTOMATIC) u8ServiceId
)
{
    /* Change the state of the driver only if the previous call to Ocu_ValidateGlobalConfigCall() 
    stated that the API call is valid, */
    if ((Std_ReturnType)E_OK == ValidCall)
    {
        if (OCU_DEINIT_ID == u8ServiceId)
        {
            Ocu_eGlobalState = OCU_STATE_UNINIT;
        }
        else
        {
            Ocu_eGlobalState = OCU_STATE_IDLE;
        }
    }
}
#endif /* (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON) */

#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)

/**
* @brief          Validate the call of a function impacting the configuration of one of the driver's
* @details        channels. Before executing, a function which changes the configuration of a 
*                 channel shall check if:
*                 1. It is not preempting itself
*                 2. It is not preempting a function that changes the configuration of the 
*                    entire driver
*                 In any of the above cases, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      ChannelId       Id of the channel the caller tries to update
* @param[in]      u8ServiceId       Id of the service calling this function
*
* @return         Std_ReturnType  Call is valid or not  
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
*
* @note           .
*/
LOCAL_INLINE FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateChannelConfigCall
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;

    /* Check if the driver is initialized */
    if (OCU_STATE_UNINIT == Ocu_eGlobalState)
    {
        /* Driver not initialized yet */
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  u8ServiceId,
            (uint8)  OCU_E_UNINIT
        );
    }
    else
    {
        /* Check that the channel is in valid range */
        if (ChannelNumber >= Ocu_pConfig->nNumChannels)
        {
            (void)Det_ReportError
            (
                (uint16) OCU_MODULE_ID,
                (uint8)  OCU_INDEX,
                (uint8)  u8ServiceId,
                (uint8)  OCU_E_PARAM_INVALID_CHANNEL
            );
        }
        else
        {   
            /* Driver is initialized and channel is valid */
            retVal = (Std_ReturnType)E_OK;   
        }
    }
    return retVal;    
}

#endif /* (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON) */

#if (OCU_PARAM_CHECK == STD_ON)

/**
* @brief          Validate the configuration parameter of the Ocu_Init API. The check is required
*                 only in variant Post-Build, where the pointer should not be NULL.In case an
*                 error is detected, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      ConfigPtr       Pointer to the configuration the driver is to be init with
*
* @return         Std_ReturnType  Validity of the pointer  
* @retval         E_OK            Pointer is valid
* @retval         E_NOT_OK        Pointer is invalid
*
*
* @note           .
*/
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateParamPtrInit
(
    P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) ConfigPtr
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
#if (OCU_PRECOMPILE_SUPPORT == STD_ON)
    /* Ignore compiler warning for pre-compile configurations */
    (void)ConfigPtr;
#endif /* (OCU_PRECOMPILE_SUPPORT == STD_ON) */

/* The function performs validation tests only for post-build configurations */
#if (OCU_PRECOMPILE_SUPPORT == STD_ON)
    /* Check if the config pointer received as param is NULL */
    if(NULL_PTR != ConfigPtr)
    {
#else
    if(NULL_PTR == ConfigPtr)
    {
#endif /* (OCU_PRECOMPILE_SUPPORT == STD_ON) */  
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  OCU_INIT_ID,
            (uint8)  OCU_E_INIT_FAILED
        );
        retVal = (Std_ReturnType)E_NOT_OK;        
    }
    return retVal;
}

/**
* @brief          Validate the running state for the given channel and API. 
* @details        For example: Ocu_StartChannel() can only be called if a channel 
*                 is not in  RUNNING mode, while Ocu_StopChannel() can only be called if 
*                 the channel is not STOPPED.                  
*
* @param[in]      ChannelNumber        Ocu channel ID
* @param[in]      u8ServiceId          Ocu service/API ID
*
* @return         Std_ReturnType  Validity of the parameter  
* @retval         E_OK            Parameter  is valid
* @retval         E_NOT_OK        Parameter  is invalid
*/     
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateRunningState
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId  
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    
    /* Check if the dutyCycle param is in valid range */
    if (OCU_STATUS_RUNNING == aOcu_ChannelState[ChannelNumber])
    {
        if(OCU_STARTCHANNEL_ID == u8ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) OCU_MODULE_ID,
                (uint8)  OCU_INDEX,
                (uint8)  OCU_STARTCHANNEL_ID,
                (uint8)  OCU_E_BUSY
            );
            
            nRetVal = (Std_ReturnType)E_NOT_OK;   
        }    
#if (OCU_SET_PIN_STATE_API == STD_ON)          
        else if(OCU_SETPINSTATE_ID == u8ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) OCU_MODULE_ID,
                (uint8)  OCU_INDEX,
                (uint8)  OCU_SETPINSTATE_ID,
                (uint8)  OCU_E_PARAM_INVALID_STATE
            );
            nRetVal = (Std_ReturnType)E_NOT_OK;   
        }
#endif  

#if (OCU_DEINIT_API == STD_ON)
    else if(OCU_DEINIT_ID == u8ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16) OCU_MODULE_ID,
                (uint8)  OCU_INDEX,
                (uint8)  OCU_DEINIT_ID,
                (uint8)  OCU_E_PARAM_INVALID_STATE
            );
            nRetVal = (Std_ReturnType)E_NOT_OK;   
        }
#endif  
        else
        {
            /*do nothing*/
        }
    }

    if ((OCU_STOPCHANNEL_ID == u8ServiceId) && (OCU_STATUS_STOPPED == aOcu_ChannelState[ChannelNumber]))
    {
        nRetVal = (Std_ReturnType)E_NOT_OK;        
    }
    
    return nRetVal;
}

#if (OCU_SET_PIN_STATE_API == STD_ON)  
/**
* @brief          Validate the PinState parameter (only OCU_LOW and OCU_HIGH are allowed) . In case an
*                 error is detected, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      PinState        Pin State level
*
* @return         Std_ReturnType  Validity of the parameter  
* @retval         E_OK            Parameter  is valid
* @retval         E_NOT_OK        Parameter  is invalid
*/  
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidatePinState
(
   VAR(Ocu_PinStateType, AUTOMATIC) PinState
)
{

    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    
    /* Check if the dutyCycle param is in valid range */
    if ((PinState != OCU_LOW) && (PinState != OCU_HIGH))
    {
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  OCU_SETPINSTATE_ID,
            (uint8)  OCU_E_PARAM_INVALID_STATE
        );
        nRetVal = (Std_ReturnType)E_NOT_OK;        
    }
    return nRetVal;   
}
#endif

#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
* @brief          Validate the Compare match Value parameter against the maximum counter value.*                 
*                 In case an error is detected, the function will report an error to Det
*
* @param[in]      ChannelId       Id of the channel the caller tries to update
* @param[in]      CompareValue    Value of the compare match
* @param[in]      u8ServiceId     Id of the service calling this function
*
* @return         Std_ReturnType  Validity of the parameter  
* @retval         E_OK            Parameter  is valid
* @retval         E_NOT_OK        Parameter  is invalid
*/     
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateCompareValue
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(Ocu_ValueType,   AUTOMATIC) CompareValue,
    VAR(uint8,           AUTOMATIC) u8ServiceId
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    VAR(Ocu_ValueType,  AUTOMATIC) MaxCounterValue = 0U;
    
    MaxCounterValue = (uint16)Ocu_Ipw_GetMaxCountValue(ChannelNumber);
    
    /* Check if the dutyCycle param is in valid range */
    if ((uint32)MaxCounterValue < (uint32)CompareValue)
    {
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  u8ServiceId,
            (uint8)  OCU_E_PARAM_INVALID_VALUE
        );
        nRetVal = (Std_ReturnType)E_NOT_OK;        
    }
    return nRetVal;   

}
#endif

#if ((OCU_SET_PIN_ACTION_API == STD_ON) || (OCU_SET_PIN_STATE_API == STD_ON))
/**
* @brief          Validate if Output Pin is enabled for a certain channel.                 
*                 In case an error is detected, the function will report an error to Det
*
* @param[in]      ChannelId       Id of the channel the caller tries to update
* @param[in]      u8ServiceId     Id of the service calling this function
*
* @return         Std_ReturnType  Validity of the parameter  
* @retval         E_OK            Parameter  is valid
* @retval         E_NOT_OK        Parameter  is invalid
*/     
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidatePinSetup
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    VAR(boolean,        AUTOMATIC) PinConfigStatus = (boolean)TRUE;
    
    PinConfigStatus = (*Ocu_pConfig->pOcuChannelsConfig)[ChannelNumber].bOcuOutputPinEnable;
    /* Check if the dutyCycle param is in valid range */
    
    if ((boolean)TRUE != PinConfigStatus)
    {
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  u8ServiceId,
            (uint8)  OCU_E_PARAM_NO_PIN
        );
        nRetVal = (Std_ReturnType)E_NOT_OK;        
    }
    return nRetVal;  
}
#endif  /* ((OCU_SET_PIN_ACTION_API == STD_ON) || (OCU_SET_PIN_STATE_API == STD_ON)) */

#if (OCU_SET_PIN_ACTION_API == STD_ON)
/**
* @brief          Validate the PinAction parameter (only OCU_SET_LOW, OCU_SET_HIGH, OCU_TOGGLE and 
*                 OCU_DISABLE are allowed). In case an error is detected, the function will report 
*                 an error to Det, depending on the environment the driver is run in.
*
* @param[in]      PinAction        Pin Action type
*
* @return         Std_ReturnType  Validity of the parameter  
* @retval         E_OK            Parameter  is valid
* @retval         E_NOT_OK        Parameter  is invalid
*/     
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidatePinAction
(
    VAR(Ocu_PinActionType, AUTOMATIC) PinAction  
)
{ 

    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    
    /* Check if the dutyCycle param is in valid range */
    if ((PinAction != OCU_SET_LOW) && (PinAction != OCU_SET_HIGH) && (PinAction != OCU_TOGGLE) && (PinAction != OCU_DISABLE))
    {
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  OCU_SETPINACTION_ID,
            (uint8)  OCU_E_PARAM_INVALID_ACTION
        );
        nRetVal = (Std_ReturnType)E_NOT_OK;        
    }
    return nRetVal;   

}  
#endif 
 
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)

/**
* @brief          Validate the notification handler of a Ocu channel.
*                 In order to be valid, the notification handler should not be
*                 NULL. In case it is NULL, the function will report an error to 
*                 Det or Serr,depending on the environment the driver is run in.
*
*
* @param[in]      ChannelNumber   The Id of the given channel
* @param[in]      Notification    The notification edge type
*
* @return         Std_ReturnType  Validity of notification handler  
* @nRetVal        E_OK            Notification handler is valid
* @nRetVal        E_NOT_OK        Notification handler is not valid
*
*
* @note           .
*/
LOCAL_INLINE  FUNC(Std_ReturnType, OCU_CODE) Ocu_ValidateParamNotification
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId 
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;
    VAR(Ocu_NotifyType, AUTOMATIC) pOcuChannelNotification;

    pOcuChannelNotification = (*Ocu_pConfig->pOcuChannelsConfig)[ChannelNumber].pfOcuChannelNotification;
    /* Check if Notification param is not NULL */
    if(NULL_PTR == pOcuChannelNotification)
    {
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  u8ServiceId,
            (uint8)  OCU_E_NO_VALID_NOTIF
        );
        nRetVal = (Std_ReturnType)E_NOT_OK;  
    }

    return nRetVal;   
}
#endif /* (OCU_NOTIFICATION_SUPPORTED == STD_ON) */  

#endif /* (OCU_PARAM_CHECK == STD_ON) */    
    
/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/

/**
* @brief        This function initializes the Ocu driver.
* @details      The function Ocu_Init shall initialize all internals variables and the used
*               OCU structure of the microcontroller according to the parameters
*               specified in ConfigPtr.
*               Ocu shall initialize the free-running timers that are used by the driver.
*              
*               If development error detection is enabled, calling the routine with a NULL ConfigPtr, 
*               Ocu_Init shall raise the development error OCU_E_INIT_FAILED and retunr without any 
*               action.
*              
*               If development error detection is enabled, calling the routine Ocu_Init
*               while the OCU driver and hardware are already initialized will cause a
*               development error OCU_E_ALREADY_INITIALIZED.
*               The desired functionality shall be left without any action.
*
*               For pre-compile and link time configuration variants, a NULL pointer shall be passed
*               to the initialization routine. In this case the check for this NULL pointer
*               has to be omitted.
*
*               If development error detection for the Ocu module is enabled, if any function
*               (except Ocu_Init) is called before Ocu_Init has been called, the called function
*               shall raise development error OCU_E_UNINIT.
*
* @param[in]    ConfigPtr       pointer to OCU top configuration structure
*
* @return       void
*
* @api
*
* @implements   Ocu_Init_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_Init
(
    P2CONST(Ocu_ConfigType, AUTOMATIC, OCU_APPL_CONST) ConfigPtr
)
{
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON) || (OCU_PARAM_CHECK == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)  CallIsValid;
#endif
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber;
     
#if (OCU_PRECOMPILE_SUPPORT == STD_ON)
    (void)ConfigPtr;
#endif
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Ocu_ValidateGlobalConfigCall(OCU_INIT_ID);
    if((Std_ReturnType)E_OK == CallIsValid)
    {
#endif /* OCU_VALIDATE_GLOBAL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)
        CallIsValid = Ocu_ValidateParamPtrInit(ConfigPtr);
        
        if((Std_ReturnType)E_OK == CallIsValid)
        {

#endif /* OCU_PARAM_CHECK */                    
            /* All validations passed. Here starts the actual
             functional code of the function */
            
            /* Save configuration pointer in global variable */
#if (OCU_PRECOMPILE_SUPPORT == STD_ON)
            Ocu_pConfig = &Ocu_PBCfgVariantPredefined;
#else
            Ocu_pConfig = ConfigPtr;
#endif
            for(ChannelNumber = 0U; ChannelNumber < OCU_MAX_CHANNELS; ChannelNumber++)
            {
                /*initialize global data*/
                aOcu_ChannelState[ChannelNumber] = OCU_STATUS_INITIALIZED;
                
                /* disable Notifications */
                Ocu_bNotificationEnabled[ChannelNumber] = (boolean)FALSE;
            }

            Ocu_Ipw_Init(
                            &Ocu_pConfig->IpConfig
                        #if (OCU_DOWNCOUNTING_SUPPORED == STD_ON)
                            ,
                            Ocu_pConfig -> eCountDir
                        #endif
                        );

#if (OCU_PARAM_CHECK == STD_ON)         
        }
#endif /* OCU_PARAM_CHECK */             

#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }
    /*
    * @violates @ref Ocu_C_REF_5 All non-null statements shall either a)have at least
    * one side efect however executed, or b)cause control flow to change.
    */
    Ocu_EndValidateGlobalConfigCall(CallIsValid, OCU_INIT_ID);
#endif /* OCU_VALIDATE_GLOBAL_CONFIG_CALL */
}


/*===============================================================================================*/
#if (OCU_DEINIT_API == STD_ON)
/**
* @brief        This function deinitializes the Ocu driver.
* @details      The function Ocu_DeInit shall deinitialize the OCU module.
*
*               The function Ocu_DeInit shall deinitialize the OCU variables and registers that were 
*               initialized by Ocu_Init to a state comparable to their power on reset state.
*               The function Ocu_DeInit shall disable OCU interrupts and OCU signal edge notifications.
*               The function Ocu_DeInit shall stop all free-running counters, which are exclusively
*               used by this driver.
*               If development error detection for the Ocu module is enabled,
*               when a development error occurs, the corresponding OCU function shall:
*                    Report the error to the Development Error Tracer.
*                    Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).                  
*               If development error detection is enabled for the OCU driver: if a channel is still in 
*               the RUNNING state when the function Ocu_DeInit is called, then the function shall raise
*               the development error OCU_E_PARAM_INVALID_STATE and return without any action.
*               If development error detection for the Ocu module is enabled, if any function
*               (except Ocu_Init) is called before Ocu_Init has been called, the called function
*               shall raise development error OCU_E_UNINIT.
*
* @return       void
*
* @api
*
* @implements   Ocu_DeInit_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_DeInit
(
    void
)
{
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber;
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) CallIsValid = Ocu_ValidateGlobalConfigCall(OCU_DEINIT_ID);

    if((Std_ReturnType)E_OK == CallIsValid)
    {
#endif /* OCU_VALIDATE_GLOBAL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)

        for(ChannelNumber = 0U; ChannelNumber < OCU_MAX_CHANNELS; ChannelNumber++)
        {
            if((Std_ReturnType)E_NOT_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_DEINIT_ID))
            {
                CallIsValid = (Std_ReturnType)E_NOT_OK;
            }
        }
        if((Std_ReturnType)E_OK == CallIsValid)
        {
#endif /* OCU_PARAM_CHECK */
            /* All validations passed. Here starts the actual
            functional code of the function */
            Ocu_Ipw_DeInit(&Ocu_pConfig->IpConfig);
    
            for(ChannelNumber = 0U; ChannelNumber < OCU_MAX_CHANNELS; ChannelNumber++)
            {
                /* initialize global data */  
                aOcu_ChannelState[ChannelNumber] = OCU_STATUS_UNINITIALIZED;
                
                /* disable Notifications */
                Ocu_bNotificationEnabled[ChannelNumber] = (boolean)FALSE;
            }
    
            /* Set global configuration pointer back to NULL, flagging that
            the driver is deinitialized */
            Ocu_pConfig = NULL_PTR;
        
#if (OCU_PARAM_CHECK == STD_ON)
        }
#endif /* OCU_PARAM_CHECK */

        
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }
    /*
    * @violates @ref Ocu_C_REF_5 All non-null statements shall either a)have at least
    * one side efect however executed, or b)cause control flow to change.
    */
    Ocu_EndValidateGlobalConfigCall(CallIsValid, OCU_DEINIT_ID);   
#endif /* OCU_VALIDATE_GLOBAL_CONFIG_CALL */
}
#endif /* (OCU_DEINIT_API == STD_ON) */

/*===============================================================================================*/
/**
* @brief            This function starts a specified Ocu channel.
* @details          The function Ocu_StartChannel shall start an OCU channel by allowing all
*                   compare match configured actions to be performed.
*
*                   The state of the selected channel shall be set to RUNNING If the function 
*                   Ocu_StartChannel has been successfully performed.
*
*                   If development error detection is enabled for the OCU driver: If the function
*                   Ocu_StartChannel is called on a channel in the state RUNINNG, then the function
*                   shall raise the error OCU_E_BUSY and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration), 
*                   the function Ocu_StartChannel shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver is 
*                   not initialized, the function Ocu_StartChannel shall raise the error OCU_E_UNINIT 
*                   and return without any action.
*
* @param[in]        ChannelNumber       Ocu channel id
*
* @return void
*
* @api
*
* @implements       Ocu_StartChannel_Activity
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_StartChannel
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber
)
{
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_STARTCHANNEL_ID))
    {
    
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_STARTCHANNEL_ID))
        {
#endif     /*OCU_PARAM_CHECK*/  
            
            /*set channel status to RUNNING*/  
            aOcu_ChannelState[ChannelNumber] = OCU_STATUS_RUNNING;
  
            /* All validations passed. Here starts the actual
            functional code of the function */
            Ocu_Ipw_StartChannel(ChannelNumber);       

#if (OCU_PARAM_CHECK == STD_ON)
        }
#endif     /*OCU_PARAM_CHECK*/
         
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */   
}

/*===============================================================================================*/
/**
* @brief            This function stops a specified Ocu channel.
* @details          The function Ocu_StopChannel shall stop an OCU channel by halting compare 
*                   match configured actions for this channel.
*
*                   The state of the selected channel shall be set to STOPPED if the function
*                   Ocu_StopChannel is successfully performed. If the function Ocu_StopChannel is
*                   called on a channel in the state STOPPED, then the function shall leave
*                   without any action (no change of the channel state), and shall not raise 
*                   a development error.
*                  
*                   If development error detection is enabled for the OCU driver: If the parameter 
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_StopChannel shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver 
*                   is not initialized, the function Ocu_StopChannel shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel id
*
* @return           void
*
* @api
*
* @implements       Ocu_StopChannel_Activity
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*
*/
FUNC(void, OCU_CODE) Ocu_StopChannel
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber
)
{
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_STOPCHANNEL_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */      

#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_STOPCHANNEL_ID))
        {
#endif     /*OCU_PARAM_CHECK*/   
       
            /*set channel status to RUNNING*/              
            aOcu_ChannelState[ChannelNumber] = OCU_STATUS_STOPPED;       
            
            /* All validations passed. Here starts the actual
            functional code of the function */
            Ocu_Ipw_StopChannel(ChannelNumber);      
#if (OCU_PARAM_CHECK == STD_ON)
        }
#endif     /*OCU_PARAM_CHECK*/
         
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */       
}

/*===============================================================================================*/
#if (OCU_SET_PIN_STATE_API == STD_ON)
/**
* @brief            Service to set immediately the level of the pin associated to an OCU channel.
* @details          The function Ocu_SetPinState shall set the pin associated with the channel 
*                   to the level indicated by PinState.
*
*                   The function Ocu_SetPinState shall be used only if the channel is not in the 
*                   RUNNING state.
*
*                   If development error detection is enabled for the OCU driver: If the parameter 
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_SetPinState shall raise the error OCU_E_PARAM_INVALID_CHANNEL 
*                   and return without any action
*
*                   If development error detection is enabled for the OCU driver: If a pin is not 
*                   associated with the channel (not defined in the configuration of the channel),
*                   the function Ocu_SetPinState shall raise the error OCU_E_PARAM_NO_PIN and
*                   return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter 
*                   PinState is invalid (not within the range specified by the configuration), 
*                   the function Ocu_SetPinState shall raise the error OCU_E_PARAM_INVALID_STATE 
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver
*                   is not initialized, the function Ocu_SetPinState shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the channel 
*                   is in the RUNNING state, the function Ocu_SetPinState shall raise the error
*                   OCU_E_PARAM_INVALID_STATE and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel id
* @param[in]        PinState      - Output Pin State
*
* @return           void
*
* @api
*
* @implements       Ocu_SetPinState_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_SetPinState
(
    VAR(Ocu_ChannelType,  AUTOMATIC) ChannelNumber,
    VAR(Ocu_PinStateType, AUTOMATIC) PinState
)
{
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETPINSTATE_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidatePinState(PinState))
        {
            if((Std_ReturnType)E_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_SETPINSTATE_ID))
            {
                if ((Std_ReturnType)E_OK == Ocu_ValidatePinSetup(ChannelNumber, OCU_SETPINSTATE_ID))
                {
#endif /* OCU_PARAM_CHECK */ 
                    /* All validations passed. Here starts the actual
                    functional code of the function */
                    Ocu_Ipw_SetPinState(ChannelNumber, PinState);
#if (OCU_PARAM_CHECK == STD_ON)
                }
            }
        }
#endif /* OCU_PARAM_CHECK */ 
            
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }
 
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */       
}
#endif /* OCU_SET_OUTPUT_TO_IDLE_API */

/*===============================================================================================*/
#if (OCU_SET_PIN_ACTION_API == STD_ON)
/**
* @brief            Service to indicate the driver what shall be done automatically by hardware 
*                   (if supported) upon compare match.
* @details          The function Ocu_SetPinAction shall set the action to be performed by hardware
*                   automatically, at the next compare match in the corresponding OCU channel.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_SetPinAction shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If a pin is not
*                   associated with the channel (not defined in the configuration of the channel),
*                   the function Ocu_SetPinAction shall raise the error OCU_E_PARAM_NO_PIN and 
*                   return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   PinAction is invalid (not within the range specified by the type), the function
*                   Ocu_SetPinAction shall raise the error OCU_E_PARAM_INVALID_ACTION and return 
*                   without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver 
*                   is not initialized, the function Ocu_SetPinAction shall raise the error 
*                   OCU_E_UNINIT and return without any action.
*
*                   If a pin is associated with a channel; the relevant action with this pin shall
*                   be performed upon compare match.
*
* @param[in]        ChannelNumber - Ocu channel id
* @param[in]        PinAction     - Pin Action (OCU_SET_LOW, OCU_SET_HIGH, OCU_TOGGLE, OCU_DISABLE)
*
* @return           void
*
* @api
*
* @implements       Ocu_SetPinAction_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_SetPinAction
(
    VAR(Ocu_ChannelType,   AUTOMATIC) ChannelNumber,
    VAR(Ocu_PinActionType, AUTOMATIC) PinAction
)
{
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETPINACTION_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidatePinAction(PinAction))
        {
            if ((Std_ReturnType)E_OK == Ocu_ValidatePinSetup(ChannelNumber, OCU_SETPINACTION_ID))
            {
#endif /* OCU_PARAM_CHECK */ 
                if (OCU_STATUS_RUNNING == aOcu_ChannelState[ChannelNumber])
                {
                    /* Call the Ipw function to set pin action */
                    Ocu_Ipw_SetPinAction(ChannelNumber, PinAction, (boolean)TRUE);
                }
                else
                {
                    /* Call the Ipw function to set pin action */
                    Ocu_Ipw_SetPinAction(ChannelNumber, PinAction, (boolean)FALSE);
                }
#if (OCU_PARAM_CHECK == STD_ON)
            }
        }
#endif /* OCU_PARAM_CHECK */  
 
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }
 
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */       
}
#endif /* OCU_SET_OUTPUT_TO_IDLE_API */

/*===============================================================================================*/
#if (OCU_GET_COUNTER_API == STD_ON)
/**
* @brief            Service to read the current value of the counter.
* @details          The function Ocu_GetCounter shall read and return the value of the counter of
*                   the channel indicated by ChannelNumber.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration), 
*                   the function Ocu_GetCounter shall raise the error OCU_E_PARAM_INVALID_CHANNEL 
*                   and shall return the value 0.
*
*                   If development error detection is enabled for the OCU driver: if the driver is
*                   not initialized, then the function Ocu_GetCounterValue shall raise the error 
*                   OCU_E_UNINIT and shall return the value 0.
*
* @param[in]        ChannelNumber  Ocu channel id
*
* @return           Ocu_ValueType  the value of the hardware counter.
*
* @api
*
* @implements       Ocu_GetCounter_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(Ocu_ValueType, OCU_CODE) Ocu_GetCounter
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber
)
{
    VAR(Ocu_ValueType, AUTOMATIC) retVal = (Ocu_ValueType)0U;

#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_GETCOUNTER_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

        /* All validations passed. Here starts the actual
        functional code of the function */
        retVal = Ocu_Ipw_GetCounter(ChannelNumber);
        
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */       

    return (Ocu_ValueType)retVal;
}
#endif /* OCU_GET_OUTPUT_STATE_API */

/*===============================================================================================*/
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This service is used to disable notifications from an OCU channel.
* @details          The function Ocu_DisableNotification shall disable the OCU compare match 
*                   notification.
*
*                   If development error detection is enabled for the OCU driver: If the driver 
*                   is not initialized, the function Ocu_DisableNotification shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   Channel is invalid (not within the range specified by configuration), the 
*                   function Ocu_DisableNotification shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the 
*                   notification function is the NULL pointer, the function Ocu_DisableNotification 
*                   shall raise the error OCU_E_NO_VALID_NOTIF and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel id
*
* @return           void
*
* @api
*
* @implements       Ocu_DisableNotification_Activity
*
*/

/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_DisableNotification
(
    VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber
)
{
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_DISABLENOTIFICATION_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidateParamNotification(ChannelNumber, OCU_DISABLENOTIFICATION_ID))
        {
#endif
            /* disable Notifications */
            Ocu_bNotificationEnabled[ChannelNumber] = (boolean)FALSE;
#if (OCU_PARAM_CHECK == STD_ON)
        }
#endif
 
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */       
}
#endif /* OCU_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This service is used to enable notifications from an OCU channel.
* @details          The function Ocu_EnableNotification shall enable the OCU compare match 
*                   notification of the indexed channel.
*
*                   If development error detection is enabled for the OCU driver: If the driver is 
*                   not initialized, the function Ocu_EnableNotification shall raise the error 
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter 
*                   Channel is invalid (not within the range specified by configuration), then the 
*                   function Ocu_EnableNotification shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*           
*                  If development error detection is enabled for the OCU driver: If the notification 
*                  function is the NULL pointer, the function Ocu_EnableNotification shall raise the 
*                  error OCU_E_NO_VALID_NOTIF and return without any action. 
*
* @param[in]        ChannelNumber - Ocu channel id
* @param[in]        Notification  - notification type to be enabled
*
* @return           void
*
* @api
*
* @implements       Ocu_EnableNotification_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_EnableNotification
(
    VAR(Ocu_ChannelType,          AUTOMATIC) ChannelNumber
)
{
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_ENABLENOTIFICATION_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */
#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidateParamNotification(ChannelNumber, OCU_ENABLENOTIFICATION_ID))
        {
#endif
            /* enable Notifications */
            Ocu_bNotificationEnabled[ChannelNumber] = (boolean)TRUE;
#if (OCU_PARAM_CHECK == STD_ON)
        }
#endif
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }
 
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */  
}
#endif /* OCU_NOTIFICATION_SUPPORTED */

/*===============================================================================================*/
#if (OCU_VERSION_INFO_API == STD_ON)
/**
* @brief            This function returns Ocu driver version details
* @details          The function Ocu_GetVersionInfo shall return the version information of this module.
*                   The version information includes: Module Id, Vendor Id, Vendor specific version number.
*
* @param[in,out]    versioninfo - pointer to Std_VersionInfoType output variable
*
* @return           void
*
* @api
*
* @implements       Ocu_GetVersionInfo_Activity
*
*/
/*
* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_GetVersionInfo
(
    P2VAR(Std_VersionInfoType , AUTOMATIC, OCU_APPL_DATA) versioninfo
)
{
#if (OCU_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR != versioninfo)
    {
#endif /* OCU_DEV_ERROR_DETECT */

        (versioninfo)->vendorID         = (uint16)OCU_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)OCU_MODULE_ID;

        (versioninfo)->sw_major_version = (uint8)OCU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)OCU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)OCU_SW_PATCH_VERSION;

#if (OCU_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        (void)Det_ReportError
        (
            (uint16) OCU_MODULE_ID,
            (uint8)  OCU_INDEX,
            (uint8)  OCU_GETVERSIONINFO_ID,
            (uint8)  OCU_E_PARAM_POINTER
        );
    }
#endif /* OCU_DEV_ERROR_DETECT */
}
#endif /* OCU_VERSION_INFO_API */

/*===============================================================================================*/
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief         Ocu_Notification
* @details       This function is called from Ocu_Ipw.c file in order to forward a 
*                channel notification call from the IP configuration. 
*                   
* @param         u8HwChannel - Hw channel for which notification should be called 
* @return        Void
*
* @implements       Ocu_Notification_Activity
*
*/
FUNC(void, OCU_CODE) Ocu_Notification
(
    VAR(Ocu_ChannelType, AUTOMATIC) u8HwChannel
)
{
    VAR(uint8,          AUTOMATIC) u8LogicChannel;
    VAR(Ocu_NotifyType, AUTOMATIC) pfNotify;
    
    if(NULL_PTR != Ocu_pConfig)
    {
        u8LogicChannel = (uint8)((*Ocu_pConfig->HwToLogicChannelMap)[u8HwChannel]);
        /* Check that there is a logic channel associated with the Hw one */
        pfNotify = (*Ocu_pConfig->pOcuChannelsConfig)[u8LogicChannel].pfOcuChannelNotification;
        /* Check that a notification is defined for the associated 
        logic channel. This is a double check not necessarily needed because if notification were
        enabled in IP layer for the channel that generated the interrupt causing this notify to
        be called, it means that this channel cannot have a null notification, otherwise notification
        could not have been enabled  */
        if((NULL_PTR != pfNotify) && ((boolean)TRUE == Ocu_bNotificationEnabled[u8LogicChannel]))
        {
            pfNotify();
        }
    }
}
#endif /* (OCU_NOTIFICATION_SUPPORTED == STD_ON) */

/*===============================================================================================*/
#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/**
* @brief            Service to set the value of the channel threshold using an absolute input data.
* @details          The function Ocu_SetAbsoluteThreshold shall set the channel threshold 
*                   (the compare value) to the value given by AbsoluteValue.
*
*                   If development error detection is enabled for the OCU driver: If the driver is 
*                   not initialized, the function Ocu_SetAbsoluteThreshold shall raise the error 
*                   OCU_E_UNINIT and return without any action.
*         
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration), 
*                   the function Ocu_SetAbsoluteThreshold shall raise the error 
*                   OCU_E_PARAM_INVALID_CHANNEL and return without any action.         
*
*                   After setting a new threshold value, the API Ocu_SetAbsoluteThreshold shall 
*                   return a status to inform the caller whether the compare match will occur 
*                   (or has already occurred) during the current Reference Interval, as a result 
*                   of setting the new threshold value. (see OCU_SWS for details)
*
* @param[in]        ChannelNumber  - Ocu channel id
* @param[in]        ReferenceValue - Value given by the upper layer and used as a base to determine
*                                    whether to call the notification before the function exits
*                                     or not.
* @param[in]        AbsoluteValue  - Value to compare with the content of the counter. 
*                                    This value is in ticks.
*
* @return           Ocu_ReturnType - Tells the caller whether the compare match will occur 
*                                    (or has already occurred) during the current Reference Interval,
*                                    as a result of setting the new threshold value.
*
*
* @implements       Ocu_SetAbsoluteThreshold_Activity
*/
/*
* @violates @ref Ocu_C_REF_3 The respective code could not be made static because
*  of layers architecture design of the driver
*/
/* @violates @ref Ocu_C_REF_2 external ... could be made static */
FUNC(Ocu_ReturnType, OCU_CODE) Ocu_SetAbsoluteThreshold
(
   VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
   VAR(Ocu_ValueType,   AUTOMATIC) ReferenceValue,
   VAR(Ocu_ValueType,   AUTOMATIC) AbsoluteValue
)
{
    VAR(Ocu_ReturnType, AUTOMATIC)  StatusValue = OCU_CM_OUT_REF_INTERVAL;
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETABSOLUTETHRESHOLD_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidateCompareValue(ChannelNumber, ReferenceValue, OCU_SETABSOLUTETHRESHOLD_ID))
        {
            if((Std_ReturnType)E_OK == Ocu_ValidateCompareValue(ChannelNumber, AbsoluteValue, OCU_SETABSOLUTETHRESHOLD_ID))
            {
#endif
                StatusValue = Ocu_Ipw_SetAbsoluteThreshold(
                                                            ChannelNumber, 
                                                            ReferenceValue, 
                                                            AbsoluteValue                                                           
                                                           );
#if (OCU_PARAM_CHECK == STD_ON)
            }
        }
#endif

#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }

#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

    return StatusValue;
}
#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API */

/*===============================================================================================*/
#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
/**
* @brief            Service to set the value of the channel threshold relative to the current 
*                   value of the counter.
* @details          The function Ocu_SetAbsoluteThreshold shall set the channel threshold 
*                   (the compare value) to the value given by RelativeValue plus the current
*                   counter value read from hw.
*
*                   After setting a new threshold value, the API Ocu_SetRelativeThreshold shall 
*                   return a status to inform the caller whether the compare match will occur 
*                   (or has already occurred) during the current Reference Interval, as a result
*                   of setting the new threshold value.
*         
*                   If development error detection is enabled for the OCU driver: If the driver 
*                   is not initialized, the function Ocu_SetRelativeThreshold shall raise the
*                   error OCU_E_UNINIT and return without any action.       
*
*                   After setting a new threshold value, the API Ocu_SetRelativeThreshold shall
*                   return a status to inform the caller whether the compare match will occur 
*                   (or has already occurred) during the current Reference Interval, as a result
*                   of setting the new threshold value.
*
* @param[in]        ChannelNumber - Ocu channel id
* @param[in]        RelativeValue - Value to use for computing the new threshold.
*
* @return          Ocu_ReturnType - Tells the caller whether the compare match will occur 
*                                   (or has already occurred) during the current Reference
*                                   Interval, as a result of setting the new threshold value.
*
*
* @implements       Ocu_SetRelativeThreshold_Activity
*/
/*
* @violates @ref Ocu_C_REF_3 The respective code could not be made static because
*  of layers architecture design of the driver
*/
/* @violates @ref Ocu_C_REF_2 external ... could be made static */
FUNC(Ocu_ReturnType, OCU_CODE) Ocu_SetRelativeThreshold
(
   VAR(Ocu_ChannelType, AUTOMATIC) ChannelNumber,
   VAR(Ocu_ValueType,   AUTOMATIC) RelativeValue
)
{
    VAR(Ocu_ReturnType, AUTOMATIC)  StatusValue = OCU_CM_OUT_REF_INTERVAL;

#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETRELATIVETHRESHOLD_ID))
    {
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */
#if (OCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == Ocu_ValidateCompareValue(ChannelNumber, RelativeValue, OCU_SETRELATIVETHRESHOLD_ID))
        {
#endif
            StatusValue = Ocu_Ipw_SetRelativeThreshold(
                                                        ChannelNumber, 
                                                        RelativeValue
                                                      );   
#if (OCU_PARAM_CHECK == STD_ON)
        }
#endif
#if (OCU_VALIDATE_CHANNEL_CONFIG_CALL == STD_ON)
    }
#endif /* OCU_VALIDATE_CHANNEL_CONFIG_CALL */

    return StatusValue;
}
#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API */

/*===============================================================================================*/
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief            Implementation specific function to change the peripheral clock frequency.
* @details          This function is useful to set the prescalers that divide the OCU channels
*                   clock frequency.
*
* @param[in]        Prescaler - prescaler type 
*                   Possible values:    
* 
* @implements       Ocu_SetClockMode_Activity
*
*/
/* @violates @ref Ocu_C_REF_2 external ... could be made static
*/
FUNC(void, OCU_CODE) Ocu_SetClockMode(VAR(Ocu_SelectPrescalerType, AUTOMATIC) ePrescaler)
{
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)  CallIsValid;
#endif

#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    CallIsValid = Ocu_ValidateGlobalConfigCall(OCU_SETCLOCKMODE_ID);
    if((Std_ReturnType)E_OK == CallIsValid)
    {
#endif /* OCU_VALIDATE_GLOBAL_CONFIG_CALL */

        Ocu_Ipw_SetClockMode(&Ocu_pConfig->IpConfig, ePrescaler);
#if (OCU_VALIDATE_GLOBAL_CONFIG_CALL == STD_ON)
    }
    /*
    * @violates @ref Ocu_C_REF_5 All non-null statements shall either a)have at least
    * one side efect however executed, or b)cause control flow to change.
    */
    Ocu_EndValidateGlobalConfigCall(CallIsValid, OCU_SETCLOCKMODE_ID);
#endif /* OCU_VALIDATE_GLOBAL_CONFIG_CALL */
}
#endif /* OCU_SET_CLOCK_MODE_API */


#define OCU_STOP_SEC_CODE
/*
* @violates @ref Ocu_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_C_REF_4 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

