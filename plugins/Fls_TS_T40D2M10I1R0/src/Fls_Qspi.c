/**
*   @file    Fls_Qspi.c
*   @implements Fls_Qspi.c_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Qspi related functions.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section fls_qspi_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_qspi_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_qspi_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as the read/write/erase/operation finished
*
* @section fls_qspi_c_REF_5
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is caused by iterating the application buffer, passed via a pointer as required by the
* Autosar API prototypes.
*
* @section fls_qspi_c_REF_6
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long, caused by the enforced Autosar API prototypes and
* used for optimizing the memory access.
*
* @section fls_qspi_c_REF_7 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* The error is the result of an equality operator (!=) expression result being casted explicitly to
* type boolean. The expression result is implicitly signed and then casted to the user defined unsigned boolean.
*
* @section fls_qspi_c_REF_8
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* Variables may be used in LLD layers.
*
* @section fls_qspi_c_REF_9 
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function. 
* The variables are declared globally in order to safely pass them as references to other functions.
*
* @section [global]
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
*/

/* Compiler warning fls_c_REF_CW_02: cast to pointer from integer of different size.
   The cast is explicit, intended and the casted value is treated properly. 
   It just supports CORE ARM 64bit
*/
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_Qspi.h"
#include "Fls_Qspi_Types.h"
#include "Reg_eSys_QSPI.h"
#include "StdRegMacros.h"

#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON or FLS_RUNTIME_ERROR_DETECT == STD_ON */

#if (STD_ON == FLS_SYNCRONIZE_CACHE) 
#include "Mcl.h"
#endif /* FLS_SYNCRONIZE_CACHE */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_QSPI_VENDOR_ID_C                           43
#define FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C            4
#define FLS_QSPI_AR_RELEASE_MINOR_VERSION_C            2
#define FLS_QSPI_AR_RELEASE_REVISION_VERSION_C         2
#define FLS_QSPI_SW_MAJOR_VERSION_C                    1
#define FLS_QSPI_SW_MINOR_VERSION_C                    0
#define FLS_QSPI_SW_PATCH_VERSION_C                    1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls.h header file have the same Vendor ID */
#if (FLS_QSPI_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Qspi_Code.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_QSPI_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_QSPI_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Qspi_Code.c and Fls.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls.h header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and Fls.h are different"
    #endif
#endif

/* Check if current file and Reg_eSys_QSPI.h header file have the same Vendor ID */
#if (FLS_QSPI_VENDOR_ID_C != ESYS_QSPI_VENDOR_ID)
    #error "Fls_Qspi_Code.c and Reg_eSys_QSPI.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_QSPI.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_C != ESYS_QSPI_SW_MAJOR_VERSION) || \
     (FLS_QSPI_SW_MINOR_VERSION_C != ESYS_QSPI_SW_MINOR_VERSION) || \
     (FLS_QSPI_SW_PATCH_VERSION_C != ESYS_QSPI_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Qspi_Code.c and Reg_eSys_QSPI.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Reg_eSys_QSPI.h header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C    != ESYS_QSPI_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C    != ESYS_QSPI_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and Reg_eSys_QSPI.h are different"
    #endif
#endif


/* Check if current file and Fls_Qspi.h header file have the same Vendor ID */
#if (FLS_QSPI_VENDOR_ID_C != FLS_QSPI_VENDOR_ID_H)
    #error "Fls_Qspi_Code.c and Fls_Qspi.h have different vendor ids"
#endif
/* Check if current file and Fls_Qspi.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_C != FLS_QSPI_SW_MAJOR_VERSION_H) || \
     (FLS_QSPI_SW_MINOR_VERSION_C != FLS_QSPI_SW_MINOR_VERSION_H) || \
     (FLS_QSPI_SW_PATCH_VERSION_C != FLS_QSPI_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Fls_Qspi_Code.c and Fls_Qspi.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls_Qspi.h header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C    != FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C    != FLS_QSPI_AR_RELEASE_MINOR_VERSION_H)    \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and Fls_Qspi.h are different"
    #endif
#endif

/* Check if current file and Fls_Qspi_Types.h header file have the same Vendor ID */
#if (FLS_QSPI_VENDOR_ID_C != FLS_QSPI_TYPES_VENDOR_ID)
    #error "Fls_Qspi_Code.c and Fls_Qspi_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Qspi_Types.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_C != FLS_QSPI_TYPES_SW_MAJOR_VERSION) || \
     (FLS_QSPI_SW_MINOR_VERSION_C != FLS_QSPI_TYPES_SW_MINOR_VERSION) || \
     (FLS_QSPI_SW_PATCH_VERSION_C != FLS_QSPI_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Qspi_Code.c and Fls_Qspi_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls_Qspi_Types.h header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C    != FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C    != FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and Fls_Qspi_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros.h header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and StdRegMacros.h are different"
    #endif
#endif

#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and Det.h are different"
    #endif
#endif
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcl header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Qspi_Code.c and Mcl.h are different"
    #endif
#endif
#endif /* FLS_SYNCRONIZE_CACHE */
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)

#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

static FUNC(void, FLS_CODE) Fls_Qspi_InvalidateAhbBuffers( void );
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IPRead
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_AHBRead
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_GetMemStatus
(
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) p32DataPtr,
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr
);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_CheckExtMemIsIdle
(
    VAR(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex
);
#if(FLS_USE_INTERRUPTS == STD_ON)
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_GetMemStatusIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr);
#endif
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_VerifyWrite
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_AddressType, AUTOMATIC) u32DataCmpAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength
);
#endif

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_ReadRXBuffer
(
    VAR(uint8, AUTOMATIC) u8BytesToRead,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_CheckControllerIsIdle(void);
#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SetLUT(uint8 u8LUTNumber, uint32 LUTValue);
#endif
static FUNC(void, FLS_CODE) Fls_Qspi_LaunchLUTCommand
(
    CONST(uint8, AUTOMATIC) u8LUTId,
    CONST(uint8, AUTOMATIC) u8DataSize,
    CONST(uint8, AUTOMATIC) u8ParEn
);
#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_VerifyErase
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength
);
#endif

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_WriteEnable
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(uint8, AUTOMATIC) u8ParEn
);
#endif
static FUNC( void, FLS_CODE ) Fls_Qspi_LoadTXBuffer
( 
    VAR(Fls_AddressType, FLS_VAR) u32SourceAddr, 
    VAR(uint8, AUTOMATIC) u8BytesToWrite
);
#if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_ReadDeviceId
(   
    VAR(uint8, AUTOMATIC) u8HwUnitCfgIndex,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr
);
#endif /*#if(FLS_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) OR #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )*/

static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_CheckResetExternalMem
(
    VAR(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex
);

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SetLUTHyperflashCmd(Fls_AddressType u32Addr, uint8 u8LUTIndex, uint8 hyperflashCmd);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareReadLUT(VAR(uint8, AUTOMATIC) u8LatCycls);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareLaunchErase(void);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareLaunchWrite(VAR(uint8, AUTOMATIC) u8BytesToWrite);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareLaunchGetStatus(VAR(uint8, AUTOMATIC) u8LatCycls, VAR(uint8, AUTOMATIC) u8ExtRegWidth);
#if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperEnterCfiAso(void);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperResetExitAso(void);
#endif /*#if(FLS_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) OR #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )*/

#if(FLS_USE_INTERRUPTS == STD_ON)
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendEnterStatusCmdIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendReadStatusRegIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendUnlock1Irq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendUnlock2Irq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendWriteWordIdIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendWriteWordDataIrq( 
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
);
#endif /* #if(FLS_USE_INTERRUPTS == STD_ON) */
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */


#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/* Base address of current HW unit: QSPI0 or QSPI1. Used to reference all QuadSPI IP register offsets. */
/* @violates @ref fls_qspi_c_REF_8 All declarations and definitions of objects should have internal linkage. */
VAR(Fls_AddressType, FLS_VAR) Fls_Qspi_u32HwUnitBaseAddr = 0UL;
/* The external sector start address. This address is used for Read jobs, inside the SFAR register for 
   IP commands or it is the address directly read in the memory map for AHB read commands.
   For ex. if an external sector start from offset 0x1000 inside the external memory and that memory is 
   connected on the channel A1 => the internal memory mapped address is: QSPI_CH_A1 base address(0x200000000) + 0x1000. */
/* @violates @ref fls_qspi_c_REF_8 All declarations and definitions of objects should have internal linkage. */
VAR(Fls_AddressType, FLS_VAR) Fls_Qspi_u32ExtSectStartAddr = 0UL;
/* The Address for check status of the parallel sectors  */
/* The Address in the individual mode of Sector A1/A2 when it was configured in parallel mode */
static VAR(Fls_AddressType, FLS_VAR) Fls_Qspi_u32StartAddrIndividual_A = 0UL;
/* The Address in the individual mode of Sector B1/B2 when it was configured in parallel mode */
static VAR(Fls_AddressType, FLS_VAR) Fls_Qspi_u32StartAddrIndividual_B = 0UL;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


/* The index of the HwUnit configuration structure,
used to select the structure holding the configuration for HwUnit0/1 mapped to QSPI0/1. 
The index is computed based on the external Hw channel(QSPI_0_A1, QSPI_1_B2, etc) of the current sector,
which is mapped to a configuration structure, for example QSPI_1_B2 is mapped to the config structure 
holding the configuration for the external Hw unit QSPI_1. */
/* @violates @ref fls_qspi_c_REF_8 All declarations and definitions of objects should have internal linkage. */
VAR(uint8, FLS_VAR) Fls_Qspi_u8HwUnitCfgIndex = 0U;

/** 
* @brief The number of bytes which have to be read(are expected to be received) in a single RX IRQ iteration.
* @details Limited by the maximum size of the RX buffer or total data length, if smaller.
*/
static VAR(volatile uint8, FLS_VAR) Fls_Qspi_u8LLDBytesToRead = 0U;

#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_NO_INIT_8
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief Global variable used as temporary source buffer for filling TXBuffer when external transactions less than
*        the minimum allowed size is needed. Only used for debug,configuration purposes, in external APIs.
*/
/* @violates @ref fls_qspi_c_REF_9 Objects shall be defined at block scope if they are only accessed from within a single function. */
static VAR(uint8, FLS_VAR) Fls_Qspi_au8TmpDataPtr[16];

#define FLS_STOP_SEC_VAR_NO_INIT_8
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief Global variable used as destination for reading the external status register value.
*/
/* @violates @ref fls_qspi_c_REF_9 Objects shall be defined at block scope if they are only accessed from within a single function. */
static VAR(uint32, FLS_VAR) Fls_Qspi_u32StatusRegVal = 0UL;

#if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
/** 
* @brief Global variable used as destination for reading the external device ID.
*/
/* @violates @ref fls_qspi_c_REF_9 Objects shall be defined at block scope if they are only accessed from within a single function. */
static VAR(uint32, FLS_VAR) Fls_Qspi_u32DeviceId = 0UL;
#endif  /*#if(FLS_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) OR #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )*/

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
#define FLS_START_SEC_CONST_32
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/* Hardware QSPI IP base address - used for register interface access. */
/* @violates @ref fls_qspi_c_REF_8 All declarations and definitions of objects should have internal linkage. */
CONST(uint32, FLS_CONST) FLS_QSPI_BASE_ADDR32[FLS_QSPI_AVAILABLE_UNITS] = 
{
#ifdef QSPI_0_BASEADDR
    QSPI_0_BASEADDR
#endif
#ifdef QSPI_1_BASEADDR
    ,QSPI_1_BASEADDR
#endif
};

/* QSPI base address of RX buffer for access in AHB mode. */
static CONST(uint32, FLS_CONST) FLS_QSPI_ARDB_BASE_ADDR32[FLS_QSPI_AVAILABLE_UNITS] = 
{
#ifdef QSPI_0_BASEADDR
    QSPI_0_ARDB_BASEADDR_U32
#endif
#ifdef QSPI_1_BASEADDR
    ,QSPI_1_ARDB_BASEADDR_U32
#endif
};

#define FLS_STOP_SEC_CONST_32
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief The address in the memory, at which hardware qspi operations are performed.
* @details The address in the memory, memory mapped in the controller memory map, 
*          used to access a specific location in the external memory for read,write,erase operations.
*/
static VAR(volatile Fls_AddressType, FLS_VAR) Fls_Qspi_u32MemoryAddress = 0UL;

/** 
* @brief The address in the application provided buffer.
* @details 
*    When used for read jobs, the buffer is used for storing the read data,
*    When used for compare jobs, the buffer is used for reading the data against which to compare the memory read data,
*    When used for write jobs, the buffer is used for reading the data which has to be written into the memory.
*/
static VAR(volatile Fls_AddressType, FLS_VAR) Fls_Qspi_u32BufferAddress = 0UL;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#if(FLS_USE_INTERRUPTS == STD_ON)
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
static VAR(boolean, FLS_VAR) Fls_Qspi_bIrqMemWriteEnabled = (boolean)FALSE;
#endif
#endif

#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"


/** 
* @brief        Qspi IP initialization
*
* @details      Configures all the QuadSPI IPs with the configuration parameters
*
* @param[in]    none
* @param[out]   none
*
* @pre          none
* @post         The module is initialized
*
* @implements     Fls_Qspi_Init_Activity
*    
*/
FUNC( void, FLS_CODE ) Fls_Qspi_Init( void )
{    
    VAR(uint8, AUTOMATIC) u8Iter=0U;
    VAR(uint8, AUTOMATIC) u8Iter2=0U;
    VAR(uint8, AUTOMATIC) u8Iter3=0U;
    VAR(Fls_AhbBufferMasterIdType, AUTOMATIC) eAhbBuffMasterId;
    VAR(uint32, AUTOMATIC) u32AhbBuffDataTransfSize=0UL;
    VAR(uint32, AUTOMATIC) u32ExtHwUnitBaseAddr=0UL;
    
    Fls_eLLDJobResult = MEMIF_JOB_OK;
    
    /* Iterate and init all external hardware units. */
    for( u8Iter = 0U; u8Iter < Fls_pConfigPtr->pFlsQspiCfgConfig->u8QspiUnitsCount; u8Iter++ )
    {
        /* Compute QSPIx module peripheral base address. */
        u32ExtHwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eHwUnitName );
        
        /* Disable QSPIx module before configuration - enter "Disabled mode" in order to be able to update QuadSPI_SMPR */
        REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);
        
        /* Configure read mode (SDR or DDR mode). */
        if( FLS_SDR == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitReadMode )
        {
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DDR_EN_U32);
        }
        else if( FLS_DDR == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitReadMode )
        {            
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DDR_EN_U32);
        }
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        
                    
        /* Configure DQS mode. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitDqsMode )
        {
            /* Enable DQS. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_EN_U32);
        }
        else
        {
            /* Disable DQS. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_EN_U32);
        }        
        
        /* Configure input buffers(SCLKCFG[7]). */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitInputPadsBufferEn )
        {
            /* Enable input pads buffer. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_PADS_BUF_EN_U32);
        }
        else
        {
            /* Disable input pads buffer. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_PADS_BUF_EN_U32);
        } 
     
        /* Configure module clock source(SCLKCFG[6]). */
        if( FLS_QSPI_SYS_CLK == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitInputClockSel )
        {
            /* Select SYC_CLK as AHB read interface clock (program it twice). */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_INPUT_CLK_SEL_U32);
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_INPUT_CLK_SEL_U32);
        }
        else if( FLS_QSPI_BUS_CLK == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitInputClockSel )
        {
            /* Select BUS_CLK as AHB read interface clock (program it twice). */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_INPUT_CLK_SEL_U32);
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_INPUT_CLK_SEL_U32);
        } 
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the Internal reference clock (async clock domain) source selection for Quadspi(SCLKCFG[4]). External clock sent to memory. */
        if( FLS_QSPI_SPLLDIV1 == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitInternalRefClockSel )
        {
            /* Select SPLLDIV1 as Internal reference clock. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_INTERN_REF_CLK_SEL_U32);
        }
        else if( FLS_QSPI_FIRCDIV1 == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitInternalRefClockSel )
        {
            /* Select FIRCDIV1 as Internal reference clock. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_INTERN_REF_CLK_SEL_U32);
        } 
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the reference clock source for DQS for Flash-B Stage 2(SCLKCFG[3]). */
        if( FLS_QSPI_DQS_INVERTED == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsBStage2ClkSource )
        {
            /* Inverted clock source. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_B_STAGE2_CLK_SRC_U32);
        }
        else if( FLS_QSPI_DQS_NONINVERTED == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsBStage2ClkSource )
        {
            /* Non-inverted clock source. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_B_STAGE2_CLK_SRC_U32);
        } 
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the reference clock source for DQS for Flash-B Stage 1(SCLKCFG[2]). */
        if( FLS_QSPI_DQS_INTERNAL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsBStage1ClkSource )
        {
            /* Internal Reference Clock selected as DQS. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_B_STAGE1_CLK_SRC_U32);
        }
        else if( FLS_QSPI_DQS_LOOPBACK == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsBStage1ClkSource )
        {
            /* Loopback clock from PAD SCKB selected as DQS. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_B_STAGE1_CLK_SRC_U32);
        } 
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the reference clock source for DQS for Flash-A Stage 2(SCLKCFG[1]). */
        if( FLS_QSPI_DQS_INVERTED == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsAStage2ClkSource )
        {
            /* Inverted clock source. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_A_STAGE2_CLK_SRC_U32);
        }
        else if( FLS_QSPI_DQS_NONINVERTED == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsAStage2ClkSource )
        {
            /* Non-inverted clock source. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_A_STAGE2_CLK_SRC_U32);
        } 
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the reference clock source for DQS for Flash-A Stage 1(SCLKCFG[0]). */
        if( FLS_QSPI_DQS_INTERNAL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsAStage1ClkSource )
        {
            /* Internal Reference Clock selected as DQS. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_A_STAGE1_CLK_SRC_U32);
        }
        else if( FLS_QSPI_DQS_LOOPBACK == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitDqsAStage1ClkSource )
        {
            /* Loopback clock from PAD SCKB selected as DQS. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_A_STAGE1_CLK_SRC_U32);
        } 
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        } 

        /* Configure Pending Read Bus Gasket. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitPendingReadBusGasket )
        {
            /* Pending reads are enabled. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_PENDIG_READ_GASKET_U32);
        }
        else
        {
            /* Pending reads are disabled. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_PENDIG_READ_GASKET_U32);
        }

        /* Configure Burst Read Bus Gasket. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitBurstReadBusGasket )
        {
            /* Burst reads are optimized for best system performance. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_BURST_READ_GASKET_U32);
        }
        else
        {
            /* Burst reads are converted into a series of single transactions on the slave side of the gasket. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_BURST_READ_GASKET_U32);
        }

        /* Configure Burst Write Bus Gasket. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitBurstWriteBusGasket )
        {
            /* Burst writes are optimized for best system performance. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_BURST_WRITE_GASKET_U32);
        }
        else
        {
            /* Burst writes are converted into a series of single transactions on the slave side of the gasket. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_BURST_WRITE_GASKET_U32);
        }   
        
        /* Disable the divider before modifying it. */
        REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_DIVIDER_EN_U32);
            
        /* Configure the programmable divider */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_PROGRAM_DIVIDER_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitProgrammableDivider) << QSPI_SOCCR_PROGRAM_DIVIDER_SHIFT_U32) 
                 );                

        /* Enable the divider after modifying it. */  
        REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_DIVIDER_EN_U32);         
                   
        /* Configure Idle Signal Drive IOFB[3] Flash B. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitIOFB3HighLvl )
        {
            /* IOFB[3] is driven to logic H. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD3FB_U32);
        }
        else
        {
            /* IOFB[3] is driven to logic L. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD3FB_U32);
        }

        /* Configure Idle Signal Drive IOFB[2] Flash B. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitIOFB2HighLvl )
        {
            /* IOFB[2] is driven to logic H. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD2FB_U32);
        }
        else
        {
            /* IOFB[2] is driven to logic L. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD2FB_U32);
        }

        /* Configure Idle Signal Drive IOFA[3] Flash A. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitIOFA3HighLvl )
        {
            /* IOFA[3] is driven to logic H. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD3FA_U32);
        }
        else
        {
            /* IOFA[3] is driven to logic L. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD3FA_U32);
        }

        /* Configure Idle Signal Drive IOFA[2] Flash A. */
        if( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitIOFA2HighLvl )
        {
            /* IOFA[2] is driven to logic H. */
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD2FA_U32);
        }
        else
        {
            /* IOFA[2] is driven to logic L. */
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_ISD2FA_U32);
        }
        
            
        
        /* Configure sampling edge.(Applicable in SDR mode only.) */
        if( FLS_RISING == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitSamplingEdge )
        {
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_SMPR_OFFSET_U32, QSPI_SMPR_FSPHS_U32);
        }
        else if( FLS_FALLING == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitSamplingEdge )
        {
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_SMPR_OFFSET_U32, QSPI_SMPR_FSPHS_U32);
        }
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the sampling delay.(Applicable in SDR mode only.)*/
        if( FLS_1SAMPLE_DLY == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitSamplingDly )
        {
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_SMPR_OFFSET_U32, QSPI_SMPR_FSDLY_U32);
        }
        else if( FLS_2SAMPLE_DLY == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitSamplingDly )
        {
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_SMPR_OFFSET_U32, QSPI_SMPR_FSDLY_U32);
        }
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure the DDR sampling point.(Applicable in DDR mode only.)*/
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_SMPR_OFFSET_U32, QSPI_SMPR_DDRSMP_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitSamplingPoint) << QSPI_SMPR_DDRSMP_SHIFT_U32) 
                 );
        
        /* Enable latency delay options. */
        if( (boolean)TRUE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitDqsLatencyEn )
        {
            REG_BIT_SET32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_LAT_EN_U32);
        }
        else
        {
            REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_DQS_LAT_EN_U32);
        }
                    
        /* Configure fine delay for external Flash A. */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_FINE_DLY_A_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitFineDlyA) << QSPI_SOCCR_FINE_DLY_A_SHIFT_U32) 
                 );
        /* Configure fine delay for external Flash B. */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_FINE_DLY_B_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitFineDlyB) << QSPI_SOCCR_FINE_DLY_B_SHIFT_U32) 
                 );
        
        /* Configure TDH (data in hold time, for data sent to flash). */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_FLSHCR_OFFSET_U32, QSPI_FLSHCR_TDH_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitTdh) << QSPI_FLSHCR_TDH_SHIFT_U32) 
                 );
        /* Configure TCSH (data in hold time, for data sent to flash). */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_FLSHCR_OFFSET_U32, QSPI_FLSHCR_TCSH_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitTcsh) << QSPI_FLSHCR_TCSH_SHIFT_U32) 
                 );
        /* Configure TCSS (data in hold time, for data sent to flash). */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_FLSHCR_OFFSET_U32, QSPI_FLSHCR_TCSS_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitTcss) << QSPI_FLSHCR_TCSS_SHIFT_U32) 
                 );
        
        /* Configure endianness. */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_END_MASK_U32, 
                   (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitEndian) << QSPI_MCR_END_SHIFT_U32) 
                 ); 
        
        /* Configure read mode for the RX buffer ( using IP bus or AHB bus) */
        if( FLS_RXBUFFER_AHB_BUS_ACCESS == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitRxBufferAccessMode )
        {
            /* RX Buffer content is read using the AHB Bus registers QSPI_ARDB0 to QSPI_ARDB31. */
            REG_BIT_CLEAR32( u32ExtHwUnitBaseAddr + QSPI_RBCT_OFFSET_U32, QSPI_RBCT_RXBRD_MASK_U32 );
        }
        else if( FLS_RXBUFFER_IP_BUS_ACCESS == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eQspiUnitRxBufferAccessMode )
        {
            /* RX Buffer content is read using the IP Bus registers QSPI_RBDR0 to QSPI_RBDR31. */
            REG_BIT_SET32( u32ExtHwUnitBaseAddr + QSPI_RBCT_OFFSET_U32, QSPI_RBCT_RXBRD_MASK_U32 );
        }
        else
        {
            /* Configuration error.*/
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Configure each AHB buffer. Loop through all configured AHB buffers. */
        for( u8Iter2 = 0U; u8Iter2 < (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitAhbBufferCount; u8Iter2++ )
        {       
            eAhbBuffMasterId = (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBufferMasterId)[u8Iter2];
            /* Configure MSTRID field from BUFxCR registers. Depending on the master id, a particular AHB buffer is used to store the read data. */
            REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_BUFXCR_OFFSET_U32 + (uint32)((uint32)(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBuffer)[u8Iter2] * 4UL),
                       QSPI_BUFxCR_MSTRID_MASK_U32, (uint32)eAhbBuffMasterId
                      );                      
            u32AhbBuffDataTransfSize = (uint32)((*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBufferDataTransferSize)[u8Iter2] / 8UL);
            /* Configure the data prefetch transfer size(the size of the data read transaction triggered by an AHB read access).
               When this value is 0,the data size mentioned in the LUT sequence pointed to by the SEQID field overrides this value. */
            REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_BUFXCR_OFFSET_U32 + (uint32)((uint32)(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBuffer)[u8Iter2] * 4UL),
                       QSPI_BUFxCR_ADATSZ_MASK_U32, 
                       (uint32)( u32AhbBuffDataTransfSize << QSPI_BUFxCR_ADATSZ_SHIFT_U32 ) 
                      );
            /* Configure AHB buffer size for all buffers(0,1,2) except buffer no.3. AHB buffer 3 size is determined by Max size - buffer 2 top.*/            
            if( AHB_BUFFER_0 == (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBuffer)[u8Iter2] )
            {
                REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_BUF0IND_OFFSET_U32,
                             (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBufferSize)[u8Iter2] 
                           );
            }
            else if( AHB_BUFFER_1 == (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBuffer)[u8Iter2] )
            {
                REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_BUF1IND_OFFSET_U32,
                             REG_READ32(u32ExtHwUnitBaseAddr + QSPI_BUF0IND_OFFSET_U32) +
                             (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBufferSize)[u8Iter2] 
                           );
            }
            else if( AHB_BUFFER_2 == (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBuffer)[u8Iter2] )
            {
                REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_BUF2IND_OFFSET_U32,
                             REG_READ32(u32ExtHwUnitBaseAddr + QSPI_BUF1IND_OFFSET_U32) +
                             (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitAhbBufferSize)[u8Iter2] 
                           );
            }
            else /* AHB_BUFFER_3 */
            {             
                /*The size of the AHB_BUFFER_3 is determined by AHB_MAX_SIZE - AHB_BUFFER_2 top.*/  
            }                                
        }
        
        /* Set ALLMST bit - enable access for all masters to AHB_BUFFER_3 */
        if( (boolean)TRUE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bHwUnitAhbBufferAllMasters )
        {
            REG_BIT_SET32( u32ExtHwUnitBaseAddr + QSPI_BUF3CR_OFFSET_U32, QSPI_BUF3CR_ALLMST_MASK_U32);
        }
        else 
        {
            REG_BIT_CLEAR32( u32ExtHwUnitBaseAddr + QSPI_BUF3CR_OFFSET_U32, QSPI_BUF3CR_ALLMST_MASK_U32);
        }
        
        /* Set HP_EN bit - enable high priority for  AHB_BUFFER_0 */
        if( (boolean)TRUE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bHwUnitAhbBufferHighPriority )
        {
            REG_BIT_SET32( u32ExtHwUnitBaseAddr + QSPI_BUF0CR_OFFSET_U32, QSPI_BUF0CR_HP_EN_MASK_U32);
        }
        else 
        {
            REG_BIT_CLEAR32( u32ExtHwUnitBaseAddr + QSPI_BUF0CR_OFFSET_U32, QSPI_BUF0CR_HP_EN_MASK_U32);
        }
                
        /* Configure Serial flash address assignment. Based on the values from SF(A/B)(1/2)AD registers, the size of the flash memory and corresponding CS line is determined. */
        REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_SFA1AD_OFFSET_U32, (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitSerialAddrMapping)[0U] );
        REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_SFA2AD_OFFSET_U32, (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitSerialAddrMapping)[1U] );
        REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_SFB1AD_OFFSET_U32, (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitSerialAddrMapping)[2U] );
        REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_SFB2AD_OFFSET_U32, (*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitSerialAddrMapping)[3U] );
                   
        /* Configure the Address mode - set the column address width. */
        REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_SFACR_OFFSET_U32, QSPI_SFACR_CAS_MASK_U32, (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiUnitColumnAddressWidth );
        /* Enable the WordAddressable(2byte) address mode setting. */
        if( (boolean)TRUE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].bQspiUnitWordAddressable )
        {
            REG_BIT_SET32( u32ExtHwUnitBaseAddr + QSPI_SFACR_OFFSET_U32, QSPI_SFACR_WA_U32);
        }                
        else
        {
            REG_BIT_CLEAR32( u32ExtHwUnitBaseAddr + QSPI_SFACR_OFFSET_U32, QSPI_SFACR_WA_U32);
        }
            
        /* Populate LUT. */        
    #if (STD_ON == FLS_QSPI_LOCK_LUT)
        /* Unlock the LUT. */
        REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_LUTKEY_OFFSET_U32, QSPI_LUT_KEY_VALUE_U32 );
        REG_RMW32(u32ExtHwUnitBaseAddr + QSPI_LCKCR_OFFSET_U32, QSPI_LCKCR_MASK_U32, QSPI_LCKCR_UNLOCKED_U32);
    #endif    
    
        /* Clear all previous LUT values. */
        for( u8Iter2 = 0U; u8Iter2 < FLS_NO_OF_LUTS_U8; u8Iter2++ )
        {
            /* Zero the LUT. */
            REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_LUT_OFFSET_U32 + (uint32)((uint32)u8Iter2*4U), 0UL);
        }
        
        /* Loop through all configured LUT sequences for this HW unit(maximum 16 LUT sequences for a HW unit). */
        for( u8Iter2 = 0U; u8Iter2 < (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u8QspiLUTSeqsCount; u8Iter2++ )
        {
            /* Loop through all configured Instr.Operand pairs inside this LUT sequence(maximum 8 instr.operand pairs for a LUT sequence). */
            for( u8Iter3 = 0U; u8Iter3 < (*( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitLUT ))[u8Iter2].u8InstrOperCount; u8Iter3++ )
            {
                VAR(Fls_InstructionOperandType, AUTOMATIC) eInstrOper;
                
                eInstrOper = (*( (*( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].paQspiUnitLUT ))[u8Iter2].paInstrOper))[u8Iter3];
                
                if( 0U == (u8Iter3 % 2U) )
                {
                    /* Write the first 16bit Instr.Oper. pair in the 32 bit LUT register. */
                    REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_LUT_OFFSET_U32 + ((uint32)u8Iter2 * 16U) + (((uint32)u8Iter3 / 2U) * 4U),
                               QSPI_LUT_INSTR0_OPER0_MASK_U32, 
                               (uint32)( (uint32)eInstrOper << QSPI_LUT_INSTR0_OPER0_OFFSET_U32 ) 
                              );
                }
                else
                {
                    /* Write the second 16bit Instr.Oper. pair in the 32 bit LUT register. */
                    REG_RMW32( u32ExtHwUnitBaseAddr + QSPI_LUT_OFFSET_U32 + ((uint32)u8Iter2 * 16U) + (((uint32)u8Iter3 / 2U) * 4U),
                               QSPI_LUT_INSTR1_OPER1_MASK_U32, 
                               (uint32)( (uint32)eInstrOper << QSPI_LUT_INSTR1_OPER1_OFFSET_U32 ) 
                              );
                }

                /* Only aligned (LUT0, LUT4, LUT8,...) are valid starting sequences, so each LUT sequence write(from the 1st FOR loop, u8Iter2), should start aligned x4 in memory.
                The offset "(u8Iter2 * 16U)" selects the first aligned byte of a valid sequence: LUT0, LUT4, LUT8, in turn each being 32 bits(x4bytes) wide. 
                The offset "((u8Iter3 / 2U) * 4U)" selects the LUT from inside the sequence: LUT0, LUT1, LUT2, LUT3 (maximum 4 LUTs per sequence). */
            }
        }
    #if (STD_ON == FLS_QSPI_LOCK_LUT)    
        /* Lock the LUT. */
        REG_WRITE32( u32ExtHwUnitBaseAddr + QSPI_LUTKEY_OFFSET_U32, QSPI_LUT_KEY_VALUE_U32 );
        REG_RMW32(u32ExtHwUnitBaseAddr + QSPI_LCKCR_OFFSET_U32, QSPI_LCKCR_MASK_U32, QSPI_LCKCR_LOCKED_U32);
    #endif               
        /* Enable QSPIx module after configuration */
        REG_BIT_CLEAR32(u32ExtHwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);
           
    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        /* If enabled, check the external memory device ID. */
        if( 0UL != (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u16QspiDeviceId )
        {
            VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
            
            Fls_Qspi_u32DeviceId = 0UL;
            /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
            eRetVal = Fls_Qspi_ReadDeviceId(u8Iter,(uint8 *)(&Fls_Qspi_u32DeviceId));
            
            /* Check if the read external memory device ID is the same as the configured one.*/
            if( ( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].u16QspiDeviceId != (uint16)Fls_Qspi_u32DeviceId ) ||
                (FLASH_E_OK != eRetVal) 
              )
            {
                /* Configuration error.*/
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_UNEXPECTED_FLASH_ID);
            #endif
                            /* Mark the Init job as failed. */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return;
            }
        }        
    #endif /*#if(FLS_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) OR #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )*/    
    }
    
    /* If enabled, call the FlsQspiInitCallout, for additional QSPI IP or external memory settings. */
    if( NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfInitCallout )
    {
        /* Call FlsQspiInitCallout function if configured. */
        Fls_pConfigPtr->pFlsQspiCfgConfig->pfInitCallout();
    }
    /*else
    {
        Callback notification configured as null pointer.            
    }*/ 
}

