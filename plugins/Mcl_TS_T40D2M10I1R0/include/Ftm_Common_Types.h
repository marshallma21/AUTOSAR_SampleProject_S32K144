/**
*   @file    Ftm_Common_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - FTM driver header file.
*   @details FTM defines.
*
*   @addtogroup FTM_MODULE
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

#ifndef FTM_COMMON_TYPES_H
#define FTM_COMMON_TYPES_H
/**
*   @file    Ftm_Common_Types.h
*/
/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section FTM_COMMON_TYPES_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported 
*
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ftm_Common_Types.h
* @brief          Source file version information
* 
*/
#define FTM_COMMON_TYPES_VENDOR_ID                       43
/** @violates @ref FTM_COMMON_TYPES_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref FTM_COMMON_TYPES_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref FTM_COMMON_TYPES_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be 
*checked to ensure that 31 character significance and case sensitivity are supported for external identifiers. */
#define FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION     2
#define FTM_COMMON_TYPES_SW_MAJOR_VERSION                1
#define FTM_COMMON_TYPES_SW_MINOR_VERSION                0
#define FTM_COMMON_TYPES_SW_PATCH_VERSION                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/**
* @brief FTM channel 0 mask 
*/
#define FTM_CH_0_MASK_U32    ((uint32)(1U << 0U))
/**
* @brief FTM channel 1 mask
*/
#define FTM_CH_1_MASK_U32    ((uint32)(1U << 1U))
/**
* @brief FTM channel 2 mask
*/
#define FTM_CH_2_MASK_U32    ((uint32)(1U << 2U))
/**
* @brief FTM channel 3 mask
*/
#define FTM_CH_3_MASK_U32    ((uint32)(1U << 3U))
/**
* @brief FTM channel 4 mask
*/
#define FTM_CH_4_MASK_U32    ((uint32)(1U << 4U))
/**
* @brief FTM channel 5 mask
*/
#define FTM_CH_5_MASK_U32    ((uint32)(1U << 5U))
/**
* @brief FTM channel 6 mask
*/
#define FTM_CH_6_MASK_U32    ((uint32)(1U << 6U))
/**
* @brief FTM channel 7 mask
*/
#define FTM_CH_7_MASK_U32    ((uint32)(1U << 7U))



/**
* @brief FTM 0
*/
#define FTM_0    ((uint8)0)
/**
* @brief FTM 1
*/
#define FTM_1    ((uint8)1)
/**
* @brief FTM 2
*/
#define FTM_2    ((uint8)2)
/**
* @brief FTM 3
*/
#define FTM_3    ((uint8)3)
/**
* @brief FTM 4
*/
#define FTM_4    ((uint8)4)
/**
* @brief FTM 5
*/
#define FTM_5   ((uint8)5)
/**
* @brief FTM 6
*/
#define FTM_6   ((uint8)6)
/**
* @brief FTM 7
*/
#define FTM_7  ((uint8)7)


/**
* @{
* @brief          FTM channels defines
* @details        There are defines used for the FTM channel encoding -> channel_id
*
* @note           an FTM module generally has only 6 channels so by using this method 
*                 there will be gaps of 2 channels between different FTM modules because
*                 [              5 bit  | 3 bit               ]
*                 [ module id: 31 ... 0 | channel id: 7 ... 0 ]
*/
#define FTM_MOD_MASK_U8     ((uint8)0xF8)
#define FTM_MOD_SHIFT       ((uint8)3U)
#define FTM_CH_MASK_U8      ((uint8)0x7)
#define FTM_CH_SHIFT        ((uint8)0U)
/** @} */


/**
* @brief FTM 0 channel 0
*/
#define FTM_0_CH_0    ((uint8)0x00)
/**
* @brief FTM 0 channel 1 
*/
#define FTM_0_CH_1    ((uint8)0x01)
/**
* @brief FTM 0 channel 2 
*/
#define FTM_0_CH_2    ((uint8)0x02)
/**
* @brief FTM 0 channel 3 
*/
#define FTM_0_CH_3    ((uint8)0x03)
/**
* @brief FTM 0 channel 4 
*/
#define FTM_0_CH_4    ((uint8)0x04)
/**
* @brief FTM 0 channel 5 
*/
#define FTM_0_CH_5    ((uint8)0x05)
/**
* @brief FTM 0 channel 6 
*/
#define FTM_0_CH_6    ((uint8)0x06)
/**
* @brief FTM 0 channel 7 
*/
#define FTM_0_CH_7    ((uint8)0x07)



/**
* @brief FTM 1 channel 0
*/
#define FTM_1_CH_0    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 1 channel 1
*/
#define FTM_1_CH_1    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 1 channel 2
*/
#define FTM_1_CH_2    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 1 channel 3
*/
#define FTM_1_CH_3    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 1 channel 4
*/
#define FTM_1_CH_4    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 1 channel 5
*/
#define FTM_1_CH_5    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 1 channel 6
*/
#define FTM_1_CH_6    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 1 channel 7
*/
#define FTM_1_CH_7    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x07))



/**
* @brief FTM 2 channel 0
*/
#define FTM_2_CH_0    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 2 channel 1
*/
#define FTM_2_CH_1    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 2 channel 2
*/
#define FTM_2_CH_2    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 2 channel 3
*/
#define FTM_2_CH_3    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 2 channel 4
*/
#define FTM_2_CH_4    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 2 channel 5
*/
#define FTM_2_CH_5    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 2 channel 6
*/
#define FTM_2_CH_6    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 2 channel 7
*/
#define FTM_2_CH_7    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x07))



