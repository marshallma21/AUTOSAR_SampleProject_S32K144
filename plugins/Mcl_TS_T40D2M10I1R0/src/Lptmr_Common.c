/**
*   @file    Lptmr_Common.c
*   @implements Lptmr_Common.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LPTMR driver source file.
*   @details Common LPTMR routines.
*
*   @addtogroup LPTMR_MODULE
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
*   @file    Lptmr_Common.c
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section LPTMR_COMMON_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section LPTMR_COMMON_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section LPTMR_COMMON_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This is mentained because the names are according to Autosar requirement. 
* 
* @section LPTMR_COMMON_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section LPTMR_COMMON_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope should have internal linkage unless external linkage is required.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Lptmr_Common.c
* 
*/

#include "modules.h"
#if ((USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON))
/** @violates @ref LPTMR_COMMON_C_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Std_Types.h"

#if (USE_GPT_MODULE==STD_ON)
   #include "Gpt_Lptmr.h"
#endif

#if (USE_ICU_MODULE==STD_ON)
    #include "Icu_Cfg.h"
    #include "Icu_Lptmr.h"
#endif

#include "Reg_eSys_Lptmr.h"
#define USER_MODE_REG_PROT_ENABLED (STD_OFF)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Lptmr_Common.c
* @brief          Source file version information  
*/
#define LPTMR_COMMON_VENDOR_ID_C                       43
/** @violates @ref LPTMR_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref LPTMR_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref LPTMR_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPTMR_COMMON_AR_RELEASE_REVISION_VERSION_C     2
/** @violates @ref LPTMR_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPTMR_COMMON_SW_MAJOR_VERSION_C                1
/** @violates @ref LPTMR_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPTMR_COMMON_SW_MINOR_VERSION_C                0
/** @violates @ref LPTMR_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPTMR_COMMON_SW_PATCH_VERSION_C                1
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != MODULES_AR_RELEASE_MINOR_VERSION_H))
        #error "AutoSar Version Numbers of Lptmr_Common.c and modules.h are different"
    #endif

    #if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Lptmr_Common.c and Std_Types.h are different"
    #endif

    #if (USE_GPT_MODULE==STD_ON)
        #if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != GPT_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
             (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != GPT_LPTMR_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lptmr_Common.c and Gpt_Lptmr.h are different"
        #endif
    #endif

    #if (USE_ICU_MODULE==STD_ON)
        #if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
             (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG))
            #error "AutoSar Version Numbers of Lptmr_Common.c and Icu_Cfg.h are different"
        #endif

        #if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
             (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_LPTMR_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lptmr_Common.c and Icu_Lptmr.h are different"
        #endif
    #endif
    
    #if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Ftm.c and SilRegMacros.h are different"
    #endif

#endif /*DISABLE_MCAL_INTERMODULE_ASR_CHECK*/

/* Check if source file and Reg_eSys_Lptmr.h header file are of the same vendor */
#if (LPTMR_COMMON_VENDOR_ID_C != REG_ESYS_LPTMR_VENDOR_ID)
    #error "Lptmr_Common.c and Reg_eSys_Lptmr.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_Lptmr.h header file are of the same Autosar version */
#if ((LPTMR_COMMON_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (LPTMR_COMMON_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (LPTMR_COMMON_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lptmr_Common.c and Reg_eSys_Lptmr.h are different"
#endif

/* Check if source file and Reg_eSys_Lptmr.h header file are of the same Software version */
#if ((LPTMR_COMMON_SW_MAJOR_VERSION_C != REG_ESYS_LPTMR_SW_MAJOR_VERSION) || \
     (LPTMR_COMMON_SW_MINOR_VERSION_C != REG_ESYS_LPTMR_SW_MINOR_VERSION) || \
     (LPTMR_COMMON_SW_PATCH_VERSION_C != REG_ESYS_LPTMR_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lptmr_Common.c and Reg_eSys_Lptmr.h are different"
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

#define MCL_START_SEC_CONST_32
/** @violates @ref LPTMR_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPTMR_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief base address array for LPTMR
*/
/** @violates @ref LPTMR_COMMON_C_REF_5 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(uint32, MCL_CONST) LPTMR_BASE_ADDR32[] = 
{
#ifdef LPTMR0_BASEADDR
    LPTMR0_BASEADDR
#endif
};

#define MCL_STOP_SEC_CONST_32
/** @violates @ref LPTMR_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPTMR_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref LPTMR_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPTMR_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/** 
@brief LPTMR_0 ISR declarations
@{
*/
ISR(LPTMR_0_CH_0_ISR);
/**@}*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if  ((defined ICU_LPTMR_0_USED) && (defined GPT_LPTMR_0_USED))
#error "ICU and GPT resource conflict for LPTMR 0 hw unit"
#endif

#if ((defined ICU_LPTMR_0_CH_0_ISR_USED) || (defined GPT_LPTMR_0_CH_0_ISR_USED))
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for LPTMR module 0
*
* @isr
*/
ISR(LPTMR_0_CH_0_ISR)
{
    #if(defined ICU_LPTMR_0_CH_0_ISR_USED)
        Icu_Lptmr_ProcessInterrupt();
    #endif
    
    #if(defined GPT_LPTMR_0_CH_0_ISR_USED)
        Gpt_Lptmr_ProcessCommonInterrupt();
    #endif

    /** @violates @ref LPTMR_COMMON_C_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif

#define MCL_STOP_SEC_CODE
/** @violates @ref LPTMR_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPTMR_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

#endif/*(USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON))*/

#ifdef __cplusplus
}
#endif

/** @} */
