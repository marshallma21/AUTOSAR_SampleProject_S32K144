[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ICU_PLUGINMACRO_42_M'))"!]
[!VAR "ICU_PLUGINMACRO_42_M"="'true'"!]
[!NOCODE!][!//
/**
  @file    Icu_PluginMacros.m
  @version 1.0.1

  @brief   AUTOSAR Icu - plugin check.
  @details Version checks.

  Project AUTOSAR 4.2 MCAL
  Patform ARM
  Peripheral FTM PORT_CI LPIT LPTMR
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
[!// MACRO for creating the mapping between hardware channels and logical channels
[!MACRO "ICU_VARIABLES"!]
[!NOCODE!]
    [!VAR "ICU_CHANNELS"   = "num:i(400)"!]
    [!VAR "OutNumIcuChannels" = "num:i(count(IcuChannel/*))"!]
    [!VAR "OutNumIcuChannelsUsingFtm" = "0"!]
    [!VAR "OutNumIcuChannelsUsingPort"  = "0"!]
    [!VAR "OutNumIcuChannelsUsingLpit"  = "0"!]
    [!VAR "OutNumIcuChannelsUsingLptmr"  = "0"!]

    [!LOOP "IcuChannel/*"!][!/*
        [!//Update variables storing number of Icu channels using either Ftm, Port
        */!][!IF "contains(IcuHwIP,'FTM')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingFtm" = "$OutNumIcuChannelsUsingFtm + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'PORT')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingPort" = "$OutNumIcuChannelsUsingPort + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'LPIT')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingLpit" = "$OutNumIcuChannelsUsingLpit + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'LPTMR')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingLptmr" = "$OutNumIcuChannelsUsingLptmr + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDLOOP!]

    [!VAR "FTM_1_CHANNELS_START_INDEX"    = "num:i(8)"!]
    [!VAR "FTM_2_CHANNELS_START_INDEX"    = "num:i(16)"!]
    [!VAR "FTM_3_CHANNELS_START_INDEX"    = "num:i(24)"!]
    [!VAR "FTM_4_CHANNELS_START_INDEX"    = "num:i(32)"!]
    [!VAR "FTM_5_CHANNELS_START_INDEX"    = "num:i(40)"!]
    [!VAR "FTM_6_CHANNELS_START_INDEX"    = "num:i(48)"!]
    [!VAR "FTM_7_CHANNELS_START_INDEX"    = "num:i(56)"!]
    [!VAR "PORT_0_CHANNELS_START_INDEX"   = "num:i(64)"!]
    [!VAR "PORT_1_CHANNELS_START_INDEX"   = "num:i(96)"!]
    [!VAR "PORT_2_CHANNELS_START_INDEX"   = "num:i(128)"!]
    [!VAR "PORT_3_CHANNELS_START_INDEX"   = "num:i(160)"!]
    [!VAR "PORT_4_CHANNELS_START_INDEX"   = "num:i(192)"!]
    [!VAR "LPIT_CHANNELS_START_INDEX"     = "num:i(224)"!]
    [!VAR "LPTMR_CHANNELS_START_INDEX"    = "num:i(228)"!]
    [!VAR "ICU_CHANNELS"   = "num:i(229)"!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for creating the mapping between hardware channels and logical channels
[!MACRO "ICU_GENERATE_HW_MAPPING","VARIANT", "MISRA_REF"!]
[!SELECT "IcuConfigSet"!]
/*
 * @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
CONST(Icu_ChannelType,ICU_CONST) Icu_InitHWMap_[!"$VARIANT"!][ICU_MAX_HW_CHANNELS] =[!CR!][!/*
*/!]{[!CR!][!/*
   */!][!FOR "idx" = "0" TO "$ICU_CHANNELS - 1"!][!/*
        */!][!VAR "found" = "'false'"!][!/*
        */!][!LOOP "./IcuChannel/*"!][!/*
            */!][!IF "contains(IcuHwIP,'FTM')"!][!/*
                */!][!IF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_0'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_1'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_1_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_2'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_2_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_3'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_3_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_4'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_4_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_5'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_5_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_6'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_6_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)) = 'FTM_7'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+$FTM_7_CHANNELS_START_INDEX"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "contains(IcuHwIP,'PORT')"!][!/*
                */!][!IF "(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule)) = 'PORT_0'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuPortChannelRef)/IcuPortChannel),'CH_')+$PORT_0_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule)) = 'PORT_1'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuPortChannelRef)/IcuPortChannel),'CH_')+$PORT_1_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule)) = 'PORT_2'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuPortChannelRef)/IcuPortChannel),'CH_')+$PORT_2_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule)) = 'PORT_3'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuPortChannelRef)/IcuPortChannel),'CH_')+$PORT_3_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule)) = 'PORT_4'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuPortChannelRef)/IcuPortChannel),'CH_')+$PORT_4_CHANNELS_START_INDEX"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "contains(IcuHwIP,'LPIT')"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuLpitChannelRef)/IcuLpitChannel),'CH_')+$LPIT_CHANNELS_START_INDEX"!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "contains(IcuHwIP,'LPTMR')"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcuLptmrChannelRef)/IcuLptmrChannel),'CH_')+$LPTMR_CHANNELS_START_INDEX"!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "num:i($ch)=$idx"!][!/*
                */!][!WS "4"!][!"node:name(.)"!][!/*
                */!][!VAR "found" = "'true'"!][!/*
            */!][!ENDIF!][!/*
            */!][!ENDLOOP!][!/*
            */!][!IF "$found='false'"!][!/*
          */!][!WS "4"!]NoIcuChannel[!/*
           */!][!ENDIF!][!/*

        */!][!IF "$idx < $ICU_CHANNELS - 1"!],[!ELSE!] [!ENDIF!][!/*

        */!][!IF "$idx < $FTM_1_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_0_CH_[!"$idx"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $FTM_2_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_1_CH_[!"num:i($idx - $FTM_1_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $FTM_3_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_2_CH_[!"num:i($idx - $FTM_2_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $FTM_4_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_3_CH_[!"num:i($idx - $FTM_3_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $FTM_5_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_4_CH_[!"num:i($idx - $FTM_4_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $FTM_6_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_5_CH_[!"num:i($idx - $FTM_5_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $FTM_7_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_6_CH_[!"num:i($idx - $FTM_6_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $PORT_0_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to FTM_7_CH_[!"num:i($idx - $FTM_7_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $PORT_1_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to PORT_0_CH_[!"num:i($idx - $PORT_0_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $PORT_2_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to PORT_1_CH_[!"num:i($idx - $PORT_1_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $PORT_3_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to PORT_2_CH_[!"num:i($idx - $PORT_2_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $PORT_4_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to PORT_3_CH_[!"num:i($idx - $PORT_3_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $LPIT_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to PORT_4_CH_[!"num:i($idx - $PORT_4_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $LPTMR_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to LPIT_0_CH_[!"num:i($idx - $LPIT_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$idx < $ICU_CHANNELS"!][!/*
            */!] /* maps to LPTMR_0_CH_[!"num:i($idx - $LPTMR_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDFOR!][!/*
    */!]};
[!ENDSELECT!]
[!ENDMACRO!]

[!// MACRO for generating the notification function prototype
[!MACRO "ICU_GENERATE_NOTIFICATION_FUNCTIONS_PROTOTYPE", "MISRA_REF"="'Icu_PBCfg_c_5'"!]
[!NOCODE!]
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "found" = "'false'"!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuChannel/*"!]
        [!VAR "a" = "IcuMeasurementMode"!]
        [!IF "(contains($a,'ICU_MODE_TIMESTAMP') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL_PTR') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL'))"!]
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "Matchcounter" = "0"!]
            [!VAR "Notification" = "IcuTimestampMeasurement/IcuTimestampNotification"!]
            [!LOOP "../../IcuChannel/*"!] [!//All notifications from all configurations
                [!VAR "a" = "IcuMeasurementMode"!]
                [!IF "(contains($a,'ICU_MODE_TIMESTAMP') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL_PTR')and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL'))"!]
                    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                        [!IF "($Notification = IcuTimestampMeasurement/IcuTimestampNotification)"!]
                             [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$Matchcounter = 1"!]
                  [!IF "$found = 'false'"!]
                      [!VAR "found" = "'true'"!]
                      [!CODE!]
/**
 *   @brief External Notifications for Timestamp
 */[!/*
                       */!][!CR!][!ENDCODE!]
                 [!ENDIF!]
                 [!CODE!]
/**
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, ICU_CODE) [!"IcuTimestampMeasurement/IcuTimestampNotification"!](void);[!CR!]
                [!ENDCODE!][!//
            [!ENDIF!]
        [!ENDIF!]
     [!ENDLOOP!]
    [!ENDSELECT!]

    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "found" = "'false'"!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuChannel/*"!]
        [!VAR "a" = "IcuMeasurementMode"!]
        [!IF "(contains($a,'ICU_MODE_SIGNAL_EDGE_DETECT') and (IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR'))"!]
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "Matchcounter" = "0"!]
            [!VAR "Notification" = "IcuSignalEdgeDetection/IcuSignalNotification"!]
            [!LOOP "../../IcuChannel/*"!] [!//All notifications from all configurations
                [!VAR "a" = "IcuMeasurementMode"!]
                [!IF "(contains($a,'ICU_MODE_SIGNAL_EDGE_DETECT') and (IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR'))"!]
                    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                        [!IF "($Notification = IcuSignalEdgeDetection/IcuSignalNotification)"!]
                             [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$Matchcounter = 1"!]
                [!IF "$found = 'false'"!]
                    [!VAR "found" = "'true'"!]
                     [!CODE!][!//
[!CR!]/**
 *   @brief External Notifications for Edge Detection
 */[!/*
          */!][!CR!][!ENDCODE!]
                [!ENDIF!]
                [!CODE!]
/**
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, ICU_CODE) [!"IcuSignalEdgeDetection/IcuSignalNotification"!](void);[!CR!]
                [!ENDCODE!][!//
            [!ENDIF!]
        [!ENDIF!]
     [!ENDLOOP!]
    [!ENDSELECT!]

    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "found" = "'false'"!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuChannel/*"!]
        [!IF "node:exists(IcuOverflowNotification)"!]
         [!IF "(IcuOverflowNotification != 'NULL_PTR') and (IcuOverflowNotification != 'NULL')"!]
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "Matchcounter" = "0"!]
            [!VAR "Notification" = "IcuOverflowNotification"!]
            [!LOOP "../../IcuChannel/*"!] [!//All notifications from all configurations
          [!IF "node:exists(IcuOverflowNotification)"!]
                [!IF "(IcuOverflowNotification != 'NULL_PTR')and (IcuOverflowNotification != 'NULL')"!]
                    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                        [!IF "($Notification = IcuOverflowNotification)"!]
                             [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
          [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$Matchcounter = 1"!]
                  [!IF "$found = 'false'"!]
                      [!VAR "found" = "'true'"!]
                      [!CODE!]
/**
 *   @brief  Overflow notification handlers
 */[!/*
                          */!][!CR!][!ENDCODE!]
                   [!ENDIF!]
                   [!CODE!]
/**
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, ICU_CODE) [!"IcuOverflowNotification"!](void);[!CR!]
                  [!ENDCODE!][!//
              [!ENDIF!]
        [!ENDIF!]
          [!ENDIF!]
     [!ENDLOOP!]
    [!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!]


[!// MACRO for creating the configuration pointer(s)
[!MACRO "ICU_GENERATE_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]
[!SELECT "IcuConfigSet"!][!//
[!VAR "count" = "count(IcuChannel/*)"!][!//
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
/*
 *  @brief    [!"$VARIANT"!] Default Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_ChannelConfigType, ICU_CONST) Icu_InitChannel_[!"$VARIANT"!][[!"num:i(count(IcuChannel/*))"!]]=
 {
 [!FOR "x" = "0" TO "num:i(count(IcuChannel/*))"!][!/*
  */!][!LOOP "IcuChannel/*"!][!/*
    */!][!VAR "Loop"="num:i($LoopVar)"!][!/*
    */!][!IF "IcuChannelId = $Loop"!][!/*
    */!][!WS "8"!]/* [!"node:name(.)"!]*/
        {[!CR!][!/*
        */!][!WS "12"!]([!IF "IcuWakeupCapability"!]((Icu_ParamType)ICU_WAKEUP_CAPABLE << ICU_WAKEUP_SHIFT) | \[!CR!][!WS "12"!][!ENDIF!][!/*
        */!](Icu_ParamType)((Icu_ParamType)[!"IcuDefaultStartEdge"!] << ICU_EDGE_PARAM_SHIFT)),[!CR!][!/*

        */!][!IF "node:value(IcuHwIP) = 'FTM'"!][!/*
                */!][!VAR "channelFTM" = "concat(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule),concat('_',node:value(node:ref(IcuFtmChannelRef)/IcuFtmChannel)))"!][!/*
                */!][!IF "not(ecu:has(concat('Icu.ChannelType.',$channelFTM)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"$channelFTM"!] do not supported, refer resource to set correctly[!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule),'_')),node:value(node:ref(IcuFtmChannelRef)/IcuFtmChannel))))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelFTM"!] ) from config set [!"node:name(../../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
                  */!][!IF "(node:ref(IcuFtmChannelRef)/IcuFtmChannel) = concat('CH_',(substring-after((node:ref(IcuFtmChannelRef)/IcuFtmChannel),'CH_')+1))"!][!/*
                      */!][!ERROR!] From variant "[!"variant:name( )"!]",Pair channel available when selecting signal measurement (for signal measurement on a channel FTM_hwModule_CH_n, the pair channel FTM_hwModule_CH_n+1 shall not be in the configuration.[!ENDERROR!][!/*
                  */!][!ENDIF!][!/*
                */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "node:value(IcuHwIP) = 'PORT'"!][!/*
                */!][!VAR "channelPort" = "concat(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule),concat('_',node:value(node:ref(IcuPortChannelRef)/../../IcuPortChannels/*/IcuPortChannel)))"!][!/*
                */!][!IF "not(ecu:has(concat('Icu.ChannelType.',$channelPort)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelPort"!] ) is not supported on the hardware; refer to the resource file to configure an existing channel.[!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule),'_')),node:value(node:ref(IcuPortChannelRef)/IcuPortChannel))))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelPort"!] ) from config set [!"node:name(../../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "node:value(IcuHwIP) = 'LPIT'"!][!/*
                */!][!VAR "channelLPIT" = "concat(node:value(node:ref(IcuLpitChannelRef)/../../IcuLpitModule),concat('_',node:value(node:ref(IcuLpitChannelRef)/../../IcuLpitChannels/*/IcuLpitChannel)))"!][!/*
                */!][!IF "not(ecu:has(concat('Icu.ChannelType.',$channelLPIT)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelLPIT"!] ) is not supported on the hardware; refer to the resource file to configure an existing channel.[!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcuLpitChannelRef)/../../IcuLpitModule),'_')),node:value(node:ref(IcuLpitChannelRef)/IcuLpitChannel))))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelLPIT"!] ) from config set [!"node:name(../../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "IcuDefaultStartEdge != 'ICU_RISING_EDGE'"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",LPIT channel what was configed for [!"node:name(.)"!] do not support for another different from RISING EDGE [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "node:value(IcuHwIP) = 'LPTMR'"!][!/*
                */!][!VAR "channelLPTMR" = "concat(node:value(node:ref(IcuLptmrChannelRef)/../../IcuLptmrModule),concat('_',node:value(node:ref(IcuLptmrChannelRef)/../../IcuLptmrChannels/*/IcuLptmrChannel)))"!][!/*
                */!][!IF "not(ecu:has(concat('Icu.ChannelType.',$channelLPTMR)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelLPTMR"!] ) is not supported on the hardware; refer to the resource file to configure an existing channel.[!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcuLptmrChannelRef)/../../IcuLptmrModule),'_')),node:value(node:ref(IcuLptmrChannelRef)/IcuLptmrChannel))))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] From variant "[!"variant:name( )"!]",[!"node:name(.)"!]( [!"$channelLPTMR"!] ) from config set [!"node:name(../../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!WS "12"!](Icu_MeasurementModeType)[!"IcuMeasurementMode"!],[!CR!][!/*

        */!][!WS "12"!](Icu_MeasurementSubModeType)[!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'"!]0U[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!"IcuTimestampMeasurement/IcuTimestampMeasurementProperty"!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!"IcuSignalMeasurement/IcuSignalMeasurementProperty"!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'"!][!"IcuDefaultStartEdge"!][!ENDIF!],[!CR!][!/*

            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!WS "12"!]NULL_PTR[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'"!][!WS "12"!]NULL_PTR[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
                */!][!IF "IcuTimestampMeasurement/IcuTimestampNotification!='NULL_PTR'"!][!/*
                    */!][!WS "12"!]&[!"IcuTimestampMeasurement/IcuTimestampNotification"!][!/*
                */!][!ELSE!][!/*
                    */!][!WS "12"!]NULL_PTR[!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'"!][!/*
                */!][!IF "IcuSignalEdgeDetection/IcuSignalNotification!='NULL_PTR'"!][!/*
                    */!][!WS "12"!]&[!"IcuSignalEdgeDetection/IcuSignalNotification"!][!/*
                */!][!ELSE!][!/*
                    */!][!WS "12"!]NULL_PTR[!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!],
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
[!/*     */!][!WS "12"!](Mcl_ChannelType)[!IF "IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'and IcuDMAChannelEnable = 'true'"!][!/*
              */!][!"node:value(node:ref(IcuDMAChannelRef)/MclDMAChannelId)"!],[!/* MCL DMA logical Channel
              */!][!IF "node:exists(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif)"!] [!/* Validation for Notification function
                 */!][!IF "(node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) = 'NULL_PTR') or (node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) = 'NULL')"!][!/*
                        */!][!ERROR!] From variant "[!"variant:name( )"!]","[!"node:path(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif)"!]" need to be configured for DMA Channels that are linked to "[!"node:name(.)"!]". The name of the notification shall be &lt;IcuChannelName&gt;_MclDmaTransferCompletionNotif e.g [!"node:name(.)"!]_MclDmaTransferCompletionNotif[!ENDERROR!][!/*
                */!][!ELSEIF "node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) != concat(node:name(.),'_MclDmaTransferCompletionNotif')"!][!/*
                        */!][!ERROR!] From variant "[!"variant:name( )"!]","[!"node:path(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif)"!]" name in "[!"node:name(.)"!]" must be [!"node:name(.)"!]_MclDmaTransferCompletionNotif[!ENDERROR!][!/*
                  */!][!ENDIF!][!/*
                */!][!ELSE!][!/*
                  */!][!ERROR!] From variant "[!"variant:name( )"!]","[!"node:path(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif)"!]" need to be configured for DMA Channels that are linked to "[!"node:name(.)"!]" [!ENDERROR!][!/*
              */!][!ENDIF!][!/*
              */!][!IF "node:ref(IcuDMAChannelRef)/DmaSource0 != 'NOT_USED'"!][!/* Validation for DMA source
                  */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource0),'FTM'),'_')!=substring-after(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule),'FTM_')"!][!/*
                      */!][!ERROR!] From variant "[!"variant:name( )"!]",Dma Source current is "[!"node:value(node:ref(IcuDMAChannelRef)/DmaSource0)"!]" which shall be "FTM_[!"substring-after(node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule),'FTM_')"!]_[!"node:value(node:ref(IcuFtmChannelRef)/IcuFtmChannel)"!]" [!ENDERROR!][!/*
                  */!][!ENDIF!][!/*
              */!][!ELSE!][!/*
                  */!][!ERROR!] From variant "[!"variant:name( )"!]",Dma Source need to be configured - For [!"node:ref(IcuDMAChannelRef)"!] set DMA Channel Enable[!ENDERROR!][!/*
              */!][!ENDIF!][!/*
           */!][!ELSE!]NoMclDmaChannel,[!/*
      */!][!ENDIF!]
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
[!/*   */!][!IF "node:exists(IcuOverflowNotification)"!][!/*
            */!][!WS "12"!][!IF "IcuOverflowNotification!= 'NULL_PTR'"!]&[!ENDIF!][!"IcuOverflowNotification"!][!/*
        */!][!ELSE!][!/*
            */!][!WS "12"!]NULL_PTR[!/*
        */!][!ENDIF!],
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
            (Icu_WakeupValueType)[!/*
            */!][!IF "IcuWakeupCapability"!][!/*
                */!]((uint32)((uint32)1U<<[!"as:ref(IcuWakeup/IcuChannelWakeupInfo)/EcuMWakeupSourceId"!]))[!/*
            */!][!ELSE!][!/*
                */!]0U[!/*
            */!][!ENDIF!][!CR!]
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        }[!IF "$idx!=$count"!],[!CR!][!ENDIF!][!/*
        */!][!VAR "idx" = "$idx + 1"!][!/*
        */!][!ENDIF!][!/*
  */!][!ENDLOOP!][!/*
*/!][!VAR "LoopVar"="$LoopVar + 1"!][!/*
*/!][!ENDFOR!][!CR!]
 };

