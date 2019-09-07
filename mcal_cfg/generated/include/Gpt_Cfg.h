/**
*   @file    Gpt_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt  - Gpt driver configuration header file.
*   @details GPT driver header file, containing C and XPath constructs for generating Gpt
*            configuration header file.
*
*   @addtogroup GPT_MODULE
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

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, Braces not used for some macros
* Braces are not used for macros which expand to multiple statements separated by ";" character.
*
* @section GPT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Some global variables used by a single driver function shall be
* exported to user application.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref GPT_CFG_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Mcal.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_CFG                    43
#define GPT_AR_RELEASE_MAJOR_VERSION_CFG     4
#define GPT_AR_RELEASE_MINOR_VERSION_CFG     2
#define GPT_AR_RELEASE_REVISION_VERSION_CFG  2
#define GPT_SW_MAJOR_VERSION_CFG             1
#define GPT_SW_MINOR_VERSION_CFG             0
#define GPT_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Mcal.h file are of the same Autosar version */
    #if ((GPT_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Cfg.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Gpt Dev error detect switch
*
*/
#define GPT_DEV_ERROR_DETECT (STD_ON)

/**
* @brief Report Wakeup Source switch
*/
#define GPT_REPORT_WAKEUP_SOURCE (STD_ON)

/**
* @brief GPT_VERSION_INFO_API switch
*
*/
#define GPT_VERSION_INFO_API (STD_ON)

/**
* @brief GPT_DEINIT_API switch
*
*/
#define GPT_DEINIT_API (STD_ON)

/**
* @brief GPT_TIME_ELAPSED_API switch
*
*/
#define GPT_TIME_ELAPSED_API (STD_ON)

/**
* @brief GPT_TIME_REMAINING_API switch
*
*/
#define GPT_TIME_REMAINING_API (STD_ON)

/**
* @brief GPT_ENABLE_DISABLE_NOTIFICATION_API switch
*
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)

/**
* @brief GPT_WAKEUP_FUNCTIONALITY_API switch
*
*/
#define GPT_WAKEUP_FUNCTIONALITY_API (STD_ON)

/**
* @brief GPT_PREDEFTIMER_FUNCTIONALITY_API switch
*
*/
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_OFF)

/**
* @brief Enable/disable support for changing timeout value during timer running
*
*/
#define GPT_CHANGE_NEXT_TIMEOUT_VALUE            (STD_OFF)

/**
* @brief Enable/disable API for Dual Mode support.
*/
#define GPT_SET_CLOCK_MODE           (STD_OFF)

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*
*/
#define GPT_USER_MODE_SOFT_LOCKING       (STD_OFF)

/**
*   @brief   Enables or disables support external trigger sources
*
*/
#define GPT_LPIT_ENABLE_EXT_TRIGGERS     (STD_OFF)








#define GPT_ENABLE_USER_MODE_SUPPORT    (STD_OFF)



#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef GPT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == GPT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef GPT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */





/**
* @brief These defines indicate that at least one chennel from each module is used in all configurations.
*
*/
#define GPT_SRTC_USED (STD_OFF)

#define GPT_LPTMR_USED (STD_OFF)

#define GPT_LPIT_USED (STD_ON)

#define GPT_FTM_USED (STD_OFF)

/**
* @{
* @brief Symbolic names of channels
*/

/** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_INTOS  (1U)


/** @violates @ref GPT_CFG_H_REF_2 Identifier clash */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_WDG  (0U)


/*@}*/

/**
* @brief This define is a reserved logical channel name representing a not existing/configured
*        hardware channel.
*
*/
#define GPT_CHN_NOT_USED    (255U)

/**
* @brief   Single Interrupt.
*
*/
#define GPT_FTM_MODULE_SINGLE_INTERRUPT (STD_OFF)
#define GPT_LPIT_MODULE_SINGLE_INTERRUPT (STD_OFF)


/**
* @{
* @brief IRQ Defines
*/

#define GPT_LPIT_0_CH_0_ISR_USED

#define GPT_LPIT_0_CH_1_ISR_USED









