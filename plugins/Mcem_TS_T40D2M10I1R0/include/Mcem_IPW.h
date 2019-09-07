/**
*   @file    Mcem_IPW.h
*   @implements     Mcem_IPW.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MCEM IP Wrapper API
*   @details Declaration of the internal IP Wrapper API of the MCEM module.
*
*   @addtogroup MCEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Eim Erm
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

#ifndef MCEM_IPW_H
#define MCEM_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 *
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcem_IPW_h_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice
 * This is not a violation since all header files are protected against multiple inclusions
 *
 * @section Mcem_IPW_h_REF_2
 * Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined is required for expand the expression of Mcal_Trusted_Call
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcem_Types.h"
#include "Mcem_Eirm.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCEM_IPW_VENDOR_ID                    43
#define MCEM_IPW_MODULE_ID                    0
#define MCEM_IPW_AR_RELEASE_MAJOR_VERSION     4
#define MCEM_IPW_AR_RELEASE_MINOR_VERSION     2
#define MCEM_IPW_AR_RELEASE_REVISION_VERSION  2
#define MCEM_IPW_SW_MAJOR_VERSION             1
#define MCEM_IPW_SW_MINOR_VERSION             0
#define MCEM_IPW_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CDD_Mcem_Types.h header file are of the same vendor */
#if (MCEM_IPW_VENDOR_ID != CDD_MCEM_TYPES_VENDOR_ID)
#error "Mcem_IPW.h and CDD_Mcem_Types.h have different vendor ids"
#endif
/* Check if current file and CDD_Mcem_Types.h header file are of the same Autosar version */
#if ((MCEM_IPW_AR_RELEASE_MAJOR_VERSION    != CDD_MCEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCEM_IPW_AR_RELEASE_MINOR_VERSION    != CDD_MCEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCEM_IPW_AR_RELEASE_REVISION_VERSION != CDD_MCEM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcem_IPW.h and CDD_Mcem_Types.h are different"
#endif
/* Check if current file and CDD_Mcem_Types.h header file are of the same Software version */
#if ((MCEM_IPW_SW_MAJOR_VERSION != CDD_MCEM_TYPES_SW_MAJOR_VERSION) || \
     (MCEM_IPW_SW_MINOR_VERSION != CDD_MCEM_TYPES_SW_MINOR_VERSION) || \
     (MCEM_IPW_SW_PATCH_VERSION != CDD_MCEM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcem_IPW.h and CDD_Mcem_Types.h are different"
#endif


/* Check if current file and Mcem_Memu.h header file are of the same vendor */
#if (MCEM_IPW_VENDOR_ID != EIRM_VENDOR_ID)
    #error "Mcem_IPW.h and Mcem_Memu.h have different Vendor ids"
#endif
/* Check if current file and Mcem_Memu.h header file are of the same Autosar version */
#if ((MCEM_IPW_AR_RELEASE_MAJOR_VERSION != EIRM_AR_RELEASE_MAJOR_VERSION) || \
     (MCEM_IPW_AR_RELEASE_MINOR_VERSION != EIRM_AR_RELEASE_MINOR_VERSION) || \
     (MCEM_IPW_AR_RELEASE_REVISION_VERSION != EIRM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_IPW.h and Mcem_Memu.h are different"
#endif
/* Check if current file and Mcem_Fccu.h header file are of the same Software version */
#if ((MCEM_IPW_SW_MAJOR_VERSION != EIRM_SW_MAJOR_VERSION) || \
     (MCEM_IPW_SW_MINOR_VERSION != EIRM_SW_MINOR_VERSION) || \
     (MCEM_IPW_SW_PATCH_VERSION != EIRM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_IPW.h and Mcem_Memu.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* @violates @ref Mcem_IPW_h_REF_2 function-like macro, required for wrapping empty api */
#define     Mcem_IPW_LockConfiguration()
/* @violates @ref Mcem_IPW_h_REF_2 function-like macro, required for wrapping empty api */
#define     Mcem_IPW_CheckNMI()                     ((Std_ReturnType)E_NOT_OK)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCEM_START_SEC_CODE
/* @violates @ref Mcem_IPW_h_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Mcem_MemMap.h"

FUNC(Std_ReturnType, MCEM_CODE) Mcem_IPW_Init(P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr);
FUNC(boolean, MCEM_CODE)    Mcem_IPW_CheckValidFault (VAR(Mcem_FaultType, AUTOMATIC)nFaultId);
FUNC(void, MCEM_CODE) Mcem_IPW_InjectFault(VAR(Mcem_FaultType, AUTOMATIC) nFaultId);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_IPW_GetErrors(P2VAR(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_DATA) pErrorContainer, boolean bNmiCall);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_IPW_ClearFaults(VAR(Mcem_FaultType, AUTOMATIC) nFaultId, boolean bNmiCall);

#define MCEM_STOP_SEC_CODE
/* @violates @ref Mcem_IPW_h_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*MCEM_IPW_H*/

/** @} */