[!ENDSELECT!]
[!ENDMACRO!]

[!// MACRO for creating the IP configuration pointer(s)
[!MACRO "ICU_GENERATE_IP_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'", "MISRA_REF_1"="'Icu_PBCfg_c_4'"!]
[!SELECT "IcuConfigSet"!][!//
[!CALL "ICU_VARIABLES"!][!//

[!IF "num:i($OutNumIcuChannelsUsingFtm)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default FTM Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_Ftm_ChannelConfigType, ICU_CONST) Icu_Ftm_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingFtm)"!]] =
 {
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'FTM')"!]
    /** @brief [!"node:name(.)"!] */
    {
        /** @brief Ftm HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!VAR "FtmMod" = "node:value(node:ref(IcuFtmChannelRef)/../../IcuFtmModule)"!][!/*
        */!][!VAR "FtmChannel" = "node:value(node:ref(IcuFtmChannelRef)/IcuFtmChannel)"!][!/*
        */!][!WS "8"!]ICU_[!"$FtmMod"!]_[!"$FtmChannel"!],
        /** @brief Ftm channel configuration parameters */[!CR!][!/*
        */!][!WS "8"!]((Icu_Ftm_ControlType)((Icu_Ftm_ControlType)[!"node:value(node:ref(IcuFtmChannelRef)/Icu_FlexTimerFilter)"!]U << ICU_FTM_FILTER_SHIFT_U32)[!/*
        */!][!IF "node:ref(IcuFtmChannelRef)/IcuFreezeEnable = 'true'"!][!/*
            */!][!CR!][!WS "8"!]| (Icu_Ftm_ControlType)((Icu_Ftm_ControlType)1U << ICU_FTM_FREEZE_SHIFT_U32)[!/*
        */!][!ENDIF!][!/*
        */!][!IF "IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'and IcuDMAChannelEnable = 'true'"!][!/*
            */!][!CR!][!WS "8"!]| (Icu_Ftm_ControlType)((Icu_Ftm_ControlType)ICU_FTM_DMA_ENABLE_U32 << ICU_FTM_DMA_ENABLE_SHIFT_U32)[!/*
        */!][!ENDIF!]),[!/*
        */!][!CR!][!WS "8"!](uint8)[!"IcuDefaultStartEdge"!],[!/*
        */!][!CR!][!WS "8"!](uint8)[!"IcuMeasurementMode"!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingFtm))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };

 /*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_Ftm_GlobalConfigurationType,ICU_CONST) Icu_Ftm_GlobalConfiguration_[!"$VARIANT"!]=
 {
/* Icu_Ftm_GlobalConfigClkSrc */
    [!LOOP "IcuFtm/*"!][!/*
     */!][!IF "node:value(./IcuFtmModule) = 'FTM_0'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 0U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_1'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 1U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_2'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 2U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_3'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 3U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_4'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 4U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_5'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 5U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_6'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 6U))) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_7'"!][!/*
        */!][!WS "4"!]((uint16)(((uint16)[!"concat(node:value(./Icu_FlexTimer_ClockSource),'_U32')"!]) << (ICU_FTM_CLK_CONFIG_WIDTH_U32 * 7U))) |\[!CR!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!WS "4"!]0x0U,[!CR!]
