/**
*   @file    Mcu_SCG_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from MC_PCU.
*   @details Public data types exported outside of the Mcu driver.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef MCU_SCG_TYPES_H
#define MCU_SCG_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Cfg.h"
#include "Soc_Ips.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_SCG_TYPES_VENDOR_ID                        43
#define MCU_SCG_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define MCU_SCG_TYPES_AR_RELEASE_MINOR_VERSION         2
#define MCU_SCG_TYPES_AR_RELEASE_REVISION_VERSION      2
#define MCU_SCG_TYPES_SW_MAJOR_VERSION                 1
#define MCU_SCG_TYPES_SW_MINOR_VERSION                 0
#define MCU_SCG_TYPES_SW_PATCH_VERSION                 1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_SCG_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_SCG_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_SCG_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCG_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SCG_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_SCG_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_SCG_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SCG_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SCG_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SCG_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SCG_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SCG_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_SCG_Types.h and Soc_Ips.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* Define macro for system clock under Mcu control */
#define SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL   ((uint32)0xFFFFFFFFU)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief            This enumerated type contains the SPLL's possible states.
* @details          This structure is used to represent the states of SPLL.
*/
typedef enum
{
    MCU_SPLL_LOCKED = 0x33U,   /**< @brief PLL is locked. */
    MCU_SPLL_UNLOCKED = 0xCCU,   /**< @brief PLL is unlocked. */
    MCU_SPLL_STATUS_UNDEFINED = 0x5AU   /**< @brief PLL Status is unknown. */

} Mcu_SCG_PllStatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)

/**
* @brief       SCG addr and value pair.
* @details     this structure is used to represent a pair of addr and data to be written to hardware
*/
typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterAddr; /* register addr, added by hand in the code template */
   VAR( uint32, MCU_VAR) u32RegisterData; /* generated value, as it is already defined */

} Mcu_SCG_RegisterConfigType;


/**
* @brief   SCG IP configuration.
* @details This structure contains information for clock configuration for all modes, SOSC, SIRC, FIRC, ROSC, SPLL
*          The definitions for each Clock setting within the structure Mcu_ConfigType shall contain:
*          - MCU specific properties as, e.g., clock safety features and special clock distribution
*            settings
*          - PLL settings /start lock options
*          - Internal oscillator setting
*/
typedef struct
{
    VAR (uint32, MCU_VAR)  u32RunClockControlConfiguration;
    VAR (uint32, MCU_VAR)  u32VLPRClockControlConfiguration;
    VAR (uint32, MCU_VAR)  u32HSRUNClockControlConfiguration;
    VAR (uint32, MCU_VAR)  u32ClockOutConfiguration;
   /* SOSC configuration */
    CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) (*apSoscClockConfig)[];
    /* SIRC configuration */
    CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) (*apSircClockConfig)[];
    /* FIRC configuration */
    CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) (*apFircClockConfig)[];
    /* SPLL configuration */
    CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) (*apSpllClockConfig)[];
    
} Mcu_SCG_ClockConfigType;


#endif /* (MCU_INIT_CLOCK == STD_ON) */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_SCG_TYPES_H */

/** @} */
