/**
*   @file    Reg_eSys_FlexCan.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - MPC560xB FlexCan Registers and Macros Definitions.
*   @details Header file for MPC560xB FlexCan Registers and Macros Definitions.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FLEXCAN
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


#ifndef REG_ESYS_FLEXCAN_H
#define REG_ESYS_FLEXCAN_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Reg_eSys_FlexCan_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_FlexCan_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Reg_eSys_FlexCan_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */
#include "Reg_eSys.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Internal micro-dependent versioning.
*/
#define CAN_VENDOR_ID_REGFLEX                    43
#define CAN_MODULE_ID_REGFLEX                    80
#define CAN_AR_RELEASE_MAJOR_VERSION_REGFLEX     4
#define CAN_AR_RELEASE_MINOR_VERSION_REGFLEX     2
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_3 Violates MISRA 2004 Required Rule 1.4, Identifier clash
*/
#define CAN_AR_RELEASE_REVISION_VERSION_REGFLEX  2
#define CAN_SW_MAJOR_VERSION_REGFLEX             1
#define CAN_SW_MINOR_VERSION_REGFLEX             0
#define CAN_SW_PATCH_VERSION_REGFLEX             1
/**@}*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define REGION_LENGTH (512U)
#define ARBITRATION_FIELD (8U)

/* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/   
#define FLEXCAN_MB_OFFSET(mb) ((((&(Can_pCurrentConfig->MBConfigContainer))->pMessageBufferConfigsPtr) + (mb))->u16MBOffsetAddr)

/*******************************************************************************************************************************/



#define     FLEXCAN_32BITS_NO   32

/**
* @brief Macro for Control Register (CTRL) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_RESERVED_MASK(value, null_mask , reserved_mask )    (((value) & (null_mask)) | (reserved_mask))   


#define FLEXCAN_ERRSR_CONFIG_MASK_U32       ((uint32)0x000D000DU)

#define FLEXCAN_MCR_NULL_MASK_U32           ((uint32)0xF2A3F37FU)
#define FLEXCAN_MCR_RESERVED_MASK_U32       ((uint32)0x08100000U)
#define FLEXCAN_CTRL_CONFIG_MASK_U32        ((uint32)0xFFFFFCFFU)
#define FLEXCAN_ECR_CONFIG_MASK_U32         ((uint32)0x0000FFFFU)
#define FLEXCAN_ESR_CONFIG_MASK_U32         ((uint32)0x00030006U)
#define FLEXCAN_IMASK2_CONFIG_MASK_U32      ((uint32)0xFFFFFFFFU)
#define FLEXCAN_IMASK1_CONFIG_MASK_U32      ((uint32)0xFFFFFFFFU)
#define FLEXCAN_IFLAG1_CONFIG_MASK_U32      ((uint32)0xFFFFFFFFU)
#define FLEXCAN_IFLAG2_CONFIG_MASK_U32      ((uint32)0xFFFFFFFFU)
#define FLEXCAN_RXGMASK_CONFIG_MASK_U32     ((uint32)0xFFFFFFFFU)
#define FLEXCAN_RXFGMASK_CONFIG_MASK_U32    ((uint32)0xFFFFFFFFU)
#define FLEXCAN_RX15MASK_CONFIG_MASK_U32    ((uint32)0xFFFFFFFFU)
#define FLEXCAN_RX14MASK_CONFIG_MASK_U32    ((uint32)0xFFFFFFFFU)

#define FLEXCAN_8_BYTES_U32                 ((uint32)0x00000008U)
#define FLEXCAN_16_BYTES_U32                ((uint32)0x00000010U)
#define FLEXCAN_32_BYTES_U32                ((uint32)0x00000020U)
#define FLEXCAN_64_BYTES_U32                ((uint32)0x00000040U)

/**
* @brief Register mask value used for Full can hardware objects.
*/
#define FLEXCAN_NO_MASK_U32                 ((uint32)0xFFFFFFFFU)
/**
* @brief Start memory address offset for a Can controller
*/
#define FLEXCAN_MEMORY_START_U32            ((uint32)0x00000080U)
/**
* @brief End memory address offset for a Can controller
*/
#if (CPU_BYTE_ORDER==HIGH_BYTE_FIRST)
    #define FLEXCAN_MEMORY_END_U32          ((uint32)0x00000ADFU)
#elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST)
    #define FLEXCAN_MEMORY_END_U32          ((uint32)0x0000047FU)
#endif
/**
* @brief Memory size reserved for one Can controller
*/
#define FLEXCAN_OFFSET_U32                  ((uint32)0x00004000U)
/**
* @brief Offset for the first MB
*/
#define FLEXCAN_MB_OFFSET_U32               ((uint32)0x00000080U)
/**
* @brief Offset for the RXIMR register
*/
#define FLEXCAN_RXIMR_OFFSET_U32            ((uint32)0x00000880U)
/**
* @brief Mask for 32 bits register
*/
#define FLEXCAN_32BITMASK_U32               ((uint32)0xFFFFFFFFU)
/**
* @brief Mask for 8 bits of IMASK registers that are reserved for Fifo
*/
#define FLEXCAN_FIFO_MASK_U32               ((uint32)0x000000FFU)
/**
* @brief Define for left shifting 5 bits.
*/
#define FLEXCAN_MB_SHIFT5BIT_U8             ((uint8)0x05U)
/**
* @brief Offset of the CAN_WMB_CS register store configuration of the Message Wake-up.
*/
#define FLEXCAN_CAN_WMB_CS_U32              ((uint32)0x00000B40U)
/**
* @brief Offset of the CAN_WMB_ID register store ID of the Message Wake-up.
*/
#define FLEXCAN_CAN_WMB_ID_U32              ((uint32)0x00000B44U)
/**
* @brief Offset of the CAN_WMB_D03 register store form data number 0 to data number 3 of the Message Wake-up.
*/
#define FLEXCAN_CAN_WMB_D03_U32             ((uint32)0x00000B48U)
/**
* @brief Offset of the CAN_WMB_D47 register store form data number 4 to data number 7 of the Message Wake-up.
*/
#define FLEXCAN_CAN_WMB_D47_U32             ((uint32)0x00000B4CU)
/**
* @brief Offset of the Standard ID in the ID reg of MB.
*/
#define FLEXCAN_STANDARD_ID_SHIFT_U32       ((uint32)18U)
/**
* @brief Offset of the LENGTH field in the MBCS register of MB.
*/
#define FLEXCAN_MBCS_LENGTH_SHIFT_U32       ((uint32)16U)
/**
* @brief Offset of the PRIO field in ID register of the MB.
*/
#define FLEXCAN_MB_ID_PRIO_SHIFT_U32        ((uint32)28U)
/**
* @brief Mask for 32 index values (0 to 31 indexes).
*/
#define FLEXCAN_MASK_32BITS_U32             ((uint32)0x0000001FU)

