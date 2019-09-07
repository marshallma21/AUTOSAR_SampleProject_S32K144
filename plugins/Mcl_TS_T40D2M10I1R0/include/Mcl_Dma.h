/**
*   @file    Mcl_Dma.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - eDMA low level header.
*   @details Low level header for eDMA module.
*
*   @addtogroup MCL_DMA_DRIVER
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


#ifndef MCL_DMA_H
#define MCL_DMA_H


/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Mcl_Dma_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice.
*          All header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_Dma_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
* @section Mcl_Dma_h_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler linker shall be
*          checked to ensure that 31 character significance and case sensitivity
*          are supported for external indentifer
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcl_Dma_Types.h"
#include "Reg_eSys_Dma.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_DMA_VENDOR_ID                    43

#define MCL_DMA_AR_RELEASE_MAJOR_VERSION     4
#define MCL_DMA_AR_RELEASE_MINOR_VERSION     2
#define MCL_DMA_AR_RELEASE_REVISION_VERSION  2
#define MCL_DMA_SW_MAJOR_VERSION             1
#define MCL_DMA_SW_MINOR_VERSION             0
#define MCL_DMA_SW_PATCH_VERSION             1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/                                                                              
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same Autosar version */
    #if ((MCL_DMA_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMA_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Dma.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and CDD_Mcl_Cfg.h header file are of the same vendor */
#if (MCL_DMA_VENDOR_ID != MCL_DMA_TYPES_VENDOR_ID)
    #error "Mcl_Dma.h and Mcl_Dma_Types.h have different vendor ids"
#endif
/* Check if header file and CDD_Mcl_Cfg.h header file are of the same Autosar version */
#if ((MCL_DMA_AR_RELEASE_MAJOR_VERSION    != MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMA_AR_RELEASE_MINOR_VERSION    != MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMA_AR_RELEASE_REVISION_VERSION != MCL_DMA_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Dma.h and Mcl_Dma_Types.h are different"
#endif
/* Check if header file and CDD_Mcl_Cfg.h header file are of the same software version */
#if ((MCL_DMA_SW_MAJOR_VERSION != MCL_DMA_TYPES_SW_MAJOR_VERSION) || \
     (MCL_DMA_SW_MINOR_VERSION != MCL_DMA_TYPES_SW_MINOR_VERSION) || \
     (MCL_DMA_SW_PATCH_VERSION != MCL_DMA_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Dma.h and Mcl_Dma_Types.h are different"
#endif

/* Check if header file and Reg_eSys_Dma.h header file are of the same vendor */
#if (MCL_DMA_VENDOR_ID != DMA_VENDOR_ID_REG)
    #error "Mcl_Dma.h and Reg_eSys_Dma.h have different vendor ids"
#endif
/* Check if header file and Reg_eSys_Dma.h header file are of the same Autosar version */
#if ((MCL_DMA_AR_RELEASE_MAJOR_VERSION    != DMA_AR_RELEASE_MAJOR_VERSION_REG) || \
     (MCL_DMA_AR_RELEASE_MINOR_VERSION    != DMA_AR_RELEASE_MINOR_VERSION_REG) || \
     (MCL_DMA_AR_RELEASE_REVISION_VERSION != DMA_AR_RELEASE_REVISION_VERSION_REG))
    #error "AutoSar Version Numbers of Mcl_Dma.h and Reg_eSys_Dma.h are different"
#endif
/* Check if header file and Reg_eSys_Dma.h header file are of the same software version */
#if ((MCL_DMA_SW_MAJOR_VERSION != DMA_SW_MAJOR_VERSION_REG) || \
     (MCL_DMA_SW_MINOR_VERSION != DMA_SW_MINOR_VERSION_REG) || \
     (MCL_DMA_SW_PATCH_VERSION != DMA_SW_PATCH_VERSION_REG))
    #error "Software Version Numbers of Mcl_Dma.h and Reg_eSys_Dma.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

