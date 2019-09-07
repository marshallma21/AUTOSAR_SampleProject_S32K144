[!CODE!][!//
/**
*     @file       CDD_Crcu_Cfg.c
*     @implements CDD_Crcu_Cfg.c_Artifact
*     @version    1.0.1
*     
*     @brief      Crcu - contains the data exported by the Crc module
*     @details    Contains the information that will be exported by the module, as requested by Autosar.
*     
*     @addtogroup CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project              : AUTOSAR 4.2 MCAL
*     Platform             : ARM
*     Peripheral           : CRCV2
*     Dependencies         : none
*     
*     Autosar Version      : 4.2.2
*     Autosar Revision     : ASR_REL_4_2_REV_0002
*     Autosar Conf.Variant :
*     SW Version           : 1.0.1
*     Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*     
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_Cfg_c_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_Cfg_c_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported for external identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section Crcu_Cfg_c_REF_3
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. MemMap.h is included after each section define
*          in order to set the current memory section as defined by AUTOSAR.
*
* @section Crcu_Cfg_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section Crcu_Cfg_c_REF_5
*          Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one
*          and only one file. This requirement is fulfilled since the function is declared as external in one 
*          and only in one configuration C file (either Crcu_Cfg.c or Crcu_PBcfg.c).
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
*==================================================================================================*/
#include "CDD_Crcu_Cfg.h"

[!//
[!NOCODE!][!//
    [!INCLUDE "Crcu_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
*==================================================================================================*/
#define CRCU_CFG_VENDOR_ID_C                      43
/** @violates @ref Crcu_Cfg_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_CFG_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Crcu_Cfg_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_CFG_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Crcu_Cfg_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_CFG_AR_RELEASE_REVISION_VERSION_C    2
#define CRCU_CFG_SW_MAJOR_VERSION_C               1
#define CRCU_CFG_SW_MINOR_VERSION_C               0
#define CRCU_CFG_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
*==================================================================================================*/
/* Check if current file and CDD_Crcu_Cfg.h header file are of the same vendor */
#if (CRCU_CFG_VENDOR_ID_C != CRCU_CFG_VENDOR_ID)
    #error "CDD_Crcu_Cfg.c and CDD_Crcu_Cfg.h have different vendor IDs"
#endif
/* Check if current file and CDD_Crcu_Cfg.h header file are of the same Autosar version */
#if ((CRCU_CFG_AR_RELEASE_MAJOR_VERSION_C != CRCU_CFG_AR_RELEASE_MAJOR_VERSION) ||      \
     (CRCU_CFG_AR_RELEASE_MINOR_VERSION_C != CRCU_CFG_AR_RELEASE_MINOR_VERSION) ||      \
     (CRCU_CFG_AR_RELEASE_REVISION_VERSION_C != CRCU_CFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of CDD_Crcu_Cfg.c and CDD_Crcu_Cfg.h are different"
#endif
/* Check if current file and CDD_Crcu_Cfg.h header file are of the same Software version */
#if ((CRCU_CFG_SW_MAJOR_VERSION_C != CRCU_CFG_SW_MAJOR_VERSION) || \
     (CRCU_CFG_SW_MINOR_VERSION_C != CRCU_CFG_SW_MINOR_VERSION) || \
     (CRCU_CFG_SW_PATCH_VERSION_C != CRCU_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crcu_Cfg.c and CDD_Crcu_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
*==================================================================================================*/


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
*==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
*==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
*==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
*==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
*==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
*==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
