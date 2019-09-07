/**
*   @file    Spi.c
*   @implements Spi.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Implements the AUTOSAR SPI driver functionality.
*   @details Implements the AUTOSAR SPI driver. All the API functions are described by AUTOSAR
*
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPSPI
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
* preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer to object type
* and a different pointer to object type.
* 'Spi_ChannelConfigType.BufferDescriptor' field is defined as P2CONST(), while the
* referenced Spi_BufferDescriptorType instance may be a variable, in the case of
* external buffers.
*
* @section Spi_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*
* @section Spi_c_REF_5
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
* @section Spi_c_REF_7
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const or volatile
* qualification from the type addressed by a pointer.
*
* @section Spi_c_REF_9
* Violates MISRA 2004 Required Rule 16.10, If a function returns error information, 
* then that error information shall be tested.
*
* @section Spi_c_REF_10
* Violates MISRA 2004 Required Rule 8.7,Objects %s shall be defined at block scope if they are 
* only accessed from within a single function %s.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_IPW.h"

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#include "SchM_Spi.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_MODULE_ID_C                     83
#define SPI_VENDOR_ID_C                     43
#define SPI_AR_RELEASE_MAJOR_VERSION_C      4
#define SPI_AR_RELEASE_MINOR_VERSION_C      2
/*
* @violates @ref Spi_c_REF_5 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_C   2
#define SPI_SW_MAJOR_VERSION_C              1
#define SPI_SW_MINOR_VERSION_C              0
#define SPI_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_VENDOR_ID)
    #error "Spi.c and Spi.h have different vendor ids"
#endif

/* Check if this header file and Spi_IPW_Types.h are of the same vendor */
#if (SPI_VENDOR_ID_C != SPI_IPW_VENDOR_ID)
    #error "Spi.h and Spi_IPW.h have different vendor ids"
#endif

/* Check if current file and Spi header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.c and Spi.h are different"
#endif

  /* Check if current file and Spi header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.c and Spi.h are different"
#endif

/* Check if current file and Spi_IPW header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_C != SPI_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_C != SPI_IPW_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_C != SPI_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi.c and Spi_IPW.h are different"
#endif

  /* Check if current file and Spi_IPW header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_C != SPI_IPW_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_C != SPI_IPW_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_C != SPI_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi.c and Spi_IPW.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  #if (SPI_DEV_ERROR_DETECT == STD_ON)
  #if ((SPI_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION))
  #error "AutoSar Version Numbers of SPI.h and Det.h are different"
  #endif
  #endif


#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #if ((SPI_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
  #error "AutoSar Version Numbers of Spi.c and Dem.h are different"
  #endif
#endif

#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief   This structure holds the HWUnit scheduling queue.
* @details For async transmissions, this structure holds the HWUnit scheduling queue .
*          For sync transmissions, only HWUnit Status is managed.
*
*/
typedef struct
{
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    /**< @brief Array of the IDs of jobs to be scheduled, for each priority level. */
    VAR(Spi_JobType, SPI_VAR) aScheduledJobsListHead[SPI_JOB_PRIORITY_LEVELS_COUNT];
    /**< @brief Array of the IDs of last jobs in queues, for each priority level. */
    VAR(Spi_JobType, SPI_VAR) aScheduledJobsListTail[SPI_JOB_PRIORITY_LEVELS_COUNT];
    /**< @brief Array of the IDs of last jobs in queues, for each priority level. */
    VAR(sint8, SPI_VAR) s8MaxScheduledPriority;
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */
    VAR(Spi_StatusType, SPI_VAR) Status;    /**< @brief DSPI state. */
} Spi_HWUnitQueue;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief  Values used to denote NULL indexes.
*/
#define SPI_JOB_NULL            ((Spi_JobType)(-1))
#define SPI_SEQUENCE_NULL       ((Spi_SequenceType)(-1))
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define   SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /**
* @brief Array of HW units queues.
*/
static VAR(Spi_HWUnitQueue, SPI_VAR) Spi_aSpiHWUnitQueueArray[SPI_MAX_HWUNIT];

#define   SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define   SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Pointer initialized during init with the address of the received configuration structure.
* @details Will be used by all functions to access the configuration data.
*/
P2CONST(Spi_ConfigType, SPI_VAR, SPI_APPL_CONST) Spi_pcSpiConfigPtr = NULL_PTR;

#define   SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 

#define   SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 /**
* @brief Spi State.
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_SequenceStateType, SPI_VAR) Spi_aSpiSequenceState[SPI_MAX_SEQUENCE];

/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_JobStateType, SPI_VAR) Spi_aSpiJobState[SPI_MAX_JOB];

/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_ChannelStateType, SPI_VAR) Spi_aSpiChannelState[SPI_MAX_CHANNEL];

#if (SPI_MAX_HWUNIT > 32u)
    #error "Too many HW Units in configuration (max 32 units allowed)"
#endif

#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define   SPI_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @note Array of used HW units per sequence:
*         The element corresponding to a given sequence will have asserted the bits
*         corresponding to the used HW units.
*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
static VAR(uint32, SPI_VAR) Spi_au32SpiSeqUsedHWUnits[SPI_MAX_SEQUENCE];
#endif

#define   SPI_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define   SPI_START_SEC_VAR_INIT_32
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Spi Sync Transmit Running HWUnits Status.
*/
/*
 * @violates @ref Spi_c_REF_10 MISRa Rule 8.7 Objects %s shall be defined at block scope ..
 */
static volatile VAR(uint32, SPI_VAR) Spi_u32SpiBusySyncHWUnitsStatus = 0u;

#define   SPI_STOP_SEC_VAR_INIT_32
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_ScheduleJob
    (
        P2VAR(Spi_HWUnitQueue, AUTOMATIC, SPI_APPL_DATA) pHWUnitQueue,
        VAR(Spi_JobType, AUTOMATIC) Job,
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    );
#endif

#if (SPI_LEVEL_DELIVERED == LEVEL2)
LOCAL_INLINE FUNC(Spi_StatusType, SPI_CODE) Spi_GetAsyncStatus(void);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LockJobs
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence,
        P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_CANCEL_API == STD_ON)
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_UnlockRemainingJobs
    (
        VAR(Spi_JobType, AUTOMATIC) RemainingJobs,
        P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    );
#endif
#endif
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
static FUNC(void, SPI_CODE) Spi_ScheduleNextJob
    (
        P2VAR(Spi_HWUnitQueue, AUTOMATIC, SPI_APPL_DATA) pHWUnitQueue
    );
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
* @brief   This function returns the status of the SPI driver related to async HW Units.
* @details Return SPI_BUSY if at least one async HW unit is busy.
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL2.
*/
/*================================================================================================*/
#if (SPI_LEVEL_DELIVERED == LEVEL2)
LOCAL_INLINE FUNC(Spi_StatusType, SPI_CODE) Spi_GetAsyncStatus(void)
{
    VAR(Spi_StatusType, AUTOMATIC) StatusFlag = SPI_IDLE;
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;

    for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
    {
        if ((SPI_BUSY == Spi_aSpiHWUnitQueueArray[HWUnit].Status) &&
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            (SPI_PHYUNIT_ASYNC_U32 == Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u32IsSync))
        {
            StatusFlag = SPI_BUSY;
            break;
        }
        else
        {
            /* Do nothing */
        }
    }
    return StatusFlag;
}
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) */

