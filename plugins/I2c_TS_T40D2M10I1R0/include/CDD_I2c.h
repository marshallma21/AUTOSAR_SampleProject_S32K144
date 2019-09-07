/**
*   @file    CDD_I2c.h
*   @implements CDD_I2c.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - High level header of I2C driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup I2C
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPI2C
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

#ifndef CDD_I2C_H
#define CDD_I2C_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section I2c_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section I2c_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section I2c_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded
* by other preprocessor directives or comments. AUTOSAR imposes the specification of the
* sections in which certain parts of the driver must be placed.
*
* @section I2c_h_REF_4
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* This is incorrectly reported by the PCLint tool used.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "CDD_I2c_Cfg.h"
#include "I2c_Types.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define I2C_VENDOR_ID                      43
#define I2C_MODULE_ID                      255
#define I2C_AR_RELEASE_MAJOR_VERSION       4
#define I2C_AR_RELEASE_MINOR_VERSION       2
/*
* @violates @ref I2c_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_REVISION_VERSION    2
#define I2C_SW_MAJOR_VERSION               1
#define I2C_SW_MINOR_VERSION               0
#define I2C_SW_PATCH_VERSION               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Cfg header file are of the same vendor */
#if (I2C_VENDOR_ID != I2C_VENDOR_ID_CFG)
    #error "CDD_I2c.h and CDD_I2c_Cfg.h have different vendor ids"
#endif
/* Check if current file and I2c_Cfg header file are of the same Autosar version */
#if (  (I2C_AR_RELEASE_MAJOR_VERSION    != I2C_AR_RELEASE_MAJOR_VERSION_CFG) || \
       (I2C_AR_RELEASE_MINOR_VERSION    != I2C_AR_RELEASE_MINOR_VERSION_CFG) || \
       (I2C_AR_RELEASE_REVISION_VERSION != I2C_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of CDD_I2c.h and CDD_I2c_Cfg.h are different"
#endif
/* Check if current file and I2c_Cfg header file are of the same Software version */
#if ( (I2C_SW_MAJOR_VERSION != I2C_SW_MAJOR_VERSION_CFG) || \
      (I2C_SW_MINOR_VERSION != I2C_SW_MINOR_VERSION_CFG) || \
      (I2C_SW_PATCH_VERSION != I2C_SW_PATCH_VERSION_CFG)    \
    )
#error "Software Version Numbers of CDD_I2c.h and CDD_I2c_Cfg.h are different"
#endif

/* Check if current file and I2c_Types header file are of the same vendor */
#if (I2C_VENDOR_ID != I2C_TYPES_VENDOR_ID)
    #error "CDD_I2c.h and I2c_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Types header file are of the same Autosar version */