/**
* @{
* @brief Current architectures of FLEXcan have 32 or 64 MBs for each controller
*/
#define FLEXCAN_MB_32_U8                    32U
#define FLEXCAN_MB_64_U8                    64U
#define FLEXCAN_MB_96_U8                    96U
/**@}*/

/**
* @{
* @brief Define for MB data
*/
#define FLEXCAN_MB_DATABYTE_REG_U32         ((uint32)4U)
#define FLEXCAN_MB_DATABYTE_FIRST_U32       ((uint32)0xFF000000U)
#define CAN_FLEXCAN_8_BYTES_PAYLOAD_U32     ((uint32)0x00080000U)
#define FLEXCAN_DATA_LENGTH_OFFSET_U8       ((uint8) 0x08U)
#define FLEXCAN_DATA_LENGTH_MIN_U8          ((uint8) 0x08U)
#define FLEXCAN_DATA_LENGTH_MAX_U8          ((uint8) 0x0FU)
/**@}*/

/**
* @{
* @maximum threshold values for DLC
*/
#define CAN_FLEXCAN_MAX_PAYLOAD8_U8      ((uint8)8U)
#define CAN_FLEXCAN_MAX_PAYLOAD12_U8     ((uint8)12U)
#define CAN_FLEXCAN_MAX_PAYLOAD16_U8     ((uint8)16U)
#define CAN_FLEXCAN_MAX_PAYLOAD20_U8     ((uint8)20U)
#define CAN_FLEXCAN_MAX_PAYLOAD24_U8     ((uint8)24U)
#define CAN_FLEXCAN_MAX_PAYLOAD32_U8     ((uint8)32U)
#define CAN_FLEXCAN_MAX_PAYLOAD48_U8     ((uint8)48U)
#define CAN_FLEXCAN_MAX_PAYLOAD64_U8     ((uint8)64U)
/**@}*/

/**
* @{
* @minimum threshold values for DLC
*/
#define CAN_FLEXCAN_MIN_PAYLOAD0_U8      ((uint8)0U)
#define CAN_FLEXCAN_MIN_PAYLOAD9_U8      ((uint8)9U)
#define CAN_FLEXCAN_MIN_PAYLOAD13_U8     ((uint8)13U)
#define CAN_FLEXCAN_MIN_PAYLOAD17_U8     ((uint8)17U)
#define CAN_FLEXCAN_MIN_PAYLOAD21_U8     ((uint8)21U)
#define CAN_FLEXCAN_MIN_PAYLOAD25_U8     ((uint8)25U)
#define CAN_FLEXCAN_MIN_PAYLOAD33_U8     ((uint8)33U)
#define CAN_FLEXCAN_MIN_PAYLOAD49_U8     ((uint8)49U)
/**@}*/

/**
* @{
* @number of maximum values in data length code region
*/
#define CAN_FLEXCAN_NUM_VAL_DLC_U8     ((uint8)8U)
/**@}*/

/**
* @{
* @brief Define for filter's payload
*/
#define CAN_FLEXCAN_FILTER_PAYLOAD7_U8       ((uint8)7U)
#define CAN_FLEXCAN_FILTER_PAYLOAD9_U8       ((uint8)9U)
#define CAN_FLEXCAN_FILTER_PAYLOAD11_U8      ((uint8)11U)
#define CAN_FLEXCAN_FILTER_PAYLOAD13_U8      ((uint8)13U)
#define CAN_FLEXCAN_FILTER_PAYLOAD15_U8      ((uint8)15U)
#define CAN_FLEXCAN_FILTER_PAYLOAD17_U8      ((uint8)17U)
#define CAN_FLEXCAN_FILTER_PAYLOAD19_U8      ((uint8)19U)
#define CAN_FLEXCAN_FILTER_PAYLOAD21_U8      ((uint8)21U)
#define CAN_FLEXCAN_FILTER_PAYLOAD23_U8      ((uint8)23U)
#define CAN_FLEXCAN_FILTER_PAYLOAD25_U8      ((uint8)25U)
#define CAN_FLEXCAN_FILTER_PAYLOAD27_U8      ((uint8)27U)
#define CAN_FLEXCAN_FILTER_PAYLOAD29_U8      ((uint8)29U)
#define CAN_FLEXCAN_FILTER_PAYLOAD31_U8      ((uint8)31U)
#define CAN_FLEXCAN_FILTER_PAYLOAD33_U8      ((uint8)33U)
#define CAN_FLEXCAN_FILTER_PAYLOAD35_U8      ((uint8)35U)
#define CAN_FLEXCAN_FILTER_PAYLOAD37_U8      ((uint8)37U)
/**@}*/

/**
* @{
* @number of maximum values in data length code region
*/
#define CAN_FLEXCAN_NUM_FILT_PAYLOAD_U8     ((uint8)16U)
/**@}*/


#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
/**
* @{
* @brief Define for MB data and interrupt mask initialization value
*/
#define FLEXCAN_MB_14_U8                    ((uint8)14U)
#define FLEXCAN_MB_15_U8                    ((uint8)15U)
#define FLEXCAN_TABLE_ID6_U8                ((uint8)6U)
#define FLEXCAN_TABLE_ID7_U8                ((uint8)7U)
#define FLEXCAN_INTERRUPT_MASKS_INIT_VALUE_U8   ((uint8)0x0U)
/**@}*/
#endif

/**
* @brief Define used for Can_ControlerDescriptorType.u8ControllerOffset when controller is not enabled.
*/
#define FLEXCAN_NULL_OFFSET_U8              ((uint8)0xFFU)



/*==================================================================================================
                BIT MASKS FOR SOFTWARE ERROR FLAGS
==================================================================================================*/
/**
* @brief CTRL: busoff software flag
*/
#define FLEXCAN_SWF_BOFF_MASK_U8            ((uint8)0x02U)
/**
* @brief CTRL: error software flag
*/
#define FLEXCAN_SWF_ERR_MASK_U8             ((uint8)0x04U)
/**
* @brief IMASK2, IMASK1: message buffers software flags
*/
#define FLEXCAN_SWF_MB_MASK_U8              ((uint8)0x08U)
/**
* @brief MCR: tx/rx warning interrupts software flags
*/
#define FLEXCAN_SWF_WRNINT_MASK_U8          ((uint8)0x10U)


