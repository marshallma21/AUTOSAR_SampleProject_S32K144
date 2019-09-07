/**
*   @file    Reg_eSys_LPI2C.h
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - LPI2C Registers and Macros Definitions.
*   @details Header file for LPI2C Registers and Macros Definitions.
*
*   @addtogroup I2C
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPI2C
*   Dependencies         : none
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

#ifndef REG_ESYS_LPI2C_H
#define REG_ESYS_LPI2C_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Reg_eSys_LPI2C_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, This violation is due to function
* like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_LPI2C_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_LPI2C.h
*/
#define REG_ESYS_LPI2C_VENDOR_ID                    43
#define REG_ESYS_LPI2C_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_LPI2C_AR_RELEASE_MINOR_VERSION     2
/**
* @violates @ref Reg_eSys_LPI2C_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define REG_ESYS_LPI2C_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_LPI2C_SW_MAJOR_VERSION             1
#define REG_ESYS_LPI2C_SW_MINOR_VERSION             0
#define REG_ESYS_LPI2C_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_LPI2C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_LPI2C_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_LPI2C.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*********************************MASTER REGISTERS*********************************/

/**
* @details  LPI2C macro to access register LPI2C Master Control Register (MCR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000010U))

/**
* @details  LPI2C macro to access register LPI2C Master Status Register (MSR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MSR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000014U))

/**
* @details  LPI2C macro to access register LPI2C Master Interrupt Enable Register (MIER).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MIER_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000018U))

/**
* @details  LPI2C macro to access register LPI2C Master DMA Enable Register (MDER).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MDER_ADDR32(offset)      ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x0000001CU))

/**
* @details  LPI2C macro to access register LPI2C Master Configuration Register 0 (MCFGR0).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCFGR0_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000020U))

/**
* @details  LPI2C macro to access register LPI2C Master Configuration Register 1 (MCFGR1).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCFGR1_ADDR32(offset)      ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000024U))

/**
* @details  LPI2C macro to access register LPI2C Master Configuration Register 2 (MCFGR2).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCFGR2_ADDR32(offset)      ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000028U))

/**
* @details  LPI2C macro to access register LPI2C Master Configuration Register 3 (MCFGR2).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCFGR3_ADDR32(offset)      ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x0000002CU))

/**
* @details  LPI2C macro to access register LPI2C Master Data Match Register (MDMR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MDMR_ADDR32(offset)        ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000040U))

/**
* @details  LPI2C macro to access register LPI2C Master Clock Configuration Register 0 (MCCR0).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCCR0_ADDR32(offset)      ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000048U))

/**
* @details  LPI2C macro to access register LPI2C Master Clock Configuration Register 1 (MCCR1).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MCCR1_ADDR32(offset)      ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000050U))

/**
* @details  LPI2C macro to access register LPI2C Master FIFO Control Register (MFCR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MFCR_ADDR32(offset)       ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000058U))

/**
* @details  LPI2C macro to access register LPI2C Master FIFO Status Register (MFCR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MFSR_ADDR32(offset)       ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x0000005CU))

/**
* @details  LPI2C macro to access register LPI2C Master Transmit Data Register (MTDR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MTDR_ADDR32(offset)       ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000060U))

/**
* @details  LPI2C macro to access register LPI2C Master Receive Data Register (MRDR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_MRDR_ADDR32(offset)       ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000070U))

/*********************************SLAVE REGISTERS*********************************/
/**
* @details  LPI2C macro to access register LPI2C Slave Control Register (SCR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SCR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000110U))

/**
* @details  LPI2C macro to access register LPI2C Slave Status Register (SSR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SSR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000114U))

/**
* @details  LPI2C macro to access register LPI2C Slave Interrupt Enable Register (SIER).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SIER_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000118U))

/**
* @details  LPI2C macro to access register LPI2C Slave DMA Enable Register (SDER).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SDER_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x0000011CU))

/**
* @details  LPI2C macro to access register LPI2C Slave Configuration Register 1 (SCFGR1).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SCFGR1_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000124U))

/**
* @details  LPI2C macro to access register LPI2C Slave Configuration Register 2 (SCFGR2).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SCFGR2_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000128U))

/**
* @details  LPI2C macro to access register LPI2C Slave Address Match Register (SAMR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SAMR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000140U))

/**
* @details  LPI2C macro to access register LPI2C Slave Address Status Register (SASR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SASR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000150U))

/**
* @details  LPI2C macro to access register LPI2C Slave Transmit ACK Register (STAR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_STAR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000154U))

/**
* @details  LPI2C macro to access register LPI2C Slave Transmit Data Register (STDR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_STDR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000160U))

/**
* @details  LPI2C macro to access register LPI2C Slave Receive Data Register (SRDR).
* @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPI2C_SRDR_ADDR32(offset)    ((uint32)(LPI2C_au32BaseAddrs[(offset)] + (uint32)0x00000170U))


/*****************************************MASTER BITFIELDS*****************************************/

