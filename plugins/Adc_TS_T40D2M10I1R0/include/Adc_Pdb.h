/**
*   @file    Adc_Pdb.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - ADC12BSAR IP header file.
*   @details ADC12BSAR low level driver API.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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

#ifndef Adc_PDB_H
#define Adc_PDB_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Pdb_h_REF_1
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared 
* in one and only one file.
* These objects are used in several files in the code.
*
* @section Adc_Pdb_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Pdb_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Adc_Pdb_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Reg_eSys_Pdb.h"
#include "Adc_Reg_eSys_Adc12bsarv2.h"
#include "Adc_Cfg.h"
#ifdef ADC_DMA_SUPPORTED
#include "CDD_Mcl.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_PDB                      43
/**
* @violates @ref Adc_Pdb_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_PDB       4
/**
* @violates @ref Adc_Pdb_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MINOR_VERSION_PDB       2
/**
* @violates @ref Adc_Pdb_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_PDB    2
#define ADC_SW_MAJOR_VERSION_PDB               1
#define ADC_SW_MINOR_VERSION_PDB               0
#define ADC_SW_PATCH_VERSION_PDB               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Adc_Reg_eSys_Pdb header file are of the same vendor */
#if (ADC_VENDOR_ID_PDB != ADC_PDB_VENDOR_ID_REG)
    #error "Adc_Pdb.h and Adc_Reg_eSys_Pdb.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Pdb header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB != ADC_PDB_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB != ADC_PDB_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB != ADC_PDB_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Pdb.h and Adc_Reg_eSys_Pdb.h are different"
#endif

/* Check if source file and ADC Adc_Reg_eSys_Pdb header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_PDB != ADC_PDB_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_PDB != ADC_PDB_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_PDB != ADC_PDB_SW_PATCH_VERSION_REG) \
    )
#error "Software Version Numbers of Adc_Pdb.h and Adc_Reg_eSys_Pdb.h are different"
#endif

#if (ADC_VENDOR_ID_PDB != ADC_VENDOR_ID_REG)
    #error "Adc_Pdb.h and Adc_Reg_eSys_Adc12bsarv2.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Pdb.h and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and ADC Adc_Reg_eSys_Adc12bsarv2 header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_PDB != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_PDB != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_PDB != ADC_SW_PATCH_VERSION_REG) \
    )
#error "Software Version Numbers of Adc_Pdb.h and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_PDB != ADC_VENDOR_ID_CFG)
#error "Adc_Pdb.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc_Pdb.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PDB != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION_PDB != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION_PDB != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc_Pdb.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @violates @ref Adc_Pdb_h_REF_3 Function-like macro defined */
#define ADC_PDB_CHANNELS_USED(x) ((((x)%8U) != 0U) ? (((x)/8U) + 1U) : ((x)/8U))
/** @violates @ref Adc_Pdb_h_REF_3 Function-like macro defined */
#define ADC_NUM_CHANNELS_USED(x) ((((x) >> 3U) != 0U) ? 8U : (x))
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Pdb_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/**
* @brief          Used for group status.
*/
/** @violates @ref Adc_Pdb_h_REF_1  External object declared more than once*/
extern VAR(Adc_GroupStatusType, ADC_VAR) Adc_aGroupStatus[ADC_MAX_GROUPS];

/**
* @brief          Used for unit status.
*/
/** @violates @ref Adc_Pdb_h_REF_1  External object declared more than once*/
extern VAR(Adc_UnitStatusType , ADC_VAR) Adc_aUnitStatus[ADC_MAX_HW_UNITS];

#if (ADC_SETCHANNEL_API == STD_ON)
/** @violates @ref Adc_Pdb_h_REF_1  External object declared more than once*/
extern VAR(Adc_RuntimeGroupChannelType, ADC_VAR) Adc_aRuntimeGroupChannel[ADC_MAX_GROUPS];
#endif

#ifdef ADC_DMA_SUPPORTED
/** @violates @ref Adc_Pdb_h_REF_1  External object declared more than once*/
extern VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) Adc_Adc12bsarv2_aDmaTcdConfig[ADC_MAX_HW_UNITS];
/** @violates @ref Adc_Pdb_h_REF_1  External object declared more than once*/
extern P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) Adc_Adc12bsarv2_aTcdAddress[ADC_MAX_HW_UNITS];
#endif /* ADC_DMA_SUPPORTED */

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Pdb_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_Pdb_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

FUNC(void, ADC_CODE) Adc_Pdb_Init
(
    VAR(Adc_HwUnitType,AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32PdbClockConfig
);

#if (ADC_DEINIT_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Pdb_DeInit(void);
#endif

FUNC(void, ADC_CODE) Adc_Pdb_ConfigurePartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger,    
    VAR(uint16, AUTOMATIC) u16CurrentChannel, 
    VAR(uint8, AUTOMATIC) u8NumChannel
);

FUNC(void, ADC_CODE) Adc_Pdb_StartSoftwareConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
FUNC(void, ADC_CODE) Adc_Pdb_SetPdbMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bContinuous
);
#endif

FUNC(void, ADC_CODE) Adc_Pdb_StopConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Pdb_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* Adc_PDB_H */

/** @} */
