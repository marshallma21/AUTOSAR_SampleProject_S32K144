/**
*   @file    Eth_Enet.h
*   @version 1.0.1
*
*   @brief   ENET controller interface header file
*   @details Implementation of the ENET controller interface for
*            the Ethernet driver
*
*   @addtogroup ETH_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ENET
*   Dependencies         : 
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
#ifndef ETH_ENET_H
#define ETH_ENET_H
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_Enet_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macros is unfortunately longer than 31 characters which is required by 
* the agreed macro format and cannot be changed. 
*
* @section Eth_Enet_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Enet_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Enet_h_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_Enet_h_REF_5
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block
* scope if they are only accessed from within a single function. This violation 
* is wrongly reported because the variable here has been drop by compiler. Other
* config will use this variable.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
   
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_ENET                    43
#define ETH_MODULE_ID_ENET                    88
/** @violates @ref Eth_Enet_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Enet_h_REF_4 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MAJOR_VERSION_ENET     4
/** @violates @ref Eth_Enet_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Enet_h_REF_4 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MINOR_VERSION_ENET     2
/** @violates @ref Eth_Enet_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Enet_h_REF_4 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_ENET  2
#define ETH_SW_MAJOR_VERSION_ENET             1
#define ETH_SW_MINOR_VERSION_ENET             0
#define ETH_SW_PATCH_VERSION_ENET             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH configuration header file are of the same vendor */
#if (ETH_VENDOR_ID_ENET != ETH_VENDOR_ID_CFG)
#error "Eth_Enet.h and Eth_Cfg.h have different vendor ids"
#endif
/* Check if current file and ETH configuration header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_ENET != ETH_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ETH_AR_RELEASE_MINOR_VERSION_ENET != ETH_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ETH_AR_RELEASE_REVISION_VERSION_ENET != ETH_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Eth_Enet.h and Eth_Cfg.h are different"
#endif
/* Check if current file and ETH configuration header file are of the same software version */
#if ((ETH_SW_MAJOR_VERSION_ENET != ETH_SW_MAJOR_VERSION_CFG) || \
     (ETH_SW_MINOR_VERSION_ENET != ETH_SW_MINOR_VERSION_CFG) || \
     (ETH_SW_PATCH_VERSION_ENET != ETH_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Eth_Enet.h and Eth_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
 /***************************************************************************
* Register Offsets Macros 
***************************************************************************/
#define ENET_EIR_ADDR16    0x0004U /**< Interrupt Event Register */
#define ENET_EIMR_ADDR16   0x0008U /**< Interrupt Mask Register */
#define ENET_RDAR_ADDR16   0x0010U /**< Receive Descriptor Active Register */
#define ENET_TDAR_ADDR16   0x0014U /**< Transmit Descriptor Active Register */
#define ENET_ECR_ADDR16    0x0024U /**< Ethernet Control Register */
#define ENET_MMFR_ADDR16   0x0040U /**< MII Management Frame Register */
#define ENET_MSCR_ADDR16   0x0044U /**< MII Speed Control Register */
#define ENET_MIBC_ADDR16   0x0064U /**< MIB Control/Status Register */
#define ENET_RCR_ADDR16    0x0084U /**< Receive Control Register */
#define ENET_TCR_ADDR16    0x00C4U /**< Transmit Control Register */
#define ENET_PALR_ADDR16   0x00E4U /**< MAC Address Low Register */
#define ENET_PAUR_ADDR16   0x00E8U /**< MAC Address Upper Register + Type Field */
#define ENET_OPD_ADDR16    0x00ECU /**< Opcode + Pause Duration Fields */
#define ENET_IAUR_ADDR16   0x0118U /**< Upper 32 bits of Individual Hash Table */
#define ENET_IALR_ADDR16   0x011CU /**< Lower 32 Bits of Individual Hash Table */
#define ENET_GAUR_ADDR16   0x0120U /**< Upper 32 bits of Group Hash Table */
#define ENET_GALR_ADDR16   0x0124U /**< Lower 32 bits of Group Hash Table */
#define ENET_TFWR_ADDR16   0x0144U /**< Transmit FIFO Watermark */
#define ENET_RDSR_ADDR16   0x0180U /**< Pointer to Receive Descriptor Ring */
#define ENET_TDSR_ADDR16   0x0184U /**< Transmit Buffer Descriptor Ring Start Reg. */
#define ENET_MRBR_ADDR16   0x0188U /**< Receive Buffer Size Register */
/* New registers that were not on FEC: */
#define ENET_RSFL_ADDR16   0x0190U /**< Receive FIFO Section Full Threshold */
#define ENET_RSEM_ADDR16   0x0194U /**< Receive FIFO Section Empty Threshold */
#define ENET_RAEM_ADDR16   0x0198U /**< Receive FIFO Almost Empty Threshold */
#define ENET_RAFL_ADDR16   0x019CU /**< Receive FIFO Almost Full Threshold */
#define ENET_TSEM_ADDR16   0x01A0U /**< Transmit FIFO Section Empty Threshold */
#define ENET_TAEM_ADDR16   0x01A4U /**< Transmit FIFO Almost Empty Threshold */
#define ENET_TAFL_ADDR16   0x01A8U /**< Transmit FIFO Almost Full Threshold */
#define ENET_TIPG_ADDR16   0x01ACU /**< Transmit Inter-Packet Gap */
#define ENET_FTRL_ADDR16   0x01B0U /**< Frame Truncation Length */
#define ENET_TACC_ADDR16   0x01C0U /**< Transmit Accelerator Function Configuration */
#define ENET_RACC_ADDR16   0x01C4U /**< Receive Accelerator Function Configuration */
#define ENET_ATCR_ADDR16   0x0400U /**< Timer Control Register */
#define ENET_ATVR_ADDR16   0x0404U /**< Timer Value Register */
#define ENET_ATOFF_ADDR16  0x0408U /**< Timer Offset Register */
#define ENET_ATPER_ADDR16  0x040CU /**< Timer Period Register */
#define ENET_ATCOR_ADDR16  0x0410U /**< Timer Correction Register */
#define ENET_ATINC_ADDR16  0x0414U /**< Time-Stamping Clock Period Register */
#define ENET_ATSTMP_ADDR16 0x0418U /**< Timestamp of Last Transmitted Frame */
#define ENET_TGSR_ADDR16   0x0604U /**< Timer Global Status Register */
#define ENET_TCSR0_ADDR16  0x0608U /**< Timer Control Status Register */
#define ENET_TCCR0_ADDR16  0x060CU /**< Timer Compare Capture Register */
#define ENET_TCSR1_ADDR16  0x0610U /**< Timer Control Status Register */
#define ENET_TCCR1_ADDR16  0x0614U /**< Timer Compare Capture Register */
#define ENET_TCSR2_ADDR16  0x0618U /**< Timer Control Status Register */
#define ENET_TCCR2_ADDR16  0x061CU /**< Timer Compare Capture Register */
#define ENET_TCSR3_ADDR16  0x0620U /**< Timer Control Status Register */
#define ENET_TCCR3_ADDR16  0x0624U /**< Timer Compare Capture Register */
#define ENET_TXBD_TS_ADDR16  0x0014U /**< Timer Compare Capture Register */
#define ENET_RXBD_TS_ADDR16  0x0014U /**< Timer Compare Capture Register */

/***************************************************************************
* Register Bits Macros 
***************************************************************************/
/* EIR register bits */
#define ENET_EIR_BABR_W1C           0x40000000U /* Babbling receive error */
#define ENET_EIR_BABT_W1C           0x20000000U /* Babbling transmit error */
#define ENET_EIR_GRA_W1C            0x10000000U /* Graceful stop complete */
#define ENET_EIR_TXF_W1C            0x08000000U /* Transmit frame interrupt */
#define ENET_EIR_TXB_W1C            0x04000000U /* Transmit buffer interrupt */
#define ENET_EIR_RXF_W1C            0x02000000U /* Receive frame interrupt */
#define ENET_EIR_RXB_W1C            0x01000000U /* Receive buffer interrupt */
#define ENET_EIR_MII_W1C            0x00800000U /* MII interrupt */
#define ENET_EIR_EBERR_W1C          0x00400000U /* Ethernet bus error */
#define ENET_EIR_LC_W1C             0x00200000U /* Late collision */
#define ENET_EIR_RL_W1C             0x00100000U /* Collision retry limit */
#define ENET_EIR_UN_W1C             0x00080000U /* Transmit FIFO underrun */
#define ENET_EIR_PLR_W1C            0x00040000U /* Payload Receive Error */
#define ENET_EIR_WAKEUP_W1C         0x00020000U /* Node Wakeup Request Indication */
#define ENET_EIR_TS_AVAIL_W1C       0x00010000U /* Transmit Timestamp Available */
#define ENET_EIR_TS_TIMER_W1C       0x00008000U /* Timestamp Timer */
#define ENET_EIR_ALL_W1C            0x7FFF8000U /* All bits */
/* EIMR register bits */
#define ENET_EIMR_BABR_U32          0x40000000U /* Babbling receive error int. enable */
#define ENET_EIMR_BABT_U32          0x20000000U /* Babbling transmit error int. enable */
#define ENET_EIMR_GRA_U32           0x10000000U /* Graceful stop complete int. enable */
#define ENET_EIMR_TXF_U32           0x08000000U /* Transmit frame int. enable */
#define ENET_EIMR_TXB_U32           0x04000000U /* Transmit buffer int. enable */
#define ENET_EIMR_RXF_U32           0x02000000U /* Receive frame int. enable */
#define ENET_EIMR_RXB_U32           0x01000000U /* Receive buffer int. enable */
#define ENET_EIMR_MII_U32           0x00800000U /* MII interrupt enable */
#define ENET_EIMR_EBERR_U32         0x00400000U /* Ethernet bus error interrupt enable */
#define ENET_EIMR_LC_U32            0x00200000U /* Late collision interrupt enable */
#define ENET_EIMR_RL_U32            0x00100000U /* Collision retry limit int. enable */
#define ENET_EIMR_UN_U32            0x00080000U /* Transmit FIFO underrun int. enable */
#define ENET_EIMR_PLR_U32           0x00040000U /* PLR Interrupt Mask */
#define ENET_EIMR_WAKEUP_U32        0x00020000U /* WAKEUP Interrupt Mask */
#define ENET_EIMR_TS_AVAIL_U32      0x00010000U /* TS_AVAIL Interrupt Mask */
#define ENET_EIMR_TS_TIMER_U32      0x00008000U /* TS_TIMER Interrupt Mask */
#define ENET_EIMR_ALL_U32           0x7FFF8000U /* All bits */
/* RDAR register bit*/
#define ENET_RDAR_R_DES_ACTIVE_U32  0x01000000U /* Empty Rx buffer exists */
/* TDAR register bit*/
#define ENET_TDAR_X_DES_ACTIVE_U32  0x01000000U /* Empty Tx buffer exists */
/* ECR register bits */
#define ENET_ECR_DBSWP_U32          0x00000100U /* Descriptor Byte Swapping Enable */
#define ENET_ECR_STOPEN_U32         0x00000080U /* Controls device behavior in doze mode */
#define ENET_ECR_DBGEN_U32          0x00000040U /* Debug Enable (freeze mode) */
#define ENET_ECR_EN1588_U32         0x00000010U /* Enable enhanced BDs and functionality */
#define ENET_ECR_SLEEP_U32          0x00000008U /* Sleep Mode Enable */
#define ENET_ECR_MAGICEN_U32        0x00000004U /* Magic Packet Detection Enable */
#define ENET_ECR_ETHEREN_U32        0x00000002U /* Enable the controller
                                                (was ETHER_EN on FEC) */
#define ENET_ECR_RESET_U32          0x00000001U /* Reset the controller */
#define ENET_ECR_SPEED_U32          0x00000020U /* SPEED for switching to Gbs */
#define ENET_ECR_DEFAULT_RESERVED_VALUE_U32          0x70000000U /* Default reset value*/
/* MMFR register bitfield masks and default values */
#define ENET_MMFR_ST_U32            0xC0000000U /* Start of frame delimiter */
#define ENET_MMFR_OP_U32            0x30000000U /* Operation */
#define ENET_MMFR_PA_U32            0x0F800000U /* PHY address */
#define ENET_MMFR_RA_U32            0x007C0000U /* Register address */
#define ENET_MMFR_TA_U32            0x00030000U /* Turn around */
#define ENET_MMFR_DATA_U32          0x0000FFFFU /* Data */
#define ENET_MMFR_ST_VAL_U32        0x40000000U /* 802.3 compliant value for ST field 
                                                    (22.2.4.5.3 in 2008 version) */
#define ENET_MMFR_OP_READ_U32       0x20000000U /* Operation "read" according to 802.3
                                                (22.2.4.5.4 in 2008 version) */
#define ENET_MMFR_OP_WRITE_U32      0x10000000U /* Operation "write" according to 
                                                802.3 (22.2.4.5.4 in 2008 version) */
#define ENET_MMFR_TA_VAL_U32        0x00020000U /* 802.3 compliant value for TA field
                                           (22.2.4.5.7 in 2008 version)  */
/* MSCR register bit mask and bitfield mask */
#define ENET_MCSR_HOLDTIME_U32      0x00000700U /* Speed bitfield mask */ 
#define ENET_MSCR_DIS_PRE_U32       0x00000080U /* Disable preamble 
                                                (was DIS_PREAMBLE on FEC) */
#define ENET_MCSR_MII_SPEED_U32     0x0000007EU /* Speed bitfield mask */ 
/* MIBC register bits */
#define ENET_MIBC_MIB_DIS_U32       0x80000000U /* Disable/enable trigger
                                                (was MIB_DISABLE on FEC) */
#define ENET_MIBC_MIB_IDLE_U32      0x40000000U /* Disable/enable indicator */
#define ENET_MIBC_MIB_CLEAR_U32     0x20000000U /* Clear all statistics */
/* RCR register bits */
#define ENET_RCR_GRS_U32            0x80000000U /* Graceful Receive Stopped */
#define ENET_RCR_NLC_U32            0x40000000U /* Payload Length Check Disable */
#define ENET_RCR_MAX_FL_U32         0x3FFF0000U /* Maximum Frame Length */
#define ENET_RCR_CFEN_U32           0x00008000U /* MAC Control Frame Enable */
#define ENET_RCR_CRCFWD_U32         0x00004000U /* Terminate/Forward Received CRC */
#define ENET_RCR_PAUFWD_U32         0x00002000U /* Terminate/Forward Pause Frames */
#define ENET_RCR_PADEN_U32          0x00001000U /* Enable Frame Padding Remove On RX */
#define ENET_RCR_RMII_10T_U32       0x00000200U /* Enables 10-Mbps mode of the RMII */
#define ENET_RCR_RMII_MODE_U32      0x00000100U /* RMII Mode Enable */
#define ENET_RCR_FCE_U32            0x00000020U /* */
#define ENET_RCR_BC_REJ_U32         0x00000010U /* Reject broadcast */
#define ENET_RCR_PROM_U32           0x00000008U /* Promiscuous mode */
#define ENET_RCR_MII_MODE_U32       0x00000004U /* */
#define ENET_RCR_DRT_U32            0x00000002U /* */
#define ENET_RCR_LOOP_U32           0x00000001U /* Loopback enable */
#define ENET_RCR_INIT_VAL_U32       0x05EE0001U /* Initial register value */

/* TCR register bits */
#define ENET_TCR_RFC_CRCFWD_U32     0x00000200U /* Forward Frame CRC from Application */
#define ENET_TCR_RFC_ADDINS_U32     0x00000100U /* Set MAC Address On Transmit */
#define ENET_TCR_RFC_ADDSEL_U32     0x000000E0U /* Source MAC Address Select On Transmit */
#define ENET_TCR_RFC_PAUSE_U32      0x00000010U /* Receive pause frame */
#define ENET_TCR_TFC_PAUSE_U32      0x00000008U /* Transmit pause frame trigger */ 
#define ENET_TCR_FDEN_U32           0x00000004U /* Full duplex enable */
#define ENET_TCR_GTS_U32            0x00000001U /* Graceful transmit stop */
/* PAUR register bitfields */
#define ENET_PAUR_PADDR2_U32        0xFFFF0000U
#define ENET_PAUR_TYPE_U32          0x0000FFFFU
#define ENET_PAUR_TYPE_INIT_VAL_U32 0x00008808U
/* OPD register bitfields */
#define ENET_OPD_OPCODE_U32         0xFFFF0000U
#define ENET_OPD_PAUSE_DUR_U32      0x0000FFFFU
/* TFWR register bitfield */
#define ENET_TFWR_STR_FWD_U32       0x00000100U
#define ENET_TFWR_TFWR_U32          0x0000003FU
/* RDSR register bitfield */
#define ENET_RDSR_R_DES_START_U32   0xFFFFFFF8U
/* TDSR register bitfield */    
#define ENET_TDSR_X_DES_START_U32   0xFFFFFFF8U
/* MRBR register bitfield */    
#define ENET_MRBR_R_BUF_SIZE_U32    0x00003FF0U
/* New registers, not present on FEC: */
/* ENET_RSEM_ADDR16 register bitfields */   
/** @violates @ref Eth_Enet_h_REF_4 MISRA rule 5.1 */
#define ENET_RSEM_STAT_SECTION_EMPTY_U32    0x001F0000U /* FIFO Threshold Value */
#define ENET_RSEM_RX_SECTION_EMPTY_U32      0x000000FFU /* FIFO Threshold Value */
/* ENET_RAEM_ADDR16 register bitfield */   
#define ENET_RAEM_RX_ALMOST_EMPTY_U32       0x000000FFU /* FIFO Threshold Value */
/* ENET_RAFL_ADDR16 register bitfield */   
#define ENET_RAFL_RX_ALMOST_FULL_U32        0x000000FFU /* FIFO Threshold Value */
/* ENET_TSEM_ADDR16 register bitfield */   
#define ENET_TSEM_TX_SECTION_EMPTY_U32      0x000000FFU /* FIFO Threshold Value */
/* ENET_TAEM_ADDR16 register bitfield */   
#define ENET_TAEM_TX_ALMOST_EMPTY_U32       0x000000FFU /* FIFO Threshold Value */
/* ENET_TAFL_ADDR16 register bitfield */   
#define ENET_TAFL_TX_ALMOST_FULL_U32        0x000000FFU /* FIFO Threshold Value */
/* ENET_RSFL_ADDR16 register bitfield */   
#define ENET_RSFL_RX_SECTION_FULL_U32       0x000000FFU /* FIFO Threshold Value */
/* ENET_TIPG_ADDR16 register bitfield */   
#define ENET_TIPG_IPG_U32                   0x0000001FU /* Transmit Inter-Packet Gap (bytes) */
/* ENET_FTRL_ADDR16 register bitfield */   
#define ENET_FTRL_TRUNC_FL_U32              0x00003FFFU /* Frame Truncation Length */
/* ENET_TACC_ADDR16 register bits */   
#define ENET_TACC_PROCHK_U32                0x00000010U /* Calculation of protocol CRC */
#define ENET_TACC_IPCHK_U32                 0x00000008U /* Calculation of IP CRC */
#define ENET_TACC_SHIFT16_U32               0x00000001U /* Shift frame by 2 bytes in buf */
/* ENET_RACC_ADDR16 register bits */   
#define ENET_RACC_SHIFT16_U32               0x00000080U /* Shift frame by 2 bytes in buf */
#define ENET_RACC_LINEDIS_U32               0x00000040U /* Discard Frames With ETH Errors */
#define ENET_RACC_PRODIS_U32                0x00000004U /* Discard Frames With prot. Errors */
#define ENET_RACC_IPDIS_U32                 0x00000002U /* Discard Frames With IP Errors */
#define ENET_RACC_PADREM_U32                0x00000001U /* Remove Padding from IP frame */
/* ENET_ATCR_ADDR16 register bits */   
#define ENET_ATCR_SLAVE_U32                 0x00002000U /* Enable Timer Slave Mode */
#define ENET_ATCR_CAPTURE_U32               0x00000800U /* Capture Timer Value */
#define ENET_ATCR_RESTART_U32               0x00000200U /* Reset Timer */
#define ENET_ATCR_PINPER_U32                0x00000080U /* Signal assertion (period ev.) */
#define ENET_ATCR_PEREN_U32                 0x00000010U /* Enable Periodical Event */
#define ENET_ATCR_OFFRST_U32                0x00000008U /* Reset Timer On Offset Event */
#define ENET_ATCR_OFFEN_U32                 0x00000004U /* Enable One-Shot Offset Event */
#define ENET_ATCR_EN_U32                    0x00000001U /* Enable Timer */
/* ENET_ATCOR_ADDR16 register bitfield */  
#define ENET_ATCOR_COR_U32                  0x7FFFFFFFU /* Correction Counter Wrap-Around */
/* ENET_ATINC_ADDR16 register bitfields */  
#define ENET_ATINC_INC_CORR_U32             0x00007F00U /* Correction Increment Value */
#define ENET_ATINC_INC_U32                  0x0000007FU /* Clock Period of timestamping clock */
/* ENET_TGSR_ADDR16 register bits */   
#define ENET_TGSR_TF3_W1C                   0x00000008U /* Copy Of Timer Flag channel 3 */
#define ENET_TGSR_TF2_W1C                   0x00000004U /* channel 2 */
#define ENET_TGSR_TF1_W1C                   0x00000002U /* channel 1 */
#define ENET_TGSR_TF0_W1C                   0x00000001U /* channel 0 */
/* ENET_TCSRn register bits/bitfields */  
#define ENET_TCSR_TF_W1C                    0x00000080U /* Timer Flag */
#define ENET_TCSR_TIE_U32                   0x00000040U /* Timer Interrupt Enable */
#define ENET_TCSR_TMODE_U32                 0x0000003CU /* Timer Mode */
#define ENET_TCSR_TDRE_U32                  0x00000001U /* Timer DMA Request Enable */

/***************************************************************************
* Buffer Descriptors Bits
***************************************************************************/
/* RX BDs */
/* Offset + 0 */
#define ENET_RXBD_E_U32      0x80000000U /* Receive buffer empty */
#define ENET_RXBD_R01_U32    0x40000000U /* User bit 1*/
#define ENET_RXBD_W_U32      0x20000000U /* Last descriptor in the ring */
#define ENET_RXBD_RO2_U32    0x10000000U /* User bit 2 */
#define ENET_RXBD_L_U32      0x08000000U /* Last buffer in the received frame */
#define ENET_RXBD_M_U32      0x01000000U /* Frame received in promiscuous mode 
                               (would not be received if not promiscuous)*/
#define ENET_RXBD_BC_U32     0x00800000U /* Frame received as broadcast */
#define ENET_RXBD_MC_U32     0x00400000U /* Frame received as multicast but 
                                   not broadcast */
#define ENET_RXBD_LG_U32     0x00200000U /* Frame length violation */
#define ENET_RXBD_NO_U32     0x00100000U /* Non octet aligned frame */
#define ENET_RXBD_CR_U32     0x00040000U /* CRC error */
#define ENET_RXBD_OV_U32     0x00020000U /* FIFO overrun during reception */
#define ENET_RXBD_TR_U32     0x00010000U /* Frame was longer than 2047B and 
                                                therefore was truncated */
#define ENET_RXBD_LENGTH_U32 0x0000FFFFU /* Buffer length bitfield mask */
/* Offset + 8 */
#define ENET_RXBD_ME_U32     0x80000000U /* MAC error */
#define ENET_RXBD_PE_U32     0x04000000U /* PHY Error */
#define ENET_RXBD_CE_U32     0x02000000U /* Collision */
#define ENET_RXBD_UC_U32     0x01000000U /* Is Unicast */
#define ENET_RXBD_INT_U32    0x00800000U /*  */
#define ENET_RXBD_VPCP_U32   0x0000E000U /* It is a bitfield! */
#define ENET_RXBD_ICE_U32    0x00000020U /*  */
#define ENET_RXBD_PCR_U32    0x00000010U /*  */
#define ENET_RXBD_VLAN_U32   0x00000004U /*  */
#define ENET_RXBD_IPV6_U32   0x00000002U /*  */
#define ENET_RXBD_FRAG_U32   0x00000001U /*  */
/* Offset + 16 */
#define ENET_RXBD_BDU_U32    0x80000000U /* Last BD was updated */

/* TX BDs */
/* Offset + 0 */
#define ENET_TXBD_R_U32      0x80000000U /* Transmit buffer is ready for
                                        transmission (filled with data) */
#define ENET_TXBD_TO1_U32    0x40000000U /* User bit 1 */
#define ENET_TXBD_W_U32      0x20000000U /* Last descriptor in the ring */
#define ENET_TXBD_TO2_U32    0x10000000U /* User bit 2 */
#define ENET_TXBD_L_U32      0x08000000U /* Last buffer in the transmitted frame */
#define ENET_TXBD_TC_U32     0x04000000U /* Compute and append CRC to the frame */
#define ENET_TXBD_LENGTH_U32 0x0000FFFFU /* Buffer length bitfield mask */
/* Offset + 8 */
#define ENET_TXBD_INT_U32    0x40000000U /*  */
#define ENET_TXBD_TS_U32     0x20000000U /* Timestamp */
#define ENET_TXBD_PINS_U32   0x10000000U /*  */
#define ENET_TXBD_IINS_U32   0x08000000U /*  */
#define ENET_TXBD_TXE_U32    0x00008000U /* Transmit error occurred. */
#define ENET_TXBD_UE_U32     0x00002000U /* Underflow error */
#define ENET_TXBD_EE_U32     0x00001000U /* Excess Collision error */
#define ENET_TXBD_FE_U32     0x00000800U /* Frame with error */
#define ENET_TXBD_LCE_U32    0x00000400U /* Late collision error */
#define ENET_TXBD_OE_U32     0x00000200U /* Overflow error */
#define ENET_TXBD_TSE_U32    0x00000100U /* Timestamp error */
/* Offset + 16 */
#define ENET_TXBD_BDU_U32    0x80000000U /* Last BD was updated */

/***************************************************************************
* TX Buffer Status Bits
***************************************************************************/
/** @brief    Status bit for TX buffer flags, TRUE -> buffer is locked */
#define ENET_TXB_LOCK_U8  (0x08U)
/** @brief    Status bit for TX buffer flags, TRUE -> TxConfirmation pending */
#define ENET_TXB_CONF_U8  (0x04U)
/** @brief    Status bit for TX buffer flags, TRUE -> buffer linked with BD */
#define ENET_TXB_LINK_U8  (0x02U)
/** @brief    Status bit for TX buffer flags, TRUE -> first buffer of frame */
#define ENET_TXB_FIRST_U8 (0x01U)


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/***************************************************************************
* Macros To Access Registers, MIB Counters, Buffers and their Descriptors
***************************************************************************/
/* The size of register space of Enet is 4KB */
#define ENET_PROT_MEM_U32 ((uint32)0x04U)
 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief Type used to return receive buffer status
*/
typedef enum
{
    RX_BUF_EMPTY = 0,         /**< Buffer is empty */
    RX_BUF_SINGLE,            /**< Buffer is full and the received frame
                                                  is within single buffer */
    RX_BUF_MULTI_UNFINISHED,  /**< Buffer is full but the frame reception
                                                has not been finished yet */
    RX_BUF_MULTI_FINISHED,    /**< Buffer is full and it is the last buffer
                              in the row of buffers occupied by one frame */
    RX_BUF_OVERFLOW           /**< Some frame occupies all available buffers
                                      so there is no space to put its end */ 
} Eth_Enet_enRxBufferType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ETH_START_SEC_VAR_INIT_8
/** @violates @ref Eth_Enet_h_REF_3 MISRA rule 19.1 */
/** @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"

extern VAR(volatile uint8, ETH_VAR) Eth_u8ActiveRxBuf[ETH_MAXCTRLS_SUPPORTED];
extern VAR(volatile uint8, ETH_VAR) Eth_u8ActiveTxBD[ETH_MAXCTRLS_SUPPORTED];
extern VAR(uint8, ETH_VAR) Eth_u8LockedBuffer[ETH_MAXCTRLS_SUPPORTED];
extern VAR(uint8, ETH_VAR) Eth_u8LockedTxBufCount[ETH_MAXCTRLS_SUPPORTED];
#define ETH_STOP_SEC_VAR_INIT_8
/** @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"
#define ETH_START_SEC_VAR_INIT_BOOLEAN
/** @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"
extern VAR(boolean, ETH_VAR) Eth_bLockedBufferUsed[ETH_MAXCTRLS_SUPPORTED];
#define ETH_STOP_SEC_VAR_INIT_BOOLEAN
/** @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"


/** @violates @ref Eth_Enet_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Enet_h_REF_4 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 */
#include "Eth_MemMap.h"

/** @violates @ref Eth_Enet_h_REF_5 MISRA rule 8.7 */
extern P2CONST(Eth_ConfigType, ETH_VAR, ETH_APPL_CONST) Eth_InternalCfgPtr;
#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
/**
* @brief          Used for internal storage of local time
* @details        This variable is used to store the value for current time including 48 bits for second 
*                 and 32 bits for nanosecond part. 
*
* @note           This variable exists only if the the time stamp is used.
*
*/
extern VAR(Eth_TimeStampType, ETH_VAR) Eth_LocalTime[ETH_MAXCTRLS_SUPPORTED];
#endif

/** @violates @ref Eth_Enet_h_REF_1 MISRA rule 1.4 
* @violates @ref Eth_Enet_h_REF_4 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
/** 
* @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 
* @violates @ref Eth_Enet_h_REF_3 MISRA rule 19.1
*/
#include "Eth_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_START_SEC_CODE
/** 
* @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 
* @violates @ref Eth_Enet_h_REF_3 MISRA rule 19.1
*/
#include "Eth_MemMap.h"

#ifdef ERR_IPV_ENET_0001
    #if STD_ON == ERR_IPV_ENET_0001
extern FUNC(void, ETH_CODE)Eth_Enet_ERR006358(CONST(uint8, AUTOMATIC) u8CtrlIdx);
    #endif /* STD_ON == ERR_IPV_ENET_0001 */
#endif /* ERR_IPV_ENET_0001 */
extern FUNC(void, ETH_CODE) Eth_Enet_ResetController (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_CheckAccessToCtrl (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_ClearMIBCounters (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_ConfigureTxBuffers (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_ConfigureRxBuffers (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_ConfigureCtrl (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_EnableController (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_DisableController (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(Eth_ModeType, ETH_CODE) Eth_Enet_CheckCtrlIsActive (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(uint16, ETH_CODE) Eth_Enet_GetPhysAddressHigh (CONST(uint8, AUTOMATIC) u8CtrlIdx);
#ifdef ETH_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == ETH_ENABLE_USER_MODE_SUPPORT)
#ifdef ETH_ENET_REG_PROT_AVAILABLE    
extern FUNC(void, ETH_CODE) Eth_Enet_SetUserAccessAllowed(void);
#endif /* STD_ON == ETH_ENABLE_USER_MODE_SUPPORT */
#endif
#endif
extern FUNC(uint32, ETH_CODE) Eth_Enet_GetPhysAddressLow (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_SetPhysAddr ( \
                                        CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                        P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                                    );
#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    extern FUNC(void, ETH_CODE) Eth_Enet_UpdtePhysAddrFiltr  ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
                VAR(Eth_FilterActionType, AUTOMATIC) eAction \
                                                             );
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */
extern FUNC(void, ETH_CODE) Eth_Enet_ClearTxIrqFlag (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(void, ETH_CODE) Eth_Enet_ClearRxIrqFlag (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_IsTxIrqFlagSet (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_IsRxIrqFlagSet (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_IsTxIrqEnabled (CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_IsRxIrqEnabled (CONST(uint8, AUTOMATIC) u8CtrlIdx);
#if STD_ON == ETH_GLOBALTIME_SUPPORT
extern FUNC(void, ETH_CODE) Eth_Enet_GetCurrentTime    ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                                );
extern FUNC(void, ETH_CODE) Eth_Enet_GetEgressTimeStamp  ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                VAR(uint8, AUTOMATIC) u8BufIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                        );
extern FUNC(void, ETH_CODE) Eth_Enet_GetIngressTimeStamp ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) pDataPtr, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                        );
extern FUNC(void, ETH_CODE) Eth_Enet_SetCorrectionTime   ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETH_APPL_CONST) pTimeOffsetPtr, \
                                P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_APPL_CONST) pRateRatioPtr \
                                                        );
extern FUNC(void, ETH_CODE)  Eth_Enet_SetGlobalTime     ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_APPL_CONST) pTimeStampPtr \
                                                       );
#endif
extern FUNC(boolean, ETH_CODE) Eth_Enet_BorrowTxBuffer ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONSTP2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) pBufIdx, \
                    P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pData, \
                    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pLength \
                                                       );
extern FUNC(boolean, ETH_CODE) Eth_Enet_IsTxBufLockedBT ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONST(Eth_BufIdxType, AUTOMATIC) u8Buf \
                                                        );
extern FUNC(void, ETH_CODE) Eth_Enet_Transmit   (
                    CONST(uint8, AUTOMATIC) u8CtrlIdx,
                    CONST(Eth_BufIdxType, AUTOMATIC) u8Buf,
                    CONST(Eth_FrameType, AUTOMATIC) u16Type,
                    CONST(uint16, AUTOMATIC) u16Length,
                    CONST(boolean, AUTOMATIC) bConfirm,
                    P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) pDest
#if STD_ON == ETH_BRIDGE_SUPPORT
                  , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) pSource 
#endif /* ETH_BRIDGE_SUPPORT  */
                                                );
    
#if STD_ON == ETH_CTRLENABLE_MII
    extern FUNC(boolean, ETH_CODE) Eth_Enet_DoMiiMMF    ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONST(uint8, AUTOMATIC) u8Trcv, \
                    CONST(uint8, AUTOMATIC) u8Reg, \
                    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pData, \
                    CONST(uint32, AUTOMATIC) u32Operation \
                                                        );
