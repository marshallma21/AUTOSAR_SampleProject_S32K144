/**
*   @file       Eth.h
*   @implements Eth.h_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver interface header file
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

#ifndef ETH_H
#define ETH_H
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macros is unfortunately longer than 31 characters which is required by 
* the agreed macro format and cannot be changed. 
*
* @section Eth_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_h_REF_4
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
#include "Eth_GeneralTypes.h"  /* Mandatory include - see the SWS */
#include "Eth_Cfg.h" /* Mandatory include - see the SWS */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/** @implements Eth_Version_define */
#define ETH_VENDOR_ID                    43
#define ETH_MODULE_ID                    88
#define ETH_AR_RELEASE_MAJOR_VERSION     4
#define ETH_AR_RELEASE_MINOR_VERSION     2
/** 
  @violates @ref Eth_h_REF_1 MISRA rule 1.4
  @violates @ref Eth_h_REF_4 MISRA rule 5.1
*/
#define ETH_AR_RELEASE_REVISION_VERSION  2
#define ETH_SW_MAJOR_VERSION             1
#define ETH_SW_MINOR_VERSION             0
#define ETH_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH configuration header file are of the same vendor */
#if (ETH_VENDOR_ID != ETH_VENDOR_ID_CFG)
    #error "Eth.h and Eth_Cfg.h have different vendor ids"
