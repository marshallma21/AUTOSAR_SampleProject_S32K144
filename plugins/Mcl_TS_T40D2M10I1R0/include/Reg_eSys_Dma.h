/**
*   @file    Reg_eSys_Dma.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - eDMA Registers and Macros Definitions.
*   @details eDMA Registers and Macros Definitions.
*
*   @addtogroup DMA_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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

/**
@file        Reg_eSys_Dma.h
*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_DMA_REF_1 
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
*/


#ifndef REG_ESYS_DMA_H
#define REG_ESYS_DMA_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Reg_eSys_DMA_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Reg_eSys.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Dma.h
* @requirements   
*/
#define DMA_VENDOR_ID_REG                       43
#define DMA_AR_RELEASE_MAJOR_VERSION_REG        4
#define DMA_AR_RELEASE_MINOR_VERSION_REG        2
#define DMA_AR_RELEASE_REVISION_VERSION_REG     2
#define DMA_SW_MAJOR_VERSION_REG                1
#define DMA_SW_MINOR_VERSION_REG                0
#define DMA_SW_PATCH_VERSION_REG                1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != DMA_AR_RELEASE_MAJOR_VERSION_REG) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != DMA_AR_RELEASE_MINOR_VERSION_REG))
        #error "AutoSar Version Numbers of Reg_eSys.h and Reg_eSys_Dma.h are different"
    #endif
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS                                                  
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* for backward compatibility:
      - if DMA_NB_CONTOLERS not defined by Reg_eSys.h is supposed that only one controller exist 
      - if MCL_DMA_NB_CHANNELS not defined by Reg_eSys.h is supposed that DMA support only 16 channels*/

#ifndef MCL_DMA_NB_CONTROLLERS 
    #define MCL_DMA_NB_CONTROLLERS           (0x01U)
#endif

#ifndef MCL_DMA_NB_CHANNELS 
    #define MCL_DMA_NB_CHANNELS              (0x10UL)
#endif

/**
* @brief Mask used to limit channels to max channels available in one DMA instance
         
*/
#define DMA_CTRL_MAX_CHANNELS_MASK_U8       ((uint8)(MCL_DMA_NB_CHANNELS - 1U))

/**
* @brief Define for checking the module corresponding to a channel
*/
#define DMA_CHANNELS_PER_MODULE_U8          ((uint8)(MCL_DMA_NB_CHANNELS))

/**
* @brief Mask used to limit minor loop offset to max offset value.
*/
#define DMA_TCD_MAX_MLOFF_MASK_U32          ((uint32)(0xFFFFFUL))

/**
* @brief Mask used to limit link channel value to max possible value.
*/
#define DMA_TCD_MAX_LINKCH_MASK_U32       ((uint32)(MCL_DMA_NB_CHANNELS - 1U))

/**
* @brief Mask used to limit iterator value to max possible value.
*/
#define DMA_TCD_MAX_ITER_MASK_U32           ((uint32)(0x1FFUL))

/**
* @brief Mask used to limit minor loop bytes to transfer to max number of bytes.
*/
#define DMA_TCD_MAX_MLOFF_NBYTES_MASK_U16    ((uint16)(0x3FFUL))

/**
* @brief Mask used to limit the address modulo to max possible value.
*/
#define DMA_TCD_MAX_MOD_MASK_U16            ((uint16)(0x1FUL))

/**
* @brief Mask used to limit the transfer size to max possible value.
*/
#define DMA_TCD_MAX_SIZE_MASK_U16           ((uint16)(0x7UL))

/**
* @brief Mask used to limit the NBYTES to max possible value.
*/
#define DMA_TCD_MAX_NBYTES_MASK_U32        ((uint32)(0x3FFFFFFFUL))

/**
* @brief Mask used to select the priority from DCHPRI value
*/
#define DMA_CH_PRI_MASK_U8                  ((uint8)(0x4UL))

/**
* @brief Mask used to select SMOD and SSIZE transfer attributes
*/
#define DMA_TCD_SMOD_SSIZE_MASK_U16         ((uint16)(0xFF00UL))

/**
* @brief Mask used to select DMOD and DSIZE transfer attributes
*/
#define DMA_TCD_DMOD_DSIZE_MASK_U16         ((uint16)(0xFFUL))

/**
* @brief Used to decide priority registers address based on endianess
*/
#define DMA_BYTES_IN_WORD_U32                   (0x4UL)

