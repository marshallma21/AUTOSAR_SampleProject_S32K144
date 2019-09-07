/**
*   @file    Fls_Flash.h   
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

#ifndef FLS_FLASH_H
#define FLS_FLASH_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_fash_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined: 'FLASH_AC_CALL'
* Macro is used for the purpose of abstraction between PPC and ARM platforms.
*
* @section fls_flash_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping 
*
* @section fls_flash_h_REF_4 
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function. It was declared as external linkage to support multiplie IPVs
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_Types.h"
#include "Fls_Flash_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_FLASH_VENDOR_ID                    43
#define FLS_FLASH_MODULE_ID                    92
#define FLS_FLASH_AR_RELEASE_MAJOR_VERSION     4
#define FLS_FLASH_AR_RELEASE_MINOR_VERSION     2
#define FLS_FLASH_AR_RELEASE_REVISION_VERSION  2
#define FLS_FLASH_SW_MAJOR_VERSION             1
#define FLS_FLASH_SW_MINOR_VERSION             0
#define FLS_FLASH_SW_PATCH_VERSION             1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID != FLS_VENDOR_ID)
    #error "Fls_Flash.h and Fls.h have different vendor ids"
#endif

/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.h and Fls.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.h and Fls.h are different"
    #endif
#endif

/* Check if current file and Fls_Types.h header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID != FLS_TYPES_VENDOR_ID)
    #error "Fls_Flash.h and Fls_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Types.h header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION != FLS_TYPES_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION != FLS_TYPES_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION != FLS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.h and Fls_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls_Types.h header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION != FLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION != FLS_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.h and Fls_Types.h are different"
    #endif
#endif

/* Check if current file and Fls_Flash_Types.h header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID != FLS_FLASH_TYPES_VENDOR_ID)
    #error "Fls_Flash.h and Fls_Flash_Types.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash_Types.h header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION != FLS_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION != FLS_FLASH_TYPES_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION != FLS_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.hc and Fls_Flash_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION != FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION != FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.h and Fls_Flash_Types.h are different"
    #endif
#endif 
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#define FLASH_ARM_FAR_CALL2THUMB_CODE_BIT0_U32 (0x00000001UL)
    /* Macro for Access Code Call. On ARM/Thumb, BLX instruction used by the compiler for calling a function
       pointed to by the pointer requires that LSB bit of the address is set to one if the called fcn is coded in Thumb. */ 
    /* @violates @ref fls_flash_h_REF_2 Function-like macro defined */
    #define FLASH_AC_CALL(ptr2fcn, ptr2fcnType) ((ptr2fcnType)(((uint32)(ptr2fcn)) | FLASH_ARM_FAR_CALL2THUMB_CODE_BIT0_U32))
#else
    /* @violates @ref fls_flash_h_REF_2 Function-like macro defined */
    #define FLASH_AC_CALL(ptr2fcn, ptr2fcnType) (ptr2fcn)
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief Logical address of data block currently processed by Fls_MainFunction
*/
extern VAR(Fls_AddressType, FLS_VAR) Fls_u32JobAddrIt;
/** 
* @brief Index of flash sector currently processed by a job
* @details Used by all types of job
*/
extern VAR(volatile Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorIt;
/** 
    @brief Result of last flash hardware job
*/
extern VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_eLLDJobResult;
/** 
    @brief Type of current flash hardware job - used for asynchronous operating mode.
*/
extern VAR(Fls_LLDJobType, FLS_VAR) Fls_eLLDJob;
/** 
* @brief Pointer to current flash module configuration set
*/
extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_pConfigPtr;
/** 
    @brief Number of bytes of data left to write.
*/
extern VAR(volatile Fls_LengthType, AUTOMATIC) Fls_u32LLDRemainingDataToWrite;

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#if( ( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON ) || ( FLS_SYNCRONIZE_CACHE == STD_ON )) 
extern VAR(Fls_LengthType, AUTOMATIC) Fls_u32LLDNumberOfStepBack;
#endif

#if (FLS_TIMEOUT_HANDLING == STD_ON)
/**
    @brief Timeout counter used in both sync/async modes
*/
extern VAR(uint32, FLS_VAR) Fls_u32LLDTimeout_Counter;
#endif

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_CONST_UNSPECIFIED
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

/**
    @brief FLASH array description
*/
/*
* @violates @ref fls_flash_h_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Fls_Flash_ArrayInfoType, FLS_CONST) Fls_Flash_aArrayList0[1U];

#define FLS_STOP_SEC_CONST_UNSPECIFIED
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

FUNC( void, FLS_CODE ) Fls_Flash_Init( void );
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_AbortSuspended(void);
#if (FLS_CANCEL_API == STD_ON )
FUNC( void, FLS_CODE ) Fls_Flash_Cancel( void );
#endif   /* FLS_CANCEL_API == STD_ON */
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorErase
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) || (STD_ON == FLS_SYNCRONIZE_CACHE) )
    CONST( Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) bAsynch
);
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorWrite
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
);
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorRead
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
);
#if(( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorCompare
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr
);
#endif
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionErase( void );
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionWrite( void );
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionEraseBlankCheck( void );
#endif

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_fash_h_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_h_REF_3 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"
   
#ifdef __cplusplus
}
#endif

#endif /* FLS_FLASH_H */

/** @}*/
