/**
*    @file    Ocu_Ftm_Irq.h
*    @version 1.0.0
*
*    @brief   AUTOSAR Ocu - eTIMER header file support for OCU driver.
*    @details eTIMER header file, containing the variables and functions that are exported by the IP driver.
*
*    @addtogroup OCU_MODULE
*    @{
*/
/*==================================================================================================
*    Project               : AUTOSAR 4.2 MCAL
*    Platform              : ARM
*    Peripheral            : Ftm
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
=====================================================================================================*/
/*===================================================================================================
======================================================================================================*/

#ifndef OCU_FTM_IRQ_H
#define OCU_FTM_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section OCU_FTM_IRQ_H_REF_1
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
#include "Ocu_Ftm_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define OCU_FTM_IRQ_VENDOR_ID                       43
#define OCU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define OCU_FTM_IRQ_AR_RELEASE_MINOR_VERSION        2
#define OCU_FTM_IRQ_AR_RELEASE_REVISION_VERSION     2
#define OCU_FTM_IRQ_SW_MAJOR_VERSION                1
#define OCU_FTM_IRQ_SW_MINOR_VERSION                0
#define OCU_FTM_IRQ_SW_PATCH_VERSION                1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Ocu_Ftm_Irq.h file and  Ocu_Ftm_Types header file are of the same vendor */
#if (OCU_FTM_IRQ_VENDOR_ID != OCU_FTM_TYPES_VENDOR_ID)
    #error "Ocu_Ftm_Irq.h and Ocu_Ftm_Types.h have different vendor IDs"
#endif

#if ((OCU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION != OCU_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_IRQ_AR_RELEASE_MINOR_VERSION != OCU_FTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_IRQ_AR_RELEASE_REVISION_VERSION != OCU_FTM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ocu_Ftm_Irq.h and Ocu_Ftm_Types.h are different"
#endif

/*Check if Ocu_Ftm_Irq.h file and Ocu_Ftm_Types header file are of the same Software version*/
#if ((OCU_FTM_IRQ_SW_MAJOR_VERSION != OCU_FTM_TYPES_SW_MAJOR_VERSION) || \
     (OCU_FTM_IRQ_SW_MINOR_VERSION != OCU_FTM_TYPES_SW_MINOR_VERSION) || \
     (OCU_FTM_IRQ_SW_PATCH_VERSION != OCU_FTM_TYPES_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Ocu_Ftm_Irq.h and Ocu_Ftm_Types.h are different"
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
#define OCU_START_SEC_CODE
/*
* @violates @ref OCU_FTM_IRQ_H_REF_1 precautions to prevent the
*       contents of a header file being included twice  */
#include "Ocu_MemMap.h"



#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, OCU_CODE) Ocu_Ftm_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8FtmChannel);
#endif

#define OCU_STOP_SEC_CODE
/*
* @violates @ref OCU_FTM_IRQ_H_REF_1 precautions to prevent the
*       contents of a header file being included twice
*/
#include "Ocu_MemMap.h"



#ifdef __cplusplus
}
#endif

#endif  /* OCU_FTM_IRQ_H */

/** @} */
