/**
*   @file    Gpt_Ipw.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - GPT driver source file.
*   @details GPT driver source file, containing the C implementation of functions prototypes that:
*            - are Autosar independent.
*            - are platform dependent.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
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
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section GPT_IPW_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_IPW_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_IPW_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_IPW_C_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
*
* @section GPT_IPW_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_IPW_C_REF_6
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be
* implicitly converted to a different underlying type. Integer to pointer conversion, specific to
* the ISR entry / exit code.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt.h"
#include "Gpt_Ipw.h"

#include "Gpt_Ftm.h"
#include "Gpt_LPit.h"
#include "Gpt_Lptmr.h"
#include "Gpt_SRtc.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_IPW_VENDOR_ID_C                    43
/** @violates @ref GPT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_IPW_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_IPW_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_IPW_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_IPW_SW_MAJOR_VERSION_C             1
#define GPT_IPW_SW_MINOR_VERSION_C             0
#define GPT_IPW_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_IPW_VENDOR_ID_C != GPT_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt.h have different vendor ids"
#endif
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt.h are different"
#endif
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_C != GPT_IPW_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt_Ipw.h have different vendor ids"
#endif
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt_Ipw.h are different"
#endif
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_IPW_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_IPW_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt_Ipw.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_C != GPT_FTM_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt_Ftm.h have different vendor ids"
#endif
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_FTM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt_Ftm.h are different"
#endif
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_FTM_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_FTM_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt_Ftm.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_C != GPT_LPIT_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt_LPit.h have different vendor ids"
#endif
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_LPIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_LPIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_LPIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt_LPit.h are different"
#endif
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_LPIT_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_LPIT_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_LPIT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt_LPit.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_C != GPT_LPTMR_VENDOR_ID)
    #error "Gpt_Ipw.c and Gpt_Lptmr.h have different vendor ids"
#endif
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_C != GPT_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_C != GPT_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_C != GPT_LPTMR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw.c and Gpt_Lptmr.h are different"
#endif
#if ((GPT_IPW_SW_MAJOR_VERSION_C != GPT_LPTMR_SW_MAJOR_VERSION) || \
     (GPT_IPW_SW_MINOR_VERSION_C != GPT_LPTMR_SW_MINOR_VERSION) || \
     (GPT_IPW_SW_PATCH_VERSION_C != GPT_LPTMR_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw.c and Gpt_Lptmr.h are different"
#endif

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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_IPW_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*================================================================================================*/
/**
* @brief   Gpt driver Autosar independent and IP dependent initialization function.
* @details This function is called once for each channel in the used configuration.
*          It determines the type of the HW channel (e.g. eMIOS, STM,etc...) and calls the
*          appropriate IP function in order to initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
*/
FUNC (void, GPT_CODE) Gpt_Ipw_Init(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig)
{

    switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
            Gpt_Ftm_Init(pHwChannelConfig->Gpt_uHwChannel,pHwChannelConfig->Gpt_bFreezeEnable,pHwChannelConfig->Gpt_uClockSource,
                         pHwChannelConfig->Gpt_uPrescaler);
        break;
#endif
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
            Gpt_LPit_Init(pHwChannelConfig->Gpt_uHwChannel,
#if (GPT_LPIT_ENABLE_EXT_TRIGGERS==STD_ON)
                          pHwChannelConfig->Gpt_uTimerTriggerConfig,
#endif
                          pHwChannelConfig->Gpt_bFreezeEnable);
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
            Gpt_Lptmr_Init(pHwChannelConfig->Gpt_uLptmrClock, pHwChannelConfig->Gpt_uLptmrPrescaler);
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
            Gpt_SRtc_Init(pHwChannelConfig->Gpt_uSRtcClock);
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}


/*================================================================================================*/
/**
* @brief   Gpt driver Autosar independent and IP dependent function for fetching the elapsed timer value.
* @details It determines the type of the HW channel (e.g. eMIOS, STM,etc...) and calls the
*          appropriate IP function for reading the elapsed timer value from the HW.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uTargetTime         Target time value
* @param[out]  pbReturnChannelOverflow  Rollover status flag value of the hardware timer channel
*
*/
FUNC (Gpt_ValueType, GPT_CODE) Gpt_Ipw_GetTimeElapsed(
                                P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,
                                P2VAR(Gpt_HwChannelInfoType, AUTOMATIC,GPT_APPL_DATA) pReturnHwChannelInfo
                                )
{
    VAR(uint32, AUTOMATIC) returnValue = 0U;

    switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
            returnValue = Gpt_Ftm_GetTimeElapsed(pHwChannelConfig->Gpt_uHwChannel, &(pReturnHwChannelInfo->bChannelRollover), &(pReturnHwChannelInfo->uTargetTime));
        break;
#endif
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
            returnValue = Gpt_LPit_GetTimeElapsed(pHwChannelConfig->Gpt_uHwChannel, &(pReturnHwChannelInfo->bChannelRollover), &(pReturnHwChannelInfo->uTargetTime));
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
            returnValue = Gpt_Lptmr_GetTimeElapsed(&(pReturnHwChannelInfo->bChannelRollover), &(pReturnHwChannelInfo->uTargetTime));
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
            returnValue = Gpt_SRtc_GetTimeElapsed(&(pReturnHwChannelInfo->bChannelRollover), &(pReturnHwChannelInfo->uTargetTime));
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return((Gpt_ValueType)returnValue);
}




