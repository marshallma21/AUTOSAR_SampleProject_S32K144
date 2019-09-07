/**
*   @file    Lin_LPUART.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - LPUART.
*   @details File containing the low level driver of the LPUART IP.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
*   Dependencies         : 
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
*
* @section Lin_LPUART_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_LPUART_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_LPUART_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Lin_LPUART_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, This violation is due to
* the structure of the types used. The application should ensure that the
* SDU pointer is pointing to an array.
*
* @section Lin_LPUART_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_LPUART_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_LPUART_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
*
* @section Lin_LPUART_c_REF_8
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin.h"
#include "Lin_LPUART.h"
#include "StdRegMacros.h"
#include "Reg_eSys_LPUART.h"
#include "SchM_Lin.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_LPUART.c
*/
#define LIN_LPUART_VENDOR_ID_C                      43
/**
* @violates @ref Lin_LPUART_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_LPUART_AR_RELEASE_MAJOR_VERSION_C       4
/**
* @violates @ref Lin_LPUART_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_LPUART_AR_RELEASE_MINOR_VERSION_C       2
/**
* @violates @ref Lin_LPUART_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_LPUART_AR_RELEASE_REVISION_VERSION_C    2
#define LIN_LPUART_SW_MAJOR_VERSION_C               1
#define LIN_LPUART_SW_MINOR_VERSION_C               0
#define LIN_LPUART_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_LPUART_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin_LPUART.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin_LPUART header file are of the same vendor */
#if (LIN_LPUART_VENDOR_ID_C != LIN_LPUART_VENDOR_ID)
    #error "Lin_LPUART.c and Lin_LPUART.h have different vendor ids"
#endif
/* Check if current file and Lin_LPUART header file are of the same vendor */
#if (LIN_LPUART_VENDOR_ID_C != REG_ESYS_LPUART_VENDOR_ID)
    #error "Lin_LPUART.c and Reg_eSys_LPUART.h have different vendor ids"
#endif
/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_LPUART_AR_RELEASE_MAJOR_VERSION_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_LPUART_AR_RELEASE_MINOR_VERSION_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_LPUART_AR_RELEASE_REVISION_VERSION_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_LPUART.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_LPUART_SW_MAJOR_VERSION_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_LPUART_SW_MINOR_VERSION_C != LIN_SW_MINOR_VERSION) || \
     (LIN_LPUART_SW_PATCH_VERSION_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_LPUART.c and Lin.h are different"
#endif

/* Check if current file and Lin_LPUART.h header file are of the same Autosar version */
#if ((LIN_LPUART_AR_RELEASE_MAJOR_VERSION_C    != LIN_LPUART_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_LPUART_AR_RELEASE_MINOR_VERSION_C    != LIN_LPUART_AR_RELEASE_MINOR_VERSION) || \
     (LIN_LPUART_AR_RELEASE_REVISION_VERSION_C != LIN_LPUART_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_LPUART.c and Lin_LPUART.h are different"
#endif
/* Check if current file and Lin_LPUART.h header file are of the same Software version */
#if ((LIN_LPUART_SW_MAJOR_VERSION_C != LIN_LPUART_SW_MAJOR_VERSION) || \
     (LIN_LPUART_SW_MINOR_VERSION_C != LIN_LPUART_SW_MINOR_VERSION) || \
     (LIN_LPUART_SW_PATCH_VERSION_C != LIN_LPUART_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_LPUART.c and Lin_LPUART.h are different"
#endif

/* Check if current file and Reg_eSys_LPUART.h header file are of the same Autosar version */
#if ((LIN_LPUART_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_LPUART_AR_RELEASE_MAJOR_VERSION) || \
      (LIN_LPUART_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_LPUART_AR_RELEASE_MINOR_VERSION) || \
      (LIN_LPUART_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPUART_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_LPUART.c and Reg_eSys_LPUART.h are different"
#endif
/* Check if current file and Reg_eSys_LPUART.h header file are of the same Software version */
#if ((LIN_LPUART_SW_MAJOR_VERSION_C != REG_ESYS_LPUART_SW_MAJOR_VERSION) || \
     (LIN_LPUART_SW_MINOR_VERSION_C != REG_ESYS_LPUART_SW_MINOR_VERSION) || \
     (LIN_LPUART_SW_PATCH_VERSION_C != REG_ESYS_LPUART_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_LPUART.c and Reg_eSys_LPUART.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((LIN_LPUART_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_LPUART_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
      )
      #error "AutoSar Version Numbers of Lin_LPUART.c and StdRegMacros.h are different"
  #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/**
* @brief        Lin_LPUART_LogicalStateType
* @details      Logical state of the transmission for a LPUART channel
*               Used for SendHeader and SendResponse
*/
typedef enum
{
    LPUART_IDLE_U32 = 0x00U,    /**< @brief No transmission ongoing. */
    LPUART_SENDING_BREAK_U32,   /**< @brief Currently sending break. */
    LPUART_SENDING_SYNC_U32,    /**< @brief Currently sending sync byte. */
    LPUART_SENDING_PID_U32,     /**< @brief Currently sending PID. */
    LPUART_SENDING_BYTES_U32,   /**< @brief Currently sending data bytes. */
    LPUART_SENDING_CHECKSUM_U32 /**< @brief Currently sending checksum. */

} Lin_LPUART_LogicalStateType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_LPUART_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 /**
* @brief        Store LPUART data to send or receive
*/
static  volatile VAR(uint8, LIN_VAR) au8LPUART_Buffer[LIN_HW_MAX_MODULES][LPUART_MAX_BUFFER_LENGTH_U8];

/**
* @brief        Point to the next byte to send or receive in LPUART Buffers
*/
static volatile VAR(uint8, LIN_VAR) Lin_Lpuart_au8BufferPtr[LIN_HW_MAX_MODULES];

/**
* @brief        Real sizes of LPUART Buffers
*/
static volatile VAR(uint8, LIN_VAR) Lin_Lpuart_au8BufferLength[LIN_HW_MAX_MODULES];

static volatile VAR(uint8, LIN_VAR) Lin_Lpuart_au8WakeupFlag[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_LPUART_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 /*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define LIN_START_SEC_CONST_32
/**
* @violates @ref Lin_LPUART_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief        LPUART IPs base addresses.
*
* @details      Array containing the base address of all the LPUART IPs.
*
*
* @violates @ref Lin_LPUART_c_REF_5 All declarations and definitions
* of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
*/
CONST(uint32, LIN_CONST) LPUART_au32BaseAddrs[13] =
{
    #ifdef  LPUART0_BASEADDR
        LPUART0_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART1_BASEADDR
        LPUART1_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART2_BASEADDR
        LPUART2_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART3_BASEADDR
        LPUART3_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART4_BASEADDR
        LPUART4_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART5_BASEADDR
        LPUART5_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART6_BASEADDR
        LPUART6_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART7_BASEADDR
        LPUART7_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART8_BASEADDR
        LPUART8_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART9_BASEADDR
        LPUART9_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART10_BASEADDR
        LPUART10_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART11_BASEADDR
        LPUART11_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPUART12_BASEADDR
        LPUART12_BASEADDR
    #else
        ((uint32)0x00000000UL)
    #endif
};

#define LIN_STOP_SEC_CONST_32


/**
* @violates @ref Lin_LPUART_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 /*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_LPUART_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 
static FUNC (void, LIN_CODE) Lin_LPUART_CopyData(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr);
static FUNC (void, LIN_CODE) Lin_LPUART_PIDCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint8, AUTOMATIC) u8FrameID);
static FUNC (uint32, LIN_CODE) Lin_LPUART_ChecksumCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(Lin_FrameCsModelType, AUTOMATIC) checksumModel);
static FUNC (void, LIN_CODE) Lin_LPUART_RxBuffFullInterruptHandler(CONST(uint8, AUTOMATIC) u8LPUART_Channel, VAR(uint8, AUTOMATIC) u8LogicChannel);
static FUNC (void, LIN_CODE) Lin_LPUART_IdleLineDetectInterruptHandler(CONST(uint8, AUTOMATIC) u8LPUART_Channel, VAR(uint8, AUTOMATIC) u8LogicChannel);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Copy the data received from the LPUART data registers to pu8LinSduPtr.
* @details This function shall copy the received data in the provided buffer
*          addressed by the pu8LinSduPtr pointer parameter.
*
* @param[in]   LPUART Channel to be addressed.
* @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LPUART Hardware receive buffer where the current SDU is stored
*
* @return       void.
*
*
* @note         Internal driver function.
*
* @violates @ref Lin_LPUART_c_REF_5 All declarations and definitions
*                of objects or functions at file scope shall have
*                internal linkage unless external linkage is required.
*/
static FUNC (void, LIN_CODE) Lin_LPUART_CopyData(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr)
{
    uint8 u8Index;
    uint8 u8BufferLength;

    u8BufferLength = (uint8)(Lin_Lpuart_au8BufferLength[u8Channel] - (uint8)3U);

    for(u8Index = (uint8)0U; u8Index < u8BufferLength; u8Index++)
    {
        /**
        * @violates @ref Lin_LPUART_c_REF_4 pointer arithmetic other
        *                than array indexing used
        */
        pu8LinSduPtr[u8Index] = au8LPUART_Buffer[u8Channel][LPUART_DATA_OFFSET_U8 + u8Index];
    }
}

/**
* @brief   Calculate Protected Identifier from the Frame ID.
* @details Calculate Protected Identifier from the Frame ID.
*
* @param[in]   u8LPUART_Channel, u8FrameID - Frame ID.
* @param[out]  void.
*
* @return       void.
*
*
* @note         Internal driver function.
*
*/
static FUNC (void, LIN_CODE) Lin_LPUART_PIDCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint8, AUTOMATIC) u8FrameID)
{
    uint32 u32Temp1;
    uint32 u32Temp2;

    u32Temp1 = ((uint32)u8FrameID) & LPUART_FRAME_ID_MASK_U32;
    u32Temp2 = u8FrameID;
    /* Calculate parity bit P1 = !(ID1 ^ ID3 ^ ID4 ^ ID5) */
    u32Temp1 |= ((((u32Temp2 >> 1) ^ \
                   (u32Temp2 >> 3) ^ \
                   (u32Temp2 >> 4) ^ \
                   (u32Temp2 >> 5) \
                  )& ((uint32)1U) \
                 ) ^ ((uint32)1U) \
                ) << (uint32)7U;

    /* Calculate parity bit P0 = (ID0 ^ ID1 ^ ID2 ^ ID4) */
    u32Temp1 |= (((u32Temp2) ^ \
                  (u32Temp2 >> 1U) ^ \
                  (u32Temp2 >> 2U) ^ \
                  (u32Temp2 >> 4U) \
                 ) & ((uint32)1U) \
                ) << (uint32)6U;

    au8LPUART_Buffer[u8Channel][LPUART_PID_BYTE_OFFSET_U8] = (uint8)u32Temp1;
}

/**
* @brief   Calculate LIN Checksum.
* @details Calculate LIN Checksum.
*
* @param[in]   u8LPUART_Channel, checksumModel.
* @param[out]  u32Checksum.
*
* @return       uint32.
*
* @note         Internal driver function.
*
*/
static FUNC (uint32, LIN_CODE) Lin_LPUART_ChecksumCalc(VAR(uint8, AUTOMATIC) u8Channel, VAR(Lin_FrameCsModelType, AUTOMATIC) checksumModel)
{
    uint32 u32Checksum = (uint32)0U;
    uint32 u32Carry = (uint32)0U;
    uint32 u32DataLen = (uint32)0U;
    uint32 u32Index = (uint32)0U;

    u32DataLen = ((uint32)Lin_Lpuart_au8BufferLength[u8Channel]) - ((uint32)3U);
    /* Enhanced Model */
    if(LIN_ENHANCED_CS == checksumModel)
    {
        u32Checksum = (uint32)au8LPUART_Buffer[u8Channel][LPUART_PID_BYTE_OFFSET_U8];
    }

    for(u32Index = (uint32)0U; u32Index < u32DataLen; u32Index++)
    {
        u32Checksum += (uint32)au8LPUART_Buffer[u8Channel][LPUART_DATA_OFFSET_U8 + u32Index];
        u32Carry = u32Checksum >> (uint32)8U;
        u32Checksum = (u32Checksum & ((uint32)0xFFU)) + u32Carry;
    }

    u32Checksum = (~(u32Checksum)) & ((uint32)0xFFU);
    return u32Checksum;
}

/**
* @brief   Interrupt handler for RX Data Register Full on LPUART.
* @details This function shall manage the RX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @implements Lin_LPUART_RxBuffFullInterruptHandler_Activity
*
* @note         Internal driver function.
*/
static FUNC (void, LIN_CODE) Lin_LPUART_RxBuffFullInterruptHandler(CONST(uint8, AUTOMATIC) u8LPUART_Channel, VAR(uint8, AUTOMATIC) u8LogicChannel)
{
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint32, AUTOMATIC) u32Lin_DataReg;
    VAR(uint8, AUTOMATIC) u8BufferPtr;
    VAR(uint8, AUTOMATIC) u8BufferLength;
    VAR(uint8, AUTOMATIC) au8Lin_Command;
    VAR(uint8, AUTOMATIC) u8LogicalChannel = (uint8)u8LogicChannel;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_12();
    {
        /* Disable Receiver Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32 );
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_12();

    /* Read the data register */
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    u32Lin_DataReg = REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));

    u8BufferPtr = Lin_Lpuart_au8BufferPtr[u8LogicalChannel];
    u8BufferLength = Lin_Lpuart_au8BufferLength[u8LogicalChannel];

    /* Code Flow Error */
    if(u8BufferPtr >= u8BufferLength)
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_13();
        {
            /* Disable Receiver Interrupt */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32 );
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_13();
    }
    /* The next byte has been received */
    else
    {
        switch(u8BufferPtr)
        {
            case LPUART_SYNCH_BYTE_OFFSET_U8:
            /* case LPUART_PID_BYTE_OFFSET_U8: */
                if((u32Lin_DataReg & LPUART_DATA_8BITS_MASK_U32) != au8LPUART_Buffer[u8LogicalChannel][u8BufferPtr])
                {
                    /* Bit error detected */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                }
                else
                {
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_14();
                    {
                        /* Enable Transmit Interrupt */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32 );
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_14();
                }
                break;
            default:
                /* Get Lin Frame Command */
                au8Lin_Command = Lin_au8TransmitHeaderCommand[u8LogicalChannel];
                /* Get the last transmitted byte */
                u8Temp1 = au8LPUART_Buffer[u8LogicalChannel][u8BufferPtr];

                switch(au8Lin_Command)
                {
                    case LIN_TX_MASTER_RES_COMMAND:
                        /* Verify received data */
                        if((u32Lin_DataReg & LPUART_DATA_8BITS_MASK_U32) != u8Temp1)
                        {
                            /* Bit error detected */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                        }
                        else
                        {
                            /* The last byte has been received */
                            if(u8BufferPtr == (u8BufferLength - (uint8)1))
                            {
                                Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_TX_COMPLETE_STATE;
                            }
                            else
                            {
                                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_15();
                                {
                                    /* Enable Transmit Interrupt */
                                    /**
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                                    */
                                    REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32 );
                                }
                                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_15();
                            }
                        }
                        break;
                    case LIN_TX_SLEEP_COMMAND:
                        /* Verify received data */
                        if((u32Lin_DataReg & LPUART_DATA_8BITS_MASK_U32) != u8Temp1)
                        {
                            /* Bit error detected */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                        }
                        else
                        {
                            /* The last byte has been received */
                            if(u8BufferPtr == (u8BufferLength - (uint8)1))
                            {
                                /* Sleep Command */
                                /* Set Channel State to Sleep */
                                 Lin_au8LinChStatus[u8LogicalChannel] = LIN_CH_SLEEP_PENDING;
                                 /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
                                Lin_au8TransmitHeaderCommand[u8LogicalChannel] = LIN_TX_NO_COMMAND;

                                /* Reset buffer length */
                                Lin_Lpuart_au8BufferLength[u8LogicalChannel] = (uint8)0U;

                                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_16();
                                {
                                    /* Enable wake up detection */
                                    /* Clear RX Pin Active Edge Interrupt Flag */
                                    /**
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                                    */
                                    REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_RXEDGIF_MASK_U32));
                                    /* Enable RX Input Active Edge Interrupt Enable */
                                    /**
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                                    */
                                    REG_BIT_SET32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_RXEDGIE_MASK_U32);

                                    /* Disable Receiver Interrupt */
                                    /**
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                                    */
                                    REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32);
                                }
                                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_16();
                            }
                            else
                            {
                                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_17();
                                {
                                    /* Enable Transmit Interrupt */
                                    /**
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                                    *
                                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                                    */
                                    REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32);
                                }
                                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_17();
                            }
                        }
                        break;
                    case LIN_TX_SLAVE_RES_COMMAND:
                        /* Store received data */
                        au8LPUART_Buffer[u8LogicalChannel][u8BufferPtr] = (uint8)(u32Lin_DataReg & LPUART_DATA_8BITS_MASK_U32);

                        /* The last byte has been received */
                        if(u8BufferPtr == (u8BufferLength - (uint8)1U))
                        {
                            /* Update LIN channel frame operation status to LIN_RX_COMPLETE_STATE */
                            Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_RX_COMPLETE_STATE;

                            /* Checksum Error */
                            if(Lin_LPUART_ChecksumCalc((uint8)u8LogicalChannel, LIN_ENHANCED_CS) != (uint32)(u32Lin_DataReg & LPUART_DATA_8BITS_MASK_U32))
                            {
                                /* Set LIN channel frame error status to LIN_CHECKSUM_ERROR */
                                Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_CHECKSUM_ERROR;
                            }
                        }
                        else
                        {
                            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_18();
                            {
                                /* Enable Receiver Interrupt */
                                /**
                                *
                                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                                *
                                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                                */
                                REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32 );
                            }
                            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_18();
                        }
                        /* Noise Error has occurred ? */
                        /** @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer */
                        if(LPUART_DATA_NOISY_MASK_U32== (u32Lin_DataReg & LPUART_DATA_NOISY_MASK_U32))
                        {
                            /* Set LIN channel frame error status to LIN_NOISE_ERROR */
                            Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_NOISE_ERROR;
                        }
                        break;
                    default:
                        /* Code Flow Error */
                        break;
                }
                break;
        }
        /* Increase Buffer Pointer */
        Lin_Lpuart_au8BufferPtr[u8LogicalChannel]++;
    }
}

