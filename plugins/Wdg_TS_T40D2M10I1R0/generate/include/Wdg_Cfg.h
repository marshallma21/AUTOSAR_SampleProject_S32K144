/**
*   @file     Wdg_Cfg.h
*   @implements Wdg_Cfg.h_Artifact
*   @version  1.0.1
*
*   @brief    AUTOSAR Wdg - Contains the implementation of the Watchdog API
*   @details  It contains the layer requested by autosar. The functions are independent of
*             hardware settings.
*
*   @addtogroup  Wdg  
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Wdog
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

#ifndef WDG_CFG_H
#define WDG_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Wdg_Cfg_h_REF_2
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of configuration sets
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Wdg_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are 
*          only accessed from within a single function.
*          These objects are used in various parts of the code
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "WdgIf_Types.h"
/** @violates @ref Wdg_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
 *                of a header file being included twice */
#include "Mcal.h"
[!NOCODE!][!//
[!VAR "WdgDisableDemReport" = "0"!]
[!IF "node:exists(WdgDemEventParameterRefs)"!]
      [!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'true'"!]
        [!VAR "WdgDisableDemReport" = "1"!]
      [!ENDIF!]
[!ELSE!]
  [!VAR "WdgDisableDemReport" = "1"!]
[!ENDIF!]
[!ENDNOCODE!][!//
[!IF "$WdgDisableDemReport = 0"!]
#include "Dem.h"
[!ENDIF!]
[!INCLUDE "Wdg_VersionCheck_Inc.m"!][!//
[!INCLUDE "Wdg_PluginMacros.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Cfg.h
*/
#define WDG_VENDOR_ID_CFG                    43
#define WDG_MODULE_ID_CFG                    102
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG     4
#define WDG_AR_RELEASE_MINOR_VERSION_CFG     2
#define WDG_AR_RELEASE_REVISION_VERSION_CFG  2
#define WDG_SW_MAJOR_VERSION_CFG             1
#define WDG_SW_MINOR_VERSION_CFG             0
#define WDG_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/



/* Check if source file and WdgIf_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (( WDG_AR_RELEASE_MAJOR_VERSION_CFG != WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         ( WDG_AR_RELEASE_MINOR_VERSION_CFG != WDGIF_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Wdg_Cfg.h and WdgIf_Types.h are different"
    #endif
#endif
[!IF "$WdgDisableDemReport = 0"!]
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Dem header file are of the same Autosar version */
     #if (( WDG_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
          ( WDG_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION) \
         )
         #error "AutoSar Version Numbers of Wdg_Channel.c and Dem.h are different"
     #endif
 #endif
[!ENDIF!]

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONST_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice*/
#include "Wdg_MemMap.h"
 /**
 * @brief Dem error codes
 */
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Disable_Rejected;
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Mode_Failed;
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Corrupt_Config;
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Invalid_Call;
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Forbidden_Invocation;
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)WDG_E_Unlocked;
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/*@violates @ref Wdg_Cfg_h_REF_3 MISRA Rule 8.7 Objects shall be defined at block scope if they are only accessed from within a single function */
extern CONST(Mcal_DemErrorType, WDG_CONST)Wdg_E_Invalid_Parameter;
[!ENDIF!][!//
[!ENDIF!][!//

#define WDG_STOP_SEC_CONST_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
 /**
 * @brief Dem error codes
 */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!CALL "WdgCheckCbkNotification","WdogInstance"="'WDOG0'"!]


[!CALL "WdgInstanceMacro","WdogInstance" = "'WDOG0'"!]
[!CALL "WdgInstanceMacro","WdogInstance" = "'WDOG1'"!]
[!CALL "WdgInstanceMacro","WdogInstance" = "'WDOG2'"!]
[!CALL "WdgInstanceMacro","WdogInstance" = "'WDOG3'"!]


/**
* @brief  This define indicate that the watchdog is internal
*/
#define WDG_INTERNAL_MODULE         (0U)

/**
* @brief  This define indicate that the watchdog is external connected on SPI
*/
#define WDG_EXTERNAL_MODULE_SPI     (1U)

/**
* @brief  This define indicate that the watchdog is external connected on DIO
*/
#define WDG_EXTERNAL_MODULE_DIO     (2U)

 /**
 * @brief  This define indicate the number of HW IPs available on the Platform
 */
#define WDG_NO_OF_INSTANCES            ([!"num:i($WdgMaxNumberOfInstances)"!]U)
/**
* @brief  This variable will indicate which type of driver is in use
*/
#define WDG_TYPE ([!//
[!IF "text:match('',string(WdgExternalConfiguration/WdgExternalContainerRef))"!][!//
          WDG_INTERNAL_MODULE[!//
[!ELSEIF "text:match('Spi',substring-before(substring-after([!//
          WdgExternalConfiguration/WdgExternalContainerRef,'/'),'/'))"!][!//
          WDG_EXTERNAL_MODULE_SPI[!//
[!ELSE!][!//
          WDG_EXTERNAL_MODULE_DIO[!//
[!ENDIF!])


/**
* @brief  Compile switch to enable/disable development error detection for this module
*/
#define WDG_DEV_ERROR_DETECT   ([!IF "WdgGeneral/WdgDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/**
* @brief  Compile switch to enable/disable the validation of the configuration update by Wdg_SetMode API
*/
#define WDG_VALIDATE_CONFIG_UPDATE      (STD_ON)
/** 
* @brief  Switch to globaly enable/disable the production error reporting.
*/
#define WDG_DISABLE_DEM_REPORT_ERROR_STATUS           [!IF "$WdgDisableDemReport = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief  Compile switch to allow/forbid disabling the watchdog driver during runtime
*/
#define WDG_DISABLE_ALLOWED    ([!IF "WdgGeneral/WdgDisableAllowed"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief  Compile switch to enable/disable the version information
*/
#define WDG_VERSION_INFO_API   ([!IF "WdgGeneral/WdgVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief  This variable will indicate the index of instance 0
*/
#define WdgConf_WdgGeneral_[!"node:name(WdgGeneral/WdgIndex)"!]_U8 ((uint8)[!"num:i(WdgGeneral/WdgIndex)"!])

/**
* @brief  This variable will indicate the Wdg Initial Timeout parameter in miliseconds
*/
#define WDG_INITIAL_TIMEOUT_U16 ((uint16)[!"num:i(WdgGeneral/WdgInitialTimeout * 1000)"!])

/**
* @brief  This variable will indicate the Wdg Max Timeout parameter in miliseconds
*/
#define WDG_MAX_TIMEOUT_U16     ((uint16)[!"num:i(WdgGeneral/WdgMaxTimeout * 1000)"!])

/**
* @brief  This macro indicate Wdg Max Timeout to fix compiler warning comparision always true
*/
#define WDG_MAX_TIMEOUT_VALUE ([!"num:i(WdgGeneral/WdgMaxTimeout * 1000)"!]U)
/**
* @brief  This macro will indicate max value of 16bits integer type
*/
#define WDG_MAX_VALUE_TYPE16      (65535U)

/**
* @brief  This define indicate that the watchdog is Enable or Disable User mode support
*/
#define WDG_ENABLE_USER_MODE_SUPPORT    ([!IF "WdgGeneral/WdgEnableUserModeSupport"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


#ifdef WDG_ENABLE_USER_MODE_SUPPORT
    #if(STD_ON == WDG_ENABLE_USER_MODE_SUPPORT)
        /**
        * @brief  This define indicate that the ipv SWT is protected by register protection 
        */
        #define WDG_WDOG_REG_PROT_AVAILABLE
    #endif /* (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifdef WDG_ENABLE_USER_MODE_SUPPORT */

/**
* @brief  perform checking marco MCAL_ENABLE_USER_MODE_SUPPORT available or not.
*/
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Wdg in user mode, the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == WDG_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

[!CALL "WdgIsr","WdgWdogInstance" = "'WDOG0'"!]
[!CALL "WdgIsr","WdgWdogInstance" = "'WDOG1'"!]
[!CALL "WdgIsr","WdgWdogInstance" = "'WDOG2'"!]

[!LOOP "WdgSettingsConfig/*"!][!//
[!IF "./WdgSettingsSlow/WdgKeyedService = 'true'[!//"
   or ./WdgSettingsFast/WdgKeyedService = 'true'"!][!//

[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

/** 
* @brief  This variable will indicate RAM/ROM execution
*/
[!IF "WdgGeneral/WdgRunArea = 'ROM'"!][!//
#define WDG_ROM
[!ELSEIF "WdgGeneral/WdgRunArea = 'RAM'"!][!//
#define WDG_RAM
[!ENDIF!][!//

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
    [!CALL "WdgExportDriverConfiguration"!]
[!ENDIF!]
 

/**
* @brief Defines the use of Pre compile (PC) support
*/
              
[!INDENT "0"!][!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime' "!][!// 
  [!IF "variant:size()<=1"!][!// 
    #define WDG_PRECOMPILE_SUPPORT  (STD_ON)
  [!ELSE!][!//
    #define WDG_PRECOMPILE_SUPPORT  (STD_OFF)  
  [!ENDIF!][!// 
[!ELSE!][!//
  #define WDG_PRECOMPILE_SUPPORT  (STD_OFF)  
[!ENDIF!][!// 
[!ENDINDENT!][!//

 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                   FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* WDG_CFG_H */
/** @} */
