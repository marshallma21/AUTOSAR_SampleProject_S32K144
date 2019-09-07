/**
*   @file    Mcu_SIM_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPV_SIM.
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


#ifndef MCU_SIM_TYPES_H
#define MCU_SIM_TYPES_H


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
#define MCU_SIM_TYPES_VENDOR_ID                        43
#define MCU_SIM_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define MCU_SIM_TYPES_AR_RELEASE_MINOR_VERSION         2
#define MCU_SIM_TYPES_AR_RELEASE_REVISION_VERSION      2
#define MCU_SIM_TYPES_SW_MAJOR_VERSION                 1
#define MCU_SIM_TYPES_SW_MINOR_VERSION                 0
#define MCU_SIM_TYPES_SW_PATCH_VERSION                 1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_SIM_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_SIM_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_SIM_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIM_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIM_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_SIM_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_SIM_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SIM_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SIM_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SIM_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SIM_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SIM_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_SIM_Types.h and Soc_Ips.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   SIM IP configuration.
* @details This structure contains information for Flash, ADC and FTM general options
*/
typedef struct
{
   /* Chip control configuration */
    VAR (uint32, MCU_VAR)  u32ChipControlConfiguration;
   /* LPO Clock Config */
    VAR (uint32, MCU_VAR)  u32LPOClockConfiguration;
   /* ADC configuration */
    VAR (uint32, MCU_VAR)  u32AdcOptionsConfiguration;
   /* FTMOPT0 Config */
    VAR (uint32, MCU_VAR)  u32FTMOPT0Configuration;
   /* FTMOPT1 configuration */
    VAR (uint32, MCU_VAR)  u32FTMOPT1Configuration;
   /* Flash configuration */
    VAR (uint32, MCU_VAR)  u32MiscellaneousConfiguration0;
   /* Miscellaneous Control configuration */
    VAR (uint32, MCU_VAR)  u32MiscellaneousConfiguration1;
} Mcu_SIM_ConfigType;

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            The structure contains SIM clock related configuration
* @details          Specifies the system behaviour during the selected clock configuration.
*                   Data set and configured by Mcu_InitClock call.
*/
typedef struct
{
   /* SIM_CHIPCTL Config */
    VAR (uint32, MCU_VAR)  u32ChipControlClockConfiguration;
   /* SIM_CLKDIV4 Config */
    VAR (uint32, MCU_VAR)  u32TraceClockConfiguration;
   /* Clock Gating Config */
    VAR (uint32, MCU_VAR)  u32ClockGatingConfiguration;
} Mcu_SIM_ClockConfigType;
#endif


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_SIM_TYPES_H */

/** @} */