/** 
* @brief        Qspi abort suspended operation
*
* @details      Called at the beginning of each FLS job, in order to check any previously suspended
*               flash operations. The intended purpose is to leave the external flash memory in an 
*               idle state, ready to start a new job.
*               The function checks for the external memory to be idle. If the memory is busy the function
*               waits for the memory to become idle, by polling the status bit. If configured, the
*               function also calls the user FlsQspiResetCallout callout.
*
* @param[in]    none
* @param[out]   none
*
* @pre          none
* @post         1. The external memory is idle, ready for a new transaction, or
*               2. The external memory is busy, job status is failed.    
*
* 
*    
*/
FUNC( void, FLS_CODE ) Fls_Qspi_AbortSuspended(void)
{
    VAR(Fls_QspiSectorChType, AUTOMATIC) eQspiSectorCh = NOT_QSPI_CHANNEL;
    VAR(Fls_QspiSectorChType, AUTOMATIC) eTmpQspiSectorCh = NOT_QSPI_CHANNEL;
    
    VAR(Fls_SectorIndexType, AUTOMATIC) u32SectorIndexIter = 0UL;
        
 
    for(u32SectorIndexIter = Fls_u32JobSectorIt; u32SectorIndexIter <= Fls_u32JobSectorEnd; u32SectorIndexIter++  )
    {
        /* Check if this sector is allocated external Flash */
        if(FLS_CH_QSPI == (*(Fls_pConfigPtr->paHwCh))[u32SectorIndexIter])
        {
            /* Get the QSPI sector channel. */
            eTmpQspiSectorCh = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectCh))[u32SectorIndexIter];
            
            /* Check if this channel already was checked before */
            if(eTmpQspiSectorCh != eQspiSectorCh )
            {
                /*Did not check yet. Check suspend status for this channel */
                eQspiSectorCh = eTmpQspiSectorCh;
                
                /* Get HW IP base address and update the global variable to be used by the subsequent IP functions in the current scheduled read job. */
                Fls_Qspi_u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitSectorAssign))[u32SectorIndexIter] );
                
                /* Update the global variables(Fls_Qspi_u32ExtSectStartAddr and Fls_Qspi_u32ExtSectStartAddrPar) with the start address 
                of the current external sector, offset-ed in the SOC serial flash assignment memory map. If applicable, update also the 
                Fls_Qspi_u32ExtSectStartAddrPar which represents the start address of the associated parallel memory. 
                For ex, in a A1B1 parallel setup: Fls_Qspi_u32ExtSectStartAddr = start address of memory A1, Fls_Qspi_u32ExtSectStartAddrPar =
                start address of memory B1. For parallel sectors, used when reading the status register of each memory, which has to be done separately.*/
                if( FLASH_E_OK != Fls_Qspi_GetExtSectStartAddr(eQspiSectorCh) )
                {
                    /* Error, the start address of the sector was not decoded correctly. */
                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return;            
                }          
                        
                /* Get the HW IP configuration index inside the configuration structure (in order to select the configuration structure associated with this sector s HW channel). */    
                Fls_Qspi_u8HwUnitCfgIndex = Fls_Qspi_GetHwUnitCfgIndex( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitSectorAssign))[u32SectorIndexIter] );
            
                #if(FLS_TIMEOUT_HANDLING == STD_ON)    
                /* Initialize timeout counters */
                Fls_u32LLDTimeout_Counter = FLS_ABT_TIMEOUT_VALUE;
                #endif
                
                /* Check if the external memory is idle. */    
                if( FLASH_E_OK != Fls_Qspi_CheckResetExternalMem(u32SectorIndexIter) )
                {
                    /* Error, the external memory is not idle, abort timer has expired. */
                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return;
                }    
            }
         /* else
            {
                This channel is already checked 
            } */
        }
 
    }    
}

/** 
* @brief        Check external memory status
*
* @details      Called at the beginning of each FLS job, in order to check any previously suspended
*               flash operations. 
*               The function checks for the external memory to be idle. If the memory is busy the function
*               waits for the memory to become idle, by polling the status bit. If configured, the
*               function also calls the user FlsQspiResetCallout callout.
*
* @param[in]    none
* @param[out]   none
*
* @pre          none
* @post         1. The external memory is idle, ready for a new transaction, or
*               2. The external memory is busy, timeout triggered if configured, job status is failed.    
*
* 
*    
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_CheckResetExternalMem
(
    VAR(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex
)
{ 
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Check and wait for transaction to finish in uC. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the current operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Wait for transaction to finish in external flash memory. Poll the external memory BUSY bit.*/
    do
    {        
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the current operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        
        /* Interrogate external memory state. */
        eRetVal = Fls_Qspi_CheckExtMemIsIdle(u32SectorIndex);
        
        /* If the external memory is not in an idle state, attempt to reset through the user configurable callout. */
        if(FLASH_E_PENDING == eRetVal)
        {
            /* If enabled, call the FlsQspiResetCallout, for checking and resetting the external memory to a usable state. */
            if( NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfResetCallout )
            {
                /* Call FlsQspiResetCallout function if configured. */
                Fls_pConfigPtr->pFlsQspiCfgConfig->pfResetCallout();
            }
            /*else
            {
                Callback notification configured as null pointer.            
            }*/
        }
        
        /* Check if interrogation encountered any errors. */
        if(FLASH_E_FAILED == eRetVal)
        {
            /* Error, the interrogation failed. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
    }while( FLASH_E_PENDING == eRetVal );  /* FLASH_E_OK(ext. mem. idle), FLASH_E_PENDING(write in progress) or FLASH_E_FAILED(write or get status cmd. failed). */
      
    return eRetVal;
}

#if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
/** 
* @brief        Read the external device ID.
*
* @details      The function reads the device ID of the external memory connected on the first port
*               of each QSPI IP instances.
*
* @param[in]    u8HwUnitCfgIndex - configuration device ID of the current hardware unit.
* @param[in]    p8DataReadPtr    - pointer to device ID variable placeholder.
* @param[out]   p8DataReadPtr    - pointer to device ID variable placeholder.
*
* @pre          Device ID parameter is not null, in the configuration.
* @pre          The general error reporting and "Unexpected Flash Id" particular error is enabled in the configuration.
* @post         The configured Device ID is checked against the read Device ID. Error is raised in case of mismatch.
*
* 
*    
*/    
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_ReadDeviceId
(   
    VAR(uint8, AUTOMATIC) u8HwUnitCfgIndex,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint8, AUTOMATIC) u8LUTReadIDId = 0U;
    VAR(uint8, AUTOMATIC) u8BytesToRead = 0U;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)    
    VAR(uint8, AUTOMATIC) u8LatCycls;
#endif

/* QSPI AMBA base address - used as base address, to determine the external CS used for an external transaction. */
static CONST(uint32, FLS_CONST) FLS_QSPI_AMBA_START_ADDR32[FLS_QSPI_AVAILABLE_UNITS] = 
{
    #ifdef QSPI_0_BASEADDR
        QSPI_QSPI_0_AMBA_BASE_U32
    #endif
    #ifdef QSPI_1_BASEADDR
        ,QSPI_QSPI_1_AMBA_BASE_U32
    #endif
};

        
    #if(FLS_TIMEOUT_HANDLING == STD_ON)    
        /* Initialize timeout counters */
        Fls_u32LLDTimeout_Counter = FLS_QSPI_SYNC_READ_TIMEOUT_VALUE;
    #endif
    
    /* Get HW IP base address and update the global variable to be used by the subsequent IP functions in the current scheduled read job. */
    Fls_Qspi_u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8HwUnitCfgIndex].eHwUnitName);
        
    /* Set the QSPI hardware unit start address, global variable. */
    Fls_Qspi_u32ExtSectStartAddr = FLS_QSPI_AMBA_START_ADDR32[(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8HwUnitCfgIndex].eHwUnitName];
       
    /* Use the Normal or Hyperflash LUT sequence. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
        /* Get LUT Read sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
        u8LUTReadIDId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8HwUnitCfgIndex].u8QspiLUTReadIdSeq;
        u8BytesToRead = 2U;     /* For normal QSPI mode, 2 bytes have to be read. */
    #else
        /* Hyperflash mode.*/ 
                
        if(FLASH_E_OK != Fls_Qspi_HyperEnterCfiAso())
        {
            /* Error, the operation has failed(possible timeout). */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        
        u8LatCycls = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiHyperflashLatCycls;
        
        if(FLASH_E_OK != Fls_Qspi_HyperPrepareReadLUT(u8LatCycls))
        {
            /* Error, the LUT setting failed due to timeout on lock/unlock. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        
        u8LUTReadIDId = FLS_LUT_SEQ_ID_15_U;  /* Fixed hard coded LUT ID number used for Hyperflash mode. */
        
        u8BytesToRead = 4U;     /* For Hyperflash QSPI mode, 4 bytes have to be read. */
    #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
    
    /* Set the start address of the IP read transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32ExtSectStartAddr );
    
    /* Set the Watermark value. */
    REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, 0U );   /* Expect maximum 1 word(4byte entries) */
    
    /* Clear reception flags, counters, prior to triggering the IP command. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
        
    /* Launch READ command. */
    Fls_Qspi_LaunchLUTCommand(u8LUTReadIDId, u8BytesToRead, 0U);
    
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    eRetVal = Fls_Qspi_ReadRXBuffer(u8BytesToRead, p8DataReadPtr, NULL_PTR);   /* Read the 2 bytes device ID. */
    
    /* For Hyperflash read device ID a byte swap is needed, the ID bytes are bus width aligned. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
        /* Hyperflash mode.*/ 
        /* For Hyperflash mode, use bytes 1 and 3. Word aspect: 0xMM00DD00 -> 0x____MMDD*/
        /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */        
        *p8DataReadPtr        = *(p8DataReadPtr + 1U);      /* p8DataReadPtr[0] = p8DataReadPtr[1] */
        /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
        *(p8DataReadPtr + 1U) = *(p8DataReadPtr + 3U);      /* p8DataReadPtr[1] = p8DataReadPtr[3] */
        
        /* Exit the Read DeviceID ASO mode, reset device to normal array read mode. */
        if(FLASH_E_OK != Fls_Qspi_HyperResetExitAso())
        {
            /* Error, the LUT setting failed due to timeout on lock/unlock. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
    #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */
    /*#else   
        Normal mode.
        No extra processing is needed.  */    
    
    return eRetVal;
}


#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
/** 
* @brief        Enters the Hyperflash ID-CFI ASO(Address Space Overlay)
*
* @details      Sends the Enter the Hyperflash ID-CFI ASO(Address Space Overlay) command, step (1.)
*                   1. CFI Enter   
*                       1.1.  (SA)+55   98
*                   2. ID-CFI Read
*                       2.1.  (SA)+RA   RD
*                   3. Reset / ASO Exit
*                       3.1.  XXX       F0/FF
*
* @param[in]    none
* @param[out]   none
*
* @pre          Hyperflash external memory and Hyperflash mode enabled in configuration.
* @pre          Error reporting enabled and device ID check enabled.
* @post         Hyperflash external memory is in ID-CFI ASO(Address space overlay).
*
* 
*    
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperEnterCfiAso(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
        
    /* Check if controller is busy(BUSY bit asserted). */
    if( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )
    {
        /* Error, controller is not idle. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* 1.1. Send the CFI Enter sequence. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_3_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0x98U);     /* Hyperflash sequence      ADDR: SA+0x55    CMD: 0x98 */
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Error, the write operation has timed out. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }   
 
    return eRetVal;
}

/** 
* @brief        Exits the Hyperflash ID-CFI ASO(Address Space Overlay)
*
* @details      Sends the Reset / ASO Exit command, step (3.)
*                   1. CFI Enter   
*                       1.1.  (SA)+55   98
*                   2. ID-CFI Read
*                       2.1.  (SA)+RA   RD
*                   3. Reset / ASO Exit
*                       3.1.  XXX       F0/FF
*
* @param[in]    none
* @param[out]   none
*
* @pre          Hyperflash external memory and Hyperflash mode enabled in configuration.
* @pre          Error reporting enabled and device ID check enabled.
* @post         Hyperflash external memory is in normal flash array read ASO(Address space overlay).
*
* 
*    
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperResetExitAso(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* 3.1. Send the Reset / ASO Exit command. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_4_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xF0U);     /* Reset / Exit ASO command ID. */
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Error, the write operation has timed out. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    return eRetVal;
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */

#endif /*#if(FLS_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) OR #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )*/

/** 
* @brief        Qspi flash sector read
*
* @details      Schedule and perform flash read jobs on external Qspi flash sectors.
*               Routes the flash read jobs to IP read interface or AHB read interface,
*               depending on the configuration options.
*
* @param[in]    u32StartAddr    - start address of the read job, as is needed by the QSPI IP controller.
*                                 the address represents the external sector address(as needed by 
                                  the external memory), offset-ed over the QSPI hardware channel offset
                                  (needed by the IP in order to select the proper external chip-select).
* @param[in]    u32DataLength   - read data length, number of bytes to be read by this job.
* @param[in]    p8DataReadPtr   - pointer to application buffer, used as destination and storage for the read data.
*                               - if the pointer is not null, the function performs a Read operation type and ignores the p8DataCmpPtr.
*                               - if the pointer is null, the function performs a Compare operation type and checks the p8DataCmpPtr to further decide.
* @param[in]    p8DataCmpPtr    - pointer to application buffer, used as source when comparing read data against a reference.
*                               - if the pointer is not null, the function performs a Compare/Verify Write operation type, checking the read data against the compare buffer.
*                               - if the pointer is null, the function performs a Blank check operation type, checking the read data against the flash erased value.
* @param[out]   p8DataReadPtr
*
* @pre          Fls_Qspi_u32ExtSectStartAddr global variable is updated and contains the sector start address 
*               offset-ed over the QSPI IP hardware channel offset
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
* @pre          Fls_Qspi_u8HwUnitCfgIndex global variable is updated and contains the index of the QSPI configuration
*               structure, for which this sector is assigned to.
*
* @post         none
*
*   
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SectorRead
(   
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
        
    /* Decide the read mode.*/
    if( (boolean)FALSE == (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_SECTOR_IRQ_MODE) )
    {   /* SYNC mode. */

        /* Call the appropriate read function, base on the configured access mode(AHB or IP mode). */
        if( FLS_IP_READ_MODE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].eQspiUnitReadBufferMode )
        {
            eRetVal = Fls_Qspi_IPRead(u32StartAddr, u32DataLength, p8DataReadPtr, p8DataCmpPtr);
        }
        else if( FLS_AHB_READ_MODE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].eQspiUnitReadBufferMode )
        {    
            eRetVal = Fls_Qspi_AHBRead(u32StartAddr, u32DataLength, p8DataReadPtr, p8DataCmpPtr);
        }
        else
        {
            /* Error, incorrect configuration parameter. */
            eRetVal = FLASH_E_FAILED;
        }
    }
    else
    {   /* IRQ mode. */
        #if(FLS_USE_INTERRUPTS == STD_ON)
        /* If the sector is configured to be read in IRQ mode, the use of IPRead is mandatory, and overrides the configuration read mode.*/
        eRetVal = Fls_Qspi_IPRead(u32StartAddr, u32DataLength, p8DataReadPtr, p8DataCmpPtr);
        #endif
    }    
    
    /* Check if there is any error from external flash chip */
    if(NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfEccCheckCallout)
    {
        if( (Std_ReturnType)E_NOT_OK == Fls_pConfigPtr->pFlsQspiCfgConfig->pfEccCheckCallout((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectCh))[Fls_u32JobSectorIt], u32StartAddr, u32DataLength ))
        {
           /* There is error from the external flash chip */
           eRetVal = FLASH_E_FAILED;
        }
    }
    return eRetVal;
}


/** 
* @brief        Qspi invalidate AHB buffers content.
*
* @details      Reset,invalidate the content of the AHB buffers. Before performing a read using 
*               the AHB interface, the buffers have to be invalidated in case there was any
*               erase or program operation which might have modified the content of the external memory. 
*
* @param[in]    none
* @param[out]   none
*
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
*
* @post         AHB buffers are empty, any read access will trigger an external transaction to fill the buffers.
*
*   
*/
static FUNC(void, FLS_CODE) Fls_Qspi_InvalidateAhbBuffers( void )
{
    /* Enable QSPIx module (MCR[MDIS] = 0) before asserting the reset bits. */
    REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);
           
    /* Software reset AHB domain and Serial Flash domain at the same time. */
    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, (QSPI_MCR_SWRSTHD_U32 | QSPI_MCR_SWRSTSD_U32) );
        
    /* Disable QSPIx module (MCR[MDIS] = 1) before de-asserting the reset bits. */
    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);
           
    /* De-asset Software reset AHB domain and Serial Flash domain bits. */
    REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, (QSPI_MCR_SWRSTHD_U32 | QSPI_MCR_SWRSTSD_U32) );
        
    /* Re-enable QSPIx module (MCR[MDIS] = 0) after reset. */
    REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);
}

/** 
* @brief        Qspi launch a LUT command.
*
* @details      Launch a LUT command, sequence, in IP mode.
*
* @param[in]    u8LUTId     - id of the LUT sequence used in the command. upon this ID write, the external transaction is started.
* @param[in]    u32DataSize - data size(number of bytes) of the external transaction(used for read/write commands). when this value is 
*                             not zero, it overrides the transaction length set in the LUT commands.
* @param[in]    u8ParEn     - parity enabled. if enabled, the external transaction is sent to both external parallel channels.
* @param[out]   none
*
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
*
* @post         External transaction is triggered on the QSPI external lines.
*
*   
*/
static FUNC(void, FLS_CODE) Fls_Qspi_LaunchLUTCommand
(
    CONST(uint8, AUTOMATIC) u8LUTId,
    CONST(uint8, AUTOMATIC) u8DataSize,
    CONST(uint8, AUTOMATIC) u8ParEn
)
{   
    /* Set transfer size and launch LUT[u8LUTId] command, by writing the LUT sequence ID. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32,
                 ( (uint32)u8LUTId << QSPI_IPCR_SEQID_SHIFT_U32 ) | ((uint32)u8ParEn << QSPI_IPCR_PAR_EN_SHIFT_U32) | ( (uint32)u8DataSize << QSPI_IPCR_IDATSZ_SHIFT_U32 ) 
               );
}


/** 
* @brief        Get the index of the HW unit configuration structure.
*
* @details      Get the index of the HW unit configuration structure inside the configuration array.
*               Used to find the configuration structure containing configurations parameters associated to the
*               HW unit(QSPI_0, QSPI_1) for the associated HW channel.
*
* @param[in]    eHwUnitName     - name of the QSPI hardware unit (QSPI_0, QSPI_1).
* @param[out]   none
*
* @pre          none
*
* @post         none
*
*   
*/
FUNC( uint8, FLS_CODE ) Fls_Qspi_GetHwUnitCfgIndex( CONST( Fls_QspiUnitNameType, AUTOMATIC ) eHwUnitName )
{
    VAR(uint8, AUTOMATIC) u8HwUnitCfgIndex = 0U;
    VAR(uint8, AUTOMATIC) u8Iter = 0U;
    
    /* Loop through all configured HW units. */
    for( u8Iter = 0U; u8Iter < Fls_pConfigPtr->pFlsQspiCfgConfig->u8QspiUnitsCount; u8Iter++ )
    {
        if( eHwUnitName == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8Iter].eHwUnitName )
        {
            u8HwUnitCfgIndex = u8Iter;
        }
    }        
    
    return u8HwUnitCfgIndex;
}

