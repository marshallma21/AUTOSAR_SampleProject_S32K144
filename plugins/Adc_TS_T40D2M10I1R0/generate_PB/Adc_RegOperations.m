[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ADC_REGOPERATIONS_M'))"!]
[!VAR "ADC_REGOPERATIONS_M"="'true'"!]
[!NOCODE!][!//
/**
*   @file    Adc_RegOperations.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - version check macro.
*   @details Version checks.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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
[!ENDNOCODE!][!//

[!MACRO "Adc_Group_Define"!][!//
/**
* @brief          Total number of groups in Config.
*
*/
#define ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]           [!"num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*))"!]
[!ENDMACRO!]
    
[!MACRO "Adc_Notification_Config"!][!//
/**
* @brief         ADC Notification functions.
* @details       ADC Notification functions defined inside the Plugin.
*
*/
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!][!//
[!IF "(../../../../../AdcGeneral/AdcGrpNotifCapability = 'true') and (node:exists(AdcNotification))"!][!//
[!IF "AdcNotification != 'NULL_PTR'"!][!//
[!IF "text:uniq(../../../../../AdcConfigSet/AdcHwUnit/*/AdcGroup/*[AdcGroupId <= $x]/AdcNotification, ./AdcNotification)"!][!//
/** @violates @ref Adc[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 MISRA-C:2004 Rule 8.8: External object declared more than once.*/
extern void [!"AdcNotification"!](void); /**< @brief for Group - [!"./AdcGroupId"!] */
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(./AdcExtraNotification) and (./AdcExtraNotification != 'NULL_PTR')"!][!//
[!IF "text:uniq(../../../../../AdcConfigSet/AdcHwUnit/*/AdcGroup/*[AdcGroupId <= $x]/AdcExtraNotification, ./AdcExtraNotification)"!][!//
/** @violates @ref Adc[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 MISRA-C:2004 Rule 8.8: External object declared more than once.*/
extern void [!"AdcExtraNotification"!](void); /**< @brief for Group - [!"./AdcGroupId"!] */
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

[!NOCODE!]
[!VAR "PdbErrorNotification" = "0"!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
[!IF "node:exists(AdcPdbSettings)"!][!//
[!IF "(AdcPdbSettings/AdcPdbChannelSequenceErrorEnable = 'true') and (AdcPdbSettings/AdcPdbErrorNotification != 'NULL_PTR')"!][!//
[!CODE!][!//
/**
* @brief         Pdb error notification functions.
* @details       Pdb error notification functions defined inside the Plugin.
*
*/
[!ENDCODE!]
[!BREAK!]
[!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!NOCODE!]
[!LOOP "AdcConfigSet/AdcHwUnit/*"!]
[!IF "node:exists(AdcPdbSettings)"!][!//
[!IF "(AdcPdbSettings/AdcPdbChannelSequenceErrorEnable = 'true') and (AdcPdbSettings/AdcPdbErrorNotification != 'NULL_PTR')"!][!//
[!CODE!][!//
/** @violates @ref Adc[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 MISRA-C:2004 Rule 8.8: External object declared more than once.*/
extern void [!"AdcPdbSettings/AdcPdbErrorNotification"!](void);
[!ENDCODE!]
[!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Adc_Group_Assignments"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',string($Unit))"!][!//
/**
* @brief          Group [!"AdcGroupId"!] Assignments on ADC Hardware unit [!"$Unit"!][!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!].
*
*/
static CONST(Adc_ChannelType, ADC_CONST) Adc_Group[!"AdcGroupId"!]_Assignment_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS] =
{
[!VAR "MAX_COUNT" = "count(AdcGroupDefinition/*)-1"!][!//
[!VAR "CRT_COUNT" = "0"!][!//
[!LOOP "AdcGroupDefinition/*"!][!//
[!VAR "CurrAdcChannel" = "."!][!//
[!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!][!//
[!VAR "INDEX" = "0"!][!//
[!LOOP "../../../../AdcChannel/*"!][!//
[!IF "@name = $CurrAdcChannel1"!][!//
    [!"AdcLogicalChannelId"!]U[!IF "$CRT_COUNT < $MAX_COUNT"!],[!ELSE!][!ENDIF!]
[!ENDIF!][!//
[!VAR "INDEX" = "$INDEX + 1"!][!//
[!ENDLOOP!][!//
[!VAR "CRT_COUNT" = "$CRT_COUNT + 1"!][!//
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Group_Delays"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
/**
* @brief          Group Channel Delays on ADC Hardware unit [!"$Unit"!].
*
*/
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "($x = AdcGroupId) and (AdcGroupUsesChannelDelays = 'true')"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',string($Unit))"!][!//
static CONST(uint16, ADC_CONST) Adc_Group[!"AdcGroupId"!]_Delays_[!"$Unit"!]_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!][[!IF "AdcGroupInBacktoBackMode = 'true'"!]1[!ELSE!]ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS[!ENDIF!]] =
{
[!VAR "MAX_COUNT" = "count(AdcChannelDelay/*)-1"!][!//
[!VAR "CRT_COUNT" = "0"!][!//
[!LOOP "AdcChannelDelay/*"!][!//
    [!"."!]U[!IF "$CRT_COUNT < $MAX_COUNT"!],[!ELSE!][!ENDIF!]
[!VAR "CRT_COUNT" = "$CRT_COUNT + 1"!][!//
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_HwUnit_Config"!][!//
[!VAR "maxUnitCfg"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
/**
* @brief          Definition of ADC Hw units for Configuration variant [!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!].
*/
static CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, ADC_CONST) Adc_HwUnitCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcLogicalUnitId = $Unit"!][!//
[!CODE!][!//
    /**< @brief Hardware Unit [!"AdcHwUnitId"!] */
    {
        /**< @brief Hardware unit id */
        (Adc_HwUnitType)[!"substring-after(string(AdcHwUnitId),'ADC')"!],
        /** Main configuration of CFG1 registers */
        /* Clock Divide Select */
[!IF "node:exists(AdcNormalConversionTimings)"!][!//
        [!IF "AdcNormalConversionTimings/AdcClockDivideSelect = 'DIV_NONE'"!]ADC12BSARV2_CFG1_CLOCK_DIV1_U32[!ELSEIF "AdcNormalConversionTimings/AdcClockDivideSelect = 'DIV_2'"!]ADC12BSARV2_CFG1_CLOCK_DIV2_U32[!ELSEIF "AdcNormalConversionTimings/AdcClockDivideSelect = 'DIV_4'"!]ADC12BSARV2_CFG1_CLOCK_DIV4_U32[!ELSE!]ADC12BSARV2_CFG1_CLOCK_DIV8_U32[!ENDIF!] |
[!ELSE!][!//
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32 |
[!ENDIF!][!// 
        /* Conversion Mode Selection */
        [!IF "AdcResolution = 'BITS_8'"!]ADC12BSARV2_CFG1_8_BITS_RESOLUTION_U32[!ELSEIF "AdcResolution = 'BITS_10'"!]ADC12BSARV2_CFG1_10_BITS_RESOLUTION_U32[!ELSEIF "AdcResolution = 'BITS_12'"!]ADC12BSARV2_CFG1_12_BITS_RESOLUTION_U32[!ENDIF!] |
        /* Input Clock Select */
[!IF "node:exists(AdcClockSource)"!][!//
        [!IF "AdcClockSource = 'ADC_ALTCLK1'"!]ADC12BSARV2_CFG1_ALTCLK1_U32[!ELSEIF "AdcClockSource = 'ADC_ALTCLK2'"!]ADC12BSARV2_CFG1_ALTCLK2_U32[!ELSEIF "AdcClockSource = 'ADC_ALTCLK3'"!]ADC12BSARV2_CFG1_ALTCLK3_U32[!ELSE!]ADC12BSARV2_CFG1_ALTCLK4_U32[!ENDIF!],
[!ELSE!][!//
        ADC12BSARV2_CFG1_ALTCLK1_U32,
[!ENDIF!][!//
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Main configuration of CFG2 registers */
        /* Sample time duration */
[!IF "node:exists(AdcNormalConversionTimings)"!][!//
        (uint32)[!"num:i(AdcNormalConversionTimings/AdcSampleTimeDuration - 1)"!]U,
[!ELSE!][!//
        (uint32)0x2U,
[!ENDIF!][!//
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
        /** Main configuration of SC2 registers */
        ADC12BSARV2_SC2_ADTRG_HW_U32 |
        ADC12BSARV2_SC2_ACFE_DIS_U32 |
        ADC12BSARV2_SC2_ACFGT_LESS_U32 |
        ADC12BSARV2_SC2_ACREN_DIS_U32 |
        ADC12BSARV2_SC2_DMA_DIS_U32 |
        /** Voltage Reference Selection */
        [!IF "AdcVoltageReferenceSelection = 'VREFH_VREFL'"!]ADC12BSARV2_SC2_REFSEL_VREFH_VREFL_U32[!ELSE!] ADC12BSARV2_SC2_REFSEL_VALTH_VALTL_U32[!ENDIF!],
        /** Main configuration of SC3 registers */
        ADC12BSARV2_SC3_CAL_DIS_U32 |
        ADC12BSARV2_SC3_ONESHOT_U32 |
[!IF "node:exists(AdcNormalConversionTimings)"!][!//
        [!IF "AdcNormalConversionTimings/AdcHardwareAverageEnable = 'true'"!]ADC12BSARV2_SC3_AVGE_EN_U32[!ELSE!]ADC12BSARV2_SC3_AVGE_DIS_U32[!ENDIF!] |
        /** Hardware average select */
        [!IF "AdcNormalConversionTimings/AdcHardwareAverageSelect = 'SAMPLES_4'"!]ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32[!ELSEIF "AdcNormalConversionTimings/AdcHardwareAverageSelect = 'SAMPLES_8'"!]ADC12BSARV2_SC3_AVGS_8_SAMPLES_U32[!ELSEIF "AdcNormalConversionTimings/AdcHardwareAverageSelect = 'SAMPLES_16'"!]ADC12BSARV2_SC3_AVGS_16_SAMPLES_U32[!ELSE!] ADC12BSARV2_SC3_AVGS_32_SAMPLES_U32[!ENDIF!],
[!ELSE!][!//
        ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32,
[!ENDIF!][!//
#if (STD_ON == ADC_DUAL_CLOCK_MODE)
        /** Alternate configuration of CFG1 registers */
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true')"!][!//
[!IF "node:exists(AdcAlternateConversionTimings)"!][!//
        [!IF "AdcAlternateConversionTimings/AdcClockDivideSelectAlternate = 'DIV_NONE'"!]ADC12BSARV2_CFG1_CLOCK_DIV1_U32[!ELSEIF "AdcAlternateConversionTimings/AdcClockDivideSelectAlternate = 'DIV_2'"!]ADC12BSARV2_CFG1_CLOCK_DIV2_U32[!ELSEIF "AdcAlternateConversionTimings/AdcClockDivideSelectAlternate = 'DIV_4'"!]ADC12BSARV2_CFG1_CLOCK_DIV4_U32[!ELSE!]ADC12BSARV2_CFG1_CLOCK_DIV8_U32[!ENDIF!] |
[!ELSE!][!//
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32 |
[!ENDIF!][!//
        /* Conversion Mode Selection */
        [!IF "AdcResolution = 'BITS_8'"!]ADC12BSARV2_CFG1_8_BITS_RESOLUTION_U32[!ELSEIF "AdcResolution = 'BITS_10'"!]ADC12BSARV2_CFG1_10_BITS_RESOLUTION_U32[!ELSEIF "AdcResolution = 'BITS_12'"!]ADC12BSARV2_CFG1_12_BITS_RESOLUTION_U32[!ENDIF!] |
        /* Input Clock Select */
[!IF "node:exists(AdcClockSource)"!][!//
        [!IF "AdcClockSource = 'ADC_ALTCLK1'"!]ADC12BSARV2_CFG1_ALTCLK1_U32[!ELSEIF "AdcClockSource = 'ADC_ALTCLK2'"!]ADC12BSARV2_CFG1_ALTCLK2_U32[!ELSEIF "AdcClockSource = 'ADC_ALTCLK3'"!]ADC12BSARV2_CFG1_ALTCLK3_U32[!ELSE!]ADC12BSARV2_CFG1_ALTCLK4_U32[!ENDIF!],
[!ELSE!][!//
        ADC12BSARV2_CFG1_ALTCLK1_U32,
[!ENDIF!][!//
[!ELSE!][!//
        (uint32)0U,
[!ENDIF!][!//
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Alternate configuration of CFG2 registers */
        /* Sample time duration */
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true')"!][!//
[!IF "node:exists(AdcAlternateConversionTimings)"!][!//
        (uint32)[!"num:i(AdcAlternateConversionTimings/AdcSampleTimeDurationAlternate - 1)"!],
[!ELSE!][!//
        (uint32)0x2U,
[!ENDIF!][!//
[!ELSE!][!//
        (uint32)0U,
[!ENDIF!][!//
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
        /** Alternate configuration of SC2 registers */
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true')"!][!//
        ADC12BSARV2_SC2_ADTRG_SW_U32 |
        ADC12BSARV2_SC2_ACFE_DIS_U32 |
        ADC12BSARV2_SC2_ACFGT_LESS_U32 |
        ADC12BSARV2_SC2_ACREN_DIS_U32 |
        ADC12BSARV2_SC2_DMA_DIS_U32 |
        /** Voltage Reference Selection */
        [!IF "AdcVoltageReferenceSelection = 'VREFH_VREFL'"!]ADC12BSARV2_SC2_REFSEL_VREFH_VREFL_U32[!ELSE!] ADC12BSARV2_SC2_REFSEL_VALTH_VALTL_U32[!ENDIF!],
[!ELSE!][!//
        (uint32)0U,
[!ENDIF!][!//
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
        /** Alternate configuration of SC3 registers */
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true')"!][!//
        ADC12BSARV2_SC3_CAL_DIS_U32 |
        ADC12BSARV2_SC3_ONESHOT_U32 |
[!IF "node:exists(AdcAlternateConversionTimings)"!][!//
        [!IF "AdcAlternateConversionTimings/AdcHardwareAverageEnableAlternate = 'true'"!]ADC12BSARV2_SC3_AVGE_EN_U32[!ELSE!]ADC12BSARV2_SC3_AVGE_DIS_U32[!ENDIF!] |
        /** Hardware average select */
        [!IF "AdcAlternateConversionTimings/AdcHardwareAverageSelectAlternate = 'SAMPLES_4'"!]ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32 [!ELSEIF "AdcAlternateConversionTimings/AdcHardwareAverageSelectAlternate = 'SAMPLES_8'"!]ADC12BSARV2_SC3_AVGS_8_SAMPLES_U32[!ELSEIF "AdcAlternateConversionTimings/AdcHardwareAverageSelectAlternate = 'SAMPLES_16'"!]ADC12BSARV2_SC3_AVGS_16_SAMPLES_U32[!ELSE!] ADC12BSARV2_SC3_AVGS_32_SAMPLES_U32[!ENDIF!],
[!ELSE!][!//
        ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32,
[!ENDIF!][!//
[!ELSE!][!//
        (uint32)0U,
[!ENDIF!][!//
#endif /*(STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)*/
#endif /* (STD_ON == ADC_DUAL_CLOCK_MODE) */
        /** ===== OFS register ===== */
        [!"AdcOffsetCorrectionValue"!]U,
        /** ===== Bitmask for converted data ===== */
        [!IF "AdcResolution = 'BITS_8'"!]ADC12BSARV2_RESULT_DATA_MASK_8_BIT_U32[!ELSEIF "AdcResolution = 'BITS_10'"!]ADC12BSARV2_RESULT_DATA_MASK_10_BIT_U32[!ELSEIF "AdcResolution = 'BITS_12'"!]ADC12BSARV2_RESULT_DATA_MASK_12_BIT_U32[!ENDIF!],
        /** ===== Adc bit resolution ===== */
        [!IF "AdcResolution = 'BITS_8'"!]ADC_BITS_RESOLUTION_8_U8[!ELSEIF "AdcResolution = 'BITS_10'"!]ADC_BITS_RESOLUTION_10_U8[!ELSEIF "AdcResolution = 'BITS_12'"!]ADC_BITS_RESOLUTION_12_U8[!ENDIF!],
        /** ===== PDB Clock Settings ===== */
[!IF "node:exists(AdcPdbSettings)"!][!//
        (([!"AdcPdbSettings/AdcPdbPrescalerDividerSelect"!]UL << 12U) | [!// 
        ([!"AdcPdbSettings/AdcPdbMultiplicationFactorSelect"!]UL << 2U)) | [!//
        [!IF "AdcPdbSettings/AdcPdbChannelSequenceErrorEnable = 'true'"!]0x00020000UL[!ELSE!]0x0UL[!ENDIF!]
[!ELSE!][!//
        0U
[!ENDIF!][!//
#if (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED))
        ,
        /**< @brief Pdb error notification function */
[!IF "node:exists(AdcPdbSettings/AdcPdbErrorNotification) and (AdcPdbSettings/AdcPdbErrorNotification != 'NULL_PTR')"!][!//
        [!IF "AdcPdbSettings/AdcPdbErrorNotification != 'NULL_PTR'"!]&[!"AdcPdbSettings/AdcPdbErrorNotification"!][!ELSE!][!"AdcPdbSettings/AdcPdbErrorNotification"!][!ENDIF!]
[!ELSE!]
        NULL_PTR
[!ENDIF!][!//
#endif /* (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED)) */
    }[!IF "$Unit < num:i($maxUnitCfg)"!],[!ENDIF!][!//
[!VAR "CRT_COUNT"="$CRT_COUNT+1"!][!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_Config"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!VAR "LoopVar"="0"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcHwUnitId = concat('ADC',string($Unit))"!][!//
[!VAR "UnitExits"="1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
[!VAR "LoopVar"="0"!][!//
/**
* @brief          Definition of channels on ADC Hardware unit for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
* @details        Array of conversion command messages
*/
static CONST(Adc_Adc12bsarv2_ChannelConfigurationType, ADC_CONST) Adc_ChannelsCfg_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "numChannel" = "num:i(count(AdcConfigSet/AdcHwUnit/*[AdcHwUnitId=concat('ADC',string($Unit))]/AdcChannel/*)-1)"!][!//
[!FOR "x" = "0" TO "$numChannel"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*[AdcHwUnitId=concat('ADC',string($Unit))]/AdcChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',string($Unit))"!][!//
[!IF "AdcLogicalChannelId = $Loop"!][!//
    /**< @brief Hardware Unit [!"../../AdcHwUnitId"!]  --  [!"AdcChannelId"!] */
    {
[!IF "starts-with(AdcChannelId, 'AN_')"!][!//
[!VAR "ChannelId" = "num:i(substring-after(AdcChannelId,'AN_'))"!][!//
[!IF "$ChannelId > 15"!][!//
[!VAR "ChannelId" = "$ChannelId + 16"!][!//
[!ENDIF!][!//
[!ELSEIF "AdcChannelId = 'INT_AN_0'"!][!//
[!VAR "ChannelId" = "21"!][!//
[!ELSEIF "AdcChannelId = 'BAND_GAP'"!][!//
[!VAR "ChannelId" = "27"!][!//
[!ELSEIF "AdcChannelId = 'VREFH'"!][!//
[!VAR "ChannelId" = "29"!][!//
[!ELSEIF "AdcChannelId = 'VREFL'"!][!//
[!VAR "ChannelId" = "30"!][!//
[!ENDIF!][!//
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8([!"num:i($ChannelId)"!]))
    }[!IF "$x < $numChannel"!],[!ELSE!][!ENDIF!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
};
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_LimitChecking_Config"!][!//
[!VAR "maxUnit"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcLogicalUnitId = $Unit"!][!//
[!VAR "UnitExits"="1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
[!VAR "LoopVar"="0"!][!//
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of channels limit checking on ADC logical unit [!"$Unit"!].
*/
static CONST(Adc_ChannelLimitCheckingType, ADC_CONST) Adc_aChannelsLimitCheckingCfg_[!"$Unit"!][] =
{
[!VAR "numChannel" = "num:i(count(AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId=$Unit]/AdcChannel/*)-1)"!][!//
[!FOR "x" = "0" TO "$numChannel"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId=$Unit]/AdcChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "AdcLogicalChannelId = $Loop"!][!//
    /**< @brief ADC logical Id [!"$Unit"!]  --  Channel logical Id [!"AdcLogicalChannelId"!] */
    {
[!IF "node:exists(AdcChannelLimitCheck) and AdcChannelLimitCheck ='true'"!][!//
        /**< @brief limit check enabled */
        /**< @brief range for limit check */
[!IF "node:exists(AdcChannelRangeSelect)"!][!//
        (Adc_ChannelRangeSelectType)[!"AdcChannelRangeSelect"!],
[!ELSE!][!//
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
[!ENDIF!][!//
        /**< @brief high limit value */
[!IF "node:exists(AdcChannelHighLimit)"!][!//
        (Adc_ValueGroupType)[!"num:i(AdcChannelHighLimit)"!],
[!ELSE!][!//
        (Adc_ValueGroupType)0,
[!ENDIF!][!//
        /**< @brief low limit value */
[!IF "node:exists(AdcChannelLowLimit)"!][!//
        (Adc_ValueGroupType)[!"num:i(AdcChannelLowLimit)"!]
[!ELSE!][!//
        (Adc_ValueGroupType)0,
[!ENDIF!][!//
[!ELSE!][!//
        /**< @brief limit check disabled */
        /**< @brief range for limit check */
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
        /**< @brief high limit value */
        (Adc_ValueGroupType)0,
        /**< @brief low limit value */
        (Adc_ValueGroupType)0
[!ENDIF!][!//
    }[!IF "$x < $numChannel"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
};
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_ResultBuffer_Config"!][!//
/**
* @brief          Adc Result Buffer RAM initializations.
* @details        Array for all ADC group result ram buffers.
*/
[!VAR "MAX_NUM"="count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)"!][!//
[!VAR "CRT_NUM"="1"!][!//
static P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) Adc_aResultsBufferPtr[] =
{
[!FOR "x" = "1" TO "$MAX_NUM"!][!//
    NULL_PTR[!IF "$CRT_NUM<$MAX_NUM"!],[!ENDIF!]
[!VAR "CRT_NUM"="$CRT_NUM+1"!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_Pointer_Config"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
/**
* @brief          Definition of channels' pointer structure for variant [!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!] [!ENDIF!] Configuration.
*
*/
static P2CONST(Adc_Adc12bsarv2_ChannelConfigurationType, ADC_VAR, ADC_APPL_CONST) Adc_ChannelsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcHwUnitId = concat('ADC',string($Unit))"!][!//
[!VAR "UnitExits"="1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 0"!][!//
    NULL_PTR[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ELSE!][!//
    Adc_ChannelsCfg_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_LimitChecking_Pointer_Config"!][!//
[!VAR "maxUnitCfg"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of channels' limit checking pointer structure.
*
*/
P2CONST(Adc_ChannelLimitCheckingType, ADC_VAR, ADC_APPL_CONST) Adc_aChannelsLimitCheckingCfg[] =
{
[!FOR "Unit" = "0" TO "num:i($maxUnitCfg)"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcLogicalUnitId = $Unit"!][!//
    Adc_aChannelsLimitCheckingCfg_[!"$Unit"!][!IF "$Unit < num:i($maxUnitCfg)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
#endif
[!ENDMACRO!][!//

[!MACRO "Adc_HwTriggerSource_Config"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW'"!][!//
/**
* @brief          Hardware trigger sources configured for group [!"AdcGroupId"!] - for configuration variant [!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
* 
*/
static CONST(Adc_HwTriggerTimerType, ADC_CONST) Adc_GroupTriggerSource[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][1] =
{
    (Adc_HwTriggerTimerType)0U
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Group_Config"!][!//
/**
* @brief          Definition of all ADC groups for configuration varaint [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!] .
*/
static CONST(Adc_GroupConfigurationType, ADC_CONST) Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "LoopVar"="0"!][!//
[!VAR "MaxGroups"="num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1)"!][!//
[!FOR "x" = "0" TO "$MaxGroups"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "AdcGroupId = $Loop"!][!//
    /**< @brief Group[!"AdcGroupId"!] -- Hardware Unit [!"../../AdcHwUnitId"!] */
    {
        /**< @brief Hardware unit configured */
        (Adc_HwUnitType)[!"substring-after(string(../../AdcHwUnitId),'ADC')"!],
        /**< @brief Access mode */
        [!"AdcGroupAccessMode"!],
        /**< @brief Conversion mode */
        [!"AdcGroupConversionMode"!],
        /**< @brief Conversion type */
        ADC_CONV_TYPE_NORMAL,
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        [!IF "../../../../../AdcGeneral/AdcPriorityImplementation != 'ADC_PRIORITY_NONE' and node:exists(AdcGroupPriority)"!]((Adc_GroupPriorityType)([!"AdcGroupPriority"!])),[!ELSE!]((Adc_GroupPriorityType)(0U)),[!ENDIF!]
#endif
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART,
        /**< @brief Trigger source configured */
        [!"AdcGroupTriggSrc"!],
#if (STD_ON==ADC_HW_TRIGGER_API)
        /**< @brief Hardware trigger signal */
        [!IF "(../../../../../AdcGeneral/AdcHwTriggerApi = 'true') and (AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW') and node:exists(AdcHwTrigSignal)"!][!"AdcHwTrigSignal"!],[!ELSE!]ADC_HW_TRIG_BOTH_EDGES,[!ENDIF!]
        /**< @brief Hardware resource for the group*/
        [!IF "(../../../../../AdcGeneral/AdcHwTriggerApi = 'true') and (AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW')"!]Adc_GroupTriggerSource[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!][!"num:i(0)"!]U,[!ENDIF!]
#endif /* (STD_ON==ADC_HW_TRIGGER_API) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
[!IF "../../../../../AdcGeneral/AdcGrpNotifCapability = 'true' and node:exists(AdcNotification)"!][!//
        [!IF "AdcNotification != 'NULL_PTR'"!]&[!"AdcNotification"!],[!ELSE!]NULL_PTR,[!ENDIF!]
[!ELSE!]
        NULL_PTR,
[!ENDIF!][!//
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
[!IF "(../../../../../NonAutosar/AdcEnableInitialNotification = 'true')"!][!//
        [!IF "AdcExtraNotification != 'NULL_PTR'"!]&[!"AdcExtraNotification"!],[!ELSE!][!"AdcExtraNotification"!],[!ENDIF!]
[!ELSE!]
        NULL_PTR,
[!ENDIF!][!//
#endif
        /**< @brief ADC Group Result Buffers RAM array */
        Adc_aResultsBufferPtr,
        /**< @brief Group Streaming Buffer Mode */
        [!"AdcStreamingBufferMode"!],
        /**< @brief Number of streaming samples */
        ((Adc_StreamNumSampleType)([!"AdcStreamingNumSamples"!])),
        /**< @brief Channels assigned to the group*/
        Adc_Group[!"AdcGroupId"!]_Assignment_[!"num:i(substring-after(../../AdcHwUnitId, 'ADC'))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        /**< @brief Channel Delays assigned to the group*/
        [!IF "AdcGroupUsesChannelDelays = 'true'"!]Adc_Group[!"AdcGroupId"!]_Delays_[!"num:i(substring-after(../../AdcHwUnitId, 'ADC'))"!]_[!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!],
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS,
#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
         /* Group Normal Conversion Timings */
[!IF "node:exists(AdcGroupNormalConversionTimings)"!][!//
        (uint32)[!"num:i(AdcGroupNormalConversionTimings/AdcGroupSampleTimeDuration - 1)"!]UL,
[!IF "AdcGroupNormalConversionTimings/AdcGroupHardwareAverageEnable = 'true'"!][!//
        (uint32)(ADC12BSARV2_SC3_AVGE_EN_U32 | [!IF "AdcGroupNormalConversionTimings/AdcGroupHardwareAverageSelect = 'SAMPLES_4'"!]ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32 [!ELSEIF "AdcGroupNormalConversionTimings/AdcGroupHardwareAverageSelect = 'SAMPLES_8'"!]ADC12BSARV2_SC3_AVGS_8_SAMPLES_U32[!ELSEIF "AdcGroupNormalConversionTimings/AdcGroupHardwareAverageSelect = 'SAMPLES_16'"!]ADC12BSARV2_SC3_AVGS_16_SAMPLES_U32[!ELSE!] ADC12BSARV2_SC3_AVGS_32_SAMPLES_U32[!ENDIF!]),
[!ELSE!][!//
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
[!ENDIF!][!//
        (uint32)[!IF "AdcGroupNormalConversionTimings/AdcGroupClockDivideSelect = 'DIV_NONE'"!]ADC12BSARV2_CFG1_CLOCK_DIV1_U32[!ELSEIF "AdcGroupNormalConversionTimings/AdcGroupClockDivideSelect = 'DIV_2'"!]ADC12BSARV2_CFG1_CLOCK_DIV2_U32[!ELSEIF "AdcGroupNormalConversionTimings/AdcGroupClockDivideSelect = 'DIV_4'"!]ADC12BSARV2_CFG1_CLOCK_DIV4_U32[!ELSE!]ADC12BSARV2_CFG1_CLOCK_DIV8_U32[!ENDIF!],
[!ELSE!][!//
        2UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32,
[!ENDIF!][!//
         /* Group Alternate Conversion Timings */
        #if (ADC_DUAL_CLOCK_MODE == STD_ON)
[!IF "node:exists(AdcGroupAlternateConversionTimings)"!][!//
        (uint32)[!"num:i(AdcGroupAlternateConversionTimings/AdcGroupAltSampleTimeDuration - 1)"!]UL,
[!IF "AdcGroupAlternateConversionTimings/AdcGroupAltHardwareAverageEnable = 'true'"!][!//
        (uint32)(ADC12BSARV2_SC3_AVGE_EN_U32 | [!IF "AdcGroupAlternateConversionTimings/AdcGroupAltHardwareAverageSelect = 'SAMPLES_4'"!]ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32 [!ELSEIF "AdcGroupAlternateConversionTimings/AdcGroupAltHardwareAverageSelect = 'SAMPLES_8'"!]ADC12BSARV2_SC3_AVGS_8_SAMPLES_U32[!ELSEIF "AdcGroupAlternateConversionTimings/AdcGroupAltHardwareAverageSelect = 'SAMPLES_16'"!]ADC12BSARV2_SC3_AVGS_16_SAMPLES_U32[!ELSE!] ADC12BSARV2_SC3_AVGS_32_SAMPLES_U32[!ENDIF!]),
[!ELSE!][!//
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
[!ENDIF!][!//
        (uint32)[!IF "AdcGroupAlternateConversionTimings/AdcGroupAltClockDivideSelect = 'DIV_NONE'"!]ADC12BSARV2_CFG1_CLOCK_DIV1_U32[!ELSEIF "AdcGroupAlternateConversionTimings/AdcGroupAltClockDivideSelect = 'DIV_2'"!]ADC12BSARV2_CFG1_CLOCK_DIV2_U32[!ELSEIF "AdcGroupAlternateConversionTimings/AdcGroupAltClockDivideSelect = 'DIV_4'"!]ADC12BSARV2_CFG1_CLOCK_DIV4_U32[!ELSE!]ADC12BSARV2_CFG1_CLOCK_DIV8_U32[!ENDIF!],
[!ELSE!][!//
        2UL,
        (uint32)(ADC12BSARV2_SC3_AVGE_DIS_U32 | ADC12BSARV2_SC3_AVGS_4_SAMPLES_U32),
        ADC12BSARV2_CFG1_CLOCK_DIV1_U32,
[!ENDIF!][!//
        #endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE) */
        /**< @brief Enables or Disables the ADC Back to Back configuration for Group channels */  
        (uint8)[!IF "AdcGroupInBacktoBackMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!],
        /**< @brief Enables or Disables the ADC pre-trigger delay configuration for each Group Channel */
        (uint8)[!IF "AdcGroupUsesChannelDelays"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!],
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)[!IF "AdcWithoutInterrupts"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        ,
        /**< @brief Enables or Disables the ADC double buffering feature */
        (boolean)[!IF "AdcEnableDoubleBuffering"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!],
        /**< @brief Enable/disable half interrupt  for group with double bufferring*/
        (boolean)[!IF "AdcEnableHalfInterrupt"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
        ,
        (uint16)[!"AdcDelayNextPdb"!]
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
        ,
        (uint16)[!"AdcPdbPeriodContinuousMode"!]
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        ,
        /**< @brief Enables or disables the usage of limit checking for an ADC group. */
        (boolean)[!IF "node:exists(node:refs(AdcGroupDefinition/*)/AdcChannelLimitCheck) and (node:refs(AdcGroupDefinition/*)/AdcChannelLimitCheck = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]
#endif /* (STD_ON == ADC_ENABLE_LIMIT_CHECK) */
    }[!IF "$x < $MaxGroups"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
};

[!ENDMACRO!][!//

[!MACRO "Adc_Structure_Config"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
/**
* @brief          ADC driver Configuration structure [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
/** @violates @ref Adc[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5 MISRA-C:2004 Rule 8.10: External linkage.*/
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
CONST(Adc_ConfigType, ADC_CONST) Adc_PBCfgVariantPredefined =
[!ELSE!][!//
CONST(Adc_ConfigType, ADC_CONST) [!"as:name(AdcConfigSet)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ENDIF!][!//
{
    /**< @brief pointer to Hw unit configurations */
    Adc_HwUnitCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief pointer to group configurations */
    Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief pointer to channel configurations */
    Adc_ChannelsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief total number of groups */
    (Adc_GroupType)ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief Miscellaneous configuration parameters. - Adc_Adc12bsarv2_MultiConfigType */
    {
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!]
            [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!][!"AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcTransferType"!][!ELSE!]ADC_INTERRUPT[!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!]
        },
        /**< @brief number of the maximum groups in the current configuration */
        [!"num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*))"!]U,
        /**< @brief number of the maximum hardware units in the current configuration */
        [!"num:i(count(AdcConfigSet/AdcHwUnit/*))"!]U,
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!NOCODE!][!//
[!VAR "DmaChannelId"="255"!]
[!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!]
    [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcTransferType = 'ADC_DMA'"!]
        [!LOOP "node:refs('ASPathDataOfSchema:/TS_T40D2M10I1R0/Mcl')/MclConfigSet/*[1]/DMAChannel/*[MclDMAChannelEnable = 'true']"!]
            [!VAR "temp"="node:value(string(concat('DmaSource',string(num:i(num:i(substring-after(DmaHwChannel,'eDMA_')) div 16)))))"!][!//
            [!IF "$temp = concat('ADC',$Unit,'_COCO')"!]
                [!VAR "DmaChannelId"="num:i(MclDMAChannelId)"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
            /** The DMA channel number for ADC [!"$Unit"!] */
            (uint8)[!"num:i($DmaChannelId)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
#ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
#if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!NOCODE!][!//
[!VAR "DmaChannelId2"="255"!]
[!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!]
    [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcTransferType = 'ADC_DMA'"!]
        [!LOOP "node:refs('ASPathDataOfSchema:/TS_T40D2M10I1R0/Mcl')/MclConfigSet/*[1]/DMAChannel/*[MclDMAChannelEnable = 'true']"!]
            [!VAR "temp"="node:value(string(concat('DmaSource',string(num:i(num:i(substring-after(DmaHwChannel,'eDMA_')) div 16)))))"!][!//
            [!VAR "temp2"="node:value(MclDmaTransferCompletionNotif)"!][!//
            [!IF "$temp = 'NOT_USED'"!]
                [!IF "$temp2 = concat('Adc_Adc12bsarv2_DmaTransferComplete',$Unit)"!]
                    [!VAR "DmaChannelId2"="num:i(MclDMAChannelId)"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
            /** The DMA channel number for ADC use double bufferring [!"$Unit"!] */
            (uint8)[!"num:i($DmaChannelId2)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
#endif
#endif
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
            /**< @brief ADC_UNIT_[!"$Unit"!] - ON/OFF */
            [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!NOCODE!][!//
    [!VAR "LogicalUnit"="255"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
        [!IF "AdcHwUnitId = concat('ADC',string($Unit))"!][!//
            [!VAR "LogicalUnit" = "num:i(AdcLogicalUnitId)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!CODE!][!//
            [!"num:i($LogicalUnit)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!//
        }
    }
};
[!ENDMACRO!][!//

[!MACRO "Adc_ETimeout_Config"!][!//
/** @violates @ref Adc_Cfg_c_REF_5 MISRA-C:2004 Rule 8.10: External linkage.*/
CONST(Mcal_DemErrorType, ADC_CONST) Adc_E_TimeoutCfg = 
{
[!IF "node:exists(AdcDemEventParameterRefs/ADC_E_TIMEOUT)"!][!//
    (uint32)STD_ON,
    (uint16)DemConf_DemEventParameter_[!"node:ref(AdcDemEventParameterRefs/ADC_E_TIMEOUT)/@name"!]
[!ELSE!][!//
    (uint32)STD_OFF,
    (uint16)0U
[!ENDIF!][!//
};
[!ENDMACRO!][!//

[!MACRO "AdcExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(AdcConfigSet)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
[!CODE!][!//
/** @violates @ref Adc_cfg_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(Adc_ConfigType, ADC_CONST) [!"$configName"!]_[!"."!];
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!][!//
/** @violates @ref Adc_cfg_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(Adc_ConfigType, ADC_CONST) [!"$configName"!];
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!ENDIF!]

/** @} */
