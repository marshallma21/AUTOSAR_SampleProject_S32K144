/**
 *   @file    WdgIf.c
 *   @implements        Wdg_HLD_unit
 *   @version 1.0.1
 *
 *   @brief   AUTOSAR WdgIf high level code.
*            This file contains sample code only. It is not part of the production code deliverables.
 *
 *   @addtogroup WDG_MODULE
 *   @{
 */
/*=================================================================================================
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif




/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/


#include "WdgIf.h"
#if (WDGIF_NUMBER_OF_DEVICES == 1U) 
    #include "Wdg.h"
#endif

#if (WDGIF_NUMBER_OF_DEVICES != 1U)     
#ifdef WDG_INSTANCE0     
#if (WDG_INSTANCE0 == STD_ON)
    #include "Wdg_43_Instance0.h"
#endif
#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
    #include "Wdg_43_Instance1.h"
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
    #include "Wdg_43_Instance2.h"
#endif
#endif

#ifdef WDG_INSTANCE3
#if (WDG_INSTANCE3 == STD_ON)
    #include "Wdg_43_Instance3.h"
#endif
#endif

#ifdef WDG_INSTANCE4
#if (WDG_INSTANCE4 == STD_ON)
    #include "Wdg_43_Instance4.h"
#endif
#endif
#endif

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define WDGIF_VENDOR_ID_C                      43
#define WDGIF_AR_RELEASE_MAJOR_VERSION_C       4
#define WDGIF_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref WdgIf_C_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define WDGIF_AR_RELEASE_REVISION_VERSION_C    2
#define WDGIF_SW_MAJOR_VERSION_C               1
#define WDGIF_SW_MINOR_VERSION_C               0
#define WDGIF_SW_PATCH_VERSION_C               1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION)  ||   \
     (WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION)  ||   \
     (WDGIF_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of WdgIf.c and Wdg.h are different"
#endif

#if ((WDGIF_SW_MAJOR_VERSION_C != WDG_SW_MAJOR_VERSION) || \
     (WDGIF_SW_MINOR_VERSION_C != WDG_SW_MINOR_VERSION) || \
     (WDGIF_SW_PATCH_VERSION_C != WDG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of WdgIf.c and Wdg.h are different"
#endif

#if (WDGIF_VENDOR_ID_C != WDG_VENDOR_ID)
    #error "VENDOR ID for WdgIf.c and Wdg.h is different"
#endif



/* Check if current file and WDGIF header file are of the same vendor.*/
#if (WDGIF_VENDOR_ID_C != WDGIF_VENDOR_ID)
    #error "WdgIf.c and WdgIf.h have different vendor ids"
#endif

/* Check if current file and WDGIF header file are of the same Autosar version.*/
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION_C    != WDGIF_AR_RELEASE_MAJOR_VERSION) || \
     (WDGIF_AR_RELEASE_MINOR_VERSION_C    != WDGIF_AR_RELEASE_MINOR_VERSION) || \
     (WDGIF_AR_RELEASE_REVISION_VERSION_C != WDGIF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of WdgIf.c and WdgIf.h are different"
#endif

/* Check if current file and WDGIF header file are of the same Software version.*/
#if ((WDGIF_SW_MAJOR_VERSION_C != WDGIF_SW_MAJOR_VERSION) || \
     (WDGIF_SW_MINOR_VERSION_C != WDGIF_SW_MINOR_VERSION) || \
     (WDGIF_SW_PATCH_VERSION_C != WDGIF_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of WdgIf.c and WdgIf.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#if (WDGIF_NUMBER_OF_DEVICES == 1U) 
const WdgIf_SetModeFctPtrType WdgIf_SetModeFctPtr[WDGIF_NUMBER_OF_DEVICES] =
    {
        Wdg_SetMode
    };
    
const WdgIf_SetTriggerFctPtrType WdgIf_SetTriggerConditionFctPtr[WDGIF_NUMBER_OF_DEVICES] =
    {
        Wdg_SetTriggerCondition
    };
#else
const WdgIf_SetModeFctPtrType WdgIf_SetModeFctPtr[WDGIF_NUMBER_OF_DEVICES] =
    {
    #if(WDG_INSTANCE0 == STD_ON)
            Wdg_43_Instance0_SetMode
            #else
            NULL_PTR
        #endif
    #if (WDGIF_NUMBER_OF_DEVICES>1)
        #ifdef WDG_INSTANCE1
            #if(WDG_INSTANCE1 == STD_ON)
            ,Wdg_43_Instance1_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>2)
        #ifdef WDG_INSTANCE2
            #if(WDG_INSTANCE2 == STD_ON)
            ,Wdg_43_Instance2_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>3)
        #ifdef WDG_INSTANCE3
            #if(WDG_INSTANCE3 == STD_ON)
            ,Wdg_43_Instance3_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>4)
        #ifdef WDG_INSTANCE4
            #if(WDG_INSTANCE4 == STD_ON)
            ,Wdg_43_Instance4_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    };
    
    
const WdgIf_SetTriggerFctPtrType WdgIf_SetTriggerConditionFctPtr[WDGIF_NUMBER_OF_DEVICES] =
    {
    #if(WDG_INSTANCE0 == STD_ON)
            Wdg_43_Instance0_SetTriggerCondition
            #else
            NULL_PTR
        #endif
    #if (WDGIF_NUMBER_OF_DEVICES>1)
        #ifdef WDG_INSTANCE1
            #if(WDG_INSTANCE1 == STD_ON)
            ,Wdg_43_Instance1_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>2)
        #ifdef WDG_INSTANCE2
            #if(WDG_INSTANCE2 == STD_ON)
            ,Wdg_43_Instance2_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>3)
        #ifdef WDG_INSTANCE3
            #if(WDG_INSTANCE3 == STD_ON)
            ,Wdg_43_Instance3_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>4)
        #ifdef WDG_INSTANCE4
            #if(WDG_INSTANCE4 == STD_ON)
            ,Wdg_43_Instance4_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    };
#endif
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
