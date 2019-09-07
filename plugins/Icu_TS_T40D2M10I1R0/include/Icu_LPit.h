/**
*     @file    Icu_LPit.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - LPit low level driver exported functions.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver
              (platform dependent).
*
*     *     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : ARM
*     Peripheral          : FTM PORT_CI LPIT LPTMR
*     Dependencies        : none
*
*     Autosar Version     : 4.2.2
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


#ifndef ICU_LPIT_H
#define ICU_LPIT_H

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_LPit_h_REF_1
*           Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced
*           initialiser, a constant, a parenthesised expression, a type qualifier, a storage class
*           specifier, or a do-while-zero construct.
*           This is used to route calls from AUTOSAR to hardware layer
*
* @section Icu_LPit_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
*
* @section Icu_LPit_h_REF_3
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice.
*          All header files are protected against multiple inclusions
*
* @section [global]
*        Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*        on the significance of more than 31 characters. The used compilers use more than 31 chars
*        for identifiers.
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_LPit_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_LPIT_VENDOR_ID                    43

#define ICU_LPIT_AR_RELEASE_MAJOR_VERSION     4
#define ICU_LPIT_AR_RELEASE_MINOR_VERSION     2
#define ICU_LPIT_AR_RELEASE_REVISION_VERSION  2
#define ICU_LPIT_SW_MAJOR_VERSION             1
#define ICU_LPIT_SW_MINOR_VERSION             0
#define ICU_LPIT_SW_PATCH_VERSION             1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Icu_LPit_Types.h file are of the same vendor */
#if (ICU_LPIT_VENDOR_ID != ICU_LPIT_TYPES_VENDOR_ID)
#error "Icu_LPit.h and Icu_LPit_Types.h have different vendor IDs"
#endif
#if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION != ICU_LPIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_MINOR_VERSION != ICU_LPIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_REVISION_VERSION != ICU_LPIT_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_LPit.h and Icu_LPit_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_LPIT_SW_MAJOR_VERSION != ICU_LPIT_TYPES_SW_MAJOR_VERSION) || \
     (ICU_LPIT_SW_MINOR_VERSION != ICU_LPIT_TYPES_SW_MINOR_VERSION) || \
     (ICU_LPIT_SW_PATCH_VERSION != ICU_LPIT_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LPit.h and Icu_LPit_Types.h are different"
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
/**
* @brief            LPit_ChannelModeType
* @details          Type that indicates the channel mode type(capture mode, edge counter).
*
* */
typedef enum
{
    LPIT_CHANNEL_MODE_SIGNAL_EDGE_DETECT    = 0x01U, /*< @brief Mode for detecting edges.  */
    LPIT_CHANNEL_MODE_TIMESTAMP             = 0x04U, /*< @brief Mode for capturing timer values */
                                                     /*  on configurable edges. */
} Icu_LPit_ChannelMeasurementModeType;
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @violates @ref Icu_LPit_h_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Icu_MemMap.h"

FUNC(void, ICU_CODE) Icu_LPit_Init(P2CONST(Icu_LPit_IpConfigType,AUTOMATIC, ICU_APPL_CONST) pLPitIpConfig);

#if (ICU_DE_INIT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_LPit_DeInit(P2CONST(Icu_LPit_IpConfigType,AUTOMATIC, ICU_APPL_CONST) pLPitIpConfig);
#endif

#if (ICU_SET_MODE_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_LPit_SetSleepMode(VAR(Icu_LPit_ChannelType,     AUTOMATIC) hwChannel);
 FUNC(void, ICU_CODE) Icu_LPit_SetNormalMode(VAR(Icu_LPit_ChannelType,    AUTOMATIC) hwChannel);
#endif  /* ICU_SET_MODE_API  */


#if (ICU_EDGE_DETECT_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_LPit_EnableEdgeDetection(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel);
 FUNC(void, ICU_CODE) Icu_LPit_DisableEdgeDetection(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_LPit_StartTimestamp (CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                              CONST(boolean, AUTOMATIC) bDmaSupport
                                             );
FUNC(void, ICU_CODE) Icu_LPit_StopTimestamp(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel);
#endif

#if (ICU_GET_INPUT_STATE_API == STD_ON)
 FUNC (boolean, ICU_CODE) Icu_LPit_GetInputState(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

FUNC(void, ICU_CODE) Icu_LPit_ProcessInterrupt(CONST(uint8, AUTOMATIC) hwChannel);


#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_LPit_h_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice  */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_LPit_H */
/** @} */

