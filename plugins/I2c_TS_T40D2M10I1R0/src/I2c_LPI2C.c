/**
*   @file    I2c_LPI2C.c
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - LPI2C.
*   @details File containing the low level driver of the LPI2C IP.
*
*   @addtogroup I2C
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
* @section I2C_LPI2C_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section I2C_LPI2C_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section I2C_LPI2C_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section I2C_LPI2C_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section I2C_LPI2C_c_REF_5
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section I2C_LPI2C_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithmetic, to access the channel
* parameters, the indexing of the pointer is taken care and hence the unintended memory location
* will not be accessed
*
* @section I2C_LPI2C_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
* The cast is used to access memory mapped registers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c.h"
#include "I2c_LPI2C.h"
#include "Reg_eSys_LPI2C.h"

#include "SchM_I2c.h"

#if (STD_ON == I2C_DMA_USED)
#include "CDD_Mcl.h"
#endif
#include "StdRegMacros.h"

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           I2c_LPI2C.c
*/
#define I2C_LPI2C_VENDOR_ID_C                      43
/**
* @violates @ref I2C_LPI2C_c_REF_5 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C       4
/**
* @violates @ref I2C_LPI2C_c_REF_5 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C       2
/**
* @violates @ref I2C_LPI2C_c_REF_5 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_LPI2C_AR_RELEASE_REVISION_VERSION_C    2
#define I2C_LPI2C_SW_MAJOR_VERSION_C               1
#define I2C_LPI2C_SW_MINOR_VERSION_C               0
#define I2C_LPI2C_SW_PATCH_VERSION_C               1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2C header file are of the same vendor */
#if (I2C_LPI2C_VENDOR_ID_C != I2C_VENDOR_ID)
    #error "I2c_LPI2C.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and I2c_LPI2C header file are of the same vendor */
#if (I2C_LPI2C_VENDOR_ID_C != I2C_LPI2C_VENDOR_ID)
    #error "I2c_LPI2C.c and I2c_LPI2C.h have different vendor ids"
#endif
/* Check if current file and I2c_LPI2C header file are of the same vendor */
#if (I2C_LPI2C_VENDOR_ID_C != REG_ESYS_LPI2C_VENDOR_ID)
    #error "I2c_LPI2C.c and Reg_eSys_LPI2C.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Autosar version */
#if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C    != I2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C    != I2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_LPI2C_AR_RELEASE_REVISION_VERSION_C != I2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_LPI2C.c and CDD_I2c.h are different"
#endif
/* Check if current file and CDD_I2c.h header file are of the same Software version */
#if ((I2C_LPI2C_SW_MAJOR_VERSION_C != I2C_SW_MAJOR_VERSION) || \
     (I2C_LPI2C_SW_MINOR_VERSION_C != I2C_SW_MINOR_VERSION) || \
     (I2C_LPI2C_SW_PATCH_VERSION_C != I2C_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_LPI2C.c and CDD_I2c.h are different"
#endif

/* Check if current file and I2c_LPI2C.h header file are of the same Autosar version */
#if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C    != I2C_LPI2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C    != I2C_LPI2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_LPI2C_AR_RELEASE_REVISION_VERSION_C != I2C_LPI2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_LPI2C.c and I2c_LPI2C.h are different"
#endif
/* Check if current file and I2c_LPI2C.h header file are of the same Software version */
#if ((I2C_LPI2C_SW_MAJOR_VERSION_C != I2C_LPI2C_SW_MAJOR_VERSION) || \
     (I2C_LPI2C_SW_MINOR_VERSION_C != I2C_LPI2C_SW_MINOR_VERSION) || \
     (I2C_LPI2C_SW_PATCH_VERSION_C != I2C_LPI2C_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_LPI2C.c and I2c_LPI2C.h are different"
#endif

/* Check if current file and Reg_eSys_LPI2C.h header file are of the same Autosar version */
#if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_LPI2C_AR_RELEASE_MAJOR_VERSION)  || \
      (I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_LPI2C_AR_RELEASE_MINOR_VERSION) || \
      (I2C_LPI2C_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPI2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_LPI2C.c and Reg_eSys_LPI2C.h are different"
#endif
/* Check if current file and Reg_eSys_LPI2C.h header file are of the same Software version */
#if ((I2C_LPI2C_SW_MAJOR_VERSION_C != REG_ESYS_LPI2C_SW_MAJOR_VERSION) || \
     (I2C_LPI2C_SW_MINOR_VERSION_C != REG_ESYS_LPI2C_SW_MINOR_VERSION) || \
     (I2C_LPI2C_SW_PATCH_VERSION_C != REG_ESYS_LPI2C_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of I2c_LPI2C.c and Reg_eSys_LPI2C.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of I2c_LPI2C.c and StdRegMacros.h are different"
  #endif
#endif


/* Check if current file and DEM header file are of the same version */
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Dem header file are of the same version */
  #if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
       (I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION)    \
      )
      #error "AutoSar Version Numbers of I2c_LPI2C.c and StdRegMacros.h are different"
  #endif
#endif

#if (I2C_DMA_USED == STD_ON)
    #if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_LPI2C_AR_RELEASE_MINOR_VERSION_C  != MCL_AR_RELEASE_MINOR_VERSION)    \
        )
    #error "AutoSar Version Numbers of I2c_LPI2C.c and CDD_Mcl.h are different"
    #endif
#endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define I2C_START_SEC_CONST_32
/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded by other preprocessor directives or comments.
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents of a header file being included twice.
*/
#include "I2c_MemMap.h"


/**
* @brief        LPI2C IPs base addresses.
*
* @details      Array containing the base address of all the LPI2C IPs.
*
*/
static CONST(uint32, I2C_CONST) LPI2C_au32BaseAddrs[] =
{
    #ifdef  LPI2C0_BASEADDR
        LPI2C0_BASEADDR
    #else
        (uint32)(0x0U)
    #endif
    #ifdef  LPI2C1_BASEADDR
        ,LPI2C1_BASEADDR
    #else
        ,(uint32)(0x0U)
    #endif
    #ifdef  LPI2C2_BASEADDR
        ,LPI2C2_BASEADDR
    #else
        ,(uint32)(0x0U)
    #endif
};

#define I2C_STOP_SEC_CONST_32


/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded by other preprocessor directives or comments.
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents of a header file being included twice.
*/
#include "I2c_MemMap.h"

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#if (STD_ON == I2C_DMA_USED)
/**
* @brief    This is the TCD descriptor used to configure the DMA channel for sending or receiving data.
*/
static VAR(Mcl_DmaTcdAttributesType, I2C_VAR) I2c_LPI2C_aDmaCfgDesc[I2C_LPI2C_MAX_MODULES];
#endif

#define I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#define I2C_START_SEC_VAR_NO_INIT_8

/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#if (STD_ON == I2C_DMA_USED)
/**
* @brief    Indexes used by master channels for sending.
*/
static volatile VAR(uint8,I2C_VAR) I2c_LPI2C_au8TxDmaChannel[I2C_LPI2C_MAX_MODULES];
/**
* @brief    Indexes used by master channels for receiving.
*/
static volatile VAR(uint8,I2C_VAR) I2c_LPI2C_au8RxDmaChannel[I2C_LPI2C_MAX_MODULES];
#endif

/**
* @brief    Used to log errors for the channels.
*/
static volatile VAR( uint8, I2C_VAR) I2c_LPI2C_au8ErrorsFound[I2C_LPI2C_MAX_MODULES];

/**
* @brief    Buffer used by master channels to send and receive data.
*/
static volatile P2VAR(uint8, I2C_VAR, I2C_APPL_DATA) I2c_LPI2C_aup8DataBuffer[I2C_LPI2C_MAX_MODULES];

/**
* @brief    Indexes used by master channels for sending and receiving.
*/
static volatile VAR(uint8,I2C_VAR) I2c_LPI2C_au8CurrentIndex[I2C_LPI2C_MAX_MODULES];

/**
* @brief    Total number of bytes used by master channels for sending and receiving.
*/
static VAR(uint8,I2C_VAR) I2c_LPI2C_au8NumberOfBytes[I2C_LPI2C_MAX_MODULES];

/**
* @brief    Buffer used by master channels to send and receive data.
*/
static volatile P2VAR(uint8, I2C_VAR, I2C_APPL_DATA) I2c_LPI2C_aup8SlaveDataBuffer[I2C_LPI2C_MAX_MODULES];

/**
* @brief    Indexes used by slave channels for sending and receiving.
*/
static volatile VAR(uint8,I2C_VAR) I2c_LPI2C_au8SlaveCurrentIndex[I2C_LPI2C_MAX_MODULES];

/**
* @brief    Total number of bytes used by slave channels for sending and receiving.
*/
static VAR(uint8,I2C_VAR) I2c_LPI2C_au8SlaveNumberOfBytes[I2C_LPI2C_MAX_MODULES];

#define I2C_STOP_SEC_VAR_NO_INIT_8

/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#define I2C_START_SEC_VAR_NO_INIT_BOOLEAN

/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/**
* @brief    Used to indicate the Slave is ready for responding to an addressing.
*/
static volatile VAR( boolean, I2C_VAR) I2c_LPI2C_bReadyForAddressing[I2C_LPI2C_MAX_MODULES];

#define I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN

/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded by other preprocessor directives or comments.
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents of a header file being included twice.
* internal linkage unless external linkage is required.
*/
#include "I2c_MemMap.h"

static FUNC (void, I2C_CODE) I2c_LPI2C_MasterAsyncSend(CONST(uint8, AUTOMATIC) u8Channel);
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSyncSend(CONST(uint8, AUTOMATIC) u8Channel);

static FUNC (void, I2C_CODE) I2c_LPI2C_MasterAsyncReceive(CONST(uint8, AUTOMATIC) u8Channel);
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSyncReceive(CONST(uint8, AUTOMATIC) u8Channel);

static FUNC (void, I2C_CODE) I2c_LPI2C_MasterInterruptProcessing(CONST(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus);

static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveEnableTransmitDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel);
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveDisableTransmitDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel);

static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveEnableReceiveDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel);
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveDisableReceiveDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel);
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveInterruptProcessing(CONST(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus);

static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveReceive(CONST(uint8, AUTOMATIC) u8Channel);
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveTransmit(CONST(uint8, AUTOMATIC) u8Channel);

static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSendAddress(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr);

static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSend(
                                                             CONST(uint8, AUTOMATIC) u8Channel,
                                                             P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr,
                                                             CONST(I2c_ModeType, AUTOMATIC) eTransmitMode
                                                           );
                                                           
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterReceive(
                                                                  CONST(uint8, AUTOMATIC) u8Channel, 
                                                                  P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr,
                                                                  CONST(I2c_ModeType, AUTOMATIC) eTransmitMode
                                                              );

static FUNC (void, I2C_CODE) I2c_LPI2C_MasterErrorHandler(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus);
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveErrorHandler(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus);

static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_SendSyncStopCommand(VAR(uint8, AUTOMATIC) u8Channel);

#if (STD_ON == I2C_DMA_USED)
static FUNC (void, I2C_CODE) I2c_LPI2C_DmaReceiveProcessing(VAR(uint8, AUTOMATIC) u8HwChannel);
static FUNC (void, I2C_CODE) I2c_LPI2C_DmaSendProcessing(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == I2C_DMA_USED)

/**
* @brief   Used to process data when sending data using a DMA channel.
* @details This function is called from the DMA transfer processing function when the channel is sending data.
*
* @param[in]   u8HwChannel     LPI2C channel to be addressed.
*
* @return            void
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_DmaSendProcessing(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    /* Time out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout = I2C_TIMEOUT_LOOPS;
    VAR( uint32, AUTOMATIC) u32MasterStatus = (uint32)0x0U;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
    
    if (0x0U == I2c_LPI2C_au8ErrorsFound[u8HwChannel])
    {
        /* If there are some more bytes to be sent */
        if (I2c_LPI2C_au8CurrentIndex[u8HwChannel] < I2c_LPI2C_au8NumberOfBytes[u8HwChannel])
        {
            /* Send the remaining bytes in one iteration */
            I2c_LPI2C_aDmaCfgDesc[u8HwChannel].u32num_bytes = (uint32)I2c_LPI2C_au8NumberOfBytes[u8HwChannel] - I2c_LPI2C_au8CurrentIndex[u8HwChannel];
            I2c_LPI2C_aDmaCfgDesc[u8HwChannel].u32iter  = 1U;
            /* Set the source for the DMA channel as the pointer to the data buffer */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            I2c_LPI2C_aDmaCfgDesc[u8HwChannel].u32saddr = (uint32)I2c_LPI2C_aup8DataBuffer[u8HwChannel] + I2c_LPI2C_au8CurrentIndex[u8HwChannel];
            
            /* Configure the DMA Channel with the new settings */
            Mcl_DmaConfigChannel(I2c_LPI2C_au8TxDmaChannel[u8HwChannel], &I2c_LPI2C_aDmaCfgDesc[u8HwChannel]);
            
            /* Update the index */
            I2c_LPI2C_au8CurrentIndex[u8HwChannel] = I2c_LPI2C_au8NumberOfBytes[u8HwChannel];
            
            /* Enable the notification at the end of the transfer */
            Mcl_DmaEnableNotification(I2c_LPI2C_au8TxDmaChannel[u8HwChannel], MCL_DMA_TRANSFER_COMPLETE);
            /* Re-enable the hardware request */
            Mcl_DmaEnableHwRequest(I2c_LPI2C_au8TxDmaChannel[u8HwChannel]);
        }
        else /* the data transfer is over */
        {
            /* Disable the TX DMA request for the I2C channel */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(LPI2C_MDER_ADDR32(u8HwChannel), LPI2C_MDER_RX_DMA_DISABLE_U32 | LPI2C_MDER_TX_DMA_DISABLE_U32);
            
            /* Wait until the FIFO is ready to receive bytes to send the stop command */
            u32Timeout = I2C_TIMEOUT_LOOPS;
            do
            {
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                u32MasterStatus = REG_READ32(LPI2C_MSR_ADDR32(u8HwChannel)) & LPI2C_MSR_TDF_MASK_U32;
                u32Timeout--;
            }while ((u32Timeout > (uint32)0x0U) && ((uint32)0x0U == u32MasterStatus));
            
            if ( (uint32)0x0U == u32Timeout)
            {
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
                {
                    Dem_ReportErrorStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
                }
#endif
                /* Change the state of the channel to indicate that an error is present */
                I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
            }
            else
            {
                /* Send a stop command */
                u8TmpReturn = I2c_LPI2C_SendSyncStopCommand(u8HwChannel);
                if ((Std_ReturnType)E_OK == u8TmpReturn)
                {
                    /* Change the state of the channel to indicate that the transfer was finished */
                    I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;
                    
#ifdef I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION
                    I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_LPI2C_au8CurrentIndex[u8HwChannel]);
#endif
                }
                else
                {
                    /* Change the state of the channel to indicate that an error is present */
                    I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
                }
            }
        }
    }
    else
    { 
        /* Disable the TX DMA request for the I2C channel */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MDER_ADDR32(u8HwChannel), LPI2C_MDER_RX_DMA_DISABLE_U32 | LPI2C_MDER_TX_DMA_DISABLE_U32);
        /* Change the state of the channel to indicate that an error is present */
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
    }
}