/* Icu_Ftm_GlobalConfigPrescale */
     [!LOOP "IcuFtm/*"!][!/*
     */!][!IF "node:value(./IcuFtmModule) = 'FTM_0'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 0U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_1'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 1U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_2'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 2U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_3'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 3U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_4'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 4U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_5'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 5U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_6'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 6U)) |\[!CR!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_7'"!][!/*
        */!][!WS "4"!](((uint32)[!"concat(node:value(./Icu_FlexTimer_Prescaler),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 7U)) |\[!CR!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!WS "4"!]0x0U
#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
    ,
/* Icu_Ftm_GlobalConfigAltPrescale */
    [!LOOP "IcuFtm/*"!][!/*
     */!][!IF "node:value(./IcuFtmModule) = 'FTM_0'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 0U)) |\[!CR!][!ENDIF!][!/*
     */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_1'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 1U)) |\[!CR!][!ENDIF!][!/*
    */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_2'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 2U)) |\[!CR!][!ENDIF!][!/*
    */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_3'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 3U)) |\[!CR!][!ENDIF!][!/*
     */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_4'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 4U)) |\[!CR!][!ENDIF!][!/*
     */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_5'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 5U)) |\[!CR!][!ENDIF!][!/*
     */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_6'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 6U)) |\[!CR!][!ENDIF!][!/*
     */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuFtmModule) = 'FTM_7'"!][!/*
        */!][!IF "node:exists(./Icu_FlexTimer_Prescaler_Alternate)"!][!WS "4"!]((uint32)([!"concat(node:value(./Icu_FlexTimer_Prescaler_Alternate),'_U32')"!]) << (ICU_FTM_PRES_CONFIG_WIDTH_U32 * 7U)) |\[!CR!][!ENDIF!][!/*
     */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
    */!][!WS "4"!]0x0U
#endif /* ICU_DUAL_CLOCK_MODE_API == STD_ON */
    [!CR!][!/*
*/!]};

/*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_Ftm_IpConfigType, ICU_CONST) Icu_FtmIcu_IpConfig_[!"$VARIANT"!] =
 {
    /** @brief Number of Ftm channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingFtm)"!],
    /** @brief Configured FTM global configuration */
    &Icu_Ftm_GlobalConfiguration_[!"$VARIANT"!],
    /** @brief Pointer to the array of Ftm enabled Icu channel configurations */
    &Icu_Ftm_ChannelConfig_[!"$VARIANT"!]
 };

