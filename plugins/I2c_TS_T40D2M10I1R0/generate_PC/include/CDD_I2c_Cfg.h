/**
*   @file    CDD_I2c_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - High level header of I2c driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup I2c
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPI2C
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

#ifndef I2C_CFG_H
#define I2C_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section CDD_I2c_Cfg_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported 
* for external identifiers. This violation is due to the requirement that requests to have a file version check.
*
* @section CDD_I2c_Cfg_h_REF_2
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed from within a single function
*
* @section CDD_I2c_Cfg_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined. This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section CDD_I2c_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to braced initialiser,
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or
* a do-while-zero construct
**
* @section CDD_I2c_Cfg_h_REF_5
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as * the operand of # or ##.
* This is used to define user configurable callbacks with parameters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */

#define I2C_VENDOR_ID_CFG                    43
#define I2C_MODULE_ID_CFG                    255
#define I2C_AR_RELEASE_MAJOR_VERSION_CFG     4
#define I2C_AR_RELEASE_MINOR_VERSION_CFG     2
/*
* @violates @ref CDD_I2c_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_REVISION_VERSION_CFG  2
#define I2C_SW_MAJOR_VERSION_CFG             1
#define I2C_SW_MINOR_VERSION_CFG             0
#define I2C_SW_PATCH_VERSION_CFG             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((I2C_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and Mcal.h are different"
    #endif
#endif

[!NOCODE!][!//
[!INCLUDE "CDD_I2c_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*
* @api
*/
#define I2C_PRECOMPILE_SUPPORT   [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief   Total number of available hardware I2c channels.
*/
#define I2C_HW_MAX_MODULES          ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')))"!]U)

/**
* @brief   Total number of available hardware LPI2C channels.
*/
#define I2C_LPI2C_MAX_MODULES       ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')[contains(., 'LPI2C')]))"!]U)

/**
* @brief   Total number of available hardware FLEXIO sub channels. Each FLEXIO module can support 2 I2c channels
*/
#define I2C_FLEXIO_MAX_CHANNELS     ([!"num:i(count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')[contains(., 'FLEXIO')]))"!]U)

/**
* @brief   Unified Interrupt.
*/
#define I2C_UNIFIED_INTERRUPTS [!IF "ecu:get('I2cUnifiedInterrupts') = 'TRUE'"!] (STD_ON) /* Only 1 interrupt vector for each LPI2C channel */ [!ELSE!] (STD_OFF) [!ENDIF!]

/**
* @brief            This is the ID of the first FLEXIO channel.
*/
#define I2C_FLEXIO_FIRST_CHANNEL_U8   (I2C_LPI2C_MAX_MODULES)

