/**
*   @file    Ocu_Ftm.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Ocu - eTIMER driver header file.
*   @details eTIMER driver interface.
*
*   @addtogroup OCU_MODULE
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
======================================================================================================*/

#ifndef OCU_FTM_H
#define OCU_FTM_H

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
* @section OCU_FTM_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref OCU_FTM_H_REF_1 Repeated include file */
#include "Ocu_Ftm_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ocu_Ftm.h
*/
#define OCU_FTM_VENDOR_ID                       43
#define OCU_FTM_AR_RELEASE_MAJOR_VERSION        4
#define OCU_FTM_AR_RELEASE_MINOR_VERSION        2
#define OCU_FTM_AR_RELEASE_REVISION_VERSION     2
#define OCU_FTM_SW_MAJOR_VERSION                1
#define OCU_FTM_SW_MINOR_VERSION                0
#define OCU_FTM_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_FTM_TYPES_VENDOR_ID != OCU_FTM_TYPES_VENDOR_ID)
    #error "Ocu_Ftm_Types.h and Ocu_Ftm_Types.h have different vendor ids"
#endif
#if ((OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION != OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION != OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocu_Ftm_Types.h and Ocu_Ftm_Types.h are different"
#endif
#if ((OCU_FTM_TYPES_SW_MAJOR_VERSION != OCU_FTM_TYPES_SW_MAJOR_VERSION) || \
     (OCU_FTM_TYPES_SW_MINOR_VERSION != OCU_FTM_TYPES_SW_MINOR_VERSION) || \
     (OCU_FTM_TYPES_SW_PATCH_VERSION != OCU_FTM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocu_Ftm_Types.h and Ocu_Ftm_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief Definition of prescaler type.
 *
*/
typedef enum
{
    FTM_OCU_NORMAL_CLOCK_MODE    = 0x0U,           /*< @brief Default channel prescaler. */
    FTM_OCU_ALTERNATE_CLOCK_MODE                   /*< @brief Alternate channel prescaler mode */
} Ocu_Ftm_SelectPrescalerType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define OCU_START_SEC_CODE
/** @violates @ref OCU_FTM_H_REF_1 Repeated include file MemMap.h */
#include "Ocu_MemMap.h"

FUNC(void, OCU_CODE) Ocu_Ftm_Init(
                                        CONSTP2CONST(Ocu_Ftm_IpConfigType, AUTOMATIC, OCU_APPL_CONST)  pFtmIpConfig
                                    );

#if (OCU_DEINIT_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_Ftm_DeInit(CONSTP2CONST(Ocu_Ftm_IpConfigType, AUTOMATIC, OCU_APPL_CONST)  pFtmIpConfig);
#endif

FUNC(void, OCU_CODE) Ocu_Ftm_StartChannel
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);

FUNC(void, OCU_CODE) Ocu_Ftm_StopChannel
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);

#if (OCU_GET_COUNTER_API == STD_ON)
FUNC(uint16, OCU_CODE) Ocu_Ftm_GetCounter
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);
#endif

#if (OCU_SET_PIN_ACTION_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_Ftm_SetPinAction
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    VAR(Ocu_PinActionType, AUTOMATIC)                               ePinAction,
    VAR(boolean, AUTOMATIC)                                         bIsRunning,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);
#endif

#if (OCU_SET_PIN_STATE_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_Ftm_SetPinState
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,    
    CONST(Ocu_PinStateType, AUTOMATIC)                              ePinState,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);
#endif

#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
FUNC(Ocu_ReturnType, OCU_CODE) Ocu_Ftm_SetAbsoluteThreshold
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,    
    VAR(Ocu_ValueType,  AUTOMATIC)                                  ReferenceValue,
    VAR(Ocu_ValueType,  AUTOMATIC)                                  AbsoluteValue,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);
#endif

#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
FUNC(Ocu_ReturnType, OCU_CODE) Ocu_Ftm_SetRelativeThreshold
(   
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,    
    VAR(Ocu_ValueType,          AUTOMATIC)                          RelativeValue,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
);
#endif

#if (OCU_SET_CLOCK_MODE_API == STD_ON)
FUNC(void, OCU_CODE) Ocu_Ftm_SetClockMode
(
    CONSTP2CONST(Ocu_Ftm_IpConfigType,        AUTOMATIC, OCU_APPL_CONST)  pFtmIpConfig,
    VAR         (Ocu_Ftm_SelectPrescalerType, AUTOMATIC) ePrescaler
);
#endif
#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
FUNC (Ocu_ValueType, OCU_CODE) Ocu_Ftm_GetMaxCountValue
(
    VAR(Ocu_ChannelType,                                      AUTOMATIC)  u8IdxChannelConfig
);
#endif
#define OCU_STOP_SEC_CODE
/** @violates @ref OCU_FTM_H_REF_1 Repeated include file */
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*OCU_FTM_H*/

/** @} */
