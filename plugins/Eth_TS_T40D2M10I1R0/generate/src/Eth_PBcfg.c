/**
*   @file       Eth_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].c
*   @implements Eth_PBcfg_c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eth driver Post-Build configuration file
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
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Eth_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements should only be preceded
* by other preprocessor directives or comments.
* The usage of the MemMap.h file violates this advisory rule, but this
* mechanism is used to properly place the code and variables into their
* sections.
*
* @section Eth_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. Precautions shall be taken in
* order to prevent the contents of a header file being included twice. This is an approved violation
* of usage MemMap.h file used to create linkage sections.
*
* @section Eth_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, A compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
* Name length of the macro is unfortunately longer than 31 characters required by the agreed file
* template and cannot be changed. Authors of the template have not taken the MISRA rules into
* account.
*
* @section Eth_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the significance of more
* than 31 characters. Name length of the macros is unfortunately longer than 31 characters 
* which is required by the agreed macros format and cannot be changed. 
*
* @section Eth_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless
* external linkage is required. The APIs always require the external
* linkage. MISRA analysis tool does not see the linkage from other files
* therefore there is no violation.
*
* @section Eth_PBcfg_c_REF_7
* Violates MISRA 2004 Required Rule 11.1, Pointer to a function shall not be converted to anything
* else than integral type. This rule is not violated however the tool used for checks reports it
* therefore it must be commented here.
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
/* ETH001 */
#include "Eth.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_VENDOR_ID_C                      43
#define ETH_AR_RELEASE_MAJOR_VERSION_C       4
#define ETH_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Eth_PBcfg_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_PBcfg_c_REF_4 MISRA rule 5.1 */
#define ETH_AR_RELEASE_REVISION_VERSION_C    2
#define ETH_SW_MAJOR_VERSION_C               1
#define ETH_SW_MINOR_VERSION_C               0
#define ETH_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and ETH header file are of the same vendor */
#if (ETH_VENDOR_ID_C != ETH_VENDOR_ID)
    #error "Eth_PBcfg.c and Eth.h have different vendor ids"
#endif
/* Check if current file and ETH header file are of the same Autosar version */
#if ((ETH_AR_RELEASE_MAJOR_VERSION_C    != ETH_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_AR_RELEASE_MINOR_VERSION_C    != ETH_AR_RELEASE_MINOR_VERSION) || \
     (ETH_AR_RELEASE_REVISION_VERSION_C != ETH_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Eth_PBcfg.c and Eth.h are different"
#endif
/* Check if current file and ETH header file are of the same Software version */
#if ((ETH_SW_MAJOR_VERSION_C != ETH_SW_MAJOR_VERSION) || \
     (ETH_SW_MINOR_VERSION_C != ETH_SW_MINOR_VERSION) || \
     (ETH_SW_PATCH_VERSION_C != ETH_SW_PATCH_VERSION))
    #error "Software Version Numbers of Eth_PBcfg.c and Eth.h are different"