[!ELSE!]
    /** @brief No Ftm channels configured */
[!ENDIF!]

[!IF "num:i($OutNumIcuChannelsUsingPort)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default PORT Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_Port_Ci_ChannelConfigType, ICU_CONST) Icu_Port_Ci_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingPort)"!]] =
 {
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'PORT')"!]
    /** @brief [!"node:name(.)"!] */
    {
        /** @brief Port HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!VAR "PortMod" = "node:value(node:ref(IcuPortChannelRef)/../../IcuPortModule)"!][!/*
        */!][!VAR "PortChannel" = "node:value(node:ref(IcuPortChannelRef)/IcuPortChannel)"!][!/*
        */!][!WS "8"!]ICU_[!"$PortMod"!]_[!"$PortChannel"!],
        /** @brief Port default start Edge */[!CR!][!/*
        */!][!WS "8"!](uint8)[!"IcuDefaultStartEdge"!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingPort))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };

/*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_Port_Ci_IpConfigType, ICU_CONST) Icu_Port_Ci_IpConfig_[!"$VARIANT"!] =
 {
    /** @brief Number of Port channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingPort)"!],
    /** @brief Pointer to the array of Port enabled Icu channel configurations */
    &Icu_Port_Ci_ChannelConfig_[!"$VARIANT"!]
 };