/** 
* @brief        Qspi IP mode read.
*
* @details      Performs a read job in IP mode, using the RXBuffer and manually triggered commands.
*
* @param[in]    u32StartAddr    - start address of the read job, as is needed by the QSPI IP controller.
*                                 the address represents the external sector address(as needed by 
                                  the external memory), offset-ed over the QSPI hardware channel offset
                                  (needed by the IP in order to select the proper external chip-select).
* @param[in]    u32DataLength   - read data length, number of bytes to be read by this job.
* @param[in]    p8DataReadPtr   - pointer to application buffer, used as destination and storage for the read data.
*                               - if the pointer is not null, the function performs a Read operation type and ignores the p8DataCmpPtr.
*                               - if the pointer is null, the function performs a Compare operation type and checks the p8DataCmpPtr to further decide.
* @param[in]    p8DataCmpPtr    - pointer to application buffer, used as source when comparing read data against a reference.
*                               - if the pointer is not null, the function performs a Compare/Verify Write operation type, checking the read data against the compare buffer.
*                               - if the pointer is null, the function performs a Blank check operation type, checking the read data against the flash erased value.
* @param[out]   p8DataReadPtr
*
* @pre          Fls_Qspi_u32ExtSectStartAddr global variable is updated and contains the sector start address 
*               offset-ed over the QSPI IP hardware channel offset
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
* @pre          Fls_Qspi_u8HwUnitCfgIndex global variable is updated and contains the index of the QSPI configuration
*               structure, for which this sector is assigned to.
*
* @post         none
*
*   
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IPRead
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint8, AUTOMATIC) u8LUTReadId;    
    VAR(uint8, AUTOMATIC) u8ParEn;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
    VAR(uint8, AUTOMATIC) u8LatCycls;        
#endif  
    
            
    /* Check if controller is not busy(BUSY bit asserted). */   
    if(FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle())
    {
        /* Error, the controller is busy. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Use the Normal or Hyperflash LUT sequence. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
        /* Get LUT Read sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
        u8LUTReadId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTReadSeq;
    #else   
        /* Hyperflash mode. */
        u8LatCycls = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiHyperflashLatCycls;     

        eRetVal = Fls_Qspi_HyperPrepareReadLUT(u8LatCycls);
        if(FLASH_E_OK != eRetVal)
        {
            /* Error, the LUT setting failed due to timeout on lock/unlock. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }        
        
        u8LUTReadId = FLS_LUT_SEQ_ID_15_U;
    #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
        
    /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
    {
        u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
    }
    else /* FLS_QSPI_CH_INDIVIDUAL */
    {
        u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
    }
    
    /* Clear reception flags, counters, prior to triggering the IP command. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
    
    if( (boolean)FALSE == (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_SECTOR_IRQ_MODE) )
    {
        /* Synchronous read mode. */               
    
        #if(FLS_TIMEOUT_HANDLING == STD_ON)    
            /* Initialize timeout counters */
            if( (FLS_JOB_READ == Fls_eJob) || (FLS_JOB_COMPARE == Fls_eJob) 
                || (FLS_JOB_BLANK_CHECK == Fls_eJob) 
            )
            {
                /* Update the timeout counter only if a specific read job is in progress, otherwise,
                for and erase or write job the timeout counter is already set in their specific functions.*/
                Fls_u32LLDTimeout_Counter = FLS_QSPI_SYNC_READ_TIMEOUT_VALUE;
            }
        #endif 
                
        /* Read loop. */
        do
        {
            VAR(uint8, AUTOMATIC) u8BytesToRead = 0U;
        
            /* Set the start address of the IP read transaction ("u32StartAddr" is updated at the end of the loop for multiple iterations). */
            REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );
            
            if( u32DataLength > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
            {
                /* Set WMRK level. More than the entire size of RXBuffer is needed to be read, so set the Watermark level to it s maximum value(32x4 byte entries). */
                u8BytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, QSPI_RXBUFFER_MAX_SIZE_WORDS_U32 - 1U );   /* Expect 31 + 1 words(4byte entries) */            
            }
            else /* if( u32DataLength > 0U ) */
            {
                /* Set WMRK level. At least one byte needed to be read. If less than 4 bytes to read, the Watermark level is set to 0U. */
                u8BytesToRead = (uint8)u32DataLength;
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)((((uint32)u8BytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */    
            }
            
            /* Launch READ command. */
            Fls_Qspi_LaunchLUTCommand(u8LUTReadId, u8BytesToRead, u8ParEn);   
            
            /* Wait for transaction to finish. */
            while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
            {
                #if (FLS_TIMEOUT_HANDLING == STD_ON)
                    if( 0U == Fls_u32LLDTimeout_Counter )
                    {
                        /* Error, the write operation has timed out. */
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_FAILED;
                    }
                    Fls_u32LLDTimeout_Counter--;
                #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            }        
                   
            /* Read received data from RX Buffer. */
            /* Read "u8BytesToRead" bytes into "p8DataReadPtr", or compare them against "p8DataCmpPtr". */
            eRetVal = Fls_Qspi_ReadRXBuffer(u8BytesToRead, p8DataReadPtr, p8DataCmpPtr);
            /* Update the local data pointers with the number of bytes read above. */
            if( NULL_PTR != p8DataReadPtr )
            {
                /* The read pointer was used in the Fls_Qspi_ReadRXBuffer() function, so update it.*/
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataReadPtr = p8DataReadPtr + u8BytesToRead;    
            }
            if( NULL_PTR != p8DataCmpPtr )
            {
                /* The compare pointer was used in the Fls_Qspi_ReadRXBuffer() function, so update it.*/
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataCmpPtr = p8DataCmpPtr + u8BytesToRead; 
            }
            
            /* Update external read address, in case it is needed for another loop iteration. */
            u32StartAddr += u8BytesToRead;
            /* Update remaining data length. */
            u32DataLength = u32DataLength - u8BytesToRead; 
            
        }while( (u32DataLength > 0U) && (FLASH_E_OK == eRetVal) );
    }
    else /* if( (boolean)TRUE == (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_SECTOR_IRQ_MODE) ) */
    {            
        /* IRQ read mode. */
    #if(FLS_USE_INTERRUPTS == STD_ON)          
        VAR(uint8, AUTOMATIC) u8BytesToRead = 0U;
    
        #if(FLS_TIMEOUT_HANDLING == STD_ON)  
        if(MEMIF_JOB_PENDING != Fls_eLLDJobResult)  /* Initialize the timer only if there is no pending job already set, because this functions is called for all types of job(read, write, erase) and to avoid overwriting it. */
        {
            /* Initialize timeout counters */            
            if( (FLS_JOB_READ == Fls_eJob) || (FLS_JOB_COMPARE == Fls_eJob) 
                || (FLS_JOB_BLANK_CHECK == Fls_eJob) 
            )
            {
                /* Update the timeout counter only if a specific read job is in progress, otherwise,
                for and erase or write job the timeout counter is already set in their specific functions.*/
                Fls_u32LLDTimeout_Counter = FLS_QSPI_IRQ_READ_TIMEOUT_VALUE;
            }
            
        }
        #endif
        
        Fls_u32LLDRemainingDataToRead = u32DataLength;      /* Total number of bytes to be read in IRQ mode for this batch(until MaxRead or sector boundary). */
        /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
        if( u32DataLength > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
        {
            /* The number of bytes to be read/expected in the firs IRQ iteration. */
            Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
        }
        else /* if( u32DataLength < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
        {
            /* The number of bytes to be read/expected in the firs IRQ iteration. */
            Fls_Qspi_u8LLDBytesToRead = (uint8)u32DataLength;
        }
        
        /* Set the Watermark level, upon which the RX interrupt will be triggered. */
        u8BytesToRead = Fls_Qspi_u8LLDBytesToRead;  /* Intermediate variable used to avoid order of evaluation issue caused by volatile specifier. */
        REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)(( ((uint32)u8BytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
             
        /* Set the start address of the IP read transaction (if more IRQ transactions are needed, the start address is updated in the IRQ routine). */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );     
        
        /* Store the operation type intended: read, compare, blank check or write verify. */
        if( NULL_PTR != p8DataReadPtr )
        {   
            /* Read operation type. */
            Fls_eLLDIrqJob = FLASH_IRQ_JOB_READ;                /* Mark the job type which has to be executed in interrupt context. */            
            Fls_Qspi_u32MemoryAddress = u32StartAddr;            /* Set the flash address(memory mapped) from where to read the data. */
            /* Compiler_Warning: see fls_c_REF_CW_02 */
            Fls_Qspi_u32BufferAddress = (uint32)p8DataReadPtr;   /* Set the target address, in the application buffer, where to store the read data. */
        }  
        else /* No read operation intended, only a compare type operation. */
        {
            if( NULL_PTR != p8DataCmpPtr )
            {
                /* Compare or Write Verify operation type). */
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_COMPARE;             /* Mark the job type which has to be executed in interrupt context. */            
                Fls_Qspi_u32MemoryAddress = u32StartAddr;            /* Set the flash address(memory mapped) from where to read the data. */
                /* Compiler_Warning: see fls_c_REF_CW_02 */
                Fls_Qspi_u32BufferAddress = (uint32)p8DataCmpPtr;    /* Set the target address, in the application buffer, against which to compare the read data. */
            }
            else /* Both "p8DataReadPtr" and "p8DataCmpPtr" are null, so a blank check operatio type is intended. */
            {
                /* Blank Check operation type. */
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK;         /* Mark the job type which has to be executed in interrupt context. */                
                Fls_Qspi_u32MemoryAddress = u32StartAddr;            /* Set the flash address(memory mapped) from where to read the data. */
            }
        }        
               
        Fls_eLLDJobResult = MEMIF_JOB_PENDING;        
        eRetVal = FLASH_E_PENDING;    
                                
        /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);
        /* Enable the Receive Buffer Drain Interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32); 

        /* Launch READ command. */
        Fls_Qspi_LaunchLUTCommand(u8LUTReadId, Fls_Qspi_u8LLDBytesToRead, u8ParEn);
    #endif    
    }  
    
    return eRetVal;
}

/** 
* @brief        Qspi AHB mode read.
*
* @details      Performs a read job in AHB mode, using the AHB buffers and automatically triggered commands.
*
* @param[in]    u32StartAddr    - start address of the read job, as is needed by the QSPI IP controller.
*                                 the address represents the external sector address(as needed by 
                                  the external memory), offset-ed over the QSPI hardware channel offset
                                  (needed by the IP in order to select the proper external chip-select).
* @param[in]    u32DataLength   - read data length, number of bytes to be read by this job.
* @param[in]    p8DataReadPtr   - pointer to application buffer, used as destination and storage for the read data.
*                               - if the pointer is not null, the function performs a Read operation type and ignores the p8DataCmpPtr.
*                               - if the pointer is null, the function performs a Compare operation type and checks the p8DataCmpPtr to further decide.
* @param[in]    p8DataCmpPtr    - pointer to application buffer, used as source when comparing read data against a reference.
*                               - if the pointer is not null, the function performs a Compare/Verify Write operation type, checking the read data against the compare buffer.
*                               - if the pointer is null, the function performs a Blank check operation type, checking the read data against the flash erased value.
* @param[out]   p8DataReadPtr
*
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
* @pre          Fls_Qspi_u8HwUnitCfgIndex global variable is updated and contains the index of the QSPI configuration
*               structure, for which this sector is assigned to.
*
* @post         none
*
*   
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_AHBRead
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint8, AUTOMATIC) u8LUTReadId; 
    VAR(uint8, AUTOMATIC) u8ParEn; 
#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
    VAR(uint8, AUTOMATIC) u8LatCycls;        
#endif  
      
    /* Data prefetch transfer size(size of each external read transaction) is set in Fls_Init() from the configuration and into BUFxCR[ADATSZ],
       or it is overridden by the data transfer size from the LUT sequence, in case the first one from configuration is 0. */
    
    /* Use the Normal or Hyperflash LUT sequence. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
        /* Get LUT Read sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
        u8LUTReadId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTReadSeq;
    #else
        /* Hyperflash mode.*/         
        u8LatCycls = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiHyperflashLatCycls;     

        eRetVal = Fls_Qspi_HyperPrepareReadLUT(u8LatCycls);
        if(FLASH_E_OK != eRetVal)
        {
            /* Error, the LUT setting failed due to timeout on lock/unlock. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        
        u8LUTReadId = FLS_LUT_SEQ_ID_15_U;
    #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
    
    /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
    {
        u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
    }
    else /* FLS_QSPI_CH_INDIVIDUAL */
    {
        u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
    }
    
    /* Provide sequence LUT ID into the buffer configuration register (QSPI_BFGENCR[SEQID]). */
    REG_WRITE32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_BFGENCR_OFFSET_U32, 
                ((uint32)u8ParEn << QSPI_BFGENCR_PAR_EN_SHIFT_U32) | ((uint32)u8LUTReadId << QSPI_BFGENCR_SEQID_SHIFT_U32) 
               );
    #if(FLS_TIMEOUT_HANDLING == STD_ON)    
        /* Initialize timeout counters */        
        if( (FLS_JOB_READ == Fls_eJob) || (FLS_JOB_COMPARE == Fls_eJob) 
                || (FLS_JOB_BLANK_CHECK == Fls_eJob) 
            )
            {
                /* Update the timeout counter only if a specific read job is in progress, otherwise,
                for and erase or write job the timeout counter is already set in their specific functions.*/
                Fls_u32LLDTimeout_Counter = FLS_QSPI_SYNC_READ_TIMEOUT_VALUE;
            }
    #endif
       
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0UL == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }            
    
    /* Invalidate the AHB buffers. If the content of the flash is changed by write/erase operations,
       the content of the AHB buffers needs to be invalidated. According to spec, both the AHB and Serial
       flash domain have to be reset at the same time. */
    Fls_Qspi_InvalidateAhbBuffers();
#if (STD_ON == FLS_SYNCRONIZE_CACHE)        
    /* Invalidate flash, before the flash read access */                                                         
    if((Std_ReturnType)E_OK != Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, u32StartAddr, u32DataLength))
    {
        /* Cache operation invalidation unsuccessful. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
#endif /* MCAL_CACHE_RUNTIME_MNGMNT */     
    
    
    /* Clear the error flags (w1c) before reading. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_ILLINE_U32 | QSPI_FR_ABSEF_U32 | QSPI_FR_AITEF_U32 | QSPI_FR_AIBSEF_U32 | QSPI_FR_ABOF_U32 );
    
    do
    {
        /* Read aligned word entries if they exist. */
        /* Compiler_Warning: see fls_c_REF_CW_02 */
        if( (0U == (u32StartAddr % 4U)) && (0U == ((uint32)p8DataReadPtr % 4U)) && (4U <= u32DataLength) )  /* An aligned entry(32bits, 4 bytes) and at least 4bytes have to be read. */
        {   
            /* Check what operation is intended: read, compare, blank check or write verify. */
            if( NULL_PTR != p8DataReadPtr )
            { 
                /* Read operation type. */
                /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
                /* Compiler_Warning: see fls_c_REF_CW_02 */
                *((volatile uint32 *)p8DataReadPtr) = *((volatile uint32 *)u32StartAddr);
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataReadPtr += 4U;    /* Increment 4 bytes. */
            }  
            else /* No read operation intended, only a compare type operation. */
            {
                if( NULL_PTR != p8DataCmpPtr )
                {
                    VAR(uint32, AUTOMATIC) u32ApplData = 0UL; 
                    VAR(uint32, AUTOMATIC) u32MemData = 0UL; 
                    
                    /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
                    u32ApplData = *((volatile const uint32 *)p8DataCmpPtr);
                    /* Compiler_Warning: see fls_c_REF_CW_02 */
                    u32MemData = *((volatile uint32 *)u32StartAddr);
                    
                    /* Compare or Write Verify operation type). */ 
                    if( u32ApplData != u32MemData )
                    {
                        /* Error, data read does not match the provided compare buffer.*/
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_BLOCK_INCONSISTENT;
                    }
                    /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                    p8DataCmpPtr += 4U;    /* Increment 4 bytes. */
                }
                else /* Both "p8DataReadPtr" and "p8DataCmpPtr" are null, so a blank check operation type is intended. */
                {
                    /* Blank Check operation type. */
                    /* Compiler_Warning: see fls_c_REF_CW_02 */
                    if( FLS_ERASED_VALUE != *((volatile uint32 *)u32StartAddr) )
                    {
                        /* Error, data read does not match the provided compare buffer.*/
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_BLOCK_INCONSISTENT;
                    }
                }             
            }
            /* Update the counters, the address in memory from where data is read and the total number of bytes to be read. */
            u32StartAddr += 4U;
            u32DataLength -= 4U;
        }            
        else /* if( (0U != (u32StartAddr % 4U)) || (4U > u32DataLength) ), read unaligned or byte entries. */
        {   
            /* Check what operation is intended: read, compare, blank check or write verify. */
            if( NULL_PTR != p8DataReadPtr )
            { 
                /* Read operation type. */
                /* Compiler_Warning: see fls_c_REF_CW_02 */
                *p8DataReadPtr = *((volatile uint8 *)u32StartAddr);
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataReadPtr += 1U;    /* Increment 1 bytes. */
            }  
            else /* No read operation intended, only a compare type operation. */
            {
                if( NULL_PTR != p8DataCmpPtr )
                {
                    /* Compare or Write Verify operation type). */ 
                    /* Compiler_Warning: see fls_c_REF_CW_02 */
                    if( *p8DataCmpPtr != *((volatile uint8 *)u32StartAddr) )
                    {
                        /* Error, data read does not match the provided compare buffer.*/
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_BLOCK_INCONSISTENT;
                    }
                    /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                    p8DataCmpPtr += 1U; /* Increment 1 byte. */
                }
                else /* Both "p8DataReadPtr" and "p8DataCmpPtr" are null, so a blank check operation type is intended. */
                {
                    /* Blank Check operation type. */
                    /* Compiler_Warning: see fls_c_REF_CW_02 */
                    if( (uint8)FLS_ERASED_VALUE != *((volatile uint8 *)u32StartAddr) )
                    {
                        /* Error, data read does not match the provided compare buffer.*/
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_BLOCK_INCONSISTENT;
                    }
                }   
            }
            /* Update the counters, the address in memory from where data is read and the total number of bytes to be read. */
            u32StartAddr += 1U;
            u32DataLength -= 1U; 
        }   
    }while(u32DataLength > 0U);

    /* Check errors from QSPI_FR. */
    if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_ILLINE_U32 | QSPI_FR_ABSEF_U32 | QSPI_FR_AITEF_U32 | QSPI_FR_AIBSEF_U32 | QSPI_FR_ABOF_U32 ) )
    {
        /* Clear the error flags (w1c). */
        REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_ILLINE_U32 | QSPI_FR_ABSEF_U32 | QSPI_FR_AITEF_U32 | QSPI_FR_AIBSEF_U32 | QSPI_FR_ABOF_U32 );
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
        
    return eRetVal;
}

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
/** 
* @brief        Prepare the LUT sequence for Hyperflash read operations.
*
* @details      Load a predefined LUT sequence(the last one, no.15) with the instruction/operand pairs
*               corresponding to a valid Hyperflash read command. 
*
* @param[in]    u8LatCycls     - number of latency cycles to be sent as dummy cycles to the memory.
* @param[out]   none
*
* @pre          none
*
* @post         LUT sequence no.15 populated with a read sequence.
*
*   
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareReadLUT(VAR(uint8, AUTOMATIC) u8LatCycls)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,    FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,  
                                                                                FLS_LUT_INSTR_CMD_DDR,     FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_READ_MEM_LINEAR
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_DUMMY,       FLS_LUT_PAD_8_PADS, u8LatCycls,  
                                                                                FLS_LUT_INSTR_CADDR_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,        FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_READ_DDR,    FLS_LUT_PAD_8_PADS, 2U
                                                                              ) 
                             );  /* READ_DDR 2 bytes, length overridden by the IDATSZ field. */
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    return eRetVal;
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */

/** 
* @brief        Read the RX Buffer.
*
* @details      Read data from the RX Buffer, as part of a read transaction in IP mode and if
*               needed perform also the compare operations. 
*
* @param[in]    u8BytesToRead   - read data length, number of bytes to be read by this job.
* @param[in]    p8DataReadPtr   - pointer to application buffer, used as destination and storage for the read data.
*                               - if the pointer is not null, the function performs a Read operation type and ignores the p8DataCmpPtr.
*                               - if the pointer is null, the function performs a Compare operation type and checks the p8DataCmpPtr to further decide.
* @param[in]    p8DataCmpPtr    - pointer to application buffer, used as source when comparing read data against a reference.
*                               - if the pointer is not null, the function performs a Compare/Verify Write operation type, checking the read data against the compare buffer.
*                               - if the pointer is null, the function performs a Blank check operation type, checking the read data against the flash erased value.
* @param[out]   p8DataReadPtr
*
* @param[ret]   FLASH_E_OK      - Read successful.
*               FLASH_E_FAILED  - Error during read transaction: controller busy, incorrect number of bytes received, error flags set.
*
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
*
* @post         RX Buffer is cleared, transmission and error flags are reset.
*
*   
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_ReadRXBuffer
(
    VAR(uint8, AUTOMATIC) u8BytesToRead,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
)
{
    VAR(Fls_AddressType, AUTOMATIC) u32RXBuffBaseAddr;        
    VAR(uint8, AUTOMATIC) u8Iter = 0U;
    
    /* Check that at least the expected number of words were received, WMRK words level reached. */
    if( 0U ==  REG_BIT_GET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SR_OFFSET_U32, QSPI_SR_RXWE_U32) )  /* Poll RXWE bit. */
    {
        /* Error, the expected number of words were not received. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Check that no more than the expected number of words were received, RDBFL words level not exceeded. */
    if( (uint32)(((uint32)u8BytesToRead + 3U) / 4U)  < (uint32)( (REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RBSR_OFFSET_U32) & QSPI_RBSR_RDBFL_MASK_U32) >> QSPI_RBSR_RDBFL_SHIFT_U32 ) )  
    {
        /* Error, the expected number of words was exceeded. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Check errors from QSPI_FR. */
    if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
    {
        /* Clear the errors (w1c). */
        REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Read received data from RX Buffer, if the expected number of bytes was received. */

    /* Get RX Buffer base address, used for reading RXBuffer through AHB bus(ARDB base addr) or IP bus(RXBRD base addr). */
    if( FLS_RXBUFFER_AHB_BUS_ACCESS == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].eQspiUnitRxBufferAccessMode )
    {
        /* RX Buffer content is read using the AHB Bus registers QSPI_ARDB0 to QSPI_ARDB31. */
        u32RXBuffBaseAddr = FLS_QSPI_ARDB_BASE_ADDR32[ (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitSectorAssign))[Fls_u32JobSectorIt] ];
    #if (STD_ON == FLS_SYNCRONIZE_CACHE)        
        /* Invalidate flash, before the flash read access */                                                         
        if((Std_ReturnType)E_OK != Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, u32RXBuffBaseAddr, (uint32)u8BytesToRead))
        {
            /* Cache operation invalidation unsuccessful. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
    #endif /* MCAL_CACHE_RUNTIME_MNGMNT */         
    }
    else /*if( FLS_RXBUFFER_IP_BUS_ACCESS == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].eQspiUnitRxBufferAccessMode )*/
    {
        /* RX Buffer content is read using the IP Bus registers QSPI_RBDR0 to QSPI_RBDR31. */
        u32RXBuffBaseAddr = Fls_Qspi_u32HwUnitBaseAddr + QSPI_RBDR_OFFSET_U32;
    }
    
    do
    {
        /* Read aligned word entries if they exist. */
        /* Compiler_Warning: see fls_c_REF_CW_02 */
        if ( (0U == ((uint32)p8DataReadPtr % 4U)) && (0U == ((u32RXBuffBaseAddr + (uint32)u8Iter) % 4U)) && (4U <= u8BytesToRead) )  /* An aligned entry(32bits, 4 bytes) and at least 4bytes have to be read. */
        {
            /* Check what operation is intended: read, compare, blank check or write verify. */
            if( NULL_PTR != p8DataReadPtr)
            {   
                /* Read operation type. */
                /* Read RX Buffer 32bit entry and copy it into the application read buffer. */
                /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
                *((volatile uint32 *)p8DataReadPtr) = REG_READ32( u32RXBuffBaseAddr + ((uint32)u8Iter) );
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataReadPtr += 4U; /* Increment 4 bytes. */
            } 
            else /* No read operation intended, only a compare type operation. */
            {
               if( NULL_PTR != p8DataCmpPtr )
                {
                   VAR(uint32, AUTOMATIC) u32ApplData = 0UL; 
                   VAR(uint32, AUTOMATIC) u32MemData = 0UL; 
                   
                   /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
                   u32ApplData = *((volatile const uint32 *)p8DataCmpPtr);
                   u32MemData = REG_READ32(u32RXBuffBaseAddr + ((uint32)u8Iter));
                       
                   /* Compare or Write Verify operation type). */
                   if( u32ApplData != u32MemData )
                   {
                       /* Error, data read does not match the provided compare buffer.*/
                       /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                       return FLASH_E_BLOCK_INCONSISTENT;
                   }
                   /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                   p8DataCmpPtr += 4U; /* Increment 4 bytes. */
                }
               else /* Both "p8DataReadPtr" and "p8DataCmpPtr" are null, so a blank check operatio type is intended. */
               {
                   /* Blank Check operation type. */
                   if( FLS_ERASED_VALUE != REG_READ32(u32RXBuffBaseAddr + ((uint32)u8Iter)) )
                   {
                       /* Error, data read does not match the provided compare buffer.*/
                       /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                       return FLASH_E_BLOCK_INCONSISTENT;
                   }
               }
            }
            /* Update the counters, and the total number of bytes to be read. */
            u8Iter += 4U; 
            u8BytesToRead -= 4U;
        }
        else  /* If read unaligned or byte entries. */
        {
            if( NULL_PTR != p8DataReadPtr )
            {   
                /* Read operation type. */
                *p8DataReadPtr = REG_READ8( u32RXBuffBaseAddr + ((uint32)u8Iter) );
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataReadPtr += 1U;    /* Increment 1 bytes. */
            }  
            else /* No read operation intended, only a compare type operation. */
            {
                if( NULL_PTR != p8DataCmpPtr )
                {
                    /* Compare or Write Verify operation type). */
                    if( (uint8)(*p8DataCmpPtr) != REG_READ8( u32RXBuffBaseAddr + ((uint32)u8Iter) ) )
                    {
                        /* Error, data read does not match the provided compare buffer.*/
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_BLOCK_INCONSISTENT;
                    }
                    /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                    p8DataCmpPtr += 1U; /* Increment 1 bytes. */
                }
                else /* Both "p8DataReadPtr" and "p8DataCmpPtr" are null, so a blank check operatio type is intended. */
                {
                    /* Blank Check operation type. */
                    if( (uint8)FLS_ERASED_VALUE != REG_READ8( u32RXBuffBaseAddr + ((uint32)u8Iter) ) )
                    {
                        /* Error, data read does not match the provided compare buffer.*/
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_BLOCK_INCONSISTENT;
                    }
                }
            }
            /* Update the counters, and the total number of bytes to be read. */
            u8Iter += 1U; 
            u8BytesToRead -= 1U;
        }
    }while(u8BytesToRead > 0U); 

    /* Clear the RX Buffer and reception flags, counters. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    
    return FLASH_E_OK;
}

/**
* @brief          Erase one complete flash sector.
*
* @param[in]      u32PhysicalSectorSize     Physical sector size, used for blank check verifications
* @param[in]      bAsynch                   FALSE for synchronous function operation, erase is blocking and finished at the end of the function call.
*                                           TRUE for asynchronous operation, when the sector is erased either Asynchronously or in IRQ mode,
*                                                erase is not blocking, only started in this function finished in the Fls_Qspi_MainFunctionErase or ISR.
*
* @return       Fls_LLDReturnType
* @retval       FLASH_E_OK Operation succeeded
* @retval       FLASH_E_FAILED Operation failed due to hardware error
* @retval       FLASH_E_PENDING The operation has not yet been finished 
*               (only for asynchronous operation )
*
* @pre          The module must be initialized
* @pre          Fls_Qspi_u32ExtSectStartAddr global variable is updated and contains the sector start address 
*               offset-ed over the QSPI IP hardware channel offset
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
* @pre          Fls_Qspi_u8HwUnitCfgIndex global variable is updated and contains the index of the QSPI configuration
*               structure, for which this sector is assigned to.
*
*
*
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_SectorErase
( 
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST(Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif
    VAR( boolean, AUTOMATIC ) bAsynch 
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
    VAR(uint8, AUTOMATIC) u8LUTEraseId;
    VAR(uint8, AUTOMATIC) u8ParEn;
#endif       
       
    /* Store the address of the sector start, at which the erase is executed. */   
    Fls_Qspi_u32MemoryAddress =  Fls_Qspi_u32ExtSectStartAddr;
            
#if(FLS_TIMEOUT_HANDLING == STD_ON)    
    /* Initialize timeout counters */
    if( (boolean)FALSE == bAsynch ) /* SYNC mode. */
    {
        Fls_u32LLDTimeout_Counter = FLS_QSPI_SYNC_ERASE_TIMEOUT_VALUE;
    }
    else /* ASYNC mode. */
    {
        if( (boolean)FALSE != (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_SECTOR_ERASE_ASYNCH) )
        { /* ASYNC mode, no IRQ processing. */
            Fls_u32LLDTimeout_Counter = FLS_QSPI_ASYNC_ERASE_TIMEOUT_VALUE;           
        }
        else
        { 
            #if(FLS_USE_INTERRUPTS == STD_ON)
            Fls_u32LLDTimeout_Counter = FLS_QSPI_IRQ_ERASE_TIMEOUT_VALUE;
            #endif
            /* IRQ mode. */
        }
    }        
