[!NOCODE!]
/**
    @file    CDD_I2c_RegOperations.m
    @version 1.0.1

    @brief   AUTOSAR I2c - Register operations.
    @details Register operations.

    Project AUTOSAR 4.2 MCAL
    Platform ARM
    Peripheral LPI2C
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

[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('I2C_REG_OPERATIONS_42_M'))"!][!//
[!VAR "I2C_REG_OPERATIONS_42_M"="'true'"!][!//

[!MACRO "CheckFlexIOPinConsistency"!]
[!NOCODE!]
    [!SELECT "I2cGlobalConfig"!]
        [!VAR "ConfigIndexA" = "@name"!]
        [!"$ConfigIndexA"!]
        [!LOOP "./I2cChannel/*"!]
            [!IF "contains(I2cHwChannel,'FLEXIO')"!]
                [!VAR "channelSettingMain" = "@name"!]
                [!VAR "firstsdaPin" = "./I2cFlexIOConfiguration/I2cFlexIOSdaPin"!]
                [!VAR "firstsclPin" = "./I2cFlexIOConfiguration/I2cFlexIOSclPin"!]
                    [!LOOP "../../I2cChannel/*"!]
                    [!IF "contains(I2cHwChannel,'FLEXIO')"!]
                        [!VAR "channelSettingSlave" = "@name"!]
                        [!IF "$channelSettingSlave != $channelSettingMain"!]
                            [!VAR "secondsdaPin" = "./I2cFlexIOConfiguration/I2cFlexIOSdaPin"!]
                            [!VAR "secondsclPin" = "./I2cFlexIOConfiguration/I2cFlexIOSclPin"!]
                            [!IF "($firstsdaPin = $secondsdaPin) or ($firstsdaPin = $secondsclPin) or ($firstsclPin = $secondsdaPin) or ($firstsclPin = $secondsclPin)"!]
                                [!ERROR!]
        In [!"$ConfigIndexA"!] the channels [!"$channelSettingMain"!] and [!"$channelSettingSlave"!] have a pin conflict. A pin can be only used once.
                                [!ENDERROR!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "I2c_Dem_Config","Type"!][!//
[!NOCODE!]
    [!VAR "I2cDemEventParameter"!]I2C_E_TIMEOUT_FAILURE[!ENDVAR!]
    [!VAR "DemErrorCount" = "num:i(count(text:split($I2cDemEventParameter, ',')))"!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
/** @violates @ref CDD_I2c_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 8.10, external linkage */
CONST( I2c_DemConfigType, I2C_CONST) I2c_DemConfig =
{
[!ENDCODE!]
    [!FOR "Index" = "1" TO "num:i($DemErrorCount)"!]
        [!VAR "ErrorName" = "normalize-space(text:split($I2cDemEventParameter, ',')[num:i($Index)])"!]
        [!IF "node:exists(I2cGlobalConfig/I2cDemEventParameterRefs)"!]
            [!VAR "DemRefNode" = "concat('I2cGlobalConfig/I2cDemEventParameterRefs/',$ErrorName)"!]
            [!IF "node:exists($DemRefNode)"!]
                [!IF "node:refvalid($DemRefNode)"!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_ON, DemConf_DemEventParameter_[!"node:ref(node:value($DemRefNode))/@name"!]}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
                [!ELSE!]
                     [!ERROR "Invalid reference for $ErrorName"!]
                [!ENDIF!]
            [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
            [!ENDIF!]
        [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!]
};
#endif /* (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "I2c_ChannelConfig","Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!SELECT "I2cGlobalConfig"!][!//
    [!IF "num:i(count(I2cChannel/*))>0"!]
        [!VAR "Channel"= "num:i(count(I2cChannel/*))-1"!]
        [!VAR "FlexIOChannel"= "num:i(0)"!]
    [!LOOP "I2cChannel/*"!]
        [!IF "contains(I2cHwChannel,'LPI2C')"!]
[!CODE!]
/**
* @brief        Definition of LPI2C hardware channel structure.
* @details      Configures the hardware peripheral of a LPI2C channel.
*               Configuration set by calling I2c_Init() API.
*/
/** @violates @ref CDD_I2c_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_4 MISRA 2004 Required Rule 1.4, 31 character significance */
static CONST( I2c_LPI2C_HwChannelConfigType, I2C_CONST) I2c_LPI2CChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!]Ch[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Master Control Config */
    (
    /* Debug Enable. */
    [!IF "I2cMasterConfiguration/I2cMasterEnabledInDebug"!]LPI2C_MCR_MASTER_ENABLED_IN_DBG_U32[!ELSE!]LPI2C_MCR_MASTER_DISABLED_IN_DBG_U32[!ENDIF!] |
    /* Doze Mode Enable. */
    [!IF "I2cMasterConfiguration/I2cMasterEnabledInDozeMode"!]LPI2C_MCR_MASTER_ENABLED_IN_DOZE_U32[!ELSE!]LPI2C_MCR_MASTER_DISABLED_IN_DOZE_U32[!ENDIF!]
    ),
    
    /* Master Config 1 */
    (LPI2C_[!"substring-after(I2cPinConfiguration,'PINCFG_')"!]_U32 |
    LPI2C_PRESCALE_U32((uint32)[!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(1)"!]0U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(2)"!]1U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(4)"!]2U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(8)"!]3U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(16)"!]4U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(32)"!]5U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(64)"!]6U[!ELSE!][!//
    [!IF "num:i(substring-after(I2cMasterConfiguration/I2cPrescaler,'DIVIDE_BY_')) = num:i(128)"!]7U[!//
    [!ENDIF!][!ENDIF!][!ENDIF!][!ENDIF!][!ENDIF!][!ENDIF!][!ENDIF!][!ENDIF!])
    ),
    
    /* Master Config 2 */
    (LPI2C_FILTSDA_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cGlitchFilterSDA)"!]U) |
     LPI2C_FILTSCL_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cGlitchFilterSCL)"!]U) |
     LPI2C_BUSIDLE_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cBusIdleTimeout)"!]U)
    ),
    
    /* Master Config 3 */
    (LPI2C_PINLOW_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cPinLowTimeout)"!]U)),
    
    /* Clock Config 0 */
    (LPI2C_DATAVD_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cDataValidDelay)"!]U) |
     LPI2C_SETHOLD_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cSetupHoldDelay)"!]U) |
     LPI2C_CLKHI_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cClockHighPeriod)"!]U) |
     LPI2C_CLKLO_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cClockLowPeriod)"!]U)
    ),
    
    /* Clock Config 1 - for High Speed */
    (LPI2C_DATAVD_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cDataValidDelay)"!]U) |
     LPI2C_SETHOLD_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cSetupHoldDelay)"!]U) |
     LPI2C_CLKHI_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cClockHighPeriod)"!]U) |
     LPI2C_CLKLO_U32((uint32)[!"num:i(I2cMasterConfiguration/I2cHighSpeedModeConfiguration/I2cClockLowPeriod)"!]U)
    ),
    
    /* Slave Control Config */
    (
    /* Filter Enable. */
    [!IF "I2cSlaveConfiguration/I2cSlaveFilterEnable"!]LPI2C_SCR_FILTER_ENABLED_U32[!ELSE!]LPI2C_SCR_FILTER_DISABLED_U32[!ENDIF!] |
    /* Doze Mode Enable. */
    [!IF "I2cSlaveConfiguration/I2cSlaveDisableFilterInDoze"!]LPI2C_SCR_FILTER_DISABLED_IN_DOZE_U32[!ELSE!]LPI2C_SCR_FILTER_ENABLED_IN_DOZE_U32[!ENDIF!]
    ),
    
    /* Slave Config 1 */
    (
    /* Address matching */
    [!IF "num:i(I2cSlaveConfiguration/I2cSlaveAddress) > num:i(127)"!]LPI2C_SLAVE_MATCH_ADDR0_10BIT_U32[!ELSE!]LPI2C_SLAVE_MATCH_ADDR0_7BIT_U32[!ENDIF!] |
    /* ACK SCL Stall */
    [!IF "I2cSlaveConfiguration/I2cSlaveAckStall"!]LPI2C_ACK_SCL_STALL_ENABLE_U32[!ELSE!]LPI2C_ACK_SCL_STALL_DISABLE_U32[!ENDIF!] |
    /* TX Data SCL Stall. */
    [!IF "I2cSlaveConfiguration/I2cSlaveTxStall"!]LPI2C_TX_DATA_SCL_STALL_ENABLE_U32[!ELSE!]LPI2C_TX_DATA_SCL_STALL_DISABLE_U32[!ENDIF!] |
    /* RX Data SCL Stall. */
    [!IF "I2cSlaveConfiguration/I2cSlaveRxStall"!]LPI2C_RX_DATA_SCL_STALL_ENABLE_U32[!ELSE!]LPI2C_RX_DATA_SCL_STALL_DISABLE_U32[!ENDIF!] |
    /* Address SCL Stall. */
    [!IF "I2cSlaveConfiguration/I2cSlaveAdrStall"!]LPI2C_ADDRESS_SCL_STALL_ENABLE_U32[!ELSE!]LPI2C_ADDRESS_SCL_STALL_DISABLE_U32[!ENDIF!]
    ),
    
    /* Slave Config 2 */
    (LPI2C_SLAVE_FILTSDA_U32((uint32)[!"num:i(I2cSlaveConfiguration/I2cGlitchFilterSDA)"!]U) |
     LPI2C_SLAVE_FILTSCL_U32((uint32)[!"num:i(I2cSlaveConfiguration/I2cGlitchFilterSCL)"!]U) |
     LPI2C_SLAVE_DATAVD_U32((uint32)[!"num:i(I2cSlaveConfiguration/I2cDataValidDelay)"!]U) |
     LPI2C_SLAVE_CLKHOLD_U32((uint32)[!"num:i(I2cSlaveConfiguration/I2cClockHoldPeriod)"!]U)
    ),
    
    /* Slave Address Config */
    (
     LPI2C_ADDR0_U32((uint32)[!"num:i(I2cSlaveConfiguration/I2cSlaveAddress)"!]U)
    )
    
