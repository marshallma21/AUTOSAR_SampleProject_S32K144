[!CODE!][!//
/**
*     @file       CDD_Crcu_Cfg.h
*     @implements CDD_Crcu_Cfg.h_Artifact
*     @version    1.0.1
*     
*     @brief      Crcu configuration header.
*     @details    This file is the CRC driver configuration header. This
*                 file is automatically generated, do not modify manually.
*     
*     @addtogroup CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project              : AUTOSAR 4.2 MCAL
*     Platform             : ARM
*     Peripheral           : CRCV2
*     Dependencies         : none
*     
*     Autosar Version      : 4.2.2
*     Autosar Revision     : ASR_REL_4_2_REV_0002
*     Autosar Conf.Variant :
*     SW Version           : 1.0.1
*     Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*     
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef CDD_CRCU_CFG_H
#define CDD_CRCU_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_Cfg_h_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported forexternal identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section Crcu_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
*          accessed from within a single function. These objects are used in various parts of the code
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crcu_Types.h"
[!IF "CrcuGeneral/CrcuDmaUsed"!][!//
#include "CDD_Mcl.h"
[!ENDIF!][!//
[!//
[!NOCODE!][!//
[!INCLUDE "Crcu_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_CFG_VENDOR_ID                   43
#define CRCU_CFG_AR_RELEASE_MAJOR_VERSION    4
#define CRCU_CFG_AR_RELEASE_MINOR_VERSION    2
#define CRCU_CFG_AR_RELEASE_REVISION_VERSION 2
#define CRCU_CFG_SW_MAJOR_VERSION            1
#define CRCU_CFG_SW_MINOR_VERSION            0
#define CRCU_CFG_SW_PATCH_VERSION            1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Crcu_Types.h header file are of the same vendor */
#if (CRCU_CFG_VENDOR_ID != CRCU_TYPES_VENDOR_ID)
    #error "CDD_Crcu_Cfg.h and Crcu_Types.h have different vendor IDs"
#endif
/* Check if current file and Crcu_Types.h header file are of the same Autosar version */
#if ((CRCU_CFG_AR_RELEASE_MAJOR_VERSION != CRCU_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (CRCU_CFG_AR_RELEASE_MINOR_VERSION != CRCU_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (CRCU_CFG_AR_RELEASE_REVISION_VERSION != CRCU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crcu_Cfg.h and Crcu_Types.h are different"
#endif
/* Check if current file and Crcu_Types.h header file are of the same Software version */
#if ((CRCU_CFG_SW_MAJOR_VERSION != CRCU_TYPES_SW_MAJOR_VERSION) || \
     (CRCU_CFG_SW_MINOR_VERSION != CRCU_TYPES_SW_MINOR_VERSION) || \
     (CRCU_CFG_SW_PATCH_VERSION != CRCU_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crcu_Cfg.h and Crcu_Types.h are different"
#endif

[!IF "CrcuGeneral/CrcuDmaUsed"!][!//
 /* Check if current file and Mcl.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CRCU_CFG_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (CRCU_CFG_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_Crcu_Cfg.h and CDD_Mcl.h are different"
    #endif
#endif
[!ENDIF!][!//

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!]
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and variant:size()<=1"!]
[!CODE!][!//
/**
* @brief        Crcu driver Pre-Compile configuration switch.
*
* @api
*/
#define CRCU_PRECOMPILE_SUPPORT                 (STD_ON)
[!ENDCODE!][!//
[!ELSE!]
[!CODE!][!//
/**
* @brief        Crcu driver Post-build configuration switch.
*
* @api
*/
#define CRCU_PRECOMPILE_SUPPORT                 (STD_OFF)
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!]

/**
*   @brief      Enables or disables the access to a hardware register from user mode
*
*   @note       Currently, no register protection mechanism is used for Crcu driver.
*/
#define CRCU_USER_MODE_SOFT_LOCKING             (STD_OFF)

/**
* @brief        Enable/Disable Development Error Detection.
*
* @api
*/
#define CRCU_DEV_ERROR_DETECT                   [!IF "CrcuGeneral/CrcuDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief        Function @p Crcu_GetVersionInfo() enable switch.
*
* @api
*/
#define CRCU_GET_VERSION_INFO_API               [!IF "CrcuGeneral/CrcuVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
*   @brief      Define number of channels per CRC hardware unit from resource file
*/
#define CRCU_NUM_CRC_CHANNELS_PER_HW_UNIT_U8    ((uint8)[!"ecu:get('Crcu.CrcChannelsPerHwUnit')"!]U)

/**
* @brief        Total number of available hardware Crc channels.
*
* @api
*
* @implements  CRCU_MAX_NUM_CRC_CHANNELS_define
*/
#define CRCU_MAX_NUM_CRC_CHANNELS               ([!"num:i(count(ecu:list('Crcu.CrcHwChannels')))"!]U)

/**
* @brief        DMA enable switch. Also defines the presence of function Crcu_AsyncCalculateCrc() in code.
*
* @api
*
* @implements  CRCU_DMA_USED_define
*/
#define CRCU_DMA_USED                           [!IF "CrcuGeneral/CrcuDmaUsed"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief        Symbolic names for the Crcu channels
*
* @api
*/
[!NOCODE!][!//
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "CrcuConfig/CrcuChannel/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "Matchcounter" = "0"!]
        [!VAR "Name" = "node:name(.)"!]
        [!LOOP "../../../*/CrcuChannel/*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                [!IF "($Name = node:name(.))"!]
                    [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$Matchcounter = 1"!]
            [!CODE!][!//
/** @violates @ref Crcu_Cfg_h_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define  CrcuConf_CrcuChannel_[!"node:name(.)"!]                       ([!"CrcuChannelId"!]U)[!CR!][!CR!][!/*
            */!][!ENDCODE!]
        [!ELSE!]
            [!ERROR!]
                [!"node:name(.)"!] Crcu channel name is repeating in more than one Crcu Channel Config Set.
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!][!//

/**
* @brief          Symbolic names for the Crcu channel configurations
*
* @api
*/
[!NOCODE!][!//
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "CrcuConfig/CrcuChannelConfig/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "Matchcounter" = "0"!]
        [!VAR "Name" = "node:name(.)"!]
        [!LOOP "../../../*/CrcuChannelConfig/*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                [!IF "($Name = node:name(.))"!]
                    [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$Matchcounter = 1"!]
            [!CODE!][!//
/** @violates @ref Crcu_Cfg_h_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define  CrcuConf_CrcuChannelConfig_[!"node:name(.)"!]                       ([!"CrcuChannelConfigId"!]U)[!CR!][!CR!][!/*
            */!][!ENDCODE!]
        [!ELSE!]
            [!ERROR!]
                [!"node:name(.)"!] Crcu channel configuration name is repeating in more than one Crcu Channel Config Set.
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!][!//

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the CRCU driver code can be executed from both supervisor and user mode.
*/
[!IF "CrcuGeneral/CrcuEnableUserModeSupport"!]
#define CRCU_ENABLE_USER_MODE_SUPPORT   (STD_ON)

/**
* @brief Support for REG_PROT in CRCV2 IP.
*        If the current platform implements REG_PROT for CRCV2 IP, this parameter will be defined, and will enable REG_PROT configuration for CRCV2 IP in CRCU drvier
*/
#define CRCU_CRCV2_REG_PROT_AVAILABLE
[!ELSE!]
#define CRCU_ENABLE_USER_MODE_SUPPORT   (STD_OFF)
[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef CRCU_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CRCU_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Crcu in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == CRCU_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef CRCU_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (STD_ON == CRCU_DMA_USED)
/**
* @brief        Crcu async calculate Crc complete notification type.  The callback notification shall be configurable
*               as pointer to user defined function within the configuration structure.
*
*/
typedef P2FUNC(void, CRCU_APPL_CODE, Crcu_AsyncCalculateCrcNotifType)
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId,
    VAR(Crcu_ValueType,     AUTOMATIC) crc
);
#endif /* (STD_ON == CRCU_DMA_USED) */

/**
 * @brief       Structure that defines a CRCU channel.
 *
 * */
typedef struct
{
    CONST(Crcu_Crcv2_ChannelType,          CRCU_CONST) crcChannel;                   /**< @brief Crc channel assigned to the CRCU logical channel     */
#if (STD_ON == CRCU_DMA_USED)
    CONST(Mcl_ChannelType,                 CRCU_CONST) dmaChannel;                   /**< @brief Dma channel assigned to the CRCU logical channel     */
    CONST(Crcu_AsyncCalculateCrcNotifType, CRCU_CONST) pfCrcuAsyncCalculateCrcNotif; /**< @brief Notification for completion of async crc calculation */
#endif /* (STD_ON == CRCU_DMA_USED) */
} Crcu_ChannelType;

/**
 * @brief       Structure that defines the format of the Crcu driver configuration data.
 *
 * @implements  Crcu_ConfigType_struct
 * */
typedef struct
{
    CONST(Crcu_ChannelIdType,           CRCU_CONST) crcuNumChannels;              /**< @brief Number of Crcu channels               */
    CONST(Crcu_ChannelConfigIdType,     CRCU_CONST) crcuNumChannelConfigs;        /**< @brief Number of Crcu channel configurations */
    CONST(Crcu_ChannelType,             CRCU_CONST) (*pCrcuChannelList)[];        /**< @brief List of Crcu channels                 */
    CONST(Crcu_Crcv2_ChannelConfigType, CRCU_CONST) (*pCrcv2ChannelConfigList)[]; /**< @brief List of Crcu channel configurations   */
}Crcu_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CRCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Crcu_Cfg_h_REF_1 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

[!MACRO "CrcuExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(CrcuConfig)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
[!CODE!][!//
/** @violates @ref Crcu_Cfg_h_REF_3 Objects shall be defined at block scope */
extern CONST(Crcu_ConfigType, CRCU_CONST) [!"$configName"!]_[!"."!];[!CR!][!//
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!][!//
/** @violates @ref Crcu_Cfg_h_REF_3 Objects shall be defined at block scope */
extern CONST(Crcu_ConfigType, CRCU_CONST) [!"$configName"!];[!CR!][!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
[!CALL "CrcuExportDriverConfiguration"!][!//
[!ENDIF!]

#define CRCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Crcu_Cfg_h_REF_1 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* CDD_CRCU_CFG_H */

/** @} */
[!ENDCODE!][!//
