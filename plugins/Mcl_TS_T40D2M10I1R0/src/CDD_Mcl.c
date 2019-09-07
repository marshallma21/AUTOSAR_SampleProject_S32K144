/**
 *     @file            CDD_Mcl.c
 *     @version 1.0.1
 *
 *     @brief   AUTOSAR Mcl - MCL Driver source file.
 *     @details MCL driver source file, containing the Autosar API specification and other variables
 *              and functions that are exported by the MCL driver.
 *
 *     @addtogroup MCL_MODULE
 *     @{
 */
/*==================================================================================================
 *     Project             : AUTOSAR 4.2 MCAL
 *     Platform            : ARM
 *     Peripheral          : eDMA
 *     Dependencies        : none
 *
 *     Autosar Version     : 4.2.2
 *     Autosar Revision    : ASR_REL_4_2_REV_0002
 *     Autosar ConfVariant :
 *     SWVersion           : 1.0.1
 *     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
 *
 *     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
 *     All Rights Reserved.
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
 * @section Mcl_c_1
 * Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
 * before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
 * is as  per Autosar  requirement MEMMAP003.
 *
 * @section Mcl_c_2
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice
 * This is not a violation since all header files are protected against multiple inclusions
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
 * significance and case sensitivity are supported for external identifiers.
 * This is not a violation since all the compilers used interpret the identifiers correctly.
 *
 * @section Mcl_c_5
 * Violates MISRA 2004 Required Rule 8.10, could be made static
 * The respective code could not be made static because of layers architecture design of the
 * driver.
 *
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_c_6
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* Middle layer between AUTOSAR and hardware needs a way to map HLD 
* functions to IP functions.
*
* @section Mcl_c_7
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
* @section Mcl_c_8
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
* @section Mcl_c_10
* Violates MISRA 2004 Required Rule 13.7, Boolean operation whose result are
* invariant shall not be perrmited
*
* @section Mcl_c_11
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
* it is accessed from several functions
*
* @section Mcl_c_12
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used.
* The comma is used  to abstract the trusted call function and to determine when the return into user mode is needed.
*
* @section  [global]
*           Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
*           be implicitly converted to a different underlying type.
*           This violation due to implementation of MCAL_TRUSTED_CALL function.
*
*/

/*==================================================================================================
 *                                          INCLUDE FILES
 *  1) system and project includes
 *  2) needed interfaces from external units
 *  3) internal and external interfaces from this unit
==================================================================================================*/
/**
*     @file            CDD_Mcl.c
*/
#include "Mcal.h"
#include "CDD_Mcl.h"

#if (MCL_ENABLE_DMA == STD_ON)
#include "Mcl_Notif.h"
#endif /* (MCL_ENABLE_DMA == STD_ON) */

#include "Mcl_IPW.h"

#if (MCL_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

/*==================================================================================================
 *                                      SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCL_VENDOR_ID_C                     43

#define MCL_AR_RELEASE_MAJOR_VERSION_C      4
#define MCL_AR_RELEASE_MINOR_VERSION_C      2
#define MCL_AR_RELEASE_REVISION_VERSION_C   2
#define MCL_SW_MAJOR_VERSION_C              1
#define MCL_SW_MINOR_VERSION_C              0
#define MCL_SW_PATCH_VERSION_C              1

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and MCL header file are of the same vendor */
#if (MCL_VENDOR_ID_C != MCL_VENDOR_ID)
#error "CDD_Mcl.c and CDD_Mcl.h have different vendor IDs"
#endif

#if ((MCL_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl.c and CDD_Mcl.h are different"
#endif
/* Check if source file and MCL header file are of the same Software version */
#if ((MCL_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl.c and CDD_Mcl.h are different"
#endif

/* Check if source file and DET header file are of the same version */
#if (MCL_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCL_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl.c and Det.h are different"
#endif
#endif
#endif /* MCL_DEV_ERROR_DETECT */

/* Check if source file and Mcl_IPW header file are of the same vendor */
#if (MCL_VENDOR_ID_C != MCL_IPW_VENDOR_ID)
#error "CDD_Mcl.c and Mcl_IPW.h have different vendor IDs"
#endif

/* Check if source file and Mcl_IPW header file are of the same version */
#if ((MCL_AR_RELEASE_MAJOR_VERSION_C != MCL_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AR_RELEASE_MINOR_VERSION_C != MCL_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AR_RELEASE_REVISION_VERSION_C != MCL_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Mcl.c and Mcl_IPW.h are different"
#endif
/* Check if source file and Mcl_IPW header file are of the same Software Version */
#if ((MCL_SW_MAJOR_VERSION_C != MCL_IPW_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_C != MCL_IPW_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_C != MCL_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl.c and Mcl_IPW.h are different"
#endif

#if (MCL_ENABLE_DMA == STD_ON)

/* Check if source file and Mcl_Notif.h file are of the same vendor */
#if (MCL_VENDOR_ID_C != MCL_NOTIF_VENDOR_ID)
    #error "CDD_Mcl.c and Mcl_Notif.h have different vendor ids"
#endif
/* Check if source file and Mcl_Notif.h file are of the same Autosar version */
#if ((MCL_AR_RELEASE_MAJOR_VERSION_C    != MCL_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AR_RELEASE_MINOR_VERSION_C    != MCL_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AR_RELEASE_REVISION_VERSION_C != MCL_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl.c and Mcl_Notif.h are different"
#endif
/* Check if source file and Mcl_Notif.h file are of the same Software version */
#if ((MCL_SW_MAJOR_VERSION_C != MCL_NOTIF_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_C != MCL_NOTIF_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_C != MCL_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_Mcl.c and Mcl_Notif.h are different"
#endif
#endif /* (MCL_ENABLE_DMA == STD_ON) */

/* Check if source file and Mcal.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCL_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl.c and Mcal.h are different"
#endif
#endif

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if(MCL_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This macro ends the validation of the global call.
 * @details    This macro ends the validation for Mcl_Init
 *
 * @implements Mcl_EndValidateGlobalCall_Activity
 * */
 
/** @violates @ref Mcl_c_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define MCL_ENDVALIDATEGLOBALCALL()
#endif 

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/

#define MCL_START_SEC_VAR_INIT_UNSPECIFIED
/*
 * @violates @ref Mcl_c_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Mcl_MemMap.h"

#if (MCL_ENABLE_DMA == STD_ON)
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
P2CONST( Mcl_DemConfigType, MCL_VAR, MCL_APPL_CONST) Mcl_pDemCfgPtr = NULL_PTR;
#endif
#endif
/**
* @brief          Global variable (pointer) used for storing the Mcl driver configuration data.
*/
/** @violates @ref Mcl_c_11 Violates MISRA 2004 Required Rule 8.7 */
static P2CONST(Mcl_ConfigType, MCL_VAR,  MCL_APPL_CONST)  Mcl_pConfig  = NULL_PTR;


#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
 * @violates @ref Mcl_c_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
 * before "#include"
 *
 * @violates @ref Mcl_c_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Mcl_MemMap.h"

/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateGlobalCall
(
    VAR(uint8, AUTOMATIC)u8ServiceId
);
#if (MCL_DEINIT_API == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateDeInitNotBusy(void);
#endif
#endif
#if (MCL_VALIDATE_PARAMS == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidatePtrInit
(
    P2CONST(Mcl_ConfigType, AUTOMATIC, MCL_APPL_CONST) ConfigPtr
);
#endif
#if ((MCL_VALIDATE_PARAMS == STD_ON) && (MCL_GET_VERSION_INFO_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateVersionInfoCall
(
P2CONST(Std_VersionInfoType, AUTOMATIC, MCL_APPL_CONST) versioninfo
);
#endif

#if (MCL_ENABLE_DMA == STD_ON)

    #ifdef MCL_DMA_NOTIFICATION_SUPPORTED
    #if ((MCL_VALIDATE_PARAMS == STD_ON) && (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON))
    LOCAL_INLINE  FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateParamNotification
    (
        VAR(Mcl_NotifyType, AUTOMATIC) pMclChannelNotification
    );
    #endif
    #endif
    #if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    LOCAL_INLINE  FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateChannelConfigCall
    (
        VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber,
        VAR(uint8,           AUTOMATIC) u8ServiceId
    );
    #endif
    
#endif /* MCL_ENABLE_DMA == STD_ON */
/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/*
 * @violates @ref Mcl_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
 *        before "#include"
 */
/*
 * @violates @ref Mcl_c_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Mcl_MemMap.h"


#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for Mcl_Init.
 *
 * @param[in]  u8ServiceId The service id of the caller function
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Mcl_ValidateGlobalCall_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateGlobalCall(VAR(uint8, AUTOMATIC)u8ServiceId)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR != Mcl_pConfig) /* Check if already initialized */
    {
        if (MCL_INIT_ID_U8 == u8ServiceId) /* If caller is the initialization function, error */
        {            
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)u8ServiceId, MCL_E_ALREADY_INITIALIZED_U8);
        }
        else
        {
            valid=(Std_ReturnType)E_OK;
        }
    }
    else 
    {
        if (MCL_INIT_ID_U8 == u8ServiceId) /* If caller is the initialization function, ok */
        {
            valid=(Std_ReturnType)E_OK;            
        }
        else
        {            
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)u8ServiceId, MCL_E_UNINIT_U8);
        } 
    }

    return valid;
}
#if (MCL_DEINIT_API == STD_ON)
/**
 * @brief      This function validates the call of Mcl_DeInit.
 * @details    The function returns E_NOT_OK if the underlaying hardware is busy when Mcl_DeInit is called
 *
 * @param[in]  u8ServiceId The service id of the caller function
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateDeInitNotBusy(void)
{

    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK; 
    #if (MCL_ENABLE_DMA == STD_ON)
    VAR(Mcl_ChannelType, AUTOMATIC) logicalDmaChannel = MCL_DMA_LOGICAL_CHANNEL_0;
    VAR(boolean, AUTOMATIC) bActive = (boolean)FALSE;

    /* loop through all configured channels */
    /* the array of channels uses the logical number as array index */
    for (logicalDmaChannel = 0U; logicalDmaChannel < Mcl_pConfig->pMclDmaConfig->MclDmaNumchannels; logicalDmaChannel++)
    {
        /* check if dma transfer in progress */
        bActive = Mcl_IPW_DmaIsTransferActive(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, logicalDmaChannel);
    
        if ((boolean)TRUE == bActive)
        {
            /* if transfer in progress the function Mcl_Deinit is not allowed */
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_DEINIT_ID_U8, (uint8)MCL_E_DMA_TRANSFER_ACTIVE_U8);           
            valid = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    #endif
    return valid;
}
#endif
#endif /* MCL_VALIDATE_GLOBAL_CALL == STD_ON */

