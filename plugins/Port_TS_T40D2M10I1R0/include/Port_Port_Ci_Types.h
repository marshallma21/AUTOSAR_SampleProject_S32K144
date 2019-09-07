/**
*   @file    Port_Port_Ci_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - PORT low level IP driver exported structures.
*   @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
*
*   @addtogroup PORT
*   @{
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

#ifndef PORT_PORT_CI_TYPES_H
#define PORT_PORT_CI_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port_Reg_eSys_Port_Ci.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/*
* @brief current file vendor, Autosar and API version numbers
*       The integration of incompatible files shall be avoided.
*/
#define PORT_PORT_CI_VENDOR_ID_TYPES_H                     43
#define PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_TYPES_H      4
#define PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_TYPES_H      2
#define PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_TYPES_H   2
#define PORT_PORT_CI_SW_MAJOR_VERSION_TYPES_H              1
#define PORT_PORT_CI_SW_MINOR_VERSION_TYPES_H              0
#define PORT_PORT_CI_SW_PATCH_VERSION_TYPES_H              1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if the files Port_Port_Ci_Types.h and Port_Reg_eSys_Port_Ci.h are of the same vendor */
#if (PORT_PORT_CI_VENDOR_ID_TYPES_H != PORT_REGESYS_PORT_CI_VENDOR_ID)
    #error "Port_Port_Ci_Types.h and Port_Reg_eSys_Port_Ci.h have different vendor ids"
#endif
/* Check if the files Port_Port_Ci_Types.h and Port_Reg_eSys_Port_Ci.h are of the same Autosar version */
#if ((PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_TYPES_H    != PORT_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_TYPES_H    != PORT_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
     (PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_TYPES_H != PORT_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION) \
    )
  #error "AutoSar Version Numbers of Port_Port_Ci_Types.h and Port_Reg_eSys_Port_Ci.h are different"
#endif
/* Check if the files Port_Port_Ci_Types.h and Port_Reg_eSys_Port_Ci.h are of the same software version */
#if ((PORT_PORT_CI_SW_MAJOR_VERSION_TYPES_H != PORT_REGESYS_PORT_CI_SW_MAJOR_VERSION) || \
     (PORT_PORT_CI_SW_MINOR_VERSION_TYPES_H != PORT_REGESYS_PORT_CI_SW_MINOR_VERSION) || \
     (PORT_PORT_CI_SW_PATCH_VERSION_TYPES_H != PORT_REGESYS_PORT_CI_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Port_Port_Ci_Types.h and Port_Reg_eSys_Port_Ci.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/**
* @brief Possible output status of a port pin.
*/
#define  PORT_PIN_LEVEL_LOW_U8         ((uint8)0)    /**< @brief Sets port pin in '0' logic. */
#define  PORT_PIN_LEVEL_HIGH_U8        ((uint8)1)    /**< @brief Sets port pin in '1' logic. */
#define  PORT_PIN_LEVEL_NOTCHANGED_U8  ((uint8)2)    /**< @brief No level changes for the port pin. */

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief Data type for the symbolic name of a port pin.
* @details Shall cover all available port pins. The type should be chosen for the specific MCU
*         platform (best performance).
* @implements Port_PinType_typedef
*/
typedef uint32 Port_PinType;

/**
* @brief Possible directions of a port pin.
* @implements Port_PinDirectionType_enumeration 
*/
typedef enum
{
    PORT_PIN_DISABLED = 0,  /**< @brief No settings: the pin is not available. */ 
    PORT_PIN_IN,            /**< @brief Sets port pin as input. */
    PORT_PIN_OUT            /**< @brief Sets port pin as output. */
} Port_PinDirectionType;

/**
* @brief Different port pin modes.
* @details A port pin shall be configurable with a number of port pin modes (type Port_PinModeType).
*        The type Port_PinModeType shall be used with the function call Port_SetPinMode
* @implements Port_PinModeType_typedef
*/
typedef uint8 Port_PinModeType;

/*
* @brief Data type for the number, mentioned in platform spec, of a port pin.
*        It is the same with the index of the PCR register.
* @details Shall cover all available port pins.
* 
*/
typedef uint16 Port_InternalPinIdType;

/**
* @brief   A PORT register value.
* @details A port register shall be written with a 32 bits value (type Port_RegValueType).
*          The type Port_RegValueType shall be used with the function call Port_SetPinMode
* 
*/
typedef uint32 Port_RegValueType;

/**
* @brief   Single pin configuration.
* @details This structure contains all configuration parameters of a single pin
*          identified by @p PORT Pin.
* 
* @api
*/
typedef struct
{
    VAR(Port_InternalPinIdType, AUTOMATIC)   Pin;       /**< @brief Pin Defined on PORT */
    VAR(uint32,                 AUTOMATIC)   u32PCR;    /**< @brief Pad Control Register */
    VAR(uint8,                  AUTOMATIC)   u8PDO;     /**< @brief Pad Data Output */
    VAR(Port_PinDirectionType,  AUTOMATIC)   ePDDir;   /**< @brief Pad Data Direction */
    VAR(boolean,                AUTOMATIC)   bGPIO;     /**< @brief GPIO initial mode*/
    VAR(boolean,                AUTOMATIC)   bDC;       /**< @brief Direction changebility*/
    VAR(boolean,                AUTOMATIC)   bMC;       /**< @brief Mode changebility*/
} Port_Port_Ci_PinConfigType;

/**
* @brief   Default pin configuration.
* @details This structure contains all configuration parameters of a Default pin
*
* @api
*/
typedef struct
{
    VAR(uint32,                 AUTOMATIC)   u32PCR;   /**< Pad Control Register */
    VAR(Port_PinDirectionType,  AUTOMATIC)   ePDDir;  /**< Pad Data Direction */
    VAR(uint8,                  AUTOMATIC)   u8PDO;    /**< Pad Data Output */
} Port_Port_Ci_UnUsedPinConfigType;

/**
* @brief   Digital filter port configuration.
* @details This structure contains all configuration parameters of a digital filter port
*
* @api
*/
typedef struct
{
    VAR(uint8,  AUTOMATIC)   u8Port;     /**< Digital Filter Port */
    VAR(uint8,  AUTOMATIC)   u8Clock;    /**< Digital Filter Clock */
    VAR(uint8,  AUTOMATIC)   u8Width;    /**< Digital Filter Width */
    VAR(uint32, AUTOMATIC)   u32PinMask; /**< Mask of pins for which digital filter is enabled */
} Port_DigitalFilter_ConfigType;

/**
* @brief Data type used for Pad Selection Multiplexed Configuration.
* @details This type should be chosen for the specific MCU platform (best performance).
*
* @api
*/
typedef uint8 Port_Port_Ci_PadSelConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/


#ifdef __cplusplus
}
#endif
/* PORT_PORT_CI_TYPES_H */
#endif
/** @} */
