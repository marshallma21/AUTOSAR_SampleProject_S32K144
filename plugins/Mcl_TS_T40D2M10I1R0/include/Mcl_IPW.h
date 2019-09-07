/**
*     @file Mcl_IPW.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Mcl - Brief description.
*     @details Detailed description.
*
*     @addtogroup MCL_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform ARM
*     Peripheral eDMA
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

#ifndef MCL_IPW_H
#define MCL_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_IPW_h_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to IP functions.
*
* @section Mcl_IPW_h_REF_2
*           Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*           contents of a header file being included twice
*           This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcl_IPW_Types.h"
#include "Mcl_Types.h"
#if (MCL_ENABLE_TRGMUX == STD_ON)
    #include "Mcl_TrgMux.h"
#endif

#if (MCL_ENABLE_DMA == STD_ON)
    #include "Mcl_Dma.h"
    #include "Mcl_DmaMux.h"
#endif 


#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (MCL_LMEM_ENABLE_CACHE_API == STD_ON)
    #include "Mcl_Lmem.h"
#endif
#endif
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_IPW_VENDOR_ID                       43

#define MCL_IPW_AR_RELEASE_MAJOR_VERSION        4
#define MCL_IPW_AR_RELEASE_MINOR_VERSION        2
#define MCL_IPW_AR_RELEASE_REVISION_VERSION     2
#define MCL_IPW_SW_MAJOR_VERSION                1
#define MCL_IPW_SW_MINOR_VERSION                0
#define MCL_IPW_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and MCL IPW types header file are of the same vendor */
#if (MCL_IPW_VENDOR_ID != MCL_IPW_TYPES_VENDOR_ID)
    #error "Mcl_IPW.h and Mcl_IPW_Types.h have different vendor IDs"
#endif
/* Check if header file and MCL IPW types header file are of the same Autosar version */
#if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION != MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_AR_RELEASE_MINOR_VERSION != MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_AR_RELEASE_REVISION_VERSION != MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcl_IPW.h and Mcl_IPW_Types.h are different"
#endif
/* Check if header file and  MCL IPW types file are of the same software version */
#if ((MCL_IPW_SW_MAJOR_VERSION != MCL_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_SW_MINOR_VERSION != MCL_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_SW_PATCH_VERSION != MCL_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcl_IPW.h and Mcl_IPW_Types.h are different"
#endif

/* Check if header file and Mcl types header file are of the same vendor */
#if (MCL_IPW_VENDOR_ID != MCL_TYPES_VENDOR_ID)
    #error "Mcl_IPW.h and Mcl_Types.h have different vendor IDs"
#endif
    /* Check if header file and Mcl types header file are of the same Autosar version */
#if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION != MCL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_AR_RELEASE_MINOR_VERSION != MCL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_AR_RELEASE_REVISION_VERSION != MCL_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcl_IPW.h and Mcl_Types.h are different"
#endif
/* Check if header file and Mcl types header file are of the same software version */
#if ((MCL_IPW_SW_MAJOR_VERSION != MCL_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_SW_MINOR_VERSION != MCL_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_SW_PATCH_VERSION != MCL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcl_IPW.h and Mcl_Types.h are different"
#endif