/**
* @brief   Used to process data when receiving data using a DMA channel.
* @details This function is called from the DMA transfer processing function when the channel is receiving data.
*
* @param[in]   u8HwChannel     LPI2C channel to be addressed.
*
* @return            void
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_DmaReceiveProcessing(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8HwChannel];
    
    /* Disable the TX DMA request for the I2C channel */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(LPI2C_MDER_ADDR32(u8HwChannel), LPI2C_MDER_RX_DMA_DISABLE_U32 | LPI2C_MDER_TX_DMA_DISABLE_U32);
    
    /* Send a stop command */
    u8TmpReturn = I2c_LPI2C_SendSyncStopCommand(u8HwChannel);
    
    if ((Std_ReturnType)E_OK == u8TmpReturn)
    {
        /* Change the state of the channel to indicate that the transfer was finished */
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;
        
#ifdef I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION
        I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_LPI2C_au8NumberOfBytes[u8HwChannel]);
#endif
    }
    else
    {
        /* Change the state of the channel to indicate that an error is present */
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
    }
}

#endif

/**
* @brief   Sends a stop command and waits for the flag that the stop command was sent to be set.
* @details This function shall send a stop command and wait for the flag that the stop command was sent to be set.
*          If the flag is not set a DEM error is reported, if DEM errors are enabled
*
* @param[in]   u8Channel     LPI2C channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_SendSyncStopCommand(VAR(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    /* Used to get the master status. */
    VAR( uint32, AUTOMATIC) u32MasterStatus = 0x0U;
    /* Time out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout = I2C_TIMEOUT_LOOPS;
    
    /* Send a stop command */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), LPI2C_GENERATE_STOP_U32);

    u32Timeout = I2C_TIMEOUT_LOOPS;
    do
    {
        /* Check if the STOP was detected and clear the flag */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        u32MasterStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
        u32Timeout--;
    } while (
               (u32Timeout > (uint32)0x0U) &&
               (LPI2C_STOP_DETECTED_U32 != (u32MasterStatus & LPI2C_STOP_DETECTED_U32)) &&
               (LPI2C_BUS_IS_BUSY_U32   == (u32MasterStatus & LPI2C_MSR_BBF_MASK_U32))
            );

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* If the stop flag was not set and a timeout occurred */
    if ( (uint32)0x0U == u32Timeout)
    {
        if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
    }
    else
    {
#endif
        /* If the stop flag was set (i.e. the bus idle timeout MDMR[BUSIDLE] has not occured) */
        if (LPI2C_STOP_DETECTED_U32 == (u32MasterStatus & LPI2C_STOP_DETECTED_U32))
        {
            /* Clear the stop generated flag */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), LPI2C_STOP_DETECTED_U32);
            u8TmpReturn = (Std_ReturnType)E_OK;
        }
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    }
#endif

    return u8TmpReturn;
}

/**
* @brief   Error handler for LPI2C.
* @details This function shall manage all the errors of a LPI2C channel
*
* @param[in]   u8Channel     LPI2C channel to be addressed.
*              u32IsrStatus  The status of the MSR flags.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_MasterErrorHandler(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus)
{
    /* Interrupt enabled/disabled. */
    VAR( uint32, AUTOMATIC) u32IsrEnable = 0x0U;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];
    
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    u32IsrEnable = REG_READ32(LPI2C_MIER_ADDR32(u8Channel)) & LPI2C_MIER_RWBITS_MASK_U32;
    
    /* Check for errors and signal the application that an error occured */
    if (0x0U != (u32IsrStatus  & LPI2C_MSR_ERROR_FLAGS_MASK_U32))
    {
        /* Log the error and it will be checked during the sync transfer or in the DMA transfer */
        I2c_LPI2C_au8ErrorsFound[u8Channel] = 0x1U;

#if (STD_ON == I2C_DMA_USED)
        if (I2C_DMA_MODE == (*I2c_pConfig->I2c_pHwConfig)[s8LogicalChannel].eAsyncMethod)
        {
            if (I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel])
            {
                /* Disable the Hw Request */
                Mcl_DmaDisableHwRequest(I2c_LPI2C_au8RxDmaChannel[u8Channel]);
                /* Disable the TX DMA request for the I2C channel */
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE32(LPI2C_MDER_ADDR32(u8Channel), LPI2C_MDER_RX_DMA_DISABLE_U32 | LPI2C_MDER_TX_DMA_DISABLE_U32);
            }
        }
        else
        {
#endif
            /* If the error appeared during an asynchronous transmission disable the interrupt */
            if (0x0U != u32IsrEnable)
            {
                /* Disable error and stop detected interrupts */
                REG_WRITE32(LPI2C_MIER_ADDR32(u8Channel),
                            (
                             LPI2C_PIN_LOW_TIMEOUT_ISR_DISABLE_U32 |
                             LPI2C_FIFO_ERROR_ISR_DISABLE_U32 |
                             LPI2C_ARBITRATION_LOST_ISR_DISABLE_U32 |
                             LPI2C_UNEXPECTED_NACK_ISR_DISABLE_U32 |
                             LPI2C_STOP_DETECT_ISR_DISABLE_U32 |
                             LPI2C_RECEIVE_DATA_ISR_DISABLE_U32 |
                             LPI2C_TRANSMIT_DATA_ISR_DISABLE_U32
                            )
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                           );
            }
#if (STD_ON == I2C_DMA_USED)
        }
