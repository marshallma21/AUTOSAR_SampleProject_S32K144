/**
*   @file    Fls_Api.h
*   @implements Fls_Api.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details All external API declarations of Flash driver.
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

#ifndef FLS_API_H
#define FLS_API_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_api_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_api_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7,A function should be used in preference to a function-like macro.
* Use function like macro to improve performance and avoid a complex statement
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls_Cfg.h"
#include "MemIf_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief          Version Check parameters.
*/
#define FLS_API_VENDOR_ID                    43
#define FLS_API_AR_RELEASE_MAJOR_VERSION     4
#define FLS_API_AR_RELEASE_MINOR_VERSION     2
#define FLS_API_AR_RELEASE_REVISION_VERSION  2
#define FLS_API_SW_MAJOR_VERSION             1
#define FLS_API_SW_MINOR_VERSION             0
#define FLS_API_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls_Cfg.h file are of the same vendor */
#if (FLS_API_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls_Api.h and Fls_Cfg.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Fls_Cfg.h file are of the same Autosar version */
#if ((FLS_API_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_API_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls_Api.h and Fls_Cfg.h are different"
#endif
#endif
/* Check if current file and Fls_Cfg.h file are of the same software version */
#if ((FLS_API_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_API_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_API_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG)  \
    )
#error "Software Version Numbers of Fls_Api.h and Fls_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and MemIf_Types.h file are of the same Autosar version */
#if ((FLS_API_AR_RELEASE_MAJOR_VERSION    != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_API_AR_RELEASE_MINOR_VERSION    != MEMIF_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Fls_Api.h and MemIf_Types.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* AUTOSAR module vendor identification */
#define FLS_VENDOR_ID            43

/* AUTOSAR module identification */
#define FLS_MODULE_ID            92

/* AUTOSAR module instance identification */
#define FLS_INSTANCE_ID          0U

/**
* @brief          Development error codes (passed to DET).
* @implements     DETERRORCODE_enumeration
*/
#define FLS_E_PARAM_CONFIG           0x01U /* API service called with wrong parameter */
#define FLS_E_PARAM_ADDRESS          0x02U
#define FLS_E_PARAM_LENGTH           0x03U
#define FLS_E_PARAM_DATA             0x04U
#define FLS_E_UNINIT                 0x05U /* API service called without module initialization */
#define FLS_E_BUSY                   0x06U /* API service called while driver still busy */
#define FLS_E_VERIFY_ERASE_FAILED    0x07U /* Erase verification (blank check) failed */
#define FLS_E_VERIFY_WRITE_FAILED    0x08U /* Write verification (compare) failed */
#define FLS_E_TIMEOUT                0x09U /* Timeout exceeded */
#define FLS_E_PARAM_POINTER          0x0AU /* NULL_PTR passed */
#define FLS_E_PARTITION_ERR          0x0BU /* Partition error on FlexNVM */
#define FLS_E_SECTOR_PROTECTED       0x0CU /* Configured sector is protected */

/**
* @brief          Runtime error codes (passed to DET).
* 
*/
#define FLS_E_ERASE_FAILED           0x01U /* Flash erase failed (HW) */
#define FLS_E_WRITE_FAILED           0x02U /* Flash write failed (HW) */
#define FLS_E_READ_FAILED            0x03U /* Flash read failed (HW) */
#define FLS_E_COMPARE_FAILED         0x04U /* Flash compare failed (HW) */
#define FLS_E_UNEXPECTED_FLASH_ID    0x05U /* Expected hardware ID not matched */

/**
* @brief          All service IDs (passed to DET).
* @implements     SERVICEIDs_enumeration
*/
#define FLS_INIT_ID                  0x00U
#define FLS_ERASE_ID                 0x01U
#define FLS_WRITE_ID                 0x02U
#define FLS_CANCEL_ID                0x03U
#define FLS_GETSTATUS_ID             0x04U
#define FLS_GETJOBRESULT_ID          0x05U
#define FLS_MAINFUNCTION_ID          0x06U
#define FLS_READ_ID                  0x07U
#define FLS_COMPARE_ID               0x08U
#define FLS_SETMODE_ID               0x09U
#define FLS_GETVERSIONINFO_ID        0x10U
#define FLS_BLANK_CHECK_ID           0x11U

/**
* @brief          All sector flags.
*/
#define FLS_SECTOR_ERASE_ASYNCH      0x01U
#define FLS_PAGE_WRITE_ASYNCH        0x02U
#define FLS_SECTOR_IRQ_MODE          0x04U

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* 
* @violates @ref fls_api_h_REF_2 A function should be used in preference to a function-like macro
*/
#define FLS_QSPI_LUT_FORMAT(CMD_1, PADS_1, OPER_1, CMD_0, PADS_0, OPER_0)   ( (((uint32)(CMD_1)&0x3FU)<<26U) | (((uint32)(PADS_1)&3U)<<24U) | (((uint32)(OPER_1)&0xFFU)<<16U) | \
                                                                              (((uint32)(CMD_0)&0x3FU)<<10U) | (((uint32)(PADS_0)&3U)<<8U)  | (((uint32)(OPER_0)&0xFFU)<<0U ) )

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief    Start of Fls section CODE 
*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_api_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