/**
* @brief enable DMA request for this channel
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_ENABLE_REQUEST(CHANNEL) \
    (REG_WRITE8(DMA_SERQ_ADDR32(DMA_MOD_IDX_U8(CHANNEL)), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))

/**
* @brief disable DMA request for this channel
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_DISABLE_REQUEST(CHANNEL) \
    (REG_WRITE8(DMA_CERQ_ADDR32(DMA_MOD_IDX_U8((CHANNEL))), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))
    
/**
* @brief enable DMA error interrupt for this channel
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_ENABLE_ERROR_INT(CHANNEL) \
    (REG_WRITE8(DMA_SEEI_ADDR32(DMA_MOD_IDX_U8((CHANNEL))), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))

/**
* @brief disable DMA error interrupt for this channel
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_DISABLE_ERROR_INT(CHANNEL) \
    (REG_WRITE8(DMA_CEEI_ADDR32(DMA_MOD_IDX_U8((CHANNEL))), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))
    
/**
* @brief disable DMA error interrupt for this channel
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLEAR_ERROR(CHANNEL) \
    (REG_WRITE8(DMA_CERR_ADDR32(DMA_MOD_IDX_U8((CHANNEL))), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))

/**
* @brief clear the interrupt request for a given channel
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLEAR_INT_REQ(CHANNEL) \
    (REG_WRITE8(DMA_CINT_ADDR32(DMA_MOD_IDX_U8((CHANNEL))), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))
    
/**
* @brief macro used to set another priority for a channel than the default one
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_PRIORITY(CHANNEL, NEW_PRIORITY) \
    (REG_RMW8(DMA_CPR((CHANNEL)), DMA_PRIORITY_MASK_U8, ((NEW_PRIORITY))))

/**
* @brief set the DCHPRI[n].ECP bit 
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_ECP(CHANNEL) \
    (REG_BIT_SET8(DMA_CPR((CHANNEL)), DMA_DCHPRI_ECP_U8))
    
/**
* @brief clear the DCHPRI[n].ECP bit  
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_ECP(CHANNEL) \
    (REG_BIT_CLEAR8(DMA_CPR((CHANNEL)), DMA_DCHPRI_ECP_U8))    
    
/**
* @brief set the DCHPRI[n].DPA bit 
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_DPA(CHANNEL) \
    (REG_BIT_SET8(DMA_CPR((CHANNEL)), DMA_DCHPRI_DPA_U8))
    
/**
* @brief clear the DCHPRI[n].DPA bit  
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_DPA(CHANNEL) \
    (REG_BIT_CLEAR8(DMA_CPR((CHANNEL)), DMA_DCHPRI_DPA_U8))    
    
/* ============================================================================================================================= */
/** @brief macros used to update certain fields of a TCD */ 
/* ============================================================================================================================= */
/**
* @brief update source address for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_SADDR(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE32((TCD_ADDR) + DMA_TCD_1ST_WORD_OFFSET_U32, ((NEW_VALUE))))

/**
* @brief update source address for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_SADDR(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_SADDR(DMA_TCD((CHANNEL)), (NEW_VALUE)))
    
/**
* @brief Get source address for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_GET_SADDR(TCD_ADDR) \
    (REG_READ32((TCD_ADDR) + DMA_TCD_1ST_WORD_OFFSET_U32))

/**
* @brief update source modulo for a TCD 
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_SMOD(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_2ND_WORD_OFFSET_U32, DMA_SMOD_MASK_U32 << DMA_SMOD_SHIFT_MASK_U32, ((NEW_VALUE)) << DMA_SMOD_SHIFT_MASK_U32))
    
/**
* @brief update source modulo for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_SMOD(CHANNEL, NEW_VALUE)     (DMA_TCD_UPDATE_SMOD(DMA_TCD((CHANNEL)), (NEW_VALUE)))
    
/**
* @brief update source transfer size for a TCD
*/  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */ 
#define DMA_TCD_UPDATE_SSIZE(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_2ND_WORD_OFFSET_U32, DMA_SSIZE_MASK_U32 << DMA_SSIZE_SHIFT_MASK_U32, ((NEW_VALUE)) << DMA_SSIZE_SHIFT_MASK_U32))
    
/**
* @brief update source transfer size for a CHANNEL
*/  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */ 
#define DMA_UPDATE_SSIZE(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_SSIZE(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/**
* @brief update destination modulo for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_DMOD(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_2ND_WORD_OFFSET_U32, DMA_DMOD_MASK_U32 << DMA_DMOD_SHIFT_MASK_U32, ((NEW_VALUE)) << DMA_DMOD_SHIFT_MASK_U32))

