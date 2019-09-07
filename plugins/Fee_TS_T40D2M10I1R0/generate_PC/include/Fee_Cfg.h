[!AUTOSPACING!]
[!CODE!]
/**
*   @file    Fee_Cfg.h
*   @implements Fee_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all pre-compile configuration parameters..
*
*   @addtogroup FEE
*   @{

*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : none
*   Dependencies         : Fls
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

#ifndef FEE_CFG_H
#define FEE_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_cfg_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR
* requirement MEMMAP003.
*
* @section Fee_cfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for a macro.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external
* identifiers.
* Block name symbol defines are too long, handled by preprocessor.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters due to
* AUTOSAR compatibility.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/** @implements   VendorId_Object */
#define FEE_VENDOR_ID_CFG                    43
/** @implements   ModuleId_Object */
#define FEE_MODULE_ID_CFG                    21
/** @implements   ArReleaseMajorVersion_Object */
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @implements   ArReleaseMinorVersion_Object */
#define FEE_AR_RELEASE_MINOR_VERSION_CFG     2
/** @implements   ArReleaseRevisionVersion_Object */
#define FEE_AR_RELEASE_REVISION_VERSION_CFG  2
/** @implements   SwMajorVersion_Object */
#define FEE_SW_MAJOR_VERSION_CFG             1
/** @implements   SwMinorVersion_Object */
#define FEE_SW_MINOR_VERSION_CFG             0
/** @implements   SwPatchVersion_Object */
#define FEE_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and MODULENAME configuration header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG != FEE_TYPES_VENDOR_ID)
    #error "Fee_Types.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same Autosar version
*/
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG    != FEE_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG != FEE_TYPES_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
/* Check if current file and MODULENAME configuration header file are
   of the same software version
*/
#if ((FEE_SW_MAJOR_VERSION_CFG != FEE_TYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG != FEE_TYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG != FEE_TYPES_SW_PATCH_VERSION)\
    )
    #error "Software Version Numbers of Fee_Types.h and Fee_Cfg.h are different"
#endif
[!VAR "NvmEndFlg" = "0"!]
[!IF "node:exists(FeeGeneral/FeeNvmJobEndNotification)"!]
    [!IF "not(text:match(normalize-space(FeeGeneral/FeeNvmJobEndNotification),'^[_a-zA-Z][_0-9a-zA-Z]*$'))"!]
        [!ERROR!]Invalid name of the Fee Nvm Job End Notification routine. Must be a valid C function name, NULL_PTR or NULL.[!ENDERROR!]
    [!ELSE!]
        [!VAR "NvmEndFlg" = "node:when((normalize-space(FeeGeneral/FeeNvmJobEndNotification) = 'NULL_PTR') or (normalize-space(FeeGeneral/FeeNvmJobEndNotification) = 'NULL'),0,1)"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "NvmErrFlg" = "0"!]
[!IF "node:exists(FeeGeneral/FeeNvmJobErrorNotification)"!]
    [!IF "not(text:match(normalize-space(FeeGeneral/FeeNvmJobErrorNotification),'^[_a-zA-Z][_0-9a-zA-Z]*$'))"!]
        [!ERROR!]Invalid name of the Fee Nvm Job Error Notification routine. Must be a valid C function name, NULL_PTR or NULL.[!ENDERROR!]    
    [!ELSE!]
        [!VAR "NvmErrFlg" = "node:when((normalize-space(FeeGeneral/FeeNvmJobErrorNotification) = 'NULL_PTR') or (normalize-space(FeeGeneral/FeeNvmJobErrorNotification) = 'NULL'),0,1)"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "NvmClusterFormatFlg" = "0"!]
[!IF "node:exists(FeeGeneral/FeeClusterFormatNotification)"!]
    [!IF "not(text:match(normalize-space(FeeGeneral/FeeClusterFormatNotification),'^[_a-zA-Z][_0-9a-zA-Z]*$'))"!]
        [!ERROR!]Invalid name of the Fee Cluster Format During Init Notification routine. Must be a valid C function name, NULL_PTR or NULL.[!ENDERROR!]    
    [!ELSE!]
        [!VAR "NvmClusterFormatFlg" = "node:when((normalize-space(FeeGeneral/FeeClusterFormatNotification) = 'NULL_PTR') or (normalize-space(FeeGeneral/FeeClusterFormatNotification) = 'NULL'),0,1)"!]
    [!ENDIF!]
[!ENDIF!]

