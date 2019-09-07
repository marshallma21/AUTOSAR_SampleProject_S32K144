/**
*   @file    Eep_InternalTypes.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Definitions of all Eeprom driver private types.
*
*   @addtogroup [EEP]
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

#ifndef EEP_INTERNALTYPES_H
#define EEP_INTERNALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eep_InternalTypes_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section Fee_InternalTypes_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
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
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @{
* @file           Fee_InternalTypes.h
* @brief          Source file version information
* 
*/
#define EEP_INTERNALTYPES_VENDOR_ID                       43
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define EEP_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define EEP_INTERNALTYPES_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define EEP_INTERNALTYPES_AR_RELEASE_REVISION_VERSION     2
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define EEP_INTERNALTYPES_SW_MAJOR_VERSION                1
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define EEP_INTERNALTYPES_SW_MINOR_VERSION                0
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define EEP_INTERNALTYPES_SW_PATCH_VERSION                1
/** @} */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Type of job currently executed by Eep_MainFunction.
*/

typedef enum
{
    /**
    * @brief erase one or more complete eeprom sectors
    */
    EEP_JOB_ERASE = 0,    
    /**
    * @brief write one or more complete eeprom pages 
    */
    EEP_JOB_WRITE,        
    /**
    * @brief read one or more bytes from eeprom memory 
    */
    EEP_JOB_READ,     
    /**
    * @brief compare data buffer with content of eeprom memory
    */
    EEP_JOB_COMPARE

} Eep_JobType;

/**
* @brief          Result of low-level eeprom operation.
*/
typedef enum 
{
    EEPROM_E_OK = 0,                 /**< @brief operation succeeded */
    EEPROM_E_FAILED,                 /**< @brief operation failed due to hardware error */
    EEPROM_E_BLOCK_INCONSISTENT,     /**< @brief data buffer doesn't match with content of eeprom memory */
    EEPROM_E_PENDING,                /**< @brief operation is pending */
    EEPROM_E_WRITE_REQUESTED        /**< @brief only for the write async mode; page write request was sent to hardware */
} Eep_Eeprom_ReturnType;


/**
* @brief          Size of data to be processeed by CRC.
*
*
*/
typedef enum 
{
    EEP_CRC_8_BITS = 0,
    EEP_CRC_16_BITS
} Eep_CrcDataSizeType;

/**
* @brief   Urgency for EEP writes: normal or quick writes
*
*/
typedef enum 
{
    EEP_URGENCY_NORMAL_WRITES = 0,
    EEP_URGENCY_QUICK_WRITES
} Eep_UrgencyModeType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/**
* @brief          Type of job currently executed 
*/
typedef Eep_JobType Eep_Eeprom_JobType;


/** 
    @brief Eep_Eeprom_SetFRControl Type used for the Set FLEXRAM function command
*/
typedef enum 
{
    EEP_SET_AS_NORMAL_RAM        = 0xFF,       /**< @brief control code for function "Set as normal RAM" */
    EEP_COMPLETE_QUICK_WRITES    = 0xAA,       /**< @brief control code for function "Complete Quick Writes" */
    EEP_GET_FLEXRAM_STATUS       = 0x77,       /**< @brief control code for function "Get Quick Writes Status" */
    EEP_SET_QUICK_WRITES_MODE    = 0x55,       /**< @brief control code for function "Set Quick Writes Mode" */
    EEP_SET_AS_EERAM             = 0x00        /**< @brief control code for function "Set as Eeram"*/
} Eep_Eeprom_SetFRControlType;

typedef Eep_Eeprom_SetFRControlType Eep_SetFRControlType;

/** 
    @brief type used for the brown out detection codes
*/
typedef enum 
{
    EEP_NO_BO_DETECTED = 0x0, 
    EEP_BO_DURING_MAINTENANCE_DETECTED = 0x1, 
    EEP_BO_DURING_QUICK_WRITES_DETECTED = 0x2, 
    EEP_BO_DURING_NORMAL_WRITES= 0x4 
} Eep_Eeprom_BrownOutCodeType;

#ifdef __cplusplus
}
#endif

#endif /* EEP_INTERNALTYPES_H */

/** @}*/