#if (MCL_VALIDATE_PARAMS == STD_ON)
/**
 * @brief              This function validate the initialization pointer.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidatePtrInit(
                                        P2CONST(Mcl_ConfigType, AUTOMATIC, MCL_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    #if (MCL_DEV_ERROR_DETECT == STD_ON)
        #if (MCL_PRECOMPILE_SUPPORT == STD_OFF)
        if (NULL_PTR == ConfigPtr)
        {
            valid=(Std_ReturnType)E_NOT_OK;            
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_INIT_ID_U8, (uint8)MCL_E_INIT_FAILED_U8);

        }
        else
        {
            /** do nothing */
        }    
        #elif (MCL_PRECOMPILE_SUPPORT == STD_ON)
        if (NULL_PTR != ConfigPtr)
        {
            valid=(Std_ReturnType)E_NOT_OK;
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_INIT_ID_U8, (uint8)MCL_E_INIT_FAILED_U8);
        }
        else
        {
            /** do nothing */
        }    
        #endif 
    #endif

    return valid;  
}
#endif /* (MCL_VALIDATE_PARAMS == STD_ON)*/

#if ((MCL_VALIDATE_PARAMS == STD_ON) && (MCL_GET_VERSION_INFO_API == STD_ON))
/**
 * @brief       This function validates the versionInfo parameter
 *
 * @param[in]   versioninfo  Pointer to a buffer where the results for version shall be saved
 *
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateVersionInfoCall(P2CONST(Std_VersionInfoType, AUTOMATIC, MCL_APPL_CONST) versioninfo)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;
    
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_GETVERSIONINFO_ID_U8, MCL_E_PARAM_VINFO_U8);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (MCL_VALIDATE_PARAMS == STD_ON) && (MCL_GET_VERSION_INFO_API == STD_ON */
#if (MCL_ENABLE_DMA == STD_ON)
#if ((MCL_VALIDATE_PARAMS == STD_ON) && (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON))
/**
* @brief          Validate the notification handler of a Mcl channel.
*                 In order to be valid, the notification handler should not be
*                 NULL. In case it is NULL, the function will report an error to 
*                 Det or Dem,depending on the environment the driver is run in.
*
*
* @param[in]      pMclChannelNotification    Notification of the channel to be validated
*
* @return         Std_ReturnType  Validity of notification handler  
* @retval         E_OK            Notification handler is valid
* @retval         E_NOT_OK        Notification handler is not valid

* @api
*
* @note           .
*/
LOCAL_INLINE  FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateParamNotification
(
    VAR(Mcl_NotifyType, AUTOMATIC) pMclChannelNotification
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Check if Notification param is not NULL */
    if(NULL_PTR == pMclChannelNotification)
    {
        (void)Det_ReportError((uint16) MCL_MODULE_ID, 0U, MCL_ENABLENOTIFICATION_ID_U8, MCL_E_PARAM_NOTIFICATION_NULL_U8);
        retVal = (Std_ReturnType)E_NOT_OK;        
    }
    return retVal;   
}
#endif /* (MCL_VALIDATE_PARAMS == STD_ON && MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) */

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)

/**
* @brief          Validate the call of a function impacting the configuration of one of the driver's
* @details        channels. Before executing, a function which changes the configuration of a 
*                 channel shall check if:
*                 1. It is not preempting itself
*                 2. It is not preempting a function that changes the configuration of the 
*                    entire driver
*                 In any of the above cases, the function will report an error to Det
*
*
* @param[in]      ChannelId       Id of the channel the caller tries to update
* @param[in]      ServiceId       Id of the service calling this function
*
* @return         Std_ReturnType  Call is valid or not  
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
* @api
*
* @note    
* @implements Mcl_ValidateChannelConfigCall_Activity
*/
LOCAL_INLINE  FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateChannelConfigCall
(
    VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint8,           AUTOMATIC) u8ServiceId
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;

    /* Check if the driver is initialized */
    if(NULL_PTR == Mcl_pConfig)
    {
        /* Driver not initialized yet */
        (void)Det_ReportError((uint16) MCL_MODULE_ID, 0U, (uint8)u8ServiceId, MCL_E_UNINIT_U8);
    }
    else
    {
        /* Check that the channel is in valid range */
        if (ChannelNumber >= Mcl_pConfig->pMclDmaConfig->MclDmaNumchannels)
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)u8ServiceId, MCL_E_INVALID_CHANNEL_U8);
        }
        else
        {   
            /* Driver is initialized and channel is valid */
            retVal = (Std_ReturnType)E_OK;   
        }
    }
    return retVal;    
}

/**
* @brief          Completes the execution of a function impacting the configuration of a driver channel.
* @details        Performs actions in order to ensure that after it's caller has completed the execution
*                 the driver will remain in a state allowing execution of other functions updating the 
*                 configuration of the entire driver or of a single channel.
*
*
*
* @return         void
*
* @api
*
* @note           .
*/
/** @violates @ref Mcl_c_6 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber)

#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON) */

#endif /* (MCL_ENABLE_DMA == STD_ON) */
#if (MCL_ENABLE_TRGMUX == STD_ON)
#if (MCL_DEV_ERROR_DETECT == STD_ON) 
/**
* @brief          Validate parameters for Mcl_TrgMuxConfigInput 
*
*
* @param[in]      registerIndex       index of the trgmux register
* @param[in]      selNumber           selection of trgmux input
* @param[in]      trigger             triger input
*
* @return         Std_ReturnType  Call is valid or not  
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
* @api
*
* @note    
* @implements Mcl_ValidateChannelConfigCall_Activity
*/
LOCAL_INLINE  FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateTrgMuxConfigCall
(   
    VAR(Mcl_TrgMuxRegisterIndexType, AUTOMATIC) registerIndex,  
    VAR(Mcl_TrgMuxSelectionNrType, AUTOMATIC) selNumber,
    VAR(Mcl_TrgMuxTriggerType, AUTOMATIC) trigger
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, AUTOMATIC) lockVal = (boolean)FALSE;
    VAR(uint8, AUTOMATIC) idx = (uint8)0U;
   
    /* get lock value */
    /*@violates @ref Mcl_c_7 Violates MISRA 2004 Rule 11.1*/
    /** @violates @ref Mcl_c_8 Violates MISRA 2004 Rule 11.3*/
    lockVal = (boolean)Mcl_IPW_TrgMuxGetLock((uint32)registerIndex);

    if ((boolean)TRUE == lockVal)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_ID_U8, MCL_E_TRGMUX_LOCKED_U8);
       
    }
    else
    {   
        /* Check that the registerIndex is in valid range */
        if (registerIndex > (Mcl_TrgMuxRegisterIndexType)MCL_NUM_TRGMUX_REG)
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_ID_U8, MCL_E_INVALID_REGINDEX_U8);
        }
        else
        {
            /* Check that the selNumber is in valid range */
            /**
            *@violates @ref Mcl_c_10 Violates MISRA 2004 Rule 13.7
            **/
            if (selNumber > (Mcl_TrgMuxSelectionNrType)MCL_TRGMUX_SEL_3)
            {
                (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_ID_U8, MCL_E_INVALID_TRGMUX_SEL_U8);
            }
            else
            {
                /* Check that the selNumber is in valid range */
                /**
                *@violates @ref Mcl_c_10 Violates MISRA 2004 Rule 13.7
                **/
                if (trigger > (Mcl_TrgMuxTriggerType)MCL_MAXIMUM_BIT_FIELD_TRIGGER_VALUE)
                {
                    (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_ID_U8, MCL_E_INVALID_TRGMUX_TRIGGER_U8);
                }
                else
                {   
                    /* check that sel1,sel2,sel3 will not be configured for registers having available only sel0*/
                    for (idx=(uint8)0; idx<(uint8)MCL_NUM_REG_MISSING_SEL_FIELD; idx++)
                    {
                        if ((Mcl_TrgMux_RegistersOneInput[idx] == registerIndex) && (selNumber != MCL_TRGMUX_SEL_0))
                        {
                            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_ID_U8, MCL_E_INVALID_TRGMUX_SEL_U8);
                            break;
                        }
                    }
                    if(idx == (uint8)MCL_NUM_REG_MISSING_SEL_FIELD)
                    {
                        /* parameters are valid */
                        retVal = (Std_ReturnType)E_OK;  
                    }
                }
            }
        }
    }
    return retVal;    
}

