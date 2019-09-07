/**
*   @file       Ocu_Cfg.h
*   @implements Ocu_Cfg.h_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR Ocu - Ocu configuration file.
*   @details    Precompile parameters and extern configuration.
*
*   @addtogroup OCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
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

#ifndef OCU_CFG_H
#define OCU_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Ocu_Cfg_H_REF_2
* Violates MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer,
* a constant, a paranthesised expression, a type qualifier, a storage class specifier or 
* a  do-while-zero construct. 
* Macro used to define external constant in order to reduce code complexity.*
*
* @section Ocu_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
* are accessed from within a sigle function.
* These symbols are used in the entire driver.*
*
* @section Ocu_Cfg_H_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* Ocu_MemMap.h included after each section define in order to set the current memory section
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
* character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref Ocu_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Ocu_EnvCfg.h"

#include "Ocu_Types.h"
#include "Soc_Ips.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ocu_Cfg.h
*/
#define OCU_CFG_VENDOR_ID                         43
#define OCU_CFG_MODULE_ID                         121
#define OCU_CFG_AR_RELEASE_MAJOR_VERSION          4
#define OCU_CFG_AR_RELEASE_MINOR_VERSION          2
#define OCU_CFG_AR_RELEASE_REVISION_VERSION       2
#define OCU_CFG_SW_MAJOR_VERSION                  1
#define OCU_CFG_SW_MINOR_VERSION                  0
#define OCU_CFG_SW_PATCH_VERSION                  1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_CFG_VENDOR_ID != OCU_ENVCFG_VENDOR_ID)
    #error "Ocu_Cfg.h and Ocu_CfgEnv.h have different vendor ids"
#endif
/* Check if current file and Ocu_CfgEnv header file are of the same Autosar version */
#if (( OCU_CFG_AR_RELEASE_MAJOR_VERSION != OCU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( OCU_CFG_AR_RELEASE_MINOR_VERSION != OCU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     ( OCU_CFG_AR_RELEASE_REVISION_VERSION !=  OCU_ENVCFG_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Ocu_Cfg.h and Ocu_CfgEnv.h are different"
#endif
/* Check if current file and Ocu_CfgEnv header file are of the same software version */
#if ((OCU_CFG_SW_MAJOR_VERSION != OCU_ENVCFG_SW_MAJOR_VERSION) || \
     (OCU_CFG_SW_MINOR_VERSION != OCU_ENVCFG_SW_MINOR_VERSION) || \
     (OCU_CFG_SW_PATCH_VERSION != OCU_ENVCFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of Ocu_Cfg.h and Ocu_CfgEnv.h are different"
#endif

/* Check if current file and Soc_Ips.h header file are of the same Autosar version */
#if ((OCU_CFG_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_CFG_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ocu_Cfg.h and Soc_Ips.h are different"
#endif


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          API service ID
*
*/
#define OCU_PROCESSNOTIFICATION_ID    0x0AU

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          Switch to indicate that Ocu_DeInit API is supported
*
*/

#define OCU_DEINIT_API             (STD_ON)

/**
* @brief          Switch to indicate that Ocu_SetPinState API is supported
*
*/

#define OCU_SET_PIN_STATE_API    (STD_ON)

/**
* @brief        Switch to indicate that Ocu_SetPinAction API is supported
*
*/
#define OCU_SET_PIN_ACTION_API      (STD_ON)

/**
* @brief   Switch to indicate that Ocu_GetCounter API is supported
*
*/
#define OCU_GET_COUNTER_API    (STD_ON)

/**
* @brief   Switch to indicate that Ocu_GetVersionInfo API is supported
*/
#define OCU_VERSION_INFO_API              (STD_ON)

/**
* @brief      Switch to indicate that Ocu_SetAbsoluteThreshold API is supported
*
*/
#define OCU_SET_ABSOLUTE_THRESHOLD_API         (STD_ON)

/**
* @brief      Switch to indicate that Ocu_SetRelativeThreshold API is supported
*
*/
#define OCU_SET_RELATIVE_THRESHOLD_API       (STD_ON)

/**
* @brief   Switch to indicate that the notifications are supported
*
*/
#define OCU_NOTIFICATION_SUPPORTED        (STD_ON)

/**
* @brief   Switch to indicate that the down counting is supported
*
*/
#define OCU_DOWNCOUNTING_SUPPORED         (STD_OFF)

/**
* @brief   Switch for enabling the development error detection.
*
*/
#define OCU_DEV_ERROR_DETECT (STD_OFF)



/**
* @brief      Switch for enabling the dual clock functionality (Ocu_SetClockMode API)
*
*/
#define OCU_SET_CLOCK_MODE_API            (STD_OFF)

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'TRUE' the Ocu driver code can be executed from both supervisor and user mode.
*
*/  
#define OCU_ENABLE_USER_MODE_SUPPORT    (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef OCU_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running  OCU in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT*/


#define OCU_FTM_MODULE_SINGLE_INTERRUPT  (STD_OFF)

#define OCU_MAX_CHANNELS     (1U)


#define  OCU_PRECOMPILE_SUPPORT           (STD_OFF)

/**
* @brief Symbolic Names for configured channels
*/
#define OcuChannel_0         ((Ocu_ChannelType)0U)


/** 
* @brief           Symbolic Names for configured channels - ecuc 2108 compliant.
*/
#define  OcuConf_OcuConfigSet_OcuChannel_0         ((Ocu_ChannelType)0U)

/**
*   @brief ISR's configured for Ocu channels
*   @details Macros for channels used in ISR
*   @{
*/

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
#define OCU_FTM_1_CH_0_CH_1_ISR_USED
#endif

/**
* @brief hardware resource configured for Ocu channels
*
@{
*/
#define OCU_FTM_1_CH_0_USED 


/* @brief maximum of FTM modules on this platform */
#define OCU_FTM_HW_CHANNEL_MAX  (1U)

/* @brief maximum of FTM modules on this platform */
#define OCU_FTM_HW_MODULES        ((uint8)4U)

/* @brief maximum of FTM channels per module on this platform */
#define OCU_FTM_CH_PER_MODULES    ((uint8)8U)

/* @brief maximum of FTM channels on this platform */
/* @violates @ref Ocu_Cfg_H_REF_2 Function like macro. */
#define OCU_FTM_HW_CHANNELS       (uint8)(OCU_FTM_HW_MODULES * OCU_FTM_CH_PER_MODULES)

/* @brief Defines the maximum number of hw channels in the current configuration */
#define  OCU_HW_CHANNELS_NO       (OCU_FTM_HW_CHANNELS)

/* @brief Each module has 8 channel slots */
#define OCU_FTM_MODULE_CHANNELS_NO (8U)
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Ocu_Cfg_H_REF_4 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_Cfg_H_REF_1 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"

/* @violates @ref Ocu_Cfg_H_REF_2 Function like macro. */
#define OCU_CONF_PB \
 extern CONST(Ocu_ConfigType, OCU_CONST) OcuConfigSet;

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Ocu_Cfg_H_REF_4 Only preprocessor statements and comments before "#include"
* @violates @ref Ocu_Cfg_H_REF_1 precautions to prevent the contents of a header file being included twice
*/
#include "Ocu_MemMap.h"
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief      Ocu Value type (the value of the period is platform dependent and thus configurable)
* @implements Ocu_ValueType_typedef
*/
typedef uint16 Ocu_ValueType;



#ifdef __cplusplus
}
#endif

#endif    /*OCU_CFG_H*/

/** @} */