/**
* @brief    LPI2C Registers bits.
* @details  MCR register bit masks.
*/
#define LPI2C_MCR_RRF_MASK_U32                  ((uint32)0x00000200U)
#define LPI2C_MCR_RTF_MASK_U32                  ((uint32)0x00000100U)
#define LPI2C_MCR_DBGEN_MASK_U32                ((uint32)0x00000008U)
#define LPI2C_MCR_DOZEN_MASK_U32                ((uint32)0x00000004U)
#define LPI2C_MCR_RST_MASK_U32                  ((uint32)0x00000002U)
#define LPI2C_MCR_MEN_MASK_U32                  ((uint32)0x00000001U)

#define LPI2C_MCR_RESET_RECEIVE_FIFO_U32        (LPI2C_MCR_RRF_MASK_U32)
#define LPI2C_MCR_RESET_TRANSMIT_FIFO_U32       (LPI2C_MCR_RTF_MASK_U32)

#define LPI2C_MCR_MASTER_ENABLED_IN_DBG_U32     (LPI2C_MCR_DBGEN_MASK_U32)
#define LPI2C_MCR_MASTER_DISABLED_IN_DBG_U32    ((uint32)0x00000000U)

#define LPI2C_MCR_MASTER_ENABLED_IN_DOZE_U32    (LPI2C_MCR_DOZEN_MASK_U32)
#define LPI2C_MCR_MASTER_DISABLED_IN_DOZE_U32   ((uint32)0x00000000U)

#define LPI2C_MCR_MASTER_ENABLE_U32             (LPI2C_MCR_MEN_MASK_U32)
#define LPI2C_MCR_MASTER_DISABLE_U32            ((uint32)0x00000000U)

/**
* @brief    LPI2C Registers bits.
* @details  MSR register bit masks.
*/
#define LPI2C_MSR_RWBITS_MASK_U32          ((uint32)0x00007F00U)

#define LPI2C_MSR_BBF_MASK_U32             ((uint32)0x02000000U)
#define LPI2C_MSR_MBF_MASK_U32             ((uint32)0x01000000U)
#define LPI2C_MSR_DMF_MASK_U32             ((uint32)0x00004000U)
#define LPI2C_MSR_PLTF_MASK_U32            ((uint32)0x00002000U)
#define LPI2C_MSR_FEF_MASK_U32             ((uint32)0x00001000U)
#define LPI2C_MSR_ALF_MASK_U32             ((uint32)0x00000800U)
#define LPI2C_MSR_NDF_MASK_U32             ((uint32)0x00000400U)
#define LPI2C_MSR_SDF_MASK_U32             ((uint32)0x00000200U)
#define LPI2C_MSR_EPF_MASK_U32             ((uint32)0x00000100U)
#define LPI2C_MSR_RDF_MASK_U32             ((uint32)0x00000002U)
#define LPI2C_MSR_TDF_MASK_U32             ((uint32)0x00000001U)

#define LPI2C_MSR_ERROR_FLAGS_MASK_U32     ((uint32)0x00007C00U)

#define LPI2C_BUS_IS_BUSY_U32              (LPI2C_MSR_BBF_MASK_U32)
#define LPI2C_BUS_IS_IDLE_U32              ((uint32)0x00000000U)
                                           
#define LPI2C_MASTER_IS_BUSY_U32           (LPI2C_MSR_MBF_MASK_U32)
#define LPI2C_MASTER_IS_IDLE_U32           ((uint32)0x00000000U)
                                           
#define LPI2C_RECEIVED_MATCHING_DATA_U32   (LPI2C_MSR_DMF_MASK_U32)
                                           
#define LPI2C_PIN_LOW_TIMEOUT_U32          (LPI2C_MSR_PLTF_MASK_U32)
                                           
#define LPI2C_FIFO_ERROR_U32               (LPI2C_MSR_FEF_MASK_U32)
                                           
#define LPI2C_ARBITRATION_LOST_U32         (LPI2C_MSR_ALF_MASK_U32)
                                           
#define LPI2C_UNEXPECTED_NACK_U32          (LPI2C_MSR_NDF_MASK_U32)
                                           
#define LPI2C_STOP_DETECTED_U32            (LPI2C_MSR_SDF_MASK_U32)
                                           
#define LPI2C_END_OF_PACKET_U32            (LPI2C_MSR_EPF_MASK_U32)
                                           
#define LPI2C_RECEIVE_DATA_IS_READY_U32    (LPI2C_MSR_RDF_MASK_U32)
                                           
#define LPI2C_TRANSMIT_DATA_IS_READY_U32   (LPI2C_MSR_TDF_MASK_U32)

/**
* @brief    LPI2C Registers bits.
* @details  MIER register bit masks.
*/
#define LPI2C_MIER_RWBITS_MASK_U32              ((uint32)0x00007F03U)

#define LPI2C_MIER_DMIE_MASK_U32                  ((uint32)0x00004000U)
#define LPI2C_MIER_PLTIE_MASK_U32                 ((uint32)0x00002000U)
#define LPI2C_MIER_FEIE_MASK_U32                  ((uint32)0x00001000U)
#define LPI2C_MIER_ALIE_MASK_U32                  ((uint32)0x00000800U)
#define LPI2C_MIER_NDIE_MASK_U32                  ((uint32)0x00000400U)
#define LPI2C_MIER_SDIE_MASK_U32                  ((uint32)0x00000200U)
#define LPI2C_MIER_EPIE_MASK_U32                  ((uint32)0x00000100U)
#define LPI2C_MIER_RDIE_MASK_U32                  ((uint32)0x00000002U)
#define LPI2C_MIER_TDIE_MASK_U32                  ((uint32)0x00000001U)
                                                  
