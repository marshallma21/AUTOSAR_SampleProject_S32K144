[!CODE!][!//
/**
*   @file    CDD_Mcem_Cfg.h
*   @implements   CDD_Mcem_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem configuration header.
*   @details This file is the Safety  MCEM driver configuration header. This
*            file is automatically generated, do not modify manually.
*
*
*   @addtogroup MCEM_CFG
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

#ifndef CDD_MCEM_CFG_H
#define CDD_MCEM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section CDD_Mcem_Cfg_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
* preprocessor directives or comments.
* Violated due to AUTOSAR requirement MEMMAP003.
*
* @section CDD_Mcem_Cfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
*
* @section [global]
* Violates MISRA 2004 Required Rule 8.7, Object shall be defined at block scope if they are only 
* accessed from within a single function, due to possible usage of the object in another 
* function or file.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_Mcem_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_MCEM_VENDOR_ID_CFG                   43
#define CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG    4
#define CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG    2
#define CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG 2
#define CDD_MCEM_SW_MAJOR_VERSION_CFG            1
#define CDD_MCEM_SW_MINOR_VERSION_CFG            0
#define CDD_MCEM_SW_PATCH_VERSION_CFG            1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Mcem_Types.h header file are of the same vendor */
#if (CDD_MCEM_VENDOR_ID_CFG != CDD_MCEM_TYPES_VENDOR_ID)
    #error "CDD_Mcem_Cfg.h and CDD_Mcem_Types.h have different Vendor ids"
#endif
/* Check if current file and CDD_Mcem_Types.h header file are of the same Autosar version */
#if ((CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG != CDD_MCEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG != CDD_MCEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG != CDD_MCEM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcem_Cfg.h and CDD_Mcem_Types.h are different"
#endif
/* Check if current file and CDD_Mcem_Types.h header file are of the same Software version */
#if ((CDD_MCEM_SW_MAJOR_VERSION_CFG != CDD_MCEM_TYPES_SW_MAJOR_VERSION) || \
     (CDD_MCEM_SW_MINOR_VERSION_CFG != CDD_MCEM_TYPES_SW_MINOR_VERSION) || \
     (CDD_MCEM_SW_PATCH_VERSION_CFG != CDD_MCEM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcem_Cfg.h and CDD_Mcem_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcem_Cfg.h and Mcal.h are different"
    #endif
#endif

[!INCLUDE "CDD_Mcem_VersionCheck_Inc.m"!][!//
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
/**
*@{
*   @brief Pre-compile configuration constants 
*/
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' and (variant:size()<=1)"!][!//
#define MCEM_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define MCEM_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//
/**
* @brief          Enable/Disable Development Error Detection.
*
* @api
*/
#define MCEM_DEV_ERROR_DETECT        [!IF "McemGeneral/McemDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Enable support for IPV EIRM.
*
* @api
*/
#define     MCEM_EIRM_SUPPORT

/**
* @brief          Enable ISR for SINGLE BIT in IPV EIRM.
*
* @api
*/
#define MCEM_EIRM_FAULT_SINGLEBIT_ISR_ENABLE  [!IF "McemGeneral/McemEnableIsrSingleErrorBit"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Enable ISR for DOUBLE BIT in IPV EIRM.
*
* @api
*/
#define MCEM_EIRM_FAULT_DOUBLEBIT_ISR_ENABLE  [!IF "McemGeneral/McemEnableIsrDoubleErrorBit"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Function @p Mcem_GetVersionInfo() enable switch.
*
* @api
*/
#define MCEM_GET_VERSION_INFO_API    [!IF "McemGeneral/McemVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Enable/Disable EIRM Cortex M0
*
* @api
*/
#define MCEM_EIRM_CORTEX_M0  [!IF "ecu:get('Mcem.McemEIRMcortexM0')='true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Enable/Disable EIRM Cortex M4
*
* @api
*/
#define MCEM_EIRM_CORTEX_M4  [!IF "ecu:get('Mcem.McemEIRMcortexM4')='true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Function @p Mcem_AlarmNotification usage
*
* @api
*/
#define MCEM_ALARM_NOTIFICATION_API  [!IF "McemGeneral/McemAlarmNotificationApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief          Enable/disable extended DEM error reporting
*
* @api
*/
#define MCEM_DEM_EXTENDED_DATA     (STD_OFF)

/**
* @brief          Enable/Disable User support mode
*
* @api
*/
#define MCEM_ENABLE_USER_MODE_SUPPORT  [!IF "McemGeneral/McemEnableUserModeSupport"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == MCEM_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running MCEM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == MCEM_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
/*=================================================================================================
*                                             ENUMS
=================================================================================================*/

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
/**
* @brief          Configuration struct type.
* @details        MCEM Driver configuration structure type. 
*
* @implements     Mcem_ConfigType_struct
*/
typedef struct
{
#ifdef MCEM_FCCU_SUPPORT
    CONST(Mcem_NotifyType, AUTOMATIC)                    AlarmNotification;   /**< @brief MCEM Alarm Interrupt Notification function. */
    CONST(Mcem_NotifyVoidType, AUTOMATIC)                CfgToNotification;   /**< @brief MCEM Configuration TimeOut Interrupt Notification function. */
#endif
    CONST(boolean, AUTOMATIC)                            Lockable;            /**< @brief This configuration will be locked. */
#ifdef MCEM_MEMU_SUPPORT
    P2CONST(Memu_ConfigType, AUTOMATIC, MCEM_APPL_CONST) MemuConfig;          /**< @brief Memu Configuration values. */
#endif
#ifdef MCEM_FCCU_SUPPORT
    P2CONST(Fccu_ConfigType, AUTOMATIC, MCEM_APPL_CONST) FccuConfig;          /**< @brief Fccu Configuration values. */
#endif
#ifdef MCEM_EIRM_SUPPORT
    P2CONST(Mcem_Eirm_ConfigType, AUTOMATIC, MCEM_APPL_CONST) EirmConfig;          /**< @brief Fccu Configuration values. */
#endif
} Mcem_ConfigType;

[!NOCODE!][!//
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
#define MCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref CDD_Mcem_Cfg_h_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_Cfg_h_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"
  [!VAR "configName" = "as:name(McemConfigSet)"!][!//
  [!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
      [!CODE!][!WS4!]extern CONST(Mcem_ConfigType, MCEM_CONST) [!"$configName"!]_[!"."!];[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
  [!ELSE!][!//
      [!CODE!][!WS4!]extern CONST(Mcem_ConfigType, MCEM_CONST) [!"$configName"!];[!CR!][!ENDCODE!][!//
  [!ENDIF!][!//
#define MCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref CDD_Mcem_Cfg_h_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_Cfg_h_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"
[!ENDIF!][!//
[!ENDNOCODE!][!//


#if (STD_ON==MCEM_DEV_ERROR_DETECT)
    extern CONST(uint32, MCEM_CONST) Mcem_au32StaticFaultMasks[[!"num:i(count(text:split(ecu:get('Mcem.McemGeneral.FaultReservedMasks'))))"!]U];
#endif

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* CDD_MCEM_CFG_H */

/** @} */
[!ENDCODE!][!//
