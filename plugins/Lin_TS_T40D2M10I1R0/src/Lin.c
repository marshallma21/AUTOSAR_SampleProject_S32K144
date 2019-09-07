/**
*   @file    Lin.c
*   @implements Lin.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - High level part of LIN driver.
*   @details This file contains the functions defined by AutoSAR.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_c_REF_5
* Violates MISRA 2004 Advisory Rule 16.7, A pointer parameter in a
* function prototype should be declared as pointer to const if the
* pointer is not used to modify the addressed object.
*
* @section Lin_c_REF_7
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Lin_c_REF_8
* Violates MISRA 2004 Required Rule 8.8, Precautions shall be taken
* in order to prevent external objects or functions to be declared
* in more than one file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin.h"
#include "Lin_IPW.h"
#if (LIN_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

#if(LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

/**
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LIN_VENDOR_ID_C                      43
#define LIN_AR_RELEASE_MAJOR_VERSION_C       4
#define LIN_AR_RELEASE_MINOR_VERSION_C       2

/**
* @violates @ref Lin_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_C    2
#define LIN_SW_MAJOR_VERSION_C               1
#define LIN_SW_MINOR_VERSION_C               0
#define LIN_SW_PATCH_VERSION_C               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same Autosar version */
#if (LIN_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin.c and Lin.h have different vendor ids"
#endif
#if ((LIN_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin.c and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_C != LIN_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Lin.c and Lin.h are different"
#endif
/* Check if current file and Lin_IPW header file are of the same Autosar version */
#if (LIN_VENDOR_ID_C != LIN_IPW_VENDOR_ID)
    #error "Lin.c and Lin_IPW.h have different vendor ids"
#endif
#if ((LIN_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION_IPW))
    #error "AutoSar Version Numbers of Lin.c and Lin_IPW.h are different"
#endif
/* Check if current file and Lin_IPW header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION_IPW) || \
     (LIN_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION_IPW) || \
     (LIN_SW_PATCH_VERSION_C != LIN_SW_PATCH_VERSION_IPW) )
    #error "Software Version Numbers of Lin.c and Lin_IPW.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if the source file and Dem header file are of the same version */
        #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
           (LIN_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lin.c and Dem.h are different"
        #endif
    #endif

    #if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((LIN_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (LIN_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Lin.c and Det.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define LIN_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#if (LIN_PRECOMPILE_SUPPORT == STD_ON)
 /**
* @violates @ref Lin_c_REF_7 Object defined external because of autosar
*
* @violates @ref Lin_c_REF_8 Precautions shall be taken in order to
* prevent variables being declared as external in more than one file.
*/
extern CONST(Lin_ConfigType,LIN_CONST)Lin_PBCfgVariantPredefined;
 #endif
#define LIN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 /*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* put all LIN variables into defined section */
#define LIN_START_SEC_VAR_INIT_UNSPECIFIED

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) Lin_pcConfigPtr = NULL_PTR;

#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief          Global configuration array.
* @details        Array containing channel configurations.
*/
P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST) Lin_pChannelConfigPtr[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#define LIN_START_SEC_VAR_INIT_8

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief          LIN driver status variable.
* @details        LIN driver state machine.
*
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
static VAR(uint8,LIN_VAR)Lin_u8LinDrvStatus = LIN_UNINIT;

#define LIN_STOP_SEC_VAR_INIT_8

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#define LIN_START_SEC_VAR_NO_INIT_8

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief          LIN channel state variable.
* @details        LIN channel state machine.
*/
volatile VAR(uint8,LIN_VAR)Lin_au8LinChStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN frame state variable.
* @details        LIN frame state.
*/
volatile VAR(uint8,LIN_VAR)Lin_au8LinChFrameStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN Frame header state variable.
* @details        LIN Frame header state.
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage
* unless external linkage is required.
*/
static volatile VAR(uint8,LIN_VAR)Lin_au8LinChHeaderStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN Frame error status variable.
* @details        LIN Frame error status.
*/
volatile VAR(uint8,LIN_VAR)Lin_au8LinChFrameErrorStatus[LIN_HW_MAX_MODULES];

/**
* @brief          LIN channel hardware map variable.
* @details        Lin channel hardware map.
*/
VAR(sint8,LIN_VAR)Lin_as8ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];

/**
* @brief          LIN header command type variable.
* @details        LIN header command type.
*/
VAR(uint8, LIN_VAR)Lin_au8TransmitHeaderCommand[LIN_HW_MAX_MODULES];

