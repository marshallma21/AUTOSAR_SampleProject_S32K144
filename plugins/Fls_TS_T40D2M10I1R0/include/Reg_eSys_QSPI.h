/**
*   @file    Reg_eSys_FLASHC.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - Defines used to access the Flash registers.
*   @details This file contains defines used to access the Flash registers.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
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

#ifndef REG_ESYS_QSPI_H
#define REG_ESYS_QSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_FLASHC_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Reg_eSys_FLASHC_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/**
* @violates @ref Reg_eSys_FLASHC_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ESYS_QSPI_VENDOR_ID                           43
#define ESYS_QSPI_AR_RELEASE_MAJOR_VERSION            4
#define ESYS_QSPI_AR_RELEASE_MINOR_VERSION            2
#define ESYS_QSPI_AR_RELEASE_REVISION_VERSION         2
#define ESYS_QSPI_SW_MAJOR_VERSION                    1
#define ESYS_QSPI_SW_MINOR_VERSION                    0
#define ESYS_QSPI_SW_PATCH_VERSION                    1

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ESYS_QSPI_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (ESYS_QSPI_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_QSPI.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* QSPI registers byte offsets */
#define QSPI_MCR_OFFSET_U32                 ((uint32)0x000UL)
#define QSPI_IPCR_OFFSET_U32                ((uint32)0x008UL)
#define QSPI_FLSHCR_OFFSET_U32              ((uint32)0x00CUL)
#define QSPI_BUFXCR_OFFSET_U32              ((uint32)0x010UL)
#define QSPI_BUF0CR_OFFSET_U32              ((uint32)0x010UL)
#define QSPI_BUF1CR_OFFSET_U32              ((uint32)0x014UL)
#define QSPI_BUF2CR_OFFSET_U32              ((uint32)0x018UL)
#define QSPI_BUF3CR_OFFSET_U32              ((uint32)0x01CUL)
#define QSPI_BFGENCR_OFFSET_U32             ((uint32)0x020UL)
#define QSPI_SOCCR_OFFSET_U32               ((uint32)0x024UL)
#define QSPI_BUFXIND_OFFSET_U32             ((uint32)0x030UL)
#define QSPI_BUF0IND_OFFSET_U32             ((uint32)0x030UL)
#define QSPI_BUF1IND_OFFSET_U32             ((uint32)0x034UL)
#define QSPI_BUF2IND_OFFSET_U32             ((uint32)0x038UL)
#define QSPI_SFAR_OFFSET_U32                ((uint32)0x100UL)
#define QSPI_SFACR_OFFSET_U32               ((uint32)0x104UL)
#define QSPI_SMPR_OFFSET_U32                ((uint32)0x108UL)
#define QSPI_RBSR_OFFSET_U32                ((uint32)0x10CUL)
#define QSPI_RBCT_OFFSET_U32                ((uint32)0x110UL)
#define QSPI_TBSR_OFFSET_U32                ((uint32)0x150UL)
#define QSPI_TBDR_OFFSET_U32                ((uint32)0x154UL)
#define QSPI_TBCT_OFFSET_U32                ((uint32)0x158UL)
#define QSPI_SR_OFFSET_U32                  ((uint32)0x15CUL)
#define QSPI_FR_OFFSET_U32                  ((uint32)0x160UL)
#define QSPI_RSER_OFFSET_U32                ((uint32)0x164UL)
#define QSPI_SPNDST_OFFSET_U32              ((uint32)0x168UL)
#define QSPI_SPTRCLR_OFFSET_U32             ((uint32)0x16CUL)
#define QSPI_SFA1AD_OFFSET_U32              ((uint32)0x180UL)
#define QSPI_SFA2AD_OFFSET_U32              ((uint32)0x184UL)
#define QSPI_SFB1AD_OFFSET_U32              ((uint32)0x188UL)
#define QSPI_SFB2AD_OFFSET_U32              ((uint32)0x18CUL)
#define QSPI_DLPR_OFFSET_U32                ((uint32)0x190UL)
#define QSPI_RBDR_OFFSET_U32                ((uint32)0x200UL)
#define QSPI_LUTKEY_OFFSET_U32              ((uint32)0x300UL)
#define QSPI_LCKCR_OFFSET_U32               ((uint32)0x304UL)
#define QSPI_LUT_OFFSET_U32                 ((uint32)0x310UL)

