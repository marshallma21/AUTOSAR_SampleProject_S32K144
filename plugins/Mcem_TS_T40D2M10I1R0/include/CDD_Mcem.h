/**
*   @file    CDD_Mcem.h
*   @implements     CDD_Mcem.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MCEM Module API header.
*   @details Main API definition for the MCEM module
*
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

#ifndef CDD_MCEM_H
#define CDD_MCEM_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section CDD_Mcem_h_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice
 * This is not a violation since all header files are protected against multiple inclusions
 *
 * @section CDD_Mcem_h_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
 * compatibility
 *
 * @section CDD_Mcem_h_REF_3
 * Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 * This violation is due to use of range checking macros as functions.
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
#include "CDD_Mcem_Cfg.h"
#if(STD_ON == MCEM_DEM_EXTENDED_DATA)
    #include "Mcem_DemErrors.h"
    #include "Dem.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCEM_VENDOR_ID                    43
#define MCEM_MODULE_ID                    0U
/* @violates @ref CDD_Mcem_h_REF_2 Exceeds 31 characters */
#define MCEM_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref CDD_Mcem_h_REF_2 Exceeds 31 characters */
#define MCEM_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref CDD_Mcem_h_REF_2 Exceeds 31 characters */
#define MCEM_AR_RELEASE_REVISION_VERSION  2
#define MCEM_SW_MAJOR_VERSION             1
#define MCEM_SW_MINOR_VERSION             0
#define MCEM_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check for CDD_Mcem_Cfg.h versions */
/* Check if current file and MCEM configuration header file are of the same vendor */
#if (MCEM_VENDOR_ID != CDD_MCEM_VENDOR_ID_CFG)
    #error "CDD_Mcem.h and CDD_Mcem_Cfg.h have different vendor ids"
#endif

