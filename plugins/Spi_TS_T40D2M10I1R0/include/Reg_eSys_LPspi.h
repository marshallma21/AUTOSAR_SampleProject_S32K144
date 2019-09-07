/**
*   @file    Reg_eSys_LPspi.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Reg eSys header file.
*   @details Reg eSys header file.

*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI
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

#ifndef REG_ESYS_LPSPI_H
#define REG_ESYS_LPSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Reg_eSys_LPspi_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* Compiler abstraction need to implement function-like macros to hide
* compiler specifics from the implementation.
*
* @section Reg_eSys_LPspi_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Reg_eSys_LPspi_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity
* are supported for external identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Reg_eSys_LPspi.c
* @requirements   BSW00374, BSW00318, SPI276.
*/
/*
* @violates @ref Reg_eSys_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
#include "Reg_eSys.h"
#include "StdRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_LPspi.h
*/
#define SPI_VENDOR_ID_REGFLEX                    43
#define SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX     4
#define SPI_AR_RELEASE_MINOR_VERSION_REGFLEX     2
/*
* @violates @ref Reg_eSys_LPspi_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_REGFLEX  2
#define SPI_SW_MAJOR_VERSION_REGFLEX             1
#define SPI_SW_MINOR_VERSION_REGFLEX             0
#define SPI_SW_PATCH_VERSION_REGFLEX             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and Reg_eSys header file are of the same version */
  #if ((SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Reg_eSys_LPspi.c and Reg_eSys.h are different"
  #endif

  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_REGFLEX != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Reg_eSys_LPspi.c and StdRegMacros.h are different"
  #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
/*
* @violates @ref Reg_eSys_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
 #include "Spi_MemMap.h"
 

/* HWUnit base address mapping array */
extern CONST(uint32, SPI_CONST) Spi_LPspi_au32BaseAddrs[13];

#define SPI_STOP_SEC_CONST_32
/*
* @violates @ref Reg_eSys_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
 #include "Spi_MemMap.h"
 /*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Macros used for low-level LPSPI register manipulation (begin section).
*/
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*to a function-like macro.
*/

#define LPSPI_GET_BASE_ADDRESS_U32(offset) \
    ((uint32)Spi_LPspi_au32BaseAddrs[(offset)])

/* Version ID Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_VERID_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)]))

/* Parameter Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_PARAM_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x04u))

/* Control Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_CR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x10u))

/* Status Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2SR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x14u))
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_SR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x14u))

/* Interrupt Enable Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_IER_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x18u))

/* DMA Enable Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2DER_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x1Cu))
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_DER_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x1Cu))

/* Configuration Register 0 */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_CFGR0_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x20u))

/* Configuration Register 1 */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_CFGR1_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x24u))

/* Data Match Register 0 */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_DMR0_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x30u))

/* Data Match Register 1 */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_DMR1_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x34u))

/* Clock Configuration Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2CCR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x40u))
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_CCR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x40u))

/* FIFO Control Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2FCR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x58u))
    
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_FCR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x58u))

/* FIFO Status Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2FSR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x5Cu))
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_FSR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x5Cu))

/* Transmit Command Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2TCR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x60u))

/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_TCR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x60u))

/* Transmit Data Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2TDR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x64u))

/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_TDR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x64u))

/* Receive Status Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2RSR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x70u))
    
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_RSR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x70u))

/* Receive Data Register */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_BASEADDR2RDR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x74u))
    
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_RDR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_LPspi_au32BaseAddrs[(offset)] + 0x74u))    
    
/**
* @brief Macros used for low-level LPSPI register read/writes operations (begin section).
*/

/* ---------- Read transfer count register to manage queue --Start ---------- */

/* Read TXCOUNT FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_FSR_TXCOUNT_VAL_U32(value) \
    ((value) & LPSPI_FSR_TXCOUNT_MASK_U32)

/* Read RXCOUNT FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_LPspi_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define LPSPI_FSR_RXCOUNT_VAL_U32(value) \
    (((value) & LPSPI_FSR_RXCOUNT_MASK_U32) >> 16 )
    
    
/*-----------------------------------------------------------------------*/

/* LPSPI reserved bit masks */
#define LPSPI_CR_RESERVED_MASK_U32        ((uint32)0x0000030Fu)
#define LPSPI_SR_RESERVED_MASK_U32        ((uint32)0x01003F03u)
#define LPSPI_IER_RESERVED_MASK_U32       ((uint32)0x00003F03u)
#define LPSPI_DER_RESERVED_MASK_U32       ((uint32)0x00000003u)
#define LPSPI_CFGR0_RESERVED_MASK_U32     ((uint32)0x00000307u)
#define LPSPI_CFGR1_RESERVED_MASK_U32     ((uint32)0x0F070F0Fu)
#define LPSPI_FCR_RESERVED_MASK_U32       ((uint32)0x00030003u)
#define LPSPI_FSR_RESERVED_MASK_U32       ((uint32)0x00070007u)
#define LPSPI_TCR_RESERVED_MASK_U32       ((uint32)0xFBFF0FFFu)
#define LPSPI_RSR_RESERVED_MASK_U32       ((uint32)0x00000003u)

