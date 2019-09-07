/**
  \file    Eth_GetRegisterValues.m
  \version 1.0.1

  \brief   AUTOSAR Eth - Get register value macro.
  \details Get register values for driver.
  
  Project AUTOSAR 4.2 MCAL
  Platform ARM
  Peripheral ENET
  Dependencies 
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.1
  BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
  All Rights Reserved.
*/
[!MACRO "GetBufLenByteReal"!][!//
[!NOCODE!][!//
    [!VAR "EthCtrlTxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlTxBufLenByte) div 64) * 64)"!]
    [!VAR "EthCtrlRxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlRxBufLenByte) div 64) * 64)"!]
    [!IF "(../../../EthGeneral/EthVendorSpecific/EthUseMultiBufferRxFrames = 'true') and (../../../EthGeneral/EthVendorSpecific/EthEnableRxFrameWrap = 'true')"!]
        [!VAR "RxAdditionalSpace" = "num:i((ceiling(num:i(1536) div $EthCtrlRxBufLenByteReal)) - 1) * $EthCtrlRxBufLenByteReal"!] [!// Get the offset for leading and trailing areas
        [!VAR "tmpVar" = "(($EthCtrlRxBufLenByteReal + $BDSize) * EthRxBufTotal + $RxAdditionalSpace)"!]
    [!ELSE!]
        [!VAR "tmpVar" = "(($EthCtrlRxBufLenByteReal + $BDSize) * EthRxBufTotal)"!]
    [!ENDIF!]
    [!IF "num:i(num:mod(EthRxBufTotal,2)) = 1"!][!// padd is added in case of even RX buffers number
        [!VAR "tmpVar" = "$tmpVar + $BDPadLen"!]
    [!ENDIF!]
    [!IF "$tmpVar > $RxSpaceMax"!]
      [!VAR "RxSpaceMax" = "$tmpVar"!]
    [!ENDIF!]
    [!VAR "tmpVar" = "(($EthCtrlTxBufLenByteReal + $BDSize) * EthTxBufTotal)"!]
    [!IF "num:i(num:mod(EthTxBufTotal,2)) = 1"!][!// padd is added in case of even TX buffers number
        [!VAR "tmpVar" = "$tmpVar + $BDPadLen"!]
    [!ENDIF!]
    [!IF "$tmpVar > $TxSpaceMax"!]
      [!VAR "TxSpaceMax" = "$tmpVar"!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!MACRO "GetRegisterValues"!][!//
[!NOCODE!][!//
    [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET alignment
      [!VAR "BDPadLen"="num:i(32)"!]
      [!VAR "BDSize"="num:i(32)"!]
    [!ELSE!]
      [!VAR "BDPadLen"="num:i(8)"!]
      [!VAR "BDSize"="num:i(8)"!]
    [!ENDIF!]
      [!/* Compute MAC address register values */!]
      [!IF "node:exists(EthCtrlPhyAddress)"!]
        [!VAR "MACAddrString"="EthCtrlPhyAddress"!]
        [!VAR "PhysAddress"="concat('0x',text:replaceAll($MACAddrString, ':',''))"!]
        [!VAR "PhysAddress"="num:hextoint($PhysAddress)"!]
      [!ELSE!]
        [!VAR "MACAddrString"="'00:00:00:00:00:00'"!]
        [!VAR "PhysAddress"="0"!]
      [!ENDIF!]
      [!VAR "MACAddrHigh" = "num:i(num:div($PhysAddress,65536))"!][!//Get first four numbers
      [!VAR "MACAddrLow" = "num:i(num:mod($PhysAddress,65536))"!][!//Get last two numbers
      [!VAR "MACAddrLow" = "num:i($MACAddrLow*65536)"!][!//Move bits to the right position
      [!VAR "MACAddrLow" = "num:i($MACAddrLow + num:hextoint('0x8808'))"!][!//Add other bits value

      [!/* Space occupied by buffers and their descriptors */!]
      [!VAR "EthCtrlTxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlTxBufLenByte) div 64) * 64)"!]
      [!VAR "EthCtrlRxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlRxBufLenByte) div 64) * 64)"!]
      [!VAR "RxBuffersSpace" = "num:i(($EthCtrlRxBufLenByteReal + $BDSize) * EthRxBufTotal)"!]
      [!IF "num:i(num:mod(EthRxBufTotal,2)) = 1"!][!// padd is added in case of even RX buffers total
        [!VAR "RxBuffersSpace" = "num:i($RxBuffersSpace + $BDPadLen)"!][!// To be sure about alignment
      [!ENDIF!]
      [!VAR "TxBuffersSpace" = "num:i(($EthCtrlTxBufLenByteReal + $BDSize) * EthTxBufTotal)"!]
      [!IF "num:i(num:mod(EthTxBufTotal,2)) = 1"!][!// padd is added in case of even TX buffers total
        [!VAR "TxBuffersSpace" = "num:i($TxBuffersSpace + $BDPadLen)"!][!// To be sure about alignment
      [!ENDIF!]
    [!IF "../../../EthGeneral/EthVendorSpecific/EthUseMultiBufferRxFrames = 'true'"!]
      [!/* Calculate the available RX space */!]
      [!VAR "AvailableRxBufSpace" = "num:i($EthCtrlRxBufLenByteReal * EthRxBufTotal)"!]
      [!/* Compare the available space with maximum allowed frame size: Payload(1500) + MAC(2*6) + VLAN(4) + TypeLength(2) + CRC(4) = 1522 */!]
      [!IF "$AvailableRxBufSpace > num:i(1522)"!]
        [!VAR "MaxRxFrameLength" = "num:i(1522)"!]
      [!ELSE!]
        [!VAR "MaxRxFrameLength" = "$AvailableRxBufSpace"!]
      [!ENDIF!]
    [!ELSE!]
      [!/* MultiBuffer feature is not used. Maximum received frame length is limited by Rx buffer length */!]
      [!VAR "MaxRxFrameLength" = "$EthCtrlRxBufLenByteReal"!]
    [!ENDIF!]
    [!SELECT "EthVendorSpecific"!][!/* Container is seleccted for simpler access to children */!][!//
      [!// -----------------------------
      [!// RCR value and description set
      [!// -----------------------------
      [!IF "$ETH_PERIPHERAL = string('FEC')"!][!//
          [!VAR "RCRValue" = "num:i(4)"!][!// Initial register value - MII mode always selected
      [!VAR "RCRDesc" = "concat('Maximal received frame length is ',string(../EthCtrlRxBufLenByte),';MII mode is selected;')"!][!// Initial description string
      [!ELSEIF "$ETH_PERIPHERAL = string('ENET')"!][!//
          [!VAR "RCRValue" = "num:i(4)"!][!// Initial register value - MII mode always selected
          [!VAR "RCRValue" = "$RCRValue + 16384"!][!// Terminate received CRC
      [!VAR "RCRDesc" = "concat('Maximal received frame length is ',string(../EthCtrlRxBufLenByte),';MII or RMII mode is selected;CRC is not forwarded to application;')"!][!//Initial description string
          [!IF "EthDropInvalidMAC = 'true'"!][!//
            [[!VAR "RCRValue" = "$RCRValue + 1073741824"!][!// Disable remove of padding at frame receive PADEN = 1, Enable payload length check NLC =1
            [!VAR "RCRDesc" = "concat($RCRDesc,'Payload length check is enable;')"!][!// Initial description string
          [!ENDIF!][!//      
      [!ELSE!][!//
        [!ERROR!]ETH module configuration error: No valid peripheral ([!"$ETH_PERIPHERAL"!]) selected[!ENDERROR!][!//
      [!ENDIF!][!//
      [!IF "EthReceiveBroadcast = 'false'"!][!// Broadcast shall be rejected
        [!VAR "RCRValue" = "$RCRValue + 16"!][!// set BC_REJ bit  
        [!VAR "RCRDesc" = "concat($RCRDesc,'Broadcast is rejected;')"!][!//Add description
      [!ELSE!]
        [!VAR "RCRDesc" = "concat($RCRDesc,'Broadcast is accepted;')"!][!//Add description    
      [!ENDIF!]
      [!IF "EthEnablePromiscuousMode = 'true'"!][!// Promiscuous mode is enabled
        [!VAR "RCRValue" = "$RCRValue + 8"!][!// set PROM bit  
        [!VAR "RCRDesc" = "concat($RCRDesc,'Promiscuous mode is enabled;')"!][!//Add description
      [!ELSE!]
        [!VAR "RCRDesc" = "concat($RCRDesc,'Promiscuous mode is disabled;')"!][!//Add description
      [!ENDIF!]
      [!IF "node:exists(EthEnableLoopbackMode) = true()"!][!// EthEnableLoopbackMode container is enabled - loopback is used 
          [!IF "EthEnableLoopbackMode/EthInternalLoopbackMode = 'true'"!]
            [!VAR "RCRValue" = "$RCRValue + 1"!][!// set LOOP bit  
            [!VAR "RCRDesc" = "concat($RCRDesc,'Internal loopback mode enabled;')"!][!//Add description        
          [!ENDIF!] 
          [!VAR "RCRDesc" = "concat($RCRDesc,'Reception during transmission enabled;')"!][!//Add description  
      [!ELSE!][!// No loopback mode 
        [!IF "EthFullDuplexEnable = 'false'"!][!//Half duplex mode is selceted
          [!/* No loopback and half duplex mode is selected so no reception during transmission is needed - set DRT bit*/!]
          [!VAR "RCRValue" = "$RCRValue + 2"!][!// set DRT bit  
          [!VAR "RCRDesc" = "concat($RCRDesc,'Reception during transmission disabled;')"!][!//Add description  
        [!ENDIF!][!//   
      [!ENDIF!]    
      [!IF "EthPhyInterface = 'RMII_100Mbs'"!][!//
        [!/* RMII 100Mbs mode is selected */!]
        [!VAR "RCRValue" = "$RCRValue + 256"!][!// set  bit
        [!VAR "RCRDesc" = "concat($RCRDesc,'RMII 100Mbs mode enabled;')"!][!//Add description
      [!ELSEIF "EthPhyInterface = 'RGMII_100Mbs' or EthPhyInterface = 'RGMII_1000Mbs'"!][!// ENET
        [!/* RGMII 1000/100 Mbs mode is selected */!]
        [!VAR "RCRValue" = "$RCRValue + 64"!][!// set  bit
        [!VAR "RCRDesc" = "concat($RCRDesc,'RGMII 1000/100 Mbs mode enabled;')"!][!//Add description
      [!ELSE!]
        [!VAR "RCRDesc" = "concat($RCRDesc, EthPhyInterface, ' mode selected;')"!][!//Add description

      [!ENDIF!][!//
      [!// -----------------------------
      [!// TCR value and description set
      [!// -----------------------------
      [!IF "$ETH_PERIPHERAL = string('FEC')"!][!// FEC
        [!IF "EthFullDuplexEnable = 'false'"!][!//
            [!VAR "TCRValue" = "num:i(0)"!][!// 0x00000000U
            [!VAR "TCRDesc" = "'Value stored to TCR during initialization - half duplex mode selected'"!][!//
        [!ELSE!]
            [!VAR "TCRValue" = "num:i(4)"!][!// 0x00000004U
            [!VAR "TCRDesc" = "'Value stored to TCR during initialization - full duplex mode selected'"!][!//
        [!ENDIF!]
      [!ELSEIF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET
        [!IF "../../../../EthGeneral/EthVendorSpecific/EthBridgeSupport = 'true'"!][!//
            [!VAR "TCRValue" = "num:i(0)"!][!// 0x0000 0000U
            [!VAR "TCRDesc" = "'Support Bridge, not copy source MAC from controller at transmit'"!][!//
        [!ELSE!]
            [!VAR "TCRValue" = "num:i(256)"!][!// 0x0000 0100U
            [!VAR "TCRDesc" = "'Not support Bridge, copy source MAC from controller at transmit'"!][!//
        [!ENDIF!]
        [!IF "EthFullDuplexEnable = 'false'"!][!//
            [!VAR "TCRValue" = "num:i($TCRValue + 0)"!][!// 0x0000 0000U
            [!VAR "TCRDesc" = "'Value stored to TCR during initialization - half duplex mode selected'"!][!//
        [!ELSE!]
            [!VAR "TCRValue" = "num:i($TCRValue + 4)"!][!// 0x0000 0104U
            [!VAR "TCRDesc" = "'Value stored to TCR during initialization - full duplex mode selected'"!][!//
        [!ENDIF!]    
      [!ELSE!][!//
        [!ERROR!]ETH module configuration error: No valid peripheral ([!"$ETH_PERIPHERAL"!]) selected[!ENDERROR!][!//
      [!ENDIF!][!//          
      [!// -----------------------------
      [!// RACC value and description set
      [!// -----------------------------
      [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET
        [!IF "EthDropInvalidMAC = 'false'"!][!//
            [!VAR "RACCValue" = "num:i(0)"!]
            [!VAR "RACCDesc" = "'Value stored to RACC during initialization - all acceleration function disabled'"!]
        [!ELSE!][!//
            [!VAR "RACCValue" = "num:i(64)"!][!// 0x40
            [!VAR "RACCDesc" = "'Value stored to RACC during initialization - frames with errors at MAC layer discarded (CRC,length,PHY)'"!]
        [!ENDIF!][!//
      [!ENDIF!]
      [!VAR "EthTimeStampClk" = "num:i(1000000)"!]
      [!IF "../../../../EthGeneral/EthGlobalTimeSupport='true'"!]
        [!IF "node:exists(EthTimeStampReferenceClock)"!]
          [!SELECT "node:ref(EthTimeStampReferenceClock)"!]
            [!VAR "EthTimeStampClk" = "McuClockReferencePointFrequency"!]
            [!IF "num:i(num:mod(1000000000,$EthTimeStampClk)) > 0"!]
              [!ERROR!] The clock provide for Eth timer should be a factor of 1000 000 000U[!ENDERROR!][!//
            [!ENDIF!][!//
          [!ENDSELECT!]
        [!ELSE!]
          [!ERROR!]When using global time (EthGlobalTimeSupport=TRUE), it is required to configure source clock for ETH timer module (EthTimeStampReferenceClock) [!ENDERROR!]  
        [!ENDIF!]
      [!ENDIF!]
    [!ENDSELECT!]
    [!IF "(../../../EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false') and (node:exists(EthDemEventParameterRefs) = true())"!]
      [!SELECT "EthDemEventParameterRefs"!]
        [!IF "node:refvalid(ETH_E_ACCESS) and node:exists(ETH_E_ACCESS)"!]
          [!VAR "EthDemEAccessEnabled" = "'true'"!]
          [!VAR "EthDemEAccessEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_ACCESS)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEAccessEnabled" = "'false'"!]
          [!VAR "EthDemEAccessEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_RX_FRAMES_LOST) and node:exists(ETH_E_RX_FRAMES_LOST)"!]
          [!VAR "EthDemFrameLostEnabled" = "'true'"!]
          [!VAR "EthDemFrameLostEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_RX_FRAMES_LOST)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemFrameLostEnabled" = "'false'"!]
          [!VAR "EthDemFrameLostEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_CRC) and node:exists(ETH_E_CRC)"!]
          [!VAR "EthDemECRCEnabled" = "'true'"!]
          [!VAR "EthDemECRCEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_CRC)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemECRCEnabled" = "'false'"!]
          [!VAR "EthDemECRCEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_UNDERSIZEFRAME) and node:exists(ETH_E_UNDERSIZEFRAME)"!]
          [!VAR "EthDemEUnderSizeEnabled" = "'true'"!]
          [!VAR "EthDemEUnderSizeEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_UNDERSIZEFRAME)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEUnderSizeEnabled" = "'false'"!]
          [!VAR "EthDemEUnderSizeEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_OVERSIZEFRAME) and node:exists(ETH_E_OVERSIZEFRAME)"!]
          [!VAR "EthDemEOverSizeEnabled" = "'true'"!]
          [!VAR "EthDemEOverSizeEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_OVERSIZEFRAME)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEOverSizeEnabled" = "'false'"!]
          [!VAR "EthDemEOverSizeEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_ALIGNMENT) and node:exists(ETH_E_ALIGNMENT)"!]
          [!VAR "EthDemEAlignmentEnabled" = "'true'"!]
          [!VAR "EthDemEAlignmentEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_ALIGNMENT)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEAlignmentEnabled" = "'false'"!]
          [!VAR "EthDemEAlignmentEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_SINGLECOLLISION) and node:exists(ETH_E_SINGLECOLLISION)"!]
          [!VAR "EthDemE1ColEnabled" = "'true'"!]
          [!VAR "EthDemE1ColEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_SINGLECOLLISION)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemE1ColEnabled" = "'false'"!]
          [!VAR "EthDemE1ColEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_MULTIPLECOLLISION) and node:exists(ETH_E_MULTIPLECOLLISION)"!]
          [!VAR "EthDemEMColEnabled" = "'true'"!]
          [!VAR "EthDemEMColEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_MULTIPLECOLLISION)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemEMColEnabled" = "'false'"!]
          [!VAR "EthDemEMColEventId" ="num:i(0)"!]
        [!ENDIF!]
        [!IF "node:refvalid(ETH_E_LATECOLLISION) and node:exists(ETH_E_LATECOLLISION)"!]
          [!VAR "EthDemELColEnabled" = "'true'"!]
          [!VAR "EthDemELColEventId" ="concat('DemConf_DemEventParameter_',node:ref(ETH_E_LATECOLLISION)/@name)"!]
        [!ELSE!][!//
          [!VAR "EthDemELColEnabled" = "'false'"!]
          [!VAR "EthDemELColEventId" ="num:i(0)"!]
        [!ENDIF!]
      [!ENDSELECT!]
    [!ELSE!]
      [!VAR "EthDemEAccessEnabled" = "'false'"!]
      [!VAR "EthDemEAccessEventId" ="num:i(0)"!]
      [!VAR "EthDemFrameLostEnabled" = "'false'"!]
      [!VAR "EthDemFrameLostEventId" ="num:i(0)"!]
      [!VAR "EthDemECRCEnabled" = "'false'"!]
      [!VAR "EthDemECRCEventId" ="num:i(0)"!]
      [!VAR "EthDemEUnderSizeEnabled" = "'false'"!]
      [!VAR "EthDemEUnderSizeEventId" ="num:i(0)"!]
      [!VAR "EthDemEOverSizeEnabled" = "'false'"!]
      [!VAR "EthDemEOverSizeEventId" ="num:i(0)"!]
      [!VAR "EthDemEAlignmentEnabled" = "'false'"!]
      [!VAR "EthDemEAlignmentEventId" ="num:i(0)"!]
      [!VAR "EthDemE1ColEnabled" = "'false'"!]
      [!VAR "EthDemE1ColEventId" ="num:i(0)"!]
      [!VAR "EthDemEMColEnabled" = "'false'"!]
      [!VAR "EthDemEMColEventId" ="num:i(0)"!]
      [!VAR "EthDemELColEnabled" = "'false'"!]
      [!VAR "EthDemELColEventId" ="num:i(0)"!]
    [!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
