/**
*   @file    Mcu_RCM.h
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


#ifndef MCU_RCM_H
#define MCU_RCM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_RCM_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_RCM_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_RCM_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcu_RCM_h_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to braced initialiser,
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or
* a do-while-zero construct
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
#include "Mcu_RCM_Types.h"
#include "Mcu_EnvCfg.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_RCM_VENDOR_ID                    43
#define MCU_RCM_AR_RELEASE_MAJOR_VERSION     4
#define MCU_RCM_AR_RELEASE_MINOR_VERSION     2
#define MCU_RCM_AR_RELEASE_REVISION_VERSION  2
#define MCU_RCM_SW_MAJOR_VERSION             1
#define MCU_RCM_SW_MINOR_VERSION             0
#define MCU_RCM_SW_PATCH_VERSION             1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_RCM_Types header file are from the same vendor */
#if (MCU_RCM_VENDOR_ID != MCU_RCM_TYPES_VENDOR_ID)
    #error "Mcu_RCM.h and Mcu_RCM_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_RCM_Types header file are of the same Autosar version */
#if ((MCU_RCM_AR_RELEASE_MAJOR_VERSION != MCU_RCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_MINOR_VERSION != MCU_RCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_REVISION_VERSION != MCU_RCM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_RCM.h and Mcu_RCM_Types.h are different"
#endif
/* Check if source file and Mcu_RCM_Types header file are of the same Software version */
#if ((MCU_RCM_SW_MAJOR_VERSION != MCU_RCM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_RCM_SW_MINOR_VERSION != MCU_RCM_TYPES_SW_MINOR_VERSION) || \
     (MCU_RCM_SW_PATCH_VERSION != MCU_RCM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_RCM.h and Mcu_RCM_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_RCM_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_RCM.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_RCM_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_RCM.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_RCM_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_RCM_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_RCM_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_RCM.h and Mcu_EnvCfg.h are different"
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
* @violates @ref Mcu_RCM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_RCM_SystemResetIsrConfig() \
do\
{ \
        Mcal_Trusted_Call(Mcu_RCM_SystemResetIsrConfig); \
}\
while(0)
#else
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_RCM_SystemResetIsrConfig() \
do\
{ \
        Mcu_RCM_SystemResetIsrConfig(); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_RCM_RestoreSystemResetIsrConfig(u32SystemResetIsrConfig) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_RCM_RestoreSystemResetIsrConfig,(u32SystemResetIsrConfig)); \
}\
while(0)
#else
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_RCM_RestoreSystemResetIsrConfig(u32SystemResetIsrConfig) \
do\
{ \
        Mcu_RCM_RestoreSystemResetIsrConfig(u32SystemResetIsrConfig); \
}\
while(0)
#endif
#endif

#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_RCM_ResetInit(RCM_pResetConfigPtr) \
do\
{ \
        Mcal_Trusted_Call1param(Mcu_RCM_ResetInit,(RCM_pResetConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_RCM_ResetInit(RCM_pResetConfigPtr) \
do\
{ \
        Mcu_RCM_ResetInit(RCM_pResetConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_RCM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_RCM_GetResetReason() \
        Mcal_Trusted_Call_Return(Mcu_RCM_GetResetReason)
#else
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_RCM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_RCM_GetResetReason() \
        Mcu_RCM_GetResetReason()
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_RCM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_RCM_GetResetRawValue() \
        Mcal_Trusted_Call_Return(Mcu_RCM_GetResetRawValue)
#else
/** @violates @ref Mcu_RCM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_RCM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_RCM_GetResetRawValue() \
        Mcu_RCM_GetResetRawValue()
#endif
#endif


FUNC(void, MCU_CODE) Mcu_RCM_ResetInit(P2CONST( Mcu_RCM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);

FUNC( Mcu_ResetType, MCU_CODE) Mcu_RCM_GetResetReason( VAR( void, AUTOMATIC));

FUNC( Mcu_RawResetType, MCU_CODE) Mcu_RCM_GetResetRawValue( VAR( void, AUTOMATIC));

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
FUNC( uint32, MCU_CODE) Mcu_RCM_GetCurrentSystemResetIsrSettings( VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_RCM_SystemResetIsrConfig( VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_RCM_RestoreSystemResetIsrConfig( VAR( uint32, AUTOMATIC ) u32SystemResetIsrConfig);
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_RCM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_RCM_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_RCM_H */

/** @} */
