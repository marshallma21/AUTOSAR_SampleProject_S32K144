/**
*   @file    Fls_Qspi_Types.h   
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of Flash IP exported types.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
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

#ifndef FLS_QSPI_TYPES_H
#define FLS_QSPI_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and 
* case sensitivity are supported for external identifiers.
* The used compilers use more than 31 chars for identifiers.
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
#define FLS_QSPI_TYPES_VENDOR_ID                    43
#define FLS_QSPI_TYPES_MODULE_ID                    92
#define FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION     2
#define FLS_QSPI_TYPES_AR_RELEASE_REVISION_VERSION  2
#define FLS_QSPI_TYPES_SW_MAJOR_VERSION             1
#define FLS_QSPI_TYPES_SW_MINOR_VERSION             0
#define FLS_QSPI_TYPES_SW_PATCH_VERSION             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief QSPI hardware unit name.
*/ 
typedef enum                                                                
{
    FLS_QSPI_0 = 0,
    FLS_QSPI_1
} Fls_QspiUnitNameType;

/**
* @brief Sampling type(SDR/DDR).
*/
typedef enum
{
    FLS_SDR = 0,
    FLS_DDR
} Fls_QspiUnitReadModeType;


/**
* @brief Clock sampling edge.
*/
typedef enum
{
    FLS_RISING = 0,
    FLS_FALLING
} Fls_QspiUnitSamplingEdgeType;

/**
* @brief Clock sampling delay.
*/
typedef enum
{
    FLS_1SAMPLE_DLY = 0,
    FLS_2SAMPLE_DLY
} Fls_QspiUnitSamplingDlyType;

/**
* @brief Serial flash data in hold time.
*/
typedef enum
{
    FLS_ALIGNED_INT_REF_CLK = 0,
    FLS_ALIGNED_2X_CLK      = 1,
    FLS_ALIGNED_4X_CLK      = 2
} Fls_QspiUnitTdhType;

/**
* @brief Endianness configuration.
*/
typedef enum
{
    FLS_BIG_ENDIAN_64       = 0,
    FLS_LITTLE_ENDIAN_32    = 1,
    FLS_BIG_ENDIAN_32       = 2,
    FLS_LITTLE_ENDIAN_64    = 3
} Fls_QspiUnitEndianType;

/**
* @brief Access mode for read jobs, determining the bus interface and the buffer used.
*/
typedef enum
{
    FLS_AHB_READ_MODE = 0,
    FLS_IP_READ_MODE
} Fls_QspiUnitReadBufferModeType;

/**
* @brief Access mode of the RX Buffer, used in read jobs, in IP accessing mode.
*/
typedef enum
{
    FLS_RXBUFFER_AHB_BUS_ACCESS = 0,
    FLS_RXBUFFER_IP_BUS_ACCESS
} Fls_QspiUnitRxBufferAccessModeType;

/**
* @brief Number of external pads used, used as an operand for a LUT instruction.
*/
typedef enum
{
    FLS_LUT_PAD_1_PAD  = 0,
    FLS_LUT_PAD_2_PADS = 1,
    FLS_LUT_PAD_4_PADS = 2,
    FLS_LUT_PAD_8_PADS = 3
} Fls_QspiUnitLutPadsType;

/**
    @brief QSPI sector channel type.
*/
typedef enum
{
    FLS_CH_EXTERN_QSPI_0_A1 = 0,
    FLS_CH_EXTERN_QSPI_0_A2,
    FLS_CH_EXTERN_QSPI_0_B1,
    FLS_CH_EXTERN_QSPI_0_B2,
    FLS_CH_EXTERN_QSPI_0_PARALLEL_A1B1,
    FLS_CH_EXTERN_QSPI_0_PARALLEL_A2B2,
    FLS_CH_EXTERN_QSPI_1_A1,
    FLS_CH_EXTERN_QSPI_1_A2,
    FLS_CH_EXTERN_QSPI_1_B1,
    FLS_CH_EXTERN_QSPI_1_B2,
    FLS_CH_EXTERN_QSPI_1_PARALLEL_A1B1,
    FLS_CH_EXTERN_QSPI_1_PARALLEL_A2B2,
    NOT_QSPI_CHANNEL
} Fls_QspiSectorChType;

/**
* @brief QSPI channel type.
*/
typedef enum
{
    FLS_QSPI_CH_INDIVIDUAL = 0,
    FLS_QSPI_CH_PARALLEL 
} Fls_QspiSectorChParallelType;

/**
* @brief Instruction-Operand type. 
*/
typedef uint16 Fls_InstructionOperandType;

