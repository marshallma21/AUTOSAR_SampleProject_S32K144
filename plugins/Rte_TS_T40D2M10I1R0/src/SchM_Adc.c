/**
*   @file    SchM_Adc.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Rte - module implementation
*   @details his module implements stubs for the AUTOSAR Rte
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup RTE_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
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

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
#include "SchM_Adc.h"
#ifdef MCAL_TESTING_ENVIRONMENT
#include "EUnit.h" /* EUnit Test Suite */
#endif

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        #define ISR_STATE_MASK     ((uint32)0x00000002UL)   /**< @brief DAIF bit I and F */
    #else 
        #define ISR_STATE_MASK     ((uint32)0x00000001UL)   /**< @brief PRIMASK bit 0 */
    #endif 
#else
    #ifdef MCAL_PLATFORM_S12
        #define ISR_STATE_MASK     ((uint32)0x00000010UL)   /**< @brief I bit of CCR */
    #else
        #define ISR_STATE_MASK     ((uint32)0x00008000UL)   /**< @brief EE bit of MSR */
    #endif
#endif
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) != (uint32)3)
    #else
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
    #endif    
#else
    #ifdef MCAL_PLATFORM_S12
        #define ISR_ON(msr)            (uint32)(((uint32)(msr) & (uint32)(ISR_STATE_MASK)) == (uint32)0)
    #else
        #define ISR_ON(msr)            (uint32)((uint32)(msr) & (uint32)(ISR_STATE_MASK))
    #endif
#endif

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
static uint32 msr_00;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_01;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_02;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_03;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_04;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_05;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_06;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_07;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_08;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_09;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_10;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_11;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_12;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_13;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_14;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_15;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_16;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_17;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_18;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_19;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_20;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_21;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_22;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_23;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_24;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_25;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_26;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_27;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_28;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_29;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_30;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_31;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_32;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_33;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_34;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_35;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_36;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_37;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_38;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_39;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_40;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_41;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_42;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_43;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_44;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_45;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_46;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_47;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_48;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_49;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_50;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_51;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_52;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_53;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_54;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_55;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_56;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_57;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_58;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_59;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_60;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_61;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_62;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_63;    /**< @brief exclusive area MSR state upon entering*/
static uint32 msr_64;    /**< @brief exclusive area MSR state upon entering*/
static volatile uint32 reentry_guard_00 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_01 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_02 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_03 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_04 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_05 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_06 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_07 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_08 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_09 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_10 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_11 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_12 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_13 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_14 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_15 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_16 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_17 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_18 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_19 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_20 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_21 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_22 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_23 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_24 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_25 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_26 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_27 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_28 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_29 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_30 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_31 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_32 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_33 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_34 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_35 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_36 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_37 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_38 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_39 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_40 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_41 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_42 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_43 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_44 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_45 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_46 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_47 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_48 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_49 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_50 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_51 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_52 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_53 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_54 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_55 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_56 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_57 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_58 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_59 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_60 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_61 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_62 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_63 = 0; /**< @brief guard for the msr variable against overwrite*/
static volatile uint32 reentry_guard_64 = 0; /**< @brief guard for the msr variable against overwrite*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#ifndef _COSMIC_C_S32K14x_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void); 
#endif /*ifndef _COSMIC_C_S32K14x_*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (defined(_GREENHILLS_C_S32K14x_) || defined(_DIABDATA_C_S32K14x_) || defined(_CODEWARRIOR_C_S32K14x_))
/*================================================================================================*/
/** 
* @brief   This macro returns the MSR register value (32 bits). 
* @details This macro function implementation returns the MSR register value in r3 (32 bits). 
*     
* @pre  None
* @post None
* 
*/
#ifdef MCAL_PLATFORM_ARM
#if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
ASM_KEYWORD FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    mrs x0, S3_3_c4_c2_1
}
#else
ASM_KEYWORD FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    mrs r0, PRIMASK
}
#endif
#else
#ifdef MCAL_PLATFORM_S12
ASM_KEYWORD FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
   tfr ccr, d6
}
#else
ASM_KEYWORD FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    mfmsr r3
}
#endif
#endif
#endif /*#ifdef GHS||DIAB||CW*/

#ifdef _COSMIC_C_S32K14x_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/

