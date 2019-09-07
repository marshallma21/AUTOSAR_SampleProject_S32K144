/**
*   @file    Adc_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Module configuration interface for Adc driver.
*   @details Contains the module configuration interface for Adc driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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

#ifndef ADC_CFG_H
#define ADC_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Cfg_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function shall be used in preference to a function-like macro.
* Middle layer between AUTOSAR and hardware needs a way to map HLD
* functions to IPV functions.
*
* @section Adc_cfg_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Adc_cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_cfg_h_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_cfg_h_REF_5
* Violates MISRA 2004 Required Rule 8.12,
* When an array is declared with external linkage, its size shall be stated explicitly
* or defined implicitly by initialisation.
* The size of the array is defiend at configuration time
*
* @section Adc_cfg_h_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_EnvCfg.h"
#include "Adc_CfgDefines.h"
#include "Adc_Adc12bsarv2_CfgEx.h"
/** @violates @ref Adc_cfg_h_REF_3 Repeated include file */
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_CFG                       43
/** @violates @ref Adc_cfg_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MAJOR_VERSION_CFG        4
/** @violates @ref Adc_cfg_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MINOR_VERSION_CFG        2
/** @violates @ref Adc_cfg_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_CFG     2
#define ADC_SW_MAJOR_VERSION_CFG                1
#define ADC_SW_MINOR_VERSION_CFG                0
#define ADC_SW_PATCH_VERSION_CFG                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/** @violates @ref Adc_cfg_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION) \
     )
    #error "AutoSar Version Numbers of Adc_Cfg.h and Dem.h are different"
 #endif
 #endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Adc_CfgDefines header file are of the same vendor */
#if (ADC_VENDOR_ID_CFG != ADC_VENDOR_ID_CFG_DEFINES)
    #error "Adc_Cfg.h and Adc_CfgDefines.h have different vendor ids"
#endif

/* Check if header file and Adc_CfgDefines header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_CFG != ADC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_CFG != ADC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_CFG != ADC_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Adc_Cfg.h and Adc_CfgDefines.h are different"
#endif

/* Check if header file and Adc Cfg header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_CFG != ADC_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (ADC_SW_MINOR_VERSION_CFG != ADC_SW_MINOR_VERSION_CFG_DEFINES) || \
     (ADC_SW_PATCH_VERSION_CFG != ADC_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Adc_Cfg.h and Adc_CfgDefines.h are different"
#endif

/* Check if header file and Adc_Adc12bsarv2_CfgEx header file are of the same vendor */
#if (ADC_VENDOR_ID_CFG != ADC_VENDOR_ID_ADC12BSARV2_CFGEX)
    #error "Adc_Cfg.h and Adc_Adc12bsarv2_CfgEx.h have different vendor ids"
#endif

/* Check if header file and Adc_Adc12bsarv2_CfgEx header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_CFG != ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_AR_RELEASE_MINOR_VERSION_CFG != ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_AR_RELEASE_REVISION_VERSION_CFG != ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_CFGEX) \
    )
    #error "AutoSar Version Numbers of Adc_Cfg.h and Adc_Adc12bsarv2_CfgEx.h are different"
#endif

/* Check if header file and Adc_Adc12bsarv2_CfgEx header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_CFG != ADC_SW_MAJOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_SW_MINOR_VERSION_CFG != ADC_SW_MINOR_VERSION_ADC12BSARV2_CFGEX) || \
     (ADC_SW_PATCH_VERSION_CFG != ADC_SW_PATCH_VERSION_ADC12BSARV2_CFGEX) \
    )
    #error "Software Version Numbers of Adc_Cfg.h and Adc_Adc12bsarv2_CfgEx.h are different"
#endif

/* Check if header file and Adc_EnvCfg header file are of the same vendor */
#if (ADC_VENDOR_ID_CFG != ADC_VENDOR_ID_ENVCFG)
    #error "Adc_Cfg.h and Adc_EnvCfg.h have different vendor ids"
#endif

/* Check if header file and Adc_EnvCfg header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_CFG != ADC_AR_RELEASE_MAJOR_VERSION_ENVCFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_CFG != ADC_AR_RELEASE_MINOR_VERSION_ENVCFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_CFG != ADC_AR_RELEASE_REVISION_VERSION_ENVCFG) \
    )
    #error "AutoSar Version Numbers of Adc_Cfg.h and Adc_EnvCfg.h are different"
#endif

/* Check if header file and Adc Cfg header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_CFG != ADC_SW_MAJOR_VERSION_ENVCFG) || \
     (ADC_SW_MINOR_VERSION_CFG != ADC_SW_MINOR_VERSION_ENVCFG) || \
     (ADC_SW_PATCH_VERSION_CFG != ADC_SW_PATCH_VERSION_ENVCFG) \
    )
    #error "Software Version Numbers of Adc_Cfg.h and Adc_EnvCfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** 
* @brief           Number of channels configured for each group.
*/

#define ADC_CFGSET_GROUP_0_CHANNELS      1
#define ADC_CFGSET_GROUP_1_CHANNELS      1
#define ADC_CFGSET_GROUP_2_CHANNELS      1
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Structure for Configuration data.
* @details        Data structure containing the set of configuration parameters required
*                 for initializing the ADC Driver and ADC HW Unit(s).
* @api
* @implements     Adc_ConfigType_struct
*/
typedef struct
{
  /** @brief Hw unit configurations */
  P2CONST(Adc_Adc12bsarv2_HwUnitConfigurationType, ADC_VAR, ADC_APPL_CONST) pAdc;
  /** @brief Group configurations */
  P2CONST(Adc_GroupConfigurationType, ADC_VAR, ADC_APPL_CONST) pGroups;
  /** @brief Channel configurations */
  P2P2CONST(Adc_Adc12bsarv2_ChannelConfigurationType, ADC_VAR, ADC_APPL_CONST) pChannels;
  /** @brief Total number of groups */
  VAR(Adc_GroupType, ADC_VAR) GroupCount;
  /** @brief Miscellaneous configuration parameters */
  CONST(Adc_Adc12bsarv2_MultiConfigType, ADC_CONST) Misc;
} Adc_ConfigType;
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/**  @violates @ref Adc_cfg_h_REF_4 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

    
/** @violates @ref Adc_cfg_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(Adc_ConfigType, ADC_CONST) AdcConfigSet;

    
#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**  @violates @ref Adc_cfg_h_REF_4 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/** @violates @ref Adc_cfg_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_cfg_h_REF_4 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/** @violates @ref Adc_cfg_h_REF_5 Missing array size in extern declaration */
/** @violates @ref Adc_cfg_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern P2CONST(Adc_ChannelLimitCheckingType, ADC_VAR, ADC_APPL_CONST) Adc_aChannelsLimitCheckingCfg[];    

/** @violates @ref Adc_cfg_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_cfg_h_REF_4 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ADC_CFG_H */

/** @} */
