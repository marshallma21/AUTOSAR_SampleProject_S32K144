/**
*   @file    Eth.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver interface.
*   @details This file contains implementation of the AUTOSAR Ethernet driver
*            and provides whole API except the interrupt handlers.
*
*   @addtogroup ETH_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ENET
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
* @section Eth_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be
* preceded by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions
* shall be taken in order to prevent the contents of a header file being
* included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for 
* external identifiers. Name length of the macros is unfortunately longer than 
* 31 characters which is required by  the agreed macro format and cannot be 
* changed. 
*
* @section Eth_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only
* allowed form of pointer arithmetic. Array indexing shall only be applied
* to objects defined as an array type. Handling with pointer without explicit
* length is defined by AUTOSAR specification. But the length of MAC address
* is strictly six bytes and used index is never out of the bounds.
*
* @section Eth_c_REF_5
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results
* are invariant shall not be permitted. This condition is invariant only for
* PreCompile variant where is this behavior expected.
*
* @section Eth_c_REF_6
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed
* on undefined or unspecified behavior. This rely to using of pointer to
* variable on stack. In this case is ensured that a local variable and its
* address is used only in the valid content.
*
* @section Eth_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. The APIs always require the external
* linkage. MISRA analysis tool does not see the linkage from upper layers
* therefore there is no violation.
*
* @section Eth_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only
* allowed form of pointer arithmetic. The MISRA analysis tool reports this
* violation badly if array of pointers is accessed  even with the array
* indexing arithmetics - this is used in a post build configuration variant
* to access the configuration parameters. It is no violation but the tool
* bug however it must be documented anyway.
*
* @section Eth_c_REF_9
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. This is aimed to be GLOBAL variable.
* MISRA analysis tool does not see the linkage from upper layers
* therefore there is no violation.
*
* @section Eth_c_REF_10
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_c_REF_11
* Violates MISRA 2004 Required Rule 11.1, Pointer to a function shall not be converted to anything
* else than integral type. This rule is not violated however the tool used for checks reports it
* therefore it must be commented here.
*
* @section Eth_c_REF_12
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be implicitly 
* converted to a different underlying type is: it is not a conversion to a wider integer type of the same 
* signedness or the expression is complex of the expression is not a constant and is a function argument or 
* the expression is not a constant and is a return expression. The violation happen in 64 bits platform where the 
* address is 64 bits, however, there is only LSB bits are meaning, so this conversion is correct. 
*
* @section Eth_c_REF_13
* Violates MISRA 2004 Required Rule 12.2, The value of an expression shall be the same under any order of
* evaluation that the standard permits. 
*
* @section Eth_c_REF_14
* Violates MISRA 2004 Required Rule 14.1, This rule refers to code which cannot under any circumstances be reached, 
* and which can be identified as such at compile-time
*
* @section Eth_c_REF_15
* Violates MISRA 2004 Required Rule 16.10, If a function returns error information, then that error information
* shall be tested. 
*
* @section Eth_c_REF_16
* Violates MISRA 2004 Required Rule 10.3, the value of a complex expression of integer type may only be cast to 
* a type that is narrower and of the same signedness as the underlying type of the expression. At here we have to
* change the sign of integer in order to process the division of 64-bits parameter and change again the signed.
* We already check regarded the sign before do conversion.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Eth.h" /* Includes also Eth_GeneralTypes.h, Eth_Cfg.h,  
                    Eth_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "Eth_Ipw.h"     /* LLD driver API */