#define LPI2C_DATA_MATCH_ISR_ENABLE_U32           (LPI2C_MIER_DMIE_MASK_U32)
#define LPI2C_DATA_MATCH_ISR_DISABLE_U32          ((uint32)0x00000000U)
                                                  
#define LPI2C_PIN_LOW_TIMEOUT_ISR_ENABLE_U32      (LPI2C_MIER_PLTIE_MASK_U32)
#define LPI2C_PIN_LOW_TIMEOUT_ISR_DISABLE_U32     ((uint32)0x00000000U)
                                                  
#define LPI2C_FIFO_ERROR_ISR_ENABLE_U32           (LPI2C_MIER_FEIE_MASK_U32)
#define LPI2C_FIFO_ERROR_ISR_DISABLE_U32          ((uint32)0x00000000U)
                                                  
#define LPI2C_ARBITRATION_LOST_ISR_ENABLE_U32     (LPI2C_MIER_ALIE_MASK_U32)
#define LPI2C_ARBITRATION_LOST_ISR_DISABLE_U32    ((uint32)0x00000000U)
                                                  
#define LPI2C_UNEXPECTED_NACK_ISR_ENABLE_U32      (LPI2C_MIER_NDIE_MASK_U32)
#define LPI2C_UNEXPECTED_NACK_ISR_DISABLE_U32     ((uint32)0x00000000U)
                                                  
#define LPI2C_STOP_DETECT_ISR_ENABLE_U32          (LPI2C_MIER_SDIE_MASK_U32)
#define LPI2C_STOP_DETECT_ISR_DISABLE_U32         ((uint32)0x00000000U)

#define LPI2C_END_PACKET_ISR_ENABLE_U32           (LPI2C_MIER_EPIE_MASK_U32)
#define LPI2C_END_PACKET_ISR_DISABLE_U32          ((uint32)0x00000000U)

#define LPI2C_RECEIVE_DATA_ISR_ENABLE_U32         (LPI2C_MIER_RDIE_MASK_U32)
#define LPI2C_RECEIVE_DATA_ISR_DISABLE_U32        ((uint32)0x00000000U)

#define LPI2C_TRANSMIT_DATA_ISR_ENABLE_U32        (LPI2C_MIER_TDIE_MASK_U32)
#define LPI2C_TRANSMIT_DATA_ISR_DISABLE_U32       ((uint32)0x00000000U)

/**
* @brief    LPI2C Registers bits.
* @details  MDER register bit masks.
*/
#define LPI2C_MDER_RDDE_MASK_U32                  ((uint32)0x00000002U)
#define LPI2C_MDER_TDDE_MASK_U32                  ((uint32)0x00000001U)
                                                  
#define LPI2C_MDER_RX_DMA_ENABLE_U32              (LPI2C_MDER_RDDE_MASK_U32)
#define LPI2C_MDER_RX_DMA_DISABLE_U32             ((uint32)0x00000000U)
                                                  
#define LPI2C_MDER_TX_DMA_ENABLE_U32              (LPI2C_MDER_TDDE_MASK_U32)
#define LPI2C_MDER_TX_DMA_DISABLE_U32             ((uint32)0x00000000U)
/**                                               
* @brief    LPI2C Registers bits.                 
* @details  MCFGR0 register bit masks.            
*/                                                
#define LPI2C_MCFGR0_RDMO_MASK_U32                ((uint32)0x00000200U)
#define LPI2C_MCFGR0_CIRFIFO_MASK_U32             ((uint32)0x00000100U)
#define LPI2C_MCFGR0_HRSEL_MASK_U32               ((uint32)0x00000004U)
#define LPI2C_MCFGR0_HRPOL_MASK_U32               ((uint32)0x00000002U)
#define LPI2C_MCFGR0_HREN_MASK_U32                ((uint32)0x00000001U)

/**
* @brief    LPI2C Registers bits.
* @details  MCFGR1 register bit masks.
*/
#define LPI2C_MCFGR1_PINCFG_MASK_U32              ((uint32)0x07000000U)
#define LPI2C_MCFGR1_MATCFG_MASK_U32              ((uint32)0x00070000U)
#define LPI2C_MCFGR1_TIMECFG_MASK_U32             ((uint32)0x00000400U)
#define LPI2C_MCFGR1_IGNACK_MASK_U32              ((uint32)0x00000200U)
#define LPI2C_MCFGR1_AUTOSTOP_MASK_U32            ((uint32)0x00000100U)
#define LPI2C_MCFGR1_PRESCALE_MASK_U32            ((uint32)0x00000007U)

