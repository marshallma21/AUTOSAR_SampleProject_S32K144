/**
*     @file    Icu_Lptmr.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Lptmr low level driver exported functions.
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


#ifndef ICU_LPTMR_H
#define ICU_LPTMR_H

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Lptmr_h_REF_1
*           Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced
*           initialiser, a constant, a parenthesised expression, a type qualifier, a storage class
*           specifier, or a do-while-zero construct.
*           This is used to route calls from AUTOSAR to hardware layer
*
* @section Icu_Lptmr_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
*
* @section Icu_Lptmr_h_REF_3
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
#include "Icu_Lptmr_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_LPTMR_VENDOR_ID                    43

#define ICU_LPTMR_AR_RELEASE_MAJOR_VERSION     4
#define ICU_LPTMR_AR_RELEASE_MINOR_VERSION     2
#define ICU_LPTMR_AR_RELEASE_REVISION_VERSION  2
#define ICU_LPTMR_SW_MAJOR_VERSION             1
#define ICU_LPTMR_SW_MINOR_VERSION             0
#define ICU_LPTMR_SW_PATCH_VERSION             1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Icu_Lptmr_Types.h file are of the same vendor */
#if (ICU_LPTMR_VENDOR_ID != ICU_LPTMR_TYPES_VENDOR_ID)
#error "Icu_Lptmr.h and Icu_Lptmr_Types.h have different vendor IDs"
#endif
#if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION != ICU_LPTMR_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_MINOR_VERSION != ICU_LPTMR_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_REVISION_VERSION != ICU_LPTMR_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lptmr.h and Icu_Lptmr_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_LPTMR_SW_MAJOR_VERSION != ICU_LPTMR_TYPES_SW_MAJOR_VERSION) || \
     (ICU_LPTMR_SW_MINOR_VERSION != ICU_LPTMR_TYPES_SW_MINOR_VERSION) || \
     (ICU_LPTMR_SW_PATCH_VERSION != ICU_LPTMR_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lptmr.h and Icu_Lptmr_Types.h are different"
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
* @brief            Ftm_ChannelModeType
* @details          Type that indicates the channel mode type(capture mode, edge counter).
*
* */
typedef enum
{
    LPTMR_CHANNEL_MODE_SIGNAL_EDGE_DETECT    = 0x01U, /*< @brief Mode for detecting edges.  */
    LPTMR_CHANNEL_MODE_EDGE_COUNTER          = 0x08U  /*< @brief Mode for counting edges on */
                                                      /*configurable edges. */
} Icu_Lptmr_ChannelMeasurementModeType;

/**
* @brief         Icu_Lptmr_ActivationType
* @details       This indicates the activation type SIUL channel (Rising, Falling )
*
* */
typedef enum
{
    LPTMR_FALLING_EDGE = 0x0U,  /**< @brief  An appropriate action shall be executed when a falling
                                 * edge occurs on the Icu input signal. */

    LPTMR_RISING_EDGE  = 0x1U,  /**< @brief  An appropriate action shall be executed when a rising
                                 *   edge occurs on the Icu input signal. */
} Icu_Lptmr_ActivationType;
/**@}*/

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
* @violates @ref Icu_Lptmr_h_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Icu_MemMap.h"
FUNC(void, ICU_CODE) Icu_Lptmr_Init(P2CONST(Icu_Lptmr_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pLptmrIpConfig);

#if (ICU_DE_INIT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Lptmr_DeInit(P2CONST(Icu_Lptmr_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pLptmrIpConfig);

#endif

#if (ICU_SET_MODE_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Lptmr_SetSleepMode(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
 FUNC(void, ICU_CODE) Icu_Lptmr_SetNormalMode(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SET_MODE_API  */

FUNC(void, ICU_CODE) Icu_Lptmr_SetActivationCondition
(
    CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel,
    CONST(Icu_Lptmr_ActivationType, AUTOMATIC) Activation
);

#if (ICU_EDGE_DETECT_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Lptmr_EnableEdgeDetection(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
 FUNC(void, ICU_CODE) Icu_Lptmr_DisableEdgeDetection(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Lptmr_ResetEdgeCount(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
FUNC(void, ICU_CODE) Icu_Lptmr_EnableEdgeCount(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
FUNC(void, ICU_CODE) Icu_Lptmr_DisableEdgeCount(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
FUNC(uint16, ICU_CODE) Icu_Lptmr_GetEdgeNumbers(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
 FUNC (boolean, ICU_CODE) Icu_Lptmr_GetInputState(VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

#if (defined ICU_LPTMR_0_CH_0_ISR_USED)
 FUNC(void, ICU_CODE) Icu_Lptmr_ProcessInterrupt(void);
#endif

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_Lptmr_h_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice  */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_Lptmr_H */
/** @} */

