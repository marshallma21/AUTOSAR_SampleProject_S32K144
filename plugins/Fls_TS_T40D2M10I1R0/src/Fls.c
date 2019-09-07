/**
*   @file    Fls.c
*   @implements Fls.c_Artifact   
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Flash driver source code.
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
* @section fls_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section fls_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
* This violation is because of complex statement
*
* @section fls_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section fls_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section fls_c_REF_6
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_7
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement
*
* @section fls_c_REF_8
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* Function may be called in user callout functions.
*
* @section fls_c_REF_9
* Violates MISRA 2004 Required Rule 12.2, The value of an expression shall be the same under any order of 
* evaluation that the standard permits.
* This violation is because of complex statement
*
* @section fls_c_REF_10
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_c_REF_11
* Violates MISRA 2004 Required Rule 8.12,
* When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
* For the purpose of copying from ROM to RAM the compiled access code opocode is treated as uint32 array.
* All start, end and size parameters are defined by the linker file and imported into C module as external
* variables.  
* 
* @section fls_c_REF_12
* Violates MISRA 2004 Required Rule 11.1, Conversions involving function pointers must be to/from integral types
* Conversion is made for special purpose - copying the compiled function opcode from ROM to RAM.
* 
* @section fls_c_REF_13
* Violates MISRA 2004 Required Rule 8.7, could define variable at block scope
* The symbol is defined by the linker file and imported into C module as external variable. 
*
* @section fls_c_REF_14 
* Violates MISRA 2004 Required Rule 17.2, Relational or subtract operator applied to pointers
* The pointers point to the same area in RAM where the AC opcode is copied from ROM.
*
* @section fls_c_REF_15
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating 
* contents in that address.
*
* @section fls_c_REF_16
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* Variables may be used in LLD layers.
*
* @section fls_c_REF_17
* Violates MISRA 2004 Required Rule 19.11, All macro identifers in preprocessor directives shall be defned before use
* All macro identifers in preprocessor directives shall be defned before use, except in #ifdef and #ifndef 
* preprocessor directives and the defned() operator.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, 
* The names of standard library macros, objects and functions shall not be reused. 
* The driver needs to use defines starting with letter E.
*
* 
*/

/* Compiler warning fls_c_REF_CW_01: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly. 
   Sizes of the pointers and integral types for all the supported platforms/compilers are well known 
   and the volatile keyword is not needed when using the pointer value as a flash address counter, 
   as the pointer value is not updated in the DSI interrupt context or by other hardware means.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
#include "Fls_Flash.h"
#endif
#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)
#include "Fls_Qspi.h"
#endif

#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */

#include "SchM_Fls.h"
#include "StdRegMacros.h"

#if (STD_ON == FLS_SYNCRONIZE_CACHE) 
#include "Mcl.h"
#endif /* FLS_SYNCRONIZE_CACHE */

#include "Fls_IPW.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_C                      43
/*
* @violates @ref fls_c_REF_10 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref fls_c_REF_10 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_AR_RELEASE_MINOR_VERSION_C       2
/*
* @violates @ref fls_c_REF_10 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_AR_RELEASE_REVISION_VERSION_C    2
#define FLS_SW_MAJOR_VERSION_C               1
#define FLS_SW_MINOR_VERSION_C               0
#define FLS_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls.c and Fls.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
         (FLS_AR_RELEASE_REVISION_VERSION_C    != FLS_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Fls.h are different"
    #endif
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls.c and Fls.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and StdRegMacros.h are different"
    #endif
#endif


#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Det.h are different"
    #endif
#endif
#endif

#if(STD_ON == FLS_QSPI_FLASH_AVAILABLE)
/* Check if current file and Fls_Qspi.h header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_QSPI_VENDOR_ID_H)
    #error "Fls.c and Fls_Qspi.h have different vendor ids"
#endif
/* Check if current file and Fls_Qspi.h header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_QSPI_SW_MAJOR_VERSION_H) || \
     (FLS_SW_MINOR_VERSION_C != FLS_QSPI_SW_MINOR_VERSION_H) || \
     (FLS_SW_PATCH_VERSION_C != FLS_QSPI_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Fls.c and Fls_Qspi.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != FLS_QSPI_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != FLS_QSPI_AR_RELEASE_MINOR_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Fls.c and Fls_Qspi.h are different"
    #endif
#endif 
#endif

#if(STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
/* Check if current file and Fls_Flash.h header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_FLASH_VENDOR_ID)
    #error "Fls.c and Fls_Flash.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash.h header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_FLASH_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_C != FLS_FLASH_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_C != FLS_FLASH_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls.c and Fls_Flash.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != FLS_FLASH_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != FLS_FLASH_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Fls_Flash.h are different"
    #endif
#endif 
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcl header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Mcl.h are different"
    #endif
#endif
#endif /* FLS_SYNCRONIZE_CACHE */


/* Check if current file and Fls_IPW.h header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_IPW_VENDOR_ID_H)
    #error "Fls.c and Fls_IPW.h have different vendor ids"
#endif
/* Check if current file and Fls_IPW.h header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_IPW_SW_MAJOR_VERSION_H) || \
     (FLS_SW_MINOR_VERSION_C != FLS_IPW_SW_MINOR_VERSION_H) || \
     (FLS_SW_PATCH_VERSION_C != FLS_IPW_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Fls.c and Fls_IPW.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != FLS_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != FLS_IPW_AR_RELEASE_MINOR_VERSION_H) \
        )
        #error "AutoSar Version Numbers of Fls.c and Fls_IPW.h are different"
    #endif
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/    
/*
* @violates @ref fls_c_REF_10 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


/*
* @violates @ref fls_c_REF_10 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
* @brief Logical address of data block currently processed by Fls_MainFunction
*/
VAR(Fls_AddressType, FLS_VAR) Fls_u32JobAddrIt = 0UL;
/** 
* @brief Index of flash sector currently processed by a job
* @details Used by all types of job
*/
VAR(volatile Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorIt = 0UL;

/** 
* @brief Type of currently executed job (erase, write, read, or compare)
*/
/*
* @violates @ref fls_c_REF_16 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
* This variable maybe used in LLD layer
*/
VAR(Fls_JobType, FLS_VAR) Fls_eJob = FLS_JOB_ERASE;
/** 
* @brief Index of last flash sector by current job
* @details Used to check status of all external flash chips before start jobs
* or is the last sector in Erease job
*/
/*
* @violates @ref fls_c_REF_16 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
* This variable maybe used in LLD layer
*/
VAR( Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorEnd = 0UL;
/** 
    @brief Result of last flash hardware job
*/
VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_eLLDJobResult = MEMIF_JOB_OK;
/** 
    @brief Type of current flash hardware job - used for asynchronous operating mode.
*/
VAR(Fls_LLDJobType, FLS_VAR) Fls_eLLDJob = FLASH_JOB_NONE;
/** 
    @brief Type of current flash hardware job - used for interrupt operating mode.
*/
/*
* @violates @ref fls_c_REF_16 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
* This variable maybe used in LLD layer
*/
VAR(volatile Fls_LLDIrqJobType, FLS_VAR) Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
/** 
* @brief Pointer to current flash module configuration set
*/
P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_pConfigPtr = NULL_PTR;
/** 
    @brief Number of bytes of data left to write.
*/
VAR(volatile Fls_LengthType, AUTOMATIC) Fls_u32LLDRemainingDataToWrite=0UL;
#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)
/** 
    @brief Number of bytes of data left to read.
*/
/*
* @violates @ref fls_c_REF_16 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
* This variable maybe used in LLD layer
*/
VAR(volatile Fls_LengthType, AUTOMATIC) Fls_u32LLDRemainingDataToRead = 0UL;
#endif
#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#if( ( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON ) || ( FLS_SYNCRONIZE_CACHE == STD_ON ) ) 
/*
* @violates @ref fls_c_REF_16 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
* This variable maybe used in LLD layer
*/
VAR(Fls_LengthType, AUTOMATIC) Fls_u32LLDNumberOfStepBack = 0UL;
#endif


#if (FLS_TIMEOUT_HANDLING == STD_ON)
/**
    @brief Timeout counter used in both sync/async modes
*/
VAR(uint32, FLS_VAR) Fls_u32LLDTimeout_Counter = 0UL;
#endif

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/** 
    @brief fill pattern used to clear write and erase access code in RAM
*/
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_AC_UNLOAD_PATTERN 0xffffffffU
#endif

/** 
    @brief Calculate total flash size in bytes
*/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_TOTAL_SIZE ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_pConfigPtr->u32SectorCount - 1U] + 1U)
#endif

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
* @brief Maximum number of bytes to read or compare in one cycle of Fls_MainFunction
*/
static VAR(Fls_LengthType, FLS_VAR) Fls_u32MaxRead = 0UL;
/** 
* @brief Maximum number of bytes to write in one cycle of Fls_MainFunction
*/
static VAR(Fls_LengthType, FLS_VAR) Fls_u32MaxWrite = 0UL;
/** 
* @brief Last logical address to be processed by a job
*/
static VAR(Fls_AddressType, FLS_VAR) Fls_u32JobAddrEnd = 0UL;
/** 
* @brief Result of last flash module job
* @implements Fls_eJobResult_Object
*/
static VAR(MemIf_JobResultType, FLS_VAR) Fls_eJobResult = MEMIF_JOB_OK;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
* @brief Pointer to current position in source data buffer
* @details Used by both write and compare jobs
*/
static P2CONST( uint8, FLS_VAR, FLS_APPL_CONST ) Fls_pJobDataSrcPtr = NULL_PTR;
/** 
* @brief Pointer to current position in target data buffer
* @details Used only by read job
*/
static P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) Fls_pJobDataDestPtr = NULL_PTR;
/** 
* @brief Indicates that new job has been accepted
* @details Used by all types of job
*/
static VAR(uint8, FLS_VAR) Fls_u8JobStart = 0U;

#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief Pointer to current flash module configuration set
* @implements Fls_u32AccCRCremainder_Object
*/
static VAR(uint32, FLS_VAR) Fls_u32AccCRCremainder = 0U;

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_START_SEC_CONST_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#ifndef _CODEWARRIOR_C_S32K14x_
/* Start Position and Size of erase access code in flash */
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACEraseRomStart[];
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACEraseSize[];

/* Start Position and Size of write access code in flash */
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACWriteRomStart[];
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACWriteSize[];
#endif

