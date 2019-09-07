/**
*   @file    Fls_IPW.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Flash driver IP wrapper declarations.
*
*   @addtogroup [FLS]
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

#ifndef FLS_IPW_H
#define FLS_IPW_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_ipw_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_ipw_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping 
*
* @section fls_ipw_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers.
*
* @section fls_ipw_h_REF_4
* Violates MISRA 2004 Required Rule 19.10,In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##.
* Macro is used to call functions in underlying layers.
*
* @section fls_ipw_h_REF_5
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only
* one file. Those objects are declared in multi files to support multi IPVs
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/
/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @{
* @file           Fls_IPW.h
* @brief          Source file version information
* 
*/
#define FLS_IPW_VENDOR_ID_H                       43
#define FLS_IPW_AR_RELEASE_MAJOR_VERSION_H        4
#define FLS_IPW_AR_RELEASE_MINOR_VERSION_H        2
#define FLS_IPW_AR_RELEASE_REVISION_VERSION_H     2
#define FLS_IPW_SW_MAJOR_VERSION_H                1
#define FLS_IPW_SW_MINOR_VERSION_H                0
#define FLS_IPW_SW_PATCH_VERSION_H                1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_IPW_VENDOR_ID_H != FLS_VENDOR_ID)
    #error "Fls_IPW.c and Fls.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Fls header file are of the same Autosar version */
    #if ((FLS_IPW_AR_RELEASE_MAJOR_VERSION_H    != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_IPW_AR_RELEASE_MINOR_VERSION_H    != FLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_IPW.c and Fls.h are different"
    #endif
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_IPW_SW_MAJOR_VERSION_H != FLS_SW_MAJOR_VERSION) || \
     (FLS_IPW_SW_MINOR_VERSION_H != FLS_SW_MINOR_VERSION) || \
     (FLS_IPW_SW_PATCH_VERSION_H != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_IPW.c and Fls.h are different"
#endif
/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/
#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_ipw_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_ipw_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief Index of flash sector currently processed by a job
* @details Used by all types of job
*/
/*
* @violates @ref fls_ipw_h_REF_5 An external object or function shall be declared in one and only
* one file.
*/
extern VAR(volatile Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorIt;

/** 
* @brief Index of last flash sector by current job
* @details Used to check status of all external flash chips before start jobs
*/
/*
* @violates @ref fls_ipw_h_REF_5 An external object or function shall be declared in one and only
* one file.
*/
extern VAR( Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorEnd;

/** 
    @brief Result of last flash hardware job
*/
/*
* @violates @ref fls_ipw_h_REF_5 An external object or function shall be declared in one and only
* one file.
*/
extern VAR(volatile MemIf_JobResultType, FLS_VAR) Fls_eLLDJobResult;
/** 
    @brief Type of current flash hardware job - used for asynchronous operating mode.
*/
/*
* @violates @ref fls_ipw_h_REF_5 An external object or function shall be declared in one and only
* one file.
*/
extern VAR(Fls_LLDJobType, FLS_VAR) Fls_eLLDJob;
/** 
* @brief Pointer to current flash module configuration set
*/
/*
* @violates @ref fls_ipw_h_REF_5 An external object or function shall be declared in one and only
* one file.
*/
extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_pConfigPtr;

/*
* @violates @ref fls_ipw_h_REF_5 An external object or function shall be declared in one and only
* one file.
*/
extern VAR(volatile Fls_LLDIrqJobType, FLS_VAR) Fls_eLLDIrqJob;



#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_ipw_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_ipw_h_REF_2 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers.
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_GetHwUnitCfgIndex(eHwUnitName)                                              (Fls_Qspi_GetHwUnitCfgIndex(eHwUnitName))

/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers.
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiSetSfarAddr(eHwUnitName, u32Addr)                                       (Fls_Qspi_SetSfarAddrExt(eHwUnitName, u32Addr))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers.
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##   
*/
#define Fls_IPW_QspiSetLUT(eHwUnitName, u8LUTNumber, LUTValue)                              (Fls_Qspi_SetLUTExt(eHwUnitName, u8LUTNumber, LUTValue))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers.
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##   
*/
#define Fls_IPW_QspiLaunchLUTNumber(eHwUnitName, u8LUTNumber, u32DataSize, u8ParEn)         (Fls_Qspi_LaunchLUTNumberExt(eHwUnitName, u8LUTNumber, u32DataSize, u8ParEn))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiResetFlags(eHwUnitName)                                                 (Fls_Qspi_ResetFlagsExt(eHwUnitName))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiSetRXWmrk(eHwUnitName, u8BytesToRead)                                   (Fls_Qspi_SetRXWmrkExt(eHwUnitName, u8BytesToRead))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiCheckControllerIdle(eHwUnitName)                                        (Fls_Qspi_CheckControllerIdleExt(eHwUnitName))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiReadRXBuffer(eHwUnitName, p8DataPtr, u8BytesToRead)                     (Fls_Qspi_ReadRXBufferExt(eHwUnitName, p8DataPtr, u8BytesToRead))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiLoadTXBuffer(eHwUnitName, p8DataPtr, u8BytesToWrite)                    (Fls_Qspi_LoadTXBufferExt(eHwUnitName, p8DataPtr, u8BytesToWrite))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiGetHwUnitBaseAddr(eHwUnitName)                                          (Fls_Qspi_GetHwUnitBaseAddr(eHwUnitName))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiDisableModule(eHwUnitName)                                              (Fls_Qspi_DisableModuleExt(eHwUnitName))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiEnableModule(eHwUnitName)                                               (Fls_Qspi_EnableModuleExt(eHwUnitName))
/* 
* @violates @ref fls_ipw_h_REF_3 A function should be used in preference to a function-like macro.
* Macro is used for interaction of MCAL layers. 
* @violates @ref fls_ipw_h_REF_4 A In the definition of a function-like macro each instance of a
* parameter shall be enclosed in parentheses unless it is used as the operand of # or ##  
*/
#define Fls_IPW_QspiSetCalibDelayValues(eHwUnitName, u8CoarseDelay, u8FineDelay)            (Fls_Qspi_SetCalibDelayValuesExt(eHwUnitName, u8CoarseDelay, u8FineDelay))


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_ipw_h_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_ipw_h_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

FUNC(void, FLS_CODE) Fls_IPW_Init(void);
FUNC(void, FLS_CODE) Fls_IPW_AbortSuspended(void);
FUNC(void, FLS_CODE) Fls_IPW_Cancel(void);
FUNC( void, FLS_CODE ) Fls_IPW_LLDMainFunction( void );
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorRead
(
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_AddressType, AUTOMATIC) u32Length,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pJobDataDestPtr
);
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorCompare
(
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_AddressType, AUTOMATIC) u32Length,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pJobDataSrcPtr
);
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorErase
(
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
    CONST( Fls_LengthType, AUTOMATIC ) u32PhysicalSectorSize,
#endif
    CONST( boolean, AUTOMATIC ) bAsynch
);
FUNC( Fls_LLDReturnType, FLS_CODE ) Fls_IPW_SectorWrite
(
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_AddressType, AUTOMATIC) u32Length,
    P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pJobDataSrcPtr,
    CONST( boolean, AUTOMATIC ) bAsynch
);

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_ipw_h_REF_1 Precautions shall be taken in order to prevent the contents of a header being included twice. 
* @violates @ref fls_ipw_h_REF_2 Only preprocessor statements and comments before "#include"
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FLS_IPW_H */

/** @}*/
