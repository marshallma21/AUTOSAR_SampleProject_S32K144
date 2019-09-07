/**
*   @file    Fee.c
*   @implements Fee.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fee - Source Code.
*   @details Flash EEPROM emulation driver source code.
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
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* This violation is due to use of macros FEE_SERIALIZE and FEE_DESERIALIZE
* as functions.
*
* @section Fee_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* Repeatedly included but does not have a standard include guard due to AUTOSAR
* requirement MEMMAP003.
*
* @section Fee_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, declaration before #include.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Fee_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable.
* This violation is not applicable because all data are present in flash memory.
*
* @section Fee_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This violation is due to casting the unsigned char pointer to unsigned long
* pointer and access these addresses for updating contents of that address.
*
* @section Fee_c_REF_6
* Violates MISRA 2004 Required Rule 17.4,  Array indexing shall be the only
* allowed form of pointer arithmetic.
* This violation is due to the use of pointer arithmatic, which is used for the
* speed optimization, the indexing of the pointer is taken care and hence the
* unintended memory location will not be accessed.
*
* @section Fee_c_REF_7
* Violates MISRA 2004 Required Rule 11.5, attempt to cast away const/volatile
* from a pointer or reference.
* A cast shall not be performed that removes any const or volatile qualification
* from the type addressed by a pointer.
*
* @section Fee_c_REF_A
* Violates MISRA 2004 Required Rule 15.2, control flows into case/default.
* These are typically used when it simplifies the code.
*
* @section Fee_c_REF_12
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro
*
* @section Fee_c_REF_13
* Violates MISRA 2004 Required Rule 19.10, unparenthesized macro parameter in definition of macro
*
* @section Fee_c_REF_14
* Violates MISRA 2004 Required Rule 17.2, Pointer subtraction shall only be applied to pointers
* that address elements of the same array
* Violated in pointer comparisons (</<=)
*
* @section Fee_c_REF_15
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.

* @section Fee_c_REF_16
* Violates MISRA 2004 Required Rule 16.10, If a function returns error information, 
* then that error information shall be tested. 
* Det_ReportError function always return E_OK error code, so there is no reason to test it.
*
** @section Fee_c_REF_17
* Violates MISRA 2004 Required Rule 17.3, >,>=,<,<= shall not be applied to pointer type.
* The comparison is between memory addresses which point to the same object
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters due to
* AUTOSAR compatibility.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fee.h"
#include "Fee_InternalTypes.h"
#include "Fee_Cbk.h"
#include "SchM_Fee.h"
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif /* FEE_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_VENDOR_ID_C                      43
#define FEE_AR_RELEASE_MAJOR_VERSION_C       4
#define FEE_AR_RELEASE_MINOR_VERSION_C       2
#define FEE_AR_RELEASE_REVISION_VERSION_C    2
#define FEE_SW_MAJOR_VERSION_C               1
#define FEE_SW_MINOR_VERSION_C               0
#define FEE_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Fee header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_VENDOR_ID)
    #error "Fee.c and Fee.h have different vendor ids"
#endif
/* Check if current file and Fee header file are of the same AUTOSAR version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C    != FEE_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C    != FEE_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_AR_RELEASE_REVISION_VERSION)\
    )
        #error "AUTOSAR version numbers of Fee.c and Fee.h are different"
#endif
/* Check if source file and Fee header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_SW_PATCH_VERSION)\
    )
    #error "Software version numbers of Fee.c and Fee.h are different"
#endif

/* Check if source file and Fee_InternalTypes.h header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_INTERNALTYPES_VENDOR_ID)
    #error "Fee.c and Fee_InternalTypes.h have different vendor IDs"
#endif
/* Check if source file and Fee_InternalTypes.h header file are of the same AUTOSAR version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C !=    FEE_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C !=    FEE_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR version numbers of Fee.c and Fee_InternalTypes.h are different"
#endif
/* Check if source file and Fee_InternalTypes.h header file are of the same software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_INTERNALTYPES_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee.c and Fee_InternalTypes.h are different"
#endif

/* Check if source file and Fee_Cbk.h header file are of the same vendor */
#if (FEE_VENDOR_ID_C != FEE_CBK_VENDOR_ID)
    #error "Fee.c and Fee_Cbk.h have different vendor IDs"
#endif
/* Check if source file and Fee_Cbk.h header file are of the same AUTOSAR version */
#if ((FEE_AR_RELEASE_MAJOR_VERSION_C !=    FEE_CBK_AR_RELEASE_MAJOR_VERSION) || \
     (FEE_AR_RELEASE_MINOR_VERSION_C !=    FEE_CBK_AR_RELEASE_MINOR_VERSION) || \
     (FEE_AR_RELEASE_REVISION_VERSION_C != FEE_CBK_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR version numbers of Fee.c and Fee_Cbk.h are different"
#endif
/* Check if source file and Fee_Cbk.h header file are of the same Software version */
#if ((FEE_SW_MAJOR_VERSION_C != FEE_CBK_SW_MAJOR_VERSION) || \
     (FEE_SW_MINOR_VERSION_C != FEE_CBK_SW_MINOR_VERSION) || \
     (FEE_SW_PATCH_VERSION_C != FEE_CBK_SW_PATCH_VERSION) \
    )
    #error "Software version numbers of Fee.c and Fee_Cbk.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FEE_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FEE_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fee.c and Mcal.h are different"
    #endif
    #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /* Check if source file and DET header file are of the same version */
        #if ((FEE_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (FEE_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)\
            )
            #error "AutoSar Version Numbers of Fee.c and Det.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/**
* @brief          Serialize scalar parameter into the buffer
*
* @param[in]      ParamVal serialized parameter
* @param[in]      ParamType type of serialized parameter
* @param[in/out]  pSerialPtr pointer to target buffer
*
* @pre            pSerialPtr must be valid pointer
* @post           increments the pSerialPtr by sizeof(ParamType)
*
* @violates @ref Fee_c_REF_1 Function-like macro defined
*/
/* @violates @ref Fee_c_REF_12 Disallowed definition for macro */
/* @violates @ref Fee_c_REF_13 unparenthesized macro parameter in definition of macro */
#define FEE_SERIALIZE( ParamVal, ParamType, pSerialPtr ) \
    do \
    { \
        *((ParamType*)(pSerialPtr)) = (ParamVal); \
        (pSerialPtr) += sizeof(ParamType); \
    } while( 0 );

/**
* @brief          Deserialize scalar parameter from the buffer
*
* @param[in/out]  pDeserialPtr pointer to source buffer
* @param[out]     ParamVal deserialized parameter
* @param[int]     ParamType type of serialized parameter
*
* @pre            pDeserialPtr must be valid pointer
* @post           increments the pDeserialPtr by sizeof(ParamType)
*
* @violates @ref Fee_c_REF_1 Function-like macro defined
*/
/* @violates @ref Fee_c_REF_12 Disallowed definition for macro */
/* @violates @ref Fee_c_REF_13 unparenthesized macro parameter in definition of macro */
#define FEE_DESERIALIZE( pDeserialPtr, ParamVal, ParamType ) \
    do \
    { \
        (ParamVal) = *((ParamType*)(pDeserialPtr)); \
        (pDeserialPtr) += sizeof(ParamType); \
    } while( 0 );

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define FEE_START_SEC_VAR_INIT_8
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"
/**
* @brief        Pointer to user data buffer. Used by the read Fee jobs
*/
static P2VAR( uint8, FEE_VAR, FEE_APPL_DATA ) Fee_pJobReadDataDestPtr = NULL_PTR;
/**
* @brief        Pointer to user data buffer. Used by the write Fee jobs
*/
static P2CONST( uint8, FEE_CONST, FEE_APPL_CONST ) Fee_pJobWriteDataDestPtr = NULL_PTR;
/**
* @brief        Internal cluster group iterator. Used by the scan and swap jobs
*               Warning: do not use it outside scan and swap functions
*                        (because it will be Out of Range)
*/
static VAR(uint8, FEE_VAR) Fee_uJobIntClrGrpIt = (uint8)0;
/**
* @brief        Internal cluster iterator. Used by the scan and swap jobs
*/
static VAR(uint8, FEE_VAR) Fee_uJobIntClrIt = (uint8)0;

/**
* @brief        Data buffer used by all jobs to store immediate data
*/
static VAR(uint8, FEE_VAR) Fee_aDataBuffer[FEE_DATA_BUFFER_SIZE] = {(uint8)0};

#define FEE_STOP_SEC_VAR_INIT_8
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_16
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"
/**
* @brief        Fee block index. Used by all Fee jobs
*/
static VAR(uint16, FEE_VAR) Fee_uJobBlockIndex = 0U;
/**
* @brief        Internal block iterator. Used by the swap job
*/
static VAR(uint16, FEE_VAR) Fee_uJobIntBlockIt = 0U;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Used to keep the number of foreign blocks found when parsing the data flash.
*               It represents the number of elements from the Fee_aForeignBlockConfig array.
*/
static VAR(uint16, FEE_VAR) Fee_uForeignBlocksNumber = 0U;
#endif
#define FEE_STOP_SEC_VAR_INIT_16
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_INIT_32
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
/**
* @brief        Run-time information about blocks touching the Reserved Area
* @implements   Fee_aReservedAreaTouched_Object
*/
static VAR( uint32, FEE_VAR )
    Fee_aReservedAreaTouched[
                              (FEE_MAX_NR_OF_BLOCKS+((sizeof( uint32 )*8U)-1U)) /
                              (sizeof( uint32 )*8U)
                            ] = { 0UL }; 
#endif
#define FEE_STOP_SEC_VAR_INIT_32
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"


#define FEE_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"
/**
* @brief        Fee block offset. Used by the read Fee job
*/
static VAR(Fls_LengthType, FEE_VAR) Fee_uJobBlockOffset = 0UL;
/**
* @brief        Number of bytes to read. Used by the read Fee job
*/
static VAR(Fls_LengthType, FEE_VAR) Fee_uJobBlockLength = 0UL;
/**
* @brief        Internal flash helper address iterator. Used by the scan and
*               swap jobs
*/
static VAR(Fls_AddressType, FEE_VAR) Fee_uJobIntAddrIt = 0UL;
/**
* @brief        Internal address of current block header. Used by the swap job
*/
static VAR(Fls_AddressType, FEE_VAR) Fee_uJobIntHdrAddr = 0UL;
/**
* @brief        Internal address of current data block. Used by the swap job.
*/
static VAR(Fls_AddressType, FEE_VAR) Fee_uJobIntDataAddr = 0UL;
/**
* @brief        Internal state of Fee module
*/
static VAR(MemIf_StatusType, FEE_VAR) Fee_eModuleStatus = MEMIF_UNINIT;
/**
* @brief        Result of last Fee module job
*/
static VAR(MemIf_JobResultType, FEE_VAR) Fee_eJobResult = MEMIF_JOB_OK;
/**
* @brief        Currently executed job (including internal one)
*/
static VAR(Fee_JobType, FEE_VAR) Fee_eJob = FEE_JOB_DONE;
/**
* @brief        Fee job which started internal management job(s) such as swap...
*/
static VAR(Fee_JobType, FEE_VAR) Fee_eJobIntOriginalJob = FEE_JOB_DONE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
/**
* @brief        Used to keep the config of the foreign blocks
*/
static VAR(Fee_BlockConfigType, FEE_VAR) Fee_aForeignBlockConfig[FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS]={{0U}};
#endif
#define FEE_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

#define FEE_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

/**
* @brief        Run-time information of all configured Fee blocks. Contains
*               status, and data information. Used by all jobs
* @implements   Fee_aBlockInfo_Object
*/
static VAR(Fee_BlockInfoType, FEE_VAR) Fee_aBlockInfo[FEE_MAX_NR_OF_BLOCKS];
/**
* @brief        Run-time information of all configured cluster groups
*/
static VAR(Fee_ClusterGroupInfoType, FEE_VAR) Fee_aClrGrpInfo[FEE_NUMBER_OF_CLUSTER_GROUPS];
#define FEE_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"
/*==================================================================================================
*                                   GLOBAL FUNCTION DECLARATION
==================================================================================================*/
#define FEE_START_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

#if !defined(__DOXYGEN__)

/* Job end notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_END_NOTIFICATION_DECL

/* Job error notification routine provided by the upper layer module (declaration) */
FEE_NVM_JOB_ERROR_NOTIFICATION_DECL

/* Cluster format notification routine provided by the upper layer module (declaration) */
FEE_NVM_CLUSTER_FORMAT_NOTIFICATION_DECL

#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr
    (
        CONST( uint16, AUTOMATIC ) uBlockNumber,
        CONST( uint16, AUTOMATIC ) uLength,
        CONST( Fls_AddressType, AUTOMATIC) uTargetAddress,
        CONST( boolean, AUTOMATIC ) bImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        CONST( Fee_BlockAssignmentType, AUTOMATIC ) uBlockAssignment,
#endif
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pBlockHdrPtr
    );

static FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck
    (
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
        CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr
    );

static FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag
    (
        CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
        CONST( uint8, AUTOMATIC ) u8FlagPattern,
        P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pFlagValue
    );

static FUNC( Fee_BlockStatusType, FEE_CODE ) Fee_DeserializeBlockHdr
    (
        CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pBlockNumber,
        CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pLength,
        CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pTargetAddress,
        CONSTP2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        CONSTP2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) uBlockAssignment,
#endif
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pBlockHdrPtr
    );

static FUNC( Fee_ClusterStatusType, FEE_CODE ) Fee_DeserializeClusterHdr
    (
        CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) pClrID,
        CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pStartAddress,
        CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) pClusteSize,
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pClrHdrPtr
    );

static FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr
    (
        CONST( uint32, AUTOMATIC ) uClrID,
        CONST( Fls_AddressType, AUTOMATIC) uStartAddress,
        CONST( Fls_LengthType, AUTOMATIC) uClusteSize,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pClrHdrPtr
    );

static FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex
    (
        CONST( uint16, AUTOMATIC ) uBlockNumber
    );
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
static FUNC( uint16, FEE_CODE ) Fee_GetForeignBlockIndex
    ( 
        CONST( uint16, AUTOMATIC ) uBlockNumber 
    );   
LOCAL_INLINE FUNC( Fee_BlockAssignmentType, FEE_CODE ) Fee_GetBlockAssignment
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
#endif
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockNumber
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockSize
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
LOCAL_INLINE FUNC( uint8, FEE_CODE ) Fee_GetBlockClusterGrp
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
LOCAL_INLINE FUNC( boolean, FEE_CODE ) Fee_GetBlockImmediate
(
    CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex
);
static FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize
    (
        VAR( uint16, AUTOMATIC ) uBlockSize
    );

static FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer
    (
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pSourcePtr,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
        CONST( uint16, AUTOMATIC ) uLength
    );

static FUNC( void, FEE_CODE ) Fee_SerializeFlag
    (
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
        CONST( uint8, AUTOMATIC ) u8FlagPattern
    );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse
    (
        CONST( boolean, AUTOMATIC ) bBufferValid
    );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse
    (
        CONST( boolean, AUTOMATIC) bBufferValid
    );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead
    (
        CONST( boolean, AUTOMATIC) bBufferValid
    );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite
    (
        CONST( boolean, AUTOMATIC ) bBufferValid
    );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone( void );

static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void );

#if (FEE_LEGACY_MODE == STD_OFF)
    static FUNC( sint8, FEE_CODE ) Fee_ReservedAreaWritable( void );
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        static INLINE FUNC( sint8, FEE_CODE ) Fee_ReservedAreaTargetedInClrGrp
            (
                CONST( uint8, AUTOMATIC ) uClrGrpIndex
            );
        static INLINE FUNC( uint32, FEE_CODE ) Fee_PowerOf2Of5LSB
            (
                CONST( uint32, AUTOMATIC ) uInVal
            );
        static INLINE FUNC( sint8, FEE_CODE ) Fee_ReservedAreaTouchedByBlock
            (
                CONST( uint16, AUTOMATIC ) uBlockNumber
            );
        static INLINE FUNC( void, FEE_CODE ) Fee_TouchReservedAreaByBlock
            (
                CONST( uint16, AUTOMATIC ) uBlockNumber
            );
        static INLINE FUNC( void, FEE_CODE ) Fee_UntouchReservedAreaByClrGrp
            (
                CONST( uint8, AUTOMATIC ) uClrGrpIndex
            );
        static INLINE FUNC( void, FEE_CODE ) Fee_UntouchReservedAreaAll( void );
    #endif   /* FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON */
#endif  /* FEE_LEGACY_MODE == STD_OFF */

#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FEE_START_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

/**
* @brief   Returns the cluster group for a block specified by its index in the Fee_aBlockInfo array 
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array 
* @return         uint8
* @retval         cluster group number
* @pre            -
*/
LOCAL_INLINE FUNC( uint8, FEE_CODE ) Fee_GetBlockClusterGrp(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
    uint8 uBlockClusterGrp = 0U;
    
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (uBlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        uBlockClusterGrp = Fee_BlockConfig[uBlockRuntimeInfoIndex].clrGrp;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        uBlockClusterGrp = Fee_aForeignBlockConfig[uBlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].clrGrp;
    }
    #else        
    /* the config is part of Fee_BlockConfig*/
        uBlockClusterGrp = Fee_BlockConfig[uBlockRuntimeInfoIndex].clrGrp;
    #endif
    
    return uBlockClusterGrp;
} 

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
/**
* @brief Checks whether the area specified by Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt
*              and Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt touches the Reserved Area.
* @param[in] uClrGrpIndex - Cluster Group Index
* @return sint8
* @retval TRUE The Reserved Area is touched.
* @retval FALSE The Reserved Area is not touched.
*
* @pre Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt must be up to date
* @pre Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt must be up to date
*
* @implements   Fee_ReservedAreaTargetedInClrGrp_Activity
*
*/
static INLINE FUNC( sint8, FEE_CODE )  Fee_ReservedAreaTargetedInClrGrp
    (
        CONST( uint8, AUTOMATIC ) uClrGrpIndex
    )
{
    VAR( sint8, AUTOMATIC ) sRetVal = FALSE;
    VAR( Fls_LengthType, AUTOMATIC ) uAvailClrSpace = 0UL;
    VAR( uint32, AUTOMATIC ) uReservedSpace = 0UL;

        /* Reserved space of cluster group*/
    uReservedSpace = Fee_ClrGrps[ uClrGrpIndex ].reservedSize;

    /* Calculate available space in active cluster */
    uAvailClrSpace = Fee_aClrGrpInfo[ uClrGrpIndex ].uDataAddrIt -
                     Fee_aClrGrpInfo[ uClrGrpIndex ].uHdrAddrIt;

    if( (FEE_BLOCK_OVERHEAD  + uReservedSpace) > uAvailClrSpace )
    {
        sRetVal = TRUE;
    }

    return sRetVal;
}

/**
* @brief Function to compute the power of 2 out of the 5 LSB bits of uInVal value.
* @return uint32
* @retval Power of 2 computed out of the 5 LSB bits of uInVal value.
*
* @param[in] uInVal - value out of which 5 LSB bits is taken as an input for the
*                     power of 2 computation
*
* @implements   Fee_PowerOf2Of5LSB_Activity
*
*/
static INLINE FUNC( uint32, FEE_CODE ) Fee_PowerOf2Of5LSB( CONST( uint32, AUTOMATIC ) uInVal )
{
    return (uint32)(0x00000001UL << (uInVal & 0x1FUL));
}