/* Check if current file and MCEM configuration header file are of the same Autosar version */
#if ((MCEM_AR_RELEASE_MAJOR_VERSION    != CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCEM_AR_RELEASE_MINOR_VERSION    != CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCEM_AR_RELEASE_REVISION_VERSION != CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of CDD_Mcem.h and CDD_Mcem_Cfg.h are different"
#endif
/* Check if current file and MCEM configuration header file are of the same software version */
#if ((MCEM_SW_MAJOR_VERSION != CDD_MCEM_SW_MAJOR_VERSION_CFG) || \
     (MCEM_SW_MINOR_VERSION != CDD_MCEM_SW_MINOR_VERSION_CFG) || \
     (MCEM_SW_PATCH_VERSION != CDD_MCEM_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of CDD_Mcem.h and CDD_Mcem_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief ID of MCEM Instance.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_INSTANCE_ID               0U
/**
* @brief API service ID for Mcem_Init function.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_INIT_ID                   0U
/**
* @brief API service ID for Mcem_InjectFaults function.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_INJECT_FAULT_ID           1U
/**
* @brief API service ID for Mcem_GetErrors function.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_GET_ERRORS_ID             2U
/**
* @brief API service ID for Mcem_ClearFaults function.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_CLEAR_FAULTS_ID           3U
/**
* @brief API service ID for Mcem_GetVersionInfo function.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_GETVERSIONINFO_ID         5U
/**
* @brief API service ID for Mcem_AlarmRoutine function.
* @details Parameters used when raising an error/exception.
* */
#define MCEM_ALARMROUTINE_ID           6U


/**
* @brief   API service is called while driver not initialized.
**/
#define MCEM_E_UNINIT                  0x02U
/**
* @brief   API service Mcem_Init is called with wrong parameter.
**/
#define MCEM_E_PARAM_CONFIG            0x04U
/**
* @brief   API service Mcem_GetVersionInfo is called with a wrong parameter.
**/
#define MCEM_E_PARAM_VINFO             0x08U
/**
* @brief   API service is called with a wrong parameter.
**/
#define MCEM_E_PARAM_FAULT             0x10U
/**
* @brief   API service is called while driver is locked.
**/
#define MCEM_E_CFG_LOCK                0x11U
/**
* @brief   API service is called while same non-reentrant service is running.
**/
#define MCEM_E_PREEMPTION              0x12U  
/**
* @brief   API service is called while driver does not permit the service to run.
**/
#define MCEM_E_FORBIDDEN_INVOCATION    0x14U


/**
* @brief   Access macro for querying collected fault status.
* @details This macro provides access to the individual fault status from the
*          collection filled by a call to the Mcem_Geterrors() function. 
* @param[in] pError Collected fault status structure (Mcem_FaultContainerType).
* @param[in] nFault Fault ID to be queried.
* @return logical
* @retval ==0 The given fault is not asserted or the ID is not valid. 
* @retval !=0 The given fault is asserted.
* @api
*/
/**
* @implements     MCEM_FAULT_PENDING_Activity 
* @violates @ref CDD_Mcem_h_REF_3 Function-like macro defined 
*/
#define MCEM_FAULT_PENDING( pError, nFault ) \
    (0UL != \
      ( MCEM_FAULT_IN_RANGE( (nFault) )      ?                                                     \
            (((pError)->au32Faults[ (nFault)>>MCEM_FAULT_CONTAINER_SHIFT ]) &                      \
             (1UL << ((nFault)&MCEM_FAULT_CONTAINER_MASK))                                         \
            )    /* nFault in range */ :                                                           \
             0UL /* invalid nFault */                                                              \
       )                                                                                           \
    )

/**
* @brief   Access macro for stored Mcem_Geterrors() return status.
* @details This macro provides access to the stored return value as returned by the call to the Mcem_Geterrors() function. 
* @param[in] pError Collected fault status structure (Mcem_FaultContainerType).
* @return         Std_ReturnType
* @retval E_OK               No fault is pending.
* @retval E_FAULT_DETECTED   There is at least one logged fault.
* @retval E_NOT_OK           Otherwise (wrong driver state, error occured while querying faults in the hardware)
* @api
*/
/**
* @implements     MCEM_GETERRORS_STATUS_Activity
* @violates @ref CDD_Mcem_h_REF_3 Function-like macro defined 
*/
#define MCEM_GETERRORS_STATUS( pError )    ((pError)->nErrorStatus)


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
/* @violates @ref CDD_Mcem_h_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Mcem_MemMap.h"

FUNC(Std_ReturnType, MCEM_CODE) Mcem_Init(P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr);

FUNC(void, MCEM_CODE) Mcem_InjectFaults(VAR(Mcem_FaultType, AUTOMATIC) nFaultId);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_GetErrors(P2VAR(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_DATA) pErrorContainer);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_ClearFaults(VAR(Mcem_FaultType, AUTOMATIC) nFaultId);

#ifdef MCEM_FCCU_EXTRA_NMI_API
  #if (STD_ON == MCEM_FCCU_EXTRA_NMI_API)
FUNC(Std_ReturnType, MCEM_CODE) Mcem_GetErrorsNMI(P2VAR(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_DATA) pErrorContainer);

FUNC(Std_ReturnType, MCEM_CODE) Mcem_ClearFaultsNMI(VAR(Mcem_FaultType, AUTOMATIC) nFaultId);
  #endif /* MCEM_FCCU_EXTRA_NMI_API == STD_ON */
#endif /* defined MCEM_FCCU_EXTRA_NMI_API */

#if(STD_ON == MCEM_GET_VERSION_INFO_API)
FUNC(void, MCEM_CODE) Mcem_GetVersionInfo(P2VAR(Std_VersionInfoType,AUTOMATIC,MCEM_APPL_DATA) pVersionInfo);
#endif /* MCEM_GET_VERSION_INFO_API */
#ifdef MCEM_FCCU_SUPPORT
FUNC(Std_ReturnType, MCEM_CODE) Mcem_CheckNMI( void );
#endif

#define MCEM_STOP_SEC_CODE
/* @violates @ref CDD_Mcem_h_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*CDD_MCEM_H*/

/** @} */