/**
* @brief   Number of loops before returning I2C_E_TIMEOUT.
*
* @api
*/
#define  I2C_TIMEOUT_LOOPS [!"GeneralConfiguration/I2cTimeoutDuration"!]U

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define I2C_DEV_ERROR_DETECT      [!IF "GeneralConfiguration/I2cDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF) /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief          Support for version info API.
* @details        Switches the I2c_GetVersionInfo() API ON or OFF.
*
* @api
*/
#define I2C_VERSION_INFO_API      [!IF "GeneralConfiguration/I2cVersionInfoApi"!](STD_ON)  /* Enable API I2c_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API I2c_GetVersionInfo     */[!ENDIF!]

[!CODE!]
/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
* @details        Link I2c channels symbolic names with I2c channel IDs.
*
* @api
*/
[!ENDCODE!]
[!FOR "HwChannelIdx" = "1" TO "count(ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel'))"!]
[!CODE!]
#define [!"ecu:list('I2c.I2cGlobalConfig.I2cChannel.I2cHwChannel')[num:i($HwChannelIdx)]"!]    [!"num:i($HwChannelIdx - num:i(1))"!]U
[!ENDCODE!]
[!ENDFOR!]

/**
* @brief          Symbolic names for configured channels.
* @details        Symbolic names for configured channels.
*
* @api
*/
[!LOOP "I2cGlobalConfig/I2cChannel/*"!][!//
/*
* @violates @ref CDD_I2c_Cfg_h_REF_1 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2cConf_I2cChannelConfiguration_[!"node:name(.)"!]         [!"I2cChannelId"!]
[!ENDLOOP!][!//

/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define I2C_DISABLE_DEM_REPORT_ERROR_STATUS   [!IF "(GeneralConfiguration/I2cDisableDemReportErrorStatus='true') or (num:i(count(I2cGlobalConfig/I2cDemEventParameterRefs[node:exists(.)]))=0)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cErrorNotification)"!]
/**
* @brief            The call out configured by the user for error notifications.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_3 MISRA 2004 Advisory Rule 19.7 This is used to define user configurable callouts with parameters .*/
/** @violates @ref CDD_I2c_Cfg_h_REF_5 This is used to define user configurable callouts with parameters */
#define I2C_ERROR_NOTIFICATION(u8Channel, u8ErrorCode) ([!"normalize-space(GeneralConfiguration/I2cErrorNotification)"!](u8Channel, u8ErrorCode))
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cMasterTransmitCompleteNotification)"!]
/**
* @brief            The call out configured by the user for master transmission completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_3 MISRA 2004 Advisory Rule 19.7 This is used to define user configurable callouts with parameters .*/
/** @violates @ref CDD_I2c_Cfg_h_REF_5 This is used to define user configurable callouts with parameters */
#define I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION(u8Channel, u8NumberOfBytes) ([!"normalize-space(GeneralConfiguration/I2cMasterTransmitCompleteNotification)"!](u8Channel, u8NumberOfBytes))
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cMasterReceiveCompleteNotification)"!]
/**
* @brief            The call out configured by the user for master reception completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_3 MISRA 2004 Advisory Rule 19.7 This is used to define user configurable callouts with parameters .*/
/** @violates @ref CDD_I2c_Cfg_h_REF_5 This is used to define user configurable callouts with parameters */
#define I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION(u8Channel, u8NumberOfBytes) ([!"normalize-space(GeneralConfiguration/I2cMasterReceiveCompleteNotification)"!](u8Channel, u8NumberOfBytes))
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cSlaveAddressMatchNotification)"!]
/**
* @brief            The call out configured by the user for address matching notifications.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_3 MISRA 2004 Advisory Rule 19.7 This is used to define user configurable callouts with parameters .*/
/** @violates @ref CDD_I2c_Cfg_h_REF_5 This is used to define user configurable callouts with parameters */
#define I2C_SLAVE_ADDR_MATCH_NOTIFICATION(u8Channel, eDirection) ([!"normalize-space(GeneralConfiguration/I2cSlaveAddressMatchNotification)"!](u8Channel, eDirection))
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cSlaveTransmitCompleteNotification)"!]
/**
* @brief            The call out configured by the user for slave transmission completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_3 MISRA 2004 Advisory Rule 19.7 This is used to define user configurable callouts with parameters .*/
/** @violates @ref CDD_I2c_Cfg_h_REF_5 This is used to define user configurable callouts with parameters */
#define I2C_SLAVE_TRANSMIT_COMPLETE_NOTIFICATION(u8Channel, u8NumberOfBytes) ([!"normalize-space(GeneralConfiguration/I2cSlaveTransmitCompleteNotification)"!](u8Channel, u8NumberOfBytes))
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cSlaveReceiveCompleteNotification)"!]
/**
* @brief            The call out configured by the user for slave reception completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_3 MISRA 2004 Advisory Rule 19.7 This is used to define user configurable callouts with parameters .*/
/** @violates @ref CDD_I2c_Cfg_h_REF_5 This is used to define user configurable callouts with parameters */
#define I2C_SLAVE_RECEIVE_COMPLETE_NOTIFICATION(u8Channel, u8NumberOfBytes) ([!"normalize-space(GeneralConfiguration/I2cSlaveReceiveCompleteNotification)"!](u8Channel, u8NumberOfBytes))
[!ENDIF!]