#if (MCL_ENABLE_DMA == STD_ON)
    /* Check if header file and Mcl_Dma header file are of the same vendor */
    #if (MCL_IPW_VENDOR_ID != MCL_DMA_VENDOR_ID)
        #error "Mcl_IPW.h and Mcl_Dma.h have different vendor IDs"
    #endif
    /* Check if header file and Mcl_Dma header file are of the same Autosar version */
    #if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION != MCL_DMA_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_MINOR_VERSION != MCL_DMA_AR_RELEASE_MINOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_REVISION_VERSION != MCL_DMA_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Mcl_IPW.h and Mcl_Dma.h are different"
    #endif
    /* Check if header file and Mcl_Dma header file are of the same Software version */
    #if ((MCL_IPW_SW_MAJOR_VERSION != MCL_DMA_SW_MAJOR_VERSION) || \
         (MCL_IPW_SW_MINOR_VERSION != MCL_DMA_SW_MINOR_VERSION) || \
         (MCL_IPW_SW_PATCH_VERSION != MCL_DMA_SW_PATCH_VERSION))
        #error "Software Version Numbers of Mcl_IPW.h and Mcl_Dma.h are different"
    #endif
    #if (MCL_DMAMUX_NB_MODULES != 0U) 
        /* Check if header file and Mcl_DmaMux header file are of the same vendor */
        #if (MCL_IPW_VENDOR_ID != MCL_DMAMUX_VENDOR_ID)
            #error "Mcl_IPW.h and Mcl_DmaMux.h have different vendor IDs"
        #endif
        /* Check if header file and Mcl_DmaMux header file are of the same Autosar version */
        #if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION != MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION) || \
             (MCL_IPW_AR_RELEASE_MINOR_VERSION != MCL_DMAMUX_AR_RELEASE_MINOR_VERSION) || \
             (MCL_IPW_AR_RELEASE_REVISION_VERSION != MCL_DMAMUX_AR_RELEASE_REVISION_VERSION))
            #error "AutoSar Version Numbers of Mcl_IPW.h and Mcl_DmaMux.h are different"
        #endif
        /* Check if header file and Mcl_DmaMux header file are of the same Software version */
        #if ((MCL_IPW_SW_MAJOR_VERSION != MCL_DMAMUX_SW_MAJOR_VERSION) || \
             (MCL_IPW_SW_MINOR_VERSION != MCL_DMAMUX_SW_MINOR_VERSION) || \
             (MCL_IPW_SW_PATCH_VERSION != MCL_DMAMUX_SW_PATCH_VERSION))
            #error "Software Version Numbers of Mcl_IPW.h and Mcl_DmaMux.h are different"
        #endif
    #endif
#endif
#if (MCL_ENABLE_TRGMUX == STD_ON)
    /* Check if header file and Mcl_TrgMux.h header file are of the same vendor */
    #if (MCL_IPW_VENDOR_ID != MCL_TRGMUX_VENDOR_ID)
        #error "Mcl_IPW.h and Mcl_TrgMux.h have different vendor IDs"
    #endif
    /* Check if header file and Mcl_TrgMux.h header file are of the same Autosar version */
    #if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION != MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_MINOR_VERSION != MCL_TRGMUX_AR_RELEASE_MINOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_REVISION_VERSION != MCL_TRGMUX_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Mcl_IPW.h and Mcl_TrgMux.h are different"
    #endif
    /* Check if header file and Mcl_TrgMux.h header file are of the same Software version */
    #if ((MCL_IPW_SW_MAJOR_VERSION != MCL_TRGMUX_SW_MAJOR_VERSION) || \
         (MCL_IPW_SW_MINOR_VERSION != MCL_TRGMUX_SW_MINOR_VERSION) || \
         (MCL_IPW_SW_PATCH_VERSION != MCL_TRGMUX_SW_PATCH_VERSION))
        #error "Software Version Numbers of Mcl_IPW.h and Mcl_TrgMux.h are different"
    #endif
#endif
 

