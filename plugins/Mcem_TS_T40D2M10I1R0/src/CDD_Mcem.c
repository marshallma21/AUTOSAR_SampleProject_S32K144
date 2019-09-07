/**
*   @file    CDD_Mcem.c
*   @implements     CDD_Mcem.c_Artifact
*   @implements     MCEM_HLD_unit
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - Implementation of MCEM interface
*   @details Implementation of the public API of the MCEM module
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

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section CDD_Mcem_c_REF_1
 * Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
 * preprocessor directives or comments.
 * Violated due to AUTOSAR requirement MEMMAP003.
 *
 * @section CDD_Mcem_c_REF_2
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice
 * This is not a violation since all header files are protected against multiple inclusions
 *
 * @section CDD_Mcem_c_REF_3
 * Violates MISRA 2004 Required Rule 1.4, Allow at least 31 character significance.
 * External identifiers are not distinct in the first 6 characters due to AUTOSAR compatibility
 *
 * @section CDD_Mcem_c_REF_4
 * Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects 
 * or functions at file scope shall have internal linkage unless external linkage is required.
 * Possibly unused public API
 *
 * @section CDD_Mcem_c_REF_5
 * Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
 * accessed from within a single function. External declaration required here.
 *
 * @section Mcem_c_REF_6
 * Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed
 * between a pointer to object type and a different pointer to object type. The cast is used in order
 * to access the Dem extended data structure as an array of bytes
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility.
 *
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcem.h"
#include "Mcem_IPW.h"
#include "CDD_Mcem_IrqHandler.h"

#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_MCEM_VENDOR_ID_C                      43
/* @violates @ref CDD_Mcem_c_REF_3 31 character significance */
#define CDD_MCEM_AR_RELEASE_MAJOR_VERSION_C       4
/* @violates @ref CDD_Mcem_c_REF_3 31 character significance */
#define CDD_MCEM_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref CDD_Mcem_c_REF_3 31 character significance */
#define CDD_MCEM_AR_RELEASE_REVISION_VERSION_C    2
#define CDD_MCEM_SW_MAJOR_VERSION_C               1
#define CDD_MCEM_SW_MINOR_VERSION_C               0
#define CDD_MCEM_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Mcem.h header file are of the same vendor */
#if (CDD_MCEM_VENDOR_ID_C != MCEM_VENDOR_ID)
    #error "CDD_Mcem.c and CDD_Mcem.h have different Vendor ids"