#ifdef _CODEWARRIOR_C_S32K14x_
/* Start Position and Size of erase access code in flash */
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) __SEG_START_acfls_code_rom[];
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) __SEG_SIZE_acfls_code_rom[];

/* Start Position and Size of write access code in flash */
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) __SEG_START_acfls_code_rom[];
/* @violates @ref fls_c_REF_11 For fixed array size. */
/* @violates @ref fls_c_REF_13 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) __SEG_SIZE_acfls_code_rom[];



/* Start Position and Size of erase access code in flash */
#define Fls_ACEraseRomStart        (__SEG_START_acfls_code_rom)
#define Fls_ACEraseSize            (((uint32)(__SEG_SIZE_acfls_code_rom)+3U)/4U)

/* Start Position and Size of write access code in flash */
#define Fls_ACWriteRomStart        (__SEG_START_acfls_code_rom)
#define Fls_ACWriteSize            (((uint32)(__SEG_SIZE_acfls_code_rom)+3U)/4U)
#endif


#define FLS_STOP_SEC_CONST_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
static FUNC(Fls_SectorIndexType, FLS_CODE) Fls_GetSectorIndexByAddr
 (CONST (Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr
( CONST(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex );
#if( FLS_DEV_ERROR_DETECT == STD_ON )
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageEndAligned
(
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress
);
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
static FUNC(boolean, FLS_CODE) Fls_IsAddrWordAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
#endif
#endif

#endif /* #if( FLS_DEV_ERROR_DETECT == STD_ON ) */

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
static FUNC( void, FLS_CODE ) Fls_LoadAc
( CONST( Fls_JobType, AUTOMATIC) eJob );
static FUNC( void, FLS_CODE ) Fls_UnloadAc
( CONST( Fls_JobType, AUTOMATIC) eJob );
#endif
static FUNC(void, FLS_CODE) Fls_AccumulateCRC
( VAR(uint32, AUTOMATIC) u32InputData );
static FUNC(void, FLS_CODE) Fls_ResetCRC ( void );
static FUNC(uint32, FLS_CODE) Fls_FinalizeCRC ( void );
static FUNC( void, FLS_CODE ) Fls_UpdateCRCreminder ( VAR(Fls_CrcDataSizeType, AUTOMATIC) eDataSize );
static FUNC( Fls_CrcType, FLS_CODE )  Fls_CalcCfgCRC( void );
static FUNC( MemIf_JobResultType, FLS_CODE )  Fls_DoJobErase( void );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcMaxTransferAddrEnd
( CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength
( CONST( Fls_AddressType, AUTOMATIC) u32MaxTransferEndAddr );
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobRead
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobWrite
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
#if( FLS_COMPARE_API == STD_ON )
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobCompare
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
#endif
#if (FLS_BLANK_CHECK_API == STD_ON)
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobBlankCheck
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
#endif /* FLS_BLANK_CHECK_API == STD_ON */
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_DoJobDataTransfer
( 
    CONST( Fls_JobType, AUTOMATIC) eJob,
    CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer 
);
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_LLDGetJobResult( void );
static FUNC( void, FLS_CODE ) Fls_LLDClrJobResult( void );


#if( (FLS_USE_INTERRUPTS == STD_ON) && (FLS_TIMEOUT_HANDLING == STD_ON) )
static FUNC( void, FLS_CODE ) Fls_CheckIrqTimeout(void);
#endif
#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief        Maps u32TargetAddress to sector index
*
* @details      Calculate index of logical sector u32TargetAddress belongs to
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       Zero based index of logical sector
* @retval       0 .. (Fls_pConfigPtr->u32SectorCount - 1)
*
* @pre          The module must be initialized
* @pre          u32TargetAddress must be in configured flash boundary
*    
*/
static FUNC(Fls_SectorIndexType, FLS_CODE) Fls_GetSectorIndexByAddr
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32SectorIndex = 0UL;

    for( u32SectorIndex = 0U; u32SectorIndex < Fls_pConfigPtr->u32SectorCount;
         u32SectorIndex++ 
       )
    {
        if( u32TargetAddress <= (*(Fls_pConfigPtr->paSectorEndAddr))[u32SectorIndex] )
        {
            /* u32TargetAddress belongs to sector with index u32SectorIndex */
            break;
        }
        else
        {
            /* Check next sector */
        }
    }
    
    return u32SectorIndex;
}

/** 
* @brief        Return start address of given sector
*
* @details      Calculate start address (in linear space) of logical sector
*               specified by the u32SectorIndex parameter
*
* @param[in]    u32SectorIndex Index of logical sector
*
* @return       Start address of u32SectorIndex sector
* @retval       0 .. (FLS_TOTAL_SIZE - 1)
*
* @pre          The module must be initialized
* @pre          u32SectorIndex must be in range 0 .. (Fls_pConfigPtr->u32SectorCount - 1)
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr
( CONST(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32TargetAddress = 0U;
    
    if( 0U != u32SectorIndex ) 
    {
        u32TargetAddress = (*(Fls_pConfigPtr->paSectorEndAddr))[u32SectorIndex - 1U] + 1U;
    }
    else
    {
        /* First sector starts with address 0 */
    }

    return u32TargetAddress;
}

/** 
* @brief        Check whether u32TargetAddress is page aligned
*
* @details      Check whether u32TargetAddress is integer multiple of Flash Page Size
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is page aligned
* @retval       FALSE u32TargetAddress is not page aligned
*    
*/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned(
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    
    /* Aligned to Double Word or Word depending if CODE/DATA Flash or DFO */
    if(0U == (u32TargetAddress % (*(Fls_pConfigPtr->paSectorPageSize))[Fls_GetSectorIndexByAddr(u32TargetAddress)])) 
    {   
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not page aligned */
    }

    return( bRetVal );
}

/** 
* @brief        Check whether u32TargetAddress is page start aligned
*
* @details      Check whether u32TargetAddress is in range and aligned to first 
*               byte of flash page
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to start of the page
* @retval       FALSE u32TargetAddress is not in range or aligned to start of the page
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;    
    
    if(( u32TargetAddress < (Fls_AddressType)FLS_TOTAL_SIZE ) &&
        ( (boolean)TRUE == Fls_IsAddrPageAligned( u32TargetAddress ) ) \
      )
    {
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or aligned to start of the page */
    }
    
    return( bRetVal );    
}

/** 
* @brief        Check whether u32TargetAddress is page start aligned
*
* @details      Check whether u32Length is in range and aligned to 
*               flash page
*
* @param[in]    u32TargetAddress Target address in flash memory
* @param[in]    u32Length size of current write
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to end of the page
* @retval       FALSE u32TargetAddress is not in range or aligned to end of the page
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageEndAligned
(
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress   
)
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    VAR(Fls_LengthType, AUTOMATIC) u32SectorOffset = 0UL;
    
    /* Calculate offset in the last sector of current operation */
    u32SectorOffset = u32TargetAddress - Fls_GetSectorStartAddr(Fls_GetSectorIndexByAddr(u32TargetAddress));
    
    if(((u32TargetAddress - 1U) < (Fls_AddressType)FLS_TOTAL_SIZE ) &&
       (0U == (u32SectorOffset % (*(Fls_pConfigPtr->paSectorPageSize))[Fls_GetSectorIndexByAddr(u32TargetAddress)]))
      ) 
    {    
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or aligned to end of the page */
    }
    
    return( bRetVal );
}


/** 
* @brief        Check whether u32TargetAddress is sector start aligned
*
* @details      Check whether u32TargetAddress is in range and aligned to first 
*               byte of flash sector
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to start of the sector
* @retval       FALSE u32TargetAddress is not in range or not aligned to 
*               start of the sector
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned
( 
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress 
)
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    
    /*
    * @violates @ref fls_c_REF_7 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( ( u32TargetAddress < FLS_TOTAL_SIZE ) && 
        ( u32TargetAddress == Fls_GetSectorStartAddr( Fls_GetSectorIndexByAddr( u32TargetAddress )))
      )
    {
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or 
            not aligned to start of the sector */
    }
    
    return bRetVal;
}



/** 
* @brief        Check whether u32TargetAddress is sector end aligned
*
* @details      Check whether u32TargetAddress is in range and aligned to last 
*               byte of flash sector
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to end of the sector
* @retval       FALSE u32TargetAddress is not in range or not aligned to 
*               end of the sector
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32SectorIndex = 0UL;
    
    u32SectorIndex = Fls_GetSectorIndexByAddr( u32TargetAddress );
    
    /*
    * @violates @ref fls_c_REF_7 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if(( u32TargetAddress < FLS_TOTAL_SIZE ) &&
        ( u32TargetAddress == (*(Fls_pConfigPtr->paSectorEndAddr))[u32SectorIndex] )
      )
    {    
        bRetVal =  (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or not aligned to end of the sector */
    }
    
    return bRetVal;
}


#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
/** 
* @brief        Check whether u32TargetAddress is word aligned
*
* @details      If QSPI is available and QSPI sectors are configured and
*               if the WordAddresable option is set, check if the address
*               is word aligned. For hyperflash memories only even addresses
*               are allowed.
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is word aligned
* @retval       FALSE u32TargetAddress is not word aligned
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrWordAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;    
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR(uint8, AUTOMATIC) u8HwUnitCfgIndex = 0U;
    
    u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32TargetAddress );
    /* Get the HW IP configuration index inside the configuration structure (in order to select the configuration structure associated with this sector s HW channel). */    
    u8HwUnitCfgIndex = Fls_IPW_GetHwUnitCfgIndex( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitSectorAssign))[u32TmpJobSectorIt] );
    
    /*
    * @violates @ref fls_c_REF_7 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( ((boolean)TRUE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8HwUnitCfgIndex].bQspiUnitWordAddressable) 
        && (0U != (u32TargetAddress % 2U)) ) 
    {
       /* The WordAddresable option is set but the address is not word aligned. */ 
       bRetVal = (boolean)FALSE;
    }
    else
    {
        /* Either WordAddresable option is not set or the address is word aligned. */
        bRetVal =  (boolean)TRUE;
    }
        
    return bRetVal;
}
#endif /* #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */     
#endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */


#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
/** 
* @brief        Load access code to RAM
*
* @details      Load erase or write access code to statically 
*               pre-configured location in RAM
*
* @param[in]    eJob Type of access code to load. Can be either 
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized
*
* @implements     Fls_LoadAc_Activity
*    
*/
static FUNC( void, FLS_CODE ) Fls_LoadAc
( CONST( Fls_JobType, AUTOMATIC) eJob )
{
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pRomPtr = NULL_PTR;
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pRomEndPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pRamPtr = NULL_PTR;

    switch( eJob ) 
    {
        case FLS_JOB_ERASE:
            pRomPtr = Fls_ACEraseRomStart;
            /*
            * @violates @ref fls_c_REF_7 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * 
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types
            * 
            * @violates @ref fls_c_REF_5 A cast should not be performed between a pointer type 
            * and an integral type             
            */
            pRomEndPtr = pRomPtr + (uint32)(Fls_ACEraseSize);
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            * 
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types                        
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acErasePtr);
            break;
        
        case FLS_JOB_WRITE:
            pRomPtr = Fls_ACWriteRomStart;
            /*
            * @violates @ref fls_c_REF_7 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * 
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types    
            *
            * @violates @ref fls_c_REF_5 A cast should not be performed between a pointer type 
            * and an integral type             
            */
            pRomEndPtr = pRomPtr + (uint32)(Fls_ACWriteSize);
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            *
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types                         
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acWritePtr);
            break;
        
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }

    /* Copy erase or write access code to RAM */
    /* pRomEndPtr is dynamically calculated and might not be multiple of 4U */
    /*
    * @violates @ref fls_c_REF_7 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_14 Relational or subtract operator applied to pointers 
    * @violates @ref fls_c_REF_15 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_5 A cast should not be performed between a pointer type 
    * and an integral type    
    */
    for(; (uint32)pRomPtr < (uint32)pRomEndPtr; pRomPtr++)
    {
        *pRamPtr = *pRomPtr;
        /*
        * @violates @ref fls_c_REF_7 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pRamPtr++;
    }
}


/** 
* @brief        Unload access code to RAM
*
* @details      Erase write or erase access code from statically 
*               pre-configured location in RAM. Fills the RAM location
*               with FLS_AC_UNLOAD_PATTERN
*
* @param[in]    eJob Type of access code to unload. Can be either 
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized
*
* @implements     Fls_UnloadAc_Activity
*    
*/
static FUNC( void, FLS_CODE ) Fls_UnloadAc
( CONST( Fls_JobType, AUTOMATIC) eJob )
{
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pRamPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pRamEndPtr = NULL_PTR;
    
    switch( eJob ) 
    {
        case FLS_JOB_ERASE:
        
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types                         
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acErasePtr);
            /*
            * @violates @ref fls_c_REF_7 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types     
            * @violates @ref fls_c_REF_5 A cast should not be performed between a pointer type 
            * and an integral type             
            */
            pRamEndPtr = pRamPtr + (uint32)(Fls_ACEraseSize);
            break;
        
        case FLS_JOB_WRITE:
        
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types                         
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acWritePtr);
            /*
            * @violates @ref fls_c_REF_7 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_12 Conversions involving function 
            * pointers must be to/from integral types 
            * @violates @ref fls_c_REF_5 A cast should not be performed between a pointer type 
            * and an integral type            
            */
            pRamEndPtr = pRamPtr + (uint32)(Fls_ACWriteSize);
            break;
        
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }    

    /* Unload (erase) write or erase access code from RAM */
    /*
    * @violates @ref fls_c_REF_7 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_14 Relational or subtract operator applied to pointers
    * @violates @ref fls_c_REF_15 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_5 A cast should not be performed between a pointer type 
    * and an integral type      
    */
    for(; (uint32)pRamPtr < (uint32)pRamEndPtr; pRamPtr++)
    {
        *pRamPtr = FLS_AC_UNLOAD_PATTERN;
    }    
}
#endif /* FLS_AC_LOAD_ON_JOB_START */

/** 
* @brief        Erase one complete flash sector
*
* @details      Call low level flash driver service 
*               to erase one complete flash sector specified by the Fls_u32JobSectorIt
*               internal job variable
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK erase operation succeeded and there 
*               is no more sectors to erase
* @retval       MEMIF_JOB_PENDING erase operation succeeded and there 
*               is still one or more sectors to erase
* @retval       MEMIF_JOB_FAILED operation failed due to hardware error
*
* @param[in]    Job Type of access code to unload. Can be either 
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized, the Fls_u32JobSectorIt internal
*               job variable must contain index of logical sector to be erased, and
*               Fls_u32JobSectorEnd must contain index of last logical sector to be erased
*
* @post         increments the Fls_u32JobSectorIt internal job variable
*
*
* @implements     Fls_DoJobErase_Activity
*    
*/
static FUNC( MemIf_JobResultType, FLS_CODE )  Fls_DoJobErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;
    VAR(uint32, AUTOMATIC) u32Datastore = 0UL;
    
    /* 
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour 
    * @violates @ref fls_c_REF_9 The value of an expression shall be the same under any order of 
    * evaluation that the standard permits.
    */
    if( Fls_u32JobSectorIt > Fls_u32JobSectorEnd )
    {
        /* No more sectors to erase */
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
        VAR( Fls_LengthType, AUTOMATIC ) u32PhysicalSectorSize = 0UL;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
        VAR( boolean, AUTOMATIC ) bAsynch = (boolean)0;
        VAR( Fls_LLDReturnType, AUTOMATIC ) eLldRetVal = FLASH_E_OK;

        /* Get the Fls_IPW_SectorErase function operation mode */
        if( (*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & 
            (FLS_SECTOR_ERASE_ASYNCH | FLS_SECTOR_IRQ_MODE)
          )
        {   
            /* The sector write is performed in an asynchronous manner, it is ASYNC or IRQ mode. */
            bAsynch = (boolean)TRUE;
        }
        else
        { 
            /* The sector write is SYNC, neither ASYNC or IRQ mode. */
            bAsynch = (boolean)FALSE;
        }
    
    #if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
        /* Calculate size of the physical sector */
        u32Datastore = (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt];
        u32PhysicalSectorSize = ( u32Datastore - Fls_GetSectorStartAddr( Fls_u32JobSectorIt ) ) 
                                    + (Fls_LengthType)1UL;
    
        eLldRetVal = Fls_IPW_SectorErase( u32PhysicalSectorSize, bAsynch );
    #else
        eLldRetVal = Fls_IPW_SectorErase( bAsynch );
    #endif
        
        /* 
         * @violates @ref fls_c_REF_4 No reliance shall be placed on
         * undefined or unspecified behaviour 
         * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
         * @violates @ref fls_c_REF_9 The value of an expression shall be the same under any order of 
         * evaluation that the standard permits.
         */
        if(( FLASH_E_OK == eLldRetVal ) && ( Fls_u32JobSectorIt == Fls_u32JobSectorEnd ))
        {
            eRetVal = MEMIF_JOB_OK;
        }
        else if( FLASH_E_FAILED == eLldRetVal )
        {
            eRetVal = MEMIF_JOB_FAILED;
                                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
                            
        }
        else
        {
            /* The erase operation is either:
                1. For ASYNCHRONOUS and IRQ operation: pending (FLASH_E_PENDING) in hardware, or
                2. For SYNCHRONOUS operation: finished (FLASH_E_OK) and there are more sectors to erase.
            
                1. If the operation is Async or Irq erase, than the sector is increased in 
                   Fls_IPW_LLDMainFunction()(for Async erase) or in the IRQ routine(for Irq mode).
                   when completing the job.
                2. If the operation is Sync erase, than the sector is increased below because the job is complete.
            */
            u32Datastore = (*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt];
            if( ( 0U == ( u32Datastore & FLS_SECTOR_ERASE_ASYNCH) )
                && ( 0U == ( u32Datastore & FLS_SECTOR_IRQ_MODE) ) )
            {
                Fls_u32JobSectorIt++;
            }
        }
    }
    
    return( eRetVal );
}


/** 
* @brief       Calculate last logical address to read, write, or compare 
*              from in current cycle of Fls_MainFunction
*
* @details      Calculate last logical address of Fls_DoJobDataTransfer
*               loop to limit number of bytes transferred to/from flash memory
*               in one cycle of Fls_MainFunction
*
* @return       Fls_AddressType
* @retval       0 .. (FLS_TOTAL_SIZE - 1)
*
* @param[in]    u32MaxTransfer Maximum number of bytes to read, write, or compare 
*               in current cycle of Fls_MainFunction
*
* @pre          Fls_u32JobAddrIt must contain current, and Fls_u32JobAddrEnd last
*               logical address of current job
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcMaxTransferAddrEnd
( CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32MaxTransferEndAddr = Fls_u32JobAddrEnd;
    
    /* Adjust the u32MaxTransferEndAddr address to transfer only
        the u32MaxTransfer bytes in one Fls_MainFunction() call */
    if( u32MaxTransferEndAddr >= (Fls_u32JobAddrIt + u32MaxTransfer) )
    {
        u32MaxTransferEndAddr = (Fls_u32JobAddrIt + u32MaxTransfer) - 1U;
    } 
    else
    {
        /* No adjustment is necessary. Job will finish in this cycle
            of Fls_MainFunction */
    }
    
    return( u32MaxTransferEndAddr );
}

/** 
* @brief       Calculate sector offset to read, write, or compare 
*              from current sector
*
* @details      Calculate sector offset in bytes for low-level driver
*               services
*
* @return       Fls_AddressType
* @retval      0 .. (FLS_SECTOR_SIZE - 1)
*
* @pre         The module must be initialized, Fls_u32JobSectorIt internal job
*              variable must contain index of current logical sector, 
*              Fls_u32JobAddrIt must contain current logical address
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void )
{    
    VAR( Fls_AddressType, AUTOMATIC ) u32SectorAddrStart = 0UL;
        
    /* Get first address of Fls_u32JobSectorIt sector */
    u32SectorAddrStart = Fls_GetSectorStartAddr( Fls_u32JobSectorIt );

    /* Calculate the sector offset */
    return( Fls_u32JobAddrIt - u32SectorAddrStart );    
}


