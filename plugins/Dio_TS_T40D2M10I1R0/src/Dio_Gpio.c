/**
*   @file    Dio_Gpio.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio GPIO source file support for DIO driver.
*   @details This file is the GPIO DIO low level driver code.
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
===================================================================================================*/

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
* @section Dio_Gpio_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file,
* Precautions shall be taken in order to prevent the contents of a header file
* being included twice. This violation is not fixed since the inclusion of MemMap.h 
* is as per Autosar requirement MEMMAP003.
*
* @section Dio_Gpio_C_REF_2
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro computes the address of any register by using the hardware offset of the controller. 
* The address calculated as an unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Dio_Gpio_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section Dio_Gpio_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Dio_Gpio_C_REF_5
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include'. MemMap.h is included after each section define in order to set 
* the current memory section as defined by AUTOSAR.
*
* @section Dio_Gpio_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type 
* and an integral type. The cast is used to access memory mapped registers.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dio_Cfg.h"
#include "Dio_Ipw.h"
#include "Dio_Gpio.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED (DIO_USER_MODE_SOFT_LOCKING)
#endif
#include "SilRegMacros.h"
#include "Reg_eSys_Gpio.h"
#include "SchM_Dio.h"

/*=================================================================================================
                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_GPIO_VENDOR_ID_C                    43
/* @violates @ref Dio_Gpio_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash */
#define DIO_GPIO_AR_RELEASE_MAJOR_VERSION_C     4
/* @violates @ref Dio_Gpio_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash */
#define DIO_GPIO_AR_RELEASE_MINOR_VERSION_C     2
/* @violates @ref Dio_Gpio_C_REF_3 MISRA 2004 Required Rule 1.4, Identifier clash */
#define DIO_GPIO_AR_RELEASE_REVISION_VERSION_C  2
#define DIO_GPIO_SW_MAJOR_VERSION_C             1
#define DIO_GPIO_SW_MINOR_VERSION_C             0
#define DIO_GPIO_SW_PATCH_VERSION_C             1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Dio_Cfg.h version check start */
#if ((DIO_GPIO_AR_RELEASE_MAJOR_VERSION_C != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DIO_GPIO_AR_RELEASE_MINOR_VERSION_C != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DIO_GPIO_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AUTOSAR Version Numbers of Dio_Gpio.c and Dio_Cfg.h are different"
#endif