#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (MCL_LMEM_ENABLE_CACHE_API == STD_ON)  
    
    #if (MCL_IPW_VENDOR_ID != MCL_LMEM_VENDOR_ID)
        #error "Mcl_IPW.h and Mcl_Lmem.h have different vendor IDs"
    #endif
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcl_Lmem header file are of the same Autosar version */
    #if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION != MCL_LMEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_MINOR_VERSION != MCL_LMEM_AR_RELEASE_MINOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_REVISION_VERSION != MCL_LMEM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW.h and Mcl_Lmem.h are different"
    #endif
    #endif
    /* Check if source file and Mcl_Lmem header file are of the same Software version */
    #if ((MCL_IPW_SW_MAJOR_VERSION != MCL_LMEM_SW_MAJOR_VERSION) || \
         (MCL_IPW_SW_MINOR_VERSION != MCL_LMEM_SW_MINOR_VERSION) || \
         (MCL_IPW_SW_PATCH_VERSION != MCL_LMEM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW.h and Mcl_Lmem.h are different"
    #endif

#endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (MCL_ENABLE_TRGMUX == STD_ON)

    #if ((STD_ON == MCL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == MCL_TRGMUX_USER_MODE_SUPPORT))
        /** @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
        #define  CALL_TRGMUX_INIT(pconfig)                                     (Mcal_Trusted_Call1param(Mcl_TrgMux_Init,(pconfig)))
         /** @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
        #define  CALL_TRGMUX_CONFIG_SEL(RegisterIndex,selNumber,source)  (Mcal_Trusted_Call3params(Mcl_TrgMux_Config_Sel,(RegisterIndex),(selNumber),(source)))
         /** @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
        #define  CALL_TRGMUX_ENABLE_LOCK(RegisterIndex)                        (Mcal_Trusted_Call1param(Mcl_TrgMux_Enable_Lock,(RegisterIndex)))
    #else
        /** @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
        #define  CALL_TRGMUX_INIT(pconfig)                                      (Mcl_TrgMux_Init(pconfig))
        /** @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
        #define  CALL_TRGMUX_CONFIG_SEL(RegisterIndex,selNumber,source)   (Mcl_TrgMux_Config_Sel((RegisterIndex),(selNumber),(source)))
        /** @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
        #define  CALL_TRGMUX_ENABLE_LOCK(RegisterIndex)                         (Mcl_TrgMux_Enable_Lock(RegisterIndex))
    #endif
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */
    #define MCL_IPW_TRGMUX_INIT(pconfig)    (CALL_TRGMUX_INIT(pconfig))
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */
    #define Mcl_IPW_TrgMuxConfigInput(RegisterIndex,selNumber,source) \
                    (CALL_TRGMUX_CONFIG_SEL((RegisterIndex),(selNumber),(source)))
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */
    #define Mcl_IPW_TrgMuxGetLock(RegisterIndex) \
                    (TRGMUX_GET_LOCK(RegisterIndex))
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_TrgMuxEnableLock(RegisterIndex) \
                    (CALL_TRGMUX_ENABLE_LOCK(RegisterIndex))
#endif /* (MCL_ENABLE_TRGMUX == STD_ON) */

#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheEnable(cacheInstance)  (Mcl_Lmem_CacheEnable(cacheInstance))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheDisable(cacheInstance)  (Mcl_Lmem_CacheDisable(cacheInstance))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheFlush(cacheInstance)  (Mcl_Lmem_CacheFlush(cacheInstance))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheInvalidate(cacheInstance)  (Mcl_Lmem_CacheInvalidate(cacheInstance))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheClear(cacheInstance)  (Mcl_Lmem_CacheClear(cacheInstance))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheFlushMultiLines(cacheInstance, u32PhyAddr, u32Length)  (Mcl_Lmem_CacheFlushMultiLines((cacheInstance), (u32PhyAddr), (u32Length)))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheInvalidateMultiLines(cacheInstance, u32PhyAddr, u32Length)  (Mcl_Lmem_InvalidateMultiLines((cacheInstance), (u32PhyAddr), (u32Length)))
    
    /*
     * @violates @ref Mcl_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
     */              
    #define Mcl_IPW_CacheClearMultiLines(cacheInstance, u32PhyAddr, u32Length)  (Mcl_Lmem_CacheClearMultiLines((cacheInstance), (u32PhyAddr), (u32Length)))

#endif 
#endif 
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

#define MCL_START_SEC_CODE
/** @violates @ref Mcl_IPW_h_REF_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#if (MCL_ENABLE_DMA == STD_ON)
    FUNC(void, MCL_CODE) Mcl_IPW_Init( P2CONST( Mcl_DmaHwIpsConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_HwIPs_ConfigPtr);
    
#if (MCL_DEINIT_API == STD_ON)
    FUNC(void, MCL_CODE) Mcl_IPW_DeInit( P2CONST( Mcl_DmaHwIpsConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_HwIPs_ConfigPtr);
#endif
    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigChannel(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                  VAR(Mcl_ChannelType, AUTOMATIC) dma_channel,
                                                  P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                               P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigLinkedChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                         VAR(Mcl_ChannelType, AUTOMATIC) dma_channel,
                                                         P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor,
                                                         VAR(Mcl_ChannelType, AUTOMATIC) next_channel);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                                VAR(Mcl_ChannelType, AUTOMATIC) dma_channel,
                                                                P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor,
                                                                P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigLinkedTcd( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                     P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                     P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor,
                                                     VAR(Mcl_ChannelType, AUTOMATIC) next_channel);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                            P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor,
                                                            P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherLinkedChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                                      VAR(Mcl_ChannelType, AUTOMATIC) dma_channel,
                                                                      P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor,
                                                                      P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                                      VAR(Mcl_ChannelType, AUTOMATIC) next_channel);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherLinkedTcd( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                                  P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                                  P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor,
                                                                  P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                                  VAR(Mcl_ChannelType, AUTOMATIC) next_channel);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetChannelPriority( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                        VAR(Mcl_ChannelType, AUTOMATIC) nChannel,
                                                        VAR(Mcl_DmaPriorityType, AUTOMATIC) nPriority);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaStartChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                  VAR(Mcl_ChannelType, AUTOMATIC) nChannel);

    FUNC(boolean, MCL_CODE) Mcl_IPW_DmaIsTransferCompleted( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                            VAR(Mcl_ChannelType, AUTOMATIC) nChannel);

    FUNC(boolean, MCL_CODE) Mcl_IPW_DmaIsTransferActive( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                         VAR(Mcl_ChannelType, AUTOMATIC) nChannel);

    #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    FUNC (void, MCL_CODE) Mcl_IPW_EnableNotification( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                      VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber,
                                                      VAR(Mcl_DmaTransferNotifType,AUTOMATIC) Notification);

    FUNC (void, MCL_CODE) Mcl_IPW_DisableNotification( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                       VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaAcknowledgeInterrupt( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                          VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);

    #endif /* MCL_DMA_NOTIFICATION_SUPPORTED */


    FUNC(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA), MCL_CODE) Mcl_IPW_DmaGetChannelTcdAddress(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                                              VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(uint32, AUTOMATIC) Saddr);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSoff(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                            VAR(sint16, AUTOMATIC) Soff);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDlast(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(sint32, AUTOMATIC) Dlast);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSga(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                           VAR(uint32, AUTOMATIC) Sga);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(uint32, AUTOMATIC) Daddr);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDoff(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                            VAR(sint16, AUTOMATIC) Doff);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetCiter(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(uint16, AUTOMATIC) Citer);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetBiter(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(uint16, AUTOMATIC) Biter);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetLinkAndIterCount(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                        P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                                        VAR(Mcl_ChannelType, AUTOMATIC) LinkCh,
                                                        VAR(uint16, AUTOMATIC) Iter);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSModSize(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                                VAR(uint8, AUTOMATIC) SModSize,
                                                VAR(Mcl_DmaSizeType, AUTOMATIC) SSize);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDModSize(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                                VAR(uint8, AUTOMATIC) DModSize,
                                                VAR(Mcl_DmaSizeType, AUTOMATIC) DSize);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetMlnoNBytes(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                                  VAR(uint32, AUTOMATIC) MlnoNBytes);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetMloffen(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                               VAR(boolean, AUTOMATIC) Smloe,
                                               VAR(boolean, AUTOMATIC) Dmloe,
                                               VAR(sint32, AUTOMATIC) Mloff,
                                               VAR(uint32, AUTOMATIC) NBytes);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSlast(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(sint32, AUTOMATIC) Slast);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetFlags(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                             VAR(uint8, AUTOMATIC) Flags);

    FUNC(uint8, MCL_CODE) Mcl_IPW_DmaGetFlags(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaSetIntMaj(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr);

    FUNC(boolean, MCL_CODE) Mcl_IPW_DmaTcdGetIntMaj(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                    VAR(Mcl_ChannelType, AUTOMATIC) nChannel);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaClearIntMaj(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr);

    FUNC(void, MCL_CODE) Mcl_IPW_DmaClearDone(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                              VAR(Mcl_ChannelType, AUTOMATIC) nChannel);

    FUNC(uint16, MCL_CODE) Mcl_IPW_DmaGetCiter(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr);

    FUNC(uint32, MCL_CODE) Mcl_IPW_DmaGetSaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr);

    FUNC(uint32, MCL_CODE) Mcl_IPW_DmaGetDaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr);

    FUNC(boolean, MCL_CODE) Mcl_IPW_DmaGetInterruptRequest(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                           VAR(Mcl_ChannelType, AUTOMATIC) nChannel);    

    FUNC(void, MCL_CODE) Mcl_IPW_DmaEnableHwRequest(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                       VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);        

    FUNC(void, MCL_CODE) Mcl_IPW_DmaDisableHwRequest(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                       VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);  
    FUNC(void, MCL_CODE)Mcl_IPW_DmaUpdateDestAddress(VAR(uint32, AUTOMATIC)channel, VAR(uint32, AUTOMATIC) daddr);
    #if (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON)
    FUNC(void, MCL_CODE) Mcl_IPW_DmaGetGlobalErrorStatus
    (
        VAR(Mcl_DmaInstanceType, AUTOMATIC) dmaInstance,
        P2VAR(Mcl_DmaGlobalErrorStatusType, AUTOMATIC, MCL_APPL_DATA) dmaGlobalErrorStatus
    );
    #endif
    
    #if (MCL_DMA_GET_CH_ERR_STATUS_API == STD_ON)                                
    FUNC(Mcl_DmaChannelErrorStatusType, MCL_CODE) Mcl_IPW_DmaGetChannelErrorStatus
    (
        P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
        VAR(Mcl_ChannelType, AUTOMATIC) logicalChannel
    );
    #endif                                                   
    FUNC(uint16, MCL_CODE) Mcl_IPW_DmaGetChBiter (VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);
    FUNC(uint16, MCL_CODE) Mcl_IPW_DmaGetChCiter (VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber);

#endif 

/*================================================================================================*/
/*================================================================================================*/
#ifdef CACHE_INVALIDATE_MACROS
#if (STD_ON == CACHE_INVALIDATE_MACROS)
    FUNC(void, MCL_CODE) Mcl_IPW_CacheFlushPc(void);
         
    FUNC(void, MCL_CODE) Mcl_IPW_CacheFlushPs(void);    

    FUNC(void, MCL_CODE) Mcl_IPW_CacheFlushAll(void);   

    FUNC(void, MCL_CODE) Mcl_IPW_CacheInvalidatePc(void);

    FUNC(void, MCL_CODE) Mcl_IPW_CacheInvalidatePs(void);

    FUNC(void, MCL_CODE) Mcl_IPW_CacheInvalidateAll(void);  
#endif /* #if (STD_ON == CACHE_INVALIDATE_MACROS)  */
#endif /* #ifdef CACHE_INVALIDATE_MACROS  */
#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_IPW_h_REF_2 Required Rule 19.15 header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* MCL_IPW_H */
/** @} */

