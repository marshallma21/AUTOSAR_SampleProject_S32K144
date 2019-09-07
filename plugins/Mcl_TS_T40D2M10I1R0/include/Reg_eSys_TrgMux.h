/**
*   @file    Reg_eSys_TrgMux.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - TrgMux registers and macros definitions.
*   @details TrgMux registers and macros definitions.
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

#ifndef REG_ESYS_TRGMUX_H
#define REG_ESYS_TRGMUX_H

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
*
* @section REG_ESYS_TRGMUX_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* 
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref REG_ESYS_TRGMUX_H_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Reg_eSys.h"

/**
* @violates @ref REG_ESYS_TRGMUX_H_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "StdRegMacros.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_TrgMux.h
* @requirements   
*/
#define TRGMUX_REG_VENDOR_ID                      43
#define TRGMUX_REG_AR_RELEASE_MAJOR_VERSION       4
#define TRGMUX_REG_AR_RELEASE_MINOR_VERSION       2
#define TRGMUX_REG_AR_RELEASE_REVISION_VERSION    2
#define TRGMUX_REG_SW_MAJOR_VERSION               1
#define TRGMUX_REG_SW_MINOR_VERSION               0
#define TRGMUX_REG_SW_PATCH_VERSION               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != TRGMUX_REG_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != TRGMUX_REG_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys.h and Reg_eSys_TrgMux.h are different"
    #endif
#endif

/* Check if header file and StdRegMacros.h header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((TRGMUX_REG_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (TRGMUX_REG_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Reg_eSys_TrgMux.h and StdRegMacros.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** TRGMUX masks */
/** mask for SEL0 bits */
#define TRGMUX_SEL0_MASK_U32          ((uint32)(0x0000007FUL))
/** mask for SEL1 bits */
#define TRGMUX_SEL1_MASK_U32          ((uint32)(0x00007F00UL))
/** mask for SEL2 bits */
#define TRGMUX_SEL2_MASK_U32          ((uint32)(0x007F0000UL))
/** mask for SEL3 bits */
#define TRGMUX_SEL3_MASK_U32          ((uint32)(0x7F000000UL))
/** mask for LK bit */
#define TRGMUX_LK_BIT_MASK_U32        ((uint32)(0x80000000UL))

/** TRGMUX values for shift bits */
#define TRGMUX_SEL0_SHIFT_U32           ((uint32)(0U))
#define TRGMUX_SEL1_SHIFT_U32           ((uint32)(8U))
#define TRGMUX_SEL2_SHIFT_U32           ((uint32)(16U))
#define TRGMUX_SEL3_SHIFT_U32           ((uint32)(24U))
#define TRGMUX_LOCK_SHIFT_U32           ((uint32)(31U))

/** TRGMUX  values of the LK bit */
#define TRGMUX_LOCK_EN_U32               ((uint32)(1U))
#define TRGMUX_LOCK_DIS_U32              ((uint32)(0U))
/*==================================================================================================
*                                             ENUMS
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

#endif /* REG_ESYS_TRGMUX_H */

/** @} */