#endif
[!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
[!AUTOSPACING!][!//
[!NOCODE!][!//
[!/* 
*************************************
* Error checks of the configuration *
*************************************
*/!]
  [!INCLUDE "Eth_VersionChecks.m"!]
  [!INCLUDE "Eth_Checks.m"!]
  [!INCLUDE "Eth_GetRegisterValues.m"!]
[!ENDNOCODE!][!//
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
/** @violates @ref Eth_PBcfg_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_PBcfg_c_REF_4 MISRA rule 5.1 */
#define ETH_START_SEC_CONFIG_DATA_UNSPECIFIED

/** 
* @violates @ref Eth_PBcfg_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_PBcfg_c_REF_2 MISRA rule 19.15
*/
#include "Eth_MemMap.h"
/*******************************************************************************
* Multiple configurations
*******************************************************************************/
[!SELECT "EthConfigSet"!][!// Select configuration
[!NOCODE!]
    [!VAR "CountIndex"="0"!]
    [!VAR "BufCountIndex"="0"!]
    [!VAR "ConfigSetName"="name(.)"!]
[!ENDNOCODE!]
[!LOOP "EthCtrlConfig/*"!] [!// Loop over the controller config
  [!NOCODE!]
    [!VAR "CountIndex"="$CountIndex+1"!]
  [!ENDNOCODE!]
  [!CALL "GetRegisterValues"!]


/**
* @var Specified for EthCtrlConfig: [!"@name"!]
* @par Memory usage:
* - RX buffers area: Occupied space: [!"$RxBuffersSpace"!] Bytes
* - TX buffers area: Occupied space: [!"$TxBuffersSpace"!] Bytes
[!IF "EthVendorSpecific/EthEnableLoopbackMode/EthInternalLoopbackMode = 'true'"!][!//
*
* @warning Internal loopback is enabled, no external signals will be used
[!ENDIF!][!//
*/
static CONST(Eth_CtrlCfgType, ETH_APPL_CONST) [!"$ConfigSetName"!]_[!"name(.)"!] =
{
    /* Configured MAC Address is [!"$MACAddrString"!] */
    [!"num:inttohex($MACAddrHigh,8)"!]U, /**< First 32 bits of MAC address */
    [!"num:inttohex($MACAddrLow,8)"!]U, /**< Last 16 bits of MAC address<<16 | 0x8808 */
    [!"num:inttohex($TCRValue,8)"!]U, /**< [!"$TCRDesc"!] */
    /* RCR value: [!LOOP "text:split($RCRDesc,';')"!]
    [!CR!]    - [!"string(.)"!][!ENDLOOP!][!WS!]*/
    (((VAR(uint32, AUTOMATIC))[!"$MaxRxFrameLength"!]U)<<16U) | [!"num:inttohex($RCRValue,8)"!]U, /**< Value stored to RCR during initialization */
    (((VAR(uint32, AUTOMATIC))[!"EthVendorSpecific/EthMIISpeedControl"!]U)<<1U) | ((VAR(uint32, AUTOMATIC))[!"EthVendorSpecific/EthMDIOHoldTime"!]U<<8U), /**< Value stored to MSCR during initialization, F_sys,max = [!"num:i(num:i(EthVendorSpecific/EthMIISpeedControl)*10)"!] MHz */
  [!IF "$ETH_PERIPHERAL = string('ENET')"!][!// ENET Registers
    [!"num:inttohex($MaxRxFrameLength,8)"!]U, /* FTRL value */
    [!"num:inttohex($RACCValue,8)"!]U, /**< [!"$RACCDesc"!] */
    [!"EthVendorSpecific/EthInterPacketGap"!]U,  /**< Value stored to TIPG during initialization */
  [!ENDIF!][!//


#if STD_ON == ETH_DEM_EVENT_DETECT

    { [!IF "$EthDemEAccessEnabled     = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemEAccessEventId = '0'"!]0U[!ELSE!][!"$EthDemEAccessEventId"!][!ENDIF!]},
    { [!IF "$EthDemFrameLostEnabled   = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemFrameLostEventId = '0'"!]0U[!ELSE!][!"$EthDemFrameLostEventId"!][!ENDIF!]},
    { [!IF "$EthDemECRCEnabled        = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemECRCEventId= '0'"!]0U[!ELSE!][!"$EthDemECRCEventId"!] [!ENDIF!] },
    { [!IF "$EthDemEUnderSizeEnabled  = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemEUnderSizeEventId= '0'"!]0U[!ELSE!][!"$EthDemEUnderSizeEventId"!][!ENDIF!] },
    { [!IF "$EthDemEOverSizeEnabled   = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemEOverSizeEventId= '0'"!]0U[!ELSE!][!"$EthDemEOverSizeEventId"!] [!ENDIF!]},
    { [!IF "$EthDemEAlignmentEnabled  = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemEAlignmentEventId= '0'"!]0U[!ELSE!][!"$EthDemEAlignmentEventId"!][!ENDIF!] },
    { [!IF "$EthDemE1ColEnabled       = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemE1ColEventId= '0'"!]0U[!ELSE!][!"$EthDemE1ColEventId"!][!ENDIF!] },
    { [!IF "$EthDemEMColEnabled       = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemEMColEventId= '0'"!]0U[!ELSE!][!"$EthDemEMColEventId"!][!ENDIF!] },
    { [!IF "$EthDemELColEnabled       = 'true'"!](VAR(uint32, AUTOMATIC))STD_ON[!ELSE!](VAR(uint32, AUTOMATIC))STD_OFF[!ENDIF!], [!IF "$EthDemELColEventId= '0'"!]0U[!ELSE!][!"$EthDemELColEventId"!][!ENDIF!] },  
#endif /* ETH_DEM_EVENT_DETECT */
#if (STD_ON == ETH_GLOBALTIME_SUPPORT)
    ((VAR(uint32, AUTOMATIC))[!"num:i($EthTimeStampClk)"!]U),
#endif

    [!"$EthCtrlRxBufLenByteReal"!]U, /**< Maximum length of one Rx buffer (header, data, crc, 64-byte alignment) */
    [!"$EthCtrlTxBufLenByteReal"!]U, /**< Maximum length of one Tx buffer (header, data, 64-byte alignment) */
    [!"EthRxBufTotal"!]U, /**< Number of Rx buffers */
    [!"EthTxBufTotal"!]U, /**< Number of Tx buffers */

};
  [!VAR "BufCountIndex"="$BufCountIndex+1"!]
[!CR!]
[!ENDLOOP!][!//End loop of controller
[!CR!]
[!ENDSELECT!][!//
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/**
* @brief         Driver configuration to be passed to Eth_Init function
* @details       This array contains references to all multiple configurations
*                to be used for the Eth driver configuration.
*/
[!SELECT "EthConfigSet"!][!//
/** @violates @ref Eth_PBcfg_c_REF_5 MISRA rule 8.10  */
CONST(Eth_ConfigType, ETH_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
 {
  [!VAR "ConfigName" = "name(.)"!]
  [!VAR "MaxController" = "../EthGeneral/EthMaxCtrlsSupported - 1"!]
  [!FOR "Ctr_Count" = "0" TO "$MaxController"!]
    [!VAR "FoundCtrl"="0"!]
    [!VAR "FoundCtrlIdx"="0"!]
    [!VAR "CtrlConfigName"="''"!]
    [!LOOP "EthCtrlConfig/*"!][!//
      [!IF "$Ctr_Count = EthCtrlIdx"!]
        [!VAR "FoundCtrl"="1"!]
        [!VAR "FoundCtrlIdx"="node:pos(.)"!]
        [!VAR "CtrlConfigName" = "name(.)"!]
        [!BREAK!]
      [!ENDIF!]
    [!ENDLOOP!][!//
    [!IF "$FoundCtrl = 1"!]
      &[!"$ConfigName"!]_[!"$CtrlConfigName"!][!IF "$Ctr_Count < $MaxController"!],[!ENDIF!]
    [!ELSE!]
      NULL_PTR[!IF "$Ctr_Count < $MaxController"!],[!ENDIF!]
    [!ENDIF!]
  [!CR!]
  [!ENDFOR!]
 }
};
[!ENDSELECT!][!//

/** @violates @ref Eth_PBcfg_c_REF_3 MISRA rule 1.4 
* @violates @ref Eth_PBcfg_c_REF_4 MISRA rule 5.1 */
#define ETH_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** 
* @violates @ref Eth_PBcfg_c_REF_1 MISRA rule 19.1
* @violates @ref Eth_PBcfg_c_REF_2 MISRA rule 19.15
*/
#include "Eth_MemMap.h"

[!ENDIF!][!//VariantPostBuild and precomplie with variant:size()>1
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
