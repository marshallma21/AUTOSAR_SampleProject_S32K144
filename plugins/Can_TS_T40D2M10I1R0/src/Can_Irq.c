/**
*   @file    Can_Irq.c
*   @implements Can_Irq.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Interrupt routines for Can driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FLEXCAN
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
* @section Can_Irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Irq_c_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type.
*
* @section Can_Irq_c_REF_10
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if: 
*    a) it is not aconversion to a wider integer type of the same signedness, 
*    b) the expression is complex,
*    c) the expression is not constant and is a function argument,
*    d) the expression is not constant and is a return expression.
*
* @section Can_Irq_c_REF_15
* Violates MISRA 2004 Advisory Rule 12.1, Use of mixed mode arithmetic
* This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed
* to the macro. The care is taken for the parameters sent as inputs to the macro and hence unintended truncation of values
* would not result.
*
* @section Can_Irq_c_REF_16
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_Irq_c_REF_17
* Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) should be
* effectively Boolean. Expressions that are effectively Boolean
* should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).
*
* @section Can_Irq_c_REF_18
* Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be
* permitted.
*
*/

/*
(CAN035) The module Can_Irq.c contains the implementation of interrupt frames.The implementation of the interrupt service routine shall be in Can.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Can_Irq.c
*/
#include "Can.h"
#include "Can_IPW.h"
#include "CanIf_Cbk.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* The integration of incompatible files shall be avoided. */
/* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_VENDOR_ID_IRQ_C                      43
#define CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define CAN_AR_RELEASE_MINOR_VERSION_IRQ_C       2
/* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_REVISION_VERSION_IRQ_C    2
#define CAN_SW_MAJOR_VERSION_IRQ_C               1
#define CAN_SW_MINOR_VERSION_IRQ_C               0
#define CAN_SW_PATCH_VERSION_IRQ_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_IRQ_C != CAN_VENDOR_ID)
    #error "Can_Irq.c and Can.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_IRQ_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_Irq.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IRQ_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_IRQ_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_IRQ_C != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_Irq.c and Can.h are different"
#endif


/* Check if current file and CAN_IPW header file are of the same vendor */
#if (CAN_VENDOR_ID_IRQ_C != CAN_IPW_VENDOR_ID_H)
    #error "Can_Irq.c and Can_IPW.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_IRQ_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_Irq.c and Can_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IRQ_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_IRQ_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_IRQ_C != CAN_IPW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Irq.c and Can_IPW.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Irq.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and CANIF_CBK header file are of the same version */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C != CANIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C != CANIF_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Irq.c and CanIf_Cbk.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/*
   (CAN033) The Can module shall implement the interrupt service routines for all CAN Hardware Unit
   interrupts that are needed. The Can module shall disable all unused interrupts in the CAN controller.
   The Can module shall reset the interrupt flag at the end of the ISR (if not done automatically by
   hardware). The Can module shall not set the configuration (i.e. priority) of the vector table entry.
*/
/**
* @brief          CAN controller A interrupts
* @details        CAN controller A interrupts
*
*
*/
/* CAN controller A interrupts */
#ifdef CAN_FCA_INDEX
#if (CAN_UNIFIED_INTERRUPTS == STD_ON) /*  Support interrupt for S32K118 */
    #if ((CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON) || (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) || (CAN_PUBLIC_ICOM_SUPPORT == STD_ON))
        ISR(Can_ISR_NVIC_ID_10_FCA_SP);
    #endif
    #if (((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON)) ||\
      ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON)) ||\
      ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF)))
        ISR(Can_ISR_NVIC_ID_11_FCA_SP);
    #endif
