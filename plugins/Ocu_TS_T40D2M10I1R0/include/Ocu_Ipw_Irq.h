/**
*   @file           Ocu_Ipw_Irq.h
*   
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - Ocu Ipw notifications API header.
*   @details        Ocu Ipw notifications API header.
*
*   @addtogroup     OCU_MODULE
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
=====================================================================================================*/
/*===================================================================================================
======================================================================================================*/

#ifndef OCU_IPW_IRQ_H
#define OCU_IPW_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_IPW_Notif_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Ocu_IPW_Notif_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section Ocu_IPW_Notif_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Ocu_IPW_Notif_H_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros should only extend to braced initializer,
* a constant, a paranthesised expression, a type qualifier, a storage class specifier or 
* a  do-while-zero construct. 
* Functions like macro are used to reduce code complexity.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Ocu_Ipw_Irq.h
*/
/*
* @violates @ref Ocu_IPW_Notif_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_Irq.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Ocu_Ipw_Irq.h
*/
#define OCU_IPW_IRQ_VENDOR_ID                       43
#define OCU_IPW_IRQ_MODULE_ID                       121
/* @violates @ref Ocu_IPW_Notif_H_REF_3 Identifier exceeds 31 chars. */
#define OCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Ocu_IPW_Notif_H_REF_3 Identifier exceeds 31 chars. */
#define OCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Ocu_IPW_Notif_H_REF_3 Identifier exceeds 31 chars. */
#define OCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION     2
#define OCU_IPW_IRQ_SW_MAJOR_VERSION                1
#define OCU_IPW_IRQ_SW_MINOR_VERSION                0
#define OCU_IPW_IRQ_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Ocu header file are of the same vendor */
#if (OCU_IPW_IRQ_VENDOR_ID != OCU_IRQ_VENDOR_ID)
    #error "Ocu_Ipw_Irq.h and Ocu_Irq.h have different vendor ids"
#endif
/* Check if header file and Ocu header file are of the same Autosar version */
#if ((OCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION    != OCU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION    != OCU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION != OCU_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw_Irq.h and Ocu_Irq.h are different"
#endif
/* Check if header file and Ocu_Ipw_Types header file are of the same software version */
#if ((OCU_IPW_IRQ_SW_MAJOR_VERSION != OCU_IRQ_SW_MAJOR_VERSION) || \
     (OCU_IPW_IRQ_SW_MINOR_VERSION != OCU_IRQ_SW_MINOR_VERSION) || \
     (OCU_IPW_IRQ_SW_PATCH_VERSION != OCU_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw_Irq.h and Ocu_Irq.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/* Function for notifications of FlexOcu channels implemented through macro */
/*
* @violates @ref Ocu_IPW_Notif_H_REF_2 A function should be used in preference to a 
* function-like  macro.
*/
/* @violates @ref Ocu_IPW_Notif_H_REF_3 Identifier exceeds 31 chars. */
/* @violates @ref Ocu_IPW_Notif_H_REF_4 Function like macro. */
#define Ocu_Ipw_ProcessCommonInterrupt(u8HwChannel)    Ocu_Notification((Ocu_ChannelType)(u8HwChannel))

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#ifdef __cplusplus
}
#endif

#endif /* OCU_IPW_IRQ_H */

/** @} */

