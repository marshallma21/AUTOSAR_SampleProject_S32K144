/**
*   @file    Port.h
*   @implements Port.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - driver API.
*   @details This file contains the PORT Autosar driver API.
*
*   @addtogroup Port
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef PORT_H
#define PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_H_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported for external 
*          identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_H_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Mcal.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
*/
#define PORT_VENDOR_ID                    43
#define PORT_MODULE_ID                    124
#define PORT_AR_RELEASE_MAJOR_VERSION     4
#define PORT_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref PORT_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_REVISION_VERSION  2
#define PORT_SW_MAJOR_VERSION             1
#define PORT_SW_MINOR_VERSION             0
#define PORT_SW_PATCH_VERSION             1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port.h and Port_Cfg.h are of the same vendor */
#if (PORT_VENDOR_ID != PORT_VENDOR_ID_CFG_H)
    #error "Port.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION_CFG_H)     || \
     (PORT_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION_CFG_H)     || \
     (PORT_AR_RELEASE_REVISION_VERSION != PORT_AR_RELEASE_REVISION_VERSION_CFG_H)  \
    )
     #error "AutoSar Version Numbers of Port.h and Port_Cfg.h are different"
#endif
/* Check if the files Port.h and Port_Cfg.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION_CFG_H) || \
     (PORT_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION_CFG_H)    \
    )
  #error "Software Version Numbers of Port.h and Port_Cfg.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port.h and Std_Types.h are of the same version */
   #if ((PORT_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
       )
       #error "AutoSar Version Numbers of Port.h and Std_Types.h are different"
   #endif
    /* Check if the files Port.h and Mcal.h are of the same version */
   #if ((PORT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (PORT_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
       )
       #error "AutoSar Version Numbers of Port.h and Mcal.h are different"
   #endif
#endif
/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/* Instance IDs */
/**
* @brief   Instance ID of port driver.
*
*/
#define PORT_INSTANCE_ID                ((uint8)0x0)

/* Service IDs */
/*
* @brief   Service ID of port driver.
*/

/**
* @brief   API service ID for PORT Init function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_INIT_ID                    ((uint8)0x00)
/**
* @brief   API service ID for PORT set pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SETPINDIRECTION_ID         ((uint8)0x01)
/**
* @brief   API service ID for PORT refresh pin direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_REFRESHPINDIRECTION_ID     ((uint8)0x02)
/**
* @brief   API service ID for PORT get version info function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_GETVERSIONINFO_ID          ((uint8)0x03)
/**
* @brief   API service ID for PORT set pin mode.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SETPINMODE_ID              ((uint8)0x04)

#if defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/**
* @brief   API service ID for PORT set 2 pins direction function.
* @details Parameters used when raising an error/exception.
*
* @api
*
*/
#define PORT_SET2PINSDIRECTION_ID       ((uint8)0x05)
#endif /* defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */

/* Errors IDs */
/**
* @brief   Error ID of port driver.
* @details The following errors and exception are detectable by the PORT driver
*          if development error detection is enabled.
*
*/

/**
* @brief   Invalid Port Pin ID requested.
* @details Det Error value, returned by Port_SetPinDirection and Port_PinMode
*          if an wrong PortPin ID is passed.
*
* @implements Port_ErrorCodes_define
* @api
*/
 #define PORT_E_PARAM_PIN                ((uint8)0x0A)
/**
* @brief   Port Pin Direction not configured as changeable.
* @details Det Error value, returned by Port_SetPinDirection
*          if the passed PortPin have unchangeable direction.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_DIRECTION_UNCHANGEABLE   ((uint8)0x0B)
/**
* @brief   API Port_Init() service called with wrong parameter.
* @details Det Error value, returned by Port_Init function
*          if Port_Init is called with wrong parameter.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_INIT_FAILED              ((uint8)0x0C)
/**
* @brief   API Port_SetPinMode() service called when mode is invalid.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPinMode is invalid.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_PARAM_INVALID_MODE       ((uint8)0x0D)
/**
* @brief   API Port_SetPinMode() service called when mode is unchangeable.
* @details Det Error value, returned by Port_SetPinMode function
*          if the passed PortPin have a unchangeable Mode.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_MODE_UNCHANGEABLE        ((uint8)0x0E)
/**
* @brief   API service called without module initialization.
* @details Det Error value, returned by a function if API service called
*          prior to module initialization.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_UNINIT                   ((uint8)0x0F)
/**
* @brief   API service called with NULL Pointer Parameter.
* @details Det Error value, returned by Port_GetVersionInfo function
*          if API is called with NULL Pointer Parameter.
*
* @implements Port_ErrorCodes_define
* @api
*/
#define PORT_E_PARAM_POINTER            ((uint8)0x10)


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                              ENUMS
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
/** @violates @ref PORT_H_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"

/*
* Initializes the Port Driver module.
*/
FUNC(void, PORT_CODE) Port_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/*
* Sets the port pin direction.
* Function disabled in the frozen pin configuration.
*/
FUNC(void, PORT_CODE) Port_SetPinDirection
( 
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction
);
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) */

#if defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/*
* Sets the port pin direction for 2 pins.
*/
FUNC(void, PORT_CODE) Port_Set2PinsDirection
(
    VAR(Port_PinType,           AUTOMATIC) Pin1,
    VAR(Port_PinType,           AUTOMATIC) Pin2,
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction
);
#endif /* defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/*
* Sets the port pin mode.
*/
FUNC(void, PORT_CODE) Port_SetPinMode
(
    VAR(Port_PinType,       AUTOMATIC) Pin,
    VAR(Port_PinModeType,   AUTOMATIC) Mode
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_VERSION_INFO_API)
/*
* Returns the version information of this module.
*/
FUNC (void, PORT_CODE) Port_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) versioninfo
);
#endif /* (STD_ON == PORT_VERSION_INFO_API) */

/*
* Refreshes port direction.
*/
FUNC(void, PORT_CODE) Port_RefreshPortDirection(void);


#define PORT_STOP_SEC_CODE
/** @violates @ref PORT_H_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* PORT_H */

/** @} */
