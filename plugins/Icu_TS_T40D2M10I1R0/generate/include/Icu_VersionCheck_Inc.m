[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ICU_VERSIONCHECK_INC_M'))"!]
[!VAR "ICU_VERSIONCHECK_INC_M"="'true'"!]
[!NOCODE!][!//
/**
*   @file    Icu_VersionCheck_Inc.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - version check macro.
*   @details Version checks.
*
*   @addtogroup ICU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FTM PORT_CI LPIT LPTMR
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

[!VAR "ICU_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "ICU_AR_RELEASE_MINOR_VERSION_TEMPLATE"="2"!][!//
[!VAR "ICU_AR_RELEASE_REVISION_VERSION_TEMPLATE"="2"!][!//
[!VAR "ICU_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
[!VAR "ICU_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
[!/*
[!ASSERT "ArReleaseMajorVersion = num:i($ICU_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR release major version number of the Basic Software Module Description file (Icu.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Icu_Cfg.h version [!"num:i($ICU_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseMinorVersion  = num:i($ICU_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]
        **** AUTOSAR release minor version number of the Basic Software Module Description file (Icu.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Icu_Cfg.h version [!"num:i($ICU_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "ArReleaseRevisionVersion  = num:i($ICU_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]
        **** AUTOSAR release revision version number of the Basic Software Module Description file (Icu.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Icu_Cfg.h version [!"num:i($ICU_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
*/!]
[!ASSERT "SwMajorVersion = num:i($ICU_SW_MAJOR_VERSION_TEMPLATE)"!]
        **** The software major number of the Basic Software Module Description file (Icu.epd version [!"SwMajorVersion"!]) and the Code template file (Icu_Cfg.h version [!"num:i($ICU_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ASSERT "SwMinorVersion = num:i($ICU_SW_MINOR_VERSION_TEMPLATE)"!]
        **** The software minor number of the Basic Software Module Description file (Icu.epd version [!"SwMinorVersion"!]) and the Code template file (Icu_Cfg.h version [!"num:i($ICU_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//
[!ENDIF!]