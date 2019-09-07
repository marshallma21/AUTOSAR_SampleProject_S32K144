/**
*   @file       I2c_Types.h
*   @implements I2c_Types.h_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR I2c - I2C generic types file.
*   @details    Contains generic I2C types and structures.
*
*   @addtogroup I2C_MODULE
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

#ifndef I2C_TYPES_H
#define I2C_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "CDD_I2c_Cfg.h"
#include "I2c_Ipw_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           I2c_Types.h
*/
#define I2C_TYPES_VENDOR_ID                         43
#define I2C_TYPES_MODULE_ID                         255
#define I2C_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define I2C_TYPES_AR_RELEASE_MINOR_VERSION          2
#define I2C_TYPES_AR_RELEASE_REVISION_VERSION       2
#define I2C_TYPES_SW_MAJOR_VERSION                  1
#define I2C_TYPES_SW_MINOR_VERSION                  0
#define I2C_TYPES_SW_PATCH_VERSION                  1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Cfg header file are of the same vendor */
#if (I2C_TYPES_VENDOR_ID != I2C_VENDOR_ID_CFG)
    #error "I2c_Types.h and CDD_I2c_Cfg.h have different vendor ids"
#endif
/* Check if current file and I2c_Cfg header file are of the same Autosar version */
#if ((I2C_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_AR_RELEASE_MAJOR_VERSION_CFG) ||    \
     (I2C_TYPES_AR_RELEASE_MINOR_VERSION != I2C_AR_RELEASE_MINOR_VERSION_CFG) ||    \
     (I2C_TYPES_AR_RELEASE_REVISION_VERSION != I2C_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif
/* Check if current file and I2c_Cfg header file are of the same Software version */
#if ((I2C_TYPES_SW_MAJOR_VERSION != I2C_SW_MAJOR_VERSION_CFG) || \
     (I2C_TYPES_SW_MINOR_VERSION != I2C_SW_MINOR_VERSION_CFG) || \
     (I2C_TYPES_SW_PATCH_VERSION != I2C_SW_PATCH_VERSION_CFG)    \
    )
#error "Software Version Numbers of I2c_Types.h and CDD_I2c_Cfg.h are different"
#endif

/* Check if current file and I2c_Ipw_Types header file are of the same vendor */
#if (I2C_TYPES_VENDOR_ID != I2C_IPW_TYPES_VENDOR_ID)
    #error "I2c_Types.h and I2c_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Ipw_Types header file are of the same Autosar version */
