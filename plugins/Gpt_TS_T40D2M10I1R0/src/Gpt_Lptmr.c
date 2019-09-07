/**
*   @file    Gpt_Lptmr.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - LPTMR driver source file.
*   @details Detailed file description (can be multiple lines).
*
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
* @section GPT_LPTMR_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_LPTMR_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_LPTMR_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section GPT_LPTMR_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_LPTMR_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_LPTMR_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Ipw_Irq.h"
#include "Gpt_Lptmr.h"
#include "Reg_eSys_Lptmr.h"
#include "SchM_Gpt.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_LPTMR_VENDOR_ID_C                    43
/** @violates @ref GPT_LPTMR_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_LPTMR_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_LPTMR_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_LPTMR_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_LPTMR_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_LPTMR_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_LPTMR_SW_MAJOR_VERSION_C             1
#define GPT_LPTMR_SW_MINOR_VERSION_C             0
#define GPT_LPTMR_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_LPTMR_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_Lptmr.c and Std_Types.h are different"
    #endif
#endif

#if ( GPT_LPTMR_VENDOR_ID_C!= GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_Lptmr.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Lptmr.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPTMR_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_LPTMR_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_LPTMR_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Lptmr.c and Gpt_Ipw_Irq.h are different"
#endif

#if (GPT_LPTMR_VENDOR_ID_C!= GPT_LPTMR_VENDOR_ID)
    #error "Gpt_Lptmr.c and Gpt_Lptmr.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION_C != GPT_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_MINOR_VERSION_C != GPT_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_REVISION_VERSION_C != GPT_LPTMR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Lptmr.c and Gpt_Lptmr.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPTMR_SW_MAJOR_VERSION_C != GPT_LPTMR_SW_MAJOR_VERSION) || \
     (GPT_LPTMR_SW_MINOR_VERSION_C != GPT_LPTMR_SW_MINOR_VERSION) || \
     (GPT_LPTMR_SW_PATCH_VERSION_C != GPT_LPTMR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Lptmr.c and Gpt_Lptmr.h are different"
#endif

#if ( GPT_LPTMR_VENDOR_ID_C!= REG_ESYS_LPTMR_VENDOR_ID)
    #error "Gpt_Lptmr.c and Reg_eSys_Lptmr.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Lptmr.c and Reg_eSys_Lptmr.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPTMR_SW_MAJOR_VERSION_C != REG_ESYS_LPTMR_SW_MAJOR_VERSION) || \
     (GPT_LPTMR_SW_MINOR_VERSION_C != REG_ESYS_LPTMR_SW_MINOR_VERSION) || \
     (GPT_LPTMR_SW_PATCH_VERSION_C != REG_ESYS_LPTMR_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Lptmr.c and Reg_eSys_Lptmr.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same vendor */
#if (GPT_LPTMR_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_Lptmr.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_LPTMR_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPTMR_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Lptmr.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_LPTMR_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (GPT_LPTMR_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (GPT_LPTMR_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Lptmr.c and SilRegMacros.h are different"
#endif

#if (GPT_LPTMR_USED == STD_ON)
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_LPTMR_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_LPTMR_C_REF_2 Repeated include file MemMap.h */

#include "Gpt_MemMap.h"

/**
* @brief   Gpt driver initialization function for Lptmr module.
* @details This function is called separately for each LPTMR hw channel corresponding to the configured
*          timer channels, and:
*          - enables the LPTMR module
*          - configures the freeze mode (enabled or disabled)
*          - disables the IRQ correpsonding to the LPTMR channel
*          - clears the (pending) interrupt flag corresponding to Lptmr channel
*          - disables the LPTMR timer channel
*          - clears the Load Value register correponding to the Lptmr channel.
*
*
* @param[in]     bFreezeEnable     indicates if the Freeze mode is enabled
*
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_Init(VAR(uint8, AUTOMATIC) u8ClockSource,
                                    VAR(uint8, AUTOMATIC) u8Prescaler
                                   )
{
    /* Stop Channel to Configure Channel. This shall be be executed before any other setup is made */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    
    /* Disable interrupts*/
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/ 
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

    /* Clear pending interrupts */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);

    /* Configures the mode of LPTMR is Time Counter */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/ 
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TMS_MASK_U32);

    /* Set Prescaler */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPTMR_PSR_ADDR32,LPTMR_PSR_PRESCALE_MASK_U32,(uint32)u8Prescaler << LPTMR_PSR_PRESCALE_SHIFT);
    
    /* Set Clock Source */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPTMR_PSR_ADDR32,LPTMR_PSR_PCS_MASK_U32,(uint32)u8ClockSource);
    
    /* Set Compare Value to 0 */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPTMR_CMR_ADDR32, 0xFFFFU);
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver de-initialization function for Lptmr module.
* @details This function is called separately for each LPTMR hw channel corresponding to the configured
*          timer channels, and:
*          - disables the LPTMR channel
*          - disables the freeze mode
*          - disables IRQ corresponding to Lptmr channel
*          - clears the (pending) interrupt flag corresponding to Lptmr channel
*
*/
FUNC (void, GPT_CODE) Gpt_Lptmr_DeInit()
{

    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);

    /* Disable channel interrupts*/
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

    /* Clear Interrupt Flag */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the Lptmr timer channel.
