/**
*   @file    Adc_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Pre-Compile configurations for ADC driver.
*   @details Pre-Compile configuration file for ADC driver.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement.
*
* @section Adc_Cfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_Cfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Cfg_c_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Cfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required.
* This violation is due to Autosar files and structures definitions.
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
#include "Adc.h"
/** @violates @ref Adc_Cfg_c_REF_4 Repeated include file */
#include "Adc_Reg_eSys_Adc12bsarv2.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_CFG_C                    43
/**
* @violates @ref Adc_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_CFG_C     4
/**
* @violates @ref Adc_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_ERLEASE_MINOR_VERSION_CFG_C     2
/**
* @violates @ref Adc_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_CFG_C  2
#define ADC_SW_MAJOR_VERSION_CFG_C             1
#define ADC_SW_MINOR_VERSION_CFG_C             0
#define ADC_SW_PATCH_VERSION_CFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_CFG_C != ADC_VENDOR_ID)
    #error "Adc_Cfg.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_CFG_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_ERLEASE_MINOR_VERSION_CFG_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_CFG_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Cfg.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_CFG_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_CFG_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_CFG_C != ADC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Cfg.c and Adc.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same vendor */
#if (ADC_VENDOR_ID_CFG_C != ADC_VENDOR_ID_REG)
    #error "Adc_Cfg.c and Adc_Reg_eSys_Adc12bsarv2.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_CFG_C != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_ERLEASE_MINOR_VERSION_CFG_C != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_CFG_C != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Cfg.c and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_CFG_C != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_CFG_C != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_CFG_C != ADC_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Adc_Cfg.c and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
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
#define ADC_START_SEC_CONST_UNSPECIFIED
/** @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Cfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of channels limit checking on ADC logical unit 0.
*/
static CONST(Adc_ChannelLimitCheckingType, ADC_CONST) Adc_aChannelsLimitCheckingCfg_0[] =
{
    /**< @brief ADC logical Id 0  --  Channel logical Id 0 */
    {
        /**< @brief limit check disabled */
        /**< @brief range for limit check */
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
        /**< @brief high limit value */
        (Adc_ValueGroupType)0,
        /**< @brief low limit value */
        (Adc_ValueGroupType)0
    },
    /**< @brief ADC logical Id 0  --  Channel logical Id 1 */
    {
        /**< @brief limit check disabled */
        /**< @brief range for limit check */
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
        /**< @brief high limit value */
        (Adc_ValueGroupType)0,
        /**< @brief low limit value */
        (Adc_ValueGroupType)0
    },
    /**< @brief ADC logical Id 0  --  Channel logical Id 2 */
    {
        /**< @brief limit check disabled */
        /**< @brief range for limit check */
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
        /**< @brief high limit value */
        (Adc_ValueGroupType)0,
        /**< @brief low limit value */
        (Adc_ValueGroupType)0
    }
};
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */



#define ADC_STOP_SEC_CONST_UNSPECIFIED
/** @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Cfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @violates @ref Adc_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Cfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of channels' limit checking pointer structure.
*
*/
P2CONST(Adc_ChannelLimitCheckingType, ADC_VAR, ADC_APPL_CONST) Adc_aChannelsLimitCheckingCfg[] =
{
    Adc_aChannelsLimitCheckingCfg_0
};
#endif


/**
* @violates @ref Adc_Cfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_Cfg_c_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Cfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */

