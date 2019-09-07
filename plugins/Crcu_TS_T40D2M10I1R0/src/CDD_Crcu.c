/**
*     @file        CDD_Crcu.c
*
*     @version     1.0.1
*
*     @brief       AUTOSAR Crcu driver source file.
*     @details     Crcu driver source file, containing the API specification and other variables
*                  and functions that are exported by the Crcu driver.
*
*     @addtogroup  CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : CRCV2
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
* @section Crcu_c_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_c_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported forexternal identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section Crcu_c_REF_3
*          Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to 
*          a function-like macro.
*          Function like macros are used to reduce code complexity.
*
* @section Crcu_c_REF_4
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. MemMap.h is included after each section define
*          in order to set the current memory section as defined by AUTOSAR.
*
* @section Crcu_c_REF_5
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section Crcu_c_REF_6
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope 
*          if they are only accessed from within a single function. 
*          These objects are used in various parts of the code.
*
* @section Crcu_c_REF_7
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
*          a pointer to a function and any type other than an integral type. 
*          There is no conversion of a function pointer to a non integral type at the line where the violation is reported.
*
* @section Crcu_c_REF_8
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
*          The cast of the pointer to the integral type is used to check the alignement of the pointer.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*==================================================================================================
 *                                          INCLUDE FILES
 *  1) system and project includes
 *  2) needed interfaces from external units
 *  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crcu.h"
#include "Crcu_Ipw.h"
#include "Mcal.h"

#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    #include "Det.h"
    #include "SchM_Crcu.h"
#endif

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_VENDOR_ID_C                        43
/** @violates @ref Crcu_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_AR_RELEASE_MAJOR_VERSION_C         4
/** @violates @ref Crcu_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_AR_RELEASE_MINOR_VERSION_C         2
/** @violates @ref Crcu_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_AR_RELEASE_REVISION_VERSION_C      2
#define CRCU_SW_MAJOR_VERSION_C                 1
#define CRCU_SW_MINOR_VERSION_C                 0
#define CRCU_SW_PATCH_VERSION_C                 1

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if CDD_Crcu.c source file and Crcu.h header file are of the same vendor */
#if (CRCU_VENDOR_ID_C != CRCU_VENDOR_ID)
    #error "CDD_Crcu.c and Crcu.h have different vendor IDs"
