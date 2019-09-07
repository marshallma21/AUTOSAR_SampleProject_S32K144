/**
*   @file    Eep.c
*   @implements Eep.c_Artifact   
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Eeprom driver source code.
*
*   @addtogroup EEP
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
* @section eep_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section eep_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section eep_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
* This violation is because right hand operator has volatile. There is no danger if the second operator is
* evaluated after because FCCOB6 and FCCOB7 are updated synchronuosly while CCIF is unset.
*
* @section eep_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section eep_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* This violation is not fixed since if hardware error is detected it should return from the function
*
* @section eep_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as the read/write/erase/operation finished
*
* @section eep_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6, Booleans operands are not used for logical
* operators '&&', '||' and '!'
* This violation because of it is not effectively boolean
*
* @section eep_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section eep_c_REF_9
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section eep_c_REF_10
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement
*
* @section eep_c_REF_11
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*
* @section eep_c_REF_12
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const and
* volatile qualification from the type address by a pointer
* Because of removing the const qualification from the type address by a pointer
*
* @section eep_c_REF_13
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section eep_c_REF_14
* Violates MISRA 2004 Required Rule 17.2, Pointer subtraction shall only be applied to pointers
* that address elements of the same array
* Due to the pointers that address elements are not the same array
* 
* @section eep_c_REF_15
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function.
* The return value is intentionally ignored at this place.
*
* @section eep_c_REF_16
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable.
* The code is not dynamically linked. An absolute stack address is obtained 
* when taking the address of the near auto variable.
*
* @section eep_c_REF_17
* Violates MISRA 2004 Required Rule 13.7, Boolean within 'if' always evaluates to True.
* Depending on the result of the underlying HW erase operation, the condition might be evaluated 
* also to False (note the operands are initialized to FALSE).
*
* @section eep_c_REF_19
* Violates MISRA 2004 Required Rule 8.12,
* When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
* For the purpose of copying from ROM to RAM the compiled access code opocode is treated as uint32 array.
* All start, end and size parameters are defined by the linker file and imported into C module as external
* variables.  
* 
* @section eep_c_REF_20
* Violates MISRA 2004 Required Rule 11.1, Conversions involving function pointers must be to/from integral types
* Conversion is made for special purpose - copying the compiled function opcode from ROM to RAM.
* 
* @section eep_c_REF_21
* Violates MISRA 2004 Required Rule 8.7, could define variable at block scope
* The symbol is defined by the linker file and imported into C module as external variable. 
*
* @section eep_c_REF_22 
* Violates MISRA 2004 Required Rule 17.2, Relational or subtract operator applied to pointers
* The pointers point to the same area in RAM where the AC opcode is copied from ROM.
*
* @section eep_c_REF_23 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* The pointer subtraction is made inside while loop and due to its condition the subtraction 
* result is always positive and therefore it can be casted to unsigned. 
*
* @section eep_c_REF_24 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* This is due to boolean conversion.
* 
* @section eep_c_REF_25
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* Due to casting between a pointer and unsigned long representing address.
* 
* @section eep_c_REF_26
* Violates MISRA 2004 Advisory Rule 11.4, cast from pointer to pointer
* Cast from pointer to pointer to const is desired at this place.    
*
* @section eep_c_REF_27
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
* Once abnormal condition is indicated, the loop is terminated by 'break'. Since 
* there are handled several abnormal conditions, the loop contains more
* than one 'break'.    
*
* @section eep_c_REF_28
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined: 'EEPROM_AC_CALL'
* Macro is used for the purpose of abstraction between PPC and ARM platforms.
* 
* @section eep_c_REF_29
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* On ARM platform, the liker is not aware whether Access Code copied to RAM
* by the EEP driver is compiled in Thumb mode. Therefore LSB bit in its
* address needs to be set to notify the core that the code executed after BLX 
* instruction branching to AC code is in Thumb-encoded.
* 
* @section eep_c_REF_30
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* The casted value is assigned to the pointer declared with the PACKED compiler directive 
* to prevent the risk listed in the Rule 11.4 
* (invalid conversion if a new pointer requires a stricter alignment).     
*    
* @section eep_c_REF_31
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const and
* volatile qualification from the type address by a pointer
* This is done intentionally since it's the only reasonable way how to perform an interlock write 
* needed for the eeprom prefetch buffer invalidation. 
*
* @section eep_c_REF_32
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section eep_c_REF_33
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
* do-while-zero construct. 
* This is used to abstract the export of configuration sets or for a function define.
*
* @section eep_c_REF_34
* Violates MISRA 2004 Required Rule 10.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating 
* contents in that address.
*
* @section eep_c_REF_35
* Violates MISRA 2004 Required Rule 19.11, All macro identifiers in preprocessor directives shall be defined
* before use, except in #ifdef and #ifndef preprocessor directives and the defined() operator.
* This violation is due to configuration defines, defined in a different file. Those defines are always present.
*
* @section eep_c_REF_36
* Violates MISRA 2004 Advisory Rule 16.7, A pointer parameter in a function prototype should be declared
* as pointer to const if the pointer is not used to modify the addressed object.
* The pointer is used to modify the addressed object.
*
* @section eep_c_REF_37
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as in only one file 
*
* @section eep_c_REF_38
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* This function may be called from Mcal.h in Base module 
*
* @section eep_c_REF_39
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used
* This comma operator was used for the side effect. The return value from called 
* was not evaluated
*
* @section eep_c_REF_40
* Violates MISRA 2004 Required Rule 17.3, >, >=, <, <=shall not be applied to pointer types 
* except where they point to the same array.
* Due to the pointers that address elements are not the same array
*
* @section eep_c_REF_41
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating 
* contents in that address.
*
* @section eep_c_REF_42
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function
* This violation because of using variable address instead of its value.
*
* @section eep_c_REF_43
* Violates MISRA 2004 Required Rule 11.5, A cast should not be performed that removes the const or volatile
* of the qualification. The cast is done to reduce the number of variables used and the complexity of the code.
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
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by smcal coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to EEP.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/

/* Compiler warning eep_c_REF_CW_01: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly. 
   Sizes of the pointers and integral types for all the supported platforms/compilers are well known 
   and the volatile keyword is not needed when using the pointer value as a eeprom address counter, 
   as the pointer value is not updated in the DSI interrupt context or by other hardware means.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


#include "Eep.h"
#include "Eep_InternalTypes.h"
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#if(EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

#if( EEP_DEV_ERROR_DETECT == STD_ON )   
#include "Det.h"
#endif /* EEP_DEV_ERROR_DETECT == STD_ON */

#include "SchM_Eep.h"

/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Reg_eSys_Ftfc.h"
#include "StdRegMacros.h"







/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_C                      43
#define EEP_AR_RELEASE_MAJOR_VERSION_C       4
#define EEP_AR_RELEASE_MINOR_VERSION_C       2
/*
* @violates @ref eep_c_REF_13 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define EEP_AR_RELEASE_REVISION_VERSION_C    2
#define EEP_SW_MAJOR_VERSION_C               1
#define EEP_SW_MINOR_VERSION_C               0
#define EEP_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_VENDOR_ID_C != EEP_VENDOR_ID)
    #error "Eep.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_C != EEP_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep.c and Eep.h are different"
#endif

/* Check if current file and Eep_InternalTypes header file are of the same vendor */
#if (EEP_VENDOR_ID_C != EEP_INTERNALTYPES_VENDOR_ID)
    #error "Eep.c and Eep_InternalTypes.h have different vendor ids"
#endif
/* Check if current file and Eep_InternalTypes header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_C    != EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_C    != EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_C != EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep.c and Eep_InternalTypes.h are different"
#endif
/* Check if current file and Eep_InternalTypes header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_C != EEP_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_C != EEP_INTERNALTYPES_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_C != EEP_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep.c and Eep_InternalTypes.h are different"
#endif

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep.c and Dem.h are different"
    #endif
#endif 
#endif

#if( EEP_DEV_ERROR_DETECT == STD_ON )
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep.c and Det.h are different"
    #endif
#endif
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/** 
    @brief fill pattern used to clear write and erase access code in RAM
*/
#if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
#define EEP_AC_UNLOAD_PATTERN 0xffffffffU
#endif

/** 
    @brief Calculate total eeprom size in bytes
*/
#define EEP_TOTAL_SIZE  (EEP_SIZE)
/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define EEP_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

/** 
* @brief Maximum number of bytes to read or compare in one cycle of Eep_MainFunction
*/
static VAR(Eep_LengthType, EEP_VAR) Eep_u32MaxRead = 0UL;
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF) 
/** 
* @brief Maximum number of bytes to write in one cycle of Eep_MainFunction
*/
static VAR(Eep_LengthType, EEP_VAR) Eep_u32MaxWrite = 0UL;
#endif
/** 
* @brief Logical address of data block currently processed by Eep_MainFunction
*/
static VAR(Eep_AddressType, EEP_VAR) Eep_u32EepromAddrIt = 0UL;
/** 
* @brief Remainin length to be transfered until the end of the job
*/
static  VAR( Eep_LengthType, EEP_VAR) Eep_u32RemainingLength = 0UL;
/** 
* @brief Result of last eeprom module job
*
*/
static VAR(MemIf_JobResultType, EEP_VAR) Eep_eJobResult = MEMIF_JOB_OK;
/** 
* @brief Type of currently executed job (erase, write, read, or compare)
*/
static VAR(Eep_JobType, EEP_VAR) Eep_eJob = EEP_JOB_ERASE;
#if (EEP_ENABLE_QUICK_WRITES_API == STD_ON)
/** 
* @brief Type of currently executed write jobs(normal or quick)
*/
static VAR(Eep_UrgencyModeType, EEP_VAR) Eep_eUrgencyMode = EEP_URGENCY_NORMAL_WRITES;
#endif
/** 
* @brief Pointer to current eeprom module configuration set
*/
static P2CONST(Eep_ConfigType, EEP_VAR, EEP_APPL_CONST) Eep_pConfigPtr = NULL_PTR;
#define EEP_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#define EEP_START_SEC_VAR_INIT_8
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
/** 
* @brief Pointer to current position in source data buffer
* @details Used by both write and compare jobs
*/
static P2CONST( uint8, EEP_VAR, EEP_APPL_CONST ) Eep_pu8JobSrcAddrPtr = NULL_PTR;
/** 
* @brief Pointer to current position in target data buffer
* @details Used only by read job
*/
static P2VAR( uint8, EEP_VAR, EEP_APPL_DATA ) Eep_pu8JobDataDestPtr = NULL_PTR;

/** 
* @brief Indicates that new job has been accepted
* @details Used by all types of job
*/
static VAR(uint8, EEP_VAR) Eep_u8JobStart = (uint8)0;
#define EEP_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
#define EEP_START_SEC_VAR_INIT_16
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#if(EEP_ENABLE_QUICK_WRITES_API == STD_ON)
/** 
* @brief Requested urgency length to set up number of bytes used for quick writes
* @details Used only by the Eep_QuickWrite, Eep_MainFunction
*/
static VAR(uint16, EEP_VAR) Eep_u16QuickWritesLength = 0U;
#endif
#define EEP_STOP_SEC_VAR_INIT_16
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#define EEP_START_SEC_VAR_INIT_32
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

/** 
* @brief Pointer to current eeprom module configuration set
* 
*/
static VAR(uint32, EEP_VAR) Eep_u32AccCRCremainder = 0U;

#define EEP_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"



#define EEP_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
/** 
    @brief Result of last eeprom hardware job
*/
#if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
static VAR(MemIf_JobResultType, EEP_VAR) Eep_Eeprom_eJobResult = MEMIF_JOB_OK;
#endif
/** 
    @brief Type of current eeprom hardware job
*/
VAR(Eep_Eeprom_JobType, EEP_VAR) Eep_Eeprom_eJob = EEP_JOB_COMPARE;

/** 
    @brief Number of bytes of data left to write.
*/
#define EEP_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#define EEP_START_SEC_VAR_INIT_32
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#if (EEP_TIMEOUT_HANDLING == STD_ON)
VAR(uint32, EEP_VAR) Eep_Eeprom_u32TimeoutCounter = 0UL;
#endif
VAR(uint32, EEP_VAR) Eep_Eeprom_u32DestAddress = 0UL;
VAR(uint32, EEP_VAR) Eep_Eeprom_u32SrcAddress = 0UL;
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON) 
static VAR(uint32, EEP_VAR) Eep_Eeprom_u32RemainingLength = 0UL;
#endif

#if ((EEP_TIMEOUT_HANDLING == STD_ON) && (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
/**
    @brief Timeout counter used in both sync/async modes
  */
static VAR(uint32, EEP_VAR) Eep_Eeprom_u32AsyncTimeoutCnt = 0U;
#endif

