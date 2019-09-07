/**
*   @file    Mcl_Lmem.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - LMEM low level driver.
*   @details LMEM module low level functions.
*
*   @addtogroup MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
*   Dependencies         : none
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section  [global]
*           Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*           on the significance of more than 31 characters. The used compilers use more than 31 chars 
*           for identifiers.
*
* @section  [global]
*           Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*           character significance and case sensitivity are supported for external identifiers.
*           This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section  [global]
*           Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
*           be implicitly converted to a different underlying type.
*           This violation due to implementation of MCAL_TRUSTED_CALL function.
*
* @section  Mcl_LMEM_c_REF_1
*           Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*           This violation is generated because conversions must not be performed between a pointer 
*           to a function and any type other than an integral type. The cast can't be avoided as it is 
*           used to access memory mapped registers.
*
* @section  Mcl_LMEM_c_REF_2
*           Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*           that 31 character significance and case sensitivity are supported for external identifiers.
*           The defines are validated.
*
* @section  Mcl_LMEM_c_REF_3
*           Violates MISRA 2004 Required Rule 19.15,Precautions shall be taken in order to prevent
*           the contents of a header file being included twice
*           This is not a violation since all header files are protected against multiple inclusions

* @section  Mcl_LMEM_c_REF_4
*           Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*           before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
*           is as  per Autosar  requirement MEMMAP003.
*
* @section  Mcl_LMEM_c_REF_5
*           Violates MISRA 2004 Required Rule 8.10, could be made static
*           The code could not be made static because it is used with external linkage.
*
* @section  Mcl_LMEM_c_REF_7
*           Violates MISRA 2004 Required Rule 13.7, Boolean within 'if' always evaluates to True.
*           Depending on the result of the underlying HW erase operation, the condition might be evaluated 
*           also to False (note the operands are initialized to FALSE).
*
* @section  Mcl_LMEM_c_REF_8
*           Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a 
*           pointer type and an integral type.
*           This violation is due to the pointer arithmetic used to write/ read
*           the data to/from the registers.
*
* @section  Mcl_LMEM_c_REF_9
*           Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*           This violation is due to function like macros defined for register operations.
*           Function like macros are used to reduce code complexity.
* @section  Mcl_LMEM_c_REF_10
*           Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
*           a preceding &, or with a paranthesised parameter list, which may be empy.
* @section  Mcl_LMEM_c_REF_11
*           Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the prototype
*           shall be visible at both the function definition and call.
*
*/
#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "CDD_Mcl_Cfg.h"
#include "Mcl_Lmem.h"
#include "StdRegMacros.h"
#include "Reg_eSys_Lmem.h"
#include "SchM_Mcl.h"
#include "Mcl_Lmem_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_LMEM_VENDOR_ID_C                    43
/** @violates @ref Mcl_LMEM_c_REF_2 MISRA 2004 Rule 1.4, Identifier clash */
#define MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Mcl_LMEM_c_REF_2 MISRA 2004 Rule 1.4, Identifier clash */
#define MCL_LMEM_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref Mcl_LMEM_c_REF_2 MISRA 2004 Rule 1.4, Identifier clash */
#define MCL_LMEM_AR_RELEASE_REVISION_VERSION_C  2
#define MCL_LMEM_SW_MAJOR_VERSION_C             1
#define MCL_LMEM_SW_MINOR_VERSION_C             0
#define MCL_LMEM_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcal.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl.c and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and CDD_Mcl_Cfg.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION_CFG))
        #error "AutoSar Version Numbers of Mcl_Lmem.c and CDD_Mcl_Cfg.h are different"
    #endif
#endif
/* Check if source file and CDD_Mcl_Cfg.h header file are of the same vendor */
#if (MCL_LMEM_VENDOR_ID_C != MCL_VENDOR_ID_CFG)
    #error "Mcl_Lmem.c and CDD_Mcl_Cfg.h have different vendor ids"
#endif
/* Check if source file and CDD_Mcl_Cfg.h header file are of the same software version */
#if ((MCL_LMEM_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_LMEM_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_LMEM_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Mcl_Lmem.c and CDD_Mcl_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Mcl_Lmem.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C != MCL_LMEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION_C != MCL_LMEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Lmem.c and Mcl_Lmem.h are different"
    #endif
#endif
/* Check if source file and Mcl_Lmem.h header file are of the same vendor */
#if (MCL_LMEM_VENDOR_ID_C != MCL_LMEM_VENDOR_ID)
    #error "Mcl_Lmem.c and Mcl_Lmem.h have different vendor ids"
#endif
/* Check if source file and Mcl_Lmem.h header file are of the same software version */
#if ((MCL_LMEM_SW_MAJOR_VERSION_C != MCL_LMEM_SW_MAJOR_VERSION) || \
     (MCL_LMEM_SW_MINOR_VERSION_C != MCL_LMEM_SW_MINOR_VERSION) || \
     (MCL_LMEM_SW_PATCH_VERSION_C != MCL_LMEM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Lmem.c and Mcl_Lmem.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and StdRegMacros.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Lmem.c and StdRegMacros.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Reg_eSys_Lmem.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C != LMEM_AR_RELEASE_MAJOR_VERSION_REG) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION_C != LMEM_AR_RELEASE_MINOR_VERSION_REG))
        #error "AutoSar Version Numbers of Mcl_Lmem.c and Reg_eSys_Lmem.h are different"
    #endif
#endif
/* Check if source file and Reg_eSys_Lmem.h header file are of the same vendor */
#if (MCL_LMEM_VENDOR_ID_C != LMEM_VENDOR_ID_REG)
    #error "Mcl_Lmem.c and Reg_eSys_Lmem.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_Lmem.h header file are of the same software version */
#if ((MCL_LMEM_SW_MAJOR_VERSION_C != LMEM_SW_MAJOR_VERSION_REG) || \
     (MCL_LMEM_SW_MINOR_VERSION_C != LMEM_SW_MINOR_VERSION_REG) || \
     (MCL_LMEM_SW_PATCH_VERSION_C != LMEM_SW_PATCH_VERSION_REG))
    #error "Software Version Numbers of Mcl_Lmem.c and Reg_eSys_Lmem.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Reg_eSys_Lmem.h header file are of the same Autosar version */
    #if ((MCL_LMEM_AR_RELEASE_MAJOR_VERSION_C != MCL_LMEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_LMEM_AR_RELEASE_MINOR_VERSION_C != MCL_LMEM_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcl_Lmem.c and Mcl_Lmem_Types.h are different"
    #endif
#endif
/* Check if source file and Reg_eSys_Lmem.h header file are of the same vendor */
#if (MCL_LMEM_VENDOR_ID_C != MCL_LMEM_TYPES_VENDOR_ID)
    #error "Mcl_Lmem.c and Reg_eSys_Lmem.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_Lmem.h header file are of the same software version */
#if ((MCL_LMEM_SW_MAJOR_VERSION_C != MCL_LMEM_TYPES_SW_MAJOR_VERSION) || \
     (MCL_LMEM_SW_MINOR_VERSION_C != MCL_LMEM_TYPES_SW_MINOR_VERSION) || \
     (MCL_LMEM_SW_PATCH_VERSION_C != MCL_LMEM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Lmem.c and Mcl_Lmem_Types.h are different"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
    #if ((STD_ON == MCL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == MCL_LMEM_USER_MODE_SUPPORT))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_ENABLE_PC() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheEnablePc))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_ENABLE_PS() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheEnablePs))
        
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_DISABLE_PC() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheDisablePc))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_DISABLE_PS() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheDisablePs))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_PC() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheFlushPc))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_PS() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheFlushPs))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_PC() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheInvalidatePc))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_PS() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheInvalidatePs))
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_PC() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheClearPc))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_PS() (Mcal_Trusted_Call_Return(Mcl_Lmem_CacheClearPs))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_MULTILINES_PC(u32PhyAddr, u32Length) (Mcal_Trusted_Call_Return2param(Mcl_Lmem_CacheFlushMultiLinesPc,(u32PhyAddr),(u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_MULTILINES_PS(u32PhyAddr, u32Length) (Mcal_Trusted_Call_Return2param(Mcl_Lmem_CacheFlushMultiLinesPs,(u32PhyAddr),(u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PC(u32PhyAddr, u32Length) (Mcal_Trusted_Call_Return2param(Mcl_Lmem_CacheInvalidateMultiLinesPc,(u32PhyAddr),(u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PS(u32PhyAddr, u32Length) (Mcal_Trusted_Call_Return2param(Mcl_Lmem_CacheInvalidateMultiLinesPs,(u32PhyAddr),(u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_MULTILINES_PC(u32PhyAddr, u32Length) (Mcal_Trusted_Call_Return2param(Mcl_Lmem_CacheClearMultiLinesPc,(u32PhyAddr),(u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_MULTILINES_PS(u32PhyAddr, u32Length) (Mcal_Trusted_Call_Return2param(Mcl_Lmem_CacheClearMultiLinesPs,(u32PhyAddr),(u32Length)))
        
                
    #else  /* (STD_OFF == MCL_ENABLE_USER_MODE_SUPPORT)   */ 
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_ENABLE_PC() (Mcl_Lmem_CacheEnablePc())
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_ENABLE_PS() (Mcl_Lmem_CacheEnablePs())
        
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_DISABLE_PC() (Mcl_Lmem_CacheDisablePc())
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_DISABLE_PS() (Mcl_Lmem_CacheDisablePs())
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_PC() (Mcl_Lmem_CacheFlushPc())
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_PS() (Mcl_Lmem_CacheFlushPs())
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_PC() (Mcl_Lmem_CacheInvalidatePc())

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_PS() (Mcl_Lmem_CacheInvalidatePs())
                
        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_PC() (Mcl_Lmem_CacheClearPc())

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_PS() (Mcl_Lmem_CacheClearPs())

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_MULTILINES_PC(u32PhyAddr, u32Length) (Mcl_Lmem_CacheFlushMultiLinesPc((u32PhyAddr), (u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_FLUSH_MULTILINES_PS(u32PhyAddr, u32Length) (Mcl_Lmem_CacheFlushMultiLinesPs((u32PhyAddr), (u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PC(u32PhyAddr, u32Length) (Mcl_Lmem_CacheInvalidateMultiLinesPc((u32PhyAddr), (u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PS(u32PhyAddr, u32Length) (Mcl_Lmem_CacheInvalidateMultiLinesPs((u32PhyAddr), (u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_MULTILINES_PC(u32PhyAddr, u32Length) (Mcl_Lmem_CacheClearMultiLinesPc((u32PhyAddr), (u32Length)))

        /** @violates @ref Mcl_LMEM_c_REF_9 Function-like macro defined.*/
        #define  LMEM_CALL_CACHE_CLEAR_MULTILINES_PS(u32PhyAddr, u32Length) (Mcl_Lmem_CacheClearMultiLinesPs((u32PhyAddr), (u32Length)))                            
    #endif

#endif /* #if (MCL_LMEM_ENABLE_CACHE_API == STD_ON) */
#endif /* #ifdef MCL_LMEM_ENABLE_CACHE_API */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushLinePc(uint32 u32PhyAddr);
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateLinePc(uint32 u32PhyAddr);
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearLinePc(uint32 u32PhyAddr);    
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheLaunchCommand(uint32 u32CacheRegAddr, uint32 u32CacheCmd, uint32 u32GoBitMask);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheEnablePc(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheDisablePc(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushPc(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidatePc(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearPc(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushMultiLinesPc(uint32 u32PhyAddr, uint32 u32Length);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateMultiLinesPc(uint32 u32PhyAddr, uint32 u32Length);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearMultiLinesPc(uint32 u32PhyAddr, uint32 u32Length);

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushLinePs(uint32 u32PhyAddr);
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateLinePs(uint32 u32PhyAddr);
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearLinePs(uint32 u32PhyAddr);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheEnablePs(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheDisablePs(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushPs(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidatePs(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearPs(void);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushMultiLinesPs(uint32 u32PhyAddr, uint32 u32Length);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateMultiLinesPs(uint32 u32PhyAddr, uint32 u32Length);
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearMultiLinesPs(uint32 u32PhyAddr, uint32 u32Length);
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

#endif /* #if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)  */
#endif /* #ifdef MCL_LMEM_ENABLE_CACHE_API  */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_LMEM_c_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of a header file being included twice */
/** @violates @ref Mcl_LMEM_c_REF_4 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include". */
#include "Mcl_MemMap.h"

#ifdef MCL_LMEM_ENABLE_CACHE_API
#if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)
       
/**
* @brief        Mcl_Lmem_CacheEnablePc
* @details      This function is used for invalidating and enabling cache on PC bus.
*
* @param[in]    void
*              
* @param[out]   none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/    
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheEnablePc(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
 
#if(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER) 
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32 | LMEM_CCR_ENCACHE_MASK_U32 | LMEM_CCR_ENWRBUF_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
#else                                     
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32 | LMEM_CCR_ENCACHE_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));                                 
#endif /*(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER)*/    
   
    return retVal;
}
 
#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/**
* @brief        Mcl_Lmem_CacheEnablePs
* @details      This function is used for invalidating and enabling cache on PS bus.
*
* @param[in]    void
*              
* @param[out]   none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/    
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheEnablePs(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
 
#if(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER) 
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32 | LMEM_CCR_ENCACHE_MASK_U32 | LMEM_CCR_ENWRBUF_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
#else                                     
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32 | LMEM_CCR_ENCACHE_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));                                
#endif /*(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER)*/     
   
    return retVal;
}
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

/**
* @brief        Mcl_Lmem_CacheDisablePc
* @details      This function is used for enabling cache on PC bus
*
* @param[in]    void
*              
* @param[out]   none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/    
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheDisablePc(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32CacheTimeout = MCL_LMEM_CACHE_TIMEOUT_VALUE; 

     /* Enter exclusive area to protect LMEM_PCCCR and PSCCR */
     SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_32();
     
#if(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER)
    /* Invalidate cache and enable cache and write buffer */
    /** @violates @ref Mcl_LMEM_c_REF_1 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PCCCR_ADDR32, (uint32)(LMEM_CCR_ENCACHE_MASK_U32 | LMEM_CCR_ENWRBUF_MASK_U32));
#else 
    /* Invalidate cache and enable cache */
    /** @violates @ref Mcl_LMEM_c_REF_1 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PCCCR_ADDR32, (uint32)LMEM_CCR_ENCACHE_MASK_U32);    
#endif /*(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER)*/   
       
    /** @violates @ref Mcl_LMEM_c_REF_1 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    while((LMEM_CCR_GO_MASK_U32 == (LMEM_CCR_GO_MASK_U32 & REG_READ32(LMEM_PCCCR_ADDR32))) && (0UL != u32CacheTimeout))
    {
        u32CacheTimeout--;
    }    
    
    /* Exit exclusive area to protect LMEM_PCCCR and PSCCR */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_32();
    
    /* Check if while loop above exited on timeout */
    if(0U == u32CacheTimeout)
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return retVal;
}

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/**
* @brief        Mcl_Lmem_CacheDisablePs
* @details      This function is used for enabling cache on PS bus
*
* @param[in]    void
*              
* @param[out]   none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/    
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheDisablePs(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32CacheTimeout = MCL_LMEM_CACHE_TIMEOUT_VALUE;
    
    /* Enter exclusive area to protect LMEM_PCCCR and PSCCR */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_33();
#if(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER)
    /* Invalidate cache and enable cache and write buffer */
    /** @violates @ref Mcl_LMEM_c_REF_1 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PSCCR_ADDR32, (uint32)(LMEM_CCR_ENCACHE_MASK_U32 | LMEM_CCR_ENWRBUF_MASK_U32));
#else 
    /* Invalidate cache and enable cache */
    /** @violates @ref Mcl_LMEM_c_REF_1 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PSCCR_ADDR32, (uint32)LMEM_CCR_ENCACHE_MASK_U32);    
#endif /*(STD_ON == MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER)*/
    
    /** @violates @ref Mcl_LMEM_c_REF_1 Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    while((LMEM_CCR_GO_MASK_U32 == (LMEM_CCR_GO_MASK_U32 & REG_READ32(LMEM_PSCCR_ADDR32))) && (0UL != u32CacheTimeout))
    {
        u32CacheTimeout--;
    }   

    /* Exit exclusive area to protect LMEM_PCCCR and PSCCR */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_33();
    
    /* Check if while loop above exited on timeout */
    if(0U == u32CacheTimeout)
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
   
    return retVal;
}
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

/**
* @brief       Mcl_Lmem_CacheFlushPs
* @details     This function is used for flushing cache on PC bus
*
* @param[in]   void
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/    
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushPc(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_PUSHW0_MASK_U32 | LMEM_CCR_PUSHW1_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
    
    return retVal;
}  

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)  
/**
* @brief       Mcl_Lmem_CacheFlushPs
* @details     This function is used for flushing cache on PS bus
*
* @param[in]   void
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */    
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushPs(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_PUSHW0_MASK_U32 | LMEM_CCR_PUSHW1_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
    
    return retVal;
}     
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/  

/**
* @brief       Mcl_Lmem_CacheInvalidatePc
* @details     This function is used for invalidating cache on PC bus
*
* @param[in]   void
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidatePc(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
    
    return retVal;
}  

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/**
* @brief       Mcl_Lmem_CacheInvalidatePs
* @details     This function is used for invalidating cache on PS bus
*
* @param[in]   void
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*      
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidatePs(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
    
    return retVal;
}  
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

/**
* @brief       Mcl_Lmem_CacheClearPc
* @details     This function is used for clearing cache on PC bus
*
* @param[in]   void
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearPc(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32 | LMEM_CCR_PUSHW0_MASK_U32 | LMEM_CCR_PUSHW1_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
    
    return retVal;
} 

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/**
* @brief       Mcl_Lmem_CacheClearPs
* @details     This function is used for clearing cache on PS bus
*
* @param[in]   void
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearPs(void)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCCR_ADDR32, \
                                     (uint32)(LMEM_CCR_INVW0_MASK_U32 | LMEM_CCR_INVW1_MASK_U32 | LMEM_CCR_PUSHW0_MASK_U32 | LMEM_CCR_PUSHW1_MASK_U32), \
                                     (uint32)(LMEM_CCR_GO_MASK_U32));
    
    return retVal;
}   
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

/**
* @brief        Mcl_Lmem_CacheFlushMultiLinesPc
* @details      This function flushes multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               flushes the lines which contain the specified address range.
*               Flush cache - flushes a cache entry if it is valid and modified, then clears the
*               modify bit. If it is not modified or not valid, no change is made.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushMultiLinesPc(uint32 u32PhyAddr, uint32 u32Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32EndAddr = u32PhyAddr + u32Length;
    
    /* Align physical address to the cache line size. */
    u32PhyAddr = u32PhyAddr & ~(MCL_LMEM_CACHE_LINE_SIZE - 1U);
    
    /* Flush entire cache if length is greater than half the size of the cache. */
    if (u32Length >= (MCL_LMEM_CACHE_PC_SIZE/2U))
    {
        retVal = Mcl_Lmem_CacheFlushPc();
    }
    else /* Else, invalidate by line. */
    {
        while((u32PhyAddr < u32EndAddr) && (retVal == (Std_ReturnType)E_OK))
        {
            retVal = Mcl_Lmem_CacheFlushLinePc(u32PhyAddr);
            u32PhyAddr = u32PhyAddr + MCL_LMEM_CACHE_LINE_SIZE;
        }
    }
        
    return retVal;
} 

/**
* @brief        Mcl_Lmem_CacheInvalidateMultiLinesPc
* @details      This function invalidates multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               invalidates the lines which contain the specified address range.
*               Invalidate cache - Invalidates a cache entry, by clearing the
*               valid and modify bits, irrespective of their state.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api    
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateMultiLinesPc(uint32 u32PhyAddr, uint32 u32Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32EndAddr = u32PhyAddr + u32Length;
    
    /* Align physical address to the cache line size. */
    u32PhyAddr = u32PhyAddr & ~(MCL_LMEM_CACHE_LINE_SIZE - 1U);
    
    /* Flush entire cache if length is greater than half the size of the cache. */
    if (u32Length >= (MCL_LMEM_CACHE_PC_SIZE/2U))
    {
        retVal = Mcl_Lmem_CacheInvalidatePc();
    }
    else /* Else, invalidate by line. */
    {
        while((u32PhyAddr < u32EndAddr) && (retVal == (Std_ReturnType)E_OK))
        {
            retVal = Mcl_Lmem_CacheInvalidateLinePc(u32PhyAddr);
            u32PhyAddr = u32PhyAddr + MCL_LMEM_CACHE_LINE_SIZE;
        }
    }
        
    return retVal;
}

/**
* @brief        Mcl_Lmem_CacheClearMultiLinesPc
* @details      This function clears multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               clears the lines which contain the specified address range.
*               Clear cache - flushes a cache entry if it is valid and modified, then clears the
*               valid and modify bits. If it is not modified, only clears the valid bit.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api    
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearMultiLinesPc(uint32 u32PhyAddr, uint32 u32Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32EndAddr = u32PhyAddr + u32Length;
    
    /* Align physical address to the cache line size. */
    u32PhyAddr = u32PhyAddr & ~(MCL_LMEM_CACHE_LINE_SIZE - 1U);
    
    /* Flush entire cache if length is greater than half the size of the cache. */
    if (u32Length >= (MCL_LMEM_CACHE_PC_SIZE/2U))
    {
        retVal = Mcl_Lmem_CacheClearPc();
    }
    else /* Else, invalidate by line. */
    {
        while((u32PhyAddr < u32EndAddr) && (retVal == (Std_ReturnType)E_OK))
        {
            retVal = Mcl_Lmem_CacheClearLinePc(u32PhyAddr);
            u32PhyAddr = u32PhyAddr + MCL_LMEM_CACHE_LINE_SIZE;
        }
    }
        
    return retVal;
}

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/**
* @brief        Mcl_Lmem_CacheFlushMultiLinesPs
* @details      This function flushes multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               flushes the lines which contain the specified address range.
*               Flush cache - flushes a cache entry if it is valid and modified, then clears the
*               modify bit. If it is not modified or not valid, no change is made.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushMultiLinesPs(uint32 u32PhyAddr, uint32 u32Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32EndAddr = u32PhyAddr + u32Length;
    
    /* Align physical address to the cache line size. */
    u32PhyAddr = u32PhyAddr & ~(MCL_LMEM_CACHE_LINE_SIZE - 1U);
    
    /* Flush entire cache if length is greater than half the size of the cache. */
    if (u32Length >= (MCL_LMEM_CACHE_PS_SIZE/2))
    {
        retVal = Mcl_Lmem_CacheFlushPs();
    }
    else /* Else, invalidate by line. */
    {
        while((u32PhyAddr < u32EndAddr) && (retVal == (Std_ReturnType)E_OK))
        {
            retVal = Mcl_Lmem_CacheFlushLinePs(u32PhyAddr);
            u32PhyAddr = u32PhyAddr + MCL_LMEM_CACHE_LINE_SIZE;
        }
    }
        
    return retVal;
} 

/**
* @brief        Mcl_Lmem_CacheInvalidateMultiLinesPs
* @details      This function invalidates multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               invalidates the lines which contain the specified address range.
*               Invalidate cache - Invalidates a cache entry, by clearing the
*               valid and modify bits, irrespective of their state.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api    
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateMultiLinesPs(uint32 u32PhyAddr, uint32 u32Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32EndAddr = u32PhyAddr + u32Length;
    
    /* Align physical address to the cache line size. */
    u32PhyAddr = u32PhyAddr & ~(MCL_LMEM_CACHE_LINE_SIZE - 1U);
    
    /* Flush entire cache if length is greater than half the size of the cache. */
    if (u32Length >= (MCL_LMEM_CACHE_PS_SIZE/2))
    {
        retVal = Mcl_Lmem_CacheInvalidatePs();
    }
    else /* Else, invalidate by line. */
    {
        while((u32PhyAddr < u32EndAddr) && (retVal == (Std_ReturnType)E_OK))
        {
            retVal = Mcl_Lmem_CacheInvalidateLinePs(u32PhyAddr);
            u32PhyAddr = u32PhyAddr + MCL_LMEM_CACHE_LINE_SIZE;
        }
    }
        
    return retVal;
}

/**
* @brief        Mcl_Lmem_CacheClearMultiLinesPs
* @details      This function clears multiple lines in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               clears the lines which contain the specified address range.
*               Clear cache - flushes a cache entry if it is valid and modified, then clears the
*               valid and modify bits. If it is not modified, only clears the valid bit.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]   none
*
* @return       The validity of the function call
* @retval       E_OK        The function call is valid
* @retval       E_NOT_OK    The function call is invalid
*
* @api    
*/
/** @violates @ref Mcl_LMEM_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */  
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearMultiLinesPs(uint32 u32PhyAddr, uint32 u32Length)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32EndAddr = u32PhyAddr + u32Length;
    
    /* Align physical address to the cache line size. */
    u32PhyAddr = u32PhyAddr & ~(MCL_LMEM_CACHE_LINE_SIZE - 1U);
    
    /* Flush entire cache if length is greater than half the size of the cache. */
    if (u32Length >= (MCL_LMEM_CACHE_PS_SIZE/2))
    {
        retVal = Mcl_Lmem_CacheClearPs();
    }
    else /* Else, invalidate by line. */
    {
        while((u32PhyAddr < u32EndAddr) && (retVal == (Std_ReturnType)E_OK))
        {
            retVal = Mcl_Lmem_CacheClearLinePs(u32PhyAddr);
            u32PhyAddr = u32PhyAddr + MCL_LMEM_CACHE_LINE_SIZE;
        }
    }
        
    return retVal;
}
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

/**
* @brief        Mcl_Lmem_CacheFlushLinePc
* @details      This function flushes one line in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               flushes the line which contains the specified address.
*               Flush cache - flushes a cache entry if it is valid and modified, then clears the
*               modify bit. If it is not modified or not valid, no change is made.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushLinePc(uint32 u32PhyAddr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Place the flush cache line command into CLCR[27:24] register */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_RMW32(LMEM_PCCLCR_ADDR32, LMEM_CLCR_LINE_CMD_MASK_U32, LMEM_CLCR_LINE_FLUSH_PHY_ADDR_U32);
    /* Select data control in tag/data select CLCR[TDSEL] register. The cache line command will operate on the data part of the cache line. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PCCLCR_ADDR32, LMEM_CLCR_LINE_TDSEL_MASK_U32);    
    /* Place the physical address in CSAR[PHYADDR], last two LSB bits are zeroed to avoid setting the LGO and reserved bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_WRITE32(LMEM_PCCSAR_ADDR32, (u32PhyAddr & LMEM_CSAR_PHYADDR_MASK_U32));
    /* Launch the command by setting CSAR[LGO] bit */
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCSAR_ADDR32, (uint32)0UL, (uint32)LMEM_CSAR_LGO_MASK_U32);
                                     
    return retVal; 
} 

/**
* @brief        Mcl_Lmem_CacheInvalidateLinePc
* @details      This function invalidates one line in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               invalidates the line which contains the specified address.
*               Invalidate cache - Invalidates a cache entry, by clearing the
*               valid and modify bits, irrespective of their state.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateLinePc(uint32 u32PhyAddr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Place the flush cache line command into CLCR[27:24] register */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_RMW32(LMEM_PCCLCR_ADDR32, LMEM_CLCR_LINE_CMD_MASK_U32, LMEM_CLCR_LINE_INVAL_PHY_ADDR_U32);
    /* Select data control in tag/data select CLCR[TDSEL] register. The cache line command will operate on the data part of the cache line. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PCCLCR_ADDR32, LMEM_CLCR_LINE_TDSEL_MASK_U32);    
    /* Place the physical address in CSAR[PHYADDR], last two LSB bits are zeroed to avoid setting the LGO and reserved bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_WRITE32(LMEM_PCCSAR_ADDR32, (u32PhyAddr & LMEM_CSAR_PHYADDR_MASK_U32));
    /* Launch the command by setting CSAR[LGO] bit */
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCSAR_ADDR32, (uint32)0UL, (uint32)LMEM_CSAR_LGO_MASK_U32);
                                     
    return retVal; 
} 

/**
* @brief        Mcl_Lmem_CacheClearLinePc
* @details      This function clears one line in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               clears the line which contains the specified address.
*               Clear cache - flushes a cache entry if it is valid and modified, then clears the
*               valid and modify bits. If it is not modified, only clears the valid bit.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearLinePc(uint32 u32PhyAddr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Place the flush cache line command into CLCR[27:24] register */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_RMW32(LMEM_PCCLCR_ADDR32, LMEM_CLCR_LINE_CMD_MASK_U32, LMEM_CLCR_LINE_CLEAR_PHY_ADDR_U32);
    /* Select data control in tag/data select CLCR[TDSEL] register. The cache line command will operate on the data part of the cache line. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PCCLCR_ADDR32, LMEM_CLCR_LINE_TDSEL_MASK_U32);    
    /* Place the physical address in CSAR[PHYADDR], last two LSB bits are zeroed to avoid setting the LGO and reserved bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_WRITE32(LMEM_PCCSAR_ADDR32, (u32PhyAddr & LMEM_CSAR_PHYADDR_MASK_U32));
    /* Launch the command by setting CSAR[LGO] bit */
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PCCSAR_ADDR32, (uint32)0UL, (uint32)LMEM_CSAR_LGO_MASK_U32);
                                     
    return retVal; 
}

#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)
/**
* @brief        Mcl_Lmem_CacheFlushLinePs
* @details      This function flushes one line in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               flushes the line which contains the specified address.
*               Flush cache - flushes a cache entry if it is valid and modified, then clears the
*               modify bit. If it is not modified or not valid, no change is made.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushLinePs(uint32 u32PhyAddr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Place the flush cache line command into CLCR[27:24] register */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_RMW32(LMEM_PSCLCR_ADDR32, LMEM_CLCR_LINE_CMD_MASK_U32, LMEM_CLCR_LINE_FLUSH_PHY_ADDR_U32);
    /* Select data control in tag/data select CLCR[TDSEL] register. The cache line command will operate on the data part of the cache line. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PSCLCR_ADDR32, LMEM_CLCR_LINE_TDSEL_MASK_U32);    
    /* Place the physical address in CSAR[PHYADDR], last two LSB bits are zeroed to avoid setting the LGO and reserved bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_WRITE32(LMEM_PSCSAR_ADDR32, (u32PhyAddr & LMEM_CSAR_PHYADDR_MASK_U32));
    /* Launch the command by setting CSAR[LGO] bit */
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCSAR_ADDR32, (uint32)0UL, (uint32)LMEM_CSAR_LGO_MASK_U32);
                                     
    return retVal; 
} 

/**
* @brief        Mcl_Lmem_CacheInvalidateLinePs
* @details      This function invalidates one line in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               invalidates the line which contains the specified address.
*               Invalidate cache - Invalidates a cache entry, by clearing the
*               valid and modify bits, irrespective of their state.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidateLinePs(uint32 u32PhyAddr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Place the flush cache line command into CLCR[27:24] register */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_RMW32(LMEM_PSCLCR_ADDR32, LMEM_CLCR_LINE_CMD_MASK_U32, LMEM_CLCR_LINE_INVAL_PHY_ADDR_U32);
    /* Select data control in tag/data select CLCR[TDSEL] register. The cache line command will operate on the data part of the cache line. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PSCLCR_ADDR32, LMEM_CLCR_LINE_TDSEL_MASK_U32);    
    /* Place the physical address in CSAR[PHYADDR], last two LSB bits are zeroed to avoid setting the LGO and reserved bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_WRITE32(LMEM_PSCSAR_ADDR32, (u32PhyAddr & LMEM_CSAR_PHYADDR_MASK_U32));
    /* Launch the command by setting CSAR[LGO] bit */
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCSAR_ADDR32, (uint32)0UL, (uint32)LMEM_CSAR_LGO_MASK_U32);
                                     
    return retVal; 
} 

/**
* @brief        Mcl_Lmem_CacheClearLinePs
* @details      This function clears one line in the specified cache instance.
*               The functions searches the specified cache instance and if there is a hit,
*               clears the line which contains the specified address.
*               Clear cache - flushes a cache entry if it is valid and modified, then clears the
*               valid and modify bits. If it is not modified, only clears the valid bit.
*
* @param[in]    u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
* @param[in]    u32Length       The length of the memory region to be searched for in the cache.
*              
* @param[out]  none
*
* @return       The completion status of the cache command
* @retval       E_OK        Cache command completed succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command completed unsuccesfuly, timeout occured. 
*
* @api
*     
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearLinePs(uint32 u32PhyAddr)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    
    /* Place the flush cache line command into CLCR[27:24] register */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_RMW32(LMEM_PSCLCR_ADDR32, LMEM_CLCR_LINE_CMD_MASK_U32, LMEM_CLCR_LINE_CLEAR_PHY_ADDR_U32);
    /* Select data control in tag/data select CLCR[TDSEL] register. The cache line command will operate on the data part of the cache line. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(LMEM_PSCLCR_ADDR32, LMEM_CLCR_LINE_TDSEL_MASK_U32);    
    /* Place the physical address in CSAR[PHYADDR], last two LSB bits are zeroed to avoid setting the LGO and reserved bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_WRITE32(LMEM_PSCSAR_ADDR32, (u32PhyAddr & LMEM_CSAR_PHYADDR_MASK_U32));
    /* Launch the command by setting CSAR[LGO] bit */
    retVal = Mcl_Lmem_CacheLaunchCommand((uint32)LMEM_PSCSAR_ADDR32, (uint32)0UL, (uint32)LMEM_CSAR_LGO_MASK_U32);
                                     
    return retVal; 
}
#endif /*#if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE)*/

/**
* @brief        Mcl_Lmem_CacheLaunchCommand
* @details      This function is used for initiating the specified cache command.
*
* @param[in]    void
*              
* @param[out]   none 
*
* @return       The timeout status of the cache command
* @retval       E_OK        Cache command launched succesfuly, no timeout occured.
* @retval       E_NOT_OK    Cache command launched unsuccesfuly, timeout occured.
*
* @api
*      
*/
LOCAL_INLINE FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheLaunchCommand(uint32 u32CacheRegAddr, uint32 u32CacheCmd, uint32 u32GoBitMask)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32CacheTimeout = MCL_LMEM_CACHE_TIMEOUT_VALUE; 
    
    u32CacheTimeout = MCL_LMEM_CACHE_TIMEOUT_VALUE;
    
    /* Enter exclusive area to protect LMEM_PCCCR and PSCCR */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_34();
    
    /* Launch the cache command by setting the (L)GO bit together with the command bits(if any). */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    REG_BIT_SET32(u32CacheRegAddr, (uint32)(u32CacheCmd | u32GoBitMask));
        
    /* Wait for command to complete by monitoring the L(GO) bit. */
    /** @violates @ref Mcl_LMEM_c_REF_1 MISRA 2004 Rule 11.1, Cast from unsigned int to pointer */
    /** @violates @ref Mcl_LMEM_c_REF_8 Violates MISRA 2004 Required Rule 11.3, cast from unsigned long to pointer. */
    while((u32GoBitMask == (u32GoBitMask & REG_READ32(u32CacheRegAddr))) && (0UL != u32CacheTimeout))
    {
        u32CacheTimeout--;
    }   

    /* Exit exclusive area to protect LMEM_PCCCR and PSCCR */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_34();
    
    /* Check if while loop above exited on timeout */
    if(0U == u32CacheTimeout)
    {
        retVal = (Std_ReturnType)E_NOT_OK;
    }
    
    return retVal;
}


/*==================================================================================================*/

/**
 * @brief       Lmem_CacheEnable
 * @details     This function is used for enabling the specified cache instance
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheEnable(Mcl_LmemCacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_ENABLE_PC();
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_ENABLE_PS();
            break;
        #endif
        case MCL_LMEM_CACHE_ALL:  
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_ENABLE_PC();
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_ENABLE_PS();
                }
            #endif
            break;   
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}    
/**
 * @brief       Lmem_CacheDisable
 * @details     This function is used for disabling the specified cache instance
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheDisable(Mcl_LmemCacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_DISABLE_PC();
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_DISABLE_PS();
            break;
        #endif
        case MCL_LMEM_CACHE_ALL: 
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_DISABLE_PC();
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_DISABLE_PS();
                }
            #endif
            break;  
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}     
/**
 * @brief       Lmem_CacheFlush
 * @details     Flushes the specified cache
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlush(Mcl_LmemCacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_FLUSH_PC();
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_FLUSH_PS();
            break;
        #endif
        case MCL_LMEM_CACHE_ALL:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_FLUSH_PC();
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_FLUSH_PS();
                }
            #endif
            break;   
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}
/**
 * @brief       Lmem_CacheInvalidate
 * @details     Invalidates the specified cache
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheInvalidate(Mcl_LmemCacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_PC();
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_PS();
            break;
        #endif
        case MCL_LMEM_CACHE_ALL: 
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_PC();
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* If PC function call was successful call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_PS();
                }
            #endif 
            break;  
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
} 
/**
 * @brief       Lmem_CacheClear
 * @details     Cleares the specified cache
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches)
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClear(Mcl_LmemCacheInstanceType cacheInstance) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_CLEAR_PC();
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_CLEAR_PS();
            break;
        #endif
        case MCL_LMEM_CACHE_ALL:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_CLEAR_PC();
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_CLEAR_PS();
                }
            #endif 
            break;    
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}

/**
 * @brief       Lmem_CacheFlushMultiLines
 * @details     Routes API layer function to IP layer function, for flushing the specified cache lines.
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches).
 * @param[in]   u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
 * @param[in]   u32Length       The length of the memory region to be searched for in the cache.
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheFlushMultiLines(Mcl_LmemCacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_FLUSH_MULTILINES_PC(u32PhyAddr, u32Length);
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_FLUSH_MULTILINES_PS(u32PhyAddr, u32Length);
            break;
        #endif
        case MCL_LMEM_CACHE_ALL:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_FLUSH_MULTILINES_PC(u32PhyAddr, u32Length);
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_FLUSH_MULTILINES_PS(u32PhyAddr, u32Length);
                }
            #endif 
            break;    
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}
   
/**
 * @brief       Lmem_InvalidateMultiLines
 * @details     Routes API layer function to IP layer function, for invalidating the specified cache lines.
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches).
 * @param[in]   u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
 * @param[in]   u32Length       The length of the memory region to be searched for in the cache.
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_InvalidateMultiLines(Mcl_LmemCacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PC(u32PhyAddr, u32Length);
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PS(u32PhyAddr, u32Length);
            break;
        #endif
        case MCL_LMEM_CACHE_ALL:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PC(u32PhyAddr, u32Length);
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_INVALIDATE_MULTILINES_PS(u32PhyAddr, u32Length);
                }
            #endif 
            break;    
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}
   
/**
 * @brief       Lmem_CacheClearMultiLines
 * @details     Routes API layer function to IP layer function, for clearing the specified cache lines.
 *
 * @param[in]   cacheInstance   The cache instance for which the function is called(PC, PS or both caches).
 * @param[in]   u32PhyAddr      The physical start address of the memory region to be searched for in the cache.
 * @param[in]   u32Length       The length of the memory region to be searched for in the cache.
 *
 * @return      The validity of the function call
 * @retval      E_OK        The function call is valid
 * @retval      E_NOT_OK    The function call is invalid
 */ 
FUNC(Std_ReturnType, MCL_CODE) Mcl_Lmem_CacheClearMultiLines(Mcl_LmemCacheInstanceType cacheInstance, uint32 u32PhyAddr, uint32 u32Length) 
{
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    switch( cacheInstance )
    {
        case MCL_LMEM_CACHE_PC:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_CLEAR_MULTILINES_PC(u32PhyAddr, u32Length);
            break;
        #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
        case MCL_LMEM_CACHE_PS:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_CLEAR_MULTILINES_PS(u32PhyAddr, u32Length);
            break;
        #endif
        case MCL_LMEM_CACHE_ALL:
            /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
            /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
            retVal = (uint32)LMEM_CALL_CACHE_CLEAR_MULTILINES_PC(u32PhyAddr, u32Length);
            #if (STD_ON == MCL_LMEM_CACHE_PS_AVAILABLE) 
                if((Std_ReturnType)E_OK == retVal)      /* Only if PC function call was successful, call also PS function. */
                {                    
                    /**  @violates @ref Mcl_LMEM_c_REF_11 MISRA 2004 Rule 8.1 */
                    /**  @violates @ref Mcl_LMEM_c_REF_10 MISRA 2004 Rule 16.9, function identifier */
                    retVal = (uint32)LMEM_CALL_CACHE_CLEAR_MULTILINES_PS(u32PhyAddr, u32Length);
                }
            #endif 
            break;    
        default:
            /* Function parameter is invalid */
            retVal = (Std_ReturnType)E_NOT_OK;
            break;
    }
    
    return retVal;
}
  


#endif /* #if (STD_ON == MCL_LMEM_ENABLE_CACHE_API)  */
#endif /* #ifdef MCL_LMEM_ENABLE_CACHE_API  */

#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_LMEM_c_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of a header file being included twice */
/** @violates @ref Mcl_LMEM_c_REF_4 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include". */
#include "Mcl_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

