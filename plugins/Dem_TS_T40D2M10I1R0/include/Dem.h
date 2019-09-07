/**
*   @file    Dem.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Dem - module interface
*   @details This file contains the functions prototypes and data types of the AUTOSAR Dem.
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
#ifndef DEM_H
#define DEM_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dem_IntErrId.h"
#include "Dem_Types.h"  

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define DEM_VENDOR_ID        43
#define DEM_MODULE_ID        54
#define DEM_AR_RELEASE_MAJOR_VERSION        4
#define DEM_AR_RELEASE_MINOR_VERSION        2
#define DEM_AR_RELEASE_REVISION_VERSION     2
#define DEM_SW_MAJOR_VERSION 1
#define DEM_SW_MINOR_VERSION 0
#define DEM_SW_PATCH_VERSION 1
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (DEM_VENDOR_ID != DEM_INTERRID_VENDOR_ID)
#error "Dem.h and Dem_IntErrId.h have different vendor ids"
#endif


#if ((DEM_AR_RELEASE_MAJOR_VERSION != DEM_INTERRID_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != DEM_INTERRID_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION != DEM_INTERRID_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dem.h and Dem_IntErrId.h are different"
#endif


#if ((DEM_SW_MAJOR_VERSION != DEM_INTERRID_SW_MAJOR_VERSION) || \
     (DEM_SW_MINOR_VERSION != DEM_INTERRID_SW_MINOR_VERSION) || \
     (DEM_SW_PATCH_VERSION != DEM_INTERRID_SW_PATCH_VERSION))
#error "Software Version Numbers of Dem.h and Dem_IntErrId.h are different"
#endif

#if (DEM_VENDOR_ID != DEM_TYPES_VENDOR_ID)
#error "Dem.h and Dem_Types.h have different vendor ids"
#endif

#if ((DEM_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dem.h and Dem_Types.h are different"
#endif

#if ((DEM_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
     (DEM_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
     (DEM_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Dem.h and Dem_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Max length value of extended data kept by Dem when Dem_ReportErrorStatusPreExtData() API is called */
#define DEM_MAX_EXTENDED_DATA_LENGTH_U8         (uint8)(100U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern VAR(Dem_EventIdType    , DEM_VAR) Dem_EventId[256];      /**< @brief DEM event ID*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_EventStatus[256];  /**< @brief DEM event status*/
extern VAR(Dem_EventStatusType, DEM_VAR) Dem_au8ExtendedData[DEM_MAX_EXTENDED_DATA_LENGTH_U8];  /**< @brief DEM event status*/
extern VAR(uint8, DEM_VAR)               Dem_OverflowEvent; /**< @brief DEM Overflow Event*/
 
extern VAR(uint32, DEM_VAR)              Dem_numEventErrors;  /**< @brief DEM event number of errors*/
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
FUNC(void, DEM_CODE) Dem_ReportErrorStatus       (VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus);
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(VAR(Dem_EventIdType, AUTOMATIC) EventId, VAR(Dem_EventStatusType, AUTOMATIC) EventStatus);
FUNC(Std_ReturnType, DEM_CODE) Dem_ReportErrorStatusPreExtData(VAR(Dem_EventIdType, AUTOMATIC) Dem_EventIdRaw,
            VAR(Dem_EventStatusType, AUTOMATIC) Dem_EventStatusRaw,
            CONSTP2CONST(uint8, DEM_CONST, DEM_APPL_CONST) Dem_pui8_PreExtData,
            VAR(uint8, AUTOMATIC) Dem_PreExtDataSize);
            
            
#ifdef __cplusplus
}
#endif

#endif /* #ifndef DEM_H */
