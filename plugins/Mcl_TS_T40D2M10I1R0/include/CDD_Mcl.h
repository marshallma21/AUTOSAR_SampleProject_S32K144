/**
*     @file           CDD_Mcl.h
*    
*     @version 1.0.1
*
*     @brief   AUTOSAR Mcl - MCL driver header file.
*     @details MCL driver header file, containing the Autosar API specification and other variables
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
*     Autosar Version     :  4.2.2
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

#ifndef CDD_MCL_H
#define CDD_MCL_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_h_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_h_2  
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Mcl_h_3
* Violates MISRA 2004 Required Rule 8.7,Objects %s shall be defined at block scope if they are 
* only accessed from within a single function %s.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "CDD_Mcl_Cfg.h"
#include "Mcl_Types.h"


/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCL_VENDOR_ID                       43
#define MCL_MODULE_ID                       255
#define MCL_AR_RELEASE_MAJOR_VERSION        4
#define MCL_AR_RELEASE_MINOR_VERSION        2
#define MCL_AR_RELEASE_REVISION_VERSION     2
#define MCL_SW_MAJOR_VERSION                1
#define MCL_SW_MINOR_VERSION                0
#define MCL_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
    /* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of CDD_Mcl.h and Std_Types.h are different"
    #endif
#endif
/* Check if source file and MCL configuration header file are of the same vendor */
#if (MCL_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "CDD_Mcl.h and MCL_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and MCL configuration header file are of the same Autosar version */
#if ((MCL_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of CDD_Mcl.h and MCL_Cfg.h are different"
#endif
/* Check if header file and MCL configuration header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of CDD_Mcl.h and MCL_Cfg.h are different"
#endif

/* Check if source file and Mcl types header file are of the same vendor */
#if (MCL_VENDOR_ID != MCL_TYPES_VENDOR_ID)
    #error "CDD_Mcl.h and Mcl_Types.h have different vendor IDs"
#endif
    /* Check if header file and Mcl types header file are of the same Autosar version */
#if ((MCL_AR_RELEASE_MAJOR_VERSION != MCL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AR_RELEASE_MINOR_VERSION != MCL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AR_RELEASE_REVISION_VERSION != MCL_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl.h and Mcl_Types.h are different"
#endif
/* Check if header file and Mcl types header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION != MCL_TYPES_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION != MCL_TYPES_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION != MCL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl.h and Mcl_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/


#if (MCL_ENABLE_DMA == STD_ON)

/**
* @brief   All API's having pointers as parameters shall return this error if 
*          called with with a NULL value
* 
* */
#define MCL_E_PARAM_POINTER_U8             ((uint8)0x0A)

/**
* @brief   API service used with a channel out of range
* 
* */
#define MCL_E_INVALID_CHANNEL_U8           ((uint8)0x0B)

#endif /* (MCL_ENABLE_DMA == STD_ON) */

/**
* @brief   API service used without module initialization
* 
* */
#define MCL_E_UNINIT_U8                    ((uint8)0x0C)

/**
* @brief   API Mcl_Dma_Init service called when the Mcl driver and the Hardware
*          are already initialized
* 
* */
#define MCL_E_ALREADY_INITIALIZED_U8      ((uint8)0x0D)

/**
* @brief   API Mcl_GetVersionInfo is called and the parameter versioninfo is is invalid
*          ( e.g. NULL )
* 
* */
#define MCL_E_PARAM_VINFO_U8               ((uint8)0x0F)

#if (MCL_ENABLE_DMA == STD_ON)

/**
* @brief            NULL function is configured as notification callback
* @details          Will be generated when a NULL function is configured as notification callback for
*                   one DMA channel and Mcl_Dma_EnableNotification is called for that channel
* 
*/
#define MCL_E_PARAM_NOTIFICATION_NULL_U8   ((uint8)0x10U)

/**
* @brief            Generated when an ISR has been triggered 
*                    1. when the driver is not initialized
*                    2. for a Hw channel that is not used by any logic channel
*                    3. for a logic channel that has no notification configured
* @details          Errors and exceptions that will be detected by the MCL driver
* 
*/
#define MCL_E_UNEXPECTED_ISR_U8            ((uint8)0x11U)

