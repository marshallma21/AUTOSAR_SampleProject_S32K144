[!NOCODE!][!//
/**
  @file    Mcl_PluginMacros.m
  @version 1.0.1

  @brief   AUTOSAR Mcl - plugin check.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform ARM
  Peripheral eDMA
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.1
  BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/
[!/* *************************** Dem config macro ******************************
******************************************************************************/!]
[!MACRO "DemConfig","MclConfigType"!]

/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType. */

[!IF "$MclConfigType = ''"!]
/** @violates @ref Mcl_Cfg_c_REF_10 MISRA 2004 Required Rule 8.10, all declarations must be static */
CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config =
[!ELSEIF "$MclConfigType = 'PC'"!][!//
/** @violates @ref Mcl_Cfg_c_REF_10 MISRA 2004 Required Rule 8.10, all declarations must be static */
CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config_[!"$MclConfigType"!] =
[!ELSEIF "$MclConfigType = 'PB'"!][!//
/** @violates @ref Mcl_PBcfg_c_REF_10 MISRA 2004 Required Rule 8.10, all declarations must be static */
CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config_[!"$MclConfigType"!] =
[!ENDIF!]
{

    /** MCL_DMA_E_BUS error code */ 
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_BUS)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_BUS)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_BUS)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},

    /** MCL_DMA_E_DESCRIPTOR  error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_DESCRIPTOR)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_DESCRIPTOR)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_DESCRIPTOR)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    /** MCL_DMA_E_PRIORITY error code */ 
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_PRIORITY)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_PRIORITY)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_PRIORITY)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    
    /** MCL_DMA_E_UNRECOGNIZED error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_UNRECOGNIZED)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_UNRECOGNIZED)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_UNRECOGNIZED)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    
    /** MCL_DMA_E_INCONSISTENCY error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_INCONSISTENCY)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_INCONSISTENCY)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_INCONSISTENCY)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]}
};

[!ENDMACRO!][!// Dem config end

[!/* *************************** Notification config macro ******************************
******************************************************************************/!]
[!MACRO "NotificationHandler","Suffix"!]

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/* DMA Channel Transfer Completion Notifications */
    [!NOCODE!]
        [!VAR "OuterLoopCounter" = "0"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!LOOP "MclConfigSet/*/DMAChannel/*"!]
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "MatchCounter" = "0"!]  
            [!VAR "Notification" = "MclDmaTransferCompletionNotif"!]
            
            [!LOOP "../../../*/DMAChannel/*"!]
              [!IF "(MclDmaTransferCompletionNotif != 'NULL_PTR') and (MclDmaTransferCompletionNotif != '"NULL"') and (MclDmaTransferCompletionNotif != 'NULL')"!]
                  [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                  [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                      [!IF "($Notification = MclDmaTransferCompletionNotif)"!]
                          [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                      [!ENDIF!]
                  [!ENDIF!]
              [!ENDIF!]
            [!ENDLOOP!]

            [!IF "$MatchCounter = 1"!]
                /* issue error if the ISR is disabled */
                [!VAR "hwCh" = "DmaHwChannel"!]
                [!LOOP "../../../../MclGeneral/MclIsrAvailable/*"!]
                    [!IF "(MclIsrName = $hwCh) and (MclIsrEnabled =  'false')"!]
                        [!ERROR!] [!//
                             "Interrupt configuration error ! Mcl hardware channel [!"$hwCh"!] has a transfer completion notification configured in one of the variants, but the ISR for the channel is disabled in the Mcl Interrupts Available TAB. "[!//
                        [!ENDERROR!][!//
                    [!ENDIF!]
                [!ENDLOOP!]
                /* generate declaration */
                [!CODE!][!//
                [!IF "$Suffix = ''"!][!//
                /** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_11 MISRA 2004 Rule 8.8 */
                [!ELSEIF "$Suffix = 'PC'"!][!//
                /** @violates @ref Mcl_Cfg_c_REF_12 MISRA 2004 Rule 8.8 */
                [!ELSEIF "$Suffix = 'PB'"!][!//
                /** @violates @ref Mcl_PBcfg_c_REF_12 MISRA 2004 Rule 8.8 */
                [!ENDIF!][!//
    extern FUNC(void, MCL_CODE)[!"MclDmaTransferCompletionNotif"!](void);[!//      
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDNOCODE!]
#endif

/* DMA error notifications */
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
[!IF "(MclGeneral/MclErrorNotificationDma0 != 'NULL_PTR') and (MclGeneral/MclErrorNotificationDma0 != '"NULL"') and (MclGeneral/MclErrorNotificationDma0 != 'NULL')"!]
    /** Notification for DMA0 */  
    [!IF "$Suffix = ''"!][!//
    /** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 Violates MISRA 2004 Required Rule 8.10 All declarations and definitions should have internal linkage */ 
    /** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_11 MISRA 2004 Rule 8.8 */
    [!ELSEIF "$Suffix = 'PC'"!][!//
    /** @violates @ref Mcl_Cfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10 All declarations and definitions should have internal linkage */
    /** @violates @ref Mcl_Cfg_c_REF_12 MISRA 2004 Rule 8.8 */
    [!ELSEIF "$Suffix = 'PB'"!][!//
     /** @violates @ref Mcl_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10 All declarations and definitions should have internal linkage */  
     /** @violates @ref Mcl_PBcfg_c_REF_12 MISRA 2004 Rule 8.8 */
    [!ENDIF!]
    extern FUNC(void, MCL_CODE) [!"normalize-space(MclGeneral/MclErrorNotificationDma0)"!](VAR(Mcl_DmaChannelErrorStatusType, AUTOMATIC) u8ErrorCode);
[!ENDIF!]
#endif

[!ENDMACRO!][!// Notification config end



[!/* *************************** DMA channel config ******************************
******************************************************************************/!]
[!MACRO "DmaChannelConfig","DmaConfigType"!]

[!IF "$DmaConfigType ='PC'"!]
static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig_[!"$DmaConfigType"!][MCL_DMA_CONF_CHANNELS_[!"$DmaConfigType"!]] =
[!ELSEIF "$DmaConfigType ='PB'"!]
static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMA_CONF_CHANNELS_[!"$DmaConfigType"!]_[!"@index"!]] =
[!ELSE!]
static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
[!ENDIF!]
{
[!FOR "varCounter" = "0" TO "num:i(count(DMAChannel/*))"!][!//
[!LOOP "DMAChannel/*"!][!//
[!IF "MclDMAChannelId = $varCounter"!][!//
    /** @brief [!"node:name(.)"!] - [!"DmaHwChannel"!] */
    { 
[!/* */!][!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
        /** @brief Enable Channel Preemption */
        ([!IF "ECP='true'"!]DMA_ECP_EN_U8[!ELSE!]DMA_ECP_DIS_U8[!ENDIF!]) |
        /** @brief Disable Preempt Ability */
        ([!IF "DPA='true'"!]DMA_DPA_EN_U8[!ELSE!]DMA_DPA_DIS_U8[!ENDIF!]) |
        /** @brief Channel Priority */
        (DMA_PRIORITY_[!"DMAChannelPriority"!]_U8),
        /** @brief eDMA HW Channel used by the Mcl channel */
        DMA_HW_CHANNEL_[!"$DmaCh"!],
        /** @brief Master ID Replication */
        [!WS "8"!][!IF "EMI='true'"!]DMA_EMI_EN_U8[!ELSE!]DMA_EMI_DIS_U8[!ENDIF!][!CR!]
    }[!IF "(num:i($comma))<(num:i($dmaChannelCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!// DMA channel config

[!/* *************************** DMA instance config ******************************
******************************************************************************/!]
[!MACRO "DmaInstanceConfig","DmaConfigType"!]
/** @brief Configuration for Dma instances */
[!IF "$DmaConfigType = 'PC'"!]
/** @violates @ref Mcl_Cfg_c_REF_10 external ... could be made static */
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig_[!"$DmaConfigType"!][MCL_DMA_NB_CONTROLLERS] =
[!ELSEIF "$DmaConfigType = 'PB'"!]
/** @violates @ref Mcl_PBcfg_c_REF_10 external ... could be made static */
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMA_NB_CONTROLLERS] =
[!ELSE!]
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_NB_CONTROLLERS] =
[!ENDIF!] 
{
[!//
[!NOCODE!]
    [!VAR "comma" = "0"!][!//
    [!FOR "currentInstance" = "0" TO "$LastDmaInstanceId"!]
    [!CODE!]{[!ENDCODE!][!//
        [!VAR "dmaCurrentInstanceExists" = "num:i(0)"!][!//
        [!LOOP "DmaInstance/*"!][!//
            [!VAR "dmaCurrentInstanceNumber" = "substring-after(node:value(DmaHwInstance),'eDMA_Instance')"!][!//
            [!IF "$dmaCurrentInstanceNumber = $currentInstance"!][!//
                [!VAR "dmaCurrentInstanceExists" = "num:i(1)"!][!//
                [!VAR "ChannelExistsForCrtDmaInstance" = "num:i(0)"!][!//
                [!LOOP "../../DMAChannel/*"!][!//
                    [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
                    [!VAR "Group" = "num:i($DmaCh div $ChannelsPerDmaGroup)"!][!//
                    [!VAR "CurrentDma" = "num:i($Group div (num:i($ChannelsPerDmaInstance div $ChannelsPerDmaGroup)))"!][!//
                    [!IF "num:i($dmaCurrentInstanceNumber) = $CurrentDma"!][!//
                        [!VAR "ChannelExistsForCrtDmaInstance"="num:i(1)"!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
                [!IF "$ChannelExistsForCrtDmaInstance=0"!][!//
                    [!ERROR!][!//
                    "Inconsistent Configuration! For Dma Instance [!"$currentInstance"!] there is no channel configured.Delete instance eDMA_Instance[!"$currentInstance"!]."[!//
                    [!ENDERROR!][!//
                [!ENDIF!][!CR!]
[!CODE!]    /** @brief Dma Hardware Instance [!"$currentInstance"!]*/
    /** @brief Dma CR Register */
    (uint32)(([!IF "MclEDMA_CX='true'"!]DMA_CANCEL_TRANSFER_EN_U32[!ELSE!]DMA_CANCEL_TRANSFER_DIS_U32[!ENDIF!]) |
    ([!IF "MclEDMA_ECX='true'"!]DMA_ERROR_CANCEL_TRANSFER_EN_U32[!ELSE!]DMA_ERROR_CANCEL_TRANSFER_DIS_U32[!ENDIF!]) | 
    ([!IF "MclEDMA_CLM='true'"!]DMA_CONT_LINK_MODE_EN_U32[!ELSE!]DMA_CONT_LINK_MODE_DIS_U32[!ENDIF!]) |
    ([!IF "MclEDMA_HALT='true'"!]DMA_HALT_OPERATIONS_EN_U32[!ELSE!]DMA_HALT_OPERATIONS_DIS_U32[!ENDIF!]) |
    ([!IF "MclEDMA_HOE='true'"!]DMA_HALT_ON_ERROR_EN_U32[!ELSE!]DMA_HALT_ON_ERROR_DIS_U32[!ENDIF!]) |[!ENDCODE!]
[!CODE!]    ([!IF "MclEDMA_ERCA='true'"!]DMA_ROUND_ROBIN_ARB_EN_U32[!ELSE!]DMA_ROUND_ROBIN_ARB_DIS_U32[!ENDIF!]) |
    [!IF "MclEDMA_EDBG='true'"!](DMA_DEBUG_EN_U32)[!ELSE!]/** @violates @ref Mcl_PB_PC_Cfg_c_REF_11 Boolean operation whose results are invariant shall not be permitted */
    (DMA_DEBUG_DIS_U32)[!ENDIF!]),
    /** @brief Dma Usage in Configuration */[!CR!]
    [!IF "$ChannelExistsForCrtDmaInstance=1"!]    DMA_INSTANCE_USED[!ELSE!]    DMA_INSTANCE_NOT_USED[!ENDIF!]
    
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ,
    /** @brief DMA error notification function */[!ENDCODE!]
[!IF "$currentInstance = 0"!][!//
    [!/* */!][!IF "(../../../../MclGeneral/MclErrorNotificationDma0 = '') or (../../../../MclGeneral/MclErrorNotificationDma0 = 'NULL_PTR') or (../../../../MclGeneral/MclErrorNotificationDma0 = 'NULL')"!][!//
[!CODE!]    NULL_PTR[!ENDCODE!]
    [!/* */!][!ELSE!][!//
[!CODE!]    &[!"../../../../MclGeneral/MclErrorNotificationDma0"!][!ENDCODE!]
    [!/* */!][!ENDIF!][!//
[!ENDIF!]
[!CODE!]
#endif
[!ENDCODE!]

[!CODE!]    }[!IF "(num:i($comma))<(num:i($LastDmaInstanceId))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$dmaCurrentInstanceExists=0"!][!//
        [!LOOP "DMAChannel/*"!][!//
                [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
                [!VAR "Group" = "num:i($DmaCh div $ChannelsPerDmaGroup)"!][!//
                [!VAR "CurrentDma" = "num:i($Group div (num:i($ChannelsPerDmaInstance div $ChannelsPerDmaGroup)))"!][!//
                [!IF "num:i($currentInstance) = $CurrentDma"!][!//
                    [!ERROR!][!//
                           "Inconsistent Configuration! Dma hardware channel eDMA_[!"$DmaCh"!] uses Dma instance eDMA_Instance[!"$currentInstance"!] which is not configured."[!//
                    [!ENDERROR!][!//
                [!ENDIF!][!//
        [!ENDLOOP!]
[!CODE!]    /** @brief Dma Hardware Instance [!"$currentInstance"!] */
    /** @brief Dma CR Register */
    (Mcl_DmaControlType)0x00000400UL,
    /** @brief Dma Usage in Configuration */
    DMA_INSTANCE_NOT_USED
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ,
    NULL_PTR
#endif
[!ENDCODE!]
[!CODE!]    }[!IF "(num:i($comma))<(num:i($LastDmaInstanceId))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!ENDCODE!][!//
    [!ENDIF!][!// 
[!ENDFOR!]
[!ENDNOCODE!]
};
[!ENDMACRO!][!// DMA instances config

[!/* *************************** DMA MUX Channel config ******************************
******************************************************************************/!]
[!MACRO "DmaMuxChannelConfig","DmaConfigType"!]
[!IF "$DmaMuxInstancesNumber != 0"!][!//
[!IF "$DmaMuxChannelsNo > 0"!][!//
[!NOCODE!]/***************************** Configuration for DMAMUX ********************/[!ENDNOCODE!][!//
/** @brief Configuration for DmaMux channels */
[!IF "$DmaConfigType = 'PC'"!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]] =
[!ELSEIF "$DmaConfigType = 'PB'"!][!//
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]_[!"@index"!]] =
[!ELSE!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
[!ENDIF!]
{
[!NOCODE!]
[!VAR "comma" = "1"!][!//
[!FOR "varCounter" = "0" TO "num:i(count(DMAChannel/*))"!][!//
    [!LOOP "DMAChannel/*"!][!//
        [!IF "MclDMAChannelId = $varCounter"!][!//
            [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
            [!IF "$ChannelsPerDmaMuxSmall = $ChannelsPerDmaMuxLarge"!][!//
                [!VAR "DmaMuxInstance"="$DmaCh div $ChannelsPerDmaMuxLarge"!][!//
                [!VAR "DmaMuxChannel"="$DmaCh mod $ChannelsPerDmaMuxLarge"!][!//
            [!ELSE!] [!//
                [!IF "$DmaCh < ($NumberOfDmaMuxSmallInstances * $ChannelsPerDmaMuxSmall)"!][!//
                    [!VAR "DmaMuxInstance"="$DmaCh div $ChannelsPerDmaMuxSmall"!][!//
                    [!VAR "DmaMuxChannel"="$DmaCh mod $ChannelsPerDmaMuxSmall"!][!//
                [!ELSE!][!//
                    [!VAR "DmaMuxInstance"="$NumberOfDmaMuxSmallInstances + (($DmaCh - ($NumberOfDmaMuxSmallInstances * $ChannelsPerDmaMuxSmall)) div $ChannelsPerDmaMuxLarge)"!][!//
                    [!VAR "DmaMuxChannel"="($DmaCh - ($NumberOfDmaMuxSmallInstances * $ChannelsPerDmaMuxSmall)) mod $ChannelsPerDmaMuxLarge"!][!//
                [!ENDIF!][!//
            [!ENDIF!] [!//
            [!VAR "DmaMuxInstance"="num:i($DmaMuxInstance)"!][!//
            [!VAR "DmaMuxChannel"="num:i($DmaMuxChannel)"!][!//
            [!IF "$DmaMuxInstance < $DmaMuxInstancesNumber"!][!//            
                [!CODE!][!CR!][!WS,"4"!]{[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]/** @brief Hardware DMAMUX channel used */[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]DMA_MUX_CH_[!"$DmaMuxChannel"!],[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]/** @brief DMAMUX instance used */[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]DMA_MUX_[!"$DmaMuxInstance"!],[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]/** @brief DMAMUX_CHCFGn register configuration */[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!](uint8)(([!IF "MclDMAChannelEnable='true'"!]DMAMUX_CHANNEL_EN_U32[!ELSE!]DMAMUX_CHANNEL_DIS_U32[!ENDIF!]) |[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]([!IF "MclDMAChannelTriggerEnable='true'"!]DMAMUX_CHANNEL_TRIG_EN_U32[!ELSE!]DMAMUX_CHANNEL_TRIG_DIS_U32[!ENDIF!]) |[!ENDCODE!]
                [!FOR "varLoop" = "0" TO "$DmaMuxInstancesNumber - 1"!]
                    [!IF "$DmaMuxInstance=$varLoop"!]
                        [!IF "node:value(concat("DmaSource",string(num:i($varLoop))))!='NOT_USED'"!]
                            [!CODE!][!CR!][!WS,"8"!](MCL_DMA_MUX_[!"$DmaMuxInstance"!]_[!"node:value(concat("DmaSource",num:i($varLoop)))"!]))[!ENDCODE!]
                        [!ELSE!]
                            [!CODE!][!CR!][!WS,"8"!](0U))[!ENDCODE!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
[!/* */!][!CODE!][!CR!][!WS,"4"!]}[!IF "(num:i($comma))<(num:i($dmaChannelCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
[!ELSE!][!//
/** @brief Configuration for DmaMux channels */
[!IF "$DmaConfigType = 'PC'"!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]+1] =
[!ELSEIF "$DmaConfigType = 'PB'"!][!//
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]+1] =
[!ELSE!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]+1] =
[!ENDIF!]
{
      /** @brief Dummy config used for the case when no DMAMUX channel is configured */  
      {
         /** @brief Hardware DMAMUX channel used */
         DMA_MUX_CH_0,
         /** @brief DMAMUX instance used */
         DMA_MUX_0,
         /** @brief DMAMUX_CHCFGn register configuration */
        (0U)
      }
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDMACRO!][!// DMA Mux Channel Config

[!/* *************************** AXBS Config Master ******************************
******************************************************************************/!]

[!/* *************************** TRGMUX Config ******************************
******************************************************************************/!]
[!MACRO "TrgMuxConfig","TrgMuxConfigType"!]
[!IF "$TrgMuxConfigType = 'PC'"!]
CONST( Mcl_TrgMuxConfigType, MCL_CONST) TrgMux_Config_PC =
[!ELSEIF "$TrgMuxConfigType = 'PB'"!]
CONST( Mcl_TrgMuxConfigType, MCL_CONST) TrgMux_Config_[!"@index"!] =
[!ELSE!]
CONST( Mcl_TrgMuxConfigType, MCL_CONST) TrgMux_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ENDIF!]
    {
        /** @brief Configuration for TRGMUX_DMAMUXCH0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxDmaMux0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxDmaMux0Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxDmaMux0Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxDmaMux0Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxDmaMux0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_XB_OUT0_3 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut0Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut0Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut0Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxXOut0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_XB_OUT4_7 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut1Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut1Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxXOut1Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxXOut1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_ADC_0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc0Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc0Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc0Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxAdc0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_ADC_1 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc1Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc1Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxAdc1Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxAdc1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_CMP0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxCmp0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxCmp0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_FTM0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm0Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm0Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm0Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_FTM1 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm1Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm1Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm1Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_FTM2 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm2Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm2Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm2Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm2Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm2LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_FTM3 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm3Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm3Input1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm3Input2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm3Input3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm3LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_PDB0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxPdb0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxPdb0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!IF "node:containsValue(ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg'),'PDB1')"!],
         /** @brief Configuration for TRGMUX_PDB1 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxPdb1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxPdb1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!ENDIF!],
         /** @brief Configuration for TRGMUX_FLEXIO register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFlexIoInput0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFlexIoInput1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFlexIoInput2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFlexIoInput3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFlexIoLockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LPIT register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpitInput0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_SEL1_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpitInput1"!] << TRGMUX_SEL1_SHIFT_U32))|
         (TRGMUX_SEL2_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpitInput2"!] << TRGMUX_SEL2_SHIFT_U32))|
         (TRGMUX_SEL3_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpitInput3"!] << TRGMUX_SEL3_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpitLockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LPUART0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpuart0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpuart0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LPUART1 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpuart1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpuart1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LPI2C0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpi2c0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpi2c0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LSPI0 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpspi0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpspi0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LSPI1 register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpspi1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpspi1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        ),
         /** @brief Configuration for TRGMUX_LPTMR register */
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLptmr0Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLptmr0LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!IF "node:containsValue(ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg'),'LPI2C1')"!],
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxLpi2c1Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxLpi2c1LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!ENDIF!][!IF "node:containsValue(ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg'),'FTM4')"!],
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm4Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm4LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!ENDIF!][!IF "node:containsValue(ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg'),'FTM5')"!],
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm5Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm5LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!ENDIF!][!IF "node:containsValue(ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg'),'FTM6')"!],
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm6Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm6LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!ENDIF!][!IF "node:containsValue(ecu:list('Mcl.MclConfigSet.TrgMux0.ListOfReg'),'FTM7')"!],
        ((TRGMUX_SEL0_MASK_U32 & ((uint32)MCL_TRGMUX_[!"TriggerMux/TrgMuxFtm7Input0"!] << TRGMUX_SEL0_SHIFT_U32))|
         (TRGMUX_LK_BIT_MASK_U32 & ([!IF "TriggerMux/TrgMuxFtm7LockEn"!]TRGMUX_LOCK_EN_U32[!ELSE!]TRGMUX_LOCK_DIS_U32[!ENDIF!] << TRGMUX_LOCK_SHIFT_U32))
        )[!ENDIF!]
    };
[!ENDMACRO!]
[!/* *************************** Mcl export driver configuration ***************************
******************************************************************************/!]
[!MACRO "MclExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(./MclConfigSet/*)"!][!//
[!CODE!][!//
/** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */  
#define MCL_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Mcl_ConfigType, MCL_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Mcl_ConfigType, MCL_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]
[!ENDNOCODE!]
