/**
*   @file           CompilerDefinition.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - SWS Compiler abstraction
*   @details The file Compiler.h provides macros for the encapsulation of definitions and
*            declarations.
*            This file contains sample code only. It is not part of the production code deliverables
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
* @section CompilerDefinition_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like
* macro. This is the compiler abstraction specified in AutoSar Specification of Compiler Abstraction.
*
* @section CompilerDefinition_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and
* functions shall not be reused. Symbol required to be defined when one compiler is used.
* Requested by AutoSAR (Req. COMPILER010).
*
* @section CompilerDefinition_h_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a
* parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section CompilerDefinition_h_REF_4
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* This is used to abstract compiler specific encapsulation of definitions and declarations
*
* @section CompilerDefinition_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for identifiers.
* @section CompilerDefinition_h_REF_6
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance
* and case sensitivity are supported for external identifiers.
*/

#ifndef COMPILERDEFINITION_H
#define COMPILERDEFINITION_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the compiler abstraction header file and also in
          the module's description file.
@{
*/
#define COMPILERDEFINITION_VENDOR_ID                      43
/*
 * @violates @ref CompilerDefinition_h_REF_5 This is required as per autosar Requirement,
 */
#define COMPILERDEFINITION_AR_RELEASE_MAJOR_VERSION       4
/*
 * @violates @ref CompilerDefinition_h_REF_5 This is required as per autosar Requirement,
 */
/** @violates @ref CompilerDefinition_h_REF_6 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers */
#define COMPILERDEFINITION_AR_RELEASE_MINOR_VERSION       2
/*
 * @violates @ref CompilerDefinition_h_REF_5 This is required as per autosar Requirement,
 */
/** @violates @ref CompilerDefinition_h_REF_6 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers */
#define COMPILERDEFINITION_AR_RELEASE_REVISION_VERSION    2
#define COMPILERDEFINITION_SW_MAJOR_VERSION               1
#define COMPILERDEFINITION_SW_MINOR_VERSION               0
#define COMPILERDEFINITION_SW_PATCH_VERSION               1
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef __ghs__
    /**
    * @brief Symbol required to be defined when GreenHills compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _GREENHILLS_C_S32K14x_
#endif
#ifdef __DCC__
    /**
    * @brief Symbol required to be defined when Diab compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _DIABDATA_C_S32K14x_
#endif
#ifdef __MWERKS__
    /**
    * @brief Symbol required to be defined when Codewarrior compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
    #define _CODEWARRIOR_C_S32K14x_
#endif
#ifdef __CSMC__
    /**
    * @brief Symbol required to be defined when Cosmic compiler is used.
    */
  /*
    * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
    * macros, objects and functions shall not be reused.
    */
  #define _COSMIC_C_S32K14x_
#endif
#ifdef __GNUC__
           /**
        * @brief Symbol required to be defined when Linaro ARM compiler is used.
        */
        /*
        * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _LINARO_C_S32K14x_
 #endif      
#ifdef __CC_ARM 
        /**
        * @brief Symbol required to be defined when DS5 ARM compiler is used.
        */
        /*
        * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _ARM_DS5_C_S32K14x_     
#endif
#ifdef __ICCARM__ 
        /**
        * @brief Symbol required to be defined when IAR compiler is used.
        */
        /*
        * @violates @ref CompilerDefinition_h_REF_2 The names of standard library
        * macros, objects and functions shall not be reused.
        */
        #define _IAR_C_S32K14x_     
#endif

#ifdef __cplusplus
}
#endif

#endif /* #ifndef COMPILERDEFINITION_H */

/** @} */
