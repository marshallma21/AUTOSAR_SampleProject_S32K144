/**
*   @file    Adc.c
*   @implements        Adc_HLD_unit
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Common Level Driver source file.
*   @details Autosar layer of ADC MCAL driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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
* @section Adc_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* '#include' statements in a file should only be preceded by othe preprocessor directives or comments
*
* @section Adc_c_REF_2
* Violates MISRA 2004 Required Rule 16.4,
* The identifiers used in the declaration and definition of a function shall be identical
* 
* @section Adc_c_REF_3
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope 
* shall have internal linkage unless external linkage is required.
*
* @section Adc_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_c_REF_5
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance 
* and case sensitivity are supported for external identifiers.
*
* @section Adc_c_REF_6
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice
*
* @section Adc_c_REF_7
* Violates MISRA 2004 Required Rule 1.2, place reliance on undefined or unspecified behaviour
* This is used for the code complexity.
*
* @section Adc_c_REF_8
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_c_REF_10
* Violates MISRA 2004 Advisory Rule 11.4, cast from pointer to pointer. This is used for the Speed
* optimization of the memory access.
*
* @section Adc_c_REF_11
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope 
* if they are only accessed from within a single function.
*
* @section Adc_c_REF_12
* Violates MISRA 2004 Required Rule 16.10, If a function returns error information, then that error 
* information shall be tested.
*
* @section Adc_c_REF_13
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as an
* unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_c_REF_14
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, 
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc.h"
#include "Adc_Ipw.h"
#include "SchM_Adc.h"
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_C                         43
#define ADC_AR_RELEASE_MAJOR_VERSION_C          4
#define ADC_AR_RELEASE_MINOR_VERSION_C          2
/**
* @violates @ref Adc_c_REF_5 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_C       2
#define ADC_SW_MAJOR_VERSION_C                  1
#define ADC_SW_MINOR_VERSION_C                  0
#define ADC_SW_PATCH_VERSION_C                  1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_C != ADC_VENDOR_ID)
#error "Adc.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Adc.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Adc.c and Adc.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same vendor */
#if (ADC_VENDOR_ID_C != ADC_VENDOR_ID_IPW_H)
    #error "Adc.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC IPW header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
#error "AutoSar Version Numbers of Adc.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION_IPW_H) || \
     (ADC_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION_IPW_H) || \
     (ADC_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION_IPW_H) \
    )
#error "Software Version Numbers of Adc.c and Adc_Ipw.h are different"
#endif

/** @violates @ref Adc_c_REF_5 Identifier clash */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and DET header file are of the same version */
 #if (ADC_DEV_ERROR_DETECT == STD_ON)
    #if ((ADC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ADC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
    #error "AutoSar Version Numbers of Adc.c and Det.h are different"
    #endif
 #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#ifdef ADC_PRECOMPILE_SUPPORT
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

/** @violates @ref Adc_c_REF_11 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(Adc_ConfigType, ADC_CONST) Adc_PBCfgVariantPredefined;
    
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

/**
* @brief          Global Configuration Pointer.
* @details        Data structure containing the set of configuration parameters required for
*                 initializing the ADC Driver and ADC HW Unit(s).
*
*/
P2CONST(Adc_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr = NULL_PTR;

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
/**
* @brief          Global Driver Status.
* @details        Data structure containing the ADC driver status
*                 uninit, during init or already init.
*
*/
static VAR(Adc_GlobalStateType, ADC_VAR) Adc_eGlobalState = ADC_STATE_UNINIT;
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          Clock mode in use
* @details        The current used clock mode: normal or alternate clock. 
*/
VAR(Adc_DualClockModeType, AUTOMATIC) Adc_eClockMode = ADC_NORMAL;
#endif /*if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)*/
#endif /*if (ADC_DUAL_CLOCK_MODE == STD_ON)*/

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

/**
* @brief          Group status array structure
* @details        Array to hold all the group status information.
* @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
*/
VAR(Adc_GroupStatusType, ADC_VAR) Adc_aGroupStatus[ADC_MAX_GROUPS];

/**
* @brief          Unit status structure
* @details        Structure for the unit status.
* @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
* @violates @ref Adc_c_REF_11 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope
*/
VAR(Adc_UnitStatusType, ADC_VAR) Adc_aUnitStatus[ADC_MAX_HW_UNITS];

/**
* @brief          Runtime group channels array
* @details        Hold the runtime group channels.
* @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
* @violates @ref Adc_c_REF_11 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope
*/
#if (ADC_SETCHANNEL_API == STD_ON)
VAR(Adc_RuntimeGroupChannelType, ADC_VAR) Adc_aRuntimeGroupChannel[ADC_MAX_GROUPS];
#endif

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
static VAR(Adc_PowerStateType, ADC_VAR) Adc_eCurrentState;
static VAR(Adc_PowerStateType, ADC_VAR) Adc_eTargetState;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief          Unit status structure
* @details        Structure for the unit status.
*
*/
VAR(Adc_NcmrType, ADC_VAR) Adc_aNCMRxMask[ADC_NO_OF_ENABLE_CH_DISABLE_CH_GROUPS];
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
#define ADC_START_SEC_VAR_NO_INIT_8
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"
/**
* @brief          Active BCTU triggers for the group in the HW queue
* @details        This array is used in Adc_Adcdig_EnableCtuTrigger. For the group currently in the HW queue,
*                 if an element is 1 in this array, the corresponding trigger from the group's configuration structure
*                 has been activated.
* @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
*/
VAR(uint8, ADC_VAR) Adc_au8BctuGroupTriggersActive[ADC_MAX_HW_UNITS][ADC_MAX_HADRWARE_TRIGGERS];

#define ADC_STOP_SEC_VAR_NO_INIT_8
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

#if ((ADC_VALIDATE_PARAMS == STD_ON) && \
     ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      (ADC_HW_TRIGGER_API == STD_ON) || \
      (ADC_ENABLE_CTUTRIG_NONAUTO_API ==STD_ON) || \
      (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) \
     ) \
    )
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateExtraParams
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint32, AUTOMATIC) u32ErrorIdList,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndGroup
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
#if (ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_NotifyCapablity
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif
#endif

#if (ADC_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ReportDetError
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8ErrorId
);
#endif

#if ((ADC_DEV_ERROR_DETECT == STD_ON) && \
     ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      (ADC_HW_TRIGGER_API == STD_ON) || \
      (ADC_ENABLE_CTUTRIG_NONAUTO_API ==STD_ON) || \
      (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) \
     ) \
    )
static FUNC(void, ADC_CODE) Adc_ReportValidationError
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pResult,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8ErrorId
);
#endif

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateGloballCall
(
    VAR(uint8, AUTOMATIC) u8ServiceId
);
#endif

#if (ADC_VALIDATE_PARAMS == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePtrInit
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
);

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePtr
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2CONST(void, AUTOMATIC, ADC_APPL_CONST) pPtrVal
);

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))  
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateBufferUninit
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      (ADC_HW_TRIGGER_API == STD_ON) || \
      (ADC_ENABLE_CTUTRIG_NONAUTO_API ==STD_ON) || \
      (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) \
    )
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateTriggerSrc
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))  
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateQueueNotFull
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif


#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) || \
    (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateConvMode
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) 
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateEnableDisbleGroupList
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateEnableDisbleIdList
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_ChannelType, AUTOMATIC) Channel
);
#endif

#if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndTrigger
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8Trigger
);
#endif

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCtuTriggerSrc
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger
);
#endif

#ifdef ADC_VALIDATE_APP_BUFFER_ALIGNMENT
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateSetupBufferAlignment
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataBufferPtr
);
#endif

#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_SET_MODE_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateSetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) eSetMode
);
#endif

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_EndValidateGloballCall
(
    VAR(Std_ReturnType, AUTOMATIC) ValidCall,
    VAR(uint8, AUTOMATIC) u8ServiceId
);
#endif

#if (ADC_VALIDATE_STATE == STD_ON)
    
#if (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateDeInitNotBusy(void);
#endif /* (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__) */

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateSetupBufferNotBusy
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateStartGroupConvNotBusy
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__) */

#if ((ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__))
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateEnableHwTriggNotBusy
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* ((ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__)) */

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateNotIdle
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);

#if ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)))
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyWithPrio
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bImplicitly
);
#endif /* ((ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__))) */

#if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyEnableHwTrig
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyEnableCtuTrig
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && (ADC_ENABLE_START_STOP_GROUP_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE)Adc_ValidateNotBusyNoPrio
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bImplicitly
);
#endif /* ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)) */
#endif /* (ADC_VALIDATE_STATE == STD_ON) */

#if (((ADC_VALIDATE_STATE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) && (ADC_ENABLE_QUEUING == STD_OFF)) \
      || (((ADC_VALIDATE_STATE == STD_ON) && ((ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__)))         \
      || (ADC_CALIBRATION == STD_ON) || (ADC_DUAL_CLOCK_MODE == STD_ON)  || (ADC_SET_MODE_API == STD_ON)   \
         ) \
    )
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyNoQueue
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint8, AUTOMATIC) u8ServiceId
);
#endif

#if (((ADC_VALIDATE_STATE == STD_ON) && ((ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__))) \
      || (ADC_CALIBRATION == STD_ON) || (ADC_DUAL_CLOCK_MODE == STD_ON) || (ADC_SET_MODE_API == STD_ON) \
    )
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCheckGroupNotConversion
(
    VAR(uint8, AUTOMATIC) u8ServiceId
);
#endif /* (((ADC_VALIDATE_STATE == STD_ON) ... */


#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndGroup
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if (((ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) || (ADC_CALIBRATION == STD_ON) || (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)) && \
     (ADC_VALIDATE_CALL_AND_UNIT == STD_ON) \
    )
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndUnit
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_InitGroupsStatus(void);

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_InitUnitStatus(void);

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_InsertIntoQueue
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusStartConversion
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    CONST(Adc_HwUnitType, AUTOMATIC) Unit
);

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusStopConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif

#if (ADC_READ_GROUP_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusReadGroupNoInt
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    CONST(boolean, AUTOMATIC) bFlag
);

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusReadGroupInt
(
    CONST(Adc_GroupType, AUTOMATIC) Group
);
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusEnableHardware
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusDisableHardware
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusAfterGetStream
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);

#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateUnitActive
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateCtuControlMode
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateAndPtr
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
);
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateIdleState
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
);
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePowerStateSupport
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_PowerStateType, AUTOMATIC) ePowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
);
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePowerStatePrepare
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
);
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (ADC_DEV_ERROR_DETECT == STD_ON)
/**
* @brief      This function reports an error to the Det module and records the failure in the local structure.
* @details    This function reports an error to the Det module and records the failure in the local structure.
*
* @param[in]  u8ServiceId       The service id of the caller function
* @param[in]  u8ErrorId         The error id to be reported
*
* @return     void
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ReportDetError
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8ErrorId
)
{
    /** @violates @ref Adc_c_REF_12 The error information will be verified in application */
    Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, u8ServiceId, u8ErrorId);
}
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

#if ((ADC_DEV_ERROR_DETECT == STD_ON) && \
     ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      (ADC_HW_TRIGGER_API == STD_ON) || \
      (ADC_ENABLE_CTUTRIG_NONAUTO_API ==STD_ON) || \
      (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) \
     ) \
    )
/**
* @brief      This function reports an error to the Det module and records the failure in the local structure.
* @details    This function reports an error to the Det module and records the failure in the local structure.
*
* @param[in]  u8ServiceId       The service id of the caller function
* @param[in]  u8ErrorId         The error id to be reported
* @param[in]  pResult           Pointer to the structure where the failure must be recorded
*
* @return     void
*/
static FUNC(void, ADC_CODE) Adc_ReportValidationError
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pResult,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8ErrorId
)
{
    pResult->bEndValidations = (boolean)TRUE;
    pResult->ValidParams = (Std_ReturnType)E_NOT_OK;

    Adc_ReportDetError(u8ServiceId, u8ErrorId);
}
#endif

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
/**
* @brief      This function validates the global call parameters.
* @details    This service is a non reentrant function used for validating the calls for functions
*               like Adc_Init, Adc_DeInit.
*
* @param[in]  u8ServiceId       The service id of the caller function
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           Valid call
* @retval     E_NOT_OK:       Invalid call
*
* @api
*
* @note       Non Re-entrant function.
* @implements  Adc_ValidateGlobalCall_Activity
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateGloballCall
(
    VAR(uint8, AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;

    if (ADC_STATE_UNINIT == Adc_eGlobalState)
    {
        if (ADC_INIT_ID == u8ServiceId)
        {
            ValidState = (Std_ReturnType)E_OK;
        }
        else
        {
            Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_UNINIT);
        }
    }
    else
    {
        if (ADC_INIT_ID == u8ServiceId)
        {
            /* Error: ADC already initialized */
            Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_ALREADY_INITIALIZED);
        }
        else
        {
            ValidState = (Std_ReturnType)E_OK;
        }
    }

    return ValidState;
}
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
/**
* @brief      This function validates the global call parameters.
* @details    This service is a non reentrant function used for validating parameters
*               for Adc_Init.
*
* @param[in]  pConfigPtr   Pointer to configuration set in Variant PB
*                         (Variant PC requires a NULL_PTR).
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           Valid parameter
* @retval     E_NOT_OK:       Invalid parameter
*
* @api
*
* @note       Non Reentrant function.
* @implements  Adc_ValidatePtrInit_Activity
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePtrInit
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidPtr = (Std_ReturnType)E_OK;

#ifdef ADC_PRECOMPILE_SUPPORT
    /* ADC344 */
    if (NULL_PTR != pConfigPtr)
#else
    /* ADC343 */
    if (NULL_PTR == pConfigPtr)
#endif /* ADC_PRECOMPILE_SUPPORT */
    {
        ValidPtr = (Std_ReturnType)E_NOT_OK;
        Adc_ReportDetError((uint8)ADC_INIT_ID, (uint8) ADC_E_PARAM_CONFIG);
    }
    return ValidPtr;
}

/**
* @brief      This function validates the pointer is NULL or not
* @details    This service is a reentrant function used for validating parameters
*
* @param[in]  PtrVal          Pointer to validate
* @param[in]  u8ServiceId     The service id of the caller function
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           Valid parameter
* @retval     E_NOT_OK:       Invalid parameter
*
* @api
*
* @note       ...
* ADC_VALUEREADGROUP_ID
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePtr
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2CONST(void, AUTOMATIC, ADC_APPL_CONST) pPtrVal
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidPtr = (Std_ReturnType)E_OK;

    if (NULL_PTR == pPtrVal)
    {
        ValidPtr = (Std_ReturnType)E_NOT_OK;
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_PARAM_POINTER);
    }

    return ValidPtr;
}

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateBufferUninit
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    switch (u8ServiceId)
    {
        case ADC_STARTGROUPCONVERSION_ID:
#if (ADC_HW_TRIGGER_API == STD_ON)
        case ADC_ENABLEHARDWARETRIGGER_ID:
#endif /* ADC_HW_TRIGGER_API == STD_ON */
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (NULL_PTR == Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group])
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_BUFFER_UNINIT);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}
#endif

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      (ADC_HW_TRIGGER_API == STD_ON) || \
      (ADC_ENABLE_CTUTRIG_NONAUTO_API ==STD_ON) || \
      (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) \
    )
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateTriggerSrc
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    switch (u8ServiceId)
    {
        case ADC_STARTGROUPCONVERSION_ID:
        case ADC_STOPGROUPCONVERSION_ID:
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        case ADC_ENABLE_CHANNEL_ID:
        case ADC_DISABLE_CHANNEL_ID:
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (ADC_TRIGG_SRC_SW != Adc_pCfgPtr->pGroups[Group].eTriggerSource)
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_WRONG_TRIGG_SRC);
            }
            break;
        }
#if (ADC_HW_TRIGGER_API == STD_ON)
        case ADC_ENABLEHARDWARETRIGGER_ID:
        case ADC_DISABLEHARDWARETRIGGER_ID:
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
        case ADC_ENABLECTUTRIGGER_ID:
        case ADC_DISABLECTUTRIGGER_ID:
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (ADC_TRIGG_SRC_SW == (Adc_pCfgPtr->pGroups[Group].eTriggerSource))
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_WRONG_TRIGG_SRC);
            }
            break;
        }
#endif /* ADC_HW_TRIGGER_API == STD_ON */
        default:
        {
            break;
        }
    }
}
#endif

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateQueueNotFull
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{

    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
#if (ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_GroupConvType, AUTOMATIC) eType;
    VAR(Adc_QueueIndexType, AUTOMATIC) HwInjectedQueueIndex;
    VAR(Adc_QueueIndexType, AUTOMATIC) HwNormalQueueIndex;
#endif /* ADC_HW_TRIGGER_API == STD_ON */

    switch (u8ServiceId)
    {
        case ADC_STARTGROUPCONVERSION_ID:
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic shall be the only allowed form of pointer arithmetic */
            if (ADC_CONV_TYPE_NORMAL == Adc_pCfgPtr->pGroups[Group].eType)
            {
                if (Adc_aUnitStatus[Unit].SwNormalQueueIndex >= ADC_QUEUE_MAX_DEPTH_MAX)
                {
                    Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_QUEUE_FULL);
                }
            }
            break;
        }
#if (ADC_HW_TRIGGER_API == STD_ON)
        case ADC_ENABLEHARDWARETRIGGER_ID:
        {   
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            eType = Adc_pCfgPtr->pGroups[Group].eType;
            HwInjectedQueueIndex = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
            HwNormalQueueIndex = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
            /* Get HW queue sizes */
            if (((ADC_CONV_TYPE_INJECTED == eType) && ( HwInjectedQueueIndex >= (Adc_QueueIndexType)ADC_HW_QUEUE)) || \
                ((ADC_CONV_TYPE_NORMAL == eType) && ( HwNormalQueueIndex >= (Adc_QueueIndexType)ADC_HW_QUEUE)) \
               )
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_QUEUE_FULL);
            }
            break;
        }
