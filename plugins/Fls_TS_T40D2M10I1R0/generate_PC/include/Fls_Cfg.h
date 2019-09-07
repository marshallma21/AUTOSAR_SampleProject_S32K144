[!AUTOSPACING!]
[!CODE!][!//
/**
*   @file    Fls_Cfg.h 
*   @implements Fls_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all pre-compile configuration parameters.
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

#ifndef FLS_CFG_H
#define FLS_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fls_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
* 
* @section Fls_Cfg_H_REF_2
* Violates MISRA 2004 Required Rule 8.7, could define variable at block scope.
* The data structure of type Fls_ConfigType shall be defined as external according to FLS352.
* 
* @section Fls_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a storage class specifier.
* This violation due to collecting configuration sets which were defined by user
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
* 
*/

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls_Types.h"
#include "Mcal.h"
[!ENDINDENT!][!//
#include "MemIf_Types.h"

#include "Fls_Flash_Types.h"
#include "Fls_Qspi_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG                    43
#define FLS_MODULE_ID_CFG                    92
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG     2
#define FLS_AR_RELEASE_REVISION_VERSION_CFG  2
#define FLS_SW_MAJOR_VERSION_CFG             1
#define FLS_SW_MINOR_VERSION_CFG             0
#define FLS_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls configuration header file are of the same vendor */
#if (FLS_TYPES_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls_Types.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fls configuration header file are of the same Autosar version */
#if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_TYPES_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_TYPES_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls configuration header file are of the same software version */
#if ((FLS_TYPES_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_TYPES_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_TYPES_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Fls_Types.h and Fls_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fls_Types.h and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemIf_Types.h file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG    != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_CFG    != MEMIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls_Cfg.h and MemIf_Types.h are different"
    #endif
#endif

/* Check if current file and Fls_Flash_Types configuration header file are of the same vendor */
#if (FLS_FLASH_TYPES_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls_Flash_Types.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fls_Flash_Types configuration header file are of the same Autosar version */
#if ((FLS_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_FLASH_TYPES_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_FLASH_TYPES_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls_Flash_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls_Flash_Types configuration header file are of the same software version */
#if ((FLS_FLASH_TYPES_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_FLASH_TYPES_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_FLASH_TYPES_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Fls_Flash_Types.h and Fls_Cfg.h are different"
#endif

/* Check if current file and Fls_Qspi_Types configuration header file are of the same vendor */
#if (FLS_QSPI_TYPES_VENDOR_ID != FLS_VENDOR_ID_CFG)
#error "Fls_Qspi_Types.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fls_Qspi_Types configuration header file are of the same Autosar version */
#if ((FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION    != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION    != FLS_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FLS_QSPI_TYPES_AR_RELEASE_REVISION_VERSION != FLS_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Fls_Qspi_Types.h and Fls_Cfg.h are different"
#endif
/* Check if current file and Fls_Qspi_Types configuration header file are of the same software version */
#if ((FLS_QSPI_TYPES_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_QSPI_TYPES_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_QSPI_TYPES_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Fls_Qspi_Types.h and Fls_Cfg.h are different"
#endif

[!INCLUDE "Fls_VersionCheck.m"!][!//

[!MACRO "FlsExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(FlsConfigSet)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]/* @violates @ref Fls_Cfg_H_REF_2 Could define variable at block scope */[!CR!][!ENDCODE!]
        [!CODE!][!WS4!]extern CONST(Fls_ConfigType, FLS_CONST) [!"$configName"!]_[!"."!];[!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]/* @violates @ref Fls_Cfg_H_REF_2 Could define variable at block scope */[!CR!][!ENDCODE!]
    [!CODE!][!WS4!]extern CONST(Fls_ConfigType, FLS_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* STD_ON: Internal flash is present on the current platform. */
#define FLS_INTERNAL_FLASH_AVAILABLE    ([!"ecu:get('Fls.Internal.Flash.Available')"!])

/* STD_ON: External flash connected via QSPI interface is available on the current platform. */
#define FLS_QSPI_FLASH_AVAILABLE    ([!"ecu:get('Fls.External.Qspi.Available')"!])

/* STD_ON: Flash access code loaded on job start / unloaded on job end or error */
#define FLS_AC_LOAD_ON_JOB_START    ([!IF "FlsGeneral/FlsAcLoadOnJobStart"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_Cancel function */
#define FLS_CANCEL_API              ([!IF "FlsGeneral/FlsCancelApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_Compare function */
#define FLS_COMPARE_API             ([!IF "FlsGeneral/FlsCompareApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_BlankCheck function */
#define FLS_BLANK_CHECK_API         ([!IF "FlsGeneral/FlsBlankCheckApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable and disable development error detection */
#define FLS_DEV_ERROR_DETECT        ([!IF "FlsGeneral/FlsDevErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable and disable runtime error detection */
#define FLS_RUNTIME_ERROR_DETECT    ([!IF "FlsGeneral/FlsRuntimeErrorDetect"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_GetJobResult function */
#define FLS_GET_JOB_RESULT_API      ([!IF "FlsGeneral/FlsGetJobResultApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_GetStatus function */
#define FLS_GET_STATUS_API          ([!IF "FlsGeneral/FlsGetStatusApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Compile switch to enable and disable the Fls_SetMode function */
#define FLS_SET_MODE_API            ([!IF "FlsGeneral/FlsSetModeApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to use interrupts for erase and write jobs */
#define FLS_USE_INTERRUPTS          ([!IF "FlsGeneral/FlsUseInterrupts"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define FLS_VERSION_INFO_API        ([!IF "FlsGeneral/FlsVersionInfoApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to report data storage (ECC) errors to the flash driver */
#define FLS_DSI_HANDLER_API         ([!IF "FlsGeneral/FlsDsiHandlerApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the API to report data storage (ECC) errors to the flash driver */
#define FLS_ECC_WITH_NO_EXCEPTION   ([!IF "FlsGeneral/FlsDsiHandlerApi"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the write blank check */
#define FLS_WRITE_BLANK_CHECK       ([!IF "FlsGeneral/FlsWriteBlankCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])


/* Pre-processor switch to enable / disable the write verify check */
#define FLS_WRITE_VERIFY_CHECK      ([!IF "FlsGeneral/FlsWriteVerifyCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Pre-processor switch to enable / disable the erase blank check */
#define FLS_ERASE_BLANK_CHECK       ([!IF "FlsGeneral/FlsEraseBlankCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* The maximum number of bytes to blank check in one cycle of the flash driver's job processing function */
#define FLS_MAX_ERASE_BLANK_CHECK   ([!"FlsGeneral/FlsMaxEraseBlankCheck"!]U)

/* Timeout handling enabled */
#define FLS_TIMEOUT_HANDLING        ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/* Timeout value for Erase and Write operation - internal flash operations. */
#define FLS_ASYNC_WRITE_TIMEOUT_VALUE       ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsAsyncWriteTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_ASYNC_ERASE_TIMEOUT_VALUE       ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsAsyncEraseTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_SYNC_WRITE_TIMEOUT_VALUE        ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsSyncWriteTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_SYNC_ERASE_TIMEOUT_VALUE        ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsSyncEraseTimeout"!][!ELSE!]0[!ENDIF!]U)
/* Timeout value for Erase and Write operation - QSPI flash operations. */
#define FLS_QSPI_SYNC_READ_TIMEOUT_VALUE    ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiSyncReadTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_SYNC_WRITE_TIMEOUT_VALUE   ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiSyncWriteTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_SYNC_ERASE_TIMEOUT_VALUE   ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiSyncEraseTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_ASYNC_WRITE_TIMEOUT_VALUE  ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiAsyncWriteTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_ASYNC_ERASE_TIMEOUT_VALUE  ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiAsyncEraseTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_IRQ_READ_TIMEOUT_VALUE     ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiIrqReadTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_IRQ_ERASE_TIMEOUT_VALUE    ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiIrqEraseTimeout"!][!ELSE!]0[!ENDIF!]U)
#define FLS_QSPI_IRQ_WRITE_TIMEOUT_VALUE    ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsQspiIrqWriteTimeout"!][!ELSE!]0[!ENDIF!]U)
/* Timeout value for Abort operation */
#define FLS_ABT_TIMEOUT_VALUE           ([!IF "node:exists(FlsGeneral/FlsTimeouts)"!][!"FlsGeneral/FlsTimeouts/FlsAbortTimeout"!][!ELSE!]0[!ENDIF!]U)

/* Number of bytes in RAM needed for the erase flash access code */
#define FLS_AC_SIZE_ERASE           ([!"FlsPublishedInformation/FlsAcSizeErase"!]U)

/* Number of bytes in RAM needed for the write flash access code */
#define FLS_AC_SIZE_WRITE           ([!"FlsPublishedInformation/FlsAcSizeWrite"!]U)

/* The contents of an erased flash memory cell */
#define FLS_ERASED_VALUE            ([!"num:inttohex(FlsPublishedInformation/FlsErasedValue)"!]U)

/* Fls Driver Index */
#define FLS_DRIVER_INDEX            ([!"num:i(FlsGeneral/FlsDriverIndex)"!]U)

[!IF "node:exists(NonAutosar/FlsCheckFlexNvmRatio)"!][!//
/* Flash check FlexNvm partion ratio at initialization */
#define FLASH_CHECK_FLEXNVM_RATIO           ([!IF "NonAutosar/FlsCheckFlexNvmRatio"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//

[!IF "ecu:has('Fls.AbortHwOperationSupported')"!][!//
[!VAR "AbortHwOperationSupported" = "ecu:get('Fls.AbortHwOperationSupported')"!][!//
[!IF "$AbortHwOperationSupported='STD_ON'"!][!//
/* Flash operation abort supported in hardware */
#define FLS_HW_OPERATION_ABORT_SUPPORTED        (STD_ON)
[!ELSEIF "$AbortHwOperationSupported='STD_OFF'"!][!//
/* Flash operation abort not supported in hardware */
#define FLS_HW_OPERATION_ABORT_SUPPORTED        (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
/* Flash operation abort supported in hardware */
#define FLS_HW_OPERATION_ABORT_SUPPORTED        (STD_ON)    
[!ENDIF!][!//

[!IF "node:exists(NonAutosar/FlsExtendedReadErrorCheck)"!][!//
/* Flash enable redundant read error check */
#define FLS_EXTENDED_READ_ERROR_CHECK           ([!IF "NonAutosar/FlsExtendedReadErrorCheck"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
[!ENDIF!][!//

[!IF "ecu:get('Fls.UserModeSupport')='true'"!] [!//
/* User mode support */
        #define FLS_ENABLE_USER_MODE_SUPPORT        ([!IF "NonAutosar/FlsEnableUserModeSupport"!]STD_ON [!ELSE!] STD_OFF [!ENDIF!])
#define FLS_USER_MODE_REG_PROT_ENABLED      (STD_OFF) 
[!IF "ecu:has('Fls.C55fmcRegisterProtectionAvailable')"!][!//
[!IF "ecu:get('Fls.C55fmcRegisterProtectionAvailable') = 'true'"!][!//
#define FLS_FLASH_REG_PROT_AVAILABLE
[!ENDIF!] [!//
[!ENDIF!] [!//
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
        #error "MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Fls in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined"
    #endif /* (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
[!ELSE!] [!//
/* User mode support */
#define FLS_ENABLE_USER_MODE_SUPPORT        (STD_OFF)
[!ENDIF!] [!//

#ifdef MCAL_CACHE_RUNTIME_MNGMNT
    #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)  
        /* Enable the use of cache invalidate */
        [!IF "node:exists(NonAutosar/FlsSynchronizeCache)"!][!//
        #define FLS_SYNCRONIZE_CACHE    [!WS "4"!]([!IF "NonAutosar/FlsSynchronizeCache"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
        [!ELSE!][!//
        #define FLS_SYNCRONIZE_CACHE    [!WS "4"!](STD_OFF)
        [!ENDIF!][!//
    #else /* MCAL_CACHE_RUNTIME_MNGMNT */     
        #define FLS_SYNCRONIZE_CACHE    [!WS "4"!](STD_OFF)         
    #endif /* MCAL_CACHE_RUNTIME_MNGMNT */     
#else /* MCAL_CACHE_RUNTIME_MNGMNT */    
    #define FLS_SYNCRONIZE_CACHE    [!WS "4"!](STD_OFF)    
#endif /* MCAL_CACHE_RUNTIME_MNGMNT */

[!INDENT "0"!][!//
[!IF "ecu:has('Fls.DifferentLockBit')"!][!//
    /*Diference from lock/select bit of FLS_DATA_ARRAY_0_PART_1_L01 on other deriveatives */
    #define FLS_SEPARATED_LOCK_BIT_POSITION
[!ENDIF!] [!//
[!ENDINDENT!][!//

/* Is there at least one (DATA) flash sector where ECCs does not lead to the exception? yes/no => STD_ON/STD_OFF */
#define FLS_DATA_FLASH_EXISTS         ([!IF "ecu:get('Fls.DataFlashExists')='true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
#define FLASH_DSI_EXC_SYNDROME          ([!"num:inttohex(num:hextoint(ecu:get('Fls.ECCSyndrome')))"!]UL)
#define FLASH_DSI_EXC_SYNDROME_CACHE    ([!"num:inttohex(num:hextoint(ecu:get('Fls.ECCSyndromeCache')))"!]UL)

/* Activate flash prefetch buffer invalidation */
/* @errata ERR_IPV_FMC_0001 */
#ifdef ERR_IPV_FMC_0001
    #if (ERR_IPV_FMC_0001 == STD_ON)   
        /* Do not use flash prefetch buffer invalidation. The errata requires flash speculation to be disabled. */
        #define FLASH_INVALIDATE_PREFETCH_BUFFERS (STD_OFF)
    #else
        /* Activate flash prefetch buffer invalidation */
        #define FLASH_INVALIDATE_PREFETCH_BUFFERS (STD_ON)
    #endif
#else
    /* Activate flash prefetch buffer invalidation */
    #define FLASH_INVALIDATE_PREFETCH_BUFFERS (STD_ON)
#endif

/* External QSPI flash memory parameters */

/* The LUT is locked and unlocked by driver when modifying it. */
#define FLS_QSPI_LOCK_LUT                   ([!IF "NonAutosar/FlsQspiLockLUT"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* Internal sectors are present or not in the current configuration. */
#define FLS_INTERNAL_SECTORS_CONFIGURED     ([!IF "NonAutosar/FlsInternalSectorsConfigured"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* External QSPI sectors are present or not in the current configuration. */
#define FLS_QSPI_SECTORS_CONFIGURED         ([!IF "NonAutosar/FlsExternalSectorsConfigured"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])
/* Number of on-chip available QSPI hardware units. */
#define FLS_QSPI_AVAILABLE_UNITS            ([!"num:i(count(ecu:list('Fls.External.HwUnit')))"!]U)
/* Qspi Hyperflash mode enabled. */
#define FLS_QSPI_HYPERFLASH_MODE            ([!IF "NonAutosar/FlsQspiHyperflashEnable"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!])

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Map access routine type according to the timeout handling setting */
#if (FLS_TIMEOUT_HANDLING == STD_ON)
    /* access routine with timeout parameters */
    typedef Fls_AcErasePtrTOType Fls_AcErasePtrType;
    typedef Fls_AcWritePtrTOType Fls_AcWritePtrType;
#else
    /* access routine without timeout parameters */
    typedef Fls_AcErasePtrNoTOType Fls_AcErasePtrType;
    typedef Fls_AcWritePtrNoTOType Fls_AcWritePtrType;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

/**
* @brief          Fls Config Type
* @details        Fls module initialization data structure
* @implements     Fls_ConfigType_typedef
*/
typedef struct 
{
    /** 
    * @brief pointer to erase access code function in RAM or ROM
    */
    Fls_AcErasePtrType acErasePtr; 
    /** 
    * @brief pointer to write access code function in RAM or ROM 
    */
    Fls_AcWritePtrType acWritePtr; 
    /** 
    * @brief pointer to ac callback function 
    */  
    Fls_ACCallbackPtrType acCallBackPtr;
    /** 
    * @brief pointer to job end notification function 
    */
    Fls_JobEndNotificationPtrType jobEndNotificationPtr; 
    /** 
    * @brief pointer to job error notification function 
    */
    Fls_JobErrorNotificationPtrType jobErrorNotificationPtr; 
    /** 
    * @brief pointer to start flash access notification 
    */
    Fls_StartFlashAccessNotifPtrType startFlashAccessNotifPtr; 
    /** 
    * @brief pointer to finished flash access notification
    */
    Fls_FinishedFlashAccessNotifPtrType finishedFlashAccessNotifPtr; 
    /** 
    * @brief default FLS device mode after initialization (MEMIF_MODE_FAST, MEMIF_MODE_SLOW) 
    */
    MemIf_ModeType eDefaultMode; 
    /** 
    * @brief max number of bytes to read in one cycle of Fls_MainFunction (fast mode) 
    */
    Fls_LengthType u32MaxReadFastMode; 
    /** 
    * @brief max number of bytes to read in one cycle of  Fls_MainFunction (normal mode) 
    */
    Fls_LengthType u32MaxReadNormalMode; 
    /** 
    * @brief max number of bytes to write in one cycle of Fls_MainFunction (fast mode) 
    */
    Fls_LengthType u32MaxWriteFastMode; 
    /** 
    * @brief max number of bytes to write in one cycle of  Fls_MainFunction (normal mode) 
    */
    Fls_LengthType u32MaxWriteNormalMode; 
    /** 
    * @brief number of configured logical sectors 
    */
    Fls_SectorCountType u32SectorCount;
    /** 
    * @brief pointer to array containing last logical address of each configured sector 
    */
    CONST( Fls_AddressType, FLS_CONST) (*paSectorEndAddr)[]; 
    /**
    * @brief pointer to array containing physical sector ID of each configured sector 
    */
    CONSTP2CONST( Fls_Flash_InternalSectorInfoType, FLS_VAR, FLS_APPL_CONST) (*pSectorList)[]; 
    /**
    * @brief pointer to array containing flags set of each configured sector 
    */
    CONST( uint8, FLS_CONST) (*paSectorFlags)[]; 
    /**
    * @brief pointer to array containing program size of each configured sector 
    */
    CONST( Fls_LengthType, FLS_CONST) (*paSectorProgSize)[]; 
    /**
    * @brief pointer to array containing page size information of each configured sector 
    */
    CONST( Fls_LengthType, FLS_CONST) (*paSectorPageSize)[]; 
    /**
    * @brief pointer to array containing Unlock information of each configured sector 
    */
    CONST( uint8, FLS_CONST) (*paSectorUnlock)[]; 
    /**
    * @brief Pointer to array containing the hardware channel(internal, external_qspi, external_emmc) of each configured sector.
    */
    CONST( Fls_HwChType, FLS_CONST) (*paHwCh)[];
    /**
    * @brief Pointer to array containing the configured hardware start address of each external sector.
    */
    CONST( uint32, FLS_CONST) (*paSectorHwAddress)[];
    
    /** @brief  Pointer to configuration structure of QSPI. */
    P2CONST(Fls_QspiCfgConfigType, FLS_VAR, FLS_APPL_CONST)  pFlsQspiCfgConfig;
    
    /** 
     * @brief FLS Config Set CRC checksum     
     */    
    Fls_CrcType u16ConfigCrc;
     
} Fls_ConfigType;

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Fls_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
[!INDENT "0"!][!//
#include "Fls_MemMap.h"

[!IF "ecu:has('Fls.k118PhysicalSectorAvailable') or ecu:has('Fls.k142PhysicalSectorAvailable') or ecu:has('Fls.k144PhysicalSectorAvailable') or ecu:has('Fls.k146PhysicalSectorAvailable') or ecu:has('Fls.k148PhysicalSectorAvailable')"!][!//
    #define P_FLASH_BASE_ADDR   (0x00000000UL)
    #define D_FLASH_BASE_ADDR   (0x10000000UL)
    #define P_FLASH_SIZE        ([!"(ecu:get('Fls.PFlashsize'))"!]U)
    #define D_FLASH_SIZE        ([!"(ecu:get('Fls.DFlashsize'))"!]U)
[!ENDIF!][!//

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//

 /* Declaration of post-build configuration set structure */ 
    [!CALL "FlsExportDriverConfiguration"!][!//
[!ENDIF!][!//

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
  [!IF "variant:size()<=1"!][!//
#define FLS_PRECOMPILE_SUPPORT
/* Declaration of pre-compile configuration set structure */ 
/* @violates @ref Fls_Cfg_H_REF_3 C macros shall only expand to a storage class specifier */
#define Fls_PBCfgVariantPredefined [!"as:name(FlsConfigSet)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
/* @violates @ref Fls_Cfg_H_REF_2 Could define variable at block scope */
extern CONST(Fls_ConfigType, FLS_CONST) Fls_PBCfgVariantPredefined;
  [!ENDIF!][!//
[!ENDIF!][!//

#define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Fls_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Fls_MemMap.h"

[!ENDINDENT!][!//
[!ENDCODE!][!//
#ifdef __cplusplus
}
#endif

#endif /* FLS_CFG_H */
