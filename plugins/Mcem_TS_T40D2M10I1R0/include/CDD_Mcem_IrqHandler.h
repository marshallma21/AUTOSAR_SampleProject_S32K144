/**
*   @file    CDD_Mcem_IrqHandler.h
*   @implements     CDD_Mcem_IrqHandler.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - ALARM Interrupt handler API
*   @details Upper layer of the ALARM itnerrupt handled by MCEM
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

#ifndef CDD_MCEM_IRQHANDLER_H
#define CDD_MCEM_IRQHANDLER_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 *
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 *
 * @section CDD_Mcem_IrqHandler_h_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice
 * This is not a violation since all header files are protected against multiple inclusions
 *
 * @section CDD_Mcem_IrqHandler_h_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
 * compatibility
 */



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "CDD_Mcem_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_MCEM_IRQHANDLER_VENDOR_ID                    43
#define CDD_MCEM_IRQHANDLER_MODULE_ID                    0
/* @violates @ref CDD_Mcem_IrqHandler_h_REF_2 Exceeds 31 characters */
#define CDD_MCEM_IRQHANDLER_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref CDD_Mcem_IrqHandler_h_REF_2 Exceeds 31 characters */
#define CDD_MCEM_IRQHANDLER_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref CDD_Mcem_IrqHandler_h_REF_2 Exceeds 31 characters */
#define CDD_MCEM_IRQHANDLER_AR_RELEASE_REVISION_VERSION  2
#define CDD_MCEM_IRQHANDLER_SW_MAJOR_VERSION             1
#define CDD_MCEM_IRQHANDLER_SW_MINOR_VERSION             0
#define CDD_MCEM_IRQHANDLER_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Mcem_Types.h file are of the same vendor */
#if (CDD_MCEM_IRQHANDLER_VENDOR_ID != CDD_MCEM_TYPES_VENDOR_ID)
#error "CDD_Mcem_IrqHandler.h and CDD_Mcem_Types.h have different vendor ids"
#endif
/* Check if current file and CDD_Mcem_Types.h file are of the same Autosar version */
#if ((CDD_MCEM_IRQHANDLER_AR_RELEASE_MAJOR_VERSION    != CDD_MCEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCEM_IRQHANDLER_AR_RELEASE_MINOR_VERSION    != CDD_MCEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCEM_IRQHANDLER_AR_RELEASE_REVISION_VERSION != CDD_MCEM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcem_IrqHandler.h and CDD_Mcem_Types.h are different"
#endif
/* Check if current file and CDD_Mcem_Types.h file are of the same software version */
#if ((CDD_MCEM_IRQHANDLER_SW_MAJOR_VERSION != CDD_MCEM_TYPES_SW_MAJOR_VERSION) || \
     (CDD_MCEM_IRQHANDLER_SW_MINOR_VERSION != CDD_MCEM_TYPES_SW_MINOR_VERSION) || \
     (CDD_MCEM_IRQHANDLER_SW_PATCH_VERSION != CDD_MCEM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcem_IrqHandler.h and CDD_Mcem_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
/* @violates @ref CDD_Mcem_IrqHandler_h_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Mcem_MemMap.h"
#ifdef MCEM_FCCU_SUPPORT
FUNC(void,MCEM_CODE) Mcem_AlarmRoutine(VAR(Mcem_FaultType,AUTOMATIC) nFaultId);
FUNC(void,MCEM_CODE) Mcem_CfgToRoutine(void);
#endif
#define MCEM_STOP_SEC_CODE
/* @violates @ref CDD_Mcem_IrqHandler_h_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*CDD_MCEM_IRQHANDLER_H*/

/** @} */