#endif /* ADC_HW_TRIGGER_API == STD_ON */

        default:
        {
            break;
        }
    }
}
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) || \
    (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateConvMode
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    switch (u8ServiceId)
    {
#if (ADC_HW_TRIGGER_API == STD_ON)
        case ADC_ENABLEHARDWARETRIGGER_ID:
        case ADC_DISABLEHARDWARETRIGGER_ID:
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
        case ADC_ENABLECTUTRIGGER_ID:
        case ADC_DISABLECTUTRIGGER_ID:
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (ADC_CONV_MODE_CONTINUOUS == (Adc_pCfgPtr->pGroups[Group].eMode))
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_WRONG_CONV_MODE);
            }
            break;
        }
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        case ADC_ENABLE_CHANNEL_ID:
        case ADC_DISABLE_CHANNEL_ID:
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if(ADC_CONV_TYPE_INJECTED == Adc_pCfgPtr->pGroups[Group].eType)
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_WRONG_CONV_MODE);
            }
            break;
        }
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

        default:
        {
            break;
        }
    }
}
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/** @brief @implements Adc_ValidateEnableDisbleGroupList_Activity */
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_ValidateEnableDisbleGroupList
(
    P2VAR(Adc_ValidationResultType, AUTOMATIC, ADC_APPL_DATA) pReturnValue,
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    switch (u8ServiceId)
    {
        case ADC_ENABLE_CHANNEL_ID:
        case ADC_DISABLE_CHANNEL_ID:
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if((Adc_GroupType)ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX == \
               Adc_pCfgPtr->pGroups[Group].EnableChDisableChGroupIndex
              )
            {
                Adc_ReportValidationError(pReturnValue, u8ServiceId, (uint8)ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/** @brief @implements Adc_ValidateEnableDisbleIdList_Activity */
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateEnableDisbleIdList
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_ChannelType, AUTOMATIC) Channel
)
{
    P2CONST(Adc_GroupDefType, AUTOMATIC, ADC_APPL_CONST) pGroupChIndexPtr;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Index = 0U;
    VAR(boolean, AUTOMATIC) bChannelFound = (boolean)FALSE;
    VAR(Std_ReturnType, AUTOMATIC) ReturnValue = (Std_ReturnType)E_NOT_OK;

    switch (u8ServiceId)
    {
        case ADC_ENABLE_CHANNEL_ID:
        case ADC_DISABLE_CHANNEL_ID:
        {
            /** @violates @ref Adc_c_REF_4 Array indexing */
            pGroupChIndexPtr = Adc_pCfgPtr->pGroups[Group].pAssignment;
            /* Check if ChannelId is valid: assigned to that group */
            /** @violates @ref Adc_c_REF_4 Array indexing */
            for (Index = 0U; Index < Adc_pCfgPtr->pGroups[Group].AssignedChannelCount; Index++)
            {
                /** @violates @ref Adc_c_REF_4 Array indexing */
                if ((Adc_ChannelType)Channel == (Adc_ChannelType)pGroupChIndexPtr[Index])
                {
                    bChannelFound = (boolean)TRUE;
                    break;
                }
            }
            if ((boolean)TRUE == bChannelFound)
            {
                ReturnValue = (Std_ReturnType)E_OK;
            }
            else
            {
                Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID);
            }
            break;
        }

        default:
        {
            break;
        }
    }
    return ReturnValue;
}
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || \
      (ADC_HW_TRIGGER_API == STD_ON) || \
      (ADC_ENABLE_CTUTRIG_NONAUTO_API ==STD_ON) || \
      (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) \
    )
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateExtraParams
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint32, AUTOMATIC) u32ErrorIdList,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_ValidationResultType, AUTOMATIC) ValidationStatus;

    ValidationStatus.bEndValidations = (boolean)FALSE;
    ValidationStatus.ValidParams = (Std_ReturnType)E_OK;

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
    if ((0U != (u32ErrorIdList&ADC_E_BUFFER_UNINIT_LIST)) && ((boolean)FALSE == ValidationStatus.bEndValidations))
    {
        /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
        Adc_ValidateBufferUninit(&ValidationStatus, u8ServiceId, Group);
    }
#endif
    if ((0U != (u32ErrorIdList&ADC_E_WRONG_TRIGG_SRC_LIST)) && ((boolean)FALSE == ValidationStatus.bEndValidations))
    {
       /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
       Adc_ValidateTriggerSrc(&ValidationStatus, u8ServiceId, Group);
    }
#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
    if ((0U != (u32ErrorIdList&ADC_E_QUEUE_FULL_LIST)) && ((boolean)FALSE == ValidationStatus.bEndValidations))
    {
        /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
        Adc_ValidateQueueNotFull(&ValidationStatus, u8ServiceId, Group);
    }
#endif
#if ((ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) || (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON))
    if ((0U != (u32ErrorIdList&ADC_E_WRONG_CONV_MODE_LIST)) && ((boolean)FALSE == ValidationStatus.bEndValidations))
    {
        /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
        Adc_ValidateConvMode(&ValidationStatus, u8ServiceId, Group);
    }
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    if ((0U != (u32ErrorIdList&ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP_LIST)) && ((boolean)FALSE == ValidationStatus.bEndValidations))
    {
        /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
        Adc_ValidateEnableDisbleGroupList(&ValidationStatus, u8ServiceId, Group);
    }
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

    return ValidationStatus.ValidParams;
}
#endif

#if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)
/** @brief @implements Adc_ValidateCallAndTrigger_Activity */
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndTrigger
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(uint8, AUTOMATIC) u8Trigger
)
{
    VAR(Std_ReturnType, AUTOMATIC) ReturnValue = (Std_ReturnType)E_OK;

    if (NULL_PTR == Adc_pCfgPtr)
    {
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_UNINIT);
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    else if ((uint8)CTU2_MAX_TRIGGERS_U8 <= u8Trigger)
    {
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_WRONG_CTUV2_TRIGGER);
        ReturnValue = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* do nothing for MISRA*/
    }
    return ReturnValue;
}
#endif /* CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/** @brief @implements Adc_ValidateCtuTriggerSrc_Activity */
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCtuTriggerSrc
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger
)
{
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Index = 0U;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Std_ReturnType, AUTOMATIC) ReturnValue = (Std_ReturnType)E_NOT_OK;

    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    for(Index = 0U; Index < Adc_pCfgPtr->pGroups[Group].AssignedTriggerCount; Index++)
    {
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        if(Trigger == Adc_pCfgPtr->pGroups[Group].pHwResource[Index])
        {
            /* This trigger is configured for this group */
            ReturnValue = (Std_ReturnType)E_OK;
            break;
        }
    }
    if ((Std_ReturnType)E_NOT_OK == ReturnValue)
    {
        /* Report error to DET */
        Adc_ReportDetError(u8ServiceId, (uint8) ADC_E_PARAM_TRIGGER);
    }
    else
    {
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
        /* Trigger should not be already enabled*/
        if ((ADC_ENABLECTUTRIGGER_ID == u8ServiceId) && (0U != Adc_au8BctuGroupTriggersActive[Unit][Index]))
        {
            /* This trigger has already been for this group */
            ReturnValue = (Std_ReturnType)E_NOT_OK;
            Adc_ReportDetError(u8ServiceId, (uint8) ADC_E_PARAM_TRIGGER);
        }
        /* Trigger should be enabled*/
        else if ((ADC_DISABLECTUTRIGGER_ID == u8ServiceId) && (0U == Adc_au8BctuGroupTriggersActive[Unit][Index]))
        {
            /* This trigger was not enabled for this group */
            ReturnValue = (Std_ReturnType)E_NOT_OK;
            Adc_ReportDetError(u8ServiceId, (uint8) ADC_E_PARAM_TRIGGER);
        }
        else
        {
            /* Do nothing for Misra*/
        }
    }
    return ReturnValue;
}
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */

#ifdef ADC_VALIDATE_APP_BUFFER_ALIGNMENT
/**
* @brief        This function validates the setup buffer to be aligned to 4 bytes.
* @details      This function validates the setup buffer to be aligned to 4 bytes.
*
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The setup buffer is aligned
* @retval     E_NOT_OK:       The setup buffer is not aligned
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateSetupBufferAlignment
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataBufferPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_OK;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = NULL_PTR;
    /** @violates @ref Adc_c_REF_13 cast from unsigned long to pointer */
    /** @violates @ref Adc_c_REF_14 A cast should not be performed between a pointer type and an integral type. */
    VAR(uint32, AUTOMATIC) u32DataBufferAddr = (uint32)pDataBufferPtr;
    
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    /* If the internal buffer is not used(streaming, without interrupt and limit checking are not used), 
       the application buffer should be aligned to 4 bytes */
    if((ADC_ACCESS_MODE_STREAMING != pGroupPtr->eAccessMode) &&
       ((uint8)STD_ON != pGroupPtr->u8AdcWithoutInterrupt)
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        &&((boolean)TRUE != pGroupPtr->bAdcGroupLimitcheck)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        &&((u32DataBufferAddr & 0x00000003UL) != 0UL)
      )
    {
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    return Valid;
}
#endif /* ADC_VALIDATE_APP_BUFFER_ALIGNMENT */

#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_SET_MODE_API == STD_ON)
/**
* @brief      This function validates the Adc_SetMode call.
* @details    This function validates the Adc_SetMode call.
*
* @param[in]  u8ServiceId   The service id of the caller function
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The Adc_SetMode call is valid
* @retval     E_NOT_OK:       The Adc_SetMode call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateSetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) eSetMode
)
{
    VAR(Std_ReturnType, AUTOMATIC) SleepModeStatus = (Std_ReturnType)E_OK;

    if(NULL_PTR == Adc_pCfgPtr)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        /* Report error to DET */
        Adc_ReportDetError((uint8)ADC_SETMODE_ID, (uint8)ADC_E_UNINIT);
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        SleepModeStatus = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if ((ADC_NORMAL_MODE != eSetMode) && (ADC_POWER_DOWN_MODE != eSetMode))
        {
            SleepModeStatus = (Std_ReturnType)E_NOT_OK;
            #if (ADC_DEV_ERROR_DETECT == STD_ON)
            Adc_ReportDetError((uint8)ADC_SETMODE_ID, (uint8)ADC_E_SET_MODE);
            #endif
        }
    }
    return SleepModeStatus;
}
#endif /* ADC_SET_MODE_API == STD_ON */


#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
/**
* @brief        This function ends the validation of the global call parameters.
* @details      This service is a non reentrant function used for end the validation the calls
*               for functions like Adc_Init, Adc_DeInit.
*
* @param[in]    ValidCall validity of the call
* @param[in]    u8ServiceId The service id of the caller function
*
* @return void
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_EndValidateGloballCall
(
    VAR(Std_ReturnType, AUTOMATIC) ValidCall,
    VAR(uint8, AUTOMATIC) u8ServiceId
)
{
    if ((Std_ReturnType)E_OK == ValidCall)
    {
        if (ADC_DEINIT_ID == u8ServiceId)
        {
            Adc_eGlobalState = ADC_STATE_UNINIT;
        }
        else
        {
            Adc_eGlobalState = ADC_STATE_IDLE;
        }
    }
}
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((ADC_VALIDATE_STATE == STD_ON) && (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)))
/**
* @brief        This function validates the state of a group when priorities are used.
* @details      This service is a non reentrant function used for validating the state of a group
*                when priorities are used
*
* @param[in]    Group         The group id
* @param[in]    bImplicitly    Indicates if the group can be implicitly stopped
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyWithPrio
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bImplicitly
)
{
    VAR(boolean, AUTOMATIC) bFlag = (boolean)FALSE;
    VAR(Adc_QueueIndexType, AUTOMATIC) Index = 0U;
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex;
    VAR(Adc_StatusType, AUTOMATIC) eConversion;

    if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0)
    {
        for (Index = 0U; Index < Adc_aUnitStatus[Unit].SwNormalQueueIndex; Index++)
        {
            if (Group == Adc_aUnitStatus[Unit].SwNormalQueue[Index])
            {
                bFlag = (boolean)TRUE;
                break;
            }
        }
    }
    SwNormalQueueIndex = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    eConversion = Adc_aGroupStatus[Group].eConversion;
    if ((((Group == Adc_aUnitStatus[Unit].SwNormalQueue[0]) && (SwNormalQueueIndex > (Adc_QueueIndexType)0)) || ((boolean)TRUE == bFlag)) && \
        ((boolean)FALSE == bImplicitly) \
       )
    {
        Adc_ReportDetError((uint8)ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
    else if (((eConversion != ADC_IDLE) && (eConversion != ADC_STREAM_COMPLETED)) && \
             ((boolean)TRUE == bImplicitly) \
            )
    {
        Adc_ReportDetError((uint8)ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
    else
    {
        ValidState = (Std_ReturnType)E_OK;
    }
    return ValidState;
}
#endif /* (ADC_VALIDATE_STATE == STD_ON) && (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) && ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)) */

#if (((ADC_VALIDATE_STATE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) && (ADC_ENABLE_QUEUING == STD_OFF)) \
      || (((ADC_VALIDATE_STATE == STD_ON) && ((ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__)))         \
      || (ADC_CALIBRATION == STD_ON) || (ADC_DUAL_CLOCK_MODE == STD_ON)  || (ADC_SET_MODE_API == STD_ON)   \
         ) \
    )
/**
* @brief        This function validates the state of a group when the queue is not used.
* @details      This service is a non reentrant function used for validating the state of a group
*                when the queue is not used
*
* @param[in]    Unit          The hardware unit
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call means that unit is not busy
* @retval     E_NOT_OK:       The call means that unit is busy
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyNoQueue
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint8, AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) ErrorFound = (Std_ReturnType)E_OK;
#if (ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInHwInjectedQueue;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInHwNormalQueue;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwNormalQueue;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwInjectedQueue;

    /* Enter critical section to protect against queue modifications */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20();
    /* Get HW and SW queue sizes */
    NoGroupsInSwNormalQueue = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    NoGroupsInSwInjectedQueue = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
#if (ADC_HW_TRIGGER_API == STD_ON)
    NoGroupsInHwInjectedQueue = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
    NoGroupsInHwNormalQueue = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20();
    /* Check for ongoing conversions */
    if ((NoGroupsInSwNormalQueue > (Adc_QueueIndexType)0)
        || (NoGroupsInSwInjectedQueue > (Adc_QueueIndexType)0)
#if (ADC_HW_TRIGGER_API == STD_ON)
        || (NoGroupsInHwInjectedQueue > (Adc_QueueIndexType)0)
        || (NoGroupsInHwNormalQueue > (Adc_QueueIndexType)0)
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
       )   
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_BUSY);

#else
        /* Avoid compiler warning */
        (void)u8ServiceId;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        ErrorFound = (Std_ReturnType)E_NOT_OK;
    }
    return ErrorFound;
}
#endif

#if ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_VALIDATE_STATE == STD_ON))
/**
* @brief        This function validates the state of a group when the hardware trigger is enabled.
* @details      This service is a non reentrant function used for validating the state of a group
*                when the hardware trigger is enabled.
*
 @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyEnableHwTrig
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_OFF)
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwNormalQueue = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwInjectedQueue = 0U;
    VAR(Adc_GroupConvType, AUTOMATIC) eGroupType = ADC_CONV_TYPE_NORMAL;
    VAR(Adc_HwTriggeringType, AUTOMATIC) eHwTriggering;
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_OFF */
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInHwNormalQueue = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInHwInjectedQueue = 0U;
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic shall be the only allowed form of pointer arithmetic */    
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;

    /* Get HW and SW queue sizes */
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_OFF)
    NoGroupsInSwNormalQueue = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    NoGroupsInSwInjectedQueue = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
    /** @violates @ref Adc_c_REF_4 Array indexing */
    eGroupType = Adc_pCfgPtr->pGroups[Group].eType;
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */
    NoGroupsInHwInjectedQueue = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
    NoGroupsInHwNormalQueue = Adc_aUnitStatus[Unit].HwNormalQueueIndex;

#if (ADC_ENABLE_QUEUING == STD_OFF)
    if ((Std_ReturnType)E_OK == Adc_ValidateNotBusyNoQueue(Unit, ADC_ENABLEHARDWARETRIGGER_ID))
#endif /* ADC_ENABLE_QUEUING == STD_OFF  */
    {
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
        /* The queue is not empty, check the type of the group that will be (or not) en-queued */
        /* Different group type or more than one regular group not allowed */
        /** @violates @ref Adc_c_REF_4 Array indexing */
        if (((0U != NoGroupsInHwInjectedQueue) || (0U != NoGroupsInHwNormalQueue)) && \
            ((Adc_aUnitStatus[Unit].eHwQueueGroupType != Adc_pCfgPtr->pGroups[Group].IsMHTGroup) || \
             ((Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE == Adc_aUnitStatus[Unit].eHwQueueGroupType)
            )
           )
        {
            Adc_ReportDetError((uint8)ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_BUSY);
        }

        else if ((ADC_HWTRIGGER_ENABLED == Adc_aGroupStatus[Group].eHwTriggering) ||
                 ((uint8)ADC_HW_QUEUE <= NoGroupsInHwInjectedQueue) ||
                 ((uint8)ADC_HW_QUEUE <= NoGroupsInHwNormalQueue)
                )
#else
        eHwTriggering = Adc_aGroupStatus[Group].eHwTriggering;
        /** @violates @ref Adc_c_REF_4 Array indexing */
        if (((ADC_HWTRIGGER_ENABLED == eHwTriggering) && ((0U != NoGroupsInHwInjectedQueue) || (0U != NoGroupsInHwNormalQueue))) || \
            ((ADC_CONV_TYPE_INJECTED == eGroupType) && ((0U != NoGroupsInSwInjectedQueue) || (0U != NoGroupsInHwNormalQueue))) || \
            ((ADC_CONV_TYPE_NORMAL == eGroupType) && ((0U != NoGroupsInHwInjectedQueue) || (0U != NoGroupsInSwNormalQueue) )) \
           )

#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */
        {
            Adc_ReportDetError((uint8)ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_BUSY);
        }
        else
        {
            ValidState = (Std_ReturnType)E_OK;
        }
    }
    return ValidState;
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON).. */

#if ((ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) && (ADC_VALIDATE_STATE == STD_ON))
/**
* @brief        This function validates the state of a group when the ctu trigger is enabled.
* @details      This service is a non reentrant function used for validating the state of a group
*                when the ctu trigger is enabled.
*
 @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateNotBusyEnableCtuTrig
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_GroupType, AUTOMATIC) GroupInQueue;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
#if (ADC_ENABLE_QUEUING == STD_OFF)
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwNormalQueue = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwInjectedQueue = 0U;
#endif /* ADC_ENABLE_QUEUING == STD_OFF */

