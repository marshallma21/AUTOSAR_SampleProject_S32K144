/**
*   @file           Pwm_Ftm_Types.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Ftm data types header file.
*   @details        Ftm defines, types used by PWM driver.
*
*   @addtogroup     PWM_MODULE
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

#ifndef PWM_FTM_TYPES_H
#define PWM_FTM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Ftm_Types_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_Ftm_Types_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

/** @violates @ref Pwm_Ftm_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Pwm_Cfg.h"


/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ftm_Types.h
*/

#define PWM_FTM_TYPES_VENDOR_ID                       43
#define PWM_FTM_TYPES_MODULE_ID                       121
/* @violates @ref Pwm_Ftm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_TYPES_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Pwm_Ftm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_TYPES_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Pwm_Ftm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_TYPES_AR_RELEASE_REVISION_VERSION     2
/* @violates @ref Pwm_Ftm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_TYPES_SW_MAJOR_VERSION                1
/* @violates @ref Pwm_Ftm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_TYPES_SW_MINOR_VERSION                0
/* @violates @ref Pwm_Ftm_Types_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_TYPES_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Pwm_Cfg.h header file are of the same vendor */
#if (PWM_FTM_TYPES_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm_Ftm_Types.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if header file and Pwm_Cfg.h header file are of the same Autosar version */
#if ((PWM_FTM_TYPES_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_TYPES_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_TYPES_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm_Types.h and Pwm_Cfg.h are different"
#endif
/* Check if header file and Pwm_Cfg.h header file are of the same software version */
#if ((PWM_FTM_TYPES_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_FTM_TYPES_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_FTM_TYPES_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm_Types.h and Pwm_Cfg.h are different"
#endif


/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/


/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/**
* @brief      Pwm signal alignment. This parameter is applied at a pwm submodule level and is 
*             available only for Ftm
* @details    This field will vary the alignment of the output signals for the specified channel
*             If the selected mode is PWM_EDGE_ALIGNED the signals will be aligned at the starting 
*             edge of the pwm period
*             If the selected mode is PWM_CENTER_ALIGNED the signals will be aligned arround the 
*             midle of the pwm period. 
*             The on-time and off-time will be divided such as the output signal will be simetric 
*             around the middle of the pwm period.
*             Seting this option will allow only output A and B for a selected Ftm sub-module
*/
typedef enum
{
    /** @brief One signal is generated that is aligned at the starting edge of the pwm period.
    This is the default generation mode */
    PWM_EDGE_ALIGNED = 0, 
    /** @brief One signal is generated that is aligned around the middle of the pwm period */
    PWM_CENTER_ALIGNED,   
    /** @brief Two channels are combined into two signals with the same polarity but can be phase shifted from the master channel by a configurable deadtime; first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal. */
    PWM_COMBINE_SYNCED,
    /** @brief Two channels are combined into two signals with the same polarity which can be phase shifted from the master channel by a configurable deadtime; first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal. */
    PWM_COMBINE_COMPL,    
    /** @brief Two channels are paired into one output signal; first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal.*/
    PWM_PHASE_SHIFT_SINGLE,
    /** @brief Two channels are paired into two-synced output signals; for both signals the first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal.*/
    PWM_PHASE_SHIFTED_SYNCED,
    /** @brief Two channels are paired into two-complementary output signals; for both signals the first channel defines the leading edge of the signal, second channel defines the trailing edge of the signal.*/
    PWM_PHASE_SHIFTED_COMPLEMENTARY
}Pwm_AlignmentType;

typedef enum
{
    /** @brief The signals are updated synchronous. 
    This is the default generation mode */
    PWM_UPDATE_SYNCHRONOUS = 0, 
    /** @brief The signals are updated asynchronous */
    PWM_UPDATE_ASYNCHRONOUS   
}Pwm_DataUdateType;

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/**
* @brief      Ftm HW channel type
*/
typedef uint8 Pwm_Ftm_ChannelType;

/**
* @brief      Ftm HW module type ID
*/
typedef uint8 Pwm_Ftm_ModuleType;


/**
* @brief      Ftm Defines of the Ftm hw modules
*/
#define PWM_FTM_0    ((Pwm_Ftm_ModuleType) 0)
#define PWM_FTM_1    ((Pwm_Ftm_ModuleType) 1)
#define PWM_FTM_2    ((Pwm_Ftm_ModuleType) 2)
#define PWM_FTM_3    ((Pwm_Ftm_ModuleType) 3)
#define PWM_FTM_4    ((Pwm_Ftm_ModuleType) 4)
#define PWM_FTM_5    ((Pwm_Ftm_ModuleType) 5)
#define PWM_FTM_6    ((Pwm_Ftm_ModuleType) 6)
#define PWM_FTM_7    ((Pwm_Ftm_ModuleType) 7)


/**
* @brief      Ftm Channel notification state type ID
*/
typedef uint8 Pwm_Ftm_ChannelNotifType;


/**
* @brief      Ftm TOF IRQ state type ID
*/
typedef uint8 Pwm_Ftm_EdgeStateType;

