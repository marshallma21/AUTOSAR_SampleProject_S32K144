/**
*   @file    Fls_Qspi.h
*   @implements Fls_Qspi.h_Artifact  
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

#ifndef FLS_QSPI_H
#define FLS_QSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_qspi_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_qspi_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping 
*
* @section fls_qspi_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers.
*
* @section fls_qspi_h_REF_4
* Violates MISRA 2004 Required Rule 19.10,In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* Macro is used to call functions in underlying layers.
*
* @section fls_qspi_h_REF_5
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only
* one file. Those objects are declared in multi files to support multi IPVs
*
* @section fls_qspi_h_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed from within a
* single function. Variables may be used in upper layers
*
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
#include "Fls.h"
#include "Fls_Types.h"
#include "Fls_Qspi_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_QSPI_VENDOR_ID_H                    43
#define FLS_QSPI_MODULE_ID_H                    92
#define FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H     4
#define FLS_QSPI_AR_RELEASE_MINOR_VERSION_H     2
#define FLS_QSPI_AR_RELEASE_REVISION_VERSION_H  2
#define FLS_QSPI_SW_MAJOR_VERSION_H             1
#define FLS_QSPI_SW_MINOR_VERSION_H             0
#define FLS_QSPI_SW_PATCH_VERSION_H             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls.h header file are of the same vendor */
#if (FLS_QSPI_VENDOR_ID_H != FLS_VENDOR_ID)
    #error "Fls_Qspi.h and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_H != FLS_SW_MAJOR_VERSION) || \
     (FLS_QSPI_SW_MINOR_VERSION_H != FLS_SW_MINOR_VERSION) || \
     (FLS_QSPI_SW_PATCH_VERSION_H != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Qspi.h and Fls.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_H != FLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Qspi.h and Fls.h are different"
    #endif
#endif 


/* Check if current file and Fls_Types.h header file are of the same vendor */
#if (FLS_QSPI_VENDOR_ID_H != FLS_TYPES_VENDOR_ID)
    #error "Fls_Qspi.h and Fls_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Types.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_H != FLS_TYPES_SW_MAJOR_VERSION) || \
     (FLS_QSPI_SW_MINOR_VERSION_H != FLS_TYPES_SW_MINOR_VERSION) || \
     (FLS_QSPI_SW_PATCH_VERSION_H != FLS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Qspi.h and Fls_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H != FLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_H != FLS_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Qspi.h and Fls_Types.h are different"
    #endif
#endif 


/* Check if current file and Fls_Qspi_Types.h header file are of the same vendor */
#if (FLS_QSPI_VENDOR_ID_H != FLS_QSPI_TYPES_VENDOR_ID)
    #error "Fls_Qspi.h and Fls_Qspi_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Qspi_Types.h header file are of the same Software version */
#if ((FLS_QSPI_SW_MAJOR_VERSION_H != FLS_QSPI_TYPES_SW_MAJOR_VERSION) || \
     (FLS_QSPI_SW_MINOR_VERSION_H != FLS_QSPI_TYPES_SW_MINOR_VERSION) || \
     (FLS_QSPI_SW_PATCH_VERSION_H != FLS_QSPI_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Qspi.h and Fls_Qspi_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H != FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_QSPI_AR_RELEASE_MINOR_VERSION_H != FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Qspi.h and Fls_Qspi_Types.h are different"
    #endif
#endif 


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Get the base address for the QSPI hardware IP(register access) corresponding to the current channel: QSPI_0 or QSPI_1. */
/*
* @violates @ref fls_qspi_h_REF_3 A function should be used in preference to a function-like macro.
* @violates @ref fls_qspi_h_REF_4 In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##
*/
#define Fls_Qspi_GetHwUnitBaseAddr(eHwUnitName)     (FLS_QSPI_BASE_ADDR32[eHwUnitName])                                                                              
                                                                
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)

#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


/** 
* @brief Logical address of data block currently processed by Fls_MainFunction
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(Fls_AddressType, FLS_VAR) Fls_u32JobAddrIt;
/** 
* @brief Index of flash sector currently processed by a job
* @details Used by all types of job
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(volatile Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorIt;

/** 
* @brief Index of last flash sector by current job
* @details Used to check status of all external flash chips before start jobs
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR( Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorEnd;

/** 
    @brief Result of last flash hardware job
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_eLLDJobResult;
/** 
    @brief Type of current flash hardware job - used for asynchronous operating mode.
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(Fls_LLDJobType, FLS_VAR) Fls_eLLDJob;
/** 
* @brief Pointer to current flash module configuration set
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_pConfigPtr;
/** 
    @brief Number of bytes of data left to write.
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(volatile Fls_LengthType, AUTOMATIC) Fls_u32LLDRemainingDataToWrite;
/** 
    @brief Hardware unit IP base address (QSPI_0, QSPI_1)
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(Fls_AddressType, FLS_VAR) Fls_Qspi_u32HwUnitBaseAddr;
/** 
    @brief Internally memory mapped start address of external sector.
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(Fls_AddressType, FLS_VAR) Fls_Qspi_u32ExtSectStartAddr;

/** 
    @brief Type of current flash hardware job - used for irq operating mode.
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
/* @violates @ref fls_qspi_h_REF_6 Objects shall be defined at block scope if they are only accessed from within a
 * single function 
*/
extern VAR(volatile Fls_LLDIrqJobType, FLS_VAR) Fls_eLLDIrqJob;

/** 
* @brief Type of currently executed job (erase, write, read, or compare)
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(Fls_JobType, FLS_VAR) Fls_eJob;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/* The index of the HwUnit configuration structure. */
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(uint8, FLS_VAR) Fls_Qspi_u8HwUnitCfgIndex;

#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#if( ( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON ) || ( FLS_SYNCRONIZE_CACHE == STD_ON )) 
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
/* @violates @ref fls_qspi_h_REF_6 Objects shall be defined at block scope if they are only accessed from within a single function */
extern VAR(Fls_LengthType, AUTOMATIC) Fls_u32LLDNumberOfStepBack;
#endif

#if (FLS_TIMEOUT_HANDLING == STD_ON)
/**
    @brief Timeout counter used in both sync/async modes
*/
/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(uint32, FLS_VAR) Fls_u32LLDTimeout_Counter;
#endif

/* @violates @ref fls_qspi_h_REF_5 An external object or function shall be declared in one and only one file. */
extern VAR(volatile Fls_LengthType, AUTOMATIC) Fls_u32LLDRemainingDataToRead;

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONST_32
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

extern CONST(uint32, FLS_CONST) FLS_QSPI_BASE_ADDR32[FLS_QSPI_AVAILABLE_UNITS];

#define FLS_STOP_SEC_CONST_32
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       FUNCTIONS DECLARATIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

FUNC( void, FLS_CODE ) Fls_Qspi_Init( void );
FUNC( void, FLS_CODE ) Fls_Qspi_AbortSuspended(void);
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SectorRead
(   
    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataReadPtr,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) p8DataCmpPtr
);
FUNC( uint8, FLS_CODE ) Fls_Qspi_GetHwUnitCfgIndex( CONST( Fls_QspiUnitNameType, AUTOMATIC ) eHwUnitName );
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_SectorErase
( 
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST(Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif
    VAR( boolean, AUTOMATIC ) bAsynch 
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_GetExtSectStartAddr( VAR(Fls_QspiSectorChType, AUTOMATIC) eHwCh );

FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Qspi_SectorWrite
(
    CONST(Fls_AddressType, AUTOMATIC) u32StartAddr,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
);
FUNC( void, FLS_CODE ) Fls_Qspi_MainFunctionErase( void );
FUNC( void, FLS_CODE ) Fls_Qspi_MainFunctionWrite( void );
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
FUNC( void, FLS_CODE ) Fls_Qspi_MainFunctionEraseBlankCheck( void );
#endif 

#if (FLS_CANCEL_API == STD_ON )
FUNC(void, FLS_CODE)Fls_Qspi_Cancel(void);
#endif

/*** Interrupt routine context functions. ***/

FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseErase
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)    
    ,P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
#endif
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseGetStatus
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseGetStatusPar
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
);
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseBlankCheck(void);
#endif /* #if( FLS_ERASE_BLANK_CHECK == STD_ON ) */
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqReadRead(void);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqReadCompare(void);
#if( FLS_BLANK_CHECK_API == STD_ON )
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqReadBlankCheck(void);
#endif /*#if( FLS_BLANK_CHECK_API == STD_ON )*/
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteBlankCheck(void);
#endif /*#if( FLS_WRITE_BLANK_CHECK == STD_ON )*/
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteWriteEnable
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy,
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteWrite
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy,
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteGetStatus
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteGetStatusPar
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusyPar
);
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteCompare(void);
#endif /*#if( FLS_WRITE_VERIFY_CHECK == STD_ON )*/