#endif /* (MCL_ENABLE_DMA == STD_ON) */

/**
* @brief   API Mcl_Init service called with wrong parameter
* 
* */
#define MCL_E_PARAM_CONFIG_U8              ((uint8)0x12U)
/**
* @brief   API Mcl_Init service called with wrong parameter
* 
* */
#define MCL_E_INIT_FAILED_U8              ((uint8)0x13U)


/**
* @brief   API Mcl_DeInit service is not allowed because a DMA transfer is in progress
* 
*/
#define MCL_E_DMA_TRANSFER_ACTIVE_U8        ((uint8)0x15U)


/**
* @brief API service ID for Mcl_GetVersionInfo function
* @details Parameters used when raising an error/exception
*/
#define MCL_GETVERSIONINFO_ID_U8           ((uint8)0x17U)


#if (MCL_ENABLE_TRGMUX == STD_ON)
/**
* @brief   API Mcl_TrgMuxConfigInput service called with wrong 
*                                      parameter regiserIndex
* */
#define MCL_E_INVALID_REGINDEX_U8          ((uint8)0x18U)

/**
* @brief   API Mcl_TrgMuxConfigInput service called with wrong 
*                                      parameter selection
* */
#define MCL_E_INVALID_TRGMUX_SEL_U8          ((uint8)0x19U)

/**
* @brief   API Mcl_TrgMuxConfigInput service called with wrong 
*                                             parameter triger
* */
#define MCL_E_INVALID_TRGMUX_TRIGGER_U8       ((uint8)0x1AU)

/**
* @brief   API Mcl_TrgMuxConfigInput service called when 
*                                           register is locked
* */
#define MCL_E_TRGMUX_LOCKED_U8                ((uint8)0x1BU)



#endif

#if (MCL_ENABLE_DMA == STD_ON)
/**
* @brief            Service ID of Mcl_ReportUnexpectedIsrError function
* @details          Parameters used when raising an error/exception
*/
#define MCL_PROCESSNOTIFICATION_ID          (0x1CU)
/**
* @brief            API service ID of Mcl_DmaEnableNotification function
* @details          Parameters used when raising an error/exception
*/
#define MCL_ENABLENOTIFICATION_ID_U8       ((uint8)0x21U)

/**
* @brief            API service ID of Mcl_DmaDisableNotification function
* @details          Parameters used when raising an error/exception
*/
#define MCL_DISABLENOTIFICATION_ID_U8       ((uint8)0x22U)

#endif /* (MCL_ENABLE_DMA == STD_ON) */
/**
* @brief API service ID for Mcl_Init function
* @details Parameters used when raising an error/exception
* */
#define MCL_INIT_ID_U8                     ((uint8)0x23U)

#if (MCL_ENABLE_DMA == STD_ON)

/**
* @brief API service ID for Mcl_DmaConfigChannel function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_CH_ID_U8                ((uint8)0x24U)

/**
* @brief API service ID for Mcl_DmaConfigLinkedChannel function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_LINK_CH_ID_U8           ((uint8)0x25U)

/**
* @brief API service ID for Mcl_DmaConfigTcd function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_TCD_ID_U8               ((uint8)0x26U)

/**
* @brief API service ID for Mcl_DmaConfigScatterGatherChannel function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_SCA_CH_ID_U8            ((uint8)0x27U)

/**
* @brief API service ID for Mcl_DmaConfigLinkedTcd function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_LINK_TCD_ID_U8          ((uint8)0x28U)

/**
* @brief API service ID for Mcl_DmaConfigScatterGatherTcd function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_SCA_TCD_ID_U8           ((uint8)0x29U)

/**
* @brief API service ID for Mcl_DmaSetChannelPriority function
* @details Parameters used when raising an error/exception
* */
#define MCL_SET_PRI_ID_U8                  ((uint8)0x2AU)

