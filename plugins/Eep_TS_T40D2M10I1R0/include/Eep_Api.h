/**
*   @file    Eep_Api.h
*   @implements Eep_Api.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details All external API declarations of Eeprom driver.
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

#ifndef EEP_API_H
#define EEP_API_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section eep_api_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
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
/* 
* @violates @ref eep_api_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_Cfg.h"
/* 
* @violates @ref eep_api_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "MemIf_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief          Version Check parameters.
*/
#define EEP_API_VENDOR_ID                    43
#define EEP_API_AR_RELEASE_MAJOR_VERSION     4
#define EEP_API_AR_RELEASE_MINOR_VERSION     2
#define EEP_API_AR_RELEASE_REVISION_VERSION  2
#define EEP_API_SW_MAJOR_VERSION             1
#define EEP_API_SW_MINOR_VERSION             0
#define EEP_API_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep_Cfg.h file are of the same vendor */
#if (EEP_API_VENDOR_ID != EEP_VENDOR_ID_CFG)
#error "Eep_Api.h and Eep_Cfg.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Eep_Cfg.h file are of the same Autosar version */
#if ((EEP_API_AR_RELEASE_MAJOR_VERSION    != EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EEP_API_AR_RELEASE_MINOR_VERSION    != EEP_AR_RELEASE_MINOR_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Eep_Api.h and Eep_Cfg.h are different"
#endif
#endif
/* Check if current file and Eep_Cfg.h file are of the same software version */
#if ((EEP_API_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION_CFG) || \
     (EEP_API_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION_CFG) || \
     (EEP_API_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION_CFG)  \
    )
#error "Software Version Numbers of Eep_Api.h and Eep_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and MemIf_Types.h file are of the same Autosar version */
#if ((EEP_API_AR_RELEASE_MAJOR_VERSION    != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_API_AR_RELEASE_MINOR_VERSION    != MEMIF_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Eep_Api.h and MemIf_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* AUTOSAR module vendor identification */
#define EEP_VENDOR_ID            43

/* AUTOSAR module identification */
#define EEP_MODULE_ID            90

/* AUTOSAR module instance identification */
#define EEP_INSTANCE_ID          0U

/**
* @brief          Development error codes (passed to DET).
* 
*/
#define EEP_E_INIT_FAILED            0x10U
#define EEP_E_PARAM_ADDRESS          0x11U
#define EEP_E_PARAM_DATA             0x12U
#define EEP_E_PARAM_LENGTH           0x13U
#define EEP_E_UNINIT                 0x20U 
#define EEP_E_BUSY                   0x21U 
#define EEP_E_TIMEOUT                0x22U 
#define EEP_E_PARAM_POINTER          0x23U 
#define EEP_E_CANCEL_REJECTED        0x24U 


/**
* @brief          All service IDs (passed to DET).
* 
*/
#define EEP_INIT_ID                  0x00U
#define EEP_SETMODE_ID               0x01U
#define EEP_READ_ID                  0x02U
#define EEP_WRITE_ID                 0x03U
#define EEP_ERASE_ID                 0x04U
#define EEP_COMPARE_ID               0x05U
#define EEP_CANCEL_ID                0x06U
#define EEP_GETSTATUS_ID             0x07U
#define EEP_GETJOBRESULT_ID          0x08U
#define EEP_MAINFUNCTION_ID          0x09U
#define EEP_GETVERSIONINFO_ID        0x0AU
#define EEP_QUICK_WRITE_ID           0x0BU

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief    Start of Eep section CODE 
*/
#define EEP_START_SEC_CODE
/* 
* @violates @ref eep_api_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"

extern FUNC( void, EEP_CODE ) Eep_Init
( P2CONST( Eep_ConfigType, AUTOMATIC, EEP_APPL_CONST ) pConfigPtr );

extern FUNC( Std_ReturnType, EEP_CODE ) Eep_Write
(   VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pSourceAddressPtr,
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
);

extern FUNC( Std_ReturnType, EEP_CODE ) Eep_Erase
( 
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
);

#if( EEP_CANCEL_API == STD_ON )
extern FUNC( void, EEP_CODE ) Eep_Cancel( void );
#endif    
#if( EEP_GET_STATUS_API == STD_ON )
extern FUNC( MemIf_StatusType, EEP_CODE ) Eep_GetStatus( void );
#endif    
#if( EEP_GET_JOB_RESULT_API == STD_ON )
extern FUNC( MemIf_JobResultType, EEP_CODE ) Eep_GetJobResult( void );
#endif   
extern FUNC( Std_ReturnType, EEP_CODE ) Eep_Read
( 
    VAR( Eep_AddressType, AUTOMATIC) u32SourceAddress, 
    P2VAR( uint8, AUTOMATIC, EEP_APPL_DATA ) pTargetAddressPtr,    
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
);
#if( EEP_COMPARE_API == STD_ON )
extern FUNC( Std_ReturnType, EEP_CODE ) Eep_Compare
(
    VAR( Eep_AddressType, AUTOMATIC) u32SourceAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pTargetAddressPtr, 
    VAR( Eep_LengthType, AUTOMATIC) u32Length 
);
#endif
#if( EEP_SET_MODE_API == STD_ON )
extern FUNC( void, EEP_CODE ) Eep_SetMode 
( VAR( MemIf_ModeType, AUTOMATIC ) eMode );
#endif 
#if( EEP_VERSION_INFO_API == STD_ON )
extern FUNC( void, EEP_CODE ) Eep_GetVersionInfo
( P2VAR( Std_VersionInfoType, AUTOMATIC, EEP_APPL_DATA ) pVersionInfoPtr );
#endif 
extern FUNC( void, EEP_CODE ) Eep_MainFunction( void );

#if(EEP_ENABLE_QUICK_WRITES_API == STD_ON)
FUNC( Std_ReturnType, EEP_CODE ) Eep_QuickWrite
(
    VAR( Eep_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, EEP_APPL_CONST ) pSourceAddressPtr,
    VAR( Eep_LengthType, AUTOMATIC) u32Length,
    VAR( uint16, AUTOMATIC ) u16QuickWritesLength 
);
#endif
/**
* @brief    Stop of Eep section CODE 
*/
#define EEP_STOP_SEC_CODE
/* 
* @violates @ref eep_api_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Eep_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* EEP_API_H */

/** @}*/