/**
* @brief FTM 3 channel 0
*/
#define FTM_3_CH_0    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 3 channel 1
*/
#define FTM_3_CH_1    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 3 channel 2
*/
#define FTM_3_CH_2    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 3 channel 3
*/
#define FTM_3_CH_3    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 3 channel 4
*/
#define FTM_3_CH_4    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 3 channel 5
*/
#define FTM_3_CH_5    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 3 channel 6
*/
#define FTM_3_CH_6    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 3 channel 7
*/
#define FTM_3_CH_7    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x07))

/**
* @brief FTM 4 channel 0
*/
#define FTM_4_CH_0    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 4 channel 1
*/
#define FTM_4_CH_1    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 4 channel 2
*/
#define FTM_4_CH_2    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 4 channel 3
*/
#define FTM_4_CH_3    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 4 channel 4
*/
#define FTM_4_CH_4    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 4 channel 5
*/
#define FTM_4_CH_5    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 4 channel 6
*/
#define FTM_4_CH_6    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 4 channel 7
*/
#define FTM_4_CH_7    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x07))

/**
* @brief FTM 5 channel 0
*/
#define FTM_5_CH_0    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 5 channel 1
*/
#define FTM_5_CH_1    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 5 channel 2
*/
#define FTM_5_CH_2    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 5 channel 3
*/
#define FTM_5_CH_3    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 5 channel 4
*/
#define FTM_5_CH_4    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 5 channel 5
*/
#define FTM_5_CH_5    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 5 channel 6
*/
#define FTM_5_CH_6    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 5 channel 7
*/
#define FTM_5_CH_7    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x07))

/**
* @brief FTM 6 channel 0
*/
#define FTM_6_CH_0    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 6 channel 1
*/
#define FTM_6_CH_1    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 6 channel 2
*/
#define FTM_6_CH_2    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 6 channel 3
*/
#define FTM_6_CH_3    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 6 channel 4
*/
#define FTM_6_CH_4    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 6 channel 5
*/
#define FTM_6_CH_5    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 6 channel 6
*/
#define FTM_6_CH_6    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 6 channel 7
*/
#define FTM_6_CH_7    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x07))

/**
* @brief FTM 7 channel 0
*/
#define FTM_7_CH_0    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 7 channel 1
*/
#define FTM_7_CH_1    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 7 channel 2
*/
#define FTM_7_CH_2    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 7 channel 3
*/
#define FTM_7_CH_3    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x03))
/**
* @brief FTM 7 channel 4
*/
#define FTM_7_CH_4    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x04))
/**
* @brief FTM 7 channel 5
*/
#define FTM_7_CH_5    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x05))
/**
* @brief FTM 7 channel 6
*/
#define FTM_7_CH_6    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x06))
/**
* @brief FTM 7 channel 7
*/
#define FTM_7_CH_7    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x07))

/**
* @brief FTM 0 Fault 0
*/
#define FTM_0_FAULT_0    ((uint8)((uint8)(0U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 0 Fault 1 
*/
#define FTM_0_FAULT_1    ((uint8)((uint8)(0U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 0 Fault 2 
*/
#define FTM_0_FAULT_2    ((uint8)((uint8)(0U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 0 Fault 3 
*/
#define FTM_0_FAULT_3   ((uint8)((uint8)(0U<<FTM_MOD_SHIFT) + (uint8)0x03))

/**
* @brief FTM 1 Fault 0
*/
#define FTM_1_FAULT_0    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 1 Fault 1 
*/
#define FTM_1_FAULT_1    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 1 Fault 2 
*/
#define FTM_1_FAULT_2    ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 1 Fault 3 
*/
#define FTM_1_FAULT_3   ((uint8)((uint8)(1U<<FTM_MOD_SHIFT) + (uint8)0x03))



/**
* @brief FTM 2 Fault 0
*/
#define FTM_2_FAULT_0    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 2 Fault 1 
*/
#define FTM_2_FAULT_1    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 2 Fault 2 
*/
#define FTM_2_FAULT_2    ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 2 Fault 3 
*/
#define FTM_2_FAULT_3   ((uint8)((uint8)(2U<<FTM_MOD_SHIFT) + (uint8)0x03))
    
    
/**
* @brief FTM 3 Fault 0
*/
#define FTM_3_FAULT_0    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 3 Fault 1 
*/
#define FTM_3_FAULT_1    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x01))
/**
* @brief FTM 3 Fault 2 
*/
#define FTM_3_FAULT_2    ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x02))
/**
* @brief FTM 3 Fault 3 
*/
#define FTM_3_FAULT_3   ((uint8)((uint8)(3U<<FTM_MOD_SHIFT) + (uint8)0x03))

/**
* @brief FTM 4 Fault 0
*/
#define FTM_4_FAULT_0    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 4 Fault 1 
*/
#define FTM_4_FAULT_1    ((uint8)((uint8)(4U<<FTM_MOD_SHIFT) + (uint8)0x01))

/**
* @brief FTM 5 Fault 0
*/
#define FTM_5_FAULT_0    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 5 Fault 1 
*/
#define FTM_5_FAULT_1    ((uint8)((uint8)(5U<<FTM_MOD_SHIFT) + (uint8)0x01))

/**
* @brief FTM 6 Fault 0
*/
#define FTM_6_FAULT_0    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 6 Fault 1 
*/
#define FTM_6_FAULT_1    ((uint8)((uint8)(6U<<FTM_MOD_SHIFT) + (uint8)0x01))

/**
* @brief FTM 7 Fault 0
*/
#define FTM_7_FAULT_0    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x00))
/**
* @brief FTM 7 Fault 1 
*/
#define FTM_7_FAULT_1    ((uint8)((uint8)(7U<<FTM_MOD_SHIFT) + (uint8)0x01))
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

#endif 

/** @} */