/*================================================================================================*/
/**
* @brief   Gpt driver Autosar independent and platform dependent function for starting the timer channel.
* @details It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*          IP function for starting the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     uValue         Timeout period (in ticks) after which a notification shall occur (if
*                               enabled).
*/
FUNC (void, GPT_CODE) Gpt_Ipw_StartTimer(
                        P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,
                        VAR(Gpt_ValueType, AUTOMATIC) uValue
                        )
{

    switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
            Gpt_Ftm_StartTimer(pHwChannelConfig->Gpt_uHwChannel, (uint32)uValue);
        break;
#endif
    /** @violates @ref GPT_IPW_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
            Gpt_LPit_StartTimer(pHwChannelConfig->Gpt_uHwChannel, (uint32)uValue);
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
            Gpt_Lptmr_StartTimer((uint16)uValue);
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
            Gpt_SRtc_StartTimer((uint32)uValue);
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }


    return;
}
/*================================================================================================*/
/**
* @brief   Gpt driver Autosar independent and platform dependent function for stopping the timer channel.
* @details It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*          IP function for stopping the timer channel.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
*/
FUNC (void, GPT_CODE) Gpt_Ipw_StopTimer(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig)
{

    switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
            Gpt_Ftm_StopTimer(pHwChannelConfig->Gpt_uHwChannel);
        break;
#endif
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
            Gpt_LPit_StopTimer(pHwChannelConfig->Gpt_uHwChannel);
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
            Gpt_Lptmr_StopTimer();
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
            Gpt_SRtc_StopTimer();
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver Autosar independent and platform dependent function for enabling hardware timer interrupts.
* @details It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*          IP function for enabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
*/
FUNC (void, GPT_CODE) Gpt_Ipw_EnableInterrupt(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig)
{
#if (GPT_LPIT_USED == STD_OFF)
    (void)pHwChannelConfig;
#endif

    switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
        {
            Gpt_LPit_EnableInterrupt(pHwChannelConfig->Gpt_uHwChannel);
        }
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
        {
            Gpt_Lptmr_EnableInterrupt();
        }
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
        {
            Gpt_SRtc_EnableInterrupt();
        }
        break;
#endif
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }
    return;
}

/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)|| (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief   Gpt driver Autosar independent and platform dependent function for disabling hardware timer interrupts.
* @details It checks the type of the HW module (e.g. eMios, STM,etc...), and calls the appropriate
*          IP function for disabling hardware timer interrupts.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
*
* @pre     On/Off by the configuration parameter: GPT_ENABLE_DISABLE_NOTIFICATION_API
* @violates @ref GPT_IPW_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Ipw_DisableInterrupt(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig)
{
#if (GPT_LPIT_USED == STD_OFF)
    (void)pHwChannelConfig;
#endif

   switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
        {
            Gpt_LPit_DisableInterrupt(pHwChannelConfig->Gpt_uHwChannel);
        }
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
        {
            Gpt_Lptmr_DisableInterrupt();
        }
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
        {
            Gpt_SRtc_DisableInterrupt();
        }
        break;
#endif
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }

    return;
}
#endif

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver Autosar independent and IP dependent de-initialization function.
* @details This function is called for each  channel from the current configuration.
*          It determines the type of the HW channel (e.g. eMIOS, STM,etc...) and calls the
*          appropriate IP function in order to de-initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
*
* @pre     On/Off by the configuration parameter: GPT_DEINIT_API
*/
FUNC (void, GPT_CODE) Gpt_Ipw_DeInit(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig)
{
    switch(pHwChannelConfig->Gpt_uHwModule)
    {

#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
            Gpt_Ftm_DeInit(pHwChannelConfig->Gpt_uHwChannel);
        break;
#endif
#if (GPT_LPIT_USED == STD_ON)
        case GPT_LPIT_MODULE:
            Gpt_LPit_DeInit(pHwChannelConfig->Gpt_uHwChannel);
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
            Gpt_Lptmr_DeInit();
        break;
#endif
#if (GPT_SRTC_USED == STD_ON)
        case GPT_SRTC_MODULE:
            Gpt_SRtc_DeInit();
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour */
        break;
    }
    return;
}
#endif