/* RX BUFFER - AHB interface base address through ARDBx registers. */
/* Kinetis integration specific. */
#define QSPI_0_ARDB_BASEADDR_U32            ((uint32)0x67000000UL)

/* QSPI registers word offsets */
#define QSPI_MCR_WORD_OFFSET_U32            ((uint32)0x000UL)
#define QSPI_IPCR_WORD_OFFSET_U32           ((uint32)0x002UL)
#define QSPI_FLSHCR_WORD_OFFSET_U32         ((uint32)0x003UL)
#define QSPI_BUFXCR_WORD_OFFSET_U32         ((uint32)0x004UL)
#define QSPI_BUF0CR_WORD_OFFSET_U32         ((uint32)0x004UL)
#define QSPI_BUF1CR_WORD_OFFSET_U32         ((uint32)0x005UL)
#define QSPI_BUF2CR_WORD_OFFSET_U32         ((uint32)0x006UL)
#define QSPI_BUF3CR_WORD_OFFSET_U32         ((uint32)0x007UL)
#define QSPI_BFGENCR_WORD_OFFSET_U32        ((uint32)0x008UL)
#define QSPI_SOCCR_WORD_OFFSET_U32          ((uint32)0x009UL)
#define QSPI_BUFXIND_WORD_OFFSET_U32        ((uint32)0x00CUL)
#define QSPI_BUF0IND_WORD_OFFSET_U32        ((uint32)0x00CUL)
#define QSPI_BUF1IND_WORD_OFFSET_U32        ((uint32)0x00DUL)
#define QSPI_BUF2IND_WORD_OFFSET_U32        ((uint32)0x00EUL)
#define QSPI_SFAR_WORD_OFFSET_U32           ((uint32)0x040UL)
#define QSPI_SFACR_WORD_OFFSET_U32          ((uint32)0x041UL)
#define QSPI_SMPR_WORD_OFFSET_U32           ((uint32)0x042UL)
#define QSPI_RBSR_WORD_OFFSET_U32           ((uint32)0x043UL)
#define QSPI_RBCT_WORD_OFFSET_U32           ((uint32)0x044UL)
#define QSPI_TBSR_WORD_OFFSET_U32           ((uint32)0x054UL)
#define QSPI_TBDR_WORD_OFFSET_U32           ((uint32)0x055UL)
#define QSPI_TBCT_WORD_OFFSET_U32           ((uint32)0x056UL)
#define QSPI_SR_WORD_OFFSET_U32             ((uint32)0x057UL)
#define QSPI_FR_WORD_OFFSET_U32             ((uint32)0x058UL)
#define QSPI_RSER_WORD_OFFSET_U32           ((uint32)0x059UL)
#define QSPI_SPNDST_WORD_OFFSET_U32         ((uint32)0x05AUL)
#define QSPI_SPTRCLR_WORD_OFFSET_U32        ((uint32)0x05BUL)
#define QSPI_SFA1AD_WORD_OFFSET_U32         ((uint32)0x060UL)
#define QSPI_SFA2AD_WORD_OFFSET_U32         ((uint32)0x061UL)
#define QSPI_SFB1AD_WORD_OFFSET_U32         ((uint32)0x062UL)
#define QSPI_SFB2AD_WORD_OFFSET_U32         ((uint32)0x063UL)
#define QSPI_DLPR_WORD_OFFSET_U32           ((uint32)0x064UL)
#define QSPI_RBDR_WORD_OFFSET_U32           ((uint32)0x080UL)
#define QSPI_LUTKEY_WORD_OFFSET_U32         ((uint32)0x0C0UL)
#define QSPI_LCKCR_WORD_OFFSET_U32          ((uint32)0x0C1UL)
#define QSPI_LUT_WORD_OFFSET_U32            ((uint32)0x0C4UL)


