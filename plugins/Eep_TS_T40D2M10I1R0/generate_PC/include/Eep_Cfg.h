[!CODE!][!//
/**
*   @file    Eep_Cfg.h 
*   @implements Eep_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Definitions of all pre-compile configuration parameters.
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

#ifndef EEP_CFG_H
#define EEP_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eep_Cfg_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
* 
* @section Eep_Cfg_H_REF_2
* Violates MISRA 2004 Required Rule 8.7, could define variable at block scope.
* The data structure of type Eep_ConfigType shall be defined as external according to EEP352.
* 
* @section Eep_Cfg_H_REF_3
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a storage class specifier.
* This violation due to collecting configuration sets which were defined by user
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

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep_InternalTypes.h"
#include "Eep_Types.h"
#include "Mcal.h"
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    #include "Dem.h"
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_CFG                    43
#define EEP_MODULE_ID_CFG                    90
#define EEP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define EEP_AR_RELEASE_MINOR_VERSION_CFG     2
#define EEP_AR_RELEASE_REVISION_VERSION_CFG  2
#define EEP_SW_MAJOR_VERSION_CFG             1
#define EEP_SW_MINOR_VERSION_CFG             0
#define EEP_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep configuration header file are of the same vendor */
#if (EEP_TYPES_VENDOR_ID != EEP_VENDOR_ID_CFG)
#error "Eep_Types.h and Eep_Cfg.h have different vendor ids"
#endif
/* Check if current file and Eep configuration header file are of the same Autosar version */
#if ((EEP_TYPES_AR_RELEASE_MAJOR_VERSION    != EEP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EEP_TYPES_AR_RELEASE_MINOR_VERSION    != EEP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EEP_TYPES_AR_RELEASE_REVISION_VERSION != EEP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Eep_Types.h and Eep_Cfg.h are different"
#endif
/* Check if current file and Eep configuration header file are of the same software version */
#if ((EEP_TYPES_SW_MAJOR_VERSION != EEP_SW_MAJOR_VERSION_CFG) || \
     (EEP_TYPES_SW_MINOR_VERSION != EEP_SW_MINOR_VERSION_CFG) || \
     (EEP_TYPES_SW_PATCH_VERSION != EEP_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Eep_Types.h and Eep_Cfg.h are different"
#endif

/* Check if current file and Eep_InternalTypes header file are of the same vendor */
#if (EEP_VENDOR_ID_CFG != EEP_INTERNALTYPES_VENDOR_ID)
    #error "Eep_Cfg.h and Eep_InternalTypes.h have different vendor ids"
#endif
/* Check if current file and Eep_InternalTypes header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG    != EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_CFG    != EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_CFG != EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep_Cfg.h and Eep_InternalTypes.h are different"
#endif
/* Check if current file and Eep_InternalTypes header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_CFG != EEP_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_CFG != EEP_INTERNALTYPES_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_CFG != EEP_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep_Cfg.h and Eep_InternalTypes.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same version */
    #if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (EEP_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Eep_Types.h and Mcal.h are different"
    #endif
#endif
[!INDENT "0"!][!//
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    [!WS "1"!]/* Check if source file and Dem header file are of the same version */
    [!WS "1"!]#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
    [!WS "1"!]     (EEP_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION) \
    [!WS "1"!]    )
    [!WS "1"!]#error "AutoSar Version Numbers of Eep_Cfg.h and Dem.h are different"
    [!WS "1"!]#endif
    #endif
[!ENDIF!][!//
[!ENDINDENT!][!//

[!INCLUDE "Eep_VersionCheck.m"!][!//

[!MACRO "EepExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(EepInitConfiguration)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]/* @violates @ref Eep_Cfg_H_REF_2 Could define variable at block scope */[!CR!][!ENDCODE!]
        [!CODE!][!WS4!]extern CONST(Eep_ConfigType, EEP_CONST) [!"$configName"!]_[!"."!];[!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]/* @violates @ref Eep_Cfg_H_REF_2 Could define variable at block scope */[!CR!][!ENDCODE!]
    [!CODE!][!WS4!]extern CONST(Eep_ConfigType, EEP_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* STD_ON: Eeprom access code loaded on job start / unloaded on job end or error */
#define EEP_AC_LOAD_ON_JOB_START    [!IF "NonAutosar/EepAcLoadOnJobStart"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Eep_Cancel function */
#define EEP_CANCEL_API              [!IF "NonAutosar/EepCancelApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Eep_Compare function */
#define EEP_COMPARE_API             [!IF "NonAutosar/EepCompareApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Pre-processor switch to enable and disable development error detection */
#define EEP_DEV_ERROR_DETECT        [!IF "EepGeneral/EepDevErrorDetect"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Eep_GetJobResult function */
#define EEP_GET_JOB_RESULT_API      [!IF "NonAutosar/EepGetJobResultApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Eep_GetStatus function */
#define EEP_GET_STATUS_API          [!IF "NonAutosar/EepGetStatusApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Eep_SetMode function */
#define EEP_SET_MODE_API            [!IF "NonAutosar/EepSetModeApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Compile switch to enable and disable the Eep_QuickWrite function */
#define EEP_ENABLE_QUICK_WRITES_API   [!IF "NonAutosar/EepEnableQuickWriteApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Pre-processor switch to enable / disable the API to use interrupts for erase and write jobs */
#define EEP_USE_INTERRUPTS          [!IF "EepGeneral/EepUseInterrupts"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Pre-processor switch to enable / disable the API to read out the modules version information */
#define EEP_VERSION_INFO_API        [!IF "EepGeneral/EepVersionInfoApi"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Timeout handling enabled */
#define EEP_TIMEOUT_HANDLING       [!IF "node:exists(EepGeneral/EepTimeouts)"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!]

/* Timeout value for Erase and Write operation */
#define EEP_ASYNC_WRITE_TIMEOUT_VALUE     [!IF "node:exists(EepGeneral/EepTimeouts)"!][!"EepGeneral/EepTimeouts/EepAsyncWriteTimeout"!][!ELSE!]0[!ENDIF!]U
#define EEP_SYNC_WRITE_TIMEOUT_VALUE      [!IF "node:exists(EepGeneral/EepTimeouts)"!][!"EepGeneral/EepTimeouts/EepSyncWriteTimeout"!][!ELSE!]0[!ENDIF!]U

/* Timeout value for Abort operation */
#define EEP_ABT_TIMEOUT_VALUE        [!IF "node:exists(EepGeneral/EepTimeouts)"!][!"EepGeneral/EepTimeouts/EepAbortTimeout"!][!ELSE!]0[!ENDIF!]U

/* The contents of an erased eeprom memory cell */
#define EEP_ERASED_VALUE_U32         ([!"num:inttohex(EepPublishedInformation/EepEraseValue)"!]UL)
#define EEP_ERASED_VALUE_U8          (0xFFU)

/* The EEP size */
#define EEP_SIZE                    ([!"num:inttohex(ecu:get('Eep.EepSizetotalvalue') - NonAutosar/EepSizeUsedForCSEC)"!]UL)
/* Eep Driver Index */
#define EEP_DRIVER_INDEX            [!"num:i(EepGeneral/EepDriverIndex)"!]U

/**
* @brief   Switches the Production Error Detection and Notification OFF
*/
#define EEP_DISABLE_DEM_REPORT_ERROR_STATUS        [!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!](STD_OFF)[!ELSE!](STD_ON)[!ENDIF!]


/* page syze of 1 byte */
#define EEP_PAGE_SIZE_1BYTE                      [!"EepPublishedInformation/EepWriteUnitSize"!]U
/* page syze of 2 bytes */
#define EEP_PAGE_SIZE_2BYTES                     2U
/* page syze of 4 bytes */
#define EEP_PAGE_SIZE_4BYTES                     4U
/* page syze of 0 bytes */
#define EEP_PAGE_SIZE_0BYTES                     0U
 
/* defines if the write operation will be executed in asynchronuos mode or not*/
#define EEP_ASYNC_OPERATIONS_ENABLED            [!IF "NonAutosar/EepPageAsynchBehaviorEn"!](STD_ON) [!ELSE!] (STD_OFF) [!ENDIF!]
/* User mode support */
#define EEP_ENABLE_USER_MODE_SUPPORT            (STD_OFF)


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* Map access routine type according to the timeout handling setting */
/* access routine without timeout parameters */
typedef Eep_Eeprom_AcErasePtrNoTOType Eep_Eeprom_AcErasePtrType;
typedef Eep_Eeprom_AcWritePtrNoTOType Eep_Eeprom_AcWritePtrType;


/**
* @brief          Eep Config Type
* @details        Eep module initialization data structure
*
*/
typedef struct 
{
    /** 
    * @brief pointer to erase access code function in RAM or ROM
    */
    Eep_Eeprom_AcErasePtrType acErasePtr; 
    /** 
    * @brief pointer to write access code function in RAM or ROM 
    */
    Eep_Eeprom_AcWritePtrType acWritePtr; 
    /** 
    * @brief pointer to ac callback function 
    */  
    Eep_ACCallbackPtrType acCallBackPtr;
    /** 
    * @brief pointer to job end notification function 
    */
    Eep_JobEndNotificationPtrType jobEndNotificationPtr; 
    /** 
    * @brief pointer to job error notification function 
    */
    Eep_JobErrorNotificationPtrType jobErrorNotificationPtr; 
    /** 
    * @brief pointer to start eeprom access notification 
    */
    Eep_StartEepromAccessNotifPtrType startEepromAccessNotifPtr; 
    /** 
    * @brief pointer to finished eeprom access notification
    */
    Eep_FinishedEepromAccessNotifPtrType finishedEepromAccessNotifPtr; 
    /** 
    * @brief default EEP device mode after initialization (MEMIF_MODE_FAST, MEMIF_MODE_SLOW) 
    */
    MemIf_ModeType eDefaultMode; 
    /** 
    * @brief max number of bytes to read in one cycle of Eep_MainFunction (fast mode) 
    */
    Eep_LengthType u32MaxReadFastMode; 
    /** 
    * @brief max number of bytes to read in one cycle of  Eep_MainFunction (normal mode) 
    */
    Eep_LengthType u32MaxReadNormalMode; 
    /** 
    * @brief max number of bytes to write in one cycle of Eep_MainFunction (fast mode) 
    */
    Eep_LengthType u32MaxWriteFastMode; 
    /** 
    * @brief max number of bytes to write in one cycle of  Eep_MainFunction (normal mode) 
    */
    Eep_LengthType u32MaxWriteNormalMode; 
    
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    /** 
     * @brief EEP Driver DEM Error: EEP_E_COMPARE_FAILED     
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_CompareFailedCfg;
    /** 
     * @brief EEP Driver DEM Error: EEP_E_ERASE_FAILED
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_EraseFailedCfg;
    /** 
     * @brief EEP Driver DEM Error: EEP_E_READ_FAILED
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_ReadFailedCfg;
    /** 
     * @brief EEP Driver DEM Error: EEP_E_WRITE_FAILED
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_WriteFailedCfg;
    /** 
     * @brief EEP Driver DEM Error: EEP_E_BO_MAINTENANCE
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_BOMaintenanceCfg;
    /** 
     * @brief EEP Driver DEM Error: EEP_E_BO_QUICK_WRITES
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_BOQuickWritesCfg;
    /** 
     * @brief EEP Driver DEM Error: EEP_E_BO_NORMAL_WRITES
     */    
    CONST(Mcal_DemErrorType, EEP_CONST) Eep_E_BONormalWritesCfg;
[!ENDIF!][!//
    /** 
     * @brief EEP Config Set CRC checksum     
     */    
    Eep_CrcType u16ConfigCrc;
     
} Eep_ConfigType;

/*==================================================================================================
                                 GLOBAL CONSTANT DECLARATIONS
==================================================================================================*/

#define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Eep_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
[!INDENT "0"!][!//
#include "Eep_MemMap.h"

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//

 /* Declaration of post-build configuration set structure */ 
    [!CALL "EepExportDriverConfiguration"!][!//
[!ENDIF!][!//

[!IF "IMPLEMENTATION_CONFIG_VARIANT='VariantPreCompile'"!][!//
  [!IF "variant:size()<=1"!][!//
#define EEP_PRECOMPILE_SUPPORT
/* Declaration of pre-compile configuration set structure */ 
/* @violates @ref Eep_Cfg_H_REF_3 C macros shall only expand to a storage class specifier */
#define Eep_PBCfgVariantPredefined [!"as:name(EepInitConfiguration)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
/* @violates @ref Eep_Cfg_H_REF_2 Could define variable at block scope */
extern CONST(Eep_ConfigType, EEP_CONST) Eep_PBCfgVariantPredefined;
  [!ENDIF!][!//
[!ENDIF!][!//

#define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Eep_Cfg_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Eep_MemMap.h"

[!ENDINDENT!][!//
[!ENDCODE!][!//
#ifdef __cplusplus
}
#endif

#endif /* EEP_CFG_H */
