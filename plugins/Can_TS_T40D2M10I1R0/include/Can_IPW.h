/**
*   @file    Can_IPW.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Main header file - can include different IPV models.
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

#ifndef CAN_IPW_H
#define CAN_IPW_H

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
* @section CAN_IPW_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section CAN_IPW_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
* Precautions shall be taken in order to prevent the contents of a header file 
* being included twice This is not a violation since all header files are 
* protected against multiple inclusions
*
* @section CAN_IPW_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* Middle layer between AUTOSAR and hardware needs a way to map HLD
* functions to LLD functions.
*
* @section CAN_IPW_h_REF_4
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*
* @section CAN_IPW_h_REF_5
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section CAN_IPW_h_REF_6
* Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
* converted to a different underlying type if: 
*    a) it is not aconversion to a wider integer type of the same signedness, 
*    b) the expression is complex,
*    c) the expression is not constant and is a function argument,
*    d) the expression is not constant and is a return expression.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_Flexcan.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Can_IPW.h
*/
#define CAN_IPW_VENDOR_ID_H                    43
#define CAN_IPW_MODULE_ID_H                    80
#define CAN_IPW_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_IPW_AR_RELEASE_MINOR_VERSION_H     2
/*
* @violates @ref CAN_IPW_h_REF_1 Violates MISRA 2004 Advisory Rule 1.4
*/
#define CAN_IPW_AR_RELEASE_REVISION_VERSION_H  2
#define CAN_IPW_SW_MAJOR_VERSION_H             1
#define CAN_IPW_SW_MINOR_VERSION_H             0
#define CAN_IPW_SW_PATCH_VERSION_H             1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN configuration header file are of the same vendor */
#if (CAN_IPW_VENDOR_ID_H != CAN_VENDOR_ID_CFG)
#error "Can_IPW.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN configuration header file are of the same Autosar version */
#if ((CAN_IPW_AR_RELEASE_MAJOR_VERSION_H    != CAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (CAN_IPW_AR_RELEASE_MINOR_VERSION_H    != CAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (CAN_IPW_AR_RELEASE_REVISION_VERSION_H != CAN_AR_RELEASE_REVISION_VERSION_CFG_H))
#error "AutoSar Version Numbers of Can_IPW.h and Can_Cfg.h are different"
#endif
/* Check if current file and CAN configuration header file are of the same software version */
#if ((CAN_IPW_SW_MAJOR_VERSION_H != CAN_SW_MAJOR_VERSION_CFG_H) || \
     (CAN_IPW_SW_MINOR_VERSION_H != CAN_SW_MINOR_VERSION_CFG_H) || \
     (CAN_IPW_SW_PATCH_VERSION_H != CAN_SW_PATCH_VERSION_CFG_H))
#error "Software Version Numbers of Can_IPW.h and Can_Cfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
    #define     CAN_NULL_OFFSET      (FLEXCAN_NULL_OFFSET_U8)
    #define     CAN_FD_ENABLE_U32    (FLEXCAN_MCR_FDEN_U32)

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Can_IPW_ProcessRx( controller, mbindex_start, mbindex_end )                              (Can_FlexCan_ProcessRx( (controller), (mbindex_start), (mbindex_end)) )

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Can_IPW_ProcessTx(controller, mbindex_start, mbindex_end)                                (Can_FlexCan_ProcessTx( (controller), (mbindex_start), (mbindex_end)) )
 
#if (CAN_RXFIFO_ENABLE == STD_ON)

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Can_IPW_RxFifoFrameAvNotif(controller)                                                    (Can_FlexCan_RxFifoFrameAvNotif( controller))
 
#endif

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Can_IPW_ProcessBusOff(controller)                                                         (Can_FlexCan_ProcessBusOff( controller))

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_InitVariables()                                                   (Can_FlexCan_InitVariables())