#define QSPI_MCR_MDIS_U32                       ((uint32)0x00004000UL)  /* MDIS - Module Disable.           QSPI_MCR[14] */
#define QSPI_MCR_DDR_EN_U32                     ((uint32)0x00000080UL)  /* DDR_EN - DDR mode enable.        QSPI_MCR[7] */
#define QSPI_MCR_DQS_EN_U32                     ((uint32)0x00000040UL)  /* DQS_EN - DQS enable.             QSPI_MCR[6] */
#define QSPI_MCR_DQS_LAT_EN_U32                 ((uint32)0x00000020UL)  /* DQS_LAT_EN - DQS Latency enable. QSPI_MCR[5] */
#define QSPI_MCR_COARSE_DLY_SHIFT_U32           (29U)           /* Bit position of Coarse delay position inside QSPI_MCR. */
#define QSPI_MCR_END_MASK_U32                   ((uint32)0x0000000CUL)  /* END_CFG - Endianness. QSPI_MCR[3:2] */
#define QSPI_MCR_END_SHIFT_U32                  (2U)            /* Bit position of Endianness configuration inside QSPI_MCR. */
#define QSPI_MCR_CLR_TXF_U32                    ((uint32)0x00000800UL)  /* Clear TX FIFO. Invalidates the TX Buffer.*/                   
#define QSPI_MCR_CLR_RXF_U32                    ((uint32)0x00000400UL)  /* Clear RX FIFO. Invalidates the RX Buffer.*/                   
#define QSPI_MCR_SWRSTHD_U32                    ((uint32)0x00000002UL)  /* MCR[1] - Software reset for AHB domain. */
#define QSPI_MCR_SWRSTSD_U32                    ((uint32)0x00000001UL)  /* MCR[0] - Software reset for serial flash domain. */


/* Kinetis integration specific. */
#define QSPI_MCR_PADS_BUF_EN_U32                ((uint32)0x80000000UL)  /* SCLKCFG[7] - Enables input buffer of QSPI pads for SDR and HyperRAM modes.    QSPI_MCR[31] */
#define QSPI_MCR_INPUT_CLK_SEL_U32              ((uint32)0x40000000UL)  /* SCLKCFG[6] - Quadspi Clocking mode selection. Always program SCLKCFG[6] twice while configuring mode selection.    QSPI_MCR[30] */
#define QSPI_MCR_HYPERRAM_SEL_U32               ((uint32)0x20000000UL)  /* SCLKCFG[5] - HyperRAM selection for Flash B - Reference clock selection for DQS for Flash-B.    QSPI_MCR[29] */
#define QSPI_MCR_INTERN_REF_CLK_SEL_U32         ((uint32)0x10000000UL)  /* SCLKCFG[4] - Internal reference clock (async clock domain) source selection for Quadspi.    QSPI_MCR[28] */
#define QSPI_MCR_DQS_B_STAGE2_CLK_SRC_U32       ((uint32)0x08000000UL)  /* SCLKCFG[3] - Reference clock selection for DQS for Flash-B.    QSPI_MCR[27] */
#define QSPI_MCR_DQS_B_STAGE1_CLK_SRC_U32       ((uint32)0x04000000UL)  /* SCLKCFG[2] - Reference clock selection for DQS for Flash-B.    QSPI_MCR[26] */
#define QSPI_MCR_DQS_A_STAGE2_CLK_SRC_U32       ((uint32)0x02000000UL)  /* SCLKCFG[1] - Reference clock selection for DQS for Flash-A.    QSPI_MCR[25] */
#define QSPI_MCR_DQS_A_STAGE1_CLK_SRC_U32       ((uint32)0x01000000UL)  /* SCLKCFG[0] - Reference clock selection for DQS for Flash-A.    QSPI_MCR[24] */

