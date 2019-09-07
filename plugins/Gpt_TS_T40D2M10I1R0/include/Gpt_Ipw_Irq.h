/**
*   @file    Gpt_Ipw_Irq.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Header file used to wrap generic ISR routine.
*   @details Driver header file used to wrap generic ISR routine for lower layers. The hardware channel
*            number is converted into an index which is used by the generic ISR routine.
*   @addtogroup GPT_MODULE
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

#ifndef GPT_IPW_IRQ_H
#define GPT_IPW_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_IPW_IRQ_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Irq.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_IPW_IRQ_VENDOR_ID                      43
#define GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION       2
#define GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION    2
#define GPT_IPW_IRQ_SW_MAJOR_VERSION               1
#define GPT_IPW_IRQ_SW_MINOR_VERSION               0
#define GPT_IPW_IRQ_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same vendor */
#if (GPT_IPW_IRQ_VENDOR_ID != GPT_IRQ_VENDOR_ID)
    #error "Gpt_Ipw_Irq.h and Gpt_Irq.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION != GPT_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Irq.h and Gpt_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_IPW_IRQ_SW_MAJOR_VERSION != GPT_IRQ_SW_MAJOR_VERSION) || \
     (GPT_IPW_IRQ_SW_MINOR_VERSION != GPT_IRQ_SW_MINOR_VERSION) || \
     (GPT_IPW_IRQ_SW_PATCH_VERSION != GPT_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Irq.h and Gpt_Irq.h are different"
#endif


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @violates @ref GPT_IPW_IRQ_H_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel,u8HwModule) (Gpt_ProcessCommonInterrupt((u8HwChannel)+(u8HwModule)))

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*GPT_IPW_IRQ_H*/

/** @} */