/*==================================================================================================
                CONTROLLER OPTIONS
==================================================================================================*/
/**
* @{
* @brief Controller options - set by the Tresos configuration
*/
#define CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32    ((uint32)0x00000001U)
#define CAN_CONTROLLERCONFIG_RXFIFO_U32         ((uint32)0x00000002U)
#define CAN_CONTROLLERCONFIG_IDAM_A_U32         ((uint32)0x00000004U)
#define CAN_CONTROLLERCONFIG_IDAM_B_U32         ((uint32)0x00000008U)
#define CAN_CONTROLLERCONFIG_IDAM_C_U32         ((uint32)0x00000010U)
#define CAN_CONTROLLERCONFIG_IDAM_D_U32         ((uint32)0x00000020U)
#define CAN_CONTROLLERCONFIG_WAKEUP_SRC_U32     ((uint32)0x00000040U)
#define CAN_CONTROLLERCONFIG_LPRIO_EN_U32       ((uint32)0x00000080U)
#define CAN_CONTROLLERCONFIG_OVER_EN_U32        ((uint32)0x00000100U)
#define CAN_CONTROLLERCONFIG_WARN_EN_U32        ((uint32)0x00000200U)
#define CAN_CONTROLLERCONFIG_RXPOL_EN_U32       ((uint32)0x00000400U)
#define CAN_CONTROLLERCONFIG_TXPOL_EN_U32       ((uint32)0x00000800U)
#define CAN_CONTROLLERCONFIG_BOPOL_EN_U32       ((uint32)0x00001000U)
#define CAN_CONTROLLERCONFIG_WKPOL_EN_U32       ((uint32)0x00002000U)
#define CAN_CONTROLLERCONFIG_WRNINT_EN_U32      ((uint32)0x00004000U)
#define CAN_CONTROLLERCONFIG_WAKSUP_EN_U32      ((uint32)0x00008000U)
#define CAN_CONTROLLERCONFIG_ERR_EN_U32         ((uint32)0x00020000U)
#if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
    #define CAN_CONTROLLERCONFIG_BCC_EN_U32     ((uint32)0x00010000U)
#endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
#define CAN_CONTROLLERCONFIG_IDAM_MASK_U32      ((uint32)0x0000003CU)
/**@}*/

/*==================================================================================================
                            MESSAGE BUFFER BIT MASKS FOR ALL STRUCTURE
==================================================================================================*/
/**
* @brief MB code: bits 27:24 in CS reg
*/
#define FLEXCAN_MBCS_CODE_U32                   ((uint32)0x0F000000U)
/**
* @brief MB code: message buffer used for Tx
*/
#define FLEXCAN_MBCS_CODETX_U32                 ((uint32)0x08000000U)
/**
* @brief MB code: Transmit contents of Tx message buffer
*/
#define FLEXCAN_MBCS_CODETXEN_U32               ((uint32)0x04000000U)
/**
* @brief MB code: transmit the message whenever a remote frame with a matching ID is received
*/
#define FLEXCAN_MBCS_CODETXRTR_U32              ((uint32)0x02000000U)
/**
* @brief MB code: Abort transmission
*/
#define FLEXCAN_MBCS_CODETXABORT_U32            ((uint32)0x01000000U)
/**
* @brief MB code: Message buffer used for Rx
*/
#define FLEXCAN_MBCS_CODERX_U32                 ((uint32)0x00000000U)
/**
* @brief MB code: Rx message buffer overrun (a new message arrived before the previous one was picked-up)
*/
#define FLEXCAN_MBCS_CODERXOVRR_U32             ((uint32)0x06000000U)
/**
* @brief MB code: Rx message buffer empty
*/
#define FLEXCAN_MBCS_CODERXEMPTY_U32            ((uint32)0x04000000U)
/**
* @brief MB code: Rx message buffer is full (a new message has arrived)
*/
#define FLEXCAN_MBCS_CODERXFULL_U32             ((uint32)0x02000000U)
/**
* @brief MB code: MB busy and cannot be read
*/
#define FLEXCAN_MBCS_CODERXBUSY_U32             ((uint32)0x01000000U)
/**
* @brief SRR bit, must be written as '1' in any Tx MB
*/
#define FLEXCAN_MBCS_SRR_U32                    ((uint32)0x00400000U)
/**
* @brief IDE bit, 0=standard ID, 1=extended ID
*/
#define FLEXCAN_MBCS_IDE_U32                    ((uint32)0x00200000U)
/**
* @brief RTR bit, 0=data frame, 1=remote frame
*/
#define FLEXCAN_MBCS_RTR_U32                    ((uint32)0x00100000U)
/**
* @brief DLC (data length code)
*/
#define FLEXCAN_MBCS_LENGTH_U32                 ((uint32)0x000F0000U)
/**
* @brief Time stamp of Rx and Tx frames (timer value captured at the time the beginning of the ID appears on the bus)
*/
#define FLEXCAN_MBCS_TIMESTAMP_U32              ((uint32)0x0000FFFFU)
/**
* @brief Local Tx priority (added in front of the ID to determine Tx priority)
*/
#define FLEXCAN_MBID_PRIO_U32                   ((uint32)0xE0000000U)
/**
* @brief Extended (bits 0-28) ID
*/
#define FLEXCAN_MBID_ID_EXTENDED_U32            ((uint32)0x1FFFFFFFU)
/**
* @brief IDE flag used in extended ID mode to identify whether the ID is Extended/Standard.(According to Can_IdType from SWS_Can_Driver.pdf of ASR3.0)
*/
#define FLEXCAN_MBC_ID_IDE_U32                  ((uint32)0x80000000U)
/**
* @brief Standard (bits 18-28) ID
*/
#define FLEXCAN_MBID_ID_STANDARD_U32            ((uint32)0x1FFC0000U)




/*==================================================================================================
                    INTERRUPT MASKS & FLAGS REGISTERS:
                        IMASK2 (Base + 0x0024); IMASK1 (Base + 0x0028)
                        IFLAG2 (Base + 0x002C); IFLAG1 (Base + 0x0030)
==================================================================================================*/
/**
* @{
* @brief Imask and Iflag index registers
*/
#if (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8 )
  #define FLEXCAN_IMASK3_INDEX_U8               ((uint8)2U)
  #define FLEXCAN_IMASK2_INDEX_U8               ((uint8)1U)
  #define FLEXCAN_IFLAG3_INDEX_U8               ((uint8)2U)
  #define FLEXCAN_IFLAG2_INDEX_U8               ((uint8)1U)
#endif

#define FLEXCAN_IMASK1_INDEX_U8               ((uint8)0U)
#define FLEXCAN_IFLAG1_INDEX_U8               ((uint8)0U)

/**@}*/

