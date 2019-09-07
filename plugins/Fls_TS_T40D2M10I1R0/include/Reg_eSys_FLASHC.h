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

#ifndef REG_ESYS_FLASHC_H
#define REG_ESYS_FLASHC_H

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
* @section Reg_eSys_FLASHC_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class
*          specifier, or a do-while-zero construct This is used to abstract access to register
*          protection bits
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
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
#define ESYS_FLASHC_VENDOR_ID                           43
/* @violates @ref Reg_eSys_FLASHC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION            4
/* @violates @ref Reg_eSys_FLASHC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_MINOR_VERSION            2
/* @violates @ref Reg_eSys_FLASHC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_REVISION_VERSION         2
#define ESYS_FLASHC_SW_MAJOR_VERSION                    1
#define ESYS_FLASHC_SW_MINOR_VERSION                    0
#define ESYS_FLASHC_SW_PATCH_VERSION                    1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Reg_eSys.h header file are of the same Autosar version */
    #if ((ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (ESYS_FLASHC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_FLASHC.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Platform Flash Register List
*/

#define FLASH_FSTAT_ADDR32     ((uint32)(FTFE_BASEADDR + (uint32)0x00UL)) /**< @brief Flash Status Register (FTFE_FSTAT) */
#define FLASH_FCNFG_ADDR32     ((uint32)(FTFE_BASEADDR + (uint32)0x01UL)) /**< @brief Flash Configuration Register (FTFE_FCNFG) */
#define FLASH_FSEC_ADDR32      ((uint32)(FTFE_BASEADDR + (uint32)0x02UL)) /**< @brief Flash Security Register (FTFE_FSEC) */
#define FLASH_FOPT_ADDR32      ((uint32)(FTFE_BASEADDR + (uint32)0x03UL)) /**< @brief Flash Option Register (FTFE_FOPT) */
#define FLASH_FCCOB3_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x04UL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB3) */
#define FLASH_FCCOB2_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x05UL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB2) */
#define FLASH_FCCOB1_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x06UL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB1) */
#define FLASH_FCCOB0_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x07UL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB0) */
#define FLASH_FCCOB7_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x08UL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB7) */
#define FLASH_FCCOB6_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x09UL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB6) */
#define FLASH_FCCOB5_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0AUL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB5) */
#define FLASH_FCCOB4_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0BUL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB4) */
#define FLASH_FCCOBB_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0CUL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOBB) */
#define FLASH_FCCOBA_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0DUL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOA) */
#define FLASH_FCCOB9_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0EUL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB9) */
#define FLASH_FCCOB8_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0FUL)) /**< @brief Flash Common Command Object Registers(FTFE_FCCOB8) */
#define FLASH_FPROT3_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x10UL)) /**< @brief Program Flash Protection Registers (FTFE_FPROT3) */
#define FLASH_FPROT2_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x11UL)) /**< @brief Program Flash Protection Registers (FTFE_FPROT2) */
#define FLASH_FPROT1_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x12UL)) /**< @brief Program Flash Protection Registers (FTFE_FPROT1) */
#define FLASH_FPROT0_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x13UL)) /**< @brief Program Flash Protection Registers (FTFE_FPROT0) */
#define FLASH_FEPROT_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x16UL)) /**< @brief EEPROM Protection Register (FTFE_FEPROT) */
#define FLASH_FDPROT_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x17UL)) /**< @brief Data Flash Protection Register (FTFE_FDPROT) */
#define FLASH_FCSESTAT_ADDR32  ((uint32)(FTFE_BASEADDR + (uint32)0x2CUL)) /**< @brief Flash CSE Status Register (FTFE_FCSESTAT) */
#define FLASH_FERSTAT_ADDR32   ((uint32)(FTFE_BASEADDR + (uint32)0x2EUL)) /**< @brief Flash Error Status Register (FTFE_FERSTAT) */
#define FLASH_FERCNFG_ADDR32   ((uint32)(FTFE_BASEADDR + (uint32)0x2FUL)) /**< @brief Flash Error Configuration Register (FTFE_FERCNFG) */

#define FLASH_FSTAT_OFFSET         (0x00U)
/**
 * @brief Flash Status Register (FTFE_FSTAT)
 */
