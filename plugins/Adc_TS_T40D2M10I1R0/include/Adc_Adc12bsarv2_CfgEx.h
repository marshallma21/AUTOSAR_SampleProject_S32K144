/**
*   @file    Adc_Adc12bsarv2_CfgEx.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - ADC12BSARV2 configuration header file.
*   @details ADC12BSARV2 Configuration extern low level driver API.
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

#ifndef ADC_ADC12BSARV2_CFGEX_H
#define ADC_ADC12BSARV2_CFGEX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Adc12bsarv2_CfgEx_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Adc_Adc12bsarv2_CfgEx_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
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
#include "Mcal.h"
#include "Adc_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_ADC12BSARV2_CFGEX                        43
#define ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_CFGEX         4
#define ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_CFGEX         2
/** @violates @ref Adc_Adc12bsarv2_CfgEx_h_REF_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_CFGEX      2
#define ADC_SW_MAJOR_VERSION_ADC12BSARV2_CFGEX                 1
#define ADC_SW_MINOR_VERSION_ADC12BSARV2_CFGEX                 0
#define ADC_SW_PATCH_VERSION_ADC12BSARV2_CFGEX                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and ADC types header file are of the same vendor */
#if (ADC_VENDOR_ID_ADC12BSARV2_CFGEX != ADC_VENDOR_ID_TYPES)
#error "Adc_Adc12bsarv2_CfgEx.h and Adc_Types.h have different vendor ids"
#endif

/* Check if source file and ADC types header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_CFGEX != ADC_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_CFGEX != ADC_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_CFGEX != ADC_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Adc_Adc12bsarv2_CfgEx.h and Adc_Types.h are different"
#endif

/* Check if source file and ADC types header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_CFGEX != ADC_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_CFGEX != ADC_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_CFGEX != ADC_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Adc_Adc12bsarv2_CfgEx.h and Adc_Types.h are different"
#endif

/** @violates @ref Adc_Adc12bsarv2_CfgEx_h_REF_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_CFGEX != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_CFGEX != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adc12bsarv2_CfgEx.h and Mcal.h are different"
 #endif 
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* The macro to calculate the index of the first channel in the previous configuration */
/** @violates @ref Adc_Adc12bsarv2_CfgEx_h_REF_2 Function-like macro defined */
#define ADC_PRE_CHANNEL_INDEX(x) ((((x) % ADC_NUM_SC1n_REGISTER_USED) == 0U) ? ((x) - ADC_NUM_SC1n_REGISTER_USED) : ((Adc_ChannelIndexType)((x)-((x) % ADC_NUM_SC1n_REGISTER_USED))))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Structure for channel configuration.
*
*/
typedef struct
{
    CONST(Adc_ChannelType, ADC_CONST) ChId; /**< @brief Channel Id */
} Adc_Adc12bsarv2_ChannelConfigurationType;

/**
* @brief          Structure for Adc hardware unit configuration.
*
*/
typedef struct
{
    /**< @brief Adc hardware unit id */
    CONST(Adc_HwUnitType, ADC_CONST) AdcHardwareUnitId; 
    /**< @brief Main configuration of CFG1 registers */
    CONST(uint32, ADC_CONST) u32AdcCfg1Register;
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
    /**< @brief Main configuration of CFG2 registers */
    CONST(uint32, ADC_CONST) u32AdcCfg2Register;
#endif
    /**< @brief Main configuration of SC2 registers */
    CONST(uint32, ADC_CONST) u32AdcSc2Register;
    /**< @brief Main configuration of SC3 registers */
    CONST(uint32, ADC_CONST) u32AdcSc3Register;
#if (STD_ON == ADC_DUAL_CLOCK_MODE)
    /**< @brief Alternate configuration of CFG1 registers */
    CONST(uint32, ADC_CONST) u32AdcCfg1RegisterAlternate;
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
    /**< @brief Alternate configuration of CFG2 register */
    CONST(uint32, ADC_CONST) u32AdcCfg2RegisterAlternate;
#endif
    /**< @brief Alternate configuration of SC2 register */
    CONST(uint32, ADC_CONST) u32AdcSc2RegisterAlternate;
#if (STD_ON == ADC_SET_ADC_CONV_TIME_ONCE)
    /**< @brief Alternate configuration of SC3 register */
    CONST(uint32, ADC_CONST) u32AdcSc3RegisterAlternate;
#endif    
#endif   
    /**< @brief Configuration of offset correction register */
    CONST(uint32, ADC_CONST) u32AdcOfsRegister;
    /**< @brief Bitmask for data register (depending on resolution) */
    CONST(uint32, ADC_CONST) u32AdcDataMask;
    /**< @brief Resolution of the ADC hardware */
    CONST(Adc_ResolutionType, ADC_CONST) Res;     
    /**< @brief Settings for PRESCALER and MULT fields of PDB_SC register */
    CONST(uint32, ADC_CONST) u32AdcPdbClockSettings;
#if (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED))
    CONST(Adc_NotifyType, ADC_CONST) pPdbNofitication;
#endif /* (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED)) */
} Adc_Adc12bsarv2_HwUnitConfigurationType;

