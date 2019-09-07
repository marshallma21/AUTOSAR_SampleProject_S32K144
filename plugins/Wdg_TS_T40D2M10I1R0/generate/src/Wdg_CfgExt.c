
/**
* @file    Wdg_CfgExt.c
* @version 1.0.1
* @brief   AUTOSAR Wdg - contains the data exported by the watchodg module
* @details Contains the information that will be exported by the module, as requested by Autosar.
*
* @addtogroup  Wdg
* @{
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Cfg_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Wdg_Cfg_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Wdg_Cfg_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
*
* @section Wdg_Cfg_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          The functions/variables are part of external configuration
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Wdg_CfgExt.c
*/

#include "Wdg_Channel.h"
#if (WDG_TYPE == WDG_INTERNAL_MODULE)
    #include "Reg_eSys_Wdog_defines.h"
#endif

[!INCLUDE "Wdg_VersionCheck_Src.m"!][!//
[!INCLUDE "Wdg_PluginMacros.m"!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_CfgExt.c
*/
#define WDG_VENDOR_ID_CFG_C                    43
/** @violates @ref Wdg_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define WDG_AR_RELEASE_MAJOR_VERSION_CFG_C     4
/** @violates @ref Wdg_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define WDG_AR_RELEASE_MINOR_VERSION_CFG_C     2
/** @violates @ref Wdg_Cfg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*  that 31 character significance and case sensitivity are supported for external identifiers. */
#define WDG_AR_RELEASE_REVISION_VERSION_CFG_C  2
#define WDG_SW_MAJOR_VERSION_CFG_C             1
#define WDG_SW_MINOR_VERSION_CFG_C             0
#define WDG_SW_PATCH_VERSION_CFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg header file are of the same vendor */
#if (WDG_VENDOR_ID_CFG_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_CfgExt.c and Wdg_Channel.h have different vendor ids"
#endif

/* Check if current file and Wdg header file are of the same Autosar version */
#if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG_C    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_AR_RELEASE_MINOR_VERSION_CFG_C    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_AR_RELEASE_REVISION_VERSION_CFG_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AutoSar Version Numbers of Wdg_CfgExt.c and Wdg_Channel.h are different"
#endif
/* Check if current file and Wdg header file are of the same Software version */
#if ((WDG_SW_MAJOR_VERSION_CFG_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_SW_MINOR_VERSION_CFG_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_SW_PATCH_VERSION_CFG_C != WDG_CHANNEL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_CfgExt.c and Wdg_Channel.h are different"
#endif

#if (WDG_TYPE == WDG_INTERNAL_MODULE)
    /* Check if current file and Reg_eSys_Wdog header file are of the same vendor */
    #if (WDG_VENDOR_ID_CFG_C != REG_ESYS_WDOG_DEFINES_VENDOR_ID)
        #error "Wdg_CfgExt.c and Reg_eSys_Wdog_defines.h have different vendor ids"
    #endif
    
    /* Check if current file and Reg_eSys_Wdog header file are of the same Autosar version */
    #if ((WDG_AR_RELEASE_MAJOR_VERSION_CFG_C != REG_ESYS_WDOG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_AR_RELEASE_MINOR_VERSION_CFG_C != REG_ESYS_WDOG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
         (WDG_AR_RELEASE_REVISION_VERSION_CFG_C != REG_ESYS_WDOG_DEFINES_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Wdg_CfgExt.c and Reg_eSys_Wdog_defines.h are different"
    #endif
    
    /* Check if current file and Reg_eSys_Wdog header file are of the same Software version */
    #if ((WDG_SW_MAJOR_VERSION_CFG_C != REG_ESYS_WDOG_DEFINES_SW_MAJOR_VERSION) || \
         (WDG_SW_MINOR_VERSION_CFG_C != REG_ESYS_WDOG_DEFINES_SW_MINOR_VERSION) || \
         (WDG_SW_PATCH_VERSION_CFG_C != REG_ESYS_WDOG_DEFINES_SW_PATCH_VERSION) \
        )
        #error "Software Version Numbers of Wdg_CfgExt.c and Reg_eSys_Wdog_defines.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define WDG_START_SEC_CONST_8
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_c_REF_1 MISRA 2004 Advisory Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Cfg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(uint8, WDG_CONST) Wdg_au8Index[WDG_NO_OF_INSTANCES] = 
{
    WdgConf_WdgGeneral_[!"node:name(WdgGeneral/WdgIndex)"!]_U8
};

#define WDG_STOP_SEC_CONST_8
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_c_REF_1 MISRA 2004 Advisory Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Cfg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_c_REF_1 MISRA 2004 Advisory Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Cfg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


[!INDENT "0"!][!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime' "!]
  [!IF "variant:size()<=1"!]
      [!LOOP "WdgSettingsConfig/*"!][!//
          [!VAR "configName" = "@name"!][!//
          [!IF "var:defined('postBuildVariant')"!][!//
              [!VAR "variant_name" = "variant:name()"!] 
              [!CODE!][!WS "0"!]extern CONST(Wdg_ConfigType, WDG_CONST) [!"$configName"!]_[!"$variant_name"!];[!CR!][!ENDCODE!]
          [!ELSE!][!//
              [!CODE!][!WS "0"!]extern CONST(Wdg_ConfigType, WDG_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
          [!ENDIF!]
      [!ENDLOOP!][!//
      CONSTP2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_apPBCfgVariantPredefined[WDG_NO_OF_INSTANCES]={
          [!FOR "i" = "0" TO "num:i($WdgMaxNumberOfInstances)-1"!][!//
              [!VAR "found" = "'false'"!][!//
              [!LOOP "./WdgSettingsConfig/*"!][!//
                  [!IF "./WdgInstance=concat('WDOG',$i)"!][!//
                      [!VAR "found" = "'true'"!][!//
                      [!VAR "configName" = "@name"!][!//
                  [!ENDIF!][!//
              [!ENDLOOP!][!//
                  [!IF "$found"!] 
                      [!IF "var:defined('postBuildVariant')"!][!//
                          &[!"$configName"!]_[!"$variant_name"!][!//                      
                      [!ELSE!][!// 
                          &[!"$configName"!][!//
                      [!ENDIF!][!//
                  [!ELSE!][!//
                      NULL_PTR[!//
                  [!ENDIF!][!//
                  [!IF "$i < num:i($WdgMaxNumberOfInstances)-1"!],[!ENDIF!]
          [!ENDFOR!][!//
          };
  [!ENDIF!]
[!ENDIF!]
[!ENDINDENT!][!//

 
#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Cfg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CONST_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Cfg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Disable_Rejected = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_DISABLE_REJECTED)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Mode_Failed = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_MODE_FAILED)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_MODE_FAILED)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_MODE_FAILED)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Corrupt_Config = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_CORRUPT_CONFIG)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_CORRUPT_CONFIG)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_CORRUPT_CONFIG)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Forbidden_Invocation = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_FORBIDDEN_INVOCATION)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_FORBIDDEN_INVOCATION)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_FORBIDDEN_INVOCATION)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Invalid_Call = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_INVALID_CALL)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_INVALID_CALL)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_INVALID_CALL)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) WDG_E_Unlocked = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_UNLOCKED)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_UNLOCKED)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_UNLOCKED)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(WdgDemEventParameterRefs)"!][!//
[!IF "WdgGeneral/NonAutosar/WdgDisableDemReportErrorStatus = 'false'"!][!//
/** @violates @ref Wdg_Cfg_c_REF_4 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(Mcal_DemErrorType, WDG_CONST) Wdg_E_Invalid_Parameter = 
{
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_INVALID_PARAMETER)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(WdgDemEventParameterRefs/WDG_E_INVALID_PARAMETER)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(WdgDemEventParameterRefs/WDG_E_INVALID_PARAMETER)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//

#define WDG_STOP_SEC_CONST_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Cfg_c_REF_1 MISRA 2004 Advisory Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Cfg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                     GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef __cplusplus
}
#endif

/** @} */