#ifdef MCAL_PLATFORM_S12
    #define Adc_schm_read_msr()  ASM_KEYWORD("tfr ccr, d6")
#else
    #define Adc_schm_read_msr() ASM_KEYWORD("mfmsr r3")
#endif

#endif  /*Cosmic compiler only*/


#ifdef _HITECH_C_S32K14x_
/*================================================================================================*/
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    uint32 result;
    __asm volatile("mfmsr %0" : "=r" (result) :);
    return result;
}

#endif  /*HighTec compiler only*/
 /*================================================================================================*/
#ifdef _LINARO_C_S32K14x_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        __asm volatile( " mrs %x0, DAIF " : "=r" (reg_tmp) );
    #else
        __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
    #endif
    return (uint32)reg_tmp;
}
#endif   /* _LINARO_C_S32K14x_*/
/*================================================================================================*/

#ifdef _ARM_DS5_C_S32K14x_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;
    #if (MCAL_PLATFORM_ARM == MCAL_ARM_AARCH64)
        __asm volatile( " mrs %x0, DAIF " : "=r" (reg_tmp) );
    #else
        __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
    #endif
    return (uint32)reg_tmp;
}
#endif   /* _ARM_DS5_C_S32K14x_ */

#ifdef _IAR_C_S32K14x_
/** 
* @brief   This function returns the MSR register value (32 bits). 
* @details This function returns the MSR register value (32 bits). 
*     
* @param[in]     void        No input parameters
* @return        uint32 msr  This function returns the MSR register value (32 bits). 
* 
* @pre  None
* @post None
* 
*/
FUNC(uint32, RTE_CODE) Adc_schm_read_msr(void)
{
    register uint32 reg_tmp;
   
   __asm volatile( " mrs %0, primask " : "=r" (reg_tmp) );
   
    return (uint32)reg_tmp;
}
#endif   /* _IAR_C_S32K14x_ */
/*================================================================================================*/
/** 
* @brief   This function is called to allow ADC to enter the specific critical region. 
* @details This is a local function stub only. 
*     
* @param[in]     void     No input parameters
* @return        void     This function does not return anything
* 
* @pre  None
* @post None
* 
*/
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_00(void)
{
    if(0UL == reentry_guard_00)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_00 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_00 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_00)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_00++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_01(void)
{
    if(0UL == reentry_guard_01)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_01 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_01 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_01)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_01++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_02(void)
{
    if(0UL == reentry_guard_02)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_02 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_02 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_02)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_02++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03(void)
{
    if(0UL == reentry_guard_03)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_03 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_03 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_03)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_03++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_04(void)
{
    if(0UL == reentry_guard_04)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_04 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_04 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_04)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_04++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05(void)
{
    if(0UL == reentry_guard_05)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_05 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_05 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_05)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_05++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06(void)
{
    if(0UL == reentry_guard_06)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_06 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_06 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_06)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_06++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_07(void)
{
    if(0UL == reentry_guard_07)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_07 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_07 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_07)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_07++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08(void)
{
    if(0UL == reentry_guard_08)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_08 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_08 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_08)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_08++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09(void)
{
    if(0UL == reentry_guard_09)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_09 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_09 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_09)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_09++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10(void)
{
    if(0UL == reentry_guard_10)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_10 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_10 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_10)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_10++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11(void)
{
    if(0UL == reentry_guard_11)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_11 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_11 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_11)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_11++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_12(void)
{
    if(0UL == reentry_guard_12)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_12 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_12 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_12)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_12++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13(void)
{
    if(0UL == reentry_guard_13)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_13 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_13 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_13)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_13++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14(void)
{
    if(0UL == reentry_guard_14)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_14 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_14 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_14)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_14++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15(void)
{
    if(0UL == reentry_guard_15)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_15 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_15 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_15)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_15++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16(void)
{
    if(0UL == reentry_guard_16)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_16 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_16 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_16)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_16++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17(void)
{
    if(0UL == reentry_guard_17)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_17 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_17 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_17)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_17++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_18(void)
{
    if(0UL == reentry_guard_18)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_18 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_18 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_18)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_18++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_19(void)
{
    if(0UL == reentry_guard_19)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_19 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_19 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_19)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_19++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_20(void)
{
    if(0UL == reentry_guard_20)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_20 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_20 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_20)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_20++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21(void)
{
    if(0UL == reentry_guard_21)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_21 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_21 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_21)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_21++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_22(void)
{
    if(0UL == reentry_guard_22)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_22 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_22 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_22)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_22++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23(void)
{
    if(0UL == reentry_guard_23)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_23 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_23 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_23)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_23++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_24(void)
{
    if(0UL == reentry_guard_24)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_24 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_24 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_24)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_24++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_25(void)
{
    if(0UL == reentry_guard_25)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_25 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_25 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_25)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_25++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_26(void)
{
    if(0UL == reentry_guard_26)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_26 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_26 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_26)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_26++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_27(void)
{
    if(0UL == reentry_guard_27)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_27 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_27 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_27)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_27++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_28(void)
{
    if(0UL == reentry_guard_28)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_28 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_28 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_28)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_28++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_29(void)
{
    if(0UL == reentry_guard_29)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_29 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_29 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_29)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_29++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_30(void)
{
    if(0UL == reentry_guard_30)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_30 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_30 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_30)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_30++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_31(void)
{
    if(0UL == reentry_guard_31)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_31 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_31 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_31)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_31++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_32(void)
{
    if(0UL == reentry_guard_32)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_32 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_32 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_32)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_32++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_33(void)
{
    if(0UL == reentry_guard_33)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_33 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_33 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_33)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_33++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_34(void)
{
    if(0UL == reentry_guard_34)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_34 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_34 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_34)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_34++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_35(void)
{
    if(0UL == reentry_guard_35)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_35 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_35 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_35)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_35++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_36(void)
{
    if(0UL == reentry_guard_36)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_36 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_36 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_36)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_36++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_37(void)
{
    if(0UL == reentry_guard_37)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_37 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_37 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_37)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_37++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_38(void)
{
    if(0UL == reentry_guard_38)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_38 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_38 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_38)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_38++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_39(void)
{
    if(0UL == reentry_guard_39)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_39 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_39 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_39)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_39++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_40(void)
{
    if(0UL == reentry_guard_40)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_40 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_40 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_40)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_40++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_41(void)
{
    if(0UL == reentry_guard_41)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_41 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_41 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_41)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_41++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_42(void)
{
    if(0UL == reentry_guard_42)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_42 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_42 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_42)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_42++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_43(void)
{
    if(0UL == reentry_guard_43)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_43 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_43 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_43)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_43++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_44(void)
{
    if(0UL == reentry_guard_44)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_44 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_44 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_44)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_44++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_45(void)
{
    if(0UL == reentry_guard_45)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_45 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_45 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_45)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_45++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_46(void)
{
    if(0UL == reentry_guard_46)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_46 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_46 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_46)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_46++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_47(void)
{
    if(0UL == reentry_guard_47)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_47 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_47 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_47)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_47++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_48(void)
{
    if(0UL == reentry_guard_48)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_48 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_48 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_48)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_48++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_49(void)
{
    if(0UL == reentry_guard_49)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_49 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_49 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_49)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_49++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_50(void)
{
    if(0UL == reentry_guard_50)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_50 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_50 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_50)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_50++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_51(void)
{
    if(0UL == reentry_guard_51)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_51 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_51 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_51)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_51++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_52(void)
{
    if(0UL == reentry_guard_52)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_52 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_52 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_52)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_52++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_53(void)
{
    if(0UL == reentry_guard_53)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_53 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_53 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_53)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_53++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_54(void)
{
    if(0UL == reentry_guard_54)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_54 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_54 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_54)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_54++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_55(void)
{
    if(0UL == reentry_guard_55)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_55 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_55 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_55)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_55++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_56(void)
{
    if(0UL == reentry_guard_56)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_56 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_56 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_56)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_56++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_57(void)
{
    if(0UL == reentry_guard_57)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_57 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_57 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_57)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_57++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_58(void)
{
    if(0UL == reentry_guard_58)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_58 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_58 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_58)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_58++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_59(void)
{
    if(0UL == reentry_guard_59)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_59 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_59 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_59)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_59++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_60(void)
{
    if(0UL == reentry_guard_60)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_60 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_60 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_60)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_60++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_61(void)
{
    if(0UL == reentry_guard_61)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_61 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_61 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_61)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_61++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_62(void)
{
    if(0UL == reentry_guard_62)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_62 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_62 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_62)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_62++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_63(void)
{
    if(0UL == reentry_guard_63)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_63 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_63 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_63)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_63++;
}
FUNC (void, RTE_CODE) SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_64(void)
{
    if(0UL == reentry_guard_64)
    {
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
       msr_64 = Mcal_Trusted_Call_Return(Adc_schm_read_msr);
#else
       msr_64 = Adc_schm_read_msr();  /*read MSR (to store interrupts state)*/
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
       if (ISR_ON(msr_64)) /*if MSR[EE] = 0, skip calling Suspend/Resume AllInterrupts*/
       {
         SuspendAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
         ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
      }
    }
    reentry_guard_64++;
}
                          