/*================================================================================================*/
/**
* @brief   This function is called in order to mark the jobs of a sequence as ready to be transmitted.
* @details For each job in sequence, the function checks if it is already
*          linked to another pending sequence.
*          If at least one job is already linked, the function returns E_NOT_OK.
*          Elsewhere, all jobs in sequence are locked (linked to the current
*          sequence)
*
* @param[in]      Sequence        The sequence ID.
* @param[in]      pcSequence       The sequence configuration.
*
* @return Std_ReturnType
* @retval E_OK       The given sequence does not share its jobs with some
*                    other sequences, and all its jobs were successfully
*                    locked.
* @retval E_NOT_OK  The given sequence shares its jobs with some other
*                   sequences. No lock performed for its jobs.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_LockJobs
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence,
        P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR(Spi_JobType, AUTOMATIC) JobCount = pcSequence->NumJobs;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pcJobs = pcSequence->pcJobIndexList;
    P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) pJobState;
    P2VAR(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_DATA) pSequenceState;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_05();

    /* use an optimized implementation for one job sequences */
    if (1u == JobCount)
    {
        pJobState = &Spi_aSpiJobState[*pcJobs];
        if (NULL_PTR == pJobState->pAsyncCrtSequenceState)
        {
            /* job not yet linked => link it to the current sequence */
            pJobState->pAsyncCrtSequenceState = &Spi_aSpiSequenceState[Sequence];
        }
        else
        {
            /* the job is already locked by a pending sequence */
            Status = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        pSequenceState = &Spi_aSpiSequenceState[Sequence];
        while (0u < JobCount)
        {
            pJobState = &Spi_aSpiJobState[*pcJobs];
            if (NULL_PTR == pJobState->pAsyncCrtSequenceState)
            {
                /* job not yet linked => link it to the current sequence */
                pJobState->pAsyncCrtSequenceState = pSequenceState;
            }
            else
            {
                /* the job is already locked by a pending sequence =>
                   rollback all the previous locks */
                if (JobCount < pcSequence->NumJobs)
                {
                    do
                    {
                        JobCount++;
                        /*
                        * @violates @ref Spi_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        pcJobs--;
                        Spi_aSpiJobState[*pcJobs].pAsyncCrtSequenceState = NULL_PTR;
                    }
                    while (JobCount < pcSequence->NumJobs);
                }
                else
                {
                    /* Do nothing */
                }
                Status = (Std_ReturnType)E_NOT_OK;
                break;
            }

            /* next job */
            JobCount--;
            /*
             * @violates @ref Spi_c_REF_6 Array indexing shall be
             *       the only allowed form of pointer arithmetic.
             */
            pcJobs++;
        }
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_05();
    return Status;
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function is called to release the jobs at the end of an async sequence transmission.
* @details Mark the linked sequence for all jobs as NULL_PTR.
*
* @param[in]      RemainingJobs    The starting job
* @param[in]      pcSequence        The sequence configuration
*
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_CANCEL_API == STD_ON)
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_UnlockRemainingJobs
    (
        VAR(Spi_JobType, AUTOMATIC) RemainingJobs,
        P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    )
{
    VAR(Spi_JobType, AUTOMATIC) NumJobsInSeq = pcSequence->NumJobs;
    VAR(Spi_JobType, AUTOMATIC) JobIdx;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_06();
    for (JobIdx = NumJobsInSeq-RemainingJobs; JobIdx < NumJobsInSeq; JobIdx++)
    {
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        Spi_aSpiJobState[pcSequence->pcJobIndexList[JobIdx]].pAsyncCrtSequenceState = NULL_PTR;
    }
    SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_06();
}
#endif /* (SPI_CANCEL_API == STD_ON) */
#endif /* (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) */

/*================================================================================================*/
/**
* @brief   This function will schedule a job for a given HW unit.
* @details If the HWUnit is not busy, the transfer is started and the HW unit is
*          marked as busy.
*          If the HWUnit is not busy (another job is in progress), the new job is
*          scheduled in a waiting job list, according to its priority.
*
* @param[in]      pHWUnitQueue     HW Unit to be used by the job
* @param[in]      Job             ID of the scheduled job
* @param[in]      pcJobConfig      Configuration of the scheduled job
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_ScheduleJob
    (
        P2VAR(Spi_HWUnitQueue, AUTOMATIC, SPI_APPL_DATA) pHWUnitQueue,
        VAR(Spi_JobType, AUTOMATIC) Job,
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    )
{
    VAR(sint8, AUTOMATIC) s8Priority;
    P2VAR(Spi_JobType, AUTOMATIC, SPI_APPL_DATA) pJobListTail;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_03();
    if (SPI_IDLE == pHWUnitQueue->Status)
    {
        /* idle unit => the job can be started */
        pHWUnitQueue->Status = SPI_BUSY;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03();

        /* mark the job as pending */
        Spi_aSpiJobState[Job].Result = SPI_JOB_PENDING;
        Spi_Ipw_JobTransfer(pcJobConfig);
    }
    else
    {
        /* add the job to the scheduling corresponding queue */

        /* retrieve the tail of the scheduling queue for the job priority */
        s8Priority = pcJobConfig->s8Priority;
        pJobListTail = &pHWUnitQueue->aScheduledJobsListTail[s8Priority];

        if (SPI_JOB_NULL == *pJobListTail)
        {
            /* the list is empty => set also the head of the list */
            pHWUnitQueue->aScheduledJobsListHead[s8Priority] = Job;
        }
        else
        {
            /* add the item at the end of the list */
            Spi_aSpiJobState[*pJobListTail].AsyncNextJob = Job;
        }

        /* set the new tail of the list */
        *pJobListTail = Job;

        /* the new item will be the last element in the list */
        Spi_aSpiJobState[Job].AsyncNextJob = SPI_JOB_NULL;

        if (pHWUnitQueue->s8MaxScheduledPriority < s8Priority)
        {
            pHWUnitQueue->s8MaxScheduledPriority = s8Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_03();
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

#if (SPI_VERSION_INFO_API == STD_ON)
/*================================================================================================*/
/**
* @brief   This function returns the version information for the SPI driver.
* @details This function returns the version information for the SPI driver.
*          - Service ID:       0x09
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in,out]    VersionInfo      Pointer to where to store the version
*                                    information of this module.
*
* @pre  Pre-compile parameter SPI_VERSION_INFO_API shall be STD_ON.
*
* @implements Spi_GetVersionInfo_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_GetVersionInfo 
    (
        P2VAR(Std_VersionInfoType, AUTOMATIC, SPI_APPL_DATA) versioninfo
    )
{      
#if( SPI_DEV_ERROR_DETECT == STD_ON )
    if(NULL_PTR == versioninfo)
    {
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16)SPI_MODULE_ID,(uint8)0,SPI_GETVERSIONINFO_ID,SPI_E_PARAM_POINTER);
    }
    else
    {
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
    versioninfo->vendorID = (uint16)SPI_VENDOR_ID;
    versioninfo->moduleID = (uint8)SPI_MODULE_ID;
    versioninfo->sw_major_version = (uint8)SPI_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)SPI_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)SPI_SW_PATCH_VERSION;
#if(SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* SPI_DEV_ERROR_DETECT == STD_ON */
}
#endif /* (SPI_VERSION_INFO_API == STD_ON) */

/*================================================================================================*/
/**
* @brief   This function initializes the SPI driver.
* @details This function initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x00
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]     ConfigPtr      Specifies the pointer to the configuration set
*
* @implements Spi_Init_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_Init
    (
        P2CONST(Spi_ConfigType, AUTOMATIC, SPI_APPL_CONST) ConfigPtr
    )
{
    VAR(uint32, AUTOMATIC) u32Channel;
    VAR(uint32, AUTOMATIC) u32Job;
    VAR(uint32, AUTOMATIC) u32Sequence;
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    VAR(sint8, AUTOMATIC) s8Priority;
#endif
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL1) || \
    ((SPI_LEVEL_DELIVERED == LEVEL0) && (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)))
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig;
#endif

 #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
 #if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if ConfigPtr */
    /* is passed as a NULL Pointer */
    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_ALREADY_INITIALIZED);
    }
    else if (NULL_PTR == ConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_UNINIT);
    }
    else
    {
#endif
    /* These defines use for fix compiler warning in the case that the */
    /* right operand is higher */
    u32Channel  = (uint32)(ConfigPtr->Spi_Max_Channel);
    u32Job      = (uint32)(ConfigPtr->Spi_Max_Job);
    u32Sequence = (uint32)(ConfigPtr->Spi_Max_Sequence);

    if ((u32Channel >= SPI_MAX_CHANNEL) || (u32Job >= SPI_MAX_JOB) || (u32Sequence >= SPI_MAX_SEQUENCE))
    {
        /* configuration sizes must be checked for
           Post Build & Link Time configurations */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_CONFIG_OUT_OF_RANGE);
#endif
    }
    else
    {
#else /* (SPI_CONFIG_VARIANT == SPI_VARIANT_PRECOMPILE) */
        if (NULL_PTR != Spi_pcSpiConfigPtr)
        {

#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_INIT_ID,SPI_E_ALREADY_INITIALIZED);
#endif
        }
        else if (NULL_PTR == ConfigPtr)
        {
             Spi_pcSpiConfigPtr = &Spi_PBCfgVariantPredefined;
         }
        else
#endif
        {
            Spi_pcSpiConfigPtr = ConfigPtr;
        }
        /* initialize buffer pointers to zero */

        for (u32Channel = 0u;
            u32Channel <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Channel);
            u32Channel++)
        {
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[u32Channel];
            /* Check if configured buffers are External (EB) */

            if (EB == pcChannelConfig->BufferType)
            {
                /* Initialize all buffers */
                pcChannelConfig->pcBufferDescriptor->pBufferTX = NULL_PTR;
                pcChannelConfig->pcBufferDescriptor->pBufferRX = NULL_PTR;

                /* Channel length is zero for unconfigured external buffers */
                Spi_aSpiChannelState[u32Channel].Length = (Spi_NumberOfDataType) 0;
            }
            else
            {
                /* Setup channel length according to configuration */
                Spi_aSpiChannelState[u32Channel].Length = pcChannelConfig->Length;
            }
            Spi_aSpiChannelState[u32Channel].u8Flags = (VAR(uint8, AUTOMATIC))SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
        }

        /* initialize job results */
        for (u32Job = 0u;
            u32Job <= (uint32)( Spi_pcSpiConfigPtr->Spi_Max_Job);
            u32Job++)
        {
            Spi_aSpiJobState[u32Job].Result = SPI_JOB_OK;

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
            /* mark the job as unlocked / not linked to a pending async sequence */
            Spi_aSpiJobState[u32Job].pAsyncCrtSequenceState = NULL_PTR;
#endif
        }

        for (u32Sequence = 0u;
            u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence);
            u32Sequence++)
        {
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[u32Sequence];
            Spi_aSpiSequenceState[u32Sequence].pcSequence = pcSequenceConfig;
#endif

            /* initialize sequence results */
            Spi_aSpiSequenceState[u32Sequence].Result = SPI_SEQ_OK;

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_ON)
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[u32Sequence];
            /* initialize the map of used HWUnits per sequence */
            Spi_au32SpiSeqUsedHWUnits[u32Sequence] = (uint32)0;

            for (u32Job = 0u;(VAR(Spi_JobType, AUTOMATIC))u32Job < pcSequenceConfig->NumJobs; u32Job++)
            {
                /*
                * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                HWUnit = Spi_pcSpiConfigPtr->pcJobConfig[pcSequenceConfig->pcJobIndexList[u32Job]].HWUnit;

                Spi_au32SpiSeqUsedHWUnits[u32Sequence] |=
                /*
                * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                    (uint32)((uint32)1 << (Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u8Offset));
            }
#else /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
            /* SPI135: Spi_SyncTransmit() must fail if an other sync transmission
                   is ongoing.*/
            /* mark all HW units as used by the sync transmission, in order to
                force the mutual exclusion of Spi_SyncTransmit() calls */

            Spi_au32SpiSeqUsedHWUnits[u32Sequence] = 0xFFFFFFFFU;
#endif /* (SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT == STD_OFF) */
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

        }
        
#ifdef SPI_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == SPI_ENABLE_USER_MODE_SUPPORT)
    #ifdef SPI_DSPI_REG_PROT_AVAILABLE
        Spi_Ipw_SetUserAccessAllowed();
    #endif
#endif
#endif

        /* De-initialize all physical HWUnits */
        for (HWUnit = (VAR(Spi_HWUnitType, AUTOMATIC)) 0;
            HWUnit < (VAR(Spi_HWUnitType, AUTOMATIC)) SPI_MAX_HWUNIT;
            HWUnit++)
        {        
            Spi_Ipw_DeInit(HWUnit);
        }
        
        /* initialize all physical HWUnits */
        for (HWUnit = (VAR(Spi_HWUnitType, AUTOMATIC)) 0;
            HWUnit < (VAR(Spi_HWUnitType, AUTOMATIC)) SPI_MAX_HWUNIT;
            HWUnit++)
        {
            Spi_Ipw_Init(HWUnit, &Spi_aSpiHWUnitQueueArray[HWUnit].Status);
            
#if (SPI_LEVEL_DELIVERED == LEVEL1)
            /* handler uses interrupt mode only if LEVEL 1 is selected */
            Spi_Ipw_IrqConfig(HWUnit, SPI_INTERRUPT_MODE);
#endif            
#if (SPI_LEVEL_DELIVERED == LEVEL2)
            /* handler uses polling mode only if LEVEL 2 is selected */
            Spi_Ipw_IrqConfig(HWUnit, SPI_POLLING_MODE);
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
            /* initialize the Job lists => no scheduled job for the unit */
            for (s8Priority = 0; s8Priority < SPI_JOB_PRIORITY_LEVELS_COUNT; s8Priority++)
            {
                Spi_aSpiHWUnitQueueArray[HWUnit].aScheduledJobsListHead[s8Priority] = SPI_JOB_NULL;
                Spi_aSpiHWUnitQueueArray[HWUnit].aScheduledJobsListTail[s8Priority] = SPI_JOB_NULL;
            }

            /* no scheduled job => s8MaxScheduledPriority is -1 */
            Spi_aSpiHWUnitQueueArray[HWUnit].s8MaxScheduledPriority = -1;
#endif
            Spi_aSpiHWUnitQueueArray[HWUnit].Status = SPI_IDLE;
        }

#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
        /* cache information for sequences having only one job */
        Spi_Ipw_PrepareCacheInformation();
#endif
 #if (SPI_PRECOMPILE_SUPPORT == STD_OFF)
     }
#if (SPI_DEV_ERROR_DETECT == STD_ON)    
    }
#endif
#endif
}
/*================================================================================================*/
/**
* @brief   This function de-initializes the SPI driver.
* @details This function de-initializes the SPI driver using the
*          pre-established configurations
*          - Service ID:       0x01
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @return Std_ReturnType
* @retval E_OK       de-initialisation command has been accepted
* @retval E_NOT_OK   de-initialisation command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_DeInit()
*       otherwise, the function Spi_DeInit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_DeInit_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_DeInit(void)
{
    VAR(Std_ReturnType, AUTOMATIC) tempExit = (Std_ReturnType)E_OK;
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */                        
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_DEINIT_ID,SPI_E_UNINIT);
        tempExit = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /* Check if Spi Status is Busy */
        if (SPI_BUSY == Spi_GetStatus())
        {
            tempExit = (VAR(Std_ReturnType, AUTOMATIC)) E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
             /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_DEINIT_ID,SPI_E_SEQ_PENDING);
 #endif
        }
        else
        {
            /* de-initialize all physical HWUnits */
            for (HWUnit = (VAR(Spi_HWUnitType, AUTOMATIC)) 0;
                 HWUnit < (VAR(Spi_HWUnitType, AUTOMATIC)) SPI_MAX_HWUNIT;
                 HWUnit++)
            {
                Spi_Ipw_DeInit(HWUnit);

                Spi_aSpiHWUnitQueueArray[HWUnit].Status = SPI_UNINIT;
            }
            /* reset configuration pointer */
            Spi_pcSpiConfigPtr = NULL_PTR;
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return tempExit;
}

/*================================================================================================*/
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || \
      (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
/**
* @brief   This function writes the given data into the buffer of a specific channel.
* @details This function writes the given data into the buffer of a specific channel.
*          - Service ID:       0x02
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      DataBufferPtr       Pointer to source data buffer
*
* @return Std_ReturnType
* @retval E_OK       Command has been accepted
* @retval E_NOT_OK   Command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_WriteIB()
*       otherwise, the function Spi_WriteIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be USAGE0 or USAGE2.
*
* @implements Spi_WriteIB_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_WriteIB
    (
        VAR(Spi_ChannelType, AUTOMATIC) Channel,
         P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) DataBufferPtr
     )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR(uint16, AUTOMATIC) u16Index;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) pChannelState;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pDataBufferDes;
    P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) pcDataBufferSrc=NULL_PTR;
    #ifdef SPI_SWAP_DATA_SUPPORT_32BITS
    #if(SPI_SWAP_DATA_SUPPORT_32BITS == STD_ON)
    VAR(uint32, AUTOMATIC) pTemp[2048];
    VAR(uint32, AUTOMATIC) u32Data[4];
    VAR(uint16, AUTOMATIC) u16Count;
    #endif
    #endif
    
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) pcDspiChannelAttributesConfig;
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_WRITEIB_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }

    /* If Development Error Detection is enabled,
       report error if invalid channel */
    else if (Channel > (Spi_pcSpiConfigPtr->Spi_Max_Channel))
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_WRITEIB_ID,SPI_E_PARAM_CHANNEL);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif

#if (SPI_FORCE_DATA_TYPE == STD_ON)
    /*
    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    pcDspiChannelAttributesConfig =&Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[Channel];
    /*
    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
#ifdef SPI_SWAP_DATA_SUPPORT_32BITS
#if(SPI_SWAP_DATA_SUPPORT_32BITS == STD_ON)

  if(SPI_DATA_WIDTH_32==pcDspiChannelAttributesConfig->u8DataWidth)
  {
    for(u16Count=0;u16Count<pcChannelConfig->Length/4;u16Count++)
    {
        u32Data[0]=*DataBufferPtr;
        DataBufferPtr++;
        u32Data[1]=*DataBufferPtr;
        DataBufferPtr++;
        u32Data[2]=*DataBufferPtr;
        DataBufferPtr++;
        u32Data[3]=*DataBufferPtr;
        DataBufferPtr++;
        pTemp[u16Count]=u32Data[2]<<24|u32Data[3]<<16|u32Data[0]<<8|u32Data[1];
    }
  }
#endif
#endif
#endif
        pChannelState = &Spi_aSpiChannelState[Channel];
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];

        /* exit early if this is the wrong buffer type */
        if (EB == pcChannelConfig->BufferType)
        {
            Status = (Std_ReturnType)E_NOT_OK;
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_WRITEIB_ID,SPI_E_PARAM_CHANNEL);
#endif
        }
        else
        {
            /* if DataBufferPtr is zero, then transmit default value */
            if (NULL_PTR == DataBufferPtr)
            {

                pChannelState->u8Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }

            /* otherwise, copy data from DataBufferPtr to IB */
            else
            {
                pDataBufferDes = pcChannelConfig->pcBufferDescriptor->pBufferTX;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
            if(SPI_DATA_WIDTH_32==pcDspiChannelAttributesConfig->u8DataWidth)
            {
#ifdef SPI_SWAP_DATA_SUPPORT_32BITS
#if(SPI_SWAP_DATA_SUPPORT_32BITS == STD_ON)
              pcDataBufferSrc = (const Spi_DataBufferType *)pTemp;
#else
              pcDataBufferSrc = DataBufferPtr;
#endif
#endif
            }
            else    
            {
              pcDataBufferSrc = DataBufferPtr;
            }
#else
             pcDataBufferSrc = DataBufferPtr;
#endif
                
                for (u16Index = 0u; u16Index < pcChannelConfig->Length; u16Index++)
                {
                    *pDataBufferDes=*pcDataBufferSrc;
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pDataBufferDes++;
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pcDataBufferSrc++;
                }
                pChannelState->u8Flags = 
                    (uint8)(pChannelState->u8Flags & ((uint8)(~SPI_CHANNEL_FLAG_TX_DEFAULT_U8)));
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    /* Return status */
    return Status;
}
#endif
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function triggers the asynchronous transmission for the given sequence.
* @details This function triggers the asynchronous transmission for the given sequence.
*          - Service ID:       0x03
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK       Transmission command has been accepted
* @retval E_NOT_OK   Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_AsyncTransmit()
*       otherwise, the function Spi_AsyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
* @implements Spi_AsyncTransmit_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_AsyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR(Spi_JobType, AUTOMATIC) NumJobsInSequence;
    VAR(Spi_JobType, AUTOMATIC) JobIndex;
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig;
    P2VAR(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_DATA) pSequenceState;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pcJob;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pcJobCount;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
    VAR(Spi_ChannelType, AUTOMATIC) ChannelID;
    VAR(Spi_ChannelType, AUTOMATIC) NumChannelsInJob;
    VAR(Spi_ChannelType, AUTOMATIC) ChannelIndex;
#endif
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Sequence Valid Range */
    else if (Sequence > (Spi_pcSpiConfigPtr->Spi_Max_Sequence))
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_SEQ);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];
        /* Get the number of jobs in the sequence */
        NumJobsInSequence = pcSequenceConfig->NumJobs;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* check for empty sequence */
        if (0u == NumJobsInSequence)
        {
            /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_SEQ_EMPTY);
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Do nothing */
        }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

        JobIndex = 0u;
        while(JobIndex < NumJobsInSequence)
        {
           /* Get the job id */
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            Job = pcSequenceConfig->pcJobIndexList[JobIndex];

            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Job];

#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /* check for empty jobs */
            if (0u == pcJobConfig->NumChannels)
            {
                /* Call Det_ReportError */
                /*
                * @violates @ref Spi_c_REF_9 If a function returns error information,
                *           then that error information shall be tested.
                */
                Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_JOB_EMPTY);
                Status = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }

            /* Logical Spi HWUnit */
            HWUnit = pcJobConfig->HWUnit;

            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            if (SPI_PHYUNIT_ASYNC_U32 != Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u32IsSync)
            {
                /* HwUnit is not prearranged for dedicated Asynchronous
                   transmission */
                /* Call Det_ReportError */
                /*
                * @violates @ref Spi_c_REF_9 If a function returns error information,
                *           then that error information shall be tested.
                */
                Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_UNIT);
                Status = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
            if ((Std_ReturnType)E_OK == Status)
            {
                /* Check if all EBs have been setup */
                NumChannelsInJob = pcJobConfig->NumChannels;
                for(ChannelIndex=(Spi_ChannelType)0;ChannelIndex < NumChannelsInJob; ChannelIndex++)
                {
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    ChannelID = pcJobConfig->pcChannelIndexList[ChannelIndex];
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    if (EB == Spi_pcSpiConfigPtr->pcChannelConfig[ChannelID].BufferType)
                    {
                        /* Length is 0 for unconfigured ext. buffers */
                        if (0U == Spi_aSpiChannelState[ChannelID].Length)
                        {
                            /* An used EB not initialized  */
                            /*
                            * @violates @ref Spi_c_REF_9 If a function returns error information,
                            *           then that error information shall be tested.
                            */
                            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_PARAM_EB_UNIT);
                            Status = (Std_ReturnType)E_NOT_OK;
                            break;
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
            }
            else
            {
                /* Do nothing */
            }
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) ) */
            if ((Std_ReturnType)E_OK != Status)
            {
                /* break */
                break;
            }
            else
            {
                /* Do nothing */
            }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */
            JobIndex++;
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        if ((Std_ReturnType)E_OK == Status)
        {
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

            Status = Spi_LockJobs(Sequence, pcSequenceConfig);
            if ((Std_ReturnType)E_OK == Status)
            {
                pSequenceState = &Spi_aSpiSequenceState[Sequence];
                /* Mark sequence pending */
                pSequenceState->Result = SPI_SEQ_PENDING;

                /* Initialize job related information */
                pSequenceState->RemainingJobs = pcSequenceConfig->NumJobs - 1u;
                /*
                * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                pcJob = &pcSequenceConfig->pcJobIndexList[0];
                pSequenceState->pcCurrentJobIndexPointer = pcJob;
                for(JobIndex = 0u; JobIndex < NumJobsInSequence; JobIndex++)
                {
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    pcJobCount = &pcSequenceConfig->pcJobIndexList[JobIndex];
                    Spi_aSpiJobState[*pcJobCount].Result = SPI_JOB_QUEUED;
                }
                /* Schedule transmission of the first job */
                /*
                * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                */
                pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[*pcJob];
                Spi_ScheduleJob(&Spi_aSpiHWUnitQueueArray[pcJobConfig->HWUnit],
                                *pcJob, pcJobConfig);
            }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            else
            {
             /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_ASYNCTRANSMIT_ID,SPI_E_SEQ_PENDING);
             }
        }
        else
        {
            /* Do nothing */
        }
    }
#endif /* (SPI_DEV_ERROR_DETECT == STD_OFF) */

    return Status;
}

#endif
/*================================================================================================*/
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE0) || \
      (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
/**
* @brief   This function reads the data from the buffer of a channel and puts at the memory location.
* @details This function reads the data from the buffer of a specific channel
*          and puts at the specified memory location.
*          - Service ID:       0x04
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
*
* @param[in]      Channel             Channel ID
* @param[in,out]  DataBufferPointer       Pointer to the memory location that will
*                                     be written with the data in the internal
*                                     buffer
*
* @return Std_ReturnType
* @retval E_OK      read command has been accepted
* @retval E_NOT_OK  read command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_ReadIB()
*       otherwise, the function Spi_ReadIB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be USAGE0 or USAGE2.
*
* @implements Spi_ReadIB_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_ReadIB
    (
        VAR(Spi_ChannelType, AUTOMATIC) Channel,
         P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DataBufferPointer
     )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR(Spi_NumberOfDataType, AUTOMATIC) Index;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pDataBufferSrc;
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pDataBufferDes;
 
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Channel valid range - Channels range is from 0 to Spi_Max_Channel */
    else if (Channel > Spi_pcSpiConfigPtr->Spi_Max_Channel)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];

        /* exit early if this is the wrong buffer type or destination
           is invalid */
        if (EB == pcChannelConfig->BufferType)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else if (NULL_PTR == DataBufferPointer)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_READIB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* Copy Rx buffer to IB buffer */
            pDataBufferSrc = pcChannelConfig->pcBufferDescriptor->pBufferRX;
            pDataBufferDes = DataBufferPointer;
            for (Index = 0u; Index < pcChannelConfig->Length; Index++)
            {
                    *pDataBufferDes=*pDataBufferSrc;
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pDataBufferDes++;
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pDataBufferSrc++;
            }
        }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif
/*================================================================================================*/
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || \
      (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
/**
* @brief   This function setup an external buffer to be used by a specific channel.
* @details This function setup an external buffer to be used by a specific channel.
*          - Service ID:       0x05
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Channel             Channel ID
* @param[in]      SrcDataBufferPtr    Pointer to the memory location that will hold
*                                     the transmitted data
* @param[in]      Length              Length of the data in the external buffer
* @param[out]     DesDataBufferPtr    Pointer to the memory location that will hold
*                                     the received data
*
* @return Std_ReturnType
* @retval E_OK      Setup command has been accepted
* @retval E_NOT_OK  Setup command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SetupEB()
*       otherwise, the function Spi_SetupEB() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CHANNEL_BUFFERS_ALLOWED shall be USAGE1 or USAGE2.
*
* @implements Spi_SetupEB_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_SetupEB
    (
        VAR(Spi_ChannelType, AUTOMATIC) Channel,
         P2CONST(Spi_DataBufferType, AUTOMATIC, SPI_APPL_CONST) SrcDataBufferPtr,
        P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) DesDataBufferPtr,
         VAR(Spi_NumberOfDataType, AUTOMATIC) Length
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) pChannelState;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
      #ifdef SPI_SWAP_DATA_SUPPORT_32BITS
    #if(SPI_SWAP_DATA_SUPPORT_32BITS == STD_ON)
        VAR(uint32, AUTOMATIC) pTemp[2048];
        VAR(uint32, AUTOMATIC) u32Data[4];
        VAR(uint16, AUTOMATIC) u16Count;
    #endif
    #endif
 
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) pcDspiChannelAttributesConfig;
#endif
    
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Channel ID - Valid channels range is from 0 to Spi_Max_Channel*/
    else if (Channel > Spi_pcSpiConfigPtr->Spi_Max_Channel)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_CHANNEL);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Length - Valid range */
    /*
    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    else if ((Length > Spi_pcSpiConfigPtr->pcChannelConfig[Channel].Length) || (0u == Length))
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_LENGTH);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    /*
    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
    */
    pcDspiChannelAttributesConfig =&Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig[Channel];
#ifdef SPI_SWAP_DATA_SUPPORT_32BITS
#if(SPI_SWAP_DATA_SUPPORT_32BITS == STD_ON)
  if(SPI_DATA_WIDTH_32==pcDspiChannelAttributesConfig->u8DataWidth)
  {
    for(u16Count=0;u16Count<Length/4;u16Count++)
    {
        u32Data[0]=*SrcDataBufferPtr;
        SrcDataBufferPtr++;
        u32Data[1]=*SrcDataBufferPtr;
        SrcDataBufferPtr++;
        u32Data[2]=*SrcDataBufferPtr;
        SrcDataBufferPtr++;
        u32Data[3]=*SrcDataBufferPtr;
        SrcDataBufferPtr++;
        pTemp[u16Count]=u32Data[2]<<24|u32Data[3]<<16|u32Data[0]<<8|u32Data[1];
    }
  }
#endif
#endif
#endif
        pChannelState = &Spi_aSpiChannelState[Channel];
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        pcChannelConfig = &Spi_pcSpiConfigPtr->pcChannelConfig[Channel];
        /* exit early if this is the wrong buffer type */
        if (IB == pcChannelConfig->BufferType)
        {
            /* Call Det_ReportError */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETUPEB_ID,SPI_E_PARAM_CHANNEL);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
#if (SPI_FORCE_DATA_TYPE == STD_ON)
            if(SPI_DATA_WIDTH_32 == pcDspiChannelAttributesConfig->u8DataWidth)
            {
#ifdef SPI_SWAP_DATA_SUPPORT_32BITS
#if(SPI_SWAP_DATA_SUPPORT_32BITS == STD_ON) 
              pcChannelConfig->pcBufferDescriptor->pBufferTX =
             /*
             * @violates @ref Spi_c_REF_3 A cast should not be performed between a pointer
             *       to object type and a different pointer to object type.
             */
             /*
             * @violates @ref Spi_c_REF_7 A cast shall not be performed that removes any const or volatile
             * qualification from the type addressed by a pointer.
             */
             
         (P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA)) pTemp;
             
             pcChannelConfig->pcBufferDescriptor->pBufferRX = DesDataBufferPtr;
             
#else
              pcChannelConfig->pcBufferDescriptor->pBufferTX =
             /*
             * @violates @ref Spi_c_REF_3 A cast should not be performed between a pointer
             *       to object type and a different pointer to object type.
             */
             /*
             * @violates @ref Spi_c_REF_7 A cast shall not be performed that removes any const or volatile
             * qualification from the type addressed by a pointer.
             */
         (P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA)) SrcDataBufferPtr;
 
#endif
#endif
            }
            else
            {
#endif              
              pcChannelConfig->pcBufferDescriptor->pBufferTX =
             /*
             * @violates @ref Spi_c_REF_3 A cast should not be performed between a pointer
             *       to object type and a different pointer to object type.
             */
             /*
             * @violates @ref Spi_c_REF_7 A cast shall not be performed that removes any const or volatile
             * qualification from the type addressed by a pointer.
             */

          (P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA)) SrcDataBufferPtr;
 #if (SPI_FORCE_DATA_TYPE == STD_ON)
             }
#endif  
             
             pcChannelConfig->pcBufferDescriptor->pBufferRX = DesDataBufferPtr;

            pChannelState->Length = Length;

            /* if source data pointer is zero, transmit default value */
            if (NULL_PTR == SrcDataBufferPtr)
            {
                pChannelState->u8Flags |= SPI_CHANNEL_FLAG_TX_DEFAULT_U8;
            }
            else
            {
                pChannelState->u8Flags &= (uint8) (~SPI_CHANNEL_FLAG_TX_DEFAULT_U8);
            }

            /* if destination data pointer is zero, discard receiving data */
            if (NULL_PTR == DesDataBufferPtr)
            {
                pChannelState->u8Flags |= SPI_CHANNEL_FLAG_RX_DISCARD_U8;
            }
            else
            {
                pChannelState->u8Flags &= (uint8) (~SPI_CHANNEL_FLAG_RX_DISCARD_U8);
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif
/*================================================================================================*/
/**
* @brief   This function returns the status of the SPI driver.
* @details This function returns the status of the SPI driver.
*          - Service ID:       0x06
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The driver is un-initialized
* @retval SPI_IDLE    The driver has no pending transfers
* @retval SPI_BUSY    The driver is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetStatus()
*       otherwise, the function Spi_GetStatus() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_GetStatus_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Spi_StatusType, SPI_CODE) Spi_GetStatus(void)
{
    VAR(Spi_StatusType, AUTOMATIC) StatusFlag = SPI_IDLE;
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;

    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
#if (SPI_DEV_ERROR_DETECT == STD_ON)
        /* If Development Error Detection is enabled, report error if not */
        /* initialized */
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSTATUS_ID,SPI_E_UNINIT);
#endif
        StatusFlag = SPI_UNINIT;
    }
    else
    {
        /* The SPI Handler Driver software module shall be busy when any
           HWUnit is busy */

        if (0u != Spi_u32SpiBusySyncHWUnitsStatus)
        {
            /* a Spi_SyncTransmit() is pending */
            StatusFlag = SPI_BUSY;
        }
        else
        {
            /* check for busy HWUnit in async transmissions*/
            /* Note: Checking for IsSync attribute for HWUnit is not really needed
                 It is preferable to skip this check in order to have a more compact code
            */
            for (HWUnit = 0u; HWUnit < (Spi_HWUnitType)SPI_MAX_HWUNIT; HWUnit++)
            {
                if (SPI_BUSY == Spi_aSpiHWUnitQueueArray[HWUnit].Status)
                {
                    StatusFlag = SPI_BUSY;
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }
        }
    }
    return StatusFlag;
}
/*================================================================================================*/
/**
* @brief   This function is used to request the status of a specific job.
* @details This function is used to request the status of a specific job.
*          - Service ID:       0x07
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Job                 Job ID
*
* @return Spi_JobResultType
* @retval SPI_JOB_OK        The job ended successfully
* @retval SPI_JOB_PENDING   The job is pending
* @retval SPI_JOB_FAILED    The job has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetJobResult()
*       otherwise, the function Spi_GetJobResult() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_GetJobResult_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Spi_JobResultType, SPI_CODE) Spi_GetJobResult
    (
        VAR(Spi_JobType, AUTOMATIC) Job
    )
{
    VAR(Spi_JobResultType, AUTOMATIC) JobResult;

#if (SPI_DEV_ERROR_DETECT == STD_ON)

    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_UNINIT);
    }
    /* Job Valid Range - from 0 to Spi_Max_Job*/
    else if (Job > Spi_pcSpiConfigPtr->Spi_Max_Job)
    {
        JobResult = SPI_JOB_FAILED;
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETJOBRESULT_ID,SPI_E_PARAM_JOB);
    }
    else
    {
#endif
        JobResult = Spi_aSpiJobState[Job].Result;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return JobResult;
}
/*================================================================================================*/
/**
* @brief   This function is used to request the status of a specific sequence.
* @details This function is used to request the status of a specific sequence.
*          - Service ID:       0x08
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Spi_SeqResultType
* @retval SPI_SEQ_OK       The sequence ended successfully
* @retval SPI_SEQ_PENDING  The sequence is pending
* @retval SPI_SEQ_FAILED   The sequence has failed
*
* @pre  The driver needs to be initialized before calling Spi_GetSequenceResult()
*       otherwise, the function Spi_GetSequenceResult() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
*
* @implements Spi_GetSequenceResult_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Spi_SeqResultType, SPI_CODE) Spi_GetSequenceResult
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    )
{
    VAR(Spi_SeqResultType, AUTOMATIC) SequenceResult;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        SequenceResult = SPI_SEQ_FAILED;
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range from 0 to Spi_Max_Sequence*/
    else if (Sequence > Spi_pcSpiConfigPtr->Spi_Max_Sequence)
    {
        SequenceResult = SPI_SEQ_FAILED;
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETSEQUENCERESULT_ID,SPI_E_PARAM_SEQ);
    }
    else
    {
#endif
        SequenceResult = Spi_aSpiSequenceState[Sequence].Result;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return SequenceResult;
}

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/*================================================================================================*/
/**
* @brief   This function is used for synchronous transmission of a given sequence.
* @details This function is used for synchronous transmission of a given sequence.
*          - Service ID:       0x0a
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @return Std_ReturnType
* @retval E_OK      Transmission command has been completed successfully
* @retval E_NOT_OK  Transmission command has not been accepted
*
* @pre  The driver needs to be initialized before calling Spi_SyncTransmit().
*       otherwise, the function Spi_SyncTransmit() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
* @implements Spi_SyncTransmit_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_SyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    )
{
    P2VAR(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_DATA) pSequenceState;
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32SpiSequenceUsedHWUnits;
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
    P2VAR(Spi_HW_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) pSequenceCache;
#endif
#if ( (SPI_DEV_ERROR_DETECT == STD_ON) || (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) )
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
#endif   
#if (SPI_DEV_ERROR_DETECT == STD_ON)    
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    VAR(uint32, AUTOMATIC) u32UnitIsSync;
    VAR(Spi_JobType, AUTOMATIC) NumJobsInSequence;
    VAR(Spi_JobType, AUTOMATIC) JobIndex;
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
    VAR(Spi_ChannelType, AUTOMATIC)ChannelID;
    VAR(Spi_ChannelType, AUTOMATIC) NumChannelsInJob;
    VAR(Spi_ChannelType, AUTOMATIC)ChannelIndex;
#endif
#endif

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    /* Sequence Valid Range */
    else if (Sequence > Spi_pcSpiConfigPtr->Spi_Max_Sequence)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_SEQ);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];

        /* Get the number of jobs in the sequence */
        NumJobsInSequence = pcSequenceConfig->NumJobs;

        for (JobIndex = 0u; JobIndex < NumJobsInSequence; JobIndex++)
        {
            /* Get the job id */
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            Job = pcSequenceConfig->pcJobIndexList[JobIndex];
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Job];
            /* Logical Spi HWUnit */
            HWUnit = pcJobConfig->HWUnit;
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            u32UnitIsSync = Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u32IsSync;
            if ((uint32)(SPI_PHYUNIT_ASYNC_U32) == (u32UnitIsSync))
            {
                /* HwUnit is not prearranged for dedicated Synchronous
                   transmission */
                /*
                * @violates @ref Spi_c_REF_9 If a function returns error information,
                *           then that error information shall be tested.
                */
                Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_UNIT);
                Status = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /* Do nothing */
            }
