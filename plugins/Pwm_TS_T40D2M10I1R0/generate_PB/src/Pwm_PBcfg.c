[!AUTOSPACING!]
[!CODE!]
/**
*   @file       Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @implements Pwm_PBcfg.c_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR Pwm - Pwm post-build configuration file.
*   @details    Post-build configuration structure instances.
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
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

[!NOCODE!][!//
[!INCLUDE "Pwm_VersionCheck_Src_PB.m"!][!//
[!ENDNOCODE!][!//


[!NOCODE!]

/* Variable storing number of Ftm Modules available on the current platform */
[!VAR "numFtmModules" = "ecu:get('Pwm.PwmChannelConfigSet.Num_Ftm_Hw_Modules')"!]

/* Macro used to generate the correspondence (translation) table between all Ftm available 
channels and the indexes of channels in the array of Pwm channels configured to use Ftm */
[!MACRO "GenerateFtmHwToLogicMap", "paramFtmModule"!]
  [!NOCODE!]
  [!VAR "OutVarHwToLogicArray" = "''"!]
  [!VAR "OutVarHwToLogicComment" = "''"!]
  /* Loop through all channels of Ftm module received as parameter */
  [!FOR "MacCurModChannel" = "0" TO "7"!]
    /* Limit max number of configured channels to 255 */
    [!VAR "MacVarChTranslationIndex" = "255"!] 
    /* Loop through all Pwm channels configured to use FlexPwm IP */
    [!LOOP "PwmChannel/*"!]
      [!IF "contains(PwmFtmChannel,'Ftm')"!]
      
        /* Build the comment for the current Module */
        [!VAR "OutVarHwToLogicComment" = "concat('/* Idx of channels 0-7 of Ftm Module ', num:i($paramFtmModule), ' in the array of logic Pwm channels */')"!]
        /* Get indexes of Ftm Module and Channel of current looped Pwm channel */
        [!VAR "MacFtmModule"  = "substring-after(node:ref(PwmFtmChannel)/../../FtmModule,'FTM_')"!]
        [!VAR "MacFtmChannel" = "substring-after(node:ref(PwmFtmChannel)/PwmFtmChannelId,'CH_')"!]
        /* Check the match with the module received as parameter */ 
        [!IF "$MacFtmModule = $paramFtmModule"!]        
          /* Check the match with the channel loop var */
          [!IF "num:i($MacFtmChannel) = $MacCurModChannel"!] 
            /* Keep the index of the channel in the array of configured Pwm channels */
            [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDIF!]
    [!ENDLOOP!]
    /* If no configured Pwm channel is using the current Ftm channel in Module  */
    [!IF "$MacVarChTranslationIndex = 255"!]
      [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Pwm_ChannelType)255')"!]
    [!ELSE!]
      [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, '(Pwm_ChannelType)', $MacVarChTranslationIndex)"!]
    [!ENDIF!]
    [!IF "$MacCurModChannel < 7"!]
      [!VAR "OutVarHwToLogicArray" = "concat($OutVarHwToLogicArray, ', ')"!]
    [!ENDIF!]
  [!ENDFOR!]
  [!ENDNOCODE!]
[!ENDMACRO!]



/* Below there are a couple of macros implementing methods for working with arrays 
   on top of strings. The arrays can store a variable number of integer entries,
   each integer being stored in decimal format using max 2 digits (0-99) */
[!MACRO "ArrayDeclare", "Size"!]
    [!VAR "OutMyArray" = "''"!]
    [!FOR "i" = "1" TO "$Size"!]
        [!VAR "OutMyArray" = "concat($OutMyArray, '00')"!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "ArraySetElement", "Index", "Value"!]
    [!IF "$Value < 10"!]
        [!VAR "MacSetElement" = "concat('0',string(num:i($Value)))"!]
    [!ELSE!] 
        [!VAR "MacSetElement" = "string(num:i($Value))"!]
    [!ENDIF!]  
    [!IF "$Index = 0"!]
        [!VAR "OutMyArray" = "concat($MacSetElement, substring($OutMyArray,3))"!]
    [!ELSE!] 
        [!VAR "OutMyArray" = "concat(substring($OutMyArray,1,$Index*2), $MacSetElement, substring($OutMyArray,$Index*2+3))"!]
    [!ENDIF!]
[!ENDMACRO!]

[!MACRO "ArrayGetElement", "Index"!]
    [!VAR "OutGetElement" = "number(substring($OutMyArray,$Index*2+1,2))"!]
[!ENDMACRO!]


[!MACRO "ValidatePwmConfiguration"!]
[!NOCODE!]
   
  /*check if PWM logical channels from one config set use references to FTM channels from the same config set*/  
  /*also check if the Channel ids must contain all the values 0 to N-1 (where N is the maximum number of channels in that config set) */
  /*NOTE: the order of the IDs is not important as long as all the values are present; e.g 0, 3, 2, 1 and 0, 1, 2, 3 are both possible solutions*/
[!SELECT "PwmChannelConfigSet"!]    
       [!VAR "SumOfChIds" = "0"!]
       [!VAR "ChanCount" = "count(PwmChannel/*)"!]            
       [!LOOP "PwmChannel/*"!]      
            [!VAR "ChannelName" = "node:name(.)"!]           
            [!VAR "ChannelId" = "PwmChannelId"!]
            [!IF "num:i($ChannelId) >= num:i($ChanCount)"!]    
            [!ERROR!] 
              "Channel [!"$ChannelName"!] Id of [!"$ChannelId"!] is out of range (max value should be: [!"num:i($ChanCount - 1)"!])."  
                [!ENDERROR!]  
            [!ENDIF!]
        [!ENDLOOP!]
  [!ENDSELECT!]
  
   
  
  /*Go through all FTM modules and check if the number of FTM channels is consistent with the configuration of the channels and module
  e.g. There should be maximum 8 independent channels configured, if there are channels that are configured as combined then for each pair of combined
  channels the maximum logical number of channels that can be defined for one module is decreasing by 2:
  e.g. we have 2 combined channels and 4 independent channels this means that 8 FTM hw channels were used but only 6 logical ftm containers are needed. */
  [!VAR "CountIndepChannels" = "0"!]
  [!VAR "CountCombinedChannels" = "0"!]
  [!VAR "MaxPossibleChannels" = "8"!]
  [!VAR "CalcSumofChannels" = "0"!]
  
  [!SELECT "PwmChannelConfigSet"!]
     [!VAR "CfgSetName" = "as:name(.)"!]
     
     [!VAR "CountIndepChannels" = "0"!]
     [!VAR "CountCombinedChannels" = "0"!]
     [!VAR "CalcSumofChannels" = "0"!]
             
     [!LOOP "./PwmFtmModule/*"!]
        [!VAR "ModuleName" = "node:name(.)"!]
        [!VAR "FtmName" = "FtmModule"!]
    
        [!VAR "PreviosChannelId" = "0"!]
        
        [!VAR "CountIndepChannels" = "0"!]
        [!VAR "CountCombinedChannels" = "0"!]
        [!VAR "CalcSumofChannels" = "0"!]
             
        [!LOOP "PwmFtmChannels/*"!]   
 
            [!VAR "hwChIndexVal" = "num:i(substring-after(PwmFtmChannelId,'CH_'))"!]     

            /*check if is a even hw channel or odd number of hw channel*/
            /*for even channel or edge setups should be possible: 0, 2, 4, 6*/
            [!IF "($hwChIndexVal mod 2) = 0"!] 
                 
                /*if an even channel is not IDEPENDENT the next hwchannel (n+1) should not exist*/
                [!IF "ChannelEdgeSetup  = 'INDEPENDENT'"!]
                    [!VAR "CountIndepChannels" = "$CountIndepChannels + 1"!]
                [!ENDIF!]

           /*current channel is odd number: 1, 3, 5, 7*/     
           [!ELSE!] 
                 
               [!IF "ChannelEdgeSetup  = 'INDEPENDENT'"!]
                
                    [!VAR "CurrentChannelId" = "PwmFtmChannelId"!]   
                    /*go through all the FTM channels of the same module again and check if Even channels are incorrectly configured*/
                    [!LOOP "./../../PwmFtmChannels/*"!]   
                        [!VAR "previosHwChIndexVal" = "num:i(substring-after(PwmFtmChannelId,'CH_'))"!]   
                   
                        [!IF "$previosHwChIndexVal = num:i($hwChIndexVal - 1) and ChannelEdgeSetup != 'INDEPENDENT'"!] 
                           [!VAR "PreviosChannelId" = "PwmFtmChannelId"!] 
                           [!CODE!] 
                           [!ERROR!] 
 "[Error in variant: [!"variant:name()"!]] Ftm Channel [!"$CurrentChannelId"!] in module [!"$ModuleName"!] should not be used as long as [!"$PreviosChannelId"!] was defined different than  INDEPENDENT."
                           [!ENDERROR!]                 
                           [!ENDCODE!]
                       [!ENDIF!] 
                    [!ENDLOOP!]                               
                
                    [!VAR "CountIndepChannels" = "$CountIndepChannels + 1"!]     
               [!ELSE!]
                    /*odd channels should not be used in combined mode*/         
                    [!CODE!] 
                    [!ERROR!]                             
