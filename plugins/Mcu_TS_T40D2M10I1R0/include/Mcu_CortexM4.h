/**
*   @file    Mcu_CortexM4.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - ARM CortexM4 Registers and Macros Definitions.
*   @details ARM CortexM4 Registers and Macros Definitions.
*
*   @addtogroup DMA_DRIVER
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

/**
@file        Mcu_CortexM4.h
*/


#ifndef MCU_CORTEXM4_H
#define MCU_CORTEXM4_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_CortexM4_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_CortexM4_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_CortexM4_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Cfg.h"
#include "Reg_eSys_CortexM4.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           CORTEXM4.h
* @requirements   
*/
#define MCU_CORTEXM4_VENDOR_ID                       43
#define MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION        4
#define MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION        2
#define MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION     2
#define MCU_CORTEXM4_SW_MAJOR_VERSION                1
#define MCU_CORTEXM4_SW_MINOR_VERSION                0
#define MCU_CORTEXM4_SW_PATCH_VERSION                1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Mcu_Cfg.h header file have same versions */
#if (MCU_CORTEXM4_VENDOR_ID != MCU_CFG_VENDOR_ID)
#error "Mcu_CortexM4.h and Mcu_Cfg.h have different vendor IDs"
#endif
#if ((MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_CortexM4.h and Mcu_Cfg.h are different"
#endif
#if ((MCU_CORTEXM4_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_CORTEXM4_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_CORTEXM4_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_CortexM4.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_CortexM4.h header file have same versions */
#if (MCU_CORTEXM4_VENDOR_ID != MCU_CFG_VENDOR_ID)
#error "Mcu_CortexM4.h and Mcu_Cfg.h have different vendor IDs"
#endif
#if ((MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION != REG_ESYS_CORTEXM4_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION != REG_ESYS_CORTEXM4_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION != REG_ESYS_CORTEXM4_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_CortexM4.h and Reg_eSys_CortexM4.h are different"
#endif
#if ((MCU_CORTEXM4_SW_MAJOR_VERSION != REG_ESYS_CORTEXM4_SW_MAJOR_VERSION) || \
     (MCU_CORTEXM4_SW_MINOR_VERSION != REG_ESYS_CORTEXM4_SW_MINOR_VERSION) || \
     (MCU_CORTEXM4_SW_PATCH_VERSION != REG_ESYS_CORTEXM4_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_CortexM4.h and Reg_eSys_CortexM4.h are different"
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS                                                  
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_CortexM4_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"




#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_CortexM4_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_CM4_EnableDeepSleep() \
do\
{ \
        Mcal_Trusted_Call(Mcu_CM4_EnableDeepSleep); \
}\
while(0)
#else
/** @violates @ref Mcu_CortexM4_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_CM4_EnableDeepSleep() \
do\
{ \
        Mcu_CM4_EnableDeepSleep(); \
}\
while(0)
#endif
#endif



#if (MCU_PERFORM_RESET_API == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_CortexM4_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_CM4_SystemReset() \
do\
{ \
        Mcal_Trusted_Call(Mcu_CM4_SystemReset); \
}\
while(0)
#else
/** @violates @ref Mcu_CortexM4_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_CM4_SystemReset() \
do\
{ \
        Mcu_CM4_SystemReset(); \
}\
while(0)
#endif
#endif

#endif /* (MCU_PERFORM_RESET_API == STD_ON) */


#if (MCU_PERFORM_RESET_API == STD_ON)
 /**
* @brief        The function initiates a system reset request to reset the SoC.
* @details      The function initiates a system reset request to reset the SoC
*
* @param[in]    none
*
* @return void
*
*/
FUNC(void, MCU_CODE) Mcu_CM4_SystemReset(void);

#endif


FUNC(void, MCU_CODE) Mcu_CM4_EnableDeepSleep(void);


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_CortexM4_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_CortexM4_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif


#endif /* MCU_CORTEXM4_H */

/** @} */