#if STD_ON == ETH_CTRLENABLE_MII
#include "EthTrcv.h"    /* Include EthTrcv.h to reports Mii indication */
#endif /* ETH_CTRLENABLE_MII */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Eth_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_c_REF_10 MISRA rule 5.1  */
#define ETH_AR_RELEASE_REVISION_VERSION_C    2
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if(ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth.c and Eth.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Eth.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth.c and Eth.h are different"
#endif
/* Check if current file and Eth_LLD header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION_ETHIPW_H) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION_ETHIPW_H) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION_ETHIPW_H))
    #error "AutoSar Version Numbers of Eth.c and Eth_Ipw.h are different"
#endif
/* Check if current file and Eth_LLD header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION_ETHIPW_H) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION_ETHIPW_H) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION_ETHIPW_H))
    #error "Software Version Numbers of Eth.c and Eth_Ipw.h are different"
#endif

#if STD_ON == ETH_CTRLENABLE_MII
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and EthIf header file are of the same AutoSar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_C != ETHTRCV_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_C != ETHTRCV_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth.c and EthTrcv.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* ETH_CTRLENABLE_MII */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


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
/** @violates @ref Eth_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_c_REF_10 MISRA rule 5.1  */
#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Eth_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/**
* @brief         State of the Eth module
* @details       Used to store state of the Ethernet controller driver i.e Eth
*                module. It is initialized to ETH_STATE_UNINIT
*/
/** @violates @ref Eth_c_REF_9 MISRA rule 8.10 */
VAR(volatile Eth_StateType, ETH_VAR) Eth_CtrlState[ETH_MAXCTRLS_SUPPORTED] = {ETH_STATE_UNINIT};
/** @violates @ref Eth_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_c_REF_10 MISRA rule 5.1  */
#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Eth_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#if STD_ON == DEBUG_VARIABLES
#define ETH_START_SEC_VAR_INIT_32
/**
 * @violates @ref Eth_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
/**
* @brief         Debug variable counting receive buffer ring overflows
* @details       Debug variable used to count events of receive buffer ring
*                overflow due to reception of too long frame which does not fit
*                into the whole ring.
*/
VAR(uint32, ETH_VAR) Eth_RxBuffersOverflow[ETH_MAXCTRLS_SUPPORTED] = {0U};
/**
* @brief         Debug variable counting MII transactions finished too late
* @details       Debug variable incremented each time when MII transaction is
*                not finished successfully
*/
VAR(uint32, ETH_VAR) Eth_MiiFailed[ETH_MAXCTRLS_SUPPORTED] = {0U};
#define ETH_STOP_SEC_VAR_INIT_32

/**
 * @violates @ref Eth_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
#endif 


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ETH_START_SEC_CODE

/**
 * @violates @ref Eth_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Initializes the Ethernet Driver
* @details       Passed configuration pointer is internally stored and
*                the driver is initialized. The Ethernet controller is not
*                touched.
* @note          Function should be called only once.
* @warning       Second call can cause undefined behavior.
*                Call the Eth_SetControllerMode() and pass ETH_MODE_DOWN to
*                the CtrlMode argument before the second Eth_Init call to avoid
*                problems.
* @api
* @param[in]     CfgPtr Points to the implementation specific structure containing
*                the Eth driver configuration
* Compiler_Warning: this warning due to behavior of compiler depend on configs. 
* @implements    Eth_Init_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_Init(P2CONST(Eth_ConfigType, AUTOMATIC, ETH_APPL_CONST) CfgPtr)
{
    VAR(uint8, AUTOMATIC) u8CtrlCount = 0U;

#if STD_ON == ETH_DEV_ERROR_DETECT   
    #if (ETH_PRECOMPILE_SUPPORT == STD_OFF)
        if(NULL_PTR == CfgPtr)
        {           
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_INIT, \
                ETH_E_PARAM_POINTER \
                                  );
        }    
    #else 
        if(NULL_PTR != CfgPtr)
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_INIT, \
                ETH_E_PARAM_POINTER \
                                  );
        }
    #endif
        else
        {   
#endif /* ETH_DEV_ERROR_DETECT  */
            /* Set the state to ETH_STATE_UNINIT before doing any changes to
               ensure that any preempting function (interrupt handler) will
               correctly stop its execution even if the state had been 
               ETH_STATE_ACTIVE when the Eth_Init was called. */
            for (u8CtrlCount=0U; u8CtrlCount < (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED; u8CtrlCount++)
            {
                Eth_CtrlState[u8CtrlCount] = ETH_STATE_UNINIT;
            }
            
    #if (ETH_PRECOMPILE_SUPPORT == STD_OFF)
            /* Store the configuration pointer to internal global variable 
            for future usage */
            Eth_InternalCfgPtr = CfgPtr;
        #endif
            for (u8CtrlCount = ETH_MIN_CTRLIDX; u8CtrlCount <= (VAR(uint8, AUTOMATIC))ETH_MAX_CTRLIDX; u8CtrlCount++)
            {               
        #if (STD_ON == ETH_GLOBALTIME_SUPPORT)
                Eth_LocalTime[u8CtrlCount].secondsHi = 0U;
                Eth_LocalTime[u8CtrlCount].seconds = 0U;
                Eth_LocalTime[u8CtrlCount].nanoseconds = 0U;
        #endif
                /* Try to reset the controller */
                Eth_Ipw_ResetController(u8CtrlCount);
                /*  Check whether the controller is available */
                if(((VAR(boolean, AUTOMATIC))TRUE) == Eth_Ipw_CheckAccessToController(u8CtrlCount))
                {
                    Eth_Ipw_ConfigureController(u8CtrlCount);
                    Eth_Ipw_ClearCounters(u8CtrlCount);
                    Eth_Ipw_ConfigureRxBuffers(u8CtrlCount); 
                    Eth_Ipw_ConfigureTxBuffers(u8CtrlCount);
                    /* Only when debug variables are used */
                    #if STD_ON == DEBUG_VARIABLES
                        /* Clear debug variables */ 
                        Eth_RxBuffersOverflow[u8CtrlCount] = 0U;
                        Eth_MiiFailed[u8CtrlCount] = 0U;
                    #endif                     
                    /* Set controller to init state */
                    Eth_CtrlState[u8CtrlCount] = ETH_STATE_INIT; 
                    /* Yes, the controller is available, report as passed */
                    #if(STD_ON == ETH_DEM_EVENT_DETECT)
                          /**
                            @violates @ref Eth_c_REF_5 MISRA rule 13.7
                            @violates @ref Eth_c_REF_8 MISRA rule 17.4 
                            @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
                           if((VAR(uint32, AUTOMATIC))STD_ON == (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_ACCESS_ENABLED(u8CtrlCount))
                           {
                               /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                               /** @violates @ref Eth_c_REF_12 MISRA rule 10.1 */
                                                           Dem_ReportErrorStatus   ( \
                                   (VAR(Dem_EventIdType, AUTOMATIC)) \
                                   ETH_CFG_DEM_E_ACCESS(u8CtrlCount), \
                                   DEM_EVENT_STATUS_PREPASSED  \
                                                       );
                                                       }
                    #endif
                }
                else
                {
                    /* No, the controller is not available, report an error */
                  #if(STD_ON == ETH_DEM_EVENT_DETECT)
                    /**
                    * @violates @ref Eth_c_REF_5 MISRA rule 13.7
                    * @violates @ref Eth_c_REF_8 MISRA rule 17.4 
                    * @violates @ref Eth_c_REF_12 MISRA rule 10.1 */
                    /** @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_ACCESS_ENABLED(u8CtrlCount))
                    {
                        /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                        /** @violates @ref Eth_c_REF_12 MISRA rule 10.1 */
                                                Dem_ReportErrorStatus   ( \
                            (VAR(Dem_EventIdType, AUTOMATIC)) \
                            ETH_CFG_DEM_E_ACCESS(u8CtrlCount), \
                            DEM_EVENT_STATUS_PREFAILED \
                                                );
                                            }
                  #endif
                Eth_CtrlState[u8CtrlCount] = ETH_STATE_UNINIT;
                }       
            }
    #if STD_ON == ETH_DEV_ERROR_DETECT
        }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Enables or disables the given controller
