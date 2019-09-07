/**
*   @file    Mcu_EnvCfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Driver external interface.
*   @details Contains all the public functions and data types that are used by the higher layer.
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


#ifndef MCU_SCFG_H
#define MCU_SCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section MCU_SCFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section MCU_SCFG_H_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section MCU_SCFG_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters.The used compilers use more than 31 chars for
* identifiers.
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
/**
* @file           Mcu.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCU_SCFG_VENDOR_ID                        43
#define MCU_SCFG_AR_RELEASE_MAJOR_VERSION         4
#define MCU_SCFG_AR_RELEASE_MINOR_VERSION         2
#define MCU_SCFG_AR_RELEASE_REVISION_VERSION      2
#define MCU_SCFG_SW_MAJOR_VERSION                 1
#define MCU_SCFG_SW_MINOR_VERSION                 0
#define MCU_SCFG_SW_PATCH_VERSION                 1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* External environment the Mcu driver currently supports */
#define MCU_FTE (STD_ON)

/* FTE environment */
#define MCU_PERIODIC_CHECKS             (MCU_FTE)
#define MCU_PARAM_CHECK                 (MCU_DEV_ERROR_DETECT)

/* high level defines */
#define MCU_VALIDATE_GLOBAL_CALL        (MCU_DEV_ERROR_DETECT)
#define MCU_USER_MODE_REG_PROT_ENABLED  (STD_OFF)

/** @violates @ref MCU_SCFG_H_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macros are used to avoid compiler warnings on unused function parameters. */
#define MCU_PARAM_UNUSED(param)         ((void)((param)))

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

#endif /* MCU_SCFG_H */

/** @} */
