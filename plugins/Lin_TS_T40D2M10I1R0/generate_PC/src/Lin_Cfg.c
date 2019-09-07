/**
*   @file    Lin_Cfg.c
*   @implements Lin_Cfg.c_Artifact
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
* @section Lin_Cfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_Cfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set
* the current memory section
*
* @section Lin_Cfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Lin.h"

#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Cfg.c
*/
#define LIN_VENDOR_ID_CFG_C                      43
/*
* @violates @ref Lin_Cfg_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MAJOR_VERSION_CFG_C       4
/*
* @violates @ref Lin_Cfg_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MINOR_VERSION_CFG_C       2
/*
* @violates @ref Lin_Cfg_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define LIN_SW_MAJOR_VERSION_CFG_C               1
#define LIN_SW_MINOR_VERSION_CFG_C               0
#define LIN_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
[!NOCODE!][!//
[!INCLUDE "Lin_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//
/* Check if current file and Lin.h header file are of the same Autosar version */
#if (LIN_VENDOR_ID_CFG_C != LIN_VENDOR_ID)
    #error "Lin_Cfg.c and Lin.h have different vendor ids"
#endif
#if ((LIN_AR_RELEASE_MAJOR_VERSION_CFG_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_CFG_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_CFG_C != LIN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Lin_Cfg.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_CFG_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_CFG_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_CFG_C != LIN_SW_PATCH_VERSION) )
  #error "Software Version Numbers of Lin_Cfg.c and Lin.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_CFG_C != STD_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_CFG_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lin_Cfg.c and Std_Types.h are different"
  #endif
  #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem.h header file are of the same Autosar version */
    #if ((LIN_AR_RELEASE_MAJOR_VERSION_CFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (LIN_AR_RELEASE_MINOR_VERSION_CFG_C != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lin_Cfg.c and Dem.h are different"
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
#define LIN_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Lin_Cfg_c_REF_1 #include statements in a file should
*     only be preceded by other preprocessor directives or comments.
*/
#include "Lin_MemMap.h"

[!NOCODE!][!//
[!LOOP "LinGlobalConfig/LinChannel/*"!][!//
    [!VAR "nodeName" = "name(.)"!]
    [!CODE!]
CONST(Lin_StaticConfig_ChannelConfigType,LIN_CONST) Lin_[!"node:name(.)"!]_PC=
{
    (uint8)[!"LinChannelId"!]U,     /* Lin Channel ID */
    [!"LinHwChannel"!],             /* Lin Hardware channel*/
[!IF "LinChannelWakeupSupport"!]
    (uint8)STD_ON,                /* Wakeup support enabled */
[!ELSE!]
    (uint8)STD_OFF,               /* Wakeup support disabled */
    [!ENDIF!]
    (EcuM_WakeupSourceType)((uint32)1U<<(uint32)[!"as:ref(LinChannelEcuMWakeupSource)/EcuMWakeupSourceId"!]U)    /* Wakeup Source transmitted to the Ecu State Manager (used only when Wakeup Support is true) */
};
[!ENDCODE!]
[!ENDLOOP!][!//

[!CODE!]
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
 * @brief   DEM error parameters
 */
CONST(Mcal_DemErrorType,LIN_CONST) Lin_E_TimeoutCfg =
{
[!ENDCODE!]

[!VAR "LinDemErrorEnable" = "'false'"!]
[!IF "NonAutosar/LinDisableDemReportErrorStatus ='false'"!][!//
    [!IF "node:exists(LinDemEventParameterRefs)"!]
        [!VAR "LinDemErrorEnable" = "'true'"!]
    [!ENDIF!]
[!ENDIF!]

[!IF "$LinDemErrorEnable"!]
    [!IF "node:exists(LinDemEventParameterRefs/LIN_E_TIMEOUT)"!]
        [!IF "node:exists(node:value(LinDemEventParameterRefs/LIN_E_TIMEOUT))"!]
            [!CODE!]
    (uint32)STD_ON,
    DemConf_DemEventParameter_[!"node:name(node:ref(LinDemEventParameterRefs/LIN_E_TIMEOUT))"!]
            [!ENDCODE!]
        [!ELSE!]
            [!ERROR "Invalid reference for LIN_E_ERROR"!]
        [!ENDIF!]
    [!ELSE!]
        [!CODE!]
    (uint32)STD_OFF,
    0U
        [!ENDCODE!]
    [!ENDIF!]
[!ELSE!]
    [!CODE!]
    (uint32)STD_OFF,
    0U
    [!ENDCODE!]
[!ENDIF!]

[!CODE!]
};
#endif /* LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
[!ENDCODE!]
[!ENDNOCODE!][!//

#define LIN_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Lin_Cfg_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*
* @violates @ref Lin_Cfg_c_REF_2 Only preprocessor
* statements and comments before '#include'
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