/*==================================================================================================
                BIT MASKS FOR MODULE CONFIGURATION REGISTER: MCR (Base+0x0000)
==================================================================================================*/
/**
* @brief MCR bit31: Module Disable (module disabled when 1)
*/
#define FLEXCAN_MCR_MDIS_U32                    ((uint32)0x80000000U)
/**
* @brief MCR bit30: Freeze enable (enable to enter freeze mode when HALT is set)
*/
#define FLEXCAN_MCR_FRZ_U32                     ((uint32)0x40000000U)
/**
* @brief MCR bit29: FIFO mode enable
*/
#define FLEXCAN_MCR_FEN_U32                     ((uint32)0x20000000U)
/**
* @brief MCR bit28: Module Halt (module enters freeze mode when this bit is set providing the FRZ bit is set)
*/
#define FLEXCAN_MCR_HALT_U32                    ((uint32)0x10000000U)
/**
* @brief MCR bit27: Module Not Ready (either disabled or in freeze mode)
*/
#define FLEXCAN_MCR_NOTRDY_U32                  ((uint32)0x08000000U)
/**
* @brief MCR bit26: Wake Up Interrupt Mask (1 = Wake Up Interrupt is enabled, 0 = Wake Up Interrupt is disabled)
*/
#define FLEXCAN_MCR_WAK_MSK_U32                 ((uint32)0x04000000U)
/**
* @brief MCR bit25: Module Soft Reset (the bit remains set until reset is completed)
*/
#define FLEXCAN_MCR_SOFTRST_U32                 ((uint32)0x02000000U)
/**
* @brief MCR bit24: Freeze Mode Acknowledge
*/
#define FLEXCAN_MCR_FRZACK_U32                  ((uint32)0x01000000U)
/**
* @brief MCR bit23: Supervisor Mode (1 = Affected registers are in Supervisor memory space.
* @details    MCR bit23: Supervisor Mode (1 = Affected registers are in Supervisor memory space.
* Any access without supervisor permission behaves as though the access was done
*    to an unimplemented register location 0 = Affected registers are in Unrestricted memory space)
*/
#define FLEXCAN_MCR_SUPV_U32                    ((uint32)0x00800000U)
/**
* @brief MCR bit22: Self Wakeup from Doze or Stop modes
*/
#define FLEXCAN_MCR_SLF_WAK_U32                 ((uint32)0x00400000U)
/**
* @brief MCR bit21: Warning interrupt enable (TWRNINT and RWRNINT flags generate an iterrupt if set)
*/
#define FLEXCAN_MCR_WRNEN_U32                   ((uint32)0x00200000U)
/**
* @brief MCR bit20: Module Disable Acknowledge
*/
#define FLEXCAN_MCR_LPMACK_U32                  ((uint32)0x00100000U)
/**
* @brief MCR bit19: Wake Up Source
* @details MCR bit19: Wake Up Source (1 = FlexCAN uses the filtered Rx input to detect recessive to dominant edges on the CAN bus,
*                                     0 = FlexCAN uses the unfiltered Rx input to detect recessive to dominant edges on the CAN bus)
*/
#define FLEXCAN_MCR_WAK_SRC_U32                 ((uint32)0x00080000U)
/**
* @brief MCR bit18: Doze Mode Enable
* @details MCR bit18: Doze Mode Enable (1 = FlexCAN is enabled to enter low power mode when Doze
*                                   Mode is requested, 0 = FlexCAN is not enabled to enter low power mode when Doze Mode is requested)
*/
#define FLEXCAN_MCR_DOZE_U32                    ((uint32)0x00040000U)
/**
* @brief MCR bit17: Self Rx Disable (module will receive its own Tx messages when cleared)
*/
#define FLEXCAN_MCR_SRXDIS_U32                  ((uint32)0x00020000U)
/**
* @brief MCR bit16: Backwards Compatibility Configuration (individual message buffer masks are used when set, global & MB14,MB15 masks are used when cleared)
*/
#define FLEXCAN_MCR_BCC_U32                     ((uint32)0x00010000U)
#if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/**
* @brief MCR bit15: Pretended Networking feature (only Calypso Platform)
*/
#define FLEXCAN_PNET_ENABLE_U32                 ((uint32)0x00004000U)
#define FLEXCAN_CTRL1_PN_NMATCH_U32             ((uint32)0x0000FF00U)
#define FLEXCAN_CTRL2_PN_MATCHTO_U32            ((uint32)0x0000FFFFU)
#define FLEXCAN_CAN_FLT_ID1_U32                 ((uint32)0x7FFFFFFFU)
#define FLEXCAN_CAN_FLT_ID2_IDMASK_U32          ((uint32)0x7FFFFFFFU)
#define FLEXCAN_CAN_FLT_DLC_U32                 ((uint32)0x000F000FU)
#define FLEXCAN_CTRL1_PN_CONFIG_U32             ((uint32)0x0003003FU) 
#define FLEXCAN_CTRL1_PN_WTOF_U32               ((uint32)0x00020000U)
#define FLEXCAN_CTRL1_PN_WUMF_U32               ((uint32)0x00010000U)
#define FLEXCAN_WU_MTC_MCOUNTER                 ((uint32)0x0000FF00U)
#define FLEXCAN_WU_MTC_WUMF_MSK_U32             ((uint32)0x00010000U)
#define FLEXCAN_WU_MTC_WTOF_MSK_U32             ((uint32)0x00020000U)
#define FLEXCAN_WU_MTC_WUMF_MSK_W1C             ((uint32)0x00010000U)
#define FLEXCAN_WU_MTC_WTOF_MSK_W1C             ((uint32)0x00020000U)
#define FLEXCAN_CAN_WMB_ID_IDMB_U32             ((uint32)0x1FFFFFFFU)
#define FLEXCAN_CAN_WMB_CS_DLC_U32              ((uint32)0x000F0000U)
#define FLEXCAN_CAN_WMB_CS_IDE_U32              ((uint32)0x00200000U)
#define FLEXCAN_EXACTLY_PAYLOAD_U32             ((uint32)0x00000000U)
#define FLEXCAN_GREATER_PAYLOAD_U32             ((uint32)0x00000010U)
#define FLEXCAN_SMALLER_PAYLOAD_U32             ((uint32)0x00000020U)
#define FLEXCAN_INSIDE_RANGE_PAYLOAD_U32        ((uint32)0x00000030U)
#define FLEXCAN_EXACTLY_ID_U32                  ((uint32)0x00000000U)
#define FLEXCAN_GREATER_ID_U32                  ((uint32)0x00000004U)
#define FLEXCAN_SMALLER_ID_U32                  ((uint32)0x00000008U)
#define FLEXCAN_INSIDE_RANGE_ID_U32             ((uint32)0x0000000CU)
#endif
/**
* @brief MCR bit13: Local Priority Enable (the PRIO field in Tx MB ID is used when set)
*/
#define FLEXCAN_MCR_LPRIOEN_U32                 ((uint32)0x00002000U)
/**
* @brief MCR bit12: Abort Enable (Tx abort is enabled when set)
*/
#define FLEXCAN_MCR_AEN_U32                     ((uint32)0x00001000U)
/**
* @brief MCR bit9-8: ID acceptance mode for the FIFO mode
*/
#define FLEXCAN_MCR_IDAM_U32                    ((uint32)0x00000300U)
/**
* @brief             ID acceptance mode: one standard or extended ID
*/
#define FLEXCAN_MCR_IDAM32_U32                  ((uint32)0x00000000U)
/**
* @brief             ID acceptance mode: two standard or partial extended IDs
*/
#define FLEXCAN_MCR_IDAM16_U32                  ((uint32)0x00000100U)
/**
* @brief             ID acceptance mode: four partial standard or extended IDs
*/
#define FLEXCAN_MCR_IDAM08_U32                  ((uint32)0x00000200U)
/**
* @brief MCR bit5-0: Maximum number of MBs in use (field value plus 1)
*/
#define FLEXCAN_MCR_MAXMB_U32                   ((uint32)0x0000003FU)