#endif
/* Check if current file and ETH configuration header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION    != ETH_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ETH_AR_RELEASE_MINOR_VERSION    != ETH_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ETH_AR_RELEASE_REVISION_VERSION != ETH_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Eth.h and Eth_Cfg.h are different"
#endif
/* Check if current file and ETH configuration header file are of the same software version */
#if ((ETH_SW_MAJOR_VERSION != ETH_SW_MAJOR_VERSION_CFG) || \
     (ETH_SW_MINOR_VERSION != ETH_SW_MINOR_VERSION_CFG) || \
     (ETH_SW_PATCH_VERSION != ETH_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Eth.h and Eth_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Service IDs definition */
#define ETH_SID_INIT                    0x01
#define ETH_SID_SETCONTROLLERMODE       0x03
#define ETH_SID_GETCONTROLLERMODE       0x04
#define ETH_SID_GETPHYSADDR             0x08
#define ETH_SID_WRITEMII                0x05
#define ETH_SID_READMII                 0x06
#define ETH_SID_PROVIDETXBUFFER         0x09
#define ETH_SID_TRANSMIT                0x0A
#define ETH_SID_RECEIVE                 0x0B
#define ETH_SID_TXCONFIRMATION          0x0C
#define ETH_SID_GETVERSIONINFO          0x0D
#define ETH_SID_SETPHYSADDR             0x13
#define ETH_SID_UPDATEADDRFILTER        0x12
#define ETH_SID_GETCURRENTTIME          0x16
#define ETH_SID_ENABLEEGRESSTIMESTAMP   0x17
#define ETH_SID_GETEGRESSTIMESTAMP      0x18
#define ETH_SID_GETINGRESSTIMESTAMP     0x19
#define ETH_SID_GETDROPCOUNT            0x14
#define ETH_SID_GETETHERSTATS           0x15
#define ETH_SID_SETCORRECTIONTIME       0x1A
#define ETH_SID_SETGLOBALTIME           0x1B

/* DET error codes */
/** @implements Eth_DetErrorIds_define */
#if STD_ON == ETH_DEV_ERROR_DETECT
#define ETH_E_INV_CTRL_IDX      ((uint8)0x01)
#define ETH_E_NOT_INITIALIZED   ((uint8)0x02)
#define ETH_E_PARAM_POINTER     ((uint8)0x03)
#define ETH_E_INV_PARAM         ((uint8)0x04)
#define ETH_E_INV_MODE          ((uint8)0x05)
#endif
/* Define Specific Error code for Std_ReturnType */
#define ETH_E_NO_ACCESS         ((uint8)0x03U)
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* @violates @ref Eth_h_REF_1 MISRA rule 1.4
* @violates @ref Eth_h_REF_4 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_INIT_UNSPECIFIED

/**
@violates @ref Eth_h_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"
    /***************************************************************************
    * AUTOSAR Debugging Variables
    ***************************************************************************/
    /* Eth_CtrlState: Used to store state of Eth controller(s). */
    extern VAR(volatile Eth_StateType, ETH_VAR) Eth_CtrlState[ETH_MAXCTRLS_SUPPORTED];

/* @violates @ref Eth_h_REF_1 MISRA rule 1.4
* @violates @ref Eth_h_REF_4 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_INIT_UNSPECIFIED
/** 
@violates @ref Eth_h_REF_2 MISRA rule 19.15
 */
#include "Eth_MemMap.h"


#if STD_ON == DEBUG_VARIABLES
#define ETH_START_SEC_VAR_INIT_32
/** 
* @violates @ref Eth_h_REF_2 MISRA rule 19.15
* @violates @ref Eth_h_REF_3 MISRA rule 19.1 
*/
#include "Eth_MemMap.h"
extern VAR(uint32, ETH_VAR) Eth_RxBuffersOverflow[ETH_MAXCTRLS_SUPPORTED];
extern VAR(uint32, ETH_VAR) Eth_MiiFailed[ETH_MAXCTRLS_SUPPORTED];
#define ETH_STOP_SEC_VAR_INIT_32
/** 
* @violates @ref Eth_h_REF_2 MISRA rule 19.15
* @violates @ref Eth_h_REF_3 MISRA rule 19.1 
*/
#include "Eth_MemMap.h"
#endif     
    
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_START_SEC_CODE
/** 
* @violates @ref Eth_h_REF_2 MISRA rule 19.15
* @violates @ref Eth_h_REF_3 MISRA rule 19.1 
*/
#include "Eth_MemMap.h"


extern FUNC(void, ETH_CODE) Eth_Init(P2CONST(Eth_ConfigType, AUTOMATIC, ETH_APPL_CONST) CfgPtr); 
extern FUNC(Std_ReturnType, ETH_CODE) Eth_SetControllerMode ( \
                                    VAR(uint8, AUTOMATIC) CtrlIdx, \
                                    VAR(Eth_ModeType, AUTOMATIC) CtrlMode \
                                                            );
extern FUNC(Std_ReturnType, ETH_CODE) Eth_GetControllerMode ( \
                                    VAR(uint8, AUTOMATIC) CtrlIdx, \
                                    P2VAR(Eth_ModeType, AUTOMATIC, ETH_APPL_DATA) CtrlModePtr \
                                                            );
extern FUNC(void, ETH_CODE) Eth_GetPhysAddr ( \
                        VAR(uint8, AUTOMATIC) CtrlIdx, \
                        P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr \
                                            );
extern FUNC(void, ETH_CODE) Eth_SetPhysAddr(VAR(uint8, AUTOMATIC) CtrlIdx, P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr);

#if STD_ON == ETH_UPDATE_PHYS_ADDR_FILTER
    extern FUNC(Std_ReturnType, ETH_CODE) Eth_UpdatePhysAddrFilter  ( \
                                            VAR(uint8, AUTOMATIC) CtrlIdx, \
                                            P2CONST(uint8, AUTOMATIC, ETH_APPL_CONST) PhysAddrPtr, \
                                            VAR(Eth_FilterActionType, AUTOMATIC) Action \
                                                                    );
#endif /* ETH_UPDATE_PHYS_ADDR_FILTER */

#if STD_ON == ETH_CTRLENABLE_MII
extern FUNC(Std_ReturnType, ETH_CODE) Eth_WriteMii ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) TrcvIdx, \
                                VAR(uint8, AUTOMATIC) RegIdx, \
                                VAR(uint16, AUTOMATIC) RegVal \
                                                    );
extern FUNC(Std_ReturnType, ETH_CODE) Eth_ReadMii   ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) TrcvIdx, \
                                VAR(uint8, AUTOMATIC) RegIdx, \
                                P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) RegValPtr \
                                                    );
#endif /* ETH_CTRLENABLE_MII */
#if STD_ON == ETH_GETDROPCOUNTAPI
extern FUNC(Std_ReturnType, ETH_CODE) Eth_GetDropCount  ( \
                                        VAR(uint8, AUTOMATIC) CtrlIdx, \
                                        P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) CountValuesPtr, \
                                        P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) DropCountPtr \
                                                        );
#endif

