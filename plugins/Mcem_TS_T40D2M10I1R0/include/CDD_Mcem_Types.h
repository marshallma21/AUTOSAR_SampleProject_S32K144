/**
*   @file    CDD_Mcem_Types.h
*   @implements     CDD_Mcem_Types.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MCEM HLL Types
*   @details Type and domain declarations used in the upper layer of the MCEM module
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

#ifndef CDD_MCEM_TYPES_H
#define CDD_MCEM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
 * @page misra_violations MISRA-C:2004 violations
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
#include "Mcem_IPW_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define CDD_MCEM_TYPES_VENDOR_ID                    43
#define CDD_MCEM_TYPES_MODULE_ID                    0
#define CDD_MCEM_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define CDD_MCEM_TYPES_AR_RELEASE_MINOR_VERSION     2
#define CDD_MCEM_TYPES_AR_RELEASE_REVISION_VERSION  2
#define CDD_MCEM_TYPES_SW_MAJOR_VERSION             1
#define CDD_MCEM_TYPES_SW_MINOR_VERSION             0
#define CDD_MCEM_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcem_IPW_Types.h header file are of the same vendor */
#if (CDD_MCEM_TYPES_VENDOR_ID != MCEM_IPW_TYPES_VENDOR_ID)
    #error "CDD_Mcem_Types.h and Mcem_IPW_Types.h have different Vendor ids"
#endif
/* Check if current file and Mcem_IPW_Types header file are of the same Autosar version */
#if ((CDD_MCEM_TYPES_AR_RELEASE_MAJOR_VERSION != MCEM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCEM_TYPES_AR_RELEASE_MINOR_VERSION != MCEM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCEM_TYPES_AR_RELEASE_REVISION_VERSION != MCEM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcem_Types.h and Mcem_IPW_Types.h are different"
#endif
/* Check if current file and Mcem_IPW_Types header file are of the same Software version */
#if ((CDD_MCEM_TYPES_SW_MAJOR_VERSION != MCEM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (CDD_MCEM_TYPES_SW_MINOR_VERSION != MCEM_IPW_TYPES_SW_MINOR_VERSION) || \
     (CDD_MCEM_TYPES_SW_PATCH_VERSION != MCEM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcem_Types.h and Mcem_IPW_Types.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* Additional value indicating pending fault when returning from Mcem_Geterrors() */
#define E_FAULT_DETECTED                ((Std_ReturnType)2)

/* Additional value indicating known spurious NMI cause */
#define E_FCCU_SPURIOUS_NMI             ((Std_ReturnType)2)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          MCEM Driver State Enum.
* @details        Enumeration covering possible states of the driver.
*
* @implements     Mcem_StateType_enumeration
*/
typedef enum 
{
    MCEM_S_UNINIT           = 0,        /**< @brief MCEM module has not been initialized. */
    MCEM_S_INITIALIZED      = 1,        /**< @brief MCEM module has been initialized without hard-lock. */
    MCEM_S_LOCKED           = 2        /**< @brief MCEM module has been initialized with hard-lock. */
} Mcem_StateType;


/**
* @brief          MCEM Driver Public functions State.
* @details        Each MCEM public function that is not re-entrant shall use this states
*                 to protect from preempting itself.
*/
typedef enum 
{
    MCEM_S_IDLE = 0,       /**< @brief Function can be executed. */
    MCEM_S_BUSY = 1        /**< @brief Function was invoked and has not finished yet. */
} Mcem_FunctionStateType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief          The notification functions shall have one parameter and no return value.
 *
 */
typedef void (*Mcem_NotifyType)(Mcem_FaultType FaultID);

/**
 * @brief          The notification functions which does not have input parameters.
 *
 */
typedef void (*Mcem_NotifyVoidType)(void);

/**
* @brief          Fault container struct type.
* @details        MCEM container for storing the errors.
*/
typedef struct
{
    Std_ReturnType                 nErrorStatus;        /**< @brief Stored return value of Mcem_Geterrors(). */
    Mcem_IPW_FaultContainerType    au32Faults;          /**< @brief Aggregated fault status container. */
} Mcem_FaultContainerType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*CDD_MCEM_TYPES_H*/

/** @} */
