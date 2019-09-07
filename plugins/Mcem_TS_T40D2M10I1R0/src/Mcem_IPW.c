/**
*   @file    Mcem_IPW.c
*   @implements     Mcem_IPW.c_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MCEM IPW Layer
*   @details Implementation of the IP Wrapper layer of the MCEM.
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
 *
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcem_IPW_c_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice
 * This is not a violation since all header files are protected against multiple inclusions
 * 
 * @section Mcem_IPW_c_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
 * compatibility
 *
 * @section Mcem_IPW_c_REF_3
 * Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
 * preprocessor directives or comments.
 * Violated due to AUTOSAR requirement MEMMAP003.
 *
 * @section Mcem_IPW_c_REF_4
 * Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
 * accessed from within a single function. External declaration required here.
 *
 * @section Mcem_IPW_c_REF_5
 * Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a parenthesised,
 * expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
 * Need wrap naming to a Base function.
 *
 * @section Mcem_IPW_c_REF_6
 * Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined is required for expand the expression of Mcal_Trusted_Call
 *
 * @section Mcem_IPW_c_REF_7
 * Violates MISRA 2004 Required Rule 10.1 , The value of an expression of integer type shall not be implicitly
 * converted to a different underlying type if: 
 *    a) it is not aconversion to a wider integer type of the same signedness, 
 *    b) the expression is complex,
 *    c) the expression is not constant and is a function argument,
 *    d) the expression is not constant and is a return expression.
 * it is required to convert from wider integer type to a smaller integer type due to workaround for mcal_trusted_call_return.
 *
 * @section Mcem_IPW_c_REF_8
 * Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used.
 * The comma is used  to abstract the trusted call function and to determine when the return into user mode is needed.
 *
 * @section Mcem_IPW_c_REF_9
 * Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects 
 * or functions at file scope shall have internal linkage unless external linkage is required.
 * Possibly unused public API
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 *
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcem_Cfg.h"
#include "Mcem_IPW.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCEM_IPW_VENDOR_ID_C                      43
/* @violates @ref Mcem_IPW_c_REF_2 Exceeds 31 characters */
#define MCEM_IPW_AR_RELEASE_MAJOR_VERSION_C       4
/* @violates @ref Mcem_IPW_c_REF_2 Exceeds 31 characters */
#define MCEM_IPW_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref Mcem_IPW_c_REF_2 Exceeds 31 characters */
#define MCEM_IPW_AR_RELEASE_REVISION_VERSION_C    2
#define MCEM_IPW_SW_MAJOR_VERSION_C               1
#define MCEM_IPW_SW_MINOR_VERSION_C               0
#define MCEM_IPW_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same vendor */
#if (MCEM_IPW_VENDOR_ID_C != CDD_MCEM_VENDOR_ID_CFG)
    #error "Mcem_IPW.c and CDD_Mcem_Cfg.h have different Vendor ids"
#endif
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same Autosar version */
#if ((MCEM_IPW_AR_RELEASE_MAJOR_VERSION_C    != CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCEM_IPW_AR_RELEASE_MINOR_VERSION_C    != CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCEM_IPW_AR_RELEASE_REVISION_VERSION_C != CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Mcem_IPW.c and CDD_Mcem_Cfg.h are different"
#endif
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same Software version */
#if ((MCEM_IPW_SW_MAJOR_VERSION_C != CDD_MCEM_SW_MAJOR_VERSION_CFG) || \
     (MCEM_IPW_SW_MINOR_VERSION_C != CDD_MCEM_SW_MINOR_VERSION_CFG) || \
     (MCEM_IPW_SW_PATCH_VERSION_C != CDD_MCEM_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Mcem_IPW.c and CDD_Mcem_Cfg.h are different"
#endif

/* Check if current file and Mcem_IPW.h header file are of the same vendor */
#if (MCEM_IPW_VENDOR_ID_C != MCEM_IPW_VENDOR_ID)
    #error "Mcem_IPW.c and Mcem_IPW.h have different Vendor ids"
#endif
/* Check if current file and Mcem_IPW.h header file are of the same Autosar version */
#if ((MCEM_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCEM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCEM_IPW_AR_RELEASE_MINOR_VERSION_C    != MCEM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCEM_IPW_AR_RELEASE_REVISION_VERSION_C != MCEM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_IPW.c and Mcem_IPW.h are different"
#endif
/* Check if current file and Mcem_IPW.h header file are of the same Software version */
#if ((MCEM_IPW_SW_MAJOR_VERSION_C != MCEM_IPW_SW_MAJOR_VERSION) || \
     (MCEM_IPW_SW_MINOR_VERSION_C != MCEM_IPW_SW_MINOR_VERSION) || \
     (MCEM_IPW_SW_PATCH_VERSION_C != MCEM_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_IPW.c and Mcem_IPW.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (STD_ON == MCEM_ENABLE_USER_MODE_SUPPORT)
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_Init(pConfigPtr)             Mcal_Trusted_Call1param(Mcem_Eirm_Init,(pConfigPtr))
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_InjectFault(nFaultId)        Mcal_Trusted_Call1param(Mcem_Eirm_InjectFault,(nFaultId))
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_GetErrors(pErrorContainner)  (Std_ReturnType)(Mcal_Trusted_Call_Return1param(Mcem_Eirm_GetErrors,(pErrorContainner)))
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_ClearFault(nFaultId)         (Std_ReturnType)(Mcal_Trusted_Call_Return1param(Mcem_Eirm_ClearFault,(nFaultId)))
#else
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_Init(pConfigPtr)             Mcem_Eirm_Init((pConfigPtr))
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_InjectFault(nFaultId)        Mcem_Eirm_InjectFault((nFaultId))
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_GetErrors(pErrorContainner)  Mcem_Eirm_GetErrors((pErrorContainner))
    /* @violates @ref Mcem_IPW_c_REF_5 MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
    /* @violates @ref Mcem_IPW_c_REF_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define Call_Mcem_Eirm_ClearFault(nFaultId)         Mcem_Eirm_ClearFault((nFaultId))
#endif

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define MCEM_START_SEC_VAR_NO_INIT_32
/* @violates @ref Mcem_IPW_c_REF_1 precautions to prevent the contents of a header file being included multiple time */
/* @violates @ref Mcem_IPW_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"


#define MCEM_STOP_SEC_VAR_NO_INIT_32
/* @violates @ref Mcem_IPW_c_REF_1 precautions to prevent the contents of a header file being included multiple time */
/* @violates @ref Mcem_IPW_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define MCEM_START_SEC_CODE
/* @violates @ref Mcem_IPW_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_IPW_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/**
* @brief          Mcem IPW Init function
* @details        Function distributes the configuration for th two IPs of the driver.
*
* @param[in,out]  pConfigPtr   Configuration pointer for the driver.
*
* @return         Std_ReturnType 
* @retval E_OK                Driver has been initialized correctly and checked using readback.
* @retval E_NOT_OK            Driver has not been initialized correctly, readback failed.
*
* @api           
*/
FUNC(Std_ReturnType, MCEM_CODE) Mcem_IPW_Init(P2CONST(Mcem_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr)
{

    /* Init the EIRM */
    /* @violates @ref Mcem_IPW_c_REF_8 comma operatore */
    Call_Mcem_Eirm_Init(pConfigPtr->EirmConfig);
    
    return((Std_ReturnType)E_OK);
}

/**
* @brief          Function to check if faults is not disable
* @details        Function to check if faults is not disable
*
* @param[in]      nFaultId     The ID of the fault to be injected
*                            
* @return         boolean: 
*                           TRUE  : Fault ID is valid (not disable)
*                           FALSE : Fault ID is valid (not disable)
*
* @pre            nFaultId is valid
*
* @api            
*
*/
/* @violates @ref Mcem_IPW_c_REF_9 external interface is required */
FUNC(boolean, MCEM_CODE)    Mcem_IPW_CheckValidFault (VAR(Mcem_FaultType, AUTOMATIC)nFaultId)
{
    return Mcem_Eirm_CheckValidFault(nFaultId);
}
/**
* @brief          Function to inject fake faults
* @details        Function is used to inject fake faults in order to test the reaction for each fault.
*
* @param[in]      nFaultId     The ID of the fault to be injected
*                            
* @return         void 
*
* @pre            nFaultId is valid
*
* @api            
*
*/
FUNC(void, MCEM_CODE) Mcem_IPW_InjectFault(VAR(Mcem_FaultType, AUTOMATIC) nFaultId)
{
    /* @violates @ref Mcem_IPW_c_REF_8 comma operatore */
    Call_Mcem_Eirm_InjectFault(nFaultId);
}

/**
* @brief          Get errors function
* @details        Function gets the errors logged in the IPs and stores them into a container.
*
* @param[in,out]  pErrorContainer  Error container where the errors shall be stored.
*
* @return         Std_ReturnType
* @retval E_OK               No fault is pending.
* @retval E_FAULT_DETECTED   There is at least one logged fault.
* @retval E_NOT_OK           Otherwise (error occured while querying faults in the hardware).
*
* @api            
*/
FUNC(Std_ReturnType, MCEM_CODE) Mcem_IPW_GetErrors(P2VAR(Mcem_FaultContainerType, AUTOMATIC, MCEM_APPL_DATA) pErrorContainer, boolean bNmiCall)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* Store Memu faults */
    /* @violates @ref Mcem_IPW_c_REF_7 cast from wider integer to smaller integer type */
    nReturnValue = (Std_ReturnType)Call_Mcem_Eirm_GetErrors( &(pErrorContainer->au32Faults[0U]));

    /* In case error status has been retrieved properly, handle global error flag */
    if ((Std_ReturnType)E_OK != nReturnValue)
    {
        /* At least one bit has been set */
        nReturnValue = (Std_ReturnType)E_FAULT_DETECTED;
    }
    /* Store the resulting status */
    pErrorContainer->nErrorStatus = nReturnValue;
    /* Prevent misra and compiler warnings about unused of this variable */
    (void)bNmiCall;
    return nReturnValue;
}


/**
* @brief          Clear fault function
* @details        The function shall clear the specified fault. The fault can be cleared only if the fault 
*                 cause is eliminated and the fault is marked as software recoverable.
*
* @param[in]      nFaultId     The ID of the fault that shall be cleared
*
* @return         Std_ReturnType 
* @retval E_OK                The fault has been successfully cleared
*
* @retval E_NOT_OK            The fault has not been successfully cleared. Possible causes : 
*                             -the fault source has not been eliminated
*                             -the fault occured again
*
* @pre            nFaultId is valid
*
* @api           
*
*/
FUNC(Std_ReturnType, MCEM_CODE) Mcem_IPW_ClearFaults(VAR(Mcem_FaultType, AUTOMATIC) nFaultId, boolean bNmiCall)
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;

    /* @violates @ref Mcem_IPW_c_REF_7 cast from wider integer to smaller integer type */
    nReturnValue = (Std_ReturnType)Call_Mcem_Eirm_ClearFault(nFaultId);
    (void)bNmiCall;
    return nReturnValue;
}


#define MCEM_STOP_SEC_CODE
/* @violates @ref Mcem_IPW_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_IPW_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