/**
* @brief Returns the information about touching the Reserved Area by the block
*         specified by uBlockuNumber.
* @return sint8
* @retval TRUE - the Reserved Area is touched by the block
* @retval FALSE - the Reserved Area is not touched by the block
*
* @param[in] uBlockNumber - number of the block under request
*
* @implements   Fee_ReservedAreaTouchedByBlock_Activity
*
*/
static INLINE FUNC( sint8, FEE_CODE ) Fee_ReservedAreaTouchedByBlock
    (
        CONST( uint16, AUTOMATIC ) uBlockNumber
    )
{
     VAR( uint32, AUTOMATIC ) uIdx = 0UL;
     VAR( sint8, AUTOMATIC ) sRetVal;

     uIdx = ((uint32)uBlockNumber) >> 5U;

     if( 0U != (Fee_aReservedAreaTouched[ uIdx ] & Fee_PowerOf2Of5LSB( (uint32)uBlockNumber )) )
     {
         sRetVal = TRUE;
     }
     else
     {
         sRetVal = FALSE;
     }
     return sRetVal;
}

/**
* @brief Stores the information about touching the Reserved Area for the block
*           specified by uBlockNumber.
* @return void
*
* @param[in] uBlockNumber - number of the block touching the Reserved Area
*
* @implements   Fee_TouchReservedAreaByBlock_Activity
*
*/
static INLINE FUNC( void, FEE_CODE ) Fee_TouchReservedAreaByBlock
    (
        CONST( uint16, AUTOMATIC ) uBlockNumber
    )
{
     VAR( uint32, AUTOMATIC ) uIdx = 0UL;

     uIdx = ((uint32)uBlockNumber) >> 5U;

     Fee_aReservedAreaTouched[ uIdx ] |= Fee_PowerOf2Of5LSB( (uint32)uBlockNumber );
}

/**
* @brief Removes the information about touching the Reserved Area for all blocks
*           within a cluster group specified by uClrGrpIndex.
* @return void
*
* @param[in] uClrGrpIndex - see above
*
* @implements   Fee_UntouchReservedAreaByClrGrp_Activity
*
*/
static INLINE FUNC( void, FEE_CODE ) Fee_UntouchReservedAreaByClrGrp
    (
        CONST( uint8, AUTOMATIC ) uClrGrpIndex
    )
{
    VAR( uint32, AUTOMATIC ) uBlockIt = 0UL;
    VAR( uint32, AUTOMATIC ) uIdx = 0UL;
    VAR( uint32, AUTOMATIC ) uMask = 0x00000001UL;
    VAR( uint8, AUTOMATIC ) uBlockClusterGrp = 0U;
    
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
   for( uBlockIt = 0U; uBlockIt < ((uint32)FEE_CRT_CFG_NR_OF_BLOCKS + (uint32)Fee_uForeignBlocksNumber); uBlockIt++ )
#else
   for( uBlockIt = 0U; uBlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; uBlockIt++ )
#endif
    {
        
        uBlockClusterGrp = Fee_GetBlockClusterGrp((uint16)uBlockIt);
        
       if(uClrGrpIndex == uBlockClusterGrp)
       {
           Fee_aReservedAreaTouched[uIdx] &= (~uMask);
       }
       if (0x80000000UL == uMask)
       {
           uMask = 0x00000001UL;
           uIdx++;
       }
       else
       {
           uMask = uMask << 1U;
       }
    }
}

