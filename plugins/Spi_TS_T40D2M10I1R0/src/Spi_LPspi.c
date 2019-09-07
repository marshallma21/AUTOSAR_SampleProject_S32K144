/**
*   @file    Spi_LPspi.c
*   @implements Spi_LPspi.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - LPSPI low-level driver implementations.
*   @details LPSPI low-level driver implementations.
*
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, Names of new objects shall be checked in order to
* not cause confusion with standard object names.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_LPspi_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_LPspi_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_LPspi_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type.
*
* @section Spi_LPspi_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.4,
* A cast should not be performed between a pointer to object type and a different pointer to object type.
* Casts between (uint8*) and (uint32*) are used for optimizing the memory accesses.
*
* @section Spi_LPspi_c_REF_5
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
* Structure shall be public as it is used by Reg_eSys_LPSPI.h which may be sed outside LPSPI module.
*
* @section Spi_LPspi_c_REF_6
* Violates MISRA 2004 Required Rule 17.4,
* Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
* @section Spi_LPspi_c_REF_8
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_LPspi_c_REF_11
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
* The variables are defined globally for performance reasons.
*
* @section Spi_LPspi_c_REF_12
* Violates MISRA 2004 Advisory Rule 11.3,
* A cast should not be performed between a pointer type and an integral type.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Spi.h"
#include "Spi_LPspi.h"
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/*
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Dem.h"
#endif

#include "Reg_eSys_LPspi.h"
#if (SPI_DMA_USED == STD_ON)
#include "CDD_Mcl.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_LPSPI_C                    43
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C         4
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C         2
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_LPSPI_C      2
#define SPI_SW_MAJOR_VERSION_LPSPI_C                 1
#define SPI_SW_MINOR_VERSION_LPSPI_C                 0
#define SPI_SW_PATCH_VERSION_LPSPI_C                 1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_LPSPI_C != SPI_VENDOR_ID)
    #error "Spi.h and Spi_LPspi.c have different vendor ids"
#endif
/* Check if Spi_LPspi.c file and Spi.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_LPSPI_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_LPspi.c and Spi.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION_LPSPI_C  != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_LPSPI_C  != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_LPSPI_C  != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_LPspi.c and Spi.h are different"
#endif

/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_VENDOR_ID_LPSPI_C != SPI_VENDOR_ID_LPSPI)
    #error "Spi_LPspi.c and Spi_LPspi.h have different vendor ids"
#endif
/* Check if Spi_LPspi.c file and Spi_LPspi.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C    != SPI_AR_RELEASE_MAJOR_VERSION_LPSPI) || \
     (SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C    != SPI_AR_RELEASE_MINOR_VERSION_LPSPI) || \
     (SPI_AR_RELEASE_REVISION_VERSION_LPSPI_C != SPI_AR_RELEASE_REVISION_VERSION_LPSPI))
#error "AutoSar Version Numbers of Spi_LPspi.c and Spi_LPspi.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION_LPSPI_C  != SPI_SW_MAJOR_VERSION_LPSPI) || \
     (SPI_SW_MINOR_VERSION_LPSPI_C  != SPI_SW_MINOR_VERSION_LPSPI) || \
     (SPI_SW_PATCH_VERSION_LPSPI_C  != SPI_SW_PATCH_VERSION_LPSPI))
#error "Software Version Numbers of Spi_LPspi.c and Spi_LPspi.h are different"
#endif

/* Check if this header file and Reg_eSys_LPSPI.h are of the same vendor */
#if (SPI_VENDOR_ID_LPSPI_C != SPI_VENDOR_ID_REGFLEX)
    #error "Spi_LPspi.c and Reg_eSys_LPSPI.h have different vendor ids"
#endif
/* Check if Spi_LPspi.c file and Reg_eSys_LPSPI.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C    != SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C    != SPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_REVISION_VERSION_LPSPI_C != SPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
#error "AutoSar Version Numbers of Spi_LPspi.c and Reg_eSys_LPSPI.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION_LPSPI_C  != SPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_SW_MINOR_VERSION_LPSPI_C  != SPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_SW_PATCH_VERSION_LPSPI_C  != SPI_SW_PATCH_VERSION_REGFLEX))
#error "Software Version Numbers of Spi_LPspi.c and Reg_eSys_LPSPI.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_LPspi.c and Mcal.h are different"
    #endif

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C  != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_LPspi.c and Dem.h are different"
    #endif
#endif

#if (SPI_DMA_USED == STD_ON)
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_LPSPI_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_AR_RELEASE_MINOR_VERSION_LPSPI_C  != MCL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_LPspi.c and CDD_Mcl.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define LPSPI_DMA_MAX_LINKED_ITER_CNT  (0x1FFu)

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#define LPSPI_SYNCTRANSMIT 0u
#define LPSPI_SYNCTRANSMIT_FAST 1u
#endif
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/**
* @brief Pool of cached information for sequences having only one job.
*/
/*
* @violates @ref Spi_LPspi_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Spi_LPspi_SequenceCacheAttrsType, SPI_VAR) Spi_LPspi_aSeqsAttributes[SPI_OPTIMIZED_SEQ_BUFFER_SIZE];

/**
* @brief Pool of cached information for sequences having only one job.
*/
/*
* @violates @ref Spi_LPspi_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Spi_LPspi_ChannelCacheAttrsType, SPI_VAR) Spi_LPspi_aChannelsAttributes[SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE];
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))

/**
* @brief DMA TCD descriptor global variable (used to avoid MISRA 1.2 rule error).
*/
/*
* @violates @ref Spi_LPspi_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Mcl_DmaTcdAttributesType, SPI_VAR) Spi_LPspi_DmaCfgDesc;

#endif  /* SPI_DMA_USED == STD_ON */

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/*
* @violates @ref Spi_LPspi_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Spi_LPspi_SyncStateType, SPI_VAR) Spi_LPspi_SyncTransmitState[SPI_MAX_HWUNIT];
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief LPSPI base address array.
*/
/*
* @violates @ref Spi_LPspi_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
CONST(uint32, SPI_CONST) Spi_LPspi_au32BaseAddrs[13] =
{
    #ifdef  LPSPI0_BASEADDR
        LPSPI0_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI1_BASEADDR
        LPSPI1_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI2_BASEADDR
        LPSPI2_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI3_BASEADDR
        LPSPI3_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI4_BASEADDR
        LPSPI4_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI5_BASEADDR
        LPSPI5_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI6_BASEADDR
        LPSPI6_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI7_BASEADDR
        LPSPI7_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI8_BASEADDR
        LPSPI8_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI9_BASEADDR
        LPSPI9_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI10_BASEADDR
        LPSPI10_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI11_BASEADDR
        LPSPI11_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  LPSPI12_BASEADDR
        LPSPI12_BASEADDR
    #else
        ((uint32)0x00000000UL)
    #endif

};

#define SPI_STOP_SEC_CONST_32
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/

#define SPI_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*
* @violates @ref Spi_LPspi_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(volatile uint32, SPI_VAR) Spi_LPspi_u32ReadDiscard;

#define SPI_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief       Holds the mode of the Dual Clock.
* @details       This structure is used to store runtime internal state parameters
*              for the LPSPI IP peripheral.
*
*/
VAR(Spi_DualClockModeType, SPI_VAR) Spi_LPspi_ClockMode = SPI_NORMAL;
#endif

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief         Pointer table to the cached information structure, for one job
*             sequences, or NULL, for unoptimized sequences.
* @details    Internal structure keeping a set of cached sequences attributes
*               used by the optimized implementation of Spi_SyncTransmit() for the
*              sequences having only one job.
*
*/
/*
* @violates @ref Spi_LPspi_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
P2VAR(Spi_LPspi_SequenceCacheAttrsType, SPI_VAR, SPI_APPL_DATA) Spi_LPspi_apOneJobSeqsOptimized[SPI_MAX_SEQUENCE] = {NULL_PTR};
#endif

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))) 
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
 
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Keep the HWUnit internal fields.
*
*/
/*
* @violates @ref Spi_LPspi_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_LPspi_DeviceStateType, SPI_VAR) Spi_LPspi_aDeviceState[SPI_MAX_HWUNIT];

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))    
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_InitDma \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_DmaIrqConfig \
    ( \
        P2CONST(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) LPspi_pDev, \
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode \
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferFifoInitTX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferFifoInitRX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferFifoDrain \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferFifoFill \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferDmaInitTX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferDmaInitRX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferDmaContinueTX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferDmaContinueRX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_WriteTxFifo \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(uint8, AUTOMATIC) LPspi_u8EndOfJob \
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_TransferStatus
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev,
        VAR(uint32, AUTOMATIC) LPspi_u32IsrStatusTX,
        VAR(uint32, AUTOMATIC) LPspi_u32IsrStatusRX
    );
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmitTX
    (
        P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState
    );
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmitRX
    (
        P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState,
        VAR(uint8, AUTOMATIC) LPspi_u8Sync
    );
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmitJob
    (
        P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState
    );
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Initialize the specific Spi unit with all configuration
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          Also this function initializes all structure parameters
*          from the specific LPSPI unit.
*
* @param[in]      HWUnit      Specifies which LPSPI peripheral is used
* @param[in]      AsyncMode   operation mode
*                             (SPI_INTERRUPT_MODE | SPI_POLLING_MODE)
* @param[in]      pStatus     pointer to the Autosar SPI HWUnit State
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_LPspi_Init
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus
    )
{
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcDeviceAttributesConfig;
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev;
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
    VAR(uint32, AUTOMATIC) LPspi_u32Job;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcJobConfig;
    VAR(uint32, AUTOMATIC) LPspi_u32CFGR1;
    VAR(uint8, AUTOMATIC) LPspi_u8HWoffset;

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /* Clock mode */
    Spi_LPspi_ClockMode = SPI_NORMAL;
#endif

    /* Get physical device instances and link them */
    LPspi_pDev = &Spi_LPspi_aDeviceState[HWUnit];
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */    
    LPspi_pcHWUnitConfig = &Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit];
    LPspi_pDev->LPspi_pcHWUnitConfig = LPspi_pcHWUnitConfig;
    LPspi_pDev->LPspi_pStatus = pStatus;
    /* Reset poll flag */
    LPspi_pDev->LPspi_u8IsPollRequest = 0u;

    /* Peripheral Registers */
    LPspi_u8HWoffset = LPspi_pcHWUnitConfig->u8Offset;
    
    /* cache frequently used LPSPI addresses in order to have a quicker access */
    LPspi_pDev->LPspi_u32BaseAddress = LPSPI_GET_BASE_ADDRESS_U32(LPspi_u8HWoffset);

    LPspi_pDev->LPspi_u32TCRAddress = LPSPI_TCR_ADDR32(LPspi_u8HWoffset);

    LPspi_pDev->LPspi_u32TDRAddress = LPSPI_TDR_ADDR32(LPspi_u8HWoffset);

    LPspi_pDev->LPspi_u32RDRAddress = LPSPI_RDR_ADDR32(LPspi_u8HWoffset);

    LPspi_pDev->LPspi_u32SRAddress  = LPSPI_SR_ADDR32(LPspi_u8HWoffset);
    
    LPspi_pDev->LPspi_u32CCRAddress = LPSPI_CCR_ADDR32(LPspi_u8HWoffset);
    /* Determine chip select inactive states for each PCS */
    LPspi_u32CFGR1 = (LPSPI_CFGR1_PCSxPOL_IDLEHIGH_U32);   /* high by default */

    for (LPspi_u32Job = 0u; LPspi_u32Job <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Job); LPspi_u32Job++)
    {
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */        
        LPspi_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[LPspi_u32Job];
        if (LPspi_pcJobConfig->HWUnit == HWUnit)
        {
            /* External device attributes */
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            LPspi_pcDeviceAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig[LPspi_pcJobConfig->ExternalDevice];
            LPspi_u32CFGR1 = (uint32)(LPspi_u32CFGR1 | (LPspi_pcDeviceAttributesConfig->u32CFGR1));
        }
        else
        {
            /* Do nothing */
        }
    }

    /* SPI works as a Master and CS configured with inactive
    state as appropriate */
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_CFGR1_ADDR32(LPspi_u8HWoffset), (LPspi_u32CFGR1 & LPSPI_CFGR1_RESERVED_MASK_U32));

#if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) )
#if (SPI_DMA_USED == STD_ON)
    if (LPspi_pcHWUnitConfig->u16UseDma)
    {
        /* Enable Transmit and Receive Data Enable */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(LPSPI_DER_ADDR32(LPspi_u8HWoffset), (uint32)(LPSPI_DER_RDDE_MASK_U32 | LPSPI_DER_TDDE_MASK_U32));
        /* initialize DMA TCDs */
        Spi_LPspi_InitDma(LPspi_pDev);
    }
    else
    {
        /* Do nothing */
    }
#endif /* (SPI_DMA_USED == STD_ON) */
#endif

    /* Enable SPI channel and will work normally in Debug mode */
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_CR_ADDR32(LPspi_u8HWoffset), (LPSPI_CR_MEN_EN_U32 | LPSPI_CR_DBGEN_EN_U32) & LPSPI_CR_RESERVED_MASK_U32);
}