#if STD_ON == ETH_GET_ETHERSTATS_API
extern FUNC(Std_ReturnType, ETH_CODE) Eth_GetEtherStats     ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2VAR(uint32, AUTOMATIC, ETH_APPL_DATA) etherStats \
                                                            );
#endif
#if STD_ON == ETH_GLOBALTIME_SUPPORT
extern FUNC(Std_ReturnType, ETH_CODE) Eth_GetCurrentTime  ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                                           );
extern FUNC(void, ETH_CODE) Eth_EnableEgressTimeStamp   ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) BufIdx \
                                                        );
extern FUNC(void, ETH_CODE) Eth_GetEgressTimeStamp  ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                VAR(uint8, AUTOMATIC) BufIdx, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                                    );
extern FUNC(void, ETH_CODE) Eth_GetIngressTimeStamp ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2VAR(Eth_DataType, AUTOMATIC, ETH_APPL_DATA) DataPtr, \
                                P2VAR(Eth_TimeStampQualType, AUTOMATIC, ETH_APPL_DATA) timeQualPtr, \
                                P2VAR(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                                    );
extern FUNC(void, ETH_CODE) Eth_SetCorrectionTime    ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2CONST(Eth_TimeIntDiffType, AUTOMATIC, ETH_APPL_DATA) timeOffsetPtr, \
                                P2CONST(Eth_RateRatioType, AUTOMATIC, ETH_APPL_DATA) rateRatioPtr \
                                                     );
extern FUNC(Std_ReturnType, ETH_CODE)  Eth_SetGlobalTime    ( \
                                VAR(uint8, AUTOMATIC) CtrlIdx, \
                                P2CONST(Eth_TimeStampType, AUTOMATIC, ETH_APPL_DATA) timeStampPtr \
                                                            );
#endif
extern FUNC(BufReq_ReturnType, ETH_CODE) Eth_ProvideTxBuffer    ( \
                            VAR(uint8, AUTOMATIC) CtrlIdx, \
                            P2VAR(Eth_BufIdxType, AUTOMATIC, ETH_APPL_DATA) BufIdxPtr, \
                            P2P2VAR(uint8, AUTOMATIC, ETH_APPL_DATA) BufPtr, \
                            P2VAR(uint16, AUTOMATIC, ETH_APPL_DATA) LenBytePtr \
                                                                );
extern FUNC(Std_ReturnType, ETH_CODE) Eth_Transmit  (
                            VAR(uint8, AUTOMATIC) CtrlIdx,
                            VAR(Eth_BufIdxType, AUTOMATIC) BufIdx,
                            VAR(Eth_FrameType, AUTOMATIC) FrameType,
                            VAR(boolean, AUTOMATIC) TxConfirmation,
                            VAR(uint16, AUTOMATIC) LenByte,
                            P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysAddrPtr
#if STD_ON == ETH_BRIDGE_SUPPORT
                          , P2CONST(uint8, AUTOMATIC, ETH_APPL_DATA) PhysSourceAddrPtr
#endif /* ETH_BRIDGE_SUPPORT  */  
                                                    );
extern FUNC(void, ETH_CODE) Eth_Receive( \
                                    VAR(uint8, AUTOMATIC) CtrlIdx, \
                                    P2VAR(Eth_RxStatusType, AUTOMATIC, ETH_APPL_DATA) RxStatusPtr \
                                        );
extern FUNC(void, ETH_CODE) Eth_TxConfirmation(VAR(uint8, AUTOMATIC) CtrlIdx);

#if STD_ON == ETH_VERSION_INFO_API
    #if STD_OFF == ETH_VERSION_INFO_API_MACRO
        extern FUNC(void, ETH_CODE) Eth_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, ETH_APPL_DATA) VersionInfoPtr);
    #endif /* ETH_VERSION_INFO_API_MACRO */
#endif /* ETH_VERSION_INFO_API */
extern FUNC(void, ETH_CODE) Eth_MainFunction(VAR(void, AUTOMATIC));
#define ETH_STOP_SEC_CODE

/** 
* @violates @ref Eth_h_REF_2 MISRA rule 19.15
* @violates @ref Eth_h_REF_3 MISRA rule 19.1
* 
*/
#include "Eth_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ETH_H */

/** @} */
