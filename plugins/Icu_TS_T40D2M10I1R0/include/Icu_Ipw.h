/**
*     @file Icu_Ipw.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Brief description.
*     @details Detailed description.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform ARM
*     Peripheral FTM PORT_CI LPIT LPTMR
*     Dependencies none
*
*     Autosar Version 4.2.2
*     Autosar Revision ASR_REL_4_2_REV_0002
*     Autosar ConfVariant
*     SWVersion 1.0.1
*     BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_IPW_H
#define ICU_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_IPW_h_REF_1
*         Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*         Middle layer between AUTOSAR and hardware needs a way to map HLD
*         functions to IP functions.
*
* @section Icu_IPW_h_REF_2
*         Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*         the contents of a header file being included twice
*         This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_IPW_h_REF_3
*           Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced
*           initialiser, a constant, a parenthesised expression, a type qualifier, a storage class
*           specifier, or a do-while-zero construct.
*           This is used to route calls from AUTOSAR to hardware layer
* @section [global]
*         Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*         on the significance of more than 31 characters. The used compilers use more than 31 chars
*         for identifiers.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Icu_Ipw_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_VENDOR_ID                       43

#define ICU_IPW_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_AR_RELEASE_MINOR_VERSION        2
#define ICU_IPW_AR_RELEASE_REVISION_VERSION     2
#define ICU_IPW_SW_MAJOR_VERSION                1
#define ICU_IPW_SW_MINOR_VERSION                0
#define ICU_IPW_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_Ipw header and Icu_Ipw_Types header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Ipw.h and Icu_Ipw_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.h and Icu_Ipw_Types.h are different"
#endif
/* Check if header file and Icu_Ipw_Types header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION != ICU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Ipw.h and Icu_Ipw_Types.h are different"
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


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_IPW_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/

#include "Icu_MemMap.h"

FUNC (void, ICU_CODE) Icu_Ipw_Init
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

#if (ICU_DE_INIT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Ipw_DeInit
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif

#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Ipw_SetSleepMode
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
FUNC (void, ICU_CODE) Icu_Ipw_SetNormalMode
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif  /* ICU_SET_MODE_API == STD_ON */


FUNC (void, ICU_CODE) Icu_Ipw_SetActivationCondition
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR(Icu_ActivationType,        AUTOMATIC)                 Activation,
    VAR(Icu_MeasurementModeType,   AUTOMATIC)                 Mode,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC(Icu_InputStateType, ICU_CODE)Icu_Ipw_GetInputState
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif  /* ICU_GET_INPUT_STATE_API == STD_ON */

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_StartTimestamp
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(boolean,                              AUTOMATIC)      bDmaSupport
);

FUNC(void, ICU_CODE) Icu_Ipw_StopTimestamp
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
FUNC(uint32, ICU_CODE) Icu_Ipw_GetStartAddress
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif  /* ICU_TIMESTAMP_USES_DMA == STD_ON */
#endif  /* ICU_TIMESTAMP_API == STD_ON */


#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_ResetEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

FUNC(void, ICU_CODE) Icu_Ipw_EnableEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

FUNC(void, ICU_CODE) Icu_Ipw_DisableEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Ipw_GetEdgeNumbers
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif  /* ICU_EDGE_COUNT_API == STD_ON */


#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Ipw_EnableEdgeDetection
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

FUNC (void, ICU_CODE) Icu_Ipw_DisableEdgeDetection
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif /* ICU_EDGE_DETECT_API */


#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
FUNC(boolean, ICU_CODE) Icu_Ipw_Get_Overflow
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_CAPTURERGISTER_API == STD_ON)
FUNC(Icu_ValueType, ICU_CODE) Icu_Ipw_GetCaptureRegisterValue
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Ipw_StartSignalMeasurement
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(Icu_ActivationType,                   AUTOMATIC)      startEdge,
    VAR(Icu_SignalMeasurementPropertyType,    AUTOMATIC)      measProperty,
    VAR(boolean,                              AUTOMATIC)      bDmaSupport
);

FUNC (void, ICU_CODE) Icu_Ipw_StopSignalMeasurement
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);
#endif  /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_SetClockMode
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(Icu_SelectPrescalerType,   AUTOMATIC)                 Prescaler
);
/**
* @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define Icu_Ipw_SelectPrescaler(hwChannel, Icu_ParamValue, Prescaler)      ((uint32)(0U))

#endif /* ICU_DUAL_CLOCK_MODE_API == STD_ON */


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)

#if (ICU_VALIDATE_PARAMS == STD_ON)
FUNC (Icu_ChannelType, ICU_CODE) Icu_Ipw_ValidateGetInputLevel
(
    VAR         (Icu_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

#endif /*(ICU_VALIDATE_PARAMS == STD_ON) */

FUNC(Icu_LevelType, ICU_CODE) Icu_Ipw_GetInputLevel
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
);

#endif /* && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_IPW_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_IPW_H */
/** @} */