#if ((I2C_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (I2C_TYPES_AR_RELEASE_MINOR_VERSION != I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (I2C_TYPES_AR_RELEASE_REVISION_VERSION != I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_Types.h and I2c_Ipw_Types.h are different"
#endif
/* Check if current file and I2c_Ipw_Types header file are of the same Software version */
#if ((I2C_TYPES_SW_MAJOR_VERSION != I2C_IPW_TYPES_SW_MAJOR_VERSION) || \
     (I2C_TYPES_SW_MINOR_VERSION != I2C_IPW_TYPES_SW_MINOR_VERSION) || \
     (I2C_TYPES_SW_PATCH_VERSION != I2C_IPW_TYPES_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of I2c_Types.h and I2c_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and Std_Types.h are of the same Autosar version */
#if ((I2C_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of I2c_Types.h and Std_Types.h are different"
#endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/**
* @brief          API functions service IDs.
* @details        Service IDs of the I2C API.
*/
typedef enum
{

    I2C_INIT_ID               =   (uint8)0x00U, /**< @brief I2c_Init() ID.*/
    I2C_DEINIT_ID             =   (uint8)0x01U, /**< @brief I2c_DeInit() ID.*/
    I2C_SYNCTRANSMIT_ID       =   (uint8)0x02U, /**< @brief I2c_SyncTransmit() ID.*/
    I2C_ASYNCTRANSMIT_ID      =   (uint8)0x03U, /**< @brief I2c_AsyncTransmit() ID.*/
    I2C_GETSTATUS_ID          =   (uint8)0x04U, /**< @brief I2c_GetStatus() ID.*/
    I2C_PREPARESLAVEBUFFER_ID =   (uint8)0x05U, /**< @brief I2c_PrepareSlaveBuffer() ID.*/
    I2C_STARTLISTENING_ID     =   (uint8)0x06U, /**< @brief I2c_StartListening() ID.*/
    I2C_GETVERSIONINFO_ID     =   (uint8)0x0AU  /**< @brief I2c_GetVersionInfo() ID.*/
} I2c_ApiFunctionIdType;

/**
 * @brief Definition for different state and errors of Operation Status
 *
 *
 * @implements     I2c_StatusType_enumeration
*/
typedef enum
{
    I2C_CH_IDLE          = 0U,  /**< @brief Status Indication I2C channel is idle */
    I2C_CH_SEND,                /**< @brief Status Indication send operation is ongoing */
    I2C_CH_RECEIVE,             /**< @brief Status Indication receiving operation is ongoing */
    I2C_CH_FINISHED,            /**< @brief Status Indication operation is finished */
    I2C_CH_ERROR_PRESENT        /**< @brief Status Indication an error is present */
    
} I2c_StatusType;

/**
  * @brief Definition of the type of a transmission
  */
typedef enum
{
    I2C_ASYNC_MODE = 0x0U,      /**< @brief Asynchronous Mode */
    I2C_SYNC_MODE  = 0x1U       /**< @brief Synchronous Mode */
} I2c_ModeType;

/**
  * @brief Asynchronous method used
  *
  * @implements     I2c_AsynchronousMethodType_enumeration
  */
typedef enum
{
    I2C_INTERRUPT_MODE = 0x0U,      /**< @brief Asynchronous Mechanism using interrupts */
    I2C_DMA_MODE       = 0x1U       /**< @brief Asynchronous Mechanism using DMA */
} I2c_AsynchronousMethodType;

/**
 * @brief Definition of the master/slave mode of an I2C hw unit
  */
typedef enum
{
    /* The channel is an I2C master */
    I2C_MASTER_MODE = 0x0U,
    /* The channel is an I2C slave */
    I2C_SLAVE_MODE  = 0x1U,
    /* The channel is both I2C master and I2C slave */
    I2C_MASTER_SLAVE_MODE  = 0x2U
} I2c_MasterSlaveModeType;
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief          This gives the numeric ID (hardware number) of an I2C hw Unit
 *
 * @implements     I2c_HwUnitType_typedef
 * 
 */
typedef uint8                         I2c_HwUnitType;

/**
 * @brief          Type Address Value of Device and its register value
 *
 * @implements     I2c_AddressType_typedef
 * 
 */
typedef uint16                         I2c_AddressType;

/**
 * @brief          Type Data to be sent or received
 *
 * @implements     I2c_DataType_typedef
 * 
 */
typedef uint8                          I2c_DataType;

/**
 * @brief    Structure that contains I2C Hw configuration.
 * @details  It contains the information specific to one I2C Hw unit
 *
 * @implements  I2c_HwUnitConfigType_struct
 */
typedef struct
{
    /**< @brief Numeric instance value of I2C Hw Unit */
    CONST( I2c_HwUnitType, I2C_CONST)                              I2c_HwUnit;
    
    /**< @brief Master/slave mode configuration of the I2C Hw Unit */
    CONST( I2c_MasterSlaveModeType, I2C_CONST)                     eMasterSlaveConfig;
    
    /**< @brief Asynchronous method */
    CONST( I2c_AsynchronousMethodType, I2C_CONST)                  eAsyncMethod;

    /**< @brief Structure containing the hardware specific configuration for the channel. */
    CONST( I2c_Ipw_HwChannelConfigType, I2C_CONST)             HwChannelConfig;
    
} I2c_HwUnitConfigType;

/**
 * @brief This type contains initialization data.
 * @details This contains initialization data for the I2C driver. It shall contain:
 *         - The number of I2C modules to be configured
 *         - Dem error reporting configuration
 *         - I2C dependent properties for used HW units
 * @implements     I2c_ConfigType_struct
*/
typedef struct
{
    /**< @brief The maximum number of configured I2C Hw unit in the current configuration structure. */
    CONST(I2c_HwUnitType, I2C_CONST) I2c_MaxHwUnit;
    
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /**< @brief DEM error reporting configuration. */
    P2CONST(I2c_DemConfigType, I2C_VAR, I2C_APPL_CONST) I2c_pDemConfig;
#endif

    /**< @brief Pointer to I2c hardware unit configuration */
    CONST(I2c_HwUnitConfigType, I2C_CONST) (*I2c_pHwConfig)[];
} I2c_ConfigType;

/**
 * @brief Definition for Request Buffer. This is the structure which is passed to I2c_SyncTransmit or I2c_AsyncTransmit
 * function. This holds the necessary information required for the communication of I2C Hw with the Slave 
 * device
 *
 * @implements     I2c_RequestType_struct
*/
typedef struct
{
    /**< @brief Slave Device Address */
    VAR( I2c_AddressType, I2C_VAR)                  SlaveAddress;
    
    /**< @brief This is true when the slave address is 10 bits, when false the address is on 7 bits. */
    VAR( boolean, I2C_VAR)                          b10BitsSlaveAddressSize;

    /**< @brief If this is true the data will be sent with high speed enabled (if hardware support exists). */
    VAR( boolean, I2C_VAR)                          bHighSpeedMode;
    
    /**< @brief When this is true, NACK will be ignored during the address cycle. */
    VAR( boolean, I2C_VAR)                          bExpectNack;
    
    /**< @brief Buffer Size : The number of bytes for reading or writing.*/
    VAR( uint8, I2C_VAR)                            u8BufferSize;
    
    /**< @brief Direction of the data. Can be either Send or Receive. */
    VAR( I2c_DataDirectionType, I2C_VAR)            eDataDirection;
    
    /**< @brief Buffer to Store or to transmit Serial data */
    P2VAR( I2c_DataType, I2C_VAR, I2C_APPL_DATA)    pDataBuffer;
    
} I2c_RequestType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif    /*I2C_TYPES_H*/

/** @} */
