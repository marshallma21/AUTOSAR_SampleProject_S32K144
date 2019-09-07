[!AUTOSPACING!]
[!CODE!][!//
/**
*   @file Icu_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - contains the configuration data of the ICU driver
*   @details Contains the configuration data of the ICU driver
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FTM PORT_CI LPIT LPTMR
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

#ifndef ICU_CFG_H
#define ICU_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
* @section [global]
*          Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects
*          and functions shall not be reused. The driver needs to use defines starting with letter E
* @section Icu_Cfg_h_REF_2
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct.
*          This is used to abstract the export of configuration sets
* @section Icu_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
* @section Icu_Cfg_h_REF_4
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
*          are only accessed from within a single function.
*          These objects are used in various parts of the code
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Icu_VersionCheck_Inc.m"!][!//
[!ENDNOCODE!][!//
/*
* @violates @ref Icu_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Icu_EnvCfg.h"
[!NOCODE!]
[!SELECT "IcuConfigSet"!][!//
    [!LOOP "IcuHwInterruptConfigList/*"!]
        [!IF "node:value(IcuIsrEnable)"!]
            [!IF "contains(IcuIsrHwId,'FTM')"!]
                [!CODE!]
#include "Reg_eSys_Ftm.h"
                [!ENDCODE!]
                [!BREAK!]
            [!ENDIF!]

        [!ENDIF!]

    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]

[!INCLUDE "Icu_PluginMacros.m"!][!//

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_CFG                       43

#define ICU_AR_RELEASE_MAJOR_VERSION_CFG        4
#define ICU_AR_RELEASE_MINOR_VERSION_CFG        2
#define ICU_AR_RELEASE_REVISION_VERSION_CFG     2

#define ICU_SW_MAJOR_VERSION_CFG                1
#define ICU_SW_MINOR_VERSION_CFG                0
#define ICU_SW_PATCH_VERSION_CFG                1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Icu_EnvCfg header file are of the same vendor */
#if (ICU_VENDOR_ID_CFG != ICU_ENVCFG_VENDOR_ID)
    #error "Icu_Cfg.h and Icu_EnvCfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same AutoSar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_CFG != ICU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_CFG != ICU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_CFG != ICU_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_EnvCfg.h are different"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_CFG != ICU_ENVCFG_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_CFG != ICU_ENVCFG_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_CFG != ICU_ENVCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Cfg.h and Icu_EnvCfg.h are different"
#endif

[!NOCODE!]
[!SELECT "IcuConfigSet"!][!//
    [!LOOP "IcuHwInterruptConfigList/*"!]
        [!IF "node:value(IcuIsrEnable)"!]
            [!IF "contains(IcuIsrHwId,'FTM')"!]
                [!CODE!]
/* Check if Icu_Cfg.h and Reg_eSys_Ftm.h file are of the same vendor */
#if (ICU_VENDOR_ID_CFG != REG_ESYS_FTM_VENDOR_ID)
#error "Icu_Cfg.h and Reg_eSys_Ftm.h have different vendor IDs"
#endif
    /* Check if Icu_Cfg.h and Reg_eSys_Ftm.h file are of the same Autosar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_CFG != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_CFG != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_CFG != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Reg_eSys_Ftm.h are different"
#endif
/* Check if Icu_Cfg.h and Reg_eSys_Ftm.h file are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_CFG != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_CFG != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_CFG != REG_ESYS_FTM_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Cfg.h and Reg_eSys_Ftm.h are different"
#endif
                [!ENDCODE!]
                [!BREAK!]
            [!ENDIF!]

        [!ENDIF!]

    [!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
*    @brief Implementation specific.
*     Each channel provides a DMA resolution of 16 bits.
*/
#define  ICU_DMA_SIZE           (DMA_SIZE_2BYTES)
/**
*    @brief Implementation specific.
*     DMA number of bytes transfer on a minor loop is 2 bytes - for 16 bits hw registers.
*/
#define  ICU_DMA_NUM_BYTES      (2U)
/**
*    @brief Implementation specific.
*     DMA offset is 16 bits hw registers.
*/
#define  ICU_DMA_OFFSET         (DMA_OFFSET_16_BITS)
/**
*   @brief   Get A number of Ftm hardware modules from resource file
*/
#define ICU_NUM_FTM_HW_MODULE_U8  ((uint8)[!"ecu:get('Icu.Num_Ftm_Hw_Modules')"!]U)
/**
*   @brief   Get A number of PORT_CI hardware modules from resource file
*/
#define ICU_NUM_PORT_CI_HW_MODULE_U8  ((uint8)[!"ecu:get('Icu.Num_Port_Hw_Modules')"!]U)

/**
@{
*   @brief Implementation specific.
*       Each channel provides a subset of the functionality available in the unified channel,
*      at a resolution of 16 bits.
*/
#define FTM_COUNTER_MASK          ((Icu_ValueType)0xFFFF)
/**@}*/

/**
 *   @brief Maximum number of ICU channels configured
 */
[!NOCODE!]
    [!VAR "MaxNoOfCh" = "0"!]
    [!SELECT "IcuConfigSet"!]
        [!IF "$MaxNoOfCh < IcuMaxChannel"!]
            [!VAR "MaxNoOfCh" = "IcuMaxChannel"!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDNOCODE!][!//
#define ICU_MAX_CHANNEL     ((Icu_ChannelType)[!"num:i($MaxNoOfCh)"!]U)

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime' "!]
  [!IF "variant:size()<=1"!]
/**
 *   @brief Pre-compile configuration constants
 */
#define ICU_PRECOMPILE_SUPPORT
[!ENDIF!]
[!ENDIF!]

/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled.
*        STD_OFF: Disabled.
*/
#define ICU_DEV_ERROR_DETECT            ([!IF "IcuGeneral/IcuDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Switch for enabling Wakeup source reporting.
*        STD_ON: Report Wakeup source.
*        STD_OFF: Do not report Wakeup source.
*
*/
#define ICU_REPORT_WAKEUP_SOURCE        ([!IF "IcuGeneral/IcuReportWakeupSource"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Icu_GetVersionInfo() from the code.
*        STD_ON: Icu_GetVersionInfo() can be used.
*        STD_OFF: Icu_GetVersionInfo() can not be used.
*
*/
#define ICU_GET_VERSION_INFO_API        ([!IF "IcuOptionalApis/IcuGetVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_DeInit() from the code.
*        STD_ON: Icu_DeInit() can be used. STD_OFF: Icu_DeInit() can not be used.
*   @implements ICU_DE_INIT_API_define
*/
#define ICU_DE_INIT_API                 ([!IF "IcuOptionalApis/IcuDeInitApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_SetMode() from the code.
*        STD_ON: Icu_SetMode() can be used.
*        STD_OFF: Icu_SetMode() can not be used.
*   @implements ICU_SET_MODE_API_define
*/
#define ICU_SET_MODE_API                ([!IF "IcuOptionalApis/IcuSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_DisableWakeup() from the code.
*        STD_ON: Icu_DisableWakeup() can be used.
*        STD_OFF: Icu_DisableWakeup() can not be used.
*   @implements ICU_DISABLE_WAKEUP_API_define
*/
#define ICU_DISABLE_WAKEUP_API          ([!IF "IcuOptionalApis/IcuDisableWakeupApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_EnableWakeup() from the code.
*        STD_ON: Icu_EnableWakeup() can be used.
*        STD_OFF: Icu_EnableWakeup() can not be used.
*   @implements ICU_ENABLE_WAKEUP_API_define
*/
#define ICU_ENABLE_WAKEUP_API           ([!IF "IcuOptionalApis/IcuEnableWakeupApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes all services related to the timestamping functionality as listed
*        below from the code: Icu_StartTimestamp(), Icu_StopTimestamp(), Icu_GetTimestampIndex().
*        STD_ON: The services listed above can be used.
*        STD_OFF: The services listed above can not be used.
*   @implements ICU_TIMESTAMP_API_define
*/
#define ICU_TIMESTAMP_API               ([!IF "IcuOptionalApis/IcuTimestampApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes all services related to the edge counting functionality as listed below,
*           from the code: Icu_ResetEdgeCount(), Icu_EnableEdgeCount(), Icu_DisableEdgeCount(),
*           Icu_GetEdgeNumbers().
*        STD_ON: The services listed above can be used.
*        STD_OFF: The services listed above can not be used.
*   @implementsICU_EDGE_COUNT_API_define
*/
#define ICU_EDGE_COUNT_API              ([!IF "IcuOptionalApis/IcuEdgeCountApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_GetTimeElapsed() from the code.
*        STD_ON: Icu_GetTimeElapsed() can be used.
*        STD_OFF: Icu_GetTimeElapsed() can not be used.
*   @implements ICU_GET_TIME_ELAPSED_API_define
*/
#define ICU_GET_TIME_ELAPSED_API        ([!IF "IcuOptionalApis/IcuGetTimeElapsedApi"!][!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!][!ERROR "If IcuSignalMeasurementApi == OFF this switch is shall also be set to OFF"!][!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_GetDutyCycleValues() from the code.
*        STD_ON: Icu_GetDutyCycleValues() can be used.
*        STD_OFF: Icu_GetDutyCycleValues() can not be used.
*   @implements ICU_GET_DUTY_CYCLE_VALUES_API_define
*/
#define ICU_GET_DUTY_CYCLE_VALUES_API   ([!IF "IcuOptionalApis/IcuGetDutyCycleValuesApi"!][!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!][!ERROR "If IcuSignalMeasurementApi == OFF this switch is shall also be set to OFF"!][!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_GetInputState() from the code.
*        STD_ON: Icu_GetInputState() can be used.
*        STD_OFF: Icu_GetInputState() can not be used.
*   @implements ICU_GET_INPUT_STATE_API_define
*/
#define ICU_GET_INPUT_STATE_API         ([!IF "IcuOptionalApis/IcuGetInputStateApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the services Icu_StartSignalMeasurement() and
*          Icu_StopSignalMeasurement() from the code.
*        STD_ON: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can be used.
*        STD_OFF: Icu_StartSignalMeasurement() and Icu_StopSignalMeasurement() can not be used.
*   @implements ICU_SIGNAL_MEASUREMENT_API_define
*/
#define ICU_SIGNAL_MEASUREMENT_API      ([!IF "IcuOptionalApis/IcuSignalMeasurementApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the service Icu_CheckWakeup() from the code.
*        STD_ON: Icu_CheckWakeup() can be used.
*        STD_OFF: Icu_CheckWakeup() can not be used.
*   @implements ICU_WAKEUP_FUNCTIONALITY_API_define
*/
#define ICU_WAKEUP_FUNCTIONALITY_API      ([!IF "IcuOptionalApis/IcuWakeupFunctionalityApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Adds or removes the services Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection()
*           from the code.
*        STD_ON: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can be used.
*        STD_OFF: Icu_EnableEdgeDetection() and Icu_DisableEdgeDetection() can not be used.
*
*   @implements  ICU_EDGE_DETECT_API_define
*/
#define ICU_EDGE_DETECT_API      ([!IF "IcuOptionalApis/IcuEdgeDetectApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief  Implementation specific parameter
*        Adds or Removes the code related to overflow notification
*        STD_ON: Overflow notification function will be called if overflow occurs
*        STD_OFF: Overflow notification function will not be called though overflow occurs
*
*/
#define ICU_OVERFLOW_NOTIFICATION_API      ([!IF "IcuNonAUTOSAR/IcuOverflowNotificationApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief   Adds or removes the service Icu_GetInputLevel() from the code.
*         STD_ON:  Icu_GetInputLevel() can be used.
*         STD_OFF: Icu_GetInputLevel() can not be used.
*
*
*/
#define ICU_GET_INPUT_LEVEL_API             ([!IF "node:exists(IcuNonAUTOSAR/IcuGetInputLevelApi)"!][!IF "IcuNonAUTOSAR/IcuGetInputLevelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])
/**@}*/

/**
*   @brief   Adds / removes the service Icu_GetPulseWidth() from the code.
*         STD_ON:  Icu_GetPulseWidth() can be used.
*         STD_OFF: Icu_GetPulseWidth() can not be used.
*/
#define ICU_GET_PULSE_WIDTH_API             (STD_OFF)

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*           USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT,
*                                          user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*
*/
#define ICU_USER_MODE_SOFT_LOCKING       ([!IF "IcuNonAUTOSAR/IcuRegisterLockingMode ='USER_MODE_SOFT_LOCKING'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/**@}*/

/**
*   @brief    Adds or removes the support  measurement with DMA
*         STD_ON:  DMA measurement can be used.
*         STD_OFF: DMA measurement can not be used.
*
*
*/
#define ICU_TIMESTAMP_USES_DMA           ([!IF "//IcuDMAChannelEnable='true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief    Adds or removes the for Signal Measurement with DMA
*         STD_ON:  DMA in SM measurement can be used.
*         STD_OFF: DMA in SM measurement can not be used.
*
*/
#define ICU_SIGNALMEASUREMENT_USES_DMA   (STD_OFF)

/**
*   @brief   Adds / removes the service Icu_SetClockMode() from the code
*         At this point, this is disabled
*         STD_ON:  Icu_SetClockMode() can be used.
*         STD_OFF: Icu_SetClockMode() can not be used.
*
*/
#define ICU_DUAL_CLOCK_MODE_API        ([!IF "IcuNonAUTOSAR/IcuEnableDualClockMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief   Adds / removes the service Icu_GetCaptureRegisterValue() from the code.
*         STD_ON:  Icu_GetCaptureRegisterValue() can be used.
*         STD_OFF: Icu_GetCaptureRegisterValue() can not be used.
*/
#define ICU_CAPTURERGISTER_API         ([!IF "node:exists(IcuNonAUTOSAR/IcuGetCaptureRegisterValueApi)"!][!IF "IcuNonAUTOSAR/IcuGetCaptureRegisterValueApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ELSE!]STD_OFF[!ENDIF!])

/**
*   @brief Selects or disables code in the HLD regarding setting channel level
*         prescalers
*         STD_ON:  There are channel prescalers on at least one IP
*         STD_OFF: There aren't channel prescalers on any IP
*
*/
#define ICU_USE_CHANNEL_PRESCALER    (STD_OFF)

/**
*   @brief No Mcl Dma Channel
*/
#define NoMclDmaChannel ((Mcl_ChannelType)0xFF)

 /**
*   @brief Icu Channel symbolic names
*   @details Get All Symbolic Names from configuration tool
*
*   @{
*/
#define NoIcuChannel  ((Icu_ChannelType)0xFF)

[!INDENT "0"!]
[!NOCODE!]
    [!VAR "OuterLoopCounter" = "0"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!LOOP "IcuConfigSet/IcuChannel/*"!]
        [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!VAR "Matchcounter" = "0"!]
        [!VAR "Name" = "node:name(.)"!]
        [!LOOP "../../IcuChannel/*"!]
            [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
            [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
            [!IF "($Name = node:name(.))"!]
                    [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$Matchcounter = 1"!]
                [!CODE!]
                 #define [!"node:name(.)"!]                     (IcuConf_IcuChannel_[!"node:name(.)"!])[!CR!]
                 /* @violates @ref Icu_Cfg_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
                 #define IcuConf_IcuChannel_[!"node:name(.)"!]  ((Icu_ChannelType)[!"IcuChannelId"!]U) [!CR!]
                [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDNOCODE!]

/**@}*/
/**
*   @brief ISR's configured for Icu channels
*   @details Macros for channels used in ISR
*   @{
*/

/**
* @brief   Single Interrupt.
*/
#define ICU_FTM_MODULE_SINGLE_INTERRUPT      ([!IF "ecu:get('Icu.IcuConfig.Icu_FTM_ModuleSingleInterrupt') = 'TRUE'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ICU_LPIT_MODULE_SINGLE_INTERRUPT     ([!IF "ecu:get('Icu.IcuConfig.Icu_LPIT_ModuleSingleInterrupt') = 'TRUE'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

#define ICU_IRQ_SINGLE_INTERRUPT     ([!IF "ecu:get('Icu.IcuConfig.Icu_PORT_ModuleSingleInterrupt') = 'TRUE'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!CALL "ICU_GENERATE_OVF_ISR_USED", "IPVType"="string('FTM')"!]

[!CALL "ICU_GENERATE_ISR_USED","IPVType"="string('FTM')"!]
[!CALL "ICU_GENERATE_ISR_USED","IPVType"="string('LPIT')"!]
[!CALL "ICU_GENERATE_ISR_USED","IPVType"="string('LPTMR')"!]

[!CALL "ICU_GENERATE_USED","IPVType"="string('FTM')"!]
[!CALL "ICU_GENERATE_USED","IPVType"="string('LPTMR')"!]


#if(ICU_IRQ_SINGLE_INTERRUPT == STD_OFF)
[!CALL "ICU_GENERATE_ISR_USED","IPVType"="string('PORT')"!]
#endif

[!CALL "CHECKFREEZE","ModuleType"="string('FTM_0')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_1')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_2')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_3')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_4')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_5')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_6')"!]
[!CALL "CHECKFREEZE","ModuleType"="string('FTM_7')"!]

/**
*   @brief export configuration icu driver
*/

[!MACRO "IcuExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(IcuConfigSet)"!][!//

[!CODE!][!//
/**
 * @violates @ref Icu_Cfg_h_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to a braced initialiser
 */
#define ICU_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Icu_ConfigType, ICU_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!] \[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Icu_ConfigType, ICU_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "IcuExportDriverConfiguration"!]
[!ENDIF!]

/**@}*/
[!ENDINDENT!]
/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Range: 0  to width of the timer register.
*       Description: Width of the buffer for timestamp ticks and measured elapsed timeticks
*/
typedef uint32 Icu_TimerRegisterWidthType;

/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Description: Type, to abstract the return value of the service Icu_GetTimestampIndex().
*/
typedef uint16 Icu_HwSpecificIndexType;

/**
*   @brief Implementation specific. This type shall be chosen in order to have the most efficient
*       implementation on a specific microcontroller platform.
*       Description: Type, to abstract the return value of the service Icu_GetEdgeNumbers().
*/
typedef uint16 Icu_HwSpecificEdgeNumberType;



/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /* ICU_CFG_H */
/**@}*/

[!ENDCODE!]