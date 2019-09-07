[!NOCODE!][!//Do not generate any output, only warnings and errors
/**
  \file    Eth_VersionCheck_Inc.m
  \version 1.0.1

  \brief   AUTOSAR Eth - version check macro.
  \details Version checks.
  
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
[!/* Multiple Inclusion Protection *** */!][!//
[!IF "not(var:defined('ETH_CHECKS_M'))"!][!//
    [!VAR "ETH_CHECKS_M"="true()"!][!//
    [!// Peripheral detection
    [!MACRO "CheckValidConfig"!][!//
        [!LOOP "EthConfigSet/*"!][!//
            [!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
                [!VAR "VarEthCtrlIdx" = "EthCtrlIdx"!]
                [!VAR "VarEnableMii" = "EthCtrlEnableMii"!]
                [!VAR "VarEnableRxInterrupt" = "EthCtrlEnableRxInterrupt"!]
                [!VAR "VarEnableTxInterrupt" = "EthCtrlEnableTxInterrupt"!]
                [!VAR "VarMDIOSupport" = "EthVendorSpecific/EthCtrlSupportMDIO"!]
                [!IF "count(../../../*/EthCtrlConfig/*[EthCtrlIdx=$VarEthCtrlIdx][EthCtrlEnableMii!=$VarEnableMii]) > 0"!]
                    [!ERROR!]ETH module configuration error: EthCtrlEnableMii should be similar for all configuration. [!ENDERROR!]
                [!ENDIF!]
                [!IF "count(../../../*/EthCtrlConfig/*[EthCtrlIdx=$VarEthCtrlIdx][EthCtrlEnableRxInterrupt!=$VarEnableRxInterrupt]) > 0"!]
                    [!ERROR!]ETH module configuration error: EthCtrlEnableRxInterrupt should be similar for all configuration. [!ENDERROR!]
                [!ENDIF!]
                [!IF "count(../../../*/EthCtrlConfig/*[EthCtrlIdx=$VarEthCtrlIdx][EthCtrlEnableTxInterrupt!=$VarEnableTxInterrupt]) > 0"!]
                    [!ERROR!]ETH module configuration error: EthCtrlEnableTxInterrupt should be similar for all configuration. [!ENDERROR!]
                [!ENDIF!]
                [!IF "count(../../../*/EthCtrlConfig/*[EthCtrlIdx=$VarEthCtrlIdx][EthVendorSpecific/EthCtrlSupportMDIO!=$VarMDIOSupport]) > 0"!]
                    [!ERROR!]ETH module configuration error: EthVendorSpecific/EthCtrlSupportMDIO should be similar for all configuration. [!ENDERROR!]
                [!ENDIF!]
            [!ENDLOOP!][!//
        [!ENDLOOP!][!//
    [!ENDMACRO!]
    [!IF "'TRUE' = 'TRUE'"!]
        [!VAR "ETH_PERIPHERAL" = "string('ENET')"!]
        [!VAR "ETH_BDSIZE" = "num:i(32)"!]
            [!MACRO "CheckMultipleConfiguration"!]
            [!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
                [!SELECT "EthVendorSpecific"!][!// Container is selected for simpler access to children
                  [!IF "num:i(EthInterPacketGap)<8"!][!// Check it EthInterPacketGap is in valid interval 8-26
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthInterPacketGap value must be at least 8B[!ENDERROR!]
                  [!ENDIF!]
                  [!IF "num:i(EthInterPacketGap)>26"!][!// Check it EthInterPacketGap is in valid interval 8-26 B
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthInterPacketGap value must less or equal to 26 B[!ENDERROR!]
                  [!ENDIF!]
                  [!IF "num:i(EthInterPacketGap)<12"!][!// Check it EthInterPacketGap is valid based on 802.3
                    [!WARNING!]ETH module configuration warning: EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthInterPacketGap value should be greater than or equal to 12 byte-times (96 bit-times) according to IEEE 802.3 specification.[!ENDWARNING!]
                  [!ENDIF!]
                  [!IF "num:i(EthMDIOHoldTime)<0"!][!// Check it EthInterPacketGap is in valid range 0-7
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthMDIOHoldTime value must be at least 0[!ENDERROR!]
                  [!ENDIF!]
                  [!IF "num:i(EthMDIOHoldTime)>7"!][!// Check it EthInterPacketGap is in valid range 0-7
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthMDIOHoldTime value must be less or equal to 7[!ENDERROR!]
                  [!ENDIF!]
                  [!/* Check of Broadcast and Promiscuous mode setting */!]
                  [!IF "EthEnablePromiscuousMode = 'true' and EthReceiveBroadcast = 'false'"!][!// Warn if broadcast reception is disabled and promiscuous mode is set - broadcast will be received
                    [!WARNING!]ETH module configuration warning: EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthReceiveBroadcast = false but all frames will be received because EthConfigSet/[!"name(..)"!]/EthVendorSpecific/EthEnablePromiscuousMode = true. EthReceiveBroadcast value has been overridden.[!ENDWARNING!]
                  [!ENDIF!]
                [!ENDSELECT!]
                  [!/* Checks of buffer lengths */!]
                  [!IF "num:i(EthCtrlRxBufLenByte )<64"!]
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthCtrlRxBufLenByte value must be greater or equal to 64 for proper driver operation.[!ENDERROR!]
                  [!ENDIF!]
                  [!IF "num:i(EthCtrlTxBufLenByte )<64"!]
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthCtrlTxBufLenByte value must be greater or equal to 64 for proper driver operation.[!ENDERROR!]
                  [!ENDIF!]
                  [[!IF "num:i(num:mod(EthCtrlRxBufLenByte, 64))!=0"!]
                    [!VAR "EthCtrlRxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlRxBufLenByte) div 64)*64)"!]
                    [!INFO!]The EthCtrlRxBufLenByte will be rounded up to [!"$EthCtrlRxBufLenByteReal"!]. Therefore, there might be wasted memory in the buffer. It is recommended that the RxBufLenByte is the multiple of 64.[!ENDINFO!]
                  [!ENDIF!]
                  [!IF "num:i(num:mod(EthCtrlTxBufLenByte, 64))!=0"!]
                    [!VAR "EthCtrlTxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlTxBufLenByte) div 64)*64)"!]
                    [!INFO!]The EthCtrlTxBufLenByte will be rounded up to [!"$EthCtrlTxBufLenByteReal"!]. Therefore, there might be wasted memory in the buffer. It is recommended that the TxBufLenByte is the multiple of 64.[!ENDINFO!]
                  [!ENDIF!]
                  [!/* Checks of number of buffers */!]
                  [!IF "num:i(EthRxBufTotal)<1"!]
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthRxBufTotal value must be greater than 0 for proper driver operation.[!ENDERROR!]
                  [!ENDIF!]
                  [!IF "num:i(EthTxBufTotal)<1"!]
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthTxBufTotal value must be greater than 0 for proper driver operation.[!ENDERROR!]
                  [!ENDIF!]
                  [!IF "num:i(../../../EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported)<num:i(EthTxBufTotal)"!]
                    [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthTxBufTotal value ([!"EthTxBufTotal"!]) must be less than or equal to EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported value ([!"num:i(../../../EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported)"!]) [!ENDERROR!]
                  [!ENDIF!]

            [!ENDLOOP!]
            [!ENDMACRO!]
    [!ELSE!]
        [!VAR "ETH_PERIPHERAL"="string('FEC')"!]
        [!VAR "ETH_BDSIZE" = "num:i(8)"!]
        [!MACRO "CheckMultipleConfiguration"!]
            [!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
            [!SELECT "EthVendorSpecific"!][!// Container is selected for simpler access to children
              [!/* Check of Broadcast and Promiscuous mode setting */!]
              [!IF "EthEnablePromiscuousMode = 'true' and EthReceiveBroadcast = 'false'"!][!// Warn if broadcast reception is disabled and promiscuous mode is set - broadcast will be received
                [!WARNING!]ETH module configuration warning: EthConfigSet/[!"name(..)"!]/EthVendorSpecific: EthReceiveBroadcast = false but all frames will be received because EthEnablePromiscuousMode = true. EthReceiveBroadcast has been overriden.[!ENDWARNING!]
              [!ENDIF!]
            [!ENDSELECT!]
              [!/* Checks of buffer lengths */!]
              [!IF "num:i(EthCtrlRxBufLenByte )<64"!]
                [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthCtrlRxBufLenByte value must be greater or equal to 64 for proper driver operation.[!ENDERROR!]
              [!ENDIF!]
              [!IF "num:i(EthCtrlTxBufLenByte )<64"!]
                [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthCtrlTxBufLenByte value must be greater or equal to 64 for proper driver operation.[!ENDERROR!]
              [!ENDIF!]
              [!IF "num:i(num:mod(EthCtrlRxBufLenByte, 64))!=0"!]
                [!VAR "EthCtrlRxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlRxBufLenByte) div 64)*64)"!]
                [!INFO!]The EthCtrlRxBufLenByte will be rounded up to [!"$EthCtrlRxBufLenByteReal"!]. Therefore, there might be wasted memory in the buffer. It is recommended that the RxBufLenByte is the multiple of 64.[!ENDINFO!]
              [!ENDIF!]
              [!IF "num:i(num:mod(EthCtrlTxBufLenByte, 64))!=0"!]
                [!VAR "EthCtrlTxBufLenByteReal" = "num:i(ceiling(num:i(EthCtrlTxBufLenByte) div 64)*64)"!]
                [!INFO!]The EthCtrlTxBufLenByte will be rounded up to [!"$EthCtrlTxBufLenByteReal"!]. Therefore, there might be wasted memory in the buffer. It is recommended that the TxBufLenByte is the multiple of 64.[!ENDINFO!]
              [!ENDIF!]
              [!/* Checks of number of buffers */!]
              [!IF "num:i(EthRxBufTotal)<1"!]
                [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthRxBufTotal value must be greater than 0 for proper driver operation.[!ENDERROR!]
              [!ENDIF!]
              [!IF "num:i(EthTxBufTotal)<1"!]
                [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthTxBufTotal value must be greater than 0 for proper driver operation.[!ENDERROR!]
              [!ENDIF!]
              [!IF "num:i(../../../EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported)<num:i(EthTxBufTotal)"!]
                [!ERROR!]ETH module configuration error: EthConfigSet/[!"name(..)"!]/EthCtrlConfig/EthTxBufTotal value ([!"EthTxBufTotal"!]) must be less than or equal to EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported value ([!"num:i(../../EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported)"!]) [!ENDERROR!]
              [!ENDIF!]

            [!ENDLOOP!]
        [!ENDMACRO!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
