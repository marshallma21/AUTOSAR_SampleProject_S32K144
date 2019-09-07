/**
*   @file    Reg_eSys_LPUART.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - LPUART Registers and Macros Definitions.
*   @details Header file for LPUART Registers and Macros Definitions.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
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

#ifndef REG_ESYS_LPUART_H
#define REG_ESYS_LPUART_H

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
* @section Reg_eSys_LPUART_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, This violation is due to function
* like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_LPUART_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Reg_eSys_LPUART_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Reg_eSys_LPUART_h_REF_3 Precautions shall be taken in 
* order to prevent the contents of a header file being
* included twice.
*/
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_LPUART.h
*/
#define REG_ESYS_LPUART_VENDOR_ID                    43
#define REG_ESYS_LPUART_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_LPUART_AR_RELEASE_MINOR_VERSION     2
/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define REG_ESYS_LPUART_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_LPUART_SW_MAJOR_VERSION             1
#define REG_ESYS_LPUART_SW_MINOR_VERSION             0
#define REG_ESYS_LPUART_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_LPUART_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_LPUART_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_LPUART.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


#define LIN_START_SEC_CONST_32
/** 
* @violates @ref Reg_eSys_LPUART_h_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
/** 
* @violates @ref Reg_eSys_LPUART_h_REF_4 The size of the array is defined at configuration time
*/
extern CONST(uint32, LIN_CONST) LPUART_au32BaseAddrs[13];

#define LIN_STOP_SEC_CONST_32
/** 
* @violates @ref Reg_eSys_LPUART_h_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
/**
* @details  LPUART macro to access register LPUART Global Register (GLOBAL).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_GLOBAL_ADDR32(offset)    ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000008U))

/**
* @details  LPUART macro to access register LPUART Pin Configuration Register (PINCFG).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_PINCFG_ADDR32(offset)    ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x0000000CU))

/**
* @details  LPUART macro to access register LPUART Baud Rate Register (BAUD).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_BAUD_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000010U))

/**
* @details  LPUART macro to access register LPUART Status Register (STAT).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_STAT_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000014U))

/**
* @details  LPUART macro to access register LPUART Control Register (CTRL).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_CTRL_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000018U))

/**
* @details  LPUART macro to access register LPUART Data Register (DATA).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_DATA_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x0000001CU))

/**
* @details  LPUART macro to access register LPUART Match Address Register (MATCH).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_MATCH_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000020U))

/**
* @details  LPUART macro to access register LPUART Modem IrDA Register (MODIR).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_MODIR_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000024U))

/**
* @details  LPUART macro to access register LPUART FIFO Register (FIFO).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_FIFO_ADDR32(offset)       ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x00000028U))

/**
* @details  LPUART macro to access register LPUART Watermark Register (WATER).
* @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LPUART_WATER_ADDR32(offset)      ((uint32)(LPUART_au32BaseAddrs[(offset)] + (uint32)0x0000002CU))

/**
* @brief    LPUART Registers bits.
* @details  GLOBAL register bit masks.
*/
#define LPUART_GLOBAL_RST_MASK_U32            ((uint32)0x00000002U)

#define LPUART_GLOBAL_MDL_IS_RESET_U32      ((uint32)0x00000002U)
/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_GLOBAL_MDL_IS_NOT_RESET_U32  ((uint32)0x00000000U)

/**
* @brief    LPUART Registers bits.
* @details  PINCFG register bit masks.
*/
#define LPUART_PINCFG_TRGSEL_MASK_U32               ((uint32)0x00000003U)

#define LPUART_TRG_DISABLED_U32                   ((uint32)0x00000000U)
/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_TRG_USED_INSTEAD_OF_RXD_INPUT_U32  ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_TRG_USED_INSTEAD_OF_CTS_INPUT_U32  ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_TRG_USED_INSTEAD_OF_TXD_OUTPUT_U32 ((uint32)0x00000000U)

/**
* @brief    LPUART Registers bits.
* @details  BAUD register bit masks.
*/
#define LPUART_BAUD_MAEN1_MASK_U32               ((uint32)0x80000000U)
#define LPUART_BAUD_MAEN2_MASK_U32               ((uint32)0x40000000U)
#define LPUART_BAUD_M10_MASK_U32                 ((uint32)0x20000000U)
#define LPUART_BAUD_OSR_MASK_U32                 ((uint32)0x1F000000U)
#define LPUART_BAUD_OSR_SHIFT_U32                ((uint32)24U)
#define LPUART_BAUD_TDMAE_MASK_U32               ((uint32)0x00800000U)
#define LPUART_BAUD_RDMAE_MASK_U32               ((uint32)0x00200000U)
#define LPUART_BAUD_RIDMAE_MASK_U32              ((uint32)0x00100000U)
#define LPUART_BAUD_MATCFG_MASK_U32              ((uint32)0x000C0000U)
#define LPUART_BAUD_BOTHEDGE_MASK_U32            ((uint32)0x00020000U)
#define LPUART_BAUD_RESYNCDIS_MASK_U32           ((uint32)0x00010000U)
#define LPUART_BAUD_LBKDIE_MASK_U32              ((uint32)0x00008000U)
#define LPUART_BAUD_RXEDGIE_MASK_U32             ((uint32)0x00004000U)
#define LPUART_BAUD_SBNS_MASK_U32                ((uint32)0x00002000U)
#define LPUART_BAUD_SBR_MASK_U32                 ((uint32)0x00001FFFU)

