/**
*     @version 1.0.1
*
*     @brief   AUTOSAR Mcl - MCL driver header file.
*     @details MCL driver header file, containing the Autosar API specification and other variables
*              and functions that are exported by the MCL driver.
*
*     @addtogroup MCL_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : eDMA
*     Dependencies        : none
*
*     Autosar Version     :  4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef MCL_TYPES_H
#define MCL_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"
#include "Mcl_IPW_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_TYPES_VENDOR_ID                       43
#define MCL_TYPES_MODULE_ID                       255
#define MCL_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCL_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCL_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCL_TYPES_SW_MAJOR_VERSION                1
#define MCL_TYPES_SW_MINOR_VERSION                0
#define MCL_TYPES_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
 /* Check if header file and MCL configuration header file are of the same vendor */
#if (MCL_TYPES_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "Mcl_Types.h and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and MCL configuration header file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcl_Types.h and CDD_Mcl_Cfg.h are different"
#endif
/* Check if header file and MCL configuration header file are of the same software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_TYPES_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_TYPES_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcl_Types.h and CDD_Mcl_Cfg.hare different"
#endif

/* Check if header file and MCL IPW types header file are of the same vendor */
#if (MCL_TYPES_VENDOR_ID != MCL_IPW_TYPES_VENDOR_ID)
    #error "Mcl_Types.h and Mcl_IPW_Types.h have different vendor IDs"
#endif
    /* Check if header file and MCL configuration header file are of the same Autosar version */
#if ((MCL_TYPES_AR_RELEASE_MAJOR_VERSION != MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_MINOR_VERSION != MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TYPES_AR_RELEASE_REVISION_VERSION != MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcl_Types.h and Mcl_IPW_Types.h are different"
#endif
/* Check if header file and MCL configuration header file are of the same software version */
#if ((MCL_TYPES_SW_MAJOR_VERSION != MCL_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCL_TYPES_SW_MINOR_VERSION != MCL_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCL_TYPES_SW_PATCH_VERSION != MCL_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcl_Types.h and Mcl_IPW_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)

