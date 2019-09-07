/**
*   @file    Mcu_SMC_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPV_SMC.
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


#ifndef MCU_SMC_TYPES_H
#define MCU_SMC_TYPES_H


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
#define MCU_SMC_TYPES_VENDOR_ID                        43
#define MCU_SMC_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define MCU_SMC_TYPES_AR_RELEASE_MINOR_VERSION         2
#define MCU_SMC_TYPES_AR_RELEASE_REVISION_VERSION      2
#define MCU_SMC_TYPES_SW_MAJOR_VERSION                 1
#define MCU_SMC_TYPES_SW_MINOR_VERSION                 0
#define MCU_SMC_TYPES_SW_PATCH_VERSION                 1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_SMC_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_SMC_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_SMC_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SMC_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SMC_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_SMC_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_SMC_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SMC_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SMC_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SMC_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SMC_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SMC_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_SMC_Types.h and Soc_Ips.h are different"
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
* @brief            Power Modes encoding.
* @details          Supported power modes for SMC hw IP.
*/
typedef enum
{
    MCU_RUN_MODE    = 0x00U,   /**< @brief Run Mode. */
    MCU_HSRUN_MODE  = 0x01U,   /**< @brief High Speed Mode. */
    MCU_VLPR_MODE   = 0x02U,   /**< @brief Very Low Power Run Mode. */
    MCU_VLPS_MODE   = 0x03U,   /**< @brief Very Low Power Stop Mode. */
    MCU_STOP1_MODE  = 0x04U,   /**< @brief Stop 1 Mode. */
    MCU_STOP2_MODE  = 0x05U,   /**< @brief Stop 2 Mode. */
} Mcu_PowerModeType;

/**
* @brief   SMC IP configuration.
* @details This structure contains information for allowed modes
*/
typedef struct
{
   /* Allowed modes */
    VAR (uint32, MCU_VAR)  u32AllowedModes;
} Mcu_SMC_ConfigType;


/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
typedef struct
{
    /**< @brief The ID for Power Mode configuration. */
    VAR( Mcu_ModeType, MCU_VAR) Mcu_ModeConfigId;
   /**< @brief Power modes control configuration */
    VAR (Mcu_PowerModeType, MCU_VAR)  u32PowerMode;
} Mcu_ModeConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_SMC_TYPES_H */

/** @} */
