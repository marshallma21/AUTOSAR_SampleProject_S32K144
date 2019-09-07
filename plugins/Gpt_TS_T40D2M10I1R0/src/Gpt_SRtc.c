/**
*   @file    Gpt_SRtc.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - SRTC driver source file.
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
* @section GPT_SRTC_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_SRTC_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_SRTC_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section GPT_SRTC_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_SRTC_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_SRTC_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
*
* @section GPT_SRTC_C_REF_7
* Violates MISRA 2004 Required Rule 19.4, Braces not used for some macros
* Braces are not used for macros which expand to multiple statements separated by ";" character.
*
* @section GPT_SRTC_C_REF_8
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section GPT_SRTC_C_REF_9
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used
* This comma operator was used for the side effect. The return value from called 
* was not evaluated
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
#include "Gpt_SRtc.h"
#include "Reg_eSys_SRtc.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_SRTC_VENDOR_ID_C                    43
/** @violates @ref GPT_SRTC_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_SRTC_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_SRTC_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_SRTC_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_SRTC_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_SRTC_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_SRTC_SW_MAJOR_VERSION_C             1
#define GPT_SRTC_SW_MINOR_VERSION_C             0
#define GPT_SRTC_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_SRTC_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_SRTC_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_SRtc.c and Std_Types.h are different"
    #endif
#endif

#if ( GPT_SRTC_VENDOR_ID_C!= GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_SRtc.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_SRTC_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_SRtc.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SRTC_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_SRTC_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_SRTC_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_SRtc.c and Gpt_Ipw_Irq.h are different"
#endif

#if (GPT_SRTC_VENDOR_ID_C!= GPT_SRTC_VENDOR_ID)
    #error "Gpt_SRtc.c and Gpt_SRtc.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_SRTC_AR_RELEASE_MAJOR_VERSION_C != GPT_SRTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_MINOR_VERSION_C != GPT_SRTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_REVISION_VERSION_C != GPT_SRTC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_SRtc.c and Gpt_SRtc.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SRTC_SW_MAJOR_VERSION_C != GPT_SRTC_SW_MAJOR_VERSION) || \
     (GPT_SRTC_SW_MINOR_VERSION_C != GPT_SRTC_SW_MINOR_VERSION) || \
     (GPT_SRTC_SW_PATCH_VERSION_C != GPT_SRTC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_SRtc.c and Gpt_SRtc.h are different"
#endif

#if ( GPT_SRTC_VENDOR_ID_C!= REG_ESYS_SRTC_VENDOR_ID)
    #error "Gpt_SRtc.c and Reg_eSys_SRtc.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_SRTC_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SRTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SRTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_SRTC_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SRTC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_SRtc.c and Reg_eSys_SRtc.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_SRTC_SW_MAJOR_VERSION_C != REG_ESYS_SRTC_SW_MAJOR_VERSION) || \
     (GPT_SRTC_SW_MINOR_VERSION_C != REG_ESYS_SRTC_SW_MINOR_VERSION) || \
     (GPT_SRTC_SW_PATCH_VERSION_C != REG_ESYS_SRTC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_SRtc.c and Reg_eSys_SRtc.h are different"
#endif


#if (GPT_SRTC_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_SRtc.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_SRTC_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
 (GPT_SRTC_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
 (GPT_SRTC_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION) \
)
    #error "AutoSar Version Numbers of Gpt_SRtc.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_SRTC_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
 (GPT_SRTC_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
 (GPT_SRTC_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION) \
)
    #error "Software Version Numbers of Gpt_SRtc.c and SilRegMacros.h are different"
#endif

#if (GPT_SRTC_USED == STD_ON)
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
#ifdef GPT_SRTC_SUPERVISER_BIT_AVAILABLE
/* @violates @ref GPT_SRTC_C_REF_8 MISRA 2004 Advisory Rule 19.7,  Use of function like macro */
/** @violates @ref GPT_SRTC_C_REF_7 MISRA 2004 Required Rule 19.4, Braces not used for some macros */
 #define Call_Gpt_SRtc_SetUserAccessAllowed() Mcal_Trusted_Call(Gpt_SRtc_SetUserAccessAllowed)
