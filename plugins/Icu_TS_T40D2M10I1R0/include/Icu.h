/**
*     @file            Icu.h
*     @implements      Icu.h_Artifact
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - ICU driver header file.
*     @details ICU driver header file, containing the Autosar API specification and other variables
*              and functions that are exported by the ICU driver.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : FTM PORT_CI LPIT LPTMR
*     Dependencies        : none
*
*     Autosar Version     :  4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_H
#define ICU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_h_REF_1
*       Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*       contents of a header file being included twice
*       This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_h_REF_2
*       Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*       character significance and case sensitivity are supported for external identifiers.
*       This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section [global]
*       Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*       on the significance of more than 31 characters. The used compilers use more than 31 chars
*       for identifiers.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Icu_Cfg.h"
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
#include "EcuM_Cbk.h"
#endif  /* ICU_REPORT_WAKEUP_SOURCE */

#include "Icu_Ipw_Types.h"
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
#include "CDD_Mcl.h"
#endif
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID                       43
#define ICU_MODULE_ID                       122
#define ICU_AR_RELEASE_MAJOR_VERSION        4
#define ICU_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Icu_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_AR_RELEASE_REVISION_VERSION     2
#define ICU_SW_MAJOR_VERSION                1
#define ICU_SW_MINOR_VERSION                0
#define ICU_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU configuration header file are of the same vendor */
#if (ICU_VENDOR_ID != ICU_VENDOR_ID_CFG)
    #error "Icu.h and ICU_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and ICU configuration header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Icu.h and ICU_Cfg.h are different"
#endif
/* Check if header file and ICU configuration header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_SW_MINOR_VERSION != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_SW_PATCH_VERSION != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu.h and ICU_Cfg.h are different"
#endif

#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if header file and EcuM_Cbk.h file are of the same Autosar version */
        #if ((ICU_AR_RELEASE_MAJOR_VERSION != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_AR_RELEASE_MINOR_VERSION != ECUM_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu.h and EcuM_Cbk.h are different"
        #endif
    #endif
#endif  /* ICU_REPORT_WAKEUP_SOURCE */

/* Check if source file and ICU types header file are of the same vendor */
#if (ICU_VENDOR_ID != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu.h and Icu_Ipw_Types.h have different vendor IDs"
#endif
    /* Check if header file and ICU types header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu.h and Icu_Ipw_Types.h are different"
#endif
/* Check if header file and ICU types header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.h and Icu_Ipw_Types.h are different"
#endif

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
/* Check if source file and CDD_Mcl header file are of the same vendor */
#if (ICU_VENDOR_ID != MCL_VENDOR_ID)
    #error "Icu.h and CDD_Mcl.h have different vendor IDs"
#endif
    /* Check if header file and CDD_Mcl header file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.h and CDD_Mcl.h are different"
#endif
/* Check if header file and CDD_Mcl header file are of the same software version */
#if ((ICU_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu.h and CDD_Mcl.h are different"
#endif
#endif  /* ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON)) */
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/**
* @brief   API Icu_Init service called with wrong parameter
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_INIT_FAILED               ((uint8)0x0D)

/**
* @brief   API service used with an invalid channel identifier or channel was not configured for
*          the functionality of the calling API
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_CHANNEL             ((uint8)0x0B)

/**
* @brief   API service used with an invalid or not feasible activation
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_ACTIVATION          ((uint8)0x0C)

/**
* @brief   API service used with an invalid application-buffer pointer
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_POINTER             ((uint8)0x0A)

/**
* @brief   API service used with an invalid buffer size
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_BUFFER_SIZE         ((uint8)0x0E)

/**
* @brief   API service Icu_SetMode used with an invalid mode
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_MODE                ((uint8)0x0F)

/**
* @brief   API service used without module initialization
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_UNINIT                    ((uint8)0x14)

/**
* @brief   API service Icu_StopTimestamp called on a channel which was not
*          started or already stopped
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_NOT_STARTED               ((uint8)0x15)

/**
* @brief   API service Icu_SetMode is called while a running operation
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_BUSY_OPERATION            ((uint8)0x16)

/**
* @brief   API Icu_Init service called when the ICU driver and the Hardware
*          are already initialized
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_ALREADY_INITIALIZED       ((uint8)0x17)

/**
* @brief   API Icu_StartTimeStamp is called and the parameter NotifyInterval is invalid (e.g. 0,
*           NotifyInterval < 1)
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_NOTIFY_INTERVAL     ((uint8)0x18)

/**
* @brief   API Icu_GetVersionInfo is called and the parameter versioninfo is is invalid
*          ( e.g. NULL )
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_PARAM_VINFO               ((uint8)0x19)

/**
* @brief    API Icu_SetClockMode service called with wrong parameter
* @implements Icu_ErrorCodes_define
*/
#define ICU_E_PARAM_CLOCK_MODE          ((uint8)0x7AU)