/*================================================================================================*/
/**
* @brief   IRQ configure functions.
* @details Activate/deactivate TDF, RDF interrupts for async HWUnit according to
*          the driver operation mode (polling or interrupt).
*
* @param[in]     HWUnit      Specifies which LPSPI peripheral is used
* @param[in]     AsyncMode   Specifies the operation mode
*                             (SPI_INTERRUPT_MODE | SPI_POLLING_MODE)
*
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*================================================================================================*/
/*
* @violates @ref Spi_LPspi_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_LPspi_IrqConfig
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    )
{
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev = &Spi_LPspi_aDeviceState[HWUnit];
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
    VAR(uint8, AUTOMATIC) LPspi_u8HWoffset = LPspi_pcHWUnitConfig->u8Offset;

    /* set the async mode for the HWUnit */
    LPspi_pDev->LPspi_AsyncMode = AsyncMode;

    /* activate/deactivate TDF, RDF interrupts for Async HWUnits */
    if (SPI_PHYUNIT_ASYNC_U32 == LPspi_pcHWUnitConfig->u32IsSync)
    {
#if (SPI_DMA_USED == STD_ON)
        if (LPspi_pcHWUnitConfig->u16UseDma)
        {
            Spi_LPspi_DmaIrqConfig(LPspi_pDev, AsyncMode);
        }
        else
        {
            /* Do nothing */
        }
#endif /* SPI_DMA_USED == STD_ON */

        if (SPI_INTERRUPT_MODE == AsyncMode)
        {
        #if (SPI_DMA_USED == STD_ON)
            if (LPspi_pcHWUnitConfig->u16UseDma)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_CLEAR32(LPSPI_IER_ADDR32(LPspi_u8HWoffset), LPSPI_IER_RDIE_MASK_U32);
            } 
            else
            {
        #endif
            #if (SPI_SLAVE_SUPPORT == STD_ON)
                if (SPI_SLAVE == (Spi_ModeType)LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_BIT_CLEAR32(LPSPI_IER_ADDR32(LPspi_u8HWoffset), LPSPI_IER_RDIE_MASK_U32);
                }
                else
                {
            #endif
                     /*
                     * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                     *     type and an integral type.
                     */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */                     
                    REG_BIT_SET32(LPSPI_IER_ADDR32(LPspi_u8HWoffset), LPSPI_IER_RDIE_MASK_U32);
            #if (SPI_SLAVE_SUPPORT == STD_ON)
                }
            #endif
       #if (SPI_DMA_USED == STD_ON)
            }
       #endif
        }
        else
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_CLEAR32(LPSPI_IER_ADDR32(LPspi_u8HWoffset), LPSPI_IER_RDIE_MASK_U32);
        }
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_BIT_CLEAR32(LPSPI_IER_ADDR32(LPspi_u8HWoffset), LPSPI_IER_TDIE_MASK_U32);
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/*================================================================================================*/
/**
* @brief   IRQ polling functions.
* @details Configures DMA unit to detect received data via
*          interrupt or by polling a bit in the IER register.
*
* @param[in]     HWUnit     Specifies which LPSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_LPspi_IrqPoll
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    )
{
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev;
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
#endif
    VAR(uint32, AUTOMATIC) LPspi_u32IsrStatus = 0u;

    LPspi_pDev = LPSPI_HWUNIT2LPSPI(HWUnit);

    if ((SPI_POLLING_MODE == LPspi_pDev->LPspi_AsyncMode) && (SPI_PHYUNIT_ASYNC_U32 == LPspi_pDev->LPspi_pcHWUnitConfig->u32IsSync))
    {
#if (SPI_DMA_USED == STD_ON)
        LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
#endif
        /* Set pool request flag */
        LPspi_pDev->LPspi_u8IsPollRequest = 1u;

#if (SPI_DMA_USED == STD_ON)
        if (LPspi_pcHWUnitConfig->u16UseDma)
        {
            /* Get status from TCD[7] register */
            /* Emulate IRQ */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if (0u != Mcl_DmaIsTransferCompleted(LPspi_pcHWUnitConfig->u8RxDmaChannel))
            {
                /* Set pool RX request flag */
                LPspi_pDev->LPspi_u32IsPollRequestRX = 1u;
                if(1u == LPspi_pDev->LPspi_u8IsPollRequest)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
                    * a pointer to a function and any type other than an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    Mcl_DmaTcdClearDone(LPspi_pcHWUnitConfig->u8RxDmaChannel) ;
                    Spi_LPspi_IsrDmaRx(LPspi_pDev);
                    /* Clear pool request flag */
                     LPspi_pDev->LPspi_u8IsPollRequest = 0u;
                }
            }
            else
            {
                /* Do nothing */
            }
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if (0u != Mcl_DmaIsTransferCompleted(LPspi_pcHWUnitConfig->u8TxDmaChannel))
            {
                /* Set pool TX request flag */
                LPspi_pDev->LPspi_u32IsPollRequestTX = 1u;
                if(1u == LPspi_pDev->LPspi_u8IsPollRequest)
                {
                     /*
                     * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
                     * a pointer to a function and any type other than an integral type.
                     */
                     /*
                     * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                     */
                     Mcl_DmaTcdClearDone(LPspi_pcHWUnitConfig->u8TxDmaChannel) ;
                     Spi_LPspi_IsrDmaTx(LPspi_pDev);
                     /* Clear pool request flag */
                     LPspi_pDev->LPspi_u8IsPollRequest = 0u;
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
#endif /* (SPI_DMA_USED == STD_ON) */
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            LPspi_u32IsrStatus = REG_READ32(LPspi_pDev->LPspi_u32SRAddress);
            LPspi_pDev->LPspi_u32IsPollRequestTX = LPspi_u32IsrStatus & LPSPI_SR_TDF_MASK_U32;
            LPspi_pDev->LPspi_u32IsPollRequestRX = LPspi_u32IsrStatus & LPSPI_SR_RDF_MASK_U32;
            if(1u == LPspi_pDev->LPspi_u8IsPollRequest)
            {
                if ((0u != LPspi_pDev->LPspi_u32IsPollRequestTX) || (0u != LPspi_pDev->LPspi_u32IsPollRequestRX))
                {
                    /* Emulate IRQ in PIO_FIFO mode */
                    Spi_LPspi_IsrFifoRx(LPspi_pDev, LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset);
                }
                else
                {
                    /* Do nothing */
                }
                /* Clear pool request flag */
                LPspi_pDev->LPspi_u8IsPollRequest = 0u;
            }
        }
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
/*================================================================================================*/
/**
* @brief   This function performs the de-initialization of a specific peripheral unit.
* @details This function de-initializes all configured values
*          in the MCR register and CTAR registers.
*
* @param[in]     HWUnit      Specifies which LPSPI peripheral is used
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_LPspi_DeInit
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    )
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
    VAR(uint8, AUTOMATIC) LPspi_u8HWoffset;

    /* Get physical device handler */  
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcHWUnitConfig = &Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit];

    /* Pointer to peripheral registers */
    LPspi_u8HWoffset = LPspi_pcHWUnitConfig->u8Offset;
    
    /* Reset the LPSPI Regs and Transmit/Receive FIFO */    
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_CR_ADDR32(LPspi_u8HWoffset), (LPSPI_CR_RST_RESET_U32 | LPSPI_CR_RRF_RESET_U32 | LPSPI_CR_RTF_RESET_U32));

    /*
    * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_CR_ADDR32(LPspi_u8HWoffset), LPSPI_CR_RESET_U32);
}


/*================================================================================================*/
/**
* @brief   This function is called by DMA ISR for Rx DMA channels.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the LPSPI
*          peripherals
*
* @param[in]     LPspi_pDev     Specifies which LPSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_LPspi_IsrDmaTx
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) LPspi_AsyncMode = LPspi_pDev->LPspi_AsyncMode;
    VAR(uint32, AUTOMATIC) LPspi_u32IsrStatus  = (uint32)FALSE; 
    VAR(uint32, AUTOMATIC) LPspi_u32Cmd = LPspi_pDev->LPspi_u32CurrentCmd;

    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE == LPspi_AsyncMode)
        {
            /* Operation mode is SPI_POLLING_MODE: set u8IsrStatus to poll TX request flag*/
            LPspi_u32IsrStatus = (uint8)LPspi_pDev->LPspi_u32IsPollRequestTX;
            /* Clear poll TX request flag */
            LPspi_pDev->LPspi_u32IsPollRequestTX = (uint8)FALSE;
        }
        else
        {
            /* Operation mode is SPI_INTERRUPT_MODE: set u8IsrStatus to enabled*/
            LPspi_u32IsrStatus = (uint8)TRUE;
        }

        /* Check if a poll request was made or if the operation mode is SPI_INTERRUPT_MODE */
        if (0u != LPspi_u32IsrStatus)
        {

            if ( 0u != LPspi_pDev->LPspi_RemainingData )
            {
                /* Channel not finished => update TX pointers */
                Spi_LPspi_JobTransferDmaContinueTX(LPspi_pDev);
            }
            else
            {
                /* reached the end of channel => move to the next channel */
                if (0u != LPspi_pDev->LPspi_RemainingChannelsTX)
                {
                    /* Increase Channel indexes */
                    LPspi_pDev->LPspi_RemainingChannelsTX--;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX++;

                    /* prepare next channel transmission */
                    Spi_LPspi_ChannelTransferDmaInitTX(LPspi_pDev,*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX));
                }
                else
                {
                    /* clear the CS assertion directly into the next TX frame */
                    LPspi_u32Cmd &= ~LPSPI_TCR_CONT_EN_U32;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_WRITE32(LPspi_pDev->LPspi_u32TCRAddress, (LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
                }
            }
        }
        else
        {
            /* Driver is initialized but there was no poll request*/
            /* Do nothing */
        }
    }
    else
    {
        /* Driver is not initialized, do nothing */
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
        
/**
* @brief   This function is called by DMA ISR for Rx DMA channels.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the LPSPI
*          peripherals
*
* @param[in]     LPspi_pDev     Specifies which LPSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_LPspi_IsrDmaRx
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) LPspi_AsyncMode = LPspi_pDev->LPspi_AsyncMode;
    VAR(uint8, AUTOMATIC) LPspi_u32IsrStatus  = (uint8)FALSE; 

    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE == LPspi_AsyncMode)
        {
            /* Operation mode is SPI_POLLING_MODE: set u8IsrStatus to poll RX request flag*/
            LPspi_u32IsrStatus = (uint8)LPspi_pDev->LPspi_u32IsPollRequestRX;
            /* Clear poll RX request flag */
            LPspi_pDev->LPspi_u32IsPollRequestRX = (uint8)FALSE;
        }
        else
        {
            /* Operation mode is SPI_INTERRUPT_MODE: set u8IsrStatus to enabled*/
            LPspi_u32IsrStatus = (uint8)TRUE;
        }

        /* Check if a poll request was made or if the operation mode is SPI_INTERRUPT_MODE */
        if (0u != LPspi_u32IsrStatus)
        {

            if ( 0u != LPspi_pDev->LPspi_ReceivedData )
            {
                /* Channel not finished => update TX pointers */
                Spi_LPspi_JobTransferDmaContinueRX(LPspi_pDev);
            }
            else
            {
                /* reached the end of channel => move to the next channel */
                if (0u != LPspi_pDev->LPspi_RemainingChannelsRX)
                {
                    /* Increase Channel indexes */
                    LPspi_pDev->LPspi_RemainingChannelsRX--;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX++;

                    /* prepare next channel transmission */
                    Spi_LPspi_ChannelTransferDmaInitRX(LPspi_pDev,*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX));
                }
                else
                {
                    Spi_JobTransferFinished(LPspi_pDev->LPspi_pcCurrentJob);
                }
            }
        }
        else
        {
            /* Driver is initialized but there was no poll request*/
            /* Do nothing */
        }
    }
    else
    {
        /* Driver is not initialized, do nothing */
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
        
/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in LPSPI HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel.
*
* @param[in]     LPspi_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmitted.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferFifoInitTX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    ) \
{
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelAttributesConfig;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfig;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelState;
    VAR(uint32, AUTOMATIC) LPspi_u32Cmd;
    VAR(uint32, AUTOMATIC) LPspi_u32FCR;
    
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[Channel];
    LPspi_pChannelState = LPspi_pcChannelConfig->pChannelState;
    LPspi_pDev->LPspi_RemainingData = LPspi_pChannelState->Length;
    /* Get the current command for this channel */
    LPspi_u32Cmd = (LPspi_pDev->LPspi_u32ExternalDeviceTCR | LPspi_pcChannelAttributesConfig->u32CMD)&(~LPSPI_TCR_BYSW_EN_U32);
    /* Get the configuration of FIFO for this channel */
    LPspi_u32FCR = LPspi_pcChannelAttributesConfig->u32FCR;
    /* Store the current command for this channel */
    LPspi_pDev->LPspi_u32CurrentCmd = LPspi_u32Cmd;
    /* identify the TX buffers */
    if (0u != (LPspi_pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
    {
        LPspi_pDev->LPspi_pCurrentTxBuffer = NULL_PTR;

        /* integrate default transmit value in the command */
        LPspi_pDev->LPspi_u32TransmitDefaultData = LPspi_pcChannelConfig->DefaultTransmitValue;
    }
    else
    {
        LPspi_pDev->LPspi_pCurrentTxBuffer = LPspi_pcChannelConfig->pcBufferDescriptor->pBufferTX;
    }
    /* set TCR register */
    /**
    * @note The call is blocking till the HWUnit exits the running state.
    */
    if(0u!=(LPspi_u32Cmd & LPSPI_TCR_CONT_EN_U32 & LPSPI_TCR_RESERVED_MASK_U32))
    {
         if((uint8)TRUE == LPspi_pDev->LPspi_FirstChannelOfJobFlag)
         {
              /*
              * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
              *     type and an integral type.
              */
              /*
              * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
              */
              REG_WRITE32(LPspi_pDev->LPspi_u32TCRAddress, (LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
              LPspi_pDev->LPspi_FirstChannelOfJobFlag=(uint8)FALSE;
          }
     }
     else
     {
          /*
          * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
          *     type and an integral type.
          */
          /*
          * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
          */
          REG_WRITE32(LPspi_pDev->LPspi_u32TCRAddress, (LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
      }
    /* set FCR register */
    /**
    * @note The call is blocking till the HWUnit exits the running state.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_BASEADDR2FCR_ADDR32(LPspi_pDev->LPspi_u32BaseAddress), (LPspi_u32FCR & LPSPI_FCR_RESERVED_MASK_U32));

#if (SPI_SLAVE_SUPPORT == STD_ON)
    if(SPI_SLAVE == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /*
         * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
         *     type and an integral type.
         */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_BIT_SET32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset), LPSPI_IER_RDIE_MASK_U32);
    }
    else
    {
        /* Do nothing */
    }
#endif
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/**
* @brief   This function initializes channel related informations in LPSPI HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel.
*
* @param[in]     LPspi_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmitted.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferFifoInitRX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    ) \
{
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfig;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelState;
    
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    LPspi_pChannelState = LPspi_pcChannelConfig->pChannelState;
    LPspi_pDev->LPspi_ReceivedData = LPspi_pChannelState->Length;
    /* identify the RX buffers */
    /* Rx buffer will be NULL if discarding read values */
    LPspi_pDev->LPspi_pCurrentRxBuffer = LPspi_pcChannelConfig->pcBufferDescriptor->pBufferRX;
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function fills the LPSPI FIFO.
* @details This function fills LPSPI FIFO Transmit buffer with the
*          predefined data assigned or transmit the default
*          buffer values in case of the lack of transmit
*          data buffer.
*
* @param[in]     LPspi_pDev     Specifies which LPSPI module is used
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferFifoFill \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    ) \
{
     VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_nFramesCount;
    VAR(uint8, AUTOMATIC) LPspi_u8EndOfJob = (uint8)FALSE; /* end of job */
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) 
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX)];

    /* calculate the number of frames to be sent and the 'end of job' state */
    LPspi_nFramesCount = LPspi_pDev->LPspi_RemainingData;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_nFramesCount/=2u;
    }
    else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_nFramesCount/=4u;
    }
    else
    {
        /* Do nothing */
    }
    #else
    if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_nFramesCount/=2u;
    }
    else
    {
        /* Do nothing */
    }
