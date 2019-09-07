/**
*   @file    Adc.h
*   @implements      Adc.h_Artifact
*   @version 1.0.1

*   @brief   AUTOSAR Adc - driver API and development errors definition.
*   @details This file contains the ADC Autosar driver API and development errors definition.
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
*   Autosar Version      : 4.2.
*                          2
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

#ifndef ADC_H
#define ADC_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* '#include' statements in a file should only be preceded by othe preprocessor directives or comments
*
* @section Adc_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice
*
* @section Adc_h_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance 
* and case sensitivity are supported for external identifiers.
*
* @section Adc_h_REF_4
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared 
* in one and only one file.
* These objects are used in several files in the code.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, 
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Adc.h
*/
#include "Std_Types.h"
#include "Mcal.h"
#include "Adc_Cfg.h"
#include "Adc_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc.h
*/
#define ADC_VENDOR_ID                           43
#define ADC_MODULE_ID                           123
#define ADC_AR_RELEASE_MAJOR_VERSION            4
#define ADC_AR_RELEASE_MINOR_VERSION            2
/** @violates @ref Adc_h_REF_3 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers */
#define ADC_AR_RELEASE_REVISION_VERSION         2
#define ADC_SW_MAJOR_VERSION                    1
#define ADC_SW_MINOR_VERSION                    0
#define ADC_SW_PATCH_VERSION                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
* @file           Adc.h
*/
/** @violates @ref Adc_h_REF_3 Identifier clash */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc.h and Std_Types.h are different"
 #endif
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc.h and Mcal.h are different"
 #endif 
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_VENDOR_ID_CFG)
#error "Adc.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc.h and Adc_Cfg.h are different"
#endif

/* Check if source file and Adc Types header file are of the same vendor */
#if (ADC_VENDOR_ID != ADC_VENDOR_ID_TYPES)
#error "Adc.h and Adc_Types.h have different vendor ids"
#endif

/* Check if source file and Adc Types header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION != ADC_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION != ADC_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION != ADC_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Adc.h and Adc_Types.h are different"
#endif

/* Check if source file and Adc Types header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION != ADC_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION != ADC_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION != ADC_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Adc.h and Adc_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*       Development errors.
*       The following errors shall be detectable by the ADC module depending on its 
*       configuration (development / production mode).
*
*       All error codes
*
*/

/**
* @brief   API service used without Adc module initialization
* */
#define ADC_E_UNINIT                                 ((uint8)0x0AU)

/**
* @brief   Adc module is busy with a running operation 
* */
#define ADC_E_BUSY                                   ((uint8)0x0BU)

/**
* @brief   Adc module is in idle state
* */
#define ADC_E_IDLE                                   ((uint8)0x0CU)

/**
* @brief   The ADC module is already initilized 
* */
#define ADC_E_ALREADY_INITIALIZED                    ((uint8)0x0DU)

/**
* @brief   The ADC module is not properly configured 
* */
#define ADC_E_PARAM_CONFIG                           ((uint8)0x0EU)

/**
* @brief   API service is called using an invalid pointer (e.g. the pointer should not be NULL).
* */
#define ADC_E_PARAM_POINTER                          ((uint8)0x14U)

/**
* @brief   API service used with an invalid ADC group.
* */
#define ADC_E_PARAM_GROUP                            ((uint8)0x15U)

/**
* @brief   API service used with an invalid ADC Conversion Mode.
* */
#define ADC_E_WRONG_CONV_MODE                        ((uint8)0x16U)

/**
* @brief   API service used with an invalid ADC Trigger Source.
* */
#define ADC_E_WRONG_TRIGG_SRC                        ((uint8)0x17U)

/**
* @brief   Check the notification capability of a group.
* */
#define ADC_E_NOTIF_CAPABILITY                       ((uint8)0x18U)