#endif
/* Check if current file and CDD_Mcem.h header file are of the same Autosar version */
#if ((CDD_MCEM_AR_RELEASE_MAJOR_VERSION_C    != MCEM_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_MINOR_VERSION_C    != MCEM_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_REVISION_VERSION_C != MCEM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcem.c and CDD_Mcem.h are different"
#endif
/* Check if current file and CDD_Mcem.h header file are of the same Software version */
#if ((CDD_MCEM_SW_MAJOR_VERSION_C != MCEM_SW_MAJOR_VERSION) || \
     (CDD_MCEM_SW_MINOR_VERSION_C != MCEM_SW_MINOR_VERSION) || \
     (CDD_MCEM_SW_PATCH_VERSION_C != MCEM_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcem.c and CDD_Mcem.h are different"
#endif


/* Check if CDD_Mcem.c file and Mcem_IPW.h header file are of the same vendor */
#if (CDD_MCEM_VENDOR_ID_C != MCEM_IPW_VENDOR_ID)
    #error "CDD_Mcem.c and Mcem_IPW.h have different Vendor ids"
#endif
/* Check if current file and Mcem_IPW header file are of the same Autosar version */
#if ((CDD_MCEM_AR_RELEASE_MAJOR_VERSION_C != MCEM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_MINOR_VERSION_C != MCEM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_REVISION_VERSION_C != MCEM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcem.c and Mcem_IPW.h are different"
#endif
/* Check if current file and Mcem.h header file are of the same Software version */
#if ((CDD_MCEM_SW_MAJOR_VERSION_C != MCEM_IPW_SW_MAJOR_VERSION) || \
     (CDD_MCEM_SW_MINOR_VERSION_C != MCEM_IPW_SW_MINOR_VERSION) || \
     (CDD_MCEM_SW_PATCH_VERSION_C != MCEM_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcem.c and Mcem_IPW.h are different"
#endif


/* Check if current file and CDD_Mcem_IrqHandler.h header file are of the same vendor */
#if (CDD_MCEM_VENDOR_ID_C != CDD_MCEM_IRQHANDLER_VENDOR_ID)
    #error "CDD_Mcem.c and CDD_Mcem_IrqHandler.h have different Vendor ids"
#endif
/* Check if current file and CDD_Mcem_IrqHandler header file are of the same Autosar version */
#if ((CDD_MCEM_AR_RELEASE_MAJOR_VERSION_C != CDD_MCEM_IRQHANDLER_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_MINOR_VERSION_C != CDD_MCEM_IRQHANDLER_AR_RELEASE_MINOR_VERSION) || \
     (CDD_MCEM_AR_RELEASE_REVISION_VERSION_C != CDD_MCEM_IRQHANDLER_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcem.c and CDD_Mcem_IrqHandler.h are different"
#endif
/* Check if current file and CDD_Mcem_IrqHandler.h header file are of the same Software version */
#if ((CDD_MCEM_SW_MAJOR_VERSION_C != CDD_MCEM_IRQHANDLER_SW_MAJOR_VERSION) || \
     (CDD_MCEM_SW_MINOR_VERSION_C != CDD_MCEM_IRQHANDLER_SW_MINOR_VERSION) || \
     (CDD_MCEM_SW_PATCH_VERSION_C != CDD_MCEM_IRQHANDLER_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcem.c and CDD_Mcem_IrqHandler.h are different"
#endif


/* Check if current file and Det.h header file are of the same Autosar version */
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((CDD_MCEM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CDD_MCEM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of CDD_Mcem.c and Det.h are different"
        #endif
    #endif
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define pMcemConfigPtr (Mcem_pConfigPtr)
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define MCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref CDD_Mcem_c_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_c_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"

#if (STD_ON == MCEM_PRECOMPILE_SUPPORT)
/* @violates @ref CDD_Mcem_c_REF_5 Block scope */
extern CONST(Mcem_ConfigType, MCEM_CONST) Mcem_PBCfgVariantPredefined;
#endif      /* (STD_OFF == MCEM_PRECOMPILE_SUPPORT) */

#define MCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref CDD_Mcem_c_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_c_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"

#define MCEM_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref CDD_Mcem_c_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_c_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"

/**
* @brief          Driver state.
* @details        The MCEM driver changes state during start-up or runtime from MCEM_S_UINIT to MCEM_S_INITIALIZED.
*                 If the configuration specify a lockable configuration, driver locks its configuration
*                 and change its state to MCEM_S_LOCKED. 
*/
/* @violates @ref CDD_Mcem_c_REF_5 Block scope */
static VAR(Mcem_StateType,MCEM_VAR) Mcem_DriverState = MCEM_S_UNINIT;

#if (MCEM_DEV_ERROR_DETECT == STD_ON)
/**
* @brief          Public function status.
* @details        Each public function that is not re-entrant protects itself against pre-emption.
*                 This variables holds the status of each public function and changes each time function 
*                 is executed from MCEM_S_IDLE to MCEM_S_BUSY, and back to MCEM_S_IDLE when the function exits.
*
*/     
static VAR(Mcem_FunctionStateType,MCEM_VAR) Mcem_FunctionState[] = 
{
    MCEM_S_IDLE, MCEM_S_IDLE, MCEM_S_IDLE, MCEM_S_IDLE,
    MCEM_S_IDLE, MCEM_S_IDLE, MCEM_S_IDLE
};
#endif /* (MCEM_DEV_ERROR_DETECT == STD_ON) */

/**
* @brief          Latest Configuration pointer.
* @details        When the MCEM driver is initialized, the initialization pointer is stored to be used later.
*/
/* @violates @ref CDD_Mcem_c_REF_5 Block scope */
static P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) Mcem_pConfigPtr = NULL_PTR;


#define MCEM_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref CDD_Mcem_c_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_c_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (MCEM_DEV_ERROR_DETECT == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, MCEM_CODE) Mcem_ValidateInitPtr(P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr);
LOCAL_INLINE FUNC(Std_ReturnType, MCEM_CODE) Mcem_ValidateErrorPtr(P2CONST(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_VAR) pFaultsContainer);
LOCAL_INLINE FUNC(Std_ReturnType, MCEM_CODE) Mcem_ValidateFaultId(VAR(Mcem_FaultType, AUTOMATIC) nFaultId, VAR(uint8, AUTOMATIC) u8FuncId);
LOCAL_INLINE FUNC(Std_ReturnType, MCEM_CODE) Mcem_CheckState(VAR(uint8, AUTOMATIC) u8FuncId);
LOCAL_INLINE FUNC(void, MCEM_CODE) Mcem_CheckStateEnd(VAR(uint8, AUTOMATIC) u8FuncId);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCEM_START_SEC_CODE
/* @violates @ref CDD_Mcem_c_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_c_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"


#if (MCEM_DEV_ERROR_DETECT == STD_ON)
/**
* @brief          Validate Init Pointer
* @details        When initializing, a pointer to the init structure is used. This functions validates
*                 the pointer based on the compile support: Pre-compile or Post-build. 
*
* @param[in]      pConfigPtr Configuration pointer to be validated.
* @return         Std_ReturnType
* @retval         E_OK for valid pointer
* @retval         E_NOT_OK otherwise
*
* @implements     Mcem_ValidateInitPtr_Activity
*
*/
LOCAL_INLINE FUNC(Std_ReturnType,MCEM_CODE) Mcem_ValidateInitPtr(P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;

#if (STD_OFF == MCEM_PRECOMPILE_SUPPORT)
    if ( NULL_PTR == pConfigPtr )
#else
    if ( NULL_PTR != pConfigPtr )
#endif
    {
        (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, MCEM_INIT_ID, MCEM_E_PARAM_CONFIG);
    }
    else
    {
        nReturnValue = (Std_ReturnType)E_OK;
    }
    return nReturnValue;
}

/**
* @brief          Faults Container pointer validator.
* @details        When getting the errors, application provides a pointer to a structure where the driver
*                 shall store the errors. This function checks that the pointer is not NULL, or else reports to Det .
* @param[in]      pFaultsContainer Pointer to be validated.
* @return         Std_ReturnType
* @retval         E_OK for valid pointer
* @retval         E_NOT_OK otherwise
*
* @implements     Mcem_ValidateErrorPtr_Activity
*
*/
LOCAL_INLINE FUNC(Std_ReturnType,MCEM_CODE) Mcem_ValidateErrorPtr(P2CONST(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_VAR) pFaultsContainer)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;

    if ( NULL_PTR == pFaultsContainer )
    {
        (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, MCEM_GET_ERRORS_ID, MCEM_E_PARAM_FAULT);
    }
    else
    {
        nReturnValue = (Std_ReturnType)E_OK;
    }
    return nReturnValue;
}


/**
* @brief          Function to validate is in acceptable range.
* @details        Before a parameter is used, it shall be checked for plausability.
* @param[in]      nFaultId Fault ID to be validated.
* @param[in]      u8FuncId Function ID for reporting.
* @return         Std_ReturnType
* @retval         E_OK for valid fault ID
* @retval         E_NOT_OK otherwise
* 
* @implements     Mcem_ValidateFaultId_Activity
*
*/
LOCAL_INLINE FUNC(Std_ReturnType,MCEM_CODE) Mcem_ValidateFaultId(VAR(Mcem_FaultType, AUTOMATIC) nFaultId, VAR(uint8, AUTOMATIC) u8FuncId)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    VAR(boolean,MCEM_VAR) bValidFault;

    bValidFault = Mcem_IPW_CheckValidFault(nFaultId);
#ifdef MCEM_FCCU_SUPPORT
    if ( ( MCEM_FAULT_IN_RANGE(nFaultId) ) && \
         (0UL != (Mcem_au32StaticFaultMasks[nFaultId >> MCEM_FAULT_CONTAINER_SHIFT] & (1UL << ((nFaultId) & MCEM_FAULT_CONTAINER_MASK)))) && \
         ((boolean)TRUE == bValidFault) \
       )
#else
    if ( MCEM_FAULT_IN_RANGE(nFaultId) && ((boolean)TRUE == bValidFault))
#endif
    {
        nReturnValue = (Std_ReturnType)E_OK;
    }
    else
    { 
        (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, u8FuncId, MCEM_E_PARAM_FAULT);
    }
    return nReturnValue;
}


/**
* @brief          Check State Mechanism .
* @details        Before executing, a function shall check if is not pre-empting itself, or the driver is
*                 not in the expected state for the function to run. If the function is ready to run, 
*                 state is changed to MCEM_S_BUSY.
*                 On any error, function will report to Det.
* @param[in]      u8FuncId Function ID.
* @return         Std_ReturnType
* @retval         E_OK for valid state
* @retval         E_NOT_OK otherwise
*
* @implements     Mcem_CheckState_Activity
*
*/
LOCAL_INLINE FUNC(Std_ReturnType,MCEM_CODE) Mcem_CheckState(VAR(uint8, AUTOMATIC) u8FuncId)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_OK;

    if ( MCEM_S_BUSY == Mcem_FunctionState[u8FuncId] )
    {
        nReturnValue = (Std_ReturnType)E_NOT_OK;
        (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, u8FuncId, MCEM_E_PREEMPTION);
    }
    else
    {
        switch (u8FuncId)
        {
            case MCEM_INIT_ID:
            {
                if ( MCEM_S_LOCKED == Mcem_DriverState )
                {
                    nReturnValue = (Std_ReturnType)E_NOT_OK;
                    (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, u8FuncId, MCEM_E_FORBIDDEN_INVOCATION);
                }
                break;
            }
            case MCEM_INJECT_FAULT_ID: 
            {
                if (MCEM_S_UNINIT == Mcem_DriverState)
                {
                    nReturnValue = (Std_ReturnType)E_NOT_OK;
                    (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, u8FuncId, MCEM_E_UNINIT);
                }
                break;
            }
            case MCEM_GET_ERRORS_ID:
            case MCEM_CLEAR_FAULTS_ID:
            default:
                break;
        }
    }

    if ( (Std_ReturnType)E_OK == nReturnValue )
    {
        /* if everything went OK, set state to busy */
        Mcem_FunctionState[u8FuncId] = MCEM_S_BUSY;
    }
    return nReturnValue;
}

/**
* @brief          End Check State Mechanism.
* @details        After a function execution, its state shall go from BUSY to IDLE.
* @param[in]      u8FuncId Function ID.
* @return         void
*
*/
LOCAL_INLINE FUNC(void,MCEM_CODE) Mcem_CheckStateEnd(VAR(uint8, AUTOMATIC) u8FuncId)
{
    Mcem_FunctionState[u8FuncId] = MCEM_S_IDLE;
}
#endif         /* MCEM_DEV_ERROR_DETECT == STD_ON */


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          Initialize the MCEM driver.
* @details        The function initializes the MCEM driver according to the configuration passed
*                 as parameter (post-build) or according to the static one (pre-compile).
*
* @param[in]  pConfigPtr   
*        - Post-build: Configuration pointer referring to the configuration structure.
*        - Pre-compile: NULL_PTR.
*
* @return         Std_ReturnType
* @retval E_OK                Initialization of the driver succeeded. The driver is functional and
*                             its state is MCEM_S_LOCKED or MCEM_S_INITIALIZED, depending whether the
*                             configuration uses hard-locking or not. 
* @retval E_NOT_OK            Initialization of the driver did not succeed. Configuration timeout expired, or the
*                             register configuration failed. Driver state is MCEM_S_UNINIT.
*
* @api            
*
* @pre            Driver state shall not be MCEM_S_DEGRADED.
*
* @implements     Mcem_Init_Activity
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_Init
(
    P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr
)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    
#if (MCEM_DEV_ERROR_DETECT == STD_ON)    
    /* Validate parameter */
    if ( (Std_ReturnType)E_OK == Mcem_ValidateInitPtr(pConfigPtr) )
#endif
    {
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        /* Validate state */
        if ( (Std_ReturnType)E_OK == Mcem_CheckState(MCEM_INIT_ID) )
        {
#endif
            /* Set the driver state to Initialize for prevent spurious interrupt in ConfigTimeoutISR */
            Mcem_DriverState = MCEM_S_INITIALIZED;
#if (STD_ON == MCEM_PRECOMPILE_SUPPORT)
            /* Use predefined configuration */
            pConfigPtr = &Mcem_PBCfgVariantPredefined;
#endif /* (STD_OFF == MCEM_PRECOMPILE_SUPPORT) */
            /* save the cfg address */
            Mcem_pConfigPtr = pConfigPtr;
            /* Insert fault injection point for testing detailed DEM errors reporting */
            MCAL_FAULT_INJECTION_POINT(FIP_T_MCEM_INIT_FP1);
            nReturnValue = Mcem_IPW_Init(pConfigPtr);
            if ( (Std_ReturnType)E_OK != nReturnValue )
            {
                /* Initialization is not successful, change driver state back to UNINIT, to not allow other function executed */
                Mcem_DriverState = MCEM_S_UNINIT;
            }
    
            if ( (Std_ReturnType)E_OK == nReturnValue )
            {
                if ( pConfigPtr->Lockable )
                {
                    Mcem_IPW_LockConfiguration();
                    Mcem_DriverState = MCEM_S_LOCKED;
                }
            }
            else
            {
#if (STD_ON == MCEM_DEM_EXTENDED_DATA)
                /* Add FP (failure point) identifier in the extended data to be sent to DEM */
                Mcem_DemExtData.u8FpId = (uint8)nReturnValue;
                /* Report extended data to DEM */
                /* @violates @ref Mcem_c_REF_6 A cast should not be performed between pointers to different object types. */
                (void)Dem_ReportErrorStatusPreExtData(Mcem_E_InitFailed, DEM_EVENT_STATUS_FAILED, (uint8*)&Mcem_DemExtData, u8DemExtDataLength);
                /* Make sure function returns a Std_ReturnType value */
                nReturnValue = (Std_ReturnType)E_NOT_OK; 
#endif
            }
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
            Mcem_CheckStateEnd(MCEM_INIT_ID);
        }
#endif
    }
    (void)Mcem_pConfigPtr;
    (void)Mcem_DriverState;
    return nReturnValue;
}

/**
* @brief          Inject a fault.
* @details        Implements mechanism of the MCEM driver to inject faults into the hardware and test the reaction.
* @param[in]      nFaultId     ID of the fault that shall be injected.
* @return         void
* @api            
* @pre            Driver shall be initialized.
*
* @implements     Mcem_InjectFault_Activity
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(void, MCEM_CODE) Mcem_InjectFaults
(
    VAR(Mcem_FaultType, AUTOMATIC) nFaultId
)
{
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    if ( (Std_ReturnType)E_OK == Mcem_CheckState(MCEM_INJECT_FAULT_ID) )
    {
        if ( (Std_ReturnType)E_OK == Mcem_ValidateFaultId(nFaultId, MCEM_INJECT_FAULT_ID) )
#endif
        {
            Mcem_IPW_InjectFault(nFaultId);
        }
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        Mcem_CheckStateEnd(MCEM_INJECT_FAULT_ID);
    }
#endif 
}


/**
* @brief          Return logged error status.
* @details        Function stores status of each NCF into a container provided by the application.
* @param[out]  pErrorContainer  Error container pointer.
*
* @return         Std_ReturnType
* @retval E_OK               No fault is pending.
* @retval E_FAULT_DETECTED   There is at least one logged fault.
* @retval E_NOT_OK           Otherwise (wrong driver state, error occured while querying faults in the hardware).
* @api            
*
* @implements     Mcem_GetErrors_Activity
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_GetErrors
(
    P2VAR(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_DATA) pErrorContainer
)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    if ( (Std_ReturnType)E_OK == Mcem_CheckState(MCEM_GET_ERRORS_ID) )
    {
        if ( (Std_ReturnType)E_OK == Mcem_ValidateErrorPtr(pErrorContainer) )
#endif
        {
            /* Insert fault injection point for testing detailed DEM errors reporting */
            MCAL_FAULT_INJECTION_POINT(FIP_T_MCEM_GET_ERRORS_FP1);
            nReturnValue = Mcem_IPW_GetErrors(pErrorContainer, (boolean)FALSE);
#if (STD_ON == MCEM_DEM_EXTENDED_DATA)
            /* We should have called here the macro Mcem_ExtendRetValForDem(), like below:
               nReturnValue = (Std_ReturnType)Mcem_ExtendRetValForDem(nReturnValue, ID_MCEM_GET_ERRORS_FP1_U8);
               Giving the fact that the demIdBase is ID_MCEM_GET_ERRORS_FP1_U8 which equals to 0x1, the macro returned value would have been identical
            with the one passed as parameter. In conclusion, the code will not call the macro in order to save some code size and execution time */
            if ((Std_ReturnType)E_OK != nReturnValue)
            {
                /* Add FP (failure point) identifier in the extended data to be sent to DEM */
                Mcem_DemExtData.u8FpId = (uint8)nReturnValue;
                /* Report extended data to DEM */
                /* @violates @ref Mcem_c_REF_6 A cast should not be performed between pointers to different object types. */
                (void)Dem_ReportErrorStatusPreExtData(Mcem_E_OperationFailed, DEM_EVENT_STATUS_FAILED, (uint8*)&Mcem_DemExtData, u8DemExtDataLength);
                /* Make sure function returns a Std_ReturnType value */
                nReturnValue = (Std_ReturnType)E_NOT_OK; 
            }
#endif
        }
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        Mcem_CheckStateEnd(MCEM_GET_ERRORS_ID);
    }
