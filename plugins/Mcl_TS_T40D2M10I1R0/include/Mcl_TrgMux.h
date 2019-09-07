/**
*   @file    Mcl_TrgMux.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - TrgMux Low level driver header file.
*   @details TrgMux module low level driver.
*
*   @addtogroup MCL
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

#ifndef MCL_TRGMUX_H
#define MCL_TRGMUX_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_TRGMUX_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section Mcl_TRGMUX_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          The macro was preferred instead of functions because of the runtime advantage.
*
* @section Mcl_TRGMUX_h_REF_3
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined a block scope if they are accessed
*          from a single function.This is neccessairy because of MCAL architecture.The variable is defined
*          in a specific file, not in the generic file where it is used.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Mcl_TRGMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Std_Types.h"
/**
* @violates @ref Mcl_TRGMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_TrgMux_Types.h"
#include "Reg_eSys_TrgMux.h"
#include "CDD_Mcl_Cfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_TrgMux.h
*/
#define MCL_TRGMUX_VENDOR_ID                      43
#define MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION       4
#define MCL_TRGMUX_AR_RELEASE_MINOR_VERSION       2
#define MCL_TRGMUX_AR_RELEASE_REVISION_VERSION    2
#define MCL_TRGMUX_SW_MAJOR_VERSION               1
#define MCL_TRGMUX_SW_MINOR_VERSION               0
#define MCL_TRGMUX_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (MCL_TRGMUX_VENDOR_ID != TRGMUX_REG_VENDOR_ID)
    #error "Mcl_TrgMux.h and Reg_eSys_TrgMux.h have different vendor IDs"
