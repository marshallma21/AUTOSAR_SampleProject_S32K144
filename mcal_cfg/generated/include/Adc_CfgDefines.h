/**
*   @file    Adc_CfgDefines.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - Module configuration interface for Adc driver.
*   @details Contains the module configuration interface for Adc driver.
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

#ifndef ADC_CFG_DEFINES_H
#define ADC_CFG_DEFINES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_CfgDefines_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function shall be used in preference to a function-like macro.
* Middle layer between AUTOSAR and hardware needs a way to map HLD
* functions to IPV functions.
*
* @section Adc_CfgDefines_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated. 
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_CFG_DEFINES                       43
#define ADC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES        4
#define ADC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES        2
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_CFG_DEFINES     2
#define ADC_SW_MAJOR_VERSION_CFG_DEFINES                1
#define ADC_SW_MINOR_VERSION_CFG_DEFINES                0
#define ADC_SW_PATCH_VERSION_CFG_DEFINES                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Specifies if Current channel is used 
*/
#define ADC_CURRENT_CHANNEL_USED

/**
* @brief          ADC unit 0 available
*/
#define ADC_UNIT_0  0U

/**
* @brief          ADC unit 1 available
*/
#define ADC_UNIT_1  1U


/**
* @brief          Number of SC1n registers available
*/
#define ADC_NUM_SC1n_REGISTER      16U

/**
* @brief          Specifies if the alias SC and Rn register supported
*/
#define ADC_USE_ALIAS_REGISTERS    (STD_OFF)

#define ADC_SC1_OFFSET_ADDR32     (0x0UL)

#define ADC_Rn_OFFSET_ADDR32      (0x48UL)

#define ADC_ADCH_MASK_U32         (0x1fUL)

/**
* @brief          The mask to calculale the previous channnel index
*/
#define ADC_PRE_CHANNEL_SHIFT_MASK      4U
/**
* @brief          Number of SC1n registers used
*/
#define ADC_NUM_SC1n_REGISTER_USED 16U
/**
* @brief          PDB support 8 delay register
*/
#define ADC_PDB_NUM_DELAY_REGISTER   8U

/**
* @brief          MHT functionality not activated.
*/
#define ADC_MULTIPLE_HARDWARE_TRIGGERS      (STD_OFF)

/** 
* @brief           Adds/removes ((STD_ON)/(STD_OFF)) the services Adc_EnableHardwareTrigger() and Adc_DisableHardwareTrigger() from the code.
*/
#define ADC_HW_TRIGGER_API                  (STD_OFF)

/** 
* @brief           Set mode api enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define ADC_SET_MODE_API                    (STD_OFF)

/** 
* @brief           Enables or disables limit checking feature in the ADC driver.
*/
#define ADC_ENABLE_LIMIT_CHECK              (STD_OFF)

/** 
* @brief           Group notification mechanism is/isn't ((STD_ON)/(STD_OFF)) available at runtime.
*/
#define ADC_GRP_NOTIF_CAPABILITY            (STD_ON)

/** 
* @brief           Type of prioritization mechanism ADC_PRIORITY_HW, ADC_PRIORITY_HW_SW and ADC_PRIORITY_NONE.
*/
#define ADC_PRIORITY_HW                     0U
#define ADC_PRIORITY_HW_SW                  1U
#define ADC_PRIORITY_NONE                   2U

/** 
* @brief           Priority implementation.
*/
#define ADC_PRIORITY_IMPLEMENTATION         (ADC_PRIORITY_NONE)

/** 
* @brief           Type of alignment mechanism ADC_ALIGN_RIGHT, ADC_ALIGN_LEFT.
*/
#define ADC_ALIGN_RIGHT                     0U
#define ADC_ALIGN_LEFT                      1U

/** 
* @brief           Result Alignment.
*/
#define ADC_RESULT_ALIGNMENT                (ADC_ALIGN_RIGHT)

/** 
* @brief           Adc transfer type.
*/
#define ADC_DMA                             0U
#define ADC_INTERRUPT                       1U