#if (ADC_ENABLE_QUEUING == STD_OFF)
    /* Enter critical section to protect against queue modifications */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20();
    /* Get HW and SW queue sizes */
    NoGroupsInSwNormalQueue = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    NoGroupsInSwInjectedQueue = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20();
    /* Check for ongoing conversions */
    if ((0U != NoGroupsInSwNormalQueue) || (0U != NoGroupsInSwInjectedQueue))
    {
       Adc_ReportDetError((uint8)ADC_ENABLECTUTRIGGER_ID, (uint8)ADC_E_BUSY);
    }
    else
#endif /* ADC_ENABLE_QUEUING == STD_OFF */
    {
        if (0U != Adc_aUnitStatus[Unit].HwInjectedQueueIndex)
        {
            GroupInQueue = Adc_aUnitStatus[Unit].HwInjectedQueue[0];
            if ((Group != GroupInQueue) || (ADC_HWTRIGGER_ENABLED == Adc_aGroupStatus[GroupInQueue].eHwTriggering))
            {
                Adc_ReportDetError((uint8)ADC_ENABLECTUTRIGGER_ID, (uint8)ADC_E_BUSY);
            }
            else
            {
                ValidState = (Std_ReturnType)E_OK;
            }
        }
        else
        {
            ValidState = (Std_ReturnType)E_OK;
        }
    }
    return ValidState;
}
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) && (ADC_VALIDATE_STATE == STD_ON) */

#if ((ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE) && (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && (ADC_VALIDATE_STATE == STD_ON))
/**
* @brief        This function validates the state of a group when priorities are not used.
* @details      This service is a non reentrant function used for validating the state of a group
*                when priorities are not used
*
* @param[in]    Unit          The hardware unit
* @param[in]    Group         The group id
* @param[in]    bImplicitly   Indicates if the group can be implicitly stopped
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE)Adc_ValidateNotBusyNoPrio
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bImplicitly
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
#if (ADC_ENABLE_QUEUING == STD_OFF)
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
    VAR(boolean, AUTOMATIC) bQueuesEmpty = (boolean)TRUE;
#else /* ADC_ENABLE_QUEUING == STD_ON */
    VAR(Adc_StatusType, AUTOMATIC) eConversion;
#endif

#if (ADC_ENABLE_QUEUING == STD_OFF)
    if (Adc_aUnitStatus[Unit].SwNormalQueueIndex != (Adc_QueueIndexType)0)
    {
        bQueuesEmpty = (boolean)FALSE;
    }
    if (Adc_aUnitStatus[Unit].SwInjectedQueueIndex != (Adc_QueueIndexType)0)
    {
        bQueuesEmpty = (boolean)FALSE;
    }
    #if (STD_ON==ADC_HW_TRIGGER_API)
    if (Adc_aUnitStatus[Unit].HwInjectedQueueIndex != (Adc_QueueIndexType)0)
    {
        bQueuesEmpty = (boolean)FALSE;
    }
    if (Adc_aUnitStatus[Unit].HwNormalQueueIndex != (Adc_QueueIndexType)0)
    {
        bQueuesEmpty = (boolean)FALSE;
    }
    #endif

    /* Check if any queue is non-empty*/
    if ((boolean)FALSE == bQueuesEmpty)
    {
        Adc_ReportDetError((uint8)ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
    else
    {
        ValidState = (Std_ReturnType)E_OK;
    }
    (void)bImplicitly;
    (void)Group;
#else /* ADC_ENABLE_QUEUING == STD_ON */
    eConversion = Adc_aGroupStatus[Group].eConversion;
    if (((boolean)FALSE == bImplicitly) && (ADC_IDLE != eConversion))
    {
        Adc_ReportDetError((uint8)ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
    else if (((boolean)TRUE == bImplicitly) && (ADC_IDLE != eConversion) && \
             (ADC_STREAM_COMPLETED != eConversion) \
            )
    {
        Adc_ReportDetError((uint8)ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
    else
    {
        ValidState = (Std_ReturnType)E_OK;
    }
#endif /* ADC_ENABLE_QUEUING  */
    return ValidState;
}
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)... */

#if (((ADC_VALIDATE_STATE == STD_ON) && ((ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__))) \
      || (ADC_CALIBRATION == STD_ON) || (ADC_DUAL_CLOCK_MODE == STD_ON) || (ADC_SET_MODE_API == STD_ON) \
    )
/**
* @brief        This function validates the state of all group.
* @details      This service is a non reentrant function used for validating the state of all group
*
* @param[in]    u8ServiceId     The service id of the caller function
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           The call means that at leat one group is not busy
* @retval       E_NOT_OK:       The call means that at leat one group is busy
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCheckGroupNotConversion
(
    VAR(uint8, AUTOMATIC) u8ServiceId
)
{
    VAR(Adc_StatusType, AUTOMATIC) eConversion;
    VAR(Adc_GroupType,AUTOMATIC) GroupId;
    VAR(Std_ReturnType, AUTOMATIC) ErrorFound = (Std_ReturnType)E_OK;
    
    for (GroupId = 0U; GroupId < (Adc_GroupType)Adc_pCfgPtr->GroupCount; GroupId++)
    {
        eConversion = Adc_aGroupStatus[GroupId].eConversion;
        /*  Check if ADC is still converting */
        if((ADC_IDLE != eConversion) && (ADC_STREAM_COMPLETED != eConversion))
        {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_BUSY);
#else
            (void)u8ServiceId;
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            ErrorFound =  (Std_ReturnType)E_NOT_OK;
        }
    }
    return ErrorFound;    
}
#endif /* (((ADC_VALIDATE_STATE == STD_ON) ... */

#if (ADC_VALIDATE_STATE == STD_ON)
#if (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief        This function validates the state of a group when De-init (should not be busy).
* @details      This service is a non reentrant function used for validating the state of a group
*
* @param[in]    void
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateDeInitNotBusy(void)
{
    VAR(Std_ReturnType, AUTOMATIC) ErrorFound = (Std_ReturnType)E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
    
    for(HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
    {
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId; 
        ErrorFound = Adc_ValidateNotBusyNoQueue(Unit, ADC_DEINIT_ID);       
        if ((Std_ReturnType)E_NOT_OK == ErrorFound)
        {
            break;
        }
    } 
    if ((Std_ReturnType)E_OK == ErrorFound)
    {
        if ((Std_ReturnType)E_OK == Adc_ValidateCheckGroupNotConversion(ADC_DEINIT_ID))
        {
            ValidState = (Std_ReturnType)E_OK;
        }
    }
    
    return ValidState;
}
#endif /* (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__) */
/**
* @brief        This function validates the state of a group when Setup result buffer (should not be busy).
* @details      This service is a non reentrant function used for validating the state of a group
*
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateSetupBufferNotBusy
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{    
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
    
    if (ADC_IDLE != Adc_aGroupStatus[Group].eConversion)
    {
        Adc_ReportDetError(ADC_SETUPRESULTBUFFER_ID, (uint8)ADC_E_BUSY);
    }
    else
    {
        ValidState = (Std_ReturnType)E_OK;
    }
    return ValidState;
}

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief        This function validates the state of a group when start group conversion (should not be busy).
* @details      This service is a non reentrant function used for validating the state of a group
*
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateStartGroupConvNotBusy
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{  
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, AUTOMATIC) bImplicitly = (boolean)FALSE;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
#if (STD_ON == ADC_HW_TRIGGER_API)
    VAR(Adc_GroupConvType, AUTOMATIC) eType;
    VAR(Adc_QueueIndexType, AUTOMATIC) SwInjectedQueueIndex;
    VAR(Adc_QueueIndexType, AUTOMATIC) HwInjectedQueueIndex;
    VAR(Adc_QueueIndexType, AUTOMATIC) HwNormalQueueIndex;
#endif /* #if (STD_ON==ADC_HW_TRIGGER_API) */
    
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode) || \
        ((ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode) && \
        (ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode) && \
        (ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode)
        )
       )
    {
        /* The current group can be implicitly stopped */
        bImplicitly = (boolean)TRUE;
    }   
    
    /* Get the unit to which the group belongs to */
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
#if (STD_ON == ADC_HW_TRIGGER_API)
    /** @violates @ref Adc_c_REF_4 Array indexing */
    eType = Adc_pCfgPtr->pGroups[Group].eType;
    SwInjectedQueueIndex = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
    HwInjectedQueueIndex = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
    HwNormalQueueIndex = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
    
    /* SW Injected conversions should be entertained only if there are no other HW or CTU injected chains enabled*/
    /** @violates @ref Adc_c_REF_4 Array indexing */
    if((SwInjectedQueueIndex != (Adc_QueueIndexType)0) || \
      (((Adc_GroupConvType)ADC_CONV_TYPE_INJECTED == eType) && \
        (HwInjectedQueueIndex != (Adc_QueueIndexType)0) \
      ) || \
      (((Adc_GroupConvType)ADC_CONV_TYPE_NORMAL == eType) && \
       (HwNormalQueueIndex != (Adc_QueueIndexType)0) \
      ) \
      )
#else
    /* Check for ongoing injected conversion */
    if (Adc_aUnitStatus[Unit].SwInjectedQueueIndex != (Adc_QueueIndexType)0)
#endif /* #if (STD_ON==ADC_HW_TRIGGER_API) */
    {
        /* Return the Group status as IDLE */
        Adc_ReportDetError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
    else if ((boolean)TRUE == Adc_aUnitStatus[Unit].bCtuControlOngoing)
    {
        Adc_ReportDetError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUSY);
    }
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
    else
    {
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)
        ValidState = Adc_ValidateNotBusyNoPrio(Group, bImplicitly);
#else /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        ValidState = Adc_ValidateNotBusyWithPrio(Group, bImplicitly);
#endif  /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
    }
    return ValidState;
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__) */

#if ((ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__))
/**
* @brief        This function validates the state of a group when enable hw trigger (should not be busy).
* @details      This service is a non reentrant function used for validating the state of a group
*
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateEnableHwTriggNotBusy
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_NOT_OK;
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
    
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
    if ((boolean)TRUE == Adc_aUnitStatus[Unit].bCtuControlOngoing)
    {
        Adc_ReportDetError(ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_BUSY);
    }
    else
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
#if (ADC_HW_TRIGGER_API == STD_ON)
    {
        ValidState = Adc_ValidateNotBusyEnableHwTrig(Group);
    }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    return ValidState;
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__) */
#endif /* ADC_VALIDATE_STATE == STD_ON */


#if (ADC_VALIDATE_STATE == STD_ON)
/**
* @brief        This function validates the state of a group (should not be idle).
* @details      This service is a non reentrant function used for validating the state of a group
*
* @param[in]    u8ServiceId     The service id of the caller function
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           The call is valid
* @retval     E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateNotIdle
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_OK;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    
    switch (u8ServiceId)
    {
#if (ADC_READ_GROUP_API == STD_ON)
        case ADC_VALUEREADGROUP_ID:
        {
            if (ADC_IDLE == Adc_aGroupStatus[Group].eConversion) 
            {
                if(ADC_NOT_YET_CONVERTED == Adc_aGroupStatus[Group].eAlreadyConverted)
                {
                    /* ADC388 */
                    Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_IDLE);
                    ValidState = (Std_ReturnType)E_NOT_OK;
                }
            }
            break;
        }
#endif /* ADC_READ_GROUP_API == STD_ON */
        case ADC_STOPGROUPCONVERSION_ID:
        {
            if (ADC_IDLE == Adc_aGroupStatus[Group].eConversion)
            {
                /* ADC241 */
                Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_IDLE);
                ValidState = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex;
                VAR(Adc_QueueIndexType, AUTOMATIC) SwInjectedQueueIndex;
                
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic shall be the only allowed form of pointer arithmetic */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                SwNormalQueueIndex = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
                SwInjectedQueueIndex = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;

                if ((Group == Adc_aUnitStatus[Unit].SwNormalQueue[0]) && \
                    (SwNormalQueueIndex > 0U) && \
                    (SwInjectedQueueIndex > 0U) \
                   )
                {
                    Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_BUSY);
                    ValidState = (Std_ReturnType)E_NOT_OK; 
                }
            }
            break;
        }
#if (ADC_HW_TRIGGER_API == STD_ON)
        case ADC_DISABLEHARDWARETRIGGER_ID:
        {
            if (ADC_HWTRIGGER_DISABLED == Adc_aGroupStatus[Group].eHwTriggering)
            {
                Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_IDLE);
                ValidState = (Std_ReturnType)E_NOT_OK;
            }
            break;
        }
#endif /* ADC_HW_TRIGGER_API == STD_ON */
        case ADC_GETSTREAMLASTPOINTER_ID:
        {
             if (ADC_IDLE == Adc_aGroupStatus[Group].eConversion)
             {
                Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_IDLE);
                 ValidState = (Std_ReturnType)E_NOT_OK;
             }
            break;
        }
        default:
        {
            break;
        }
    }

    return ValidState;
}
#endif

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
/**
* @brief        This function validates the call for a specific group
* @details      This service is non reentrant function on channel used for validating the calls
*               for functions that use a group
*
* @param[in]    u8ServiceId     The service id of the caller function
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           Valid call and group
* @retval     E_NOT_OK:       Invalid call or group
*
* @api
* @implements     Adc_ValidateCallAndGroup_Activity
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndGroup
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidCallAndGroup = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == Adc_pCfgPtr)
    {
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_UNINIT);
    }
    else if (Group >= Adc_pCfgPtr->GroupCount)
    {
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_PARAM_GROUP);
    }
    else
    {
        ValidCallAndGroup = (Std_ReturnType)E_OK;
    }

    return ValidCallAndGroup;
}
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) || \
    (ADC_CALIBRATION == STD_ON) || \
    (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || \
    defined(__DOXYGEN__)
#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
/**
* @brief        This function validates the call for a specific unit
* @details      This service is non reentrant function on channel used for validating the calls
*               for functions that use a unit
*
* @param[in]    u8ServiceId     The service id of the caller function
* @param[in]    Unit          The unit id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           Valid call and group
* @retval     E_NOT_OK:       Invalid call or group
*
* @api
* @implements     Adc_ValidateCallAndUnit_Activity
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateCallAndUnit
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidCallAndUnit = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, AUTOMATIC) bFoundUnit = (boolean)FALSE;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U;

    if (NULL_PTR == Adc_pCfgPtr)
    {
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_UNINIT);
    }
    else
    {
        for(HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
        {
            /* Get the index of hardware unit in structure which will match with the hardware unit ID*/
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if(Unit == Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId)
            {
                bFoundUnit = (boolean)TRUE;
                break;
            }
        }
        if ((boolean)FALSE == bFoundUnit)
        {
            Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_PARAM_UNIT);
        }
        else
        {
            ValidCallAndUnit = (Std_ReturnType)E_OK;
        }
    }

    return ValidCallAndUnit;
}
#endif /* ADC_VALIDATE_CALL_AND_UNIT */
#endif /* (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) || (ADC_CALIBRATION == STD_ON) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
#if (ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON)
/**
* @brief        This function checks the notification capability of a group.
* @details      This service is non reentrant function on channel used for validating the
*               notification capability of a group.
*
* @param[in]    u8ServiceId     The service id of the caller function
* @param[in]    Group         The group id
*
* @return     Std_ReturnType  Standard return type.
* @retval     E_OK:           Valid notification capability
* @retval     E_NOT_OK:       Invalid notification capability
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_NotifyCapablity
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidCapability = (Std_ReturnType)E_OK;

    switch (u8ServiceId)
    {
        case ADC_ENABLEGROUPNOTIFICATION_ID:
        case ADC_DISABLEGROUPNOTIFICATION_ID:
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (NULL_PTR == Adc_pCfgPtr->pGroups[Group].Notification)
            {
                ValidCapability = (Std_ReturnType)E_NOT_OK;
                Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_NOTIF_CAPABILITY);
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return ValidCapability;
}
#endif /* ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON */
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

/**
* @brief          Initializes the group status structures.
* @details        Initializes the group status structures with the default values.
*
* @param[in]      void
*
* @return         void
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_InitGroupsStatus(void)
{
    VAR(Adc_GroupType,AUTOMATIC) Group = 0U;

    /* Initialize Group Status structures to beginning values */
    for (Group = 0U; Group < Adc_pCfgPtr->GroupCount; Group++)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
        /* this group was not converted yet */
        Adc_aGroupStatus[Group].eAlreadyConverted = ADC_NOT_YET_CONVERTED;

        Adc_aGroupStatus[Group].ResultIndex = 0U;
#ifdef ADC_CURRENT_CHANNEL_USED
        Adc_aGroupStatus[Group].CurrentChannel = 0U;
#endif /* ADC_CURRENT_CHANNEL_USED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
        Adc_aGroupStatus[Group].eHwTriggering = ADC_HWTRIGGER_DISABLED;
    #if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
        Adc_aGroupStatus[Group].eCtuTriggering = ADC_HWTRIGGER_DISABLED;
    #endif  /* ADC_ENABLE_CTUTRIG_API == STD_ON */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_aGroupStatus[Group].eNotification = ADC_NOTIFICATION_DISABLED;
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_aRuntimeGroupChannel[Group].pChannel = Adc_pCfgPtr->pGroups[Group].pAssignment;
    #ifdef ADC_PDB_SUPPORTED
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_aRuntimeGroupChannel[Group].pu16Delays = Adc_pCfgPtr->pGroups[Group].pDelay;
        Adc_aRuntimeGroupChannel[Group].u32Mask = 0xFFFFFFFFUL;
    #endif /* ADC_PDB_SUPPORTED */
    #if (defined(ADC_PTUV3_SUPPORTED) && (ADC_HW_TRIGGER_API == STD_ON))
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_aRuntimeGroupChannel[Group].pu16Delays = Adc_pCfgPtr->pGroups[Group].pDelay;
    #endif /* (defined(ADC_PTUV3_SUPPORTED) && (ADC_HW_TRIGGER_API == STD_ON)) */
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_aRuntimeGroupChannel[Group].ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
        Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean)FALSE;
#endif
    }
}

/**
* @brief          Initializes the Unit status structures.
* @details        Initializes the Unit status structures with the default values.
*
* @param[in]      void
*
* @return         void
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_InitUnitStatus(void)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) QueueIdx = 0U;

    for(Unit = 0U; Unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; Unit++)
    {
        /* Filled slots in the queue */
        Adc_aUnitStatus[Unit].SwNormalQueueIndex = 0U;
        /* Mark all the queue slots as "empty" */
        for(QueueIdx = 0U; QueueIdx < ADC_QUEUE_MAX_DEPTH_MAX; QueueIdx++)
        {
            Adc_aUnitStatus[Unit].SwNormalQueue[QueueIdx] = 0U;
        }

        /* SW Injected queue initialization */
        Adc_aUnitStatus[Unit].SwInjectedQueue[0] =0U;
           /* Filled slots in the sw injected queue */
        Adc_aUnitStatus[Unit].SwInjectedQueueIndex = 0U;

