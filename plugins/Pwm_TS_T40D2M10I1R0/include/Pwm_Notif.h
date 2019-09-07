/**
*   @file           Pwm_Notif.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Pwm notifications API header.
*   @details        Pwm notifications API header.
*
*   @addtogroup     PWM_MODULE
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

#ifndef PWM_NOTIF_H
#define PWM_NOTIF_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Notif_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_Notif_H_REF_2
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
/*
* @file           Pwm_Notif.h
*/
/*
* @violates @ref Pwm_Notif_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Pwm_Notif.h
*/
#define PWM_NOTIF_VENDOR_ID                       43
#define PWM_NOTIF_MODULE_ID                       121
/* @violates @ref Pwm_Notif_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_NOTIF_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Pwm_Notif_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_NOTIF_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Pwm_Notif_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_NOTIF_AR_RELEASE_REVISION_VERSION     2
#define PWM_NOTIF_SW_MAJOR_VERSION                1
#define PWM_NOTIF_SW_MINOR_VERSION                0
#define PWM_NOTIF_SW_PATCH_VERSION                1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if header file and Pwm header file are of the same vendor */
#if (PWM_NOTIF_VENDOR_ID != PWM_VENDOR_ID)
    #error "Pwm_Notif.h and Pwm.h have different vendor ids"
#endif
/* Check if header file and Pwm header file are of the same Autosar version */
#if ((PWM_NOTIF_AR_RELEASE_MAJOR_VERSION    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_NOTIF_AR_RELEASE_MINOR_VERSION    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_NOTIF_AR_RELEASE_REVISION_VERSION != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Notif.h and Pwm.h are different"
#endif
/* Check if header file and Pwm_Notif header file are of the same software version */
#if ((PWM_NOTIF_SW_MAJOR_VERSION != PWM_SW_MAJOR_VERSION) || \
     (PWM_NOTIF_SW_MINOR_VERSION != PWM_SW_MINOR_VERSION) || \
     (PWM_NOTIF_SW_PATCH_VERSION != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Notif.h and Pwm.h are different"
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
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_Notif_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, PWM_CODE) Pwm_Notification
(
    VAR(Pwm_ChannelType, AUTOMATIC) Channel
);
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */

#if ((PWM_FAULT_SUPPORTED == STD_ON) || (PWM_RELOAD_NOTIF_SUPPORTED == STD_ON))
FUNC (P2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST), PWM_CODE) Pwm_GetIpConfigPtr
(
    void
);
#endif /* (PWM_FAULT_SUPPORTED == STD_ON) */



#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_Notif_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* PWM_NOTIF_H */

/** @} */
