/**
*   @file       Eth_Cfg.h
*   @implements Eth_Cfg.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver configuration header file
*   @details File containing the configuration for the Ethernet driver
*   @note    This file was generated on [!"$date"!].
*
*   @addtogroup ETH_DRIVER_CONFIGURATION
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
[!AUTOSPACING!]
[!NOCODE!][!//
[!/* 
*************************************
* Error checks of the configuration *
*************************************
*/!]
  [!INCLUDE "Eth_Checks.m"!][!// Configuration checks
  [!INCLUDE "Eth_GetRegisterValues.m"!][!// Calculates register values from configuration parameters
  [!SELECT "EthConfigSet"!] [!//Check correctness of each multiple configuration
    [!CALL "CheckMultipleConfiguration"!]
  [!ENDSELECT!]

[!ENDNOCODE!][!//
#ifndef ETH_CFG_H
#define ETH_CFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_Cfg_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, functions should be used instead of
* function-like macros. Usage of function-like macros violates this advisory
* rule however the function-like macros are used only to wrap functions
* between driver layers so all advantages of function calls are used.
*
* @section Eth_Cfg_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_Cfg_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_Cfg_h_REF_4
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macros is unfortunately longer than 31 characters required by the agreed 
* macros format.
*
* @section Eth_Cfg_h_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_Cfg_h_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope
* if they are only accessed from within a single function. 
*
* @section Eth_Cfg_h_REF_7
* Violates MISRA 2004 Required Rule 19.10, In the definition of a function-like
* macro each instance of a parameter shall be enclosed in parentheses unless
* it is used as the operand of # or ##.
* This violation is wrongly reported by PCLint because the CtrIdx is not used
* as parameter in macro expansion.
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

[!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
#include "Det.h"
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
#include "Dem.h"
[!ENDIF!][!//
#include "Mcal.h"
#include "Reg_eSys.h"
#include "Soc_Ips.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_CFG                    43
#define ETH_MODULE_ID_CFG                    88
/** @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MAJOR_VERSION_CFG     4
/** @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_AR_RELEASE_MINOR_VERSION_CFG     2
/** @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_CFG  2
#define ETH_SW_MAJOR_VERSION_CFG             1
#define ETH_SW_MINOR_VERSION_CFG             0
#define ETH_SW_PATCH_VERSION_CFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MCAL header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Mcal.h are different"
    #endif
    /* Check if current file and Reg_eSys header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Reg_eSys.h are different"
    #endif
    /* Check if current file and Soc_Ips header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Soc_Ips.h are different"
    #endif
    /* Check if current file and DET header file are of the same Autosar version */
  [!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != DET_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Det.h are different"
    #endif
  [!ENDIF!][!//
  [!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
    /* Check if current file and Dem header file are of the same Autosar version */
    #if ((ETH_AR_RELEASE_MAJOR_VERSION_CFG != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (ETH_AR_RELEASE_MINOR_VERSION_CFG != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Eth_Cfg.h and Dem.h are different"
    #endif
  [!ENDIF!][!//
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define VARIANT_PRE_COMPILE 0
#define VARIANT_LINK_TIME 1
#define VARIANT_POST_BUILD 2

[!IF "(IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild' and (variant:size()<=1))"!][!//
#define ETH_PRECOMPILE_SUPPORT     (STD_ON)
[!ELSE!][!//
#define ETH_PRECOMPILE_SUPPORT     (STD_OFF)
[!ENDIF!][!//
 /******************************************************************************
 * Diagnostic Event Manager (DEM)
 ******************************************************************************/
[!IF "EthGeneral/EthVendorSpecific/EthDisableDemEventDetect = 'false'"!][!//
 #define ETH_DEM_EVENT_DETECT  (STD_ON)   /*!< Enables Diagnostic Event Manager */
[!ELSE!][!//
 #define ETH_DEM_EVENT_DETECT  (STD_OFF)  /*!< Enables Diagnostic Event Manager */
[!ENDIF!][!//
[!IF "EthGeneral/EthVendorSpecific/EthBridgeSupport = 'true'"!][!//
 #define ETH_BRIDGE_SUPPORT  (STD_ON)   /*!< Enable the Ethernet Bridge feature with the dual channels shall be supported*/
[!ELSE!][!//
 #define ETH_BRIDGE_SUPPORT  (STD_OFF)  /*!< Disable the Ethernet Bridge feature with the dual channels shall be supported */
[!ENDIF!][!//

[!IF "ecu:get('Eth.EthGeneral.GigabitSupport') = 'STD_ON'"!][!//
 #define ETH_GIGABIT_SUPPORT  (STD_ON)   /*!< Support Gigabit*/
[!ELSE!][!//
 #define ETH_GIGABIT_SUPPORT  (STD_OFF)  /*!< Not Support Gigabit */
[!ENDIF!][!//
/*
* @brief          Support for User Mode feature.
* @details        This parameter is enabled only in order to support the write access to some registers are protected in user mode.
*/
[!IF "EthGeneral/EthEnableUserModeSupport = 'true'"!]
    #define ETH_ENABLE_USER_MODE_SUPPORT (STD_ON)
[!ELSE!]
    #define ETH_ENABLE_USER_MODE_SUPPORT (STD_OFF)
[!ENDIF!]

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == ETH_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running ETH in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == ETH_ENABLE_USER_MODE_SUPPORT */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

[!IF "ecu:has('Eth.EthGeneral.EthHwUnderRegPotList')"!]
    [!VAR "numProtectedCtrl" = "0"!]
    [!VAR "listProtectedCtrl" = "ecu:get('Eth.EthGeneral.EthHwUnderRegPotList')"!]
    [!VAR "numProtectedCtrl" = "count(text:split($listProtectedCtrl,','))"!]
    [!IF "num:i($numProtectedCtrl) != 0"!]
/**
* @brief          Support for User Mode feature.
* @details        This parameters are defined only at least the Eth controller that has registers under REG_PROT protection.
*/
        #define ETH_ENET_REG_PROT_AVAILABLE
    [!ENDIF!]
    [!LOOP "text:split($listProtectedCtrl,',')"!]
        #define [!WS "1"!][!"text:toupper(normalize-space(node:current()))"!]_UNDER_REG_PROT[!CR!]
    [!ENDLOOP!]
[!ENDIF!]
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!NOCODE!][!// Check minimum/maximum available CtrlIdx
  [!VAR "MaxCtrlIdx"="0"!]
  [!VAR "MinCtrlIdx"="EthGeneral/EthMaxCtrlsSupported"!]
  [!SELECT "EthConfigSet"!]
    [!LOOP "EthCtrlConfig/*"!]
      [!IF "EthCtrlIdx < $MinCtrlIdx "!]
        [!VAR "MinCtrlIdx"="EthCtrlIdx"!]
      [!ENDIF!]
      [!IF "EthCtrlIdx > $MaxCtrlIdx "!]
        [!VAR "MaxCtrlIdx"="EthCtrlIdx"!]
      [!ENDIF!]
    [!ENDLOOP!]
  [!ENDSELECT!]
[!ENDNOCODE!]
#define ETH_MAX_CTRLIDX  ((uint8)[!"num:i($MaxCtrlIdx)"!]U)
#define ETH_MIN_CTRLIDX  ((uint8)[!"num:i($MinCtrlIdx)"!]U)

[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
/* Configuration access macros */
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TXBUFTOTAL(CtrlIdx)          ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthTxBufTotal)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RXBUFTOTAL(CtrlIdx)          ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthRxBufTotal)
    /* Compiler_Warning: This is a cast from pointer type (can be 32bit or 64 bit) to uint32. Assuming the pointer value is always in range of uint32 type(MCAL limitation), the cast is safe.*/
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TXBDSTARTADDRESS(CtrlIdx)    ((uint32)((*(Eth_StaticConfigPtr.pController[CtrlIdx])).TxBufStartAddr))
    /* Compiler_Warning: This is a cast from pointer type (can be 32bit or 64 bit) to uint32. Assuming the pointer value is always in range of uint32 type(MCAL limitation), the cast is safe.*/
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RXBDSTARTADDRESS(CtrlIdx)    ((uint32)((*(Eth_StaticConfigPtr.pController[CtrlIdx])).RxBufStartAddr))
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_CTRLTXBUFLENBYTE(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthCtrlTxBufLenByte)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_CTRLRXBUFLENBYTE(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthCtrlRxBufLenByte)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_ENABLERXINTERRUPT(CtrlIdx)   ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).EnableRxInterrupt)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_ENABLETXINTERRUPT(CtrlIdx)   ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).EnableTxInterrupt)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MDIOSUPPORT(CtrlIdx)         ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).MDIOSupport)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_GIGABITSUPPORT(CtrlIdx)         ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).GigabitSupport)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MACADDRESSLOW(CtrlIdx)       ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthMACAddressLow)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MACADDRESSHIGH(CtrlIdx)      ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthMACAddressHigh)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_MSCR(CtrlIdx)                ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthMSCR)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RCR(CtrlIdx)                 ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthRCR)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TCR(CtrlIdx)                 ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthTCR)
  [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_FTRL(CtrlIdx)                ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthFTRL)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_RACC(CtrlIdx)                ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthRACC)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TIPG(CtrlIdx)                ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).EthTIPG)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TIMESTAMP_CLK(CtrlIdx)       ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).EthTimestampClk)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_TIMESTAMP_INC(CtrlIdx)       ((VAR(uint32, AUTOMATIC))(1000000000U/ETH_CFG_TIMESTAMP_CLK(CtrlIdx)))
  [!ENDIF!][!//
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_CTRLIDXINETHIF(CtrlIdx)      ((*(Eth_StaticConfigPtr.pController[CtrlIdx])).EthCtrlIdxInEthIf)
#if STD_ON == ETH_DEM_EVENT_DETECT
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_ACCESS_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).ETH_DEM_E_ACCESS_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_ACCESS(CtrlIdx)    ((*(Eth_InternalCfgPtr->pController[CtrlIdx])).ETH_DEM_E_ACCESS_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_FRAMELOST_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_RX_FRAMES_LOST_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_FRAMELOST(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_RX_FRAMES_LOST_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_CRC_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_CRC_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_CRC(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_CRC_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_UNDERSIZE_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_UNDERSIZEFRAME_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_UNDERSIZE(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_UNDERSIZEFRAME_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_OVERSIZE_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_OVERSIZEFRAME_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_OVERSIZE(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_OVERSIZEFRAME_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_ALIGN_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_ALIGNMENT_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_ALIGN(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_ALIGNMENT_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_1COL_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_SINGLECOLLISION_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_1COL(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_SINGLECOLLISION_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_MCOL_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_MULTIPLECOLLISION_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_MCOL(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_MULTIPLECOLLISION_Cfg.id)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_LCOL_ENABLED(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_LATECOLLISION_Cfg.state)
    /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
    /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
    #define ETH_CFG_DEM_E_LCOL(CtrlIdx)    ((*(Eth_InternalCfgPtr[0].pController[CtrlIdx])).ETH_E_LATECOLLISION_Cfg.id)
#endif /* ETH_DEM_EVENT_DETECT */

[!ELSE!][!//Is Pre-Compile
/* For Pre-Compile only first configuration is used */
#define ETH_USED_PC_CFG 0

/*******************************************************************************
* Configuration parameters
*******************************************************************************/

[!SELECT "EthConfigSet"!][!// Select the configuration

[!NOCODE!]
  [!VAR "CountIndex"="0"!]
  [!VAR "BufCountIndex"="0"!]
  [!VAR "MaxController" = "num:i(count(EthCtrlConfig/*))"!]
[!ENDNOCODE!]
  [!IF "$MaxController=1"!]
    [!SELECT "EthCtrlConfig/*[1]"!]
      [!CALL "GetRegisterValues"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        /* Configured MAC Address is [!"$MACAddrString"!] */
        #define ETH_CFG_MACADDRESSLOW(CtrlIdx) [!"num:inttohex($MACAddrHigh,8)"!]U /* First 32 bits of MAC address */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_MACADDRESSHIGH(CtrlIdx) [!"num:inttohex($MACAddrLow,8)"!]U /* Last 16 bits of MAC address<<16 | 0x8808 */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TCR(CtrlIdx) ([!"num:inttohex($TCRValue,8)"!]U) /* [!"$TCRDesc"!] */
        /* RCR value: [!LOOP "text:split($RCRDesc,';')"!]
        [!CR!]            - [!"string(.)"!][!ENDLOOP!][!WS!]*/
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_RCR(CtrlIdx) ((((VAR(uint32, AUTOMATIC))[!"$MaxRxFrameLength"!]U)<<16U) | [!"num:inttohex($RCRValue,8)"!]U) /* Value stored to RCR during initialization */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_MSCR(CtrlIdx) ((((VAR(uint32, AUTOMATIC))[!"EthVendorSpecific/EthMIISpeedControl"!]U)<<1U) | ((VAR(uint32, AUTOMATIC))[!"EthVendorSpecific/EthMDIOHoldTime"!]U<<8U)) /*!< Value stored to MSCR during initialization, F_sys,max = [!"num:i(num:i(EthVendorSpecific/EthMIISpeedControl)*10)"!] MHz */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        /* Compiler_Warning: This is a cast from pointer type (can be 32bit or 64 bit) to uint32. Assuming the pointer value is always in range of uint32 type(MCAL limitation), the cast is safe.*/
        #define ETH_CFG_RXBDSTARTADDRESS(CtrlIdx) ((uint32)(&Eth_RxBuffers[[!"num:i($BufCountIndex)"!]][0])) /* Address of Rx buffer descriptors ring start, must be 64-bytes aligned. */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        /* Compiler_Warning: This is a cast from pointer type (can be 32bit or 64 bit) to uint32. Assuming the pointer value is always in range of uint32 type(MCAL limitation), the cast is safe.*/
        #define ETH_CFG_TXBDSTARTADDRESS(CtrlIdx) ((uint32)(&Eth_TxBuffers[[!"num:i($BufCountIndex)"!]][0])) /* Address of Tx buffer descriptors ring start, must be 64-bytes aligned. */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ACCESS_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemEAccessEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ACCESS(CtrlIdx)[!WS!] ([!"$EthDemEAccessEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_FRAMELOST_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemFrameLostEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_FRAMELOST(CtrlIdx)[!WS!] ([!"$EthDemFrameLostEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
         /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_CRC_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemECRCEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_CRC(CtrlIdx)[!WS!]([!"$EthDemECRCEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_UNDERSIZE_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemEUnderSizeEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_UNDERSIZE(CtrlIdx)[!WS!]([!"$EthDemEUnderSizeEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_OVERSIZE_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemEOverSizeEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_OVERSIZE(CtrlIdx)[!WS!]([!"$EthDemEOverSizeEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ALIGN_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemEAlignmentEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ALIGN(CtrlIdx)[!WS!]([!"$EthDemEAlignmentEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_1COL_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemE1ColEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_1COL(CtrlIdx)[!WS!]([!"$EthDemE1ColEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_MCOL_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemEMColEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_MCOL(CtrlIdx)[!WS!]([!"$EthDemEMColEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_LCOL_ENABLED(CtrlIdx)[!WS!][!IF "$EthDemELColEnabled = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/* Allows ETH_E_ACCESS reporting */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_LCOL(CtrlIdx)[!WS!]([!"$EthDemELColEventId"!]) /* Value assigned by Dem for ETH_E_ACCESS reporting */

        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_CTRLRXBUFLENBYTE(CtrlIdx) [!"$EthCtrlRxBufLenByteReal"!]U /* Maximum length of one Rx buffer (header, data, crc, 64-byte alignment) */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_CTRLTXBUFLENBYTE(CtrlIdx) [!"$EthCtrlTxBufLenByteReal"!]U /* Maximum length of one Tx buffer (header, data,64-byte alignment) */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_RXBUFTOTAL(CtrlIdx) [!"EthRxBufTotal"!]U /* Number of Rx buffers */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TXBUFTOTAL(CtrlIdx) [!"EthTxBufTotal"!]U /* Number of Tx buffers */
      [!IF "EthCtrlEnableRxInterrupt = 'true'"!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_ENABLERXINTERRUPT(CtrlIdx)    ((VAR(boolean, AUTOMATIC))TRUE)        /* RX interrupt enabled */ 
      [!ELSE!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_ENABLERXINTERRUPT(CtrlIdx)    ((VAR(boolean, AUTOMATIC))FALSE)       /* RX interrupt disabled */ 
      [!ENDIF!][!//
      [!IF "EthCtrlEnableTxInterrupt = 'true'"!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_ENABLETXINTERRUPT(CtrlIdx)    ((VAR(boolean, AUTOMATIC))TRUE)        /* TX interrupt enabled */ 
      [!ELSE!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_ENABLETXINTERRUPT(CtrlIdx)    ((VAR(boolean, AUTOMATIC))FALSE)       /* TX interrupt disabled */ 
      [!ENDIF!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
      [!IF "((ecu:list('Eth.EthConfigSet.EthCtrlConfig.SupportRMIIList'))[position()-1=node:current()/EthCtrlIdx] = 'STD_ON') and (EthVendorSpecific/EthCtrlSupportMDIO = 'true')"!][!//
        #define ETH_CFG_MDIOSUPPORT(CtrlIdx)         ((VAR(boolean, AUTOMATIC))TRUE)
      [!ELSE!][!//
        #define ETH_CFG_MDIOSUPPORT(CtrlIdx)         ((VAR(boolean, AUTOMATIC))FALSE)
      [!ENDIF!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
      [!IF "(EthVendorSpecific/EthPhyInterface = 'RGMII_1000Mbs')"!][!//
        #define ETH_CFG_GIGABITSUPPORT(CtrlIdx)         ((VAR(boolean, AUTOMATIC))TRUE)
      [!ELSE!][!//
        #define ETH_CFG_GIGABITSUPPORT(CtrlIdx)         ((VAR(boolean, AUTOMATIC))FALSE)
      [!ENDIF!][!//
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_CTRLIDXINETHIF(CtrlIdx) [!"EthCtrlIdx"!]U /* Instance ID of the controller within the EthIf module context */ 
      [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_FTRL(CtrlIdx) ((VAR(uint32, AUTOMATIC))[!"$MaxRxFrameLength"!]U)
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        #define ETH_CFG_RACC(CtrlIdx) ([!"num:inttohex($RACCValue,8)"!]U) /* [!"$RACCDesc"!] */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        #define ETH_CFG_TIPG(CtrlIdx) ((VAR(uint32, AUTOMATIC))[!"EthVendorSpecific/EthInterPacketGap"!]U)  /* Value stored to TIPG during initialization */
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TIMESTAMP_CLK(CtrlIdx)       ((VAR(uint32, AUTOMATIC))[!"num:i($EthTimeStampClk)"!]U)
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TIMESTAMP_INC(CtrlIdx)       ((VAR(uint32, AUTOMATIC))(1000000000U/ETH_CFG_TIMESTAMP_CLK(CtrlIdx)))
      [!ENDIF!]
    [!ENDSELECT!]
  [!ELSE!][!// More than 1 controller was configured
    [!NOCODE!]
      [!VAR "VarCfgMacLow"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCfgMacHigh"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCfgTcr"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCfgRcr"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCfgMscr"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarRxBdStart"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarTxBdStart"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCfgDemEAE"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCfgDemEA"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemFLE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemFL"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemCRCE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemCRC"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemUSE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemUS"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemOSE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemOS"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemALE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemAL"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemSCE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemSC"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemMCE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemMC"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemLCE"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgDemLC"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarEthTimeStmClk"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarRxBufLen"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarTxBufLen"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarRxBufTotal"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarTxBufTotal"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarEnRxIrq"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarEnTxIrq"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarMdioSupport"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarGigabitSupport"="'((0U==(CtrlIdx)) ? '"!]
      [!VAR "VarCtrlIdxIf"="'((0U==(CtrlIdx)) ? '"!]
      [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
        [!VAR "VarCfgFtrl"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgRacc"="'((0U==(CtrlIdx)) ? '"!]
        [!VAR "VarCfgTipg"="'((0U==(CtrlIdx)) ? '"!]
      [!ENDIF!]
      [!FOR "Ctr_Count" = "0" TO "$MaxController - 1"!][!// Check all Index in order
        [!LOOP "EthCtrlConfig/*"!][!// Loop all controller to find the correct one.
          [!IF "$Ctr_Count = EthCtrlIdx"!]
            [!CALL "GetRegisterValues"!]
            [!VAR "VarCfgMacLow"="concat($VarCfgMacLow, num:inttohex($MACAddrHigh,8),'U')"!]
            [!VAR "VarCfgMacHigh"="concat($VarCfgMacHigh, num:inttohex($MACAddrLow,8),'U')"!]
            [!VAR "VarCfgTcr"="concat($VarCfgTcr,num:inttohex($TCRValue,8),'U')"!]
            [!VAR "Temp"="$MaxRxFrameLength * 65536 + $RCRValue"!]
            [!VAR "VarCfgRcr"="concat($VarCfgRcr,num:inttohex($Temp,8),'U')"!]
            [!VAR "Temp"="EthVendorSpecific/EthMIISpeedControl * 2 + EthVendorSpecific/EthMDIOHoldTime + 256"!]
            [!VAR "VarCfgMscr"="concat($VarCfgMscr,num:inttohex($Temp,8),'U')"!]
            [!VAR "Temp"="concat('&Eth_RxBuffers[',num:i($Ctr_Count),'][0]')"!]
            [!VAR "VarRxBdStart"="concat($VarRxBdStart,'(uint32)',$Temp)"!]
            [!VAR "Temp"="concat('&Eth_TxBuffers[',num:i($Ctr_Count),'][0]')"!]
            [!VAR "VarTxBdStart"="concat($VarTxBdStart,'(uint32)',$Temp)"!]
            [!IF "$EthDemEAccessEnabled = 'true'"!]
              [!VAR "Temp"="'STD_ON'"!]
            [!ELSE!]
              [!VAR "Temp"="'STD_OFF'"!]
            [!ENDIF!]
            [!VAR "VarCfgDemEAE"="concat($VarCfgDemEAE,$Temp)"!]
            [!VAR "VarCfgDemEA"="concat($VarCfgDemEA,$EthDemEAccessEventId)"!]
              [!IF "$EthDemFrameLostEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemFLE"="concat($VarCfgDemFLE,$Temp)"!]
              [!VAR "VarCfgDemFL"="concat($VarCfgDemFL,$EthDemFrameLostEventId)"!]
              [!IF "$EthDemECRCEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemCRCE"="concat($VarCfgDemCRCE,$Temp)"!]
              [!VAR "VarCfgDemCRC"="concat($VarCfgDemCRC,$EthDemECRCEventId)"!]
              [!IF "$EthDemEUnderSizeEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemUSE"="concat($VarCfgDemUSE,$Temp)"!]
              [!VAR "VarCfgDemUS"="concat($VarCfgDemUS,$EthDemEUnderSizeEventId)"!]
              [!IF "$EthDemEOverSizeEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemOSE"="concat($VarCfgDemOSE,$Temp)"!]
              [!VAR "VarCfgDemOS"="concat($VarCfgDemOS,$EthDemEOverSizeEventId)"!]
              [!IF "$EthDemEAlignmentEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemALE"="concat($VarCfgDemALE,$Temp)"!]
              [!VAR "VarCfgDemAL"="concat($VarCfgDemAL,$EthDemEAlignmentEventId)"!]
              [!IF "$EthDemE1ColEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemSCE"="concat($VarCfgDemSCE,$Temp)"!]
              [!VAR "VarCfgDemSC"="concat($VarCfgDemSC,$EthDemE1ColEventId)"!]
              [!IF "$EthDemEMColEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemMCE"="concat($VarCfgDemMCE,$Temp)"!]
              [!VAR "VarCfgDemMC"="concat($VarCfgDemMC,$EthDemEMColEventId)"!]
              [!IF "$EthDemELColEnabled = 'true'"!]
                [!VAR "Temp"="'STD_ON'"!]
              [!ELSE!]
                [!VAR "Temp"="'STD_OFF'"!]
              [!ENDIF!]
              [!VAR "VarCfgDemLCE"="concat($VarCfgDemLCE,$Temp)"!]
              [!VAR "VarCfgDemLC"="concat($VarCfgDemLC,$EthDemELColEventId)"!]
              [!VAR "VarEthTimeStmClk"="concat($VarEthTimeStmClk,num:i($EthTimeStampClk))"!]
            [!VAR "VarRxBufLen"="concat($VarRxBufLen,$EthCtrlRxBufLenByteReal,'U')"!]
            [!VAR "VarTxBufLen"="concat($VarTxBufLen,$EthCtrlTxBufLenByteReal,'U')"!]
            [!VAR "VarRxBufTotal"="concat($VarRxBufTotal,EthRxBufTotal,'U')"!]
            [!VAR "VarTxBufTotal"="concat($VarTxBufTotal,EthTxBufTotal,'U')"!]
            [!IF "EthCtrlEnableRxInterrupt = 'true'"!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))TRUE'"!]
            [!ELSE!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))FALSE'"!]
            [!ENDIF!]
            [!VAR "VarEnRxIrq"="concat($VarEnRxIrq,$Temp)"!]
            [!IF "EthCtrlEnableTxInterrupt = 'true'"!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))TRUE'"!]
            [!ELSE!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))FALSE'"!]
            [!ENDIF!]
            [!VAR "VarEnTxIrq"="concat($VarEnTxIrq,$Temp)"!]
            [!IF "((ecu:list('Eth.EthConfigSet.EthCtrlConfig.SupportRMIIList'))[position()-1=node:current()/EthCtrlIdx] = 'STD_ON') and (EthVendorSpecific/EthCtrlSupportMDIO = 'true')"!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))TRUE'"!]
            [!ELSE!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))FALSE'"!]
            [!ENDIF!]
            [!VAR "VarMdioSupport"="concat($VarMdioSupport,$Temp)"!]
            [!IF "EthVendorSpecific/EthPhyInterface = 'RGMII_1000Mbs'"!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))TRUE'"!]
            [!ELSE!]
              [!VAR "Temp"="'(VAR(boolean, AUTOMATIC))FALSE'"!]
            [!ENDIF!]
            [!VAR "VarGigabitSupport"="concat($VarGigabitSupport,$Temp)"!]
            [!VAR "VarCtrlIdxIf"="concat($VarCtrlIdxIf,EthCtrlIdx,'U')"!]
            [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
              [!VAR "VarCfgFtrl"="concat($VarCfgFtrl,num:inttohex($MaxRxFrameLength,8),'U')"!]
              [!VAR "VarCfgRacc"="concat($VarCfgRacc,num:inttohex($RACCValue,8),'U')"!]
              [!VAR "VarCfgTipg"="concat($VarCfgTipg,num:inttohex(EthVendorSpecific/EthInterPacketGap,8),'U')"!]
            [!ENDIF!]
            [!IF "$Ctr_Count < $MaxController - 2"!][// Check if not yet the last one
              [!VAR "VarCfgMacLow"="concat($VarCfgMacLow,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCfgMacHigh"="concat($VarCfgMacHigh,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCfgTcr"="concat($VarCfgTcr,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCfgRcr"="concat($VarCfgRcr,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCfgMscr"="concat($VarCfgMscr,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarRxBdStart"="concat($VarRxBdStart,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarTxBdStart"="concat($VarTxBdStart,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCfgDemEAE"="concat($VarCfgDemEAE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCfgDemEA"="concat($VarCfgDemEA,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemFLE"="concat($VarCfgDemFLE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemFL"="concat($VarCfgDemFL,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemCRCE"="concat($VarCfgDemCRCE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemCRC"="concat($VarCfgDemCRC,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemUSE"="concat($VarCfgDemUSE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemUS"="concat($VarCfgDemUS,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemOSE"="concat($VarCfgDemOSE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemOS"="concat($VarCfgDemOS,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemALE"="concat($VarCfgDemALE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemAL"="concat($VarCfgDemAL,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemSCE"="concat($VarCfgDemSCE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemSC"="concat($VarCfgDemSC,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemMCE"="concat($VarCfgDemMCE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemMC"="concat($VarCfgDemMC,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemLCE"="concat($VarCfgDemLCE,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgDemLC"="concat($VarCfgDemLC,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarEthTimeStmClk"="concat($VarEthTimeStmClk,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarRxBufLen"="concat($VarRxBufLen,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarTxBufLen"="concat($VarTxBufLen,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarRxBufTotal"="concat($VarRxBufTotal,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarTxBufTotal"="concat($VarTxBufTotal,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarEnRxIrq"="concat($VarEnRxIrq,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarEnTxIrq"="concat($VarEnTxIrq,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarMdioSupport"="concat($VarMdioSupport,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarGigabitSupport"="concat($VarGigabitSupport,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!VAR "VarCtrlIdxIf"="concat($VarCtrlIdxIf,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
                [!VAR "VarCfgFtrl"="concat($VarCfgFtrl,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgRacc"="concat($VarCfgRacc,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
                [!VAR "VarCfgTipg"="concat($VarCfgTipg,' : ((',num:i($Ctr_Count),' ==(CtrlIdx)) ? ')"!]
              [!ENDIF!]
            [!ELSEIF "$Ctr_Count = $MaxController - 2"!][// The last controller
              [!VAR "VarCfgMacLow"="concat($VarCfgMacLow,' : ')"!]
              [!VAR "VarCfgMacHigh"="concat($VarCfgMacHigh,' : ')"!]
              [!VAR "VarCfgTcr"="concat($VarCfgTcr,' : ')"!]
              [!VAR "VarCfgRcr"="concat($VarCfgRcr,' : ')"!]
              [!VAR "VarCfgMscr"="concat($VarCfgMscr,' : ')"!]
              [!VAR "VarRxBdStart"="concat($VarRxBdStart,' : ')"!]
              [!VAR "VarTxBdStart"="concat($VarTxBdStart,' : ')"!]
              [!VAR "VarCfgDemEAE"="concat($VarCfgDemEAE,' : ')"!]
              [!VAR "VarCfgDemEA"="concat($VarCfgDemEA,' : ')"!]
                [!VAR "VarCfgDemFLE"="concat($VarCfgDemFLE,' : ')"!]
                [!VAR "VarCfgDemFL"="concat($VarCfgDemFL,' : ')"!]
                [!VAR "VarCfgDemCRCE"="concat($VarCfgDemCRCE,' : ')"!]
                [!VAR "VarCfgDemCRC"="concat($VarCfgDemCRC,' : ')"!]
                [!VAR "VarCfgDemUSE"="concat($VarCfgDemUSE,' : ')"!]
                [!VAR "VarCfgDemUS"="concat($VarCfgDemUS,' : ')"!]
                [!VAR "VarCfgDemOSE"="concat($VarCfgDemOSE,' : ')"!]
                [!VAR "VarCfgDemOS"="concat($VarCfgDemOS,' : ')"!]
                [!VAR "VarCfgDemALE"="concat($VarCfgDemALE,' : ')"!]
                [!VAR "VarCfgDemAL"="concat($VarCfgDemAL,' : ')"!]
                [!VAR "VarCfgDemSCE"="concat($VarCfgDemSCE,' : ')"!]
                [!VAR "VarCfgDemSC"="concat($VarCfgDemSC,' : ')"!]
                [!VAR "VarCfgDemMCE"="concat($VarCfgDemMCE,' : ')"!]
                [!VAR "VarCfgDemMC"="concat($VarCfgDemMC,' : ')"!]
                [!VAR "VarCfgDemLCE"="concat($VarCfgDemLCE,' : ')"!]
                [!VAR "VarCfgDemLC"="concat($VarCfgDemLC,' : ')"!]
                [!VAR "VarEthTimeStmClk"="concat($VarEthTimeStmClk,' : ')"!]
              [!VAR "VarRxBufLen"="concat($VarRxBufLen,' : ')"!]
              [!VAR "VarTxBufLen"="concat($VarTxBufLen,' : ')"!]
              [!VAR "VarRxBufTotal"="concat($VarRxBufTotal,' : ')"!]
              [!VAR "VarTxBufTotal"="concat($VarTxBufTotal,' : ')"!]
              [!VAR "VarEnRxIrq"="concat($VarEnRxIrq,' : ')"!]
              [!VAR "VarEnTxIrq"="concat($VarEnTxIrq,' : ')"!]
              [!VAR "VarMdioSupport"="concat($VarMdioSupport,' : ')"!]
              [!VAR "VarGigabitSupport"="concat($VarGigabitSupport,' : ')"!]
              [!VAR "VarCtrlIdxIf"="concat($VarCtrlIdxIf,' : ')"!]
              [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
                [!VAR "VarCfgFtrl"="concat($VarCfgFtrl,' : ')"!]
                [!VAR "VarCfgRacc"="concat($VarCfgRacc,' : ')"!]
                [!VAR "VarCfgTipg"="concat($VarCfgTipg,' : ')"!]
              [!ENDIF!]
            [!ENDIF!]
            [!BREAK!]
          [!ENDIF!]
        [!ENDLOOP!][!//
      [!ENDFOR!]
      [!FOR "Ctr_Count" = "0" TO "$MaxController - 2"!][!// Check all Index in order
        [!VAR "VarCfgMacLow"="concat($VarCfgMacLow,' )')"!]
        [!VAR "VarCfgMacHigh"="concat($VarCfgMacHigh,' )')"!]
        [!VAR "VarCfgTcr"="concat($VarCfgTcr,' )')"!]
        [!VAR "VarCfgRcr"="concat($VarCfgRcr,' )')"!]
        [!VAR "VarCfgMscr"="concat($VarCfgMscr,' )')"!]
        [!VAR "VarRxBdStart"="concat($VarRxBdStart,' )')"!]
        [!VAR "VarTxBdStart"="concat($VarTxBdStart,' )')"!]
        [!VAR "VarCfgDemEAE"="concat($VarCfgDemEAE,' )')"!]
        [!VAR "VarCfgDemEA"="concat($VarCfgDemEA,' )')"!]
        [!VAR "VarCfgDemFLE"="concat($VarCfgDemFLE,' )')"!]
        [!VAR "VarCfgDemFL"="concat($VarCfgDemFL,' )')"!]
        [!VAR "VarCfgDemCRCE"="concat($VarCfgDemCRCE,' )')"!]
        [!VAR "VarCfgDemCRC"="concat($VarCfgDemCRC,' )')"!]
        [!VAR "VarCfgDemUSE"="concat($VarCfgDemUSE,' )')"!]
        [!VAR "VarCfgDemUS"="concat($VarCfgDemUS,' )')"!]
        [!VAR "VarCfgDemOSE"="concat($VarCfgDemOSE,' )')"!]
        [!VAR "VarCfgDemOS"="concat($VarCfgDemOS,' )')"!]
        [!VAR "VarCfgDemALE"="concat($VarCfgDemALE,' )')"!]
        [!VAR "VarCfgDemAL"="concat($VarCfgDemAL,' )')"!]
        [!VAR "VarCfgDemSCE"="concat($VarCfgDemSCE,' )')"!]
        [!VAR "VarCfgDemSC"="concat($VarCfgDemSC,' )')"!]
        [!VAR "VarCfgDemMCE"="concat($VarCfgDemMCE,' )')"!]
        [!VAR "VarCfgDemMC"="concat($VarCfgDemMC,' )')"!]
        [!VAR "VarCfgDemLCE"="concat($VarCfgDemLCE,' )')"!]
        [!VAR "VarCfgDemLC"="concat($VarCfgDemLC,' )')"!]
        [!VAR "VarEthTimeStmClk"="concat($VarEthTimeStmClk,' )')"!]
        [!VAR "VarRxBufLen"="concat($VarRxBufLen,' )')"!]
        [!VAR "VarTxBufLen"="concat($VarTxBufLen,' )')"!]
        [!VAR "VarRxBufTotal"="concat($VarRxBufTotal,' )')"!]
        [!VAR "VarTxBufTotal"="concat($VarTxBufTotal,' )')"!]
        [!VAR "VarEnRxIrq"="concat($VarEnRxIrq,' )')"!]
        [!VAR "VarEnTxIrq"="concat($VarEnTxIrq,' )')"!]
        [!VAR "VarMdioSupport"="concat($VarMdioSupport,' )')"!]
        [!VAR "VarGigabitSupport"="concat($VarGigabitSupport,' )')"!]
        [!VAR "VarCtrlIdxIf"="concat($VarCtrlIdxIf,' )')"!]
        [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
          [!VAR "VarCfgFtrl"="concat($VarCfgFtrl,' )')"!]
          [!VAR "VarCfgRacc"="concat($VarCfgRacc,' )')"!]
          [!VAR "VarCfgTipg"="concat($VarCfgTipg,' )')"!]
        [!ENDIF!]
      [!ENDFOR!]
    [!ENDNOCODE!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_MACADDRESSLOW(CtrlIdx)       [!"$VarCfgMacLow"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_MACADDRESSHIGH(CtrlIdx)      [!"$VarCfgMacHigh"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TCR(CtrlIdx)                 [!"$VarCfgTcr"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_RCR(CtrlIdx)                 [!"$VarCfgRcr"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_MSCR(CtrlIdx)                [!"$VarCfgMscr"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_RXBDSTARTADDRESS(CtrlIdx)    [!"$VarRxBdStart"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TXBDSTARTADDRESS(CtrlIdx)    [!"$VarTxBdStart"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ACCESS_ENABLED(CtrlIdx) [!"$VarCfgDemEAE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ACCESS(CtrlIdx)        [!"$VarCfgDemEA"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_FRAMELOST_ENABLED(CtrlIdx)[!WS!] [!"$VarCfgDemFLE"!]       
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_FRAMELOST(CtrlIdx) [!"$VarCfgDemFL"!]       
          /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_CRC_ENABLED(CtrlIdx)[!WS!] [!"$VarCfgDemCRCE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_CRC(CtrlIdx) [!"$VarCfgDemCRC"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_UNDERSIZE_ENABLED(CtrlIdx)[!WS!][!"$VarCfgDemUSE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_UNDERSIZE(CtrlIdx) [!"$VarCfgDemUS"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_OVERSIZE_ENABLED(CtrlIdx)[!WS!][!"$VarCfgDemOSE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_OVERSIZE(CtrlIdx) [!"$VarCfgDemOS"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ALIGN_ENABLED(CtrlIdx)[!WS!][!"$VarCfgDemALE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_ALIGN(CtrlIdx) [!"$VarCfgDemAL"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_1COL_ENABLED(CtrlIdx)[!WS!][!"$VarCfgDemSCE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_1COL(CtrlIdx) [!"$VarCfgDemSC"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_MCOL_ENABLED(CtrlIdx)[!WS!][!"$VarCfgDemMCE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_MCOL(CtrlIdx) [!"$VarCfgDemMC"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_LCOL_ENABLED(CtrlIdx)[!WS!][!"$VarCfgDemLCE"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_DEM_E_LCOL(CtrlIdx) [!"$VarCfgDemLC"!]      
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_CTRLRXBUFLENBYTE(CtrlIdx)    [!"$VarRxBufLen"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_CTRLTXBUFLENBYTE(CtrlIdx)    [!"$VarTxBufLen"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_RXBUFTOTAL(CtrlIdx)          [!"$VarRxBufTotal"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TXBUFTOTAL(CtrlIdx)          [!"$VarTxBufTotal"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_ENABLERXINTERRUPT(CtrlIdx)   [!"$VarEnRxIrq"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_ENABLETXINTERRUPT(CtrlIdx)   [!"$VarEnTxIrq"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_MDIOSUPPORT(CtrlIdx)         [!"$VarMdioSupport"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_GIGABITSUPPORT(CtrlIdx)         [!"$VarGigabitSupport"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_CTRLIDXINETHIF(CtrlIdx)      [!"$VarCtrlIdxIf"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
      [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_FTRL(CtrlIdx)                [!"$VarCfgFtrl"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_RACC(CtrlIdx)                [!"$VarCfgRacc"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TIPG(CtrlIdx)                [!"$VarCfgTipg"!]
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TIMESTAMP_CLK(CtrlIdx)       ((VAR(uint32, AUTOMATIC))[!"$VarEthTimeStmClk"!]U)
        /** @violates @ref Eth_Cfg_h_REF_1 MISRA rule 19.7 */
        /** @violates @ref Eth_Cfg_h_REF_7 MISRA rule 19.10 */
        #define ETH_CFG_TIMESTAMP_INC(CtrlIdx)       ((VAR(uint32, AUTOMATIC))(1000000000U/ETH_CFG_TIMESTAMP_CLK(CtrlIdx)))

      [!ENDIF!]
  [!ENDIF!]
[!CR!]

[!ENDSELECT!]
[!ENDIF!][!//
/******************************************************************************
* Features enable/disable switches 
******************************************************************************/
/* ETH004_Conf */
#define ETH_VERSION_INFO_API[!WS!][!IF "EthGeneral/EthVersionInfoApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables Version info function */
/* ETH005_Conf */
#define ETH_VERSION_INFO_API_MACRO[!WS!][!IF "EthGeneral/EthVersionInfoApiMacro = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables Version info function implementation as macro */
/* ETH019_Conf */
#define ETH_UPDATE_PHYS_ADDR_FILTER[!WS!][!IF "EthGeneral/EthUpdatePhysAddrFilter = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables optional API Eth_UpdatePhysAddrFilter */

/* Multi-Buffer frames support */
#define ETH_USE_MULTIBUFFER_RX_FRAMES[!WS!][!IF "EthGeneral/EthVendorSpecific/EthUseMultiBufferRxFrames = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables multi-buffer frames reception */
#define ETH_USE_RX_FRAMES_WRAP[!WS!][!IF "EthGeneral/EthVendorSpecific/EthEnableRxFrameWrap = 'true' and EthGeneral/EthVendorSpecific/EthUseMultiBufferRxFrames = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables multi-buffer frames wrap */

/* TX Multi-Buffer frames support */
#define ETH_USE_MULTIBUFFER_TX_FRAMES[!WS!][!IF "EthGeneral/EthVendorSpecific/EthUseMultiBufferTxFrames = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!WS!]/*!< Enables multi-buffer frames transmission */

[!NOCODE!][!//
  [!/* This code check all multiple configurations whether all code switches
       (AllMiiDisabled) 
       have the value equal to false which means that the code can be omitted.
       The code cannot be omitted when a true value is set in at least 
       one multiple configuration */!]
  [!/* Set initial value to "can be omitted" */!]
  [!VAR "AllMiiDisabled" = "true()"!]
  [!/* Go through all multiple configurations and change initial value to
       "cannot be omitted" if a true value is found for a parameter */!]
  [!SELECT "EthConfigSet"!][!//
    [!LOOP "EthCtrlConfig/*"!][!//
      [!IF "EthCtrlEnableMii = 'true'"!]
        [!VAR "AllMiiDisabled" = "false()"!]
      [!ENDIF!]   
    [!ENDLOOP!]
  [!ENDSELECT!][!//
[!ENDNOCODE!][!//
    /* This macro can have STD_OFF value only if the controller in all multiple configurations
       does not use the MII API. The value STD_ON means that code is compiled but the MII
       might not be used (API is present because it is needed in another multiple configuration
       but it is not called). */
    /* @requirements SWS_Eth_00012_Conf */
[!IF "$AllMiiDisabled = 'true'"!][!//
    #define ETH_CTRLENABLE_MII (STD_OFF)        /*!< MII handling functions compilation disabled */      
[!ELSE!][!//
    #define ETH_CTRLENABLE_MII (STD_ON)         /*!< MII handling functions compilation enabled */      
[!ENDIF!][!//
[!SELECT "EthGeneral"!][!//
    #define ETH_GETDROPCOUNTAPI[!WS!][!IF "EthGetDropCountApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
    #define ETH_GET_ETHERSTATS_API[!WS!][!IF "EthGetEtherStatsApi = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
    #define ETH_GLOBALTIME_SUPPORT[!WS!][!IF "$ETH_PERIPHERAL = string('ENET') and EthGlobalTimeSupport = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
  [!SELECT "EthCtrlOffloading"!][!//
    #define ETH_ENABLE_OFFLOAD_CRC_IPV4[!WS!][!IF "$ETH_PERIPHERAL = string('ENET') and EthCtrlEnableOffloadChecksumIPv4 = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
    #define ETH_ENABLE_OFFLOAD_CRC_ICMP[!WS!][!IF "$ETH_PERIPHERAL = string('ENET') and EthCtrlEnableOffloadChecksumICMP = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
    #define ETH_ENABLE_OFFLOAD_CRC_TCP[!WS!][!IF "$ETH_PERIPHERAL = string('ENET') and EthCtrlEnableOffloadChecksumTCP = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
    #define ETH_ENABLE_OFFLOAD_CRC_UDP[!WS!][!IF "$ETH_PERIPHERAL = string('ENET') and EthCtrlEnableOffloadChecksumUDP = 'true'"!](STD_ON)[!ELSE!](STD_OFF)[!ENDIF!][!CR!][!//
  [!ENDSELECT!][!//
[!ENDSELECT!]
/******************************************************************************
* Development Error Detection 
******************************************************************************/
/* ETH003_Conf */
[!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
    #define ETH_DEV_ERROR_DETECT  (STD_ON)      /*!< Enables Development Error Detect feature */
[!ELSE!][!//
    #define ETH_DEV_ERROR_DETECT  (STD_OFF)     /*!< Enables Development Error Detect feature */
[!ENDIF!][!//
    
    /******************************************************************************
    * Configuration constants
    ******************************************************************************/
    /* Required Eth buffers alignment, may be different for TX and RX depending on the used IP */
    #define ETH_TX_BUF_ALIGNMENT 64 /* 64 bytes */
    #define ETH_RX_BUF_ALIGNMENT 64 /* 64 bytes */
    /* ETH002_Conf */
    #define ETH_MAXCTRLS_SUPPORTED [!"EthGeneral/EthMaxCtrlsSupported"!]U  /* Number of supported controllers */
    #define ETH_NUM_OF_CONFIGURATIONS 1U /* Number of configurations */
    #define ETH_DRIVER_INSTANCE [!"EthGeneral/EthIndex"!]U   /* Instance number assigned to the driver */
    /* [!"$ETH_PERIPHERAL"!] is running on half of core frequency at least 10 bus cycles are needed
       so the minimal value is 20 */
    #define ETH_RESET_WAIT_LOOP_COUNT 30U /* Reset waiting loop timeout */
    #define ETH_INFINITE_LOOP_PROTECTION 4096U /* Number of runs in the loop 
                  before it is claimed to be never-ending and broken */   
    #define DEBUG_VARIABLES (STD_OFF) /* Debug variables inclusion into the code -
     debug variables are normally excluded from the code to save memory space */
    
    #define ETH_MULTICAST_POOL_SIZE [!"num:i(EthGeneral/EthVendorSpecific/EthMulticastPoolSize)"!]U /* Maximal count of MAC address inside multicast pool */

    #define ETHTXBUFNUM [!"num:i(EthGeneral/EthVendorSpecific/EthMaxTXBuffersSupported)"!]U /* Number of tranmit buffers supported by the driver 
         each buffer requires one byte in internal driver memory, decreasing this number
         allows reducing memory consumption */


[!NOCODE!]
    [!VAR "MAX_CONTROLLER_CFG"="num:i(count(EthConfigSet/EthCtrlConfig/*))"!]
[!IF "EthGeneral/EthMaxCtrlsSupported >1 "!][!//
    [!VAR "RxSpaceMax" = "num:i(ceiling(num:i(EthGeneral/EthVendorSpecific/EthMaxRXBuffersSize) div 64) * 64)"!]
    [!VAR "TxSpaceMax" = "num:i(ceiling(num:i(EthGeneral/EthVendorSpecific/EthMaxTXBuffersSize) div 64) * 64)"!]
[!ELSE!][!// 
    [!VAR "RxSpaceMax" = "EthGeneral/EthVendorSpecific/EthMaxRXBuffersSize"!]
    [!VAR "TxSpaceMax" = "EthGeneral/EthVendorSpecific/EthMaxTXBuffersSize"!]
[!ENDIF!][!//
[!ENDNOCODE!]
    /* Sizes of memory blocks allocated for TX/RX data buffers and related descriptors */
    #define ETH_TX_BUF_MEM_SIZE ([!"num:i($TxSpaceMax)"!]U)
    #define ETH_RX_BUF_MEM_SIZE ([!"num:i($RxSpaceMax)"!]U)
    #define ETH_MAX_CONTROLLER_CFG  ([!"num:i($MAX_CONTROLLER_CFG)"!]U)
    
    
    
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief         Type for Ethernet driver configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
* @implements Eth_CtrlCfgType_structure
*/
typedef struct
{
    uint32 EthMACAddressLow;     /**< First 32 bits of MAC address */
    uint32 EthMACAddressHigh; /**< Last 16 bits of MAC address<<16|0x8808 */
    uint32 EthTCR;         /**< Value stored to TCR during initialization */
    uint32 EthRCR;         /**< Value stored to RCR during initialization */
    uint32 EthMSCR;        /**< Value stored to MSCR during initialization */
[!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
    uint32 EthFTRL;        /**< Value stored to FTRL during initialization */
    uint32 EthRACC;        /**< Value stored to RACC during initialization */
    uint32 EthTIPG;        /**< Value stored to TIPG during initialization */
[!ENDIF!]
#if ETH_DEM_EVENT_DETECT
    Mcal_DemErrorType ETH_DEM_E_ACCESS_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_ACCESS and   */
    Mcal_DemErrorType ETH_E_RX_FRAMES_LOST_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_ACCESS and   */
    Mcal_DemErrorType ETH_E_CRC_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_CRC and   */
    Mcal_DemErrorType ETH_E_UNDERSIZEFRAME_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_UNDERSIZEFRAME and   */
    Mcal_DemErrorType ETH_E_OVERSIZEFRAME_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_OVERSIZEFRAME and   */
    Mcal_DemErrorType ETH_E_ALIGNMENT_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_ALIGNMENT and   */
    Mcal_DemErrorType ETH_E_SINGLECOLLISION_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_SINGLECOLLISION and   */
    Mcal_DemErrorType ETH_E_MULTIPLECOLLISION_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_MULTIPLECOLLISION and   */
    Mcal_DemErrorType ETH_E_LATECOLLISION_Cfg; /**< Contains enablement of specific
                                                error report and value assigned
                                                by Dem as ETH_E_LATECOLLISION and   */
#endif /* ETH_DEM_EVENT_DETECT */
#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
    uint32 EthTimestampClk;
#endif
    uint16 EthCtrlRxBufLenByte;  /**< Length of one Rx buffer*/
    uint16 EthCtrlTxBufLenByte;  /**< Length of one Tx buffer */
    uint8 EthRxBufTotal;         /**< Number of Rx buffers */
    uint8 EthTxBufTotal;         /**< Number of Tx buffers */
} Eth_CtrlCfgType;

/**
* @brief         Type for Ethernet driver Static configuration values storage.
* @details       This type is used to collect and pass all configuration data
*                of one controller (except those which have only
*                precompile variant) to the Eth driver.
*/
typedef struct
{
    boolean EnableRxInterrupt;  /**< Enable interrupt requests for frame
                                      reception event */
    boolean EnableTxInterrupt;  /**< Enable interrupt requests for
                                      frame transmission event */
    boolean MDIOSupport;        /**<Support MDIO for current controller */
    boolean GigabitSupport;     /**<Support Gigabits for current controller */
    uint8 EthCtrlIdxInEthIf;    /**< Instance ID of the controller */
    uint8 *TxBufStartAddr;      /**< Start address for TX buffer of the controller */
    uint8 *RxBufStartAddr;      /**< Start address for TX buffer of the controller */
} Eth_StaticCtrlCfgType;

/* 
* @brief This type is used to group all multiple configurations.
*/   
typedef struct 
{
    P2CONST(Eth_CtrlCfgType, TYPEDEF, ETH_APPL_DATA) pController[ETH_MAXCTRLS_SUPPORTED];
} Eth_ConfigType;

/* 
* @brief This type is used to group Static configuration for all controllers.
*/   
typedef struct 
{
    P2CONST(Eth_StaticCtrlCfgType, TYPEDEF, ETH_APPL_DATA) pController[ETH_MAXCTRLS_SUPPORTED];
} Eth_StaticConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//

#define ETH_START_SEC_CONST_UNSPECIFIED

/** 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

/* Configuration for parameters which are not variant */
extern CONST(Eth_StaticConfigType, ETH_APPL_CONST) Eth_StaticConfigPtr;

#define ETH_STOP_SEC_CONST_UNSPECIFIED

/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "Eth_MemMap.h"
[!ENDIF!]
/**
* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

[!NOCODE!][!//
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
  [!VAR "configName" = "as:name(EthConfigSet)"!][!//
  [!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
      [!CODE!][!WS4!]extern CONST(Eth_ConfigType, ETH_CONST) [!"$configName"!]_[!"."!];[!CR!][!ENDCODE!][!//
    [!ENDLOOP!][!//
  [!ELSE!][!//
      [!CODE!][!WS4!]extern CONST(Eth_ConfigType, ETH_CONST) [!"$configName"!];[!CR!][!ENDCODE!][!//
  [!ENDIF!][!//


[!ENDIF!][!//
[!ENDNOCODE!][!//
/**
* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

/* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "Eth_MemMap.h"
    extern VAR(uint8, ETH_VAR) Eth_RxBuffers[ETH_MAX_CONTROLLER_CFG][ETH_RX_BUF_MEM_SIZE];
    extern VAR(uint8, ETH_VAR) Eth_TxBuffers[ETH_MAX_CONTROLLER_CFG][ETH_TX_BUF_MEM_SIZE]; 
/* @violates @ref Eth_Cfg_h_REF_4 MISRA rule 1.4 
* @violates @ref Eth_Cfg_h_REF_5 MISRA rule 5.1 */
#define ETH_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/** 
* @violates @ref Eth_Cfg_h_REF_2 MISRA rule 19.1 
* @violates @ref Eth_Cfg_h_REF_3 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif /* __cplusplus */   
#endif /* ETH_CFG_H */
/** @} */