#if ((DIO_GPIO_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION_CFG) || \
     (DIO_GPIO_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION_CFG) ||\
     (DIO_GPIO_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Dio_Gpio.c and Dio_Cfg.h are different"
#endif

#if (DIO_GPIO_VENDOR_ID_C != DIO_VENDOR_ID_CFG)
    #error "VENDOR ID for Dio_Gpio.c and Dio_Cfg.h is different"
#endif
/* Dio_Cfg.h version check end */

/* Dio_Ipw.h version check start */
#if ((DIO_GPIO_AR_RELEASE_MAJOR_VERSION_C != DIO_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (DIO_GPIO_AR_RELEASE_MINOR_VERSION_C != DIO_AR_RELEASE_MINOR_VERSION_IPW) || \
     (DIO_GPIO_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AUTOSAR Version Numbers of Dio_Gpio.c and Dio_Ipw.h are different"
#endif

#if ((DIO_GPIO_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION_IPW) || \
     (DIO_GPIO_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION_IPW) ||\
     (DIO_GPIO_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION_IPW) \
    )
    #error "Software Version Numbers of Dio_Gpio.c and Dio_Ipw.h are different"
#endif

#if (DIO_GPIO_VENDOR_ID_C != DIO_VENDOR_ID_IPW)
    #error "VENDOR ID for Dio_Gpio.c and Dio_Ipw.h is different"
#endif
/* Dio_Ipw.h version check end */

/* Dio_Gpio.h version check start */
#if ((DIO_GPIO_AR_RELEASE_MAJOR_VERSION_C != DIO_GPIO_AR_RELEASE_MAJOR_VERSION) || \
     (DIO_GPIO_AR_RELEASE_MINOR_VERSION_C != DIO_GPIO_AR_RELEASE_MINOR_VERSION) || \
     (DIO_GPIO_AR_RELEASE_REVISION_VERSION_C != DIO_GPIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Dio_Gpio.c and Dio_Gpio.h are different"
#endif

#if ((DIO_GPIO_SW_MAJOR_VERSION_C != DIO_GPIO_SW_MAJOR_VERSION) || \
     (DIO_GPIO_SW_MINOR_VERSION_C != DIO_GPIO_SW_MINOR_VERSION) ||\
     (DIO_GPIO_SW_PATCH_VERSION_C != DIO_GPIO_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dio_Gpio.c and Dio_Gpio.h are different"
#endif

#if (DIO_GPIO_VENDOR_ID_C != DIO_GPIO_VENDOR_ID)
    #error "VENDOR ID for Dio_Gpio.c and Dio_Gpio.h is different"
#endif
/* Dio_Gpio.h version check end */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* SilRegMacros.h version check start */
    #if ((DIO_GPIO_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (DIO_GPIO_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of Dio_Gpio.c and SilRegMacros.h are different"
    #endif
    /* SilRegMacros.h version check end */
#endif

/* Reg_eSys_Gpio.h version check start */
#if ((DIO_GPIO_AR_RELEASE_MAJOR_VERSION_C != REGESYS_GPIO_AR_RELEASE_MAJOR_VERSION_REG) || \
     (DIO_GPIO_AR_RELEASE_MINOR_VERSION_C != REGESYS_GPIO_AR_RELEASE_MINOR_VERSION_REG) || \
     (DIO_GPIO_AR_RELEASE_REVISION_VERSION_C != REGESYS_GPIO_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AUTOSAR Version Numbers of Dio_Gpio.c and Reg_eSys_Gpio.h are different"
#endif

#if ((DIO_GPIO_SW_MAJOR_VERSION_C != REGESYS_GPIO_SW_MAJOR_VERSION_REG) || \
     (DIO_GPIO_SW_MINOR_VERSION_C != REGESYS_GPIO_SW_MINOR_VERSION_REG) ||\
     (DIO_GPIO_SW_PATCH_VERSION_C != REGESYS_GPIO_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Dio_Gpio.c and Reg_eSys_Gpio.h are different"
#endif

#if (DIO_GPIO_VENDOR_ID_C != REGESYS_GPIO_VENDOR_ID_REG)
    #error "VENDOR ID for Dio_Gpio.c and Reg_eSys_Gpio.h is different"
#endif
/* Reg_eSys_Gpio.h version check end */

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
/* @violates @ref Dio_Gpio_C_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DIO_PGPDI_OFFSET_U32(Port)        ((uint32)((Port) << 0x1U))
/* @violates @ref Dio_Gpio_C_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DIO_PGPDO_OFFSET_U32(Port)        ((uint32)((Port) << 0x1U))
/* @violates @ref Dio_Gpio_C_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
#define DIO_MPGPDO_OFFSET_U32(Port)       ((uint32)((Port) << 0x2U))
#define DIO_MPGPDO_MASK_SHIFT_U8          ((uint8)16)
#define DIO_MPGPDO_MPPDO_MASK_U32         ((uint32)0x0000FFFFU)
#define GPIO_REVERSE_BITS_SHIFT           ((Dio_PortLevelType)1U)
#define GPIO_REVERSE_BITS_MASK            ((Dio_PortLevelType)0x1U)
#define GPIO_REVERSE_BITS_NUMBER          ((Dio_PortLevelType)((sizeof(Dio_PortLevelType) << 0x3U) - 1U))

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
#define DIO_START_SEC_CODE
/* @violates @ref Dio_Gpio_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Dio_MemMap.h"

#if (STD_ON == DIO_REVERSEPORTBITS)
static FUNC(Dio_PortLevelType, DIO_CODE) Dio_Gpio_ReverseBits
(
    VAR(Dio_PortLevelType, AUTOMATIC) Level
);
#endif /* (STD_ON == DIO_REVERSEPORTBITS) */

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*================================================================================================*/

#if (STD_ON == DIO_REVERSEPORTBITS)
/*================================================================================================*/
/**
* @brief          Reverses bits
*
* @param[in]      Level       Bits to be reversed.
*
* @return         The reversed bits
*
* @pre            This function can be used only if @p DIO_REVERSEPORTBITS is
*                 enabled.
*/

static FUNC(Dio_PortLevelType, DIO_CODE) Dio_Gpio_ReverseBits
(
    VAR(Dio_PortLevelType, AUTOMATIC) Level
)
{
    /* RevLevel will be reversed bits of Level */
    VAR(Dio_PortLevelType, AUTOMATIC) RevLevel = Level;
    VAR(Dio_PortLevelType, AUTOMATIC) NumShifts = GPIO_REVERSE_BITS_NUMBER; /* number of shifts needed due to trailing 0s */

    Level = (Dio_PortLevelType)(Level >> GPIO_REVERSE_BITS_SHIFT);
    for (; (Dio_PortLevelType)STD_LOW != Level; Level = (Dio_PortLevelType)(Level >> GPIO_REVERSE_BITS_SHIFT))
    {
        RevLevel = (Dio_PortLevelType)(RevLevel << GPIO_REVERSE_BITS_SHIFT);
        RevLevel = (Dio_PortLevelType)(RevLevel | ((Dio_PortLevelType)(Level & GPIO_REVERSE_BITS_MASK)));
        NumShifts--;
    }
    RevLevel = (Dio_PortLevelType)(((Dio_PortLevelType)RevLevel) << NumShifts); /* Remaining shifts when Level's highest bits are zero */

    return RevLevel;
}
#endif /* (STD_ON == DIO_REVERSEPORTBITS) */

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

/*================================================================================================*/
/**
* @brief          Returns the value of the specified DIO channel.
* @details        This function returns the value of the specified DIO channel.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*/
FUNC (Dio_LevelType, DIO_CODE) Dio_Gpio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) ChannelLevel = (Dio_LevelType)STD_LOW;

    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    ChannelLevel = (Dio_LevelType)(((REG_READ32(GPIO_PDIR_ADDR32(GPIO_PORT_U32(ChannelId))))&PIN_NO_MASK_U32(ChannelId))>>GPIO_CHANNEL_U32(ChannelId));

    return ChannelLevel;
}

/*===============================================================================================*/
/**
* @brief          Sets the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall set the specified level on the
*                 specified channel. If the specified channel is configured
*                 as an input channel, this function shall have no influence
*                 on the physical output and on the result of the next read
*                 service.
*
* @param[in]      ChannelId   Specifies the required channel id.
* @param[in]      Level       Specifies the channel desired level.
*/
FUNC (void, DIO_CODE) Dio_Gpio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC)   ChannelId,
    CONST(Dio_LevelType, AUTOMATIC)     Level
)
{
    if ((Dio_LevelType)STD_HIGH == Level)
    {
        /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(GPIO_PSOR_ADDR32(GPIO_PORT_U32(ChannelId)), ((Dio_PortLevelType)1U<<GPIO_CHANNEL_U32(ChannelId)));
    }
    else if ((Dio_LevelType)STD_LOW == Level)
    {
        /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(GPIO_PCOR_ADDR32(GPIO_PORT_U32(ChannelId)), ((Dio_PortLevelType)1U<<GPIO_CHANNEL_U32(ChannelId)));
    }
    else
    {
        /* Do nothing. Required by MISRA */
    }
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/*===============================================================================================*/
/**
* @brief          Inverts the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall invert the level of the specified
*                 channel. If the specified channel is configured as an
*                 input channel, this function shall have no influence
*                 on the physical output and on the result of the next
*                 read service.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*
* @pre            This function can be used only if @p DIO_FLIP_CHANNEL_API
*                 has been enabled.
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_Gpio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) ChannelLevel = (Dio_LevelType)STD_LOW;

    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(GPIO_PTOR_ADDR32(GPIO_PORT_U32(ChannelId)), (Dio_PortLevelType)STD_HIGH<<GPIO_CHANNEL_U32(ChannelId));
#if (STD_ON == DIO_INOUT_CONFIG_SUPPORTED)

#if defined(DIO_FLIPCHANNEL_DELAY)
    /* Insert user configured number of NOP instructions between write output buffer and read input buffer */
    DIO_FLIPCHANNEL_DELAY;
#endif

    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    ChannelLevel = (Dio_LevelType)(((REG_READ32(GPIO_PDIR_ADDR32(GPIO_PORT_U32(ChannelId))))&PIN_NO_MASK_U32(ChannelId))>> GPIO_CHANNEL_U32(ChannelId));
#else
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    ChannelLevel = (Dio_LevelType)(((REG_READ32(GPIO_PDOR_ADDR32(GPIO_PORT_U32(ChannelId))))&PIN_NO_MASK_U32(ChannelId))>> GPIO_CHANNEL_U32(ChannelId));
#endif /* (STD_ON == DIO_INOUT_CONFIG_SUPPORTED) */
    
   return ChannelLevel;
}
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

/*===============================================================================================*/
/**
* @brief          Returns the level of all channels of specified port.
* @details        This function will return the level of all channels
*                 belonging to the specified port.
*
* @param[in]      PortId      Specifies the required port id.
*
* @return                     Levels of all channels of specified port.
*/
FUNC (Dio_PortLevelType, DIO_CODE) Dio_Gpio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) PortLevel = (Dio_PortLevelType) STD_LOW;

    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    PortLevel = (Dio_PortLevelType)((REG_READ32(GPIO_PDIR_ADDR32(PortId))));
