/**
*   @file        IoDal_Types.h
*   @version     1.0.1
*
*   @brief       AUTOSAR - Integration Framework - Types file for IO Driver Abstraction Layer
*   @details     This file implements the IODAL Types
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup IODAL
*   @{
*/
/*=========================================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
============================================================================================================================*/
/*============================================================================================================================
==============================================================================================================================*/
#ifndef IODAL_TYPES_H
#define IODAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "IoDal_Drv_Cfg.h"

/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define IODAL_TYPES_VENDOR_ID                           43
#define IODAL_TYPES_MODULE_ID                           100

#define IODAL_TYPES_AR_RELEASE_MAJOR_VERSION            4
#define IODAL_TYPES_AR_RELEASE_MINOR_VERSION            2
#define IODAL_TYPES_AR_RELEASE_REVISION_VERSION         2

#define IODAL_TYPES_SW_MAJOR_VERSION                    1
#define IODAL_TYPES_SW_MINOR_VERSION                    0
#define IODAL_TYPES_SW_PATCH_VERSION                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if types header file and IODAL driver configuration header file are of the same vendor */
#if (IODAL_TYPES_VENDOR_ID != IODAL_DRV_CFG_VENDOR_ID)
    #error "IoDal_Types.h and IoDal_Drv_Cfg.h have different vendor ids"
#endif

/* Check if types header file and IODAL driver configuration header file are of the same Autosar version */
#if ((IODAL_TYPES_AR_RELEASE_MAJOR_VERSION != IODAL_DRV_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_TYPES_AR_RELEASE_MINOR_VERSION != IODAL_DRV_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_TYPES_AR_RELEASE_REVISION_VERSION != IODAL_DRV_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Types.h and IoDal_Drv_Cfg.h are different"
#endif

/* Check if header file and IODAL driver configuration header file are of the same software version */
#if ((IODAL_TYPES_SW_MAJOR_VERSION != IODAL_DRV_CFG_SW_MAJOR_VERSION) || \
     (IODAL_TYPES_SW_MINOR_VERSION != IODAL_DRV_CFG_SW_MINOR_VERSION) || \
     (IODAL_TYPES_SW_PATCH_VERSION != IODAL_DRV_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal_Types.h and IoDal_Drv_Cfg.h are different"
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
    IODAL_ANALOG_SW_TRIG  = 0U,        /**< @brief IODAL channel is of type analog SW triggered. */
	IODAL_ANALOG_HW_TRIG  = 1U,        /**< @brief IODAL channel is of type analog HW triggered. */
    IODAL_DIO_INPUT,                   /**< @brief IODAL channel is of type digital input. */
    IODAL_TIMER_CAPTURE, 	           /**< @brief IODAL channel is of type timer input capture (ICU). */
	IODAL_DIO_OUTPUT, 	               /**< @brief IODAL channel is of type digital output. */
	IODAL_TIMER_OUTPUT, 	           /**< @brief IODAL channel is of type digital input. */
	IODAL_EXT_DEV_INPUT,               /**< @brief IODAL channel is of type external device input. */ 
	IODAL_EXT_DEV_OUTPUT,              /**< @brief IODAL channel is of type external device output. */
	IODAL_PWM_VARIBLE_PERIOD_OUTPUT,   /**< @brief IODAL channel is of type variable period PWM. */
	IODAL_PWM_FIXED_PERIOD_OUTPUT,     /**< @brief IODAL channel is of type fixed period PWM */
	IODAL_PWM_EXT_DEV_OUTPUT, 	       /**< @brief IODAL channel is of type external device PWM output. */
	IODAL_PWM_SYNC_OUTPUT             /**< @brief IODAL channel is of type synced output PWM */

} IoDal_BswChannelType;


typedef enum
{
    IODAL_AD_CONV_NO_ERROR  = 0U,        /**< @brief mark No error detected for analog descriptor. */
	IODAL_AD_CONV_BUSY         = 1U,     /**< @brief mark conversion on-going for analog descriptor. */
    IODAL_AD_CONV_ERROR_STATE,           /**< @brief mark conversion error detected for analog descriptor. */ 
    IODAL_AD_CONV_NOT_STARTED,           /**< @brief mark conversion not started for analog descriptor. */
	IODAL_AD_CONV_NOT_INIT,              /**< @brief mark conversion not initialized for analog descriptor. */
	IODAL_AD_CONV_INIT,                  /**< @brief mark fist conversion to be initialized for analog descriptor. */
	IODAL_AD_CONV_INVALID               /**< @brief mark conversion as invalid for analog descriptor. */ 
}IoDal_AnalogStatusType;



