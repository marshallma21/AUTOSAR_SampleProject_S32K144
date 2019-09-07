/**
*   @file    Eth_Ipw.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver implementation
*   @details Implementation of the AUTOSAR Ethernet driver
*
*   @addtogroup ETH_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ENET
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_Ipw_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be
* preceded by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Ipw_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions
* shall be taken in order to prevent the contents of a header file being
* included twice. This is an approved violation of usage MemMap.h file used
* to create linkage sections.
*
* @section Eth_Ipw_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for 
* external identifiers. Name length of the macros is unfortunately longer than 
* 31 characters which is required by  the agreed macro format and cannot be 
* changed. 
*
* @section Eth_Ipw_c_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by JDP coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to ETH.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eth.h" /* Includes also Eth_GeneralTypes.h, Eth_Cfg.h, Eth_FEC_Counters.h,
                    Eth_ComStack_Types.h, Dem.h, Det.h and Mcal.h */
#include "SchM_Eth.h" /* RTE module header for critical sections protection */
#include "EthIf_Cbk.h" /* EthIf callbacks to be called from Eth driver */
#include "Eth_Ipw.h" /* Own header */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Eth_Ipw_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_Ipw_c_REF_4 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_C    2
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if (ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth_Ipw.c and Eth_Ipw.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Eth_Ipw.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_Ipw.c and Eth.h are different"
#endif
/* Check if current file and Eth_Enet header file are of the same Autosar version */
#if((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION_ENET) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION_ENET) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION_ENET))
    #error "AutoSar Version Numbers of Eth_Ipw.c and Eth_Enet.h are different"
#endif
/* Check if current file and Eth_Enet header file are of the same Software version */
#if((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION_ENET) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION_ENET) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION_ENET))
    #error "Software Version Numbers of Eth_Ipw.c and Eth_Enet are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ETH_START_SEC_CODE
/**
 * @violates @ref Eth_Ipw_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief         Reports received frames to the upper layer
* @param[in]     u8CtrlIdx Index of the controller to report receptions
* @param[in]     bIrq Selects between the poll driven and interrupt driven
*                mode (algorithm). The value TRUE means interrupt driven mode.
* @details       Function examines type of receive buffers. It begins
*                from the empty buffer found by previous call or from the
*                first one if no call has been done since the controller has
*                been enabled or from the latest known full buffer containing
*                the single-buffer-error-free frame.
* @par
*                Each buffer is checked to be error-free, buffer type is
*                examined and the buffer is reported via the
*                EthIf_RxIndication function call if the buffer type
*                is RX_BUF_SINGLE. All buffers of multi-buffer frame are
*                discarded when such frame is detected i.e. buffer type is
*                RX_BUF_MULTI_FINISHED.
* @par
*                Search ends when empty buffer is found i.e. buffer type
*                is RX_BUF_MULTI_UNFINISHED or RX_BUF_EMPTY or in the poll
*                driven mode when a second single-buffer frame is found
*                (this frame is not reported to the EthIf_RxIndication).
*                Function silently discards all buffers when the receive
*                buffers ring overflow is detected i.e. RX_BUF_OVERFLOW value
*                of buffer type is found.
* @note          The function reports all found frames in the interrupt driven
*                mode. In the poll driven mode it reports only the first found
*                frame signals whether there is at least another frame to be
*                received (in the next call).
* @return        In the poll driven mode signalizes whether a frame has been
*                reported to the EthIf module and whether another frame is
*                available. It shall be ignored in the interrupt driven mode.
* @retval        ETH_RECEIVED Only one frame received
* @retval        ETH_NOT_RECEIVED No frame received
* @retval        ETH_RECEIVED_MORE_DATA_AVAILABLE More frames received
*                frame was discarded.
* @implements    Eth_Ipw_ReportReception_Activity
*/
/*
* The interrupt flag shall be cleared after each finished buffer which will.
* If a buffer reception is finished during the loop execution the flag will be
* set however it will be cleared after the buffer is processed and the loop
* continues with the next empty buffer. The algorithm continues until
* an empty buffer is found which ensures that no buffer can forgotten if
* the interrupt flag is cleared.
* If the flag was cleared at the beginning the buffer finished during the loop
* execution would cause the flag being set again but the loop would handle the
* buffer therefore the next interrupt would occur but no buffer would be found.
* If the flag was cleared at the end it could happen that a buffer is finished
* between the loop end and clearing the flag so the buffer would not be
* processed however no interrupt would come because flag would be cleared.
* NOTE: This is valid only for the interrupts, polling mode ignores the flag.
*/

FUNC(Eth_RxStatusType, ETH_CODE) Eth_Ipw_ReportReception ( \
                                                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                                                CONST(boolean, AUTOMATIC) bIrq \
                                                         )
{
    return(Eth_Enet_ReportReception(u8CtrlIdx, bIrq));
}
/*================================================================================================*/
/**
* @brief         Confirms transmission of all transmitted buffers
* @param[in]     u8CtrlIdx Index of the controller to report transmissions
* @details       Function examines all transmit buffers whether some of them
*                have been already sent and whether they should be confirmed.
*                EthIf_TxConfirmation is called for each such buffer.
* @return        Error report
* @retval        TRUE No error has occurred.
* @retval        FALSE Some error has occurred.
* @implements    Eth_Ipw_ReportTransmission_Activity
*/

FUNC(boolean, ETH_CODE) Eth_Ipw_ReportTransmission(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return(Eth_Enet_ReportTransmission(u8CtrlIdx));
}

/*================================================================================================*/
/**
*//*!
* @brief         Safely disables the controller
* @param[in]     u8Ctrl Index of the controller to disable
* @details       Function disables the Ethernet controller and clears all
*                buffers to ensure safe start in the future i.e. no buffer is
*                retransmitted and all received frames are discarded - nothing
*                is received after the controller is disabled.
* @warning       Transmission which is in progress is terminated and frame
*                being transmitted is appended by bad CRC when the
*                Eth_Ipw_DisableController function is called.
*/
 
FUNC(void, ETH_CODE) Eth_Ipw_DisableController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    /* Disable the controller */
    Eth_Enet_DisableController(u8CtrlIdx);
    /* Clear all buffers */
    Eth_Enet_ConfigureTxBuffers(u8CtrlIdx);
    Eth_Enet_ConfigureRxBuffers(u8CtrlIdx);
}
#if STD_ON == ETH_GETDROPCOUNTAPI
FUNC(void, ETH_CODE) Eth_Ipw_GetDropCount  (
                               VAR(uint8, AUTOMATIC) u8CtrlIdx,
                               P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pCountValuesPtr,
                               P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pDropCountPtr
                                           )
{
    Eth_Enet_GetDropCount(u8CtrlIdx, pCountValuesPtr, pDropCountPtr);
}
#endif

