/**
*   @file    Fls_Flash_Code.c  
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Flash IPV_FLASHV2 driver source code.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_flash_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section fls_flash_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
* This violation is because of complex statement
*
* @section fls_flash_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section fls_flash_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* This violation is not fixed since if hardware error is detected it should return from the function
*
* @section fls_flash_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as the read/write/erase/operation finished
*
* @section fls_flash_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6, Booleans operands are not used for logical
* operators '&&', '||' and '!'
* This violation because of it is not effectively boolean
*
* @section fls_flash_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section fls_flash_c_REF_9
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before #include
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_flash_c_REF_10
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement
*
* @section fls_flash_c_REF_11
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*
* @section fls_flash_c_REF_12
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_flash_c_REF_13
* Violates MISRA 2004 Required Rule 17.2, Pointer subtraction shall only be applied to pointers
* that address elements of the same array
* Due to the pointers that address elements are not the same array
*
* @section fls_flash_c_REF_14
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable.
* The code is not dynamically linked. An absolute stack address is obtained 
* when taking the address of the near auto variable.
*
* @section fls_flash_c_REF_15 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* The pointer subtraction is made inside while loop and due to its condition the subtraction 
* result is always positive and therefore it can be casted to unsigned. 
*
* @section fls_flash_c_REF_16
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* Due to casting between a pointer and unsigned long representing address.
* 
* @section fls_flash_c_REF_17
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
* Once abnormal condition is indicated, the loop is terminated by 'break'. Since 
* there are handled several abnormal conditions, the loop contains more
* than one 'break'.    
*
* @section fls_flash_c_REF_18
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* On ARM platform, the liker is not aware whether Access Code copied to RAM
* by the FLS driver is compiled in Thumb mode. Therefore LSB bit in its
* address needs to be set to notify the core that the code executed after BLX 
* instruction branching to AC code is in Thumb-encoded.
* 
* @section fls_flash_c_REF_19
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section fls_flash_c_REF_20
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as in only one file 
*
* @section fls_flash_c_REF_21
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* This function may be called from Mcal.h in Base module 
*
* @section fls_flash_c_REF_22
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used
* This comma operator was used for the side effect. The return value from called 
* was not evaluated
*
* @section fls_flash_c_REF_23
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating 
* contents in that address.
*
* @section fls_flash_c_REF_24
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function. Variable is may be used in many functions depend on user configurations
*
* @section fls_flash_c_REF_25
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* This function may be called from upper layer
*
* @section fls_flash_c_REF_26
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted
* Variable is compared with same value more than one time to support multi derivatives of platfom.
*
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
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
#include "Fls_Flash.h"
#include "Fls_Flash_Types.h"
#include "Reg_eSys_FLASHC.h"


#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */

#include "SchM_Fls.h"
#include "StdRegMacros.h"

#if (STD_ON == FLS_SYNCRONIZE_CACHE) 
#include "Mcl.h"
#endif /* FLS_SYNCRONIZE_CACHE */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_FLASH_VENDOR_ID_C                      43
/*
* @violates @ref fls_flash_c_REF_12 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C       4
/*
* @violates @ref fls_flash_c_REF_12 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_FLASH_AR_RELEASE_MINOR_VERSION_C       2
/*
* @violates @ref fls_flash_c_REF_12 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_FLASH_AR_RELEASE_REVISION_VERSION_C    2
#define FLS_FLASH_SW_MAJOR_VERSION_C               1
#define FLS_FLASH_SW_MINOR_VERSION_C               0
#define FLS_FLASH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Flash.c and Fls.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and Fls.h are different"
    #endif
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Fls.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC.h header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Flash.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and Reg_eSys_FLASHC.h are different"
    #endif
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Fls_Flash_Types.h header file are of the same vendor */
#if (FLS_FLASH_VENDOR_ID_C != FLS_FLASH_TYPES_VENDOR_ID)
    #error "Fls_Flash.c and Fls_Flash_Types.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls_Flash_Types header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and Fls_Flash_Types.h are different"
    #endif
#endif
/* Check if current file and Fls_Flash_Types header file are of the same Software version */
#if ((FLS_FLASH_SW_MAJOR_VERSION_C != FLS_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (FLS_FLASH_SW_MINOR_VERSION_C != FLS_FLASH_TYPES_SW_MINOR_VERSION) || \
     (FLS_FLASH_SW_PATCH_VERSION_C != FLS_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Flash.c and Fls_Flash_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StdRegMacros header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Flash.c and StdRegMacros.h are different"
    #endif
#endif


#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Det.h are different"
    #endif
#endif
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcl header file are of the same Autosar version */
    #if ((FLS_FLASH_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_FLASH_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Mcl.h are different"
    #endif
#endif
#endif /* FLS_SYNCRONIZE_CACHE */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_VerifyErase
(
    P2CONST(volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    CONST( Fls_LengthType, AUTOMATIC) u32DataLength               
);
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK */
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_VerifyWrite
(
    P2CONST( volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    P2CONST( Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pUserBufferPtr,
    CONST( Fls_LengthType, AUTOMATIC) u32DataLength               
);
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */
static FUNC( void, FLS_CODE ) Fls_Flash_PageWrite
( 
    CONST(uint32, AUTOMATIC) u32TotalBytes        
);
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcInitDataLength
( 
    CONSTP2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) volatile pSourceAddrPtr,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
);
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcWideDataLength
(
    CONST(uint32, AUTOMATIC) u32InitDataLength,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
);
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Flash_CheckCtrlIdle(void);
static FUNC(void, FLS_CODE) Fls_Flash_LoadFCCOBParams
(
    CONST(Fls_AddressType, AUTOMATIC) u32PhyTargetAddr,
    CONST(uint8, AUTOMATIC) u8FCCOBCmdId
);
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_GetFProtReg
( 
    VAR( Fls_AddressType, AUTOMATIC) u32SectStartAddr,  
    P2VAR( Fls_AddressType, AUTOMATIC, FLS_APPL_DATA ) pu32RegAddr, 
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pu8BitProtNo 
);
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_WaitForOperationFinish( void );
#if( FLASH_CHECK_FLEXNVM_RATIO == STD_ON ) 
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_CheckFlexNvmPartitionRatio( void );
#endif /* FLASH_CHECK_FLEXNVM_RATIO == STD_ON */

static FUNC( Fls_AddressType, FLS_CODE ) Fls_Flash_ConvertSysToFTFEAddr( VAR(Fls_AddressType, AUTOMATIC) u32SystemAddress );
    
#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON)

#define FLS_START_SEC_RAMCODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#ifdef _LINARO_C_S32K14x_
/* @violates @ref fls_flash_c_REF_20 Object/function previously declared */
 FUNC( void, FLS_CODE ) Fls_Flash_InvalidPrefetchBuff_Ram( void ) __attribute__ ((section (".ramcode")));
#else
/* @violates @ref fls_flash_c_REF_20 Object/function previously declared */
 FUNC( void, FLS_CODE ) Fls_Flash_InvalidPrefetchBuff_Ram( void );
#endif /* #ifdef _LINARO_C_S32K14x_ */

#define FLS_STOP_SEC_RAMCODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#endif /* #if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON) */

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#if( FLS_DSI_HANDLER_API == STD_ON )
/** 
    @brief Current status of the sector read operation. The Fls_DsiHandler function can terminate
        the read operation by setting this volatile variable to FLASH_E_FAILED
*/
static VAR( volatile Fls_LLDReturnType, FLS_VAR ) Fls_Flash_eReadStatus = FLASH_E_OK;

/** 
    @brief Current status of the sector compare operation. The Fls_DsiHandler function can terminate
        the compare operation by setting this volatile variable to FLASH_E_FAILED
*/
/*
* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/
static VAR( volatile Fls_LLDReturnType, FLS_VAR ) Fls_Flash_eCompareStatus = FLASH_E_OK;
#endif

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

/**
    @brief Physical address of currently read uint8, uint32 from flash
*/
/*
* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/
static P2CONST(volatile uint8, FLS_VAR, FLS_APPL_CONST) volatile Fls_Flash_pReadAddressPtr = NULL_PTR;
/**
    @brief Physical address of currently compared uint8, uint32 from user buffer
*/
/*
* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/
static P2CONST(volatile uint8, FLS_VAR, FLS_APPL_CONST) volatile Fls_Flash_pCompareAddressPtr = NULL_PTR;

/**
    @brief Bit position of current sector in Protect register
*/
static VAR(uint8, FLS_VAR) u8SecRegProtBitPos = 0U;

#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

/** 
    @brief 'double word program operation' iterator
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32ProgramCycle = 0UL;

/** 
    @brief 'double word program operation' count
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32DoubleWordToCopy = 0UL;
/** 
    @brief Protect register address of current sector
*/
static VAR(Fls_AddressType, FLS_VAR) u32SecRegProtAddr = 0UL;
/** 
    @brief 'data copy' auxiliary pointers
*/
static P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_Flash_pTargetAddressPtr = NULL_PTR;
static P2CONST(uint32, FLS_VAR, FLS_APPL_CONST) Fls_Flash_pSourceAddressPtr = NULL_PTR;
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
static P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_Flash_pEndAddressPtr = NULL_PTR;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"


#define FLS_START_SEC_CONST_32
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
    @brief Flash erased value for erased state
*/
/*
* @violates @ref fls_flash_c_REF_24 Objects shall be defined at block scope if they are only accessed
* from within a single function
*/
static CONST(uint32, FLS_CONST) Fls_Flash_ErasedValue = FLS_ERASED_VALUE;
#endif

#define FLS_STOP_SEC_CONST_32
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

/**
* @brief            Convert system memory map address to FTFE internal memory address
*
* @details          FTFE module requires flash address in 24bit format. Address passed to FTFE module
*                   via FCCOB command object is composed of sector offset(reported to D-FLASH or P-FLASH 
*                   base address) plus the 24-th bit set for DATA flash sectors and cleared for 
*                   PROGRAM flash sectors. 
*
* @param[in]        u32SystemAddress Physical flash address in system memory map
*
* @return           u32FTFEAddr    FTFE internal memory address
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_Flash_ConvertSysToFTFEAddr( VAR(Fls_AddressType, AUTOMATIC) u32SystemAddress )
{
    VAR( Fls_AddressType, AUTOMATIC) u32FTFEAddr = 0x0UL;
    
    /* check if address is a valid flash address and calculate FTFE internal memory addr */
    if( u32SystemAddress >= (P_FLASH_BASE_ADDR + P_FLASH_SIZE))                /* if NOT a P-FLASH addr... */     
    {
        if( (u32SystemAddress < D_FLASH_BASE_ADDR) ||               
            (u32SystemAddress >= (D_FLASH_BASE_ADDR + D_FLASH_SIZE))            /* ...and also NOT a D-FLASH addr... */
          ) 
        {
            /* invalid flash address */
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return u32FTFEAddr;      
        }
        else /* valid D-FLASH addr */
        {
            /* data flash FTFE address */
            u32FTFEAddr = (u32SystemAddress - D_FLASH_BASE_ADDR) + 0x800000UL;  /* for D-FLASH set 24th bit of flash addr */
        }
    }
    else /* valid P-FLASH addr */
    {
        /* program flash FTFE address */
        u32FTFEAddr = u32SystemAddress - P_FLASH_BASE_ADDR;  
    }
        
    return u32FTFEAddr;
}


/**
* @brief          Wait for HW operation to complete, with timeout.
* @return         Success (DONE)
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_WaitForOperationFinish( void )
{
#if( FLS_TIMEOUT_HANDLING == STD_ON )
    uint32 u32TimerCounterAbort = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_FAILED;
    
#if( FLS_TIMEOUT_HANDLING == STD_ON )
    /* wait until done or abort timeout is reached */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    while((0U == (REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))) && (0U < u32TimerCounterAbort))
    {
        --u32TimerCounterAbort;
    }
#else
    /* wait until done */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    while(0U == (REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8)))
    {
    }
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    /* return true if DONE */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    MCAL_FAULT_INJECTION_POINT(FLS_FIP_1_WAIT_FOR_OPERATION_FINISH_KINETIS);
    
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if (REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))
    {
        /* OK, memory idle */
        eRetVal = FLASH_E_OK; 
    }
    else
    {
        /* error, memory controller not idle */
        eRetVal = FLASH_E_FAILED;
    }
    
    MCAL_FAULT_INJECTION_POINT(FLS_FIP_10_FLS_FLASH_FINISH_HV_OPERATION);
    
    return eRetVal;  
}

