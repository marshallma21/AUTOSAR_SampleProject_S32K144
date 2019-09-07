[!CODE!][!//
/**
*   @file    Spi_Cfg.h
*   @implements Spi_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi configuration header file.
*   @details This file is the header containing all the necessary information for SPI
*            module configuration(s).
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

#ifndef SPI_CFG_H
#define SPI_CFG_H

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
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, Names of new objects shall be checked in order to
* not cause confusion with standard object names.
*
* @section Spi_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, Precautions shall be taken in order for defines not
* leading to unexpected behaviour when substitution is made.
*
* @section Spi_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
* 4) user callback header files
==================================================================================================*/
[!LOOP "SpiGeneral/SpiUserCallbackHeaderFile/*"!][!//
[!IF "(node:value(.) != '')"!][!//
#include "[!"node:value(.)"!]"
[!ENDIF!][!//
[!ENDLOOP!][!//
[!NOCODE!][!//
[!INCLUDE "Spi_VersionCheck_Inc.m"!][!//
[!INCLUDE "Spi_RegOperations.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SPI_MODULE_ID_CFG                       83
#define SPI_VENDOR_ID_CFG                       43
#define SPI_AR_RELEASE_MAJOR_VERSION_CFG        4
#define SPI_AR_RELEASE_MINOR_VERSION_CFG        2
#define SPI_AR_RELEASE_REVISION_VERSION_CFG     2
#define SPI_SW_MAJOR_VERSION_CFG                1
#define SPI_SW_MINOR_VERSION_CFG                0
#define SPI_SW_PATCH_VERSION_CFG                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

[!NOCODE!][!//
[!//Check repeat of Job, Seq, External device
[!CALL "Spi_CheckRepeatOfJobSeqExternalDevice"!]
[!//Check repeat of SpiPhyTxDmaChannel, SpiPhyTxDmaChannelAux, SpiPhyRxDmaChannel
[!CALL "Spi_CheckRepeatOfDmaChannels"!]
[!ENDNOCODE!][!//
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
[!NOCODE!][!//
[!CALL "Spi_CheckNumberOfSequenceJobChannel"!]
[!ENDNOCODE!][!//
/**
* @brief Switches the Development Error functionality ON or OFF.
* @details Switches the Development Error Detection and Notification ON or OFF.
* @implements SPI_DEV_ERROR_DETECT_define
*/
#define SPI_DEV_ERROR_DETECT           ([!IF "SpiGeneral/SpiDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Switches the Version Information API functionality ON or OFF.
* @details Switches the Spi_GetVersionInfo function ON or OFF.
*/
#define SPI_VERSION_INFO_API           ([!IF "SpiGeneral/SpiVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Switches the Interruptible Sequences handling functionality ON or OFF. 
* @details This parameter depends on SPI_LEVEL_DELIVERED value. 
*        It is only used for SPI_LEVEL_DELIVERED configured to 1 or 2.
* @implements SPI_INTERRUPTIBLE_SEQ_ALLOWED_define
*/
#define SPI_INTERRUPTIBLE_SEQ_ALLOWED  ([!IF "SpiGeneral/SpiInterruptibleSeqAllowed"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Switches the Spi_GetHWUnitStatus function ON or OFF.
* @details Switches the Spi_GetHWUnitStatus function ON or OFF.
* @implements SPI_HW_STATUS_API_define
*/
#define SPI_HW_STATUS_API          ([!IF "SpiGeneral/SpiHwStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Switches the Spi_Cancel function ON or OFF.
* @details Switches the Spi_Cancel function ON or OFF. (see chapter 8.3.13)
* @implements SPI_CANCEL_API_define
*/
#define SPI_CANCEL_API             ([!IF "SpiGeneral/SpiCancelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Only Internal Buffers are allowed in Handler Driver.*/
#define USAGE0                          0x00u

/* Only External Buffers are allowed in Handler Driver.*/
#define USAGE1                          0x01u

/* Both Buffer types are allowd in Handler Driver. */
#define USAGE2                          0x02u

/**
* @brief Selects the SPI Handler Driver Channel Buffers usage allowed and delivered.
* @details Selects the SPI Handler Driver Channel Buffers usage allowed and delivered.
*        (see chapter 7.2.1)
* @implements SPI_CHANNEL_BUFFERS_ALLOWED_define
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED    (USAGE[!"SpiGeneral/SpiChannelBuffersAllowed"!])

/* The LEVEL 0 Simple Synchronous SPI Handler Driver functionalities are selected.*/
#define LEVEL0                          0x00u

/* The LEVEL 1 Basic Asynchronous SPI Handler Driver functionalities are selected.*/
#define LEVEL1                          0x01u

/* The LEVEL 2 Enhanced SPI Handler Driver functionalities are selected. */
#define LEVEL2                          0x02u

/**
* @brief Selects the SPI Handler Driver level of scalable functionality.
* @details Selects the SPI Handler Driver level of scalable functionality that 
* is available and delivered. (see chapter 7.1)
* @implements SPI_LEVEL_DELIVERED_define
*/
#define SPI_LEVEL_DELIVERED            (LEVEL[!"SpiGeneral/SpiLevelDelivered"!])

/**
* @brief Defines the maximum number of supported channels.
* @details Defines the maximum number of supported channels
*     for all the driver configurations.
*/
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!ENDNOCODE!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!CALL "Spi_CheckChannelAttributes"!][!//
[!IF "$Matchcounter = 1"!][!//
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SpiConf_SpiChannel_[!"name(.)"!]    ((Spi_ChannelType)[!"SpiChannelId"!])
[!ENDIF!][!//
[!ENDLOOP!][!//
#define SPI_MAX_CHANNEL  ([!"num:i($SpiMaxChannelsCount)"!]u)

/**
* @brief Total number of Jobs configured.
* @details Defines the maximum number of supported jobs
*     for all the driver configurations.
*/
[!LOOP "SpiDriver/SpiJob/*"!][!//
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SpiConf_SpiJob_[!"name(.)"!]   ((Spi_JobType)[!"SpiJobId"!])
[!ENDLOOP!][!//
#define SPI_MAX_JOB     ([!"num:i($SpiMaxJobsCount)"!]u)

/**
* @brief Total number of Sequences configured.
* @details Defines the maximum number of supported sequences
*     for all the driver configurations.
*/
[!LOOP "SpiDriver/SpiSequence/*"!][!//
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SpiConf_SpiSequence_[!"name(.)"!]   ((Spi_SequenceType)[!"SpiSequenceId"!])
[!ENDLOOP!][!//
#define SPI_MAX_SEQUENCE  ([!"num:i($SpiMaxSequencesCount)"!]u)

[!IF "SpiGeneral/SpiOptimizeOneJobSequences"!][!//
[!//
/**
* @brief Define the size of sequence cached data buffer.
* @details Define the size of sequence cached data buffer for sequences having only one job.
*/
#define SPI_OPTIMIZED_SEQ_BUFFER_SIZE ((Spi_SequenceType)[!//
[!IF "SpiGeneral/SpiOptimizedSeqNumber > 0"!][!//
[!"SpiGeneral/SpiOptimizedSeqNumber"!][!//
[!ELSE!][!//
[!"num:i($SpiMaxOneJobSequences)"!][!//
[!ENDIF!][!//
)
/**
* @brief Define the size of channel cached data buffer.
* @details Define the size of channel cached data buffer 
*    for sequences having only one job.
*/
#define SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE ((Spi_ChannelType)[!//
[!IF "SpiGeneral/SpiOptimizedChannelsNumber > 0"!][!//
[!"SpiGeneral/SpiOptimizedChannelsNumber"!][!//
[!ELSE!][!//
[!"num:i($SpiMaxOneJobSeqChannels)"!][!//
[!ENDIF!][!//
)
[!//
[!ENDIF!][!//

/**
* @brief Defines the peripherals used throughout the configuration(s).
* @details Defines the peripherals used throughout the configuration(s).
*/
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
#define CSIB[!"@index"!]  ((uint8)[!"@index"!]u)
[!ENDLOOP!][!//
#define SPI_MAX_HWUNIT   ([!"num:i(count(SpiGeneral/SpiPhyUnit/*))"!]u)

/**
* @brief Physical HWUnits definition - as from resource manager.
* @details Physical HWUnits definition - as from resource manager.
*/
[!VAR "LPSPI_0_Counter" = "0"!][!//
[!VAR "LPSPI_1_Counter" = "0"!][!//
[!VAR "LPSPI_2_Counter" = "0"!][!//

[!VAR "LPSPI_SLAVE_FLAG" = "0"!][!//
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "SpiPhyUnitMapping = 'LPSPI_0'"!][!//
[!VAR "LPSPI_0_Counter" = "$LPSPI_0_Counter + 1"!][!//
#define LPSPI_0_HWUNIT   (CSIB[!"@index"!])
[!ENDIF!][!//
[!IF "SpiPhyUnitMapping = 'LPSPI_1'"!][!//
[!VAR "LPSPI_1_Counter" = "$LPSPI_1_Counter + 1"!][!//
#define LPSPI_1_HWUNIT   (CSIB[!"@index"!])
[!ENDIF!][!//
[!IF "SpiPhyUnitMapping = 'LPSPI_2'"!][!//
[!VAR "LPSPI_2_Counter" = "$LPSPI_2_Counter + 1"!][!//
#define LPSPI_2_HWUNIT   (CSIB[!"@index"!])
[!ENDIF!][!//

[!IF "SpiPhyUnitMode = 'SPI_SLAVE'"!][!//
[!VAR "LPSPI_SLAVE_FLAG" = "1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

/**
* @brief Physical HWUnits enabled/disabled
* @details Physical HWUnits enabled/disabled
*/
#define LPSPI_0_ENABLED  ([!IF "$LPSPI_0_Counter = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!])
#define LPSPI_1_ENABLED  ([!IF "$LPSPI_1_Counter = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!])
#define LPSPI_2_ENABLED  ([!IF "$LPSPI_2_Counter = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!])

#define SPI_SLAVE_SUPPORT  ([!IF "$LPSPI_SLAVE_FLAG = 1"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!])

[!IF "$LPSPI_0_Counter = 1"!][!//
#define LPSPI_0_OFFSET  0u
[!ENDIF!][!//
[!IF "$LPSPI_1_Counter = 1"!][!//
#define LPSPI_1_OFFSET  1u
[!ENDIF!][!//
[!IF "$LPSPI_2_Counter = 1"!][!//
#define LPSPI_2_OFFSET  2u
[!ENDIF!][!//

#define SPI_FIFO_SIZE   ((uint8)[!"ecu:get('SpiFifoSize')"!]u)

#define SPI_NUMBER_OF_UNITS   ((uint8)[!"ecu:get('SpiNumberOfUnits')"!]u)

/**
* @brief Defines the external devices the driver will use.
* @details Reference to the external device used by this job.
*/
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
/*
* @violates @ref Spi_Cfg_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_[!"name(.)"!]  ((Spi_ExternalDeviceType)[!"@index"!]u)
[!ENDLOOP!][!//

[!NOCODE!]
[!VAR "SpiDemErrorEnable" = "'false'"!]
[!IF "SpiNonAUTOSAR/SpiDisableDemReportErrorStatus ='false'"!][!//
    [!VAR "nconf" = "count(SpiDriver/*)"!]
    [!VAR "iconf" = "0"!]
    [!FOR "iconf" = "1" TO "$nconf"!]
        [!IF "node:exists(SpiDemEventParameterRefs)"!]
            [!VAR "SpiDemErrorEnable" = "'true'"!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDIF!]
[!ENDNOCODE!]
/**
* @brief   Switches the Production Error Detection and Notification OFF
*
* @implements SPI_DISABLE_DEM_REPORT_ERROR_STATUS_define
* 
*/
#define SPI_DISABLE_DEM_REPORT_ERROR_STATUS   [!IF "$SpiDemErrorEnable"!](STD_OFF)  /* Enable Production Error Detection */[!ELSE!](STD_ON) /* Disable Production Error Detection */[!ENDIF!]


/*==================================================================================================
 *                                     DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Define values for Autosar configuration variants.
* @details Define values for Autosar configuration variants.
*/
#define SPI_VARIANT_PRECOMPILE  (0)
#define SPI_VARIANT_POSTBUILD   (1)
#define SPI_VARIANT_LINKTIME    (2)

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
/**
* @brief Defines the use of Pre-Compile(PC) support
* @details VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time" configu-ration are allowed 
*        in this variant.
*/
[!ELSEIF "IMPLEMENTATION_CONFIG_VARIANT='VariantPostBuild'"!][!//
/**
* @brief Defines the use of Post-Build(PB) support.
* @details VARIANT-POST-BUILD: Parameters with "Pre-compile time", 
*        "Link time" and "Post-build time" are allowed in this variant.
*/
[!ELSEIF "IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime'"!][!//
/**
* @brief Defines the use of Link-Time(L) support.
* @details VARIANT-LINK-TIME: Only parameters with "Pre-compile time" 
*        and "Link time" are allowed in this variant.
*/
[!ENDIF!][!//
/**
* @implements SPI_CONFIG_VARIANT_define
*/
#define SPI_CONFIG_VARIANT      [!//
[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
(SPI_VARIANT_PRECOMPILE)
[!ELSEIF "IMPLEMENTATION_CONFIG_VARIANT='VariantPostBuild'"!][!//
(SPI_VARIANT_POSTBUILD)
[!ELSEIF "IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime'"!][!//
(SPI_VARIANT_LINKTIME)
[!ENDIF!][!//

/*
* @violates @ref Spi_Cfg_h_REF_3 Precautions shall be taken in order for
* defines not leading to unexpected behaviour when substitution is made.
*/
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
    [!CALL "Spi_ExportDriverConfiguration"!][!//
[!ENDIF!][!//

/**
* @brief Define precompile support.
* @details Define precompile support if VariantPreCompile or VariantLinkTime is selected and number of variant <=1.
*/
#define SPI_PRECOMPILE_SUPPORT  [!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!][!//

/**
* @brief Defines if transfers are made using DMA or FIFO.
* @details Defines if transfers are made using DMA or FIFO.
* @implements SPI_DMA_USED_define
*/
#define SPI_DMA_USED [!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE' and SpiGeneral/SpiGlobalDmaEnable = 'true'"!][!//
    (STD_ON)
[!ELSE!][!//
    (STD_OFF)
[!ENDIF!][!//

/**
* @brief Defines if Spi driver optimization for sequences having only one job is activated or not.
* @details Defines if Spi driver optimization for sequences having only one job is activated or not.
*        If activated, additional RAM memory is required for internal data caching.
*/
#define SPI_OPTIMIZE_ONE_JOB_SEQUENCES ([!IF "SpiGeneral/SpiOptimizeOneJobSequences"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/**
* @brief Number of CPU clock cycles consumed by a wait loop during the wait for TX/RX transmission to complete one frame in Spi_SyncTransmit().
* @details This value is set to the minimum measure retrieved for GHS, DIAB and CW compilers,
*       with all optimizations activated.
*/
#define SPI_WAIT_LOOP_TICKS       23u

/**
* @brief Defines the "Number of Loops" timeout.
* @details Defines the "Number of Loops" timeout used by Spi_SyncTransmit and Spi_AsyncTransmit
*        function during the wait on TX/RX transmission to complete one frame.
*        One timeout unit means that no TX or RX was executed(the IF statements are returning FALSE).
*/
[!NOCODE!][!//
    [!SELECT "node:ref(SpiGeneral/SpiCPUClockRef)"!]
    [!VAR "CoreFrequency" = "McuClockReferencePointFrequency"!]
    [!ENDSELECT!]
    
[!ENDNOCODE!][!//
#define SPI_TIMEOUT_COUNTER       ((uint32)(([!"num:i(SpiGeneral/SpiTransmitTimeout * $CoreFrequency div 1000000)"!]u) / SPI_WAIT_LOOP_TICKS))

/**
* @brief Allow simultaneous calls to Spi_SyncTransmit() for different threads.
* @details Two concurrent calls to Spi_SyncTransmit() will be allowed only if the related sequences
*       do not share HW units.
*/
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT    ([!IF "SpiGeneral/SpiSupportConcurrentSyncTransmit"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
 *                                           Non AUTOSAR DEFINES
==================================================================================================*/
/**
* @brief If enabled, the asyncronous operation mode (POLLING or INTERRUPT)
* @details If enabled, the asyncronous operation mode (POLLING or INTERRUPT) can
*       be defined independently for each HWUnit using Spi_SetHWUnitAsyncMode().
* @implements SPI_HWUNIT_ASYNC_MODE_define
*/
#define SPI_HWUNIT_ASYNC_MODE [!//
[!IF "(SpiGeneral/SpiLevelDelivered = 2)"!][!//
 ([!IF "SpiNonAUTOSAR/SpiEnableHWUnitAsyncMode"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ELSE!][!//
 (STD_OFF)
[!ENDIF!][!//

[!VAR "DualClockEnabled"= "'false'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!][!//
[!VAR "DualClockEnabled"= "'true'"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
/**
* @brief If enabled, allows dual MCU clock configuration settings.
* @details If enabled, allows dual MCU clock configuration settings.
* @implements SPI_DUAL_CLOCK_MODE_define
*/
#define SPI_DUAL_CLOCK_MODE [!//
[!IF "$DualClockEnabled = 'true'"!][!//
 (STD_ON)
[!ELSE!][!//
 (STD_OFF)
[!ENDIF!][!//

/**
* @brief If enabled, allows to configure more than 256 sequences, jobs and channels.
*/
#define SPI_ALLOW_BIGSIZE_COLLECTIONS [!IF "(node:value(SpiNonAUTOSAR/SpiAllowBigSizeCollections) = 'true')"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief If enabled, SpiDataType is declared as uint8 instead of uint16.
*/
#define SPI_DATA_WIDTH_8  1u
#define SPI_DATA_WIDTH_16 2u
#define SPI_DATA_WIDTH_32 4u

/**
* @brief The below define to use for enable QSPI interface.
*/
[!NOCODE!]
[!VAR "SpiQspiEnable" = "'false'"!]
[!LOOP "SpiChannel/*"!]
    [!IF "(SpiTransferWidth >= 2)"!][!//
        [!VAR "SpiQspiEnable" = "'true'"!][!//
    [!ENDIF!]
[!ENDLOOP!][!//  
[!ENDNOCODE!][!//

#define SPI_QSPI_COMMUNICATION_ENABLE   [!IF "$SpiQspiEnable"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/**
* @brief The below define to use for configure the number of bits can transfer per clock.
*/
/* Normal transfer */
#define SPI_TRANSFER_WIDTH_1    0u
/* QSPI transfer */
#define SPI_TRANSFER_WIDTH_2    1u
#define SPI_TRANSFER_WIDTH_4    2u

#define SPI_FORCE_DATA_TYPE (STD_ON)


/**
* @brief If enabled, SPI_MAIN_FUNCTION_PERIOD defines the cycle time of the function Spi_MainFunction_Handling in seconds
*/
[!IF " node:exists(SpiGeneral/SpiMainFunctionPeriod)"!][!//
#define SPI_MAIN_FUNCTION_PERIOD            ([!"num:f(SpiGeneral/SpiMainFunctionPeriod)"!])
[!ENDIF!][!//


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
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

#endif /*SPI_CFG_H*/

/** @} */
[!ENDCODE!][!//