#endif
/* Check if CDD_Crcu.c source file and Crcu.h header file are of the same Autosar version */
#if ((CRCU_AR_RELEASE_MAJOR_VERSION_C    != CRCU_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_AR_RELEASE_MINOR_VERSION_C    != CRCU_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_AR_RELEASE_REVISION_VERSION_C != CRCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crcu.c and Crcu.h are different"
#endif
/* Check if CDD_Crcu.c source file and Crcu.h header file are of the same Software version */
#if ((CRCU_SW_MAJOR_VERSION_C != CRCU_SW_MAJOR_VERSION) || \
     (CRCU_SW_MINOR_VERSION_C != CRCU_SW_MINOR_VERSION) || \
     (CRCU_SW_PATCH_VERSION_C != CRCU_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crcu.c and Crcu.h are different"
#endif

/* Check if CDD_Crcu.c source file and Crcu_Ipw.h header file are of the same vendor */
#if (CRCU_VENDOR_ID_C != CRCU_IPW_VENDOR_ID)
    #error "CDD_Crcu.c and Crcu_Ipw.h have different vendor IDs"
#endif
/* Check if CDD_Crcu.c source file and Crcu_Ipw.h header file are of the same Autosar version */
#if ((CRCU_AR_RELEASE_MAJOR_VERSION_C    != CRCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_AR_RELEASE_MINOR_VERSION_C    != CRCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_AR_RELEASE_REVISION_VERSION_C != CRCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crcu.c and Crcu_Ipw.h are different"
#endif
/* Check if CDD_Crcu.c source file and Crcu_Ipw.h header file are of the same Software version */
#if ((CRCU_SW_MAJOR_VERSION_C != CRCU_IPW_SW_MAJOR_VERSION) || \
     (CRCU_SW_MINOR_VERSION_C != CRCU_IPW_SW_MINOR_VERSION) || \
     (CRCU_SW_PATCH_VERSION_C != CRCU_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crcu.c and Crcu_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((CRCU_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CRCU_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_Crcu.c source file and Mcal.h are different"
    #endif
#endif

/* Check if  CDD_Crcu.c source file and Det.h header file are of the same Autosar version */
#if(STD_ON == CRCU_DEV_ERROR_DETECT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((CRCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CRCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_Crcu.c and Det.h are different"
        #endif

        #if ((CRCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (CRCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_Crcu.c and Det.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
 * @brief       Enumerator that defines CRCU channel states.
 * @details     Provides CRCU channel state
 **/
typedef enum
{
    CRCU_CH_STATE_IDLE = 0U,
    CRCU_CH_STATE_BUSY
}Crcu_ChannelStateType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/* Internal identifiers for the Crcu functions working on channels */
#define CRCU_ID_CHANNEL_FUNC_SET_CONFIG          0U
#define CRCU_ID_CHANNEL_FUNC_SET_SEED            1U
#define CRCU_ID_CHANNEL_FUNC_SYNC_CALCULATE_CRC  2U
#define CRCU_ID_CHANNEL_FUNC_ASYNC_CALCULATE_CRC 3U
#define CRCU_ID_CHANNEL_FUNC_GET_CRC             4U
/* Max number of Crcu functions working on channels */
#define CRCU_ID_CHANNEL_FUNC_MAX                 5U

#if (STD_OFF == CRCU_DEV_ERROR_DETECT)
    /** @violates @ref Crcu_c_REF_3 A function should be used in preference to 
    a function-like macro. */
    #define Crcu_SetChannelStateIdle(Crcu_ChannelId)
#endif

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/
#if(STD_ON == CRCU_DEV_ERROR_DETECT)
    
#define CRCU_START_SEC_CONST_8
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/** @violates @ref Crcu_c_REF_6 Objects shall be defined at block scope if they are only accessed from within a single function. */
static CONST(uint8, CRCU_CONST) Crcu_au8ChannelFuncServiceId[CRCU_ID_CHANNEL_FUNC_MAX] =
{
    CRCU_SETCHANNELCONFIG_ID,
    CRCU_SETCHANNELSEED_ID,
    CRCU_SYNCCALCULATECHANNELCRC_ID,
    CRCU_ASYNCCALCULATECHANNELCRC_ID,
    CRCU_GETCHANNELCRC_ID
};

#define CRCU_STOP_SEC_CONST_8
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */

/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/
#define CRCU_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/* Pointer to the currently used configuration. Null if Init function was not yet called */
static P2CONST(Crcu_ConfigType, CRCU_VAR, CRCU_APPL_CONST) Crcu_pConfig = NULL_PTR;

#define CRCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"


#if(STD_ON == CRCU_DEV_ERROR_DETECT)

#define CRCU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/* Array of variables storing the state of each channel */
static VAR(Crcu_ChannelStateType, CRCU_VAR) Crcu_aeChannelState[CRCU_MAX_NUM_CRC_CHANNELS];

#define CRCU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/
#define CRCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before "#include".*/
#include "Crcu_MemMap.h"

#if (STD_ON == CRCU_PRECOMPILE_SUPPORT)
    /** @violates @ref Crcu_c_REF_6 Objects shall be defined at block scope if they are only accessed from within a single function. */
    extern CONST(Crcu_ConfigType, CRCU_CONST) Crcu_PBCfgVariantPredefined;
#endif

#define CRCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before "#include".*/
#include "Crcu_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CRCU_START_SEC_CODE
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

#if (STD_ON == CRCU_DEV_ERROR_DETECT)
LOCAL_INLINE FUNC(boolean, CRCU_CODE) Crcu_ValidateDriverInitAndChannel
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId,
    VAR(uint8,              AUTOMATIC) u8ChannelFuncId
);

LOCAL_INLINE FUNC(boolean, CRCU_CODE) Crcu_ValidateChannelStateAndSetBusyIfIdle
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId,
    VAR(uint8,              AUTOMATIC) u8ChannelFuncId
);

LOCAL_INLINE FUNC(void, CRCU_CODE) Crcu_SetChannelStateIdle
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId
);

#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */

#if (STD_ON == CRCU_DMA_USED)
static FUNC(void, CRCU_CODE) Crcu_ProcessDmaTransferComplete
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) Crcu_ChannelId
);
#endif /* (STD_ON == CRCU_DMA_USED) */

/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
/**
 * @brief           CRCU driver initialization validation.
 * @details         Checks if the driver is initialized and the channel is valid.
 *
 * @param[in]       channelId       - Id of the channel to validate
 * @param[in]       u8ChannelFuncId - The internal id of the caller channel function
 *
 * @return          boolean
 *
 * @api
 *
 * */