/**
* @brief   Interrupt handler for Idle line detected on LPUART.
* @details This function shall manage the RX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @implements Lin_LPUART_IdleLineDetectInterruptHandler_Activity
*
* @note         Internal driver function.
*/
static FUNC (void, LIN_CODE) Lin_LPUART_IdleLineDetectInterruptHandler(CONST(uint8, AUTOMATIC) u8LPUART_Channel, VAR(uint8, AUTOMATIC) u8LogicChannel)
{
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint8, AUTOMATIC) u8LogicalChannel = (uint8)u8LogicChannel;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_20();
    {
        /* Clear Idle Line Interrupt Flag */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_IDLE_MASK_U32));

        /* Disable Idle Line Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_ILIE_MASK_U32 );
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_20();

    u8Temp1 = Lin_au8LinChStatus[u8LogicalChannel];
    /* Check whether the Lin channel status is in LIN_CH_SLEEP_STATE */
    if (LIN_CH_SLEEP_STATE == u8Temp1)
    {
        /* Discard data from Rx buffer */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));

        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_21();
        {
            /* Clear Error Flags */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_ERR_FLAGS_MASK_U32));
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_21();

        /* Check whether wake up detection is enabled */
         if ((uint8)STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelWakeupSupport)
        {
            /* Indicates a valid timer wakeup event to ECU State Manager */
             EcuM_CheckWakeup(Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
             /* Update Wakeup Flag */
            Lin_Lpuart_au8WakeupFlag[u8LogicalChannel] = (uint8)FALSE;
            /* Set Channel state Operational */
            Lin_au8LinChStatus[u8LogicalChannel] = LIN_CH_OPERATIONAL;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_CH_READY_STATE;
        }
        else
        {
            /* Update Wakeup Flag */
            Lin_Lpuart_au8WakeupFlag[u8LogicalChannel] = (uint8)TRUE;
        }
    }
    else
    {
        /* Do nothing */
    }
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_LPUART_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn;

    u8TempReturn = Lin_Lpuart_au8WakeupFlag[u8Channel];

    if((uint8)TRUE == u8TempReturn)
    {
        /* Reset Wakeup Flag */
        Lin_Lpuart_au8WakeupFlag[u8Channel] = (uint8)FALSE;
    }
    else
    {
        /* Do nothing */
    }

    return u8TempReturn;
}

