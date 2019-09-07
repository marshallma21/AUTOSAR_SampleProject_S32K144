/**
*   @file    Mcu_IPW_Irq.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Midle layer interface for interrupts.
*   @details File contains function prototypes used by IPV ISRs only.
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


#ifndef MCU_IPW_IRQ_H
#define MCU_IPW_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_IPW_Irq_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_IRQ_VENDOR_ID                       43
#define MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION        2
#define MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION     2
#define MCU_IPW_IRQ_SW_MAJOR_VERSION                1
#define MCU_IPW_IRQ_SW_MINOR_VERSION                0
#define MCU_IPW_IRQ_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* defines for various fields for CMU_ISR_ADDR32 */
#define MCU_IPW_CMU_UNMASK_VALUE_U32        ((uint32)0x00000000U)
#define MCU_IPW_CMU_ISR_FHHI_MASK32         ((uint32)0x00000004U)
#define MCU_IPW_CMU_ISR_FLLI_MASK32         ((uint32)0x00000002U)
#define MCU_IPW_CMU_ISR_OLRI_MASK32         ((uint32)0x00000001U)

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
#define MCU_START_SEC_CODE
/** @violates @ref Mcu_IPW_Irq_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

#if (MCU_CMU_PMC_SCG_INTERRUPT == STD_ON)
ISR( Mcu_PMC_SCG_CMU_Isr );
#endif

#define MCU_STOP_SEC_CODE
/** @violates @ref Mcu_IPW_Irq_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_IPW_IRQ_H */

/** @} */

