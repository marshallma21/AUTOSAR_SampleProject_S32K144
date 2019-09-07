[!NOCODE!][!//
/**
  @file    Wdg_PluginMacros.m
  @version 1.0.1

  @brief   AUTOSAR Wdg - plugin check.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform ARM
  Peripheral Wdog
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.1
  BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/

[!// Constant that defines the maximum number of Wdg instances
[!VAR "WdgMaxNumberOfInstances"="num:i(count(ecu:list('Wdg.WdgInstance')))"!]

[!// MACRO for defining which instances will be used
[!MACRO "WdgInstanceMacro","WdogInstance"!]
[!NOCODE!]
[!VAR "MacWdgFoundInstance"="0"!]
[!LOOP "WdgSettingsConfig/*"!]
       [!IF "node:value(./WdgInstance) = $WdogInstance"!]
       [!VAR "MacWdgFoundInstance"="1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
[!IF "$MacWdgFoundInstance = 1 "!][!/*
    */!]#define WDG_INSTANCE[!"substring-after($WdogInstance,'WDOG')"!] (STD_ON)
[!ELSE!][!/*
    */!]#define WDG_INSTANCE[!"substring-after($WdogInstance,'WDOG')"!] (STD_OFF)
[!ENDIF!]
[!ENDMACRO!]

[!// MACRO for checking that the Gpt callback has been set
[!MACRO "WdgCheckCbkNotification","WdogInstance"!]
[!NOCODE!]
[!LOOP "WdgSettingsConfig/*"!]
    [!IF "./WdgInstance = $WdogInstance"!]
        [!IF "node:exists(node:ref(./WdgExternalTriggerCounterRef)/GptNotification)"!]
            [!IF "node:ref(./WdgExternalTriggerCounterRef)/GptNotification != concat('Wdg_Cbk_GptNotification',substring-after($WdogInstance,'WDOG'))"!]
                [!ERROR!] The notification handler for [!"$WdogInstance"!] must be Wdg_Cbk_GptNotification[!"substring-after($WdogInstance,'WDOG')"!][!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!ERROR!] The channel notification for [!"$WdogInstance"!] must be set up and the notification handler must be Wdg_Cbk_GptNotification[!"substring-after($WdogInstance,'WDOG')"!][!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

[!ENDMACRO!]

[!// MACRO for defining mode configuration
[!MACRO "WdgModeConfig","WdgMode"!]
(uint32)( WDOG_ENABLED_U32 |  WDOG_RESERVED_BIT13_U32 | [!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgWindowMode'))"!]WDOG_TRIGGER_MODE_WINDOW_U32 | [!ELSE!]WDOG_TRIGGER_MODE_REGULAR_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgRunsInStopMode'))"!]WDOG_RUN_IN_HALT_U32 | [!ELSE!]WDOG_STOP_IN_HALT_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgRunsInDebugMode'))"!]WDOG_RUN_IN_DEBUG_U32 | [!ELSE!]WDOG_STOP_IN_DEBUG_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgRunsInWaitMode'))"!]WDOG_RUN_IN_WAIT_U32 | [!ELSE!]WDOG_STOP_IN_WAIT_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgOperationMode')) = 'Interrupt'"!]WDOG_INTERRUPT_ENABLED_U32 | [!ELSE!]WDOG_INTERRUPT_DISABLED_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgClockSelection')) = 'Bus_Clock'"!]WDOG_BUS_CLK_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgClockSelection')) = 'LPO_Clock'"!]WDOG_LPO_CLK_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgClockSelection')) = 'SOSC_Clock'"!]WDOG_SOSC_CLK_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgClockSelection')) = 'SIRC_Clock'"!]WDOG_SIRC_CLK_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgTestMode')) = 'TestModeDisabled'"!]WDOG_TEST_MODE_DISABLED_U32 |[!ENDIF!] [!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgTestMode')) = 'UserModeEnabled'"!]WDOG_USER_MODE_ENABLED_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgTestMode')) = 'TestModeLowByte'"!]WDOG_TEST_MODE_LOW_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgTestMode')) = 'TestModeHighByte'"!]WDOG_TEST_MODE_HIGH_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgPrescalerEnabled'))"!]WDOG_PRES_ENABLED_U32 | [!ELSE!]WDOG_PRES_DISABLED_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgAllowUpdates'))"!]WDOG_UPDATE_ENABLED_U32[!ELSE!]WDOG_UPDATE_DISABLED_U32[!ENDIF!][!/*
             */!] 
        ), /* WDG Control and configuration */
        (uint32)[!"num:inttohex(num:i(node:value(concat(concat('./',$WdgMode),'/WdgTimeoutPeriod')) * node:value(concat(concat('./',$WdgMode),'/WdgClockValue')) * 1000),8)"!],  /* Time-out config */
        (uint32)[!IF "node:value(concat(concat('./',$WdgMode),'/WdgWindowMode'))"!][!/*
                  */!][!"num:inttohex(num:i(node:value(concat(concat('./',$WdgMode),'/WdgWindowPeriod'))* node:value(concat(concat('./',$WdgMode),'/WdgClockValue')) * 1000),8)"!][!/*
            */!][!ELSE!][!"0"!][!ENDIF!], /* Window config */
        (boolean)[!IF "node:value(concat(concat('./',$WdgMode),'/WdgPrescalerEnabled'))"!]TRUE[!ELSE!]FALSE[!ENDIF!],
        (uint32)[!"node:value(concat(concat('./',$WdgMode),'/WdgClockValue'))"!] /* Internalwdgclocksource */
