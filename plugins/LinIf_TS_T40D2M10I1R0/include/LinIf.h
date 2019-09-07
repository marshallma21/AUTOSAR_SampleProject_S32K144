/**
*   @file    LinIf.h
*   @version 1.0.1
*
*   @brief   AUTOSAR LinIf - AUTOSAR LinIf module interface.
*   @details AUTOSAR LinIf module interface.
*            This file contains sample code only. It is not part of the production code deliverables.
*
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
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

#ifndef LIN_IF_H
#define LIN_IF_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Lin_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section Lin_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Lin_C_REF_3
* Violates MISRA 2004 Advisory Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           LinIf.h
* @requirements   LINIF383
*/
#define LIN_IF_VENDOR_ID                      43
#define LIN_IF_MODULE_ID                      62
#define LIN_IF_AR_RELEASE_MAJOR_VERSION       4
#define LIN_IF_AR_RELEASE_MINOR_VERSION       2
#define LIN_IF_AR_RELEASE_REVISION_VERSION    2
#define LIN_IF_SW_MAJOR_VERSION               1
#define LIN_IF_SW_MINOR_VERSION               0
#define LIN_IF_SW_PATCH_VERSION               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/           

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

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

#endif /* LIN_IF_H */

/** @} */