/** 
* @brief         This is a timeout value which is used to wait till
*                  - the conversion is not aborted.
*                  - ADC hardware is not entered in power down state.
*                  - ADC hardware is not entered in idle state.
*/
#define ADC_TIMEOUT_COUNTER                 (0x0000ffffUL)

/** 
* @brief         This is a timeout value which is used to wait till Dma transfering finish
*/
#define ADC_DMA_TRANSFER_TIMEOUT                 (0x0000ffffUL)

/** 
* @brief           Specifies for reducing the number of interrupts for streaming groups
*/
#define ADC_ENABLE_DOUBLE_BUFFERING  (STD_OFF)

/** 
* @brief           Specifies to optimize converstions for hw triggered, one shot group.
*/
#define ADC_OPTIMIZE_ONESHOT_HW_TRIGGER      (STD_OFF)


/**
 * @brief   Max number of ADCDig Hw units
 */
#define ADC_MAX_HW_UNITS                    2U

/**
 * @brief   Define the number of maximum channels
 */
#define ADC_PDB_CHANNELS_U8                 2U

/**
* @brief          Number PDB module.
*/ 
#define ADC_PDB_NUM_MODULES                 2U

/** 
* @brief           Add/Remove non autosar Adc_EnableChannel() and Adc_DisableChannel() api.
*/
#define ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API        (STD_OFF)

/** 
* @brief           Get injected conversion status api enabled/disabled (STD_ON/STD_OFF).
*/
#define ADC_GET_INJECTED_CONVERSION_STATUS_API      (STD_OFF)

/** 
* @brief          Add/Remove non autosar Adc_SetClockMode().
*/
#define ADC_DUAL_CLOCK_MODE                         (STD_OFF)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_Calibration() from the code.
*/
#define ADC_CALIBRATION                             (STD_OFF)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_SetChannel() from the code.
*/
#define ADC_SETCHANNEL_API                          (STD_OFF)

/** 
* @brief          Extra group notification mechanism is/isn't ((STD_ON)/(STD_OFF)) available at runtime.
*/
#define ADC_ENABLE_INITIAL_NOTIFICATION             (STD_OFF)


/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_SelfTest() from the code.
*/
#define ADC_SELF_TEST                               (STD_OFF)

/** 
* @brief           ADC Configure Threshold enabled/disabled (STD_ON/STD_OFF).
*/
#define ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API    (STD_OFF)

/**
* @brief  Switch to enable/disable the API for the PR-MCAL-3312, PR-MCAL-3313, PR-MCAL-3314, PR-MCAL-3315 and PR-MCAL-3316.
*/
#define CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS   (STD_OFF)

/** 
* @brief          This switch is used to enable the hardware trigger non autosar API.
*/
#define ADC_ENABLE_CTUTRIG_NONAUTO_API              (STD_OFF)

/** 
* @brief  Switch to enable/disable the API for the CPR-MCAL-726, CPR-MCAL-727, CPR-MCAL-728.
*/
#define ADC_ENABLE_CTU_CONTROL_MODE_API             (STD_OFF)
/** 
* @brief  Switch to enable/disable the production error reporting.
*/
#define ADC_DISABLE_DEM_REPORT_ERROR_STATUS         (STD_ON)

/**
* @brief IRQ definition
*/
#define ADC_UNIT_0_ISR_USED



/** 
* @brief           max queue depth configured across all configset.
*/
#define ADC_QUEUE_MAX_DEPTH_MAX             1U

/** 
* @brief           max number of groups configured across all configset.
*/
#define ADC_MAX_GROUPS                      3U

/** 
* @brief           Define the HW queue size depending on the MHT groups existence.
* @details         If there are MHT groups in the configuration the HW queue size will be the total number of MHT
*                  groups defined. If there are no MHT groups in the current configuration, then only one hardware
*                  group can be added to the HW queue, thus the queue size will be only 1.
*/

#define ADC_HW_QUEUE                        (1U)

#define ADC_USER_MODE_REG_PROT_ENABLED      (STD_OFF)