#endif
    if(SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        if((0u == (uint32)(LPspi_pDev->LPspi_RemainingChannelsTX)) && (1U == LPspi_nFramesCount))
        {
            LPspi_u8EndOfJob = (uint8)TRUE;
        }
        else
        {
            LPspi_u8EndOfJob = (uint8)FALSE;
        }
    }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if(SPI_SLAVE == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        if(LPspi_nFramesCount > SPI_FIFO_SIZE)
        {
            /*
             * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
             *     type and an integral type.
             */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            LPspi_nFramesCount = (Spi_NumberOfDataType)((uint32)SPI_FIFO_SIZE - LPSPI_FSR_TXCOUNT_VAL_U32(REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset))));
        }
        else
        {
            /*
             * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
             *     type and an integral type.
             */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if(LPspi_nFramesCount > (Spi_NumberOfDataType)((uint32)SPI_FIFO_SIZE - LPSPI_FSR_TXCOUNT_VAL_U32(REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)))))
            {
               /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_nFramesCount = (Spi_NumberOfDataType)((uint32)SPI_FIFO_SIZE - LPSPI_FSR_TXCOUNT_VAL_U32(REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset))));
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
#endif
        if(LPspi_nFramesCount>0u)
        {
            LPspi_nFramesCount = 1u;
        }
        else
        {
            /*do nothing*/
        }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif

    LPspi_pDev->LPspi_RemainingData -= LPspi_nFramesCount;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_pDev->LPspi_RemainingData -= LPspi_nFramesCount;
    }
    else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_pDev->LPspi_RemainingData -= 3u * LPspi_nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #else
    if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_pDev->LPspi_RemainingData -= LPspi_nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #endif
    
    LPspi_pDev->LPspi_SentFrames = LPspi_nFramesCount;

    Spi_LPspi_WriteTxFifo(LPspi_pDev, LPspi_u8EndOfJob);

}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
/*================================================================================================*/
/**
* @brief   This function fills the LPSPI FIFO.
* @details This function fills LPSPI FIFO Transmit buffer with
*          data assigned or transmit the default
*          buffer values in case of the lack of transmit
*          data buffer.
*
* @param[in]     LPspi_pDev             Specifies which LPSPI module is used
*                LPspi_u8EndOfJob       End of job flag
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_WriteTxFifo \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(uint8, AUTOMATIC) LPspi_u8EndOfJob \
    ) \
{
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LPspi_pBufferTX = LPspi_pDev->LPspi_pCurrentTxBuffer;
     VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_nFramesCount = LPspi_pDev->LPspi_SentFrames;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) 
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX)];
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) LPspi_pu16BufferFullTX;
    P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LPspi_pu32BufferFullTX;
#else
    VAR(uint32, AUTOMATIC) LPspi_u32BufferFullTX;
#endif
    /* Get physical device handler */
    VAR(uint32, AUTOMATIC) LPspi_u32TDRAddress = LPspi_pDev->LPspi_u32TDRAddress;

    if (NULL_PTR != LPspi_pBufferTX)
    {
        /* set the new TX buffer pointer */
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        LPspi_pDev->LPspi_pCurrentTxBuffer += LPspi_nFramesCount;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            LPspi_pDev->LPspi_pCurrentTxBuffer += LPspi_nFramesCount;
        }
        else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            LPspi_pDev->LPspi_pCurrentTxBuffer += 3u * LPspi_nFramesCount;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            LPspi_pDev->LPspi_pCurrentTxBuffer += LPspi_nFramesCount;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        
        /* write the information from the buffer */
        while (LPspi_nFramesCount > 0u)
        {
            LPspi_nFramesCount--;

            #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if( SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                * pointer to object type and a different pointer to object type.
                */
                LPspi_pu16BufferFullTX = (uint16 *) LPspi_pBufferTX;
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPspi_u32TDRAddress, (*LPspi_pu16BufferFullTX));
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                LPspi_pBufferTX++;
            }
            else if( SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
            {
                 /*
                       * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a pointer
                       *       to object type and a different pointer to object type.
                       */
                LPspi_pu32BufferFullTX = (uint32 *) LPspi_pBufferTX;
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPspi_u32TDRAddress, (*LPspi_pu32BufferFullTX));
                /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                LPspi_pBufferTX += 3u;
            }
            else
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPspi_u32TDRAddress, (*LPspi_pBufferTX));
            }
            #else
            if( SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
            {
                #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                     /*
                            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                            *  pointer to object type and a different pointer to object type.
                            */
                    LPspi_u32BufferFullTX = (uint32)(*LPspi_pBufferTX) | ((uint32)(*(LPspi_pBufferTX+1u)) << 16u);
                #else
                    /*
                            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                            *  pointer to object type and a different pointer to object type.
                            */
                    LPspi_u32BufferFullTX = ((uint32)(*LPspi_pBufferTX) << 16u) | (uint32)(*(LPspi_pBufferTX+1u));
                #endif
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPspi_u32TDRAddress, LPspi_u32BufferFullTX);
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                LPspi_pBufferTX++;
            }
            else
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPspi_u32TDRAddress, (*LPspi_pBufferTX));
            }            
            #endif
            if(SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
            {
                if (0u == LPspi_nFramesCount)
                {
                    if (LPspi_u8EndOfJob)
                    {
                        /* signal the end of job for the current LPSPI Unit */
                        LPspi_pDev->LPspi_bIsEndOfJob = (boolean)TRUE;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
            }
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            LPspi_pBufferTX++;
        }
    }
    else
    {   /* write the default value */
        while (LPspi_nFramesCount > 0u)
        {
            LPspi_nFramesCount--;
            /* default transmit value already integrated in LPspi_pDev->u32CurrentCmd */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPspi_u32TDRAddress, LPspi_pDev->LPspi_u32TransmitDefaultData);
            if(SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
            {
                if (0u == LPspi_nFramesCount)
                {
                    if (LPspi_u8EndOfJob)
                    {
                        /* signal the end of job for the current LPSPI Unit */
                        LPspi_pDev->LPspi_bIsEndOfJob = (boolean)TRUE;
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }

}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
/*================================================================================================*/
/**
* @brief   This function drains the LPSPI FIFO.
* @details This function retrieves the received data from LPSPI FIFO.
*
* @param[in]     LPspi_pDev     Specifies which LPSPI module is used.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferFifoDrain \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    ) \
{
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LPspi_pBufferRx;
     VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_nFramesCount = 0U;
    VAR(uint32, AUTOMATIC) LPspi_u32RDRAddress = LPspi_pDev->LPspi_u32RDRAddress;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) \
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX)];
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) LPspi_pu16BufferFullRX;
    P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LPspi_pu32BufferFullRX;
    #else
    VAR(uint32, AUTOMATIC) LPspi_u32BufferFullRX;
    #endif
    #if (SPI_SLAVE_SUPPORT == STD_ON)
    VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_DiscardFramesCount = 0U;
    #endif
    VAR(Spi_NumberOfDataType, AUTOMATIC) TempFramesCount = 0U;

    if( SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode )
    {
        /* Master mode */
        LPspi_nFramesCount = LPspi_pDev->LPspi_SentFrames;
    }
    else
    {
        /* Slave mode */
        #if (SPI_SLAVE_SUPPORT == STD_ON)
        LPspi_nFramesCount = LPspi_pDev->LPspi_ReceivedData;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_nFramesCount/=2u;
        }
        else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_nFramesCount/=4u;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_nFramesCount/=2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* Check if the received data fits into the remaining buffer space */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        if( LPSPI_FSR_RXCOUNT_VAL_U32(REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset))) > LPspi_nFramesCount )
        {
            /* Too much data, buffer overflow detected */
            /* Set the number of frames to be discarded */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            LPspi_DiscardFramesCount = (Spi_NumberOfDataType)LPSPI_FSR_RXCOUNT_VAL_U32(REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset))) - LPspi_nFramesCount;
        }
        else
        {
            /* Set the number of frames received */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            LPspi_nFramesCount = (Spi_NumberOfDataType)LPSPI_FSR_RXCOUNT_VAL_U32(REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)));
            /* No overflow detected, continue normal flow */
            /* Set no frames to discard */
            LPspi_DiscardFramesCount = 0u;
        }
        #endif
    }
    
    LPspi_pDev->LPspi_ReceivedData -= LPspi_nFramesCount;
    
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_pDev->LPspi_ReceivedData -= LPspi_nFramesCount;
    }
    else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_pDev->LPspi_ReceivedData -= 3u*LPspi_nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #else
    if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_pDev->LPspi_ReceivedData -= LPspi_nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #endif

    LPspi_pBufferRx = LPspi_pDev->LPspi_pCurrentRxBuffer;

    if (NULL_PTR != LPspi_pBufferRx)
    {
        /* Save LPspi_nFramesCount into TempFramesCount for compare by do{}while */
        TempFramesCount = LPspi_nFramesCount;
        /* read the deserialized information */
        do
        {
            if(0u != LPspi_nFramesCount)
            {
            #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                    * pointer to object type and a different pointer to object type.
                    */
                    LPspi_pu16BufferFullRX = (uint16 *) LPspi_pBufferRx;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRx += 2u;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    *LPspi_pu16BufferFullRX = (uint16)REG_READ32(LPspi_u32RDRAddress);  
                }
                else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                    * pointer to object type and a different pointer to object type.
                    */
                    LPspi_pu32BufferFullRX = (uint32 *) LPspi_pBufferRx;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRx += 4u;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    *LPspi_pu32BufferFullRX = (uint32)REG_READ32(LPspi_u32RDRAddress);               
                }
                else
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                     *LPspi_pBufferRx = (Spi_DataBufferType)REG_READ32(LPspi_u32RDRAddress);
                     /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRx++;
                }
            #else
                if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
                {                   
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    LPspi_u32BufferFullRX = (uint32)REG_READ32(LPspi_u32RDRAddress);           
                    #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                        *LPspi_pBufferRx = (uint16)(LPspi_u32BufferFullRX & (uint32)0x0000FFFFu);
                         /*
                                  * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                                  *       the only allowed form of pointer arithmetic.
                                  */
                        *(LPspi_pBufferRx+1u) = (uint16)(LPspi_u32BufferFullRX >> 16u);
                    #else
                        *LPspi_pBufferRx = (uint16)(LPspi_u32BufferFullRX >> 16u);
                         /*
                                  * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                                  *       the only allowed form of pointer arithmetic.
                                  */
                        *(LPspi_pBufferRx+1u) = (uint16)(LPspi_u32BufferFullRX & (uint32)0x0000FFFFu);
                    #endif       
                    /*
                          * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                          *       the only allowed form of pointer arithmetic.
                          */
                    LPspi_pBufferRx += 2u;                    
                }
                else
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                     *LPspi_pBufferRx = (Spi_DataBufferType)REG_READ32(LPspi_u32RDRAddress);
                     /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRx++; 
                }
            #endif
                LPspi_nFramesCount--;
            }
        } while ((0u < LPspi_nFramesCount) && (LPspi_nFramesCount < TempFramesCount));  /* TX_FIFO_SIZE =4 */
        /* update current RX buffer pointer */
        LPspi_pDev->LPspi_pCurrentRxBuffer = LPspi_pBufferRx;
    }
    else
    {   
        /* Save LPspi_nFramesCount into TempFramesCount for use compare by do{}while */
        TempFramesCount = LPspi_nFramesCount;
        /* discard the information read */
        do
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Spi_LPspi_u32ReadDiscard = REG_READ32(LPspi_u32RDRAddress);
            LPspi_nFramesCount--;
        } while ((0u < LPspi_nFramesCount) && (LPspi_nFramesCount < TempFramesCount));
    }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    if( SPI_SLAVE == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /* Check if there are any frames to discard */
        if(0u != LPspi_DiscardFramesCount)
        {
            /* Save LPspi_DiscardFramesCount into TempFramesCount for use compare by do{}while */
            TempFramesCount = LPspi_DiscardFramesCount;
            /* Discard all the surplus frames */
            do
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                Spi_LPspi_u32ReadDiscard = REG_READ32(LPspi_u32RDRAddress);
                LPspi_DiscardFramesCount--;
            }
            while((0u < LPspi_DiscardFramesCount) && (LPspi_DiscardFramesCount < TempFramesCount));
        }
        else
        {
            /* Do nothing */
        }

        if((Spi_NumberOfDataType)0u == LPspi_pDev->LPspi_ReceivedData)
        {
            LPspi_pDev->LPspi_bIsEndOfJob = (boolean)TRUE;
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
#endif
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Computes sequence / job configuration parameters like
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          This cached values will be used in sync transmissions in
*          order to optimize the time.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall not be LEVEL1.
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON.
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_LPspi_PrepareCacheInformation(void)
{
    VAR(Spi_ChannelType, AUTOMATIC) LPspi_Channel;
    VAR(Spi_ChannelType, AUTOMATIC) LPspi_ChannelId;
    VAR(Spi_JobType, AUTOMATIC) LPspi_Job;
    VAR(uint32, AUTOMATIC) LPspi_u32Sequence;
    P2VAR(Spi_LPspi_ChannelCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelAttrs;
    P2VAR(Spi_LPspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) LPspi_pSeqAttrs;
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcDeviceAttributesConfig;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcJobConfig;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcSequenceConfig;
    /* index to the first free entry in 'Spi_LPspi_aSeqsAttributes' table. */
    VAR(Spi_SequenceType, AUTOMATIC) LPspi_SeqsAttrCurrentIndex = 0u;
    /* index to the first free entry in 'Spi_LPspi_aChannelsAttributes' table. */
    VAR(Spi_ChannelType, AUTOMATIC) LPspi_ChannelsAttrCurrentIndex = 0u;

    /* reset all sequences as not optimized */
    for (LPspi_u32Sequence = 0u; LPspi_u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence); LPspi_u32Sequence++)
    {
        Spi_LPspi_apOneJobSeqsOptimized[LPspi_u32Sequence] = NULL_PTR;
    }

    for (LPspi_u32Sequence = 0u; LPspi_u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence); LPspi_u32Sequence++)
    {
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[LPspi_u32Sequence];
        /* only one job sequences can be optimized */
        if (1u == LPspi_pcSequenceConfig->NumJobs)
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            LPspi_Job = LPspi_pcSequenceConfig->pcJobIndexList[0];
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            LPspi_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[LPspi_Job];

            /* check if enough place in the cached data channel pool */
            if (LPspi_pcJobConfig->NumChannels <= (SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE-LPspi_ChannelsAttrCurrentIndex))
            {
                /* get the first empty entry in the sequence pool and
                link it to the sequence */
                LPspi_pSeqAttrs = &Spi_LPspi_aSeqsAttributes[LPspi_SeqsAttrCurrentIndex];
                Spi_LPspi_apOneJobSeqsOptimized[LPspi_u32Sequence] = LPspi_pSeqAttrs;

                /* retrieve the device configuration for the sequence */
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                LPspi_pcDeviceAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig[Spi_pcSpiConfigPtr->pcJobConfig[LPspi_Job].ExternalDevice];

                /* prepare sequence cache information */
                LPspi_pSeqAttrs->LPspi_HWUnit = LPspi_pcJobConfig->HWUnit;
                LPspi_pSeqAttrs->LPspi_NumChannels = LPspi_pcJobConfig->NumChannels;
                LPspi_pSeqAttrs->LPspi_pJobState = &Spi_aSpiJobState[LPspi_Job];
                LPspi_pSeqAttrs->LPspi_u32BaseAddress = Spi_LPspi_aDeviceState[LPspi_pcJobConfig->HWUnit].LPspi_u32BaseAddress;
                LPspi_pSeqAttrs->LPspi_pJobStatus = Spi_LPspi_aDeviceState[LPspi_pcJobConfig->HWUnit].LPspi_pStatus;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
                LPspi_pSeqAttrs->LPspi_u32JobCMD[0] = LPspi_pcDeviceAttributesConfig->u32TCR[0];
                LPspi_pSeqAttrs->LPspi_u32JobCCR[0] = LPspi_pcDeviceAttributesConfig->u32CCR[0];
                if ((uint8)TRUE == LPspi_pcDeviceAttributesConfig->u8DualClk)
                {
                    LPspi_pSeqAttrs->LPspi_u32JobCMD[1] = LPspi_pcDeviceAttributesConfig->u32TCR[1];                
                    LPspi_pSeqAttrs->LPspi_u32JobCCR[1] = LPspi_pcDeviceAttributesConfig->u32CCR[1];
                }
                else
                {
                    LPspi_pSeqAttrs->LPspi_u32JobCMD[1] = LPspi_pcDeviceAttributesConfig->u32TCR[0];                
                    LPspi_pSeqAttrs->LPspi_u32JobCCR[1] = LPspi_pcDeviceAttributesConfig->u32CCR[0];
                }                
#else
                LPspi_pSeqAttrs->LPspi_u32JobCMD = LPspi_pcDeviceAttributesConfig->u32TCR;
                LPspi_pSeqAttrs->LPspi_u32JobCCR = LPspi_pcDeviceAttributesConfig->u32CCR;
#endif
                /* set the link to the first cached channel entry */
                LPspi_pSeqAttrs->LPspi_pChannels = &Spi_LPspi_aChannelsAttributes[LPspi_ChannelsAttrCurrentIndex];

                /* prepare channel cache information */
                for (LPspi_Channel = 0u; LPspi_Channel < LPspi_pcJobConfig->NumChannels; LPspi_Channel++)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    LPspi_ChannelId = LPspi_pcJobConfig->pcChannelIndexList[LPspi_Channel];
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    LPspi_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[LPspi_ChannelId];
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pChannelAttrs = &LPspi_pSeqAttrs->LPspi_pChannels[LPspi_Channel];
                    LPspi_pChannelAttrs->LPspi_DefaultTransmitValue = LPspi_pcChannelConfig->DefaultTransmitValue;
                    LPspi_pChannelAttrs->LPspi_pState = LPspi_pcChannelConfig->pChannelState;
                    LPspi_pChannelAttrs->LPspi_pcBufferDescriptor = LPspi_pcChannelConfig->pcBufferDescriptor;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
                    LPspi_pChannelAttrs->LPspi_u32TCR[0] =
                        LPspi_pcDeviceAttributesConfig->u32TCR[0]
                        |
                        /*
                        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                        */
                        Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelId].u32CMD;
                    if ((uint8)TRUE == LPspi_pcDeviceAttributesConfig->u8DualClk)
                    {    
                        LPspi_pChannelAttrs->LPspi_u32TCR[1] =
                            LPspi_pcDeviceAttributesConfig->u32TCR[1]
                            |
                            /*
                            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                            */
                            Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelId].u32CMD;
                    }
                    else
                    {
                        LPspi_pChannelAttrs->LPspi_u32TCR[1] =
                            LPspi_pcDeviceAttributesConfig->u32TCR[0]
                            |
                            /*
                            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                            */
                            Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelId].u32CMD;
                    }
