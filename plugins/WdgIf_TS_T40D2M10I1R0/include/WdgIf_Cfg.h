/**
*   @file    WdgIf_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR WdgIf - Interface Configuration header file.
*   @details Contains information about Interface Configuration header file.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : generic
*   Dependencies         : 
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

#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H

#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDGIF_VENDOR_ID_CFG                   43
#define WDGIF_MODULE_ID_CFG                   43
#define WDGIF_AR_RELEASE_MAJOR_VERSION_CFG    4
#define WDGIF_AR_RELEASE_MINOR_VERSION_CFG    2
#define WDGIF_AR_RELEASE_REVISION_VERSION_CFG 2
#define WDGIF_SW_MAJOR_VERSION_CFG            1
#define WDGIF_SW_MINOR_VERSION_CFG            0
#define WDGIF_SW_PATCH_VERSION_CFG            1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** 
*   @brief  Compile switch to enable/disable development error detection for this module
*/
#define WDGIF_DEV_ERROR_DETECT   (STD_ON)

/** 
*   @brief  Constant specifying the number of controlled watchdog drivers
*/
#define WDGIF_NUMBER_OF_DEVICES   WDG_NO_OF_INSTANCES

/** 
*   @brief  Compile switch to enable/disable the version information
*/
#define WDGIF_VERSION_INFO_API   (STD_ON)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*WDGIF_CFG_H*/

/** @} */
