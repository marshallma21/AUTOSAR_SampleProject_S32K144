/**
*   @file Wdg_EnvCfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - contains the configuration data of the ICU driver
*   @details Contains the configuration data of the ICU driver
*
*   @addtogroup WDG_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Wdog
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

#ifndef WDG_ENVCFG_H
#define WDG_ENVCFG_H

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
#define WDG_ENVCFG_VENDOR_ID                        43

#define WDG_ENVCFG_AR_RELEASE_MAJOR_VERSION         4
#define WDG_ENVCFG_AR_RELEASE_MINOR_VERSION         2
#define WDG_ENVCFG_AR_RELEASE_REVISION_VERSION      2

#define WDG_ENVCFG_SW_MAJOR_VERSION                 1
#define WDG_ENVCFG_SW_MINOR_VERSION                 0
#define WDG_ENVCFG_SW_PATCH_VERSION                 1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define WDG_QM   (STD_OFF)
#define WDG_FTE  (STD_ON)
#define WDG_GTE  (STD_OFF)
#define WDG_NTE  (STD_OFF)

#if (WDG_FTE == STD_ON)
 #define WDG_VALIDATE_GLOBAL_CALL         (WDG_DEV_ERROR_DETECT)
 #define WDG_VALIDATE_PARAMS              (WDG_DEV_ERROR_DETECT)
#endif

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

#endif /* WDG_ENVCFG_H */
