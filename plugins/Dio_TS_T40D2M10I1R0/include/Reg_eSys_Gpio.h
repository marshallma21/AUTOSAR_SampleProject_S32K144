/**
*   @file Reg_eSys_Gpio.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio - GPIO low level driver register defines.
*   @details The description of the registers of the GPIO module.
*
*   @addtogroup GPIO
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

#ifndef REG_ESYS_GPIO_H
#define REG_ESYS_GPIO_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_Gpio_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REGESYS_GPIO_VENDOR_ID_REG                    43
#define REGESYS_GPIO_AR_RELEASE_MAJOR_VERSION_REG     4
#define REGESYS_GPIO_AR_RELEASE_MINOR_VERSION_REG     2
#define REGESYS_GPIO_AR_RELEASE_REVISION_VERSION_REG  2
#define REGESYS_GPIO_SW_MAJOR_VERSION_REG             1
#define REGESYS_GPIO_SW_MINOR_VERSION_REG             0
#define REGESYS_GPIO_SW_PATCH_VERSION_REG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Reg_eSys.h version check start */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REGESYS_GPIO_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REGESYS_GPIO_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Gpio.h and Reg_eSys.h are different"
    #endif
#endif
/* Reg_eSys.h version check end */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define DIO_CHANNEL_MASK_U8                     ((uint8)0x1F)      
#define DIO_PORTID_SHIFT_U8                     ((uint8)5UL)

/*=================================================================================================
*                               DEFINES AND MACROS
==================================================================================================*/
/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PORT_U32(channel)              ((uint32)((uint32)(channel)>>DIO_PORTID_SHIFT_U8))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_CHANNEL_U32(channel)           ((uint32)((uint32)(channel)&DIO_CHANNEL_MASK_U8))                  


/***********************************************************/
/*                         GPIO_PDOR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PDOR_OFFSET_ADDR32          ((uint32)0x0000UL)


/***********************************************************/
/*                         GPIO_PSOR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PSOR_OFFSET_ADDR32          ((uint32)0x0004UL)


/***********************************************************/
/*                         GPIO_PCOR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PCOR_OFFSET_ADDR32         ((uint32)0x0008UL)


/***********************************************************/
/*                         GPIO_PTOR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PTOR_OFFSET_ADDR32          ((uint32)0x000CUL)


/***********************************************************/
/*                         GPIO_PDIR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PDIR_OFFSET_ADDR32          ((uint32)0x0010UL)


/***********************************************************/
/*                         GPIO_PDDR                       */
/*                            OFFSET(0->4)                 */
/***********************************************************/
#define  GPIO_PDDR_OFFSET_ADDR32          ((uint32)0x0014UL)

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PDOR_ADDR32(port)  ((uint32)(GPIO_BASEADDR + GPIO_PDOR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x40)))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PSOR_ADDR32(port)  ((uint32)(GPIO_BASEADDR + GPIO_PSOR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x40) ))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PCOR_ADDR32(port)  ((uint32)(GPIO_BASEADDR + GPIO_PCOR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x40) ))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PTOR_ADDR32(port)  ((uint32)(GPIO_BASEADDR + GPIO_PTOR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x40) ))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PDIR_ADDR32(port)  ((uint32)(GPIO_BASEADDR + GPIO_PDIR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x40) ))

/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define GPIO_PDDR_ADDR32(port)  ((uint32)(GPIO_BASEADDR + GPIO_PDDR_OFFSET_ADDR32 + ((uint32)(port) * (uint32)0x40) ))

/***********************************************************/
/*                         SELECT PIN NO.                  */
/***********************************************************/


/* @violates @ref Reg_eSys_Gpio_H_REF_1 Function-like macro defined */
#define PIN_NO_MASK_U32(channel)           ((uint32)((uint32)1<<GPIO_CHANNEL_U32(channel)))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
/* REG_ESYS_GPIO_H */
#endif
/** @} */
