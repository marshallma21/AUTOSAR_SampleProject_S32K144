/**
*   @file           Pwm_Ftm_Irq.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Interface for Ftm Interrupt handlers.
*   @details        Header containing interface for Ftm Interrupt handlers.
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



#ifndef PWM_FTM_IRQ_H
#define PWM_FTM_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Ftm_Irq_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_Ftm_Irq_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_Ftm_Irq_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* MemMap.h included after each section define in order to set the current memory section
*
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Mcal.h"

/*
* @violates @ref Pwm_Ftm_Irq_H_REF_1 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Pwm_Ftm_Types.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ftm_Irq.h
*/
#define PWM_FTM_IRQ_VENDOR_ID                         43
#define PWM_FTM_IRQ_MODULE_ID                         121
/* @violates @ref Pwm_Ftm_Irq_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_IRQ_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_Ftm_Irq_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_IRQ_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_Ftm_Irq_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_FTM_IRQ_AR_RELEASE_REVISION_VERSION       2
#define PWM_FTM_IRQ_SW_MAJOR_VERSION                  1
#define PWM_FTM_IRQ_SW_MINOR_VERSION                  0
#define PWM_FTM_IRQ_SW_PATCH_VERSION                  1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal.h are of the same Autosar version */
    #if ((PWM_FTM_IRQ_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_FTM_IRQ_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm_Ftm_Irq.h and Mcal.h are different"
    #endif
#endif

/* Check if header file and Pwm_Ftm_Types.h header file are of the same vendor */
#if (PWM_FTM_IRQ_VENDOR_ID != PWM_FTM_TYPES_VENDOR_ID)
    #error "Pwm_Ftm_Irq.h and Pwm_Ftm_Types.h have different vendor ids"
#endif
/* Check if header file and Pwm_Ftm_Types.h header file are of the same Autosar version */
#if ((PWM_FTM_IRQ_AR_RELEASE_MAJOR_VERSION    != PWM_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_IRQ_AR_RELEASE_MINOR_VERSION    != PWM_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_IRQ_AR_RELEASE_REVISION_VERSION != PWM_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm_Irq.h and Pwm_Ftm_Types.h are different"
#endif
/* Check if header file and Pwm_Ftm_Types.h header file are of the same software version */
#if ((PWM_FTM_IRQ_SW_MAJOR_VERSION != PWM_FTM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_FTM_IRQ_SW_MINOR_VERSION != PWM_FTM_TYPES_SW_MINOR_VERSION) || \
     (PWM_FTM_IRQ_SW_PATCH_VERSION != PWM_FTM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm_Irq.h and Pwm_Ftm_Types.h are different"
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
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/
/*
* @violates @ref Pwm_Ftm_Irq_H_REF_3 Only preprocessor statements and comments 
                 before 'include'
*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_Ftm_Irq_H_REF_1 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Pwm_MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*
* @brief            This function is a interrupt service routine used to proccess compare events for each Ftm channel
* @details          This function will call notification functions configured. 
*/
FUNC(void , PWM_CODE) Pwm_Ftm_ProcessCommonInterrupt(CONST(uint8, AUTOMATIC) u8FtmChannel);


/*
* @brief            This function is a interrupt service routine used to proccess timer overflow events for each Ftm module
* @details          This function will call notification functions configured. 
*/
FUNC(void , PWM_CODE) Pwm_Ftm_ProcessTofInterrupt(CONST(uint8, AUTOMATIC) u8FtmModule);

#endif


#if (PWM_FAULT_SUPPORTED == STD_ON)
/**
* @brief            This function is a interrupt service routine used to proccess faults for each Ftm module
* @details          This function will call fault notification functions configured. 
*
*/
FUNC(void , PWM_CODE) Pwm_Ftm_ProcessFaultInterrupt(CONST(uint8, AUTOMATIC) u8FaultChannelId);
#endif

/*
* @violates @ref Pwm_Ftm_Irq_H_REF_3 Only preprocessor statements and comments before 'include'
*/
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_Ftm_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* PWM_FTM_IRQ_H */
/** @} */