/**
* @{
* @brief Defines for HW IPs will be used by GPT driver
*/
#define GPT_LPIT_0_USED

#define GPT_PRECOMPILE_SUPPORT  (STD_OFF)

/**
* @brief The maxiumum number of HW channels. This is used to allocate memory space for channel runtime info.
*/
#define GPT_HW_CHANNEL_NUM   (2U)



/**
* @brief The number of LPIT HW channels
*/


/* The real number of channels in LPIT_0 */
#define GPT_LPIT_0_NUM_CHANNEL_U8 (4U)
/* The maximum number of channels per module for LPIT */
#define GPT_LPIT_CHANNELS_PER_MODULE_U8 (4U)

#define GPT_LPIT_MODULES_NUM      (1U)

#define GPT_LPIT_CHAN_NUM         (4U)



/* The real number of channels in LPTMR_0 */
#define GPT_LPTMR_0_NUM_CHANNEL_U8 (1U)
/* The maximum number of channels per module for LPTMR */
#define GPT_LPTMR_CHANNELS_PER_MODULE_U8 (1U)

#define GPT_LPTMR_MODULES_NUM      (1U)

#define GPT_LPTMR_CHAN_NUM         (1U)




/* The real number of channels in SRTC_0 */
#define GPT_SRTC_0_NUM_CHANNEL_U8 (1U)
/* The maximum number of channels per module for SRTC */
#define GPT_SRTC_CHANNELS_PER_MODULE_U8 (1U)

#define GPT_SRTC_MODULES_NUM      (1U)

#define GPT_SRTC_CHAN_NUM         (1U)




/* The real number of channels in FTM_0 */
#define GPT_FTM_0_NUM_CHANNEL_U8 (8U)
/* The real number of channels in FTM_1 */
#define GPT_FTM_1_NUM_CHANNEL_U8 (8U)
/* The real number of channels in FTM_2 */
#define GPT_FTM_2_NUM_CHANNEL_U8 (8U)
/* The real number of channels in FTM_3 */
#define GPT_FTM_3_NUM_CHANNEL_U8 (8U)
/* The maximum number of channels per module for FTM */
#define GPT_FTM_CHANNELS_PER_MODULE_U8 (8U)


/**
* @brief The number of Ftm HW modules
*/
#define GPT_FTM_MODULES_NUM_U8   (4U)

/**
* @brief The number of Ftm HW channels
*/
#define GPT_FTM_MODULE_CHAN_NUM_U8      (32U)

/**
* @brief The total number of indexes used by the hardware to logic channel map
*/
#define GPT_CHANNEL_IDX_NUM    (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_LPIT_CHAN_NUM + GPT_LPTMR_CHAN_NUM + GPT_SRTC_CHAN_NUM)

/**
@{
@brief ID for peripheral. This ID need to match the order in the hardware to logic channels mapping table
*      because it is used as a base index.
*/
#define GPT_FTM_MODULE                         0U                                                           /** @brief index where the FTM channels start*/
#define GPT_LPIT_MODULE                       (GPT_FTM_MODULE_CHAN_NUM_U8)                                            /** @brief index where the LPIT channels start*/
#define GPT_LPTMR_MODULE                      (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_LPIT_CHAN_NUM)                        /** @brief index where the LPTMR channels start*/
#define GPT_SRTC_MODULE                       (GPT_FTM_MODULE_CHAN_NUM_U8 + GPT_LPIT_CHAN_NUM + GPT_LPTMR_CHAN_NUM)   /** @brief index where the SRTC channels start*/
/** @} */

#define GPT_HW_PREDEFTIMER_NUM                              (4U) /** @brief number for channels predef timer supported by the platform */

/**
*   @brief export configuration Gpt driver
*/




    
/**
 * @violates @ref GPT_CFG_H_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to...
 */
#define GPT_CONF_PB \
 extern CONST(Gpt_ConfigType, GPT_CONST) GptChannelConfigSet;



/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief Predef Timer type. Indicates the type of predef timer.
* @implements   Gpt_PredefTimerType_enumeration
*/
typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT = 0x0U,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;
#endif
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* GPT_CFG_H */

/** @} */
