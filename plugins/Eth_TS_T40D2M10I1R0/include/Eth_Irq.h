/**
*   @file    Eth_Irq.h
*   @version 1.0.1
*
*   @brief AUTOSAR Eth driver interrupt handlers prototypes
*   @details Prototypes of interrupt handling routines for the Ethernet driver.
*
*   @addtogroup ETH_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ENET
*   Dependencies         : 
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
#ifndef ETH_IRQ_H
#define ETH_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_Irq_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macros is unfortunately longer than 31 characters which is required by 
* the agreed macro format and cannot be changed. 
*
* @section Eth_Irq_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Irq_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth_Ipw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_ETHIRQ                    43
#define ETH_MODULE_ID_ETHIRQ                    88
/** @violates @ref Eth_Irq_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Irq_h_REF_3 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MAJOR_VERSION_ETHIRQ     4
/** @violates @ref Eth_Irq_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Irq_h_REF_3 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MINOR_VERSION_ETHIRQ     2
/** @violates @ref Eth_Irq_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Irq_h_REF_3 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_ETHIRQ  2
#define ETH_SW_MAJOR_VERSION_ETHIRQ             1
#define ETH_SW_MINOR_VERSION_ETHIRQ             0
#define ETH_SW_PATCH_VERSION_ETHIRQ             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH configuration header file are of the same vendor */
#if (ETH_VENDOR_ID_ETHIRQ != ETH_VENDOR_ID_CFG)
#error "Eth_Irq.h and Eth_Cfg.h have different vendor ids"
#endif
/* Check if current file and ETH configuration header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_ETHIRQ    != ETH_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ETH_AR_RELEASE_MINOR_VERSION_ETHIRQ    != ETH_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ETH_AR_RELEASE_REVISION_VERSION_ETHIRQ != ETH_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Eth_Irq.h and Eth_Cfg.h are different"
#endif
/* Check if current file and ETH configuration header file are of the same software version */
#if ((ETH_SW_MAJOR_VERSION_ETHIRQ != ETH_SW_MAJOR_VERSION_CFG) || \
     (ETH_SW_MINOR_VERSION_ETHIRQ != ETH_SW_MINOR_VERSION_CFG) || \
     (ETH_SW_PATCH_VERSION_ETHIRQ != ETH_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Eth_Irq.h and ETH_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_START_SEC_CODE

/** @violates @ref Eth_Irq_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"

    extern ISR(Eth_TxIrqHdlr_0);
    extern ISR(Eth_RxIrqHdlr_0);
    /* This ISR is used only in ARM platform which doesnot have separated IRQ vectors */
#if defined(ETH_COMBINED_IRQ_SCR) && (STD_ON == ETH_COMBINED_IRQ_SCR)
    extern ISR(Eth_TxRxIrqHdlr_0);
#endif

#if (1U < ETH_MAXCTRLS_SUPPORTED)
    extern ISR(Eth_TxIrqHdlr_1);
    extern ISR(Eth_RxIrqHdlr_1);
    /* This ISR is used only in ARM platform which doesnot have separated IRQ vectors */
#if defined(ETH_COMBINED_IRQ_SCR) && (STD_ON == ETH_COMBINED_IRQ_SCR)
    extern ISR(Eth_TxRxIrqHdlr_1);
#endif

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
    extern ISR(Eth_TimerWrapIsr_1);
    extern void Eth_TimerWrapIsr_1(void);
#endif
#endif

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
    extern ISR(Eth_TimerWrapIsr_0);
    extern void Eth_TimerWrapIsr_0(void);
#endif

#define ETH_STOP_SEC_CODE

/** @violates @ref Eth_Irq_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_IRQ_H */

/** @} */
