/**
*   @file             EthIf_Cbk.c
*   @version          1.0.1
*
*   @brief            AUTOSAR Ethernet Interface callbacks stub file
*   @details          File containing function bodies needed
*                     for the Ethernet driver compilation. This file should
*                     be replaced by a complete version.
*   @warning          This is only a stub file. It does not fully comply to AUTOSAR standard.
*
*   @addtogroup       ETHIF_SECTION
*   @{
*/
/*==================================================================================================
*   Project            : AUTOSAR 4.2 MCAL
*   Platform           : ARM
*   Peripheral         : 
*   Dependencies       : 
*
*   AutosarVersion     : 4.2.2
*   AutosarRevision    : ASR_REL_4_2_REV_0002
*   AutosarConfVariant :
*   SW Version         : 1.0.1
*   BuildVersion       : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
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

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ComStack_Types.h"
#include "EthIf_Cbk.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHIF_VENDOR_ID_C                      43
#define ETHIF_AR_RELEASE_MAJOR_VERSION_C       4
#define ETHIF_AR_RELEASE_MINOR_VERSION_C       2
#define ETHIF_AR_RELEASE_REVISION_VERSION_C    2
#define ETHIF_SW_MAJOR_VERSION_C               1
#define ETHIF_SW_MINOR_VERSION_C               0
#define ETHIF_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETHIF header file are of the same vendor */
#if (ETHIF_VENDOR_ID_C != ETHIF_VENDOR_ID)
    #error "EthIf_Cbk.c and EthIf_Cbk.h have different vendor ids"
#endif
/* Check if current file and ETHIF header file are of the same Autosar version */
#if ((ETHIF_AR_RELEASE_MAJOR_VERSION_C    != ETHIF_AR_RELEASE_MAJOR_VERSION) || \
     (ETHIF_AR_RELEASE_MINOR_VERSION_C    != ETHIF_AR_RELEASE_MINOR_VERSION) || \
     (ETHIF_AR_RELEASE_REVISION_VERSION_C != ETHIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of EthIf_Cbk.c and EthIf_Cbk.h are different"
#endif
/* Check if current file and ETHIF header file are of the same Software version */
#if ((ETHIF_SW_MAJOR_VERSION_C != ETHIF_SW_MAJOR_VERSION) || \
     (ETHIF_SW_MINOR_VERSION_C != ETHIF_SW_MINOR_VERSION) || \
     (ETHIF_SW_PATCH_VERSION_C != ETHIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of EthIf_Cbk.c and EthIf_Cbk.h are different"
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


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          This function handles the received Ethernet frame.
* @details        Function should parse the received frame and pass the gathered
*                 information to the appropriate upper layer module.
* @note           The passed data buffer is no longer valid after the function
*                 is exited.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which received the frame.
* @param[in]      FrameType The received frame Ethertype (from the frame header)
* @param[in]      IsBroadcast The value TRUE indicates that the received frame
*                 was sent to broadcast address (ff-ff-ff-ff-ff-ff)
* @param[in]      PhysAddrPtr Pointer to received frame source MAC address
*                 (6 bytes).
* @param[in]      DataPtr Data buffer containing the received Ethernet frame 
*                 payload.
* @param[in]      LenByte Length of the data in the buffer DataPtr.
*
*/
FUNC(void, ETHIF_CODE)EthIf_RxIndication(VAR(uint8, AUTOMATIC) CtrlIdx, \
                             VAR(Eth_FrameType, AUTOMATIC) FrameType, \
                             VAR(boolean, AUTOMATIC) IsBroadcast, \
                             P2VAR(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr, \
                             P2VAR(Eth_DataType, AUTOMATIC, AUTOMATIC) DataPtr, \
                             VAR(uint16, AUTOMATIC) LenByte)
{
    ; /* This is an empty stub function */
}


/*================================================================================================*/
/**
* @brief          This function confirms that transmission of an Ethernet frame
*                 was finished.
* @details        Function should notify the appropriate upper layer module that
*                 the data transmission was successfully finished.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which transmitted the frame.
* @param[in]      BufIdx Index of the transmitted data buffer.

*/
FUNC(void, ETHIF_CODE)EthIf_TxConfirmation(VAR(uint8, AUTOMATIC) CtrlIdx, \
                                               VAR(uint8, AUTOMATIC) BufIdx)
{
    ; /* This is an empty stub function */ 
}

/*================================================================================================*/
/**
* @brief          This function indicate that driver mode has been changed
* @details        Called asynchronously when mode has been read out. Triggered by previous 
*                 Eth_SetControllerMode call. Can directly be called within the trigger functions.
* @warning        This is only an empty stub function provided only to be able
*                 to compile and link the Eth module.
* @param[in]      CtrlIdx Index of the controller which mode has been changed.
* @param[in]      CtrlMode New mode of correspond Eth driver.

*/
FUNC(void, ETHIF_CODE)EthIf_CtrlModeIndication( \
                                     VAR(uint8, AUTOMATIC) CtrlIdx, \
                                     VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
                                              )
{
    ; /* This is an empty stub function */ 
}

#ifdef __cplusplus
}
#endif
/** @} */