#if STD_ON == ETH_GET_ETHERSTATS_API
FUNC(void, ETH_CODE) Eth_Ipw_GetEtherStats     ( \
                       VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                       P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) pEtherStats \
                                               )
{
    Eth_Enet_GetEtherStats(u8CtrlIdx, pEtherStats);
}
#endif

#if STD_ON == ETH_GLOBALTIME_SUPPORT
FUNC(void, ETH_CODE) Eth_Ipw_GetCurrentTime    ( \
                      VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                      P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                      P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                               )
{
    Eth_Enet_GetCurrentTime(u8CtrlIdx, pTimeQualPtr, pTimeStampPtr);
}

FUNC(void, ETH_CODE) Eth_Ipw_EnableEgressTimeStamp   ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                VAR(uint8, AUTOMATIC) u8BufIdx \
                                                     )
{
    /* Prevent misra, compiler warnings */
    (void)u8CtrlIdx;
    (void)u8BufIdx;
}

FUNC(void, ETH_CODE) Eth_Ipw_GetEgressTimeStamp  ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                VAR(uint8, AUTOMATIC) u8BufIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                 )
{
    Eth_Enet_GetEgressTimeStamp(u8CtrlIdx, u8BufIdx, pTimeQualPtr, pTimeStampPtr );
}

FUNC(void, ETH_CODE) Eth_Ipw_GetIngressTimeStamp ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) pDataPtr, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) pTimeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                 )
{
    Eth_Enet_GetIngressTimeStamp (u8CtrlIdx, pDataPtr, pTimeQualPtr, pTimeStampPtr);
}

