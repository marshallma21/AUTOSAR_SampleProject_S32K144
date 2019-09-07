/**
*   @file    Ocu_Ftm_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Ocu -  eTIMER driver header file specific to OCU driver
*   @details eTIMER specific defines which need to be exported to external application
*
*   @addtogroup FTM_MODULE
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
====================================================================================================*/
/*==================================================================================================
======================================================================================================*/

#ifndef OCU_FTM_TYPES_H
#define OCU_FTM_TYPES_H
/**
*   @file    Ocu_Ftm_Types.h
*/
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
* @section [global]
*     Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
*     functions shall not be reused. The driver needs to use defines starting with letter E.
*
* @section OCU_eTIMER_TYPES_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. This is an Autosar requirement
* about the memory management.
*
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref OCU_eTIMER_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Ftm_Common_Types.h"
/** @violates @ref OCU_eTIMER_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Ocu_Cfg.h"
/** @violates @ref OCU_eTIMER_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Ocu_EnvCfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ocu_Ftm_Types.h
* @brief          Source file version information
*
*/
#define OCU_FTM_TYPES_VENDOR_ID                       43
#define OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION        2
#define OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION     2
#define OCU_FTM_TYPES_SW_MAJOR_VERSION                1
#define OCU_FTM_TYPES_SW_MINOR_VERSION                0
#define OCU_FTM_TYPES_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the header files are of the same Autosar version */
    #if ((OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Ocu_Ftm_Types.h and Ftm_Common_Types.h are different"
    #endif
#endif