#define LPI2C_2PIN_OPEN_DRAIN_U32                 ((uint32)0x00000000U)
#define LPI2C_2PIN_OUTPUT_ONLY_U32                ((uint32)0x01000000U)
#define LPI2C_2PIN_PUSH_PULL_U32                  ((uint32)0x02000000U)
#define LPI2C_4PIN_PUSH_PULL_U32                  ((uint32)0x03000000U)
#define LPI2C_2PIN_OPEN_DRAIN_SEPARATE_SLAVE_U32  ((uint32)0x04000000U)
#define LPI2C_2PIN_OUTPUT_ONLY_SEPARATE_SLAVE_U32 ((uint32)0x05000000U)
#define LPI2C_2PIN_PUSH_PULL_SEPARATE_SLAVE_U32   ((uint32)0x06000000U)
#define LPI2C_4PIN_PUSH_PULL_INVERTED_OUTPUT_U32  ((uint32)0x07000000U)

#define LPI2C_PIN_LOW_TIMEOUT_SCL_U32             ((uint32)0x00000000U)
#define LPI2C_PIN_LOW_TIMEOUT_SCL_OR_SDA_U32      (LPI2C_MCFGR1_TIMECFG_MASK_U32)

#define LPI2C_NORMAL_ACK_AND_NACK_U32             ((uint32)0x00000000U)
#define LPI2C_TREAT_NACK_AS_ACK_U32               (LPI2C_MCFGR1_IGNACK_MASK_U32)

#define LPI2C_AUTOMATIC_STOP_ENABLE_U32           (LPI2C_MCFGR1_AUTOSTOP_MASK_U32)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_PRESCALE_U32(value)                 ((uint32)((value) & LPI2C_MCFGR1_PRESCALE_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  MCFGR2 register bit masks.
*/
#define LPI2C_MCFGR2_FILTSDA_MASK_U32     ((uint32)0x0F000000U)
#define LPI2C_MCFGR2_FILTSDA_SHIFT_U32    ((uint32)24U)
#define LPI2C_MCFGR2_FILTSCL_MASK_U32     ((uint32)0x000F0000U)
#define LPI2C_MCFGR2_FILTSCL_SHIFT_U32    ((uint32)16U)
#define LPI2C_MCFGR2_BUSIDLE_MASK_U32     ((uint32)0x000000FFU)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_FILTSDA_U32(value)         ((uint32)((uint32)((value) << LPI2C_MCFGR2_FILTSDA_SHIFT_U32) & LPI2C_MCFGR2_FILTSDA_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_FILTSCL_U32(value)         ((uint32)((uint32)((value) << LPI2C_MCFGR2_FILTSCL_SHIFT_U32) & LPI2C_MCFGR2_FILTSCL_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_BUSIDLE_U32(value)         (((value) & LPI2C_MCFGR2_BUSIDLE_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  MCFGR3 register bit masks.
*/
#define LPI2C_MCFGR3_PINLOW_MASK_U32     ((uint32)0x000FFF00U)
#define LPI2C_MCFGR3_PINLOW_SHIFT_U32    ((uint32)8U)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_PINLOW_U32(value)          ((uint32)((uint32)((value) << LPI2C_MCFGR3_PINLOW_SHIFT_U32) & LPI2C_MCFGR3_PINLOW_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  MDMR register bit masks.
*/
#define LPI2C_MDMR_MATCH1_MASK_U32      ((uint32)0x00FF0000U)
#define LPI2C_MDMR_MATCH1_SHIFT_U32     ((uint32)16U)
#define LPI2C_MDMR_MATCH0_MASK_U32      ((uint32)0x000000FFU)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_MATCH1_U32(value)         ((uint32)((uint32)((value) << LPI2C_MDMR_MATCH1_SHIFT_U32) & LPI2C_MDMR_MATCH1_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_MATCH0_U32(value)         (((value) & LPI2C_MDMR_MATCH0_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  MCCR0 register bit masks.
*/
#define LPI2C_MCCR0_DATAVD_MASK_U32     ((uint32)0x3F000000U)
#define LPI2C_MCCR0_DATAVD_SHIFT_U32    ((uint32)24U)
#define LPI2C_MCCR0_SETHOLD_MASK_U32    ((uint32)0x003F0000U)
#define LPI2C_MCCR0_SETHOLD_SHIFT_U32   ((uint32)16U)
#define LPI2C_MCCR0_CLKHI_MASK_U32      ((uint32)0x00003F00U)
#define LPI2C_MCCR0_CLKHI_SHIFT_U32     ((uint32)8U)
#define LPI2C_MCCR0_CLKLO_MASK_U32      ((uint32)0x0000003FU)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_DATAVD_U32(value)         ((uint32)((uint32)((value) << LPI2C_MCCR0_DATAVD_SHIFT_U32) & LPI2C_MCCR0_DATAVD_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_SETHOLD_U32(value)        ((uint32)((uint32)((value) << LPI2C_MCCR0_SETHOLD_SHIFT_U32) & LPI2C_MCCR0_SETHOLD_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_CLKHI_U32(value)          ((uint32)((uint32)((value) << LPI2C_MCCR0_CLKHI_SHIFT_U32) & LPI2C_MCCR0_CLKHI_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_CLKLO_U32(value)          (((value) & LPI2C_MCCR0_CLKLO_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  MFCR register bit masks.
*/
#define LPI2C_MFCR_RXWATER_MASK_U32     ((uint32)0x00030000U)
#define LPI2C_MFCR_RXWATER_SHIFT_U32    ((uint32)16U)
#define LPI2C_MFCR_TXWATER_MASK_U32     ((uint32)0x00000003U)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_RXWATER_U32(value)        ((uint32)((uint32)((value) << LPI2C_MFCR_RXWATER_SHIFT_U32) & LPI2C_MFCR_RXWATER_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_TXWATER_U32(value)        (((value) & LPI2C_MFCR_TXWATER_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  MFSR register bit masks.
*/
#define LPI2C_MFSR_RXCOUNT_MASK_U32     ((uint32)0x00070000U)
#define LPI2C_MFSR_TXCOUNT_MASK_U32     ((uint32)0x00000007U)