/**
* @brief update destination modulo for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_DMOD(CHANNEL, NEW_VALUE)     (DMA_TCD_UPDATE_DMOD(DMA_TCD((CHANNEL)), (NEW_VALUE)))
    
/**
* @brief update destination transfer size for a TCD
*/   
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_DSIZE(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_2ND_WORD_OFFSET_U32, DMA_DSIZE_MASK_U32 << DMA_DSIZE_SHIFT_MASK_U32, ((NEW_VALUE)) << DMA_DSIZE_SHIFT_MASK_U32))

/**
* @brief update destination transfer size for a CHANNEL
*/   
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_DSIZE(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_DSIZE(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/**
* @brief update source offset for a TCD
*/  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_SOFF(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_2ND_WORD_OFFSET_U32, DMA_SOFF_MASK_U32, ((NEW_VALUE))))

/**
* @brief update source offset for a CHANNEL
*/  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_SOFF(CHANNEL, NEW_VALUE)     (DMA_TCD_UPDATE_SOFF(DMA_TCD((CHANNEL)), (NEW_VALUE)))
        
/**
* @brief update number of bytes to be transferred for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_NBYTES(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE32((TCD_ADDR) + DMA_TCD_3RD_WORD_OFFSET_U32, ((NEW_VALUE))))
 
/**
* @brief update number of bytes to be transferred for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_NBYTES(CHANNEL, NEW_VALUE)   (DMA_TCD_UPDATE_NBYTES(DMA_TCD((CHANNEL)), (NEW_VALUE)))
    
/**
* @brief update number of bytes to be transferred for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_MLOFFYES(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE32((TCD_ADDR) + DMA_TCD_3RD_WORD_OFFSET_U32, ((NEW_VALUE))))
    
/**
* @brief update last source address adjustment for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_SLAST(TCD_ADDR, NEW_VALUE) \
   (REG_WRITE32((TCD_ADDR) + DMA_TCD_4TH_WORD_OFFSET_U32, ((NEW_VALUE))))

/**
* @brief update last source address adjustment for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_SLAST(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_SLAST(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/**
* @brief update destination address for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_DADDR(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE32((TCD_ADDR) + DMA_TCD_5TH_WORD_OFFSET_U32, ((NEW_VALUE))))

/**
* @brief update destination address for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_DADDR(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_DADDR(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/**
* @brief Get destination address
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_GET_DADDR(TCD_ADDR) \
    (REG_READ32((TCD_ADDR) + DMA_TCD_5TH_WORD_OFFSET_U32))

/**
* @brief update destination offset for a TCD
*/  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_DOFF(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32, DMA_DOFF_MASK_U32, ((NEW_VALUE))))

