/**
*     @file         Crcu_Ipw_Types.h
*     @version      1.0.1
* 
*     @brief        AUTOSAR Crcu IPW layer header file.
*     @details      Crcu driver header file, containing device specific type and macro
*                   definitions that are needed by the Crcu driver
*     
*     @addtogroup   CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : CRCV2
*     Dependencies        : none
*
*     Autosar Version     : 4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef CRCU_IPW_TYPES_H
#define CRCU_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crcu_Crcv2_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_IPW_TYPES_VENDOR_ID                      43
#define CRCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define CRCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION       2
#define CRCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION    2
#define CRCU_IPW_TYPES_SW_MAJOR_VERSION               1
#define CRCU_IPW_TYPES_SW_MINOR_VERSION               0
#define CRCU_IPW_TYPES_SW_PATCH_VERSION               1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Crcu_Ipw_Types.h file and Crcu_Crcv2_Types.h header file are of the same vendor */
#if (CRCU_IPW_TYPES_VENDOR_ID != CRCU_CRCV2_TYPES_VENDOR_ID)
    #error "Crcu_Ipw_Types.h and Crcu_Crcv2_Types.h have different Vendor ids"
#endif
/* Check if Crcu_Ipw_Types.h file and Crcu_Crcv2_Types.h header file are of the same Autosar version */
#if ((CRCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != CRCU_CRCV2_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != CRCU_CRCV2_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != CRCU_CRCV2_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Ipw_Types.h and Crcu_Crcv2_Types.h are different"
#endif
/* Check if Crcu_Ipw_Types.h file and Crcu_Crcv2_Types.h header file are of the same Software version */
#if ((CRCU_IPW_TYPES_SW_MAJOR_VERSION != CRCU_CRCV2_TYPES_SW_MAJOR_VERSION) || \
     (CRCU_IPW_TYPES_SW_MINOR_VERSION != CRCU_CRCV2_TYPES_SW_MINOR_VERSION) || \
     (CRCU_IPW_TYPES_SW_PATCH_VERSION != CRCU_CRCV2_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Ipw_Types.h and Crcu_Crcv2_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief      Defines for the hardware CRC channels.
 * */
#define CRC_0               (0U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief      Crcu_ValueType
 * @details    Type for abstracting the CRC computation values
 * @implements Crcu_ValueType_typedef
 * */
typedef Crcu_Crcv2_ValueType             Crcu_ValueType;

/**
 * @brief      Crcu_ChannelAddressType
 * @details    Type for abstracting the address of the CRC feeding register
 * @implements Crcu_ChannelAddressType_typedef
 * */
typedef Crcu_Crcv2_ChannelAddressType    Crcu_ChannelAddressType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif
/** @} */
