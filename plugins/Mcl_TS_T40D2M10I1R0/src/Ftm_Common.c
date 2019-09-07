/**
*   @file    Ftm_Common.c
*   @implements Ftm_Common.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - FTM driver source file.
*   @details Common FTM routines.
*
*   @addtogroup FTM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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
*   @file    Ftm_Common.c
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section FTM_COMMON_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section FTM_COMMON_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section FTM_COMMON_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This is mentained because the names are according to Autosar requirement. 
* 
* @section FTM_COMMON_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Ftm_Common.c
* 
*/

#include "modules.h"
#if ((USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON) || (USE_PWM_MODULE==STD_ON) || (USE_OCU_MODULE==STD_ON))

/** @violates @ref FTM_COMMON_C_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Std_Types.h"
#include "Ftm_Common_Types.h"

#if (USE_GPT_MODULE==STD_ON)
   #include "Gpt_Ftm.h"
#endif

#if (USE_ICU_MODULE==STD_ON)
    #include "Icu_Cfg.h"
    #include "Icu_Ftm_Irq.h"
#endif

#if (USE_PWM_MODULE==STD_ON)
    #include "Pwm_Ftm_Irq.h"
#endif
#if (USE_OCU_MODULE==STD_ON)
    #include "Ocu_Ftm_Irq.h"
#endif
#include "SchM_Mcl.h"

#include "Reg_eSys_Ftm.h"
#define USER_MODE_REG_PROT_ENABLED (STD_OFF)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ftm_Common.c
* @brief          Source file version information  
*/
#define FTM_COMMON_VENDOR_ID_C                       43
/** @violates @ref FTM_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref FTM_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define FTM_COMMON_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref FTM_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define FTM_COMMON_AR_RELEASE_REVISION_VERSION_C     2
#define FTM_COMMON_SW_MAJOR_VERSION_C                1
#define FTM_COMMON_SW_MINOR_VERSION_C                0
#define FTM_COMMON_SW_PATCH_VERSION_C                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != MODULES_AR_RELEASE_MINOR_VERSION_H))
        #error "AutoSar Version Numbers of Ftm_Common.c and modules.h are different"
    #endif
    
    #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftm_Common.c and Std_Types.h are different"
    #endif
    
    #if (USE_GPT_MODULE==STD_ON)
        #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != GPT_FTM_AR_RELEASE_MAJOR_VERSION) || \
             (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != GPT_FTM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Ftm_Common.c and Gpt_Ftm.h are different"
        #endif
    #endif
    
   #if (USE_ICU_MODULE==STD_ON)
        #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
             (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG))
            #error "AutoSar Version Numbers of Ftm_Common.c and Icu_Cfg.h are different"
        #endif
        #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION) || \
             (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_FTM_IRQ_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Ftm_Common.c and Icu_Ftm_Irq.h are different"
        #endif
    #endif
    
    #if (USE_PWM_MODULE==STD_ON)
        #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != PWM_FTM_IRQ_AR_RELEASE_MAJOR_VERSION) || \
             (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != PWM_FTM_IRQ_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Ftm_Common.c and Pwm_Ftm_Irq.h are different"
        #endif
    #endif
    #if (USE_OCU_MODULE==STD_ON)
        #if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != OCU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION) || \
             (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != OCU_FTM_IRQ_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Ftm_Common.c and Ocu_Ftm_Irq.h are different"
        #endif
    #endif 
#endif

/* Check if source file and GPT header file are of the same vendor */
#if (FTM_COMMON_VENDOR_ID_C != FTM_COMMON_TYPES_VENDOR_ID)
    #error "Ftm_Common.c and Ftm_Common_Types.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_COMMON_AR_RELEASE_REVISION_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Common.c and Ftm_Common_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((FTM_COMMON_SW_MAJOR_VERSION_C != FTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (FTM_COMMON_SW_MINOR_VERSION_C != FTM_COMMON_TYPES_SW_MINOR_VERSION) || \
     (FTM_COMMON_SW_PATCH_VERSION_C != FTM_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Common.c and Ftm_Common_Types.h are different"
#endif

/* Check if source file and GPT header file are of the same vendor */
#if (FTM_COMMON_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Ftm_Common.c and Reg_eSys_Ftm.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((FTM_COMMON_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_COMMON_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (FTM_COMMON_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Common.c and Reg_eSys_Ftm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((FTM_COMMON_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (FTM_COMMON_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (FTM_COMMON_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Common.c and Reg_eSys_Ftm.h are different"
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
#define FTM_CHANNEL_MAX (8U)
#define FTM_FAULT_MAX   (4U)

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define MCL_START_SEC_CONST_32
/** @violates @ref FTM_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief base address array for FTM
*/
CONST(uint32, MCL_CONST) FTM_BASE_ADDR32[] = {
#ifdef FTM_0_BASEADDR
    FTM_0_BASEADDR
#else
    (uint32)0UL
#endif
#ifdef FTM_1_BASEADDR
    ,FTM_1_BASEADDR
#else
    ,(uint32)0UL
#endif
#ifdef FTM_2_BASEADDR
    ,FTM_2_BASEADDR
#else
    ,(uint32)0UL
#endif
#ifdef FTM_3_BASEADDR
    ,FTM_3_BASEADDR
#else
    ,(uint32)0UL
#endif
#ifdef FTM_4_BASEADDR
    ,FTM_4_BASEADDR
#else
    ,(uint32)0UL
#endif
#ifdef FTM_5_BASEADDR
    ,FTM_5_BASEADDR
#else
    ,(uint32)0UL
#endif
#ifdef FTM_6_BASEADDR
    ,FTM_6_BASEADDR
#else
    ,(uint32)0UL
#endif
#ifdef FTM_7_BASEADDR
    ,FTM_7_BASEADDR
#else
    ,(uint32)0UL
#endif
};

#define MCL_STOP_SEC_CONST_32
/** @violates @ref FTM_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref FTM_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref FTM_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref FTM_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/** 
@brief FTM ISR declarations
@{
*/

#if(defined IPV_FTM)
#if (IPV_FTM == IPV_FTM_05_00_04_00)

ISR(FTM_0_CH_0_CH_1_ISR);
ISR(FTM_0_CH_2_CH_3_ISR);
ISR(FTM_0_CH_4_CH_5_ISR);
ISR(FTM_0_CH_6_CH_7_ISR);
ISR(FTM_0_OVF_ISR);
ISR(FTM_0_FAULT_ISR);

ISR(FTM_1_CH_0_CH_1_ISR);
ISR(FTM_1_CH_2_CH_3_ISR);
ISR(FTM_1_CH_4_CH_5_ISR);
ISR(FTM_1_CH_6_CH_7_ISR);
ISR(FTM_1_OVF_ISR);
ISR(FTM_1_FAULT_ISR);

ISR(FTM_2_CH_0_CH_1_ISR);
ISR(FTM_2_CH_2_CH_3_ISR);
ISR(FTM_2_CH_4_CH_5_ISR);
ISR(FTM_2_CH_6_CH_7_ISR);
ISR(FTM_2_OVF_ISR);
ISR(FTM_2_FAULT_ISR);

ISR(FTM_3_CH_0_CH_1_ISR);
ISR(FTM_3_CH_2_CH_3_ISR);
ISR(FTM_3_CH_4_CH_5_ISR);
ISR(FTM_3_CH_6_CH_7_ISR);
ISR(FTM_3_OVF_ISR);
ISR(FTM_3_FAULT_ISR);

ISR(FTM_4_CH_0_CH_1_ISR);
ISR(FTM_4_CH_2_CH_3_ISR);
ISR(FTM_4_CH_4_CH_5_ISR);
ISR(FTM_4_CH_6_CH_7_ISR);
ISR(FTM_4_OVF_ISR);
ISR(FTM_4_FAULT_ISR);

ISR(FTM_5_CH_0_CH_1_ISR);
ISR(FTM_5_CH_2_CH_3_ISR);
ISR(FTM_5_CH_4_CH_5_ISR);
ISR(FTM_5_CH_6_CH_7_ISR);
ISR(FTM_5_OVF_ISR);
ISR(FTM_5_FAULT_ISR);

ISR(FTM_6_CH_0_CH_1_ISR);
ISR(FTM_6_CH_2_CH_3_ISR);
ISR(FTM_6_CH_4_CH_5_ISR);
ISR(FTM_6_CH_6_CH_7_ISR);
ISR(FTM_6_OVF_ISR);
ISR(FTM_6_FAULT_ISR);

ISR(FTM_7_CH_0_CH_1_ISR);
ISR(FTM_7_CH_2_CH_3_ISR);
ISR(FTM_7_CH_4_CH_5_ISR);
ISR(FTM_7_CH_6_CH_7_ISR);
ISR(FTM_7_OVF_ISR);
ISR(FTM_7_FAULT_ISR);
#endif
#endif

#if ((IPV_FTM == IPV_FTM_04_00_29_00) || (!(defined IPV_FTM)) || (GPT_FTM_MODULE_SINGLE_INTERRUPT == STD_ON)|| (ICU_FTM_MODULE_SINGLE_INTERRUPT == STD_ON) || (PWM_FTM_MODULE_SINGLE_INTERRUPT == STD_ON) || (OCU_FTM_MODULE_SINGLE_INTERRUPT == STD_ON))
    
ISR(FTM_0_ISR);
ISR(FTM_1_ISR);
ISR(FTM_2_ISR);
ISR(FTM_3_ISR);

#endif
/**@}*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if  ((defined GPT_FTM_0_USED) && (defined PWM_FTM_0_USED))
#error "GPT and PWM resource conflict for FTM 0 hw unit"
#endif

#if  ((defined PWM_FTM_0_USED) && (defined ICU_FTM_0_USED))
#error "PWM and ICU resource conflict for FTM 0 hw unit"
#endif

#if  ((defined ICU_FTM_0_USED) && (defined GPT_FTM_0_USED))
#error "ICU and GPT resource conflict for FTM 0 hw unit"
#endif

#if  ((defined OCU_FTM_0_USED) && (defined GPT_FTM_0_USED))
#error "OCU and GPT resource conflict for FTM 0 hw unit"
#endif

#if  ((defined OCU_FTM_0_USED) && (defined ICU_FTM_0_USED))
#error "OCU and ICU resource conflict for FTM 0 hw unit"
#endif

#if  ((defined OCU_FTM_0_USED) && (defined PWM_FTM_0_USED))
#error "OCU and PWM resource conflict for FTM 0 hw unit"
#endif

#if  ((defined GPT_FTM_1_USED) && (defined PWM_FTM_1_USED))
    #error "GPT and PWM resource conflict for FTM 1 hw unit"
#endif

#if  ((defined PWM_FTM_1_USED) && (defined ICU_FTM_1_USED))
    #error "PWM and ICU resource conflict for FTM 1 hw unit"
#endif

#if  ((defined ICU_FTM_1_USED) && (defined GPT_FTM_1_USED))
#error "ICU and GPT resource conflict for FTM 1 hw unit"
#endif

#if  ((defined OCU_FTM_1_USED) && (defined GPT_FTM_1_USED))
#error "OCU and GPT resource conflict for FTM 1 hw unit"
#endif

#if  ((defined OCU_FTM_1_USED) && (defined ICU_FTM_1_USED))
#error "OCU and ICU resource conflict for FTM 1 hw unit"
#endif

#if  ((defined OCU_FTM_1_USED) && (defined PWM_FTM_1_USED))
#error "OCU and PWM resource conflict for FTM 1 hw unit"
#endif

#if  ((defined GPT_FTM_2_USED) && (defined PWM_FTM_2_USED))
#error "GPT and PWM resource conflict for FTM 2 hw unit"
#endif

#if  ((defined PWM_FTM_2_USED) && (defined ICU_FTM_2_USED))
#error "PWM and ICU resource conflict for FTM 2 hw unit"
#endif

#if  ((defined ICU_FTM_2_USED) && (defined GPT_FTM_2_USED))
#error "ICU and GPT resource conflict for FTM 2 hw unit"
#endif

#if  ((defined OCU_FTM_2_USED) && (defined GPT_FTM_2_USED))
#error "OCU and GPT resource conflict for FTM 2 hw unit"
#endif

#if  ((defined OCU_FTM_2_USED) && (defined ICU_FTM_2_USED))
#error "OCU and ICU resource conflict for FTM 2 hw unit"
#endif

#if  ((defined OCU_FTM_2_USED) && (defined PWM_FTM_2_USED))
#error "OCU and PWM resource conflict for FTM 2 hw unit"
#endif
#if  ((defined GPT_FTM_3_USED) && (defined PWM_FTM_3_USED))
    #error "GPT and PWM resource conflict for FTM 3 hw unit"
#endif

#if  ((defined PWM_FTM_3_USED) && (defined ICU_FTM_3_USED))
#error "PWM and ICU resource conflict for FTM 3 hw unit"
#endif

#if  ((defined ICU_FTM_3_USED) && (defined GPT_FTM_3_USED))
#error "ICU and GPT resource conflict for FTM 3 hw unit"
#endif

#if  ((defined OCU_FTM_3_USED) && (defined GPT_FTM_3_USED))
#error "OCU and GPT resource conflict for FTM 3 hw unit"
#endif

#if  ((defined OCU_FTM_3_USED) && (defined ICU_FTM_3_USED))
#error "OCU and ICU resource conflict for FTM 3 hw unit"
#endif

#if  ((defined OCU_FTM_3_USED) && (defined PWM_FTM_3_USED))
#error "OCU and PWM resource conflict for FTM 3 hw unit"
#endif

#if  ((defined GPT_FTM_4_USED) && (defined PWM_FTM_4_USED))
    #error "GPT and PWM resource conflict for FTM 4 hw unit"
#endif

#if  ((defined PWM_FTM_4_USED) && (defined ICU_FTM_4_USED))
#error "PWM and ICU resource conflict for FTM 4 hw unit"
#endif

#if  ((defined ICU_FTM_4_USED) && (defined GPT_FTM_4_USED))
#error "ICU and GPT resource conflict for FTM 4 hw unit"
#endif

#if  ((defined OCU_FTM_4_USED) && (defined GPT_FTM_4_USED))
#error "OCU and GPT resource conflict for FTM 4 hw unit"
#endif

#if  ((defined OCU_FTM_4_USED) && (defined ICU_FTM_4_USED))
#error "OCU and ICU resource conflict for FTM 4 hw unit"
#endif

#if  ((defined OCU_FTM_4_USED) && (defined PWM_FTM_4_USED))
#error "OCU and PWM resource conflict for FTM 4 hw unit"
#endif

#if  ((defined GPT_FTM_5_USED) && (defined PWM_FTM_5_USED))
    #error "GPT and PWM resource conflict for FTM 5 hw unit"
#endif

#if  ((defined PWM_FTM_5_USED) && (defined ICU_FTM_5_USED))
#error "PWM and ICU resource conflict for FTM 5 hw unit"
#endif

#if  ((defined ICU_FTM_5_USED) && (defined GPT_FTM_5_USED))
#error "ICU and GPT resource conflict for FTM 5 hw unit"
#endif

#if  ((defined OCU_FTM_5_USED) && (defined GPT_FTM_5_USED))
#error "OCU and GPT resource conflict for FTM 5 hw unit"
#endif

#if  ((defined OCU_FTM_5_USED) && (defined ICU_FTM_5_USED))
#error "OCU and ICU resource conflict for FTM 5 hw unit"
#endif

#if  ((defined OCU_FTM_5_USED) && (defined PWM_FTM_5_USED))
#error "OCU and PWM resource conflict for FTM 5 hw unit"
#endif

#if  ((defined GPT_FTM_6_USED) && (defined PWM_FTM_6_USED))
    #error "GPT and PWM resource conflict for FTM 6 hw unit"
#endif

#if  ((defined PWM_FTM_6_USED) && (defined ICU_FTM_6_USED))
#error "PWM and ICU resource conflict for FTM 6 hw unit"
#endif

#if  ((defined ICU_FTM_6_USED) && (defined GPT_FTM_6_USED))
#error "ICU and GPT resource conflict for FTM 6 hw unit"
#endif

#if  ((defined OCU_FTM_6_USED) && (defined GPT_FTM_6_USED))
#error "OCU and GPT resource conflict for FTM 6 hw unit"
#endif

#if  ((defined OCU_FTM_6_USED) && (defined ICU_FTM_6_USED))
#error "OCU and ICU resource conflict for FTM 6 hw unit"
#endif

#if  ((defined OCU_FTM_6_USED) && (defined PWM_FTM_6_USED))
#error "OCU and PWM resource conflict for FTM 6 hw unit"
#endif

#if  ((defined GPT_FTM_7_USED) && (defined PWM_FTM_7_USED))
    #error "GPT and PWM resource conflict for FTM 7 hw unit"
#endif

#if  ((defined PWM_FTM_7_USED) && (defined ICU_FTM_7_USED))
#error "PWM and ICU resource conflict for FTM 7 hw unit"
#endif

#if  ((defined ICU_FTM_7_USED) && (defined GPT_FTM_7_USED))
#error "ICU and GPT resource conflict for FTM 7 hw unit"
#endif

#if  ((defined OCU_FTM_7_USED) && (defined GPT_FTM_7_USED))
#error "OCU and GPT resource conflict for FTM 7 hw unit"
#endif

#if  ((defined OCU_FTM_7_USED) && (defined ICU_FTM_7_USED))
#error "OCU and ICU resource conflict for FTM 7 hw unit"
#endif

#if  ((defined OCU_FTM_7_USED) && (defined PWM_FTM_7_USED))
#error "OCU and PWM resource conflict for FTM 7 hw unit"
#endif

#if(defined IPV_FTM)
#if (IPV_FTM == IPV_FTM_05_00_04_00)

/* @brief FTM_0 */

#if ((defined GPT_FTM_0_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_0_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_0_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_0_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_0_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_0));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_0);
        #endif

        #if (defined PWM_FTM_0_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_0);
        #endif

        #if (defined ICU_FTM_0_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_0);
        #endif
        
        #if (defined OCU_FTM_0_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_1);
        #endif

        #if (defined PWM_FTM_0_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_1);
        #endif

        #if (defined ICU_FTM_0_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_1);
        #endif
        
        #if (defined OCU_FTM_0_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_0_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_0_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_0_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_0_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_0_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_0));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_2);
        #endif

        #if (defined PWM_FTM_0_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_2);
        #endif

        #if (defined ICU_FTM_0_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_2);
        #endif
        
        #if (defined OCU_FTM_0_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_3);
        #endif

        #if (defined PWM_FTM_0_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_3);
        #endif

        #if (defined ICU_FTM_0_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_3);
        #endif
        
        #if (defined OCU_FTM_0_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_0_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_0_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_0_CH_4_CH_5_ISR_USED)|| (defined OCU_FTM_0_CH_4_CH_5_ISR_USED))
/*
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_0_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_0));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_4);
        #endif

        #if (defined PWM_FTM_0_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_4);
        #endif

        #if (defined ICU_FTM_0_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_4);
        #endif
        
        #if (defined OCU_FTM_0_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_5);
        #endif

        #if (defined PWM_FTM_0_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_5);
        #endif

        #if (defined ICU_FTM_0_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_5);
        #endif
        
        #if (defined OCU_FTM_0_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_0_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_0_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_0_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_0_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_0_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_0));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_6);
        #endif

        #if (defined PWM_FTM_0_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_6);
        #endif

        #if (defined ICU_FTM_0_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_6);
        #endif
        
        #if (defined OCU_FTM_0_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_0_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_7);
        #endif

        #if (defined PWM_FTM_0_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_7);
        #endif

        #if (defined ICU_FTM_0_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_0_CH_7);
        #endif
        
        #if (defined OCU_FTM_0_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_0_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_0_OVF_ISR_USED) || \
        (defined ICU_FTM_0_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 overflow
*
* @isr
*/
ISR(FTM_0_OVF_ISR)
{  
#if(defined PWM_FTM_0_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_0);
#endif
#if (defined ICU_FTM_0_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_0);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_0_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 fault
*
* @isr
*/
ISR(FTM_0_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 0U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
            Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif

/* @brief FTM_1 */

#if ((defined GPT_FTM_1_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_1_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_1_CH_0_CH_1_ISR_USED)  || (defined OCU_FTM_1_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_1_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_1));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_0);
        #endif

        #if (defined PWM_FTM_1_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_0);
        #endif

        #if (defined ICU_FTM_1_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_0);
        #endif
        
        #if (defined OCU_FTM_1_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_1);
        #endif

        #if (defined PWM_FTM_1_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_1);
        #endif

        #if (defined ICU_FTM_1_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_1);
        #endif
        
        #if (defined OCU_FTM_1_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}

#endif

#if ((defined GPT_FTM_1_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_1_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_1_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_1_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_1_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_1));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_2);
        #endif

        #if (defined PWM_FTM_1_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_2);
        #endif

        #if (defined ICU_FTM_1_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_2);
        #endif
        
        #if (defined OCU_FTM_1_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_3);
        #endif

        #if (defined PWM_FTM_1_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_3);
        #endif

        #if (defined ICU_FTM_1_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_3);
        #endif
        
        #if (defined OCU_FTM_1_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_1_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_1_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_1_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_1_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_1_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_1));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_4);
        #endif

        #if (defined PWM_FTM_1_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_4);
        #endif

        #if (defined ICU_FTM_1_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_4);
        #endif
        
        #if (defined OCU_FTM_1_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_5);
        #endif

        #if (defined PWM_FTM_1_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_5);
        #endif

        #if (defined ICU_FTM_1_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_5);
        #endif
        
        #if (defined OCU_FTM_1_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_1_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_1_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_1_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_1_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_1_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_1));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_6);
        #endif

        #if (defined PWM_FTM_1_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_6);
        #endif

        #if (defined ICU_FTM_1_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_6);
        #endif
        
        #if (defined OCU_FTM_1_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_1_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_7);
        #endif

        #if (defined PWM_FTM_1_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_7);
        #endif

        #if (defined ICU_FTM_1_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_1_CH_7);
        #endif
        
        #if (defined OCU_FTM_1_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_1_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_1_OVF_ISR_USED) || \
        (defined ICU_FTM_1_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1 overflow
*
* @isr
*/
ISR(FTM_1_OVF_ISR)
{
  
#if(defined PWM_FTM_1_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_1);
#endif
#if (defined ICU_FTM_1_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_1);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_1_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1 fault
*
* @isr
*/
ISR(FTM_1_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 1U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
           Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif

/* @brief FTM_2 */

#if ((defined GPT_FTM_2_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_2_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_2_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_2_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_2_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_2));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_0);
        #endif

        #if (defined PWM_FTM_2_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_0);
        #endif

        #if (defined ICU_FTM_2_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_0);
        #endif
        
        #if (defined OCU_FTM_2_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_1);
        #endif

        #if (defined PWM_FTM_2_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_1);
        #endif

        #if (defined ICU_FTM_2_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_1);
        #endif
        
        #if (defined OCU_FTM_2_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_2_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_2_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_2_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_2_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_2_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_2));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_2);
        #endif

        #if (defined PWM_FTM_2_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_2);
        #endif

        #if (defined ICU_FTM_2_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_2);
        #endif
        
        #if (defined OCU_FTM_2_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_3);
        #endif

        #if (defined PWM_FTM_2_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_3);
        #endif

        #if (defined ICU_FTM_2_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_3);
        #endif
        
        #if (defined OCU_FTM_2_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_2_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_2_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_2_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_2_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_2_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_2));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_4);
        #endif

        #if (defined PWM_FTM_2_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_4);
        #endif

        #if (defined ICU_FTM_2_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_4);
        #endif
        
        #if (defined OCU_FTM_2_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_5);
        #endif

        #if (defined PWM_FTM_2_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_5);
        #endif

        #if (defined ICU_FTM_2_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_5);
        #endif
        
        #if (defined OCU_FTM_2_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_2_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_2_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_2_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_2_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_2_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_2));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_6);
        #endif

        #if (defined PWM_FTM_2_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_6);
        #endif

        #if (defined ICU_FTM_2_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_6);
        #endif
        
        #if (defined OCU_FTM_2_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_2_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_7);
        #endif

        #if (defined PWM_FTM_2_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_7);
        #endif

        #if (defined ICU_FTM_2_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_2_CH_7);
        #endif
        
        #if (defined OCU_FTM_2_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_2_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_2_OVF_ISR_USED) || \
        (defined ICU_FTM_2_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2 overflow
*
* @isr
*/
ISR(FTM_2_OVF_ISR)
{
#if(defined PWM_FTM_2_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_2);
#endif
#if (defined ICU_FTM_2_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_2);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_2_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2 fault
*
* @isr
*/
ISR(FTM_2_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 2U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
           Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif

/* @brief FTM_3 */

#if ((defined GPT_FTM_3_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_3_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_3_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_3_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 3 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_3_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_3));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_0);
        #endif

        #if (defined PWM_FTM_3_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_0);
        #endif

        #if (defined ICU_FTM_3_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_0);
        #endif
        
        #if (defined OCU_FTM_3_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_1);
        #endif

        #if (defined PWM_FTM_3_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_1);
        #endif

        #if (defined ICU_FTM_3_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_1);
        #endif
        
        #if (defined OCU_FTM_3_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_3_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_3_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_3_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_3_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 3 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_3_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_3));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_2);
        #endif

        #if (defined PWM_FTM_3_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_2);
        #endif

        #if (defined ICU_FTM_3_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_2);
        #endif
        
        #if (defined OCU_FTM_3_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_3);
        #endif

        #if (defined PWM_FTM_3_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_3);
        #endif

        #if (defined ICU_FTM_3_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_3);
        #endif
        
        #if (defined OCU_FTM_3_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_3_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_3_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_3_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_3_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 3 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_3_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_3));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_4);
        #endif

        #if (defined PWM_FTM_3_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_4);
        #endif

        #if (defined ICU_FTM_3_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_4);
        #endif
        
        #if (defined OCU_FTM_3_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_5);
        #endif

        #if (defined PWM_FTM_3_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_5);
        #endif

        #if (defined ICU_FTM_3_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_5);
        #endif
        
        #if (defined OCU_FTM_3_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_3_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_3_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_3_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_3_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 3 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_3_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_3));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_6);
        #endif

        #if (defined PWM_FTM_3_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_6);
        #endif

        #if (defined ICU_FTM_3_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_6);
        #endif
        
        #if (defined OCU_FTM_3_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_3_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_7);
        #endif

        #if (defined PWM_FTM_3_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_7);
        #endif

        #if (defined ICU_FTM_3_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_3_CH_7);
        #endif
        
        #if (defined OCU_FTM_3_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_3_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_3_OVF_ISR_USED) || \
        (defined ICU_FTM_3_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 3 overflow
*
* @isr
*/
ISR(FTM_3_OVF_ISR)
{
#if(defined PWM_FTM_3_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_3);
#endif
#if (defined ICU_FTM_3_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_3);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_3_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 3 fault
*
* @isr
*/
ISR(FTM_3_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 3U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
            Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }    
    EXIT_INTERRUPT();
}
#endif  /*(defined PWM_FTM_3_FAULT_ISR_USED)*/

/* @brief FTM_4 */

#if ((defined GPT_FTM_4_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_4_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_4_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_4_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 4 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_4_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_4));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_0);
        #endif

        #if (defined PWM_FTM_4_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_0);
        #endif

        #if (defined ICU_FTM_4_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_0);
        #endif
        
        #if (defined OCU_FTM_4_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_1);
        #endif

        #if (defined PWM_FTM_4_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_1);
        #endif

        #if (defined ICU_FTM_4_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_1);
        #endif
        
        #if (defined OCU_FTM_4_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_4_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_4_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_4_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_4_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 4 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_4_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_4));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_2);
        #endif

        #if (defined PWM_FTM_4_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_2);
        #endif

        #if (defined ICU_FTM_4_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_2);
        #endif
        
        #if (defined OCU_FTM_4_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_3);
        #endif

        #if (defined PWM_FTM_4_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_3);
        #endif

        #if (defined ICU_FTM_4_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_3);
        #endif
        
        #if (defined OCU_FTM_4_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_4_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_4_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_4_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_4_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 4 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_4_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_4));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_4);
        #endif

        #if (defined PWM_FTM_4_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_4);
        #endif

        #if (defined ICU_FTM_4_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_4);
        #endif
        
        #if (defined OCU_FTM_4_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_5);
        #endif

        #if (defined PWM_FTM_4_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_5);
        #endif

        #if (defined ICU_FTM_4_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_5);
        #endif
        
        #if (defined OCU_FTM_4_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_4_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_4_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_4_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_4_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 4 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_4_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_4));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_6);
        #endif

        #if (defined PWM_FTM_4_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_6);
        #endif

        #if (defined ICU_FTM_4_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_6);
        #endif
        
        #if (defined OCU_FTM_4_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_4_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_7);
        #endif

        #if (defined PWM_FTM_4_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_7);
        #endif

        #if (defined ICU_FTM_4_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_4_CH_7);
        #endif
        
        #if (defined OCU_FTM_4_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_4_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_4_OVF_ISR_USED) || \
        (defined ICU_FTM_4_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 overflow
*
* @isr
*/
ISR(FTM_4_OVF_ISR)
{  
#if(defined PWM_FTM_4_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_4);
#endif
#if (defined ICU_FTM_4_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_4);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_4_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 fault
*
* @isr
*/
ISR(FTM_4_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 4U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
            Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif /*(defined PWM_FTM_4_FAULT_ISR_USED)*/

/* @brief FTM_5 */

#if ((defined GPT_FTM_5_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_5_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_5_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_5_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 5 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_5_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_5));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_0);
        #endif

        #if (defined PWM_FTM_5_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_0);
        #endif

        #if (defined ICU_FTM_5_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_0);
        #endif
        
        #if (defined OCU_FTM_5_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_1);
        #endif

        #if (defined PWM_FTM_5_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_1);
        #endif

        #if (defined ICU_FTM_5_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_1);
        #endif
        
        #if (defined OCU_FTM_5_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_5_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_5_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_5_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_5_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 5 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_5_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_5));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_2);
        #endif

        #if (defined PWM_FTM_5_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_2);
        #endif

        #if (defined ICU_FTM_5_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_2);
        #endif
        
        #if (defined OCU_FTM_5_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_3);
        #endif

        #if (defined PWM_FTM_5_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_3);
        #endif

        #if (defined ICU_FTM_5_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_3);
        #endif
        
        #if (defined OCU_FTM_5_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_5_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_5_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_5_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_5_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 5 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_5_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_5));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_4);
        #endif

        #if (defined PWM_FTM_5_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_4);
        #endif

        #if (defined ICU_FTM_5_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_4);
        #endif
        
        #if (defined OCU_FTM_5_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_5);
        #endif

        #if (defined PWM_FTM_5_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_5);
        #endif

        #if (defined ICU_FTM_5_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_5);
        #endif
        
        #if (defined OCU_FTM_5_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_5_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_5_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_5_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_5_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 5 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_5_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_5));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_6);
        #endif

        #if (defined PWM_FTM_5_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_6);
        #endif

        #if (defined ICU_FTM_5_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_6);
        #endif
        
        #if (defined OCU_FTM_5_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_5_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_7);
        #endif

        #if (defined PWM_FTM_5_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_7);
        #endif

        #if (defined ICU_FTM_5_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_5_CH_7);
        #endif
        
        #if (defined OCU_FTM_5_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_5_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_5_OVF_ISR_USED) || \
        (defined ICU_FTM_5_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 overflow
*
* @isr
*/
ISR(FTM_5_OVF_ISR)
{  
#if(defined PWM_FTM_5_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_5);
#endif
#if (defined ICU_FTM_5_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_5);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_5_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 fault
*
* @isr
*/
ISR(FTM_5_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 5U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
            Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif /*(defined PWM_FTM_5_FAULT_ISR_USED)*/

/* @brief FTM_6 */

#if ((defined GPT_FTM_6_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_6_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_6_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_6_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 6 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_6_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_6));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_0);
        #endif

        #if (defined PWM_FTM_6_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_0);
        #endif

        #if (defined ICU_FTM_6_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_0);
        #endif
        
        #if (defined OCU_FTM_6_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_1);
        #endif

        #if (defined PWM_FTM_6_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_1);
        #endif

        #if (defined ICU_FTM_6_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_1);
        #endif
        
        #if (defined OCU_FTM_6_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_6_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_6_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_6_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_6_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 6 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_6_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_6));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_2);
        #endif

        #if (defined PWM_FTM_6_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_2);
        #endif

        #if (defined ICU_FTM_6_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_2);
        #endif
        
        #if (defined OCU_FTM_6_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_3);
        #endif

        #if (defined PWM_FTM_6_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_3);
        #endif

        #if (defined ICU_FTM_6_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_3);
        #endif
        
        #if (defined OCU_FTM_6_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_6_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_6_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_6_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_6_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 6 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_6_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_6));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_4);
        #endif

        #if (defined PWM_FTM_6_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_4);
        #endif

        #if (defined ICU_FTM_6_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_4);
        #endif
        
        #if (defined OCU_FTM_6_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_5);
        #endif

        #if (defined PWM_FTM_6_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_5);
        #endif

        #if (defined ICU_FTM_6_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_5);
        #endif
        
        #if (defined OCU_FTM_6_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_6_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_6_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_6_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_6_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 6 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_6_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_6));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_6);
        #endif

        #if (defined PWM_FTM_6_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_6);
        #endif

        #if (defined ICU_FTM_6_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_6);
        #endif
        
        #if (defined OCU_FTM_6_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_6_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_7);
        #endif

        #if (defined PWM_FTM_6_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_7);
        #endif

        #if (defined ICU_FTM_6_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_6_CH_7);
        #endif
        
        #if (defined OCU_FTM_6_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_6_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_6_OVF_ISR_USED) || \
        (defined ICU_FTM_6_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 overflow
*
* @isr
*/
ISR(FTM_6_OVF_ISR)
{  
#if(defined PWM_FTM_6_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_6);
#endif
#if (defined ICU_FTM_6_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_6);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_6_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 fault
*
* @isr
*/
ISR(FTM_6_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 6U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
            Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif /*(defined PWM_FTM_6_FAULT_ISR_USED)*/

/* @brief FTM_7 */

#if ((defined GPT_FTM_7_CH_0_CH_1_ISR_USED) || (defined ICU_FTM_7_CH_0_CH_1_ISR_USED) || (defined PWM_FTM_7_CH_0_CH_1_ISR_USED) || (defined OCU_FTM_7_CH_0_CH_1_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 7 channel 0 - channel 1
*
* @isr
*/
ISR(FTM_7_CH_0_CH_1_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_7));

    if ((u32IsrStatus & FTM_CH_0_MASK_U32) == FTM_CH_0_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_0);
        #endif

        #if (defined PWM_FTM_7_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_0);
        #endif

        #if (defined ICU_FTM_7_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_0);
        #endif
        
        #if (defined OCU_FTM_7_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_0);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_1_MASK_U32) == FTM_CH_1_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_0_CH_1_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_1);
        #endif

        #if (defined PWM_FTM_7_CH_0_CH_1_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_1);
        #endif

        #if (defined ICU_FTM_7_CH_0_CH_1_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_1);
        #endif
        
        #if (defined OCU_FTM_7_CH_0_CH_1_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_1);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_7_CH_2_CH_3_ISR_USED) || (defined ICU_FTM_7_CH_2_CH_3_ISR_USED) || (defined PWM_FTM_7_CH_2_CH_3_ISR_USED) || (defined OCU_FTM_7_CH_2_CH_3_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 7 channel 2 - channel 3
*
* @isr
*/
ISR(FTM_7_CH_2_CH_3_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_7));

    if ((u32IsrStatus & FTM_CH_2_MASK_U32) == FTM_CH_2_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_2);
        #endif

        #if (defined PWM_FTM_7_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_2);
        #endif

        #if (defined ICU_FTM_7_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_2);
        #endif
        
        #if (defined OCU_FTM_7_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_2);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_3_MASK_U32) == FTM_CH_3_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_2_CH_3_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_3);
        #endif

        #if (defined PWM_FTM_7_CH_2_CH_3_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_3);
        #endif

        #if (defined ICU_FTM_7_CH_2_CH_3_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_3);
        #endif
        
        #if (defined OCU_FTM_7_CH_2_CH_3_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_3);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_7_CH_4_CH_5_ISR_USED) || (defined ICU_FTM_7_CH_4_CH_5_ISR_USED) || (defined PWM_FTM_7_CH_4_CH_5_ISR_USED) || (defined OCU_FTM_7_CH_4_CH_5_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 7 channel 4 - channel 5
*
* @isr
*/
ISR(FTM_7_CH_4_CH_5_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_7));

    if ((u32IsrStatus & FTM_CH_4_MASK_U32) == FTM_CH_4_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_4);
        #endif

        #if (defined PWM_FTM_7_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_4);
        #endif

        #if (defined ICU_FTM_7_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_4);
        #endif
        
        #if (defined OCU_FTM_7_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_4);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_5_MASK_U32) == FTM_CH_5_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_4_CH_5_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_5);
        #endif

        #if (defined PWM_FTM_7_CH_4_CH_5_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_5);
        #endif

        #if (defined ICU_FTM_7_CH_4_CH_5_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_5);
        #endif
        
        #if (defined OCU_FTM_7_CH_4_CH_5_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_5);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if ((defined GPT_FTM_7_CH_6_CH_7_ISR_USED) || (defined ICU_FTM_7_CH_6_CH_7_ISR_USED) || (defined PWM_FTM_7_CH_6_CH_7_ISR_USED) || (defined OCU_FTM_7_CH_6_CH_7_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 7 channel 6 - channel 7
*
* @isr
*/
ISR(FTM_7_CH_6_CH_7_ISR)
{
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(FTM_7));

    if ((u32IsrStatus & FTM_CH_6_MASK_U32) == FTM_CH_6_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_6);
        #endif

        #if (defined PWM_FTM_7_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_6);
        #endif

        #if (defined ICU_FTM_7_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_6);
        #endif
        
        #if (defined OCU_FTM_7_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_6);
        #endif
    }
                
    if ((u32IsrStatus & FTM_CH_7_MASK_U32) == FTM_CH_7_MASK_U32)
    {
        #if (defined GPT_FTM_7_CH_6_CH_7_ISR_USED)
        Gpt_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_7);
        #endif

        #if (defined PWM_FTM_7_CH_6_CH_7_ISR_USED)
        Pwm_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_7);
        #endif

        #if (defined ICU_FTM_7_CH_6_CH_7_ISR_USED)
        Icu_Ftm_ProcessInterrupt((uint8)FTM_7_CH_7);
        #endif
        
        #if (defined OCU_FTM_7_CH_6_CH_7_ISR_USED)
        Ocu_Ftm_ProcessCommonInterrupt((uint8)FTM_7_CH_7);
        #endif
    }                
    EXIT_INTERRUPT();
}
#endif

#if   ( (defined PWM_FTM_7_OVF_ISR_USED) || \
        (defined ICU_FTM_7_OVF_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 overflow
*
* @isr
*/
ISR(FTM_7_OVF_ISR)
{  
#if(defined PWM_FTM_7_OVF_ISR_USED)
    Pwm_Ftm_ProcessTofInterrupt(FTM_7);
#endif
#if (defined ICU_FTM_7_OVF_ISR_USED)
    Icu_Ftm_ProcessTofInterrupt(FTM_7);
#endif
    EXIT_INTERRUPT();
}
#endif

#if (defined PWM_FTM_7_FAULT_ISR_USED)
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0 fault
*
* @isr
*/
ISR(FTM_7_FAULT_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 7U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
            Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
    
    EXIT_INTERRUPT();
}
#endif /*(defined PWM_FTM_7_FAULT_ISR_USED)*/

#endif  /*(defined IPV_FTM)*/
#endif  /*(IPV_FTM == IPV_FTM_05_00_04_00)*/


#if ((IPV_FTM == IPV_FTM_04_00_29_00) || (!(defined IPV_FTM)) || (GPT_FTM_MODULE_SINGLE_INTERRUPT == STD_ON)|| (ICU_FTM_MODULE_SINGLE_INTERRUPT == STD_ON) || (PWM_FTM_MODULE_SINGLE_INTERRUPT == STD_ON)|| (OCU_FTM_MODULE_SINGLE_INTERRUPT == STD_ON))

#if ( (defined GPT_FTM_0_ISR_USED) || \
      (defined PWM_FTM_0_ISR_USED) || \
      (defined OCU_FTM_0_ISR_USED) || \
      (defined ICU_FTM_0_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 0
*
* @isr
*/
ISR(FTM_0_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 0U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
     /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(u8ModuleIdx));
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
#endif
#endif
  
#if ((defined PWM_FTM_0_ISR_USED) || (defined ICU_FTM_0_ISR_USED))
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32TofStatus = REG_READ32(FTM_SC_ADDR32(u8ModuleIdx)) & FTM_SC_TOF_OVF_U32;
  
    if(FTM_SC_TOF_OVF_U32 == u32TofStatus)
    {
#if(defined PWM_FTM_0_ISR_USED)
        Pwm_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
#if (defined ICU_FTM_0_ISR_USED)
        Icu_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
    }
#endif

    for (u8FTMchannel = 0U; u8FTMchannel < FTM_CHANNEL_MAX; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8FTMchannel)) == (uint8)(1U << u8FTMchannel))
        {
            #if (defined GPT_FTM_0_ISR_USED)
                 Gpt_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if(defined PWM_FTM_0_ISR_USED)
                 Pwm_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if(defined OCU_FTM_0_ISR_USED)
                 Ocu_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
            
            #if (defined ICU_FTM_0_ISR_USED)
                 Icu_Ftm_ProcessInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
        }
    }
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
           Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
#endif
#endif
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ( (defined GPT_FTM_1_ISR_USED) || \
      (defined PWM_FTM_1_ISR_USED) || \
      (defined OCU_FTM_1_ISR_USED) || \
      (defined ICU_FTM_1_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 1
*
* @isr
*/
ISR(FTM_1_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 1U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
     /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(u8ModuleIdx));
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
#endif
#endif

#if ((defined PWM_FTM_1_ISR_USED) || (defined ICU_FTM_1_ISR_USED))
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32TofStatus = REG_READ32(FTM_SC_ADDR32(u8ModuleIdx)) & FTM_SC_TOF_OVF_U32;
  
    if(FTM_SC_TOF_OVF_U32 == u32TofStatus)
    {
#if(defined PWM_FTM_1_ISR_USED)
        Pwm_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
#if (defined ICU_FTM_1_ISR_USED)
        Icu_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
    }
#endif

    for (u8FTMchannel = 0U; u8FTMchannel < FTM_CHANNEL_MAX; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8FTMchannel)) == (uint8)(1U << u8FTMchannel))
        {
            #if (defined GPT_FTM_1_ISR_USED)
                 Gpt_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if(defined PWM_FTM_1_ISR_USED)
                 Pwm_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
            
            #if(defined OCU_FTM_1_ISR_USED)
                 Ocu_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if (defined ICU_FTM_1_ISR_USED)
                 Icu_Ftm_ProcessInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
        }
    }
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
           Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
#endif
#endif
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ( (defined GPT_FTM_2_ISR_USED) || \
      (defined PWM_FTM_2_ISR_USED) || \
      (defined OCU_FTM_2_ISR_USED) || \
      (defined ICU_FTM_2_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2
*
* @isr
*/
ISR(FTM_2_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 2U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
     /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(u8ModuleIdx));
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
#endif
#endif
  
#if ((defined PWM_FTM_2_ISR_USED) || (defined ICU_FTM_2_ISR_USED))
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32TofStatus = REG_READ32(FTM_SC_ADDR32(u8ModuleIdx)) & FTM_SC_TOF_OVF_U32;

    if(FTM_SC_TOF_OVF_U32 == u32TofStatus)
    {
#if(defined PWM_FTM_2_ISR_USED)
        Pwm_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
#if (defined ICU_FTM_2_ISR_USED)
        Icu_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
    }
#endif

    for (u8FTMchannel = 0U; u8FTMchannel < FTM_CHANNEL_MAX; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8FTMchannel)) == (uint8)(1U << u8FTMchannel))
        {
            #if (defined GPT_FTM_2_ISR_USED)
                 Gpt_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if(defined PWM_FTM_2_ISR_USED)
                 Pwm_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
            
            #if(defined OCU_FTM_2_ISR_USED)
                 Ocu_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if (defined ICU_FTM_2_ISR_USED)
                 Icu_Ftm_ProcessInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
        }
    }
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
           Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
#endif
#endif
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ( (defined GPT_FTM_3_ISR_USED) || \
      (defined PWM_FTM_3_ISR_USED) || \
      (defined OCU_FTM_3_ISR_USED) || \
      (defined ICU_FTM_3_ISR_USED) )
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for FTM module 2
*
* @isr
*/
ISR(FTM_3_ISR)
{
     VAR(uint8,  AUTOMATIC) u8ModuleIdx = 3U;
     VAR(uint8,  AUTOMATIC) u8FTMchannel = 0U;
     /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32IsrStatus = REG_READ32(FTM_STATUS_ADDR32(u8ModuleIdx));
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON) 
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32FaultIsrStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleIdx));
#endif
#endif
  
#if ((defined PWM_FTM_3_ISR_USED) || (defined ICU_FTM_3_ISR_USED))
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32, MCL_CONST) u32TofStatus = REG_READ32(FTM_SC_ADDR32(u8ModuleIdx)) & FTM_SC_TOF_OVF_U32;
  
    if(FTM_SC_TOF_OVF_U32 == u32TofStatus)
    {
#if(defined PWM_FTM_3_ISR_USED)
        Pwm_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
#if (defined ICU_FTM_3_ISR_USED)
        Icu_Ftm_ProcessTofInterrupt(u8ModuleIdx);
#endif
    }
#endif

    for (u8FTMchannel = 0U; u8FTMchannel < FTM_CHANNEL_MAX; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8FTMchannel)) == (uint8)(1U << u8FTMchannel))
        {
            #if (defined GPT_FTM_3_ISR_USED)
                 Gpt_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if(defined PWM_FTM_3_ISR_USED)
                 Pwm_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
            
            #if(defined OCU_FTM_3_ISR_USED)
                 Ocu_Ftm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif

            #if (defined ICU_FTM_3_ISR_USED)
                 Icu_Ftm_ProcessInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
            #endif
        }
    }
#ifdef PWM_FAULT_SUPPORTED
#if (PWM_FAULT_SUPPORTED == STD_ON)
   
    for (u8FTMchannel = 0U; u8FTMchannel < FTM_FAULT_MAX  ; u8FTMchannel++)
    {
        if ((uint8)((uint8)u32FaultIsrStatus & ((uint8)(1U << u8FTMchannel))) == (uint8)(1U << u8FTMchannel))
        {
           Pwm_Ftm_ProcessFaultInterrupt((uint8)((uint8)(u8ModuleIdx<<FTM_MOD_SHIFT) + u8FTMchannel));
        }
    }
#endif
#endif
    /** @violates @ref FTM_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#endif /*((IPV_FTM == IPV_FTM_04_00_29_00) || (FTM_UNIFIED_INTERRUPTS == STD_ON))*/



#define MCL_STOP_SEC_CODE
/** @violates @ref FTM_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref FTM_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"


#ifdef __cplusplus
}
#endif
#endif/*(USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON) || (USE_PWM_MODULE==STD_ON))*/
/** @} */