#define QSPI_MCR_ISD3FB_U32                     ((uint32)0x00080000UL)  /* Idle Signal Drive IOFB[3] Flash B. */
#define QSPI_MCR_ISD2FB_U32                     ((uint32)0x00040000UL)  /* Idle Signal Drive IOFB[2] Flash B. */
#define QSPI_MCR_ISD3FA_U32                     ((uint32)0x00020000UL)  /* Idle Signal Drive IOFA[3] Flash A. */
#define QSPI_MCR_ISD2FA_U32                     ((uint32)0x00010000UL)  /* Idle Signal Drive IOFA[2] Flash A. */
                    
#define QSPI_SMPR_DDRSMP_MASK_U32               ((uint32)0x00070000UL)  /* SMPR[18:16] - DDR Sampling point. */
#define QSPI_SMPR_DDRSMP_SHIFT_U32              (16U)           /* Bit position of DDRSMP field. */
#define QSPI_SMPR_FSPHS_U32                     ((uint32)0x00000020UL)  /* FSPHS - Full Speed Phase selection for SDR instructions and DQS DDR mode.    QSPI_SMPR[5] */
#define QSPI_SMPR_FSDLY_U32                     ((uint32)0x00000040UL)  /* FSDLY - Full Speed Delay selection for SDR instructions and DQS DDR mode.    QSPI_SMPR[6] */

#define QSPI_FLSHCR_TDH_MASK_U32                ((uint32)0x00030000UL)  /* TDH - Serial flash data in hold time.   QSPI_FLSHCR[17:16] */
#define QSPI_FLSHCR_TDH_SHIFT_U32               (16U)           /* TDH - Serial flash data in hold time.   QSPI_FLSHCR[17:16] */
#define QSPI_FLSHCR_TCSH_MASK_U32               ((uint32)0x00000F00UL)  /* TCSH - Serial flash CS hold time.   QSPI_FLSHCR[11:8] */
#define QSPI_FLSHCR_TCSH_SHIFT_U32              (8U)            /* TCSH - Serial flash CS hold time.   QSPI_FLSHCR[11:8] */
#define QSPI_FLSHCR_TCSS_MASK_U32               ((uint32)0x0000000FUL)  /* TCSS - Serial flash CS setup time.   QSPI_FLSHCR[3:0] */
#define QSPI_FLSHCR_TCSS_SHIFT_U32              (0U)            /* TCSS - Serial flash CS setup time.   QSPI_FLSHCR[3:0] */

#define QSPI_RBCT_RXBRD_MASK_U32                ((uint32)0x100UL)


#define QSPI_SOCCR_FINE_DLY_A_MASK_U32          ((uint32)0x000000FFUL)  /* SOCCFG[7:0] - Fine delay chain configuration for Flash A.   QSPI_SOCCR[7:0] */
#define QSPI_SOCCR_FINE_DLY_B_MASK_U32          ((uint32)0x0000FF00UL)  /* SOCCFG[15:8] - Fine delay chain configuration for Flash B.  QSPI_SOCCR[15:8] */
#define QSPI_SOCCR_FINE_DLY_A_SHIFT_U32         (0U)            /* Bit position of fine delay chain configuration for Flash A. */
#define QSPI_SOCCR_FINE_DLY_B_SHIFT_U32         (8U)            /* Bit position of fine delay chain configuration for Flash B. */
#define QSPI_SOCCR_PENDIG_READ_GASKET_U32       ((uint32)0x00010000UL)  /* SOCCFG[16] - Pending read enable controls the bus gasket’s handling of pending read transactions. */
#define QSPI_SOCCR_BURST_READ_GASKET_U32        ((uint32)0x00020000UL)  /* SOCCFG[17] - Burst read enable controls the bus gasket’s handling of burst read transactions. */
#define QSPI_SOCCR_BURST_WRITE_GASKET_U32       ((uint32)0x00040000UL)  /* SOCCFG[18] - Burst writes enable controls the bus gasket’s handling of burst read transactions. */
#define QSPI_SOCCR_PROGRAM_DIVIDER_MASK_U32     ((uint32)0xE0000000UL)  /* SOCCFG[31:29] - Programmable divider configuration selection. */
#define QSPI_SOCCR_PROGRAM_DIVIDER_SHIFT_U32    (29U)
#define QSPI_SOCCR_DIVIDER_EN_U32               ((uint32)0x10000000UL)  /* SOCCFG[28] - Programmable Divider Enable. */