/**
* @brief   API service used without initializing the buffer.
* */
#define ADC_E_BUFFER_UNINIT                          ((uint8)0x19U)
/**
* @brief   One or more ADC group/channel not in IDLE state.
* */
#define ADC_E_NOT_DISENGAGED                        ((uint8)0x1AU)
/**
* @brief   Unsupported power state request.
* */
#define ADC_E_POWER_STATE_NOT_SUPPORTED             ((uint8)0x1BU)
/**
* @brief   Requested power state can not be reached directly.
* */
#define ADC_E_TRANSITION_NOT_POSSIBLE               ((uint8)0x1CU)
/**
* @brief   ADC not prepared for target power state.
* */
#define ADC_E_PERIPHERAL_NOT_PREPARED               ((uint8)0x1DU)

/**
* @brief    The Adc_StartGroupConversion and Adc_EnableHardwareTrigger services can not queue 
            another conversion (queue is full)
*/ 
#define ADC_E_QUEUE_FULL                             ((uint8)0x20U)

#if (ADC_SET_MODE_API == STD_ON)     
/**
* @brief   An error occurred when the Adc_SetMode services is used.
* */    
#define ADC_E_SET_MODE                               ((uint8)0x21U)
#endif        
                                       
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)   
/**
* @brief   Wrong trigger source to be used for the group.
* */      
#define ADC_E_PARAM_TRIGGER                          ((uint8)0x22U)
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief   Adc_EnableChannel or Adc_DisableChannel services called with a wrong channel.
* */   
/** @violates @ref Adc_h_REF_3 Identifier exceeds 31 characters */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP       ((uint8)0x23U)
/**
* @brief   Adc_EnableChannel or Adc_DisableChannel services called with a wrong channel identifier (ID).
* */  
/** @violates @ref Adc_h_REF_3 Identifier exceeds 31 characters */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID          ((uint8)0x24U)
#endif

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
* @brief   Adc_ConfigureThreshold service is called for a wrong group.
* */  
#define ADC_E_WRONG_CONF_THRHLD_GROUP                ((uint8)0x25U)
/**
* @brief   Adc_ConfigureThreshold service is called using wrong values.
* */ 
#define ADC_E_WRONG_CONF_THRHLD_VALUE                ((uint8)0x26U)
#endif

/**
* @brief   API service called using a wrong ADC unit.
* */ 
#define ADC_E_PARAM_UNIT                             ((uint8)0x27U)

#if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)
/**
* @brief   API service called using a wrong CTU trigger.
* */ 
#define ADC_E_WRONG_CTUV2_TRIGGER                    ((uint8)0x28U)
/**
* @brief   API service called using a wrong CTU CLCR trigger.
* */ 
#define ADC_E_WRONG_CTUV2_CLCR_TRIGGER               ((uint8)0x29U)
#endif

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   Adc_SetClockMode service called using an invalid clock mode.
* */ 
#define ADC_E_INVALID_CLOCK_MODE                     ((uint8)0x2AU)
#endif

#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief   Adc_SetChannel service called using an invalid channel list.
* */ 
#define ADC_E_PARAM_CHANNEL                          ((uint8)0x2BU)
#endif


#define ADC_E_BUFFER_UNINIT_LIST                     ((uint32)0x00000001U)
#define ADC_E_WRONG_TRIGG_SRC_LIST                   ((uint32)0x00000002U)
#define ADC_E_QUEUE_FULL_LIST                        ((uint32)0x00000004U)
#define ADC_E_WRONG_CONV_MODE_LIST                   ((uint32)0x00000008U)
/** @violates @ref Adc_h_REF_3 Identifier exceeds 31 characters */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_GROUP_LIST  ((uint32)0x00000010U)
/** @violates @ref Adc_h_REF_3 Identifier exceeds 31 characters */
#define ADC_E_WRONG_ENABLE_CH_DISABLE_CH_ID_LIST     ((uint32)0x00000020U)
#define ADC_E_SET_MODE_LIST                          ((uint32)0x00000040U)