#else
/* @violates @ref GPT_SRTC_C_REF_8 MISRA 2004 Advisory Rule 19.7,  Use of function like macro */
/** @violates @ref GPT_SRTC_C_REF_7 MISRA 2004 Required Rule 19.4, Braces not used for some macros */
 #define Call_Gpt_SRtc_SetUserAccessAllowed()
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_32
/** @violates @ref GPT_SRTC_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_SRTC_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/**
* @brief     Variable used to store the runtime target time value.
* @violates @ref GPT_SRTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
static VAR(uint32, GPT_VAR) Gpt_SRtc_u32TargetValue = 0U;

#define GPT_STOP_SEC_VAR_INIT_32
/** @violates @ref GPT_SRTC_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_SRTC_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
/**
* @brief Highest possible value for SRTC channels
*/
#define GPT_SRTC_COUNT_MAX_VALUE_U32        ((uint32)0xFFFFFFFFUL)
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_SRTC_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_SRTC_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


#ifdef GPT_SRTC_0_CH_0_ISR_USED
ISR(Gpt_SRTC_0_Ch_0_ISR);
#endif /*GPT_SRTC_0_CH_0_ISR_USED*/

#if (GPT_SRTC_USED == STD_ON)
static FUNC (void, GPT_CODE) Gpt_SRtc_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif /*GPT_SRTC_USED == STD_ON*/
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

#if (GPT_SRTC_USED == STD_ON)
/**
* @brief   Driver routine to process all the interrupts of SRTC.
* @details Support function used by interrupt service routines to implement SRTC specific operations
*          and call the GPT upper layer handler to implement non-hardware specific operations.
*
* @param[in]     u8HwChannel     hardware channel index
*
* @implements   Gpt_SRtc_ProcessCommonInterrupt_Activity
*/
static FUNC(void, GPT_CODE) Gpt_SRtc_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint32, AUTOMATIC) u32OldTimeAlarm;
    VAR(uint32, AUTOMATIC) u32NextTimeAlarm;
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;
    
    /* Get Time Counter Enable Bit */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp1 = REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TCE_U32);
    /* Get Time Alarm Interrupt Flag Bit */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp2 = REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TAF_U32);
    /* Time Counter is enable and Time Alarm Flag is set */
    if ((u32Temp1 != (uint32)0U) && (u32Temp2 != (uint32)0U))
    {
        /* Get Old Time Alarm Value */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32OldTimeAlarm = REG_READ32(SRTC_TAR_ADDR32);
        /* Compute next Time Alarm */
        u32NextTimeAlarm = (uint32)(u32OldTimeAlarm + Gpt_SRtc_u32TargetValue);
        /* Set New Time Alarm, and this also clears the TAF flag */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(SRTC_TAR_ADDR32, u32NextTimeAlarm);
        
        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel,(uint8)GPT_SRTC_MODULE);
    }
}
#endif /*GPT_SRTC_USED == STD_ON*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef GPT_SRTC_SUPERVISER_BIT_AVAILABLE
/**
* @brief        Enables SRTC registers writing in User Mode
* @details      Sets the SUP (Supervisor access) bit of the SRTC IP allowing SRTC registers writing in User Mode
*
* @param[in]    none
*
* @return       none
*
* @pre          Should be executed in supervisor mode
* @post         none
* @violates @ref GPT_SRTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC( void, GPT_CODE) Gpt_SRtc_SetUserAccessAllowed()
{
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(SRTC_CR_ADDR32, SRTC_CR_SUP_U32);
}
#endif /* GPT_SRTC_SUPERVISER_BIT_AVAILABLE */