/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          IoDal Basic Software channel Id type
* @details        Type used for Bsw Iodal channels;
*/
typedef uint16                                                IoDal_BswDescriptorIdType;

/**
* @brief          IoDal Basic Software channel Id type
* @details
*/
typedef uint8                                                 IoDal_BswChannelIdType;


typedef uint16                                                IoDal_BswDutyType;


typedef IoDal_PwmPeriodType                                   IoDal_BswPeriodType;

typedef uint16                                                IoDal_BswValueType;


/**
* @brief          Structure to configure PWM internal channels
* @details        Data structure containing the set of configuration parameters required 
*                 for setting up PWM sync channels.
*/
typedef struct
{  
  /**< @brief If of HW timer module of all synced channels */
  CONST(uint8, IODAL_VAR)                                          UsedSyncPwmTimer;
  
  /**< @brief HW timer channels which run in sync */
  CONST(uint16, IODAL_VAR)                                         SubmoduleMask;  
    
 } IoDal_InternalPwmConfig;


#ifdef IFWK_USE_DIO
/**
* @brief          Structure to configure digital channels
* @details        Data structure containing the set of configuration parameters required 
*                 for setting up digital input-output channels.
*/
typedef struct
{  
  /**< @brief Referenced Dio channel id*/ 
  CONST(Dio_ChannelType, AUTOMATIC)                                  DioChannel;
    
  CONST(Dio_LevelType, AUTOMATIC)                                    ChannelLevel;
	
  /**< @brief Pointer to configuration data of external (SPI) device */
  P2CONST(IoDal_ExternalDioDeviceConfig, AUTOMATIC, IODAL_APPL_CONST)   pExtDioChannelCfg;
    
} IoDal_DigitalDescriptorType;
#endif


#ifdef IFWK_USE_PWM
/**
* @brief          Structure to configure Pwm channels
* @details        Data structure containing the set of configuration parameters required 
*                 for setting up Pwm output channels.
*/
typedef struct
{  
  /**< @brief Referenced Pwm channel id*/
  CONST(Pwm_ChannelType, AUTOMATIC)                                  PwmChannel;

  /**< @brief Pointer to configuration data of the internal Pwm channel*/
  P2CONST(IoDal_InternalPwmConfig, AUTOMATIC, IODAL_APPL_CONST)      pIntPwmChannelCfg;
   
  /**< @brief Pointer to configuration data of external (SPI) device */   
  P2CONST(IoDal_ExternalPwmDeviceConfig, AUTOMATIC, IODAL_APPL_CONST) pExtPwmChannelCfg;  
    
} IoDal_PwmDescriptorType;
#endif


#ifdef IFWK_USE_ICU
/**
* @brief          Structure to configure Input capture (ICU) channels
* @details        Data structure containing the set of configuration parameters required 
*                 for setting up ICU channels.
*/
typedef struct
{  
  /**< @brief Referenced Icu channel id*/
  CONST(Icu_ChannelType, AUTOMATIC)                               InputCaptureChannel;
      
} IoDal_IcuDescriptorType;
#endif


#ifdef IFWK_USE_OCU
/**
* @brief          Structure to configure Output compare (OCU) channels
* @details        Data structure containing the set of configuration parameters required 
*                 for setting up OCU channels.
*/
typedef struct
{  
  /**< @brief Referenced Ocu channel id*/
  CONST(Ocu_ChannelType, AUTOMATIC)                                OcuChannel;
  /**< @brief Referenced Ocu channel id*/
  CONST(uint8, AUTOMATIC)                                          NoTimeEvents;
  /**< @brief Referenced Ocu channel id*/
  P2CONST(Ocu_ValueType, AUTOMATIC, IODAL_APPL_CONST)              pTimeTableEventsList;  
} IoDal_OcuDescriptorType;
#endif


