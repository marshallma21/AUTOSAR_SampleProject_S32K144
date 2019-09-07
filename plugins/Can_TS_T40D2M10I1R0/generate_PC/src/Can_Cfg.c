/**
*   @file    Can_Cfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PreCompile.
*
*   @addtogroup CAN_DRIVER
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Can_Cfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Cfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Cfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_Cfg_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Cfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_IPW.h"

/**
* @file           Can_Cfg.c
*/

[!AUTOSPACING!]
[!NOCODE!][!//
/*
 Example 1 of valid configuration:
   Source Clock = 8MHz, Bit Rate = 1Mb/sec,
   CanControllerTimeQuanta  = 125ns
      -> Presclaer = 1, CanBit = 8Tq (these ale calculated in background)
   CanControllerPropSeg  = 3, CanControllerSeg1 = 0, CanControllerSeg2 = 1, CanControllerSyncJumpWidth = 0.

 Example 2 of valid configuration:
   Source Clock = 8MHz, Bit Rate = 125Kb/sec,
   CanControllerTimeQuanta  = 1000ns
      -> Presclaer = 8, CanBit = 8Tq (these ale calculated in background)
   CanControllerPropSeg  = 0, CanControllerSeg1 = 2, CanControllerSeg2 = 2, CanControllerSyncJumpWidth = 2.
*/
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!INCLUDE "Can_VersionCheck_Src.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CAN_VENDOR_ID_PCCFG_C                   43
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C     4
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C     2
/* @violates @ref Can_Cfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C  2
#define CAN_SW_MAJOR_VERSION_PCCFG_C             1
#define CAN_SW_MINOR_VERSION_PCCFG_C             0
#define CAN_SW_PATCH_VERSION_PCCFG_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_PCCFG_C != CAN_VENDOR_ID)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_Cfg.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_Cfg.c and Can.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_PCCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PCCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_Cfg.c and Can.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PCCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PCCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PCCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_Cfg.c and Can.h are different"
#endif


/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_Cfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

/**
* @brief    Prototype of User Notifications
*/
[!NOCODE!][!INCLUDE "Can_NotifyCheck_Src.m"!][!ENDNOCODE!][!//
[!NOCODE!][!INCLUDE "Can_SourceClock.m"!][!ENDNOCODE!][!//
[!NOCODE!][!CALL "CanRxFifoWarningNotification_PC"!][!ENDNOCODE!][!//
[!NOCODE!][!CALL "CanRxFifoOverflowNotification_PC"!][!ENDNOCODE!][!//
[!NOCODE!][!CALL "CanErrorControllerNotification_PC"!][!ENDNOCODE!][!//

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
[!NOCODE!] [!/* This section is for global variables, local to this file */!]
    [!VAR "Tsyncsegment"="1"!][!/* Sync_seg has 1 Tq length */!]
    [!/*
    Sync-seg = is the segment that is used to synchronise the nodes on the bus. A bit edge (if there is a data change) is expected during this segment.
    Prop-Seg = is a period of time that is used to compensate for physical delay times within the network.
    Phase-seg1 = is a buffer segment that may be lengthened during resynchronisation to compensate for oscillator drift and positive phase differences between the oscillators of the transmitting and receiving node(s).
    Phase-seg2 = is a buffer segment that may be shortened during resynchronisation (described below) to compensate for negative phase errors and oscillator drift.

    The Sample point is always at the end of Phase-seg1 and is the time at which the bus level is read and interpreted as the value of the current bit.
    Whether transmitting or receiving, all nodes on a single CAN bus must have the same nominal bit time. Bit time is programmable at each node on a CAN Bus and is a function
        of the period of the oscillator local to each node, the value that is user-programmed into a Baud Rate Prescaler (BRP) register in the controller at each node, and the programmed number of time quanta per bit.
    When any node receives a data frame or a remote frame, it is necessary for the receiver to synchronise with the transmitter.
        1. The first is hard synchronisation and occurs at Start-of-Frame (SOF).
        2. For subsequent bits in any received frame, if a bit edge does not occur in the Sync-seg segment of bit time, resynchronisation is automatically invoked and will shorten or lengthen the current bit time depending
            on where the edge occurs. The maximum amount by which the bit time is lengthened or shortened is determined by a user-programmable number of time quanta known as the Synchronisation Jump Width (SJW).
    */!]
[!ENDNOCODE!]

[!IF "(CanGeneral/CanPublicIcomSupport  = 'true') and (ecu:get('Can.CanConfigSet.CanPretendedNetworking')='STD_ON')"!]
    [!INDENT "0"!]
    /*==================================================================================================*/
    /**
    * @brief          Information about Pretended Networking
    * @details        All information about Pretended Networking
    *
    */
    /*==========================================generation of CanIcomRxMessageSignalConfig structures====================================================*/
    [!SELECT "CanConfigSet"!]
        [!VAR "CNT_ICOM_CONFIG_COUNTER" = "0"!]    
        [!LOOP "CanIcom/CanIcomConfig/*"!] 
            [!VAR "CNT_ICOM_RX_MESSAGE" = "0"!]
            [!LOOP "CanIcomWakeupCauses/CanIcomRxMessage/*"!] 
                [!VAR "CNT_ICOM_RX_SIGNAL_MESSAGE1" = "0"!]
                [!LOOP "CanIcomRxMessageSignalConfig/*"!]
                    [!VAR "CNT_ICOM_RX_SIGNAL_MESSAGE1" = "$CNT_ICOM_RX_SIGNAL_MESSAGE1+1"!]
                [!ENDLOOP!]
                [!IF "CanPayloadFilter = 'true'"!]
                    [!VAR "CNT_ICOM_RX_SIGNAL_MESSAGE" = "0"!]
                    static CONST(Can_IcomRxMessageSignalType, CAN_CONST) Can_PnConfig_[!"num:i($CNT_ICOM_CONFIG_COUNTER)"!]_Rx[!"num:i($CNT_ICOM_RX_MESSAGE)"!]_Signal[[!"num:i($CNT_ICOM_RX_SIGNAL_MESSAGE1)"!]] =
                    {
                        [!INDENT "4"!]
                        [!VAR "CNT_ICOM_RX_MESSAGE" = "$CNT_ICOM_RX_MESSAGE+1"!]
                        [!LOOP "CanIcomRxMessageSignalConfig/*"!] 
                            {
                                [!INDENT "8"!]
                                    (uint32)[!"num:inttohex(bit:shr(num:i(node:value(CanIcomSignalMask)), 32), 8)"!]U,    /* CanIcomSignalMaskLow */
                                    (uint32)[!"num:inttohex(node:value(CanIcomSignalMask), 8)"!]U,    /* CanIcomSignalMaskHigh */
                                    [!"node:value(CanIcomSignalOperation)"!],   /*CanIcomSignalOperation */
                                    (uint32)[!"num:inttohex(bit:shr(num:i(node:value(CanIcomSignalValue)), 32), 8)"!]U,    /* CanIcomSignalValueLow */
                                    (uint32)[!"num:inttohex(node:value(CanIcomSignalValue), 8)"!]U,    /* CanIcomSignalValueHigh */
                                /*DLCLowValue */
                                [!IF "../../CanIcomPayloadLengthError='false'"!]
                                    [!"node:value(DLCLowValue)"!]U,
                                [!ELSE!]
                                    0U ,
                                [!ENDIF!]
                                /*DLCHighValue */
                                [!IF "../../CanIcomPayloadLengthError='false'"!]
                                    [!"node:value(DLCHighValue)"!]U,
                                [!ELSE!]    
                                    8U ,
                                [!ENDIF!]
                                /*CanIcomSignalRef */
                                [!IF "node:exists(CanIcomSignalRef)"!]
                                    1  /*  [!"node:value(CanIcomSignalRef)"!]*/ /*reference it is not availabel for now. It may be referenced from an upper layer*/
                                [!ELSE!]    
                                    0U
                                [!ENDIF!]
                                [!ENDINDENT!]
                            }[!VAR "CNT_ICOM_RX_SIGNAL_MESSAGE" = "$CNT_ICOM_RX_SIGNAL_MESSAGE+1"!][!IF "$CNT_ICOM_RX_SIGNAL_MESSAGE1>1"!],[!ENDIF!][!CR!]
                        [!ENDLOOP!]
                        [!ENDINDENT!]
                    };
                    [!CR!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!VAR "CNT_ICOM_CONFIG_COUNTER" = "$CNT_ICOM_CONFIG_COUNTER+1"!]
        [!ENDLOOP!]
    [!ENDSELECT!]
    /*============================================================================================================*/
    /*====================================generation of CanIcomRxMessage==========================================*/
    [!SELECT "CanConfigSet"!]
        [!VAR "CNT_ICOM_CONFIG_COUNTER" = "0"!]    
        [!LOOP "CanIcom/CanIcomConfig/*"!] 
            [!VAR "CNT_ICOM_RX_MESSAGE1" = "0"!]    
            [!LOOP "CanIcomWakeupCauses/CanIcomRxMessage/*"!]
                [!VAR "CNT_ICOM_RX_MESSAGE1" = "$CNT_ICOM_RX_MESSAGE1+1"!]
            [!ENDLOOP!]
            [!VAR "CNT_ICOM_RX_MESSAGE" = "0"!]
            static CONST(Can_IcomRxMessageConfigsType, CAN_CONST) Can_PnConfig_[!"num:i($CNT_ICOM_CONFIG_COUNTER)"!]_Rx[[!"num:i($CNT_ICOM_RX_MESSAGE1)"!]]=
            {
                [!INDENT "4"!]
                [!LOOP "CanIcomWakeupCauses/CanIcomRxMessage/*"!] 
                    {
                        [!INDENT "8"!]
                        [!VAR "CNT_ICOM_RX_SIGNAL_MESSAGE1" = "0"!]
                        [!LOOP "CanIcomRxMessageSignalConfig/*"!]
                            [!VAR "CNT_ICOM_RX_SIGNAL_MESSAGE1" = "$CNT_ICOM_RX_SIGNAL_MESSAGE1+1"!]
                        [!ENDLOOP!]
                        /*value for node CanIcomCounterValue */
                        [!IF "node:exists(CanIcomCounterValue)"!]
                            [!"node:value(CanIcomCounterValue)"!]U,
                        [!ELSE!]
                            0U ,
                        [!ENDIF!]
                        /*value for node CanIcomMessageId*/
                        [!IF "node:exists(CanIcomMessageId)"!]
                            [!"node:value(CanIcomMessageId)"!]U,
                        [!ELSE!]
                            0U ,
                        [!ENDIF!]
                        /*value for node CanIcomMessageIdMask*/
                        [!IF "node:exists(CanIcomMessageIdMask)"!]
                            [!"node:value(CanIcomMessageIdMask)"!]U,
                        [!ELSE!]
                            0U ,
                        [!ENDIF!]
                        /*value for node CanIcomMissingMessageTimerValue*/
                        [!IF "node:exists(CanIcomMissingMessageTimerValue)"!]
                            [!"num:i(node:value(CanIcomMissingMessageTimerValue))"!]U,
                        [!ELSE!]
                            0U ,
                        [!ENDIF!]
                        /* Type of ID filtering */
                        [!IF "node:exists(CanIcomIdOperation)"!]
                            [!"node:value(CanIcomIdOperation)"!],
                        [!ELSE!]    
                            0U ,
                        [!ENDIF!]
                        /*total number of CanIcomRxSignalMessage defined structures - u8NumCanIcomRxMessageSignal*/
                        (uint8)[!"num:i($CNT_ICOM_RX_SIGNAL_MESSAGE1)"!]U,
                        /* Select filter payload or not*/
                        [!IF "CanPayloadFilter='true'"!]
                            (boolean)TRUE,
                        [!ELSE!]
                            (boolean)FALSE,
                        [!ENDIF!]
                        /*pCanIcomRxMessageSignalConfigs*/
                        [!IF "CanPayloadFilter = 'true'"!]
                            &Can_PnConfig_[!"num:i($CNT_ICOM_CONFIG_COUNTER)"!]_Rx[!"num:i($CNT_ICOM_RX_MESSAGE)"!]_Signal[0U]
                        [!ELSE!]
                            NULL_PTR
                        [!ENDIF!]
                        [!VAR "CNT_ICOM_RX_MESSAGE" = "$CNT_ICOM_RX_MESSAGE+1"!]            
                        [!ENDINDENT!]
                    }[!IF "$CNT_ICOM_RX_MESSAGE1>1"!] ,[!ENDIF!][!CR!]
                [!ENDLOOP!]
                [!ENDINDENT!]
            };
            [!CR!]
            [!VAR "CNT_ICOM_CONFIG_COUNTER" = "$CNT_ICOM_CONFIG_COUNTER+1"!]
        [!ENDLOOP!]  
    [!ENDSELECT!]
    /*==================================================================*/
    /*==============================generation of CanIcomConfig=========*/
    [!SELECT "CanConfigSet"!]
        [!VAR "CNT_ICOM_CONFIG_COUNTER1" = "0"!]    
        [!LOOP "CanIcom/CanIcomConfig/*"!]
            [!VAR "CNT_ICOM_CONFIG_COUNTER1" = "$CNT_ICOM_CONFIG_COUNTER1+1"!]
        [!ENDLOOP!]    
        [!VAR "CNT_ICOM_CONFIG_COUNTER" = "0"!]    
        static CONST(Can_IcomConfigsType, CAN_CONST) Can_PnConfig[[!"num:i($CNT_ICOM_CONFIG_COUNTER1)"!]] = 
        {
            [!INDENT "4"!]
            [!LOOP "CanIcom/CanIcomConfig/*"!] 
                {
                    [!INDENT "4"!]
                    /*value for node CanIcomConfigId */
                    (uint8)[!"node:value(CanIcomConfigId)"!]U,
                    /*value for node CanIcomWakeOnBusOff*/
                    [!IF "node:value(CanIcomWakeOnBusOff)='true'"!]
                        (boolean)TRUE,
                    [!ELSE!]
                        (boolean)FALSE,
                    [!ENDIF!]
                    /*u8NumberCanIcomRxMessage */
                    [!VAR "COUNT_ICOM_RX_MSG"="0"!]
                    [!LOOP "CanIcomWakeupCauses/CanIcomRxMessage/*"!]
                        [!VAR "COUNT_ICOM_RX_MSG"="$COUNT_ICOM_RX_MSG+1"!] 
                    [!ENDLOOP!]
                    (uint8)[!"num:i($COUNT_ICOM_RX_MSG)"!]U,
                    /*pCanIcomRxMessageConfigs*/
                    &Can_PnConfig_[!"num:i($CNT_ICOM_CONFIG_COUNTER)"!]_Rx[0U]
                    [!ENDINDENT!]
                }[!VAR "CNT_ICOM_CONFIG_COUNTER" = "$CNT_ICOM_CONFIG_COUNTER+1"!][!IF "$CNT_ICOM_CONFIG_COUNTER1>1"!] ,[!ENDIF!][!CR!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };
    [!ENDSELECT!]
    [!ENDINDENT!]
[!ENDIF!]

/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
*/
[!VAR "LoopVar"="0"!]
[!SELECT "CanConfigSet"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    [!LOOP "CanController/*"!]
        [!VAR "MASK_COUNT2"="num:i(count(CanControllerBaudrateConfig/*))"!]
        [!VAR "END_COMMA2"="0"!]
        [!INDENT "0"!]
        /* Compiler_Warning: this warning due to behavior of compiler depend on configs. */
        static CONST(CanStatic_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateCfgSet[!"$CSET_NR"!]_PC_[!"CanControllerId"!][CAN_CFGSET[!"num:i($CSET_NR)"!]_MAX_BAUDRATE_FC_[!"substring-after(CanHwChannel,'FlexCAN_')"!]_[!"@index"!]] = 
        {
            [!INDENT "4"!]
            [!LOOP "CanControllerBaudrateConfig/*"!][!VAR "END_COMMA2"="$END_COMMA2 + 1"!]
                [!IF "../../CanControllerActivation = 'true'"!]
                    /* Configuration for CanController ID[!"../../CanControllerId"!] == [!"../../CanHwChannel"!] */
                    {
                        [!INDENT "8"!]
                        /* ===== Control Register - CTRL ===== */
                        (uint32)(
                                    [!INDENT "20"!]
                                    /* CTRL[LPB] - Loop-back mode */
                                    ([!IF "../../CanLoopBackMode = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_LPB_SHIFT_U8) |
                                    /* CTRL[SMP] - Sampling mode */
                                    ([!IF "../../CanTrippleSamplingEnable = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_SMP_SHIFT_U8) |
                                    /* CTRL[BOFF_REC] - Bus off recovery */
                                    ([!IF "../../CanAutoBusOffRecovery = 'true'"!](uint32)0[!ELSE!](uint32)1[!ENDIF!] << FLEXCAN_CTRL_BOFFREC_SHIFT_U8) |
                                    /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                                    ([!IF "../../CanLowestBuffTransmitFirst = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_LBUF_SHIFT_U8) |
                                    /* CTRL[LOM] - Listen only mode */
                                    ([!IF "../../CanListenOnlyMode = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_LOM_SHIFT_U8)
                                    [!ENDINDENT!]
                        [!WS "9"!]) 
                        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
                        [!IF "../../CanClockFromBus = 'true'"!]
                            [!IF "../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
                                /* ===== Control Register Alternate - CTRL ===== */
                                /* CTRL[LPB] - Loop-back mode */
                                ,(uint32)(
                                            [!INDENT "20"!]
                                            ([!IF "../../CanLoopBackMode = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_LPB_SHIFT_U8) |
                                            /* CTRL[SMP] - Sampling mode */
                                            ([!IF "../../CanTrippleSamplingEnable = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_SMP_SHIFT_U8) |
                                            /* CTRL[BOFF_REC] - Bus off recovery */
                                            ([!IF "../../CanAutoBusOffRecovery = 'true'"!](uint32)0[!ELSE!](uint32)1[!ENDIF!] << FLEXCAN_CTRL_BOFFREC_SHIFT_U8) |
                                            /* CTRL[LBUF] - Lowest Buffer Transmitted First */
                                            ([!IF "../../CanLowestBuffTransmitFirst = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_LBUF_SHIFT_U8) |
                                            /* CTRL[LOM] - Listen only mode */
                                            ([!IF "../../CanListenOnlyMode = 'true'"!](uint32)1[!ELSE!](uint32)0[!ENDIF!] << FLEXCAN_CTRL_LOM_SHIFT_U8)
                                            [!ENDINDENT!]
                                [!WS "9"!])
                            [!ELSE!]    
                                ,0U
                            [!ENDIF!]
                        [!ELSE!]    
                            ,0U
                        [!ENDIF!]
                        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
                        [!ENDINDENT!]
                    }[!IF "$END_COMMA2 < $MASK_COUNT2"!],[!ENDIF!]
                    [!CR!] 
                [!ELSE!]
                    {
                        [!INDENT "8"!]
                        /* [!"../../CanHwChannel"!] ControlRegister Default Configuration: 125 Kbps BaudRate with Oscillator clock 8MHz as Clock source and TimeQuantum of 1000ns. */
                        /* ===== Control Register - CTRL ===== */
                        (uint32)(
                                    [!INDENT "20"!]
                                    /* CTRL[LPB] - Loop-back mode */
                                    ((uint32)0 << FLEXCAN_CTRL_LPB_SHIFT_U8) |
                                    /* CTRL[SMP] - Sampling mode */
                                    ((uint32)0 << FLEXCAN_CTRL_SMP_SHIFT_U8) |
                                    /* CTRL[BOFF_REC] - Bus off recovery */
                                    ((uint32)1 << FLEXCAN_CTRL_BOFFREC_SHIFT_U8) |
                                    /* CTRL[LBUF]  - Lowest Buffer Transmitted First */
                                    ((uint32)0 << FLEXCAN_CTRL_LBUF_SHIFT_U8) |
                                    /* CTRL[LOM] - Listen only mode */
                                    ((uint32)0 << FLEXCAN_CTRL_LOM_SHIFT_U8)
                                    [!ENDINDENT!]
                        [!WS "9"!])
                        #if (CAN_DUAL_CLOCK_MODE == STD_ON)
                        /* ===== Control Register Alternate - CTRL ===== */
                        ,(uint32)(
                                    [!INDENT "20"!]
                                    /* CTRL[LPB] - Loop-back mode */
                                    ((uint32)0 << FLEXCAN_CTRL_LPB_SHIFT_U8) |
                                    /* CTRL[SMP] - Sampling mode */
                                    ((uint32)0 << FLEXCAN_CTRL_SMP_SHIFT_U8) |
                                    /* CTRL[BOFF_REC] - Bus off recovery */
                                    ((uint32)1 << FLEXCAN_CTRL_BOFFREC_SHIFT_U8) |
                                    /* CTRL[LBUF]  - Lowest Buffer Transmitted First */
                                    ((uint32)0 << FLEXCAN_CTRL_LBUF_SHIFT_U8) |
                                    /* CTRL[LOM] - Listen only mode */
                                    ((uint32)0 << FLEXCAN_CTRL_LOM_SHIFT_U8)
                                    [!ENDINDENT!]
                        [!WS "9"!])
                        #endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
                        [!ENDINDENT!]
                    }[!IF "$END_COMMA2 < $MASK_COUNT2"!],[!ENDIF!][!CR!]
                    [!CR!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!ENDINDENT!]
        };
        [!CR!]
        [!ENDINDENT!]
    [!ENDLOOP!]
[!ENDSELECT!]

/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
*/
[!VAR "LoopVar"="0"!]
[!SELECT "CanConfigSet"!]
    [!INDENT "0"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    static CONST(CanStatic_ControlerDescriptorType, CAN_CONST) ControlerDescriptors[!"$CSET_NR"!]_PC[CAN_MAXCONTROLLERCOUNT_[!"$CSET_NR"!]] =
    {
        [!INDENT "4"!]
        [!VAR "MASK_COUNT4"="num:i(count(CanController/*))"!]
        [!VAR "END_COMMA4"="0"!]
        [!VAR "tableidcount" = "0"!]
        [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!]
            /* ControlerDescriptor of CanController_[!"node:value(CanControllerId)"!] */
            {
                [!INDENT "8"!]
                [!IF "CanControllerActivation = 'true'"!]
                    /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
                    [!IF "CanControllerActivation = 'true'"!]
                        (uint8)FLEXCAN_[!"substring-after(CanHwChannel,'FlexCAN_')"!]_OFFSET,
                    [!ELSE!]
                        (uint8)FLEXCAN_NULL_OFFSET_U8,
                    [!ENDIF!]

                    /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
                    ControllerBaudrateCfgSet[!"$CSET_NR"!]_PC_[!"CanControllerId"!],

                    #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
                    /* Pointer to Error INTERRUPT notification function (ESR[ERR_INT]). - Can_ErrorNotification */
                    [!IF "(CanErrorControllerNotifEn = 'true') and (normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
                        &[!"normalize-space(CanErrorControllerNotification)"!],
                    [!ELSE!]
                        NULL_PTR,
                    [!ENDIF!]  
                    #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
                    
                    /* Pointer to Error INTERRUPT notification function (ESR[ERR_INT]). */
                    [!IF "(CanErrorControllerNotifEn = 'true') and (normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
                        &[!"normalize-space(CanErrorControllerNotification)"!],
                    [!ELSE!]
                        NULL_PTR,
                    [!ENDIF!]  
                    #endif

                    /* Maximum MBs supported for this controller. - u8NumberOfMB */
                    (uint8)[!"normalize-space(ecu:get(concat('Can.CanConfigSet.',CanHwChannel)))"!]U,
                    
                    [!IF "(node:value(../../../CanGeneral/CanPublicIcomSupport)='true') and (ecu:get('Can.CanConfigSet.CanPretendedNetworking')='STD_ON')"!]
                    /* ===== Pretended Network Support ===== */
                    #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                      [!IF "CanControllerIcomSupported = 'true'"!]
                          (boolean)TRUE,
                      [!ELSE!]
                          (boolean)FALSE,
                      [!ENDIF!]
                    #endif
                    [!ENDIF!]
                    /* ===== Controller Options ===== */
                    (uint32)(
                                [!INDENT "20"!]
                                [!IF "CanRxProcessing = 'POLLING'"!]
                                    CAN_CONTROLLERCONFIG_RXPOL_EN_U32 | /* RxPoll Enabled */
                                [!ELSE!]
                                    /* Rx select by INTERRUPT */
                                [!ENDIF!]
                                [!IF "CanTxProcessing = 'POLLING'"!]
                                    CAN_CONTROLLERCONFIG_TXPOL_EN_U32 | /* TxPoll Enabled */
                                [!ELSE!]
                                    /* Tx select by INTERRUPT */
                                [!ENDIF!]
                                [!IF "CanBusoffProcessing = 'POLLING'"!]
                                    CAN_CONTROLLERCONFIG_BOPOL_EN_U32 | /* BusOffPoll Enabled */
                                [!ELSE!]
                                    /* BusOff select by INTERRUPT */
                                [!ENDIF!]
                                0U
                                [!ENDINDENT!]
                    [!WS "9"!])
                [!ELSE!]
                    /* Can Controller Offset on chip: Can_A=offset 0, Can_B=offset 1, .. -u8ControllerOffset */
                    (uint8)FLEXCAN_NULL_OFFSET_U8,
                    /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr */
                    ControllerBaudrateCfgSet[!"$CSET_NR"!]_PC_[!"CanControllerId"!],
                    #if ((CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) && (CPU_BYTE_ORDER==HIGH_BYTE_FIRST))
                    /* Pointer to Error INTERRUPT notification function (ESR[ERR_INT]). - Can_ErrorNotification */             
                    NULL_PTR,
                    #elif(CPU_BYTE_ORDER==LOW_BYTE_FIRST) /* (CAN_ERROR_NOTIFICATION_ENABLE == STD_ON) */
                    /* Pointer to Error INTERRUPT notification function (ESR[ERR_INT]). */
                    NULL_PTR,
                    #endif
                    /* Maximum MBs supported for this controller. - u8NumberOfMB */
                    (uint8)[!"normalize-space(ecu:get(concat('Can.CanConfigSet.',CanHwChannel)))"!]U,

                    [!IF "(node:value(../../../CanGeneral/CanPublicIcomSupport)='true') and (ecu:get('Can.CanConfigSet.CanPretendedNetworking')='STD_ON')"!]
                        #if (CAN_PUBLIC_ICOM_SUPPORT == STD_ON)
                            (boolean)FALSE,
                        #endif
                    [!ENDIF!]
                    /* ===== Controller Options ===== */
                    (uint32)(0U)
                [!ENDIF!]
                [!ENDINDENT!]
            }[!//
            [!VAR "END_COMMA4"="$END_COMMA4 + 1"!][!//
            [!IF "$END_COMMA4 < $MASK_COUNT4"!][!//
                , /* ControlerDescriptors CanController_[!"node:value(CanControllerId)"!] end */
            [!ENDIF!]
            [!CR!]
        [!ENDLOOP!]
        [!ENDINDENT!]
    };
    [!ENDINDENT!]
[!ENDSELECT!]
/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
[!VAR "LoopVar"="0"!]
[!SELECT "CanConfigSet"!]
    [!INDENT "0"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    /* @violates @ref Can_PBcfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10*/
    CONST(CanStatic_ConfigType, CAN_CONST) CanStatic_ConfigSet =
    {
        [!INDENT "4"!]
        /* Number of CAN controllers configured -u8ControllersConfigured*/
        (uint8) [!"num:i(count(CanController/*))"!]U,
        /* FlexCAN controller description - ControlerDescriptors*/
        ControlerDescriptors[!"$CSET_NR"!]_PC,
        [!VAR "Can_hardware_ob_id" = "0"!]
        [!LOOP "CanHardwareObject/*"!]
            [!IF "$Can_hardware_ob_id < CanObjectId"!]
                [!VAR "Can_hardware_ob_id" = "CanObjectId"!]
            [!ENDIF!]
        [!ENDLOOP!]
        /*Maximum Object IDs configured - u32CanMaxObjectId*/
        (uint32)[!"num:i($Can_hardware_ob_id + 1)"!]U
        [!IF "(../CanGeneral/CanPublicIcomSupport  = 'true') and (ecu:get('Can.CanConfigSet.CanPretendedNetworking')='STD_ON')"!]
            /*Number of CanIcomConfig: u8NumCanIcomConfigs */ 
            ,[!"num:i(count(CanIcom/CanIcomConfig/*))"!]U
            /*Pointer to CanIcomCofig - pCanIcomConfigs*/
            ,&Can_PnConfig[0U]
        [!ENDIF!]
        [!ENDINDENT!]
    };
    [!ENDINDENT!]
[!ENDSELECT!]

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*
@file  Can_PBcfg.c
@note  Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives. - See @ref Can_Cfg_c_REF_1
@note  Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h - See @ref Can_Cfg_c_REF_2
*/
#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_Cfg_c_REF_1 MISRA 2004  Rule 19.1, #include preceded by non preproc directives.*/
/* @violates @ref Can_Cfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