#if (STD_ON == DIO_READZERO_UNDEFINEDPORTS)
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    PortLevel =(Dio_PortLevelType)(PortLevel & Dio_aAvailablePinsForRead[PortId]);
#endif
#if (STD_ON == DIO_REVERSEPORTBITS)
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    PortLevel = (Dio_PortLevelType)(Dio_Gpio_ReverseBits(PortLevel));
#endif

     return PortLevel;
}

/*===============================================================================================*/
/**
* @brief          Sets the value of a port.
* @details        This function will set the specified value on the specified
*                 port.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
*/
FUNC (void, DIO_CODE) Dio_Gpio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
)
{
    VAR( Dio_PortLevelType, AUTOMATIC) CrtLevel = Level;

#if (STD_ON == DIO_REVERSEPORTBITS)
    CrtLevel =  Dio_Gpio_ReverseBits(Level);
#endif

    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(GPIO_PDOR_ADDR32(PortId), CrtLevel);
}

/*===============================================================================================*/
/**
* @brief          This service reads a subset of the adjoining bits of a port.
* @details        This function will read a subset of adjoining bits of a
*                 port (channel group).
*
* @param[in]      pChannelGroupIdPtr Pointer to the channel group.
* @return         The channel group levels.
*/

FUNC (Dio_PortLevelType, DIO_CODE) Dio_Gpio_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupIdPtr
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) PortLevel = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_REVERSEPORTBITS)
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    PortLevel = (Dio_PortLevelType)((REG_READ32(GPIO_PDIR_ADDR32((uint32)(pChannelGroupIdPtr->port))) & (pChannelGroupIdPtr->mask)) << (pChannelGroupIdPtr->u8offset));
    PortLevel = (Dio_PortLevelType)(Dio_Gpio_ReverseBits(PortLevel));