/** 
* @brief          Development error detection enabled/disabled ((STD_ON)/(STD_OFF)).
*/
#define ADC_DEV_ERROR_DETECT                (STD_ON)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_GetVersionInfo() from the code.
*/
#define ADC_VERSION_INFO_API                (STD_ON)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the service Adc_DeInit() from the code.
*/
#define ADC_DEINIT_API                      (STD_ON)

/** 
* @brief          Add/remove ((STD_ON)/(STD_OFF)) the services Adc_StartGroupConversion()and Adc_StopGroupConversion() from the code.
*/
#define ADC_ENABLE_START_STOP_GROUP_API     (STD_ON)

/** 
* @brief          Add/Remove the services Adc_ReadGroup() from the code.
*/
#define ADC_READ_GROUP_API                  (STD_ON)

/** 
* @brief           This switch is used to enable the non autosar ADC performance optimization feature.
*/
#define ADC_BYPASS_CONSISTENCY_LOOP         (STD_OFF)


/** 
* @brief          Add/Remove One time setting of Conversion time regsisters from Init() function.
*/
#define ADC_SET_ADC_CONV_TIME_ONCE          (STD_OFF)

/** 
* @brief   Switch to enable that power state mode is supported
*
*/
#define ADC_POWER_STATE_SUPPORTED           (STD_OFF)

/** 
* @brief           This switch is used to enable the queue.
*/
#define ADC_ENABLE_QUEUING                  (STD_ON)

/** 
* @brief           Symbolic names of ADC Hardware units.
*/
#define  AdcHwUnit_0                      (0)

/** 
* @brief           ADC Hardware unit macro for register access.
*
* @violates @ref Adc_CfgDefines_h_REF_1 Use of function like macro.
*/
#define ADC_HW_UNITS(unit)                  (Adc_pCfgPtr->Misc.au8Adc_HwUnit[(unit)])

/**
* @brief          Adc channel id.
* @violates @ref Adc_CfgDefines_h_REF_1 Use of function like macro.
*/
#define ADC_ID_CHANNEL_U8(Id)               (Id)

/**
* @brief          Maximum boundary for the Adc_QueueIndexType.
*/
#define ADC_QUEUE_INDEX_TYPE_MAXIMUM          65535U

/**
* @brief          Specifies if Software Normal injected conversions are supported / used.
*/
#define ADC_SOFTWARE_INJECTED_CONVERSIONS_USED     (STD_OFF)

/** 
* @brief           Normal hardware triggering used
*/
#define ADC_HARDWARE_NORMAL_CONVERSIONS_USED       (STD_OFF)

/** 
* @brief           AUTOSAR Symbolic names of channels on all HW units.
*/

#define AdcPotChannel                       0
#define AdcLedFdbkChannel0                       1
#define AdcLedFdbkChannel1                       2


/** 
* @brief           Symbolic names of groups.
*/

#define AdcPotGroup                       0
#define AdcLedFdbkGroup0                       1
#define AdcLedFdbkGroup1                       2

/** 
* @brief           Symbolic names of groups - ecuc 2108 compliant.
*/

/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define AdcConf_AdcGroup_AdcPotGroup                       0
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define AdcConf_AdcGroup_AdcLedFdbkGroup0                       1
/** @violates @ref Adc_CfgDefines_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define AdcConf_AdcGroup_AdcLedFdbkGroup1                       2

/** 
* @brief           Active CMR register
*/
#define ADC_CMR_REGISTER_NOT_SUPPORTED

/** 
* @brief           PDB is supported
*/
#define ADC_PDB_SUPPORTED

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Adc driver code can be executed from both supervisor and user mode.
*/

#define ADC_ENABLE_USER_MODE_SUPPORT   (STD_OFF)


#define ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL       (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef ADC_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == ADC_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running  ADC in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == ADC_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifndef ADC_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT*/
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

#ifdef __cplusplus
}
#endif

#endif /* ADC_CFG_DEFINES_H */

/** @} */