/**
* @brief Removes information about touching the Reserved Area globally for all blocks.
* @return void
*
* @implements   Fee_UntouchReservedAreaAll_Activity
*
*/
static INLINE FUNC( void, FEE_CODE ) Fee_UntouchReservedAreaAll( void )
{
    VAR( uint32, AUTOMATIC ) uIdx;
    
    for( uIdx = 0UL;
         uIdx < (sizeof( Fee_aReservedAreaTouched )/sizeof( *Fee_aReservedAreaTouched ));
         uIdx++
       )
    {
        Fee_aReservedAreaTouched[ uIdx ] = 0x00000000UL;
    }
}
#endif /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF) */







    
/**
* @brief        Serialize Fee block parameters into a write buffer
*
* @param[in]    uBlockNumber     Fee block number
* @param[in]    uLength          Size of Fee block in bytes
* @param[in]    uTargetAddress   Logical address of Fee block in Fls adress
*                                space
* @param[in]    bImmediateBlock  Type of Fee block. Set to TRUE for immediate
*                                block
* @param[out]   pBlockHdrPtr     Pointer to serialization buffer
*
* @pre          pBlockHdrPtr must be valid pointer
*
*/
static FUNC( void, FEE_CODE ) Fee_SerializeBlockHdr
    (
        CONST( uint16, AUTOMATIC ) uBlockNumber,
        CONST( uint16, AUTOMATIC ) uLength,
        CONST( Fls_AddressType, AUTOMATIC) uTargetAddress,
        CONST( boolean, AUTOMATIC ) bImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        CONST( Fee_BlockAssignmentType, AUTOMATIC ) uBlockAssignment,
#endif
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pBlockHdrPtr
    )
{
    VAR( uint32, AUTOMATIC ) u32checkSum = 0UL;
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = NULL_PTR;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    pTargetEndPtr = pBlockHdrPtr + FEE_BLOCK_OVERHEAD;

    /* Calculate the block header checksum */
    u32checkSum = ((uint32) uBlockNumber) + ((uint32) uLength) + uTargetAddress;

    /* Use MSB of the checksum for the immediate block flag so
       the checksum is 31-bit */
    if( bImmediateBlock )
    {
        u32checkSum += 1U;
        u32checkSum |= 0x80000000U;
    }
    else
    {
        u32checkSum &= 0x7fffffffU;
    }

    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( uBlockNumber, uint16, pBlockHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( uLength, uint16, pBlockHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( uTargetAddress, Fls_AddressType, pBlockHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( u32checkSum, uint32, pBlockHdrPtr )
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( (uint8)uBlockAssignment, uint8, pBlockHdrPtr  )
#endif
    /* Fill rest of the header with the erase pattern */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_14 Pointer subtraction */
    /* @violates @ref Fee_c_REF_17 Pointer comparison */
    for( ; pBlockHdrPtr < pTargetEndPtr; pBlockHdrPtr++ )
    {
        *pBlockHdrPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief          Check whether specified data buffer contains only
*                 the FEE_ERASED_VALUE value
*
* @param[in]      pTargetPtr     pointer to start of the checked buffer
* @param[in]      pTargetEndPtr  pointer to end + 1 of the checked buffer
*
* @return         Std_ReturnType
* @retval         E_OK           The buffer contains only erased value
* @retval         E_NOT_OK       The buffer doesn't contain only erased value
*
* @pre            pTargetPtr and pTargetEndPtr pointers must be valid
*
*/
static FUNC( Std_ReturnType, FEE_CODE ) Fee_BlankCheck
    (
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
        CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr
    )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_14 Pointer subtraction */
    /* @violates @ref Fee_c_REF_17 Pointer comparison */
    for( ; pTargetPtr < pTargetEndPtr; pTargetPtr++ )
    {
        if( FEE_ERASED_VALUE == *pTargetPtr )
        {
            /* Pattern match */
        }
        else
        {
            uRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }

    return( uRetVal );
}

/**
* @brief        Deserialize the valid or invalid flag from a read buffer
*
* @param[in]    pTargetPtr       Pointer to the read buffer
* @param[in]    u8FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
* @param[out]   pFlagValue        TRUE if flag of above type is set
*
* @return       Std_ReturnType
* @retval       E_OK             The flag is set or cleared and rest of the read buffer
*                               (FEE_VIRTUAL_PAGE_SIZE - 1) contains FEE_ERASED_VALUE
* @retval       E_NOT_OK         Buffer doesn't contain valid flag data. It's garbled...
*
* @pre          pTargetPtr and pFlagValue pointers must be valid
*
*/
static FUNC( Std_ReturnType, FEE_CODE ) Fee_DeserializeFlag
    (
        CONSTP2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetPtr,
        CONST( uint8, AUTOMATIC ) u8FlagPattern,
        P2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pFlagValue
    )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;

    if( (u8FlagPattern == *pTargetPtr) || ( FEE_ERASED_VALUE == *pTargetPtr ))
    {
        /* The bytePattern can be either present or not */
        if( u8FlagPattern == *pTargetPtr )
        {
            *pFlagValue = (boolean)TRUE;
        }
        else
        {
            *pFlagValue = (boolean)FALSE;
        }

        /* Check rest of the FEE_VIRTUAL_PAGE_SIZE */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        uRetVal = Fee_BlankCheck( pTargetPtr+1, pTargetPtr+FEE_VIRTUAL_PAGE_SIZE );
    }
    else
    {
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }

    return( uRetVal );
}

/**
* @brief        Deserialize Fee block header parameters from read buffer
*
* @param[out]   pBlockNumber             Fee block number
* @param[out]   pLength                  Size of Fee block in bytes
* @param[out]   pTargetAddress           Logical address of Fee block in Fls adress space
* @param[out]   pImmediateBlock          Type of Fee block. Set to TRUE for immediate block
* @param[in]    pBlockHdrPtr             Pointer to read buffer
*
* @return       Fee_BlockStatusType
* @retval       FEE_BLOCK_VALID          Fee block is valid
* @retval       FEE_BLOCK_INVALID        Fee block is invalid (has been invalidated)
* @retval       FEE_BLOCK_INCONSISTENT   Fee block is inconsistent, it may contain corrupted data...
* @retval       FEE_BLOCK_HEADER_INVALID Fee block header is invalid (garbled)
* @retval       FEE_BLOCK_HEADER_BLANK   Fee block header is filled with FEE_ERASED_VALUE
*
* @pre          pBlockHdrPtr             pointer must be valid
*
*/
static FUNC( Fee_BlockStatusType, FEE_CODE ) Fee_DeserializeBlockHdr
    (
        CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pBlockNumber,
        CONSTP2VAR( uint16, AUTOMATIC, FEE_APPL_DATA ) pLength,
        CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pTargetAddress,
        CONSTP2VAR( boolean, AUTOMATIC, FEE_APPL_DATA ) pImmediateBlock,
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        CONSTP2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) uBlockAssignment,
#endif
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pBlockHdrPtr
    )
{
    VAR( Fee_BlockStatusType, AUTOMATIC ) eRetVal = FEE_BLOCK_HEADER_INVALID;
    VAR( uint32, AUTOMATIC ) u32ReadCheckSum = 0UL;
    VAR( uint32, AUTOMATIC ) u32CalcCheckSum = 0UL;
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr = NULL_PTR;
    VAR( boolean, AUTOMATIC ) bFlagValid = (boolean)FALSE;
    VAR( boolean, AUTOMATIC ) bFlagInvalid = (boolean)FALSE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_OFF) 
    VAR( uint8, AUTOMATIC ) u8ReservedSpace = 0U;
#endif

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    if( Fee_BlankCheck( pBlockHdrPtr, pBlockHdrPtr+FEE_BLOCK_OVERHEAD ) == ((Std_ReturnType)E_OK) )
    {
        eRetVal = FEE_BLOCK_HEADER_BLANK;
    }
    else
    {
        /* Check 1st part of the header */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        pTargetEndPtr = (pBlockHdrPtr + FEE_BLOCK_OVERHEAD) - (2U * FEE_VIRTUAL_PAGE_SIZE);

        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
           or reference. */
        FEE_DESERIALIZE( pBlockHdrPtr, *pBlockNumber, uint16 )
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
           or reference. */
        FEE_DESERIALIZE( pBlockHdrPtr, *pLength, uint16 )
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
           or reference. */
        FEE_DESERIALIZE( pBlockHdrPtr, *pTargetAddress, Fls_AddressType )
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
           or reference. */
        FEE_DESERIALIZE( pBlockHdrPtr, u32ReadCheckSum, uint32 )
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
           or reference. */
        FEE_DESERIALIZE( pBlockHdrPtr, *uBlockAssignment, uint8 )
#else
        /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
           or reference. */
         /* pBlockHdrPtr must be advanced with 1 bytes. 
          * the reason is to avoid blank check for this area reserved for blockAssignment even when 
          * SWAP_FOREIGN is disabled to allow disabling SWAP_FOREIGN at production time. */
        FEE_DESERIALIZE( pBlockHdrPtr, u8ReservedSpace, uint8)
        /* variable u8ReservedSpace not used */
        (void)u8ReservedSpace;
#endif
        /* Use MSB of checksum for immediate block flag so
            the checksum is 31-bit long */
        u32CalcCheckSum = *pLength + *pTargetAddress + *pBlockNumber;

        if( 0U == (u32ReadCheckSum & 0x80000000U) )
        {
            *pImmediateBlock = (boolean)FALSE;
        }
        else
        {
            *pImmediateBlock = (boolean)TRUE;
            u32CalcCheckSum += 1U;
        }

        /* Ignore MSB since it's used for ImmediateBlock flag */
        if( (u32ReadCheckSum & 0x7fffffffU) != (u32CalcCheckSum & 0x7fffffffU) )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }
        else if( ((Std_ReturnType)E_OK) != Fee_BlankCheck( pBlockHdrPtr, pTargetEndPtr ) )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }
        else if( ((Std_ReturnType)E_OK) !=
                 /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
                 /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
                    allowed form of pointer arithmetic. */
                 Fee_DeserializeFlag( pTargetEndPtr, FEE_VALIDATED_VALUE, &bFlagValid )
               )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }
        else if( ((Std_ReturnType)E_OK) !=
                 /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
                    allowed form of pointer arithmetic. */
                 Fee_DeserializeFlag( pTargetEndPtr+FEE_VIRTUAL_PAGE_SIZE,
                                      /* @violates @ref Fee_c_REF_4 Taking address of near
                                         auto variable. */
                                      FEE_INVALIDATED_VALUE, &bFlagInvalid \
                                    )
               )
        {
            /* FEE_BLOCK_HEADER_INVALID */
        }
        else
        {
            /* Block header is valid */
            if( ((boolean)FALSE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
            {
                eRetVal = FEE_BLOCK_INCONSISTENT;
            }
            else if( ((boolean)TRUE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
            {
                eRetVal = FEE_BLOCK_VALID;
            }
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            else if( ((boolean)TRUE == bFlagValid) && ((boolean)TRUE == bFlagInvalid) )
            {
                eRetVal = FEE_BLOCK_INVALIDATED;
            }
#endif
            else
            {
                eRetVal = FEE_BLOCK_INVALID;
            }
        }
    }

    return( eRetVal );
}

/**
* @brief        Deserialize Fee cluster header parameters from read buffer
*
* @param[out]   pClrID                     32-bit cluster ID
* @param[out]   pStartAddress              Logical address of Fee cluster in Fls address space
* @param[out]   pClusteSize                Size of Fee cluster in bytes
* @param[in]    pClrHdrPtr                 Pointer to read buffer
*
* @return       Fee_ClusterStatusType
* @retval       FEE_CLUSTER_VALID          Fee cluster is valid
* @retval       FEE_CLUSTER_INVALID        Fee cluster has been invalidated
* @retval       FEE_CLUSTER_INCONSISTENT   Fee cluster is inconsistent, it may
*                                          contain corrupted data
* @retval       FEE_CLUSTER_HEADER_INVALID Fee cluster header is invalid (garbled)
*
* @pre          pClrHdrPtr pointer must be valid
*
*/
static FUNC( Fee_ClusterStatusType, FEE_CODE ) Fee_DeserializeClusterHdr
    (
        CONSTP2VAR( uint32, AUTOMATIC, FEE_APPL_DATA ) pClrID,
        CONSTP2VAR( Fls_AddressType, AUTOMATIC, FEE_APPL_DATA ) pStartAddress,
        CONSTP2VAR( Fls_LengthType, AUTOMATIC, FEE_APPL_DATA ) pClusteSize,
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pClrHdrPtr
    )
{
    VAR( Fee_ClusterStatusType, AUTOMATIC ) eRetVal = FEE_CLUSTER_HEADER_INVALID;
    VAR( uint32, AUTOMATIC ) u32CheckSum = 0UL;
    VAR( boolean, AUTOMATIC ) bFlagValid = (boolean)FALSE;
    VAR( boolean, AUTOMATIC ) bFlagInvalid = (boolean)FALSE;
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pTargetEndPtr = NULL_PTR;

    /* Check 1st part of the header */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    pTargetEndPtr = (pClrHdrPtr + FEE_CLUSTER_OVERHEAD) - (2U * FEE_VIRTUAL_PAGE_SIZE);

    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
       or reference. */
    FEE_DESERIALIZE( pClrHdrPtr, *pClrID, uint32 )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
       or reference. */
    FEE_DESERIALIZE( pClrHdrPtr, *pStartAddress, Fls_AddressType )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
       or reference. */
    FEE_DESERIALIZE( pClrHdrPtr, *pClusteSize, Fls_LengthType )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_7 attempt to cast away const/volatile from a pointer
       or reference. */
    FEE_DESERIALIZE( pClrHdrPtr, u32CheckSum, uint32 )

    if( (*pClrID+*pStartAddress+*pClusteSize) != u32CheckSum )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else if( ((Std_ReturnType)E_OK) != Fee_BlankCheck( pClrHdrPtr, pTargetEndPtr ) )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else if( ((Std_ReturnType)E_OK) !=
             /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
             /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
                allowed form of pointer arithmetic. */
             Fee_DeserializeFlag( pTargetEndPtr, FEE_VALIDATED_VALUE, &bFlagValid )
           )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else if( ((Std_ReturnType)E_OK) !=
             /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
                allowed form of pointer arithmetic. */
             Fee_DeserializeFlag( pTargetEndPtr+FEE_VIRTUAL_PAGE_SIZE,
                                  /* @violates @ref Fee_c_REF_4 Taking address of
                                     near auto variable. */
                                  FEE_INVALIDATED_VALUE, &bFlagInvalid \
                                )
           )
    {
        /* FEE_CLUSTER_HEADER_INVALID */
    }
    else
    {
        if( ((boolean)FALSE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
        {
            eRetVal = FEE_CLUSTER_INCONSISTENT;
        }
        if( ((boolean)TRUE == bFlagValid) && ((boolean)FALSE == bFlagInvalid) )
        {
            eRetVal = FEE_CLUSTER_VALID;
        }
        else
        {
            eRetVal = FEE_CLUSTER_INVALID;
        }
    }

    return( eRetVal );
}

/**
* @brief        Serialize        Fee cluster header parameters to write buffer
*
* @param[in]    uClrID           32-bit cluster ID
* @param[in]    uStartAddress    Logical address of Fee cluster in Fls address space
* @param[in]    uClusteSize      Size of Fee cluster in bytes
* @param[out]   pClrHdrPtr       Pointer to write buffer
*
* @pre          pClrHdrPtr       pointer must be valid
*
*/
static FUNC( void, FEE_CODE ) Fee_SerializeClusterHdr
    (
        CONST( uint32, AUTOMATIC ) uClrID,
        CONST( Fls_AddressType, AUTOMATIC) uStartAddress,
        CONST( Fls_LengthType, AUTOMATIC) uClusteSize,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pClrHdrPtr
    )
{
    VAR( uint32, AUTOMATIC ) u32CheckSum = 0UL;
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = NULL_PTR;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    pTargetEndPtr = pClrHdrPtr + FEE_CLUSTER_OVERHEAD;

    /* Calculate the cluster header checksum */
    u32CheckSum = uClrID + uStartAddress + uClusteSize;

    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( uClrID, uint32, pClrHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( uStartAddress, Fls_AddressType, pClrHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( uClusteSize, Fls_LengthType, pClrHdrPtr )
    /* @violates @ref Fee_c_REF_5 Cast from pointer to pointer. */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    FEE_SERIALIZE( u32CheckSum, uint32, pClrHdrPtr )

    /* Fill rest of the header with the erase pattern */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_14 Pointer subtraction */
    /* @violates @ref Fee_c_REF_17 Pointer comparison */
    for( ; pClrHdrPtr < pTargetEndPtr; pClrHdrPtr++ )
    {
        *pClrHdrPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    uBlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if uBlockNumber is invalid
*
*/
static FUNC( uint16, FEE_CODE ) Fee_GetBlockIndex( CONST( uint16, AUTOMATIC ) uBlockNumber )
{
    VAR( sint32, AUTOMATIC ) sLow = 0L;
    VAR( sint32, AUTOMATIC ) sHigh = (sint32)FEE_CRT_CFG_NR_OF_BLOCKS - 1;
    VAR( sint32, AUTOMATIC ) sMiddle = 0;
    VAR( uint16, AUTOMATIC ) uRetVal = 0xFFFFU;

    while( sLow <= sHigh )
    {
        sMiddle = sLow + (( sHigh - sLow ) / 2);

        if( uBlockNumber < Fee_BlockConfig[sMiddle].blockNumber )
        {
            sHigh = sMiddle - 1;
        }
        else if( uBlockNumber > Fee_BlockConfig[sMiddle].blockNumber )
        {
            sLow = sMiddle + 1;
        }
        else
        {
            uRetVal = (uint16)sMiddle;
            break;
        }
    }

    return( uRetVal );
}
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
/**
* @brief        Searches ordered list of Fee blocks and returns index of block
*               with matching BlockNumber
*
* @param[in]    uBlockNumber             Fee block number (FeeBlockNumber)
*
* @return       uint16
* @retval       Fee block index
* @retval       0xFFFF if uBlockNumber is invalid
*
*/
static FUNC( uint16, FEE_CODE ) Fee_GetForeignBlockIndex( CONST( uint16, AUTOMATIC ) uBlockNumber )
{
    VAR( uint16, AUTOMATIC ) uForeignBlockIt = 0U;
    VAR( uint16, AUTOMATIC ) uRetVal = 0xFFFFU;
    
    if (Fee_uForeignBlocksNumber >= 1UL)
    {
        for(uForeignBlockIt = 0U; uForeignBlockIt < Fee_uForeignBlocksNumber; uForeignBlockIt++)
        {
            if(uBlockNumber == Fee_aForeignBlockConfig[uForeignBlockIt].blockNumber)
            {
                uRetVal = uForeignBlockIt;
                break;
            }
        }
    }
    
    return( uRetVal );
}
/**
* @brief  Returns the block project assignement for a block specified by its index in the Fee_aBlockInfo array 
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array 
* @return         Fee_BlockAssignmentType
* @retval         FEE_PROJECT_SHARED
* @retval         FEE_PROJECT_APPLICATION
* @retval         FEE_PROJECT_BOOTLOADER
* @retval         FEE_PROJECT_RESERVED
* @pre            -
*/
LOCAL_INLINE FUNC( Fee_BlockAssignmentType, FEE_CODE ) Fee_GetBlockAssignment(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
    Fee_BlockAssignmentType uBlockAssignment = FEE_PROJECT_RESERVED;
    
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (uBlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        uBlockAssignment = Fee_BlockConfig[uBlockRuntimeInfoIndex].blockAssignment;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        uBlockAssignment = Fee_aForeignBlockConfig[uBlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].blockAssignment;
    }
    #else        
    /* the config is part of Fee_BlockConfig*/
        uBlockAssignment = Fee_BlockConfig[uBlockRuntimeInfoIndex].blockAssignment;
    #endif
    
    return uBlockAssignment;
}
#endif


/**
* @brief  Returns the block size for a block specified by its index in the Fee_aBlockInfo array 
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array 
* @return         uint16
* @retval         block size
* @pre            -
*/
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockSize(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
    uint16 uBlockSize = 0U;
    
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (uBlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        uBlockSize = Fee_BlockConfig[uBlockRuntimeInfoIndex].blockSize;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        uBlockSize = Fee_aForeignBlockConfig[uBlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].blockSize;
    }
    #else        
    /* the config is part of Fee_BlockConfig*/
        uBlockSize = Fee_BlockConfig[uBlockRuntimeInfoIndex].blockSize;
    #endif
    
    return uBlockSize;
}  
/**
* @brief  Returns the block number for a block specified by its index in the Fee_aBlockInfo array 
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array 
* @return         uint16
* @retval         block number
* @pre            -
*/
LOCAL_INLINE FUNC( uint16, FEE_CODE ) Fee_GetBlockNumber(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
    uint16 uBlockNumber = 0U;
    
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (uBlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        uBlockNumber = Fee_BlockConfig[uBlockRuntimeInfoIndex].blockNumber;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        uBlockNumber = Fee_aForeignBlockConfig[uBlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].blockNumber;
    }
    #else        
    /* the config is part of Fee_BlockConfig*/
        uBlockNumber = Fee_BlockConfig[uBlockRuntimeInfoIndex].blockNumber;
    #endif
    
    return uBlockNumber;
}
/**
* @brief  Returns the immediate attribute for a block specified by its index in the Fee_aBlockInfo array 
*
* @param[in]      uBlockRuntimeInfoIndex     index in the Fee_aBlockInfo array 
* @return         boolean
* @retval         value of the immediate attribute
* @pre            -
*/
LOCAL_INLINE FUNC( boolean, FEE_CODE ) Fee_GetBlockImmediate(CONST( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex)
{
    boolean bImmediate = (boolean)FALSE;
    
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if (uBlockRuntimeInfoIndex < FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        /* this means block is not foreign, so the config is part of Fee_BlockConfig*/
        bImmediate = Fee_BlockConfig[uBlockRuntimeInfoIndex].immediateData;
    }
    else
    {
        /* this means block is foreign, so the config is part of Fee_aForeignBlockConfig*/
        bImmediate = Fee_aForeignBlockConfig[uBlockRuntimeInfoIndex-FEE_CRT_CFG_NR_OF_BLOCKS].immediateData;
    }
    #else        
        /* the config is part of Fee_BlockConfig*/
        bImmediate = Fee_BlockConfig[uBlockRuntimeInfoIndex].immediateData;
    #endif
    
    return bImmediate;
}
/**
* @brief        Adjusts passed size so it's integer multiple of pre-configured +
*               FEE_VIRTUAL_PAGE_SIZE
*
* @param[in]    uBlockSize        Fee block size (FeeBlockSize)
*
* @return       uint16
* @retval       Adjusted         Fee block size to integer multiple    of FEE_VIRTUAL_PAGE_SIZE
*
*/
static FUNC( uint16, FEE_CODE ) Fee_AlignToVirtualPageSize( VAR( uint16, AUTOMATIC ) uBlockSize )
{
    /* Check whether the block size is integer multiple
        of FEE_VIRTUAL_PAGE_SIZE */
    if( 0U == (uBlockSize % FEE_VIRTUAL_PAGE_SIZE) )
    {
        /* block size is an integer multiple of FEE_VIRTUAL_PAGE_SIZE */
    }
    else
    {
        uBlockSize = ((uBlockSize / FEE_VIRTUAL_PAGE_SIZE) + 1U) *
                         FEE_VIRTUAL_PAGE_SIZE;
    }

    return( (uint16)uBlockSize );
}

/**
* @brief        Copy data from user to internal write buffer and fills
*               rest of the write buffer with FEE_ERASED_VALUE
*
* @param[in]    pSourcePtr        Pointer to user data buffer
* @param[out]   pTargetPtr        Pointer to internal write buffer
* @param[in]    uLength           Number of bytes to copy
*
* @pre          pSourcePtr and pTargetPtr must be valid pointers
* @pre          uLength must be <= FEE_VIRTUAL_PAGE_SIZE
*
*/
static FUNC( void, FEE_CODE ) Fee_CopyDataToPageBuffer
    (
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pSourcePtr,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
        CONST( uint16, AUTOMATIC ) uLength
    )
{
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = pTargetPtr + uLength;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pPageEndPtr = pTargetPtr + FEE_VIRTUAL_PAGE_SIZE;

    /* Copy data to page buffer */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_14 Pointer subtraction */
    /* @violates @ref Fee_c_REF_17 Pointer comparison */
    for( ; pTargetPtr < pTargetEndPtr; pTargetPtr++ )
    {
        *pTargetPtr = *pSourcePtr;
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        pSourcePtr++;
    }

    /* Fill rest of the page buffer with FEE_ERASED_VALUE */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_14 Pointer subtraction */
    /* @violates @ref Fee_c_REF_17 Pointer comparison */
    for( ; pTargetPtr < pPageEndPtr; pTargetPtr++ )
    {
        *pTargetPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Serialize validation or invalidation flag to write buffer
*
* @param[out]   pTargetPtr       Pointer to write buffer
* @param[in]    u8FlagPattern    FEE_VALIDATED_VALUE or FEE_INVALIDATED_VALUE
*
* @pre          pTargetPtr        must be valid pointer
*
*/
static FUNC( void, FEE_CODE ) Fee_SerializeFlag
    (
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetPtr,
        CONST( uint8, AUTOMATIC ) u8FlagPattern
    )
{
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pTargetEndPtr = pTargetPtr + FEE_VIRTUAL_PAGE_SIZE;

    *pTargetPtr = u8FlagPattern;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    /* @violates @ref Fee_c_REF_14 Pointer subtraction */
    /* @violates @ref Fee_c_REF_17 Pointer comparison */
    for( pTargetPtr++ ; pTargetPtr < pTargetEndPtr; pTargetPtr++ )
    {
        *pTargetPtr = FEE_ERASED_VALUE;
    }
}

/**
* @brief        Validate current Fee cluster in current Fee cluster group by
*               writing FEE_VALIDATED_VALUE into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current cluster group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVld( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;

    /* Get start address of swap cluster */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;

    /* Serialize validation pattern to write buffer */
    Fee_SerializeFlag( Fee_aDataBuffer, FEE_VALIDATED_VALUE );

    /* Write validation pattern to flash */
    if( ((Std_ReturnType)E_OK) ==
            Fls_Write( (uStartAddr+FEE_CLUSTER_OVERHEAD )-(2U*FEE_VIRTUAL_PAGE_SIZE),
                       Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE
                     )
      )
    {
        /* Fls write job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule subsequent Fee job */
    Fee_eJob = FEE_JOB_INT_SWAP_CLR_VLD_DONE;

    return( eRetVal );
}

/**
* @brief        Copy next block from source to target cluster
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the write job
*
* @pre          Fee_uJobIntBlockIt       must contain index of currently swaped
*                                        Fee block
* @pre          Fee_uJobBlockIndex       must contain index of Fee block which
*                                        caused the swap
* @pre          Fee_uJobIntClrGrpIt       must contain index of current cluster
*                                        group
* @pre          Fee_uJobIntHdrAddr       must contain valid address of Fee block
*                                        header in target cluster
*
* @post         Fee_uJobIntHdrAddr is advanced on to next Fee block
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ, FEE_JOB_INT_SWAP_BLOCK,
* or            FEE_JOB_INT_SWAP_CLR_VLD_DONE subsequent job
*
* @implements   Fee_JobIntSwapBlock_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlock( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0UL;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uBlockNumber = 0U;
    VAR( uint8, AUTOMATIC ) uBlockClusterGrp = 0U;
    VAR( boolean, AUTOMATIC ) bImmediateBlock = (boolean)FALSE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    VAR( Fee_BlockAssignmentType, AUTOMATIC ) uBlockAssignment = FEE_PROJECT_RESERVED;
#endif
    
    /* Find first valid or inconsistent block in same cluster group */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    for( ; Fee_uJobIntBlockIt < (FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber); Fee_uJobIntBlockIt++ )
#else
    for( ; Fee_uJobIntBlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; Fee_uJobIntBlockIt++ )
#endif
    {
        /* get cluster group */
        uBlockClusterGrp = Fee_GetBlockClusterGrp(Fee_uJobIntBlockIt);
        /* process only valid and inconsistent blocks from the current cluster */
        if ((Fee_uJobIntClrGrpIt == uBlockClusterGrp) &&
            ((FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus) ||
             (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus) ||
             (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus)
            )
           )

        {
            break;
        }
        else
        {
            /* No match. Try next one... */
        }
    }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
    if((FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber) == Fee_uJobIntBlockIt)
#else
    if( FEE_CRT_CFG_NR_OF_BLOCKS == Fee_uJobIntBlockIt )
#endif
    {
        /* No more matching blocks. Validate the cluster */
        eRetVal = Fee_JobIntSwapClrVld();
    }
    else
    {
        uBlockSize = Fee_GetBlockSize(Fee_uJobIntBlockIt);
        bImmediateBlock = Fee_GetBlockImmediate(Fee_uJobIntBlockIt);
        uBlockNumber = Fee_GetBlockNumber(Fee_uJobIntBlockIt);
        #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        uBlockAssignment = Fee_GetBlockAssignment(Fee_uJobIntBlockIt);
        #endif 

#if (FEE_LEGACY_MODE == STD_OFF)
        /* Data space no more allocated even for inconsistent immediate (pre-erased) blocks */
        if( FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus )
#else
        if( (FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus) ||
            ((boolean)TRUE == bImmediateBlock) \
          )
#endif
        {
            /* Align Fee block size to the virtual page boundary */
            uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

            /* Calculate data address */
            uDataAddr = Fee_uJobIntDataAddr - uAlignedBlockSize;

            /* Update the block address info */
            Fee_uJobIntDataAddr = uDataAddr;

            /* Initialize the data transfer iterator */
            Fee_uJobIntAddrIt = uDataAddr;
        }
        else
        {
#if (FEE_LEGACY_MODE == STD_OFF)
            /* Don't allocate data space for inconsistent block */
#else
            /* Don't allocate data space for inconsistent and
                not immediate block */
#endif
            uDataAddr = 0U;
        }

        /* Serialize block header to the write buffer */

        Fee_SerializeBlockHdr( uBlockNumber,
                               uBlockSize, uDataAddr,
                               bImmediateBlock, 
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                               uBlockAssignment,
#endif
                               Fee_aDataBuffer
                             );


        if( FEE_BLOCK_VALID == Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus )
        {
            /* Read block data */
            Fee_eJob = FEE_JOB_INT_SWAP_DATA_READ;
        }
        else
        {
            /* Nothing to read. Move on to next block */
            Fee_uJobIntBlockIt++;
            Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;
        }

        /* Write header to flash */
        if( ((Std_ReturnType)E_OK) !=
                Fls_Write( Fee_uJobIntHdrAddr, Fee_aDataBuffer,
                           FEE_BLOCK_OVERHEAD-(2U*FEE_VIRTUAL_PAGE_SIZE)
                         )
          )
        {
            /* Fls write job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls write job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }

        /* Move on to next block header */
        Fee_uJobIntHdrAddr += FEE_BLOCK_OVERHEAD;
    }

    return( eRetVal );
}

/**
* @brief        Format current Fee cluster in current Fee cluster group by
*               writing cluster header into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the write
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster
*                                        group
* @pre          Fee_uJobIntClrIt         must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrFmt( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;
    VAR( uint32, AUTOMATIC ) uActClrID = 0UL;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uLength = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].length;
    uActClrID = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClrID;

    /* Build cluster header with new uActClrID + 1 */
    Fee_SerializeClusterHdr( uActClrID+1U, uStartAddr, uLength, Fee_aDataBuffer );

    /* Write the cluster header to flash */
    if( ((Std_ReturnType)E_OK) ==
            Fls_Write( uStartAddr, Fee_aDataBuffer,
                       FEE_CLUSTER_OVERHEAD-(2U*FEE_VIRTUAL_PAGE_SIZE)
                     )
      )
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format done job */
    Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;

    return( eRetVal );
}

/**
* @brief        Erase current Fee cluster in current Fee cluster group by erasing flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_uJobIntClrIt        must contain index of current cluster
* @post         Schedule the FEE_JOB_INT_SWAP_CLR_FMT subsequent job
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uLength = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].length;

    /* Erase cluster */
    if( ((Std_ReturnType)E_OK) == Fls_Erase( uStartAddr, uLength ) )
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls read job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format job */
    Fee_eJob = FEE_JOB_INT_SWAP_CLR_FMT;

    return( eRetVal );
}

/**
* @brief        Initialize the cluster swap internal operation on
*               current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase job
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current cluster group
* @pre          Fee_eJob                 must contain type of Fee job which caused the cluster swap
*
* @post         Fee module status is set to MEMIF_BUSY_INTERNAL
* @post         Fee_eJob is stored in Fee_eJobIntOriginalJob so it can be rescheduled
*               once the swap operation is finished
* @post         Fee internal block iterator Fee_uJobIntBlockIt is set to zero
* @post         Fee internal cluster iterator Fee_uJobIntClrIt is set to
*               the target cluster
* @post         Fee_uJobIntHdrAddr and Fee_uJobIntDataAddr addresses are initialized to
*               point to the target cluster
* @post         Schedule erase of the target cluster
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwap( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    /* Store type of original job so Fee can re-schedule
        this job once the swap is complete */
    Fee_eJobIntOriginalJob = Fee_eJob;

    /* Reset the block iterator */
    Fee_uJobIntBlockIt = 0U;

    /* Get cluster index the block belongs to */
    Fee_uJobIntClrIt = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClr;

    /* Calculate index of cluster to swap to */
    Fee_uJobIntClrIt++;

    if( Fee_uJobIntClrIt == Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrCount )
    {
        /* Cluster roll over */
        Fee_uJobIntClrIt = 0U;
    }
    else
    {
        /* Do nothing */
    }

    /* Calculate header and data address iterators */
    Fee_uJobIntHdrAddr =
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;

    Fee_uJobIntDataAddr = Fee_uJobIntHdrAddr +
        /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
           allowed form of pointer arithmetic. */
        Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].length;

    /* Move on to the first block header */
    Fee_uJobIntHdrAddr += FEE_CLUSTER_OVERHEAD;

    /* Erase the swap cluster */
    eRetVal = Fee_JobIntSwapClrErase();

    return( eRetVal );
}

/**
* @brief        Read the Fee block header into internal buffer
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept the read job
*
* @pre          Fee_uJobIntAddrIt must contain valid logical address of
*               Fee block header to read
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    /* Read the block header */
    if( ((Std_ReturnType)E_OK) !=
            Fls_Read( Fee_uJobIntAddrIt, Fee_aDataBuffer, FEE_BLOCK_OVERHEAD )
      )
    {
        /* Fls read job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }

    Fee_eJob = FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE;

    return( eRetVal );
}

/**
* @brief        Erase first Fee cluster in current cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;

    /* Get address and size of first cluster in the current cluster group */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[0].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uLength = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[0].length;

    if( ((Std_ReturnType)E_OK) == Fls_Erase( uStartAddr, uLength ) )
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls read job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format job */
    Fee_eJob = FEE_JOB_INT_SCAN_CLR_FMT;

    return( eRetVal );
}

/**
* @brief        Scan active cluster of current cluster group or erase and format
*               first cluster if an active cluster can't be found
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @post         Initialize the Fee_uJobIntAddrIt iterator to address of
*               the first Fee block header to scan
* @post         Initialize the uHdrAddrIt and uDataAddrIt iterators to addresses of
*               the first Fee block header and data block
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClr( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( uint8, AUTOMATIC ) uClrIndex = (uint8)0;
    VAR( Fls_AddressType , AUTOMATIC ) uClrStartAddr = 0UL;
    VAR( Fls_LengthType , AUTOMATIC ) uClrLength = 0UL;

    if( FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_uJobIntClrGrpIt )
    {
        /* Nor more cluster groups to scan */
        Fee_eJob = FEE_JOB_DONE;
    }
    else
    {
        if( 0U == Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClrID )
        { 
            /* call the cluster format notification */
            FEE_NVM_CLUSTER_FORMAT_NOTIFICATION    
            /* No active cluster found in current group so erase and format
                the first one... */              
            eRetVal = Fee_JobIntScanClrErase();
        }
        else
        {
            /* Active cluster found */
            /* Get index of active cluster */
            uClrIndex = Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClr;

            /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
               allowed form of pointer arithmetic. */
            uClrStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[uClrIndex].startAddr;

            /* Calculate logical address of first block header in active cluster */
            Fee_uJobIntAddrIt = FEE_CLUSTER_OVERHEAD + uClrStartAddr;

            /* Initialize the block header pointer */
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt = Fee_uJobIntAddrIt;

            /* Initialize the block data pointer */
            /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
               allowed form of pointer arithmetic. */
            uClrLength = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[uClrIndex].length;
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt = uClrStartAddr + uClrLength;

            /* Active cluster found so read the first block header */
            eRetVal = Fee_JobIntScanBlockHdrRead();
        }
    }

    return( eRetVal );
}

/**
* @brief        Format first Fee cluster in current Fee cluster group by writing
*               cluster header into flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_FMT_DONE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmt( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) uLength = 0UL;

    /* Get address and size of first cluster in the current cluster group */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[0].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uLength = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[0].length;

    /* Build cluster header with clusterID = 1 */
    Fee_SerializeClusterHdr( 1U, uStartAddr, uLength, Fee_aDataBuffer );

    /* Make the cluster valid right away as it's empty anyway... */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    Fee_SerializeFlag( (Fee_aDataBuffer+FEE_CLUSTER_OVERHEAD)-(2U*FEE_VIRTUAL_PAGE_SIZE),
                       FEE_VALIDATED_VALUE
                     );

    /* Write the cluster header to flash */
    if( ((Std_ReturnType)E_OK) ==
            Fls_Write( uStartAddr, Fee_aDataBuffer,
                       FEE_CLUSTER_OVERHEAD-FEE_VIRTUAL_PAGE_SIZE
                     )
      )
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }
    else
    {
        /* Fls write job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }

    /* Schedule cluster format done job */
    Fee_eJob = FEE_JOB_INT_SCAN_CLR_FMT_DONE;

    return( eRetVal );
}

/**
* @brief        Finalize format of first Fee cluster in current Fee cluster group
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @post         Assign index (uActClr) and ID (uActClrID) of active cluster in
*               current cluster group
* @post         Initialize the uHdrAddrIt and uDataAddrIt iterators to addresses
*               of
*               the first Fee block header and data block
* @post         Advance the Fee_uJobIntClrGrpIt iterator to next cluster group
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrFmtDone( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType , AUTOMATIC ) uClrStartAddr = 0UL;
    VAR( Fls_LengthType , AUTOMATIC ) uClrLength = 0UL;

    /* Assign Index and ID of active cluster */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClr = 0U;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClrID = 1U;

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic. */
    uClrStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[0].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic */
    uClrLength = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[0].length;

    /* Initialize the block header pointer */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt =
        uClrStartAddr + FEE_CLUSTER_OVERHEAD;

    /* Initialize the block data pointer */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt = uClrStartAddr + uClrLength;

    /* Move on to next cluster group */
    Fee_uJobIntClrGrpIt++;

    /* Scan next cluster group if any */
    eRetVal = Fee_JobIntScanClr();

    return( eRetVal );
}

/**
* @brief        Parse Fee block header
*
* @param[in]    bBufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or
*                                        read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase
*                                        or read job
* @retval       MEMIF_JOB_OK             There is no more cluster groups to scan
*
* @pre          Fee_uJobIntClrGrpIt      must contain index of current Fee
*                                        cluster group
*
* @post         Initialize internal recovery swap operation in case of bogus
*               Fee block header or failure of previous read job (perhaps ECC failure..)
* @post         Advance the Fee_uJobIntClrGrpIt iterator to next cluster group in
*               case of blank Fee block header (end of header list)
* @post         Update the eBlockStatus, uDataAddr, and uInvalidAddr block
*               information and the uHdrAddrIt and uDataAddrIt iterators in case of valid
*               Fee block header
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_PARSE subsequent job in case
*               of valid Fee block header
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanBlockHdrParse
    (
        CONST( boolean, AUTOMATIC ) bBufferValid
    )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
    VAR( Fee_BlockStatusType, AUTOMATIC ) eBlockStatus;
    VAR( uint16, AUTOMATIC ) uBlockNumber = 0U;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0UL;
    VAR( boolean, AUTOMATIC ) bImmediateData = (boolean)FALSE;
    VAR( uint16, AUTOMATIC ) uBlockIndex = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uBlockRuntimeInfoIndex = 0U;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    VAR( uint8, AUTOMATIC ) uBlockAssignment = (uint8)FEE_PROJECT_RESERVED;
    VAR( uint16, AUTOMATIC ) uForeignBlockIndex = 0U;
    VAR( boolean, AUTOMATIC ) bForeign = (boolean)FALSE;
    VAR( boolean, AUTOMATIC ) bForeignBlockOverflow = (boolean)FALSE;
#endif
    /* Internal variable used to trigger a cluster swap. Used by the swap job. */
    static VAR( boolean, AUTOMATIC) bSwapToBePerformed = (boolean)FALSE;
    VAR( boolean, AUTOMATIC) bFeeSwapNeeded = (boolean)FALSE;
    
    /* Deserialize block header from read buffer */
    eBlockStatus =
        /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
        Fee_DeserializeBlockHdr( &uBlockNumber, &uBlockSize, &uDataAddr,  &bImmediateData,
                                #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
                                /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
                                 &uBlockAssignment,
                                #endif
                                 Fee_aDataBuffer
                               );

#if (FEE_LEGACY_MODE == STD_ON)
    /* Clear swap variable except for last header */
    if( FEE_BLOCK_HEADER_BLANK  != eBlockStatus )
    {
        bSwapToBePerformed = (boolean)FALSE;
    }
#else
    /* bSwapToBePerformed was set because previously processed block wasn't properly recognized.
       => perform a swap to prevent a risk that this block overlaps the Reserved Area. */
#endif
    if( (FEE_BLOCK_HEADER_INVALID  == eBlockStatus) || ((boolean)FALSE == bBufferValid))
    {
        /* Invalidate the block index so Fee won't skip
            the Fee_uJobBlockIndex block */
        Fee_uJobBlockIndex = 0xffffU;

        /* Move on to next block header */
        Fee_uJobIntAddrIt += FEE_BLOCK_OVERHEAD;

        /* Update the block header pointer */
        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt = Fee_uJobIntAddrIt;

        /* Set swap-to-be-performed flag */
        bSwapToBePerformed = (boolean)TRUE;

        /* Read next header */
        eRetVal = Fee_JobIntScanBlockHdrRead();

    }
    else if( FEE_BLOCK_HEADER_BLANK  == eBlockStatus )
    {
        /* If SwapToBePerformed is set, it means that last header is corrupted and
           ONLY now the uDataAddrIt variable will be updated to cause swap. */
        if( ((boolean)TRUE) == bSwapToBePerformed )
        {
           bSwapToBePerformed = (boolean)FALSE;
           Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt = Fee_uJobIntAddrIt +
                                                               (2U * FEE_BLOCK_OVERHEAD);
        }

        /* End of header list so move on to next cluster group */
        Fee_uJobIntClrGrpIt++;

        eRetVal = Fee_JobIntScanClr();
    }
    else
    {
        /* Look for found block in the block configuration */
        uBlockIndex = Fee_GetBlockIndex( uBlockNumber );
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        /* initialize bForeign as false */
        bForeign = (boolean)FALSE;

        /* check if block was found in the configuration */
        if( 0xFFFFU == uBlockIndex )
        {
            /* check if block is foreign*/
            #if (FEE_BOOTLOADER_CONFIG == STD_ON)
                if (FEE_PROJECT_APPLICATION == (Fee_BlockAssignmentType)uBlockAssignment)
            #else
                if (FEE_PROJECT_BOOTLOADER == (Fee_BlockAssignmentType)uBlockAssignment)
            #endif
                {       
                    /* block is foreign */
                    bForeign = (boolean)TRUE;
                    /* search for block index in the foreign blocks config */
                    uForeignBlockIndex =  Fee_GetForeignBlockIndex( uBlockNumber );
                    if( 0xFFFFU == uForeignBlockIndex )
                    {
                        /* assume there is no overflow */
                        bForeignBlockOverflow = (boolean)FALSE;
                        /* it's a new foreign block */
                        if(Fee_uForeignBlocksNumber < (FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS))
                        {
                            uForeignBlockIndex = Fee_uForeignBlocksNumber;
                            /* update the foreign block config */
                            Fee_aForeignBlockConfig[uForeignBlockIndex].blockNumber = uBlockNumber;
                            Fee_aForeignBlockConfig[uForeignBlockIndex].blockSize = uBlockSize;
                            Fee_aForeignBlockConfig[uForeignBlockIndex].clrGrp = Fee_uJobIntClrGrpIt;
                            Fee_aForeignBlockConfig[uForeignBlockIndex].immediateData = bImmediateData;
                            Fee_aForeignBlockConfig[uForeignBlockIndex].blockAssignment = (Fee_BlockAssignmentType)uBlockAssignment; 
                            /* increment the number of foreign blocks */
                            Fee_uForeignBlocksNumber = Fee_uForeignBlocksNumber + 1U;
                        }
                        else
                        {
                            #if (FEE_DEV_ERROR_DETECT == STD_ON)
                            /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
                            Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_FOREIGN_BLOCKS_OVF);
                            #endif
                            /* Call job error notification function */
                            FEE_NVM_JOB_ERROR_NOTIFICATION 
                            /* set job failed*/
                            bForeignBlockOverflow = (boolean)TRUE;
                        }
                    }
                }
        }
        if( (boolean)FALSE == bForeignBlockOverflow) 
        {
#endif    
            #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)        
            if( (0xFFFFU != uBlockIndex) || ((boolean)TRUE == bForeign))
            #else
            if( 0xFFFFU != uBlockIndex) 
            #endif
            {

                /* prepare index to be used for the runtime info data*/        
                #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
                if((boolean)TRUE == bForeign)
                {
                    uBlockRuntimeInfoIndex = FEE_CRT_CFG_NR_OF_BLOCKS + uForeignBlockIndex;
                }
                else
                {
                    uBlockRuntimeInfoIndex = uBlockIndex;
                }
                #else
                uBlockRuntimeInfoIndex = uBlockIndex;
                #endif    

                uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );
                
                /* Check whether found block belongs to current cluster group,
                    and its size and type match the configuration,
                    and its data pointer points to an acceptable area
                */
                bFeeSwapNeeded = (boolean)FALSE;
                
                if ((uDataAddr <=(Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt-uAlignedBlockSize)) &&
                    (uDataAddr >= (Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt+(2U*FEE_BLOCK_OVERHEAD))))
                {
    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)                
                    if((boolean)FALSE == bForeign)
    #endif 
                    {
                        if((Fee_BlockConfig[uBlockIndex].clrGrp == Fee_uJobIntClrGrpIt) &&
                            (Fee_BlockConfig[uBlockIndex].blockSize == uBlockSize) &&
                            (Fee_BlockConfig[uBlockIndex].immediateData == bImmediateData))
                        {
                            bFeeSwapNeeded = (boolean)FALSE;

                        }
                        else
                        {
                            bFeeSwapNeeded = (boolean)TRUE;   
                        }
                    }

                }
                else
                {
                    bFeeSwapNeeded = (boolean)TRUE;  
                }
                /* check if swap is needed */
                if( (boolean)FALSE == bFeeSwapNeeded )
                {
                    /* Update block run-time information */
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                    /* Update block run-time information when:
                      - new valid block is found
                      - block was invalidated
                      - block contains immediate data
                        (basically just ignore INCONSISTENT non-immediate blocks)
                     */
        #if (FEE_LEGACY_MODE == STD_OFF)
                    /* no special treatment of immediate data needed any more */
                    if( FEE_BLOCK_INCONSISTENT != eBlockStatus )
        #else
                    if( (FEE_BLOCK_INCONSISTENT != eBlockStatus) ||
                        (((boolean)TRUE) == bImmediateData)
                      )
        #endif
                    {
                         /* Mark invalidated blocks as invalid */
                        if( FEE_BLOCK_INVALIDATED == eBlockStatus )
                        {
                             eBlockStatus = FEE_BLOCK_INVALID;
                        }
    #endif

                        Fee_aBlockInfo[uBlockRuntimeInfoIndex].eBlockStatus = eBlockStatus;
                         /* Update the block data pointer */
                        Fee_aBlockInfo[uBlockRuntimeInfoIndex].uDataAddr = uDataAddr;
                        Fee_aBlockInfo[uBlockRuntimeInfoIndex].uInvalidAddr =
                            (Fee_uJobIntAddrIt + FEE_BLOCK_OVERHEAD) -
                                FEE_VIRTUAL_PAGE_SIZE;
       


                        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt = uDataAddr;
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
                    }
                    else
                    {
                        /* header is valid but data is corrupted, in this case it is important to update
                           uDataAddrIt to avoid corrupted space, cluster swap is not needed */
                        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt = uDataAddr;
                    }
    #endif

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
                    /* Check for blocks potentially overlaping the Reserved Area */
                    /* Let Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt] be completely updated before calling
                       Fee_ReservedAreaTargetedInClrGrp() */
                    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt =
                        Fee_uJobIntAddrIt + FEE_BLOCK_OVERHEAD;
                    if( FALSE != Fee_ReservedAreaTargetedInClrGrp( Fee_uJobIntClrGrpIt ) )
                    {
                        if( bImmediateData )
                        {
                            /* Mark the imm. block as touching the Reserved Area (we are esp.
                               interested only about inconsistent imm. blocks here, but it does not
                               matter if also consistent imm. block will be marked) */
                            Fee_TouchReservedAreaByBlock( uBlockRuntimeInfoIndex );

                        }
                        else
                        {
                            /* Non-immediate data found in the Reserved Area => swap */
                            bSwapToBePerformed = (boolean)TRUE;
                            /* Note that if FEE_LEGACY_MODE == STD_OFF, bSwapToBePerformed is not reset
                               to FALSE upon recognition of the next written header =>
                               the swap is mandatory. */
                        }
                    }
    #endif
                }
                else
                {
                    /* Block header doesn't match Fee config or the FEE algorithm...
                       during next write cluster swap occurs */
                    bSwapToBePerformed = (boolean)TRUE;
                }

            }
            else
            {
                /* Invalid block number (removed from Fee config...) next write cluster swap occurs */
                bSwapToBePerformed = (boolean)TRUE;
            }

            /* Move on to next block header */
            Fee_uJobIntAddrIt += FEE_BLOCK_OVERHEAD;

            /* Update the block header pointer */
            Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt = Fee_uJobIntAddrIt;

            /* Read next header */
            eRetVal = Fee_JobIntScanBlockHdrRead();
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
        }
        else
        {
            /* set job as failed */
            eRetVal = MEMIF_JOB_FAILED;
        }
#endif 
    }
    return( eRetVal );
}