/**
* @brief          Validate parameters for Mcl_TrgMuxConfigInput 
*
*
* @param[in]      registerIndex       index of the trgmux register
* @param[in]      selNumber           selection of trgmux input
* @param[in]      trigger             triger input
*
* @return         Std_ReturnType  Call is valid or not  
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
* @api
*
* @note    
* @implements Mcl_TrgMuxEnableLock_Activity
*/
LOCAL_INLINE  FUNC(Std_ReturnType, MCL_CODE) Mcl_ValidateTrgMuxConfigLockCall
(   
    VAR(Mcl_TrgMuxRegisterIndexType, AUTOMATIC) registerIndex
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, AUTOMATIC) lockVal = (boolean)FALSE;

    /*@violates @ref Mcl_c_7 Violates MISRA 2004 Rule 11.1*/
    /** @violates @ref Mcl_c_8 Violates MISRA 2004 Rule 11.3*/
    lockVal = (boolean)Mcl_IPW_TrgMuxGetLock((uint32)registerIndex);

    if ((boolean)TRUE == lockVal)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_LOCK_U8, MCL_E_TRGMUX_LOCKED_U8);
    }
    else
    {
        /* Check that the registerIndex is in valid range */
        if (registerIndex > (Mcl_TrgMuxRegisterIndexType)MCL_NUM_TRGMUX_REG)
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_TRGMUX_CONFIG_LOCK_U8, MCL_E_INVALID_REGINDEX_U8);
        }
        else
        {   
            /* parameters are valid */
            retVal = (Std_ReturnType)E_OK;   
        }
    }
    return retVal;    
}
#endif
#endif
/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief          This function initializes the MCL hardware components.
 * @details        This service is a non reentrant function used for driver initialization.
 *        The  Initialization function  shall initialize  all relevant  registers of  the configured
 *        hardware with the  values of the  structure referenced by  the parameter ConfigPtr.
 *        If  the  hardware  allows  for   only  one  usage   of  the  register,   the  driver module
 *        implementing that functionality is responsible for initializing the register.
 *        The initialization function of this module shall always have a pointer as a parameter, even
 *        though for Variant PC no configuration set shall be given.
 *        Instead a NULL pointer shall be passed to the initialization function.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return             void
 * @implements         Mcl_Init_Activity
 *
 * @api
 *
 * 
 */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_Init(P2CONST( Mcl_ConfigType, AUTOMATIC, MCL_APPL_CONST) ConfigPtr)
{
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON) || (MCL_VALIDATE_PARAMS == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
#endif

#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Mcl_ValidateGlobalCall(MCL_INIT_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
#if (MCL_VALIDATE_PARAMS == STD_ON)
        valid = Mcl_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* (MCL_VALIDATE_PARAMS == STD_ON) */

#if (MCL_PRECOMPILE_SUPPORT == STD_ON)
            Mcl_pConfig = &Mcl_Init_PBCfgVariantPredefined;
           (void)ConfigPtr;
#else
            Mcl_pConfig = ConfigPtr;
#endif /* MCL_PRECOMPILE_SUPPORT */

#if (MCL_ENABLE_DMA == STD_ON)

#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* Get a local copy of the DEM error reporting structure. */
            Mcl_pDemCfgPtr = Mcl_pConfig->Mcl_pDemConfig;
#endif 
            /* Init eDMA controllers and channels. */
            Mcl_IPW_Init(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig);
#endif
#if (MCL_ENABLE_TRGMUX == STD_ON)
            /* Init TRGMUX registers */
            /** @violates @ref Mcl_c_12 The comma operator shall not be used. */
            MCL_IPW_TRGMUX_INIT(Mcl_pConfig->pMclTrgMuxConfig);
#endif
#ifdef MCL_ENABLE_CROSSBAR_LITE
#if (MCL_ENABLE_CROSSBAR_LITE == STD_ON)
            /* Init Crossbar registers */
            Mcl_IPW_Crossbar_Init();
#endif
#endif        
#if (MCL_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
#endif
}

#if (MCL_DEINIT_API == STD_ON)
/**
 * @brief          This function de-initializes the Mcl driver.
 * @details        This service is a non reentrant function.
 *                 Returns all underlying hardware to a state comparable to their
 *                 power on reset state, and de-initialize the MCL driver.
 *
 * @param[in]      void
 * @return         void
 * @implements     Mcl_DeInit_Activity
 */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DeInit(void)
{
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid = (Std_ReturnType)E_NOT_OK;

    /* Validate call of function */
    valid = Mcl_ValidateGlobalCall(MCL_DEINIT_ID_U8);
    /* Check validity of function call */
    if ((Std_ReturnType)E_OK == valid)
    {
        /* Validate call of function for the Dma feature*/
        valid = Mcl_ValidateDeInitNotBusy(); 

        /* Check validity of function call */
        if ((Std_ReturnType)E_OK == valid)
        {
    #endif
            #if (MCL_ENABLE_DMA == STD_ON)
            /* DeInit the DMA feature*/
            Mcl_IPW_DeInit(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig);
            #endif
            /* Set the global configuration pointer to NULL */
            Mcl_pConfig = NULL_PTR;
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
        }
    }
    /* End validation of global call */
    MCL_ENDVALIDATEGLOBALCALL();
    #endif
}
#endif
#if (MCL_GET_VERSION_INFO_API == STD_ON)
/*===============================================================================================*/
/**
 * @brief   This service returns the version information of this module.
 * @details This  service is Non reentrant and returns the version information of this module.
 *          The version information includes:
 *          - Module Id
 *          - Vendor Id
 *          - Vendor specific version numbers
 *          If source code for caller and callee of this function is available this function should
 *          be realized as a macro. The macro should be defined in the modules header file.
 *
 * @param[out]    versioninfo      Pointer to location to store version info
 *
 * @return void
 *
 * @api
 *
 * @implements Mcl_GetVersionInfo_Activity
 * @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static
 *
 * */
FUNC(void, MCL_CODE) Mcl_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MCL_APPL_DATA)versioninfo)
{
#if (MCL_VALIDATE_PARAMS == STD_ON)
    if ((Std_ReturnType)E_OK == Mcl_ValidateVersionInfoCall(versioninfo))
    {
#endif
        (versioninfo)->vendorID         = (uint16)MCL_VENDOR_ID;
        (versioninfo)->moduleID         = (uint8)MCL_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)MCL_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)MCL_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)MCL_SW_PATCH_VERSION;
#if (MCL_VALIDATE_PARAMS == STD_ON)
    }
#endif
}
#endif  /* MCL_GET_VERSION_INFO_API == STD_ON */

#if (MCL_ENABLE_DMA == STD_ON)
/*===============================================================================================*/
/**
 * @brief   This function configures a DMA Channel
 *
 * @details This function is reentrant and configures the specified DMA channel
 * @param[in]     dma_channel          Numeric identifier of the DMA channel
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigChannel_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaConfigChannel( VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                           P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor)
{
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    valid = Mcl_ValidateGlobalCall(MCL_CONFIG_CH_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(dma_channel, MCL_CONFIG_CH_ID_U8))
        {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_DEV_ERROR_DETECT == STD_ON) 
        if (NULL_PTR == config_descriptor)
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_CH_ID_U8, MCL_E_PARAM_POINTER_U8);
        }
        else
        {
#endif        
            /* Call IPW config channel function*/
            Mcl_IPW_DmaConfigChannel(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, dma_channel, config_descriptor);
#if (MCL_DEV_ERROR_DETECT == STD_ON)             
        }
#endif        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        MCL_ENDVALIDATECHANNELCONFIGCALL(dma_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */           
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */   
}                                            

/*===============================================================================================*/
/**
 * @brief   This function configures linked DMA Channel
 *
 * @details This function is reentrant and configures the specified linked DMA channel
 * @param[in]     dma_channel          Numeric identifier of the DMA channel
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 * @param[in]     next_channel         Numeric identifier of the next DMA channel
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigLinkedChannel_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(void, MCL_CODE) Mcl_DmaConfigLinkedChannel( VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                                 P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                 VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    valid = Mcl_ValidateGlobalCall(MCL_CONFIG_LINK_CH_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(dma_channel, MCL_CONFIG_LINK_CH_ID_U8))
        {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
            if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(next_channel, MCL_CONFIG_LINK_CH_ID_U8))
            {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_DEV_ERROR_DETECT == STD_ON)
            if (NULL_PTR == config_descriptor)
            {
                (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_LINK_CH_ID_U8, MCL_E_PARAM_POINTER_U8);
            }
            else
            {
#endif         
                /* Call IPW config linked channel function*/
                Mcl_IPW_DmaConfigLinkedChannel(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, dma_channel, config_descriptor, next_channel);
#if (MCL_DEV_ERROR_DETECT == STD_ON)                
            }
#endif            
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
            }
            MCL_ENDVALIDATECHANNELCONFIGCALL(next_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        MCL_ENDVALIDATECHANNELCONFIGCALL(dma_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */                        
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */   
} 

/*===============================================================================================*/
/**
 * @brief   This function configures a DMA Tcd
 *
 * @details This function is reentrant and configures the specified DMA Tcd
 * @param[in]     pTcdAddress          Pointer to the TCD to be configured
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigTcd_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaConfigTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                       P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if ((NULL_PTR == config_descriptor) || (NULL_PTR == pTcdAddress))
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_TCD_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call IPW config tcd function*/
        Mcl_IPW_DmaConfigTcd(pTcdAddress, config_descriptor);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
} 