#endif 
        
    /* Check if controller is busy(BUSY bit asserted) and wait for transaction to finish in uC, if there is any ongoing AHB buffer prefetch read triggered by a previous verify operation. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0UL == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write enable operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
         
    /* Use the Normal or Hyperflash LUT sequence. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)     
        /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
        if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
        {
            u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
        }
        else /* FLS_QSPI_CH_INDIVIDUAL */
        {
            u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
        }
        
        /* Enable the Write/Erase operation on the external memory. */ 
        if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
        {
            /* Error, WriteEnable command has failed. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
       
        /* Get LUT Erase sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
        u8LUTEraseId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTEraseSeq;
    
        /* Set the start address of the IP erase transaction. */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
    
        /* Clear the errors (w1c). */
        REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
    
        Fls_Qspi_LaunchLUTCommand(u8LUTEraseId, 0U, u8ParEn);
    #else
        /* Hyperflash mode. */

        eRetVal = Fls_Qspi_HyperPrepareLaunchErase();
        if( FLASH_E_OK != eRetVal)
        {
            /* Error, the command sequences required for Hyperflash mode erase have failed. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }        
    #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
    
    if( (boolean)FALSE == bAsynch ) /* SYNC mode. */
    {
        /* Wait for transaction to finish in uC. */
        while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
        {
            #if (FLS_TIMEOUT_HANDLING == STD_ON)
                if( 0U == Fls_u32LLDTimeout_Counter )
                {
                    /* Error, the write operation has timed out. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                Fls_u32LLDTimeout_Counter--;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        } 
        
        /* Check the error flags. */
        if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
        {
            /* Error, error flags were set during programming. */
            /* Clear the errors (w1c). */
            REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }   
            
        /* Wait for transaction to finish in external flash memory. Poll the external memory BUSY bit.*/
        do
        {
            #if (FLS_TIMEOUT_HANDLING == STD_ON)
                if( 0U == Fls_u32LLDTimeout_Counter )
                {
                    /* Error, the write operation has timed out. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                Fls_u32LLDTimeout_Counter--;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            
            eRetVal = Fls_Qspi_CheckExtMemIsIdle(Fls_u32JobSectorIt);
        }while( FLASH_E_PENDING == eRetVal );  /* FLASH_E_OK(ext. mem. idle), FLASH_E_PENDING(erase in progress) or FLASH_E_FAILED(erase or get status cmd. failed). */       
        
        /* Check if erase was successful. */
        if(FLASH_E_FAILED == eRetVal)
        {
            /* Error, the job failed, either because the loop was exited on the timeout condition or the polling of the status failed. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        
        /* Check error flags from external flash chip */
        if(NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout)
        {
            if( (Std_ReturnType)E_NOT_OK == Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectCh))[Fls_u32JobSectorIt]))
            {
               /* There is error from external flash chip */
               /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
               return FLASH_E_FAILED;
            }
        }
        
    #if( FLS_ERASE_BLANK_CHECK == STD_ON )   
        /* Check if memory locations were successfully erased. */
        if( FLASH_E_OK != Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, u32PhysicalSectorSize) )
        {
            /* Error, the memory locations are not erased or there was an error when attempting to read it. */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
    #endif  
    
        /* Everything OK, sector erase was successful. */
        eRetVal = FLASH_E_OK;
    }
    else /* Asynchronous mode(ASYNC or IRQ mode). */
    {
        #if( FLS_ERASE_BLANK_CHECK == STD_ON )    
        /* Store the total number of bytes to be checked in Blank Check. */
        Fls_u32LLDNumberOfStepBack = u32PhysicalSectorSize;
        #endif
        
        /* Store the pending status before enabling an interrupt. */
        Fls_eLLDJobResult = MEMIF_JOB_PENDING; 
        eRetVal = FLASH_E_PENDING;
        
        if( (boolean)FALSE != (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_SECTOR_ERASE_ASYNCH) )
        { /* ASYNC mode, no IRQ processing. */                
            /* Schedule pending async erase job. */
            Fls_eLLDJob = FLASH_JOB_ERASE;            
        }
        else
        { /* IRQ mode. */
            #if(FLS_USE_INTERRUPTS == STD_ON)
            /* Schedule the pending IRQ erase job. */
            Fls_eLLDIrqJob = FLASH_IRQ_JOB_ERASE;

            /* Enable the Transaction Finished Interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);
            #endif
            /* IRQ mode. */    
        }
    }       

    return eRetVal;
}

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
/** 
* @brief        Prepare and launch the LUT sequence for Hyperflash erase operations.
*
* @details      Load a predefined LUT sequence(the last one, no.15) with the instruction/operand pairs
*               corresponding to a valid Hyperflash erase command and also launch the erase command. 
*
* @param[in]    none 
* @param[out]   none
*
* @pre          Fls_Qspi_u32ExtSectStartAddr global variable is updated and contains the sector start address 
*               offset-ed over the QSPI IP hardware channel offset
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
*
*
* @post         LUT sequence no.15 populated with an erase sequence.
*
*   
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareLaunchErase(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Check and wait for controller to be idle, in case the controller is busy by a previously long AHB triggered read access. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Unlock sequence 1. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xAAU);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Unlock sequence 2. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_2_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0x55U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Erase command sequence 1. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0x80U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Erase command sequence 2. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xAAU);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Erase command sequence 3. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_2_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0x55U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    /* Send the Erase command sequence 4 - sector erase selection. */
    
    /* Set the start address of the IP erase transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
    
    /* Send the Sector Erase command to the memory. */
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,    FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,  
                                                                                FLS_LUT_INSTR_CMD_DDR,     FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_WRITE_MEM_WRAP
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_CMD_DDR,       FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_CADDR_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,        FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_CMD_DDR,    FLS_LUT_PAD_8_PADS, FLS_HYPERF_SECTOR_ERASE_ID_U8
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED); 
    
    return eRetVal;    
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
/** 
* @brief        Qspi Write enable
*
* @details      Schedule or launch the write enable command. 
*
* @param[in]    u32StartAddr    - start address of the transaction, used to select the external chip-select channel. 
* @param[in]    u8ParEn         - parity flag, used if the current sector is a parallel one and the write enable command has to be sent to both memories. 
* @param[out]   none
*
* @pre          Fls_Qspi_u32HwUnitBaseAddr global variable is updated and contains the base address of the QSPI
*               IP unit register map, for which this sector is assigned to.
*
*
* @post         External memory is write enabled(for Sync/Async modes) or the WriteEnable command was sent to the memory(IRQ mode).
*
*   
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_WriteEnable
( 
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr, 
    VAR(uint8, AUTOMATIC) u8ParEn 
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;     
    VAR(uint8, AUTOMATIC) u8LUTWriteEnId;
        
    /* Check if controller is busy(BUSY bit asserted) and wait for transaction to finish in uC, if there is any ongoing AHB buffer prefetch read triggered by a previous verify operation. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write enable operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
                
    /* Set the start address of the IP read transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );
    
    /* Get LUT Write Enable sequence index. */
    u8LUTWriteEnId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTWriteEnSeq;
    
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
    
    Fls_Qspi_LaunchLUTCommand(u8LUTWriteEnId, 0U, u8ParEn);
    
    /* Wait for the write enable command to finish only if this is not an IRQ mode write, 
       because this would mean that the WriteEnable job was called within interrupt context. */
    if( (FLASH_IRQ_JOB_WRITE_EN != Fls_eLLDIrqJob) )
    {
        /* Wait for transaction to finish in uC. */
        while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
        {
            #if (FLS_TIMEOUT_HANDLING == STD_ON)
                if( 0U == Fls_u32LLDTimeout_Counter )
                {
                    /* Error, the write enable operation has timed out. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                Fls_u32LLDTimeout_Counter--;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        }    
        
        /* Check errors from QSPI_FR. */
        if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
        {
            /* Clear the errors (w1c). */
            REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
            
        /* Wait for transaction to finish in external flash memory. Poll the external memory BUSY bit.*/
        do
        {        
            #if (FLS_TIMEOUT_HANDLING == STD_ON)
                if( 0U == Fls_u32LLDTimeout_Counter )
                {
                    /* Error, the write enable operation has timed out. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                Fls_u32LLDTimeout_Counter--;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */

            eRetVal = Fls_Qspi_CheckExtMemIsIdle(Fls_u32JobSectorIt);
        }while( FLASH_E_PENDING == eRetVal );   /* FLASH_E_OK(ext. mem. idle), FLASH_E_PENDING(write in progress) or FLASH_E_FAILED(write or get status cmd. failed). */
        
        if(FLASH_E_OK == eRetVal)
        {
            /* Check errors from QSPI_FR. */
            if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
            {
                /* Clear the errors (w1c). */
                REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
                eRetVal = FLASH_E_FAILED;
            }
        }
        else
        {
             /* Consider the job failed, because the loop was exited on the timeout condition. */
            eRetVal = FLASH_E_FAILED;
        }
    }
    /*else    This WriteEnable job was called from an WriteEnable IRQ job, in interrupt context, so no waiting should be done here.
    {           
        
    }*/    
    
    return eRetVal;
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */

/*
    eRetVal     FLASH_E_OK          Status register read successfully.
                FLASH_E_FAILED      Error, to many expected bytes, error during read transaction.
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_GetMemStatus
(
    P2VAR(uint32, AUTOMATIC, FLS_APPL_DATA) p32DataPtr,
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;       
    VAR(uint8, AUTOMATIC) u8ExtRegWidth;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)         
    VAR(uint8, AUTOMATIC) u8LUTGetStatusId;  
#else
    VAR(uint8, AUTOMATIC) u8LatCycls;                   
#endif    
    
    /* Clear reception flags, counters, prior to triggering the IP command. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
      
    /* Set the Watermark level. */
    REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, 0U );   /* Expect 1 word(4byte entries) */
      
    /* Get the external memory register width,in bytes no., in order to determine the transfer length. */
    u8ExtRegWidth = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitRegisterWidth;
    /* Check "u8ExtRegWidth" is no bigger than 4 bytes, otherwise data might get corrupted when updating the "u32ExtRegValue". */
    if(4U < u8ExtRegWidth)
    {
        /* Error, the register width is bigger than the variable in which it has to be stored. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }  
    /* Check if controller is busy(BUSY bit asserted). */
    if( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )
    {
        /* Error, controller is not idle. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
        
    /* Use the Normal or Hyperflash LUT sequence. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
        /* Get LUT Get Status sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
        u8LUTGetStatusId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTGetStatusSeq;
                    
        /* Set the start address of the IP read status transaction. */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );    
           
        Fls_Qspi_LaunchLUTCommand(u8LUTGetStatusId, u8ExtRegWidth, QSPI_PARALLEL_MODE_DISABLED);                                        
    #else
        /* Hyperflash mode. */
         
        (void)u32StartAddr; /* The Hyperflash Get status command uses the external start sector address and a predefined value. */ 
        u8LatCycls = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiHyperflashLatCycls;
        
        /* Prepare the LUT with the Hyperflash get status sequence and launch the read status register command. */
        eRetVal = Fls_Qspi_HyperPrepareLaunchGetStatus(u8LatCycls, u8ExtRegWidth);
        if(FLASH_E_OK != eRetVal)
        {
            /* Error, the Get status command sequence failed. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }      
        
        /* The Get status read command is launched above. */
    #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
    
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write enable operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }   
    
    /* Read received data from RX Buffer. Read "u8ExtRegWidth" bytes into the variable pointed to by "p32DataPtr". */
    /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
    eRetVal = Fls_Qspi_ReadRXBuffer(u8ExtRegWidth, (uint8 *)p32DataPtr, NULL_PTR);        
    
    return eRetVal;
}

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareLaunchGetStatus(VAR(uint8, AUTOMATIC) u8LatCycls, VAR(uint8, AUTOMATIC) u8ExtRegWidth)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Send the Read Status Register Hyperflash command to memory. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, FLS_HYPERF_STATUS_REG_READ_ID_U8);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write enable operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Setup the LUT for the read of the status register. */
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,    FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,  
                                                                                FLS_LUT_INSTR_CMD_DDR,     FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_READ_MEM_LINEAR
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_DUMMY,       FLS_LUT_PAD_8_PADS, u8LatCycls,  
                                                                                FLS_LUT_INSTR_CADDR_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,        FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_READ_DDR,    FLS_LUT_PAD_8_PADS, u8ExtRegWidth
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, u8ExtRegWidth, QSPI_PARALLEL_MODE_DISABLED);
    
    return eRetVal;
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */

FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_GetExtSectStartAddr( VAR(Fls_QspiSectorChType, AUTOMATIC) eHwCh )
{   
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;  
    VAR(uint32, AUTOMATIC) u32MemVal = 0UL;  
    
    /* "Fls_Qspi_u32ExtSectStartAddr" is the address used in the QSPI commands. From this value, the HW IP internally subtracts the SF{A/B}{1/2}AD value
       (which is the base address upon which the IP determines the HW channel used, the ChipSelect), the remainder being used inside the 
       serial command sent to memory. The obtained address is used in SFAR register(for IP operations) or it is directly read(for AHB operations). 
       "Fls_Qspi_u32StartAddrIndividual_A/B" the address for check each sectors in parallel mode with corresponding individual start address */    
    switch(eHwCh)
    {
        case FLS_CH_EXTERN_QSPI_0_A1:
            Fls_Qspi_u32ExtSectStartAddr = QSPI_QSPI_0_AMBA_BASE_U32 + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt] ;
            break;
    #ifdef QSPI_1_BASEADDR        
        case FLS_CH_EXTERN_QSPI_1_A1:
            Fls_Qspi_u32ExtSectStartAddr = QSPI_QSPI_1_AMBA_BASE_U32 + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt] ;
            break;
    #endif        
        case FLS_CH_EXTERN_QSPI_0_A2:
        case FLS_CH_EXTERN_QSPI_1_A2:
            /* Compute the address used in the transaction: Internal ch. offset(from SFA2AD register) + sector HW address(memory offset). */
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA1AD_OFFSET_U32);
            Fls_Qspi_u32ExtSectStartAddr = u32MemVal + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            break;
        case FLS_CH_EXTERN_QSPI_0_B1:
        case FLS_CH_EXTERN_QSPI_1_B1:
            /* Compute the address used in the transaction: Internal ch. offset(from SFB1AD register) + sector HW address(memory offset). */
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA2AD_OFFSET_U32);
            Fls_Qspi_u32ExtSectStartAddr = u32MemVal + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            break;
        case FLS_CH_EXTERN_QSPI_0_B2:
        case FLS_CH_EXTERN_QSPI_1_B2:
            /* Compute the address used in the transaction: Internal ch. offset(from SFB2AD register) + sector HW address(memory offset). */
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFB1AD_OFFSET_U32);
            Fls_Qspi_u32ExtSectStartAddr = u32MemVal + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            break;
        case FLS_CH_EXTERN_QSPI_0_PARALLEL_A1B1:
            /* Compute the address used in the transaction, AMBA base start address + sector offset. */
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA2AD_OFFSET_U32);
            Fls_Qspi_u32ExtSectStartAddr      = QSPI_QSPI_0_AMBA_BASE_U32 + (2U*(*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt]) ;
            Fls_Qspi_u32StartAddrIndividual_A = QSPI_QSPI_0_AMBA_BASE_U32 + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt] ;
            Fls_Qspi_u32StartAddrIndividual_B = u32MemVal + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            break;
        case FLS_CH_EXTERN_QSPI_0_PARALLEL_A2B2:
            /* Compute the address used in the transaction: Internal ch. offset(from SFA2AD register) + sector HW address(memory offset). */
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA2AD_OFFSET_U32);
            Fls_Qspi_u32ExtSectStartAddr      = u32MemVal + (2U*(*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt]);
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA1AD_OFFSET_U32);
            Fls_Qspi_u32StartAddrIndividual_A = u32MemVal + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            u32MemVal = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFB1AD_OFFSET_U32);
            Fls_Qspi_u32StartAddrIndividual_B = u32MemVal + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            break;
    #ifdef QSPI_1_BASEADDR
        case FLS_CH_EXTERN_QSPI_1_PARALLEL_A1B1:
            /* Compute the address used in the transaction, AMBA base start address + sector offset. */
            Fls_Qspi_u32ExtSectStartAddr      = QSPI_QSPI_1_AMBA_BASE_U32 + (2U*(*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt]) ;
            Fls_Qspi_u32StartAddrIndividual_A = QSPI_QSPI_1_AMBA_BASE_U32 + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            Fls_Qspi_u32StartAddrIndividual_B = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA2AD_OFFSET_U32) + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            break;
        case FLS_CH_EXTERN_QSPI_1_PARALLEL_A2B2:
            /* Compute the address used in the transaction, AMBA base start address + sector offset. */
            Fls_Qspi_u32ExtSectStartAddr      = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA2AD_OFFSET_U32) + (2U*(*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt]);
            Fls_Qspi_u32StartAddrIndividual_A = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFA1AD_OFFSET_U32) + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];
            Fls_Qspi_u32StartAddrIndividual_B = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFB1AD_OFFSET_U32) + (*(Fls_pConfigPtr->paSectorHwAddress))[Fls_u32JobSectorIt];            
            break;
    #endif 
        default:
            /* Error case, NOT_QSPI_CHANNEL value or unrecognized channel.*/
            Fls_Qspi_u32ExtSectStartAddr    = 0UL;
            Fls_Qspi_u32StartAddrIndividual_A = 0UL;
            Fls_Qspi_u32StartAddrIndividual_B = 0UL;
            eRetVal = FLASH_E_FAILED;
            break;
    }
    
    return eRetVal;
}

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_CheckControllerIsIdle(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK; 
    
    /* Check if controller is busy(BUSY bit asserted). */
    if( 0U != (QSPI_SR_BUSY_U32 & REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_SR_OFFSET_U32)) )
    {
        /* Error, controller is busy handling another transaction. */
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}

/*
    eRetVal     FLASH_E_OK          External memory is idle.
                FLASH_E_FAILED      Error during read of status register.
                FLASH_E_PENDING     Read of status register successful but external memory is busy.
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_CheckExtMemIsIdle
(
    VAR(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_FAILED;
    VAR(uint32, AUTOMATIC) u32StatusStartAddr = 0x00UL;
    VAR(boolean, AUTOMATIC) bMemoryIsBusy = (boolean)TRUE;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitVal = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitPosOff = 0U;
    
    /* Set Start Address for check status from external flash chip */
    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[u32SectorIndex] )
    {
        /* Current sector is in Parallel mode then using individual address to get status of sector in the channel A */
        u32StatusStartAddr = Fls_Qspi_u32StartAddrIndividual_A;
    }
    else 
    {
        /* Current sector is in Individual mode then using Address for IP command */
        u32StatusStartAddr = Fls_Qspi_u32ExtSectStartAddr;
    }    
    /* Get the external memory status register. */
    Fls_Qspi_u32StatusRegVal = 0UL;
    if(FLASH_E_OK != Fls_Qspi_GetMemStatus(&Fls_Qspi_u32StatusRegVal, u32StatusStartAddr) )
    {
        /* Error during read of status register.*/
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Clean all the bits from the read value of the status register, except the status bit. */
    Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset));
    /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. 
       bMemoryIsBusy = (boolean)( Fls_Qspi_u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
    u8QspiUnitBusyBitVal = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue);
    u8QspiUnitBusyBitPosOff = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset);
    /*  @violates @ref fls_qspi_c_REF_7 Cast of complex expression changes signedness. */
    bMemoryIsBusy = (boolean)( Fls_Qspi_u32StatusRegVal == (uint32)((uint32)u8QspiUnitBusyBitVal << (uint32)u8QspiUnitBusyBitPosOff) ); 
    
    if( (boolean)TRUE == bMemoryIsBusy )
    {
        eRetVal = FLASH_E_PENDING;
    }
    else
    {
        /* The above memory is idle. 
           (If this is an INDIVIDUAL sector, then only one external memory has to be interrogated
           and the entire status is considered OK, idle. If this is a PARALLEL sectors, then below we have to interrogate 
           the second memory also.) */
        eRetVal = FLASH_E_OK;
    }
    
    /* If current sector is a parallel one, then request the status for the second device in the Flash B channel also. 
    (Above it was requested for the first device only), */
    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[u32SectorIndex] )
    {        
        VAR(boolean, AUTOMATIC) bMemoryIsBusyPar = (boolean)TRUE;   /* Busy status of the second memory from the parallel pair. */
        
        /* Get the external memory status register. */
        Fls_Qspi_u32StatusRegVal = 0UL;
        if(FLASH_E_OK != Fls_Qspi_GetMemStatus(&Fls_Qspi_u32StatusRegVal, Fls_Qspi_u32StartAddrIndividual_B) )
        {
            /* Error during read of status register.*/
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }    
        /* Clean all the bits from the read value of the status register, except the status bit. */
        Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset));
        /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. 
           bMemoryIsBusyPar = (boolean)( Fls_Qspi_u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
        u8QspiUnitBusyBitVal = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue);
        u8QspiUnitBusyBitPosOff = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset);
        /*  @violates @ref fls_qspi_c_REF_7 Cast of complex expression changes signedness. */
        bMemoryIsBusyPar = (boolean)( Fls_Qspi_u32StatusRegVal == (uint32)((uint32)u8QspiUnitBusyBitVal << (uint32)u8QspiUnitBusyBitPosOff) ); 
        
        /* Check if the second memory is idle, and if not, overwrite the return value to indicate that overall the memory is still busy. */
        if( ((boolean)TRUE == bMemoryIsBusy) || ((boolean)TRUE == bMemoryIsBusyPar) )
        {   
            /* Overwrite the final status. */
            eRetVal = FLASH_E_PENDING;
        }
        else
        {
            /* Both memories are idle */
            eRetVal = FLASH_E_OK;
        }
    }
    /*else if FLS_QSPI_CH_INDIVIDUAL 
    {    
        Only one memory needs to be interrogated, no need to interrogate the second memory status also. 
    }*/
    
    return eRetVal;
}

/**
* @brief          Write one or more flash pages into given flash sector.
*
* @param[in]      u32StartAddr      Memory mapped(offset-ed) QSPI address
* @param[in]      u32DataLength     Data length in bytes
* @param[in]      pDataPtr          Data to be written
* @param[in]      bAsynch           Set to TRUE for asynchronous operations(ASYNC and IRQ modes) and FALSE for synchronous function operation.
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            Fls_Qspi_u8HwUnitCfgIndex       HW IP configuration index inside the configuration structure
* @pre            Fls_Qspi_u32HwUnitBaseAddr      HW IP base address used as base offset for all register operations
* @pre            The module must be initialized
*
*/
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SectorWrite
(
    CONST(Fls_AddressType, AUTOMATIC) u32StartAddr,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
    VAR(uint8, AUTOMATIC) u8LUTWriteId;
    VAR(uint8, AUTOMATIC) u8ParEn;  
    VAR(uint32, AUTOMATIC) u32SectProgSize = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];   /* Sector Programming size configuration parameter. */
 
    
    /* Get LUT Write sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
    u8LUTWriteId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTWriteSeq;        
                
    /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
    {
        u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
    }
    else /* FLS_QSPI_CH_INDIVIDUAL */
    {
        u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
    } 
#endif
    
    /* Store the number of bytes to be written. If SYNC mode, all u32DataLength are written in this function iteration. 
       If ASYNC mode, a maximum of TXBuffer size are started to be written in this function, the rest, up to u32DataLength
       are written in Fls_LLDMainFunction cyclic calls. */
    Fls_u32LLDRemainingDataToWrite = u32DataLength;    
    /* Store the address of the first written location. */
    Fls_Qspi_u32MemoryAddress = u32StartAddr;
    /* Store the address of the source buffer. */
    /* Compiler_Warning: see fls_c_REF_CW_02 */
    Fls_Qspi_u32BufferAddress = (uint32)p8DataPtr;
        
#if(FLS_TIMEOUT_HANDLING == STD_ON)    
    /* Initialize timeout counters */
    if( (boolean)FALSE == bAsynch ) /* SYNC mode. */
    {
        Fls_u32LLDTimeout_Counter = FLS_QSPI_SYNC_WRITE_TIMEOUT_VALUE;
    }
    else /* ASYNC mode. */
    {
        if( (boolean)FALSE != (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_PAGE_WRITE_ASYNCH) )
        { /* ASYNC mode, no IRQ processing. */
            Fls_u32LLDTimeout_Counter = FLS_QSPI_ASYNC_WRITE_TIMEOUT_VALUE;
        }
        else
        { 
            #if(FLS_USE_INTERRUPTS == STD_ON)
            Fls_u32LLDTimeout_Counter = FLS_QSPI_IRQ_WRITE_TIMEOUT_VALUE;
            #endif
            /* IRQ mode. */
        }
    }        
#endif 
    
    /* Check if controller is busy(BUSY bit asserted) and wait for transaction to finish in uC, if there is any ongoing AHB buffer prefetch read triggered by a previous verify operation. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write enable operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }   
        
    if( (boolean)FALSE == bAsynch ) /* SYNC mode. */
    {        
        do  /* Each loop transfers a maximum of QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 bytes, until all bytes are transfered. */
        {
            VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
            VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;
            VAR(uint8, AUTOMATIC) u8BytesToWrite = 0U;  /* No. of bytes to be written in one external serial write transaction. */        
                
            /* Check if the total number of bytes to be written exceeds the TXBuffer size. */
            if( Fls_u32LLDRemainingDataToWrite > QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
            {
                /* More than the maximum size of TX Buffer has to sent, use only 128bytes. */
                u8BytesToWrite = QSPI_TXBUFFER_MAX_SIZE_BYTES_U32; 
            }
            else
            {
                u8BytesToWrite = (uint8)Fls_u32LLDRemainingDataToWrite;
            }  

        /* Use the Normal or Hyperflash LUT sequence. */
        #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
            /* Check if the total no. of bytes to be written will exceed the external memory internal buffer.
               If the internal buffer boundary is exceeded, the actual memory writes could wrap-around in the memory. */
            u32MemAddr1 = Fls_Qspi_u32MemoryAddress/u32SectProgSize;
            u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress+u8BytesToWrite)-1U)/u32SectProgSize;
            if( u32MemAddr1 != u32MemAddr2 )
            {    
                VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                    
                /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                /* u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % u32SectProgSize) + (u32SectProgSize - 1U); Split into multiple statements in order to avoid MISRA error. */
                u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % u32SectProgSize;
                u32LineEndAddr += u32SectProgSize - 1U;
                u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);   
            }   
        #else
            /* Hyperflash mode.*/
    
            /* Check that the last address to be programmed is in the same flash line. Any hyperflash write operation must not exceed the boundary of the current flash line(512bytes). */
            u32MemAddr1 = Fls_Qspi_u32MemoryAddress/FLS_HYPERF_LINE_SIZE_U32;
            u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/FLS_HYPERF_LINE_SIZE_U32;
            if( u32MemAddr1 != u32MemAddr2 )
            {
                VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                
                /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                /* u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32) + (FLS_HYPERF_LINE_SIZE_U32 - 1U); Split into multiple statements in order to avoid MISRA error. */
                u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32;
                u32LineEndAddr += FLS_HYPERF_LINE_SIZE_U32 - 1U;
                u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);
            } 
            /* else 
                All the bytes fit inside the same flash line. */    
        #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
            
        #if( FLS_WRITE_BLANK_CHECK == STD_ON )    
            /* Check if memory locations are erased prior to attempted write. */
            if( FLASH_E_OK != Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, (uint32)u8BytesToWrite) )
            {
                /* Error, the memory locations are not erased or there was an error when attempting to read it. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }  
        #endif
            
            /* Use the Normal or Hyperflash LUT sequence. */
            #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
    
                /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                /* Update the source address pointer with the amount loaded above into TX Buffer*/
                Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                
                /* Enable the Write/Erase operation on the external memory. */   
                if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
                {
                    /* Error, WriteEnable command has failed. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                
                /* Set the start address of the IP write transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
            
                /* Launch WRITE command. */
                Fls_Qspi_LaunchLUTCommand(u8LUTWriteId, u8BytesToWrite, u8ParEn);
            #else
                /* Hyperflash mode.*/
                
                /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                /* Update the source address pointer with the amount loaded above into TX Buffer*/
                Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                    
                /* Prepare and launch the LUT sequences required for a Hyperflash write transaction. */    
                eRetVal = Fls_Qspi_HyperPrepareLaunchWrite(u8BytesToWrite);
                if(FLASH_E_OK != eRetVal)
                {
                    /* Error, the Write command sequence failed. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }

                /* The Write command was launched above. */
                
            #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
        
            /* Wait for transaction to finish in uC. */
            while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
            {
                #if (FLS_TIMEOUT_HANDLING == STD_ON)
                    if( 0U == Fls_u32LLDTimeout_Counter )
                    {
                        /* Error, the write operation has timed out. */
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_FAILED;
                    }
                    Fls_u32LLDTimeout_Counter--;
                #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            } 
            
            /* Check the error flags. */
            if(0U !=  REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TBUF_U32 | QSPI_FR_ILLINE_U32 | QSPI_FR_IUEF_U32  | QSPI_FR_IPAEF_U32  | QSPI_FR_IPIEF_U32  | QSPI_FR_IPGEF_U32 ) ) 
            {
                /* Error, error flags were set during programming. */
                /* Clear the error flags (w1c). */
                REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TBUF_U32 | QSPI_FR_ILLINE_U32 | QSPI_FR_IUEF_U32  | QSPI_FR_IPAEF_U32  | QSPI_FR_IPIEF_U32  | QSPI_FR_IPGEF_U32 );
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */               
                return FLASH_E_FAILED;
            }            
            
            /* Wait for transaction to finish in external flash memory. Poll the external memory BUSY bit.*/
            do
            {        
                #if (FLS_TIMEOUT_HANDLING == STD_ON)
                    if( 0U == Fls_u32LLDTimeout_Counter )
                    {
                        /* Error, the write operation has timed out. */
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_FAILED;
                    }
                    Fls_u32LLDTimeout_Counter--;
                #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
                
                eRetVal = Fls_Qspi_CheckExtMemIsIdle(Fls_u32JobSectorIt);
            }while( FLASH_E_PENDING == eRetVal );  /* FLASH_E_OK(ext. mem. idle), FLASH_E_PENDING(write in progress) or FLASH_E_FAILED(write or get status cmd. failed). */
            
            /* Check if programming was successful. */
            if(FLASH_E_FAILED == eRetVal)
            {
                /* Error, the job failed, either because the loop was exited on the timeout condition or the polling of the status failed. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }

            /* Check error flags from the external flash chip */
            if( NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout )
            {
                /* Call configured callout functions */
                if((Std_ReturnType)E_NOT_OK == Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectCh))[Fls_u32JobSectorIt] ))
                {
                    /* Got errors from external Flash */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
            }
            
            #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* Verify the memory was correctly programmed. */            
            u32MemAddr1 = Fls_Qspi_u32MemoryAddress;
            u32MemAddr2 = (uint32)(Fls_Qspi_u32BufferAddress - (uint32)u8BytesToWrite);
            if( FLASH_E_OK != Fls_Qspi_VerifyWrite(u32MemAddr1, u32MemAddr2, (uint32)u8BytesToWrite) )
            {
                /* Error, the memory locations were not correctly programmed or there was an error when attempting to read it. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            #endif
            
            /* Programming was successful. */
                        
            /* Update external write address. */
            Fls_Qspi_u32MemoryAddress += u8BytesToWrite;
            /* "Fls_Qspi_u32BufferAddress" is updated above. */
            /* Update the remaining number of bytes to be written. */
            Fls_u32LLDRemainingDataToWrite -= u8BytesToWrite;              
            
        }while(Fls_u32LLDRemainingDataToWrite > 0U);  /* Loop until all bytes are programmed. */  
    }
    else /* Asynchronous mode(ASYNC or IRQ mode). */
    {        
        if( (boolean)FALSE != (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_PAGE_WRITE_ASYNCH) )
        { /* ASYNC mode, no IRQ processing. */  
            VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
            VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;
                                        
            VAR(uint8, AUTOMATIC) u8BytesToWrite = 0U;  /* Number of bytes to be written in this function iteration, up to a max of TXBuffer size. */
            
            /* Check if the total number of bytes to be written exceeds the TXBuffer size. */
            if( Fls_u32LLDRemainingDataToWrite > QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
            {
                /* More than the maximum size of TX Buffer has to sent, use only 128bytes. */
                u8BytesToWrite = QSPI_TXBUFFER_MAX_SIZE_BYTES_U32; 
            }
            else
            {
                u8BytesToWrite = (uint8)Fls_u32LLDRemainingDataToWrite;
            } 

        /* Use the Normal or Hyperflash LUT sequence. */
        #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
            /* Check if the total no. of bytes to be written will exceed the external memory internal buffer.
               If the internal buffer boundary is exceeded, the actual memory writes could wrap-around in the memory. */
            u32MemAddr1 = Fls_Qspi_u32MemoryAddress/u32SectProgSize;
            u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/u32SectProgSize;            
            if( u32MemAddr1 != u32MemAddr2 )
            {    
                VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                    
                /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                /*u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % u32SectProgSize) + (u32SectProgSize - 1U);Split into multiple statements in order to avoid MISRA error. */
                u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % u32SectProgSize;
                u32LineEndAddr += u32SectProgSize - 1U;
                u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);   
            }   
        #else
            /* Hyperflash mode.*/
    
            /* Check that the last address to be programmed is in the same flash line. Any hyperflash write operation must not exceed the boundary of the current flash line(512bytes). */
            u32MemAddr1 = Fls_Qspi_u32MemoryAddress/FLS_HYPERF_LINE_SIZE_U32;
            u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/FLS_HYPERF_LINE_SIZE_U32;
            if( u32MemAddr1 != u32MemAddr2 )
            {
                VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                
                /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                /*u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32) + (FLS_HYPERF_LINE_SIZE_U32 - 1U);Split into multiple statements in order to avoid MISRA error. */
                u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32;
                u32LineEndAddr += FLS_HYPERF_LINE_SIZE_U32 - 1U;
                u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);
            } 
            /* else 
                All the bytes fit inside the same flash line. */    
        #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */ 
            
            #if( FLS_WRITE_BLANK_CHECK == STD_ON )        
                /* Check if memory locations are erased prior to attempted write. */
                /* For ASYNC mode, the verify erase is made here and the result is returned, 
                   for IRQ mode, the verify erase is only started and the result is processed in the interrupt routine. */
                if( FLASH_E_OK != Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, (uint32)u8BytesToWrite) )
                {
                    /* Error, the memory locations are not erased or there was an error when attempting to read it. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
            #endif        

            /* Use the Normal or Hyperflash LUT sequence. */
            #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)     
                /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                /* Update the source address pointer with the amount loaded above into TX Buffer*/
                Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                
                /* Enable the Write/Erase operation on the external memory. */   
                if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
                {
                    /* Error, WriteEnable command has failed. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
            
                /* Set the start address of the IP write transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
        
                /* Launch WRITE command. */
                Fls_Qspi_LaunchLUTCommand(u8LUTWriteId, u8BytesToWrite, u8ParEn); 
            #else
                /* Hyperflash mode.*/
                                
                /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                /* Update the source address pointer with the amount loaded above into TX Buffer*/
                Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                    
                /* Prepare and launch the LUT sequences required for a Hyperflash write transaction. */    
                eRetVal = Fls_Qspi_HyperPrepareLaunchWrite(u8BytesToWrite);
                if(FLASH_E_OK != eRetVal)
                {
                    /* Error, the Write command sequence failed. */
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }

                /* The Write command was launched above. */
                
            #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
            
            /* Update external write address. */
            Fls_Qspi_u32MemoryAddress += u8BytesToWrite;
            /* "Fls_Qspi_u32BufferAddress" is updated above, right after loading it into the TX Buffer. */
            /* Update the remaining number of bytes to be written. */
            Fls_u32LLDRemainingDataToWrite -= u8BytesToWrite;
            #if( FLS_WRITE_VERIFY_CHECK == STD_ON )    
            /* Store the number of bytes written, to be used for the VerifyWrite function inside async call of MainFunction. */
            Fls_u32LLDNumberOfStepBack = u8BytesToWrite;
            #endif    
            /* Schedule pending async write job. */
            Fls_eLLDJob = FLASH_JOB_WRITE;
            Fls_eLLDJobResult = MEMIF_JOB_PENDING;
            
            eRetVal = FLASH_E_PENDING;          
        }
        else /*if( (boolean)FALSE != (boolean)((*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & FLS_PAGE_WRITE_ASYNCH) )*/
        { /* IRQ mode. */
        #if(FLS_USE_INTERRUPTS == STD_ON)
            #if( FLS_WRITE_BLANK_CHECK == STD_ON )
                VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
                VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;
            #endif
            
            #if( FLS_WRITE_VERIFY_CHECK == STD_ON )    
                /* Store the number of bytes written, to be used for the VerifyWrite function inside async call of MainFunction. */
                Fls_u32LLDNumberOfStepBack = Fls_u32LLDRemainingDataToWrite;
            #endif   
            
            eRetVal = FLASH_E_PENDING;  
              
            #if( FLS_WRITE_BLANK_CHECK == STD_ON )        
                /* Check if memory locations are erased prior to attempted write. */
            
                /* Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK; is set in the VerifyErase function. */
                /* Fls_eLLDJobResult = MEMIF_JOB_PENDING;     is set in the VerifyErase function. */
                /* The RBDF interrupt is enabled in the VerifyErase function. */
                
                /* For IRQ mode, the verify erase is only started and the result is processed in the interrupt routine
                   (also clears the flag, enables the RBDF interrupt and sets the IRQ job to Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK). 
                   The difference from the Async mode is that the entire area which is supposed to be written is checked.*/
                u32MemAddr1 = Fls_Qspi_u32MemoryAddress;
                u32MemAddr2 = Fls_u32LLDRemainingDataToWrite;
                if( FLASH_E_FAILED == Fls_Qspi_VerifyErase(u32MemAddr1, u32MemAddr2) )
                {
                    /* Error, there was an error when attempting to schedule the memory read. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }    
            #else
                /* Launch the IRQ Write operation directly.*/
                
                Fls_eLLDJobResult = MEMIF_JOB_PENDING;
                
                /* Prepare and enable the TFF interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
            
                #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
                
                    /* Schedule the write enable IRQ job. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_WRITE_EN;               
                
                    /* Enable the Write/Erase operation on the external memory(will launch the write enable command). */   
                    if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
                    {
                        /* Error, WriteEnable command has failed. */
                        
                        /* Clear the interrupt flag and disable the TFF interrupt source. */
                        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
                        
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_FAILED;
                    }  
                    
                #else
                    
                    /* Schedule the write unlock sequence 1 IRQ job. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1;
                    
                    /* Schedule and launch the first write unlock 1 sequence. */   
                    if( FLASH_E_OK != Fls_Qspi_HyperSendUnlock1Irq(Fls_Qspi_u32ExtSectStartAddr) )
                    {
                        /* Error, Write unlock sequence 1 command has failed when attempting to schedule it. */            
                        
                        /* Clear the interrupt flag and disable the TFF interrupt source. */
                        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return FLASH_E_FAILED;
                    }
                    
                #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
                                
            #endif /* #if( FLS_WRITE_BLANK_CHECK == STD_ON ) */ 
        #endif /* #if(FLS_USE_INTERRUPTS == STD_ON) */
        /* IRQ mode. */
        }       
    }   
    
    return eRetVal;
}

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
    
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperPrepareLaunchWrite(VAR(uint8, AUTOMATIC) u8BytesToWrite)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Check and wait for controller to be idle, in case the controller is busy by a previously long AHB triggered read access. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
            Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Unlock sequence 1. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xAAU);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Error, the write operation has timed out. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
    
    /* Send the Unlock sequence 2. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_2_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0x55U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Error, the write operation has timed out. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }                
    
    /* Send the Write Program command. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xA0U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    /* Wait for transaction to finish. */
    while( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )  /* Poll BUSY bit. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* Error, the write operation has timed out. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return FLASH_E_FAILED;
        }
        Fls_u32LLDTimeout_Counter--;
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
                   
    /* Set the start address of the IP write transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );

    /* Send the DATAx words. */
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,    FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,  
                                                                                FLS_LUT_INSTR_CMD_DDR,     FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_WRITE_MEM_WRAP
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_WRITE_DDR,       FLS_LUT_PAD_8_PADS, u8BytesToWrite,  
                                                                                FLS_LUT_INSTR_CADDR_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,        FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_STOP,    FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    
    return eRetVal;
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */

/**
* @brief          Check the asynchronous status of a pending erase job.
*                 If job finished successfully, mark the internal low level job as done.
*                 If job failed, mark the internal low level job as failed and store the error code for later DEM error reporting.
*                 If job still pending and no timeout occurred, wait and attempt to check it on the next Fls_MainFunction iteration.
*
* @param[in]      none
* @param[out]     none
*
* @return         none
*
* @pre            Erase job was scheduled and is pending.
*
*/
FUNC( void, FLS_CODE ) Fls_Qspi_MainFunctionErase( void )
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eCtrlIdle = FLASH_E_FAILED;
    VAR(Fls_LLDReturnType, AUTOMATIC) eExtMemIdle = FLASH_E_FAILED;
        
    eCtrlIdle   = Fls_Qspi_CheckControllerIsIdle();
    
    /* Verify any possible errors which could have occurred in the QSPI IP, during the internal transaction. */    
    if(FLASH_E_OK == eCtrlIdle)   
    {        
        /* Check the error flags. */
        if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
        {
            /* Error, error flags were set during programming. */
            /* Clear the errors (w1c). */
            REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
            
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
                
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        
        /* Get external memory status, only when the controller is idle. */
        eExtMemIdle = Fls_Qspi_CheckExtMemIsIdle(Fls_u32JobSectorIt);

    }
    
    
    /* Check if the transaction is still pending in the uC and external memory. */
    if( (FLASH_E_OK == eCtrlIdle) &&     /* Poll internal BUSY bit. */
        (FLASH_E_OK == eExtMemIdle) )          /* Poll the external memory BUSY bit. */
    {
        /* Check if error occurred. */
        if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
        {
            /* Erase operation failed. */
            
            /* Clear the errors (w1c). */
            REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
            
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
                    
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        /* Check error from external flash chip status */        
        else if (NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout )
        {
            if((Std_ReturnType)E_NOT_OK == Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectCh))[Fls_u32JobSectorIt]))
            {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                #endif
                        
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return;
            }
        }
        else /* Erase operation was successful */        
        {
        #if( FLS_ERASE_BLANK_CHECK == STD_ON )
            /* Schedule erase blank check of flash sector. */
            Fls_eLLDJob = FLASH_JOB_ERASE_BLANK_CHECK;
        #else
            /* Erase operation succeed. */
            Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
            
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_OK;
        #endif
        }
    }
    else /* Erase transaction is still in progress. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)    
            /* Handle possible timeout. */
            Fls_u32LLDTimeout_Counter--;
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                #endif
                        
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return;
            }
            /* else
                    Erase operation still in progress, wait for another call of Fls_LLDMainFunction, do nothing. 
            */
        #else
            /* Erase operation still in progress, wait for another call of Fls_LLDMainFunction, do nothing. */
        #endif
    }
}

/**
* @brief          Check the asynchronous status of a pending write job.
*                 If job finished successfully, mark the internal low level job as done or schedule the next chun.
*                 If job failed, mark the internal low level job as failed and store the error code for later DEM error reporting.
*                 If job still pending and no timeout occurred, wait and attempt to check it on the next Fls_MainFunction iteration.
*
* @param[in]      none
* @param[out]     none
*
* @return         none
*
* @pre            Write job was scheduled and is pending.
* @pre            Fls_Qspi_u32BufferAddress has to point to the application source buffer, to the first address not yet read.
* @pre            Fls_Qspi_u32MemoryAddress has to point to the memory location to be written, to the first address not yet written.
* @pre            Fls_u32LLDNumberOfStepBack has to hold the previously scheduled data length.
*
*/
FUNC( void, FLS_CODE ) Fls_Qspi_MainFunctionWrite( void )
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eCtrlIdle = FLASH_E_FAILED;
    VAR(Fls_LLDReturnType, AUTOMATIC) eExtMemIdle = FLASH_E_FAILED;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
    VAR(uint8, AUTOMATIC) u8ParEn;
#endif
    
    eCtrlIdle   = Fls_Qspi_CheckControllerIsIdle();
    
    /* Verify any possible errors which could have occurred in the QSPI IP, during the internal transaction. */    
    if(FLASH_E_OK == eCtrlIdle)   
    {        
        /* Check the error flags. */
        if(0U !=  REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TBUF_U32 | QSPI_FR_ILLINE_U32 | QSPI_FR_IUEF_U32  | QSPI_FR_IPAEF_U32  | QSPI_FR_IPIEF_U32  | QSPI_FR_IPGEF_U32 ) ) 
        {
            /* Error, error flags were set during programming. */
            /* Clear the errors (w1c). */
            REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TBUF_U32 | QSPI_FR_ILLINE_U32 | QSPI_FR_IUEF_U32  | QSPI_FR_IPAEF_U32  | QSPI_FR_IPIEF_U32  | QSPI_FR_IPGEF_U32 );

                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
                    
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
    
        /* Get external memory status, only when the controller is idle. */
        eExtMemIdle = Fls_Qspi_CheckExtMemIsIdle(Fls_u32JobSectorIt);
        
    }
        
    /* Check if the transaction is still pending in the uC and external memory. */
    if( (FLASH_E_OK == eCtrlIdle) &&     /* Poll internal BUSY bit. */
        (FLASH_E_OK == eExtMemIdle) )          /* Poll the external memory BUSY bit. */
    {
        /* Check if error occurred. */
        if( 0U != REG_BIT_GET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
        {
            /* Error, Write operation failed. */            
            /* Clear the errors (w1c). */
            REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
            
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
                    
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;            
        }
        /* Check if there is any error from external flash chip */
        else if (NULL_PTR != Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout)
        {
            if((Std_ReturnType)E_NOT_OK == Fls_pConfigPtr->pFlsQspiCfgConfig->pfErrorCheckCallout((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectCh))[Fls_u32JobSectorIt]))
            {                
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                #endif
                            
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return;  
            }
        }
        else /* Pending write operation was successful. */
        {
        #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
            VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;    
            
            /* Verify the memory was correctly programmed. "Fls_Qspi_u32MemoryAddress" and "Fls_Qspi_u32BufferAddress" were updated at the end of SectorWrite() function. */
            u32MemAddr1 = Fls_Qspi_u32MemoryAddress - Fls_u32LLDNumberOfStepBack;
            u32MemAddr2 = Fls_Qspi_u32BufferAddress - Fls_u32LLDNumberOfStepBack;
            if( FLASH_E_OK != Fls_Qspi_VerifyWrite( u32MemAddr1, u32MemAddr2, Fls_u32LLDNumberOfStepBack ) )
            {
                /* Error, the memory locations were not correctly programmed or there was an error when attempting to read it. */
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                #endif
                        
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return;
            }
        #endif
            
            /* If more bytes have to be written in this async transaction. */
            if(0UL < Fls_u32LLDRemainingDataToWrite)
            {
            #if( FLS_WRITE_VERIFY_CHECK == STD_OFF )
                VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
                VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;
            #endif
                VAR(uint8, AUTOMATIC) u8BytesToWrite = 0U;  /* Number of bytes to be written in this function iteration, up to a max of TXBuffer size. */
            #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
                VAR(uint8, AUTOMATIC) u8LUTWriteId;    
                VAR(uint32, AUTOMATIC) u32SectProgSize = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];   /* Sector Programming size configuration parameter. */
            #endif
                
                /* Check if the total number of bytes to be written exceeds the TXBuffer size. */
                if( Fls_u32LLDRemainingDataToWrite > QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* More than the maximum size of TX Buffer has to sent, use only 128bytes. */
                    u8BytesToWrite = QSPI_TXBUFFER_MAX_SIZE_BYTES_U32; 
                }
                else
                {
                    u8BytesToWrite = (uint8)Fls_u32LLDRemainingDataToWrite;
                }
                
                /* Use the Normal or Hyperflash LUT sequence. */
            #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
                /* Check if the total no. of bytes to be written will exceed the external memory internal buffer.
                   If the internal buffer boundary is exceeded, the actual memory writes could wrap-around in the memory. */
                u32MemAddr1 = Fls_Qspi_u32MemoryAddress/u32SectProgSize;
                u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/u32SectProgSize;
                if( u32MemAddr1 != u32MemAddr2 )
                {    
                    VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                        
                    /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                    /*u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % u32SectProgSize) + (u32SectProgSize - 1U);*/
                    u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                    u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % u32SectProgSize;
                    u32LineEndAddr += u32SectProgSize - 1U;
                    u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);   
                }   
            #else
                /* Hyperflash mode.*/
        
                /* Check that the last address to be programmed is in the same flash line. Any hyperflash write operation must not exceed the boundary of the current flash line(512bytes). */
                u32MemAddr1 = Fls_Qspi_u32MemoryAddress/FLS_HYPERF_LINE_SIZE_U32;
                u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/FLS_HYPERF_LINE_SIZE_U32;
                if( u32MemAddr1 != u32MemAddr2 )
                {
                    VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                    
                    /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                    /*u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32) + (FLS_HYPERF_LINE_SIZE_U32 - 1U);*/
                    u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                    u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32;
                    u32LineEndAddr += FLS_HYPERF_LINE_SIZE_U32 - 1U;
                    u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);
                } 
                /* else 
                    All the bytes fit inside the same flash line. */    
            #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */    
                
            #if( FLS_WRITE_BLANK_CHECK == STD_ON )    
                /* Check if memory locations are erased prior to attempted write. */
                if( FLASH_E_OK != Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, (uint32)u8BytesToWrite) )
                {
                    /* Error, the memory locations are not erased or there was an error when attempting to read it. */
                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return;
                }
            #endif
                
                /* Use the Normal or Hyperflash LUT sequence. */
                #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
                    /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
                    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                    {
                        u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
                    }
                    else /* FLS_QSPI_CH_INDIVIDUAL */
                    {
                        u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
                    }
                    
                    /* Enable the Write/Erase operation on the external memory. */   
                    if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
                    {
                        /* Error, WriteEnable command failed. */
                        
                        /* Clear the errors (w1c). */
                        REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
                        
                                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                        #endif
                                            
                        Fls_eLLDJob = FLASH_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return;
                    }
                    
                    /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                    Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                    /* Update the source address pointer with the amount loaded above into TX Buffer*/
                    Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                
                    /* Set the start address of the IP write transaction. */
                    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
            
                    /* Launch WRITE command. */
                    u8LUTWriteId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTWriteSeq;
                    Fls_Qspi_LaunchLUTCommand(u8LUTWriteId, u8BytesToWrite, u8ParEn); 
                #else
                    /* Hyperflash mode.*/
                        
                    /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                    Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                    /* Update the source address pointer with the amount loaded above into TX Buffer*/
                    Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                    
                    /* Prepare and launch the LUT sequences required for a Hyperflash write transaction. */    
                    if(FLASH_E_OK != Fls_Qspi_HyperPrepareLaunchWrite(u8BytesToWrite))
                    {
                        /* Error, the Write command sequence failed. */
                                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                        #endif
                                            
                        Fls_eLLDJob = FLASH_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                        return;
                    }

                    /* The Write command was launched above. */
                    
                #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
                
                /* Update external write address. */
                Fls_Qspi_u32MemoryAddress += u8BytesToWrite;
                /* Update the remaining number of bytes to be written. */
                Fls_u32LLDRemainingDataToWrite -= u8BytesToWrite;                     
            }  
            else /* All bytes were programmed successfully. */
            {
                /* For a Write Job in ASYNC mode check if Fls_u32JobSectorIt should be increased */
                if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]) ))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;
                }
                        
                /* Write operation succeed. */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
    }
    else /* Write transaction is still in progress. */
    {
        #if (FLS_TIMEOUT_HANDLING == STD_ON)    
            /* Handle possible timeout. */
            Fls_u32LLDTimeout_Counter--;
            if( 0U == Fls_u32LLDTimeout_Counter )
            {
                /* Error, the write operation has timed out. */
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                #endif
                        
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                return;
            }
            /* else
                    Write operation still in progress, wait for another call of Fls_LLDMainFunction, do nothing. 
            */
        #else
            /* Write operation still in progress, wait for another call of Fls_LLDMainFunction, do nothing. */
        #endif
    }    
}

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
/**
* @brief          Execute a chunk of Erase blank check job scheduled previously by an asynchronous erase job.
*                 
*
* @param[in]      none
* @param[out]     none
*
* @return         none
*
* @pre            Blank check job was scheduled and is pending.
* 
*/
FUNC( void, FLS_CODE ) Fls_Qspi_MainFunctionEraseBlankCheck( void )
{
    /* Check if more than maximum allowed nr. of bytes are left to checked, more MainFunctions calls are needed. */
    if( FLS_MAX_ERASE_BLANK_CHECK < Fls_u32LLDNumberOfStepBack )
    {
        if( FLASH_E_OK != Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, FLS_MAX_ERASE_BLANK_CHECK) )
        {
            /* Error, the Erase Blank Check failed. */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        /* Update address pointers and remaining nr. of bytes to be checked. */
        Fls_Qspi_u32MemoryAddress += FLS_MAX_ERASE_BLANK_CHECK;
        Fls_u32LLDNumberOfStepBack -= FLS_MAX_ERASE_BLANK_CHECK;
    }
    else /* Fls_u32LLDNumberOfStepBack <= FLS_MAX_ERASE_BLANK_CHECK  - only this MainFunction call is needed. */
    {
        if( FLASH_E_OK != Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, Fls_u32LLDNumberOfStepBack) )
        {
            /* Error, the Erase Blank Check failed. */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return;
        }
        /* Erase Blank Check finished successfully. */
        Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
        
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_OK;
    }
}
#endif /* #if( FLS_ERASE_BLANK_CHECK == STD_ON ) */

/**
* @brief          Load the TX Buffer with data to be written.
*                 
*
* @param[in]      u32SourceAddr     Address in the application buffer holding the data to be written.
* @param[in]      u8BytesToWrite    Number of bytes to be written. Range [1:128] bytes.
* @param[out]     none
*
* @return         none
*
* @pre            Minimum number of bytes to be written using the TX Buffer is 16 bytes.
* 
*/
static FUNC( void, FLS_CODE ) Fls_Qspi_LoadTXBuffer
( 
    VAR(Fls_AddressType, FLS_VAR) u32SourceAddr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
)
{
    VAR(uint8, AUTOMATIC) u8Iter = 0U;
    
    /* Clear TX counters. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_TXF_U32 );
        
    /* Load the TX Buffer.*/
    for( u8Iter=0U; u8Iter < (u8BytesToWrite / 4U); u8Iter++)    /* Write complete words - 32bits transfers, first. */
    {            
        /* Write TX circular buffer 32bit entry. */
        /* Compiler_Warning: see fls_c_REF_CW_02 */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_TBDR_OFFSET_U32, *((volatile uint32 *)u32SourceAddr) ); /* Write 4 bytes. */
        u32SourceAddr += 4U;  /* 4 byte increment*/
    }
    /* Check if in-complete byte entries exist. */
    if( 0U !=  (u8BytesToWrite % 4U) )
    {
        VAR(uint32, AUTOMATIC) u32TxIncompleteWord = 0UL;
        
        /* Loop through remaining bytes. */
        for( u8Iter=0U; u8Iter < (u8BytesToWrite % 4U); u8Iter++) 
        {
            VAR(uint8, AUTOMATIC) u8TmpData = 0U;
            
            /* Compiler_Warning: see fls_c_REF_CW_02 */
            u8TmpData = (*((volatile uint8 *)u32SourceAddr));
            u32TxIncompleteWord = u32TxIncompleteWord | (uint32)( (uint32)u8TmpData << ((uint32)u8Iter*8UL) ); /* Write 1 byte. */
            u32SourceAddr += 1U;    /* 1 byte increment. */
        }
        /* Write TX circular buffer incomplete last entry. */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_TBDR_OFFSET_U32, u32TxIncompleteWord );
    }
}

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
/**
* @brief          Starts a Verify Erase job by mapping the job onto a read job.
*                 Checks the read values against the FLS_ERASED_VALUE value.
*                 If sync mode, performs a read operation, if irq mode, it just starts the read operation.
*                 
*
* @param[in]      u32StartAddr     Address in the memory from where the data is read.
* @param[in]      u32DataLength    Number of bytes to be read.
* @param[out]     none
*
* @return         Fls_LLDReturnType
* @retval         The return value of the SectorRead operation.
*
* @pre            
* 
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_VerifyErase
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Call the read function with pointers "p8DataReadPtr == NULL_PTR" and "p8DataCmpPtr == NULL_PTR", so to trigger the Verify Erase branch. */
    eRetVal = Fls_Qspi_SectorRead(u32StartAddr, u32DataLength, NULL_PTR, NULL_PTR);    
    
#if (FLS_DEV_ERROR_DETECT == STD_ON)    
    if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_ERASE_FAILED 
                              );
    }
#endif    
    
    return eRetVal;
}
#endif

#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
/**
* @brief          Starts a Verify Write job by mapping the job onto a read job.
*                 Checks the read values against the newly written data from the application buffer.
*                 If Sync mode, performs a read operation, if Irq mode, it just starts the read operation.
*                 
*
* @param[in]      u32StartAddr     Address in the memory from where the data is read.
* @param[in]      u32DataCmpAddr   Address in the application buffer, against which to compare the memory read data.
* @param[in]      u32DataLength    Number of bytes to be read.
* @param[out]     none
*
* @return         Fls_LLDReturnType
* @retval         The return value of the SectorRead operation.
*
* @pre            
* 
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_VerifyWrite
(
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,   /* The address in the memory, at which to start the read. */
    VAR(Fls_AddressType, AUTOMATIC) u32DataCmpAddr, /* The address in the application buffer, against which to compare the memory read data. */
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Call the read function with pointers "p8DataReadPtr == NULL_PTR" and "p8DataCmpPtr == p8DataCmpPtr", so to trigger the Compare - Verify Write branch. */
    /* Compiler_Warning: see fls_c_REF_CW_02 */
    eRetVal = Fls_Qspi_SectorRead(u32StartAddr, u32DataLength, NULL_PTR, (uint8 *)u32DataCmpAddr);    
    
#if( FLS_DEV_ERROR_DETECT == STD_ON )    
    if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_WRITE_FAILED 
                              );
    }
#endif    
    
    return eRetVal;
}
#endif

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
/*
    Hyperflash commands usually have the following structure:
        "| ADDR | DATA | ADDR | DATA | ADDR...., "
    where a pair sequence of "| ADDR | DATA |" can be considered as a Hyperflash command.
    According to the Hyperflash protocol, a pair sequence of "| ADDR | DATA |" translates on the external lines 
    to a word(2bytes) sequence of "| CA2 | CA1 | CA0 | CMD_ID |" and consists internally of 6 x Instr.Oper. LUT pairs.
    The main reason for the below translation is that Hyperflash protocol assumes a start 6 bytes sequence (3 x CAx words)
    followed by a 2 bytes data/command id, and because it is word based(16bits) while the QSPI LUT sequence engine uses byte elements.
    
    Memory POV:              |                      ADDR                  |             DATA            |
    Hyperflash protocol POV: |      CA2        |    CA1   |      CA0      |            CMD_ID           |
    QSPI LUT POV:            | CMD_DDR(Wr) | ADDR_DDR(24) | CADDR_DDR(16) | CMD_DDR(Wr) | CMD_DDR(DATA) | STOP |
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SetLUTHyperflashCmd(Fls_AddressType u32Addr, uint8 u8LUTIndex, uint8 hyperflashCmd)
{
VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;

    /* Set the start address of the IP read transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32Addr );
    
    eRetVal = Fls_Qspi_SetLUT((u8LUTIndex*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,  FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,
                                                                       FLS_LUT_INSTR_CMD_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_WRITE_MEM_WRAP 
                                                                     ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    eRetVal = Fls_Qspi_SetLUT((u8LUTIndex*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_CMD_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_NOP,
                                                                       FLS_LUT_INSTR_CADDR_DDR, FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR 
                                                                      ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    eRetVal = Fls_Qspi_SetLUT((u8LUTIndex*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,      FLS_LUT_HYPER_NOP,  FLS_LUT_HYPER_NOP,
                                                                       FLS_LUT_INSTR_CMD_DDR,   FLS_LUT_PAD_8_PADS, hyperflashCmd 
                                                                     ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    return eRetVal;                                                           
}

/** 
* @brief        Load a LUT sequence
*
* @details      Load two instruction-operand pairs into a LUT sequence.
*
* @param[in]    u8LUTNumber The LUT number[0:63]. 64 available LUTs, the DIV4 LUTs are used for launching the
*                           LUT sequence command. (For ex. LUT0, LUT4, LUT8...LUT60. Launching a command 
*                           with LUT0 will send all the instruction-operand pairs from LUT0, LUT1, LUT2 and LUT3)
* @param[in]    LUTValue    The LUT Value, each consisting of two 16 bit instruction-operand pairs.
*                           Ex: LUT0 = 31(MSB) [INSTR1 | PAD1 | OPRND1] [INSTR0 | PAD0 | OPRND0] 0(LSB)
*
* @pre          The LUT which is manually populated should be empty, and not part of LUT sequence populated during
*               Init from the configuration. During Init, the LUT is populated from the bottom up, so if
*               the LUT was not filled with all 16 sequences, it can be assumed that the top LUT numbers are free.
*
* @post         LUT sequence no. 'u8LUTNumber' is populated with one or two instruction-operand pairs.
*
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SetLUT(uint8 u8LUTNumber, uint32 LUTValue)
{ 
    #if (STD_ON == FLS_QSPI_LOCK_LUT)
        /* Unlock the LUT. */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_LUTKEY_OFFSET_U32, QSPI_LUT_KEY_VALUE_U32 );
        REG_RMW32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_LCKCR_OFFSET_U32, QSPI_LCKCR_MASK_U32, QSPI_LCKCR_UNLOCKED_U32);
        while( 0U == REG_BIT_GET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_LCKCR_OFFSET_U32, QSPI_LCKCR_UNLOCKED_U32) )
        {
            #if (FLS_TIMEOUT_HANDLING == STD_ON)
                if( 0U == Fls_u32LLDTimeout_Counter )
                {
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                Fls_u32LLDTimeout_Counter--;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        }
    #endif
    
    /* Write the 32 bit LUT register */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + (QSPI_LUT_OFFSET_U32 + ((uint32)u8LUTNumber*4UL)), LUTValue);
    
    #if (STD_ON == FLS_QSPI_LOCK_LUT)    
        /* Lock the LUT. */
        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_LUTKEY_OFFSET_U32, QSPI_LUT_KEY_VALUE_U32 );
        REG_RMW32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_LCKCR_OFFSET_U32, QSPI_LCKCR_MASK_U32, QSPI_LCKCR_LOCKED_U32);
        while( 0U == REG_BIT_GET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_LCKCR_OFFSET_U32, QSPI_LCKCR_LOCKED_U32) )
        {
            #if (FLS_TIMEOUT_HANDLING == STD_ON)
                if( 0U == Fls_u32LLDTimeout_Counter )
                {
                    /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
                    return FLASH_E_FAILED;
                }
                Fls_u32LLDTimeout_Counter--;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        }
    #endif
    
    return FLASH_E_OK;
}
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */



#if (FLS_CANCEL_API == STD_ON )
FUNC(void, FLS_CODE)Fls_Qspi_Cancel(void)
{
    /* Disable all QSPI interrupt sources. */
    REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, 
                      ( QSPI_RSER_DLPFIE_U32|QSPI_RSER_TBFIE_U32|QSPI_RSER_TBUIE_U32|QSPI_RSER_ILLINIE_U32|
                        QSPI_RSER_RBOIE_U32|QSPI_RSER_RBDIE_U32|QSPI_RSER_ABSEIE_U32|QSPI_RSER_AITIE_U32|
                        QSPI_RSER_AIBSIE_U32|QSPI_RSER_ABOIE_U32|QSPI_RSER_IUEIE_U32|QSPI_RSER_IPAEIE_U32|
                        QSPI_RSER_IPIEIE_U32|QSPI_RSER_IPGEIE_U32|QSPI_RSER_TFIE_U32 
                      )
                   );
    /* Clear all QSPI interrupt flags. */ 
    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, 
                      ( QSPI_FR_TBFF_U32|QSPI_FR_TBUF_U32|QSPI_FR_ILLINE_U32|QSPI_FR_RBOF_U32|
                        QSPI_FR_RBDF_U32|QSPI_FR_ABSEF_U32|QSPI_FR_AITEF_U32|QSPI_FR_AIBSEF_U32|
                        QSPI_FR_ABOF_U32|QSPI_FR_IUEF_U32|QSPI_FR_IPAEF_U32|QSPI_FR_IPIEF_U32|
                        QSPI_FR_IPGEF_U32|QSPI_FR_TFF_U32
                       ) 
                 ); 
    
    #if(FLS_TIMEOUT_HANDLING == STD_ON)    
        /* Initialize timeout counters */
        Fls_u32LLDTimeout_Counter = FLS_ABT_TIMEOUT_VALUE;
    #endif
                                    
    /* Mark the job as canceled.*/
    Fls_eLLDJob = FLASH_JOB_NONE;
    Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
    Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
}
#endif

/*** Interrupt routine functions. ***/
#if(FLS_USE_INTERRUPTS == STD_ON)
/*
    The Fls_Qspi_IrqEraseErase() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_ERASE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_ERASE
        - It is processing a flash erase job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseErase
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
    ,P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
#endif
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
     
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Erase command has been sent to the memory previously and TFF interrupt is expected at the end of the IP transaction. */
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear and disable the TFF interrupt.*/
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);        /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* The Erase command has finished in the controller, but is probably still pending in the external memory, 
           so launch the get status command to check if the memory is idle. */
        
        /* Schedule and launch the read of the status register, get memory status. */
        #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
            /* Prepare and enable the next interrupt(RBDF) for receiving the memory status register value. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */                         
            
            if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32ExtSectStartAddr))
            {
                /* Error during scheduling the read of status register.*/
                eRetVal = FLASH_E_FAILED;                    
            }        
            
            /* Reset the static status variables, because the next state is supposed to check and update them based on the external memory status. */
            *pbMemoryIsBusy    = (boolean)TRUE;                               
            *pbMemoryIsBusyPar = (boolean)TRUE;  
                
            /* Schedule the next state, in which the status response will be received and interpreted. */
            Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS;            
        #else            
            /* Prepare and enable the TFF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
        
            if(FLASH_E_OK != Fls_Qspi_HyperSendEnterStatusCmdIrq(Fls_Qspi_u32ExtSectStartAddr))
            {
                /* Error during scheduling the read of status register.*/
                eRetVal = FLASH_E_FAILED;                    
            }        
            
            /* Reset the static status variables, because the next state is supposed to check and update them based on the external memory status. */
            *pbMemoryIsBusy    = (boolean)TRUE; 
                
            /* Schedule the next state, in which the actual status register read request will be sent to the memory. */
            Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_GET_STATUS_1;            
        #endif  
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) 
/*
    The Fls_Qspi_IrqEraseGetStatus() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_ERASE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_GET_STATUS
        - It is processing a flash (read)get status job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received status register value and compute the busy state of the memory.
    If the memory is idle, schedule the next state, if any, or mark the erase job as finished.
    The next scheduled state could be:
        - another get status memory read, if the memory is still busy.
        - a new get status memory read sent to the second external memory, if this is a parallel sector and the first memory is idle.
        - an erase blank check read operation, if the check operation is enable
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseGetStatus
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(Fls_AddressType, AUTOMATIC) u32StatusStartAddr = 0x00U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitVal = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitPosOff = 0U;
    
     
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Status register read command has been sent to the memory previously and the RBDF interrupt is expected, in which the register value has to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        Fls_Qspi_u32StatusRegVal = 0UL;
        
        /* Read the expected number of bytes, the status register value, from the RX buffer.(Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_GetMemStatusIrq() function, when scheduling the read job) */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, (uint8 *)(&Fls_Qspi_u32StatusRegVal), NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Status register read successful, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
            
            /* Compute the busy state of the memory, based on the busy/idle bit and its value in the status register. */
            Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset)); /* Clean all the bits from the read value of the status register, except the status bit. */
            
            u8QspiUnitBusyBitVal = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue);
            u8QspiUnitBusyBitPosOff = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset);
            /*  @violates @ref fls_qspi_c_REF_7 Cast of complex expression changes signedness. */
            *pbMemoryIsBusy = (boolean)( Fls_Qspi_u32StatusRegVal == (uint32)((uint32)u8QspiUnitBusyBitVal << (uint32)u8QspiUnitBusyBitPosOff) ); /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. bMemoryIsBusy = (boolean)( u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
            
            /* Check the memory status. */
            if( (boolean)TRUE == *pbMemoryIsBusy ) /* If the first memory is still busy */
            {   
                /* The erase operation is still in progress in the external (first) memory. Schedule a new check operation for the same memory. */                    
                
                /* Enable and prepare the RBDF interrupt for a new status register read. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */
                
                /* Set Start Address for check status from external flash chip */
                if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                {
                    /* Current sector is in Parallel mode then using individual address to get status of sector in the channel A */
                    u32StatusStartAddr = Fls_Qspi_u32StartAddrIndividual_A;
                }
                else 
                {
                    /* Current sector is in Individual mode then using Address for IP command */
                    u32StatusStartAddr = Fls_Qspi_u32ExtSectStartAddr;
                }    
                
                /* Schedule and launch another read of the status register. */                
                if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(u32StatusStartAddr))
                {
                    /* Error during scheduling the read of status register.*/
                    eRetVal = FLASH_E_FAILED; 
                }
                /* Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS; - already set.*/
            }
            else /* The (first) external memory is idle. */
            {
                /* Check if the current sector is a parallel one, if so, then check the status for the second memory also. */
                if(FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt]) 
                {   
                    /* This is a parallel sector(two external memories seen as a single device), so schedule the status check for the second memory also.*/
                    
                    /* Enable and prepare the RBDF interrupt for a new status register read. */
                    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
                    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */
                    
                    /* Schedule and launch the read status for the second memory.*/
                    if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32StartAddrIndividual_B))
                    {
                        /* Error during scheduling the read of the status register.*/
                        eRetVal = FLASH_E_FAILED;
                    }
                    /* Schedule the next state, in which the status response for the second memory will be received and interpreted. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS_PAR;
                }
                else /* The current sector is not a parallel one, so the FLASH_IRQ_JOB_GET_STATUS is completely finished, schedule the next job. */
                {
                    /*The entire memory is idle, so schedule the next job, if any, or mark the erase job as finished. */
                    #if( FLS_ERASE_BLANK_CHECK == STD_ON )                        
                        /* Schedule the erase blank check(also clears the flag and enables the RBDF interrupt). */                   
                        if( FLASH_E_FAILED == Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, Fls_u32LLDNumberOfStepBack) )
                        {
                            /* Error, there was an error when attempting to schedule the job. */
                            eRetVal = FLASH_E_FAILED;                           
                        }  
                        /* else
                            Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK;  is set in the VerifyErase function.
                            Fls_eLLDJobResult = MEMIF_JOB_PENDING;       is set in the VerifyErase function.
                            The RBDF interrupt is enabled in the VerifyErase function. */
                    #else
                        /* The erase job has finished.*/
                        Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_OK;
                    #endif
                }
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/
            
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;    
}

/*
    The Fls_Qspi_IrqEraseGetStatusPar() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_ERASE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_GET_STATUS_PAR
        - It is processing a flash (read)get status job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received status register value and compute the busy state of the second memory.
    If the memory is idle, schedule the next state, if any, or mark the erase job as finished.
    The next scheduled state could be:
        - another get status memory read, if the second memory is still busy.
        - an erase blank check read operation, if the check operation is enable
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseGetStatusPar
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitVal = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitPosOff = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Status register read command has been sent to the second memory previously and the RBDF interrupt is expected, in which the register value has to be ready to read.*/    
     
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        Fls_Qspi_u32StatusRegVal = 0UL;
        
        /* Read the expected number of bytes, the status register value, from the RX buffer.(Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_GetMemStatusIrq() function, when scheduling the read job) */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, (uint8 *)(&Fls_Qspi_u32StatusRegVal), NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Status register read successful, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
            
            /* Compute the busy state of the memory, based on the busy/idle bit and its value in the status register. */
            Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset)); /* Clean all the bits from the read value of the status register, except the status bit. */   
            
            u8QspiUnitBusyBitVal = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue);
            u8QspiUnitBusyBitPosOff = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset);
            /*  @violates @ref fls_qspi_c_REF_7 Cast of complex expression changes signedness. */
            *pbMemoryIsBusyPar = (boolean)( Fls_Qspi_u32StatusRegVal == (uint32)((uint32)u8QspiUnitBusyBitVal << (uint32)u8QspiUnitBusyBitPosOff) );  /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. bMemoryIsBusyPar = (boolean)( u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
             
            /* Check the memory status. */
            if( (boolean)TRUE == *pbMemoryIsBusyPar ) /* If the second memory is still busy */
            {   
                /* The erase operation is still in progress in the external (second) memory. Schedule a new check operation for the same memory. */

                /* Enable and prepare the RBDF interrupt for a new status register read. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32); /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32); /* Enable the Receive Buffer Drain Interrupt. */
                            
                /* Schedule and launch another read of the status register. */                
                if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32StartAddrIndividual_B))
                {   
                    /* Error during scheduling the read of status register.*/
                    eRetVal = FLASH_E_FAILED;                        
                }
                /* Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS_PAR; - already set.*/
            }
            else /* The (second) external memory is idle. */
            {
                /*The entire memory is idle, so schedule the next job, if any, or mark the erase job as finished. */
                #if( FLS_ERASE_BLANK_CHECK == STD_ON )                        
                    /* Schedule the erase blank check(also clears the flag and enables the RBDF interrupt). */                   
                    if( FLASH_E_FAILED == Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, Fls_u32LLDNumberOfStepBack) )
                    {
                        /* Error, there was an error when attempting to schedule the job. */
                        eRetVal = FLASH_E_FAILED;
                    } 
                    /* else
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK; is set in the VerifyErase function.
                        Fls_eLLDJobResult = MEMIF_JOB_PENDING;      is set in the VerifyErase function.
                        The RBDF interrupt is enabled in the VerifyErase function. */
                #else
                    /* The erase job has finished.*/
                    Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_OK;
                #endif                
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/
            
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }        
                
    return eRetVal;
}
#endif /*#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
/*
    The Fls_Qspi_IrqEraseBlankCheck() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_ERASE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_BLANK_CHECK
        - It is processing a flash (read)get status job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received memory values and check that all of them are equal to the erased value.
    Check if more data has to read, if yes, schedule and launch a new read operation, if not, mark the erase job as completed.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseBlankCheck(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The read erase blank check was sent to the memory previously and the RBDF interrupt is now expected, where data has to be read. */
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        /* Read the expected number of bytes from the RX buffer (Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_VerifyErase() function, when scheduling the read job). */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, NULL_PTR, NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {          
            VAR(uint8, AUTOMATIC) u8LLDBytesToRead = 0U;
            
            /* Memory values read successfully, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
                
            /* Update the memory counter iterators. (Fls_u32LLDRemainingDataToRead, Fls_Qspi_u8LLDBytesToRead and Fls_Qspi_u32MemoryAddress are initially set in the Fls_Qspi_VerifyErase() function, when the job is scheduled) */
            u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;
            Fls_u32LLDRemainingDataToRead -= u8LLDBytesToRead;
            Fls_Qspi_u32MemoryAddress += u8LLDBytesToRead;  /* Update the flash address(memory mapped) from where to read the data. */
                
            /* Check if more data has to read and other iterations are needed. */
            if(0U < Fls_u32LLDRemainingDataToRead)
            {        
                /* Set the start address of the IP read transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );    
                
                /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
                if( Fls_u32LLDRemainingDataToRead > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* The number of bytes to be read/expected in the IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                }
                else /* if( Fls_u32LLDRemainingDataToRead < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
                {
                    /* The number of bytes to be read/expected in the IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = (uint8)Fls_u32LLDRemainingDataToRead;
                }
                
                /* Set the Watermark level, upon which the next RX interrupt will be triggered. */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;  /* Intermediate variable used to avoid order of evaluation issue caused by volatile specifier. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)(( ((uint32)u8LLDBytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
                
                /* Enable the Receive Buffer Drain Interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);
                            
                /* Re-launch the last LUT command, changing only the number of bytes.(A LUT command is triggered whenever the SEQID field is written, so by using a RMW operation, the previous LUT sequence ID which which is already written in the register is reused and only the DATASZ field is updated) */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32, QSPI_IPCR_IDATSZ_MASK_U32, (uint32)((uint32)u8LLDBytesToRead << QSPI_IPCR_IDATSZ_SHIFT_U32) );
            }    
            else
            {
                /* Erase operation(verify blank check) succeeded. The read interrupt job has finished. */
                                
                Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
                
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED, eRetVal = FLASH_E_BLOCK_INCONSISTENT.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}
#endif /* #if( FLS_ERASE_BLANK_CHECK == STD_ON ) */


/*
    The Fls_Qspi_IrqReadRead() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_READ, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_READ
        - It is processing a flash read job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received memory values and add all of them into the application buffer
    Check if more data has to read, if yes, schedule and launch a new read operation, if not, mark the read job as completed.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqReadRead(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(uint8, AUTOMATIC) u8LLDBytesToRead = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The read command has been sent to the memory previously and the RBDF interrupt is expected, in which the values have to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        /* Read the expected number of bytes from the RX buffer (Fls_Qspi_u8LLDBytesToRead and Fls_Qspi_u32BufferAddress is set previously in the Fls_Qspi_IPRead() function, when scheduling the read job). */
        u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;   /* Use an intermediary variable in order to avoid volatile order of evaluation side effects compiler warning. */
        /* Compiler_Warning: see fls_c_REF_CW_02 */
        eRetVal = Fls_Qspi_ReadRXBuffer(u8LLDBytesToRead, (uint8 *)Fls_Qspi_u32BufferAddress, NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {            
            /* Memory values read successfully, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
           
            /* Update the memory counter iterators. (Fls_u32LLDRemainingDataToRead, Fls_Qspi_u8LLDBytesToRead, Fls_Qspi_u32BufferAddress and Fls_Qspi_u32MemoryAddress are initially set in the Fls_Qspi_IPRead() function, when the job is scheduled) */
            Fls_u32LLDRemainingDataToRead -= u8LLDBytesToRead;
            Fls_Qspi_u32BufferAddress += u8LLDBytesToRead;  /* Update the target address, in the application buffer, where to store the read data. */
            Fls_Qspi_u32MemoryAddress += u8LLDBytesToRead;  /* Update the flash address(memory mapped) from where to read the data. */
            
            /* Check if more data has to read and other iterations are needed. */
            if(0U < Fls_u32LLDRemainingDataToRead)
            {
                /* Set the start address of the IP read transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );    
                
                /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
                if( Fls_u32LLDRemainingDataToRead > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                }
                else /* if( Fls_u32LLDRemainingDataToRead < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = (uint8)Fls_u32LLDRemainingDataToRead;
                }
                
                /* Set the Watermark level, upon which the next RX interrupt will be triggered. */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;  /* Intermediate variable used to avoid order of evaluation issue caused by volatile specifier. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)(( ((uint32)u8LLDBytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
            
                /* Enable the Receive Buffer Drain Interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);
                            
                /* Re-launch the last LUT command, changing only the number of bytes. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32, QSPI_IPCR_IDATSZ_MASK_U32, (uint32)((uint32)u8LLDBytesToRead << QSPI_IPCR_IDATSZ_SHIFT_U32) );
            }
            else
            {
                /* The read interrupt job has finished, no more data to be read. */

                /* The Fls_u32JobAddrIt is increased right after scheduling the read job, check if now, at the end of the job , we have to switch to the next sector or not, for the possible subsequent jobs. */
                if( (Fls_u32JobAddrIt > (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;        
                }
                
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}

/*
    The Fls_Qspi_IrqReadCompare() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_READ, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_COMPARE
        - It is processing a flash (read)compare job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received memory values and check all of them against the values from the application buffer.
    Check if more data has to read, if yes, schedule and launch a new read operation, if not, mark the compare job as completed.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqReadCompare(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(uint8, AUTOMATIC) u8LLDBytesToRead = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The read compare command has been sent to the memory previously and the RBDF interrupt is expected, in which the values have to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        /* Read the expected number of bytes from the RX buffer (Fls_Qspi_u8LLDBytesToRead and Fls_Qspi_u32BufferAddress is set previously in the Fls_Qspi_IPRead() function, when scheduling the read job). */
        u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;       /* Use an intermediary variable in order to avoid volatile order of evaluation side effects compiler warning. */
        /* Compiler_Warning: see fls_c_REF_CW_02 */
        eRetVal = Fls_Qspi_ReadRXBuffer(u8LLDBytesToRead, NULL_PTR, (uint8 *)Fls_Qspi_u32BufferAddress);
        if(FLASH_E_OK == eRetVal)
        {            
            /* Memory values read successfully, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
           
            /* Update the memory counter iterators. (Fls_u32LLDRemainingDataToRead, Fls_Qspi_u8LLDBytesToRead, Fls_Qspi_u32BufferAddress and Fls_Qspi_u32MemoryAddress are initially set in the Fls_Qspi_IPRead() function, when the job is scheduled) */
            Fls_u32LLDRemainingDataToRead -= u8LLDBytesToRead;
            Fls_Qspi_u32BufferAddress += u8LLDBytesToRead;  /* Update the target address, in the application buffer, against which the read data is compared. */
            Fls_Qspi_u32MemoryAddress += u8LLDBytesToRead;  /* Update the flash address(memory mapped) from where to read the data. */
                
            /* Check if more data has to read and other iterations are needed. */
            if(0U < Fls_u32LLDRemainingDataToRead)
            {
                /* Set the start address of the IP read transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );    
                
                /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
                if( Fls_u32LLDRemainingDataToRead > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                }
                else /* if( Fls_u32LLDRemainingDataToRead < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = (uint8)Fls_u32LLDRemainingDataToRead;
                }
                
                /* Set the Watermark level, upon which the next RX interrupt will be triggered. */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;  /* Intermediate variable used to avoid order of evaluation issue caused by volatile specifier. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)(( ((uint32)u8LLDBytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
            
                /* Enable the Receive Buffer Drain Interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);
                            
                /* Re-launch the last LUT command, changing only the number of bytes. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32, QSPI_IPCR_IDATSZ_MASK_U32, (uint32)((uint32)u8LLDBytesToRead << QSPI_IPCR_IDATSZ_SHIFT_U32) );
            }
            else
            {
                /* The read compare interrupt job has finished, no more data to be read. */

                /* The Fls_u32JobAddrIt is increased right after scheduling the read job, check if now, at the end of the job , we have to switch to the next sector or not, for the possible subsequent jobs. */
                if( (Fls_u32JobAddrIt > (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;        
                }
                
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED, eRetVal = FLASH_E_BLOCK_INCONSISTENT.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;  
}

#if( FLS_BLANK_CHECK_API == STD_ON )
/*
    The Fls_Qspi_IrqReadBlankCheck() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_READ, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_BLANK_CHECK
        - It is processing a flash (read)blank check, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received memory values and check that all of them are equal to the erased value.
    Check if more data has to read, if yes, schedule and launch a new read operation, if not, mark the read blank check job as completed.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqReadBlankCheck(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(uint8, AUTOMATIC) u8LLDBytesToRead = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The read blank check command has been sent to the memory previously and the RBDF interrupt is expected, in which the values have to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        /* Read the expected number of bytes from the RX buffer (Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_IPRead() function, when scheduling the read job). */
        u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;       /* Use an intermediary variable in order to avoid volatile order of evaluation side effects compiler warning. */
        eRetVal = Fls_Qspi_ReadRXBuffer(u8LLDBytesToRead, NULL_PTR, NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Memory values read successfully, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
           
            /* Update the memory counter iterators. (Fls_u32LLDRemainingDataToRead, Fls_Qspi_u8LLDBytesToRead and Fls_Qspi_u32MemoryAddress are initially set in the Fls_Qspi_IPRead() function, when the job is scheduled) */
            Fls_u32LLDRemainingDataToRead -= u8LLDBytesToRead;
            Fls_Qspi_u32MemoryAddress += u8LLDBytesToRead;  /* Update the flash address(memory mapped) from where to read the data. */
                    
            /* Check if more data has to read and other iterations are needed. */
            if(0U < Fls_u32LLDRemainingDataToRead)
            {
                /* Set the start address of the IP read transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );    
                
                /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
                if( Fls_u32LLDRemainingDataToRead > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                }
                else /* if( Fls_u32LLDRemainingDataToRead < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = (uint8)Fls_u32LLDRemainingDataToRead;
                }
            
                /* Set the Watermark level, upon which the next RX interrupt will be triggered. */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;       /* Use an intermediary variable in order to avoid volatile order of evaluation side effects compiler warning. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, ( ((uint32)u8LLDBytesToRead + 3U) / 4U ) - 1U ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
            
                /* Enable the Receive Buffer Drain Interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);
                            
                /* Re-launch the last LUT command, changing only the number of bytes. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32, QSPI_IPCR_IDATSZ_MASK_U32, (uint32)((uint32)u8LLDBytesToRead << QSPI_IPCR_IDATSZ_SHIFT_U32) );                
            }
            else
            {
                /* The read blank check interrupt job has finished, no more data to be read. */

                /* The Fls_u32JobAddrIt is increased right after scheduling the read job, check if now, at the end of the job , we have to switch to the next sector or not, for the possible subsequent jobs. */
                if( (Fls_u32JobAddrIt > (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;        
                }
                
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED, eRetVal = FLASH_E_BLOCK_INCONSISTENT.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;   
}
#endif /*#if( FLS_BLANK_CHECK_API == STD_ON )*/

#if( FLS_WRITE_BLANK_CHECK == STD_ON )
/*
    The Fls_Qspi_IrqWriteBlankCheck() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_BLANK_CHECK
        - It is processing a flash (read)blank check, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received memory values and check that all of them are equal to the erased value.
    Check if more data has to read, if yes, schedule and launch a new read operation, if not, mark the read blank check job as completed.
    
    Previous possible states:
        - Initial state (the FLASH_IRQ_JOB_BLANK_CHECK can be scheduled only at the beginning of a write job, in Fls_Qspi_SectorWrite() function).
        
    Next possible states:
        - FLASH_IRQ_JOB_BLANK_CHECK, the same state is scheduled again, more data to be read.
        - FLASH_IRQ_JOB_WRITE_EN, for normal flash sectors, not hyperflash memory.
        - FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1, for hyperflash memory only.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteBlankCheck(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
    VAR(uint8, AUTOMATIC) u8ParEn;
#endif       

    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The write blank check command has been sent to the memory previously and the RBDF interrupt is expected, in which the values have to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        /* Read the expected number of bytes from the RX buffer (Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_VerifyErase() function, when scheduling the read job). The Fls_Qspi_ReadRXBuffer() functions checks internally the read values against the erase value. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, NULL_PTR, NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {                  
            VAR(uint8, AUTOMATIC) u8LLDBytesToRead = 0U;
            
            /* Memory values read successfully, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
                    
            /* Update the memory counter iterators. (Fls_u32LLDRemainingDataToRead, Fls_Qspi_u8LLDBytesToRead and Fls_Qspi_u32MemoryAddress are initially set in the Fls_Qspi_VerifyErase() function, when the job is scheduled) */
            u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;
            Fls_u32LLDRemainingDataToRead -= u8LLDBytesToRead;  /* Fls_u32LLDRemainingDataToRead is the value of the entire area to be checked before the read operation. */
            Fls_Qspi_u32MemoryAddress += u8LLDBytesToRead;       /* Update the flash address(memory mapped) from where to read the data. */
                
            /* Check if more data has to read and other iterations are needed. */
            if(0U < Fls_u32LLDRemainingDataToRead)
            {
                /* Set the start address of the IP read transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );    
                
                /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
                if( Fls_u32LLDRemainingDataToRead > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* The number of bytes to be read/expected in the IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                }
                else /* if( Fls_u32LLDRemainingDataToRead < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
                {
                    /* The number of bytes to be read/expected in the IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = (uint8)Fls_u32LLDRemainingDataToRead;
                }
                
                /* Set the Watermark level, upon which the next RX interrupt will be triggered. */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;  /* Intermediate variable used to avoid order of evaluation issue caused by volatile specifier. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)(( ((uint32)u8LLDBytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
                
                /* Enable the Receive Buffer Drain Interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);
                            
                /* Re-launch the last LUT command, changing only the number of bytes.(A LUT command is triggered whenever the SEQID field is written, so by using a RMW operation, the previous LUT sequence ID which which is already written in the register is reused and only the DATASZ field is updated) */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32, QSPI_IPCR_IDATSZ_MASK_U32, (uint32)((uint32)u8LLDBytesToRead << QSPI_IPCR_IDATSZ_SHIFT_U32) );
                
                /* The state remains the same, already set when the blank check job was scheduled in Fls_Qspi_SectorWrite(). 
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK; */
            } 
            else
            {   /* Verify erase succeeded, the read interrupt job has finished. */
                                   
                /* Restore the initial write location. Fls_Qspi_u32MemoryAddress was incremented progressively in the verify erase stage. */
                Fls_Qspi_u32MemoryAddress -= Fls_u32LLDNumberOfStepBack;
                 
                /* Prepare and enable the TFF interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
                                
                /* Use the Normal or Hyperflash LUT sequence. */
                #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
                    
                    /* Schedule the write enable IRQ job. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_WRITE_EN;
    
                    if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                    {
                        u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
                    }
                    else /* FLS_QSPI_CH_INDIVIDUAL */
                    {
                        u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
                    }
    
                    /* Enable the Write/Erase operation on the external memory(will launch the write enable command). */   
                    if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32ExtSectStartAddr, u8ParEn) )
                    {
                        /* Error, WriteEnable command has failed when attempting to schedule it. */            
                        eRetVal = FLASH_E_FAILED;
                    }  
                    
                #else
                    
                    /* Schedule the write unlock sequence 1 IRQ job. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1;
                    
                    /* Schedule and launch the first write unlock 1 sequence. */   
                    if( FLASH_E_OK != Fls_Qspi_HyperSendUnlock1Irq(Fls_Qspi_u32ExtSectStartAddr) )
                    {
                        /* Error, Write unlock sequence 1 command has failed when attempting to schedule it. */            
                        eRetVal = FLASH_E_FAILED;
                    }
                    
                #endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED, eRetVal = FLASH_E_BLOCK_INCONSISTENT.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}
#endif /*#if( FLS_WRITE_BLANK_CHECK == STD_ON )*/

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
/*
    The Fls_Qspi_IrqWriteWriteEnable() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_WRITE_EN
        - It is processing a flash write enable, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Process the write enable command by scheduling and launching the get memory status command, to check the memory state after the write enable command.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteWriteEnable
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy,
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The write enable command has been sent to the memory previously and the TFF interrupt is expected, in which to launch the get status command.*/    
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear the interrupt flag and disable the TFF interrupt source. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* The WriteEnable command has finished in the controller, but is probably still pending in the external memory, so launch the check status command. */
        
        /* Prepare and enable the RBDF interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);   /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */                 
                
        /* Schedule and launch the read of the status register, get memory status. */
        if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }
        
        /* Reset the static status variables, because the next state is supposed to check and update them based on the external memory status. */
        *pbMemoryIsBusy    = (boolean)TRUE;                               
        *pbMemoryIsBusyPar = (boolean)TRUE;

        /* Mark the memory state as write enabled - indicate the next state can be an actual memory write, because the WriteEnable command is sent here to the memory. */
        Fls_Qspi_bIrqMemWriteEnabled = (boolean)TRUE;
                
        /* Schedule the next state, in which the status response will be received and interpreted. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS;
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}
#endif /*#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)*/

/*
    The Fls_Qspi_IrqWriteWrite() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_WRITE
        - It is processing a flash write, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Process the write command by scheduling and launching the get memory status command, to check the memory state after the write command.
*/
/* @violates @ref fls_qspi_c_REF_8 All declarations and definitions of objects should have internal linkage. */
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteWrite
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy,
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The write command has been sent to the memory previously and the TFF interrupt is expected, in which to launch the get status command.*/    
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear the interrupt flag and disable the TFF interrupt source. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* The Write command has finished in the controller, but is probably still pending in the external memory, 
           so launch the check status command. */
        
        /* Prepare and enable the RBDF interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);   /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */                 
         
        /* Schedule and launch the read of the status register, get memory status. */
        if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }
        
        /* Reset the static status variables, because the next state is supposed to check and update them based on the external memory status. */
        *pbMemoryIsBusy    = (boolean)TRUE;                               
        *pbMemoryIsBusyPar = (boolean)TRUE;
        
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
        /* Mark the memory state as write disabled - indicate the the next state has to be a new WriteEnable command because the previous write enable latched bit was cleared by this data write. */
        Fls_Qspi_bIrqMemWriteEnabled = (boolean)FALSE;
    #endif    
                
        /* Schedule the next state, in which the status response will be received and interpreted. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS;
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
        
    return eRetVal;
}

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
/*
    The Fls_Qspi_IrqWriteGetStatus() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_GET_STATUS
        - It is processing a flash (read)get status job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received status register value and compute the busy state of the memory.
    If the memory is idle, schedule the next state, if any, or mark the write job as finished.
    The next scheduled state could be:
        - another get status memory read, if the memory is still busy.
        - a new get status memory read sent to the second external memory, if this is a parallel sector and the first memory is idle.
        - a write operation, if this job is following a write enable command.
        - a write operation, if this job is following another write command, and there are more data to be written.
        - a compare(verify write) operation, if the check operation is enabled.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteGetStatus
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(Fls_AddressType, AUTOMATIC) u32StatusStartAddr = 0x00U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitVal = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitPosOff = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Status register read command has been sent to the memory previously and the RBDF interrupt is expected, in which the register value has to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        Fls_Qspi_u32StatusRegVal = 0UL;
        
        /* Read the expected number of bytes, the status register value, from the RX buffer.(Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_GetMemStatusIrq() function, when scheduling the read job) */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, (uint8 *)(&Fls_Qspi_u32StatusRegVal), NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Status register read successful, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
            
            /* Compute the busy state of the memory, based on the busy/idle bit and its value in the status register. */
            Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset)); /* Clean all the bits from the read value of the status register, except the status bit. */
            
            u8QspiUnitBusyBitVal = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue);
            u8QspiUnitBusyBitPosOff = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset);
            /*  @violates @ref fls_qspi_c_REF_7 Cast of complex expression changes signedness. */
            *pbMemoryIsBusy = (boolean)( Fls_Qspi_u32StatusRegVal == (uint32)((uint32)u8QspiUnitBusyBitVal << (uint32)u8QspiUnitBusyBitPosOff) ); /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. bMemoryIsBusy = (boolean)( u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
            
            /* Check the memory status. */
            if( (boolean)TRUE == *pbMemoryIsBusy ) /* If the first memory is still busy */
            {   
                /* The erase operation is still in progress in the external (first) memory. Schedule a new check operation for the same memory. */                    
                
                /* Enable and prepare the RBDF interrupt for a new status register read. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */
                
                /* Set Start Address for check status from external flash chip */
                if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                {
                    /* Current sector is in Parallel mode then using individual address to get status of sector in the channel A */
                    u32StatusStartAddr = Fls_Qspi_u32StartAddrIndividual_A;
                }
                else 
                {
                    /* Current sector is in Individual mode then using Address for IP command */
                    u32StatusStartAddr = Fls_Qspi_u32ExtSectStartAddr;
                }    
                
                /* Schedule and launch another read of the status register. */                
                if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(u32StatusStartAddr))
                {
                    /* Error during scheduling the read of status register.*/
                    eRetVal = FLASH_E_FAILED; 
                }
                /* Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS; - already set.*/
            }
            else /* The (first) external memory is idle. */
            {
                /* Check if the current sector is a parallel one, if so, then check the status for the second memory also. */
                if(FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt]) 
                {   
                    /* This is a parallel sector(two external memories seen as a single device), so schedule the status check for the second memory also.*/
                    
                    /* Enable and prepare the RBDF interrupt for a new status register read. */
                    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
                    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */
                    
                    /* Schedule and launch the read status for the second memory.*/
                    if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32StartAddrIndividual_B))
                    {
                        /* Error during scheduling the read of the status register.*/
                        eRetVal = FLASH_E_FAILED;
                    }
                    /* Schedule the next state, in which the status response for the second memory will be received and interpreted. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS_PAR;
                }
                else /* The current sector is not a parallel one, so the FLASH_IRQ_JOB_GET_STATUS is completely finished, schedule the next job. */
                {
                    /*The entire memory is idle, so schedule the next job, if any, or mark the write job as finished. */
                    if(0UL < Fls_u32LLDRemainingDataToWrite)    /* If there is more data to be written */
                    {                        
                        /* Check if the memory is write enabled. The actual data write can happen only if previously the 
                           WritenEnable command had been sent to the memory.
                           If the WriteEnable command had been already sent to the memory: schedule and launch the actual data write.
                           If the WriteEnable command was not sent to the memory: schedule and launch the WriteEnable first. */
                        if( (boolean)TRUE == Fls_Qspi_bIrqMemWriteEnabled )
                        {
                            /* Schedule the actual data write. */
                         
                            /*Schedule the next IRQ write job.*/
                            VAR(uint8, AUTOMATIC) u8BytesToWrite = 0U;  /* Number of bytes to be written in this function iteration, up to a max of TXBuffer size. */
                            VAR(uint8, AUTOMATIC) u8LUTWriteId = 0U;
                            VAR(uint8, AUTOMATIC) u8ParEn = 0U; 
                            VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
                            VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;                           
                        #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
                            VAR(uint32, AUTOMATIC) u32SectProgSize = (*(Fls_pConfigPtr->paSectorProgSize))[Fls_u32JobSectorIt];   /* Sector Programming size configuration parameter. */
                        #endif
                            
                            /* Get LUT Write sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
                            u8LUTWriteId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTWriteSeq;
                            /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
                            if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                            {
                                u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
                            }
                            else /* FLS_QSPI_CH_INDIVIDUAL */
                            {
                                u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
                            } 
                            
                            /* Check if the total number of bytes to be written exceeds the TXBuffer size. */
                            if( Fls_u32LLDRemainingDataToWrite > QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                            {
                                /* More than the maximum size of TX Buffer has to sent, use only 128bytes. */
                                u8BytesToWrite = QSPI_TXBUFFER_MAX_SIZE_BYTES_U32; 
                            }
                            else
                            {
                                u8BytesToWrite = (uint8)Fls_u32LLDRemainingDataToWrite;
                            }
                            
                            /* Check if the total no. of bytes to be written will exceed the external memory internal buffer.
                               If the internal buffer boundary is exceeded, the actual memory writes could wrap-around in the memory. */
                            u32MemAddr1 = Fls_Qspi_u32MemoryAddress/u32SectProgSize;
                            u32MemAddr2 = ((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/u32SectProgSize;
                            if( u32MemAddr1 != u32MemAddr2 )
                            {    
                                VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0UL;   /* The last byte address of the current flash line. */
                                    
                                /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
                                /*u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % u32SectProgSize) + (u32SectProgSize - 1U);Split into multiple statements in order to avoid MISRA error. */
                                u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
                                u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % u32SectProgSize;
                                u32LineEndAddr += u32SectProgSize - 1U;
                                u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);   
                            } 
                                    
                            /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                            Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                            /* Update the source address pointer in the application buffer with the amount loaded above into TX Buffer*/
                            Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                                    
                            /* Set the start address of the IP write transaction. */
                            REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
            
                            /* Prepare and enable the TFF interrupt. */
                            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Enable the Transaction Finished Interrupt. */
                        
                            /* Launch WRITE command. */
                            Fls_Qspi_LaunchLUTCommand(u8LUTWriteId, u8BytesToWrite, u8ParEn); 
                                    
                            /* Update external write address. */
                            Fls_Qspi_u32MemoryAddress += u8BytesToWrite;
                            /* "Fls_Qspi_u32BufferAddress" is updated above, right after loading it into the TX Buffer. */
                            /* Update the remaining number of bytes to be written. */
                            Fls_u32LLDRemainingDataToWrite -= u8BytesToWrite;
        
                            /* Schedule the write job*/
                            Fls_eLLDIrqJob = FLASH_IRQ_JOB_WRITE; 
                        }
                        else /* The memory has to be write enabled before being able to attempt writing the actual data. */
                        {
                            VAR(uint8, AUTOMATIC) u8ParEn;
                            
                            /* Schedule the WriteEnable prior to attempting to write the actual data. */
                            
                            /* Schedule the write enable IRQ job. */
                            Fls_eLLDIrqJob = FLASH_IRQ_JOB_WRITE_EN;
                                                   
                            /* Use the Normal LUT sequence, no Hyperflash mode is available in this state. */
                                                     
                            /* Prepare and enable the TFF interrupt. */
                            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
            
                            if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                            {
                                u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
                            }
                            else /* FLS_QSPI_CH_INDIVIDUAL */
                            {
                                u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
                            }
            
                            /* Enable the Write/Erase operation on the external memory(will launch the write enable command). */   
                            if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
                            {
                                /* Error, WriteEnable command has failed when attempting to schedule it. */            
                                eRetVal = FLASH_E_FAILED;
                            }                              
                        }
                    }
                    else /* No more remaining data to write. */
                    {
                        /* The programming part of the write job has finished. Schedule the next job(verify write), if any, or mark the write job as complete. */
                        
                        #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                            VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
                            VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL; 
                            
                            /* Schedule the write verify check, if enabled. */
                            u32MemAddr1 = Fls_Qspi_u32MemoryAddress - Fls_u32LLDNumberOfStepBack;
                            u32MemAddr2 = Fls_Qspi_u32BufferAddress - Fls_u32LLDNumberOfStepBack;
                            if( FLASH_E_FAILED == Fls_Qspi_VerifyWrite( u32MemAddr1, u32MemAddr2, Fls_u32LLDNumberOfStepBack ) )
                            {
                                /* Error, there was an error when attempting to schedule the memory read. */
                                eRetVal = FLASH_E_FAILED;
                            } 
                            /* else
                                Fls_eLLDIrqJob = FLASH_IRQ_JOB_COMPARE;  is set in the VerifyErase function.
                                Fls_eLLDJobResult = MEMIF_JOB_PENDING;   is set in the VerifyErase function.
                                The RBDF interrupt is enabled in the VerifyErase function. */
                        #else
                            /*The write job has finished successfully.*/
                    
                            /* For a Write Job in IRQ mode check if Fls_u32JobSectorIt should be increased */
                            if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]) ))
                            {
                                /* Move on to the next sector */
                                Fls_u32JobSectorIt++;
                            }
                            
                            Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                            Fls_eLLDJobResult = MEMIF_JOB_OK; 
                        #endif
                    }
                }
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/            
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;    
}

