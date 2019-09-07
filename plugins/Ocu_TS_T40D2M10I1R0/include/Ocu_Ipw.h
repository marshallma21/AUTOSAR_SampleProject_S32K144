/**
*   @file           Ocu_Ipw.h
*
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - Ocu Ipw API.
*   @details        Ocu Ipw API.
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
=====================================================================================================*/
/*====================================================================================================
======================================================================================================*/

#ifndef OCU_IPW_H
#define OCU_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_IPW_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Ocu_IPW_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Ocu_IPW_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. Middle layer between AUTOSAR
* and hardware needs a way to map HLD functions to IP functions.
*/

/*===============================================================================================
*         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

/*===============================================================================================
*               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Ocu_Ipw.h
*/
#define OCU_IPW_VENDOR_ID         43
#define OCU_IPW_MODULE_ID         121
/* @violates @ref Ocu_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_IPW_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Ocu_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_IPW_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Ocu_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_IPW_AR_RELEASE_REVISION_VERSION       2
#define OCU_IPW_SW_MAJOR_VERSION  1
#define OCU_IPW_SW_MINOR_VERSION  0
#define OCU_IPW_SW_PATCH_VERSION  1
/**@}*/

/*===============================================================================================
*                                    FILE VERSION CHECKS
===============================================================================================*/

/*===============================================================================================
*                                         CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                    DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                          ENUMS
===============================================================================================*/

/*===============================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                               GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                   FUNCTION PROTOTYPES
===============================================================================================*/
/*
* @violates @ref Ocu_IPW_H_REF_2 Only preprocessor statements and comments before "#include"
*/

#define OCU_START_SEC_CODE
/*
* @violates @ref Ocu_IPW_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

FUNC (void, OCU_CODE) Ocu_Ipw_Init
(   
    CONSTP2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpConfig
);

/*===============================================================================================*/

#if (OCU_DEINIT_API == STD_ON)
FUNC (void, OCU_CODE) Ocu_Ipw_DeInit
(
    CONSTP2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpConfig
);
#endif /* OCU_DEINIT_API */

/*===============================================================================================*/

FUNC (void, OCU_CODE) Ocu_Ipw_StartChannel
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber
);    

/*===============================================================================================*/

FUNC (void, OCU_CODE) Ocu_Ipw_StopChannel
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber
);    

/*===============================================================================================*/

#if (OCU_SET_PIN_STATE_API == STD_ON)
FUNC (void, OCU_CODE) Ocu_Ipw_SetPinState
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_PinStateType, AUTOMATIC) ePinState
);
#endif /* OCU_SET_PIN_STATE_API */

/*===============================================================================================*/

#if (OCU_SET_PIN_ACTION_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_Ipw_SetPinAction
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_PinActionType, AUTOMATIC) ePinAction,
    VAR(boolean,           AUTOMATIC) bIsRunning
);
#endif /* OCU_SET_PIN_ACTION_API */

/*===============================================================================================*/

#if (OCU_GET_COUNTER_API == STD_ON)
FUNC (Ocu_ValueType, OCU_CODE) Ocu_Ipw_GetCounter
(
    VAR(Ocu_ChannelType,  AUTOMATIC) u8ChannelNumber
);
#endif /* OCU_GET_COUNTER_API */

/*===============================================================================================*/

#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
FUNC (Ocu_ReturnType, OCU_CODE) Ocu_Ipw_SetAbsoluteThreshold
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_ValueType,     AUTOMATIC) ReferenceValue,
    VAR(Ocu_ValueType,     AUTOMATIC) AbsoluteValue
);
#endif/* OCU_SET_ABSOLUTE_THRESHOLD_API*/

/*===============================================================================================*/

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) 
FUNC (Ocu_ReturnType, OCU_CODE) Ocu_Ipw_SetRelativeThreshold
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber,
    VAR(Ocu_ValueType,     AUTOMATIC) RelativeValue
);
#endif/*OCU_SET_RELATIVE_THRESHOLD_API */

/*===============================================================================================*/

#if (OCU_SET_CLOCK_MODE_API == STD_ON)
FUNC (void, OCU_CODE) Ocu_Ipw_SetClockMode
(
    CONSTP2CONST(Ocu_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pIpConfig,
    VAR(Ocu_SelectPrescalerType,   AUTOMATIC) ePrescaler
);
#endif

/*===============================================================================================*/

#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
FUNC (Ocu_ValueType, OCU_CODE) Ocu_Ipw_GetMaxCountValue
(
    VAR(Ocu_ChannelType,   AUTOMATIC) u8ChannelNumber
);
#endif

/* @violates @ref Ocu_IPW_H_REF_2 Only preprocessor statements and comments before "#include" */
#define OCU_STOP_SEC_CODE
/* @violates @ref Ocu_IPW_H_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* OCU_IPW_H */

/** @} */
