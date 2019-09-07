/**
*    @file    Icu_Ftm.h
*    @version 1.0.1
*
*    @brief   AUTOSAR Icu - Ftm header file support for ICU driver.
*    @details Ftm header file, containing the variables and functions that are exported by the IP driver.
*
*    @addtogroup ICU_MODULE
*    @{
*/
/*==================================================================================================
*    Project               : AUTOSAR 4.2 MCAL
*    Platform              : ARM
*    Peripheral            : FTM PORT_CI LPIT LPTMR
*    Dependencies          : none
*
*    Autosar Version       : 4.2.2
*    Autosar Revision      : ASR_REL_4_2_REV_0002
*    Autosar Conf.Variant  :
*    SWVersion             : 1.0.1
*    BuildVersion          : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*    All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_FTM_H
#define ICU_FTM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section ICU_FTM_H_REF_1
*       Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*       contents of a header file being included twice
*       This is not a violation since all header files are protected against multiple inclusions
* @section [global]
*       Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*       on the significance of more than 31 characters. The used compilers use more than 31 chars
*       for identifiers.
* @section ICU_FTM_H_REF_2
*       Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*       character significance and case sensitivity are supported for external identifiers.
*       This is not a violation since all the compilers used interpret the identifiers correctly
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Ftm_Types.h"
#include "Icu_Types.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/* */
#define ICU_FTM_VENDOR_ID                       43
#define ICU_FTM_AR_RELEASE_MAJOR_VERSION        4
#define ICU_FTM_AR_RELEASE_MINOR_VERSION        2
#define ICU_FTM_AR_RELEASE_REVISION_VERSION     2
#define ICU_FTM_SW_MAJOR_VERSION                1
#define ICU_FTM_SW_MINOR_VERSION                0
#define ICU_FTM_SW_PATCH_VERSION                1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_Ftm.h file and Icu_Ftm_Types header file are of the same vendor */
#if (ICU_FTM_VENDOR_ID != ICU_FTM_TYPES_VENDOR_ID)
    #error "Icu_Ftm.h and Icu_Ftm_Types.h have different vendor IDs"
#endif
/*  Check if Icu_Ftm.h file and Icu_Ftm_Types header file are of the same AutoSar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION != ICU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION != ICU_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION != ICU_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.h and Icu_Ftm_Types.h are different"
#endif
/*  Check if Icu_Ftm.h file and Icu_Ftm_Types header file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION != ICU_FTM_TYPES_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION != ICU_FTM_TYPES_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION != ICU_FTM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.h and Icu_Ftm_Types.h are different"
#endif

/* Check if Icu_Ftm.h file and Icu_Types header file are of the same vendor */
#if (ICU_FTM_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu_Ftm.h and Icu_Types.h have different vendor IDs"
#endif
/*  Check if Icu_Ftm.h file and Icu_Types header file are of the same AutoSar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.h and Icu_Types.h are different"
#endif
/*  Check if Icu_Ftm.h file and Icu_Types header file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.h and Icu_Types.h are different"
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
* @brief            Ftm_ChannelModeType
* @details          Type that indicates the channel mode type(capture mode, edge counter).
*
* */
typedef enum
{
    FTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT    = 0x01U, /*< @brief Mode for detecting edges. */
    FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT    = 0x02U, /*< @brief Mode for measuring different times
                                                        *  between various configurable edges. */
    /* @violates @ref ICU_FTM_H_REF_2 Identifier clash.*/
    FTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA = 0x04U, /*< @brief Mode for capturing timer values
                                                        *  on configurable edges. */
    /* @violates @ref ICU_FTM_H_REF_2 Identifier clash.*/
    FTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA    = 0x10U, /*< @brief Mode for capturing timer values
                                                            *  on configurable edges. */
    FTM_CHANNEL_MODE_EDGE_COUNTER          = 0x08U /*< @brief Mode for counting edges on
                                                       *  configurable edges. */
} Ftm_IcuChannelMeasurementModeType;


/**
* @brief         Ftm_ActivationType
* @details       Type that indicates the channel activation type(Rising, Falling,
*                Both Edges or Opposite Edges).
*
* */
typedef enum
{
    FTM_FALLING_EDGE = 0x2U,  /*< @brief An appropriate action shall be executed when a falling
                                           edge occurs on the ICU input signal. */

    FTM_RISING_EDGE  = 0x1U, /*< @brief An appropriate action shall be executed when a rising
                                           edge occurs on the ICU input signal.*/

    FTM_BOTH_EDGES   = 0x3U /*< @brief An appropriate action shall be executed when either
                                           a rising or falling edge occur on the ICU input signal.*/
} Ftm_IcuActivationType;