#define LPUART_BAUD_USE_10_BITS_U32            (LPUART_BAUD_M10_MASK_U32)
#define LPUART_BAUD_USE_8_OR_9_BITS_U32        ((uint32)0x00000000U)

/** @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPUART_BAUD_OSR_U32(value)          ((uint32)((uint32)((value) << LPUART_BAUD_OSR_SHIFT_U32) & LPUART_BAUD_OSR_MASK_U32))
/* 16 bit Oversampling Ratio */
#define LPUART_BAUD_OSR_16_BITS_U32             ((uint32)15U)

#define LPUART_BAUD_TX_DMA_ENABLE_U32                   (LPUART_BAUD_TDMAE_MASK_U32)
#define LPUART_BAUD_TX_DMA_DISABLE_U32                  ((uint32)0x00000000U)

#define LPUART_BAUD_RX_DMA_ENABLE_U32                   (LPUART_BAUD_RDMAE_MASK_U32)
#define LPUART_BAUD_RX_DMA_DISABLE_U32                  ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_BOTH_EDGE_SAMPLING_ENABLE_U32            (LPUART_BAUD_BOTHEDGE_MASK_U32)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_BOTH_EDGE_SAMPLING_DISABLE_U32           ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_RESYNCHRONIZATION_DISABLE_U32            (LPUART_BAUD_RESYNCDIS_MASK_U32)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_RESYNCHRONIZATION_ENABLE_U32             ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_LIN_BREAK_DETECT_ISR_ENABLED_U32         (LPUART_BAUD_LBKDIE_MASK_U32)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_LIN_BREAK_DETECT_ISR_DISABLED_U32        ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_RX_INPUT_ACTIVE_EDGE_ISR_ENABLED_U32     (LPUART_BAUD_RXEDGIE_MASK_U32)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_RX_INPUT_ACTIVE_EDGE_ISR_DISABLED_U32    ((uint32)0x00000000U)

#define LPUART_BAUD_TWO_STOP_BITS_U32                   (LPUART_BAUD_SBNS_MASK_U32)
#define LPUART_BAUD_ONE_STOP_BIT_U32                    ((uint32)0x00000000U)

/** @violates @ref Reg_eSys_LPUART_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define LPUART_BAUD_SBR_U32(value)         (((value) & LPUART_BAUD_SBR_MASK_U32))

/**
* @brief    LPUART Registers bits.
* @details  STAT register bit masks.
*/
#define LPUART_STAT_LBKDIF_MASK_U32               ((uint32)0x80000000U)
#define LPUART_STAT_RXEDGIF_MASK_U32              ((uint32)0x40000000U)
#define LPUART_STAT_MSBF_MASK_U32                 ((uint32)0x20000000U)
#define LPUART_STAT_RXINV_MASK_U32                ((uint32)0x10000000U)
#define LPUART_STAT_RWUID_MASK_U32                ((uint32)0x08000000U)
#define LPUART_STAT_BRK13_MASK_U32                ((uint32)0x04000000U)
#define LPUART_STAT_LBKDE_MASK_U32                ((uint32)0x02000000U)
    
#define LPUART_STAT_RAF_MASK_U32                  ((uint32)0x01000000U)
#define LPUART_STAT_TDRE_MASK_U32                 ((uint32)0x00800000U)
#define LPUART_STAT_TC_MASK_U32                   ((uint32)0x00400000U)
#define LPUART_STAT_RDRF_MASK_U32                 ((uint32)0x00200000U)
    
#define LPUART_STAT_IDLE_MASK_U32                 ((uint32)0x00100000U)
#define LPUART_STAT_OR_MASK_U32                   ((uint32)0x00080000U)
#define LPUART_STAT_NF_MASK_U32                   ((uint32)0x00040000U)
#define LPUART_STAT_FE_MASK_U32                   ((uint32)0x00020000U)
#define LPUART_STAT_PF_MASK_U32                   ((uint32)0x00010000U)
    