#if ( OCU_FTM_TYPES_VENDOR_ID!= OCU_CFG_VENDOR_ID)
    #error "Ocu_Ftm_Types.h and Ocu_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != OCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION != OCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION != OCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocu_Ftm_Types.h and Ocu_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((OCU_FTM_TYPES_SW_MAJOR_VERSION != OCU_CFG_SW_MAJOR_VERSION) || \
     (OCU_FTM_TYPES_SW_MINOR_VERSION != OCU_CFG_SW_MINOR_VERSION) || \
     (OCU_FTM_TYPES_SW_PATCH_VERSION != OCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocu_Ftm_Types.h and Ocu_Cfg.h are different"
#endif




#if ( OCU_FTM_TYPES_VENDOR_ID!= OCU_ENVCFG_VENDOR_ID)
    #error "Ocu_Ftm_Types.h and Ocu_EnvCfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION != OCU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION != OCU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION != OCU_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocu_Ftm_Types.h and Ocu_EnvCfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((OCU_FTM_TYPES_SW_MAJOR_VERSION != OCU_ENVCFG_SW_MAJOR_VERSION) || \
     (OCU_FTM_TYPES_SW_MINOR_VERSION != OCU_ENVCFG_SW_MINOR_VERSION) || \
     (OCU_FTM_TYPES_SW_PATCH_VERSION != OCU_ENVCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ocu_Ftm_Types.h and Ocu_EnvCfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief Ftm register define used to configure counter clock source.
*/
#define OCU_FTM_OUTPUTDISABLED          ((uint8)(0U))

#define OCU_FTM_CLOCK_DIV_SHIFT         ((uint8)(2U))
#define OCU_FTM_CLOCK_DIV_MASK_U8       ((uint8)(BIT2|BIT3|BIT4))
#define OCU_FTM_CLOCK_SOURCE_SHIFT      ((uint8)(0U))
#define OCU_FTM_CLOCK_SOURCE_MASK_U8    ((uint8)(BIT0|BIT1))
#define OCU_FTM_DBG_INFO_SHIFT          ((uint8)(5U))


#define OCU_FTM_OUTPIN_USED_SHIFT       ((uint8)(0U))
#define OCU_FTM_OUTPIN_USED_MASK_U8     ((uint8)(BIT0))
#define OCU_FTM_PIN_STATE_SHIFT         ((uint8)(1U))
#define OCU_FTM_PIN_STATE_MASK_U8       ((uint8)(BIT1))
#define OCU_FTM_PIN_ACTION_SHIFT        ((uint8)(2U))
#define OCU_FTM_PIN_ACTION_MASK_U8      ((uint8)(BIT2|BIT3))

#define OCU_FTM_SC_PWMEN_SHIFT_U8       ((uint8)(16U))
/**@}*/

/*==================================================================================================
*                                            ENUMS 
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/
/**
* @brief          Ftm HW module/channel id type
*/
typedef uint8 Ocu_Ftm_ChannelType;

/**
* @brief          Ftm HW module/channel id type
*/
typedef uint8 Ocu_Ftm_ModuleType;

/**
* @brief          Ftm unified channel control register value
* 
*/
typedef uint8 Ocu_Ftm_ChannelControlType;

/**
* @brief          Ftm unified module control register value
* 
*/
typedef uint8 Ocu_Ftm_ModuleControlType;

/**
* @brief            Ftm IP channel specific configuration structure for the Ocu functionality
*/
typedef struct
{
    /** @brief Assigned Ftm channel id*/
    CONST(Ocu_Ftm_ChannelType,  OCU_CONST) u8EncodedHwChannel;
    /** @brief Compare match threshold for the current channel*/
    CONST(Ocu_ValueType,           OCU_CONST) u16DefaultThreshold;    
    /** @brief Ftm channel parameters */
    /** Bits 7        --> 1: Output Pin is Used / 0: Output Pin is not used
        Bit  6        --> Default Pin State: 0: PIN_LOW; 1: PIN_HIGH
        Bits 5 .. 4   --> Pin Action behaviour on compare match: SET_PIN_LOW; 2: SET_PIN_HIGH; 1: PIN_TOGLE; 0: OUTPUT_DISABLE
        Bits 3 .. 0   --> Reserved for future use*/
    CONST(Ocu_Ftm_ChannelControlType,  OCU_CONST) u8ChannelControlValue;

} Ocu_Ftm_ChannelConfigType;

/**
* @brief            Ftm IP module specific configuration structure for the Ocu functionality
*/
typedef struct
{
    /** @brief Assigned Ftm module id*/
    CONST(uint8 ,   OCU_CONST) u8ModuleId;
    /** @brief Assigned Ftm module id*/
    CONST(uint16 ,   OCU_CONST) u16MaxCounterValue;
    /** @brief Ftm module parameters */
    /** Bits 7 .. 6   --> Clock source
        Bits 5 .. 3   --> Normal prescale
        Bit  2 .. 1   --> Debug mode config
        Bits 0        --> Reserved for future use*/
    CONST(Ocu_Ftm_ModuleControlType,  OCU_CONST) u8ModuleControlValue;  
#if (OCU_SET_CLOCK_MODE_API == STD_ON)    
    /** @brief Ftm channel parameters */
    /** Bits 7 .. 5 --> Alternate Prescaler configuration
        Bits 4 .. 0 --> Reserved for future use*/
    CONST(uint8,  OCU_CONST) u8AltControlValue;
#endif
} Ocu_Ftm_ModuleConfigType;

/**
* @brief      Ftm IP specific configuration structure type 
*/
typedef struct
{
    /** @brief Number of Ftm channels in the Ocu configuration */
    CONST(Ocu_Ftm_ChannelType,       OCU_CONST) u8NumChannels;
    /** @brief Number of Ftm channels in the Ocu configuration */
    CONST(Ocu_Ftm_ModuleType,        OCU_CONST) u8NumModules;
    /** @brief Pointer to the configured channels for Ftm */
    CONST(Ocu_Ftm_ChannelConfigType, OCU_CONST) (*pChannelsConfig)[];
    /** @brief Pointer to the configured channels for Ftm */
    CONST(Ocu_Ftm_ModuleConfigType, OCU_CONST) (*pModulesConfig)[];     
} Ocu_Ftm_IpConfigType;



#ifdef __cplusplus
}
#endif

#endif

/** @} */
