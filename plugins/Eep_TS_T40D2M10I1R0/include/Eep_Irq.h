
#ifndef EEP_IRQ_H
#define EEP_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section eep_irq_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping  
* 
* @section [global]
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_IRQ_VENDOR_ID                       43
#define EEP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define EEP_IRQ_AR_RELEASE_MINOR_VERSION        2
#define EEP_IRQ_AR_RELEASE_REVISION_VERSION     2
#define EEP_IRQ_SW_MAJOR_VERSION                1
#define EEP_IRQ_SW_MINOR_VERSION                0
#define EEP_IRQ_SW_PATCH_VERSION                1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep.h header file are of the same vendor */
#if (EEP_IRQ_VENDOR_ID != EEP_VENDOR_ID)
    #error "Eep_Irq.h and Eep.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Eep.h header file are of the same Autosar version */
    #if ((EEP_IRQ_AR_RELEASE_MAJOR_VERSION != EEP_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_IRQ_AR_RELEASE_MINOR_VERSION != EEP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eep_Irq.h and Eep.h are different"
    #endif
#endif
/* Check if current file and Eep.h header file are of the same software version */
#if ((EEP_IRQ_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION) || \
     (EEP_IRQ_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION) || \
     (EEP_IRQ_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eep_Irq.h and Eep.h are different"
#endif

/*==================================================================================================
*                              VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                              FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief    Start of Eep section CODE 
*/
#define EEP_START_SEC_CODE

/* 
* @violates @ref eep_irq_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"


/**
* @brief    Stop of Eep section CODE 
*/
#define EEP_STOP_SEC_CODE

/* 
* @violates @ref eep_irq_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*EEP_IRQ_H*/