#if (ADC_HW_TRIGGER_API == STD_ON)
        Adc_aUnitStatus[Unit].HwInjectedQueue[0] = 0U;
        /* Filled slots in the Hw queue */
        Adc_aUnitStatus[Unit].HwInjectedQueueIndex = 0U;

        Adc_aUnitStatus[Unit].HwNormalQueue[0] = 0U;
        /* Filled slots in the Hw queue */
        Adc_aUnitStatus[Unit].HwNormalQueueIndex = 0U;
    #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
        /* by default consider all groups regular groups */
        Adc_aUnitStatus[Unit].eHwQueueGroupType = ADC_REGULAR_GROUP_TYPE;
    #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#ifdef ADC_PDB_SUPPORTED
        Adc_aUnitStatus[Unit].u8Sc1Used = 0U;
#endif /* ADC_PDB_SUPPORTED */
    }
#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
    Adc_eCurrentState = ADC_FULL_POWER;
    Adc_eTargetState = ADC_NODEFINE_POWER;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Checks if conversion values are in the configured range.
* @details        Return true if conversion values are in the configured range, otherwise false.
*
* @param[in]      value       Adc conversion value.
*                 Unit        Adc Hardware Unit.
*                 Index       Adc channel index assigned to a group.
*
* @return         boolean     Conversion value in range flag.
* @retval         TRUE        if conversion values are in the configured range.
* @retval         FALSE       if conversion values are not in the configured range.
*
* @pre            Driver must be initialized.
* @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
*/
FUNC(boolean, ADC_CODE) Adc_CheckConversionValuesInRange
(
    VAR(Adc_ValueGroupType, AUTOMATIC) Value,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_ChannelType, AUTOMATIC) Index
)
{
    VAR(boolean, AUTOMATIC) bValInRange = (boolean)FALSE;
    VAR(Adc_ChannelRangeSelectType, AUTOMATIC) eChRange;
    VAR(Adc_ValueGroupType, AUTOMATIC) LowLimit;
    VAR(Adc_ValueGroupType, AUTOMATIC) HighLimit;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;

    VAR(Adc_ChannelType, AUTOMATIC) Shift = 0U;
    VAR(uint16, AUTOMATIC) u16AdcMask = ADC_DATA_MASK_U16;
    
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    eChRange = Adc_aChannelsLimitCheckingCfg[HwIndex][Index].eChannelRange;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    LowLimit = (Adc_ValueGroupType)Adc_aChannelsLimitCheckingCfg[HwIndex][Index].ChannelLowLimit;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    HighLimit = (Adc_ValueGroupType)Adc_aChannelsLimitCheckingCfg[HwIndex][Index].ChannelHighLimit;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    Shift = (16U - (Adc_pCfgPtr->pAdc[HwIndex].Res));

#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    Value = (Value & u16AdcMask) >> Shift;
#else
    Value = Value & (u16AdcMask >> Shift);
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */
    switch (eChRange)
    {
        /* Complete range - independent from channel limit settings. */
        case ADC_RANGE_ALWAYS:
        {
            bValInRange = (boolean)TRUE;
            break;
        }
        /* Range between low limit and high limit - high limit value included. */
        case ADC_RANGE_BETWEEN:
        {
            if ((Value > LowLimit) && (Value <= HighLimit))
            {
                bValInRange = (boolean)TRUE;
            }
            break;
        }
        /* Range above high limit or below low limit - low limit value included. */
        case ADC_RANGE_NOT_BETWEEN:
        {
            if ((Value > HighLimit) || (Value <= LowLimit))
            {
                bValInRange = (boolean)TRUE;
            }
            break;
        }
        /* Range below high limit -high limit value included. */
        case ADC_RANGE_NOT_OVER_HIGH:
        {
            if (Value <= HighLimit)
            {
                bValInRange = (boolean)TRUE;
            }
            break;
        }
        /* Range above low limit. */
        case ADC_RANGE_NOT_UNDER_LOW:
        {
            if (Value > LowLimit)
            {
                bValInRange = (boolean)TRUE;
            }
            break;
        }
        /* Range above high limit. */
        case ADC_RANGE_OVER_HIGH:
        {
            if (Value > HighLimit)
            {
                bValInRange = (boolean)TRUE;
            }
            break;
        }
        /* Range below low limit - low limit value included. */
        case ADC_RANGE_UNDER_LOW:
        {
            if (Value <= LowLimit)
            {
                bValInRange = (boolean)TRUE;
            }
            break;
        }
        /* Unexpected value */
        default:
        {
            break;
        }
    }
    return (boolean)bValInRange;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_ENABLE_QUEUING == STD_ON)
/**
* @brief          This function performs the dequeue operation on the internal ADC queue.
* @details        This function performs the dequeue operation on the internal ADC queue.
*
* @param[in]      Unit            The used hw Unit.
* @param[in]      CurQueueIndex   The current queue index.
*
* @return         void
*
* @pre This function must be called from a critical region. It is not protecting itself against interruptions.
* @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
*/
FUNC(void, ADC_CODE) Adc_RemoveFromQueue
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_QueueIndexType, AUTOMATIC) CurQueueIndex
)
{
    VAR(Adc_QueueIndexType, AUTOMATIC) PositionIndex = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) CurrentIndex = Adc_aUnitStatus[Unit].SwNormalQueueIndex;

    if((Adc_QueueIndexType)1U >= CurrentIndex)
    {
        /* Zero or one element present in the queue */
        Adc_aUnitStatus[Unit].SwNormalQueueIndex = 0U;
    }
    else
    {
        /* More than one element in the queue */
        /* Move all elements after the one to remove (from CurQueueIndex position) one place to the left */
        for(PositionIndex = (CurQueueIndex + 1U); PositionIndex < CurrentIndex; PositionIndex++)
        {
            Adc_aUnitStatus[Unit].SwNormalQueue[PositionIndex - 1U] =
            (Adc_GroupType)Adc_aUnitStatus[Unit].SwNormalQueue[PositionIndex];
        }
        Adc_aUnitStatus[Unit].SwNormalQueueIndex--;
    }
}
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
/**
* @brief          This function inserts a group into the queue.
* @details        This function inserts a group into the queue.
*
* @param[in]      Unit      The hardware Unit.
* @param[in]      Group     The group id.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_InsertIntoQueue
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_QUEUE_MAX_DEPTH_MAX != 1U)
    /* Temporary index in the Queue */
    VAR(Adc_QueueIndexType, AUTOMATIC) QueueTemp = 0U;
#endif
    /* Position of the new Group in the Queue */
    VAR(Adc_QueueIndexType, AUTOMATIC) Pos = 0U;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_GroupPriorityType, AUTOMATIC) gPri = Adc_pCfgPtr->pGroups[(Group)].Priority;
    VAR(Adc_QueueIndexType, AUTOMATIC) qPtr = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    VAR(Std_ReturnType, AUTOMATIC) DemTest = (Std_ReturnType)E_OK;

    /* Find the right place in Queue */
    /**
     * @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic
     */
    while(Adc_pCfgPtr->pGroups[(Adc_aUnitStatus[Unit].SwNormalQueue[Pos])].Priority >= gPri)
    {
        Pos++;
        if (Pos >= qPtr)
        {
            break;
        }
    }
    if(0U == Pos)
    {
        /* Highest priority group detected */
        DemTest = Adc_Ipw_StopCurrentConversion(Unit, Adc_aUnitStatus[Unit].SwNormalQueue[0]);
    }
    #if (ADC_QUEUE_MAX_DEPTH_MAX != 1U)
    /* Make space for the new Group */
    if(qPtr > Pos)
    {
        for(QueueTemp = qPtr; QueueTemp > Pos; QueueTemp--)
        {
            /* Move elements to the right */
            Adc_aUnitStatus[Unit].SwNormalQueue[QueueTemp] = (Adc_GroupType)Adc_aUnitStatus[Unit].SwNormalQueue[QueueTemp- 1U];
        }
    }
    #endif
    /* Place the Group in the Queue */
    Adc_aUnitStatus[Unit].SwNormalQueue[Pos] = Group;
    /* Increase the Queue Index */
    Adc_aUnitStatus[Unit].SwNormalQueueIndex++;
    
    return DemTest;
}
#endif  /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          This function update queue before start a group conversion.
* @details        This function update queue before start a group conversion.
*
* @param[in]      Group     The group id.
* @param[in]      Unit      The hardware Unit.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusStartConversion
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    CONST(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /* First available slot in the Queue */
    VAR(Adc_QueueIndexType, AUTOMATIC) qPtr = 0U;
#else
#if (ADC_ENABLE_QUEUING == STD_ON) && (ADC_QUEUE_MAX_DEPTH_MAX != 1U)
    VAR(Adc_QueueIndexType, AUTOMATIC) qPtr = 0U;
#endif
#endif
#if (ADC_ENABLE_QUEUING == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    VAR(Std_ReturnType, AUTOMATIC) DemTest = (Std_ReturnType)E_OK;

    /* Enter critical region to work on queue, DMA, ADC registers */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_07();
    /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
    Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
    Adc_aGroupStatus[Group].ResultIndex = 0U;

#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)       
    /* Injected conversion mode */
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((Adc_GroupConvType)ADC_CONV_TYPE_INJECTED == Adc_pCfgPtr->pGroups[Group].eType)
    {
#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
        {
            if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
            {
                /* Queue is NOT Empty */
                DemTest = Adc_Ipw_StopCurrentConversion(Unit, Adc_aUnitStatus[Unit].SwNormalQueue[0]);
            }
        }
#endif
        /* Place the Group in the SW Inj Queue */
        Adc_aUnitStatus[Unit].SwInjectedQueue[0] = Group;
        /* Increase the Queue Index */
        Adc_aUnitStatus[Unit].SwInjectedQueueIndex++;

        Adc_Ipw_StartInjectedConversion(Unit);
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
#if ((ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) && defined(ADC_DMA_SUPPORTED))
        /* Dem error was checked and not failed, so it must be reported passed */
        if (((Std_ReturnType)E_OK == DemTest) && ((uint32)STD_ON == Adc_E_TimeoutCfg.state))
        {
            /* Report production error passed.  */
            Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
        }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
        /** @violates @ref Adc_c_REF_8 Return statement before end of function. */
        return;
    }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */ 

    /* Normal conversion*/
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    qPtr = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    if (qPtr > (Adc_QueueIndexType)0U)
    {
        /* Queue is NOT Empty */
        DemTest = Adc_InsertIntoQueue(Unit, Group);
    }
#else /* ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE */
 #if (ADC_ENABLE_QUEUING == STD_ON) && (ADC_QUEUE_MAX_DEPTH_MAX != 1U)
    qPtr = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    if (qPtr > (Adc_QueueIndexType)0U)
    {
        /* Place the Group in the Queue */
        Adc_aUnitStatus[Unit].SwNormalQueue[qPtr] = Group;
        /* Increase the Queue Index */
        Adc_aUnitStatus[Unit].SwNormalQueueIndex++;
    }
 #else /* ADC_ENABLE_QUEUING == STD_OFF*/
  /* In this case all the StartConversion should be rejected by DET */
 #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
#endif /* ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE */

#if (ADC_ENABLE_QUEUING == STD_ON)
    SwNormalQueueIndex = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
    if((Group == Adc_aUnitStatus[Unit].SwNormalQueue[0]) || (0U == SwNormalQueueIndex))
    {
        /* No_priorities OR Queue_is_empty */
        /* Indicate a new group was added to the queue */
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
        if (0U == Adc_aUnitStatus[Unit].SwNormalQueueIndex)
        {
            /* Place the Group in the Queue */
            Adc_aUnitStatus[Unit].SwNormalQueue[0] = Group;
            Adc_aUnitStatus[Unit].SwNormalQueueIndex++;
        }

        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();

        /* ADC will not be running - no ISR can occur now */
        Adc_Ipw_StartNormalConversion(Unit);

#if (ADC_ENABLE_QUEUING == STD_ON)
    }
    else
    {
        /* exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
    }
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
#if ((ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) && (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
    /* Dem error was checked and not failed, so it must be reported passed */
    if (((Std_ReturnType)E_OK == DemTest) && ((uint32)STD_ON == Adc_E_TimeoutCfg.state))
    {
        /* Report production error passed.  */
        Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
    }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    (void)DemTest;   
}

/**
* @brief          This function update queue before start a group conversion.
* @details        This function update queue before start a group conversion.
*
* @param[in]      Group     The group id.
* @param[in]      Unit      The hardware Unit.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusStopConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#if (ADC_ENABLE_QUEUING == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) RemovedPos = 0U;
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    VAR(Std_ReturnType, AUTOMATIC) DemTest = (Std_ReturnType)E_OK;
    VAR(Adc_GroupConvModeType, AUTOMATIC) eMode;
    VAR(Adc_GroupAccessModeType, AUTOMATIC) eAccessMode;
    VAR(Adc_StreamBufferModeType, AUTOMATIC) eBufferMode;
    VAR(Adc_StatusType, AUTOMATIC) eConversion;

    /* Enter critical region to protect against queue changes from ISRs */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic shall be the only allowed form of pointer arithmetic */
    eMode = Adc_pCfgPtr->pGroups[Group].eMode;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic shall be the only allowed form of pointer arithmetic */
    eAccessMode = Adc_pCfgPtr->pGroups[Group].eAccessMode;
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic shall be the only allowed form of pointer arithmetic */
    eBufferMode = Adc_pCfgPtr->pGroups[Group].eBufferMode;
    eConversion = Adc_aGroupStatus[Group].eConversion;

     /* FD reset number of samples completed */
     Adc_aGroupStatus[Group].ResultIndex = 0U;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
     /* disable group notification (ADC155) */
     Adc_aGroupStatus[Group].eNotification = ADC_NOTIFICATION_DISABLED;
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
#if (ADC_SETCHANNEL_API == STD_ON) && defined(ADC_PDB_SUPPORTED)
     Adc_aRuntimeGroupChannel[Group].u32Mask = 0xFFFFFFFFUL;
#endif
    /**
     * @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic
     */
    if(((ADC_CONV_MODE_ONESHOT == eMode) || \
        ((ADC_ACCESS_MODE_STREAMING == eAccessMode) && (ADC_STREAM_BUFFER_LINEAR == eBufferMode)) \
       ) && (ADC_STREAM_COMPLETED == eConversion) \
      )
    {
        /* group is stopped, change its status to IDLE  */
        Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
    }
    else
    {
    #if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)     
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        if ((Adc_GroupConvType)ADC_CONV_TYPE_INJECTED == Adc_pCfgPtr->pGroups[Group].eType)
        {
            if (Group == Adc_aUnitStatus[Unit].SwInjectedQueue[0])
            {
                DemTest = Adc_Ipw_StopCurrentConversion(Unit, Group);
                /* zero elements in the sw injected queue */
                Adc_aUnitStatus[Unit].SwInjectedQueueIndex = 0U;
            }
        }
        else
    #endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */    
        {
    #if (ADC_ENABLE_QUEUING == STD_ON)
            /* Find the Group in the Queue */
            RemovedPos = Adc_aUnitStatus[Unit].SwNormalQueueIndex;  /* initialize with something invalid */
    
            for (SwNormalQueueIndex = 0U; SwNormalQueueIndex < Adc_aUnitStatus[Unit].SwNormalQueueIndex; SwNormalQueueIndex++)
            {
                if (Group == Adc_aUnitStatus[Unit].SwNormalQueue[SwNormalQueueIndex] )
                {
                    /* The group is found in the Queue */
                    /* Store the position of the group to be removed */
                    RemovedPos = SwNormalQueueIndex;
    
                    /* Stop the conversion of all channels belonging to this group */
                    if((Adc_QueueIndexType)0U == SwNormalQueueIndex) /* In this case the group might be under conversion */
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
                    {
                        DemTest = Adc_Ipw_StopCurrentConversion(Unit, Group);
                    }
    #if (ADC_ENABLE_QUEUING == STD_ON)
                    /* Remove group from Queue */
                    Adc_RemoveFromQueue(Unit, SwNormalQueueIndex);
                }
            }
    #else
            /* No element will be present in the queue */
            Adc_aUnitStatus[Unit].SwNormalQueueIndex = 0U;
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
        }
    
        /* group is stopped, change its status to IDLE  */
        Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
        
    #if (ADC_ENABLE_QUEUING == STD_ON)
        /* Start the next group in the Queue (if any) */
        if((Adc_QueueIndexType)0U == RemovedPos) 
        {
            if(Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
            {
                /* Structures and pointers will be initialized when the next Group starts */
                Adc_Ipw_StartNormalConversion(Unit);
            }
        }
    #endif /* (ADC_ENABLE_QUEUING == STD_ON) */
    
    #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* Dem error was checked and not failed, so it must be reported passed */
            if (((Std_ReturnType)E_OK == DemTest) && ((uint32)STD_ON == Adc_E_TimeoutCfg.state))
            {
                /* Report production error passed.  */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
            }
    #else
        (void)DemTest;    
    #endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    }
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function updates the status variables after the read group operation.
* @details        This function updates the status variables after the read group operation.
*
* @param[in]      Group       The group of which conversion will be started.
* @param[in]      bFlag        Indicates if the values are in the configured limit range.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusReadGroupNoInt
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    CONST(boolean, AUTOMATIC) bFlag
)
{
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
#if (ADC_ENABLE_QUEUING == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex = 0U;
#endif 
  
    /* at least once the group was converted */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
    /* Update conversion status*/
    /* Conversion values are not in the configured range */
    if ((boolean)TRUE == bFlag)
    {
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
    #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        /* NOTE: Streaming groups are NOT allowed without interrupts in configuration */
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        if(ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
        }
        /* Case of software - one shot mode */
        else
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if(ADC_TRIGG_SRC_SW == Adc_pCfgPtr->pGroups[Group].eTriggerSource)
            {
                Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
        #if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)             
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                if ((Adc_GroupConvType)ADC_CONV_TYPE_INJECTED == Adc_pCfgPtr->pGroups[Group].eType)
                {
                    if (Adc_aUnitStatus[Unit].SwInjectedQueueIndex > (Adc_QueueIndexType)0)
                    {
                        /* empty queue of  SW injected conversions */
                        Adc_aUnitStatus[Unit].SwInjectedQueueIndex--;
                    }
                }
                else /* SW NORMAL CONVERSION */
        #endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */            
                {
                    if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0)
                    {
        #if (ADC_ENABLE_QUEUING == STD_ON)               
                        /* remove group without interrupts from queue  */
                        for (SwNormalQueueIndex = 0U; SwNormalQueueIndex < Adc_aUnitStatus[Unit].SwNormalQueueIndex; SwNormalQueueIndex++)
                        {
                            if (Group == Adc_aUnitStatus[Unit].SwNormalQueue[SwNormalQueueIndex])
                            {
                                /* The group is found in the Queue */
                                Adc_RemoveFromQueue(Unit, SwNormalQueueIndex);
                                break;
                            }
                        }
        #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
                        /* Start / restore next conversion in the queue*/
                        if (0U == SwNormalQueueIndex)
                        {
                            if(Adc_aUnitStatus[Unit].SwNormalQueueIndex > 0U)
                            {
                                Adc_Ipw_StartNormalConversion(Unit);
                            }
                        }
        #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
        #else
                        Adc_aUnitStatus[Unit].SwNormalQueueIndex--;
        #endif
                    }
                } 
            }
        }
    }
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        if(ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode)
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if(ADC_TRIGG_SRC_SW == Adc_pCfgPtr->pGroups[Group].eTriggerSource)
            {
                /* ADC449 */
                Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
            }
            else
            {
                /* ADC450 */
                Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
            }
        }
        Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)TRUE;  
    }
    #endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusReadGroupInt
(
    CONST(Adc_GroupType, AUTOMATIC) Group
)
{
    /* The following code has been added to respect the State Diagram of Streaming Access Mode */
    if (ADC_COMPLETED == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].ResultIndex = 0U;
        /* ADC331 -- ADC222*/
        Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
    }
    else if (ADC_STREAM_COMPLETED == Adc_aGroupStatus[Group].eConversion)
    {
        /* Compliance with State Diagram */
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_TRIGG_SRC_SW == Adc_pCfgPtr->pGroups[Group].eTriggerSource)
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if((ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode)|| \
               ((ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode) && \
                (ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode) && \
                (ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode)
               )
              )
            {
                /* ADC330 - ADC221 */
                Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
            }
            else
            { /* Continuous*/
                /* ADC329 -- ADC222 */
                Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
            }
        }
#if (ADC_HW_TRIGGER_API == STD_ON)
        else
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if((ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode)&& \
               (ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode)
              )
            {
                /* ADC330 - ADC221*/
                Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
            }
            else
            { /* Simple One-shot mode, in other words in single access mode*/
                /* ADC329 -- ADC222*/
                Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
            }
        }
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    }
    else
    {
        /* Nothing for misra */
    }
}

#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusEnableHardware
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /* Enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10();

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    /* if the queue is empty than simply copy into the groups in queue type the first group type */
    if ((Adc_QueueIndexType)0 == Adc_aUnitStatus[Unit].HwInjectedQueueIndex)
    {
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_aUnitStatus[Unit].eHwQueueGroupType = Adc_pCfgPtr->pGroups[Group].IsMHTGroup;
    }
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    if((Adc_GroupConvType)ADC_CONV_TYPE_NORMAL == Adc_pCfgPtr->pGroups[Group].eType)
    {
        Adc_aUnitStatus[Unit].HwNormalQueue[Adc_aUnitStatus[Unit].HwNormalQueueIndex] = Group;
        Adc_aUnitStatus[Unit].HwNormalQueueIndex++;
    }
    else
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
    {
        Adc_aUnitStatus[Unit].HwInjectedQueue[Adc_aUnitStatus[Unit].HwInjectedQueueIndex] = Group;
        Adc_aUnitStatus[Unit].HwInjectedQueueIndex++;
    }

    /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
    /* ADC222 */
    Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
    /* if HW trigger is enabled for a group, its HW trigger status becomes ENABLED */
    Adc_aGroupStatus[Group].eHwTriggering = ADC_HWTRIGGER_ENABLED;
    /* ADC432 */
    /* Put the conversion results from Results Buffer Base Address */
    Adc_aGroupStatus[Group].ResultIndex = 0U;
    /* Exit critical section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusDisableHardware
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /* Enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11();

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* [ADC157] if HW trigger is disabled for a group, its HW trigger status becomes DISABLED */
    Adc_aGroupStatus[Group].eNotification = ADC_NOTIFICATION_DISABLED;
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

    /* ADC361*/
    /* Mark the Group status as IDLE */
    Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
    /* Hardware trigger is disabled */
    Adc_aGroupStatus[Group].eHwTriggering = ADC_HWTRIGGER_DISABLED;
#if (ADC_SETCHANNEL_API == STD_ON) && defined(ADC_PDB_SUPPORTED)
    Adc_aRuntimeGroupChannel[Group].u32Mask = 0xFFFFFFFFUL;
#endif
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    if((Adc_GroupConvType)ADC_CONV_TYPE_INJECTED == Adc_pCfgPtr->pGroups[Group].eType)
    {
        if(Adc_aUnitStatus[Unit].HwInjectedQueueIndex > 0U)
        {
            /* ADC429 */
            Adc_aUnitStatus[Unit].HwInjectedQueueIndex--;
        }
    }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    else
    {
        if(Adc_aUnitStatus[Unit].HwNormalQueueIndex > 0U)
        {
            /* ADC429 */
            Adc_aUnitStatus[Unit].HwNormalQueueIndex--;
        }
    }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

    /* Exit critical section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

/**
* @brief          This function updates the status variables after the getstreamlastpointer operation.
* @details        This function updates the status variables after the getstreamlastpointer operation.
*
* @param[in]      Group       The group of which conversion will be started.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_UpdateStatusAfterGetStream
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* The following code has been added to respect the State Diagram of Streaming Access Mode */
    if (ADC_COMPLETED == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].ResultIndex = 0U;
        /* ADC328 -- ADC222*/
        Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
    }
    
    if (ADC_STREAM_COMPLETED == Adc_aGroupStatus[Group].eConversion)
    {
        /* Compliance with State Diagram */
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_TRIGG_SRC_SW == Adc_pCfgPtr->pGroups[Group].eTriggerSource)
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if((ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode) || \
               ((ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode) && \
                (ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode) && \
                (ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode)
               )
              )
            {
                /* ADC327 -- ADC221*/
                Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
            }
            else
            { /* Continuous*/
                /* ADC326 -- ADC222*/
                Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
            }
        }
#if (STD_ON == ADC_HW_TRIGGER_API)
        else
        {
            /* Hw Trigger*/
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if((ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode) && \
               (ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode)
              )
            {
                Adc_aGroupStatus[Group].eConversion = ADC_IDLE;
            }
            else
            { /* Simple One-shot mode, in other words in single access mode*/
                Adc_aGroupStatus[Group].eConversion = ADC_BUSY;
            }
        }
#endif /* (STD_ON == ADC_HW_TRIGGER_API ) */ 
    }
}

#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_ON))
/**
* @brief        This function validates the Adc unit is activated for Ctu control mode.
* @details      This service is a non reentrant function used for validating the Adc unit when
*               Ctu control mode is used.
*
* @param[in]    Unit            The unit id
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           The call is valid
* @retval       E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateUnitActive
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Std_ReturnType, AUTOMATIC) Return = (Std_ReturnType)E_OK;

    if ((uint8)STD_OFF == Adc_pCfgPtr->pCtuCfgPtr->au8AdcUnitActive[Unit])
    {
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_PARAM_UNIT);
        Return = (Std_ReturnType)E_NOT_OK;
    }

    return Return;
}

/**
* @brief        This function validates the state of s unit when the Ctu Control is enabled.
* @details      This service is a non reentrant function used for validating the state of a unit
*               when the ctu control is enabled.
*
* @param[in]    Unit            The unit id
*
* @return       Std_ReturnType  Standard return type.
* @retval       E_OK:           The call is valid
* @retval       E_NOT_OK:       The call is not valid
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateCtuControlMode
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Std_ReturnType, AUTOMATIC) ValidState = (Std_ReturnType)E_OK;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwNormalQueue = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInSwInjectedQueue = 0U;
#if (ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInHwNormalQueue = 0U;
    VAR(Adc_QueueIndexType, AUTOMATIC) NoGroupsInHwInjectedQueue = 0U;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

    switch(u8ServiceId)
    {
        case ADC_ENABLECTUCONTROLMODE_ID:
        {
            /* Enter critical section to protect against queue modifications */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_29();
            /* Get HW and SW queue sizes */
            NoGroupsInSwNormalQueue = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
            NoGroupsInSwInjectedQueue = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
#if (ADC_HW_TRIGGER_API == STD_ON)
            NoGroupsInHwNormalQueue = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
            NoGroupsInHwInjectedQueue = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_29();

            /* Check for ongoing conversions */
            if ((NoGroupsInSwNormalQueue != (Adc_QueueIndexType)0) ||
                (NoGroupsInSwInjectedQueue != (Adc_QueueIndexType)0) ||
#if (ADC_HW_TRIGGER_API == STD_ON)
                (NoGroupsInHwInjectedQueue != (Adc_QueueIndexType)0) ||
                (NoGroupsInHwNormalQueue != (Adc_QueueIndexType)0) ||
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
                ((boolean)TRUE == Adc_aUnitStatus[Unit].bCtuControlOngoing)
               )
            {
                ValidState = (Std_ReturnType)E_NOT_OK;
                Adc_ReportDetError((uint8)ADC_ENABLECTUCONTROLMODE_ID, (uint8)ADC_E_BUSY);
            }
            break;
        }
        case ADC_DISABLECTUCONTROLMODE_ID:
        {
            /* Ctu control mode is not already enabled for this unit */
            if((boolean)FALSE == Adc_aUnitStatus[Unit].bCtuControlOngoing)
            {
                ValidState = (Std_ReturnType)E_NOT_OK;
                Adc_ReportDetError((uint8)ADC_DISABLECTUCONTROLMODE_ID, (uint8)ADC_E_IDLE);
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return ValidState;
}
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) && (ADC_DEV_ERROR_DETECT == STD_ON) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateStateAndPtr
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
    
    if (NULL_PTR == pResult)
    {
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Adc_ReportDetError(u8ServiceId, (uint8)ADC_E_PARAM_POINTER);
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(NULL_PTR == Adc_pCfgPtr)
    {
        /* Adc module is not initialized */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
        Adc_ReportDetError(u8ServiceId, ADC_E_UNINIT);
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
        
        *pResult = ADC_NOT_INIT;
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Nothing for misra */
    }
    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidateIdleState
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIdx;
    VAR(Adc_QueueIndexType, AUTOMATIC) SwInjQueueIdx;
#if (ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) HwNormalQueueIdx;
    VAR(Adc_QueueIndexType, AUTOMATIC) HwInjQueueIdx;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U;
    
    for(HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
    {
        /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId;
        SwNormalQueueIdx = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
        SwInjQueueIdx = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
#if (ADC_HW_TRIGGER_API == STD_ON)
        HwNormalQueueIdx = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
        HwInjQueueIdx = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

        if((SwNormalQueueIdx > 0U) || (SwInjQueueIdx > 0U)
#if (ADC_HW_TRIGGER_API == STD_ON)
           || (HwNormalQueueIdx > 0U) || (HwInjQueueIdx > 0U)
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
           ||((boolean)TRUE == Adc_aUnitStatus[Unit].bCtuControlOngoing)
#endif /* if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */
          )
        {
            /* Adc conversion is ongoing */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            Adc_ReportDetError(u8ServiceId, ADC_E_NOT_DISENGAGED);
#endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
            *pResult = ADC_SEQUENCE_ERROR;
            RetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }/* end for(HwIndex = 0U; HwIndex <... */    
    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePowerStateSupport
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    VAR(Adc_PowerStateType, AUTOMATIC) ePowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
    
    /* If the power state is not supported or low power state is not supported at all */
    if(ePowerState >= ADC_NODEFINE_POWER)
    {
        /* The state is not supported */
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        Adc_ReportDetError(u8ServiceId, ADC_E_POWER_STATE_NOT_SUPPORTED);
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

        *pResult = ADC_POWER_STATE_NOT_SUPP;
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_ValidatePowerStatePrepare
(
    VAR(uint8, AUTOMATIC) u8ServiceId,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pResult
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
    
    /* If the terget state is invalid state */
    if(Adc_eTargetState >= ADC_NODEFINE_POWER)
    {
        /* The target power state is not prepared */
        #if (ADC_DEV_ERROR_DETECT == STD_ON)
        Adc_ReportDetError(u8ServiceId, ADC_E_PERIPHERAL_NOT_PREPARED);
        #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */

        *pResult = ADC_SEQUENCE_ERROR;
        RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return RetVal;
}
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief          Initializes the ADC hardware unit and the driver.
* @details        This function will initialize both the ADC HW unit and the driver structures.
*
* @param[in]      pConfigPtr   Pointer to configuration set in Variant PB
*                             (Variant PC requires a NULL_PTR).
* @return         void
*
* @api
*
* @post           Initializes the driver.
*
*
* @note           The function Autosar Service ID[hex]: 0x00.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements  Adc_Init_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr
)
{
#if ((ADC_VALIDATE_GLOBAL_CALL == STD_ON) || (ADC_VALIDATE_PARAMS == STD_ON))
    VAR(Std_ReturnType, AUTOMATIC) ValidStatus = (Std_ReturnType)E_NOT_OK;
#endif

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    ValidStatus = Adc_ValidateGloballCall(ADC_INIT_ID);
    if ((Std_ReturnType)E_OK == ValidStatus)
    {
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        ValidStatus = Adc_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == ValidStatus)
        {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#ifdef ADC_PRECOMPILE_SUPPORT
            /* ADC342 */
            Adc_pCfgPtr = &Adc_PBCfgVariantPredefined;
            (void)ConfigPtr;
#else
            /* ADC054 */
            Adc_pCfgPtr = ConfigPtr;
#endif /* ADC_PRECOMPILE_SUPPORT */

            /* Initialize the unit status for all units */
            Adc_InitUnitStatus();
            /* Initialize the group status for all groups */
            Adc_InitGroupsStatus();
            /* Call the low level function to initialize driver */
            Adc_Ipw_Init(Adc_pCfgPtr);

#if (ADC_VALIDATE_PARAMS == STD_ON)
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Adc_EndValidateGloballCall(ValidStatus, ADC_INIT_ID);
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */
}

/**
* @brief          Initializes the group specific ADC result buffer pointer as
*                 configured to point to the pDataBufferPtr address which is
*                 passed as parameter.
* @details        Initializes ADC driver with the group specific result buffer
*                 start address where the conversion results will be stored.
*                 The application has to ensure that the application buffer,
*                 where pDataBufferPtr points to, can hold all the conversion
*                 results of the specified group. The initialization with
*                 Adc_SetupResultBuffer is required after reset, before a group
*                 conversion can be started.
*
* @param[in]      Group           Numeric ID of requested ADC channel group.
* @param[in]      pDataBufferPtr   Pointer to result data buffer
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Result buffer pointer initialized correctly.
* @retval         E_NOT_OK:       Operation failed or development error
*                                 occurred.
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x0C.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements  Adc_SetupResultBuffer_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_NOT_OK;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = NULL_PTR;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_SETUPRESULTBUFFER_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidatePtr(ADC_SETUPRESULTBUFFER_ID, DataBufferPtr))
        {
        #ifdef ADC_VALIDATE_APP_BUFFER_ALIGNMENT
             if((Std_ReturnType)E_OK == Adc_ValidateSetupBufferAlignment(Group, DataBufferPtr))
             {
        #endif
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
                if ((Std_ReturnType)E_OK == Adc_ValidateSetupBufferNotBusy(Group))
                {
#endif /* ADC_VALIDATE_STATE == STD_ON */

                    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    pGroupPtr = &Adc_pCfgPtr->pGroups[Group];
                    /* ADC420 */
                    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    (pGroupPtr->pResultsBufferPtr[Group]) = DataBufferPtr;
                    TempReturn = (Std_ReturnType)E_OK;
#if (ADC_VALIDATE_STATE == STD_ON)
                }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        #ifdef ADC_VALIDATE_APP_BUFFER_ALIGNMENT
             }
        #endif
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

    return TempReturn;
}

#if (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Returns all ADC HW Units to a state comparable to their
*                 power on reset state.
* @details        Returns all ADC HW Units to a state comparable to their
*                 power on reset state, and de-initialize the ADC MCAL driver.
*
* @return         void
*
* @api
*
* @note          The function Autosar Service ID[hex]: 0x01.
* @note          Synchronous.
* @note          Non Re-entrant function.
* @implements    Adc_DeInit_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DeInit(void)
{
    VAR(Adc_GroupType,AUTOMATIC) Group = 0U;
#ifdef ADC_PDB_SUPPORTED
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
#endif /* ADC_PDB_SUPPORTED */
#if ((ADC_VALIDATE_GLOBAL_CALL == STD_ON) || (ADC_VALIDATE_STATE == STD_ON))
    VAR(Std_ReturnType, AUTOMATIC) ValidStatus = (Std_ReturnType)E_NOT_OK;
#endif

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    ValidStatus = Adc_ValidateGloballCall(ADC_DEINIT_ID);
    if ((Std_ReturnType)E_OK == ValidStatus)
    {
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        ValidStatus = Adc_ValidateDeInitNotBusy();
        if ((Std_ReturnType)E_OK == ValidStatus)
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

            Adc_Ipw_DeInit();
            for (Group = 0U; Group < Adc_pCfgPtr->GroupCount; Group++)
            {
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of */
                Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] = NULL_PTR;
#if (ADC_SETCHANNEL_API == STD_ON)
                Adc_aRuntimeGroupChannel[Group].pChannel = NULL_PTR;
            #if(defined(ADC_PDB_SUPPORTED) || defined(ADC_PTUV3_SUPPORTED))
                Adc_aRuntimeGroupChannel[Group].pu16Delays = NULL_PTR;
                #ifdef ADC_PDB_SUPPORTED
                Adc_aRuntimeGroupChannel[Group].u32Mask = 0UL;
                #endif
            #endif /* (defined(ADC_PDB_SUPPORTED) || defined(ADC_PTUV3_SUPPORTED)) */
                Adc_aRuntimeGroupChannel[Group].ChannelCount = 0U;
                Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean)FALSE;
#endif
            }
#ifdef ADC_PDB_SUPPORTED
            for(Unit = 0U; Unit < ADC_MAX_HW_UNITS; Unit++)
            {
                Adc_aUnitStatus[Unit].u8Sc1Used = 0U;
            }
#endif /* ADC_PDB_SUPPORTED */
            /* Undefined the global pointer to the configuration */
            Adc_pCfgPtr = NULL_PTR;

#if (ADC_VALIDATE_STATE == STD_ON)
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Adc_EndValidateGloballCall(ValidStatus, ADC_DEINIT_ID);
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */
}
#endif /* (ADC_DEINIT_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Starts the conversion of all channels of
*                 the requested ADC Channel group.
* @details        This function will start the SW conversion of all channels
*                 of the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x02.
* @note           Asynchronous.
* @note           Re-entrant function.
* @implements     Adc_StartGroupConversion_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_StartGroupConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = (Adc_HwUnitType)0;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_STARTGROUPCONVERSION_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateStateStartGroupConvNotBusy(Group))
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_STARTGROUPCONVERSION_ID,
                                                                ADC_E_BUFFER_UNINIT_LIST | \
                                                                ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                                ADC_E_QUEUE_FULL_LIST,
                                                                Group
                                                               )
               )
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

                /* Get the unit to which the group belongs to */
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                /* Update queue */
                Adc_UpdateStatusStartConversion(Group, Unit);