/**
* @brief Number of groups within a DMA instance
*/
#define DMA_GROUPS                           (0x4U)

/**
* @brief Comply to naming for all platforms
*/
#ifdef DMA_BASEADDR
    #ifndef DMA0_BASEADDR
        #define DMA0_BASEADDR (DMA_BASEADDR)
    #endif
#endif
#if (MCL_DMA_NB_CONTROLLERS == 0x02U)
    /** 
    * @brief Macro to get the DMA Module address by module index.
    * @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
    */
    #define DMA_MOD_BASE_ADDR32(mIdx) \
        ((uint32)(((mIdx)>0UL) ? (DMA1_BASEADDR) : (DMA0_BASEADDR)))
#else
    /** 
    * @brief macro to get the DMA Module address by module index
    * @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
    */
    #define DMA_MOD_BASE_ADDR32(mIdx)         ((uint32)(DMA0_BASEADDR))
#endif
/** 
* @brief macro to get the DMA Module base address by channel
* @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define DMA_MOD_BASE_CH_ADDR32(channel) \
        ((uint32)(DMA_MOD_BASE_ADDR32(DMA_MOD_IDX_U8(channel))))
/** 
* @brief macro to get the DMA Module index by channel
* @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define DMA_MOD_IDX_U8(channel) \
    ((uint8)((((channel) & (~((uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))>0U)? (1U) : (0U)))
      
/** 
* @{
* @brief Macros used to get the DMA registers address by DMA index 
*/
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_CR_ADDR32(mIdx)        ((uint32)( DMA_MOD_BASE_ADDR32((mIdx))))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_ES_ADDR32(mIdx)        ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000004UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_ERQH_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000008UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_ERQL_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000000CUL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_EEIH_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000010UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_EEIL_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000014UL ))

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)  
    /** 
    * @{
    * @brief Macros used to get the DMA registers address by DMA index 
    */
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */                  
    #define DMA_SERQ_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001BUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CERQ_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001AUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_SEEI_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000019UL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CEEI_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000018UL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CINT_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001FUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CERR_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001EUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_SSRT_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001DUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CDNE_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001CUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    /** @} */
#else
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */                           
    #define DMA_SERQ_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000018UL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CERQ_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000019UL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_SEEI_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001AUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CEEI_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001BUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CINT_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001CUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CERR_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001DUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_SSRT_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001EUL ))
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CDNE_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000001FUL ))
#endif

/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_INTH_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000020UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_INTL_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000024UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_EERH_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000028UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_EERL_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x0000002CUL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_HRSH_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000030UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_HRSL_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000034UL ))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define DMA_GPOR_ADDR32(mIdx)      ((uint32)( DMA_MOD_BASE_ADDR32((mIdx)) + 0x00000038UL ))

/* default value for the DMA_CR register */
#define DMA_CR_DEFAULT_VAL_U32               ((uint32) (0x0000E400UL))
#define DMA_TCD_6TH_DEFAULT_VAL_U32          ((uint32) (0x00000000UL))
#define DMA_TCD_8TH_DEFAULT_VAL_U32          ((uint32) (0x00000000UL))
/** @brief Mask for SMOD_SSIZE in a 32-bit word */
#define DMA_TCD_SMOD_SSIZE_MASK_U32         ((uint32)(0xFF000000UL))
/** @brief Mask for SOFF in a 32-bit word */
#define DMA_TCD_TA_SOFF_MASK_U32            ((uint32)(0x0000FFFFUL))
/** @brief Mask for DOFF in a 32-bit word */
#define DMA_TCD_DOFF_MASK_U32               ((uint32)(0x0000FFFFUL))
/** @brief Mask for CITER in a 32-bit word */
#define DMA_TCD_CITER_MASK_U32              ((uint32)(0xFFFF0000UL))
/** @brief Mask for CITER ELINK YES in a 32-bit word */
#define DMA_TCD_CITER_ELINK_YES_MASK_U32              ((uint32)(0x01FF0000UL))
/** @brief Mask for CITER ELINK NO in a 32-bit word */
#define DMA_TCD_CITER_ELINK_NO_MASK_U32              ((uint32)(0x7FFF0000UL))
/** @brief Mask for DMOD_DSIZE in a 32-bit word */
#define DMA_TCD_DMOD_DSIZE_MASK_U32         ((uint32)(0x00FF0000UL))
/** @brief Mask for BITER in a 32-bit word */
#define DMA_TCD_BITER_MASK_U32              ((uint32)(0xFFFF0000UL))
/** @brief Mask for BITER in a 16-bit word */
#define DMA_TCD_BITER_ELINK_YES_MASK_U16              ((uint32)(0x01FFUL))
/** @brief Mask for BITER in a 16-bit word */
#define DMA_TCD_BITER_ELINK_NO_MASK_U16              ((uint32)(0x7FFFUL))
/** @brief Mask for FLAGS in a 32-bit word */
#define DMA_TCD_FLAGS_MASK_U32              ((uint32)(0x000000FFUL))
/** @brief Mask for MAJORLINCH in a 32-bit word */
#define DMA_TCD_MAJORLINCH_MASK_U32         ((uint32)(0x00003F00))
/** @brief Mask for MAJOR_E_LINK in a 32-bit word */
#define DMA_TCD_MAJOR_E_LINK_MASK_U32       ((uint32)(0x00000020UL))
/** @brief Mask for E_SG in a 32-bit word */
#define DMA_TCD_E_SG_MASK_U32               ((uint32)(0x00000010UL))

/**
* @brief Control register address offset 
*/
#define DMA_CR_OFFSET_U32         ((uint32) (0x0000UL))

/**
* @brief Task control block address offset 
*/
#define DMA_TCD_OFFSET_U32        ((uint32) (0x1000UL))
/**
* @brief Channel priority block address offset 
*/
#define DMA_CPT_OFFSET_U32        ((uint32) (0x0100UL))

/**
* @brief Channel priority block address offset 
*/
#define DMA_CDNE_OFFSET_U32        ((uint32) (0x0000001FUL))

/**
* @brief Channel master ID replication address offset 
*/
#define DMA_DCHMID_OFFSET_U32     ((uint32) (0x0140UL))
/**
* @brief Enable Asynchronous Request address offset 
*/
#define DMA_EARS_OFFSET_U32       ((uint32) (0x44UL))


/** @brief Offset in words for DLAST_SGA in TCD */
#define DMA_TCD_DLAST_SGA_WORD_OFFSET_U32   ((uint32) 0x06UL)

/**
* @brief Offset to destination address field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_DADDR_WORD_OFFSET_U32        ((uint32) 0x04UL)

/**
* @brief Offset to destination address offset field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_DOFF_WORD_OFFSET_U32    ((uint32) 0x05UL)

/** @brief Offset of CITER in a 32-bit word */
#define DMA_TCD_CITER_OFFSET_IN_WORD_U32        ((uint32) 0x10UL)

/** @brief Offset of SMOD_SSIZE in a 32-bit word */
#define DMA_TCD_SMOD_SSIZE_OFFSET_IN_WORD_U32            ((uint32)(0x18UL))

/** @brief Offset of DMOD_DSIZE in a 32-bit word */
#define DMA_TCD_DMOD_DSIZE_OFFSET_IN_WORD_U32       ((uint32)(0x10UL))

/** @brief Offset in words for CITER in TCD */
#define DMA_TCD_CITER_WORD_OFFSET_U32      ((uint32) 0x14UL)

/** @brief Offset in words for BITER in TCD */
#define DMA_TCD_BITER_CCS_WORD_OFFSET_U32  ((uint32) 0x07UL)

/** @brief Offset of MAJORLINCH in a 32-bit word */
#define DMA_TCD_MAJORLINKCH_OFFSET_IN_WORD_U32      ((uint32) 0x8UL)

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /** @brief Offset to tcd_csr from the 8th word */
    #define DMA_TCD_CSR_OFFSET_U32               ((uint32) 0x1UL)
    /** @brief Offset to biter from the 8th word */
    #define DMA_TCD_BITER_OFFSET_U32             ((uint32) 0x2UL)
    /** @brief Offset to citer from the 6th word */
    #define DMA_TCD_CITER_OFFSET_U32             ((uint32) 0x2UL)
#else
    /** @brief Offset to tcd_csr from the 8th word */
    #define DMA_TCD_CSR_OFFSET_U32               ((uint32) 0x2UL)
    /** @brief Offset to biter from the 8th word */
    #define DMA_TCD_BITER_OFFSET_U32             ((uint32) 0x0UL)
    /** @brief Offset to citer from the 6th word */
    #define DMA_TCD_CITER_OFFSET_U32             ((uint32) 0x0UL)