#if( FLASH_CHECK_FLEXNVM_RATIO == STD_ON ) 
/**
* @brief        Checks FlexNvm memory partition ratio
*
* @param[in]    u16EEPROMSize    EEPROM size allocated in FlexRAM , expressed in bytes   
* @param[in]    u8DFlashSize     Data flash allocated for EEPROM emulation in FlexNVM, expressed in Kilobytes    
*
* @return       Configuration validity
* @retval       FLASH_E_OK FlexNVM partition valid configuration (all FlexNVM configured as Data flash)
* @retval       FLASH_E_FAILED operation failed due to invalid configuration or timeout 
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_CheckFlexNvmPartitionRatio(void)
{
    
    VAR(uint32, AUTOMATIC) u32FlexNvmPartSize = 0U;
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_PARTITION_ERR;   /* Remains unchanged if FlexNVM partion code is not correct */      
    /* Get FlexNVM Partition Code Ratio */
    /* 
    * @violates @ref fls_flash_c_REF_16 Cast from pointer to unsigned long 
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */    
    u32FlexNvmPartSize = (uint32)(REG_BIT_GET32(FLASH_SIM_FCFG1_ADDR32,FLASH_SIM_FCFG1_DEPART_U32) >> 12U );  
    
    /* Check FlexNVM Partition Data flash dimension is configured correctly */
    /* 
    * @violates @ref fls_flash_c_REF_26 Compare with same value two more than one time 
    */   
        if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V1) ||
            (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V2) ||
            (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V3) ||
            (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V1) ||
            (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V2)
    /* 
    * @violates @ref fls_flash_c_REF_26 Compare with same value two more than one time 
    */ 
          )
        {
            /* FlexNvm configured for all Data Flash (no EEPROM) */
            eRetVal = FLASH_E_OK;
        }
        else 
        {
            /* FlexNvm NOT configured for all Data Flash */
            eRetVal =  FLASH_E_PARTITION_ERR;
        }        
    return eRetVal;
}
#endif /* FLASH_CHECK_FLEXNVM_RATIO == STD_ON */

/**
* @brief          Initialize flash hardware.
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/     
FUNC( void, FLS_CODE ) Fls_Flash_Init( void )
{
    VAR(uint32, AUTOMATIC) u32ConfigIter = 0UL;
    VAR(Fls_AddressType, AUTOMATIC) u32SecStartAddr = 0UL;
#if( FLASH_CHECK_FLEXNVM_RATIO == STD_ON )    
    VAR(Fls_LLDReturnType, AUTOMATIC) eFlexNVMConfigurationFlag = FLASH_E_PARTITION_ERR;
#endif  

    Fls_eLLDJobResult = MEMIF_JOB_OK;

/* @errata ERR_IPV_FMC_0001 */
#ifdef ERR_IPV_FMC_0001
    #if (ERR_IPV_FMC_0001 == STD_ON)       
    /* Check the status of the prefecth buffers, and disable them only if they are enabled.*/
    /* 
    * @violates @ref fls_flash_c_REF_16 Cast from pointer to unsigned long 
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */   
    if(0U == REG_BIT_GET32(FLASH_MSCM_OCMDR0_ADDR32,FLASH_MSCM_OCMDR0_OCMC1_U32)) /* If prefetch is enabled for program flash, OCMDR0[5] == 0 */
    {
        /* 
        * @violates @ref fls_flash_c_REF_16 Cast from pointer to unsigned long 
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */             
        REG_BIT_SET32(FLASH_MSCM_OCMDR0_ADDR32, FLASH_MSCM_OCMDR0_OCMC1_U32); /* Set OCMDR0[5]. Disable PF for program flash */
    }
    /* 
    * @violates @ref fls_flash_c_REF_16 Cast from pointer to unsigned long 
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */  
    if( 0U == REG_BIT_GET32(FLASH_MSCM_OCMDR1_ADDR32,FLASH_MSCM_OCMDR1_OCMC1_U32)) /* If prefetch is enabled for data flash, OCMDR1[5] == 0 */
    {
        /* 
        * @violates @ref fls_flash_c_REF_16 Cast from pointer to unsigned long 
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET32(FLASH_MSCM_OCMDR1_ADDR32, FLASH_MSCM_OCMDR1_OCMC1_U32); /* Set OCMDR1[5]. Disable PF for data flash */
    }
    #endif
#endif /* #ifdef ERR_IPV_FMC_0001 */   
            
#if( FLASH_CHECK_FLEXNVM_RATIO == STD_ON )    
    /* Check FlexNVM Partition Code Ratio is: 0 KB EEPROM backup,64 KB Data flash */
    eFlexNVMConfigurationFlag = Fls_Flash_CheckFlexNvmPartitionRatio();
    
    if( FLASH_E_PARTITION_ERR == eFlexNVMConfigurationFlag )   
    {
        /* FlexNVM is not partitioned for only Data Flash */        
        #if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                             FLS_E_PARTITION_ERR 
                            );
        #endif
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */ 
        return;         
    } 
    /*else
    {
       FlexNVM configured correctly, allocated all to Data flash, no EEPROM. 
    }*/
#endif  /* FLASH_CHECK_FLEXNVM_RATIO == STD_ON */

    /* iterate over all configured sectors (they are allowed to be sorted 
       independently of their physical order) */
    for (u32ConfigIter = 0U; u32ConfigIter < Fls_pConfigPtr->u32SectorCount; u32ConfigIter++ )
    {
        /* This internal sector is configured to be unlocked? */
        if ((1U == (*(Fls_pConfigPtr->paSectorUnlock))[u32ConfigIter]) && (FLS_CH_INTERN ==(*(Fls_pConfigPtr->paHwCh))[u32ConfigIter])) 
        {
            /* Check if sector is protected */
            
            /* Get sector start address. */
            /*
            * @violates @ref fls_flash_c_REF_19 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            u32SecStartAddr = (uint32) (*((*(Fls_pConfigPtr->pSectorList))[u32ConfigIter])).pSectorStartAddressPtr;
            /* Get this sector s associated protection register address and bit position. */
            if( FLASH_E_OK != Fls_Flash_GetFProtReg(u32SecStartAddr, &u32SecRegProtAddr, &u8SecRegProtBitPos) )
            {
                /* Error, invalid sector address. */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */ 
                return;
            }
            
            /*
            * @violates @ref fls_flash_c_REF_19 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            if(0U == REG_BIT_GET8(u32SecRegProtAddr, (uint8)(1U << u8SecRegProtBitPos)) ) 
            {
                /* Error, sector is protected */
                #if( FLS_DEV_ERROR_DETECT == STD_ON )
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, \
                                FLS_E_SECTOR_PROTECTED 
                                );
                #endif
                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                    /*
                    * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                    */ 
                    return;
            }            
            /*else
            {
                Sector OK, available for write/erase.
            }*/
        }
    } /* for (u32ConfigIter = 0U; u32ConfigIter < Fls_pConfigPtr->u32SectorCount; u32ConfigIter++ ) */   
    
    /* if any previous errors exist */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if( REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 ) )
    {
        /* clear the error flags, otherwise CCIF cannot be cleared to launch command */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */        
        REG_WRITE8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_ACCERR_W1C | FLASH_FSTAT_FPVIOL_W1C);
    }   
    
    /* Check(if erase suspended is possible) if any ongoing erase suspended and abort it */
    if( FLASH_E_FAILED == Fls_Flash_AbortSuspended())
    {
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_3_FLS_ABORT_SUSPENDED_KINETIS);
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
        #endif
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */ 
        return;
    }
    /* Finalize any pending operations */
    
    /* If there is any pending operation in the memory controller */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if(0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))
    {
        /* wait for memory controller to finish current operation, as there is no abort 
        possible for write and erase commands*/
        if( FLASH_E_FAILED == Fls_Flash_WaitForOperationFinish() )
        {            
            /* Operation not finished, aborted on timeout */
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */ 
            return;
        }
        /*else 
        {
            Everything OK              
        }*/   
    }
    /*else
    {
        no pending operation
    }*/
}

