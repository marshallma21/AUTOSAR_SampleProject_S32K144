/**
*   @file    Wdg_Irq.h
*   @version 1.0.1
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) interrupt routine
*   @details Contains information about the interrupt routine
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Wdog
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

#ifndef WDG_IRQ_H
#define WDG_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Irq_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/**
* @file           Wdg_Irq.h
*/

/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Irq_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Irq.h
*/
#define WDG_IRQ_VENDOR_ID                       43
#define WDG_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define WDG_IRQ_AR_RELEASE_MINOR_VERSION        2
#define WDG_IRQ_AR_RELEASE_REVISION_VERSION     2
#define WDG_IRQ_SW_MAJOR_VERSION                1
#define WDG_IRQ_SW_MINOR_VERSION                0
#define WDG_IRQ_SW_PATCH_VERSION                1

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_IRQ_VENDOR_ID != WDG_VENDOR_ID_CFG)
    #error "Wdg_Irq.h and Wdg_Cfg.h have different vendor ids"
#endif

/* Check if current file and WDG configuration header file are of the same Autosar version */
#if ((WDG_IRQ_AR_RELEASE_MAJOR_VERSION    != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_IRQ_AR_RELEASE_MINOR_VERSION    != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_IRQ_AR_RELEASE_REVISION_VERSION != WDG_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Wdg_Irq.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and WDG configuration header file are of the same software version */
#if ((WDG_IRQ_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_IRQ_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_IRQ_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Wdg_Irq.h and Wdg_Cfg.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Irq_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


/* Process the wdg interrupt */
FUNC(void, WDG_CODE) Wdg_ProcessInterrupt( CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Irq_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* WDG_IRQ_H */

/** @} */
