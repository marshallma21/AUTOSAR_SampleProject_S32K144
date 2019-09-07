/**
*   @file    IoDal_Drv_Cfg.h
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component low-level configuration file
*   @details This file implements the IODAL configuration header for connection to low-level drivers.
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
#ifndef IODAL_DRV_CFG_H
#define IODAL_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

#define IFWK_USE_ADC

#define IFWK_USE_PWM

#define IFWK_USE_OCU

#define IFWK_USE_DIO


#ifdef IFWK_USE_DIO
    #include "Dio.h"
    #include "Port.h"
#endif

#ifdef IFWK_USE_ADC
    #include "Adc.h"
#endif

#ifdef IFWK_USE_PWM
    #include "Pwm.h"
#endif

#ifdef IFWK_USE_OCU
    #include "Ocu.h"
#endif    
    
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#define IODAL_DRV_CFG_VENDOR_ID                       43

#define IODAL_DRV_CFG_AR_RELEASE_MAJOR_VERSION        4
#define IODAL_DRV_CFG_AR_RELEASE_MINOR_VERSION        2
#define IODAL_DRV_CFG_AR_RELEASE_REVISION_VERSION     2

#define IODAL_DRV_CFG_SW_MAJOR_VERSION                1
#define IODAL_DRV_CFG_SW_MINOR_VERSION                0
#define IODAL_DRV_CFG_SW_PATCH_VERSION                1
    
    
typedef uint16 IoDal_PwmPeriodType;
    
    
typedef uint16 IoDal_Dio_ExtDev_Config;
typedef uint16 IoDal_Pwm_ExtDev_Config;

typedef void (*IoDal_Dio_InitCalloutType)(const IoDal_Dio_ExtDev_Config *);
typedef void (*IoDal_Dio_DeInitCalloutType)(void);
typedef void (*IoDal_Dio_UpdateCalloutType)(uint8, uint8 *);

typedef void (*IoDal_Pwm_InitCalloutType)(const IoDal_Pwm_ExtDev_Config *);
typedef void (*IoDal_Pwm_DeInitCalloutType)(void);
typedef void (*IoDal_Pwm_UpdateCalloutType)(uint8, uint16 *);


/**
* @brief          Structure to configure external devices (SPI).
* @details        Data structure containing the set of configuration parameters required 
*                 for initializin external SPI devices.
*/
typedef struct
{  
   /**< @brief Pointer to configuration data of external (SPI) device */
   P2CONST(IoDal_Dio_ExtDev_Config, AUTOMATIC, IODAL_APPL_CONST)   pExtDioChannelCfg;
  
   CONST(IoDal_Dio_InitCalloutType,       IODAL_CONST) pfDio_ExtDev_InitHandler;
   CONST(IoDal_Dio_DeInitCalloutType,     IODAL_CONST) pfDio_ExtDev_DeInitHandler;
   CONST(IoDal_Dio_UpdateCalloutType,     IODAL_CONST) pfDio_ExtDev_UpdateHandler;
} IoDal_ExternalDioDeviceConfig;

/**
* @brief          Structure to configure external devices (SPI).
* @details        Data structure containing the set of configuration parameters required 
*                 for initializin external SPI devices.
*/
typedef struct
{  
   /**< @brief Pointer to configuration data of external (SPI) device */
   P2CONST(IoDal_Pwm_ExtDev_Config, AUTOMATIC, IODAL_APPL_CONST)   pExtPwmChannelCfg;
   
   CONST(IoDal_Pwm_InitCalloutType,        IODAL_CONST) pfPwm_ExtDev_InitHandler;
   CONST(IoDal_Pwm_DeInitCalloutType,      IODAL_CONST) pfPwm_ExtDev_DeInitHandler;
   CONST(IoDal_Pwm_UpdateCalloutType,      IODAL_CONST) pfPwm_ExtDev_UpdateHandler;
} IoDal_ExternalPwmDeviceConfig;    

/*================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif  /* IODAL_TYPES_H*/
