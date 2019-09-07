/**
*   @file    Reg_eSys_CortexM4.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - ARM CortexM4 Registers and Macros Definitions.
*   @details ARM CortexM4 Registers and Macros Definitions.
*
*   @addtogroup DMA_DRIVER
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
@file        Reg_eSys_CortexM4.h
*/


#ifndef REG_ESYS_CORTEXM4_H
#define REG_ESYS_CORTEXM4_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_CortexM4_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
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
#include "Mcal.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_CORTEXM4.h
* @requirements   
*/
#define REG_ESYS_CORTEXM4_VENDOR_ID                       43
#define REG_ESYS_CORTEXM4_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_CORTEXM4_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_CORTEXM4_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_CORTEXM4_SW_MAJOR_VERSION                1
#define REG_ESYS_CORTEXM4_SW_MINOR_VERSION                0
#define REG_ESYS_CORTEXM4_SW_PATCH_VERSION                1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != REG_ESYS_CORTEXM4_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != REG_ESYS_CORTEXM4_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Reg_eSys_CortexM4.h are different"
    #endif
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
/* Memory mapping of Cortex-M4 Hardware */
/* Application Interrupt and Reset Control Register */
#define CM4_AIRCR_BASEADDR    ((uint32)0xE000ED0CU)               /* System Control Block Base Address  */
                        
/* AIRCR Bit Fields */
#define CM4_AIRCR_VECTRESET_MASK             0x1u
#define CM4_AIRCR_VECTRESET_SHIFT            0u
#define CM4_AIRCR_VECTRESET_WIDTH            1u
/** @violates @ref Reg_eSys_CortexM4_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define CM4_AIRCR_VECTRESET(x)               (((uint32)(((uint32)(x))<<CM4_AIRCR_VECTRESET_SHIFT))&CM4_AIRCR_VECTRESET_MASK)
#define CM4_AIRCR_VECTCLRACTIVE_MASK         0x2u
#define CM4_AIRCR_VECTCLRACTIVE_SHIFT        1u
#define CM4_AIRCR_VECTCLRACTIVE_WIDTH        1u
/** @violates @ref Reg_eSys_CortexM4_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define CM4_AIRCR_VECTCLRACTIVE(x)           (((uint32)(((uint32)(x))<<CM4_AIRCR_VECTCLRACTIVE_SHIFT))&CM4_AIRCR_VECTCLRACTIVE_MASK)
#define CM4_AIRCR_SYSRESETREQ_MASK           0x4u
#define CM4_AIRCR_SYSRESETREQ_SHIFT          2u
#define CM4_AIRCR_SYSRESETREQ_WIDTH          1u
/** @violates @ref Reg_eSys_CortexM4_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define CM4_AIRCR_SYSRESETREQ(x)             (((uint32)(((uint32)(x))<<CM4_AIRCR_SYSRESETREQ_SHIFT))&CM4_AIRCR_SYSRESETREQ_MASK)
#define CM4_AIRCR_PRIGROUP_MASK              0x700u
#define CM4_AIRCR_PRIGROUP_SHIFT             8u
#define CM4_AIRCR_PRIGROUP_WIDTH             3u
/** @violates @ref Reg_eSys_CortexM4_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define CM4_AIRCR_PRIGROUP(x)                (((uint32)(((uint32)(x))<<CM4_AIRCR_PRIGROUP_SHIFT))&CM4_AIRCR_PRIGROUP_MASK)
#define CM4_AIRCR_ENDIANNESS_MASK            0x8000u
#define CM4_AIRCR_ENDIANNESS_SHIFT           15u
#define CM4_AIRCR_ENDIANNESS_WIDTH           1u
/** @violates @ref Reg_eSys_CortexM4_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define CM4_AIRCR_ENDIANNESS(x)              (((uint32)(((uint32)(x))<<CM4_AIRCR_ENDIANNESS_SHIFT))&CM4_AIRCR_ENDIANNESS_MASK)
#define CM4_AIRCR_VECTKEY_MASK               0xFFFF0000u
#define CM4_AIRCR_VECTKEY_SHIFT              16u
#define CM4_AIRCR_VECTKEY_WIDTH              16u
/** @violates @ref Reg_eSys_CortexM4_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define CM4_AIRCR_VECTKEY(x)                 (((uint32)(((uint32)(x))<<CM4_AIRCR_VECTKEY_SHIFT))&CM4_AIRCR_VECTKEY_MASK)

/* System Control Register */
#define CM4_SCR_BASEADDR    ((uint32)0xE000ED10U)

#define CM4_SCR_SLEEPDEEP_MASK32    ((uint32)0x00000004U)
#define CM4_SCR_SLEEPDEEP_U32       (CM4_SCR_SLEEPDEEP_MASK32)

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


#endif /* REG_ESYS_CORTEXM4_H */

/** @} */