/**
* @brief   Gpt driver initialization function for SRtc module.
* @details This function:
*          - Disable the time counter
*          - Disable Time Alarm, Time Overflow, Time Invalid Interrupt
*          - Clear Time Invalid Flag 
*          - Select source Clock
*
*
* @param[in]     u8ClockSource     SRtc hw channel ID
*          - u8ClockSource = 0 : External Crystal (32kHz) clock is used
*          - Otherwise : LPO (1kHz) clock is used
*
*/
FUNC (void, GPT_CODE) Gpt_SRtc_Init(VAR(uint8, AUTOMATIC) u8ClockSource)
{
    /* Enables SRTC registers writing in User Mode */
    /** @violates @ref GPT_SRTC_C_REF_9 MISRA 2004 Required Rule 12.10, The comma operator shall not be used */
    Call_Gpt_SRtc_SetUserAccessAllowed();
    
    /*Disable time counter*/
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_SR_ADDR32, SRTC_SR_TCE_U32);
    /* When on POR, the TAIE, TOIE and TIIE are set */
    /* Disable Time Alarm Interrupt */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_IER_ADDR32, SRTC_IER_TAIE_U32);
    /* Disable Time Overflow Interrupt*/
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_IER_ADDR32, SRTC_IER_TOIE_U32);
    /* Disable Time Invalid Interrupt */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_IER_ADDR32, SRTC_IER_TIIE_U32);
    /* On POR, TIF is set. The TSR ans TPR do not increment. */
    /* Clear TIF flag by writing to TSR */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(SRTC_TSR_ADDR32, (uint32)0U);
    /*Select clock source */
    if (u8ClockSource != (uint8)0U)
    {
        /* LPO clock (1kHz) is used */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(SRTC_CR_ADDR32, SRTC_CR_LPOS_U32);
        /* Disable External Crytal (32kHz) clock*/
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(SRTC_CR_ADDR32, SRTC_CR_OSCE_U32);
    }
    else 
    {
        /* External Crystal (32kHz) clock is used */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(SRTC_CR_ADDR32, SRTC_CR_LPOS_U32);
        /* Enable Oscillator */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(SRTC_CR_ADDR32, SRTC_CR_OSCE_U32);        
    }
    /* Initialize local variables */
    Gpt_SRtc_u32TargetValue = 0U;
    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver de-initialization function for SRtc module.
* @details This function:
*          - All registers in SRTC moudle are affected by SOFTWARE RESET
*            except the CR[SWR] bit itseft and the Write Acces Register and the Read Access Register
*
*
*/
FUNC (void, GPT_CODE) Gpt_SRtc_DeInit(void)
{
    
    /* Software Reset*/
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(SRTC_CR_ADDR32, SRTC_CR_SWR_U32);
    /* Initialize local variables */
    Gpt_SRtc_u32TargetValue = 0U;
    /* Enables SRTC registers writing in User Mode */
    /** @violates @ref GPT_SRTC_C_REF_9 MISRA 2004 Required Rule 12.10, The comma operator shall not be used */
    Call_Gpt_SRtc_SetUserAccessAllowed();
    /* Clear Software Reset*/
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_CR_ADDR32, SRTC_CR_SWR_U32);
    return;
}
#endif /*GPT_DEINIT_API == STD_ON*/

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the SRtc timer channel.
* @details This function:
*          - Disable Time Counter and Time Alarm Functionality
*          - Sets the target time for alarming and also stores the value into local variable
*          - Enables Timer Alarm Interrupt
*          - Enable Time Counter
*
* @param[in]     u32Value          channel timeout value (in seconds)
*
*
*/
FUNC (void, GPT_CODE) Gpt_SRtc_StartTimer(VAR(uint32, AUTOMATIC) u32Value)
{
    VAR(uint32, AUTOMATIC) u32CounterValue;
    
    Gpt_SRtc_u32TargetValue = u32Value;
    /* Disable Time Counter */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_SR_ADDR32, SRTC_SR_TCE_U32);
    /* Disable Time Alarm Interrupt */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_IER_ADDR32, SRTC_IER_TAIE_U32);
    
    /* To update accurate value for SRTC_TAR_ADDR32, interrupts is suspended*/
    SuspendAllInterrupts();
    
    /* Get Time Counter Value */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32CounterValue = REG_READ32(SRTC_TSR_ADDR32);
    /* Compute the Next Time Alarm Value, the TAF is set when TAR==TSR and TSR "increments" */
    if (u32Value >= 1U)
    {
        u32CounterValue = u32CounterValue + (u32Value - 1UL);
    }
    /* Set Time Alarm Register, and also clear TAF */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(SRTC_TAR_ADDR32, u32CounterValue);
    
    ResumeAllInterrupts();
    
    /* Enable Timer Alarm Interrupt */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(SRTC_IER_ADDR32, SRTC_IER_TAIE_U32);
    /* Enable Time Counter */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(SRTC_SR_ADDR32, SRTC_SR_TCE_U32);
    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the SRtc timer channel.
