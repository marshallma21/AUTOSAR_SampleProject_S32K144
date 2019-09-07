/**
*   @file    LPit_Common.c
*   @implements LPit_Common.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LPIT driver source file.
*   @details Common LPIT routines.
*
*   @addtogroup LPIT_MODULE
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
*   @file    LPit_Common.c
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section LPIT_COMMON_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section LPIT_COMMON_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section LPIT_COMMON_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This is mentained because the names are according to Autosar requirement. 
* 
* @section LPIT_COMMON_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section LPIT_COMMON_C_REF_5
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
* @file           LPit_Common.c
* 
*/
#include "modules.h"
#if ((USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON))

/** @violates @ref LPIT_COMMON_C_REF_2 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Std_Types.h"

#if (USE_GPT_MODULE==STD_ON)
   #include "Gpt_LPit.h"
#endif

#if (USE_ICU_MODULE==STD_ON)
    #include "Icu_Cfg.h"
    #include "Icu_LPit.h"
#endif

#include "Reg_eSys_LPit.h"

#define USER_MODE_REG_PROT_ENABLED (STD_OFF)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           LPit_Common.c
* @brief          Source file version information  
*/
#define LPIT_COMMON_VENDOR_ID_C                       43
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPIT_COMMON_AR_RELEASE_REVISION_VERSION_C     2
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPIT_COMMON_SW_MAJOR_VERSION_C                1
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPIT_COMMON_SW_MINOR_VERSION_C                0
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define LPIT_COMMON_SW_PATCH_VERSION_C                1
/** @violates @ref LPIT_COMMON_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
         (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != MODULES_AR_RELEASE_MINOR_VERSION_H))
        #error "AutoSar Version Numbers of LPit_Common.c and modules.h are different"
    #endif

    #if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LPit_Common.c and Std_Types.h are different"
    #endif

    #if (USE_GPT_MODULE==STD_ON)
        #if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != GPT_LPIT_AR_RELEASE_MAJOR_VERSION) || \
             (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != GPT_LPIT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of LPit_Common.c and Gpt_LPit.h are different"
        #endif
    #endif

    #if (USE_ICU_MODULE==STD_ON)
        #if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
             (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG))
            #error "AutoSar Version Numbers of LPit_Common.c and Icu_Cfg.h are different"
        #endif

        #if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_LPIT_AR_RELEASE_MAJOR_VERSION) || \
             (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_LPIT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of LPit_Common.c and Icu_LPit.h are different"
        #endif
    #endif
    
    #if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of LPit_Common.c and SilRegMacros.h are different"
    #endif

#endif 

/* Check if source file and Reg_eSys_LPit.h header file are of the same vendor */
#if (LPIT_COMMON_VENDOR_ID_C != REG_ESYS_LPIT_VENDOR_ID)
    #error "LPit_Common.c and Reg_eSys_LPit.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_LPit.h header file are of the same Autosar version */
#if ((LPIT_COMMON_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_COMMON_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_COMMON_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of LPit_Common.c and Reg_eSys_LPit.h are different"
#endif

/* Check if source file and Reg_eSys_LPit.h header file are of the same Software version */
#if ((LPIT_COMMON_SW_MAJOR_VERSION_C != REG_ESYS_LPIT_SW_MAJOR_VERSION) || \
     (LPIT_COMMON_SW_MINOR_VERSION_C != REG_ESYS_LPIT_SW_MINOR_VERSION) || \
     (LPIT_COMMON_SW_PATCH_VERSION_C != REG_ESYS_LPIT_SW_PATCH_VERSION))
    #error "Software Version Numbers of LPit_Common.c and Reg_eSys_LPit.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define LPIT_CHANNEL_MAX (4U)
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
/** @violates @ref LPIT_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPIT_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief base address array for LPIT
*/
/** @violates @ref LPIT_COMMON_C_REF_5 MISRA 2004 Required Rule 8.10 External Linkage */
CONST(uint32, MCL_CONST) LPIT_BASE_ADDR32[] = {
#ifdef LPIT0_BASEADDR
    LPIT0_BASEADDR
#endif
};