/**
* @brief Structure describing a LUT element.
*/
typedef struct
{
    /** @brief  Number of instruction-operand pairs inside a LUT sequence. */
    CONST(uint8, FLS_CONST) u8InstrOperCount;
    /** @brief  Instruction-operand pairs. */
    CONST(Fls_InstructionOperandType, FLS_CONST) (*paInstrOper)[];
}Fls_QspiLUTType;

/**
* @brief AHB buffer instance name.
*/
typedef enum
{
    AHB_BUFFER_0 = 0,
    AHB_BUFFER_1 = 1,
    AHB_BUFFER_2 = 2,
    AHB_BUFFER_3 = 3
} Fls_AhbBufferType;

/**
* @brief Master ID used for AHB buffer access routing and prefetch triggering.  
*/


typedef enum
{
    FLS_CORTEX_M4_CODE      = 0,
    FLS_CORTEX_M4_SYS       = 1,
    FLS_DMA                 = 2,
    FLS_ENET                = 3    
} Fls_AhbBufferMasterIdType;

typedef enum
{
    FLS_QSPI_SYS_CLK = 0,
    FLS_QSPI_BUS_CLK = 1
} Fls_eQspiUnitInputClockSelType;

typedef enum
{
    FLS_QSPI_SPLLDIV1 = 0,
    FLS_QSPI_FIRCDIV1 = 1
} Fls_eQspiUnitInternalRefClockSelType;

typedef enum
{
    FLS_QSPI_DQS_INVERTED = 0,
    FLS_QSPI_DQS_NONINVERTED = 1
} Fls_eQspiUnitDqsStage2ClkSourceType;

typedef enum
{
    FLS_QSPI_DQS_INTERNAL = 0,
    FLS_QSPI_DQS_LOOPBACK = 1
} Fls_eQspiUnitDqsStage1ClkSourceType;

/**
* @brief Programmable Divider.
*/
typedef enum
{
    FLS_PGM_DIV_1  = 0,
    FLS_PGM_DIV_2  = 1,
    FLS_PGM_DIV_3  = 2,
    FLS_PGM_DIV_4  = 3,
    FLS_PGM_DIV_5  = 4,
    FLS_PGM_DIV_6  = 5,
    FLS_PGM_DIV_7  = 6,
    FLS_PGM_DIV_8  = 7
} Fls_QspiUnitProgrammableDividerType;