/** 
* @brief       Calculate number of bytes to read, write, or compare 
*              from current sector
*
* @details      Calculate sector transfer length for low-level driver
*               services
*
* @param[in]    u32MaxTransferEndAddr Last address to read, write, 
*               or compare data from in this cycle of Fls_MainFunction
*        
* @return      Fls_AddressType
* @retval      0 .. (FLS_SECTOR_SIZE - 1)
*
* @pre        The module must be initialized, Fls_u32JobSectorIt internal job
*             variable must contain index of current logical sector, 
*             Fls_u32JobAddrIt must contain current logical address, and
*             u32MaxTransferEndAddr must be >= Fls_u32JobAddrIt and lie within 
*             the specified lower and upper flash address boundaries
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength
( CONST( Fls_AddressType, AUTOMATIC) u32MaxTransferEndAddr )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32SectorEndAddr = 0UL;
        
    /* Get last address of Fls_u32JobSectorIt sector */
    u32SectorEndAddr = (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt];
        
    /* Adjust the u32SectorEndAddr according to max number of bytes to transfer
        during one cycle of Fls_MainFunction */
    if( u32SectorEndAddr > u32MaxTransferEndAddr )
    {
        u32SectorEndAddr = u32MaxTransferEndAddr;
    }
    else
    {
        /* No adjustment is necessary. There is more sectors 
            to transfer */
    }

    /* Calculate number of bytes to read from the sector */
    return(( u32SectorEndAddr - Fls_u32JobAddrIt ) + 1U );
}

/** 
* @brief       Read up to one physical flash sector
*
* @details      Call low level flash driver service to read given number of bytes
*               from given sector offset.
*
* @param[in]    SectorOffset Flash sector offset to read data from
* @param[in]    Length Number of bytes to read
*        
* @return       Fls_LLDReturnType
* @retval       FLASH_E_OK read operation succeeded
* @retval       FLASH_E_FAILED read operation failed due to a hardware error
*
* @pre          The module must be initialized, the Fls_u32JobSectorIt internal job
*               variable must contain valid index of logical sector to read, 
*               u32SectorOffset and u32Length must be in physical    sector boundary,
*               Fls_pJobDataDestPtr internal job variable must point to data read buffer
*
* @implements     Fls_DoJobRead_Activity
*    
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobRead
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    
    eRetVal = Fls_IPW_SectorRead( u32SectorOffset, u32Length, Fls_pJobDataDestPtr );
    
    /* Do physical sector read */
    if( FLASH_E_FAILED == eRetVal )
    {
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_READ_FAILED);
        #endif
        }

    return( eRetVal );
}
 
/** 
* @brief        Write up to one physical flash sector
*
* @details      Call low level flash driver service to write given number of bytes
*               at given sector offset
*
* @param[in]    u32SectorOffset Flash sector offset to write data from
* @param[in]    Length Number of bytes to read
*        
* @return       Fls_LLDReturnType
* @retval       FLASH_E_OK write operation succeeded
* @retval       FLASH_E_FAILED write operation failed due to a hardware error
*
* @pre          The module must be initialized, the Fls_u32JobSectorIt internal job
*               variable must contain valid index of logical sector to write, 
*               u32SectorOffset and u32Length must be in physical sector boundary and page
*               aligned, Fls_pJobDataSrcPtr internal job variable must point to data
                write buffer
*
* @implements     Fls_DoJobWrite_Activity
*    
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobWrite
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    VAR( boolean, AUTOMATIC ) bAsynch = (boolean)0;

    /* Get the Fls_IPW_SectorWrite function operation mode */
    if( (*(Fls_pConfigPtr->paSectorFlags))[Fls_u32JobSectorIt] & 
        (FLS_PAGE_WRITE_ASYNCH | FLS_SECTOR_IRQ_MODE)
      )
    {   
        /* The sector write is performed in an asynchronous manner, it is ASYNC or IRQ mode. */
        bAsynch = (boolean)TRUE;
    }
    else
    { 
        /* The sector write is SYNC, neither ASYNC or IRQ mode. */
        bAsynch = (boolean)FALSE;
    }  
    
    eRetVal = Fls_IPW_SectorWrite( u32SectorOffset, u32Length, Fls_pJobDataSrcPtr, bAsynch );
    
    if( FLASH_E_FAILED == eRetVal )
    {
                                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
                        }    
                                      
    return( eRetVal );
}

#if( FLS_COMPARE_API == STD_ON )
/** 
    @brief Compare up to one physical flash sector with data buffer
    @details Call low level flash driver service to compare given
        number of bytes at given sector offset with data buffer
    
    @param[in] u32SectorOffset Flash sector offset to compare data with
    @param[in] u32Length Number of bytes to compare
    
    @return Fls_LLDReturnType
    @retval FLASH_E_OK compare operation succeeded
    @retval FLASH_E_FAILED compare operation failed due to a hardware error
    @retval FLASH_E_BLOCK_INCONSISTENT compare operation failed 
        due to data mismatch
    
    @pre The module must be initialized, the Fls_u32JobSectorIt internal job
        variable must contain valid index of logical sector to compare, 
        u32SectorOffset and u32Length must be in physical sector boundary, 
        Fls_pJobDataSrcPtr internal job variable must point to 
        compare data buffer

    @implements Fls_DoJobCompare_Activity
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobCompare
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;    

    eRetVal = Fls_IPW_SectorCompare( u32SectorOffset, u32Length, Fls_pJobDataSrcPtr );

    if( FLASH_E_FAILED == eRetVal )
    {
                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_COMPARE_FAILED);
        #endif
        }
    
    return( eRetVal );
}
#endif /* FLS_COMPARE_API == STD_ON */  
  
#if (FLS_BLANK_CHECK_API == STD_ON)
/** 
*   @brief          Compare up to one physical flash sector with pre-defined erased value 
*   @details        Call low level flash driver service to compare given
*                   number of bytes at given sector offset with pre-defined erased value 
*    
*   @param[in]      u32SectorOffset Flash sector offset to verify memory area has been erased
*   @param[in]      u32Length Number of bytes to verify
*    
*   @return         Fls_LLDReturnType
*   @retval         FLASH_E_OK blank check operation succeeded
*   @retval         FLASH_E_FAILED blank check operation failed due to a hardware error
*   @retval         FLASH_E_BLOCK_INCONSISTENT blank check operation failed 
*                   due to data mismatch
*    
*   @pre            The module must be initialized, the Fls_u32JobSectorIt internal job
*                   variable must contain valid index of logical sector to blank check, 
*                   u32SectorOffset and u32Length must be in physical sector boundary
*
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_DoJobBlankCheck
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;

    eRetVal = Fls_IPW_SectorCompare( u32SectorOffset, u32Length, NULL_PTR );

    if( FLASH_E_FAILED == eRetVal )
    {
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_COMPARE_FAILED);
        #endif
        } 
    /*else
    {
         physical sector blank check succeeded or
            FLASH_E_BLOCK_INCONSISTENT 
    }*/
    
    return( eRetVal );
}
#endif /* FLS_BLANK_CHECK_API == STD_ON */

