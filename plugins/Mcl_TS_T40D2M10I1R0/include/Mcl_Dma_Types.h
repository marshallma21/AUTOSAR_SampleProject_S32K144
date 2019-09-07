/**
*   @file           Mcl_Dma_Types.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Mcl - Dma data types header file.
*   @details        Dma defines, types used by MCL driver.
*
*   @addtogroup     MCL_MODULE
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

#ifndef MCL_DMA_TYPES_H
#define MCL_DMA_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Std_Types.h"
#include "CDD_Mcl_Cfg.h"

#include "Soc_Ips.h"
/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Mcl_Dma_Types.h
* @requirements   
*/
#define MCL_DMA_TYPES_VENDOR_ID                        43
#define MCL_DMA_TYPES_MODULE_ID                        255
#define MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION         2
#define MCL_DMA_TYPES_AR_RELEASE_REVISION_VERSION      2
#define MCL_DMA_TYPES_SW_MAJOR_VERSION                 1
#define MCL_DMA_TYPES_SW_MINOR_VERSION                 0
#define MCL_DMA_TYPES_SW_PATCH_VERSION                 1
/** @} */
/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same Autosar version */
    #if ((MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Dma_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and CDD_Mcl_Cfg.h header file are of the same vendor */
#if (MCL_DMA_TYPES_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "Mcl_Dma_Types.h and CDD_Mcl_Cfg.h have different vendor ids"
#endif
/* Check if header file and CDD_Mcl_Cfg.h header file are of the same Autosar version */
#if ((MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_DMA_TYPES_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Mcl_Dma_Types.h and CDD_Mcl_Cfg.h are different"
#endif
/* Check if header file and CDD_Mcl_Cfg.h header file are of the same software version */
#if ((MCL_DMA_TYPES_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_DMA_TYPES_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_DMA_TYPES_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Mcl_Dma_Types.h and CDD_Mcl_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Soc_Ips.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Mcl_Dma_Types.h are different"
    #endif
#endif
/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/

#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)
/**
* @{
* @brief          defines used for Mcl_DmaInstanceType
*/
#define DMA_INSTANCE0        (0U)
#if (MCL_DMA_NB_CONTROLLERS == 0x02U)
#define DMA_INSTANCE1        (1U)
#endif