LOCAL_INLINE FUNC(boolean, CRCU_CODE) Crcu_ValidateDriverInitAndChannel
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId,
    VAR(uint8,              AUTOMATIC) u8ChannelFuncId
)
{
    VAR(boolean, AUTOMATIC) bValid = (boolean)FALSE;
    
    /* Check if CRCU module is initialized */
    if (NULL_PTR == Crcu_pConfig)
    {
        (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, Crcu_au8ChannelFuncServiceId[u8ChannelFuncId], CRCU_E_UNINIT);
    }
    /* Check if channelId is in the valid range */
    else if (channelId >= Crcu_pConfig->crcuNumChannels)
    {
        (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, Crcu_au8ChannelFuncServiceId[u8ChannelFuncId], CRCU_E_INVALID_CHANNEL);
    }
    else
    {
        bValid = (boolean)TRUE;
    }

    return bValid;
}

/**
 * @brief           CRCU driver channel state validation.
 * @details         Checks if the channel the Crcu function is using is idle or busy.
 *
 * @param[in]       channelId       - Id of the channel to validate
 * @param[in]       u8ChannelFuncId - The internal id of the caller channel function
 *
 * @return          boolean
 *
 * @api
 *
 * */
LOCAL_INLINE FUNC(boolean, CRCU_CODE) Crcu_ValidateChannelStateAndSetBusyIfIdle
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId,
    VAR(uint8,              AUTOMATIC) u8ChannelFuncId
)
{
    VAR(boolean, AUTOMATIC) bValid = (boolean)FALSE;
    
    SchM_Enter_Crcu_CRCU_EXCLUSIVE_AREA_00();
    /* Check if another channel function is not already running */
    if (Crcu_aeChannelState[channelId] != CRCU_CH_STATE_IDLE)
    {
        (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, Crcu_au8ChannelFuncServiceId[u8ChannelFuncId], CRCU_E_CHANNEL_BUSY);
    }
    else
    {
        Crcu_aeChannelState[channelId] = CRCU_CH_STATE_BUSY;
        bValid = (boolean)TRUE;
    }
    SchM_Exit_Crcu_CRCU_EXCLUSIVE_AREA_00();
    
    return bValid;
}

/**
 * @brief           CRCU driver channel state switching to idle.
 * @details         Sets to idle the state of a given channel.
 *
 * @param[in]       channelId - Id of the channel to validate
 *
 * @return          void
 *
 * @api
 *
 * */
LOCAL_INLINE FUNC(void, CRCU_CODE) Crcu_SetChannelStateIdle
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) channelId
)
{
    SchM_Enter_Crcu_CRCU_EXCLUSIVE_AREA_01();

    Crcu_aeChannelState[channelId] = CRCU_CH_STATE_IDLE;

    SchM_Exit_Crcu_CRCU_EXCLUSIVE_AREA_01();
}
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */

#if (STD_ON == CRCU_DMA_USED)

/**
 * @brief           Redirects Crcu async Crc calculation complete notifications to each Crcu channel callback.
 * @details         Called by every Crcu_DmaTransferCompleteX function available in the code.
 *
 * @param[in]       Crcu_ChannelId - Id of the CRCU channel to for which an application notification should be called
 *                    
 *
 * @return          Crcu_ValueType - CRC checksum result
 * implements       Crcu_ProcessDmaTransferComplete_Activity
 * @api
 **/
static FUNC(void, CRCU_CODE) Crcu_ProcessDmaTransferComplete
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) Crcu_ChannelId
)
{
    P2CONST(Crcu_ChannelType, AUTOMATIC, CRCU_APPL_CONST) pCrcuChannel;
    
    VAR(Crcu_AsyncCalculateCrcNotifType, AUTOMATIC) pfCrcuAsyncCalculateCrcNotif;
    VAR(Crcu_ValueType,                  AUTOMATIC) crcValue;
    
    if (NULL_PTR != Crcu_pConfig)
    {
        pCrcuChannel                 = &((*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId]);
        pfCrcuAsyncCalculateCrcNotif = pCrcuChannel->pfCrcuAsyncCalculateCrcNotif;
        if(NULL_PTR != pfCrcuAsyncCalculateCrcNotif)
        {
            Crcu_Ipw_GetChannelCrc(pCrcuChannel->crcChannel, crcValue);
            pfCrcuAsyncCalculateCrcNotif(Crcu_ChannelId, crcValue);
        }
    }
}
#endif /* (STD_ON == CRCU_DMA_USED) */