#ifdef IFWK_USE_ADC
/**
* @brief          Structure to configure ADC channels
* @details        Data structure containing the set of configuration parameters required 
*                 for setting up ADC channels.
*/
typedef struct
{  
  /**< @brief Referenced ADC group id*/
  CONST(Adc_GroupType, AUTOMATIC)                                   AdcGroupId;
    
  /**< @brief Referenced group size (number of channel in given group)*/
  CONST(Adc_ChannelType, AUTOMATIC)                                 AdcChannelId;

   /**< @brief Referenced group size (number of channel in given group)*/
  CONST(Ocu_ValueType, AUTOMATIC)                                    EstimatedConvTime;
  
  /**< @brief Referenced to Hw-Sw trigger channel used by ADC group*/
  P2VAR(Adc_ValueGroupType, AUTOMATIC, IODAL_APPL_DATA  )            pAdConvResultsPtr;
  
  /**< @brief Referenced to Hw-Sw trigger channel used by ADC group*/
  CONST(uint8, AUTOMATIC)                                           TimeTriggerEntry;  
  
} IoDal_AnalogDescriptorType;
#endif

/**
* @brief          Structure used form IODAL channel mapping.
* @details        
*/
typedef struct
{  
  /**< @brief Bsw channel type*/
  CONST(IoDal_BswChannelType, AUTOMATIC)                               BswChannelType;

  /**< @brief Bsw channel id*/
  CONST(IoDal_BswDescriptorIdType, AUTOMATIC)                          BswDescriptorIndex;
 
} IoDal_BswChannelMapType;


#ifdef IFWK_USE_ADC
/**
* @brief          Function pointer type used to define the callout which shall initialize ADC internal buffers.
* @details        
*/
typedef void (*IoDal_CalloutType)(void);
#endif

/**
* @brief          Structure containing configuration data for the initialization of IODAL .
* @details        Data structure containing the set of configuration parameters required
*                 for initializing the IODAL.
*/
typedef struct
{
	/**< @brief Total number of Adc groups */
	CONST(uint8, AUTOMATIC)                                           AdcDescriptorsCount;
	/**< @brief SW Trigger descriptor index*/
	CONST(uint8, AUTOMATIC)                                           AdcSwTriggerDescriptorIndex;	
	/**< @brief Total number of Pwm channels */
	CONST(uint8, AUTOMATIC)                                           PwmChannelCount;
	/**< @brief Total number of digital input-output channels */
	CONST(uint8, AUTOMATIC)                                           DioChannelCount;
    /**< @brief Total number of output compare channels */
	CONST(uint8, AUTOMATIC)                                           OcuChannelCount;
	/**< @brief Total number of input capture channels */
	CONST(uint8, AUTOMATIC)                                           IcuChannelCount;

#ifdef IFWK_USE_ADC	
	/**< @brief pointer to Analog channel descriptor */
	P2CONST(IoDal_AnalogDescriptorType, AUTOMATIC,  IODAL_APPL_CONST) pAnGroupDescriptor;
	
	/**< @brief pointer to Analog channel descriptor */
	CONST(IoDal_CalloutType, IODAL_APPL_CONST) pfAdcBufferSetupCallout;
#endif

#ifdef IFWK_USE_PWM	
	/**< @brief pointer to PWM channel descriptor*/
	P2CONST(IoDal_PwmDescriptorType, AUTOMATIC,  IODAL_APPL_CONST)    pPwmChanDescriptor;
#endif	

#ifdef IFWK_USE_DIO
	/**< @brief pointer to Digital I-O channel descriptor*/
	P2CONST(IoDal_DigitalDescriptorType, AUTOMATIC,  IODAL_APPL_CONST) pDioChanDescriptor;
#endif	

#ifdef IFWK_USE_OCU
	/**< @brief pointer to output compare channel descriptor*/
	P2CONST(IoDal_OcuDescriptorType, AUTOMATIC,  IODAL_APPL_CONST) pOcuChanDescriptor;
#endif

#ifdef IFWK_USE_ICU	
	/**< @brief pointer to input capture channel descriptor*/
	P2CONST(IoDal_IcuDescriptorType, AUTOMATIC,  IODAL_APPL_CONST) pIcuChanDescriptor;
#endif	
	/**< @brief pointer to bsw channel map*/	
	P2CONST(IoDal_BswChannelMapType,  AUTOMATIC, ADC_APPL_CONST) pBswChannelMap;

} IoDal_BswIoConfigType;



/*================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif  /* IODAL_TYPES_H*/
/** @} */