#endif

/**
* @brief Offset to Source address in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_1ST_WORD_OFFSET_U32         ((uint32) 0x00UL)
/**
* @brief Offset to smod, ssize, dmod, dsize, soff fields in TCD-Transfer Control Descriptor structure.
*/
#define DMA_TCD_2ND_WORD_OFFSET_U32         ((uint32) 0x04UL)
/**
* @brief Offset to smloe, dmloe, mloff, nbytes fields in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_3RD_WORD_OFFSET_U32         ((uint32) 0x08UL)
/**
* @brief Offset to slast field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_4TH_WORD_OFFSET_U32         ((uint32) 0x0CUL)
/**
* @brief Offset to destination address field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_5TH_WORD_OFFSET_U32         ((uint32) 0x10UL)
/**
* @brief Offset to citer, doff fields in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_6TH_WORD_OFFSET_U32         ((uint32) 0x14UL)
/**
* @brief Offset to dlast_sga field in TCD - Transfer Control Descriptor structure.
*/
#define DMA_TCD_7TH_WORD_OFFSET_U32         ((uint32) 0x18UL)
/**
* @brief Offset to biter, channle control/status fields in TCD - Transfer Control Descriptor structure
*/
#define DMA_TCD_8TH_WORD_OFFSET_U32         ((uint32) 0x1CUL)


/** @brief offset used in Tcd configuration functions to get each word's address */
#define DMA_TCD_1ST_WORD_ARRAY_OFFSET        (0UL)
#define DMA_TCD_2ND_WORD_ARRAY_OFFSET        (1UL)
#define DMA_TCD_3RD_WORD_ARRAY_OFFSET        (2UL)    
#define DMA_TCD_4TH_WORD_ARRAY_OFFSET        (3UL)
#define DMA_TCD_5TH_WORD_ARRAY_OFFSET        (4UL)
#define DMA_TCD_6TH_WORD_ARRAY_OFFSET        (5UL)
#define DMA_TCD_7TH_WORD_ARRAY_OFFSET        (6UL)
#define DMA_TCD_8TH_WORD_ARRAY_OFFSET        (7UL)


/** @brief ITER ELINK for setting ELINK in a TCD word */
#define DMA_TCD_ITER_ELINK_U32        (0x80000000UL)

/** @brief ITER ELINK for setting ELINK in CITER or BITER */
#define DMA_TCD_ITER_ELINK_U16    ((uint16)(0x8000L))

/** 
* @{
* @brief DMA CERR CAEI mask.
*/
#define DMA_CERR_CAEI_U8       ((uint8) 0x40UL)

/** 
* @{
* @brief DMA_DCHPRI register bit masks.
*/
#define DMA_DCHPRI_ECP_U8          ((uint8) 0x80UL)
#define DMA_DCHPRI_DPA_U8          ((uint8) 0x40UL)
/** @} */

/** 
* @{
* @brief DMA_ES register bit masks.
*/
#define DMA_ES_VLD_U32         ((uint32)0x80000000UL)
#define DMA_ES_UCE_U32         ((uint32)0x00020000UL)
#define DMA_ES_ECX_U32         ((uint32)0x00010000UL)
#define DMA_ES_GPE_U32         ((uint32)0x00008000UL)
#define DMA_ES_CPE_U32         ((uint32)0x00004000UL)

#if (MCL_DMA_NB_CHANNELS == 0x40U)
    #define DMA_ES_ERRCHN_U32      ((uint32)0x00003F00UL)
#else
    #define DMA_ES_ERRCHN_U32      ((uint32)0x00001F00UL)
#endif
#define DMA_ES_SAE_U32         ((uint32)0x00000080UL)
#define DMA_ES_SOE_U32         ((uint32)0x00000040UL)
#define DMA_ES_DAE_U32         ((uint32)0x00000020UL)
#define DMA_ES_DOE_U32         ((uint32)0x00000010UL)
#define DMA_ES_NCE_U32         ((uint32)0x00000008UL)
#define DMA_ES_SGE_U32         ((uint32)0x00000004UL)
#define DMA_ES_SBE_U32         ((uint32)0x00000002UL)
#define DMA_ES_DBE_U32         ((uint32)0x00000001UL)
#define DMA_ES_BUS_U32         ((uint32)0x00000003UL)
#define DMA_ES_DESCRIPTOR_U32  ((uint32)0x000000FCUL)
/** @} */
/** 
* @{
* @brief DMA_ES register shift value.
*/
#define DMA_ES_ERRCHN_SHIFT_RIGTH_U8      ((uint8)8U)
/** @} */