#define QSPI_BUFxCR_MSTRID_MASK_U32             ((uint32)0x00000000FUL)

#define QSPI_BUFxCR_ADATSZ_MASK_U32             ((uint32)0x0000FF00UL)
#define QSPI_BUFxCR_ADATSZ_SHIFT_U32            ((uint32)8UL)
#define QSPI_BUF3CR_ALLMST_MASK_U32             ((uint32)0x80000000UL)  /* BUF3CR[31] - All master enable */
#define QSPI_BUF0CR_HP_EN_MASK_U32              ((uint32)0x80000000UL)  /* BUF0CR[31] - High Priority Enable*/

#define QSPI_LCKCR_MASK_U32                     ((uint32)0x00000003UL)
#define QSPI_LCKCR_LOCKED_U32                   ((uint32)0x00000001UL)
#define QSPI_LCKCR_UNLOCKED_U32                 ((uint32)0x00000002UL)

#define QSPI_LUT_KEY_VALUE_U32                  ((uint32)0x5AF05AF0UL)  /* The key to lock or unlock the LUT. */

#define QSPI_SR_BUSY_U32                        ((uint32)0x00000001UL)  /* Module Busy. BUSY == 1 when module is busy. */
#define QSPI_SR_RXWE_U32                        ((uint32)0x00010000UL)  /* RX Buffer Watermark Exceeded. RXWE == 1 when the number of valid entries in the RX Buffer exceeds the number given in the QSPI_RBCT[WMRK] field. */

#define QSPI_FR_TBFF_U32                        ((uint32)0x08000000UL)  /* FR[27] TX Buffer Fill Flag. */
#define QSPI_FR_TBUF_U32                        ((uint32)0x04000000UL)  /* FR[26] TX Buffer Underrun Flag. */
#define QSPI_FR_ILLINE_U32                      ((uint32)0x00800000UL)  /* FR[23] Illegal Instruction Error Flag */
#define QSPI_FR_RBOF_U32                        ((uint32)0x00020000UL)  /* FR[17] RX Buffer Overflow Flag. */
#define QSPI_FR_RBDF_U32                        ((uint32)0x00010000UL)  /* FR[16] RX Buffer Drain Flag. Writting 1 POPs WMRK+1 entries from the RXBuffer. */
#define QSPI_FR_ABSEF_U32                       ((uint32)0x00008000UL)  /* FR[15] AHB Sequence Error Flag. */
#define QSPI_FR_AITEF_U32                       ((uint32)0x00004000UL)  /* FR[14] AHB Illegal transaction error flag. */
#define QSPI_FR_AIBSEF_U32                      ((uint32)0x00002000UL)  /* FR[13] AHB Illegal Burst Size Error Flag. */
#define QSPI_FR_ABOF_U32                        ((uint32)0x00001000UL)  /* FR[12] AHB Buffer Overflow Flag. */
#define QSPI_FR_IUEF_U32                        ((uint32)0x00000800UL)  /* FR[11] IP Command Usage Error Flag - parallel mode. */
#define QSPI_FR_IPAEF_U32                       ((uint32)0x00000080UL)  /* FR[7] IP Command Trigger during AHB Access Error Flag. */
#define QSPI_FR_IPIEF_U32                       ((uint32)0x00000040UL)  /* FR[6] IP Command Trigger could not be executed Error Flag.*/
#define QSPI_FR_IPGEF_U32                       ((uint32)0x00000010UL)  /* FR[4] IP Command Trigger during AHB Grant Error Flag. */
#define QSPI_FR_TFF_U32                         ((uint32)0x00000001UL)  /* FR[0] IP Command Transaction Finished Flag. */