/**
* @brief        Read Fee cluster header
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_uJobIntClrIt must contain index of current Fee cluster
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uReadAddress = 0UL;

    /* Get address of current cluster */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
       allowed form of pointer arithmetic */
    uReadAddress = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;

    if( ((Std_ReturnType)E_OK) != Fls_Read( uReadAddress, Fee_aDataBuffer, FEE_CLUSTER_OVERHEAD  ) )
    {
        /* Fls read job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }

    /* Schedule cluster scan job */
    Fee_eJob = FEE_JOB_INT_SCAN_CLR_HDR_PARSE;

    return( eRetVal );
}

/**
* @brief        Initialize the cluster scan job
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @post         Reset the Fee_uJobIntClrGrpIt and Fee_uJobIntClrIt iterators
* @post         Schedule the FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScan( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    /* Reset iterators to first cluster of first cluster group */
    Fee_uJobIntClrGrpIt = 0U;
    Fee_uJobIntClrIt = 0U;

    /* Schedule reading of first cluster header */
    eRetVal = Fee_JobIntScanClrHdrRead();

    return( eRetVal );
}

/**
* @brief        Parse Fee cluster header
*
* @param[in]    bBufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the erase or read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept the erase or read job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Update the Fee_uJobIntClrIt and/or Fee_uJobIntClrGrpIt iterators to move
*               into next cluster and/or cluster group and read next cluster header if
*               there is any
* @post         Scan first active cluster if Fee is done with reading the cluster headers
* @post         Schedule the FEE_JOB_DONE, FEE_JOB_INT_SCAN_CLR_FMT,
*               FEE_JOB_INT_SCAN_CLR_PARSE, FEE_JOB_INT_SCAN_CLR_HDR_PARSE subsequent jobs
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntScanClrHdrParse
    (
        CONST( boolean, AUTOMATIC) bBufferValid
    )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fee_ClusterStatusType, AUTOMATIC ) eClrStatus = FEE_CLUSTER_VALID;
    VAR( uint32, AUTOMATIC ) uClrID = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) uClrStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) uClrSize = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) uCfgStartAddr = 0UL;
    VAR( Fls_LengthType, AUTOMATIC ) uCfgClrSize = 0UL;

    /* Get configured cluster start address and size */
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the
       only allowed form of pointer arithmetic */
    uCfgStartAddr = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the
       only allowed form of pointer arithmetic */
    uCfgClrSize = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].length;

    /* Deserialize cluster parameters from the read buffer */
    /* @violates @ref Fee_c_REF_4 Taking address of near auto variable. */
    eClrStatus = Fee_DeserializeClusterHdr( &uClrID, &uClrStartAddr, &uClrSize, Fee_aDataBuffer );
    
    if( ((boolean)TRUE == bBufferValid) && (FEE_CLUSTER_VALID == eClrStatus) &&
        (uClrStartAddr == uCfgStartAddr) && (uClrSize == uCfgClrSize) &&
        (uClrID > Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClrID)
      )
    {
        /* Found valid and active cluster */
        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClr = Fee_uJobIntClrIt;
        Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClrID = uClrID;
    }
    else
    {
        /* Invalid, inconsistent, or cluster with low ID */
    }

    /* Move on to next cluster */
    Fee_uJobIntClrIt++;

    if( Fee_uJobIntClrIt == Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrCount )
    {
        /* Move on to next cluster group */
        Fee_uJobIntClrGrpIt++;
        Fee_uJobIntClrIt = 0U;
    }
    else
    {
        /* next cluster in current cluster group */
    }

    if( FEE_NUMBER_OF_CLUSTER_GROUPS == Fee_uJobIntClrGrpIt )
    {
        Fee_uJobIntClrGrpIt = 0U;

        /* Done reading all cluster headers. Now scan active clusters */
        eRetVal = Fee_JobIntScanClr();
    }
    else
    {
        /* Read next cluster header */
        eRetVal = Fee_JobIntScanClrHdrRead();
    }

    return( eRetVal );
}

