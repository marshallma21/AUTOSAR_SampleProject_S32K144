/**
*   @file    Reg_eSys_DmaMux.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - DmaMux registers and macros definitions.
*   @details DmaMux registers and macros definitions.
*
*   @addtogroup MCL
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

#ifndef REG_ESYS_DMAMUX_H
#define REG_ESYS_DMAMUX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_DMAMUX_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_DMAMUX_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section REG_ESYS_DMAMUX_H_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are 
* only accessed from within a single function.
* 
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "StdRegMacros.h"
#include "CDD_Mcl_Cfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_DmaMux.h
* @requirements   
*/
#define DMAMUX_REG_VENDOR_ID                      43
#define DMAMUX_REG_AR_RELEASE_MAJOR_VERSION       4
#define DMAMUX_REG_AR_RELEASE_MINOR_VERSION       2
#define DMAMUX_REG_AR_RELEASE_REVISION_VERSION    2
#define DMAMUX_REG_SW_MAJOR_VERSION               1
#define DMAMUX_REG_SW_MINOR_VERSION               0
#define DMAMUX_REG_SW_PATCH_VERSION               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != DMAMUX_REG_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != DMAMUX_REG_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys.h and Reg_eSys_DmaMux.h are different"
    #endif
#endif

/* Check if header file and StdRegMacros.h header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((DMAMUX_REG_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (DMAMUX_REG_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Reg_eSys_DmaMux.h and StdRegMacros.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

#define MCL_START_SEC_CONST_32
/**
* @violates @ref REG_ESYS_DMAMUX_H_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

/**
* @violates @ref REG_ESYS_DMAMUX_H_REF_3 Objects shall defined at block if they  only accessed from
*  within a single function.
*/
extern CONST(uint32, MCL_CONST) DMAMUX_BASE_ADDR32[MCL_DMAMUX_NB_MODULES] ;

#define MCL_STOP_SEC_CONST_32
/**
* @violates @ref REG_ESYS_DMAMUX_H_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (STD_ON == MCL_DMAMUX_CHCFG_LITTLE_ENDIAN) 
/**
* @brief Used to decide dmamux config address based on endianess
*/
#define DMAMUX_BYTES_IN_WORD                   (0x4U)

/** @violates @ref REG_ESYS_DMAMUX_H_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */ 
#define DMAMUX_LITTLE_ENDIAN_FORMULA(byte) ((((DMAMUX_BYTES_IN_WORD * \
    ((byte) / DMAMUX_BYTES_IN_WORD))) + DMAMUX_BYTES_IN_WORD) -(((byte) % DMAMUX_BYTES_IN_WORD) + 1U))
#endif

#if (STD_ON == MCL_DMAMUX_CHCFG_LITTLE_ENDIAN)
/**
* @brief macros used to calculate the address of a CHCONFIG register.
* @violates @ref REG_ESYS_DMAMUX_H_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define DMACHMUX_CHCONFIG(u8channel, u8instance)  \
    (DMAMUX_BASE_ADDR32[(u8instance)] + (uint32)DMAMUX_LITTLE_ENDIAN_FORMULA((u8channel)))
#else
/**
* @brief macros used to calculate the address of a CHCONFIG register.
* @violates @ref REG_ESYS_DMAMUX_H_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define DMACHMUX_CHCONFIG(u8channel, u8instance)  \
    (DMAMUX_BASE_ADDR32[(u8instance)] + (u8channel))
#endif
/** 
* @brief masks used to set/clear the CHCONFIG.trig and CHCONFIG.enbl bits.
*/
#define DMACHMUX_CHCONFIG_ENBL_U8   (0x80U)
#define DMACHMUX_CHCONFIG_TRIG_U8   (0x40U)
#define DMACHMUX_CHCONFIG_SOURCE_U8 (0x3FU)
/** 
* @brief reset value of the DMAMUX registers
*/
#define DMAMUX_CHCFG_DEFAULT_VAL_U8 (0U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#endif /* (MCL_ENABLE_DMA == STD_ON) */
#endif /* #ifdef MCL_ENABLE_DMA */

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_DMAMUX_H */

/** @} */