#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
/* There is not the register of the Can controller under protection in this platform, thus this macro points to NULL_PTR*/
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/* @violates @ref CAN_IPW_h_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
        #define         Can_IPW_SetUserAccessAllowed()         Mcal_Trusted_Call(Can_FlexCan_SetUserAccessAllowed)
#endif

#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/* @violates @ref CAN_IPW_h_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
/* @violates @ref CAN_IPW_h_REF_6 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        #define         Can_IPW_InitController(Controller)               Mcal_Trusted_Call_Return1param(Can_FlexCan_InitController,(Controller))
#else                                          
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_InitController(Controller)                                        (Can_FlexCan_InitController(Controller))
#endif

#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/* @violates @ref CAN_IPW_h_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
/* @violates @ref CAN_IPW_h_REF_6 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        #define         Can_IPW_SetControllerMode(Controller, pCanControlerDescriptor, Transition, canif_notification_required) \
                         Mcal_Trusted_Call_Return4param(Can_FlexCan_SetControllerMode,(Controller), (pCanControlerDescriptor), (Transition), (canif_notification_required))
#else
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_SetControllerMode(Controller, pCanControlerDescriptor, Transition, canif_notification_required) \
                        (Can_FlexCan_SetControllerMode((Controller), (pCanControlerDescriptor), (Transition), (canif_notification_required)))
#endif

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_DisableControllerInterrupts(Controller) \
                        (Can_FlexCan_DisableControllerInterrupts((Controller)))

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_EnableControllerInterrupts(Controller, pCanControlerDescriptor) \
                        (Can_FlexCan_EnableControllerInterrupts((Controller), (pCanControlerDescriptor)))

    #if ((CAN_API_ENABLE_ABORT_MB == STD_ON))  
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_Cancel(controller, mbindex)                                       (Can_FlexCan_Cancel((controller), (mbindex)))
    #endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */
    
    #if ((CAN_API_ENABLE_ABORT_MB == STD_ON))

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_AbortMb(Hth)                                                      (Can_FlexCan_AbortMb(Hth))
    #endif /* (CAN_API_ENABLE_ABORT_MB == STD_ON) */
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define         Can_IPW_Write(Hth, PduInfo)                                               (Can_FlexCan_Write((Hth), (PduInfo)))
    
    #if (CAN_TXPOLL_SUPPORTED == STD_ON)

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_MainFunctionWrite()                                               (Can_FlexCan_MainFunctionWrite())

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_MainFunctionMultipleWritePoll(writepoll)                          (Can_FlexCan_MainFunctionMultipleWritePoll(writepoll))
    #endif
    
    #if (CAN_RXPOLL_SUPPORTED == STD_ON)
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_MainFunctionRead()                                                (Can_FlexCan_MainFunctionRead())

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_MainFunctionMultipleReadPoll(readpoll)                            (Can_FlexCan_MainFunctionMultipleReadPoll(readpoll))
    #endif


#if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/* @violates @ref CAN_IPW_h_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
        #define         Can_IPW_MainFunctionMode()                              Mcal_Trusted_Call(Can_FlexCan_MainFunctionMode)
#else        
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_MainFunctionMode()                                                (Can_FlexCan_MainFunctionMode())
#endif

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_CheckBusOff(controller)                                           (Can_FlexCan_CheckBusOff(controller))
    
    #if (CAN_DUAL_CLOCK_MODE == STD_ON)

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_SetClockMode(u8Controller, can_clk_mode)                        (Can_FlexCan_SetClockMode((u8Controller), (can_clk_mode)))
    #endif

    
#if(CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    #if (STD_ON == CAN_ENABLE_USER_MODE_SUPPORT)
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
/* @violates @ref CAN_IPW_h_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
/* @violates @ref CAN_IPW_h_REF_6 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        #define         Can_IPW_SetIcomConfiguration( u8Controller, u8ConfigIcomIndex)         Mcal_Trusted_Call_Return2param(Can_FlexCan_SetIcomConfig,  (u8Controller), (u8ConfigIcomIndex))
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */     
/* @violates @ref CAN_IPW_h_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
/* @violates @ref CAN_IPW_h_REF_6 Violates MISRA 2004 Required Rule 10.1 , Prohibited Implicit Conversion: Non-constant argument to function, Implicit conversion of integer to smaller type */
        #define         Can_IPW_DeactivateIcomConfiguration(u8Controller)                      Mcal_Trusted_Call_Return1param(Can_FlexCan_DeactivateIcom, (u8Controller))
    #else
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_SetIcomConfiguration( u8Controller, u8ConfigIcomIndex)                                 (Can_FlexCan_SetIcomConfig( (u8Controller), (u8ConfigIcomIndex)))
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */     
        #define         Can_IPW_DeactivateIcomConfiguration(u8Controller)                                               (Can_FlexCan_DeactivateIcom(u8Controller))
    #endif

/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
        #define         Can_IPW_ProcessWakeupPN(u8controller)                                   (Can_FlexCan_ProcessWakeupPN(u8controller))
#else
#if(CAN_UNIFIED_INTERRUPTS == STD_ON)
/* @violates @ref CAN_IPW_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
        #define         Can_IPW_ProcessWakeupPN(u8controller)
#endif
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref  CAN_IPW_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Can_MemMap.h"

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref  CAN_IPW_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Can_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/* @violates @ref  CAN_IPW_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Can_MemMap.h"
#define CAN_STOP_SEC_CODE
/* @violates @ref  CAN_IPW_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include files */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