#if ( (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) )
            if ((Std_ReturnType)E_OK == Status)
            {
                /* Check if all EBs have been setup */
                NumChannelsInJob = pcJobConfig->NumChannels;
                for(ChannelIndex=(Spi_ChannelType)0;ChannelIndex < NumChannelsInJob; ChannelIndex++)
                {
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    ChannelID = pcJobConfig->pcChannelIndexList[ChannelIndex];
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    if (EB == Spi_pcSpiConfigPtr->pcChannelConfig[ChannelID].BufferType)
                    {
                        /* Channel length is 0 for unconfigured ext. buffers */
                        if (0U == Spi_aSpiChannelState[ChannelID].Length)
                        {
                            /* An used EB not initialized  */
                            /*
                            * @violates @ref Spi_c_REF_9 If a function returns error information,
                            *           then that error information shall be tested.
                            */
                            Det_ReportError((uint16) SPI_MODULE_ID, (uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_PARAM_EB_UNIT);
                            Status = (Std_ReturnType)E_NOT_OK;
                            break;
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
            }
            else
            {
                /* Do nothing */
            }
#endif /* ((SPI_CHANNEL_BUFFERS_ALLOWED == USAGE1) || (SPI_CHANNEL_BUFFERS_ALLOWED == USAGE2) ) */
            if ((Std_ReturnType)E_NOT_OK == Status)
            {
                /* break */
                break;
            }
            else
            {
                /* Do nothing */
            }           
        }        
        
        if ((Std_ReturnType)E_NOT_OK != Status)
        {
#endif /* (SPI_DEV_ERROR_DETECT == STD_ON) */
            u32SpiSequenceUsedHWUnits = Spi_au32SpiSeqUsedHWUnits[Sequence];

            SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_01();

            /* check if there are HW units already running */

            if ( 0u != (Spi_u32SpiBusySyncHWUnitsStatus & u32SpiSequenceUsedHWUnits) )
            {
                Status = (Std_ReturnType)E_NOT_OK;

                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();

#if (SPI_DEV_ERROR_DETECT == STD_ON)
                 /* Call Det_ReportError */
                /*
                * @violates @ref Spi_c_REF_9 If a function returns error information,
                *           then that error information shall be tested.
                */
                Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SYNCTRANSMIT_ID,SPI_E_SEQ_IN_PROCESS);
 
#endif
            }
            else
            {
                /* Set the sequence as pending */
                pSequenceState = &Spi_aSpiSequenceState[Sequence];
                pSequenceState->Result = (Spi_SeqResultType) SPI_SEQ_PENDING;

                /* set used HW units as busy */
                Spi_u32SpiBusySyncHWUnitsStatus |= u32SpiSequenceUsedHWUnits;

                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_01();

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
                pSequenceCache = Spi_Ipw_apOneJobSeqsOptimized[Sequence];
                if (NULL_PTR != pSequenceCache)
                {
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    pcSequenceConfig = &Spi_pcSpiConfigPtr->pcSequenceConfig[Sequence];
                    /* Get the job id */
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    Job = pcSequenceConfig->pcJobIndexList[0];
                    /*
                    * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
                    */
                    pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Job];
                    /* start job notification to assert the non-cs pin,
                            when non-cs pin is used as chipselect*/
                    if (NULL_PTR != pcJobConfig->pfStartNotification)
                    {
                        pcJobConfig->pfStartNotification();
                    }
                    else
                    {
                        /* Do nothing */
                    }
                    Status = Spi_Ipw_SyncTransmit_Fast(pSequenceCache);
                    /* end job notification to assert the non-cs pin,
                    when non-cs pin is used as chipselect*/
                    if (NULL_PTR != pcJobConfig->pfEndNotification)
                    {
                        pcJobConfig->pfEndNotification();
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    Status = Spi_Ipw_SyncTransmit(Sequence);
                }
#else /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES != STD_ON) */
                Status = Spi_Ipw_SyncTransmit(Sequence);
#endif

                SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_02();

                if ((Std_ReturnType)E_OK == Status)
                {
                    /* Set the sequence as OK */
                    pSequenceState->Result = SPI_SEQ_OK;
                }
                else
                {
                    /* Set the sequence as FAILED */
                    pSequenceState->Result = SPI_SEQ_FAILED;
                }

                /* set used HW units as idle */
                Spi_u32SpiBusySyncHWUnitsStatus &= (~u32SpiSequenceUsedHWUnits);

                SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_02();

            }

#if (SPI_DEV_ERROR_DETECT == STD_ON)
        }
        else
        {
            /* Do nothing */
        }
    }
#endif

    return Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

/*================================================================================================*/
#if (SPI_HW_STATUS_API == STD_ON)
/**
* @brief   This function is used to request the status of a specific SPI peripheral unit.
* @details This function is used to request the status of a specific SPI peripheral unit.
*          - Service ID:       0x0b
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      HWUnit              The HW peripheral for which we need the status
*
* @return Spi_StatusType
* @retval SPI_UNINIT  The peripheral is un-initialized
* @retval SPI_IDLE    The peripheral is in idle state
* @retval SPI_BUSY    The peripheral is busy
*
* @pre  The driver needs to be initialized before calling Spi_GetHWUnitStatus()
*       otherwise, the function Spi_GetHWUnitStatus() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  SPI_HW_STATUS_API == STD_ON
*
* @implements Spi_GetHWUnitStatus_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Spi_StatusType, SPI_CODE) Spi_GetHWUnitStatus
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    )
{
    VAR(Spi_StatusType, AUTOMATIC) Status;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (Spi_pcSpiConfigPtr == NULL_PTR)
    {
        Status = SPI_UNINIT;
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETHWUNITSTATUS_ID,SPI_E_UNINIT);

    }
    else if (HWUnit >= SPI_MAX_HWUNIT)
    {
        Status = SPI_UNINIT;
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_GETHWUNITSTATUS_ID,SPI_E_PARAM_UNIT);
    }
    else
    {
#endif
        Status = Spi_aSpiHWUnitQueueArray[HWUnit].Status;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}
#endif
/*================================================================================================*/
#if (SPI_CANCEL_API == STD_ON)
/**
* @brief   This function is used to request the cancelation of the given sequence.
* @details This function is used to request the cancelation of the given sequence.
*          - Service ID:       0x0c
*          - Sync or Async:       Asynchronous
*          - Reentrancy:       Reentrant
*
* @param[in]      Sequence            Sequence ID
*
* @pre  The driver needs to be initialized before calling Spi_Cancel()
*       otherwise, the function Spi_Cancel() shall raise the development error
*       if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_CANCEL_API shall be STD_ON
* @post  The SPI Handler Driver is not responsible on external devices damages or
*       undefined state due to cancelling a sequence transmission.
*
* @implements Spi_Cancel_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_Cancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (Spi_pcSpiConfigPtr == NULL_PTR)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_UNINIT);
    }
    /* Sequence Valid Range  from 0 to Spi_Max_Sequence*/
    else if (Sequence > Spi_pcSpiConfigPtr->Spi_Max_Sequence)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_CANCEL_ID,SPI_E_PARAM_SEQ);
    }
    else
    {
#endif
        /* Set sequence state to Cancel */
        Spi_aSpiSequenceState[Sequence].Result = SPI_SEQ_CANCELLED;

        /* In Slave mode: Stop sequence immediately */
        #if (SPI_SLAVE_SUPPORT == STD_ON)
        Spi_Ipw_SlaveCancel(Sequence);
        #endif
        
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}
#endif
/*================================================================================================*/
#if (SPI_LEVEL_DELIVERED == LEVEL2)
/**
* @brief   This function specifies the asynchronous mode for the SPI busses handled asynchronously.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          - Service ID:       0x0d
*          - Sync or Async:       Synchronous
*          - Reentrancy:       Non-Reentrant
*
* @param[in]      AsyncMode    This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK      The command ended successfully
* @retval E_NOT_OK  The command has failed
*
* @pre  The driver needs to be initialized before calling Spi_SetAsyncMode()
*       otherwise, the function Spi_SetAsyncMode() shall raise the development
*       error if SPI_DEV_ERROR_DETECT is STD_ON.
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL2
*
* @implements Spi_SetAsyncMode_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_SetAsyncMode
    (
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    )
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (Spi_pcSpiConfigPtr == NULL_PTR)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETASYNCMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        if (SPI_BUSY == Spi_GetAsyncStatus())
        {

#if (SPI_DEV_ERROR_DETECT == STD_ON)
             /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETASYNCMODE_ID,SPI_E_SEQ_PENDING);
             
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* set the async mode for each HW Unit;
               activate/deactivate EOQ interrupts for Async HWUnits */
            for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
            {
                Spi_Ipw_IrqConfig(HWUnit, AsyncMode);
            }
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif

/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON))
/**
* @brief   This function specifies the asynchronous mode for a given HWUnit.
* @details This function specifies the asynchronous mode for the SPI busses
*          handled asynchronously.
*          For synchronous HW units, the function has no impact.
*          The function will fail in two cases:
*          - driver not initialised (SPI_E_UNINIT reported by DET)
*          - a sequence transmission is pending the the asynchronous HW unit
*            (SPI_E_SEQ_PENDING reported by DET)
*
* @param[in]      HWUnit       The ID of the HWUnit to be configured
* @param[in]      AsyncMode    This parameter specifies the asynchronous
*                              operating mode (SPI_POLLING_MODE or
*                              SPI_INTERRUPT_MODE)
*
* @return Std_ReturnType
* @retval E_OK       The command ended successfully
* @retval E_NOT_OK   The command has failed
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL2 and
*       SPI_HWUNIT_ASYNC_MODE should be on STD_ON
*
* @implements Spi_SetHWUnitAsyncMode_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_SetHWUnitAsyncMode
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (Spi_pcSpiConfigPtr == NULL_PTR)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETHWUNITASYNCMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (HWUnit >= SPI_MAX_HWUNIT)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETHWUNITASYNCMODE_ID,SPI_E_PARAM_UNIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        if (SPI_PHYUNIT_ASYNC_U32 != Spi_pcSpiConfigPtr->pcHWUnitConfig[HWUnit].u32IsSync)
        {
            /* return E_NOT_OK if HWUnit is Sync */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
            /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETHWUNITASYNCMODE_ID,SPI_E_PARAM_UNIT);
#endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else if (SPI_BUSY == Spi_aSpiHWUnitQueueArray[HWUnit].Status)
        {
        /* return E_NOT_OK if HWUnit is Async and Busy */
#if (SPI_DEV_ERROR_DETECT == STD_ON)
             /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETHWUNITASYNCMODE_ID,SPI_E_SEQ_PENDING);
 #endif
            Status = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* set the async mode & activate/deactivate the interrupts for the HW Unit */
            Spi_Ipw_IrqConfig(HWUnit, AsyncMode);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return Status;
}
#endif /* (SPI_LEVEL_DELIVERED == LEVEL2) && (SPI_HWUNIT_ASYNC_MODE == STD_ON) */

/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function shall asynchronously poll SPI interrupts and call ISR if appropriate.
* @details This function shall asynchronously poll SPI interrupts and call
*          ISR if appropriate.
*          - Service ID:       0x10
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
* @implements Spi_MainFunction_Handling_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void)
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;

    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        for (HWUnit = 0u; HWUnit < (Spi_HWUnitType) SPI_MAX_HWUNIT; HWUnit++)
        {
            if (SPI_BUSY == Spi_aSpiHWUnitQueueArray[HWUnit].Status)
            {
                Spi_Ipw_IrqPoll(HWUnit);
            }
            else
            {
                /* Do nothing */
            }
        }
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/*================================================================================================*/
/**
* @brief   This function starts the transfer of the first scheduled job for a given HW unit.
* @details If the list of scheduled jobs is not empty, pop the first job and
*          start the transfer. Elsewhere, mark the HW unit as IDLE.
*
* @param[in]      pHWUnitQueue     The HW Unit used for scheduling
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
static FUNC(void, SPI_CODE) Spi_ScheduleNextJob
    (
        P2VAR(Spi_HWUnitQueue, AUTOMATIC, SPI_APPL_DATA) pHWUnitQueue
    )
{
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2VAR(Spi_JobType, AUTOMATIC, SPI_APPL_DATA) pJobListHead;
    VAR(sint8, AUTOMATIC) s8Priority;
    VAR(sint8, AUTOMATIC) s8MaxScheduledPriority = pHWUnitQueue->s8MaxScheduledPriority;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_04();
    if (0 > s8MaxScheduledPriority)
    {
        /* no job waiting => mark the HWUnit as IDLE */
        pHWUnitQueue->Status = SPI_IDLE;
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04();
    }
    else
    {
        /* a job is waiting => get the job ID from the highest priority queue */
        pJobListHead = &pHWUnitQueue->aScheduledJobsListHead[s8MaxScheduledPriority];
        Job = *pJobListHead;

        /* set the new head of the list */
        *pJobListHead = Spi_aSpiJobState[Job].AsyncNextJob;

        /* if the list is empty, set the tail accordingly and adjust the
           scheduled priority level */
        if (SPI_JOB_NULL == *pJobListHead)
        {
            /* reset the tail */
            pHWUnitQueue->aScheduledJobsListTail[s8MaxScheduledPriority] = SPI_JOB_NULL;

            /* find the first non empty scheduling queue */
            for (s8Priority = s8MaxScheduledPriority - 1; s8Priority >= 0; s8Priority--)
            {
                if (SPI_JOB_NULL != pHWUnitQueue->aScheduledJobsListHead[s8Priority])
                {
                    /* there is a scheduled Job for this priority level */
                    break;
                }
                else
                {
                    /* Do nothing */
                }
            }

            /* Priority is set on the highest priority queue having
               scheduled jobs, or -1 if no other jobs scheduled */
            pHWUnitQueue->s8MaxScheduledPriority = s8Priority;
        }
        else
        {
            /* Do nothing */
        }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_04();

        /* mark the job as pending */
        Spi_aSpiJobState[Job].Result = SPI_JOB_PENDING;
        /*
        * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
        */
        Spi_Ipw_JobTransfer(&Spi_pcSpiConfigPtr->pcJobConfig[Job]);
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called after a Job has been executed.
* @details The function calls Job and Sequence end notifications and schedules
*          the next job of the sequence or on the liberated HW Unit.
*
* @param[in]    pcJobConfig   The just transmited job pointer.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
*
* @implements Spi_JobTransferFinished_Activity
*/
FUNC(void, SPI_CODE) Spi_JobTransferFinished
    (
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    )
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit = pcJobConfig->HWUnit;
    P2VAR(Spi_HWUnitQueue, AUTOMATIC, SPI_APPL_DATA) pHWUnitQueue = &Spi_aSpiHWUnitQueueArray[HWUnit];
    P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) pJobState = pcJobConfig->pJobState;
    P2VAR(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_DATA) pSequenceState = pJobState->pAsyncCrtSequenceState;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig = pSequenceState->pcSequence;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pcJob;
    VAR(Spi_JobType, AUTOMATIC) Job;

    SchM_Enter_Spi_SPI_EXCLUSIVE_AREA_07();
    pJobState->Result = SPI_JOB_OK;

    /* unlink the job from its sequence */
    pJobState->pAsyncCrtSequenceState = NULL_PTR;

    /* Perform job EndNotification (if there is one) */
    if (NULL_PTR != pcJobConfig->pfEndNotification)
    {
        pcJobConfig->pfEndNotification();
    }
    else
    {
        /* Do nothing */
    }