/* Control Register LPSPI_CR Attributes */
#define LPSPI_CR_RRF_RESET_U32            ((uint32)0x00000200u) /* Receive FIFO is reset */
#define LPSPI_CR_RTF_RESET_U32            ((uint32)0x00000100u) /* Transmit FIFO is reset */
#define LPSPI_CR_DBGEN_EN_U32             ((uint32)0x00000008u) /* Module is enabled in debug mode */
#define LPSPI_CR_DOZEN_EN_U32             ((uint32)0x00000004u) /* Module is disabled in doze mode */
#define LPSPI_CR_RST_RESET_U32            ((uint32)0x00000002u) /* Master logic is reset */
#define LPSPI_CR_MEN_EN_U32               ((uint32)0x00000001u) /* Module is enabled */
#define LPSPI_CR_RESET_U32                ((uint32)0x00000000u) /* Reset value for CR register */

/* Status Register LPSPI_SR Attributes */
#define LPSPI_SR_MBF_MASK_U32             ((uint32)0x01000000u) /* Module Busy Flag */
#define LPSPI_SR_DMF_W1C                  ((uint32)0x00002000u) /* Data Match Flag */
#define LPSPI_SR_REF_W1C                  ((uint32)0x00001000u) /* Receive Error Flag */
#define LPSPI_SR_TEF_W1C                  ((uint32)0x00000800u) /* Transmit Error Flag */
#define LPSPI_SR_TCF_W1C                  ((uint32)0x00000400u) /* Transfer Complete Flag */
#define LPSPI_SR_FCF_W1C                  ((uint32)0x00000200u) /* Frame Complete Flag */
#define LPSPI_SR_WCF_W1C                  ((uint32)0x00000100u) /* Word Complete Flag */
#define LPSPI_SR_RDF_MASK_U32             ((uint32)0x00000002u) /* Receive Data Flag */
#define LPSPI_SR_TDF_MASK_U32             ((uint32)0x00000001u) /* Transmit Data Flag */
#define LPSPI_SR_INT_MASK_U32             ((uint32)( LPSPI_SR_DMF_W1C | LPSPI_SR_REF_W1C | LPSPI_SR_TEF_W1C | \
                                            LPSPI_SR_TCF_W1C | LPSPI_SR_FCF_W1C | LPSPI_SR_WCF_W1C))
/* Interrupt Enable Register LPSPI_IER Attributes */
#define LPSPI_IER_DMIE_MASK_U32           ((uint32)0x00002000u) /* Data Match Interrupt Enable */
#define LPSPI_IER_REIE_MASK_U32           ((uint32)0x00001000u) /* Receive Error Interrupt Enable */
#define LPSPI_IER_TEIE_MASK_U32           ((uint32)0x00000800u) /* Transmit Error Interrupt Enable */
#define LPSPI_IER_TCIE_MASK_U32           ((uint32)0x00000400u) /* Transfer Complete Interrupt Enable */
#define LPSPI_IER_FCIE_MASK_U32           ((uint32)0x00000200u) /* Frame Complete Interrupt Enable */
#define LPSPI_IER_WCIE_MASK_U32           ((uint32)0x00000100u) /* Word Complete Interrupt Enable */
#define LPSPI_IER_RDIE_MASK_U32           ((uint32)0x00000002u) /* Receive Data Interrupt Enable */
#define LPSPI_IER_TDIE_MASK_U32           ((uint32)0x00000001u) /* Transmit Data Interrupt Enable */

/* DMA Enable Register LPSPI_DER Attributes */
#define LPSPI_DER_RDDE_MASK_U32           ((uint32)0x00000002u) /* Receive Data DMA Enable */
#define LPSPI_DER_TDDE_MASK_U32           ((uint32)0x00000001u) /* Transmit Data DMA Enable */

/* Configuration Register 0 LPSPI_CFGR0 Attributes */
#define LPSPI_CFGR0_RDMO_MASK_U32         ((uint32)0x00000200u) /* Receive Data Match Only */
#define LPSPI_CFGR0_CIRFIFO_MASK_U32      ((uint32)0x00000100u) /* Circular FIFO Enable */
#define LPSPI_CFGR0_HRSEL_MASK_U32        ((uint32)0x00000004u) /* Host Request Select */
#define LPSPI_CFGR0_HRPOL_MASK_U32        ((uint32)0x00000002u) /* Host Request Polarity */
#define LPSPI_CFGR0_HREN_MASK_U32         ((uint32)0x00000001u) /* Host Request Enable */