#if(FLS_QSPI_HYPERFLASH_MODE == STD_ON)
#if(FLS_USE_INTERRUPTS == STD_ON)
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseHyperGetStatus1(void);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqEraseHyperGetStatus2
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperUnlock1(void);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperUnlock2(void);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperWordId(void);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperWordData
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperGetStatus1(void);
FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Qspi_IrqWriteHyperGetStatus2
(
    P2VAR(boolean, AUTOMATIC, FLS_APPL_DATA) pbMemoryIsBusy
);
#endif /* FLS_USE_INTERRUPTS == STD_ON */
#endif /* FLS_QSPI_HYPERFLASH_MODE == STD_ON */
/* External callout functions. */
FUNC(void, FLS_CODE) Fls_Qspi_SetSfarAddrExt  
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(Fls_AddressType, AUTOMATIC) u32Addr
);
FUNC( Std_ReturnType, FLS_CODE ) Fls_Qspi_SetLUTExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber, 
    CONST(uint32, AUTOMATIC) LUTValue
);
FUNC(Std_ReturnType, FLS_CODE) Fls_Qspi_LaunchLUTNumberExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber,
    CONST(uint32, AUTOMATIC) u32DataSize,
    CONST(uint8, AUTOMATIC) u8ParEn
);
FUNC(void, FLS_CODE) Fls_Qspi_ResetFlagsExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
FUNC(void, FLS_CODE) Fls_Qspi_SetRXWmrkExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    CONST(uint8, AUTOMATIC) u8BytesToRead
);
FUNC(Std_ReturnType, FLS_CODE) Fls_Qspi_CheckControllerIdleExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
FUNC(Std_ReturnType, FLS_CODE) Fls_Qspi_ReadRXBufferExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    CONST(uint8, AUTOMATIC) u8BytesToRead
);
FUNC( void, FLS_CODE ) Fls_Qspi_LoadTXBufferExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
);
FUNC( void, FLS_CODE ) Fls_Qspi_DisableModuleExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
FUNC( void, FLS_CODE ) Fls_Qspi_EnableModuleExt(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
FUNC( void, FLS_CODE ) Fls_Qspi_SetCalibDelayValuesExt
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    CONST(uint8, AUTOMATIC) u8CoarseDelay, 
    CONST(uint8, AUTOMATIC) u8FineDelay
);


#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_qspi_h_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_qspi_h_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

#endif /* #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */    
#endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */

#ifdef __cplusplus
}
#endif

#endif /* FLS_QSPI_H */

/** @}*/