* @details This function:
*          - clears the (pending) interrupt flag corresponding to Lptmr channel
*          - disables the LPTMR timer channel
*          - sets the timeout value into the LPTMR timer channel register
*          - enables the LPTMR timer channel
*          - enables the IRQ corresponding to the LPTMR timer channel,if channel configured in One Shot mode.
*
* @param[in]     u32Value          channel timeout value
*
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_StartTimer(VAR(uint16, AUTOMATIC) u16Value)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    /* Disable LPTMR timer */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPTMR_CMR_ADDR32, u16Value);
    
    /* Enable LPTMR timer */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Lptmr timer channel.
* @details This function disables the LPTMR channel
*
*
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_StopTimer()
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01();
    /* Disable LPTMR timer */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    
    /* Clear interrupt flag */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01();
}

/*================================================================================================*/

/**
* @brief   Gpt driver function for getting the time elapsed for an Lptmr timer channel.
* @details This function:
*          - reads the LPTMR channel load register
*          - reads the LPTMR counter register
*          - depending on above it calculates and returns the elapsed time
*          - reads and return the interrupt status flag value
*          - reads and return the current target time value
*
* @param[out]    pbReturnChannelRollover    Interrupt status flag value
* @param[out]    pu32TargetValue            current target time value
*
* @return        Elapsed time since the last roll-over or start time.
*
*/
FUNC(uint32, GPT_CODE) Gpt_Lptmr_GetTimeElapsed(P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                                P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                               )
{
    VAR(uint32, AUTOMATIC) u32ReturnValue;

    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    *pu32TargetValue = REG_READ32(LPTMR_CMR_ADDR32);
    /* The Counter Register returns the current value of the LPTMR at the time this register was last written. */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPTMR_CNR_ADDR32, 0U);
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32ReturnValue = REG_READ32(LPTMR_CNR_ADDR32);
    
    /*Check interrupt status flag*/
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if (REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32))
    {
        /* Channel counter was roll-over */
        *pbReturnChannelRollover = (boolean)TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        *pbReturnChannelRollover = (boolean)FALSE;
    }
    
    return u32ReturnValue;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for enabling the Lptmr timer channel IRQ.
* @details This function enables the IRQ corresponding to the Lptmr timer channel
*
*
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_EnableInterrupt()
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02();
    /* Clear interrupt flag */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
    
    /* Enable LPTMR interrupt */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02();
}

/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief   Gpt driver function for disabling the Lptmr timer channel IRQ.
* @details This function disables the IRQ corresponding to the Lptmr timer channel
*
*
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_DisableInterrupt()
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06();
    /* Disable LPTMR interrupt */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06();
}
#endif