/**
* @brief    LPI2C Registers bits.
* @details  MTDR register bit masks.
*/
#define LPI2C_MTDR_CMD_MASK_U32                      ((uint32)0x00000700U)
#define LPI2C_MTDR_DATA_MASK_U32                     ((uint32)0x000000FFU)

#define LPI2C_TRANSMIT_U32                           ((uint32)0x00000000U)
#define LPI2C_RECEIVE_U32                            ((uint32)0x00000100U)
#define LPI2C_GENERATE_STOP_U32                      ((uint32)0x00000200U)
#define LPI2C_RECEIVE_AND_DISCARD_U32                ((uint32)0x00000300U)
#define LPI2C_REPEAT_START_TRANSMIT_U32              ((uint32)0x00000400U)
#define LPI2C_REPEAT_START_TRANSMIT_NACK_U32         ((uint32)0x00000500U)
#define LPI2C_REPEAT_START_TRANSMIT_HS_U32           ((uint32)0x00000600U)
#define LPI2C_REPEAT_START_AND_TRANSMIT_HS_NACK_U32  ((uint32)0x00000700U)

#define LPI2C_MTDR_READ_BIT_MASK_U8                    ((uint8)0x01U)
/**
* @brief    LPI2C Registers bits.
* @details  MRDR register bit masks.
*/
#define LPI2C_MRDR_RXEMPTY_MASK_U32             ((uint32)0x00004000U)
#define LPI2C_MRDR_DATA_MASK_U32                ((uint32)0x000000FFU)
  
#define LPI2C_RECEIVE_FIFO_NOT_EMPTY_U32        ((uint32)0x00000000U)
#define LPI2C_RECEIVE_FIFO_EMPTY_U32            (LPI2C_MRDR_RXEMPTY_MASK_U32)

/*********************************SLAVE BITFIELDS*********************************/

/**
* @brief    LPI2C Registers bits.
* @details  SCR register bit masks.
*/
#define LPI2C_SCR_RRF_MASK_U32                 ((uint32)0x00000200U)
#define LPI2C_SCR_RTF_MASK_U32                 ((uint32)0x00000100U)
#define LPI2C_SCR_FILTDZ_MASK_U32              ((uint32)0x00000020U)
#define LPI2C_SCR_FILTEN_MASK_U32              ((uint32)0x00000010U)
#define LPI2C_SCR_RST_MASK_U32                 ((uint32)0x00000002U)
#define LPI2C_SCR_SEN_MASK_U32                 ((uint32)0x00000001U)

#define LPI2C_SCR_RESET_RECEIVE_FIFO_U32       (LPI2C_SCR_RRF_MASK_U32)
#define LPI2C_SCR_RESET_TRANSMIT_FIFO_U32      (LPI2C_SCR_RTF_MASK_U32)

#define LPI2C_SCR_FILTER_ENABLED_IN_DOZE_U32   ((uint32)0x00000000U)
#define LPI2C_SCR_FILTER_DISABLED_IN_DOZE_U32  (LPI2C_SCR_FILTDZ_MASK_U32)

#define LPI2C_SCR_FILTER_ENABLED_U32           (LPI2C_SCR_FILTEN_MASK_U32)
#define LPI2C_SCR_FILTER_DISABLED_U32          ((uint32)0x00000000U)
   
#define LPI2C_SCR_SLAVE_ENABLE_U32             (LPI2C_SCR_SEN_MASK_U32)
#define LPI2C_SCR_SLAVE_DISABLE_U32            ((uint32)0x00000000U)

/**
* @brief    LPI2C Registers bits.
* @details  SSR register bit masks.
*/
#define LPI2C_SSR_RWBITS_MASK_U32               ((uint32)0x00000F00U)
        
#define LPI2C_SSR_BBF_MASK_U32                  ((uint32)0x02000000U)
#define LPI2C_SSR_SBF_MASK_U32                  ((uint32)0x01000000U)
#define LPI2C_SSR_SARF_MASK_U32                 ((uint32)0x00008000U)
#define LPI2C_SSR_GCF_MASK_U32                  ((uint32)0x00004000U)
#define LPI2C_SSR_AM1F_MASK_U32                 ((uint32)0x00002000U)
#define LPI2C_SSR_AM0F_MASK_U32                 ((uint32)0x00001000U)
#define LPI2C_SSR_FEF_MASK_U32                  ((uint32)0x00000800U)
#define LPI2C_SSR_BEF_MASK_U32                  ((uint32)0x00000400U)
#define LPI2C_SSR_SDF_MASK_U32                  ((uint32)0x00000200U)
#define LPI2C_SSR_RSF_MASK_U32                  ((uint32)0x00000100U)
#define LPI2C_SSR_TAF_MASK_U32                  ((uint32)0x00000008U)
#define LPI2C_SSR_AVF_MASK_U32                  ((uint32)0x00000004U)
#define LPI2C_SSR_RDF_MASK_U32                  ((uint32)0x00000002U)
#define LPI2C_SSR_TDF_MASK_U32                  ((uint32)0x00000001U)