#endif 
    return nReturnValue;
}


/**
* @brief          Clear software recoverable fault.
* @details        When a software recoverable fault occurs, a software routine shall remove the fault 
*                 cause and then it shall clear the fault status using this function.
*
* @param[in]      nFaultId    ID of the fault that shall be cleared. If the fault is not marked as software
*                             recoverable, the request is ignored.
*
* @return         Std_ReturnType 
* @retval E_OK                Fault was cleared successfully.
* @retval E_NOT_OK            Fault was not cleared.
*
* @api 
*
* @implements     Mcem_ClearFaults_Activity
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_ClearFaults
(
    VAR(Mcem_FaultType, AUTOMATIC) nFaultId
)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    if ( (Std_ReturnType)E_OK == Mcem_CheckState(MCEM_CLEAR_FAULTS_ID) )
    {
        if ( (Std_ReturnType)E_OK == Mcem_ValidateFaultId(nFaultId, MCEM_CLEAR_FAULTS_ID) )
#endif
        {
            /* Insert fault injection point for testing detailed DEM errors reporting */
            MCAL_FAULT_INJECTION_POINT(FIP_T_MCEM_CLEAR_FAULTS_FP1);
            nReturnValue = Mcem_IPW_ClearFaults(nFaultId, (boolean)FALSE);