/**
* @brief          Managing Abort Erase suspend.
* @details        If erase suspend is possible in this array and if there is a pending erase suspended,
*                 abort it. 
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_AbortSuspended( void )
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    
    /* if erase suspend operation is possible within this array */      
    if(Fls_Flash_aArrayList0[0].bEraseSuspPossible)
    {
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_2_FLS_ABORT_SUSPENDED_KINETIS);
        
        /* this array a candidate to be in erase suspend operation state */    
    
        /* if there is a suspended operation in progress */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed 
        * between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(REG_BIT_GET8(FLASH_FCNFG_ADDR32,FLASH_FCNFG_ERSSUSP_U8))
        {
            /* if the memory controller is ready to receive new commands */
            /*
            * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed 
            * between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */ 
            if(REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))
            {
                /* abort the suspended erase */
                /*
                * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed 
                * between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                REG_BIT_CLEAR8(FLASH_FCNFG_ADDR32,FLASH_FCNFG_ERSSUSP_U8);
                
                /* wait for memory controller to finish erase suspended abort operation */
                if( FLASH_E_OK == Fls_Flash_WaitForOperationFinish() )
                {
                    /* everything OK */
                }
                else /* operation not finished, aborted on timeout */
                {
                    eRetVal = FLASH_E_FAILED;
                }
            }
            else    /* memory controller busy */
            {
                /* wait for memory controller to finish current operation */
                if( FLASH_E_OK == Fls_Flash_WaitForOperationFinish() )
                {
                    /* abort the suspended erase */                    
                    /*
                    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
                    * performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
                    * and an integral type
                    */
                     REG_BIT_CLEAR8(FLASH_FCNFG_ADDR32,FLASH_FCNFG_ERSSUSP_U8);
                }
                else /* operation not finished, aborted on timeout */
                {
                    eRetVal = FLASH_E_FAILED;
                }                    
            }                
        }
        /*else
        {
            No suspended erase in this array
        }*/
    }
    /*else
    {
        Erase suspended not possible in this array
    }*/
    return eRetVal;
}

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
/**
* @brief          Check that the addressed flash memory area is erased.
* @details        The function compares the contents of the addressed flash memory 
*                 area against the value of an erased flash cell to check that the block 
*                 has been completely erased
*
* @param[in]      1           pFlashAreaPtr first address of the addressed flash memory area
*                             aligned to the MCU bus width
* @param[in]      2           u32DataLength number of bytes to check (aligned to the bus width)
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK operation succeeded
* @retval         FLASH_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the addressed memory area don't match with value of 
*                 an erased flash cell
*
* @note           Report the FLS_E_VERIFY_ERASE_FAILED Det error when the blank 
*                 check operation failed due to hardware error (ECC) or contents of 
*                 the addressed memory area didn't match with value of an erased 
*                 flash cell
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_VerifyErase
(
    P2CONST(volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength 
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif          
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) pFlashAreaEndPtr = \
           /*
           * @violates @ref fls_flash_c_REF_2 A cast should not be performed
           * between a pointer to object type and a different pointer to object type
           * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
           * only allowed form of pointer arithmetic
           */
           ((const volatile uint8 *)pFlashAreaPtr) + u32DataLength;
  
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eReadStatus = FLASH_E_PENDING;
#endif
 
#if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON)
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
    /* @violates @ref fls_flash_c_REF_22 The comma operator shall not be used */
    Mcal_Trusted_Call(Fls_Flash_InvalidPrefetchBuff_Ram);
#else
    Fls_Flash_InvalidPrefetchBuff_Ram();
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */
#endif 

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    /* Invalidate the cache, in order to display the newly erased flash values */
    /*
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    eCacheRetVal = Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, (uint32)pFlashAreaPtr, u32DataLength);
#endif /* FLS_SYNCRONIZE_CACHE */ 
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( Fls_Flash_pReadAddressPtr = ((const volatile uint8 *)pFlashAreaPtr); ((uint32)Fls_Flash_pReadAddressPtr) < \
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
         /* Compiler_Warning: see fls_c_REF_CW_01 */
         ((uint32)pFlashAreaEndPtr); Fls_Flash_pReadAddressPtr += sizeof(Fls_Flash_DataBusWidthType) \
       )
    {
        Fls_Flash_DataBusWidthType data;
#if( FLS_DSI_HANDLER_API == STD_ON )

        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
       
        /* clear EER flags */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* read flash location */
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */                 
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
       
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }  

        /* Fls_Flash_eReadStatus might have been updated by the exception handler */
        if (FLASH_E_FAILED == Fls_Flash_eReadStatus)
        {
            break;
        }        

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */         
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if( FLS_DSI_HANDLER_API == STD_ON )
        if( FLASH_E_PENDING != Fls_Flash_eReadStatus )
        {
            /* @violates @ref fls_flash_c_REF_17 More than one 'break' terminates loop */
            break;         /* ECC handler has been triggered */
        }
#endif        
        if( FLS_ERASED_VALUE != data )
        {
            /* @violates @ref fls_flash_c_REF_17 More than one 'break' terminates loop */
            break;         /* Read data differs from erased value */
        }
    }
    
    if( Fls_Flash_pReadAddressPtr == pFlashAreaEndPtr )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eReadStatus = FLASH_E_OK;
#endif
    }
    else
    {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_ERASE_FAILED 
                              );
#endif
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eReadStatus = FLASH_E_FAILED;
#else
        eRetVal = FLASH_E_FAILED;
#endif
    }

#if( FLS_DSI_HANDLER_API == STD_ON )
    eRetVal = Fls_Flash_eReadStatus;
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    if((Std_ReturnType)E_OK != eCacheRetVal)
    {
        /* Cache operation invalidation unsuccessful, ignore the ECC and value check status and return failed directly. */
        eRetVal = FLASH_E_FAILED;
    }        
    /*else{
         Cache operation invalidation successful, return the check status(from ECC and value check) 
    }*/
#endif
    
    return eRetVal;
}
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK */

#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
/**
* @brief          Check that the addressed flash memory area is correctly programmed.
* @details        The function compares the contents of the reprogrammed memory area
*                 against the contents of the provided application buffer to check that 
*                 the block has been completely reprogrammed
*
* @param[in]      1           pFlashAreaPtr First address of the addressed flash memory area
*                             aligned to MCU bus width boundary
* @param[in]      2           pUserBufferPtr first address of the application buffer area 
*                             aligned to MCU bus width boundary
* @param[in]      3           DataLength number of bytes to compare aligned to the MCU bus
*                             width
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK operation succeeded
* @retval         FLASH_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the reprogrammed memory area don't match with the 
*                 contents of the provided application buffer
*
* @note           Report the FLS_E_VERIFY_WRITE_FAILED Det error when the verify 
*                 write operation failed due to hardware error (ECC) or contents of 
*                 the reprogrammed memory area didn't match with the contents of 
*                 the provided application buffer
*/
static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_VerifyWrite
(
    P2CONST( volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    P2CONST( Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pUserBufferPtr,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength 
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif             
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) pFlashAreaEndPtr = \
           /*
           * @violates @ref fls_flash_c_REF_2 A cast should not be performed
           * between a pointer to object type and a different pointer to object type
           * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
           * only allowed form of pointer arithmetic
           */
           ((const volatile uint8 *)pFlashAreaPtr) + u32DataLength;

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eCompareStatus = FLASH_E_PENDING;
#endif
    
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    */
    Fls_Flash_pCompareAddressPtr = ((const uint8 *)pUserBufferPtr);

#if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON)
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
    /* @violates @ref fls_flash_c_REF_22 The comma operator shall not be used */
    Mcal_Trusted_Call(Fls_Flash_InvalidPrefetchBuff_Ram);
#else
    Fls_Flash_InvalidPrefetchBuff_Ram();
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE)    
    /* Invalidate cache in order to display the new hardware writes */
    /*
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    eCacheRetVal = Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, (uint32)pFlashAreaPtr, u32DataLength);
#endif /* FLS_SYNCRONIZE_CACHE */     
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( Fls_Flash_pReadAddressPtr = ((const volatile uint8 *)pFlashAreaPtr); ((uint32)Fls_Flash_pReadAddressPtr) < \
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    */
         /* Compiler_Warning: see fls_c_REF_CW_01 */
         ((uint32)pFlashAreaEndPtr); Fls_Flash_pReadAddressPtr += sizeof(Fls_Flash_DataBusWidthType) \
       )
    {
        Fls_Flash_DataBusWidthType data;
#if( FLS_DSI_HANDLER_API == STD_ON )

        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
       
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
       
        /* read flash location */
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */         
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
       
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

        /* Fls_Flash_eCompareStatus might have been updated by the exception handler */
        if (FLASH_E_FAILED == Fls_Flash_eCompareStatus)
        {
            break;
        }

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */         
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if( FLS_DSI_HANDLER_API == STD_ON )
        if( FLASH_E_PENDING != Fls_Flash_eCompareStatus )
        {
            /* @violates @ref fls_flash_c_REF_17 More than one 'break' terminates loop */
            break;         /* ECC handler has been triggered */
        }
#endif        
        /*
        * @violates @ref fls_flash_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        if( data != *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pCompareAddressPtr) )
        {
            /* @violates @ref fls_flash_c_REF_17 More than one 'break' terminates loop */
            break;         /* Read data differs from erased value */
        }
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pCompareAddressPtr += sizeof(Fls_Flash_DataBusWidthType);        
    }
    
    if( Fls_Flash_pReadAddressPtr == pFlashAreaEndPtr )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eCompareStatus = FLASH_E_OK;
#endif
    }
    else
    {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
       (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_WRITE_FAILED 
                             );
#endif
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eCompareStatus = FLASH_E_FAILED;
#else
        eRetVal = FLASH_E_FAILED;
#endif
    }

#if( FLS_DSI_HANDLER_API == STD_ON )
     eRetVal = Fls_Flash_eCompareStatus;
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    if((Std_ReturnType)E_OK != eCacheRetVal)
    {
        /* Cache operation invalidation unsuccessful, ignore the ECC and value check status and return failed directly. */
        eRetVal = FLASH_E_FAILED;
    }        
    /*else{
         Cache operation invalidation successful, return the check status(from ECC and value check) 
    }*/
#endif

    return eRetVal;

}
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */



/**
* @brief          Process ongoing erase hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase
*
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionErase( void )
{
    /* FLASH_JOB_ERASE */
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif 
    
    /* if erase finished */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if(REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))
    {
        /* erase/program high voltage sequence already finished */

        /* Invalidate cache, make the new erase visible */
        #if (STD_ON == FLS_SYNCRONIZE_CACHE)   
        /* Invalidate cache in order to discard any old values from cache, after the hardware erase */
        eCacheRetVal = Mcl_CacheClearMultiLines(  MCL_LMEM_CACHE_ALL, \
                                                  /* @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type */
                                                  /* @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type */
                                                  (uint32)Fls_Flash_pTargetAddressPtr, \
                                                  /* @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type */
                                                  /* @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type */
                                                  (uint32)Fls_Flash_pEndAddressPtr - (uint32)Fls_Flash_pTargetAddressPtr );
        #endif /* FLS_SYNCRONIZE_CACHE */
            
        /* verify that erase operation was successful */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if((0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32, \
            FLASH_FSTAT_RDCOLERR_U8 | FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 | FLASH_FSTAT_MGSTAT0_U8))
            #if (STD_ON == FLS_SYNCRONIZE_CACHE)
            && ((Std_ReturnType)E_OK == eCacheRetVal)
            #endif                  
          )
        {                   
            #if( FLS_ERASE_BLANK_CHECK == STD_ON )
                /* schedule erase blank check of flash sector */
                Fls_eLLDJob = FLASH_JOB_ERASE_BLANK_CHECK;
            #else                    
                /* erase operation succeed */
                Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
                
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            #endif /* FLS_ERASE_BLANK_CHECK == STD_ON */
            /* return */
        }
        else /* errors encountered */
        {
            /* erase operation failed */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /* return */
        }
    }
    else /* erase is still ongoing */
    {
        #if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* Operation in progress, handle possible timeout */
        Fls_u32LLDTimeout_Counter--;
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* erase operation timeout-ed. operations cannot be aborted */
            /* erase operation failed */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
            #endif
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /* return */
        }
        #else
        /* erase/program high voltage sequence didn't finished yet */
        /* wait for another call of Fls_Flash_MainFunction, do nothing */
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }    
}