#endif

        /* If the error notification is used signal which error is present */
        /* Check for pin low timeout */
#ifdef I2C_ERROR_NOTIFICATION
        if (LPI2C_PIN_LOW_TIMEOUT_U32 == (u32IsrStatus & LPI2C_PIN_LOW_TIMEOUT_U32))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_PIN_LOW_TIMEOUT);
        }
#endif
        /* Check for FIFO error */
        if (LPI2C_FIFO_ERROR_U32 == (u32IsrStatus & LPI2C_FIFO_ERROR_U32))
        {
            /* Reset transmit FIFO */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_RTF_MASK_U32, LPI2C_MCR_RTF_MASK_U32);
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_RTF_MASK_U32, (uint32)0x0U);
            /* Clear the FIFO flag again after resetting the transmit FIFO */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), LPI2C_FIFO_ERROR_U32);
#ifdef I2C_ERROR_NOTIFICATION
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_FIFO_ERROR);
#endif
        }

#ifdef I2C_ERROR_NOTIFICATION
        /* Check for arbitration lost spurious interrupt */
        if (LPI2C_ARBITRATION_LOST_U32 == (u32IsrStatus & LPI2C_ARBITRATION_LOST_U32))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_ARBITRATION_LOST);
        }
#endif

#ifdef I2C_ERROR_NOTIFICATION
        /* Check for unexpected NACK spurious interrupt */
        if (LPI2C_UNEXPECTED_NACK_U32 == (u32IsrStatus & LPI2C_UNEXPECTED_NACK_U32))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_UNEXPECTED_NACK);
        }
#endif

        /* Change the state of the channel to indicate that an error is present */
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
    }
}


/**
* @brief   Error handler for a LPI2C slave channel.
* @details This function shall manage all the errors of a LPI2C slave channel
*
* @param[in]   u8Channel     LPI2C channel to be addressed.
*              u32IsrStatus  The status of the SSR flags.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveErrorHandler(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus)
{
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];
    
    /* Check for errors and signal the application that an error occured */
    if (0x0U != (u32IsrStatus  & LPI2C_SSR_ERROR_FLAGS_MASK_U32))
    {
        /* Change the state of the channel to indicate that an error is present */
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
        
        /* If the error notification is used signal which error is present */
        /* Check for fifo error */
        if (LPI2C_SLAVE_FIFO_ERROR_DETECTED_U32 == (u32IsrStatus & LPI2C_SSR_FEF_MASK_U32))
        {
            /* Disable TDIE interrupt and reset Transmit FIFO */
            I2c_LPI2C_SlaveDisableTransmitDataInterrupt(u8Channel);
            
            /* Disable RDIE interrupt and reset Receive FIFO */
            I2c_LPI2C_SlaveDisableReceiveDataInterrupt(u8Channel);
            
            /* Reset Receive FIFO */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, LPI2C_SCR_RRF_MASK_U32);

            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, (uint32)0x0U);

#ifdef I2C_ERROR_NOTIFICATION
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_SLAVE_FIFO_ERROR);
#endif
        }

#ifdef I2C_ERROR_NOTIFICATION
        /* Check for bit error */
        if (LPI2C_SLAVE_BIT_ERROR_DETECTED_U32 == (u32IsrStatus & LPI2C_SSR_BEF_MASK_U32))
        {
            I2C_ERROR_NOTIFICATION((uint8)s8LogicalChannel, I2C_E_SLAVE_BIT_ERROR);
        }
#endif
    }
}

/**
* @brief   Sends the address of the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   u8Channel   I2C channel to be addressed.
* @param[in]   pRequestPtr Pointer to the structure that contains the information necessary to begin the
*                          transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                          and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSendAddress(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequestPtr)
{
    /* Time out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout = I2C_TIMEOUT_LOOPS;
    VAR( uint32, AUTOMATIC) u32MasterStatus = (uint32)0x0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Command = (uint32)LPI2C_REPEAT_START_TRANSMIT_U32;

    /* Reset transmit FIFO */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_RTF_MASK_U32, LPI2C_MCR_RTF_MASK_U32);
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_RTF_MASK_U32, (uint32)0x0U);
    /* Clear interrupt flags */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    u32MasterStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), u32MasterStatus);

    /* Clear the errors found */
    I2c_LPI2C_au8ErrorsFound[u8Channel] = 0x0U;
    
    if ((boolean)TRUE == (boolean)pRequestPtr->bHighSpeedMode)
    {
        if ((boolean)TRUE == (boolean)pRequestPtr->bExpectNack)
        {
            u32Command = (uint32)LPI2C_REPEAT_START_AND_TRANSMIT_HS_NACK_U32;
        }
        else
        {
            u32Command = (uint32)LPI2C_REPEAT_START_TRANSMIT_HS_U32;
        }
    }
    else
    {
        if ((boolean)TRUE == (boolean)pRequestPtr->bExpectNack)
        {
            u32Command = (uint32)LPI2C_REPEAT_START_TRANSMIT_NACK_U32;
        }
        else
        {
            u32Command = (uint32)LPI2C_REPEAT_START_TRANSMIT_U32;
        }
    }
    
    do
    {
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        u32MasterStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel)) & (LPI2C_MSR_BBF_MASK_U32 | LPI2C_MSR_MBF_MASK_U32);
        u32Timeout--;
    } while ((u32Timeout > (uint32)0x0U) && ((uint32)0x0U != u32MasterStatus));
    
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if ( (uint32)0x0U == u32Timeout)
    {

        if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
    }
    else
    {
#endif
        /* Initialize the current index to 0 */
        I2c_LPI2C_au8CurrentIndex[u8Channel] = 0x00U;
        /* Initialize the number of bytes to send */
        I2c_LPI2C_au8NumberOfBytes[u8Channel] = pRequestPtr->u8BufferSize;
        /* Initialize the transfer buffer */
        I2c_LPI2C_aup8DataBuffer[u8Channel] = pRequestPtr->pDataBuffer;

        /* Send slave address */
        if ((boolean)TRUE == (boolean)(pRequestPtr->b10BitsSlaveAddressSize))
        {
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), u32Command | (uint32)((((uint32)pRequestPtr->SlaveAddress >> (uint8)0x08U) & 0x03U) | (uint8)0xF0U));
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), u32Command | ((uint32)pRequestPtr->SlaveAddress & (uint8)0xFFU));
        }
        else
        {
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), u32Command | ((uint32)pRequestPtr->SlaveAddress & (uint8)0xFFU));
        }
        
        u8TmpReturn = (Std_ReturnType)E_OK;
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    }
#endif
    
    return u8TmpReturn;
}


/**
* @brief   Interrupt handler for LPI2C master channels.
* @details This function shall manage all the interrupts of a LPI2C master channel
*
* @param[in]   u8Channel    LPI2C channel to be addressed.
* @param[in]   u32IsrStatus Interrupt flags for the LPI2C channel.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_MasterInterruptProcessing(CONST(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus)
{
    /* Received data. */
    VAR( uint32, AUTOMATIC) u32ReceiveData = 0x0U;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
#if (defined(I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION) || defined(I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION))
    VAR( I2c_StatusType, I2C_VAR) ePreviousChannelStatus;
#endif
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];

    I2c_LPI2C_MasterErrorHandler(u8Channel, u32IsrStatus);

    if (I2C_CH_ERROR_PRESENT != I2c_aeChannelStatus[s8LogicalChannel])
    {
        /* Check for stop detected */
        if (LPI2C_STOP_DETECTED_U32 == (u32IsrStatus & LPI2C_STOP_DETECTED_U32))
        {
            /* Disable error and stop detected interrupts */
            REG_WRITE32(LPI2C_MIER_ADDR32(u8Channel),
                        (
                         LPI2C_PIN_LOW_TIMEOUT_ISR_DISABLE_U32 |
                         LPI2C_FIFO_ERROR_ISR_DISABLE_U32 |
                         LPI2C_ARBITRATION_LOST_ISR_DISABLE_U32 |
                         LPI2C_UNEXPECTED_NACK_ISR_DISABLE_U32 |
                         LPI2C_STOP_DETECT_ISR_DISABLE_U32
                        )
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                       );

#if (defined(I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION) || defined(I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION))
            ePreviousChannelStatus = I2c_aeChannelStatus[s8LogicalChannel];
#endif
            /* Update channel status */
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;

#ifdef I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION
            if (I2C_CH_SEND == ePreviousChannelStatus)
            {
                I2C_MASTER_TRANSMIT_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_LPI2C_au8CurrentIndex[u8Channel]);
            }
#endif

#ifdef I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION
            if (I2C_CH_RECEIVE == ePreviousChannelStatus)
            {
                I2C_MASTER_RECEIVE_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_LPI2C_au8CurrentIndex[u8Channel]);
            }
#endif
        }
        
        /* Check for transmit ready */
        if (LPI2C_TRANSMIT_DATA_IS_READY_U32 == (u32IsrStatus & LPI2C_TRANSMIT_DATA_IS_READY_U32))
        {
            if ( I2C_CH_SEND == I2c_aeChannelStatus[s8LogicalChannel] )
            {
                /* Send next data byte */
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                /** @violates @ref I2C_LPI2C_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
                REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), I2c_LPI2C_aup8DataBuffer[u8Channel][I2c_LPI2C_au8CurrentIndex[u8Channel]]);
                I2c_LPI2C_au8CurrentIndex[u8Channel]++;
                
                if ( I2c_LPI2C_au8CurrentIndex[u8Channel] == I2c_LPI2C_au8NumberOfBytes[u8Channel])
                {
                    REG_RMW32(
                                LPI2C_MIER_ADDR32(u8Channel), 
                                (LPI2C_MIER_TDIE_MASK_U32 | LPI2C_MIER_SDIE_MASK_U32), 
                                (LPI2C_TRANSMIT_DATA_ISR_DISABLE_U32 | LPI2C_STOP_DETECT_ISR_ENABLE_U32)
                    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                             );
                     
                    /* Send STOP condition */
                    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                    REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), LPI2C_GENERATE_STOP_U32);
                }
            }
        }
        /* Check for data received spurious interrupt */
        if (LPI2C_RECEIVE_DATA_IS_READY_U32 == (u32IsrStatus & LPI2C_RECEIVE_DATA_IS_READY_U32))
        {
            if ( I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel] )
            {
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                u32ReceiveData = REG_READ32(LPI2C_MRDR_ADDR32(u8Channel));
                if ( LPI2C_RECEIVE_FIFO_NOT_EMPTY_U32 == (u32ReceiveData & LPI2C_RECEIVE_FIFO_EMPTY_U32) )
                {
                    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                    /** @violates @ref I2C_LPI2C_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
                    I2c_LPI2C_aup8DataBuffer[u8Channel][I2c_LPI2C_au8CurrentIndex[u8Channel]] = (uint8)(u32ReceiveData & LPI2C_MRDR_DATA_MASK_U32);
                    I2c_LPI2C_au8CurrentIndex[u8Channel]++;
                }
                
                if ( I2c_LPI2C_au8CurrentIndex[u8Channel] == I2c_LPI2C_au8NumberOfBytes[u8Channel] )
                {
                    REG_RMW32(LPI2C_MIER_ADDR32(u8Channel), 
                              (LPI2C_MIER_RDIE_MASK_U32 | LPI2C_MIER_SDIE_MASK_U32), 
                              (LPI2C_RECEIVE_DATA_ISR_DISABLE_U32 | LPI2C_STOP_DETECT_ISR_ENABLE_U32)
                    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                             );
                    
                    /* Send STOP condition */
                    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                    REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), LPI2C_GENERATE_STOP_U32);
                }
            }
        }
    }
}


