/**
* @file    Port_Ipw.h
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver low level driver interface.
* @details Interface between the high level driver (Autosar dependent) and the low level driver(IP dependent).
*          It is platform specific.
*
* @addtogroup  Port
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef PORT_IPW_H
#define PORT_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_IPW_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linkershall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers. 
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_IPW_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_Port_Ci.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file.
*
*/
#define PORT_VENDOR_ID_IPW_H                    43
#define PORT_AR_RELEASE_MAJOR_VERSION_IPW_H     4
#define PORT_AR_RELEASE_MINOR_VERSION_IPW_H     2
/**
* @violates @ref PORT_IPW_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for external
* identifiers.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_IPW_H  2

#define PORT_SW_MAJOR_VERSION_IPW_H             1
#define PORT_SW_MINOR_VERSION_IPW_H             0
#define PORT_SW_PATCH_VERSION_IPW_H             1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_Ipw.h and Port_Port_Ci.h file are of the same vendor */
#if (PORT_VENDOR_ID_IPW_H != PORT_PORT_CI_VENDOR_ID_H)
    #error "Port_Ipw.h and Port_Port_Ci.h have different vendor ids"
#endif

/* Check if Port_Ipw.h and Port_Port_Ci.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_IPW_H    != PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_IPW_H    != PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_IPW_H != PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_H) \
    )
   #error "AutoSar Version Numbers of Port_Ipw.h and Port_Port_Ci.h are different"
#endif

/* Check if Port_Ipw.h and Port_Port_Ci.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_IPW_H != PORT_PORT_CI_SW_MAJOR_VERSION_H) || \
     (PORT_SW_MINOR_VERSION_IPW_H != PORT_PORT_CI_SW_MINOR_VERSION_H) || \
     (PORT_SW_PATCH_VERSION_IPW_H != PORT_PORT_CI_SW_PATCH_VERSION_H) \
    )
   #error "Software Version Numbers of Port_Ipw.h and Port_Port_Ci.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#define PORT_MODE_BIT_OFFSET_MASK_U8  ((uint8)0x0F)

/**
* @brief  Mapping between low level layer and high level layer for Port_Ipw_Init function.
*/
#define Port_Ipw_Init                  (Port_Port_Ci_Init)

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
* @brief  Mapping between low level layer and high level layer for Port_Ipw_SetPinDirection.
*/
#define Port_Ipw_SetPinDirection       (Port_Port_Ci_SetPinDirection)

#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) */

#if defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/**
* @brief  Mapping between low level layer and high level layer for Port_Ipw_SetwPinsDirection.
*/
#define Port_Ipw_Set2PinsDirection     (Port_Port_Ci_Set2PinsDirection)

#endif /* defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */

/**
* @brief  Mapping between low level layer and high level layer for Port_Ipw_RefreshPortDirection function.
*/
#define Port_Ipw_RefreshPortDirection  (Port_Port_Ci_RefreshPortDirection)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                     FUNCTION PROTOTYPES
=================================================================================================*/

/* Allocate defined section for PORT code */
#define PORT_START_SEC_CODE
/**
* @violates @ref PORT_IPW_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* Sets the port pin mode.
*/
FUNC(Std_ReturnType, PORT_CODE) Port_Ipw_SetPinMode
(
    VAR     (Port_PinType,      AUTOMATIC                 ) PinIndex,
    VAR     (Port_PinModeType,  AUTOMATIC                 ) PinMode,
    P2CONST (Port_ConfigType,   AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#define PORT_STOP_SEC_CODE
/**
* @violates @ref PORT_IPW_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /*PORT_IPW_H*/
/** @} */