/*================================================================================================*/

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief   Gpt driver Autosar independent and IP dependent function to change Ftm compare register value.
* @details Calls the Ftm function to change the Ftm compare register value at the next match.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     value         New Timeout period (in ticks) after which a notification shall occur (if
*                              enabled).
*
*/

FUNC (Std_ReturnType, GPT_CODE) Gpt_Ipw_ChangeNextTimeoutValue(P2CONST(Gpt_HwChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,
                                                               VAR(Gpt_ValueType, AUTOMATIC) value
                                                              )
{
    VAR(Std_ReturnType,AUTOMATIC) returnValue = (Std_ReturnType)E_NOT_OK;

#if (GPT_FTM_USED == STD_ON)
    if((uint8)GPT_FTM_MODULE == pHwChannelConfig->Gpt_uHwModule)
    {
        Gpt_Ftm_ChangeNextTimeoutValue(pHwChannelConfig->Gpt_uHwChannel, (uint32)value);
        returnValue =(Std_ReturnType)E_OK;
    }
#endif /*GPT_FTM_USED == STD_ON*/

    return returnValue;
}

#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */


#if (GPT_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/


/**
* @brief   This function changes the channel pre scaler.
* @details This function sets all channels pre scalers based on the input mode and IP type.
*
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     eClkMode            Channel clock mode. Please see Gpt_ClockModeType for more details.
*
*
*
*/
FUNC(void, GPT_CODE) Gpt_Ipw_SetClockMode
(
    P2CONST(Gpt_HwChannelConfigType,    AUTOMATIC,  GPT_APPL_CONST) pHwChannelConfig,
    VAR    (Gpt_ClockModeType,          AUTOMATIC)                  eClkMode
)
{
#if ((GPT_LPIT_USED == STD_ON) && (GPT_FTM_USED == STD_OFF) && (GPT_LPTMR_USED == STD_OFF))
    (void)eClkMode;
#else
#if (GPT_FTM_USED == STD_ON)
    VAR(Gpt_PrescalerType, AUTOMATIC) eFtmPrescaler;
#endif /*GPT_FTM_USED*/
#if (GPT_LPTMR_USED == STD_ON)
    VAR(Gpt_PrescalerType, AUTOMATIC) eLptmrPrescaler;
#endif /*GPT_LPTMR_USED*/
#endif

    switch(pHwChannelConfig->Gpt_uHwModule)
    {
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
        {
            if(GPT_CLOCKMODE_NORMAL == eClkMode)
            {
                eFtmPrescaler = pHwChannelConfig->Gpt_uPrescaler;
            }
            else
            {
                eFtmPrescaler = pHwChannelConfig->Gpt_uFtmPrescaler_Alternate;
            }
            Gpt_Ftm_SetClockMode(pHwChannelConfig->Gpt_uHwChannel, eFtmPrescaler);
        }
        break;
#endif /*GPT_FTM_USED*/
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
        {
            if(GPT_CLOCKMODE_NORMAL == eClkMode)
            {
                eLptmrPrescaler = pHwChannelConfig->Gpt_uLptmrPrescaler;
            }
            else
            {
                eLptmrPrescaler = pHwChannelConfig->Gpt_uLptmrPrescaler_Alternate;
            }
            Gpt_Lptmr_SetClockMode(eLptmrPrescaler);
        }
        break;
#endif /*GPT_LPTMR_USED*/

        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }
}
#endif

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/**
* @brief   Gpt driver Autosar start predeftimer hw.
* @details This function to start channel, which using predeftimer feature in the used configuration.
*          It determines the type of the HW channel (e.g. FTM, LPTMR, etc...) and calls the
*          appropriate IP function in order to initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @implements Gpt_Ipw_StartPredefTimer_Activity
* @violates @ref GPT_IPW_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Ipw_StartPredefTimer
(
    P2CONST(Gpt_ConfigType, AUTOMATIC,GPT_APPL_CONST) configPtr
)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channel;
    P2CONST(Gpt_HwPredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig;

    for(channel = 0U; channel < GPT_HW_PREDEFTIMER_NUM; channel++)
    {
        /** @violates @ref GPT_IPW_C_REF_4 MISRA 2004 Rule 17.4, Array indexing shall be the only allowed form of pointer */
        pHwChannelConfig = *((configPtr->Gpt_pChannelPredefConfigType)+channel);
        if(NULL_PTR != pHwChannelConfig)
        {
            switch(pHwChannelConfig->Gpt_u8HwModule)
            {
            #if (GPT_FTM_USED == STD_ON)
                case GPT_FTM_MODULE:
                {
                    Gpt_Ftm_StartPredefTimer(pHwChannelConfig->Gpt_u8HwChannel,  \
                                            pHwChannelConfig->Gpt_bFreezeEnable, \
                                            pHwChannelConfig->Gpt_uClockSource,  \
                                            pHwChannelConfig->Gpt_uPrescaler);
                }
                break;
            #endif /*GPT_FTM_USED = STD_ON*/
            #if (GPT_LPTMR_USED == STD_ON)
                case GPT_LPTMR_MODULE:
                {
                    Gpt_Lptmr_StartPredefTimer(pHwChannelConfig->Gpt_uClockSource, \
                                                pHwChannelConfig->Gpt_uPrescaler);
                }
                break;
            #endif /*GPT_LPTMR_USED == STD_ON*/
                default:
                    /*This switch branch is empty because it shall not be executed for normal behaviour*/
                break;
            }
        }
    }

    return;
}
/**
* @brief   Gpt driver Autosar get value of predeftimer hw.
* @details This function to start channel, which using predeftimer feature in the used configuration.
*          It determines the type of the HW channel (e.g. FTM, LPTMR, etc...) and calls the
*          appropriate IP function in order to initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @param[in]     TimeValuePtr        The pointer using for save current value of hardware channel
* @implements Gpt_Ipw_GetPredefTimerValue_Activity
*/
FUNC (void, GPT_CODE) Gpt_Ipw_GetPredefTimerValue
(
    P2CONST(Gpt_HwPredefChannelConfigType, AUTOMATIC,GPT_APPL_CONST) pHwChannelConfig,
    VAR(Gpt_PredefTimerType, AUTOMATIC) PredefTimer,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) TimeValuePtr
)
{
    switch(pHwChannelConfig->Gpt_u8HwModule)
    {
#if (GPT_FTM_USED == STD_ON)
        case GPT_FTM_MODULE:
        {
            *TimeValuePtr = Gpt_Ftm_GetPredefTimerValue(pHwChannelConfig->Gpt_u8HwChannel, PredefTimer);
        }
        break;
#endif
#if (GPT_LPTMR_USED == STD_ON)
        case GPT_LPTMR_MODULE:
        {
            *TimeValuePtr = Gpt_Lptmr_GetPredefTimerValue(PredefTimer);
        }
        break;
#endif
        default:
            /*This switch branch is empty because it shall not be executed for normal behaviour*/
        break;
    }

    return;
}

