/**
* @file    Port_Port_Ci.h
* @version 1.0.1
*
* @brief   AUTOSAR Port - PORT low level IP driver interface.
* @details API of the PORT low level IP driver.
*
* @addtogroup PORT
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef PORT_PORT_CI_H
#define PORT_PORT_CI_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Port_Port_Ci_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Port_Port_Ci_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "modules.h"
#include "Port_Cfg.h"
#include "Port_Port_Ci_Types.h"

/*=================================================================================================
*                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define PORT_PORT_CI_VENDOR_ID_H                     43
/* @violates @ref Port_Port_Ci_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_H      4
/* @violates @ref Port_Port_Ci_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_H      2
/* @violates @ref Port_Port_Ci_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_H   2
#define PORT_PORT_CI_SW_MAJOR_VERSION_H              1
#define PORT_PORT_CI_SW_MINOR_VERSION_H              0
#define PORT_PORT_CI_SW_PATCH_VERSION_H              1


#if (STD_ON == USE_PORT_MODULE)
/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Port_Ci.h and Port_Cfg.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_H != PORT_VENDOR_ID_CFG_H)
    #error "Port_Port_Ci.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port_Port_Ci.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_H    != PORT_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_H    != PORT_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
  #error "AutoSar Version Numbers of Port_Port_Ci.h and Port_Cfg.h are different"
#endif
/* Check if the files Port_Port_Ci.h and Port_Cfg.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_CFG_H) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_CFG_H) \
    )
  #error "Software Version Numbers of Port_Port_Ci.h and Port_Cfg.h are different"
#endif

/* Check if the files Port_Port_Ci.h and Port_PORT_CfgEx.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_H != PORT_PORT_CI_VENDOR_ID_TYPES_H)
    #error "Port_Port_Ci.h and Port_Port_Ci_Types.h have different vendor ids"
#endif
/* Check if the files Port_Port_Ci.h and Port_PORT_CfgEx.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_H    != PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_TYPES_H) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_H    != PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_TYPES_H) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_H != PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
   #error "AutoSar Version Numbers of Port_Port_Ci.h and Port_Port_Ci_Types.h are different"
#endif
/* Check if the files Port_Port_Ci.h and Port_PORT_CfgEx.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_H != PORT_PORT_CI_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_H != PORT_PORT_CI_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_H != PORT_PORT_CI_SW_PATCH_VERSION_TYPES_H) \
    )
  #error "Software Version Numbers of Port_Port_Ci.h and Port_Port_Ci_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Port_Ci.h and modules.h are of the same version */
   #if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_H != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_H != MODULES_AR_RELEASE_MINOR_VERSION_H)    \
       )
       #error "AutoSar Version Numbers of Port_Port_Ci.h and modules.h are different"
   #endif
#endif
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                               DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                     FUNCTION PROTOTYPES
=================================================================================================*/

/* @brief Allocate defined section for PORT code. */
#define PORT_START_SEC_CODE
/* @violates @ref Port_Port_Ci_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Port_MemMap.h"


/* @brief    Initializes the PORT IP Driver. */
FUNC(void, PORT_CODE) Port_Port_Ci_Init
(
    P2CONST(Port_ConfigType,AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/*
* @brief     Sets the port pin direction
*/
FUNC(Std_ReturnType, PORT_CODE) Port_Port_Ci_SetPinDirection
(
    VAR    (Port_PinType,          AUTOMATIC                 ) PinIndex,
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) eDirection,
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#if defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/*
* @brief     Sets the port direction for 2 pins
*/
FUNC(Std_ReturnType, PORT_CODE) Port_Port_Ci_Set2PinsDirection
(
    VAR    (Port_PinType,          AUTOMATIC                 ) Pin1Index,
    VAR    (Port_PinType,          AUTOMATIC                 ) Pin2Index,
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) eDirection,
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);
#endif /* defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Sets the port pin mode.
*/
FUNC(void, PORT_CODE) Port_Port_Ci_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
#if (STD_ON == PORT_DEV_ERROR_DETECT)
/**
* @brief    Sets or resets the direction changeability for pads in GPIO mode.
*/
FUNC(void, PORT_CODE) Port_Port_Ci_SetGpioDirChangeability
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PadID,
    VAR(boolean,                AUTOMATIC) bStatus
);
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
/**
* @brief    Sets the desired output value for the pad  switched in GPIO mode.
*/
FUNC(void, PORT_CODE) Port_Port_Ci_SetGpioPadOutput
(
    VAR    (Port_PinType,    AUTOMATIC                 ) PinIndex,
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#endif /* (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL) */
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/**
* @brief   Refreshes port direction.
*/
FUNC(void, PORT_CODE) Port_Port_Ci_RefreshPortDirection
(
    P2CONST(Port_ConfigType, AUTOMATIC,PORT_APPL_CONST) pConfigPtr
);

#define PORT_STOP_SEC_CODE
/* @violates @ref Port_Port_Ci_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Port_MemMap.h"

/* USE_PORT_MODULE */
#endif


#ifdef __cplusplus
}
#endif
/* PORT_PORT_CI_H */
#endif
/** @} */
