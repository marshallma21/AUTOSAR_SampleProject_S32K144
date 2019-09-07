/**
*   @file    Gpt_LPit.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - LPIT driver source file.
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
* @section GPT_LPIT_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_LPIT_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_LPIT_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section GPT_LPIT_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_LPIT_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_LPIT_C_REF_6
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
#include "Gpt_LPit.h"
#include "Reg_eSys_LPit.h"
#include "SchM_Gpt.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_LPIT_VENDOR_ID_C                    43
/** @violates @ref GPT_LPIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_LPIT_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_LPIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_LPIT_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_LPIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_LPIT_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_LPIT_SW_MAJOR_VERSION_C             1
#define GPT_LPIT_SW_MINOR_VERSION_C             0
#define GPT_LPIT_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_LPIT_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_LPIT_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_LPit.c and Std_Types.h are different"
    #endif
#endif

#if ( GPT_LPIT_VENDOR_ID_C!= GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_LPit.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPIT_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPIT_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_LPIT_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_LPIT_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_LPit.c and Gpt_Ipw_Irq.h are different"
#endif

#if (GPT_LPIT_VENDOR_ID_C!= GPT_LPIT_VENDOR_ID)
    #error "Gpt_LPit.c and Gpt_LPit.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPIT_AR_RELEASE_MAJOR_VERSION_C != GPT_LPIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_MINOR_VERSION_C != GPT_LPIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_REVISION_VERSION_C != GPT_LPIT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit.c and Gpt_LPit.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPIT_SW_MAJOR_VERSION_C != GPT_LPIT_SW_MAJOR_VERSION) || \
     (GPT_LPIT_SW_MINOR_VERSION_C != GPT_LPIT_SW_MINOR_VERSION) || \
     (GPT_LPIT_SW_PATCH_VERSION_C != GPT_LPIT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_LPit.c and Gpt_LPit.h are different"
#endif

#if ( GPT_LPIT_VENDOR_ID_C!= REG_ESYS_LPIT_VENDOR_ID)
    #error "Gpt_LPit.c and Reg_eSys_LPit.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_LPIT_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit.c and Reg_eSys_LPit.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_LPIT_SW_MAJOR_VERSION_C != REG_ESYS_LPIT_SW_MAJOR_VERSION) || \
     (GPT_LPIT_SW_MINOR_VERSION_C != REG_ESYS_LPIT_SW_MINOR_VERSION) || \
     (GPT_LPIT_SW_PATCH_VERSION_C != REG_ESYS_LPIT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_LPit.c and Reg_eSys_LPit.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same vendor */
#if (GPT_LPIT_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_LPit.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_LPIT_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_LPIT_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_LPit.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_LPIT_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (GPT_LPIT_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (GPT_LPIT_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_LPit.c and SilRegMacros.h are different"
#endif

#if (GPT_LPIT_USED == STD_ON)

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

#define GPT_START_SEC_CODE
/** @violates @ref GPT_LPIT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_LPIT_C_REF_2 Repeated include file MemMap.h */

#include "Gpt_MemMap.h"

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#if ((GPT_LPIT_USED == STD_ON) || (defined GPT_LPIT_0_ISR_USED))

