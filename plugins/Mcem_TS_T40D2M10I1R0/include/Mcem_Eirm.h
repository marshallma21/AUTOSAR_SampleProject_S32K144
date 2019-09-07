/**
*   @file    Mcem_Eirm.h
*   @implements     Mcem_Eirm.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MEMU IP layer API
*   @details MEMU internal IP API of the MCEM module
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

#ifndef MCEM_EIRM_H
#define MCEM_EIRM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 *
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcem_Eirm_h_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice.
 * This is not a violation since all header files are protected against multiple inclusions.
 *
 * @section Mcem_Eirm_h_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
 * compatibility. 
 *
 * @section Mcem_Eirm_h_REF_3
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 *
 * @section Mcem_Eirm_h_REF_4
 * Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be precedded by other preprocessor directives or comments.
 * It is required for MEMMAP requirement.
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions shall
 * not be reused. Ipv name start with letter E which is reserved for Error status. However, EIRM is unique. 
 *
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcem_Eirm_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
 
#define EIRM_VENDOR_ID                    43
#define EIRM_MODULE_ID                    0
#define EIRM_AR_RELEASE_MAJOR_VERSION     4
#define EIRM_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Mcem_Eirm_h_REF_2 Exceeds 31 characters */
#define EIRM_AR_RELEASE_REVISION_VERSION  2
#define EIRM_SW_MAJOR_VERSION             1
#define EIRM_SW_MINOR_VERSION             0
#define EIRM_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcem_Eirm_Types.h header file are of the same vendor */
#if (EIRM_VENDOR_ID != EIRM_TYPES_VENDOR_ID)
    #error "Mcem_Eirm.h and Mcem_Eirm_Types.h have different Vendor ids"
#endif
/* Check if current file and Mcem_Eirm_Types.h header file are of the same Autosar version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION != EIRM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EIRM_AR_RELEASE_MINOR_VERSION != EIRM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EIRM_AR_RELEASE_REVISION_VERSION != EIRM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_Eirm.h and Mcem_Eirm_Types.h are different"
#endif
/* Check if current file and Mcem_Eirm_Types.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION != EIRM_TYPES_SW_MAJOR_VERSION) || \
     (EIRM_SW_MINOR_VERSION != EIRM_TYPES_SW_MINOR_VERSION) || \
     (EIRM_SW_PATCH_VERSION != EIRM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_Eirm.h and Mcem_Eirm_Types.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define EIRM_REG_SIZE_U8          32U
#define EIRM_FAULT_INDEX_U8       1U
#define EIRM_SHIFT_BIT_U32        (0x00000001UL)

#define EIRM_NO_ERRORS_U32        (0x00000000UL)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define MCEM_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcem_Eirm_h_REF_1 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"
extern P2CONST(Mcem_Eirm_ConfigType, AUTOMATIC, MCEM_APPL_CONST) Mcem_Eirm_pConfigPtr;
#define MCEM_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcem_Eirm_h_REF_1 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"
#define MCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Mcem_Eirm_h_REF_1 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"
#if (MCEM_EIRM_CORTEX_M0 == STD_ON)
extern CONST(uint32,MCEM_CONST) Mcem_u32EirmBitPosition[MCEM_EIRM_MAX_NO_FAULTS_M0_U8];
#else
extern CONST(uint32,MCEM_CONST) Mcem_u32EirmBitPosition[MCEM_EIRM_MAX_NO_FAULTS_U8];
#endif
#define MCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Mcem_Eirm_h_REF_1 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCEM_START_SEC_CODE
/* @violates @ref Mcem_Eirm_h_REF_1 Repeatedly included file. */
#include "Mcem_MemMap.h"

FUNC(void, MCEM_CODE) Mcem_Eirm_Init(P2CONST(Mcem_Eirm_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr);

FUNC(void, MCEM_CODE) Mcem_Eirm_InjectFault(VAR(Mcem_FaultType, AUTOMATIC) nFaultId);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_Eirm_ClearFault(VAR(Mcem_FaultType, AUTOMATIC) nFaultId);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_Eirm_GetErrors(VAR(uint32,AUTOMATIC) pFaultContainer[]);

FUNC(boolean, MCEM_CODE) Mcem_Eirm_CheckValidFault (VAR(Mcem_FaultType, AUTOMATIC)nFaultId);

#define MCEM_STOP_SEC_CODE
/* @violates @ref Mcem_Eirm_h_REF_1 Repeatedly included file. */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*MCEM_EIRM_H*/

/** @} */
