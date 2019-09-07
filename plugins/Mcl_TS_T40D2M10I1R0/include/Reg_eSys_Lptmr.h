/**
*   @file    Reg_eSys_Lptmr.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LPTMR driver header file.
*   @details LPTMR module register description.
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

#ifndef REG_ESYS_LPTMR_H
#define REG_ESYS_LPTMR_H

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
* @section REG_ESYS_LPTMR_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section REG_ESYS_LPTMR_H_REF_2
* Violates MISRA 2004 Required Rule 8.12, Array size not defined
* This violation is  due to the fact that this file is shared by multiple drivers: GPT, PWM and ICU.
* The array size depends by the number of eTimer modules used by all drivers. The eTimer common component
* driver doesn't have yet its own plugin which could be used to generate the common parameters.
*
* @section REG_ESYS_LPTMR_H_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
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
* @file           Reg_eSys_Lptmr.h
*/
#define REG_ESYS_LPTMR_VENDOR_ID                       43
#define REG_ESYS_LPTMR_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_LPTMR_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_LPTMR_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_LPTMR_SW_MAJOR_VERSION                1
#define REG_ESYS_LPTMR_SW_MINOR_VERSION                0
#define REG_ESYS_LPTMR_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_LPTMR_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_LPTMR_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Lptmr.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define MCL_START_SEC_CONST_32
/** @violates @ref REG_ESYS_LPTMR_H_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref REG_ESYS_LPTMR_H_REF_3 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief LPTMR base address array declaration
*/
/** @violates @ref REG_ESYS_LPTMR_H_REF_2 Array size not defined */
extern CONST(uint32, MCL_CONST) LPTMR_BASE_ADDR32[];

#define MCL_STOP_SEC_CONST_32
/** @violates @ref REG_ESYS_LPTMR_H_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref REG_ESYS_LPTMR_H_REF_3 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* LPTMR Registers */
#define LPTMR_CSR_ADDR32                      (LPTMR0_BASEADDR + (uint32)0x00UL)
#define LPTMR_PSR_ADDR32                      (LPTMR0_BASEADDR + (uint32)0x04UL)
#define LPTMR_CMR_ADDR32                      (LPTMR0_BASEADDR + (uint32)0x08UL)
#define LPTMR_CNR_ADDR32                      (LPTMR0_BASEADDR + (uint32)0x0CUL)


#define LPTMR_CSR_TDRE_MASK_U32                ((uint32)BIT8)
#define LPTMR_CSR_TDRE_SHIFT                   ((uint32)8U)
#define LPTMR_CSR_TCF_MASK_U32                 ((uint32)BIT7)
#define LPTMR_CSR_TCF_SHIFT                    ((uint32)7U)
#define LPTMR_CSR_TIE_MASK_U32                 ((uint32)BIT6)
#define LPTMR_CSR_TIE_SHIFT                    ((uint32)6U)
#define LPTMR_CSR_TPS_MASK_U32                 ((uint32)BIT5|BIT14)
#define LPTMR_CSR_TPS_SHIFT                    ((uint32)4U)
#define LPTMR_CSR_TPP_MASK_U32                 ((uint32)BIT3)
#define LPTMR_CSR_TPP_SHIFT                    ((uint32)3U)
#define LPTMR_CSR_TFC_MASK_U32                 ((uint32)BIT2)
#define LPTMR_CSR_TFC_SHIFT                    ((uint32)2U)
#define LPTMR_CSR_TMS_MASK_U32                 ((uint32)BIT1)
#define LPTMR_CSR_TMS_SHIFT                    ((uint32)1U)
#define LPTMR_CSR_TEN_MASK_U32                 ((uint32)BIT0)
#define LPTMR_CSR_TEN_SHIFT                    ((uint32)0U)

#define LPTMR_PSR_PRESCALE_MASK_U32            ((uint32)BIT6|BIT5|BIT4|BIT3)
#define LPTMR_PSR_PRESCALE_SHIFT               ((uint32)3U)
#define LPTMR_PSR_PBYP_MASK_U32                ((uint32)BIT2)
#define LPTMR_PSR_PBYP_SHIFT                   ((uint32)2U)
#define LPTMR_PSR_PCS_MASK_U32                 ((uint32)BIT1|BIT0)
#define LPTMR_PSR_PCS_SHIFT                    ((uint32)0U)

#define LPTMR_CSR_TCF_ON_U32                   ((uint32)1U)
#define LPTMR_CSR_TCF_OFF_U32                  ((uint32)0U)
#define LPTMR_CSR_TIE_ON_U32                   ((uint32)1U)
#define LPTMR_CSR_TIE_OFF_U32                  ((uint32)0U)

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

#endif /*REG_ESYS_LPTMR_H*/

/** @} */