/**
          All AUTOSAR API's service IDs
*/

/**
* @brief API service ID for Adc_Init function
* */
#define ADC_INIT_ID                                  0x00U

/**
* @brief API service ID for Adc_DeInit function
* */
#define ADC_DEINIT_ID                                0x01U

/**
* @brief API service ID for Adc_StartGroupConversion function
* */
#define ADC_STARTGROUPCONVERSION_ID                  0x02U

/**
* @brief API service ID for Adc_StopGroupConversion function
* */
#define ADC_STOPGROUPCONVERSION_ID                   0x03U

/**
* @brief API service ID for Adc_ReadGroup function
* */
#define ADC_VALUEREADGROUP_ID                        0x04U

/**
* @brief API service ID for Adc_EnableHardwareTrigger function
* */
#define ADC_ENABLEHARDWARETRIGGER_ID                 0x05U

/**
* @brief API service ID for Adc_DisableHardwareTrigger function
* */
#define ADC_DISABLEHARDWARETRIGGER_ID                0x06U

/**
* @brief API service ID for Adc_EnableGroupNotification function
* */
#define ADC_ENABLEGROUPNOTIFICATION_ID               0x07U

/**
* @brief API service ID for Adc_DisableGroupNotification function
* */
#define ADC_DISABLEGROUPNOTIFICATION_ID              0x08U

/**
* @brief API service ID for Adc_GetGroupStatus function
* */
#define ADC_GETGROUPSTATUS_ID                        0x09U

/**
* @brief API service ID for Adc_GetVersionInfo function
* */
#define ADC_GETVERSIONINFO_ID                        0x0AU

/**
* @brief API service ID for Adc_GetStreamLastPointer function
* */
#define ADC_GETSTREAMLASTPOINTER_ID                  0x0BU

/**
* @brief API service ID for Adc_SetupResultBuffer function
* */
#define ADC_SETUPRESULTBUFFER_ID                     0x0CU
/**
* @brief API service ID for Adc_SetPowerState function
* */
#define ADC_SETPOWERSTATE_ID                         0x10U
/**
* @brief API service ID for Adc_GetCurrentPowerState function
* */
#define ADC_GETCURRENTPOWERSTATE_ID                  0x11U
/**
* @brief API service ID for Adc_GetTargetPowerState function
* */
#define ADC_GETTARGETPOWERSTATE_ID                   0x12U
/**
* @brief API service ID for Adc_PreparePowerState function
* */
#define ADC_PREPAREPOWERSTATE_ID                     0x13U

/**
*        All non AUTOSAR API's service IDs
**       NOTE: Parameters used when raising an error/exception
*/



#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
/**
* @brief API service ID for Adc_HwResultReadGroup function
* */ 
#define ADC_HWRESULTREADGROUP_ID                     0x20U
/**
* @brief API service ID for Adc_EnableCTUTrigge function
* */ 
#define ADC_ENABLECTUTRIGGER_ID                      0x21U
/**
* @brief API service ID for Adc_DisableCTUTrigger function
* */ 
#define ADC_DISABLECTUTRIGGER_ID                     0x22U
#endif        
                                       
#if (ADC_SET_MODE_API == STD_ON)    
/**
* @brief API service ID for Adc_SetMode function
* */    
#define ADC_SETMODE_ID                               0x23U
#endif

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief API service ID for Adc_SetClockMode function
* */
#define ADC_SETCLOCKMODE_ID                          0x24U
#endif

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief API service ID for Adc_EnableChannel function
* */
#define ADC_ENABLE_CHANNEL_ID                        0x25U
/**
* @brief API service ID for Adc_DisableChannel function
* */
#define ADC_DISABLE_CHANNEL_ID                       0x26U
#endif

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
/**
* @brief API service ID for Adc_GetInjectedConversionStatus function
* */
#define ADC_GETINJECTEDCONVERSIONSTATUS_ID           0x27U
#endif

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief API service ID for Adc_Calibrate function
* */
#define ADC_CALIBRATE_ID                             0x28U
#endif