#define EEP_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#define EEP_START_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
#define EEP_STOP_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#define EEP_START_SEC_CONST_8
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
CONST(uint8, EEP_CONST) Eep_Eeprom_u8ErasedValue[EEP_PAGE_SIZE_4BYTES] = {EEP_ERASED_VALUE_U8,
                               EEP_ERASED_VALUE_U8, EEP_ERASED_VALUE_U8, EEP_ERASED_VALUE_U8};
#define EEP_STOP_SEC_CONST_8
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
#define EEP_START_SEC_CONST_32
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"


/* Start Position and Size of write access code in eeprom */
/* @violates @ref eep_c_REF_19 For fixed array size. */
/* @violates @ref eep_c_REF_21 Could define variable at block scope */
extern CONST(uint32, EEP_CONST) Eep_ACWriteRomStart[];
/* @violates @ref eep_c_REF_19 For fixed array size. */
/* @violates @ref eep_c_REF_21 Could define variable at block scope */
extern CONST(uint32, EEP_CONST) Eep_ACWriteSize[];

#define EEP_STOP_SEC_CONST_32
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
#endif /* EEP_AC_LOAD_ON_JOB_START == STD_ON */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/    

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define EEP_START_SEC_CODE
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"
#if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
static FUNC( void, EEP_CODE ) Eep_LoadAc(void);
static FUNC( void, EEP_CODE ) Eep_UnloadAc(void);
#endif
static FUNC(void, EEP_CODE) Eep_AccumulateCRC(VAR(uint32, AUTOMATIC) u32InputData);
static FUNC(void, EEP_CODE) Eep_ResetCRC (void);
static FUNC(uint32, EEP_CODE) Eep_FinalizeCRC (void);
static FUNC( void, EEP_CODE ) Eep_UpdateCRCreminder (VAR(Eep_CrcDataSizeType, AUTOMATIC) eDataSize);
static FUNC( Eep_CrcType, EEP_CODE )  Eep_CalcCfgCRC(void);
#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static FUNC( void, EEP_CODE ) Eep_ReportDemErrors(void);
static FUNC( void, EEP_CODE ) Eep_ReportDemPasses(void);
#endif
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessWriteJob(void);  
#if( EEP_ENABLE_QUICK_WRITES_API == STD_ON )
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_SetUrgencyMode(Eep_UrgencyModeType eUrgencyMode);
static FUNC( Std_ReturnType, EEP_CODE ) Eep_CheckParaInputQuickWrite
(
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pSourceAddressPtr,
    VAR( Eep_LengthType, AUTOMATIC) u32Length,
    VAR( uint16, AUTOMATIC ) u16QuickWritesLength 
);
#endif
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessReadJob(void); 
#if(EEP_COMPARE_API == STD_ON)
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessCompareJob(void);
#endif
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessRequestedJobs
( 
    VAR(Eep_JobType, AUTOMATIC) eJob
);
static FUNC( void, EEP_CODE ) Eep_CallNotification
( 
    VAR(MemIf_JobResultType, AUTOMATIC) eJobResult
);
static FUNC( void, EEP_CODE ) Eep_StartJobs( void );
static FUNC( void, EEP_CODE ) Eep_EndJobs( void );

#define EEP_STOP_SEC_CODE
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define EEP_START_SEC_CODE
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#define EEPROM_ARM_FAR_CALL2THUMB_CODE_BIT0_U32 (0x00000001UL)
    /* Macro for Access Code Call. On ARM/Thumb, BLX instruction used by the compiler for calling a function
       pointed to by the pointer requires that LSB bit of the address is set to one if the called fcn is coded in Thumb. */ 
    /* @violates @ref eep_c_REF_28 Function-like macro defined */
    #define EEPROM_AC_CALL(ptr2fcn, ptr2fcnType) ((ptr2fcnType)(((uint32)(ptr2fcn)) | EEPROM_ARM_FAR_CALL2THUMB_CODE_BIT0_U32))
#else
    /* @violates @ref eep_c_REF_28 Function-like macro defined */
    #define EEPROM_AC_CALL(ptr2fcn, ptr2fcnType) (ptr2fcn)
#endif


static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_Init( void );
#if (EEP_CANCEL_API == STD_ON )
static FUNC( void, EEP_CODE ) Eep_Eeprom_Cancel( void );
#endif  

static FUNC( void, EEP_CODE ) Eep_Eeprom_InitJob
(
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pu8JobSrcAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobDestAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32RemainingLength,
    VAR(Eep_JobType, AUTOMATIC) eJob
    
);
#if (EEP_CANCEL_API == STD_ON)
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WaitForFlexRamReady( void );
#endif

static Std_ReturnType Eep_Eeprom_SetFlexRamFuncCmd
(
    VAR(Eep_Eeprom_SetFRControlType, AUTOMATIC) eepControlCode,
    VAR(uint16, AUTOMATIC) u16QuickWritesLength
);

#if(EEP_COMPARE_API == STD_ON)
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_CompareSync
(
    P2CONST(uint8, AUTOMATIC, EEP_APPL_CONST ) pu8JobDestAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobSrcAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32TransferSize
);
#endif
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_ReadSync
(
    P2VAR (uint8, AUTOMATIC, EEP_APPL_DATA ) pu8JobDestAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobSrcAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32TransferSize
);
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE )Eep_Eeprom_ExecuteCmdAndCheckErrors 
(
    VAR(uint8, AUTOMATIC) u8PageSize
);
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF)
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WriteSync
(
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pu8JobSrcAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobDestAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32TransferSize
);
#endif
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON)
static FUNC( void, EEP_CODE ) Eep_Eeprom_WriteAsync(void);
#endif
#if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_Eeprom_GetJobResult( void );
#endif
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF)

static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WritePageSync
(
    VAR(uint8, AUTOMATIC) u8PageSize
);
#endif
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON)
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WaitIdleOrWritePageAsync
(
    VAR(uint8, AUTOMATIC) u8PageSize
);
#endif
#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static FUNC( void, EEP_CODE ) Eep_Eeprom_ReportBrownOut( VAR(uint8, AUTOMATIC) u8BrownOutCode);
#endif
#if((EEP_DEV_ERROR_DETECT == STD_ON) && (EEP_TIMEOUT_HANDLING == STD_ON))
static FUNC( void, EEP_CODE ) Eep_Eeprom_ReportDetTimeout(void);
#endif
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_CheckFlexRamReady( void );
static FUNC( void, EEP_CODE ) Eep_Eeprom_CheckPreviousCommand(void);
static FUNC( Std_ReturnType, EEP_CODE ) Eep_Eeprom_CompleteMaintenance( VAR(uint8, AUTOMATIC) u8BrownOutCode);
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if((EEP_DEV_ERROR_DETECT == STD_ON) && (EEP_TIMEOUT_HANDLING == STD_ON))
static FUNC( void, EEP_CODE ) Eep_Eeprom_ReportDetTimeout(void)
{
    VAR(uint8, AUTOMATIC) apiID = EEP_INIT_ID;
    
    switch (Eep_Eeprom_eJob)
   {
        case EEP_JOB_ERASE:
                apiID = EEP_ERASE_ID;
            break;
        case EEP_JOB_WRITE:
                #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON) 
                if (EEP_URGENCY_NORMAL_WRITES == Eep_eUrgencyMode) 
                {                    
                    apiID = EEP_WRITE_ID;
                }
                else
                {
                    apiID = EEP_QUICK_WRITE_ID;
                }    
                #else
                apiID = EEP_WRITE_ID; 
                #endif    
            break;              
        case EEP_JOB_READ:
                apiID = EEP_READ_ID;
            break;
        #if (EEP_COMPARE_API == STD_ON)                
        case EEP_JOB_COMPARE:
                apiID = EEP_COMPARE_ID;
            break;
        #endif
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }
    (void)Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, apiID, EEP_E_TIMEOUT );
}
#endif
#if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
/**
* @brief          Returns the LLD JobResult
*/
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_Eeprom_GetJobResult( void )
{
    return( Eep_Eeprom_eJobResult );
}
#endif
/**
* @brief          Wait for HW operation to complete, with timeout.
* @return         Success (DONE)
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_CheckFlexRamReady( void )
{
    VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eRetVal = EEPROM_E_FAILED;
    
    /* get hardware flags */
    /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
     * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type */
    if ((EEPROM_FCNFG_EEERDY_U8 == (REG_BIT_GET8(EEPROM_FCNFG_ADDR32, EEPROM_FCNFG_EEERDY_U8))))
    {
        /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
        * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type */
        if (EEPROM_FSTAT_CCIF_U8 == (REG_BIT_GET8(EEPROM_FSTAT_ADDR32, EEPROM_FSTAT_CCIF_U8)))
        {
            /* OK, FLEXRAM memory ready */
            eRetVal = EEPROM_E_OK; 
        }
        else
        {
            /* NOK, FLEXRAM memory not ready */
            eRetVal = EEPROM_E_FAILED;
        }
    }
    else
    {
        /* NOK, FLEXRAM memory not ready */
        eRetVal = EEPROM_E_FAILED;
    } 
    
    return eRetVal;  
}
/**
* @brief          Check Results from previous command to verify that any previous command has completed.
* @return         None
*/
static FUNC( void, EEP_CODE ) Eep_Eeprom_CheckPreviousCommand(void)
{
    /* if any previous errors exist */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if(REG_BIT_GET8(EEPROM_FSTAT_ADDR32, EEPROM_FSTAT_ACCERR_U8 | EEPROM_FSTAT_FPVIOL_U8) )
    {
        /* clear the error flags, otherwise CCIF cannot be cleared to launch command */
        /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        REG_WRITE8(EEPROM_FSTAT_ADDR32, EEPROM_FSTAT_ACCERR_W1C | EEPROM_FSTAT_FPVIOL_W1C);
    }
}
#if (EEP_CANCEL_API == STD_ON)
/**
* @brief          Wait for HW operation to complete, with timeout.
* @return         Success (DONE)
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WaitForFlexRamReady( void )
{
#if( EEP_TIMEOUT_HANDLING == STD_ON )
    VAR(uint32, AUTOMATIC) u32TimerCounterAbort = EEP_ABT_TIMEOUT_VALUE;
#endif 
    VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eRetVal = EEPROM_E_FAILED;

    /* wait until FlexRam is ready or abort if timeout is reached */
#if( EEP_TIMEOUT_HANDLING == STD_ON )
    while ((EEPROM_E_FAILED == (Eep_Eeprom_ReturnType)Eep_Eeprom_CheckFlexRamReady()) && (0U < u32TimerCounterAbort))
#else    
    while (EEPROM_E_FAILED == (Eep_Eeprom_ReturnType)Eep_Eeprom_CheckFlexRamReady()) 
#endif        
    {
        /* update timeout counter */
        #if( EEP_TIMEOUT_HANDLING == STD_ON )
        --u32TimerCounterAbort;
        #endif
    }
    if (EEPROM_E_OK == (Eep_Eeprom_ReturnType)Eep_Eeprom_CheckFlexRamReady()) 
    {
        /* FLEXRAM memory ready */
        eRetVal = EEPROM_E_OK; 
    }
    else
    {
        #if((EEP_DEV_ERROR_DETECT == STD_ON) &&( EEP_TIMEOUT_HANDLING == STD_ON))
        Eep_Eeprom_ReportDetTimeout();
        #endif
        /* FLEXRAM memory not ready, there was timeout */
        eRetVal = EEPROM_E_FAILED;
    } 
    
    return eRetVal;  
}
#endif
 #if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief          eports brownout codes to DEM