/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Write
*
* 
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionWrite( void )
{
    /* FLASH_JOB_WRITE */
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif 
    VAR(uint32, AUTOMATIC) u32DataSectorPageSize = 0UL; 
     
    /* if write finished */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if(REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))
    {
        /* erase/program high voltage sequence already finished */

        /* Invalidate cache, make the new erase visible */
        #if (STD_ON == FLS_SYNCRONIZE_CACHE)   
        /* Invalidate cache in order to discard any old values from cache, after the hardware write */
        eCacheRetVal = Mcl_CacheClearMultiLines(  MCL_LMEM_CACHE_ALL, \
                                                  /* @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type */
                                                  /* @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type */
                                                  (uint32)((uint32)Fls_Flash_pTargetAddressPtr - Fls_u32LLDNumberOfStepBack), \
                                                  Fls_u32LLDNumberOfStepBack ); 
        #endif /* FLS_SYNCRONIZE_CACHE */

        /* verify that program operation was successful */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if((0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32, \
            FLASH_FSTAT_RDCOLERR_U8 | FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 | FLASH_FSTAT_MGSTAT0_U8))
            #if (STD_ON == FLS_SYNCRONIZE_CACHE)
            && ((Std_ReturnType)E_OK == eCacheRetVal)
            #endif                  
          ) 
        {
            /* program operation was successful */  
            
            #if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            if( FLASH_E_OK != Fls_Flash_VerifyWrite \
                                ( Fls_Flash_pTargetAddressPtr - (Fls_u32LLDNumberOfStepBack/4U), \
                                  Fls_Flash_pSourceAddressPtr - (Fls_u32LLDNumberOfStepBack/4U), \
                                  Fls_u32LLDNumberOfStepBack \
                                ) 
              )
            {
                /* terminate program operation */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */
                return;
            }
            #endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */ 
            
            /* more page program operation to be performed? */
            if(Fls_Flash_u32ProgramCycle<Fls_Flash_u32DoubleWordToCopy)
            {
                /* continue with next double word program operation */
                #if( FLS_WRITE_BLANK_CHECK == STD_ON )                       
                if( FLASH_E_OK != Fls_Flash_VerifyErase
                                   ( Fls_Flash_pTargetAddressPtr,
                                    /*
                                    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
                                    * only allowed form of pointer arithmetic
                                    */
                                     (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]
                                   ) 
                  )
                {
                    /* terminate program operation */
                    Fls_eLLDJob = FLASH_JOB_NONE;
                    Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                    /*
                    * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                    */
                    return;                
                }
                #endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */

                /* execute page programming */

                /*
                * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
                Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
                Fls_Flash_u32ProgramCycle++;
                u32DataSectorPageSize = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
                Fls_u32LLDRemainingDataToWrite -= u32DataSectorPageSize;
                #if( (FLS_WRITE_VERIFY_CHECK == STD_ON) || (STD_ON == FLS_SYNCRONIZE_CACHE) )
                /* target and source address has been increased by Fls_Flash_PageWrite,
                   so we need a number of step back for both pointer to perform a write 
                   verify check*/
                /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only 
                   allowed form of pointer arithmetic */
                    Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
                #endif 
                
                /* start internal erase/program sequence */
                /*
                * @violates @ref fls_flash_c_REF_19 Conversions shall not be
                * performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
                * and an integral type
                */
                REG_WRITE8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8);

                Fls_eLLDJob = FLASH_JOB_WRITE;
                Fls_eLLDJobResult = MEMIF_JOB_PENDING;
            }
            else
            {
                /* all page program operations succeed */
                
                /* For a Write Job in ASYNC mode check if Fls_u32JobSectorIt should be increased */
                if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->paSectorEndAddr))[Fls_u32JobSectorIt]) ))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;
                }            
                
                /* program operation succeed */
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_OK;
            }
        }
        else
        {
            /* program operation was not successful */
            
            /* program operation failed */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
            /* return */
        }
    }
    else
    {
        #if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* Operation in progress, handle possible timeout */
        Fls_u32LLDTimeout_Counter--;
        if( 0U == Fls_u32LLDTimeout_Counter )
        {
            /* write operation timeout-ed. operations cannot be aborted */
            /* write operation failed */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
            #endif
            Fls_eLLDJob = FLASH_JOB_NONE;
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
        #else
        /* erase/program high voltage sequence didn't finished yet */
        /* wait for another call of Fls_Flash_MainFunction, do nothing */
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    }
}


#if( FLS_ERASE_BLANK_CHECK == STD_ON )
/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase blank Check
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( void, FLS_CODE ) Fls_Flash_MainFunctionEraseBlankCheck( void )
{
    /* FLASH_JOB_ERASE_BLANK_CHECK */

    /*
    * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers
    * that address elements of the same array
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    while ((uint32)Fls_Flash_pTargetAddressPtr < (uint32)Fls_Flash_pEndAddressPtr)
    {
        /*
        * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers
        * that address elements of the same array
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if (((uint32)Fls_Flash_pEndAddressPtr - (uint32)Fls_Flash_pTargetAddressPtr) >= 
              FLS_MAX_ERASE_BLANK_CHECK
           )
        {
            /* at least one erase blank check with FLS_MAX_ERASE_BLANK_CHECK size */
            if( FLASH_E_OK != Fls_Flash_VerifyErase
                                ( Fls_Flash_pTargetAddressPtr,
                                  FLS_MAX_ERASE_BLANK_CHECK
                                ) 
              )
            {
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */
                return;
            }
            /*                           
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pTargetAddressPtr += FLS_MAX_ERASE_BLANK_CHECK/(Fls_Flash_DataBusWidthType)4;
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return;
        }
        else
        {
            /* at least one erase blank check with 4 bytes size */
            if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                ( Fls_Flash_pTargetAddressPtr, \
                                /*
                                * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers
                                * that address elements of the same array
                                * @violates @ref fls_flash_c_REF_15 Cast of complex expression changes signedness
                                * @violates @ref fls_flash_c_REF_23 Conversions shall not be
                                * performed between a pointer to a function and any type other than an integral type
                                * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
                                * and an integral type
                                */
                                  (Fls_LengthType)((uint32)Fls_Flash_pEndAddressPtr - (uint32)Fls_Flash_pTargetAddressPtr) \
                                ) 
              )
            {
                Fls_eLLDJob = FLASH_JOB_NONE;
                Fls_eLLDJobResult = MEMIF_JOB_FAILED;
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */
                return;
            }
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_flash_c_REF_13 Pointer subtraction shall only be applied to pointers
            * that address elements of the same array
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            Fls_Flash_pTargetAddressPtr += ((uint32)Fls_Flash_pEndAddressPtr - (uint32)Fls_Flash_pTargetAddressPtr)/4U;
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return;
        }
    }
    /* erase blank check succeeded */
    Fls_u32JobSectorIt++;   /* The sector was successfully erased, increment the sector iterator.*/
    
    Fls_eLLDJob = FLASH_JOB_NONE;
    Fls_eLLDJobResult = MEMIF_JOB_OK;   
}
#endif

#if (FLS_CANCEL_API == STD_ON )
/**
* @brief          Cancel ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will abort the following jobs:
*                 - Erase
*                 - Write
*                 .
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( void, FLS_CODE ) Fls_Flash_Cancel( void )
{
    /* some hardware job (asynchronous) is pending */
    
    /* Wait for current pending operation to finish, as there is no hardware way to abort it */
    if( FLASH_E_OK == Fls_Flash_WaitForOperationFinish() )
    {
        /* memory idle, no operation is pending */
        Fls_eLLDJob = FLASH_JOB_NONE;
        Fls_eLLDJobResult = MEMIF_JOB_CANCELED;
    }
    /*else 
    {   
        operation not finished, aborted on timeout 
        Cancel of ongoing operation failed 
    }*/
}
#endif /* FLS_CANCEL_API == STD_ON */

/**
* @brief          Erase one complete flash sector.
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           bAsynch Set to TRUE for asynchronous and FALSE for synchronous 
*                             function operation
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            ePhySector must be in range
* @pre            The module must be initialized
*
* @implements     Fls_Flash_SectorErase_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorErase
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) || (STD_ON == FLS_SYNCRONIZE_CACHE) )
    CONST(Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) bAsynch
)
{
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif
    
    Fls_Flash_pTargetAddressPtr = (*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr;
   
    #if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
    Fls_Flash_pEndAddressPtr = \
    /*   
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    ((*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr + (u32PhysicalSectorSize/(Fls_Flash_DataBusWidthType)4));
    #endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
      
      
    /* verify that sector is not protected against erase/program operations */
    
    /* Get this sector s associated protection register address and bit position. */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
    if( FLASH_E_OK != Fls_Flash_GetFProtReg((uint32)Fls_Flash_pTargetAddressPtr, &u32SecRegProtAddr, &u8SecRegProtBitPos) )
    {
        /* Error, invalid sector address. */
                /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }    
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if(0U == REG_BIT_GET8(u32SecRegProtAddr, (uint8)(1U << u8SecRegProtBitPos)) ) 
    {
        /* sector protected: erase operation failed */
                /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }            
    /*else
    {
        Sector OK, available for write/erase.
    }*/

    if ((boolean)FALSE == bAsynch) /* sync */
    {
#if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* Initialize timeout counters */
        Fls_u32LLDTimeout_Counter = FLS_SYNC_ERASE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /* Enter exclusive area which must guarantee that the flash IP resources are not used by another driver. */
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();
        
        /* verify that ERASE SECTOR command may be started */    
        if( FLASH_E_OK != Fls_Flash_CheckCtrlIdle() )
        {
            /* Flash controller is not idle. */
            
                        
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
            
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */      
            return FLASH_E_FAILED;
        }
        
        /* Setup erase operation */      
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        Fls_Flash_LoadFCCOBParams((uint32)Fls_Flash_pTargetAddressPtr, FLASH_CMD_ERASE_SECTOR);
        

        /* start critical section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_11_FLS_FLASH_SECTOR_ERASE);
        
        /* call flash access code routine */
#if( FLS_TIMEOUT_HANDLING == STD_ON )
        /*
        * @violates @ref fls_flash_c_REF_14 Taking address of near auto variable.
        * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long  
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type        
        */        
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_AcErasePtrType)(FTFE_BASEADDR, Fls_pConfigPtr->acCallBackPtr, &Fls_u32LLDTimeout_Counter);
#else
        /* 
        * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long 
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_AcErasePtrType)(FTFE_BASEADDR, Fls_pConfigPtr->acCallBackPtr);
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_12_FLS_FLASH_SECTOR_ERASE);
        
        /* end critical section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }  
    
        /* Invalidate cache, make the new writes visible */
        #if (STD_ON == FLS_SYNCRONIZE_CACHE)    
        /* Invalidate cache in order to discard any un-finalized hardware write */                                                          
        /*
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        eCacheRetVal = Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, (uint32)Fls_Flash_pTargetAddressPtr, u32PhysicalSectorSize);
        #endif /* FLS_SYNCRONIZE_CACHE */ 
    
        /* verify that erase operation was successful */
        
