[!NOCODE!]
/**
*   @file    Can_SourceClock.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - version check macro.
*   @details Extract source clock from MCU plugin.
*
*   @addtogroup [CAN]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FLEXCAN
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
[!ENDNOCODE!]
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('CAN_SOURCECLOCK_M'))"!]
[!VAR "CAN_SOURCECLOCK_M"="'true'"!]
[!MACRO "CanClockFrequency_M"!]

    [!/* Use the Reference of MCU from CAN module and calculate CAN clock Frequency for any late useless. 
         The scope is to calculate the <<OutCanClockFrequencyFromMcu>> valiable from below (in Hz). */!]
    [!SELECT "node:ref(../../CanCpuClockRef)"!][!/* Switch to MCU model to obtain clock source - MCU is refered by CAN module! */!]
        [!/* If the McuClockReferencePointFrequency value is zero, the clock configured in "GeneralClockSettings/SystemClockSelect" will be the 
            system clock and the respective container parameters will be used. */!]
        [!VAR "OutCanClockFrequencyFromMcu" = "McuClockReferencePointFrequency"!]

    [!ENDSELECT!]

    [!IF "node:exists(./../../../../../CanGeneral/CanEnableDualClockMode)"!][!IF "./../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
        [!IF "node:exists(../../CanCpuClockRef_Alternate)"!]
            [!SELECT "node:ref(../../CanCpuClockRef_Alternate)"!][!/* Switch to MCU model to obtain clock source - MCU is refered by CAN module! */!]
            [!/* If the McuClockReferencePointFrequency value is zero, the clock configured in "GeneralClockSettings/SystemClockSelect" will be the 
                system clock and the respective container parameters will be used. */!]
            [!VAR "OutCanClockFrequencyFromMcu_Alternate" = "McuClockReferencePointFrequency"!]
            
            [!ENDSELECT!]
        [!ENDIF!]
    [!ENDIF!][!ENDIF!]
[!ENDMACRO!]

    
[!ENDIF!]
[!NOCODE!]
/** @} */
[!ENDNOCODE!]