/**
* @brief          LIN SDU buffer variable.
* @details        LIN SDU buffer to be returned.
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage
* unless external linkage is required.
*/
static VAR(uint8, LIN_VAR) Lin_au8SduBuffAddress[LIN_HW_MAX_MODULES][LIN_MAX_DATA_LENGTH];

#define LIN_STOP_SEC_VAR_NO_INIT_8

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @note put all LIN code into defined section
*/
#define LIN_START_SEC_CODE

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief   Initializes the LIN module.
* @details This function performs software initialization of LIN
*          driver:
*          - Clears the shadow buffer of all available Lin channels
*          - Set LIN channel state machine of all available Lin
*            channels to LIN_CH_SLEEP_STATE for ASR 4.3.1 or
*            LIN_CH_OPERATIONAL for others
*          - Set frame operation state machine of all available LIN
*            channels to LIN_CH_NOT_READY_STATE for ASR 4.3.1 or
*            LIN_CH_READY_STATE for others
*          - Set driver state machine to LIN_INIT.
*
* @param[in] Config        Pointer to LIN driver configuration set.
*
* @return  void
*
* @api
*
* @implements Lin_Init_Activity
*
* @note    Autosar Service ID: 0x00.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, LIN_CODE) Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config)
{
    VAR(uint8,AUTOMATIC) u8Lin_ChLoop;
    VAR(uint8,AUTOMATIC) u8Lin_Hw_ChLoop;
    VAR(uint8,AUTOMATIC) u8Length;

    /* Check whether the LIN driver is in LIN_UNINIT state */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
    if (LIN_UNINIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has been already initialized */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_INIT_ID, \
                              (uint8)LIN_E_STATE_TRANSITION \
                             );
    }
    else
    {
        /* Do nothing */
    }
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */

#if (LIN_PRECOMPILE_SUPPORT != STD_ON)
    /* Check Config for not being a null pointer */
    if (NULL_PTR == Config)
    {
    #if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Invalid pointer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_INIT_ID, \
                              (uint8)LIN_E_INVALID_POINTER \
                             );
    #endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        Lin_pcConfigPtr = Config;
#else /* LIN_PRECOMPILE_SUPPORT == STD_ON */
    if( NULL_PTR != Config )
    {
    #if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Invalid pointer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_INIT_ID, \
                              (uint8)LIN_E_INVALID_POINTER \
                             );
    #endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
         Lin_pcConfigPtr = &Lin_PBCfgVariantPredefined;
 
#endif /* LIN_PRECOMPILE_SUPPORT */

#ifdef LIN_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == LIN_ENABLE_USER_MODE_SUPPORT)
        #ifdef LIN_LINFLEX_REG_PROT_AVAILABLE
            Lin_Ipw_SetUserAccessAllowed();
        #endif
    #endif
#endif

        for(u8Lin_Hw_ChLoop=(uint8)0U;u8Lin_Hw_ChLoop<LIN_HW_MAX_AVAILABLE_MODULES;u8Lin_Hw_ChLoop++)
        {
            Lin_as8ChannelHardwareMap[u8Lin_Hw_ChLoop]= -1;
        }
         for(u8Lin_ChLoop=(uint8)0U; u8Lin_ChLoop < LIN_HW_MAX_MODULES; u8Lin_ChLoop++)
         {
            for(u8Length=(uint8)0U;u8Length<LIN_MAX_DATA_LENGTH;u8Length++)
            {
                Lin_au8SduBuffAddress[u8Lin_ChLoop][u8Length]= (uint8)0;
            }
            Lin_pChannelConfigPtr[u8Lin_ChLoop] = Lin_pcConfigPtr->pLin_Channel[u8Lin_ChLoop];
            Lin_Ipw_InitChannel(u8Lin_ChLoop);
             /* Set LIN channel state machine to LIN_CH_OPERATIONAL */
            Lin_au8LinChStatus[u8Lin_ChLoop] = LIN_CH_OPERATIONAL;
            /* Set LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_au8LinChFrameStatus[u8Lin_ChLoop] = LIN_CH_READY_STATE;
             /* Header status flag */
            Lin_au8LinChHeaderStatus[u8Lin_ChLoop] = (uint8)FALSE;
            /* Reset header command type */
            Lin_au8TransmitHeaderCommand[u8Lin_ChLoop] = LIN_TX_NO_COMMAND;
            /* Reset error status global flag */
            Lin_au8LinChFrameErrorStatus[u8Lin_ChLoop] = LIN_NO_ERROR;
            /* Map configured hardware channel to logical channel */
             Lin_as8ChannelHardwareMap[Lin_pChannelConfigPtr[u8Lin_ChLoop]->pChannelConfigPC->u8LinChannelID] = (sint8)Lin_pChannelConfigPtr[u8Lin_ChLoop]->pChannelConfigPC->u8LinHwChannel;
         }
        /* Update LIN driver status to LIN_INIT */
        Lin_u8LinDrvStatus = LIN_INIT;
    }
    return; /* Exit function with no return */
}

/**
* @brief   Validates for upper layers the wake up of LIN channel.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          the addressed LIN Channel is not
*                          in sleep state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_CheckWakeup_Activity
*
* @note    Autosar Service ID: 0x0A.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_CHECKWAKEUP_ID, \
                              (uint8)LIN_E_UNINIT \
                             );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_CHECKWAKEUP_ID, \
                                  (uint8)LIN_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            u8TempReturn = (uint8)E_OK;

            /* The addressed LIN channel is initialized */
            /* chInSleep = 0U;*/
            /* Check if the addressed LIN channel is in */
            /* LIN_CH_SLEEP_STATE state */
            if (LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[Channel])
            {
                /* Lin channel is in LIN_CH_SLEEP_STATE state */

                /* Check if Lin channel has detected a wake-up */
                if ((uint8)TRUE == Lin_Ipw_CheckWakeup(Channel))
                {
                     /* Indicates a valid timer wakeup event to ECU State Manager */
                     EcuM_SetWakeupEvent(Lin_pChannelConfigPtr[Channel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
                 }
            }
            else
            {
                 /* In the case of ASR4.2, nothing need to do */
             }
        }
    }
    return u8TempReturn;
}

/**
* @brief   Gets the status of the LIN driver.
* @details This function returns the state of the current
*          transmission, reception or operation status.
*          If the reception of a Slave response was successful then
*          this service provides a pointer to the buffer where the
*          data is stored.
*
* @param[in] Channel       LIN channel to be checked.
*
* @param[out] Lin_SduPtr   Lin_SduPtr pointer to pointer to a shadow
*                          buffer or memory mapped LIN Hardware
*                          receive buffer where the current SDU is
*                          stored.
* @return                  Lin_StatusType.
* @retval LIN_NOT_OK       Development or production error rised
*                          none of the below conditions.
* @retval LIN_TX_OK        Successful transmission.
* @retval LIN_TX_BUSY      Ongoing transmission of header or response.
* @retval LIN_TX_HEADER_ERROR Error occurred during header
*                          transmission.
* @retval LIN_TX_ERROR     Error occurred during response
*                          transmission.
* @retval LIN_RX_OK        Reception of correct response.
* @retval LIN_RX_BUSY      Ongoing reception where at least one byte
*                          has been received.
* @retval LIN_RX_ERROR     Error occurred during reception.
* @retval LIN_RX_NO_REPONSE No data byte has been received yet.
* @retval LIN_OPERATIONAL  Channel is ready for next header.
*                          transmission and no data are available.
* @retval LIN_CH_SLEEP     Channel is in sleep mode.
*
* @api
*
* @implements Lin_GetStatus_Activity
*
* @note    Autosar Service ID: 0x08.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage
* unless external linkage is required.
*/
FUNC(Lin_StatusType, LIN_CODE) Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr)
{
    VAR(Lin_StatusType, AUTOMATIC) u8tempReturn = LIN_NOT_OK;

    VAR(uint8, LIN_VAR) u8Lin_ChannelState;

    /* Check whether the LIN driver is in LIN_INIT state */
    if(LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GETSTATUS_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8tempReturn = LIN_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_GETSTATUS_ID, \
                                  (uint8)LIN_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8tempReturn = LIN_NOT_OK;
        }
        else
        {
            /* Check PduInfoPtr for not being a null pointer */
            if(NULL_PTR == Lin_SduPtr)
            {
                /* Invalid pointer */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_GETSTATUS_ID, \
                                      (uint8)LIN_E_PARAM_POINTER \
                                     );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                u8tempReturn = LIN_NOT_OK;
            }
            else
            {
                u8Lin_ChannelState = Lin_au8LinChStatus[Channel];
                /* LIN channel state */
                 switch(u8Lin_ChannelState)
                {
                    case LIN_CH_SLEEP_STATE:
                        u8tempReturn = LIN_CH_SLEEP;
                        break;
                     case LIN_CH_SLEEP_PENDING:
                        Lin_au8LinChStatus[Channel] = LIN_CH_SLEEP_STATE;
                        /* Initialize the pointer to return with */
                        /* the address of the data receive buffer */
                        *Lin_SduPtr = Lin_au8SduBuffAddress[Channel];
                        u8tempReturn = Lin_Ipw_HardwareGetStatus(Channel, Lin_au8SduBuffAddress[Channel]);
                        break;
                     case LIN_CH_OPERATIONAL:
                        /* LIN Channel frame state */
                        /* Initialize the pointer to return with */
                        /* the address of the data receive buffer */
                        *Lin_SduPtr = Lin_au8SduBuffAddress[Channel];
                        u8tempReturn = Lin_Ipw_HardwareGetStatus(Channel, Lin_au8SduBuffAddress[Channel]);
                        break;
                    default :
                        break;
                }

            }
        }

    }
    return u8tempReturn;
}