[!INCLUDE "Fee_VersionCheck.m"!][!//

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
[!VAR "FeeVPS" = "num:i(FeeGeneral/FeeVirtualPageSize)"!]
[!VAR "FeeBlkOverhead" = "num:i(ceiling(12 div $FeeVPS + 2) * $FeeVPS)"!]
[!VAR "FeeClsOverhead" = "num:i(ceiling(16 div $FeeVPS + 2) * $FeeVPS)"!]

/* Pre-processor switch to enable and disable development error detection */
/** @implements   FeeDevErrorDetect_Object */
#define FEE_DEV_ERROR_DETECT                ([!IF "FeeGeneral/FeeDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to read out the modules
    version information */
/** @implements   FeeVersionInfoApi_Object */
#define FEE_VERSION_INFO_API                ([!IF "FeeGeneral/FeeVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compiler switch to enable/disable the SetMode functionality of the module */
/** @implements   FeeSetModeSupported_Object */
#define FEE_SETMODE_API_SUPPORTED           ([!IF "FeeGeneral/FeeSetModeSupported"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

[!SELECT "as:modconf('Fls')"!]
/* Pre-processor switch to enable /disable the Fls_Cancel function of the module */
#define FEE_CANCEL_API                     ([!IF "FlsGeneral/FlsCancelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDSELECT!]

/* The size in bytes to which logical blocks shall be aligned */
/** @implements   FeeVirtualPageSize_Object */
#define FEE_VIRTUAL_PAGE_SIZE               [!"$FeeVPS"!]U

/* Job end notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobEndNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION_DECL   [!//
[!IF "$NvmEndFlg = '1.0'"!]extern void [!"normalize-space(FeeGeneral/FeeNvmJobEndNotification)"!](void);[!ENDIF!]


/* Job end notification routine provided by the upper layer module */
/** @implements   FeeNvmJobEndNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_END_NOTIFICATION        [!//
[!IF "$NvmEndFlg = '1.0'"!][!"normalize-space(FeeGeneral/FeeNvmJobEndNotification)"!]();[!ENDIF!]


/* Job error notification routine provided by the upper layer module (declaration) */
/** @implements   FeeNvmJobErrorNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION_DECL  [!//
[!IF "$NvmErrFlg = '1.0'"!]extern void [!"normalize-space(FeeGeneral/FeeNvmJobErrorNotification)"!](void);[!ENDIF!]


/* Job error notification routine provided by the upper layer module */
/** @implements   FeeNvmJobErrorNotification_Object */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_JOB_ERROR_NOTIFICATION       [!//
[!IF "$NvmErrFlg = '1.0'"!][!"normalize-space(FeeGeneral/FeeNvmJobErrorNotification)"!]();[!ENDIF!]


/* Job cluster format notification routine provided by the upper layer module (declaration) */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL  [!//
[!IF "$NvmClusterFormatFlg = '1.0'"!]extern void [!"normalize-space(FeeGeneral/FeeClusterFormatNotification)"!](void);[!ENDIF!]


/* Job cluster format notification routine provided by the upper layer module */
/* @violates @ref Fee_cfg_h_REF_2 Disallowed definition for macro */
#define FEE_NVM_CLUSTER_FORMAT_NOTIFICATION       [!//
[!IF "$NvmClusterFormatFlg = '1.0'"!][!"normalize-space(FeeGeneral/FeeClusterFormatNotification)"!]();[!ENDIF!]


/* Number of configured Fee cluster groups */
#define FEE_NUMBER_OF_CLUSTER_GROUPS        [!"num:i(count(FeeClusterGroup/*))"!]U

/* Number of configured Fee blocks */
#define FEE_CRT_CFG_NR_OF_BLOCKS                [!"num:i(count(FeeBlockConfiguration/*))"!]U

/* Maximum number of Fee blocks in all project versions and configurations */
#define FEE_MAX_NR_OF_BLOCKS        [!//
[!IF "FeeGeneral/FeeSwapForeignBlocksEnabled"!]    [!"node:value(FeeGeneral/FeeMaximumNumberBlocks)"!]U[!ELSE!] (FEE_CRT_CFG_NR_OF_BLOCKS)[!ENDIF!]

/* Management overhead per logical block in bytes */
/** @implements   FeeBlockOverhead_Object */
#define FEE_BLOCK_OVERHEAD                  [!"$FeeBlkOverhead"!]U

/* Management overhead per logical cluster in bytes */
#define FEE_CLUSTER_OVERHEAD                [!"$FeeClsOverhead"!]U

/* Size of the data buffer in bytes */
#define FEE_DATA_BUFFER_SIZE                [!"num:i(FeeGeneral/FeeDataBufferSize)"!]U

/* The contents of an erased flash memory cell */
#define FEE_ERASED_VALUE                    [!"num:inttohex(bit:and(as:modconf('Fls')[1]/FlsPublishedInformation/FlsErasedValue,255),2)"!]U

/* Value of the block and cluster validation flag */
#define FEE_VALIDATED_VALUE                [!"num:inttohex(bit:and(bit:xor(as:modconf('Fls')[1]/FlsPublishedInformation/FlsErasedValue,126),255),2)"!]U

/* Value of the block and cluster invalidation flag */
#define FEE_INVALIDATED_VALUE              [!"num:inttohex(bit:and(bit:xor(as:modconf('Fls')[1]/FlsPublishedInformation/FlsErasedValue,231),255),2)"!]U

/* If reset, power loss etc. occurs here, neither newly nor previously written data is available */
#define FEE_BLOCK_ALWAYS_AVAILABLE          ([!IF "FeeGeneral/FeeBlockAlwaysAvailable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable Legacy mode (original FEE immediate data handling) */
#define FEE_LEGACY_MODE                     ([!IF "FeeGeneral/FeeLegacyMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Behavior of Fee_ImmediateBlockErase */
#define FEE_LEGACY_IMM_ERASE_MODE           ([!IF "FeeGeneral/FeeLegacyEraseMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* This configuration defines wheather Fee should swap foreign blocks found in flash at swap or not */
#define FEE_SWAP_FOREIGN_BLOCKS_ENABLED          ([!IF "FeeGeneral/FeeSwapForeignBlocksEnabled"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* This configuration defines for which project the Fee configuration is used  */
#define FEE_BOOTLOADER_CONFIG           ([!IF "FeeGeneral/FeeConfigAssignment='BOOTLOADER'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* This configuration defines if the status for the never written blocks must be INVALID or INCONSISTENT */
#define FEE_MARK_EMPTY_BLOCKS_INVALID    ([!IF "FeeGeneral/FeeMarkEmptyBlocksInvalid"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Symbolic names of configured Fee blocks */
[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!]
#define FeeConf_FeeBlockConfiguration_[!"node:name(.)"!]     [!"./FeeBlockNumber"!]U
[!ENDLOOP!]


#define FEE_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "Fee_MemMap.h"

[!LOOP "FeeClusterGroup/*"!]
    [!VAR "FeeSmallestClusterSize" = "2147483647"!]
    [!VAR "FeeLoopIt" = "count(FeeCluster/*)"!]
    [!VAR "FeeReservedSize" = "0"!]
       
    [!LOOP "FeeCluster/*"!]
        [!VAR "FeeClusterSize" = "0"!]
        [!LOOP "FeeSector/*"!]
            [!VAR "FeeClusterSize" = "$FeeClusterSize + (num:i(node:ref(./FeeSectorRef)/FlsSectorSize) * num:i(node:ref(./FeeSectorRef)/FlsNumberOfSectors))"!]
        [!ENDLOOP!]
        [!IF "$FeeClusterSize < $FeeSmallestClusterSize"!]
            [!VAR "FeeSmallestClusterSize" = "$FeeClusterSize"!]
        [!ENDIF!]
    [!ENDLOOP!]

    [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
        [!IF "./FeeImmediateData"!]
            [!VAR "FeeReservedSize" = "$FeeReservedSize + $FeeBlkOverhead + [!//
                             num:i( ceiling( ./FeeBlockSize div $FeeVPS ) * $FeeVPS )"!]
        [!ENDIF!]
    [!ENDLOOP!]    

    [!VAR "FeeAvailClusterSize" = "$FeeSmallestClusterSize - ($FeeClsOverhead + $FeeBlkOverhead)"!]
    [!VAR "FeePrefilledClusterSize" = "$FeeSmallestClusterSize - ($FeeClsOverhead + $FeeBlkOverhead)"!]

    [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
        [!VAR "FeePrefilledClusterSize" = "$FeePrefilledClusterSize - num:i(ceiling(./FeeBlockSize div $FeeVPS) * $FeeVPS) - $FeeBlkOverhead"!]
    [!ENDLOOP!]

    [!IF "../../FeeGeneral/FeeLegacyMode"!]
        [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
            [!VAR "BlkSize" = "num:i(ceiling(./FeeBlockSize div $FeeVPS) * $FeeVPS) + $FeeBlkOverhead"!]
            [!VAR "FeeAvailClusterSize" = "$FeeAvailClusterSize - $BlkSize"!]
            [!VAR "FeePrefilledAvailClusterSize"="$FeePrefilledClusterSize - $BlkSize"!]
            [!IF "($FeeAvailClusterSize < 0) or ($FeePrefilledAvailClusterSize < 0)"!]
                [!ERROR!]
The block [!"node:name(.)"!] is too big. The block doesn't fit into the cluster group [!"node:name(node:ref(./FeeClusterGroupRef))"!].
                [!ENDERROR!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ELSE!]
        [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
            [!IF "./FeeImmediateData ='false'"!]
                [!VAR "BlkSize" = "num:i(ceiling(./FeeBlockSize div $FeeVPS) * $FeeVPS) + $FeeBlkOverhead"!]
                [!VAR "FeeAvailClusterSize" = "$FeeAvailClusterSize - $BlkSize"!]
                [!VAR "FeePrefilledAvailClusterSize"="$FeePrefilledClusterSize - $BlkSize - $FeeReservedSize "!]
                [!IF "($FeeAvailClusterSize < 0) or ($FeePrefilledAvailClusterSize < 0)"!]
                    [!ERROR!]
The block [!"node:name(.)"!] is too big. The block doesn't fit into the cluster group [!"node:name(node:ref(./FeeClusterGroupRef))"!].
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDLOOP!]  
/* Configuration of cluster group set */
extern CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[ FEE_NUMBER_OF_CLUSTER_GROUPS ];

/* Configuration of Fee blocks */
extern CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[ FEE_CRT_CFG_NR_OF_BLOCKS ];

#define FEE_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "Fee_MemMap.h"

[!ENDCODE!]
#ifdef __cplusplus
}
#endif

#endif /* FEE_CFG_H */
/** @} */
