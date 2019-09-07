/**
*   @file    Lin_PBcfg.c
*   @implements Lin_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
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
* @section Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
* Structure shall be public as it is used by Reg_eSys_DSPI.h which may be sed outside DSPI module.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Lin_Cfg.h"

#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*/
#define LIN_VENDOR_ID_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C                      43
/*
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C       4
/*
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C       2
/*
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C    2
#define LIN_SW_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               1
#define LIN_SW_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               0
#define LIN_SW_PATCH_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Lin_VersionCheck_Src_PB.m"!][!//
[!ENDNOCODE!][!//
/* Check if current file and LIN header file are of the same vendor */
#if (LIN_VENDOR_ID_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != LIN_VENDOR_ID_CFG)
    #error "Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lin_Cfg.h have different vendor ids"
#endif
/* Check if current file and LIN header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C    != LIN_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C    != LIN_AR_RELEASE_MINOR_VERSION_CFG) || \
     (LIN_AR_RELEASE_REVISION_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != LIN_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lin_Cfg.h are different"
#endif
/* Check if current file and LIN header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != LIN_SW_MAJOR_VERSION_CFG) || \
     (LIN_SW_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != LIN_SW_MINOR_VERSION_CFG) || \
     (LIN_SW_PATCH_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != LIN_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Lin_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != STD_AR_RELEASE_MAJOR_VERSION) || \
        (LIN_AR_RELEASE_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Std_Types.h are different"
    #endif

    #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if ((LIN_AR_RELEASE_MAJOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_AR_RELEASE_MINOR_VERSION_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dem.h are different"
        #endif
    #endif /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
#endif

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
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
*/
#include "Lin_MemMap.h"

[!NOCODE!][!//
[!VAR "LFDIV"="0"!][!//
[!VAR "temp1" = "0"!][!//
[!VAR "temp2" = "0"!][!//
[!VAR "LINIBRR" = "0"!][!//
[!VAR "LINFBRR" = "0"!][!//
[!VAR "LINIBRR_LINFBRR" = "0"!][!//
[!VAR "DualClockEnabled"= "'false'"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
[!IF "(node:exists(LinClockRef_Alternate))"!][!//
[!VAR "DualClockEnabled"= "'true'"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

[!VAR "nodeName" = "as:name(./LinGlobalConfig)"!][!//
[!VAR "shortNodeName" = "concat('_C', substring-after($nodeName, '_'))"!]
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
/**
* @brief          Configuration for Lin Channel [!"LinChannelId"!] - Configuration:
*                 [!"$nodeName"!].
*
* @api
*/
/*
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_4 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
CONST(Lin_ChannelConfigType,LIN_CONST) Lin_[!"node:name(.)"!][!"$shortNodeName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    &Lin_[!"node:name(.)"!]_PC,
    [!"LinChannelBaudRate"!]U,      /* LIN Baudrate value */
[!NOCODE!][!//
    [!VAR "linBaudrate" = "LinChannelBaudRate"!]
    [!SELECT "node:ref(LinClockRef)"!]
        [!INCLUDE "Lin_BaudRate_Comp.m"!][!//
    [!ENDSELECT!]
[!ENDNOCODE!][!//
    [!"$CTRL_SBR"!]U,       /* Baudrate [!"LinChannelBaudRate"!] */
[!CODE!]
#if (LIN_DUAL_CLOCK_MODE == STD_ON)
[!ENDCODE!]
[!NOCODE!][!//
    [!IF "$DualClockEnabled = 'true'"!]
        [!IF "node:exists(LinClockRef_Alternate)"!]
            [!VAR "linBaudrate" = "LinChannelBaudRate"!]
            [!SELECT "node:ref(LinClockRef_Alternate)"!]
            [!INCLUDE "Lin_BaudRate_Comp.m"!][!//
            [!ENDSELECT!][!//
            [!CODE!]
            [!"$CTRL_SBR"!]U,    /* Alternate Baudrate [!"LinChannelBaudRate"!] */
            [!ENDCODE!]
        [!ELSE!]
            [!CODE!]
            [!"$CTRL_SBR"!]U,    /* This channel is not enable Alternate Mode, Set Alternate Baudrate is the same configuration as Normal Mode */
            [!ENDCODE!]
        [!ENDIF!][!//
    [!ENDIF!]
[!CODE!]
#endif
[!ENDCODE!]
    [!VAR "IntegerBrkLength" = "substring-after(BreakLength,'_')"!]
[!ENDNOCODE!][!//
    [!"num:inttohex($IntegerBrkLength,2)"!]U                /* BreakLength = [!"BreakLength"!] bits */
};
[!ENDLOOP!][!//

[!NOCODE!][!//
[!VAR "nodeName" = "as:name(./LinGlobalConfig)"!][!//
[!VAR "shortNodeName" = "concat('_C', substring-after($nodeName, '_'))"!]
[!CODE!]
/**
* @brief          Lin Configuration data for [!"$nodeName"!].
*
* @api
*/
/*
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_4 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]
CONST(Lin_ConfigType,LIN_CONST) Lin_PBCfgVariantPredefined =
[!ELSE!]
CONST(Lin_ConfigType,LIN_CONST) [!"$nodeName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ENDIF!]
{
    {
[!ENDCODE!]
[!VAR "count"="0"!]
[!VAR "MaxChannelNr" = "num:i(count(LinGlobalConfig/LinChannel/*))"!]
[!FOR "count" = "0" TO "$MaxChannelNr - 1"!]
        [!LOOP "LinGlobalConfig/LinChannel/*"!]
            [!IF "$count = num:i(LinChannelId)"!]
                [!CODE!]
        /**
        * @brief   Configuration for Lin Channel [!"LinChannelId"!].
        */
                [!ENDCODE!]
                [!IF "$count > $MaxChannelNr - 2"!]
                    [!CODE!]
        &Lin_[!"node:name(.)"!][!"$shortNodeName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
                    [!ENDCODE!]
                [!ELSE!]
                    [!CODE!]
        &Lin_[!"node:name(.)"!][!"$shortNodeName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
                    [!ENDCODE!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
[!ENDFOR!]
[!CODE!]
    }
};
[!ENDCODE!]
[!ENDNOCODE!]

#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "Lin_MemMap.h"

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