#if (GPT_SET_CLOCK_MODE == STD_ON)
/**
* @brief      The function changes the LPTMR prescaler value.
* @details    This function sets the LPTMR prescaler based on the input mode.
*
* @param[in]  u8Prescaler     prescaler value
*
* @pre     On/Off by the configuration parameter: GPT_SET_CLOCK_MODE_API
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_SetClockMode(VAR(uint8, AUTOMATIC) u8Prescaler)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03();
    /* Disable the LPTMR */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    /* set the prescaler with the wanted value */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPTMR_PSR_ADDR32,LPTMR_PSR_PRESCALE_MASK_U32,(uint32)u8Prescaler << LPTMR_PSR_PRESCALE_SHIFT);
    /* Enable the LPTMR */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03();
}
#endif /*GPT_SET_CLOCK_MODE == STD_ON*/

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief      The function start the Low Power Timer module.
* @details    This function start the Low Power Timer module.
*
* @param[in]  u8Prescaler      prescaler value
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_StartPredefTimer 
(
    VAR(uint8, AUTOMATIC) u8ClockSource, 
    VAR(uint8, AUTOMATIC) u8Prescaler
)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04();
    /* Setup the Control Register */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPTMR_CSR_ADDR32, \
                (uint32)((uint32)1U << LPTMR_CSR_TCF_SHIFT)   /* Clear Pending Flag Interrupt*/| \
                (uint32)((uint32)0U << LPTMR_CSR_TIE_SHIFT)   /* Disable Timer Interrupt */    | \
                (uint32)((uint32)1U << LPTMR_CSR_TFC_SHIFT)   /* CNR is reset on overflow */   | \
                (uint32)((uint32)0U << LPTMR_CSR_TMS_SHIFT)   /* Select Time Counter Mode */   | \
                (uint32)((uint32)0U << LPTMR_CSR_TEN_SHIFT)); /* Disable Timer */
    /* Setup Prescaler Register */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPTMR_PSR_ADDR32, \
                (uint32)((uint32)  u8Prescaler << LPTMR_PSR_PRESCALE_SHIFT) /* Set prescaler */              | \
                (uint32)((uint32)           0U << LPTMR_PSR_PBYP_SHIFT)     /* Prescaler/glitch is enable */ | \
                (uint32)((uint32)u8ClockSource << LPTMR_PSR_PCS_SHIFT));    /* Select Prescaler Clock source */
    /* Set Compare Value to 0xffff */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPTMR_CMR_ADDR32, 0xFFFFU);
    /* Enable Timer */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04();
}

/*================================================================================================*/
/**
* @brief      The function get time elapsed of the ETIMER predefined timer channel.
* @details    The function get time elapsed of the ETIMER predefined timer channel.
*
* @param[in]  u8hwChannel       hardware channel
* @param[in]  ePredefTimerType  Types of predef timer
*
*/
FUNC(uint32, GPT_CODE) Gpt_Lptmr_GetPredefTimerValue (VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType)
{
    VAR(uint32, AUTOMATIC)  u32ReturnValue = 0U;
    
    switch(ePredefTimerType)
    {
        case GPT_PREDEF_TIMER_1US_16BIT:
            /* The Counter Register returns the current value of the LPTMR at the time this register was last written. */
            /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(LPTMR_CNR_ADDR32, 0U);
            /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            u32ReturnValue = REG_READ32(LPTMR_CNR_ADDR32);
            break;
        case GPT_PREDEF_TIMER_1US_24BIT:
        case GPT_PREDEF_TIMER_1US_32BIT:
        case GPT_PREDEF_TIMER_100US_32BIT:
            break;
        default:
            /* 32bit timer */
            break;
    }
    
    return u32ReturnValue;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Low Power Timer module.
* @details This function:
*          - stop the timer
*
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_StopPredefTimer (void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05();
    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);

    /* Disable channel interrupts*/
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

    /* Clear Interrupt Flag */
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05();
}
#endif
#if (defined GPT_LPTMR_0_CH_0_ISR_USED)
/**
* @brief   Driver routine to process all the interrupts of LPTMR.
* @details Support function used by interrupt service routines to implement LPTMR specific operations
*          and call the GPT upper layer handler to implement non-hardware specific operations.
*
*
* @implements   Gpt_Lptmr_ProcessCommonInterrupt_Activity
* @violates @ref GPT_LPTMR_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Lptmr_ProcessCommonInterrupt(void)
{
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;
    
    /*Checks for spurious interrupts*/
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp1 = REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
    
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp2 = REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);
    
    if ((LPTMR_CSR_TCF_ON_U32 == (u32Temp1 >> LPTMR_CSR_TCF_SHIFT)) && \
        (LPTMR_CSR_TIE_ON_U32 == (u32Temp2 >> LPTMR_CSR_TIE_SHIFT)) \
       )
    {
        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(0U, (uint8)GPT_LPTMR_MODULE);
    }
    
    /*Clear interrupt flag*/
    /** @violates @ref GPT_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
}
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_LPTMR_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_LPTMR_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif/*GPT_LPTMR_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

/** @} */