#if (ADC_SELF_TEST == STD_ON)
#define ADC_SELFTEST_ID                              0x29U
#endif

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
* @brief API service ID for Adc_ConfigureThreshold function
* */    
#define ADC_CONFIGURE_THRESHOLD_ID                   0x2AU
#endif

#if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)
/**
* @brief API service ID for Adc_SetCtu2TriggerHandlerCtrlRegs function
* */
#define CTUV2_SET_TRG_HANDLER_CTRL_REGS_ID              (0x2BU)
/**
* @brief API service ID for Adc_Ctu2TriggerHandlerCtrlRegsEnableDisable function
* */
#define CTUV2_EN_DIS_TRG_HANDLER_CTRL_REGS_ID                 (0x2CU)
/**
* @brief API service ID for ADC_CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS function
* */
/** @violates @ref Adc_h_REF_3 Identifier exceeds 31 characters */
#define CTUV2_SET_CMD_LIST_HANDLER_CTRL_REGS_ID             (0x2DU)
/**
* @brief API service ID for Adc_SetCtu2TriggerCompareRegs function
* */
/** @violates @ref Adc_h_REF_3 Identifier exceeds 31 characters */
#define CTUV2_SET_TRIGGER_COMPARE_REGS_ID        (0x2EU)
#endif

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief API service ID for Adc_EnableCtuControlMode function
* */    
#define ADC_ENABLECTUCONTROLMODE_ID                  (0x2FU)
/**
* @brief API service ID for Adc_DisableCtuControlMode function
* */
#define ADC_DISABLECTUCONTROLMODE_ID                 (0x30U)
#endif

#if (ADC_SETCHANNEL_API == STD_ON)
/**
* @brief API service ID for Adc_SetChannel function
* */
#define ADC_SETCHANNEL_ID                            (0x31U)
#endif
/* Re-define as workaround e9061 on RaceRunner IS */
#ifdef ERR_IPV_ADCDIG_0017
    #if (ERR_IPV_ADCDIG_0017 == STD_ON)
        #ifdef ADC_DUAL_CLOCK_MODE
            #undef ADC_DUAL_CLOCK_MODE
            #define ADC_DUAL_CLOCK_MODE         (STD_OFF)
        #endif
    #endif
#endif

/**
* @brief          Mask used to verify the DATA registers content.
*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADC_DATA_MASK_U16         (0xFFFFU)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/**
* @brief          Used to point the configuration structure.
*/
extern P2CONST(Adc_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

/** @violates @ref Adc_h_REF_4  External object declared more than once*/
extern VAR(Adc_GroupStatusType, ADC_VAR) Adc_aGroupStatus[ADC_MAX_GROUPS];
/** @violates @ref Adc_h_REF_4  External object declared more than once*/
extern VAR(Adc_UnitStatusType , ADC_VAR) Adc_aUnitStatus[ADC_MAX_HW_UNITS];

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

FUNC(void, ADC_CODE) Adc_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) ConfigPtr
);

FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
);

#if (ADC_DEINIT_API == STD_ON)
FUNC(void, ADC_CODE) Adc_DeInit(void);
#endif /* ADC_DEINIT_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
FUNC(void, ADC_CODE) Adc_StartGroupConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(void, ADC_CODE) Adc_StopGroupConversion
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (ADC_READ_GROUP_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr
);
#endif /* ADC_READ_GROUP_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableGroupNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(void, ADC_CODE) Adc_DisableGroupNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);

FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr
);

#if (ADC_VERSION_INFO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_GetVersionInfo
(
    P2VAR(Std_VersionInfoType , AUTOMATIC, ADC_APPL_DATA) versioninfo
);
#endif /* ADC_VERSION_INFO_API == STD_ON */