/*==================================================================================================
                BIT MASKS FOR CONTROL REGISTER: CTRL (Base+0x0004)
==================================================================================================*/
/**
* @brief CTRL bit31-24: Clock divider (clock is divided by field value plus 1)
*/
#define FLEXCAN_CTRL_PRESDIV_U32                ((uint32)0xFF000000U)
/**
* @brief CTRL bit23-22: Resynchronization jump width (the width is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_RJW_U32                    ((uint32)0x00C00000U)
/**
* @brief CTRL bit21-19: Phase segment 1 (length of the segment is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_PSEG1_U32                  ((uint32)0x00380000U)
/**
* @brief CTRL bit18-16: Phase segment 2 (length of the segment is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_PSEG2_U32                  ((uint32)0x00070000U)
/**
* @brief CTRL bit15: Bus Off Mask (bus off interrupt enabled when set)
*/
#define FLEXCAN_CTRL_BOFFMSK_U32                ((uint32)0x00008000U)
/**
* @brief CTRL bit14: Error Mask (error interrupt enabled when set)
*/
#define FLEXCAN_CTRL_ERRMSK_U32                 ((uint32)0x00004000U)
/**
* @brief CTRL bit12: Loop-Back mode (loop-back mode enabled when set)
*/
#define FLEXCAN_CTRL_LPB_U32                    ((uint32)0x00001000U)
/**
* @brief CTRL bit11: Tx Warning interrupt enable (enabled when bit is set)
*/
#define FLEXCAN_CTRL_TWRNMSK_U32                ((uint32)0x00000800U)
/**
* @brief CTRL bit10: Rx Warning interrupt enable (enabled when bit is set)
*/
#define FLEXCAN_CTRL_RWRNMSK_U32                ((uint32)0x00000400U)
/**
* @brief CTRL bit7: Sampling mode (0=1 sample, 1=3 samples)
*/
#define FLEXCAN_CTRL_SMP_U32                    ((uint32)0x00000080U)
/**
* @brief CTRL bit6: Bus off recovery mode (0=automatic, 1=manual)
*/
#define FLEXCAN_CTRL_BOFFREC_U32                ((uint32)0x00000040U)
/**
* @brief CTRL bit5: Timer Synchronization (when set the free-running timer is reset each time a message is received into MB0)
*/
#define FLEXCAN_CTRL_TSYN_U32                   ((uint32)0x00000020U)
/**
* @brief CTRL bit4: Lowest Buffer First (0=highest priority buffer transmitted first, 1=lowest numbered buffer transmitted first)
*/
#define FLEXCAN_CTRL_LBUF_U32                   ((uint32)0x00000010U)
/**
* @brief CTRL bit3: Listen only mode (listen only mode is enabled when bit is set)
*/
#define FLEXCAN_CTRL_LOM_U32                    ((uint32)0x00000008U)
/**
* @brief CTRL bit2-0: Propagation Segment (length of the segment is field value plus 1 time quantum)
*/
#define FLEXCAN_CTRL_PROPSEG_U32                ((uint32)0x00000007U)

/*==================================================================================================
                BIT MASKS FOR SHIFTING CONTROL REGISTER VALUES
==================================================================================================*/
/**
* @{
* @brief Offset bits for CTRL register
*/
#define FLEXCAN_CTRL_PRESDIV_SHIFT_U8           ((uint8)24U)
#define FLEXCAN_CTRL_RJW_SHIFT_U8               ((uint8)22U)
#define FLEXCAN_CTRL_PSEG1_SHIFT_U8             ((uint8)19U)
#define FLEXCAN_CTRL_PSEG2_SHIFT_U8             ((uint8)16U)
#define FLEXCAN_CTRL_CLKSRC_SHIFT_U8            ((uint8)13U)
#define FLEXCAN_CTRL_LPB_SHIFT_U8               ((uint8)12U)
#define FLEXCAN_CTRL_SMP_SHIFT_U8               ((uint8) 7U)
#define FLEXCAN_CTRL_BOFFREC_SHIFT_U8           ((uint8) 6U)
#define FLEXCAN_CTRL_LBUF_SHIFT_U8              ((uint8) 4U)
#define FLEXCAN_CTRL_LOM_SHIFT_U8               ((uint8) 3U)
/**@}*/

/**
* @{
* @brief Offset bits for CTRL2 register
*/
#define FLEXCAN_CTRL2_TASD_SHIFT_U32            ((uint32)19U)

/*Offset bits for FD register*/
#define FLEXCAN_FD_OFFSET_U8                    ((uint8)11U)
#define FLEXCAN_FD_PROPSEG_OFFSET_U8            ((uint8)10U)
#define FLEXCAN_FD_PSEG1_OFFSET_U8              ((uint8) 5U)
#define FLEXCAN_FD_PSEG2_OFFSET_U8              ((uint8) 0U) 
#define FLEXCAN_FD_SJW_OFFSET_U8                ((uint8)16U) 
#define FLEXCAN_FD_BRS_OFFSET_U8                ((uint8)31U)
#define FLEXCAN_MBDSR0_OFFSET_U8                ((uint8)16U)
#define FLEXCAN_MBDSR1_OFFSET_U8                ((uint8)19U)
#define FLEXCAN_MBDSR2_OFFSET_U8                ((uint8)22U)
#define FLEXCAN_FD_PRESDIV_OFFSET_U8            ((uint8)20U)
#define FLEXCAN_FDCTRL_TDCOFF_OFFSET_U8         ((uint8) 8U)
#define FLEXCAN_FD_CTRL2_STFCNTEN_SHIFT_U32     ((uint32)12U)
#define FLEXCAN_FD_CTRL2_EDFLTDIS_SHIFT_U32     ((uint32)11U)
#define FLEXCAN_FD_CTRL2_PREXCEN_SHIFT_U32      ((uint32)14U)

#define CAN_8_BYTES_PAYLOAD_U32     ((uint32)0U)
#define CAN_16_BYTES_PAYLOAD_U32    ((uint32)1U)
#define CAN_32_BYTES_PAYLOAD_U32    ((uint32)2U)
#define CAN_64_BYTES_PAYLOAD_U32    ((uint32)3U)

#ifdef CAN_EXTENDEDID
    #if (CAN_EXTENDEDID == STD_ON)
        #define CAN_FD_ID_DESCRIPTOR            ((uint32)0x40000000)       
    #else /* (CAN_EXTENDEDID == STD_OFF) */
    #define CAN_FD_ID_DESCRIPTOR                ((uint16)0x4000)       
    #endif /* (CAN_EXTENDEDID == STD_ON/STD_OFF) */
#endif              

#define FLEXCAN_REMOVE_DLC_U8                   ((uint32)0xFFF0FFFFU)