#else
    #if (CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON)
        ISR(Can_IsrFCA_ERR);
    #endif
        #if (CAN_A_BUSOFFINT_SUPPORTED == STD_ON)
            ISR(Can_IsrFCA_BO);
        #endif /* (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_PUBLIC_ICOM_SUPPORT==STD_ON)
        ISR(Can_IsrFCA_PN);
    #endif/* (CAN_PUBLIC_ICOM_SUPPORT==STD_OFF) */
        #if ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON))
            #if (CAN_ISROPTCODESIZE == STD_ON)
                ISR(Can_IsrFCA_UNI);
            #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
                #if (CAN_A_FIFO_EN == STD_ON)
                    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                        ISR(Can_IsrFCA_RxFifoEventsMbMix);
                    #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        ISR(Can_IsrFCA_FrameAvMbMix);
                        ISR(Can_IsrFCA_OverfMbMix);
                        ISR(Can_IsrFCA_WarnMbMix);
                    
                    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                #else /* (CAN_A_FIFO_EN == STD_OFF) */
                        ISR(Can_IsrFCA_MB_00_15);
                #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                        ISR(Can_IsrFCA_MB_16_31);
            #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

        #elif ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON))
            #if (CAN_ISROPTCODESIZE == STD_ON)
                ISR(Can_IsrFCA_UNI);
            #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
                #if (CAN_A_FIFO_EN == STD_ON)
                    #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                        ISR(Can_IsrFCA_RxFifoEventsMbMix);
                    #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        ISR(Can_IsrFCA_FrameAvMbMix);
                        ISR(Can_IsrFCA_OverfMbMix);
                        ISR(Can_IsrFCA_WarnMbMix);
                    #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                #else /* (CAN_A_FIFO_EN == STD_OFF) */
                        ISR(Can_IsrFCA_MB_00_15);
                #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                        ISR(Can_IsrFCA_MB_16_31);
            #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

        #elif ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF))
            #if (CAN_ISROPTCODESIZE == STD_ON)
                ISR(Can_IsrFCA_UNI);
            #else /* (CAN_ISROPTCODESIZE == STD_ON) */
                #if (CAN_A_FIFO_EN == STD_OFF)
                    ISR(Can_IsrFCA_MB_00_15);
                    ISR(Can_IsrFCA_MB_16_31);
                #endif /* (CAN_A_FIFO_EN == STD_OFF) */
            #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
        #endif /* ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF)) */
    #endif /* CAN_FCA_INDEX */
#endif
/**
* @brief          CAN controller B interrupts
* @details        CAN controller B interrupts
*
*
*/
/* CAN controller B interrupts */
#ifdef CAN_FCB_INDEX
  #if (CAN_B_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCB_ERR);
  #endif
    #if (CAN_B_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCB_BO);
    #endif /* (CAN_B_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCB_RxFifoEventsMbMix);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCB_FrameAvMbMix);
                    ISR(Can_IsrFCB_OverfMbMix);
                    ISR(Can_IsrFCB_WarnMbMix);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_00_15);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_16_31);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_OFF) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCB_RxFifoEventsMbMix);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCB_FrameAvMbMix);
                    ISR(Can_IsrFCB_OverfMbMix);
                    ISR(Can_IsrFCB_WarnMbMix);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_00_15);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_16_31);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_OFF)
                    ISR(Can_IsrFCB_MB_00_15);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
                    ISR(Can_IsrFCB_MB_16_31);
    #endif /* ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCB_INDEX */

/**
* @brief          CAN controller C interrupts
* @details        CAN controller C interrupts
**/
/* CAN controller C interrupts */
#ifdef CAN_FCC_INDEX
  #if (CAN_C_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCC_ERR);
  #endif
    #if (CAN_C_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCC_BO);
    #endif /* (CAN_C_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCC_RxFifoEventsMbMix);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCC_FrameAvMbMix);
                    ISR(Can_IsrFCC_OverfMbMix);
                    ISR(Can_IsrFCC_WarnMbMix);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_00_15);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_16_31);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_OFF) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCC_RxFifoEventsMbMix);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCC_FrameAvMbMix);
                    ISR(Can_IsrFCC_OverfMbMix);
                    ISR(Can_IsrFCC_WarnMbMix);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_00_15);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_16_31);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_OFF)
                    ISR(Can_IsrFCC_MB_00_15);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_16_31);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCC_INDEX */


