/**
*   @file    Mcu_CMU.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPV_CMU.
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

#ifndef MCU_CMU_H
#define MCU_CMU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_CMU_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions.
*
* @section Mcu_CMU_h_REF_4
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
#include "Mcu_CMU_Types.h"
#include "Mcu_EnvCfg.h"
#include "Mcu_CMU_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_CMU_VENDOR_ID                    43
#define MCU_CMU_AR_RELEASE_MAJOR_VERSION     4
#define MCU_CMU_AR_RELEASE_MINOR_VERSION     2
#define MCU_CMU_AR_RELEASE_REVISION_VERSION  2
#define MCU_CMU_SW_MAJOR_VERSION             1
#define MCU_CMU_SW_MINOR_VERSION             0
#define MCU_CMU_SW_PATCH_VERSION             1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_CMU_VENDOR_ID != MCU_CMU_TYPES_VENDOR_ID)
    #error "Mcu_CMU.h and Mcu_CMU_Types.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION != MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_MINOR_VERSION != MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_REVISION_VERSION != MCU_CMU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_CMU.h and Mcu_CMU_Types.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_CMU_SW_MAJOR_VERSION != MCU_CMU_TYPES_SW_MAJOR_VERSION) || \
     (MCU_CMU_SW_MINOR_VERSION != MCU_CMU_TYPES_SW_MINOR_VERSION) || \
     (MCU_CMU_SW_PATCH_VERSION != MCU_CMU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_CMU.h and Mcu_CMU_Types.h are different"
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_CMU_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_CMU.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_CMU.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_CMU_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_CMU_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_CMU_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_CMU.h and Mcu_EnvCfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
#ifdef MCU_CMU_REG_PROT_AVAILABLE
#if (STD_ON == MCU_CMU_REG_PROT_AVAILABLE)

#ifdef IPV_REG_PROT
#if (IPV_REG_PROT == IPV_REG_PROT_00_01_02_04)
/**
* @brief Size memory protected of CMU.
*/
#define CMU_PROT_MEM_U32                    ((uint32)0x00000001u)
#else
/**
* @brief Size memory protected of CMU.
*/
#define CMU_PROT_MEM_U32                    ((uint32)0x00000010u)
#endif
#else
/**
* @brief Size memory protected of CMU.
*/
#define CMU_PROT_MEM_U32                    ((uint32)0x00000010u)
#endif

#endif /* (STD_ON == MCU_CMU_REG_PROT_AVAILABLE) */
#endif
#endif /* (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT) */
#endif /* MCU_ENABLE_USER_MODE_SUPPORT */


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
 * @violates @ref Mcu_CMU_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
 */
#include "Mcu_MemMap.h"


#if (IPV_CMU == IPV_CMU_00_00_00_01)
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)

#if (MCU_INIT_CLOCK == STD_ON)
FUNC( void, MCU_CODE) Mcu_CMU_DeInit(VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_CMU_Init(P2CONST(Mcu_CMU_ConfigType, AUTOMATIC, MCU_APPL_CONST) pCmu_ConfigPtr);
FUNC( uint32, MCU_CODE) Mcu_CMU_GetInterruptStatus(VAR(uint8, AUTOMATIC) u8IndexCmu);
FUNC( void, MCU_CODE) Mcu_CMU_ClearInterruptStatus(VAR(uint8, AUTOMATIC) u8IndexCmu, VAR(uint32, AUTOMATIC) u32ClearMask);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC( void, MCU_CODE ) Mcu_CMU_Disable_CMU(VAR (uint8, AUTOMATIC) u8IndexCmu);

/* isr handler */
#ifdef MCU_CMU_ERROR_ISR_USED
#if (MCU_CMU_ERROR_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_CMU_ClockFailInt( VAR( void, AUTOMATIC) );
#endif
#endif

#if defined(MCU_CMU_ERROR_ISR_USED)
#if (MCU_CMU_ERROR_ISR_USED == STD_ON)
FUNC(Std_ReturnType, MCU_CODE) Mcu_CMU_ClearClockFailIrqFlags(VAR(uint8, AUTOMATIC) u8CmuIdx, VAR(uint32, AUTOMATIC) u32IsrMask);
#endif /* (MCU_CMU_ERROR_ISR_USED == STD_ON)*/
#endif
#endif
#endif

#else 
    
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
#if (STD_ON == MCU_CMU_REG_PROT_AVAILABLE)
FUNC( void, MCU_CODE) Mcu_CMU_SetUserAccessAllowed(void);
#endif /* (STD_ON == MCU_CMU_REG_PROT_AVAILABLE) */
#endif /* (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT) */
#endif /* MCU_ENABLE_USER_MODE_SUPPORT */

#if (MCU_INIT_CLOCK == STD_ON)
FUNC( void, MCU_CODE) Mcu_CMU_DeInit(VAR( void, AUTOMATIC));
FUNC( void, MCU_CODE) Mcu_CMU_Init(P2CONST(Mcu_CMU_ConfigType, AUTOMATIC, MCU_APPL_CONST) pCmu_ConfigPtr);
FUNC( uint32, MCU_CODE) Mcu_CMU_GetInterruptStatus(VAR(uint8, AUTOMATIC) u8IndexCmu);
FUNC( void, MCU_CODE) Mcu_CMU_ClearInterruptStatus(VAR(uint8, AUTOMATIC) u8IndexCmu, VAR(uint32, AUTOMATIC) u32ClearMask);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_CMU_Disable_CMU(VAR (uint8, AUTOMATIC) u8IndexCmu);
#endif
#endif

/* isr handler */
#ifdef MCU_CMU_ERROR_ISR_USED
#if (MCU_CMU_ERROR_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_CMU_ClockFailInt( VAR( void, AUTOMATIC) );
#endif
#endif

#if defined(MCU_CMU_ERROR_ISR_USED) || defined(MCU_CMU_CLEAR_CLOCK_IRQ_FLAG)
#if ((MCU_CMU_ERROR_ISR_USED == STD_ON) || (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON))
FUNC(Std_ReturnType, MCU_CODE) Mcu_CMU_ClearClockFailIrqFlags(VAR(uint8, AUTOMATIC) u8CmuIdx, VAR(uint32, AUTOMATIC) u32IsrMask);
#endif /* ((MCU_CMU_ERROR_ISR_USED == STD_ON) || (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)) */
#endif

#endif
#define MCU_STOP_SEC_CODE
/**
 * @violates @ref Mcu_CMU_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
 */
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_CMU_H */

/** @} */