#define FLASH_FSTAT_CCIF_U8         (0x0080U) /**< @brief Command Complete Interrupt Flag */
#define FLASH_FSTAT_RDCOLERR_U8     (0x0040U) /**< @brief FTFE Read Collision Error Flag */
#define FLASH_FSTAT_ACCERR_U8       (0x0020U) /**< @brief Flash Access Error Flag */
#define FLASH_FSTAT_FPVIOL_U8       (0x0010U) /**< @brief Flash Protection Violation Flag */
#define FLASH_FSTAT_MGSTAT0_U8      (0x0001U) /**< @brief Memory Controller Command Completion Status Flag */

/* FSTAT masks for W1C operations */
#define FLASH_FSTAT_CCIF_W1C        (FLASH_FSTAT_CCIF_U8)        
#define FLASH_FSTAT_RDCOLERR_W1C    (FLASH_FSTAT_RDCOLERR_U8)
#define FLASH_FSTAT_ACCERR_W1C      (FLASH_FSTAT_ACCERR_U8)      
#define FLASH_FSTAT_FPVIOL_W1C      (FLASH_FSTAT_FPVIOL_U8)     

/**
 * @brief Flash Configuration Register (FTFE_FCNFG)
 */
#define FLASH_FCNFG_CCIE_U8         (0x80U) /**< @brief Command Complete Interrupt Enable */
#define FLASH_FCNFG_ERSSUSP_U8      (0x10U) /**< @brief Erase Suspend */
#define FLASH_FCNFG_RAMRDY_U8       (0x02U) /**< @brief RAM Ready */
#define FLASH_FCNFG_EEERDY_U8       (0x01U) /**< @brief EEE Ready */

/**
 * @brief Flash Status Register (FTFE_FERSTAT)
 */
#define FLASH_FERSTAT_DFDIF_U8      (0x02U) /**< @brief Double Bit Fault Detect Interrupt Flag*/

/* FERSTAT mask for  W1C operations */
#define FLASH_FERSTAT_DFDIF_W1C     (FLASH_FERSTAT_DFDIF_U8)

/**
 * @brief Flash Error Configuration Register (FTFE_FERCNFG)
 */
#define FLASH_FERCNFG_DFDIE_U8      (0x02) /**< @brief Double Bit Fault Detect Interrupt Enable*/

/**
 * @brief Program Flash Protection Registers (FTFE_FPROTn)
 */
#define FLASH_FPROT3_P00            (0x01U)    /**< @brief Protection region 0 */
#define FLASH_FPROT3_P01            (0x02U)    /**< @brief Protection region 1 */
#define FLASH_FPROT3_P02            (0x04U)    /**< @brief Protection region 2 */
#define FLASH_FPROT3_P03            (0x08U)    /**< @brief Protection region 3 */
#define FLASH_FPROT3_P04            (0x10U)    /**< @brief Protection region 4 */
#define FLASH_FPROT3_P05            (0x20U)    /**< @brief Protection region 5 */
#define FLASH_FPROT3_P06            (0x40U)    /**< @brief Protection region 6 */
#define FLASH_FPROT3_P07            (0x80U)    /**< @brief Protection region 7 */

#define FLASH_FPROT2_P08            (0x01U)    /**< @brief Protection region 8 */
#define FLASH_FPROT2_P09            (0x02U)    /**< @brief Protection region 9 */
#define FLASH_FPROT2_P10            (0x04U)    /**< @brief Protection region 10 */
#define FLASH_FPROT2_P11            (0x08U)    /**< @brief Protection region 11 */
#define FLASH_FPROT2_P12            (0x10U)    /**< @brief Protection region 12 */
#define FLASH_FPROT2_P13            (0x20U)    /**< @brief Protection region 13 */
#define FLASH_FPROT2_P14            (0x40U)    /**< @brief Protection region 14 */
#define FLASH_FPROT2_P15            (0x80U)    /**< @brief Protection region 15 */

