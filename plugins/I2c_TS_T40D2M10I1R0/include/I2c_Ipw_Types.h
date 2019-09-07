/**
*   @file    I2c_Ipw_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - I2c driver header file.
*   @details I2c driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar independent.
*            - are platform dependent.
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

#ifndef I2C_IPW_TYPES_H
#define I2C_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I2c_LPI2C_Types.h"
#include "I2c_FlexIO_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define I2C_IPW_TYPES_VENDOR_ID                      43
#define I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION       2
#define I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION    2
#define I2C_IPW_TYPES_SW_MAJOR_VERSION               1
#define I2C_IPW_TYPES_SW_MINOR_VERSION               0
#define I2C_IPW_TYPES_SW_PATCH_VERSION               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_LPI2C_Types header file are of the same vendor */
#if (I2C_IPW_TYPES_VENDOR_ID != I2C_LPI2C_TYPES_VENDOR_ID)
    #error "I2c_LPI2C_Types.h and I2c_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_Ipw_Types header file are of the same Autosar version */
#if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_LPI2C_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != I2C_LPI2C_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != I2C_LPI2C_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_LPI2C_Types.h and I2c_Ipw_Types.h are different"
#endif
/* Check if current file and I2c_Ipw_Types header file are of the same Software version */
#if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != I2C_LPI2C_TYPES_SW_MAJOR_VERSION) || \
     (I2C_IPW_TYPES_SW_MINOR_VERSION != I2C_LPI2C_TYPES_SW_MINOR_VERSION) || \
     (I2C_IPW_TYPES_SW_PATCH_VERSION != I2C_LPI2C_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_LPI2C_Types.h and I2c_Ipw_Types.h are different"
#endif

/* Check if current file and I2c_FlexIO_Types header file are of the same vendor */
#if (I2C_IPW_TYPES_VENDOR_ID != I2C_FLEXIO_TYPES_VENDOR_ID)
    #error "I2c_FlexIO_Types.h and I2c_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and I2c_FlexIO_Types header file are of the same Autosar version */
#if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_FLEXIO_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != I2C_FLEXIO_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != I2C_FLEXIO_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_FlexIO_Types.h and I2c_Ipw_Types.h are different"
#endif
/* Check if current file and I2c_FlexIO_Types header file are of the same Software version */
#if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != I2C_FLEXIO_TYPES_SW_MAJOR_VERSION) || \
     (I2C_IPW_TYPES_SW_MINOR_VERSION != I2C_FLEXIO_TYPES_SW_MINOR_VERSION) || \
     (I2C_IPW_TYPES_SW_PATCH_VERSION != I2C_FLEXIO_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_FlexIO_Types.h and I2c_Ipw_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   The structure contains the hardware channel configuration type.
*/
typedef struct
{
    CONST( I2c_HwChannelType, I2C_CONST)                              I2c_Ipw_eChannelType;
    
    P2CONST( I2c_LPI2C_HwChannelConfigType, I2C_VAR, I2C_APPL_CONST)  I2c_Ipw_LPI2CHwConfig;
    P2CONST( I2c_FlexIO_HwChannelConfigType, I2C_VAR, I2C_APPL_CONST) I2c_Ipw_FlexIOCHwConfig;

} I2c_Ipw_HwChannelConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*I2C_IPW_TYPES_H*/

/** @} */