/** 
    @brief Read, write, or compare flash data
    @details Call Fls_DoJobRead, Fls_DoJobWrite, or Fls_DoJobCompare
        functions to read, write, or compare flash data. The functions
        ensures that only pre-configured maximum number of bytes is
        read, written, or compared during one cycle of 
        the Fls_MainFunction call
    
    @return MemIf_JobResultType
    @retval MEMIF_JOB_OK read, write, or compare operation succeeded and there 
        is no more data to read, write, or compare
    @retval MEMIF_JOB_PENDING read, write, or compare operation succeeded
        and there is still some data to read, write, or compare
    @retval MEMIF_JOB_FAILED read, write, or compare operation failed due
        to a hardware error
    @retval MEMIF_BLOCK_INCONSISTENT Compared data from a flash compare
        eJob are not equal
    
    @pre The module must be initialized, the Fls_u32JobSectorIt internal
        eJob variable must contain index of logical sector to read, write, 
        or compare, the Fls_u32JobAddrIt must contain logical address to read, 
        write or compare, and Fls_u32JobAddrEnd must contain last address to read,
        write or compare.

    @post Updates the Fls_u32JobSectorIt, Fls_pJobDataSrcPtr, Fls_pJobDataDestPtr,
        and Fls_u32JobAddrIt internal eJob variables
        
    @implements Fls_DoJobDataTransfer_Activity
*/
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_DoJobDataTransfer
( 
    CONST( Fls_JobType, AUTOMATIC) eJob,
    CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer 
)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;
    
    /* No more data to write */
    if( Fls_u32JobAddrIt > Fls_u32JobAddrEnd )
    {
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
        VAR( Fls_AddressType, AUTOMATIC ) u32MaxTransferAddrEnd = 0UL;
        VAR( Fls_LLDReturnType, AUTOMATIC ) eTransferRetVal = FLASH_E_FAILED;
        
        /* Last address to transfer data to/from in this call of 
            the Fls_MainFunction() functions */
        u32MaxTransferAddrEnd = Fls_CalcMaxTransferAddrEnd( u32MaxTransfer );

        /* Transfer sector by sector until the u32MaxTransferAddrEnd address is reached
            or error is detected */
        do
        {
            VAR( Fls_AddressType, AUTOMATIC ) u32SectorTransferOffset = 0UL;
            VAR( Fls_AddressType, AUTOMATIC ) u32SectorTransferLength = 0UL;

            /* Calculate offset and length of the sector data transfer */
            u32SectorTransferOffset = Fls_CalcSectorTransferOffset();
            u32SectorTransferLength = Fls_CalcSectorTransferLength( u32MaxTransferAddrEnd );

            /* Update the Fls_JobAddressIt iterator. (It is not modified in the below functions, but it has to 
                be updated here because it is checked in the IRQ mode, which might happen right in the function call.) */
            Fls_u32JobAddrIt += u32SectorTransferLength;
            
            /* Call Low-level driver to transfer data to/from
                physical flash device */
            switch( eJob )
            {
                case FLS_JOB_WRITE:
                    eTransferRetVal =  Fls_DoJobWrite( u32SectorTransferOffset,
                                                      u32SectorTransferLength 
                                                    );                        
                    /* Update the source data pointer for next write */
                    /*
                    * @violates @ref fls_c_REF_7 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_pJobDataSrcPtr += u32SectorTransferLength;                    
                    break;
                    
                case FLS_JOB_READ:
                    eTransferRetVal =  Fls_DoJobRead( u32SectorTransferOffset,
                                                     u32SectorTransferLength 
                                                   );
                        
                    /* Update the destination data pointer for next read */
                    /*
                    * @violates @ref fls_c_REF_7 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_pJobDataDestPtr += u32SectorTransferLength;                    
                    break;

#if( FLS_COMPARE_API == STD_ON )
                case FLS_JOB_COMPARE:
                    eTransferRetVal =  Fls_DoJobCompare( u32SectorTransferOffset,
                                                        u32SectorTransferLength 
                                                      );
                    /* Update the source data pointer for next compare */
                    /*
                    * @violates @ref fls_c_REF_7 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_pJobDataSrcPtr += u32SectorTransferLength;                                
                    break;
#endif /* FLS_COMPARE_API == STD_ON */
                
#if( FLS_BLANK_CHECK_API == STD_ON )                   
                case FLS_JOB_BLANK_CHECK:
                    eTransferRetVal =  Fls_DoJobBlankCheck(  u32SectorTransferOffset,
                                                            u32SectorTransferLength 
                                                         );
                    break;
#endif /* FLS_BLANK_CHECK_API == STD_ON */
                /*case FLS_JOB_ERASE:
         If the case corresponds to FLS_JOB_ERASE the switch case will  break 
                    break;
                */    
                default:
                    /* Do nothing - should not happen in Fully Trusted Environment;
                       "default" clause added to fulfill MISRA Rule 15.3 */
                    break;
            }            

            /* Fls_u32JobSectorIt should be increased here only for SYNC mode and for read/compare job
               For a Write Job in ASYNC mode it should be set by Fls_IPW_LLDMainFunction just before 
               completing the Job */
            /* Fls_u32JobSectorIt should be increased here for:
                    READ jobs        - SYNC mode.
                    COMPARE jobs     - SYNC mode.
                    BLANK CHECK jobs - SYNC mode.
                    WRITE jobs       - SYNC mode.
               Fls_u32JobSectorIt will not be increased here for: 
                    ERASE jobs       - SYNC, ASYNC or IRQ   (Fls_u32JobSectorIt will be set at the end of Fls_DoJobErase for SYNC mode, at the end of Fls_IPW_LLDMainFunction for ASYNC mode and at the end of the interrupt routine for IRQ mode)
                    READ jobs        - IRQ mode.            (Fls_u32JobSectorIt will be set at the end of the interrupt routine)
                    COMPARE jobs     - IRQ mode.            (Fls_u32JobSectorIt will be set at the end of the interrupt routine)
                    BLANK CHECK jobs - IRQ mode.            (Fls_u32JobSectorIt will be set at the end of the interrupt routine)
                    WRITE jobs       - ASYNC or IRQ mode.   (Fls_u32JobSectorIt will be set at the end of Fls_IPW_LLDMainFunction, if batch is finished)
            */   
            if( FLASH_E_OK == eTransferRetVal ) /* If the previous(SYNC job) has finished successfully */
            {                
                if( (Fls_u32JobAddrIt > (*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;        
                }
            
            }
        }
        while(( Fls_u32JobAddrIt <= u32MaxTransferAddrEnd ) && 
              ( FLASH_E_OK == eTransferRetVal )
             );
             
             
        if( FLASH_E_FAILED == eTransferRetVal )
        {
            eRetVal = MEMIF_JOB_FAILED;
        } 
        else if( FLASH_E_BLOCK_INCONSISTENT == eTransferRetVal )
        {
            /* compare job only */
            eRetVal = MEMIF_BLOCK_INCONSISTENT;
        }     
        else if(( Fls_u32JobAddrIt > Fls_u32JobAddrEnd ) && 
                ( FLASH_E_OK == eTransferRetVal )
               )
        {
            /* All desired job data has been successfully transferred */
            eRetVal = MEMIF_JOB_OK;
        }
        else
        {
            /* The write operation is either pending (FLASH_E_PENDING) 
            in hardware in case of asynchronous operation or 
            finished (FLASH_E_OK) in case of synchronous operation 
            and there is more pages to write */
        }
    }
    
    return( eRetVal );
}

/** 
* @brief        Function to handle cumulative CRC calculation over input data.
*
* @details      Handles cumulative CRC calculation over input 32-bit data, . 
*
* @param[in]    inputData ... data to be CRC-ed
*
* @return       void
* @retval       None.
*
* @pre          Fls_ResetCRC() was executed before the first call of 
*               Fls_AccumulateCRC().
*
*    
*/
static FUNC(void, FLS_CODE) Fls_AccumulateCRC
(
  VAR(uint32, AUTOMATIC) u32InputData
)
{     

    if (0xFFFFU < u32InputData)
    {
        /* preparation for accumulation of higher 16 bits of the u32InputData */
        Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 16U) | (u32InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
        Fls_UpdateCRCreminder(FLS_CRC_16_BITS);                    
    }

    if (0xFFU < u32InputData)
    {
        /* preparation for accumulation of lower 16 bits of the u32InputData */
        Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 16U) | (u32InputData & 0x0000FFFFU);    
        /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
        Fls_UpdateCRCreminder(FLS_CRC_16_BITS);    
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the u32InputData */
        Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 8U) | u32InputData;    
        /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
        Fls_UpdateCRCreminder(FLS_CRC_8_BITS);        
    }

    return;
} 


/** 
* @brief        Function to reset CRC calculation.
*
* @details      Resets accumulated Fls_u32AccCRCremainder. 
*
* @param[in]    void
*
* @return       void
* @retval       None.
*
* @pre          None.  
*
*    
*/
static FUNC(void, FLS_CODE) Fls_ResetCRC ( void )
{
    Fls_u32AccCRCremainder = 0U;
}

/** 
* @brief        Function to finalize CRC calculation.
*
* @details      Finalizes accumulated CRC computation and resturns the final 
*               CRC checksum. 
*
* @param[in]    void
*
* @return       uint32 
* @retval       The final CRC checksum in the lower 16 bits.                
*
* @pre          Fls_AccumulateCRC() was executed at least once before 
*               calling Fls_FinalizeCRC().
*    
*/
static FUNC(uint32, FLS_CODE) Fls_FinalizeCRC ( void )
{
    /* add the final 0x0000 to the remainder */
    Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */         
    Fls_UpdateCRCreminder(FLS_CRC_16_BITS);
    
    return (Fls_u32AccCRCremainder);
}

/** 
* @brief        Function to perfom CRC calculation over input 32-bit data.
*
* @details      Process 32-bit data to 16-bit reminder. 
*
* @param[in]    accDataPtr ... ptr to data to be processed
*
* @return       void 
* @retval       None.                
*
* @pre          Can be called only from Fls_AccumulateCRC().
*    
*/

static FUNC( void, FLS_CODE ) Fls_UpdateCRCreminder 
( 
    VAR(Fls_CrcDataSizeType, AUTOMATIC) eDataSize 
)
{
    VAR(uint32, AUTOMATIC) u32CrcPolynomSft; 
    VAR(uint32, AUTOMATIC) u32LeadingOne;
    VAR(uint32, AUTOMATIC) u32AccDataLoc;
    VAR(uint32, AUTOMATIC) u32LeadingOneInitial;
    
    switch (eDataSize)
    {
        case FLS_CRC_8_BITS:
            u32CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            u32LeadingOneInitial = 0x10000U << 7U;        
            break;
        case FLS_CRC_16_BITS:
        default:
            u32CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            u32LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    u32AccDataLoc = Fls_u32AccCRCremainder;
    
    /* CRC computation */
    for (u32LeadingOne = u32LeadingOneInitial; u32LeadingOne >= 0x00010000U; u32LeadingOne >>= 1U)
    {
        if (0U != (u32AccDataLoc & u32LeadingOne))
        {
            u32AccDataLoc ^= u32CrcPolynomSft;   
        }
        u32CrcPolynomSft >>= 1U;
    }
    
    /* copy back to static variable */ 
    Fls_u32AccCRCremainder = u32AccDataLoc;
    
    return;    
}

/** 
* @brief        Calculates CRC over Fls configuration.
*
* @details      Calculates CRC over selected items of Fls configuration set 
*               pointed to by ConfigPtr. 
*
* @param[in]    ConfigPtr        Pointer to flash driver configuration set.
*
* @return       uint32
* @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
*
* @pre          Fls_pConfigPtr must not be properly initialized.
*    
*/

static FUNC( Fls_CrcType, FLS_CODE )  Fls_CalcCfgCRC( void )
{
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32SectorIndex;
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)    
    VAR( uint8, AUTOMATIC ) u8IterAhb = 0U;
    VAR( uint8, AUTOMATIC ) u8IterUnits = 0U;
    VAR( uint8, AUTOMATIC ) u8IterLUTs = 0U;
    VAR( uint8, AUTOMATIC ) u8IterInstrOpers = 0U;
#endif /*#ifdef (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)*/
    
    /* Reset the accumulated CRC value */
    Fls_ResetCRC();
    
    /* Accumulate the rest of the params (common for all sectors within a config set) */
    /* CRC - Accumulate eDefaultMode */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->eDefaultMode);
    /* CRC - Accumulate u32MaxReadFastMode */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxReadFastMode );
    /* CRC - Accumulate u32MaxReadNormalMode */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxReadNormalMode);
    /* CRC - Accumulate u32MaxWriteFastMode */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxWriteFastMode);
    /* CRC - Accumulate u32MaxWriteNormalMode */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxWriteNormalMode);        
    /* CRC - Accumulate u32SectorCount */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32SectorCount);
        
    /* Iterate through the sector-dependent params */
    for( u32SectorIndex = 0U; u32SectorIndex < Fls_pConfigPtr->u32SectorCount; u32SectorIndex++ )
    {
        /* CRC - Accumulate paSectorEndAddr */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->paSectorEndAddr))[u32SectorIndex]);
            /* CRC - Accumulate pSectorList */
        if(NULL_PTR != (*(Fls_pConfigPtr->pSectorList))[u32SectorIndex])
        {   /* Accumulate Sector index for internal flash sectors */
            Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*((*(Fls_pConfigPtr->pSectorList))[u32SectorIndex])).u32SectorId)); 
        }
            /* CRC - Accumulate paSectorFlags */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->paSectorFlags))[u32SectorIndex]);  
        /* CRC - Accumulate paSectorProgSize */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->paSectorProgSize))[u32SectorIndex]);
        /* CRC - Accumulate paSectorUnlock */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->paSectorUnlock))[u32SectorIndex]);
#if (FLS_QSPI_FLASH_AVAILABLE == STD_ON)    
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)
        /* CRC - Accumulate paHwCh */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->paHwCh))[u32SectorIndex]);
        /* CRC - Accumulate paSectorHwAddress */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->paSectorHwAddress))[u32SectorIndex]);
