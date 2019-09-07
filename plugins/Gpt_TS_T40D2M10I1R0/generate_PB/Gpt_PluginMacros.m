[!AUTOSPACING!]
[!NOCODE!]

/**
*   @file    Gpt_PluginMacros.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Macros used to generate code template for GPT driver.
*   @details Macros used to generate code template for GPT driver.
*
*   @addtogroup GPT_MODULE
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
==================================================================================================*/
[!/* Avoid multiple inclusion */!][!//
[!IF "not(var:defined('GPT_BUILD_CHANNEL_MAP_M'))"!][!//
[!VAR "GPT_BUILD_CHANNEL_MAP_M"="'true'"!][!//
[!//This macros is used to calculate the number of timer channel Ids and number of timer hw modules.
[!MACRO "CalculateModulesNumber","ModuleType"!][!//
        [!VAR "OutModulesNumber"="0"!][!//
        [!VAR "OutModuleChannelsNumber"="0"!][!//
        [!IF "$ModuleType = 'LPTMR'"!]
            [!VAR "MacMaxModuleId" = "num:i(ecu:list('Gpt.Num_Lptmr_Hw_Modules'))"!] [!//max id of the hardware unit available for this family i.e. 0,1,2,3 etc
        [!ELSEIF "$ModuleType = 'LPIT'"!]
            [!VAR "MacMaxModuleId" = "num:i(ecu:list('Gpt.Num_Lpit_Hw_Modules'))"!] [!//max id of the hardware unit available for this family i.e. 0,1,2,3 etc
        [!ELSEIF "$ModuleType = 'FTM'"!]
            [!VAR "MacMaxModuleId" = "num:i(ecu:list('Gpt.Num_Ftm_Hw_Modules'))"!] [!//max id of the hardware unit available for this family i.e. 0,1,2,3 etc
        [!ELSEIF "$ModuleType = 'SRTC'"!]
            [!VAR "MacMaxModuleId" = "num:i(ecu:list('Gpt.Num_Srtc_Hw_Modules'))"!] [!//max id of the hardware unit available for this family i.e. 0,1,2,3 etc
        [!ENDIF!][!//
        [!VAR "MaxChannelsNumber" = "0"!][!//
        [!FOR "x" = "0" TO "num:i($MacMaxModuleId)-1"!][!//
                [!VAR "ChannelsNumber" = "count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($ModuleType,'_',$x,'_CH','.*')))"!][!//
                [!IF "$ChannelsNumber > 0"!][!//
                    [!VAR "OutModulesNumber" = "$x+1"!][!//
[!CODE!]
/* The real number of channels in [!"$ModuleType"!]_[!"$x"!] */
#define GPT_[!"$ModuleType"!]_[!"$x"!]_NUM_CHANNEL_U8 ([!"num:i($ChannelsNumber)"!]U)[!//
[!ENDCODE!][!//
                    [!VAR "OutModuleChannelsNumber" = "$OutModuleChannelsNumber + $ChannelsNumber"!][!//
                [!ENDIF!][!//
                [!IF "$ChannelsNumber > $MaxChannelsNumber"!][!//
                    [!VAR "MaxChannelsNumber" = "$ChannelsNumber"!][!//
                [!ENDIF!][!//
        [!ENDFOR!][!//
        [!IF "$OutModulesNumber = 0"!][!//
            [!ERROR !][!//
                [!"$Name"!][!"'-OutModulesNumber should be > 0 at this stage because at least 1 module exists '"!][!//
            [!ENDERROR!][!//
        [!ENDIF!][!//
[!CODE!]
/* The maximum number of channels per module for [!"$ModuleType"!] */
#define GPT_[!"$ModuleType"!]_CHANNELS_PER_MODULE_U8 ([!"num:i($MaxChannelsNumber)"!]U)
[!ENDCODE!][!//
[!ENDMACRO!][!//

[!// MACRO for creating the defines for the interrupts used on GPT module
[!MACRO "GPT_GENERATE_USED_ISR","HW_UNIT"="'FTM_0'"!]
[!IF "text:match(GptChannelConfigSet/*/*/GptHwChannel,$HW_UNIT)"!][!//
/**
*   @brief ISR's configured for [!"$HW_UNIT"!]
*   @details Macros for channels used in ISR
*/
#define GPT_[!"$HW_UNIT"!]_ISR_USED
[!ELSEIF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi and contains(GptPredefTimerConfiguration/*[1]/GptPredefTimer_1us_16Bit/GptHwChannel, $HW_UNIT)"!][!//
/**
*   @brief ISR's configured for [!"$HW_UNIT"!]
*   @details Macros for channels used in ISR
*/
#define GPT_[!"$HW_UNIT"!]_USED
[!ENDIF!][!//
[!ENDMACRO!][!//

[!// MACRO for creating the defines to indicate other modules that this IPVault was used by GPT module
[!MACRO "GPT_GENERATE_USED","HW_UNIT"="'FTM_0'"!][!//
[!IF "text:match(GptChannelConfigSet/*/*/GptHwChannel,$HW_UNIT)"!][!//
/**
*   @brief ISR's configured for [!"$HW_UNIT"!]
*   @details Macros for channels used in GPT
*/
#define GPT_[!"$HW_UNIT"!]_USED
[!ELSEIF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi and contains(GptPredefTimerConfiguration/*[1]/GptPredefTimer_1us_16Bit/GptHwChannel, $HW_UNIT)"!][!//
/**
*   @details Macros for [!"$HW_UNIT"!] used in GPT
*/
#define GPT_[!"$HW_UNIT"!]_USED
[!ENDIF!][!//
[!ENDMACRO!][!//

[!//This macros is used to build the hardware to logic map table
[!MACRO "BuildChannelMap" , "ModuleType","LastModule"!]
        [!IF "$ModuleType = 'FTM'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Ftm_Hw_Modules'))"!][!//
        [!ELSEIF "$ModuleType = 'LPIT'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Lpit_Hw_Modules'))"!][!//
        [!ELSEIF "$ModuleType = 'LPTMR'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Lptmr_Hw_Modules'))"!][!//
        [!ELSEIF "$ModuleType = 'SRTC'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Srtc_Hw_Modules'))"!][!//
        [!ENDIF!][!//
        [!VAR "MacMaxChannelId"="0"!][!//
        [!FOR "MacModuleId" = "0" TO "num:i($MacMaxModules)-1"!][!//
            [!VAR "MacMaxChannelIdcount"="count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($ModuleType,'_',$MacModuleId,'_CH','.*')))"!]
            [!IF "$MacMaxChannelIdcount > $MacMaxChannelId"!][!//
                [!VAR "MacMaxChannelId"="$MacMaxChannelIdcount"!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!//Hardware to logic channel mapping
        [!FOR "MacModuleId" = "0" TO "num:i($MacMaxModules)-1"!][!//
            [!FOR "MacChannelId" = "0" TO "num:i($MacMaxChannelId)-1"!][!//
                [!VAR "MacChannelUsed"="0"!][!//
                [!FOR "MacLogicChannel" = "0" TO "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!][!//
                    [!SELECT "GptChannelConfigSet/GptChannelConfiguration/*/GptChannelId[.=$MacLogicChannel]/.."!][!//
                        [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!][!//
                            [!CODE!]
        GptConf_GptChannelConfiguration_[!"node:name(.)"!][!ENDCODE!][!//
                            [!VAR "MacChannelUsed"="1"!][!//
                        [!ENDIF!][!//
                    [!ENDSELECT!][!//
                [!ENDFOR!][!//
                
                [!IF "$MacChannelUsed=0"!][!//
                    [!CODE!]
        GPT_CHN_NOT_USED[!ENDCODE!][!//
                [!ENDIF!][!//
    
                [!IF "$MacModuleId=(num:i($MacMaxModules -1)) and $MacChannelId=(num:i($MacMaxChannelId -1)) and $LastModule = 'TRUE'"!]
                [!ELSE!]
                    [!CODE!],[!ENDCODE!][!//
                [!ENDIF!][!//
                [!IF "$ModuleType = 'FTM'"!]
                    [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
                [!ELSEIF "$ModuleType = 'LPIT'"!]
                    [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
                [!ELSEIF "$ModuleType = 'LPTMR'"!]
                    [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
                [!ELSEIF "$ModuleType = 'SRTC'"!]
                    [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ENDFOR!][!//
[!ENDMACRO!]

[!//This macros is used to check parameters
[!MACRO "CheckParameter" , "ModuleType", "param"!]
    [!IF "$ModuleType = 'FTM'"!]
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Ftm_Hw_Modules'))"!]
    [!ELSE!][!//
        [!VAR "MacMaxModules"="0"!]
    [!ENDIF!][!//

    [!VAR "MacErrorFlag" = "string('Invalid')"!][!//

    [!FOR "idx" = "0" TO "num:i($MacMaxModules)"!][!//
        [!VAR "MacErrorFlag" = "string('Invalid')"!][!//
        [!FOR "x" = "0" TO "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!][!//
        [!SELECT "GptChannelConfigSet/GptChannelConfiguration/*/GptChannelId[.=$x]/.."!][!//
            [!IF "contains(GptHwChannel, concat($ModuleType, '_', $idx)) and node:exists($param)"!][!//
                [!IF "($MacErrorFlag = string('Invalid'))"!][!//
                    [!VAR "MacErrorFlag" = "string(node:value($param))"!][!//
                [!ELSE!][!//
                    [!IF "($MacErrorFlag = string(node:value($param)))"!][!//
                    [!ELSE!][!//
                        [!ERROR!][!//
                        [!"concat('For the ',$ModuleType, '_', $idx,' module all the channels must have the same value for the ', $param, ' parameter, because this module has one general clock prescaler for all its counter channels.')"!][//
                        [!ENDERROR!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDSELECT!][!//
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!//This macros is used to build the configuration structure for a config set.
[!MACRO "BuildConfigSet"!]
    [!CALL "CheckParameter","ModuleType"="string('FTM')", "param"="string('GptChannelTickFrequency')"!][//
    [!CALL "CheckParameter","ModuleType"="string('FTM')", "param"="string('GptFtmChannelClkSrc')"!][//
    [!CALL "CheckParameter","ModuleType"="string('FTM')", "param"="string('GptFtmPrescaler')"!][//
    [!IF "node:value(GptNonAUTOSAR/GptEnableDualClockMode)"!][!//
        [!CALL "CheckParameter","ModuleType"="string('FTM')", "param"="string('GptFtmPrescaler_Alternate')"!][!//
    [!ENDIF!][!//
    [!FOR "x" = "0" TO "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!][!//
    [!SELECT "GptChannelConfigSet/GptChannelConfiguration/*/GptChannelId[.=$x]/.."!][!//
[!CODE!][!//
    {   /*[!"node:name(.)"!] configuration data*/
        [!IF "node:exists(GptEnableWakeup)"!][!IF "GptEnableWakeup"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!][!ELSE!](boolean)FALSE[!ENDIF!], /* Wakeup capability */
        [!IF "node:exists(GptNotification)"!][!IF "(GptNotification != '') and (GptNotification != 'NULL_PTR') and (GptNotification != 'NULL')"!]&[!"GptNotification"!][!ELSE!]NULL_PTR[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!], /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
        (EcuM_WakeupSourceType)[!IF "node:exists(GptWakeupConfiguration)"!] ((uint32)((uint32)1<<[!"as:ref(GptWakeupConfiguration/GptWakeupSourceRef)/EcuMWakeupSourceId"!]))[!ELSE!]0U[!ENDIF!], /* Wakeup information */
#endif
        (Gpt_ValueType)([!"num:i(num:i(GptChannelTickValueMax))"!]U), /* Maximum ticks value*/
        (Gpt_ChannelModeType)([!"GptChannelMode"!]), /* Timer mode:continous/one-shot */
        {
            (uint8)([!"GptHwChannel"!]), /* GPT physical channel no. */
            (uint8)(GPT_[!"substring-before(GptHwChannel, '_')"!]_MODULE), /* hardware module ID */
            [!IF "GptFreezeEnable"!](boolean)TRUE[!ELSE!](boolean)(FALSE)[!ENDIF!], /* Freeze Enable */
[!ENDCODE!][!//
        [!IF "contains(GptHwChannel, 'FTM_')"!][!//
            [!IF "contains(node:value(GptFtmChannelClkSrc),'FIXED_FREQUENCY_CLOCK')"!]
                [!CODE!][!WS "12"!](uint8)(2U), /* FTM clock source */[!CR!][!ENDCODE!]
            [!ELSE!]
                [!IF "contains(node:value(GptFtmChannelClkSrc),'EXTERNAL_CLOCK')"!]
                    [!CODE!][!WS "12"!](uint8)(3U), /* FTM clock source */[!CR!][!ENDCODE!]
                [!ELSE!]
                    [!CODE!][!WS "12"!](uint8)(1U), /* FTM clock source */[!CR!][!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
            [!FOR "macIndex" = "0" TO "7"!]
                [!VAR "macTemp" = "bit:shr(num:i(number(GptFtmPrescaler)),num:i($macIndex))"!]
                    [!IF "$macTemp < 2"!]
                        [!CODE!][!WS "12"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* FTM Clock divider */ [!CR!][!ENDCODE!]
                        [!BREAK!][!//
                    [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ELSE!][!//
            [!CODE!][!WS "12"!](uint8)(0U), /* FTM Clock source, FTM is not used */
            (Gpt_PrescalerType)(0U), /* FTM Clock divider, FTM is not used */ [!CR!][!ENDCODE!]
        [!ENDIF!][!//

    [!VAR "MacChannelFreq" = "num:i(contains(node:fallback(GptHwChannel,'LPIT'),'LPIT') = true()) * noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(node:fallback(GptChannelClkSrcRef, .)), '/GptClockReference'))), '/McuClockReferencePointFrequency'))"!][!//
    [!VAR "MacChannelFreq" = "$MacChannelFreq + num:i(contains(node:fallback(GptHwChannel,'LPTMR'),'LPTMR') = true()) * (noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(node:fallback(GptChannelClkSrcRef, .)), '/GptClockReference'))), '/McuClockReferencePointFrequency')) div  (num:i(not(contains(node:fallback(GptHwChannel,'LPTMR'),'LPTMR'))) + noderef:value(node:fallback(GptLptmrPrescaler,1))) )"!][!//
    [!VAR "MacChannelFreq" = "$MacChannelFreq + num:i(contains(node:fallback(GptHwChannel,'FTM'),'FTM') = true()) * (noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(node:fallback(GptChannelClkSrcRef, .)), '/GptClockReference'))), '/McuClockReferencePointFrequency')) div  (num:i(not(contains(node:fallback(GptHwChannel,'FTM'),'FTM'))) + noderef:value(node:fallback(GptFtmPrescaler,1))) )"!][!//
    [!VAR "MacChannelFreq" = "$MacChannelFreq + num:i( contains(node:fallback(GptHwChannel,'SRTC'),'SRTC') = true()) * num:i(1)"!][!//

    [!IF "num:f(GptChannelTickFrequency)!=num:f($MacChannelFreq)"!]
        [!ERROR!]
                The value configured for GptChannelTickFrequency parameter is not compliant with MCU clock tree settings.
                To solve this problem change the configured channel ticks frequency from "[!"num:f(GptChannelTickFrequency)"!]" to "[!"num:f($MacChannelFreq)"!]".
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "contains(GptHwChannel, 'LPTMR')"!][!//
        [!FOR "macIndex" = "0" TO "15"!]
          [!VAR "macTemp" = "bit:shr(num:i(number(GptLptmrPrescaler)),num:i($macIndex))"!]
            [!IF "$macTemp < 4"!]
               [!CODE!][!WS "12"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* LPTMR Clock divider */ [!CR!][!ENDCODE!]
               [!BREAK!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
        [!IF "contains(node:value(GptLptmrChannelClkSrc),'SIRCDIV2_CLK')"!][!//
            [!CODE!][!WS "12"!](uint8)(0U), /* LPTMR Clock Select [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!IF "contains(node:value(GptLptmrChannelClkSrc),'RTC_CLK')"!][!//
                [!CODE!][!WS "12"!](uint8)(2U), /* LPTMR Clock Select [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
            [!ELSE!][!//
                [!IF "contains(node:value(GptLptmrChannelClkSrc),'LPO1K_CLK')"!][!//
                    [!CODE!][!WS "12"!](uint8)(1U), /* LPTMR Clock Select [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
                [!ELSE!][!//
                    [!IF "contains(node:value(GptLptmrChannelClkSrc),'PCC_LPTMR0')"!][!//
                        [!CODE!][!WS "12"!](uint8)(3U), /* LPTMR Clock Select [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ELSE!][!//
        [!CODE!][!WS "12"!](uint8)(0U), /* LPTMR Clock divider, LPTMR is not USED */
            (Gpt_PrescalerType)(0U),  /* LPTMR Clock Select, LPTMR is not USED */ [!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!CODE!][!//
#if (GPT_SET_CLOCK_MODE == STD_ON)
[!ENDCODE!][!//
    [!IF "contains(GptHwChannel, 'FTM_')"!][!//
        [!IF "node:exists(GptFtmPrescaler_Alternate)"!]
            [!FOR "macIndex" = "0" TO "7"!]
              [!VAR "macTemp" = "bit:shr(num:i(number(GptFtmPrescaler_Alternate)),num:i($macIndex))"!]
                [!IF "$macTemp < 2"!]
                   [!CODE!][!WS "12"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* FTM alternate Clock divider */ [!CR!][!ENDCODE!]
                   [!BREAK!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ELSE!]
            [!FOR "macIndex" = "0" TO "7"!]
              [!VAR "macTemp" = "bit:shr(num:i(number(GptFtmPrescaler)),num:i($macIndex))"!]
                [!IF "$macTemp < 2"!]
                   [!CODE!][!WS "12"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* FTM alternate Clock divider */ [!CR!][!ENDCODE!]
                   [!BREAK!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ENDIF!][!//
    [!ELSE!][!//
        [!CODE!][!WS "12"!](Gpt_PrescalerType)(0U), /* FTM alternate Clock divider, FTM is not USED */ [!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
    [!IF "contains(GptHwChannel, 'LPTMR_')"!][!//
        [!IF "node:exists(GptLptmrPrescaler_Alternate)"!]
            [!FOR "macIndex" = "0" TO "15"!]
              [!VAR "macTemp" = "bit:shr(num:i(number(GptLptmrPrescaler_Alternate)),num:i($macIndex))"!]
                [!IF "$macTemp < 4"!]
                   [!CODE!][!WS "12"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* LPTMR alternate Clock divider */ [!CR!][!ENDCODE!]
                   [!BREAK!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ELSE!]
            [!FOR "macIndex" = "0" TO "15"!]
              [!VAR "macTemp" = "bit:shr(num:i(number(GptLptmrPrescaler)),num:i($macIndex))"!]
                [!IF "$macTemp < 4"!]
                   [!CODE!][!WS "12"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* LPTMR alternate Clock divider */ [!CR!][!ENDCODE!]
                   [!BREAK!][!//
                [!ENDIF!][!//
            [!ENDFOR!][!//
        [!ENDIF!][!//
    [!ELSE!][!//
        [!CODE!][!WS "12"!](Gpt_PrescalerType)(0U), /* LPTMR alternate Clock divider, LPTMR is not USED */ [!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!CODE!][!//
#endif /*GPT_SET_CLOCK_MODE == STD_ON*/
[!ENDCODE!][!//

[!IF "contains(GptHwChannel, 'SRTC')"!][!//
    [!IF "contains(node:value(GptSRtcChannelClkSrc),'EXTERNAL_CLOCK')"!][!//
        [!CODE!][!WS "12"!](uint8)(0U)          /* SRTC Clock Select */ [!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!CODE!][!WS "12"!](uint8)(1U)          /* SRTC Clock Select */ [!CR!][!ENDCODE!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!CODE!][!WS "12"!](uint8)0             /* SRTC Clock Select, SRTC is not USED */ [!CR!][!ENDCODE!][!//
[!ENDIF!][!//

[!CODE!][!//
#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
            /* LPIT External/Internal Trigger Configuration */
[!IF "contains(GptHwChannel, 'LPIT')"!][!//
[!IF "node:value(GptLPitIsExternalTrigger)"!][!//
            ,(uint32)([!IF "node:exists(GptLPitTriggerChannels)"!]((uint32)[!"text:split(node:value(GptLPitTriggerChannels), '_')[2]"!]U << 24U) |[!ENDIF!] \
[!IF "node:value(GptLPitIsExternalTrigger)"!][!//
            ((uint32)0U << 23U) | \
[!ELSE!][!//
            ((uint32)1U << 23U) | \
[!ENDIF!][!//
[!IF "node:value(GptLPitEnReloadOnTrigger)"!][!//
            ((uint32)1U << 18U) | \
[!ELSE!][!//
            ((uint32)0U << 18U) | \
[!ENDIF!][!//
[!IF "node:value(GptLPitEnStopOnInterrupt)"!][!//
            ((uint32)1U << 17U) | \
[!ELSE!][!//
            ((uint32)0U << 17U) | \
[!ENDIF!][!//
[!IF "node:value(GptLPitEnStartOnTrigger)"!][!//
            ((uint32)1U << 16U))
[!ELSE!][!//
            ((uint32)0U << 16U))
[!ENDIF!][!//
[!ELSE!][!//
            ,(uint32)((uint32)1U << 23U)  /* LPIT Trigger Disabled */
[!ENDIF!][!//
[!ELSE!][!//
            ,(uint32)0U              /* Not used for [!"GptHwChannel"!] */
[!ENDIF!][!//
#endif
[!ENDCODE!][!//
[!CODE!][!//
        }
    }
[!ENDCODE!][!//
[!ENDSELECT!][!//

[!CODE!][!//
[!IF "$x < num:i(count(GptChannelConfigSet/GptChannelConfiguration/*)) - 1"!],[!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!// FOR "x" = "0" TO "num:i(count(GptChannelConfigSet ...
[!ENDMACRO!]

[!//This macros is used to build the Predef timer configuration structure.
[!MACRO "BuildHwchannelPredefTimer","predefType"!]
[!NOCODE!]
[!VAR "path_temp" = "'GptPredefTimer_1us_16Bit'"!]
[!IF "$predefType = 'PREDEF_TIMER_1US_16BIT'"!]
    [!VAR "path_temp" = "'GptPredefTimer_1us_16Bit'"!]
[!ELSEIF "$predefType = 'PREDEF_TIMER_1US_24BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_24Bit'"!]
[!ELSEIF "$predefType = 'PREDEF_TIMER_1US_32BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_32Bit'"!]
[!ELSE!]
    [!VAR "path_temp" = "'GptPredefTimer_100us_32Bit'"!]
[!ENDIF!]

[!VAR "path_predef" = "concat('GptPredefTimerConfiguration/',$path_temp)"!]
[!SELECT "node:ref($path_predef)"!][!//
[!CODE!][!//
    (uint8)([!"GptHwChannel"!]), /* GPT physical channel no. */
    (uint8)(GPT_[!"substring-before(GptHwChannel, '_')"!]_MODULE), /* hardware module ID */
[!IF "GptFreezeEnable"!][!//
    (boolean)TRUE[!ELSE!] (boolean)(FALSE)[!ENDIF!], /* Freeze Enable */
[!ENDCODE!][!//
[!IF "contains(GptHwChannel, 'FTM')"!][!//
    [!FOR "macIndex" = "0" TO "7"!]
        [!VAR "macTemp" = "bit:shr(num:i(number(GptChannelPrescaler)),num:i($macIndex))"!][!//
            [!IF "$macTemp < 2"!]
                [!CODE!][!WS "4"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* FTM Clock divider */[!CR!][!ENDCODE!][!//
        [!BREAK!][!//
        [!ENDIF!][!//
    [!ENDFOR!]
        
    [!IF "contains(node:value(GptFtmChannelClkSrc),'FIXED_FREQUENCY_CLOCK')"!][!//
        [!CODE!][!WS "4"!](Gpt_ClockSourceType)(2U) /* FTM clock source [!"GptFtmChannelClkSrc"!]*/ [!CR!][!ENDCODE!][!//
    [!ELSE!][!//
        [!IF "contains(node:value(GptFtmChannelClkSrc),'EXTERNAL_CLOCK')"!][!//
            [!CODE!][!WS "4"!](Gpt_ClockSourceType)(3U) /* FTM clock source [!"GptFtmChannelClkSrc"!]*/ [!CR!][!ENDCODE!][!//
        [!ELSE!][!//
            [!CODE!][!WS "4"!](Gpt_ClockSourceType)(1U) /* FTM clock source [!"GptFtmChannelClkSrc"!]*/ [!CR!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!IF "contains(GptHwChannel, 'LPTMR')"!][!//
        [!FOR "macIndex" = "0" TO "15"!]
            [!VAR "macTemp" = "bit:shr(num:i(number(GptChannelPrescaler)),num:i($macIndex))"!][!//
            [!IF "$macTemp < 4"!]
                [!CODE!][!WS "4"!](Gpt_PrescalerType)([!"num:i(number($macIndex))"!]U), /* LPTMR Clock divider */ [!CR!][!ENDCODE!][!//
                [!BREAK!][!//
            [!ENDIF!][!//
        [!ENDFOR!]
        [!IF "contains(node:value(GptLptmrChannelClkSrc),'SIRCDIV2_CLK')"!][!//
            [!CODE!][!WS "4"!](Gpt_ClockSourceType)(0U) /* LPTMR Clock Source [!"GptLptmrChannelClkSrc"!] */ [!CR!] [!ENDCODE!][!//
        [!ELSE!][!//
            [!IF "contains(node:value(GptLptmrChannelClkSrc),'RTC_CLK')"!][!//
                [!CODE!][!WS "4"!](Gpt_ClockSourceType)(2U) /* LPTMR Clock Source [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
            [!ELSE!][!//
                [!IF "contains(node:value(GptLptmrChannelClkSrc),'LPO1K_CLK')"!][!//
                    [!CODE!][!WS "4"!](Gpt_ClockSourceType)(1U) /* LPTMR Clock Source [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
                [!ELSE!][!//
                    [!IF "contains(node:value(GptLptmrChannelClkSrc),'PCC_LPTMR0')"!][!//
                        [!CODE!][!WS "4"!](Gpt_ClockSourceType)(3U) /* LPTMR Clock Source [!"GptLptmrChannelClkSrc"!] */ [!CR!][!ENDCODE!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!]
[!ENDMACRO!]

[!ENDIF!] /* Avoid multiple inclusion ENDIF */
[!ENDNOCODE!]