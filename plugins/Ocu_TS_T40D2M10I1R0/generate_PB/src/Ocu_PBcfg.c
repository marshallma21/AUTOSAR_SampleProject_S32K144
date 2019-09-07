[!AUTOSPACING!]
[!CODE!]
/**
*   @file       Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @implements Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR Ocu - Ocu post-build configuration file.
*   @details    Post-build configuration structure instances.
*
*   @addtogroup OCU_MODULE
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
[!NOCODE!]

/* Variable storing number of Emios Modules available on the current platform */
[!VAR "numFtmModules" = "num:i(ecu:get('Ocu.Num_Ftm_Hw_Modules'))"!]

/* Macro used to generate the correspondence (translation) table between all Ftm available 
channels and the indexes of channels in the array of Ocu channels configured to use Ftm */
/* Macro used to generate the correspondence (translation) table between all Ftm available 
channels and the indexes of channels in the array of Ocu channels configured to use Ftm */
[!MACRO "GenerateFtmHwToLogicMap", "paramFtmModule"!]
    [!NOCODE!]
    [!VAR "OutVarHwToLogicArray" = "''"!]
    [!VAR "OutVarHwToLogicComment" = "''"!]
   
    /* Loop through all channels of Ftm module received as parameter */
    [!FOR "MacCurModChannel" = "0" TO "7"!]
        /* Limit max number of configured channels to 255 */
        [!VAR "MacVarChTranslationIndex" = "255"!] 
        
        /* Loop through all Ocu channels configured to use Ftm IP */
        [!LOOP "OcuChannel/*"!]

            /* Build the comment for the current Module */
            [!VAR "OutVarHwToLogicComment" = "concat('/* Idx of channels 0 - ', num:i(7), ' of Ftm Module ', num:i($paramFtmModule), ' in the array of logic Ocu channels */')"!]
            [!VAR "MacOcuAssignedHardwareChannel" = "OcuAssignedHardwareChannel"!]
            [!VAR "MacOcuChannelId" = "OcuChannelId"!]
            
            [!VAR "MacFtmModule"     = "num:i(substring-before(substring-after(FtmHwChannel,'FTM_'),'_CH_'))"!]
            [!VAR "MacFtmChannel" = "num:i(substring-after(FtmHwChannel,'_CH_'))"!]    
            /* Check the match with the module received as parameter */
            [!IF "$MacFtmModule = $paramFtmModule"!]
                /* Check the match with the channel loop var */
                [!IF "num:i($MacFtmChannel) = $MacCurModChannel"!] 
                    /* Keep the index of the channel in the array of configured Ocu channels */
                    [!VAR "MacVarChTranslationIndex" = "$MacOcuChannelId"!]
                [!ENDIF!]
            [!ENDIF!]          
        [!ENDLOOP!]
        
        /* If no configured Ocu channel is using the current Ftm channel in Module  */
        [!IF "$MacVarChTranslationIndex = 255"!]
            [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Ocu_ChannelType)255')"!]
        [!ELSE!]
            [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Ocu_ChannelType)', $MacVarChTranslationIndex)"!]
        [!ENDIF!]
        
        [!IF "$MacCurModChannel < num:i(7)"!]
             [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, ', ')"!]
        [!ENDIF!]
    [!ENDFOR!]
    [!ENDNOCODE!]
[!ENDMACRO!]

[!ENDNOCODE!]

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
* 
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
* 
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
* character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly
*
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* preceing &, or with a paranhesised parameter list which may be empty.
*
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6
* Violates MISRA 2004 Required Rule 12.8, The right-hand operand of a shift operator shall lie 
* between zero and one less than the width in bits of the underlying type of the left-hand operand.
*
* @section Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one 
* and only one file.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocu.h"

#include "Reg_eSys_Ftm.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*/
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                      43
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID_C                      121
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C       2
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C    2

#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C               1
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C               0
#define OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C               1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != OCU_VENDOR_ID)
    #error "Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ocu.h have different vendor ids"
#endif

#if ((OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OCU_AR_RELEASE_MAJOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != OCU_AR_RELEASE_MINOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != OCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ocu.h are different"
#endif

#if ((OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != OCU_SW_MAJOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != OCU_SW_MINOR_VERSION)  || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != OCU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ocu.h are different"
#endif

#if (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_Ftm.h have different vendor ids"
#endif

