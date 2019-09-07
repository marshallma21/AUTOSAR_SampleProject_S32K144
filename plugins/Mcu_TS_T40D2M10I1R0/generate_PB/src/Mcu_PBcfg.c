/**
*   @file    Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @implements Mcu_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCU
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


#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed
* between a pointer to object type and a different pointer to object type.
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and
* functions shall not be reused
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is requiered.
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_8
* Violates MISRA 2004 Required Rule 8.12, when an array is declared with external linkage, it's size shall be stated explicitly
* or defined implicitly by initialisation
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_9
* Violates MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*
* @section Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_10
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"

#include "Reg_eSys_PCC.h"
#include "Reg_eSys_PMC.h"
#include "Reg_eSys_RCM.h"
#include "Reg_eSys_SCG.h"
#include "Reg_eSys_SIM.h"
#include "Reg_eSys_SMC.h"
#include "Reg_eSys_CMU.h"

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                     43
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C      2
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C   2
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C              1
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C              0
#define MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != MCU_VENDOR_ID)
    #error "Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcu.h have different vendor ids"
#endif
/* Check if current file and MCU header file are of the same Autosar version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcu.h are different"
#endif
/* Check if current file and MCU header file are of the same Software version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcu.h are different"
#endif

/* Check if source file and Reg_eSys_PCC.h are from the same vendor */
#if (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_PCC_VENDOR_ID)
    #error "Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_PCC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_PCC.h are of the same Autosar version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PCC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PCC_AR_RELEASE_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PCC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_PCC.h are different"
#endif
/*Check if source file and Reg_eSys_PCC.h are of the same Software version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_PCC_SW_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_PCC_SW_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_PCC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_PCC.h are different"
#endif

/* Check if source file and Reg_eSys_SMC.h are from the same vendor */
#if (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_SMC_VENDOR_ID)
    #error "Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SMC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SMC.h are of the same Autosar version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SMC.h are different"
#endif
/*Check if source file and Reg_eSys_SMC.h are of the same Software version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_SMC_SW_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_SMC_SW_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SMC.h are different"
#endif

/* Check if source file and Reg_eSys_SIM.h are from the same vendor */
#if (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_SIM_VENDOR_ID)
    #error "Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SIM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SIM.h are of the same Autosar version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SIM_AR_RELEASE_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SIM.h are different"
#endif
/*Check if source file and Reg_eSys_SIM.h are of the same Software version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_SIM_SW_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_SIM_SW_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SIM.h are different"
#endif

/* Check if source file and Reg_eSys_SCG.h are from the same vendor */
#if (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_SCG_VENDOR_ID)
    #error "Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SCG.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SCG.h are of the same Autosar version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SCG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SCG_AR_RELEASE_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SCG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SCG.h are different"
#endif
/*Check if source file and Reg_eSys_SCG.h are of the same Software version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_SCG_SW_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_SCG_SW_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_SCG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_SCG.h are different"
#endif

/* Check if source file and Reg_eSys_RCM.h are from the same vendor */
#if (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_RCM_VENDOR_ID)
    #error "Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_RCM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_RCM.h are of the same Autosar version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_RCM.h are different"
#endif
/*Check if source file and Reg_eSys_RCM.h are of the same Software version */
#if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_RCM_SW_MAJOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_RCM_SW_MINOR_VERSION) || \
     (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_RCM.h are different"
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dem.h are different"
    #endif
#endif
#endif

[!INCLUDE "Mcu_VersionCheck_Src_PB.m"!][!//

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
[!INCLUDE "Mcu_RegOperations.m"!]
[!INCLUDE "Mcu_checkvalues.m"!]


[!CALL "McuLinkerSymbols", "Type" = "'PB'"!]

[!CALL "Mcu_Ram_Config", "Type" = "'PB'"!]

[!CALL "Mcu_Mode_Config", "Type" = "'PB'"!]

[!CALL "SIM_Clock_Config", "Type" = "'PB'"!]

[!CALL "SOSC_Clock_Config", "Type" = "'PB'"!]

[!CALL "SIRC_Clock_Config", "Type" = "'PB'"!]

[!CALL "FIRC_Clock_Config", "Type" = "'PB'"!]

[!CALL "SPLL_Clock_Config", "Type" = "'PB'"!]

[!CALL "SCG_Clock_Config", "Type" = "'PB'"!]

[!CALL "MC_CMU_Config", "Type" = "'PB'"!]

[!CALL "PCC_Registers_Config", "Type" = "'PB'"!]

[!CALL "PCC_Clock_Config", "Type" = "'PB'"!]

[!CALL "Mcu_Clock_Config", "Type" = "'PB'"!]

[!CALL "Reset_Config", "Type" = "'PB'"!]

[!CALL "SIM_Config", "Type" = "'PB'"!]

[!CALL "PMC_Config", "Type" = "'PB'"!]

[!CALL "SMC_Config", "Type" = "'PB'"!]

[!CALL "Mcu_HwIPs_Config", "Type" = "'PB'"!]

[!CALL "Mcu_Config", "Type" = "'PB'"!]



#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

