/**
*   @file Port_EnvCfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Port - contains the configuration data of the PORT driver
*   @details Contains the configuration data of the PORT driver
*
*   @addtogroup PORT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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

#ifndef PORT_ENVCFG_H
#define PORT_ENVCFG_H

#ifdef __cplusplus
extern "C"{
#endif 

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
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

#define PORT_ENVCFG_VENDOR_ID                        43

#define PORT_ENVCFG_AR_RELEASE_MAJOR_VERSION         4
#define PORT_ENVCFG_AR_RELEASE_MINOR_VERSION         2
#define PORT_ENVCFG_AR_RELEASE_REVISION_VERSION      2

#define PORT_ENVCFG_SW_MAJOR_VERSION                 1
#define PORT_ENVCFG_SW_MINOR_VERSION                 0
#define PORT_ENVCFG_SW_PATCH_VERSION                 1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define PORT_PERIODIC_CHECK_API        (STD_OFF)
#define PORT_USER_MODE_SOFT_LOCKING    (STD_OFF)
#define PORT_SERR_NOTIFY_ERROR_ENABLE  (STD_OFF)

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

#endif /* PORT_ENVCFG_H */