/*===============================================================================================*/
/**
 * @brief   This function configures a scatter gather DMA channel
 *
 * @details This function is reentrant and configures the specified scatter gather DMA Channel
 * @param[in]     dma_channel          Numeric identifier of the DMA channel
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 * @param[in]     pNext_tcd            Pointer to the next TCD
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigScatterGatherChannel_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherChannel( VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                                        P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                        P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd)
{
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    valid = Mcl_ValidateGlobalCall(MCL_CONFIG_SCA_CH_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(dma_channel, MCL_CONFIG_SCA_CH_ID_U8))
        {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_DEV_ERROR_DETECT == STD_ON)
        if ((NULL_PTR == config_descriptor) || (NULL_PTR == pNext_tcd))
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_SCA_CH_ID_U8, MCL_E_PARAM_POINTER_U8);
        }
        else
        {
#endif        
            /* Call IPW config scatter gather channel function*/
            Mcl_IPW_DmaConfigScatterGatherChannel(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, dma_channel, config_descriptor, pNext_tcd);
#if (MCL_DEV_ERROR_DETECT == STD_ON)            
        }
#endif        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        MCL_ENDVALIDATECHANNELCONFIGCALL(dma_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */     
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */       
} 

/*===============================================================================================*/
/**
 * @brief   This function configures a linked DMA Tcd
 *
 * @details This function is reentrant and configures a linked DMA Tcd
 * @param[in]     pTcdAddress          Pointer to the TCD to be configured
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 * @param[in]     next_channel         Numeric identifier of the next DMA channel
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigLinkedTcd_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(void, MCL_CODE) Mcl_DmaConfigLinkedTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                             P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                             VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(next_channel, MCL_CONFIG_LINK_TCD_ID_U8))
    {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if ((NULL_PTR == config_descriptor) || (NULL_PTR == pTcdAddress))
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_LINK_TCD_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call IPW config linked tcd function*/
        Mcl_IPW_DmaConfigLinkedTcd(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, pTcdAddress, config_descriptor, next_channel);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(next_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */             
} 

/*===============================================================================================*/
/**
 * @brief   This function configures a linked scatter gather DMA Tcd
 *
 * @details This function is reentrant and configures a linked scatter gather DMA Tcd
 * @param[in]     pTcdAddress          Pointer to the TCD to be configured
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 * @param[in]     pNext_tcd            Pointer to the next TCD
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigScatterGatherTcd_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if ((NULL_PTR == config_descriptor) || (NULL_PTR == pTcdAddress) || (NULL_PTR == pNext_tcd))
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_SCA_TCD_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call IPW config scatter gather tcd function*/
        Mcl_IPW_DmaConfigScatterGatherTcd(pTcdAddress, config_descriptor, pNext_tcd);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
} 

/*===============================================================================================*/
/**
 * @brief   This function configures a scatter gather DMA channel with linking.
 *
 * @details This function is reentrant and configures the specified scatter gather DMA Channel and linking.
 * @param[in]     dma_channel          Numeric identifier of the DMA channel
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 * @param[in]     pNext_tcd            Pointer to the TCD address used for scatter gather
 * @param[in]     next_channel         Channel used for link
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigScatterGatherLinkedChannel_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherLinkedChannel( VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                                              P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                              P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                              VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    valid = Mcl_ValidateGlobalCall(MCL_CONFIG_SCA_LINK_CH_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(dma_channel, MCL_CONFIG_SCA_LINK_CH_ID_U8))
        {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
            if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(next_channel, MCL_CONFIG_SCA_LINK_CH_ID_U8))
            {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_DEV_ERROR_DETECT == STD_ON)
            if ((NULL_PTR == config_descriptor) || (NULL_PTR == pNext_tcd))
            {
                (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_SCA_LINK_CH_ID_U8, MCL_E_PARAM_POINTER_U8);
            }
            else
            {
#endif            
                /* Call IPW config scatter gather channel function*/
                Mcl_IPW_DmaConfigScatterGatherLinkedChannel(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, dma_channel, config_descriptor, pNext_tcd, next_channel);
#if (MCL_DEV_ERROR_DETECT == STD_ON)                
            }
#endif            
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
            }
            MCL_ENDVALIDATECHANNELCONFIGCALL(next_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        MCL_ENDVALIDATECHANNELCONFIGCALL(dma_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */     
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */       
} 


/*===============================================================================================*/
/**
 * @brief   This function configures a scatter gather DMA TCD with linking.
 *
 * @details This function is reentrant and configures the specified scatter gather DMA Channel and linking.
 * @param[in]     pTcdAddress          Tcd address used for configuring SGA with linking
 * @param[in]     config_descriptor    Pointer to the channel's descriptor attributes
 * @param[in]     pNext_tcd            Pointer to the TCD address used for scatter gather
 * @param[in]     next_channel         Channel used for link
 *
 * @return void
 *
 * @api
 *
 * @pre Mcl_Dma_Init must be called before.
 * @implements Mcl_DmaConfigScatterGatherLinkedTcd_Activity
 *
 * 
 */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherLinkedTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                          P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                          P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                          VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    valid = Mcl_ValidateGlobalCall(MCL_CONFIG_SCA_LINK_TCD_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(next_channel, MCL_CONFIG_SCA_LINK_TCD_ID_U8))
        {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
#if (MCL_DEV_ERROR_DETECT == STD_ON)
        if ((NULL_PTR == config_descriptor) || (NULL_PTR == pTcdAddress) || (NULL_PTR == pNext_tcd))
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_CONFIG_SCA_LINK_TCD_ID_U8, MCL_E_PARAM_POINTER_U8);
        }
        else
        {
#endif        
            /* Call IPW config scatter gather channel function*/
            Mcl_IPW_DmaConfigScatterGatherLinkedTcd(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, pTcdAddress, config_descriptor, pNext_tcd, next_channel);
#if (MCL_DEV_ERROR_DETECT == STD_ON)            
        }
#endif        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        MCL_ENDVALIDATECHANNELCONFIGCALL(next_channel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */     
#if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
#endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */       
} 


/*===============================================================================================*/
/**
 * @brief   This function sets the priority for the specified DMA Channel
 *
 * @details This function is reentrant and sets the priority for the specified DMA Channel
 * @param[in]     nChannel          Numeric identifier of the DMA channel
 * @param[in]     nPriority         Value for the priority
 *
 * @return void
 *
 * @api
 *
 * @pre
 * @implements Mcl_DmaSetChannelPriority_Activity
 *
 * */
 /** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaSetChannelPriority( VAR(Mcl_ChannelType, AUTOMATIC) nChannel, 
                                                VAR(Mcl_DmaPriorityType, AUTOMATIC) nPriority)
{
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(nChannel, MCL_SET_PRI_ID_U8))
    {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */

        /* Call IPW set channel priority function*/    
        Mcl_IPW_DmaSetChannelPriority(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, nChannel, nPriority);
        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(nChannel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */       
} 

/*===============================================================================================*/
/**
 * @brief   This function starts the specified DMA Channel
 *
 * @details This function is reentrant and starts the specified DMA Channel
 * @param[in]     nChannel          Numeric identifier of the DMA channel
 *
 * @return void
 *
 * @api
 *
 * @pre
 * @implements Mcl_DmaStartChannel_Activity
 *
 * */
 /** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaStartChannel( VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(nChannel, MCL_START_CH_ID_U8))
    {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */

        /* Call IPW start channel function*/
        Mcl_IPW_DmaStartChannel(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, nChannel);
        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(nChannel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
} 

/*===============================================================================================*/
/**
 * @brief   This function checks if the DMA transfer is completed
 *
 * @details This function is reentrant and checks if the DMA transfer is completed
 * @param[in]     nChannel          Numeric identifier of the DMA channel
 *
 * @return boolean
 *
 * @api
 *
 * @pre
 * @implements Mcl_DmaIsTransferCompleted_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(boolean, MCL_CODE) Mcl_DmaIsTransferCompleted( VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
    VAR(boolean, AUTOMATIC) bCompleted = (boolean)FALSE;
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(nChannel, MCL_TRANSF_COMPL_ID_U8))
    {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
    
        bCompleted = Mcl_IPW_DmaIsTransferCompleted(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, nChannel);
        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(nChannel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */
    
    return (bCompleted);

} 

/*===============================================================================================*/
/**
 * @brief   This function checks if a DMA transfer is active
 *
 * @details This function is reentrant and checks if a DMA transfer is active
 * @param[in]     nChannel          Numeric identifier of the DMA channel
 *
 * @return boolean
 *
 * @api
 *
 * @pre
 * @implements Mcl_DmaIsTransferActive_Activity
 *
 * */
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(boolean, MCL_CODE) Mcl_DmaIsTransferActive( VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
    VAR(boolean, AUTOMATIC) bActive = (boolean)FALSE;
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(nChannel, MCL_TRANSF_ACTIVE_ID_U8))
    {
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */   
 
        bActive = Mcl_IPW_DmaIsTransferActive(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, nChannel);
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(nChannel);
#endif /* (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON */   
 
    return (bActive);

} 

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/*===============================================================================================*/
/**
* @brief            This function enables the user notifications.
* @details          The function Mcl_Dma_EnableNotification shall enable the DMA completion
*                   notification or half-completion of a transfer according to notification parameter.
*                   If development error detection for the Mcl module is enabled:
*                   - The Mcl functions shall check the parameter ChannelNumber and raise
*                   development error MCL_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Mcl module is enabled, when a development error
*                   occurs, the corresponding Mcl function shall:
*
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions of
*                           data or hardware registers (this means leave the function without any actions).
*
*                   If the MclDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*
*                   If development error detection for the Mcl module is enabled, if any function
*                   (except Mcl_Init) is called before Mcl_Init has been called, the called function
*                   shall raise development error MCL_E_UNINIT_U8.
*
* @param[in]        ChannelNumber - Dma channel id
* @param[in]        Notification  - notification type to be enabled
*
* @return           void
*
* @api
*
* @implements       Mcl_DmaEnableNotification_Activity
*
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaEnableNotification
(
    VAR(Mcl_ChannelType,          AUTOMATIC)     ChannelNumber,
    VAR(Mcl_DmaTransferNotifType, AUTOMATIC)     Notification
)
{
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_ENABLENOTIFICATION_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

#if ((MCL_VALIDATE_PARAMS == STD_ON) && (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON))
        if((Std_ReturnType)E_OK == Mcl_ValidateParamNotification((*(Mcl_pConfig->pMclDmaConfig->pMclDmaChannelsConfig))[ChannelNumber].pfDmaChannelNotification))
        {
#endif /* (MCL_VALIDATE_PARAMS == STD_ON && MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) */

            /* All validations passed. Here starts the actual
            functional code of the function */
            Mcl_IPW_EnableNotification(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config,
                                        ChannelNumber,
                                       Notification);