#define QSPI_RSER_DLPFIE_U32                    ((uint32)0x80000000UL) /* RSER[31] Data Learning Pattern Failure Interrupt enable. */
#define QSPI_RSER_TBFIE_U32                     ((uint32)0x08000000UL) /* RSER[27] TX Buffer Fill Interrupt Enable. */
#define QSPI_RSER_TBUIE_U32                     ((uint32)0x04000000UL) /* RSER[26] TX Buffer Underrun Interrupt Enable. */
#define QSPI_RSER_TBFDE_U32                     ((uint32)0x02000000UL) /* RSER[25] TX Buffer Fill DMA Enable. */
#define QSPI_RSER_ILLINIE_U32                   ((uint32)0x00800000UL) /* RSER[23] Illegal Instruction Error Interrupt Enable. */
#define QSPI_RSER_RBDDE_U32                     ((uint32)0x00200000UL) /* RSER[21] RX Buffer Drain DMA Enable. */
#define QSPI_RSER_RBOIE_U32                     ((uint32)0x00020000UL) /* RSER[17] RX Buffer Overflow Interrupt Enable. */
#define QSPI_RSER_RBDIE_U32                     ((uint32)0x00010000UL) /* RSER[16] RX Buffer Drain Interrupt Enable. */
#define QSPI_RSER_ABSEIE_U32                    ((uint32)0x00008000UL) /* RSER[15] AHB Sequence Error Interrupt Enable. */
#define QSPI_RSER_AITIE_U32                     ((uint32)0x00004000UL) /* RSER[14] AHB Illegal transaction interrupt enable. */
#define QSPI_RSER_AIBSIE_U32                    ((uint32)0x00002000UL) /* RSER[13] AHB Illegal Burst Size Interrupt Enable. */
#define QSPI_RSER_ABOIE_U32                     ((uint32)0x00001000UL) /* RSER[12] AHB Buffer Overflow Interrupt Enable. */
#define QSPI_RSER_IUEIE_U32                     ((uint32)0x00000800UL) /* RSER[11] IP Command Usage Error Interrupt Enable. */
#define QSPI_RSER_IPAEIE_U32                    ((uint32)0x00000080UL) /* RSER[7]  IP Command Trigger during AHB Access Error Interrupt Enable. */
#define QSPI_RSER_IPIEIE_U32                    ((uint32)0x00000040UL) /* RSER[6]  IP Command Trigger during IP Access Error Interrupt Enable. */
#define QSPI_RSER_IPGEIE_U32                    ((uint32)0x00000010UL) /* RSER[4]  IP Command Trigger during AHB Grant Error Interrupt Enable. */
#define QSPI_RSER_TFIE_U32                      ((uint32)0x00000001UL) /* RSER[0]  Transaction Finished Interrupt Enable. */

#define QSPI_RBCT_WMRK_MASK_U32                 ((uint32)0x0000001FUL)  /* RBCT[4:0] - WMRK bitifield mask. */
#define QSPI_RBCT_WMRK_SHIFT_U32                ((uint32)0x00000000UL)  /* RBCT[4:0] - WMRK bitifield position shift. */

#define QSPI_IPCR_SEQID_MASK_U32                ((uint32)0xF000000UL)   /* IPCR[27:24] SEQID field. */
#define QSPI_IPCR_SEQID_SHIFT_U32               (24U)
#define QSPI_IPCR_IDATSZ_MASK_U32               ((uint32)0x000FFFFUL)   /* IPCR[15:0] IDATSZ field. */
#define QSPI_IPCR_IDATSZ_SHIFT_U32              (0U)
#define QSPI_IPCR_PAR_EN_SHIFT_U32              (16U)           /* IPCR[16] PAR_EN bit. */

#define QSPI_LUT_INSTR0_OPER0_OFFSET_U32        ((uint32)0UL)            /* [INSTR0|PAD0|OPRND0] = LUTx[15:0]*/
#define QSPI_LUT_INSTR0_OPER0_MASK_U32          ((uint32)0x0000FFFFUL)
#define QSPI_LUT_INSTR1_OPER1_OFFSET_U32        ((uint32)16UL)           /* [INSTR1|PAD1|OPRND1] = LUTx[31:16]*/
#define QSPI_LUT_INSTR1_OPER1_MASK_U32          ((uint32)0xFFFF0000UL)