/**
* @brief   The service instructs the driver to transmit a
*          go-to-sleep-command on the addressed LIN channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command
*          frame with ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF,
*          0xFF, 0xFF, 0xFF, 0xFF). State transition in
*          LIN_CH_SLEEP_STATE shall be done after the completion of
*          the sleep command transmission regardless of the success
*          (therefore the ISR is responsible to put the channel in
*          LIN_CH_SLEEP_STATE).
*
* @param[in] Channel       LIN channel to be checked.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_GoToSleep_Activity
*
* @note    Autosar Service ID: 0x06.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_GOTOSLEEP_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_GOTOSLEEP_ID, \
                                  (uint8)LIN_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
            if(LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[Channel])
            {
                 u8TempReturn = (uint8)E_OK;
             }
            else
            {
                if((uint8)E_NOT_OK == Lin_Ipw_GoToSleep(Channel))
                {
                     /* Report Production error */
                    #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_E_TimeoutCfg.state)
                    {
                        (void)Dem_ReportErrorStatus((Dem_EventIdType)Lin_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                     }
                    else
                    {
                        #if (LIN_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                              (uint8)0, \
                                              (uint8)LIN_GOTOSLEEP_ID, \
                                              (uint8)LIN_E_TIMEOUT \
                                             );
                        #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    }
                    #else
                        #if (LIN_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                              (uint8)0, \
                                              (uint8)LIN_GOTOSLEEP_ID, \
                                              (uint8)LIN_E_TIMEOUT \
                                             );
                        #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    #endif  /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                     u8TempReturn = (uint8)E_NOT_OK;
                }
                else
                {
                     /* Report Production error */
                    #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_E_TimeoutCfg.state)
                    {
                        (void)Dem_ReportErrorStatus((Dem_EventIdType)Lin_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
                     }
                    #endif
                     u8TempReturn = (uint8)E_OK;
                }
            }
        }
    }
    return u8TempReturn;
}

