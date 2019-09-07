/**
*     @file       Crcu_Crcv2.c
*     @version    1.0.1
*     
*     @brief      Crcu low level code.
*     @details    This file contains the Crcu driver low level driver code.
*     
*     @addtogroup CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project              : AUTOSAR 4.2 MCAL
*     Platform             : ARM
*     Peripheral           : CRCV2
*     Dependencies         : none
*     
*     Autosar Version      : 4.2.2
*     Autosar Revision     : ASR_REL_4_2_REV_0002
*     Autosar Conf.Variant :
*     SW Version           : 1.0.1
*     Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*     
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
===================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
*
* @section Crcu_Crcv2_c_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_Crcv2_c_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported forexternal identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section Crcu_Crcv2_c_REF_3
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. MemMap.h is included after each section define
*          in order to set the current memory section as defined by AUTOSAR.
*
* @section Crcu_Crcv2_c_REF_4
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type 
*          and an integral type. This macro computes the address of any register by using the hardware offset 
*          of the controller. The address calculated as an unsigned int is passed to a macro for initializing
*          the pointer with that address.
*
* @section Crcu_Crcv2_c_REF_5
*          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
*          arithmetic. This violation is due to the use of pointer arithematic, to access data provided by
*          upper layer, the indexing of the pointer is taken care and hence unintended memory locations
*          will not be accessed.
*
* @section Crcu_Crcv2_c_REF_6
*          Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer. Target platform and used 
*          compilers does not require special alignment for char, short, int, long type variables. This 
*          allows typecasts between pointers to them because no problems with data alignment will arise.
*
* @section Crcu_Crcv2_c_REF_7
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a 
*          function and a type other than an integral type. This macro computes the address of any register by
*          using the hardware offset of the controller. The address calculated as an unsigned int is passed to 
*          a macro for initializing the pointer with that address.
*
* @section Crcu_Crcv2_c_REF_8
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Crcu_Crcv2.h"
#include "Crcu_Reg_eSys_Crcv2.h"

#ifndef USER_MODE_REG_PROT_ENABLED
#define  USER_MODE_REG_PROT_ENABLED     (CRCU_USER_MODE_SOFT_LOCKING)
#endif
#include "SilRegMacros.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRCU_CRCV2_VENDOR_ID_C                          43
/** @violates @ref Crcu_Crcv2_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION_C           4
/** @violates @ref Crcu_Crcv2_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_CRCV2_AR_RELEASE_MINOR_VERSION_C           2
/** @violates @ref Crcu_Crcv2_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_CRCV2_AR_RELEASE_REVISION_VERSION_C        2
#define CRCU_CRCV2_SW_MAJOR_VERSION_C                   1
#define CRCU_CRCV2_SW_MINOR_VERSION_C                   0
#define CRCU_CRCV2_SW_PATCH_VERSION_C                   1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Crcu_Crcv2.h header file are of the same vendor */
#if (CRCU_CRCV2_VENDOR_ID_C != CRCU_CRCV2_VENDOR_ID)
    #error "Crcu_Crcv2.c and Crcu_Crcv2.h have different vendor ids"
