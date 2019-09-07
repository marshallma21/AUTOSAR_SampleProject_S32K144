/**
*   @file    Dem.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Dem - module implementation
*   @details This module implements stubs for the AUTOSAR Dem
*            This file contains sample code only. It is not part of the production code deliverables
*
*   @addtogroup DEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
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
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Dem.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define DEM_VENDOR_ID_C         43
#define DEM_AR_RELEASE_MAJOR_VERSION_C  4
#define DEM_AR_RELEASE_MINOR_VERSION_C  2
#define DEM_AR_RELEASE_REVISION_VERSION_C  2
#define DEM_SW_MAJOR_VERSION_C  1
#define DEM_SW_MINOR_VERSION_C  0
#define DEM_SW_PATCH_VERSION_C  1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and DEM header file are of the same vendor */
#if (DEM_VENDOR_ID_C != DEM_VENDOR_ID)
    #error "Dem.c and Dem.h have different vendor ids"
#endif

/* Check if source file and DEM header file are of the same Autosar version */
#if ((DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Dem.c and Dem.h are different"
#endif

/* Check if source file and DEM header file are of the same Software version */
#if ((DEM_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
     (DEM_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
     (DEM_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Dem.c and Dem.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if DEM source file and STD_TYPES header file are of the same Software version */
    #if ((DEM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
        (DEM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Dem.C and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define DEM_MAX_NUMBER_OF_EVENTS (uint32)256

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
/**< @brief DEM byte array storing reported extended data */
VAR(uint8, DEM_VAR) Dem_au8ExtendedData[DEM_MAX_EXTENDED_DATA_LENGTH_U8];   


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/* Variable Definition */
VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];                 /**< @brief DEM event ID*/
VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];             /**< @brief DEM event status*/
VAR(uint8, DEM_VAR)               Dem_OverflowEvent;                /**< @brief DEM Overflow Event*/
 
VAR(uint32, DEM_VAR)              Dem_numEventErrors = (uint32)0;  /**< @brief DEM event number of errors*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/** 
* @brief   This function reports the error status. 
* @details This is a function stub only. It loads Dem_EventId = EventId and 
*          Dem_EventStatus = EventStatus and increments Dem_numEventErrors
*     
* @param[in]     EventId      ID of the event
* @param[in]     EventStatus  status of the event
*   
*/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus)
{
        if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors)
        {
            Dem_EventId[Dem_numEventErrors] = EventId;
            Dem_EventStatus[Dem_numEventErrors] = EventStatus;
            Dem_numEventErrors++;
            Dem_OverflowEvent = 0U;
        }
        else
        {
            Dem_EventId[(Dem_numEventErrors-1)] = EventId;
            Dem_EventStatus[(Dem_numEventErrors-1)] = EventStatus;
            Dem_OverflowEvent = 1U;
        }
}

/*================================================================================================*/
/** 
* @brief   This function sets the error status. 
* @details This is a function stub only. It loads Dem_EventId2 = EventId and 
*          Dem_EventStatus2 = EventStatus and returns success.
*     
* @param[in]     EventId        ID of the event
* @param[in]     EventStatus    status of the event 
* @return        Std_ReturnType This function is always successful
*   
*/
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus)
{
    if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors)
    {
        Dem_EventId[Dem_numEventErrors] = EventId;
        Dem_EventStatus[Dem_numEventErrors] = EventStatus;
        Dem_numEventErrors++;
        Dem_OverflowEvent = 0U;
    }
    else
    {
        Dem_EventId[(Dem_numEventErrors-1)] = EventId;
        Dem_EventStatus[(Dem_numEventErrors-1)] = EventStatus;
        Dem_OverflowEvent = 1U;
    }
    return(E_OK);
}

/** 
* Description:    NON-AUTOSAR DEM function: 
*                 This function shall be used to report the Event Status from a monitoring function as soon as a new test result is available. 
*                 This function has to be used if pre-extended data shall be logged at the time the event has been reported as "Failed".
*                 In case the EvTestResult is "Passed" the parameters pPreExtData and PreExtDataSize will be ignored.                                   
* 
* Return value:   Std_ReturnType: E_OK (0x00) Operation was successful ; E_NOT_OK (0x01) Operation failed 
*  
* Preconditions:  None: function can be called at any time during startup-phase. Functions "Dem_PreInit()" and "Dem_Init()" do not have to be called before. 
* Postconditions: - 
*  
* ************************************************************************** 
* PARAMETERS: 
*    Dem_EventIdRaw      [In] Identification of the event 
*    Dem_EventStatus     [In] DEM_EVENT_STATUS_PASSED or DEM_EVENT_STATUS_FAILED 
*    Dem_pui8_PreExtData [In] Pointer to pre-extended data 
*    Dem_PreExtDataSize  [In] Size of pre-extended data 
*  
* **************************************************************************/
FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatusPreExtData
( 
    VAR(Dem_EventIdType, AUTOMATIC) Dem_EventIdRaw, 
    VAR(Dem_EventStatusType, AUTOMATIC) Dem_EventStatusRaw, 
    CONSTP2CONST(uint8, DEM_CONST, DEM_APPL_CONST) Dem_pui8_PreExtData, 
    VAR(uint8, AUTOMATIC) Dem_PreExtDataSize 
)
{
    VAR(uint8,          DEM_VAR) u8Counter;
    VAR(Std_ReturnType, DEM_VAR) retVal = (Std_ReturnType)E_OK;
    if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors)
    {
        Dem_EventId[Dem_numEventErrors] = Dem_EventIdRaw;
        Dem_EventStatus[Dem_numEventErrors] = Dem_EventStatusRaw;
        Dem_numEventErrors++;
        Dem_OverflowEvent = 0U;
    }
    else
    {
        Dem_EventId[(Dem_numEventErrors-1)] = Dem_EventIdRaw;
        Dem_EventStatus[(Dem_numEventErrors-1)] = Dem_EventStatusRaw;
        Dem_OverflowEvent = 1U;
    }
    
    /* Store extended data only if Dem_EventStatus is set to DEM_EVENT_STATUS_FAILED */
    if ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED == Dem_EventStatusRaw)
    {
        /* Check if the extended data fits in the DEM statically allocated buffer */
        if (Dem_PreExtDataSize <= DEM_MAX_EXTENDED_DATA_LENGTH_U8)
        {
            for(u8Counter=0; u8Counter<Dem_PreExtDataSize; u8Counter++)
            {
                Dem_au8ExtendedData[u8Counter] = Dem_pui8_PreExtData[u8Counter];
            }
        }
        else
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }
    
    return retVal;
}

#ifdef __cplusplus
}
#endif

/** @} */