"[Error in variant: [!"variant:name()"!]] Ftm Channel [!"PwmFtmChannelId"!] in module configuration [!"$ModuleName"!] as well as all Ftm channels with Odd id values (1, 3, 5, 7)  should not be configured different than INDEPENDENT. "
                    [!ENDERROR!]                 
                    [!ENDCODE!]                    
                [!ENDIF!]

           [!ENDIF!]        
                     
        [!ENDLOOP!]   /*Ftm outher channel loop*/  
      
       /*calculate the maximum possible hw channels considering the given FTM channel configuration*/
        [!VAR "CalcSumofChannels" = "$CountIndepChannels + ($CountCombinedChannels * 2)"!]         
        [!IF "$CalcSumofChannels  > $MaxPossibleChannels"!]
           [!ERROR!] 
           [!CODE!]           
  "[Error in variant: [!"variant:name()"!]] Module configuration [!"$ModuleName"!] contains a maximum number of Hw channels that surpasses the modules capability of [!"$MaxPossibleChannels"!] channels."
           [!ENDCODE!] 
           [!ENDERROR!] 
        [!ENDIF!]

     [!ENDLOOP!] /*Ftm modules loop*/
  [!ENDSELECT!]    
[!ENDNOCODE!]  
 
[!ENDMACRO!]



/* Macro used to generate the value of the default period attribute of a Pwm channel using
either the eTimer IP. The unit measure requested by Autosar for the 
Default Period attribute is 'second'. The plugin allows the user to introduce it either in
seconds or, if plugin field PwmPeriodInTicks is checked, directly in ticks. In both cases, the value
is converted to ticks, beucase this is the format used internally by the driver */
[!MACRO "GenerateTimerChannelPeriodInTicks", "McuClockRefFreqValue", "FtmClockPrescaler"!]
     [!NOCODE!]

    [!VAR "MacVarPeriod" = "PwmPeriodDefault"!]

    [!VAR "MacVarPeriodMax" = "65534"!]

    [!VAR "MacVarPwmPeriodInTicks" = "PwmPeriodInTicks"!]
    [!IF "$MacVarPwmPeriodInTicks = 'true'"!]
        [!VAR "MacVarPeriodTicks" = "num:f($MacVarPeriod)"!]
    [!ELSE!]
        [!VAR "MacVarPeriodTicks" = "num:i(($MacVarPeriod) * ($McuClockRefFreqValue div $FtmClockPrescaler))"!]
    [!ENDIF!]
    [!VAR "MacChannelFreq" =  "$McuClockRefFreqValue div ($MacVarPeriodTicks * $FtmClockPrescaler)"!]
    [!IF "num:i($MacVarPeriodTicks) < 1"!]
        [!WARNING!]
[Error in variant: [!"variant:name()"!]] The configured period/ticks for channel: [!"PwmChannelId"!] is smaller than 1 tick: [!"$MacVarPeriodTicks"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm clock tree settings.
        [!ENDWARNING!]
    [!ENDIF!]
    
    [!IF "num:i($MacVarPeriodTicks) > $MacVarPeriodMax"!]
        [!ERROR!]
[Error in variant: [!"variant:name()"!]] The configured period/ticks for PwmChannelId '[!"PwmChannelId"!]' is [!"$MacVarPeriodTicks"!] which is larger than the maximum allowed value for the period, which is [!"$MacVarPeriodMax"!] ticks
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm clock tree settings.
        [!ENDERROR!]
    [!ENDIF!]

    [!VAR "OutVareTimerChannelDefaultPeriodComment" = "concat(', freq = ', $MacChannelFreq, ' Hz')"!]
    [!VAR "OutVareTimerChannelDefaultPeriod"        = "num:i($MacVarPeriodTicks)"!]
    [!ENDNOCODE!]
[!ENDMACRO!]

/*Macro used for validate PwmMcuClockReferencePoint*/
[!MACRO "ValidateMcuClockAndPwmPeriod"!]
[!NOCODE!]
  [!VAR "VARPwmMcuClockReferencePoint" = "node:value(PwmChannel/*[1]/PwmMcuClockReferencePoint)"!]
  [!LOOP "PwmChannel/*"!]
    [!IF "not(node:value(PwmMcuClockReferencePoint) = $VARPwmMcuClockReferencePoint)"!]
       [!ERROR!]
          [Error in variant: [!"variant:name()"!]] PwmMcuClockReferencePoint is not uniformity. PwmMcuClockReferencePoint must same for all channels 
       [!ENDERROR!]
    [!ENDIF!]
  [!ENDLOOP!]
[!LOOP "PwmFtmModule/*"!]
    [!VAR "FtmPeriodTemp" = "0"!]
    [!VAR "FtmPeriodFinal" = "'hihi'"!]
    [!LOOP "PwmFtmChannels/*"!]
        [!VAR "FtmChanName" = "node:name(.)"!]  
        [!VAR "FtmModName" = "node:name(../../.)"!]  
        /*Go through all FTM channel*/
        [!LOOP "../../../../PwmChannel/*"!]    
            [!VAR "FtmRefName" = "node:name(.)"!]  
            /*get the hw FTM module name from the reference */
            [!VAR "FtmRefName" = "node:value(PwmFtmChannel)"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefModName" = "substring-before($FtmRefName,'/')"!]  
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]  
            [!IF "($FtmRefName = $FtmChanName) and ($FtmRefModName = $FtmModName)"!]    
                [!VAR "PresValue" = "node:ref(PwmFtmChannel)/../../PwmPrescaler"!]
                [!VAR "PresValue" = "substring-after($PresValue,'PRESC_')"!]
                [!VAR "McuClockValue" = "node:ref(PwmMcuClockReferencePoint)/McuClockReferencePointFrequency"!]
                [!CALL "GenerateTimerChannelPeriodInTicks", "McuClockRefFreqValue" = "$McuClockValue", "FtmClockPrescaler" = "$PresValue"!]                  
                [!VAR "FtmPeriodTemp" = "$OutVareTimerChannelDefaultPeriod"!]    
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$FtmPeriodFinal = 'hihi'"!]
            [!VAR "FtmPeriodFinal" = "$FtmPeriodTemp"!]
        [!ELSEIF "$FtmPeriodFinal != $FtmPeriodTemp"!]
            [!ERROR!]
                [Error in variant: [!"variant:name()"!]] Uniform period violation. All logical channels using FTM hardware channels from module [!"$FtmModName"!] must be configured with the same period value.
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!ENDNOCODE!]

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
* 
* @section Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
* 
* @section Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.*
*
* @section Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only one file.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pwm.h"
#include "Reg_eSys_Ftm.h"
#include "Ftm_Common_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*/

#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C                      43
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_MODULE_ID_C                      121
/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C    2

#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C               1
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C               0
#define PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C               1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pwm.h have different vendor ids"
#endif

#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pwm.h are different"
#endif