#define LPI2C_SSR_ERROR_FLAGS_MASK_U32          ((uint32)0x00000C00U)

#define LPI2C_SLAVE_BUS_IS_BUSY_U32             (LPI2C_SSR_BBF_MASK_U32)
#define LPI2C_SLAVE_BUS_IS_IDLE_U32             ((uint32)0x00000000U)

#define LPI2C_SLAVE_IS_BUSY_U32                 (LPI2C_SSR_SBF_MASK_U32)
#define LPI2C_SLAVE_IS_IDLE_U32                 ((uint32)0x00000000U)

#define LPI2C_SMBUS_ALERT_RESPONSE_DETECTED_U32 (LPI2C_SSR_SARF_MASK_U32)

#define LPI2C_GENERAL_CALL_ADDRESS_DETECTED_U32 (LPI2C_SSR_GCF_MASK_U32)

#define LPI2C_ADDRESS1_MATCH_U32                (LPI2C_SSR_AM1F_MASK_U32)
        
#define LPI2C_ADDRESS0_MATCH_U32                (LPI2C_SSR_AM0F_MASK_U32)

#define LPI2C_SLAVE_FIFO_ERROR_DETECTED_U32     (LPI2C_SSR_FEF_MASK_U32)

#define LPI2C_SLAVE_BIT_ERROR_DETECTED_U32      (LPI2C_SSR_BEF_MASK_U32)

#define LPI2C_SLAVE_STOP_DETECTED_U32           (LPI2C_SSR_SDF_MASK_U32)

#define LPI2C_SLAVE_REPEATED_START_DETECTED_U32 (LPI2C_SSR_RSF_MASK_U32)
        
#define LPI2C_TRANSMIT_ACK_NOT_REQUIRED_U32     ((uint32)0x00000000U)
#define LPI2C_TRANSMIT_ACK_REQUIRED_U32         (LPI2C_SSR_TAF_MASK_U32)

#define LPI2C_SLAVE_ADDRESS_VALID_U32           (LPI2C_SSR_AVF_MASK_U32)

#define LPI2C_SLAVE_RECEIVE_DATA_IS_READY_U32   (LPI2C_SSR_RDF_MASK_U32)
        
#define LPI2C_SLAVE_TRANSMIT_DATA_IS_READY_U32  (LPI2C_SSR_TDF_MASK_U32)
        
/**
* @brief    LPI2C Registers bits.
* @details  SIER register bit masks.
*/
#define LPI2C_SIER_RWBITS_MASK_U32                  ((uint32)0x0000FF0FU)
                                                    
#define LPI2C_SIER_SARIE_MASK_U32                   ((uint32)0x00008000U)
#define LPI2C_SIER_GCIE_MASK_U32                    ((uint32)0x00004000U)
#define LPI2C_SIER_AM1IE_MASK_U32                   ((uint32)0x00002000U)
#define LPI2C_SIER_AM0IE_MASK_U32                   ((uint32)0x00001000U)
#define LPI2C_SIER_FEIE_MASK_U32                    ((uint32)0x00000800U)
#define LPI2C_SIER_BEIE_MASK_U32                    ((uint32)0x00000400U)
#define LPI2C_SIER_SDIE_MASK_U32                    ((uint32)0x00000200U)
#define LPI2C_SIER_RSIE_MASK_U32                    ((uint32)0x00000100U)
#define LPI2C_SIER_TAIE_MASK_U32                    ((uint32)0x00000008U)
#define LPI2C_SIER_AVIE_MASK_U32                    ((uint32)0x00000004U)
#define LPI2C_SIER_RDIE_MASK_U32                    ((uint32)0x00000002U)
#define LPI2C_SIER_TDIE_MASK_U32                    ((uint32)0x00000001U)
                                                    
#define LPI2C_SMBUS_ALERT_ISR_ENABLE_U32            (LPI2C_SIER_SARIE_MASK_U32)
#define LPI2C_SMBUS_ALERT_ISR_DISABLE_U32           ((uint32)0x00000000U)
                                                    
#define LPI2C_GENERAL_CALL_ISR_ENABLE_U32           (LPI2C_SIER_GCIE_MASK_U32)
#define LPI2C_GENERAL_CALL_ISR_DISABLE_U32          ((uint32)0x00000000U)
                                                    
#define LPI2C_ADDRESS1_MATCH_ISR_ENABLE_U32         (LPI2C_SIER_AM1IE_MASK_U32)
#define LPI2C_ADDRESS1_MATCH_ISR_DISABLE_U32        ((uint32)0x00000000U)
                                                    
