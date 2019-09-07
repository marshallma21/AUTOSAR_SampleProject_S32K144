/**
*   @file    Spi_LPspi.h
*   @implements Spi_LPspi.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - LPSPI LLD header file.
*   @details LPSPI peripheral LLD header file.

*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI
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

#ifndef SPI_LPSPI_H
#define SPI_LPSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_LPspi_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_LPspi_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_LPspi_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Spi_LPspi_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_LPspi_h_REF_5
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_VENDOR_ID_LPSPI                    43
/*
* @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_MAJOR_VERSION_LPSPI     4
/*
* @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_LPSPI     2
/*
* @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_LPSPI  2
#define SPI_SW_MAJOR_VERSION_LPSPI             1
#define SPI_SW_MINOR_VERSION_LPSPI             0
#define SPI_SW_PATCH_VERSION_LPSPI             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief  Map HWUnit to LPSPI device structure.
*/
/*
* @violates @ref Spi_LPspi_h_REF_3 A function should be used in preference to a function-like macro.
*/

#define LPSPI_HWUNIT2LPSPI(HWUnit)    (&Spi_LPspi_aDeviceState[(HWUnit)])


#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   This Macro shall set different MCU clock mode .
* @details This Macro shall set different MCU clock mode .
*
* @param[in]    ClockMode   Clock mode to be set.
*
* @pre  Pre-compile parameter SPI_DUAL_CLOCK_MODE shall be STD_ON.
*
*/
/*================================================================================================*/
/*
* @violates @ref Spi_LPspi_h_REF_3 A function should be used in preference to a function-like macro.
*/
#define LPSPI_SET_CLOCK_MODE(ClockMode)  (Spi_LPspi_ClockMode = (ClockMode))

#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   Internal structure keeping a set of cached channel attributes.
* @details Internal structure keeping a set of cached channel attributes
*          used by the optimized implementation of Spi_SyncTransmit() for
*          the sequences having only one job.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Cached value of the TCR register. */
    VAR(uint32, SPI_VAR) LPspi_u32TCR[2];
#else
    VAR(uint32, SPI_VAR) LPspi_u32TCR;
#endif
    /**< @brief Cached pointer to the buffer descriptor. */
    P2CONST(Spi_BufferDescriptorType, SPI_VAR, SPI_APPL_CONST) LPspi_pcBufferDescriptor;
    /**< @brief Cached pointer to the channel states. */
    P2VAR(Spi_ChannelStateType, SPI_VAR, SPI_APPL_DATA) LPspi_pState;
    /**< @brief Cached default transmit value. */
     VAR(Spi_DataBufferType, SPI_VAR) LPspi_DefaultTransmitValue;
     /**< @brief Channel attributes for data width. */
    VAR(uint8, SPI_VAR) LPspi_u8DataWidth;
} Spi_LPspi_ChannelCacheAttrsType;

/**
* @brief    Internal structure keeping a set of cached sequences attributes.
* @details  Internal structure keeping a set of cached sequences attributes
*           used by the optimized implementation of Spi_SyncTransmit() for
*           the sequences having only one job.
*/
typedef struct
{
    /**< @brief HWUnit. */
    VAR(Spi_HWUnitType, SPI_VAR) LPspi_HWUnit;
    /**< @brief Number of channels in sequence. */
    VAR(Spi_ChannelType, SPI_VAR) LPspi_NumChannels;
    /**< @brief Cached pointer to the sequence job state. */
    P2VAR(Spi_JobStateType, SPI_VAR, SPI_APPL_DATA) LPspi_pJobState;
    /**< @brief Cached pointer to the sequence LPSPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) LPspi_pJobStatus;
    /**< @brief Table of channel cached attributes. */
    P2VAR(Spi_LPspi_ChannelCacheAttrsType, SPI_VAR, SPI_APPL_DATA) LPspi_pChannels;
    /**< @brief Cached value of the LPSPI HW Unit memory mapped registers base address. */
    VAR(uint32, SPI_VAR) LPspi_u32BaseAddress;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Cached value of CMD field of the SPI dataframes. */
    VAR(uint32, SPI_VAR) LPspi_u32JobCMD[2];
    /**< @brief Cached value of CCR field of the SPI dataframes. */
    VAR(uint32, SPI_VAR) LPspi_u32JobCCR[2];
#else
    /**< @brief Cached value of CMD field of the SPI dataframes. */
    VAR(uint32, SPI_VAR) LPspi_u32JobCMD;
    /**< @brief Cached value of CCR field of the SPI dataframes. */
    VAR(uint32, SPI_VAR) LPspi_u32JobCCR;
#endif
/*
 * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
 * significance and case sensitivity are supported for external identifiers.
 */
} Spi_LPspi_SequenceCacheAttrsType;
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