#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
        (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION)  || \
        (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Pwm.h are different"
#endif

/* Check if header file and Reg_eSys_Ftm.h header file are of the same vendor */
#if (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_Ftm.h have different vendor ids"
#endif
/* Check if header file and Reg_eSys_Ftm.h header file are of the same Autosar version */
#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif
/* Check if header file and Reg_eSys_Ftm.h header file are of the same software version */
#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif

/* Check if header file and Ftm_Common_Types.h header file are of the same vendor */
#if (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_VENDOR_ID_C != FTM_COMMON_TYPES_VENDOR_ID)
    #error "Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftm_Common_Types.h have different vendor ids"
#endif
/* Check if header file and Ftm_Common_Types.h header file are of the same Autosar version */
#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftm_Common_Types.h are different"
#endif
/* Check if header file and Ftm_Common_Types.h header file are of the same software version */
#if ((PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MAJOR_VERSION_C != FTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_MINOR_VERSION_C != FTM_COMMON_TYPES_SW_MINOR_VERSION) || \
     (PWM[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBCFG_SW_PATCH_VERSION_C != FTM_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Ftm_Common_Types.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
[!SELECT "PwmChannelConfigSet"!]
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

[!NOCODE!]
[!INCLUDE "Pwm_NotifyCheck_Src.m"!]
[!IF "../PwmGeneral/PwmNotificationSupported"!]
    [!CALL "GeneratePwmNotifications"!]
[!ENDIF!]
[!ENDNOCODE!]
[!ENDSELECT!]

[!NOCODE!]
[!IF "PwmGeneral/PwmFaultSupport"!]
    [!CALL "GenerateFtmFaultNotifications"!]
[!ENDIF!]
[!ENDNOCODE!]
  
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*  contents of a header file being included twice.*/
/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3 MISRA 2004 Required Rule 19.1, only preprocessor statements 
*  and comments before "#include" */
#include "Pwm_MemMap.h"

[!CALL "ValidatePwmConfiguration"!]

[!SELECT "PwmChannelConfigSet"!]
[!NOCODE!]
[!CALL "ValidateMcuClockAndPwmPeriod"!]

/* Validate Pwm configuration */
[!VAR "PwmChannels" = "num:i(count(PwmChannel/*))"!]
[!VAR "PwmFtmModules" = "num:i(count(PwmFtmModule/*))"!]
[!VAR "NumPwmFtmChannels" = "num:i(count(PwmFtmModule/*/PwmFtmChannels/*))"!]

[!ENDNOCODE!]

/** 
* @brief Number of configured Pwm channels 
*/
#define PWM_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]            ((uint8) [!"$PwmChannels"!]U)

/** 
* @brief Number of configured Ftm channels 
*/
#define PWM_FTM_MOD_CONFIGS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]         ((uint8) [!"$PwmFtmModules"!]U)

/** 
* @brief Number of configured Ftm channels 
*/
#define PWM_CONF_FTM_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]         ((uint8) [!"$NumPwmFtmChannels"!]U)



[!NOCODE!]



[!CODE!]
/** @brief Configurations for Pwm channels using Ftm */
static CONST(Pwm_Ftm_ChannelConfigType, PWM_CONST) Pwm_Ftm_ChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_CONF_FTM_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
[!ENDCODE!]
    [!VAR "CountFtmChannels" = "0"!]

    /*Go through all PWM channels*/
    
   [!LOOP "PwmFtmModule/*/PwmFtmChannels/*"!]    
    [!VAR "FtmChanName" = "node:name(.)"!]  
    [!VAR "FtmModName" = "node:name(../../.)"!]  
    [!VAR "FtmChanPolarity" = "0"!]          
    [!VAR "FtmChanIdleState" = "0"!] 
    [!VAR "FtmChanDefDuty" = "0"!] 
    [!VAR "FtmPhaseShiftValue" = "0"!]    
    [!VAR "FtmPresValue" = "substring-after(../../PwmPrescaler,'PRESC_')"!]
    /*Go through all FTM channel*/ 
    [!LOOP "../../../../PwmChannel/*"!]    
        [!VAR "FtmRefName" = "node:name(.)"!]  
        /*get the hw FTM module name from the reference */
        [!VAR "FtmRefName" = "node:value(PwmFtmChannel)"!]
        [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
        [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
        [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
        [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
        [!VAR "FtmRefModName" = "substring-before($FtmRefName,'/')"!]  
        [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]  
        [!VAR "McuClockValue" = "node:value(node:ref(PwmMcuClockReferencePoint)/McuClockReferencePointFrequency)"!]
        [!IF "($FtmRefName = $FtmChanName) and ($FtmRefModName = $FtmModName)"!]
            [!VAR "FtmChanPolarity" = "node:value(PwmPolarity)"!]   
            [!VAR "FtmChanIdleState" = "node:value(PwmIdleState)"!]   
            [!VAR "FtmChanDefDuty" = "node:value(PwmDutycycleDefault)"!]          
            [!CALL "GenerateTimerChannelPeriodInTicks", "McuClockRefFreqValue" = "$McuClockValue", "FtmClockPrescaler" = "$FtmPresValue"!]     
            [!IF "ChannelEdgeSetup = 'PHASE_SHIFTED_SINGLE' or ChannelEdgeSetup = 'PHASE_SHIFTED_SYNCED' or ChannelEdgeSetup = 'PHASE_SHIFTED_COMPLEMENTARY'"!]
                [!VAR "FtmPhaseShiftValue" = "PwmPhaseShift"!]
                [!IF "$FtmPhaseShiftValue > $OutVareTimerChannelDefaultPeriod"!]
                    [!ERROR!]
                    Phase Shift Ticks ([!"$FtmPhaseShiftValue"!])  should not be greater than period default ([!"$OutVareTimerChannelDefaultPeriod"!])
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]  
    [!ENDLOOP!]    
[!CODE!]
    /** @brief PWM_FTM_CHANNEL_[!"num:i($CountFtmChannels)"!] */
    {
        /** @brief Pwm channel polarity */
        [!ENDCODE!]       
        /*channel polarity is a mandatory parameter if it was not defined as HIGH or LOW then the Ftm channel was not used by any PWM channel */
           [!CODE!]  
     [!IF "($FtmChanPolarity != 'PWM_LOW'  and   $FtmChanPolarity != 'PWM_HIGH')"!]
             [!ERROR!]          
  "[Error in variant: [!"variant:name()"!]] Ftm Channel container [!"$FtmChanName"!] of module [!"$FtmModName"!] was not referenced by any PWM channels."
             [!ENDERROR!] 
        [!ELSE!]
        [!"$FtmChanPolarity"!],
        [!ENDIF!]  
     [!ENDCODE!]  
        [!CODE!] 

        /** @brief Pwm channel idle state */
        [!"$FtmChanIdleState"!],

        /** @brief Default duty cycle value */
        ((uint16)[!"$FtmChanDefDuty"!]),
        
        /** @brief Ftm Channel Id */
        [!"node:value(PwmFtmChannelId)"!],
        
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        /** @brief Default phase shift value */
    [!IF "node:accessible(PwmPhaseShift)"!]
        ((uint16)[!"node:value(PwmPhaseShift)"!]),
    [!ELSE!]
        ((uint16) 0),
    [!ENDIF!]
#endif
[!ENDCODE!]
    [!IF "node:value(../../PwmChanEdgeAlignment) = 'PWM_CENTER_ALIGNED'"!]
[!CODE!]
        /** @brief Edge alignment for the current channel  */
        PWM_CENTER_ALIGNED
[!ENDCODE!]
    [!ELSE!]
        [!IF "node:value(ChannelEdgeSetup) = 'INDEPENDENT'"!]        
[!CODE!]
        /** @brief Edge alignment for the current channel  */    
        PWM_EDGE_ALIGNED
[!ENDCODE!]
        [!ELSEIF "node:value(ChannelEdgeSetup) = 'COMBINED_SYNCED'"!]
[!CODE!]
        /** @brief Edge alignment for the current channel  */    
        PWM_COMBINE_SYNCED
[!ENDCODE!]
        [!ELSEIF "node:value(ChannelEdgeSetup) = 'COMBINED_COMPLEMENTARY'"!]
[!CODE!]
        /** @brief Edge alignment for the current channel  */    
        PWM_COMBINE_COMPL
[!ENDCODE!]
        [!ELSEIF "node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SINGLE'"!]
[!CODE!]
        /** @brief Edge alignment for the current channel  */    
        PWM_PHASE_SHIFT_SINGLE
[!ENDCODE!]
        [!ELSEIF "node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SYNCED'"!]
[!CODE!]
        /** @brief Edge alignment for the current channel  */    
        PWM_PHASE_SHIFTED_SYNCED
[!ENDCODE!]
        [!ELSE!]
[!CODE!]
        /** @brief Edge alignment for the current channel  */    
        PWM_PHASE_SHIFTED_COMPLEMENTARY
[!ENDCODE!]
        [!ENDIF!]
    [!ENDIF!]
       
[!CODE!] 
        [!VAR "CountFtmChannels" = "$CountFtmChannels + 1"!]      
        [!IF "$CountFtmChannels < $NumPwmFtmChannels"!]
    },     
        [!ELSE!]
    }
        [!ENDIF!]    
   
    [!ENDCODE!]   

    [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
[!CODE!]
/** @brief Array of configurations for all Ftm modules supported by the platform */
/*
* @violates @ref Pwm_Cfg_C_REF_2 external ... could be made static
*/
static CONST(Pwm_Ftm_ModuleConfigType, PWM_CONST) Pwm_Ftm_ModuleConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_FTM_MOD_CONFIGS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
[!ENDCODE!]
    [!VAR "CountFtmModules" = "0"!]
    [!VAR "CurrentConfigSetName" = "node:name(.)"!]
[!LOOP "PwmFtmModule/*"!]
    [!VAR "FtmModName" = "node:value(FtmModule)"!]
    [!VAR "FtmModContName" = "node:name(.)"!]
    [!VAR "FtmBDMXdmValue" = "node:value(PwmBDMEnable)"!]

    [!VAR "FtmCSRegValue" = "'((uint32)0)),'"!]
    [!VAR "FtmAlternativeCSRegValue" = "'((uint32)0)),'"!]
    [!VAR "McuClockValue" = "0"!] 

    [!VAR "FtmConfRegValue" = "'('"!]
    [!IF "$FtmBDMXdmValue = 'CNT_STOPED_FLAG_SET'"!]     
        [!VAR "FtmConfRegValue" = "concat($FtmConfRegValue, 'FTM_CONF_BDMMODE_ALLSTOP_U32 | ')"!]
    [!ELSEIF "$FtmBDMXdmValue = 'CNT_STOPED_OUTPUTS_SAFE'"!]     
        [!VAR "FtmConfRegValue" = "concat($FtmConfRegValue, 'FTM_CONF_BDMMODE_OUTPUTSSAFE_U32 | ')"!]
    [!ELSEIF "$FtmBDMXdmValue = 'CNT_STOPED_OUTPUTS_FROZEN'"!]     
        [!VAR "FtmConfRegValue" = "concat($FtmConfRegValue, 'FTM_CONF_BDMMODE_OUTPUTSRUN_U32 | ')"!]
    [!ELSE!]        
        [!VAR "FtmConfRegValue" = "concat($FtmConfRegValue, 'FTM_CONF_BDMMODE_ALLRUN_U32 | ')"!]
    [!ENDIF!]

    /* Get LDFQ for reload frequency */
    [!IF "node:value(../../../PwmGeneral/PwmDutycycleUpdatedEndperiod) = 'true'"!]
        [!VAR "ReloadFrequency" = "num:i(substring-after(node:value(./PwmReloadFrequency), 'LDFQ_EACH')) - 1"!]
        [!VAR "FtmConfRegValue" = "concat($FtmConfRegValue, '((uint32) ', num:i($ReloadFrequency), 'U) | ')"!]        
    [!ENDIF!]
    
    [!VAR "FtmConfRegValue" = "concat($FtmConfRegValue, '((uint32) 0)),')"!]
    
    /* Get EXTTRIG value*/
    [!IF "node:value(../../../PwmGeneral/PwmFtmEnableExtTrigger) = 'true'"!]
      [!VAR "FtmExtTrgChValue" = "'((uint32)0U'"!]       
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel0) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)4U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel1) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)5U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel2) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)0U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel3) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)1U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel4) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)2U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel5) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)3U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel6) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)8U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableExternalTriggerChannel7) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)9U)')"!]
      [!ENDIF!]
      [!IF "node:value(./PwmExternalTriggerSettings/PwmEnableInitializationTrigger) = 'true'"!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,'|((uint32)1U <<  (uint32)6U)')"!]
      [!ENDIF!]
        [!VAR "FtmExtTrgChValue" = "concat($FtmExtTrgChValue,')')"!]
    [!ENDIF!]
    
    /*get edge alignment*/
     [!IF "node:value(PwmChanEdgeAlignment) = 'PWM_CENTER_ALIGNED'"!]
          [!VAR "FtmCSEdgeRegValue" = "'FTM_SC_CPWMS_UP_DOWN_COUNTING_U32 | '"!]
     [!ELSE!]
          [!VAR "FtmCSEdgeRegValue" = "''"!]
     [!ENDIF!]
     
    /*get update period status*/
     [!VAR "FtmSYNCRegValue" = "'(uint8) ('"!]
     [!IF "node:value(../../../PwmGeneral/PwmDutycycleUpdatedEndperiod) = 'true'"!]
         [!IF "node:value(PwmChanEdgeAlignment) = 'PWM_CENTER_ALIGNED'"!]
             [!IF "node:value(PwmUpdatedEndPeriod) = 'true'"!]
                [!VAR "FtmSYNCRegValue" = "concat($FtmSYNCRegValue,'(FTM_SYNC_CNTMAX_ENABLE_U32 << FTM_SYNC_CNTMAX_SHIFT) | ')"!]
             [!ENDIF!]         
             [!IF "node:value(PwmUpdatedMiddlePeriod) = 'true'"!]
                 [!VAR "FtmSYNCRegValue" = "concat($FtmSYNCRegValue, 'FTM_SYNC_CNTMIN_ENABLE_U32 | ')"!]
             [!ENDIF!]         
         [!ELSE!]
            [!VAR "FtmSYNCRegValue" = "concat($FtmSYNCRegValue, 'FTM_SYNC_CNTMIN_ENABLE_U32 | ')"!]
         [!ENDIF!]
     [!ENDIF!]
     [!VAR "FtmSYNCRegValue" = "concat($FtmSYNCRegValue, '((uint32) 0)),')"!] 
    
    /*get channels are used to enble OUTPUTEN bits*/
    [!VAR "PwmOutputEnableBitField" = "' '"!]
    [!IF "ecu:get('Pwm.PwmChannelConfigSet.PWMEN_feature') = 'true'"!]
       [!LOOP "PwmFtmChannels/*"!]
            [!VAR "ChannelUsed" = "substring-after(PwmFtmChannelId,'CH_')"!]                        
            [!VAR "PwmOutputEnableBitField" = "concat(' ((uint32)1U << (FTM_SC_PWMOUTPUTEN_SHIFT + (uint32)',$ChannelUsed ,'U ))', '|', $PwmOutputEnableBitField)"!]
            [!IF "($ChannelUsed mod 2) = 0"!] 
                [!IF "ChannelEdgeSetup  != 'INDEPENDENT'"!] 
                [!VAR "PwmOutputEnableBitField" = "concat(' ((uint32)1U << (FTM_SC_PWMOUTPUTEN_SHIFT + (uint32)',($ChannelUsed+1) ,'U ))', '|', $PwmOutputEnableBitField)"!]
                [!ENDIF!]    
            [!ENDIF!]    
        [!ENDLOOP!]    
    [!ENDIF!]

    /*get clock source*/
     [!IF "node:value(PwmClockSelection) = 'PWM_SYSTEM_CLOCK'"!]
          [!VAR "FtmCSClkRegValue" = "'FTM_SC_CLKS_SYS_CLOCK_U32 | '"!]
     [!ELSEIF "node:value(PwmClockSelection) = 'PWM_FIXED_FREQ_CLOCK'"!]
          [!VAR "FtmCSClkRegValue" = "'FTM_SC_CLKS_FIXED_FREQ_CLOCK_U32 | '"!]
     [!ELSEIF "node:value(PwmClockSelection) = 'PWM_EXTERNAL_CLOCK'"!]
          [!VAR "FtmCSClkRegValue" = "'FTM_SC_CLKS_EXTERNAL_CLOCK_U32 | '"!]
     [!ELSE!]
          [!VAR "FtmCSClkRegValue" = "'FTM_SC_CLKS_NO_CLOCKS_U32 | '"!]
          [!WARNING!] 
