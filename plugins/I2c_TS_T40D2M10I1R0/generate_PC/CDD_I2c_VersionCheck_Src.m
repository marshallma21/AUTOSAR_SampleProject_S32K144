[!NOCODE!][!//
/**
  @file    CDD_I2c_VersionCheck_Src.m
  @version 1.0.1

  @brief   AUTOSAR I2c - version check macro.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform ARM
  Peripheral LPI2C
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

[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('I2C_VERSION_CHECK_SRC_M'))"!][!//
[!VAR "I2C_VERSION_CHECK_SRC_M"="'true'"!][!//
    [!VAR "I2cArMajorVersionTemplate"="4"!][!//
    [!VAR "I2cArMinorVersionTemplate"="2"!][!//
    [!VAR "I2cArPatchVersionTemplate"="2"!][!//
    [!VAR "I2cSwMajorVersionTemplate"="1"!][!//     
    [!VAR "I2cSwMinorVersionTemplate"="0"!][!//     

    [!SELECT "CommonPublishedInformation"!][!//
    [!/*
    [!IF "not(num:i(ArMajorVersion) = num:i($I2cArMajorVersionTemplate))"!]
        [!ERROR!]
            "AUTOSAR major version number of the Basic Software Module Description file (I2c.epd version [!"ArMajorVersion"!]) and the Code template file (CDD_I2c_Cfg.c version [!"num:i($I2cArMajorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(ArMinorVersion)  = num:i($I2cArMinorVersionTemplate))"!]
        [!ERROR!]
            "AUTOSAR minor version number of the Basic Software Module Description file (I2c.epd version [!"ArMinorVersion"!]) and the Code template file (CDD_I2c_Cfg.c version [!"num:i($I2cArMinorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(ArPatchVersion)  = num:i($I2cArPatchVersionTemplate))"!]
        [!ERROR!]
            "AUTOSAR patch version number of the Basic Software Module Description file (I2c.epd version [!"ArPatchVersion"!]) and the Code template file (CDD_I2c_Cfg.c version [!"num:i($I2cArPatchVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    */!]
    [!IF "not(num:i(SwMajorVersion) = num:i($I2cSwMajorVersionTemplate))"!]
        [!ERROR!]
            "The software major number of the Basic Software Module Description file (I2c.epd version [!"SwMajorVersion"!]) and the Code template file (CDD_I2c_Cfg.c version [!"num:i($I2cSwMajorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!IF "not(num:i(SwMinorVersion) = num:i($I2cSwMinorVersionTemplate))"!]
        [!ERROR!]
            "The software minor number of the Basic Software Module Description file (I2c.epd version [!"SwMinorVersion"!]) and the Code template file (CDD_I2c_Cfg.c version [!"num:i($I2cSwMinorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!][!//
    [!ENDSELECT!][!//
[!ENDIF!][!// avoid multiple inclusion ENDIF
[!ENDNOCODE!][!//