/**
* @brief API service ID for Mcl_DmaStartChannel function
* @details Parameters used when raising an error/exception
* */
#define MCL_START_CH_ID_U8                 ((uint8)0x2BU)

/**
* @brief API service ID for Mcl_DmaIsTransferCompleted function
* @details Parameters used when raising an error/exception
* */
#define MCL_TRANSF_COMPL_ID_U8             ((uint8)0x2CU)

/**
* @brief API service ID for Mcl_DmaIsTransferActive function
* @details Parameters used when raising an error/exception
* */
#define MCL_TRANSF_ACTIVE_ID_U8            ((uint8)0x2DU)


/**
* @brief API service ID for Mcl_DmaGetChannelTcdAddress function
* @details Parameters used when raising an error/exception
* */
#define MCL_DMAGETCHANNELTCDADDRESS_ID_U8   ((uint8)0x2FU)

/**
* @brief API service ID for Mcl_DmaClearDone function
* @details Parameters used when raising an error/exception
* */
#define MCL_DMACLEARDONE_ID_U8              ((uint8)0x30U)

/**
* @brief API service ID for Mcl_DmaConfigScatterGatherLinkedChannel function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_SCA_LINK_CH_ID_U8        ((uint8)0x31U)

/**
* @brief API service ID for Mcl_DmaTcdGetIntMaj function
* @details Parameters used when raising an error/exception
* */
#define MCL_DMATCDGETINTMAJ_ID_U8           ((uint8)0x32U)

/**
* @brief API service ID for Mcl_DmaGetInterruptRequest function
* @details Parameters used when raising an error/exception
* */
#define MCL_DMAGETINTERRUPTREQUEST_ID_U8    ((uint8)0x33U)

/**
* @brief API service ID for Mcl_DmaAcknowledgeInterrupt function
* @details Parameters used when raising an error/exception
* */
#define MCL_ACKNOWLEDGEINTERRUPT_ID_U8    ((uint8)0x34U)

/**
* @brief API service ID for Mcl_DmaGetPhysicalChannel function
* @details Parameters used when raising an error/exception
* */
#define MCL_DMAGETPHYSICALCHANNEL_ID_U8    ((uint8)0x35U)

/**
* @brief API service ID for Mcl_DmaConfigScatterGatherLinkedTcd function
* @details Parameters used when raising an error/exception
* */
#define MCL_CONFIG_SCA_LINK_TCD_ID_U8     ((uint8)0x36U)

/**
* @brief API service ID for Mcl_DmaTcdSetSaddr function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_SADDR_ID_U8           ((uint8)0x37U)

/**
* @brief API service ID for Mcl_DmaTcdSetSoff function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_SOFF_ID_U8            ((uint8)0x38U)

/**
* @brief API service ID for Mcl_DmaTcdSetDlast function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_DLAST_ID_U8          ((uint8)0x39U)

/**
* @brief API service ID for Mcl_DmaTcdSetDaddr function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_DADDR_ID_U8           ((uint8)0x3AU)

/**
* @brief API service ID for Mcl_DmaTcdSetDoff function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_DOFF_ID_U8           ((uint8)0x3BU)

/**
* @brief API service ID for Mcl_DmaTcdSetIterCount function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_ITER_COUNT_ID_U8     ((uint8)0x3CU)

/**
* @brief API service ID for Mcl_DmaTcdSetLinkAndIterCount function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_LINK_ITER_COUNT_ID_U8 ((uint8)0x3DU)

/**
* @brief API service ID for Mcl_DmaTcdSetSModuloAndSize function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_SMOD_SIZE_ID_U8      ((uint8)0x3FU)

/**
* @brief API service ID for Mcl_DmaTcdSetDModuloAndSize function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_DMOD_SIZE_ID_U8      ((uint8)0x40U)

/**
* @brief API service ID for Mcl_DmaTcdSetMlnoNBytes function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_MLNON_BYTES_ID_U8   ((uint8)0x41U)

/**
* @brief API service ID for Mcl_DmaTcdSetMinorLoop function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_MINOR_LOOP_ID_U8         ((uint8)0x42U)

/**
* @brief API service ID for Mcl_DmaTcdSetSlast function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_SLAST_ID_U8         ((uint8)0x43U)

/**
* @brief API service ID for Mcl_DmaTcdSetFlags function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_FLAGS_ID_U8         ((uint8)0x44U)

/**
* @brief API service ID for Mcl_DmaTcdGetFlags function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_GET_FLAGS_ID_U8         ((uint8)0x45U)

/**
* @brief API service ID for Mcl_DmaTcdClearIntMaj function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_CLEAR_INT_MAJ_ID_U8     ((uint8)0x46U)

/**
* @brief API service ID for Mcl_DmaTcdSetIntMaj function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_INT_MAJ_ID_U8       ((uint8)0x47U)

/**
* @brief API service ID for Mcl_DmaTcdGetIterCount function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_GET_ITER_COUNT_ID_U8         ((uint8)0x48U)

/**
* @brief API service ID for Mcl_DmaTcdGetSaddr function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_GET_SADDR_ID_U8         ((uint8)0x49U)

/**
* @brief API service ID for Mcl_DmaTcdGetDaddr function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_GET_DADDR_ID_U8         ((uint8)0x4AU)

/**
* @brief API service ID for Mcl_DmaTcdSetSga function
* @details Parameters used when raising an error/exception
* */
#define MCL_TCD_SET_SGA_ID_U8          ((uint8)0x4BU)