#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */
}

/**
* @brief          Stops the conversion of all channels of the requested ADC
*                 Channel group.
* @details        This function will stop the SW conversion of all channels
*                 of the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x03.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_StopGroupConversion_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_StopGroupConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = (Adc_HwUnitType)0;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_STOPGROUPCONVERSION_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateStateNotIdle(ADC_STOPGROUPCONVERSION_ID, Group))
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_STOPGROUPCONVERSION_ID,
                                                                ADC_E_WRONG_TRIGG_SRC_LIST,
                                                                Group
                                                               )
               )
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

                /* Get the unit to which the group belongs to */
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                Adc_UpdateStatusStopConversion(Group, Unit);

#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_READ_GROUP_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Reads the group conversion results.
* @details        Reads the group conversion results of the last completed
                  conversion round of the requested group and stores the
                  channel values starting at the pDataBufferPtr address.
                  The group channel values are stored in ascending channel
                  number order (in contrast to the storage layout of the
                  result buffer if streaming access is configured).
*
* @param[in]      Group          Numeric ID of requested ADC Channel group.
* @param[in]      pDataBufferPtr  ADC results of all channels of the selected group
*                                are stored in the data buffer addressed with the pointer.
* @return         Std_ReturnType Standard return type.
* @retval         E_OK:          results are available and written to the
*                                data buffer.
* @retval         E_NOT_OK:      no results are available or development
*                                error occured.
* @api
* @pre            Preconditions as text description. Optional tag.
* @post           Postconditions as text description. Optional tag.
*
* @note           The function Autosar Service ID[hex]: 0x04.
* @note           Synchronous.
* @note           Reentrant function.
* @implements     Adc_ReadGroup_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
)
{
    /* Return Value */
    VAR(Std_ReturnType, AUTOMATIC) GroupRet = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, AUTOMATIC) bFlag = (boolean)TRUE;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_VALUEREADGROUP_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidatePtr(ADC_VALUEREADGROUP_ID, DataBufferPtr))
        {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
            if ((Std_ReturnType)E_OK == Adc_ValidateStateNotIdle(ADC_VALUEREADGROUP_ID, Group))
            {
#endif /* ADC_VALIDATE_STATE == STD_ON */

                /** @violates @ref Adc_c_REF_7 MISRA-C:2004 Rule 1.4: Undefined behaviour.*/
                GroupRet = Adc_Ipw_ReadGroup(Group, DataBufferPtr, &bFlag);
                /*if the conversion is finished or if the limit checking was failed for the group without interrupts*/
                if(((Std_ReturnType)E_OK == GroupRet) || ((boolean)FALSE == bFlag))
                {
                    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    if((uint8)STD_ON == Adc_pCfgPtr->pGroups[Group].u8AdcWithoutInterrupt)
                    {
                        Adc_UpdateStatusReadGroupNoInt(Group, bFlag);
                    }
                    else
                    {
                        Adc_UpdateStatusReadGroupInt(Group);
                    }
                }
#if (ADC_VALIDATE_STATE == STD_ON)
            }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */

    return(GroupRet);
}
#endif /* (ADC_READ_GROUP_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enables the hardware trigger for the requested ADC Channel group.
* @details        This function will enable the HW trigger source for the requested
*                 ADC channel group. This function does set the CTU register for all
*                 platform that have the CTU Hw Unit.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x05.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_EnableHardwareTrigger_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_ENABLEHARDWARETRIGGER_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateStateEnableHwTriggNotBusy(Group))
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_ENABLEHARDWARETRIGGER_ID,
                                                                ADC_E_BUFFER_UNINIT_LIST | \
                                                                ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                                ADC_E_WRONG_CONV_MODE_LIST | \
                                                                ADC_E_QUEUE_FULL_LIST,
                                                                Group
                                                               )
               )
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

                /* Get the unit to which the group belongs to */
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                Adc_UpdateStatusEnableHardware(Group, Unit);

                Adc_Ipw_EnableHardwareTrigger(Group, Unit);

#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif /* ADC_VALIDATE_GLOBAL_CALL == STD_ON */
}

/**
* @brief          Disables the hardware trigger for the requested ADC Channel group.
* @details        This function will disable the HW trigger source for the requested
*                 ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x06.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_DisableHardwareTrigger_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /* ADC Hardware unit on which the requested group will run */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = (Adc_HwUnitType)0;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_DISABLEHARDWARETRIGGER_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateStateNotIdle(ADC_DISABLEHARDWARETRIGGER_ID, Group))
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_DISABLEHARDWARETRIGGER_ID,
                                                                ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                                ADC_E_WRONG_CONV_MODE_LIST,
                                                                Group
                                                               )
               )
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

                /* Get the unit to which the group belongs to */
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                Adc_UpdateStatusDisableHardware(Group, Unit);

                Adc_Ipw_DisableHardwareTrigger(Group, Unit);

#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enables the notification mechanism for the requested ADC
*                 channel group.
* @details        This function will enable the notification mechanism only for
*                 the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x07.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_EnableGroupNotification_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableGroupNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_ENABLEGROUPNOTIFICATION_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_NotifyCapablity(ADC_ENABLEGROUPNOTIFICATION_ID, Group))
        {
#endif /* ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON */

            /* Enter critical section to protect agains Adc_GroupStatus modifications */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00();
            Adc_aGroupStatus[Group].eNotification = ADC_NOTIFICATION_ENABLED;
            /* Exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00();

#if (ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON)
        }
#endif /* ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}

/**
* @brief          Disables the notification mechanism for the requested ADC
*                 channel group.
* @details        This function will disable the notification mechanism only for
*                 the requested ADC channel group.
*
* @param[in]      Group       Numeric ID of requested ADC channel group.
* @return         void
*
* @api
*
* @note           The function Autosar Service ID[hex]: 0x08.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_DisableGroupNotification_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableGroupNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_DISABLEGROUPNOTIFICATION_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_NotifyCapablity(ADC_DISABLEGROUPNOTIFICATION_ID, Group))
        {
#endif /* ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON */

            /* Enter critical section to protect against Adc_GroupStatus modifications */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01();
            Adc_aGroupStatus[Group].eNotification = ADC_NOTIFICATION_DISABLED;
            /* Exit critical section */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01();

#if (ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON)
        }
#endif /* ADC_VALIDATE_NOTIFY_CAPABILITY == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) || defined(__DOXYGEN__) */

/**
* @brief          Returns the conversion status of the requested ADC Channel group.
* @details        This function will return the conversion status of the requested
*                 ADC channel group.
*
* @param[in]      Group             Numeric ID of requested ADC channel group.
* @return         Adc_StatusType    Conversion status for the requested group.
* @retval         ADC_IDLE          in case of errors.
* @retval         conversion status in case of no errors.
* @api
*
* @note           The function Autosar Service ID[hex]: 0x09.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_GetGroupStatus_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_StatusType, AUTOMATIC) eTempReturn = ADC_IDLE;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_GETGROUPSTATUS_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
        eTempReturn = Adc_aGroupStatus[Group].eConversion;
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

    return(eTempReturn);
}

/**
* @brief          Returns the number of valid samples per channel.
* @details        Returns the number of valid samples per channel, stored in
*                 the result buffer. Reads a pointer, pointing to a position
*                 in the group result buffer. With the pointer position, the
*                 results of all group channels of the last completed conversion
*                 round can be accessed. With the pointer and the return value,
*                 all valid group conversion results can be accessed (the user
*                 has to take the layout of the result buffer into account).
*
* @param[in]      Group              Numeric ID of requested ADC channel group.
* @param[out]     PtrToSamplePtr     Pointer to result buffer pointer.
*
* @return         Adc_StreamNumSampleType Number of valid samples per channel.
* @retval         0                 in case of errors.
* @retval         >0                Number of valid samples per channel.
* @api
*
* @note           The function Autosar Service ID[hex]: 0x0B.
* @note           Synchronous.
* @note           Reentrant function.
* @implements     Adc_GetStreamLastPointer_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr
)
{
    /* Number of samples to return */
    VAR(Adc_StreamNumSampleType, AUTOMATIC) NumberOfResults = 0U;
    VAR(Adc_StreamNumSampleType, AUTOMATIC) ResultIndex = 0U;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_GETSTREAMLASTPOINTER_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateStateNotIdle(ADC_GETSTREAMLASTPOINTER_ID, Group))
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

            *PtrToSamplePtr = (Adc_ValueGroupType *)NULL_PTR;

            /* Enter critical region */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12();

            /** @violates @ref Adc_c_REF_4 only Array indexing shall be allowed */
            if (ADC_IDLE != Adc_aGroupStatus[Group].eConversion)
            {
                if (ADC_BUSY != Adc_aGroupStatus[Group].eConversion)
                {
                    if ((Adc_StreamNumSampleType)0U == Adc_aGroupStatus[Group].ResultIndex)
                    {
                        /** @violates @ref Adc_c_REF_4 only Array indexing shall be allowed */
                        ResultIndex = Adc_pCfgPtr->pGroups[Group].NumSamples - (Adc_StreamNumSampleType)1U;
                        /* ADC387 Note */
                        /** @violates @ref Adc_c_REF_4 only Array indexing shall be allowed */
                        NumberOfResults = Adc_pCfgPtr->pGroups[Group].NumSamples;
                    }
                    else
                    {
                        ResultIndex = Adc_aGroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1U;
                        NumberOfResults = Adc_aGroupStatus[Group].ResultIndex;
                    }
       
                    /* ADC214 -- ADC418 -- ADC382*/
                    /** @violates @ref Adc_c_REF_10 cast from pointer to pointer */
                    /** @violates @ref Adc_c_REF_4 only Array indexing shall be allowed */
                    *PtrToSamplePtr = (Adc_ValueGroupType *)(Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + \
                                                            ResultIndex \
                                                            );
                    Adc_UpdateStatusAfterGetStream(Group);
                }
            }

            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12();

#if (ADC_VALIDATE_STATE == STD_ON)
        }
        else
        {
            *PtrToSamplePtr = NULL_PTR;
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
    else
    {
        *PtrToSamplePtr = NULL_PTR;
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

    return (NumberOfResults);
}

#if (ADC_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Returns the version information of this module.
* @details        Returns the version information of this module.
*
* @param[out]     versioninfo    Pointer to where to store the version
*                                 information of this module.
* @retval         structure       in case of no errors.
* @api
*
* @note           The function Autosar Service ID[hex]: 0x0A.
* @note           Synchronous.
* @note           Reentrant function.
* @implements     Adc_GetVersionInfo_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_GetVersionInfo
(
    P2VAR(Std_VersionInfoType , AUTOMATIC, ADC_APPL_DATA) versioninfo
)
/** @violates @ref Adc_c_REF_2 The identifiers used in the declaration and definition of a function shall be identical */
{
#if (ADC_VALIDATE_PARAMS == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidatePtr(ADC_GETVERSIONINFO_ID, versioninfo))
    {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

        (versioninfo)->vendorID = (uint16)ADC_VENDOR_ID;
        (versioninfo)->moduleID = (uint16)ADC_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)ADC_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)ADC_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)ADC_SW_PATCH_VERSION;

#if (ADC_VALIDATE_PARAMS == STD_ON)
    }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */
}
#endif /* (ADC_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enters the already prepared power state.
* @details        This API configures the Adc module so that it enters the already prepared power 
*                 state, chosen between a predefined set of configured ones.
*
* @param[out]     Result        Pointer to a variable to store the result of this function
*                 
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Power Mode changed.
* @retval         E_NOT_OK:       Request rejected.
*
* @api
*
* @post           Enters the already prepared power state.
*
*
* @note           The function Autosar Service ID[hex]: 0x10.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_SetPowerState_Activity
*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetPowerState
(
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_NOT_OK;

    if((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_SETPOWERSTATE_ID, Result))
    {
        if((Std_ReturnType)E_OK == Adc_ValidatePowerStatePrepare(ADC_SETPOWERSTATE_ID, Result))
        {
            if((Std_ReturnType)E_OK == Adc_ValidatePowerStateSupport(ADC_SETPOWERSTATE_ID, Adc_eTargetState, Result))
            {
                if((Std_ReturnType)E_OK == Adc_ValidateIdleState(ADC_SETPOWERSTATE_ID, Result))
                {
                    if(Adc_eCurrentState == Adc_eTargetState)
                    {
                        /* SWS_Adc_00482 (ADC482) :The target state is the same as the current one, return a E_OK and no action is executed  */
                        *Result = ADC_SERVICE_ACCEPTED;
                        Adc_eTargetState = ADC_NODEFINE_POWER;
                        RetVal=(Std_ReturnType)E_OK;
                    }
                    else
                    {
                        RetVal = Adc_Ipw_SetPowerState(Adc_eTargetState);
                        if((Std_ReturnType)E_OK == RetVal)
                        {
                            /* Everything is ok */
                            *Result = ADC_SERVICE_ACCEPTED;
                            Adc_eCurrentState = Adc_eTargetState;
                            Adc_eTargetState = ADC_NODEFINE_POWER;
                        }
                        else
                        {
                            #if (ADC_DEV_ERROR_DETECT == STD_ON)
                            Adc_ReportDetError(ADC_SETPOWERSTATE_ID, ADC_E_TRANSITION_NOT_POSSIBLE);
                            #endif /* (ADC_DEV_ERROR_DETECT == STD_ON) */
                            /* Hardware failure */
                            *Result = ADC_HW_FAILURE;
                        }
                    }
                }
            }
        }
    }
    
    return RetVal;
}

/**
* @brief          Get the current power state of the ADC HW unit.
* @details        This API returns the current power state of the ADC HW unit.
*
* @param[out]     CurrentPowerState     The current power mode of the ADC HW Unit is returned in this parameter
* @param[out]     Result                Pointer to a variable to store the result of this function
*                 
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Mode could be read.
* @retval         E_NOT_OK:       Service is rejected.
*
* @api
*
* @post           Returns the current power state of the ADC HW unit.
*
*
* @note           The function Autosar Service ID[hex]: 0x11.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_GetCurrentPowerState_Activity
*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_GetCurrentPowerState
(
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) CurrentPowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_NOT_OK;

    if((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_GETCURRENTPOWERSTATE_ID, Result))
    {
#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidatePtr(ADC_GETCURRENTPOWERSTATE_ID, CurrentPowerState))
#endif /* (ADC_VALIDATE_PARAMS == STD_ON) */
        {
            *CurrentPowerState = Adc_eCurrentState;
            *Result = ADC_SERVICE_ACCEPTED;
            RetVal = (Std_ReturnType)E_OK;  
        }
    }
    return RetVal;
}

/**
* @brief          Get the target power state of the ADC HW unit.
* @details        This API returns the target power state of the ADC HW unit.
*
* @param[out]     TargetPowerState      The Target power mode of the ADC HW Unit is returned in this parameter.
* @param[out]     Result                Pointer to a variable to store the result of this function.
*                 
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Mode could be read.
* @retval         E_NOT_OK:       Service is rejected.
*
* @api
*
* @post           Returns the target power state of the ADC HW unit.
*
*
* @note           The function Autosar Service ID[hex]: 0x12.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_GetTargetPowerState_Activity
*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_GetTargetPowerState
(
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) TargetPowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_NOT_OK;

    if((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_GETTARGETPOWERSTATE_ID, Result))
    {
#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidatePtr(ADC_GETTARGETPOWERSTATE_ID, TargetPowerState))
#endif /* (ADC_VALIDATE_PARAMS == STD_ON) */
        {
            if(Adc_eTargetState < ADC_NODEFINE_POWER)
            {
                /* A transition is ongoing */
                *TargetPowerState = Adc_eTargetState;
            }
            else
            {
                /* No transition is ongoing */
                *TargetPowerState = Adc_eCurrentState;
            }
            *Result = ADC_SERVICE_ACCEPTED;
            RetVal = (Std_ReturnType)E_OK;  
        }
    }
    return RetVal;
}

/**
* @brief          Starts the needed process to allow the ADC HW module to enter the requested power state.
* @details        This API starts the needed process to allow the ADC HW module to enter the requested power state.
*
* @param[in]      PowerState      The target power state intended to be attained.
* @param[out]     Result          Pointer to a variable to store the result of this function.
*                 
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Mode could be read.
* @retval         E_NOT_OK:       Service is rejected.
*
* @api
*
* @post           Starts the needed process to allow the ADC HW module to enter the requested power state.
*
*
* @note           The function Autosar Service ID[hex]: 0x13.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_PreparePowerState_Activity
*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_PreparePowerState
(
    VAR(Adc_PowerStateType, AUTOMATIC) PowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
)
{
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_NOT_OK;

    if((Std_ReturnType)E_OK == Adc_ValidateStateAndPtr(ADC_PREPAREPOWERSTATE_ID, Result))
    {   
        if((Std_ReturnType)E_OK == Adc_ValidatePowerStateSupport(ADC_PREPAREPOWERSTATE_ID, PowerState, Result))
        {
            /* Everything is ok */
            Adc_eTargetState = PowerState;
            *Result = ADC_SERVICE_ACCEPTED;
            RetVal = (Std_ReturnType)E_OK;
        }
    }
    return RetVal;
}

