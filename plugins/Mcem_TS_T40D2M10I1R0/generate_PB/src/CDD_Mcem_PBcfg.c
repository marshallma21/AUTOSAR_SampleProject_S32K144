[!CODE!][!//
/**
*   @file    CDD_Mcem_PBcfg.c
*   @implements     CDD_Mcem_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - contains the data exported by the Mcem module
*   @details Contains the information that will be exported by the module, as requested by Autosar.
*
*   @addtogroup MCEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Eim Erm
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

[!INCLUDE "CDD_Mcem_VersionCheck_Src_PB.m"!][!//

[!NOCODE!][!//
[!VAR "PostBuildFile"="0=0"!][!//

[!CODE!][!//
/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1
* Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
* compatibility
*
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* This violation is due to readability of static initializations.
*
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
* preprocessor directives or comments.
* Violated due to AUTOSAR requirement MEMMAP003.
*
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects 
* or functions at file scope shall have internal linkage unless external linkage is required.
* Possibly unused public configuration
* 
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer...
* Unvoidable when addressing memory mapped registers.
*
* @section CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
* Unvoidable when addressing memory mapped registers.
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
*==================================================================================================*/
#include "CDD_Mcem_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
*==================================================================================================*/
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                        43
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C         2
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C      2
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C                 1
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C                 0
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C                 1

/*==================================================================================================
*                                      FILE VERSION CHECKS
*==================================================================================================*/

/* Check Mcem_Cfg.c against CDD_Mcem_Cfg.h file versions */
#if (CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != CDD_MCEM_VENDOR_ID_CFG)
    #error "CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Mcem_Cfg.h have different vendor IDs"
#endif

#if ((CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Mcem_Cfg.h are different"
#endif

#if ((CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != CDD_MCEM_SW_MAJOR_VERSION_CFG) || \
     (CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != CDD_MCEM_SW_MINOR_VERSION_CFG) || \
     (CDD_MCEM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != CDD_MCEM_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Mcem_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
*==================================================================================================*/
/* Enable/Disable Configuration bit values */
#define MCEM_ENABLED               (1UL)
#define MCEM_DISABLED              (0UL)

/* Configuration Bit/Tuple manipulation macros */
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 Function-like macro defined */
#define MCEM_CONFIG_VAL_1BIT( shl, val )            (((uint32)((val)&1UL)) << ((shl)%32U))
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 Function-like macro defined */
#define MCEM_CONFIG_VAL_2BITS( shl, val )           (((uint32)((val)&3UL)) << ((2U*(shl))%32U))

/*==================================================================================================
*                                      LOCAL CONSTANTS
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
*==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
*==================================================================================================*/

[!ENDCODE!][!//


[!//
[!// Generate an initialization value for a bit register
[!//
[!MACRO "GenBitCfgRegister", "nameList"="''", "valList" = "''", "comment" = "''", "TrueVal"="'MCEM_ENABLED'", "FalseVal"="'MCEM_DISABLED'", "comma"="''"!][!//
[!CODE!]
    /* [!"$comment"!] */
[!ENDCODE!][!//            
    [!IF "$nameList=''"!][!//
[!CODE!][!//
    (uint32)0UL[!"$comma"!]                  /* [!"$comment"!] */
[!ENDCODE!][!//            
    [!ELSE!][!//
        [!VAR "idx"="0"!][!//
        [!VAR "RegVal"="0"!][!//
        [!VAR "Flg"="0"!][!//
        [!LOOP "text:split( $nameList, ',' )"!][!//
            [!VAR "Name"="."!][!//
            [!VAR "idx"="$idx + 1"!][!//
            [!VAR "BitCfg"="node:when( text:split( $valList, ',' )[ position()=$idx ]='true', 1, 0 )"!][!//
            [!VAR "RegVal"="bit:or( $RegVal, bit:shl( $BitCfg, -1+$idx ) )"!][!//
            [!VAR "Or"="node:when( $Flg, '         | ', '(uint32)(  ' )"!][!//
            [!VAR "Flg"="1"!][!//
[!CODE!][!//
    [!"$Or"!]MCEM_CONFIG_VAL_1BIT( [!"text:toupper( $Name )"!], [!"node:when( $BitCfg=1, 'MCEM_ENABLED', 'MCEM_DISABLED' )"!] )
[!ENDCODE!][!//
        [!ENDLOOP!][!//
[!CODE!][!//
             )[!"$comma"!]                   /* [!"$comment"!] = [!"num:inttohex( $RegVal, 8 )"!]UL */
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDMACRO!][!//



[!//
[!// Generate an initialization value for a bit register
[!// Individual values must be explicitly listed
[!//
[!MACRO "GenCfgRegister", "defList" = "''", "valList" = "''", "comment" = "''", "comma"="''"!][!//
[!CODE!]
    /* [!"$comment"!] */
[!ENDCODE!][!//            
    [!IF "$defList=''"!][!//
[!CODE!][!//
    (uint32)0UL[!"$comma"!]                  /* [!"$comment"!] */
[!ENDCODE!][!//            
    [!ELSE!][!//
        [!VAR "idx"="0"!][!//
        [!VAR "RegVal"="0"!][!//
        [!VAR "Flg"="0"!][!//
        [!LOOP "text:split( $defList, ':' )"!][!//
            [!IF ". != ''"!][!//
                [!VAR "Name"="."!][!//
                [!VAR "idx"="$idx + 1"!][!//
                [!VAR "val"="text:split( $valList, ',' )[ position()=$idx ]"!][!//
                [!VAR "RegVal"="bit:or( $RegVal, $val )"!][!//
                [!VAR "Or"="node:when( $Flg, '         | ', '(uint32)(  ' )"!][!//
                [!VAR "Flg"="1"!][!//
[!CODE!][!//
    [!"$Or"!][!"$Name"!]
[!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
[!CODE!][!//
             )[!"$comma"!]                   /* [!"$comment"!] = [!"num:inttohex( $RegVal, 8 )"!]UL */
[!ENDCODE!][!//
    [!ENDIF!][!//
[!ENDMACRO!][!//



[!//
[!// Generate an initialization value for a bit register
[!// All values for which FaultList is set
[!//
[!MACRO "GenBitRegister", "valList" = "''", "comment" = "''", "TrueVal"="'MCEM_ENABLED'", "FalseVal"="'MCEM_DISABLED'"!][!//
[!CODE!]
    /* [!"$comment"!]s */
[!ENDCODE!][!//
    [!VAR "RegsORed"="0"!][!//
    [!VAR "RegsNum"="num:i(substring-before('4U','U')-1)"!][!//
    [!FOR "wordIdx"="0" TO "$RegsNum"!][!//
        [!VAR "faultOffset"="$wordIdx * 32"!][!//
        [!VAR "FWord"="substring( $FaultList, $faultOffset+1, 32 )"!][!//
        [!IF "$Empty = $FWord"!][!//
[!CODE!][!//
[!IF "$wordIdx='0'"!][!//
   {(uint32)0UL,              /* [!"$comment"!] [!"num:i( $wordIdx )"!] */
[!ELSEIF "$wordIdx = $RegsNum"!][!//
    (uint32)0UL},             /* [!"$comment"!] [!"num:i( $wordIdx )"!] */
[!ELSE!][!//
    (uint32)0UL,                  /* [!"$comment"!] [!"num:i( $wordIdx )"!] */
[!ENDIF!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
            [!VAR "Word"="substring( $valList, $faultOffset+1, 32 )"!][!//
            [!VAR "RegVal"="0"!][!//
            [!VAR "Flg"="0"!][!//
            [!FOR "bit"="0" TO "31"!][!//
                [!IF "substring( $FWord, $bit+1, 1 ) = '1'"!][!//
                    [!VAR "BitCfg"="substring( $Word, $bit+1, 1 )"!][!//
                    [!IF "$BitCfg='1'"!][!VAR "RegVal"="bit:bitset( $RegVal, $bit )"!][!ENDIF!][!//
                        [!IF "$wordIdx='0'"!][!//
                    [!VAR "Or"="node:when( $Flg, '         | ', '{(uint32)(  ' )"!][!//
                        [!ELSE!][!//
                    [!VAR "Or"="node:when( $Flg, '         | ', '(uint32)(  ' )"!][!//
                        [!ENDIF!][!//       
                    [!VAR "Name"="ecu:list( 'Mcem.McemConfigSet.Fault.SignalDesc' )[ position()-1 = ($faultOffset+$bit) ]"!][!//
                    [!VAR "Flg"="1"!][!//
[!CODE!][!//
    [!"$Or"!]MCEM_CONFIG_VAL_1BIT( [!"text:toupper( $Name )"!], [!"node:when( $BitCfg='1', $TrueVal, $FalseVal )"!] )
[!ENDCODE!][!//            
                [!ENDIF!][!//
            [!ENDFOR!][!//
            [!VAR "RegsORed"="bit:or( $RegsORed, $RegVal )"!][!//
[!CODE!][!//
            [!"node:when( $wordIdx=$RegsNum, ')},', '),' )"!]                   /* [!"$comment"!] [!"num:i( $wordIdx )"!] = [!"num:inttohex( $RegVal, 8 )"!]UL */
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ENDMACRO!][!//



[!//
[!// Generate an initialization value for a 2-bit register
[!// All values for which FaultList is set
[!//
[!MACRO "GenBit2Register", "valList" = "''", "comment" = "''", "Defines"="''"!][!//
[!CODE!]
    /* [!"$comment"!]s */
[!ENDCODE!][!//            
    [!VAR "RegsNum"="num:i(substring-before('8U','U')-1)"!][!//
    [!FOR "wordIdx"="0" TO "$RegsNum"!][!//
        [!VAR "faultOffset"="$wordIdx * 16"!][!//
        [!VAR "RegVal"="0"!][!//
        [!VAR "FWord"="substring( $FaultList, $faultOffset+1, 16 )"!][!//
        [!VAR "Word"="substring( $valList, $faultOffset+1, 16 )"!][!//
        [!IF "starts-with( $Empty, $FWord )"!][!//
[!CODE!][!//
[!IF "$wordIdx='0'"!][!//
   {(uint32)0UL,              /* [!"$comment"!] [!"num:i( $wordIdx )"!] */
[!ELSEIF "$wordIdx = $RegsNum"!][!//
    (uint32)0UL},             /* [!"$comment"!] [!"num:i( $wordIdx )"!] */
[!ELSE!][!//
    (uint32)0UL,              /* [!"$comment"!] [!"num:i( $wordIdx )"!] */
[!ENDIF!][!//
[!ENDCODE!][!//            
        [!ELSE!][!//
            [!VAR "Flg"="0"!][!//
            [!FOR "bit"="0" TO "15"!][!//
                [!IF "substring( $FWord, $bit+1, 1 ) = '1'"!][!//
                    [!VAR "BitCfg"="num:i( substring( $Word, $bit+1, 1 ) )"!][!//
                    [!VAR "RegVal"="bit:or( $RegVal, bit:shl( $BitCfg, 2*$bit ) )"!][!//
                    [!VAR "Def"="text:split( $Defines, ',' )[ position()=($BitCfg+1) ]"!][!//
                    [!VAR "Def"="text:split( $Def, ':' )[ position()=1 ]"!]
                        [!IF "$wordIdx='0'"!][!//
                    [!VAR "Or"="node:when( $Flg, '         | ', '{(uint32)(  ' )"!][!//
                        [!ELSE!][!//
                    [!VAR "Or"="node:when( $Flg, '         | ', '(uint32)(  ' )"!][!//
                        [!ENDIF!][!//
                    [!VAR "Name"="ecu:list( 'Mcem.McemConfigSet.Fault.SignalDesc' )[ position()-1 = ($faultOffset+$bit) ]"!][!//
                    [!VAR "Flg"="1"!][!//
[!CODE!][!//
    [!"$Or"!]MCEM_CONFIG_VAL_2BITS( [!"text:toupper( $Name )"!], MCEM_FCCU_REACTION_[!"text:toupper( $Def )"!] )
[!ENDCODE!][!//            
                [!ENDIF!][!//
            [!ENDFOR!][!//
[!CODE!][!//
             )[!"node:when( $wordIdx=$RegsNum, '}', ',' )"!]                   /* [!"$comment"!] [!"num:i( $wordIdx )"!] = [!"num:inttohex( $RegVal, 8 )"!]UL */
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ENDMACRO!][!//



[!//
[!// Auxiliary variables
[!// Reset reaction types and their values
[!VAR "ResetTypes"="'NoResetReaction:0,ShortResetReaction:1,LongResetReaction:2'"!][!//
[!// Zero register ('00...0', length 32)
[!VAR "Empty"="''"!][!//
[!FOR "wordIdx"="0" TO "31"!][!//
    [!VAR "Empty"="concat( $Empty, '0' )"!][!//
[!ENDFOR!][!//


[!CODE!][!//

[!IF "normalize-space(McemConfigSet/McemErrorNotificationWithAddressAPI) != 'NULL_PTR'"!][!//
    extern void [!"normalize-space(McemConfigSet/McemErrorNotificationWithAddressAPI)"!] (Mcem_FaultType FaultID, uint32 u32FaultAddr);
[!ELSE!]
    [!IF "McemGeneral/McemEnableIsrSingleErrorBit or McemGeneral/McemEnableIsrDoubleErrorBit"!]
        [!WARNING "ISR handler may not process properly if user do not do any action with error notification"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

#define MCEM_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3 precautions to prevent the contents of a header file being included twice */
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

[!ENDCODE!][!//

[!VAR "AlarmAnyNotifNULL"="node:when( node:value( McemGeneral/McemAlarmNotificationApi ), 0, 1 )"!][!//

[!SELECT "McemConfigSet"!][!//
  [!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
    [!// Settings for each Variant
    [!IF "var:defined('postBuildVariant')"!][!//
        [!VAR "CfgSuffix" = "concat( 'PB_', $postBuildVariant)"!][!//
        [!VAR "MCEM_Cfg"  = "concat( as:name(.), '_', $postBuildVariant)"!][!//
    [!ELSE!][!//
        [!VAR "CfgSuffix" = "'PB'"!][!//
        [!VAR "MCEM_Cfg"  = "as:name(.)"!][!//
    [!ENDIF!][!//
  [!ELSE!]
    [!VAR "CfgSuffix" = "'_Predefined'"!][!//
    [!VAR "MCEM_Cfg"  = "'Mcem_PBCfgVariantPredefined'"!][!//
  [!ENDIF!][!//

[!CODE!]static CONST(Mcem_Eirm_ConfigType, MCEM_CONST) Eirm_Config[!"$CfgSuffix"!] = {
[!ENDCODE!][!//
    [!VAR "Var_EirmInterruptConfig"="''"!]
    [!VAR "Var_EirmFaultConfig"="''"!]
    [!VAR "Var_FaultList"="''"!]

    [!VAR "Var_DefaultIrqConfig"="node:when( node:value( ./DefaultFaultConfig/FaultIrqEnabled ), '1', '0' )"!]
    
    [!LOOP "ecu:list('Mcem.McemConfigSet.Fault.SignalDesc')"!][!//
        [!VAR "Var_EirmInterruptConfig"="concat($Var_EirmInterruptConfig,$Var_DefaultIrqConfig)"!]
        [!VAR "Var_EirmFaultConfig"="concat($Var_EirmFaultConfig,'1')"!]
        [!VAR "Var_FaultList"="concat($Var_FaultList, . ,',')"!]
    [!ENDLOOP!][!//
    
    [!LOOP "Fault/*"!][!//
        [!VAR "Var_Idx"="indexOf( ecu:list( 'Mcem.McemConfigSet.Fault.SignalDesc' ), node:value( SignalDesc ) )"!]
        [!IF "(FaultDisabled='false') and (FaultIrqEnabled='true')"!]
            [!VAR "Var_FaltIrqEnable"="'1'"!]
        [!ELSE!]
            [!VAR "Var_FaltIrqEnable"="'0'"!]
        [!ENDIF!]
        [!IF "(FaultDisabled='true')"!]
            [!VAR "Var_LocalEirmFaultConfig"="'0'"!]
        [!ELSE!]
            [!VAR "Var_LocalEirmFaultConfig"="'1'"!]
        [!ENDIF!]
        [!VAR "Var_EirmInterruptConfig"="concat( substring( $Var_EirmInterruptConfig, 1, $Var_Idx ), $Var_FaltIrqEnable, substring( $Var_EirmInterruptConfig, $Var_Idx+2 ) )"!][!//
        [!VAR "Var_EirmFaultConfig"="concat( substring( $Var_EirmFaultConfig, 1, $Var_Idx ), $Var_LocalEirmFaultConfig, substring( $Var_EirmFaultConfig, $Var_Idx+2 ) )"!][!//
    [!ENDLOOP!]
   
[!CODE!]
/* Fault Configuration:
    [!FOR "Var_Idx" = "1" TO "num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!// maximum 4 faults in EIRM
        - Fault [!"text:split($Var_FaultList,',')[position()=$Var_Idx]"!] [!IF "substring($Var_EirmFaultConfig,$Var_Idx, 1)='1'"!]ENABLE[!ELSE!]DISABLE[!ENDIF!][!//
    [!ENDFOR!][!//
    */
    (uint32)(
    [!FOR "Var_Idx" = "1" TO "num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!// maximum 4 faults in EIRM
        [!IF "substring($Var_EirmFaultConfig,$Var_Idx, 1)='1'"!][!//
        ((uint32)1U << [!"text:split($Var_FaultList,',')[position()=$Var_Idx]"!]_SHIFT_U8) [!IF "$Var_Idx < num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!WS!]|[!ENDIF!][!//
        [!ELSE!][!//
        ((uint32)0U << [!"text:split($Var_FaultList,',')[position()=$Var_Idx]"!]_SHIFT_U8) [!IF "$Var_Idx < num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!WS!]|[!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!CR!][!//
            ),
    /* Fault Interrupt Configuration:
    [!FOR "Var_Idx" = "1" TO "num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!// maximum 4 faults in EIRM
        - Fault [!"text:split($Var_FaultList,',')[position()=$Var_Idx]"!] [!IF "substring($Var_EirmInterruptConfig,$Var_Idx, 1)='1'"!]ENABLE[!ELSE!]DISABLE[!ENDIF!][!//
    [!ENDFOR!][!//
    */
    (uint32)(
    [!FOR "Var_Idx" = "1" TO "num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!// maximum 4 faults in EIRM
        [!IF "substring($Var_EirmInterruptConfig,$Var_Idx, 1)='1'"!][!//
        ((uint32)1U << [!"text:split($Var_FaultList,',')[position()=$Var_Idx]"!]_SHIFT_U8) [!IF "$Var_Idx < num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!WS!]|[!ENDIF!][!//
        [!ELSE!][!//
        ((uint32)0U << [!"text:split($Var_FaultList,',')[position()=$Var_Idx]"!]_SHIFT_U8) [!IF "$Var_Idx < num:i(count(text:split(ecu:get('Mcem.McemConfigSet.Fault.SignalDesc'),',')))"!][!WS!]|[!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!CR!][!//
            ),
[!IF "node:exists(McemTcmLowerAddr)"!][!//
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 Pointer conversion */
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7 Pointer conversion */
    (uint32 *)[!"num:inttohex(bit:and(McemTcmLowerAddr,num:hextoint('0xFFFFFFFC')))"!]U,
[!ELSE!][!//
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 Pointer conversion */
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7 Pointer conversion */
    (uint32 *)0x1FFFFF00U,
[!ENDIF!][!//
[!IF "node:exists(McemTcmUpperAddr)"!][!//
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 Pointer conversion */
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7 Pointer conversion */
    (uint32 *)[!"num:inttohex(bit:and(McemTcmUpperAddr,num:hextoint('0xFFFFFFFC')))"!]U,
[!ELSE!][!//
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_6 Pointer conversion */
    /* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_7 Pointer conversion */
    (uint32 *)0x20000000U,
[!ENDIF!][!//
    (uint32) [!IF "contains(McemInjectBit1,'CHECK_BIT_')"!]((uint32)1U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ELSE!]((uint32)0U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ENDIF!],[!CR!][!//
    (uint32) [!IF "contains(McemInjectBit1,'DATA_BIT_')"!]((uint32)1U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ELSE!]((uint32)0U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ENDIF!],[!CR!][!//
    (uint32) [!IF "contains(McemInjectBit1,'CHECK_BIT_')"!]((uint32)1U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ELSE!]((uint32)0U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ENDIF!] |[!CR!][!//
             [!IF "contains(McemInjectBit2,'CHECK_BIT_')"!]((uint32)1U << MCEM_EIM_[!"McemInjectBit2"!]_SHIFT_U8)[!ELSE!]((uint32)0U << MCEM_EIM_[!"McemInjectBit2"!]_SHIFT_U8)[!ENDIF!],[!CR!][!//
    (uint32) [!IF "contains(McemInjectBit1,'DATA_BIT_')"!]((uint32)1U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ELSE!]((uint32)0U << MCEM_EIM_[!"McemInjectBit1"!]_SHIFT_U8)[!ENDIF!] |[!CR!][!//
             [!IF "contains(McemInjectBit2,'DATA_BIT_')"!]((uint32)1U << MCEM_EIM_[!"McemInjectBit2"!]_SHIFT_U8)[!ELSE!]((uint32)0U << MCEM_EIM_[!"McemInjectBit2"!]_SHIFT_U8)[!ENDIF!],[!CR!][!//
[!IF "normalize-space(McemErrorNotificationWithAddressAPI) = 'NULL_PTR'"!][!//
    NULL_PTR
[!ELSE!][!//
    &[!"normalize-space(McemErrorNotificationWithAddressAPI)"!]
[!ENDIF!][!//
};
[!ENDCODE!][!//
[!IF "node:exists(McemTcmUpperAddr)"!][!//
    [!IF "bit:and(McemTcmUpperAddr,num:hextoint('0x00000003'))  != 0"!][!//
        [!WARNING "In order to access address at McemTcmUpperAddr in 32-bits mode, it is required to align this address to 4. Driver automatically do the rounding to lower address which align 4 bit."!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(McemTcmLowerAddr)"!][!//
    [!IF "bit:and(McemTcmLowerAddr,num:hextoint('0x00000003')) != 0"!][!//
        [!WARNING "In order to access address at McemTcmLowerAddr in 32-bits mode, it is required to align this address to 4. Driver automatically do the rounding to lower address which align 4 bit."!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

[!CODE!][!//
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5 Public configuration */
CONST(Mcem_ConfigType, MCEM_CONST) [!"$MCEM_Cfg"!] = 
{
    (boolean)[!IF "(McemHardlockedConfiguration='true') or (McemSoftLockedConfiguration='true')"!]TRUE,[!ELSE!]FALSE,[!ENDIF!][!//
                       /* This configuration will [!IF "(McemHardlockedConfiguration='true') or (McemSoftLockedConfiguration='true')"!][!ELSE!]not [!ENDIF!]be locked */     
    &Eirm_Config[!"$CfgSuffix"!],            /* Memu configuration pointer */
};

[!ENDCODE!][!//
[!ENDSELECT!][!//

[!CODE!][!//

#define MCEM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3 precautions to prevent the contents of a header file being included twice */
/* @violates @ref CDD_Mcem[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


[!ENDCODE!][!//

[!ENDNOCODE!][!//

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