[!ENDMACRO!]

[!// MACRO for defining configuration sets
[!MACRO "WdgConfigSet","WdgWdogInstance", "WdgMisraRef", "WdgConfigType"!]
[!NOCODE!]
[!ENDNOCODE!]

[!LOOP "WdgSettingsConfig/*"!][!//
[!IF "node:value(./WdgInstance) = $WdgWdogInstance"!][!//
/** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. 
 */
[!IF "$WdgConfigType = 'PB'"!][!//
/** @violates @ref Wdg_PBcfg_c_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ELSEIF "$WdgConfigType = 'PC'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ELSE!][!//
/** @violates @ref Wdg_Lcfg_c_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ENDIF!]
CONST(Wdg_Wdog_ConfigType, WDG_CONST) Wdg_Wdog_OffModeSettings_Instance[!"substring-after($WdgWdogInstance,'WDOG')"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
        (uint32)( WDOG_DISABLED_U32 | WDOG_RESERVED_BIT13_U32 |[!IF "node:value(concat(concat('./',"WdgSettingsOff"),'/WdgAllowUpdates'))"!]WDOG_UPDATE_ENABLED_U32[!ELSE!]WDOG_UPDATE_DISABLED_U32[!ENDIF!]), /* WDG Control and configuration */
        (uint32)0x00000100, /* Timeout config */
        (uint32)0x00000000,  /* Window config */
        (boolean)FALSE,
        (uint32) 0x00000001 /* Internalwdgclocksource */
};

 /** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
  *   functions at file scope shall have internal linkage unless external linkage is required. 
  */
[!IF "$WdgConfigType = 'PB'"!][!//
/** @violates @ref Wdg_PBcfg_c_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ELSEIF "$WdgConfigType = 'PC'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ELSE!][!//
/** @violates @ref Wdg_Lcfg_c_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ENDIF!]
CONST(Wdg_Wdog_ConfigType, WDG_CONST) Wdg_Wdog_SlowModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    [!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsSlow'"!]
};


/** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. 
 */
[!IF "$WdgConfigType = 'PB'"!][!//
/** @violates @ref Wdg_PBcfg_c_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ELSEIF "$WdgConfigType = 'PC'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ELSE!][!//
/** @violates @ref Wdg_Lcfg_c_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
[!ENDIF!]
CONST(Wdg_Wdog_ConfigType, WDG_CONST) Wdg_Wdog_FastModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    [!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsFast'"!]
};

[!VAR "MacWdgNotificationValue"="node:value(concat('./../../WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgWdogInstance,'WDOG'))))"!]
/**
* @brief  This constant contains the configuration set for the postbuild time
*/
/** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */

CONST(Wdg_ConfigType, WDG_CONST)[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
        [!"node:value(./WdgDefaultMode)"!],
        WDG_IPW_INSTANCE[!"substring-after($WdgWdogInstance,'WDOG')"!],
        (Gpt_ChannelType)GptConf_GptChannelConfiguration_[!"text:split(./WdgExternalTriggerCounterRef ,'/')[5]"!],
        (uint32)[!"num:i(node:value(node:ref(./WdgExternalTriggerCounterRef)/GptChannelTickFrequency)div 1000)"!],
        { &Wdg_Wdog_OffModeSettings_Instance[!"substring-after($WdgWdogInstance,'WDOG')"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], &Wdg_Wdog_SlowModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], &Wdg_Wdog_FastModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]},
        [!IF "normalize-space($MacWdgNotificationValue) = 'NULL' or normalize-space($MacWdgNotificationValue) = 'NULL_PTR'"!]NULL_PTR[!ELSE!]&[!"$MacWdgNotificationValue"!][!ENDIF!] /* WdgCallbackNotification */
};
[!ENDIF!]
[!ENDLOOP!]
[!ENDMACRO!]

[!// MACRO for defining wich isrs are used configuration
[!MACRO "WdgNotificationMacro","WdgWdogInstance"!]
[!IF "(normalize-space(node:value(concat('WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgWdogInstance,'WDOG'))))) !='NULL_PTR') and (normalize-space(node:value(concat('WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgWdogInstance,'WDOG'))))) !='NULL')"!]
/**
 *   @brief External Notifications for Wdg Interrupt
 */[!CR!]
extern FUNC (void, WDG_CODE) [!"node:value(concat('WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgWdogInstance,'WDOG'))))"!](void);
[!ENDIF!]
[!ENDMACRO!]

[!// MACRO for defining which isrs are used configuration
[!MACRO "WdgIsr","WdgWdogInstance"!]
[!LOOP "WdgSettingsConfig/*"!][!//
[!IF "./WdgInstance = $WdgWdogInstance and node:value(./WdgInterruptContentEnable) = 'true'"!]

/**
* @brief  This variable will indicate if the ISR[!"substring-after($WdgWdogInstance,'WDOG')"!] is used
*/
#define  WDG_ISR[!"substring-after($WdgWdogInstance,'WDOG')"!]_USED
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!]

[!MACRO "WdgExporter","WdgWdogInstance","WdgConfigType"!]
    [!LOOP "WdgSettingsConfig/*"!][!//
    [!IF "./WdgInstance = $WdgWdogInstance"!][!//
extern CONST(Wdg_ConfigType, WDG_CONST) [!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!];
    [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDMACRO!]

[!MACRO "WdgExportDriverConfiguration"!]
[!NOCODE!][!//
[!CODE!][!//
/** 
 * @violates @ref Wdg_Cfg_h_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to...
 */
#define WDG_CONF_PB \
[!ENDCODE!][!//
[!VAR "num_confg" = "num:i(count(WdgSettingsConfig/*))"!][!//
[!VAR "num_confgIndex"="0"!][!//
[!LOOP "WdgSettingsConfig/*"!][!//
[!VAR "num_confgIndex" = "$num_confgIndex + 1"!][!//
[!VAR "configName" = "@name"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Wdg_ConfigType, WDG_CONST) [!"$configName"!]_[!"."!];[!IF "($variantIndex < $variantNumber) or ($num_confgIndex < $num_confg)"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Wdg_ConfigType, WDG_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!ENDNOCODE!]