#else
                    LPspi_pChannelAttrs->LPspi_u32TCR =
                        LPspi_pcDeviceAttributesConfig->u32TCR
                        |
                        /*
                        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                        */
                        Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelId].u32CMD;
#endif
                    LPspi_pChannelAttrs->LPspi_u8DataWidth =
                        /*
                        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                        */
                        Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelId].u8DataWidth;
                } /* for (channels) */

                /* set the pool indexes to the new empty entries */
                LPspi_SeqsAttrCurrentIndex++;
                LPspi_ChannelsAttrCurrentIndex += LPspi_pcJobConfig->NumChannels;

                /* end the loop if caches are full */
                if(
                    (LPspi_SeqsAttrCurrentIndex >= SPI_OPTIMIZED_SEQ_BUFFER_SIZE)||
                    (LPspi_ChannelsAttrCurrentIndex >= SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE)
                  )
                {
                    break; /* end the loop */
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    } /* for (sequences) */
}
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

/*================================================================================================*/
/**
* @brief   This function sets the Job's attributes and send all the data through the SPI bus.
* @details This function is in charge to setup the Job attribute,
*          and to send all data though the SPI Bus.
*
* @param[in]     pcJobConfig    Specifies the Job for which we will set the
*                            register values
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_LPspi_JobTransfer
    (
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    )
{
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev = &Spi_LPspi_aDeviceState[pcJobConfig->HWUnit];
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelList = pcJobConfig->pcChannelIndexList;
    VAR(uint32, AUTOMATIC) LPspi_u32CCR;
#if (SPI_DMA_USED == STD_ON)
    #if (SPI_SLAVE_SUPPORT == STD_ON)
    VAR(uint32, AUTOMATIC) LPspi_u32FSR;
    #endif
#endif

    /* start job notification to assert the non-cs pin,
        when non-cs pin is used as chipselect*/
    if (NULL_PTR != pcJobConfig->pfStartNotification)
    {
        pcJobConfig->pfStartNotification();
    }
    else
    {
        /* Do nothing */
    }
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    if((uint8)TRUE == pcJobConfig->ExternalDeviceAttrs.u8DualClk)
    {
        LPspi_pDev->LPspi_u32ExternalDeviceTCR = pcJobConfig->ExternalDeviceAttrs.u32TCR[Spi_LPspi_ClockMode];
        LPspi_pDev->LPspi_u32ExternalDeviceCCR = pcJobConfig->ExternalDeviceAttrs.u32CCR[Spi_LPspi_ClockMode];
    }
    else
    { 
        LPspi_pDev->LPspi_u32ExternalDeviceTCR = pcJobConfig->ExternalDeviceAttrs.u32TCR[SPI_NORMAL];
        LPspi_pDev->LPspi_u32ExternalDeviceCCR = pcJobConfig->ExternalDeviceAttrs.u32CCR[SPI_NORMAL];
    } 
#else
    LPspi_pDev->LPspi_u32ExternalDeviceTCR = pcJobConfig->ExternalDeviceAttrs.u32TCR;
    LPspi_pDev->LPspi_u32ExternalDeviceCCR = pcJobConfig->ExternalDeviceAttrs.u32CCR;
#endif
    /* Update the timing register */
    LPspi_u32CCR=LPspi_pDev->LPspi_u32ExternalDeviceCCR;
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPspi_pDev->LPspi_u32CCRAddress, LPspi_u32CCR);
    LPspi_pDev->LPspi_FirstChannelOfJobFlag=(uint8)TRUE;
    /* initialize starting channel index */
    LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX = LPspi_pcChannelList;
    LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX = LPspi_pcChannelList;
    LPspi_pDev->LPspi_RemainingChannelsTX = pcJobConfig->NumChannels - (Spi_ChannelType) 1u;
    LPspi_pDev->LPspi_RemainingChannelsRX = pcJobConfig->NumChannels - (Spi_ChannelType) 1u;

    /* memorize the current job */
    LPspi_pDev->LPspi_pcCurrentJob = pcJobConfig;
#if (SPI_DMA_USED == STD_ON)
    #if (SPI_SLAVE_SUPPORT == STD_ON)
    if(SPI_SLAVE == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        LPspi_u32FSR=REG_READ32(LPSPI_BASEADDR2FSR_ADDR32(LPspi_pDev->LPspi_u32BaseAddress));
        if(0u != LPspi_u32FSR)
        {
            /* Discard all frames in FIFO */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET32(LPSPI_CR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset),(LPSPI_CR_RRF_RESET_U32 | LPSPI_CR_RTF_RESET_U32)); 
        }
    }
    else
    {
        /* Do nothing */
    }   
    #endif
    if (0u != LPspi_pDev->LPspi_pcHWUnitConfig->u16UseDma)
    {
        LPspi_pDev->LPspi_bIsEndOfJob = (boolean)FALSE;
        /* initialize the transfer parameters for the first channel */
        Spi_LPspi_ChannelTransferDmaInitRX(LPspi_pDev, *LPspi_pcChannelList);
        Spi_LPspi_ChannelTransferDmaInitTX(LPspi_pDev, *LPspi_pcChannelList);
    }
    else