/**
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
*
* @return            void.
*
*/
FUNC(void, LIN_CODE) Lin_LPUART_InitChannel(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8BreakLength;
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;
    VAR(uint32, AUTOMATIC) u32Counter = (uint32)0U;

    /* Get the hardware Lin channel from logical channel */
     u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    /* Get the Break Length chose for the hardware Lin channel from logical channel */
    u8BreakLength = Lin_pChannelConfigPtr[u8Channel]->u8LinChannelBreakLength;

    /* Reset LPUART registers */
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    REG_BIT_SET32(LPUART_GLOBAL_ADDR32(u8LPUART_Channel), LPUART_GLOBAL_RST_MASK_U32);
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    REG_BIT_CLEAR32(LPUART_GLOBAL_ADDR32(u8LPUART_Channel), LPUART_GLOBAL_RST_MASK_U32);

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00();
    {
        /* Disable LPUART Receiver and Transmitter */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RE_MASK_U32 );
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TE_MASK_U32 );

        /* Break Length Configuration */
        if ( (uint8)13U == u8BreakLength )
        {
            /* Set Break Length = 13 (BAUD.SBNS = 0; CTRL.M = 0; STAT.BRK13 = 1; CTRL.M7 = 0) */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_SBNS_MASK_U32);
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_M_MASK_U32);
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_SET32(LPUART_STAT_ADDR32(u8LPUART_Channel), LPUART_STAT_BRK13_MASK_U32);
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_M7_MASK_U32);
        }

        /* Initialize baud rate */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_RMW32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_OSR_MASK_U32, LPUART_BAUD_OSR_U32(LPUART_BAUD_OSR_16_BITS_U32));
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_RMW32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_SBR_MASK_U32, LPUART_BAUD_SBR_U32(Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Lin_BaudRate_RegValue));

        /* Configure LSB (bit0) to be the first bit that is transmitted following the start bit */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_STAT_ADDR32(u8LPUART_Channel), LPUART_STAT_MSBF_MASK_U32 );

        /* No hardware parity generation or checking */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_PE_MASK_U32 );

        /* LPUART Interrupts' Initialization - Disable all interrupts */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_INT_FLAGS_MASK_U32));
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_IE_FLAGS_MASK_U32);

        /* Clear Wakeup Flags */
        Lin_Lpuart_au8WakeupFlag[u8Channel] = (uint8)FALSE;

        /* Enable LPUART Transmitter */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TE_MASK_U32 );
        /* Enable LPUART Receiver */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RE_MASK_U32 );

        /* After LPUART Transmitter is enabled, a preamble character that is one full character frame of the idle state will be queued automatically */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
        {
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            if( (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32) == ( REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32)))
            {
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();
}

/**
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the Lin_LPUART_SendReponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_LPUART_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr)
{
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;
    VAR(uint32, AUTOMATIC) volatile u32Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
     u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_01();
    {
        /** Stop any ongoing transmission */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32);
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32);
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32);

        MCAL_FAULT_INJECTION_POINT(LPUART_FIP_1_T_TIME_OUT_1);

        /* wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1))
        {
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            if( (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32) == ( REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32)))
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_01();

    /* Discard LPUART Rx Buffer */
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));

    if((uint8)E_OK == u8TmpReturn)
    {
        /* Reset error status global flag */
        Lin_au8LinChFrameErrorStatus[u8Channel] = LIN_NO_ERROR;

        /* Set header status to TRUE if master wants to send the response frame */
        if (LIN_MASTER_RESPONSE == pPduInfoPtr->Drc)
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_MASTER_RES_COMMAND;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_READY_STATE;
        }
        else
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLAVE_RES_COMMAND;
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
        }

        /* The buffer contains [sync byte, pid, data, checksum] */
        Lin_Lpuart_au8BufferLength[u8Channel] = ((uint8)3U) + pPduInfoPtr->Dl;

        /* Write in the transmission buffer the synchronization byte and the PID */
        au8LPUART_Buffer[u8Channel][LPUART_SYNCH_BYTE_OFFSET_U8] = LPUART_SYNC_BYTE_U8;
        Lin_LPUART_PIDCalc(u8Channel, pPduInfoPtr->Pid);

        /* Set Data Direction */
        if (LIN_MASTER_RESPONSE == pPduInfoPtr->Drc)
        {
            /* Do not transmit header here because it's a master->slave frame
            the header will be transmitted together with the response when calling SendResponse function */
        }
        else
        {
            /* Transmit Header */
            /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
            Lin_Lpuart_au8BufferPtr[u8Channel] = LPUART_SYNCH_BYTE_OFFSET_U8;

            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_02();
            {
                /* Disable Error Interrupts */
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                REG_RMW32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_ONFIE_MASK_U32, LPUART_CTRL_ONFIE_DISABLE_U32);

                /* Discard LPUART Rx Buffer */
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));
                /* Send break by toggling DATA_FRETSC bit */
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                REG_BIT_SET32(LPUART_DATA_ADDR32(u8LPUART_Channel), LPUART_DATA_FRETSC_MASK_U32);
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                REG_BIT_CLEAR32(LPUART_DATA_ADDR32(u8LPUART_Channel), LPUART_DATA_FRETSC_MASK_U32);

                /* Enable Transmission Complete Interrupt */
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );
            }
            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_02();
        }
    }
    return u8TmpReturn;
}