#if (ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Cyclically called and supervises the power state transitions.
* @details        This API is cyclically called and supervises the power state transitions, checking for the readiness of the module and issuing the callbacks.
*
* @param[in]      none
* @param[out]     none
*                 
* @return         none
*
* @api
*
* @post           Cyclically called and supervises the power state transitions.
*
*
* @note           The function Autosar Service ID[hex]: 0x14.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_Main_PowerTransitionManager_Activity
*
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_Main_PowerTransitionManager(void)
{
    
}
#endif /* (ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED == STD_ON) */
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_SET_MODE_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Set the ADC mode either to powerdown or normal.
* @details        Set the ADC either to powerdown or normal mode.
*
* @param[in]      SetMode         Normal or powerdown mode.
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           In case of successful settings.
* @retval         E_NOT_OK:       In case of unsuccessful settings.
*
* @api
*
* @note           The function Non Autosar Service ID[hex]: 0x10.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_SetMode_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) SetMode
)
{
    /* Return standard value */
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U;

    if ((Std_ReturnType)E_OK == Adc_ValidateSetMode(SetMode))
    {
        for(HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            Unit = Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId; 
            TempReturn = Adc_ValidateNotBusyNoQueue(Unit, ADC_SETMODE_ID); 
            if ((Std_ReturnType)E_NOT_OK == TempReturn)
            {
                break;
            }
        }
        if ((Std_ReturnType)E_OK == TempReturn)
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateCheckGroupNotConversion(ADC_SETMODE_ID))
            {
                TempReturn = Adc_Ipw_SetMode(SetMode);
            }
        }
    }
    return TempReturn;
}
#endif /* (ADC_SET_MODE_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enable the TriggerSource for group selected by Group parameter.
* @details        This non Autosar API is used to enable any one of the configured
*                 TriggerSource of the Group. When this non Autosar API is used to
*                 enable the trigger source the CTU interrupt will be disabled by the driver.
*                 So user has to call the non Autosar API Adc_HwResultReadGroup to read
*                 the converted result from the ADC hardware register.
*
* @param[in]      Group            Index of group.
* @param[in]      TriggerSource    Trigger source to be used for the group.
*                                  (Configuration file should contain it for that group).
* @return         void
*
* @api
*
* @note           The function Service ID[hex]: 0x0E.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_EnableCTUTrigger_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableCTUTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_ENABLECTUTRIGGER_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateNotBusyEnableCtuTrig(Group))
        {
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_ENABLECTUTRIGGER_ID,
                                                                ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                                ADC_E_WRONG_CONV_MODE_LIST,
                                                                Group
                                                               )
               )
            {
                if ((Std_ReturnType)E_OK == Adc_ValidateCtuTriggerSrc(ADC_ENABLECTUTRIGGER_ID, Group, TriggerSource))
                {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */
                    Adc_Ipw_EnableCtuTrigger(Group, TriggerSource);
#if (ADC_VALIDATE_PARAMS == STD_ON)
                }
            }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_STATE == STD_ON)
        }
#endif /* ADC_VALIDATE_STATE == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}

/**
* @brief          Disable the TriggerSource for group selected by Group parameter.
* @details        This non Autosar API is used to disable the already enabled
*                 TriggerSource of the Group.
*
* @param[in]      Group            Index of group.
* @param[in]      TriggerSource    Trigger source to be disabled for the group.
*                                  (Configuration file should contain it for that group).
* @return         void
*
* @api
*
* @note           The function Service ID[hex]: 0x0F.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_DisableCTUTrigger_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableCTUTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_DISABLECTUTRIGGER_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_DISABLECTUTRIGGER_ID,
                                                            ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                            ADC_E_WRONG_CONV_MODE_LIST,
                                                            Group
                                                           )
           )
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateCtuTriggerSrc(ADC_DISABLECTUTRIGGER_ID, Group, TriggerSource))
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */
                Adc_Ipw_DisableCtuTrigger(Group, TriggerSource);
#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}

/**
* @brief          Read the result of the hardware triggered groups conversion result.
* @details        This non Autosar API is used to read the result of the hardware
*                 triggered groups conversion result from the ADC hardware register
*                 in this case the CTU interrupt will be disabled for the group.
*                 The VALID bit CDR register will be cleared automatically when we read the results
*                 from the channel data register. If the user calls non-Autosar function
*                 Adc_HwResultReadGroup() once again before the next conversion takes place, the
*                 Adc_HwResultReadGroup() returns E_NOT_OK.
*
* @param[in]      Group      Index of group.
* @param[in]      pDataPtr    Pointer to a buffer which will be filled by the
*                            conversion results.
* @return         Std_ReturnType Standard return type.
* @retval         E_OK:          results are available and written to the
*                                data buffer.
* @retval         E_NOT_OK:      no results are available or development
*                                error occurred.
* @api
* @note           The function Service ID[hex]: 0x0D.
* @note           Synchronous.
* @note           Non Re-entrant function.
* @implements     Adc_HwResultReadGroup_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
)
{
    /* Standard return value */
    VAR(Std_ReturnType, AUTOMATIC) GroupRet = (Std_ReturnType)E_NOT_OK;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_HWRESULTREADGROUP_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if (NULL_PTR == DataPtr)
        {
            GroupRet = (Std_ReturnType)E_NOT_OK;
        }
        else
#endif
        {
            GroupRet = Adc_Ipw_HwResultReadGroup(Group, DataPtr);
        }
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
    return(GroupRet);
}
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Enable a channel inside a group.
* @details        This function allows to active a channel assigned to a group for SW normal
*                 conversion
*
* @param[in]      Group         Symbolic name of group.
* @param[in]      Channel       Symbolic name of channel.
* @return         void
*
* @api
*
* @note           The function Service ID[hex]: 0x12.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_EnableChannel_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_EnableChannel
(
   VAR(Adc_GroupType, AUTOMATIC) Group,
   VAR(Adc_ChannelType, AUTOMATIC) Channel
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = (Adc_HwUnitType)0;
    VAR(Adc_ChannelType, AUTOMATIC) ChId;
    VAR(Adc_GroupType, AUTOMATIC) GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
    VAR(Adc_NcmrType , AUTOMATIC) CmrMask;
    
#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_ENABLE_CHANNEL_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_ENABLE_CHANNEL_ID,
                                                            ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                            ADC_E_WRONG_CONV_MODE_LIST | \
                                                            ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP_LIST | \
                                                            ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID_LIST, \
                                                            Group \
                                                           )
           )
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateEnableDisbleIdList(ADC_ENABLE_CHANNEL_ID, Group, Channel))
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */
                /* Get the unit to which the group belongs to */
                /** @violates @ref Adc_c_REF_4 Array indexing */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                /** @violates @ref Adc_c_REF_4 Array indexing */
                ChId = Adc_pCfgPtr->pChannels[Unit][Channel].ChId;
                /** @violates @ref Adc_c_REF_4 Array indexing */
                GroupId = (Adc_GroupType)Adc_pCfgPtr->pGroups[Group].EnableChDisableChGroupIndex;
                
                /* Global Interrupt disable to protect code section */
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25();
                /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
                Adc_GetCmrRegister(Unit, Group, &CmrMask);
                if(ChId < ADC_ST_EXTENDED_CH_U8)
                {
                    /* Precision channel */
                    Adc_aNCMRxMask[GroupId].Adc_u32NCMR0 = (CmrMask.Adc_u32NCMR0 | ((uint32)1UL << ChId));
                }
                else if ((ChId >= ADC_ST_EXTENDED_CH_U8) && (ChId <= ADC_ED_EXTENDED_CH_U8))
                {
                    /* Standard channel */
                    Adc_aNCMRxMask[GroupId].Adc_u32NCMR1 = (CmrMask.Adc_u32NCMR1 | ((uint32)1UL << (ChId - ADC_ST_EXTENDED_CH_U8)));
                }
                else if ((ChId >= ADC_ST_EXTERNAL_CH_U8) && (ChId <= ADC_ED_EXTERNAL_CH_U8))
                {
                    /* External multiplexed channel */
                    Adc_aNCMRxMask[GroupId].Adc_u32NCMR2 = (CmrMask.Adc_u32NCMR2 | ((uint32)1UL << (ChId - ADC_ST_EXTERNAL_CH_U8)));
                }
                else
                {
                    /* nothing for misra */
                }
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25();
#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}

/**
* @brief          Disable a channel inside a group.
* @details        This function allows to de-active a channel assigned to a group for SW normal
*                 conversion
*
* @param[in]      Group        Symbolic name of group.
* @param[in]      Channel      Symbolic name of channel.
*
* @return         void
*
* @api
* @note           The function Service ID[hex]: 0x13.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_DisableChannel_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_DisableChannel
(
    VAR(Adc_GroupType, AUTOMATIC)Group,
    VAR(Adc_ChannelType, AUTOMATIC)Channel
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) ChId;
    VAR(Adc_GroupType, AUTOMATIC) GroupId = ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX;
    VAR(Adc_NcmrType , AUTOMATIC) CmrMask;

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_DISABLE_CHANNEL_ID, Group))
    {
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidateExtraParams(ADC_DISABLE_CHANNEL_ID,
                                                            ADC_E_WRONG_TRIGG_SRC_LIST | \
                                                            ADC_E_WRONG_CONV_MODE_LIST | \
                                                            ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP_LIST | \
                                                            ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID_LIST, \
                                                            Group \
                                                           )
           )
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateEnableDisbleIdList(ADC_DISABLE_CHANNEL_ID, Group, Channel))
            {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */
                /** @violates @ref Adc_c_REF_4 Array indexing */
                Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
                /** @violates @ref Adc_c_REF_4 Array indexing */
                ChId = Adc_pCfgPtr->pChannels[Unit][Channel].ChId;
                /** @violates @ref Adc_c_REF_4 Array indexing */
                GroupId = (Adc_GroupType)Adc_pCfgPtr->pGroups[Group].EnableChDisableChGroupIndex;
                
                /* Global Interrupt disable to protect code section */
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18();
                /** @violates @ref Adc_c_REF_7 It is needed for calculation value of go back space for source address.*/
                Adc_GetCmrRegister(Unit, Group, &CmrMask);
                if (ChId < ADC_ST_EXTENDED_CH_U8)
                {   /* Precision channel */
                    Adc_aNCMRxMask[GroupId].Adc_u32NCMR0 = (CmrMask.Adc_u32NCMR0 & (~((uint32)1UL << ChId)));
                }
                else if ((ChId >= ADC_ST_EXTENDED_CH_U8) && (ChId <= ADC_ED_EXTENDED_CH_U8))
                {   /* Standard channel */
                    Adc_aNCMRxMask[GroupId].Adc_u32NCMR1 = (CmrMask.Adc_u32NCMR1 & (~((uint32)1UL << (ChId - ADC_ST_EXTENDED_CH_U8))));
                }
                else if ((ChId >= ADC_ST_EXTERNAL_CH_U8) && (ChId <= ADC_ED_EXTERNAL_CH_U8))
                {   /* External multiplexed channel */
                    Adc_aNCMRxMask[GroupId].Adc_u32NCMR2 = (CmrMask.Adc_u32NCMR2 & (~((uint32)1UL << (ChId - ADC_ST_EXTERNAL_CH_U8))));
                }
                else
                {
                    /* nothing for misra */
                }
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18();
#if (ADC_VALIDATE_PARAMS == STD_ON)
            }
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_CALL_AND_GROUP == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_GROUP == STD_ON */
}
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Get the injected conversions status.
* @details        This function checks if an injected conversion (HW,SW) is ongoing
*
* @param[in]      unit            ADC Unit id.
*
* @return         Adc_StatusType  Status of the ADC HW unit.
* @retval         ADC_IDLE:       SW,HW Injection or Hardware Trigger group are idle.
* @retval         ADC_BUSY:       SW,HW Injection or Hardware Trigger is inprogress.
*
* @api
* @note           The function Service ID[hex]: 0x14.
* @note           Synchronous.
* @note           Re-entrant function.
* @implements     Adc_GetInjectedConversionStatus_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Adc_StatusType, ADC_CODE) Adc_GetInjectedConversionStatus
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Adc_StatusType, AUTOMATIC) eTempReturn = (Adc_StatusType)ADC_IDLE;

#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndUnit(ADC_GETINJECTEDCONVERSIONSTATUS_ID, Unit))
    {
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */

        /* Global Interrupt disable to protect code section */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19();

        if (Adc_aUnitStatus[Unit].SwInjectedQueueIndex > (Adc_QueueIndexType)0)
        {
            eTempReturn = (Adc_StatusType)ADC_BUSY;
        }
#if (ADC_HW_TRIGGER_API == STD_ON)
        else if (Adc_aUnitStatus[Unit].HwInjectedQueueIndex > (Adc_QueueIndexType)0)
        {
            eTempReturn = (Adc_StatusType)ADC_BUSY;
        }
#endif
        else
        {
            /* nothing for Mirsa */
        }

        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19();
#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */

    return (eTempReturn);
}
#endif /* (ADC_GET_INJECTED_CONVERSION_STATUS_API) || defined(__DOXYGEN__) */

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief          Executes high accuracy calibration of a ADC HW unit.
* @details        This function calibrates the ADC HW unit and updates calibration related registers
*
* @param[in]      Unit      ADC Unit Id.
* @param[in]      pStatus    Status of the ADC HW unit calibration and
*                           list of failed and passed tests.
*
* @return         void
*
* @api
*
* @note           The function Service ID[hex]: 0x15.
* @implements  Adc_Calibrate_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_Calibrate
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2VAR(Adc_CalibrationStatusType , AUTOMATIC, ADC_APPL_DATA) pStatus
)
{ 
#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndUnit(ADC_CALIBRATE_ID, Unit))
    {
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */

#if (ADC_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Adc_ValidatePtr(ADC_CALIBRATE_ID, pStatus))
        {
#endif /* ADC_VALIDATE_PARAMS == STD_ON */
            if ((Std_ReturnType)E_OK == Adc_ValidateNotBusyNoQueue(Unit, ADC_CALIBRATE_ID))
            {
                
                if ((Std_ReturnType)E_OK == Adc_ValidateCheckGroupNotConversion(ADC_CALIBRATE_ID))
                {
                    pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType) E_NOT_OK;
                    Adc_Ipw_Calibrate(Unit, pStatus);
                }
            }
#if (ADC_VALIDATE_PARAMS == STD_ON)
        }
#endif /* ADC_VALIDATE_PARAMS == STD_ON */

#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */
}
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_SELF_TEST == STD_ON)
/**
* @brief          Executes hardware Self Test of a ADC HW unit.
* @details        This function checks if the ADC HW unit is functioning correctly
*
* @param[in]      Unit    ADC Unit Id.
*
* @return         Std_ReturnType. Status of the ADC HW unit Self Test.
*
* @api
*
* @note           The function Service ID[hex]: 0x16.
* @implements  Adc_SelfTest_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SelfTest
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Std_ReturnType, AUTOMATIC) ReturnValue = (Std_ReturnType)E_NOT_OK;

#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndUnit(ADC_SELFTEST_ID , Unit))
    {
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */

        ReturnValue = Adc_Ipw_SelfTest(Unit);

#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    }
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */
    return ReturnValue;
}
#endif

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
/**
 * @brief   Function to reconfigure High and Low thresholds for a given group.
 *
 * @details This Non Autosar API is used to reconfigure High and Low thresholds for a given group.
 *
 * @note    The function Service ID[hex]: 0x14.
 *
 * @param[in]  GroupId          Index of group
 * @param[in]  LowValue         Low threshold value for channels in the group
 * @param[in]  HighValue        High threshold value for channels in the group
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful Configure Threshold.
 * @retval         E_NOT_OK        In case of unsuccessful ConfigureThreshold.
 *
 * @implements Adc_ConfigureThreshold_Activity
 *
 * @api
 */
/** @violates @ref Adc_c_REF_3 All declarations and definitions of objects or */
FUNC(Std_ReturnType, ADC_CODE) Adc_ConfigureThreshold
(
    VAR(Adc_GroupType, AUTOMATIC) GroupId,
    VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
    VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
)
{
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChCount = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) Ch = 0U;
    VAR(boolean, AUTOMATIC) bErrorFlag = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) bThresholdEnabled = (boolean)FALSE;