/**
* @brief Configuration structure for QSPI HW unit related parameters.
*/
typedef struct
{
    /** @brief  Name of the QSPI hardware unit for which these configuration parameters apply. */
    CONST(Fls_QspiUnitNameType, FLS_CONST) eHwUnitName;
    /** @brief  Sampling type(SDR/DDR). */
    CONST(Fls_QspiUnitReadModeType, FLS_CONST) eQspiUnitReadMode;
/* Kinetis implementation specific types. */
    /** @brief  DQS mode. */
    CONST(boolean, FLS_CONST) bQspiUnitDqsMode;
    /** @brief  Input pads buffers. */
    CONST(boolean, FLS_CONST) bQspiUnitInputPadsBufferEn;    
    /** @brief  Module clock source. */
    CONST(Fls_eQspiUnitInputClockSelType, FLS_CONST) eQspiUnitInputClockSel;
    /** @brief  Internal reference clock. */
    CONST(Fls_eQspiUnitInternalRefClockSelType, FLS_CONST) eQspiUnitInternalRefClockSel;
    /** @brief  Reference clock source for DQS for Flash-B Stage 2. */
    CONST(Fls_eQspiUnitDqsStage2ClkSourceType, FLS_CONST) eQspiUnitDqsBStage2ClkSource;
    /** @brief  Reference clock source for DQS for Flash-B Stage 1. */
    CONST(Fls_eQspiUnitDqsStage1ClkSourceType, FLS_CONST) eQspiUnitDqsBStage1ClkSource;
    /** @brief  Reference clock source for DQS for Flash-A Stage 2. */
    CONST(Fls_eQspiUnitDqsStage2ClkSourceType, FLS_CONST) eQspiUnitDqsAStage2ClkSource;
    /** @brief  Reference clock source for DQS for Flash-A Stage 1. */
    CONST(Fls_eQspiUnitDqsStage1ClkSourceType, FLS_CONST) eQspiUnitDqsAStage1ClkSource;   
    /** @brief  Pending Read Bus Gasket. */
    CONST(boolean, FLS_CONST) bQspiUnitPendingReadBusGasket;   
    /** @brief  Burst Read Bus Gasket. */
    CONST(boolean, FLS_CONST) bQspiUnitBurstReadBusGasket;   
    /** @brief  Burst Write Bus Gasket. */
    CONST(boolean, FLS_CONST) bQspiUnitBurstWriteBusGasket; 
    /** @brief  Programmable Divider. */
    CONST(Fls_QspiUnitProgrammableDividerType, FLS_CONST) eQspiUnitProgrammableDivider;
    /** @brief  Idle Signal Drive IOFB[3] Flash B. */
    CONST(boolean, FLS_CONST) bQspiUnitIOFB3HighLvl; 
    /** @brief  Idle Signal Drive IOFB[2] Flash B. */
    CONST(boolean, FLS_CONST) bQspiUnitIOFB2HighLvl; 
    /** @brief  Idle Signal Drive IOFA[3] Flash A. */
    CONST(boolean, FLS_CONST) bQspiUnitIOFA3HighLvl; 
    /** @brief  Idle Signal Drive IOFA[2] Flash A. */
    CONST(boolean, FLS_CONST) bQspiUnitIOFA2HighLvl; 
    /** @brief  Clock sampling edge. */
    CONST(Fls_QspiUnitSamplingEdgeType, FLS_CONST) eQspiUnitSamplingEdge;
    /** @brief  Clock sampling delay. */
    CONST(Fls_QspiUnitSamplingDlyType, FLS_CONST) eQspiUnitSamplingDly;
    /** @brief  Clock sampling point(used in DDR INTERNAL_4X mode). */
    CONST(uint8, FLS_CONST) u8QspiUnitSamplingPoint;
    /** @brief  Latency cycles enable. */
    CONST(boolean, FLS_CONST) bQspiUnitDqsLatencyEn;
    /** @brief  Fine delay for QSPI_A port memories. */
    CONST(uint8, FLS_CONST) u8QspiUnitFineDlyA;
    /** @brief  Fine delay for QSPI_B port memorie. */
    CONST(uint8, FLS_CONST) u8QspiUnitFineDlyB;
    /** @brief  Serial flash data in hold time. */
    CONST(Fls_QspiUnitTdhType, FLS_CONST) eQspiUnitTdh;
    /** @brief  Serial flash CS setup time in clock cycles. */
    CONST(uint8, FLS_CONST) u8QspiUnitTcsh;
    /** @brief  Serial flash CS setup time in clock cycles. */
    CONST(uint8, FLS_CONST) u8QspiUnitTcss;
    /** @brief  Byte endianness. */
    CONST(Fls_QspiUnitEndianType, FLS_CONST) eQspiUnitEndian;
    /** @brief  Access mode for read jobs(IP/AHB). */
    CONST(Fls_QspiUnitReadBufferModeType, FLS_CONST) eQspiUnitReadBufferMode;
    /** @brief  Access mode of the RX Buffer(used in IP mode, RX_IP bus/RX_AHB bus). */
    CONST(Fls_QspiUnitRxBufferAccessModeType, FLS_CONST) eQspiUnitRxBufferAccessMode;
    /** @brief  AHB buffers instances. */
    CONST(Fls_AhbBufferType, FLS_CONST) (*paQspiUnitAhbBuffer)[];
    /** @brief  AHB buffers masters ID. */
    CONST(Fls_AhbBufferMasterIdType, FLS_CONST) (*paQspiUnitAhbBufferMasterId)[];
    /** @brief  AHB buffers size. */
    CONST(uint32, FLS_CONST) (*paQspiUnitAhbBufferSize)[];
    /** @brief  AHB buffers data prefetch size. */
    CONST(uint32, FLS_CONST) (*paQspiUnitAhbBufferDataTransferSize)[];
    /** @brief  All master enable bit for AHB_BUFFER_3. */
    CONST(boolean, FLS_CONST) bHwUnitAhbBufferAllMasters;
    /** @brief  Master High Priority enable bit for AHB_BUFFER_0. */
    CONST(boolean, FLS_CONST) bHwUnitAhbBufferHighPriority;
    /** @brief  Number of configured AHB buffers. */
    CONST(uint8, FLS_CONST) u8QspiUnitAhbBufferCount;
    /** @brief  Serial address mapping of external memories into internal memory map. */
    CONST(uint32, FLS_CONST) (*paQspiUnitSerialAddrMapping)[];
    /** @brief  Column address bit width. */
    CONST(uint8, FLS_CONST) u8QspiUnitColumnAddressWidth;
    /** @brief  Word addressable memories. */
    CONST(boolean, FLS_CONST) bQspiUnitWordAddressable;
    /** @brief  External memory register width. */
    CONST(uint8, FLS_CONST) u8QspiUnitRegisterWidth;
    /** @brief  Value of the BUSY/IDLE bit signifying a busy state of the memory(0/1). */
    CONST(uint8, FLS_CONST) u8QspiUnitBusyBitValue;
    /** @brief  BUSY/IDLE bit position offset inside the status register. */
    CONST(uint8, FLS_CONST) u8QspiUnitBusyBitPosOffset;
    /** @brief  Device ID configured value(Manufacturer ID | Device ID). */
    CONST(uint16, FLS_CONST) u16QspiDeviceId;
    /** @brief  Hyperflash latency cycles. */
    CONST(uint8, FLS_CONST) u8QspiHyperflashLatCycls;
    /** @brief  LUT sequences of instruction/operand pairs. */
    CONST(Fls_QspiLUTType, FLS_CONST) (*paQspiUnitLUT)[];
    /** @brief  Number of configured LUT sequences. */
    CONST(uint8, FLS_CONST) u8QspiLUTSeqsCount;
    /** @brief  LUT sequence ID used for get status jobs. */
    CONST(uint8, FLS_CONST) u8QspiLUTGetStatusSeq;
    /** @brief  LUT sequence ID used for read jobs. */
    CONST(uint8, FLS_CONST) u8QspiLUTReadSeq;
    /** @brief  LUT sequence ID used for write enable jobs. */
    CONST(uint8, FLS_CONST) u8QspiLUTWriteEnSeq;
    /** @brief  LUT sequence ID used for write jobs. */
    CONST(uint8, FLS_CONST) u8QspiLUTWriteSeq;
    /** @brief  LUT sequence ID used for erase jobs. */
    CONST(uint8, FLS_CONST) u8QspiLUTEraseSeq;
    /** @brief  LUT sequence ID used for read ID jobs. */
    CONST(uint8, FLS_CONST) u8QspiLUTReadIdSeq;    
} Fls_QspiUnitCfgType;