FUNC(void, ETH_CODE) Eth_Ipw_SetCorrectionTime   ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETH_APPL_DATA) pTimeOffsetPtr, \
                                P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_APPL_DATA) pRateRatioPtr \
                                                 )
{
    Eth_Enet_SetCorrectionTime(u8CtrlIdx, pTimeOffsetPtr, pRateRatioPtr);
}

FUNC(void, ETH_CODE)  Eth_Ipw_SetGlobalTime     ( \
                                VAR(uint8, AUTOMATIC) u8CtrlIdx, \
                                P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) pTimeStampPtr \
                                                )
{
    Eth_Enet_SetGlobalTime( u8CtrlIdx, pTimeStampPtr);
}
#endif
FUNC(void, ETH_CODE) Eth_Ipw_MainFunction(VAR(void, AUTOMATIC))
{
    Eth_Enet_MainFunction();
}
#if STD_ON == ETH_GLOBALTIME_SUPPORT
FUNC(void, ETH_CODE) Eth_IPW_ClearTimerWrapFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ClearTimerWrapFlag(u8CtrlIdx);
}
FUNC(boolean, ETH_CODE) Eth_IPW_IsTimerWrapEvent(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_IsTimerWrapEvent(u8CtrlIdx);
}
#endif
FUNC(void, ETH_CODE) Eth_Ipw_ResetController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ResetController(u8CtrlIdx);
}

FUNC(boolean, ETH_CODE) Eth_Ipw_CheckAccessToController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_CheckAccessToCtrl(u8CtrlIdx);
}

FUNC(void, ETH_CODE) Eth_Ipw_ConfigureController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ConfigureCtrl(u8CtrlIdx);
}

FUNC(void, ETH_CODE) Eth_Ipw_ClearCounters(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ClearMIBCounters(u8CtrlIdx);
}

FUNC(void, ETH_CODE) Eth_Ipw_ConfigureRxBuffers(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ConfigureRxBuffers(u8CtrlIdx);
}

FUNC(void, ETH_CODE) Eth_Ipw_ConfigureTxBuffers(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ConfigureTxBuffers(u8CtrlIdx);
}

FUNC(void, ETH_CODE) Eth_Ipw_EnableController(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_EnableController(u8CtrlIdx);
}

FUNC(Eth_ModeType, ETH_CODE) Eth_Ipw_CheckControllerIsActive(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_CheckCtrlIsActive(u8CtrlIdx);
}

FUNC(uint32, ETH_CODE) Eth_Ipw_GetPhysicalAddressLow(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_GetPhysAddressLow(u8CtrlIdx);
}
FUNC(uint16, ETH_CODE) Eth_Ipw_GetPhysicalAddressHigh(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_GetPhysAddressHigh(u8CtrlIdx);
}

FUNC(boolean, ETH_CODE) Eth_Ipw_SetPhysAddr ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr \
                                            )
{
    return Eth_Enet_SetPhysAddr(u8CtrlIdx, pPhysAddrPtr);
}

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
FUNC(void, ETH_CODE) Eth_Ipw_UpdatePhysAddrFilter   ( \
                CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) pPhysAddrPtr, \
                VAR(Eth_FilterActionType, AUTOMATIC) eAction \
                                                    )
{
    Eth_Enet_UpdtePhysAddrFiltr(u8CtrlIdx, pPhysAddrPtr, eAction);
}
#endif
FUNC(boolean, ETH_CODE) Eth_Ipw_ProvideBufferDataArea   ( \
                        CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                        CONSTP2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) pBufIdx, \
                        P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) pData, \
                        CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pLength \
                                                        )
{
    return Eth_Enet_BorrowTxBuffer(u8CtrlIdx, pBufIdx, pData, pLength);
}