#else
    /* @violates @ref Dio_Gpio_C_REF_2 Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    PortLevel = (Dio_PortLevelType)((REG_READ32(GPIO_PDIR_ADDR32((uint32)(pChannelGroupIdPtr->port))) & (pChannelGroupIdPtr->mask)) >> (pChannelGroupIdPtr->u8offset));
#endif
    return PortLevel;
}

/*===============================================================================================*/
/**
* @brief          Sets a subset of the adjoining bits of a port to the
*                 specified levels.
* @details        This function will set a subset of adjoining bits of a port
*                 (channel group) to the specified levels without changing
*                 the remaining channels of the port and channels that
*                 are configured as input.
*                 This function will do the masking of the channels and will
*                 do the shifting so that the values written by the function
*                 are aligned to the LSB.
*
* @param[in]      pChannelGroupIdPtr Pointer to the channel group.
* @param[in]      Level       Desired levels for the channel group.
*/
FUNC (void, DIO_CODE) Dio_Gpio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) ValueSet;
    VAR(Dio_PortLevelType, AUTOMATIC) ValueClear;

#if (STD_ON == DIO_REVERSEPORTBITS)
    ValueSet = (((Dio_PortLevelType)(Dio_Gpio_ReverseBits(Level)) >> (pChannelGroupIdPtr->u8offset)) & (((Dio_PortLevelType)(pChannelGroupIdPtr->mask) )));
#else
    ValueSet = (((Dio_PortLevelType)(Level) << (pChannelGroupIdPtr->u8offset)) & (((Dio_PortLevelType)(pChannelGroupIdPtr->mask) )));
#endif
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(GPIO_PSOR_ADDR32((pChannelGroupIdPtr->port)), ValueSet);
    ValueClear = (~ValueSet) & pChannelGroupIdPtr->mask;
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(GPIO_PCOR_ADDR32((pChannelGroupIdPtr->port)), ValueClear);
}

#if ((STD_ON == DIO_MASKEDWRITEPORT_API) || defined(__DOXYGEN__))
/*===============================================================================================*/
/**
* @brief          DIO Mask write port using mask.
* @details        Writes a DIO port with masked value.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
* @param[in]      Mask        Specifies the Mask value of the port.
*
* @pre            This function can be used only if @p DIO_MASKEDWRITEPORT_API
*                 has been enabled.
*/

FUNC (void, DIO_CODE) Dio_Gpio_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) Value;

    Value = (( ((uint32)Mask) & ((uint32)(Level))));
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(GPIO_PSOR_ADDR32(PortId), Value);
    Value = (~Level) & Mask;
    /* @violates @ref Dio_Gpio_C_REF_2 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Dio_Gpio_C_REF_6 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(GPIO_PCOR_ADDR32(PortId), Value);
}
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) || defined(__DOXYGEN__) */


#define DIO_STOP_SEC_CODE
/* @violates @ref Dio_Gpio_C_REF_5 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include' */
/* @violates @ref Dio_Gpio_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