#define FLASH_FPROT1_P16            (0x01U)    /**< @brief Protection region 16 */
#define FLASH_FPROT1_P17            (0x02U)    /**< @brief Protection region 17 */
#define FLASH_FPROT1_P18            (0x04U)    /**< @brief Protection region 18 */
#define FLASH_FPROT1_P19            (0x08U)    /**< @brief Protection region 19 */
#define FLASH_FPROT1_P20            (0x10U)    /**< @brief Protection region 20 */
#define FLASH_FPROT1_P21            (0x20U)    /**< @brief Protection region 21 */
#define FLASH_FPROT1_P22            (0x40U)    /**< @brief Protection region 22 */
#define FLASH_FPROT1_P23            (0x80U)    /**< @brief Protection region 23 */

#define FLASH_FPROT0_P24            (0x01U)    /**< @brief Protection region 24 */
#define FLASH_FPROT0_P25            (0x02U)    /**< @brief Protection region 25 */
#define FLASH_FPROT0_P26            (0x04U)    /**< @brief Protection region 26 */
#define FLASH_FPROT0_P27            (0x08U)    /**< @brief Protection region 27 */
#define FLASH_FPROT0_P28            (0x10U)    /**< @brief Protection region 28 */
#define FLASH_FPROT0_P29            (0x20U)    /**< @brief Protection region 29 */
#define FLASH_FPROT0_P30            (0x40U)    /**< @brief Protection region 30 */
#define FLASH_FPROT0_P31            (0x80U)    /**< @brief Protection region 31 */

/**
 * @brief Data Flash Protection Registers (FTFE_FDPROT)
 */
#define FLASH_FDPROT_P00            (0x01U)    /**< @brief Protection region 0 */
#define FLASH_FDPROT_P01            (0x02U)    /**< @brief Protection region 1 */
#define FLASH_FDPROT_P02            (0x04U)    /**< @brief Protection region 2 */
#define FLASH_FDPROT_P03            (0x08U)    /**< @brief Protection region 3 */
#define FLASH_FDPROT_P04            (0x10U)    /**< @brief Protection region 4 */
#define FLASH_FDPROT_P05            (0x20U)    /**< @brief Protection region 5 */
#define FLASH_FDPROT_P06            (0x40U)    /**< @brief Protection region 6 */
#define FLASH_FDPROT_P07            (0x80U)    /**< @brief Protection region 7 */

/**
 * @brief Flash CSE Status Register (FTFE_FCSESTAT)
 */
#define FLASH_FCSESTAT_BSY_U8          (0x0001U) /**< @brief Busy Flag */
#define FLASH_FCSESTAT_SB_U8           (0x0002U) /**< @brief Secure Boot Flag */
#define FLASH_FCSESTAT_BIN_U8          (0x0004U) /**< @brief Secure Boot Initialization Flag */
#define FLASH_FCSESTAT_BFN_U8          (0x0008U) /**< @brief Secure Boot Finished Flag */
#define FLASH_FCSESTAT_BOK_U8          (0x0010U) /**< @brief Secure Boot OK Flag */
#define FLASH_FCSESTAT_RIN_U8          (0x0020U) /**< @brief Random Number Generator Initialized Flag */
#define FLASH_FCSESTAT_EDB_U8          (0x0040U) /**< @brief External Debug Flag */
#define FLASH_FCSESTAT_IDB_U8          (0x0080U) /**< @brief Internal Debug Flag */

/**
 * @brief FCCOB commands IDs
 */
#define FLASH_CMD_READ1S_BLOCK                  (0x00U)
#define FLASH_CMD_READ1S_SECTION                (0x01U)
#define FLASH_CMD_PROGRAM_CHECK                 (0x02U)
#define FLASH_CMD_PROGRAM_PHRASE                (0x07U)
#define FLASH_CMD_ERASE_BLOCK                   (0x08U)
#define FLASH_CMD_ERASE_SECTOR                  (0x09U)
#define FLASH_CMD_PROGRAM_SECTION               (0x0BU)
#define FLASH_CMD_READ1S_ALLBLOCKS              (0x40U)
#define FLASH_CMD_READ_ONCE                     (0x41U)
#define FLASH_CMD_PROGRAM_ONCE                  (0x43U)
#define FLASH_CMD_ERASE_ALLBLOCKS               (0x44U)
#define FLASH_CMD_VERIFY_BACKDOOR               (0x45U)
#define FLASH_CMD_ERASE_ALLBLOCKS_UNSECURE      (0x49U)
#define FLASH_CMD_PROGRAM_PARTITION             (0x80U)
#define FLASH_CMD_SET_FLEXRAM                   (0x81U)