#endif /* (SPI_DMA_USED == STD_ON) */
    {
        LPspi_pDev->LPspi_bIsEndOfJob = (boolean)FALSE;

        /* initialize the transfer parameters for the first channel */
        Spi_LPspi_ChannelTransferFifoInitTX(LPspi_pDev, *LPspi_pcChannelList);
        Spi_LPspi_ChannelTransferFifoInitRX(LPspi_pDev, *LPspi_pcChannelList);
        Spi_LPspi_JobTransferFifoFill(LPspi_pDev);
        
        if(SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
        {
            /* Enable transmit interrupt for interrupt mode */
            if(SPI_INTERRUPT_MODE == LPspi_pDev->LPspi_AsyncMode)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */                     
                REG_BIT_SET32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset), LPSPI_IER_TDIE_MASK_U32);
            }
        }
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called by TDF or RDF ISRs for the LPSPI units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the LPSPI
*          peripherals.
*
* @param[in]     LPspi_pDev     Specifies which LPSPI peripheral is used
*
* @implements Spi_LPspi_IsrFifoRx_Activity
*/
FUNC(void, SPI_CODE) Spi_LPspi_IsrFifoRx
    (
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev,
        VAR(uint8, AUTOMATIC) u8HWoffset
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode = LPspi_pDev->LPspi_AsyncMode;
    VAR(uint32, AUTOMATIC) LPspi_u32IsrStatusTX = 0u;
    VAR(uint32, AUTOMATIC) LPspi_u32IsrStatusRX = 0u;

    /* Check if the driver has been initialized */
    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE != AsyncMode)
        {
            if((uint8)SPI_MASTER == LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
            {
                /*Not in pooling mode: read status register and interrupts enabled register */
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusTX = REG_READ32(LPspi_pDev->LPspi_u32SRAddress) & LPSPI_SR_TDF_MASK_U32;
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusRX = REG_READ32(LPspi_pDev->LPspi_u32SRAddress) & LPSPI_SR_RDF_MASK_U32;
                /*
                * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusTX &= REG_READ32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)) & LPSPI_IER_TDIE_MASK_U32;
                /*
                * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusRX &= REG_READ32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)) & LPSPI_IER_RDIE_MASK_U32;
            }
            else
            {
    #if (SPI_SLAVE_SUPPORT == STD_ON)

                /*Not in pooling mode: read status register and interrupts enabled register */
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusRX = REG_READ32(LPspi_pDev->LPspi_u32SRAddress) & LPSPI_SR_RDF_MASK_U32;
                /*
                * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusRX &= REG_READ32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)) & LPSPI_IER_RDIE_MASK_U32;
                /* Need to verify the RX FIFO is not empty */
                /*
                * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32IsrStatusRX &= ~(REG_READ32(LPSPI_RSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)) & LPSPI_RSR_RXEMPTY_MASK_U32);
    #endif
            }
        }
        else
        {
            /* Operation mode is SPI_POLLING_MODE: set u32IsrStatus to poll request flag */
            if(LPspi_pDev->LPspi_u8IsPollRequest)
            {
                LPspi_u32IsrStatusTX = LPspi_pDev->LPspi_u32IsPollRequestTX;
                LPspi_u32IsrStatusRX = LPspi_pDev->LPspi_u32IsPollRequestRX;
                /* Clear poll request flag */
                LPspi_pDev->LPspi_u8IsPollRequest = 0u;
            }
        }

        /* check if any enabled isr had been triggered */
        if ((0u != LPspi_u32IsrStatusTX) || (0u != LPspi_u32IsrStatusRX))
        {
            /* 
            * check if any enabled isr had been triggered, copy data from FIFO 
            * and prepare next channel transmission, perform the next chunk transmission
            */ 
            Spi_LPspi_TransferStatus(LPspi_pDev, LPspi_u32IsrStatusTX, LPspi_u32IsrStatusRX);
            
            if ((boolean)TRUE == LPspi_pDev->LPspi_bIsEndOfJob)
            {
                if((0u == LPspi_pDev->LPspi_ReceivedData) && (0u == LPspi_pDev->LPspi_RemainingChannelsRX))
                {
                    if(SPI_JOB_OK != LPspi_pDev->LPspi_pcCurrentJob->pJobState->Result)
                    {
                        if(NULL_PTR != LPspi_pDev->LPspi_pcCurrentJob->pJobState->pAsyncCrtSequenceState)
                        {
                            /* finish job transfer */
                            Spi_JobTransferFinished(LPspi_pDev->LPspi_pcCurrentJob);
                        }
                    }
                    else
                    {
                        /* Do nothing */
                    }  
                } 
            }
        }
        else
        {
            /* Driver has been initialized and received an unconfigured interrupt, clear status flags */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPspi_pDev->LPspi_u32SRAddress, LPSPI_SR_INT_MASK_U32);
            /* Disable transmit interrupt */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */                     
            REG_BIT_CLEAR32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset), LPSPI_IER_TDIE_MASK_U32);
        }
    }
    else
    {
        /* Driver has not been initialized, clear status flags and Reset the LPSPI Regs*/
        /* Reset the LPSPI Regs and Transmit/Receive FIFO */    
        /*
         * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
         *     type and an integral type.
         */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(LPSPI_CR_ADDR32(u8HWoffset), (LPSPI_CR_RST_RESET_U32 | LPSPI_CR_RRF_RESET_U32 | LPSPI_CR_RTF_RESET_U32));
        /*
        * @violates @ref Spi_LPspi_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(LPSPI_CR_ADDR32(u8HWoffset), LPSPI_CR_RESET_U32);
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called by TDF or RDF ISRs for the LPSPI units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the LPSPI
*          peripherals.
*
* @param[in]     LPspi_pDev               Specifies which LPSPI peripheral is used
*                LPspi_u32IsrStatusTX     Status of TDF flag
*                LPspi_u32IsrStatusRX     Status of RDF flag
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_TransferStatus
(
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev,
    VAR(uint32, AUTOMATIC) LPspi_u32IsrStatusTX,
    VAR(uint32, AUTOMATIC) LPspi_u32IsrStatusRX
)
{
    /* Get current command */
    VAR(uint32, AUTOMATIC) LPspi_u32Cmd = LPspi_pDev->LPspi_u32CurrentCmd;
    /* Get physical device handler */
    VAR(uint32, AUTOMATIC) LPspi_u32TCRAddress = LPspi_pDev->LPspi_u32TCRAddress;

    if(0u != LPspi_u32IsrStatusRX)
    {
        /* Copy data from LPSPI FIFOD to channels */
        Spi_LPspi_JobTransferFifoDrain(LPspi_pDev);               
        /* check for the channel switch */
        if ((0u == LPspi_pDev->LPspi_ReceivedData) && (0u != LPspi_pDev->LPspi_RemainingChannelsRX))
        {
            /* reached the end of channel => move to the next channel */
            /* Increase Channel indexes */
            LPspi_pDev->LPspi_RemainingChannelsRX--;
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX++;
        
            if(SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode )
            {
                /* prepare next channel transmission */
                Spi_LPspi_ChannelTransferFifoInitRX(LPspi_pDev, *(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX));
            }
            #if (SPI_SLAVE_SUPPORT == STD_ON)
            else
            {
                /* reached the end of channel => move to the next channel */
                /* Increase Channel indexes */
                LPspi_pDev->LPspi_RemainingChannelsTX--;
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX++;
                /* prepare next channel transmission */
                Spi_LPspi_ChannelTransferFifoInitTX(LPspi_pDev, *(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX));
                /* prepare next channel transmission */
                Spi_LPspi_ChannelTransferFifoInitRX(LPspi_pDev, *(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX));
            }
            #endif
        }
        else
        {
            /* Do nothing */
        }
        #if (SPI_SLAVE_SUPPORT == STD_ON)
        if(SPI_SLAVE == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode )
        {
            if ((boolean)FALSE == LPspi_pDev->LPspi_bIsEndOfJob)
            {
                /* perform the next chunk transmission */
                Spi_LPspi_JobTransferFifoFill(LPspi_pDev);
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
        #endif
    }
    else
    {
        /* Do nothing */
    }
    
    if(0u != LPspi_u32IsrStatusTX)
    {
        if ((boolean)FALSE == LPspi_pDev->LPspi_bIsEndOfJob)
        {
            /* check for the channel switch */
            if ((0u == LPspi_pDev->LPspi_RemainingData) && (0u != LPspi_pDev->LPspi_RemainingChannelsTX))
            {
                /* reached the end of channel => move to the next channel */
                /* Increase Channel indexes */
                LPspi_pDev->LPspi_RemainingChannelsTX--;
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX++;
            
                if(SPI_MASTER == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode )
                {
                    /* prepare next channel transmission */
                    Spi_LPspi_ChannelTransferFifoInitTX(LPspi_pDev, *(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX));
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
            /* perform the next chunk transmission */
            Spi_LPspi_JobTransferFifoFill(LPspi_pDev);
        }
        else
        {
            /* Disable transmit interrupt for interrupt mode if end of job*/
            if(SPI_INTERRUPT_MODE == LPspi_pDev->LPspi_AsyncMode)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */                     
                REG_BIT_CLEAR32(LPSPI_IER_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset), LPSPI_IER_TDIE_MASK_U32);
            }
            /* Force the CS disabling because last data unit for the last channel of the Job is transmited */
            LPspi_u32Cmd = LPspi_u32Cmd & (~LPSPI_TCR_CONT_EN_U32); /* clear the continuous CS assertion */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPspi_u32TCRAddress, (LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
        }
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function performs the synchronous transmission for a sequence.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Sequence      Specifies the sequence for which we will have
*                              the synchronous transmission
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
* @implements Spi_LPspi_SyncTransmit_Activity
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    )
{
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcSequenceConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcJobConfig;
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev;
    VAR(Spi_JobType, AUTOMATIC) LPspi_JobsCount;
    VAR(Spi_JobType, AUTOMATIC) LPspi_Job;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcJobIndexList;
    VAR(Std_ReturnType, AUTOMATIC) LPspi_Status = (Std_ReturnType)E_OK;
    P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pJobState;
    VAR(uint32, AUTOMATIC) LPspi_u32JobCmd;
    VAR(uint32, AUTOMATIC) LPspi_u32CCR;
    VAR(Std_ReturnType, AUTOMATIC) LPspi_SyncJobStatus = (Std_ReturnType)E_NOT_OK;
    P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC, SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState;

    /* Get sequence configuration */
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];
    /* Get the number of jobs in the sequence */
    LPspi_JobsCount = LPspi_pcSequenceConfig->NumJobs;
    LPspi_pcJobIndexList = LPspi_pcSequenceConfig->pcJobIndexList;
    while (0u < LPspi_JobsCount)
    {
        /* Get the job id */
        LPspi_Job = *LPspi_pcJobIndexList;

        /* Set the job status as pending */
        LPspi_pJobState = &Spi_aSpiJobState[LPspi_Job];
        LPspi_pJobState->Result = SPI_JOB_PENDING;

        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[LPspi_Job];
        
        /* start job notification to assert the non-cs pin,
            when non-cs pin is used as chipselect*/
        if (NULL_PTR != LPspi_pcJobConfig->pfStartNotification)
        {
            LPspi_pcJobConfig->pfStartNotification();
        }
        else
        {
            /* Do nothing */
        }
        
        LPspi_pDev = &Spi_LPspi_aDeviceState[LPspi_pcJobConfig->HWUnit];

        /* mark HW unit as busy */
        *(LPspi_pDev->LPspi_pStatus) = SPI_BUSY;
        
        /* retrieve the TCR setting for the corresponding external device */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        if((uint8)TRUE == LPspi_pcJobConfig->ExternalDeviceAttrs.u8DualClk)
        {
            LPspi_u32JobCmd = LPspi_pcJobConfig->ExternalDeviceAttrs.u32TCR[Spi_LPspi_ClockMode];
            LPspi_u32CCR = LPspi_pcJobConfig->ExternalDeviceAttrs.u32CCR[Spi_LPspi_ClockMode];
        }
        else
        {
            LPspi_u32JobCmd = LPspi_pcJobConfig->ExternalDeviceAttrs.u32TCR[SPI_NORMAL];
            LPspi_u32CCR = LPspi_pcJobConfig->ExternalDeviceAttrs.u32CCR[SPI_NORMAL]; 
        }        
#else
        LPspi_u32JobCmd = LPspi_pcJobConfig->ExternalDeviceAttrs.u32TCR;
        LPspi_u32CCR = LPspi_pcJobConfig->ExternalDeviceAttrs.u32CCR;
#endif 
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(LPspi_pDev->LPspi_u32CCRAddress, LPspi_u32CCR);
        /* Update Synchronous transmission state  */
        Spi_LPspi_pSyncTransmitState = &Spi_LPspi_SyncTransmitState[LPspi_pcJobConfig->HWUnit];
        Spi_LPspi_pSyncTransmitState->LPspi_u32BaseAddress = LPspi_pDev->LPspi_u32BaseAddress;
        Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag=(uint8)FALSE;
        Spi_LPspi_pSyncTransmitState->LPspi_u32JobCmd = LPspi_u32JobCmd;
        /* iterate on all channels in job */
        Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX = LPspi_pcJobConfig->NumChannels;
        Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX = LPspi_pcJobConfig->NumChannels;
        Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListTX = LPspi_pcJobConfig->pcChannelIndexList;
        Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListRX = LPspi_pcJobConfig->pcChannelIndexList;
        /* Synchronous transmission for a Job*/
        LPspi_SyncJobStatus = Spi_LPspi_SyncTransmitJob(Spi_LPspi_pSyncTransmitState);
        /* release the HW unit */
        *(LPspi_pDev->LPspi_pStatus) = SPI_IDLE;
        if ((Std_ReturnType)E_OK == LPspi_SyncJobStatus)
        {
            /* Job is done set the status as OK */
            LPspi_pJobState->Result = SPI_JOB_OK;
            /* Perform job EndNotification (if there is one) */
            if (NULL_PTR != LPspi_pcJobConfig->pfEndNotification)
            {
                LPspi_pcJobConfig->pfEndNotification();
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* u32Timeout expired => transmission failed */
            /* set the remaining job status (including the current one) as FAILED */
            do
            {
                /* Set the job status as FAILED */
                Spi_aSpiJobState[*LPspi_pcJobIndexList].Result = SPI_JOB_FAILED;
                /* Update pointer position for pcJobConfig */
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                LPspi_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[*LPspi_pcJobIndexList];
                /* Perform job EndNotification (if there is one) */
                if (NULL_PTR != LPspi_pcJobConfig->pfEndNotification)
                {
                    LPspi_pcJobConfig->pfEndNotification();
                }
                else
                {
                    /* Do nothing */
                }
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                LPspi_pcJobIndexList++;
                LPspi_JobsCount--;
            } while (0u < LPspi_JobsCount);
            LPspi_JobsCount = 1u;  /* needed to end correctly the outer loop */
            LPspi_Status = (Std_ReturnType)E_NOT_OK;
        }
        /* iterate to next job in sequence */
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */    
        LPspi_pcJobIndexList++;
        LPspi_JobsCount--;
    } /* while (JobsCount > 0u) */

    if ((Std_ReturnType)E_OK != LPspi_Status)
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    else
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            /* Do nothing */
        }
#endif 
    }
    return LPspi_Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function performs the synchronous transmission for a job.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Spi_LPspi_pSyncTransmitState   Specifies which state transmission data of job and channel
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*/
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmitJob
(
    P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState
)
{
    VAR(Spi_ChannelType, AUTOMATIC) LPspi_ChannelTX=0u;
    VAR(Spi_ChannelType, AUTOMATIC) LPspi_ChannelRX=0u;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelAttributesCfgTX = NULL_PTR;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelAttributesCfgRX = NULL_PTR;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfigTX;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfigRX;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelState;
    VAR(uint8, AUTOMATIC) LPspi_FirstChannelOfJobFlag = (uint8)TRUE;
    VAR(uint32, AUTOMATIC) LPspi_u32BaseAddress = Spi_LPspi_pSyncTransmitState->LPspi_u32BaseAddress;
    VAR(uint32, AUTOMATIC) LPspi_u32Timeout = SPI_TIMEOUT_COUNTER; 
    VAR(Std_ReturnType, AUTOMATIC) LPspi_SyncJobStatus = (Std_ReturnType)E_OK;
    VAR(Std_ReturnType, AUTOMATIC) LPspi_TransStatus = (Std_ReturnType)E_NOT_OK;
    
    while((Spi_ChannelType)0 < Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX)
    {
        Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX--;
        /* Get the channel ID & configuration */
        LPspi_ChannelTX = *Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListTX;
        /* Get Channel Attributes */
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcChannelAttributesCfgTX = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelTX];
        /* Update the channel attributions */
        Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd = Spi_LPspi_pSyncTransmitState->LPspi_u32JobCmd | LPspi_pcChannelAttributesCfgTX->u32CMD;
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcChannelConfigTX = &Spi_pcSpiConfigPtr->pcChannelConfig[LPspi_ChannelTX];
        LPspi_pChannelState = LPspi_pcChannelConfigTX->pChannelState;
        Spi_LPspi_pSyncTransmitState->LPspi_DefaultTransmitValue = LPspi_pcChannelConfigTX->DefaultTransmitValue;
        Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthTX = LPspi_pcChannelAttributesCfgTX->u8DataWidth;
        /* set TCR register */
        /**
        * @note The call is blocking till the HWUnit exits
        *       the running state.
        */
        if(0u != (Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd & LPSPI_TCR_CONT_EN_U32 & LPSPI_TCR_RESERVED_MASK_U32))
        {
            if((uint8)TRUE == LPspi_FirstChannelOfJobFlag)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPSPI_BASEADDR2TCR_ADDR32(LPspi_u32BaseAddress), (Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPSPI_BASEADDR2TCR_ADDR32(LPspi_u32BaseAddress), (Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
        }
        /* retrieve TX buffers and the transmitted length */
        if (LPspi_pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferTX = NULL_PTR;
        }
        else
        {
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferTX = LPspi_pcChannelConfigTX->pcBufferDescriptor->pBufferTX;
        }

        Spi_LPspi_pSyncTransmitState->LPspi_LengthTX = LPspi_pChannelState->Length;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesCfgTX->u8DataWidth)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_LengthTX /= 2u;
        }
        else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesCfgTX->u8DataWidth)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_LengthTX /= 4u;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesCfgTX->u8DataWidth)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_LengthTX /= 2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* if the channel is the first of Job then retrieve RX buffers and the received length */
        if((uint8)TRUE == LPspi_FirstChannelOfJobFlag)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX--;
            /* Get the channel ID & configuration */
            LPspi_ChannelRX = *Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListRX;
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            LPspi_pcChannelAttributesCfgRX = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelRX];
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            LPspi_pcChannelConfigRX = &Spi_pcSpiConfigPtr->pcChannelConfig[LPspi_ChannelRX];
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferRX = LPspi_pcChannelConfigRX->pcBufferDescriptor->pBufferRX;
            Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX = LPspi_pcChannelAttributesCfgRX->u8DataWidth;
            Spi_LPspi_pSyncTransmitState->LPspi_LengthRX = Spi_LPspi_pSyncTransmitState->LPspi_LengthTX;
        }
        else
        {
            /* Do nothing */
        }
        LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
        /* while there is still something to read or to write */
        /* a kind of: while ((LengthTX > 0) || (LengthRX > 0)) */
        while(
                ((Spi_LPspi_pSyncTransmitState->LPspi_LengthTX>0u) && (Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag==(uint8)FALSE)) ||
                ((Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag==(uint8)TRUE) && ((Spi_LPspi_pSyncTransmitState->LPspi_LengthTX>0u) || (Spi_LPspi_pSyncTransmitState->LPspi_LengthRX>0u)))
             )
        {
            /* --------- Transmit ---------- */
            LPspi_TransStatus = Spi_LPspi_SyncTransmitTX(Spi_LPspi_pSyncTransmitState);
            if((Std_ReturnType)E_OK == LPspi_TransStatus)
            {
                /* reset the timeout */
                LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
            }
            else
            {
                /* Do nothing */
            }
           /* --------- Receive ---------- */
            LPspi_TransStatus = Spi_LPspi_SyncTransmitRX(Spi_LPspi_pSyncTransmitState, LPSPI_SYNCTRANSMIT);
            if((Std_ReturnType)E_OK == LPspi_TransStatus)
            {
                /* reset the timeout */
                LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
            }
            else
            {
                /* Do nothing */
            }
            LPspi_u32Timeout--;
            /* end the loop if timeout expired */
            if (0u == LPspi_u32Timeout)
            {
                /* force the end of the outer loop too */
                Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX = 0U;
                Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX = 0U;
                LPspi_SyncJobStatus = (Std_ReturnType)E_NOT_OK;
                break; 
            }
            else
            {
                /* Do nothing */
            }
        } /* while ((LengthTX > 0) || (LengthRX > 0)) */
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListTX++;
        LPspi_FirstChannelOfJobFlag=(uint8)FALSE;
    } /* while (ChannelsCountTX) */

    return LPspi_SyncJobStatus;
}
#endif
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   This function starts the synchronous transmission for optimized sequences having only one job.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*          Same behavior as Spi_SyncTransmit(), but the initialization time and
*          data preparation time are optimized.
*
* @param[in]     pcSequence     Keep the cached information for "one job sequence"
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON
*
* @implements Spi_LPspi_SyncTransmit_Fast_Activity
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmit_Fast
    (
        P2CONST(Spi_LPspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    )
{
    P2VAR(Spi_LPspi_ChannelCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelTX;    
     P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pJobState = pcSequence->LPspi_pJobState;
    VAR(uint32, AUTOMATIC) LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) LPspi_u32JobCmd;
    VAR(uint32, AUTOMATIC) LPspi_u32CCR;
    VAR(Std_ReturnType, AUTOMATIC) LPspi_Status;
    VAR(uint8, AUTOMATIC) LPspi_FirstChannelOfJobFlag=(uint8)TRUE;
    VAR(Std_ReturnType, AUTOMATIC) LPspi_TransStatus = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) LPspi_u32BaseAddress = pcSequence->LPspi_u32BaseAddress;
    VAR(uint32, AUTOMATIC) LPspi_u32Cmd;
    P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC, SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState = &Spi_LPspi_SyncTransmitState[pcSequence->LPspi_HWUnit];
    
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /* get the CMD to be transmitted */
    LPspi_u32JobCmd = pcSequence->LPspi_u32JobCMD[Spi_LPspi_ClockMode];
    LPspi_u32CCR = pcSequence->LPspi_u32JobCCR[Spi_LPspi_ClockMode];
#else
    /* get the CMD to be transmitted */
    LPspi_u32JobCmd = pcSequence->LPspi_u32JobCMD;
    LPspi_u32CCR = pcSequence->LPspi_u32JobCCR;
#endif
    /* set the CCR to be transmitted */
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_BASEADDR2CCR_ADDR32(LPspi_u32BaseAddress), LPspi_u32CCR);
    /* Set the job status as pending and mark HW Unit as busy */
    LPspi_pJobState->Result = SPI_JOB_PENDING;
    *(pcSequence->LPspi_pJobStatus) = SPI_BUSY;
    /* iterate on all channels in job */
    LPspi_pChannelTX = pcSequence->LPspi_pChannels;
    Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag = (uint8)FALSE;
    Spi_LPspi_pSyncTransmitState->LPspi_u32BaseAddress = LPspi_u32BaseAddress;
    Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX = pcSequence->LPspi_pChannels;
    Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX = pcSequence->LPspi_NumChannels;
    Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX = pcSequence->LPspi_NumChannels;
    while ((Spi_ChannelType)0 < Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX)
    {
        Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX--;
        Spi_LPspi_pSyncTransmitState->LPspi_DefaultTransmitValue = LPspi_pChannelTX->LPspi_DefaultTransmitValue;
        Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthTX = LPspi_pChannelTX->LPspi_u8DataWidth;
        /* set TCR register */
        /**
        * @note The call is blocking till the HWUnit exits
        *       the running state.
        */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        LPspi_u32Cmd = LPspi_u32JobCmd | LPspi_pChannelTX->LPspi_u32TCR[Spi_LPspi_ClockMode];
#else
        LPspi_u32Cmd = LPspi_u32JobCmd | LPspi_pChannelTX->LPspi_u32TCR;
#endif
        Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd = LPspi_u32Cmd;
        if(0u != (LPspi_u32Cmd & LPSPI_TCR_CONT_EN_U32 & LPSPI_TCR_RESERVED_MASK_U32))
        {
            if((uint8)TRUE == LPspi_FirstChannelOfJobFlag)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(LPSPI_BASEADDR2TCR_ADDR32(LPspi_u32BaseAddress), LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32);
            }
        }
        else
        {
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPSPI_BASEADDR2TCR_ADDR32(LPspi_u32BaseAddress), LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32);
        }
        /* retrieve TX buffers and the transmitted length */
        if (LPspi_pChannelTX->LPspi_pState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferTX = NULL_PTR;
        }
        else
        {
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferTX = LPspi_pChannelTX->LPspi_pcBufferDescriptor->pBufferTX;
        }
        Spi_LPspi_pSyncTransmitState->LPspi_LengthTX = LPspi_pChannelTX->LPspi_pState->Length;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == LPspi_pChannelTX->LPspi_u8DataWidth)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_LengthTX /= 2u;
        }
        else if (SPI_DATA_WIDTH_32 == LPspi_pChannelTX->LPspi_u8DataWidth)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_LengthTX /= 4u;
        }
        else
        {
            /* Do nothing */
        }
        #else
        if (SPI_DATA_WIDTH_32 == LPspi_pChannelTX->LPspi_u8DataWidth)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_LengthTX /= 2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* if the channel is the first of Job then retrieve RX buffers and the received length */
        if((uint8)TRUE == LPspi_FirstChannelOfJobFlag)
        {
            Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX--;
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferRX = Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX->LPspi_pcBufferDescriptor->pBufferRX;
            Spi_LPspi_pSyncTransmitState->LPspi_LengthRX = Spi_LPspi_pSyncTransmitState->LPspi_LengthTX;
            Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX = Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX->LPspi_u8DataWidth;
        }
        LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
        /* while there is still something to read or to write */
        /* a kind of: while ((LPspi_LengthTX > 0) || (LPspi_LengthRX > 0)) */
        while(
                ((Spi_LPspi_pSyncTransmitState->LPspi_LengthTX>0u) && (Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag==(uint8)FALSE)) ||
                ((Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag==(uint8)TRUE) && ((Spi_LPspi_pSyncTransmitState->LPspi_LengthTX>0u) || (Spi_LPspi_pSyncTransmitState->LPspi_LengthRX>0u)))
             )
        {
                /* --------- Transmit ---------- */
                LPspi_TransStatus = Spi_LPspi_SyncTransmitTX(Spi_LPspi_pSyncTransmitState);
                if((Std_ReturnType)E_OK == LPspi_TransStatus)
                {
                    /* reset the timeout */
                    LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
                }
                else
                {
                    /* Do nothing */
                }
               /* --------- Receive ---------- */
                LPspi_TransStatus = Spi_LPspi_SyncTransmitRX(Spi_LPspi_pSyncTransmitState, LPSPI_SYNCTRANSMIT_FAST);
                if((Std_ReturnType)E_OK == LPspi_TransStatus)
                {
                    /* reset the timeout */
                    LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
                }
                else
                {
                    /* Do nothing */
                }
           
           LPspi_u32Timeout--;
            /* end the loop if timeout expired */
            if (0u == LPspi_u32Timeout)
            {
                /* force the end of the outer loop too */
                Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX = 0U;
                Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX = 0U;
                break; 
            }
            else
            {
                /* Do nothing */
            }
        } /* while ((LengthTX > 0) || (LengthRX > 0)) */
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        LPspi_pChannelTX++;
        LPspi_FirstChannelOfJobFlag=(uint8)FALSE;
    } /* while (ChannelsCount) */
    /* release the HW Unit */
    *(pcSequence->LPspi_pJobStatus) = SPI_IDLE;
    if (0u < LPspi_u32Timeout)
    {
        /* Job is done set the status as OK */
        LPspi_pJobState->Result = SPI_JOB_OK;
        LPspi_Status = (Std_ReturnType)E_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            /* Do nothing */
        }