/**
* @brief          Structure for group configuration.
*
*/
typedef struct
{
    CONST(Adc_HwUnitType, ADC_CONST) HwUnit; /**< @brief Hw unit to which the group belongs to */
    CONST(Adc_GroupAccessModeType , ADC_CONST) eAccessMode; /**< @brief   Access mode */
    CONST(Adc_GroupConvModeType , ADC_CONST) eMode; /**< @brief Conversion mode (OneShot/Continuous) */  
    CONST(Adc_GroupConvType , ADC_CONST) eType; /**< @brief Conversion type (Normal/Injected) */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || defined(__DOXYGEN__)
    CONST(Adc_GroupPriorityType , ADC_CONST) Priority; /**< @brief Priority of group */
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || defined(__DOXYGEN__) */
    CONST(Adc_GroupReplacementType , ADC_CONST) eReplecementMode; /**< @brief Replacement mode */
    CONST(Adc_TriggerSourceType , ADC_CONST) eTriggerSource; /**< @brief Hw/Sw trigger */
#if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__)
    CONST(Adc_HwTriggerSignalType , ADC_CONST) eTriggerEdge; /**< @brief Hardware trigger edge */
    P2CONST(Adc_HwTriggerTimerType, ADC_VAR, ADC_APPL_CONST) pHwResource; /**< @brief Resource of the selected hw trigger */
#endif /* #if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY) || defined(__DOXYGEN__)
    CONST(Adc_NotifyType , ADC_CONST) Notification; /**< @brief Pointer to notification function */
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) || defined(__DOXYGEN__) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
    CONST(Adc_NotifyType , ADC_CONST) ExtraNotification; /**< @brief Pointer to extra notification function */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResultsBufferPtr; /**< @brief pointer to user result buffer array */
    CONST(Adc_StreamBufferModeType , ADC_CONST) eBufferMode; /**< @brief Buffer Mode */
    CONST(Adc_StreamNumSampleType , ADC_CONST) NumSamples; /**< @brief  Number of samples */
    P2CONST(Adc_GroupDefType , ADC_VAR, ADC_APPL_CONST) pAssignment; /**< @brief Assigned channels to group */
    P2CONST(uint16 , ADC_VAR, ADC_APPL_CONST) pDelay; /**< @brief Assigned channels to group */
    CONST(Adc_ChannelIndexType , ADC_CONST) AssignedChannelCount; /**< @brief Number of channels */
#if (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE)
    /**< @brief Group configuration of CFG2 registers */
    CONST(uint32, ADC_CONST) u32SampleTime;
    /**< @brief Group configuration of SC3 registers */
    CONST(uint32, ADC_CONST) u32AvgSelect;
     /**< @brief Clock Divide Select for CFG1 */
    CONST(uint32, ADC_CONST) u32ClockDivideSelect;
    #if (ADC_DUAL_CLOCK_MODE == STD_ON)
     /**< @brief Alternate Group configuration of CFG2 registers */
    CONST(uint32, ADC_CONST) u32SampleTimeAlternate;
    /**< @brief Alternate Group configuration of SC3 registers */
    CONST(uint32, ADC_CONST) u32AvgSelectAlternate;
     /**< @brief Alternate Clock Divide Select for CFG1 */
    CONST(uint32, ADC_CONST) u32ClockDivideSelectAlternate;
    #endif
#endif /* (STD_OFF == ADC_SET_ADC_CONV_TIME_ONCE) */
    CONST(uint8 , ADC_CONST) u8AdcGroupBackToBack; /**< @brief Enables or Disables the ADC Back to BAck configuration for Group Channels */
    CONST(uint8 , ADC_CONST) u8AdcGroupChannelDelays; /**< @brief Enables or Disables the ADC pre-trigger delay configuration for each Group Channel */
    CONST(uint8 , ADC_CONST) u8AdcWithoutInterrupt; /**< @brief Enables or Disables the ADC and DMA interrupts */
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
    CONST(boolean , ADC_CONST) bAdcDoubleBuffering; /**< @brief Enables or Disables the ADC double buffering feature */
    CONST(boolean , ADC_CONST) bHalfInterrupt; /**< @brief Enable half interrupt for double buffering feature */
#endif
    CONST(uint16, ADC_CONST) u16PdbDelay; /**< @brief The delay for next PDB */
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
    CONST(uint16, ADC_CONST) u16PdbPeriod; /**< @brief The period PDB for continuous mode */
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    CONST(boolean, ADC_CONST) bAdcGroupLimitcheck; /**< @brief Enables or disables the usage of limit checking for an ADC group. */
#endif
} Adc_GroupConfigurationType;

/**
* @brief          Miscellaneous configuration structure.
* 
*/
typedef struct
{
    CONST(uint8 , ADC_CONST) u8Adc_DmaInterruptSoftware[ADC_MAX_HW_UNITS];     /**< @brief DMA or Interrupt driven */
    CONST(Adc_GroupType , ADC_CONST) Adc_MaxGroups;           /**< @brief Number of the maximum groups */
    CONST(uint8 , ADC_CONST) Adc_MaxHwCfg;                    /**< @brief Number of the maximum hw units */
    CONST(uint8 , ADC_CONST) au8Adc_DmaChannel[ADC_MAX_HW_UNITS]; /**< @brief If dma driven then indicates the dma channel number for HW UNITS */
#ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
#if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
    CONST(uint8 , ADC_CONST) au8Adc_DmaDoubleBuffer[ADC_MAX_HW_UNITS]; /**< DMA channel for HW enable double bufering more than one channel */
#endif
#endif
    CONST(uint8 , ADC_CONST) au8Adc_HwUnit[ADC_MAX_HW_UNITS]; /**< @brief If unit x is active STD_ON/STD_OFF */
    CONST(Adc_HwUnitType, ADC_CONST) aHwLogicalId[ADC_MAX_HW_UNITS];  /**< Hardware index in the structure */
} Adc_Adc12bsarv2_MultiConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* ADC_ADC12BSARV2_CFGEX_H */

/** @} */