/* FlexNVM EEPROM Data Set Sizes (size in Bytes)- used for Program Partition Command */
#define FLASH_FLEXNVM_EEPROM_0                  (0x0FU)         /* used for when the FlexNVM Partition Code is set for no EEPROM */
#define FLASH_FLEXNVM_EEPROM_4096               (0x02U)
#define FLASH_FLEXNVM_EEPROM_2048               (0x03U)

/* FlexNVM Partition Code Ratios (DFLASH_EEPROM sizes in KB) - used for Program Partition Command */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V1     (0x00U)   /* Bit value:0000   Data flash (KByte):32 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V1     (0x03U)   /* Bit value:0011   Data flash (KByte):0  EEPROM backup (KByte):32 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V2     (0x08U)   /* Bit value:1000   Data flash (KByte):0  EEPROM backup (KByte):32 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_8_24_V1     (0x09U)   /* Bit value:1001   Data flash (KByte):8  EEPROM backup (KByte):24 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V2     (0x0BU)   /* Bit value:1011   Data flash (KByte):32 EEPROM backup (KByte):0 */

#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V1     (0x00U)   /* Bit value:0000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V1    (0x03U)   /* Bit value:0011   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V1     (0x04U)   /* Bit value:0100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V2     (0x08U)   /* Bit value:1000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_16_48_V1    (0x0AU)   /* Bit value:1010   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V2    (0x0BU)   /* Bit value:1011   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V2     (0x0CU)   /* Bit value:1100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V3     (0x0FU)   /* Bit value:1111   Data flash (KByte):64 EEPROM backup (KByte):0 */

#define FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V1    (0x00U)   /* Bit value:0000   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_448_64_V1   (0x04U)   /* Bit value:0100   Data flash (KByte):64 EEPROM backup (KByte):0 */
#define FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V2    (0x0FU)   /* Bit value:1111   Data flash (KByte):64 EEPROM backup (KByte):0 */

/* Flash configuration field address */
#define FLASH_CONFIG_FIELD_ADDR_OFFSET          (0x000408UL)  /* First aligned address containing FPROT0-3 and FDPROT flash sector protection registers */


/* MSCM (Miscellaneous System Control Module) register offset - Flash Prefetch Buffers control */
#define FLASH_MSCM_OCMDR0_ADDR32           ((uint32)(MSCM_BASEADDR + (uint32)0x400UL)) /* On-Chip Memory Descriptor Register (MSCM_OCMDR0) */
#define FLASH_MSCM_OCMDR1_ADDR32           ((uint32)(MSCM_BASEADDR + (uint32)0x404UL)) /* On-Chip Memory Descriptor Register (MSCM_OCMDR1) */

/* OCMDRx bitfield macro */
#define FLASH_MSCM_OCMDR0_OCMC1_U32         (0x20UL)    /* OCMEM Control Field 1, OCMDR0[5] controls prefetches for PFLASH */
#define FLASH_MSCM_OCMDR1_OCMC1_U32         (0x20UL)    /* OCMEM Control Field 1, OCMDR1[5] controls prefetches for DFLASH */

/* SIM (System Integration Module) */
#define FLASH_SIM_BASEADDR              ((uint32)0x40048000UL)
/* Flash Configuration Register 1 (FCFG1) address offset */
#define FLASH_SIM_FCFG1_ADDR_OFFSET     ((uint32)0x4CUL)
/* Flash Configuration Register 1 (FCFG1) address */     
#define FLASH_SIM_FCFG1_ADDR32          ((uint32)(FLASH_SIM_BASEADDR + FLASH_SIM_FCFG1_ADDR_OFFSET))
/* FlexNVM partition code (DEPART) bits mask */
#define FLASH_SIM_FCFG1_DEPART_U32      ((uint32)0x0000F000UL)

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_FLASHC_H*/

/** @} */
