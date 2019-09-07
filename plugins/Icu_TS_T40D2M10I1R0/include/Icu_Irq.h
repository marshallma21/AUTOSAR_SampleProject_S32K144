/**
*     @file    Icu_Irq.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - ICU driver header file.
*     @details ICU driver header file, containing the Autosar API specification and other variables
*              and functions that are exported by the ICU driver.
*
*     @addtogroup ICU_IRQ_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : FTM PORT_CI LPIT LPTMR
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

#ifndef ICU_IRQ_H
#define ICU_IRQ_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Irq_h_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
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



/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* */
#define ICU_IRQ_VENDOR_ID                       43
#define ICU_IRQ_MODULE_ID                       122

#define ICU_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IRQ_AR_RELEASE_MINOR_VERSION        2
#define ICU_IRQ_AR_RELEASE_REVISION_VERSION     2
#define ICU_IRQ_SW_MAJOR_VERSION                1
#define ICU_IRQ_SW_MINOR_VERSION                0
#define ICU_IRQ_SW_PATCH_VERSION                1

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


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

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_Irq_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

FUNC(void, ICU_CODE) Icu_ReportWakeupAndOverflow(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                                 VAR(boolean, AUTOMATIC) bOverflow
                                                );
FUNC(void, ICU_CODE) Icu_ReportEvents(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                      VAR(boolean, AUTOMATIC) bOverflow
                                     );
#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void,ICU_CODE)  Icu_Timestamp(VAR(Icu_ChannelType, AUTOMATIC)hwChannel,
                                   VAR(uint8, AUTOMATIC)u8CapturedWords,
                                   P2CONST(Icu_ValueType, AUTOMATIC, ICU_APPL_CONST)pBufferPtr,
                                   VAR(boolean, AUTOMATIC) bOverflow
                                  );
#endif
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC(void,ICU_CODE) Icu_SignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC)hwChannel,
                                          VAR(Icu_ValueType, AUTOMATIC)activePulseWidth,
                                          VAR(Icu_ValueType, AUTOMATIC)period,
                                          VAR(boolean, AUTOMATIC) bOverflow
                                         );
#endif
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
FUNC(void,ICU_CODE) Icu_TimestampDmaProcessing(VAR(Icu_ChannelType, AUTOMATIC)Channel);
#endif
#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
FUNC(void,ICU_CODE) Icu_SignalMeasurementDmaProcessing(VAR(Icu_ChannelType, AUTOMATIC)Channel);
#endif

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_Irq_h_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_IRQ_H */
/** @} */