* @warning       Disabling the controller clears all receive and transmit
*                buffers. The application should ensure that no data is lost.
* @api
* @param[in]     CtrlIdx Index of the controller to be enabled or disabled.
*                The index is valid within the context of the Ethernet Driver
*                only.
* @param[in]     CtrlMode Mode which shall be entered
*                - ETH_MODE_DOWN: disable the controller
*                - ETH_MODE_ACTIVE: enable the controller
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected and the function
*                failed.
* @implements    Eth_SetControllerMode_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_SetControllerMode(VAR(uint8, AUTOMATIC) CtrlIdx, VAR(Eth_ModeType, AUTOMATIC) CtrlMode)
{
    VAR(Std_ReturnType, AUTOMATIC) u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK; /* Variable used to track the
                                           function execution success status */
                                           
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {        
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_SETCONTROLLERMODE, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {     
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_SETCONTROLLERMODE, ETH_E_NOT_INITIALIZED \
                
                                  );
        }
        else
        {
    #endif /* ETH_DEV_ERROR_DETECT  */
            if(ETH_MODE_ACTIVE == CtrlMode)
            {
                Eth_Ipw_EnableController(CtrlIdx);
            }
            else
            {
                Eth_Ipw_DisableController(CtrlIdx);
            }
            u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
        #if(STD_ON == ETH_DEM_EVENT_DETECT)
                /**
                @violates @ref Eth_c_REF_5 MISRA rule 13.7
                @violates @ref Eth_c_REF_8 MISRA rule 17.4 
                @violates @ref Eth_c_REF_12 MISRA rule 10.1 
                @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (VAR(uint32, AUTOMATIC))ETH_CFG_DEM_E_ACCESS_ENABLED(CtrlIdx))
                {
                    /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                    /** @violates @ref Eth_c_REF_12 MISRA rule 10.1 */
                    Dem_ReportErrorStatus   ( \
                        (VAR(Dem_EventIdType, AUTOMATIC)) \
                        ETH_CFG_DEM_E_ACCESS(CtrlIdx), \
                        DEM_EVENT_STATUS_PREPASSED  \
                                            );
                }
        #endif
    #if STD_ON == ETH_DEV_ERROR_DETECT
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return u8FunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Obtains the mode of the given controller
* @api
* @param[in]     CtrlIdx Index of the controller which state shall be read.
*                The index is valid within the context of the Ethernet Driver
*                only.
* @param[out]    CtrlModePtr Pointer where to store the current controller mode.
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected and the function
*                failed.
* @implements    Eth_GetControllerMode_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_GetControllerMode( \
                            VAR(uint8, AUTOMATIC) CtrlIdx, \
                            P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_DATA) CtrlModePtr \
                                                    )
{
    VAR(Std_ReturnType, AUTOMATIC) u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK; /* Variable used to track
                                      the function execution success status */

    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_GETCONTROLLERMODE, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
       if(NULL_PTR == CtrlModePtr)
        {

            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETCONTROLLERMODE, ETH_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETCONTROLLERMODE, ETH_E_NOT_INITIALIZED \
                    
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                * CtrlModePtr = Eth_Ipw_CheckControllerIsActive(CtrlIdx);
                u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return u8FunctionSuccess;
}
  
/*================================================================================================*/
/**
* @brief         Obtains the physical source address used by the indexed
*                controller (the node MAC address).
* @api
* @param[in]     CtrlIdx Index of the controller which MAC address should be
*                read. The index is valid within the context of the Ethernet
*                Driver only.
* @param[out]    PhysAddrPtr Pointer where to store physical source address
*                (MAC address). The address in network byte order is stored into
*                6 bytes at the given memory address.
* @implements    Eth_GetPhysAddr_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_GetPhysAddr(VAR(uint8, AUTOMATIC) CtrlIdx, P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr)
{
    VAR(uint32, AUTOMATIC) u32AddressHolder; /* Used to hold the address value */
    
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_GETPHYSADDR, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETPHYSADDR, ETH_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETPHYSADDR, ETH_E_NOT_INITIALIZED \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                /* Get the first four bytes of the address */
                u32AddressHolder = Eth_Ipw_GetPhysicalAddressLow(CtrlIdx);
                /* Saved as four uint8 values instead of one uint32 value 
                   because the proper uint32 alignment is not ensured by the 
                   function prototype 
                */                
                /* Store the LSB */
                /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                PhysAddrPtr[3U] = (VAR(uint8, AUTOMATIC))(u32AddressHolder & 0xFFU);
                u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */
                
                /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                PhysAddrPtr[2U] = (VAR(uint8, AUTOMATIC))(u32AddressHolder & 0xFFU);
                u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */
                
                /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                PhysAddrPtr[1U] = (VAR(uint8, AUTOMATIC))(u32AddressHolder & 0xFFU);
                u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */
                /* Store the MSB */
                
                /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                PhysAddrPtr[0U] = (VAR(uint8, AUTOMATIC))(u32AddressHolder & 0xFFU);
                /* Get the last two bytes of the address */
                u32AddressHolder = Eth_Ipw_GetPhysicalAddressHigh(CtrlIdx);
                /* Saved as four uint8 values instead of one uint32 value 
                   because the proper uint16 alignment is not ensured by the 
                   function prototype 
                */                
                /* Store the LSB */
                
                /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                PhysAddrPtr[5U] = (VAR(uint8, AUTOMATIC))(u32AddressHolder & 0xFFU);
                u32AddressHolder = u32AddressHolder >> 8U; /* Prepare the next bit */
                /* Store the MSB */
                
                /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                PhysAddrPtr[4U] = (VAR(uint8, AUTOMATIC))(u32AddressHolder & 0xFFU);
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }      
        }  
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}  

/*================================================================================================*/
/**
* @brief         Set or change physical address to the defined controller.
* @api
* @param[in]     CtrlIdx Index of the controller which PHY address should be
*                changed. The index is valid within the context of the Ethernet
*                Driver only.
* @param[in]     PhysAddrPtr Pointer to PHY address which should be set to
*                the controller. The address is stored in 6 bytes of memory
*                in network byte order.
* @caution       This function may be called only when the controller is down.
*                Call of function Eth_ControllerInit change MAC address
*                to the default value!
* @implements    Eth_SetPhysAddr_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_SetPhysAddr(VAR(uint8, AUTOMATIC) CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr)
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_SETPHYSADDR, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_SETPHYSADDR, ETH_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_SETPHYSADDR, ETH_E_NOT_INITIALIZED \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                (void)Eth_Ipw_SetPhysAddr(CtrlIdx, PhysAddrPtr);
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}


#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
/*================================================================================================*/
/**
* @brief         Adds or removes the specific @c PhysAddrPtr address to or from
*                a multicast address pool at controller specified by @c CtrlIdx
*                index.
* @api
* @details       Enables or disables reception for specified unicast
*                physical address.
*                Operations for special Physical addresses follow.
*                If Physical Address ff:ff:ff:ff:ff:ff is added into a filter
*                (Action=ETH_ADD_TO_FILTER) the filter is completely open
*                and any address is accepted at reception. Later on when
*                Physical Address ff:ff:ff:ff:ff:ff is removed from the filter
*                (Action=ETH_REMOVE_FROM_FILTER) the filtering is recovered
*                and the reception is allowed again only for addresses remaining
*                in the filter.
*                If Physical Address 00:00:00:00:00:00 is added into a filter,
*                no matter whether action is ETH_ADD_TO_FILTER
*                or ETH_REMOVE_FROM_FILTER,
*                the filter is completely closed and all items from table
*                are removed.
*                Note that operations of full open or close are in exclusive
*                disjunction. Operation of full open excludes full close and
*                vice versa.
* @param[in]     CtrlIdx Index of the controller. The index is valid within
*                the context of the Ethernet Driver only.
* @param[in]     PhysAddrPtr Pointer to PHY address which shall be added
*                or removed to or from multicast pool.
*                The address in network byte order stored into 6 bytes of
*                memory.
* @param[in]     Action Determine whenever the defined address will be added
*                to the pool ETH_ADD_TO_FILTER or removed from it
*                ETH_REMOVE_FROM_FILTER.
* @implements    Eth_UpdatePhysAddrFilter_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_UpdatePhysAddrFilter ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr, \
                                VAR(Eth_FilterActionType, AUTOMATIC) Action \
                                                        )
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;

    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
          (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, ETH_DRIVER_INSTANCE, \
          (VAR(uint8, AUTOMATIC)) ETH_SID_UPDATEADDRFILTER, \
          ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {           
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_UPDATEADDRFILTER, ETH_E_PARAM_POINTER \
                                  );

        }
        else
        {
           if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_UPDATEADDRFILTER, ETH_E_NOT_INITIALIZED \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_UpdatePhysAddrFilter(CtrlIdx, PhysAddrPtr, Action);
                /* Check whenever is added multicast address. I/G bit is set */
                if(1U == (*(PhysAddrPtr) & 1U))
                {
                    eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
                }
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return eReturnStatus;
}