/**
* @brief   API Icu_GetEdgeNumbers service called when the Counter rolls over
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_EDGECOUNTING_OVERFLOW     ((uint8)0xD0)

/**
* @brief   API Icu_GetTimestampIndex service called when the Time stamp count overflows
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_TIMESTAMP_OVERFLOW        ((uint8)0xD1)

/**
* @brief   API Icu_GetTimeElapsed service called when the Time elapsed overflows
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_MEASUREMENT_OVERFLOW      ((uint8)0xD2)

/**
* @brief   API Icu_EnableWakeup and Icu_DisableWakeup services called in ICU_SLEEP_MODE
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_INVALID_MODE              ((uint8)0xD3)

/**
* @brief   API Check mode before set up feature for channel 
* @implements Icu_ErrorCodes_define
* */
#define ICU_E_FORBIDEN_MODE             ((uint8)0xD4)

/**
* @brief API service ID for Icu_Init function
* @details Parameters used when raising an error/exception
* */
#define ICU_INIT_ID                     ((uint8)0x00)
/**
* @brief API service ID for Icu_DeInit function
* @details Parameters used when raising an error/exception
* */
#define ICU_DEINIT_ID                   ((uint8)0x01)

/**
* @brief API service ID for Icu_SetMode function
* @details Parameters used when raising an error/exception
* */
#define ICU_SETMODE_ID                  ((uint8)0x02)

/**
* @brief API service ID for Icu_DisableWakeup function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLEWAKEUP_ID            ((uint8)0x03)

/**
* @brief API service ID for Icu_EnableWakeup function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLEWAKEUP_ID             ((uint8)0x04)

/**
* @brief API service ID for Icu_SetActivationCondition function
* @details Parameters used when raising an error/exception
* */
#define ICU_SETACTIVATIONCONDITION_ID   ((uint8)0x05)

/**
* @brief API service ID for Icu_DisableNotification function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLENOTIFICATION_ID      ((uint8)0x06)

/**
* @brief API service ID for Icu_EnableNotification function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLENOTIFICATION_ID       ((uint8)0x07)

/**
* @brief API service ID for Icu_GetInputState function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETINPUTSTATE_ID            ((uint8)0x08)

/**
* @brief API service ID for Icu_StartTimestamp function
* @details Parameters used when raising an error/exception
* */
#define ICU_STARTTIMESTAMP_ID           ((uint8)0x09)

/**
* @brief API service ID for Icu_StopTimestamp function
* @details Parameters used when raising an error/exception
* */
#define ICU_STOPTIMESTAMP_ID            ((uint8)0x0A)

/**
* @brief API service ID for Icu_GetTimestampIndex function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETTIMESTAMPINDEX_ID        ((uint8)0x0B)

/**
* @brief API service ID for Icu_ResetEdgeCount function
* @details Parameters used when raising an error/exception
* */
#define ICU_RESETEDGECOUNT_ID           ((uint8)0x0C)

/**
* @brief API service ID for Icu_EnableEdgeCount function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLEEDGECOUNT_ID          ((uint8)0x0D)

/**
* @brief API service ID for Icu_DisableEdgeCount function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLEEDGECOUNT_ID         ((uint8)0x0E)

/**
* @brief API service ID for Icu_GetEdgeNumbers function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETEDGENUMBERS_ID           ((uint8)0x0F)

/**
* @brief API service ID for Icu_GetTimeElapsed function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETTIMEELAPSED_ID           ((uint8)0x10)

/**
* @brief API service ID for Icu_GetDutyCycleValues function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETDUTYCYCLEVALUES_ID       ((uint8)0x11)

/**
* @brief API service ID for Icu_GetVersionInfo function
* @details Parameters used when raising an error/exception
* */
#define ICU_GETVERSIONINFO_ID           ((uint8)0x12)

/**
* @brief API service ID for Icu_StartSignalMeasurement function
* @details Parameters used when raising an error/exception
* */
#define ICU_STARTSIGNALMEASUREMENT_ID   ((uint8)0x13)

/**
* @brief API service ID for Icu_StopSignalMeasurement function
* @details Parameters used when raising an error/exception
* */
#define ICU_STOPSIGNALMEASUREMENT_ID    ((uint8)0x14)