/**
* @brief            DMA is used for at least one channel (STD_ON/STD_OFF)
*/
[!CODE!][!//
#define I2C_DMA_USED   [!IF "(GeneralConfiguration/I2cDmaUsed='true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]
[!ENDCODE!][!//

/* Errors to be reported by the user configurable error notification */
#define I2C_E_PIN_LOW_TIMEOUT           ((uint8)0x01U)
#define I2C_E_FIFO_ERROR                ((uint8)0x02U)
#define I2C_E_ARBITRATION_LOST          ((uint8)0x03U)
#define I2C_E_UNEXPECTED_NACK           ((uint8)0x04U)

#define I2C_E_TX_UNDERFLOW              ((uint8)0x05U)
#define I2C_E_RX_OVERFLOW               ((uint8)0x06U)

#define I2C_E_SLAVE_FIFO_ERROR          ((uint8)0x10U)
#define I2C_E_SLAVE_BIT_ERROR           ((uint8)0x11U)


[!MACRO "I2cExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(I2cGlobalConfig)"!][!//
[!CODE!][!//
/**
* @brief            Pre-Compile structure from CDD_I2c_Cfg.c file.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {} */
#define I2C_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(I2c_ConfigType, I2C_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(I2c_ConfigType, I2C_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "I2cExportDriverConfiguration"!]
[!ENDIF!]

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * @brief Definition of the type of activation or procession mechanism of an I2c hw unit
 * @implements     I2c_DataDirectionType_enumeration
 * 
 */
typedef enum
{
    I2C_SEND_DATA       = 0x0U, /**< @brief Used to send data to a slave */
    I2C_RECEIVE_DATA    = 0x1U  /**< @brief Used to receive data from a slave */
} I2c_DataDirectionType;

/**
 * @brief Definition of the hardware channel type
 * 
 */
typedef enum
{
    LPI2C_CHANNEL       = 0x0U, /**< @brief This is used for LPI2C channels */
    FLEXIO_CHANNEL      = 0x1U  /**< @brief This is used for FlexIO channels */
} I2c_HwChannelType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    VAR( Mcal_DemErrorType, I2C_VAR) I2c_E_TimeoutFailureCfg;

} I2c_DemConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

extern CONST( I2c_DemConfigType, I2C_CONST) I2c_DemConfig;

[!IF "node:exists(GeneralConfiguration/I2cErrorNotification)"!]
/**
* @brief            The call out configured by the user for error notifications.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_2 MISRA 2004 Required Rule 8.7, these object are used trough the entire I2c code*/
extern FUNC(void, I2C_CODE) I2C_ERROR_NOTIFICATION(VAR (uint8, AUTOMATIC) u8Channel, VAR (uint8, AUTOMATIC) u8ErrorCode);
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cMasterTransmitCompleteNotification)"!]
/**
* @brief            The call out configured by the user for master transmission completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_2 MISRA 2004 Required Rule 8.7, these object are used trough the entire I2c code*/
extern FUNC(void, I2C_CODE) I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION(VAR (uint8, AUTOMATIC) u8Channel, VAR (uint8, AUTOMATIC) u8NumberOfBytes);
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cMasterReceiveCompleteNotification)"!]
/**
* @brief            The call out configured by the user for master reception completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_2 MISRA 2004 Required Rule 8.7, these object are used trough the entire I2c code*/
extern FUNC(void, I2C_CODE) I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION(VAR (uint8, AUTOMATIC) u8Channel, VAR (uint8, AUTOMATIC) u8NumberOfBytes);
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cSlaveAddressMatchNotification)"!]
/**
* @brief            The call out configured by the user for address matching notifications.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_2 MISRA 2004 Required Rule 8.7, these object are used trough the entire I2c code*/
extern FUNC(void, I2C_CODE) I2C_SLAVE_ADDR_MATCH_NOTIFICATION(VAR (uint8, AUTOMATIC) u8Channel, VAR (I2c_DataDirectionType, AUTOMATIC) eDirection);
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cSlaveTransmitCompleteNotification)"!]
/**
* @brief            The call out configured by the user for slave transmission completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_2 MISRA 2004 Required Rule 8.7, these object are used trough the entire I2c code*/
extern FUNC(void, I2C_CODE) I2C_SLAVE_TRANSMIT_COMPLETE_NOTIFICATION(VAR (uint8, AUTOMATIC) u8Channel, VAR (uint8, AUTOMATIC) u8NumberOfBytes);
[!ENDIF!]

[!IF "node:exists(GeneralConfiguration/I2cSlaveReceiveCompleteNotification)"!]
/**
* @brief            The call out configured by the user for slave reception completion.
*/
/** @violates @ref CDD_I2c_Cfg_h_REF_2 MISRA 2004 Required Rule 8.7, these object are used trough the entire I2c code*/
extern FUNC(void, I2C_CODE) I2C_SLAVE_RECEIVE_COMPLETE_NOTIFICATION(VAR (uint8, AUTOMATIC) u8Channel, VAR (uint8, AUTOMATIC) u8NumberOfBytes);
[!ENDIF!]

#ifdef __cplusplus
}
#endif

#endif /* I2C_CFG_H */