#endif /* STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER */


#if STD_ON == ETH_CTRLENABLE_MII

/*================================================================================================*/
/**
* @brief         Writes to a transceiver (physical layer driver) register.
* @details       The management frame is assembled and the MII bus transaction
*                is issued in order to transfer the data. Function waits until
*                the bus transaction finishes.
* @warning       This function is blocking the execution until the MII bus
*                transaction is finished.
* @api
* @param[in]     CtrlIdx Index of the controller which transceiver register
*                shall be written. The index is valid within the context of
*                the Ethernet Driver only.
* @param[in]     TrcvIdx Index of the transceiver connected the MII. The value
*                shall be within the range 0..31.
* @param[in]     RegIdx Index of the transceiver register to be written. The
*                value shall be within the range 0..31.
* @param[in]     RegVal Value to be written into the indexed register.
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error or the function failed.
* @retval        ETH_E_NO_ACCESS Inaccessible to transceiver.
* @implements    Eth_WriteMii_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_WriteMii ( \
                                    VAR(uint8, AUTOMATIC) CtrlIdx, \
                                    VAR(uint8, AUTOMATIC) TrcvIdx, \
                                    VAR(uint8, AUTOMATIC) RegIdx, \
                                    VAR(uint16, AUTOMATIC) RegVal \
                                            )
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    
    #if STD_ON == ETH_DEV_ERROR_DETECT
    /** @violates @ref Eth_c_REF_4 MISRA rule 17.4 */
    /** @violates @ref Eth_c_REF_5 MISRA rule 13.7 */
    /** @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
    if((CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)||((VAR(boolean, AUTOMATIC))FALSE == ETH_CFG_MDIOSUPPORT(CtrlIdx)))
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_WRITEMII, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
       if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_WRITEMII, \
                ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
    #endif /* ETH_DEV_ERROR_DETECT  */
            /** @violates @ref Eth_c_REF_6 MISRA rule 1.2 */
            if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_WriteMii(CtrlIdx, TrcvIdx, RegIdx, &RegVal))
            {
                EthTrcv_WriteMiiIndication(CtrlIdx, TrcvIdx, RegIdx);
                eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
            }
            else
            {   /* Communication timeout - controller inaccessible */
                    eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))ETH_E_NO_ACCESS;
            }
    #if STD_ON == ETH_DEV_ERROR_DETECT
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return eReturnStatus;
}

