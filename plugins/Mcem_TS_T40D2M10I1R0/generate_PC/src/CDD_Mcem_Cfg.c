[!CODE!][!//
/**
*   @file    CDD_Mcem_Cfg.c
*   @implements     CDD_Mcem_Cfg.c_Artifact
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

[!INCLUDE "CDD_Mcem_VersionCheck_Src.m"!][!//

/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section CDD_Mcem_Cfg_C_REF_1
* Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
* compatibility
*
* @section CDD_Mcem_Cfg_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section CDD_Mcem_Cfg_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
* preprocessor directives or comments.
* Violated due to AUTOSAR requirement MEMMAP003.
* 
* @section CDD_Mcem_Cfg_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects 
* or functions at file scope shall have internal linkage unless external linkage is required.
* Possibly unused public API
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
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_VENDOR_ID_C                        43
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_AR_RELEASE_MAJOR_VERSION_C         4
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_AR_RELEASE_MINOR_VERSION_C         2
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_AR_RELEASE_REVISION_VERSION_C      2
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_SW_MAJOR_VERSION_C                 1
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_SW_MINOR_VERSION_C                 0
/* @violates @ref CDD_Mcem_Cfg_C_REF_1 Exceeds 31 characters */
#define CDD_MCEM_CFG_SW_PATCH_VERSION_C                 1

/*==================================================================================================
*                                      FILE VERSION CHECKS
*==================================================================================================*/

/* Check Mcem_Cfg.c against CDD_Mcem_Cfg.h file versions */
#if (CDD_MCEM_CFG_VENDOR_ID_C != CDD_MCEM_VENDOR_ID_CFG)
    #error "CDD_Mcem_Cfg.c and CDD_Mcem_Cfg.h have different vendor IDs"
#endif

#if ((CDD_MCEM_CFG_AR_RELEASE_MAJOR_VERSION_C != CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (CDD_MCEM_CFG_AR_RELEASE_MINOR_VERSION_C != CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (CDD_MCEM_CFG_AR_RELEASE_REVISION_VERSION_C != CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of CDD_Mcem_Cfg.c and CDD_Mcem_Cfg.h are different"
#endif

#if ((CDD_MCEM_CFG_SW_MAJOR_VERSION_C != CDD_MCEM_SW_MAJOR_VERSION_CFG) || \
     (CDD_MCEM_CFG_SW_MINOR_VERSION_C != CDD_MCEM_SW_MINOR_VERSION_CFG) || \
     (CDD_MCEM_CFG_SW_PATCH_VERSION_C != CDD_MCEM_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of CDD_Mcem_Cfg.c and CDD_Mcem_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
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

#if (STD_ON==MCEM_DEV_ERROR_DETECT)
    #define MCEM_START_SEC_CONST_UNSPECIFIED
    /* @violates @ref CDD_Mcem_Cfg_C_REF_2 only preprocessor statements and comments before "#include". */
    /* @violates @ref CDD_Mcem_Cfg_C_REF_3 precautions to prevent the contents of a header file being included twice. */
    #include "Mcem_MemMap.h"
    /* @violates @ref CDD_Mcem_Cfg_C_REF_4 External object */
    CONST(uint32, MCEM_CONST) Mcem_au32StaticFaultMasks[[!"num:i(count(text:split(ecu:get('Mcem.McemGeneral.FaultReservedMasks'))))"!]U] = { [!"ecu:get('Mcem.McemGeneral.FaultReservedMasks')"!] };
    
    #define MCEM_STOP_SEC_CONST_UNSPECIFIED
    /* @violates @ref CDD_Mcem_Cfg_C_REF_2 only preprocessor statements and comments before "#include". */
    /* @violates @ref CDD_Mcem_Cfg_C_REF_3 precautions to prevent the contents of a header file being included twice. */
    #include "Mcem_MemMap.h"
#endif


#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