#if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* check all error flags */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if((0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32, \
            FLASH_FSTAT_RDCOLERR_U8 | FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 | FLASH_FSTAT_MGSTAT0_U8))
            #if (STD_ON == FLS_SYNCRONIZE_CACHE)
            && ((Std_ReturnType)E_OK == eCacheRetVal)
            #endif               
            && (0U != Fls_u32LLDTimeout_Counter)  
          )         
#else
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if((0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32, \
            FLASH_FSTAT_RDCOLERR_U8 | FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 | FLASH_FSTAT_MGSTAT0_U8))
            #if (STD_ON == FLS_SYNCRONIZE_CACHE)
            && ((Std_ReturnType)E_OK == eCacheRetVal)
            #endif                  
        )
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */        
        {
            /* erase operation succeed */
                        
            #if( FLS_ERASE_BLANK_CHECK == STD_ON )
            if( FLASH_E_OK != Fls_Flash_VerifyErase(Fls_Flash_pTargetAddressPtr, u32PhysicalSectorSize) )
            {                

                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */
                return FLASH_E_FAILED;
            }
            #endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        
            /*
            * @violates @ref fls_flash_c_REF_6 Return statement before end of function.
            */         
            return FLASH_E_OK;
        }
        else
        {
            /* erase operation failed */

            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
            
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_FAILED;
        }
    }
    else /* bAsynch == TRUE */
    {        
        /* verify that ERASE SECTOR command may be started */    
        if( FLASH_E_OK != Fls_Flash_CheckCtrlIdle() )
        {
            /* Flash controller is not idle. */
            
                                    
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */      
            return FLASH_E_FAILED;
        }
        
        /* Setup erase operation */      
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        Fls_Flash_LoadFCCOBParams((uint32)Fls_Flash_pTargetAddressPtr, FLASH_CMD_ERASE_SECTOR);
        
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8);
        
        /* schedule async job check for Fls_Flash_MainFunction */
        Fls_eLLDJob = FLASH_JOB_ERASE;
        Fls_eLLDJobResult = MEMIF_JOB_PENDING;
        
#if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* Initialize timeout counter */
        Fls_u32LLDTimeout_Counter = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */        
        
        /*
        * @violates @ref fls_flash_c_REF_6 Return statement before end of function.
        */
        return FLASH_E_PENDING;                
    }
}

/**
* @brief          Write one or more complete flash pages into given flash sector.
*
* @param[in]      ePhySector Physical sector ID
* @param[in]      u32SectorOffset sector offset in bytes
* @param[in]      u32DataLength data length in bytes
* @param[in]      pDataPtr data to be written
* @param[in]      bAsynch set to TRUE for asynchronous and FALSE for synchronous function operation
*
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            u32SectorOffset must be double word aligned
* @pre            u32DataLength must be multiple double word length
* @pre            ePhySector must be in range
* @pre            The module must be initialized
*
* @implements     Fls_Flash_SectorWrite_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorWrite
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
)
{
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif    
    VAR(uint32, AUTOMATIC) u32DataSectorPageSize = 0UL;
    
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    */
    Fls_Flash_pSourceAddressPtr = (const uint32*)(pDataPtr);
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_pTargetAddressPtr = (*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr + \
                               (u32SectorOffset/4U);    
    
    Fls_u32LLDRemainingDataToWrite = u32DataLength;
        
    /* verify that sector is not protected against erase/program operations */
    
    /* verify that sector is not protected against erase/program operations */
    
    /* Get this sector s associated protection register address and bit position. */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
    if( FLASH_E_OK != Fls_Flash_GetFProtReg((uint32)Fls_Flash_pTargetAddressPtr, &u32SecRegProtAddr, &u8SecRegProtBitPos) )
    {
        /* Error, invalid sector address. */
                /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }    
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if(0U == REG_BIT_GET8(u32SecRegProtAddr, (uint8)(1U << u8SecRegProtBitPos)) ) 
    {
        /* sector protected: program operation failed */
                /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }            
    /*else
    {
        Sector OK, available for write/erase.
    }*/
        

    /* Number of double words (i.e.64bits=8bytes) to be copied  */
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_u32DoubleWordToCopy = u32DataLength/(*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
    Fls_Flash_u32ProgramCycle = 0U;

    if ((boolean)FALSE == bAsynch) /* sync */
    {    
        /* process all double word program operations */
        /*for( Fls_Flash_u32ProgramCycle=0U; Fls_Flash_u32ProgramCycle < Fls_Flash_u32DoubleWordToCopy; \
             Fls_Flash_u32ProgramCycle++ )*/
        while (Fls_Flash_u32ProgramCycle < Fls_Flash_u32DoubleWordToCopy)
        {         
            /* Enter exclusive area which must guarantee that the flash IP resources are not used by another driver. */
            SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00();   
               
            /* verify that PROGRAM command may be started */    
            if( FLASH_E_OK != Fls_Flash_CheckCtrlIdle() )
            {
                /* Flash controller is not idle. */
                
                                
                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
                
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */      
                return FLASH_E_FAILED;
            }   
             
            #if( FLS_WRITE_BLANK_CHECK == STD_ON )
            /* check the memory location for being erased before attempting to write it */
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only 
               allowed form of pointer arithmetic */
            if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                ( Fls_Flash_pTargetAddressPtr, \
                                 (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt] \
                                ) 
              )
            {
                /* verify erase failed */

                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        
                /* @violates @ref fls_flash_c_REF_5 Return statement before end of function. */
                return FLASH_E_FAILED;                
            }
            #endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */ 
               
            /* double word programming */
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
            Fls_Flash_u32ProgramCycle++;
            u32DataSectorPageSize = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
            Fls_u32LLDRemainingDataToWrite -= u32DataSectorPageSize;
            #if( (FLS_WRITE_VERIFY_CHECK == STD_ON) || (STD_ON == FLS_SYNCRONIZE_CACHE) )
            /* target and source address has been increased by Fls_Flash_PageWrite,
               so we need a number of step back for both pointer to perform a write 
               verify check*/
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only 
               allowed form of pointer arithmetic */
               Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
            #endif
                        
            #if( FLS_TIMEOUT_HANDLING == STD_ON )
            /* Initialize timeout counters */
            Fls_u32LLDTimeout_Counter = FLS_SYNC_WRITE_TIMEOUT_VALUE;
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */

                /* start flash access section: implementation depends on integrator */
            if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
            {
                /* Call FlsStartFlashAccessNotif function if configured */
                Fls_pConfigPtr->startFlashAccessNotifPtr();
            }
            
            MCAL_FAULT_INJECTION_POINT(FLS_FIP_13_FLS_FLASH_SECTOR_WRITE);
            
            /* call flash access code routine */
            #if( FLS_TIMEOUT_HANDLING == STD_ON )
            /*
            * @violates @ref fls_flash_c_REF_14 Taking address of near auto variable.
            * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type            
            */        
            FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_AcWritePtrType)(FTFE_BASEADDR, Fls_pConfigPtr->acCallBackPtr, &Fls_u32LLDTimeout_Counter);
            #else
            /*
            * @violates @ref fls_flash_c_REF_18 Cast from pointer to unsigned long 
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_AcWritePtrType)(FTFE_BASEADDR, Fls_pConfigPtr->acCallBackPtr);
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */               

            MCAL_FAULT_INJECTION_POINT(FLS_FIP_14_FLS_FLASH_SECTOR_ERASE);
            
            /* end flash access section: implementation depends on integrator */
            if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
            {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
            }  
            
            /* Invalidate cache, make the new writes visible */
            #if (STD_ON == FLS_SYNCRONIZE_CACHE)    
            /* Invalidate the flash, before the read access */                                                          
            /*
            * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */
            eCacheRetVal = Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, (uint32)Fls_Flash_pTargetAddressPtr, (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
            #endif /* FLS_SYNCRONIZE_CACHE */ 
    
            /* verify that program operation was successful */
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
#if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* check all error flags */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if((0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32, \
            FLASH_FSTAT_RDCOLERR_U8 | FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 | FLASH_FSTAT_MGSTAT0_U8))
            #if (STD_ON == FLS_SYNCRONIZE_CACHE)
            && ((Std_ReturnType)E_OK == eCacheRetVal)
            #endif                
            && (0U != Fls_u32LLDTimeout_Counter)
            )        
#else
            /*
            * @violates @ref fls_flash_c_REF_19 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            if((0U == REG_BIT_GET8(FLASH_FSTAT_ADDR32, \
                FLASH_FSTAT_RDCOLERR_U8 | FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8 | FLASH_FSTAT_MGSTAT0_U8))
                #if (STD_ON == FLS_SYNCRONIZE_CACHE)
                && ((Std_ReturnType)E_OK == eCacheRetVal)
                #endif                 
                )
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */               
            {    
                /* program operation succeed */
                
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                if( FLASH_E_OK != Fls_Flash_VerifyWrite
                                     ( /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only 
                                           allowed form of pointer arithmetic */
                                            Fls_Flash_pTargetAddressPtr - (Fls_u32LLDNumberOfStepBack/4U),
                                        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only 
                                           allowed form of pointer arithmetic */
                                            Fls_Flash_pSourceAddressPtr - (Fls_u32LLDNumberOfStepBack/4U),
                                            Fls_u32LLDNumberOfStepBack
                                     ) 
                  )
                {

                    SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
                    
                    /*
                    * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                    */
                    return FLASH_E_FAILED;
                }
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */     
                
                /* Verify Write succeeded, continue with next double word program operation */
            }
            else
            {
                /* program operation failed */

                SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
                
                /*
                * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
                */
                return FLASH_E_FAILED;
            }
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00();
        }
        
        /* all double word program operations succeed */
        /* program operation succeed */
        /*
        * @violates @ref fls_flash_c_REF_6 Return statement before end of function.
        */
        return FLASH_E_OK;
    }
    else /* bAsynch */
    {    
        /* first double word program operation */
        Fls_Flash_u32ProgramCycle=0U;
           
        /* verify that PROGRAM command may be started */    
        if( FLASH_E_OK != Fls_Flash_CheckCtrlIdle() )
        {
            /* Flash controller is not idle. */
            
                                    
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */      
            return FLASH_E_FAILED;
        }
        
        #if( FLS_WRITE_BLANK_CHECK == STD_ON )
        if( FLASH_E_OK != 
            Fls_Flash_VerifyErase(Fls_Flash_pTargetAddressPtr,
                                  /*
                                  * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
                                  * only allowed form of pointer arithmetic
                                  */
                                  (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]
                                 ) 
          )
        {
            /* verify erase failed */
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_FAILED;                
        }
        #endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
           
        
        /*It is time to do word or double word programming */
        Fls_Flash_PageWrite((*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt]);
        Fls_Flash_u32ProgramCycle++;
        u32DataSectorPageSize = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
        Fls_u32LLDRemainingDataToWrite -= u32DataSectorPageSize;
#if( (FLS_WRITE_VERIFY_CHECK == STD_ON) || (STD_ON == FLS_SYNCRONIZE_CACHE) )
            /* target and source address has been increased by Fls_Flash_PageWrite,
               so we need a number of step back for both pointer to perform a write 
               verify check*/
            /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only 
               allowed form of pointer arithmetic */
            Fls_u32LLDNumberOfStepBack = (*(Fls_pConfigPtr->paSectorPageSize))[Fls_u32JobSectorIt];
#endif
        /* start internal erase/program sequence */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FSTAT_ADDR32, FLASH_FSTAT_CCIF_U8);
         
        Fls_eLLDJob = FLASH_JOB_WRITE;
        Fls_eLLDJobResult = MEMIF_JOB_PENDING;