/**
* @brief update destination offset for a CHANNEL
*/  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_DOFF(CHANNEL, NEW_VALUE)     (DMA_TCD_UPDATE_DOFF(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/**
* @brief update last destination address adjustment for a TCD
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_DLAST_SGA(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE32((TCD_ADDR) + DMA_TCD_7TH_WORD_OFFSET_U32, (NEW_VALUE)))

/**
* @brief update last destination address adjustment for a CHANNEL
*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_DLAST_SGA(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_DLAST_SGA(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/* ============================================================================================================================= */
/** @brief Macros for CITER field of TCD number 6 */  
/* ============================================================================================================================= */ 
/** @brief set the citer.e_link bit for a TCD*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_CITER_ELINK(CHANNEL) \
    (REG_BIT_SET32(DMA_TCD((CHANNEL)) + DMA_TCD_6TH_WORD_OFFSET_U32, DMA_TCD_ITER_ELINK_U32))

/** @brief clear the citer.e_link bit for a CHANNEL*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_CITER_ELINK(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_6TH_WORD_OFFSET_U32, DMA_TCD_ITER_ELINK_U32))  

/** @brief update TCD.citer_linkch*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_CITER_LINKCH(CHANNEL, LINKED_CHANNEL) \
      (REG_RMW32(DMA_TCD(((CHANNEL))) + DMA_TCD_6TH_WORD_OFFSET_U32, DMA_MAJOR_LINKCH_MASK_U32 << DMA_MAJOR_LINKCH_SHIFT_MASK_U32, (LINKED_CHANNEL) << DMA_ITER_LINKCH_SHIFT_MASK_U32))

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_TCD_UPDATE_CITER(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32, DMA_CITER_MASK_U32 << DMA_ITER_SHIFT_MASK_U32, (NEW_VALUE)))
    
/** @brief update current iteration count*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_UPDATE_CITER(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_CITER(DMA_TCD((CHANNEL)), (NEW_VALUE)))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */ 
/* This macro will set CITER for Tcd the elink bit in TCD number 6 with elink bit = 1*/ 
#define DMA_TCD_SET_CITER_ELINK_ON(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32, (DMA_CITER_MASK_ON_U32 << DMA_ITER_SHIFT_MASK_U32), ((NEW_VALUE)) << DMA_ITER_SHIFT_MASK_U32))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */ 
/* This macro will set CITER for Tcd the elink bit in TCD number 6 with elink bit = 0 */ 
#define DMA_TCD_SET_CITER_ELINK_OFF(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32, (DMA_CITER_MASK_OFF_U32 << DMA_ITER_SHIFT_MASK_U32), ((NEW_VALUE)) << DMA_ITER_SHIFT_MASK_U32))

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_GET_CH_CITER(CHANNEL) \
    (REG_READ16((uint32)(DMA_TCD((CHANNEL))) + DMA_TCD_6TH_WORD_OFFSET_U32 + DMA_TCD_CITER_OFFSET_U32))
#else  
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_GET_CH_CITER(CHANNEL) \
    (REG_READ32((uint32)(DMA_TCD((CHANNEL))) + DMA_TCD_6TH_WORD_OFFSET_U32 + DMA_TCD_CITER_OFFSET_U32) >> DMA_ITER_SHIFT_MASK_U32)
#endif   

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
/* This macro will return the elink bit in TCD number 6 */
#define DMA_TCD_GET_CITER_ELINK(TCD_ADDR) \
    (REG_BIT_GET16((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32 + DMA_TCD_CITER_OFFSET_U32, DMA_TCD_ITER_ELINK_U16))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
/* This macro will return the CITER field with elink_bit = 1 in TCD number 6 */
#define DMA_TCD_GET_CITER_ON(TCD_ADDR) \
    (REG_READ16((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32 + DMA_TCD_CITER_OFFSET_U32) & DMA_CITER_MASK_ON_U16)
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
/* This macro will return the CITER field with elink_bit = 0 in TCD number 6 */
#define DMA_TCD_GET_CITER_OFF(TCD_ADDR) \
    (REG_READ16((TCD_ADDR) + DMA_TCD_6TH_WORD_OFFSET_U32 + DMA_TCD_CITER_OFFSET_U32) & DMA_CITER_MASK_OFF_U16)

/* ============================================================================================================================= */
/** @brief Macros for BITER field of TCD number 8 */  
/* ============================================================================================================================= */ 

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_BITER(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE16((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32 + DMA_TCD_BITER_OFFSET_U32, (NEW_VALUE)))
#else 
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_UPDATE_BITER(TCD_ADDR, NEW_VALUE) \
    (REG_WRITE16((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32, (NEW_VALUE)))
#endif

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */    
#define DMA_UPDATE_BITER(CHANNEL, NEW_VALUE)    (DMA_TCD_UPDATE_BITER(DMA_TCD((CHANNEL)), (NEW_VALUE)))

/** @brief set the biter.e_link bit from a TCD */
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_BITER_ELINK(CHANNEL) \
    (REG_BIT_SET32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_ITER_ELINK_U32))

/** @brief clear the biter.e_link bit from a TCD */
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_BITER_ELINK(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_ITER_ELINK_U32))  
    
/** @brief update TCD.biter_linkch from a TCD */
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_BITER_LINKCH(CHANNEL, LINKED_CHANNEL) \
    (REG_RMW32(DMA_TCD(((CHANNEL))) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_MAJOR_LINKCH_MASK_U32 << DMA_MAJOR_LINKCH_SHIFT_MASK_U32, (LINKED_CHANNEL) << DMA_ITER_LINKCH_SHIFT_MASK_U32))

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */ 
#define DMA_TCD_SET_BITER_ELINK_ON(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32, (DMA_BITER_MASK_ON_U32 << DMA_ITER_SHIFT_MASK_U32), ((NEW_VALUE)) << DMA_ITER_SHIFT_MASK_U32))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */ 
#define DMA_TCD_SET_BITER_ELINK_OFF(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32, (DMA_BITER_MASK_OFF_U32 << DMA_ITER_SHIFT_MASK_U32), ((NEW_VALUE)) << DMA_ITER_SHIFT_MASK_U32))

#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)   
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_GET_CH_BITER(CHANNEL) \
    (REG_READ16((uint32)(DMA_TCD((CHANNEL))) + DMA_TCD_8TH_WORD_OFFSET_U32 + DMA_TCD_BITER_OFFSET_U32))
#else
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_GET_CH_BITER(CHANNEL) \
    (REG_READ32((uint32)(DMA_TCD((CHANNEL))) + DMA_TCD_8TH_WORD_OFFSET_U32 + DMA_TCD_BITER_OFFSET_U32) >> DMA_ITER_SHIFT_MASK_U32)
#endif

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */  
#define DMA_TCD_GET_BITER_ELINK(TCD_ADDR) \
    (REG_BIT_GET16((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32 + DMA_TCD_BITER_OFFSET_U32, DMA_TCD_ITER_ELINK_U16))

/* ============================================================================================================================= */
/** @brief Macros for CRS field of TCD number 8 */  
/* ============================================================================================================================= */ 
/** @brief update TCD.major_linkch*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_UPDATE_MAJOR_LINKCH(CHANNEL, NEW_VALUE) \
    (REG_RMW32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_MAJOR_LINKCH_MASK_U32<<DMA_MAJOR_LINKCH_SHIFT_MASK_U32, ((NEW_VALUE))<<DMA_MAJOR_LINKCH_SHIFT_MASK_U32))

/** @brief returns the value of DONE bit from word 7 of TCD*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_DONE(CHANNEL) \
    (REG_BIT_GET32(DMA_TCD_CHANNEL(((CHANNEL)), (uint32) DMA_TCD_8TH_WORD_OFFSET_U32), DMA_TCD_DONE_U32))

/** @brief returns the value of ACTIVE bit from word 7 of TCD*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_ACTIVE(CHANNEL) \
    (REG_BIT_GET32(DMA_TCD_CHANNEL(((CHANNEL)), (uint32) DMA_TCD_8TH_WORD_OFFSET_U32), DMA_TCD_ACTIVE_U32))
    
/** @brief clear DONE bit in TCD*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_DONE(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_DONE_U32))
    
/** @brief set the TCD.e_sg bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_E_SG(CHANNEL) \
    (REG_BIT_SET32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_E_SG_U32))
    
/** @brief clear the TCD.e_sg bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_E_SG(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_E_SG_U32))

/** @brief set the major.e_link bit from TCD*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_MAJOR_ELINK(CHANNEL) \
    (REG_BIT_SET32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_MAJOR_E_LINK_U32))
    
/** @brief clear the major.e_link bit from TCD*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_MAJOR_ELINK(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_MAJOR_E_LINK_U32))    

/** @brief set the TCD.int_maj bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_INT_MAJ(CHANNEL) \
    (REG_BIT_SET32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_INT_MAJOR_U32))
    
/** @brief set the TCD.int_maj bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_SET_INT_MAJ(TCD_ADDR) \
    (REG_BIT_SET32((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_INT_MAJOR_U32))
    
/** @brief set the TCD.int_half bit */
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_SET_INT_HALF(CHANNEL) \
    (REG_BIT_SET32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_INT_HALF_U32))
    
/** @brief clear the TCD.int_maj bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_INT_MAJ(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_INT_MAJOR_U32))

/** @brief clear the TCD.int_maj bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_TCD_CLR_INT_MAJ(TCD_ADDR) \
    (REG_BIT_CLEAR32((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_INT_MAJOR_U32))
    
/** @brief clear the TCD.int_half bit*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_CLR_INT_HALF(CHANNEL) \
    (REG_BIT_CLEAR32(DMA_TCD((CHANNEL)) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_INT_HALF_U32))

/** @brief start transfer*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_START(CHANNEL) \
    (REG_WRITE8(DMA_SSRT_ADDR32(DMA_MOD_IDX_U8((((CHANNEL))))), (uint8)(((CHANNEL)) & (uint32)DMA_CTRL_MAX_CHANNELS_MASK_U8)))

/** @brief stop the data transfer for the specified DMA module*/
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DMA_STOP(MODULE_ID) \
    (REG_BIT_SET32(DMA_MOD_BASE_ADDR32(MODULE_ID) + DMA_CR_OFFSET_U32, DMA_CR_CX_U32))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */       
#define DMA_TCD_SR(Channel) \
    (REG_READ32((uint32)DMA_TCD_CHANNEL(((Channel)), DMA_TCD_8TH_WORD_OFFSET_U32)))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */        
#define DMA_TCD_GET_INT_MAJ(channel) \
    ((boolean)(((uint32)DMA_TCD_INT_MAJOR_U32 == (uint32)(DMA_TCD_SR((channel)) & DMA_TCD_INT_MAJOR_U32))? TRUE : FALSE))
    
/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */        
#define DMA_TCD_GET_INT_HALF(channel) \
    ((boolean)(((uint32)DMA_TCD_INT_HALF_U32 == (uint32)(DMA_TCD_SR((channel)) & DMA_TCD_INT_HALF_U32))? TRUE : FALSE))        

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */ 
#define DMA_TCD_SET_FLAGS(TCD_ADDR, NEW_VALUE) \
    (REG_RMW32((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32, DMA_TCD_FLAGS_MASK_U32, (NEW_VALUE)))

/** @violates @ref Mcl_Dma_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */     
#define DMA_TCD_GET_FLAGS(TCD_ADDR) \
    (REG_READ32((TCD_ADDR) + DMA_TCD_8TH_WORD_OFFSET_U32) & DMA_TCD_FLAGS_MASK_U32)
 
/** @} */    
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_Dma_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

FUNC(void, MCL_CODE) Mcl_Dma_Init( CONSTP2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) pConfig, Mcl_DmaInstanceType dma_instance);

#if (MCL_DEINIT_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_Dma_DeInit( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) pConfig, Mcl_DmaInstanceType dma_instance);
#endif

FUNC(void, MCL_CODE) Mcl_Dma_ConfigChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                        P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor);
                                        
FUNC(void, MCL_CODE) Mcl_Dma_ConfigTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                    P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor);

FUNC(void, MCL_CODE) Mcl_Dma_ConfigLinkedChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                              P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                              VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel);
                                              
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                                     P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                     P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd); 

