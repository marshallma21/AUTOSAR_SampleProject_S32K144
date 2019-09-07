/**
*   @file    Reg_eSys_SMC.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef REG_ESYS_SMC_H
#define REG_ESYS_SMC_H


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
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_SMC_VENDOR_ID                       43
#define REG_ESYS_SMC_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_SMC_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_SMC_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_SMC_SW_MAJOR_VERSION                1
#define REG_ESYS_SMC_SW_MINOR_VERSION                0
#define REG_ESYS_SMC_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_SMC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_SMC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_SMC.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/********** SMC Registers **********/

/* SMC_VERID - SMC Version ID Register */
#define SMC_VERID_ADDR32                     ((uint32)(SMC_BASEADDR + (uint32)0x00000000U))
/* SMC_PARAM - SMC Parameter Register */
#define SMC_PARAM_ADDR32                     ((uint32)(SMC_BASEADDR + (uint32)0x00000004U))
/* SMC_PMPROT - Power Mode Protection register */
#define SMC_PMPROT_ADDR32                    ((uint32)(SMC_BASEADDR + (uint32)0x00000008U))
/* SMC_PMCTRL - Power Mode Control register */
#define SMC_PMCTRL_ADDR32                    ((uint32)(SMC_BASEADDR + (uint32)0x0000000CU))
/* SMC_STOPCTRL - Stop Control Register */
#define SMC_STOPCTRL_ADDR32                  ((uint32)(SMC_BASEADDR + (uint32)0x00000010U))
/* SMC_PMSTAT - Power Mode Status register */
#define SMC_PMSTAT_ADDR32                    ((uint32)(SMC_BASEADDR + (uint32)0x00000014U))

/****************************************************/
/***              SMC_PMPROT                      ***/
/****************************************************/
#define SMC_PMPROT_RWBITS_MASK32            ((uint32)0x000000A0U)

#define SMC_PMPROT_AHSRUN_MASK32            ((uint32)0x00000080U)
#define SMC_PMPROT_AVLP_MASK32              ((uint32)0x00000020U)

#define SMC_PMPROT_HSRUN_ALLOWED_U32        (SMC_PMPROT_AHSRUN_MASK32)
#define SMC_PMPROT_HSRUN_NOT_ALLOWED_U32    ((uint32)0x00000000U)

#define SMC_PMPROT_VLP_ALLOWED_U32          (SMC_PMPROT_AVLP_MASK32)
#define SMC_PMPROT_VLP_NOT_ALLOWED_U32      ((uint32)0x00000000U)

/****************************************************/
/***              SMC_PMCTRL                      ***/
/****************************************************/
#define SMC_PMCTRL_RWBITS_MASK32            ((uint32)0x00000067U)

#define SMC_PMCTRL_RUNM_MASK32              ((uint32)0x00000060U)
#define SMC_PMCTRL_STOPA_MASK32             ((uint32)0x00000008U)
#define SMC_PMCTRL_STOPM_MASK32             ((uint32)0x00000007U)

#define SMC_PMCTRL_RUN_MODE_U32             ((uint32)0x00000000U)
#define SMC_PMCTRL_VLPR_MODE_U32            ((uint32)0x00000040U)
#define SMC_PMCTRL_HSRUN_MODE_U32           ((uint32)0x00000060U)

#define SMC_PMCTRL_STOP_U32                 ((uint32)0x00000000U)
#define SMC_PMCTRL_VLPS_U32                 ((uint32)0x00000002U)

/****************************************************/
/***              SMC_STOPCTRL                    ***/
/****************************************************/
#define SMC_STOPCTRL_RWBITS_MASK32         ((uint32)0x000000C0U)

#define SMC_STOPCTRL_PSTOP0_MASK32         ((uint32)0x000000C0U)

#define SMC_STOPCTRL_STOP1_U32            ((uint32)0x00000040U)
#define SMC_STOPCTRL_STOP2_U32            ((uint32)0x00000080U)

/****************************************************/
/***              SMC_PMSTAT                      ***/
/****************************************************/
#define SMC_PMSTAT_RWBITS_MASK32        ((uint32)0x00000000U)

#define SMC_PMSTAT_PMSTAT_MASK32        ((uint32)0x000000FFU)

#define SMC_PMSTAT_RUN_U32              ((uint32)0x00000001U)
#define SMC_PMSTAT_VLPR_U32             ((uint32)0x00000004U)
#define SMC_PMSTAT_VLPW_U32             ((uint32)0x00000008U)
#define SMC_PMSTAT_VLPS_U32             ((uint32)0x00000010U)
#define SMC_PMSTAT_HSRUN_U32            ((uint32)0x00000080U)

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

#endif /* REG_ESYS_SMC_H */

/** @} */
