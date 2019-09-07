[!CODE!][!//
/**
* @file    Port_PBcfg.c
* @implements Port_PBcfg.c_Artifact
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver postbuild configuration.
*
* @addtogroup  Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
*   Dependencies         : none
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_PBCFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section PORT_PBCFG_REF_2
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
* functions at file scope shall have internal linkage unless external linkage is required. 
* The functions/variables are part of PORT API.
*
* @section PORT_PBCFG_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_PBCFG_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character signifiance and case sensitivity are supported for external identifiers.
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"
[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Src_PB.m"!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('PortFamily'))=142)"!][!//
    [!INCLUDE "Port_S32K142_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=144)"!][!//
    [!INCLUDE "Port_S32K144_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=146)"!][!//
    [!INCLUDE "Port_S32K146_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=148)"!][!//
    [!INCLUDE "Port_S32K148_Resource.m"!][!//
[!ELSEIF "((ecu:get('PortFamily'))=118)"!][!//
    [!INCLUDE "Port_S32K118_Resource.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_PBCFG_C                       43
/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C        2

/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C     2
#define PORT_SW_MAJOR_VERSION_PBCFG_C                1
#define PORT_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_PBCFG_C                1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
/**
* @brief The number of configured Digital Filter Ports
*/
[!SELECT "PortConfigSet"!][!//
/** @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers. */
#define PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8         ([!"num:i(count(DigitalFilter/*))"!]U)
[!ENDSELECT!][!//

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
[!NOCODE!][!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetAltConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetAltConf"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutPinAltConf"="1"!]
[!ELSE!][!//
    [!VAR "MacPinMode"="concat(./PortPinMode,'_PORT',number(./PortPinPcr))"!][!//
    [!VAR "OutPinAltConf"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode)),':'),';'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetMSCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the selected pin */!][!//
[!MACRO "GetMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacPinMSCR"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the PCR */!][!//
[!CALL "GetAltConf"!][!//
[!/* Check if pin is disabled (analog) mode, meaning is configured in ALT0 */!][!//
[!IF "($OutPinAltConf = 0)"!][!//
    [!/* Do nothing */!][!//
[!ELSE!][!//
    [!/* Set the MUX field */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl($OutPinAltConf,8))"!][!//

    [!/* Check what type of drive strength is set */!][!//
    [!IF "text:match(./PortPinDSE,'Low_drive_strength')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,6))"!][!//
    [!ELSEIF "text:match(./PortPinDSE,'High_drive_strength')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,6))"!][!//
    [!ENDIF!][!//

    [!/* Check if open port passive filter is enabled */!][!//
    [!IF "./PortPinPFE"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,4))"!][!//
    [!ENDIF!][!//

    [!/* Check whether pull-up or pull-down is enabled */!][!//
    [!IF "text:match(./PortPinPE,'PullEnabled')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,1))"!][!//
        [!IF "text:match(./PortPinPS,'PullUp')"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,0))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacPinMSCR,8)"!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetUnusedMSCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the unused pins */!][!//
[!MACRO "GetUnusedMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacUnusedPinMSCR"="num:i(0)"!][!//
[!/* Set the Mux field of the PCR to 001, configuring the pin as GPIO */!][!//
[!VAR "MacUnusedPinMSCR"="bit:or($MacUnusedPinMSCR,bit:shl(1,8))"!][!//
[!/* Check if the pin is configured as input or output */!][!//
[!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
    [!/* Check what type of drive strength is set */!][!//
    [!IF "text:match(./PortPinDSE,'Low_Drive_Strength')"!][!//
        [!VAR "MacUnusedPinMSCR"="bit:or($MacUnusedPinMSCR,bit:shl(0,6))"!][!//
    [!ELSEIF "text:match(./PortPinDSE,'High_Drive_Strength')"!][!//
        [!VAR "MacUnusedPinMSCR"="bit:or($MacUnusedPinMSCR,bit:shl(1,6))"!][!//
    [!ENDIF!][!//
[!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
    [!/* Check if PE is enabled */!][!//
    [!IF "text:match(./PortPinPE,'PullEnabled')"!][!//
        [!VAR "MacUnusedPinMSCR"="bit:or($MacUnusedPinMSCR,bit:shl(1,1))"!][!//
        [!/* Check if Pull-up is enabled. For pull-down, bit value is zero */!][!//
        [!IF "text:match(./PortPinPS,'PullUp')"!][!//
            [!VAR "MacUnusedPinMSCR"="bit:or($MacUnusedPinMSCR,bit:shl(1,0))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacUnusedPinMSCR,8)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDO                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the output status for selected pin */!][!//
[!MACRO "GetPDO"!][!//
[!NOCODE!][!//
[!IF "not(contains(node:fallback(./PortPinMode,'ADC'),'ADC') or contains(node:fallback(./PortPinMode,'TAL'),'TAL') or contains(node:fallback(./PortPinMode,'ACMP'),'ACMP'))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO"="num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO"="num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO"="num:i(2)"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO"="num:i(2)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDO"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDDir                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetPDDir"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'ADC')"!][!//
    [!VAR "MacPinPDDir"="num:i(0)"!][!//
[!ELSE!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
        [!VAR "MacPinPDDir"="num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
        [!VAR "MacPinPDDir"="num:i(2)"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDDir"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetGPIO                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Set the initial GPIO Mode for selected pin */!][!//
[!MACRO "GetGPIO"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacGPIOMode"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetDirConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetDirConf"!][!//
[!NOCODE!][!//
[!IF "(./PortPinMode = 'GPIO')"!][!//
    [!IF "./PortPinDirectionChangeable"!][!//
        [!VAR "MacDirection"= "string('(boolean)TRUE')"!][!//
    [!ELSE!][!//
        [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDirection"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetModeChang                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "GetModeChang"!][!//
[!NOCODE!][!//
[!IF "./PortPinModeChangeable"!][!//
    [!VAR "MacModeChang"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacModeChang"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacModeChang"!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetDigitalFilterPort                     */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetDigitalFilterPort"!][!//
[!NOCODE!][!//
    [!IF "text:match(./DigitalFilterPort,'PORT_A')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(0)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_B')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(1)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_C')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(2)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_D')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(3)"!][!//
    [!ELSEIF "text:match(./DigitalFilterPort,'PORT_E')"!][!//
        [!VAR "MacDigitalFilterPort"="num:i(4)"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDigitalFilterPort"!][!//
[!ENDMACRO!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetDigitalFilterClock                    */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetDigitalFilterClock"!][!//
[!NOCODE!][!//
    [!IF "text:match(./DigitalFilterClock,'BUS_CLOCK')"!][!//
        [!VAR "MacDigitalFilterClock"="num:i(0)"!][!//
    [!ELSEIF "text:match(./DigitalFilterClock,'LPO_CLOCK')"!][!//
        [!VAR "MacDigitalFilterClock"="num:i(1)"!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDigitalFilterClock"!][!//
[!ENDMACRO!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetDigitalFilterPinMask                    */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetDigitalFilterPinMask"!][!//
[!NOCODE!][!//
[!VAR "MacDigitalFilterPinMask"="num:i(0)"!][!//
[!LOOP "DigitalFilterChannel/*"!][!//
    [!VAR "MacDigitalFilterPinMask"="bit:or($MacDigitalFilterPinMask,bit:shl(1,./DigitalFilterChannelIndex))"!][!//
[!ENDLOOP!]
[!ENDNOCODE!][!//
[!"num:inttohex($MacDigitalFilterPinMask,8)"!][!//
[!ENDMACRO!][!//

#define PORT_START_SEC_CONFIG_DATA_16
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_UnUsedPadsArrayDefault                */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
#if (0UL != PORT_MAX_UNUSED_PADS_U16)
/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
* @violates @ref PORT_PBCFG_REF_4 The used compilers use more than 31 chars for identifiers.
*/
static CONST(uint16, PORT_CONST) Port_au16NoUnUsedPadsArrayDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_UNUSED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "ecu:get('PortMaxPinNumber')"!][!//
    [!VAR "PinUsed"="0"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "$PinUsed=0"!][!//
            [!IF "num:i(./PortPinPcr)=$x"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "contains(concat(',',string(ecu:get('PortUnimplementedPAD')),','),concat(',',$x,','))"!][!//
            [!VAR "PinUsed"="$PinUsed + 1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
#endif
[!ENDSELECT!][!//

#define PORT_STOP_SEC_CONFIG_DATA_16
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"
[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_UnUsedPin                             */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
 * @brief Default Configuration for Pins not initialized
 */
static CONST(Port_Port_Ci_UnUsedPinConfigType, PORT_CONST) Port_UnUsedPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* @note: Configuration of Default pin */
    [!LOOP "NotUsedPortPin"!][!/*
        */!](uint32)[!CALL "GetUnusedMSCR"!], (Port_PinDirectionType)[!CALL "GetPDDir"!], (uint8)[!CALL "GetPDO"!][!/*
    */!][!ENDLOOP!]
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_aPinConfigDefault                     */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!VAR "LoopVar"="1"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pin default configuration data for configPB
*/
static CONST(Port_Port_Ci_PinConfigType, PORT_CONST) Port_aPinConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!VAR "Loop"="num:i($LoopVar)"!][!//
        [!IF "PortPinId = $Loop"!][!//
            [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    {(Port_InternalPinIdType)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetPDO"!], (Port_PinDirectionType)[!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!]},
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
    {(Port_InternalPinIdType)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetPDO"!], (Port_PinDirectionType)[!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!]}
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "count"= "$count+1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_aDigitalFilter                     */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8)
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(DigitalFilter/*))-1"!][!//
static CONST(Port_DigitalFilter_ConfigType, PORT_CONST) Port_aDigitalFilter[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8]=
{
[!NOCODE!]
[!LOOP "DigitalFilter/*"!][!//
    [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    /* Digital Filter Port, Digital Filter Clock, Digital Filter Width, Digital Filter Port Pins */
    {(uint8)[!CALL "GetDigitalFilterPort"!], (uint8)[!CALL "GetDigitalFilterClock"!], (uint8)[!"./DigitalFilterWidth"!], (uint32)[!CALL "GetDigitalFilterPinMask"!]},
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
    /* Digital Filter Port, Digital Filter Clock, Digital Filter Width, Digital Filter Port Pins */
    {(uint8)[!CALL "GetDigitalFilterPort"!], (uint8)[!CALL "GetDigitalFilterClock"!], (uint8)[!"./DigitalFilterWidth"!], (uint32)[!CALL "GetDigitalFilterPinMask"!]}
[!ENDCODE!][!//
    [!ENDIF!][!//
    [!VAR "count"= "$count+1"!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!]
};
#endif /* (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8) */
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!/*                          MACRO Port_ConfigPinParameter                     */!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
* @violates @ref PORT_PBCFG_REF_2 This warning appears when defining functions or objects 
* that will be used by the upper layers.
*/
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
CONST(Port_ConfigType, PORT_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ELSE!]
CONST(Port_ConfigType, PORT_CONST) Port_PBCfgVariantPredefined =
[!ENDIF!]
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
#if (0UL != PORT_MAX_UNUSED_PADS_U16)
    Port_au16NoUnUsedPadsArrayDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#else
    NULL_PTR,
#endif
    &Port_UnUsedPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Port_aPinConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8,
#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_U8)
    Port_aDigitalFilter[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
#else
    NULL_PTR
#endif
};
[!ENDSELECT!][!//

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref PORT_PBCFG_REF_3 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
[!ENDCODE!][!//
