/**
*   @file    Wdg_IPW_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - Wdg_IPW Types.
*   @details Contains the Wdg_IPW Types that are exported
*
*   @addtogroup Wdg
*   @{
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

#ifndef WDG_IPW_TYPES_H
#define WDG_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif



/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
* @section Wdg_IPW_Types_h_REF_1
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialised,
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct.
*          Braces can not be applied in this case due to a compiler limitation.It was analysed and this 
*          MISRA issue does not imply an impact on the driver's functionality. 
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Wdg_Wdog_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_IPW_Types.h
*/
#define WDG_IPW_TYPES_VENDOR_ID                    43
#define WDG_IPW_TYPES_MODULE_ID                    102
#define WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     2
#define WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  2
#define WDG_IPW_TYPES_SW_MAJOR_VERSION             1
#define WDG_IPW_TYPES_SW_MINOR_VERSION             0
#define WDG_IPW_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_Wdog_Types.h header file are of the same vendor */
#if (WDG_IPW_TYPES_VENDOR_ID!= WDG_WDOG_TYPES_VENDOR_ID)
    #error "Wdg_IPW_Types.h and Wdg_Wdog_Types.h have different vendor ids"
#endif

/* Check if Wdg_IPW_Types file and Wdg_Wdog_Types.h header file are of the same Autosar version */
#if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != WDG_WDOG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION != WDG_WDOG_TYPES_AR_RELEASE_MINOR_VERSION ) || \
     (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != WDG_WDOG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_IPW_Types.h and Wdg_Wdog_Types.h are different"
#endif

/* Check if Wdg_IPW_Types file and Wdg_Wdog_Types.h header file are of the same Software version */
#if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != WDG_WDOG_TYPES_SW_MAJOR_VERSION ) || \
     (WDG_IPW_TYPES_SW_MINOR_VERSION != WDG_WDOG_TYPES_SW_MINOR_VERSION ) || \
     (WDG_IPW_TYPES_SW_PATCH_VERSION != WDG_WDOG_TYPES_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Wdg_IPW_Types.h and Wdg_Wdog_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Wdg_IPW_ConfigType.
* @details        Contains the information related to the hardware setup for WDOG

*/
/** @violates @ref Wdg_IPW_Types_h_REF_1 MISRA 2004 Required Rule 19.4 */
#define Wdg_IPW_ConfigType Wdg_Wdog_ConfigType


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum Wdg_IPW_InstanceType
{
    WDG_IPW_INSTANCE0 = 0x0U,
    WDG_IPW_INSTANCE1,
    WDG_IPW_INSTANCE2,
    WDG_IPW_INSTANCE3
} Wdg_IPW_InstanceType;

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

#endif /*WDG_IPW_TYPES_H*/

/** @} */
