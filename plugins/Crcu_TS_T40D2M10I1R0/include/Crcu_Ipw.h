/**
*     @file         Crcu_Ipw.h
*     @version      1.0.1
* 
*     @brief        AUTOSAR Crcu IPW layer header file.
*     @details      Interface between the high level driver and the low level driver (IP dependent).
*     
*     @addtogroup   CRCU_MODULE
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
#ifndef CRCU_IPW_H
#define CRCU_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_Ipw_h_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to 
*          a function-like macro.
*          Function like macros are used to reduce code complexity.
*
* @section Crcu_Ipw_h_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
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
#include "CDD_Crcu_Cfg.h"
#include "Crcu_Crcv2.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_IPW_VENDOR_ID                      43
#define CRCU_IPW_AR_RELEASE_MAJOR_VERSION       4
#define CRCU_IPW_AR_RELEASE_MINOR_VERSION       2
#define CRCU_IPW_AR_RELEASE_REVISION_VERSION    2
#define CRCU_IPW_SW_MAJOR_VERSION               1
#define CRCU_IPW_SW_MINOR_VERSION               0
#define CRCU_IPW_SW_PATCH_VERSION               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crcu_Ipw.h file and CDD_Crcu_Cfg.h header file are of the same vendor */
#if (CRCU_IPW_VENDOR_ID != CRCU_CFG_VENDOR_ID)
    #error "Crcu_Ipw.h and CDD_Crcu_Cfg.h have different Vendor ids"
