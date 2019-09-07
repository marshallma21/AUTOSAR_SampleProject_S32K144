[!AUTOSPACING!]
[!NOCODE!]

/*!
*   @file    Pwm_NotifyCheck_Src.m
*   @version 1.0.1
*
*   @brief   AUTOSAR Pwm Macros that generate notifications handlers
*   @details Macros that generate notifications handlers prototypes
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


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('PWM_NOTIFY_CHECK_SRC_M'))"!]
[!VAR "PWM_NOTIFY_CHECK_SRC_M"="'true'"!]


/* Variable storing number of Ftm Modules available on the current platform */
[!VAR "numFtmModules" = "ecu:get('Pwm.PwmChannelConfigSet.Num_Ftm_Hw_Modules')"!]

/* This macro generates the list of prototypes of Pwm channel notification handlers */
[!MACRO "GeneratePwmNotifications"!]
  [!CODE!]
/** @brief Prototypes of Pwm channels User Notifications */[!//
  [!ENDCODE!]  
  [!NOCODE!]
  [!VAR "MacOuterLoopCounter" = "0"!]
  [!VAR "MacInnerLoopCounter" = "0"!] 
  /* Loop through all Pwm channels and get name of Notification
  handlers for each of them. Loop the channels twice because there might be
  channels using same MacNotification function and we only want to 
  declare it as external once */
  [!LOOP "./PwmChannel/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!IF "node:exists('PwmNotification')"!]
        [!VAR "MacNotification" = "PwmNotification"!]
        [!LOOP "../../PwmChannel/*"!]
            [!IF "(PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL')"!]
                [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                    [!IF "($MacNotification = PwmNotification)"!]
                        [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
    [!IF "$MacMatchcounter = 1"!]
      [!CODE!]
/* @violates @ref Pwm[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg_C_REF_5 MISRA 2004 Required Rule 8.8, external object or function 
*  shall be declared in one and only one file */      
extern FUNC(void, PWM_CODE)[!"PwmNotification"!](void);[!//      
      [!ENDCODE!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!ENDNOCODE!]
[!ENDMACRO!]

[!NOCODE!]
/* Below there are a couple of macros implementing methods for working with string arrays 
   on top of a simple string. The arrays can store a variable number of string entries,
   each string having a maximum length of 30 chars 
   Each element in the array has exactly 30 chars (which is also the plugin maximum allowed
length for Ftm notification handlers) and is used to store the name of the Ftm
Fault notification handler trailed till 30 chars with '*' */
[!MACRO "ArrayDeclare", "Size"!]
    [!VAR "OutMyArray" = "''"!]
    [!FOR "i" = "1" TO "$Size"!]
        [!VAR "OutMyArray" = "concat($OutMyArray, '******************************')"!]
    [!ENDFOR!]

[!ENDMACRO!]

[!MACRO "ArraySetElement", "Index", "Value"!]
    [!VAR "MacSetElement" = "$Value"!]
    /* Add trailing '*' chars until length of 30 */
    [!FOR "idx" = "string-length($Value)" TO "30"!]
      [!VAR "MacSetElement" = "concat($MacSetElement, '*')"!]
    [!ENDFOR!]
    /* Insert the value prepared for the entry in it's place in the string keeping the array */
    [!IF "$Index = 0"!]
        [!VAR "OutMyArray" = "concat($MacSetElement, substring($OutMyArray,31))"!]
    
    [!ELSE!] 
        [!VAR "OutMyArray" = "concat(substring($OutMyArray,1,$Index*30), $MacSetElement, substring($OutMyArray,$Index*30+31))"!]
    [!ENDIF!]

[!ENDMACRO!]



[!MACRO "ArrayGetElement", "Index"!]
    /* Get the element out the string storring the array and
    remove the trailing '*' chars */
    [!VAR "OutGetElement" = "substring-before(substring($OutMyArray,$Index*30+1,30),'*')"!]
[!ENDMACRO!]



[!VAR "NConfigSets" = "1"!]
 [!VAR "ArraySize" = "$NConfigSets * $numFtmModules  * 4"!]


[!VAR "CurrentPb" = "0"!]
/* This macro generates the list of prototypes of Ftm Modules 
Fault Notification handlers */
 [!ENDNOCODE!]
[!MACRO "GenerateFtmFaultNotifications"!]
[!NOCODE!]
  /* Declare an array storing the names of the Fault Notification handlers 
  for possibly each Ftm module available on the platform. Each Fault
  Notification is limited by the plugin at max 30 chars length */
  [!CALL "ArrayDeclare", "Size" = "num:i($ArraySize)"!]
  
  /* If Fault Notification is globally enabled, loop through all Ftm Modules 
  defined in the configuration. For each Module, insert the 4 Fault notification 
  handlers in the array */
  [!IF "PwmGeneral/PwmFaultSupport = 'true'"!]
    [!CODE!]

/** @brief Prototypes of Ftm Modules Fault Notifications */[!CR!]
    [!ENDCODE!]    
    [!VAR "CurrentIndex" = "0"!]
    
    [!SELECT "PwmChannelConfigSet"!]

        [!LOOP "PwmFtmModule/*"!]  

          /* Check if fault functionality is enabled for the current Ftm Module */
         [!VAR "MacFtmMod" = "substring-after(FtmModule,'FTM_')"!]
    

     [!IF "PwmFtmFaultFunctionality != 'FLTCTRL_DISABLED'"!]        

        /* Check if a valid Fault Notification is defined for fault channel 0 and if yes,
        put it in the array, at corresponding position */
        
        [!IF "node:exists('PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification != 'NULL')"!]
          [!CALL "ArraySetElement", "Index" = "num:i($CurrentIndex)+ (4 * num:i($MacFtmMod))", "Value" = "PwmFtmChannelFaultSettings/PwmFtmChannelFault0Settings/PwmFault0Notification"!]      
        [!ENDIF!]  

         
        /* Check if a valid Fault Notification is defined for fault channel 1 and if yes,
        put it in the array, at corresponding position */
         [!IF "node:exists('PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification != 'NULL')"!]
             [!CALL "ArraySetElement", "Index" = "num:i($CurrentIndex)+ (4 * num:i($MacFtmMod)) + 1", "Value" = "PwmFtmChannelFaultSettings/PwmFtmChannelFault1Settings/PwmFault1Notification"!]
        [!ENDIF!]  

        /* Check if a valid Fault Notification is defined for fault channel 2 and if yes,
        put it in the array, at corresponding position */
        [!IF "node:exists('PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification != 'NULL')"!]
         [!CALL "ArraySetElement", "Index" = "num:i($CurrentIndex)+ (4 * num:i($MacFtmMod)) + 2", "Value" = "PwmFtmChannelFaultSettings/PwmFtmChannelFault2Settings/PwmFault2Notification"!]  
        [!ENDIF!]  

        /* Check if a valid Fault Notification is defined for fault channel 3 and if yes,
        put it in the array, at corresponding position */
        [!IF "node:exists('PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification != 'NULL_PTR') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification != '"NULL"') and (PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification != 'NULL')"!]
             [!CALL "ArraySetElement", "Index" = "num:i($CurrentIndex)+ (4 * num:i($MacFtmMod)) + 3", "Value" = "PwmFtmChannelFaultSettings/PwmFtmChannelFault3Settings/PwmFault3Notification"!]  
        [!ENDIF!]         


      [!ENDIF!]


      [!ENDLOOP!] 

      [!VAR "CurrentIndex" = "$CurrentIndex + (4 * ($numFtmModules))"!]
      [!VAR "CurrentPb" = "$CurrentPb + 1"!]  
  [!ENDSELECT!]

    /* Now that we have all valid Ftm fault notifications in the array, loop through array using
    inner and outer loop counters and identify the unique values, as user could have chosed identic
    names for multiple Ftm Fault Notification handlers */
  [!FOR "MacOuterLoopCounter" = "0" TO "num:i($ArraySize)-1"!]
      [!CALL "ArrayGetElement", "Index" = "$MacOuterLoopCounter"!]
      /* Skip over undefined notifications or notifications that were found to be null */
      

      [!IF "$OutGetElement != ''"!]
        [!VAR "MacMatchcounter" = "0"!]
        [!VAR "MacCurElement" = "$OutGetElement"!]

        [!FOR "MacInnerLoopCounter" = "$MacOuterLoopCounter+1" TO "num:i($ArraySize)-1"!]
          [!CALL "ArrayGetElement", "Index" = "$MacInnerLoopCounter"!]
          [!IF "$MacCurElement = $OutGetElement"!]
             [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!] 
          [!ENDIF!]
        [!ENDFOR!]

        /* If no match was found with any notification following the current one in the array
        check if there is any Pwm channel using the Ftm Module the current notification
        belongs to and in case it is, declare it as external */
    
        [!VAR "ModIndex" = "num:i($MacOuterLoopCounter mod ($numFtmModules * 4))"!]
        [!VAR "ModIndex" = "num:i($ModIndex div 4)"!]
        
        [!VAR "FtmMod" = "(ecu:list('Pwm.PwmChannelConfigSet.PwmFtmModule'))[num:i($ModIndex) + 1]"!]
        [!IF "$MacMatchcounter = 0"!]
        
            [!SELECT "PwmChannelConfigSet"!]

               [!VAR "Matchcounter" = "0"!]    
        [!VAR "CfgSetName" = "node:name(.)"!]
        [!LOOP "PwmChannel/*"!]
                    [!VAR "Matchcounter" = "0"!]          
                    [!VAR "FtmRefName" = "node:name(.)"!]  
                    [!VAR "FtmRefName" = "node:value(PwmFtmChannel)"!]
                    [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
                    [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
                [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
                [!VAR "FtmRefName" = "substring-after($FtmRefName,'/')"!]
                    [!VAR "FtmRefName" = "substring-before($FtmRefName,'/')"!]
                    [!LOOP "../../PwmFtmModule/*"!]
                        [!VAR "FtmModName" = "node:name(.)"!] 

                    [!VAR "FtmHwModName" = "node:value(FtmModule)"!]  

                        [!IF "$FtmModName = $FtmRefName"!]
                 
                             [!IF "$FtmHwModName = $FtmMod"!]                  
                                 [!CODE!]
extern FUNC (void, PWM_CODE)[!"$MacCurElement"!](uint8 ModuleId, uint8 FaultChannel);[!CR!]
                                 [!ENDCODE!]
                                 [!VAR "Matchcounter" = "$Matchcounter + 1"!]
                                 [!BREAK!]    
                             [!ENDIF!]            
                        [!ENDIF!]         
                    [!ENDLOOP!] 

                    [!IF "$Matchcounter = 1"!]
                        [!BREAK!]
                    [!ENDIF!]            
                [!ENDLOOP!] 
                [!IF "$Matchcounter = 1"!]
                    [!BREAK!]
                [!ENDIF!]            
           [!ENDSELECT!] 
        [!ENDIF!]   
       [!ENDIF!]             
    [!ENDFOR!]
  [!ENDIF!]
  [!ENDNOCODE!]
[!ENDMACRO!]


[!ENDIF!] /* Avoid multiple inclusion ENDIF */
[!ENDNOCODE!]