/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/
/**
 * @brief           This function initializes the driver.
 * @details         This service is a non reentrant function used for driver initialization.
 *
 * @param[in]       Crcu_ConfigPtr - Pointer to a selected configuration structure.
 *
 * @return          void
 * @implements      Crcu_Init_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(void, CRCU_CODE) Crcu_Init
(
    P2CONST(Crcu_ConfigType, AUTOMATIC, CRCU_APPL_CONST) Crcu_ConfigPtr
)
{
#if(STD_ON == CRCU_DEV_ERROR_DETECT)
    VAR(uint8, AUTOMATIC) u8iCounter;
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */

#if (STD_ON == CRCU_PRECOMPILE_SUPPORT)
    #if (STD_ON == CRCU_DEV_ERROR_DETECT)
    if (NULL_PTR != Crcu_ConfigPtr)
    {
        (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_INIT_ID, CRCU_E_INVALID_POINTER);
    }
    else
    #endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
#else  /* (STD_ON == CRCU_PRECOMPILE_SUPPORT) */
    #if (STD_ON == CRCU_DEV_ERROR_DETECT)
    if (NULL_PTR == Crcu_ConfigPtr)
    {
        (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_INIT_ID, CRCU_E_INVALID_POINTER);
    }
    else
    #endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
#endif /* (STD_ON == CRCU_PRECOMPILE_SUPPORT) */
    {
#if (STD_ON == CRCU_PRECOMPILE_SUPPORT)
        Crcu_ConfigPtr = &Crcu_PBCfgVariantPredefined;
#endif /* (STD_ON == CRCU_PRECOMPILE_SUPPORT) */ 

        /* Call Ipw layer function to init CRCU module */
        Crcu_Ipw_Init(Crcu_ConfigPtr);
    }
#if(STD_ON == CRCU_DEV_ERROR_DETECT)
    /* Mark all channels as being idle */
    for(u8iCounter = 0U; u8iCounter < Crcu_ConfigPtr->crcuNumChannels; u8iCounter++)
    {
        Crcu_aeChannelState[u8iCounter] = CRCU_CH_STATE_IDLE;
    }
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
    /*  Save configuration pointer in global variable */
    Crcu_pConfig = Crcu_ConfigPtr;
}

/**
 * @brief           This function configures a CRCU channel.
 * @details         This service is used for CRCU channel configuration.
 *
 * @param[in]       Crcu_ChannelId       - Id of the CRCU channel to configure
 * @param[in]       Crcu_ChannelConfigId - Id of the CRCU channel configuration to apply
 *                    
 *
 * @return          Crcu_ChannelAddressType - Address of the CRC channel data register
 * @implements      Crcu_SetChannelConfig_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(Crcu_ChannelAddressType, CRCU_CODE) Crcu_SetChannelConfig
(
    VAR(Crcu_ChannelIdType,       AUTOMATIC) Crcu_ChannelId,
    VAR(Crcu_ChannelConfigIdType, AUTOMATIC) Crcu_ChannelConfigId
)
{
    VAR(Crcu_ChannelAddressType, AUTOMATIC) retVal = NULL_PTR;
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    VAR(boolean, AUTOMATIC) bValidParams;

    /* Allow testing the case when the function should report DET error CRCU_E_CHANNEL_BUSY using fault injection */
    MCAL_FAULT_INJECTION_POINT(CRCU_FIP_1_E_CHANNEL_BUSY);

    bValidParams = Crcu_ValidateDriverInitAndChannel(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_SET_CONFIG);
    
    if((boolean)TRUE == bValidParams)
    {
        /* Check if the id of the channel configuration is in the valid range */
        if(Crcu_ChannelConfigId >= Crcu_pConfig->crcuNumChannelConfigs)
        {
            (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_SETCHANNELCONFIG_ID, CRCU_E_INVALID_CHANNEL_CONFIG);
        }
        else
        {
            /* Check if another channel function is not already running */
            if ((boolean)TRUE == Crcu_ValidateChannelStateAndSetBusyIfIdle(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_SET_CONFIG))
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
            {
                /* Call Ipw layer function to configure the CRCU channel */
                Crcu_Ipw_SetChannelConfig((*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId].crcChannel, &(*(Crcu_pConfig->pCrcv2ChannelConfigList))[Crcu_ChannelConfigId], retVal);
                /* Mark the channel as idle */
                Crcu_SetChannelStateIdle(Crcu_ChannelId);
            }
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
        }
    }
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */

    /* Return pointer to CRC channel */
    return retVal;
}