/**
* @{
* @brief          defines used for Mcl_DmaChannelType
*/
#define DMA_HW_CHANNEL_0       (0U)
#define DMA_HW_CHANNEL_1       (1U)
#define DMA_HW_CHANNEL_2       (2U)
#define DMA_HW_CHANNEL_3       (3U)
#define DMA_HW_CHANNEL_4       (4U)
#define DMA_HW_CHANNEL_5       (5U)
#define DMA_HW_CHANNEL_6       (6U)
#define DMA_HW_CHANNEL_7       (7U)
#define DMA_HW_CHANNEL_8       (8U)
#define DMA_HW_CHANNEL_9       (9U)
#define DMA_HW_CHANNEL_10      (10U)
#define DMA_HW_CHANNEL_11      (11U)
#define DMA_HW_CHANNEL_12      (12U)
#define DMA_HW_CHANNEL_13      (13U)
#define DMA_HW_CHANNEL_14      (14U)
#define DMA_HW_CHANNEL_15      (15U)
#define DMA_HW_CHANNEL_16      (16U)
#define DMA_HW_CHANNEL_17      (17U)
#define DMA_HW_CHANNEL_18      (18U)
#define DMA_HW_CHANNEL_19      (19U)
#define DMA_HW_CHANNEL_20      (20U)
#define DMA_HW_CHANNEL_21      (21U)
#define DMA_HW_CHANNEL_22      (22U)
#define DMA_HW_CHANNEL_23      (23U)
#define DMA_HW_CHANNEL_24      (24U)
#define DMA_HW_CHANNEL_25      (25U)
#define DMA_HW_CHANNEL_26      (26U)
#define DMA_HW_CHANNEL_27      (27U)
#define DMA_HW_CHANNEL_28      (28U)
#define DMA_HW_CHANNEL_29      (29U)
#define DMA_HW_CHANNEL_30      (30U)
#define DMA_HW_CHANNEL_31      (31U)
#define DMA_HW_CHANNEL_32      (32U)
#define DMA_HW_CHANNEL_33      (33U)
#define DMA_HW_CHANNEL_34      (34U)
#define DMA_HW_CHANNEL_35      (35U)
#define DMA_HW_CHANNEL_36      (36U)
#define DMA_HW_CHANNEL_37      (37U)
#define DMA_HW_CHANNEL_38      (38U)
#define DMA_HW_CHANNEL_39      (39U)
#define DMA_HW_CHANNEL_40      (40U)
#define DMA_HW_CHANNEL_41      (41U)
#define DMA_HW_CHANNEL_42      (42U)
#define DMA_HW_CHANNEL_43      (43U)
#define DMA_HW_CHANNEL_44      (44U)
#define DMA_HW_CHANNEL_45      (45U)
#define DMA_HW_CHANNEL_46      (46U)
#define DMA_HW_CHANNEL_47      (47U)
#define DMA_HW_CHANNEL_48      (48U)
#define DMA_HW_CHANNEL_49      (49U)
#define DMA_HW_CHANNEL_50      (50U)
#define DMA_HW_CHANNEL_51      (51U)
#define DMA_HW_CHANNEL_52      (52U)
#define DMA_HW_CHANNEL_53      (53U)
#define DMA_HW_CHANNEL_54      (54U)
#define DMA_HW_CHANNEL_55      (55U)
#define DMA_HW_CHANNEL_56      (56U)
#define DMA_HW_CHANNEL_57      (57U)
#define DMA_HW_CHANNEL_58      (58U)
#define DMA_HW_CHANNEL_59      (59U)
#define DMA_HW_CHANNEL_60      (60U)
#define DMA_HW_CHANNEL_61      (61U)
#define DMA_HW_CHANNEL_62      (62U)
#define DMA_HW_CHANNEL_63      (63U)
#define DMA_HW_CHANNEL_64      (64U)
#define DMA_HW_CHANNEL_65      (65U)
#define DMA_HW_CHANNEL_66      (66U)
#define DMA_HW_CHANNEL_67      (67U)
#define DMA_HW_CHANNEL_68      (68U)
#define DMA_HW_CHANNEL_69      (69U)
#define DMA_HW_CHANNEL_70      (70U)
#define DMA_HW_CHANNEL_71      (71U)
#define DMA_HW_CHANNEL_72      (72U)
#define DMA_HW_CHANNEL_73      (73U)
#define DMA_HW_CHANNEL_74      (74U)
#define DMA_HW_CHANNEL_75      (75U)
#define DMA_HW_CHANNEL_76      (76U)
#define DMA_HW_CHANNEL_77      (77U)
#define DMA_HW_CHANNEL_78      (78U)
#define DMA_HW_CHANNEL_79      (79U)
#define DMA_HW_CHANNEL_80      (80U)
#define DMA_HW_CHANNEL_81      (81U)
#define DMA_HW_CHANNEL_82      (82U)
#define DMA_HW_CHANNEL_83      (83U)
#define DMA_HW_CHANNEL_84      (84U)
#define DMA_HW_CHANNEL_85      (85U)
#define DMA_HW_CHANNEL_86      (86U)
#define DMA_HW_CHANNEL_87      (87U)
#define DMA_HW_CHANNEL_88      (88U)
#define DMA_HW_CHANNEL_89      (89U)
#define DMA_HW_CHANNEL_90      (90U)
#define DMA_HW_CHANNEL_91      (91U)
#define DMA_HW_CHANNEL_92      (92U)
#define DMA_HW_CHANNEL_93      (93U)
#define DMA_HW_CHANNEL_94      (94U)
#define DMA_HW_CHANNEL_95      (95U)
#define DMA_HW_CHANNEL_96      (96U)
#define DMA_HW_CHANNEL_97      (97U)
#define DMA_HW_CHANNEL_98      (98U)
#define DMA_HW_CHANNEL_99      (99U)
#define DMA_HW_CHANNEL_100     (100U)
#define DMA_HW_CHANNEL_101     (101U)
#define DMA_HW_CHANNEL_102     (102U)
#define DMA_HW_CHANNEL_103     (103U)
#define DMA_HW_CHANNEL_104     (104U)
#define DMA_HW_CHANNEL_105     (105U)
#define DMA_HW_CHANNEL_106     (106U)
#define DMA_HW_CHANNEL_107     (107U)
#define DMA_HW_CHANNEL_108     (108U)
#define DMA_HW_CHANNEL_109     (109U)
#define DMA_HW_CHANNEL_110     (110U)
#define DMA_HW_CHANNEL_111     (111U)
#define DMA_HW_CHANNEL_112     (112U)
#define DMA_HW_CHANNEL_113     (113U)
#define DMA_HW_CHANNEL_114     (114U)
#define DMA_HW_CHANNEL_115     (115U)
#define DMA_HW_CHANNEL_116     (116U)
#define DMA_HW_CHANNEL_117     (117U)
#define DMA_HW_CHANNEL_118     (118U)
#define DMA_HW_CHANNEL_119     (119U)
#define DMA_HW_CHANNEL_120     (120U)
#define DMA_HW_CHANNEL_121     (121U)
#define DMA_HW_CHANNEL_122     (122U)
#define DMA_HW_CHANNEL_123     (123U)
#define DMA_HW_CHANNEL_124     (124U)
#define DMA_HW_CHANNEL_125     (125U)
#define DMA_HW_CHANNEL_126     (126U)
#define DMA_HW_CHANNEL_127     (127U)