#if( FLS_TIMEOUT_HANDLING == STD_ON )
        /* Initialize timeout counter */
        Fls_u32LLDTimeout_Counter = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /*
        * @violates @ref fls_flash_c_REF_6 Return statement before end of function.
        */
        return FLASH_E_PENDING;
    }
}

/**
* @brief          Execute an interlock write and next program.
*
* @param[in]      1           TotalBytes Total number of bytes to program
*
*/
static FUNC( void, FLS_CODE ) Fls_Flash_PageWrite
( CONST(uint32, AUTOMATIC) u32TotalBytes )
{    
    VAR( Fls_AddressType, AUTOMATIC) u32FTFEAddr = 0UL;
    uint32 u32Counter;
 
 /* setup write operation */
    
    /* convert system memory map address to FTFE module address */
    /*
    * @violates @ref fls_flash_c_REF_16 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    u32FTFEAddr = Fls_Flash_ConvertSysToFTFEAddr((uint32)Fls_Flash_pTargetAddressPtr);
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    REG_WRITE8(FLASH_FCCOB0_ADDR32, FLASH_CMD_PROGRAM_PHRASE ); /* Program Phrase (8 bytes) */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */    
    REG_WRITE8(FLASH_FCCOB1_ADDR32, (uint8)(u32FTFEAddr >> 16U)); /* Flash address [23:16] */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */    
    REG_WRITE8(FLASH_FCCOB2_ADDR32, (uint8)(u32FTFEAddr >> 8U));  /* Flash address [15:8] */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    REG_WRITE8(FLASH_FCCOB3_ADDR32, (uint8)(u32FTFEAddr >> 0U));   /* Flash address [7:0] */     
    
    MCAL_FAULT_INJECTION_POINT(FLS_FIP_4_FLS_FLASH_SECTOR_WRITE_KINETIS);
    /* load page (8 bytes) into command object */
    for (u32Counter=0UL; u32Counter < (u32TotalBytes/8U); u32Counter++)
    {
        /* load first 4 bytes */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOB4_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 24U));
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOB5_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 16U));
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOB6_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 8U));
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOB7_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 0U));     
        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
        Fls_Flash_pTargetAddressPtr++;
        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
        Fls_Flash_pSourceAddressPtr++;
        
        /* load last 4 bytes */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOB8_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 24U));
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOB9_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 16U));
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_WRITE8(FLASH_FCCOBA_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 8U));
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */        
        REG_WRITE8(FLASH_FCCOBB_ADDR32, (uint8)((*Fls_Flash_pSourceAddressPtr) >> 0U));
        
        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
        Fls_Flash_pTargetAddressPtr++;
        /* @violates @ref fls_flash_c_REF_10 Array indexing shall be the only allowed form of pointer arithmetic */
        Fls_Flash_pSourceAddressPtr++;
    }      
}

/**
* @brief          Calculate length of initial 8-bit flash read.
* @details        Calculate number of bytes to read from flash until
*                 the source pointer is aligned to the data  width and
*                 optimized wide (32-bit or 64-bit) flash reads can begin
*
* @param[in]      1           pSourceAddrPtr Source pointer
* @param[in]      2           TotalBytes Total number of bytes to read
*
* @return         u32Length of initial 8-bit flash reads in bytes
*/
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcInitDataLength
( 
    CONSTP2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) volatile pSourceAddrPtr,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
)
{
    /* Calc length of initial 8-bit transfer */
    VAR(uint32, AUTOMATIC) u32Length = 
        /*
        * @violates @ref fls_flash_c_REF_23 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        ( (uint32)pSourceAddrPtr ) & ( sizeof(Fls_Flash_DataBusWidthType) - 1UL );
    
    if ( u32Length != 0U )
    {
        u32Length = sizeof(Fls_Flash_DataBusWidthType) - u32Length;
    }
    else
    {
        /* u32Length == 0 */
    }

    if( u32Length > u32TotalBytes ) 
    {
        u32Length = u32TotalBytes;
    }
    else
    {
        /* u32Length <=  u32TotalBytes */
    }
    
    return u32Length;
}

/**
* @brief          Calculate length of optimized wide flash reads.
* @details        Calculate number of bytes to read from flash until
*                 the source pointer is not aligned to the data bus width
*
* @param[in]      1           u32InitDataLength Calculated by Fls_Flash_CalcInitDataLength
* @param[in]      2           u32TotalBytes Total number of bytes to read
*
* @return         u32Length of optimized 32-bit or 64-bit flash reads in bytes
*/
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcWideDataLength
(
    CONST(uint32, AUTOMATIC) u32InitDataLength,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
)
{
    VAR(uint32, AUTOMATIC) u32Length =
        (( u32TotalBytes - u32InitDataLength ) & (~( sizeof(Fls_Flash_DataBusWidthType) - 1UL )));

    return u32Length;
}

/**
* @brief          Check if the flash controller is idle.
*                 If the controller is idle, also checks and clears any previous pending errors.
*                 If the controller is not idle, it returns failed and reports a DEM error.
*
* @param[in]      none
*
* @return         FLASH_E_OK     - Controller is idle, ready to accept new commands.
*                 FLASH_E_FAILED - Controller is busy, unable to accept new commands.
*/
static FUNC(Fls_LLDReturnType, FLS_CODE) Fls_Flash_CheckCtrlIdle(void)
{
    VAR( Fls_LLDReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    
    /* Check if the flash controller is idle, by polling the CCIF status bit. */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if( REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_CCIF_U8))
    {
        /* OK, memory controller is idle */
        
        /* if any previous errors exist */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        if(REG_BIT_GET8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_ACCERR_U8 | FLASH_FSTAT_FPVIOL_U8))
        {
            /* clear the error flags, otherwise CCIF cannot be cleared to launch command */
            /*
            * @violates @ref fls_flash_c_REF_19 Conversions shall not be
            * performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            REG_WRITE8(FLASH_FSTAT_ADDR32,FLASH_FSTAT_ACCERR_W1C | FLASH_FSTAT_FPVIOL_W1C);
        }
        eRetVal = FLASH_E_OK;
    }
    else /* error, another operation is in progress*/
    {
        /*  Flash hardware operation may not be started, modify operation already in progress */
        
        eRetVal = FLASH_E_FAILED;        
    }
    
    return eRetVal;
}

static FUNC(void, FLS_CODE) Fls_Flash_LoadFCCOBParams
(
    CONST(Fls_AddressType, AUTOMATIC) u32PhyTargetAddr,
    CONST(uint8, AUTOMATIC) u8FCCOBCmdId
)
{
    VAR( Fls_AddressType, AUTOMATIC) u32FTFEAddr = 0UL;
    
    /* convert system memory map address to FTFE module address */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */ 
    u32FTFEAddr = Fls_Flash_ConvertSysToFTFEAddr(u32PhyTargetAddr);
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */    
    REG_WRITE8(FLASH_FCCOB0_ADDR32,u8FCCOBCmdId); /* Erase Flash Sector */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    REG_WRITE8(FLASH_FCCOB1_ADDR32, (uint8)(u32FTFEAddr >> 16UL)); /* Flash address [23:16] */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    REG_WRITE8(FLASH_FCCOB2_ADDR32, (uint8)(u32FTFEAddr >> 8UL));  /* Flash address [15:8] */
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    REG_WRITE8(FLASH_FCCOB3_ADDR32, (uint8)(u32FTFEAddr >> 0UL));  /* Flash address [7:0] */
}

static FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_GetFProtReg
( 
    VAR( Fls_AddressType, AUTOMATIC) u32SectStartAddr,  
    P2VAR( Fls_AddressType, AUTOMATIC, FLS_APPL_DATA ) pu32RegAddr, 
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pu8BitProtNo 
)
{
    VAR( uint32, AUTOMATIC) u32FlexNvmPartSize = 0UL;
    VAR( uint32, AUTOMATIC) u32DFlashSize = 0UL;
    VAR( uint32, AUTOMATIC) u32PFlashSize = 0UL;
    VAR( uint32, AUTOMATIC) u32DFlashBitSize = 0UL;     /* The amount of Dflash size which is covered by a bit in a protection register, which is the total amount of Pflash divided by 8. */
    VAR( uint32, AUTOMATIC) u32PFlashBitSize = 0UL;     /* The amount of Pflash size which is covered by a bit in a protection register, which is the total amount of Pflash divided by 32. */
    VAR( uint32, AUTOMATIC) u32PFlashRegSize = 0UL;     /* The amount of Pflash size which is covered by a protection register, which is the total amount of Pflash divided by 4. */
    VAR( uint8, AUTOMATIC)  u8RegProtNo = 0U;
    VAR( Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
   
    /* Determine the PFlash size. */
#if (0x180000UL == P_FLASH_SIZE ) /* 2048K device */
    /* For 2048K device, the PFlash size, which is 1.5K has to be rounded to 2K. */
    u32PFlashSize = 0x200000UL;
#else
    u32PFlashSize = P_FLASH_SIZE;
#endif
    
    /* Determine the DFlash size. Get the amount of flash allocated to FlexNVM/EEPROM partition, which has to be subtracted from the current Dflash size. */
    /* 
    * @violates @ref fls_flash_c_REF_16 Cast from pointer to unsigned long 
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    u32FlexNvmPartSize = (uint32)(REG_BIT_GET32(FLASH_SIM_FCFG1_ADDR32,FLASH_SIM_FCFG1_DEPART_U32) >> 12U );

 /* Special partition codes for 2048K device. */
#if (0x10000UL < D_FLASH_SIZE )
    if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V1) ||
            (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_512_0_V2)
      )
    {
         /* FlexNvm configured for all Data Flash (no EEPROM partitioned) */
        u32DFlashSize = D_FLASH_SIZE;   /*0x80000, 512K*/
    } 
    else if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_448_64_V1) )
    {
         /* FlexNvm configured for all Data Flash (no EEPROM partitioned) */
        u32DFlashSize = 0x70000UL;  /* 448K */
    }
    else
    {
        u32DFlashSize = 0U;     /* Error case, should not be taken. */
    }
    
