[!NOCODE!]
/**
  @file    Can_NotifyCheck_Src_PB.m
  @version 1.0.1

  @brief   AUTOSAR Can - macros.
  @details Macros
  
  Project AUTOSAR 4.2 MCAL
  Platform ARM
  Peripheral FLEXCAN
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
/*==================================================================================================
==================================================================================================*/
[!ENDNOCODE!]


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('CAN_NOTIFY_CHECK_SRC_PB_M'))"!]
[!VAR "CAN_NOTIFY_CHECK_SRC_PB_M"="'true'"!]

[!NOCODE!]
[!MACRO "CanRxFifoWarningNotification_PB"!]
    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!LOOP "CanConfigSet/CanController/*"!]
         [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
        [!VAR "MacInnerLoopCounter" = "0"!]
        [!VAR "MacMatchcounter" = "0"!]
        [!IF "CanControllerRxFifoEnable = 'true'"!]
            [!VAR "MacNotification" = "CanRxFifoWarningNotification"!]
        [!ENDIF!]
        [!LOOP "../../CanController/*"!]
             [!IF "CanControllerRxFifoEnable = 'true'"!]
                [!IF "(normalize-space(CanRxFifoWarningNotification) != 'NULL_PTR')"!]
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                        [!IF "($MacNotification = CanRxFifoWarningNotification)"!]
                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$MacMatchcounter = 1"!][!CODE!]
            [!IF "CanControllerRxFifoEnable = 'true'"!]
/* @violates @ref Can_PBcfg_c_REF_6 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file  */
extern FUNC(void,CAN_CODE) [!"normalize-space(CanRxFifoWarningNotification)"!]( void);
            [!ENDIF!]
        [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
 [!ENDMACRO!]

[!MACRO "CanRxFifoOverflowNotification_PB"!]
    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!LOOP "CanConfigSet/CanController/*"!]
     
        [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
        [!VAR "MacInnerLoopCounter" = "0"!]
        [!VAR "MacMatchcounter" = "0"!]
        [!IF "CanControllerRxFifoEnable = 'true'"!]
            [!VAR "MacNotification" = "CanRxFifoOverflowNotification"!]
        [!ENDIF!]
        [!LOOP "../../CanController/*"!]
             [!IF "CanControllerRxFifoEnable = 'true'"!]
                [!IF "(normalize-space(CanRxFifoOverflowNotification) != 'NULL_PTR')"!]
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                        [!IF "($MacNotification = CanRxFifoOverflowNotification)"!]
                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$MacMatchcounter = 1"!][!CODE!]
            [!IF "CanControllerRxFifoEnable = 'true'"!]
/* @violates @ref Can_PBcfg_c_REF_6 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file  */
extern FUNC(void,CAN_CODE) [!"normalize-space(CanRxFifoOverflowNotification)"!]( void);
            [!ENDIF!]
        [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
 [!ENDMACRO!]

[!MACRO "CanErrorControllerNotification_PB"!]
    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!LOOP "CanConfigSet/CanController/*"!]
         [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
        [!VAR "MacInnerLoopCounter" = "0"!]
        [!VAR "MacMatchcounter" = "0"!]
        [!IF "CanErrorControllerNotifEn = 'true'"!]
            [!VAR "MacNotification" = "CanErrorControllerNotification"!]
        [!ENDIF!] 
        [!LOOP "../../CanController/*"!]
             [!IF "CanErrorControllerNotifEn = 'true'"!]
                [!IF "(normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                        [!IF "($MacNotification = CanErrorControllerNotification)"!]
                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$MacMatchcounter = 1"!]
            [!IF "CanErrorControllerNotifEn = 'true'"!][!CODE!]
/* @violates @ref Can_PBcfg_c_REF_6 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file  */
extern FUNC(void,CAN_CODE) [!"normalize-space(CanErrorControllerNotification)"!]( void);
            [!ENDCODE!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]
   [!ENDMACRO!]

[!ENDNOCODE!]
[!ENDIF!][!// avoid multiple inclusion ENDIF