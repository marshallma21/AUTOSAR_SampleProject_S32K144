/**
*   @file    Lin_NonASR.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Lin module NonAutosar API header.
*   @details Lin NonAutosar APIs and defines.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPUART
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

#ifndef LIN_NONASR_H
#define LIN_NONASR_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_NonASR_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_NonASR_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the
* current memory section
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define LIN_VENDOR_ID_NONASR                    43
#define LIN_MODULE_ID_NONASR                    82
#define LIN_AR_RELEASE_MAJOR_VERSION_NONASR     4
#define LIN_AR_RELEASE_MINOR_VERSION_NONASR     2
#define LIN_AR_RELEASE_REVISION_VERSION_NONASR  2
#define LIN_SW_MAJOR_VERSION_NONASR             1
#define LIN_SW_MINOR_VERSION_NONASR             0
#define LIN_SW_PATCH_VERSION_NONASR             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and LIN configuration header file are of the same Autosar version */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#if (LIN_DUAL_CLOCK_MODE == STD_ON)

/**
* @brief          Clock modes.
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @note           Possible clock modes: LIN_NORMAL (normal execution mode),
*                 LIN_ALTERNATE (low power mode).
*
*/
typedef enum
{
    LIN_NORMAL     =   (uint8)0x01U, /**< @brief
                                               LIN_NORMAL mode.*/
    LIN_ALTERNATE  =   (uint8)0x02U  /**< @brief
                                               LIN_ALTERNATE mode.*/
} Lin_ClockModesType;

#endif /* #if LIN_DUAL_CLOCK_MODE == STD_ON */


#ifdef LIN_USE_MSC

/**
* @brief          Micro Second Channel status type.
* @pre            LIN_USE_MSC must be defined.
*
* @note           MSC channel frame operation status, as returned by the
*                 API service Msc_GetStatus().
*
*/
typedef enum
{
    LIN_MSC_IDLE = 0,      /**< @brief Receiver is disabled and no
                                   reception is running.*/
    LIN_MSC_READY,         /**< @brief Receiver is enabled and no
                                   reception is running.*/
    LIN_MSC_RUN,           /**< @brief Receiver is enabled and
                                   reception is running.*/
    LIN_MSC_WAKEUP,        /**< @brief Receiver is in wakeup mode.*/
    LIN_MSC_OVERRUN_ERROR, /**< @brief Erroneous reception due to
                                   an OR error.*/
    LIN_MSC_FRAMING_ERROR, /**< @brief Erroneous reception due to
                                   a FE error.*/
    LIN_MSC_PARITY_ERROR,  /**< @brief Erroneous reception due to
                                   a PE error.*/
    LIN_MSC_NOISE_ERROR    /**< @brief Erroneous reception due to
                                   an NF error.*/
} Lin_MscStatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Micro Second Channel data type.
* @pre            LIN_USE_MSC must be defined.
*
* @note           This type is used to provide Address, data, and any possible
*                 errors from the MSC driver to the application.
*
*/
typedef struct
{
    uint8 u8Data;     /**< @brief Payload of the upstream MSC frame.*/
    uint8 u8Address;  /**< @brief address of the receive data buffer.*/
    uint8 u8Errors;   /**< @brief upstream MSC frame error type.*/
    Lin_MscStatusType  State;   /**< @brief upstream MSC channel state.*/
} Lin_MscDataType;

#endif    /* #ifdef LIN_USE_MSC */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (LIN_DUAL_CLOCK_MODE == STD_ON)

    #define LIN_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    *
    *
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
    * statements and comments before '#include'
    */
         #include "Lin_MemMap.h"
     
    extern VAR(Lin_ClockModesType,LIN_VAR)Lin_Clock;

    #define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    *
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
    * statements and comments before '#include'
    */
         #include "Lin_MemMap.h"
     
#endif    /* #if LIN_DUAL_CLOCK_MODE == STD_ON */


#ifdef LIN_USE_MSC

    #define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    *
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
    * statements and comments before '#include'
    */
         #include "Lin_MemMap.h"
     
    #define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    /**
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    *
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
    * statements and comments before '#include'
    */
         #include "Lin_MemMap.h"
     

    #define LIN_START_SEC_VAR_NO_INIT_8
    /**
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    *
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
    * statements and comments before '#include'
    */
         #include "Lin_MemMap.h"
     
    extern VAR(sint8,LIN_VAR)Lin_as8ChannelHardwareMap[];

    #define LIN_STOP_SEC_VAR_NO_INIT_8
    /**
    * @violates @ref Lin_NonASR_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
    *
    * @violates @ref Lin_NonASR_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
    * statements and comments before '#include'
    */
         #include "Lin_MemMap.h"
     
#endif    /* #ifdef LIN_USE_MSC */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_NonASR_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#if LIN_DUAL_CLOCK_MODE == STD_ON
 extern FUNC (Std_ReturnType, LIN_CODE) Lin_SetClockMode(VAR(Lin_ClockModesType, AUTOMATIC) ClockMode);
#endif

#ifdef LIN_USE_MSC

extern FUNC(void, LIN_CODE) Lin_MscInitChannel(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_ChannelConfigType, AUTOMATIC, LIN_APPL_CONST) pcConfig);

extern FUNC (void, LIN_CODE) Lin_MscDeInitChannel(CONST(uint8, AUTOMATIC) u8Channel);

extern FUNC(Lin_MscStatusType, LIN_CODE) Lin_MscGetStatus(CONST(uint8, AUTOMATIC) u8Channel);

extern FUNC (void, LIN_CODE) Lin_MscPolling(CONST(uint8, AUTOMATIC) u8Channel);

#endif

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_NonASR_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* LIN_NONASR_H */

/** @} */