#define CAN_START_SEC_CODE
/* @violates @ref Can_Irq_c_REF_3 MISRA 2004 Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Irq_c_REF_5 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN A
==================================================================================================*/
#ifdef CAN_FCA_INDEX
#if (CAN_UNIFIED_INTERRUPTS == STD_ON) /*  Support interrupt for S32K118 */
    #if ((CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON) || (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) || (CAN_PUBLIC_ICOM_SUPPORT == STD_ON))
        Can_Isr_ID_10(A)
    #endif
    #if (((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON)) ||\
    ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON)) ||\
    ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF)))
        Can_Isr_ID_11(A)
    #endif
#else
  #if (CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    CAN_ERRISR(A)
  #endif
    #if (CAN_A_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        CAN_BOISR(A)
    #endif /* (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_PUBLIC_ICOM_SUPPORT==STD_ON)
        /* External Wake-up by PNET */
        CAN_WKPPNISR(A)
    #endif/* (CAN_PUBLIC_ICOM_SUPPORT==STD_OFF) */
    #if ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
                       converted to a different underlying type if:
                       (a) it is not a conversion to a wider integer type of the samesignedness, or
                       (b) the expression is complex, or
                       (c) the expression is not constant and is a function argument, or
                       (d) the expression is not constant and is a return expression*/
                    /* @violates @ref Can_Irq_c_REF_17 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
                        should be effectively Boolean. Expressions that are effectively Boolean
                        should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).*/
                    /* @violates @ref Can_Irq_c_REF_18 Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be permitted.*/
                    CAN_RXFIFO_EVENTS_MB_MIX(A,15)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV_MB_MIX(A)
                        /* RX Fifo Overflow Interrupt*/
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER_MB_MIX(A)
                        /* Rx Fifo Warning Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN_MB_MIX(A)

                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(A, MB_00_15, 0U, 15U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(A, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
                       converted to a different underlying type if:
                       (a) it is not a conversion to a wider integer type of the samesignedness, or
                       (b) the expression is complex, or
                       (c) the expression is not constant and is a function argument, or
                       (d) the expression is not constant and is a return expression*/
                    /* @violates @ref Can_Irq_c_REF_17 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
                        should be effectively Boolean. Expressions that are effectively Boolean
                        should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).*/
                    /* @violates @ref Can_Irq_c_REF_18 Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be permitted.*/
                    CAN_RXFIFO_EVENTS_MB_MIX(A,15)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV_MB_MIX(A)
                        /* RX Fifo Overflow Interrupt*/
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER_MB_MIX(A)
                        /* Rx Fifo Warning Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN_MB_MIX(A)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_RXISRS(A, MB_00_15, 0U, 15U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(A, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_TXISRS(A, MB_00_15, 0U, 15U)
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_TXISRS(A, MB_16_31, 16U, 31U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */

        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON)) */
#endif
#endif /* CAN_FCA_INDEX */

