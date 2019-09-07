/**
*   @file    Adc_Types.h
*   @version 1.0.1
*   
*   @brief   AUTOSAR Adc - driver API and development errors definition.
*   @details This file contains the ADC Autosar driver API and development errors definition.
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
*   Autosar Version      : 4.2.
*                          2
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

#ifndef ADC_TYPES_H
#define ADC_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Types_h_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance 
* and case sensitivity are supported for external identifiers.
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
/**
* @file           Adc_Types.h
*/
#include "Std_Types.h"
#include "Adc_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Types.h
*/
#define ADC_VENDOR_ID_TYPES                         43
#define ADC_AR_RELEASE_MAJOR_VERSION_TYPES          4
#define ADC_AR_RELEASE_MINOR_VERSION_TYPES          2
/** @violates @ref Adc_Types_h_REF_3 MISRA-C:2004 Rule 1.4: 31 character significance */
#define ADC_AR_RELEASE_REVISION_VERSION_TYPES       2
#define ADC_SW_MAJOR_VERSION_TYPES                  1
#define ADC_SW_MINOR_VERSION_TYPES                  0
#define ADC_SW_PATCH_VERSION_TYPES                  1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/** @violates @ref Adc_Types_h_REF_3 MISRA-C:2004 Rule 1.4: 31 character significance */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Adc_Types.h file and Std_Types header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_TYPES != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_TYPES != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_Types.h and Std_Types.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID_TYPES != ADC_VENDOR_ID_CFG_DEFINES)
#error "Adc_Types.h and Adc_CfgDefines.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_TYPES != ADC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_TYPES != ADC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_TYPES != ADC_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
#error "AutoSar Version Numbers of Adc_Types.h and Adc_CfgDefines.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_TYPES != ADC_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (ADC_SW_MINOR_VERSION_TYPES != ADC_SW_MINOR_VERSION_CFG_DEFINES) || \
     (ADC_SW_PATCH_VERSION_TYPES != ADC_SW_PATCH_VERSION_CFG_DEFINES) \
    )
#error "Software Version Numbers of Adc_Types.h and Adc_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Threshold register Id
*/
#define ADC_THRESHOLD_REG_0_U8           ((uint8)0x0)
#define ADC_THRESHOLD_REG_1_U8           ((uint8)0x1)
#define ADC_THRESHOLD_REG_2_U8           ((uint8)0x2)
#define ADC_THRESHOLD_REG_3_U8           ((uint8)0x3)
#define ADC_THRESHOLD_REG_4_U8           ((uint8)0x4)
#define ADC_THRESHOLD_REG_5_U8           ((uint8)0x5)
#define ADC_THRESHOLD_REG_6_U8           ((uint8)0x6)
#define ADC_THRESHOLD_REG_7_U8           ((uint8)0x7)
#define ADC_THRESHOLD_REG_8_U8           ((uint8)0x8)
#define ADC_THRESHOLD_REG_9_U8           ((uint8)0x9)
#define ADC_THRESHOLD_REG_10_U8          ((uint8)0xA)
#define ADC_THRESHOLD_REG_11_U8          ((uint8)0xB)
#define ADC_THRESHOLD_REG_12_U8          ((uint8)0xC)
#define ADC_THRESHOLD_REG_13_U8          ((uint8)0xD)
#define ADC_THRESHOLD_REG_14_U8          ((uint8)0xE)
#define ADC_THRESHOLD_REG_15_U8          ((uint8)0xF)
#define ADC_UNUSED_THRESHOLD_U8          ((uint8)0xFF)

/**
* @brief          Maximum Precision channel range from 0 to 32
*/
#define ADC_ST_PRICISION_CH_U8           (0U)
#define ADC_ED_PRICISION_CH_U8           (31U)

/**
* @brief          Maximum medium accuracy Extended channel range from 32 to 63
*/
#define ADC_ST_EXTENDED_CH_U8            (32U)
#define ADC_ED_EXTENDED_CH_U8            (63U)

/**
* @brief          Maximum external channel range from 64 to 95
*/
#define ADC_ST_EXTERNAL_CH_U8            (64U)
#define ADC_ED_EXTERNAL_CH_U8            (95U)

/**
 * @brief    Maximum Test channel range (TST_CH_96 to TST_CH_127)
 */
#define ADC_ST_TST_CH_U8                 (96U)
#define ADC_ED_TST_CH_U8                 (127U)

