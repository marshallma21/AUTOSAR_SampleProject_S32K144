/**
*   @file    Mcu_PMC_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Power Management Controller module functions implementation.
*   @details Specific functions for PMC configuration and control.
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
* @section Mcu_PMC_IRQ_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_PMC_IRQ_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_PMC_IRQ_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. This conversion is specific to the interrupt
* handler entry / exit code.
*
* @section Mcu_PMC_IRQ_c_REF_4
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be
* implicitly converted to a different underlying type. Integer to pointer conversion, specific to
* the ISR entry / exit code.
*
* @section Mcu_PMC_IRQ_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Mcu_PMC.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define MCU_PMC_IRQ_VENDOR_ID_C                     43
#define MCU_PMC_IRQ_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_PMC_IRQ_AR_RELEASE_MINOR_VERSION_C      2
#define MCU_PMC_IRQ_AR_RELEASE_REVISION_VERSION_C   2
#define MCU_PMC_IRQ_SW_MAJOR_VERSION_C              1
#define MCU_PMC_IRQ_SW_MINOR_VERSION_C              0
#define MCU_PMC_IRQ_SW_PATCH_VERSION_C              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PMC_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PMC_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PMC_Irq.c and Mcal.h are different"
    #endif
#endif

/* Check if current file and Mcu_PMC_Irq header file are of the same Autosar version */
#if (MCU_PMC_IRQ_VENDOR_ID_C != MCU_PMC_VENDOR_ID)
    #error "Mcu_PMC_Irq.c and Mcu_PMC.h have different vendor ids"
#endif
/* Check if current file and Mcu_PMC_Irq header file are of the same Autosar version */
#if ((MCU_PMC_IRQ_AR_RELEASE_MAJOR_VERSION_C    != MCU_PMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PMC_IRQ_AR_RELEASE_MINOR_VERSION_C    != MCU_PMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PMC_IRQ_AR_RELEASE_REVISION_VERSION_C != MCU_PMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PMC_Irq.c and Mcu_PMC.h are different"
#endif
/* Check if current file and Mcu_PMC_Irq header file are of the same Software version */
#if ((MCU_PMC_IRQ_SW_MAJOR_VERSION_C != MCU_PMC_SW_MAJOR_VERSION) || \
     (MCU_PMC_IRQ_SW_MINOR_VERSION_C != MCU_PMC_SW_MINOR_VERSION) || \
     (MCU_PMC_IRQ_SW_PATCH_VERSION_C != MCU_PMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMC_Irq.c and Mcu_PMC.h are different"
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


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_PMC_IRQ_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#if (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON)
ISR(Mcu_PMC_LowVoltage_ISR);
#endif /* (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON) */

#if (MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON)
ISR(Mcu_PMC_TemperatureError_ISR);
#endif /* (MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON) */

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON)
/**
* @brief       This function represents the ISR handler for PMC related events.
* @details     This interrupt is triggered if one of the enabled PMC's detect an out of range clock.
*
*
* @isr
*
*/
/** @violates @ref Mcu_PMC_IRQ_c_REF_5 MISRA 2004 The IRQ handler is used by external code */
#ifndef MCU_CMU_PMC_SCG_INTERRUPT
ISR(Mcu_PMC_LowVoltage_ISR)
{
    Mcu_PMC_VoltageErrorIsr();
    /** @violates @ref Mcu_PMC_IRQ_c_REF_3 MISRA 2004 Conversion from pointer to integer */
    /** @violates @ref Mcu_PMC_IRQ_c_REF_4 MISRA 2004 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#else 
#if(MCU_CMU_PMC_SCG_INTERRUPT == STD_OFF)
ISR(Mcu_PMC_LowVoltage_ISR)
{
    Mcu_PMC_VoltageErrorIsr();
    /** @violates @ref Mcu_PMC_IRQ_c_REF_3 MISRA 2004 Conversion from pointer to integer */
    /** @violates @ref Mcu_PMC_IRQ_c_REF_4 MISRA 2004 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif
#endif
#endif /* (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON) */

#if (MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON)
/**
* @brief       This function represents the ISR handler for PMC related events.
* @details     This interrupt is triggered if one of the enabled PMC's detect an out of range clock.
*
*
* @isr
*
*/
/** @violates @ref Mcu_PMC_IRQ_c_REF_5 MISRA 2004 The IRQ handler is used by external code */
ISR(Mcu_PMC_TemperatureError_ISR)
{
    Mcu_PMC_TemperatureErrorIsr();
    /** @violates @ref Mcu_PMC_IRQ_c_REF_3 MISRA 2004 Conversion from pointer to integer */
    /** @violates @ref Mcu_PMC_IRQ_c_REF_4 MISRA 2004 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* (MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON) */


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_PMC_IRQ_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PMC_IRQ_c_REF_2 MISRA 2004 Only preprocessor statements and comments before
* '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
