/**
*    @file    Icu_Ftm_Irq.h
*    @version 1.0.1
*
*    @brief   AUTOSAR Icu - Ftm header file support for ICU driver.
*    @details Ftm header file, containing the variables and functions that are exported by the IP driver.
*
*    @addtogroup ICU_MODULE
*    @{
*/
/*==================================================================================================
*    Project               : AUTOSAR 4.2 MCAL
*    Platform              : ARM
*    Peripheral            : FTM PORT_CI LPIT LPTMR
*    Dependencies          : none
*
*    Autosar Version       : 4.2.2
*    Autosar Revision      : ASR_REL_4_2_REV_0002
*    Autosar Conf.Variant  :
*    SWVersion             : 1.0.1
*    BuildVersion          : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*    All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_FTM_IRQ_H
#define ICU_FTM_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section ICU_FTM_IRQ_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Ftm_Types.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define ICU_FTM_IRQ_VENDOR_ID                       43
#define ICU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define ICU_FTM_IRQ_AR_RELEASE_MINOR_VERSION        2
#define ICU_FTM_IRQ_AR_RELEASE_REVISION_VERSION     2
#define ICU_FTM_IRQ_SW_MAJOR_VERSION                1
#define ICU_FTM_IRQ_SW_MINOR_VERSION                0
#define ICU_FTM_IRQ_SW_PATCH_VERSION                1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_Ftm_Irq.h file and  Icu_Ftm_Types header file are of the same vendor */
#if (ICU_FTM_IRQ_VENDOR_ID != ICU_FTM_TYPES_VENDOR_ID)
    #error "Icu_Ftm_Irq.h and Icu_Ftm_Types.h have different vendor IDs"
#endif

#if ((ICU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_IRQ_AR_RELEASE_MINOR_VERSION != ICU_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_IRQ_AR_RELEASE_REVISION_VERSION != ICU_FTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm_Irq.h and Icu_Ftm_Types.h are different"
#endif

/*Check if Icu_Ftm_Irq.h file and Icu_Ftm_Types header file are of the same Software version*/
#if ((ICU_FTM_IRQ_SW_MAJOR_VERSION != ICU_FTM_TYPES_SW_MAJOR_VERSION) || \
     (ICU_FTM_IRQ_SW_MINOR_VERSION != ICU_FTM_TYPES_SW_MINOR_VERSION) || \
     (ICU_FTM_IRQ_SW_PATCH_VERSION != ICU_FTM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm_Irq.h and Icu_Ftm_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

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
#define ICU_START_SEC_CODE
/*
* @violates @ref ICU_FTM_IRQ_H_REF_1 precautions to prevent the
*       contents of a header file being included twice  */
#include "Icu_MemMap.h"

FUNC(void, ICU_CODE) Icu_Ftm_ProcessInterrupt(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

FUNC(void, ICU_CODE) Icu_Ftm_ProcessTofInterrupt(CONST(uint8, AUTOMATIC) u8hwModuleNo);

#define ICU_STOP_SEC_CODE
/*
* @violates @ref ICU_FTM_IRQ_H_REF_1 precautions to prevent the
*       contents of a header file being included twice
*/
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* ICU_FTM_IRQ_H */

/** @} */
