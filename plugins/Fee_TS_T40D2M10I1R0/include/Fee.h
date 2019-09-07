/**
*   @file    Fee.h
*   @implements Fee.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Include File.
*   @details Include all external API declarations and definitions of
*            all pre-compile parameters.
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
#ifndef FEE_H
#define FEE_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR
* requirement MEMMAP003.
*
* @section Fee_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section Fee_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the 
* significance of more than 31 characters.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fee_Cfg.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_AR_RELEASE_MAJOR_VERSION     4
#define FEE_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Fee_h_REF_2 Identifier clash */
/* @violates @ref Fee_h_REF_3 Identifiers shall not rely*/
#define FEE_AR_RELEASE_REVISION_VERSION  2
#define FEE_SW_MAJOR_VERSION             1
#define FEE_SW_MINOR_VERSION             0
#define FEE_SW_PATCH_VERSION             1


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* AUTOSAR module vendor identification */
#define FEE_VENDOR_ID            43

/* AUTOSAR module identification */
#define FEE_MODULE_ID            21

/* AUTOSAR module instance identification */
#define FEE_INSTANCE_ID          0U

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fee configuration header file are of the same vendor */
#if (FEE_VENDOR_ID != FEE_VENDOR_ID_CFG)
    #error "Fee.h and Fee_Cfg.h have different vendor ids"
#endif
/* Check if current file and Fee configuration header file are of the same Autosar version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION    != FEE_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_MINOR_VERSION    != FEE_AR_RELEASE_MINOR_VERSION_CFG) || \
     (FEE_AR_RELEASE_REVISION_VERSION != FEE_AR_RELEASE_REVISION_VERSION_CFG)\
    )
    #error "AutoSar Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif
/* Check if current file and Fee configuration header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION != FEE_SW_MAJOR_VERSION_CFG) || \
     (FEE_SW_MINOR_VERSION != FEE_SW_MINOR_VERSION_CFG) || \
     (FEE_SW_PATCH_VERSION != FEE_SW_PATCH_VERSION_CFG)\
    )
    #error "Software Version Numbers of Fee.h and Fee_Cfg.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/



/**
* @brief        All service IDs (passed to DET)
*/
/** @implements Fee_interface */
#define FEE_INIT_ID                    0x00U
/** @implements Fee_interface */
#define FEE_SETMODE_ID                 0x01U
/** @implements Fee_interface */
#define FEE_READ_ID                    0x02U
/** @implements Fee_interface */
#define FEE_WRITE_ID                   0x03U
/** @implements Fee_interface */
#define FEE_CANCEL_ID                  0x04U
/** @implements Fee_interface */
#define FEE_GETSTATUS_ID               0x05U
/** @implements Fee_interface */
#define FEE_GETJOBRESULT_ID            0x06U
/** @implements Fee_interface */
#define FEE_INVALIDATEBLOCK_ID         0x07U
/** @implements Fee_interface */
#define FEE_GETVERSIONINFO_ID          0x08U
/** @implements Fee_interface */
#define FEE_ERASEIMMEDIATEBLOCK_ID     0x09U
/** @implements Fee_interface */
#define FEE_JOBENDNOTIFICATION_ID      0x10U
/** @implements Fee_interface */
#define FEE_JOBERRORNOTIFICATION_ID    0x11U
/** @implements Fee_interface */
#define FEE_MAINFUNCTION_ID            0x12U
/* Vendor specific API */
/** @implements Fee_interface */
#define FEE_GETRUNTIMEINFO_ID          0x13U
/** @implements Fee_interface */
#define FEE_FORCESWAPONNEXTWRITE_ID    0x14U


/**
* @brief        Development error codes (passed to DET)
*
*/
/** @brief API called when module was not initialized */
#define FEE_E_UNINIT                  0x01U
/** @brief API called with invalid block number */
#define FEE_E_INVALID_BLOCK_NO        0x02U
/** @brief API called with invalid block offset */
#define FEE_E_INVALID_BLOCK_OFS       0x03U
/** @brief API called with invalid data pointer */
#define FEE_E_PARAM_POINTER           0x04U
/** @brief API called with invalid length information */
#define FEE_E_INVALID_BLOCK_LEN       0x05U
/** @brief API called while module is busy processing a user request */
#define FEE_E_BUSY                    0x06U
/** @brief API called while module is busy doing internal management operations */
#define FEE_E_BUSY_INTERNAL           0x07U
/** @brief API called while module is not busy because there is no job to cancel */
#define FEE_E_INVALID_CANCEL          0x08U
/** @brief API Fee_init failed */
#define FEE_E_INIT_FAILED             0x09U
/* Vendor Specific Define */
/** @brief API called when underlying driver has cancel API disabled */
#define FEE_E_CANCEL_API              0x0AU
/** @brief API called with invalid cluster group index */
#define FEE_E_CLUSTER_GROUP_IDX       0x0BU
/** @brief API number of foreign blocks from data flash exceeds the total number
    of blocks allowed which is FEE_MAX_NR_OF_BLOCKS */
#define FEE_E_FOREIGN_BLOCKS_OVF      0x0CU


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define FEE_START_SEC_CODE
/* @violates @ref Fee_h_REF_1 Repeatedly included but does not have a standard include guard */
#include "Fee_MemMap.h"

extern FUNC( void, FEE_CODE ) Fee_Init(P2CONST( Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST ) paConfigPtr);


#if( FEE_SETMODE_API_SUPPORTED == STD_ON )
extern FUNC( void, FEE_CODE ) Fee_SetMode( VAR( MemIf_ModeType, AUTOMATIC ) eMode );
#endif /* FEE_SETMODE_API_SUPPORTED == STD_ON */

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_Read
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber,
        VAR( uint16, AUTOMATIC ) uBlockOffset,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pDataBufferPtr,
        VAR( uint16, AUTOMATIC ) uLength
    );

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_Write
   (
       VAR( uint16, AUTOMATIC ) uBlockNumber,
       P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pDataBufferPtr
   );

extern FUNC( void, FEE_CODE ) Fee_Cancel( void );

extern FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void );

extern FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void );

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber
    );

#if( FEE_VERSION_INFO_API == STD_ON )
extern FUNC( void, FEE_CODE ) Fee_GetVersionInfo
    (
        P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) pVersionInfoPtr
    );
#endif /* FEE_VERSION_INFO_API == STD_ON */

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber
    );

extern FUNC( void, FEE_CODE ) Fee_MainFunction( void );

extern FUNC( void, FEE_CODE ) Fee_GetRunTimeInfo
    (
        VAR( uint8, AUTOMATIC ) uClrGrpIndex,
        P2VAR( Fee_ClusterGroupRuntimeInfoType, AUTOMATIC,FEE_APPL_DATA ) pClrGrpRTInfo
    );

extern FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWrite
    (
        VAR( uint8, AUTOMATIC ) uClrGrpIndex
    );


#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_h_REF_1 Repeatedly included but does not have a standard include guard */
#include "Fee_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* FEE_H */
/** @} */
