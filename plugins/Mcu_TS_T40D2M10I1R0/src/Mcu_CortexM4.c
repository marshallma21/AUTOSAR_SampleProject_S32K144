/**
*   @file    Mcu_CortexM4.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - ARM CortexM4 Registers and Macros Definitions.
*   @details ARM CortexM4 Registers and Macros Definitions.
*
*   @addtogroup CORTEXM_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
@file        Mcu_CortexM4.c
*/


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_CortexM4_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_CortexM4_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_CortexM4_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_CortexM4_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_CortexM4_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section Mcu_CortexM4_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Cfg.h"
#include "Mcu_CortexM4.h"
#include "StdRegMacros.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           CORTEXM4.c
* @requirements   
*/
#define MCU_CORTEXM4_VENDOR_ID_C                       43
/** @violates @ref Mcu_CortexM4_c_REF_3 MISRA 2004 Required Rule 1.4,The compiler/linker shall be
checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref Mcu_CortexM4_c_REF_3 MISRA 2004 Required Rule 1.4,The compiler/linker shall be
checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref Mcu_CortexM4_c_REF_3 MISRA 2004 Required Rule 1.4,The compiler/linker shall be
checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION_C     2
#define MCU_CORTEXM4_SW_MAJOR_VERSION_C                1
#define MCU_CORTEXM4_SW_MINOR_VERSION_C                0
#define MCU_CORTEXM4_SW_PATCH_VERSION_C                1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg.h header file have same versions */
#if (MCU_CORTEXM4_VENDOR_ID_C != MCU_CORTEXM4_VENDOR_ID)
#error "Mcu_CortexM4.h and Mcu_CortexM4.c have different vendor IDs"
#endif
#if ((MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION_C != MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION_C != MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION_C != MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_CortexM4.c and Mcu_CortexM4.h are different"
#endif
#if ((MCU_CORTEXM4_SW_MAJOR_VERSION_C != MCU_CORTEXM4_SW_MAJOR_VERSION) || \
     (MCU_CORTEXM4_SW_MINOR_VERSION_C != MCU_CORTEXM4_SW_MINOR_VERSION) || \
     (MCU_CORTEXM4_SW_PATCH_VERSION_C != MCU_CORTEXM4_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_CortexM4.c and Mcu_CortexM4.h are different"
#endif

/* Check if source file and StdRegMacros.h header file have same versions */
#if (MCU_CORTEXM4_VENDOR_ID_C != MCU_CFG_VENDOR_ID)
#error "CortexM4.h and Mcu_Cfg.h have different vendor IDs"
#endif
#if ((MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION_C != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION_C != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION_C != MCU_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_CortexM4.c and Mcu_Cfg.h are different"
#endif
#if ((MCU_CORTEXM4_SW_MAJOR_VERSION_C != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_CORTEXM4_SW_MINOR_VERSION_C != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_CORTEXM4_SW_PATCH_VERSION_C != MCU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_CortexM4.c and Mcu_Cfg.h are different"
#endif

/* Check if source file and StdRegMacros.h header file have same versions */
#if (MCU_CORTEXM4_VENDOR_ID_C != STDREGMACROS_VENDOR_ID)
#error "Reg_eSys_CortexM4.h and StdRegMacros.h have different vendor IDs"
#endif
#if ((MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION_C != STDREGMACROS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_CortexM4.c and StdRegMacros.h are different"
#endif
#if ((MCU_CORTEXM4_SW_MAJOR_VERSION_C != STDREGMACROS_SW_MAJOR_VERSION) || \
     (MCU_CORTEXM4_SW_MINOR_VERSION_C != STDREGMACROS_SW_MINOR_VERSION) || \
     (MCU_CORTEXM4_SW_PATCH_VERSION_C != STDREGMACROS_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_CortexM4.c and StdRegMacros.h are different"
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS                                                  
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                     LOCAL FUNCTION 
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_CortexM4_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#if (MCU_PERFORM_RESET_API == STD_ON)
 /**
* @brief        The function initiates a system reset request to reset the SoC.
* @details      The function initiates a system reset request to reset the SoC
*
* @param[in]    none
*
* @return void
*
*/
FUNC(void, MCU_CODE) Mcu_CM4_SystemReset(void)
{

    ASM_KEYWORD(" dsb");               /* All memory accesses have to be completed before reset */
    /** @violates @ref Mcu_CortexM4_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_CortexM4_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( CM4_AIRCR_BASEADDR, (uint32)(CM4_AIRCR_VECTKEY(0x5FAU) | (REG_READ32(CM4_AIRCR_BASEADDR) & CM4_AIRCR_PRIGROUP_MASK) | CM4_AIRCR_SYSRESETREQ_MASK ));
    ASM_KEYWORD(" dsb");               /* All memory accesses have to be completed */

}

#endif


 /**
* @brief        The function initiates a system reset request to reset the SoC.
* @details      The function initiates a system reset request to reset the SoC
*
* @param[in]    none
*
* @return void
* @violates @ref Mcu_CortexM4_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(void, MCU_CODE) Mcu_CM4_EnableDeepSleep(void)
{
    /** @violates @ref Mcu_CortexM4_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_CortexM4_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32( CM4_SCR_BASEADDR, CM4_SCR_SLEEPDEEP_MASK32, CM4_SCR_SLEEPDEEP_U32);

}


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_CortexM4_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_CortexM4_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif



/** @} */