/**
* @brief   Sends the response part of the LIN frame.
* @details Initiates the transmission of the data
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_LPUART_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr)
{
    VAR(uint8, AUTOMATIC) u8Loop = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;

    /* Get the hardware Lin channel from logical channel */
     u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    /* Tx Buffer Preparation */
    /* Data */
    for(u8Loop = (uint8)0U; u8Loop < pPduInfoPtr->Dl; u8Loop++)
    {
        /**
        * @violates @ref Lin_LPUART_c_REF_4 pointer arithmetic other
        *                than array indexing used
        */
        au8LPUART_Buffer[u8Channel][LPUART_DATA_OFFSET_U8 + u8Loop] = pPduInfoPtr->SduPtr[u8Loop];
    }
    /* Checksum */
    au8LPUART_Buffer[u8Channel][Lin_Lpuart_au8BufferLength[u8Channel] - ((uint8)1U)] = (uint8)Lin_LPUART_ChecksumCalc(u8Channel, LIN_ENHANCED_CS);

    /* Transmit Header */
    /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
    Lin_Lpuart_au8BufferPtr[u8Channel] = LPUART_SYNCH_BYTE_OFFSET_U8;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_03();
    {
        /* Disable Error Interrupts */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_RMW32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_ONFIE_MASK_U32, LPUART_CTRL_ONFIE_DISABLE_U32);

        /* Discard LPUART Rx Buffer */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));
        /* Send break by toggling DATA_FRETSC bit */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_SET32(LPUART_DATA_ADDR32(u8LPUART_Channel), LPUART_DATA_FRETSC_MASK_U32);
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_DATA_ADDR32(u8LPUART_Channel), LPUART_DATA_FRETSC_MASK_U32);

        /* Enable Transmission Complete Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_03();
}

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time-out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_LPUART_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;
    VAR(uint32, AUTOMATIC) volatile u32Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
     u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_04();
    {
        /** Stop any ongoing transmission */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32);
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32);

        MCAL_FAULT_INJECTION_POINT(LPUART_FIP_2_T_TIME_OUT_2);

        /* wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + ((uint32)1U)))
        {
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            if( (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32) == ( REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32)))
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_04();

    /* Discard LPUART Rx Buffer */
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));

    if((uint8)E_OK == u8TmpReturn)
    {
        Lin_Lpuart_au8BufferLength[u8Channel] = LPUART_MAX_BUFFER_LENGTH_U8;

        /* Prepare header */
        /* Synch byte */
        au8LPUART_Buffer[u8Channel][LPUART_SYNCH_BYTE_OFFSET_U8] = LPUART_SYNC_BYTE_U8;

        /* Protected Identifier */
        Lin_LPUART_PIDCalc(u8Channel, LPUART_MASTER_REQUEST_DIAGNOSTIC_ID_U8);

        /* The Go to sleep command is (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF) */
        au8LPUART_Buffer[u8Channel][(uint8)2U] = LPUART_DATA_0_U8;
        au8LPUART_Buffer[u8Channel][(uint8)3U] = LPUART_DATA_255_U8;
        au8LPUART_Buffer[u8Channel][(uint8)4U] = LPUART_DATA_255_U8;
        au8LPUART_Buffer[u8Channel][(uint8)5U] = LPUART_DATA_255_U8;
        au8LPUART_Buffer[u8Channel][(uint8)6U] = LPUART_DATA_255_U8;
        au8LPUART_Buffer[u8Channel][(uint8)7U] = LPUART_DATA_255_U8;
        au8LPUART_Buffer[u8Channel][(uint8)8U] = LPUART_DATA_255_U8;
        au8LPUART_Buffer[u8Channel][(uint8)9U] = LPUART_DATA_255_U8;

        /* The Classic checksum for the go to sleep frame is 0x00  */
        au8LPUART_Buffer[u8Channel][Lin_Lpuart_au8BufferLength[u8Channel] - ((uint8)1U)] = (uint8)Lin_LPUART_ChecksumCalc(u8Channel, LIN_CLASSIC_CS);

        /* Set next byte to send the sync byte. This will be used in the transmission complete interrupt */
        Lin_Lpuart_au8BufferPtr[u8Channel] = LPUART_SYNCH_BYTE_OFFSET_U8;

        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_05();
        {
            /* Disable Error Interrupts */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_RMW32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_ONFIE_MASK_U32, LPUART_CTRL_ONFIE_DISABLE_U32);

            /* Discard LPUART Rx Buffer */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));
            /* Send break by toggling DATA_FRETSC bit */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_SET32(LPUART_DATA_ADDR32(u8LPUART_Channel), LPUART_DATA_FRETSC_MASK_U32);
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_DATA_ADDR32(u8LPUART_Channel), LPUART_DATA_FRETSC_MASK_U32);

            /* Set header command type is sleep*/
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLEEP_COMMAND;

            /* Enable Transmission Complete Interrupt */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_05();
    }
    return u8TmpReturn;
}