#define MCL_STOP_SEC_CONST_32
/** @violates @ref LPIT_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPIT_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref LPIT_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPIT_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/** 
@brief LPIT_0 independent ISR declarations
@{
*/
#if ( (defined GPT_LPIT_0_CH_0_ISR_USED) || (defined ICU_LPIT_0_CH_0_ISR_USED) )
ISR(LPIT_0_CH_0_ISR);
#endif
#if ( (defined GPT_LPIT_0_CH_1_ISR_USED) || (defined ICU_LPIT_0_CH_1_ISR_USED) )
ISR(LPIT_0_CH_1_ISR);
#endif
#if ( (defined GPT_LPIT_0_CH_2_ISR_USED) || (defined ICU_LPIT_0_CH_2_ISR_USED) )
ISR(LPIT_0_CH_2_ISR);
#endif
#if ( (defined GPT_LPIT_0_CH_3_ISR_USED) || (defined ICU_LPIT_0_CH_3_ISR_USED) )
ISR(LPIT_0_CH_3_ISR);
#endif
#if ( (defined GPT_LPIT_0_ISR_USED) || (defined ICU_LPIT_0_ISR_USED) || (GPT_LPIT_MODULE_SINGLE_INTERRUPT == STD_ON) || (ICU_LPIT_MODULE_SINGLE_INTERRUPT == STD_ON) )
ISR(LPIT_0_ISR);
#endif

