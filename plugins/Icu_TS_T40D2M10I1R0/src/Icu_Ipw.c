/**
*     @file            Icu_Ipw.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - ICU Driver LLD source file.
*     @details ICU driver source file, containing the LLD variables and functions that are used by
*              the ICU driver.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform ARM
*     Peripheral FTM PORT_CI LPIT LPTMR
*     Dependencies none
*
*     Autosar Version 4.2.2
*     Autosar Revision ASR_REL_4_2_REV_0002
*     Autosar ConfVariant
*     SWVersion 1.0.1
*     BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_IPW_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*          before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
*          is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_IPW_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_IPW_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.

* @section Icu_IPW_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, could be made static
*          The respective code could not be made static because of layers architecture design of
*          the driver.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

#include "Icu_Cfg.h"

#include "Icu_Ipw.h"
#include "Icu_Ftm.h"
#include "Icu_Port_Ci.h"
#include "Icu_LPit.h"
#include "Icu_Lptmr.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_VENDOR_ID_C                     43
/*
* @violates @ref Icu_IPW_c_REF_3 Identifier clash.
*/
#define ICU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/*
* @violates @ref Icu_IPW_c_REF_3 Identifier clash.
*/
#define ICU_IPW_AR_RELEASE_MINOR_VERSION_C      2
/*
* @violates @ref Icu_IPW_c_REF_3 Identifier clash.
*/
#define ICU_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define ICU_IPW_SW_MAJOR_VERSION_C              1
#define ICU_IPW_SW_MINOR_VERSION_C              0
#define ICU_IPW_SW_PATCH_VERSION_C              1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Ipw.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and Icu_Cfg header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
#error "Icu_Ipw.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Ipw.c are different"
    #endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_Cfg.h and Icu_Ipw.c are different"
#endif

/* Check if source file and Icu_Ipw header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif
/* Check if source file and Icu_Ipw header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif

/* Check if source file and Icu_Ftm.h file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_FTM_VENDOR_ID)
#error "Icu_Ipw.c and Icu_Ftm.h have different vendor IDs"
#endif

/* Check if source file and Icu_Ftm header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_FTM_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Ftm.h are different"
    #endif

/* Check if source file and Icu_Ftm header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_FTM_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_FTM_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_FTM_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Icu_Ftm.h are different"
#endif

/* Check if source file and Icu_Port_Ci header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_PORT_CI_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Port_Ci.h have different vendor IDs"
#endif
    /* Check if source file and Icu_Port_Ci header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_PORT_CI_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Port_Ci.h are different"
#endif
/* Check if source file andIcu_Port_Ci header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_PORT_CI_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_PORT_CI_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_PORT_CI_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw.c and Icu_Port_Ci.h are different"
#endif

/* Check if source file and Icu_LPit header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_LPIT_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_LPit.h have different vendor IDs"
#endif
    /* Check if source file and Icu_LPit header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_LPIT_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_LPIT_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_LPIT_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_LPit.h are different"
#endif
/* Check if source file andIcu_LPit header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_LPIT_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_LPIT_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_LPIT_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw.c and Icu_LPit.h are different"
#endif

/* Check if source file and Icu_Lptmr header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_LPTMR_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Lptmr.h have different vendor IDs"
#endif
    /* Check if source file and Icu_Lptmr header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_LPTMR_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Lptmr.h are different"
#endif
/* Check if source file andIcu_Lptmr header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_LPTMR_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_LPTMR_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_LPTMR_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw.c and Icu_Lptmr.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/


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


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_IPW_c_REF_1 only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_IPW_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

 /**
 * @brief      Icu_Ipw_Init
 * @details    Initialize a hardware ICU channel
 *
 * @param[in]  pIpConfig - Pointer to ICU top configuration structure
 *
 * @return void
 *
 * @pre        Icu_DeInit must be called before.
 *
 */
FUNC (void, ICU_CODE) Icu_Ipw_Init
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    /* FTM Channel Configuration */
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        Icu_Ftm_Init(pIpConfig->pFtmIpConfig);
    }

    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pPort_CiIpConfig)
    {
        Icu_Port_Ci_Init(pIpConfig->pPort_CiIpConfig);
    }

    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pLPitIpConfig)
    {
        Icu_LPit_Init(pIpConfig->pLPitIpConfig);
    }

    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pLptmrIpConfig)
    {
        Icu_Lptmr_Init(pIpConfig->pLptmrIpConfig);
    }
}

 #if (ICU_DE_INIT_API == STD_ON)
