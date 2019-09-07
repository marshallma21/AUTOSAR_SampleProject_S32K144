/**
*   @file    Adc_Adc12bsarv2.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - ADC12BSARV2 IP header file.
*   @details ADC12BSARV2 low level driver API.
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

#ifndef ADC_ADC12BSARV2_H
#define ADC_ADC12BSARV2_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Adc12bsarv2_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Adc12bsarv2_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Adc_Adc12bsarv2_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Adc12bsarv2_h_REF_5
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared 
* in one and only one file.
* These objects are used in several files in the code.
*
* @section Adc_Adc12bsarv2_h_REF_6
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope 
* if they are only accessed from within a single function.
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
#include "Adc_Reg_eSys_Adc12bsarv2.h"
#ifdef ADC_DMA_SUPPORTED
#include "CDD_Mcl.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_ADC12BSARV2                      43
/**
* @violates @ref Adc_Adc12bsarv2_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2       4
/**
* @violates @ref Adc_Adc12bsarv2_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2       2
/**
* @violates @ref Adc_Adc12bsarv2_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2    2
/**
* @violates @ref Adc_Adc12bsarv2_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_SW_MAJOR_VERSION_ADC12BSARV2               1
/**
* @violates @ref Adc_Adc12bsarv2_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_SW_MINOR_VERSION_ADC12BSARV2               0
/**
* @violates @ref Adc_Adc12bsarv2_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_SW_PATCH_VERSION_ADC12BSARV2               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same vendor */
#if (ADC_VENDOR_ID_ADC12BSARV2 != ADC_VENDOR_ID_REG)
    #error "Adc_Adc12bsarv2.h and Adc_Reg_eSys_Adc12bsarv2.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adc12bsarv2 header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2 != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2 != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2 != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2.h and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/* Check if source file and ADC Adc_Reg_eSys_Adc12bsarv2 header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2 != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2 != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2 != ADC_SW_PATCH_VERSION_REG) \
    )
#error "Software Version Numbers of Adc_Adc12bsarv2.h and Adc_Reg_eSys_Adc12bsarv2.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* The macro to calculate the number of channel for each configuration */
/** @violates @ref Adc_Adc12bsarv2_h_REF_3 Function-like macro defined */
#define ADC_ADC12BSARV2_GET_LEFT_CHANNEL(x) ((((x)/ADC_NUM_SC1n_REGISTER_USED) != 0U) ? ADC_NUM_SC1n_REGISTER_USED : ((x)%ADC_NUM_SC1n_REGISTER_USED))

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
/** @violates @ref Adc_Adc12bsarv2_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/**
* @brief          Used for group status.
*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
extern VAR(Adc_GroupStatusType, ADC_VAR) Adc_aGroupStatus[ADC_MAX_GROUPS];

/**
* @brief          Used for unit status.
*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
extern VAR(Adc_UnitStatusType , ADC_VAR) Adc_aUnitStatus[ADC_MAX_HW_UNITS];

#if (ADC_SETCHANNEL_API == STD_ON)
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
extern VAR(Adc_RuntimeGroupChannelType, ADC_VAR) Adc_aRuntimeGroupChannel[ADC_MAX_GROUPS];
#endif

#ifdef ADC_DMA_SUPPORTED
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps.
*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern VAR(Adc_ValueGroupType,ADC_VAR) Adc_Adc12bsarv2_aDmaInternalResultBuffer[ADC_MAX_HW_UNITS];
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
/**
* @brief          The array to store the Dma configuration for each Adc hardware unit.
*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) Adc_Adc12bsarv2_aDmaTcdConfig[ADC_MAX_HW_UNITS];
/**
* @brief          The array to store the address of TCD which configured for each Adc hardware unit.
*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_6 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) Adc_Adc12bsarv2_aTcdAddress[ADC_MAX_HW_UNITS];
#endif /* ADC_DMA_SUPPORTED */

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Adc12bsarv2_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_Adc12bsarv2_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

/**
* @brief          Used to point the configuration structure.
*/
/** @violates @ref Adc_Adc12bsarv2_h_REF_5  External object declared more than once*/
extern P2CONST(Adc_ConfigType , ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_Adc12bsarv2_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_Adc12bsarv2_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

FUNC(void, ADC_CODE) Adc_Adc12bsarv2_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
);

#if (ADC_DEINIT_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DeInit(void);
#endif /* (ADC_DEINIT_API == STD_ON) */

FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StartNormalConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

#if ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE))
FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_StopCurrentConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StartHwTrigConversion
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit, 
    CONST(Adc_GroupType, AUTOMATIC) Group
);
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_ReadGroup
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataPtr,
    P2VAR(boolean, AUTOMATIC, ADC_APPL_DATA) pFlag
);
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
FUNC (Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_SetClockMode
(
    VAR(Adc_DualClockModeType, AUTOMATIC) eClockMode
);
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_Calibrate
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2VAR(Adc_CalibrationStatusType , AUTOMATIC, ADC_APPL_DATA) pStatus
);
#endif /* ADC_CALIBRATION == STD_ON */

FUNC(void, ADC_CODE) Adc_Adc12bsarv2_ConfigurePartialConversion
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger,
    CONST(uint8, AUTOMATIC) u8NumChannel
);

#ifdef ADC_DMA_SUPPORTED
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_ConfigureDmaPartialConversion
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger,
    CONST(uint8, AUTOMATIC) u8NumChannel,
    CONST(boolean, AUTOMATIC) bFromIsr
);
#endif

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Adc12bsarv2_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /* ADC_ADC12BSARV2_H */

/** @} */
