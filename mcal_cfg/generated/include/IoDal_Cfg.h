/**
*   @file    IoDal_Cfg.h
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component configuration file
*   @details This file implements the IODAL configuration header.
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
#ifndef IODAL_Cfg_H
#define IODAL_Cfg_H

#ifdef __cplusplus
extern "C"{
#endif


#include "IoDal_Types.h"
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#define IODAL_CFG_VENDOR_ID                       43

#define IODAL_CFG_AR_RELEASE_MAJOR_VERSION        4
#define IODAL_CFG_AR_RELEASE_MINOR_VERSION        2
#define IODAL_CFG_AR_RELEASE_REVISION_VERSION     2

#define IODAL_CFG_SW_MAJOR_VERSION                1
#define IODAL_CFG_SW_MINOR_VERSION                0
#define IODAL_CFG_SW_PATCH_VERSION                1


/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if IoDal_Cfg.h header file and IoDal_Types.h header file are of the same vendor */
#if (IODAL_CFG_VENDOR_ID != IODAL_TYPES_VENDOR_ID)
    #error "IoDal_Cfg.h and IoDal_Types.h have different vendor ids"
#endif

/* Check if IoDal_Cfg.h header file and IoDal_Types.h header file are of the same Autosar version */
#if ((IODAL_CFG_AR_RELEASE_MAJOR_VERSION != IODAL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_CFG_AR_RELEASE_MINOR_VERSION != IODAL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_CFG_AR_RELEASE_REVISION_VERSION != IODAL_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Cfg.h and IoDal_Types.h are different"
#endif

/* Check if IoDal_Cfg.h header file and IoDal_Types.h header file are of the same Software version */
#if ((IODAL_CFG_SW_MAJOR_VERSION != IODAL_TYPES_SW_MAJOR_VERSION) || \
     (IODAL_CFG_SW_MINOR_VERSION != IODAL_TYPES_SW_MINOR_VERSION) || \
     (IODAL_CFG_SW_PATCH_VERSION != IODAL_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal_Cfg.h and IoDal_Cfg.h are different"
#endif



/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#define    IODAL_MAX_DIO_CHANNELS_HW_VAR_0            3U
#define    IODAL_MAX_DIO_DESCRIPTORS                3U
    
#define    IODAL_MAX_PWM_CHANNELS_HW_VAR_0            3U
#define    IODAL_MAX_PWM_DESCRIPTORS                3U
    
#define    IODAL_MAX_ANALOG_CHANNELS_HW_VAR_0        3U
#define    IODAL_MAX_ANI_DESCRIPTORS                3U
    
#define    IODAL_MAX_OCU_CHANNELS_HW_VAR_0            1U
#define    IODAL_MAX_OCU_DESCRIPTORS                1U
    
#define    IODAL_MAX_ICU_CHANNELS_HW_VAR_0            0U
#define    IODAL_MAX_ICU_DESCRIPTORS                0U
    
#define    IODAL_MAX_CHANNELS_HW_VAR_0                10U

#define    IODAL_MAX_HW_VARIANTS                    1U

#define IODAL_DEV_ERROR_DETECT                  (STD_OFF)
#define IODAL_ENABLE_DEM_REPORT_ERROR_STATUS    (STD_OFF)

/**
    * @brief          Symbolic name for the configuration IoDal channels.
*
*/
#define    IoDAL_ADCTRIGGER        (0U)
#define    IoDAL_AN_FBK_PWM0        (1U)
#define    IoDAL_AN_FBK_PWM1        (2U)
#define    IoDAL_AN_POT        (3U)
#define    IoDAL_DIGITAL_KEY        (4U)
#define    IoDAL_DOUT0        (5U)
#define    IoDAL_DOUT1        (6U)
#define    IoDAL_PMW1        (7U)
#define    IoDAL_PMW2        (8U)
#define    IoDAL_PWM0        (9U)

#define IODAL_PWM_EXT_DEV          (STD_OFF)
#define IODAL_PWM_SYNC             (STD_OFF)      
#define IODAL_DIO_EXT_DEV          (STD_OFF)
#define IODAL_VARIABLE_PERIOD      (STD_OFF)

extern void IoDal_AdcBufferSetup(void);
extern const IoDal_BswIoConfigType IoDal_Config[IODAL_MAX_HW_VARIANTS];

/*================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif  /* IODAL_TYPES_H*/
