/**
*   @file    Eth_Irq.c
*   @version 1.0.1
*
*  @brief    AUTOSAR Eth driver interrupt handlers
*  @details  Implementation of interrupt handling routines for the Ethernet
*            Driver.
*
*   @addtogroup ETH_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ENET
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
* @section Eth_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for 
* external identifiers. Name length of the macros is unfortunately longer than 
* 31 characters which is required by  the agreed macro format and cannot be 
* changed. 
*
* @section Eth_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Pointer to a function shall not be converted to anything
* else than integral type. This rule is not violated however the tool used for checks reports it
* therefore it must be commented here.*
*
* @section Eth_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. The APIs always require the external
* linkage. MISRA analysis tool does not see the linkage from upper layers
* therefore there is no violation.
*
* @section Eth_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth.h" /* Includes also Eth_GeneralTypes.h, Eth_Cfg.h, Eth_ENET_Counters.h, 
                    Eth_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "Eth_Ipw.h"     /* LLD driver API */
#include "Eth_Irq.h"     /* Own interface */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Eth_Irq_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Irq_c_REF_6 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_C    2
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if (ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth_Irq.c and Eth.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Eth_Irq.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_Irq.c and Eth.h are different"
#endif
/* Check if current file and Eth_Irq header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION_ETHIRQ) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION_ETHIRQ) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION_ETHIRQ))
    #error "AutoSar Version Numbers of Eth_Irq.c and Eth_Irq.h are different"
#endif
/* Check if current file and Eth_Irq header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION_ETHIRQ) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION_ETHIRQ) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION_ETHIRQ))
    #error "Software Version Numbers of Eth_Irq.c and Eth_Irq.h are different"
#endif

/* Check if current file and Eth_LLD header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION_ETHIPW_H) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION_ETHIPW_H) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION_ETHIPW_H))
    #error "AutoSar Version Numbers of Eth_Irq.c and Eth_Ipw.h are different"
#endif
/* Check if current file and Eth_LLD header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION_ETHIPW_H) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION_ETHIPW_H) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION_ETHIPW_H))
    #error "Software Version Numbers of Eth_Irq.c and Eth_Ipw.h are different"
#endif

#if STD_ON == ETH_DEM_EVENT_DETECT
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if current file and Dem header file are of the same version */
        #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (ETH_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Eth_Irq.c and Dem.h are different"
        #endif
    #endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* ETH_DEM_EVENT_DETECT */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and DET header file are of the same version */
    #if (ETH_DEV_ERROR_DETECT == STD_ON)
        #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (ETH_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Eth_Irq.c and Det.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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
    LOCAL_INLINE void Eth_RxIrqHdlr (CONST(uint8, AUTOMATIC) u8CtrlIdx);
    LOCAL_INLINE void Eth_TxIrqHdlr (CONST(uint8, AUTOMATIC) u8CtrlIdx);
    #if defined(ETH_COMBINED_IRQ_SCR) && (STD_ON == ETH_COMBINED_IRQ_SCR)
    LOCAL_INLINE void Eth_TxRxIrqHdlr (CONST(uint8, AUTOMATIC) u8CtrlIdx);
#endif

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
LOCAL_INLINE void Eth_TimerWrapIsr (CONST(uint8, AUTOMATIC) u8CtrlIdx);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ETH_START_SEC_CODE
/**
 * @violates @ref Eth_Irq_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Irq_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/**
* @brief         Reception interrupt handler for specific controller 
* @details       All receive buffers are checked and upper layers are notified
*                about received frames. Received data are passed to the upper
*                layers.
* @param[in]     u8CtrlIdx Index of controller to be processed
* @implements    Eth_ISR_Activity
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
    LOCAL_INLINE void Eth_RxIrqHdlr (CONST(uint8, AUTOMATIC) u8CtrlIdx)

{
    if(ETH_STATE_INIT != Eth_CtrlState[u8CtrlIdx])
    {
        /* Clear the interrupt flag to avoid isr flood on failure */
        Eth_Ipw_ClearRxInterruptFlag(u8CtrlIdx);

    }
    else
    {
        /* Check whether the interrupt flag is set */
        if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_IsRxInterruptFlagSet(u8CtrlIdx))
        {    
            /* Check whether the interrupt is enabled */
            if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_IsRxInterruptEnabled(u8CtrlIdx))
            {   /* The interrupt flag is set and the interrupt is enabled, 
                   proceed with the handler */
                /* Process the receive buffers.
                   This call also handles interrupt flags. */
                (void)Eth_Ipw_ReportReception(u8CtrlIdx, (VAR(boolean, AUTOMATIC))TRUE);
            }
        }
        /* else: The interrupt flag is not set however the handler has been
                 called. This may happen if the call is invalid or if an 
                 interrupt latched in the interrupt controller occurs after 
                 the global interrupt mask is again set (after being cleared) 
                 and if the flag was cleared in that time e.g. by the ethernet
                 controller reset */
        /* Clear RX interrupt flag anyway.
         * Rationalize: If the flag is read as clear even if it is set (HW fault),
         * it would lead to ISR flood */
        Eth_Ipw_ClearRxInterruptFlag(u8CtrlIdx); /* Clear the interrupt flag */

    }
}

