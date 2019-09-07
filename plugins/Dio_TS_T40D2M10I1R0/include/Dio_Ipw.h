/**
*   @file    Dio_Ipw.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio low level header.
*   @details This file is the DIO driver low level header.
*
*   @addtogroup DIO_IPW
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
==================================================================================================*/

#ifndef DIO_IPW_H
#define DIO_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_IPW_H_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section Dio_IPW_H_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to LLD functions. Function like macro are used to reduce code complexity.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Dio_Gpio.h"
#include "Reg_eSys_Gpio.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID_IPW                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_IPW    4
#define DIO_AR_RELEASE_MINOR_VERSION_IPW    2
/** @violates @ref Dio_IPW_H_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define DIO_AR_RELEASE_REVISION_VERSION_IPW 2
#define DIO_SW_MAJOR_VERSION_IPW            1
#define DIO_SW_MINOR_VERSION_IPW            0
#define DIO_SW_PATCH_VERSION_IPW            1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if Dio_Ipw.h and Dio_Gpio.h are of the same vendor */
#if (DIO_VENDOR_ID_IPW != DIO_GPIO_VENDOR_ID)
    #error "VENDOR ID for Dio_Ipw.h and Dio_Gpio.h is different"
#endif
/* Check if Dio_Ipw.h and Dio_Gpio.h are of the same Autosar version */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_IPW != DIO_GPIO_AR_RELEASE_MAJOR_VERSION) || \
     (DIO_AR_RELEASE_MINOR_VERSION_IPW != DIO_GPIO_AR_RELEASE_MINOR_VERSION) || \
     (DIO_AR_RELEASE_REVISION_VERSION_IPW != DIO_GPIO_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Dio_Ipw.h and Dio_Gpio.h are different"
#endif
/* Check if Dio_Ipw.h and Dio_Gpio.h are of the same software version */
#if ((DIO_SW_MAJOR_VERSION_IPW != DIO_GPIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_IPW != DIO_GPIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_IPW != DIO_GPIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dio_Ipw.h and Dio_Gpio.h are different"
#endif

/* Check if Dio_Ipw.h and Reg_eSys_Gpio.h are of the same vendor */
#if (DIO_VENDOR_ID_IPW != REGESYS_GPIO_VENDOR_ID_REG)
    #error "VENDOR ID for Dio_Ipw.h and Reg_eSys_Gpio.h is different"
#endif
/* Check if Dio_Ipw.h and Reg_eSys_Gpio.h are of the same Autosar version */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_IPW != REGESYS_GPIO_AR_RELEASE_MAJOR_VERSION_REG) || \
     (DIO_AR_RELEASE_MINOR_VERSION_IPW != REGESYS_GPIO_AR_RELEASE_MINOR_VERSION_REG) || \
     (DIO_AR_RELEASE_REVISION_VERSION_IPW != REGESYS_GPIO_AR_RELEASE_REVISION_VERSION_REG) \
    )
     #error "AUTOSAR Version Numbers of Dio_Ipw.h and Reg_eSys_Gpio.h are different"
#endif
/* Check if Dio_Ipw.h and Reg_eSys_Gpio.h are of the same software version */
#if ((DIO_SW_MAJOR_VERSION_IPW != REGESYS_GPIO_SW_MAJOR_VERSION_REG) || \
     (DIO_SW_MINOR_VERSION_IPW != REGESYS_GPIO_SW_MINOR_VERSION_REG) || \
     (DIO_SW_PATCH_VERSION_IPW != REGESYS_GPIO_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Dio_Ipw.h and Reg_eSys_Gpio.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define DIO_CHECK_CHANNEL_VALIDITY(ChannelId)   ((uint32)((Dio_PortLevelType)1<<((ChannelId) & DIO_CHANNEL_MASK_U8)))

/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_ReadChannel(ChannelId)              (Dio_Gpio_ReadChannel(ChannelId))

/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_WriteChannel(ChannelId, ChannelLevel)   (Dio_Gpio_WriteChannel((ChannelId), (ChannelLevel)))

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_FlipChannel(ChannelId)              (Dio_Gpio_FlipChannel(ChannelId))

#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_ReadPort(PortId)                    (Dio_Gpio_ReadPort(PortId))

/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_WritePort(PortId, PortLevel)       (Dio_Gpio_WritePort((PortId), (PortLevel)))

/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_ReadChannelGroup(pChannelGroupIdPtr)    (Dio_Gpio_ReadChannelGroup(pChannelGroupIdPtr))

/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_WriteChannelGroup(pChannelGroupIdPtr, Level)    (Dio_Gpio_WriteChannelGroup((pChannelGroupIdPtr), (Level)))

#if (STD_ON == DIO_MASKEDWRITEPORT_API)
/**
* @brief          Mapping macro between low level layer and high level layer.
*
*/
/**
* @violates @ref Dio_IPW_H_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define Dio_Ipw_MaskedWritePort(PortId, PortLevel, Mask)    (Dio_Gpio_MaskedWritePort((PortId), (PortLevel), (Mask)))
    
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) */


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

#ifdef __cplusplus
}
#endif

#endif /* DIO_IPW_H */

/** @} */