/**
* @brief   Transmission function for LPI2C slave channels.
* @details This function is used to transmit messages from interrupts of LPI2C slave channels
*
* @param[in]   u8Channel LPI2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveTransmit(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* If there are more bytes to be sent */
    if (I2c_LPI2C_au8SlaveCurrentIndex[u8Channel] < I2c_LPI2C_au8SlaveNumberOfBytes[u8Channel])
    {
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        /** @violates @ref I2C_LPI2C_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
        REG_WRITE32(LPI2C_STDR_ADDR32(u8Channel), I2c_LPI2C_aup8SlaveDataBuffer[u8Channel][I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]]);
        I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]++;
    }
    /* The master requested more bytes than they were prepared in the buffer */
    else
    {
        I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]--;
    }

}

/**
* @brief   Receive function for LPI2C slave channels.
* @details This function is used to receive messages from interrupts of LPI2C slave channels
*
* @param[in]   u8Channel LPI2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveReceive(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Received data. */
    VAR( uint32, AUTOMATIC) u32ReceiveData = 0x0U;

    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    u32ReceiveData = REG_READ32(LPI2C_SRDR_ADDR32(u8Channel));
    if ( LPI2C_RDR_NOT_EMPTY_U32 == (u32ReceiveData & LPI2C_SRDR_RXEMPTY_MASK_U32) )
    {
        /* If there are more bytes to be sent */
        if (I2c_LPI2C_au8SlaveCurrentIndex[u8Channel] < I2c_LPI2C_au8SlaveNumberOfBytes[u8Channel])
        {    
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
            I2c_LPI2C_aup8SlaveDataBuffer[u8Channel][I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]] = (uint8)(u32ReceiveData & LPI2C_SRDR_DATA_MASK_U32);
            I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]++;
        }
        /* The master is sending more bytes than the buffer is prepared to receive */
        else
        {
            I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8Channel]] = I2C_CH_ERROR_PRESENT;
        }
    }
}

/**
* @brief   Reset Transmit FIFO and enable TDIE interrupt for LPI2C slave channels.
* @details This function will reset Transmit FIFO and enable TDIE interrupt for LPI2C slave channels.
*
* @param[in]   u8Channel    LPI2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveEnableTransmitDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Reset Transmit FIFO  */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RTF_MASK_U32, LPI2C_SCR_RTF_MASK_U32);
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RTF_MASK_U32, (uint32)0x0U);
    
    if (I2C_CH_ERROR_PRESENT != I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8Channel]])
    {
        /* Enable interrupt for TDIE*/
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_TDIE_MASK_U32, LPI2C_SLAVE_TRANSMIT_DATA_ISR_ENABLE_U32);
    }
}

/**
* @brief   Disable TDIE interrupt and reset Transmit FIFO for LPI2C slave channels.
* @details This function will disable TDIE interrupt and reset Transmit FIFO for LPI2C slave channels.
*
* @param[in]   u8Channel    LPI2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveDisableTransmitDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Disable interrupt for TDIE*/
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_TDIE_MASK_U32, ~LPI2C_SLAVE_TRANSMIT_DATA_ISR_ENABLE_U32);
    /* Reset Transmit FIFO  */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RTF_MASK_U32, LPI2C_SCR_RTF_MASK_U32);
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RTF_MASK_U32, (uint32)0x0U);
}

/**
* @brief   Reset Receive FIFO and enable RDIE interrupt for LPI2C slave channels.
* @details This function will reset Receive FIFO and enable RDIE interrupt for LPI2C slave channels.
*
* @param[in]   u8Channel    LPI2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveEnableReceiveDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Reset Receive FIFO */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, LPI2C_SCR_RRF_MASK_U32);
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, (uint32)0x0U);

    if (I2C_CH_ERROR_PRESENT != I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8Channel]])
    {
        /* Enable interrupt for RDIE */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_RDIE_MASK_U32, LPI2C_SLAVE_RECEIVE_DATA_ISR_ENABLE_U32);
    }
}

/**
* @brief   Disable RDIE interrupt and reset Receive FIFO for LPI2C slave channels.
* @details This function will disable RDIE interrupt and reset Receive FIFO for LPI2C slave channels.
*
* @param[in]   u8Channel    LPI2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC(void, I2C_CODE) I2c_LPI2C_SlaveDisableReceiveDataInterrupt(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Disable interrupt for RDIE */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_RDIE_MASK_U32, LPI2C_SLAVE_RECEIVE_DATA_ISR_DISABLE_U32);
    /* Reset Receive FIFO */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, LPI2C_SCR_RRF_MASK_U32);
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, (uint32)0x0U);
}

/**
* @brief   Interrupt handler for LPI2C slave channels.
* @details This function shall manage all the interrupts of a LPI2C slave channel
*
* @param[in]   u8Channel    LPI2C channel to be addressed.
* @param[in]   u32IsrStatus Interrupt status flags.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_SlaveInterruptProcessing(CONST(uint8, AUTOMATIC) u8Channel, VAR(uint32, AUTOMATIC) u32IsrStatus)
{
    /* Received address. */
    VAR( uint32, AUTOMATIC) u32ReceiveAddress = 0x0U;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    VAR( uint32, AUTOMATIC) u32IsrEnable = 0x0U;
#if (defined(I2C_SLAVE_TRANSMIT_COMPLETE_NOTIFICATION) || defined(I2C_SLAVE_RECEIVE_COMPLETE_NOTIFICATION))
    VAR( I2c_StatusType, I2C_VAR) ePreviousChannelStatus;