/**
 * @brief Definition of the measurement property type.
 * */
typedef enum
{
    FTM_ICU_LOW_TIME     = 0x01U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Low Time. */
    FTM_ICU_HIGH_TIME    = 0x02U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal High Time. */

    FTM_ICU_PERIOD_TIME  = 0x04U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Period Time. */
    FTM_ICU_DUTY_CYCLE   = 0x08U     /*< @brief The channel is configured to read values which
                                         *          are needed for calculating the duty cycle
                                         *          (coherent Active and Period Time). */
} Ftm_IcuSignalMeasurementPropertyType;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief          The Icu_ParamType contains combined bit fields for initialization options, for
 *                 different registers.
 *
 * */
typedef uint32                          Ftm_IcuParamType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref ICU_FTM_H_REF_1 precautions to prevent the
*       contents of a header file being included twice  */
#include "Icu_MemMap.h"


FUNC(void, ICU_CODE) Icu_Ftm_Init
(
    P2CONST(Icu_Ftm_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pFtmIpConfig
);
#if (ICU_DE_INIT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_DeInit
(
    P2CONST(Icu_Ftm_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pFtmIpConfig
);
#endif

#if (ICU_SET_MODE_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_SetSleepMode(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
FUNC(void, ICU_CODE) Icu_Ftm_SetNormalMode(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SET_MODE_API */


FUNC(void, ICU_CODE) Icu_Ftm_SetActivationCondition
(
    CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
    CONST(Ftm_IcuActivationType, AUTOMATIC) Activation
);

#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_EnableEdgeDetection(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
FUNC(void, ICU_CODE) Icu_Ftm_DisableEdgeDetection(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_StartTimestamp
(
    CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
    CONST(boolean, AUTOMATIC) bDmaSupport
);

FUNC(void, ICU_CODE) Icu_Ftm_StopTimestamp(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
FUNC(uint32, ICU_CODE) Icu_Ftm_GetStartAddress(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif
#endif  /* ICU_TIMESTAMP_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_ResetEdgeCount(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
FUNC(void, ICU_CODE) Icu_Ftm_EnableEdgeCount(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
FUNC(void, ICU_CODE) Icu_Ftm_DisableEdgeCount(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
FUNC(uint16, ICU_CODE) Icu_Ftm_GetEdgeNumbers(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_EDGE_COUNT_API */

FUNC (boolean, ICU_CODE) Icu_Ftm_GetOverflow(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_StartSignalMeasurement
(
    CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
    CONST(Ftm_IcuActivationType, AUTOMATIC) Activation,
    CONST(Ftm_IcuSignalMeasurementPropertyType, AUTOMATIC) measProperty,
    CONST(boolean, AUTOMATIC)bDmaSupport
);

FUNC(void, ICU_CODE) Icu_Ftm_StopSignalMeasurement(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (boolean, ICU_CODE) Icu_Ftm_GetInputState(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */


FUNC(void, ICU_CODE) Icu_Ftm_ProcessInterrupt(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

FUNC(void, ICU_CODE) Icu_Ftm_ProcessTofInterrupt(CONST(uint8, AUTOMATIC) u8hwModuleNo);

FUNC(void, ICU_CODE) Icu_Ftm_GlobalConfiguration(CONST(uint8, AUTOMATIC) u8hwModuleNo,\
                                                 CONST(uint8, AUTOMATIC) u8srcClk, \
                                                 CONST(uint8, AUTOMATIC) u8prescaler);
#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
FUNC (uint8, ICU_CODE) Icu_Ftm_GetInputLevel(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_GET_INPUT_LEVEL_API == STD_ON */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ftm_SetPrescaler (CONST(uint8, AUTOMATIC) u8hwModuleNo,
                                           VAR(uint8, AUTOMATIC) u8ChPrescaler
                                          );
#endif /*ICU_DUAL_CLOCK_MODE_API */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
FUNC(uint8, ICU_CODE) Icu_Ftm_GetInputLevel(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif

#if (ICU_CAPTURERGISTER_API == STD_ON)
FUNC(uint16, ICU_CODE) Icu_Ftm_GetCaptureRegisterValue(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_CAPTURERGISTER_API == STD_ON */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref ICU_FTM_H_REF_1 precautions to prevent the
*       contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_FTM_H */

/** @} */