#if (STD_ON == MCEM_DEM_EXTENDED_DATA)            
            if ( (Std_ReturnType)E_OK != nReturnValue)
            {
                /* Add FP (failure point) identifier in the extended data to be sent to DEM */
                Mcem_DemExtData.u8FpId = (Std_ReturnType)Mcem_ExtendRetValForDem(nReturnValue, ID_MCEM_CLEAR_FAULTS_FP1_U8);
                /* Report extended data to DEM */
                /* @violates @ref Mcem_c_REF_6 A cast should not be performed between pointers to different object types. */
                (void)Dem_ReportErrorStatusPreExtData(Mcem_E_OperationFailed, DEM_EVENT_STATUS_FAILED, (uint8*)&Mcem_DemExtData, u8DemExtDataLength);
                /* Make sure function returns a Std_ReturnType value */
                nReturnValue = (Std_ReturnType)E_NOT_OK; 
            }
#endif
        }
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        Mcem_CheckStateEnd(MCEM_CLEAR_FAULTS_ID);
    }
#endif
    return nReturnValue;
}

#ifdef MCEM_FCCU_EXTRA_NMI_API
  #if (STD_ON == MCEM_FCCU_EXTRA_NMI_API)
/**
* @brief          Return logged error status.
* @details        Function stores status of each NCF into a container provided by the application.
* @param[out]  pErrorContainer  Error container pointer.
*
* @return         Std_ReturnType
* @retval E_OK               No fault is pending.
* @retval E_FAULT_DETECTED   There is at least one logged fault.
* @retval E_NOT_OK           Otherwise (wrong driver state, error occured while querying faults in the hardware).
* @api
* Remarks: this API is available only when USERMODE is used. And can be called only in NMI interrupt.
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_GetErrorsNMI
(
    P2VAR(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_DATA) pErrorContainer
)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    if ( (Std_ReturnType)E_OK == Mcem_CheckState(MCEM_GET_ERRORS_ID) )
    {
        if ( (Std_ReturnType)E_OK == Mcem_ValidateErrorPtr(pErrorContainer) )
#endif
        {
            nReturnValue = Mcem_IPW_GetErrors(pErrorContainer, (boolean)TRUE);
        }
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        Mcem_CheckStateEnd(MCEM_GET_ERRORS_ID);
    }
#endif 
    return nReturnValue;
}


/**
* @brief          Clear software recoverable fault.
* @details        When a software recoverable fault occurs, a software routine shall remove the fault 
*                 cause and then it shall clear the fault status using this function.
*
* @param[in]      nFaultId    ID of the fault that shall be cleared. If the fault is not marked as software
*                             recoverable, the request is ignored.
*
* @return         Std_ReturnType 
* @retval E_OK                Fault was cleared successfully.
* @retval E_NOT_OK            Fault was not cleared.
* Remarks: this API is available only when USERMODE is used. And can be called only in NMI interrupt.
* @api 
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_ClearFaultsNMI
(
    VAR(Mcem_FaultType, AUTOMATIC) nFaultId
)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    if ( (Std_ReturnType)E_OK == Mcem_CheckState(MCEM_CLEAR_FAULTS_ID) )
    {
        if ( (Std_ReturnType)E_OK == Mcem_ValidateFaultId(nFaultId, MCEM_CLEAR_FAULTS_ID) )
#endif
        {
            nReturnValue = Mcem_IPW_ClearFaults(nFaultId, (boolean)TRUE);
        }
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        Mcem_CheckStateEnd(MCEM_CLEAR_FAULTS_ID);
    }
#endif
    return nReturnValue;
}
  #endif /* MCEM_FCCU_EXTRA_NMI_API == STD_ON */
#endif /* defined MCEM_FCCU_EXTRA_NMI_API */

#if (MCEM_GET_VERSION_INFO_API == STD_ON)
/**
* @brief          Get version of the software module.
* @details        Returns the version information of this module.
*
* @param[out]  pVersionInfo  Pointer to a structure where the info about the version shall be stored.
*
* @return         void 
*
* @api           
*
* @implements     Mcem_GetVersionInfo_Activity
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(void, MCEM_CODE) Mcem_GetVersionInfo
(
    P2VAR(Std_VersionInfoType,AUTOMATIC,MCEM_APPL_DATA) pVersionInfo
)
{
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pVersionInfo)
    {
        (void)Det_ReportError(MCEM_MODULE_ID, MCEM_INSTANCE_ID, MCEM_GETVERSIONINFO_ID, MCEM_E_PARAM_VINFO);
    }
    else
#endif
    {
        (pVersionInfo)->vendorID         = (uint16)MCEM_VENDOR_ID;
        (pVersionInfo)->moduleID         = (uint8)MCEM_MODULE_ID;
        (pVersionInfo)->sw_major_version = (uint8)MCEM_SW_MAJOR_VERSION;
        (pVersionInfo)->sw_minor_version = (uint8)MCEM_SW_MINOR_VERSION;
        (pVersionInfo)->sw_patch_version = (uint8)MCEM_SW_PATCH_VERSION;
    }
}
#endif  /* MCEM_GET_VERSION_INFO_API == STD_ON */

#ifdef MCEM_FCCU_SUPPORT
/**
* @brief          Fault ALARM Interrupt Routine.
* @details        Upper layer of the ALARM interrupt which either calls a user notification routine.
*     
* @param[in]      nFaultId Fault ID that generated a transition of the FCCU to the ALARM state.
* @return         void 
* @note           This function shall not be directly called from the user code.
*
* @implements     Mcem_AlarmRoutine_Activity
*
*/
FUNC(void,MCEM_CODE) Mcem_AlarmRoutine
(
    VAR(Mcem_FaultType,AUTOMATIC) nFaultId
)
{
    if ( MCEM_S_UNINIT != Mcem_DriverState )
    {
#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        if ( ((Std_ReturnType)E_OK) == Mcem_ValidateFaultId(nFaultId, MCEM_ALARMROUTINE_ID) )
        {
#endif

#if (MCEM_ALARM_NOTIFICATION_API == STD_ON)
            if ( NULL_PTR != pMcemConfigPtr->AlarmNotification )
            {
                pMcemConfigPtr->AlarmNotification( nFaultId );
            }
            else
            {
#endif /* (MCEM_ALARM_NOTIFICATION_API == STD_ON) */
        (void)nFaultId; /* Do nothing, just prevent Misra violation */
#if (MCEM_ALARM_NOTIFICATION_API == STD_ON)
            }
#endif

#if (MCEM_DEV_ERROR_DETECT == STD_ON)
        }
#endif
    }
    else
    {
        (void)nFaultId; /* Do nothing, just prevent Misra violation */
    }
}