#define QSPI_RBSR_RDBFL_MASK_U32                ((uint32)0x00003F00UL)  /* RBSR[13:8] */
#define QSPI_RBSR_RDBFL_SHIFT_U32               (8U)

#define QSPI_SPTRCLR_IPPTRC_MASK_U32            ((uint32)0x00000100UL)  /* SPTRCLR[8] IP Pointer Clear */
#define QSPI_SPTRCLR_BFPTRC_MASK_U32            ((uint32)0x00000001UL)  /* SPTRCLR[0] Buffer Pointer Clear */

#define QSPI_BFGENCR_SEQID_MASK_U32             ((uint32)0x0000F000UL)  /* BFGENCR[15:12] */
#define QSPI_BFGENCR_SEQID_SHIFT_U32            (12U)
#define QSPI_BFGENCR_PAR_EN_SHIFT_U32           (16U)           /* BFGENCR[16] PAR_EN bit. */

#define QSPI_SFACR_WA_U32                       ((uint32)0x00010000UL)  /* SFACR[16] WA bit. */
#define QSPI_SFACR_CAS_MASK_U32                 ((uint32)0x0000000FUL)  /* SFACR[3:0] CAS bit. */
#define QSPI_SFACR_CAS_SHIFT_U32                (0U)


/* Kinetis integration specific. */
#define QSPI_QSPI_0_AMBA_BASE_U32               ((uint32)0x68000000UL)  /* Base address of Serial flash memory address asignement (upon which memory ch, ChipSelect is determined). */
#define QSPI_QSPI_1_AMBA_BASE_U32               ((uint32)0x68000000UL)  /* Base address of Serial flash memory address asignement (upon which memory ch, ChipSelect is determined). */

#define QSPI_RXBUFFER_MAX_SIZE_BYTES_U32        (128U)          /* Maximum size of RX Buffer in bytes, 32 entries x 4bytes each.*/
#define QSPI_RXBUFFER_MAX_SIZE_WORDS_U32        (32U)           /* Maximum size of RX Buffer in words("entries"), 32 entries x 4bytes each.*/

#define QSPI_TXBUFFER_MAX_SIZE_BYTES_U32        (128U)          /* Maximum size of TX Buffer in bytes, 32 entries x 4bytes each.*/
#define QSPI_TXBUFFER_MAX_SIZE_WORDS_U32        (32U)           /* Maximum size of TX Buffer in words("entries"), 32 entries x 4bytes each.*/

#define QSPI_TXBUFFER_MIN_SIZE_BYTES_U32        (16U)           /* Minimum size of TX Buffer in bytes, 32 entries x 4bytes each.*/
#define QSPI_TXBUFFER_MIN_SIZE_WORDS_U32        (4U)            /* Minimum size of TX Buffer in words("entries"), 32 entries x 4bytes each.*/

#define QSPI_PARALLEL_MODE_ENABLED              (1U)
#define QSPI_PARALLEL_MODE_DISABLED             (0U)

/********* LUT instruction type ************/
#define FLS_LUT_INSTR_STOP          (0U)
#define FLS_LUT_INSTR_CMD           (1U)
#define FLS_LUT_INSTR_ADDR          (2U)
#define FLS_LUT_INSTR_DUMMY         (3U)
#define FLS_LUT_INSTR_MODE          (4U)
#define FLS_LUT_INSTR_MODE2         (5U)
#define FLS_LUT_INSTR_MODE4         (6U)
#define FLS_LUT_INSTR_READ          (7U)
#define FLS_LUT_INSTR_WRITE         (8U)
#define FLS_LUT_INSTR_JMP_ON_CS     (9U)
#define FLS_LUT_INSTR_ADDR_DDR      (10U)
#define FLS_LUT_INSTR_MODE_DDR      (11U)
#define FLS_LUT_INSTR_MODE2_DDR     (12U)
#define FLS_LUT_INSTR_MODE4_DDR     (13U)
#define FLS_LUT_INSTR_READ_DDR      (14U)
#define FLS_LUT_INSTR_WRITE_DDR     (15U)
#define FLS_LUT_INSTR_DATA_LEARN    (16U)
#define FLS_LUT_INSTR_CMD_DDR       (17U)
#define FLS_LUT_INSTR_CADDR         (18U)
#define FLS_LUT_INSTR_CADDR_DDR     (19U)

