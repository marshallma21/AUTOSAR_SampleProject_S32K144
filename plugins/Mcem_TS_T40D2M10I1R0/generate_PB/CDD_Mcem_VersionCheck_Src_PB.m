[!NOCODE!][!//
/**
  @file    Mcem_VersionCheck_Src_PB.m
  @version 1.0.1

  @brief   AUTOSAR Mcem - version check macro.
  @details Version checks.

  Project AUTOSAR 4.2 MCAL
  Platform ARM
  Peripheral Eim Erm
  Dependencies none

  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.1
  BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/

[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('CDD_MCEM_VERSION_CHECK_SRC_PB_M'))"!]
[!VAR "CDD_MCEM_VERSION_CHECK_SRC_PB_M"="'true'"!]


[!VAR "CDD_MCEM_AR_RELEASE_MAJOR_VERSION_TEMPLATE"="4"!][!// 
[!VAR "CDD_MCEM_AR_RELEASE_MINOR_VERSION_TEMPLATE"="2"!][!// 
[!VAR "CDD_MCEM_AR_RELEASE_REVISION_VERSION_TEMPLATE"="2"!][!// 
[!VAR "CDD_MCEM_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//      
[!VAR "CDD_MCEM_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "CDD_MCEM_SW_PATCH_VERSION_TEMPLATE"="1"!][!//      

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($CDD_MCEM_AR_RELEASE_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release major version number of the Basic Software Module Description file (Mcem.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (CDD_Mcem_PBfg.c version [!"num:i($CDD_MCEM_AR_RELEASE_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($CDD_MCEM_AR_RELEASE_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Mcem.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (CDD_Mcem_PBCfg.c version [!"num:i($CDD_MCEM_AR_RELEASE_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($CDD_MCEM_AR_RELEASE_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Mcem.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (CDD_Mcem_PBCfg.c version [!"num:i($CDD_MCEM_AR_RELEASE_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMajorVersion) = num:i($CDD_MCEM_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Mcem.epd version [!"SwMajorVersion"!]) and the Code template file (CDD_Mcem_PBCfg.c version [!"num:i($CDD_MCEM_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwMinorVersion) = num:i($CDD_MCEM_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Mcem.epd version [!"SwMinorVersion"!]) and the Code template file (CDD_Mcem_PBCfg.c version [!"num:i($CDD_MCEM_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!IF "not(num:i(SwPatchVersion) = num:i($CDD_MCEM_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Mcem.epd version [!"SwPatchVersion"!]) and the Code template file (CDD_Mcem_PBCfg.c version [!"num:i($CDD_MCEM_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF

[!ENDNOCODE!][!//
