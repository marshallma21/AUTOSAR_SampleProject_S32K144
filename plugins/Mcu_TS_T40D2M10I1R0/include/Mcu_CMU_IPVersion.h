/**
*   @file    Mcu_CMU_IPVersion.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Platform version definitions, used inside IPV_CMU.
*   @details Public data types exported outside of the Mcu driver.
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

#ifndef MCU_CMU_IPVERSION_H
#define MCU_CMU_IPVERSION_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_CMU_IPVersion_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
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
/* none */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_CMU_IPVERSION_VENDOR_ID                       43
/** @violates @ref Mcu_CMU_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_CMU_IPVERSION_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Mcu_CMU_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_CMU_IPVERSION_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Mcu_CMU_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_CMU_IPVERSION_AR_RELEASE_REVISION_VERSION     2
#define MCU_CMU_IPVERSION_SW_MAJOR_VERSION                1
#define MCU_CMU_IPVERSION_SW_MINOR_VERSION                0
#define MCU_CMU_IPVERSION_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define IPV_CMU_00_00_00_01        (0x00000001U)

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

#endif /* MCU_CMU_IPVERSION_H */
