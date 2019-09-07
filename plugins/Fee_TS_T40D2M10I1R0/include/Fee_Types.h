/**
*   @file    Fee_Types.h
*   @implements Fee_Types.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Exported types.
*   @details Definitions of all flash EEPROM emulation driver exported types.
*
*   @addtogroup FEE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : none
*   Dependencies         : Fls
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
#ifndef FEE_TYPES_H
#define FEE_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_types_h_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Fls.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_TYPES_VENDOR_ID                    43
#define FEE_TYPES_MODULE_ID                    21
/* @violates @ref Fee_types_h_REF_1 Identifier exceeds 31 characters */
#define FEE_TYPES_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Fee_types_h_REF_1 Identifier exceeds 31 characters */
#define FEE_TYPES_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Fee_types_h_REF_1 Identifier exceeds 31 characters */
#define FEE_TYPES_AR_RELEASE_REVISION_VERSION  2
#define FEE_TYPES_SW_MAJOR_VERSION             1
#define FEE_TYPES_SW_MINOR_VERSION             0
#define FEE_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types header file are of the same version */
    #if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fee_Types.h and Std_Types.h are different"
    #endif
    /* Check if current file and Fls header file are of the same version */
    #if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_TYPES_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fee_Types.h and Fls.h are different"
    #endif
    /* Check if this file and MemIf_Types.h header file are of the same AUTOSAR version */
    #if ((FEE_TYPES_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_TYPES_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR version numbers of Fee_Types.h and MemIf_Types.h are different"
    #endif
#endif

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief        Fee cluster group run-time Information
* @api
*/
typedef struct
{
    Fls_AddressType  clusterTotalSpace;   /**< @brief Total space in the selected cluster group */
    Fls_AddressType  clusterFreeSpace;    /**< @brief Free space in the selected cluster group */
    uint8            blockHeaderOverhead; /**< @brief Block Overhead (header valid and inval flag)*/
    uint8            virtualPageSize;     /**< @brief Fee Virtual Page Size */
    uint32           numberOfSwap;        /**< @brief Number of cluster swap performed in the
                                                      selected cluster group */
} Fee_ClusterGroupRuntimeInfoType;


/**
* @brief Fee block assignment type
* @api
*/
typedef enum 
{
    FEE_PROJECT_SHARED          = 0x01,     /** block is used for all the projects */
    FEE_PROJECT_APPLICATION     = 0x02,     /** block is used for the application project */
    FEE_PROJECT_BOOTLOADER      = 0x03,     /** block is used for the bootloader project */
    FEE_PROJECT_RESERVED        = 0xFF      /** the value is reserved */
} Fee_BlockAssignmentType;

/**
* @brief        Fee block configuration structure
* @api
* @implements   FeeBlockConfiguration_Object
*/
typedef struct
{
    /** @implements   FeeBlockNumber_Object */
    uint16 blockNumber;                         /**< @brief Fee block number */
    /** @implements   FeeBlockSize_Object */
    uint16 blockSize;                           /**< @brief Size of Fee block in bytes */
    uint8 clrGrp;                               /**< @brief  Index of cluster group the Fee
                                                                block belongs to */
    /** @implements   FeeImmediateData_Object */
    boolean immediateData;                      /**< @brief TRUE if immediate data block */
    Fee_BlockAssignmentType blockAssignment;    /**< @brief specifies which project uses this block */
} Fee_BlockConfigType;

/**
* @brief Fee cluster configuration structure
* @api
*/
typedef struct
{
    Fls_AddressType startAddr;   /**< @brief Address of Fee cluster in flash */
    Fls_LengthType length;       /**< @brief Size of Fee cluster in bytes */
} Fee_ClusterType;

/**
* @brief Fee cluster group configuration structure
* @api
* @implements   Fee_ClusterGroupType_Struct
*/
typedef struct
{
    CONSTP2CONST( Fee_ClusterType, FEE_CONST, FEE_APPL_CONST ) clrPtr;
                                 /** < @brief Pointer to array of Fee cluster
                                       configurations */
    uint32 clrCount;             /**< @brief Number of clusters in cluster group */
     /**
     * @brief Size of reserved area in the given cluster group (memory occupied by immediate blocks)
     */
     Fls_LengthType reservedSize; 
} Fee_ClusterGroupType;
/**
* @brief        Fee Configuration type is a stub type, not used, but required by ASR 4.2.2.
* @api
* @implements Fee_ConfigType_Struct
*/
typedef Fee_BlockConfigType Fee_ConfigType;
#ifdef __cplusplus
}
#endif

#endif /* FEE_TYPES_H */

/** @}*/