/**
* @brief This structure holds runtime configuration parameters for Spi handler.
*/
typedef struct
{
    /**< @brief Reference to the corresponding HWUnit config instance. */
    P2CONST(Spi_HWUnitConfigType, SPI_VAR, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
    /**< @brief Address of the master TX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) LPspi_pu32TxDmaTcd;
    /**< @brief Address of the master RX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) LPspi_pu32RxDmaTcd;
#endif    
    /**< @brief TCR register used to define different transfer attributes for external device. */
    VAR(uint32, SPI_VAR) LPspi_u32ExternalDeviceTCR;
    /**< @brief CCR register used to define different transfer attributes for external device. */
    VAR(uint32, SPI_VAR) LPspi_u32ExternalDeviceCCR;
    /**< @brief Pointer to the Tx buffer of the channel currently in transmission. */
     P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) LPspi_pCurrentTxBuffer;
    /**< @brief Pointer to the Rx buffer of the channel currently in transmission. */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) LPspi_pCurrentRxBuffer;
     /**< @brief The frame default data value to be used for the channel in transmission. */
    VAR(uint32, SPI_VAR) LPspi_u32TransmitDefaultData;
    /**< @brief Position in ChannelIndexList to the channel in transmission. */
    /*
     * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
     * significance and case sensitivity are supported for external identifiers.
     */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) LPspi_pcCurrentChannelIndexPointerTX;
    /**< @brief Position in ChannelIndexList to the channel in transmission. */
    /*
     * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
     * significance and case sensitivity are supported for external identifiers.
     */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) LPspi_pcCurrentChannelIndexPointerRX;
    /**< @brief Number of channels in a pending async job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) LPspi_RemainingChannelsTX;
    /**< @brief Number of channels in a pending async job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) LPspi_RemainingChannelsRX;
    /**< @brief Number of frames in a pending channel, not yet transmitted. */
    VAR(Spi_NumberOfDataType, SPI_VAR) LPspi_RemainingData;
    /**< @brief Number of sent frames, which must be read back in the next ISR call. */
    VAR(Spi_NumberOfDataType, SPI_VAR) LPspi_SentFrames;
    /**< @brief Reference to the current job. */
    P2CONST(Spi_JobConfigType, SPI_VAR, SPI_APPL_CONST) LPspi_pcCurrentJob;
    /**< @brief Indicates if this is the last chunk of data in the job. */
    VAR(boolean, SPI_VAR) LPspi_bIsEndOfJob;
#endif
    /**< @brief Memory mapped registers base address. */
    VAR(uint32, SPI_VAR) LPspi_u32BaseAddress;    
    /**< @brief LPSPI Transmit command register address. */
    VAR(uint32, SPI_VAR) LPspi_u32TCRAddress;
    /**< @brief LPSPI Transmit data register address. */
    VAR(uint32, SPI_VAR) LPspi_u32TDRAddress;    
    /**< @brief LPSPI Receive data register address. */
    VAR(uint32, SPI_VAR) LPspi_u32RDRAddress;    
    /**< @brief LPSPI Status register address. */
    VAR(uint32, SPI_VAR) LPspi_u32SRAddress;
    /**< @brief LPSPI Clock Configuration Register address. */
    VAR(uint32, SPI_VAR) LPspi_u32CCRAddress;
    /**< @brief The frame command value to be used for the transmission. */
    VAR(uint32, SPI_VAR) LPspi_u32CurrentCmd;
    /**< @brief Asynchronous operating mode of the LPSPI unit. */
    VAR(Spi_AsyncModeType, SPI_VAR) LPspi_AsyncMode;
    /**< @brief Pointer to the Autosar HW unit SPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) LPspi_pStatus;
    VAR(Spi_NumberOfDataType, SPI_VAR) LPspi_ReceivedData;
    /**< @brief Flag that indicates a poll request enable*/
    VAR(uint8, SPI_VAR) LPspi_u8IsPollRequest;
    /**< @brief Flag that indicates a poll request TX */
    VAR(uint32, SPI_VAR) LPspi_u32IsPollRequestTX;
    /**< @brief Flag that indicates a poll request RX*/
    VAR(uint32, SPI_VAR) LPspi_u32IsPollRequestRX;
    /**< @brief Flag that indicates the first channel of job*/
    VAR(uint8, SPI_VAR) LPspi_FirstChannelOfJobFlag;
/*
 * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
 * significance and case sensitivity are supported for external identifiers.
 */
}Spi_LPspi_DeviceStateType;

