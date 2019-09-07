/**
*   @file    Lin_IPW.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Lin - Isolation level file for LIN driver.
*   @details Implementation file for function definition on isolation level between high and low level driver.
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
* @section Lin_Ipw_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_Ipw_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_Ipw_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
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
#include "Lin.h"
#include "Lin_IPW.h"
#include "Lin_LPUART.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_IPW.c
*/
#define LIN_IPW_VENDOR_ID_C                    43
/*
* @violates @ref Lin_Ipw_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MAJOR_VERSION_IPW_C     4
/*
* @violates @ref Lin_Ipw_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MINOR_VERSION_IPW_C     2
/*
* @violates @ref Lin_Ipw_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_IPW_C  2
#define LIN_SW_MAJOR_VERSION_IPW_C             1
#define LIN_SW_MINOR_VERSION_IPW_C             0
#define LIN_SW_PATCH_VERSION_IPW_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin_IPW header file are of the same vendor */
#if (LIN_IPW_VENDOR_ID_C != LIN_IPW_VENDOR_ID)
    #error "Lin_IPW.c and Lin_IPW.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_IPW_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin_IPW.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin_LPUART header file are of the same vendor */
#if (LIN_IPW_VENDOR_ID_C != LIN_LPUART_VENDOR_ID)
    #error "Lin_IPW.c and Lin_LPUART.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_IPW_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IPW_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IPW_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_IPW.c and Lin.h are different"
#endif
#if ((LIN_SW_MAJOR_VERSION_IPW_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_IPW_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_IPW_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_IPW.c and Lin.h are different"
#endif
/* Check if current file and Lin_IPW header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_IPW_C    != LIN_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IPW_C    != LIN_AR_RELEASE_MINOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IPW_C != LIN_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of Lin_IPW.c and Lin_IPW.h are different"
#endif
/* Check if current file and Lin_IPW header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IPW_C != LIN_SW_MAJOR_VERSION_IPW) || \
     (LIN_SW_MINOR_VERSION_IPW_C != LIN_SW_MINOR_VERSION_IPW) || \
     (LIN_SW_PATCH_VERSION_IPW_C != LIN_SW_PATCH_VERSION_IPW) \
    )
    #error "Software Version Numbers of Lin_IPW.c and Lin_Ipw.h are different"
#endif
/* Check if current file and Lin_LPUART header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_IPW_C    != LIN_LPUART_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IPW_C    != LIN_LPUART_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IPW_C != LIN_LPUART_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_Ipw.c and Lin_LPUART.h are different"
#endif
/* Check if current file and Lin_LPUART header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IPW_C != LIN_LPUART_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_IPW_C != LIN_LPUART_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_IPW_C != LIN_LPUART_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_Ipw.c and Lin_LPUART.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_Ipw_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies which LIN channel has been woken
*          up by the LIN bus transceiver This API is used when the
*          LIN channel wake up functionality is disabled (wake up
*          interrupt is disabled) it checks the wake up flag from
*          all LIN channels which are in sleep mode and which
*          have the wake up functionality disabled.
*
* @param[in] u8Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Ipw_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel)
{
    return Lin_LPUART_CheckWakeup(u8Channel);
}

/**
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] u8Channel LIN channel to be initialized.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_Ipw_InitChannel(CONST(uint8, AUTOMATIC) u8Channel)
{
    Lin_LPUART_InitChannel(u8Channel);
}

/**
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the LPUART_Ipw_SendReponse
*
* @param[in]   u8Channel LIN channel to be addressed.
* @param[in]   pPduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
* @implements Lin_Ipw_SendHeader_Activity
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_Ipw_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pcPduInfoPtr)
{
    return Lin_LPUART_SendHeader(u8Channel, pcPduInfoPtr);
}

/**
* @brief   Sends the response part of the LIN frame.
* @details Initiates the transmission of the data
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*
* @param[in]   u8Channel LIN channel to be addressed.
* @param[in]   pPduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            void.
*
* @implements Lin_Ipw_SendResponse_Activity
*/
FUNC(void, LIN_CODE) Lin_Ipw_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pcPduInfoPtr)
{
    Lin_LPUART_SendResponse(u8Channel, pcPduInfoPtr);
}

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] u8Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Ipw_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel)
{
    return Lin_LPUART_GoToSleep(u8Channel);
}

/**
* @brief   Same function as Lin_Ipw_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] u8Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Ipw_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    return Lin_LPUART_GoToSleepInternal(u8Channel);
}

/**
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   u8Channel LIN channel to be addressed
 * @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error rised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 *
  */
FUNC (Lin_StatusType, LIN_CODE) Lin_Ipw_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr)
{
    return Lin_LPUART_HardwareGetStatus(u8Channel, pu8LinSduPtr);
}

/**
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   u8Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_Ipw_WakeUp(CONST(uint8, AUTOMATIC) u8Channel)
{
    Lin_LPUART_WakeUp(u8Channel);
}

 /**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL_STATE_U8 state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   u8Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_Ipw_WakeUpInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    Lin_LPUART_WakeupInternal(u8Channel);
}
 
#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_Ipw_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref Lin_Ipw_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