#endif /* if (ADC_DEV_ERROR_DETECT == STD_ON) */
    VAR(Std_ReturnType, AUTOMATIC) ConThdRet = (Std_ReturnType)E_NOT_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Adc_pCfgPtr)
    {
        /* Error (ADC302): called prior to initializing */
        Adc_ReportDetError((uint8)ADC_CONFIGURE_THRESHOLD_ID, (uint8)ADC_E_UNINIT);
        bErrorFlag = (boolean)TRUE;
    }
    else if (GroupId >= Adc_pCfgPtr->GroupCount)
    {
        /* Error (ADC218): non-existing group ID */
        Adc_ReportDetError(ADC_CONFIGURE_THRESHOLD_ID, (uint8)ADC_E_PARAM_GROUP);
        bErrorFlag = (boolean)TRUE;
    }
    else if (HighValue < LowValue)
    {
        /* Error if High Threshold value is less than Low Threshold value */
        Adc_ReportDetError((uint8)ADC_CONFIGURE_THRESHOLD_ID, (uint8)ADC_E_WRONG_CONF_THRHLD_VALUE);
        bErrorFlag = (boolean)TRUE;
    }
    else
    {
      /* Check for Error: group has no channels with threshold enabled */
      /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of */
        Unit = Adc_pCfgPtr->pGroups[(GroupId)].HwUnit;
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of */
            for(ChCount = 0U; ((boolean)FALSE == bThresholdEnabled) && \
                (ChCount <Adc_pCfgPtr->pGroups[GroupId].AssignedChannelCount); \
                ChCount++
               )
            {
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of */
                Ch = Adc_pCfgPtr->pGroups[GroupId].pAssignment[ChCount];
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of */
                if(ADC_UNUSED_THRESHOLD_U8 != Adc_pCfgPtr->pChannels[Unit][Ch].u8ThReg)
                {
                    bThresholdEnabled = (boolean)TRUE;
                }
            }

            if ((boolean)FALSE == bThresholdEnabled)
            {
                Adc_ReportDetError((uint8)ADC_CONFIGURE_THRESHOLD_ID, (uint8)ADC_E_WRONG_CONF_THRHLD_GROUP);
                bErrorFlag = (boolean)TRUE;
            }
        }
    }

    if((boolean)FALSE == bErrorFlag)
    {
  #endif /* if (ADC_DEV_ERROR_DETECT == STD_ON) */

        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26();
        ConThdRet = Adc_Ipw_ConfigureThreshold(GroupId, LowValue, HighValue);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26();

  #if (ADC_DEV_ERROR_DETECT == STD_ON)
        if((Std_ReturnType)E_NOT_OK == ConThdRet)
        {
            Adc_ReportDetError((uint8)ADC_CONFIGURE_THRESHOLD_ID, (uint8)ADC_E_WRONG_CONF_THRHLD_VALUE);
        }
    }
  #endif

    return ConThdRet;
}
#endif /* ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON || defined(__DOXYGEN__) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Set the ADC clock prescaler if available and modify the conversion timings.
* @details        This function sets the ADC clock prescaler (Analog clock frequency selector)
*
* @param[in]      eClockMode      Normal or Alternate mode.
*
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           In case of successful settings.
* @retval         E_NOT_OK:       In case of unsuccessful settings.
*
* @api
*
* @implements     Adc_SetClockMode_Activity
*/
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetClockMode
(
    VAR(Adc_DualClockModeType, AUTOMATIC) eClockMode
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
    VAR(Std_ReturnType, AUTOMATIC) ErrorFound = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Adc_pCfgPtr)
    {
        Adc_ReportDetError((uint8)ADC_SETCLOCKMODE_ID, (uint8)ADC_E_UNINIT);
    }
    else if ((ADC_NORMAL != eClockMode) && (ADC_ALTERNATE != eClockMode))
    {
        Adc_ReportDetError((uint8)ADC_SETCLOCKMODE_ID, (uint8)ADC_E_INVALID_CLOCK_MODE);
    }
    else
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
    {
        for(HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            Unit = Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId; 
            ErrorFound = Adc_ValidateNotBusyNoQueue(Unit, ADC_SETCLOCKMODE_ID); 
            if ((Std_ReturnType)E_NOT_OK == ErrorFound)
            {
                break;
            }
        } 
        if ((Std_ReturnType)E_OK == ErrorFound)
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateCheckGroupNotConversion(ADC_SETCLOCKMODE_ID))
            {

                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27();
                Ret = Adc_Ipw_SetClockMode(eClockMode);
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
                Adc_eClockMode = eClockMode;
#endif
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27();

            }        
        }    
    }
    return Ret;
}
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)
/**
 * @brief   Function to set the trigger handler control registers of the CTUV2 IP.
 *
 * @details Full configurability of CTU THCR1 & THCR2 registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and the mask (8 bit)
 *          to enable the External Trigger and Timer output for that Trigger, without considering
 *          the ADC command output enable.
 *          See from the RM the THCR1 and THCR2 registers for the right Thcr_value to use.
 *
 * @note    The function Service ID[hex]: 0x35.
 *
 * @param[in]  Trigger      Index of the trigger: 0...7.
 * @param[in]  ThcrValue   THCRx mask value (only with bits for Ext. Trigger and Timer) for the selected input trigger.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful settings.
 * @retval         E_NOT_OK        In case of unsuccessful settings.
 *
 * @implements Adc_SetCTU2TriggerHandlerCtrlRegs_Activity
 *
 * @api
 */
/** @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required */
/** @violates @ref Adc_c_REF_5 Identifier clash */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCtu2TriggerHandlerCtrlRegs
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(uint8, AUTOMATIC) u8ThcrValue
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_ValidateCallAndTrigger(CTUV2_SET_TRG_HANDLER_CTRL_REGS_ID, u8Trigger);
    if((Std_ReturnType)E_OK == Ret)
#endif
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28();
        Ret = Adc_Ipw_SetCtu2TriggerHandlerCtrlRegs(u8Trigger, u8ThcrValue);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28();
    }
    return Ret;
}

/**
* @brief   Function to set or clear the bit Tx_E of the trigger handler control registers of the CTUV2 IP.
 *
 * @details Full configurability of CTU THCR1 & THCR2 registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and a Boolean to set to clear the right trigger bit.
 *          See from the RM the THCR1 and THCR2 registers for the right API use.
 *
 * @param[in]  Trigger      Index of the trigger: 0...7.
 * @param[in]  bEnable      if True, the bit Tx_E shall be set to 1, 0 otherwise
 *
 * @note    The function Service ID[hex]: 0x36.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful settings.
 * @retval         E_NOT_OK        In case of unsuccessful settings.
 *
 * @implements Adc_CTU2TriggerHandlerCtrlRegsEnableDisable_Activity
 *
 * @api
 */
/** @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
 * functions at file scope shall have internal linkage unless external linkage is required
 * @violates @ref Adc_c_REF_5 Identifier clash
 */
FUNC(Std_ReturnType, ADC_CODE) Adc_Ctu2TriggerHandlerCtrlRegsEnableDisable
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(boolean, AUTOMATIC) bEnable
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_ValidateCallAndTrigger(CTUV2_EN_DIS_TRG_HANDLER_CTRL_REGS_ID, u8Trigger);
    if((Std_ReturnType)E_OK == Ret)
#endif
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28();
        Ret = Adc_Ipw_Ctu2TriggerHandlerCtrlRegsEnableDisable(u8Trigger, bEnable);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28();
    }
    return Ret;
}

/**
* @brief   Function to set the cmd list handler control registers of the CTUV2 IP.
 *
 * @details Full configurability of CLCR1 & CLCR2 registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and  the position of the first
 *          command in the command list.
 *          See from the RM the CLCR1 and CLCR2 registers for the right API use.
 *
 * @param[in]  u8Trigger      Index of the trigger: 0...7.
 * @param[in]  u8ClcrValue   Position of the first command
 *
 * @note    The function Service ID[hex]: 0x37.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful settings.
 * @retval         E_NOT_OK        In case of unsuccessful settings.
 *
 * @implements Adc_SetCTU2CmdListHandlerCtrlRegs_Activity
 *
 * @api
 */
/** @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
 * functions at file scope shall have internal linkage unless external linkage is required
 * @violates @ref Adc_c_REF_5 Identifier clash
 */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCtu2CmdListHandlerCtrlRegs
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(uint8, AUTOMATIC) u8ClcrValue
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_ValidateCallAndTrigger(CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID, u8Trigger);
    if((Std_ReturnType)E_OK == Ret)
    {
        if ((uint32)u8ClcrValue > CTU2_CLCR_MAX_VALUE_U8)
        {
            Adc_ReportDetError(CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID, ADC_E_WRONG_CTUV2_CLCR_TRIGGER);
            Ret = (Std_ReturnType)E_NOT_OK;
        }
    }
    if((Std_ReturnType)E_OK == Ret)
#endif
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28();
        Ret = Adc_Ipw_SetCtu2CmdListHandlerCtrlRegs(u8Trigger, u8ClcrValue);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28();
    }
    return Ret;
}
/**
 * @brief   Function to set the trigger compare registers of the CTUV2 IP.
 *
 * @details Full configurability of CTU TxCR registers of the CTUv2 IP.
 *          This function has in input the CTU trigger (0...7) and the comparator value
 *          See from the RM the TxCR trigger compare registers for the right compare_value to use.
 *
 * @note    The function Service ID[hex]: 0x38.
 *
 * @param[in]  u8Trigger      Index of the trigger: 0...7.
 * @param[in]  u16CompareValue  value to set in the register TxCR.
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful settings.
 * @retval         E_NOT_OK        In case of unsuccessful settings.
 *
 * @implements Adc_SetCTU2TriggerCompareRegs_Activity
 *
 * @api
 */
 /** @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required */
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCtu2TriggerCompareRegs
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(uint16, AUTOMATIC) u16CompareValue
)
{
    VAR(Std_ReturnType, AUTOMATIC) Ret = (Std_ReturnType)E_OK;

#if (ADC_DEV_ERROR_DETECT == STD_ON)
    Ret = Adc_ValidateCallAndTrigger(CTUV2_SET_TRIGGER_COMPARE_REGS_ID, u8Trigger);
    if((Std_ReturnType)E_OK == Ret)
#endif
    {
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28();
        Ret = Adc_Ipw_SetCtu2TriggerCompareRegs(u8Trigger, u16CompareValue);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28();
    }
    return Ret;
}
#endif /* if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)  */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
 * @brief   Function to enable CTU control mode for an ADC unit.
 *
 * @details Enable CTU control mode for an ADC unit.
 *          This function to enable CTU control mode for Adc. When a unit works in CTU control mode,
 *          no other conversions shall run in parallel(Adc). The only conversions occurring shall be
 *          the ones defined in the CTU configuration.
 *
 * @param[in]  Unit      ADC Unit Id.
 *
 * @note    The function Service ID[hex]: 0x39.
 *
 * @implements Adc_EnableCtuControlMode_Activity
 *
 * @api
 */
/** @violates @ref Adc_c_REF_3 internal linkage vs external linkage. */
FUNC(void, ADC_CODE) Adc_EnableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndUnit(ADC_ENABLECTUCONTROLMODE_ID, Unit))
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    {
        if ((Std_ReturnType)E_OK == Adc_ValidateUnitActive(ADC_ENABLECTUCONTROLMODE_ID, Unit))
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateStateCtuControlMode(ADC_ENABLECTUCONTROLMODE_ID, Unit))
            {
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
                Adc_Ipw_EnableCtuControlMode(Unit);
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
}
/**
 * @brief   Function to disable CTU control mode for an ADC unit.
 *
 * @details Disable CTU control mode for an ADC unit.
 *          This function to disable CTU control mode for Adc. The other Adc conversions can run in
 *          software trigger normal mode, software trigger injected mode or hardware trigger mode.
 *
 * @param[in]  Unit      ADC Unit Id.
 *
 * @note    The function Service ID[hex]: 0x4A.
 *
 * @implements Adc_DisableCtuControlMode_Activity
 *
 * @api
 */
/** @violates @ref Adc_c_REF_3 internal linkage vs external linkage. */
FUNC(void, ADC_CODE) Adc_DisableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#if (ADC_VALIDATE_CALL_AND_UNIT == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndUnit(ADC_DISABLECTUCONTROLMODE_ID, Unit))
#endif /* ADC_VALIDATE_CALL_AND_UNIT == STD_ON */
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    {
        if ((Std_ReturnType)E_OK == Adc_ValidateUnitActive(ADC_DISABLECTUCONTROLMODE_ID, Unit))
        {
            if ((Std_ReturnType)E_OK == Adc_ValidateStateCtuControlMode(ADC_DISABLECTUCONTROLMODE_ID, Unit))
            {
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
                Adc_Ipw_DisableCtuControlMode(Unit);
#if (ADC_DEV_ERROR_DETECT == STD_ON)
            }
        }
    }
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
}
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if (ADC_SETCHANNEL_API == STD_ON)
/**
 * @brief   Function to dynamic handling of ADC channels list for Adc channel group.
 *
 * @details Dynamic handling of ADC channels list.
 *          This function to dynamic handling of ADC channels list for Adc channel group.
 *
 * @param[in]  Group                Group Id.
 * @param[in]  pChannel             Pointer to channel list array.
 * @param[in]  NumberOfChannel      Number of Channel.
 *
 * @note    The function Service ID[hex]: 0x4B.
 *
 * @implements Adc_SetChannel_Activity
 *
 * @api
 * @violates @ref Adc_c_REF_3 internal linkage vs external linkage.
 */
FUNC(void, ADC_CODE) Adc_SetChannel
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupDefType, AUTOMATIC, ADC_APPL_CONST) pChannel,
    P2CONST(uint16, AUTOMATIC, ADC_APPL_CONST) pDelays,
    CONST(uint32, AUTOMATIC) u32Mask,
    CONST(Adc_ChannelIndexType, AUTOMATIC) NumberOfChannel
)
{
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    if ((Std_ReturnType)E_OK == Adc_ValidateCallAndGroup(ADC_SETCHANNEL_ID, Group))
    {
    #if (defined(ADC_PDB_SUPPORTED) || defined(ADC_PTUV3_SUPPORTED))
        if((NULL_PTR == pChannel) || (NULL_PTR == pDelays))
    #else
        if(NULL_PTR == pChannel)
    #endif /* (defined(ADC_PDB_SUPPORTED) || defined(ADC_PTUV3_SUPPORTED)) */       
        {
            Adc_ReportDetError(ADC_SETCHANNEL_ID, (uint8)ADC_E_PARAM_POINTER);
        }
        else if((0U == NumberOfChannel) 
                #ifdef ADC_PDB_SUPPORTED
                || (NumberOfChannel > ADC_NUM_SC1n_REGISTER_USED)
                #endif
                #ifdef ADC_PTUV3_SUPPORTED
                /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                || (NumberOfChannel > Adc_pCfgPtr->pGroups[Group].AssignedChannelCount)
                #endif
               )
        {
            Adc_ReportDetError(ADC_SETCHANNEL_ID, (uint8)ADC_E_PARAM_CHANNEL);
        }
        else
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
        {
            /* Enter critical region */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_30();
            Adc_aRuntimeGroupChannel[Group].pChannel = pChannel;
        #if (defined(ADC_PDB_SUPPORTED) || defined(ADC_PTUV3_SUPPORTED))
            Adc_aRuntimeGroupChannel[Group].pu16Delays = pDelays;
            #ifdef ADC_PDB_SUPPORTED
            Adc_aRuntimeGroupChannel[Group].u32Mask = u32Mask;
            #else
            (void)u32Mask;  /* Avoid compiler warning */
            #endif
        #else
            (void)pDelays;  /* Avoid compiler warning */
            (void)u32Mask;  /* Avoid compiler warning */
        #endif /* (defined(ADC_PDB_SUPPORTED) || defined(ADC_PTUV3_SUPPORTED)) */
            Adc_aRuntimeGroupChannel[Group].ChannelCount = NumberOfChannel;
            Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean) TRUE;
            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_30();
        }
#if (ADC_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* ADC_DEV_ERROR_DETECT == STD_ON */
}
#endif /* ADC_SETCHANNEL_API == STD_ON */

#ifndef ADC_CMR_REGISTER_NOT_SUPPORTED
FUNC(void, ADC_CODE) Adc_GetCmrRegister
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_NcmrType , AUTOMATIC, ADC_APPL_DATA) pCmrMask
)
{
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    VAR(Adc_GroupType, AUTOMATIC) Adc_IndividualGroupId;
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
#if (ADC_SETCHANNEL_API == STD_ON)
    VAR(Adc_ChannelType, AUTOMATIC) ChId;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Ch;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_SETCHANNEL_API == STD_OFF)
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr =  &(Adc_pCfgPtr->pGroups[Group]);
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || (ADC_SETCHANNEL_API == STD_OFF) */

    (void)Unit;

    pCmrMask->Adc_u32NCMR0 = 0UL;
#if ((ADC_NCMR1_AVAILABLE == STD_ON) || (ADC_JCMR1_AVAILABLE == STD_ON))
    pCmrMask->Adc_u32NCMR1 = 0UL;
#endif
#if ((ADC_NCMR2_AVAILABLE == STD_ON) || (ADC_JCMR2_AVAILABLE == STD_ON))
    pCmrMask->Adc_u32NCMR2 = 0UL;
#endif
    
    /* If the Individual group channel enable capability is ON*/
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    Adc_IndividualGroupId = pGroupPtr->EnableChDisableChGroupIndex;
    if(ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != Adc_IndividualGroupId)
    {
        pCmrMask->Adc_u32NCMR0 = Adc_aNCMRxMask[Adc_IndividualGroupId].Adc_u32NCMR0;
        pCmrMask->Adc_u32NCMR1 = Adc_aNCMRxMask[Adc_IndividualGroupId].Adc_u32NCMR1;
        pCmrMask->Adc_u32NCMR2 = Adc_aNCMRxMask[Adc_IndividualGroupId].Adc_u32NCMR2; 
    }
    else
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        for(Ch = 0U; Ch < Adc_aRuntimeGroupChannel[Group].ChannelCount; Ch++)
        {
            /** @violates @ref Adc_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            ChId = Adc_pCfgPtr->pChannels[Unit][Adc_aRuntimeGroupChannel[Group].pChannel[Ch]].ChId;
            if(ChId < ADC_ST_EXTENDED_CH_U8)
            {
                pCmrMask->Adc_u32NCMR0 |= (uint32)(1UL << (uint32)ChId);
            }
            #if ((ADC_NCMR1_AVAILABLE == STD_ON) || (ADC_JCMR1_AVAILABLE == STD_ON))
            else if ((ChId >= ADC_ST_EXTENDED_CH_U8) && (ChId <= ADC_ED_EXTENDED_CH_U8))
            {
                pCmrMask->Adc_u32NCMR1 |= (uint32)(1UL << ((uint32)ChId - ADC_ST_EXTENDED_CH_U8));
            }
            #endif
            #if ((ADC_NCMR2_AVAILABLE == STD_ON) || (ADC_JCMR2_AVAILABLE == STD_ON))
            else if ((ChId >= ADC_ST_EXTERNAL_CH_U8) && (ChId <= ADC_ED_EXTERNAL_CH_U8))
            {
                pCmrMask->Adc_u32NCMR2 |= (uint32)(1UL << ((uint32)ChId - ADC_ST_EXTERNAL_CH_U8));
            }
            #endif
            else
            {
                /* do nothing to avoid misra */
            }
        }
#else
        /* Program the mask registers */
        pCmrMask->Adc_u32NCMR0 = pGroupPtr->u32PrecisionChannel;
        #if ((ADC_NCMR1_AVAILABLE == STD_ON) || (ADC_JCMR1_AVAILABLE == STD_ON))
        pCmrMask->Adc_u32NCMR1 = pGroupPtr->u32ExtendedChannel;
        #endif /* ((ADC_NCMR1_AVAILABLE == STD_ON) || (ADC_JCMR1_AVAILABLE == STD_ON)) */
        #if ((ADC_NCMR2_AVAILABLE == STD_ON) || (ADC_JCMR2_AVAILABLE == STD_ON))
        pCmrMask->Adc_u32NCMR2 = pGroupPtr->u32ExternalChannel;
        #endif /* ((ADC_NCMR2_AVAILABLE == STD_ON) || (ADC_JCMR2_AVAILABLE == STD_ON)) */
#endif
    }
}
#endif /* ADC_CMR_REGISTER_NOT_SUPPORTED */

#ifdef ERR_IPV_ADC12B_LBA_0001
#ifdef ADC_WORK_AROUND_ERRATA_E8188
#if (ADC_WORK_AROUND_ERRATA_E8188 == STD_ON)
/**
* @violates @ref Adc_c_REF_3 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_StopCurrentWorkAround(void)
{
    Adc_Ipw_StopCurrentWorkAround();
}
#endif
#endif
#endif

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_c_REF_6 Repeated include file MemMap.h*/
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