/**
* @brief API service ID for Icu_CheckWakeup function
* @details Parameters used when raising an error/exception
* */
#define ICU_CHECKWAKEUP_ID              ((uint8)0x15)
/**
* @brief API service ID for Icu_EnableEdgeDetection function
* @details Parameters used when raising an error/exception
* */
#define ICU_ENABLEEDGEDETECTION_ID      ((uint8)0x16)

/**
* @brief API service ID for Icu_DisableEdgeDetection function
* @details Parameters used when raising an error/exception
* */
#define ICU_DISABLEEDGEDETECTION_ID     ((uint8)0x17)

/**
* @brief   API service ID for Icu_SetClockMode function
* @details Parameters used when raising an error/exception
*/
#define ICU_SET_CLOCK_MODE_ID           ((uint8)0x7BU)

/**
* @brief   API service ID for Icu_GetCaptureRegisterValue function
* @details Parameters used when raising an error/exception
*/
#define ICU_GET_CAPTURE_REGISTER_VALUE_ID           ((uint8)0x19U)

/**
* @brief   API service ID for Icu_GetPulseWidth function
* @details Parameters used when raising an error/exception
*/
#define ICU_GET_PULSE_WIDTH_ID                      ((uint8)0x1AU)

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
 * @brief   API service ID for Icu_GetInputLevel function
 * @details Parameters used when raising an error/exception
 * */
 #define ICU_GET_INPUT_LEVEL_ID          ((uint8)0x7CU)

#endif /* ICU_GET_INPUT_LEVEL_API */


#ifdef ICU_CUSTOM_NOTIFICATION_API
/**
 * @brief Definition of Custom Notification Handler Enabled bitfield
 */
#define ICU_CUSTOM_NOTIFICATION_ENABLED         (BIT0)

/**
 * @brief Definition of bit mask to isolate the Custom Notification Handler Enabled bitfield
 */
#define ICU_CUSTOM_NOTIFICATION_ENABLED_MASK    ((uint32)BIT28)

/**
 * @brief  Definition of Custom Notification Handler Enabled bitfield position
 */
#define ICU_CUSTOM_NOTIFICATION_ENABLED_SHIFT   ((uint32)28U)
#endif  /* ICU_CUSTOM_NOTIFICATION_API */

/*================================================================================================*/



/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
 * @brief Definition of the type of wake up capability of an ICU channel.
 *
 * */
typedef enum
{
    ICU_WAKEUP_NOTCAPABLE = 0x0U,    /*< @brief Channel is not wakeup capable. */
    ICU_WAKEUP_CAPABLE    = 0x1U     /*< @brief TChannel is wakeup capable. */
} Icu_WakeupCapableType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/**
 * @brief    Structure that contains ICU channel configuration.
 * @details  It contains the information like Icu Channel Mode, Channel Notification function,
 *           overflow Notification function.
 * @implements Icu_ChannelConfigType_struct
 * */
typedef struct
{
    Icu_ParamType Icu_ParamValue;                        /*< @brief  Configuration parameters of
                                                         *           hardware channel registers. */
    Icu_MeasurementModeType Icu_Channel_Mode;            /*< @brief  EDGE_DETECT, TIME_STAMP,
                                                         *           SIGNAL_MEASUREMENT or
                                                         *           EDGE_COUNTER. */
    Icu_MeasurementSubModeType Icu_Channel_Property;     /*< @brief  CIRCULAR_BUFFER or
                                                         *           LINEAR_BUFFER for TIME_STAMP,
                                                         *           DUTY_CYCLE, HIGH_TIME, LOW_TIME
                                                         *           or PERIOD_TIME for
                                                         *           SIGNAL_MEASUREMENT and
                                                         *           RISING_EDGE, FALLING_EDGE or
                                                         *           BOTH_EDGES for EDGE_COUNTER. */
    Icu_NotifyType Icu_Channel_Notification;             /*< @brief  Icu Channel Notification
                                                         *           function for TIME_STAMP or
                                                         *           EDGE_COUNTER mode. */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
    CONST(Mcl_ChannelType, ICU_CONST) Mcl_DmaChannel;    /*< @brief  Mcl_DmaChannel Id*/
#endif
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        /*< @brief  Icu Channel Overflow Notification function. */    
    Icu_NotifyType Icu_Channel_OverflowNotification;   
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    Icu_WakeupValueType Icu_Channel_WakeupValue;           /*< @brief EcuM wakeup source Id. */
#endif  /* ICU_REPORT_WAKEUP_SOURCE == STD_ON */

} Icu_ChannelConfigType;