/**
* @brief define the DMA usage
*/
#define DMA_INSTANCE_USED         (0x1U)
#define DMA_INSTANCE_NOT_USED     (0x0U)
/**
* @brief  offsets used to increment the source and destination addresses
*/
#define DMA_OFFSET_8_BITS       (0x00000001UL)
#define DMA_OFFSET_16_BITS      (0x00000002UL)
#define DMA_OFFSET_32_BITS      (0x00000004UL)
#define DMA_OFFSET_64_BITS      (0x00000008UL)
#define DMA_OFFSET_128_BITS     (0x00000010UL)
#define DMA_OFFSET_256_BITS     (0x00000020UL)

/**
* @brief define the DMA MODULES
*/
#define DMA_MODULE0     (0x0UL)
#define DMA_MODULE1     (0x1UL)


#define DMA_SMOD_MASK_U32           ((uint32)(0x1FUL))
#define DMA_SSIZE_MASK_U32          ((uint32)(0x7UL))
#define DMA_DMOD_MASK_U32           ((uint32)(0x1FUL))
#define DMA_DSIZE_MASK_U32          ((uint32)(0x7UL))
#define DMA_SOFF_MASK_U32           ((uint32)(0xFFFFUL))
#define DMA_CITER_MASK_U32          ((uint32)(0xFFFFUL))

#define DMA_CITER_MASK_ON_U16       ((uint16)(0x01FFU)) 
#define DMA_CITER_MASK_ON_U32       ((uint32)(0x01FFUL))   
#define DMA_CITER_MASK_OFF_U16      ((uint16)(0x7FFFU))  
#define DMA_CITER_MASK_OFF_U32      ((uint32)(0x7FFFUL))

#define DMA_DOFF_MASK_U32           ((uint32)(0xFFFFUL))
#define DMA_BITER_MASK_U32          ((uint32)(0xFFFFUL))
#define DMA_BITER_MASK_ON_U32       ((uint32)(0x01FFUL))        
#define DMA_BITER_MASK_OFF_U32      ((uint32)(0x7FFFUL))
#if (MCL_DMA_NB_CHANNELS == 0x40U)
#define DMA_MAJOR_LINKCH_MASK_U32   ((uint32)(0x3FUL))
#else
#define DMA_MAJOR_LINKCH_MASK_U32   ((uint32)(0x1FUL))
#endif
#define DMA_PRIORITY_MASK_U8        ((uint8)(0xFUL))


/**
* @brief TCD fields shift masks
*/
#define DMA_SMOD_SHIFT_MASK_U32         ((uint32)(27UL))
#define DMA_SSIZE_SHIFT_MASK_U32        ((uint32)(24UL))   
#define DMA_DMOD_SHIFT_MASK_U32         ((uint32)(19UL))
#define DMA_DSIZE_SHIFT_MASK_U32        ((uint32)(16UL))
#define DMA_ITER_SHIFT_MASK_U32         ((uint32)(16UL))
#define DMA_MAJOR_LINKCH_SHIFT_MASK_U32 ((uint32)(8UL))
#define DMA_ITER_LINKCH_SHIFT_MASK_U32  ((uint32)(25UL))

