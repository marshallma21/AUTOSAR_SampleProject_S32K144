/**
*   @file    Fee_Cbk.h
*   @implements Fee_Cbk.h_Artifact   
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Callback Notifications.
*   @details Definitions of the callback functions Fee_JobEndNotification 
*            and Fee_JobErrorNotification.
*
*   @addtogroup FEE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : none
*   Dependencies         : Fls
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
#ifndef FEE_CBK_H
#define FEE_CBK_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_Cbk_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section Fee_Cbk_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR 
* requirement MEMMAP003.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/



/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @{
* @file           Fee_Cbk.h
* @brief          Source file version information
* 
*/
#define FEE_CBK_VENDOR_ID                       43
/** @violates @ref Fee_Cbk_H_REF_1 MISRA 2004 Rule 1.4, Identifier too long. */
#define FEE_CBK_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Fee_Cbk_H_REF_1 MISRA 2004 Rule 1.4, Identifier too long. */
#define FEE_CBK_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Fee_Cbk_H_REF_1 MISRA 2004 Rule 1.4, Identifier too long. */
#define FEE_CBK_AR_RELEASE_REVISION_VERSION     2
#define FEE_CBK_SW_MAJOR_VERSION                1
#define FEE_CBK_SW_MINOR_VERSION                0
#define FEE_CBK_SW_PATCH_VERSION                1
/** @} */


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define FEE_START_SEC_CODE
/* @violates @ref Fee_Cbk_h_REF_2 Repeatedly included but does not have a standard include guard */
#include "Fee_MemMap.h"

extern FUNC( void, FEE_CODE ) Fee_JobEndNotification( void );
extern FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void );

#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_Cbk_h_REF_2 Repeatedly included but does not have a standard include guard */
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* _FEE_CBK_H_ */
/** @} */