/** 
* @{
* shift value used for GRPPRI bits from DMA_DCHPRI register
*/
#define DMA_DCHPRI_GRPPRI_SHIFT_LEFT_U8      ((uint8)4U)

/** 
* @{
* @brief masks used to set the DMA_CR fields.
*/
#define DMA_CR_EBW_U32      ((uint32)0x00000001UL) 
#define DMA_CR_EDBG_U32     ((uint32)0x00000002UL)  
#define DMA_CR_ERCA_U32     ((uint32)0x00000004UL) 
#define DMA_CR_ERGA_U32     ((uint32)0x00000008UL) 
#define DMA_CR_HOE_U32      ((uint32)0x00000010UL) 
#define DMA_CR_HALT_U32     ((uint32)0x00000020UL)
#define DMA_CR_CLM_U32      ((uint32)0x00000040UL)  
#define DMA_CR_EMLM_U32     ((uint32)0x00000080UL) 
#define DMA_GRP0PRI_0_U32   ((uint32)0x00000000UL)
#define DMA_GRP0PRI_1_U32   ((uint32)0x00000100UL)
#define DMA_GRP0PRI_2_U32   ((uint32)0x00000200UL)
#define DMA_GRP0PRI_3_U32   ((uint32)0x00000300UL)
#define DMA_GRP1PRI_0_U32   ((uint32)0x00000000UL)
#define DMA_GRP1PRI_1_U32   ((uint32)0x00000400UL)
#define DMA_GRP1PRI_2_U32   ((uint32)0x00000800UL)
#define DMA_GRP1PRI_3_U32   ((uint32)0x00000C00UL)
#define DMA_CR_ECX_U32      ((uint32)0x00010000UL)
#define DMA_CR_CX_U32       ((uint32)0x00020000UL)
/** @} */

/** 
* @{
* @brief Low Level Macros used to access DMA registers for read/write operations.
*/
#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
    #define DMA_CPR(channel) \
        ((uint32)(DMA_MOD_BASE_CH_ADDR32((channel)) + DMA_CPT_OFFSET_U32 + \
        (LITTLE_ENDIAN_FORMULA((channel) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8))))
#else
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */   
    #define DMA_CPR(channel) \
        ((uint32)(DMA_MOD_BASE_CH_ADDR32((channel)) + DMA_CPT_OFFSET_U32 + \
        ((channel) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))
#endif

#ifdef MCL_DMA_ENABLE_INIT_DCHMID
#if (MCL_DMA_ENABLE_INIT_DCHMID == STD_ON)  
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */        
    #define DMA_DCHMID(channel) \
        ((uint32)(DMA_MOD_BASE_CH_ADDR32((channel)) + DMA_DCHMID_OFFSET_U32 + \
        (((channel)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))    
#endif  
#endif

#ifdef MCL_DMA_SETUP_EARS
#if (MCL_DMA_SETUP_EARS == STD_ON)  
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */        
    #define DMA_EARS(channel) \
        ((uint32)(DMA_MOD_BASE_CH_ADDR32((channel)) + DMA_EARS_OFFSET_U32))  
#endif  
#endif
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */        
#define DMA_TCD(channel) \
    ((uint32)(DMA_MOD_BASE_CH_ADDR32((channel)) + DMA_TCD_OFFSET_U32 + \
    (((channel) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)<<5)))
/** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */    
#define DMA_TCD_CHANNEL(channel, offset) ((uint32)(DMA_TCD((channel)) + (offset)))
 

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER) 
    /** @violates @ref Reg_eSys_DMA_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */ 
    #define LITTLE_ENDIAN_FORMULA(byte) ((uint32)((uint32)(((uint32)(DMA_BYTES_IN_WORD_U32 * \
        ((uint32)((byte) / DMA_BYTES_IN_WORD_U32)))) + DMA_BYTES_IN_WORD_U32) -((uint32)((byte) % DMA_BYTES_IN_WORD_U32) + 1)))
#endif
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif


#endif /* REG_ESYS_DMA_H */

/** @} */
