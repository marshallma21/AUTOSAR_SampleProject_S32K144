/**
*   @file           I2c_MemMap.h
*   @implements     MemMap.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - Memory mapping specification.
*   @details This document specifies mechanisms for the mapping of code and data to specific
*            memory sections via memory mapping file. For many ECUs and microcontroller platforms
*            it is of utmost necessity to be able to map code, variables and constants module
*            wise to specific memory sections.
*            This file contains sample code only. It is not part of the production code deliverables
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
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
* @section I2c_MemMap_h_REF_1
* Violates MISRA 2004 Required Rule 19.6, #undef shall not be used.
* This is due to #undef MEMMAP_ERROR and #undef <section_type> and cannot be removed as it is
* required by Autosar Specification - Specification of Memory Mapping.
* @section I2c_MemMap_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
* @section I2c_MemMap_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by
* other preprocessor directives or comments.
* This comes from the order of includes in the .c. MemMap is required by AutoSAR to be included in
* the middle of the source file(s).
* @section [global] 
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely  on the significance of more than 31 characters. All compilers used support more than 31 chars for identifiers.
* @section [global] 
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance and case  sensitivity are supported for external identifiers. This violation is due to the naming convention for the memory ssections.
* @section [global] 
* Violates MISRA 2004 Required Rule 3.4, All uses of the pragma directive shall be documented and explained. The pragma directives are used MemMap.h file to define memory sections.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref I2c_MemMap_h_REF_2 Precautions shall be taken in order
* to prevent the contents of a header being included twice.
*/
/* @violates @ref I2c_MemMap_h_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the memory map header file and also in the
*       module's description file
*/
#define I2C_MEMMAP_VENDOR_ID                    43
#define I2C_MEMMAP_AR_RELEASE_MAJOR_VERSION     4
#define I2C_MEMMAP_AR_RELEASE_MINOR_VERSION     2
#define I2C_MEMMAP_AR_RELEASE_REVISION_VERSION  2
#define I2C_MEMMAP_SW_MAJOR_VERSION             1
#define I2C_MEMMAP_SW_MINOR_VERSION             0
#define I2C_MEMMAP_SW_PATCH_VERSION             1
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR

#ifndef AUTOSAR_OS_NOT_USED
        #include "Os_memmap.h"
#endif
/**************************************************************************************************/
/********************************************* GREENHILLS *****************************************/
/**************************************************************************************************/
#ifdef _GREENHILLS_C_S32K14x_
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".mcal_text"
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".aci2c_code_rom"
    #pragma ghs inlineprologue
#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif
/**************************************************************************************************/
/********************************************* DIAB ***********************************************/
/**************************************************************************************************/
#elif defined(_DIABDATA_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CONST
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section CODE ".ramcode" far-absolute
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma section CODE
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* use code relative addressing mode to ensure Position-independent Code (PIC) */
    #pragma section CODE ".aci2c_code_rom" far-code 

#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #pragma section CODE
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA 
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA 
#endif


#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA 
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA 
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data" ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA 
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA 
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif


#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section DATA
#endif
/**************************************************************************************************/
/********************************************* CODEWARRIOR ****************************************/
/**************************************************************************************************/
#elif defined(_CODEWARRIOR_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG mcal_text
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG aci2c_code_rom
#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif
/**************************************************************************************************/
/********************************************* COSMIC *********************************************/
/**************************************************************************************************/
#elif defined(_COSMIC_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcalconstcfg}
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {mcal_const}
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section const {}
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (mcal_text)
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (ramcode)
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section (aci2ccode)
#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ()
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section [mcal_bss]
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section []
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {mcal_data}
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section {}
#endif
/**************************************************************************************************/
/********************************************* HighTec *********************************************/
/**************************************************************************************************/
#elif defined(_HITECH_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_text" avx
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode" avx
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".aci2c_code_rom" avx
#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss_no_cacheable" awsB
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif
/**************************************************************************************************/
/********************************************* Linaro *********************************************/
/**************************************************************************************************/
#elif defined(_LINARO_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
/**************************************************************************************************/
/********************************************* DS5 ************************************************/
/**************************************************************************************************/
#elif defined(_ARM_DS5_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".mcal_text"
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode"
#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section code=".aci2c_code_rom"
#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
     #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif




/**************************************************************************************************/
/********************************************* IAR ************************************************/
/**************************************************************************************************/
#elif defined(_IAR_C_S32K14x_)
/**************************************** I2C *******************************/
#ifdef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".mcal_text"
#endif

#ifdef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode"

#endif

#ifdef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_RAMCODE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
    
#endif

#ifdef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".aci2c_code_rom"

#endif

#ifdef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_CODE_AC
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = 
    
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif


#ifdef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef I2C_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file I2c_MemMap.h
    * @violates @ref I2c_MemMap_h_REF_1 MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif
#endif 
/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "MemMap.h, no valid memory mapping symbol defined."
#endif
                                                                                                     
/*================================================================================================== 
*                                            ENUMS                                                   
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                 STRUCTURES AND OTHER TYPEDEFS                                      
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                 GLOBAL VARIABLE DECLARATIONS                                       
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                     FUNCTION PROTOTYPES                                            
==================================================================================================*/ 
                                                                                                     
#ifdef __cplusplus                                                                                   
}                                                                                                    
#endif                                                                                               
