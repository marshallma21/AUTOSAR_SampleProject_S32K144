/**
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

#ifndef ICU_TYPES_H
#define ICU_TYPES_H

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
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_TYPES_VENDOR_ID                       43
#define ICU_TYPES_MODULE_ID                       122
#define ICU_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_TYPES_AR_RELEASE_MINOR_VERSION        2
#define ICU_TYPES_AR_RELEASE_REVISION_VERSION     2
#define ICU_TYPES_SW_MAJOR_VERSION                1
#define ICU_TYPES_SW_MINOR_VERSION                0
#define ICU_TYPES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
 /* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
 * @brief Allow enabling or disabling of all interrupts which are not required for the ECU wakeup
 * @implements Icu_ModeType_enumeration
 * */
typedef enum
{
    ICU_MODE_NORMAL = 0U,     /*< @brief Normal operation, all used interrupts are enabled
                               *          according to the notification requests. */
    ICU_MODE_SLEEP            /*< @brief Reduced power operation. In sleep mode only those
                               *          notifications are available which are configured as wakeup
                               *          capable. */
} Icu_ModeType;


/**
 * @brief          Input state of an ICU channel.
 * @implements     Icu_InputStateType_enumeration
 * */
typedef enum
{
    ICU_ACTIVE = 0U,         /*< @brief An activation edge has been detected. */
    ICU_IDLE                 /*< @brief No activation edge has been detected since the last call of
                              *          Icu_GetInputState() or Icu_Init(). */
} Icu_InputStateType;


/**
 * @brief Definition of the measurement mode type.
 * @implements Icu_MeasurementModeType_enumeration
 * */
typedef enum
{
    ICU_MODE_SIGNAL_EDGE_DETECT = 0x01U,   /*< @brief Mode for detecting edges */
    ICU_MODE_SIGNAL_MEASUREMENT = 0x02U,   /*< @brief Mode for measuring different times between
                                            *         various configurable edges */
    ICU_MODE_TIMESTAMP          = 0x04U,   /*< @brief Mode for capturing timer values on
                                            *         configurable edges */
    ICU_MODE_EDGE_COUNTER       = 0x08U    /*< @brief Mode for counting edges on configurable
                                            *         edges*/
} Icu_MeasurementModeType;


/**
 * @brief Definition of the measurement property type.
 * @implements Icu_SignalMeasurementPropertyType_enumeration
 * */
typedef enum
{
    ICU_LOW_TIME    = 0x01U,            /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Low Time. */
    ICU_HIGH_TIME   = 0x02U,            /*< @brief The channel is configured for reading the
                                         *          elapsed Signal High Time. */
    ICU_PERIOD_TIME = 0x04U,            /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Period Time. */
    ICU_DUTY_CYCLE  = 0x08U             /*< @brief The channel is configured to read values which
                                         *          are needed for calculating the duty cycle
                                         *          (coherent Active and Period Time). */
} Icu_SignalMeasurementPropertyType;


/**
 * @brief Definition of the timestamp measurement property type.
 * @implements Icu_TimestampBufferType_enumeration
 * */
typedef enum
{
    ICU_LINEAR_BUFFER = 0U,     /*< @brief The buffer will just be filled once. */
    ICU_CIRCULAR_BUFFER         /*< @brief After reaching the end of the buffer, the driver
                                 *          restarts at the beginning of the buffer. */
} Icu_TimestampBufferType;


/**
 * @brief Definition of the type of activation of an ICU channel.
 * @implements Icu_ActivationType_enumeration
 * */
typedef enum
{
    ICU_FALLING_EDGE = 0x0U,     /*< @brief An appropriate action shall be executed when a falling
                                  *          edge occurs on the ICU input signal. */
    ICU_RISING_EDGE  = 0x1U,     /*< @brief An appropriate action shall be executed when a rising
                                  *          edge occurs on the ICU input signal */
    ICU_BOTH_EDGES   = 0x2U      /*< @brief An appropriate action shall be executed when either a
                                  *         rising or falling edge occur on the ICU input signal. */
} Icu_ActivationType;



#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
 * @brief   Return the status of the pin.
 * @details Enumeration of to check the status of emios pin.
 * */
typedef enum
{
    /* Default Input PIN Status */
    ICU_LEVEL_LOW    = 0x0U,
    /* As Icu_GetInputState do not give the Actual PIN status user can call the Non Autosar API
        Icu_GetInputLevel to get the Actual status of PIN*/
    ICU_LEVEL_HIGH = 0x1U
} Icu_LevelType;

#endif /* ICU_GET_INPUT_LEVEL_API */


#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/**
 * @brief   Definition of prescaler type.
 *
*/
typedef enum
{
    ICU_NORMAL_CLOCK_MODE    = 0x0U,           /*< @brief Default channel prescaler. */
    ICU_ALTERNATE_CLOCK_MODE                   /*< @brief Alternate channel prescaler mode */
} Icu_SelectPrescalerType;

#endif /* ICU_DUAL_CLOCK_MODE_API */
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief          This gives the numeric ID (hardware channel number) of an ICU channel
 * @implements     Icu_ChannelType_typedef
 * */
typedef uint16                          Icu_ChannelType;


/**
 * @brief          The Icu_ParamType contains combined bit fields for initialization options, for
 *                 different registers.
 *
 * */
typedef uint32                          Icu_ParamType;

/**
 * @brief          Type for saving the timer register width value
 * @implements     Icu_ValueType_typedef
 * */
typedef Icu_TimerRegisterWidthType      Icu_ValueType;

/**
 * @brief          Type for saving the ICU Hardware specific index
 * @implements     Icu_IndexType_typedef
 * */
typedef Icu_HwSpecificIndexType         Icu_IndexType;

/**
 * @brief          Type for saving hardware specific edge number
 * @implements     Icu_EdgeNumberType_typedef
 * */
typedef Icu_HwSpecificEdgeNumberType    Icu_EdgeNumberType;


/**
 * @brief          Type for saving the Wakeup value
 *
 * */
typedef uint32                          Icu_WakeupValueType;

/**
 * @brief          Type for saving the ICU measurement submode type
 *
 * */
typedef uint16                           Icu_MeasurementSubModeType;

/**
 * @brief          Type for saving the ICU global configuration type
 *
 * */
typedef uint32                           Icu_GlobalConfigType;

/**
 * @brief          The notification functions shall have no parameters and no return value.
 * @implements     Icu_NotifyType_typedef
 * */
typedef void (*Icu_NotifyType)(void);

/**
 * @brief Structure that contains ICU Duty cycle parameters. It contains the values needed for
 *        calculating duty cycles i.e Period time value and active time value.
 * @implements Icu_DutyCycleType_struct
 * */
typedef struct
{
    Icu_ValueType ActiveTime;          /*< @brief Low or High time value. */
    Icu_ValueType PeriodTime;         /*< @brief Period time value. */
} Icu_DutyCycleType;


/**
 * @brief Structure that contains ICU DMA Configuration.
* */

typedef struct
{
    uint8 u8ChGenericInformation;
    Icu_TimerRegisterWidthType DmaReqValue;
} Icu_DmaReqConfigType;

/**
 * @brief Structure that contains ICU DMA configuration parameters. 
* */
typedef struct
{
    CONST(uint8, ICU_CONST) u8NoDmaChConfigured;                 /*< @brief number of Dma Requests 
                                                                   configured for Icu*/
    CONST(Icu_DmaReqConfigType, ICU_CONST) (*DmaReqConfig)[]; /*< @brief Array of Dma Requests
                                                                   configuration for Icu*/
} Icu_DmaConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/



/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* ICU_TYPES_H */
/** @} */