/**
* @brief API service ID for Mcl_DmaEnableHardwareRequest function
* @details Parameters used when raising an error/exception
* */
#define MCL_ENABLE_HW_REQ_ID_U8        ((uint8)0x4CU)
/**
* @brief API service ID for Mcl_DmaUpdateIterCount function
* @details Parameters used when raising an error/exception
* */
#define MCL_UPDATE_ITER_ID_U8        ((uint8)0x4DU)
/**
* @brief API service ID for Mcl_DmaGetCrtIterCount function
* @details Parameters used when raising an error/exception
* */
#define MCL_GET_CRT_ITER_CH_ID_U8        ((uint8)0x4EU)
/**
* @brief API service ID for Mcl_DmaUpdateDestAddress function
* @details Parameters used when raising an error/exception
* */
#define MCL_UPDATE_DEST_CH_ID_U8        ((uint8)0x4FU)
/**
* @brief API service ID for Mcl_DmaGetStartIterCount function
* @details Parameters used when raising an error/exception
* */
#define MCL_GET_STRT_ITER_CH_ID_U8        ((uint8)0x50U)

/**
* @brief API service ID for Mcl_DmaDisableHwRequest function
* @details Parameters used when raising an error/exception
* */
#define MCL_DISABLE_HW_REQ_ID_U8          ((uint8)0x51U)
/**
* @brief API service ID for Mcl_DmaGetGlobalErrorStatus function
* @details Parameters used when raising an error/exception
* */
#define MCL_GET_GLOBAL_ERR_STATUS_ID_U8         ((uint8)0x52U)
/**
* @brief API service ID for Mcl_DmaGetChannelErrorStatus function
* @details Parameters used when raising an error/exception
* */
#define MCL_GET_CH_ERR_STATUS_ID_U8          ((uint8)0x53U)


#endif /* (MCL_ENABLE_DMA == STD_ON) */

#if (MCL_ENABLE_TRGMUX == STD_ON)
/**
* @brief API service ID for Mcl_TrgMuxConfigInput function
* @details Parameters used when raising an error/exception
* */
#define MCL_TRGMUX_CONFIG_ID_U8              ((uint8)0x54U)

/**
* @brief API service ID for Mcl_TrgMuxConfigLock function
* @details Parameters used when raising an error/exception
* */
#define MCL_TRGMUX_CONFIG_LOCK_U8            ((uint8)0x55U)

#endif
/**
* @brief API service ID for Mcl_DeInit function
* @details Parameters used when raising an error/exception
* */
#define MCL_DEINIT_ID_U8                     ((uint8)0x56U)
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#if (MCL_ENABLE_DMA == STD_ON)

/**
* @brief      Mcl Dma channel high level configuration structure
* 
*/
typedef struct 
{
    /** @brief Dma Channel configuration */
    CONST(Mcl_ChannelType, MCL_CONST) Mcl_ChannelIndex;
#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief Pointer to notification function */
    CONST(Mcl_NotifyType,       MCL_CONST) pfDmaChannelNotification;
#endif /*(MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)*/

} Mcl_ChannelConfigType;

/**
* @brief      Mcl Dma init configuration 
* 
*/
typedef struct
{
    /** @brief Number of channels in the Mcl configuration */
    CONST(Mcl_ChannelType, MCL_CONST)                                  MclDmaNumchannels;
    /** @brief Pointer to the list of Dma configured channels */
    CONST(Mcl_ChannelConfigType, MCL_CONST)                   (* const pMclDmaChannelsConfig)[]; 
    /**< @brief IPs data generic configuration. */
    P2CONST(Mcl_DmaHwIpsConfigType, MCL_VAR, MCL_APPL_CONST)           pMclDmaHwIpsConfig;
    #if ((MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) || (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON))
    /** @brief Index table to translate eDma HW channels on to logical channels used 
    to process interrupts for notifications */
    CONST(Mcl_ChannelType, MCL_CONST)                                  MclDmaHwToLogicChannelMap[MCL_EDMA_CHANNELS_NO]; 
#endif /*(MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)*/
} Mcl_DmaInitConfigType;

#endif /* (MCL_ENABLE_DMA == STD_ON) */

/**
* @brief      Mcl high level configuration structure
*
*/
typedef struct 
{
#if (MCL_ENABLE_DMA == STD_ON)
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /**< @brief DEM error reporting configuration. */
    P2CONST( Mcl_DemConfigType, MCL_VAR, MCL_APPL_CONST)               Mcl_pDemConfig;
#endif
    P2CONST( Mcl_DmaInitConfigType, MCL_VAR, MCL_APPL_CONST)           pMclDmaConfig;
#endif /*(MCL_ENABLE_DMA == STD_ON)*/

#if (MCL_ENABLE_TRGMUX == STD_ON)
    /** @brief Pointer to the GTMCFG configuration */
    P2CONST(Mcl_TrgMuxConfigType, MCL_VAR, MCL_APPL_CONST)               pMclTrgMuxConfig;
#endif
} Mcl_ConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"


#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#if (MCL_ENABLE_DMA == STD_ON)
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)

#define MCL_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
/*
 * @violates @ref Mcl_h_3 MISRa Rule 8.7 Objects %s shall be defined at block scope ..
 */
extern P2CONST( Mcl_DemConfigType, MCL_VAR, MCL_APPL_CONST) Mcl_pDemCfgPtr;

#define MCL_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#endif
#endif

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
#if (MCL_PRECOMPILE_SUPPORT == STD_OFF)
    MCL_CONF_PB
#else
/** @violates @ref Mcl_h_3 MISRa Rule 8.7 Objects %s shall be defined at block scope .. */
    MCL_INIT_CONFIG_PC_DEFINE
#endif
#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define MCL_START_SEC_CODE
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"
FUNC(void, MCL_CODE) Mcl_Init(P2CONST( Mcl_ConfigType, AUTOMATIC, MCL_APPL_CONST) ConfigPtr);
#if (MCL_DEINIT_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_DeInit(void);
#endif

#if (MCL_GET_VERSION_INFO_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_GetVersionInfo(P2VAR(Std_VersionInfoType , AUTOMATIC, MCL_APPL_DATA) versioninfo);
#endif

#if (MCL_ENABLE_DMA == STD_ON)
FUNC(void, MCL_CODE) Mcl_DmaConfigChannel
( 
    VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor
);

FUNC(void, MCL_CODE) Mcl_DmaConfigTcd
( 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor
);

FUNC(void, MCL_CODE) Mcl_DmaConfigLinkedChannel
(
    VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
    VAR(Mcl_ChannelType, AUTOMATIC) next_channel
);
                                              
FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherChannel
( 
    VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd
);                                              