/** 
* @brief this is the implicit value of DMACR regiser, after a reset.
*/ 
#define DMACR_RESET_VALUE_U32       ((uint32)(0x00000400UL))

/** 
* @brief DMA_CR[CX] possible values.
*/
#define DMA_CANCEL_TRANSFER_EN_U32                 ((uint32)(0x00020000U))
#define DMA_CANCEL_TRANSFER_DIS_U32                ((uint32)(0x00000000U))

/** 
* @brief DMA_CR[ECX] possible values.
*/         
#define DMA_ERROR_CANCEL_TRANSFER_EN_U32           ((uint32)(0x00010000U))
#define DMA_ERROR_CANCEL_TRANSFER_DIS_U32          ((uint32)(0x00000000U))


/** 
* @brief DMA_CR[GRP0PRI] shift value.
*/ 
#define DMA_CHANNEL_GROUP_0_PRIORITY_SHIFT_U8       ((uint8)(8))
/** 
* @brief DMA_CR[GRP1PRI] shift value.
*/ 
#define DMA_CHANNEL_GROUP_1_PRIORITY_SHIFT_U8       ((uint8)(10))


#if (MCL_DMA_NB_CHANNELS == 0x40U)
/** 
* @brief DMA_CR[GRP2PRI] shift value.
*/ 
#define DMA_CHANNEL_GROUP_2_PRIORITY_SHIFT_U8       ((uint8)(12))
/** 
* @brief DMA_CR[GRP3PRI] shift value.
*/ 
#define DMA_CHANNEL_GROUP_3_PRIORITY_SHIFT_U8       ((uint8)(14))
#endif

/** 
* @brief DMA_CR[EMLM] possible values.
*/ 
#define DMA_MINOR_LOOP_MAPPING_EN_U32              ((uint32)(0x00000080U))
#define DMA_MINOR_LOOP_MAPPING_DIS_U32             ((uint32)(0x00000000U))
     
/** 
* @brief DMA_CR[CLM] possible values.
*/        
#define DMA_CONT_LINK_MODE_EN_U32                  ((uint32)(0x00000040U))
#define DMA_CONT_LINK_MODE_DIS_U32                 ((uint32)(0x00000000U))
    
/** 
* @brief DMA_CR[HALT] possible values.
*/       
#define DMA_HALT_OPERATIONS_EN_U32                 ((uint32)(0x00000020U))
#define DMA_HALT_OPERATIONS_DIS_U32                ((uint32)(0x00000000U))

/** 
* @brief DMA_CR[HOE] possible values.
*/      
#define DMA_HALT_ON_ERROR_EN_U32                   ((uint32)(0x00000010U))
#define DMA_HALT_ON_ERROR_DIS_U32                  ((uint32)(0x00000000U))
 
/** 
* @brief DMA_CR[ERGA] possible values.
*/  
#define DMA_ROUND_ROBIN_GROUP_ARB_EN_U32           ((uint32)(0x00000008U))
#define DMA_ROUND_ROBIN_GROUP_ARB_DIS_U32          ((uint32)(0x00000000U))

/** 
* @brief DMA_CR[ERCA] possible values.
*/     
#define DMA_ROUND_ROBIN_ARB_EN_U32                 ((uint32)(0x00000004U))
#define DMA_ROUND_ROBIN_ARB_DIS_U32                ((uint32)(0x00000000U))
     
/** 
* @brief DMA_CR[EDBG] possible values.
*/       
#define DMA_DEBUG_EN_U32                           ((uint32)(0x00000002U))
#define DMA_DEBUG_DIS_U32                          ((uint32)(0x00000000U))

/** 
* @brief DMA_CR[EBW] possible values.
*/     
#define DMA_BUFFERED_WRITE_EN_U32                  ((uint32)(0x00000001U))
#define DMA_BUFFERED_WRITE_DIS_U32                 ((uint32)(0x00000000U))

/** 
* @brief DMA_DCHPRIn[ECP] possible values.
*/
#define DMA_ECP_EN_U8                             ((uint8)(0x80U))
#define DMA_ECP_DIS_U8                            ((uint8)(0x00U))

/** 
* @brief DMA_DCHPRIn[DPA] possible values.
*/
#define DMA_DPA_EN_U8                             ((uint8)(0x40U))
#define DMA_DPA_DIS_U8                            ((uint8)(0x00U))