/*
    The Fls_Qspi_IrqWriteGetStatusPar() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_GET_STATUS_PAR
        - It is processing a flash (read)get status job, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received status register value and compute the busy state of the memory.
    If the memory is idle, schedule the next state, if any, or mark the write job as finished.
    The next scheduled state could be:
        - another get status memory read, if the (second) memory is still busy.
        - a write operation, if this job is following a write enable command.
        - a write operation, if this job is following another write command, and there are more data to be written.
        - a compare(verify write) operation, if the check operation is enabled.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteGetStatusPar
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitVal = 0U;
    VAR(uint8, AUTOMATIC) u8QspiUnitBusyBitPosOff = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Status register read command has been sent to the second memory previously and the RBDF interrupt is expected, in which the register value has to be ready to read.*/    
     
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        Fls_Qspi_u32StatusRegVal = 0UL;
        
        /* Read the expected number of bytes, the status register value, from the RX buffer.(Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_GetMemStatusIrq() function, when scheduling the read job) */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, (uint8 *)(&Fls_Qspi_u32StatusRegVal), NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Status register read successful, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
            
            /* Compute the busy state of the memory, based on the busy/idle bit and its value in the status register. */
            Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset)); /* Clean all the bits from the read value of the status register, except the status bit. */   
            
            u8QspiUnitBusyBitVal = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue);
            u8QspiUnitBusyBitPosOff = ((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset);
            /*  @violates @ref fls_qspi_c_REF_7 Cast of complex expression changes signedness. */
            *pbMemoryIsBusyPar = (boolean)( Fls_Qspi_u32StatusRegVal == (uint32)((uint32)u8QspiUnitBusyBitVal << (uint32)u8QspiUnitBusyBitPosOff) );  /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. bMemoryIsBusyPar = (boolean)( u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
             
            /* Check the memory status. */
            if( (boolean)TRUE == *pbMemoryIsBusyPar ) /* If the second memory is still busy */
            {   
                /* The write operation is still in progress in the external (second) memory. Schedule a new check operation for the same memory. */

                /* Enable and prepare the RBDF interrupt for a new status register read. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32); /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32); /* Enable the Receive Buffer Drain Interrupt. */
                            
                /* Schedule and launch another read of the status register. */                
                if(FLASH_E_OK != Fls_Qspi_GetMemStatusIrq(Fls_Qspi_u32StartAddrIndividual_B))
                {   
                    /* Error during scheduling the read of status register.*/
                    eRetVal = FLASH_E_FAILED;                        
                }
                /* Fls_eLLDIrqJob = FLASH_IRQ_JOB_GET_STATUS_PAR; - already set.*/
            }
            else /* The (second) external memory is idle. */
            {
                /*The entire memory is idle, so schedule the next job, if any, or mark the write job as finished. */
                if(0UL < Fls_u32LLDRemainingDataToWrite)    /* If there is more data to be written */
                {
                        
                    /* Check if the memory is write enabled. The actual data write can happen only if previously the 
                       WritenEnable command had been sent to the memory.
                       If the WriteEnable command had been already sent to the memory: schedule and launch the actual data write.
                       If the WriteEnable command was not sent to the memory: schedule and launch the WriteEnable first. */
                    if( (boolean)TRUE == Fls_Qspi_bIrqMemWriteEnabled )
                    {
                        /*Schedule the next write IRQ job.*/
                        VAR(uint8, AUTOMATIC) u8BytesToWrite = 0U;  /* Number of bytes to be written in this function iteration, up to a max of TXBuffer size. */
                        VAR(uint8, AUTOMATIC) u8LUTWriteId = 0U;
                        VAR(uint8, AUTOMATIC) u8ParEn = 0U;
                                
                        /* Get LUT Write sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
                        u8LUTWriteId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTWriteSeq;
                        /* Set PARALLEL ENABLE mode bit if current sector is a parallel one. */
                        if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                        {
                            u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
                        }
                        else /* FLS_QSPI_CH_INDIVIDUAL */
                        {
                            u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
                        } 

                        /* Check if the total number of bytes to be written exceeds the TXBuffer size. */
                        if( Fls_u32LLDRemainingDataToWrite > QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                        {
                            /* More than the maximum size of TX Buffer has to sent, use only 128bytes. */
                            u8BytesToWrite = QSPI_TXBUFFER_MAX_SIZE_BYTES_U32; 
                        }
                        else
                        {
                            u8BytesToWrite = (uint8)Fls_u32LLDRemainingDataToWrite;
                        }
                                
                        /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
                        Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
                        /* Update the source address pointer with the amount loaded above into TX Buffer*/
                        Fls_Qspi_u32BufferAddress += u8BytesToWrite;
                        
                        /* Set the start address of the IP write transaction. */
                        REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );
         
                        /* Prepare and enable the TFF interrupt. */
                        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Enable the Transaction Finished Interrupt. */
                        
                        /* Launch WRITE command. */
                        Fls_Qspi_LaunchLUTCommand(u8LUTWriteId, u8BytesToWrite, u8ParEn); 
                                
                        /* Update external write address. */
                        Fls_Qspi_u32MemoryAddress += u8BytesToWrite;
                        /* "Fls_Qspi_u32BufferAddress" is updated above, right after loading it into the TX Buffer. */
                        /* Update the remaining number of bytes to be written. */
                        Fls_u32LLDRemainingDataToWrite -= u8BytesToWrite;

                        /* Schedule the write job*/
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_WRITE;
                    }
                    else /* The memory has to be write enabled before being able to attempt writing the actual data. */
                    {
                        VAR(uint8, AUTOMATIC) u8ParEn;
                            
                        /* Schedule the WriteEnable prior to attempting to write the actual data. */
                        
                        /* Schedule the write enable IRQ job. */
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_WRITE_EN;
                                               
                        /* Use the Normal LUT sequence, no Hyperflash mode is available in this state. */
                         
                        /* Prepare and enable the TFF interrupt. */
                        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
        
                        if ( FLS_QSPI_CH_PARALLEL == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiSectChParallel))[Fls_u32JobSectorIt] )
                        {
                            u8ParEn = QSPI_PARALLEL_MODE_ENABLED;
                        }
                        else /* FLS_QSPI_CH_INDIVIDUAL */
                        {
                            u8ParEn = QSPI_PARALLEL_MODE_DISABLED;
                        }
        
                        /* Enable the Write/Erase operation on the external memory(will launch the write enable command). */   
                        if( FLASH_E_OK != Fls_Qspi_WriteEnable(Fls_Qspi_u32MemoryAddress, u8ParEn) )
                        {
                            /* Error, WriteEnable command has failed when attempting to schedule it. */            
                            eRetVal = FLASH_E_FAILED;
                        }                                                   
                    }                    
                }
                else /* No more remaining data to write. */
                {
                    /* The programming part of the write job has finished. Schedule the next job, if any, or mark the write job as complete. */
                    
                    #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                        VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
                        VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL;
                        
                        /* Schedule the write verify check, if enabled. */
                        u32MemAddr1 = Fls_Qspi_u32MemoryAddress - Fls_u32LLDNumberOfStepBack;
                        u32MemAddr2 = Fls_Qspi_u32BufferAddress - Fls_u32LLDNumberOfStepBack;
                        if( FLASH_E_FAILED == Fls_Qspi_VerifyWrite( u32MemAddr1, u32MemAddr2, Fls_u32LLDNumberOfStepBack ) )
                        {
                            /* Error, there was an error when attempting to schedule the memory read. */
                            eRetVal = FLASH_E_FAILED;
                        } 
                        /* else 
                            Fls_eLLDIrqJob = FLASH_IRQ_JOB_COMPARE;  is set in the VerifyErase function. 
                            Fls_eLLDJobResult = MEMIF_JOB_PENDING;   is set in the VerifyErase function.
                            The RBDF interrupt is enabled in the VerifyErase function. */
                    #else
                        /*The write job has finished successfully.*/
                
                        /* For a Write Job in IRQ mode check if Fls_u32JobSectorIt should be increased */
                        if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]) ))
                        {
                            /* Move on to the next sector */
                            Fls_u32JobSectorIt++;
                        }
                        
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_OK; 
                    #endif
                }                
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/            
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }        
                
    return eRetVal;   
}
#endif /*#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)*/

#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
/*
    The Fls_Qspi_IrqWriteCompare() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_COMPARE
        - It is processing a flash (read)compare, on a QSPI sector, which has the FLS_SECTOR_IRQ_MODE flag set
    Read the received memory values and check that all of them are equal to the newly written values, compared against the provided application buffer.
    Check if more data has to read, if yes, schedule and launch a new read operation, if not, mark the compare job as completed.
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteCompare(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
    VAR(uint8, AUTOMATIC) u8LLDBytesToRead = 0U;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The read compare command has been sent to the memory previously and the RBDF interrupt is expected, in which the values have to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        /* Read the expected number of bytes from the RX buffer (Fls_Qspi_u8LLDBytesToRead and Fls_Qspi_u32BufferAddress is set previously in the Fls_Qspi_IPRead() function, when scheduling the read job). */
        u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;   /* Use an intermediary variable in order to avoid volatile order of evaluation side effects compiler warning. */
        /* Compiler_Warning: see fls_c_REF_CW_02 */
        eRetVal = Fls_Qspi_ReadRXBuffer(u8LLDBytesToRead, NULL_PTR, (uint8 *)Fls_Qspi_u32BufferAddress);
        if(FLASH_E_OK == eRetVal)
        {
            
            /* Memory values read successfully, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
           
            /* Update the memory counter iterators. (Fls_u32LLDRemainingDataToRead, Fls_Qspi_u8LLDBytesToRead, Fls_Qspi_u32BufferAddress and Fls_Qspi_u32MemoryAddress are initially set in the Fls_Qspi_VerifyWrite() function, when the job is scheduled) */
            Fls_u32LLDRemainingDataToRead -= u8LLDBytesToRead;
            Fls_Qspi_u32BufferAddress += u8LLDBytesToRead;  /* Update the target address, in the application buffer, against which the read data is compared. */
            Fls_Qspi_u32MemoryAddress += u8LLDBytesToRead;  /* Update the flash address(memory mapped) from where to read the data. */
                
            /* Check if more data has to read and other iterations are needed. */
            if(0UL < Fls_u32LLDRemainingDataToRead)
            {
                /* Set the start address of the IP read transaction. */
                REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, Fls_Qspi_u32MemoryAddress );    
                
                /* Determine the maximum number to be read in an IRQ iteration: limited by the maximum size of the RX buffer or the total maximum size which has to be read, if smaller. */
                if( Fls_u32LLDRemainingDataToRead > QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = QSPI_RXBUFFER_MAX_SIZE_BYTES_U32;
                }
                else /* if( Fls_u32LLDRemainingDataToRead < QSPI_RXBUFFER_MAX_SIZE_BYTES_U32 ) */
                {
                    /* The number of bytes to be read/expected in the firs IRQ iteration. */
                    Fls_Qspi_u8LLDBytesToRead = (uint8)Fls_u32LLDRemainingDataToRead;
                }
            
                /* Set the Watermark level, upon which the next RX interrupt will be triggered. */
                u8LLDBytesToRead = Fls_Qspi_u8LLDBytesToRead;  /* Intermediate variable used to avoid order of evaluation issue caused by volatile specifier. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)(( ((uint32)u8LLDBytesToRead + 3U) / 4U ) - 1U) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */
                
                /* Enable the Receive Buffer Drain Interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);
                            
                /* Re-launch the last LUT command, changing only the number of bytes. */
                REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32, QSPI_IPCR_IDATSZ_MASK_U32, (uint32)((uint32)u8LLDBytesToRead << QSPI_IPCR_IDATSZ_SHIFT_U32) );
                
                /* The state remains the same, already set when the blank check job was scheduled in Fls_Qspi_VerifyWrite(). 
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_COMPARE; */
            }
            else
            {
                /* The verify write compare interrupt job has finished, no more data to be read. */

                /* The Fls_u32JobAddrIt is increased right after scheduling the read job, check if now, at the end of the job , we have to switch to the next sector or not, for the possible subsequent jobs. */
                if( (Fls_u32JobAddrIt > (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;        
                }
                
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED, eRetVal = FLASH_E_BLOCK_INCONSISTENT.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal; 
}
#endif /*#if( FLS_WRITE_VERIFY_CHECK == STD_ON )*/

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_GetMemStatusIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr)
{
    VAR(uint8, AUTOMATIC) u8LUTGetStatusId;      
    VAR(uint8, AUTOMATIC) u8ExtRegWidth;
    
    /* Clear reception flags, counters, prior to triggering the IP command. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
      
    /* Set the Watermark level. */
    REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, 0U );   /* Expect 1 word(4byte entries) */
      
    /* Get the external memory register width,in bytes no., in order to determine the transfer length. */
    u8ExtRegWidth = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitRegisterWidth;
    /* Check "u8ExtRegWidth" is no bigger than 4 bytes, otherwise data might get corrupted when updating the "u32ExtRegValue". */
    if(4U < u8ExtRegWidth)
    {
        /* Error, the register width is bigger than the variable in which it has to be stored. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }  
    
    /* Check if controller is busy(BUSY bit asserted). */
    if( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )
    {
        /* Error, controller is not idle. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
        
    /* Schedule the read of the status register. */
    Fls_Qspi_u8LLDBytesToRead = u8ExtRegWidth;
    
    /* Use the Normal LUT sequence, no Hyperflash mode is available in this state. */
    
    /* Get LUT Get Status sequence index. The configuration structure holds the index from the LUT configuration array(0,1,2,...) */
    u8LUTGetStatusId = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiLUTGetStatusSeq;
                
    /* Set the start address of the IP read status transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );    
       
    Fls_Qspi_LaunchLUTCommand(u8LUTGetStatusId, u8ExtRegWidth, QSPI_PARALLEL_MODE_DISABLED);                                        
        
    return FLASH_E_OK;    
}

/*** Hyperflash specific interrupt routine functions. ***/
#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendEnterStatusCmdIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
        
    /* Check if controller is busy(BUSY bit asserted). */
    if( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )
    {
        /* Error, controller is not idle. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Set the start address of the IP read status transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );
    
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
    
    /* The TFF interrupt was enabled previously, in the calling function. */
    
    /* Send the Enter read status register mode command to memory. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, FLS_HYPERF_STATUS_REG_READ_ID_U8);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
        
    return eRetVal;
}

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendReadStatusRegIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;    
    VAR(uint8, AUTOMATIC) u8ExtRegWidth;
    VAR(uint8, AUTOMATIC) u8LatCycls;
        
    /* Check if controller is busy(BUSY bit asserted). */
    if( FLASH_E_OK != Fls_Qspi_CheckControllerIsIdle() )
    {
        /* Error, controller is not idle. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Set the start address of the IP read status transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );
    
    /* Clear reception flags, counters, prior to triggering the IP command. */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    /* Clear the errors (w1c). */
    REG_BIT_SET32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
      
    /* Set the Watermark level. */
    REG_RMW32( Fls_Qspi_u32HwUnitBaseAddr +  QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, 0U );   /* Expect 1 word(4byte entries) */
      
    /* Get the external memory register width,in bytes no., in order to determine the transfer length. */
    u8ExtRegWidth = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitRegisterWidth;
    /* Check "u8ExtRegWidth" is no bigger than 4 bytes, otherwise data might get corrupted when updating the "u32ExtRegValue". */
    if(4U < u8ExtRegWidth)
    {
        /* Error, the register width is bigger than the variable in which it has to be stored. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* Schedule the read of the status register. */
    Fls_Qspi_u8LLDBytesToRead = u8ExtRegWidth;
 
    u8LatCycls = (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiHyperflashLatCycls;
        
    /* Setup the LUT for the read of the status register. */
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,    FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,  
                                                                                FLS_LUT_INSTR_CMD_DDR,     FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_READ_MEM_LINEAR
                                                                               ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_DUMMY,       FLS_LUT_PAD_8_PADS, u8LatCycls,  
                                                                                FLS_LUT_INSTR_CADDR_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR
                                                                               ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,        FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_READ_DDR,    FLS_LUT_PAD_8_PADS, u8ExtRegWidth
                                                                               ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    /* The RBDF interrupt is enabled in the caller function. */

    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, u8ExtRegWidth, QSPI_PARALLEL_MODE_DISABLED);                   
     
    return eRetVal;
}

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendUnlock1Irq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
                   
    /* Set the start address of the IP write transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );
    
    /* Send the Unlock sequence 1. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xAAU);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    
    return eRetVal;
}

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendUnlock2Irq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
                   
    /* Set the start address of the IP write transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );

    /* Send the Unlock sequence 2. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_2_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0x55U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    
    return eRetVal;
}

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendWriteWordIdIrq(VAR(Fls_AddressType, AUTOMATIC) u32StartAddr)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
                   
    /* Set the start address of the IP write transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );

    /* Send the Write Program Word command ID. */
    eRetVal = Fls_Qspi_SetLUTHyperflashCmd(Fls_Qspi_u32ExtSectStartAddr + FLS_HYPERF_TYPE_1_ADDR_U32, FLS_LUT_SEQ_ID_15_U, 0xA0U);
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    
    return eRetVal;
}

static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_HyperSendWriteWordDataIrq
( 
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
                   
    /* Set the start address of the IP write transaction. */
    REG_WRITE32( Fls_Qspi_u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32StartAddr );

    /* Send the DATAx words. */
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U),    FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_ADDR_DDR,    FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_24BIT_ADDR,  
                                                                                FLS_LUT_INSTR_CMD_DDR,     FLS_LUT_PAD_8_PADS, FLS_LUT_HYPER_WRITE_MEM_WRAP
                                                                              ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+1U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_WRITE_DDR,       FLS_LUT_PAD_8_PADS, u8BytesToWrite,  
                                                                                FLS_LUT_INSTR_CADDR_DDR,   FLS_LUT_PAD_8_PADS, FLS_LUT_OPER_16BIT_ADDR
                                                                              )
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    eRetVal = Fls_Qspi_SetLUT((FLS_LUT_SEQ_ID_15_U*4U)+2U, FLS_QSPI_LUT_FORMAT( FLS_LUT_INSTR_STOP,        FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP,  
                                                                                FLS_LUT_INSTR_STOP,    FLS_LUT_HYPER_NOP, FLS_LUT_HYPER_NOP
                                                                               ) 
                             );
    if(FLASH_E_OK != eRetVal)
    {
        /* Error, the LUT setting failed due to timeout on lock/unlock. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return FLASH_E_FAILED;
    }
    
    Fls_Qspi_LaunchLUTCommand(FLS_LUT_SEQ_ID_15_U, 0U, QSPI_PARALLEL_MODE_DISABLED);
    
    return eRetVal;
}

/*
    The Fls_Qspi_IrqHyperEraseGetStatus1() function is called from the QSPI interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_ERASE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_GET_STATUS_1
        - It is processing a flash (write) enter get status mode job, on a Hyperflash QSPI sector, 
          which has the FLS_SECTOR_IRQ_MODE flag set.
    FLASH_IRQ_JOB_HYPER_GET_STATUS_1 state means that the first part of the Get status command
    (the enter status register read mode) has been successfully sent to the memory.
    In this state it is sent to the memory the second part of the status command, the actual read request.
    The next scheduled state is: FLASH_IRQ_JOB_HYPER_GET_STATUS_2
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseHyperGetStatus1(void)
{    
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
     
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Get status first command(Enter the read status register mode) has been sent to the memory previously and TFF interrupt is expected at the end of the IP transaction. */
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear and disable the TFF interrupt.*/
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);        /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* The first part of the Get status has been successfully sent to the memory, send the second part, the actual memory register read. */
                
        /* Prepare and enable the next interrupt(RBDF) for receiving the memory status register value. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */                 
        
        /* Schedule and launch the read of the status register, get memory status. */
        if(FLASH_E_OK != Fls_Qspi_HyperSendReadStatusRegIrq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }
                
        /* Schedule the next state, in which the second part of the Get status command will be sent to the memory, the actual status register read request. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_GET_STATUS_2; 
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }  
    
    return eRetVal;    
}

/*
    The Fls_Qspi_IrqHyperEraseGetStatus2() function is called from the QSPI interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_ERASE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_GET_STATUS_2
        - It is processing a flash (read) get status register job, on a Hyperflash QSPI sector, 
          which has the FLS_SECTOR_IRQ_MODE flag set.
    FLASH_IRQ_JOB_HYPER_GET_STATUS_2 state means that the second part of the Get status command
    (the read status register) has been successfully sent to the memory and the register content received.
    The next scheduled state could be:
        - 
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseHyperGetStatus2
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
     
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Status register read command has been sent to the memory previously and the RBDF interrupt is expected, in which the register value has to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        Fls_Qspi_u32StatusRegVal = 0UL;
        
        /* Read the expected number of bytes, the status register value, from the RX buffer.(Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_GetMemStatusIrq() function, when scheduling the read job) */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, (uint8 *)(&Fls_Qspi_u32StatusRegVal), NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Status register read successful, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
            
            /* Compute the busy state of the memory, based on the busy/idle bit and its value in the status register. */
            Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset); /* Clean all the bits from the read value of the status register, except the status bit. */
            if(Fls_Qspi_u32StatusRegVal == (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue) << (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset))
            {   
                *pbMemoryIsBusy = (boolean)TRUE; /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. bMemoryIsBusy = (boolean)( u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
            }
            else
            {
                *pbMemoryIsBusy = (boolean)FALSE;
            }
            /* Check the memory status. */
            if( (boolean)TRUE == *pbMemoryIsBusy ) /* If the memory is still busy */
            {   
                /* The erase operation is still in progress in the external memory. Schedule a new check operation for the same memory. */                    
                
                /* Prepare and enable the TFF interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
                
                /* Schedule and launch another read sequence(enter + read) of the status register. */                
                if(FLASH_E_OK != Fls_Qspi_HyperSendEnterStatusCmdIrq(Fls_Qspi_u32ExtSectStartAddr))
                {
                    /* Error during scheduling the read of status register.*/
                    eRetVal = FLASH_E_FAILED; 
                }
                
                /* Schedule a new status register read, starting from the first state, entering the read status mode. */
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_GET_STATUS_1;
            }
            else /* The external memory is idle. */
            {
                /*The entire memory is idle, so schedule the next job, if any, or mark the erase job as finished. */
                #if( FLS_ERASE_BLANK_CHECK == STD_ON )                        
                    /* Schedule the erase blank check(also clears the flag and enables the RBDF interrupt). */                   
                    if( FLASH_E_FAILED == Fls_Qspi_VerifyErase(Fls_Qspi_u32MemoryAddress, Fls_u32LLDNumberOfStepBack) )
                    {
                        /* Error, there was an error when attempting to schedule the job. */
                        eRetVal = FLASH_E_FAILED;                           
                    }  
                    /* else
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_BLANK_CHECK;  is set in the VerifyErase function.
                        Fls_eLLDJobResult = MEMIF_JOB_PENDING;       is set in the VerifyErase function.
                        The RBDF interrupt is enabled in the VerifyErase function. */
                #else
                    /* The erase job has finished.*/
                    Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_OK;
                #endif
            }
        }
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/
            
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;    
}



/*
    The Fls_Qspi_IrqWriteHyperUnlock1() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1
        - It is processing a flash 
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperUnlock1(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The unlock sequence 1 command has been sent to the memory previously and the TFF interrupt is expected, in which to launch unlock sequence 2 command.*/    
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear the interrupt flag and disable the TFF interrupt source. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* Prepare and enable the TFF interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
               
        /* Schedule the write unlock sequence 2 IRQ job. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_2;
                    
        /* Schedule and launch the unlock sequence 2. */
        if(FLASH_E_OK != Fls_Qspi_HyperSendUnlock2Irq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;
}

/*
    The Fls_Qspi_IrqWriteHyperUnlock2() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_2
        - It is processing a flash ...
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperUnlock2(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The unlock sequence 2 command has been sent to the memory previously and the TFF interrupt is expected, in which to launch word program id command.*/    
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear the interrupt flag and disable the TFF interrupt source. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* Prepare and enable the TFF interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
               
        /* Schedule the write word program id IRQ job. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_WRITE_WORD_ID;
                    
        /* Schedule and launch the write word program id command. */
        if(FLASH_E_OK != Fls_Qspi_HyperSendWriteWordIdIrq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }  
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }        
    
    return eRetVal;
}