#define LPI2C_ADDRESS0_MATCH_ISR_ENABLE_U32         ((uint32)0x00000000U)
#define LPI2C_ADDRESS0_MATCH_ISR_DISABLE_U32        (LPI2C_SIER_AM0IE_MASK_U32)
                                                    
#define LPI2C_SLAVE_FIFO_ERROR_ISR_ENABLE_U32       (LPI2C_SIER_FEIE_MASK_U32)
#define LPI2C_SLAVE_FIFO_ERROR_ISR_DISABLE_U32      ((uint32)0x00000000U)
                                                    
#define LPI2C_SLAVE_BIT_ERROR_ISR_ENABLE_U32        (LPI2C_SIER_BEIE_MASK_U32)
#define LPI2C_SLAVE_BIT_ERROR_ISR_DISABLE_U32       ((uint32)0x00000000U)
    
#define LPI2C_SLAVE_STOP_DETECT_ISR_ENABLE_U32      (LPI2C_SIER_SDIE_MASK_U32)
#define LPI2C_SLAVE_STOP_DETECT_ISR_DISABLE_U32     ((uint32)0x00000000U)
    
#define LPI2C_REPEATED_START_ISR_ENABLE_U32         (LPI2C_SIER_RSIE_MASK_U32)
#define LPI2C_REPEATED_START_ISR_DISABLE_U32        ((uint32)0x00000000U)
    
#define LPI2C_TRANSMIT_ACK_ISR_ENABLE_U32           (LPI2C_SIER_TAIE_MASK_U32)
#define LPI2C_TRANSMIT_ACK_ISR_DISABLE_U32          ((uint32)0x00000000U)
    
#define LPI2C_ADDRESS_VALID_ISR_ENABLE_U32          (LPI2C_SIER_AVIE_MASK_U32)
#define LPI2C_ADDRESS_VALID_ISR_DISABLE_U32         ((uint32)0x00000000U)

#define LPI2C_SLAVE_RECEIVE_DATA_ISR_ENABLE_U32     (LPI2C_SIER_RDIE_MASK_U32)
#define LPI2C_SLAVE_RECEIVE_DATA_ISR_DISABLE_U32    ((uint32)0x00000000U)
                                                    
#define LPI2C_SLAVE_TRANSMIT_DATA_ISR_ENABLE_U32    (LPI2C_SIER_TDIE_MASK_U32)
#define LPI2C_SLAVE_TRANSMIT_DATA_ISR_DISABLE_U32   ((uint32)0x00000000U)

/**
* @brief    LPI2C Registers bits.
* @details  SDER register bit masks.
*/
#define LPI2C_SDER_AVDE_MASK_U32                ((uint32)0x00000004U)
#define LPI2C_SDER_RDDE_MASK_U32                ((uint32)0x00000002U)
#define LPI2C_SDER_TDDE_MASK_U32                ((uint32)0x00000001U)

/**
* @brief    LPI2C Registers bits.
* @details  SCFGR1 register bit masks.
*/
#define LPI2C_SCFGR1_ADDRCFG_MASK_U32         ((uint32)0x00070000U)
#define LPI2C_SCFGR1_HSMEN_MASK_U32           ((uint32)0x00002000U)
#define LPI2C_SCFGR1_IGNACK_MASK_U32          ((uint32)0x00001000U)
#define LPI2C_SCFGR1_RXCFG_MASK_U32           ((uint32)0x00000800U)
#define LPI2C_SCFGR1_TXCFG_MASK_U32           ((uint32)0x00000400U)
#define LPI2C_SCFGR1_SAEN_MASK_U32            ((uint32)0x00000200U)
#define LPI2C_SCFGR1_GCEN_MASK_U32            ((uint32)0x00000100U)
#define LPI2C_SCFGR1_ACKSTALL_MASK_U32        ((uint32)0x00000008U)
#define LPI2C_SCFGR1_TXDSTALL_MASK_U32        ((uint32)0x00000004U)
#define LPI2C_SCFGR1_RXDSTALL_MASK_U32        ((uint32)0x00000002U)
#define LPI2C_SCFGR1_ADRSTALL_MASK_U32        ((uint32)0x00000001U)

#define LPI2C_SLAVE_MATCH_ADDR0_7BIT_U32      ((uint32)0x00000000U)
#define LPI2C_SLAVE_MATCH_ADDR0_10BIT_U32     ((uint32)0x00010000U)

#define LPI2C_ENABLE_DETECTION_OF_HS_U32      (LPI2C_SCFGR1_HSMEN_MASK_U32)
#define LPI2C_DISABLE_DETECTION_OF_HS_U32     ((uint32)0x00000000U)

#define LPI2C_ACK_SCL_STALL_ENABLE_U32        (LPI2C_SCFGR1_ACKSTALL_MASK_U32)
#define LPI2C_ACK_SCL_STALL_DISABLE_U32       ((uint32)0x00000000U)
                                              
#define LPI2C_TX_DATA_SCL_STALL_ENABLE_U32    (LPI2C_SCFGR1_TXDSTALL_MASK_U32)
#define LPI2C_TX_DATA_SCL_STALL_DISABLE_U32   ((uint32)0x00000000U)
                                              