/*================================================================================================*/
/** 
* @brief   This function is called to allow ADC to exit the specific critical region. 
* @details This is a local function stub only. It will resume interrupts if no other 
*          critical area is still executing.
*     
* @param[in]     void     No input parameters
* @return        void     This function does not return anything
* 
* @pre  None
* @post None
* 
*/
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_00(void)
{
    reentry_guard_00--;
    if ((ISR_ON(msr_00))&&(0UL == reentry_guard_00))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_01(void)
{
    reentry_guard_01--;
    if ((ISR_ON(msr_01))&&(0UL == reentry_guard_01))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_02(void)
{
    reentry_guard_02--;
    if ((ISR_ON(msr_02))&&(0UL == reentry_guard_02))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03(void)
{
    reentry_guard_03--;
    if ((ISR_ON(msr_03))&&(0UL == reentry_guard_03))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_04(void)
{
    reentry_guard_04--;
    if ((ISR_ON(msr_04))&&(0UL == reentry_guard_04))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05(void)
{
    reentry_guard_05--;
    if ((ISR_ON(msr_05))&&(0UL == reentry_guard_05))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06(void)
{
    reentry_guard_06--;
    if ((ISR_ON(msr_06))&&(0UL == reentry_guard_06))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07(void)
{
    reentry_guard_07--;
    if ((ISR_ON(msr_07))&&(0UL == reentry_guard_07))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08(void)
{
    reentry_guard_08--;
    if ((ISR_ON(msr_08))&&(0UL == reentry_guard_08))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09(void)
{
    reentry_guard_09--;
    if ((ISR_ON(msr_09))&&(0UL == reentry_guard_09))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10(void)
{
    reentry_guard_10--;
    if ((ISR_ON(msr_10))&&(0UL == reentry_guard_10))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11(void)
{
    reentry_guard_11--;
    if ((ISR_ON(msr_11))&&(0UL == reentry_guard_11))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_12(void)
{
    reentry_guard_12--;
    if ((ISR_ON(msr_12))&&(0UL == reentry_guard_12))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13(void)
{
    reentry_guard_13--;
    if ((ISR_ON(msr_13))&&(0UL == reentry_guard_13))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14(void)
{
    reentry_guard_14--;
    if ((ISR_ON(msr_14))&&(0UL == reentry_guard_14))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15(void)
{
    reentry_guard_15--;
    if ((ISR_ON(msr_15))&&(0UL == reentry_guard_15))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16(void)
{
    reentry_guard_16--;
    if ((ISR_ON(msr_16))&&(0UL == reentry_guard_16))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17(void)
{
    reentry_guard_17--;
    if ((ISR_ON(msr_17))&&(0UL == reentry_guard_17))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_18(void)
{
    reentry_guard_18--;
    if ((ISR_ON(msr_18))&&(0UL == reentry_guard_18))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_19(void)
{
    reentry_guard_19--;
    if ((ISR_ON(msr_19))&&(0UL == reentry_guard_19))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_20(void)
{
    reentry_guard_20--;
    if ((ISR_ON(msr_20))&&(0UL == reentry_guard_20))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21(void)
{
    reentry_guard_21--;
    if ((ISR_ON(msr_21))&&(0UL == reentry_guard_21))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_22(void)
{
    reentry_guard_22--;
    if ((ISR_ON(msr_22))&&(0UL == reentry_guard_22))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23(void)
{
    reentry_guard_23--;
    if ((ISR_ON(msr_23))&&(0UL == reentry_guard_23))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_24(void)
{
    reentry_guard_24--;
    if ((ISR_ON(msr_24))&&(0UL == reentry_guard_24))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_25(void)
{
    reentry_guard_25--;
    if ((ISR_ON(msr_25))&&(0UL == reentry_guard_25))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_26(void)
{
    reentry_guard_26--;
    if ((ISR_ON(msr_26))&&(0UL == reentry_guard_26))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_27(void)
{
    reentry_guard_27--;
    if ((ISR_ON(msr_27))&&(0UL == reentry_guard_27))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_28(void)
{
    reentry_guard_28--;
    if ((ISR_ON(msr_28))&&(0UL == reentry_guard_28))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_29(void)
{
    reentry_guard_29--;
    if ((ISR_ON(msr_29))&&(0UL == reentry_guard_29))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_30(void)
{
    reentry_guard_30--;
    if ((ISR_ON(msr_30))&&(0UL == reentry_guard_30))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_31(void)
{
    reentry_guard_31--;
    if ((ISR_ON(msr_31))&&(0UL == reentry_guard_31))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_32(void)
{
    reentry_guard_32--;
    if ((ISR_ON(msr_32))&&(0UL == reentry_guard_32))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_33(void)
{
    reentry_guard_33--;
    if ((ISR_ON(msr_33))&&(0UL == reentry_guard_33))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_34(void)
{
    reentry_guard_34--;
    if ((ISR_ON(msr_34))&&(0UL == reentry_guard_34))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_35(void)
{
    reentry_guard_35--;
    if ((ISR_ON(msr_35))&&(0UL == reentry_guard_35))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_36(void)
{
    reentry_guard_36--;
    if ((ISR_ON(msr_36))&&(0UL == reentry_guard_36))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_37(void)
{
    reentry_guard_37--;
    if ((ISR_ON(msr_37))&&(0UL == reentry_guard_37))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_38(void)
{
    reentry_guard_38--;
    if ((ISR_ON(msr_38))&&(0UL == reentry_guard_38))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_39(void)
{
    reentry_guard_39--;
    if ((ISR_ON(msr_39))&&(0UL == reentry_guard_39))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_40(void)
{
    reentry_guard_40--;
    if ((ISR_ON(msr_40))&&(0UL == reentry_guard_40))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_41(void)
{
    reentry_guard_41--;
    if ((ISR_ON(msr_41))&&(0UL == reentry_guard_41))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_42(void)
{
    reentry_guard_42--;
    if ((ISR_ON(msr_42))&&(0UL == reentry_guard_42))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_43(void)
{
    reentry_guard_43--;
    if ((ISR_ON(msr_43))&&(0UL == reentry_guard_43))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_44(void)
{
    reentry_guard_44--;
    if ((ISR_ON(msr_44))&&(0UL == reentry_guard_44))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_45(void)
{
    reentry_guard_45--;
    if ((ISR_ON(msr_45))&&(0UL == reentry_guard_45))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_46(void)
{
    reentry_guard_46--;
    if ((ISR_ON(msr_46))&&(0UL == reentry_guard_46))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_47(void)
{
    reentry_guard_47--;
    if ((ISR_ON(msr_47))&&(0UL == reentry_guard_47))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_48(void)
{
    reentry_guard_48--;
    if ((ISR_ON(msr_48))&&(0UL == reentry_guard_48))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_49(void)
{
    reentry_guard_49--;
    if ((ISR_ON(msr_49))&&(0UL == reentry_guard_49))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_50(void)
{
    reentry_guard_50--;
    if ((ISR_ON(msr_50))&&(0UL == reentry_guard_50))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_51(void)
{
    reentry_guard_51--;
    if ((ISR_ON(msr_51))&&(0UL == reentry_guard_51))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_52(void)
{
    reentry_guard_52--;
    if ((ISR_ON(msr_52))&&(0UL == reentry_guard_52))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_53(void)
{
    reentry_guard_53--;
    if ((ISR_ON(msr_53))&&(0UL == reentry_guard_53))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_54(void)
{
    reentry_guard_54--;
    if ((ISR_ON(msr_54))&&(0UL == reentry_guard_54))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_55(void)
{
    reentry_guard_55--;
    if ((ISR_ON(msr_55))&&(0UL == reentry_guard_55))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_56(void)
{
    reentry_guard_56--;
    if ((ISR_ON(msr_56))&&(0UL == reentry_guard_56))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_57(void)
{
    reentry_guard_57--;
    if ((ISR_ON(msr_57))&&(0UL == reentry_guard_57))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_58(void)
{
    reentry_guard_58--;
    if ((ISR_ON(msr_58))&&(0UL == reentry_guard_58))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_59(void)
{
    reentry_guard_59--;
    if ((ISR_ON(msr_59))&&(0UL == reentry_guard_59))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_60(void)
{
    reentry_guard_60--;
    if ((ISR_ON(msr_60))&&(0UL == reentry_guard_60))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_61(void)
{
    reentry_guard_61--;
    if ((ISR_ON(msr_61))&&(0UL == reentry_guard_61))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_62(void)
{
    reentry_guard_62--;
    if ((ISR_ON(msr_62))&&(0UL == reentry_guard_62))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_63(void)
{
    reentry_guard_63--;
    if ((ISR_ON(msr_63))&&(0UL == reentry_guard_63))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}
FUNC (void, RTE_CODE) SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_64(void)
{
    reentry_guard_64--;
    if ((ISR_ON(msr_64))&&(0UL == reentry_guard_64))         /*if interrupts were enabled*/
    {
      ResumeAllInterrupts();
#ifdef _ARM_DS5_C_S32K14x_
      ASM_KEYWORD(" nop ");/* Compiler fix - forces the CSPID instruction to be generated with -02, -Ospace are selected*/
#endif
    }
}

#ifdef MCAL_TESTING_ENVIRONMENT
/** 
@brief   This function checks that all entered exclusive areas were also exited. 
@details This function checks that all entered exclusive areas were also exited. The check
         is done by verifying that all reentry_guard_* static variables are back to the
         zero value.
    
@param[in]     void       No input parameters
@return        void       This function does not return a value. Test asserts are used instead. 

@pre  None
@post None

@remarks Covers 
@remarks Implements 
*/
FUNC(void, RTE_CODE) SchM_Check_adc(void)
{
  EU_ASSERT(0UL == reentry_guard_00);
  EU_ASSERT(0UL == reentry_guard_01);
  EU_ASSERT(0UL == reentry_guard_02);
  EU_ASSERT(0UL == reentry_guard_03);
  EU_ASSERT(0UL == reentry_guard_04);
  EU_ASSERT(0UL == reentry_guard_05);
  EU_ASSERT(0UL == reentry_guard_06);
  EU_ASSERT(0UL == reentry_guard_07);
  EU_ASSERT(0UL == reentry_guard_08);
  EU_ASSERT(0UL == reentry_guard_09);
  EU_ASSERT(0UL == reentry_guard_10);
  EU_ASSERT(0UL == reentry_guard_11);
  EU_ASSERT(0UL == reentry_guard_12);
  EU_ASSERT(0UL == reentry_guard_13);
  EU_ASSERT(0UL == reentry_guard_14);
  EU_ASSERT(0UL == reentry_guard_15);
  EU_ASSERT(0UL == reentry_guard_16);
  EU_ASSERT(0UL == reentry_guard_17);
  EU_ASSERT(0UL == reentry_guard_18);
  EU_ASSERT(0UL == reentry_guard_19);
  EU_ASSERT(0UL == reentry_guard_20);
  EU_ASSERT(0UL == reentry_guard_21);
  EU_ASSERT(0UL == reentry_guard_22);
  EU_ASSERT(0UL == reentry_guard_23);
  EU_ASSERT(0UL == reentry_guard_24);
  EU_ASSERT(0UL == reentry_guard_25);
  EU_ASSERT(0UL == reentry_guard_26);
  EU_ASSERT(0UL == reentry_guard_27);
  EU_ASSERT(0UL == reentry_guard_28);
  EU_ASSERT(0UL == reentry_guard_29);
  EU_ASSERT(0UL == reentry_guard_30);
  EU_ASSERT(0UL == reentry_guard_31);
  EU_ASSERT(0UL == reentry_guard_32);
  EU_ASSERT(0UL == reentry_guard_33);
  EU_ASSERT(0UL == reentry_guard_34);
  EU_ASSERT(0UL == reentry_guard_35);
  EU_ASSERT(0UL == reentry_guard_36);
  EU_ASSERT(0UL == reentry_guard_37);
  EU_ASSERT(0UL == reentry_guard_38);
  EU_ASSERT(0UL == reentry_guard_39);
  EU_ASSERT(0UL == reentry_guard_40);
  EU_ASSERT(0UL == reentry_guard_41);
  EU_ASSERT(0UL == reentry_guard_42);
  EU_ASSERT(0UL == reentry_guard_43);
  EU_ASSERT(0UL == reentry_guard_44);
  EU_ASSERT(0UL == reentry_guard_45);
  EU_ASSERT(0UL == reentry_guard_46);
  EU_ASSERT(0UL == reentry_guard_47);
  EU_ASSERT(0UL == reentry_guard_48);
  EU_ASSERT(0UL == reentry_guard_49);
  EU_ASSERT(0UL == reentry_guard_50);
  EU_ASSERT(0UL == reentry_guard_51);
  EU_ASSERT(0UL == reentry_guard_52);
  EU_ASSERT(0UL == reentry_guard_53);
  EU_ASSERT(0UL == reentry_guard_54);
  EU_ASSERT(0UL == reentry_guard_55);
  EU_ASSERT(0UL == reentry_guard_56);
  EU_ASSERT(0UL == reentry_guard_57);
  EU_ASSERT(0UL == reentry_guard_58);
  EU_ASSERT(0UL == reentry_guard_59);
  EU_ASSERT(0UL == reentry_guard_60);
  EU_ASSERT(0UL == reentry_guard_61);
  EU_ASSERT(0UL == reentry_guard_62);
  EU_ASSERT(0UL == reentry_guard_63);
  EU_ASSERT(0UL == reentry_guard_64);
  reentry_guard_00 = 0UL; /*reset reentry_guard_00 for the next test in the suite*/
  reentry_guard_01 = 0UL; /*reset reentry_guard_01 for the next test in the suite*/
  reentry_guard_02 = 0UL; /*reset reentry_guard_02 for the next test in the suite*/
  reentry_guard_03 = 0UL; /*reset reentry_guard_03 for the next test in the suite*/
  reentry_guard_04 = 0UL; /*reset reentry_guard_04 for the next test in the suite*/
  reentry_guard_05 = 0UL; /*reset reentry_guard_05 for the next test in the suite*/
  reentry_guard_06 = 0UL; /*reset reentry_guard_06 for the next test in the suite*/
  reentry_guard_07 = 0UL; /*reset reentry_guard_07 for the next test in the suite*/
  reentry_guard_08 = 0UL; /*reset reentry_guard_08 for the next test in the suite*/
  reentry_guard_09 = 0UL; /*reset reentry_guard_09 for the next test in the suite*/
  reentry_guard_10 = 0UL; /*reset reentry_guard_10 for the next test in the suite*/
  reentry_guard_11 = 0UL; /*reset reentry_guard_11 for the next test in the suite*/
  reentry_guard_12 = 0UL; /*reset reentry_guard_12 for the next test in the suite*/
  reentry_guard_13 = 0UL; /*reset reentry_guard_13 for the next test in the suite*/
  reentry_guard_14 = 0UL; /*reset reentry_guard_14 for the next test in the suite*/
  reentry_guard_15 = 0UL; /*reset reentry_guard_15 for the next test in the suite*/
  reentry_guard_16 = 0UL; /*reset reentry_guard_16 for the next test in the suite*/
  reentry_guard_17 = 0UL; /*reset reentry_guard_17 for the next test in the suite*/
  reentry_guard_18 = 0UL; /*reset reentry_guard_18 for the next test in the suite*/
  reentry_guard_19 = 0UL; /*reset reentry_guard_19 for the next test in the suite*/
  reentry_guard_20 = 0UL; /*reset reentry_guard_20 for the next test in the suite*/
  reentry_guard_21 = 0UL; /*reset reentry_guard_21 for the next test in the suite*/
  reentry_guard_22 = 0UL; /*reset reentry_guard_22 for the next test in the suite*/
  reentry_guard_23 = 0UL; /*reset reentry_guard_23 for the next test in the suite*/
  reentry_guard_24 = 0UL; /*reset reentry_guard_24 for the next test in the suite*/
  reentry_guard_25 = 0UL; /*reset reentry_guard_25 for the next test in the suite*/
  reentry_guard_26 = 0UL; /*reset reentry_guard_26 for the next test in the suite*/
  reentry_guard_27 = 0UL; /*reset reentry_guard_27 for the next test in the suite*/
  reentry_guard_28 = 0UL; /*reset reentry_guard_28 for the next test in the suite*/
  reentry_guard_29 = 0UL; /*reset reentry_guard_29 for the next test in the suite*/
  reentry_guard_30 = 0UL; /*reset reentry_guard_30 for the next test in the suite*/
  reentry_guard_31 = 0UL; /*reset reentry_guard_31 for the next test in the suite*/
  reentry_guard_32 = 0UL; /*reset reentry_guard_32 for the next test in the suite*/
  reentry_guard_33 = 0UL; /*reset reentry_guard_33 for the next test in the suite*/
  reentry_guard_34 = 0UL; /*reset reentry_guard_34 for the next test in the suite*/
  reentry_guard_35 = 0UL; /*reset reentry_guard_35 for the next test in the suite*/
  reentry_guard_36 = 0UL; /*reset reentry_guard_36 for the next test in the suite*/
  reentry_guard_37 = 0UL; /*reset reentry_guard_37 for the next test in the suite*/
  reentry_guard_38 = 0UL; /*reset reentry_guard_38 for the next test in the suite*/
  reentry_guard_39 = 0UL; /*reset reentry_guard_39 for the next test in the suite*/
  reentry_guard_40 = 0UL; /*reset reentry_guard_40 for the next test in the suite*/
  reentry_guard_41 = 0UL; /*reset reentry_guard_41 for the next test in the suite*/
  reentry_guard_42 = 0UL; /*reset reentry_guard_42 for the next test in the suite*/
  reentry_guard_43 = 0UL; /*reset reentry_guard_43 for the next test in the suite*/
  reentry_guard_44 = 0UL; /*reset reentry_guard_44 for the next test in the suite*/
  reentry_guard_45 = 0UL; /*reset reentry_guard_45 for the next test in the suite*/
  reentry_guard_46 = 0UL; /*reset reentry_guard_46 for the next test in the suite*/
  reentry_guard_47 = 0UL; /*reset reentry_guard_47 for the next test in the suite*/
  reentry_guard_48 = 0UL; /*reset reentry_guard_48 for the next test in the suite*/
  reentry_guard_49 = 0UL; /*reset reentry_guard_49 for the next test in the suite*/
  reentry_guard_50 = 0UL; /*reset reentry_guard_50 for the next test in the suite*/
  reentry_guard_51 = 0UL; /*reset reentry_guard_51 for the next test in the suite*/
  reentry_guard_52 = 0UL; /*reset reentry_guard_52 for the next test in the suite*/
  reentry_guard_53 = 0UL; /*reset reentry_guard_53 for the next test in the suite*/
  reentry_guard_54 = 0UL; /*reset reentry_guard_54 for the next test in the suite*/
  reentry_guard_55 = 0UL; /*reset reentry_guard_55 for the next test in the suite*/
  reentry_guard_56 = 0UL; /*reset reentry_guard_56 for the next test in the suite*/
  reentry_guard_57 = 0UL; /*reset reentry_guard_57 for the next test in the suite*/
  reentry_guard_58 = 0UL; /*reset reentry_guard_58 for the next test in the suite*/
  reentry_guard_59 = 0UL; /*reset reentry_guard_59 for the next test in the suite*/
  reentry_guard_60 = 0UL; /*reset reentry_guard_60 for the next test in the suite*/
  reentry_guard_61 = 0UL; /*reset reentry_guard_61 for the next test in the suite*/
  reentry_guard_62 = 0UL; /*reset reentry_guard_62 for the next test in the suite*/
  reentry_guard_63 = 0UL; /*reset reentry_guard_63 for the next test in the suite*/
  reentry_guard_64 = 0UL; /*reset reentry_guard_64 for the next test in the suite*/
}
#endif /*MCAL_TESTING_ENVIRONMENT*/


#ifdef __cplusplus
}
#endif

/** @} */