/**
* @brief         Transmission interrupt handler for specific controller
* @details       All transmit buffers are checked and upper layers are notified
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
* @param[in]     u8CtrlIdx Index of controller to be processed
* @implements    Eth_ISR_Activity
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
LOCAL_INLINE void Eth_TxIrqHdlr (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(boolean, AUTOMATIC) bIrqFlagState;
    
    /* Interrupt flags have to be always cleared, even in case of error */
    bIrqFlagState = Eth_Ipw_IsTxInterruptFlagSet(u8CtrlIdx);
    Eth_Ipw_ClearTxInterruptFlag(u8CtrlIdx); /* Clear the interrupt flag */

    if(ETH_STATE_INIT == Eth_CtrlState[u8CtrlIdx])
    {
        /* Check whether the interrupt flag is set */
        if((VAR(boolean, AUTOMATIC))TRUE == bIrqFlagState)
        {    
            /* Check whether the interrupt is enabled */
            if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_IsTxInterruptEnabled(u8CtrlIdx))
            {   /* The interrupt flag is set and the interrupt is enabled, 
                proceed with the handler */
                /* There is no mean to report an error - ignore return value. 
                The interrupt flag has been already cleared at the function
                beginning */
                (void)Eth_Ipw_ReportTransmission(u8CtrlIdx);      
            }                
            /* else: The interrupt is disabled however the handler has been 
                    called. This may happen if the call is invalid or if the
                    interrupt occurred while global interrupt mask was cleared
                    and the peripheral interrupt mask was then cleared because
                    the interrupt request is still latched in the interrupt 
                    controller */
            /* The interrupt has been already cleared at function beginning */

            
        }
        /* else: The interrupt flag is not set however the handler has been
                called. This may happen if the call is invalid or if an 
                interrupt latched in the interrupt controller occurs after 
                the global interrupt mask is again set (after being cleared) 
                and if the flag was cleared in that time e.g. by the ethernet
                controller reset */
    }
}

#if defined(ETH_COMBINED_IRQ_SCR) && (STD_ON == ETH_COMBINED_IRQ_SCR)
/**
* @brief         Combined transmission and reception interrupt handler
*                for particular controller
* @note          This interrupt handler is primary intended only for devices
*                without transmit and receive interrupts separation
* @details       All transmit buffers are checked and upper layers are notified
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
*                All receive buffers are checked and upper layers are notified
*                about received frames. Received data are passed to the upper
*                layers.
* @param[in]     u8CtrlIdx Index of controller to be processed
* @implements    Eth_ISR_Activity
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
LOCAL_INLINE void Eth_TxRxIrqHdlr (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    VAR(boolean, AUTOMATIC) bTxIrqFlagState;
    VAR(boolean, AUTOMATIC) bRxIrqFlagState;
        /* Hold TXF locally */
    bTxIrqFlagState = Eth_Ipw_IsTxInterruptFlagSet(u8CtrlIdx);
    if ((VAR(boolean, automatic))TRUE == bTxIrqFlagState)
    {
        /* Clear TXF as soon as possible after function entry
         * to prevent flag vanishing of next queued interrupt */
        Eth_Ipw_ClearTxInterruptFlag(u8CtrlIdx);
    }
    /* Hold RXF locally */
    bRxIrqFlagState = Eth_Ipw_IsRxInterruptFlagSet(u8CtrlIdx);
    if ((VAR(boolean, automatic))TRUE == bRxIrqFlagState)
    {
        /* Clear RXF as soon as possible after function entry
         * to prevent flag vanishing of next queued interrupt */
        Eth_Ipw_ClearRxInterruptFlag(u8CtrlIdx);
    }
    if(ETH_STATE_INIT == Eth_CtrlState[u8CtrlIdx])
    {
        /* Check whether the interrupt flag is set */
        if((VAR(boolean, AUTOMATIC))TRUE == bTxIrqFlagState)
        {
            /* Check whether the interrupt is enabled */
            if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_IsTxInterruptEnabled(u8CtrlIdx))
            {
                (void)Eth_Ipw_ReportTransmission(u8CtrlIdx);
            }
        }
        /* Check whether the interrupt flag is set */
        if((VAR(boolean, AUTOMATIC))TRUE == bRxIrqFlagState)
        {
            /* Check whether the interrupt is enabled */
            if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_IsRxInterruptEnabled(u8CtrlIdx))
            {
                (void)Eth_Ipw_ReportReception(u8CtrlIdx, (VAR(boolean, AUTOMATIC))TRUE);
            }

        }
    }
}
#endif

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
/**
* @brief         Process timer-wrap event when using timestamps
* @details       When using time-stamp, the timer only support for nano-second part of time,
*                driver need to process with second part of time. In this IRQ, the value in second will be updated.
* @param[in]     u8CtrlIdx Index of controller to be processed
* @implements    Eth_ISR_Activity
*/
LOCAL_INLINE void Eth_TimerWrapIsr (CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    if(ETH_STATE_INIT == Eth_CtrlState[u8CtrlIdx])
    {
        if ((VAR(boolean,AUTOMATIC))TRUE == Eth_IPW_IsTimerWrapEvent(u8CtrlIdx))
        {
            if ((VAR(uint32, AUTOMATIC))0xFFFFFFFFU == Eth_LocalTime[u8CtrlIdx].seconds)
            {
                Eth_LocalTime[u8CtrlIdx].secondsHi++;
                Eth_LocalTime[u8CtrlIdx].seconds = 0U;
            }
            else
            {
                Eth_LocalTime[u8CtrlIdx].seconds++;
            }
        }
    }
    /* Clear interrupt flag anyway */
    Eth_IPW_ClearTimerWrapFlag(u8CtrlIdx);
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Reception interrupt handler for the controller 0
* @details       All receive buffers are checked and upper layers are notified
*                about received frames. Received data are passed to the upper
*                layers.
* @isr
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/

ISR(Eth_RxIrqHdlr_0)
{
    Eth_RxIrqHdlr((uint8)0U);
    /**
     * @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1
     */
    EXIT_INTERRUPT(); 
}

/*================================================================================================*/
/**
* @brief         Transmission interrupt handler for the controller 0
* @details       All transmit buffers are checked and upper layers are notified
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
* @isr
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
ISR(Eth_TxIrqHdlr_0)
{
    Eth_TxIrqHdlr((uint8)0U);
    /**
     * @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1
     */
    EXIT_INTERRUPT();     
}