/**
 * @brief    Maximum External channel range (EXT_CH_128 to EXT_CH_255)
 */
#define ADC_ST_EXT_CH_U8                 (128U)
#define ADC_ED_EXT_CH_U8                 (255U)

/**
* @brief          ADC Resolutions.
*/
#define ADC_BITS_RESOLUTION_8_U8                   (8U)
#define ADC_BITS_RESOLUTION_10_U8                  (10U)
#define ADC_BITS_RESOLUTION_12_U8                  (12U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          ADC driver status
* @details        Used to differentiate if ADC driver is already uninit, during init or already 
*                 initialized or not.
*
*/
typedef enum
{
    ADC_STATE_UNINIT = 0U,
    ADC_STATE_BUSY,
    ADC_STATE_IDLE
} Adc_GlobalStateType;

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          Group Access Mode type.
* @details        Used for value received by Tressos interface configuration.
*/
typedef enum
{
    ADC_NORMAL = 0U, /**< @brief Normal mode */
    ADC_ALTERNATE    /**< @brief Alternate mode */
} Adc_DualClockModeType;
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

/**
* @brief          ADC group already converted type.
* @details        Used to differentiate if group is already converted or not.
*
*/
typedef enum
{
    ADC_NOT_YET_CONVERTED = 0U, /**< @brief Group not yet converted */
    ADC_ALREADY_CONVERTED       /**< @brief Group is already converted */
} Adc_GroupConversionStateType;

/**
* @brief          Adc group access Mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_GroupAccessModeType_enumeration
*/
typedef enum
{
    ADC_ACCESS_MODE_SINGLE = 0U, /**< @brief Single access mode */
    ADC_ACCESS_MODE_STREAMING    /**< @brief Streaming access mode */
} Adc_GroupAccessModeType;

/**
* @brief          Adc group conversion.
* @details        Used for value received by Tressos interface configuration.
*
*/
typedef enum
{
    ADC_CONV_TYPE_NORMAL = 0U, /**< @brief Normal conversion mode */
    ADC_CONV_TYPE_INJECTED     /**< @brief Injected conversion mode */
} Adc_GroupConvType;

/**
* @brief          Adc Group conversion mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_GroupConvModeType_enumeration
*/
typedef enum
{
    ADC_CONV_MODE_ONESHOT = 0U, /**< @brief One shot*/
    ADC_CONV_MODE_CONTINUOUS    /**< @brief Continuous conversion mode */
} Adc_GroupConvModeType;

/**
* @brief          Adc group replacement.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_GroupReplacementType_enumeration
*/
typedef enum
{
    ADC_GROUP_REPL_ABORT_RESTART, /**< @brief Abort and restart of group*/
    ADC_GROUP_REPL_SUSPEND_RESUME /**< @brief Suspend and resuming of group*/
}Adc_GroupReplacementType;

/**
* @brief          Adc group streaming buffer mode.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_StreamBufferModeType_enumeration
*/
typedef enum
{
    ADC_STREAM_BUFFER_LINEAR = 0U, /**< @brief Linear streaming*/
    ADC_STREAM_BUFFER_CIRCULAR     /**< @brief Circular streaming*/
} Adc_StreamBufferModeType;

/**
* @brief          ADC group status.
* @details        ADC group enumeration type.
*
* @implements     Adc_StatusType_enumeration
*/
typedef enum
{
    ADC_IDLE = 0U,       /**< @brief Group is in IDLE state*/
    ADC_BUSY,            /**< @brief Group is in BUSY state */
    ADC_COMPLETED,       /**< @brief Group is in COMPLETED state*/
    ADC_STREAM_COMPLETED /**< @brief Group is in STREAM_COMPLETED state*/
} Adc_StatusType;

/**
* @brief          ADC group notification.
* @details        Indicates if notification is enabled for the group.
*
*/
typedef enum
{
    ADC_NOTIFICATION_DISABLED = 0U, /**< @brief Notification is disabled */
    ADC_NOTIFICATION_ENABLED        /**< @brief Notification is enabled */
} Adc_NotificationType;

/**
* @brief          Adc hardware trigger edge.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_HwTriggerSignalType_enumeration
*/
typedef enum
{
    ADC_HW_TRIG_RISING_EDGE = 0U, /**< @brief Rising edge */
    ADC_HW_TRIG_FALLING_EDGE,     /**< @brief Falling edge */
    ADC_HW_TRIG_BOTH_EDGES        /**< @brief falling and rising edge */
} Adc_HwTriggerSignalType;

