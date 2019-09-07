/**
*   @file           Mcl_IPW_Notif.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Mcl - Mcl IPW notifications API header.
*   @details        Mcl IPW notifications API header.
*
*   @addtogroup     MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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

#ifndef MCL_IPW_NOTIF_H
#define MCL_IPW_NOTIF_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_IPW_Notif_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Mcl_IPW_Notif.h
*/
#include "Mcl_Notif.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Mcl_IPW_Notif.h
*/
#define MCL_IPW_NOTIF_VENDOR_ID                       43
#define MCL_IPW_NOTIF_MODULE_ID                       255
#define MCL_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION        4
#define MCL_IPW_NOTIF_AR_RELEASE_MINOR_VERSION        2
#define MCL_IPW_NOTIF_AR_RELEASE_REVISION_VERSION     2
#define MCL_IPW_NOTIF_SW_MAJOR_VERSION                1
#define MCL_IPW_NOTIF_SW_MINOR_VERSION                0
#define MCL_IPW_NOTIF_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if header file and Mcl header file are of the same vendor */
#if (MCL_IPW_NOTIF_VENDOR_ID != MCL_NOTIF_VENDOR_ID)
    #error "Mcl_IPW_Notif.h and Mcl_Notif.h have different vendor ids"
#endif
/* Check if header file and Mcl header file are of the same Autosar version */
#if ((MCL_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION    != MCL_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_NOTIF_AR_RELEASE_MINOR_VERSION    != MCL_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_NOTIF_AR_RELEASE_REVISION_VERSION != MCL_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW_Notif.h and Mcl_Notif.h are different"
#endif
/* Check if header file and Mcl_IPW_Types header file are of the same software version */
#if ((MCL_IPW_NOTIF_SW_MAJOR_VERSION != MCL_NOTIF_SW_MAJOR_VERSION) || \
     (MCL_IPW_NOTIF_SW_MINOR_VERSION != MCL_NOTIF_SW_MINOR_VERSION) || \
     (MCL_IPW_NOTIF_SW_PATCH_VERSION != MCL_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW_Notif.h and Mcl_Notif.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)

/* Function for reporting Unexpected ISR error implemented through macro */
#if (MCL_REPORT_UNEXPECTED_ISR == STD_ON)
/** @violates @ref Mcl_IPW_Notif_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Mcl_IPW_ReportUnexpectedIsrError() (Mcl_ReportUnexpectedIsrError())
#endif /* (MCL_REPORT_UNEXPECTED_ISR == STD_ON) */

/* Function for notifications of Dma channels implemented through macro */
/** @violates @ref Mcl_IPW_Notif_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define Mcl_IPW_DmaChannelNotification(Channel)  \
    (Mcl_Notification(Channel))
    
/* Function for processing error interrupts of Dma channels implemented through macro */
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
/** @violates @ref Mcl_IPW_Notif_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define Mcl_IPW_ErrorNotification(DmaHwInstance,Error) \
    (Mcl_ErrorNotification((DmaHwInstance),(Error)))
#endif /*(MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON) */


#endif /* (MCL_ENABLE_DMA == STD_ON) */
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

#endif /* MCL_IPW_NOTIF_H */

/** @} */

