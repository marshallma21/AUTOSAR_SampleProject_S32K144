/**
*   @file    Reg_eSys_Ftfc.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - Defines used to access the Eeprom registers.
*   @details This file contains defines used to access the Eeprom registers.
*
*   @addtogroup EEP
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

#ifndef REG_ESYS_FTFC_H
#define REG_ESYS_FTFC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_FTFC_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section REG_ESYS_FTFC_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section REG_ESYS_FTFC_H_REF_3
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
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by smcal coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to EEP.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/**
* @violates @ref REG_ESYS_FTFC_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ESYS_FLASHC_VENDOR_ID                           43
/* @violates @ref REG_ESYS_FTFC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION            4
/* @violates @ref REG_ESYS_FTFC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_MINOR_VERSION            2
/* @violates @ref REG_ESYS_FTFC_H_REF_2 Identifier exceeds 31 characters */
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
        #error "AutoSar Version Numbers of Reg_eSys_Ftfc.h and Reg_eSys.h are different"
    #endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief Platform Eeprom Register List
*/

#define EEPROM_FSTAT_ADDR32     ((uint32)(FTFE_BASEADDR + (uint32)0x00UL)) /**< @brief Eeprom Status Register (FTFE_FSTAT) */
#define EEPROM_FCNFG_ADDR32     ((uint32)(FTFE_BASEADDR + (uint32)0x01UL)) /**< @brief Eeprom Configuration Register (FTFE_FCNFG) */
#define EEPROM_FSEC_ADDR32      ((uint32)(FTFE_BASEADDR + (uint32)0x02UL)) /**< @brief Eeprom Security Register (FTFE_FSEC) */
#define EEPROM_FOPT_ADDR32      ((uint32)(FTFE_BASEADDR + (uint32)0x03UL)) /**< @brief Eeprom Option Register (FTFE_FOPT) */
#define EEPROM_FCCOB3_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x04UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB3) */
#define EEPROM_FCCOB2_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x05UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB2) */
#define EEPROM_FCCOB1_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x06UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB1) */
#define EEPROM_FCCOB0_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x07UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB0) */
#define EEPROM_FCCOB7_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x08UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB7) */
#define EEPROM_FCCOB6_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x09UL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB6) */
#define EEPROM_FCCOB5_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0AUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB5) */
#define EEPROM_FCCOB4_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0BUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB4) */
#define EEPROM_FCCOBB_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0CUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOBB) */
#define EEPROM_FCCOBA_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0DUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOA) */
#define EEPROM_FCCOB9_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0EUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB9) */
#define EEPROM_FCCOB8_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x0FUL)) /**< @brief Eeprom Common Command Object Registers(FTFE_FCCOB8) */
#define EEPROM_FPROT3_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x10UL)) /**< @brief Program Eeprom Protection Registers (FTFE_FPROT3) */
#define EEPROM_FPROT2_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x11UL)) /**< @brief Program Eeprom Protection Registers (FTFE_FPROT2) */
#define EEPROM_FPROT1_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x12UL)) /**< @brief Program Eeprom Protection Registers (FTFE_FPROT1) */
#define EEPROM_FPROT0_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x13UL)) /**< @brief Program Eeprom Protection Registers (FTFE_FPROT0) */
#define EEPROM_FEPROT_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x16UL)) /**< @brief EEPROM Protection Register (FTFE_FEPROT) */
#define EEPROM_FDPROT_ADDR32    ((uint32)(FTFE_BASEADDR + (uint32)0x17UL)) /**< @brief Data Eeprom Protection Register (FTFE_FDPROT) */
#define EEPROM_FCSESTAT_ADDR32  ((uint32)(FTFE_BASEADDR + (uint32)0x2CUL))  /**< @brief Eeprom CSE Status Register (FTFE_FCSESTAT) */
#define EEPROM_FERSTAT_ADDR32   ((uint32)(FTFE_BASEADDR + (uint32)0x2EUL)) /**< @brief Eeprom Error Status Register (FTFE_FERSTAT) */
#define EEPROM_FERCNFG_ADDR32   ((uint32)(FTFE_BASEADDR + (uint32)0x2FUL)) /**< @brief Eeprom Error Configuration Register (FTFE_FERCNFG) */