#if ((OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION ))
    #error "AutoSar Version Numbers of Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif

#if ((OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (OCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Ocu_MemMap.h"
[!NOCODE!]

[!VAR "NumOcuChannels" = "num:i(count(OcuConfigSet/OcuChannel/*))"!]
[!VAR "NumOcuModules" = "num:i(count(OcuConfigSet/OcuHWSpecificSettings/*))"!]

[!SELECT "OcuConfigSet"!]

[!CODE!]

/** 
* @brief Number of configured Ocu channels 
*/
#define OCU_CONF_CHANNELS_PB           [!"num:i($NumOcuChannels)"!]

/** 
* @brief Number of configured FTM channels
*/
#define OCU_FTM_CONF_CHANNELS_PB     [!"num:i($NumOcuChannels)"!]
/** 
* @brief Number of configured FTM modules
*/
#define OCU_FTM_CONF_MODULES_PB     [!"num:i($NumOcuModules)"!]

/***************************** Configuration for Ftm ********************/

/* @brief Configurations for Ocu channels using FTM 
 * @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 external ... could be made static
 * @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 violates Misra 1.4 Identifier clash
 */
static CONST(Ocu_Ftm_ChannelConfigType, OCU_CONST) Ocu_Ftm_ChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][OCU_FTM_CONF_CHANNELS_PB] =
{
[!ENDCODE!]
    [!VAR "comma" = "1"!]
        
[!LOOP "OcuChannel/*"!]
    [!VAR "DefaultThreshold" = "num:i(OcuDefaultThreshold)"!]
    [!VAR "PinUsed" = "OcuOuptutPinUsed"!]
    [!VAR "PinState" = "'(OCU_FTM_OUTPUTDISABLED)'"!]
    [!VAR "PinAction" = "'(uint8)((uint32)(OCU_DISABLE) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
    [!IF "($PinUsed = 'true')"!]
        [!IF "(node:exists('OcuOutputPinDefaultState'))"!]
            [!IF "(OcuOutputPinDefaultState = 'OCU_HIGH')"!]
                [!VAR "PinState"= "'(uint8)((uint32)1U << OCU_FTM_OUTPIN_USED_SHIFT) | (uint8)((uint32)(OCU_HIGH) << OCU_FTM_PIN_STATE_SHIFT)'"!]
            [!ELSE!]
                [!VAR "PinState"= "'(uint8)((uint32)1U << OCU_FTM_OUTPIN_USED_SHIFT)'"!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "PinState"= "'(uint8)((uint32)1U << OCU_FTM_OUTPIN_USED_SHIFT)'"!]
        [!ENDIF!]
        [!IF "(node:exists('OcuOutputPinAction'))"!]       
            [!IF "(OcuOutputPinAction = 'OCU_SET_HIGH')"!] 
                [!VAR "PinAction"= "'(uint8)((uint32)(OCU_SET_HIGH) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
            [!ELSEIF "(OcuOutputPinAction = 'OCU_TOGGLE')"!]
                [!VAR "PinAction"= "'(uint8)((uint32)(OCU_TOGGLE) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
            [!ELSEIF "(OcuOutputPinAction = 'OCU_DISABLE')"!] 
                [!VAR "PinAction"= "'(uint8)((uint32)(OCU_DISABLE) << OCU_FTM_PIN_ACTION_SHIFT)'"!]
            [!ELSE!]
                 [!VAR "PinAction"= "'(uint8)((uint32)(OCU_SET_LOW) << OCU_FTM_PIN_ACTION_SHIFT)'"!] 
            [!ENDIF!]
        [!ENDIF!]
    [!ENDIF!]

    [!CODE!]       
    /* @brief [!"node:name(.)"!] -> [!"FtmHwChannel"!] */
    {
        /** @brief Ocu Hw Channel */
        (Ocu_Ftm_ChannelType)[!"FtmHwChannel"!],
        /** @brief Ocu Default treshold: [!"$DefaultThreshold"!] */
        (uint16)[!"num:inttohex($DefaultThreshold,4)"!]U,
        /** @brief Ftm Control Value */
        (Ocu_Ftm_ChannelControlType)
        (
        [!WS "12"!][!"$PinState"!] |  /*Output Pin Enable and default state */
        [!WS "12"!][!"$PinAction"!]  /*Output Pin default action*/  
        )
    }[!IF "(num:i($comma))<(num:i($NumOcuChannels))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!]
    [!ENDCODE!]
[!ENDLOOP!]

[!CODE!]
};


/* @brief Configurations for Ocu channels using FTM 
 * @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 external ... could be made static
 * @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 violates Misra 1.4 Identifier clash
 */
static CONST(Ocu_Ftm_ModuleConfigType, OCU_CONST) Ocu_Ftm_ModuleConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][OCU_FTM_CONF_MODULES_PB] =
{
[!ENDCODE!]
    [!VAR "comma" = "1"!]
        
[!LOOP "OcuHWSpecificSettings/*"!]
    /*get hw information: clock source*/
    [!IF "(node:exists('OcuClockSource'))"!]
        [!IF "node:value(OcuClockSource) = 'OCU_SYSTEM_CLOCK'"!]
            [!VAR "SourceClock" = "'(FTM_SC_CLKS_SYS_CLOCK_U32 >> FTM_SC_CLKS_SHIFT) '"!]
        [!ELSE!]
            [!VAR "SourceClock" = "'(FTM_SC_CLKS_EXTERNAL_CLOCK_U32 >> FTM_SC_CLKS_SHIFT)'"!]
        [!ENDIF!]
    [!ELSE!]
        [!VAR "SourceClock" = "'(FTM_SC_CLKS_SYS_CLOCK_U32 >> FTM_SC_CLKS_SHIFT)'"!]
    [!ENDIF!]
    /*get hw information: prescaler*/ 
    [!IF "(node:exists('OcuPrescale'))"!]   
        [!VAR "Prescaler" = "node:value(OcuPrescale)"!]  
    [!ELSE!]
        [!VAR "Prescaler" = "'DIV1'"!]
    [!ENDIF!]
    [!VAR "Prescaler" = "concat('FTM_SC_PS_', $Prescaler,'_U32')"!]  
    [!VAR "Prescaler" = "concat('(uint8)((uint32)(', $Prescaler, ') << OCU_FTM_CLOCK_DIV_SHIFT)')"!]  

     /*get hw information: alternate prescaler*/
    [!IF "(node:exists('OcuPrescale_Alternate'))"!]  
        [!VAR "AltPrescaler" = "OcuPrescale_Alternate"!]
    [!ELSE!]
        [!VAR "AltPrescaler" = "'DIV1'"!]
    [!ENDIF!]
    [!VAR "AltPrescaler" = "concat('(FTM_SC_PS_', $AltPrescaler,'_U32)')"!]
    
    /*get hw information: debug information*/
    
    [!IF "OcuDebugMode = 'CNT_STOPED_FLAG_SET'"!]     
         [!VAR "DebugCfg" = "'(uint8)((FTM_CONF_BDMMODE_ALLSTOP_U32 >> FTM_CONF_BDMMODE_SHIFT) << OCU_FTM_DBG_INFO_SHIFT)'"!]
     [!ELSEIF "OcuDebugMode = 'CNT_STOPED_OUTPUTS_SAFE'"!]     
         [!VAR "DebugCfg" = "'(uint8)((FTM_CONF_BDMMODE_OUTPUTSSAFE_U32 >> FTM_CONF_BDMMODE_SHIFT) << OCU_FTM_DBG_INFO_SHIFT)'"!]
     [!ELSEIF "OcuDebugMode = 'CNT_STOPED_OUTPUTS_FROZEN'"!]     
         [!VAR "DebugCfg" = "'(uint8)((FTM_CONF_BDMMODE_OUTPUTSRUN_U32 >>FTM_CONF_BDMMODE_SHIFT) << OCU_FTM_DBG_INFO_SHIFT)'"!]
     [!ELSE!]        
        [!VAR "DebugCfg" = "'(uint8)((FTM_CONF_BDMMODE_ALLRUN_U32 >>FTM_CONF_BDMMODE_SHIFT)  << OCU_FTM_DBG_INFO_SHIFT)'"!]
     [!ENDIF!]
    
    /* Process Max Couter Value*/
    [!VAR "FtmModId" = "OcuFtmModule"!]
    [!VAR "ModulleMaxCounterValue" = "num:i(0)"!]
    [!LOOP "../../OcuChannel/*"!]
        [!IF "substring-before(FtmHwChannel,'_CH') = $FtmModId"!]
            [!IF "$ModulleMaxCounterValue = 0"!]
                [!VAR "ModulleMaxCounterValue" = "OcuMaxCounterValue"!]
            [!ELSEIF "$ModulleMaxCounterValue != OcuMaxCounterValue"!]
                [!ERROR!] [!"@name"!] uses [!"substring-before(FtmHwChannel,'_CH')"!], has max counter value is [!"OcuMaxCounterValue"!] but other OcuChannel using also [!"substring-before(FtmHwChannel,'_CH')"!] has max counter value is [!"$ModulleMaxCounterValue"!]. They must have same max counter value since each FTM module has only one counter. [!ENDERROR!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!CODE!]
    /* @brief [!"node:name(.)"!] -> [!"OcuFtmModule"!] */
    {
        /** @brief Assigned Ftm module id*/
        (uint8)[!"text:split(OcuFtmModule,'_')[2]"!]U,
        /** @brief Ocu Max Counter Value */
        (uint16)[!"$ModulleMaxCounterValue"!]U,
        /** @brief Ftm Control Value */
        (Ocu_Ftm_ModuleControlType) 
        (
        [!WS "12"!][!"$SourceClock"!] |  /* Clock source */
        [!WS "12"!][!"$Prescaler"!]  | /*Timer clock prescaler configuration*/   
        [!WS "12"!][!"$DebugCfg"!] /*Timer debug config*/
        )
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
        ,
        /** @brief prescale alternate */
        (uint8)[!"$AltPrescaler"!]
#endif
    }[!IF "(num:i($comma))<(num:i($NumOcuModules))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!]
    [!ENDCODE!]
[!ENDLOOP!]

[!CODE!]
};
[!ENDCODE!]

[!CODE!]
/**
@brief FTM IP configuration
*/
static CONST(Ocu_Ftm_IpConfigType, OCU_CONST) Ocu_Ftm_IpConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!] =
{
    /** @brief Number of FTM channels in the Ocu configuration */
    (uint8)[!"num:i($NumOcuChannels)"!]U,
    /** @brief Number of FTM modules in the Ocu configuration */
    (uint8)[!"num:i($NumOcuModules)"!]U,
    /** @brief Pointer to the array of FTM channel enabled Ocu channel configurations */
    &Ocu_Ftm_ChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!CR!]
    /** @brief Pointer to the array of FTM module enabled Ocu channel configurations */
    &Ocu_Ftm_ModuleConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!]
};
[!ENDCODE!]

[!LOOP "OcuChannel/*"!]
[!IF "node:exists('OcuNotification')"!]
        [!IF "(OcuNotification = '') or (OcuNotification = 'NULL_PTR') or (OcuNotification = 'NULL')"!]
        [!ELSE!]
        [!CODE!]
/** 
 *  @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7 violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, OCU_CODE) [!"OcuNotification"!](void);
        [!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]

[!CODE!]

/* @brief Array of configured Ocu channels */
static CONST(Ocu_ChannelConfigType, OCU_CONST) Ocu_Channels_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!][OCU_CONF_CHANNELS_PB] =
{
[!ENDCODE!]
    [!VAR "comma" = "1"!]
    [!FOR "varCounter" = "0" TO "$NumOcuChannels"!]
        [!LOOP "OcuChannel/*"!]
            [!IF "OcuChannelId = $varCounter"!]
            [!CODE!]        
    /* @brief [!"@name"!] */
    {    
        /* @brief OcuOuptutPinUsed */
    [!IF "OcuOuptutPinUsed = 'true'"!]
        [!WS "8"!](boolean)TRUE,
    [!ELSE!]
        [!WS "8"!](boolean)FALSE,
    [!ENDIF!]
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
        /** @brief Ocu notification function */
        [!ENDCODE!]    
    [!IF "node:exists('OcuNotification')"!]
        [!IF "(OcuNotification = '') or (OcuNotification = 'NULL_PTR') or (OcuNotification = 'NULL')"!]
        [!CODE!][!WS "8"!]NULL_PTR [!ENDCODE!][!CR!]    
        [!ELSE!]
        [!CODE!]
        [!WS "8"!]/* @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5 Callback definition */
        [!WS "8"!]&[!"OcuNotification"!]
        [!ENDCODE!]    
        [!ENDIF!]
    [!ELSE!]
        [!CODE!][!WS "8"!]NULL_PTR[!ENDCODE!][!CR!]
    [!ENDIF!]
    [!CODE!]
#endif

    }[!IF "(num:i($comma))<(num:i($NumOcuChannels))"!],[!ENDIF!][!VAR "comma"="$comma + 1"!][!CR!]
            [!ENDCODE!]        
            [!ENDIF!]            
        [!ENDLOOP!]
    [!ENDFOR!]
[!CODE!]  
};
[!ENDCODE!]

[!CODE!]  
/**
@brief   Ocu channels IP related configuration array
*/
static CONST(Ocu_IpChannelConfigType, OCU_CONST) Ocu_IpChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!][OCU_CONF_CHANNELS_PB] =
{
[!NOCODE!]
   [!VAR "VarFtmChannelIndex" = "0"!]     
    [!FOR "OcuChIndex" = "0" TO "$NumOcuChannels - 1"!]    
        [!LOOP "OcuChannel/*"!]
            [!VAR "ChannelName" = "node:name(.)"!]
            [!IF "$OcuChIndex = OcuChannelId"!]
                [!VAR "VarFtmChannelIndex" = "@index"!]
               [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]
  [!CODE!]
    /** @brief [!"$ChannelName"!] */
        [!IF "$OcuChIndex < $NumOcuChannels - 1"!]
    {(uint8)[!"num:i($VarFtmChannelIndex)"!]U},    
        [!ELSE!]
    {(uint8)[!"num:i($VarFtmChannelIndex)"!]U}
        [!ENDIF!]
  [!ENDCODE!]
    [!ENDFOR!]
[!ENDNOCODE!]
};

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
static CONST(Ocu_ChannelType, OCU_CONST)  Ocu_InitHWMap_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][OCU_HW_CHANNELS_NO]=
    /** @brief Hw to logic channel map. Array containing a number of elements
    equal to total number of available channels on FTM IPV */
    {
[!FOR "idx" = "0" TO "$numFtmModules - 1"!]
        [!CALL "GenerateFtmHwToLogicMap", "paramFtmModule" = "$idx"!]
        [!"$OutVarHwToLogicComment"!]
        [!"$OutVarHwToLogicArray"!][!IF "$idx < num:i($numFtmModules) - 1"!],[!ENDIF!][!CR!]
[!ENDFOR!]
    };
#endif
[!ENDCODE!]

[!IF "../IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and  variant:size()<=1"!]
    [!CODE!]
/**
@brief   Ocu high level configuration structure for a single precompile variant
*/
/*
* @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 external ... could be made static
*/
CONST(Ocu_ConfigType, OCU_CONST) Ocu_PBCfgVariantPredefined =
    [!ENDCODE!]
[!ELSE!]
    [!CODE!]
/**
@brief   Ocu high level configuration structure
*/
/*
* @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 external ... could be made static
*/
CONST(Ocu_ConfigType, OCU_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    [!ENDCODE!]
[!ENDIF!]
[!CODE!]
{
    /** @brief Number of configured Ocu channels */
    (Ocu_ChannelType)OCU_CONF_CHANNELS_PB,
    /** @brief Pointer to array of Ocu channels */
    &Ocu_Channels_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!],
    /** @brief IP specific configuration */
    {
        /* @brief Pointer to the structure containing Ftm configuration */
        &Ocu_Ftm_IpConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!],
        /* @brief Pointer to Array containing channe IP related information */
        &Ocu_IpChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!]
    }
    /** @brief counter direction */
    [!IF "node:exists(OcuCountdirection)"!]
#if (OCU_DOWNCOUNTING_SUPPORED == STD_ON)
    ,
        [!IF "OcuCountdirection = 'OCU_DOWNCOUNTING'"!]
    (Ocu_CountDirectionType)OCU_DOWNCOUNTING
        [!ELSE!]
    (Ocu_CountDirectionType)OCU_UPCOUNTING
        [!ENDIF!]
#endif
    [!ENDIF!]
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    ,
    &Ocu_InitHWMap_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!CR!]
#endif /* (OCU_NOTIFICATION_SUPPORTED == STD_ON) */  
};
[!ENDCODE!]
[!ENDSELECT!]
[!ENDNOCODE!]
#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Ocu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Ocu_MemMap.h"


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!]