#if ((MCL_VALIDATE_PARAMS == STD_ON) && (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON))
        }
#endif /* (MCL_VALIDATE_PARAMS == STD_ON && MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) */
        

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */  
}

/*===============================================================================================*/
/**
* @brief            This function disables the user notifications.
* @details          The function Mcl_Dma_DisableNotification shall disable the DMA completion
*                   notification or half-completion of a transfer.
*                   If development error detection for the Mcl module is enabled:
*                   - The Mcl functions shall check the parameter ChannelNumber and raise
*                   development error MCL_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Mcl module is enabled, when a development error
*                   occurs, the corresponding Mcl function shall:
*
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions of
*                           data or hardware registers (this means leave the function without any actions).
*
*                   If the MclDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*
*                   If development error detection for the Mcl module is enabled, if any function
*                   (except Mcl_Init) is called before Mcl_Init has been called, the called function
*                   shall raise development error MCL_E_UNINIT_U8.
*
* @param[in]        ChannelNumber - Dma channel id
*
* @return           void
*
* @api
*
* @implements       Mcl_DmaDisableNotification_Activity
*
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaDisableNotification(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_DISABLENOTIFICATION_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

            /* All validations passed. Here starts the actual
            functional code of the function */
            Mcl_IPW_DisableNotification(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config,
                                        ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */  
}

/*===============================================================================================*/
/**
* @brief            This function acknowledges the interrupt for the channel passed as parameter.
* @details          The function Mcl_DmaAcknowledgeInterrupt shall acknowledge the interrupt for 
*                   the channel passed as parameter.
*                   If development error detection for the Mcl module is enabled:
*                   - The Mcl functions shall check the parameter ChannelNumber and raise
*                   development error MCL_E_PARAM_CHANNEL if the parameter ChannelNumber is invalid.
*
*                   If development error detection for the Mcl module is enabled, when a development error
*                   occurs, the corresponding Mcl function shall:
*
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions of
*                           data or hardware registers (this means leave the function without any actions).
*
*                   If the MclDevErorDetect switch is enabled, API parameter checking is enabled.
*                   The detailed description of the detected errors can be found in chapter
*
*                   If development error detection for the Mcl module is enabled, if any function
*                   (except Mcl_Init) is called before Mcl_Init has been called, the called function
*                   shall raise development error MCL_E_UNINIT_U8.
*
* @param[in]        ChannelNumber - Channel id
*
* @return           void
*
* @api
*
* @implements       Mcl_DmaAcknowledgeInterrupt_Activity
*
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaAcknowledgeInterrupt(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_ACKNOWLEDGEINTERRUPT_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

            /* All validations passed. Here starts the actual
            functional code of the function */
            Mcl_IPW_DmaAcknowledgeInterrupt(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config,
                                            ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */  
}
#endif /* MCL_DMA_NOTIFICATION_SUPPORTED */

#if (MCL_REPORT_UNEXPECTED_ISR == STD_ON)
/*===============================================================================================*/
/**
* @brief         Mcl_ReportUnexpectedIsrError
* @details       This function is called in order to report an unexpected ISR in case 
*                driver is not configured or corresponding channel has no handler defined
*                   
* @param[in]     None
* @return        None
*
*
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_ReportUnexpectedIsrError
(
    void
)
{
#if  (MCL_FTE == STD_ON)

    #if (MCL_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_PROCESSNOTIFICATION_ID, (uint8)MCL_E_UNEXPECTED_ISR_U8);
    #endif /* (MCL_DEV_ERROR_DETECT == STD_ON)   */

#endif /* (MCL_FTE == STD_ON) */
}
#endif /* (MCL_REPORT_UNEXPECTED_ISR == STD_ON) */

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/*===============================================================================================*/
/**
* @brief         Mcl_Notification
* @details       This function is called from Mcl_IPW.c file in order to forward a 
*                channel notification call from the IP configuration. 
*                   
* @param         Channel - Hw channel for which notification should be called 
* @return        Void
*
* @implements     Mcl_Notification_Activity
*/
FUNC(void, MCL_CODE) Mcl_Notification
(
    VAR(Mcl_ChannelType, AUTOMATIC) Channel
)
{
    VAR(uint8,          AUTOMATIC) u8LogicChannel;
    VAR(Mcl_NotifyType, AUTOMATIC) pfNotify;
    
    /* Check if the driver is initialized */
    if(NULL_PTR != Mcl_pConfig)    
    {
        u8LogicChannel = Mcl_pConfig->pMclDmaConfig->MclDmaHwToLogicChannelMap[Channel];
        /* Check that there is a logic channel associated with the Hw one */
        if (0xFFU != u8LogicChannel) 
        {
            pfNotify = (*(Mcl_pConfig->pMclDmaConfig->pMclDmaChannelsConfig))[u8LogicChannel].pfDmaChannelNotification;
            /* Check that a notification is defined for the associated 
            logic channel */
            if(NULL_PTR != pfNotify)
            {
                pfNotify();   
            }
#if (MCL_REPORT_UNEXPECTED_ISR == STD_ON)
            else
            {
                /* Associated logic channel has no notification handler defined */
                Mcl_ReportUnexpectedIsrError();
            }
#endif /* (MCL_REPORT_UNEXPECTED_ISR == STD_ON) */
        }
#if (MCL_REPORT_UNEXPECTED_ISR == STD_ON)
        else
        {
            /* Hw channel has no associated logic channel */
            Mcl_ReportUnexpectedIsrError();
        }
#endif /* (MCL_REPORT_UNEXPECTED_ISR == STD_ON) */
    }
}
#endif /* (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) */


#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
/*===============================================================================================*/
/**
* @brief         Mcl_ErrorNotification
* @details       This function is called from Mcl_IPW.h file in order to forward a 
*                channel error notification. 
*                   
* @param         Error - The channel error that occurred
* @return        Void
*
*/

FUNC(void, MCL_CODE) Mcl_ErrorNotification(VAR(Mcl_DmaInstanceType, AUTOMATIC) DmaHwInstance, VAR(Mcl_DmaChannelErrorStatusType, AUTOMATIC) Error)
{
    VAR(Mcl_DmaErrNotifyType, AUTOMATIC) pfNotify = (*(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config->pDmaConfigInstance))[DmaHwInstance].pfDmaInstanceErrNotif;

    if (NULL_PTR != pfNotify)
    {
        /** call user function */
        pfNotify(Error);
    }

}
#endif /*(MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON) */

/*================================================================================================*/
/**
* @brief    Mcl_DmaGetChannelTcdAddress.
* @details  This function is used for getting the translation between a Mcl channel and 
*           the adress for the corresponding tcd.
*
* @param[in]   ChannelNumber - Mcl Channel for which notification should be called 
*
* @return   The adress of the TCD for the channel given as parameter.
*
* @api
*
* @implements     Mcl_DmaGetChannelTcdAddress_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA), MCL_CODE) Mcl_DmaGetChannelTcdAddress(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{

    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) returnValue = NULL_PTR;
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_DMAGETCHANNELTCDADDRESS_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

            /* All validations passed. Here starts the actual
            functional code of the function */
            returnValue = Mcl_IPW_DmaGetChannelTcdAddress(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config,
                                        ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     

    return returnValue;
} 


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetSaddr.
* @details  This function is used for setting the SADDR for a TCD based
*           on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    Saddr - Address to set in SADDR.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetSaddr_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetSaddr( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                         VAR(uint32, AUTOMATIC) u32Saddr)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_SADDR_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the SADDR */
        Mcl_IPW_DmaSetSaddr(pTcdAddress, u32Saddr);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
}                                     

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetSoff.
* @details  This function is used for setting the SOFF for a TCD based
*           on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    s16Soff - Source address offset.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetSoff_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetSoff( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                        VAR(sint16, AUTOMATIC) s16Soff)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_SOFF_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the SOFF */
        Mcl_IPW_DmaSetSoff(pTcdAddress, s16Soff);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetDlast.