#define EEPROM_FSTAT_OFFSET         (0x00U)
/**
 * @brief Eeprom Status Register (FTFE_FSTAT)
 */
#define EEPROM_FSTAT_CCIF_U8         (0x80U) /**< @brief Command Complete Interrupt Flag */
#define EEPROM_FSTAT_RDCOLERR_U8     (0x40U) /**< @brief FTFE Read Collision Error Flag */
#define EEPROM_FSTAT_ACCERR_U8       (0x20U) /**< @brief Eeprom Access Error Flag */
#define EEPROM_FSTAT_FPVIOL_U8       (0x10U) /**< @brief Eeprom Protection Violation Flag */
#define EEPROM_FSTAT_MGSTAT0_U8      (0x01U) /**< @brief Memory Controller Command Completion Status Flag */

/* FSTAT masks for W1C operations */
#define EEPROM_FSTAT_CCIF_W1C        (EEPROM_FSTAT_CCIF_U8)        
#define EEPROM_FSTAT_RDCOLERR_W1C    (EEPROM_FSTAT_RDCOLERR_U8)
#define EEPROM_FSTAT_ACCERR_W1C      (EEPROM_FSTAT_ACCERR_U8)      
#define EEPROM_FSTAT_FPVIOL_W1C      (EEPROM_FSTAT_FPVIOL_U8)     
#define EEPROM_FSTAT_CCIF_SHIFT_U8   (0x7U) 
/**
 * @brief Eeprom Configuration Register (FTFE_FCNFG)
 */
#define EEPROM_FCNFG_CCIE_U8         (0x80U) /**< @brief Command Complete Interrupt Enable */
#define EEPROM_FCNFG_ERSSUSP_U8     (0x10U) /**< @brief Erase Suspend */
#define EEPROM_FCNFG_RAMRDY_U8       (0x02U) /**< @brief RAM Ready */
#define EEPROM_FCNFG_EEERDY_U8       (0x01U) /**< @brief EEE Ready */
#define EEPROM_FCNFG_RAMRDY_SHIFT_U8 (0x01U) 
/**
 * @brief Eeprom Status Register (FTFE_FERSTAT)
 */
#define EEPROM_FERSTAT_DFDIF_U8      (0x02U) /**< @brief Double Bit Fault Detect Interrupt Flag*/

/* FERSTAT mask for  W1C operations */
#define EEPROM_FERSTAT_DFDIF_W1C     (EEPROM_FERSTAT_DFDIF_U8)

/**
 * @brief Eeprom Error Configuration Register (FTFE_FERCNFG)
 */
#define EEPROM_FERCNFG_DFDIE_U8      (0x02) /**< @brief Double Bit Fault Detect Interrupt Enable*/

/**
 * @brief Program Eeprom Protection Registers (FTFE_FPROTn)
 */
#define EEPROM_FPROT0_P00            (0x01U)    /**< @brief Protection region 0 */
#define EEPROM_FPROT0_P01            (0x02U)    /**< @brief Protection region 1 */
#define EEPROM_FPROT0_P02            (0x04U)    /**< @brief Protection region 2 */
#define EEPROM_FPROT0_P03            (0x08U)    /**< @brief Protection region 3 */
#define EEPROM_FPROT0_P04            (0x10U)    /**< @brief Protection region 4 */
#define EEPROM_FPROT0_P05            (0x20U)    /**< @brief Protection region 5 */
#define EEPROM_FPROT0_P06            (0x40U)    /**< @brief Protection region 6 */
#define EEPROM_FPROT0_P07            (0x80U)    /**< @brief Protection region 7 */