[!ELSE!]
    /** @brief No Port channels configured */
[!ENDIF!]

[!IF "num:i($OutNumIcuChannelsUsingLpit)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default LPIT Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_LPit_ChannelConfigType, ICU_CONST) Icu_LPit_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingLpit)"!]] =
 {
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'LPIT')"!]
    /** @brief [!"node:name(.)"!] */
    {
        /** @brief Lpit HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!VAR "LpitMod" = "node:value(node:ref(IcuLpitChannelRef)/../../IcuLpitModule)"!][!/*
        */!][!VAR "LpitChannel" = "node:value(node:ref(IcuLpitChannelRef)/IcuLpitChannel)"!][!/*
        */!][!WS "8"!]ICU_[!"$LpitMod"!]_[!"$LpitChannel"!],
        /** @brief LPIT channel configuration parameters */[!CR!][!/*
        */!][!IF "node:ref(IcuLpitChannelRef)/../../IcuFreezeEnable = 'true'"!][!/*
            */!][!WS "8"!](Icu_LPit_ControlType)((Icu_LPit_ControlType)1U << ICU_LPIT_FREEZE_SHIFT)|\[!CR!][!/*
        */!][!ELSE!][!/*
            */!][!WS "8"!](Icu_LPit_ControlType)((Icu_LPit_ControlType)0U << ICU_LPIT_FREEZE_SHIFT)|\[!CR!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "node:value(node:ref(IcuLpitChannelRef)/IcuLpitTriggerSource) = 'INTERNAL_TRIGGER'"!][!/*
            */!][!WS "8"!](Icu_LPit_ControlType)((Icu_LPit_ControlType)1U << ICU_LPIT_TRG_SRC_SHIFT)|\[!CR!][!/*
            */!][!WS "8"!](Icu_LPit_ControlType)((Icu_LPit_ControlType)[!"node:value(node:ref(IcuLpitChannelRef)/IcuLpitTriggerSelect)"!]<< ICU_LPIT_TRG_SEL_SHIFT)[!/*
        */!][!ELSE!][!/*
            */!][!WS "8"!](Icu_LPit_ControlType)((Icu_LPit_ControlType)0U << ICU_LPIT_TRG_SRC_SHIFT)|\[!CR!][!/*
            */!][!WS "8"!](Icu_LPit_ControlType)((Icu_LPit_ControlType)[!"node:value(node:ref(IcuLpitChannelRef)/IcuLpitTriggerSelect)"!]<< ICU_LPIT_TRG_SEL_SHIFT)[!/*
        */!][!ENDIF!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingLpit))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };

/*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_LPit_IpConfigType, ICU_CONST) Icu_LPit_IpConfig_[!"$VARIANT"!] =
 {
    /** @brief Number of Lpit channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingLpit)"!],
    /** @brief Pointer to the array of Lpit enabled Icu channel configurations */
    &Icu_LPit_ChannelConfig_[!"$VARIANT"!]
 };

[!ELSE!]
    /** @brief No LPit channels configured */
[!ENDIF!]

[!IF "num:i($OutNumIcuChannelsUsingLptmr)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default Lptmr Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_Lptmr_ChannelConfigType, ICU_CONST) Icu_Lptmr_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingLptmr)"!]] =
 {
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'LPTMR')"!]
    /** @brief [!"node:name(.)"!] */
    {
        /** @brief Lptmr HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!VAR "LptmrMod" = "node:value(node:ref(IcuLptmrChannelRef)/../../IcuLptmrModule)"!][!/*
        */!][!VAR "LptmrChannel" = "node:value(node:ref(IcuLptmrChannelRef)/IcuLptmrChannel)"!][!/*
        */!][!WS "8"!]ICU_[!"$LptmrMod"!]_[!"$LptmrChannel"!],
        /** @brief Lptmr channel configuration parameters */[!CR!][!/*
        */!][!IF "node:ref(IcuLptmrChannelRef)/../../IcuLptmrPinSelect = 'TRGMUX_OUTPUT'"!][!/*
            */!][!WS "8"!]((Icu_Lptmr_ControlType)((Icu_Lptmr_ControlType)0U << ICU_LPTMR_CSR_TPS_SHIFT_U32)[!/*
        */!][!ELSEIF "node:ref(IcuLptmrChannelRef)/../../IcuLptmrPinSelect = 'ALT1'"!][!/*
            */!][!WS "8"!]((Icu_Lptmr_ControlType)((Icu_Lptmr_ControlType)1U << ICU_LPTMR_CSR_TPS_SHIFT_U32)[!/*
        */!][!ELSEIF "node:ref(IcuLptmrChannelRef)/../../IcuLptmrPinSelect = 'ALT2'"!][!/*
            */!][!WS "8"!]((Icu_Lptmr_ControlType)((Icu_Lptmr_ControlType)2U << ICU_LPTMR_CSR_TPS_SHIFT_U32)[!/*
        */!][!ELSEIF "node:ref(IcuLptmrChannelRef)/../../IcuLptmrPinSelect = 'ALT3'"!][!/*
            */!][!WS "8"!]((Icu_Lptmr_ControlType)((Icu_Lptmr_ControlType)3U << ICU_LPTMR_CSR_TPS_SHIFT_U32)[!/*
        */!][!ENDIF!][!/*
        */!][!IF "node:ref(IcuLptmrChannelRef)/../../PrescalerEnable = 'true'"!][!/*
            */!][!CR!][!WS "8"!]|(Icu_Lptmr_ControlType)((Icu_Lptmr_ControlType)1U << ICU_LPTMR_PSR_PBYP_SHIFT_U32)[!/*
        */!][!ENDIF!]),[!/*
        */!][!CR!][!WS "8"!](uint8)[!"IcuDefaultStartEdge"!],[!/*
        */!][!CR!][!WS "8"!](uint8)[!"IcuMeasurementMode"!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingLptmr))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };
 /*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_Lptmr_GlobalConfigurationType,ICU_CONST) Icu_Lptmr_GlobalConfiguration_[!"$VARIANT"!]=
 {
    /* Icu_Lptmr_GlobalConfig */[!CR!][!/*
    */!][!LOOP "IcuLptmr/*"!][!/*
    */!][!IF "node:value(./PrescalerEnable) = 'true'"!][!/*
    */!][!WS "4"!]((uint16)((uint16)[!"concat(node:value('IcuLptmrPrescaler'),'_U16')"!] << ICU_LPTMR_PSR_PRESCALE_SHIFT_U32)) |[!/*
    */!][!ENDIF!][!/*
    */!][!IF "node:value(./IcuLptmrChannelClkSrc) = 'SIRCDIV2_CLK'"!][!/*
        */!][!WS "4"!](uint16)((uint16)(0U) << ICU_LPTMR_PSR_PCS_SHIFT_U32) |\[!CR!][!/*
    */!][!ELSEIF "node:value(./IcuLptmrChannelClkSrc) = 'LPO1K_CLK'"!][!/*
        */!][!WS "4"!](uint16)((uint16)(1U) << ICU_LPTMR_PSR_PCS_SHIFT_U32) |\[!CR!][!/*
    */!][!ELSEIF "node:value(./IcuLptmrChannelClkSrc) = 'RTC_CLK'"!][!/*
        */!][!WS "4"!](uint16)((uint16)(2U) << ICU_LPTMR_PSR_PCS_SHIFT_U32) |\[!CR!][!/*
    */!][!ELSEIF "node:value(./IcuLptmrChannelClkSrc) = 'PCC_LPTMR0'"!][!/*
        */!][!WS "4"!](uint16)((uint16)(3U) << ICU_LPTMR_PSR_PCS_SHIFT_U32) |\[!CR!][!/*
    */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
        */!][!WS "4"!]0x0U[!CR!][!/*
*/!]};