/**
 * @brief This type contains initialization data.
 * @details he notification functions shall be configurable
 *         as function pointers within the initialization data structure (Icu_ConfigType).
 *         This type of the external data structure shall contain the
 *         initialization data for the ICU driver. It shall contain:
 *         - Wakeup Module Info (in case the wakeup-capability is true)
 *         - ICU dependent properties for used HW units
 *         - Clock source with optional prescaler (if provided by HW)
 * @implements Icu_ConfigType_struct
 * */
typedef struct
{
    /*< @brief The number of configured channels. */
    CONST   (Icu_ChannelType, ICU_CONST) nNumChannels;

    /** @brief Pointer to the list of Icu configured channels */
    CONST   (Icu_ChannelConfigType, ICU_CONST)   (*Icu_ChannelConfigPtr)[];

    /** @brief Combined IP specific configuration structure */       
    CONST   (Icu_IpConfigType,      ICU_CONST)   IpConfig;       

    /** @brief Index table to translate HW channels to logical used 
    to process interrupts for notifications */
    CONST   (Icu_ChannelType,       ICU_CONST)  (*Icu_HwMap)[ICU_MAX_HW_CHANNELS];
} Icu_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef ICU_PRECOMPILE_SUPPORT
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Icu_h_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

ICU_CONF_PB

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Icu_h_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

#endif /* #ifndef ICU_PRECOMPILE_SUPPORT*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_h_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"


FUNC (void, ICU_CODE) Icu_Init(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);


#if (ICU_DE_INIT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DeInit(void);
#endif /* ICU_DE_INIT_API */


#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_SetMode(VAR(Icu_ModeType, AUTOMATIC) Mode);
#endif /* ICU_SET_MODE_API */


#if (ICU_DISABLE_WAKEUP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DisableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_DISABLE_WAKEUP_API */


#if (ICU_ENABLE_WAKEUP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_EnableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_ENABLE_WAKEUP_API */


#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && (ICU_REPORT_WAKEUP_SOURCE == STD_ON) && \
 (ICU_ENABLE_WAKEUP_API == STD_ON))
FUNC (void, ICU_CODE) Icu_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);
#endif /* ICU_WAKEUP_FUNCTIONALITY_API && ICU_REPORT_WAKEUP_SOURCE  &&  ICU_ENABLE_WAKEUP_API */


FUNC (void, ICU_CODE) Icu_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                 VAR(Icu_ActivationType, AUTOMATIC) Activation
                                                );


FUNC (void, ICU_CODE) Icu_DisableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);


FUNC (void, ICU_CODE) Icu_EnableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);


#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (Icu_InputStateType, ICU_CODE) Icu_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_GET_INPUT_STATE_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StartTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                         P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA) BufferPtr,
                                         VAR(uint16, AUTOMATIC) BufferSize,
                                         VAR(uint16, AUTOMATIC) NotifyInterval
                                        );
#endif /* ICU_TIMESTAMP_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StopTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_TIMESTAMP_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (Icu_IndexType, ICU_CODE) Icu_GetTimestampIndex(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_TIMESTAMP_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_ResetEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_EnableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DisableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (Icu_EdgeNumberType, ICU_CODE) Icu_GetEdgeNumbers(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_TIME_ELAPSED_API== STD_ON)
FUNC (Icu_ValueType, ICU_CODE) Icu_GetTimeElapsed(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_GET_TIME_ELAPSED_API */


#if (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)
FUNC (void, ICU_CODE) Icu_GetDutyCycleValues(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                             P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA)
                                             DutyCycleValues
                                            );
#endif /* ICU_GET_DUTY_CYCLE_VALUES_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StartSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_StopSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_GET_VERSION_INFO_API == STD_ON)
FUNC(void, ICU_CODE) Icu_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,ICU_APPL_DATA) versioninfo);
#endif  /* ICU_GET_VERSION_INFO_API == STD_ON */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_SetClockMode(VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler);
#endif  /* ICU_DUAL_CLOCK_MODE_API == STD_ON */


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
FUNC(Icu_LevelType, ICU_CODE) Icu_GetInputLevel(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || \
                                                                    (ICU_TIMESTAMP_API == STD_ON)))
FUNC (Icu_ValueType, ICU_CODE) Icu_GetCaptureRegisterValue(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
FUNC (void, ICU_CODE) Icu_GetPulseWidth(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_h_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_H */
/** @} */

