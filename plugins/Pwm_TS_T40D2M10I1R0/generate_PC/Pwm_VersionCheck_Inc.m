[!NOCODE!][!//

/*!
*   @file    Pwm_VersionCheck_Inc.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm macro to check for notification config, variant post-build
*   @details    macro to check for notification config, variant pre-compile
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*!==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
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
[!ENDNOCODE!][!//


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('PWM_VERSION_CHECK_INC_M'))"!]
[!VAR "PWM_VERSION_CHECK_INC_M"="'true'"!]


[!VAR "PWM_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
[!VAR "PWM_AR_MINOR_VERSION_TEMPLATE"="2"!][!//
[!VAR "PWM_AR_REVISION_VERSION_TEMPLATE"="2"!][!//
[!VAR "PWM_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
[!VAR "PWM_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
[!VAR "PWM_SW_PATCH_VERSION_TEMPLATE"="1"!][!//

[!SELECT "CommonPublishedInformation"!][!//
[!IF "not(num:i(ArReleaseMajorVersion) = num:i($PWM_AR_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR major version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseMajorVersion"!]) and the Code template file (Pwm_Cfg.h version [!"num:i($PWM_AR_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseMinorVersion) = num:i($PWM_AR_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release minor version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseMinorVersion"!]) and the Code template files (Pwm_Cfg.h version [!"num:i($PWM_AR_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(ArReleaseRevisionVersion) = num:i($PWM_AR_REVISION_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "AUTOSAR release revision version number of the Basic Software Module Description file (Pwm.epd version [!"ArReleaseRevisionVersion"!]) and the Code template files (Pwm_Cfg.h version [!"num:i($PWM_AR_REVISION_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMajorVersion) = num:i($PWM_SW_MAJOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software major number of the Basic Software Module Description file (Pwm.epd version [!"SwMajorVersion"!]) and the Code template files (Pwm_Cfg.h version [!"num:i($PWM_SW_MAJOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwMinorVersion) = num:i($PWM_SW_MINOR_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software minor number of the Basic Software Module Description file (Pwm.epd version [!"SwMinorVersion"!]) and the Code template files (Pwm_Cfg.h version [!"num:i($PWM_SW_MINOR_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!][!//
[!IF "not(num:i(SwPatchVersion) = num:i($PWM_SW_PATCH_VERSION_TEMPLATE))"!]
    [!ERROR!]
        "The software patch number of the Basic Software Module Description file (Pwm.epd version [!"SwPatchVersion"!]) and the Code template files (Pwm_Cfg.h version [!"num:i($PWM_SW_PATCH_VERSION_TEMPLATE)"!]) are different"
    [!ENDERROR!]
[!ENDIF!]


[!ENDSELECT!][!//
[!NOCODE!][!//
[!ENDNOCODE!][!//


[!ENDIF!][!// avoid multiple inclusion ENDIF

