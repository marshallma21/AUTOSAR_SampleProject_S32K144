/**
*     @file       Crcu_Crcv2.h
*     @version    1.0.1
*
*     @brief      Crcu IPV layer header.
*     @details    This file is the Crcu low level driver header.
*
*     @addtogroup CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project              : AUTOSAR 4.2 MCAL
*     Platform             : ARM
*     Peripheral           : CRCV2
*     Dependencies         : none
*     
*     Autosar Version      : 4.2.2
*     Autosar Revision     : ASR_REL_4_2_REV_0002
*     Autosar Conf.Variant :
*     SW Version           : 1.0.1
*     Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*     
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
===================================================================================================*/
#ifndef CRCU_CRCV2_H
#define CRCU_CRCV2_H


#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_Crcv2_h_REF_1
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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Crcu_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_CRCV2_VENDOR_ID                    43
#define CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION     4
#define CRCU_CRCV2_AR_RELEASE_MINOR_VERSION     2
#define CRCU_CRCV2_AR_RELEASE_REVISION_VERSION  2
#define CRCU_CRCV2_SW_MAJOR_VERSION             1
#define CRCU_CRCV2_SW_MINOR_VERSION             0
#define CRCU_CRCV2_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crcu_Crcv2.h file and CDD_Crcu_Cfg.h header file are of the same vendor */
#if (CRCU_CRCV2_VENDOR_ID != CRCU_CFG_VENDOR_ID)
    #error "Crcu_Crcv2.h and CDD_Crcu_Cfg.h have different Vendor ids"
#endif
/* Check if Crcu_Crcv2.h file and CDD_Crcu_Cfg.h header file are of the same Autosar version */
#if ((CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION    != CRCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_CRCV2_AR_RELEASE_MINOR_VERSION    != CRCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_CRCV2_AR_RELEASE_REVISION_VERSION != CRCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Crcv2.h and CDD_Crcu_Cfg.h are different"
#endif
/* Check if Crcu_Crcv2.h file and CDD_Crcu_Cfg.h header file are of the same Software version */
#if ((CRCU_CRCV2_SW_MAJOR_VERSION != CRCU_CFG_SW_MAJOR_VERSION) || \
     (CRCU_CRCV2_SW_MINOR_VERSION != CRCU_CFG_SW_MINOR_VERSION) || \
     (CRCU_CRCV2_SW_PATCH_VERSION != CRCU_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Crcv2.h and CDD_Crcu_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
#define CRCU_START_SEC_CODE
/* @violates @ref Crcu_Crcv2_h_REF_1 */
#include "Crcu_MemMap.h"

extern FUNC(Crcu_Crcv2_ChannelAddressType, CRCU_CODE) Crcu_Crcv2_SetChannelConfig
(
    VAR    (Crcu_Crcv2_ChannelType,       AUTOMATIC                 ) channel,
    P2CONST(Crcu_Crcv2_ChannelConfigType, AUTOMATIC, CRCU_APPL_CONST) channelConfigPtr
);

extern FUNC(void, CRCU_CODE) Crcu_Crcv2_SetChannelSeed
(
    VAR(Crcu_Crcv2_ChannelType, AUTOMATIC) channel,
    VAR(Crcu_Crcv2_ValueType,   AUTOMATIC) seed
);

extern FUNC(Crcu_Crcv2_ValueType, CRCU_CODE) Crcu_Crcv2_SyncCalculateChannelCrc
(
    VAR    (Crcu_Crcv2_ChannelType, AUTOMATIC                 ) channel,
    P2CONST(uint8,                  AUTOMATIC, CRCU_APPL_CONST) u8DataPtr,
    VAR    (uint32,                 AUTOMATIC                 ) u32Length
);

extern FUNC(Crcu_Crcv2_ValueType, CRCU_CODE) Crcu_Crcv2_GetChannelCrc
(
    VAR(Crcu_Crcv2_ChannelType, AUTOMATIC) channel
);

#define CRCU_STOP_SEC_CODE
/* @violates @ref Crcu_Crcv2_h_REF_1 */
#include "Crcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CRCU_CRCV2_H */

/** @} */