/**@}*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if  ((defined GPT_LPIT_0_CH_0_ISR_USED) && (defined ICU_LPIT_0_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for LPIT 0 channel 0 hw unit"
#endif
#if ( (defined GPT_LPIT_0_CH_0_ISR_USED) || (defined ICU_LPIT_0_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for LPIT module 0 channel 0
*
* @isr
*/
/*================================================================================================*/
ISR(LPIT_0_CH_0_ISR)
{
    VAR(uint8,      AUTOMATIC) u8LPitchannel = 0U;
    VAR(uint8,      AUTOMATIC) u8ModuleIdx = 0U;
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32,   MCL_CONST) u32IsrStatus = REG_READ32(LPIT_MSR_ADDR32(u8ModuleIdx));

    if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8LPitchannel)) == (uint8)(1U << u8LPitchannel))
    {
        #if (defined GPT_LPIT_0_CH_0_ISR_USED)
            Gpt_LPit_ProcessCommonInterrupt(u8LPitchannel);
        #endif

        #if (defined ICU_LPIT_0_CH_0_ISR_USED)
            Icu_LPit_ProcessInterrupt(u8LPitchannel);
        #endif
    }
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if  ((defined GPT_LPIT_0_CH_1_ISR_USED) && (defined ICU_LPIT_0_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for LPIT 0 channel 1 hw unit"
#endif
#if ( (defined GPT_LPIT_0_CH_1_ISR_USED) || (defined ICU_LPIT_0_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for LPIT module 0 channel 1
*
* @isr
*/
/*================================================================================================*/
ISR(LPIT_0_CH_1_ISR)
{
    VAR(uint8,      AUTOMATIC) u8LPitchannel = 1U;
    VAR(uint8,      AUTOMATIC) u8ModuleIdx = 0U;
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32,   MCL_CONST) u32IsrStatus = REG_READ32(LPIT_MSR_ADDR32(u8ModuleIdx));
    
    if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8LPitchannel)) == (uint8)(1U << u8LPitchannel))
    {
        #if (defined GPT_LPIT_0_CH_1_ISR_USED)
            Gpt_LPit_ProcessCommonInterrupt(u8LPitchannel);
        #endif

        #if (defined ICU_LPIT_0_CH_1_ISR_USED)
            Icu_LPit_ProcessInterrupt(u8LPitchannel);
        #endif
    }
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if  ((defined GPT_LPIT_0_CH_2_ISR_USED) && (defined ICU_LPIT_0_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for LPIT 0 channel 2 hw unit"
#endif
#if ( (defined GPT_LPIT_0_CH_2_ISR_USED) || (defined ICU_LPIT_0_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for LPIT module 0 channel 2
*
* @isr
*/
/*================================================================================================*/
ISR(LPIT_0_CH_2_ISR)
{
    VAR(uint8,      AUTOMATIC) u8LPitchannel = 2U;
    VAR(uint8,      AUTOMATIC) u8ModuleIdx = 0U;
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32,   MCL_CONST) u32IsrStatus = REG_READ32(LPIT_MSR_ADDR32(u8ModuleIdx));

    if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8LPitchannel)) == (uint8)(1U << u8LPitchannel))
    {
        #if (defined GPT_LPIT_0_CH_2_ISR_USED)
            Gpt_LPit_ProcessCommonInterrupt(u8LPitchannel);
        #endif

        #if (defined ICU_LPIT_0_CH_2_ISR_USED)
            Icu_LPit_ProcessInterrupt(u8LPitchannel);
        #endif
    }
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if  ((defined GPT_LPIT_0_CH_3_ISR_USED) && (defined ICU_LPIT_0_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for LPIT 0 channel 3 hw unit"
#endif
#if ( (defined GPT_LPIT_0_CH_3_ISR_USED) || (defined ICU_LPIT_0_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief          Independent interrupt handler.
* @details        Interrupt handler for LPIT module 0 channel 3
*
* @isr
*/
/*================================================================================================*/
ISR(LPIT_0_CH_3_ISR)
{
    VAR(uint8,      AUTOMATIC) u8LPitchannel = 3U;
    VAR(uint8,      AUTOMATIC) u8ModuleIdx = 0U;
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32,   MCL_CONST) u32IsrStatus = REG_READ32(LPIT_MSR_ADDR32(u8ModuleIdx));

    if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8LPitchannel)) == (uint8)(1U << u8LPitchannel))
    {
        #if (defined GPT_LPIT_0_CH_3_ISR_USED)
            Gpt_LPit_ProcessCommonInterrupt(u8LPitchannel);
        #endif

        #if (defined ICU_LPIT_0_CH_3_ISR_USED)
            Icu_LPit_ProcessInterrupt(u8LPitchannel);
        #endif
    }
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#if ( (defined GPT_LPIT_0_ISR_USED) || (defined ICU_LPIT_0_ISR_USED) || (GPT_LPIT_MODULE_SINGLE_INTERRUPT == STD_ON) || (ICU_LPIT_MODULE_SINGLE_INTERRUPT == STD_ON) )
ISR(LPIT_0_ISR)
{
    VAR(uint8,      AUTOMATIC) u8LPitchannel = 0U;
    VAR(uint8,      AUTOMATIC) u8ModuleIdx = 0U;
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    CONST(uint32,   MCL_CONST) u32IsrStatus = REG_READ32(LPIT_MSR_ADDR32(u8ModuleIdx));
 for (u8LPitchannel = 0U; u8LPitchannel < LPIT_CHANNEL_MAX; u8LPitchannel++)
    {
        if ((uint8)((uint8)u32IsrStatus & (uint8)(1U << u8LPitchannel)) == (uint8)(1U << u8LPitchannel))
        {
            #if (defined GPT_LPIT_0_ISR_USED)
                Gpt_LPit_ProcessCommonInterrupt(u8LPitchannel);
            #endif

            #if (defined ICU_LPIT_0_ISR_USED)
                Icu_LPit_ProcessInterrupt(u8LPitchannel);
            #endif
        }
    }
    /** @violates @ref LPIT_COMMON_C_REF_1 Cast from unsigned int to pointer */
    EXIT_INTERRUPT();
}
#endif

#define MCL_STOP_SEC_CODE
/** @violates @ref LPIT_COMMON_C_REF_4 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
  before '#include'.*/
/** @violates @ref LPIT_COMMON_C_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

#endif /*(USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON)*/

#ifdef __cplusplus
}
#endif
/** @} */
