/**
*   @file    Reg_eSys_Eirm.h
*   @implements     Reg_eSys_Eirm.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MEMU register definitions
*   @details MEMU HW-related definitions
*
*   @addtogroup MCEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Eim Erm
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

#ifndef REG_ESYS_MEMU_H
#define REG_ESYS_MEMU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 *
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcem_Eirm_Types_h_REF_1
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions shall
 * not be reused. Ipv name start with letter E which is reserved for Error status. However, EIRM is unique. 
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

#define EIRM_REG_VENDOR_ID                    43
#define EIRM_REG_AR_RELEASE_MAJOR_VERSION     4
#define EIRM_REG_AR_RELEASE_MINOR_VERSION     2
#define EIRM_REG_AR_RELEASE_REVISION_VERSION  2
#define EIRM_REG_SW_MAJOR_VERSION             1
#define EIRM_REG_SW_MINOR_VERSION             0
#define EIRM_REG_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Reg_eSys.h header file are the same Autosar version */
    #if ((EIRM_REG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (EIRM_REG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_Memu.h Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*
*  EIM Module configuration register
*/
#define EIRM_EIM_CONFIG_REG_ADDR32              ((uint32)(EIM_BASEADDR + (uint32)0x000U))
/*
*  EIM channel enable register
*/
#define EIRM_EIM_EICHEN_ADDR32                  ((uint32)(EIM_BASEADDR + (uint32)0x004U))
/*
*  EIM Error Injection channel descriptor 0, word 0
*/
#define EIRM_EIM_EICH0_WORD0_ADDR32             ((uint32)(EIM_BASEADDR + (uint32)0x100U))
/*
*  EIM Error Injection channel descriptor 0, word 1
*/
#define EIRM_EIM_EICH0_WORD1_ADDR32             ((uint32)(EIM_BASEADDR + (uint32)0x104U))
/*
*  EIM Error Injection channel descriptor 1, word 0
*/
#define EIRM_EIM_EICH1_WORD0_ADDR32             ((uint32)(EIM_BASEADDR + (uint32)0x200U))
/*
*  EIM Error Injection channel descriptor 1, word 1
*/
#define EIRM_EIM_EICH1_WORD1_ADDR32             ((uint32)(EIM_BASEADDR + (uint32)0x204U))


/*
*  EIM Module configuration register
*/
#define EIRM_ERM_CONFIG_REG_ADDR32              ((uint32)(ERM_BASEADDR + (uint32)0x000U))
/*
*  EIM channel enable register
*/
#define EIRM_ERM_STATUS_REG_ADDR32              ((uint32)(ERM_BASEADDR + (uint32)0x010U))
/*
*  EIM Error Injection channel descriptor 0, word 0
*/
#define EIRM_ERM_ERR_ADDR0_ADDR32               ((uint32)(ERM_BASEADDR + (uint32)0x100U))
/*
*  EIM Error Injection channel descriptor 0, word 1
*/
#define EIRM_ERM_ERR_ADDR1_ADDR32               ((uint32)(ERM_BASEADDR + (uint32)0x110U))

/* this section for register */
#define MCEM_EIRM_EIM_ENABLE_U32        ((uint32)0x00000001U)
#define MCEM_EIRM_EIM_DISABLE_U32       ((uint32)0x00000000U)
#define EIRM_EIM_EICHEN_CH0_U32     ((uint32)0x80000000U)
#define EIRM_EIM_EICHEN_CH1_U32     ((uint32)0x40000000U)
#define EIRM_ERM_STATUS_MASK_U32    ((uint32)0xCC000000U)
#define MCEM_EIRM_LOWER_MAX         1U
#define MCEM_EIRM_UPPER_MAX         3U


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

#endif /*REG_ESYS_MEMU_H*/

/** @} */
