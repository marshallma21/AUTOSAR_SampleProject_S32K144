[!NOCODE!]
/**
    @file    Mcu_RegOperations.m
    @version 1.0.1

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project AUTOSAR 4.2 MCAL
    Platform ARM
    Peripheral MC
    Dependencies none

    ARVersion 4.2.2
    ARRevision ASR_REL_4_2_REV_0002
    ARConfVariant
    SWVersion 1.0.1
    BuildVersion S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723

    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
    All Rights Reserved.
 */
/*==================================================================================================
==================================================================================================*/


[!// **************************************************************************
[!// Translate 'ItemName' into the item found in 'EnumTranslationList' (e.g. 'WAIT:0;STOP:1;SLEEP:2')


[!MACRO "Mcu_Dem_Config"!][!// 
[!NOCODE!]
    [!VAR "McuDemEventParameter"!]MCU_E_TIMEOUT_FAILURE[!ENDVAR!]
    [!VAR "DemErrorCount" = "num:i(count(text:split($McuDemEventParameter, ',')))"!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
CONST( Mcu_DemConfigType, MCU_CONST) Mcu_Dem_Config = 
{
[!ENDCODE!]
            [!FOR "Index" = "1" TO "num:i($DemErrorCount)"!]
                [!VAR "ErrorName" = "normalize-space(text:split($McuDemEventParameter, ',')[num:i($Index)])"!]
                [!IF "node:exists(McuModuleConfiguration/McuDemEventParameterRefs)"!]
                    [!VAR "DemRefNode" = "concat('McuModuleConfiguration/McuDemEventParameterRefs/',$ErrorName)"!]
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
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "McuLinkerSymbols","Type"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
    [!IF "McuRamSectionSizeLinkerSym != ''"!]
        [!VAR "Externs_SL" = "concat('extern  VAR(uint32, MCU_VAR) ',McuRamSectionSizeLinkerSym,'[];')"!]
        [!CODE!][!//
/**
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_6 MISRA 2004 Required Rule 20.2, The names of standard macros, objects and functions shall not be reused
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_8 MISRA 2004 Required Rule 8.12, The array shall be stated explicitly or defined implicitly by initialisation
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_9 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*/
[!"$Externs_SL"!]
        [!ENDCODE!][!//
    [!ENDIF!]
    [!IF "McuRamSectionBaseAddrLinkerSym != ''"!]
        [!VAR "Externs_BAL" = "concat('extern  VAR(uint8, MCU_VAR) ',McuRamSectionBaseAddrLinkerSym,'[];')"!]
        [!CODE!][!//
/**
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_6 MISRA 2004 Required Rule 20.2, The names of standard macros, objects and functions shall not be reused
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_8 MISRA 2004 Required Rule 8.12, The array shall be stated explicitly or defined implicitly by initialisation
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_9 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*/
[!"$Externs_BAL"!]
        [!ENDCODE!][!//
    [!ENDIF!]
[!ENDLOOP!][!//McuRamSectorSettingConf/*
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!MACRO "Mcu_Ram_Config","Type"!][!//
[!NOCODE!]

[!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0"!]
    [!VAR "var"= "1"!]
    [!VAR "RamSector"= "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))-1"!]
[!CODE!]
/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitClock() API.
*
*/
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_Ram_Config[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]] =
{
[!ENDCODE!]
        [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
            [!VAR "PCindex" = "@index"!]
            [!CALL "MCheckRamSection"!]
[!CODE!]
    {
        /* The ID for Ram Sector configuration. */
        (uint8)[!"num:i(McuRamSectorId)"!]U,

        /* RAM section base address: Start of Mcu_RamConfig[[!"@index"!]]. */
        /** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_5 MISRA 2004 Advisory Rule 11.4, cast between pointer and object */
        /** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        [!IF "McuRamSectionBaseAddrLinkerSym = ''"!](uint8 (*)[1U])[!"num:inttohex(McuRamSectionBaseAddress,8)"!]U[!ELSE!](uint8 (*)[1U])[!"McuRamSectionBaseAddrLinkerSym"!][!ENDIF!],

        /* RAM section size: Section base address (must be aligned to 4 bytes). */
        /** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        [!IF "McuRamSectionSizeLinkerSym = ''"!](uint32)[!"num:inttohex(McuRamSectionSize,8)"!]U,[!ELSE!](uint32)[!"McuRamSectionSizeLinkerSym"!],[!ENDIF!]

        /* RAM default value: Section size in bytes (must be multiple of 4). */
        (uint8)[!"num:inttohex(McuRamDefaultValue,2)"!]U
    }[!IF "$PCindex < $RamSector"!],[!ENDIF!] /* End of Mcu_Ram_Config[!"$Type"!][[!"@index"!]]. */
                [!ENDCODE!]
            [!VAR "var"= "$var+1"!]
        [!ENDLOOP!][!//McuRamSectorSettingConf/*
        [!CODE!]
};
[!ENDCODE!]
        [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Mcu_Mode_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]
            [!VAR "Mode"= "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))-1"!]
[!CODE!]
/**
* @brief        Definition of MCU mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST( Mcu_ModeConfigType, MCU_CONST) Mcu_Mode_Config[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]] =
{
[!ENDCODE!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "PCindex" = "@index"!]
[!CODE!]
    /* Start of Mcu_ModeConfig[[!"@index"!]]*/
    {
        /* The ID for Power Mode configuration. */
        (uint8)[!"num:i(McuMode)"!]U,
        
        /* Power Mode */
        (Mcu_PowerModeType)MCU_[!"McuPowerMode"!]_MODE
    }[!IF "$PCindex < $Mode"!],[!ENDIF!]
    /* end of Mcu_Mode_Config[!"$Type"!][!"num:i($ConfigIndex)"!][[!"@index"!]]. */
[!ENDCODE!]
        [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
        [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "SIM_Clock_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Clock settings from the SIM IP.
* @details      Configures SIM_CHIPCTL[TRACECLK_SEL], SIM_CHIPCTL[CLKOUTSEL] bits and SIM_PLATGC and SIM_CLKDIV4 registers.
*               Configuration set by calling Mcu_InitClock API.
*/
static CONST( Mcu_SIM_ClockConfigType, MCU_CONST) SIM_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* SIM_CHIPCTL settings. */
    (
        SIM_CHIPCTL_TRACECLK_[!"McuSIMClockConfig/McuTraceClockSelect"!]_U32 |
        [!IF "McuSIMClockConfig/McuClockOutEnable"!]SIM_CHIPCTL_CLKOUT_ENABLE_U32[!ELSE!]SIM_CHIPCTL_CLKOUT_DISABLE_U32[!ENDIF!] |
        SIM_CHIPCTL_CLKOUTDIV_U32((uint32)[!"num:i(num:i(McuSIMClockConfig/McuClockOutDivider) - num:i(1))"!]U) |
        SIM_CHIPCTL_CLKOUTSEL_[!"McuSIMClockConfig/McuClockOutSelect"!]_U32
    ),
    /* SIM_CLKDIV4 settings. */
    (
        [!IF "McuSIMClockConfig/McuDebugTraceDividerEnable"!]SIM_DEBUG_TRACE_DIVIDER_ENABLED_U32[!ELSE!]SIM_DEBUG_TRACE_DIVIDER_DISABLED_U32[!ENDIF!] | 
        SIM_CLKDIV4_TRACEDIV_U32((uint32)[!"num:i(McuSIMClockConfig/McuTraceClockDivider)"!]U) |
        [!IF "McuSIMClockConfig/McuTraceClockFraction"!]SIM_CLKDIV4_TRACEFRAC_1_U32[!ELSE!]SIM_CLKDIV4_TRACEFRAC_0_U32[!ENDIF!]
    ),
    /* SIM_PLATGC settings. */
    (
        [!IF "McuSIMClockConfig/McuEIMClockGatingEnable"!]SIM_PLATGC_EIM_CLK_ENABLE_U32[!ELSE!]SIM_PLATGC_EIM_CLK_DISABLE_U32[!ENDIF!] |
        [!IF "McuSIMClockConfig/McuERMClockGatingEnable"!]SIM_PLATGC_ERM_CLK_ENABLE_U32[!ELSE!]SIM_PLATGC_ERM_CLK_DISABLE_U32[!ENDIF!] |
        [!IF "McuSIMClockConfig/McuDMAClockGatingEnable"!]SIM_PLATGC_DMA_CLK_ENABLE_U32[!ELSE!]SIM_PLATGC_DMA_CLK_DISABLE_U32[!ENDIF!] |
        [!IF "McuSIMClockConfig/McuMPUClockGatingEnable"!]SIM_PLATGC_MPU_CLK_ENABLE_U32[!ELSE!]SIM_PLATGC_MPU_CLK_DISABLE_U32[!ENDIF!] |
        [!IF "McuSIMClockConfig/McuMSCMClockGatingEnable"!]SIM_PLATGC_MSCM_CLK_ENABLE_U32[!ELSE!]SIM_PLATGC_MSCM_CLK_DISABLE_U32[!ENDIF!] |
        [!IF "McuSIMClockConfig/McuGPIOClockGatingEnable"!]SIM_PLATGC_GPIO_CLK_ENABLE_U32[!ELSE!]SIM_PLATGC_GPIO_CLK_DISABLE_U32[!ENDIF!]
    )
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "SOSC_Clock_Config", "Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuSystemOSCClockConfig/McuSOSCUnderMcuControl='true'"!][!//
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SOSC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_NUMBER_OF_SOSC_REGISTERS_U32] =
{
    /* SCG_SOSCCFG settings. */
    {
        SCG_SOSCCFG_ADDR32,
        (
            SCG_SOSCCFG_[!"McuSystemOSCClockConfig/McuSOSCRangeSelect"!]_U32 |
            [!IF "McuSystemOSCClockConfig/McuSOSCExternalReferenceSelect"!]SCG_SOSCCFG_EXTERNAL_REFERENCE_U32[!ELSE!]SCG_SOSCCFG_INTERNAL_OSCILLATOR_U32[!ENDIF!] |
            [!IF "McuSystemOSCClockConfig/McuSOSCHighGainOscillatorSelect"!]SCG_SOSCCFG_HIGH_GAIN_OPERATION_U32[!ELSE!]SCG_SOSCCFG_LOW_POWER_OPERATION_U32[!ENDIF!]
        )
    },
    /* SCG_SOSCDIV settings. */
    {
        SCG_SOSCDIV_ADDR32,
        (
            SCG_SOSCDIV_SOSCDIV2_U32((uint32)[!IF "McuSystemOSCClockConfig/McuSOSCDiv2=4"!]3U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv2=8"!]4U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv2=16"!]5U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv2=32"!]6U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv2=64"!]7U)[!ELSE!][!"num:i(McuSystemOSCClockConfig/McuSOSCDiv2)"!]U)[!ENDIF!] |
            SCG_SOSCDIV_SOSCDIV1_U32((uint32)[!IF "McuSystemOSCClockConfig/McuSOSCDiv1=4"!]3U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv1=8"!]4U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv1=16"!]5U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv1=32"!]6U)[!ELSEIF "McuSystemOSCClockConfig/McuSOSCDiv1=64"!]7U)[!ELSE!][!"num:i(McuSystemOSCClockConfig/McuSOSCDiv1)"!]U)[!ENDIF!]
        )
    },
    /* SCG_SOSCCSR settings. */
    {
        SCG_SOSCCSR_ADDR32,
        (
             [!IF "McuSystemOSCClockConfig/McuSOSCEnable"!]SCG_SOSCCSR_SOSC_ENABLE_U32[!ELSE!]SCG_SOSCCSR_SOSC_DISABLE_U32[!ENDIF!] |
             [!IF "McuSystemOSCClockConfig/McuSOSCClockMonitorResetEnable"!]SCG_SOSCCSR_SOSCCMRE_RESET_U32[!ELSE!]SCG_SOSCCSR_SOSCCMRE_ISR_U32[!ENDIF!] |
             [!IF "McuSystemOSCClockConfig/McuSOSCClockMonitorEnable"!]SCG_SOSCCSR_SOSCCM_ENA_U32[!ELSE!]SCG_SOSCCSR_SOSCCM_DIS_U32[!ENDIF!]
         )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDIF!]
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "SIRC_Clock_Config", "Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuSIRCClockConfig/McuSIRCUnderMcuControl='true'"!][!//
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_NUMBER_OF_SIRC_REGISTERS_U32] =
{
    /* SCG_SIRCCFG settings. */
    {
        SCG_SIRCCFG_ADDR32,
        (
            SCG_SIRCCFG_[!"McuSIRCClockConfig/McuSIRCRangeSelect"!]_U32
        )
    },
    /* SCG_SIRCDIV settings. */
    {
        SCG_SIRCDIV_ADDR32,
        (
            SCG_SIRCDIV_SIRCDIV2_U32((uint32)[!IF "McuSIRCClockConfig/McuSIRCDiv2=4"!]3U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv2=8"!]4U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv2=16"!]5U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv2=32"!]6U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv2=64"!]7U)[!ELSE!][!"num:i(McuSIRCClockConfig/McuSIRCDiv2)"!]U)[!ENDIF!] |
            SCG_SIRCDIV_SIRCDIV1_U32((uint32)[!IF "McuSIRCClockConfig/McuSIRCDiv1=4"!]3U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv1=8"!]4U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv1=16"!]5U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv1=32"!]6U)[!ELSEIF "McuSIRCClockConfig/McuSIRCDiv1=64"!]7U)[!ELSE!][!"num:i(McuSIRCClockConfig/McuSIRCDiv1)"!]U)[!ENDIF!]
        )
    },
    /* SCG_SIRCCSR settings. */
    {
        SCG_SIRCCSR_ADDR32,
        (
             [!IF "McuSIRCClockConfig/McuSIRCEnable"!]SCG_SIRCCSR_SIRC_ENABLE_U32[!ELSE!]SCG_SIRCCSR_SIRC_DISABLE_U32[!ENDIF!] |
             [!IF "McuSIRCClockConfig/McuSIRCLowPowerEnable"!]SCG_SIRCCSR_SIRCLPEN_VLP_ENA_U32[!ELSE!]SCG_SIRCCSR_SIRCLPEN_VLP_DIS_U32[!ENDIF!] |
             [!IF "McuSIRCClockConfig/McuSIRCStopEnable"!]SCG_SIRCCSR_SIRCSTEN_STOP_ENA_U32[!ELSE!]SCG_SIRCCSR_SIRCSTEN_STOP_DIS_U32[!ENDIF!]
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDIF!]
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "FIRC_Clock_Config", "Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuFIRCClockConfig/McuFIRCUnderMcuControl='true'"!][!//
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) FIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_NUMBER_OF_FIRC_REGISTERS_U32] =
{
    /* SCG_FIRCCFG settings. */
    {
        SCG_FIRCCFG_ADDR32,
        (
            SCG_FIRCCFG_[!"substring-after(McuFIRCClockConfig/McuFIRCRangeSelect,'TRIMMED_TO_')"!]_U32
        )
    },
    /* SCG_FIRCDIV settings. */
    {
        SCG_FIRCDIV_ADDR32,
        (
            SCG_FIRCDIV_FIRCDIV2_U32((uint32)[!IF "McuFIRCClockConfig/McuFIRCDiv2=4"!]3U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv2=8"!]4U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv2=16"!]5U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv2=32"!]6U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv2=64"!]7U)[!ELSE!][!"num:i(McuFIRCClockConfig/McuFIRCDiv2)"!]U)[!ENDIF!] |
            SCG_FIRCDIV_FIRCDIV1_U32((uint32)[!IF "McuFIRCClockConfig/McuFIRCDiv1=4"!]3U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv1=8"!]4U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv1=16"!]5U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv1=32"!]6U)[!ELSEIF "McuFIRCClockConfig/McuFIRCDiv1=64"!]7U)[!ELSE!][!"num:i(McuFIRCClockConfig/McuFIRCDiv1)"!]U)[!ENDIF!]
        )
    },
    /* SCG_FIRCCSR settings. */
    {
        SCG_FIRCCSR_ADDR32,
        (
             [!IF "McuFIRCClockConfig/McuFIRCEnable"!]SCG_FIRCCSR_FIRC_ENABLE_U32[!ELSE!]SCG_FIRCCSR_FIRC_DISABLE_U32[!ENDIF!] |
             [!IF "McuFIRCClockConfig/McuFIRCRegulatorEnable"!]SCG_FIRCCSR_REGULATOR_ENABLE_U32[!ELSE!]SCG_FIRCCSR_REGULATOR_DISABLE_U32[!ENDIF!]
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDIF!]
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "SPLL_Clock_Config", "Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuSystemPll/McuSystemPllUnderMcuControl"!]
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SPLL_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_NUMBER_OF_SPLL_REGISTERS_U32] =
{
    /* SCG_SPLLCFG settings. */
    {
        SCG_SPLLCFG_ADDR32,
        (
            SCG_SPLLCFG_PREDIV_U32((uint32)[!"num:i(num:i(McuSystemPll/McuSPLLInputClkPreDivider)-num:i(1))"!]U) |
            SCG_SPLLCFG_MULT_U32((uint32)[!"num:i(num:i(McuSystemPll/McuSPLLMultiplier)-num:i(16))"!]U)
        )
    },
    /* SCG_SPLLDIV settings. */
    {
        SCG_SPLLDIV_ADDR32,
        (
            SCG_SPLLDIV_SPLLDIV2_U32((uint32)[!IF "McuSystemPll/McuSPLLDiv2=4"!]3U)[!ELSEIF "McuSystemPll/McuSPLLDiv2=8"!]4U)[!ELSEIF "McuSystemPll/McuSPLLDiv2=16"!]5U)[!ELSEIF "McuSystemPll/McuSPLLDiv2=32"!]6U)[!ELSEIF "McuSystemPll/McuSPLLDiv2=64"!]7U)[!ELSE!][!"num:i(McuSystemPll/McuSPLLDiv2)"!]U)[!ENDIF!] |
            SCG_SPLLDIV_SPLLDIV1_U32((uint32)[!IF "McuSystemPll/McuSPLLDiv1=4"!]3U)[!ELSEIF "McuSystemPll/McuSPLLDiv1=8"!]4U)[!ELSEIF "McuSystemPll/McuSPLLDiv1=16"!]5U)[!ELSEIF "McuSystemPll/McuSPLLDiv1=32"!]6U)[!ELSEIF "McuSystemPll/McuSPLLDiv1=64"!]7U)[!ELSE!][!"num:i(McuSystemPll/McuSPLLDiv1)"!]U)[!ENDIF!]
        )
    },
    /* SCG_SPLLCSR settings. */
    {
        SCG_SPLLCSR_ADDR32,
        (
             [!IF "McuSystemPll/McuSPLLEnable"!]SCG_SPLLCSR_SPLL_ENABLE_U32[!ELSE!]SCG_SPLLCSR_SPLL_DISABLE_U32[!ENDIF!] |
             [!IF "McuSystemPll/McuSPLLClockMonitorResetEnable"!]SCG_SPLLCSR_SPLLCMRE_RESET_U32[!ELSE!]SCG_SPLLCSR_SPLLCMRE_ISR_U32[!ENDIF!] |
             [!IF "McuSystemPll/McuSPLLClockMonitorEnable"!]SCG_SPLLCSR_SPLLCM_ENA_U32[!ELSE!]SCG_SPLLCSR_SPLLCM_DIS_U32[!ENDIF!]
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDIF!]
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "MC_CMU_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            CMU configuration.
* @details          This structure contains information for CMU[n]. 
*                   The number of CMU's is defined in the resource files, 
*
*/
static CONST( Mcu_CMU_ConfigType, MCU_CONST) Mcu_CMU_Config[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "ierh" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuFrequencyHigherInterrupt')"!]
                [!VAR "ierl" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuFrequencyLowerInterrupt')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
[!CODE!]
        /* [!"$cmuTmp"!] interrupt */
        CMU_IER_VALUE_U32
        (
            [!IF "node:value($ierh)"!]CMU[!"num:i($cmuCfgIndex)"!]_IER_FHH_ENA_U32 |[!ELSE!]CMU[!"num:i($cmuCfgIndex)"!]_IER_FHH_DIS_U32 |[!ENDIF!]
            [!IF "node:value($ierl)"!]CMU[!"num:i($cmuCfgIndex)"!]_IER_FLL_ENA_U32[!ELSE!]CMU[!"num:i($cmuCfgIndex)"!]_IER_FLL_DIS_U32[!ENDIF!]
            
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    },
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "cnt" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuReferenceCountConfiguration')"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
[!CODE!]
        /* [!"$cmuTmp"!] count */
        CMU_RCCR_VALUE_U32
        (
            (uint32)[!IF "node:value($enable)"!][!"num:i(node:value($cnt))"!][!ELSE!]0[!ENDIF!]U
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    },
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "hf" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuHighFrequencyRef')"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
[!CODE!]
        /* [!"$cmuTmp"!] HTCR */
        CMU_HTCR_VALUE_U32
        (
            (uint32)[!IF "node:value($enable)"!][!"num:i(node:value($hf))"!][!ELSE!]0[!ENDIF!]U
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    },
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "lf" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuLowFrequencyRef')"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
[!CODE!]
        /* [!"$cmuTmp"!] LTCR */
        CMU_LTCR_VALUE_U32
        (
            (uint32)[!IF "node:value($enable)"!][!"num:i(node:value($lf))"!][!ELSE!]0[!ENDIF!]U
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    }
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
#endif
#endif
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 



[!MACRO "PCC_Registers_Config", "Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
            [!VAR "TheFirstPCC" = "1"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PCC_RegisterConfigType, MCU_CONST) PCC_aRegistersConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_NUMBER_OF_PCC_REGISTERS_U32] =
{
[!LOOP "McuPeripheralClockConfig/*"!]
    [!IF "num:i($TheFirstPCC)=0"!],[!ENDIF!][!VAR "TheFirstPCC"="0"!]
    {
        PCC_[!"McuPerName"!]_ADDR32,
        (
            [!IF "McuPeripheralClockEnable"!]PCC_CLOCK_ENABLED_U32[!ELSE!]PCC_CLOCK_DISABLED_U32[!ENDIF!]
            [!IF "contains(ecu:list('MCU.PerSourceWithPcsFromPlat.List'), McuPerName) or contains(ecu:list('MCU.PerSourceWithPcsFromSlow.List'),McuPerName)"!] | PCC_PCS_[!"McuPeripheralClockSelect"!]_U32[!ELSE!] | PCC_PCS_UNAVAILABLE_U32[!ENDIF!]
            [!IF "contains(ecu:list('MCU.PerSourceWithPcd.List'),McuPerName)"!] |
            [!IF "McuPeripheralFractionalDivider"!]PCC_FRAC_1_U32[!ELSE!]PCC_FRAC_0_U32[!ENDIF!] |
            PCC_PCD_U32((uint32)[!"num:i(num:i(McuPeripheralClockDivider)-num:i(1))"!])
            [!ENDIF!]
        )
    }
[!ENDLOOP!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "PCC_Clock_Config", "Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PCC_ConfigType, MCU_CONST) PCC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Number of PCC Registers */
    MCU_NUMBER_OF_PCC_REGISTERS_U32,
    /* Register Configuration */
    &PCC_aRegistersConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "SCG_Clock_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            SCG clock configuration.
* @details          This structure contains information for SOSC, SIRC, FIRC, SPLL, ClockOut and System Clock
*
*/
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_ClockConfigType, MCU_CONST) SCG_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
[!IF "McuSysClockUnderMcuControl"!]
    /* Run Clock Config(SCG_RCCR) */
    (
        SCG_SCS_[!"McuRunClockConfig/McuSystemClockSwitch"!]_U32 |
        SCG_DIVCORE_U32((uint32)[!"num:i(num:i(McuRunClockConfig/McuCoreClockDivider)-num:i(1))"!]U) |
        SCG_DIVBUS_U32((uint32)[!"num:i(num:i(McuRunClockConfig/McuBusClockDivider)-num:i(1))"!]U) |
        SCG_DIVSLOW_U32((uint32)[!"num:i(num:i(McuRunClockConfig/McuSlowClockDivider)-num:i(1))"!]U)
    ),
    /* VLPR Clock Config(SCG_VCCR) */
    (
        SCG_SCS_[!"McuVlprClockConfig/McuSystemClockSwitch"!]_U32 |
        SCG_DIVCORE_U32((uint32)[!"num:i(num:i(McuVlprClockConfig/McuCoreClockDivider)-num:i(1))"!]U) |
        SCG_DIVBUS_U32((uint32)[!"num:i(num:i(McuVlprClockConfig/McuBusClockDivider)-num:i(1))"!]U) |
        SCG_DIVSLOW_U32((uint32)[!"num:i(num:i(McuVlprClockConfig/McuSlowClockDivider)-num:i(1))"!]U)
    ),
    /* High Speed Run Clock Config(SCG_HCCR) */
    (
        SCG_SCS_[!"McuHsrunClockConfig/McuSystemClockSwitch"!]_U32 |
        SCG_DIVCORE_U32((uint32)[!"num:i(num:i(McuHsrunClockConfig/McuCoreClockDivider)-num:i(1))"!]U) |
        SCG_DIVBUS_U32((uint32)[!"num:i(num:i(McuHsrunClockConfig/McuBusClockDivider)-num:i(1))"!]U) |
        SCG_DIVSLOW_U32((uint32)[!"num:i(num:i(McuHsrunClockConfig/McuSlowClockDivider)-num:i(1))"!]U)
    ),
[!ELSE!]
    (SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL),
    (SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL),
    (SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL),
[!ENDIF!]

    /* SCG ClockOut Config */
    SCG_CLKOUTCNFG_CLKOUTSEL_[!"McuScgClkOutSelect"!]_U32,

    /* SOSC Config */
[!IF "McuSystemOSCClockConfig/McuSOSCUnderMcuControl"!]   &SOSC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!]
    (NULL_PTR),
[!ENDIF!]
    /* SIRC Config */
[!IF "McuSIRCClockConfig/McuSIRCUnderMcuControl"!]    &SIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!]
    (NULL_PTR),
[!ENDIF!]
    /* FIRC Config */
[!IF "McuFIRCClockConfig/McuFIRCUnderMcuControl"!]    &FIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!]
    (NULL_PTR),
[!ENDIF!]
    /* SPLL Config */
[!IF "McuSystemPll/McuSystemPllUnderMcuControl"!]    &SPLL_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ELSE!]
    (NULL_PTR)