* @return         -
*/
static FUNC( void, EEP_CODE ) Eep_Eeprom_ReportBrownOut( VAR(uint8, AUTOMATIC) u8BrownOutCode)
{
    switch ((Eep_Eeprom_BrownOutCodeType)u8BrownOutCode)
    {
        case EEP_BO_DURING_MAINTENANCE_DETECTED:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_BOMaintenanceCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_BOMaintenanceCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        break;
        case EEP_BO_DURING_QUICK_WRITES_DETECTED:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_BOQuickWritesCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        break;
        case EEP_BO_DURING_NORMAL_WRITES:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_BONormalWritesCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_BONormalWritesCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        break;
        case EEP_NO_BO_DETECTED:
            /* No EEPROM issues detected*/
        break;
        default:
        break;
    }
}
#endif
/**
* @brief    Complete interrupted EEPROM quick write process.
*/  
static FUNC( Std_ReturnType, EEP_CODE ) Eep_Eeprom_CompleteMaintenance( VAR(uint8, AUTOMATIC) u8BrownOutCode)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal  = (Std_ReturnType)E_OK;
    
    /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
     * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type
     * @violates @ref eep_c_REF_3 Side effects on right hand of logical operator */
    if ((0U != REG_READ8(EEPROM_FCCOB6_ADDR32)) || (0U != REG_READ8(EEPROM_FCCOB7_ADDR32)) || 
        (EEP_NO_BO_DETECTED != (Eep_Eeprom_BrownOutCodeType)u8BrownOutCode)
        )
    {
        /* complete maintenenance and check query status again to see if maintenence was successful*/ 
        /* @violates @ref eep_c_REF_3 Side effects on right hand of logical operator */         
        if (((Std_ReturnType)E_NOT_OK == ((Std_ReturnType)Eep_Eeprom_SetFlexRamFuncCmd(EEP_COMPLETE_QUICK_WRITES, 0U))) || \
            ((Std_ReturnType)E_NOT_OK == ((Std_ReturnType)Eep_Eeprom_SetFlexRamFuncCmd(EEP_GET_FLEXRAM_STATUS, 0U))))
        {
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */
            return u8RetVal;
        }
        #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON)
        /* read the status reported in FTFC registers to identify if maintenance is needed */
        /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
         * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type
         * @violates @ref eep_c_REF_3 Side effects on right hand of logical operator */
        if ((0U != REG_READ8(EEPROM_FCCOB6_ADDR32)) ||(0U != REG_READ8(EEPROM_FCCOB7_ADDR32))) 
        {
            /* maintenence failed */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */
            return u8RetVal;
        }
        #endif
    }
    return u8RetVal;
}
/**
* @brief          Initialize eeprom hardware.
*/    
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_Init( void )
{
   
    VAR( Eep_Eeprom_ReturnType, AUTOMATIC ) eRetVal = EEPROM_E_OK;
    VAR(uint8, AUTOMATIC) u8BrownOutCode = 0U;

    
    /* initialize low level driver variables */
    Eep_Eeprom_u32DestAddress = 0UL;
    Eep_Eeprom_u32SrcAddress = 0UL;
    #if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
    Eep_Eeprom_eJobResult = MEMIF_JOB_OK;
    #endif
    /* get EERDY flag; EeeReady true is a precondiftion for a succesful FLEXRAM operations. 
       When the partitioning is done without the option to load FLEXRAM at reset, 
       EEP_SET_AS_EERAM command is needed to load FLEXRAM data and set EeeReady.
       Also quick writes query command is not allowed unless EEERDY is set.  */
    /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
     * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type */
    if (EEPROM_FCNFG_EEERDY_U8 != (REG_BIT_GET8(EEPROM_FCNFG_ADDR32, EEPROM_FCNFG_EEERDY_U8)))
    {
        /* wait for FLERAM to be ready to accept operations */
        if ((Std_ReturnType)E_NOT_OK == ((Std_ReturnType)Eep_Eeprom_SetFlexRamFuncCmd(EEP_SET_AS_EERAM, 0U)))
        {            
            eRetVal = EEPROM_E_FAILED;
            #if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
            Eep_Eeprom_eJobResult = MEMIF_JOB_FAILED;
            #endif  
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */
            return eRetVal;
        }
    }
    #if ((EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) || (EEP_ENABLE_QUICK_WRITES_API == STD_ON))
    /* query status of FLEXRAM quick writes and normal operations */
    if ((Std_ReturnType)E_NOT_OK == ((Std_ReturnType)Eep_Eeprom_SetFlexRamFuncCmd(EEP_GET_FLEXRAM_STATUS, 0U)))
    {            
        eRetVal = EEPROM_E_FAILED;
        #if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
        Eep_Eeprom_eJobResult = MEMIF_JOB_FAILED;
        #endif  
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */
        return eRetVal;
    }
    #endif
    /* report Brown-out Detection Codes to DEM */
    /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
     * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type */
    u8BrownOutCode = REG_READ8(EEPROM_FCCOB5_ADDR32);
    #if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    Eep_Eeprom_ReportBrownOut(u8BrownOutCode);
    #endif   
    /* read the status reported in FTFC registers to identify if maintenance is needed */
    if ((Std_ReturnType)E_NOT_OK == ((Std_ReturnType)Eep_Eeprom_CompleteMaintenance(u8BrownOutCode)))
    {            
        eRetVal = EEPROM_E_FAILED;
        #if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
        Eep_Eeprom_eJobResult = MEMIF_JOB_FAILED;
        #endif  
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */
        return eRetVal;
    }
    /* at this point EEERDY will be set due to Eep_Eeprom_SetFlexRamFuncCmd successful execution */
    eRetVal = Eep_Eeprom_CheckFlexRamReady();

    return eRetVal;
    
}

/**
* @brief          Initialize low level driver variables
* @details        
*/  
static FUNC( void, EEP_CODE ) Eep_Eeprom_InitJob
(
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pu8JobSrcAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobDestAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32RemainingLength,
    VAR(Eep_JobType, AUTOMATIC) eJob
)
{
    Eep_Eeprom_eJob = eJob;
    #if ((EEP_CANCEL_API == STD_ON) || (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON))
    Eep_Eeprom_eJobResult = MEMIF_JOB_PENDING;
    #endif
    #if (EEP_ASYNC_OPERATIONS_ENABLED == STD_ON)
    if(( EEP_JOB_ERASE == Eep_Eeprom_eJob ) || ( EEP_JOB_WRITE == Eep_Eeprom_eJob ))
    {
        /* initialize internal EEPROM variables
           used for the asynchronuos job processing */
        /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
         /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        Eep_Eeprom_u32SrcAddress = (uint32)pu8JobSrcAddrPtr; 
        Eep_Eeprom_u32DestAddress = FLEXRAM_BASEADDR + u32JobDestAddrIt;
        Eep_Eeprom_u32RemainingLength = (uint32)u32RemainingLength;
        #if( EEP_TIMEOUT_HANDLING == STD_ON )
        Eep_Eeprom_u32AsyncTimeoutCnt = EEP_ASYNC_WRITE_TIMEOUT_VALUE;
        #endif
        /* if any previous errors exist, clear the error flags to make sure that controlled will accept the new job  */
        Eep_Eeprom_CheckPreviousCommand();
    }
    else
    {
        /* do nothing */
    }
    #else
    (void)pu8JobSrcAddrPtr;
    (void)u32JobDestAddrIt;
    (void)u32RemainingLength;
    #endif
}



