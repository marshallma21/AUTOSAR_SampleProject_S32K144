/**
*   @file    Lin_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - High level header of LIN driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
*   Dependencies         : 
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

#ifndef LIN_CFG_H
#define LIN_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_Cfg_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of Lin_MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_Cfg_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, Precautions shall be taken in order for defines not
* leading to unexpected behaviour when substitution is made.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!]
[!// check for duplicated channel id, or hw channel id

    [!VAR "tmp_ch_id" = "-1"!]
    [!VAR "tmp_hw_ch" = "-1"!]
    [!VAR "tmp_channel_index" = "0"!]
    [!VAR "max_channel_nr" = "count(LinChannel/*)"!]
    [!LOOP "LinChannel/*"!]
        [!VAR "i" = "0"!]
        [!VAR "tmp_channel_index" = "$tmp_channel_index + 1"!]
        [!VAR "tmp_ch_id" = "LinChannelId"!]
        [!VAR "tmp_hw_ch" = "substring-after(LinHwChannel,'_')"!]
        [!FOR "i" = "$tmp_channel_index + 1" TO "$max_channel_nr"!]
            [!IF "$tmp_ch_id = ../*[num:i($i)]/LinChannelId"!]
                [!ERROR!] Duplicate LinChannelId.[!ENDERROR!]
            [!ENDIF!]
            [!IF "$tmp_hw_ch = substring-after(../*[num:i($i)]/LinHwChannel,'_')"!]
                [!ERROR!] Duplicate LinHwChannel IDs.[!ENDERROR!]
            [!ENDIF!]
        [!ENDFOR!]
    [!ENDLOOP!]

[!// end check for duplicated channel id, or hw channel id
[!CODE!][!//
#include "EcuM_Cbk.h"
[!ENDCODE!][!//
[!ENDNOCODE!][!//

/**
* @violates @ref Lin_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Cfg.h
*/
[!NOCODE!][!//
[!INCLUDE "Lin_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//

/* Inclusion of incompatible header files shall be avoided */

#define LIN_VENDOR_ID_CFG                    43
#define LIN_MODULE_ID_CFG                    82
#define LIN_AR_RELEASE_MAJOR_VERSION_CFG     4
#define LIN_AR_RELEASE_MINOR_VERSION_CFG     2
/**
* @violates @ref Lin_Cfg_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_CFG  2
#define LIN_SW_MAJOR_VERSION_CFG             1
#define LIN_SW_MINOR_VERSION_CFG             0
#define LIN_SW_PATCH_VERSION_CFG             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and EcuM_Cbk header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_CFG != ECUM_CBK_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_CFG != ECUM_CBK_AR_RELEASE_MINOR_VERSION) \
      )
    #error "AutoSar Version Numbers of Lin_Cfg.h and EcuM_Cbk.h are different"
  #endif
  /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Lin_Cfg.h and Mcal.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief          Unified Interrupt.
* @details        This define was enable when the platform has only one
*                 interrupt for each LINFlex channel
*
* @api
*/
#define LIN_UNIFIED_INTERRUPTS [!IF "ecu:has('LinUnifiedInterrupts')"!][!IF "ecu:get('LinUnifiedInterrupts') = 'TRUE'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief   No of Channels configured.
*
*
* @api
*/
#define LIN_HW_MAX_MODULES [!"num:i(count(LinGlobalConfig/LinChannel/*))"!]U

/**
* @brief   Total number of available hardware lin channels.
*
*
* @api
*/
#define LIN_HW_MAX_AVAILABLE_MODULES [!"num:i(ecu:get('Lin.LinGlobalConfig.LinChannel'))"!]U

/**
* @brief   Max data length of the LIN SDU buffer to be returned.
*
* @api
*/
#define LIN_MAX_DATA_LENGTH  8U

/**
* @brief   Number of loops before returning LIN_E_TIMEOUT.
*
* @api
*/
#define  LIN_TIMEOUT_LOOPS ((uint32)[!"LinGeneral/LinTimeoutDuration"!]U)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*
* @api
*/
#define LIN_DEV_ERROR_DETECT      [!IF "LinGeneral/LinDevErrorDetect"!](STD_ON)  /* Enable Development Error Detection */[!ELSE!](STD_OFF) /* Disable Development Error Detection */[!ENDIF!]

/**
* @brief          Support for version info API.
* @details        Switches the Lin_GetVersionInfo() API ON or OFF.
*
* @api
*/
#define LIN_VERSION_INFO_API      [!IF "LinGeneral/LinVersionInfoApi"!](STD_ON)  /* Enable API Lin_GetVersionInfo      */[!ELSE!](STD_OFF) /* Disable API Lin_GetVersionInfo     */[!ENDIF!]

/**
* @brief          Enable Non-Autosar API for Dual-Clock support.
* @details        Enable/Disable API Lin_SetClockMode() to set the
*                 clock to be used by the LIN driver (Normal clock: default mode;
*                 Alternate clock: when the driver is in Low-Power mode).
*                 This can be set to STD_ON only if it is activated from xdm file:
*                 LinClockRef_Alternate is enable.
*
* @api
*/
[!VAR "DualClockEnabled"= "'false'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
[!IF "(node:exists(LinClockRef_Alternate))"!][!//
[!VAR "DualClockEnabled"= "'true'"!]
[!ENDIF!][!//
[!ENDLOOP!][!//

#define LIN_DUAL_CLOCK_MODE [!IF "$DualClockEnabled = 'true'"!] (STD_ON) /* Enable API Lin_SetClockMode */ [!ELSE!] (STD_OFF) /* Disable API Lin_SetClockMode */ [!ENDIF!][!//

/**
* @brief          Disable Frame Timeout Feature.
* @details        When NonAutosar/LinDisableFrameTimeout == STD_ON,
*                 the LIN Master will accept the frame that is longer than TFrame_Maximum.
*
* @api
*/
#define LIN_DISABLE_FRAME_TIMEOUT   [!IF "NonAutosar/LinDisableFrameTimeout"!](STD_ON)  /* The LIN Master will accept the frame that is longer than TFrame_Maximum. */[!ELSE!](STD_OFF) /* The master will not accept the frame that is longer than TFrame_Maximum. */[!ENDIF!]

[!NOCODE!]
[!CODE!]
/**
* @brief          Link Lin channels symbolic names with Lin channel IDs.
* @details        Link Lin channels symbolic names with Lin channel IDs.
*
* @api
*/
[!ENDCODE!]
[!FOR "index" = "0" TO "num:i(ecu:get('Lin.LinGlobalConfig.LinChannel'))-1"!][!//
    [!VAR "MaxHwChannels" = "string((ecu:list('Lin.LinGlobalConfig.LinChannel.LinHwChannel'))[$index+1])"!][!//
    [!VAR "ChannelFound" = "0"!][!//
    [!LOOP "LinGlobalConfig/LinChannel/*"!][!//
            [!VAR "HardwareChannel" = "string(LinHwChannel)"!][!//
            [!IF "$MaxHwChannels = $HardwareChannel"!][!//
                [!IF "$ChannelFound = 0"!][!//
                    [!CODE!][!//

#define [!"$MaxHwChannels"!]    [!"substring-after(LinHwChannel,'_')"!]U[!//

                    [!ENDCODE!][!//
                    [!VAR "ChannelFound" = "1"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]

/**
* @brief          Symbolic names for configured channels.
* @details        Symbolic names for configured channels.
*
* @api
*/
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
/**
* @violates @ref Lin_Cfg_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LinConf_LinChannelConfiguration_[!"node:name(.)"!]         [!"LinChannelId"!]
[!ENDLOOP!][!//

/**
* @brief   Switches the Production Error Detection and Notification OFF
*
* @api
*/
[!NOCODE!]
[!VAR "LinDemErrorEnable" = "'false'"!]
[!IF "NonAutosar/LinDisableDemReportErrorStatus ='false'"!][!//
    [!IF "node:exists(LinDemEventParameterRefs)"!]
            [!VAR "LinDemErrorEnable" = "'true'"!]
        [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]

#define LIN_DISABLE_DEM_REPORT_ERROR_STATUS   [!IF "$LinDemErrorEnable"!](STD_OFF)  /* Enable Production Error Detection */[!ELSE!](STD_ON) /* Disable Production Error Detection */[!ENDIF!]

#define LIN_PRECOMPILE_SUPPORT [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

[!MACRO "LinExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(LinGlobalConfig)"!][!//
[!CODE!][!//
/**
* @violates @ref Lin_Cfg_h_REF_3 Precautions shall be taken in order for
* defines not leading to unexpected behaviour when substitution is made.
*/
#define LIN_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Lin_ConfigType, LIN_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Lin_ConfigType, LIN_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "LinExportDriverConfiguration"!]
[!ENDIF!]

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          LIN channel configuration type structure.
* @details        This is the type of the external data structure containing
*                 the overall initialization data for one LIN Channel.
*                 A pointer to such a structure is provided to the LIN channel
*                 initialization routine for configuration of the LIN hardware
*                 channel.
*
* @api
*/
typedef struct
{
    VAR(uint8, LIN_VAR) u8LinChannelID;             /*!< Lin Channel ID */
    VAR(uint8, LIN_VAR) u8LinHwChannel;             /*!< LIN Hardware Channel.*/
    VAR(uint8, LIN_VAR) u8LinChannelWakeupSupport; /*!< Is wake-up supported by the LIN channel ?.*/
    VAR(EcuM_WakeupSourceType, LIN_VAR) LinChannelEcuMWakeupSource;    /*!< [LIN098] This parameter contains a reference to the Wakeup Source for this controller as defined in the ECU State Manager.*/
} Lin_StaticConfig_ChannelConfigType;

/**
* @brief          LIN channel configuration type structure.
* @details        This is the type of the external data structure containing
*                 the overall initialization data for one LIN Channel.
*                 A pointer to such a structure is provided to the LIN channel
*                 initialization routine for configuration of the LIN hardware
*                 channel.
*
* @api
*/
typedef struct
{
    P2CONST(Lin_StaticConfig_ChannelConfigType, LIN_VAR, LIN_APPL_CONST) pChannelConfigPC;  /* Pointer to precompile configuration structure */
    VAR(uint32, LIN_VAR) u32Baudrate;               /* LIN Baudrate value */
#if (LIN_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, LIN_VAR) u32Lin_BaudRate_RegValue;   /*!< LIN baudrate value.*/
    VAR(uint32, LIN_VAR) u32Lin_BaudRate_RegValue_Alternate;   /*!< LIN baudrate value with alternate clock.*/
#else
    VAR(uint32, LIN_VAR) u32Lin_BaudRate_RegValue;   /*!< LIN baudrate value.*/
#endif /* LIN_DUAL_CLOCK_MODE == STD_ON */
    VAR(uint8, LIN_VAR) u8LinChannelBreakLength;    /*!< These bits indicate the Break length in Master mode.*/
} Lin_ChannelConfigType;

/**
* @brief          LIN driver configuration type structure.
* @details        This is the type of the pointer to the external data
*                 LIN Channels.
*                 A pointer of such a structure is provided to the LIN driver
*                 initialization routine for configuration of the LIN hardware
*                 channel.
*
* @api
*
* @implements Lin_ConfigType_struct
*/
typedef struct
{
     /**
     * @brief     Hardware channel.
     * @details   Constant pointer of the constant external data
     *            structure containing the overall initialization data
     *            for all the LIN Channels.
     */
    CONSTP2CONST (Lin_ChannelConfigType,LIN_APPL_CONST,LIN_CONST) pLin_Channel[LIN_HW_MAX_MODULES];
} Lin_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                  EXTERNAL CONSTANTS
==================================================================================================*/

#define LIN_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Lin_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "Lin_MemMap.h"

[!NOCODE!][!//
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!VAR "nodeName" = "name(.)"!][!//
    [!CODE!][!//
extern CONST(Lin_StaticConfig_ChannelConfigType,LIN_CONST) Lin_[!"node:name(.)"!]_PC;
    [!ENDCODE!]
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
extern CONST(Mcal_DemErrorType,LIN_CONST) Lin_E_TimeoutCfg;
#endif /* LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */

#define LIN_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Lin_Cfg_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "Lin_MemMap.h"

#endif /* LIN_CFG_H */

#ifdef __cplusplus
}
#endif