/**
* @brief   Driver routine to process all the interrupts of LPIT.
* @details Support function used by interrupt service routines to implement LPIT specific operations
*          and call the GPT upper layer handler to implement non-hardware specific operations.
*
* @param[in]     u8ModuleIdx      hardware module index
* @param[in]     u8ChannelIdx     hardware channel index
*
* @implements   Gpt_LPit_ProcessCommonInterrupt_Activity
* @violates @ref GPT_LPIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_LPit_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    /*Checks for spurious interrupts*/
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp1 = (uint32)(REG_BIT_GET32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << u8ChannelIdx)) >> u8ChannelIdx);
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp2 = (uint32)(REG_BIT_GET32(LPIT_MIER_ADDR32(u8ModuleIdx), (LPIT_MIER_TIE_MASK_U32 << u8ChannelIdx)) >> u8ChannelIdx);

    if ((LPIT_TFLG_TIF_ON_U32 == u32Temp1) && ((uint32)LPIT_TCTRL_TIE_ON_U32 == u32Temp2))
    {
        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel, (uint8)GPT_LPIT_MODULE);
    }

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07();
    /*Clear interrupt flag*/
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32  << u8ChannelIdx));
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07();
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver initialization function for LPit module.
* @details This function is called separately for each LPIT hw channel corresponding to the configured
*          timer channels, and:
*          - enables the LPIT module
*          - configures the freeze mode (enabled or disabled)
*          - disables the IRQ correpsonding to the LPIT channel
*          - clears the (pending) interrupt flag corresponding to LPit channel
*          - disables the LPIT timer channel
*          - clears the Load Value register correponding to the LPit channel.
*
*
* @param[in]     u8HwChannel        LPit hw channel ID
* @param[in]     bFreezeEnable     indicates if the Freeze mode is enabled
*/
FUNC(void, GPT_CODE) Gpt_LPit_Init(
    VAR(uint8, AUTOMATIC) u8HwChannel, 
#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
    VAR(uint32, AUTOMATIC) uTimerTriggerConfig,
#endif
    VAR(boolean, AUTOMATIC) bFreezeEnable)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPIT_MCR_ADDR32((uint32)u8ModuleIdx), LPIT_MCR_MCEN_MASK_U32);

    /* Stop Channel to Configure Channel */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_TCTRL_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx),(uint32)LPIT_TCTRL_TEN_MASK_U32);

#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
    /* Configures Trigger */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_TCTRL_ADDR32(u8ModuleIdx,u8ChannelIdx), uTimerTriggerConfig);
#endif
    /* Config LPIT Mode as periodic counters */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPIT_TCTRL_ADDR32(u8ModuleIdx,u8ChannelIdx), LPIT_TCTRL_MODE_MASK_U32, (uint32)0U);
    
    /* Disable interrupts*/
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_MIER_ADDR32((uint32)u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << ((uint32)u8ChannelIdx)));

    /* Clear pending interrupts */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_MSR_ADDR32((uint32)u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << ((uint32)u8ChannelIdx)));

    /* Set Compare Value to 0 */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_TVAL_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx), 0xFFFFFFFFU);
    
    if ((boolean)TRUE == bFreezeEnable)
    {
        /* Lpit freeze enable*/
        /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_MCR_ADDR32((uint32)u8ModuleIdx), LPIT_MCR_FRZ_MASK_U32);
    }
    else
    {
        /* Lpit freeeze disable */
        /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPIT_MCR_ADDR32((uint32)u8ModuleIdx), LPIT_MCR_FRZ_MASK_U32);
    }
    
    return;
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Gpt driver de-initialization function for LPit module.
* @details This function is called separately for each LPIT hw channel corresponding to the configured
*          timer channels, and:
*          - disables the LPIT channel
*          - disables the freeze mode
*          - disables IRQ corresponding to LPit channel
*          - clears the (pending) interrupt flag corresponding to LPit channel
*
* @param[in]     u8HwChannel        LPit hw channel ID
*
*/
/*================================================================================================*/
FUNC(void, GPT_CODE) Gpt_LPit_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPIT_MCR_ADDR32((uint32)u8ModuleIdx), LPIT_MCR_MCEN_MASK_U32);
    
    /* Reset Status and Control Register */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_TCTRL_ADDR32(((uint32)u8ModuleIdx),((uint32)u8ChannelIdx)),(uint32)LPIT_TCTRL_TEN_MASK_U32);
    
    /* Config LPIT Mode as periodic counters */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPIT_TCTRL_ADDR32(u8ModuleIdx, u8ChannelIdx), LPIT_TCTRL_MODE_MASK_U32, (uint32)0U);
    
    /* Disable channel interrupts*/
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_MIER_ADDR32((uint32)u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << ((uint32)u8ChannelIdx)));

    /* Clear Interrupt Flag */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_MSR_ADDR32((uint32)u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << ((uint32)u8ChannelIdx)));

    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_MCR_ADDR32((uint32)u8ModuleIdx), LPIT_MCR_FRZ_MASK_U32);

    /* Disable hardware module clock */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_MCR_ADDR32((uint32)u8ModuleIdx),LPIT_MCR_MCEN_MASK_U32);

    return;
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the LPit timer channel.
* @details This function:
*          - clears the (pending) interrupt flag corresponding to LPit channel
*          - disables the LPIT timer channel
*          - sets the timeout value into the LPIT timer channel register
*          - enables the LPIT timer channel
*          - enables the IRQ corresponding to the LPIT timer channel,if channel configured in One Shot mode.
*
* @param[in]     u8HwChannel        LPit hw channel ID
* @param[in]     u32Value          channel timeout value
* @param[in]     eChannelMode      One Shot or Continous
*
*
*/
/*================================================================================================*/
FUNC(void, GPT_CODE) Gpt_LPit_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08();
    /* Lpit timer disable */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_TCTRL_ADDR32(((uint32)u8ModuleIdx),((uint32)u8ChannelIdx)),(uint32)LPIT_TCTRL_TEN_MASK_U32);
    
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_TVAL_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx),u32Value);
    
    /* Lpit timer enable */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPIT_TCTRL_ADDR32(((uint32)u8ModuleIdx),((uint32)u8ChannelIdx)),(uint32)LPIT_TCTRL_TEN_MASK_U32);
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08();
    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the LPit timer channel.