/*Offset bits for CBT register*/
#define FLEXCAN_CBT_OFFSET_U8                   ((uint8)31U)
#define FLEXCAN_FD_PRESDIV_CBT_OFFSET_U8        ((uint8)21U)
#define FLEXCAN_CBT_PROPSEG_OFFSET_U8           ((uint8)10U)
#define FLEXCAN_CBT_PSEG1_OFFSET_U8             ((uint8) 5U) 
#define FLEXCAN_CBT_PSEG2_OFFSET_U8             ((uint8) 0U) 
#define FLEXCAN_CBT_SJW_OFFSET_U8               ((uint8)16U)

/**
* @brief BTF bit31: Enable values from CBT register to replace values from CTRL register
*/
#define FLEXCAN_CBT_BTF_U32                     ((uint32)0x80000000U)

/**
* @brief FDEN bit11: Enable FD
*/
#define FLEXCAN_MCR_FDEN_U32                    ((uint32)0x00000800U)

/**
* @brief EDL + BRS bit30 and BIT 31: Enable FD and BRS in MB
*/
#define FLEXCAN_MB_EDL_BRS_U32                  ((uint32)0xC0000000U)


/**
* @brief ESR bit17: Tx error warning interrupt flag (set when TXWRN becomes set while WRNEN is set)
*/
#define FLEXCAN_FD_MB_MESSAGE_U32               ((uint32)0xC0000000U)
/*==================================================================================================
                BIT MASKS FOR ERROR AND STATUS REGISTER: ESR (Base+0x0020)
==================================================================================================*/
/**
* @brief ESR bit17: Tx error warning interrupt flag (set when TXWRN becomes set while WRNEN is set)
*/
#define FLEXCAN_ESR_TWRNINT_U32                 ((uint32)0x00020000U)
/**
* @brief ESR bit16: Rx error warning interrupt flag (set when RXWRN becomes set while WRNEN is set)
*/
#define FLEXCAN_ESR_RWRNINT_U32                 ((uint32)0x00010000U)
/**
* @brief ESR bit15: Recessive bit error (when set it indicates that at least one bit wans transmitted as recessive, but received as dominant)
*/
#define FLEXCAN_ESR_BIT1ERR_U32                 ((uint32)0x00008000U)
/**
* @brief ESR bit14: Dominant bit error (when set it indicates that at least one bit wans transmitted as dominant, but received as recessive)
*/
#define FLEXCAN_ESR_BIT0ERR_U32                 ((uint32)0x00004000U)
/**
* @brief ESR bit13: Acknowledge error (dominant acknowledge has been detected)
*/
#define FLEXCAN_ESR_ACKERR_U32                  ((uint32)0x00002000U)
/**
* @brief ESR bit12: CRC error detected
*/
#define FLEXCAN_ESR_CRCERR_U32                  ((uint32)0x00001000U)
/**
* @brief ESR bit11: Form error detected
*/
#define FLEXCAN_ESR_FRMERR_U32                  ((uint32)0x00000800U)
/**
* @brief ESR bit10: Stuffing error detected
*/
#define FLEXCAN_ESR_STFERR_U32                  ((uint32)0x00000400U)
/**
* @brief ESR bit9: Tx error warning flag (set when Tx error counter >=96)
*/
#define FLEXCAN_ESR_TXWRN_U32                   ((uint32)0x00000200U)
/**
* @brief ESR bit8: Rx error warning flag (set when Rx error counter >=96)
*/
#define FLEXCAN_ESR_RXWRN_U32                   ((uint32)0x00000100U)
/**
* @brief ESR bit7: Can bus IDLE
*/
#define FLEXCAN_ESR_IDLE_U32                    ((uint32)0x00000080U)
/**
* @brief ESR bit6: Indicates type of activity when IDLE==0 (0=Rx, 1=Tx)
*/
#define FLEXCAN_ESR_TXRX_U32                    ((uint32)0x00000040U)
/**
* @brief ESR bit5-4: Fault state (00=error active, 01=error passive, 1x=bus off)
*/
#define FLEXCAN_ESR_FLTCONF_U32                 ((uint32)0x00000030U)
/**
* @brief ESR bit2: Bus off interrupt flag (set after the module enters bus off state)
*/
#define FLEXCAN_ESR_BOFFINT_U32                 ((uint32)0x00000004U)
/**
* @brief ESR bit1: Error interrupt flag (set when at least one of the error bits (BIT1ERR..STFERR) is set)
*/
#define FLEXCAN_ESR_ERRINT_U32                  ((uint32)0x00000002U)
/**
* @brief ESR bit0: Wake-Up Interrupt (1 = Indicates a recessive to dominant transition received on the CAN bus when the FlexCAN module is in Doze Mode or Stop Mode,
*/
#define FLEXCAN_ESR_WAK_INT_U32                 ((uint32)0x00000001U)

/*==================================================================================================
                BIT MASKS FOR CONTROL 2 REGISTER: CTRL2 (Base+0x0034)
==================================================================================================*/
/**
* @brief CTRL bit27-24: Number Of Rx FIFO Filters
*/
#define FLEXCAN_CTRL2_RFFN_U32                  ((uint32)0x0F000000U)
/**
* @brief CTRL2 bit3: Write-Access To Memory In Freeze Mode
*/
#define FLEXCAN_CTRL2_WRMFRZ_U32                ((uint32)0x10000000U)
/**
* @brief CTRL2 bit2: Error-correction Configuration Register Write Enable
*/
#define FLEXCAN_CTRL2_ECRWRE_U32                ((uint32)0x20000000U)
/**
* @brief CTRL2 bit19-23: Tx Arbitration Start Delay bit field
*/
#define FLEXCAN_CTRL2_TASD_U32                  ((uint32)0x00F80000U)
/**
* @brief CTRL2[STFCNTEN] bit19: support the select ISO or non-ISO for CAN FD
*/
#define FLEXCAN_FD_CTRL2_STFCNTEN_U32           ((uint32)0x00001000U)
/**
* @brief CTRL2[EDFLTDIS] bit11: Edge Filter Disable 
*/
#define FLEXCAN_FD_CTRL2_EDFLTDIS_U32           ((uint32)0x00000800U)
/**
* @brief CTRL2[PREXCEN] bit14: Protocol Exception Enable
*/
#define FLEXCAN_FD_CTRL2_PREXCEN_U32            ((uint32)0x00004000U)
/*==================================================================================================
                BIT MASKS FOR MEMORY ERROR CONTROL REGISTER: MECR (Base+0x0AE0)
==================================================================================================*/
/**
* @brief MECR bit13: FlexCAN Access With Non-Correctable Errors Interrupt Mask
*/
#define FLEXCAN_MECR_FANCEI_U32                 ((uint32)0x00040000U)

/**
* @brief MECR bit12: Host Access With Non-Correctable Errors Interrupt Mask
*/
#define FLEXCAN_MECR_HANCEI_U32                 ((uint32)0x00080000U)

/**
* @brief MECR bit0: Error Configuration Register Write Disable
*/
#define FLEXCAN_MECR_ECRWRDIS_U32               ((uint32)0x80000000U)
/**
* @brief MECR bit24: Non-Correctable Errors In FlexCAN Access Put Device In Freeze Mode
*/
#define FLEXCAN_MECR_ECCDIS_U32                 ((uint32)0x00000100U)