/**
* @brief   Put a Lin channel in the internal sleep state.
* @details Stops any ongoing transmission, sets the channel
*          state to LIN_CH_SLEEP and put the LIN
*          hardware unit to a reduced power operation mode.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          LIN Channel is in sleep state or
*                          a timeout occurs.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_GoToSleepInternal_Activity
*
* @note    Autosar Service ID: 0x09.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_GOTOSLEEPINTERNAL_ID, \
                              (uint8)LIN_E_UNINIT \
                             );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_GOTOSLEEPINTERNAL_ID, \
                                  (uint8)LIN_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn =  (uint8)E_NOT_OK;
        }
        else
        {
            /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
            if (LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[Channel])
            {
                 u8TempReturn = (uint8)E_OK;
             }
            else
            {
                /* Call LLD function */
                if((uint8)E_NOT_OK == Lin_Ipw_GoToSleepInternal(Channel))
                {
                     /* Report Production error */
                    #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_E_TimeoutCfg.state)
                    {
                        (void)Dem_ReportErrorStatus((Dem_EventIdType)Lin_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                     }
                    else
                    {
                        #if (LIN_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                              (uint8)0, \
                                              (uint8)LIN_GOTOSLEEPINTERNAL_ID, \
                                              (uint8)LIN_E_TIMEOUT \
                                             );
                        #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    }
                    #else
                        #if (LIN_DEV_ERROR_DETECT == STD_ON)
                        /* Report error to development error tracer */
                        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                              (uint8)0, \
                                              (uint8)LIN_GOTOSLEEPINTERNAL_ID, \
                                              (uint8)LIN_E_TIMEOUT \
                                             );
                        #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    #endif  /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
 
                    u8TempReturn = (uint8)E_NOT_OK;
                }
                else
                {
                     /* Report Production Error */
                    #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    if ((uint32)STD_ON == Lin_E_TimeoutCfg.state)
                    {
                        (void)Dem_ReportErrorStatus((Dem_EventIdType)Lin_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
                     }
                    #endif
                     /* Update LIN channel status to LIN_CH_SLEEP_STATE */
                    Lin_au8LinChStatus[Channel] = LIN_CH_SLEEP_STATE;
                    /* Update LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
                    Lin_au8LinChFrameStatus[Channel] = LIN_CH_NOT_READY_STATE;
                    u8TempReturn = (uint8)E_OK;
                }
            }
        }
    }
    return u8TempReturn;
}

/**
* @brief   Sends a LIN frame.
* @details Sends a LIN header and a LIN response, if necessary. The
*          direction of the frame response (master response, slave
*          response, slave-to-slave communication) is provided by
*          the PduInfoPtr.
*
* @param[in] Channel       LIN channel to be addressed.
* @param[in] PduInfoPtr    pointer to PDU containing the PID,
*                          Checksum model, Response type, Dl and SDU
*                          data pointer.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN Channel is not valid or
*                          LIN driver is not initialized or
*                          PduInfoPtr is NULL or
*                          a timeout occurs or
*                          LIN Channel is in sleep state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_SendFrame_Activity
*
* @note    Autosar Service ID: 0x04.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*
*/
 FUNC(Std_ReturnType, LIN_CODE) Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, P2VAR(Lin_PduType, AUTOMATIC, LIN_APPL_DATA) PduInfoPtr)
 {
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_SENDFRAME_ID, \
                              (uint8)LIN_E_UNINIT \
                             );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_SENDFRAME_ID, (uint8)LIN_E_INVALID_CHANNEL);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check PduInfoPtr for not being a null pointer */
            if(NULL_PTR == PduInfoPtr)
            {
                /* Invalid pointer */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_SENDFRAME_ID, \
                                      (uint8)LIN_E_PARAM_POINTER \
                                     );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                u8TempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
                if (LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[Channel])
                {
                    /* LIN channel is in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                          (uint8)0, \
                                          (uint8)LIN_SENDFRAME_ID, \
                                          (uint8)LIN_E_STATE_TRANSITION \
                                         );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                    u8TempReturn = (uint8)E_NOT_OK;
                }
                else
                {
                    /* Lin Master Device will send the header first */
                    if((uint8)E_NOT_OK == Lin_Ipw_SendHeader(Channel,PduInfoPtr))
                    {
                         /* Report Production error */
                        #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        if ((uint32)STD_ON == Lin_E_TimeoutCfg.state)
                        {
                            (void)Dem_ReportErrorStatus((Dem_EventIdType)Lin_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                        }
                        else
                        {
                            #if (LIN_DEV_ERROR_DETECT == STD_ON)
                            /* Report error to development error tracer */
                            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                                  (uint8)0, \
                                                  (uint8)LIN_SENDFRAME_ID, \
                                                  (uint8)LIN_E_TIMEOUT \
                                                 );
                            #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                        }
                        #else
                            #if (LIN_DEV_ERROR_DETECT == STD_ON)
                            /* Report error to development error tracer */
                            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                                  (uint8)0, \
                                                  (uint8)LIN_SENDFRAME_ID, \
                                                  (uint8)LIN_E_TIMEOUT \
                                                 );
                            #endif  /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                        #endif  /* (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                         u8TempReturn = (uint8)E_NOT_OK;
                    }
                    else
                    {
                         /* Report Production no error */
                        #if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        if ((uint32)STD_ON == Lin_E_TimeoutCfg.state)
                        {
                            (void)Dem_ReportErrorStatus((Dem_EventIdType)Lin_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
                        }
                        #endif
                          /* Set header status to TRUE if master wants to send the response frame */
                        if (LIN_MASTER_RESPONSE == PduInfoPtr->Drc)
                        {
                            Lin_au8LinChHeaderStatus[Channel]= (uint8)TRUE;
                        }

                        /* Lin_SendHeader() function should be called first */
                        if ((uint8)FALSE != Lin_au8LinChHeaderStatus[Channel])
                        {
                            Lin_au8LinChHeaderStatus[Channel] = (uint8)FALSE;
                            Lin_Ipw_SendResponse(Channel,PduInfoPtr);
                            u8TempReturn = (uint8)E_OK;
                        }
                        else
                        {
                            u8TempReturn = (uint8)E_OK;
                        }
                    }
                }
            }
        }
    }
    return u8TempReturn;