/**
* @brief        Read Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
* @retval       MEMIF_BLOCK_INVALID      Requested Fee block is invalid
* @retval       MEMIF_BLOCK_INCONSISTENT Requested Fee block is inconsistent
*
* @pre          Fee_uJobBlockIndex must contain index of requested Fee block
* @pre          Fee_uJobBlockOffset must contain offset in requested Fee block
* @pre          Fee_uJobBlockLength must contain number of bytes to read from requested Fee block
* @post         Schedule the FEE_JOB_DONE    subsequent job
*
* @implements   Fee_JobRead_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobRead( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
    VAR( Fee_BlockStatusType, AUTOMATIC ) eBlockStatus = FEE_BLOCK_VALID;
    VAR( Fls_AddressType, AUTOMATIC ) uBlockAddress = 0UL;

    eBlockStatus = Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus;
    uBlockAddress = Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr;

    if( FEE_BLOCK_VALID == eBlockStatus )
    {

        if( ((Std_ReturnType)E_OK) !=
                Fls_Read( uBlockAddress+Fee_uJobBlockOffset,
                          Fee_pJobReadDataDestPtr, Fee_uJobBlockLength
                        )
          )

        {
            /* Fls read job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }
    }
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF) 
    else if( FEE_BLOCK_NEVER_WRITTEN == eBlockStatus )
    {
        /* in case the block was never written */
        eRetVal = MEMIF_BLOCK_INCONSISTENT;
    }
#endif
    else if( FEE_BLOCK_INVALID == eBlockStatus )
    {
        eRetVal = MEMIF_BLOCK_INVALID;
    }
    else if( (FEE_BLOCK_INCONSISTENT == eBlockStatus) || (FEE_BLOCK_INCONSISTENT_COPY == eBlockStatus) )
    {
#if (FEE_LEGACY_MODE == STD_OFF)
        /* No special treatment of immediate blocks needed anymore */
        eRetVal = MEMIF_BLOCK_INCONSISTENT;
#else
        #if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON) 
        /* In the LEGACY mode, if immediate data was only pre-erased, but never written,
           Fee must return MEMIF_BLOCK_INCONSISTENT state */
        if( Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        {
            eRetVal = MEMIF_BLOCK_INVALID;
        }
        else
        #endif
        {
            eRetVal = MEMIF_BLOCK_INCONSISTENT;
        }
#endif
    }
    else
    {
        /* Something is wrong... MEMIF_JOB_FAILED */
    }

    /* There is no consecutive job to schedule */
    Fee_eJob = FEE_JOB_DONE;

    return( eRetVal );
}

/**
* @brief        Validate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls did not accept write job
*
* @pre          Fee_uJobIntHdrAddr must contain address of Fee block header to
*               validate
* @post         Schedule the FEE_JOB_INT_SWAP_BLOCK subsequent job
*
* @implements   Fee_JobIntSwapBlockVld_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapBlockVld( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    /* Serialize validation pattern to buffer */
    Fee_SerializeFlag( Fee_aDataBuffer, FEE_VALIDATED_VALUE );

    /* Write header to flash */
    if( ((Std_ReturnType)E_OK) !=
            Fls_Write( Fee_uJobIntHdrAddr-(2U*FEE_VIRTUAL_PAGE_SIZE),
                       Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE
                     )
      )
    {
        /* Fls read job hasn't been accepted */
        eRetVal = MEMIF_JOB_FAILED;
    }
    else
    {
        /* Fls read job has been accepted */
        eRetVal = MEMIF_JOB_PENDING;
    }

    /* Finalize the write operation */
    Fee_eJob = FEE_JOB_INT_SWAP_BLOCK;

    return( eRetVal );
}

/**
* @brief        Read data from source cluster to internal Fee buffer
*
* @param[in]    bBufferValid             FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the read job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept read job
*
* @pre          Fee_uJobIntBlockIt must contain index of currently swaped
*               Fee block
* @pre          Fee_uJobIntDataAddr must contain start address of Fee data block
*               in the target cluster
* @pre          Fee_uJobIntAddrIt must contain current address of Fee data block
*               in the target cluster
* @post         Move on to next block Fee block if bBufferValid == FALSE
* @post         Validates the Fee block if there is no more data to read
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_WRITE subsequent job
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataRead
    (
        CONST( boolean, AUTOMATIC) bBufferValid
    )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
    VAR( Fls_AddressType, AUTOMATIC ) uReadAddr = 0UL;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;

    /* Get size of swaped block */
    uBlockSize = Fee_GetBlockSize(Fee_uJobIntBlockIt);
    
    /* Get size of swaped block aligned to virtual page boundary */
    uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

    /* Calculate remaining number of bytes to read */
    Fee_uJobBlockLength = (Fee_uJobIntDataAddr + uAlignedBlockSize) - Fee_uJobIntAddrIt;

    if( (boolean)FALSE == bBufferValid )
    {
        /* There was error while reading the source cluster.
           Change the block status to FEE_BLOCK_INCONSISTENT_COPY to mark the status change
           during swap, leave the block (in flash) INCONSITENT and move on to next block */
        Fee_aBlockInfo[Fee_uJobIntBlockIt].eBlockStatus = FEE_BLOCK_INCONSISTENT_COPY;

        Fee_uJobIntBlockIt++;

        eRetVal = Fee_JobIntSwapBlock();
    }
    else if( 0U == Fee_uJobBlockLength )
    {
        /* No more bytes to copy. Validate the block and
            move on to next block... */
        Fee_uJobIntBlockIt++;

        eRetVal = Fee_JobIntSwapBlockVld();
    }
    else
    {
        if( Fee_uJobBlockLength > FEE_DATA_BUFFER_SIZE )
        {
            Fee_uJobBlockLength = FEE_DATA_BUFFER_SIZE;
        }
        else
        {
            /* Block data fits into the buffer */
        }

        /* Calculate source address */
        uReadAddr = (Fee_aBlockInfo[Fee_uJobIntBlockIt].uDataAddr + Fee_uJobIntAddrIt) -
                       Fee_uJobIntDataAddr;

        /* Read the block data */
        if( ((Std_ReturnType)E_OK) != Fls_Read( uReadAddr, Fee_aDataBuffer, Fee_uJobBlockLength ) )
        {
            /* Fls read job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* Fls read job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }

        Fee_eJob = FEE_JOB_INT_SWAP_DATA_WRITE;
    }

    return( eRetVal );
}

/**
* @brief        Write data from internal Fee buffer to target cluster
*
* @param[in]    bBufferValid              FALSE if previous Fls read job has failed
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING         Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED          Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockLength       must contain size of data block being
*                                         transfered(up to FEE_DATA_BUFFER_SIZE)
* @pre          Fee_uJobIntAddrIt         must contain current address of Fee
*                                         data block in the target cluster
* @post         Update the Fee_uJobIntAddrIt data iterator for next data
*               transfer if any
* @post         Schedule the FEE_JOB_INT_SWAP_DATA_READ subsequent job
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapDataWrite
    (
        CONST( boolean, AUTOMATIC ) bBufferValid
    )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    if( bBufferValid )
    {
        if( ((Std_ReturnType)E_OK) ==
                Fls_Write( Fee_uJobIntAddrIt, Fee_aDataBuffer, Fee_uJobBlockLength )
          )
        {
            /* Fls read job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }

        Fee_uJobIntAddrIt += Fee_uJobBlockLength;

        Fee_eJob = FEE_JOB_INT_SWAP_DATA_READ;
    }
    else
    {
        eRetVal = Fee_JobIntSwapDataRead( (boolean)FALSE );
    }

    return( eRetVal );
}

/**
* @brief        Finalize cluster validation
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
*
* @pre          Fee_uJobIntClrGrpIt must contain index of current Fee cluster
*               group
* @pre          Fee_uJobIntClrIt must contain index of current cluster
* @post         Update the uDataAddr and uInvalidAddr Fee_BlockConfig variables of
*               all affected (swaped) Fee blocks
* @post         Update uActClr, uActClrID, uHdrAddrIt, uDataAddrIt Fee_aClrGrpInfo
*               variables of current cluster group
* @post         Change Fee module status from MEMIF_BUSYINTERNAL to MEMIF_BUSY
* @post         Re-schedule the Fee_eJobIntOriginalJob subsequent job
*
* @implements   Fee_JobIntSwapClrVldDone_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobIntSwapClrVldDone( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) uBlockIt = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddrIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddrIt = 0UL;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
#if (FEE_LEGACY_MODE == STD_ON)     
    VAR( boolean, AUTOMATIC ) bImmediateBlock = (boolean)FALSE;
#endif
    VAR( uint8, AUTOMATIC ) uBlockClusterGrp = 0U;
    
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
    /* Swap is done => re-initialize info about the blocks touching the Reserved Area within
       a cluster group where the swap has happened. */
    Fee_UntouchReservedAreaByClrGrp( Fee_uJobIntClrGrpIt );
#endif

    /* @violates @ref Fee_c_REF_6 Array indexing shall be the
       only allowed form of pointer arithmetic */
    uHdrAddrIt = Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].startAddr;
    /* @violates @ref Fee_c_REF_6 Array indexing shall be the
       only allowed form of pointer arithmetic */
    uDataAddrIt = uHdrAddrIt + Fee_ClrGrps[Fee_uJobIntClrGrpIt].clrPtr[Fee_uJobIntClrIt].length;

    /* Move on to the first block header */
    uHdrAddrIt += FEE_CLUSTER_OVERHEAD;

    /* Sync block info */
    
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
   for( uBlockIt = 0U; uBlockIt < (FEE_CRT_CFG_NR_OF_BLOCKS + Fee_uForeignBlocksNumber); uBlockIt++ )
#else
   for( uBlockIt = 0U; uBlockIt < FEE_CRT_CFG_NR_OF_BLOCKS; uBlockIt++ )
#endif
    {
        uBlockClusterGrp = Fee_GetBlockClusterGrp(uBlockIt);
        
        if(Fee_uJobIntClrGrpIt == uBlockClusterGrp)
        {
            /* Valid blocks and inconsistent blocks with allocated data were copied,
               update the block info and internal pointers accordingly.
            */
            if( (FEE_BLOCK_VALID == Fee_aBlockInfo[uBlockIt].eBlockStatus) ||
                (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[uBlockIt].eBlockStatus) ||
                (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[uBlockIt].eBlockStatus)
              )
            {
                /* Sync uInvalidAddr */
                Fee_aBlockInfo[uBlockIt].uInvalidAddr = (uHdrAddrIt + FEE_BLOCK_OVERHEAD) -
                                                         FEE_VIRTUAL_PAGE_SIZE;
                /* check if block is immediate */
                #if (FEE_LEGACY_MODE == STD_ON)                
                bImmediateBlock = Fee_GetBlockImmediate(uBlockIt);
                #endif
                /* Update the block data address info */
                if( (FEE_BLOCK_VALID == Fee_aBlockInfo[ uBlockIt ].eBlockStatus) ||
                    (FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[ uBlockIt ].eBlockStatus)
                #if (FEE_LEGACY_MODE == STD_ON)
                     || ( ((boolean)TRUE == bImmediateBlock) &&
                          (FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[ uBlockIt ].eBlockStatus) 
                        )
                #endif
                  )
                {
                    uBlockSize = Fee_GetBlockSize(uBlockIt);
                    /* Align block size to the virtual page boundary */
                    uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );
                    /* "Allocate" data already swapped (written to the flash) */
                    uDataAddrIt -= uAlignedBlockSize;
                    if( FEE_BLOCK_INCONSISTENT_COPY == Fee_aBlockInfo[ uBlockIt ].eBlockStatus )
                    {
                        /* Damaged data read during copy, but already allocated => inconsistent */
                        Fee_aBlockInfo[ uBlockIt ].eBlockStatus = FEE_BLOCK_INCONSISTENT;
                        /* Mark inconsistency in the runtime info (no data) for the next swap attempt */
                        Fee_aBlockInfo[uBlockIt].uDataAddr = 0U;
                    }
                    else
                    {
                        /* store the data address to the block runtime record */
                        Fee_aBlockInfo[uBlockIt].uDataAddr = uDataAddrIt;
                    }
                }
                else
                {
                    /* (Inconsistent plain block in LEGACY == ON) or 
                       (Inconsistent plain or immediate block in LEGACY == OFF) -- no data written (swapped, allocated)/available */
                    Fee_aBlockInfo[uBlockIt].uDataAddr = 0U;
                }

                /* Advance the header pointer */
                uHdrAddrIt += FEE_BLOCK_OVERHEAD;
            }
            else
            {
                /* Not a usable block */
                /* clear the addresses of the block not present in the new active cluster */
                Fee_aBlockInfo[uBlockIt].uDataAddr = 0U;
                Fee_aBlockInfo[uBlockIt].uInvalidAddr = 0U;
            }
        }
    }

    /* Switch to the new cluster */
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClr = Fee_uJobIntClrIt;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uActClrID++;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uHdrAddrIt = uHdrAddrIt;
    Fee_aClrGrpInfo[Fee_uJobIntClrGrpIt].uDataAddrIt = uDataAddrIt;

    /* restore original Fee_eJob */
    if( FEE_JOB_INT_SCAN_CLR == Fee_eJobIntOriginalJob )
    {
        Fee_uJobIntClrGrpIt++;
    }
    else
    {
        /* Do nothing */
    }

    /* Internal job has finished so transition from MEMIF_BUSYINTERNAL to MEMIF_BUSY */
    Fee_eModuleStatus = MEMIF_BUSY;

    /* And now cross fingers and re-schedule original job ... */
    Fee_eJob = Fee_eJobIntOriginalJob;

    eRetVal = Fee_JobSchedule();

    return( eRetVal );
}