#endif
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];

    I2c_LPI2C_SlaveErrorHandler(u8Channel, u32IsrStatus);
    
    if (I2C_CH_ERROR_PRESENT != I2c_aeChannelStatus[s8LogicalChannel])
    {
        if (LPI2C_SLAVE_REPEATED_START_DETECTED_U32 == (u32IsrStatus & LPI2C_SSR_RSF_MASK_U32))
        {
            /* Disable TDIE interrupt and reset Transmit FIFO */
            I2c_LPI2C_SlaveDisableTransmitDataInterrupt(u8Channel);
            
            /* Disable RDIE interrupt and reset Receive FIFO */
            I2c_LPI2C_SlaveDisableReceiveDataInterrupt(u8Channel);
        }

        if (LPI2C_ADDRESS0_MATCH_U32 == (u32IsrStatus & LPI2C_SSR_AM0F_MASK_U32))
        {
             /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
             /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
             u32ReceiveAddress = REG_READ32(LPI2C_SASR_ADDR32(u8Channel));
             
            if (LPI2C_MTDR_READ_BIT_MASK_U8 == (LPI2C_MTDR_READ_BIT_MASK_U8 & u32ReceiveAddress))
            {
                if ((boolean)FALSE == I2c_LPI2C_bReadyForAddressing[u8Channel])
                {
                    /* Disable TDIE interrupt and reset Transmit FIFO */
                    I2c_LPI2C_SlaveDisableTransmitDataInterrupt(u8Channel);
                }
                else
                {
#ifdef I2C_SLAVE_ADDR_MATCH_NOTIFICATION
                    I2C_SLAVE_ADDR_MATCH_NOTIFICATION((uint8)s8LogicalChannel, I2C_SEND_DATA);
#endif

                    /* Enter critical section */
                    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_03();

                    I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_SEND;

                    /* Exit critical section */
                    SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_03();

                    /* Enable TDIE interrupt and reset Transmit FIFO */
                    I2c_LPI2C_SlaveEnableTransmitDataInterrupt(u8Channel);
                }
            }
            else
            {
                if ((boolean)FALSE == I2c_LPI2C_bReadyForAddressing[u8Channel])
                {
                    /* Disable RDIE interrupt and reset Receive FIFO */
                    I2c_LPI2C_SlaveDisableReceiveDataInterrupt(u8Channel);
                }
                else
                {
#ifdef I2C_SLAVE_ADDR_MATCH_NOTIFICATION
                    I2C_SLAVE_ADDR_MATCH_NOTIFICATION((uint8)s8LogicalChannel, I2C_RECEIVE_DATA);
#endif

                    /* Enter critical section */
                    SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_03();

                    I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_RECEIVE;

                    /* Exit critical section */
                    SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_03();
                    
                    /* Enable RDIE interrupt and reset Receive FIFO */
                    I2c_LPI2C_SlaveEnableReceiveDataInterrupt(u8Channel);
                }
            }
            
            I2c_LPI2C_bReadyForAddressing[u8Channel] = (boolean)FALSE;
        }
                
        if (NULL_PTR == I2c_LPI2C_aup8SlaveDataBuffer[u8Channel])
        {
            if (LPI2C_TRANSMIT_ACK_REQUIRED_U32 == (u32IsrStatus & LPI2C_SSR_TAF_MASK_U32))
            {
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32(LPI2C_STAR_ADDR32(u8Channel), LPI2C_STAR_TXNACK_MASK_U32, LPI2C_TRANSMIT_NACK_U32);
            }
        }
        else
        {            
            if (LPI2C_SLAVE_RECEIVE_DATA_IS_READY_U32 == (u32IsrStatus & LPI2C_SSR_RDF_MASK_U32))
            {
                I2c_LPI2C_SlaveReceive(u8Channel);
            }

            /* Slave only transmit the data when TDF flag and TDIE are set */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            u32IsrEnable = REG_READ32(LPI2C_SIER_ADDR32(u8Channel)) & LPI2C_SIER_RWBITS_MASK_U32;
            if (
                (LPI2C_SLAVE_TRANSMIT_DATA_IS_READY_U32 == (u32IsrStatus & LPI2C_SSR_TDF_MASK_U32)) &&
                (LPI2C_SLAVE_TRANSMIT_DATA_ISR_ENABLE_U32 == (u32IsrEnable & LPI2C_SIER_TDIE_MASK_U32))
               )
            {
                I2c_LPI2C_SlaveTransmit(u8Channel);
            }

            if (LPI2C_TRANSMIT_ACK_REQUIRED_U32 == (u32IsrStatus & LPI2C_SSR_TAF_MASK_U32))
            {
                /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32(LPI2C_STAR_ADDR32(u8Channel), LPI2C_STAR_TXNACK_MASK_U32, LPI2C_TRANSMIT_ACK_U32);
            }
            
            if (LPI2C_SLAVE_STOP_DETECTED_U32 == (u32IsrStatus & LPI2C_SSR_SDF_MASK_U32))
            {
                /* Disable TDIE interrupt and reset Transmit FIFO */
                I2c_LPI2C_SlaveDisableTransmitDataInterrupt(u8Channel);

                /* Disable RDIE interrupt and reset Receive FIFO */
                I2c_LPI2C_SlaveDisableReceiveDataInterrupt(u8Channel);

                /* Used to indicate that there is no transfer in progress */
                I2c_LPI2C_aup8SlaveDataBuffer[u8Channel] = NULL_PTR;

#if (defined(I2C_SLAVE_TRANSMIT_COMPLETE_NOTIFICATION) || defined(I2C_SLAVE_RECEIVE_COMPLETE_NOTIFICATION))
                ePreviousChannelStatus = I2c_aeChannelStatus[s8LogicalChannel];
#endif
                /* Update channel status */
                I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;

#ifdef I2C_SLAVE_TRANSMIT_COMPLETE_NOTIFICATION
                if (I2C_CH_SEND == ePreviousChannelStatus)
                {
                    I2C_SLAVE_TRANSMIT_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]);
                }
#endif

#ifdef I2C_SLAVE_RECEIVE_COMPLETE_NOTIFICATION
                if (I2C_CH_RECEIVE == ePreviousChannelStatus)
                {
                    I2C_SLAVE_RECEIVE_COMPLETE_NOTIFICATION((uint8)s8LogicalChannel, I2c_LPI2C_au8SlaveCurrentIndex[u8Channel]);
                }
#endif
            }
        }
    }
    else
    {
        /* Disable TDIE interrupt and reset Transmit FIFO */
        I2c_LPI2C_SlaveDisableTransmitDataInterrupt(u8Channel);
        
        /* Disable RDIE interrupt and reset Receive FIFO */
        I2c_LPI2C_SlaveDisableReceiveDataInterrupt(u8Channel);

        /* Reset interrupt flags if the interruption for other cases */
        if (
            (LPI2C_SMBUS_ALERT_RESPONSE_DETECTED_U32 == (u32IsrStatus & LPI2C_SSR_SARF_MASK_U32)) ||
            (LPI2C_GENERAL_CALL_ADDRESS_DETECTED_U32 == (u32IsrStatus & LPI2C_SSR_GCF_MASK_U32)) ||
            (LPI2C_ADDRESS1_MATCH_U32 == (u32IsrStatus & LPI2C_SSR_AM1F_MASK_U32)) ||
            (LPI2C_ADDRESS0_MATCH_U32 == (u32IsrStatus & LPI2C_SSR_AM0F_MASK_U32)) ||
            (LPI2C_SLAVE_ADDRESS_VALID_U32 == (u32IsrStatus & LPI2C_SSR_AVF_MASK_U32))
           )
        {
            /* reading the Address Status Register */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            (void)REG_READ32(LPI2C_SASR_ADDR32(u8Channel));
        }

        if (LPI2C_TRANSMIT_ACK_REQUIRED_U32 == (u32IsrStatus & LPI2C_SSR_TAF_MASK_U32))
        {
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_STAR_ADDR32(u8Channel), LPI2C_STAR_TXNACK_MASK_U32, LPI2C_TRANSMIT_NACK_U32);
        }

        if (LPI2C_SLAVE_RECEIVE_DATA_IS_READY_U32 == (u32IsrStatus & LPI2C_SSR_RDF_MASK_U32))
        {
            /* Reset Receive FIFO */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, LPI2C_SCR_RRF_MASK_U32);
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_RRF_MASK_U32, (uint32)0x0U);
        }
    }
}

/**
* @brief   Prepares an asynchronous send operation.
* @details Depending on the asynchronous method chosen for the given channel the interrupts will be enabled or
*          the DMA will be configured to continue the asynchronous transfer
*
* @param[in]   u8Channel   I2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_MasterAsyncSend(CONST(uint8, AUTOMATIC) u8Channel)
{
#if (STD_ON == I2C_DMA_USED)
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];

    if (I2C_INTERRUPT_MODE == (*I2c_pConfig->I2c_pHwConfig)[s8LogicalChannel].eAsyncMethod)
    {
#endif
        REG_WRITE32(LPI2C_MIER_ADDR32(u8Channel), 
                    (LPI2C_PIN_LOW_TIMEOUT_ISR_ENABLE_U32 | 
                     LPI2C_FIFO_ERROR_ISR_ENABLE_U32 |
                     LPI2C_ARBITRATION_LOST_ISR_ENABLE_U32 | 
                     LPI2C_UNEXPECTED_NACK_ISR_ENABLE_U32 |
                     LPI2C_TRANSMIT_DATA_ISR_ENABLE_U32
                    )
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                   );
#if (STD_ON == I2C_DMA_USED)
    }
    else
    {
        /* Set the destination for the DMA channel the MTDR register of the LPI2C hw unit */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32daddr = LPI2C_MTDR_ADDR32(u8Channel);
        /* Set the source for the DMA channel as the pointer to the data buffer */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32saddr = (uint32)I2c_LPI2C_aup8DataBuffer[u8Channel];
        
        if (LPI2C_FIFO_SIZE_U8 < I2c_LPI2C_au8NumberOfBytes[u8Channel])
        {
            /* Set the number of bytes equal to the FIFO size, because the DMA will check for the TDF flag
               only after one iteration is finished, so using a bigger number of bytes will flood the FIFO */
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32num_bytes = LPI2C_FIFO_SIZE_U8;
            /* Set the number of iterations. If the number of bytes is not a FIFO_SIZE multiple another DMA transfer
               will be started in the DMA notification for the rest of the bytes */
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32iter  = (uint32)I2c_LPI2C_au8NumberOfBytes[u8Channel]/LPI2C_FIFO_SIZE_U8;
            /* Set the index that will be used in the DMA notification to end the tranmission or start a new one with the rest of the bytes */
            I2c_LPI2C_au8CurrentIndex[u8Channel] = (uint8)(I2c_LPI2C_au8NumberOfBytes[u8Channel]/LPI2C_FIFO_SIZE_U8) * LPI2C_FIFO_SIZE_U8;
        }
        else
        {
            /* Set the number of bytes equal to the FIFO size, because the DMA will check for the TDF flag
               only after one iteration is finished, so using a bigger number of bytes will flood the FIFO */
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32num_bytes = I2c_LPI2C_au8NumberOfBytes[u8Channel];
            /* Set the number of iterations. If the number of bytes is not a FIFO_SIZE multiple another DMA transfer
               will be started in the DMA notification for the rest of the bytes */
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32iter  = (uint32)1U;
            /* Set the index that will be used in the DMA notification to end the tranmission or start a new one with the rest of the bytes */
            I2c_LPI2C_au8CurrentIndex[u8Channel] = I2c_LPI2C_au8NumberOfBytes[u8Channel];
        }
        /* The offset for the data buffer is 8 bits (1 byte) */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32soff  = DMA_OFFSET_8_BITS;
        /* The offset for the destination buffer is 0, because we want all the bytes to be written to MTDR */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32doff  = 0U;
        
        /* Configure the DMA channel with the configured settings */
        Mcl_DmaConfigChannel(I2c_LPI2C_au8TxDmaChannel[u8Channel], &I2c_LPI2C_aDmaCfgDesc[u8Channel]);
        
        /* Enable the TX DMA request in the LPI2C hardware unit */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MDER_ADDR32(u8Channel), LPI2C_MDER_TX_DMA_ENABLE_U32);
        
        /* Enable the notification at the end of the transfer */
        Mcl_DmaEnableNotification(I2c_LPI2C_au8TxDmaChannel[u8Channel], MCL_DMA_TRANSFER_COMPLETE);
        
        /* Enable the Hw Request to start the DMA transfer */
        Mcl_DmaEnableHwRequest(I2c_LPI2C_au8TxDmaChannel[u8Channel]);
    }
#endif
}


/**
* @brief   Sends data synchronously.
* @details Sends data blocking.
*
* @param[in]   u8Channel   I2C channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSyncSend(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    /* Interrupt flags read from the status register. */
    VAR( uint32, AUTOMATIC) u32IsrStatus = 0x0U;
    /* Time out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout = I2C_TIMEOUT_LOOPS;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];

    /* While there still are bytes to be sent */
    while (I2c_LPI2C_au8CurrentIndex[u8Channel] < I2c_LPI2C_au8NumberOfBytes[u8Channel])
    {
        u32Timeout = I2C_TIMEOUT_LOOPS;
        do
        {
            /* Check if the TX FIFO is ready for a new byte */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            u32IsrStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
            u32Timeout--;
        }while ((u32Timeout > (uint32)0x0U) && (LPI2C_TRANSMIT_DATA_IS_READY_U32 != (u32IsrStatus & LPI2C_TRANSMIT_DATA_IS_READY_U32)));
        
        /* Clear interrupt flags */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), u32IsrStatus);

        /* Check for errors */
        I2c_LPI2C_MasterErrorHandler(u8Channel, u32IsrStatus);

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)0x0U == u32Timeout)
        {
            if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        }