#endif /* ETH_CTRLENABLE_MII */

#if STD_ON == ETH_GETDROPCOUNTAPI
extern FUNC(void, ETH_CODE) Eth_Enet_GetDropCount  ( \
                              CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                              P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pCountValuesPtr, \
                              P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pDropCountPtr \
                                                  );
#endif

#if STD_ON == ETH_GET_ETHERSTATS_API
extern FUNC(void, ETH_CODE) Eth_Enet_GetEtherStats     ( \
                      CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                      P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pEtherStats \
                                                      );
#endif
extern FUNC(void, ETH_CODE) Eth_Enet_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, ETH_CODE) Eth_Enet_ClearTimerWrapFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(boolean, ETH_CODE) Eth_Enet_IsTimerWrapEvent(CONST(uint8, AUTOMATIC) u8CtrlIdx);

extern FUNC(boolean, ETH_CODE) Eth_Enet_ReportTransmission(CONST(uint8, AUTOMATIC) u8CtrlIdx);
extern FUNC(Eth_RxStatusType, ETH_CODE) Eth_Enet_ReportReception(CONST(uint8, AUTOMATIC) u8CtrlIdx, CONST(boolean, AUTOMATIC) bIrq);
#define ETH_STOP_SEC_CODE
/** 
* @violates @ref Eth_Enet_h_REF_2 MISRA rule 19.15 
* @violates @ref Eth_Enet_h_REF_3 MISRA rule 19.1
*/
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_ENET_LLD_H */
/** @} */