#define LPUART_STAT_MA1F_MASK_U32                 ((uint32)0x00008000U)
#define LPUART_STAT_MA2F_MASK_U32                 ((uint32)0x00004000U)
#define LPUART_STAT_INT_FLAGS_MASK_U32            ((uint32)0xC0FFC000U)
#define LPUART_STAT_ERR_FLAGS_MASK_U32            ((uint32)0x000F0000U)
#define LPUART_STAT_W1C_FLAGS_MASK_U32            ((uint32)0xC01FC000U)

/**
* @brief    LPUART Registers bits.
* @details  CTRL register bit masks.
*/
#define LPUART_CTRL_R8T9_MASK_U32                 ((uint32)0x80000000U)
#define LPUART_CTRL_R9T8_MASK_U32                 ((uint32)0x40000000U)
#define LPUART_CTRL_TXDIR_MASK_U32                ((uint32)0x20000000U)
#define LPUART_CTRL_TXINV_MASK_U32                ((uint32)0x10000000U)
#define LPUART_CTRL_ORIE_MASK_U32                 ((uint32)0x08000000U)
#define LPUART_CTRL_NEIE_MASK_U32                 ((uint32)0x04000000U)
#define LPUART_CTRL_FEIE_MASK_U32                 ((uint32)0x02000000U)
#define LPUART_CTRL_ONFIE_MASK_U32                ((uint32)0x0E000000U)
#define LPUART_CTRL_PEIE_MASK_U32                 ((uint32)0x01000000U)
#define LPUART_CTRL_TIE_MASK_U32                  ((uint32)0x00800000U)
#define LPUART_CTRL_TCIE_MASK_U32                 ((uint32)0x00400000U)
#define LPUART_CTRL_RIE_MASK_U32                  ((uint32)0x00200000U)
#define LPUART_CTRL_ILIE_MASK_U32                 ((uint32)0x00100000U)
#define LPUART_CTRL_TE_MASK_U32                   ((uint32)0x00080000U)
#define LPUART_CTRL_RE_MASK_U32                   ((uint32)0x00040000U)
#define LPUART_CTRL_RWU_MASK_U32                  ((uint32)0x00020000U)
#define LPUART_CTRL_SBK_MASK_U32                  ((uint32)0x00010000U)
#define LPUART_CTRL_MA1IE_MASK_U32                ((uint32)0x00008000U)
#define LPUART_CTRL_MA2IE_MASK_U32                ((uint32)0x00004000U)
#define LPUART_CTRL_M7_MASK_U32                   ((uint32)0x00000800U)
#define LPUART_CTRL_IDLECFG_MASK_U32              ((uint32)0x00000700U)
#define LPUART_CTRL_LOOPS_MASK_U32                ((uint32)0x00000080U)
#define LPUART_CTRL_DOZEEN_MASK_U32               ((uint32)0x00000040U)
#define LPUART_CTRL_RSRC_MASK_U32                 ((uint32)0x00000020U)
#define LPUART_CTRL_M_MASK_U32                    ((uint32)0x00000010U)
#define LPUART_CTRL_WAKE_MASK_U32                 ((uint32)0x00000008U)
#define LPUART_CTRL_ILT_MASK_U32                  ((uint32)0x00000004U)
#define LPUART_CTRL_PE_MASK_U32                   ((uint32)0x00000002U)
#define LPUART_CTRL_PT_MASK_U32                   ((uint32)0x00000001U)
#define LPUART_CTRL_IE_FLAGS_MASK_U32             ((uint32)0x0FF0C000U)

#define LPUART_CTRL_ONFIE_ENABLE_U32              (LPUART_CTRL_ONFIE_MASK_U32)
#define LPUART_CTRL_ONFIE_DISABLE_U32             ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_CTRL_IDLECFG_1_IDLE_MASK_U32     ((uint32)0x00000000U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_CTRL_IDLECFG_2_IDLE_MASK_U32     ((uint32)0x00000100U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_CTRL_IDLECFG_4_IDLE_MASK_U32     ((uint32)0x00000200U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_CTRL_IDLECFG_8_IDLE_MASK_U32     ((uint32)0x00000300U)

/**
* @violates @ref Reg_eSys_LPUART_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LPUART_CTRL_IDLECFG_16_IDLE_MASK_U32    ((uint32)0x00000400U)

/**
* @brief    LPUART Registers bits.
* @details  DATA register bit masks.
*/
#define LPUART_DATA_NOISY_MASK_U32                ((uint32)0x00008000U)
#define LPUART_DATA_PARITYE_MASK_U32              ((uint32)0x00004000U)
#define LPUART_DATA_FRETSC_MASK_U32               ((uint32)0x00002000U)
#define LPUART_DATA_RXEMPT_MASK_U32               ((uint32)0x00001000U)
#define LPUART_DATA_IDLINE_MASK_U32               ((uint32)0x00000800U)

#define LPUART_DATA_8BITS_MASK_U32                ((uint32)0x000000FFU)

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

#endif /* REG_eSys_LPUART_H */

/** @} */