* @details  This function is used for setting the DLAST for a TCD, when Enable Scatter
*           Gather is not set, based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    s32Dlast - Adjustment value added to the destination address at the completion of the major iteration count.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetDlast_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetDlast( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                         VAR(sint32, AUTOMATIC) s32Dlast)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_DLAST_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the DLAST */
        Mcl_IPW_DmaSetDlast(pTcdAddress, s32Dlast);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
}                                        

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetSga.
* @details  This function is used for setting the SGA for a TCD, when Enable Scatter
*           Gather is set, based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    u32Sga - This address points to the beginning of a region containing the next TCD to be loaded into this channel.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetSga_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetSga( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                       VAR(uint32, AUTOMATIC) u32Sga)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_SGA_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the SGA */
        Mcl_IPW_DmaSetSga(pTcdAddress, u32Sga);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
} 

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetDaddr.
* @details  This function is used for setting the DADDR for a TCD based
*           on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    u32Daddr - Destination Address.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetDaddr_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetDaddr( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                         VAR(uint32, AUTOMATIC) u32Daddr)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_DADDR_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the DADDR */
        Mcl_IPW_DmaSetDaddr(pTcdAddress, u32Daddr);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
}                                     
                                     

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetDoff.
* @details  This function is used for setting the Destination offset for a TCD based
*           on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    s16Doff - Destination Address Offset.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetDoff_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetDoff( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                        VAR(sint16, AUTOMATIC) s16Doff)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_DOFF_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the DOFF */
        Mcl_IPW_DmaSetDoff(pTcdAddress, s16Doff);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif    
}                                     


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetIterCount.
* @details  This function is used for setting  the major iteration count (CITER and BITER fields)     
*           for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    u16Iter - Value for major iteration count.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetIterCount_Activity    
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetIterCount( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                             VAR(uint16, AUTOMATIC) u16Iter)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_ITER_COUNT_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the CITER */
        Mcl_IPW_DmaSetCiter(pTcdAddress, u16Iter);
        
       /* Call the IPW function for setting the BITER with the same value as CITER*/
        Mcl_IPW_DmaSetBiter(pTcdAddress, u16Iter);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif     
} 


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetLinkAndIterCount.
* @details  This function is used for enabling channel-to-channel linking (ELINK field set),
*           setting  the linked channel number (LINKCH field) and the major iteration count 
*           (CITER & BITER fields) for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    LinkCh - Linked DMA channel number.
* @param[in]    u16Iter - Is the value for major iteration count.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetLinkAndIterCount_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetLinkAndIterCount( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                    VAR(Mcl_ChannelType, AUTOMATIC) LinkCh,
                                                    VAR(uint16, AUTOMATIC) u16Iter)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_LINK_ITER_COUNT_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif    
        /* Call the IPW function for setting the ELINK, LINKCH, BITER and CITER */
        Mcl_IPW_DmaSetLinkAndIterCount(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, pTcdAddress, LinkCh, u16Iter);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif     
}                                                            


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetSModuloAndSize.
* @details  This function is used for setting the SMOD and SSIZE for a TCD based
*           on the address of the TCD. DMOD and DSIZE will be preserved.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    u8SModulo - Source Address Modulo.
* @param[in]    SSize - Source data transfer size.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetSModuloAndSize_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetSModuloAndSize( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                  VAR(uint8, AUTOMATIC) u8SModulo,
                                                  VAR(Mcl_DmaSizeType, AUTOMATIC) SSize)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_SMOD_SIZE_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */     
        /* Call the IPW function for setting the SMOD and SSIZE */
        Mcl_IPW_DmaSetSModSize(pTcdAddress, u8SModulo, SSize);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */     
}                                        
       

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetDModuloAndSize.
* @details  This function is used for setting the DMOD and DSIZE for a TCD based
*           on the address of the TCD. SMOD and SSIZE will be preserved.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    u8DModulo - Destination Address Modulo.
* @param[in]    DSize - Destination data transfer size.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetDModuloAndSize_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetDModuloAndSize( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                  VAR(uint8, AUTOMATIC) u8DModulo,
                                                  VAR(Mcl_DmaSizeType, AUTOMATIC) DSize)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_DMOD_SIZE_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */      
        /* Call the IPW function for setting the DMOD and DSIZE */
        Mcl_IPW_DmaSetDModSize(pTcdAddress, u8DModulo, DSize);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */      
}
       

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetMinorLoop.
* @details  This function is used for setting the Smloe, Dmloe, Mloff and NBytes 
*           for minor loop offset when minor loop is enabled, for a TCD based on the address of the TCD.
*           If offset is disabled (Smloe = FALSE and Dmloe = FALSE), the values set will be Smloe, Dmloe
*           and NBytes for the rest of the register. If offset is enabled (Smloe = TRUE or Dmloe = true)
*           the values set will be Smloe, Dmloe, Mloff, Nbytes.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    bSmloe - Source minor loop offset enable.
* @param[in]    bDmloe - Destination minor loop offset enable.
* @param[in]    s32Mloff - Offset applied to the source or destination address.
* @param[in]    u32NBytes - Minor Byte Transfer Count.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetMinorLoop_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetMinorLoop( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                             VAR(boolean, AUTOMATIC) bSmloe,
                                             VAR(boolean, AUTOMATIC) bDmloe,
                                             VAR(sint32, AUTOMATIC) s32Mloff,
                                             VAR(uint32, AUTOMATIC) u32NBytes) 
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)    
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_MINOR_LOOP_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
        if (((boolean)TRUE != bSmloe) && ((boolean)TRUE !=bDmloe))
        {
            /* No offset enabled, call IPW function that sets Minor Byte Transfer Count */
            Mcl_IPW_DmaSetMlnoNBytes(pTcdAddress, u32NBytes);
        }
        else
        {
            /* Offset enabled, call IPW function that sets Smloe, Dmloe, Mloff and NBytes */
            Mcl_IPW_DmaSetMloffen(pTcdAddress, bSmloe, bDmloe, s32Mloff, u32NBytes);
        }
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
}                                     


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetSlast.
* @details  This function is used for setting the SLAST for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    s32Slast - Last Source Address Adjustment.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetSlast_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetSlast( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                         VAR(sint32, AUTOMATIC) s32Slast)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_SLAST_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */      
        /* Call the IPW function for setting the SLAST NBytes */
        Mcl_IPW_DmaSetSlast(pTcdAddress, s32Slast);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */      
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetFlags.
* @details  This function is used for setting the Channel Done, Channel Active, 
*           Enable channel-to-channel linking on major loop complete,
*           Enable Scatter Gather Processing, Disable Request, 
*           Enable an interrupt when major counter is half complete,
*           Enable an interrupt when major iteration count completes,
*           Channel Start flags for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    u8Flags - Flags to be set.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetFlags_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetFlags( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                         VAR(uint8, AUTOMATIC) u8Flags)
{
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_FLAGS_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */     
        /* Call the IPW function for setting the Flags in CSR */
        Mcl_IPW_DmaSetFlags(pTcdAddress, u8Flags);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdGetFlags.
* @details  This function is used for getting the Channel Done, Channel Active, 
*           Enable channel-to-channel linking on major loop complete,
*           Enable Scatter Gather Processing, Disable Request, 
*           Enable an interrupt when major counter is half complete,
*           Enable an interrupt when major iteration count completes,
*           Channel Start flags for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
*
* @return    Value for all the flags. 
*
* @api
*
* @implements     Mcl_DmaTcdGetFlags_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(uint8, MCL_CODE) Mcl_DmaTcdGetFlags( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress)
{
    VAR(uint8, AUTOMATIC) u8returnValue = 0U;

#if (MCL_DEV_ERROR_DETECT == STD_ON)    
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_GET_FLAGS_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
        /* Call the IPW function for getting the Flags in CSR */
        u8returnValue = Mcl_IPW_DmaGetFlags(pTcdAddress);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */ 
    return u8returnValue;
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdClearIntMaj.
* @details  This function disables the interrupts when major iteration count completes
*           for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdClearIntMaj_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdClearIntMaj( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress)
{

#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_CLEAR_INT_MAJ_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
        /* Call the IPW function for disabling the interupts  when major iteration count completes */
        Mcl_IPW_DmaClearIntMaj(pTcdAddress);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdSetIntMaj.
* @details  This function enables the interrupts when major iteration count completes
*           for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdSetIntMaj_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdSetIntMaj( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress)
{

#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_SET_INT_MAJ_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */
    
        /* Call the IPW function for enabling the interupts  when major iteration count completes */
        Mcl_IPW_DmaSetIntMaj(pTcdAddress);
        
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdGetIntMaj.
* @details  This function returns TRUE if the interrupts were enabled and FALSE if interrupts were 
*           disabled for the corresponding channel.
*
* @param[in]   ChannelNumber - Mcl Channel for getting interrupt state.
*
* @return boolean
*
* @api
*
* @implements     Mcl_DmaTcdGetIntMaj_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(boolean, MCL_CODE) Mcl_DmaTcdGetIntMaj(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
    VAR(boolean,AUTOMATIC) bReturnValue = (boolean)FALSE;
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_DMATCDGETINTMAJ_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

            /* All validations passed. Here starts the actual
            functional code of the function */
            bReturnValue = Mcl_IPW_DmaTcdGetIntMaj(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config,
                                        ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     

    return bReturnValue;
}
       
       
/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdClearDone.
* @details  This function is used for setting the Channel Done, Channel Active, 
*           Enable channel-to-channel linking on major loop complete,
*           Enable Scatter Gather Processing, Disable Request, 
*           Enable an interrupt when major counter is half complete,
*           Enable an interrupt when major iteration count completes,
*           Channel Start flags for a TCD based on the address of the TCD.
*
* @param[in]    nChannel - Channel number for clearing DONE bit.
*
* @return
*
* @api
*
* @implements     Mcl_DmaTcdClearDone_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaTcdClearDone(VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(nChannel, MCL_DMACLEARDONE_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        /* Call the IPW function for setting the Flags in CSR */
        Mcl_IPW_DmaClearDone(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, nChannel);
        
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(nChannel);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */         
}       
/*================================================================================================*/

/**
* @brief    Mcl_DmaTcdGetIterCount.
* @details  This function is used for getting the CITER
*           for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
*
* @return   Value for CITER.
*
* @api
*
* @implements     Mcl_DmaTcdGetIterCount_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(uint16, MCL_CODE) Mcl_DmaTcdGetIterCount(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress)
{
    VAR(uint16, AUTOMATIC) u16returnValue = 0U;
 
#if (MCL_DEV_ERROR_DETECT == STD_ON)  
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_GET_ITER_COUNT_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    

        /* Call the IPW function for getting the CITER field */
        u16returnValue = Mcl_IPW_DmaGetCiter(pTcdAddress);
        
#if (MCL_DEV_ERROR_DETECT == STD_ON)          
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */      
    
    return u16returnValue;
}

/*================================================================================================*/

/**
* @brief    Mcl_DmaGetStartIterCount.
* @details  This function is used for getting the staring iteration count for a specified channel.
*
* @param[in]   ChannelNumber - Mcl Channel.
*
* @return   iteration number
*
* @api
* @implements     Mcl_DmaGetStartIterCount_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(uint16, MCL_CODE) Mcl_DmaGetStartIterCount(VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber)
{
     VAR(uint16, AUTOMATIC) u16returnValue = 0U;
     
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_GET_STRT_ITER_CH_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        /* All validations passed. Here starts the actual
        functional code of the function */
      
        /* Call the IPW functionss for getting the CITER and BITER*/
        u16returnValue =(uint16)Mcl_IPW_DmaGetChBiter((Mcl_DmaChannelType)(*(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config->pChannelsConfig))[ChannelNumber].Dma_Channel);
        
                     
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */   

    return u16returnValue;
}

/**
* @brief    Mcl_DmaGetCrtIterCount.
* @details  This function is used for geting the current iteration count for a specified channel.
*
* @param[in]   ChannelNumber - Mcl Channel.
*
* @return   iteration number
*
* @api
* @implements     Mcl_DmaGetCrtIterCount_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(uint16, MCL_CODE) Mcl_DmaGetCrtIterCount(VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber)
{
     VAR(uint16, AUTOMATIC) u16returnValue = 0U;
     
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_GET_CRT_ITER_CH_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        /* All validations passed. Here starts the actual
        functional code of the function */
      
        /* Call the IPW functionss for getting the CITER and BITER*/
        u16returnValue =(uint16)Mcl_IPW_DmaGetChCiter((Mcl_DmaChannelType)(*(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config->pChannelsConfig))[ChannelNumber].Dma_Channel);
                    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */   

    return u16returnValue;

}

/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdGetSaddr.
* @details  This function is used for getting the SADDR
*           for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
*
* @return   Value for SADDR.
*
* @api
*
* @implements     Mcl_DmaTcdGetSaddr_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(uint32, MCL_CODE) Mcl_DmaTcdGetSaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress)
{
    VAR(uint32, AUTOMATIC) u32returnValue = 0U;
 
#if (MCL_DEV_ERROR_DETECT == STD_ON) 
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_GET_SADDR_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */    
        /* Call the IPW function for getting the SADDR field */
        u32returnValue = Mcl_IPW_DmaGetSaddr(pTcdAddress);
#if (MCL_DEV_ERROR_DETECT == STD_ON)         
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */
    
    return u32returnValue;
}


/*================================================================================================*/
/**
* @brief    Mcl_DmaTcdGetDaddr.
* @details  This function is used for getting the DADDR
*           for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
*
* @return   Value for DADDR.
*
* @api
*
* @implements     Mcl_DmaTcdGetDaddr_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(uint32, MCL_CODE) Mcl_DmaTcdGetDaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress)
{
 
    VAR(uint32, AUTOMATIC) u32returnValue = 0U;
 
#if (MCL_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pTcdAddress)
    {
        (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_TCD_GET_DADDR_ID_U8, MCL_E_PARAM_POINTER_U8);
    }
    else
    {
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */
        /* Call the IPW function for getting the DADDR field */
        u32returnValue = Mcl_IPW_DmaGetDaddr(pTcdAddress);
#if (MCL_DEV_ERROR_DETECT == STD_ON)        
    }
#endif /* MCL_DEV_ERROR_DETECT == STD_ON */     
    
    return u32returnValue;
}    


