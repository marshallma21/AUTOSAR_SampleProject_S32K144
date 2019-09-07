/**
*     @file       Crcu_Reg_eSys_Crcv2.h
*     @version    1.0.1
*     
*     @brief      AUTOSAR Crcu - CRCV2 low level driver register defines.
*     @details    The description of the registers of the CRCV2 module.
*     
*     @addtogroup CRCU_MODULE
*     @{
*/
/*=================================================================================================
*     Project              : AUTOSAR 4.2 MCAL
*     Platform             : ARM
*     Peripheral           : CRCV2
*     Dependencies         : none
*     
*     Autosar Version      : 4.2.2
*     Autosar Revision     : ASR_REL_4_2_REV_0002
*     Autosar Conf.Variant :
*     SW Version           : 1.0.1
*     Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*     
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
=================================================================================================*/
/*=================================================================================================
==================================================================================================*/

#ifndef CRCU_REG_ESYS_CRCV2_H
#define CRCU_REG_ESYS_CRCV2_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_Reg_eSys_Crcv2_h_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported forexternal identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section Crcu_Reg_eSys_Crcv2_h_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_Reg_eSys_Crcv2_h_REF_3
*          Violates MISRA 2004 Required Rule 8.12, Array size not defined.
*          CRC_BASE_ADDR32 size is different based on configuration. 
*
* @section Crcu_Reg_eSys_Crcv2_h_REF_4 
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Functions like macros are used to reduce code complexity.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
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
#define CRCU_REGESYS_CRCV2_VENDOR_ID                    43
/** @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_REGESYS_CRCV2_AR_RELEASE_MAJOR_VERSION     4
/** @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_REGESYS_CRCV2_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_REGESYS_CRCV2_AR_RELEASE_REVISION_VERSION  2
#define CRCU_REGESYS_CRCV2_SW_MAJOR_VERSION             1
#define CRCU_REGESYS_CRCV2_SW_MINOR_VERSION             0
#define CRCU_REGESYS_CRCV2_SW_PATCH_VERSION             1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Reg_eSys.h version check */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CRCU_REGESYS_CRCV2_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (CRCU_REGESYS_CRCV2_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Crcu_Reg_eSys_Crcv2.h and Reg_eSys.h are different"
    #endif
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
#define CRCU_START_SEC_CONST_32
/** @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

/**
* @brief CRC units base address array declaration
*/
/** @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_3 Array size not defined */
extern CONST(uint32, CRCU_CONST) CRC_BASE_ADDR32[];

#define CRCU_STOP_SEC_CONST_32
/** @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Crcu_MemMap.h"

/*=================================================================================================
*                                       DEFINES AND MACROS
=================================================================================================*/
/* @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define CRCV2_HW_UNIT_U8(channel)               ((uint8)((channel)/CRCU_NUM_CRC_CHANNELS_PER_HW_UNIT_U8))
/* @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define CRCV2_HW_CH_U8(channel)                 ((uint8)((channel)%CRCU_NUM_CRC_CHANNELS_PER_HW_UNIT_U8))
    
/* CRCV2 DATA register */ 
/* @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define CRCV2_DATA_ADDR32(channel)              ((uint32)CRC_BASE_ADDR32[CRCV2_HW_UNIT_U8(channel)] + (uint32)0x0U)
    
/* CRCV2 GPOLY register */
/* @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define CRCV2_GPOLY_ADDR32(channel)             ((uint32)CRC_BASE_ADDR32[CRCV2_HW_UNIT_U8(channel)] + (uint32)0x4U)
    
/* CRCV2 CTRL register */
/* @violates @ref Crcu_Reg_eSys_Crcv2_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/ 
#define CRCV2_CTRL_ADDR32(channel)              ((uint32)CRC_BASE_ADDR32[CRCV2_HW_UNIT_U8(channel)] + (uint32)0x8U)
    
/* CRCV2 CTRL register bitfields offsets */
#define CRCV2_CTRL_TOT_OFFSET_U32               ((uint32)(30))
#define CRCV2_CTRL_TOTR_OFFSET_U32              ((uint32)(28))
#define CRCV2_CTRL_FXOR_OFFSET_U32              ((uint32)(26))
#define CRCV2_CTRL_WAS_OFFSET_U32               ((uint32)(25))
#define CRCV2_CTRL_TCRC_OFFSET_U32              ((uint32)(24))

/* CRCV2 CTRL register bitfields masks and values */
#define CRCV2_CTRL_TOT_NOSWAP_U32               ((uint32)(0x0) << CRCV2_CTRL_TOT_OFFSET_U32)
#define CRCV2_CTRL_TOT_BITSWAP_U32              ((uint32)(0x1) << CRCV2_CTRL_TOT_OFFSET_U32)
#define CRCV2_CTRL_TOT_BITANDBYTESWAP_U32       ((uint32)(0x2) << CRCV2_CTRL_TOT_OFFSET_U32)
#define CRCV2_CTRL_TOT_BYTESWAP_U32             ((uint32)(0x3) << CRCV2_CTRL_TOT_OFFSET_U32)
#define CRCV2_CTRL_TOT_MASK_U32                 ((uint32)(0x3) << CRCV2_CTRL_TOT_OFFSET_U32)

#define CRCV2_CTRL_TOTR_NOSWAP_U32              ((uint32)(0x0) << CRCV2_CTRL_TOTR_OFFSET_U32)
#define CRCV2_CTRL_TOTR_BITSWAP_U32             ((uint32)(0x1) << CRCV2_CTRL_TOTR_OFFSET_U32)
#define CRCV2_CTRL_TOTR_BITANDBYTESWAP_U32      ((uint32)(0x2) << CRCV2_CTRL_TOTR_OFFSET_U32)
#define CRCV2_CTRL_TOTR_BYTESWAP_U32            ((uint32)(0x3) << CRCV2_CTRL_TOTR_OFFSET_U32)
#define CRCV2_CTRL_TOTR_MASK_U32                ((uint32)(0x3) << CRCV2_CTRL_TOTR_OFFSET_U32)

#define CRCV2_CTRL_FXOR_NO_INVERSION_U32        ((uint32)(0x0) << CRCV2_CTRL_FXOR_OFFSET_U32)
#define CRCV2_CTRL_FXOR_INVERSION_U32           ((uint32)(0x1) << CRCV2_CTRL_FXOR_OFFSET_U32)
#define CRCV2_CTRL_FXOR_MASK_U32                ((uint32)(0x1) << CRCV2_CTRL_FXOR_OFFSET_U32)

#define CRCV2_CTRL_WAS_DATA_U32                 ((uint32)(0x0) << CRCV2_CTRL_WAS_OFFSET_U32)
#define CRCV2_CTRL_WAS_SEED_U32                 ((uint32)(0x1) << CRCV2_CTRL_WAS_OFFSET_U32)
#define CRCV2_CTRL_WAS_MASK_U32                 ((uint32)(0x1) << CRCV2_CTRL_WAS_OFFSET_U32)

#define CRCV2_CTRL_TCRC_WIDTH_16_U32            ((uint32)(0x0) << CRCV2_CTRL_TCRC_OFFSET_U32)
#define CRCV2_CTRL_TCRC_WIDTH_32_U32            ((uint32)(0x1) << CRCV2_CTRL_TCRC_OFFSET_U32)
#define CRCV2_CTRL_TCRC_MASK_U32                ((uint32)(0x1) << CRCV2_CTRL_TCRC_OFFSET_U32)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* CRCU_REG_ESYS_CRCV2_H */

/** @} */
