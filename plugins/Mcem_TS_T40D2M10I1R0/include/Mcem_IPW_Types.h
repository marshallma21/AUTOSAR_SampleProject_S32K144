/**
*   @file    Mcem_IPW_Types.h
*   @implements     Mcem_IPW_Types.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MCEM IPW Types
*   @details Declarations used in the IP wrapper layer of the MCEM module
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

#ifndef MCEM_IPW_TYPES_H
#define MCEM_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcem_IPW_Types_h_REF_1
 * Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * This violation is due to use of range checking macros as functions.
 *
 * @section Mcem_IPW_Types_h_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Allow at least 31 character significance.
 * External identifiers are not distinct in the first 6 characters due to AUTOSAR compatibility
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
#include "Mcem_Eirm_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCEM_IPW_TYPES_VENDOR_ID                    43
#define MCEM_IPW_TYPES_MODULE_ID                    0
#define MCEM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MCEM_IPW_TYPES_AR_RELEASE_MINOR_VERSION     2
#define MCEM_IPW_TYPES_AR_RELEASE_REVISION_VERSION  2
#define MCEM_IPW_TYPES_SW_MAJOR_VERSION             1
#define MCEM_IPW_TYPES_SW_MINOR_VERSION             0
#define MCEM_IPW_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcem_Memu_Types.h header file are of the same vendor */
#if (MCEM_IPW_TYPES_VENDOR_ID != EIRM_TYPES_VENDOR_ID)
    #error "Mcem_IPW_Types.h and Mcem_Memu_Types.h have different Vendor ids"
#endif
/* Check if current file and Mcem_Memu_Types header file are of the same Autosar version */
#if ((MCEM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != EIRM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCEM_IPW_TYPES_AR_RELEASE_MINOR_VERSION != EIRM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCEM_IPW_TYPES_AR_RELEASE_REVISION_VERSION != EIRM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_IPW_Types.h and Mcem_Memu_Types.h are different"
#endif
/* Check if current file and Mcem_Memu_Types.h header file are of the same Software version */
#if ((MCEM_IPW_TYPES_SW_MAJOR_VERSION != EIRM_TYPES_SW_MAJOR_VERSION) || \
     (MCEM_IPW_TYPES_SW_MINOR_VERSION != EIRM_TYPES_SW_MINOR_VERSION) || \
     (MCEM_IPW_TYPES_SW_PATCH_VERSION != EIRM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcem_IPW_Types.h and Mcem_Memu_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* FCCU NCF base number (for the list of FCCU faults to be 0-based */
#define MCEM_EIRM_NCF_BASE                               0U

/* Total count of MEMU Errors */
#define MCEM_EIRM_NCF_TOTAL_NUMBER                       (MCEM_EIRM_MAX_NO_FAULTS_U8)

/* Total count of all errors */
#define MCEM_NCF_TOTAL_NUMBER                       (MCEM_EIRM_NCF_BASE + MCEM_EIRM_NCF_TOTAL_NUMBER)

/* FCCU Specific Errors */

/* NCF[0] Single error correctable in lower TCM */
/* @violates @ref Mcem_IPW_Types_h_REF_2 31 character significance */
#define MCEM_EIRM_MEN0_SINGLE_CORRECTION             0U
/* NCF[1] Multipler error noncorrectable in lower TCM */
#define MCEM_EIRM_MEN0_NON_CORRECTABLE               1U
/* NCF[0] Single error correctable in upper TCM */
/* @violates @ref Mcem_IPW_Types_h_REF_2 31 character significance */
#define MCEM_EIRM_MEN1_SINGLE_CORRECTION             2U
/* NCF[1] Multipler error noncorrectable in upper TCM */
#define MCEM_EIRM_MEN1_NON_CORRECTABLE               3U


/* Check whether fault ID is in the proper range (FCCU, MEMU, or any) */
/* @violates @ref Mcem_IPW_Types_h_REF_1 Function-like macro defined */
#define MCEM_FAULT_IN_EIRM_RANGE(FaultID)   ((FaultID) < (MCEM_EIRM_NCF_BASE + MCEM_NCF_TOTAL_NUMBER))

/* @violates @ref Mcem_IPW_Types_h_REF_1 Function-like macro defined */
#define MCEM_FAULT_IN_RANGE(FaultID)        (MCEM_FAULT_IN_EIRM_RANGE((FaultID)))

/* @violates @ref Mcem_IPW_Types_h_REF_1 Function-like macro defined */
#define MCEM_FAULT_IS_VALID(FaultID)        (MCEM_FAULT_IN_RANGE( (FaultID) ))

/*
* Shift and mask used to access fault container slot 
* 1 word per slot ~ 32bits = 2^5
*/
#define MCEM_FAULT_CONTAINER_SHIFT          5U
#define MCEM_FAULT_CONTAINER_MASK           ((1UL << MCEM_FAULT_CONTAINER_SHIFT)-1UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* An array containing unified faults reported by FCCU and MEMU */
typedef uint32 Mcem_IPW_FaultContainerType[EIRM_FAULT_REGISTER_COUNT_U8 ];

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*MCEM_IPW_TYPES_H*/

/** @} */
