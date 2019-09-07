/**
*     @file         CDD_Crcu.h
*     @version      1.0.1
*
*     @brief        AUTOSAR Crcu driver header file.
*     @details      Crcu driver header file, containing the API specification and other variables
*                   and functions that are exported by the Crcu driver.
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

#ifndef CDD_CRCU_H
#define CDD_CRCU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_h_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported for external identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
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

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_VENDOR_ID                      43
#define CRCU_MODULE_ID                      255
#define CRCU_AR_RELEASE_MAJOR_VERSION       4
#define CRCU_AR_RELEASE_MINOR_VERSION       2
/** @violates @ref Crcu_h_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_AR_RELEASE_REVISION_VERSION    2
#define CRCU_SW_MAJOR_VERSION               1
#define CRCU_SW_MINOR_VERSION               0
#define CRCU_SW_PATCH_VERSION               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if CDD_Crcu.h file and CDD_Crcu_Cfg.h header file are of the same vendor */
#if (CRCU_VENDOR_ID != CRCU_CFG_VENDOR_ID)
    #error "CDD_Crcu.h and CDD_Crcu_Cfg.h have different Vendor ids"
#endif
/* Check if CDD_Crcu.h file and CDD_Crcu_Cfg.h header file are of the same Autosar version */
#if ((CRCU_AR_RELEASE_MAJOR_VERSION    != CRCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_AR_RELEASE_MINOR_VERSION    != CRCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_AR_RELEASE_REVISION_VERSION != CRCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crcu.h and CDD_Crcu_Cfg.h are different"
#endif
/* Check if CDD_Crcu.h file and CDD_Crcu_Cfg.h header file are of the same Software version */
#if ((CRCU_SW_MAJOR_VERSION != CRCU_CFG_SW_MAJOR_VERSION) || \
     (CRCU_SW_MINOR_VERSION != CRCU_CFG_SW_MINOR_VERSION) || \
     (CRCU_SW_PATCH_VERSION != CRCU_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crcu.h and CDD_Crcu_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief    ID of CRC Instance
* @details  Parameters used when raising an error/exception
* */
#define CRCU_INSTANCE_ID                            (0U)

/**
* @brief    API service ID for Crcu_Init function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_INIT_ID                                (1U)

/**
* @brief    API service ID for Crcu_SetChannelConfig function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_SETCHANNELCONFIG_ID                    (2U)

/**
* @brief    API service ID for Crcu_SetChannelSeed function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_SETCHANNELSEED_ID                      (3U)

/**
* @brief    API service ID for Crcu_SyncCalculateChannelCrc function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_SYNCCALCULATECHANNELCRC_ID             (4U)

/**
* @brief    API service ID for Crcu_AsyncCalculateChannelCrc function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_ASYNCCALCULATECHANNELCRC_ID            (5U)

/**
* @brief    API service ID for Crcu_GetChannelCrc function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_GETCHANNELCRC_ID                       (6U)

/**
* @brief    API service ID for Crcu_GetVersionInfo function
* @details  Parameters used when raising an error/exception
* */
#define CRCU_GETVERSIONINFO_ID                      (10U)

/**
* @brief        API service is called before driver is initialized
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_UNINIT                               (1U)

/**
* @brief        API service is called with wrong channel identifier
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_INVALID_CHANNEL                      (2U)

/**
* @brief        API service is called with wrong channel configuration identifier
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_INVALID_CHANNEL_CONFIG               (3U)

/**
* @brief        API service is called with NULL pointer parameter
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_INVALID_POINTER                      (4U)

/**
* @brief        API service is called with length parameter set to zero
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_INVALID_LENGTH                       (5U)

/**
* @brief        API service is called without having a Dma channel configured
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_DMA_CH_NOT_CONFIGURED                (6U)

/**
* @brief        API channel service is called while another channel service
*               is running on the same channel
* @details      Parameter is used when raising a Det error
* @implements   Crcu_ErrorIds_define
**/
#define CRCU_E_CHANNEL_BUSY                         (7U)

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
#define CRCU_START_SEC_CODE
/** @violates @ref Crcu_h_REF_1 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

extern FUNC(void, CRCU_CODE) Crcu_Init
(
    P2CONST(Crcu_ConfigType, AUTOMATIC, CRCU_APPL_CONST) Crcu_ConfigPtr
);

extern FUNC(Crcu_ChannelAddressType, CRCU_CODE) Crcu_SetChannelConfig
(
    VAR(Crcu_ChannelIdType,       AUTOMATIC) Crcu_ChannelId,
    VAR(Crcu_ChannelConfigIdType, AUTOMATIC) Crcu_ChannelConfigId
);

extern FUNC(void, CRCU_CODE) Crcu_SetChannelSeed
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) Crcu_ChannelId,
    VAR(Crcu_ValueType,     AUTOMATIC) Crcu_Seed
);

extern FUNC(Crcu_ValueType, CRCU_CODE) Crcu_SyncCalculateChannelCrc
(
    VAR    (Crcu_ChannelIdType, AUTOMATIC                  ) Crcu_ChannelId,
    P2CONST(uint8,              AUTOMATIC, CRCU_APPL_CONST ) Crcu_DataPtr,
    VAR    (uint32,             AUTOMATIC                  ) Crcu_Length
);

#if (STD_ON == CRCU_DMA_USED)
extern FUNC(void, CRCU_CODE) Crcu_AsyncCalculateChannelCrc
(
    VAR    (Crcu_ChannelIdType, AUTOMATIC                  ) Crcu_ChannelId,
    P2CONST(uint8,              AUTOMATIC, CRCU_APPL_CONST ) Crcu_DataPtr,
    VAR    (uint32,             AUTOMATIC                  ) Crcu_Length
);
#endif /* (STD_ON == CRCU_DMA_USED) */

extern FUNC(Crcu_ValueType, CRCU_CODE) Crcu_GetChannelCrc
(
    VAR(Crcu_ChannelIdType, AUTOMATIC) Crcu_ChannelId
);

#if (STD_ON == CRCU_GET_VERSION_INFO_API)
extern FUNC(void, CRCU_CODE) Crcu_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRCU_APPL_CONST) Crcu_VersionInfoPtr
);
#endif /* (STD_ON == CRCU_GET_VERSION_INFO_API) */

#if (STD_ON == CRCU_DMA_USED)

#if (CRCU_MAX_NUM_CRC_CHANNELS > 0U)
extern FUNC(void, MCL_CODE) Crcu_DmaTransferComplete0(void);
#endif /* (CRCU_MAX_NUM_CRC_CHANNELS > 0) */

#endif /* (STD_ON == CRCU_DMA_USED) */

#define CRCU_STOP_SEC_CODE
/** @violates @ref Crcu_h_REF_1 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* CDD_CRCU_H */
/** @} */