/*==================================================================================================
                BIT MASKS FOR CAN FD CONTROL REGISTER: FDCTRL (Base+0x0C00)
==================================================================================================*/
/**
* @brief FDCTRL bit31: Enable values bit rate switch
*/
#define FLEXCAN_FDCTRL_FDRATE_U32               ((uint32)0x80000000U)
/**
* @brief FDCTRL bit15: Enable Transceiver Delay Compensation
*/
#define FLEXCAN_FDCTRL_TDCEN_U32                ((uint32)0x00008000U)
/**
* @brief FDCTRL bit23-22: Message Buffer Data Size for Region 2
*/
#define FLEXCAN_FDCTRL_MBDSR2_U32               ((uint32)0x00C00000U)
/**
* @brief FDCTRL bit20-19: Message Buffer Data Size for Region 1
*/
#define FLEXCAN_FDCTRL_MBDSR1_U32               ((uint32)0x00180000U)
/**
* @brief FDCTRL bit17-16: Message Buffer Data Size for Region 0
*/
#define FLEXCAN_FDCTRL_MBDSR0_U32               ((uint32)0x00030000U)
/**
* @brief FDCTRL bit12-08: Transceiver Delay Compensation Offset
*/
#define FLEXCAN_FDCTRL_TDCOFF_U32               ((uint32)0x00001F00U)
/**
* @brief FDCTRL bit23-22: Mask Message Buffer Data Size for three Regions
*/
#define FLEXCAN_FDCTRL_MBDSR_MASK_U32           ((uint32)0x00DB0000U)
/*==================================================================================================
                BIT MASKS FOR FIFO INTs
==================================================================================================*/
#if (CAN_RXFIFO_ENABLE == STD_ON)
/**
* @brief Overflow Condition: bit7 of IFRL register
*/
#define FLEXCAN_FIFO_OVERFLOW_INT_MASK_U32      ((uint32)0x00000080U)
/**
* @brief Fifo Warning: bit6 of IFRL register
*/
#define FLEXCAN_FIFO_WARNING_INT_MASK_U32       ((uint32)0x00000040U)
/**
* @brief Fifo Available: bit5 of IFRL register
*/
#define FLEXCAN_FIFO_AVAILABLE_INT_MASK_U32     ((uint32)0x00000020U)

/**
* @brief Buffer MB7 Interrupt or FIFO Overflow
*/
#define FLEXCAN_FIFOOVERFLOW_INT_INDEX_U8       ((uint8)0x07U)
/**
* @brief Buffer MB6 Interrupt or FIFO Warning
*/
#define FLEXCAN_FIFOWARNING_INT_INDEX_U8        ((uint8)0x06U)
/**
* @brief Buffer MB5 Interruptor Frames Available in FIFO
*/
#define FLEXCAN_FIFOFRAME_INT_INDEX_U8          ((uint8)0x05U)

/**
* @brief Message buffers used by FIFO engine
*/
#define FLEXCAN_FIFO_MB_COUNT_U8                ((uint8)0x08U)
/**
* @brief Used to write table ID
*/
#define FLEXCAN_TABLEID_ADDR_OFFSET_U32         ((uint32)0x000000E0U)

/**
* @brief Specify the depth of FIFO structure
*/
#define FLEXCAN_FIFO_DEPTH_U8                   ((uint8)6U)

/**
* @brief Specify the times (in the depth of FIFO) for searching available Rx MBs in FIFO
*/
#define FLEXCAN_FIFO_DEPTH_UNIT_U8              ((uint8)2U)

/**
* @brief CTRL bit0: Buffer MB0 Interrupt Or Clear FIFO bit
*/
#define FLEXCAN_IFLAG1_BUF0I_U32                ((uint32)0x00000001U)

#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */

/*==================================================================================================
                              FLEXCAN Register address calculation Macros
==================================================================================================*/

/**
* @brief Macro for Returning Base address of the controller.
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define CAN_GET_BASE_ADDRESS(offset) ( (uint32)( Can_u32BaseAddress[(offset)] ) )


/**
* @brief Macro for Module Configuration (MCR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_MCR(offset)         ( (uint32)( CAN_GET_BASE_ADDRESS(offset) ) )



/**
* @brief Macro for Control Register (CTRL) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CTRL(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x04U ) )



/**
* @brief Macro for Free Running Timer (TIMER) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_TIMER(offset)       ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x08U ) )


/**
* @brief Macro for Rx Global Mask (RXGMASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_RXGMASK(offset)     ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x10U ) )



/**
* @brief Macro for Rx Buffer 14 Mask (RX14MASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_RX14MASK(offset)    ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x14U ) )



/**
* @brief Macro for Rx Buffer 15 Mask (RX15MASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_RX15MASK(offset)    ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x18U ) )



/**
* @brief Macro for Error Counter Register (ECR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_ECR(offset)         ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x1CU ) )



/**
* @brief Macro for Error and Status Register (ESR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_ESR(offset)         ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x20U ) )




/**
* @brief Macro for Interrupt Masks 1 (IMASK1) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_IMASK1(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x28U ) )
/**
* @brief Macro for Interrupt Flags 1 (IFLAG1) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_IFLAG1(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x30U ) )

#if ((CAN_MAXMB_SUPPORTED == FLEXCAN_MB_64_U8) || (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_96_U8 )) 
/**
* @brief Macro for Interrupt Masks 2 (IMASK2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_IMASK2(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x24U ) )

/**
* @brief Macro for Interrupt Flags 2 (IFLAG2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_IFLAG2(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x2CU ) )
#endif

 #if  (CAN_MAXMB_SUPPORTED == FLEXCAN_MB_96_U8 )
/**
* @brief Macro for Interrupt Masks 2 (IMASK2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_IMASK3(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x6CU ) )

/**
* @brief Macro for Interrupt Flags 3 (IFLAG3) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_IFLAG3(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x74U ) )
#endif

/**
* @brief Macro for Control Register 2 (CTRL2) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CTRL2(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x34U ) )


/**
* @brief Macro for Rx Fifo Global Mask (RXFGMASK) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_RXFGMASK(offset)     ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x48U ) )


/**
* @brief Macro for RxFifo structure ID Table 0-7 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_RXFIFO_ID(offset, id)  ( (uint32)( CAN_GET_BASE_ADDRESS(offset) +  \
                                                   (uint32)FLEXCAN_TABLEID_ADDR_OFFSET_U32 + (uint32)((id) *0x04U) ))



/**
* @brief Macro for Message Buffers MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_MB(offset, mb) ((uint32)( CAN_GET_BASE_ADDRESS(offset) + (uint32)(FLEXCAN_MB_OFFSET(mb) ) ))

/**
* @brief Macro for Message Buffers ID of MB0_MB63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_MB_ID(offset, mb)       ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                   ((uint32)(FLEXCAN_MB_OFFSET(mb) ) + (uint32)(0x04U)) ))

/**
* @brief Macro for Rx Individual Mask Registers RXIMR0_RXIMR63 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_RXIMR(offset, mb)           ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                        (uint32)(FLEXCAN_RXIMR_OFFSET_U32) + \
                                                        (uint32)((mb) * 0x04U) ))

/**
* @brief Macro for Message Buffers DATA0 - DATA7 of MB0_MB63 register access
*/