/**
* @brief        Write Fee block header to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         Update the uDataAddr and uInvalidAddr Fee_BlockConfig variables of
*               written Fee block
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
*
* @implements   Fee_JobWriteHdr_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteHdr( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0U;
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = 0U;
#if (FEE_LEGACY_MODE == STD_ON)
    VAR( Fls_LengthType, AUTOMATIC ) uAvailClrSpace = 0UL;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/    
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif

        /* Index of cluster group the Fee block belongs to */
        uClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;

        #if (FEE_LEGACY_MODE == STD_ON)
        /* Calculate available space in active cluster */
        uAvailClrSpace = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt -
                             Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;
        #endif

        /* Get size of Fee block */
        uBlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].blockSize;

        /* Align Fee block size to the virtual page boundary */
        uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

        #if (FEE_LEGACY_MODE == STD_ON)
        /* One FEE_BLOCK_OVERHEAD must be left blank to have a clear separation
           between header block space and data block space */
        if( (((uint32)uAlignedBlockSize)+(2U*FEE_BLOCK_OVERHEAD)) > uAvailClrSpace )
        #else
        if( (boolean)FALSE == (boolean)Fee_ReservedAreaWritable() )
        #endif
        {
            /* The block won't fit into current cluster. Init swap sequence... */

            /* Get cluster group index the block belongs to */
            Fee_uJobIntClrGrpIt = uClrGrpIndex;

            eRetVal = Fee_JobIntSwap();
        }
        else
        {
            /* Calculate data and header addresses */
            uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt - uAlignedBlockSize;
            uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

            /* Serialize block header to the write buffer */
            Fee_SerializeBlockHdr( Fee_BlockConfig[Fee_uJobBlockIndex].blockNumber,
                                   uBlockSize, uDataAddr,
                                   Fee_BlockConfig[Fee_uJobBlockIndex].immediateData,
                                    #if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
                                   Fee_BlockConfig[Fee_uJobBlockIndex].blockAssignment,
                                   #endif
                                   Fee_aDataBuffer
                                 );

            /* Write header to flash */
            if( ((Std_ReturnType)E_OK) !=
                    Fls_Write( uHdrAddr, Fee_aDataBuffer,
                               FEE_BLOCK_OVERHEAD-(2U*FEE_VIRTUAL_PAGE_SIZE)
                             )
              )
            {
                /* Fls read job hasn't been accepted */
                eRetVal = MEMIF_JOB_FAILED;
            }
            else
            {
                /* Fls read job has been accepted */
                eRetVal = MEMIF_JOB_PENDING;
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif
    return( eRetVal );
}


/**
* @brief        Write Fee block data to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex       must contain index of Fee block to
*                                        write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user
*                                        buffer
* @post         Update uHdrAddrIt, uDataAddrIt Fee_aClrGrpInfo variables of current
*               cluster group if immediateData == FALSE only
* @post         Changes eBlockStatus to FEE_BLOCK_INCONSISTENT
* @post         Schedule either FEE_JOB_WRITE_VALIDATE or
*               FEE_JOB_WRITE_UNALIGNED_DATA subsequent job
*
* @implements   Fee_JobWriteData_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteData( void )
{
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = (Fls_AddressType)0;
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( Fls_LengthType, AUTOMATIC ) uWriteLength = 0UL;
    VAR( uint8, AUTOMATIC ) uClrGrp = 0U;
    P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pWriteDataPtr = NULL_PTR; 
#if (FEE_LEGACY_MODE == STD_OFF)
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)    
    VAR(sint8, AUTOMATIC) sIsReservedAreaTouched = TRUE; 
#endif
#endif
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = 0U;
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/    
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
        #if (FEE_LEGACY_MODE == STD_OFF)
        /* No special treatment of immediate blocks needed anymore; dataAddr and invalidAddr
           has to be updated for a newly written imm/non-imm block  */
        #else
        if( (boolean)FALSE == Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        #endif
        {

            /* Index of cluster group the Fee block belongs to */
            uClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;

            /* Get size of Fee block */
            uBlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].blockSize;

            /* Align Fee block size to the virtual page boundary */
            uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

            /* Calculate data and header addresses */
            uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt - uAlignedBlockSize;
            uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

            Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr = uDataAddr;
            Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr = (uHdrAddr + FEE_BLOCK_OVERHEAD) -
                                                                  FEE_VIRTUAL_PAGE_SIZE;
        }
        /* Mark the block as inconsistent since the block header has been written */
        Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INCONSISTENT;
    #endif  /* (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF) */

        /* Get size of Fee block */
        uBlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].blockSize;

        /* Align Fee block size to the virtual page boundary */
        uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

        /* Index of cluster group the Fee block belongs to */
        uClrGrp = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;

    #if (FEE_LEGACY_MODE == STD_OFF)
        /* Header has been written so update both header and data addresses;
           no special treatment of immediate blocks needed anymore */
        Fee_aClrGrpInfo[uClrGrp].uHdrAddrIt += FEE_BLOCK_OVERHEAD;
        Fee_aClrGrpInfo[uClrGrp].uDataAddrIt -= uAlignedBlockSize;
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* When FEE_BLOCK_ALWAYS_AVAILABLE is enabled, Fee_BlockInfo is not updated immediatelly
           upon a header write. In case of FEE Cancel, the information about the incosistent
           (due to incomplete write) immediate block potentially residing in the Reserved Area
           might be lost and therefore it need to be extra handled. */
        sIsReservedAreaTouched = Fee_ReservedAreaTargetedInClrGrp( uClrGrp );
        if( (0UL != Fee_BlockConfig[Fee_uJobBlockIndex].immediateData) && (FALSE != sIsReservedAreaTouched))
        {
            /* Store the information about immediate blook touching the Reserved Area. */
            Fee_TouchReservedAreaByBlock( Fee_uJobBlockIndex );
        }
        #endif
    #else
        if( Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        {
            /* Don't update header and data pointes as it's immediate write */
        }
        else
        {
            /* Header has been written so update both header and data addresses */
            Fee_aClrGrpInfo[uClrGrp].uHdrAddrIt += FEE_BLOCK_OVERHEAD;
            Fee_aClrGrpInfo[uClrGrp].uDataAddrIt -= uAlignedBlockSize;
        }
    #endif

        if( uBlockSize < FEE_VIRTUAL_PAGE_SIZE )
        {
            /* Go through buffer... */
                Fee_CopyDataToPageBuffer( Fee_pJobWriteDataDestPtr, Fee_aDataBuffer, uBlockSize );
                pWriteDataPtr = Fee_aDataBuffer;
            uWriteLength = FEE_VIRTUAL_PAGE_SIZE;

            /* Schedule write of validation pattern */
            Fee_eJob = FEE_JOB_WRITE_VALIDATE;
        }
        else
        {
                pWriteDataPtr = Fee_pJobWriteDataDestPtr;
    
            if( uAlignedBlockSize == uBlockSize )
            {
                uWriteLength = uBlockSize;

                /* Schedule write of validation pattern */
                Fee_eJob = FEE_JOB_WRITE_VALIDATE;
            }
            else
            {
                uWriteLength = ((uint32)uAlignedBlockSize) - FEE_VIRTUAL_PAGE_SIZE;

                /* Schedule write of unaligned data */
                Fee_eJob = FEE_JOB_WRITE_UNALIGNED_DATA;
            }
        }


    #if (FEE_LEGACY_MODE == STD_OFF)
       uDataAddr = Fee_aClrGrpInfo[uClrGrp].uDataAddrIt;
    #else
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        if( Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        {
        #endif
            /* Use Block info because it has been updated into Fee_JobEraseImmediateDone */
            uDataAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr;

        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        }
        else
        {
            /* Use ClrGrp info */
            uDataAddr = Fee_aClrGrpInfo[uClrGrp].uDataAddrIt;
        }
        #endif
    #endif

        if( ((Std_ReturnType)E_OK) == Fls_Write( uDataAddr, pWriteDataPtr, uWriteLength ) )
        {
            /* Fls read job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif    
    return( eRetVal );
}

/**
* @brief        Write Fee block to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_WRITE_DATA subsequent job
*
* @implements   Fee_JobWrite_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWrite( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif
        #if (FEE_LEGACY_MODE == STD_ON)
        if( Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        {
            if( FEE_BLOCK_INCONSISTENT == Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus )
            {
                /* The immediate block is ready to be written */
                eRetVal = Fee_JobWriteData();
            }
            else
            {
                /* The immediate block is not pre-erased and ready to be written */
                eRetVal = MEMIF_JOB_FAILED;
            }
        }
        else
        #else
        /* No special treatment of immediate data needed any more;
           pre-erased space not required */
        #endif
        {
            /* Write block header */
            eRetVal = Fee_JobWriteHdr();

            /* Schedule next job */
            if( FEE_JOB_INT_SWAP_CLR_FMT == Fee_eJob )
            {
                /* Block din't fit into the cluster.
                   Cluster swap has been enforced... */
            }
            else
            {
                Fee_eJob = FEE_JOB_WRITE_DATA;
            }
        }
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif     
    return( eRetVal );
}

/**
* @brief        Write unaligned rest of Fee block data to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @pre          Fee_pJobWriteDataDestPtr must contain valid pointer to user buffer
* @post         Schedule FEE_JOB_WRITE_VALIDATE subsequent job
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteUnalignedData( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = 0U;
    VAR( uint16, AUTOMATIC ) uWriteOffset = 0U;
    VAR( uint16, AUTOMATIC ) uWriteLength = 0U;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    VAR( uint16, AUTOMATIC ) uClrGrp = 0U;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Index of cluster group the Fee block belongs to */
        uClrGrp = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;
    #endif

        /* Get size of Fee block */
        uBlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].blockSize;

        /* Calculate number of bytes already written */
        uWriteOffset = (uBlockSize / FEE_VIRTUAL_PAGE_SIZE) * FEE_VIRTUAL_PAGE_SIZE;

        /* Calculate length remaining data to write */
        uWriteLength = uBlockSize % FEE_VIRTUAL_PAGE_SIZE;

        /* @violates @ref Fee_c_REF_6 Array indexing shall be the
           only allowed form of pointer arithmetic */
            Fee_CopyDataToPageBuffer( Fee_pJobWriteDataDestPtr+uWriteOffset, Fee_aDataBuffer, uWriteLength );
    
    #if (FEE_LEGACY_MODE == STD_OFF)
        /* No special treatment of immediate data needed any more */
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Use ClrGrp info */
        uDataAddr = Fee_aClrGrpInfo[uClrGrp].uDataAddrIt;
        #else
        /* Use Block info because it has been updated */
        uDataAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr;
        #endif
    #else
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        if( Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        {
        #endif
            /* Use Block info because it has been updated into Fee_JobEraseImmediateDone */
            uDataAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr;
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        }
        else
        {
            /* Use ClrGrp info */
            uDataAddr = Fee_aClrGrpInfo[uClrGrp].uDataAddrIt;
        }
        #endif
    #endif

        if( ((Std_ReturnType)E_OK) ==
                Fls_Write( uDataAddr+uWriteOffset, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE )
          )
        {
            /* Fls write job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }

        /* Schedule write of validation pattern */
        Fee_eJob = FEE_JOB_WRITE_VALIDATE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif
    return( eRetVal );
}

/**
* @brief        Validate Fee block by writing validation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to validate
* @post         Schedule FEE_JOB_WRITE_DONE subsequent job
*
* @implements   Fee_JobWriteValidate_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteValidate( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = (Fls_AddressType)0;

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Index of cluster group the Fee block belongs to */
        uClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;
    #endif

        /* Serialize validation pattern to buffer */
        Fee_SerializeFlag( Fee_aDataBuffer, FEE_VALIDATED_VALUE );

    #if (FEE_LEGACY_MODE == STD_OFF)
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* Use ClrGrp info */
        uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt - (2U *  FEE_VIRTUAL_PAGE_SIZE);
        #else
        /* Use Block info */
        uHdrAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr - FEE_VIRTUAL_PAGE_SIZE;
        #endif
    #else
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        if( Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
        {
        #endif
            /* Use Block info because it has been updated into Fee_JobEraseImmediateDone */
            uHdrAddr = Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr - FEE_VIRTUAL_PAGE_SIZE;
        #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        }
        else
        {
            /* Use ClrGrp info */
            uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt - (2U *  FEE_VIRTUAL_PAGE_SIZE);
        }
        #endif
    #endif

        /* Write validation pattern to flash */
        if( ((Std_ReturnType)E_OK) == Fls_Write( uHdrAddr, Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE) )
        {
            /* Fls read job has been accepted */
            eRetVal = MEMIF_JOB_PENDING;
        }
        else
        {
            /* Fls write job hasn't been accepted */
            eRetVal = MEMIF_JOB_FAILED;
        }

        /* Finalize the write operation */
        Fee_eJob = FEE_JOB_WRITE_DONE;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif
    return( eRetVal );
}

/**
* @brief        Finalize validation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_VALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobWriteDone( void )
{
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = (Fls_AddressType)0;
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = (Fls_AddressType)0;
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;

    /* Index of cluster group the Fee block belongs to */
    uClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;

    /* Calculate data and header addresses */
    uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt;
    uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

    #if (FEE_LEGACY_MODE == STD_ON)
    /* @violates @ref Fee_c_REF_8 boolean expression required for logical operators. */
    if( (boolean)FALSE == Fee_BlockConfig[Fee_uJobBlockIndex].immediateData )
    #endif
    {
        /* Update the block address info */
        Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr = uDataAddr;
        Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr = uHdrAddr - FEE_VIRTUAL_PAGE_SIZE;
    }
#endif

    /* Mark the Fee block as valid */
    Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_VALID;

    /* No more Fls jobs to schedule */
    Fee_eJob = FEE_JOB_DONE;

    return( MEMIF_JOB_OK );
}

/**
* @brief        Invalidate Fee block by writing the invalidation flag to flash
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
* @retval       MEMIF_JOB_OK             The Fee block is already invalid
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to invalidate
* @post         Schedule FEE_JOB_DONE or FEE_JOB_INVAL_BLOCK_DONE subsequent
*               jobs
*
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlock( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

    if( FEE_BLOCK_INVALID == Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus )
    {
        /* No more subsequent Fls jobs to schedule */
        Fee_eJob = FEE_JOB_DONE;

        /* Fee job completed */
        eRetVal = MEMIF_JOB_OK;
    }
    else 
    {
        #if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_OFF)
        if( FEE_BLOCK_NEVER_WRITTEN == Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus )
        {
            /* set status as INVALID */
            Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INVALID;
            
            /* No more subsequent Fls jobs to schedule */
            Fee_eJob = FEE_JOB_DONE;

            /* Fee job completed */
            eRetVal = MEMIF_JOB_OK;   
        }
        else
        #endif
        {
            /* Serialize invalidation pattern to buffer */
            Fee_SerializeFlag( Fee_aDataBuffer, FEE_INVALIDATED_VALUE );

            /* Write invalidation pattern to flash */
            if( ((Std_ReturnType)E_OK) ==
                    Fls_Write( Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr,
                               Fee_aDataBuffer, FEE_VIRTUAL_PAGE_SIZE
                             )
              )
            {
                /* Fls read job has been accepted */
                eRetVal = MEMIF_JOB_PENDING;
            }
            else
            {
                /* Fls write job hasn't been accepted */
                eRetVal = MEMIF_JOB_FAILED;
            }

            /* Finalize the invalidation operation */
            Fee_eJob = FEE_JOB_INVAL_BLOCK_DONE;
        }
    }

    return( eRetVal );
}

/**
* @brief        Finalize invalidation of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex       must contain index of Fee block to
*                                        write to
* @post         change Fee block status to FEE_BLOCK_INVALID
* @post         Schedule FEE_JOB_DONE subsequent job
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobInvalBlockDone( void )
{
    /* Mark the Fee block as in valid */
    Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INVALID;

    /* No more subsequent Fls jobs to schedule */
    Fee_eJob = FEE_JOB_DONE;

    /* Fee job completed */
    return( MEMIF_JOB_OK );
}

/**
* @brief        Erase (pre-allocate) immediate Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_PENDING        Underlying Fls accepted the write job
* @retval       MEMIF_JOB_FAILED         Underlying Fls didn't accept write job
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to
*               pre-allocated
* @post         Initialize internal cluster swap sequence if requested block
*               doesn't fit into current cluster
* @post         Schedule FEE_JOB_ERASE_IMMEDIATE_DONE subsequent jobs
*
* @implements   Fee_JobEraseImmediate_Activity
*
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediate( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif
    #if (FEE_LEGACY_MODE == STD_OFF)
        #if (FEE_LEGACY_IMM_ERASE_MODE == STD_ON)
        /* Legacy mode enabled, Fee_JobEraseImmediate shall invalidate the block */
        if( FALSE == Fee_ReservedAreaWritable() )
        {
            /* In legacy mode, pronounce the block to be erased as invalidated and then force the swap */
            Fee_aBlockInfo[ Fee_uJobBlockIndex ].eBlockStatus = FEE_BLOCK_INVALID;
            Fee_uJobIntClrGrpIt = Fee_BlockConfig[ Fee_uJobBlockIndex ].clrGrp;              /* Get cluster group index */
            eRetVal = Fee_JobIntSwap();
        }
        else
        {
            /* Otherwise trigger invalidate operation (in legacy mode) */
            eRetVal = Fee_JobInvalBlock();
        }
        #else
        /* In standard mode, perform swap if reserved area has been touched, or do nothing. */
        if( FALSE == Fee_ReservedAreaWritable() )
        {
            /* Reserved area is not writable, force the swap */
            Fee_uJobIntClrGrpIt = Fee_BlockConfig[ Fee_uJobBlockIndex ].clrGrp;              /* Get cluster group index */
            eRetVal = Fee_JobIntSwap();
        }
        else
        {
            /* Do effectively nothing */
            Fee_eJob = FEE_JOB_DONE;
        }
        #endif
    #else           /* Original code */
        /* Write block header */
        eRetVal = Fee_JobWriteHdr();

        /* Schedule next job */
        if( FEE_JOB_INT_SWAP_CLR_FMT == Fee_eJob )
        {
            /* Block din't fit into the cluster. Cluster swap has been enforced... */
        }
        else
        {
            Fee_eJob = FEE_JOB_ERASE_IMMEDIATE_DONE;
        }
    #endif  /* (FEE_LEGACY_MODE == STD_OFF) */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif
    return( eRetVal );
}

/**
* @brief        Finalize erase (pre-allocation) of Fee block
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK
*
* @pre          Fee_uJobBlockIndex must contain index of Fee block to write to
* @post         change Fee block status to FEE_BLOCK_INCONSISTENT
* @post         Schedule FEE_JOB_DONE subsequent job
*
* @implements   Fee_JobEraseImmediateDone_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobEraseImmediateDone( void )
{
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uClrGrp = 0U;
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;
    
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)
    VAR( Fls_AddressType, AUTOMATIC ) uDataAddr = (Fls_AddressType)0;
    VAR( Fls_AddressType, AUTOMATIC ) uHdrAddr = (Fls_AddressType)0;
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
#endif

#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    if (Fee_uJobBlockIndex >= FEE_CRT_CFG_NR_OF_BLOCKS)
    {
        #if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/    
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        #endif
        /* set job as failed */
        eRetVal = MEMIF_JOB_FAILED;
        /* Call job error notification function */
        FEE_NVM_JOB_ERROR_NOTIFICATION 
    }
    else
    {
#endif
        /* Mark the Fee immediate block as inconsistent so it can be written later on */
        Fee_aBlockInfo[Fee_uJobBlockIndex].eBlockStatus = FEE_BLOCK_INCONSISTENT;

        /* Get size of Fee block */
        uBlockSize = Fee_BlockConfig[Fee_uJobBlockIndex].blockSize;

        /* Align Fee block size to the virtual page boundary */
        uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

        /* Index of cluster group the Fee block belongs to */
        uClrGrp = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_OFF)

        /* Index of cluster group the Fee block belongs to */
        uClrGrpIndex = Fee_BlockConfig[Fee_uJobBlockIndex].clrGrp;
        uDataAddr = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt - uAlignedBlockSize;
        uHdrAddr = Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

        /* Update the block address info */
        Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr = uDataAddr;
        Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr = (uHdrAddr + FEE_BLOCK_OVERHEAD) -
                                                              FEE_VIRTUAL_PAGE_SIZE;

    #endif

        /* Header has been written so update both header and data addresses */
        Fee_aClrGrpInfo[uClrGrp].uHdrAddrIt += FEE_BLOCK_OVERHEAD;
        Fee_aClrGrpInfo[uClrGrp].uDataAddrIt -= uAlignedBlockSize;

    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        /* As Fee immediate block is inconsistent
           it is not possible to get previous data, so update Block info */
        Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr = Fee_aClrGrpInfo[uClrGrp].uHdrAddrIt -
                                                              FEE_VIRTUAL_PAGE_SIZE;
        Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr = Fee_aClrGrpInfo[uClrGrp].uDataAddrIt;
    #endif
        /* No more subsequent Fls jobs to schedule */
        Fee_eJob = FEE_JOB_DONE;
        /* set job as ook */
        eRetVal = MEMIF_JOB_OK;
        /* Fee job completed */
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON) 
    }
#endif
    return( eRetVal );
}

/**
* @brief        Schedule subsequent jobs
*
* @return       MemIf_JobResultType
*
* @pre          Fee_eJob must contain type of job to schedule
*
* @implements   Fee_JobSchedule_Activity
*/
static FUNC( MemIf_JobResultType, FEE_CODE ) Fee_JobSchedule( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_FAILED;

    switch( Fee_eJob )
    {
        /* Fee_Read() related jobs */
        case FEE_JOB_READ:
            eRetVal = Fee_JobRead();
            break;  
        /* Fee_Write() related jobs */
        case FEE_JOB_WRITE:
            eRetVal = Fee_JobWrite();
            break;

        case FEE_JOB_WRITE_DATA:
            eRetVal = Fee_JobWriteData();
            break;

        case FEE_JOB_WRITE_UNALIGNED_DATA:
            eRetVal = Fee_JobWriteUnalignedData();
            break;

        case FEE_JOB_WRITE_VALIDATE:
            eRetVal = Fee_JobWriteValidate();
            break;

        case FEE_JOB_WRITE_DONE:
            eRetVal = Fee_JobWriteDone();
            break;

        /* Fee_InvalidateBlock() related jobs */
        case FEE_JOB_INVAL_BLOCK:
            eRetVal = Fee_JobInvalBlock();
            break;

        case FEE_JOB_INVAL_BLOCK_DONE:
            eRetVal = Fee_JobInvalBlockDone();
            break;

        /* Fee_EraseImmediateBlock() related jobs */
        case FEE_JOB_ERASE_IMMEDIATE:
            eRetVal = Fee_JobEraseImmediate();
            break;

        case FEE_JOB_ERASE_IMMEDIATE_DONE:
            eRetVal = Fee_JobEraseImmediateDone();
            break;

        /* Fee_Init() related jobs */
        case FEE_JOB_INT_SCAN:
            eRetVal = Fee_JobIntScan();
            break;

        case FEE_JOB_INT_SCAN_CLR:
            eRetVal = Fee_JobIntScanClr();
            break;

        case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
            eRetVal = Fee_JobIntScanClrHdrParse( (boolean)TRUE );
            break;

        case FEE_JOB_INT_SCAN_CLR_FMT:
            eRetVal = Fee_JobIntScanClrFmt();
            break;

        case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
            eRetVal = Fee_JobIntScanClrFmtDone();
            break;

        case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
            eRetVal = Fee_JobIntScanBlockHdrParse( (boolean)TRUE );
            break;

        /* Swap related jobs */
        case FEE_JOB_INT_SWAP_CLR_FMT:
            eRetVal = Fee_JobIntSwapClrFmt();
            break;

        case FEE_JOB_INT_SWAP_BLOCK:
            eRetVal = Fee_JobIntSwapBlock();
            break;

        case FEE_JOB_INT_SWAP_DATA_READ:
            eRetVal = Fee_JobIntSwapDataRead( (boolean)TRUE );
            break;

        case FEE_JOB_INT_SWAP_DATA_WRITE:
            eRetVal = Fee_JobIntSwapDataWrite( (boolean)TRUE );
            break;

        case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
            eRetVal = Fee_JobIntSwapClrVldDone();
            break;

        /* if the job is finished switch case will break */
        case FEE_JOB_DONE:
            /* Do nothing */
            break;

        default:
            /* Compiler_Warning: This default branch will never be reached in FTE */
            break;
    }

    return( eRetVal );
}

