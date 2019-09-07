[!NOCODE!][!//
/**
*   @file    Crcu_VersionCheck_Src.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Crcu - version check macro.
*   @details Version checks.
*
*   @addtogroup CRCU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : CRCV2
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('CRCU_VERSIONCHECK_SRC_M'))"!]
[!VAR "CRCU_VERSIONCHECK_SRC_M"="'true'"!]
[!VAR "CRCU_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "CRCU_AR_RELEASE_MINOR_VERSION_TEMPLATE"="2"!][!//
[!VAR "CRCU_AR_RELEASE_REVISION_VERSION_TEMPLATE"="2"!][!//
[!VAR "CRCU_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
[!VAR "CRCU_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "CRCU_SW_PATCH_VERSION_TEMPLATE"="1"!][!//

[!SELECT "CommonPublishedInformation"!][!//

[!IF "not(num:i(ArReleaseMajorVersion) = num:i($CRCU_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release major version number of the Basic Software Module Description file (Crcu.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (CDD_Crcu_Cfg.c version [!"num:i($CRCU_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion)  = num:i($CRCU_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Crcu.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (CDD_Crcu_Cfg.c version [!"num:i($CRCU_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($CRCU_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Crcu.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (CDD_Crcu_Cfg.c version [!"num:i($CRCU_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($CRCU_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Crcu.epd version [!"SwMajorVersion"!]) and the Code template file (CDD_Crcu_Cfg.c version [!"num:i($CRCU_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($CRCU_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Crcu.epd version [!"SwMinorVersion"!]) and the Code template file (CDD_Crcu_Cfg.c version [!"num:i($CRCU_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($CRCU_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Crcu.epd version [!"SwPatchVersion"!]) and the Code template file (CDD_Crcu_Cfg.c version [!"num:i($CRCU_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF
[!ENDNOCODE!][!//