/*================================================================================================*/
/**
* @brief    Mcl_DmaGetInterruptRequest.
* @details  This function is used for getting the interrupt request for the 
*           specified channel
*
* @param[in]   ChannelNumber - Mcl Channel for getting interrupt state.
*
* @return   boolean
*
* @api
*
* @implements     Mcl_DmaGetInterruptRequest_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(boolean, MCL_CODE) Mcl_DmaGetInterruptRequest(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
    VAR(boolean,AUTOMATIC) bReturnValue = (boolean)FALSE;
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_DMAGETINTERRUPTREQUEST_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

            /* All validations passed. Here starts the actual
            functional code of the function */
            bReturnValue = Mcl_IPW_DmaGetInterruptRequest(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config,
                                                         ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     

    return bReturnValue;
}   

/*================================================================================================*/
/**
* @brief    Mcl_DmaGetPhysicalChannel.
* @details  This function is used for getting the phyisical DMA channel for a given
*           Mcl channel.
*
* @param[in]   ChannelNumber - Mcl Channel for getting the physical DMA channel.
*
* @return
*
* @api
*
* @implements     Mcl_DmaGetPhysicalChannel_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Mcl_DmaChannelType, MCL_CODE) Mcl_DmaGetPhysicalChannel(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
    VAR(Mcl_DmaChannelType,AUTOMATIC) returnChannel = (Mcl_DmaChannelType)255;
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_DMAGETPHYSICALCHANNEL_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

            /* All validations passed. Here starts the actual
            functional code of the function */
            returnChannel = (*(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config->pChannelsConfig))[ChannelNumber].Dma_Channel;

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     

    return returnChannel;
}   
  
/*================================================================================================*/
/**
* @brief    Mcl_DmaEnableHwRequest.
* @details  This function is used for enabling the hardware request for a given
*           Mcl channel.
*
* @param[in]   ChannelNumber - Mcl Channel for hardware request enabling.
*
* @return   Mcl_DmaChannelType
*
* @api
* @implements     Mcl_DmaEnableHwRequest_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaEnableHwRequest(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_ENABLE_HW_REQ_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        /* All validations passed. Here starts the actual
        functional code of the function */
        
        /* Call the IPW function for hardware request enable */
        Mcl_IPW_DmaEnableHwRequest(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     

}   

/*================================================================================================*/
/**
* @brief    Mcl_DmaDisableHwRequest.
* @details  This function is used for disabling the hardware request for a given
*           Mcl channel.
*
* @param[in]   ChannelNumber - Mcl Channel for hardware request disabling.
*
* @return   Mcl_DmaChannelType
*
* @api
* @implements     Mcl_DmaDisableHwRequest_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaDisableHwRequest(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_DISABLE_HW_REQ_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        /* All validations passed. Here starts the actual
        functional code of the function */
        
        /* Call the IPW function for hardware request enable */
        Mcl_IPW_DmaDisableHwRequest(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, ChannelNumber);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     

}  
/*================================================================================================*/
/**
* @brief    Mcl_DmaUpdateIterCount.
* @details  This function is used for updating the iteration count bits.
*
* @param[in]   ChannelNumber - Mcl Channel for updating the iteration count.
*              u16Iter - iteration number
*
* @return   void
*
* @api
* @implements     Mcl_DmaUpdateIterCount_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaUpdateIterCount( VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber ,
                                             VAR(uint16, AUTOMATIC) u16Iter)
{
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA)tcd_address;
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_UPDATE_ITER_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */
       
       tcd_address = Mcl_IPW_DmaGetChannelTcdAddress(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, ChannelNumber);
       /* All validations passed. Here starts the actual
       functional code of the function */

       /* Call the IPW function for setting the CITER */
       Mcl_IPW_DmaSetCiter(tcd_address, u16Iter);
       
       /* Call the IPW function for setting the BITER with the same value as CITER */
       Mcl_IPW_DmaSetBiter(tcd_address, u16Iter);

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */     
}

/*================================================================================================*/

/**
* @brief    Mcl_UpdateDmaDestAddress.
* @details  This function is used for updating the destination address.
*
* @param[in]   ChannelNumber - Mcl Channel.
*              daddr - Destination address
*
* @return   void
*
* @api
* @implements     Mcl_DmaUpdateDestAddress_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaUpdateDestAddress(VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber,
                                                VAR(uint32, AUTOMATIC) daddr)
{
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(ChannelNumber, MCL_UPDATE_DEST_CH_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        /* All validations passed. Here starts the actual
        functional code of the function */
     
        /* Call the IPW function for updating the destination addr */
 

        Mcl_IPW_DmaUpdateDestAddress((uint32)(*(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config->pChannelsConfig))[ChannelNumber].Dma_Channel, (uint32)daddr);
      
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */ 
}
#if (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON)
/**
* @brief    Mcl_DmaGetGlobalErrorStatus
* @details  This function is used for getting the DMA instance global error status provided by hardware.
*
* @param[in]   dmaInstance - DMA instance identifier.
*              Mcl_DmaGlobalErrorStatus - pointer to the error information
* @param[out]  Mcl_DmaGlobalErrorStatus - pointer to the error information
* @return   void
*
* @api
* @implements     Mcl_DmaGetGlobalErrorStatus_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_DmaGetGlobalErrorStatus
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) dmaInstance,
    P2VAR(Mcl_DmaGlobalErrorStatusType, AUTOMATIC, MCL_APPL_DATA) dmaGlobalErrorStatus
)
{
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    /* validate globall call of the function */
    valid = Mcl_ValidateGlobalCall(MCL_GET_GLOBAL_ERR_STATUS_ID_U8);
    
    if ((Std_ReturnType)E_OK == valid)
    {
    #endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
    
    #if (MCL_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR == dmaGlobalErrorStatus)
        {
            /* report to DET in pointer is NULL */
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_GET_GLOBAL_ERR_STATUS_ID_U8, MCL_E_PARAM_CONFIG_U8);
        }
        else
    #endif    
        {
    #if (MCL_DMA_NB_CONTROLLERS == 0x02U)        
            if ((DMA_INSTANCE0 != dmaInstance) && (DMA_INSTANCE1 != dmaInstance))
    #else
            if (DMA_INSTANCE0 != dmaInstance)      
    #endif       
            {
    #if (MCL_DEV_ERROR_DETECT == STD_ON)
                /* report to DET in DMA instance parameter is incorrect */
                (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, MCL_GET_GLOBAL_ERR_STATUS_ID_U8, MCL_E_PARAM_CONFIG_U8);
    #endif             
            }
            else
            {
                /* call lower layer API to get global error status */
                Mcl_IPW_DmaGetGlobalErrorStatus(dmaInstance, dmaGlobalErrorStatus);
                 
                /* perform range check and transform from hardware to logical */ 
                if (MCL_DMA_NO_CHANNEL_U16 != dmaGlobalErrorStatus->erroneousChannel)     
                {
                    if (dmaGlobalErrorStatus->erroneousChannel < MCL_DMA_NB_CHANNELS)
                    {
                        /* transform from hardware channel to logical channel */
                        dmaGlobalErrorStatus->erroneousChannel = Mcl_pConfig->pMclDmaConfig->MclDmaHwToLogicChannelMap[dmaGlobalErrorStatus->erroneousChannel];
                    }
                }
            }
        }
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
    #endif /* (MCL_VALIDATE_GLOBAL_CALL == STD_ON */
}
#endif