#else
    /* 256K, 512K, 1024K devices. */
    if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V1) ||
        (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V2) ||
        (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_64_0_V3) ||
        (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V1) ||
        (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_32_0_V2)
      )
    {
        /* FlexNvm configured for all Data Flash (no EEPROM partitioned) */
        u32DFlashSize = D_FLASH_SIZE;
    } 
    else if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V1) ||
             (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_32_32_V2)
           )
    {
         /* FlexNvm configured for all Data Flash (no EEPROM partitioned) */
        u32DFlashSize = 0x8000UL;  /* 32K */
    }
    else if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_16_48_V1) )
    {
         /* FlexNvm configured for all Data Flash (no EEPROM partitioned) */
        u32DFlashSize = 0x4000UL;  /* 16K */
    }
    else if( (u32FlexNvmPartSize == FLASH_FLEXNVM_DFLASH_EEPROM_8_24_V1) )
    {
         /* FlexNvm configured 8K Data Flash (24K EEPROM partitioned) */
        u32DFlashSize = 0x2000UL;  /* 8K */
    }
    else
    {
        /*FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V1*/
        /*FLASH_FLEXNVM_DFLASH_EEPROM_0_64_V2*/
        /*FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V1*/
        /*FLASH_FLEXNVM_DFLASH_EEPROM_0_32_V2*/
        u32DFlashSize = 0U;     /* No data flash configured. */
    }
#endif /*#if (0x10000UL < D_FLASH_SIZE )*/
        
    /* Determine if it is a Pflash or Dflash data sector. */
    if( u32SectStartAddr >= (P_FLASH_BASE_ADDR + P_FLASH_SIZE))                /* if NOT a P-FLASH addr... */     
    {
        if( (u32SectStartAddr < D_FLASH_BASE_ADDR) ||               
            (u32SectStartAddr >= (D_FLASH_BASE_ADDR + D_FLASH_SIZE))            /* ...and also NOT a D-FLASH addr... */
          ) 
        {
            /* invalid flash address */
            eRetVal = FLASH_E_FAILED;      
        }
        else 
        {
            /* DATA flash sector */            
            
            if( 0UL != u32DFlashSize )
            {
                *pu32RegAddr = FLASH_FDPROT_ADDR32;     /* There is a single prot register for all DATA flash sectors. */
                u32DFlashBitSize = u32DFlashSize/8U;    /* Each bit in the FDPROT register protects an 8th of the available Dflash. */  
                *pu8BitProtNo = (uint8)( (u32SectStartAddr - D_FLASH_BASE_ADDR) / u32DFlashBitSize );
            }
            else
            {
                /* No Dflash configured, although this sector is supposed to be a DFlash one. */
                eRetVal = FLASH_E_FAILED;
            }
        }
    }
    else
    {
        /* PROGRAM flash sector */
        
        /* There are four prot registers for PROGRAM flash sectors, the right one has to be determined. Find in which reg prot register this sector belongs. */
               
        u32PFlashRegSize = u32PFlashSize / 4U;              /* Determine the Pflash size which is protected by a register. */
        u8RegProtNo = (uint8)(u32SectStartAddr / u32PFlashRegSize);  /* Determine in which of the four protection regions the current address resides. */
        
        if(0U == u8RegProtNo)
        {
            *pu32RegAddr = FLASH_FPROT3_ADDR32;     /* This sector resides in the first protection region, starting from 0x0000_0000, FPROT3[PROT0] - FPROT3[PROT7]. */
        }
        else if(1U == u8RegProtNo)
        {
            *pu32RegAddr = FLASH_FPROT2_ADDR32;     /* This sector resides in the second protection region, starting from, FPROT2[PROT8] - FPROT2[PROT15]. */
        }
        else if(2U == u8RegProtNo)
        {
            *pu32RegAddr = FLASH_FPROT1_ADDR32;
        }
        else if(3U == u8RegProtNo)
        {
            *pu32RegAddr = FLASH_FPROT0_ADDR32;
        }
        else
        {
            /* Empty clause to fulfill MISRA. */
        }
        
        /* Compute the protection region size depending on the P-FLASH size. */       
#if (0x40000UL == P_FLASH_SIZE)
        u32PFlashBitSize = 8192UL;      /* Each bit protects 8KB regions */
#endif 
#if (0x80000UL == P_FLASH_SIZE)
        u32PFlashBitSize = 16384UL;     /* Each bit protects 16KB regions */
#endif
#if (0x100000UL == P_FLASH_SIZE)
        u32PFlashBitSize = 32768UL;     /* Each bit protects 32KB regions */
#endif
#if (0x180000UL == P_FLASH_SIZE)
        u32PFlashBitSize = 65536UL;     /* Each bit protects 64KB regions */
#endif        
        
        *pu8BitProtNo = (uint8)((u32SectStartAddr % u32PFlashRegSize) / u32PFlashBitSize);
    }
    
    return eRetVal;
}


/**
* @brief          Read one or more bytes from given flash sector
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           u32SectorOffset sector offset in bytes
* @param[in]      3           u32DataLength data length in bytes
* @param[out]     pDataPtr     where read data to be written
*
* @return Fls_LLDReturnType
* @retval FLASH_E_OK Operation succeeded
*
* @implements     Fls_Flash_SectorRead_Activity
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorRead
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    VAR(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif 
 
    /* Physical flash address to read */
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_pReadAddressPtr = (volatile const uint8 *)((*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr) + \
                              u32SectorOffset;
    
    /* End of read pointer */
    
#if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON)
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
    /* @violates @ref fls_flash_c_REF_22 The comma operator shall not be used */
    Mcal_Trusted_Call(Fls_Flash_InvalidPrefetchBuff_Ram);
#else
    Fls_Flash_InvalidPrefetchBuff_Ram();
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */
#endif
    
#if (STD_ON == FLS_SYNCRONIZE_CACHE)        
    /* Invalidate flash, before the flash read access */                                                         
    /*
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    eCacheRetVal = Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, (uint32)Fls_Flash_pReadAddressPtr, u32DataLength);
#endif /* MCAL_CACHE_RUNTIME_MNGMNT */              

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eReadStatus = FLASH_E_PENDING;
    
    /* Initial 8-bit flash read (until the data bus alignment boundary) */ 
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_7 Booleans operands are not used for logical operators '&&', '||' and '!' 
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    while ((4U <= u32DataLength ) && ((0U != ( (uint32)pDataPtr % 4U )) || (0U != ( (uint32)Fls_Flash_pReadAddressPtr % 4U ))) && ( FLASH_E_PENDING == Fls_Flash_eReadStatus ))
#else
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    while ((4U <= u32DataLength ) && ((0U != ((uint32)pDataPtr % 4U )) || (0U != ((uint32)Fls_Flash_pReadAddressPtr % 4U ))))
#endif    
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flag */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;      
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }     
#else
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;
#endif
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pDataPtr++;
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pReadAddressPtr++;
        u32DataLength -= 1U;
    }

    /* Data bus width transfer */    
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    while ((4U <= u32DataLength) && (FLASH_E_PENDING == Fls_Flash_eReadStatus))
#else
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    while (4U <= u32DataLength)
#endif    
    {
        /*
        * @violates @ref fls_flash_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flag */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type */
        *( uint32*)(pDataPtr) = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }
#else
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type */
        *( uint32*)(pDataPtr) = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pDataPtr += sizeof(Fls_Flash_DataBusWidthType);
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pReadAddressPtr += sizeof(Fls_Flash_DataBusWidthType);
        u32DataLength -= 4U;
    }
    
    /* Final 8-bit transfer */
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )    
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    while ((0U < u32DataLength) && (FLASH_E_PENDING == Fls_Flash_eReadStatus))
#else
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    while (0U < u32DataLength)
#endif    
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }
#else
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;
#endif
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pDataPtr++;
        /*
        * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pReadAddressPtr++;
        u32DataLength -= 1U;
    }

#if( FLS_DSI_HANDLER_API == STD_ON )    
    if( FLASH_E_PENDING == Fls_Flash_eReadStatus )
    {
        Fls_Flash_eReadStatus = FLASH_E_OK;
    }
    
    eRetVal = Fls_Flash_eReadStatus;
#else
    eRetVal = FLASH_E_OK;
#endif    

#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    if((Std_ReturnType)E_OK != eCacheRetVal)
    {
        /* Cache operation invalidation unsuccessful, ignore the ECC and value check status and return failed directly. */
        eRetVal = FLASH_E_FAILED;
    }        
    /*else{
         Cache operation invalidation successful, return the check status(from ECC and value check) 
    }*/
#endif

    return eRetVal;
}

#if(( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
/**
* @brief          Compare data buffer with content of given flash sector.
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           u32SectorOffset sector offset in bytes
* @param[in]      3           u32DataLength data length in bytes
* @param[in]      4           pDataPtr data to be compared
*                 
* @return         Fls_LLDReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_BLOCK_INCONSISTENT Data buffer doesn't match with content of flash sector
*
* @implements     Fls_Flash_SectorCompare_Activity
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/ 
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_Flash_SectorCompare
(
    CONST( Fls_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr
)
{
    VAR(uint32, AUTOMATIC) u32InitDataLength = 0UL;
    VAR(uint8, AUTOMATIC) Fls_Flash_u8ReadAddress8 = 0U;
    VAR(uint32, AUTOMATIC) Fls_Flash_u32ReadAddress32 = 0UL;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) pReadAddressEndPtr = NULL_PTR;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) pReadBlockAddressEndPtr = NULL_PTR;
#if (STD_ON == FLS_SYNCRONIZE_CACHE)
    VAR(Std_ReturnType, AUTOMATIC) eCacheRetVal = (Std_ReturnType)E_OK;
#endif             
    
    /* Physical flash address to read */
    /*
    * @violates @ref fls_flash_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_pReadAddressPtr = (volatile const uint8 *)((*((*(Fls_pConfigPtr->pSectorList))[ePhySector])).pSectorStartAddressPtr) + \
                              u32SectorOffset;
#if (FLS_BLANK_CHECK_API == STD_ON)                              
    if (NULL_PTR == pDataPtr)
    {  
        /* BLANK_CHECK API */
        /* 
        *  @violates @ref fls_flash_c_REF_2 A cast should not be performed
        *  between a pointer to object type and a different pointer to object type 
        */ 
        Fls_Flash_pCompareAddressPtr = (volatile const uint8 *) &Fls_Flash_ErasedValue;
    }
    else