#if (EEP_CANCEL_API == STD_ON )
/**
* @brief          Cancel ongoing erase or write hardware job.
*               
*/
static FUNC( void, EEP_CODE ) Eep_Eeprom_Cancel( void )
{
    /* Wait for current aynchronuous pending write operation to finish, 
       as there is no hardware way to abort FLEXRAM operations*/
    if( EEPROM_E_OK == Eep_Eeprom_WaitForFlexRamReady() )
    {
        /* memory idle, no operation is pending */
        Eep_Eeprom_eJobResult = MEMIF_JOB_CANCELED;
    }
    else
    {
        /* do nothing */
    }

}
#endif 
static FUNC(Eep_Eeprom_ReturnType, EEP_CODE)Eep_Eeprom_ExecuteCmdAndCheckErrors 
(
    VAR(uint8, AUTOMATIC) u8PageSize
) 
{
    VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eRetVal = EEPROM_E_OK;
        
    /* call start EEPROM access notif function */
    if( NULL_PTR != Eep_pConfigPtr->startEepromAccessNotifPtr )
    {
        Eep_pConfigPtr->startEepromAccessNotifPtr();
    }

    /* call eeprom access code routine */
    /* @violates @ref eep_c_REF_29 Cast from pointer to unsigned long 
    *  @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type  and an integral type */
    EEPROM_AC_CALL(Eep_pConfigPtr->acWritePtr, Eep_Eeprom_AcWritePtrType)(Eep_pConfigPtr->acCallBackPtr, u8PageSize);    

    /* call start EEPROM access notif function */
    if( NULL_PTR != Eep_pConfigPtr->finishedEepromAccessNotifPtr )
    {
        Eep_pConfigPtr->finishedEepromAccessNotifPtr();
    }  
            
    /* verify if the cmd operation was successful */
    #if( EEP_TIMEOUT_HANDLING == STD_ON )
    /* check all error flags */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if((0U == REG_BIT_GET8(EEPROM_FSTAT_ADDR32, \
        EEPROM_FSTAT_RDCOLERR_U8 | EEPROM_FSTAT_ACCERR_U8 | EEPROM_FSTAT_FPVIOL_U8 | EEPROM_FSTAT_MGSTAT0_U8))
        && (0U != Eep_Eeprom_u32TimeoutCounter)
       )        
    #else
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if((0U == REG_BIT_GET8(EEPROM_FSTAT_ADDR32, \
        EEPROM_FSTAT_RDCOLERR_U8 | EEPROM_FSTAT_ACCERR_U8 | EEPROM_FSTAT_FPVIOL_U8 | EEPROM_FSTAT_MGSTAT0_U8))                 
       )
    #endif              
    {    
        /* do nothing */
    }
    else
    {
        /* in case the operation failed because of timeout */
        #if((EEP_DEV_ERROR_DETECT == STD_ON) && (EEP_TIMEOUT_HANDLING == STD_ON))
        if (0UL == Eep_Eeprom_u32TimeoutCounter)
        {
            Eep_Eeprom_ReportDetTimeout();
        }
        #endif
        
        /* program operation failed */    
        eRetVal = EEPROM_E_FAILED;
    }
    
    return eRetVal;
}
#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF)
/**
* @brief   Write in synchronous mode.
*
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WritePageSync
(
    VAR(uint8, AUTOMATIC) u8PageSize
)
{

    VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eRetVal = EEPROM_E_OK;
    

    #if(EEP_TIMEOUT_HANDLING == STD_ON)
    /* Initialize timeout counters */
    Eep_Eeprom_u32TimeoutCounter = EEP_SYNC_WRITE_TIMEOUT_VALUE;
    #endif 
    
    /* clear CCIF to execute cmd, wait for command to finish and check errors */
    eRetVal = Eep_Eeprom_ExecuteCmdAndCheckErrors(u8PageSize); 

    /* add number of bytes defined by page size - 1 or 4 */
    Eep_Eeprom_u32DestAddress = Eep_Eeprom_u32DestAddress + u8PageSize;
    /* add number of bytes defined by page size - 1 or 4 */
    Eep_Eeprom_u32SrcAddress = Eep_Eeprom_u32SrcAddress + u8PageSize;  

    return eRetVal;    
}
#else
/**
* @brief  Wait for operation to finish or write a page of 1 or 4 bytes.   
*
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WaitIdleOrWritePageAsync
(
    VAR(uint8, AUTOMATIC) u8PageSize
)
{  
    /* write the page to FLEXRAM */
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST )  pu8TempSrc = NULL_PTR;
    P2VAR( uint8, AUTOMATIC, EEP_APPL_DATA )  pu8TempDest = NULL_PTR;
    P2CONST(uint32, AUTOMATIC, EEP_APPL_CONST )  pu32TempSrc = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, EEP_APPL_DATA )  pu32TempDest = NULL_PTR;
    
    /* verify if controller is IDLE */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if (EEPROM_E_OK == Eep_Eeprom_CheckFlexRamReady())
    {
        /* OK, memory controller is idle */
        
        /* check and report errors from previous step */
        /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        if((0U == REG_BIT_GET8(EEPROM_FSTAT_ADDR32, \
            EEPROM_FSTAT_RDCOLERR_U8 | EEPROM_FSTAT_ACCERR_U8 | EEPROM_FSTAT_FPVIOL_U8 | EEPROM_FSTAT_MGSTAT0_U8))                 
           )
          
        {    
            /* do nothing */
        }
        else
        {
            /* program operation failed at previous step */
            Eep_Eeprom_eJobResult = MEMIF_JOB_FAILED;
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */
            return EEPROM_E_FAILED;
        }
        
        /* write to FLEXRAM */
        /* prepare access pointers */
        switch(u8PageSize)
        {
            case EEP_PAGE_SIZE_1BYTE:
                if (EEP_JOB_WRITE == Eep_Eeprom_eJob)
                {
                /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
                /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
                    pu8TempSrc = (uint8 *) Eep_Eeprom_u32SrcAddress;
                }
                else
                {
                    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
                    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
                    pu8TempSrc = Eep_Eeprom_u8ErasedValue;
                }
                /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
                /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
                pu8TempDest = (uint8 *)Eep_Eeprom_u32DestAddress;  
                *pu8TempDest = *pu8TempSrc; 
                break;
            case EEP_PAGE_SIZE_4BYTES:
                if (EEP_JOB_WRITE == Eep_Eeprom_eJob)
                {
                    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
                     /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
                    pu32TempSrc = (uint32 *) Eep_Eeprom_u32SrcAddress;
                }
                else
                {
                    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
                     /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
                     /* @violates @ref eep_c_REF_43 A cast should not be performed between a pointer type */
                     /* @violates @ref eep_c_REF_2 A cast should not be performed between a pointer type */
                    pu32TempSrc = (uint32 *)Eep_Eeprom_u8ErasedValue;  
                }   
                /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
                 /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
                pu32TempDest = (uint32 *) Eep_Eeprom_u32DestAddress;  
                *pu32TempDest = *pu32TempSrc;              
                break;
            default:    
                break;
        }
            
        if (EEP_PAGE_SIZE_0BYTES != u8PageSize)
        {
            /* add number of bytes defined by page size - 1,2 or 4 */
            Eep_Eeprom_u32DestAddress = Eep_Eeprom_u32DestAddress + u8PageSize;
            /* add number of bytes defined by page size - 1,2 or 4 */
            Eep_Eeprom_u32SrcAddress = Eep_Eeprom_u32SrcAddress + u8PageSize;
            /* update remaining length */
            Eep_Eeprom_u32RemainingLength = Eep_Eeprom_u32RemainingLength - u8PageSize;
            /* return PENDING to inform that the request was sent to FLEXRAM for the page write */
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */    
            return EEPROM_E_WRITE_REQUESTED;  
        }
    }
    else 
    {
        /* operation in progress, handle timeout */
        #if( EEP_TIMEOUT_HANDLING == STD_ON )
        /* Operation in progress, handle possible timeout */
        Eep_Eeprom_u32AsyncTimeoutCnt--;
        if( 0U == Eep_Eeprom_u32AsyncTimeoutCnt )
        {
            /* write operation timeout-ed. operations cannot be aborted */
            /* write operation failed */
            Eep_Eeprom_eJobResult = MEMIF_JOB_FAILED;
            #if( EEP_DEV_ERROR_DETECT == STD_ON)
            Eep_Eeprom_ReportDetTimeout();
            #endif
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */    
            return EEPROM_E_FAILED;
        }
        #else
            /* do nothing*/
        #endif
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */    
        return EEPROM_E_PENDING;  
    } 
    /* @violates @ref eep_c_REF_5 Return statement before end of function. */        
    return EEPROM_E_OK;
}
#endif
#if(EEP_COMPARE_API == STD_ON)
/**
* @brief  Execute a compare job for a main function.      
*
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_CompareSync
(
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pu8JobDestAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobSrcAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32TransferSize
)
{     
    VAR(Eep_LengthType, AUTOMATIC)  u32LocalTransferSize = u32TransferSize;
    VAR( uint32, AUTOMATIC )  u32TempSrc = 0UL;
    VAR( uint32, AUTOMATIC )  u32TempDest = 0UL;

    SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_09();  
    /* fault injection point */
    MCAL_FAULT_INJECTION_POINT(EEP_FIP_02_EEP_AFTER_COMPARE_SYNC);
    /* verify that EERAM is retrieving the data from EFLASH - EERDY set */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if (EEPROM_FCNFG_EEERDY_U8 == (REG_BIT_GET8(EEPROM_FCNFG_ADDR32, EEPROM_FCNFG_EEERDY_U8)))
    {
        /* OK, FLEXRAM ready */
    }
    else /* error, FLEXRAM is not ready */
    {
         SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_09();  
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
        return EEPROM_E_FAILED;        
    }
    
    /* initialize addresses */ 
    u32TempSrc = FLEXRAM_BASEADDR + u32JobSrcAddrIt; 
    /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    u32TempDest = (uint32)pu8JobDestAddrPtr; 
    /* compare on 1 byte */
    while ((EEP_PAGE_SIZE_4BYTES <= u32LocalTransferSize) && 
          (((u32TempSrc % EEP_PAGE_SIZE_4BYTES) != 0UL) || ((u32TempDest % EEP_PAGE_SIZE_4BYTES) != 0UL)))
    {
        /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        if ( *((uint8 *)u32TempDest) != *((uint8 *)u32TempSrc))
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_09();  
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
            return EEPROM_E_BLOCK_INCONSISTENT; 
        }
        else
        {
            u32TempSrc = u32TempSrc + 1UL; 
            u32TempDest = u32TempDest + 1UL;
            u32LocalTransferSize = u32LocalTransferSize - 1UL;
        }
    }
    
    /* u32TempSrc is alligned to 4 bytes */
    /* compare on 4 bytes*/
    while (EEP_PAGE_SIZE_4BYTES <= u32LocalTransferSize)
    {
        /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        if ( *((uint32 *)u32TempDest) != *((uint32 *)u32TempSrc))
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_09();  
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
            return EEPROM_E_BLOCK_INCONSISTENT; 
        }
        else
        {
            u32TempSrc = u32TempSrc + 4UL;
            u32TempDest = u32TempDest + 4UL;
            u32LocalTransferSize = u32LocalTransferSize - 4UL;
        }
    }
    
    /* compare on 1 byte */
    while (0UL < u32LocalTransferSize)
    {
        /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        if ( *((uint8 *)u32TempDest) != *((uint8 *)u32TempSrc))
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_09();  
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
            return EEPROM_E_BLOCK_INCONSISTENT; 
        }
        else
        {
            u32TempSrc = u32TempSrc + 1UL; 
            u32TempDest = u32TempDest + 1UL;
            u32LocalTransferSize = u32LocalTransferSize - 1UL;
        }
    }
    SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_09();  
    /* read ok */
    /* @violates @ref eep_c_REF_5 Return statement before end of function. */    
    return EEPROM_E_OK; 
}
#endif
/**
* @brief  Execute a read job for a main function.      
*
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_ReadSync
(
    P2VAR( uint8, AUTOMATIC, EEP_APPL_DATA ) pu8JobDestAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobSrcAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32TransferSize
)
{     
    VAR(Eep_LengthType, AUTOMATIC)  u32LocalTransferSize = u32TransferSize;
    VAR( uint32, AUTOMATIC )  u32TempSrc = 0UL;
    VAR( uint32, AUTOMATIC )  u32TempDest = 0UL;

    SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_08();  
    /* fault injection point */
    MCAL_FAULT_INJECTION_POINT(EEP_FIP_01_EEP_AFTER_READ_SYNC);
    /* verify that EERAM is retrieving the data from EFLASH - EERDY set */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if (EEPROM_FCNFG_EEERDY_U8 == (REG_BIT_GET8(EEPROM_FCNFG_ADDR32, EEPROM_FCNFG_EEERDY_U8)))
    {
        /* OK, FLEXRAM ready */
    }
    else /* error, FLEXRAM is not ready */
    {
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_08(); 
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
        return EEPROM_E_FAILED;        
    }
    
    /* initialize addresses */ 
    u32TempSrc = FLEXRAM_BASEADDR + u32JobSrcAddrIt; 
    /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    u32TempDest = (uint32)pu8JobDestAddrPtr; 
    
    /* copy from FLEXRAM to RAM on 1 byte if not alligned */
    while ((EEP_PAGE_SIZE_4BYTES <= u32LocalTransferSize) && 
           (((u32TempSrc % EEP_PAGE_SIZE_4BYTES) != 0UL) || ((u32TempDest % EEP_PAGE_SIZE_4BYTES) != 0UL))
           )
    {
        /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        *((uint8 *)u32TempDest) = *((uint8 *)u32TempSrc);
        u32TempSrc = u32TempSrc + 1UL; 
        u32TempDest = u32TempDest + 1UL;
        u32LocalTransferSize = u32LocalTransferSize - 1UL;
    }
    
    /* u32TempSrc is alligned to 4 bytes */
    /* copy from FLEXRAM to RAM on 4 bytes */
    while (EEP_PAGE_SIZE_4BYTES <= u32LocalTransferSize)
    {
        /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        *((uint32 *)u32TempDest) = *((uint32 *)u32TempSrc);
        u32TempSrc = u32TempSrc + 4UL;
        u32TempDest = u32TempDest + 4UL;
        u32LocalTransferSize = u32LocalTransferSize - 4UL;
    }
    
    /* copy from FLEXRAM to RAM on 1 byte */
    while (0UL < u32LocalTransferSize)
    {
        /* @violates @ref eep_c_REF_25 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        *((uint8 *)u32TempDest) = *((uint8 *)u32TempSrc);
        u32TempSrc = u32TempSrc + 1UL; 
        u32TempDest = u32TempDest + 1UL;
        u32LocalTransferSize = u32LocalTransferSize - 1UL;
    }
    SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_08();  
    /* read ok */
    /* @violates @ref eep_c_REF_5 Return statement before end of function. */    
    return EEPROM_E_OK; 
}

#if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF)
/**
* @brief  Execute write operation in sync mode.      
*
*/
static FUNC( Eep_Eeprom_ReturnType, EEP_CODE ) Eep_Eeprom_WriteSync
(
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pu8JobSrcAddrPtr,
    VAR(Eep_AddressType, AUTOMATIC) u32JobDestAddrIt,
    VAR(Eep_LengthType, AUTOMATIC)  u32TransferSize
)
{   
    VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eRetVal = EEPROM_E_FAILED; 
    VAR(Eep_LengthType, AUTOMATIC)  u32LocalTransferSize = u32TransferSize;
    
    SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_07();  
    /* verify that PROGRAM command may be started */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if (EEPROM_E_OK == Eep_Eeprom_CheckFlexRamReady())
    {
        /* OK, memory controller is idle */

    }
    else /* error, another operation is in progress*/
    {
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_07(); 
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
        return EEPROM_E_FAILED;        
    }  
    /* if any previous errors exist, clear the error flags */
    Eep_Eeprom_CheckPreviousCommand();    
    /* initialize internal EEPROM dest and src variables */
    Eep_Eeprom_u32DestAddress = FLEXRAM_BASEADDR + u32JobDestAddrIt;
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    Eep_Eeprom_u32SrcAddress = (uint32)pu8JobSrcAddrPtr;    
    
    /* unalligned start loop writes on 1 byte page */
    while (((0U != (Eep_Eeprom_u32DestAddress % EEP_PAGE_SIZE_4BYTES)) || (0U != (Eep_Eeprom_u32SrcAddress % EEP_PAGE_SIZE_4BYTES))) 
            &&( EEP_PAGE_SIZE_4BYTES <= u32LocalTransferSize)
           )
    {
   
        eRetVal = Eep_Eeprom_WritePageSync(EEP_PAGE_SIZE_1BYTE);
        u32LocalTransferSize = u32LocalTransferSize - EEP_PAGE_SIZE_1BYTE; 
        if (EEPROM_E_OK == eRetVal)
        {
            /* do nothing */
        }
        else
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_07(); 
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
            return EEPROM_E_FAILED;     
        }            
    }
    
    /* alligned loop for writes on 4 bytes */
    while (EEP_PAGE_SIZE_4BYTES <= u32LocalTransferSize)
    {
        eRetVal = Eep_Eeprom_WritePageSync(EEP_PAGE_SIZE_4BYTES);
        u32LocalTransferSize = u32LocalTransferSize - EEP_PAGE_SIZE_4BYTES; 
        if (EEPROM_E_OK == eRetVal)
        {
            /* do nothing */
        }
        else
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_07(); 
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
            return EEPROM_E_FAILED;     
        }  
    }
    
    while (0UL < u32LocalTransferSize)
    {
        eRetVal = Eep_Eeprom_WritePageSync(EEP_PAGE_SIZE_1BYTE);
        u32LocalTransferSize = u32LocalTransferSize - EEP_PAGE_SIZE_1BYTE; 
        if (EEPROM_E_OK == eRetVal)
        {
            /* do nothing */
        }
        else
        {
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_07(); 
            /* @violates @ref eep_c_REF_5 Return statement before end of function. */      
            return EEPROM_E_FAILED;     
        } 
    }
    SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_07();  
    /* transfer ok */
    /* @violates @ref eep_c_REF_5 Return statement before end of function. */    
    return EEPROM_E_OK; 
}