#define EEPROM_FPROT1_P08            (0x01U)    /**< @brief Protection region 8 */
#define EEPROM_FPROT1_P09            (0x02U)    /**< @brief Protection region 9 */
#define EEPROM_FPROT1_P10            (0x04U)    /**< @brief Protection region 10 */
#define EEPROM_FPROT1_P11            (0x08U)    /**< @brief Protection region 11 */
#define EEPROM_FPROT1_P12            (0x10U)    /**< @brief Protection region 12 */
#define EEPROM_FPROT1_P13            (0x20U)    /**< @brief Protection region 13 */
#define EEPROM_FPROT1_P14            (0x40U)    /**< @brief Protection region 14 */
#define EEPROM_FPROT1_P15            (0x80U)    /**< @brief Protection region 15 */

#define EEPROM_FPROT2_P16            (0x01U)    /**< @brief Protection region 16 */
#define EEPROM_FPROT2_P17            (0x02U)    /**< @brief Protection region 17 */
#define EEPROM_FPROT2_P18            (0x04U)    /**< @brief Protection region 18 */
#define EEPROM_FPROT2_P19            (0x08U)    /**< @brief Protection region 19 */
#define EEPROM_FPROT2_P20            (0x10U)    /**< @brief Protection region 20 */
#define EEPROM_FPROT2_P21            (0x20U)    /**< @brief Protection region 21 */
#define EEPROM_FPROT2_P22            (0x40U)    /**< @brief Protection region 22 */
#define EEPROM_FPROT2_P23            (0x80U)    /**< @brief Protection region 23 */

#define EEPROM_FPROT3_P24            (0x01U)    /**< @brief Protection region 24 */
#define EEPROM_FPROT3_P25            (0x02U)    /**< @brief Protection region 25 */
#define EEPROM_FPROT3_P26            (0x04U)    /**< @brief Protection region 26 */
#define EEPROM_FPROT3_P27            (0x08U)    /**< @brief Protection region 27 */
#define EEPROM_FPROT3_P28            (0x10U)    /**< @brief Protection region 28 */
#define EEPROM_FPROT3_P29            (0x20U)    /**< @brief Protection region 29 */
#define EEPROM_FPROT3_P30            (0x40U)    /**< @brief Protection region 30 */
#define EEPROM_FPROT3_P31            (0x80U)    /**< @brief Protection region 31 */

/**
 * @brief Data Eeprom Protection Registers (FTFE_FDPROT)
 */
#define EEPROM_FDPROT_P00            (0x01U)    /**< @brief Protection region 0 */
#define EEPROM_FDPROT_P01            (0x02U)    /**< @brief Protection region 1 */
#define EEPROM_FDPROT_P02            (0x04U)    /**< @brief Protection region 2 */
#define EEPROM_FDPROT_P03            (0x08U)    /**< @brief Protection region 3 */
#define EEPROM_FDPROT_P04            (0x10U)    /**< @brief Protection region 4 */
#define EEPROM_FDPROT_P05            (0x20U)    /**< @brief Protection region 5 */
#define EEPROM_FDPROT_P06            (0x40U)    /**< @brief Protection region 6 */
#define EEPROM_FDPROT_P07            (0x80U)    /**< @brief Protection region 7 */

/**
 * @brief Eeprom CSE Status Register (FTFE_FCSESTAT)
 */
#define EEPROM_FCSESTAT_BSY_U8          (0x0001U) /**< @brief Busy Flag */
#define EEPROM_FCSESTAT_SB_U8           (0x0002U) /**< @brief Secure Boot Flag */
#define EEPROM_FCSESTAT_BIN_U8          (0x0004U) /**< @brief Secure Boot Initialization Flag */
#define EEPROM_FCSESTAT_BFN_U8          (0x0008U) /**< @brief Secure Boot Finished Flag */
#define EEPROM_FCSESTAT_BOK_U8          (0x0010U) /**< @brief Secure Boot OK Flag */
#define EEPROM_FCSESTAT_RIN_U8          (0x0020U) /**< @brief Random Number Generator Initialized Flag */
#define EEPROM_FCSESTAT_EDB_U8          (0x0040U) /**< @brief External Debug Flag */
#define EEPROM_FCSESTAT_IDB_U8          (0x0080U) /**< @brief Internal Debug Flag */

/**
 * @brief FCCOB commands IDs
 */