/**
* @violates @ref Lin_c_REF_5 A pointer parameter in a
* function prototype should be declared as pointer to const if the
* pointer is not used to modify the addressed object.
*
*/
}

/**
* @brief   Generates a wake up pulse.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_Wakeup_Activity
*
* @note    Autosar Service ID: 0x07.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_WAKEUP_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_WAKEUP_ID, \
                                  (uint8)LIN_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
            if (LIN_CH_SLEEP_STATE != Lin_au8LinChStatus[Channel])
            {
                /* LIN channel is not in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_WAKEUP_ID, \
                                      (uint8)LIN_E_STATE_TRANSITION \
                                     );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                u8TempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Call LLD function */
                Lin_Ipw_WakeUp(Channel);
                /* Update LIN channel status to LIN_CH_OPERATIONAL */
                Lin_au8LinChStatus[Channel] = LIN_CH_OPERATIONAL;
                /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                Lin_au8LinChFrameStatus[Channel] = LIN_CH_READY_STATE;
                u8TempReturn = (uint8)E_OK;
            }
        }
    }
    return u8TempReturn;
}

 /**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without sending a
*          wake up signal to the LIN bus
*
* @param[in] Channel       LIN channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the LIN driver is not in sleep state or
*                          LIN Channel is not valid or
*                          LIN driver is not initialized.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements Lin_WakeupInternal_Activity
*
* @note    Autosar Service ID: 0x0B.
* @note    Asynchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_WakeupInternal(VAR(uint8, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_NOT_OK;

    /* Check whether the LIN driver is in LIN_INIT state */
    if (LIN_INIT != Lin_u8LinDrvStatus)
    {
        /* LIN driver has not been initialized yet */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)LIN_MODULE_ID,(uint8)0,(uint8)LIN_WAKEUPINTERNAL_ID,(uint8)LIN_E_UNINIT);
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
        u8TempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
         if (Channel >= LIN_HW_MAX_MODULES)
         {
            /* Invalid channel */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
        /* Report error to development error tracer */
            (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                  (uint8)0, \
                                  (uint8)LIN_WAKEUPINTERNAL_ID, \
                                  (uint8)LIN_E_INVALID_CHANNEL \
                                 );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
            u8TempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check whether the LIN channel is in LIN_CH_SLEEP_STATE state */
            if (LIN_CH_SLEEP_STATE != Lin_au8LinChStatus[Channel])
            {
                /* LIN channel is not in sleep mode */
#if (LIN_DEV_ERROR_DETECT == STD_ON)
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                                      (uint8)0, \
                                      (uint8)LIN_WAKEUPINTERNAL_ID, \
                                      (uint8)LIN_E_STATE_TRANSITION \
                                     );
#endif /* (LIN_DEV_ERROR_DETECT == STD_ON) */
                u8TempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Call LLD function */
                Lin_Ipw_WakeUpInternal(Channel);
                /* Update LIN channel status to LIN_CH_OPERATIONAL */
                Lin_au8LinChStatus[Channel] = LIN_CH_OPERATIONAL;
                /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                Lin_au8LinChFrameStatus[Channel] = LIN_CH_READY_STATE;
                u8TempReturn = (uint8)E_OK;
            }
        }
    }
    return u8TempReturn;
}

 #if (LIN_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] versioninfo   Pointer for storing the version information
*                              of this module.
*
* @return                  void.
*
* @api
*
* @pre            Preconditions as text description. Optional tag.
*
* @implements Lin_GetVersionInfo_Activity
*
* @note    Autosar Service ID: 0x01.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref Lin_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, LIN_CODE) Lin_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC,LIN_APPL_DATA) versioninfo)
{
#if( LIN_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == versioninfo )
    {
        (void)Det_ReportError((uint16)LIN_MODULE_ID, \
                              (uint8)0, \
                              (uint8)LIN_GETVERSIONINFO_ID, \
                              (uint8) LIN_E_PARAM_POINTER \
                             );
    }
    else
    {
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
        (versioninfo)->vendorID = (uint16) LIN_VENDOR_ID;
        (versioninfo)->moduleID = (uint8) LIN_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8) LIN_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8) LIN_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8) LIN_SW_PATCH_VERSION;
#if( LIN_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* LIN_DEV_ERROR_DETECT == STD_ON */
}
#endif /* LIN_VERSION_INFO_API == STD_ON */

#define LIN_STOP_SEC_CODE

/**
* @violates @ref Lin_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