FUNC(void, MCL_CODE) Mcl_DmaConfigLinkedTcd
( 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
    VAR(Mcl_ChannelType, AUTOMATIC) next_channel
);
                                          
FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherTcd
( 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd
);

FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherLinkedChannel
( 
    VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
    VAR(Mcl_ChannelType, AUTOMATIC) next_channel
);   

FUNC(void, MCL_CODE) Mcl_DmaConfigScatterGatherLinkedTcd(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
    VAR(Mcl_ChannelType, AUTOMATIC) next_channel
);                                                                

FUNC(void, MCL_CODE) Mcl_DmaSetChannelPriority
( 
    VAR(Mcl_ChannelType, AUTOMATIC) nChannel, 
    VAR(Mcl_DmaPriorityType, AUTOMATIC) nPriority
);     

FUNC(void, MCL_CODE) Mcl_DmaStartChannel( VAR(Mcl_ChannelType, AUTOMATIC) nChannel);      

FUNC(boolean, MCL_CODE) Mcl_DmaIsTransferCompleted( VAR(Mcl_ChannelType, AUTOMATIC) nChannel);           

FUNC(boolean, MCL_CODE) Mcl_DmaIsTransferActive( VAR(Mcl_ChannelType, AUTOMATIC) nChannel);     

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, MCL_CODE) Mcl_DmaEnableNotification
(
    VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(Mcl_DmaTransferNotifType, AUTOMATIC) Notification
); 
                                                
FUNC(void, MCL_CODE) Mcl_DmaDisableNotification(VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);

FUNC(void, MCL_CODE) Mcl_DmaAcknowledgeInterrupt(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);
#endif             
     

FUNC(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA), MCL_CODE) Mcl_DmaGetChannelTcdAddress(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);             

FUNC(void, MCL_CODE) Mcl_DmaTcdSetSaddr
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint32, AUTOMATIC) u32Saddr
);   

FUNC(void, MCL_CODE) Mcl_DmaTcdSetSoff
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(sint16, AUTOMATIC) s16Soff
); 

FUNC(void, MCL_CODE) Mcl_DmaTcdSetDlast
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(sint32, AUTOMATIC) s32Dlast
); 
                                           
FUNC(void, MCL_CODE) Mcl_DmaTcdSetSga
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint32, AUTOMATIC) u32Sga
);                                            

FUNC(void, MCL_CODE) Mcl_DmaTcdSetDaddr
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint32, AUTOMATIC) u32Daddr
);

FUNC(void, MCL_CODE) Mcl_DmaTcdSetDoff
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(sint16, AUTOMATIC) s16Doff
);

FUNC(void, MCL_CODE) Mcl_DmaTcdSetIterCount
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint16, AUTOMATIC) u16Iter
);  

FUNC(void, MCL_CODE) Mcl_DmaTcdSetLinkAndIterCount
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(Mcl_ChannelType, AUTOMATIC) LinkCh,
    VAR(uint16, AUTOMATIC) u16Iter
);  

FUNC(void, MCL_CODE) Mcl_DmaTcdSetSModuloAndSize
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint8, AUTOMATIC) u8SModulo,
    VAR(Mcl_DmaSizeType, AUTOMATIC) SSize
); 

FUNC(void, MCL_CODE) Mcl_DmaTcdSetDModuloAndSize
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint8, AUTOMATIC) u8DModulo,
    VAR(Mcl_DmaSizeType, AUTOMATIC) DSize
); 

FUNC(void, MCL_CODE) Mcl_DmaTcdSetMinorLoop
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(boolean, AUTOMATIC) bSmloe,
    VAR(boolean, AUTOMATIC) bDmloe,
    VAR(sint32, AUTOMATIC) s32Mloff,
    VAR(uint32, AUTOMATIC) u32NBytes
); 

FUNC(void, MCL_CODE) Mcl_DmaTcdSetSlast
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(sint32, AUTOMATIC) s32Slast
);  

FUNC(void, MCL_CODE) Mcl_DmaTcdSetFlags
(
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
    VAR(uint8, AUTOMATIC) u8Flags
); 