* @details This function disables the SRTC channel
*
*/
FUNC (void, GPT_CODE) Gpt_SRtc_StopTimer(void)
{
    VAR(uint32, AUTOMATIC) u32TimeAlarmValue;
    
    /* Time Alarm Interrupt Disable */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_IER_ADDR32, SRTC_IER_TAIE_U32);
    /* Get current Timer Alarm Value */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32TimeAlarmValue = REG_READ32(SRTC_TAR_ADDR32);
    /* Make sure that the time alarm interrupt flag was pending cleared */
    /* Clear TAF by writing to the TAR register */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(SRTC_TAR_ADDR32, u32TimeAlarmValue);
    
#ifdef ERR_IPV_RTC_0001
#if STD_ON == ERR_IPV_RTC_0001
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if(REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TAF_U32))
    {
        /* Clear TAF by writing to the TAR register */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(SRTC_TAR_ADDR32, u32TimeAlarmValue);
    }
#endif
#endif

    /* Disable time counter*/
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_SR_ADDR32, SRTC_SR_TCE_U32);
    return;
}

/*================================================================================================*/

/**
* @brief   Gpt driver function for getting the time elapsed for an SRtc timer channel.
* @details This function:
*          - return the elapsed time for SRTC timer channel
*
* @param[out]    pbReturnChannelRollover    Interrupt status flag value
* @param[out]    pu32TargetValue            current target time value
*
* @return        Elapsed time since the last roll-over or start time.
*
*/ 
FUNC(uint32, GPT_CODE) Gpt_SRtc_GetTimeElapsed(P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                               P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue)
{
    VAR(uint32, AUTOMATIC) u32ReturnValue = 0U;
    VAR(uint32, AUTOMATIC) u32CounterValue;
    VAR(uint32, AUTOMATIC) u32TempValue;
    VAR(uint32, AUTOMATIC) u32TimeAlarmValue;
    /* Get Target Time */
    *pu32TargetValue = Gpt_SRtc_u32TargetValue;
    /* Get Time counter register */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32CounterValue = REG_READ32(SRTC_TSR_ADDR32);
    /* Get Time Alarm Register. Time Alarm was minus one at initial (StartTimer)*/
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32TimeAlarmValue = REG_READ32(SRTC_TAR_ADDR32) + 1UL;
    /* Calculate the elapsed time */
    if (u32CounterValue >= u32TimeAlarmValue)
    {
        /* The counter may be roll-over, but for this SRTC IP, tick frequency is always 1Hz.
         * So this might never be occurred.*/
        u32TempValue = (GPT_SRTC_COUNT_MAX_VALUE_U32 - u32CounterValue) + u32TimeAlarmValue + 1UL;
    }
    else 
    {
        u32TempValue = u32TimeAlarmValue - u32CounterValue;
    }
    
    if (u32TempValue > *pu32TargetValue)
    {
        u32ReturnValue = *pu32TargetValue;
    }
    else 
    {
        u32ReturnValue = *pu32TargetValue - u32TempValue;
    }
    
    /* Get time alarm flag */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32TempValue = REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TAF_U32);
    if (u32TempValue != 0U)
    {    
        /* Channel counter was rollover */
        *pbReturnChannelRollover = (boolean)TRUE;
    }
    else     
    {
        /* Channel counter was not rollover */
        *pbReturnChannelRollover = (boolean)FALSE;
    }
    return u32ReturnValue;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for enabling the SRtc timer channel IRQ.
