/**
*   @file    Dio_Gpio.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio GPIO low level GPIO header.
*   @details This file is the GPIO DIO low level driver header.
*
*   @addtogroup DIO_GPIO
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : GPIO
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

#ifndef DIO_GPIO_H
#define DIO_GPIO_H

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
* @section Dio_Gpio_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice. 
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

/*=================================================================================================
*                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_GPIO_VENDOR_ID                     43
#define DIO_GPIO_AR_RELEASE_MAJOR_VERSION      4
#define DIO_GPIO_AR_RELEASE_MINOR_VERSION      2
#define DIO_GPIO_AR_RELEASE_REVISION_VERSION   2
#define DIO_GPIO_SW_MAJOR_VERSION              1
#define DIO_GPIO_SW_MINOR_VERSION              0
#define DIO_GPIO_SW_PATCH_VERSION              1

/*=================================================================================================
                                      FILE VERSION CHECKS
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
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#define DIO_START_SEC_CODE
/* @violates @ref Dio_Gpio_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Dio_MemMap.h"


/**
* @brief   Read the channel level
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_Gpio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

/**
* @brief   Write the level to the channel
*/
FUNC(void, DIO_CODE) Dio_Gpio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,   AUTOMATIC) Level
);

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/**
* @brief   Flip the level of the channel
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_Gpio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

/**
* @brief   Read the port level
*/
FUNC(Dio_PortLevelType, DIO_CODE) Dio_Gpio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

/**
* @brief   Write the port level
*/
FUNC(void, DIO_CODE) Dio_Gpio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

/**
* @brief   Read the level of the channels group
*/
FUNC(Dio_PortLevelType, DIO_CODE) Dio_Gpio_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupIdPtr
);

/**
* @brief   Write the level of the channels group
*/
FUNC(void, DIO_CODE) Dio_Gpio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
);

#if (STD_ON == DIO_MASKEDWRITEPORT_API)
/**
@brief   DIO Mask write port using mask
*/
FUNC(void, DIO_CODE) Dio_Gpio_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
);
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) */

#define DIO_STOP_SEC_CODE
/* @violates @ref Dio_Gpio_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DIO_GPIO_H */
/** @} */