#endif
/* Check if Crcu_Ipw.h file and CDD_Crcu_Cfg.h header file are of the same Autosar version */
#if ((CRCU_IPW_AR_RELEASE_MAJOR_VERSION    != CRCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_MINOR_VERSION    != CRCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_REVISION_VERSION != CRCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Ipw.h and CDD_Crcu_Cfg.h are different"
#endif
/* Check if Crcu_Ipw.h file and CDD_Crcu_Cfg.h header file are of the same Software version */
#if ((CRCU_IPW_SW_MAJOR_VERSION != CRCU_CFG_SW_MAJOR_VERSION) || \
     (CRCU_IPW_SW_MINOR_VERSION != CRCU_CFG_SW_MINOR_VERSION) || \
     (CRCU_IPW_SW_PATCH_VERSION != CRCU_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Ipw.h and CDD_Crcu_Cfg.h are different"
#endif

/* Check if Crcu_Ipw.h file and Crcu_Crcv2.h header file are of the same vendor */
#if (CRCU_IPW_VENDOR_ID != CRCU_CRCV2_VENDOR_ID)
    #error "Crcu_Ipw.h and Crcu_Crcv2.h have different vendor ids"
#endif
/* Check if Crcu_Ipw.h file and Crcu_Crcv2.h header file are of the same Autosar version */
#if ((CRCU_IPW_AR_RELEASE_MAJOR_VERSION    != CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_MINOR_VERSION    != CRCU_CRCV2_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_IPW_AR_RELEASE_REVISION_VERSION != CRCU_CRCV2_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Ipw.h and Crcu_Crcv2.h are different"
#endif
/* Check if Crcu_Ipw.h file and Crcu_Crcv2.h header file are of the same Software version */
#if ((CRCU_IPW_SW_MAJOR_VERSION != CRCU_CRCV2_SW_MAJOR_VERSION) || \
     (CRCU_IPW_SW_MINOR_VERSION != CRCU_CRCV2_SW_MINOR_VERSION) || \
     (CRCU_IPW_SW_PATCH_VERSION != CRCU_CRCV2_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Ipw.h and Crcu_Crcv2.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Crcu_Ipw_Init
* @details      CRCU Init wrapper function
* 
* @param[in]    pCrcuConfig - Pointer to the Crcu driver configuration structure
* 
* @return       void
*/
#if (STD_OFF == CRCU_DMA_USED)
    /** @violates @ref Crcu_Ipw_h_REF_1 A function should be used in preference to a function-like macro */
    #define Crcu_Ipw_Init(pCrcuConfig)
#endif

/**
* @brief        Crcu_Ipw_SetChannelConfig
* @details      Selects which CRC engine is going to be configured
* 
* @param[in]    channel          - CRC Hw channel
* @param[in]    channelConfigPtr - Pointer to channel configuration data
*
* @param[out]   retValue         - Pointer to CRC data register address
* 
* @return       void
*/
/** @violates @ref Crcu_Ipw_h_REF_1 A function should be used in preference to a function-like macro */
#define Crcu_Ipw_SetChannelConfig(channel, channelConfigPtr, retValue)       \
do                                                                           \
{                                                                            \
    (retValue) = Crcu_Crcv2_SetChannelConfig((channel), (channelConfigPtr)); \
}                                                                            \
while(0)

/**
* @brief        Crcu_Ipw_SetChannelSeed
* @details      Selects which CRC channel is going to be written by new Seed value
* 
* @param[in]    channel - CRC Hw channel
* @param[in]    seed    - Input seed for CRC value computation
* 
* @return       void
*/
/** @violates @ref Crcu_Ipw_h_REF_1 A function should be used in preference to a function-like macro */
#define Crcu_Ipw_SetChannelSeed(channel, seed)    \
do                                                \
{                                                 \
    Crcu_Crcv2_SetChannelSeed((channel), (seed)); \
}                                                 \
while(0)
    
    
/**
* @brief        Crcu_Ipw_CalculateChannelCrc
* @details      Selects which CRC engine is going to be feeded by data
* 
* @param[in]    channel - CRC Hw channel
* @param[in]    pData   - Pointer to data for CRC value computation
* @param[in]    length  - Length of data for CRC value computation
*
* @param[out]   retValue - CRC result
* 
* @return       void
*/
/** @violates @ref Crcu_Ipw_h_REF_1 A function should be used in preference to a function-like macro */
#define Crcu_Ipw_SyncCalculateChannelCrc(channel, pData, length, retValue)         \
do                                                                                 \
{                                                                                  \
    (retValue) = Crcu_Crcv2_SyncCalculateChannelCrc((channel), (pData), (length)); \
}                                                                                  \
while(0)

/**
* @brief        Crcu_Ipw_GetChannelCrc
* @details      Selects which is the CRC engine to read the signature from
* 
* @param[in]    channel - CRC Hw channel
*
* @param[out]   retValue - Contains the computed CRC
* 
* @return       void
*/
/** @violates @ref Crcu_Ipw_h_REF_1 A function should be used in preference to a function-like macro */
#define Crcu_Ipw_GetChannelCrc(channel, retValue)     \
do                                                    \
{                                                     \
    (retValue) = Crcu_Crcv2_GetChannelCrc((channel)); \
}                                                     \
while(0)



/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == CRCU_DMA_USED)

#define CRCU_START_SEC_CODE
/** @violates @ref Crcu_Ipw_h_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

extern FUNC(void, CRCU_CODE) Crcu_Ipw_Init
(
    P2CONST(Crcu_ConfigType, AUTOMATIC, CRCU_APPL_CONST) pConfigPtr
);

extern FUNC(void, CRCU_CODE) Crcu_Ipw_AsyncCalculateChannelCrc
(
    VAR    (Crcu_Crcv2_ChannelType, AUTOMATIC                 ) crcChannel,
    VAR    (Mcl_ChannelType,        AUTOMATIC                 ) dmaChannel,
    P2CONST(uint8,                  AUTOMATIC, CRCU_APPL_CONST) u8DataPtr,
    VAR    (uint32,                 AUTOMATIC                 ) u32Length,
    VAR    (uint8,                  AUTOMATIC                 ) u8NumBytesPerDmaTransfer
);

#define CRCU_STOP_SEC_CODE
/** @violates @ref Crcu_Ipw_h_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

#endif /* (STD_ON == CRCU_DMA_USED) */

#ifdef __cplusplus
}
#endif

#endif /* CRCU_IPW_H */

/** @} */
