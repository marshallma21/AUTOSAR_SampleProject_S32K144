/**
*   @file             EthIf_Cbk.h
*   @version          1.0.1
*
*   @brief            AUTOSAR EthIf callbacks header file stub
*   @details          File containing prototypes needed by the Ethernet driver
*                     This file contains sample code only. It is not part of the production code deliverables.
*   @warning          This is only a stub file. It does not fully comply to AUTOSAR standard.
*
*   @addtogroup       ETHIF_SECTION
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : 
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

#ifndef ETHIF_CBK_H
  #define ETHIF_CBK_H
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
  /* Common types for all communication modules*/
  #include "Eth.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ETHIF_VENDOR_ID                    43
#define ETHIF_MODULE_ID                    65
#define ETHIF_AR_RELEASE_MAJOR_VERSION     4
#define ETHIF_AR_RELEASE_MINOR_VERSION     2
#define ETHIF_AR_RELEASE_REVISION_VERSION  2
#define ETHIF_SW_MAJOR_VERSION             1
#define ETHIF_SW_MINOR_VERSION             0
#define ETHIF_SW_PATCH_VERSION             1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
    
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

  extern FUNC(void, ETHIF_CODE)EthIf_RxIndication(\
                             VAR(uint8, AUTOMATIC) CtrlIdx,\
                             VAR(Eth_FrameType, AUTOMATIC) FrameType, \
                             VAR(boolean, AUTOMATIC) IsBroadcast, \
                             P2VAR(uint8, AUTOMATIC, AUTOMATIC) PhysAddrPtr, \
                             P2VAR(Eth_DataType, AUTOMATIC, AUTOMATIC) DataPtr,\
                             VAR(uint16, AUTOMATIC) LenByte);
                            
  extern FUNC(void, ETHIF_CODE)EthIf_TxConfirmation(\
                                              VAR(uint8, AUTOMATIC) CtrlIdx,\
                                              VAR(uint8, AUTOMATIC) BufIdx);
  extern FUNC(void, ETHIF_CODE)EthIf_CtrlModeIndication( \
                                              VAR(uint8, AUTOMATIC) CtrlIdx, \
                                              VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
                                                       );
                                              
#ifdef __cplusplus
}
#endif                                              

#endif /* ETHIF_CBK_H */
/** @} */