FUNC(uint8, MCL_CODE) Mcl_DmaTcdGetFlags(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress);                                        

FUNC(void, MCL_CODE) Mcl_DmaTcdSetIntMaj(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress);                                       

FUNC(void, MCL_CODE) Mcl_DmaTcdClearIntMaj(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress);  

FUNC(boolean, MCL_CODE) Mcl_DmaTcdGetIntMaj(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);      

FUNC(void, MCL_CODE) Mcl_DmaTcdClearDone(VAR(Mcl_ChannelType, AUTOMATIC) nChannel);  

FUNC(uint16, MCL_CODE) Mcl_DmaTcdGetIterCount(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress);       

FUNC(uint32, MCL_CODE) Mcl_DmaTcdGetSaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress);

FUNC(uint32, MCL_CODE) Mcl_DmaTcdGetDaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress);          

FUNC(boolean, MCL_CODE) Mcl_DmaGetInterruptRequest(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);       

FUNC(Mcl_DmaChannelType, MCL_CODE) Mcl_DmaGetPhysicalChannel(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);        
 
FUNC(void, MCL_CODE) Mcl_DmaEnableHwRequest(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber); 
FUNC(void, MCL_CODE) Mcl_DmaDisableHwRequest(VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber); 

FUNC(void, MCL_CODE) Mcl_DmaUpdateIterCount
(
    VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint16, AUTOMATIC) u16Iter
);

FUNC(void, MCL_CODE) Mcl_DmaUpdateDestAddress
(
    VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber,
    VAR(uint32, AUTOMATIC) daddr
);

FUNC(uint16, MCL_CODE) Mcl_DmaGetCrtIterCount(VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);
FUNC(uint16, MCL_CODE) Mcl_DmaGetStartIterCount(VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);
#if (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_DmaGetGlobalErrorStatus
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) dmaInstance,
    P2VAR(Mcl_DmaGlobalErrorStatusType, AUTOMATIC, MCL_APPL_DATA) dmaGlobalErrorStatus
);
#endif
#if (MCL_DMA_GET_CH_ERR_STATUS_API == STD_ON)
FUNC(Mcl_DmaChannelErrorStatusType, MCL_CODE) Mcl_DmaGetChannelErrorStatus
(
    VAR(Mcl_ChannelType, AUTOMATIC) logicalChannel
);
#endif
#endif /* (MCL_ENABLE_DMA == STD_ON) */
#if (MCL_ENABLE_TRGMUX == STD_ON)
FUNC(void, MCL_CODE) Mcl_TrgMuxConfigInput
( 
    VAR(Mcl_TrgMuxRegisterIndexType, AUTOMATIC) registerIndex,  
    VAR(Mcl_TrgMuxSelectionNrType, AUTOMATIC) selNumber,
    VAR(Mcl_TrgMuxTriggerType, AUTOMATIC) trigger
);
FUNC(void, MCL_CODE) Mcl_TrgMuxEnableLock
( 
    VAR(Mcl_TrgMuxRegisterIndexType, AUTOMATIC) registerIndex
);
#endif /* #ifdef MCL_ENABLE_TRGMUX */                  

/*================================================================================================*/
#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheEnable(Mcl_CacheInstanceType cacheInstance);
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheDisable(Mcl_CacheInstanceType cacheInstance);   
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheFlush(Mcl_CacheInstanceType cacheInstance);
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheInvalidate(Mcl_CacheInstanceType cacheInstance);
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheClear(Mcl_CacheInstanceType cacheInstance);
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheFlushMultiLines(Mcl_CacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length);
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheInvalidateMultiLines(Mcl_CacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length);
FUNC(Std_ReturnType, MCL_CODE) Mcl_CacheClearMultiLines(Mcl_CacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length);
#endif /* #if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)  */
#endif /* #ifdef MCL_LMEM_ENABLE_CACHE_API  */                  
                  
#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_h_1 Advisory Rule 19.1 only preprocessor statements and comments before "#include" */
/** @violates @ref Mcl_h_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* MCL_H */
/** @} */