FUNC(void, MCL_CODE) Mcl_Dma_ConfigLinkedTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                          P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                          VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel);      

FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                 P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                 P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd); 
                                                 
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherLinkedChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) dma_channel, 
                                                           P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                           P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                           VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel);     
/** @violates @ref Mcl_Dma_h_REF_3 MISRA 2004 Required Rule 1.4, The compiler linker shall be checked. */
FUNC(void, MCL_CODE) Mcl_Dma_ConfigScatterGatherLinkedTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                                       P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                       P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                       VAR(Mcl_DmaChannelType, AUTOMATIC) next_channel);                                                                    

FUNC(void, MCL_CODE) Mcl_Dma_SetChannelPriority( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel, 
                                             VAR(Mcl_DmaPriorityType, AUTOMATIC) nPriority);  

FUNC(void, MCL_CODE) Mcl_Dma_StartChannel( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel);    

FUNC(boolean, MCL_CODE) Mcl_Dma_IsTransferCompleted( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel);           

FUNC(boolean, MCL_CODE) Mcl_Dma_IsTransferActive( VAR(Mcl_DmaChannelType, AUTOMATIC) nChannel);      

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)        
FUNC (void, MCL_CODE) Mcl_Dma_EnableNotification(VAR(Mcl_DmaChannelType,AUTOMATIC) nChannel,
                                             VAR(Mcl_DmaTransferNotifType,AUTOMATIC) Notification);
                                             
FUNC (void, MCL_CODE) Mcl_Dma_DisableNotification(VAR(Mcl_DmaChannelType,AUTOMATIC) nChannel);                                             
#endif /* MCL_DMA_NOTIFICATION_SUPPORTED */        

FUNC (boolean, MCL_CODE) Mcl_Dma_GetMultiRegChInfo(VAR(Mcl_DmaChannelType,AUTOMATIC) nChannel, 
                                                 VAR(Mcl_DmaRequestType,AUTOMATIC) request);                
#if (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON)                                                 
FUNC (void, MCL_CODE) Mcl_Dma_GetGlobalErrorStatus
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) dmaInstance,
    P2VAR(Mcl_DmaGlobalErrorStatusType, AUTOMATIC, MCL_APPL_DATA) dmaGlobalErrorStatus
);
#endif

#if ((MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON) || (MCL_DMA_GET_CH_ERR_STATUS_API == STD_ON))                   
FUNC(Mcl_DmaChannelErrorStatusType, MCL_CODE) Mcl_Dma_GetChannelErrorStatus
(
    VAR(Mcl_DmaChannelType,AUTOMATIC) hwChannel
);    
#endif
                        
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_Dma_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* MCL_DMA_H */

/** @} */