/**
 * @brief           This function writes a seed value to a CRC channel.
 * @details         The function writes the seed value of a CRC channel.
 *
 * @param[in]       Crcu_ChannelId - Id of the CRCU channel to set seed for
 * @param[in]       Crcu_Seed      - Value of the seed
 *                    
 * @return          void
 * @implements      Crcu_SetChannelSeed_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(void, CRCU_CODE) Crcu_SetChannelSeed
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) Crcu_ChannelId,
    VAR(Crcu_ValueType,     AUTOMATIC) Crcu_Seed
)
{
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    VAR(boolean, AUTOMATIC) bValidParams;

    /* Allow testing the case when the function should report DET error CRCU_E_CHANNEL_BUSY using fault injection */
    MCAL_FAULT_INJECTION_POINT(CRCU_FIP_2_E_CHANNEL_BUSY);

    bValidParams = Crcu_ValidateDriverInitAndChannel(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_SET_SEED);
    
    if((boolean)TRUE == bValidParams)
    {
        /* Check if another channel function is not already running */
        if ((boolean)TRUE == Crcu_ValidateChannelStateAndSetBusyIfIdle(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_SET_SEED))
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
        {  
            /* Call Ipw layer to write the CRCU channel seed */
            Crcu_Ipw_SetChannelSeed((*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId].crcChannel, Crcu_Seed);
            /* Mark the channel as idle */
            Crcu_SetChannelStateIdle(Crcu_ChannelId);
        }
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    }
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
}

/**
 * @brief           This function calculates synchronously a CRC. It's return value is the calculated CRC.
 * @details         The function calculates and returns the CRC for a previously configured channel.
 *
 * @param[in]       Crcu_ChannelId - Id of the CRCU channel to use for synchronous Crc calculation
 * @param[in]       Crcu_DataPtr   - Pointer to data to perform CRC on
 * @param[in]       Crcu_Length    - Length of data to perform CRC on, in bytes
 *                    
 *
 * @return          Crcu_ValueType - value of the CRC
 * @implements      Crcu_SyncCalculateChannelCrc_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(Crcu_ValueType, CRCU_CODE) Crcu_SyncCalculateChannelCrc
(
    VAR    (Crcu_ChannelIdType, AUTOMATIC                  ) Crcu_ChannelId,
    P2CONST(uint8,              AUTOMATIC, CRCU_APPL_CONST ) Crcu_DataPtr,
    VAR    (uint32,             AUTOMATIC                  ) Crcu_Length
)
{
    VAR(Crcu_ValueType, AUTOMATIC) retVal = 0U;
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    VAR(boolean, AUTOMATIC) bValidParams;

    /* Allow testing the case when the function should report DET error CRCU_E_CHANNEL_BUSY using fault injection */
    MCAL_FAULT_INJECTION_POINT(CRCU_FIP_3_E_CHANNEL_BUSY);

    bValidParams = Crcu_ValidateDriverInitAndChannel(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_SYNC_CALCULATE_CRC);
    
    if((boolean)TRUE == bValidParams)
    {
        if(NULL_PTR == Crcu_DataPtr)
        {
            /* If Crcu_DataPtr equals NULL_PTR, CRCU_E_INVALID_POINTER shall be reported to the DET and the API function shall return. */
            (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_SYNCCALCULATECHANNELCRC_ID, CRCU_E_INVALID_POINTER);
        }        
        else
        {
            if(0U == Crcu_Length)
            {
                /* If Crcu_Length equals 0, CRCU_E_INVALID_LENGTH shall be reported to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_SYNCCALCULATECHANNELCRC_ID, CRCU_E_INVALID_LENGTH);
            }
            else
            {
                /* Check if another channel function is not already running */
                if ((boolean)TRUE == Crcu_ValidateChannelStateAndSetBusyIfIdle(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_SYNC_CALCULATE_CRC))
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
                {
                    /* Call Ipw layer to write data to the CRC channel */
                    Crcu_Ipw_SyncCalculateChannelCrc((*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId].crcChannel, Crcu_DataPtr, Crcu_Length, retVal);
                    /* Mark the channel as idle */
                    Crcu_SetChannelStateIdle(Crcu_ChannelId);
                }
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
            }
        }
    }
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
    
    return retVal;
}