/**
* @brief      Fault channel notification typedef
*/
typedef void (*Pwm_Ftm_FaultNotifyType)(uint8 u8ModuleId, uint8 u8FaultChannel);



/**
* @brief Ftm IP specific channel configuration structure type
*/
typedef struct
{
    /** @brief Pwm signal polarity:   High or low */
    CONST(Pwm_OutputStateType,     PWM_CONST) ePwmPolarity;
    /** @brief Pwm signal idle state: High or low */
    CONST(Pwm_OutputStateType,     PWM_CONST) ePwmIdleState;
    /** @brief Default value for duty cycle: [0-0x8000] (0-100%) */
    CONST(uint16,              PWM_CONST)    u16PwmDefaultDutyCycle; 
    /** @brief Ftm channel id*/
    CONST(Pwm_Ftm_ChannelType, PWM_CONST)    nHwChannelId;
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    /** @brief Default value for phase shift: [0-0xFFFE] */
    CONST(uint16,              PWM_CONST)    u16PhaseShiftValue;
#endif
    /** @brief channel alignment type */
    CONST(Pwm_AlignmentType, PWM_CONST)   eAlingnment;

} Pwm_Ftm_ChannelConfigType;


/**
* @brief Ftm IP specific common to all Ftm channels configuration structure type
*/
typedef struct
{
    /** @brief configuration register value */
    CONST(uint32, PWM_CONST)    u32RegConf;
    /** @brief status and control register value */
    CONST(uint32, PWM_CONST)    u32RegSc;
#if (PWM_SET_CLOCK_MODE_API == STD_ON) 
    /** @brief alternate status and control register value */
    CONST(uint32, PWM_CONST)    u32AlternateRegSc;
#endif
    /** @brief synchronize register value */
    CONST(uint8, PWM_CONST)     u8RegSync;
    /** @brief mode selection register value */
    CONST(uint32, PWM_CONST)    u32RegMode;
    /** @brief deadtime register value */
    CONST(uint32, PWM_CONST)    u32RegDeadtime;
    /** @brief channel combine register value */
    CONST(uint32, PWM_CONST)    u32RegCombine;
    /** @brief Id value of the configured FTM module */
    CONST(uint8, PWM_CONST)     u8FtmHwModuleId;
    /** @brief default period (mod) register value */
    CONST(uint16, PWM_CONST)    u16RegModVal;
#if (PWM_FAULT_SUPPORTED == STD_ON)    
    /** @brief fault control register value */
    CONST(uint32, PWM_CONST)    u32RegFctrl;
    /** @brief fault polarity register value */
    CONST(uint32, PWM_CONST)    u32RegFltpol;
    /** @brief Pointer to fault notification function */
    CONST(Pwm_Ftm_FaultNotifyType,PWM_CONST)    pfFaultNotification[PWM_FTM_MODULE_FAULT_NO];
#endif /* (PWM_FAULT_SUPPORTED == STD_ON) */
#ifdef PWM_FTM_ENABLE_EXT_TRIGGERS
#if (PWM_FTM_ENABLE_EXT_TRIGGERS  == STD_ON) 
    /** @brief alternate status and control register value */
    CONST(uint32, PWM_CONST)    u32RegExtTrigg;
#endif
#endif

} Pwm_Ftm_ModuleConfigType;


/**
* @brief      Ftm IP specific channels and module configuration structure type
*/
typedef struct
{
    /** @brief Number of Ftm channels in eacb module of the current the Pwm configuration */
    CONST(Pwm_Ftm_ChannelType,         PWM_CONST) nNumChannels;
    
    /** @brief Number of Ftm modules in the Pwm configuration */
    CONST(Pwm_Ftm_ModuleType,         PWM_CONST) nNumModules;
    
    
    /** @brief Pointer to the configured channels for Ftm */
    CONST(Pwm_Ftm_ChannelConfigType,   PWM_CONST) (*pChannelsConfig)[]; 
  
    /** @brief Pointer to the configured channels for the Ftm Module */
    CONST(Pwm_Ftm_ModuleConfigType,    PWM_CONST) (*pModulesConfig)[];   
} Pwm_Ftm_IpConfigType;




/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/



/** @brief      Defines that specifies the Module types used in Pwm_Ftm_ModuleType type
*/
#define PWM_NO_EDGE                  ((Pwm_Ftm_EdgeStateType)0U)
#define PWM_CHF_IRQ_EDGE             ((Pwm_Ftm_EdgeStateType)1U)
#define PWM_TOF_IRQ_EDGE             ((Pwm_Ftm_EdgeStateType)2U)
#define PWM_TOF_IRQ_NO_EDGE_NOTIF    ((Pwm_Ftm_EdgeStateType)4U)
#define PWM_TOF_IRQ_FAULT_IDLE_STATE ((Pwm_Ftm_EdgeStateType)8U)
#define PWM_CHANNEL_NOT_USED         ((Pwm_Ftm_EdgeStateType)255U)



/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PWM_FTM_TYPES_H */

/** @} */