#endif /*#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)*/    
#endif /*#if (FLS_QSPI_FLASH_AVAILABLE == STD_ON)*/    
    }
    
#if (FLS_QSPI_FLASH_AVAILABLE == STD_ON)    
#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)    
    /* Iterate through the external QSPI HW units related params. */
    for(u8IterUnits = 0U; u8IterUnits < Fls_pConfigPtr->pFlsQspiCfgConfig->u8QspiUnitsCount; u8IterUnits++)
    {
        /* CRC - Accumulate eHwUnitName */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eHwUnitName);
        /* CRC - Accumulate eQspiUnitReadMode */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitReadMode);
        /* CRC - Accumulate eQspiUnitSamplingEdge */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitSamplingEdge);
        /* CRC - Accumulate eQspiUnitSamplingDly */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitSamplingDly);
        /* CRC - Accumulate u8QspiUnitSamplingPoint */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitSamplingPoint);
        /* CRC - Accumulate bQspiUnitDqsLatencyEn */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).bQspiUnitDqsLatencyEn);
            /* CRC - Accumulate u8QspiUnitFineDlyA */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitFineDlyA);
        /* CRC - Accumulate u8QspiUnitFineDlyB */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitFineDlyB);
        /* CRC - Accumulate eQspiUnitTdh */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitTdh);
        /* CRC - Accumulate u8QspiUnitTcsh */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitTcsh);
        /* CRC - Accumulate u8QspiUnitTcss */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitTcss);
        /* CRC - Accumulate eQspiUnitEndian */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitEndian);
        /* CRC - Accumulate eQspiUnitReadBufferMode */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitReadBufferMode);
        /* CRC - Accumulate eQspiUnitRxBufferAccessMode */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).eQspiUnitRxBufferAccessMode);
        
        if( FLS_AHB_READ_MODE == (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].eQspiUnitReadBufferMode )
        {
            /* Loop through all configured AHB buffers. */
            for( u8IterAhb = 0U; u8IterAhb < (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].u8QspiUnitAhbBufferCount; u8IterAhb++ )
            {
                /* CRC - Accumulate paQspiUnitAhbBuffer */
                Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitAhbBuffer)[u8IterAhb]);
                /* CRC - Accumulate paQspiUnitAhbBufferMasterId */
                Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitAhbBufferMasterId)[u8IterAhb]);
                /* CRC - Accumulate paQspiUnitAhbBufferSize */
                Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitAhbBufferSize)[u8IterAhb]);
                /* CRC - Accumulate paQspiUnitAhbBufferDataTransferSize */
                Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitAhbBufferDataTransferSize)[u8IterAhb]);
            }        
            /* CRC - Accumulate bHwUnitAhbBufferAllMasters*/
            Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].bHwUnitAhbBufferAllMasters);                                                  
            /* CRC - Accumulate u8QspiUnitAhbBufferCount */
            Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitAhbBufferCount);
        }
        
        /* CRC - Accumulate paQspiUnitSerialAddrMapping*/
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitSerialAddrMapping)[0U]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitSerialAddrMapping)[1U]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitSerialAddrMapping)[2U]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitSerialAddrMapping)[3U]);
        /* CRC - Accumulate u8HwUnitColumnAddressWidth */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitColumnAddressWidth);
        /* CRC - Accumulate bQspiUnitWordAddressable */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).bQspiUnitWordAddressable);
        /* CRC - Accumulate u8QspiUnitRegisterWidth */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitRegisterWidth);
        /* CRC - Accumulate u8QspiUnitBusyBitValue */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitBusyBitValue);
        /* CRC - Accumulate u8QspiUnitBusyBitPosOffset */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiUnitBusyBitPosOffset);
        /* CRC - Accumulate u8QspiHyperflashLatCycls*/
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiHyperflashLatCycls);
        
        if( NULL_PTR != (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitLUT )  /* Check if the LUT is populated or not(if Hyperflash mode). */
        {
            /* Loop through all LUT Instruction/Operand pairs */
            for(u8IterLUTs = 0U; u8IterLUTs < (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].u8QspiLUTSeqsCount; u8IterLUTs++)
            {
                for(u8IterInstrOpers = 0U; u8IterInstrOpers < (*( (*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits].paQspiUnitLUT ))[u8IterLUTs].u8InstrOperCount; u8IterInstrOpers++)
                {
                    /* CRC - Accumulate LUT Instruction/Operand pair */
                    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))  (*( (*(((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).paQspiUnitLUT))[u8IterLUTs].paInstrOper))[u8IterInstrOpers] );
                }
            }        
        }
        
        /* CRC - Accumulate u8QspiLUTSeqsCount */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTSeqsCount);
        /* CRC - Accumulate u8QspiLUTGetStatusSeq */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTGetStatusSeq);
        /* CRC - Accumulate u8QspiLUTReadSeq */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTReadSeq);
        /* CRC - Accumulate u8QspiLUTWriteEnSeq */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTWriteEnSeq);
        /* CRC - Accumulate u8QspiLUTWriteSeq */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTWriteSeq);
        /* CRC - Accumulate u8QspiLUTEraseSeq */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTEraseSeq);        
        /* CRC - Accumulate u8QspiLUTReadIdSeq */
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))((*(Fls_pConfigPtr->pFlsQspiCfgConfig->paQspiUnitCfg))[u8IterUnits]).u8QspiLUTReadIdSeq);       
    }   
#endif /*#if (FLS_QSPI_SECTORS_CONFIGURED == STD_ON)*/    
#endif /*#if (FLS_QSPI_FLASH_AVAILABLE == STD_ON)*/    
    
    return ((Fls_CrcType)Fls_FinalizeCRC());
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        The function initializes Fls module.
* @details      The function sets the internal module variables according to given
*               configuration set.
*
* @param[in]    pConfigPtr        Pointer to flash driver configuration set.
*
* @api
*
* @pre          @p pConfigPtr must not be @p NULL_PTR and the module status must not
*               be @p MEMIF_BUSY.
*
* @implements     Fls_Init_Activity 
*
*/
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_Init
( P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) pConfigPtr )
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#ifdef FLS_PRECOMPILE_SUPPORT
    if (NULL_PTR != pConfigPtr)
#else
    if (NULL_PTR == pConfigPtr)
#endif /* <DRIVER>_PRECOMPILE_SUPPORT */
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_PARAM_CONFIG );
    }
    else if(MEMIF_JOB_PENDING == Fls_eJobResult)
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_BUSY );
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    
    #ifdef FLS_PRECOMPILE_SUPPORT
       Fls_pConfigPtr = &Fls_PBCfgVariantPredefined;
       (void)pConfigPtr;
    #else
       Fls_pConfigPtr = pConfigPtr;
    #endif /* <DRIVER>_PRECOMPILE_SUPPORT */
        if (Fls_pConfigPtr->u16ConfigCrc != Fls_CalcCfgCRC())
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_PARAM_CONFIG );
            Fls_pConfigPtr = NULL_PTR;
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
            Fls_eJobResult = MEMIF_JOB_FAILED;            
        }
        else        
        {
            /* Set the max number of bytes to read/write
                during Fls_MainFunction call */    
            if (MEMIF_MODE_SLOW == Fls_pConfigPtr->eDefaultMode)
            {
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadNormalMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteNormalMode;
            }
            else
            {
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadFastMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteFastMode;
            }
            /* Initialize flash hardware 
               NOTE: The variable 'Fls_eLLDJobResult' will be updated in the below function*/
            Fls_IPW_Init();
            
            if(  MEMIF_JOB_FAILED == Fls_eLLDJobResult )
            {
                Fls_eJobResult = MEMIF_JOB_FAILED;
            #if( FLS_DEV_ERROR_DETECT == STD_ON )
                Fls_pConfigPtr = NULL_PTR; 
            #endif
            }
            else
            {
                Fls_eJobResult = MEMIF_JOB_OK;
            }
        }
    #if(FLS_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}

/**
* @brief            Erase one or more complete flash sectors.
* @details          Starts an erase job asynchronously. The actual job is performed
 *                  by the @p Fls_MainFunction.
*
* @param[in]        TargetAddress        Target address in flash memory.
* @param[in]        Length               Number of bytes to erase.
*
* @return           Std_ReturnType
* @retval           E_OK                    Erase command has been accepted.
* @retval           E_NOT_OK                Erase command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Erase changes module status and some internal variables 
*                   (@p Fls_u32JobSectorIt, @p Fls_u32JobSectorEnd, @p Fls_Job,
*                   @p Fls_eJobResult).
*
* @implements       Fls_Erase_Activity
*
*/
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Erase
( 
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorEnd = 0UL;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( (boolean)FALSE == (Fls_IsAddrSectorStartAligned( (Fls_AddressType)u32TargetAddress )) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(( 0U == u32Length ) || ( (boolean)FALSE == (Fls_IsAddrSectorEndAligned(( (Fls_AddressType)u32TargetAddress + u32Length ) - 1U ))) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32TargetAddress );
        u32TmpJobSectorEnd = Fls_GetSectorIndexByAddr(( u32TargetAddress + u32Length ) - 1U );

        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10();
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
        }    
        else
        {
            /* Configure the erase job */
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobSectorEnd = u32TmpJobSectorEnd;
            Fls_eJob = FLS_JOB_ERASE;
            Fls_u8JobStart = 1U;
            
            /* Execute the erase job */
            Fls_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
        }
    }
    
    return( u8RetVal );
}


/**
* @brief            Write one or more complete flash pages to the flash device.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   @p Fls_MainFunction.
*
* @param[in]        TargetAddress        Target address in flash memory.
* @param[in]        SourceAddressPtr     Pointer to source data buffer.
* @param[in]        Length               Number of bytes to write.
*
* @return           Std_ReturnType
* @retval           E_OK                 Write command has been accepted.
* @retval           E_NOT_OK             Write command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Write changes module status and some internal variables 
 *                  (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
 *                  @p Fls_pJobDataSrcPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_Write_Activity
*
*/
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Write
(
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) pSourceAddressPtr,
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;        
    }
    else if( (boolean)FALSE == (Fls_IsAddrPageStartAligned( (Fls_AddressType)u32TargetAddress )))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(( 0U == u32Length ) || ( (boolean)FALSE == (Fls_IsAddrPageEndAligned( u32TargetAddress +  u32Length ) )))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pSourceAddressPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_DATA );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr(u32TargetAddress);
        u32TmpJobAddrEnd = ( u32TargetAddress + u32Length ) - 1U;
            
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11();
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11();
        }
        else
        {
            /* Configure the write job */
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobSectorEnd = Fls_GetSectorIndexByAddr(u32TmpJobAddrEnd);
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;
            Fls_u32JobAddrIt = u32TargetAddress;
            Fls_pJobDataSrcPtr = pSourceAddressPtr;
            Fls_eJob = FLS_JOB_WRITE;
            Fls_u8JobStart = 1U;
            
            /* Execute the write job */
            Fls_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11();
        }
    } 
    
    return( u8RetVal );
}


