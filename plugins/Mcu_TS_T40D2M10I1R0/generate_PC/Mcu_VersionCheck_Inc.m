[!NOCODE!][!//
/**
  @file    Mcu_VersionCheck_Inc.m
  @version 1.0.1

  @brief   AUTOSAR Mcu - version check macro.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform ARM
  Peripheral MC
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.1
  BuildVersion S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/
[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('MCU_VERSION_CHECK_INC_M'))"!]
[!VAR "MCU_VERSION_CHECK_INC_M"="'true'"!]

[!VAR "McuArReleaseMajorVersionTemplate"="4"!][!//
[!VAR "McuArReleaseMinorVersionTemplate"="2"!][!//
[!VAR "McuArReleaseRevisionVersionTemplate"="2"!][!//
[!VAR "McuSwMajorVersionTemplate"="1"!][!//
[!VAR "McuSwMinorVersionTemplate"="0"!][!//
[!VAR "McuSwPatchVersionTemplate"="1"!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($McuArReleaseMajorVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Mcu.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Mcu_Cfg.h version [!"num:i($McuArReleaseMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseMinorVersion)  = num:i($McuArReleaseMinorVersionTemplate))"!]
     [!ERROR!]
        "AUTOSAR minor version number of the Basic Software Module Description file (Mcu.epd version [!"ArReleaseMinorVersion"!]) and the Code template file (Mcu_Cfg.h version [!"num:i($McuArReleaseMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseRevisionVersion)  = num:i($McuArReleaseRevisionVersionTemplate))"!]
    [!ERROR!]
        "AUTOSAR revision version number of the Basic Software Module Description file (Mcu.epd version [!"ArReleaseRevisionVersion"!]) and the Code template file (Mcu_Cfg.h version [!"num:i($McuArReleaseRevisionVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//

[!IF "not(num:i(SwMajorVersion) = num:i($McuSwMajorVersionTemplate))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Mcu.epd version [!"SwMajorVersion"!]) and the Code template file (Mcu_Cfg.h version [!"num:i($McuSwMajorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($McuSwMinorVersionTemplate))"!]
    [!ERROR!]   
        "The software minor number of the Basic Software Module Description file (Mcu.epd version [!"SwMinorVersion"!]) and the Code template file (Mcu_Cfg.h version [!"num:i($McuSwMinorVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwPatchVersion) = num:i($McuSwPatchVersionTemplate))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Mcu.epd version [!"SwPatchVersion"!]) and the Code template file (Mcu_Cfg.h version [!"num:i($McuSwPatchVersionTemplate)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]
[!ENDSELECT!][!//

[!ENDIF!][!// avoid multiple inclusion ENDIF

[!ENDNOCODE!][!//