/**
* @brief   Gpt driver Autosar stop predeftimer hw.
* @details This function to start channel, which using predeftimer feature in the used configuration.
*          It determines the type of the HW channel (e.g. FTM, LPTMR, etc...) and calls the
*          appropriate IP function in order to initializes the hardware timer.
* @param[in]     pHwChannelConfig    Pointer to the channel configuration structure dependent by platform
* @implements Gpt_Ipw_StopPredefTimer_Activity
* @violates @ref GPT_IPW_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Ipw_StopPredefTimer
(
    P2CONST(Gpt_ConfigType, AUTOMATIC,GPT_APPL_CONST) configPtr
)
{
    VAR(Gpt_ChannelType, AUTOMATIC) channel;
    P2CONST(Gpt_HwPredefChannelConfigType, AUTOMATIC, GPT_APPL_CONST) pHwChannelConfig;

    for(channel = 0U; channel < GPT_HW_PREDEFTIMER_NUM; channel++)
    {
        /** @violates @ref GPT_IPW_C_REF_4 MISRA 2004 Rule 17.4, Array indexing shall be the only allowed form of pointer */
        pHwChannelConfig = *((configPtr->Gpt_pChannelPredefConfigType)+channel);
        if(NULL_PTR != pHwChannelConfig)
        {
            switch(pHwChannelConfig->Gpt_u8HwModule)
            {
            #if (GPT_FTM_USED == STD_ON)
                case GPT_FTM_MODULE:
                {
                    Gpt_Ftm_StopPredefTimer(pHwChannelConfig->Gpt_u8HwChannel);
                }
                break;
            #endif /* GPT_FTM_USED == STD_ON */

            #if (GPT_LPTMR_USED == STD_ON)
                case GPT_LPTMR_MODULE:
                {
                    (void)pHwChannelConfig;
                    Gpt_Lptmr_StopPredefTimer();
                }
                break;
            #endif /* GPT_LPTMR_USED == STD_ON */
                default:
                    /*This switch branch is empty because it shall not be executed for normal behaviour*/
                break;
            }
        }
    }

    return;
}

#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_IPW_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_IPW_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
