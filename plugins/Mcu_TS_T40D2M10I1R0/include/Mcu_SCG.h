/**
*   @file    Mcu_SCG.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Function prototypes.
*   @details Interface available for IPW layer only.
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


#ifndef MCU_SCG_H
#define MCU_SCG_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_SCG_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_SCG_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_SCG_h_REF_3
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
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_SCG_Types.h"
#include "Mcu_EnvCfg.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_SCG_VENDOR_ID                    43
#define MCU_SCG_AR_RELEASE_MAJOR_VERSION     4
#define MCU_SCG_AR_RELEASE_MINOR_VERSION     2
#define MCU_SCG_AR_RELEASE_REVISION_VERSION  2
#define MCU_SCG_SW_MAJOR_VERSION             1
#define MCU_SCG_SW_MINOR_VERSION             0
#define MCU_SCG_SW_PATCH_VERSION             1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_SCG_Types header file are from the same vendor */
#if (MCU_SCG_VENDOR_ID != MCU_SCG_TYPES_VENDOR_ID)
    #error "Mcu_SCG.h and Mcu_SCG_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_SCG_Types header file are of the same Autosar version */
#if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION != MCU_SCG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_MINOR_VERSION != MCU_SCG_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_REVISION_VERSION != MCU_SCG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SCG.h and Mcu_SCG_Types.h are different"
#endif
/* Check if source file and Mcu_SCG_Types header file are of the same Software version */
#if ((MCU_SCG_SW_MAJOR_VERSION != MCU_SCG_TYPES_SW_MAJOR_VERSION) || \
     (MCU_SCG_SW_MINOR_VERSION != MCU_SCG_TYPES_SW_MINOR_VERSION) || \
     (MCU_SCG_SW_PATCH_VERSION != MCU_SCG_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SCG.h and Mcu_SCG_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_SCG_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_SCG.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SCG.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_SCG_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_SCG_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_SCG_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SCG.h and Mcu_EnvCfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


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
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_SCG_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DropSysClkToSircInRunMode() \
do\
{ \
        Mcal_Trusted_Call(Mcu_SCG_DropSysClkToSircInRunMode); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DropSysClkToSircInRunMode() \
do\
{ \
        Mcu_SCG_DropSysClkToSircInRunMode(); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableFircClock() \
do\
{ \
        Mcal_Trusted_Call(Mcu_SCG_DisableFircClock); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableFircClock() \
do\
{ \
        Mcu_SCG_DisableFircClock(); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableSoscClock() \
do\
{ \
        Mcal_Trusted_Call(Mcu_SCG_DisableSoscClock); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableSoscClock() \
do\
{ \
        Mcu_SCG_DisableSoscClock(); \
}\
while(0)
#endif
#endif

#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

#if (MCU_INIT_CLOCK == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DropSystemClockToSirc() \
do\
{ \
        Mcal_Trusted_Call(Mcu_SCG_DropSystemClockToSirc); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DropSystemClockToSirc() \
do\
{ \
        Mcu_SCG_DropSystemClockToSirc(); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SircInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_SCG_SircInit,(SCG_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SircInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcu_SCG_SircInit(SCG_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_FircInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_SCG_FircInit,(SCG_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_FircInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcu_SCG_FircInit(SCG_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SoscInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_SCG_SoscInit,(SCG_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SoscInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcu_SCG_SoscInit(SCG_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SpllInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_SCG_SpllInit,(SCG_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SpllInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcu_SCG_SpllInit(SCG_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SystemClockInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_SCG_SystemClockInit,(SCG_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_SystemClockInit(SCG_pClockConfigPtr) \
do\
{ \
        Mcu_SCG_SystemClockInit(SCG_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableClockMonitors() \
do\
{ \
        Mcal_Trusted_Call(Mcu_SCG_DisableClockMonitors); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableClockMonitors() \
do\
{ \
        Mcu_SCG_DisableClockMonitors(); \
}\
while(0)
#endif
#endif

#if (MCU_NO_PLL == STD_OFF)
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableSpllClock() \
do\
{ \
        Mcal_Trusted_Call(Mcu_SCG_DisableSpllClock); \
}\
while(0)
#else
/** @violates @ref Mcu_SCG_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_SCG_DisableSpllClock() \
do\
{ \
        Mcu_SCG_DisableSpllClock(); \
}\
while(0)
#endif  /* MCU_NO_PLL */
#endif
#endif


#if (MCU_INIT_CLOCK == STD_ON)

FUNC( void, MCU_CODE) Mcu_SCG_SystemClockInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC( void, MCU_CODE) Mcu_SCG_SoscInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC( void, MCU_CODE) Mcu_SCG_FircInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC( void, MCU_CODE) Mcu_SCG_SircInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
#if (MCU_NO_PLL == STD_OFF)
FUNC( void, MCU_CODE) Mcu_SCG_SpllInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
#endif  /* MCU_NO_PLL */
FUNC( void, MCU_CODE) Mcu_SCG_DropSystemClockToSirc(VAR( void, AUTOMATIC));
#endif

#if (MCU_NO_PLL == STD_OFF)
FUNC( Mcu_SCG_PllStatusType, MCU_CODE) Mcu_SCG_GetPLLStatus(VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_SCG_DisableSpllClock(VAR( void, AUTOMATIC));
#endif

FUNC( void, MCU_CODE) Mcu_SCG_DisableClockMonitors(VAR( void, AUTOMATIC));

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
FUNC( void, MCU_CODE) Mcu_SCG_DropSysClkToSircInRunMode(VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_SCG_DisableFircClock(VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_SCG_DisableSoscClock(VAR( void, AUTOMATIC));
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SCG_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SCG_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_SCG_H */

/** @} */