/*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_Lptmr_IpConfigType, ICU_CONST) Icu_Lptmr_IpConfig_[!"$VARIANT"!] =
 {
    /** @brief Number of Lptmr channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingLptmr)"!],
    /** @brief Configured Lptmr global configuration */
    &Icu_Lptmr_GlobalConfiguration_[!"$VARIANT"!],
    /** @brief Pointer to the array of Lptmr enabled Icu channel configurations */
    &Icu_Lptmr_ChannelConfig_[!"$VARIANT"!]
 };

[!ELSE!]
    /** @brief No Lptmr channels configured */
[!ENDIF!]

/*
 * @brief   Icu channels IP related configuration array
 * @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_IpChannelConfigType, ICU_CONST) Icu_IpChannelConfig_[!"$VARIANT"!][[!"num:i(count(IcuChannel/*))"!]] =
 {
    [!VAR "CurIcuChannelUsingFtm" = "0"!][!/*
    */!][!VAR "CurIcuChannelUsingPort"  = "0"!][!/*
    */!][!VAR "CurIcuChannelUsingLpit"  = "0"!][!/*
    */!][!VAR "CurIcuChannelUsingLptmr"  = "0"!][!/*
    */!][!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!]
    /** @brief [!"@name"!] */
    {[!/*
        */!][!IF "contains(IcuHwIP,'FTM')"!]
        /** @brief IP type of this channel */
        ICU_FTM_CHANNEL,
        /** @brief Index in the configuration table of the Ftm channels */
        (uint8)[!"num:i($CurIcuChannelUsingFtm)"!],[!/*
        */!][!VAR "CurIcuChannelUsingFtm" = "$CurIcuChannelUsingFtm + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'PORT')"!]
        /** @brief IP type of this channel */
        ICU_PORT_CI_CHANNEL,
        /** @brief Index in the configuration table of the Port channels */
        (uint8)[!"num:i($CurIcuChannelUsingPort)"!],[!/*
        */!][!VAR "CurIcuChannelUsingPort" = "$CurIcuChannelUsingPort + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'LPIT')"!]
        /** @brief IP type of this channel */
        ICU_LPIT_CHANNEL,
        /** @brief Index in the configuration table of the Lpit channels */
        (uint8)[!"num:i($CurIcuChannelUsingLpit)"!],[!/*
        */!][!VAR "CurIcuChannelUsingLpit" = "$CurIcuChannelUsingLpit + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'LPTMR')"!]
        /** @brief IP type of this channel */
        ICU_LPTMR_CHANNEL,
        /** @brief Index in the configuration table of the Lptmr channels */
        (uint8)[!"num:i($CurIcuChannelUsingLptmr)"!],[!/*
        */!][!VAR "CurIcuChannelUsingLptmr" = "$CurIcuChannelUsingLptmr + 1"!][!/*
        */!][!ENDIF!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannels))"!],[!ENDIF!][!VAR "comma"="$comma + 1"!][!CR!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };
[!ENDSELECT!]
[!ENDMACRO!]

[!// MACRO for creating the defines for the interrupts used on hardware modules
[!MACRO "ICU_GENERATE_OVF_ISR_USED", "IPVType"!]
[!NOCODE!]
    [!SELECT "IcuConfigSet"!][!//
    [!VAR "ChannelKey" = "string('null')"!]
    [!LOOP "IcuHwInterruptConfigList/*"!]
        [!IF "node:value(IcuIsrEnable)"!]
            [!IF "contains(IcuIsrHwId,$IPVType)"!]
                [!VAR "IPV_NAME" = "substring-before(node:value(IcuIsrHwId),'_CH_')"!]
                [!IF "($ChannelKey != $IPV_NAME) and (node:value(../../../*/IcuOverflowNotificationApi) = 'true')"!]
                                [!CODE!]
/**
*   @brief ISR's configured for [!"$IPV_NAME"!] OVF interrupt service routines
*   @{
*/
#define ICU_[!"$IPV_NAME"!]_OVF_ISR_USED [!CR!]
                    [!ENDCODE!]
                            [!ENDIF!]
                        [!VAR "ChannelKey" = "$IPV_NAME"!]
            [!ENDIF!]

        [!ENDIF!]

    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!// MACRO for creating the defines for the interrupts used on hardware modules
[!MACRO "ICU_GENERATE_ISR_USED", "IPVType"!]
[!NOCODE!]
    [!SELECT "IcuConfigSet"!][!//
    [!VAR "ChannelKey" = "string('null')"!]
    [!VAR "ModunleKey" = "string('null')"!]
    [!LOOP "IcuHwInterruptConfigList/*"!]
        [!IF "node:value(IcuIsrEnable)"!]
            [!IF "contains(IcuIsrHwId,$IPVType)"!]
                [!VAR "IPV_NAME" = "substring-before(node:value(IcuIsrHwId),'_CH_')"!]
                [!VAR "IcuChannel" = "substring-after(node:value(IcuIsrHwId),'_CH_')"!]
                [!VAR "ChIntegerDivisionBy2"  = "floor(number($IcuChannel) div 2)"!]
                [!IF "(($IPVType = 'FTM' or $IPVType = 'LPIT') and (ecu:get(concat('Icu.IcuConfig.Icu_', $IPVType,'_ModuleSingleInterrupt'))='TRUE')) or $IPVType = 'PORT'"!]
                    [!VAR "ChannelName" = "$IPV_NAME"!]    
                [!ELSE!]
                    [!IF "($IPVType = 'FTM')"!]
                        [!VAR "ChannelName" = "concat($IPV_NAME, '_CH_', string($ChIntegerDivisionBy2 * 2),'_CH_',string($ChIntegerDivisionBy2 * 2 + 1))"!]
                    [!ELSE!]
                        [!VAR "ChannelName" = "IcuIsrHwId"!]
                    [!ENDIF!]
                [!ENDIF!]
                [!IF "($ChannelKey != $ChannelName)"!]
[!CODE!]
/**
*   @brief ISR's configured for [!"$IPV_NAME"!] channels
*   @details Macros for channels used in ISR
*/
#define ICU_[!"$ChannelName"!]_ISR_USED [!CR!]
[!ENDCODE!]
                [!ENDIF!]
                [!VAR "ChannelKey" = "$ChannelName"!]
            [!ENDIF!]

        [!ENDIF!]

    [!ENDLOOP!]
    [!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!// MACRO for creating the defines for the interrupts used on hardware modules
[!MACRO "ICU_GENERATE_USED", "IPVType"!]
[!NOCODE!]
[!SELECT "IcuConfigSet"!][!//
    [!VAR "ChannelKey" = "string('null')"!]
    [!LOOP "IcuHwInterruptConfigList/*"!]
        [!IF "node:value(IcuIsrEnable)"!]
            [!IF "contains(IcuIsrHwId,$IPVType)"!]
                [!VAR "IPV_NAME" = "substring-before(node:value(IcuIsrHwId),'_CH_')"!]
                [!IF "($ChannelKey != $IPV_NAME)"!]
                                [!CODE!]
/**
 *   @brief ISR's configured for [!"$IPV_NAME"!]
 *   @details Macros for channels used in ISR
 */
#define ICU_[!"$IPV_NAME"!]_USED
                    [!ENDCODE!]
                            [!ENDIF!]
                        [!VAR "ChannelKey" = "$IPV_NAME"!]
            [!ENDIF!]

        [!ENDIF!]

    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "CHECKFREEZE" , "ModuleType"!]
[!NOCODE!]
    [!LOOP "IcuConfigSet/IcuFtm/*"!]
    [!VAR "MacNumChannels" = "0"!]
    [!VAR "MacFreezeEnabledChannels" = "0"!]
        [!IF "./IcuFtmModule = $ModuleType"!]
            [!LOOP "./IcuFtmChannels/*"!]
                [!IF "./IcuFreezeEnable"!] [!VAR "MacFreezeEnabledChannels" = "$MacFreezeEnabledChannels + 1"!][!ENDIF!][!//
                [!VAR "MacNumChannels" = "$MacNumChannels + 1"!][!//
            [!ENDLOOP!]

            [!IF "not($MacNumChannels = $MacFreezeEnabledChannels) and not($MacFreezeEnabledChannels = 0)"!]
            [!ERROR !][!//
                Module [!"$ModuleType"!]  has channels configured with different values for FreezeEnable. Please select the same value for FreezeEnable accross all [!"$ModuleType"!] channels
            [!ENDERROR!][!//
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!ENDNOCODE!]
[!ENDIF!]