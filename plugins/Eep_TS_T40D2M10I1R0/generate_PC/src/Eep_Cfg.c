[!CODE!][!//
/**
*   @file    Eep_Cfg.c
*   @implements Eep_Cfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Definitions of all Pre-compile configuration structures.
*
*   @addtogroup EEP
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
* @section eep_cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section eep_cfg_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions involing function pointers must be to/from integral types.
* This violation is due to EEP213.
* 
* @section eep_cfg_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This violation is due to EEP213.
* 
* @section eep_cfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Eep_Cfg.c or Eep_PBcfg.c). There is no need to put the declaration into Eep_Cfg.h and made it 
* accessible for all modules which includes Eep.h/Eep_Cfg.h.
* 
* @section eep_cfg_c_REF_5
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier pattern.
* This is just a matter of a symbol specified in the configuration.    
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
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
[!INDENT "0"!]
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep.h"
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    #include "Dem.h"
[!ENDIF!][!//
[!ENDINDENT!][!//
#ifdef EEP_PRECOMPILE_SUPPORT

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_PCFG_C                      43
#define EEP_AR_RELEASE_MAJOR_VERSION_PCFG_C       4
#define EEP_AR_RELEASE_MINOR_VERSION_PCFG_C       2
#define EEP_AR_RELEASE_REVISION_VERSION_PCFG_C    2
#define EEP_SW_MAJOR_VERSION_PCFG_C               1
#define EEP_SW_MINOR_VERSION_PCFG_C               0
#define EEP_SW_PATCH_VERSION_PCFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_VENDOR_ID_PCFG_C != EEP_VENDOR_ID)
    #error "Eep_Cfg.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_PCFG_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_PCFG_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_PCFG_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Cfg.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_PCFG_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_PCFG_C != EEP_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_PCFG_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Cfg.c and Eep.h are different"
#endif

[!INDENT "0"!][!//
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    [!WS "1"!]/* Check if source file and Dem header file are of the same version */
    [!WS "1"!]#if ((EEP_AR_RELEASE_MAJOR_VERSION_PCFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
    [!WS "1"!]     (EEP_AR_RELEASE_MINOR_VERSION_PCFG_C != DEM_AR_RELEASE_MINOR_VERSION) \
    [!WS "1"!]    )
    [!WS "1"!]#error "AutoSar Version Numbers of Eep_Cfg.c and Dem.h are different"
    [!WS "1"!]#endif
    #endif
[!ENDIF!][!//
[!ENDINDENT!][!//

[!INCLUDE "Eep_VersionCheck.m"!][!//

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


[!ENDCODE!]


#endif /* EEP_PRECOMPILE_SUPPORT */
#ifdef __cplusplus
}
#endif

/** @}*/