/**
* @brief              Icu_Ipw_DeInit
* @details            De-initialize ICU hardware channel
*
* @param[in]          pIpConfig - Pointer to ICU top configuration structure
*
* @return void
*
* @pre                Icu_Init must be called before.
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_DeInit
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    /* FTM Channel Configuration */
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        Icu_Ftm_DeInit(pIpConfig->pFtmIpConfig);
    }
    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pPort_CiIpConfig)
    {
        Icu_Port_Ci_DeInit(pIpConfig->pPort_CiIpConfig);
    }
    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pLPitIpConfig)
    {
        Icu_LPit_DeInit(pIpConfig->pLPitIpConfig);
    }
    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pLptmrIpConfig)
    {
        Icu_Lptmr_DeInit(pIpConfig->pLptmrIpConfig);
    }
}
#endif /* ICU_DE_INIT_API == STD_ON */

#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief      Icu_Ipw_SetSleepMode
* @details    Set sleep mode
*
* @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
* @param[in]      pIpConfig      - Pointer to ICU top configuration structure
*
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_SetSleepMode
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC, ICU_APPL_CONST) pFtmChannelConfig;

    P2CONST(Icu_LPit_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC, ICU_APPL_CONST)  pLPitChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC, ICU_APPL_CONST) pLptmrChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC, ICU_APPL_CONST) pPort_CiChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_SetSleepMode((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;

        Icu_Port_Ci_SetSleepMode((Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(nHardwareChannel));
    }
    else if (ICU_LPIT_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        Icu_LPit_SetSleepMode((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        Icu_Lptmr_SetSleepMode((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}

/**
* @brief      Icu_Ipw_SetNormalMode
* @details    Set normal mode
*
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
*
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_SetNormalMode
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pPort_CiChannelConfig;

    P2CONST(Icu_LPit_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pLPitChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_SetNormalMode((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;

        Icu_Port_Ci_SetNormalMode((Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(nHardwareChannel));
    }
    else if (ICU_LPIT_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        Icu_LPit_SetNormalMode((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        Icu_Lptmr_SetNormalMode((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}
#endif  /* ICU_SET_MODE_API */


/**
* @brief      Icu_Ipw_SetActivationCondition
* @details
*
* @param[in]      hwChannel     - The index of ICU channel for current configuration structure
* @param[in]      Activation    - the type of activation for the ICU channel.
* @param[in]      Mode            - the measurement mode of the channel
*
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_SetActivationCondition
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR(Icu_ActivationType,        AUTOMATIC)                 Activation,
    VAR(Icu_MeasurementModeType,   AUTOMATIC)                 Mode,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pPort_CiChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;
    (void) Mode;

    /* Ftm Channel Configuration */
    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        VAR(Ftm_IcuActivationType, AUTOMATIC)startEdge;
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        if (ICU_FALLING_EDGE == Activation)
        {
            startEdge = FTM_FALLING_EDGE;
        }
        else if (ICU_RISING_EDGE == Activation)
        {
            startEdge = FTM_RISING_EDGE;
        }
        else
        {
            startEdge = FTM_BOTH_EDGES;
        }
        Icu_Ftm_SetActivationCondition
        (
            (Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel),
            (Ftm_IcuActivationType)startEdge
        );
    }
    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        VAR(Icu_Port_Ci_ActivationType, AUTOMATIC)startEdge;
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;

        if (ICU_FALLING_EDGE == Activation)
        {
            startEdge = PORT_CI_FALLING_EDGE;
        }
        else if (ICU_RISING_EDGE == Activation)
        {
            startEdge = PORT_CI_RISING_EDGE;
        }
        else
        {
            startEdge = PORT_CI_BOTH_EDGES;
        }
        Icu_Port_Ci_SetActivationCondition
        (
            (Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(nHardwareChannel),
            (Icu_Port_Ci_ActivationType)startEdge
        );
    }
    else
    {
        VAR(Icu_Lptmr_ActivationType, AUTOMATIC)startEdge;
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        if (ICU_FALLING_EDGE == Activation)
        {
            startEdge = LPTMR_FALLING_EDGE;
        }
        else
        {
            startEdge = LPTMR_RISING_EDGE;
        }
        Icu_Lptmr_SetActivationCondition
        (
            (Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel),
            (Icu_Lptmr_ActivationType)startEdge
        );
    }
}

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu_Ipw_GetInputState
* @details    Service that returns the state of the ICU driver
*
* @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
*
* @return Icu_InputStateType
* @retval   ICU_ACTIVE          An active edge has been detected
* @retval   ICU_IDLE            No active edge has been detected since the cast call to
*                               Icu_Ipw_Init or Icu_Ipw_GetInputState
*
*/

FUNC (Icu_InputStateType, ICU_CODE) Icu_Ipw_GetInputState
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pPort_CiChannelConfig;

    P2CONST(Icu_LPit_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pLPitChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;

    VAR(Icu_InputStateType, AUTOMATIC) tempReturn = ICU_IDLE;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        if (Icu_Ftm_GetInputState((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;

        if (Icu_Port_Ci_GetInputState((Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    else if (ICU_LPIT_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        if (Icu_LPit_GetInputState((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        if (Icu_Lptmr_GetInputState((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    return (tempReturn);
}

#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_StartTimestamp
(
    VAR(Icu_ChannelType,                AUTOMATIC)                  nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType,      AUTOMATIC, ICU_APPL_CONST)  pIpConfig,
    VAR(boolean,                        AUTOMATIC)                  bDmaSupport
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                  nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                  u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST)  pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC, ICU_APPL_CONST)  pFtmChannelConfig;
    P2CONST(Icu_LPit_IpConfigType,      AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)  pLPitChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        /*Get Ftm Hardware Channel */
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_StartTimestamp((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel), (boolean)bDmaSupport);
    }
    else
    {
        /*Get LPit Hardware Channel */
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        Icu_LPit_StartTimestamp((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel), (boolean)bDmaSupport);
    }
}

FUNC(void, ICU_CODE) Icu_Ipw_StopTimestamp
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                  nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                  u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST)  pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC, ICU_APPL_CONST)  pFtmChannelConfig;
    P2CONST(Icu_LPit_IpConfigType,      AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)  pLPitChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        /*Get Ftm Hardware Channel */
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_StopTimestamp((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else
    {
        /*Get LPit Hardware Channel */
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        Icu_LPit_StopTimestamp((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel));
    }
}

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
FUNC(uint32, ICU_CODE) Icu_Ipw_GetStartAddress
(
    VAR(Icu_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;
    VAR(uint32, AUTOMATIC) u32Saddress;

    /*Get Ftm Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    pFtmIpChConfig = pIpConfig->pFtmIpConfig;
    pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

    u32Saddress = Icu_Ftm_GetStartAddress((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    return (u32Saddress);
}
#endif  /* ICU_TIMESTAMP_USES_DMA == STD_ON */
#endif  /* ICU_TIMESTAMP_API == STD_ON */

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_ResetEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;

    /*Get Ftm Hardware Channel */
    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_ResetEdgeCount((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
     }
     else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        Icu_Lptmr_ResetEdgeCount((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}

FUNC(void, ICU_CODE) Icu_Ipw_EnableEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;

    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;

    /*Get Ftm Hardware Channel */
    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
       u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
       pFtmIpChConfig = pIpConfig->pFtmIpConfig;
       pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
       nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

       Icu_Ftm_EnableEdgeCount((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else
    {
       u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
       pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
       pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
       nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

       Icu_Lptmr_EnableEdgeCount((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}

FUNC(void, ICU_CODE) Icu_Ipw_DisableEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;

    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;

    /*Get Ftm Hardware Channel */
    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
       u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
       pFtmIpChConfig = pIpConfig->pFtmIpConfig;
       pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
       nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

       Icu_Ftm_DisableEdgeCount((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else
    {
       u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
       pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
       pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
       nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

       Icu_Lptmr_DisableEdgeCount((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}

FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Ipw_GetEdgeNumbers
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;
    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pLptmrChannelConfig;
    VAR(Icu_EdgeNumberType,             AUTOMATIC)                 EdgeNumber;

    /*Get Ftm Hardware Channel */
    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
         u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
         pFtmIpChConfig = pIpConfig->pFtmIpConfig;
         pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
         nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

         EdgeNumber = Icu_Ftm_GetEdgeNumbers((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else
    {
         u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
         pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
         pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
         nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

         EdgeNumber = Icu_Lptmr_GetEdgeNumbers((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
    return (EdgeNumber);
}
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief          Icu_Ipw_EnableEdgeDetection
* @details        Retrieve the number of edges
*
* @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
* @return         void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_EnableEdgeDetection
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pPort_CiChannelConfig;

    P2CONST(Icu_LPit_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pLPitChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pLptmrChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_EnableEdgeDetection((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;

        Icu_Port_Ci_EnableEdgeDetection((Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(nHardwareChannel));
    }
    else if (ICU_LPIT_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        Icu_LPit_EnableEdgeDetection((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        Icu_Lptmr_EnableEdgeDetection((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief      Icu_Ipw_DisableEdgeDetection
* @details    Retrieve the number of edges
*
* @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
*
* @return         void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_DisableEdgeDetection
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pPort_CiChannelConfig;

    P2CONST(Icu_LPit_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pLPitChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pLptmrChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

        Icu_Ftm_DisableEdgeDetection((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    }
    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;

        Icu_Port_Ci_DisableEdgeDetection((Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(nHardwareChannel));
    }
    else if (ICU_LPIT_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;

        Icu_LPit_DisableEdgeDetection((Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;

        Icu_Lptmr_DisableEdgeDetection((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(nHardwareChannel));
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
 /** @violates @ref Icu_IPW_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(boolean, ICU_CODE) Icu_Ipw_Get_Overflow
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;
    VAR(boolean,                        AUTOMATIC)                 bGetOverflow;

    /*Get Ftm Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    pFtmIpChConfig = pIpConfig->pFtmIpConfig;
    pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

    bGetOverflow = (boolean)Icu_Ftm_GetOverflow((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    return bGetOverflow;
}
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_CAPTURERGISTER_API == STD_ON)
/** @violates @ref Icu_IPW_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Icu_ValueType, ICU_CODE) Icu_Ipw_GetCaptureRegisterValue
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;
    VAR(Icu_ValueType,                  AUTOMATIC)                 CaptureRegisterValue;

    /*Get Ftm Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    pFtmIpChConfig = pIpConfig->pFtmIpConfig;
    pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

    CaptureRegisterValue = (Icu_ValueType)Icu_Ftm_GetCaptureRegisterValue((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
    return (CaptureRegisterValue);
}
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_Ipw_StartSignalMeasurement
* @details    Starts the signal measurement service
*
* @param[in]      hwChannel     - The index of ICU channel for current configuration structure
* @param[in]      startEdge     - activation edge of the signal measurement
* @param[in]      measProperty  - the property that will be measured on the channel
*
* @return void
*
*/

FUNC (void, ICU_CODE) Icu_Ipw_StartSignalMeasurement
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(Icu_ActivationType,                   AUTOMATIC)      startEdge,
    VAR(Icu_SignalMeasurementPropertyType,    AUTOMATIC)      measProperty,
    VAR(boolean,                              AUTOMATIC)      bDmaSupport
)
{
    Ftm_IcuActivationType activation = FTM_RISING_EDGE;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    pFtmIpChConfig = pIpConfig->pFtmIpConfig;
    pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];

    /*Get FTM Hardware Channel */
    nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

    /* Set Default Start Edge, signal can be start measured either by falling edge or
    rising edge */
    if (ICU_FALLING_EDGE == startEdge)
    {
        activation = FTM_FALLING_EDGE;
    }
    else if (ICU_RISING_EDGE == startEdge)
    {
        activation = FTM_RISING_EDGE;
    }
    else
    {
        activation = FTM_BOTH_EDGES;
    }

    /* Start Signal Measurement */
    Icu_Ftm_StartSignalMeasurement
    (
        (Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel),
        (Ftm_IcuActivationType)activation,
        (Ftm_IcuSignalMeasurementPropertyType)measProperty,
        (boolean)bDmaSupport
    );
}

FUNC (void, ICU_CODE) Icu_Ipw_StopSignalMeasurement
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC,ICU_APPL_CONST)  pFtmChannelConfig;

    /*Get Ftm Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    pFtmIpChConfig = pIpConfig->pFtmIpConfig;
    pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

    Icu_Ftm_StopSignalMeasurement((Ftm_IcuChannelType)ICU_FTM_CHANNELS(nHardwareChannel));
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)

#if (ICU_VALIDATE_PARAMS == STD_ON)
FUNC (Icu_ChannelType, ICU_CODE) Icu_Ipw_ValidateGetInputLevel
(
    VAR         (Icu_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType, AUTOMATIC) nChannelInput;
    VAR(uint8,                         AUTOMATIC)                     u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,      AUTOMATIC, ICU_APPL_CONST)     pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)     pFtmChannelConfig;

    P2CONST(Icu_Port_Ci_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pPort_CiIpChConfig;
    P2CONST(Icu_Port_Ci_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) pPort_CiChannelConfig;
    
    P2CONST(Icu_LPit_IpConfigType,      AUTOMATIC, ICU_APPL_CONST)    pLPitIpChConfig;
    P2CONST(Icu_LPit_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)    pLPitChannelConfig;

    P2CONST(Icu_Lptmr_IpConfigType,      AUTOMATIC, ICU_APPL_CONST)   pLptmrIpChConfig;
    P2CONST(Icu_Lptmr_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)   pLptmrChannelConfig;

    if (ICU_FTM_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pFtmIpChConfig = pIpConfig->pFtmIpConfig;
        pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;
    }

    else if (ICU_PORT_CI_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pPort_CiIpChConfig = pIpConfig->pPort_CiIpConfig;
        pPort_CiChannelConfig = &(*pPort_CiIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)pPort_CiChannelConfig->nHwChannel;
    }

    else if (ICU_LPTMR_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLPitIpChConfig = pIpConfig->pLPitIpConfig;
        pLPitChannelConfig = &(*pLPitIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)pLPitChannelConfig->nHwChannel;
    }
    
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pLptmrIpChConfig = pIpConfig->pLptmrIpConfig;
        pLptmrChannelConfig = &(*pLptmrIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)pLptmrChannelConfig->nHwChannel;
    }

    return nChannelInput;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */


FUNC(Icu_LevelType, ICU_CODE) Icu_Ipw_GetInputLevel
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_LevelType,                  AUTOMATIC)                 InputLevel;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_Ftm_IpConfigType,       AUTOMATIC, ICU_APPL_CONST) pFtmIpChConfig;
    P2CONST(Icu_Ftm_ChannelConfigType,  AUTOMATIC, ICU_APPL_CONST) pFtmChannelConfig;

    /*Get Ftm Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    pFtmIpChConfig = pIpConfig->pFtmIpConfig;
    pFtmChannelConfig = &(*pFtmIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)pFtmChannelConfig->nHwChannel;

    InputLevel = (Icu_LevelType)(Icu_Ftm_GetInputLevel((Ftm_IcuChannelType)nHardwareChannel));
    
    return (InputLevel);
}
#endif   /* ICU_GET_INPUT_LEVEL_API == STD_ON */



#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      This function changes the global prescaler.
* @details    This function sets the module prescalers based on the input mode.
*
* @param[in]  Icu_IPW_GlobalConfiguration - The index of ICU channel for current
*                                            configuration structure
* @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
*
* @return void
*/
/*================================================================================================*/

FUNC (void, ICU_CODE) Icu_Ipw_SetClockMode
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(Icu_SelectPrescalerType,   AUTOMATIC)                 Prescaler
)
{
    VAR(uint8, AUTOMATIC) u8hwModuleNo;
    VAR(uint8,  AUTOMATIC) u8srcClk;
    VAR(uint8, AUTOMATIC) u8prescaler;
    VAR(uint32, AUTOMATIC) u32GlobalConfigPrescale;
    VAR(uint16, AUTOMATIC) u16GlobalConfigClkSrc;

    /* Set ClockMode for Ftm Channel */
    if (NULL_PTR != pIpConfig->pFtmIpConfig)
    {
        u16GlobalConfigClkSrc = (uint16)(pIpConfig->pFtmIpConfig->IcuFtmGlobalConfiguration->Icu_Ftm_GlobalConfigClkSrc);
        if (ICU_NORMAL_CLOCK_MODE == Prescaler)
        {
            u32GlobalConfigPrescale = (uint32)(pIpConfig->pFtmIpConfig->IcuFtmGlobalConfiguration->Icu_Ftm_GlobalConfigPrescale);
        }
        else
        {
            u32GlobalConfigPrescale = (uint32)(pIpConfig->pFtmIpConfig->IcuFtmGlobalConfiguration->Icu_Ftm_GlobalConfigAltPrescale);
        }

        for (u8hwModuleNo = 0U; u8hwModuleNo < ICU_NUM_FTM_HW_MODULE_U8; u8hwModuleNo++)
        {
            u8srcClk = (uint8)(u16GlobalConfigClkSrc & ICU_FTM_SRC_CLK_MASK_U16 );
            u8prescaler = (uint8)(u32GlobalConfigPrescale & ICU_FTM_PRESCALER_MASK_U32);
            u16GlobalConfigClkSrc = u16GlobalConfigClkSrc >> ICU_FTM_CLK_CONFIG_WIDTH_U32;
            u32GlobalConfigPrescale = u32GlobalConfigPrescale >> ICU_FTM_PRES_CONFIG_WIDTH_U32;

            if (u8srcClk != (uint8)0U)
            {
                Icu_Ftm_SetPrescaler(u8hwModuleNo, u8prescaler);
            }
        }
    }
}

#endif /* ICU_DUAL_CLOCK_MODE_API == STD_ON */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_IPW_c_REF_1 only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_IPW_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
