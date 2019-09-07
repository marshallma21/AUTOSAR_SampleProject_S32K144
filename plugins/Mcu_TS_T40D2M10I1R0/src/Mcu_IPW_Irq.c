/**
*   @file    Mcu_IPW.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Middle layer implementation.
*   @details Layer that implements the wrapper for routing data from/to external interface
*            to IP layer.
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


#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_IPW_Irq_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_IPW_Irq_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_IPW_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_IPW_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Mcu_IPW_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used.
* The comma is used  to abstract the trusted call function and to determine when the return into user mode is needed.
*
* @section Mcu_IPW_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall
* not be implicitly converted to a different underlying type. Integer to pointer conversion, specific
* to the ISR entry / exit code .
*
* @section  Mcu_IPW_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* preceding &, or with a paranthesised parameter list, which may be empy.
*
* @section  Mcu_IPW_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the prototype
* shall be visible at both the function definition and call.
*
* @section Mcu_IPW_Irq_c_REF_9
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Header file with prototype functions defines in this layer. */
#include "Mcu_IPW.h"
#include "Mcu_IPW_Irq.h"

/* Header files that are called from IPW layer. */
#include "Mcu_PMC.h"
#include "Mcu_SCG.h"
#include "Mcu_CMU.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_IRQ_VENDOR_ID                     43
/** @violates @ref Mcu_IPW_Irq_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION      4
/** @violates @ref Mcu_IPW_Irq_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION      2
/** @violates @ref Mcu_IPW_Irq_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION   2
#define MCU_IPW_IRQ_SW_MAJOR_VERSION              1
#define MCU_IPW_IRQ_SW_MINOR_VERSION              0
#define MCU_IPW_IRQ_SW_PATCH_VERSION              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_IPW_Irq header file are of the same vendor */
#if (MCU_IPW_IRQ_VENDOR_ID != MCU_IPW_VENDOR_ID)
    #error "Mcu_IPW_Irq.c and Mcu_IPW_Irq.h have different vendor ids"
#endif
/* Check if current file and Mcu_IPW header file are of the same Autosar version */
#if ((MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION    != MCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION    != MCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION != MCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_IPW.h are different"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Software version */
#if ((MCU_IPW_IRQ_SW_MAJOR_VERSION != MCU_IPW_SW_MAJOR_VERSION) || \
     (MCU_IPW_IRQ_SW_MINOR_VERSION != MCU_IPW_SW_MINOR_VERSION) || \
     (MCU_IPW_IRQ_SW_PATCH_VERSION != MCU_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Irq.c and Mcu_IPW_Irq.h are different"
#endif


/* Check if current file and Mcu_PMC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_PMC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_PMC.h have different vendor ids"
#endif
/* Check if current file and Mcu_PMC header file are of the same Autosar version */
#if ((MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION    != MCU_PMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION    != MCU_PMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION != MCU_PMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_PMC.h are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_CODE

/* @violates @ref Mcu_IPW_Irq_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if (MCU_CMU_PMC_SCG_INTERRUPT == STD_ON)
/**
* @brief       This function represents the ISR handler for CMU PMC SCG related events.
* @details     This interrupt is triggered if one of the enabled CMU PMC SCG detect an out of range clock.
*              this function exist only on S32K11X.
*
*
* @isr
*
*/
/** @violates @ref Mcu_IPW_Irq_c_REF_9 MISRA 2004 The IRQ handler is used by external code */
ISR( Mcu_PMC_SCG_CMU_Isr )
{
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
    if(Mcu_CMU_GetInterruptStatus(CMU1_CHANNEL) != 0U)
    {
        /* CMU1 interrupt */
        Mcu_CMU_ClockFailInt();
    }
#endif
#endif
    if(Mcu_PMC_GetInterruptStatus() != 0U)
    {
        /* PMC interrupt */
        Mcu_PMC_VoltageErrorIsr();
    }
   
    /* SCG Interrupt */
/* if(Mcu_SCG_GetInterruptStatus() != 0U)
    {
        
    }
*/
    /** @violates @ref Mcu_CMU_IRQ_c_REF_3 MISRA 2004 Conversion from pointer to integer */
    /** @violates @ref Mcu_CMU_IRQ_c_REF_4 MISRA 2004 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}

#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_IPW_Irq_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_Irq_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