#endif   
    {
        /* COMPARE API */
        Fls_Flash_pCompareAddressPtr = pDataPtr;
    }
        
    /* End of read pointer */
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadAddressEndPtr = Fls_Flash_pReadAddressPtr + u32DataLength;
    
    /* Calculate end address of initial 8-bit transfer */
    u32InitDataLength = Fls_Flash_CalcInitDataLength( Fls_Flash_pReadAddressPtr, u32DataLength );
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadBlockAddressEndPtr = Fls_Flash_pReadAddressPtr + u32InitDataLength;

    
#if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON)
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
    /* @violates @ref fls_flash_c_REF_22 The comma operator shall not be used */
    Mcal_Trusted_Call(Fls_Flash_InvalidPrefetchBuff_Ram);
#else
    Fls_Flash_InvalidPrefetchBuff_Ram();
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */
#endif
    
#if (STD_ON == FLS_SYNCRONIZE_CACHE) 
    /* Invalidate the flash, before the read access */                                                          
    /*
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    eCacheRetVal = Mcl_CacheClearMultiLines(MCL_LMEM_CACHE_ALL, (uint32)Fls_Flash_pReadAddressPtr, u32DataLength);
    if( (Std_ReturnType)E_OK != eCacheRetVal )
    { 
        /*
        * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_BLOCK_INCONSISTENT;
    }
#endif /* FLS_SYNCRONIZE_CACHE */  

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eCompareStatus = FLASH_E_PENDING;
    
    /* Initial 8-bit flash read (until the data bus alignment boundary) */ 
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr) ) && \
         ( Fls_Flash_eCompareStatus == FLASH_E_PENDING ); Fls_Flash_pReadAddressPtr++ \
       )
#else
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr); Fls_Flash_pReadAddressPtr++)
#endif    
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flag */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }
#else
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
#endif
        /*
        * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *Fls_Flash_pCompareAddressPtr != Fls_Flash_u8ReadAddress8 )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            { 
                Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_Flash_eCompareStatus != FLASH_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_BLOCK_INCONSISTENT;
#endif            
        }
        else
        {
            /* *Fls_Flash_pCompareAddressPtr == *Fls_Flash_pReadAddressPtr */
        }
        #if (FLS_BLANK_CHECK_API == STD_ON)         
        if (NULL_PTR == pDataPtr)
        {  
            /* BLANK_CHECK API */
        }
        else
#endif 
        {
            /* COMPARE API */
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pCompareAddressPtr++;
        }
    }

    /* Calculate end address of wide 32-bit or 64-bit flash read */
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadBlockAddressEndPtr += Fls_Flash_CalcWideDataLength( u32InitDataLength, u32DataLength );

    /* Data bus width transfer */    
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr) ) && \
         /*
         * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
         * This violation is because of complex statement
         */
         ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ); Fls_Flash_pReadAddressPtr += \
         /*
         * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         sizeof(Fls_Flash_DataBusWidthType) \
       )
#else
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
   */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr); Fls_Flash_pReadAddressPtr += \
         /*
         * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         sizeof(Fls_Flash_DataBusWidthType) \
       )
#endif    
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flag */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* read flash location */
        /* @violates @ref fls_flash_c_REF_2 A cast should not be performed between a pointer to object type 
            and a different pointer to object type */
        Fls_Flash_u32ReadAddress32 = *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

#else
        /* read flash location */
        /*
        * @violates @ref fls_flash_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        Fls_Flash_u32ReadAddress32 = *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif
        /*
        * @violates @ref fls_flash_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pCompareAddressPtr) !=
            Fls_Flash_u32ReadAddress32 
          )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            { 
                Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_Flash_eCompareStatus != FLASH_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_BLOCK_INCONSISTENT;
#endif
        }
        else
        {
            /* *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pCompareAddressPtr) = \
               *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr) */
        }
#if (FLS_BLANK_CHECK_API == STD_ON) 
        if (NULL_PTR == pDataPtr)
        {  
            /* BLANK_CHECK API */
        }
        else
#endif 
        {
            /* COMPARE API */
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pCompareAddressPtr += sizeof(Fls_Flash_DataBusWidthType);
        }
    }
    
    /* Final 8-bit transfer */
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )    
    /*
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadAddressEndPtr) ) && \
         /*
         * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
         * This violation is because of complex statement
         * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ); Fls_Flash_pReadAddressPtr++
       )
#else
    /*
    * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_flash_c_REF_23 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadAddressEndPtr); Fls_Flash_pReadAddressPtr++)
#endif    
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET8(FLASH_FERSTAT_ADDR32, FLASH_FERSTAT_DFDIF_W1C);
        
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }
#else
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
#endif
        /*
        * @violates @ref fls_flash_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *Fls_Flash_pCompareAddressPtr != Fls_Flash_u8ReadAddress8 )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            { 
                Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_Flash_eCompareStatus != FLASH_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_BLOCK_INCONSISTENT;
#endif
        }
        else
        {
            /* *Fls_Flash_pCompareAddressPtr == *Fls_Flash_pReadAddressPtr */
        }
#if (FLS_BLANK_CHECK_API == STD_ON)         
        if (NULL_PTR == pDataPtr)
        {  
            /* BLANK_CHECK API */
        }
        else
#endif 
        {
            /* COMPARE API */
            /*
            * @violates @ref fls_flash_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pCompareAddressPtr++;
        }
    }

#if( FLS_DSI_HANDLER_API == STD_ON )    
    if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
    {
        Fls_Flash_eCompareStatus = FLASH_E_OK;
    }
    else
    {
        /* Do nothing */
    }
    /*
    * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
    */
    return Fls_Flash_eCompareStatus;
#else
    /*
    * @violates @ref fls_flash_c_REF_5 Return statement before end of function.
    */
    return FLASH_E_OK;
#endif    
}
#endif /* ( FLS_COMPARE_API == STD_ON ) || (FLS_BLANK_CHECK_API == STD_ON) */
    
#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON)

#define FLS_START_SEC_RAMCODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"
/**
* @brief          Invalidate flash prefetch buffers
*
* @return         void
*
*/
/*
* @violates @ref fls_flash_c_REF_25 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/     
FUNC( void, FLS_CODE ) Fls_Flash_InvalidPrefetchBuff_Ram( void )
{

     /* start critical section: implementation depends on integrator */
    if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
    {
        /* Call FlsStartFlashAccessNotif function if configured */
        Fls_pConfigPtr->startFlashAccessNotifPtr();
    }
    /* Check the status of the prefecth buffers, and invalidate them only if they are enabled.*/
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    if( 0U == REG_BIT_GET32(FLASH_MSCM_OCMDR0_ADDR32, FLASH_MSCM_OCMDR0_OCMC1_U32))    /* If prefetch is enabled for program flash, OCMDR0[5] == 0 */
    {
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        REG_BIT_SET32(FLASH_MSCM_OCMDR0_ADDR32, FLASH_MSCM_OCMDR0_OCMC1_U32); /* Set OCMDR0[5]. Disable PF for program flash */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */        
        REG_BIT_CLEAR32(FLASH_MSCM_OCMDR0_ADDR32, FLASH_MSCM_OCMDR0_OCMC1_U32 );  /* Clear OCMDR0[5]. Enable PF for program flash */ 
    }
    /*
    * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */   
    if( 0U == REG_BIT_GET32(FLASH_MSCM_OCMDR1_ADDR32, FLASH_MSCM_OCMDR1_OCMC1_U32) )    /* If prefetch is enabled for data flash, OCMDR1[5] == 0 */
    {
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */   
        REG_BIT_SET32(FLASH_MSCM_OCMDR1_ADDR32, FLASH_MSCM_OCMDR1_OCMC1_U32); /* Set OCMDR0[5]. Disable PF for program flash */
        /*
        * @violates @ref fls_flash_c_REF_19 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_flash_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */           
        REG_BIT_CLEAR32(FLASH_MSCM_OCMDR1_ADDR32, FLASH_MSCM_OCMDR1_OCMC1_U32 );  /* Clear OCMDR0[5]. Enable PF for program flash */ 
    }
    
    /* end flash access section: implementation depends on integrator */
    if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
    {
        /* Call Fls_FinishedFlashAccessNotif function if configured */
        Fls_pConfigPtr->finishedFlashAccessNotifPtr();
    }
}
#define FLS_STOP_SEC_RAMCODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#endif /* #if (FLASH_INVALIDATE_PREFETCH_BUFFERS == STD_ON) */


#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"


#if( FLS_DSI_HANDLER_API == STD_ON )
/**
* @brief          Low level data storage exception handler.
*
* @return         Exc_CompHandlerReturnType
* @retval         EXC_HANDLED_SKIP The data storage exception was 
*                 caused by currently pending flash read or compare job
* @retval         EXC_UNHANDLED The data storage exception was 
*                 NOT caused by currently pending flash read or compare job
*
*/
/*
* @violates @ref fls_flash_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_DsiHandler
(
    P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) pExceptionDetailsPtr 
)
{
    VAR( Fls_CompHandlerReturnType, AUTOMATIC ) u8RetVal = FLS_UNHANDLED;
    
    /*  Check whether there is 
        [1] pending read, compare, erase or write job, 
        [2] exception syndrome register indicates DSI reason, and 
        [3] data_pt matches address currently accessed by pending flash read or flash compare job */       
    if( ( FLASH_E_PENDING == Fls_Flash_eReadStatus ) && 
        ( FLASH_DSI_EXC_SYNDROME == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME) 
        ) &&
         /*
         * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
         * This violation is because of complex statement
         */
        ( pExceptionDetailsPtr->data_pt == Fls_Flash_pReadAddressPtr ) \
      )
    {
        Fls_Flash_eReadStatus = FLASH_E_FAILED;
        u8RetVal = FLS_HANDLED_SKIP;
    }
    else if( ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ) &&
             ( FLASH_DSI_EXC_SYNDROME ==
               (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME) 
             ) &&
             (( pExceptionDetailsPtr->data_pt == Fls_Flash_pReadAddressPtr ) ||
              /*
               * @violates @ref fls_flash_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
               * This violation is because of complex statement
               */
               ( pExceptionDetailsPtr->data_pt == Fls_Flash_pCompareAddressPtr ) \
             ) \
           )
    {
        Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        u8RetVal = FLS_HANDLED_SKIP;
    }
    else
    {
        /* FLS_UNHANDLED */
    }

    return u8RetVal;
}
#endif /* FLS_DSI_HANDLER_API == STD_ON */


#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_flash_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_flash_c_REF_9 Only preprocessor statements
* and comments before #include
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif