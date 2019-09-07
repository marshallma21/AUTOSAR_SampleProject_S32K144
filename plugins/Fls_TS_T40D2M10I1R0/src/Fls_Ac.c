/**
*   @file    Fls_Ac.c
*   @implements Fls_Ac.c_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Position independent erase and write access code.
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
* @section fls_ac_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section fls_ac_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section fls_ac_c_REF_5
* Violates MISRA 2004 Advisory Rule 12.6, boolean expression required for operator: '!'
* This violation because of it is not effectively boolean.
*
* @section fls_ac_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* External linkage required for a global function.
*
* @section fls_ac_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section fls_ac_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section fls_ac_c_REF_9
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only
* one file. To provide the optional "Fls Load Access Code On Job Start" 
* it is declared in congifurations files also 
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
* 
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Reg_eSys_FLASHC.h"
#include "StdRegMacros.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_AC_VENDOR_ID_C                      43
#define FLS_AC_AR_RELEASE_MAJOR_VERSION_C       4
#define FLS_AC_AR_RELEASE_MINOR_VERSION_C       2
#define FLS_AC_AR_RELEASE_REVISION_VERSION_C    2
#define FLS_AC_SW_MAJOR_VERSION_C               1
#define FLS_AC_SW_MINOR_VERSION_C               0
#define FLS_AC_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_AC_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Ac.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls_Ac header file are of the same Autosar version */
#if ((FLS_AC_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AC_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AC_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Ac.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_AC_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_AC_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_AC_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Ac.c and Fls.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC header file are of the same vendor */
#if (FLS_AC_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Ac.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Autosar version */
#if ((FLS_AC_AR_RELEASE_MAJOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AC_AR_RELEASE_MINOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AC_AR_RELEASE_REVISION_VERSION_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Ac.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Software version */
#if ((FLS_AC_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_AC_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_AC_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Ac.c and Reg_eSys_FLASHC.h are different"
#endif

/* Check if current file and StdRegMacros header file are of the same Autosar version */
#if ((FLS_AC_AR_RELEASE_MAJOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AC_AR_RELEASE_MINOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MINOR_VERSION)  \
    )
    #error "AutoSar Version Numbers of Fls_Ac.c and StdRegMacros.h are different"
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief    Start of Fls section CODE_AC 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define FLS_START_SEC_CODE_AC
/* 
* @violates @ref fls_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

#ifdef _LINARO_C_S32K14x_ 
    #if (FLS_TIMEOUT_HANDLING == STD_ON)
    /*
    * @violates @ref fls_ac_c_REF_9 An external object or function shall be declared in one and only one file
    */
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC ) __attribute__ ((section (".acfls_code_rom")));
    #else
    /*
    * @violates @ref fls_ac_c_REF_9 An external object or function shall be declared in one and only one file
    */
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
    #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#else
    #if (FLS_TIMEOUT_HANDLING == STD_ON)
    /*
    * @violates @ref fls_ac_c_REF_9 An external object or function shall be declared in one and only one file
    */
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC );
    #else
    /*
    * @violates @ref fls_ac_c_REF_9 An external object or function shall be declared in one and only one file
    */
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
    #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#endif /* #ifdef _LINARO_C_S32K14x_ */
/*==================================================================================================
                                      GLOBAL FUNCTIONS
==================================================================================================*/
/* Position independent erase access code */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
/*
* @violates @ref fls_ac_c_REF_6 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC )
{
    /* start internal erase/program sequence */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    REG_WRITE8(u32RegBaseAddr + FLASH_FSTAT_OFFSET , FLASH_FSTAT_CCIF_W1C);
    
    /* wait until operation finishes or write/erase timeout is reached */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    while((0U == REG_BIT_GET8(u32RegBaseAddr + FLASH_FSTAT_OFFSET, FLASH_FSTAT_CCIF_U8)) && (0U < *pTimerCounterAC) )
    {
        (*pTimerCounterAC)--;
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }    
    }
}
#else
/*
* @violates @ref fls_ac_c_REF_6 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) )
{
    /* start internal erase/program sequence */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    REG_WRITE8(u32RegBaseAddr + FLASH_FSTAT_OFFSET , FLASH_FSTAT_CCIF_W1C);

    /* wait until operation finishes or write/erase timeout is reached */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    while(0U == REG_BIT_GET8(u32RegBaseAddr + FLASH_FSTAT_OFFSET, FLASH_FSTAT_CCIF_U8))
    {
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }
}
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

/**
* @brief    Stop of Fls section CODE_AC 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define FLS_STOP_SEC_CODE_AC
/* 
* @violates @ref fls_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