/*================================================================================================*/
/**
* @brief          Reads a transceiver (physical layer driver) register.
* @api
* @param[in]      CtrlIdx Index of the controller which transceiver register
*                 shall be read. The index is valid within the context of
*                 the Ethernet Driver only.
* @param[in]      TrcvIdx Index of the transceiver connected on the MII. The
*                 value shall be within the range 0..31.
* @param[in]      RegIdx Index of the transceiver register to be read. The
*                 Value shall be within the range 0..31.
* @param[out]     RegValPtr Filled with the register content of the indexed register
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error or the function failed.
* @retval        ETH_E_NO_ACCESS Inaccessible to transceiver.
* @details        The management frame is assembled and the MII bus transaction
*                 is issued in order to transfer the data. Function waits until
*                 the bus transaction finishes and then returns the read data.
* @warning        This function is blocking the execution until the MII bus
*                 transaction is finished.
* @implements     Eth_ReadMii_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_ReadMii  ( \
                            VAR(uint8, AUTOMATIC) CtrlIdx, \
                            VAR(uint8, AUTOMATIC) TrcvIdx, \
                            VAR(uint8, AUTOMATIC) RegIdx, \
                            P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) RegValPtr \
                                            )
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    
    #if STD_ON == ETH_DEV_ERROR_DETECT
    /** @violates @ref Eth_c_REF_4 MISRA rule 17.4 */
    /** @violates @ref Eth_c_REF_5 MISRA rule 13.7 */
    /** @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
    if((CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)||((VAR(boolean, AUTOMATIC))FALSE == ETH_CFG_MDIOSUPPORT(CtrlIdx)))
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_READMII, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == RegValPtr)
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_READMII, ETH_E_PARAM_POINTER \
                                  );
        }
        else
        {
           if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_READMII, ETH_E_NOT_INITIALIZED \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_ReadMii(CtrlIdx, TrcvIdx, RegIdx, RegValPtr))
                {
                    EthTrcv_ReadMiiIndication(CtrlIdx, TrcvIdx, RegIdx, *RegValPtr);
                    eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
                }
                else
                {   /* Communication timeout - controller inaccessible */
                    eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))ETH_E_NO_ACCESS;
                }

    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        }  
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return eReturnStatus;
}
#endif /* ETH_CTRLENABLE_MII */
#if STD_ON == ETH_GETDROPCOUNTAPI
/*================================================================================================*/
/**
* @brief            Reads a list with drop counter values of the corresponding controller.
* @api
* @param[in]        CtrlIdx Index of the controller which shall be be read the drop
*                   package counts.
* @param[in,out]    CountValues The number of values which return.
*                   -In: Maximal number of values which can be written from DropCount.
*                   -Out: Number of values which are returned in the DropCount list.
* @param[out]       DropCount The interpretation of this list of values is hardware 
*                   dependent
* @return           Error status
* @retval           E_OK No error was detected during the function execution.
* @retval           E_NOT_OK Development error was detected or inaccessible to counters register 
*                   and the function.
* @details          Reads a list with drop counter values of the corresponding controller. The meaning 
*                   of these values is hardware dependent. However, the list DropCount[] shall 
*                   contain the following values in the given order, where the maximal possible value 
*                   shall denote an invalid value, e.g. if this counter is not available:
*                   1.) dropped packets due to buffer overrun
*                   2.) dropped packets due to CRC errors
*                   3.) number of undersize packets which were less than 64 octets long (excluding 
*                   framing bits, but including FCS octets) and were otherwise will formed. (see IETF 
*                   RFC 1757)
*                   4.) number of oversize packets which are longer than 1518 octets (excluding 
*                   framing bits, but including FCS octets) and were otherwise well formed. (see IETF 
*                   RFC 1757)
*                   5.) number of alignment errors, i.e. packets which are received and are not an 
*                   integral number of octets in length and do not pass the CRC.
*                   6.) SQE test error according to IETF RFC1643 dot3StatsSQETestErrors
*                   7.) The number of inbound packets which were chosen to be discarded even 
*                   though no errors had been detected to prevent their being deliverable to a higher layer protocol. 
*                   One possible reason for discarding such a packet could be to free 
*                   up buffer space. (see IETF RFC 2233 ifInDiscards)
*                   8.) total number of erroneous inbound packets
*                   9.) The number of outbound packets which were chosen to be discarded even 
*                   though no errors had been detected to prevent their being transmitted. One 
*                   possible reason for discarding such a packet could be to free up buffer space. 
*                   (see IETF RFC 2233 ifOutDiscards)
*                   10.) total number of erroneous outbound packets
*                   11.) Single collision frames: A count of successfully transmitted frames on a 
*                   particular interface for which transmission is inhibited by exactly one collision. (see 
*                   IETF RFC1643 dot3StatsSingleCollisionFrames)
*                   12.) Multiple collision frames: A count of successfully transmitted frames on a 
*                   particular interface for which transmission is inhibited by more than one collision. 
*                   (see IETF RFC1643 dot3StatsMultipleCollisionFrames)
*                   13.) Number of deferred transmission: A count of frames for which the first 
*                   transmission attempt on a particular interface is delayed because the medium is 
*                   busy. (see IETF RFC1643 dot3StatsDeferredTransmissions)
*                   14.) Number of late collisions: The number of times that a collision is detected on 
*                   a particular interface later than 512 bit times into the transmission of a packet. 
*                   (see IETF RFC1643 dot3StatsLateCollisions)
*                   15.) the following positions in the list can contain hardware dependent counter 
*                   values
* @implements       Eth_GetDropCount_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_GetDropCount ( \
                                        VAR(uint8, AUTOMATIC) CtrlIdx, \
                                        P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) CountValuesPtr, \
                                        P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) DropCountPtr \
                                                )
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC)) E_NOT_OK;
    
#if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_GETDROPCOUNT, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETDROPCOUNT, ETH_E_NOT_INITIALIZED\
                                  );
        }
        else
        {
            if((NULL_PTR == DropCountPtr)||(NULL_PTR == CountValuesPtr))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETDROPCOUNT, \
                    ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
#endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_GetDropCount(CtrlIdx, CountValuesPtr, DropCountPtr);
                eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
#if STD_ON == ETH_DEV_ERROR_DETECT
            } 
        }
    }
#endif /* ETH_DEV_ERROR_DETECT  */
    return(eReturnStatus);
}
#endif /* ETH_GETDROPCOUNTAPI */
#if STD_ON == ETH_GET_ETHERSTATS_API
/*================================================================================================*/
/**
* @brief        Read the status of a controller
* @detail       Returns the following list according to IETF RFC2819, where the maximal possible 
*               value shall denote an invalid value, e.g. if this counter is not available:
*               1. etherStatsDropEvents
*               2. etherStatsOctets
*               3. etherStatsPkts
*               4. etherStatsBroadcastPkts
*               5. etherStatsMulticastPkts
*               6. etherStatsCrcAlignErrors
*               7. etherStatsUndersizePkts
*               8. etherStatsOversizePkts
*               9. etherStatsFragments
*               10. etherStatsJabbers
*               11. etherStatsCollisions
*               12. etherStatsPkts64Octets
*               13. etherStatsPkts65to127Octets
*               14. etherStatsPkts128to255Octets
*               15. etherStatsPkts256to511Octets
*               16. etherStatsPkts512to1023Octets
*               17. etherStatsPkts1024to1518Octets
* @api
* @param[in]    CtrlIdx Index of the controller which shall be read the status register.
* @param[out]   etherStats Pointer to 32 bit long memory space to be filled with
*               the list values according to IETF RFC 2819 (Remote Network 
*               Monitoring Management Information Base). 
* @return       Error status
* @retval       E_OK No error was detected during the function execution.
* @retval       E_NOT_OK Development error was detected or inaccessible to counters register 
*               and the function.
* @implements   Eth_GetEtherStats_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_GetEtherStats    ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) etherStats \
                                                    )
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC)) E_NOT_OK;

#if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_GETETHERSTATS, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETETHERSTATS, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if(NULL_PTR == etherStats)
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETETHERSTATS, \
                    ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
#endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_GetEtherStats(CtrlIdx, etherStats);
                eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC)) E_OK;
#if STD_ON == ETH_DEV_ERROR_DETECT
            } 
        }
    }
#endif /* ETH_DEV_ERROR_DETECT  */
    return(eReturnStatus);
}
#endif /* ETH_GET_ETHERSTATS_API */



#if STD_ON == ETH_GLOBALTIME_SUPPORT
/*================================================================================================*/
/**
* @brief         Returns a time value out of the HW registers according to the capability of the HW.
* @note          Is the HW  resolution is lower than the Eth_TimeStampType resolution resp. range, 
*                than an the remaining bits will be filled with 0.
* @api
* @param[in]     CtrlIdx Index of the controller shall be read the time value.
* @param[out]    timeQualPtr quality of HW time stamp, e.g. based on current drift
* @param[out]    timeStampPtr current time stamp
* @return        Error status
* @retval        +E_OK: successfully read the timestamp
* @retval        +E_NOT_OK: development error was detected or fail to read the TimeStamp.
* @implements    Eth_GetCurrentTime_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_GetCurrentTime  ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                                    )
{
    VAR(Std_ReturnType, AUTOMATIC) eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_GETCURRENTTIME, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETCURRENTTIME, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if ((NULL_PTR == timeQualPtr)||(NULL_PTR == timeStampPtr))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETCURRENTTIME, ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_GetCurrentTime(CtrlIdx, timeQualPtr, timeStampPtr);
                eReturnStatus = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return(eReturnStatus);
}

/*================================================================================================*/
/**
* @brief         Activates egress time stamping on a dedicated message object.
* @note          Some HW does store once the egress time stamp marker and some HW needs it 
*                always before transmission. There will be no disable functionality, due to the fact, 
*                that the message type is always "time stamped" by network design.
* @api
* @param[in]     CtrlIdx Index of the controller which counter state shall be
*                enable the TimeStamp
* @param[in]     BufIdx Index of the message buffer, where Application expects egress time 
*                stamping
* @implements    Eth_EnableEgressTimeStamp_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_EnableEgressTimeStamp  ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) BufIdx \
                                                )
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_ENABLEEGRESSTIMESTAMP, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_ENABLEEGRESSTIMESTAMP, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
    #endif /* ETH_DEV_ERROR_DETECT  */
            Eth_Ipw_EnableEgressTimeStamp(CtrlIdx, BufIdx);
    #if STD_ON == ETH_DEV_ERROR_DETECT
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Reads back the egress time stamp on a dedicated message object.
* @note          It must be called within the TxConfirmation() function.
* @api
* @param[in]     CtrlIdx Index of the controller which the egress timestamp shall be
*                read. 
* @param[in]     BufIdx Index of the message buffer, where Application expects egress time 
*                stamping
* @param[out]    timeQualPtr quality of HW time stamp, e.g. based on current drift
* @param[out]    timeStampPtr current time stamp
* @implements    Eth_GetEgressTimeStamp_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_GetEgressTimeStamp ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) BufIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                            )
{
    #if STD_ON == ETH_DEV_ERROR_DETECT

    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_GETEGRESSTIMESTAMP, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETEGRESSTIMESTAMP, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if ((NULL_PTR == timeQualPtr)||(NULL_PTR == timeStampPtr))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETEGRESSTIMESTAMP, ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_GetEgressTimeStamp(CtrlIdx, BufIdx, timeQualPtr, timeStampPtr);
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Reads back the egress time stamp on a dedicated message object.
* @note          It must be called within the TxConfirmation() function.
* @api
* @param[in]     CtrlIdx Index of the controller which the egress timestamp shall be
*                read. 
* @param[in]     DataPtr Pointer to the message buffer, where Application expects ingress 
*                time stamping
* @param[out]    timeQualPtr quality of HW time stamp, e.g. based on current drift
* @param[out]    timeStampPtr current time stamp
* @implements    Eth_GetIngressTimeStamp_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_GetIngressTimeStamp ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) DataPtr, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                             )
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_GETINGRESSTIMESTAMP, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_GETINGRESSTIMESTAMP, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if ((NULL_PTR == DataPtr)||(NULL_PTR == timeQualPtr)||(NULL_PTR == timeStampPtr))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_GETINGRESSTIMESTAMP, ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_GetIngressTimeStamp(CtrlIdx, DataPtr, timeQualPtr, timeStampPtr);
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}
/*================================================================================================*/
/**
* @brief        Allows the Time Slave to adjust the local ETH Reference clock in HW.
* @note         Only use this function when this controller used as Time Slave.
* @api
* @param[in]    CtrlIdx Index of the controller which time shall be corrected
* @param[in]    timeOffsetPtr  offset between time stamp grandmaster and time stamp by local 
*               clock.
* @param[in]    rateRatioPtr time elements to calculate and to modify the ratio of the frequency of 
*               the grandmaster in relation to the frequency of the Local Clock
* @implements   Eth_SetCorrectionTime_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_SetCorrectionTime    ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETH_APPL_DATA) timeOffsetPtr, \
                                P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_APPL_DATA) rateRatioPtr \
                                              )
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_SETCORRECTIONTIME, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_SETCORRECTIONTIME, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if ((NULL_PTR == timeOffsetPtr)||(NULL_PTR == rateRatioPtr))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_SETCORRECTIONTIME, ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_SetCorrectionTime(CtrlIdx, timeOffsetPtr, rateRatioPtr);
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Allows the Time Master to adjust the global ETH Reference clock in HW.
* @note          We can use this method to set a global time base on ETH in general or to 
*                synchronize the global ETH time base with another time base, e.g. FlexRay.
* @api
* @param[in]     CtrlIdx Index of the TM controller which time shall be adjusted. 
* @param[in]     timeStampPtr Pointer to new time stamp
* @implements    Eth_SetGlobalTime_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE)  Eth_SetGlobalTime   ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                                    )
{
    /* Used to track function success */
    VAR(Std_ReturnType, AUTOMATIC) u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK;
    
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_SETGLOBALTIME, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_SETGLOBALTIME, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if (NULL_PTR == timeStampPtr)
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_SETGLOBALTIME, ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                Eth_Ipw_SetGlobalTime(CtrlIdx, timeStampPtr);
                u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return u8FunctionSuccess;
}
#endif /* ETH_GLOBALTIME_SUPPORT */

/*================================================================================================*/
/**
* @brief         Provides access to a transmit buffer of the specified
*                controller.
* @warning       The application should handle possible difference between the
*                requested and granted buffer lengths. It is not necessary to
*                use whole granted buffer i.e. some space at the end may not
*                be written.
* @api
* @param[in]     CtrlIdx Index of the controller which buffer shall be provided.
*                The index is valid within the context of the Ethernet Driver
*                only.
* @param[out]    BufIdxPtr Index to the granted transmit buffer resource.
*                It uniquely identifies the buffer in all subsequent calls of
*                functions Eth_Transmit() and Eth_TxConfirmation().
* @param[out]    BufPtr Pointer to the granted buffer. This is the space where
*                the data to be transmitted shall be stored.
* @param[in,out] LenBytePtr Buffer payload length
*                - In: desired length in bytes
*                - Out: granted length in bytes
* @return        Error and buffer status
* @retval        BUFREQ_OK: Buffer was successfully granted and no error has
*                occurred.
* @retval        BUFREQ_E_NOT_OK: A development error was detected and no buffer
*                was granted.
* @retval        BUFREQ_E_BUSY: All available buffers in use therefore no
*                buffer was granted. No error has been detected.
* @implements    Eth_ProvideTxBuffer_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(BufReq_ReturnType, ETH_CODE) Eth_ProvideTxBuffer( \
                            VAR(uint8, AUTOMATIC) CtrlIdx, \
                            P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) BufIdxPtr, \
                            P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) BufPtr, \
                            P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LenBytePtr \
                                                     )
{
    /* Variable used to track function success status */
    VAR(BufReq_ReturnType, AUTOMATIC) eFunctionSuccess = BUFREQ_E_NOT_OK;
    VAR(uint16, AUTOMATIC) u16TempLenByte; /* Avoid changes of input
                                              parameters in case of an error */
    VAR(uint32, AUTOMATIC) u32MaxLenByte; /* Maximum available buffer length that
                                              drivers can provide*/
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_PROVIDETXBUFFER, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == BufIdxPtr)
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_PROVIDETXBUFFER, ETH_E_PARAM_POINTER \
                                  );
        }
        else
        {
            if(NULL_PTR == BufPtr)
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_PROVIDETXBUFFER, ETH_E_PARAM_POINTER \
                                      );
            }
            else
            {
                if(NULL_PTR == LenBytePtr)
                {
                    (void)Det_ReportError ( \
                        (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                        ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                        ETH_SID_PROVIDETXBUFFER, ETH_E_PARAM_POINTER \
                                          );
                }
                else
                {
                    if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
                    {
                        (void)Det_ReportError ( \
                            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                            ETH_SID_PROVIDETXBUFFER, ETH_E_NOT_INITIALIZED \
                                              );
                    }
                    else
                    {
    #endif /* ETH_DEV_ERROR_DETECT  */
                            /* Check whether the requested length is greater than
                                maximal configured one */
    #if STD_ON == ETH_USE_MULTIBUFFER_TX_FRAMES
                            /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                            /** @violates @ref Eth_c_REF_13 MISRA rule 12.1 */
                            /** @violates @ref Eth_c_REF_6 MISRA rule 1.2 */
                            u32MaxLenByte = ((ETH_CFG_CTRLTXBUFLENBYTE(CtrlIdx)) * (VAR(uint32, AUTOMATIC))ETH_CFG_TXBUFTOTAL(CtrlIdx)) - (VAR(uint32, AUTOMATIC))14U;
    #else
                            /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                            /** @violates @ref Eth_c_REF_13 MISRA rule 12.1 */
                            /** @violates @ref Eth_c_REF_6 MISRA rule 1.2 */
                            u32MaxLenByte = ETH_CFG_CTRLTXBUFLENBYTE(CtrlIdx) - (VAR(uint32, AUTOMATIC))14U;
    #endif

                            if(*LenBytePtr > u32MaxLenByte)
                            {   /* Requested size is too long, do not lock buffer */
                                /* Set length to maximal available payload length */
                            *LenBytePtr = (VAR(uint16,AUTOMATIC))u32MaxLenByte;
                                eFunctionSuccess = BUFREQ_E_OVFL;
                            }
                            else
                            {   /* Good, the requested size fits into buffer size */
                                /* Get some space to put data in, check success */
                                u16TempLenByte = *LenBytePtr;
                                /** @violates @ref Eth_c_REF_6 MISRA rule 1.2 */
                                if(((VAR(boolean, AUTOMATIC))TRUE) == Eth_Ipw_ProvideBufferDataArea(CtrlIdx, BufIdxPtr, BufPtr, &u16TempLenByte))
                                { /* Data space is available */
                                    *LenBytePtr = u16TempLenByte;
                                    eFunctionSuccess = BUFREQ_OK;
                                }
                                else
                                { /* Data space is not available */
                                    eFunctionSuccess = BUFREQ_E_BUSY;
                                }
                            }
    #if STD_ON == ETH_DEV_ERROR_DETECT
                    }
                }
            }
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return eFunctionSuccess;
}

/*================================================================================================*/
/**
* @brief         Triggers transmission of a previously granted and then filled
*                transmit buffer.
* @api
* @param[in]     CtrlIdx Index of the controller which buffer shall be
*                transmitted. The index is valid within the context of
*                the Ethernet Driver only.
* @param[in]     BufIdx Index of the buffer resource to be transmitted.
* @param[in]     FrameType Desired value of the Ethernet frame type in the
*                frame header.
* @param[in]     TxConfirmation Activates transmission confirmation.
* @param[in]     LenByte Buffer data length in bytes (payload length).
* @param[in]     PhysAddrPtr Physical target address (MAC address) in network
*                byte order.
* @return        Error status
* @retval        E_OK No error was detected during the function execution.
* @retval        E_NOT_OK Development error was detected and the function
*                failed.
* @implements    Eth_Transmit_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(Std_ReturnType, ETH_CODE) Eth_Transmit     (
                            VAR(uint8, AUTOMATIC) CtrlIdx,
                            VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
                            VAR(Eth_FrameType, AUTOMATIC) FrameType,
                            VAR(boolean, AUTOMATIC) TxConfirmation,
                            VAR(uint16, AUTOMATIC) LenByte,
                            P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr
#if STD_ON == ETH_BRIDGE_SUPPORT
                          , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysSourceAddrPtr
#endif /* ETH_BRIDGE_SUPPORT  */
                                                )
{
    VAR(Std_ReturnType, AUTOMATIC) u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_NOT_OK; /* Used to track
                                                     function success */
    
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_TRANSMIT, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(NULL_PTR == PhysAddrPtr)
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_TRANSMIT, ETH_E_PARAM_POINTER \
                                  );
        }
        else
        {
            if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_TRANSMIT, ETH_E_NOT_INITIALIZED \
                                      );
            }
            else
            {
                if(ETH_MODE_ACTIVE != Eth_Ipw_CheckControllerIsActive(CtrlIdx))
                {
                    (void)Det_ReportError ( \
                        (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                        ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                        ETH_SID_TRANSMIT, ETH_E_INV_MODE \
                                          );
                }
                else
                {
                    /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                    /** @violates @ref Eth_c_REF_12 MISRA rule 10.1 */
                    /** @violates @ref Eth_c_REF_16 MISRA rule 10.3 */
                    /** @violates @ref Eth_c_REF_5 MISRA rule 13.7 */
                    if(BufIdx >= ETH_CFG_TXBUFTOTAL(CtrlIdx))

                    {
                        (void)Det_ReportError ( \
                            (VAR(uint8, AUTOMATIC)) \
                            ETH_MODULE_ID,  ETH_DRIVER_INSTANCE, \
                            (VAR(uint8, AUTOMATIC)) ETH_SID_TRANSMIT, \
                            ETH_E_INV_PARAM \
                                              );
                    }
                    else
                    {
    #endif /* ETH_DEV_ERROR_DETECT  */
                        /* Check whether the buffer was previously locked
                           and has not been transmitted yet */
                        /** @violates @ref Eth_c_REF_8 MISRA rule 17.4 */
                        /** @violates @ref Eth_c_REF_11 MISRA rule 11.1 */
                        if((VAR(boolean, AUTOMATIC))TRUE == Eth_Ipw_IsTxBufLockedBT(CtrlIdx, BufIdx))
                        { /* Yes, transmit the buffer */
                            Eth_Ipw_Transmit(CtrlIdx, BufIdx, FrameType, LenByte, TxConfirmation, PhysAddrPtr
#if STD_ON == ETH_BRIDGE_SUPPORT
                                                , PhysSourceAddrPtr
#endif /* ETH_BRIDGE_SUPPORT  */
                                            );
                            u8FunctionSuccess = (VAR(Std_ReturnType, AUTOMATIC))E_OK;
                        }
                        else
                        { /* No, report an error, do not transmit buffer */
    #if STD_ON == ETH_DEV_ERROR_DETECT
                            (void)Det_ReportError ( \
                                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                                ETH_SID_TRANSMIT, ETH_E_INV_PARAM \
                                                  );
    #endif /* ETH_DEV_ERROR_DETECT  */
                        }
    #if STD_ON == ETH_DEV_ERROR_DETECT
                    }
                }
            }
        }
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
    return u8FunctionSuccess; 
}