/**
* @brief   Same function as Lin_LLD_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time-out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_LPUART_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;
    VAR(uint32, AUTOMATIC) volatile u32Counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
     u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_06();
    {
        /** Stop any ongoing transmission */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32);
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32);

        MCAL_FAULT_INJECTION_POINT(LPUART_FIP_3_T_TIME_OUT_3);

        /* wait till Cancellation of current frame */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + ((uint32)1U)))
        {
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            if( (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32) == ( REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32)))
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            else
            {
                u32Counter++;
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_06();

    /* Discard LPUART Rx Buffer */
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));

    /* Sleep Command */
    /* Set Channel State to Sleep */
    Lin_au8LinChStatus[u8Channel] = LIN_CH_SLEEP_STATE;
    /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
    Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_NO_COMMAND;

    /* Reset buffer length */
    Lin_Lpuart_au8BufferLength[u8Channel] = (uint8)0U;

    if((uint8)E_OK == u8TmpReturn)
    {
        /* Enter Sleep mode */
        /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
        Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_NO_COMMAND;

        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_07();
        {
            /* Enable wake up detection */
            /* Clear RX Pin Active Edge Interrupt Flag */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_RXEDGIF_MASK_U32));
            /* Enable RX Input Active Edge Interrupt Enable */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_SET32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_RXEDGIE_MASK_U32);

            /* Disable Receiver Interrupt */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32 );
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_07();
    }

    return u8TmpReturn;
}

/**
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_LPUART_WakeUp(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint32, AUTOMATIC) u32Counter = (uint32)0U;
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;
    VAR(uint8, AUTOMATIC) u8WakeupByte;

    /* Get the hardware Lin channel from logical channel */
     u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    u8WakeupByte = (uint8)(LPUART_MIN_WAKEUP_PULSE_LENGTH_U32/LPUART_BIT_LENGTH32(Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Baudrate));
    u8WakeupByte = (uint8)(~((uint8)((uint8)((uint32)1U << u8WakeupByte) - (uint8)1U)));

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_08();
    {
        /* Disable Transmit Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32 );
        /* Disable Transmission Complete Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );

        /* wait till LPUART transmitter is available */
        while(u32Counter <= (LIN_TIMEOUT_LOOPS + (uint32)1U))
        {
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            if( (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32) == ( REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (LPUART_STAT_TDRE_MASK_U32 | LPUART_STAT_TC_MASK_U32)))
            {
                break;
            }
            else
            {
                u32Counter++;
            }
        }

        /* Disable wake up detection */
        /* Clear RX Pin Active Edge Interrupt Flag */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_RXEDGIF_MASK_U32));
        /* Disable RX Input Active Edge Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_RXEDGIE_MASK_U32);

        /* Disable Receiver Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32 );
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_08();

    /* Send Wake up request */
    /**
    *
    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
    */
    REG_WRITE32(LPUART_DATA_ADDR32(u8LPUART_Channel), u8WakeupByte);
}

 /**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC(void, LIN_CODE) Lin_LPUART_WakeupInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8LPUART_Channel;

    /* Get the hardware Lin channel from logical channel */
    u8LPUART_Channel = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_09();
    {
        /* Disable Transmit Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32 );
        /* Disable Transmission Complete Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );
        /* Disable wake up detection */
        /* Clear RX Pin Active Edge Interrupt Flag */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_RXEDGIF_MASK_U32));
        /* Disable RX Input Active Edge Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_RXEDGIE_MASK_U32);
        /* Disable Receiver Interrupt */
        /**
        *
        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
        */
        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32 );
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_09();
}
 
/**
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error raised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 * @retval LIN_CH_SLEEP     Channel is in sleep mode.
 *
 *
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_LPUART_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr)
{
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint8, AUTOMATIC) u8Temp2;
    VAR(uint8, AUTOMATIC) u8TransmitHeaderCommand;
    VAR(uint8, AUTOMATIC) u8ChannelFrameError;
    VAR(uint8, AUTOMATIC) u8ChannelFrameStatus;
    VAR(Lin_StatusType,AUTOMATIC) u8TempReturn = LIN_NOT_OK;

    u8Temp1 = Lin_Lpuart_au8BufferPtr[u8Channel];
    u8Temp2 = Lin_Lpuart_au8BufferLength[u8Channel];
    u8TransmitHeaderCommand = Lin_au8TransmitHeaderCommand[u8Channel];

    /* Frame transmission */
    if(((uint8)0U) != u8Temp2)
    {
        u8ChannelFrameError = Lin_au8LinChFrameErrorStatus[u8Channel];
        /* Header transmission */
        if((LPUART_PID_BYTE_OFFSET_U8 + ((uint8)1U)) >= u8Temp1)
        {
            switch(u8ChannelFrameError)
            {
                /* No error has occurred */
                case LIN_NO_ERROR:
                    u8TempReturn = LIN_TX_BUSY;
                    break;
                /* Errors occurred */
                case LIN_BIT_ERROR:
                    u8TempReturn = LIN_TX_HEADER_ERROR;
                    break;
                default:
                    u8TempReturn = LIN_NOT_OK;
                    break;
            }
        }
        /* Data transmission */
        else if(u8Temp2 > u8Temp1)
        {
            switch(u8ChannelFrameError)
            {
                /* No error has occurred */
                case LIN_NO_ERROR:
                    if(LIN_TX_SLAVE_RES_COMMAND == u8TransmitHeaderCommand)
                    {
                        u8TempReturn = LIN_RX_BUSY;
                    }
                    else
                    {
                        u8TempReturn = LIN_TX_BUSY;
                    }
                    break;
                /* Errors occurred */
                case LIN_BIT_ERROR:
                    u8TempReturn = LIN_TX_ERROR;
                    break;
                case LIN_NOISE_ERROR:
                    if(LIN_TX_SLAVE_RES_COMMAND == u8TransmitHeaderCommand)
                    {
                        u8TempReturn = LIN_RX_ERROR;
                    }
                    else
                    {
                        u8TempReturn = LIN_TX_ERROR;
                    }
                    break;
                case LIN_BUFFER_OVER_RUN_ERROR:
                case LIN_FRAMING_ERROR:
                    u8TempReturn = LIN_RX_ERROR;
                    break;
                default:
                    u8TempReturn = LIN_NOT_OK;
                    break;
            }
        }
        /* The last byte has been transmitted/received */
        else if(u8Temp2 == u8Temp1)
        {
            u8ChannelFrameStatus = Lin_au8LinChFrameStatus[u8Channel];

            switch(u8ChannelFrameError)
            {
                /* No error has occurred */
                case LIN_NO_ERROR:
                    if(LIN_TX_COMPLETE_STATE == u8ChannelFrameStatus)
                    {
                        u8TempReturn = LIN_TX_OK;
                        Lin_Lpuart_au8BufferLength[u8Channel] = (uint8)0U;
                    }
                    else if(LIN_RX_COMPLETE_STATE == u8ChannelFrameStatus)
                    {
                        /* Copy the data from hardware buffer */
                        Lin_LPUART_CopyData(u8Channel, pu8LinSduPtr);
                        Lin_Lpuart_au8BufferLength[u8Channel] = (uint8)0U;
                        u8TempReturn = LIN_RX_OK;
                    }
                    else
                    {
                        /* Code Flow Error */
                        u8TempReturn = LIN_NOT_OK;
                    }
                    break;
                /* Errors occurred */
                case LIN_NOISE_ERROR:
                    if(LIN_TX_SLAVE_RES_COMMAND == u8TransmitHeaderCommand)
                    {
                        u8TempReturn = LIN_RX_ERROR;
                    }
                    else
                    {
                        u8TempReturn = LIN_TX_ERROR;
                    }
                    break;
                case LIN_CHECKSUM_ERROR:
                case LIN_BUFFER_OVER_RUN_ERROR:
                case LIN_FRAMING_ERROR:
                    u8TempReturn = LIN_RX_ERROR;
                    break;
                default:
                    break;
            }
        }
        else
        {
            /* Code Flow Error */
            u8TempReturn = LIN_NOT_OK;
        }
    }
    /* LPUART is idle */
    else
    {
        u8TempReturn = LIN_OPERATIONAL;
    }
    return u8TempReturn;
}