#if ( FLS_CANCEL_API == STD_ON ) || defined(__DOXYGEN__)
/**
* @brief            Cancel an ongoing flash read, write, erase or compare job.
* @details          Abort a running job synchronously so that directly after returning
*                   from this function a new job can be started.
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Fls_Cancel changes module status and @p Fls_eJobResult
*                   internal variable.
*
* @implements       Fls_Cancel_Activity 
*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_Cancel( void )
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_CANCEL_ID, FLS_E_UNINIT );
    }
    else
    {
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */

        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {   
            /* Cancel ongoing hardware job */
            Fls_IPW_Cancel();

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
            if(( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
            {
                Fls_UnloadAc( Fls_eJob );
            }
            else
            {
                /* The FLS_JOB_READ and FLS_JOB_COMPARE jobs don't use the access code */
            }
#endif 
            /* If underlying hardware job was successfully canceled */
            if(MEMIF_JOB_CANCELED == Fls_eLLDJobResult)
            {
                /* Update global job result status */
                Fls_eJobResult = MEMIF_JOB_CANCELED;
            }            

            if( NULL_PTR != Fls_pConfigPtr->jobErrorNotificationPtr )
            {
                /* Call FlsJobErrorNotification function if configured */
                Fls_pConfigPtr->jobErrorNotificationPtr();
            }
            else
            {
                /* Callback notification configured as null pointer */            
            }        
        }
        else
        {
            /* Leave the job result unchanged */
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif    /* FLS_CANCEL_API == STD_ON */


#if(( FLS_GET_STATUS_API == STD_ON ) || defined (__DOXYGEN__))
/**
* @brief            Returns the FLS module status.
* @details          Returns the FLS module status synchronously.
*
* @return           MemIf_StatusType
* @retval           MEMIF_UNINIT        Module has not been initialized (yet).
* @retval           MEMIF_IDLE          Module is currently idle.
* @retval           MEMIF_BUSY          Module is currently busy.
*
* @api
*
* @implements       Fls_GetStatus_Activity
*                   
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_StatusType, FLS_CODE ) Fls_GetStatus( void )
{
    VAR( MemIf_StatusType, AUTOMATIC ) eRetVal = MEMIF_IDLE;

    if( NULL_PTR == Fls_pConfigPtr )
    {
        eRetVal = MEMIF_UNINIT;
    } 
    else if( MEMIF_JOB_PENDING == Fls_eJobResult )
    {
        eRetVal = MEMIF_BUSY;
    }
    else
    {
        eRetVal = MEMIF_IDLE;
    }

    return( eRetVal );
}
#endif    /* FLS_GET_STATUS_API == STD_ON */


#if ( FLS_GET_JOB_RESULT_API == STD_ON )||  defined (__DOXYGEN__)/**
* @brief            Returns the result of the last job.
* @details          Returns synchronously the result of the last job.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @implements       Fls_GetJobResult_Activity
*                   
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_JobResultType, FLS_CODE ) Fls_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETJOBRESULT_ID, FLS_E_UNINIT );
        eRetVal = (MemIf_JobResultType)MEMIF_JOB_FAILED;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        eRetVal = Fls_eJobResult;
    } 
    return( eRetVal );
}
#endif    /* FLS_GET_JOB_RESULT_API == STD_ON */


/**
* @brief            Reads from flash memory.
* @details          Starts a read job asynchronously. The actual job is performed by
*                   @p Fls_MainFunction.
*
* @param[in]        SourceAddress        Source address in flash memory.
* @param[in]        Length               Number of bytes to read.
* @param[out]       TargetAddressPtr    Pointer to target data buffer.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_Read changes module status and some internal variables 
*                 (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
*                 @p Fls_pJobDataDestPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_Read_Activity
*                   
*/
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Read
( 
    VAR( Fls_AddressType, AUTOMATIC) u32SourceAddress, 
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pTargetAddressPtr,    
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;
    
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    else if( u32SourceAddress >= FLS_TOTAL_SIZE )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32SourceAddress + u32Length) > FLS_TOTAL_SIZE ))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }   
    #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
    #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)    
    else if( (boolean)FALSE == Fls_IsAddrWordAligned(u32SourceAddress) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK; 
    }    
    else if( (boolean)FALSE == Fls_IsAddrWordAligned(u32SourceAddress + u32Length) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK; 
    }
    #endif /* #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */
    #endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */   
    else if( NULL_PTR == pTargetAddressPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_DATA );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32SourceAddress );
        u32TmpJobAddrEnd = ( u32SourceAddress + u32Length ) - 1U;
        
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12();
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }    
        else
        {
            /* Configure the read job */
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobSectorEnd = Fls_GetSectorIndexByAddr(u32TmpJobAddrEnd);   
            Fls_u32JobAddrIt = u32SourceAddress;
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;
            Fls_pJobDataDestPtr = pTargetAddressPtr;
            Fls_eJob = FLS_JOB_READ;
            
            Fls_u8JobStart = 1U;

            /* Execute the read job */
            Fls_eJobResult = MEMIF_JOB_PENDING;

        }       
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12();
    }
    
    return( u8RetVal );
}


#if( FLS_COMPARE_API == STD_ON ) || defined(__DOXYGEN__)
/**
* @brief           Compares a flash memory area with an application data buffer.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  @p Fls_MainFunction.
*
* @param[in]        SourceAddress          Source address in flash memory.
* @param[in]        TargetAddressPtr       Pointer to source data buffer.
* @param[in]        Length                 Number of bytes to compare.
*
* @return           Std_ReturnType
* @retval           E_OK                      Compare command has been accepted.
* @retval           E_NOT_OK                   Compare command has not been accepted.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_Read changes module status and some internal variables 
 *                (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
 *                @p Fls_pJobDataSrcPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_Compare_Activity
*                   
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Compare
(
    VAR( Fls_AddressType, AUTOMATIC) u32SourceAddress, 
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) pTargetAddressPtr, 
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( u32SourceAddress >= FLS_TOTAL_SIZE )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32SourceAddress + u32Length) > FLS_TOTAL_SIZE ))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
    #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)    
    else if( (boolean)FALSE == Fls_IsAddrWordAligned(u32SourceAddress) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK; 
    }    
    else if( (boolean)FALSE == Fls_IsAddrWordAligned(u32SourceAddress + u32Length) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK; 
    }
    #endif /* #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */
    #endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */   
    else if( NULL_PTR == pTargetAddressPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_DATA );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32SourceAddress );
        u32TmpJobAddrEnd = ( u32SourceAddress + u32Length ) - 1U;
   
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13();    
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */            
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobSectorEnd = Fls_GetSectorIndexByAddr(u32TmpJobAddrEnd);            
            Fls_u32JobAddrIt = u32SourceAddress;
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;
            Fls_pJobDataSrcPtr = pTargetAddressPtr;
            Fls_eJob = FLS_JOB_COMPARE;
            Fls_u8JobStart = 1U;

            /* Execute the read job */
            Fls_eJobResult = MEMIF_JOB_PENDING;

        }       
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13();
    }
    
    return( u8RetVal );
}
#endif /* FLS_COMPARE_API == STD_ON */

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
* @brief           Verify whether a given memory area has been erased but not (yet) programmed.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  @p Fls_MainFunction.                  
*
* @param[in]        TargetAddress          Address in flash memory from which the blank check should be started.
* @param[in]        Length                 Number of bytes to be checked for erase pattern.
*
* @return           Std_ReturnType
* @retval           E_OK                   Blank checking command has been accepted.
* @retval           E_NOT_OK               Blank checking command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Read changes module status and some internal variables 
*                   (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
*                   @p Fls_pJobDataSrcPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_BlankCheck_Activity
*                   
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_BlankCheck
(
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) u32Length
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;
    
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( u32TargetAddress >= FLS_TOTAL_SIZE )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32TargetAddress + u32Length) > FLS_TOTAL_SIZE ))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }  
    #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)
    #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)    
    else if( (boolean)FALSE == Fls_IsAddrWordAligned(u32TargetAddress) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK; 
    }    
    else if( (boolean)FALSE == Fls_IsAddrWordAligned(u32TargetAddress + u32Length) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK; 
    }
    #endif /* #if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */
    #endif /* #if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED) */
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32TargetAddress );
        u32TmpJobAddrEnd = ( u32TargetAddress + u32Length ) - 1U;
        
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_14(); 
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */               
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_u32JobSectorIt = u32TmpJobSectorIt;               
            Fls_u32JobAddrIt = u32TargetAddress;               
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;         
            Fls_eJob = FLS_JOB_BLANK_CHECK;
            Fls_u8JobStart = 1U;

            /* Execute the read job */
            Fls_eJobResult = MEMIF_JOB_PENDING;
        }       
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_14();        
    }
    
    return( u8RetVal );
}
#endif /* FLS_BLANK_CHECK_API == STD_ON */

#if( FLS_SET_MODE_API == STD_ON )|| defined (__DOXYGEN__)
/**
* @brief           Sets the FLS module's operation mode to the given Mode.
* @details         Every given mode determinates maximum bytes for read-write
 *                 operations. Every mode has a set of pre-configured values.
*
* @param[in]        Mode        MEMIF_MODE_FAST or MEMIF_MODE_SLOW.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_SetMode changes internal variables @p Fls_u32MaxRead and
*                 @p Fls_u32MaxWrite.
*
* @implements       Fls_SetMode_Activity
*                   
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_SetMode
(
    VAR( MemIf_ModeType, AUTOMATIC ) eMode 
)
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_UNINIT );
    }
    else if( MEMIF_JOB_PENDING == Fls_eJobResult )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_BUSY );
    }
    else
    {
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
        /* Set the max number of bytes to read/write
            during Fls_MainFunction call */
        switch( eMode ) 
        {
            case MEMIF_MODE_FAST:
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadFastMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteFastMode;    
                break;
                
            case MEMIF_MODE_SLOW:
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadNormalMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteNormalMode;
                break;
                
            default:
                /* Do nothing - should not happen in Fully Trusted Environment;
                   'default' clause added to fulfill MISRA Rule 15.3 */
                break;
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )        
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_SET_MODE_API == STD_ON */