/* Configuration Register 1 LPSPI_CFGR1 Attributes */
#define LPSPI_CFGR1_PCSCFG_MASK_U32       ((uint32)0x08000000u) /* Peripheral Chip Select Configuration */
#define LPSPI_CFGR1_OUTCFG_MASK_U32       ((uint32)0x04000000u) /* Output Config */
#define LPSPI_CFGR1_PINCFG_NORMAL_U32     ((uint32)0x00000000u) /* SIN is used for input data and SOUT for output data */
#define LPSPI_CFGR1_PINCFG_SOUT_BOTH_U32  ((uint32)0x01000000u) /* SOUT is used for both input and output data */
#define LPSPI_CFGR1_PINCFG_SDI_BOTH_U32   ((uint32)0x02000000u) /* SDI is used for both input and output data */
#define LPSPI_CFGR1_PINCFG_REVERSE_U32    ((uint32)0x03000000u) /* SOUT is used for input data and SIN for output data */

#define LPSPI_CFGR1_MATCFG_DIS_U32        ((uint32)0x00000000u) /* Match Disable */
#define LPSPI_CFGR1_MATCFG_CFG0_U32       ((uint32)0x00020000u) /* Match enabled (1st data word equals MATCH0 OR MATCH1) */
#define LPSPI_CFGR1_MATCFG_CFG1_U32       ((uint32)0x00030000u) /* Match enabled (any data word equals MATCH0 OR MATCH1) */
#define LPSPI_CFGR1_MATCFG_CFG2_U32       ((uint32)0x00040000u) /* Match enabled (1st data word equals MATCH0 AND 2nd data word equals MATCH1) */
#define LPSPI_CFGR1_MATCFG_CFG3_U32       ((uint32)0x00050000u) /* Match enabled (any data word equals MATCH0 AND next data word equals MATCH1) */
#define LPSPI_CFGR1_MATCFG_CFG4_U32       ((uint32)0x00060000u) /* Match enabled (1st data word AND MATCH1 equals MATCH0 AND MATCH1) */
#define LPSPI_CFGR1_MATCFG_CFG5_U32       ((uint32)0x00070000u) /* Match enabled (any data word AND MATCH1 equals MATCH0 AND MATCH1) */

#define LPSPI_CFGR1_PCSxPOL_IDLEHIGH_U32  ((uint32)0x00000000u) /* Peripheral Chip Select Polarity - Active Low */
#define LPSPI_CFGR1_PCS0_IDLELOW_U32      ((uint32)0x00000100u) /* Peripheral Chip Select Polarity - Active High */
#define LPSPI_CFGR1_PCS1_IDLELOW_U32      ((uint32)0x00000200u) /* Peripheral Chip Select Polarity - Active High */
#define LPSPI_CFGR1_PCS2_IDLELOW_U32      ((uint32)0x00000400u) /* Peripheral Chip Select Polarity - Active High */
#define LPSPI_CFGR1_PCS3_IDLELOW_U32      ((uint32)0x00000800u) /* Peripheral Chip Select Polarity - Active High */

#define LPSPI_CFGR1_NOSTALL_MASK_U32      ((uint32)0x00000008u) /* Transfers will not stall, allowing transmit FIFO underrun or receive FIFO overrun to occur */
#define LPSPI_CFGR1_AUTOPCS_MASK_U32      ((uint32)0x00000004u) /* Automatic PCS generation enabled */
#define LPSPI_CFGR1_SAMPLE_MASK_U32       ((uint32)0x00000002u) /* Input data sampled on delayed SCK edge */
#define LPSPI_CFGR1_MASTER_EN_U32         ((uint32)0x00000001u) /* Module is Master mode */

/* Clock Configuration Register LPSPI_CCR Attributes */
#define LPSPI_CCR_SCKPCS_MASK_U32         ((uint32)0xFF000000u) /* SCK to PCS Delay */
#define LPSPI_CCR_PCSSCK_MASK_U32         ((uint32)0x00FF0000u) /* PCS to SCK Delay */
#define LPSPI_CCR_DBT_MASK_U32            ((uint32)0x0000FF00u) /* Delay Between Transfers */
#define LPSPI_CCR_SCKDIV_MASK_U32         ((uint32)0x000000FFu) /* SCK Divider */