/**
* @brief   Interrupt handler for TX and RX on LPUART.
* @details This function shall manage all the RX and TX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @implements Lin_LPUART_TxRxInterruptHandler_Activity
*
* @note         Internal driver function.
*/
FUNC(void, LIN_CODE) Lin_LPUART_TxRxInterruptHandler(CONST(uint8, AUTOMATIC) u8LPUART_Channel)
{
    VAR(uint8, AUTOMATIC) u8LogicalChannel = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8BufferPtr;
    VAR(uint8, AUTOMATIC) u8Temp1;
    VAR(uint32, AUTOMATIC) u32Lin_Status;
    VAR(uint32, AUTOMATIC) u32Lin_EnabledInterrupts;
    VAR(uint32, AUTOMATIC) u32Lin_BaudReg;
    VAR(boolean, AUTOMATIC) bLPUART_reset = (boolean)FALSE;

    /* Check if driver is initialized */
    if( NULL_PTR != Lin_pcConfigPtr )
    {
        while(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
             if((sint32)u8LPUART_Channel == Lin_as8ChannelHardwareMap[Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID])
             {
                break;
            }
            else
            {
                u8LogicalChannel++;
            }
        }

        if(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
            /* Get the logical channel index from physical channel */
             u8LogicalChannel = Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID;
 
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            u32Lin_Status = REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & LPUART_STAT_INT_FLAGS_MASK_U32;
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            u32Lin_EnabledInterrupts = REG_READ32(LPUART_CTRL_ADDR32(u8LPUART_Channel)) & LPUART_CTRL_IE_FLAGS_MASK_U32;
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            u32Lin_BaudReg = REG_READ32(LPUART_BAUD_ADDR32(u8LPUART_Channel));

            if (0UL != u32Lin_Status)
            {
                /* Transmit Interrupt - Unused*/
                /* Transmit Data Register Empty Flag is set */
                if((LPUART_STAT_TDRE_MASK_U32 == (u32Lin_Status & LPUART_STAT_TDRE_MASK_U32)) && (LPUART_CTRL_TIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_TIE_MASK_U32)))
                {
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_10();
                    {
                        /* Disable Transmit Interrupt */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32 );

                        /* Enable Receiver Interrupt */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32);
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_10();

                    /* Transmit the next byte */
                    u8BufferPtr = Lin_Lpuart_au8BufferPtr[u8LogicalChannel];
                    /**
                    *
                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                    */
                    REG_WRITE32(LPUART_DATA_ADDR32(u8LPUART_Channel), au8LPUART_Buffer[u8LogicalChannel][u8BufferPtr]);

                }
                /* Transmission Complete Interrupt */
                /* Transmission Complete Flag is set */
                else if ((LPUART_STAT_TC_MASK_U32 == (u32Lin_Status & LPUART_STAT_TC_MASK_U32)) && (LPUART_CTRL_TCIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_TCIE_MASK_U32)))
                {
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_11();
                    {
                        /* Disable Transmission Complete Interrupt */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );

                        /* Enable Error Interrupts */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_ERR_FLAGS_MASK_U32));
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_RMW32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_ONFIE_MASK_U32, LPUART_CTRL_ONFIE_ENABLE_U32);

                        /* Discard LPUART Rx Buffer */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_READ32(LPUART_DATA_ADDR32(u8LPUART_Channel));

                        /* Enable Receiver Interrupt */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_RIE_MASK_U32);
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_11();

                    /* Transmit the next byte */
                    u8BufferPtr = Lin_Lpuart_au8BufferPtr[u8LogicalChannel];
                    /**
                    *
                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                    */
                    REG_WRITE32(LPUART_DATA_ADDR32(u8LPUART_Channel), au8LPUART_Buffer[u8LogicalChannel][u8BufferPtr]);
                }
                /* Receiver Interrupt */
                /* Receive Data Register Full Flag is set */
                /** @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer */
                else if ((LPUART_STAT_RDRF_MASK_U32 == (u32Lin_Status & LPUART_STAT_RDRF_MASK_U32)) && (LPUART_CTRL_RIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_RIE_MASK_U32)))
                {
                    Lin_LPUART_RxBuffFullInterruptHandler(u8LPUART_Channel, u8LogicalChannel);
                }
                /* RX Input Active Edge Interrupt Detected */
                else if ((LPUART_STAT_RXEDGIF_MASK_U32 == (u32Lin_Status & LPUART_STAT_RXEDGIF_MASK_U32)) && \
                         /** @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer */
                         (LPUART_BAUD_RXEDGIE_MASK_U32 == (LPUART_BAUD_RXEDGIE_MASK_U32 & u32Lin_BaudReg)) \
                        )
                {
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_19();
                    {
                        /* Clear RX Input Active Edge Interrupt Flag */
                       /**
                       *
                       * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                       *
                       * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                       */
                       REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_RXEDGIF_MASK_U32));
                        /* Disable RX Input Active Edge Interrupt */
                        /**
                        *
                        * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                        */
                        REG_BIT_CLEAR32(LPUART_BAUD_ADDR32(u8LPUART_Channel), LPUART_BAUD_RXEDGIE_MASK_U32);

                        u8Temp1 = Lin_au8LinChStatus[u8LogicalChannel];
                        /* Check whether the Lin channel status is in LIN_CH_SLEEP_STATE */
                        if (LIN_CH_SLEEP_STATE == u8Temp1)
                        {
                            /* Idle flag is set after one idle character is received */
                            /**
                            *
                            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                            */
                            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_IDLECFG_MASK_U32 );

                            /* Enable Idle Line Interrupt */
                            /**
                            *
                            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                            */
                            REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_IDLE_MASK_U32));
                            /**
                            *
                            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                            */
                            REG_BIT_SET32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_ILIE_MASK_U32 );
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_19();
                }
                /* Idle Line Interrupt Detected */
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                else if ((LPUART_STAT_IDLE_MASK_U32 == (u32Lin_Status & LPUART_STAT_IDLE_MASK_U32)) && (LPUART_CTRL_ILIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_ILIE_MASK_U32)))
                {
                    Lin_LPUART_IdleLineDetectInterruptHandler(u8LPUART_Channel, u8LogicalChannel);
                }
                else
                {
                    /* The LPUART hardware should be reset, Disable Transmission Complete & Transmit Data Register Empty Interrupt */
                    bLPUART_reset = (boolean)TRUE;
                }
            }
            else
            {
                /* The LPUART hardware should be reset, Disable Transmission Complete & Transmit Data Register Empty Interrupt */
                bLPUART_reset = (boolean)TRUE;
            }
        }
        else
        {
            /* The LPUART hardware should be reset, Disable Transmission Complete & Transmit Data Register Empty Interrupt */
            bLPUART_reset = (boolean)TRUE;
        }
    }
    else
    {
        /* The LPUART hardware should be reset, Disable Transmission Complete & Transmit Data Register Empty Interrupt */
        bLPUART_reset = (boolean)TRUE;
    }

    if((boolean)TRUE == bLPUART_reset)
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_22();
        {
            /* Unknown interrupts, reset all flags */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_INT_FLAGS_MASK_U32));

            /* Disable Transmission Complete Interrupt */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TCIE_MASK_U32 );
            /* Disable Transmit Data Register Empty Interrupt */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_BIT_CLEAR32(LPUART_CTRL_ADDR32(u8LPUART_Channel), LPUART_CTRL_TIE_MASK_U32 );
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_22();
    }

    return; /* exit function with no return */
}