/*
    The Fls_Qspi_IrqWriteHyperWordId() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_WRITE_WORD_ID
        - It is processing a flash ...
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperWordId(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The write word program id command has been sent to the memory previously and the TFF interrupt is expected, in which to launch write word program data command.*/    
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        VAR(uint8, AUTOMATIC) u8BytesToWrite = 0U;  /* Number of bytes to be written in this function iteration, up to a max of TXBuffer size. */
        VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
        VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL; 
        
        /* Clear the interrupt flag and disable the TFF interrupt source. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* Prepare and enable the TFF interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
               
        /* In this state, it means there is data to be written (0 < Fls_u32LLDRemainingDataToWrite),
           either pending directly from the Fls_Qspi_SectorWrite() if this is the first iteration,
           or coming from the FLASH_IRQ_JOB_HYPER_GET_STATUS_2 state, after a successful chunk write. */       
                
        /* Check if the total number of bytes to be written exceeds the TXBuffer size. */
        if( Fls_u32LLDRemainingDataToWrite > QSPI_TXBUFFER_MAX_SIZE_BYTES_U32 )  /* > 128 bytes, equivalent to: u32WordsToRead > 32U (4byte words) */
        {
            /* More than the maximum size of TX Buffer has to sent, use only 128bytes. */
            u8BytesToWrite = QSPI_TXBUFFER_MAX_SIZE_BYTES_U32; 
        }
        else
        {
            u8BytesToWrite = (uint8)Fls_u32LLDRemainingDataToWrite;
        } 
        
        /* Check that the last address to be programmed is in the same flash line. Any hyperflash write operation must not exceed the boundary of the current flash line(512bytes). */
        u32MemAddr1 = (Fls_Qspi_u32MemoryAddress/FLS_HYPERF_LINE_SIZE_U32);
        u32MemAddr2 = (((Fls_Qspi_u32MemoryAddress + u8BytesToWrite) - 1U)/FLS_HYPERF_LINE_SIZE_U32);
        if( u32MemAddr1 != u32MemAddr2 )
        {
            VAR(Fls_AddressType, AUTOMATIC) u32LineEndAddr = 0U;   /* The last byte address of the current flash line. */
            
            /* This write transaction is supposed to write more than it fits in the current flash line, so split it, by writing only until the end of the line. */
            /*u32LineEndAddr = Fls_Qspi_u32MemoryAddress - (Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32) + (FLS_HYPERF_LINE_SIZE_U32 - 1U);Split into multiple statements in order to avoid MISRA error. */
            u32LineEndAddr = Fls_Qspi_u32MemoryAddress;
            u32LineEndAddr -= Fls_Qspi_u32MemoryAddress % FLS_HYPERF_LINE_SIZE_U32;
            u32LineEndAddr += FLS_HYPERF_LINE_SIZE_U32 - 1U;
            u8BytesToWrite = (uint8)((u32LineEndAddr - Fls_Qspi_u32MemoryAddress) + 1U);
        } 
        /* else 
            All the bytes fit inside the same flash line. */
                    
        /* Clear TX flags, counters and load the specified number of bytes into TXBuffer. */
        Fls_Qspi_LoadTXBuffer(Fls_Qspi_u32BufferAddress, u8BytesToWrite);
        /* Update the source address pointer with the amount loaded above into TX Buffer*/
        Fls_Qspi_u32BufferAddress += u8BytesToWrite;                           
                            
        /* Schedule and launch the write word data command. */
        if(FLASH_E_OK != Fls_Qspi_HyperSendWriteWordDataIrq(Fls_Qspi_u32MemoryAddress, u8BytesToWrite))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }
        
        /* The Write command was launched above. */
            
        /* Update external write address. */
        Fls_Qspi_u32MemoryAddress += u8BytesToWrite;
        /* "Fls_Qspi_u32BufferAddress" is updated above, right after loading it into the TX Buffer. */
        /* Update the remaining number of bytes to be written. */
        Fls_u32LLDRemainingDataToWrite -= u8BytesToWrite;
         
        /* Schedule the write word program data IRQ job. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_WRITE_WORD_DATA; 
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }
    
    return eRetVal;

}

/*
    The Fls_Qspi_IrqWriteHyperWordData() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_WRITE_WORD_DATA
        - It is processing a flash ...
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperWordData
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
       
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The write word program data command has been sent to the memory previously and the TFF interrupt is expected, in which to launch get status command.*/    
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear the interrupt flag and disable the TFF interrupt source. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* The Write command has finished in the controller, but is probably still pending in the external memory, 
           so launch the check status command. */
               
        /* Prepare and enable the TFF interrupt. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
        
        if(FLASH_E_OK != Fls_Qspi_HyperSendEnterStatusCmdIrq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }        
        
        /* Reset the static status variables, because the next state is supposed to check and update them based on the external memory status. */
        *pbMemoryIsBusy    = (boolean)TRUE; 
            
        /* Schedule the next state, in which the actual status register read request will be sent to the memory. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_GET_STATUS_1;        
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }       
    
    return eRetVal;    
}

/*
    The Fls_Qspi_IrqWriteHyperGetStatus1() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_GET_STATUS_1
        - It is processing a flash ...
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperGetStatus1(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0UL;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0UL;
     
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Get status first command(Enter the read status register mode) has been sent to the memory previously and TFF interrupt is expected at the end of the IP transaction. */
    
    /* Check that the current interrupt was triggered by a Transaction Finished interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_TFF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_TFIE_U32 & u32EnableReg)) )
    {
        /* Clear and disable the TFF interrupt.*/
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);        /* Clear the interrupt flag(w1c). */
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Disable the Transaction Finished Interrupt. */
        
        /* The first part of the Get status has been successfully sent to the memory, send the second part, the actual memory register read. */
                
        /* Prepare and enable the next interrupt(RBDF) for receiving the memory status register value. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);       /* Clear the interrupt flag(w1c). */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);  /* Enable the Receive Buffer Drain Interrupt. */                 
        
        /* Schedule and launch the read of the status register, get memory status. */
        if(FLASH_E_OK != Fls_Qspi_HyperSendReadStatusRegIrq(Fls_Qspi_u32ExtSectStartAddr))
        {
            /* Error during scheduling the read of status register.*/
            eRetVal = FLASH_E_FAILED;                    
        }
                
        /* Schedule the next state, in which the second part of the Get status command will be sent to the memory, the actual status register read request. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_GET_STATUS_2; 
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }  
    
    return eRetVal;    
}

/*
    The Fls_Qspi_IrqWriteHyperGetStatus2() function is called from the QSPI_x interrupt routine.
    It is called when the QSPI interrupt is triggered and the driver is in the following state:
        - Fls_eJob       == FLS_JOB_WRITE, and
        - Fls_eLLDIrqJob == FLASH_IRQ_JOB_HYPER_GET_STATUS_2
        - It is processing a flash ...
*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperGetStatus2
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    VAR(uint32, AUTOMATIC) u32FlagsReg = 0U;
    VAR(uint32, AUTOMATIC) u32EnableReg = 0U;
     
    /* Get the interrupt type and status. */
    u32FlagsReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32);      /* Get the interrupt status register, the interrupt source. */
    u32EnableReg = REG_READ32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32);   /* Get the interrupt source enable register. */
    
    /* The Status register read command has been sent to the memory previously and the RBDF interrupt is expected, in which the register value has to be ready to read.*/    
    
    /* Check that the current interrupt was triggered by a RBDF interrupt, which also was not spurious. */
    if( (0U != (QSPI_FR_RBDF_U32 & u32FlagsReg)) && (0U != (QSPI_RSER_RBDIE_U32 & u32EnableReg)) )
    { 
        Fls_Qspi_u32StatusRegVal = 0UL;
        
        /* Read the expected number of bytes, the status register value, from the RX buffer.(Fls_Qspi_u8LLDBytesToRead is set previously in the Fls_Qspi_HyperSendReadStatusRegIrq() function, when scheduling the read job) */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        eRetVal = Fls_Qspi_ReadRXBuffer(Fls_Qspi_u8LLDBytesToRead, (uint8 *)(&Fls_Qspi_u32StatusRegVal), NULL_PTR);
        if(FLASH_E_OK == eRetVal)
        {
            /* Status register read successful, clear and disable the RBDF interrupt. */
            REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBDF_U32);           /* Clear the interrupt flag(w1c) - the RBDF flag has to be read only after reading the values from RX buffer, because clearing it will pop/discard a number of WMRK values. */
            REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_RBDIE_U32);    /* Disable the RBDF interrupt. */
            
            /* Compute the busy state of the memory, based on the busy/idle bit and its value in the status register. */
            Fls_Qspi_u32StatusRegVal = Fls_Qspi_u32StatusRegVal & (uint32)(1UL << (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset); /* Clean all the bits from the read value of the status register, except the status bit. */
            if(Fls_Qspi_u32StatusRegVal == (uint32)((uint32)((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitValue) << (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[Fls_Qspi_u8HwUnitCfgIndex].u8QspiUnitBusyBitPosOffset))
            {    
                *pbMemoryIsBusy = (boolean)TRUE; /* Check if the Busy bit from the status register has the value corresponding to the busy state of the memory. bMemoryIsBusy = (boolean)( u32StatusRegVal == (u8QspiUnitBusyBitValue << u8QspiUnitBusyBitPosOffset) ); */
            }
            else
            {
                *pbMemoryIsBusy = (boolean)FALSE;
            }
            /* Check the memory status. */
            if( (boolean)TRUE == *pbMemoryIsBusy ) /* If the memory is still busy */
            {   
                /* The write operation is still in progress in the external memory. Schedule a new check operation for the same memory. */                    
                
                /* Prepare and enable the TFF interrupt. */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32);/* Enable the Transaction Finished Interrupt. */
                
                /* Schedule and launch another read of the status register. */                
                if(FLASH_E_OK != Fls_Qspi_HyperSendEnterStatusCmdIrq(Fls_Qspi_u32ExtSectStartAddr))
                {
                    /* Error during scheduling the read of status register.*/
                    eRetVal = FLASH_E_FAILED; 
                }
                
                /* Schedule a new status register read, starting from the first state, entering the read status mode. */
                Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_GET_STATUS_1;
            }
            else /* The external memory is idle. */
            {
                /*The entire memory is idle, so schedule the next job, if any, or mark the write job as finished. */
                if(0UL < Fls_u32LLDRemainingDataToWrite)    /* If there is more data to be written */
                { 
                    /* More data to be written, so schedule a new write sequence, starting with unlock 1 sequence. */                       
                                        
                    /* Prepare and enable the TFF interrupt. */
                    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TFF_U32);    /* Clear the interrupt flag(w1c). */
                    REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, QSPI_RSER_TFIE_U32); /* Enable the Transaction Finished Interrupt. */
                    
                    /* Schedule the write unlock sequence 1 IRQ job. */
                    Fls_eLLDIrqJob = FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1;  
                    
                    /* Schedule and launch the first write unlock 1 sequence. */   
                    if( FLASH_E_OK != Fls_Qspi_HyperSendUnlock1Irq(Fls_Qspi_u32ExtSectStartAddr) )
                    {
                        /* Error, WriteEnable command has failed when attempting to schedule it. */            
                        eRetVal = FLASH_E_FAILED;
                    } 
                }
                else /* No more remaining data to write. */
                {
                    /* The programming part of the write job has finished. Schedule the next job(verify write), if any, or mark the write job as complete. */
                    
                    #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                        VAR(uint32, AUTOMATIC) u32MemAddr1 = 0UL;
                        VAR(uint32, AUTOMATIC) u32MemAddr2 = 0UL; 
                        
                        /* Schedule the write verify check, if enabled. */
                        u32MemAddr1 = Fls_Qspi_u32MemoryAddress - Fls_u32LLDNumberOfStepBack;
                        u32MemAddr2 = Fls_Qspi_u32BufferAddress - Fls_u32LLDNumberOfStepBack; 
                        if( FLASH_E_FAILED == Fls_Qspi_VerifyWrite( u32MemAddr1, u32MemAddr2, Fls_u32LLDNumberOfStepBack ) )
                        {
                            /* Error, there was an error when attempting to schedule the memory read. */
                            eRetVal = FLASH_E_FAILED;
                        } 
                        /* else
                            Fls_eLLDIrqJob = FLASH_IRQ_JOB_COMPARE;  is set in the VerifyErase function.
                            Fls_eLLDJobResult = MEMIF_JOB_PENDING;   is set in the VerifyErase function.
                            The RBDF interrupt is enabled in the VerifyErase function. */
                    #else
                        /*The write job has finished successfully.*/
                
                        /* For a Write Job in IRQ mode check if Fls_u32JobSectorIt should be increased */
                        if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]) ))
                        {
                            /* Move on to the next sector */
                            Fls_u32JobSectorIt++;
                        }
                        
                        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
                        Fls_eLLDJobResult = MEMIF_JOB_OK; 
                    #endif
                }
            } 
        } 
        /*else  (FLASH_E_OK != Fls_Qspi_ReadRXBuffer(...))
        {
            eRetVal = FLASH_E_FAILED.
            Error, there was a problem during the reading of the RX buffer.
        }*/
    }
    else /* Error, either the interrupt was spurious or another interrupt source has fired, other than the expected one. */
    {
        eRetVal = FLASH_E_FAILED;
    }        
    
    return eRetVal;
}

#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_ON) */
#endif /*#if(FLS_USE_INTERRUPTS == STD_ON)*/

FUNC(void, FLS_CODE) Fls_Qspi_SetSfarAddrExt  
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(Fls_AddressType, AUTOMATIC) u32Addr
)
{  
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Set the start address of the IP read transaction. */
    REG_WRITE32( u32HwUnitBaseAddr + QSPI_SFAR_OFFSET_U32, u32Addr );
}


/** 
* @brief        Load a LUT sequence
*
* @details      Load two instruction-operand pairs into a LUT sequence.
*               Intended to be used externally, by the application, inside the FLS QSPI callouts.
*
* @param[in]    u8LUTNumber The LUT number[0:63]. 64 available LUTs, the DIV4 LUTs are used for launching the
*                           LUT sequence command. (For ex. LUT0, LUT4, LUT8...LUT60. Launching a command 
*                           with LUT0 will send all the instruction-operand pairs from LUT0, LUT1, LUT2 and LUT3)
* @param[in]    LUTValue    The LUT Value, each consisting of two 16 bit instruction-operand pairs.
*                           Ex: LUT0 = 31(MSB) [INSTR1 | PAD1 | OPRND1] [INSTR0 | PAD0 | OPRND0] 0(LSB)
*
* @param[in]    u32Timeout  Timeout value used for the LUT lock/unlock sequence, in case the management is configured.
*
* @pre          The LUT which is manually populated should be empty, and not part of LUT sequence populated during
*               Init from the configuration. During Init, the LUT is populated from the bottom up, so if
*               the LUT was not filled with all 16 sequences, it can be assumed that the top LUT numbers are free.
*
* @post         LUT sequence no. 'u8LUTNumber' is populated with one or two instruction-operand pairs.
*
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Qspi_SetLUTExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber, 
    CONST(uint32, AUTOMATIC) LUTValue
)
{  
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0U;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Write the 32 bit LUT register */
    REG_WRITE32( u32HwUnitBaseAddr + QSPI_LUT_OFFSET_U32 + ((uint32)u8LUTNumber*4U), LUTValue);
        
    return (Std_ReturnType)E_OK;
}

/** 
* @brief        Qspi launch a LUT command based on the LUT number.
*
* @details      Launch a LUT command, sequence, in IP mode. Intended to be used externally, by the application, 
*               inside the FLS QSPI callouts.
*
* @param[in]    u8LUTNumber - number of the LUT sequence used in the command. upon this ID write, the external transaction is started.
*                           - Available LUT numbers are [0-63] but only DIV4 LUT numbers are valid for launching a LUT command sequence (LUT0, LUT4...LUT60).
* @param[in]    u32DataSize - data size(number of bytes) of the external transaction(used for read/write commands). When this value is 
*                             not zero, it overrides the transaction length set in the LUT command operands.
* @param[in]    u8ParEn     - parity enabled. if enabled, the external transaction is sent to both external parallel channels.
* @param[out]   none
*
* @return       E_OK        - command successfully launched.
*               E_NOT_OK    - the LUT number is not DIV4 aligned.
*
* @post         External transaction is triggered on the QSPI external lines.
*
*   
*/
FUNC(Std_ReturnType, FLS_CODE) Fls_Qspi_LaunchLUTNumberExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber,
    CONST(uint32, AUTOMATIC) u32DataSize,
    CONST(uint8, AUTOMATIC) u8ParEn
)
{  
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL; 
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Check LUT number is correctly aligned */
    if( 0U == (u8LUTNumber % 4U) ) 
    {  
        /* Set transfer size and launch LUT[u8LUTNumber] command, by writing the LUT sequence ID. 
           The IPCR register requires the LUTNumber to be DIV4 aligned, hence the division by 4 with the shift. */
        REG_WRITE32( u32HwUnitBaseAddr + QSPI_IPCR_OFFSET_U32,
                        ( ((uint32)u8LUTNumber >> 2UL) << QSPI_IPCR_SEQID_SHIFT_U32 ) | ( (uint32)u8ParEn << QSPI_IPCR_PAR_EN_SHIFT_U32 ) | ( u32DataSize << QSPI_IPCR_IDATSZ_SHIFT_U32 ) 
                   );   
    }
    else {
        /* Error, the LUT number is not aligned on a DIV4 basis. */
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    
    return u8RetVal;
}


FUNC(void, FLS_CODE) Fls_Qspi_ResetFlagsExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
        
    /* Clear the RX/TX Buffer and reception flags, counters. */
    REG_BIT_SET32( u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    REG_BIT_SET32( u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_TXF_U32 );
    /* Clear the error flags (w1c). */
    REG_BIT_SET32( u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_ILLINE_U32 | QSPI_FR_ABSEF_U32 | QSPI_FR_AITEF_U32 | QSPI_FR_AIBSEF_U32 | QSPI_FR_ABOF_U32 );
    REG_BIT_SET32( u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 | QSPI_FR_RBDF_U32);
    REG_BIT_SET32( u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_TBFF_U32 | QSPI_FR_TBUF_U32 | QSPI_FR_TFF_U32 );
}


FUNC(void, FLS_CODE) Fls_Qspi_SetRXWmrkExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, CONST(uint8, AUTOMATIC) u8BytesToRead)
{
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Set the WMRK value. */
    REG_RMW32( u32HwUnitBaseAddr + QSPI_RBCT_OFFSET_U32, QSPI_RBCT_WMRK_MASK_U32, (uint32)( (((uint32)u8BytesToRead + 3UL) / 4UL) - 1UL ) ); /* If no. of bytes is not divisible by 4, round to next integer to expect 1 more word. Ex: 5 bytes -> 2 words -> WMRK=1. */    
}


FUNC(Std_ReturnType, FLS_CODE) Fls_Qspi_CheckControllerIdleExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL;
    VAR(Std_ReturnType, AUTOMATIC) u8RetVal = (Std_ReturnType)E_OK;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Check if controller is busy(BUSY bit asserted). */
    if( 0U != (QSPI_SR_BUSY_U32 & REG_READ32(u32HwUnitBaseAddr + QSPI_SR_OFFSET_U32)) )
    {
        /* Error, controller is busy handling another transaction. */
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return u8RetVal;
}


FUNC(Std_ReturnType, FLS_CODE) Fls_Qspi_ReadRXBufferExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    CONST(uint8, AUTOMATIC) u8BytesToRead
)
{
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL;
    VAR(Fls_AddressType, AUTOMATIC) u32RXBuffBaseAddr = 0UL;        
    VAR(uint8, AUTOMATIC) u8Iter = 0U;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Check that at least the expected number of words were received, WMRK words level reached. */
    if( 0U ==  REG_BIT_GET32(u32HwUnitBaseAddr + QSPI_SR_OFFSET_U32, QSPI_SR_RXWE_U32) )  /* Poll RXWE bit. */
    {
        /* Error, the expected number of words were not received. */
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return (Std_ReturnType)E_NOT_OK;
    }
    
    /* Check errors from QSPI_FR. */
    if( 0U != REG_BIT_GET32( u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 ) )
    {
        /* Clear the errors (w1c). */
        REG_BIT_SET32( u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, QSPI_FR_RBOF_U32 | QSPI_FR_IUEF_U32 | QSPI_FR_IPAEF_U32 | QSPI_FR_IPIEF_U32 | QSPI_FR_IPGEF_U32 );
        /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
        return (Std_ReturnType)E_NOT_OK;
    }
    
    /* Read received data from RX Buffer. */
    
    /* Check the RXBuffer access mode: IP Bus or AHB Bus. */
    if( REG_BIT_GET32(u32HwUnitBaseAddr + QSPI_RBCT_OFFSET_U32, QSPI_RBCT_RXBRD_MASK_U32) )
    {
        /* The RXBRD bit is set, so the RX Buffer is configured to be read using the IP bus register interface. */
        u32RXBuffBaseAddr = u32HwUnitBaseAddr + QSPI_RBDR_OFFSET_U32;
    }
    else
    {
        /* The RXBRD bit is cleared, so the RX Buffer is configured to be read using the AHB bus register interface. */
        u32RXBuffBaseAddr = FLS_QSPI_ARDB_BASE_ADDR32[eHwUnitName];
        #if (STD_ON == FLS_SYNCRONIZE_CACHE)        
        /* Invalidate flash, before the flash read access */                                                         
        if((Std_ReturnType)E_OK != Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, u32RXBuffBaseAddr, (uint32)u8BytesToRead))
        {
            /* Cache operation invalidation unsuccessful. */
            /*  @violates @ref fls_qspi_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType)E_NOT_OK;
        }
    #endif /* MCAL_CACHE_RUNTIME_MNGMNT */
    }
    
    /* Read complete words - 32bits transfers */
    for( u8Iter=0U; u8Iter < (u8BytesToRead / 4U); u8Iter++)
    {   
        /* Read RX Buffer 32bit entry and copy it into the application read buffer. */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        (*((volatile uint32 *)p8DataPtr)) = REG_READ32( u32RXBuffBaseAddr + ((uint32)u8Iter*4UL) );
        /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
        p8DataPtr += 4U; /* Increment 4 bytes. */       
    }
    
    /* Check if in-complete entries should exist. */
    if( 0U !=  (u8BytesToRead % 4U) )
    {            
        VAR(uint8, AUTOMATIC) u8RxBuffLastEntry = 0U; 
        VAR(uint32, AUTOMATIC) u32RxIncompleteWord = 0UL;
        
        /* Store the last complete RX Buffer entry.*/
        u8RxBuffLastEntry = u8Iter; /* From above FOR loop, the u8RxBuffLastEntry points to the last incomplete entry, the one after the last previously read complete entry. */
        /* Read the last incomplete entry from the RXBuffer. */
        u32RxIncompleteWord = REG_READ32( u32RXBuffBaseAddr + ((uint32)u8RxBuffLastEntry*4UL) );
        /* Update destination data buffer. */
        for( u8Iter=0U; u8Iter < (u8BytesToRead % 4U); u8Iter++) /* Loop through remaining bytes. */
        {  
            *p8DataPtr = (uint8)( u32RxIncompleteWord >> (u8Iter*8U) );
            /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
            p8DataPtr += 1U;    /* Increment 1 bytes. */
        }            
    }              
    
    /* Clear the RX Buffer and reception flags, counters. */
    REG_BIT_SET32( u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_RXF_U32 );
    
    return (Std_ReturnType)E_OK;
}


FUNC( void, FLS_CODE ) Fls_Qspi_LoadTXBufferExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
)
{
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8LocalDataPtr;
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL;      
    VAR(uint8, AUTOMATIC) u8Iter = 0U;
    
    /* Get HW IP base address. */
    u32HwUnitBaseAddr = Fls_Qspi_GetHwUnitBaseAddr( eHwUnitName );
    
    /* Clear TX counters. */
    REG_BIT_SET32( u32HwUnitBaseAddr +  QSPI_MCR_OFFSET_U32, QSPI_MCR_CLR_TXF_U32 );
    
    /* Check if the minimum TX transaction size is fulfilled. */
    if(QSPI_TXBUFFER_MIN_SIZE_BYTES_U32 > u8BytesToWrite)
    {
        /* Less than the minimum TX transaction size is allowed, so pad the buffer with ERASE values. */

        VAR(uint8, AUTOMATIC) u8iter2 = 0U;
        
        for(u8iter2=0U; u8iter2 < QSPI_TXBUFFER_MIN_SIZE_BYTES_U32; u8iter2++)
        {
            if(0U < u8BytesToWrite)
            {
                Fls_Qspi_au8TmpDataPtr[u8iter2] = *p8DataPtr;
                /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
                p8DataPtr++;
                u8BytesToWrite--;
            }
            else
            {
                Fls_Qspi_au8TmpDataPtr[u8iter2] = (uint8)FLS_ERASED_VALUE;
            }
        }
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        p8LocalDataPtr = Fls_Qspi_au8TmpDataPtr;
        u8BytesToWrite = QSPI_TXBUFFER_MIN_SIZE_BYTES_U32;
    }
    else
    {
        p8LocalDataPtr = p8DataPtr;
    }
    
    /* Load the TX Buffer.*/
    for( u8Iter=0U; u8Iter < (u8BytesToWrite / 4U); u8Iter++)    /* Write complete words - 32bits transfers, first. */
    {            
        /* Write TX circular buffer 32bit entry. */
        /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
        REG_WRITE32( u32HwUnitBaseAddr + QSPI_TBDR_OFFSET_U32, *((volatile uint32 *)p8LocalDataPtr) ); /* Write 4 bytes. */
        /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
        p8LocalDataPtr += 4U;  /* 4 byte increment*/
    }
    /* Check if in-complete byte entries exist. */
    if( 0U !=  (u8BytesToWrite % 4U) )
    {
        VAR(uint32, AUTOMATIC) u32TxIncompleteWord = 0UL;
        
        /* Loop through remaining bytes. */
        for( u8Iter=0U; u8Iter < (u8BytesToWrite % 4U); u8Iter++) 
        {
            /* @violates @ref fls_qspi_c_REF_6 A cast should not be performed between a pointer to object type and a different pointer to object type. */
            u32TxIncompleteWord = (u32TxIncompleteWord << (u8Iter*8U)) | *((volatile uint8 *)p8LocalDataPtr); /* Write 1 byte. */
            /* @violates @ref fls_qspi_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic. */
            p8LocalDataPtr += 1U;    /* 1 byte increment. */
        }
        /* Write TX circular buffer incomplete last entry. */
        REG_WRITE32( u32HwUnitBaseAddr + QSPI_TBDR_OFFSET_U32, u32TxIncompleteWord );
    } 
}

FUNC( void, FLS_CODE ) Fls_Qspi_DisableModuleExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{ 
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL; 
        
    /* Get the QSPI IP hardware base address, used for register addressing. */
    u32HwUnitBaseAddr = Fls_QspiGetHwUnitBaseAddr(eHwUnitName);
        
    /* Disable QSPIx module before configuration - enter "Disabled mode" in order to be able to update QuadSPI_SMPR */
    REG_BIT_SET32(u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);        
}

FUNC( void, FLS_CODE ) Fls_Qspi_EnableModuleExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL; 
        
    /* Get the QSPI IP hardware base address, used for register addressing.*/
    u32HwUnitBaseAddr = Fls_QspiGetHwUnitBaseAddr(eHwUnitName);
        
    /* Enable QSPIx module after configuration */
    REG_BIT_CLEAR32(u32HwUnitBaseAddr + QSPI_MCR_OFFSET_U32, QSPI_MCR_MDIS_U32);
}

FUNC( void, FLS_CODE ) Fls_Qspi_SetCalibDelayValuesExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    CONST(uint8, AUTOMATIC) u8CoarseDelay, 
    CONST(uint8, AUTOMATIC) u8FineDelay
)
{
    VAR(Fls_AddressType, AUTOMATIC) u32HwUnitBaseAddr = 0UL; 
         
    /* Get the QSPI IP hardware base address, used for register addressing. */
    u32HwUnitBaseAddr = Fls_QspiGetHwUnitBaseAddr(eHwUnitName);
    
    Fls_Qspi_DisableModuleExt(eHwUnitName);
    
    /* Configure the coarse delay value. */

    (void)u8CoarseDelay;    /* The coarse delay parameter is not configurable on S32K148 SOC implementation. */
    
    /* Configure fine delay for external Flash A. */
    REG_RMW32( u32HwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_FINE_DLY_A_MASK_U32, 
               ((uint32)u8FineDelay << QSPI_SOCCR_FINE_DLY_A_SHIFT_U32) 
             );
    /* Configure fine delay for external Flash B. */
    REG_RMW32( u32HwUnitBaseAddr + QSPI_SOCCR_OFFSET_U32, QSPI_SOCCR_FINE_DLY_B_MASK_U32, 
               ((uint32)u8FineDelay << QSPI_SOCCR_FINE_DLY_B_SHIFT_U32) 
             );    
    
    Fls_Qspi_EnableModuleExt(eHwUnitName);
}

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_qspi_c_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_c_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

#endif /* #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */    
#endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    
#ifdef __cplusplus
}
#endif