/** 
* @brief DMA_DCHMIDn[EMI] possible values.
*/
#define DMA_EMI_EN_U8                             ((uint8)(0x80U))
#define DMA_EMI_DIS_U8                            ((uint8)(0x00U))
/** 
* @brief DMA_EARS[EDREQx] possible values.
*/
#define DMA_EDREQ_EN_U32                             ((uint32)(0x01UL))
#define DMA_EDREQ_DIS_U32                            ((uint32)(0x00UL))
/**
* @brief Priority Values
*/
#define DMA_PRIORITY_0_U8                         ((uint8)(0x00U))
#define DMA_PRIORITY_1_U8                         ((uint8)(0x01U))
#define DMA_PRIORITY_2_U8                         ((uint8)(0x02U))
#define DMA_PRIORITY_3_U8                         ((uint8)(0x03U))
#define DMA_PRIORITY_4_U8                         ((uint8)(0x04U))
#define DMA_PRIORITY_5_U8                         ((uint8)(0x05U))
#define DMA_PRIORITY_6_U8                         ((uint8)(0x06U))
#define DMA_PRIORITY_7_U8                         ((uint8)(0x07U))
#define DMA_PRIORITY_8_U8                         ((uint8)(0x08U))
#define DMA_PRIORITY_9_U8                         ((uint8)(0x09U))
#define DMA_PRIORITY_10_U8                        ((uint8)(0x0aU))
#define DMA_PRIORITY_11_U8                        ((uint8)(0x0bU))
#define DMA_PRIORITY_12_U8                        ((uint8)(0x0cU))
#define DMA_PRIORITY_13_U8                        ((uint8)(0x0dU))
#define DMA_PRIORITY_14_U8                        ((uint8)(0x0eU))
#define DMA_PRIORITY_15_U8                        ((uint8)(0x0fU))
#define DMA_PRIORITY_16_U8                        ((uint8)(0x10U))
#define DMA_PRIORITY_17_U8                        ((uint8)(0x11U))
#define DMA_PRIORITY_18_U8                        ((uint8)(0x12U))
#define DMA_PRIORITY_19_U8                        ((uint8)(0x13U))
#define DMA_PRIORITY_20_U8                        ((uint8)(0x14U))
#define DMA_PRIORITY_21_U8                        ((uint8)(0x15U))
#define DMA_PRIORITY_22_U8                        ((uint8)(0x16U))
#define DMA_PRIORITY_23_U8                        ((uint8)(0x17U))
#define DMA_PRIORITY_24_U8                        ((uint8)(0x18U))
#define DMA_PRIORITY_25_U8                        ((uint8)(0x19U))
#define DMA_PRIORITY_26_U8                        ((uint8)(0x1aU))
#define DMA_PRIORITY_27_U8                        ((uint8)(0x1bU))
#define DMA_PRIORITY_28_U8                        ((uint8)(0x1cU))
#define DMA_PRIORITY_29_U8                        ((uint8)(0x1dU))
#define DMA_PRIORITY_30_U8                        ((uint8)(0x1eU))
#define DMA_PRIORITY_31_U8                        ((uint8)(0x1fU))

/** 
* @{
* @brief TCD Word8 bit masks for flags.
*/
#define DMA_TCD_DONE_U8             ((uint8)0x80U)
#define DMA_TCD_DONE_U32            ((uint32)DMA_TCD_DONE_U8)

#define DMA_TCD_ACTIVE_U8           ((uint8)0x40U)
#define DMA_TCD_ACTIVE_U32          ((uint32)DMA_TCD_ACTIVE_U8)

#define DMA_TCD_MAJOR_E_LINK_U8     ((uint8)0x20U)
#define DMA_TCD_MAJOR_E_LINK_U32    ((uint32)DMA_TCD_MAJOR_E_LINK_U8)

#define DMA_TCD_E_SG_U8             ((uint8)0x10U)
#define DMA_TCD_E_SG_U32            ((uint32)DMA_TCD_E_SG_U8)

#define DMA_TCD_DISABLE_REQ_U8      ((uint8)0x08U)
#define DMA_TCD_DISABLE_REQ_U32     ((uint32)DMA_TCD_DISABLE_REQ_U8)

