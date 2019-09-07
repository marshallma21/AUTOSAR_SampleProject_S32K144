/**
* @file    Wdg_IPW.h
* @version 1.0.1
* @brief   AUTOSAR Wdg - IP Wrapper for Wdg
* @details Contains the platform specific implementation for WDG
*
* @addtogroup  Wdg
* @{
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

#ifndef WDG_IPW_H
#define WDG_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_IPW_h_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to LLD functions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Wdog.h"
/**
* @file          Wdg_IPW.h  
*/


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file          Wdg_IPW.h    
*/
#define WDG_IPW_VENDOR_ID                    43
#define WDG_IPW_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_AR_RELEASE_MINOR_VERSION     2
#define WDG_IPW_AR_RELEASE_REVISION_VERSION  2
#define WDG_IPW_SW_MAJOR_VERSION             1
#define WDG_IPW_SW_MINOR_VERSION             0
#define WDG_IPW_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Wdog header file are of the same vendor */
#if (WDG_IPW_VENDOR_ID != WDG_WDOG_VENDOR_ID)
    #error "Wdg_IPW.h and Wdg_Wdog.h have different vendor ids"
#endif
/* Check if current file and Wdg_Wdog header file are of the same Autosar version */
#if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION    != WDG_WDOG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_MINOR_VERSION    != WDG_WDOG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_REVISION_VERSION != WDG_WDOG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_IPW.h and Wdg_Wdog.h are different"
#endif
/* Check if current file and WDOG header file are of the same Software version */
#if ((WDG_IPW_SW_MAJOR_VERSION != WDG_WDOG_SW_MAJOR_VERSION) || \
     (WDG_IPW_SW_MINOR_VERSION != WDG_WDOG_SW_MINOR_VERSION) || \
     (WDG_IPW_SW_PATCH_VERSION != WDG_WDOG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Wdg_IPW.h and Wdg_Wdog.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between WDOG initialization function and high level initialization function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_Init(Wdg_IPW_ConfigPtr, Wdg_Instance) (Wdg_Wdog_Init((Wdg_IPW_ConfigPtr), (Wdg_Instance)))
#endif

#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between WDOG initialization function and high level set mode function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_SetMode(Wdg_IPW_ConfigPtr, Wdg_Instance) (Wdg_Wdog_Init((Wdg_IPW_ConfigPtr), (Wdg_Instance)))
#endif

#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between WDOG trigger function and high level trigger function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_Trigger(Wdg_Instance) (Wdg_Wdog_Trigger(Wdg_Instance))
#endif


#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between WDOG check hw settings and high level check hw settings function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_CheckHwSettings(Wdg_IPW_ConfigPtr, Wdg_Instance) (Wdg_Wdog_CheckHwSettings((Wdg_IPW_ConfigPtr), (Wdg_Instance)))
#endif

#ifdef WDG_VALIDATE_CONFIG_UPDATE        
#if (WDG_VALIDATE_CONFIG_UPDATE == STD_ON)
#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between WDOG validate update config and high level validate update config function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_ValidateConfigUpdate(Wdg_Instance) (Wdg_Wdog_ValidateConfigUpdate(Wdg_Instance))
#endif
#endif
#endif
/*==================================================================================================
*                                            ENUMS
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

#endif /*WDG_IPW_H*/
/** @} */