/**
* @brief          Adc hardware trigger source.
* @details        Used for value received by Tressos interface configuration.
*
* @implements     Adc_TriggerSourceType_enumeration
*/
typedef enum
{
    ADC_TRIGG_SRC_SW = 0U /**< @brief Software triggered */
#if (ADC_HW_TRIGGER_API == STD_ON)
,
    ADC_TRIGG_SRC_HW      /**< @brief Hardware triggered */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
} Adc_TriggerSourceType;

#if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__)
/**
* @brief          Adc Hardware trigger.
* @details        Indicates if hardware trigger is enabled for group.
*
*/
typedef enum
{
    ADC_HWTRIGGER_DISABLED = 0U, /**< @brief Hardware trigger is disabled */
    ADC_HWTRIGGER_ENABLED        /**< @brief Hardware trigger is enabled */
} Adc_HwTriggeringType;

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Adc MHT group.
* @details        Indicates if the hardware triggered group is regular or MHT type.
*
*/
typedef enum
{
    ADC_REGULAR_GROUP_TYPE = 0U, /**< @brief Indicate that the group is part-of a regular groups */
    ADC_MHT_GROUP_TYPE           /**< @brief Indicate that the group is part-of the MHT groups subset */
} Adc_MhtGroupType;
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__) */
#endif /* (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__) */

#if (ADC_SET_MODE_API==STD_ON)
/**
* @brief          Set mode values.
* @details        Indicates all the values to set the Adc mode.
*
*/
typedef enum
{
    ADC_NORMAL_MODE = 0U, /**< @brief Normal mode */
    ADC_POWER_DOWN_MODE   /**< @brief Power down mode */
} Adc_SetModeType;
#endif /* (ADC_SET_MODE_API==STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Range select values.
* @details        Indicates which range select is used.
*
* @implements  Adc_ChannelRangeSelectType_enumeration
*/
typedef enum
{
    ADC_RANGE_ALWAYS = 0U,   /**< @brief Complete range - independent from channel limit settings */
    ADC_RANGE_BETWEEN,       /**< @brief Range between low limit and high limit - high limit value included */
    ADC_RANGE_NOT_BETWEEN,   /**< @brief Range above high limit or below low limit - low limit value included */
    ADC_RANGE_NOT_OVER_HIGH, /**< @brief Range below high limit - high limit value included */
    ADC_RANGE_NOT_UNDER_LOW, /**< @brief Range above low limit */
    ADC_RANGE_OVER_HIGH,     /**< @brief Range above high limit */
    ADC_RANGE_UNDER_LOW      /**< @briefRange below low limit - low limit value included */
} Adc_ChannelRangeSelectType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
/**
* @brief      Power state type
* @details    Power state currently active or set as target power state.
* 
* @implements     Adc_PowerStateType_enumeration
*/
typedef enum
{
    ADC_FULL_POWER = 0U,    /**< @brief Adc full power mode. */
    ADC_LOW_POWER,          /**< @brief Adc low power mode. */
    ADC_NODEFINE_POWER      /**< @brief Adc no define power mode. */
} Adc_PowerStateType;