#if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
/* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define FLEXCAN_MB_DATA(offset, mb, databyte)   ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                           (uint32)((FLEXCAN_MB_OFFSET(mb)) + (uint32)0x08U + ((((uint32)(databyte) & 0xFCU) + 3U)-((uint32)(databyte) & 3U)))))
                                                            
#elif (CPU_BYTE_ORDER==HIGH_BYTE_FIRST)    
/* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/                                                   
#define FLEXCAN_MB_DATA(offset, mb, databyte)    ((uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                           (uint32)((FLEXCAN_MB_OFFSET(mb) ) + (uint32)0x08U + (uint32)(databyte)) ))

#endif

/**
* @brief Macro for Memory Error Control Register (MECR) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_MECR(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0xAE0U ) )

/**
* @brief Macro for ERRSR register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_ERRSR(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0AFCU ) )

/**
* @brief Macro for CAN_CTRL1_PN register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_CTRL1_PN(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B00U ) )

/**
* @brief Macro for CAN_CTRL2_PN register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_CTRL2_PN(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B04U ) )

/**
* @brief Macro for CAN_WU_MTC register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_WU_MTC(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B08U ) )

/**
* @brief Macro for CAN_FLT_ID1 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_FLT_ID1(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B0CU ) )

/**
* @brief Macro for CAN_FLT_DLC register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_FLT_DLC(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B10U ) )

/**
* @brief Macro for CAN_PL1_LO register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_PL1_LO(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B14U ) )

/**
* @brief Macro for CAN_PL1_HI register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_PL1_HI(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B18U ) )

/**
* @brief Macro for CAN_FLT_ID2_IDMASK register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_FLT_ID2_IDMASK(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B1CU ) )

/**
* @brief Macro for CAN_PL2_PLMASK_LO register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_PL2_PLMASK_LO(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B20U ) )

/**
* @brief Macro for CAN_PL2_PLMASK_HI register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_PL2_PLMASK_HI(offset)      ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x0B24U ) )

/**
* @brief Macro for CAN_WMBn_CS register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_WMB_CS(offset, mb)           ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                        (uint32)(FLEXCAN_CAN_WMB_CS_U32) + \
                                                        (uint32)((mb) * 0x10U) ))
                                                        
/**
* @brief Macro for CAN_WMBn_ID register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_WMB_ID(offset, mb)           ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                        (uint32)(FLEXCAN_CAN_WMB_ID_U32) + \
                                                        (uint32)((mb) * 0x10U) ))

/**
* @brief Macro for CAN_WMB_D03 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_WMB_D03(offset, mb)           ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                        (uint32)(FLEXCAN_CAN_WMB_D03_U32) + \
                                                        (uint32)((mb) * 0x10U) ))
                                                        
/**
* @brief Macro for CAN_WMB_D47 register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_CAN_WMB_D47(offset, mb)           ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + \
                                                        (uint32)(FLEXCAN_CAN_WMB_D47_U32) + \
                                                        (uint32)((mb) * 0x10U) ))
/**
* @brief Macro for Control FD Register (FDCTRL) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_FDCTRL(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0xC00U ) )


/**
* @brief Macro for FD Bit Timing register (FDCBT) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/

#define FLEXCAN_FDCBT(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0xC04U ) ) 

/**
* @brief Macro for Bit Timing register (CBT) register access
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define FLEXCAN_CBT(offset)        ( (uint32)( CAN_GET_BASE_ADDRESS(offset) + 0x50U ) )
/*==================================================================================================
                            FLEXCAN Register Configuration Macros
==================================================================================================*/

/*==================================================================================================
                            FLEXCAN Register Read Macros
==================================================================================================*/



/*==================================================================================================
                              FLEXCAN Register Bit Configuration Macros
==================================================================================================*/



/**@}*/

/**
* @{
* @brief MECR Register: BASE + 0x0AE0 bits set
* @violates @ref Reg_eSys_FlexCan_h_REF_1 Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/



/*Calculate the number of CAN controllers available on the platform */
#ifdef  FLEXCAN0_BASEADDR
        #define FLEXCAN0_AVAILABLE    1U
#else    
        #define FLEXCAN0_AVAILABLE    0U    
#endif /* FLEXCAN0_BASEADDR */

#ifdef  FLEXCAN1_BASEADDR
        #define FLEXCAN1_AVAILABLE    1U
#else    
        #define FLEXCAN1_AVAILABLE    0U    
#endif /* FLEXCAN1_BASEADDR */

#ifdef  FLEXCAN2_BASEADDR
        #define FLEXCAN2_AVAILABLE    1U
#else    
        #define FLEXCAN2_AVAILABLE    0U    
#endif /* FLEXCAN2_BASEADDR */

#ifdef  FLEXCAN3_BASEADDR
        #define FLEXCAN3_AVAILABLE    1U
#else    
        #define FLEXCAN3_AVAILABLE    0U    
#endif /* FLEXCAN3_BASEADDR */

#ifdef  FLEXCAN4_BASEADDR
        #define FLEXCAN4_AVAILABLE    1U
#else    
        #define FLEXCAN4_AVAILABLE    0U    
#endif /* FLEXCAN4_BASEADDR */

#ifdef  FLEXCAN5_BASEADDR
        #define FLEXCAN5_AVAILABLE    1U
#else    
        #define FLEXCAN5_AVAILABLE    0U    
#endif /* FLEXCAN5_BASEADDR */

#ifdef  FLEXCAN6_BASEADDR
        #define FLEXCAN6_AVAILABLE    1U
#else    
        #define FLEXCAN6_AVAILABLE    0U    
#endif /* FLEXCAN6_BASEADDR */

#ifdef  FLEXCAN7_BASEADDR
        #define FLEXCAN7_AVAILABLE    1U
#else    
        #define FLEXCAN7_AVAILABLE    0U    
#endif /* FLEXCAN7_BASEADDR */
/*Calculate the controllers number available on this platform*/
#define FLEXCAN_CONTROLLERS_NO    (FLEXCAN0_AVAILABLE+FLEXCAN1_AVAILABLE+FLEXCAN2_AVAILABLE+FLEXCAN3_AVAILABLE+FLEXCAN4_AVAILABLE+FLEXCAN5_AVAILABLE+FLEXCAN6_AVAILABLE+FLEXCAN7_AVAILABLE)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#define CAN_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h */

#include "Can_MemMap.h"

extern CONST(uint32, CAN_CONST) Can_u32BaseAddress[FLEXCAN_CONTROLLERS_NO];

#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/


#include "Can_MemMap.h"

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"


#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CODE
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#define CAN_STOP_SEC_CODE
/*
* @violates @ref Reg_eSys_FlexCan_h_REF_2 Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*/
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
