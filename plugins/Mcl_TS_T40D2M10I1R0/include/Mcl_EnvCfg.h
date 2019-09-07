/**
*   @file Mcl_EnvCfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - contains the environment configuration data of the MCL driver
*   @details Contains the configuration data of the MCL driver
*
*   @addtogroup MCL_MODULE
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

#ifndef MCL_ENVCFG_H
#define MCL_ENVCFG_H

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
*/
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_ENVCFG_VENDOR_ID                        43

#define MCL_ENVCFG_AR_RELEASE_MAJOR_VERSION         4
#define MCL_ENVCFG_AR_RELEASE_MINOR_VERSION         2
#define MCL_ENVCFG_AR_RELEASE_REVISION_VERSION      2

#define MCL_ENVCFG_SW_MAJOR_VERSION                 1
#define MCL_ENVCFG_SW_MINOR_VERSION                 0
#define MCL_ENVCFG_SW_PATCH_VERSION                 1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define MCL_QM   (STD_OFF)
#define MCL_FTE  (STD_ON)
#define MCL_GTE  (STD_OFF)
#define MCL_NTE  (STD_OFF)


#define MCL_VALIDATE_GLOBAL_CALL         (MCL_DEV_ERROR_DETECT)
#define MCL_VALIDATE_CALL_AND_CHANNEL    (MCL_DEV_ERROR_DETECT)
#define MCL_VALIDATE_PARAMS              (MCL_DEV_ERROR_DETECT)
#define MCL_REPORT_UNEXPECTED_ISR        (MCL_DEV_ERROR_DETECT)

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


#endif /* MCL_ENVCFG_H */
