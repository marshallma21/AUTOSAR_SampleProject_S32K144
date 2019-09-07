/**
*     @file Icu_Ipw_Irq.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Brief description.
*     @details Detailed description.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform ARM
*     Peripheral FTM PORT_CI LPIT LPTMR
*     Dependencies none
*
*     Autosar Version 4.2.2
*     Autosar Revision ASR_REL_4_2_REV_0002
*     Autosar ConfVariant
*     SWVersion 1.0.1
*     BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_IPW_IRQ_H
#define ICU_IPW_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
*
* @section ICU_IPW_IRQ_h_REF_1
*           Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*           the contents of a header file being included twice
*           This is not a violation since all header files are protected against multiple inclusions
* @section ICU_IPW_IRQ_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to IP functions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Icu_Types.h"
#include "Icu_Irq.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_IRQ_VENDOR_ID                       43

#define ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION        2
#define ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION     2
#define ICU_IPW_IRQ_SW_MAJOR_VERSION                1
#define ICU_IPW_IRQ_SW_MINOR_VERSION                0
#define ICU_IPW_IRQ_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (ICU_IPW_IRQ_VENDOR_ID != ICU_TYPES_VENDOR_ID)
#error "Icu_Ipw_Irq.h and Icu_Types.h have different vendor IDs"
#endif
/* Check if Icu_Ipw_Irq file and Icu_Types header file are of the same Autosar version */
#if ((ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Types.h and Icu_Ipw_Irq.h are different"
#endif
/* Check if Icu_Ipw_Irq file and Icu_Types header file are of the same Software version */
#if ((ICU_IPW_IRQ_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_IRQ_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_IRQ_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Types.h and Icu_Ipw_Irq.h are different"
#endif

#if (ICU_IPW_IRQ_VENDOR_ID != ICU_IRQ_VENDOR_ID)
#error "Icu_Ipw_Irq.h and Icu_Irq.h have different vendor IDs"
#endif
/* Check if source file and Icu_Irq header file are of the same Autosar version */
#if ((ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION != ICU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION != ICU_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Irq.h and Icu_Ipw_Irq.h are different"
#endif
/* Check if source file and Icu_Irq header file are of the same Software version */
#if ((ICU_IPW_IRQ_SW_MAJOR_VERSION != ICU_IRQ_SW_MAJOR_VERSION) || \
     (ICU_IPW_IRQ_SW_MINOR_VERSION != ICU_IRQ_SW_MINOR_VERSION) || \
     (ICU_IPW_IRQ_SW_PATCH_VERSION != ICU_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Irq.h and Icu_Ipw_Irq.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/


#define ICU_START_SEC_CODE
/*
* @violates @ref ICU_IPW_IRQ_h_REF_1 Precautions shall be taken in order to prevent the contents of
* a header file being included twice
*/
#include "Icu_MemMap.h"

/**
* @brief Mapping macro between get edge numbers eTimer functionality and high level function
*
* @violates @ref ICU_IPW_IRQ_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define Icu_Ipw_ReportEvents(hwChannel, overflow) \
        do { \
            Icu_ReportEvents((Icu_ChannelType)(hwChannel), (overflow));\
        } while(0)
/**
* @brief Mapping macro between get edge numbers eTimer functionality and high level function
*
* @violates @ref ICU_IPW_IRQ_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define Icu_Ipw_ReportWakeupAndOverflow(hwChannel, overflow) \
        do { \
            Icu_ReportWakeupAndOverflow((Icu_ChannelType)(hwChannel), (overflow));\
        } while(0)

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief Mapping macro between get edge numbers eTimer functionality and high level function
 *
 * @violates @ref ICU_IPW_IRQ_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
 #define Icu_Ipw_Timestamp(hwChannel,capturedWords,bufferPtr,overflow) \
        do { \
            Icu_Timestamp((Icu_ChannelType)(hwChannel),(capturedWords),(bufferPtr),(overflow));\
        } while(0)
#endif /* ICU_TIMESTAMP_API == STD_ON */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief Mapping macro between get edge numbers eTimer functionality and high level function
*
* @violates @ref ICU_IPW_IRQ_h_REF_2  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Icu_Ipw_SignalMeasurement(hwChannel, activePulseWidth, period, overflow) \
        do { \
            Icu_SignalMeasurement((Icu_ChannelType)(hwChannel), (activePulseWidth), (period), (overflow));\
        } while(0)
#endif

#define ICU_STOP_SEC_CODE
/*
* @violates @ref ICU_IPW_IRQ_h_REF_1 Precautions shall be taken in order to prevent the contents of
* a header file being included twice
*/
#include "Icu_MemMap.h"

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


#ifdef __cplusplus
}
#endif

#endif  /* ICU_IPW_IRQ_H */
/** @} */

