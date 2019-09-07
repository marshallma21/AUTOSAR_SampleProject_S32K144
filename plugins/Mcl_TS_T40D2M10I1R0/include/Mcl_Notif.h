/**
*     @file    Mcl_Notif.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Mcl - MCL driver header file.
*     @details MCL driver header file, containing the Autosar API specification and other variables
*              and functions that are exported by the MCL driver.
*
*     @addtogroup MCL_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : eDMA
*     Dependencies        : none
*
*     Autosar Version     :  4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant :
*     SWVersion           : 1.0.1
*     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef MCL_NOTIF_H
#define MCL_NOTIF_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Notif_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcl_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_NOTIF_VENDOR_ID                       43
#define MCL_NOTIF_MODULE_ID                       255
#define MCL_NOTIF_AR_RELEASE_MAJOR_VERSION        4
#define MCL_NOTIF_AR_RELEASE_MINOR_VERSION        2
#define MCL_NOTIF_AR_RELEASE_REVISION_VERSION     2
#define MCL_NOTIF_SW_MAJOR_VERSION                1
#define MCL_NOTIF_SW_MINOR_VERSION                0
#define MCL_NOTIF_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
    /* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_NOTIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_NOTIF_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcl_Notif.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Mcl types header file are of the same vendor */
#if (MCL_NOTIF_VENDOR_ID != MCL_TYPES_VENDOR_ID)
    #error "Mcl_Notif.h and Mcl_Types.h have different vendor IDs"
#endif
    /* Check if header file and Mcl types header file are of the same Autosar version */
#if ((MCL_NOTIF_AR_RELEASE_MAJOR_VERSION != MCL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_NOTIF_AR_RELEASE_MINOR_VERSION != MCL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_NOTIF_AR_RELEASE_REVISION_VERSION != MCL_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcl_Notif.h and Mcl_Types.h are different"
#endif
/* Check if header file and Mcl types header file are of the same software version */
#if ((MCL_NOTIF_SW_MAJOR_VERSION != MCL_TYPES_SW_MAJOR_VERSION) || \
     (MCL_NOTIF_SW_MINOR_VERSION != MCL_TYPES_SW_MINOR_VERSION) || \
     (MCL_NOTIF_SW_PATCH_VERSION != MCL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcl_Notif.h and Mcl_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*================================================================================================*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)

#define MCL_START_SEC_CODE
/*
* @violates @ref Mcl_Notif_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Mcl_MemMap.h"

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
FUNC (void, MCL_CODE) Mcl_Notification
(
    VAR(Mcl_ChannelType, AUTOMATIC) Channel
);
#endif /* (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) */

#if (MCL_REPORT_UNEXPECTED_ISR == STD_ON)
FUNC (void, MCL_CODE) Mcl_ReportUnexpectedIsrError
(
    void
);
#endif /* (MCL_REPORT_UNEXPECTED_ISR == STD_ON) */

#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
FUNC (void, MCL_CODE) Mcl_ErrorNotification(VAR(Mcl_DmaInstanceType, AUTOMATIC) DmaHwInstance, VAR(Mcl_DmaChannelErrorStatusType, AUTOMATIC) Error);
#endif /*(MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON) */

#define MCL_STOP_SEC_CODE
/*
* @violates @ref Mcl_Notif_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Mcl_MemMap.h"

#endif /* (MCL_ENABLE_DMA == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif  /* MCL_NOTIF_H */
/** @} */