"No clock was selected for module [!"$FtmModName"!]." 
          [!ENDWARNING!]
     [!ENDIF!]

    /*get prescaler*/
     [!IF "node:value(PwmPrescaler) = 'PRESC_1'"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV1_U32 | '"!]
        [!VAR "FtmPresValue" = "1"!]
     [!ELSEIF "node:value(PwmPrescaler) = 'PRESC_2'"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV2_U32 | '"!]
        [!VAR "FtmPresValue" = "2"!]
     [!ELSEIF "node:value(PwmPrescaler) = 'PRESC_4'"!]
        [!VAR "FtmPresValue" = "4"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV4_U32 | '"!]
     [!ELSEIF "node:value(PwmPrescaler) = 'PRESC_8'"!]
        [!VAR "FtmPresValue" = "8"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV8_U32 |'"!]
     [!ELSEIF "node:value(PwmPrescaler) = 'PRESC_16'"!]
        [!VAR "FtmPresValue" = "16"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV16_U32 | '"!]
     [!ELSEIF "node:value(PwmPrescaler) = 'PRESC_32'"!]
        [!VAR "FtmPresValue" = "32"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV32_U32 | '"!]
     [!ELSEIF "node:value(PwmPrescaler) = 'PRESC_64'"!]
        [!VAR "FtmPresValue" = "64"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV64_U32 | '"!]
     [!ELSE!]
        [!VAR "FtmPresValue" = "128"!]
          [!VAR "FtmCSPresRegValue" = "'FTM_SC_PS_DIV128_U32 | '"!]
     [!ENDIF!]

      /*get alterntive prescaler*/
     [!IF "../../../PwmGeneral/PwmEnableDualClockMode"!] 
         [!IF "node:value(PwmPrescaler_Alternate) = 'PRESC_1'"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV1_U32 | '"!]
            [!VAR "FtmPresValue" = "1"!]
         [!ELSEIF "node:value(PwmPrescaler_Alternate) = 'PRESC_2'"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV2_U32 | '"!]
            [!VAR "FtmPresValue" = "2"!]
         [!ELSEIF "node:value(PwmPrescaler_Alternate) = 'PRESC_4'"!]
            [!VAR "FtmPresValue" = "4"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV4_U32 | '"!]
         [!ELSEIF "node:value(PwmPrescaler_Alternate) = 'PRESC_8'"!]
            [!VAR "FtmPresValue" = "8"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV8_U32 |'"!]
         [!ELSEIF "node:value(PwmPrescaler_Alternate) = 'PRESC_16'"!]
            [!VAR "FtmPresValue" = "16"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV16_U32 | '"!]
         [!ELSEIF "node:value(PwmPrescaler_Alternate) = 'PRESC_32'"!]
            [!VAR "FtmPresValue" = "32"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV32_U32 | '"!]
         [!ELSEIF "node:value(PwmPrescaler_Alternate) = 'PRESC_64'"!]
            [!VAR "FtmPresValue" = "64"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV64_U32 | '"!]
         [!ELSE!]
            [!VAR "FtmPresValue" = "128"!]
              [!VAR "FtmCSAlternativePresRegValue" = "'FTM_SC_PS_DIV128_U32 | '"!]
         [!ENDIF!]
     [!ENDIF!]

     [!IF "../../../PwmGeneral/PwmEnableDualClockMode"!] 
     /*calculate alternative CS Reg value*/
        [!VAR "FtmAlternativeCSRegValue" = "concat('(', $FtmCSEdgeRegValue, $FtmCSClkRegValue, $FtmCSAlternativePresRegValue, $PwmOutputEnableBitField,$FtmAlternativeCSRegValue)"!]
     [!ENDIF!]
    
     /*calculate CS Reg value*/
     [!VAR "FtmCSRegValue" = "concat('(', $FtmCSEdgeRegValue, $FtmCSClkRegValue, $FtmCSPresRegValue, $PwmOutputEnableBitField, $FtmCSRegValue)"!]

     
     /*get fault configuration*/
    [!IF "node:value(../../../PwmGeneral/PwmFaultSupport) = 'true'"!] 
        [!IF "node:value(PwmFtmFaultFunctionality) = 'FLTCTRL_DISABLED'"!]
            [!VAR "FtmModeFltValue" = "''"!]
        [!ELSEIF "node:value(PwmFtmFaultFunctionality) = 'AUTOMATIC_FOR_EVEN_CHANNELS'"!]
            [!VAR "FtmModeFltValue" = "'(FTM_MODE_FAULTM_ENABLE_EVEN_U32 | FTM_MODE_FAULTIE_ENABLE_U32) | '"!]
        [!ELSEIF "node:value(PwmFtmFaultFunctionality) = 'AUTOMATIC_FOR_ALL_CHANNELS'"!]
            [!VAR "FtmModeFltValue" = "'(FTM_MODE_FAULTM_ENABLED_MANUAL_U32 | FTM_MODE_FAULTIE_ENABLE_U32) | '"!]
        [!ENDIF!]
    [!ELSE!]
        [!VAR "FtmModeFltValue" = "''"!]
    [!ENDIF!]
      
    /*get dead time configuration*/
    [!IF "((node:exists(DeadTimePrescaler)) and (DeadTimePrescaler = 'PRESC_16'))"!] 
          [!VAR "FtmDTPSValue" = "'(FTM_DEADTIME_DTPS_DIV16_U32 | '"!]
    [!ELSEIF "((node:exists(DeadTimePrescaler)) and (DeadTimePrescaler = 'PRESC_4'))"!]
          [!VAR "FtmDTPSValue" = "'(FTM_DEADTIME_DTPS_DIV4_U32 | '"!]     
    [!ELSE!]
        [!VAR "FtmDTPSValue" = "'(FTM_DEADTIME_DTPS_DIV1_U32 | '"!]
    [!ENDIF!]
    
    [!IF "node:exists(PwmDeadTimeCount)"!] 
         [!VAR "DeadTimeCount" = "num:i(node:value(PwmDeadTimeCount))"!]
    [!ELSE!]
        [!VAR "DeadTimeCount" = "num:i(0)"!]
    [!ENDIF!]  
    
    [!LOOP "PwmFtmChannels/*"!]
        [!IF "((ChannelEdgeSetup = 'PHASE_SHIFTED_SYNCED') or (ChannelEdgeSetup = 'COMBINED_SYNCED')) and ($DeadTimeCount != 0)"!]
            [!WARNING!]
If ChannelEdgeSetup is configured as PHASE_SHIFTED_SYNCED/COMBINED_SYNCED, PwmDeadTimeCount should be 0 or disabled. Deadtime insertion with PHASE_SHIFTED_SYNCED/COMBINED_SYNCED mode may cause to the odd channel not work.
            [!ENDWARNING!]
        [!ENDIF!]
    [!ENDLOOP!]
    
    [!VAR "ExtendDeadtimeValue" = "bit:shr(bit:and($DeadTimeCount,960),6)"!]
    [!VAR "DeadtimeValue" = "bit:and($DeadTimeCount,63)"!]
    
    [!IF "$DeadTimeCount < 64"!]
        [!VAR "FtmDTPSValue" = "concat($FtmDTPSValue, '((uint32) ', $DeadTimeCount, 'U)),')"!]
    [!ELSE!]
        [!VAR "FtmDTPSValue" = "concat($FtmDTPSValue, '(((uint32) ', $ExtendDeadtimeValue, 'U) << FTM_DEADTIME_DTVALEX_SHIFT) | ((uint32)', $DeadtimeValue, 'U)),')"!]
    [!ENDIF!]
    
    
    [!VAR "FtmCombine0Value" = "''"!]
    [!VAR "FtmCombine1Value" = "''"!]
    [!VAR "FtmCombine2Value" = "''"!]
    [!VAR "FtmCombine3Value" = "''"!]
    /*write POL register */
   /*Go through all PWM channels*/ 
   [!VAR "FtmPolValue" = "''"!]
   [!VAR "FtmChanCount" = "0"!]
   [!LOOP "PwmFtmChannels/*"!]
       [!VAR "FtmChanName" = "node:name(.)"!]   
       [!VAR "FtmChanPolarity" = "0"!]              
             
       /*Go through all FTM channel*/
       [!LOOP "../../../../PwmChannel/*"!]    
            [!VAR "FtmRefName" = "node:name(.)"!]  
            /*get the hw FTM module name from the reference */
            [!VAR "FtmRefName" = "node:value(PwmFtmChannel)"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefModName" = "substring-before($FtmRefName,'/')"!]  
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]  

            [!IF "($FtmRefName = $FtmChanName) and ($FtmRefModName = $FtmModContName)"!]
                [!VAR "FtmChanPolarity" = "node:value(PwmPolarity)"!] 
           
                [!BREAK!]
            [!ENDIF!]      
       [!ENDLOOP!] 
         
       [!IF "$FtmChanPolarity = 'PWM_LOW'"!] 
               [!VAR "FtmPolValue" = "concat($FtmPolValue, '(1 << ', node:value(PwmFtmChannelId),') | ')"!]     
       [!ENDIF!]   
   
       [!VAR "ChannelId" = "substring-after(PwmFtmChannelId,'CH_')"!]     
        
       [!IF "$ChannelId = '0' or $ChannelId = '1'"!]  
             [!VAR "FtmCombine0Value" = "'FTM_COMBINE_SYNCEN0_ENABLE_U32'"!]
             
             /*if fault is enabled for module then fault should be enabled for combined channels*/
             [!IF "node:value(../../../../../PwmGeneral/PwmFaultSupport) = 'true'"!]
                 [!IF "../../PwmFtmFaultFunctionality != 'FLTCTRL_DISABLED'"!]
                     [!VAR "FtmCombine0Value" = "concat($FtmCombine0Value, ' | FTM_COMBINE_FAULTEN0_ENABLE_U32')"!]    
                 [!ENDIF!]  
             [!ENDIF!]
       [!ENDIF!]
       
       [!IF "$ChannelId = '2' or $ChannelId = '3'"!]  
             [!VAR "FtmCombine1Value" = "'FTM_COMBINE_SYNCEN1_ENABLE_U32'"!]

             /*if fault is enabled for module then fault should be enabled for combined channels*/
             [!IF "node:value(../../../../../PwmGeneral/PwmFaultSupport) = 'true'"!]
                  [!IF "../../PwmFtmFaultFunctionality != 'FLTCTRL_DISABLED'"!]
                     [!VAR "FtmCombine1Value" = "concat($FtmCombine1Value, ' | FTM_COMBINE_FAULTEN1_ENABLE_U32')"!]  
                 [!ENDIF!]    
             [!ENDIF!]
       [!ENDIF!] 
       
       [!IF "$ChannelId = '4' or $ChannelId = '5'"!]  
             [!VAR "FtmCombine2Value" = "'FTM_COMBINE_SYNCEN2_ENABLE_U32'"!]

             /*if fault is enabled for module then fault should be enabled for combined channels*/
             [!IF "node:value(../../../../../PwmGeneral/PwmFaultSupport) = 'true'"!]
                  [!IF "../../PwmFtmFaultFunctionality != 'FLTCTRL_DISABLED'"!]
                     [!VAR "FtmCombine2Value" = "concat($FtmCombine2Value, ' | FTM_COMBINE_FAULTEN2_ENABLE_U32')"!]      
                 [!ENDIF!]
             [!ENDIF!]
       [!ENDIF!] 
       
       [!IF "$ChannelId = '6' or $ChannelId = '7'"!]  
             [!VAR "FtmCombine3Value" = "'FTM_COMBINE_SYNCEN3_ENABLE_U32'"!]

             /*if fault is enabled for module then fault should be enabled for combined channels*/
             [!IF "node:value(../../../../../PwmGeneral/PwmFaultSupport) = 'true'"!]
                 [!IF "../../PwmFtmFaultFunctionality != 'FLTCTRL_DISABLED'"!]
                     [!VAR "FtmCombine3Value" = "concat($FtmCombine3Value, ' | FTM_COMBINE_FAULTEN3_ENABLE_U32')"!]      
                 [!ENDIF!]
             [!ENDIF!]
       [!ENDIF!]
       
       [!IF "node:value(ChannelEdgeSetup) != 'INDEPENDENT'"!]
                
                /*check for each even channel*/
                [!IF "$ChannelId = '0'"!]                          
                    [!VAR "FtmCombine0Value" = "concat($FtmCombine0Value, ' | FTM_COMBINE_COMBINE0_COMBINED_U32')"!]                        
                    
                     /*if deadtime for combined channels is needed*/
                    [!IF "node:value(ChannelCombDeadTimeEn) = 'true'"!]                   
                         [!VAR "FtmCombine0Value" = "concat($FtmCombine0Value, ' | FTM_COMBINE_DTEN0_ENABLE_U32')"!] 
                    [!ENDIF!]  

                     /*check if channels are in complementary mode*/
                    [!IF "node:value(ChannelEdgeSetup) = 'COMBINED_COMPLEMENTARY' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine0Value" = "concat($FtmCombine0Value, ' | FTM_COMBINE_COMP0_COMPLEMENT_U32')"!]                         
                    [!ENDIF!]
                    
                    /*check if channels are in phase shift mode*/
                     [!IF "node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SINGLE' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SYNCED' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine0Value" = "concat($FtmCombine0Value, ' | FTM_COMBINE_MCOMBINE0_ENABLE_U32')"!]                         
                    [!ENDIF!] 
                       
                     
                    [!ELSEIF "$ChannelId = '2'"!]
                    [!VAR "FtmCombine1Value" = "concat($FtmCombine1Value, ' | FTM_COMBINE_COMBINE1_COMBINED_U32')"!]    
                    
                     /*if deadtime for combined channels is needed*/
                    [!IF "node:value(ChannelCombDeadTimeEn) = 'true'"!]                   
                        [!VAR "FtmCombine1Value" = "concat($FtmCombine1Value, ' | FTM_COMBINE_DTEN1_ENABLE_U32')"!] 
                    [!ENDIF!]  
                    
                     /*check if channels are in complementary mode*/
                    [!IF "node:value(ChannelEdgeSetup) = 'COMBINED_COMPLEMENTARY' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!]  
                        [!VAR "FtmCombine1Value" = "concat($FtmCombine1Value, ' | FTM_COMBINE_COMP1_COMPLEMENT_U32')"!]       
                    [!ENDIF!]   
                    
                    /*check if channels are in phase shift mode*/
                     [!IF "node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SINGLE' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SYNCED' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine1Value" = "concat($FtmCombine1Value, ' | FTM_COMBINE_MCOMBINE1_ENABLE_U32')"!]                         
                    [!ENDIF!]
                    
                    [!ELSEIF "$ChannelId = '4'"!]                    
                    [!VAR "FtmCombine2Value" = "concat($FtmCombine2Value, ' | FTM_COMBINE_COMBINE2_COMBINED_U32')"!]  
                    
                     /*if deadtime for combined channels is needed*/
                    [!IF "node:value(ChannelCombDeadTimeEn) = 'true'"!]                   
                        [!VAR "FtmCombine2Value" = "concat($FtmCombine2Value, ' | FTM_COMBINE_DTEN2_ENABLE_U32')"!]      
                    [!ENDIF!] 
                    
                     /*check if channels are in complementary mode*/
                     [!IF "node:value(ChannelEdgeSetup) = 'COMBINED_COMPLEMENTARY' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine2Value" = "concat($FtmCombine2Value, ' | FTM_COMBINE_COMP2_COMPLEMENT_U32')"!]      
                     [!ENDIF!]
                    
                     /*check if channels are in phase shift mode*/
                     [!IF "node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SINGLE' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SYNCED' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine2Value" = "concat($FtmCombine2Value, ' | FTM_COMBINE_MCOMBINE2_ENABLE_U32')"!]                         
                     [!ENDIF!]  

                [!ELSEIF "$ChannelId = '6'"!]
                    [!VAR "FtmCombine3Value" = "concat($FtmCombine3Value, ' | FTM_COMBINE_COMBINE3_COMBINED_U32')"!]     
                    
                     /*if deadtime for combined channels is needed*/
                    [!IF "node:value(ChannelCombDeadTimeEn) = 'true'"!]                   
                        [!VAR "FtmCombine3Value" = "concat($FtmCombine3Value, ' | FTM_COMBINE_DTEN3_ENABLE_U32')"!]      
                    [!ENDIF!] 
                    
                     /*check if channels are in complementary mode*/
                     [!IF "node:value(ChannelEdgeSetup) = 'COMBINED_COMPLEMENTARY' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine3Value" = "concat($FtmCombine3Value, ' | FTM_COMBINE_COMP3_COMPLEMENT_U32')"!]      
                     [!ENDIF!]  

                    /*check if channels are in phase shift mode*/
                     [!IF "node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SINGLE' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_SYNCED' or node:value(ChannelEdgeSetup) = 'PHASE_SHIFTED_COMPLEMENTARY'"!] 
                        [!VAR "FtmCombine3Value" = "concat($FtmCombine3Value, ' | FTM_COMBINE_MCOMBINE3_ENABLE_U32')"!]                         
                    [!ENDIF!]       
                    
                [!ELSE!]
                    /*do nothing*/
                [!ENDIF!]
        
       [!ENDIF!]    
       
       [!VAR "FtmChanCount" = "$FtmChanCount + 1"!]
    [!ENDLOOP!] 
    
    
    /*write COMBINE register*/
    [!VAR "FtmCombineValue" = "'((uint32) 0)'"!]
    
    /*check if channels are in complementary mode*/
    [!IF "$FtmCombine0Value != ''"!] 
         [!VAR "FtmCombineValue" = "concat($FtmCombine0Value, ' | ', $FtmCombineValue)"!]      
    [!ENDIF!] 
    
    [!IF "$FtmCombine1Value != ''"!] 
         [!VAR "FtmCombineValue" = "concat($FtmCombine1Value, ' | ', $FtmCombineValue)"!]      
    [!ENDIF!] 
    
     [!IF "$FtmCombine2Value != ''"!] 
         [!VAR "FtmCombineValue" = "concat($FtmCombine2Value, ' | ', $FtmCombineValue)"!]      
     [!ENDIF!] 
    
    [!IF "$FtmCombine3Value != ''"!] 
          [!VAR "FtmCombineValue" = "concat($FtmCombine3Value, ' | ', $FtmCombineValue)"!] 
    [!ENDIF!]  
    
    [!IF "$FtmCombineValue != '((uint32) 0)'"!] 
        [!VAR "FtmCombineValue" = "concat('(', $FtmCombineValue, '),')"!]
    [!ELSE!]
        [!VAR "FtmCombineValue" = "'((uint32) 0),'"!]
    [!ENDIF!]
    
    [!VAR "FtmPolValue" = "concat($FtmPolValue, '((uint32) 0)')"!]
    [!VAR "FtmPolValue" = "concat('(', $FtmPolValue, '),')"!]

    
    /*write FLTCTRL register*/
    [!VAR "FtmFltCtrlValue" = "''"!]
    [!VAR "FtmEnableFltFilter0" = "''"!]
    [!VAR "FtmEnableFltFilter1" = "''"!]
    [!VAR "FtmEnableFltFilter2" = "''"!]
    [!VAR "FtmEnableFltFilter3" = "''"!]
    [!VAR "FtmFault0Polarity" = "''"!]
    [!VAR "FtmFault1Polarity" = "''"!]
    [!VAR "FtmFault2Polarity" = "''"!]
    [!VAR "FtmFault3Polarity" = "''"!]
    [!VAR "FtmFault0Notif" = "'NULL_PTR'"!]
    [!VAR "FtmFault1Notif" = "'NULL_PTR'"!]
    [!VAR "FtmFault2Notif" = "'NULL_PTR'"!]
    [!VAR "FtmFault3Notif" = "'NULL_PTR'"!]

    [!IF "node:value(../../../PwmGeneral/PwmFaultSupport) = 'true'"!]
        [!IF "node:value(PwmFtmFaultFunctionality) = 'FLTCTRL_DISABLED'"!]
            [!VAR "FtmFltCtrlValue" = "'((uint32) 0),'"!]
        [!ELSE!]
            [!VAR "FtmFilterVal" = "num:i(node:value(PwmFtmChannelFaultSettings/PwmFilterValue))"!]
            [!VAR "FtmFltCtrlValue" = "concat('FTM_FLTCTRL_FFVAL_U32(', $FtmFilterVal, ') | ')"!]
            [!IF "node:value(PwmFtmChannelFaultSettings/PwmFtmFaultOutputState) = 'TRISTATE' "!]
                [!VAR "FtmFltCtrlValue" = "concat($FtmFltCtrlValue, ' FTM_FLTCTRL_FFLTR3EN_TRISTATE_U32 |')"!]
            [!ELSE!]
                [!VAR "FtmFltCtrlValue" = "concat($FtmFltCtrlValue, ' FTM_FLTCTRL_FLTSTATE_SAFEVALUE_U32 |')"!]
            [!ENDIF!]
            [!IF "PwmFtmChannelFaultSettings/PwmDisableOutputOnFault0 = 'true'"!]
                /*write the value of Fault0 enable bit*/
                [!VAR "FtmEnableFlt0" = "'FTM_FLTCTRL_FAULT0EN_ENABLE_U32 | '"!]
                
                /*write the value of Fault0 Filter enable bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmEnableFault0Filter = 'true'"!]
                    [!VAR "FtmEnableFltFilter0" = "'FTM_FLTCTRL_FFLTR0EN_ENABLE_U32 | '"!]              
                [!ENDIF!]
                
                /*write the value of Fault0 polarity bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Polarity = 'true'"!]
                    [!VAR "FtmFault0Polarity" = "'FTM_FLTPOL_FLT0POL_HIGH_U32 | '"!]
                [!ENDIF!]
                
                /*Write Fault0 Notification function name*/
                [!IF "((PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification != 'NULL'))"!]
                    [!VAR "FtmFault0Notif" = "concat('&',PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification)"!]               
                [!ENDIF!]           
            [!ELSE!]
                [!VAR "FtmEnableFlt0" = "''"!]
            [!ENDIF!]
            
            [!IF "PwmFtmChannelFaultSettings/PwmDisableOutputOnFault1 = 'true'"!]
                /*write the value of Fault1 enable bit*/
                [!VAR "FtmEnableFlt1" = "'FTM_FLTCTRL_FAULT1EN_ENABLE_U32 | '"!]
                
                /*write the value of Fault1 Filter enable bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmEnableFault1Filter = 'true'"!]
                    [!VAR "FtmEnableFltFilter1" = "'FTM_FLTCTRL_FFLTR1EN_ENABLE_U32 | '"!]
                [!ENDIF!]
                
                /*write the value of Fault1 polarity bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Polarity = 'true'"!]
                    [!VAR "FtmFault1Polarity" = "'FTM_FLTPOL_FLT1POL_HIGH_U32 | '"!]
                [!ENDIF!]
                
                /*Write Fault1 Notification function name*/
                [!IF "((PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification != 'NULL'))"!]
                    [!VAR "FtmFault1Notif" = "concat('&',PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification)"!]
                [!ENDIF!]           
            [!ELSE!]
                [!VAR "FtmEnableFlt1" = "''"!]
            [!ENDIF!]

            [!IF "PwmFtmChannelFaultSettings/PwmDisableOutputOnFault2 = 'true'"!]
                /*write the value of Fault2 enable bit*/
                [!VAR "FtmEnableFlt2" = "'FTM_FLTCTRL_FAULT2EN_ENABLE_U32 | '"!]
                
                /*write the value of Fault2 Filter enable bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmEnableFault2Filter = 'true'"!]
                    [!VAR "FtmEnableFltFilter2" = "'FTM_FLTCTRL_FFLTR2EN_ENABLE_U32 | '"!]
                [!ENDIF!]
                
                /*write the value of Fault2 polarity bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Polarity = 'true'"!]
                    [!VAR "FtmFault2Polarity" = "'FTM_FLTPOL_FLT2POL_HIGH_U32 | '"!]
                [!ENDIF!]
                
                /*Write Fault2 Notification function name*/
                [!IF "((PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification != 'NULL'))"!]
                    [!VAR "FtmFault2Notif" = "concat('&',PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification)"!]
                [!ENDIF!]           
            [!ELSE!]
                [!VAR "FtmEnableFlt2" = "''"!]
            [!ENDIF!]
     
            [!IF "PwmFtmChannelFaultSettings/PwmDisableOutputOnFault3 = 'true'"!]
                /*write the value of Fault3 enable bit*/
                [!VAR "FtmEnableFlt3" = "'FTM_FLTCTRL_FAULT3EN_ENABLE_U32 | '"!]
                
                /*write the value of Fault3 Filter enable bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmEnableFault3Filter = 'true'"!]
                    [!VAR "FtmEnableFltFilter3" = "'FTM_FLTCTRL_FFLTR3EN_ENABLE_U32 | '"!]
                [!ENDIF!]
                
                /*write the value of Fault3 polarity bit*/
                [!IF "PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Polarity = 'true'"!]
                    [!VAR "FtmFault3Polarity" = "'FTM_FLTPOL_FLT3POL_HIGH_U32 | '"!]
                [!ENDIF!]
                
                /*Write Fault3 Notification function name*/
                [!IF "((PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification != 'NULL'))"!]
                    [!VAR "FtmFault3Notif" = "concat('&',PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification)"!]
                [!ENDIF!]           
            [!ELSE!]
                [!VAR "FtmEnableFlt3" = "''"!]
            [!ENDIF!]

            [!VAR "FtmFltCtrlValue" = "concat('(', $FtmFltCtrlValue, $FtmEnableFltFilter3,  $FtmEnableFltFilter2, $FtmEnableFltFilter1, $FtmEnableFltFilter0, $FtmEnableFlt3, $FtmEnableFlt2, $FtmEnableFlt1,  $FtmEnableFlt0,  '((uint32) 0)),' )"!]
        [!ENDIF!]
    [!ELSE!]    
        [!VAR "FtmFltCtrlValue" =  "'((uint32) 0),'"!]
   [!ENDIF!]
    
    /*write FLTPOL register*/
   [!IF "node:value(../../../PwmGeneral/PwmFaultSupport) = 'true'"!] 
        [!VAR "FtmFltPolValue" = "concat('(', $FtmFault3Polarity, $FtmFault2Polarity,  $FtmFault1Polarity, $FtmFault0Polarity, '((uint32) 0)),' )"!]
   [!ELSE!]
        [!VAR "FtmFltPolValue" =  "'((uint32) 0),'"!]
   [!ENDIF!]     
     /*write MOD register with default period value*/
     /*go through all PWM channels and module references to the current FTM module*/
    [!LOOP "../../PwmChannel/*"!]    
            [!VAR "PwmChannelName" = "node:name(.)"!]  
            /*get the hw FTM module name from the reference */
            [!VAR "FtmRefName" = "node:value(PwmFtmChannel)"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
            [!VAR "FtmRefModName" = "substring-before($FtmRefName,'/')"!]  
            [!VAR "FtmRefModNameFreq" = "substring-before($FtmRefName,'/')"!]  
            [!VAR "McuClockValue" = "node:ref(PwmMcuClockReferencePoint)/McuClockReferencePointFrequency"!]
            
            [!IF "$FtmRefModName = $FtmModContName"!]

            [!CALL "GenerateTimerChannelPeriodInTicks", "McuClockRefFreqValue" = "$McuClockValue", "FtmClockPrescaler" = "$FtmPresValue"!]
                [!VAR "PeriodId" = "$OutVareTimerChannelDefaultPeriod"!]
                [!VAR "FtmPwmPeriodComent" = "$OutVareTimerChannelDefaultPeriodComment"!]     
                /*loop again through all channels and for all other channels using the same module get default period*/
                 [!LOOP "../../PwmChannel/*"!]
               
                    [!CALL "GenerateTimerChannelPeriodInTicks", "McuClockRefFreqValue" = "$McuClockValue", "FtmClockPrescaler" = "$FtmPresValue"!]    

  
                    [!VAR "InnerPeriodId" = "$OutVareTimerChannelDefaultPeriod"!]

                       

              [!VAR "PwmInnerChannelName" = "node:name(.)"!]  
                    /*get the hw FTM module name from the reference */
              [!VAR "FtmInnerRefName" = "node:value(PwmFtmChannel)"!]
                    [!VAR "FtmInnerInnerRefName" = "substring-after($FtmInnerRefName,'/')"!]
                    [!VAR "FtmInnerRefName" = "substring-after($FtmInnerRefName,'/')"!]
                    [!VAR "FtmInnerRefName" = "substring-after($FtmInnerRefName,'/')"!]
                    [!VAR "FtmInnerRefName" = "substring-after($FtmInnerRefName,'/')"!]
                    [!VAR "FtmInnerRefName" = "substring-after($FtmInnerRefName,'/')"!]
                    [!VAR "FtmInnerRefModName" = "substring-before($FtmInnerRefName,'/')"!]  

                    [!IF "$FtmRefModName = $FtmInnerRefModName and $PeriodId != $InnerPeriodId"!]

                       [!CODE!] 
                           [!ERROR!] 
 "Pwm Channel [!"$PwmInnerChannelName"!]  of ConfigSet ["$CurrentConfigSetName"] has a different period value from all other Pwm channels that reference FTM module [!"$FtmRefModName"!]."
                             [!ENDERROR!]                 
                      [!ENDCODE!]
                    [!ENDIF!]      
                [!ENDLOOP!]            
            [!ENDIF!]      
       [!ENDLOOP!]      
     
 [!CODE!]    
  
    /* Ftm Module [!"num:i($CountFtmModules)"!] */
    {
        /** @brief [!"$FtmModName"!]_CONF */
        [!"$FtmConfRegValue"!]
      
        /** @brief [!"$FtmModName"!]_SC register */
        [!"$FtmCSRegValue"!]

        [!IF "../../../PwmGeneral/PwmEnableDualClockMode"!] 
        #if (PWM_SET_CLOCK_MODE_API == STD_ON) 
        /** @brief [!"$FtmModName"!]_SC register */
        [!"$FtmAlternativeCSRegValue"!]
        #endif
        [!ENDIF!]
        
        /** @brief [!"$FtmModName"!]_SYNC register */
        [!"$FtmSYNCRegValue"!]
         
        /** @brief [!"$FtmModName"!]_MODE register used to enable other features of the FTM */
[!ENDCODE!]
        [!IF "$FtmModeFltValue != ''"!]
                [!CODE!]           
        ([!"$FtmModeFltValue"!] (FTM_MODE_INIT_ENABLE_U32 | FTM_MODE_FTMEN_ENABLE_U32 | FTM_MODE_WPDIS_DISABLE_U32 | ((uint32)0))),    
                [!ENDCODE!] 
        [!ELSE!]
                [!CODE!]           
        (FTM_MODE_INIT_ENABLE_U32 | FTM_MODE_FTMEN_ENABLE_U32 | FTM_MODE_WPDIS_DISABLE_U32 | ((uint32)0)),    
                [!ENDCODE!]
        [!ENDIF!]
 [!CODE!]   
 
        /** @brief [!"$FtmModName"!]_DEADTIME register */
        [!"$FtmDTPSValue"!]

        /** @brief [!"$FtmModName"!]_COMBINE register */
        [!"$FtmCombineValue"!]
        
         /** @brief Id of the referenced FTM module: [!"$FtmModName"!] */
        PWM_[!"$FtmModName"!],
        
        /** @brief Default period value: [!"$FtmPwmPeriodComent"!]: [!"$FtmModName"!]_MOD register*/
        ((Pwm_PeriodType) [!"$PeriodId"!])
            
#if (PWM_FAULT_SUPPORTED == STD_ON)
        ,

        /** @brief [!"$FtmModName"!]_FLTCTRL register */
        [!"$FtmFltCtrlValue"!]

        /** @brief [!"$FtmModName"!]_FLTPOL register */
        [!"$FtmFltPolValue"!]
        
        /** @brief Fault notification callbacks */
       { [!"$FtmFault0Notif"!], [!"$FtmFault1Notif"!], [!"$FtmFault2Notif"!], [!"$FtmFault3Notif"!] }
#endif /* (PWM_FAULT_SUPPORTED == STD_ON) */
[!IF "node:value(../../../PwmGeneral/PwmFtmEnableExtTrigger) = 'true'"!]
#if (PWM_FTM_ENABLE_EXT_TRIGGERS == STD_ON)
        ,
        /** @brief [!"$FtmModName"!]_EXTTRIG register */
        [!"$FtmExtTrgChValue"!]
#endif /* (PWM_FTM_ENABLE_EXT_TRIGGERS == STD_ON) */
[!ENDIF!]
        [!VAR "CountFtmModules" = "$CountFtmModules + 1"!]  
            [!IF "$CountFtmModules < $PwmFtmModules "!]
    },     
            [!ELSE!]
    }
            [!ENDIF!]
[!ENDCODE!]    
[!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]


[!CODE!]
/**
@brief Ftm IP configuration
*/
static CONST(Pwm_Ftm_IpConfigType, PWM_CONST) Pwm_Ftm_IpConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /** @brief Number of Ftm channels in each Ftm module used in the current Pwm configuration */
     PWM_CONF_FTM_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
 
    /** @brief Number of Ftm modules in the Pwm configuration */
     PWM_FTM_MOD_CONFIGS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    
    /** @brief Pointer to the array of Ftm enabled Pwm channel configurations */
    &Pwm_Ftm_ChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], 

    /** @brief Pointer to the array of Ftm Module configurations */
    &Pwm_Ftm_ModuleConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [!CR!] 
};

[!ENDCODE!]


[!CODE!]
/** @brief Array of configured Pwm channels */
/*
* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 external ... could be made static
*/
static CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_Channels_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
[!ENDCODE!]
  
    [!FOR "PwmChIndex" = "0" TO "$PwmChannels - 1"!]
    
        [!LOOP "PwmChannel/*"!]

        [!VAR "ChannelName" = "node:name(.)"!]
        [!IF "$PwmChIndex = PwmChannelId"!]
        

           [!IF "node:exists(PwmChannelClass)"!]
               [!VAR "ChannelClass" = "node:value(PwmChannelClass)"!]
               [!IF "$ChannelClass = 'PWM_VARIABLE_PERIOD'"!]
                       [!WARNING!] 
                        "Changing the period of one channel from any FTM module will affect the period of all the channels of that module." 
                        [!ENDWARNING!]
               [!ENDIF!]
           [!ELSE!]
               [!VAR "ChannelClass" = "'PWM_FIXED_PERIOD'"!]
           [!ENDIF!]
            
           [!IF "(node:exists('PwmNotification')) and ((PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL'))"!]
               [!VAR "NotifFunc" = "concat('&', PwmNotification)"!]     
           [!ELSE!]     
               [!VAR "NotifFunc" = "'NULL_PTR'"!]         
           [!ENDIF!]       

               [!BREAK!]
           [!ENDIF!]
        [!ENDLOOP!] 
    
     
    [!CODE!]
   /** @brief [!"$ChannelName"!] */
    {
        /** @brief Channel class: Variable/Fixed/Fixed_Shifted period */
        [!"$ChannelClass"!]
        
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        ,
        
        /** @brief Pwm notification function */
        [!"$NotifFunc"!]
#endif
 
        [!IF "$PwmChIndex < $PwmChannels - 1"!]
    },     
        [!ELSE!]
    }

        [!ENDIF!]

    [!ENDCODE!]
    
    [!ENDFOR!]    
  [!CODE!]
};

[!ENDCODE!]

[!CODE!]

/**
@brief   Pwm channels IP related configuration array
*/
static CONST(Pwm_IpChannelConfigType, PWM_CONST) Pwm_IpChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
[!ENDCODE!]

    [!VAR "VarFtmChannelIndex" = "0"!] 
    
    [!FOR "PwmChIndex" = "0" TO "$PwmChannels - 1"!]
    
        [!LOOP "PwmChannel/*"!]

            [!VAR "ChannelName" = "node:name(.)"!]
            [!IF "$PwmChIndex = PwmChannelId"!]

               [!VAR "FtmRefName" = "node:name(.)"!]  
               [!VAR "FtmRefName" = "node:value(PwmFtmChannel)"!]
               [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
               [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
               [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
               [!VAR "FtmRefCfgName" = "substring-before($FtmRefName,'/')"!]  
               [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
               [!VAR "FtmRefModName" = "substring-before($FtmRefName,'/')"!] 
               [!VAR "FtmRefChanName" = "substring-after($FtmRefName,'/')"!] 
  
              /*go through all FTM channels */
               [!VAR "CountFtmChannels" = "0"!] 

               [!LOOP "../../PwmFtmModule/*/PwmFtmChannels/*"!]
                   [!VAR "FtmChanName" = "node:name(.)"!]  
                   [!VAR "FtmModName" = "node:name(../../.)"!]
                       
                   [!IF "$FtmRefModName = $FtmModName and $FtmRefChanName = $FtmChanName"!]
                        [!VAR "VarFtmChannelIndex" = "$CountFtmChannels"!]
                        [!BREAK!]               
                   [!ENDIF!]
                   [!VAR "CountFtmChannels" = "$CountFtmChannels + 1"!]
               [!ENDLOOP!]
               [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]
   [!CODE!]
    /** @brief [!"$ChannelName"!] */
        [!IF "$PwmChIndex < $PwmChannels"!]
    ((uint8) [!"num:i($VarFtmChannelIndex)"!]),    
        [!ELSE!]
    ((uint8) [!"num:i($VarFtmChannelIndex)"!])
        [!ENDIF!]
    
    [!ENDCODE!]
    [!ENDFOR!]
  [!CODE!]
};


[!ENDCODE!]

[!CODE!]
/**
@brief   Pwm high level configuration structure
*/
/*
* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_2 external ... could be made static
*/
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
CONST(Pwm_ConfigType, Pwm_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ELSE!]
CONST(Pwm_ConfigType, Pwm_CONST) Pwm_PBCfgVariantPredefined =
[!ENDIF!]
{
   /** @brief Number of configured Pwm channels */
    (Pwm_ChannelType)PWM_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /** @brief Pointer to array of Pwm channels */
    &Pwm_Channels_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /** @brief IP specific configuration */
    {             
        /** @brief Pointer to the structure containing Ftm configuration */
        &Pwm_Ftm_IpConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
         /** @brief Pointer to Array containing channel IP related information */
        &Pwm_IpChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] 
        
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    ,
    /** @brief Hw to logic channel map. Array containing a number of elements
    equal to total number of available channels on FTM IPV */
    {
[!FOR "idx" = "0" TO "$numFtmModules - 1"!]
        [!CALL "GenerateFtmHwToLogicMap", "paramFtmModule" = "$idx"!]
        [!"$OutVarHwToLogicComment"!]
        [!"$OutVarHwToLogicArray"!][!IF "$idx < num:i($numFtmModules)-1"!],[!ENDIF!][!CR!]
[!ENDFOR!]
    }
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */ 
};
[!ENDCODE!]

[!ENDNOCODE!]

[!ENDSELECT!]

/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_MemMap.h"



/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!]
