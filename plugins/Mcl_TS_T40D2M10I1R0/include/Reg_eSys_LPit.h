/**
*   @file    Reg_eSys_LPit.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LPIT driver header file.
*   @details LPIT module register description.
*
*   @addtogroup GPT_MODULE
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

#ifndef REG_ESYS_LPIT_H
#define REG_ESYS_LPIT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section REG_ESYS_LPIT_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.

* @section REG_ESYS_LPIT_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section REG_ESYS_LPIT_H_REF_3
* Violates MISRA 2004 Required Rule 8.12, Array size not defined
* This violation is  due to the fact that this file is shared by multiple drivers: GPT, PWM and ICU.
* The array size depends by the number of eTimer modules used by all drivers. The eTimer common component
* driver doesn't have yet its own plugin which could be used to generate the common parameters.
*
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
/**
* @file           Reg_eSys_LPit.h
*/
#define REG_ESYS_LPIT_VENDOR_ID                       43
#define REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_LPIT_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_LPIT_SW_MAJOR_VERSION                1
#define REG_ESYS_LPIT_SW_MINOR_VERSION                0
#define REG_ESYS_LPIT_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_LPit.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define MCL_START_SEC_CONST_32
/** @violates @ref REG_ESYS_LPIT_H_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief LPIT base address array declaration
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_3 Array size not defined */
extern CONST(uint32, MCL_CONST) LPIT_BASE_ADDR32[];

#define MCL_STOP_SEC_CONST_32
/** @violates @ref REG_ESYS_LPIT_H_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_MODULE_INDEX_U32(ch)      (((ch) & LPIT_MOD_MASK_U8) >> LPIT_MOD_SHIFT)

/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_CHANNEL_INDEX_U32(ch)     (((ch) & LPIT_CH_MASK_U8)  >> LPIT_CH_SHIFT)

/* LPIT Registers */

/**
* @brief LPIT Module Control Registers (MCR)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_MCR_ADDR32(u8ModuleIdx)     (LPIT_BASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0008UL)

/**
* @brief LPIT Module Status Registers (MSR)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_MSR_ADDR32(u8ModuleIdx)     (LPIT_BASE_ADDR32[(u8ModuleIdx)] + (uint32)0x000CUL)
    
/**
* @brief LPIT Module Interrupt Enable Registers (MIER)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_MIER_ADDR32(u8ModuleIdx)    (LPIT_BASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0010UL)
    
/**
* @brief LPIT Set Timer Enable Register (MSR)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_SETTEN_ADDR32(u8ModuleIdx)         (LPIT_BASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0014UL)
    
/**
* @brief LPIT Clear Timer Enable Register (CLRTEN)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_CLRTEN_ADDR32(u8ModuleIdx)         (LPIT_BASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0018UL)

/**
* @brief Timer Load Value Register (TVAL)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_TVAL_ADDR32(u8ModuleIdx,u8ChannelIdx)     (LPIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x0020UL))

/**
* @brief Current Timer Value Register (CVAL)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_CVAL_ADDR32(u8ModuleIdx,u8ChannelIdx)     (LPIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x0024UL))

/**
* @brief Timer Control Register (TCTRL)  Register address
*/
/** @violates @ref REG_ESYS_LPIT_H_REF_1 Use of function like macro */
#define LPIT_TCTRL_ADDR32(u8ModuleIdx,u8ChannelIdx)    (LPIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x0028UL))


  /**
  * @brief LPIT registers - bitfield mask and shift defines.
  */
#define LPIT_MSR_TIF_MASK_U32                               ((uint32)(BIT0))
  
#define LPIT_MIER_TIE_MASK_U32                              ((uint32)(BIT0))

#define LPIT_TCTRL_TEN_MASK_U32                             ((uint32)(BIT0))
#define LPIT_TCTRL_MODE_MASK_U32                            ((uint32)(BIT3|BIT2))
#define LPIT_TCTRL_TRG_SRC_MASK_U32                         ((uint32)(BIT23))
#define LPIT_TCTRL_TRG_SRC_SHIFT                            ((uint32)(23UL))
#define LPIT_TCTRL_TRG_SEL_MASK_U32                         ((uint32)(BIT27|BIT26|BIT25|BIT24))
#define LPIT_TCTRL_TRG_SEL_SHIFT                            ((uint32)(24U))
#define LPIT_TCTRL_TRG_TROT_MASK_U32                        ((uint32)(BIT18))
#define LPIT_TCTRL_TRG_TROT_SHIFT                           ((uint32)(18U))
#define LPIT_TCTRL_TRG_TSOI_MASK_U32                        ((uint32)(BIT17))
#define LPIT_TCTRL_TRG_TSOI_SHIFT                           ((uint32)(17U))
#define LPIT_TCTRL_TRG_TSOT_MASK_U32                        ((uint32)(BIT16))
#define LPIT_TCTRL_TRG_TSOT_SHIFT                           ((uint32)(16U))

#define LPIT_MCR_MCEN_MASK_U32                              ((uint32)(BIT0))
#define LPIT_MCR_DBG_EN_SHIFT                               ((uint32)1UL)
#define LPIT_MCR_FRZ_MASK_U32                               ((uint32)(BIT3))
  
  
  /**
  * @brief LPIT registers - bitfield defines.
  */
#define LPIT_TFLG_TIF_ON_U32                             ((uint32)1UL)
#define LPIT_TFLG_TIF_OFF_U32                            ((uint32)0UL)
  
#define LPIT_TCTRL_TIE_ON_U32                            ((uint32)1UL)
#define LPIT_TCTRL_TIE_OFF_U32                           ((uint32)0UL)
#define LPIT_TCTRL_TEN_ON_U32                            ((uint32)1UL)
#define LPIT_TCTRL_TEN_OFF_U32                           ((uint32)0UL)

#define LPIT_MCR_MDIS_ON_U32                             ((uint32)1UL)
#define LPIT_MCR_MDIS_OFF_U32                            ((uint32)0UL)
#define LPIT_MCR_FRZ_ON_U32                              ((uint32)1UL)
#define LPIT_MCR_FRZ_OFF_U32                             ((uint32)0UL)


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

#endif /*REG_ESYS_LPIT_H*/

/** @} */
