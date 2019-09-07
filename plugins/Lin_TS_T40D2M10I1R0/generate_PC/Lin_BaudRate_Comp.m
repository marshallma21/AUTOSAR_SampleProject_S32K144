[!/*
    @file    Lin_BaudRate_Comp.m
    @version 1.0.1

    @brief   AUTOSAR Lin - Baud rate computation for Lin_Cfg.c, Lin_PBcfg.c.
    @details Baud rate computation for Lin_Cfg.c, Lin_PBcfg.c
    
    Project AUTOSAR 4.2 MCAL
    Patform ARM
    Peripheral LPUART
    Dependencies 
    
    ARVersion 4.2.2
    ARRevision ASR_REL_4_2_REV_0002
    ARConfVariant
    SWVersion 1.0.1
    BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713

    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
    All Rights Reserved.
*/!]
[!/*==================================================================================================
==================================================================================================
*/!]
[!VAR "ClockFrequencyFromMcu" = "McuClockReferencePointFrequency"!]
    [!VAR "CTRL_SBR" = "($ClockFrequencyFromMcu div ($linBaudrate * 16))"!][//
    [!VAR "CTRL_SBR" = "num:inttohex($CTRL_SBR)"!][!//
