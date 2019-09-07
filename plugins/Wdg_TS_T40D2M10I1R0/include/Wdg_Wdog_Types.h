/**
*   @file    Wdg_Wdog_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - Wdg_WDOG Types.
*   @details Contains the Wdg_Wdog Types that are exported
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

#ifndef WDG_WDOG_TYPES_H
#define WDG_WDOG_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Wdog_Types_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
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
/** @violates @ref Wdg_Wdog_Types_h_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the contents
*                  of a header file being included twice */
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Wdog_Types.h
*/
#define WDG_WDOG_TYPES_VENDOR_ID                    43
#define WDG_WDOG_TYPES_MODULE_ID                    102
#define WDG_WDOG_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_WDOG_TYPES_AR_RELEASE_MINOR_VERSION     2
#define WDG_WDOG_TYPES_AR_RELEASE_REVISION_VERSION  2
#define WDG_WDOG_TYPES_SW_MAJOR_VERSION             1
#define WDG_WDOG_TYPES_SW_MINOR_VERSION             0
#define WDG_WDOG_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_WDOG_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_WDOG_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Types.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Wdg_Wdog_ConfigType.
* @details        Contains the information related to the hardware setup for WDOG

*/
typedef struct
{
    uint32              Wdog_u32Config;       /**< @brief WDOG configuration */
    uint32              Wdog_u32Timeout;      /**< @brief WDOG timeout */
    uint32              Wdog_u32Window;       /**< @brief WDOG window */
    boolean             Wdog_bPrescalerEn;    /**< @brief WDOG prescaler enabled */
    uint32              Wdg_u32InternalTimerClock; /**< @brief WDOG internal clock frequency */
}Wdg_Wdog_ConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /*WDG_WDOG_TYPES_H*/

/** @} */