#define FLS_LUT_OPER_16BIT_ADDR     (16U)
#define FLS_LUT_OPER_24BIT_ADDR     (24U)
#define FLS_LUT_OPER_32BIT_ADDR     (32U)


#define FLS_LUT_HYPER_WRITE_MEM_WRAP    (0x00U)
#define FLS_LUT_HYPER_WRITE_MEM_LINEAR  (0x20U)
#define FLS_LUT_HYPER_WRITE_REG_WRAP    (0x40U)
#define FLS_LUT_HYPER_WRITE_REG_LINEAR  (0x60U)
#define FLS_LUT_HYPER_READ_MEM_WRAP     (0x80U)
#define FLS_LUT_HYPER_READ_MEM_LINEAR   (0xA0U)
#define FLS_LUT_HYPER_READ_REG_WRAP     (0xC0U)
#define FLS_LUT_HYPER_READ_REG_LINEAR   (0xE0U)
#define FLS_LUT_HYPER_NOP               (0x00U)

#define FLS_LUT_SEQ_ID_0_U      (0U)
#define FLS_LUT_SEQ_ID_1_U      (1U)
#define FLS_LUT_SEQ_ID_2_U      (2U)
#define FLS_LUT_SEQ_ID_3_U      (3U)
#define FLS_LUT_SEQ_ID_4_U      (4U)
#define FLS_LUT_SEQ_ID_5_U      (5U)
#define FLS_LUT_SEQ_ID_6_U      (6U)
#define FLS_LUT_SEQ_ID_7_U      (7U)
#define FLS_LUT_SEQ_ID_8_U      (8U)
#define FLS_LUT_SEQ_ID_9_U      (9U)
#define FLS_LUT_SEQ_ID_10_U     (10U)
#define FLS_LUT_SEQ_ID_11_U     (11U)
#define FLS_LUT_SEQ_ID_12_U     (12U)
#define FLS_LUT_SEQ_ID_13_U     (13U)
#define FLS_LUT_SEQ_ID_14_U     (14U)
#define FLS_LUT_SEQ_ID_15_U     (15U)       /* The last LUT, reserved for Hyperflash volatile commands loading. */

#define FLS_NO_OF_LUTS_U8       (64U)

#define FLS_HYPERF_TYPE_1_ADDR_U32        ((uint32)0xAAAUL)   /* Byte address 0xAAA will be sent to Hyperflash memory as 0x555, when WA bit is set. */
#define FLS_HYPERF_TYPE_2_ADDR_U32        ((uint32)0x554UL)   /* Byte address 0x554 will be sent to Hyperflash memory as 0x2AA, when WA bit is set. */
#define FLS_HYPERF_TYPE_3_ADDR_U32        ((uint32)0xAAUL)    /* Byte address 0xAA will be sent to Hyperflash memory as 0x55, when WA bit is set. */
#define FLS_HYPERF_TYPE_4_ADDR_U32        ((uint32)0x0UL)     /* Byte address 0x0 will be sent to Hyperflash memory as 0x0, when WA bit is set. */



#define FLS_HYPERF_STATUS_REG_READ_ID_U8    (0x70U)
#define FLS_HYPERF_SECTOR_ERASE_ID_U8       (0x30U)
#define FLS_HYPERF_WRITE_BUFFER_ID_U8       (0x25U)

#define FLS_HYPERF_LINE_SIZE_U32    ((uint32)512UL) /* Each hypeflash line is 512 bytes long. */

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_QSPI_H*/

/** @} */