#if (STD_ON == CRCU_DMA_USED)
/**
 * @brief           This function initiates the asynchronous calculation of a CRC.
 * @details         The data is transfered to the CRC engine using DMA and a notification is called from the driver
 *                  in the application when all data has been transfered and the CRC value is ready. 
 *
 * @param[in]       Crcu_ChannelId - Id of the CRCU channel to use for asynchronous Crc calculation
 * @param[in]       Crcu_DataPtr   - Pointer to data to perform CRC on
 * @param[in]       Crcu_Length    - Length of data to perform CRC on, in bytes
 *                    
 *
 * @return          void
 * @implements      Crcu_AsyncCalculateChannelCrc_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(void, CRCU_CODE) Crcu_AsyncCalculateChannelCrc
(
    VAR    (Crcu_ChannelIdType, AUTOMATIC                  ) Crcu_ChannelId,
    P2CONST(uint8,              AUTOMATIC, CRCU_APPL_CONST ) Crcu_DataPtr,
    VAR    (uint32,             AUTOMATIC                  ) Crcu_Length
)
{
    P2CONST(Crcu_ChannelType, AUTOMATIC, CRCU_APPL_CONST) pCrcuChannel;
    
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    VAR(boolean, AUTOMATIC) bValidParams;

    /* Allow testing the case when the function should report DET error CRCU_E_CHANNEL_BUSY using fault injection */
    MCAL_FAULT_INJECTION_POINT(CRCU_FIP_4_E_CHANNEL_BUSY);

    bValidParams = Crcu_ValidateDriverInitAndChannel(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_ASYNC_CALCULATE_CRC);
    
    if((boolean)TRUE == bValidParams)
    {
        if(NULL_PTR == Crcu_DataPtr)
        {
            /* If Crcu_DataPtr equals NULL_PTR, CRCU_E_INVALID_POINTER shall be reported to the DET and the API function shall return. */
            (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_ASYNCCALCULATECHANNELCRC_ID, CRCU_E_INVALID_POINTER);
        }        
        else
        {
            if(0U == Crcu_Length)
            {
                /* If Crcu_Length equals 0, CRCU_E_INVALID_LENGTH shall be reported to the DET and the API function shall return. */
                (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_ASYNCCALCULATECHANNELCRC_ID, CRCU_E_INVALID_LENGTH);
            }
            else
            {
                if(MCL_DMA_CHANNEL_NOT_CONFIGURED_U8 == (*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId].dmaChannel)
                {
                    /* If no Dma channel is configured for the current Crcu channel, CRCU_E_DMA_CH_NOT_CONFIGURED shall be reported to the DET and the API function shall return. */
                    (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_ASYNCCALCULATECHANNELCRC_ID, CRCU_E_DMA_CH_NOT_CONFIGURED);
                }
                else
                {
                    if ((boolean)TRUE == Crcu_ValidateChannelStateAndSetBusyIfIdle(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_ASYNC_CALCULATE_CRC))
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
                    {
                        pCrcuChannel = &((*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId]);
                        /* Call Ipw layer to write data to the CRC channel */
                        if((Crcu_Length < sizeof(uint32))                    || \
                            /** @violates @ref Crcu_c_REF_7 Cast from a pointer to a function and any type other than an integral type */
                            /** @violates @ref Crcu_c_REF_8 A cast should not be performed between a pointer type and an integral type. */                     
                            ((((uint32)Crcu_DataPtr)%(sizeof(uint32))) != 0U) || \
                            (((Crcu_Length)%(sizeof(uint32))) != 0U)             \
                          )
                        {
                            Crcu_Ipw_AsyncCalculateChannelCrc(pCrcuChannel->crcChannel, pCrcuChannel->dmaChannel, Crcu_DataPtr, Crcu_Length, (uint8)(sizeof(uint8)));
                        }
                        else
                        {
                            Crcu_Ipw_AsyncCalculateChannelCrc(pCrcuChannel->crcChannel, pCrcuChannel->dmaChannel, Crcu_DataPtr, Crcu_Length, (uint8)(sizeof(uint32)));
                        }
                        /* Mark the channel as idle */
                        Crcu_SetChannelStateIdle(Crcu_ChannelId);
                    }
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
                }
            }
        }
    }
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
}
#endif /* (STD_ON == CRCU_DMA_USED) */