/* DMA logical channels */
#define MCL_DMA_LOGICAL_CHANNEL_0       (0U)
#define MCL_DMA_LOGICAL_CHANNEL_1       (1U)
#define MCL_DMA_LOGICAL_CHANNEL_2       (2U)
#define MCL_DMA_LOGICAL_CHANNEL_3       (3U)
#define MCL_DMA_LOGICAL_CHANNEL_4       (4U)
#define MCL_DMA_LOGICAL_CHANNEL_5       (5U)
#define MCL_DMA_LOGICAL_CHANNEL_6       (6U)
#define MCL_DMA_LOGICAL_CHANNEL_7       (7U)
#define MCL_DMA_LOGICAL_CHANNEL_8       (8U)
#define MCL_DMA_LOGICAL_CHANNEL_9       (9U)
#define MCL_DMA_LOGICAL_CHANNEL_10      (10U)
#define MCL_DMA_LOGICAL_CHANNEL_11      (11U)
#define MCL_DMA_LOGICAL_CHANNEL_12      (12U)
#define MCL_DMA_LOGICAL_CHANNEL_13      (13U)
#define MCL_DMA_LOGICAL_CHANNEL_14      (14U)
#define MCL_DMA_LOGICAL_CHANNEL_15      (15U)
#define MCL_DMA_LOGICAL_CHANNEL_16      (16U)
#define MCL_DMA_LOGICAL_CHANNEL_17      (17U)
#define MCL_DMA_LOGICAL_CHANNEL_18      (18U)
#define MCL_DMA_LOGICAL_CHANNEL_19      (19U)
#define MCL_DMA_LOGICAL_CHANNEL_20      (20U)
#define MCL_DMA_LOGICAL_CHANNEL_21      (21U)
#define MCL_DMA_LOGICAL_CHANNEL_22      (22U)
#define MCL_DMA_LOGICAL_CHANNEL_23      (23U)
#define MCL_DMA_LOGICAL_CHANNEL_24      (24U)
#define MCL_DMA_LOGICAL_CHANNEL_25      (25U)
#define MCL_DMA_LOGICAL_CHANNEL_26      (26U)
#define MCL_DMA_LOGICAL_CHANNEL_27      (27U)
#define MCL_DMA_LOGICAL_CHANNEL_28      (28U)
#define MCL_DMA_LOGICAL_CHANNEL_29      (29U)
#define MCL_DMA_LOGICAL_CHANNEL_30      (30U)
#define MCL_DMA_LOGICAL_CHANNEL_31      (31U)
#define MCL_DMA_LOGICAL_CHANNEL_32      (32U)
#define MCL_DMA_LOGICAL_CHANNEL_33      (33U)
#define MCL_DMA_LOGICAL_CHANNEL_34      (34U)
#define MCL_DMA_LOGICAL_CHANNEL_35      (35U)
#define MCL_DMA_LOGICAL_CHANNEL_36      (36U)
#define MCL_DMA_LOGICAL_CHANNEL_37      (37U)
#define MCL_DMA_LOGICAL_CHANNEL_38      (38U)
#define MCL_DMA_LOGICAL_CHANNEL_39      (39U)
#define MCL_DMA_LOGICAL_CHANNEL_40      (40U)
#define MCL_DMA_LOGICAL_CHANNEL_41      (41U)
#define MCL_DMA_LOGICAL_CHANNEL_42      (42U)
#define MCL_DMA_LOGICAL_CHANNEL_43      (43U)
#define MCL_DMA_LOGICAL_CHANNEL_44      (44U)
#define MCL_DMA_LOGICAL_CHANNEL_45      (45U)
#define MCL_DMA_LOGICAL_CHANNEL_46      (46U)
#define MCL_DMA_LOGICAL_CHANNEL_47      (47U)
#define MCL_DMA_LOGICAL_CHANNEL_48      (48U)
#define MCL_DMA_LOGICAL_CHANNEL_49      (49U)
#define MCL_DMA_LOGICAL_CHANNEL_50      (50U)
#define MCL_DMA_LOGICAL_CHANNEL_51      (51U)
#define MCL_DMA_LOGICAL_CHANNEL_52      (52U)
#define MCL_DMA_LOGICAL_CHANNEL_53      (53U)
#define MCL_DMA_LOGICAL_CHANNEL_54      (54U)
#define MCL_DMA_LOGICAL_CHANNEL_55      (55U)
#define MCL_DMA_LOGICAL_CHANNEL_56      (56U)
#define MCL_DMA_LOGICAL_CHANNEL_57      (57U)
#define MCL_DMA_LOGICAL_CHANNEL_58      (58U)
#define MCL_DMA_LOGICAL_CHANNEL_59      (59U)
#define MCL_DMA_LOGICAL_CHANNEL_60      (60U)
#define MCL_DMA_LOGICAL_CHANNEL_61      (61U)
#define MCL_DMA_LOGICAL_CHANNEL_62      (62U)
#define MCL_DMA_LOGICAL_CHANNEL_63      (63U)
#define MCL_DMA_LOGICAL_CHANNEL_64      (64U)
#define MCL_DMA_LOGICAL_CHANNEL_65      (65U)
#define MCL_DMA_LOGICAL_CHANNEL_66      (66U)
#define MCL_DMA_LOGICAL_CHANNEL_67      (67U)
#define MCL_DMA_LOGICAL_CHANNEL_68      (68U)
#define MCL_DMA_LOGICAL_CHANNEL_69      (69U)
#define MCL_DMA_LOGICAL_CHANNEL_70      (70U)
#define MCL_DMA_LOGICAL_CHANNEL_71      (71U)
#define MCL_DMA_LOGICAL_CHANNEL_72      (72U)
#define MCL_DMA_LOGICAL_CHANNEL_73      (73U)
#define MCL_DMA_LOGICAL_CHANNEL_74      (74U)
#define MCL_DMA_LOGICAL_CHANNEL_75      (75U)
#define MCL_DMA_LOGICAL_CHANNEL_76      (76U)
#define MCL_DMA_LOGICAL_CHANNEL_77      (77U)
#define MCL_DMA_LOGICAL_CHANNEL_78      (78U)
#define MCL_DMA_LOGICAL_CHANNEL_79      (79U)
#define MCL_DMA_LOGICAL_CHANNEL_80      (80U)
#define MCL_DMA_LOGICAL_CHANNEL_81      (81U)
#define MCL_DMA_LOGICAL_CHANNEL_82      (82U)
#define MCL_DMA_LOGICAL_CHANNEL_83      (83U)
#define MCL_DMA_LOGICAL_CHANNEL_84      (84U)
#define MCL_DMA_LOGICAL_CHANNEL_85      (85U)
#define MCL_DMA_LOGICAL_CHANNEL_86      (86U)
#define MCL_DMA_LOGICAL_CHANNEL_87      (87U)
#define MCL_DMA_LOGICAL_CHANNEL_88      (88U)
#define MCL_DMA_LOGICAL_CHANNEL_89      (89U)
#define MCL_DMA_LOGICAL_CHANNEL_90      (90U)
#define MCL_DMA_LOGICAL_CHANNEL_91      (91U)
#define MCL_DMA_LOGICAL_CHANNEL_92      (92U)
#define MCL_DMA_LOGICAL_CHANNEL_93      (93U)
#define MCL_DMA_LOGICAL_CHANNEL_94      (94U)
#define MCL_DMA_LOGICAL_CHANNEL_95      (95U)
#define MCL_DMA_LOGICAL_CHANNEL_96      (96U)
#define MCL_DMA_LOGICAL_CHANNEL_97      (97U)
#define MCL_DMA_LOGICAL_CHANNEL_98      (98U)
#define MCL_DMA_LOGICAL_CHANNEL_99      (99U)
#define MCL_DMA_LOGICAL_CHANNEL_100     (100U)
#define MCL_DMA_LOGICAL_CHANNEL_101     (101U)
#define MCL_DMA_LOGICAL_CHANNEL_102     (102U)
#define MCL_DMA_LOGICAL_CHANNEL_103     (103U)
#define MCL_DMA_LOGICAL_CHANNEL_104     (104U)
#define MCL_DMA_LOGICAL_CHANNEL_105     (105U)
#define MCL_DMA_LOGICAL_CHANNEL_106     (106U)
#define MCL_DMA_LOGICAL_CHANNEL_107     (107U)
#define MCL_DMA_LOGICAL_CHANNEL_108     (108U)
#define MCL_DMA_LOGICAL_CHANNEL_109     (109U)
#define MCL_DMA_LOGICAL_CHANNEL_110     (110U)
#define MCL_DMA_LOGICAL_CHANNEL_111     (111U)
#define MCL_DMA_LOGICAL_CHANNEL_112     (112U)
#define MCL_DMA_LOGICAL_CHANNEL_113     (113U)
#define MCL_DMA_LOGICAL_CHANNEL_114     (114U)
#define MCL_DMA_LOGICAL_CHANNEL_115     (115U)
#define MCL_DMA_LOGICAL_CHANNEL_116     (116U)
#define MCL_DMA_LOGICAL_CHANNEL_117     (117U)
#define MCL_DMA_LOGICAL_CHANNEL_118     (118U)
#define MCL_DMA_LOGICAL_CHANNEL_119     (119U)
#define MCL_DMA_LOGICAL_CHANNEL_120     (120U)
#define MCL_DMA_LOGICAL_CHANNEL_121     (121U)
#define MCL_DMA_LOGICAL_CHANNEL_122     (122U)
#define MCL_DMA_LOGICAL_CHANNEL_123     (123U)
#define MCL_DMA_LOGICAL_CHANNEL_124     (124U)
#define MCL_DMA_LOGICAL_CHANNEL_125     (125U)
#define MCL_DMA_LOGICAL_CHANNEL_126     (126U)
#define MCL_DMA_LOGICAL_CHANNEL_127     (127U)
#endif 

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)
/**
 * @brief          The notification functions shall have no parameters and no return value.
 * */
typedef void       (*Mcl_NotifyType)(void);
  
/**
 * @brief          This gives the numeric ID of a Mcl logic channel
 * */
typedef uint8      Mcl_ChannelType;
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* MCL_TYPES_H */
/** @} */