#endif
/* Check if source file and Crcu_Crcv2.h header file are of the same Autosar version */
#if ((CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION_C    != CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_CRCV2_AR_RELEASE_MINOR_VERSION_C    != CRCU_CRCV2_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_CRCV2_AR_RELEASE_REVISION_VERSION_C != CRCU_CRCV2_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Crcv2.c and Crcu_Crcv2.h are different"
#endif
/* Check if source file and Crcu_Crcv2.h header file are of the same Software version */
#if ((CRCU_CRCV2_SW_MAJOR_VERSION_C != CRCU_CRCV2_SW_MAJOR_VERSION) || \
     (CRCU_CRCV2_SW_MINOR_VERSION_C != CRCU_CRCV2_SW_MINOR_VERSION) || \
     (CRCU_CRCV2_SW_PATCH_VERSION_C != CRCU_CRCV2_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Crcv2.c and Crcu_Crcv2.h are different"
#endif

/* Check if source file and Crcu_Reg_eSys_Crcv2.h header file are of the same vendor */
#if (CRCU_CRCV2_VENDOR_ID_C != CRCU_REGESYS_CRCV2_VENDOR_ID)
    #error "Crcu_Crcv2.c and Crcu_Reg_eSys_Crcv2.h have different vendor ids"
#endif
/* Check if source file and Crcu_Reg_eSys_Crcv2.h header file are of the same Autosar version */
#if ((CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION_C    != CRCU_REGESYS_CRCV2_AR_RELEASE_MAJOR_VERSION) || \
     (CRCU_CRCV2_AR_RELEASE_MINOR_VERSION_C    != CRCU_REGESYS_CRCV2_AR_RELEASE_MINOR_VERSION) || \
     (CRCU_CRCV2_AR_RELEASE_REVISION_VERSION_C != CRCU_REGESYS_CRCV2_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crcu_Crcv2.c and Crcu_Reg_eSys_Crcv2.h are different"
#endif
/* Check if source file and Crcu_Reg_eSys_Crcv2.h header file are of the same Software version */
#if ((CRCU_CRCV2_SW_MAJOR_VERSION_C != CRCU_REGESYS_CRCV2_SW_MAJOR_VERSION) || \
     (CRCU_CRCV2_SW_MINOR_VERSION_C != CRCU_REGESYS_CRCV2_SW_MINOR_VERSION) || \
     (CRCU_CRCV2_SW_PATCH_VERSION_C != CRCU_REGESYS_CRCV2_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crcu_Crcv2.c and Crcu_Reg_eSys_Crcv2.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SilRegMacros.h header file are of the same Autosar version */
    #if ((CRCU_CRCV2_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (CRCU_CRCV2_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Crcu_Crcv2.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CRCV2_16BIT_RESULT_MASK_U32          ((uint32)(0x0000FFFF))

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CRCU_START_SEC_CONST_32
/** @violates @ref Crcu_Crcv2_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_Crcv2_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/**
* @brief Base address array for Crc hardware units
*/
/** @violates @ref Crcu_Crcv2_c_REF_8 Internal linkage unless external linkage is required. */
CONST(uint32, CRCU_CONST) CRC_BASE_ADDR32[] = 
{
#ifdef CRC_BASEADDR
    CRC_BASEADDR
#endif
};

#define CRCU_STOP_SEC_CONST_32
/** @violates @ref Crcu_Crcv2_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_Crcv2_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CRCU_START_SEC_CODE
/** @violates @ref Crcu_Crcv2_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_Crcv2_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Crcu_Crcv2_SetChannelConfig
* @details      Writes CTRL register with the configuration sent by the upper layer
* 
* @param[in]    channel          - CRC Hw channel
* @param[in]    channelConfigPtr - Pointer to the configuration data
* 
* @return       Crcu_Crcv2_ChannelAddressType - Address to the DATA register
*
*/
FUNC(Crcu_Crcv2_ChannelAddressType, CRCU_CODE) Crcu_Crcv2_SetChannelConfig
(
    VAR    (Crcu_Crcv2_ChannelType,       AUTOMATIC                 ) channel,
    P2CONST(Crcu_Crcv2_ChannelConfigType, AUTOMATIC, CRCU_APPL_CONST) channelConfigPtr
)
{
    /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    VAR(Crcu_Crcv2_ChannelAddressType, AUTOMATIC) crcv2DataRegAddress = (Crcu_Crcv2_ChannelAddressType)CRCV2_DATA_ADDR32(channel);

    /* Write the CRC CTRL register */
    /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    REG_WRITE32(CRCV2_CTRL_ADDR32(channel), channelConfigPtr->crcv2Control);
    
    /* Write the polynom in the GPOLY register */
    if(CRCV2_CTRL_TCRC_WIDTH_16_U32 == (channelConfigPtr->crcv2Control & CRCV2_CTRL_TCRC_MASK_U32))
    {
        /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
        /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
        other than an integral type. */
        REG_WRITE16(CRCV2_GPOLY_ADDR32(channel), (uint16)(channelConfigPtr->crcv2Polynom));
    }
    else
    {
        /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
        /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
        other than an integral type. */
        REG_WRITE32(CRCV2_GPOLY_ADDR32(channel), channelConfigPtr->crcv2Polynom);
    }
    
    return crcv2DataRegAddress;
}

/**
* @brief        Crcu_Crcv2_SetChannelSeed
* @details      Writes data into the CRC DATA register, enabling first the CTRL[WAS] bit
* 
* @param[in]    channel - CRC Hw channel
* @param[in]    seed    - Seed data for CRC value computation
* 
* @return       void
*
*/
FUNC(void, CRCU_CODE) Crcu_Crcv2_SetChannelSeed
(
    VAR(Crcu_Crcv2_ChannelType, AUTOMATIC) channel,
    VAR(Crcu_Crcv2_ValueType,   AUTOMATIC) seed
)
{
    /* Set first the WAS (Write As Seed) bit in CTRL reg */
    /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    REG_BIT_SET32(CRCV2_CTRL_ADDR32(channel), CRCV2_CTRL_WAS_SEED_U32);
    
    /* Always write the seed as 32 bit, because the IP will ignore anyway the MSB 16 bits
    when configured for CRC width of 16 bit */
    /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    REG_WRITE32(CRCV2_DATA_ADDR32(channel), seed);
    
    /* Clear the WAS (Write As Seed) bit in CTRL reg, in order for the next calls of  Crcu_Crcv2_CalculateCrc
    to write the DATA register with data values and not seed values */
    /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    REG_BIT_CLEAR32(CRCV2_CTRL_ADDR32(channel), CRCV2_CTRL_WAS_SEED_U32);
}


/**
* @brief        Crcu_Crcv2_SyncCalculateChannelCrc
* @details      Calculates synchronously the CRC over a given data buffer
* 
* @param[in]    channel    - CRC Hw channel
* @param[in]    u8DataPtr  - Pointer to buffer to perform CRC on
* @param[in]    u32Length  - Length of buffer to perform CRC on
* 
* @return       Crcu_ValueType - CRC value
*
*/
FUNC(Crcu_Crcv2_ValueType, CRCU_CODE) Crcu_Crcv2_SyncCalculateChannelCrc
(
    VAR    (Crcu_Crcv2_ChannelType,  AUTOMATIC                 ) channel,
    P2CONST(uint8,                   AUTOMATIC, CRCU_APPL_CONST) u8DataPtr,
    VAR    (uint32,                  AUTOMATIC                 ) u32Length
)
{
    VAR(uint32, AUTOMATIC) u32LengthRemained = u32Length;
    VAR(uint32, AUTOMATIC) u32CurPosInBuffer = 0U;
   
    /* Take chunks of 4 bytes and write them to DATA register as uint32 until no more chunks are available */
    while(u32LengthRemained >= sizeof(uint32))
    {
        /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
        /* @violates @ref Crcu_Crcv2_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
        /* @violates @ref Crcu_Crcv2_c_REF_6 Cast from pointer to pointer. */ 
        /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
        other than an integral type. */
        REG_WRITE32(CRCV2_DATA_ADDR32(channel), *((const uint32*)(&u8DataPtr[u32CurPosInBuffer])));     
        u32LengthRemained -= sizeof(uint32); 
        u32CurPosInBuffer += sizeof(uint32); 
    }
    /* Take remaining bytes one by one and write them to DATA register until no more bytes are available */
    while(u32LengthRemained >= sizeof(uint8))
    {
        /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
        /* @violates @ref Crcu_Crcv2_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
        /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
        other than an integral type. */
        REG_WRITE8(CRCV2_DATA_ADDR32(channel), u8DataPtr[u32CurPosInBuffer]);     
        u32LengthRemained -= sizeof(uint8); 
        u32CurPosInBuffer += sizeof(uint8); 
    }
    return Crcu_Crcv2_GetChannelCrc(channel);
}

/**
* @brief        Crcu_Crcv2_GetChannelCrc
* @details      Reads CRC signature from the CRC DATA register
* 
* @param[in]    channel - CRC Hw channel
*
* 
* @return       Crcu_Crcv2_ValueType - The result of CRC computation
*
*/
FUNC(Crcu_Crcv2_ValueType, CRCU_CODE) Crcu_Crcv2_GetChannelCrc
(
    VAR(Crcu_Crcv2_ChannelType, AUTOMATIC) channel
)
{
    /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    VAR(Crcu_Crcv2_ValueType,   AUTOMATIC) signature = REG_READ32(CRCV2_DATA_ADDR32(channel));
    VAR(Crcu_Crcv2_ControlType, AUTOMATIC) controlReg;
    
    /* Check if CRC width is set to 16 bit */
     /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
    /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
    other than an integral type. */
    if(CRCV2_CTRL_TCRC_WIDTH_16_U32 == (REG_READ32(CRCV2_CTRL_ADDR32(channel)) & CRCV2_CTRL_TCRC_MASK_U32))
    {
        /* Get the type of swap for when reading the CRC value */
        /* @violates @ref Crcu_Crcv2_c_REF_4 A cast should not be performed between a pointer type and an integral type. */
        /* @violates @ref Crcu_Crcv2_c_REF_7 Conversions shall not be performed between a pointer to a function and a type
        other than an integral type. */
        controlReg = REG_READ32(CRCV2_CTRL_ADDR32(channel)) & CRCV2_CTRL_TOTR_MASK_U32;
        
        /* Check if byte swap is applied */
        if((CRCV2_CTRL_TOTR_BITANDBYTESWAP_U32 == controlReg) || (CRCV2_CTRL_TOTR_BYTESWAP_U32 == controlReg))
        {
            /* Byte swap is applied. We need to deliver the CRC signature from CRC[HU:HL] */
            signature = (uint32)(signature >> 16);
        }
        else
        {
            signature = (uint32)(signature & CRCV2_16BIT_RESULT_MASK_U32);
        }
    }
    return signature;
}



#define CRCU_STOP_SEC_CODE
/** @violates @ref Crcu_Crcv2_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_Crcv2_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