#if (STD_ON == I2C_DMA_USED)
    ,
    [!IF "I2cMasterConfiguration/I2cAsyncMethod = 'DMA'"!]
    [!"node:value(node:ref(I2cMasterConfiguration/I2cDmaTxChannelRef)/MclDMAChannelId)"!]U,
    [!"node:value(node:ref(I2cMasterConfiguration/I2cDmaRxChannelRef)/MclDMAChannelId)"!]U
    [!ELSE!]
    0U,
    0U
    [!ENDIF!]
#endif
};
[!ENDCODE!]
        [!ELSE!]
        [!VAR "FlexIOChannel"= "$FlexIOChannel+1"!]
[!CODE!]
/**
* @brief        Definition of FlexIO hardware channel structure.
* @details      Configures the hardware peripheral of a FlexIO channel.
*               Configuration set by calling I2c_Init() API.
*/
/** @violates @ref CDD_I2c_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_4 MISRA 2004 Required Rule 1.4, 31 character significance */
static CONST( I2c_FlexIO_HwChannelConfigType, I2C_CONST) I2c_FlexIOChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!]Ch[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{

    /* FlexIO control register */
    (
        [!IF "$FlexIOChannel = num:i(1)"!]
        FLEXIO_SW_RESET_ENABLED_U32 |
        [!ENDIF!]
        [!IF "$FlexIOChannel = count(../*[contains(./I2cHwChannel,'FLEXIO0')])"!]
        FLEXIO_MODULE_ENABLED_U32 |
        [!ENDIF!]
        [!IF "../../I2cFlexIOModuleConfiguration/I2cFlexIOEnabledInDebug"!]FLEXIO_ENABLED_IN_DBG_U32[!ELSE!]FLEXIO_DISABLED_IN_DBG_U32[!ENDIF!] |
        [!IF "../../I2cFlexIOModuleConfiguration/I2cFlexIOEnabledInDozeMode"!]FLEXIO_ENABLED_IN_DOZE_U32[!ELSE!]FLEXIO_DISABLED_IN_DOZE_U32[!ENDIF!] |
        [!IF "../../I2cFlexIOModuleConfiguration/I2cFlexIOFastAccessMode"!]FLEXIO_FAST_REGISTER_ACCESS_U32[!ELSE!]FLEXIO_NORMAL_REGISTER_ACCESS_U32[!ENDIF!]
    ),
    /* SCL Timer config */
    {
        /* Timer ID */
        (uint32)[!"substring-before(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U,
        /* Timer Control Config */
        (
            (uint32)(((uint32)((uint32)[!"substring-before(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U << 2U) + 1U) << FLEXIO_TIMCTL_TRGSEL_SHIFT_U32) |
            FLEXIO_TMR_TRIGGER_ACTIVE_LOW_U32 |
            FLEXIO_TMR_INTERNAL_TRIGGER_U32 |
            FLEXIO_TMR_PIN_OPEN_DRAIN_U32 |
            (uint32)(((uint32)[!"I2cFlexIOConfiguration/I2cFlexIOSclPin"!]U) << FLEXIO_TIMCTL_PINSEL_SHIFT_U32) |
            FLEXIO_TMR_PIN_ACTIVE_HIGH_U32 |
            FLEXIO_TMR_DUAL_8BIT_BAUD_U32
        ),
        /* Timer Config Config */
        (
            FLEXIO_TMR_OUT_ZERO_ONLY_ON_ENABLE_U32 |
            FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_U32 |
            FLEXIO_TMR_RST_ON_PIN_EQ_OUT_U32 |
            FLEXIO_TMR_DIS_ON_TMR_COMP_U32 |
            FLEXIO_TMR_EN_ON_TRG_HIGH_U32 |
            FLEXIO_TMR_STOP_BIT_ON_TMR_DIS_U32 |
            FLEXIO_TMR_START_BIT_ENABLED_U32
        ),
        /* Timer Compare Config */
        ((uint32)[!"I2cFlexIOConfiguration/I2cFlexIOCompareValue"!]U)
    },
    /* Control Timer for Shifters config */
    {
        /* Timer ID */
        (uint32)[!"substring-after(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U,
        /* Timer Control Config */
        (
            (uint32)(((uint32)((uint32)[!"substring-before(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U << 2U) + 1U) << FLEXIO_TIMCTL_TRGSEL_SHIFT_U32) |
            FLEXIO_TMR_TRIGGER_ACTIVE_LOW_U32 |
            FLEXIO_TMR_INTERNAL_TRIGGER_U32 |
            FLEXIO_TMR_PIN_OUTPUT_DISABLED_U32 |
            (uint32)(((uint32)[!"I2cFlexIOConfiguration/I2cFlexIOSclPin"!]U) << FLEXIO_TIMCTL_PINSEL_SHIFT_U32) |
            FLEXIO_TMR_PIN_ACTIVE_LOW_U32 |
            FLEXIO_TMR_SINGLE_16BIT_COUNTER_U32
        ),
        /* Timer Config Config */
        (
            FLEXIO_TMR_OUT_ONE_ONLY_ON_ENABLE_U32 |
            FLEXIO_TMR_DECREMENT_ON_PIN_INPUT_U32 |
            FLEXIO_TMR_NEVER_RST_U32 |
            FLEXIO_TMR_DIS_ON_PREV_TMR_DIS_U32 |
            FLEXIO_TMR_EN_ON_PREV_TMR_EN_U32 |
            FLEXIO_TMR_STOP_BIT_ON_TMR_COMP_U32 |
            FLEXIO_TMR_START_BIT_ENABLED_U32
        ),
        /* Timer Compare Config */
        ((uint32)0x0000000FU)
    },
    /* TX Shifter config */
    {
        /* TX Shifter ID */
        (uint32)[!"substring-before(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U,
        (
            (uint32)((uint32)([!"substring-after(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U) << FLEXIO_SHIFTCTL_TIMSEL_SHIFT_U32) |
            FLEXIO_SHIFT_ON_POSEDGE_OF_SHIFT_CLK_U32 |
            FLEXIO_SHIFTER_PIN_OPEN_DRAIN_U32 |
            (uint32)((uint32)((uint32)[!"I2cFlexIOConfiguration/I2cFlexIOSdaPin"!]U) << FLEXIO_SHIFTCTL_PINSEL_SHIFT_U32) |
            FLEXIO_SHIFTER_PIN_ACTIVE_LOW_U32 |
            FLEXIO_SHIFTER_TRANSMIT_MODE_U32
        ),
        (
            FLEXIO_SHIFTER_INPUT_IS_PIN_U32 |
            FLEXIO_STOP_BIT_VALUE_1_U32 |
            FLEXIO_START_BIT_VALUE_0_U32
        )
    },
    /* RX Shifter config */
    {
        /* RX Shifter ID */
        (uint32)[!"substring-after(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U,
        (
            (uint32)((uint32)([!"substring-after(substring-after(node:value(I2cHwChannel),'_'),'_')"!]U) << FLEXIO_SHIFTCTL_TIMSEL_SHIFT_U32) |
            FLEXIO_SHIFT_ON_NEGEDGE_OF_SHIFT_CLK_U32 |
            FLEXIO_SHIFTER_PIN_OUTPUT_DISABLED_U32 |
            (uint32)((uint32)((uint32)[!"I2cFlexIOConfiguration/I2cFlexIOSdaPin"!]U) << FLEXIO_SHIFTCTL_PINSEL_SHIFT_U32) |
            FLEXIO_SHIFTER_PIN_ACTIVE_HIGH_U32 |
            FLEXIO_SHIFTER_RECEIVE_MODE_U32
        ),
        (
            FLEXIO_SHIFTER_INPUT_IS_PIN_U32 |
            FLEXIO_STOP_BIT_VALUE_0_U32 |
            FLEXIO_START_BIT_DIS_LOAD_ON_EN_U32
        )
    }
#if (STD_ON == I2C_DMA_USED)
    ,
    [!IF "I2cFlexIOConfiguration/I2cAsyncMethod = 'DMA'"!]
    [!"node:value(node:ref(I2cFlexIOConfiguration/I2cDmaTxChannelRef)/MclDMAChannelId)"!]U,
    [!"node:value(node:ref(I2cFlexIOConfiguration/I2cDmaRxChannelRef)/MclDMAChannelId)"!]U
    [!ELSE!]
    0U,
    0U
    [!ENDIF!]
#endif
};
[!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]

[!CODE!]
/**
* @brief        Definition of I2c hardware channel structure.
* @details      Configures the hardware peripheral of an I2c channel.
*               Configuration set by calling I2c_Init() API.
*/
static CONST( I2c_HwUnitConfigType, I2C_CONST) I2c_ChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(I2cChannel/*))"!]] =
{
[!ENDCODE!]
        [!LOOP "I2cChannel/*"!]
            [!VAR "PCindex" = "@index"!]
[!CODE!]
    /* Start of I2c_ChannelConfig[[!"@index"!]]*/
    {
        /* The hardware channel ID. */
        (uint8)[!"node:value(I2cHwChannel)"!],
        
        (I2c_MasterSlaveModeType)I2C_[!"I2cMasterSlaveConfiguration"!],
        
        (I2c_AsynchronousMethodType)I2C_[!IF "contains(node:value(I2cHwChannel), 'LPI2C')"!][!"I2cMasterConfiguration/I2cAsyncMethod"!][!ELSE!][!"I2cFlexIOConfiguration/I2cAsyncMethod"!][!ENDIF!]_MODE,
        

        {
            [!IF "contains(node:value(I2cHwChannel), 'LPI2C')"!]LPI2C_CHANNEL[!ELSE!]FLEXIO_CHANNEL[!ENDIF!],
            
            [!IF "contains(I2cHwChannel,'LPI2C')"!]
            &I2c_LPI2CChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!]Ch[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
            NULL_PTR
            [!ELSE!]
            NULL_PTR,
            &I2c_FlexIOChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!]Ch[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
            [!ENDIF!]
        }
    }[!IF "$PCindex < $Channel"!],[!ENDIF!]/* end of I2c_ChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!][[!"@index"!]]. */
[!ENDCODE!]
        [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
        [!ENDIF!]
        [!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "I2c_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for the I2c driver.
* @details        A pointer to such a structure is provided to the I2c initialization routines for configuration.
*
*/
/** @violates @ref CDD_I2c_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 8.10, external linkage */
CONST(I2c_ConfigType, I2C_CONST) [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]I2c_PBCfgVariantPredefined[!ELSE!][!"as:name(I2cGlobalConfig)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
    /* Number of channel configurations. */
    (I2c_HwUnitType)[!"num:i(count(I2cGlobalConfig/I2cChannel/*))"!]U,

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &I2c_DemConfig,
#endif

    /* Pointer to I2c hardware unit configuration. */
    &I2c_ChannelConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF
[!ENDNOCODE!]
