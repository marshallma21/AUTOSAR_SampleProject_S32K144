/**
*   @file           Mcal.h
*   @implements     Mcal.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction specific for MCAL.
*   @details The file Mcal.h provides MCAL specific macros used for compiler abstraction.
*
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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
* @section Mcal_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. Compiler abstraction need to implement function-like macros to hide compiler specifics from
* the implementation.
*
* @section Mcal_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Mcal_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for identifiers
* 
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*
* @section Mcal_h_REF_5
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section Mcal_h_REF_6
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as * the operand of # or ##.
* This is used to abstract compiler specific encapsulation of definitions and declarations
* 
* @section Mcal_h_REF_7
* Violates MISRA 2004 Advisory Rule 19.13, The # and ## preprocessor operators should not be used.
* This is used to abstract the trusted function calls.
* 
* @section Mcal_h_REF_8
* Violates MISRA 2004 Required Rule 19.12, There shall be at most one occurrence of the # or ## operators in a single macro definition.
* The order of evaluation does not impact the implementation of this macro, it is safe to use more instances of ## operator.
* 
*
* @section Mcal_h_REF_9
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used.
* The comma is used  to abstract the trusted call function and to determine when the return into user mode is needed.
*
*/

#ifndef MCAL_H
#define MCAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @file        Mcal.h
* @brief Include compiler abstraction
*/
/*
* @violates @ref Mcal_h_REF_2 MISRA 2004 Precautions shall be taken in order to
* prevent the contents of a header being included twice.
*/
#include "Compiler.h"
/*
* @file        Mcal.h
* @brief Include standard types
*/
/*
* @violates @ref Mcal_h_REF_2 MISRA 2004 Precautions shall be taken in order to
* prevent the contents of a header being included twice.
*/
#include "Std_Types.h"

#include "Soc_Ips.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCAL_VENDOR_ID                    43
#define MCAL_MODULE_ID                    0
/*
 * @violates @ref Mcal_h_REF_3 This is required as per autosar Requirement, 
 */
#define MCAL_AR_RELEASE_MAJOR_VERSION     4
/*
 * @violates @ref Mcal_h_REF_3 This is required as per autosar Requirement, 
 */
#define MCAL_AR_RELEASE_MINOR_VERSION     2
/*
 * @violates @ref Mcal_h_REF_3 This is required as per autosar Requirement, 
 */
#define MCAL_AR_RELEASE_REVISION_VERSION  2
#define MCAL_SW_MAJOR_VERSION             1
#define MCAL_SW_MINOR_VERSION             0
#define MCAL_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Compiler.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Compiler.h are different"
    #endif
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Soc_Ips.h header file are of the same Autosar version */
    #if ((MCAL_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCAL_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcal.h and Soc_Ips.h are different"
    #endif
#endif
/*==================================================================================================
*                                         CONSTANTS
==================================================================================================*/
#define MCAL_ARM_MARCH      (16)  /* for ARM M4 Thumb2 */
#define MCAL_ARM_AARCH32    (32)  /* for ARM ARCH32    */
#define MCAL_ARM_AARCH64    (64)  /* for ARM ARCH64    */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
#ifdef AUTOSAR_OS_NOT_USED

extern  uint8 Sys_GoToSupervisor(void);
extern  uint32 Sys_GoToUser_Return(uint8 u8SwitchToSupervisor, uint32 u32returnValue);
extern  uint32 Sys_GoToUser(void);

/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
#define Mcal_goToSupervisor() ASM_KEYWORD("svc 0x0");
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser,  a constant, a parenthesised expression */
#define Mcal_goToUser()       ASM_KEYWORD("svc 0x1");

/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call(name)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(), (void)Sys_GoToUser()) : (name(),(void)0U))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call1param(name,param)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param), (void)Sys_GoToUser()) : (name(param),(void)0U))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call2params(name,param1,param2)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2), (void)Sys_GoToUser()) : (name(param1,param2),(void)0U))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call3params(name,param1,param2,param3)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3), (void)Sys_GoToUser()) : (name(param1,param2,param3),(void)0U))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call4params(name,param1,param2,param3,param4)  \
    ((1UL == Sys_GoToSupervisor()) ? (name(param1,param2,param3,param4), (void)Sys_GoToUser()) : (name(param1,param2,param3,param4),(void)0U))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call_Return(name)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name()) :  Sys_GoToUser_Return(0U, name()))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call_Return1param(name,param)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param)) :  Sys_GoToUser_Return(0U, name(param)))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call_Return2param(name,param1,param2)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2)) : Sys_GoToUser_Return(0U, name(param1,param2)))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call_Return3param(name,param1,param2,param3)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3)))
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses*/
/** @violates @ref Mcal_h_REF_9 The comma operator shall not be used. */
#define Mcal_Trusted_Call_Return4param(name,param1,param2,param3,param4)  \
    ((1UL == Sys_GoToSupervisor()) ?  Sys_GoToUser_Return(1U, name(param1,param2,param3,param4)) :  Sys_GoToUser_Return(0U, name(param1,param2,param3,param4)))


#else
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call(name) Call_##name##_TRUSTED()
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call1param(name,param) Call_##name##_TRUSTED(param)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call2params(name,param1,param2) Call_##name##_TRUSTED(param1,param2)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call3params(name,param1,param2,param3) Call_##name##_TRUSTED(param1,param2,param3)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call4params(name,param1,param2,param3,param4) Call_##name##_TRUSTED(param1,param2,param3,param4)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call_Return(name) Call_##name##_TRUSTED()
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call_Return1param(name,param1) Call_##name##_TRUSTED(param1)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call_Return2param(name,param1,param2) Call_##name##_TRUSTED(param1,param2)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call_Return3param(name,param1,param2,param3) Call_##name##_TRUSTED(param1,param2,param3)
/** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
/** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
/** @violates @ref Mcal_h_REF_8 There shall be at most one occurrence of the # or ## operators. */
    #define Mcal_Trusted_Call_Return4param(name,param1,param2,param3,param4) Call_##name##_TRUSTED(param1,param2,param3,param4)

#endif /* AUTOSAR_OS_NOT_USED */
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
    

/* ARM_MARCH - is used to specify the ARM architecture MCAL_MARCH, MCAL_AARCH32, MCAL_AARCH64 */
/** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
#define MCAL_PLATFORM_ARM  MCAL_ARM_MARCH
 /**************************************** Green Hills *********************************************/
#ifdef _GREENHILLS_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  __asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wfi")

    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    * @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses
    */
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
    
   /**
    * @brief Compiler abstraction for the packed qualifier
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
        #define PACKED __packed 
        
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
        #define MCAL_PUT_IN_QUOTES(x) #x
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_6 Parameter not enclosed in parentheses */
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label::))
    #else
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
        
#endif /* #ifdef _GREENHILLS_C_S32K14x_ */

/**************************************** Wind River Diab *****************************************/
#ifdef _DIABDATA_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define ASM_KEYWORD  asm volatile

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD("  .word 0x7C00007C")
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
    
    /**
     * @brief Compiler abstraction for the packed qualifier
     */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define PACKED __packed__ 
    
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
        #define MCAL_PUT_IN_QUOTES(x) #x
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_6 Parameter not enclosed in parentheses */
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif

#endif /* #ifdef _DIABDATA_C_S32K14x_ */

/*************************************** CodeWarrior **********************************************/
#ifdef _CODEWARRIOR_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define ASM_KEYWORD  asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD (" opword 0x7C00007C")
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define VAR_ALIGN(v, size) v __attribute__(( aligned(size) ));
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
    
    /**
    * @brief Compiler abstraction for the packed qualifier
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define PACKED __packed 

#endif /* #ifdef _CODEWARRIOR_C_S32K14x_ */

/*************************************** Cosmic ***************************************************/
#ifdef _COSMIC_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define ASM_KEYWORD  _asm
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ASM_PUBLIC_LABEL(label)  _asm("\txdef\t" #label "\n" #label ":")

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD (" dc.l 0x7C00007C")
    /**
    * @brief Compiler abstraction for the data alignment
    */
    #define ALIGNED_VARS_START(sec_name, align) \#pragma section [sec_name ## align]
    /**
    * @brief Compiler abstraction for the data alignment
    */
    #define VAR_ALIGN(v, size) v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    #define ALIGNED_VARS_STOP() \#pragma section []
#endif /* #ifdef _COSMIC_C_S32K14x_ */

/*************************************** HighTec **********************************************/
#ifdef _HITECH_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    */
    #define ASM_KEYWORD  __asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wait")
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
#endif /* #ifdef _HITECH_C_S32K14x_ */
/**************************************** Linaro *********************************************/
#ifdef _LINARO_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  __asm
    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wfi")
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    * @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses
    */
    #define VAR_ALIGN(v, size) __attribute__(( aligned(size) )) v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
    
    /**
     * @brief Compiler abstraction for the packed qualifier
     */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define PACKED __attribute__((__packed__))
    
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
        #define MCAL_PUT_IN_QUOTES(x) #x
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */    
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_6 Parameter not enclosed in parentheses */
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
  
#endif /* #ifdef _LINARO_C_S32K14x_ */

/**************************************** DS5 *********************************************/
#ifdef _ARM_DS5_C_S32K14x_
    /**
    * @brief Compiler abstraction for the asm keyword.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  __asm
    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wfi")
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align)
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    * @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses
    */
    #define VAR_ALIGN(v, size) __align(size) v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP()
    /**
     * @brief Compiler abstraction for the packed qualifier
     */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define PACKED __packed 
    
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_7 The # and ## preprocessor operators should not be used. */
        #define MCAL_PUT_IN_QUOTES(x) #x
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /** @violates @ref Mcal_h_REF_6 Parameter not enclosed in parentheses */
        #define MCAL_FAULT_INJECTION_POINT(label) ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
    
#endif /* #ifdef _ARM_DS5_C_S32K14x_ */
/**************************************** IAR *********************************************/
#ifdef _IAR_C_S32K14x_
    
    /**
    * @brief Compiler abstraction for the "Put in Quotes".
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    #define MCAL_PUT_IN_QUOTES(x) #x
    /**
    * @brief Compiler abstraction for the "Double Put in Quotes" - Used by VAL_ALIGN.
    */
    /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
    /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
    #define MCAL_PUT_IN_QUOTES1(x) MCAL_PUT_IN_QUOTES(x)

    /**
    * @brief Compiler abstraction for the asm keyword.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    *    a constant, a parenthesised expression
    */    
    #define ASM_KEYWORD  __asm

    /**
    * @brief Compiler abstraction for the intrinsic wait instruction.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define EXECUTE_WAIT()      ASM_KEYWORD("  wfi")

    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_START(sec_name, align) 
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    * @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
    * parameter shall be enclosed in parentheses
    */
    #define VAR_ALIGN(v, size)  _Pragma(MCAL_PUT_IN_QUOTES1(data_alignment=size)) \
                                v;
    /**
    * @brief Compiler abstraction for the data alignment
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define ALIGNED_VARS_STOP() 
    
   /**
    * @brief Compiler abstraction for the packed qualifier
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define PACKED __packed 
        
    /**
     * @brief Compiler abstraction for MCAL Fault Injection tests 
    */
    #ifdef MCAL_ENABLE_FAULT_INJECTION
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define MCAL_FAULT_INJECTION_POINT(label)   ASM_KEYWORD(MCAL_PUT_IN_QUOTES(label:))
    #else
        /**  @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro. */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define MCAL_FAULT_INJECTION_POINT(label)
    #endif
        
#endif /* #ifdef _IAR_C_S32K14x_ */

/* check that the compiler used is supported (otherwise some defines might not exist) */
#ifndef _GREENHILLS_C_S32K14x_
    #ifndef _DIABDATA_C_S32K14x_
        #ifndef _CODEWARRIOR_C_S32K14x_
            #ifndef _COSMIC_C_S32K14x_
                #ifndef _HITECH_C_S32K14x_
                    #ifndef _LINARO_C_S32K14x_
                        #ifndef _ARM_DS5_C_S32K14x_
                            #ifndef _IAR_C_S32K14x_
                                #error "Unsupported compiler. Compiler abstraction needs to be updated to use this compiler."
                            #endif    
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
#endif

#if defined(AUTOSAR_OS_NOT_USED)
    #if defined (USE_SW_VECTOR_MODE)
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        */
        /*
        * @violates @ref Mcal_h_REF_1 A function should be used in
        * preference to a function-like macro.
        * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
        * a constant, a parenthesised expression
        * @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
        * parameter shall be enclosed in parentheses
        */
        #define ISR(IsrName)       void IsrName(void)
    #else
        /**
        * @brief Compiler abstraction for creating an interrupt handler if no OS is present.
        */
        /*
        * @violates @ref Mcal_h_REF_1 A function should be used in
        * preference to a function-like macro.
        * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
        * a constant, a parenthesised expression
        * @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
        * parameter shall be enclosed in parentheses
        */
        #define ISR(IsrName)       INTERRUPT_FUNC void IsrName(void)

    #endif /*USE_SW_VECTOR_MODE*/
          
    /**
    * @brief Compiler abstraction for returning from an ISR if no OS is present.
    */    
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #define EXIT_INTERRUPT()  
  
    /**
    * @brief Compiler abstraction for disabling all interrupts if no OS is present.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #if(MCAL_ARM_AARCH64 == MCAL_PLATFORM_ARM)
        /* for AARCH64 bit */
        /** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.    */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define SuspendAllInterrupts() ASM_KEYWORD(" msr DAIFSet,#0xf")   
    #else
        #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        /* for AARCH32 bit ARM/THUMB instructions */
        /** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.    */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
            #define SuspendAllInterrupts()  ASM_KEYWORD("svc 0x3")  /* BASEPRI will be set to 0x10 from SVC handler  */
        #else
       /* for AARCH32 bit ARM/THUMB instructions */
       /** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.    */
       /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
            #define SuspendAllInterrupts()  ASM_KEYWORD(" cpsid i")
        #endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
    #endif 
    /**
    * @brief Compiler abstraction for re-enabling all interrupts if no OS is present.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    * @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
    * a constant, a parenthesised expression
    */
    #if(MCAL_ARM_AARCH64 == MCAL_PLATFORM_ARM)
        /* for AARCH64 bit */
        /** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.    */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        #define ResumeAllInterrupts() ASM_KEYWORD(" msr DAIFClr,#0xf")   
    #else
        #ifdef MCAL_ENABLE_USER_MODE_SUPPORT
        /** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.    */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /* for AARCH32 bit ARM/THUMB instructions */
            #define ResumeAllInterrupts() ASM_KEYWORD("svc 0x2")  /* BASEPRI will be set to 0x0 from SVC handler  */
        #else
        /** @violates @ref Mcal_h_REF_1 A function should be used in preference to a function-like macro.    */
        /** @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, a constant, a parenthesised expression */
        /* for AARCH32 bit ARM/THUMB instructions */
            #define ResumeAllInterrupts()  ASM_KEYWORD(" cpsie i")
        #endif /* MCAL_ENABLE_USER_MODE_SUPPORT */
    #endif     
#else
    #include "Os.h"
    /**
    * @brief Compiler abstraction for returning from an ISR if OS is present must be empty.
    */
    /*
    * @violates @ref Mcal_h_REF_1 A function should be used in
    * preference to a function-like macro.
    */
    #define EXIT_INTERRUPT()
#endif

/**
* @brief The compiler abstraction for pointer to pointer to variable.
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in
* preference to a function-like macro.
* @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
* a constant, a parenthesised expression
* @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses
*/
#define P2P2VAR(ptrtype, memclass, ptrclass) ptrtype **

/**
* @brief The compiler abstraction for pointer to pointer to constant.
*/
/*
* @violates @ref Mcal_h_REF_1 A function should be used in
* preference to a function-like macro.
* @violates @ref Mcal_h_REF_5 C macros shall only expand to a braced initialiser, 
* a constant, a parenthesised expression
* @violates @ref Mcal_h_REF_6 In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses
*/
#define P2P2CONST(ptrtype, memclass, ptrclass) const ptrtype **

 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Typedef for DEM error management implemented by MCAL drivers
*/
typedef struct
{
    uint32 state;   /**< enabling/disabling the DEM error: Active=STD_ON/ Inactive=STD_OFF */
    uint32 id ;     /**< ID of DEM error (0 if STD_OFF)*/
}Mcal_DemErrorType; 
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MCAL_H */

/** @} */
