/**
*   @file    Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @version 1.0.1
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file.
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Post-build configuration variant.
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


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include'. This is an Autosar requirement about
* the memory management.
*
* @section GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. This is an Autosar requirement
* about the memory management.
*
* @section GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_5
* Violates MISRA 2004 Required Rule 8.8, an external variable or function should only be declared
* in one file. The variable can not be included in only one file because of the arhitecture of the
* ASR 4.2 driver
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Cfg.h"
#include "Gpt.h"

[!NOCODE!][!//
[!INCLUDE "Gpt_VersionCheck_Src_PB.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                      43
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_VERSION_C    2
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C                       1
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C                       0
#define GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C                       1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != GPT_VENDOR_ID_CFG)
    #error "Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gpt_Cfg.h are different"
#endif

/* Check if Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c file and Gpt.h header file are of the same vendor */
#if (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gpt.h have different vendor ids"
#endif
/* Check if Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c file and Gpt.h header file are of the same Autosar version */
#if ((GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gpt.h are different"
#endif
/* Check if Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c file and Gpt.h header file are of the same Software version */
#if ((GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Gpt.h are different"
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"
/**
* @{
* @brief The callback functions defined by the user to be called as channel notifications
*/
[!VAR "AlreadyParsedNotification"!][!ENDVAR!][!//
[!LOOP "GptChannelConfigSet/*/*/GptNotification"!][!//
[!IF "(. != 'NULL_PTR') and (. != 'NULL')"!][!//
[!IF "contains($AlreadyParsedNotification, concat(.,'|')) = false()"!][!//
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_5 External variables and functions should only appear in one file*/
extern void [!"."!](void);
[!VAR "AlreadyParsedNotification"="concat($AlreadyParsedNotification,.,'|')"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
/** @} */
#define GPT_STOP_SEC_CODE
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"
[!INCLUDE "Gpt_PluginMacros.m"!]

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/* configuration predef timers here */
[!NOCODE!][!//
[!VAR "flag_1us_16bit" = "'false'"!][!//
[!VAR "flag_1us_16bit_24bit" = "'false'"!][!//
[!VAR "flag_1us_16bit_24bit_32bit" = "'false'"!][!//
[!VAR "flag_100us_32bit" = "'false'"!][!//
[!IF "GptConfigurationOfOptApiServices/GptPredefTimerFunctionalityApi"!][!//
[!SELECT "GptDriverConfiguration"!]
    [!IF "(GptPredefTimer1usEnablingGrade = 'GPT_PREDEF_TIMER_1US_16BIT_ENABLED')"!]
        [!VAR "flag_1us_16bit"="'true'"!]
    [!ENDIF!]
    [!IF "(GptPredefTimer1usEnablingGrade = 'GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED')"!]
        [!VAR "flag_1us_16bit_24bit"="'true'"!]
    [!ENDIF!]
    [!IF "(GptPredefTimer1usEnablingGrade = 'GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED')"!]
        [!VAR "flag_1us_16bit_24bit_32bit"="'true'"!]
    [!ENDIF!]
    [!IF "(GptPredefTimer100us32bitEnable = 'true')"!]
        [!VAR "flag_100us_32bit"="'true'"!]
    [!ENDIF!]
[!ENDSELECT!]
[!ENDIF!][!//
[!CODE!][!//
[!IF "($flag_1us_16bit = 'true') or ($flag_1us_16bit_24bit = 'true') or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONST(Gpt_HwPredefChannelConfigType, GPT_CONST) Gpt_pInitPredefTimer_1us_16bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
[!NOCODE!][!//
  [!CALL "BuildHwchannelPredefTimer","predefType"="string('PREDEF_TIMER_1US_16BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!//
[!IF "($flag_1us_16bit_24bit = 'true')or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONST(Gpt_HwPredefChannelConfigType, GPT_CONST) Gpt_pInitPredefTimer_1us_24bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
[!NOCODE!][!//
  [!CALL "BuildHwchannelPredefTimer","predefType"="string('PREDEF_TIMER_1US_24BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!//
[!IF "($flag_1us_16bit_24bit_32bit = 'true')"!][!//
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONST(Gpt_HwPredefChannelConfigType, GPT_CONST) Gpt_pInitPredefTimer_1us_32bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
[!NOCODE!][!//
  [!CALL "BuildHwchannelPredefTimer","predefType"="string('PREDEF_TIMER_1US_32BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!//
[!IF "$flag_100us_32bit = 'true'"!][!//
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONST(Gpt_HwPredefChannelConfigType, GPT_CONST) Gpt_pInitPredefTimer_100us_32bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
[!NOCODE!][!//
  [!CALL "BuildHwchannelPredefTimer","predefType"="string('PREDEF_TIMER_100US_32BIT')"!]
[!ENDNOCODE!][!//
};
[!ENDIF!][!//
[!ENDCODE!][!//
[!ENDNOCODE!][!//

/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_4 MISRA 2004 Required Rule 8.10, could be made static */
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
static CONSTP2CONST(Gpt_HwPredefChannelConfigType, GPT_CONST, GPT_APPL_CONST) Gpt_pInitPredefTimerChannelPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][GPT_HW_PREDEFTIMER_NUM]=
{
[!IF "($flag_1us_16bit = 'true') or ($flag_1us_16bit_24bit = 'true')or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_1us_16bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "($flag_1us_16bit_24bit = 'true')or ($flag_1us_16bit_24bit_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_1us_24bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "($flag_1us_16bit_24bit_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_1us_32bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!IF "($flag_100us_32bit = 'true')"!][!//
    &Gpt_pInitPredefTimer_100us_32bitPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ELSE!][!//
    NULL_PTR
[!ENDIF!][!//
};
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/

static CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_InitChannelPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!]] =
{
[!NOCODE!]
    [!CALL "BuildConfigSet"!]
[!ENDNOCODE!]
};

/*PostBuild configuration structure.*/
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static*/
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
[!CODE!][!//
CONST(Gpt_ConfigType, GPT_CONST)  [!"as:name(./GptChannelConfigSet)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ENDCODE!][!//
[!ELSE!]
[!CODE!][!//
CONST(Gpt_ConfigType, GPT_CONST) Gpt_PBCfgVariantPredefined =
[!ENDCODE!][!//
[!ENDIF!][!//
{
    (Gpt_ChannelType)[!"num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!]U,
    &Gpt_InitChannelPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_pInitPredefTimerChannelPB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#endif
    /*Hardware to logic channel mapping.*/
    {[!NOCODE!]
    [!CALL "BuildChannelMap","ModuleType"="string('FTM')","LastModule"="string('FALSE')"!]
    [!CALL "BuildChannelMap","ModuleType"="string('LPIT')","LastModule"="string('FALSE')"!]
    [!CALL "BuildChannelMap","ModuleType"="string('LPTMR')","LastModule"="string('FALSE')"!]
    [!CALL "BuildChannelMap","ModuleType"="string('SRTC')","LastModule"="string('TRUE')"!]
    [!ENDNOCODE!]
    }
};


#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