#define LPI2C_RX_DATA_SCL_STALL_ENABLE_U32    (LPI2C_SCFGR1_RXDSTALL_MASK_U32)
#define LPI2C_RX_DATA_SCL_STALL_DISABLE_U32   ((uint32)0x00000000U)
                                              
#define LPI2C_ADDRESS_SCL_STALL_ENABLE_U32    (LPI2C_SCFGR1_ADRSTALL_MASK_U32)
#define LPI2C_ADDRESS_SCL_STALL_DISABLE_U32   ((uint32)0x00000000U)

/**
* @brief    LPI2C Registers bits.
* @details  SCFGR2 register bit masks.
*/
#define LPI2C_SCFGR2_FILTSDA_MASK_U32   ((uint32)0x0F000000U)
#define LPI2C_SCFGR2_FILTSDA_SHIFT_U32  ((uint32)24U)
#define LPI2C_SCFGR2_FILTSCL_MASK_U32   ((uint32)0x000F0000U)
#define LPI2C_SCFGR2_FILTSCL_SHIFT_U32  ((uint32)16U)
#define LPI2C_SCFGR2_DATAVD_MASK_U32    ((uint32)0x00003F00U)
#define LPI2C_SCFGR2_DATAVD_SHIFT_U32   ((uint32)8U)
#define LPI2C_SCFGR2_CLKHOLD_MASK_U32   ((uint32)0x0000000FU)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_SLAVE_FILTSDA_U32(value)  ((uint32)((uint32)((value) << LPI2C_SCFGR2_FILTSDA_SHIFT_U32) & LPI2C_SCFGR2_FILTSDA_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_SLAVE_FILTSCL_U32(value)  ((uint32)((uint32)((value) << LPI2C_SCFGR2_FILTSCL_SHIFT_U32) & LPI2C_SCFGR2_FILTSCL_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_SLAVE_DATAVD_U32(value)   ((uint32)((uint32)((value) << LPI2C_SCFGR2_DATAVD_SHIFT_U32) & LPI2C_SCFGR2_DATAVD_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_SLAVE_CLKHOLD_U32(value)  (((value) & LPI2C_SCFGR2_CLKHOLD_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  SAMR register bit masks.
*/
#define LPI2C_SAMR_ADDR1_MASK_U32       ((uint32)0x007FE000U)
#define LPI2C_SAMR_ADDR1_SHIFT_U32      ((uint32)17U)
#define LPI2C_SAMR_ADDR0_MASK_U32       ((uint32)0x000007FEU)
#define LPI2C_SAMR_ADDR0_SHIFT_U32      ((uint32)1U)

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_ADDR1_U32(value)          ((uint32)((uint32)((value) << LPI2C_SAMR_ADDR1_SHIFT_U32) & LPI2C_SAMR_ADDR1_MASK_U32))

/** @violates @ref Reg_eSys_LPI2C_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPI2C_ADDR0_U32(value)          ((uint32)((uint32)((value) << LPI2C_SAMR_ADDR0_SHIFT_U32) & LPI2C_SAMR_ADDR0_MASK_U32))

/**
* @brief    LPI2C Registers bits.
* @details  SASR register bit masks.
*/
#define LPI2C_SASR_ANV_MASK_U32         ((uint32)0x00004000U)
#define LPI2C_SASR_RADDR_MASK_U32       ((uint32)0x000007FFU)
                                        
#define LPI2C_RADDR_IS_NOT_VALID_U32    (LPI2C_SASR_ANV_MASK_U32)
#define LPI2C_RADDR_IS_VALID_U32        ((uint32)0x00000000U)

/**
* @brief    LPI2C Registers bits.
* @details  STAR register bit masks.
*/
#define LPI2C_STAR_TXNACK_MASK_U32      ((uint32)0x00000001U)

#define LPI2C_TRANSMIT_ACK_U32          ((uint32)0x00000000U)
#define LPI2C_TRANSMIT_NACK_U32         (LPI2C_STAR_TXNACK_MASK_U32)

/**
* @brief    LPI2C Registers bits.
* @details  STDR register bit masks.
*/
#define LPI2C_STDR_DATA_MASK_U32        ((uint32)0x000000FFU)

/**
* @brief    LPI2C Registers bits.
* @details  SRDR register bit masks.
*/
#define LPI2C_SRDR_SOF_MASK_U32                   ((uint32)0x00008000U)
#define LPI2C_SRDR_RXEMPTY_MASK_U32               ((uint32)0x00004000U)
#define LPI2C_SRDR_DATA_MASK_U32                  ((uint32)0x000000FFU)
  
#define LPI2C_START_OF_FRAME_DETECTED_U32         (LPI2C_SRDR_SOF_MASK_U32)
#define LPI2C_RDR_NOT_EMPTY_U32                   ((uint32)0x00000000U)
#define LPI2C_RDR_EMPTY_U32                       (LPI2C_SRDR_RXEMPTY_MASK_U32)

#define LPI2C_FIFO_SIZE_U8                        (0x04U)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_eSys_LPI2C_H */

/** @} */