#define EEPROM_CMD_READ1S_BLOCK                  (0x00U)
#define EEPROM_CMD_READ1S_SECTION                (0x01U)
#define EEPROM_CMD_PROGRAM_CHECK                 (0x02U)
#define EEPROM_CMD_PROGRAM_PHRASE                (0x07U)
#define EEPROM_CMD_ERASE_BLOCK                   (0x08U)
#define EEPROM_CMD_ERASE_SECTOR                  (0x09U)
#define EEPROM_CMD_PROGRAM_SECTION               (0x0BU)
#define EEPROM_CMD_READ1S_ALLBLOCKS              (0x40U)
#define EEPROM_CMD_READ_ONCE                     (0x41U)
#define EEPROM_CMD_PROGRAM_ONCE                  (0x43U)
#define EEPROM_CMD_ERASE_ALLBLOCKS               (0x44U)
#define EEPROM_CMD_VERIFY_BACKDOOR               (0x45U)
#define EEPROM_CMD_ERASE_ALLBLOCKS_UNSECURE      (0x49U)
#define EEPROM_CMD_PROGRAM_PARTITION             (0x80U)
#define EEPROM_CMD_SET_FLEXRAM                   (0x81U)

/* FlexNVM EEPROM Data Set Sizes (size in Bytes)- used for Program Partition Command */
#define EEPROM_FLEXNVM_EEPROM_0                  (0x0FU)         /* used for when the FlexNVM Partition Code is set for no EEPROM */
#define EEPROM_FLEXNVM_EEPROM_4096               (0x02U)


/* Eeprom configuration field address */
#define EEPROM_CONFIG_FIELD_ADDR_OFFSET          (0x000408UL)  /* First aligned address containing FPROT0-3 and FDPROT eeprom sector protection registers */


/* MSCM (Miscellaneous System Control Module) register offset - Eeprom Prefetch Buffers control */
#define EEPROM_MSCM_OCMDR0_ADDR32           ((uint32)(MSCM_BASEADDR + (uint32)0x400UL)) /* On-Chip Memory Descriptor Register (MSCM_OCMDR0) */
#define EEPROM_MSCM_OCMDR1_ADDR32           ((uint32)(MSCM_BASEADDR + (uint32)0x404UL)) /* On-Chip Memory Descriptor Register (MSCM_OCMDR1) */

/* OCMDRx bitfield macro */
#define EEPROM_MSCM_OCMDR0_OCMC1_U32         (0x20UL)    /* OCMEM Control Field 1, OCMDR0[5] controls prefetches for PFLASH */
#define EEPROM_MSCM_OCMDR1_OCMC1_U32         (0x20UL)    /* OCMEM Control Field 1, OCMDR1[5] controls prefetches for DFLASH */

/* SIM (System Integration Module) */
#define EEPROM_SIM_BASEADDR              ((uint32)0x40048000UL)
/* Eeprom Configuration Register 1 (FCFG1) address offset */
#define EEPROM_SIM_FCFG1_ADDR_OFFSET     ((uint32)0x4CUL)
/* Eeprom Configuration Register 1 (FCFG1) address */     
#define EEPROM_SIM_FCFG1_ADDR32          ((uint32)(EEPROM_SIM_BASEADDR + EEPROM_SIM_FCFG1_ADDR_OFFSET))
/* FlexNVM partition code (DEPART) bits mask */
#define EEPROM_SIM_FCFG1_DEPART_U32      ((uint32)0x0000F000UL)
/* FlexNVM partition code (DEPART) bits shift value */
#define EEPROM_SIM_FCFG1_DEPART_SHIFT      (12U)
/* FlexNVM partition code (EERAMSIZE) bits mask */
#define EEPROM_SIM_FCFG1_EERAM_U32         ((uint32)0x000F0000UL)
/* FlexNVM partition code (EERAMSIZE) bits shift value */
#define EEPROM_SIM_FCFG1_EERAM_SHIFT       (16U)

#define EEPROM_ONE_BYTE_SHIFT_U8            (0x8U)

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_FTFC_H*/

/** @} */