#endif

        if ((0x1U == I2c_LPI2C_au8ErrorsFound[u8Channel]) || ((uint32)0x0U == u32Timeout))
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
            u8TmpReturn = (Std_ReturnType)E_NOT_OK;
            break;
        }
        /* Send next data byte */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        /** @violates @ref I2C_LPI2C_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
        REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), I2c_LPI2C_aup8DataBuffer[u8Channel][I2c_LPI2C_au8CurrentIndex[u8Channel]]);
        I2c_LPI2C_au8CurrentIndex[u8Channel]++;
    }
    
    /* If no error was found and the last byte, including the STOP command was sent */
    if ( I2c_LPI2C_au8CurrentIndex[u8Channel] == I2c_LPI2C_au8NumberOfBytes[u8Channel] )
    {
        /* Send Stop command */
        u8TmpReturn = I2c_LPI2C_SendSyncStopCommand(u8Channel);
        
        /* If the stop flag was set, clear the flag and mark the transmission as finished */
        if ((Std_ReturnType)E_OK == u8TmpReturn)
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;
        }
        else
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
        }
    }
    
    return u8TmpReturn;
}

/**
* @brief   Starts sending an I2C message from the master.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*          Fills the TX FIFO and start transmitting data.
*
* @param[in]   u8Channel        I2C channel to be addressed.
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
* @param[in]   eTransmitMode    To determine if the transfer will be synchronous or asynchronous
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSend(
                                                             CONST(uint8, AUTOMATIC) u8Channel,
                                                             P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr,
                                                             CONST(I2c_ModeType, AUTOMATIC) eTransmitMode
                                                           )
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];
    /* Write the Read/Write bit with 0 to indicate a write operation is needed */
    pRequestPtr->SlaveAddress &= ~LPI2C_MTDR_READ_BIT_MASK_U8;
    /* Send the slave address */
    u8TmpReturn = I2c_LPI2C_MasterSendAddress(u8Channel, pRequestPtr);
    
    /* If the address was sent successfully the data can be sent */
    if ((Std_ReturnType)E_OK == u8TmpReturn)
    {
        /* If the I2C_AsyncTransmit was called enable the error and transmit interrupts */
        if ( I2C_ASYNC_MODE == eTransmitMode )
        {
            I2c_LPI2C_MasterAsyncSend(u8Channel);
        }
        /* If I2C_SyncTransmit was called send the data blocking */
        else
        {
            u8TmpReturn = I2c_LPI2C_MasterSyncSend(u8Channel);
        }
    }
    else
    {
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
    }
    
    return u8TmpReturn;
}


/**
* @brief   Prepares an asynchronous receive operation.
* @details Depending on the asynchronous method chosen for the given channel the interrupts will be enabled or
*          the DMA will be configured to continue the asynchronous transfer
*
* @param[in]   u8Channel   I2C channel to be addressed.
*
* @return       void.
*
*/
static FUNC (void, I2C_CODE) I2c_LPI2C_MasterAsyncReceive(CONST(uint8, AUTOMATIC) u8Channel)
{
#if (STD_ON == I2C_DMA_USED)
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;

    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];
    if (I2C_INTERRUPT_MODE == (*I2c_pConfig->I2c_pHwConfig)[s8LogicalChannel].eAsyncMethod)
    {
#endif
        REG_WRITE32(LPI2C_MIER_ADDR32(u8Channel), 
                        (LPI2C_PIN_LOW_TIMEOUT_ISR_ENABLE_U32 | 
                         LPI2C_FIFO_ERROR_ISR_ENABLE_U32 |
                         LPI2C_ARBITRATION_LOST_ISR_ENABLE_U32 | 
                         LPI2C_UNEXPECTED_NACK_ISR_ENABLE_U32 |
                         LPI2C_RECEIVE_DATA_ISR_ENABLE_U32
                        )
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                   );
#if (STD_ON == I2C_DMA_USED)
    }
    else
    {
        /* Set the destination for the DMA channel as the pointer to the data buffer */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32daddr = (uint32)I2c_LPI2C_aup8DataBuffer[u8Channel];
        /* Set the source for the DMA channel the MRDR register of the LPI2C hw unit */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32saddr = LPI2C_MRDR_ADDR32(u8Channel);
        /* Set the number of bytes for an iteration 1 to receive the bytes one by one and to check for the DMA
           trigger (RDF bit) after each byte */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32num_bytes = 1U;
        /* Set the number of iterations equal to the number of bytes to be received */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32iter  = (uint8)I2c_LPI2C_au8NumberOfBytes[u8Channel];
        /* Set the source offset to 0, because we always need to read from MRDR */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32soff  = 0U; 
        /* Set the offset for the destination equal to 8 bits (1 byte) to increment the index in the data buffer */
        I2c_LPI2C_aDmaCfgDesc[u8Channel].u32doff  = DMA_OFFSET_8_BITS;
        
        /* Configure the DMA channel with the wanted settings */
        Mcl_DmaConfigChannel(I2c_LPI2C_au8RxDmaChannel[u8Channel], &I2c_LPI2C_aDmaCfgDesc[u8Channel]);
        
        /* Update the index for the transfer */
        I2c_LPI2C_au8CurrentIndex[u8Channel] = (uint8)I2c_LPI2C_au8NumberOfBytes[u8Channel];
        
        /* Enable the DMA RX request in the LPI2C hardware unit */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MDER_ADDR32(u8Channel), LPI2C_MDER_RX_DMA_ENABLE_U32);
        
        /* Enable the notification at the end of the transfer */
        Mcl_DmaEnableNotification(I2c_LPI2C_au8RxDmaChannel[u8Channel], MCL_DMA_TRANSFER_COMPLETE);
        
        /* Enable the Hw Request to start the DMA transfer */
        Mcl_DmaEnableHwRequest(I2c_LPI2C_au8RxDmaChannel[u8Channel]);
    }
#endif
}


/**
* @brief   Receives data synchronously.
* @details Receives data blocking.
*
* @param[in]   u8Channel   I2C channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterSyncReceive(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    /* Received data. */
    VAR( uint32, AUTOMATIC) u32ReceiveData = 0x0U;
    /* Interrupt flags read from the status register. */
    VAR( uint32, AUTOMATIC) u32IsrStatus = 0x0U;
    /* Time out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout = I2C_TIMEOUT_LOOPS;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;

    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];

    /* While there still are bytes to be sent */
    while (I2c_LPI2C_au8CurrentIndex[u8Channel] < I2c_LPI2C_au8NumberOfBytes[u8Channel])
    {
        u32Timeout = I2C_TIMEOUT_LOOPS;
        do
        {
            /* Check if the RX FIFO is not empty */
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            u32IsrStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
            u32Timeout--;
        }while ((u32Timeout > (uint32)0x0U) && (LPI2C_RECEIVE_DATA_IS_READY_U32 != (u32IsrStatus & LPI2C_RECEIVE_DATA_IS_READY_U32)));

        if ( (uint32)0x0U == u32Timeout)
        {
#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == I2c_pDemCfg->I2c_E_TimeoutFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType)I2c_pDemCfg->I2c_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
            u8TmpReturn = (Std_ReturnType)E_NOT_OK;
            break;
        }
        else
        {
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            u32ReceiveData = REG_READ32(LPI2C_MRDR_ADDR32(u8Channel));
            if ( LPI2C_RECEIVE_FIFO_NOT_EMPTY_U32 == (u32ReceiveData & LPI2C_RECEIVE_FIFO_EMPTY_U32) )
            {
                /** @violates @ref I2C_LPI2C_c_REF_6 MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer */
                I2c_LPI2C_aup8DataBuffer[u8Channel][I2c_LPI2C_au8CurrentIndex[u8Channel]] = (uint8)(u32ReceiveData & LPI2C_MRDR_DATA_MASK_U32);
                I2c_LPI2C_au8CurrentIndex[u8Channel]++;
            }
        }
    }
    
    if ( I2c_LPI2C_au8CurrentIndex[u8Channel] == I2c_LPI2C_au8NumberOfBytes[u8Channel] )
    {
        u8TmpReturn = I2c_LPI2C_SendSyncStopCommand(u8Channel);
        
        /* If the stop flag was set, clear the flag and mark the transmission as finished */
        if ((Std_ReturnType)E_OK == u8TmpReturn)
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_FINISHED;
        }
        else
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
        }
    }
    
    return u8TmpReturn;
}


/**
* @brief   Sends a command to the slave for receiving a number of bytes.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*          Sends a receive command with the number of bytes in the DATA field
*
* @param[in]   u8Channel        I2C channel to be addressed.
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
* @param[in]   eTransmitMode    To determine if the transfer will be synchronous or asynchronous
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
static FUNC (Std_ReturnType, I2C_CODE) I2c_LPI2C_MasterReceive(
                                                                  CONST(uint8, AUTOMATIC) u8Channel, 
                                                                  P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr,
                                                                  CONST(I2c_ModeType, AUTOMATIC) eTransmitMode
                                                              )
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Command = (uint32)LPI2C_RECEIVE_U32;
    /* Interrupt flags read from the status register. */
    VAR( uint32, AUTOMATIC) u32IsrStatus = 0x0U;
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;

    s8LogicalChannel = I2c_as8ChannelHardwareMap[u8Channel];
    pRequestPtr->SlaveAddress |= LPI2C_MTDR_READ_BIT_MASK_U8;
    u8TmpReturn = I2c_LPI2C_MasterSendAddress(u8Channel, pRequestPtr);
    
    if ((Std_ReturnType)E_OK == u8TmpReturn)
    {
        /* Send a receive command with the number of bytes in DATA field */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MTDR_ADDR32(u8Channel), u32Command | (((uint32)pRequestPtr->u8BufferSize - 1U) & (uint8)0xFFU));
        
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        u32IsrStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
        /* Clear interrupt flags */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), u32IsrStatus);
                    
        I2c_LPI2C_MasterErrorHandler(u8Channel, (uint32)u32IsrStatus);
        
        if (0x1U == I2c_LPI2C_au8ErrorsFound[u8Channel])
        {
            I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
            u8TmpReturn = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* If the I2C_AsyncTransmit was called enable the error and receive interrupts */
            if ( I2C_ASYNC_MODE == eTransmitMode )
            {
                I2c_LPI2C_MasterAsyncReceive(u8Channel);
            }
            /* If I2C_SyncTransmit was called receive the data blocking */
            else
            {
                u8TmpReturn = I2c_LPI2C_MasterSyncReceive(u8Channel);
            }
        }
    }
    else
    {
        I2c_aeChannelStatus[s8LogicalChannel] = I2C_CH_ERROR_PRESENT;
    }
    
    return u8TmpReturn;
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (STD_ON == I2C_DMA_USED)
    #if defined(LPI2C_0)