#endif
/* Check if Mcl_Dma header file and Reg_eSys are of the same Autosar version */
#if ((MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION != TRGMUX_REG_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TRGMUX_AR_RELEASE_MINOR_VERSION != TRGMUX_REG_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TRGMUX_AR_RELEASE_REVISION_VERSION != TRGMUX_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_TrgMux.h and Reg_eSys_TrgMux.h are different"
#endif
/* Check if Mcl_Dma header file and Reg_eSys are of the same Software version */
#if ((MCL_TRGMUX_SW_MAJOR_VERSION != TRGMUX_REG_SW_MAJOR_VERSION) || \
     (MCL_TRGMUX_SW_MINOR_VERSION != TRGMUX_REG_SW_MINOR_VERSION) || \
     (MCL_TRGMUX_SW_PATCH_VERSION != TRGMUX_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_TrgMux.h and Reg_eSys_TrgMux.h are different"
#endif

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_TRGMUX_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcl_TrgMux.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Mcl_TrgMux_Types.h header file are of the same vendor */
#if (MCL_TRGMUX_VENDOR_ID != MCL_TRGMUX_TYPES_VENDOR_ID)
    #error "Mcl_TrgMux.h and Mcl_TrgMux_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_TrgMux_Types.h header file are of the same Autosar version */
#if ((MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION    != MCL_TRGMUX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TRGMUX_AR_RELEASE_MINOR_VERSION    != MCL_TRGMUX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TRGMUX_AR_RELEASE_REVISION_VERSION != MCL_TRGMUX_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_TrgMux.h and Mcl_TrgMux_Types.h are different"
#endif
/* Check if header file and Mcl_TrgMux_Types.h header file are of the same software version */
#if ((MCL_TRGMUX_SW_MAJOR_VERSION != MCL_TRGMUX_TYPES_SW_MAJOR_VERSION) || \
     (MCL_TRGMUX_SW_MINOR_VERSION != MCL_TRGMUX_TYPES_SW_MINOR_VERSION) || \
     (MCL_TRGMUX_SW_PATCH_VERSION != MCL_TRGMUX_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_TrgMux.h and Mcl_TrgMux_Types.h are different"
#endif

 /* Check if header file and MCL configuration header file are of the same vendor */
#if (MCL_TRGMUX_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "Mcl_TrgMux.h and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and MCL configuration header file are of the same Autosar version */
#if ((MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_TRGMUX_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_TRGMUX_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcl_TrgMux.h and CDD_Mcl_Cfg.h are different"
#endif
/* Check if header file and MCL configuration header file are of the same software version */
#if ((MCL_TRGMUX_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_TRGMUX_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_TRGMUX_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcl_TrgMux.h and CDD_Mcl_Cfg.hare different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* size of the TRGMUX registers */
#define TRGMUX_REGSIZE           (4U)
/* number of bits to shift the SEL field */
#define TRGMUX_BITS_TO_SHIFT     (8U)

/* register address depending on the registerIndex - address of registers DMAMUXCH0, XB_OUT0_3, ADC0, etc. */
 /* @violates @ref Mcl_TRGMUX_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define TRGMUX_REG_ADDR(registerIndex) \
        ((TRGMUX_BASEADDR + (uint32)(TRGMUX_REGSIZE * (uint32)(registerIndex))))
        
/* mask of the sel input selected : mask of sel0 or sel1 or sel2 or sel3 */ 
 /* @violates @ref Mcl_TRGMUX_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */       
#define TRGMUX_REG_SEL_MASK(sel) \
        (TRGMUX_SEL0_MASK_U32 << (TRGMUX_BITS_TO_SHIFT * (sel)))

/* macro used to set the value val in the SEL field defined by a register */
 /* @violates @ref Mcl_TRGMUX_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */   
#define TRGMUX_CONFIG_SEL(registerIndex, sel, val) \
        (REG_RMW32( \
                 (uint32)TRGMUX_REG_ADDR(registerIndex), \
                 TRGMUX_REG_SEL_MASK(sel), \
                 ((val)<< (TRGMUX_BITS_TO_SHIFT * (sel))) \
                 )\
         )
        
/* macro to enable or disable lock of a register */   
 /* @violates @ref Mcl_TRGMUX_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */        
#define TRGMUX_ENABLE_LOCK(registerIndex) \
        (REG_RMW32( \
                 (uint32)TRGMUX_REG_ADDR(registerIndex), \
                 TRGMUX_LK_BIT_MASK_U32, \
                 TRGMUX_LK_BIT_MASK_U32 \
                 ) \
        )
/* read lock value from register */
 /* @violates @ref Mcl_TRGMUX_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */   
#define TRGMUX_READ_LOCK(registerIndex) \
        ((uint32)(((uint32)REG_READ32((uint32)(TRGMUX_REG_ADDR(registerIndex))) & TRGMUX_LK_BIT_MASK_U32) >> TRGMUX_LOCK_SHIFT_U32))

/* return if register is locked */
 /* @violates @ref Mcl_TRGMUX_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined */   
#define TRGMUX_GET_LOCK(registerIndex) \
        ((TRGMUX_READ_LOCK(registerIndex) == (uint32)TRGMUX_LOCK_EN_U32) ? (TRUE) : (FALSE))
        
/* maximum number of registers which are missing sel1, sel2 and sel3 */
#define MCL_TRGMUX_MAX_IDX        10
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#if (MCL_DEV_ERROR_DETECT == STD_ON)
#define MCL_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_TRGMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

 /* @violates @ref Mcl_TRGMUX_h_REF_3  MISRA 2004 Advisory Rule 8.7, Objects shall be defined at block*/ 
extern CONST(Mcl_TrgMuxRegisterIndexType, MCL_CONST) Mcl_TrgMux_RegistersOneInput[MCL_NUM_REG_MISSING_SEL_FIELD];

#define MCL_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_TRGMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_TRGMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"
      
FUNC(void, MCL_CODE) Mcl_TrgMux_Init( P2CONST(Mcl_TrgMuxConfigType, MCL_VAR, MCL_APPL_VAR)   pTrgMuxConfig);   
FUNC(void, MCL_CODE) Mcl_TrgMux_Config_Sel(Mcl_TrgMuxRegisterIndexType TrgMuxRegInput, Mcl_TrgMuxSelectionNrType SelectNum, Mcl_TrgMuxRegisterType Sourceinput);
FUNC(void, MCL_CODE) Mcl_TrgMux_Enable_Lock(Mcl_TrgMuxRegisterIndexType TrgMuxRegInput);
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_TRGMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCL_TRGMUX_H */

/** @} */