/**
* @brief Internal structure keeping a state of transfer process.
* @details  Internal structure keeping a state of transfer process
*           used by Spi_LPspi_SyncTransmit() & Spi_LPspi_SyncTransmit_fast().
*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
typedef struct
{
    /**< @brief Memory mapped register base address. */
    VAR(uint32, SPI_VAR) LPspi_u32BaseAddress;
     /**< @brief Pointer to the Tx buffer of the channel currently in transmission. */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) LPspi_pBufferTX;
    /**< @brief Pointer to the Rx buffer of the channel currently in transmission. */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) LPspi_pBufferRX;  
    /**< @brief The frame default data value to be used for the channel in transmission. */    
    VAR(Spi_DataBufferType, SPI_VAR) LPspi_DefaultTransmitValue;
     /**< @brief The data width value to be used for the transmission. */
    VAR(uint8, SPI_VAR) LPspi_u8DataWidthTX;
    /**< @brief The data width value to be used for the data receive.*/
    VAR(uint8, SPI_VAR) LPspi_u8DataWidthRX;
    /**< @brief Number of channels in a pending job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) LPspi_ChannelsCountTX;
    /**< @brief Number of channels in a pending job, not yet receive. */
    VAR(Spi_ChannelType, SPI_VAR) LPspi_ChannelsCountRX;
    /**< @brief Number of frames in a pending channel, not yet transmitted. */
    VAR(Spi_NumberOfDataType, SPI_VAR) LPspi_LengthTX;
    /**< @brief Number of frames in a pending channel, not yet receive. */
    VAR(Spi_NumberOfDataType, SPI_VAR) LPspi_LengthRX;
    /**< @brief Position in ChannelIndexList of TX channel*/
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) LPspi_pcChannelIndexListTX;
    /**< @brief Position in ChannelIndexList of RX channel*/
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) LPspi_pcChannelIndexListRX;
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
    /**< @brief Position in table of channel cached attributes. */
    P2VAR(Spi_LPspi_ChannelCacheAttrsType, SPI_VAR, SPI_APPL_DATA) LPspi_pChannelRX;
#endif
    /**< @brief Indicates if this is the last chunk of data in the job. */
    VAR(uint8, SPI_VAR) LPspi_EndOfJobFlag;
    /**< @brief The frame command value to be used for the transmission. */
    VAR(uint32, SPI_VAR) LPspi_u32Cmd;
    /**< @brief The command value for external device. */
    VAR(uint32, SPI_VAR) LPspi_u32JobCmd;
}Spi_LPspi_SyncStateType;
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/*
* @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_LPspi_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/

 #include "Spi_MemMap.h"
 

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief    Pointer table to the cached information structure
* @details  Pointer table to the cached information structure, for one job sequences,
*           or NULL, for unoptimized sequences.
*/
extern P2VAR(Spi_LPspi_SequenceCacheAttrsType, AUTOMATIC, SPI_VAR) Spi_LPspi_apOneJobSeqsOptimized[SPI_MAX_SEQUENCE];
#endif

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief Holds the mode of the Dual Clock.
*/
extern VAR(Spi_DualClockModeType, AUTOMATIC) Spi_LPspi_ClockMode;
#endif
/*
 * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
 * significance and case sensitivity are supported for external identifiers.
 */
#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_LPspi_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))) 
/*
* @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /*
     * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
     * significance and case sensitivity are supported for external identifiers.
     */
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
 
/*
* @violates @ref Spi_LPspi_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Keep the HWUnit internal fields.
*/
/*
* @violates @ref Spi_LPspi_h_REF_5 An external object or function shall be declared in one and
* only one file
*/
extern VAR(Spi_LPspi_DeviceStateType, SPI_VAR) Spi_LPspi_aDeviceState[SPI_MAX_HWUNIT];

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))    
/*
* @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    /*
     * @violates @ref Spi_LPspi_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
     * significance and case sensitivity are supported for external identifiers.
     */
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_LPspi_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_LPspi_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
FUNC(void, SPI_CODE) Spi_LPspi_Init
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus
    );

FUNC(void, SPI_CODE) Spi_LPspi_DeInit
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    );

#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
FUNC(void, SPI_CODE) Spi_LPspi_PrepareCacheInformation(void);
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    );
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmit_Fast
    (
        P2CONST(Spi_LPspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    );
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_LPspi_JobTransfer
    (
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_LPspi_IrqConfig
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_LPspi_IrqPoll
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_LPspi_IsrFifoRx
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev,
        VAR(uint8, AUTOMATIC) u8HWoffset
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_LPspi_IsrDmaTx
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_LPspi_IsrDmaRx
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev
    );
#endif

#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
FUNC(void, SPI_CODE) Spi_LPspi_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_LPspi_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_LPspi_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* SPI_LPSPI_H */

/** @} */