#define DMA_TCD_INT_HALF_U8         ((uint8)0x04U)
#define DMA_TCD_INT_HALF_U32        ((uint32)DMA_TCD_INT_HALF_U8)

#define DMA_TCD_INT_MAJOR_U8        ((uint8)0x02U)
#define DMA_TCD_INT_MAJOR_U32       ((uint32)DMA_TCD_INT_MAJOR_U8)

#define DMA_TCD_START_U8            ((uint8)0x01U)
#define DMA_TCD_START_U32           ((uint32)DMA_TCD_START_U8)

/** @} */

/**
* @brief For DMA TCDs which do not use e_link field, major loop iteration count is on 15 bits.
*/
#define DMA_MAX_UNLINKED_ITER_CNT_U16   (0x7FFFu)
/**
* @brief For DMA TCDs using e_link field, major loop iteration count is on 9 bits
*/
#define DMA_MAX_LINKED_ITER_CNT_U16     (0x1FFu)
/**
* @brief For getting the DMA error status,the define is used when no channel should be reported
*/
#define MCL_DMA_NO_CHANNEL_U16              (65535U)
/**
* @brief For getting the DMA error status,the define is used when no channel should be reported
*/
#define MCL_DMA_CHANNEL_NOT_CONFIGURED_U8   (255U)
/*===============================================================================================
                                             ENUMS
===============================================================================================*/
/**
* @brief      Dma notification configuration structure
*/
typedef enum 
{
    /** @brief A notification will be generated when major iteration count completes */
    MCL_DMA_TRANSFER_COMPLETE = 0,
    /** @brief A notification will be generated when major counter is half complete */
    MCL_DMA_TRANSFER_HALF_COMPLETE
} Mcl_DmaTransferNotifType;

/**
* @brief      Dma transfer size structure
*/
typedef enum 
{ 
#ifdef MCL_TRANSFER_SIZE_1_BYTE 
    DMA_SIZE_1BYTE = 0 /** @brief Transfer size 1 byte */ 
#endif 
#ifdef MCL_TRANSFER_SIZE_2_BYTE 
    ,DMA_SIZE_2BYTES = 1 /** @brief Transfer size 2 bytes */ 
#endif 
#ifdef MCL_TRANSFER_SIZE_4_BYTE 
    ,DMA_SIZE_4BYTES = 2 /** @brief Transfer size 4 bytes */ 
#endif 
#ifdef MCL_TRANSFER_SIZE_8_BYTE 
    ,DMA_SIZE_8BYTES = 3 /** @brief Transfer size 8 bytes */ 
#endif 
#ifdef MCL_TRANSFER_SIZE_16_BYTE 
    ,DMA_SIZE_16BYTES = 4 /** @brief Transfer size 16 bytes */ 
#endif 
#ifdef MCL_TRANSFER_SIZE_32_BYTE 
    ,DMA_SIZE_32BYTES = 5 /** @brief Transfer size 32 bytes */ 
#endif 
} Mcl_DmaSizeType;

/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/
/**
 * @brief          Mcl_DmaErroneousChannelType the numeric ID of a Mcl logic channel
 * */
typedef uint16  Mcl_DmaErroneousChannelType;

/**
 * @brief          Mcl_DmaChannelErrorStatusType provides the numeric ID of a Mcl DMA error
 * */
typedef enum
{
    MCL_DMA_NO_ERROR = 0,
    MCL_DMA_HW_INCONSISTENCY_ERROR = 1,
    MCL_DMA_ECC_ERROR = 2,
    MCL_DMA_BUS_ERROR = 3,
    MCL_DMA_DESCRIPTOR_ERROR = 4,
    MCL_DMA_PRIORITY_ERROR = 5,
    MCL_DMA_UNRECOGNIZED_ERROR = 6,
    MCL_DMA_MEM_SYNC_ERROR = 7        
}Mcl_DmaChannelErrorStatusType;
/**
 * @brief          Mcl_DmaRequestType provides the request for AAPIs which get info from hardware
 * */
typedef enum
{
    MCL_DMA_GET_ERR = 0,
    MCL_DMA_GET_INT
}Mcl_DmaRequestType;
/**
* @brief      Mcl high level report error structure
*
*/
typedef struct {
    Mcl_DmaErroneousChannelType    erroneousChannel;
    Mcl_DmaChannelErrorStatusType  errorId;
}Mcl_DmaGlobalErrorStatusType;
/**
 * @brief          Type for specifing the DMA channel's priority
 *
 * */
