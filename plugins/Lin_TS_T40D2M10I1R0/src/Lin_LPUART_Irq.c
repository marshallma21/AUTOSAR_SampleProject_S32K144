/**
*   @file    Lin_LPUART_Irq.c
*   @implements Lin_LPUART_Irq.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - File used by LIN that contain the ISRs.
*   @details This file contains the ISR functions used to serve the LIN interrupts.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_LPUART_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_LPUART_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_LPUART_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_LPUART_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Lin_LPUART_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Lin_Irq.c
*/
#include "Lin.h"
#include "Lin_LPUART.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Irq.c
*/
#define LIN_IRQ_VENDOR_ID_C                    43
#define LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C     4
#define LIN_AR_RELEASE_MINOR_VERSION_IRQ_C     2
/*
* @violates @ref Lin_LPUART_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_IRQ_C  2
#define LIN_SW_MAJOR_VERSION_IRQ_C             1
#define LIN_SW_MINOR_VERSION_IRQ_C             0
#define LIN_SW_PATCH_VERSION_IRQ_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_IRQ_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin_Irq.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C   != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IRQ_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IRQ_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IRQ_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_IRQ_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_IRQ_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Irq.c and Lin.h are different"
#endif
/* Check if current file and Lin_LPUART header file are of the same vendor */
#if (LIN_IRQ_VENDOR_ID_C != LIN_LPUART_VENDOR_ID)
    #error "Lin_Irq.c and Lin_LPUART.h have different vendor ids"
#endif
/* Check if current file and Lin_LPUART header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != LIN_LPUART_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IRQ_C    != LIN_LPUART_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IRQ_C != LIN_LPUART_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin_LPUART.h are different"
#endif
/* Check if current file and Lin_LPUART header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IRQ_C != LIN_LPUART_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_IRQ_C != 0) || \
     (LIN_SW_PATCH_VERSION_IRQ_C != 1) \
    )
    #error "Software Version Numbers of Lin_Irq.c and Lin_LPUART.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief          LIN controller interrupts
* @details        LIN controller interrupts
*
*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_LPUART_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#if ( LIN_UNIFIED_INTERRUPTS == STD_ON )
    #if defined(LPUART_0)
    ISR(Lin_LPUART_Isr_LPUART_0);
    #endif

    #if defined(LPUART_1)
    ISR(Lin_LPUART_Isr_LPUART_1);
    #endif

    #if defined(LPUART_2)
    ISR(Lin_LPUART_Isr_LPUART_2);
    #endif

    #if defined(LPUART_3)
    ISR(Lin_LPUART_Isr_LPUART_3);
    #endif
#else
    #if defined(LPUART_0)
    ISR(Lin_LPUART_IsrError_LPUART_0);
    ISR(Lin_LPUART_IsrTxRx_LPUART_0);
    #endif

    #if defined(LPUART_1)
    ISR(Lin_LPUART_IsrError_LPUART_1);
    ISR(Lin_LPUART_IsrTxRx_LPUART_1);
    #endif

    #if defined(LPUART_2)
    ISR(Lin_LPUART_IsrError_LPUART_2);
    ISR(Lin_LPUART_IsrTxRx_LPUART_2);
    #endif

    #if defined(LPUART_3)
    ISR(Lin_LPUART_IsrError_LPUART_3);
    ISR(Lin_LPUART_IsrTxRx_LPUART_3);
    #endif
#endif /* LIN_UNIFIED_INTERRUPTS == STD_ON */

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_LPUART_Irq_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_LPUART_Irq_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#if ( LIN_UNIFIED_INTERRUPTS == STD_ON )
    #if defined(LPUART_0)
    /**
    * @brief   Interrupt on LPUART_0.
    * @details This function implements the ISR occurring on LPUART_0.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 0 is used.
    *
    * @isr
    *
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_Isr_LPUART_0)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_0);
        Lin_LPUART_ErrorInterruptHandler(LPUART_0);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif

    #if defined(LPUART_1)
    /**
    * @brief   Interrupt on LPUART_1.
    * @details This function implements the ISR occurring on LPUART_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_Isr_LPUART_1)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_1);
        Lin_LPUART_ErrorInterruptHandler(LPUART_1);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif

    #if defined(LPUART_2)
    /**
    * @brief   Interrupt on LPUART_2.
    * @details This function implements the ISR occurring on LPUART_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_Isr_LPUART_2)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_2);
        Lin_LPUART_ErrorInterruptHandler(LPUART_2);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif

    #if defined(LPUART_3)
    /**
    * @brief   Interrupt on LPUART_3.
    * @details This function implements the ISR occurring on LPUART_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_Isr_LPUART_3)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_3);
        Lin_LPUART_ErrorInterruptHandler(LPUART_3);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
#else
    #if defined(LPUART_0)
    /**
    * @brief   Error interrupt on LPUART_0.
    * @details This function implements the ISR occurring on error on
    *          LPUART_0.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 0 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrError_LPUART_0)
    {
        Lin_LPUART_ErrorInterruptHandler(LPUART_0);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    /**
    * @brief   TxRx interrupt on LPUART_0.
    * @details This function implements the ISR occurring on reception on
    *          LPUART_0.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 0 is used and DMA is not used.
    *
    * @isr
    *
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrTxRx_LPUART_0)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_0);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif

    #if defined(LPUART_1)
    /**
    * @brief   Error interrupt on LPUART_1.
    * @details This function implements the ISR occurring on error on
    *          LPUART_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrError_LPUART_1)
    {
        Lin_LPUART_ErrorInterruptHandler(LPUART_1);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    /**
    * @brief   TxRx interrupt on LPUART_1.
    * @details This function implements the ISR occurring on reception on
    *          LPUART_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrTxRx_LPUART_1)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_1);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    #endif

    #if defined(LPUART_2)
    /**
    * @brief   Error interrupt on LPUART_2.
    * @details This function implements the ISR occurring on error on
    *          LPUART_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrError_LPUART_2)
    {
        Lin_LPUART_ErrorInterruptHandler(LPUART_2);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    /**
    * @brief   TxRx interrupt on LPUART_2.
    * @details This function implements the ISR occurring on reception on
    *          LPUART_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrTxRx_LPUART_2)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_2);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    #endif

    #if defined(LPUART_3)
    /**
    * @brief   Error interrupt on LPUART_3.
    * @details This function implements the ISR occurring on error on
    *          LPUART_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrError_LPUART_3)
    {
        Lin_LPUART_ErrorInterruptHandler(LPUART_3);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    /**
    * @brief   TxRx interrupt on LPUART_3.
    * @details This function implements the ISR occurring on reception on
    *          LPUART_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LPUART_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_LPUART_IsrTxRx_LPUART_3)
    {
        Lin_LPUART_TxRxInterruptHandler(LPUART_3);
        /** @violates @ref Lin_LPUART_Irq_c_REF_4 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }

    #endif

#endif /* LIN_UNIFIED_INTERRUPTS == STD_ON */

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_LPUART_Irq_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/*! @} */