* @details This function enables the IRQ corresponding to the SRtc timer channel
*
*/
FUNC (void, GPT_CODE) Gpt_SRtc_EnableInterrupt(void)
{
    VAR(uint32, AUTOMATIC) u32TimeAlarmValue;
    
    /* Get current Timer Alarm Value */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32TimeAlarmValue = REG_READ32(SRTC_TAR_ADDR32);
    /* Make sure that the time alarm interrupt flag was pending cleared */
    /* Clear TAF by writing to the TAR register */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(SRTC_TAR_ADDR32, u32TimeAlarmValue);
    
#ifdef ERR_IPV_RTC_0001
#if STD_ON == ERR_IPV_RTC_0001
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if(REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TAF_U32))
    {
        /* Clear TAF by writing to the TAR register */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(SRTC_TAR_ADDR32, u32TimeAlarmValue);
    }
#endif
#endif
    /* Time Alarm Interrupt Enable */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(SRTC_IER_ADDR32, SRTC_IER_TAIE_U32);
    return;
}

/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief   Gpt driver function for disabling the SRtc timer channel IRQ.
* @details This function: Clear Time Alarm Interrupt Flag and Disable the Interrupt
*
*/
FUNC (void, GPT_CODE) Gpt_SRtc_DisableInterrupt(void)
{
    VAR(uint32, AUTOMATIC) u32TimeAlarmValue;
    
    /* Time Alarm Interrupt Disable */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(SRTC_IER_ADDR32, SRTC_IER_TAIE_U32);
    /* Get current Timer Alarm Value */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32TimeAlarmValue = REG_READ32(SRTC_TAR_ADDR32);
    /* Make sure that the time alarm interrupt flag was pending cleared */
    /* Clear TAF by writing to the TAR register */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(SRTC_TAR_ADDR32, u32TimeAlarmValue);
    
#ifdef ERR_IPV_RTC_0001
#if STD_ON == ERR_IPV_RTC_0001
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if(REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TAF_U32))
    {
        /* Clear TAF by writing to the TAR register */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(SRTC_TAR_ADDR32, u32TimeAlarmValue);
    }
#endif
#endif
}
#endif

#ifdef GPT_SRTC_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for SRTC channels.
* @details Interrupt Service Routine corresponding to Gpt_SRTC_0_TIMER_0 hw channel.
*
* @isr
* @violates @ref GPT_SRTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_SRTC_0_Ch_0_ISR)
{
    VAR(uint32, AUTOMATIC) u32Temp1;
    /* Get Time Interrupt Flag Bits */
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Temp1 = REG_BIT_GET32(SRTC_SR_ADDR32, SRTC_SR_TIF_U32 | SRTC_SR_TAF_U32);
    /* Time Alarm Interrupt Occured */
    if ((u32Temp1 & SRTC_SR_TAF_U32) != 0U)
    {
        Gpt_SRtc_ProcessCommonInterrupt((uint8)SRTC_0_CH_0);
    }
    /* Time Invalid Occured */
    else if ((u32Temp1 & SRTC_SR_TIF_U32) != 0U)
    {
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(SRTC_CR_ADDR32, SRTC_CR_SWR_U32);
        /*Disable time counter*/
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(SRTC_SR_ADDR32, SRTC_SR_TCE_U32);
        /* Clear TIF flag by writing to TSR */
        /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(SRTC_TSR_ADDR32, (uint32)0U);
    }
    else 
    {
        /* Do Nothing */
    }
    /** @violates @ref GPT_SRTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_SRTC_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif /* GPT_SRTC_0_CH_0_ISR_USED */

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_SRTC_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_SRTC_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif/*GPT_SRTC_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

/** @} */
