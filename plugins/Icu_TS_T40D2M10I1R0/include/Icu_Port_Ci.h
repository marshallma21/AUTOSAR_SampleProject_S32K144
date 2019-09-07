/**
*     @file    Icu_Port_Ci.h
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Port_Ci low level driver exported functions.
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


#ifndef ICU_PORT_CI_H
#define ICU_PORT_CI_H

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_PORT_CI_h_REF_1
*           Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced
*           initialiser, a constant, a parenthesised expression, a type qualifier, a storage class
*           specifier, or a do-while-zero construct.
*           This is used to route calls from AUTOSAR to hardware layer
*
* @section Icu_PORT_CI_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
*
* @section Icu_PORT_CI_h_REF_3
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice.
*          All header files are protected against multiple inclusions
*
* @section Icu_PORT_CI_h_REF_4
*         Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*         that 31 character significance and case sensitivity are supported for external identifiers
*         The defines are validated.
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
#include "Icu_Port_Ci_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_PORT_CI_VENDOR_ID                    43

#define ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION     4
#define ICU_PORT_CI_AR_RELEASE_MINOR_VERSION     2
#define ICU_PORT_CI_AR_RELEASE_REVISION_VERSION  2
#define ICU_PORT_CI_SW_MAJOR_VERSION             1
#define ICU_PORT_CI_SW_MINOR_VERSION             0
#define ICU_PORT_CI_SW_PATCH_VERSION             1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Icu_Port_Ci_Types.h file are of the same vendor */
#if (ICU_PORT_CI_VENDOR_ID != ICU_PORT_CI_TYPES_VENDOR_ID)
#error "Icu_Port_Ci.h and Icu_Port_Ci_Types.h have different vendor IDs"
#endif
#if ((ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION != ICU_PORT_CI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_CI_AR_RELEASE_MINOR_VERSION != ICU_PORT_CI_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_CI_AR_RELEASE_REVISION_VERSION != ICU_PORT_CI_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Port_Ci.h and Icu_Port_Ci_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_PORT_CI_SW_MAJOR_VERSION != ICU_PORT_CI_TYPES_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_SW_MINOR_VERSION != ICU_PORT_CI_TYPES_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_SW_PATCH_VERSION != ICU_PORT_CI_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Ci.h and Icu_Port_Ci_Types.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Default value for DFWR and DFCR for all ports
*/
#define PORT_CI_DFWR_DEFAULT_VALUE_U32 (0x00000000UL)

/**
* @{
* @brief   PORT_CI_GET_PIN_MASK_U16 - used to get the pin of the IRQ channel
* @remarks on each port there are 32 channels available
*/
#define PORT_CI_GET_PIN_MASK_U16         ((uint16)(0x1FU))
/**@}*/

/**
* @brief   returns the port of the Port_Ci hwChannel
*
* @violates @ref Icu_PORT_CI_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* @violates @ref Icu_PORT_CI_h_REF_2  MISRA 2004 Advisory Rule 19.4, C macros shall only expand to a
*                                   braced initializer, a constant, a parenthesized expression
*/
#define PORT_CI_PORT_MASK(hwChannel) ((hwChannel) >> 5U)

/**
* @brief   returns the pin of the Port_Ci hwChannel
*
* @violates @ref Icu_PORT_CI_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* @violates @ref Icu_PORT_CI_h_REF_2  MISRA 2004 Advisory Rule 19.4, C macros shall only expand to a
*                                   braced initializer, a constant, a parenthesized expression
*/
#define PORT_CI_PIN_MASK(hwChannel)  ((hwChannel) & PORT_CI_GET_PIN_MASK_U16)


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief         Icu_Port_Ci_ActivationType
* @details       This indicates the activation type Port_Ci channel (Rising, Falling or Both)
*
* */
typedef enum
{
    PORT_CI_FALLING_EDGE = 0x0U,  /**< @brief  An appropriate action shall be executed when a
                                 * falling edge occurs on the Port_Ci input signal. */

    PORT_CI_RISING_EDGE  = 0x1U,  /**< @brief  An appropriate action shall be executed when a
                                 * rising edge occurs on the Port_Ci input signal. */

    PORT_CI_BOTH_EDGES   = 0x2U  /**< @brief  An appropriate action shall be executed when a rising
                                 * edge or falling edge occurs on the Port_Ci input signal. */
} Icu_Port_Ci_ActivationType;
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
* @violates @ref Icu_PORT_CI_h_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Icu_MemMap.h"

#if ((defined ICU_PORT_0_ISR_USED) || (defined ICU_PORT_1_ISR_USED) || \
     (defined ICU_PORT_2_ISR_USED) || (defined ICU_PORT_3_ISR_USED) || \
     (defined ICU_PORT_4_ISR_USED) || (defined ICU_PORT_5_ISR_USED) || \
     (defined ICU_PORT_6_ISR_USED) || (defined ICU_PORT_7_ISR_USED) || \
     (defined ICU_PORT_9_ISR_USED) || (defined ICU_PORT_10_ISR_USED) || \
     (defined ICU_PORT_11_ISR_USED)|| (defined ICU_IRQ_SINGLE_INTERRUPT))

FUNC(boolean, ICU_CODE) Icu_Port_Ci_GetChInit(CONST(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
#endif

FUNC(void, ICU_CODE) Icu_Port_Ci_Init(P2CONST(Icu_Port_Ci_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pPort_CiIpConfig);

#if (ICU_DE_INIT_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Port_Ci_DeInit(P2CONST(Icu_Port_Ci_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pPort_CiIpConfig);
#endif

#if (ICU_SET_MODE_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Port_Ci_SetSleepMode(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
 FUNC(void, ICU_CODE) Icu_Port_Ci_SetNormalMode(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SET_MODE_API  */

FUNC (void, ICU_CODE) Icu_Port_Ci_SetActivationCondition(VAR(Icu_Port_Ci_ChannelType,    AUTOMATIC) hwChannel,
                                                         VAR(Icu_Port_Ci_ActivationType, AUTOMATIC) Activation
                                                        );

#if (ICU_EDGE_DETECT_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Port_Ci_EnableEdgeDetection(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
 FUNC(void, ICU_CODE) Icu_Port_Ci_DisableEdgeDetection(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
 FUNC (boolean, ICU_CODE) Icu_Port_Ci_GetInputState(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_PORT_CI_h_REF_3 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice  */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_PORT_CI_H */
/** @} */