#if (FEE_LEGACY_MODE == STD_OFF)
/**
* @brief Checks whether the block specified by Fee_JobBlockIndex is writable into the reserved area.
*
* @return sint8
* @retval TRUE The block is writable into the reserved area.
* @retval FALSE The block is not writable into the reserved area.
*
* @pre Fee_JobBlockIndex must contain index of Fee block to be written
* @pre Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt must be up to date
* @pre Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt must be up to date
*
* @implements   Fee_ReservedAreaWritable_Activity
*
*/
static FUNC( sint8, FEE_CODE ) Fee_ReservedAreaWritable( void )
{
    VAR( sint8, AUTOMATIC ) sRetVal = TRUE;
    VAR( uint16, AUTOMATIC ) uBlockSize = 0U;
    VAR( uint16, AUTOMATIC ) uAlignedBlockSize = 0U;
    VAR( Fls_LengthType, AUTOMATIC ) uAvailClrSpace = 0UL;
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = (uint8)0;
    VAR( uint32, AUTOMATIC ) uReservedSpace = 0UL;
    VAR( boolean, AUTOMATIC ) bImmediateData = (boolean)FALSE;
#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
    VAR( sint8, AUTOMATIC ) sIsReservedAreaTouched = TRUE;
#endif

    /* Index of cluster group the Fee block belongs to */
    uClrGrpIndex = Fee_GetBlockClusterGrp(Fee_uJobBlockIndex);

    /* Reserved space of cluster group*/
    uReservedSpace = Fee_ClrGrps[uClrGrpIndex].reservedSize;

    /* Calculate available space in active cluster */
    uAvailClrSpace = Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt -
                     Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt;

    /* Get size of Fee block */
    uBlockSize = Fee_GetBlockSize(Fee_uJobBlockIndex);

    /* Align Fee block size to the virtual page boundary */
    uAlignedBlockSize = Fee_AlignToVirtualPageSize( uBlockSize );

    /* Hard Stop condition: One FEE_BLOCK_OVERHEAD must be left blank to have a clear separation
       between header block space and data block space */
    if( (((uint32)uAlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD)) > uAvailClrSpace )
    {
        sRetVal = FALSE;
    }
    else if( (((uint32)uAlignedBlockSize) + (2U * FEE_BLOCK_OVERHEAD) + uReservedSpace) >
             uAvailClrSpace
           )
    {
        bImmediateData = Fee_GetBlockImmediate(Fee_uJobBlockIndex);
        /* Block targets reserved area */
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
        sIsReservedAreaTouched = Fee_ReservedAreaTouchedByBlock( Fee_uJobBlockIndex );
        if( ((boolean)TRUE == bImmediateData) &&
            (FALSE == sIsReservedAreaTouched ) \
          )
    #else
        if( (boolean)TRUE == bImmediateData )
    #endif
        {
            /* Immediate block - only writable if not already present in the reserved area */
            if( (0UL == Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr) &&
                (0UL == Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr)
              )
            {
                /* The block is not written in the cluster at all => writable */
                sRetVal = TRUE;
            }
            else
            {
                /* The block is written in the cluster - is it written in the reserved area? */
                if( (FEE_BLOCK_OVERHEAD + uReservedSpace) >
                    (Fee_aBlockInfo[Fee_uJobBlockIndex].uDataAddr -
                       (Fee_aBlockInfo[Fee_uJobBlockIndex].uInvalidAddr + FEE_VIRTUAL_PAGE_SIZE)
                    )
                  )
                {
                    /* The block is already written in the reserved area */
                    sRetVal = FALSE;
                }
                else
                {
                   /* The block is not written in the reserved area */
                   sRetVal = TRUE;
                }
            }
        }
        else
        {
    #if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON)
            /* Non-immediate block or immediate block for which an attempt for a write to the
               Reserved area was made is not writable into reserved area */
    #else
            /* Non-immediate block is not writable into reserved area */
    #endif
            sRetVal = FALSE;
        }
    }
    else
    {
        /* Block does not target reserved area */
        sRetVal = TRUE;
    }
    return sRetVal;
}
#endif /* FEE_LEGACY_MODE == STD_OFF */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Service to initialize the FEE module.
* @details      The function Fee_Init shall initialize the Flash EEPROM
*               Emulation module.
*
* @pre          The FEE module'  s environment shall not call the function
*               Fee_Init shall during a running operation of the FEE module.
* @note         The function Autosar Service ID[hex]: 0x00.
* @note         Synchronous
* @note         Non Reentrant
*
* @api
*
* @implements   Fee_Init_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_Init(P2CONST( Fee_ConfigType, AUTOMATIC, FEE_APPL_CONST ) paConfigPtr)
{
   VAR( uint32, AUTOMATIC ) uInvalIndex = 0U;

#if (FEE_DEV_ERROR_DETECT == STD_ON)   
    if (NULL_PTR != paConfigPtr)
    {
       /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
       Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_INIT_ID, FEE_E_PARAM_POINTER); 
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID, FEE_E_BUSY );
    }
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INIT_ID, FEE_E_BUSY_INTERNAL);
    }
    else
#else
        (void)paConfigPtr;
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    {
        /* Initialize all block info records */
        for( uInvalIndex = 0U; uInvalIndex < FEE_MAX_NR_OF_BLOCKS; uInvalIndex++ )
        {
#if (FEE_MARK_EMPTY_BLOCKS_INVALID == STD_ON)
            /* for blocks which were never written Fee returns INVALID status */
            Fee_aBlockInfo[uInvalIndex].eBlockStatus = FEE_BLOCK_INVALID;
#else
            /* for blocks which were never written Fee returns INCONSISTENT status */
            Fee_aBlockInfo[uInvalIndex].eBlockStatus = FEE_BLOCK_NEVER_WRITTEN;
#endif

#if (FEE_LEGACY_MODE == STD_OFF)
            Fee_aBlockInfo[uInvalIndex].uDataAddr = 0U;
            Fee_aBlockInfo[uInvalIndex].uInvalidAddr = 0U;
#endif
        }
        
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)
        /* Initialize all foreign block config records */
        for( uInvalIndex = 0U; uInvalIndex < (FEE_MAX_NR_OF_BLOCKS - FEE_CRT_CFG_NR_OF_BLOCKS); uInvalIndex++ )
        {
            Fee_aForeignBlockConfig[uInvalIndex].blockNumber = 0U;
            Fee_aForeignBlockConfig[uInvalIndex].blockSize = 0U;
            Fee_aForeignBlockConfig[uInvalIndex].clrGrp = 0U;
            Fee_aForeignBlockConfig[uInvalIndex].immediateData = (boolean)FALSE;
            Fee_aForeignBlockConfig[uInvalIndex].blockAssignment = FEE_PROJECT_RESERVED;
        }
#endif
        /* Invalidate all cluster groups */
        for( uInvalIndex = 0U; uInvalIndex < FEE_NUMBER_OF_CLUSTER_GROUPS; uInvalIndex++ )
        {
            Fee_aClrGrpInfo[uInvalIndex].uActClrID = 0U;
        }

#if (FEE_BLOCK_ALWAYS_AVAILABLE == STD_ON) && (FEE_LEGACY_MODE == STD_OFF)
        Fee_UntouchReservedAreaAll();
#endif

        /* Schedule init job */
        Fee_eJob = FEE_JOB_INT_SCAN;

        Fee_eModuleStatus = MEMIF_BUSY_INTERNAL;

        Fee_eJobResult = MEMIF_JOB_PENDING;
#if (FEE_SWAP_FOREIGN_BLOCKS_ENABLED == STD_ON)   
        Fee_uForeignBlocksNumber = 0U;
#endif
    }
}

#if ((FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__))
/**
* @brief        Set the Fee module' s operation mode to the given Mode.
* @details      Call the Fls_SetMode function of the underlying flash driver.
*
* @param[in]    Mode (Either MEMIF_MODE_FAST or MEMIF_MODE_SLOW)
*
* @pre          The module must be initialized and not busy.
*
* @note         The function Autosar Service ID[hex]: 0x01.
* @note         Synchronous
* @note         Non Reentrant
*
* @api
*
* @implements   Fee_SetMode_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_SetMode( VAR( MemIf_ModeType, AUTOMATIC) eMode )
{
    #if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID, FEE_E_UNINIT );
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID, FEE_E_BUSY );
    }
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_SETMODE_ID, FEE_E_BUSY_INTERNAL);
    }
    else
    #else
        if( MEMIF_IDLE == Fee_eModuleStatus )
    #endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        {
            Fls_SetMode( eMode );
        }
}
#endif /* (FEE_SETMODE_API_SUPPORTED == STD_ON) || defined(__DOXYGEN__) */

/**
* @brief        Service to initiate a read job.
* @details      The function Fee_Read shall take the block start address and
*               offset and calculate the corresponding memory read address.
*
* @param[in]    uBlockNumber     Number of logical block, also denoting
*                                start address of that block in flash memory.
* @param[in]    uBlockOffset     Read address offset inside the block.
* @param[out]   pDataBufferPtr   Pointer to data buffer.
* @param[in]    uLength          Number of bytes to read.
*
* @pre          The module must be initialized, not busy, uBlockNumber must be
*               valid, uLength != 0, pDataBufferPtr != NULL_PTR, uBlockOffset and
*               (uBlockOffset + uLength - 1) must be in range.
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockOffset,
*               Fee_uJobBlockLength, Fee_uJobBlockIndex, Fee_pJobReadDataDestPtr,
*               Fee_eJob, Fee_eJobResult job control internal variables.
*
* @return       Std_ReturnType
* @retval       E_OK             The read job was accepted by the
*                                underlying memory driver.
* @retval       E_NOT_OK         The read job has not been accepted
*                                by the underlying memory driver.
* @note         The function Autosar Service ID[hex]: 0x02.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_Read_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_Read
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber,
        VAR( uint16, AUTOMATIC ) uBlockOffset,
        P2VAR( uint8, AUTOMATIC, FEE_APPL_DATA ) pDataBufferPtr,
        VAR( uint16, AUTOMATIC ) uLength
    )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_00();
    
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_BUSY_INTERNAL);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else if( 0xFFFFU == uBlockIndex )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( uBlockOffset >= Fee_BlockConfig[uBlockIndex].blockSize )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_OFS);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if((0U == uLength) || ((uBlockOffset+uLength) > Fee_BlockConfig[uBlockIndex].blockSize))
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_INVALID_BLOCK_LEN);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pDataBufferPtr )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_READ_ID, FEE_E_PARAM_POINTER);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {

        /* Configure the read job */
        Fee_uJobBlockIndex = uBlockIndex;

        Fee_uJobBlockOffset = uBlockOffset;

        Fee_uJobBlockLength = uLength;
        Fee_pJobReadDataDestPtr = pDataBufferPtr;

        Fee_eJob = FEE_JOB_READ;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the read job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
    }
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_00();

    return( uRetVal );
}

/**
* @brief        Service to initiate a write job.
* @details      The function Fee_Write shall take the block start address and
*               calculate the corresponding memory write address. The block
*               address offset shall be fixed to zero.
*               The function Fee_Write shall copy the given or computed
*               parameters to module internal variables, initiate a write job,
*               set the FEE module status to MEMIF_BUSY, set the job result to
*               MEMIF_JOB_PENDING and return with E_OK.The FEE module shall
*               execute the write job of the function Fee_Write
*               asynchronously within the FEE module' s main function.
*
* @param[in]    uBlockNumber     Number of logical block, also denoting
*                                start address of that block in emulated
*                                EEPROM.
* @param[out]   pDataBufferPtr   Pointer to data buffer.
*
* @return       Std_ReturnType
* @retval       E_OK             The write job was accepted by the
*                                underlying memory driver.
* @retval       E_NOT_OK         The write job has not been accepted by
*                                the underlying memory driver.
*
* @pre          The module must be initialized, not busy, uBlockNumber must be
*               valid, and pDataBufferPtr != NULL_PTR.
*               Before call the function "Fee_Write" for immediate date must be
*               called the function "Fee_EraseImmediateBlock".
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockIndex,
*               Fee_pJobWriteDataDestPtr, Fee_eJob, Fee_eJobResult job control internal
*               variables.
* @note         The function Autosar Service ID[hex]: 0x03.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_Write_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_Write
    (
        VAR( uint16, AUTOMATIC ) uBlockNumber,
        P2CONST( uint8, AUTOMATIC, FEE_APPL_CONST ) pDataBufferPtr
    )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_01();
    
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_UNINIT );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_BUSY );
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else if( 0xFFFFU == uBlockIndex )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_WRITE_ID, FEE_E_BUSY_INTERNAL);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pDataBufferPtr )
    {
       /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_WRITE_ID, FEE_E_PARAM_POINTER);

        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {

        /* Configure the write job */
        Fee_uJobBlockIndex = uBlockIndex;
        Fee_pJobWriteDataDestPtr = pDataBufferPtr;

        Fee_eJob = FEE_JOB_WRITE;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the write job */
        Fee_eJobResult = MEMIF_JOB_PENDING;

    }
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_01();

    return( uRetVal );
}

/**
* @brief        Service to call the cancel function of the underlying flash
*               driver.
* @details      The function Fee_Cancel and the cancel function of the
*               underlying flash driver are asynchronous w.r.t. an ongoing
*               read, erase or write job in the flash memory.
*
* @pre          The module must be initialized.
* @post         Changes Fee_eModuleStatus module status and job result
*               Fee_eJobResult internal variables.
* @note         The function Autosar Service ID[hex]: 0x04.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_Cancel_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_Cancel( void )
{

/* If FEE_CANCEL_API == STD_OFF Fee_Cancel set only a Det Error Notification
   Note: this is to avoid robustness issues (in term of internal variables) */
#if (FEE_CANCEL_API == STD_OFF)
    #if (FEE_DEV_ERROR_DETECT == STD_ON)
    /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
    Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_CANCEL_API );
    #endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#else

    #if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_UNINIT );
    }
    else
    {
    #endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        if( MEMIF_JOB_PENDING == Fee_eJobResult )
        {
            /* Cancel ongoing Fls job if any */
            if( MEMIF_BUSY == Fee_eModuleStatus )
            {
                Fee_eJobResult = MEMIF_JOB_CANCELED;
                Fee_eJob = FEE_JOB_DONE;
                Fls_Cancel();
                Fee_eModuleStatus = MEMIF_IDLE;

                /* No notifications from internal jobs */
            }
            else
            {
    #if (FEE_DEV_ERROR_DETECT == STD_ON)
                /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
                Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_CANCEL_ID, FEE_E_INVALID_CANCEL);
    #endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
                /* Call job error notification function */
                FEE_NVM_JOB_ERROR_NOTIFICATION
            }
        }
        else
        {
            /* Leave the job result unchanged */
        }

    #if (FEE_DEV_ERROR_DETECT == STD_ON)
    }
    #endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

#endif    /* FLS_CANCEL_API == STD_ON */
}

/**
* @brief        Return the Fee module state.
* @details      Return the Fee module state synchronously.
*
* @note         The function Autosar Service ID[hex]: 0x05.
* @note         Synchronous
* @note         Non Reentrant
*
* @return       Fee_eModuleStatus
* @retval       MEMIF_UNINIT             Module has not been initialized (yet).
* @retval       MEMIF_IDLE               Module is currently idle.
* @retval       MEMIF_BUSY               Module is currently busy.
* @retval       MEMIF_BUSY_INTERNAL      Module is busy with internal management
*                                        operations.
*
* @api
*
* @implements   Fee_GetStatus_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_StatusType, FEE_CODE ) Fee_GetStatus( void )
{
    return( Fee_eModuleStatus );
}

/**
* @brief        Return the result of the last job.
* @details      Return the result of the last job synchronously.
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK              The job has been finished successfully.
* @retval       MEMIF_JOB_FAILED          The job has not been finished
*                                         successfully.
* @retval       MEMIF_JOB_PENDING         The job has not yet been finished.
* @retval       MEMIF_JOB_CANCELED        The job has been canceled.
* @retval       MEMIF_BLOCK_INCONSISTENT  The requested block is inconsistent,
*                                         it may contain corrupted data.
* @retval       MEMIF_BLOCK_INVALID       The requested block has been invalidated,
*                                         the requested read operation can not be performed.
* @note         The function Autosar Service ID[hex]: 0x06.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_GetJobResult_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_JobResultType, FEE_CODE ) Fee_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = Fee_eJobResult;

#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETJOBRESULT_ID, FEE_E_UNINIT);
        eRetVal = MEMIF_JOB_FAILED;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

    return( eRetVal );
}

/**
* @brief        Service to invalidate a logical block.
*
* @param[in]    uBlockNumber     Number of logical block, also denoting
*                                start address of that block in flash memory
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the
*                                underlying memory driver.
*
* @pre          The module must be initialized, not busy, and uBlockNumber must be
*               valid
*
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockIndex,
*               Fee_eJob, and Fee_eJobResult job control internal variables.
*               EEPROM.
* @note         The function Autosar Service ID[hex]: 0x07.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_InvalidateBlock_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_InvalidateBlock( VAR( uint16, AUTOMATIC ) uBlockNumber )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_NOT_OK;
    VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_02();
    
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_UNINIT);
    }
    else if( 0xFFFFU == uBlockIndex )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY );
    }
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_INVALIDATEBLOCK_ID, FEE_E_BUSY_INTERNAL);
    }
    else
#else
        if( MEMIF_IDLE == Fee_eModuleStatus )
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        {

            /* Configure the invalidate block job */
            Fee_uJobBlockIndex = uBlockIndex;

            Fee_eJob = FEE_JOB_INVAL_BLOCK;

            Fee_eModuleStatus = MEMIF_BUSY;

            /* Execute the invalidate block job */
            Fee_eJobResult = MEMIF_JOB_PENDING;

            uRetVal = (Std_ReturnType)E_OK;
        }  
        
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_02();

    return( uRetVal );
}

/* @implements  FEE_VERSION_INFO_API==STD_ON_ActivityPartition */
#if ((FEE_VERSION_INFO_API == STD_ON) || defined(__DOXYGEN__))
/**
* @brief        Return the version information of the Fee module.
* @details      The version information includes: Module Id, Vendor Id,
*               Vendor specific version numbers.
*
* @param[out]   pVersionInfoPtr  Pointer to where to store the version
*                                information of this module .
*
* @pre          pVersionInfoPtr must not be NULL_PTR.
* @note         The function Autosar Service ID[hex]: 0x08.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_GetVersionInfo_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_GetVersionInfo
    (
        P2VAR( Std_VersionInfoType, AUTOMATIC, FEE_APPL_DATA ) pVersionInfoPtr
    )
{
    #if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( NULL_PTR == pVersionInfoPtr )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_GETVERSIONINFO_ID, FEE_E_PARAM_POINTER);

    }
    else
    {
    #endif /* FEE_DEV_ERROR_DETECT == STD_ON */
        pVersionInfoPtr->moduleID = (uint16)FEE_MODULE_ID;
        pVersionInfoPtr->vendorID = (uint16)FEE_VENDOR_ID;
        pVersionInfoPtr->sw_major_version = (uint8)FEE_SW_MAJOR_VERSION;
        pVersionInfoPtr->sw_minor_version = (uint8)FEE_SW_MINOR_VERSION;
        pVersionInfoPtr->sw_patch_version = (uint8)FEE_SW_PATCH_VERSION;
    #if (FEE_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FEE_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FEE_VERSION_INFO_API == STD_ON */

/**
* @brief        Service to erase a logical block.
* @details      The function Fee_EraseImmediateBlock shall take the block number
*               and calculate the corresponding memory block address.
*               The function Fee_EraseImmediateBlock shall ensure that the FEE
*               module can write immediate data. Whether this involves
*               physically erasing a memory area and therefore calling the erase
*               function of the underlying driver depends on the implementation.
*               If development error detection for the FEE module is enabled,
*               the function Fee_EraseImmediateBlock shall check whether the
*               addressed logical block is configured as containing immediate
*               data (configuration parameter FeeImmediateData == TRUE).
*               If not, the function Fee_EraseImmediateBlock
*               shall report the error code FEE_E_INVALID_BLOCK_NO.
*
* @param[in]    uBlockNumber     Number of logical block, also denoting.
*
* @return       Std_ReturnType
* @retval       E_OK             The job was accepted by the underlying
*                                memory driver.
* @retval       E_NOT_OK         The job has not been accepted by the underlying
*                                memory driver.
*                                start address of that block in emulated EEPROM.
*
* @pre          The module must be initialized, not busy, uBlockNumber must be
*               valid, and type of Fee block must be immediate.
* @post         changes Fee_eModuleStatus module status and Fee_uJobBlockIndex,
*               Fee_eJob, and Fee_eJobResult job control internal variables.
*
* @note         The function Autosar Service ID[hex]: 0x09.
* @note         Asynchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_EraseImmediateBlock_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_EraseImmediateBlock( VAR( uint16, AUTOMATIC ) uBlockNumber )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;
    VAR( uint16, AUTOMATIC ) uBlockIndex = Fee_GetBlockIndex( uBlockNumber );

    /* Start of exclusive area. Implementation depends on integrator. */
    SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_03();
    
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_UNINIT);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( 0xFFFFU == uBlockIndex )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( (boolean)FALSE == Fee_BlockConfig[uBlockIndex].immediateData )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_INVALID_BLOCK_NO);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_ERASEIMMEDIATEBLOCK_ID, FEE_E_BUSY_INTERNAL);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        /* Configure the erase immediate block job */
        Fee_uJobBlockIndex = uBlockIndex;

        Fee_eJob = FEE_JOB_ERASE_IMMEDIATE;

        Fee_eModuleStatus = MEMIF_BUSY;

        /* Execute the erase immediate block job */
        Fee_eJobResult = MEMIF_JOB_PENDING;
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    
    /* End of exclusive area. Implementation depends on integrator. */
    SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_03();

    return( uRetVal );
}

/**
* @brief        Service to report the FEE module the successful end of
*               an asynchronous operation.
* @details      The underlying flash driver shall call the function
*               Fee_JobEndNotification to report the successful end of
*               an asynchronous operation.
*
* @pre          The module must be initialized.
* @post         Changes Fee_eModuleStatus module status and Fee_eJobResult
*               internal variables.
* @note         The function Autosar Service ID[hex]: 0x10.
* @note         Synchronous.
* @note         Non Reentrant
*
* @api
*
* @implements   Fee_JobEndNotification_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_JobEndNotification( void )
{
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
     #if (FEE_DEV_ERROR_DETECT == STD_ON)     
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_JOBENDNOTIFICATION_ID, FEE_E_UNINIT);
     #else
         /* Do nothing. Fee is not initialized */
     #endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {        
        if( FEE_JOB_DONE == Fee_eJob )
        {
            /* Last schedule Fls job finished */
            Fee_eJobResult = Fls_GetJobResult();
    
            if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
            {
                /* no notifications from internal jobs */
                Fee_eModuleStatus = MEMIF_IDLE;
            }
            else
            {
                Fee_eModuleStatus = MEMIF_IDLE;
    
                /* Call job end notification function */
                FEE_NVM_JOB_END_NOTIFICATION
            }
        }
        else
        {
            Fee_eJobResult = Fee_JobSchedule();
    
            if( MEMIF_JOB_OK == Fee_eJobResult )
            {
                if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
                {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_IDLE;
                }
                else
                {
                    Fee_eModuleStatus = MEMIF_IDLE;
    
                    /* Call job end notification function */
                    FEE_NVM_JOB_END_NOTIFICATION
                }
            }
            else if( MEMIF_JOB_PENDING == Fee_eJobResult )
            {
                /* Nothing to do (ongoing Fls job) */
            }
            else
            {
                if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
                {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_IDLE;
                }
                else
                {
                    Fee_eModuleStatus = MEMIF_IDLE;
    
                    /* Call job error notification function */
                    FEE_NVM_JOB_ERROR_NOTIFICATION
                }
            }
        }
    }
}

/**
* @brief        Service to report the FEE module the failure of
*               an asynchronous operation.
* @details      The underlying flash driver shall call the function
*               Fee_JobErrorNotification to report the failure of
*               an asynchronous operation.
*
* @pre          The module must be initialized.
* @post         Changes Fee_eModuleStatus module status and Fee_eJobResult
*               internal variables.
* @note         The function Autosar Service ID[hex]: 0x11.
* @note         Synchronous.
* @note         Non Reentrant.
*
* @api
*
* @implements   Fee_JobErrorNotification_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_JobErrorNotification( void )
{
    VAR( uint8, AUTOMATIC ) uClrGrpIndex = 0U;
    
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
     #if (FEE_DEV_ERROR_DETECT == STD_ON)     
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_JOBERRORNOTIFICATION_ID, FEE_E_UNINIT);
     #else
         /* Do nothing. Fee is not initialized */
     #endif  /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else
    {
        if( MEMIF_JOB_CANCELED == Fee_eJobResult )
        {
            /* Fls job has been canceled. Do nothing in this callback.
            The NvM_JobErrorNotification() callback will be called from
            the Fee_Cancel()function which called the Fls_Cancel() function */
        }
        else
        {
            switch( Fee_eJob )
            {
                /* Error while reading block header. Treat block header as
                    invalid and    stop reading further block headers */
                case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
                    Fee_eJobResult = Fee_JobIntScanBlockHdrParse( (boolean)FALSE );
                    break;
    
                /* Error while reading cluster header. Treat cluster as
                    invalid and    move on to next cluster */
                case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
                    Fee_eJobResult = Fee_JobIntScanClrHdrParse( (boolean)FALSE );
                    break;
    
                /* Error while reading data from source cluster.
                    Leave block as INCONSISTENT and move on to next block */
                case FEE_JOB_INT_SWAP_DATA_WRITE:
                    Fee_eJobResult = Fee_JobIntSwapDataWrite( (boolean)FALSE );
                    break;
                /* for all the following cases based on the Fee module status error notification will
                be called */
                case FEE_JOB_WRITE:
                case FEE_JOB_WRITE_DATA:
                case FEE_JOB_WRITE_UNALIGNED_DATA:
                case FEE_JOB_ERASE_IMMEDIATE:
                case FEE_JOB_ERASE_IMMEDIATE_DONE:
                case FEE_JOB_WRITE_VALIDATE:
                case FEE_JOB_WRITE_DONE:
                {
                    uClrGrpIndex = Fee_GetBlockClusterGrp(Fee_uJobBlockIndex);
      
                    /* Something wrong in FlashMemory (cluster swap occurs to next write) */
                    Fee_aClrGrpInfo[uClrGrpIndex].uDataAddrIt =
                        Fee_aClrGrpInfo[uClrGrpIndex].uHdrAddrIt +
                        (2U * FEE_BLOCK_OVERHEAD);
                }
                /* @violates @ref Fee_c_REF_A control flows into case/default. */
    
                case FEE_JOB_READ:          
                case FEE_JOB_INVAL_BLOCK:
                case FEE_JOB_INVAL_BLOCK_DONE:
                case FEE_JOB_INT_SCAN:
                case FEE_JOB_INT_SCAN_CLR:
                case FEE_JOB_INT_SCAN_CLR_FMT:
                case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
                case FEE_JOB_INT_SWAP_BLOCK:
                case FEE_JOB_INT_SWAP_CLR_FMT:
                case FEE_JOB_INT_SWAP_DATA_READ:
                case FEE_JOB_INT_SWAP_CLR_VLD_DONE:
                case FEE_JOB_DONE:
                default:
                    Fee_eJobResult = Fls_GetJobResult();
    
                    if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
                    {
                        /* No notifications from internal jobs */
                        Fee_eModuleStatus = MEMIF_IDLE;
                    }
                    else
                    {
                        Fee_eModuleStatus = MEMIF_IDLE;
    
                        /* Call job error notification function */
                        FEE_NVM_JOB_ERROR_NOTIFICATION
                    }
                    break;
            }
        }
    }
}

/**
* @brief        Service to handle the requested read, write, or erase jobs
*               respectively the internal management operations.
* @details      The function shall asynchronously handle the requested
*               read, write, or erase jobs respectively the internal management operations.
*               The function shall check, whether
*               the block requested for reading has been invalidated by the
*               upper layer module.
*               If so, the function shall set the job result to
*               MEMIF_BLOCK_INVALID and call the error notification routine
*               of the upper layer if configured.
*               The function shall check the consistency of the logical block
*               being read before notifying the caller. If an inconsistency
*               of the read data is detected, the function
*               shall set the job result to MEMIF_BLOCK_INCONSISTENT and call
*               the error notification routine of the upper layer.
* @pre          The module must be initialized.
* @note         The function Autosar Service ID[hex]: 0x12.
*
* @api
*
* @implements   Fee_MainFunction_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_MainFunction( void )
{
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_MAINFUNCTION_ID, FEE_E_UNINIT);
    }
    else
    {
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */

        if( MEMIF_JOB_PENDING == Fee_eJobResult )
        {

            switch( Fee_eJob )
            {
                /* for all the following jobs subsequent jobs will be called in Fee job schedule
                   function based on Job */
                case FEE_JOB_INT_SCAN:
                case FEE_JOB_READ:          
                case FEE_JOB_WRITE:
                case FEE_JOB_INVAL_BLOCK:
                case FEE_JOB_ERASE_IMMEDIATE:
                    Fee_eJobResult = Fee_JobSchedule();
                    break;
               /* for all the following jobs job end or job error notification will be called
                  based on the job result  */
                case FEE_JOB_WRITE_DATA:
                case FEE_JOB_WRITE_UNALIGNED_DATA:
                case FEE_JOB_WRITE_VALIDATE:
                case FEE_JOB_WRITE_DONE:
                case FEE_JOB_INVAL_BLOCK_DONE:
                case FEE_JOB_ERASE_IMMEDIATE_DONE:
                case FEE_JOB_INT_SCAN_CLR_HDR_PARSE:
                case FEE_JOB_INT_SCAN_CLR:
                case FEE_JOB_INT_SCAN_CLR_FMT:
                case FEE_JOB_INT_SCAN_CLR_FMT_DONE:
                case FEE_JOB_INT_SCAN_BLOCK_HDR_PARSE:
                case FEE_JOB_INT_SWAP_BLOCK:
                case FEE_JOB_INT_SWAP_CLR_FMT:
                case FEE_JOB_INT_SWAP_DATA_READ:
                case FEE_JOB_INT_SWAP_DATA_WRITE:
                case FEE_JOB_INT_SWAP_CLR_VLD_DONE:               
                case FEE_JOB_DONE:
                default:
                    /* Internal or subsequent job */
                    break;
            }

            if( MEMIF_JOB_PENDING == Fee_eJobResult )
            {
                /* Nothing to do */
            }
            else if( MEMIF_JOB_OK == Fee_eJobResult )
            {
                if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
                {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_IDLE;
                }
                else
                {
                    Fee_eModuleStatus = MEMIF_IDLE;

                    /* Call job end notification function */
                    FEE_NVM_JOB_END_NOTIFICATION
                }
            }
            else
            {
                if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
                {
                    /* no notifications from internal jobs */
                    Fee_eModuleStatus = MEMIF_IDLE;
                }
                else
                {
                    Fee_eModuleStatus = MEMIF_IDLE;

                    /* Call job error notification function */
                    FEE_NVM_JOB_ERROR_NOTIFICATION
                }
            }
        }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
}

/**
* @brief        Service to read runtime information in the selected cluster.
*
* @param[in]    uClrGrpIndex    Index of the selected cluster group

* @return       Fee_ClusterGroupRuntimeInfoType
* @retval       current cluster total size
* @retval       current cluster available space.
* @retval       the block header overhead (blk header, valid flag and inval flag),
* @retval       the virtual page size (the size of an allocation unit)
* @retval       number of cluster swap already performed
*
* @pre          The module must be initialized, not busy and uClrGrpIndex must be valid
*
* @api
*
* @implements   Fee_GetRunTimeInfo_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FEE_CODE ) Fee_GetRunTimeInfo
    (
        VAR( uint8, AUTOMATIC ) uClrGrpIndex,
        P2VAR( Fee_ClusterGroupRuntimeInfoType, AUTOMATIC,FEE_APPL_DATA ) pClrGrpRTInfo
    )
{
    VAR( uint32, AUTOMATIC ) uActiveClrIndex = 0U;

    /* DET Check for cluster group should be added:
        - INITIALIZED driver
        - BUSY and BUSY_INTERNAL driver
        - Cluster group valid
    */
    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
    else if ( NULL_PTR == pClrGrpRTInfo)
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID,FEE_GETRUNTIMEINFO_ID, FEE_E_PARAM_POINTER);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */  
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_BUSY);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_BUSY_INTERNAL);
    }
    /* Cluster group index in valid range */
    else if( FEE_NUMBER_OF_CLUSTER_GROUPS <= uClrGrpIndex )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_GETRUNTIMEINFO_ID, FEE_E_CLUSTER_GROUP_IDX);
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {
        /* Get active cluster index for selected cluster group */
        uActiveClrIndex = Fee_aClrGrpInfo[ uClrGrpIndex ].uActClr;

        /* Size of the active cluster in selected cluster group */
        pClrGrpRTInfo->clusterTotalSpace =
            /* @violates @ref Fee_c_REF_6 Array indexing shall be the only
               allowed form of pointer arithmetic. */
            Fee_ClrGrps[ uClrGrpIndex ].clrPtr[ uActiveClrIndex ].length;

        pClrGrpRTInfo->clusterFreeSpace =
                Fee_aClrGrpInfo[ uClrGrpIndex ].uDataAddrIt -
                (Fee_aClrGrpInfo[ uClrGrpIndex ].uHdrAddrIt + (2U*FEE_BLOCK_OVERHEAD));

        pClrGrpRTInfo->blockHeaderOverhead  = (uint8)FEE_CLUSTER_OVERHEAD;

        pClrGrpRTInfo->virtualPageSize = (uint8)FEE_VIRTUAL_PAGE_SIZE;

        pClrGrpRTInfo->numberOfSwap = Fee_aClrGrpInfo[ uClrGrpIndex ].uActClrID - 1U;
    }
}

/**
* @brief        Service to prepare the driver for a cluster swap in the selected cluster group.
*
* @detailes     While the computed amount of memory is allocated as a result of Fee_Write
*               call for plain data blocks, for immediate data blocks memory gets completely
*               pre-allocated through Fee_EraseImmediateBlock function (i.e. Fee_Write does
*               not change the remaining space).
*               As a result, swaps triggered by the planned Fee_ForceSwapOnNextWrite function
*               behave the same way, or in other words, an operation that really activates the
*               pysical swap must be either Fee_Write on plain FEE block or
*               Fee_EraseImmediateBlock on immediate data block.
*
* @param[in]    uClrGrpIndex    Index of the selected cluster group

* @return       Std_ReturnType
* @retval       E_NOT_OK  module is not initialized, busy or uClrGrpIndex is not in the
*                         valid range.
* @retval       E_OK      No more space available in the selected cluster.
*
* @pre          The module must be initialized, not busy and uClrGrpIndex must be valid.
*
* @note         As this API manipulates the internal driver state, it has to be claimed
*               non-reentrant and colliding with other FEE ASR APIs
* @api
*
* @implements   Fee_ForceSwapOnNextWrite_Activity
*/
/*
* @violates @ref Fee_c_REF_15 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FEE_CODE ) Fee_ForceSwapOnNextWrite ( VAR( uint8, AUTOMATIC ) uClrGrpIndex )
{
    VAR( Std_ReturnType, AUTOMATIC ) uRetVal = (Std_ReturnType)E_OK;

    /* DET Check for cluster group should be added:
        - INITIALIZED driver
        - BUSY and BUSY_INTERNAL driver
        - Cluster group valid
    */

    if( MEMIF_UNINIT == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError( (uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_UNINIT);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == Fee_eModuleStatus )
    {
#if (FEE_DEV_ERROR_DETECT == STD_ON)
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_BUSY);
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
#if (FEE_DEV_ERROR_DETECT == STD_ON)
    else if( MEMIF_BUSY_INTERNAL == Fee_eModuleStatus )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_BUSY_INTERNAL);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Cluster group index in valid range */
    else if( FEE_NUMBER_OF_CLUSTER_GROUPS <= uClrGrpIndex )
    {
        /** @violates @ref Fee_c_REF_16 Violates MISRA 2004 Rule 16.10 **/
        Det_ReportError((uint16)FEE_MODULE_ID, FEE_INSTANCE_ID, FEE_FORCESWAPONNEXTWRITE_ID, FEE_E_CLUSTER_GROUP_IDX);
        uRetVal = (Std_ReturnType)E_NOT_OK;
    }
#endif    /* FEE_DEV_ERROR_DETECT == STD_ON */
    else
    {
        Fee_aClrGrpInfo[ uClrGrpIndex ].uDataAddrIt =
            Fee_aClrGrpInfo[ uClrGrpIndex ].uHdrAddrIt + (2U * FEE_BLOCK_OVERHEAD);

    }

    return( uRetVal );
}

#define FEE_STOP_SEC_CODE
/* @violates @ref Fee_c_REF_2 Repeated include file */
/* @violates @ref Fee_c_REF_3 declaration before #include */
#include "Fee_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