#endif 
    }
    else
    {
        /* u32Timeout expired => transmission failed */
        /* set the Job status as FAILED */
        LPspi_pJobState->Result = SPI_JOB_FAILED;
        LPspi_Status = (Std_ReturnType)E_NOT_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    return LPspi_Status;
}
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function fills the LPSPI TX FIFO.
* @details This function fills the LPSPI FIFO Transmit buffer with
*          data assigned or transmit the default buffer values.   
*          This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Spi_LPspi_pSyncTransmitState   Specifies which state transmission data of job and channel
* 
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmitTX
(
    P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState
)
{
    VAR(Std_ReturnType, AUTOMATIC) LPspi_Status = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) LPspi_u32FSR;
    VAR(uint32, AUTOMATIC) LPspi_u32BaseAddress = Spi_LPspi_pSyncTransmitState->LPspi_u32BaseAddress;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LPspi_pBufferTX = Spi_LPspi_pSyncTransmitState->LPspi_pBufferTX;
     VAR(uint32, AUTOMATIC) LPspi_u32TempXferData;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) LPspi_pu16BufferFullTX;
    P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LPspi_pu32BufferFullTX;
#endif
    VAR(uint8, AUTOMATIC) LPspi_u8DataWidthTX = Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthTX;

    /* --------- Transmit ---------- */
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    LPspi_u32FSR=REG_READ32(LPSPI_BASEADDR2FSR_ADDR32(LPspi_u32BaseAddress));
    /* there is something to write and Transmit FIFO not full */
    if (
         (Spi_LPspi_pSyncTransmitState->LPspi_LengthTX > 0u) &&
         ((LPspi_u32FSR & LPSPI_FSR_TXCOUNT_MASK_U32)<SPI_FIFO_SIZE)
       )
    {
        Spi_LPspi_pSyncTransmitState->LPspi_LengthTX--;
        /* prepare the data to be transmitted */

        if (NULL_PTR == LPspi_pBufferTX)
        {
            /* Get default data if TX buffer is NULL_PTR */
            LPspi_u32TempXferData = Spi_LPspi_pSyncTransmitState->LPspi_DefaultTransmitValue;
        }
        else
        {
            /* Read transmit data */
            #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if (SPI_DATA_WIDTH_16 == LPspi_u8DataWidthTX)
            {
                /*
                 * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed
                 * between a pointer to object type and a different pointer to object
                 * type.
                 */
                LPspi_pu16BufferFullTX = (uint16 *) LPspi_pBufferTX;
                LPspi_u32TempXferData = (*LPspi_pu16BufferFullTX);
                /*
                 * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                 */
                LPspi_pBufferTX++;
            }
            else if (SPI_DATA_WIDTH_32 == LPspi_u8DataWidthTX)
            {
                /*
                * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a 
                *       pointer to object type and a different pointer to object type.
                */
                LPspi_pu32BufferFullTX = (uint32 *) LPspi_pBufferTX;
                LPspi_u32TempXferData = (*LPspi_pu32BufferFullTX);
                /*
                * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                LPspi_pBufferTX += 3u;
            }
            else
            {
                /*
                 * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed
                 *  between a pointer type and an integral type.
                 */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32TempXferData = (*LPspi_pBufferTX);
            }
            #else
            if (SPI_DATA_WIDTH_32 == LPspi_u8DataWidthTX)
            {
                #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                    *  pointer to object type and a different pointer to object type.
                    */
                    LPspi_u32TempXferData = (uint32)(*LPspi_pBufferTX) | ((uint32)(*(LPspi_pBufferTX+1u)) << 16u);
                #else
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    * @violates @ref Spi_LPspi_c_REF_4 A cast should not be performed between a
                    *  pointer to object type and a different pointer to object type.
                    */
                    LPspi_u32TempXferData = ((uint32)(*LPspi_pBufferTX) << 16u) | (uint32)(*(LPspi_pBufferTX+1u));
                #endif
                /*
                 * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                 *       the only allowed form of pointer arithmetic.
                 */
                LPspi_pBufferTX++;
            }
            else
            {
                /*
                 * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed
                 * between a pointer type and an integral type.
                 */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                LPspi_u32TempXferData = (*LPspi_pBufferTX);
            }
            #endif
            /*
            * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            LPspi_pBufferTX++;
        }
        /* update LPspi_pBufferTX */
        Spi_LPspi_pSyncTransmitState->LPspi_pBufferTX = LPspi_pBufferTX;
        /* Transmit the data */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(LPSPI_BASEADDR2TDR_ADDR32(LPspi_u32BaseAddress), LPspi_u32TempXferData);
        /* a kind of: if ((0u == LengthTX) && (0u == ChannelsCount) )*/
        if (0u == (Spi_LPspi_pSyncTransmitState->LPspi_LengthTX | Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountTX))
        {
            Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag=(uint8)TRUE;
        }
        else
        {
            /* Do nothing */
        }
        LPspi_Status = (Std_ReturnType)E_OK;
    }
    else
    {
        /* Do nothing */
    }
    return LPspi_Status;  
}
#endif
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function drains the LPSPI RX FIFO.
* @details This function retrieves the received data from LPSPI FIFO.
*          This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Spi_LPspi_pSyncTransmitState   Specifies which state transmission data of job and channel
*                LPspi_u8Sync   Specifies which this function has called by
*                               Spi_LPspi_SyncTransmit()            : LPSPI_SYNCTRANSMIT
*                               or Spi_LPspi_SyncTransmit_Fast()    : LPSPI_SYNCTRANSMIT_FAST
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LPspi_SyncTransmitRX
(
    P2VAR(Spi_LPspi_SyncStateType, AUTOMATIC,SPI_APPL_DATA) Spi_LPspi_pSyncTransmitState,
    VAR(uint8, AUTOMATIC) LPspi_u8Sync
)
{
    VAR(Std_ReturnType, AUTOMATIC) LPspi_Status = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) LPspi_u32FSR;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LPspi_pBufferRX = Spi_LPspi_pSyncTransmitState->LPspi_pBufferRX;
     P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelAttributesCfgRX = NULL_PTR;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfigRX;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelState;
    VAR(Spi_ChannelType, AUTOMATIC) LPspi_ChannelRX=0u;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) LPspi_pu16BufferFullRX;
    P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA) LPspi_pu32BufferFullRX;
#else
    VAR(uint32, AUTOMATIC) LPspi_u32BufferFullRX;
