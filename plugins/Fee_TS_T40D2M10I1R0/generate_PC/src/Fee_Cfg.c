[!AUTOSPACING!]
[!CODE!]
/**
*   @file    Fee_Cfg.c
*   @implements Fee_Cfg.c_Artifact   
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - AUTOSAR Module Flash EEPROM Emulation Driver.
*   @details Definitions of all Pre-compile configuration structures.
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
/*==================================================================================================
==================================================================================================*/

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
* Violates MISRA 2004 Advisory Rule 19.1, #include statement preceded by some code 
* #include statements should only be preceded by other preprocessor directive or comments.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters due to 
* AUTOSAR compatibility.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* External identifiers are not distinct in the first 6 characters due to AUTOSAR
* compatibility.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_CFG_C                      43
#define FEE_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FEE_AR_RELEASE_MINOR_VERSION_CFG_C       2
#define FEE_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define FEE_SW_MAJOR_VERSION_CFG_C               1
#define FEE_SW_MINOR_VERSION_CFG_C               0
#define FEE_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_CFG_C != FEE_VENDOR_ID)
    #error "Fee_Cfg.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fee header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_CFG_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_CFG_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_CFG_C != FEE_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif
/* Check if current file and Fee header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_CFG_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_CFG_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_CFG_C != FEE_SW_PATCH_VERSION)\
    )
    #error "Software Version Numbers of Fee_Cfg.c and Fee.h are different"
#endif

[!INCLUDE "Fee_VersionCheck.m"!][!//


#define FEE_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
#include "Fee_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!VAR "FeeVPS" = "num:i(FeeGeneral/FeeVirtualPageSize)"!]
[!VAR "FeeBlkOverhead" = "num:i(ceiling(12 div $FeeVPS + 2) * $FeeVPS)"!]
[!VAR "FeeClsOverhead" = "num:i(ceiling(16 div $FeeVPS + 2) * $FeeVPS)"!]

[!LOOP "FeeClusterGroup/*"!]
/* Configuration of cluster group [!"node:name(.)"!] */
static CONST(Fee_ClusterType, FEE_CONST) Fee_[!"node:name(.)"!][[!"num:i(count(FeeCluster/*))"!]] =
{
    [!VAR "FeeLoopIt" = "count(FeeCluster/*)"!]
    [!LOOP "FeeCluster/*"!]
        [!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!]
        [!VAR "FeeClusterSize" = "0"!]
        [!LOOP "FeeSector/*"!]
            [!VAR "FeeClusterSize" = "$FeeClusterSize + num:i(node:ref(./FeeSectorRef)/FlsSectorSize) * num:i(node:ref(./FeeSectorRef)/FlsNumberOfSectors)"!]
        [!ENDLOOP!]
    /* [!"node:name(.)"!] */
    {
        [!"num:i(node:ref(FeeSector/*[FeeSectorIndex = 0]/FeeSectorRef)/FlsSectorStartaddress)"!]U, /* Start address */
        [!"num:i($FeeClusterSize)"!]U /* Size */
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!//
    [!ENDLOOP!]
};
[!ENDLOOP!]

[!// Check if there is no immediate block when Fee legacy mode is disable
[!IF "FeeGeneral/FeeLegacyMode = 'false'"!][!//
    [!VAR "IsThereImmediateBlock" = "0"!][!//
    [!LOOP "FeeBlockConfiguration/*"!][!//
        [!IF "./FeeImmediateData"!][!//
            [!VAR "IsThereImmediateBlock" = "1"!][!//
            [!BREAK!][!//
        [!ENDIF!][!//        
    [!ENDLOOP!][!//

    [!IF "$IsThereImmediateBlock = 0"!][!//
        [!ERROR!] [!//
 There is no Fee block configured as containing immediate data while FeeLegacyMode is off [!//
        [!ENDERROR!][!//
    [!ENDIF!][!//
[!ENDIF!][!//

/* Configuration of cluster group set */
CONST(Fee_ClusterGroupType, FEE_CONST) Fee_ClrGrps[FEE_NUMBER_OF_CLUSTER_GROUPS] =
{
[!VAR "FeeLoopIt" = "count(FeeClusterGroup/*)"!]
[!LOOP "FeeClusterGroup/*"!]
    [!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!]
    [!// Compute the size of the reserved area (immediate block headers and aligned data)
    [!VAR "FeeReservedSize" = "0"!][!//
    [!LOOP "../../FeeBlockConfiguration/*[node:name(node:ref(FeeClusterGroupRef)) = node:current()/@name]"!]
        [!IF "./FeeImmediateData"!]
            [!VAR "FeeReservedSize" = "$FeeReservedSize + $FeeBlkOverhead + [!//
                             num:i( ceiling( ./FeeBlockSize div $FeeVPS ) * $FeeVPS )"!]
        [!ENDIF!]
    [!ENDLOOP!]     
    /* [!"node:name(.)"!] */
    {
        Fee_[!"node:name(.)"!], /* Cluster set */
        [!"num:i(count(./FeeCluster/*))"!]U, /* Number of clusters */
        [!"num:i( $FeeReservedSize )"!]U /* Size of the reserved area */        
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!//

[!ENDLOOP!]
};

/* Configuration of Fee blocks */
CONST(Fee_BlockConfigType, FEE_CONST) Fee_BlockConfig[FEE_CRT_CFG_NR_OF_BLOCKS] =
{
[!VAR "FeeLoopIt" = "count(FeeBlockConfiguration/*)"!]
[!LOOP "node:order(FeeBlockConfiguration/*,'node:value(./FeeBlockNumber)')"!]
    [!VAR "FeeLoopIt" = "$FeeLoopIt - 1"!]
    /* [!"node:name(.)"!] */
    {
        FeeConf_FeeBlockConfiguration_[!"node:name(.)"!], /* FeeBlockNumber symbol */
        [!"./FeeBlockSize"!]U, /* FeeBlockSize */
        [!"node:ref(./FeeClusterGroupRef)/@index"!]U, /* FeeClusterGroup */
        (boolean) [!IF "./FeeImmediateData"!]TRUE [!ELSE!]FALSE[!ENDIF!],[!//
   /* FeeImmediateData */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        FEE_PROJECT_[!"node:value(./FeeBlockAssignment)"!] /* Fee Block Assignment to a project */
#else
        FEE_PROJECT_RESERVED
#endif
    }[!IF "$FeeLoopIt != 0"!],[!ENDIF!][!//

[!ENDLOOP!]
};
[!ENDCODE!]


#define FEE_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Fee_cfg_h_REF_1 Repeated include file */
/* @violates @ref Fee_cfg_h_REF_2 #include statement preceded by some code */
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @}*/