/**
* @brief          Config Timeout Interrupt Routine.
* @details        Report to upper layer of the Config Timeout interrupt.
*     
* @note           This function shall not be directly called from the user code.
*
*/
FUNC(void,MCEM_CODE) Mcem_CfgToRoutine (void)
{
    if ( MCEM_S_UNINIT != Mcem_DriverState )
    {
        if ( NULL_PTR != pMcemConfigPtr->CfgToNotification )
        {
            pMcemConfigPtr->CfgToNotification();
        }
    }
}

/**
* @brief          Check whether an NMI has originated from the MCEM driver.
* @details        Function checks whether the initialized MCEM module is the source of the NMI request.
*
* @return         Std_ReturnType (extended) 
* @retval E_FCCU_SPURIOUS_NMI   The initialized MCEM (FCCU) might trigger a spurious interrupt.
* @retval E_OK                  The NMI request originates in initialized MCEM (FCCU).
* @retval E_NOT_OK              Othewise (MCEM not initialized, non-FCCU related NMI, FCCU malfunction).
*
* @note           In case the preconditions for erratum e5922 are fulfilled, the user NMI handler has to 
*                 call Mcem_GetErrors() function to check whether there is at least one pending fault.
*                 Refer to the platform reference manual and appropriate errata documentation.
* @api
*
* @implements     Mcem_CheckNMI_Activity
*
*/
/* @violates @ref CDD_Mcem_c_REF_4 Public API */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_CheckNMI( void )
{
    VAR(Std_ReturnType, MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;

    if ( MCEM_S_UNINIT != Mcem_DriverState )
    {
        /* The MCEM has been initialized, call IPW layer */
        nReturnValue = Mcem_IPW_CheckNMI();
    }

    return nReturnValue;
}

#endif /* MCEM support FCCU */

#define MCEM_STOP_SEC_CODE
/* @violates @ref CDD_Mcem_c_REF_1 only preprocessor statements and comments before "#include". */
/* @violates @ref CDD_Mcem_c_REF_2 precautions to prevent the contents of a header file being included twice. */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
