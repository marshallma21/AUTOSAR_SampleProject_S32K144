/**
*   @file    Lin_IPW.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
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

#ifndef LIN_IPW_H
#define LIN_IPW_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_Ipw_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Lin_Ipw_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Lin_Ipw_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The compiler/linker shall be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @violates @ref Lin_Ipw_h_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_IPW_VENDOR_ID                    43
#define LIN_AR_RELEASE_MAJOR_VERSION_IPW     4
#define LIN_AR_RELEASE_MINOR_VERSION_IPW     2
/*
* @violates @ref Lin_Ipw_h_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_IPW  2
#define LIN_SW_MAJOR_VERSION_IPW             1
#define LIN_SW_MINOR_VERSION_IPW             0
#define LIN_SW_PATCH_VERSION_IPW             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
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
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_Ipw_h_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_Ipw_h_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
FUNC(Std_ReturnType, LIN_CODE) Lin_Ipw_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel);

FUNC(void, LIN_CODE) Lin_Ipw_InitChannel(CONST(uint8, AUTOMATIC) u8Channel);

FUNC(Std_ReturnType, LIN_CODE) Lin_Ipw_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pcPduInfoPtr);

FUNC(void, LIN_CODE) Lin_Ipw_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pcPduInfoPtr);

FUNC(Std_ReturnType, LIN_CODE) Lin_Ipw_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel);

FUNC(Std_ReturnType, LIN_CODE) Lin_Ipw_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel);

FUNC(Lin_StatusType, LIN_CODE) Lin_Ipw_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr);

FUNC(void, LIN_CODE) Lin_Ipw_WakeUp(CONST(uint8, AUTOMATIC) u8Channel);

 FUNC (void, LIN_CODE) Lin_Ipw_WakeUpInternal(CONST(uint8, AUTOMATIC) u8Channel);
 
#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_Ipw_h_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_Ipw_h_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* LIN_IPW_H */

/** @} */