/**
* @brief   Interrupt handler for Error on LPUART.
* @details This function shall manage all the Error ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
FUNC (void, LIN_CODE) Lin_LPUART_ErrorInterruptHandler(CONST(uint8, AUTOMATIC) u8LPUART_Channel)
{
    VAR(uint8, AUTOMATIC) u8LogicalChannel = (uint8)0U;
    VAR(uint32, AUTOMATIC) u32Lin_Status;
    VAR(uint32, AUTOMATIC) u32Lin_EnabledInterrupts;

    /* Check if driver is initialized */
    if( NULL_PTR != Lin_pcConfigPtr )
    {
        while(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
             if((sint32)u8LPUART_Channel == Lin_as8ChannelHardwareMap[Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID])
             {
                break;
            }
            else
            {
                u8LogicalChannel++;
            }
        }

        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_23();
        {
            if(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
            {
                /* Get the logical channel index from physical channel */
                 u8LogicalChannel = Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID;
 
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                u32Lin_Status = REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel));
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                u32Lin_EnabledInterrupts = REG_READ32(LPUART_CTRL_ADDR32(u8LPUART_Channel)) & LPUART_CTRL_IE_FLAGS_MASK_U32;

                /* Receiver Overrun Flag */
                if((LPUART_STAT_OR_MASK_U32 == (u32Lin_Status & LPUART_STAT_OR_MASK_U32)) && (LPUART_CTRL_ORIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_ORIE_MASK_U32)))
                {
                    /* Clear Receiver Overrun Flag */
                    /**
                    *
                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                    */
                    REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_OR_MASK_U32));
                    /* Set LIN channel frame error status to LIN_BUFFER_OVER_RUN_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BUFFER_OVER_RUN_ERROR;
                }
                /* Noise Flag */
                else if((LPUART_STAT_NF_MASK_U32 == (u32Lin_Status & LPUART_STAT_NF_MASK_U32)) && (LPUART_CTRL_NEIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_NEIE_MASK_U32)))
                {
                    /* Clear Noise Flag */
                    /**
                    *
                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                    */
                    REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_NF_MASK_U32));
                    /* Set LIN channel frame error status to LIN_NOISE_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_NOISE_ERROR;
                }
                /* Framing Error Flag */
                else if((LPUART_STAT_FE_MASK_U32 == (u32Lin_Status & LPUART_STAT_FE_MASK_U32)) && (LPUART_CTRL_FEIE_MASK_U32 == (u32Lin_EnabledInterrupts & LPUART_CTRL_FEIE_MASK_U32)))
                {
                    /* Clear Framing Error Flag */
                    /**
                    *
                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                    */
                    REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_FE_MASK_U32));
                    /* Set LIN channel frame error status to LIN_FRAMING_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_FRAMING_ERROR;
                }
                /* Unknown Error Interrupts */
                else
                {
                    /* Reset all error interrupt flags */
                    /**
                    *
                    * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                    */
                    REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_ERR_FLAGS_MASK_U32));
                }
            }
            /* Unknown Error Interrupts */
            else
            {
                /* Reset all error interrupt flags */
                /**
                *
                * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
                */
                REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_ERR_FLAGS_MASK_U32));
            }
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_23();
    }
    /* Unknown Error Interrupts */
    else
    {
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_24();
        {
            /* Reset all error interrupt flags */
            /**
            *
            * @violates @ref Lin_LPUART_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LPUART_c_REF_7 cast should not be performed
            */
            REG_WRITE32(LPUART_STAT_ADDR32(u8LPUART_Channel), (uint32)((REG_READ32(LPUART_STAT_ADDR32(u8LPUART_Channel)) & (~LPUART_STAT_W1C_FLAGS_MASK_U32)) | LPUART_STAT_ERR_FLAGS_MASK_U32));
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_24();
    }

    return; /* exit function with no return */
}

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_LPUART_c_REF_1 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LPUART_c_REF_2 Precautions shall be taken in
* order to prevent the contents of a header file being
* included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