#if( FLS_VERSION_INFO_API == STD_ON )|| defined(__DOXYGEN__)
/**
* @brief        Returns version information about FLS module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] pVersionInfoPtr  Pointer to where to store the version information of this module.
*
* @api
*
* @implements       Fls_GetVersionInfo_Activity
*                   
*/
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_GetVersionInfo
(
    P2VAR( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) pVersionInfoPtr 
)
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == pVersionInfoPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETVERSIONINFO_ID, FLS_E_PARAM_POINTER );
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        pVersionInfoPtr->moduleID = (uint16)FLS_MODULE_ID;
        pVersionInfoPtr->vendorID = (uint16)FLS_VENDOR_ID;
        pVersionInfoPtr->sw_major_version = (uint8)FLS_SW_MAJOR_VERSION;
        pVersionInfoPtr->sw_minor_version = (uint8)FLS_SW_MINOR_VERSION;
        pVersionInfoPtr->sw_patch_version = (uint8)FLS_SW_PATCH_VERSION;
#if( FLS_DEV_ERROR_DETECT == STD_ON )        
    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_VERSION_INFO_API == STD_ON */


/**
* @brief            Performs actual flash read, write, erase and compare jobs.
* @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
*                   current FLS module's operating mode (normal, fast)
*                   and write, erase Mode of Execution (sync, async).
*
* @api
*
* @pre              The module has to be initialized.
*
*
* @implements       Fls_MainFunction_Activity
*                   
* @note             This function have to be called ciclically by the Basic Software Module; 
*                   it will do nothing if there aren't pending job.
*/
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_MainFunction( void )
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_UNINIT );
    }
    else
    { 
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
            VAR(MemIf_JobResultType, AUTOMATIC) eWorkResult = MEMIF_JOB_OK;

            if( 1U == Fls_u8JobStart )
            {            
                Fls_u8JobStart = 0U;
                
                /* Clear result of hardware job */
                Fls_LLDClrJobResult();

                Fls_IPW_AbortSuspended();
                
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
                /* Load position independent access code */
                if(( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
                {
                    Fls_LoadAc( Fls_eJob );
                }
                else
                {
                    /* Fls_Job != FLS_JOB_ERASE &&  Fls_Job != FLS_JOB_WRITE */
                }
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */
                        
            }
            /*else
            {
                 Fls_u8JobStart != 1U 
            }*/
                        
            
            /* Check the status of pending jobs. */
            if( FLASH_JOB_NONE != Fls_eLLDJob ) /* If there is any Async job scheduled. */
            {
                /* Process ongoing erase or write asynchronous hardware job */
                Fls_IPW_LLDMainFunction();  /* Process the maximum defined length(configuration parameter), or until a sector boundary. */
            }
        #if( (FLS_USE_INTERRUPTS == STD_ON) && (FLS_TIMEOUT_HANDLING == STD_ON) )    
            else if(FLASH_IRQ_JOB_NONE != Fls_eLLDIrqJob)
            {   /* else, there might be an interrupt context job pending. 
                If timeout is not enabled, do nothing, wait for the Fls_eLLDJobResult
                to be update in interrupt context at the end of the IRQ job. 
                If timeout is enabled, update and check if it has expired.*/
                Fls_CheckIrqTimeout();  /* If timeout has expired, Fls_eLLDJobResult will be updated to MEMIF_JOB_FAILED. */
            }
            else
            {
                /* Empty clause added to fulfill MISRA. */
            }
        #endif    
            
            
            /* Get status/result of ongoing erase or write Async or Irq mode hardware job */
            eWorkResult = Fls_LLDGetJobResult();
            

            if( MEMIF_JOB_OK == eWorkResult )
            {
                switch( Fls_eJob )
                {
                    case FLS_JOB_ERASE:
                            eWorkResult = Fls_DoJobErase();
                        break;
                    case FLS_JOB_WRITE:
                            eWorkResult = Fls_DoJobDataTransfer( Fls_eJob, Fls_u32MaxWrite );
                        break;
#if( FLS_BLANK_CHECK_API == STD_ON )                    
                    case FLS_JOB_BLANK_CHECK:
    /* For Blank Check job, the static function Fls_DoJobDataTransfer( ) 
                will be used with the same input parameters */
#endif /* FLS_BLANK_CHECK_API == STD_ON */                
                    case FLS_JOB_READ:
    /* For Read and Compare jobs the static function Fls_DoJobDataTransfer( ) 
                will be used with the same input parameters */
#if( FLS_COMPARE_API == STD_ON )                
                    case FLS_JOB_COMPARE:
#endif /* FLS_COMPARE_API == STD_ON */        
                            eWorkResult = Fls_DoJobDataTransfer( Fls_eJob, Fls_u32MaxRead );
                        break;
                    default:
                        /* Do nothing - should not happen in Fully Trusted Environment;
                           'default' clause added to fulfill MISRA Rule 15.3 */
                        break;
                }
            }
            else
            {
                /* eWorkResult != MEMIF_JOB_OK */
            }

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
            if(( MEMIF_JOB_PENDING != eWorkResult ) &&
               (( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
              )
            {
                Fls_UnloadAc( Fls_eJob );
            }
#endif

            Fls_eJobResult = eWorkResult;
            
            if( MEMIF_JOB_OK == eWorkResult )
            {
                if( NULL_PTR != Fls_pConfigPtr->jobEndNotificationPtr )
                {
                    /* Call FlsJobEndNotification function if configured */
                    Fls_pConfigPtr->jobEndNotificationPtr();
                }
                /*else
                {
                     Callback notification configured as null pointer 
                }*/
            }            
            else if(( MEMIF_JOB_FAILED == eWorkResult ) ||
                    ( MEMIF_BLOCK_INCONSISTENT == eWorkResult )
                   )
            {                
                                        
                if( NULL_PTR != Fls_pConfigPtr->jobErrorNotificationPtr )
                {
                    /* Call FlsJobErrorNotification function if configured */
                    Fls_pConfigPtr->jobErrorNotificationPtr();
                }
                else
                {
                    /* Callback notification configured as null pointer */            
                }
            }
            else
            {
                /* Compiler_Warning: else clause added to fulfil the MISRA rule 14.10 */
                /* Not done yet. There is more data to transfer in following 
                    Fls_MainFunction call(for Async jobs, or in interrupt context for IRQ type jobs). */
            }
        }
        else
        {
            /* Nothing to do since no job is pending */
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }    
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}

/**
* @brief          Returns the LLD JobResult
*/
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_LLDGetJobResult( void )
{
    return( Fls_eLLDJobResult );
}

/**
* @brief          Clear status of erase or write hardware job result.
* @details        Set the internal status to  MEMIF_JOB_OK
*/  
static FUNC( void, FLS_CODE ) Fls_LLDClrJobResult( void )
{
    Fls_eLLDJobResult = MEMIF_JOB_OK;
    Fls_eLLDJob = FLASH_JOB_NONE;
    Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
}


#if( (FLS_USE_INTERRUPTS == STD_ON) && (FLS_TIMEOUT_HANDLING == STD_ON) )
/**
* @brief          Check and update the IRQ timeout.
* @details        If there is any pending IRQ job, check if the timeout has expired.
*/
static FUNC( void, FLS_CODE ) Fls_CheckIrqTimeout(void)
{    
    if( 0UL == Fls_u32LLDTimeout_Counter )
    {   
        /* Error, the number of maximum configured Fls_MainFunction iterations for an 
           IRQ mode job has been exceeded. Mark the job as failed. */
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;    
    }
    else
    {
        Fls_u32LLDTimeout_Counter--;
    }
}
#endif

#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiSetSfarAddr  
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(Fls_AddressType, AUTOMATIC) u32Addr
)
{
    Fls_IPW_QspiSetSfarAddr(eHwUnitName, u32Addr);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( Std_ReturnType, FLS_CODE ) Fls_QspiSetLUT
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber, 
    CONST(uint32, AUTOMATIC) LUTValue
)
{
    return Fls_IPW_QspiSetLUT(eHwUnitName, u8LUTNumber, LUTValue);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(Std_ReturnType, FLS_CODE) Fls_QspiLaunchLUTNumber
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber,
    CONST(uint32, AUTOMATIC) u32DataSize,
    CONST(uint8, AUTOMATIC) u8ParEn
)
{
    return Fls_IPW_QspiLaunchLUTNumber(eHwUnitName, u8LUTNumber, u32DataSize, u8ParEn);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiResetFlags(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    Fls_IPW_QspiResetFlags(eHwUnitName);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiSetRXWmrk(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, CONST(uint8, AUTOMATIC) u8BytesToRead)
{
    Fls_IPW_QspiSetRXWmrk(eHwUnitName, u8BytesToRead);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(Std_ReturnType, FLS_CODE) Fls_QspiCheckControllerIdle(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    return Fls_IPW_QspiCheckControllerIdle(eHwUnitName);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(Std_ReturnType, FLS_CODE) Fls_QspiReadRXBuffer
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    CONST(uint8, AUTOMATIC) u8BytesToRead
)
{
    return Fls_IPW_QspiReadRXBuffer(eHwUnitName, p8DataPtr, u8BytesToRead);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiLoadTXBuffer
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
)
{
    Fls_IPW_QspiLoadTXBuffer(eHwUnitName, p8DataPtr, u8BytesToWrite);
}
/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(Fls_AddressType, FLS_CODE) Fls_QspiGetHwUnitBaseAddr(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    return Fls_IPW_QspiGetHwUnitBaseAddr(eHwUnitName);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiDisableModule(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    Fls_IPW_QspiDisableModule(eHwUnitName);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiEnableModule(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName)
{
    Fls_IPW_QspiEnableModule(eHwUnitName);
}

/*
* @violates @ref fls_c_REF_8 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_QspiSetCalibDelayValues
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8CoarseDelay,
    CONST(uint8, AUTOMATIC) u8FineDelay
)
{
    Fls_IPW_QspiSetCalibDelayValues(eHwUnitName, u8CoarseDelay, u8FineDelay);
}

#endif
#endif

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_6 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
/*Compiler_Warning: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly. 
   Compiler wrongfully reports the warnings at the last line of the file. 
*/

