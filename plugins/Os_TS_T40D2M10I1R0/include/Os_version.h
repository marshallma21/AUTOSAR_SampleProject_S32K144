/**
*   @file    Os_version.h
*   @version 1.0.1
*
*   @brief   AUTOSAR OS - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup [OS]
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

#ifndef OS_VERSION_H
#define OS_VERSION_H


#ifdef __cplusplus
extern "C"
{
#endif

#define OS_VENDOR_ID                    43    /* Freescale AUTOSAR Vendor ID  */
#define OS_MODULE_ID                    0x01   /* OS Module ID                 */

#define OS_AR_RELEASE_MAJOR_VERSION     4   /* Major version number of AUTOSAR specification       */
#define OS_AR_RELEASE_MINOR_VERSION     2   /* Minor version number of AUTOSAR specification       */
#define OS_AR_RELEASE_REVISION_VERSION  2   /* Patch level version number of AUTOSAR specification */

#define OS_SW_MAJOR_VERSION             1   /* Major version number of the implementation   */
#define OS_SW_MINOR_VERSION             0   /* Minor version number of the implementation   */
#define OS_SW_PATCH_VERSION             1    /* Patch level version number of the implementation */



#ifdef __cplusplus
}
#endif



#endif /*OS_VERSION_H*/

/** @} */