extern FUNC( void, FLS_CODE ) Fls_Init
( P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) pConfigPtr );

extern FUNC( Std_ReturnType, FLS_CODE ) Fls_Write
(   VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) pSourceAddressPtr,
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
);

extern FUNC( Std_ReturnType, FLS_CODE ) Fls_Erase
( 
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
);

#if( FLS_CANCEL_API == STD_ON )
extern FUNC( void, FLS_CODE ) Fls_Cancel( void );
#endif    /* FLS_CANCEL_API == STD_ON */

#if( FLS_GET_STATUS_API == STD_ON )
extern FUNC( MemIf_StatusType, FLS_CODE ) Fls_GetStatus( void );
#endif    /* FLS_GET_STATUS_API == STD_ON */

#if( FLS_GET_JOB_RESULT_API == STD_ON )
extern FUNC( MemIf_JobResultType, FLS_CODE ) Fls_GetJobResult( void );
#endif    /* FLS_GET_JOB_RESULT_API == STD_ON */

extern FUNC( Std_ReturnType, FLS_CODE ) Fls_Read
( 
    VAR( Fls_AddressType, AUTOMATIC) u32SourceAddress, 
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pTargetAddressPtr,    
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
);

#if( FLS_COMPARE_API == STD_ON )
extern FUNC( Std_ReturnType, FLS_CODE ) Fls_Compare
(
    VAR( Fls_AddressType, AUTOMATIC) u32SourceAddress, 
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) pTargetAddressPtr, 
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
);
#endif /* FLS_COMPARE_API == STD_ON */

#if (FLS_BLANK_CHECK_API == STD_ON)
FUNC( Std_ReturnType, FLS_CODE ) Fls_BlankCheck
(
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) u32Length
);
#endif /* FLS_BLANK_CHECK_API == STD_ON */

#if( FLS_SET_MODE_API == STD_ON )
extern FUNC( void, FLS_CODE ) Fls_SetMode 
( VAR( MemIf_ModeType, AUTOMATIC ) eMode );
#endif /* FLS_SET_MODE_API == STD_ON */

#if( FLS_VERSION_INFO_API == STD_ON )
extern FUNC( void, FLS_CODE ) Fls_GetVersionInfo
( P2VAR( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) pVersionInfoPtr );
#endif /* FLS_VERSION_INFO_API == STD_ON */

extern FUNC( void, FLS_CODE ) Fls_MainFunction( void );

#if (STD_ON == FLS_INTERNAL_FLASH_AVAILABLE)
#if( FLS_DSI_HANDLER_API == STD_ON )
extern FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_DsiHandler
( P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) pExceptionDetailsPtr );
#ifdef IPV_FLASH
extern FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_MciHandler
( P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) pExceptionDetailsPtr );
#endif  /* IPV_FLASH */
#endif /* FLS_DSI_HANDLER_API == STD_ON */
#endif /* FLS_INTERNAL_FLASH_AVAILABLE == STD_ON */

#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)
extern FUNC(void, FLS_CODE) Fls_QspiSetSfarAddr  
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(Fls_AddressType, AUTOMATIC) u32Addr
);
extern FUNC( Std_ReturnType, FLS_CODE ) Fls_QspiSetLUT
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber, 
    CONST(uint32, AUTOMATIC) LUTValue
);
extern FUNC(Std_ReturnType, FLS_CODE) Fls_QspiLaunchLUTNumber
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8LUTNumber,
    CONST(uint32, AUTOMATIC) u32DataSize,
    CONST(uint8, AUTOMATIC) u8ParEn
);
extern FUNC(void, FLS_CODE) Fls_QspiResetFlags(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
extern FUNC(void, FLS_CODE) Fls_QspiSetRXWmrk(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, CONST(uint8, AUTOMATIC) u8BytesToRead);
extern FUNC(Std_ReturnType, FLS_CODE) Fls_QspiCheckControllerIdle(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
extern FUNC(Std_ReturnType, FLS_CODE) Fls_QspiReadRXBuffer
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    CONST(uint8, AUTOMATIC) u8BytesToRead
);
extern FUNC(void, FLS_CODE) Fls_QspiLoadTXBuffer
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName, 
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) p8DataPtr,
    VAR(uint8, AUTOMATIC) u8BytesToWrite
);
extern FUNC(Fls_AddressType, FLS_CODE) Fls_QspiGetHwUnitBaseAddr(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
extern FUNC(void, FLS_CODE) Fls_QspiDisableModule(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
extern FUNC(void, FLS_CODE) Fls_QspiEnableModule(CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName);
extern FUNC(void, FLS_CODE) Fls_QspiSetCalibDelayValues
(
    CONST(Fls_QspiUnitNameType, AUTOMATIC) eHwUnitName,
    CONST(uint8, AUTOMATIC) u8CoarseDelay,
    CONST(uint8, AUTOMATIC) u8FineDelay
);



#endif
#endif

/**
* @brief    Stop of Fls section CODE 
*/
#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_api_h_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FLS_API_H */

/** @}*/