#endif
    VAR(uint32, AUTOMATIC) LPspi_u32TCR;
    VAR(uint32, AUTOMATIC) LPspi_u32BaseAddress = Spi_LPspi_pSyncTransmitState->LPspi_u32BaseAddress;
    VAR(uint8, AUTOMATIC) LPspi_u8DataWidthRX = Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX;
    
    /* --------- Receive ---------- */
    /* there is still something to read and Receive FIFO has data */
    if (0u < Spi_LPspi_pSyncTransmitState->LPspi_LengthRX)
    {
         /*
         * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
         *     type and an integral type.
         */
         /*
         * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
         */
         LPspi_u32FSR = REG_READ32(LPSPI_BASEADDR2FSR_ADDR32(LPspi_u32BaseAddress));
         if (0u < (LPspi_u32FSR & LPSPI_FSR_RXCOUNT_MASK_U32))
         {
             Spi_LPspi_pSyncTransmitState->LPspi_LengthRX--;
            /* Read Data from RX FIFO */
            if (NULL_PTR == LPspi_pBufferRX)
            {
                /* discard data if RX buffer is NULL_PTR */
                /*
                * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                */
                /*
                * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                Spi_LPspi_u32ReadDiscard = REG_READ32(LPSPI_BASEADDR2RDR_ADDR32(LPspi_u32BaseAddress));
            }
            else
            {
                #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if (SPI_DATA_WIDTH_16 == LPspi_u8DataWidthRX)
                {
                     /*
                     * @violates @ref Spi_LPspi_c_REF_4 A cast should not be
                     * performed between a pointer
                     *       to object type and a different pointer to object type.
                     */
                     LPspi_pu16BufferFullRX = (uint16 *) LPspi_pBufferRX;
                     /*
                     * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                     *       the only allowed form of pointer arithmetic.
                     */
                     LPspi_pBufferRX += 2u;
                     /*
                     * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                     *     type and an integral type.
                     */
                     /*
                     * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                     */
                    *LPspi_pu16BufferFullRX = (uint16)REG_READ32(LPSPI_BASEADDR2RDR_ADDR32(LPspi_u32BaseAddress));                         
                }
                else if (SPI_DATA_WIDTH_32 == LPspi_u8DataWidthRX)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_4 A cast should not be
                    * performed between a pointer
                    *       to object type and a different pointer to object type.
                    */
                    LPspi_pu32BufferFullRX = (uint32 *) LPspi_pBufferRX;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRX += 4u;               
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    *LPspi_pu32BufferFullRX = REG_READ32(LPSPI_BASEADDR2RDR_ADDR32(LPspi_u32BaseAddress));
                }
                else
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                     *LPspi_pBufferRX = (Spi_DataBufferType)REG_READ32(LPSPI_BASEADDR2RDR_ADDR32(LPspi_u32BaseAddress));
                     /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRX++;
                }
                #else
                if (SPI_DATA_WIDTH_32 == LPspi_u8DataWidthRX)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    LPspi_u32BufferFullRX = (uint32)REG_READ32(LPSPI_BASEADDR2RDR_ADDR32(LPspi_u32BaseAddress));
                    #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                        *LPspi_pBufferRX = (uint16)(LPspi_u32BufferFullRX & (uint32)0x0000FFFFu);
                        /*
                        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        *(LPspi_pBufferRX+1u) = (uint16)(LPspi_u32BufferFullRX >> 16u);
                    #else
                        *LPspi_pBufferRX = (uint16)(LPspi_u32BufferFullRX >> 16u);
                        /*
                        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        *(LPspi_pBufferRX+1u) = (uint16)(LPspi_u32BufferFullRX & (uint32)0x0000FFFFu);
                    #endif 
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRX += 2u;
                }
                else
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    */
                    /*
                    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                     *LPspi_pBufferRX = (Spi_DataBufferType)REG_READ32(LPSPI_BASEADDR2RDR_ADDR32(LPspi_u32BaseAddress));
                     /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    LPspi_pBufferRX++;
                }                        
                #endif
            }
            /* update LPspi_pBufferRX */
            Spi_LPspi_pSyncTransmitState->LPspi_pBufferRX = LPspi_pBufferRX;
            
            if((Spi_LPspi_pSyncTransmitState->LPspi_LengthRX == 0u) && (Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX > 0u))
            {
                /* Update channel count RX */
                Spi_LPspi_pSyncTransmitState->LPspi_ChannelsCountRX--;
                if(LPSPI_SYNCTRANSMIT == LPspi_u8Sync)
                {
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListRX++;
                    /* Get the channel ID & configuration */
                    LPspi_ChannelRX = *Spi_LPspi_pSyncTransmitState->LPspi_pcChannelIndexListRX;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    LPspi_pcChannelAttributesCfgRX = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[LPspi_ChannelRX];
                    Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX = LPspi_pcChannelAttributesCfgRX->u8DataWidth;
                    LPspi_u8DataWidthRX = Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX;
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    LPspi_pcChannelConfigRX = &Spi_pcSpiConfigPtr->pcChannelConfig[LPspi_ChannelRX];
                    LPspi_pChannelState = LPspi_pcChannelConfigRX->pChannelState;
                    Spi_LPspi_pSyncTransmitState->LPspi_LengthRX = LPspi_pChannelState->Length;
                    Spi_LPspi_pSyncTransmitState->LPspi_pBufferRX = LPspi_pcChannelConfigRX->pcBufferDescriptor->pBufferRX;
                }
                else
                {
                    #if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
                    /*
                    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX++;
                    /* retrieve RX buffers and the received length */
                    Spi_LPspi_pSyncTransmitState->LPspi_LengthRX = Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX->LPspi_pState->Length;
                    Spi_LPspi_pSyncTransmitState->LPspi_pBufferRX = Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX->LPspi_pcBufferDescriptor->pBufferRX; 
                    Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX = Spi_LPspi_pSyncTransmitState->LPspi_pChannelRX->LPspi_u8DataWidth;
                    LPspi_u8DataWidthRX = Spi_LPspi_pSyncTransmitState->LPspi_u8DataWidthRX;
                    #endif
                }
                #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if (SPI_DATA_WIDTH_16 == LPspi_u8DataWidthRX)
                {
                    Spi_LPspi_pSyncTransmitState->LPspi_LengthRX /= 2u;
                }
                else if (SPI_DATA_WIDTH_32 == LPspi_u8DataWidthRX)
                {
                    Spi_LPspi_pSyncTransmitState->LPspi_LengthRX /= 4u;
                }
                else
                {
                    /* Do nothing */
                }
                #else
                if (SPI_DATA_WIDTH_32 == LPspi_u8DataWidthRX)
                {
                    Spi_LPspi_pSyncTransmitState->LPspi_LengthRX /= 2u;
                }
                else
                {
                    /* Do nothing */
                }
                #endif
            }
            LPspi_Status = (Std_ReturnType)E_OK;
        }
        else
        {
            /* Do nothing */
        }
        /* clear the continous CS assertion */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        LPspi_u32TCR=REG_READ32(LPSPI_BASEADDR2TCR_ADDR32(LPspi_u32BaseAddress));
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        LPspi_u32FSR = REG_READ32(LPSPI_BASEADDR2FSR_ADDR32(LPspi_u32BaseAddress));
        if(
             ((uint8)TRUE == Spi_LPspi_pSyncTransmitState->LPspi_EndOfJobFlag) &&
             (0u != (LPspi_u32TCR & LPSPI_TCR_CONT_EN_U32 & LPSPI_TCR_RESERVED_MASK_U32)) &&
             (0u == LPspi_u32FSR)
          )
        {
            Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd &= (~LPSPI_TCR_CONT_EN_U32);
            /* clear the continuous CS assertion */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPSPI_BASEADDR2TCR_ADDR32(LPspi_u32BaseAddress), Spi_LPspi_pSyncTransmitState->LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32);
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }
    return LPspi_Status; 
}
#endif
/*================================================================================================*/
/**
* @brief   Initialize DMA related fields for a LPSPI unit.
* @details Initialize DMA TCD descriptors static fields.
*
* @param[in]     HWUnit      Specifies which LPSPI peripheral is used.
* @param[in]     LPspi_pDev     LLD instance of the given LPSPI peripheral.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_InitDma \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    ) \
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;

    LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
    /* Get the adress of the TCD for the channels Tx and Rx */
    LPspi_pDev->LPspi_pu32TxDmaTcd = Mcl_DmaGetChannelTcdAddress(LPspi_pcHWUnitConfig->u8TxDmaChannel);
    LPspi_pDev->LPspi_pu32RxDmaTcd = Mcl_DmaGetChannelTcdAddress(LPspi_pcHWUnitConfig->u8RxDmaChannel);

    /* configure TX Channel 1 to write u32TxDmaBuffer (32bits) to LPSPI TDR */
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_LPspi_DmaCfgDesc.u32saddr = 0u; /* src address read - will be updated later*/

    Spi_LPspi_DmaCfgDesc.u32daddr = LPspi_pDev->LPspi_u32TDRAddress;/* dest address */ 
    
    Spi_LPspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_4BYTES; /* 4bytes dest transfer size */
    Spi_LPspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_4BYTES; /* 4bytes src transfer size */
    Spi_LPspi_DmaCfgDesc.u32num_bytes = 4u; /* bytes to transfer */  
    
    Spi_LPspi_DmaCfgDesc.u32soff  = 0u;     /* no src offset */
    Spi_LPspi_DmaCfgDesc.u32doff  = 0u;     /* no dest offset */ 
    
    Spi_LPspi_DmaCfgDesc.u32smod  = 0u;     /* no source address modulo */
    Spi_LPspi_DmaCfgDesc.u32dmod  = 0u;     /* no dest address modulo   */ 
          
    Spi_LPspi_DmaCfgDesc.u32iter  = 1u;     /* iteration count - will be updated later */

    Mcl_DmaConfigTcd(LPspi_pDev->LPspi_pu32TxDmaTcd, &Spi_LPspi_DmaCfgDesc);  
    Mcl_DmaTcdSetFlags(LPspi_pDev->LPspi_pu32TxDmaTcd, (uint8)DMA_TCD_DISABLE_REQ_U32 );       
    
    /* setup RX DMA channel */
    Spi_LPspi_DmaCfgDesc.u32saddr = LPspi_pDev->LPspi_u32RDRAddress; /* data only read */
    Spi_LPspi_DmaCfgDesc.u32daddr = 0u;  /* dest address => will be updated later */ 
    
    Spi_LPspi_DmaCfgDesc.u32soff  = 0u;  /* src offset */
    Spi_LPspi_DmaCfgDesc.u32doff  = 0u;     /* no dest offset */ 
    
    Spi_LPspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_4BYTES; /* 4bytes dest transfer size */
    Spi_LPspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_4BYTES; /* 4bytes src transfer size */
    Spi_LPspi_DmaCfgDesc.u32num_bytes = 4u; /* bytes to transfer */ 
    
    Spi_LPspi_DmaCfgDesc.u32smod  = 0u;  /* no source address modulo */
    Spi_LPspi_DmaCfgDesc.u32dmod  = 0u;  /* no dest address modulo   */
    
    Spi_LPspi_DmaCfgDesc.u32iter  = 1u;  /* beg maj iter cnt => will be updated later */

    /* !!!! Not able to set the e-link */
    Mcl_DmaConfigTcd(LPspi_pDev->LPspi_pu32RxDmaTcd, &Spi_LPspi_DmaCfgDesc);
    Mcl_DmaTcdSetFlags(LPspi_pDev->LPspi_pu32RxDmaTcd,  (uint8)DMA_TCD_DISABLE_REQ_U32);  

}
#endif /* (SPI_DMA_USED == STD_ON) */

/*================================================================================================*/
/**
* @brief   Configures DMA interrupts for the Rx channel.
* @details Activate RX channel interrupt in interrupt mode or disable then
*          in polling mode.
*
* @param[in]     LPspi_pDev     LLD instance of the given LPSPI peripheral.
* @param[in]     AsyncMode   Operation mode (SPI_INTERRUPT_MODE | SPI_POLLING_MODE).
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_DmaIrqConfig \
    ( \
        P2CONST(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) LPspi_pDev, \
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode \
    ) \
{
    /* start RX before TX! */
    if (SPI_INTERRUPT_MODE == AsyncMode)
    {
        Mcl_DmaTcdSetIntMaj(LPspi_pDev->LPspi_pu32RxDmaTcd);
        Mcl_DmaTcdSetIntMaj(LPspi_pDev->LPspi_pu32TxDmaTcd);
    }
    else
    {
        Mcl_DmaTcdClearIntMaj(LPspi_pDev->LPspi_pu32TxDmaTcd);
        Mcl_DmaTcdClearIntMaj(LPspi_pDev->LPspi_pu32RxDmaTcd);
    }
}
#endif /* (SPI_DMA_USED == STD_ON) */

/**
* @param[in]     LPspi_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferDmaInitTX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    ) \
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelAttributesConfig;
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelState = LPspi_pcChannelConfig->pChannelState;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LPspi_pBufferTX;
     VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_FramesCount;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) LPspi_pTxTcdAddr = LPspi_pDev->LPspi_pu32TxDmaTcd;
    VAR(uint32, AUTOMATIC) LPspi_u32Cmd;
    VAR(uint32, AUTOMATIC) LPspi_u32FCR;
    
    /* Set the TCR parameters for this channel */
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[Channel];
    /* Get the current command for this channel */
    LPspi_u32Cmd = (LPspi_pDev->LPspi_u32ExternalDeviceTCR | LPspi_pcChannelAttributesConfig->u32CMD|LPSPI_TCR_BYSW_EN_U32);
    /* Store the current command for this channel */
    LPspi_pDev->LPspi_u32CurrentCmd = LPspi_u32Cmd;
    /* Get the configuration of FIFO for this channel */
    LPspi_u32FCR = (LPspi_pcChannelAttributesConfig->u32FCR);
    /* set TCR register */
    /**
    * @remarks The call is blocking till the HWUnit exits the running state.
    */
    if(0u != (LPspi_u32Cmd & LPSPI_TCR_CONT_EN_U32 & LPSPI_TCR_RESERVED_MASK_U32))
    {
         if((uint8)TRUE == LPspi_pDev->LPspi_FirstChannelOfJobFlag)
         {
              /*
              * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
              *     type and an integral type.
              */
              /*
              * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
              */
              REG_WRITE32(LPspi_pDev->LPspi_u32TCRAddress, (LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
              LPspi_pDev->LPspi_FirstChannelOfJobFlag=(uint8)FALSE;
         }
    }
    else
    {
          /*
          * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
          *     type and an integral type.
          */
          /*
          * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
          */
          REG_WRITE32(LPspi_pDev->LPspi_u32TCRAddress, (LPspi_u32Cmd & LPSPI_TCR_RESERVED_MASK_U32));
    }
    /* set FCR register */
    /**
    * @note The call is blocking till the HWUnit exits the running state.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(LPSPI_BASEADDR2FCR_ADDR32(LPspi_pDev->LPspi_u32BaseAddress), (LPspi_u32FCR & LPSPI_FCR_RESERVED_MASK_U32));

    LPspi_FramesCount = LPspi_pChannelState->Length;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 2u;
    }
    else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 4u;
    }
    else
    {
        /* Do nothing */
    }
#else
    if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 4u;
    }
    else if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 2u;
    }
    else
    {
        /* Do nothing */
    }
#endif

    /* identify the TX buffers and update them into the DMA TCDs */
    if (0u != (LPspi_pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
    {
        /* update source address into the DMA TCD */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSaddr(LPspi_pTxTcdAddr, (uint32)(&LPspi_pcChannelConfig->DefaultTransmitValue));

        /* overwrite the default src next offset */
        /* 1 bytes src transfer size, 1 bytes dest transfer size */
        /* 1 bytes src offset */
        Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)0u);
        Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
        Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
        /* dest address */
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
        #else
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress+3u);
        #endif
        /* 1 bytes to transfer */
        Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        Mcl_DmaTcdSetDoff(LPspi_pTxTcdAddr, (sint16)0u);
    }
    else
    {
        LPspi_pBufferTX = LPspi_pcChannelConfig->pcBufferDescriptor->pBufferTX;

        /* configure TX Channel 1 to write data frames (8 or 16bits - depending on Spy_DataType) to
           u32TxDmaBuffer */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSaddr(LPspi_pTxTcdAddr, (uint32)LPspi_pBufferTX);

    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* 2 bytes src offset */
            Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress+2u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            #endif
            /* 2 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* 4 bytes src offset */
            Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            /* 4 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* 1 bytes src offset */
            Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)1u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress+3u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            #endif
            /* 1 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
    #else
        if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* 4 bytes src offset */
            Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            /* dest address */
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            /* 4 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* 2 bytes src offset */
            Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            #endif
            /* 2 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* 1 bytes src offset */
            Mcl_DmaTcdSetSoff(LPspi_pTxTcdAddr, (sint16)1u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress+3u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetDaddr(LPspi_pTxTcdAddr, LPspi_pDev->LPspi_u32TDRAddress);
            #endif
            /* 1 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(LPspi_pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
    #endif
        Mcl_DmaTcdSetDoff(LPspi_pTxTcdAddr, (sint16)0u);
    }

    /* get the number of frames to be sent through DMA */
    if ( LPSPI_DMA_MAX_LINKED_ITER_CNT < LPspi_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        LPspi_pDev->LPspi_RemainingData = LPspi_FramesCount - LPSPI_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_RemainingData *= 2u;
        }
        else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_RemainingData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_RemainingData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        LPspi_FramesCount = LPSPI_DMA_MAX_LINKED_ITER_CNT;
        Mcl_DmaTcdSetIterCount(LPspi_pTxTcdAddr, (uint16)(LPspi_FramesCount)); 
    }
    else
    {
        Mcl_DmaTcdSetIterCount(LPspi_pTxTcdAddr, (uint16)(LPspi_FramesCount)); 
        LPspi_pDev->LPspi_RemainingData = 0u;
    }
    /* start TX! */
    LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;

    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(LPspi_pcHWUnitConfig->u8TxDmaChannel);

}
#endif /* SPI_DMA_USED == STD_ON */

/**
* @param[in]     LPspi_pDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_ChannelTransferDmaInitRX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev, \
        VAR(Spi_ChannelType, AUTOMATIC) Channel \
    ) \
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelAttributesConfig;
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pChannelState = LPspi_pcChannelConfig->pChannelState;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) LPspi_pBufferRX;
     VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_FramesCount;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) LPspi_pRxTcdAddr = LPspi_pDev->LPspi_pu32RxDmaTcd;
    
    /* Set the TCR parameters for this channel */
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[Channel];
    LPspi_FramesCount = LPspi_pChannelState->Length;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 2u;
    }
    else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 4u;
    }
    else
    {
        /* Do nothing */
    }
#else
    if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 4u;
    }
    else if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount /= 2u;
    }
    else
    {
        /* Do nothing */
    }
#endif
    /* get the number of frames to be sent through DMA */
    if ( LPSPI_DMA_MAX_LINKED_ITER_CNT < LPspi_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        LPspi_pDev->LPspi_ReceivedData = LPspi_FramesCount - LPSPI_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 2u;
        }
        else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 4u;
        }
        else if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        LPspi_FramesCount = LPSPI_DMA_MAX_LINKED_ITER_CNT;
    }
    else
    {
        LPspi_pDev->LPspi_ReceivedData = 0u;
    }
    /* Configure RX DMA descriptor */
    /* Rx buffer will be NULL if discarding read values */
    LPspi_pBufferRX = LPspi_pcChannelConfig->pcBufferDescriptor->pBufferRX;
    if (NULL_PTR == LPspi_pBufferRX)
    {
        /* dest address - discard read */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetDaddr(LPspi_pRxTcdAddr, (uint32) &Spi_LPspi_u32ReadDiscard);
        /* update RX transfer size; 1bytes offset for destination address */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
        Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)0u);
    #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
        /* Compiler_Warning: It is intended for the address of the element to be passed
                          to the function as an unsigned integer*/
        Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
    #else
        /* Compiler_Warning: It is intended for the address of the element to be passed
                            to the function as an unsigned integer*/
        Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress+3u);
    #endif
        /* overwrite the default src next offset */
        /* 1 bytes src transfer size, 1 bytes dest transfer size */
        /* no src offset */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
        Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE );
        Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
        /* 1 bytes to transfer */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
    }
    else
    {
        /* dest address - RX buffer */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetDaddr(LPspi_pRxTcdAddr, (uint32)LPspi_pBufferRX);
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* update RX transfer size; 2bytes offset for destination address */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
            Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)2u);
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress+2u);
        #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
        #endif
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 2 bytes to transfer */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* update RX transfer size; 4bytes offset for destination address */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
            Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)2u);
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 4 bytes to transfer */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else
        {
            /* update RX transfer size; 1bytes offset for destination address */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
            Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)1u);
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress+3u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
            #endif
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE );
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* 1 bytes to transfer */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
    #else
        if (SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            /* update RX transfer size; 4bytes offset for destination address */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
            Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)2u);
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
            /* overwrite the default src next offset */
            /* 4 bytes src transfer size, 4 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_4BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 4 bytes to transfer */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x04u));
        }
        else if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth) 
        {
            /* update RX transfer size; 2bytes offset for destination address */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
            Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)2u);
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress+2u);
        #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
        #endif
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 2 bytes to transfer */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else
        {
            /* update RX transfer size; 1bytes offset for destination address */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));
            Mcl_DmaTcdSetDoff(LPspi_pRxTcdAddr, (sint16)1u);
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress+3u);
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(LPspi_pRxTcdAddr, LPspi_pDev->LPspi_u32RDRAddress);
            #endif
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(LPspi_pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE );
            Mcl_DmaTcdSetDModuloAndSize(LPspi_pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* 1 bytes to transfer */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(LPspi_pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }            
    #endif
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount));        
    }

    /* start RX */
    LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(LPspi_pcHWUnitConfig->u8RxDmaChannel);
}
#endif /* SPI_DMA_USED == STD_ON */
/*================================================================================================*/
/**
* @brief   Restart the DMA transmission, refreshing the size.
* @details Source and destination addresses are already set into the active TCDs.
*
* @param[in]     LPspi_pDev      Specifies which LPSPI module is used
*
* @pre The function can be called only if Spi_LPspi_JobTransferDmaStart() was
*      previously called to initialize the DMA configuration.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferDmaContinueTX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    ) \
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_FramesCount;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
       /*
       * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
       */
       LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerTX)];
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) LPspi_pTxTcdAddr = LPspi_pDev->LPspi_pu32TxDmaTcd;
    
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_RemainingData / 2u;
    }
    else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_RemainingData / 4u;
    }
    else
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_RemainingData;
    }
#else
    if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_RemainingData / 2u;
    }
    else
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_RemainingData;
    }    
#endif

    /* get the number of frames to be sent through DMA */
    if ( LPSPI_DMA_MAX_LINKED_ITER_CNT < LPspi_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        LPspi_pDev->LPspi_RemainingData = LPspi_FramesCount - LPSPI_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_RemainingData *= 2u;
        }
        else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_RemainingData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_RemainingData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        LPspi_FramesCount = LPSPI_DMA_MAX_LINKED_ITER_CNT;        
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(LPspi_pTxTcdAddr, (uint16)(LPspi_FramesCount)); 
    }
    else
    {
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update TX transfer size */ 
        Mcl_DmaTcdSetIterCount(LPspi_pTxTcdAddr, (uint16)(LPspi_FramesCount)); 
        LPspi_pDev->LPspi_RemainingData = 0u;
    }
    /* start TX */
    LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(LPspi_pcHWUnitConfig->u8TxDmaChannel);
}
#endif

/**
* @brief   Restart the DMA transmission, refreshing the size.
* @details Source and destination addresses are already set into the active TCDs.
*
* @param[in]     LPspi_pDev      Specifies which LPSPI module is used
*
* @pre The function can be called only if Spi_LPspi_JobTransferDmaStart() was
*      previously called to initialize the DMA configuration.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*
* @violates @ref Spi_LPspi_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_LPspi_JobTransferDmaContinueRX \
    ( \
        P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev \
    ) \
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) LPspi_FramesCount;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
        /*
        * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        LPspi_pcChannelAttributesConfig = &Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[*(LPspi_pDev->LPspi_pcCurrentChannelIndexPointerRX)];
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) LPspi_pRxTcdAddr = LPspi_pDev->LPspi_pu32RxDmaTcd;
    
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_ReceivedData / 2u;
    }
    else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_ReceivedData / 4u;
    }
    else
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_ReceivedData;
    }
#else
    if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_ReceivedData / 2u;
    }
    else
    {
        LPspi_FramesCount = LPspi_pDev->LPspi_ReceivedData;
    }    
#endif

    /* get the number of frames to be sent through DMA */
    if ( LPSPI_DMA_MAX_LINKED_ITER_CNT < LPspi_FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        LPspi_pDev->LPspi_ReceivedData = LPspi_FramesCount - LPSPI_DMA_MAX_LINKED_ITER_CNT;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 2u;
        }
        else if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 4u;
        }
        else
        {
            /* Do nothing */
        }
    #else
        if(SPI_DATA_WIDTH_32 == LPspi_pcChannelAttributesConfig->u8DataWidth)
        {
            LPspi_pDev->LPspi_ReceivedData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        LPspi_FramesCount = LPSPI_DMA_MAX_LINKED_ITER_CNT;
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount)); 
    }
    else
    {
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(LPspi_pRxTcdAddr, (uint16)(LPspi_FramesCount)); 

        LPspi_pDev->LPspi_ReceivedData = 0u;
    }

    /* start RX */
    LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
    /*
    * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(LPspi_pcHWUnitConfig->u8RxDmaChannel);
}
#endif

/*================================================================================================*/
#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
/**
* @brief   This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
* @details This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
*          - Sync or Async:       Asynchronous
*
* @param[in]      Sequence            Sequence ID
*
* @pre  parameters: (SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)
*                             
*/
FUNC(void, SPI_CODE) Spi_LPspi_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcJobConfig;
    VAR(Spi_JobType, AUTOMATIC) LPspi_Job;
    P2VAR(Spi_LPspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pDev;
    P2VAR(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_DATA) LPspi_pSequenceState;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcJob;
    VAR(uint32, AUTOMATIC) LPspi_u32FSRval;
    VAR(uint32, AUTOMATIC) LPspi_u32SRval;
    VAR(uint32, AUTOMATIC) LPspi_u32Timeout = SPI_TIMEOUT_COUNTER;
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) LPspi_pcHWUnitConfig;
#endif
    
    /* Set sequence state to Cancel */
    Spi_aSpiSequenceState[Sequence].Result = SPI_SEQ_CANCELLED;
    
    LPspi_pSequenceState = &Spi_aSpiSequenceState[Sequence];
    LPspi_pcJob = LPspi_pSequenceState->pcCurrentJobIndexPointer;
    LPspi_Job = *LPspi_pcJob;
    /*
    * @violates @ref Spi_LPspi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    LPspi_pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[LPspi_Job];
    LPspi_pDev = &Spi_LPspi_aDeviceState[LPspi_pcJobConfig->HWUnit];
    if(SPI_SLAVE == (Spi_ModeType)LPspi_pDev->LPspi_pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /* Stop DMA transfer */
    #if (SPI_DMA_USED == STD_ON)
        if (0u != LPspi_pDev->LPspi_pcHWUnitConfig->u16UseDma)
        {
            /* Disable TX before RX */
            LPspi_pcHWUnitConfig = LPspi_pDev->LPspi_pcHWUnitConfig;
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaDisableHwRequest(LPspi_pcHWUnitConfig->u8TxDmaChannel);
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaDisableHwRequest(LPspi_pcHWUnitConfig->u8RxDmaChannel);
        }
        else
        {
            /* Do nothing */
        }
    #endif
        /* Wait untill the module is IDLE. This way no data is in Shift Register */
        do
        {
            LPspi_u32Timeout--; 
            /* end the loop if timeout expired */
             if (0u == LPspi_u32Timeout)
            { 
                /* force the end of the outer loop too */
                 break;
            }
            else 
            { 
                /* Do nothing */
            } 
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            LPspi_u32SRval = REG_READ32(LPspi_pDev->LPspi_u32SRAddress) & LPSPI_SR_MBF_MASK_U32;
        }while(0u != LPspi_u32SRval); 
        /* Clear TX FIFO and RX FIFO */
        /*
        * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        */
        /*
        * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        LPspi_u32FSRval = REG_READ32(LPSPI_FSR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset)) & \
                                            (LPSPI_FSR_TXCOUNT_MASK_U32 | LPSPI_FSR_RXCOUNT_MASK_U32);
        if(0u != LPspi_u32FSRval)
        {
            /* Discard all frames in FIFO */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET32(LPSPI_CR_ADDR32(LPspi_pDev->LPspi_pcHWUnitConfig->u8Offset), (LPSPI_CR_RRF_RESET_U32 | LPSPI_CR_RTF_RESET_U32)); 
            /* Clear Status register */
            /*
            * @violates @ref Spi_LPspi_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            */
            /*
            * @violates @ref Spi_LPspi_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(LPspi_pDev->LPspi_u32SRAddress, LPSPI_SR_INT_MASK_U32);
        }
        else
        {
            /* Do nothing */
        }
        
        Spi_JobTransferFinished(LPspi_pcJobConfig);
    }
    else
    {
        /* Do nothing */
    }
}
#endif  /* ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)) */

/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_LPspi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_LPspi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/** @} */