#if (SPI_CANCEL_API == STD_ON)
    /* Check if current sequence has been cancelled */
    if (SPI_SEQ_CANCELLED == pSequenceState->Result)
    {

        /* unlock jobs */
        Spi_UnlockRemainingJobs(pSequenceState->RemainingJobs, pcSequenceConfig);
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07();

        if (NULL_PTR != pcSequenceConfig->pfEndNotification)
        {
            pcSequenceConfig->pfEndNotification();
        }
        else
        {
            /* Do nothing */
        }
        Spi_ScheduleNextJob(pHWUnitQueue);
    }
    else
    {
#endif
        /* Check if this job is the last one */
        if (0u == pSequenceState->RemainingJobs)
        {
            /* Reset sequence state */
            pSequenceState->Result = SPI_SEQ_OK;
            SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07();
            
            /* SeqEndNotification */
            if (NULL_PTR != pcSequenceConfig->pfEndNotification)
            {
                pcSequenceConfig->pfEndNotification();
            }
            else
            {
                /* Do nothing */
            }

            Spi_ScheduleNextJob(pHWUnitQueue);

        }
        else
        {
            /* advance to the next job */
            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pSequenceState->pcCurrentJobIndexPointer++;
            pcJob = pSequenceState->pcCurrentJobIndexPointer;
            Job = *pcJob;
            pSequenceState->RemainingJobs--;

            /*
            * @violates @ref Spi_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic.
            */
            pcJobConfig = &Spi_pcSpiConfigPtr->pcJobConfig[Job];
            if (HWUnit != pcJobConfig->HWUnit)
            {
                /* schedule the next job on the new DSPI unit */
                Spi_ScheduleJob(&Spi_aSpiHWUnitQueueArray[pcJobConfig->HWUnit], Job, pcJobConfig);

                /* transmit the next scheduled job on the current DSPI unit */
                Spi_ScheduleNextJob(pHWUnitQueue);
            }
            else
            {
                /* the next job uses the same DSPI unit */

#if (SPI_INTERRUPTIBLE_SEQ_ALLOWED == STD_ON)
                if (pcSequenceConfig->u8Interruptible)
                {
                    /* if the sequence is interruptible,
                       then schedule the next job */
                    /* DSPI is marked as BUSY => the new job is scheduled only */
                    Spi_ScheduleJob(pHWUnitQueue, Job, pcJobConfig);

                    /* run the first eligible job */
                    Spi_ScheduleNextJob(pHWUnitQueue);
                }
                else
#endif
                {
                    /* non-interruptible sequence =>
                       start transmission without scheduling */
                    /* mark the job as pending */
                    Spi_aSpiJobState[Job].Result = SPI_JOB_PENDING;
                    Spi_Ipw_JobTransfer(pcJobConfig);
                }
            }
        SchM_Exit_Spi_SPI_EXCLUSIVE_AREA_07();
        }
#if (SPI_CANCEL_API == STD_ON)
    }
#endif
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief   This function shall set different MCU clock configuration .
* @details This function shall set different MCU clock configuration .
*
* @param[in]    ClockMode   Clock mode to be set (SPI_NORMAL | SPI_ALTERNATE).
*
* @return Std_ReturnType
* @retval E_OK       The driver is initialised and in an IDLE state. The clock
*                    mode can be changed.
* @retval E_NOT_OK   The driver is NOT initialised OR is NOT in an IDLE state.
*                    The clock mode can NOT be changed.
*
* @pre  Pre-compile parameter SPI_DUAL_CLOCK_MODE shall be STD_ON.
*
* @implements Spi_SetClockMode_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_SetClockMode
    (
        VAR(Spi_DualClockModeType,AUTOMATIC) ClockMode
    )
{
   VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    /* If Development Error Detection is enabled, report error if not */
    /* initialized */
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETCLOCKMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        /* Check if Spi Status is Busy */
        if (SPI_BUSY == Spi_GetStatus())
        {
            Status = (VAR(Std_ReturnType, AUTOMATIC)) E_NOT_OK;
#if (SPI_DEV_ERROR_DETECT == STD_ON)
             /* Call Det_ReportError */
            /*
            * @violates @ref Spi_c_REF_9 If a function returns error information,
            *           then that error information shall be tested.
            */
            Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETCLOCKMODE_ID,SPI_E_SEQ_PENDING);
 #endif
        }
        else
        {
            SPI_IPW_SET_CLOCK_MODE(ClockMode);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
}
#endif
    return Status;
}
#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief   This function shall to enable user to access the Micro Second Bus functionality .
* @details A non-Autosar API to support the configuration of the TSB
* to enable user to access the Micro Second Bus functionality
*
* @param[in]    Spi_JobType   Specifies the job configured in TSB mode
*
* @return Std_ReturnType
* @retval E_OK       The driver is initialised . The TSB  mode can be configured.
* @retval E_NOT_OK   The driver is NOT initialised
*
* @pre  Pre-compile parameter SPI_TSB_MODE shall be STD_ON.
*
* @implements Spi_TSBStart_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_TSBStart
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
       /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETTSBMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (TSBJob > SPI_MAX_TSBJOBS)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETTSBMODE_ID,SPI_E_TSBJOB);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        {
            Spi_Ipw_SetTSBMode(TSBJob);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}
/*================================================================================================*/
/**
* @brief   This function shall to stop teh transfer in TSB mode.
* @details A non-Autosar API to support the configuartion of the TSB
*          Hardware is deinitialized to master and SPI mode.
*
* @param[in]    Spi_JobType   Job configured in TSB mode
*
* @return Std_ReturnType
* @retval E_OK       The driver is initialised . The TSB  mode can be configured.
* @retval E_NOT_OK   The driver is NOT initialised
*
* @pre  Pre-compile parameter SPI_TSB_MODE shall be STD_ON.
*
* @implements Spi_TSBStop_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_TSBStop
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
          /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETTSBMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (TSBJob > SPI_MAX_TSBJOBS)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETTSBMODE_ID,SPI_E_TSBJOB);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        {
            Spi_Ipw_StopTSBMode(TSBJob);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}

/*================================================================================================*/
/**
* @brief   This function shall to enable user to write data in ASDR while using Micro Second Bus.
* @details A non-Autosar API to support the configuartion of the TSB
* to enable user to access the Micro Second Bus functionality
*
* @param[in]    Spi_JobType   Specifies the job confgiured in TSB mode
*
* @return Std_ReturnType
* @retval E_OK      The driver is initialised . The TSB  mode can be configured.
* @retval E_NOT_OK  The driver is NOT initialised
*
* @pre  Pre-compile parameter SPI_TSB_MODE shall be STD_ON.
*
* @implements Spi_TSB_ASDR_DataUpdate_Activity
*/
/*
* @violates @ref Spi_c_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_TSB_ASDR_DataUpdate
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob,
        P2CONST(uint32, AUTOMATIC,SPI_APPL_CONST) pcASDR_Data
    )
{
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;

#if (SPI_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == Spi_pcSpiConfigPtr)
    {
          /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETTSBMODE_ID,SPI_E_UNINIT);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else if (TSBJob > SPI_MAX_TSBJOBS)
    {
        /* Call Det_ReportError */
        /*
        * @violates @ref Spi_c_REF_9 If a function returns error information,
        *           then that error information shall be tested.
        */
        Det_ReportError((uint16) SPI_MODULE_ID,(uint8) 0,SPI_SETTSBMODE_ID,SPI_E_TSBJOB);
        Status = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
#endif
        {
            Spi_Ipw_TSB_ASDR_DataUpdate(TSBJob, pcASDR_Data);
        }
#if (SPI_DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return Status;
}
#endif /*SPI_TSB_MODE == STD_ON*/
#endif /*TSB_MODE_SUPPORTED*/
/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/** @} */