/**
* @brief          Fls Qspi Init Callout Pointer Type
* @details        Pointer type of FlsQspiInitCallout function
*
*/
typedef P2FUNC(void, FLS_CODE, FlsQspiInitCalloutPtrType)(void);

/**
* @brief          Fls Qspi Reset Callout Pointer Type
* @details        Pointer type of FlsQspiResetCallout function
*
*/
typedef P2FUNC(void, FLS_CODE, FlsQspiResetCalloutPtrType)(void);

/**
* @brief          Fls Qspi Error Check Callout Pointer Type
* @details        Pointer type of FlsQspiErrorCheckCallout function
*
*/
typedef P2FUNC(Std_ReturnType, FLS_CODE, FlsQspiErrorCheckCalloutPtrType)
        (
            VAR(Fls_QspiSectorChType, AUTOMATIC) eQspiSectorChannel
        );

/**
* @brief          Fls Qspi Ecc Check Callout Pointer Type
* @details        Pointer type of FlsQspiEccCheckCallout function
*
*/        
typedef P2FUNC(Std_ReturnType, FLS_CODE, FlsQspiEccCheckCalloutPtrType)
        (
            VAR(Fls_QspiSectorChType, AUTOMATIC) eQspiSectorChannel,
            VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
            VAR(Fls_LengthType, AUTOMATIC)  u32DataLength
        );
/**
* @brief General configuration structure for QSPI related parameters.
*/
typedef struct
{
    /** @brief pointer to init callout */
    FlsQspiInitCalloutPtrType pfInitCallout; 
    /** @brief pointer to reset callout */
    FlsQspiResetCalloutPtrType pfResetCallout; 
    /** @brief pointer to error check callout */
    FlsQspiErrorCheckCalloutPtrType pfErrorCheckCallout;    
    /** @brief pointer to Ecc check callout */
    FlsQspiEccCheckCalloutPtrType pfEccCheckCallout;
    /** @brief QSPI sector channel type(assigned external port, chip select). */
    CONST( Fls_QspiSectorChType, FLS_CONST) (*paQspiSectCh)[]; 
    /** @brief QSPI sector channel type(individual/parallel). */
    CONST( Fls_QspiSectorChParallelType, FLS_CONST) (*paQspiSectChParallel)[]; 
    /** @brief QSPI sector assign to a specific hardware unit instance(QSPI0/QSPI1). */
    CONST( Fls_QspiUnitNameType, FLS_CONST) (*paQspiUnitSectorAssign)[]; 
    /** @brief QSPI configuration for each configured hardware unit instances(QSPI0/QSPI1). */
    CONST( Fls_QspiUnitCfgType, FLS_CONST) (*paQspiUnitCfg)[];
    /** @brief Number for configured QSPI hardware instances. */
    CONST( uint8, FLS_CONST) u8QspiUnitsCount;    
}Fls_QspiCfgConfigType;


#ifdef __cplusplus
}
#endif

#endif /* FLS_QSPI_TYPES_H */

/** @}*/