FUNC(void, ETH_CODE) Eth_Ipw_Transmit   (
                        CONST(uint8, AUTOMATIC) u8CtrlIdx,
                        CONST(Eth_BufIdxType, AUTOMATIC) u8Buf,
                        CONST(Eth_FrameType, AUTOMATIC) u16Type,
                        CONST(uint16, AUTOMATIC) u16Length,
                        CONST(boolean, AUTOMATIC) bConfirm,
                        P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) pDest
#if STD_ON == ETH_BRIDGE_SUPPORT
                      , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) pSource
#endif /* ETH_BRIDGE_SUPPORT  */
                                        )
{
    Eth_Enet_Transmit(u8CtrlIdx, u8Buf, u16Type, u16Length, bConfirm, pDest
#if STD_ON == ETH_BRIDGE_SUPPORT
                           , pSource
#endif /* ETH_BRIDGE_SUPPORT  */
                     );
}

FUNC(boolean, ETH_CODE) Eth_Ipw_IsTxBufLockedBT(
                            CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                            CONST(Eth_BufIdxType, AUTOMATIC) u8Buf \
                            )
{
    return Eth_Enet_IsTxBufLockedBT(u8CtrlIdx, u8Buf);    
}
   
#if STD_ON == ETH_CTRLENABLE_MII
FUNC(boolean, ETH_CODE) Eth_Ipw_WriteMii    ( \
                    CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                    CONST(uint8, AUTOMATIC) u8Trcv, \
                    CONST(uint8, AUTOMATIC) u8Reg, \
                    CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pData \
                                            )
{
    return Eth_Enet_DoMiiMMF(u8CtrlIdx, u8Trcv, u8Reg, pData, ENET_MMFR_OP_WRITE_U32);    
}

FUNC(boolean, ETH_CODE) Eth_Ipw_ReadMii ( \
                        CONST(uint8, AUTOMATIC) u8CtrlIdx, \
                        CONST(uint8, AUTOMATIC) u8Trcv, \
                        CONST(uint8, AUTOMATIC) u8Reg, \
                        CONSTP2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) pData \
                                        )
{ 
    return Eth_Enet_DoMiiMMF(u8CtrlIdx, u8Trcv, u8Reg, pData, ENET_MMFR_OP_READ_U32);
}
#endif /* ETH_CTRLENABLE_MII */

FUNC(void, ETH_CODE) Eth_Ipw_ClearRxInterruptFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ClearRxIrqFlag(u8CtrlIdx);
}

FUNC(void, ETH_CODE) Eth_Ipw_ClearTxInterruptFlag(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    Eth_Enet_ClearTxIrqFlag(u8CtrlIdx);
}

FUNC(boolean, ETH_CODE) Eth_Ipw_IsTxInterruptFlagSet(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_IsTxIrqFlagSet(u8CtrlIdx);
}

FUNC(boolean, ETH_CODE) Eth_Ipw_IsRxInterruptFlagSet(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_IsRxIrqFlagSet(u8CtrlIdx);
}

FUNC(boolean, ETH_CODE) Eth_Ipw_IsTxInterruptEnabled(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_IsTxIrqEnabled(u8CtrlIdx);
}

FUNC(boolean, ETH_CODE) Eth_Ipw_IsRxInterruptEnabled(CONST(uint8, AUTOMATIC) u8CtrlIdx)
{
    return Eth_Enet_IsRxIrqEnabled(u8CtrlIdx);
}


#define ETH_STOP_SEC_CODE
/**
 * @violates @ref Eth_Ipw_c_REF_1 MISRA rule 19.1
 * @violates @ref Eth_Ipw_c_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