/**
 * @brief           Provides CRC result.
 * @details         Returns CRC checksum result for required channel.
 *
 * @param[in]       Crcu_ChannelId - Id of the CRCU channel to read CRC value from
 *                    
 *
 * @return          Crcu_ValueType - CRC checksum result
 * @implements      Crcu_GetChannelCrc_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(Crcu_ValueType, CRCU_CODE) Crcu_GetChannelCrc
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) Crcu_ChannelId
)
{
    VAR(Crcu_ValueType, AUTOMATIC) retVal = 0x0U;
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    VAR(boolean, AUTOMATIC) bValidParams;
    
    /* Allow testing the case when the function should report DET error CRCU_E_CHANNEL_BUSY using fault injection */
    MCAL_FAULT_INJECTION_POINT(CRCU_FIP_5_E_CHANNEL_BUSY);

    bValidParams = Crcu_ValidateDriverInitAndChannel(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_GET_CRC);
    
    if((boolean)TRUE == bValidParams)
    {
        if ((boolean)TRUE == Crcu_ValidateChannelStateAndSetBusyIfIdle(Crcu_ChannelId, CRCU_ID_CHANNEL_FUNC_GET_CRC))
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
        {
            /* Call Ipw layer to get channel CRC signature */
            Crcu_Ipw_GetChannelCrc((*(Crcu_pConfig->pCrcuChannelList))[Crcu_ChannelId].crcChannel, retVal);
            /* Mark the channel as idle */
            Crcu_SetChannelStateIdle(Crcu_ChannelId);
        }
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    }
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
    /* Return CRC signature */
    return retVal;
}

#if (STD_ON == CRCU_GET_VERSION_INFO_API)
/**
 * @brief          Software module version query.
 * @details        Returns the version information of this module
 *
 * @param[out]     Crcu_VersionInfoPtr
 *                    
 *
 * @return         void
 * @implements     Crcu_GetVersionInfo_Activity
 *
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(void, CRCU_CODE) Crcu_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRCU_APPL_CONST) Crcu_VersionInfoPtr
)
{
#if (STD_ON == CRCU_DEV_ERROR_DETECT)
    if (NULL_PTR == Crcu_VersionInfoPtr)
    {
        /* If VersioninfoPtr equals NULL_PTR, CRCU_E_INVALID_POINTER shall be reported
        to the DET and the API function shall return. */
        (void)Det_ReportError((uint16)CRCU_MODULE_ID, CRCU_INSTANCE_ID, CRCU_GETVERSIONINFO_ID, CRCU_E_INVALID_POINTER);
    }
    else
#endif /* (STD_ON == CRCU_DEV_ERROR_DETECT) */
    {
        Crcu_VersionInfoPtr->moduleID         = (uint16)CRCU_MODULE_ID;
        Crcu_VersionInfoPtr->vendorID         = (uint16)CRCU_VENDOR_ID;
        Crcu_VersionInfoPtr->sw_major_version = (uint8)CRCU_SW_MAJOR_VERSION;
        Crcu_VersionInfoPtr->sw_minor_version = (uint8)CRCU_SW_MINOR_VERSION;
        Crcu_VersionInfoPtr->sw_patch_version = (uint8)CRCU_SW_PATCH_VERSION;
    }
}
#endif /* (STD_ON == CRCU_GET_VERSION_INFO_API) */


#if (STD_ON == CRCU_DMA_USED)

#if (CRCU_MAX_NUM_CRC_CHANNELS > 0U)
/**
 * @brief           Implementation of MCL transfer complete callback
 * @details         Dma transfer complete notification called from the MCL DMA channel 
 *                  configured for CRCU channel with ID 0
 *
 *
 * @return          void
 * implements       Crcu_DmaTransferComplete0_Activity
 * @api
 **/
/** @violates @ref Crcu_c_REF_5 Internal linkage unless external linkage is required. */
FUNC(void, MCL_CODE) Crcu_DmaTransferComplete0(void)
{
    Crcu_ProcessDmaTransferComplete((Crcu_ChannelIdType)0U);
}
#endif /* (CRCU_MAX_NUM_CRC_CHANNELS > 0) */

#endif /* (STD_ON == CRCU_DMA_USED) */

#define CRCU_STOP_SEC_CODE
/** @violates @ref Crcu_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_c_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
