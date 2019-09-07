/**
*   @file    Mcu_IPW_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPW.
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


#ifndef MCU_IPW_TYPES_H
#define MCU_IPW_TYPES_H


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
#include "Mcu_PCC_Types.h"
#include "Mcu_PMC_Types.h"
#include "Mcu_RCM_Types.h"
#include "Mcu_SCG_Types.h"
#include "Mcu_SIM_Types.h"
#include "Mcu_SMC_Types.h"
#include "Mcu_CMU_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_IPW_TYPES_VENDOR_ID                       43
#define MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCU_IPW_TYPES_SW_MAJOR_VERSION                1
#define MCU_IPW_TYPES_SW_MINOR_VERSION                0
#define MCU_IPW_TYPES_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/

/* Check if current file and Mcu_PCC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_PCC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_PCC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_PCC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_PCC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_PCC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_PCC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_PCC_Types.h are different"
#endif

/* Check if current file and Mcu_PCC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_PCC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_PCC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_PCC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_PCC_Types.h are different"
#endif

/* Check if current file and Mcu_PMC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_PMC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_PMC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_PMC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_PMC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_PMC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_PMC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_PMC_Types.h are different"
#endif

/* Check if current file and Mcu_PMC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_PMC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_PMC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_PMC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_PMC_Types.h are different"
#endif

/* Check if current file and Mcu_RCM_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_RCM_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_RCM_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_RCM_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_RCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_RCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_RCM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_RCM_Types.h are different"
#endif

/* Check if current file and Mcu_RCM_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_RCM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_RCM_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_RCM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_RCM_Types.h are different"
#endif

/* Check if current file and Mcu_SCG_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SCG_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SCG_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SCG_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SCG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SCG_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SCG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SCG_Types.h are different"
#endif

/* Check if current file and Mcu_SCG_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SCG_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SCG_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SCG_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SCG_Types.h are different"
#endif

/* Check if current file and Mcu_SIM_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SIM_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SIM_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SIM_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SIM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SIM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SIM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SIM_Types.h are different"
#endif

/* Check if current file and Mcu_SIM_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SIM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SIM_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SIM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SIM_Types.h are different"
#endif

/* Check if current file and Mcu_SMC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SMC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SMC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SMC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SMC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SMC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SMC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SMC_Types.h are different"
#endif

/* Check if current file and Mcu_SMC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SMC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SMC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SMC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SMC_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Define macro for clock under Mcu control */
#define MCU_IPW_SOSC_UNDER_MCU_CONTROL              ((uint8)0x01U)
#define MCU_IPW_SOSC_NOT_UNDER_MCU_CONTROL          ((uint8)0x00U)
#define MCU_IPW_SIRC_UNDER_MCU_CONTROL              ((uint8)0x02U)
#define MCU_IPW_SIRC_NOT_UNDER_MCU_CONTROL          ((uint8)0x00U)
#define MCU_IPW_FIRC_UNDER_MCU_CONTROL              ((uint8)0x04U)
#define MCU_IPW_FIRC_NOT_UNDER_MCU_CONTROL          ((uint8)0x00U)
#define MCU_IPW_CMU_UNDER_MCU_CONTROL               ((uint8)0x08U)
#define MCU_IPW_CMU_NOT_UNDER_MCU_CONTROL           ((uint8)0x00U)
#define MCU_IPW_SPLL_UNDER_MCU_CONTROL              ((uint8)0x10U)
#define MCU_IPW_SPLL_NOT_UNDER_MCU_CONTROL          ((uint8)0x00U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Mcu_ClockNotificationType
* @details      Clock failure notification.
*               Enable/disable clock failure interrupt generated by the MCU.
*/
typedef enum
{
    MCU_CLK_NOTIF_DIS = 0x5AU,   /**< @brief Disable clock notification. */
    MCU_CLK_NOTIF_EN = 0xA5U  /**< @brief Enable clock notification. */

} Mcu_ClockNotificationType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            Mcu driver configuration structure.
* @details          Configuration for RCM reset configuration module.
*                   Configuration for power management.
*                   Configuration for System integration module (SIM).
*                   Used by "Mcu_ConfigType" structure.
*
*/
typedef struct
{
    /**< @brief Configuration for RCM (Reset Control Module) hardware IP. */
    P2CONST( Mcu_RCM_ConfigType, MCU_VAR, MCU_APPL_CONST) RCM_pResetConfig;
    /**< @brief Configuration for MC_PCU/PMU (Power Management Unit) hardware IP, part of PCU. */
    P2CONST( Mcu_PMC_ConfigType, MCU_VAR, MCU_APPL_CONST) PMC_pConfig;
    /**< @brief Configuration for SIM (System Integration Module) hardware IP. */
    P2CONST( Mcu_SIM_ConfigType, MCU_VAR, MCU_APPL_CONST) SIM_pConfig;
    /**< @brief Configuration for SMC hardware IP. */
    P2CONST( Mcu_SMC_ConfigType, MCU_VAR, MCU_APPL_CONST) SMC_pConfig;
} Mcu_HwIPsConfigType;


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Definition of a Clock configuration.
* @details          This configuration is transmitted as parameter to Mcu_Ipw_InitClock() API.
*                   Used by "Mcu_ConfigType" structure.
*
* @note             The structure Mcu_ConfigType shall provide a configurable (enable/ disable)
*                   clock failure notification if the MCU provides an interrupt for such detection.
*
*/
typedef struct
{
    /**< @brief The ID for Clock configuration. */
    VAR( Mcu_ClockType, MCU_VAR) Mcu_ClkConfigId;
    /**< @brief SIM IP Clock settings. */
    P2CONST( Mcu_SIM_ClockConfigType, MCU_VAR, MCU_APPL_CONST) SIM_pClockConfig;
    /**< @brief SCG IP settings. */
    P2CONST( Mcu_SCG_ClockConfigType, MCU_VAR, MCU_APPL_CONST) SCG_pClockConfig;
    /**< @brief PCC settings. */
    P2CONST( Mcu_PCC_ConfigType, MCU_VAR, MCU_APPL_CONST) PCC_pConfig;
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
    /**< @brief CMU settings. */
    P2CONST( Mcu_CMU_ConfigType, MCU_VAR, MCU_APPL_CONST) CMU_pConfig;
#endif
#endif
    /**< @brief Clock sources and PLLs under mcu control. */
    VAR( uint8, MCU_VAR) u8ClockSourcesControl;
} Mcu_ClockConfigType;
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

#endif /* MCU_IPW_TYPES_H */


/** @} */