#if (  (I2C_AR_RELEASE_MAJOR_VERSION    != I2C_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (I2C_AR_RELEASE_MINOR_VERSION    != I2C_TYPES_AR_RELEASE_MINOR_VERSION) || \
       (I2C_AR_RELEASE_REVISION_VERSION != I2C_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c.h and I2c_Types.h are different"
#endif
/* Check if current file and I2c_Types header file are of the same Software version */
#if ( (I2C_SW_MAJOR_VERSION != I2C_TYPES_SW_MAJOR_VERSION) || \
      (I2C_SW_MINOR_VERSION != I2C_TYPES_SW_MINOR_VERSION) || \
      (I2C_SW_PATCH_VERSION != I2C_TYPES_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of CDD_I2c.h and I2c_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ( (I2C_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
          (I2C_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_I2c.h and Mcal.h are different"
    #endif
#endif

/* Check if current file and DEM header file are of the same version */
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Dem header file are of the same version */
  #if ( (I2C_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (I2C_AR_RELEASE_MINOR_VERSION != DEM_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of CDD_I2c.h and StdRegMacros.h are different"
  #endif
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/**
* @brief            API service used without module initialization
* @details          The I2C Driver module shall report the development error "I2C_E_UNINIT (0x01)", 
*                   when the API Service is used without module initialization.
* 
* @api
*/
#define I2C_E_UNINIT            ((uint8)0x01U)

/**
* @brief            API service used with an invalid or inactive channel parameter
* @details          The I2C Driver module shall report the development error 
*                   "I2C_E_INVALID_CHANNEL (0x02)", when API Service used with 
*                   an invalid or inactive channel parameter.
* 
* @api
*/
#define I2C_E_INVALID_CHANNEL   ((uint8)0x02U)

/**
* @brief            API service called with invalid configuration pointer
* @details          The I2C Driver module shall report the development error 
*                   "I2C_E_INVALID_POINTER (0x03)", when API Service is called 
*                   with invalid configuration pointer.
* 
* @api
*/
#define I2C_E_INVALID_POINTER   ((uint8)0x03U)

/**
* @brief            Initialization called when already initialized
* @details          The I2C Driver module shall report the development error 
*                   "I2C_E_ALREADY_INITIALIZED (0x04)", when initialization is called 
*                   when the driver is already initialized.
* 
* @api
*/
#define I2C_E_ALREADY_INITIALIZED  ((uint8)0x04U)

/**
* @brief            Number of bytes is exceeded, if a limit exists for the channel
* @details          The I2C Driver module shall report the development error 
*                   "I2C_E_INVALID_BUFFER_SIZE (0x05)", when I2c_SyncTransmit or 
*                   I2c_AsyncTransmit are called with a number of bytes that exceed the
*                   maximum number of bytes supported for that channel.
* 
* @api
*/
#define I2C_E_INVALID_BUFFER_SIZE  ((uint8)0x05U)

/**
* @brief            I2C driver states
* @details          The state I2C_UNINIT means that the I2C module has not 
*                   been initialized yet and cannot be used.
* 
* @api
*/
#define I2C_UNINIT              (0x01U)

/**
* @brief            I2C driver states
* @details          The I2C_INIT state indicates that the I2C driver has been 
*                   initialized, making each available channel ready for service.
* 
* @api
*/
#define I2C_INIT                (0x02U)

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (I2C_PRECOMPILE_SUPPORT == STD_OFF)

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

I2C_CONF_PB

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

#endif

#define I2C_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

/** @violates @ref I2c_h_REF_4  This is incorrectly reported by the PCLint tool. */
extern VAR(sint8,I2C_VAR) I2c_as8ChannelHardwareMap[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_NO_INIT_8
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"


#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/** @violates @ref I2c_h_REF_4  This is incorrectly reported by the PCLint tool. */
extern P2CONST( I2c_DemConfigType, I2C_VAR, I2C_APPL_CONST) I2c_pDemCfg;
#endif

extern P2CONST(I2c_ConfigType,I2C_VAR,I2C_APPL_CONST) I2c_pConfig;

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED

/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

/** @violates @ref I2c_h_REF_4  This is incorrectly reported by the PCLint tool. */
extern volatile VAR(I2c_StatusType,I2C_VAR) I2c_aeChannelStatus[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE

/**
* @violates @ref I2c_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

FUNC(void, I2C_CODE)            I2c_Init(P2CONST(I2c_ConfigType, AUTOMATIC, I2C_APPL_CONST) pConfig);

FUNC(void, I2C_CODE)            I2c_DeInit(void);

FUNC(Std_ReturnType, I2C_CODE)  I2c_SyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr);

FUNC(Std_ReturnType, I2C_CODE)  I2c_AsyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr);

FUNC(I2c_StatusType, I2C_CODE)  I2c_GetStatus(VAR(uint8, AUTOMATIC) u8Channel);

FUNC(Std_ReturnType, I2C_CODE)  I2c_PrepareSlaveBuffer(
                                                        VAR(uint8, AUTOMATIC) u8Channel,
                                                        VAR(uint8, AUTOMATIC) u8NumberOfBytes, 
                                                        P2VAR(I2c_DataType, AUTOMATIC, I2C_APPL_DATA) pDataBuffer
                                                      );

FUNC(Std_ReturnType, I2C_CODE)  I2c_StartListening(VAR(uint8, AUTOMATIC) u8Channel);

#if I2C_VERSION_INFO_API == STD_ON
FUNC (void, I2C_CODE)           I2c_GetVersionInfo (P2VAR (Std_VersionInfoType, AUTOMATIC, I2C_APPL_DATA) pVersionInfo);
#endif  /* #if I2C_VERSION_INFO_API == STD_ON */

#define I2C_STOP_SEC_CODE
/**
* @violates @ref I2c_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref I2c_h_REF_3 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CDD_I2C_H */

/** @} */