/*================================================================================================*/
/**
* @brief         Triggers frames reception notifications.
* @details       All receive buffers are checked and the first received frame is
*                passed to the EthIf module. The caller is notified whether any
*                frame was received and whether more frames are available in the
*                receive queue.
* @api
* @param[in]     CtrlIdx Index of the controller which shall be checked whether
*                any new frames were received. The index is valid within
*                the context of the Ethernet Driver only.
* @param[out]    RxStatusPtr Informs the caller whether a frame was received 
*                (@c ETH_RECEIVED or @c ETH_NOT_RECEIVED) and whether more frames
*                are available in the queue (@c ETH_RECEIVED or 
*                @c ETH_RECEIVED_MORE_DATA_AVAILABLE).
* @implements    Eth_Receive_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_Receive( \
                        VAR(uint8, AUTOMATIC) CtrlIdx, \
                        P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_DATA) RxStatusPtr \
                                 )
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_RECEIVE, \
            ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_RECEIVE, \
                ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if(ETH_MODE_ACTIVE != Eth_Ipw_CheckControllerIsActive(CtrlIdx))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_RECEIVE, ETH_E_INV_MODE \
                                      );
            }
            else
            {
    #endif /* ETH_DEV_ERROR_DETECT  */
                    /** @violates @ref Eth_c_REF_5 MISRA rule 13.7 */
                    /** @violates @ref Eth_c_REF_4 MISRA rule 17.4 */
                    /** @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
                    if((VAR(boolean, AUTOMATIC))FALSE == ETH_CFG_ENABLERXINTERRUPT(CtrlIdx))
                    {
                        /* Check all buffers and report them - returned error
                        status is ignored because there is no mean to report errors
                        in the AUTOSAR specification */
                        *RxStatusPtr = Eth_Ipw_ReportReception(CtrlIdx, (VAR(boolean, AUTOMATIC))FALSE);
                    }/*ETH_CFG_ENABLERXINTERRUPT*/
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

/*================================================================================================*/
/**
* @brief         Triggers frame transmission confirmations.
* @api
* @param[in]     CtrlIdx Index of the controller which shall be checked whether
*                any frame transmission has finished. The index is valid within
*                the context of the Ethernet Driver only.
* @details       All transmit buffers are checked and upper layers are informed
*                about successfully transmitted frames. Buffers containing
*                transmitted frames are unlocked after the confirmation.
* @implements    Eth_TxConfirmation_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_TxConfirmation(VAR(uint8, AUTOMATIC) CtrlIdx)
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(CtrlIdx >= (VAR(uint8, AUTOMATIC))ETH_MAXCTRLS_SUPPORTED)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
            ETH_SID_TXCONFIRMATION, ETH_E_INV_CTRL_IDX \
                              );
    }
    else
    {
        if(ETH_STATE_INIT != Eth_CtrlState[CtrlIdx])
        {
            (void)Det_ReportError ( \
                (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                ETH_SID_TXCONFIRMATION, ETH_E_NOT_INITIALIZED \
                                  );
        }
        else
        {
            if(ETH_MODE_ACTIVE != Eth_Ipw_CheckControllerIsActive(CtrlIdx))
            {
                (void)Det_ReportError ( \
                    (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
                    ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) \
                    ETH_SID_TXCONFIRMATION, ETH_E_INV_MODE \
                                      );
            }
            else
            {

    #endif /* ETH_DEV_ERROR_DETECT  */
                /** @violates @ref Eth_c_REF_5 MISRA rule 13.7 */
                /** @violates @ref Eth_c_REF_4 MISRA rule 17.4 */
                /** @violates @ref Eth_c_REF_14 MISRA rule 14.1 */
                if((VAR(boolean, AUTOMATIC))FALSE == ETH_CFG_ENABLETXINTERRUPT(CtrlIdx))
                {
                    /* Check all buffers and report them - returned error 
                    status is ignored because there is no mean to report errors
                    in the AUTOSAR specification */
                    (void)Eth_Ipw_ReportTransmission(CtrlIdx);
                }/*ETH_CFG_ENABLETXINTERRUPT*/
    #if STD_ON == ETH_DEV_ERROR_DETECT
            }
        } 
    }
    #endif /* ETH_DEV_ERROR_DETECT  */
}

#if STD_ON == ETH_VERSION_INFO_API
#if STD_OFF == ETH_VERSION_INFO_API_MACRO
/*================================================================================================*/
/**
* @brief         Returns the version information of this module.
* @api
* @param[out]    VersionInfoPtr Pointer where to store the version information
*                of this particular module instance.
* @implements    Eth_GetVersionInfo_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, ETH_APPL_DATA) VersionInfoPtr) 
{
    #if STD_ON == ETH_DEV_ERROR_DETECT
    if(NULL_PTR == VersionInfoPtr)
    {
        (void)Det_ReportError ( \
            (VAR(uint8, AUTOMATIC)) ETH_MODULE_ID, \
            ETH_DRIVER_INSTANCE, (VAR(uint8, AUTOMATIC)) ETH_SID_GETVERSIONINFO, ETH_E_PARAM_POINTER \
                              );
    }
    else
    {
    #endif /* ETH_DEV_ERROR_DETECT */
        VersionInfoPtr->moduleID = (VAR(uint16, AUTOMATIC))ETH_MODULE_ID;
        VersionInfoPtr->vendorID = (VAR(uint16, AUTOMATIC))ETH_VENDOR_ID;
        VersionInfoPtr->sw_major_version = (VAR(uint8, AUTOMATIC))ETH_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version = (VAR(uint8, AUTOMATIC))ETH_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version = (VAR(uint8, AUTOMATIC))ETH_SW_PATCH_VERSION;

    #if STD_ON == ETH_DEV_ERROR_DETECT
    }
    #endif /* ETH_DEV_ERROR_DETECT */
}
#endif /* STD_OFF == ETH_VERSION_INFO_API_MACRO */
#endif /* ETH_VERSION_INFO_API */
/*================================================================================================*/
/**
* @brief         The function checks for controller errors and lost frames. Used for polling state 
*                changes. Calls EthIf_CtrlModeIndication when the controller mode changed.
* @api
* @implements    Eth_MainFunction_Activity
*/

/** @violates @ref Eth_c_REF_7 MISRA rule 8.10 */
FUNC(void, ETH_CODE) Eth_MainFunction(VAR(void, AUTOMATIC))
{
    Eth_Ipw_MainFunction();
}

#define ETH_STOP_SEC_CODE

/**
 * @violates @ref Eth_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
