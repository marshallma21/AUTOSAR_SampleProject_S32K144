[!NOCODE!][!//Do not generate any output, only warnigs and errors
/**
  \file    Eth_VersionChecks_Inc.m
  \version 1.0.1

  \brief   AUTOSAR Eth - version check macro.
  \details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Platform ARM
  Peripheral ENET
  Dependencies 
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.1
  BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
  All Rights Reserved.
*/

[!/* Multiple Inclusion Protection *** */!][!//
[!IF "not(var:defined('ETH_VERSIONCHECKS_M'))"!][!//
    [!VAR "ETH_VERSIONCHECKS_M"="true()"!][!//
    
    [!VAR "ETH_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
    [!VAR "ETH_AR_MINOR_VERSION_TEMPLATE"="2"!][!//
    [!VAR "ETH_AR_PATCH_VERSION_TEMPLATE"="2"!][!//
    [!VAR "ETH_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
    [!VAR "ETH_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
    [!VAR "ETH_SW_PATCH_VERSION_TEMPLATE"="1"!][!//
    [!VAR "ETH_VENDOR_ID_TEMPLATE"="43"!][!//
    [!VAR "ETH_MODULE_ID_TEMPLATE"="88"!][!//
    
    [!SELECT "CommonPublishedInformation"!][!//
        [!IF "ArReleaseMajorVersion != num:i($ETH_AR_MAJOR_VERSION_TEMPLATE)"!]
            [!ERROR!]AUTOSAR major version number of the Basic Software Module Description file ([!"ArReleaseMajorVersion"!]) and the Code Template files ([!"num:i($ETH_AR_MAJOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "ArReleaseMinorVersion != num:i($ETH_AR_MINOR_VERSION_TEMPLATE)"!]
            [!ERROR!]AUTOSAR minor version number of the Basic Software Module Description file ([!"ArReleaseMinorVersion"!]) and the Code Template files ([!"num:i($ETH_AR_MINOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "ArReleaseRevisionVersion != num:i($ETH_AR_PATCH_VERSION_TEMPLATE)"!]
            [!ERROR!]AUTOSAR patch version number of the Basic Software Module Description file ([!"ArReleaseRevisionVersion"!]) and the Code Template files ([!"num:i($ETH_AR_PATCH_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "SwMajorVersion != num:i($ETH_SW_MAJOR_VERSION_TEMPLATE)"!]
            [!ERROR!]The software major number of the Basic Software Module Description file ([!"SwMajorVersion"!]) and the Code Template files ([!"num:i($ETH_SW_MAJOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "SwMinorVersion != num:i($ETH_SW_MINOR_VERSION_TEMPLATE)"!]
            [!ERROR!]The software minor number of the Basic Software Module Description file ([!"SwMinorVersion"!]) and the Code Template files ([!"num:i($ETH_SW_MINOR_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "SwPatchVersion != num:i($ETH_SW_PATCH_VERSION_TEMPLATE)"!]
            [!ERROR!]The software patch number of the Basic Software Module Description file ([!"SwPatchVersion"!]) and the Code Template files ([!"num:i($ETH_SW_PATCH_VERSION_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "VendorId != num:i($ETH_VENDOR_ID_TEMPLATE)"!]
            [!ERROR!]The vendor ID of the Basic Software Module Description file ([!"VendorId"!]) and the Code Template files ([!"num:i($ETH_VENDOR_ID_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
        [!IF "ModuleId != num:i($ETH_MODULE_ID_TEMPLATE)"!]
            [!ERROR!]The module ID of the Basic Software Module Description file ([!"ModuleId"!]) and the Code Template files ([!"num:i($ETH_MODULE_ID_TEMPLATE)"!]) are different.[!ENDERROR!]
        [!ENDIF!][!//
    [!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
