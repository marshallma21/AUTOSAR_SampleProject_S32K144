/**
* 
*   
*   @version 1.0.1
*   @brief   AUTOSAR Eep - FLASH (EEP) functions
*   @details Contains functions for accessing FTFE from the EEP driver perspective
*
*   @addtogroup  Eep
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section eep_irq_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
* 
* @section eep_irq_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section eep_irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section eep_irq_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by smcal coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to EEP.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep.h"
#include "StdRegMacros.h"
#include "Reg_eSys_Ftfc.h"
#include "MemIf_Types.h"
#include "Eep_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_IRQ_VENDOR_ID_C                       43
#define EEP_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define EEP_IRQ_AR_RELEASE_MINOR_VERSION_C        2
#define EEP_IRQ_AR_RELEASE_REVISION_VERSION_C     2
#define EEP_IRQ_SW_MAJOR_VERSION_C                1
#define EEP_IRQ_SW_MINOR_VERSION_C                0
#define EEP_IRQ_SW_PATCH_VERSION_C                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep.h header file are of the same vendor */
#if (EEP_IRQ_VENDOR_ID_C != EEP_VENDOR_ID)
    #error "Eep_Irq.c and Eep.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Eep.h header file are of the same Autosar version */
    #if ((EEP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EEP_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IRQ_AR_RELEASE_MINOR_VERSION_C != EEP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep_Irq.c and Eep.h are different"
    #endif
#endif
/* Check if current file and Eep.h header file are of the same software version */
#if ((EEP_IRQ_SW_MAJOR_VERSION_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_IRQ_SW_MINOR_VERSION_C != EEP_SW_MINOR_VERSION) || \
     (EEP_IRQ_SW_PATCH_VERSION_C != EEP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eep_Irq.c and Eep.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros.h header file are of the same Autosar version */
    #if ((EEP_IRQ_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IRQ_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep_Irq.c and StdRegMacros.h are different"
    #endif
#endif

/* Check if current file and Reg_eSys_Ftfc.h header file are of the same vendor */
#if (EEP_IRQ_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Eep_Irq.c and Reg_eSys_Ftfc.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Reg_eSys_Ftfc.h header file are of the same Autosar version */
    #if ((EEP_IRQ_AR_RELEASE_MAJOR_VERSION_C != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IRQ_AR_RELEASE_MINOR_VERSION_C != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep_Irq.c and Reg_eSys_Ftfc.h are different"
    #endif
#endif
/* Check if current file and Reg_eSys_Ftfc.h header file are of the same software version */
#if ((EEP_IRQ_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (EEP_IRQ_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (EEP_IRQ_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eep_Irq.c and Reg_eSys_Ftfc.h are different"
#endif

/* Check if current file and Eep_Irq.h header file are of the same vendor */
#if (EEP_IRQ_VENDOR_ID_C != EEP_IRQ_VENDOR_ID)
    #error "Eep_Irq.c and Eep_Irq.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Eep_Irq.h header file are of the same Autosar version */
    #if ((EEP_IRQ_AR_RELEASE_MAJOR_VERSION_C != EEP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IRQ_AR_RELEASE_MINOR_VERSION_C != EEP_IRQ_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep_Irq.c and Eep_Irq.h are different"
    #endif
#endif
/* Check if current file and Eep_Irq.h header file are of the same software version */
#if ((EEP_IRQ_SW_MAJOR_VERSION_C != EEP_IRQ_SW_MAJOR_VERSION) || \
     (EEP_IRQ_SW_MINOR_VERSION_C != EEP_IRQ_SW_MINOR_VERSION) || \
     (EEP_IRQ_SW_PATCH_VERSION_C != EEP_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eep_Irq.c and Eep_Irq.h are different"
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