#else
/**
* @brief  Execute write operation in async mode.      
*
*/
static FUNC( void, EEP_CODE ) Eep_Eeprom_WriteAsync(void)
{  
   VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eRetVal = EEPROM_E_FAILED;      
    
    /* unalligned start loop writes on 1 byte page */
    if (((0UL != (Eep_Eeprom_u32DestAddress % EEP_PAGE_SIZE_4BYTES))||
        (0UL != (Eep_Eeprom_u32SrcAddress % EEP_PAGE_SIZE_4BYTES)))&&
        (Eep_Eeprom_u32RemainingLength >= EEP_PAGE_SIZE_4BYTES)
        )
    {
        /* write on 1 bytes page */
        eRetVal = Eep_Eeprom_WaitIdleOrWritePageAsync(EEP_PAGE_SIZE_1BYTE);
    }
    /* alligned loop for writes on 4 bytes */
    else if (EEP_PAGE_SIZE_4BYTES <= Eep_Eeprom_u32RemainingLength )
    {
         /* write on 4 bytes page */
        eRetVal = Eep_Eeprom_WaitIdleOrWritePageAsync(EEP_PAGE_SIZE_4BYTES);
       /* check state exit conditions */
    }
    else if( 0UL < Eep_Eeprom_u32RemainingLength)
    {
        /* write on 1bytes page */
        eRetVal = Eep_Eeprom_WaitIdleOrWritePageAsync(EEP_PAGE_SIZE_1BYTE);
    }
    else
    {
        /*write on 0bytes page just wait for the controller to get idle to make sure the job is finished*/
        eRetVal = Eep_Eeprom_WaitIdleOrWritePageAsync(EEP_PAGE_SIZE_0BYTES);
    }
    if (0UL == Eep_Eeprom_u32RemainingLength)
    {
        /* a request to write last page was sent to the controller, just
        wait for the controller to get idle to make sure the job is finished */
        eRetVal = Eep_Eeprom_WaitIdleOrWritePageAsync(EEP_PAGE_SIZE_0BYTES);
        /* while controller is not idle, EEPROM_E_PENDING is sent*/
        if ((EEPROM_E_PENDING != eRetVal))
        {   
            /* if it was not failed until now, it's ok */
            if (MEMIF_JOB_PENDING == Eep_Eeprom_eJobResult)
            {
                Eep_Eeprom_eJobResult = MEMIF_JOB_OK;
            }   
        }
    }
}

#endif

/** 
* @brief        Sends to the hardware the command Set FlexRam Function
*    
*/
static Std_ReturnType Eep_Eeprom_SetFlexRamFuncCmd
(
    VAR(Eep_Eeprom_SetFRControlType, AUTOMATIC) eepControlCode,
    VAR(uint16, AUTOMATIC) u16QuickWritesLength
)
{

    VAR(Std_ReturnType, AUTOMATIC) u8RetVal  = (Std_ReturnType)E_OK;
    VAR(Eep_Eeprom_ReturnType, AUTOMATIC) eCmdResult = EEPROM_E_OK;
    VAR(boolean, AUTOMATIC) bCmdAllowed = (boolean)TRUE;
   
    #if( EEP_TIMEOUT_HANDLING == STD_ON )
    Eep_Eeprom_u32TimeoutCounter = EEP_ABT_TIMEOUT_VALUE;   
    #endif   
    /* verify if the command is allowed */
    #if(EEP_ENABLE_QUICK_WRITES_API == STD_ON)
    if (EEP_SET_QUICK_WRITES_MODE == eepControlCode)
    {
        /* check both EERDY and CCIF bits */
        if (EEPROM_E_OK == (Eep_Eeprom_ReturnType)Eep_Eeprom_CheckFlexRamReady())
        {
            bCmdAllowed = (boolean)TRUE;
        }
        else
        {
            bCmdAllowed = (boolean)FALSE;
        }
    }
    {
    #endif    
        /* check only CCIF bit */
        /* @violates @ref eep_c_REF_32 Conversions shall not be performed between a pointer to a function and ...
         * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type and an integral type */
        if (EEPROM_FSTAT_CCIF_U8 == (REG_BIT_GET8(EEPROM_FSTAT_ADDR32, EEPROM_FSTAT_CCIF_U8)))
        {
            bCmdAllowed = (boolean)TRUE;
        }
        else
        {
            bCmdAllowed = (boolean)FALSE;
        }
        
    #if(EEP_ENABLE_QUICK_WRITES_API == STD_ON)
    }
    #endif
    
    if((boolean)TRUE == bCmdAllowed)
    {
        /* if any previous errors exist, clear the error flags */
        Eep_Eeprom_CheckPreviousCommand();
        /* prepare FCCOBs for the flexram command */
        /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        REG_WRITE8(EEPROM_FCCOB0_ADDR32, EEPROM_CMD_SET_FLEXRAM); 
        /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
        /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
        REG_WRITE8(EEPROM_FCCOB1_ADDR32, (uint8)eepControlCode);
        #if(EEP_ENABLE_QUICK_WRITES_API == STD_ON)        
        if (EEP_SET_QUICK_WRITES_MODE == eepControlCode)
        {
            /* Number of FlexRAM bytes allocated for EEPROM quick writes [15:8] */
            /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
            /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
            REG_WRITE8(EEPROM_FCCOB4_ADDR32, (uint8)(u16QuickWritesLength >> EEPROM_ONE_BYTE_SHIFT_U8)); 
            /* Number of FlexRAM bytes allocated for EEPROM quick writes [7:0] */
            /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
            /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
            REG_WRITE8(EEPROM_FCCOB5_ADDR32, (uint8)(u16QuickWritesLength));
        }
        #else
            /* if quick writes mode is not used the parameter is not needed */
            (void)u16QuickWritesLength;
        #endif
        
        /* clear CCIF to execute cmd, wait for command to finish and check errors */
        eCmdResult = Eep_Eeprom_ExecuteCmdAndCheckErrors(EEP_PAGE_SIZE_0BYTES); 
        
        /* convert result */
        if (EEPROM_E_OK == eCmdResult)
        {
            /* cmd ok */
            u8RetVal = (Std_ReturnType)E_OK;
        }
        else
        {
            /* cmd failed */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* cmd not allowed */
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return u8RetVal;
}





#if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
/** 
* @brief        Load access code to RAM
*
* @details      Load erase or write access code to statically 
*               pre-configured location in RAM
*
* @param[in]    eJob Type of access code to load. Can be either 
*               EEP_JOB_ERASE or EEP_JOB_WRITE
*
* @pre          The module must be initialized
*
*
*    
*/
static FUNC( void, EEP_CODE ) Eep_LoadAc(void)
{
    P2CONST( uint32, AUTOMATIC, EEP_APPL_CONST ) pRomPtr = NULL_PTR;
    P2CONST( uint32, AUTOMATIC, EEP_APPL_CONST ) pRomEndPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, EEP_APPL_DATA ) pRamPtr = NULL_PTR;

    pRomPtr = Eep_ACWriteRomStart;
    /*
    * @violates @ref eep_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * 
    * @violates @ref eep_c_REF_20 Conversions involving function 
    * pointers must be to/from integral types    
    *
    * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type             
    */
    pRomEndPtr = pRomPtr + (uint32)(Eep_ACWriteSize);
    /*
    * @violates @ref eep_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref eep_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    *
    * @violates @ref eep_c_REF_20 Conversions involving function 
    * pointers must be to/from integral types                         
    */
    pRamPtr = (uint32*)(Eep_pConfigPtr->acWritePtr);
        
    /* Copy erase or write access code to RAM */
    /* pRomEndPtr is dynamically calculated and might not be multiple of 4U */
    /*
    * @violates @ref eep_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref eep_c_REF_22 Relational or subtract operator applied to pointers 
    * @violates @ref eep_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type    
    */
    for(; (uint32)pRomPtr < (uint32)pRomEndPtr; pRomPtr++)
    {
        *pRamPtr = *pRomPtr;
        /*
        * @violates @ref eep_c_REF_10 Array indexing shall be the
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
*               with EEP_AC_UNLOAD_PATTERN
*
* @param[in]    eJob Type of access code to unload. Can be either 
*               EEP_JOB_ERASE or EEP_JOB_WRITE
*
* @pre          The module must be initialized
*
*
*    
*/
static FUNC( void, EEP_CODE ) Eep_UnloadAc (void)
{
    P2VAR( uint32, AUTOMATIC, EEP_APPL_DATA ) pRamPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, EEP_APPL_DATA ) pRamEndPtr = NULL_PTR;
    
    /*
    * @violates @ref eep_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref eep_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref eep_c_REF_20 Conversions involving function 
    * pointers must be to/from integral types                         
    */
    pRamPtr = (uint32*)(Eep_pConfigPtr->acWritePtr);
    /*
    * @violates @ref eep_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref eep_c_REF_20 Conversions involving function 
    * pointers must be to/from integral types 
    * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type            
    */
    pRamEndPtr = pRamPtr + (uint32)(Eep_ACWriteSize);

    /* Unload (erase) write or erase access code from RAM */
    /*
    * @violates @ref eep_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref eep_c_REF_22 Relational or subtract operator applied to pointers
    * @violates @ref eep_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type      
    */
    for(; (uint32)pRamPtr < (uint32)pRamEndPtr; pRamPtr++)
    {
        *pRamPtr = EEP_AC_UNLOAD_PATTERN;
    }    
}
#endif 
/** 
* @brief        Function to call notifications
*
* @details      The Eep module shall call the callback function defined in the configuration parameter 
*               - EepJobEndNotification when a job has been completed with a positive result:  Read or Write or Erase or 
*                Compare finished & data blocks are equal.
*               - EepJobErrorNotification when a job has been canceled or aborted with negative result:read or write or earse or 
*                Compare aborted or data blocks are not equal
*
* @param[in]    eJobResult ... data 
*
* @return       void
* @retval       None.
*    
*/
static FUNC( void, EEP_CODE ) Eep_CallNotification
( 
    VAR(MemIf_JobResultType, AUTOMATIC) eJobResult
)
{
    if(MEMIF_JOB_OK == eJobResult)
    {
        if( NULL_PTR != Eep_pConfigPtr->jobEndNotificationPtr )
        {
            /* Call EepJobEndNotification function if configured */
            Eep_pConfigPtr->jobEndNotificationPtr();
        }
        else
        {
            /* Callback notification configured as null pointer */
        }
    }
    else if(( MEMIF_JOB_FAILED == eJobResult) || ( MEMIF_BLOCK_INCONSISTENT == eJobResult ) || 
            (MEMIF_JOB_CANCELED == eJobResult) || (MEMIF_JOB_PENDING == eJobResult)
           )
    {
        if( NULL_PTR != Eep_pConfigPtr->jobErrorNotificationPtr )
        {
            /* Call EepJobErrorNotification function if configured */
            Eep_pConfigPtr->jobErrorNotificationPtr();
        }
        else
        {
            /* Callback notification configured as null pointer */            
        }
    }
    else
    {
        /* Not done yet. There is more data to transfer in following Eep_MainFunction call .*/
    }
}

#if(EEP_COMPARE_API == STD_ON)
/** 
* @brief        Pocess the compare job
*
* @details      Compares data from Eep_pu8JobSrcAddrPtr to data from Eep_u32EepromAddrIt
*               of lenth equal to Eep_u32MaxRead or Eep_u32RemainingLength.
*
* @param[in]    
*
* @pre          The module must be initialized
*
* 
*    
*/
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessCompareJob( void)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;
    VAR( Eep_Eeprom_ReturnType, AUTOMATIC ) eTransferRetVal = EEPROM_E_FAILED; 
    VAR(uint32, AUTOMATIC) u32TempSource = 0UL;   
    VAR(Eep_LengthType, AUTOMATIC) u32TransfLength = 0UL;
   
    /* the function will compare Eep_u32MaxRead or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxRead)
    {
        /* Eep_u32MaxWrite must be transferred */
        u32TransfLength = Eep_u32MaxRead;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        u32TransfLength = Eep_u32RemainingLength;
    }
    /* if there is something to transfer */
    if (u32TransfLength > 0UL)
    {
        eTransferRetVal = Eep_Eeprom_CompareSync(Eep_pu8JobSrcAddrPtr, Eep_u32EepromAddrIt, u32TransfLength);
    }
    else
    {
        eTransferRetVal = EEPROM_E_OK;
    }
    /* update variables to be used for the next iteration */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    u32TempSource = (uint32)Eep_pu8JobSrcAddrPtr;
    u32TempSource = u32TempSource + u32TransfLength;
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
     /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    Eep_pu8JobSrcAddrPtr = (uint8 *)u32TempSource;
    Eep_u32EepromAddrIt = Eep_u32EepromAddrIt + u32TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - u32TransfLength;
    
    /* check status */
    if( EEPROM_E_FAILED == eTransferRetVal )
    {
        /* job has failed */
        eRetVal = MEMIF_JOB_FAILED;
    }    
    if( EEPROM_E_BLOCK_INCONSISTENT == eTransferRetVal )
    {
        /* comparison failed */
        eRetVal = MEMIF_BLOCK_INCONSISTENT;
    } 
    else if((0UL == Eep_u32RemainingLength ) && (EEPROM_E_OK == eTransferRetVal))
    {
        /* the job is finished successfully */
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return eRetVal;
}
#endif
/** 
* @brief        Pocess a read job
*
* @details      Reads data from Eep_u32EepromAddrIt to Eep_pu8JobDataDestPtr
*               of lenth equal to Eep_u32MaxRead or Eep_u32RemainingLength.
*
* @param[in]    
*
* @pre          The module must be initialized
*
* 
*    
*/
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessReadJob( void)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;
    VAR( Eep_Eeprom_ReturnType, AUTOMATIC ) eTransferRetVal = EEPROM_E_FAILED; 
    VAR(uint32, AUTOMATIC) u32TempSource = 0UL;   
    VAR(Eep_LengthType, AUTOMATIC) u32TransfLength = 0UL;
 
    /* transfer information to low level driver */    
    /* the function will read Eep_u32MaxRead or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxRead)
    {
        /* Eep_u32MaxWrite must be transferred */
        u32TransfLength = Eep_u32MaxRead;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        u32TransfLength = Eep_u32RemainingLength;
    }
    /* if there is something to transfer */
    if (u32TransfLength > 0UL)
    {    
        eTransferRetVal = Eep_Eeprom_ReadSync(Eep_pu8JobDataDestPtr, Eep_u32EepromAddrIt, u32TransfLength);
    }
    else
    {
        eTransferRetVal = EEPROM_E_OK;
    }
    /* update variables to be used for the next iteration */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    u32TempSource = (uint32)Eep_pu8JobDataDestPtr;
    u32TempSource = u32TempSource + u32TransfLength;
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    Eep_pu8JobDataDestPtr = (uint8 *)u32TempSource;
    Eep_u32EepromAddrIt = Eep_u32EepromAddrIt + u32TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - u32TransfLength;
    
    /* check status */
    if( EEPROM_E_FAILED == eTransferRetVal )
    {
        /* job has failed */
        eRetVal = MEMIF_JOB_FAILED;
    }    
    else if((0UL == Eep_u32RemainingLength ) && (EEPROM_E_OK == eTransferRetVal))
    {
        /* the job is finished */
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* do nothing */
    }

    return eRetVal;
}

/** 
* @brief        Pocess a write job
*
* @details      Performs the write operation for a main function call.
*                Calls low level drivers for async or snc behavior.
*
* @param[in]    
*
* @pre          The module must be initialized
*
* 
*    
*/
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessWriteJob( void)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;

    #if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF)  
    VAR(uint32, AUTOMATIC) u32TempSource = 0UL;   
    VAR( Eep_Eeprom_ReturnType, AUTOMATIC ) eTransferRetVal = EEPROM_E_FAILED; 
    VAR(Eep_LengthType, AUTOMATIC) u32TransfLength = 0UL;
 
    /* transfer information to low level driver */    
    /* the function will write Eep_u32MaxWrite or the remaining length */
    /* compute length of transfer */
    if (Eep_u32RemainingLength > Eep_u32MaxWrite)
    {
        /* Eep_u32MaxWrite must be transferred */
        u32TransfLength = Eep_u32MaxWrite;
    }
    else
    {
        /* Eep_u32RemainingLength must be transferred */
        u32TransfLength = Eep_u32RemainingLength;
    }
    /* if there is something to transfer */
    if (u32TransfLength > 0UL)
    {
        eTransferRetVal = Eep_Eeprom_WriteSync(Eep_pu8JobSrcAddrPtr, Eep_u32EepromAddrIt, u32TransfLength); 
    }
    else
    {
        eTransferRetVal = EEPROM_E_OK;
    }
    /* update variables to be used for the next iteration */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    u32TempSource = (uint32)Eep_pu8JobSrcAddrPtr;
    u32TempSource = u32TempSource + u32TransfLength;
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer */
    /* @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    Eep_pu8JobSrcAddrPtr = (uint8 *)u32TempSource;
    Eep_u32EepromAddrIt = Eep_u32EepromAddrIt + u32TransfLength;
    Eep_u32RemainingLength = Eep_u32RemainingLength - u32TransfLength;

    if( EEPROM_E_FAILED == eTransferRetVal )
    {
        /* job has failed */
        eRetVal = MEMIF_JOB_FAILED;
    }    
    else if((0UL == Eep_u32RemainingLength ) && (EEPROM_E_OK == eTransferRetVal))
    {
        /* the job is finished */
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
        /* do nothing */
    }
    #else
    /* in asynchronuous mode in one main function call EEP
     * will trigger a hardware write operation for a 1,2, or 4 bytes page and return,
     * it will not wait for operation to finish */
    Eep_Eeprom_WriteAsync(); 
    /* get job result */
    eRetVal = Eep_Eeprom_GetJobResult();
    #endif
        
    return eRetVal;
}
#if( EEP_ENABLE_QUICK_WRITES_API == STD_ON )
    /** 
* @brief        Pocess a set urgency job
*
* @details      Sets the hardware for quick writes or normal writes
*
* @param[in]    eUrgencyMode - quick/normal writes
*
* @pre    
*    
*/
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_SetUrgencyMode(Eep_UrgencyModeType eUrgencyMode)
{
    VAR(Eep_SetFRControlType, AUTOMATIC) eControlCode = EEP_SET_AS_EERAM;
    VAR(MemIf_JobResultType, AUTOMATIC) eRetVal = MEMIF_JOB_FAILED;
    VAR(Std_ReturnType, AUTOMATIC) eCmdResult = (Std_ReturnType)E_NOT_OK;
    
    switch( eUrgencyMode ) 
    {
        case EEP_URGENCY_QUICK_WRITES:
            eControlCode = EEP_SET_QUICK_WRITES_MODE;
            break;
        case EEP_URGENCY_NORMAL_WRITES:
            eControlCode = EEP_SET_AS_EERAM;
            Eep_u16QuickWritesLength = 0U;
            break;
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }
    /* call low level driver to change the mode */
    eCmdResult = (Std_ReturnType)Eep_Eeprom_SetFlexRamFuncCmd(eControlCode, Eep_u16QuickWritesLength);
    
    if ((Std_ReturnType)E_OK == eCmdResult)
    {
       eRetVal = MEMIF_JOB_OK;
    }
    else
    {
       eRetVal = MEMIF_JOB_FAILED;
    }    
    return eRetVal;
}
#endif
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
* @pre          Eep_ResetCRC() was executed before the first call of 
*               Eep_AccumulateCRC().
*
*    
*/
static FUNC(void, EEP_CODE) Eep_AccumulateCRC
(
  VAR(uint32, AUTOMATIC) u32InputData
)
{     

    if (0xFFFFU < u32InputData)
    {
        /* preparation for accumulation of higher 16 bits of the u32InputData */
        Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 16U) | (u32InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of Eep_u32AccCRCremainder) */
        Eep_UpdateCRCreminder(EEP_CRC_16_BITS);                    
    }

    if (0xFFU < u32InputData)
    {
        /* preparation for accumulation of lower 16 bits of the u32InputData */
        Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 16U) | (u32InputData & 0x0000FFFFU);    
        /* make 16-bit accumulated result (in lower 16-bits of Eep_u32AccCRCremainder) */
        Eep_UpdateCRCreminder(EEP_CRC_16_BITS);    
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the u32InputData */
        Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 8U) | u32InputData;    
        /* make 16-bit accumulated result (in lower 16-bits of Eep_u32AccCRCremainder) */
        Eep_UpdateCRCreminder(EEP_CRC_8_BITS);        
    }

    return;
} 


/** 
* @brief        Function to reset CRC calculation.
*
* @details      Resets accumulated Eep_u32AccCRCremainder. 
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
static FUNC(void, EEP_CODE) Eep_ResetCRC ( void )
{
    Eep_u32AccCRCremainder = 0U;
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
* @pre          Eep_AccumulateCRC() was executed at least once before 
*               calling Eep_FinalizeCRC().
*    
*/
static FUNC(uint32, EEP_CODE) Eep_FinalizeCRC ( void )
{
    /* add the final 0x0000 to the remainder */
    Eep_u32AccCRCremainder = (Eep_u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */         
    Eep_UpdateCRCreminder(EEP_CRC_16_BITS);
    
    return (Eep_u32AccCRCremainder);
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
* @pre          Can be called only from Eep_AccumulateCRC().
*    
*/

static FUNC( void, EEP_CODE ) Eep_UpdateCRCreminder 
( 
    VAR(Eep_CrcDataSizeType, AUTOMATIC) eDataSize 
)
{
    VAR(uint32, AUTOMATIC) u32CrcPolynomSft; 
    VAR(uint32, AUTOMATIC) u32LeadingOne;
    VAR(uint32, AUTOMATIC) u32AccDataLoc;
    VAR(uint32, AUTOMATIC) u32LeadingOneInitial;
    
    switch (eDataSize)
    {
        case EEP_CRC_8_BITS:
            u32CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            u32LeadingOneInitial = 0x10000U << 7U;        
            break;
        case EEP_CRC_16_BITS:
        default:
            u32CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            u32LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    u32AccDataLoc = Eep_u32AccCRCremainder;
    
    /* CRC computation */
    for (u32LeadingOne = u32LeadingOneInitial; u32LeadingOne >= 0x00010000U; u32LeadingOne >>= 1U)
    {
        if (u32AccDataLoc & u32LeadingOne)
        {
            u32AccDataLoc ^= u32CrcPolynomSft;   
        }
        u32CrcPolynomSft >>= 1U;
    }
    
    /* copy back to static variable */ 
    Eep_u32AccCRCremainder = u32AccDataLoc;
    
    return;    
}

/** 
* @brief        Calculates CRC over Eep configuration.
*
* @details      Calculates CRC over selected items of Eep configuration set 
*               pointed to by ConfigPtr. 
*
* @param[in]    ConfigPtr        Pointer to eeprom driver configuration set.
*
* @return       uint32
* @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
*
* @pre          Eep_pConfigPtr must not be properly initialized.
*    
*/

static FUNC( Eep_CrcType, EEP_CODE )  Eep_CalcCfgCRC( void )
{

    /* Reset the accumulated CRC value */
    Eep_ResetCRC();

    /* Accumulate the rest of the params (common for all sectors within a config set) */
    Eep_AccumulateCRC((VAR(uint32, AUTOMATIC))Eep_pConfigPtr->eDefaultMode);
    Eep_AccumulateCRC((VAR(uint32, AUTOMATIC))Eep_pConfigPtr->u32MaxReadFastMode );
    Eep_AccumulateCRC((VAR(uint32, AUTOMATIC))Eep_pConfigPtr->u32MaxReadNormalMode);
    Eep_AccumulateCRC((VAR(uint32, AUTOMATIC))Eep_pConfigPtr->u32MaxWriteFastMode);
    Eep_AccumulateCRC((VAR(uint32, AUTOMATIC))Eep_pConfigPtr->u32MaxWriteNormalMode);        
    
    return ((Eep_CrcType)Eep_FinalizeCRC());
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        The function initializes Eep module.
* @details      The function sets the internal module variables according to given
*               configuration set.
*
* @param[in]    pConfigPtr        Pointer to eeprom driver configuration set.
*
* @api
*
* @pre          @p pConfigPtr must not be @p NULL_PTR and the module status must not
*               be @p MEMIF_BUSY.
*
* @implements     Eep_Init_Activity 
*
*/
/*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/

FUNC( void, EEP_CODE ) Eep_Init
( P2CONST( Eep_ConfigType, AUTOMATIC, EEP_APPL_CONST ) pConfigPtr )
{
    VAR( Eep_Eeprom_ReturnType, AUTOMATIC ) eRetVal = EEPROM_E_OK;
    
    /* check DET error codes */
#if (EEP_DEV_ERROR_DETECT == STD_ON)
#if defined(EEP_PRECOMPILE_SUPPORT)
    if (NULL_PTR != pConfigPtr)
#else
    if (NULL_PTR == pConfigPtr)
#endif 
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_INIT_FAILED );
    }
    else if(MEMIF_JOB_PENDING == Eep_eJobResult)
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_BUSY );
    }
    else
    {
#endif 
        /* no error */
        /* set the configuration pointer according to the config variant */
        #if defined(EEP_PRECOMPILE_SUPPORT)
            Eep_pConfigPtr = &Eep_PBCfgVariantPredefined;
            #if (EEP_DEV_ERROR_DETECT == STD_OFF)
            (void)pConfigPtr;
            #endif
        #else 
            Eep_pConfigPtr = pConfigPtr;
        #endif

        /* check configuration CRC */
        if (Eep_pConfigPtr->u16ConfigCrc != Eep_CalcCfgCRC())
        {
            #if( EEP_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_INIT_ID, EEP_E_INIT_FAILED );
            Eep_pConfigPtr = NULL_PTR;
            #endif 
            Eep_eJobResult = MEMIF_JOB_FAILED;            
        }
        else        
        {
            /* Set the max number of bytes to read/write
                during Eep_MainFunction call */    
            if (MEMIF_MODE_SLOW == Eep_pConfigPtr->eDefaultMode)
            {
                Eep_u32MaxRead = Eep_pConfigPtr->u32MaxReadNormalMode;
                #if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF) 
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteNormalMode;
                #endif
            }
            else
            {
                Eep_u32MaxRead = Eep_pConfigPtr->u32MaxReadFastMode;
                #if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF) 
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteFastMode;
                #endif
            }
            
            #if(EEP_AC_LOAD_ON_JOB_START == STD_ON)
            /* load access code. the access code is needed by the Set FLEXRAM command */    
            Eep_LoadAc();
            #endif
            /* Initialize eeprom hardware */
            eRetVal = Eep_Eeprom_Init();
            #if(EEP_AC_LOAD_ON_JOB_START == STD_ON)
            /* unload access code. the access code is needed by the Set FLEXRAM command */      
            Eep_UnloadAc();
            #endif
            if(EEPROM_E_FAILED == eRetVal)
            {
                Eep_eJobResult = MEMIF_JOB_FAILED;
                #if(EEP_DEV_ERROR_DETECT == STD_ON)
                Eep_pConfigPtr = NULL_PTR; 
                #endif
            }
            else
            {
                Eep_eJobResult = MEMIF_JOB_OK;
            }
        }
    #if (EEP_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}

/**
* @brief            Erase memory by writing erase value.
* @details          Starts an erase job asynchronously. The actual job is performed
 *                  by the Eep_MainFunction.
*
* @param[in]        TargetAddress        Target address in eeprom memory.
* @param[in]        Length               Number of bytes to erase by writing the erased value.
*
* @return           Std_ReturnType
* @retval           E_OK                    Erase command has been accepted.
* @retval           E_NOT_OK                Erase command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post 
*
* @implements       Eep_Erase_Activity
*
*/
/*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, EEP_CODE ) Eep_Erase
( 
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    
    if( NULL_PTR == Eep_pConfigPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_UNINIT );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(u32TargetAddress > (Eep_AddressType)EEP_TOTAL_SIZE )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_PARAM_ADDRESS );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == u32Length ) || ((u32TargetAddress + u32Length) > (Eep_AddressType)EEP_TOTAL_SIZE))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_PARAM_LENGTH );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else 
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_01();
        
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_ERASE_ID, EEP_E_BUSY );
        #endif
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_01();
        }    
        else
        {
            /* Configure the erase job */
            Eep_u32EepromAddrIt = u32TargetAddress;
            Eep_u32RemainingLength = u32Length;
            Eep_eJob = EEP_JOB_ERASE;
            Eep_u8JobStart = 1U;
            Eep_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_01();
            
        }
    }
    return( u8RetVal );
}


/**
* @brief            Write one or more complete eeprom pages to the eeprom device.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   Eep_MainFunction.
*
* @param[in]        TargetAddress        Target address in eeprom memory.
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
*
* @implements       Eep_Write_Activity
*
*/
/*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, EEP_CODE ) Eep_Write
(
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pSourceAddressPtr,
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;

    if( NULL_PTR == Eep_pConfigPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_UNINIT );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(u32TargetAddress > (Eep_AddressType)EEP_TOTAL_SIZE )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_ADDRESS );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if ((0U == u32Length) || ((u32TargetAddress + u32Length) > (Eep_AddressType)EEP_TOTAL_SIZE))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_LENGTH );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pSourceAddressPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_PARAM_DATA );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else   
    {
        /* enter EA to protect global variables */
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_02();
        
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
#if( EEP_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_WRITE_ID, EEP_E_BUSY );
#endif    
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_02();
        }
        else
        {
            /* Configure the write job */
            /* uint32 destination address which will be incremented during job processing */
            Eep_u32EepromAddrIt = u32TargetAddress;
            /* uint8 source pointer which will be incremented during job processing */
            Eep_pu8JobSrcAddrPtr = pSourceAddressPtr;
            /* remaining length to be transfered */
            Eep_u32RemainingLength = u32Length;
            Eep_eJob = EEP_JOB_WRITE;
            #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON)
            Eep_eUrgencyMode = EEP_URGENCY_NORMAL_WRITES;
            #endif
            Eep_u8JobStart = 1U;
            Eep_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_02();
        }
    } 
    
    return( u8RetVal );
}


#if ( EEP_CANCEL_API == STD_ON ) || defined(__DOXYGEN__)
/**
* @brief            Cancel an ongoing eeprom read, write, erase or compare job.
* @details          Abort a running job synchronously so that directly after returning
*                   from this function a new job can be started.
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Eep_Cancel changes module status and @p Eep_eJobResult
*                   internal variable.
*
* @implements       Eep_Cancel_Activity 
*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, EEP_CODE ) Eep_Cancel( void )
{   
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Eep_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_CANCEL_ID, EEP_E_UNINIT );
    }
    #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON)
    else if (EEP_URGENCY_QUICK_WRITES == Eep_eUrgencyMode)
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_CANCEL_ID, EEP_E_CANCEL_REJECTED );
    }
    #endif
    else        
    {
    #endif 
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_06();
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
            /* Cancel ongoing hardware job */
            Eep_Eeprom_Cancel();
 
            #if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
            if(( EEP_JOB_ERASE == Eep_eJob ) || ( EEP_JOB_WRITE == Eep_eJob ))
            {
                Eep_UnloadAc( );
            }
            #endif 
            
            /* If underlying hardware job was successfully canceled */
            if(MEMIF_JOB_CANCELED == Eep_Eeprom_GetJobResult())
            {
                /* Update global job result status */
                Eep_eJobResult = MEMIF_JOB_CANCELED;
            }
            /* Call the error notification function if configured */            
            Eep_CallNotification(Eep_eJobResult);
        }
        else
        {
            /* Leave the job result unchanged */
        }
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_06();
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
    }
    #endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
}
#endif    /* EEP_CANCEL_API == STD_ON */


#if(( EEP_GET_STATUS_API == STD_ON ) || defined (__DOXYGEN__))
/**
* @brief            Returns the EEP module status.
* @details          Returns the EEP module status synchronously.
*
* @return           MemIf_StatusType
* @retval           MEMIF_UNINIT        Module has not been initialized (yet).
* @retval           MEMIF_IDLE          Module is currently idle.
* @retval           MEMIF_BUSY          Module is currently busy.
*
* @api
*
* @implements       Eep_GetStatus_Activity
*                   
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_StatusType, EEP_CODE ) Eep_GetStatus( void )
{
    VAR( MemIf_StatusType, AUTOMATIC ) eRetVal = MEMIF_IDLE;

    if( NULL_PTR == Eep_pConfigPtr )
    {
        eRetVal = MEMIF_UNINIT;
    } 
    else if( MEMIF_JOB_PENDING == Eep_eJobResult )
    {
        eRetVal = MEMIF_BUSY;
    }
    else
    {
        eRetVal = MEMIF_IDLE;
    }

    return( eRetVal );
}
#endif    /* EEP_GET_STATUS_API == STD_ON */


#if ( EEP_GET_JOB_RESULT_API == STD_ON )||  defined (__DOXYGEN__)/**
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
* @implements       Eep_GetJobResult_Activity
*                   
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_JobResultType, EEP_CODE ) Eep_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    if( NULL_PTR == Eep_pConfigPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_GETJOBRESULT_ID, EEP_E_UNINIT );
        #endif  
        eRetVal = (MemIf_JobResultType)MEMIF_JOB_FAILED;
    }
    else
    {
        eRetVal = Eep_eJobResult;
    } 
    return( eRetVal );
}
#endif


/**
* @brief            Reads from eeprom memory.
* @details          Starts a read job asynchronously. The actual job is performed by
*                   @p Eep_MainFunction.
*
* @param[in]        SourceAddress        Source address in eeprom memory.
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
* @post   
*
* @implements       Eep_Read_Activity
*                   
*/
/*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, EEP_CODE ) Eep_Read
( 
    VAR( Eep_AddressType, AUTOMATIC) u32SourceAddress, 
    P2VAR( uint8, AUTOMATIC, EEP_APPL_DATA ) pTargetAddressPtr,    
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    
    if( NULL_PTR == Eep_pConfigPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_UNINIT );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    else if( u32SourceAddress >= EEP_TOTAL_SIZE )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_ADDRESS );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32SourceAddress + u32Length) > EEP_TOTAL_SIZE ))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_LENGTH );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pTargetAddressPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_PARAM_DATA );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_03();
        
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
#if( EEP_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_READ_ID, EEP_E_BUSY );
#endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }    
        else
        {
            /* Configure the read job */
            Eep_u32EepromAddrIt = u32SourceAddress;
            Eep_pu8JobDataDestPtr = pTargetAddressPtr;
            Eep_u32RemainingLength = u32Length;
            Eep_eJob = EEP_JOB_READ;
            Eep_u8JobStart = 1U;
            /* Execute the read job */
            Eep_eJobResult = MEMIF_JOB_PENDING;

        }       
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_03();
    }
    
    return( u8RetVal );
}


#if( EEP_COMPARE_API == STD_ON ) || defined(__DOXYGEN__)
/**
* @brief           Compares a eeprom memory area with an application data buffer.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  Eep_MainFunction.
*
* @param[in]        SourceAddress          Source address in eeprom memory.
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
*
* @implements       Eep_Compare_Activity
*                   
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, EEP_CODE ) Eep_Compare
(
    VAR( Eep_AddressType, AUTOMATIC) u32SourceAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pTargetAddressPtr, 
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;

    if( NULL_PTR == Eep_pConfigPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_UNINIT );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( u32SourceAddress >= EEP_TOTAL_SIZE )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_ADDRESS );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32SourceAddress + u32Length) > EEP_TOTAL_SIZE ))
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_LENGTH );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pTargetAddressPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_PARAM_DATA );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else   
    {
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_04();    
        
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
#if( EEP_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_COMPARE_ID, EEP_E_BUSY );
#endif    /* EEP_DEV_ERROR_DETECT == STD_ON */            
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Eep_u32EepromAddrIt = u32SourceAddress;
            Eep_pu8JobSrcAddrPtr = pTargetAddressPtr;
            Eep_u32RemainingLength = u32Length;
            Eep_eJob = EEP_JOB_COMPARE;
            Eep_u8JobStart = 1U;
            Eep_eJobResult = MEMIF_JOB_PENDING;

        }       
        SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_04();
    }
    
    return( u8RetVal );
}
#endif /* EEP_COMPARE_API == STD_ON */

#if( EEP_SET_MODE_API == STD_ON )|| defined (__DOXYGEN__)
/**
* @brief           Sets the EEP module's operation mode to the given Mode.
* @details         Every given mode determinates maximum bytes for read-write
 *                 operations. Every mode has a set of pre-configured values.
*
* @param[in]        Mode        MEMIF_MODE_FAST or MEMIF_MODE_SLOW.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Eep_SetMode changes internal variables @p Eep_u32MaxRead and
*                 @p Eep_u32MaxWrite.
*
* @implements       Eep_SetMode_Activity
*                   
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, EEP_CODE ) Eep_SetMode
(
    VAR( MemIf_ModeType, AUTOMATIC ) eMode 
)
{
#if( EEP_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Eep_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_SETMODE_ID, EEP_E_UNINIT );
    }
    else if( MEMIF_JOB_PENDING == Eep_eJobResult )
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_SETMODE_ID, EEP_E_BUSY );
    }
    else
    {
#endif  /* EEP_DEV_ERROR_DETECT == STD_ON */
        /* Set the max number of bytes to read/write
            during Eep_MainFunction call */
        switch( eMode ) 
        {
            case MEMIF_MODE_FAST:
                Eep_u32MaxRead = Eep_pConfigPtr->u32MaxReadFastMode;
                #if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF) 
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteFastMode;    
                #endif
                break;
                
            case MEMIF_MODE_SLOW:
                Eep_u32MaxRead = Eep_pConfigPtr->u32MaxReadNormalMode;
                #if (EEP_ASYNC_OPERATIONS_ENABLED == STD_OFF) 
                Eep_u32MaxWrite = Eep_pConfigPtr->u32MaxWriteNormalMode;
                #endif
                break;
                
            default:
                /* Do nothing - should not happen in Fully Trusted Environment;
                   'default' clause added to fulfill MISRA Rule 15.3 */
                break;
        }
#if( EEP_DEV_ERROR_DETECT == STD_ON )        
    }
#endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
}
#endif /* EEP_SET_MODE_API == STD_ON */

#if( EEP_ENABLE_QUICK_WRITES_API == STD_ON )|| defined (__DOXYGEN__)
/**
*   Check parameter input of Eep_QuickWrite function
*/
static FUNC( Std_ReturnType, EEP_CODE ) Eep_CheckParaInputQuickWrite
(
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pSourceAddressPtr,
    VAR( Eep_LengthType, AUTOMATIC) u32Length,
    VAR( uint16, AUTOMATIC ) u16QuickWritesLength 
)
{
    VAR(Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    
    /* in the quick writes mode only 4 bytes alligned writes are allowed */
    /* @violates @ref eep_c_REF_32 Conversions shall not be  performed between a pointer 
    * @violates @ref eep_c_REF_8 A cast should not be performed between a pointer type */
    if((u32TargetAddress > (Eep_AddressType)EEP_TOTAL_SIZE ) || ((u32TargetAddress % EEP_PAGE_SIZE_4BYTES) != 0U) || \
             ((((uint32)pSourceAddressPtr) % EEP_PAGE_SIZE_4BYTES) != 0U)
           )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_PARAM_ADDRESS );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if (( 0U == u32Length ) || ((u32TargetAddress + u32Length) >(Eep_AddressType)EEP_TOTAL_SIZE) || (16U > u16QuickWritesLength) || \
             (512U < u16QuickWritesLength) || ((u16QuickWritesLength % 4U) != 0U) || ((u32Length % u16QuickWritesLength) != 0U)
            )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_PARAM_LENGTH );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else 
    {
        /* Parameter Input in Eep_QuickWrite funtion is satisfied */
        u8RetVal = (Std_ReturnType)E_OK;
    }
    return u8RetVal;
}
/**
* @brief            Write one or more complete eeprom pages to the eeprom device in quick write mode.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   Eep_MainFunction.
*
* @param[in]        TargetAddress               Target address in eeprom memory.
* @param[in]        SourceAddressPtr            Pointer to source data buffer.
* @param[in]        Length                      Number of bytes to write.
* @param[in]        u16QuickWritesLength        Number of bytes to allocated for quick write
*
* @return           Std_ReturnType
* @retval           E_OK                 Write command has been accepted.
* @retval           E_NOT_OK             Write command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @implements       Eep_QuickWrite_Activity
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, EEP_CODE ) Eep_QuickWrite
(
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pSourceAddressPtr,
    VAR( Eep_LengthType, AUTOMATIC) u32Length,
    VAR( uint16, AUTOMATIC ) u16QuickWritesLength 
)
{
    VAR(Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    
    u8RetVal = (Std_ReturnType)Eep_CheckParaInputQuickWrite(u32TargetAddress, pSourceAddressPtr, u32Length, u16QuickWritesLength);
    if ((Std_ReturnType)E_NOT_OK == u8RetVal)
    {
        /* @violates @ref eep_c_REF_5 Return statement before end of function. */
        return u8RetVal;
    }
    else if( NULL_PTR == pSourceAddressPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_PARAM_DATA );
        #endif
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == Eep_pConfigPtr )
    {
        #if( EEP_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_UNINIT );
        #endif 
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* enter EA to protect global variables */
        SchM_Enter_Eep_EEP_EXCLUSIVE_AREA_05();
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
            #if( EEP_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_QUICK_WRITE_ID, EEP_E_BUSY );
            #endif    
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_05();
        }
        else
        {
            /* Configure the write job */
            /* uint32 destination address which will be incremented during job processing */
            Eep_u32EepromAddrIt = u32TargetAddress;
            /* uint8 source pointer which will be incremented during job processing */
            Eep_pu8JobSrcAddrPtr = pSourceAddressPtr;
            /* remaining length to be transfered */
            Eep_u32RemainingLength = u32Length;
            Eep_eJob = EEP_JOB_WRITE;
            Eep_eUrgencyMode = EEP_URGENCY_QUICK_WRITES;
            Eep_u8JobStart = 1U;
            Eep_u16QuickWritesLength = u16QuickWritesLength;
            Eep_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Eep_EEP_EXCLUSIVE_AREA_05();
        }    
    }

    return u8RetVal;
}
#endif 

#if( EEP_VERSION_INFO_API == STD_ON )|| defined(__DOXYGEN__)
/**
* @brief        Returns version information about EEP module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] pVersionInfoPtr  Pointer to where to store the version information of this module.
*
* @api
*
* @implements       Eep_GetVersionInfo_Activity
*                   
*/
/*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, EEP_CODE ) Eep_GetVersionInfo
(
    P2VAR( Std_VersionInfoType, AUTOMATIC, EEP_APPL_DATA ) pVersionInfoPtr 
)
{
#if( EEP_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == pVersionInfoPtr )
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_GETVERSIONINFO_ID, EEP_E_PARAM_POINTER );
    }
    else
    {
#endif /* EEP_DEV_ERROR_DETECT == STD_ON */
        pVersionInfoPtr->moduleID = (uint16)EEP_MODULE_ID;
        pVersionInfoPtr->vendorID = (uint16)EEP_VENDOR_ID;
        pVersionInfoPtr->sw_major_version = (uint8)EEP_SW_MAJOR_VERSION;
        pVersionInfoPtr->sw_minor_version = (uint8)EEP_SW_MINOR_VERSION;
        pVersionInfoPtr->sw_patch_version = (uint8)EEP_SW_PATCH_VERSION;
#if( EEP_DEV_ERROR_DETECT == STD_ON )        
    }
#endif /* EEP_DEV_ERROR_DETECT == STD_ON */
}
#endif

#if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 /**
* @brief        Reports DEM errors
* @details      Reports production errors.
*
* @param[in,out] -
*
* @api
*                   
*/
static FUNC( void, EEP_CODE ) Eep_ReportDemErrors(void)
{
    switch( Eep_eJob )
    {
        case EEP_JOB_ERASE:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_EraseFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;
        case EEP_JOB_WRITE:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_WriteFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;              
        case EEP_JOB_READ:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_ReadFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_ReadFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;
        #if(EEP_COMPARE_API == STD_ON)                
        case EEP_JOB_COMPARE:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_CompareFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_CompareFailedCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            break;
        #endif                      
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }
}
/**
* @brief        Reports DEM passes
* @details      Reports production passes.
*
* @param[in,out] -
*
* @api
*                   
*/
static FUNC( void, EEP_CODE ) Eep_ReportDemPasses(void)
{
    switch( Eep_eJob )
    {
        case EEP_JOB_ERASE:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_EraseFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_EraseFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;
        case EEP_JOB_WRITE:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_WriteFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_WriteFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;              
        case EEP_JOB_READ:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_ReadFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_ReadFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;
        #if(EEP_COMPARE_API == STD_ON)                
        case EEP_JOB_COMPARE:
            if ((VAR(boolean, EEP_VAR))TRUE == Eep_pConfigPtr->Eep_E_CompareFailedCfg.state)
            {
                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))Eep_pConfigPtr->Eep_E_CompareFailedCfg.id, DEM_EVENT_STATUS_PASSED);
            }
            break;
        #endif                      
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               default clause added to fulfill MISRA Rule 15.3 */
            break;
    }
}
#endif
/**
* @brief            Performs actual eeprom read, write, erase and compare jobs.
* @pre              The module has to be initialized.
* @param[in]        eJob  Currently executed job (erase, write, read, or compare)
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.                   

*/
static FUNC( MemIf_JobResultType, EEP_CODE ) Eep_ProcessRequestedJobs
( 
    VAR(Eep_JobType, AUTOMATIC) eJob
)
{
    VAR(MemIf_JobResultType, AUTOMATIC) eRetVal = MEMIF_JOB_FAILED;

    switch( eJob )
    {
        case EEP_JOB_ERASE:
                /*for FLEXRAM ERASE will be implemented by writing the erased value
                  because there is no FLEXRAM suppot for erase */
                eRetVal = Eep_ProcessWriteJob();
            break;
        case EEP_JOB_WRITE:
                eRetVal = Eep_ProcessWriteJob();
            break;              
        case EEP_JOB_READ:
                eRetVal = Eep_ProcessReadJob();
            break;
        #if (EEP_COMPARE_API == STD_ON)                
        case EEP_JOB_COMPARE:
                eRetVal = Eep_ProcessCompareJob();         
            break;
        #endif
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }
    return eRetVal;
}
/**
* @brief            Only implement first time in Eep_mainfunction which is started for a new jobs.
*       
* @param[in]        None
*
* @pre              The module has to be initialized.
*                   
*/
static FUNC( void, EEP_CODE ) Eep_StartJobs( void )
{
    #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON) 
    VAR(MemIf_JobResultType, AUTOMATIC) eSetUrgencyResult = MEMIF_JOB_OK;
    #endif

    #if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
    /* Load position independent access code */
    if(( EEP_JOB_ERASE == Eep_eJob ) || ( EEP_JOB_WRITE == Eep_eJob ))
    {
        Eep_LoadAc();
    }
    #endif
    #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON) 
    /* go to quick writes mode */    
    if ((EEP_URGENCY_QUICK_WRITES == Eep_eUrgencyMode) && (EEP_JOB_WRITE == Eep_eJob))
    {
        eSetUrgencyResult = Eep_SetUrgencyMode(EEP_URGENCY_QUICK_WRITES); 
        if (MEMIF_JOB_FAILED == eSetUrgencyResult) 
        {
            Eep_eUrgencyMode = EEP_URGENCY_NORMAL_WRITES;
        } 
    }
    #endif
    /* initialize low level driver variables */
    Eep_Eeprom_InitJob(Eep_pu8JobSrcAddrPtr, Eep_u32EepromAddrIt, Eep_u32RemainingLength, Eep_eJob);
}
/**
* @brief            Only executed at the end of a new job 
*       
* @param[in]        None
*
* @pre              The module has to be initialized.
*                   
*/
static FUNC( void, EEP_CODE ) Eep_EndJobs( void )
{
    
    #if (EEP_ENABLE_QUICK_WRITES_API == STD_ON)
    /* if the quick write job finished succesfully then go back to the normal mode */    
    if((EEP_URGENCY_QUICK_WRITES == Eep_eUrgencyMode) && (EEP_JOB_WRITE == Eep_eJob))
    {
        if(MEMIF_JOB_OK == Eep_SetUrgencyMode(EEP_URGENCY_NORMAL_WRITES))
        {
            Eep_eUrgencyMode = EEP_URGENCY_NORMAL_WRITES;
        }
    }
    #endif
    /* unload access code */
    #if( EEP_AC_LOAD_ON_JOB_START == STD_ON )
    if(( EEP_JOB_ERASE == Eep_eJob ) || ( EEP_JOB_WRITE == Eep_eJob ))
    {
        Eep_UnloadAc();
    }
    #endif
    #if (EEP_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* if job failed report errors */
    if (MEMIF_JOB_FAILED == Eep_eJobResult)
    {
        Eep_ReportDemErrors();
    }
    else if (MEMIF_JOB_OK == Eep_eJobResult)
    {
        Eep_ReportDemPasses();
    }
    else
    {
       /* Not report any dems */
    }
    #endif
    /* call notifications when job was finished */
    if(( MEMIF_JOB_FAILED == Eep_eJobResult ) || ( MEMIF_BLOCK_INCONSISTENT == Eep_eJobResult ) || ( MEMIF_JOB_OK == Eep_eJobResult ))
    {
        Eep_CallNotification(Eep_eJobResult);
    }
}
/**
* @brief            Performs actual eeprom read, write, erase and compare jobs.
* @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
*                   current EEP module's operating mode (normal, fast)
*                   and write, erase Mode of Execution (sync, async).
*
* @api
*
* @pre              The module has to be initialized.
*
*
* @implements       Eep_MainFunction_Activity
*                   
* @note             This function have to be called ciclically by the Basic Software Module; 
*                   it will do nothing if there aren't pending job.
*/
/*
* @violates @ref eep_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, EEP_CODE ) Eep_MainFunction( void )
{
    
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Eep_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)EEP_MODULE_ID, EEP_INSTANCE_ID, EEP_MAINFUNCTION_ID, EEP_E_UNINIT );
    }
    else
    { 
    #endif   
        if( MEMIF_JOB_PENDING == Eep_eJobResult )
        {
            
            if( 1U == Eep_u8JobStart )
            {  
                /* only executed at the beginning of a new job */
                Eep_u8JobStart = 0U;
                Eep_StartJobs();
            }
            /* Process the requested jobs : write, compare, erase, read */
            Eep_eJobResult = Eep_ProcessRequestedJobs(Eep_eJob);
            
            if(MEMIF_JOB_PENDING != Eep_eJobResult)
            {
                /* only executed at the end of a new job */
                Eep_EndJobs();
            }
        }
        else
        {
            /* Nothing to do since no job is pending */
        }
    #if( EEP_DEV_ERROR_DETECT == STD_ON )
    }    
    #endif    /* EEP_DEV_ERROR_DETECT == STD_ON */
}

#define EEP_STOP_SEC_CODE
/* 
* @violates @ref eep_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref eep_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
/*Compiler_Warning: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly. 
   Compiler wrongfully reports the warnings at the last line of the file. 
*/
