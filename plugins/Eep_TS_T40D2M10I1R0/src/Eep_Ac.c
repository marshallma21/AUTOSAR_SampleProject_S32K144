/**
*   @file    Eep_Ac.c
*   @implements Eep_Ac.c_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Position independent erase and write access code.
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
* @section eep_ac_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section eep_ac_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section eep_ac_c_REF_5
* Violates MISRA 2004 Advisory Rule 12.6, boolean expression required for operator: '!'
* This violation because of it is not effectively boolean.
*
* @section eep_ac_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* External linkage required for a global function.
*
* @section eep_ac_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section eep_ac_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section eep_ac_c_REF_9
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Eep_Cfg.c or Eep_PBcfg.c). There is no need to put the declaration into Eep_Cfg.h and made it 
* accessible for all modules which includes Eep.h/Eep_Cfg.h.
*
* @section eep_ac_c_REF_10
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function
* The array is used by two modules.
*
* @section eep_ac_c_REF_11
* Violates MISRA 2004 Required Rule 11.5, A cast should not be performed that removes the const or volatile
* of the qualification. The cast is done to reduce the number of variables used and the complexity of the code.
*
* @section eep_ac_c_REF_12
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer
* to object type and a different pointer to object type. The cast is needed because
* a u32 pointer must be advanced by 1 byte.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
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


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep.h"
#include "Reg_eSys_Ftfc.h"
#include "StdRegMacros.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_AC_VENDOR_ID_C                      43
#define EEP_AC_AR_RELEASE_MAJOR_VERSION_C       4
#define EEP_AC_AR_RELEASE_MINOR_VERSION_C       2
#define EEP_AC_AR_RELEASE_REVISION_VERSION_C    2
#define EEP_AC_SW_MAJOR_VERSION_C               1
#define EEP_AC_SW_MINOR_VERSION_C               0
#define EEP_AC_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_AC_VENDOR_ID_C != EEP_VENDOR_ID)
    #error "Eep_Ac.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep_Ac header file are of the same Autosar version */
#if ((EEP_AC_AR_RELEASE_MAJOR_VERSION_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AC_AR_RELEASE_MINOR_VERSION_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AC_AR_RELEASE_REVISION_VERSION_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Ac.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_AC_SW_MAJOR_VERSION_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_AC_SW_MINOR_VERSION_C != EEP_SW_MINOR_VERSION) || \
     (EEP_AC_SW_PATCH_VERSION_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Ac.c and Eep.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC header file are of the same vendor */
#if (EEP_AC_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Eep_Ac.c and Reg_eSys_Ftfc.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Autosar version */
#if ((EEP_AC_AR_RELEASE_MAJOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AC_AR_RELEASE_MINOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AC_AR_RELEASE_REVISION_VERSION_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Ac.c and Reg_eSys_Ftfc.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Software version */
#if ((EEP_AC_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (EEP_AC_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (EEP_AC_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Ac.c and Reg_eSys_Ftfc.h are different"
#endif

/* Check if current file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EEP_AC_AR_RELEASE_MAJOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AC_AR_RELEASE_MINOR_VERSION_C    != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Eep_Ac.c and StdRegMacros.h are different"
    #endif
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define EEP_START_SEC_CONST_8
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"
/* 
* @violates @ref eep_ac_c_REF_10 objects shall be defined at block scope */
extern CONST(uint8, EEP_CONST) Eep_Eeprom_u8ErasedValue[EEP_PAGE_SIZE_4BYTES];
#define EEP_STOP_SEC_CONST_8
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"
/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define EEP_START_SEC_VAR_INIT_32
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"

#if (EEP_TIMEOUT_HANDLING == STD_ON)
extern VAR(uint32, EEP_VAR) Eep_Eeprom_u32TimeoutCounter;
#endif
extern VAR(uint32, EEP_VAR) Eep_Eeprom_u32DestAddress;
extern VAR(uint32, EEP_VAR) Eep_Eeprom_u32SrcAddress;

#define EEP_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"
#define EEP_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"
extern VAR(Eep_Eeprom_JobType, EEP_VAR) Eep_Eeprom_eJob;
#define EEP_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief    Start of Eep section CODE_AC 
*
* @violates @ref eep_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define EEP_START_SEC_CODE_AC
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"

#ifdef _LINARO_C_S32K14x_ 
    /* @violates @ref eep_ac_c_REF_9 Rule 8.8, Object/function previously declared.*/
    void Eep_Eeprom_AccessCode(   P2FUNC(void, EEP_CODE, CallBack)( void ),VAR(uint8, AUTOMATIC) u8PageSize ) __attribute__ ((section (".aceep_code_rom")));
#else
    /* @violates @ref eep_ac_c_REF_9 Rule 8.8, Object/function previously declared.*/
    void Eep_Eeprom_AccessCode(   P2FUNC(void, EEP_CODE, CallBack)( void ),VAR(uint8, AUTOMATIC) u8PageSize );
#endif /* #ifdef _LINARO_C_S32K14x_ */
/*==================================================================================================
                                      GLOBAL FUNCTIONS
==================================================================================================*/
/* Position independent erase access code */
/* @violates @ref eep_ac_c_REF_6 All declarations and definitions of objects or functions at file scope shall have internal linkage */
void Eep_Eeprom_AccessCode(P2FUNC(void, EEP_CODE, CallBack)( void ), VAR(uint8, AUTOMATIC) u8PageSize )
{
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST )  pu8TempSrc = NULL_PTR;
    P2VAR( uint8, AUTOMATIC, EEP_APPL_DATA )  pu8TempDest = NULL_PTR;
    P2CONST(uint32, AUTOMATIC, EEP_APPL_CONST )  pu32TempSrc = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, EEP_APPL_DATA )  pu32TempDest = NULL_PTR;
 
    /* prepare access pointers */
    switch(u8PageSize)
    {
        case EEP_PAGE_SIZE_1BYTE:
            if(EEP_JOB_WRITE == Eep_Eeprom_eJob)
            {
                /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
                /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
                pu8TempSrc = (uint8 *) Eep_Eeprom_u32SrcAddress;
            }
            else
            {
            /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
            /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
                pu8TempSrc = Eep_Eeprom_u8ErasedValue;
            }
            /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
            /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
            pu8TempDest = (uint8 *)Eep_Eeprom_u32DestAddress;  
            *pu8TempDest = *pu8TempSrc; 
            break;
        case EEP_PAGE_SIZE_4BYTES:
            if(EEP_JOB_WRITE == Eep_Eeprom_eJob)
            {
                /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
                /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
                pu32TempSrc = (uint32 *) Eep_Eeprom_u32SrcAddress;
            }
            else
            {
                /* @violates @ref eep_ac_c_REF_12 a cast shall not be  performed between different ptr types */
                /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
                /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
                /* @violates @ref eep_ac_c_REF_11 A cast should not be performed if removes qualifier */   
                pu32TempSrc = (uint32 *)Eep_Eeprom_u8ErasedValue;  
            }   
            /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
            /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
            pu32TempDest = (uint32 *) Eep_Eeprom_u32DestAddress;  
            *pu32TempDest = *pu32TempSrc;              
            break;
        case EEP_PAGE_SIZE_0BYTES: 
            /* when the function is called for Set FlexRam cmd, there is no memory copy needed */
            /* set CCIF to start the command */
            /* @violates @ref eep_ac_c_REF_8 Conversions shall not be  performed between a pointer */
            /* @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type */
            REG_WRITE8(EEPROM_FSTAT_ADDR32 , EEPROM_FSTAT_CCIF_W1C);    
            break;
        default:
            break;
    } 
    
    /* wait until operation finishes or write/erase timeout is reached */
    #if (EEP_TIMEOUT_HANDLING == STD_ON)
    /* @violates @ref eep_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
     * @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type */
    while((0U == REG_BIT_GET8(EEPROM_FSTAT_ADDR32, EEPROM_FSTAT_CCIF_U8)) && (0U < Eep_Eeprom_u32TimeoutCounter) )
    #else
    /* @violates @ref eep_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
     * @violates @ref eep_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type */
    while(0U == REG_BIT_GET8(EEPROM_FSTAT_ADDR32, EEPROM_FSTAT_CCIF_U8))
    #endif 
    {  
        #if (EEP_TIMEOUT_HANDLING == STD_ON)
        Eep_Eeprom_u32TimeoutCounter = Eep_Eeprom_u32TimeoutCounter - 1U;
        #endif 
       
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }    
    }
}

/**
* @brief    Stop of Eep section CODE_AC 
*
* @violates @ref eep_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define EEP_STOP_SEC_CODE_AC
/* 
* @violates @ref eep_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref eep_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif
