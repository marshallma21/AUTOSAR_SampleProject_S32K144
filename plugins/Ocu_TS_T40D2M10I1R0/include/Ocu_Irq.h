/**
*   @file           Ocu_Irq.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Ocu - Ocu notifications API header.
*   @details        Ocu notifications API header.
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef OCU_IRQ_H
#define OCU_IRQ_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_Irq_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Ocu_Irq_H_REF_2
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

#include "Ocu.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Ocu_Irq.h
*/
#define OCU_IRQ_VENDOR_ID                       43
#define OCU_IRQ_MODULE_ID                       121
/* @violates @ref Ocu_Irq_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_IRQ_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Ocu_Irq_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_IRQ_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Ocu_Irq_H_REF_2 Identifier exceeds 31 chars. */
#define OCU_IRQ_AR_RELEASE_REVISION_VERSION     2
#define OCU_IRQ_SW_MAJOR_VERSION                1
#define OCU_IRQ_SW_MINOR_VERSION                0
#define OCU_IRQ_SW_PATCH_VERSION                1
/**@}*/


/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if Ocu_Irq.h and the Ocu.h header file are of the same vendor */
#if (OCU_IRQ_VENDOR_ID != OCU_VENDOR_ID)
    #error "Ocu_Irq.h and Ocu.h have different vendor ids"
#endif
/* Check if Ocu_Irq.h and the Ocu.h header file are of the same Autosar version */
#if ((OCU_IRQ_AR_RELEASE_MAJOR_VERSION    != OCU_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IRQ_AR_RELEASE_MINOR_VERSION    != OCU_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IRQ_AR_RELEASE_REVISION_VERSION != OCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Irq.h and Ocu.h are different"
#endif
/* Check if Ocu_Irq.h and the Ocu.h header file are of the same Software version */
#if ((OCU_IRQ_SW_MAJOR_VERSION != OCU_SW_MAJOR_VERSION)  || \
     (OCU_IRQ_SW_MINOR_VERSION != OCU_SW_MINOR_VERSION)  || \
     (OCU_IRQ_SW_PATCH_VERSION != OCU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Irq.h and Ocu.h are different"
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

/*===============================================================================================
*                                   STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                   GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                        FUNCTION PROTOTYPES
===============================================================================================*/
#define OCU_START_SEC_CODE
/*
* @violates @ref Ocu_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, OCU_CODE) Ocu_Notification
(
    VAR(Ocu_ChannelType, AUTOMATIC) u8HwChannel
);
#endif /* (OCU_NOTIFICATION_SUPPORTED == STD_ON) */


#define OCU_STOP_SEC_CODE
/*
* @violates @ref Ocu_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* OCU_IRQ_H */

/** @} */