[!ENDIF!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Mcu_Clock_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Initialization clock data.
* @details        Static configuration realized by calling Mcu_InitClock() API.
*
*/
static CONST( Mcu_ClockConfigType, MCU_CONST) Mcu_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]] =  
{
[!ENDCODE!]
    [!IF "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))>0"!]
        [!VAR "ClockConfigs"= "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))-1"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
    /* Start of Mcu_ClockConfig[[!"@index"!]]. */
    {
[!ENDCODE!]
            [!VAR "PCindex" = "@index"!]
[!CODE!]
        /* ID Clock Configuration. */
        (uint8)[!"num:i(McuClockSettingId)"!]U,

        /* SIM IP Clock settings. */
        &SIM_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

        /* SCG IP Clock settings. */
        &SCG_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        
        /* PCC IP Clock settings. */
        &PCC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
        /* CMU IP Clock settings. */
        &Mcu_CMU_Config[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#endif
#endif
        ([!IF "McuSystemOSCClockConfig/McuSOSCUnderMcuControl"!]MCU_IPW_SOSC_UNDER_MCU_CONTROL[!ELSE!]MCU_IPW_SOSC_NOT_UNDER_MCU_CONTROL[!ENDIF!] |
         [!IF "McuSIRCClockConfig/McuSIRCUnderMcuControl"!]MCU_IPW_SIRC_UNDER_MCU_CONTROL[!ELSE!]MCU_IPW_SIRC_NOT_UNDER_MCU_CONTROL[!ENDIF!] |
         [!IF "McuFIRCClockConfig/McuFIRCUnderMcuControl"!]MCU_IPW_FIRC_UNDER_MCU_CONTROL[!ELSE!]MCU_IPW_FIRC_NOT_UNDER_MCU_CONTROL[!ENDIF!] |
         [!IF "McuSystemPll/McuSystemPllUnderMcuControl"!]MCU_IPW_SPLL_UNDER_MCU_CONTROL[!ELSE!]MCU_IPW_SPLL_NOT_UNDER_MCU_CONTROL[!ENDIF!])

    }[!IF "$PCindex < $ClockConfigs"!],[!ENDIF!] /* end of Mcu_ClockConfig[[!"@index"!]] */
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!CODE!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
        [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "SIM_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST(Mcu_SIM_ConfigType, MCU_CONST) SIM_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* SIM ChipControlConfiguration */
    (
        [!IF "McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuEnableAdcSupplyMonitoring"!]SIM_CHIPCTL_ENABLE_ADC_SUPPLY_MON_U32[!ELSE!]SIM_CHIPCTL_DISABLE_ADC_SUPPLY_MON_U32[!ENDIF!] |
        SIM_CHIPCTL_ADC_SUPPLY_[!"McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuAdcSupply"!]_U32 |        
        [!IF "McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuPDBBackToBackSelect"!]SIM_CHIPCTL_PDB_BB_SEL_MASK32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuPTB14InterleaveChannelSelect"!]SIM_PTB14_TO_ADC1_SE9_AND_ADC0_SE9_U32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuPTB13InterleaveChannelSelect"!]SIM_PTB13_TO_ADC1_SE8_AND_ADC0_SE8_U32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuPTB1InterleaveChannelSelect"!]SIM_PTB1_TO_ADC0_SE4_AND_ADC1_SE15_U32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuChipControlConfiguration/McuPTB0InterleaveChannelSelect"!]SIM_PTB0_TO_ADC0_SE4_AND_ADC1_SE14_U32[!ELSE!]SIM_CHIPCTL_NO_INTERLEAVE_CHANNEL_U32[!ENDIF!]
    ),
    /* SIM LPOClocks config */
    (
        SIM_RTCCLKSEL_[!"McuModuleConfiguration/McuRtcClkSelect"!]_U32 |
        SIM_LPOCLKSEL_[!"McuModuleConfiguration/McuLPOClockSelect"!]_U32 |
        [!IF "McuModuleConfiguration/McuLPO32KClockEnable"!]SIM_ENABLE_32KHZ_LPO_CLK_U32[!ELSE!]SIM_DISABLE_32KHZ_LPO_CLK_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuLPO1KClockEnable"!]SIM_ENABLE_1KHZ_LPO_CLK_U32[!ELSE!]SIM_DISABLE_1KHZ_LPO_CLK_U32[!ENDIF!]
    ),
    /* SIM ADC Configuration */
    (        
        SIM_ADC1_[!"McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuADC1PreTrigeerSourceSelect"!]_U32 |
        SIM_ADC1_[!"McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuADC1SoftwarePreTrigeerSourceSelect"!]_U32 |
        SIM_ADC1_[!"McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuADC1TrigeerSourceSelect"!]_TRIGGER_SOURCE_U32 |
        SIM_ADC0_[!"McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuADC0PreTrigeerSourceSelect"!]_U32 |
        SIM_ADC0_[!"McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuADC0SoftwarePreTrigeerSourceSelect"!]_U32 |
        SIM_ADC0_[!"McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuADC0TrigeerSourceSelect"!]_TRIGGER_SOURCE_U32
    ),
    /* SIM FTMOPT0 Config */
    (
        SIM_FTM3CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3ExternalClockPinSelect"!]_U32 |
        SIM_FTM2CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2ExternalClockPinSelect"!]_U32 |
        SIM_FTM1CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1ExternalClockPinSelect"!]_U32 |
        SIM_FTM0CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0ExternalClockPinSelect"!]_U32 |[!IF "(ecu:get('MCU.FTMOPT0.FTM7CLKSEL.Exist') = 'true')"!][!//
        SIM_FTM7CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM7ExternalClockPinSelect"!]_U32 |[!ENDIF!][!IF "(ecu:get('MCU.FTMOPT0.FTM6CLKSEL.Exist') = 'true')"!][!//
        SIM_FTM6CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM6ExternalClockPinSelect"!]_U32 |[!ENDIF!][!IF "(ecu:get('MCU.FTMOPT0.FTM5CLKSEL.Exist') = 'true')"!][!//
        SIM_FTM5CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM5ExternalClockPinSelect"!]_U32 |[!ENDIF!][!IF "(ecu:get('MCU.FTMOPT0.FTM4CLKSEL.Exist') = 'true')"!][!//
        SIM_FTM4CLKSEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM4ExternalClockPinSelect"!]_U32 |[!ENDIF!][!//
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Fault0Select"!]_FLT0_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Fault1Select"!]_FLT1_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Fault2Select"!]_FLT2_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2Fault0Select"!]_FLT0_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2Fault1Select"!]_FLT1_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2Fault2Select"!]_FLT2_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1Fault0Select"!]_FLT0_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1Fault1Select"!]_FLT1_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1Fault2Select"!]_FLT2_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Fault0Select"!]_FLT0_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Fault1Select"!]_FLT1_U32 |
        SIM_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Fault2Select"!]_FLT2_U32
    ),
    /* SIM FTMOPT1 Config */
    (
        SIM_FTMOPT1_FTM3OUTSEL_U32
        (   (0x00U)
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch0ModulationSelect"!]| 0x01U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch1ModulationSelect"!]| 0x02U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch2ModulationSelect"!]| 0x04U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch3ModulationSelect"!]| 0x08U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch4ModulationSelect"!]| 0x10U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch5ModulationSelect"!]| 0x20U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch6ModulationSelect"!]| 0x40U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3Ch7ModulationSelect"!]| 0x80U[!ENDIF!]
        ) |
        SIM_FTMOPT1_FTM0OUTSEL_U32
        (   (0x00U)
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch0ModulationSelect"!]| 0x01U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch1ModulationSelect"!]| 0x02U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch2ModulationSelect"!]| 0x04U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch3ModulationSelect"!]| 0x08U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch4ModulationSelect"!]| 0x10U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch5ModulationSelect"!]| 0x20U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch6ModulationSelect"!]| 0x40U[!ENDIF!]
            [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0Ch7ModulationSelect"!]| 0x80U[!ENDIF!]
        ) |
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTMGlobalLoadEnable"!]SIM_FTM_GLOBAL_LOAD_ENABLED_U32[!ELSE!]SIM_FTM_GLOBAL_LOAD_DISABLED_U32[!ENDIF!] |[!IF "(ecu:get('MCU.FTMOPT1.FTM7SYNCBIT.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM7SyncBit"!]SIM_FTMOPT1_FTM7SYNCBIT_MASK32 |[!ENDIF!][!ENDIF!][!IF "(ecu:get('MCU.FTMOPT1.FTM6SYNCBIT.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM6SyncBit"!]SIM_FTMOPT1_FTM6SYNCBIT_MASK32 |[!ENDIF!][!ENDIF!][!IF "(ecu:get('MCU.FTMOPT1.FTM5SYNCBIT.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM5SyncBit"!]SIM_FTMOPT1_FTM5SYNCBIT_MASK32 |[!ENDIF!][!ENDIF!][!IF "(ecu:get('MCU.FTMOPT1.FTM4SYNCBIT.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM4SyncBit"!]SIM_FTMOPT1_FTM4SYNCBIT_MASK32 |[!ENDIF!][!ENDIF!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3SyncBit"!]SIM_FTMOPT1_FTM3SYNCBIT_MASK32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2SyncBit"!]SIM_FTMOPT1_FTM2SYNCBIT_MASK32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1SyncBit"!]SIM_FTMOPT1_FTM1SYNCBIT_MASK32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0SyncBit"!]SIM_FTMOPT1_FTM0SYNCBIT_MASK32 |[!ENDIF!]
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2Ch1InputSelect = 'FTM2_CHI1_INPUT'"!]SIM_FTM2CH1SEL_FTM2_CH1_U32[!ELSE!]SIM_FTM2CH1SEL_XOR_U32[!ENDIF!] |
        SIM_FTM2CH0SEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2Ch0InputSelect"!]_U32 |
        SIM_FTM1CH0SEL_[!"McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1Ch0InputSelect"!]_U32
    ),
    /* SIM Miscellaneous Control configuration 0 */
    (
        [!IF "(ecu:get('MCU.MISCTRL0.QSPI_CLK_SEL.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuQspiClkSelect"!]SIM_QSPI_CLK_REFERENCE_EN_U32[!ELSE!]SIM_QSPI_CLK_REFERENCE_DIS_U32[!ENDIF!] |[!ENDIF!][!IF "(ecu:get('MCU.MISCTRL0.RMII_CLK_SEL.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuRMII_ClkSelect"!]SIM_RMII_CLK_SEL_SOSCDIV1_EN_U32[!ELSE!]SIM_RMII_CLK_SEL_SOSCDIV1_DIS_U32[!ENDIF!] |[!ENDIF!][!IF "(ecu:get('MCU.MISCTRL0.RMII_CLK_OBE.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuRMII_Clk_OBE"!]SIM_RMII_CLK_OBE_EN_U32[!ELSE!]SIM_RMII_CLK_OBE_DIS_U32[!ENDIF!] |[!ENDIF!][!IF "(ecu:get('MCU.MISCTRL0.FTM7_OBE_CTRL.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM7OBEControl"!]SIM_FTM7_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM7_OUTPUT_SAFE_STATE_U32[!ENDIF!] |[!ENDIF!][!IF "(ecu:get('MCU.MISCTRL0.FTM6_OBE_CTRL.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM6OBEControl"!]SIM_FTM6_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM6_OUTPUT_SAFE_STATE_U32[!ENDIF!] |[!ENDIF!][!IF "(ecu:get('MCU.MISCTRL0.FTM5_OBE_CTRL.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM5OBEControl"!]SIM_FTM5_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM5_OUTPUT_SAFE_STATE_U32[!ENDIF!] |[!ENDIF!][!IF "(ecu:get('MCU.MISCTRL0.FTM4_OBE_CTRL.Exist') = 'true')"!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM4OBEControl"!]SIM_FTM4_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM4_OUTPUT_SAFE_STATE_U32[!ENDIF!] |[!ENDIF!][!//
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM3OBEControl"!]SIM_FTM3_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM3_OUTPUT_SAFE_STATE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM2OBEControl"!]SIM_FTM2_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM2_OUTPUT_SAFE_STATE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM1OBEControl"!]SIM_FTM1_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM1_OUTPUT_SAFE_STATE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM0OBEControl"!]SIM_FTM0_OUTPUT_TRISTATE_U32[!ELSE!]SIM_FTM0_OUTPUT_SAFE_STATE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuSIMConfig/McuFlexTimerConfiguration/McuFTM_GTBControl"!]SIM_FTM_GTB_SPLIT_EN_U32[!ELSE!]SIM_FTM_GTB_SPLIT_DIS_U32[!ENDIF!]
    ),
    /* SIM Miscellaneous Control configuration 1 */
    (
        [!IF "McuModuleConfiguration/McuSIMConfig/McuAdcOptionsConfiguration/McuSoftwareTriggerToTRGMUX"!]SIM_MISCTRL1_SW_TRG_MASK32[!ELSE!](0x0U)[!ENDIF!]
    )
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "Reset_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST(Mcu_RCM_ConfigType, MCU_CONST) RCM_ResetConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Reset Pin Control register (RCM_RPC) */
    (
        RCM_RPC_STOP_[!"McuModuleConfiguration/McuResetConfig/McuResetPinFilterInStopMode"!]_U32 |
        RCM_RPC_NORMAL_[!"McuModuleConfiguration/McuResetConfig/McuResetPinFilterInRunAndWait"!]_U32 |
        RCM_RPC_RSTFLTSEL_U32((uint32)([!"num:i(McuModuleConfiguration/McuResetConfig/McuResetPinFilterBusClockSelect)"!]U))
    ),
    /* System Reset Interrupt Enable Register (RCM_SRIE) */
    (
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuStopAcknowledgeErrorInterrupt"!]RCM_SRIE_SACKERR_INT_EN_U32[!ELSE!]RCM_SRIE_SACKERR_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuMDMAPSystemResetInterrupt"!]RCM_SRIE_MDM_AP_INT_EN_U32[!ELSE!]RCM_SRIE_MDM_AP_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuSoftwareInterrupt"!]RCM_SRIE_SSW_INT_EN_U32[!ELSE!]RCM_SRIE_SSW_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuCoreLockupInterrupt"!]RCM_SRIE_LOCKUP_INT_EN_U32[!ELSE!]RCM_SRIE_LOCKUP_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuJTAGResetInterrupt"!]RCM_SRIE_JTAG_INT_EN_U32[!ELSE!]RCM_SRIE_JTAG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuGlobalInterrupt"!]RCM_SRIE_GIE_INT_EN_U32[!ELSE!]RCM_SRIE_GIE_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuExternalResetPinInterrupt"!]RCM_SRIE_PIN_INT_EN_U32[!ELSE!]RCM_SRIE_PIN_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuWatchdogInterrupt"!]RCM_SRIE_WDOG_INT_EN_U32[!ELSE!]RCM_SRIE_WDOG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuCMULossOfClockResetInterrupt"!]RCM_SRIE_CMU_INT_EN_U32[!ELSE!]RCM_SRIE_CMU_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuLossOfLockInterrupt"!]RCM_SRIE_LOL_INT_EN_U32[!ELSE!]RCM_SRIE_LOL_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuLossOfClockInterrupt"!]RCM_SRIE_LOC_INT_EN_U32[!ELSE!]RCM_SRIE_LOC_INT_DIS_U32[!ENDIF!] |
        RCM_SRIE_[!"McuModuleConfiguration/McuResetConfig/McuSystemInterruptEnable/McuResetDelayTime"!]_U32
    )
    
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "PMC_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_PMC_ConfigType, MCU_CONST) PMC_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Low Voltage Detect Status and Control 1 Register (PMC_LVDSC1) */
    (
        [!IF "McuModuleConfiguration/McuPowerControl/McuLowVoltageDetectInterruptEnable='true'"!]PMC_LVDSC1_LVD_ENABLE_U8[!ELSE!]PMC_LVDSC1_LVD_DISABLE_U8[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuLowVoltageDetectResetEnable='true'"!]PMC_LVDSC1_LVDRE_ENABLE_U8[!ELSE!]PMC_LVDSC1_LVDRE_DISABLE_U8[!ENDIF!]
    ),
    /* Low Voltage Detect Status and Control 2 Register (PMC_LVDSC2) */
    (
        [!IF "McuModuleConfiguration/McuPowerControl/McuLowVoltageWarningInterruptEnable = 'true'"!]PMC_LVDSC2_LVW_ENABLE_U8[!ELSE!]PMC_LVDSC2_LVW_DISABLE_U8[!ENDIF!]
    ),
    /* Regulator Status and Control Register (PMC_REGSC) */
    (
        [!IF "McuModuleConfiguration/McuPowerControl/McuLPODisable = 'true'"!]PMC_REGSC_LPO_DISABLE_U8[!ELSE!]PMC_REGSC_LPO_ENABLE_U8[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuClockBiasDisable = 'true'"!]PMC_REGSC_CLKBIAS_DISABLE_U8[!ELSE!]PMC_REGSC_CLKBIAS_ENABLE_U8[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuLowPowerBiasEnable = 'true'"!]PMC_REGSC_BIAS_ENABLE_U8[!ELSE!]PMC_REGSC_BIAS_DISABLE_U8[!ENDIF!]
    ),
    /* Regulator Status and Control Register (PMC_LPOTRIM) */
    (
        PMC_LPOTRIM_LPOTRIM_U8((uint8)[!"num:i(McuModuleConfiguration/McuPowerControl/McuLpoTrimming)"!]U)
    )
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "SMC_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for SMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_SMC_ConfigType, MCU_CONST) SMC_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Allowed modes */
    (
        [!IF "McuModuleConfiguration/McuAllowedModes/McuAllowHighSpeedRunMode = 'true'"!]SMC_PMPROT_HSRUN_ALLOWED_U32[!ELSE!]SMC_PMPROT_HSRUN_NOT_ALLOWED_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuAllowedModes/McuAllowVeryLowPowerModes = 'true'"!]SMC_PMPROT_VLP_ALLOWED_U32[!ELSE!]SMC_PMPROT_VLP_NOT_ALLOWED_U32[!ENDIF!]
    ),
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Mcu_HwIPs_Config","Type"!][!//
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_HwIPsConfigType, MCU_CONST) Mcu_HwIPsConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Configuration for RCM Reset. */
    &RCM_ResetConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for PMC (Power Management Control) hardware IP. */
    &PMC_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for SIM hardware IP. */
    &SIM_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    
    /* Configuration for SIM hardware IP. */
    &SMC_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Mcu_Config","Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for configuration.
*
*/
/** @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!IF "$Type = 'PC'"!]_Cfg[!ELSE!]_PBcfg[!ENDIF!][!ENDIF!]_c_REF_7 MISRA 2004 Required Rule 8.10, external linkage ... */
CONST(Mcu_ConfigType, MCU_CONST) [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]Mcu_PBCfgVariantPredefined[!ELSE!][!"as:name(McuModuleConfiguration)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &Mcu_Dem_Config,
#endif

    /* Number of RAM Sections configurations. */
    (Mcu_RamSectionType)[!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]U,

    /* Number of Power Modes configurations. */
    (Mcu_ModeType)[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]U,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Number of Clock Setting configurations. */
    (Mcu_ClockType)[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]U,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
    /* Pointer to RAM Section configurations. */
    [!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0"!]&Mcu_Ram_Config[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]
#endif

    /* Pointer to Power Mode configurations. */
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]&Mcu_Mode_Config[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]

#if (MCU_INIT_CLOCK == STD_ON)
    /* Pointer to Clock configurations. */
    [!IF "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))>0"!]&Mcu_ClockConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    /* Pointer to Low Level Mcu driver configuration. */
    &Mcu_HwIPsConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!//
[!ENDNOCODE!]