/**
* @brief      Result of power state type
* @details    Result of the requests related to power state transitions.
* 
* @implements     Adc_PowerStateRequestResultType_enumeration
*/
typedef enum
{
    
    ADC_SERVICE_ACCEPTED = 0U,  /**< @brief Power state change executed. */
    ADC_NOT_INIT,               /**< @brief Module not initialized. */
    ADC_SEQUENCE_ERROR,         /**< @brief Wrong API call sequence. */
    ADC_HW_FAILURE,             /**< @brief The HW module has a failure which prevents it to enter the required power state. */
    ADC_POWER_STATE_NOT_SUPP,   /**< @brief Module does not support the requested power state. */
    ADC_TRANS_NOT_POSSIBLE      /**< @brief Module cannot transition directly from the current power state to the requested power state. */
} Adc_PowerStateRequestResultType;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef void (*Adc_NotifyType)(void);     /**< @brief Notification function pointer definition */
typedef void (*Adc_WdgNotifyType)(void);  /**< @brief Notification function pointer definition - WDG */
typedef uint16 Adc_ChannelIndexType;      /**< @brief Number of channels */
typedef uint8 Adc_HwUnitType;             /**< @brief Numeric ID of an ADC Hw Unit */
typedef uint8 Adc_ClockSourceType;        /**< @brief clock source for ADC */
typedef uint16 Adc_VoltageSourceType;     /**< @brief reference voltage source */
typedef uint16 Adc_QueueIndexType;        /**< @brief Index for the queue of groups */
/** @implements     Adc_ChannelType_uint */
typedef uint8 Adc_ChannelType;            /**< @brief Numeric ID of an ADC channel */
/** @implements     Adc_GroupType_uint */
typedef uint16 Adc_GroupType;             /**< @brief Numeric ID of an ADC channel group. No uC dependent */
/** @implements     Adc_ResolutionType_uint */
typedef uint8 Adc_ResolutionType;         /**< @brief channel resolution in number of bits */
/** @implements     Adc_GroupPriorityType_uint */
typedef uint8 Adc_GroupPriorityType;      /**< @brief ADC Channel group priority */
/** @implements     Adc_GroupDefType_uint */
typedef Adc_ChannelType Adc_GroupDefType; /**< @brief definition of channels in a group */
/** @implements     Adc_ValueGroupType_int */
typedef uint16 Adc_ValueGroupType;        /**< @brief type for ADC result of one channel */
/** @implements     Adc_PrescaleType_uint */
typedef uint8 Adc_PrescaleType;           /**< @brief clock prescaler factor */
/** @implements     Adc_ConversionTimeType_uint */
typedef uint16 Adc_ConversionTimeType;    /**< @brief conversion time */
/** @implements     Adc_SamplingTimeType_uint */
typedef uint8 Adc_SamplingTimeType;       /**< @brief sampling time */
/** @implements     Adc_StreamNumSampleType_uint */
typedef uint16 Adc_StreamNumSampleType;   /**< @brief Number of samples of a streaming conversion buffer */
/** @implements     Adc_HwTriggerTimerType_uint */
typedef uint16 Adc_HwTriggerTimerType;    /**< @brief Type for the reload value of the ADC embedded timer */

/**
* @brief          Structure for validation results
* @details        This structure contains the validation information
*
*/
typedef struct 
{
    VAR(boolean, AUTOMATIC) bEndValidations; /**< @brief Signal if validation ended */
    VAR(Std_ReturnType, AUTOMATIC) ValidParams; /**< @brief Return status */
} Adc_ValidationResultType; 

/**
* @brief          Structure for group status.
* @details        This structure contains the group status information.
*
*/
typedef struct
{
    volatile VAR(Adc_StatusType, AUTOMATIC) eConversion;   /**< @brief Group status */
    volatile VAR(Adc_GroupConversionStateType, AUTOMATIC) eAlreadyConverted;     /**< @brief Group was previously converted or not */
#if (ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_HwTriggeringType, AUTOMATIC) eHwTriggering;   /**< @brief hw trigger enabled/disabled */
  #if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
    VAR(Adc_HwTriggeringType, AUTOMATIC) eCtuTriggering;  /**< @brief CTU trigger enabled/disabled */
  #endif  /* ADC_ENABLE_CTUTRIG_API == STD_ON */  
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(Adc_NotificationType, AUTOMATIC) eNotification;   /**< @brief notification enabled/disabled */
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
    volatile VAR(Adc_StreamNumSampleType, AUTOMATIC) ResultIndex;  /**< @brief index into streaming buffer that is currently being filled */
#ifdef ADC_CURRENT_CHANNEL_USED
    VAR(Adc_ChannelIndexType, AUTOMATIC) CurrentChannel;  /**< @brief Current channel in use */
#endif /* ADC_CURRENT_CHANNEL_USED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    volatile VAR(boolean, AUTOMATIC) bLimitCheckFailed;   /**< @brief check limit check fail */
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
} Adc_GroupStatusType;