/**
* @brief   The notification that must be configured in the Mcl configuration if LPI2C0 is used for the RX DMA channel.
* @details This function is called from the DMA interrupt when the RX channel finishes the transmission.
*
* @return            void
*
*/
/** @violates @ref I2C_LPI2C_c_REF_4 All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
*/
FUNC (void, I2C_CODE) I2c_LPI2C0_DmaRxCompleteNotification(VAR( void, AUTOMATIC))
{
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[LPI2C_0];

    /* Disable the Hw Request */
    Mcl_DmaDisableHwRequest(I2c_LPI2C_au8RxDmaChannel[LPI2C_0]);
    
    if ( I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        I2c_LPI2C_DmaReceiveProcessing(LPI2C_0);
    }
}


/**
* @brief   The notification that must be configured in the Mcl configuration if LPI2C0 is used for the TX DMA channel.
* @details This function is called from the DMA interrupt when the TX channel finishes the transmission.
*
* @return            void
*
*/
/** @violates @ref I2C_LPI2C_c_REF_4 All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
*/
FUNC (void, I2C_CODE) I2c_LPI2C0_DmaTxCompleteNotification(VAR( void, AUTOMATIC))
{
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[LPI2C_0];

    /* Disable the Hw Request */
    Mcl_DmaDisableHwRequest(I2c_LPI2C_au8TxDmaChannel[LPI2C_0]);
    
    if ( I2C_CH_SEND == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        I2c_LPI2C_DmaSendProcessing(LPI2C_0);
    }
}
    #endif
    
    #if defined(LPI2C_1)
/**
* @brief   The notification that must be configured in the Mcl configuration if LPI2C1 is used for the RX DMA channel.
* @details This function is called from the DMA interrupt when the RX channel finishes the transmission.
*
* @return            void
*
*/
/** @violates @ref I2C_LPI2C_c_REF_4 All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
*/
FUNC (void, I2C_CODE) I2c_LPI2C1_DmaRxCompleteNotification(VAR( void, AUTOMATIC))
{
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[LPI2C_1];

    /* Disable the Hw Request */
    Mcl_DmaDisableHwRequest(I2c_LPI2C_au8RxDmaChannel[LPI2C_1]);
    
    if ( I2C_CH_RECEIVE == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        I2c_LPI2C_DmaReceiveProcessing(LPI2C_1);
    }
}


/**
* @brief   The notification that must be configured in the Mcl configuration if LPI2C1 is used for the TX DMA channel.
* @details This function is called from the DMA interrupt when the TX channel finishes the transmission.
*
* @return            void
*
*/
/** @violates @ref I2C_LPI2C_c_REF_4 All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
*/
FUNC (void, I2C_CODE) I2c_LPI2C1_DmaTxCompleteNotification(VAR( void, AUTOMATIC))
{
    VAR( sint8, AUTOMATIC) s8LogicalChannel = -1;
    
    s8LogicalChannel = I2c_as8ChannelHardwareMap[LPI2C_1];

    /* Disable the Hw Request */
    Mcl_DmaDisableHwRequest(I2c_LPI2C_au8TxDmaChannel[LPI2C_1]);
    
    if ( I2C_CH_SEND == I2c_aeChannelStatus[s8LogicalChannel] )
    {
        I2c_LPI2C_DmaSendProcessing(LPI2C_1);
    }
}
    #endif
#endif

/**
* @brief   Initialize a I2C channel.
* @details This function initializes all hardware registers needed to
*          start the I2C functionality on the selected channel.
*
* @param[in] u8Channel  I2C channel to be initialized.
*            pConfigPtr Configuration pointer containing hardware specific settings.
*
* @return            void.
*
*/
FUNC (void, I2C_CODE) I2c_LPI2C_InitChannel(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(I2c_LPI2C_HwChannelConfigType, AUTOMATIC, I2C_APPL_CONST) pConfigPtr)
{
    /* Disable master if enabled */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_MEN_MASK_U32, LPI2C_MCR_MASTER_DISABLE_U32);

    /* Reset master logic, receive FIFO and transmit FIFO */
    REG_RMW32(
                LPI2C_MCR_ADDR32(u8Channel), 
                (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32), 
                (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32)
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
             );
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32), (uint32)0x0U);
    
     /* Disable slave if enabled */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_SEN_MASK_U32, LPI2C_SCR_SLAVE_DISABLE_U32);

    /* Reset slave logic, receive FIFO and transmit FIFO */
    REG_RMW32(
                LPI2C_SCR_ADDR32(u8Channel), 
                (LPI2C_SCR_RRF_MASK_U32 | LPI2C_SCR_RTF_MASK_U32 | LPI2C_SCR_RST_MASK_U32), 
                (LPI2C_SCR_RESET_RECEIVE_FIFO_U32 | LPI2C_SCR_RESET_TRANSMIT_FIFO_U32 | LPI2C_SCR_RST_MASK_U32)
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
             );  
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), (LPI2C_SCR_RRF_MASK_U32 | LPI2C_SCR_RTF_MASK_U32 | LPI2C_SCR_RST_MASK_U32), (uint32)0x0U);

    /* If the channel is either a MASTER or MASTER/SLAVE */
    if ( I2C_SLAVE_MODE != (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eMasterSlaveConfig )
    {
        /* Enable/disable the channel in debug/doze mode */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), (LPI2C_MCR_DBGEN_MASK_U32 | LPI2C_MCR_DOZEN_MASK_U32), pConfigPtr->u32MasterControlConfig);
        
        /* Configure master configuration registers */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MCFGR1_ADDR32(u8Channel), pConfigPtr->u32MasterConfig1);
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MCFGR2_ADDR32(u8Channel), pConfigPtr->u32MasterConfig2);
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MCFGR3_ADDR32(u8Channel), pConfigPtr->u32MasterConfig3);
        
        /* Configure master clock configuration register */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MCCR0_ADDR32(u8Channel), pConfigPtr->u32ClockingConfig0);
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MCCR1_ADDR32(u8Channel), pConfigPtr->u32ClockingConfig1);
#if (STD_ON == I2C_DMA_USED)
        /* Set ssize, dsize, smod and dmod to 0 because the values will be used for all transfers */
        if (I2C_DMA_MODE == (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eAsyncMethod)
        {
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32dsize = 0U; 
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32ssize = 0U;
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32smod  = 0U;  
            I2c_LPI2C_aDmaCfgDesc[u8Channel].u32dmod  = 0U;
            
            I2c_LPI2C_au8TxDmaChannel[u8Channel] = pConfigPtr->u8TxDmaChannel;
            I2c_LPI2C_au8RxDmaChannel[u8Channel] = pConfigPtr->u8RxDmaChannel;
        }
#endif
        /* Enable the master logic */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_MEN_MASK_U32, LPI2C_MCR_MASTER_ENABLE_U32);
    }
    
    /* If the channel is either a SLAVE or MASTER/SLAVE */
    if ( I2C_MASTER_MODE != (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eMasterSlaveConfig )
    {
        /* Write the pin configuration in MCFGR1 */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_MCFGR1_ADDR32(u8Channel), LPI2C_MCFGR1_PINCFG_MASK_U32, pConfigPtr->u32MasterConfig1);
        
        /* Enable/disable the filters */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), (LPI2C_SCR_FILTDZ_MASK_U32 | LPI2C_SCR_FILTEN_MASK_U32), pConfigPtr->u32SlaveControlConfig);
        
        /* Configure slave configuration registers */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_SCFGR1_ADDR32(u8Channel), pConfigPtr->u32SlaveConfig1);
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_SCFGR2_ADDR32(u8Channel), pConfigPtr->u32SlaveConfig2);
        
        /* Configure slave address */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_SAMR_ADDR32(u8Channel), pConfigPtr->u32SlaveAddressConfig);
        
        /* The Slave will start processing transactions when the user calls "StartListening()". */
        I2c_LPI2C_bReadyForAddressing[u8Channel] = (boolean)FALSE;
        
        /* Enable the slave logic */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_SEN_MASK_U32, LPI2C_SCR_SLAVE_ENABLE_U32);
        
        /* Enable all interrupts except TDIE, TDIE will enable when the received address has matched the ADDR0 field*/
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_RWBITS_MASK_U32&(~LPI2C_SIER_TDIE_MASK_U32), LPI2C_SIER_RWBITS_MASK_U32&(~LPI2C_SIER_TDIE_MASK_U32));
        
        /* Enable ADDR0 IE */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_AM0IE_MASK_U32, LPI2C_ADDRESS0_MATCH_ISR_ENABLE_U32);
        
        /* Disable ADDR1 IE */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SIER_ADDR32(u8Channel), LPI2C_SIER_AM1IE_MASK_U32, LPI2C_ADDRESS1_MATCH_ISR_DISABLE_U32);
    }
}


/**
* @brief   De initialize a I2c channel.
* @details This function de initializes the hardware registers of an I2c channel
*
* @param[in] u8Channel I2c channel to be de initialized.
*
* @return            void.
*
*/
FUNC (void, I2C_CODE) I2c_LPI2C_DeInitChannel(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Disable master if enabled */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_MEN_MASK_U32, LPI2C_MCR_MASTER_DISABLE_U32);

    /* Reset master logic, receive FIFO and transmit FIFO */
    REG_RMW32(
                LPI2C_MCR_ADDR32(u8Channel), 
                (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32), 
                (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32)
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
             );

    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32), (uint32)0x0U);
    
     /* Disable slave if enabled */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_SEN_MASK_U32, LPI2C_SCR_SLAVE_DISABLE_U32);

    /* Reset slave logic, receive FIFO and transmit FIFO */
    REG_RMW32(
                LPI2C_SCR_ADDR32(u8Channel), 
                (LPI2C_SCR_RRF_MASK_U32 | LPI2C_SCR_RTF_MASK_U32 | LPI2C_SCR_RST_MASK_U32), 
                (LPI2C_SCR_RESET_RECEIVE_FIFO_U32 | LPI2C_SCR_RESET_TRANSMIT_FIFO_U32 | LPI2C_SCR_RST_MASK_U32)
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
             );
             
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), (LPI2C_SCR_RRF_MASK_U32 | LPI2C_SCR_RTF_MASK_U32 | LPI2C_SCR_RST_MASK_U32), (uint32)0x0U);
}

/**
* @brief   Prepare the RX or TX buffer for a slave channel.
* @details Prepares a RX or TX buffer that will be used to receive data or send data when requested by the master.
*
* @param[in] u8Channel       I2c channel to be addressed.
* @param[in] u8NumberOfBytes Maximum number of bytes.
* @param[in] pDataBuffer     Pointer to data buffer
*
* @return                  void
*/
FUNC(void, I2C_CODE)  I2c_LPI2C_PrepareSlaveBuffer(
                                                    VAR(uint8, AUTOMATIC) u8Channel,
                                                    VAR(uint8, AUTOMATIC) u8NumberOfBytes, 
                                                    P2VAR(I2c_DataType, AUTOMATIC, I2C_APPL_DATA) pDataBuffer
                                                  )
{
    /* Initialize the current index to 0 */
    I2c_LPI2C_au8SlaveCurrentIndex[u8Channel] = 0x00U;
    /* Initialize the number of bytes to send */
    I2c_LPI2C_au8SlaveNumberOfBytes[u8Channel] = u8NumberOfBytes;
    /* Prepare the TX buffer */
    I2c_LPI2C_aup8SlaveDataBuffer[u8Channel] = pDataBuffer;
}

/**
* @brief   Makes a slave channel available for processing requests (addressings).
* @details When called, the slave channel becomes available for starting incoming or outgoing transfers.
*
* @param[in] u8Channel     I2C channel to be addressed.
*
* @return                  void
*/
FUNC(void, I2C_CODE)  I2c_LPI2C_StartListening(VAR(uint8, AUTOMATIC) u8Channel)
{
    I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8Channel]] = I2C_CH_IDLE;
    I2c_LPI2C_bReadyForAddressing[u8Channel] = (boolean)TRUE;
}

/**
* @brief   Sends or receives an I2c message from the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   u8Channel   I2c channel to be addressed.
* @param[in]   pRequestPtr Pointer to the structure that contains the information necessary to begin the
*                          transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                          and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_LPI2C_SyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequest)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    
    if (I2C_SEND_DATA == pRequest->eDataDirection)
    {
        u8TmpReturn = I2c_LPI2C_MasterSend(u8Channel, pRequest, I2C_SYNC_MODE);
    }
    else
    {
        u8TmpReturn = I2c_LPI2C_MasterReceive(u8Channel, pRequest, I2C_SYNC_MODE);
    }
    
    return u8TmpReturn;
}


/**
* @brief   Starts sending an I2c message from the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   u8Channel   I2c channel to be addressed.
* @param[in]   pRequestPtr Pointer to the structure that contains the information necessary to begin the
*                          transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                          and the data buffer
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_LPI2C_AsyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequest)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    
    if (I2C_SEND_DATA == pRequest->eDataDirection)
    {
        u8TmpReturn = I2c_LPI2C_MasterSend(u8Channel, pRequest, I2C_ASYNC_MODE);
    }
    else
    {
        u8TmpReturn = I2c_LPI2C_MasterReceive(u8Channel, pRequest, I2C_ASYNC_MODE);
    }
    
    return u8TmpReturn;
}


/**
* @brief   Interrupt handler for a master LPI2C.
* @details This function shall manage all the interrupts of a LPI2C master channel
*
* @param[in]   u8Channel LPI2C master channel to be addressed.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
FUNC (void, I2C_CODE) I2c_LPI2C_MasterInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Interrupt flags read from the master status register. */
    VAR(uint32, AUTOMATIC) u32IsrStatus = 0x0U;
    /* Interrupt enable flags read from the master interrupt enable register. */
    VAR(uint32, AUTOMATIC) u32MaskedIsrStatus = 0x0U;
    
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    u32IsrStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
    /* Clear all interrupt flags */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), u32IsrStatus);

    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    u32MaskedIsrStatus = u32IsrStatus & (REG_READ32(LPI2C_MIER_ADDR32(u8Channel)) & LPI2C_MIER_RWBITS_MASK_U32);
    
    if (NULL_PTR != I2c_pConfig)
    {
        if ( I2C_SLAVE_MODE != (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eMasterSlaveConfig )
        {
            /* Check if the driver is initialized and if any flags are set */
            if (0x0U != u32MaskedIsrStatus)
            {
                I2c_LPI2C_MasterInterruptProcessing(u8Channel, u32MaskedIsrStatus);
            }
        }
    }
    else
    {
        /* Driver has not been initialized, clear status flags and Reset the LPSPI Regs*/
        /* Reset the LPI2C Regs and Transmit/Receive FIFO */
        /* Disable master if enabled */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), LPI2C_MCR_MEN_MASK_U32, LPI2C_MCR_MASTER_DISABLE_U32);

        /* Reset master logic, receive FIFO and transmit FIFO */
        REG_RMW32(
                    LPI2C_MCR_ADDR32(u8Channel), 
                    (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32), 
                    (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32)
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                 );
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_MCR_ADDR32(u8Channel), (LPI2C_MCR_RRF_MASK_U32 | LPI2C_MCR_RTF_MASK_U32 | LPI2C_MCR_RST_MASK_U32), (uint32)0x0U);
    }
}

/**
* @brief   Interrupt handler for a slave LPI2C.
* @details This function shall manage all the interrupts of a LPI2C slave channel
*
* @param[in]   u8Channel LPI2C slave channel to be addressed.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
FUNC (void, I2C_CODE) I2c_LPI2C_SlaveInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Interrupt enabled/disabled. */
    VAR( uint32, AUTOMATIC) u32IsrEnable = 0x0U;
    /* Interrupt flags read from the slave status register. */
    VAR( uint32, AUTOMATIC) u32SlaveIsrStatus = 0x0U;
    
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    u32SlaveIsrStatus = REG_READ32(LPI2C_SSR_ADDR32(u8Channel));
    /* Clear interrupt flags */
    /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(LPI2C_SSR_ADDR32(u8Channel), u32SlaveIsrStatus);
    
    if (NULL_PTR != I2c_pConfig)
    {
        if ( I2C_MASTER_MODE != (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eMasterSlaveConfig )
        {
            /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
            u32IsrEnable = REG_READ32(LPI2C_SIER_ADDR32(u8Channel)) & LPI2C_SIER_RWBITS_MASK_U32;
            
            /* Check if any flags are set */
            if ((0x0U != u32SlaveIsrStatus) && (0x0U != u32IsrEnable))
            {
                I2c_LPI2C_SlaveInterruptProcessing(u8Channel, u32SlaveIsrStatus);
            }
        }
    }
    else
    {
        /* Driver has not been initialized, clear status flags and Reset the LPSPI Regs*/
        /* Reset the LPI2C Regs and Transmit/Receive FIFO */
        /* Disable slave if enabled */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), LPI2C_SCR_SEN_MASK_U32, LPI2C_SCR_SLAVE_DISABLE_U32);

        /* Reset slave logic, receive FIFO and transmit FIFO */
        REG_RMW32(
                    LPI2C_SCR_ADDR32(u8Channel), 
                    (LPI2C_SCR_RRF_MASK_U32 | LPI2C_SCR_RTF_MASK_U32 | LPI2C_SCR_RST_MASK_U32), 
                    (LPI2C_SCR_RESET_RECEIVE_FIFO_U32 | LPI2C_SCR_RESET_TRANSMIT_FIFO_U32 | LPI2C_SCR_RST_MASK_U32)
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
                 );
                 
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32(LPI2C_SCR_ADDR32(u8Channel), (LPI2C_SCR_RRF_MASK_U32 | LPI2C_SCR_RTF_MASK_U32 | LPI2C_SCR_RST_MASK_U32), (uint32)0x0U);
    }
}

/**
* @brief   Gets the status of a LPI2C channel.
* @details The function will check for error flags and return the status of a channel.
*
* @param[in]   u8Channel I2c channel to be addressed.
*
* @return   I2c_StatusType.
* @retval I2C_CH_IDLE           In case the channel was just initialized and not request is pending.
* @retval I2C_CH_SEND           In case the channel is busy sending data.
* @retval I2C_CH_RECEIVE        In case the channel is busy receiving data.
* @retval I2C_CH_FINISHED       In case a transmission or reception of bytes has finished.
* @retval I2C_CH_ERROR_PRESENT  In case an error is present.
*
*/
FUNC (I2c_StatusType, I2C_CODE) I2c_LPI2C_GetStatus(CONST(uint8, AUTOMATIC) u8Channel)
{
    /* Interrupt flags read from the status register. */
    VAR( uint32, AUTOMATIC) u32IsrStatus = 0x0U;
    VAR(I2c_StatusType, AUTOMATIC) eChannelStatus = I2C_CH_IDLE;
    
    if ( I2C_MASTER_MODE != (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eMasterSlaveConfig )
    {
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        u32IsrStatus = REG_READ32(LPI2C_SSR_ADDR32(u8Channel));
        /* Clear interrupt flags */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_SSR_ADDR32(u8Channel), u32IsrStatus);
    
        I2c_LPI2C_SlaveErrorHandler(u8Channel, (uint32)u32IsrStatus);
    }
    if ( I2C_SLAVE_MODE != (*I2c_pConfig->I2c_pHwConfig)[I2c_as8ChannelHardwareMap[u8Channel]].eMasterSlaveConfig )
    {
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        u32IsrStatus = REG_READ32(LPI2C_MSR_ADDR32(u8Channel));
        /* Clear interrupt flags */
        /** @violates @ref I2C_LPI2C_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref I2C_LPI2C_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(LPI2C_MSR_ADDR32(u8Channel), u32IsrStatus);
    
        I2c_LPI2C_MasterErrorHandler(u8Channel, (uint32)u32IsrStatus);
    }
    
    eChannelStatus = I2c_aeChannelStatus[I2c_as8ChannelHardwareMap[u8Channel]];
    
    return eChannelStatus;
}

#define I2C_STOP_SEC_CODE
/**
* @violates @ref I2C_LPI2C_c_REF_1 #include statements in a file should only be preceded by other preprocessor directives or comments.
* @violates @ref I2C_LPI2C_c_REF_2 Precautions shall be taken in order to prevent the contents of a header file being included twice.
*/
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