/* FIFO Control Register LPSPI_FCR Attributes */
#define LPSPI_FCR_RXWATER_MASK_U32        ((uint32)0x00030000u) /* Receive FIFO Watermark */
#define LPSPI_FCR_TXWATER_MASK_U32        ((uint32)0x00000003u) /* Transmit FIFO Watermark */

/* FIFO Status Register LPSPI_FSR Attributes */
#define LPSPI_FSR_RXCOUNT_MASK_U32        ((uint32)0x00070000u) /* Receive FIFO Count */
#define LPSPI_FSR_TXCOUNT_MASK_U32        ((uint32)0x00000007u) /* Transmit FIFO Count */

/* Transmit Command Register LPSPI_TCR Attributes */
#define LPSPI_TCR_CPOL_LOW_U32            ((uint32)0x00000000u) /* The inactive state value of SCK is low */
#define LPSPI_TCR_CPOL_HIGH_U32           ((uint32)0x80000000u) /* The inactive state value of SCK is high */
#define LPSPI_TCR_CPHA_LEADING_U32        ((uint32)0x40000000u) /* Data is changed on the leading edge of SCK and captured on the following edge */
#define LPSPI_TCR_CPHA_TRAILING_U32       ((uint32)0x00000000u) /* Data is captured on the leading edge of SCK and changed on the following edge */

#define LPSPI_TCR_PRESCALE_1_U32          ((uint32)0x00000000u) /* Divide by 1 */
#define LPSPI_TCR_PRESCALE_2_U32          ((uint32)0x08000000u) /* Divide by 2 */
#define LPSPI_TCR_PRESCALE_4_U32          ((uint32)0x10000000u) /* Divide by 4 */
#define LPSPI_TCR_PRESCALE_8_U32          ((uint32)0x18000000u) /* Divide by 8 */
#define LPSPI_TCR_PRESCALE_16_U32         ((uint32)0x20000000u) /* Divide by 16 */
#define LPSPI_TCR_PRESCALE_32_U32         ((uint32)0x28000000u) /* Divide by 32 */
#define LPSPI_TCR_PRESCALE_64_U32         ((uint32)0x30000000u) /* Divide by 64 */
#define LPSPI_TCR_PRESCALE_128_U32        ((uint32)0x38000000u) /* Divide by 128 */

#define LPSPI_TCR_PCS0_EN_U32             ((uint32)0x00000000u) /* Transfer using LPSPI_PCS[0] */
#define LPSPI_TCR_PCS1_EN_U32             ((uint32)0x01000000u) /* Transfer using LPSPI_PCS[1] */
#define LPSPI_TCR_PCS2_EN_U32             ((uint32)0x02000000u) /* Transfer using LPSPI_PCS[2] */
#define LPSPI_TCR_PCS3_EN_U32             ((uint32)0x03000000u) /* Transfer using LPSPI_PCS[3] */

#define LPSPI_TCR_MSB_U32                 ((uint32)0x00000000u) /* Data is transferred MSB first */
#define LPSPI_TCR_LSB_U32                 ((uint32)0x00800000u) /* Data is transferred LSB first */
#define LPSPI_TCR_BYSW_EN_U32             ((uint32)0x00400000u) /* Byte swap enabled */
#define LPSPI_TCR_BYSW_DIS_U32            ((uint32)0x00000000u) /* Byte swap disable */

#define LPSPI_TCR_CONT_EN_U32             ((uint32)0x00200000u) /* Continuous transfer enabled */
#define LPSPI_TCR_CONT_DIS_U32            ((uint32)0x00000000u) /* Continuous transfer enabled */
#define LPSPI_TCR_CONTC_MASK_U32          ((uint32)0x00100000u) /* Command word for continuing transfer */

#define LPSPI_TCR_RXMSK_MASK_U32          ((uint32)0x00080000u) /* Receive data is masked */
#define LPSPI_TCR_TXMSK_MASK_U32          ((uint32)0x00040000u) /* Mask transmit data */

#define LPSPI_TCR_WIDTH_1_U32             ((uint32)0x00000000u) /* Single bit transfer */
#define LPSPI_TCR_WIDTH_2_U32             ((uint32)0x00010000u) /* Two bita transfer */
#define LPSPI_TCR_WIDTH_4_U32             ((uint32)0x00020000u) /* Four bits transfer */
#define LPSPI_TCR_FRAMESZ_MASK_U32        ((uint32)0x00000FFFu) /* Frame Size */

/* Receive Status Register LPSPI_RSR Attributes */
#define LPSPI_RSR_RXEMPTY_MASK_U32        ((uint32)0x00000002u) /* RX FIFO is empty */
#define LPSPI_RSR_SOF_MASK_U32            ((uint32)0x00000001u) /* First data word received after LPSPI_PCS assertion */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* Reg_eSys_LPspi_H */



/** @} */