#if (MCL_DMA_GET_CH_ERR_STATUS_API == STD_ON)
/**
* @brief       Mcl_DmaGetChannelErrorStatus
* @details     This function is used for getting the error staus for a specified logical channel
*
* @param[in]   logicalChannel - MCL logical channel.
*              
* @param[out] 
* @return      Mcl_DmaChannelErrorStatusType - provides the error information for a specified logical channel
*
* @api
* @implements     Mcl_DmaGetChannelErrorStatus_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Mcl_DmaChannelErrorStatusType, MCL_CODE) Mcl_DmaGetChannelErrorStatus(VAR(Mcl_ChannelType, AUTOMATIC) logicalChannel)
{
     Mcl_DmaChannelErrorStatusType errorStatus = MCL_DMA_NO_ERROR;

#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    if((Std_ReturnType)E_OK == Mcl_ValidateChannelConfigCall(logicalChannel, MCL_GET_CH_ERR_STATUS_ID_U8))
    {
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */

        errorStatus = Mcl_IPW_DmaGetChannelErrorStatus(Mcl_pConfig->pMclDmaConfig->pMclDmaHwIpsConfig->pDma_Config, logicalChannel);
    
#if (MCL_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    MCL_ENDVALIDATECHANNELCONFIGCALL(ChannelNumber);   
#endif /* MCL_VALIDATE_CALL_AND_CHANNEL */ 

    return errorStatus;
}
#endif

#endif /* (MCL_ENABLE_DMA == STD_ON) */
#if (MCL_ENABLE_TRGMUX == STD_ON)
/**
* @brief       Mcl_TrgMuxConfigInput
* @details     This function is used for configuring a trigger in a TRGMUX register
*
* @param[in]   registerIndex - TRGMUX register index.
* @param[in]   selNumber - number of the input configured(sel0,sel1,sel2,sel3).
* @param[in]   trigger - trigger to be configured.
*              
* @param[out] 
* @return      void
*
* @api
* @implements     Mcl_TrgMuxConfigInput_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_TrgMuxConfigInput
( 
    VAR(Mcl_TrgMuxRegisterIndexType, AUTOMATIC) registerIndex,  
    VAR(Mcl_TrgMuxSelectionNrType, AUTOMATIC) selNumber,
    VAR(Mcl_TrgMuxTriggerType, AUTOMATIC) trigger
)
{
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    /* validate that API is called after MCL was initialized */
    valid = Mcl_ValidateGlobalCall(MCL_TRGMUX_CONFIG_ID_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
    #endif
        #if (MCL_DEV_ERROR_DETECT == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateTrgMuxConfigCall(registerIndex, selNumber, trigger))
        {
        #endif        
            /* Call IPW config channel function*/
            /* @violates @ref Mcl_c_7 Violates MISRA 2004 Rule 11.1 */
            /** @violates @ref Mcl_c_8 Violates MISRA 2004 Rule 11.3*/
            /** @violates @ref Mcl_c_12 The comma operator shall not be used. */
            Mcl_IPW_TrgMuxConfigInput(registerIndex, selNumber, trigger);     
        #if (MCL_DEV_ERROR_DETECT == STD_ON)
        }
        #endif
    /* end validation */
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
    #endif  
}   
/**
* @brief       Mcl_TrgMuxEnableLock
* @details     This function is used for enabling lock of a TRGMUX register
*
* @param[in]   registerIndex - TRGMUX register index.
*              
* @param[out] 
* @return      void 
*
* @api
* @implements     Mcl_TrgMuxEnableLock_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(void, MCL_CODE) Mcl_TrgMuxEnableLock
( 
    VAR(Mcl_TrgMuxRegisterIndexType, AUTOMATIC) registerIndex
)
{
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    /* validate that API is called after MCL was initialized */
    valid = Mcl_ValidateGlobalCall(MCL_TRGMUX_CONFIG_LOCK_U8);
    if ((Std_ReturnType)E_OK == valid)
    {
    #endif
        #if (MCL_DEV_ERROR_DETECT == STD_ON)
        if((Std_ReturnType)E_OK == Mcl_ValidateTrgMuxConfigLockCall(registerIndex))
        {
        #endif        
            /* Call IPW config channel function*/
            /* @violates @ref Mcl_c_7 Violates MISRA 2004 Rule 11.1 */
            /** @violates @ref Mcl_c_8 Violates MISRA 2004 Rule 11.3*/
            /** @violates @ref Mcl_c_12 The comma operator shall not be used. */
            Mcl_IPW_TrgMuxEnableLock(registerIndex);      
        #if (MCL_DEV_ERROR_DETECT == STD_ON)
        }
        #endif
    /* end validation */
    #if (MCL_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    MCL_ENDVALIDATEGLOBALCALL();
    #endif  
}  
#endif /* #ifdef MCL_ENABLE_TRGMUX */
/*=================================== CACHE API ===================================================*/
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
/**
* @brief        Mcl_CacheEnable
* @details      This function is used for enabling the specified cache instance
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api  
* @implements     Mcl_CacheEnable_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheEnable(Mcl_CacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheEnable(cacheInstance);
    
    return retVal;
} 
/**
* @brief        Mcl_CacheDisable
* @details      This function is used for disabling the specified cache instance
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api  
* @implements     Mcl_CacheDisable_Activity
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheDisable(Mcl_CacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheDisable(cacheInstance);
    
    return retVal;
}   
/**
* @brief        Mcl_CacheFlush
* @details      This function is used for flushing the specified cache instance 
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api  
* @implements Mcl_CacheFlush_Activity 
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheFlush(Mcl_CacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheFlush(cacheInstance);
    
    return retVal;
}
/**
* @brief        Mcl_CacheInvalidate
* @details      This function is used for invalidating the specified cache instance
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api    
* @implements Mcl_CacheInvalidate_Activity 
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheInvalidate(Mcl_CacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheInvalidate(cacheInstance);
    
    return retVal;
}
/**
* @brief        Mcl_CacheClear
* @details      This function is used for clearing the specified cache instance
*
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api
* @implements Mcl_CacheClear_Activity 
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheClear(Mcl_CacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheClear(cacheInstance);
    
    return retVal;
}

/**
* @brief        Mcl_CacheFlushMultiLines
* @details      This function flushes multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               flushes the lines which contain the specified address range.
*               Flush cache - flushes a cache entry if it is valid and modified, then clears the
*               modify bit. If it is not modified or not valid, no change is made.
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches).
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api 
* @implements Mcl_CacheFlushMultiLines_Activity   
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheFlushMultiLines(Mcl_CacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheFlushMultiLines(cacheInstance, u32PhyAddr, u32Length);
    
    return retVal;
}

/**
* @brief        Mcl_CacheInvalidateMultiLines
* @details      This function invalidates multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               invalidates the lines which contain the specified address range.
*               Invalidate cache - Invalidates a cache entry, by clearing the
*               valid and modify bits, irrespective of their state.
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches).
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api    
* @implements Mcl_CacheInvalidateMultiLines_Activity 
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheInvalidateMultiLines(Mcl_CacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheInvalidateMultiLines(cacheInstance, u32PhyAddr, u32Length);
    
    return retVal;
}

/**
* @brief        Mcl_CacheClearMultiLines
* @details      This function clears multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               clears the lines which contain the specified address range.
*               Clear cache - flushes a cache entry if it is valid and modified, then clears the
*               valid and modify bits. If it is not modified, only clears the valid bit.
* @param[in]    cacheInstance   The cache instance for which the function is called(PC, PS or both caches).
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api   
* @implements Mcl_CacheClearMultiLines_Activity  
*/
/** @violates @ref Mcl_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheClearMultiLines(Mcl_CacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
    retVal = Mcl_IPW_CacheClearMultiLines(cacheInstance, u32PhyAddr, u32Length);
    
    return retVal;
}

#endif /* #if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)  */

#define MCL_STOP_SEC_CODE
/*
 * @violates @ref Mcl_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 * and comments before  "#include".
 */
/*
 * @violates @ref Mcl_c_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif


/* End of file */
/** @} */