typedef uint8               Mcl_DmaPriorityType;
/**
 * @brief          This gives the numeric ID (hardware channel number) of an DMA channel
 * */
typedef uint8               Mcl_DmaChannelType;

/**
 * @brief          The Dma_ControlType contains DMA CR configuration
 *
 * */
typedef uint32              Mcl_DmaControlType;

/**
 * @brief          The Dma_TcdType contains combined bit fields for the channel's TCD
 *
 * */
typedef uint32              Mcl_DmaTcdType;
/**
 * @brief          The Mcl_DmaInstanceType contains he DMA instance number
 *
 * */
typedef uint8              Mcl_DmaInstanceType;
/**
 * @brief          The Mcl_DmaUsedType contains the DMA usage information (whether DMA is used in configuration or not)
 *
 * */
typedef uint8              Mcl_DmaUsedType;
/**
* @brief      Dma channel configuration structure
*/
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
/**
 * @brief          The error notification function.
 * */
typedef void       (*Mcl_DmaErrNotifyType)(VAR(Mcl_DmaChannelErrorStatusType, AUTOMATIC) u8ErrorCode);
#endif

typedef struct
{
    /** @brief Channel ECP, DPA and Priority */
    CONST(Mcl_DmaPriorityType, MCL_CONST) Dma_ChannelPriority;
    /** @brief eDma channel used */
    CONST(Mcl_DmaChannelType,  MCL_CONST) Dma_Channel;
    /** @brief eDma channel master ID replication */
    CONST(Mcl_DmaChannelType,  MCL_CONST) Dma_MasterId;
#ifdef MCL_DMA_SETUP_EARS
#if (MCL_DMA_SETUP_EARS == STD_ON)
    /** @brief Enable Asynchronous Request in Stop Register */
    CONST(uint32,  MCL_CONST) Dma_AsynchronousRequest;
#endif
#endif
} Mcl_DmaChannelConfigType;

typedef struct
{
    /** @brief Dma CR Configuration */
    CONST(Mcl_DmaControlType, MCL_CONST)         pDmaControl;
    /** @brief Dma Usage in Configuration */
    CONST(Mcl_DmaUsedType, MCL_CONST)            pDmaUsed;
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    /** @brief Pointer to notification function */
    CONST(Mcl_DmaErrNotifyType, MCL_CONST)       pfDmaInstanceErrNotif;
#endif /*(MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)*/
} Mcl_DmaConfigInstanceType;

/**
* @brief      Dma configuration structure
*/

typedef struct
{
    /** @brief Number of eDma channels in the Mcl configuration */
    CONST(Mcl_DmaChannelType, MCL_CONST)                                NumChannels;
    /** @brief Pointer to the configured channels for eDma */
    CONST(Mcl_DmaConfigInstanceType, MCL_CONST) (* const pDmaConfigInstance)[];
    /** @brief Pointer to the configured channels for eDma */
    CONST(Mcl_DmaChannelConfigType, MCL_CONST) (* const pChannelsConfig)[];
} Mcl_DmaConfigType;


/**
* @brief structure used for a basic configuration of a TCD
*/
typedef struct 
{
    VAR(uint32, AUTOMATIC) u32saddr;                     /** @brief source address */
    VAR(uint32, AUTOMATIC) u32daddr;                     /** @brief destination address */
    VAR(uint32, AUTOMATIC) u32ssize;                     /** @brief source transfer size */
    VAR(uint32, AUTOMATIC) u32dsize;                     /** @brief destination transfer size */
    VAR(uint32, AUTOMATIC) u32soff;                      /** @brief source address offset */
    VAR(uint32, AUTOMATIC) u32doff;                      /** @brief destination address offset */
    VAR(uint32, AUTOMATIC) u32smod;                      /** @brief source address modulo */
    VAR(uint32, AUTOMATIC) u32dmod;                      /** @brief destination address modulo */
    VAR(uint32, AUTOMATIC) u32num_bytes;                 /** @brief number of bytes to be transferred */
    VAR(uint32, AUTOMATIC) u32iter;                      /** @brief iteration count */
}Mcl_DmaTcdAttributesType;  

#endif
#endif
/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* MCL_DMA_TYPES_H */
/** @} */