/* This function is used only in ARM platform which doesnot have separated IRQ vectors */
#if defined(ETH_COMBINED_IRQ_SCR) && (STD_ON == ETH_COMBINED_IRQ_SCR)
/*================================================================================================*/
/**
* @brief         Combined transmission and reception interrupt handler
*                for the controller 0
* @note          This interrupt handler is primary intended only for devices
*                without transmit and receive interrupts separation
* @details       All transmit buffers are checked and upper layers are notified
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
*                All receive buffers are checked and upper layers are notified
*                about received frames. Received data are passed to the upper
*                layers.
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/

ISR(Eth_TxRxIrqHdlr_0)
{
    Eth_TxRxIrqHdlr((uint8)0U);
    /**
     * @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1
     */
    EXIT_INTERRUPT();
}
#endif


#if (1U < ETH_MAXCTRLS_SUPPORTED)
/**
* @brief         Reception interrupt handler for the controller 1
* @details       All receive buffers are checked and upper layers are notified
*                about received frames. Received data are passed to the upper
*                layers.
* @isr
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
ISR(Eth_RxIrqHdlr_1)
{
    Eth_RxIrqHdlr((uint8)1U);
    /**
     * @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1
     */
    EXIT_INTERRUPT(); 
}

/*================================================================================================*/
/**
* @brief         Transmission interrupt handler for the controller 1
* @details       All transmit buffers are checked and upper layers are notified
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
* @isr
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/

ISR(Eth_TxIrqHdlr_1)
{
    Eth_TxIrqHdlr((uint8)1U);
    /**
     * @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1
     */
    EXIT_INTERRUPT();     
}

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
/**
* @brief         Process timer-wrap event for the controller 1 when using timestamps
* @details       When using time-stamp, the timer only support for nano-second part of time,
*                driver need to process with second part of time. In this IRQ, the value in second will be updated.
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*
**/

ISR(Eth_TimerWrapIsr_1)
{
    Eth_TimerWrapIsr((uint8)1U);
    /** @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1 */
    EXIT_INTERRUPT();
}
#endif

/* This function is used only in ARM platform which doesnot have separated IRQ vectors */
#if defined(ETH_COMBINED_IRQ_SCR) && (STD_ON == ETH_COMBINED_IRQ_SCR)
/*================================================================================================*/
/**
* @brief         Combined transmission and reception interrupt handler
*                for the controller 1
* @note          This interrupt handler is primary intended only for devices
*                without transmit and receive interrupts separation
* @details       All transmit buffers are checked and upper layers are notified
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
*                All receive buffers are checked and upper layers are notified
*                about received frames. Received data are passed to the upper
*                layers.
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
ISR(Eth_TxRxIrqHdlr_1)
{
    Eth_TxRxIrqHdlr((uint8)1U);
    /**
     * @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1
     */
    EXIT_INTERRUPT();
}

#endif
#endif /* ETH_MAXCTRLS_SUPPORTED greater than 1*/

#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
/**
* @brief         Process timer-wrap event for the controller 0 when using timestamps
* @details       When using time-stamp, the timer only support for nano-second part of time,
*                driver need to process with second part of time. In this IRQ, the value in second will be updated.
* @violates @ref Eth_Irq_c_REF_5 MISRA 2004 Rule 8.10
*/
ISR(Eth_TimerWrapIsr_0)
{
    Eth_TimerWrapIsr((uint8)0U);
    /** @violates @ref Eth_Irq_c_REF_4 MISRA rule 11.1 */
    EXIT_INTERRUPT();
}
#endif
#define ETH_STOP_SEC_CODE
/**
 * @violates @ref Eth_Irq_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Irq_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