/**
* @brief          Structure for hardware unit status.
* @details        This structure contains the HW unit status information.
*
*/
typedef struct
{
    /** @brief Filled slots in the queue */
    volatile VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex; 
    /** @brief Queued groups indexes, always executing Queue[0] */
    volatile VAR(Adc_GroupType, AUTOMATIC) SwNormalQueue[ADC_QUEUE_MAX_DEPTH_MAX]; 
#if (ADC_HW_TRIGGER_API == STD_ON)
    /** @brief The depth of the hardware injected queue */
    volatile VAR(Adc_GroupType, AUTOMATIC) HwInjectedQueue[ADC_HW_QUEUE]; 
    /** @brief Filled slots in the Hw injected queue */
    volatile VAR(Adc_QueueIndexType, AUTOMATIC) HwInjectedQueueIndex;
    /** @brief The depth of the hardware normal queue */
    volatile VAR(Adc_GroupType, AUTOMATIC) HwNormalQueue[ADC_HW_QUEUE]; 
    /** @brief Filled slots in the Hw normal queue */
    volatile VAR(Adc_QueueIndexType, AUTOMATIC) HwNormalQueueIndex;
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    /** @brief When != 0 indicate MHT groups in queue, else regular */
    VAR(Adc_MhtGroupType, AUTOMATIC) eHwQueueGroupType; 
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
    /** @brief The depth of the software injected queue */
    volatile VAR(Adc_GroupType, AUTOMATIC) SwInjectedQueue[1]; 
    /** @brief Filled slots in the Sw injected queue */
    volatile VAR(Adc_QueueIndexType, AUTOMATIC) SwInjectedQueueIndex; 
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
    /** @brief Indicates Ctu control mode is ongoing */
    VAR(boolean, AUTOMATIC) bCtuControlOngoing; 
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */
#if (defined(ADC_DMA_SUPPORTED) && defined(ADC_DMA_SCATTER_GATHER_USED))
    /** @brief Indicates the number of channel segments of group */
    VAR(Adc_ChannelIndexType, AUTOMATIC) NumSegment;
#endif /* defined(ADC_DMA_SUPPORTED) && defined(ADC_DMA_SCATTER_GATHER_USED) */
#ifdef ADC_PDB_SUPPORTED
    VAR(uint8, AUTOMATIC) u8Sc1Used;
#endif /* ADC_PDB_SUPPORTED */
} Adc_UnitStatusType;

/**
* @brief          NCMR structure type
* @details        This structure is used to enable/disable SW (not injected) trigger groups
*
*/
typedef struct
{
    VAR(uint32, AUTOMATIC) Adc_u32NCMR0; /**< @brief Precision configured channels */
    VAR(uint32, AUTOMATIC) Adc_u32NCMR1; /**< @brief Extended configured channels */
    VAR(uint32, AUTOMATIC) Adc_u32NCMR2; /**< @brief External configured channels */
} Adc_NcmrType;

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief          Structure for calibration status
*/
typedef struct
{
    /** @brief Unit calibration result status */
    VAR(Std_ReturnType, AUTOMATIC) Adc_UnitSelfTestStatus;
#if (defined (ADC_BIST1_AVAILABLE) || defined (ADC_CALSTAT_AVAILABLE))
    /** @brief List of failed tests */
    VAR(uint8, AUTOMATIC) Adc_Calibrate_Failed_Steps[ADCDIG_MAX_CALIBRATION_STEPS];
#endif
} Adc_CalibrationStatusType;
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_SETCHANNEL_API == STD_ON)
typedef struct
{
    /** @brief Run time assigned channels to group */
    P2CONST(Adc_GroupDefType, ADC_VAR, ADC_APPL_CONST) pChannel;
    /** @brief Run time assigned delay of channels group */
    P2CONST(uint16, AUTOMATIC, ADC_APPL_CONST) pu16Delays;
    /** @brief Mask per channel - to be updated or not */
    VAR(uint32, AUTOMATIC) u32Mask;
    /** @brief Run time number of channels */
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    /** @brief Indicates whether the configuration has been updated or not*/
    VAR(boolean, AUTOMATIC) bRuntimeUpdated;
} Adc_RuntimeGroupChannelType;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__)
typedef struct
{    
    CONST(Adc_ChannelRangeSelectType, ADC_CONST) eChannelRange; /**< @brief  Range conversion */
    CONST(Adc_ValueGroupType, ADC_CONST) ChannelHighLimit; /**< @brief High limit channel conversion value */
    CONST(Adc_ValueGroupType, ADC_CONST) ChannelLowLimit; /**< @brief Low limit channel conversion value */
} Adc_ChannelLimitCheckingType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__) */
/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* ADC_TYPES_H */

/** @} */