#if (ADC_SET_MODE_API == STD_ON)
FUNC (Std_ReturnType, ADC_CODE) Adc_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) SetMode
);
#endif

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableCTUTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);

FUNC(void, ADC_CODE) Adc_DisableCTUTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);

FUNC(Std_ReturnType, ADC_CODE) Adc_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataPtr
);
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableChannel
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_ChannelType, AUTOMATIC) Channel
);
FUNC(void, ADC_CODE) Adc_DisableChannel
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_ChannelType, AUTOMATIC) Channel
);
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#if (ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON)
FUNC(Adc_StatusType, ADC_CODE) Adc_GetInjectedConversionStatus
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* ADC_GET_INJECTED_CONVERSION_STATUS_API == STD_ON */

#if (ADC_CALIBRATION == STD_ON)
FUNC(void, ADC_CODE) Adc_Calibrate
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2VAR(Adc_CalibrationStatusType , AUTOMATIC, ADC_APPL_DATA) pStatus  
);
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_SELF_TEST == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_SelfTest
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* ADC_SELF_TEST == STD_ON */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_ConfigureThreshold
(
    VAR(Adc_GroupType, AUTOMATIC) GroupId,
    VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
    VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
);
#endif /*  ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_SetClockMode
(
    VAR(Adc_DualClockModeType, AUTOMATIC) eClockMode
);
#endif

#if (CTUV2_ENABLE_TRIGGER_CONFIGURATION_APIS == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCtu2TriggerHandlerCtrlRegs
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(uint8, AUTOMATIC) u8ThcrValue
);
FUNC(Std_ReturnType, ADC_CODE) Adc_Ctu2TriggerHandlerCtrlRegsEnableDisable
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(boolean, AUTOMATIC) bEnable
);
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCtu2CmdListHandlerCtrlRegs
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(uint8, AUTOMATIC) u8ClcrValue
);
FUNC(Std_ReturnType, ADC_CODE) Adc_SetCtu2TriggerCompareRegs
(
    VAR(uint8, AUTOMATIC) u8Trigger,
    VAR(uint16, AUTOMATIC) u16CompareValue
);
#endif

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
FUNC(void, ADC_CODE) Adc_EnableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

FUNC(void, ADC_CODE) Adc_DisableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if (ADC_SETCHANNEL_API == STD_ON)
FUNC(void, ADC_CODE) Adc_SetChannel
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupDefType, AUTOMATIC, ADC_APPL_CONST) pChannel,
    P2CONST(uint16, AUTOMATIC, ADC_APPL_CONST) pDelays,
    CONST(uint32, AUTOMATIC) u32Mask,
    CONST(Adc_ChannelIndexType, AUTOMATIC) NumberOfChannel
);
#endif /* ADC_SETCHANNEL_API == STD_ON */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
FUNC(Std_ReturnType, ADC_CODE) Adc_SetPowerState
(
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
);

FUNC(Std_ReturnType, ADC_CODE) Adc_GetCurrentPowerState
(
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) CurrentPowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
);

FUNC(Std_ReturnType, ADC_CODE) Adc_GetTargetPowerState
(
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) TargetPowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
);

FUNC(Std_ReturnType, ADC_CODE) Adc_PreparePowerState
(
    VAR(Adc_PowerStateType, AUTOMATIC) PowerState,
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result
);

#if (ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
FUNC(void, ADC_CODE) Adc_Main_PowerTransitionManager(void);
#endif /* (ADC_POWER_STATE_ASYNCH_MODE_SUPPORTED == STD_ON) */
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#ifdef ERR_IPV_ADC12B_LBA_0001
#ifdef ADC_WORK_AROUND_ERRATA_E8188
#if (ADC_WORK_AROUND_ERRATA_E8188 == STD_ON)
FUNC(void, ADC_CODE) Adc_StopCurrentWorkAround(void);
#endif
#endif
#endif

#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_H */

/** @} */