* @details This function disables the LPIT channel
*
* @param[in]     u8HwChannel        LPit hw channel ID
*
*
*/
/*================================================================================================*/
FUNC(void, GPT_CODE) Gpt_LPit_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14();
    /* Lpit timer disable */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_TCTRL_ADDR32(((uint32)u8ModuleIdx),((uint32)u8ChannelIdx)),(uint32)LPIT_TCTRL_TEN_MASK_U32);
    
    /* Clear interrupt flag */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_MSR_ADDR32((uint32)u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << ((uint32)u8ChannelIdx)));
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14();
    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for getting the time elapsed for an LPit timer channel.
* @details This function:
*          - reads the LPIT channel load register
*          - reads the LPIT counter register
*          - depending on above it calculates and returns the elapsed time
*          - reads and return the interrupt status flag value
*          - reads and return the current target time value
*
* @param[in]     u8HwChannel                LPit hw channel ID
* @param[out]    pbReturnChannelRollover    Interrupt status flag value
* @param[out]    pu32TargetValue            current target time value
*
* @return        Elapsed time since the last roll-over or start time.
*
*/
/*================================================================================================*/
FUNC(uint32, GPT_CODE) Gpt_LPit_GetTimeElapsed(VAR(uint8, AUTOMATIC) u8HwChannel,
                                              P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                              P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                             )
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    VAR(uint32, AUTOMATIC)  u32ReturnValue;
    
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    *pu32TargetValue = REG_READ32(LPIT_TVAL_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx));
    
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32ReturnValue = *pu32TargetValue - REG_READ32(LPIT_CVAL_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx));
    
    /*Check interrupt status flag*/
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if (REG_BIT_GET32(LPIT_MSR_ADDR32((uint32)u8ModuleIdx), LPIT_MSR_TIF_MASK_U32 << ((uint32)u8ChannelIdx)))
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
* @brief   Gpt driver function for enabling the LPit timer channel IRQ.
* @details This function enables the IRQ corresponding to the LPit timer channel
*
* @param[in]     u8HwChannel        LPit hw channel ID
*
*
*/
/*================================================================================================*/
FUNC(void, GPT_CODE) Gpt_LPit_EnableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15();
    /* Clear interrupt flag */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_MSR_ADDR32((uint32)u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << ((uint32)u8ChannelIdx)));
    
    /* Enable interrupt */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPIT_MIER_ADDR32((uint32)u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << ((uint32)u8ChannelIdx)));
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15();
    return;
}

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/*================================================================================================*/
/**
* @brief   Gpt driver function for disabling the LPit timer channel IRQ.
* @details This function disables the IRQ corresponding to the LPit timer channel
*
* @param[in]     u8HwChannel        LPit hw channel ID
*
*
*/
/*================================================================================================*/
FUNC(void, GPT_CODE) Gpt_LPit_DisableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16();
    /* Clear Lpit interrupt flag */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPIT_MIER_ADDR32((uint32)u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << ((uint32)u8ChannelIdx)));
    
    /* Disable Lpit interrupt */
    /** @violates @ref GPT_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_LPIT_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(LPIT_MSR_ADDR32((uint32)u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << ((uint32)u8ChannelIdx)));
    
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16();
}
#endif


#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_LPIT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_LPIT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif/*GPT_LPIT_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

/** @} */