/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN B
==================================================================================================*/
#ifdef CAN_FCB_INDEX
  #if (CAN_B_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    CAN_ERRISR(B)
  #endif
    #if (CAN_B_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        CAN_BOISR(B)
    #endif /* (CAN_B_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
                       converted to a different underlying type if:
                       (a) it is not a conversion to a wider integer type of the samesignedness, or
                       (b) the expression is complex, or
                       (c) the expression is not constant and is a function argument, or
                       (d) the expression is not constant and is a return expression*/
                    /* @violates @ref Can_Irq_c_REF_17 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
                        should be effectively Boolean. Expressions that are effectively Boolean
                        should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).*/
                    /* @violates @ref Can_Irq_c_REF_18 Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be permitted.*/
                    CAN_RXFIFO_EVENTS_MB_MIX(B,15)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        CAN_MB_FRAV_MB_MIX(B)
                        /* RX Fifo Overflow Interrupt*/
                        CAN_MB_RXOVER_MB_MIX(B)
                        /* Rx Fifo Warning Interrupt */
                        CAN_MB_RXWARN_MB_MIX(B)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(B, MB_00_15, 0U, 15U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(B, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_OFF) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
                       converted to a different underlying type if:
                       (a) it is not a conversion to a wider integer type of the samesignedness, or
                       (b) the expression is complex, or
                       (c) the expression is not constant and is a function argument, or
                       (d) the expression is not constant and is a return expression*/
                    /* @violates @ref Can_Irq_c_REF_17 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
                        should be effectively Boolean. Expressions that are effectively Boolean
                        should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).*/
                    /* @violates @ref Can_Irq_c_REF_18 Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be permitted.*/
                    CAN_RXFIFO_EVENTS_MB_MIX(B,15)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV_MB_MIX(B)
                        /* RX Fifo Overflow Interrupt*/
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER_MB_MIX(B)
                        /* Rx Fifo Warning Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN_MB_MIX(B)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_RXISRS(B, MB_00_15, 0U, 15U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_RXISRS(B, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_TXISRS(B, MB_00_15, 0U, 15U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_TXISRS(B, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCB_INDEX */
/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN C
==================================================================================================*/
#ifdef CAN_FCC_INDEX
  #if (CAN_C_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    CAN_ERRISR(C)
  #endif
    #if (CAN_C_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        CAN_BOISR(C)
    #endif /* (CAN_C_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
                       converted to a different underlying type if:
                       (a) it is not a conversion to a wider integer type of the samesignedness, or
                       (b) the expression is complex, or
                       (c) the expression is not constant and is a function argument, or
                       (d) the expression is not constant and is a return expression*/
                    /* @violates @ref Can_Irq_c_REF_17 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
                        should be effectively Boolean. Expressions that are effectively Boolean
                        should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).*/
                    /* @violates @ref Can_Irq_c_REF_18 Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be permitted.*/
                    CAN_RXFIFO_EVENTS_MB_MIX(C,15)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(C)
                        /* RX Fifo Overflow Interrupt*/
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(C)
                        /* Rx Fifo Warning Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(C)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(C, MB_00_15, 0U, 15U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_ISRS(C, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_OFF) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNIRXISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                    /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
                       converted to a different underlying type if:
                       (a) it is not a conversion to a wider integer type of the samesignedness, or
                       (b) the expression is complex, or
                       (c) the expression is not constant and is a function argument, or
                       (d) the expression is not constant and is a return expression*/
                    /* @violates @ref Can_Irq_c_REF_17 Violates MISRA 2004 Advisory Rule 12.6 , The operands of logical operators (&&, || and !) 
                        should be effectively Boolean. Expressions that are effectively Boolean
                        should not be used as operands to operators other than (&&, ||, !, =, ==, != and ?:).*/
                    /* @violates @ref Can_Irq_c_REF_18 Violates MISRA 2004 Required Rule 13.7 , Boolean operations whose results are invariant shall not be permitted.*/
                    CAN_RXFIFO_EVENTS_MB_MIX(C,15)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(C)
                        /* RX Fifo Overflow Interrupt*/
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(C)
                        /* Rx Fifo Warning Interrupt */
                        /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                        /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                        /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(C)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_RXISRS(C, MB_00_15, 0U, 15U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_RXISRS(C, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            CAN_MB_UNITXISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_15 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_TXISRS(C, MB_00_15, 0U, 15U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_7 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_8  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */    
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_15 Violates MISRA 2004 Advisory Rule 12.1 , This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed to the macro. */
                   /* @violates @ref Can_Irq_c_REF_16 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   CAN_MB_TXISRS(C, MB_16_31, 16U, 31U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCC_INDEX */

/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN D
==================================================================================================*/

#define CAN_STOP_SEC_CODE
/* @violates @ref Can_Irq_c_REF_3 MISRA 2004 Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Irq_c_REF_5 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
