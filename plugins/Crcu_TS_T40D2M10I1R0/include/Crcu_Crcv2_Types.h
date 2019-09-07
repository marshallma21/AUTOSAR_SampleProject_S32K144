/**
*   @file    Crcu_Crcv2_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Crcu - CRCv2 low level IP driver exported structures.
*   @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
*
*   @addtogroup CRCU_MODULE
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : CRCV2
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef CRCU_CRCV2_TYPES_H
#define CRCU_CRCV2_TYPES_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters.The used compilers use more than 31 chars
* for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/*
* @brief current file vendor, Autosar and API version numbers
*       The integration of incompatible files shall be avoided.
*/
#define CRCU_CRCV2_TYPES_VENDOR_ID                     43
#define CRCU_CRCV2_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define CRCU_CRCV2_TYPES_AR_RELEASE_MINOR_VERSION      2
#define CRCU_CRCV2_TYPES_AR_RELEASE_REVISION_VERSION   2
#define CRCU_CRCV2_TYPES_SW_MAJOR_VERSION              1
#define CRCU_CRCV2_TYPES_SW_MINOR_VERSION              0
#define CRCU_CRCV2_TYPES_SW_PATCH_VERSION              1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
/**
 * @brief       Crcu_Crcv2_ChannelType
 * @details     Type for abstracting the available Crc channels range.
 * */
typedef uint8 Crcu_Crcv2_ChannelType;

/**
 * @brief       Crcu_Crcv2_ValueType
 * @details     Type for abstracting the Crc computation values
 * */
typedef uint32 Crcu_Crcv2_ValueType;

/**
 * @brief       Crcu_Crcv2_ChannelAddressType
 * @details     Type for abstracting the address of the Crc feeding register
 * @implements  Crcu_ChannelAddressType_typedef
 * */
typedef uint32* Crcu_Crcv2_ChannelAddressType;

/**
 * @brief       Type that defines Crc polynom.
 * @details     Provides Crc polynom selection
 * */
typedef uint32 Crcu_Crcv2_PolynomType;

/**
 * @brief       Type that defines control configuration for Crc.
 * @details     Provides Crc control selection
 * */
typedef uint32 Crcu_Crcv2_ControlType;

/**
 * @brief       Structure that defines Crc channel configuration.
 * @details     Provides Crc channel configuration
 * */
typedef struct
{
    VAR(Crcu_Crcv2_PolynomType, AUTOMATIC) crcv2Polynom;
    VAR(Crcu_Crcv2_ControlType, AUTOMATIC) crcv2Control;
} Crcu_Crcv2_ChannelConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/


#ifdef __cplusplus
}
#endif


/* CRCU_CRCV2_TYPES_H */
#endif
/** @} */
