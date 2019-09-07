[!CODE!][!//
/**
*   @file    Eep_PBcfg.c
*   @implements Eep_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Eep - AUTOSAR Module Eeprom Driver.
*   @details Definitions of all post-build configuration structures.
*
*   @addtogroup EEP
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
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
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
* 
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions involing function pointers must be to/from integral types.
* This violation is due to EEP213.
* 
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This violation is due to EEP213.
* 
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Eep_Cfg.c or Eep_PBcfg.c). There is no need to put the declaration into Eep_Cfg.h and made it 
* accessible for all modules which includes Eep.h/Eep_Cfg.h.
* 
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Could be made static.  
* Making EepInitConfiguration_0 static would make it unaccessible to the application.
*
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier pattern.
* This is just a matter of a symbol specified in the configuration.
* 
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_7
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
* Possible MISRA error if the same callback function or variable name is used in multiple configuration variants. 
* Callback function/variable name is set by the driver user so this cannot be fixed by updating the driver code.*
*
* @section eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* This violation is due to EEP213.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros,
* objects and functions shall not be reused. All defines starting with upper
* letter E are reserved for future use inside <error.h> header file.
* All module define options and enumerations are restricted by smcal coding rules
* 5.6 and 5.8 and must follow format <MSN>_<NAME> where MSN is equal to EEP.
* It was agreed that this violation will not be commented above each line but
* only in header of affected file.
*  
*/

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Eep.h"
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    #include "Dem.h"
[!ENDIF!][!//
[!ENDINDENT!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EEP_VENDOR_ID_CFG_C                      43
#define EEP_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define EEP_AR_RELEASE_MINOR_VERSION_CFG_C       2
#define EEP_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define EEP_SW_MAJOR_VERSION_CFG_C               1
#define EEP_SW_MINOR_VERSION_CFG_C               0
#define EEP_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Eep header file are of the same vendor */
#if (EEP_VENDOR_ID_CFG_C != EEP_VENDOR_ID)
    #error "AutoSar Version Numbers of Eep[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Eep.h have different vendor ids"
#endif
/* Check if current file and Eep header file are of the same Autosar version */
#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG_C    != EEP_AR_RELEASE_MAJOR_VERSION) || \
     (EEP_AR_RELEASE_MINOR_VERSION_CFG_C    != EEP_AR_RELEASE_MINOR_VERSION) || \
     (EEP_AR_RELEASE_REVISION_VERSION_CFG_C != EEP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Eep[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Eep.h are different"
#endif
/* Check if current file and Eep header file are of the same Software version */
#if ((EEP_SW_MAJOR_VERSION_CFG_C != EEP_SW_MAJOR_VERSION) || \
     (EEP_SW_MINOR_VERSION_CFG_C != EEP_SW_MINOR_VERSION) || \
     (EEP_SW_PATCH_VERSION_CFG_C != EEP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Eep[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Eep.h are different"
#endif

[!INDENT "0"!][!//
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    [!WS "1"!]/* Check if source file and Dem header file are of the same version */
    [!WS "1"!]#if ((EEP_AR_RELEASE_MAJOR_VERSION_CFG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
    [!WS "1"!]     (EEP_AR_RELEASE_MINOR_VERSION_CFG_C != DEM_AR_RELEASE_MINOR_VERSION) \
    [!WS "1"!]    )
    [!WS "1"!]#error "AutoSar Version Numbers of Eep[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Dem.h are different"
    [!WS "1"!]#endif
    #endif
[!ENDIF!][!//
[!ENDINDENT!][!//

[!INCLUDE "Eep_VersionCheck.m"!][!//

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
[!NOCODE!][!//
[!VAR "EepIndex0" = "0"!][!//
[!VAR "EepIndex1" = "0"!][!//
[!VAR "EepIndex2" = "0"!][!//
[!VAR "EepIndex3" = "0"!][!//
[!VAR "EepIndex4" = "0"!][!//

[!LOOP "EepInitConfiguration"!][!//
    [!IF "node:exists(EepJobEndNotification)"!][!//
        [!VAR "EepIndex0" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(EepJobErrorNotification)"!][!//
        [!VAR "EepIndex1" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(EepACCallback)"!][!//
        [!VAR "EepIndex2" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(EepStartEepromAccessNotif)"!][!//
        [!VAR "EepIndex3" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(EepFinishedEepromAccessNotif)"!][!//
        [!VAR "EepIndex4" = "1"!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!ENDNOCODE!][!//
[!IF "$EepIndex0 = '1.0' or $EepIndex1 = '1.0' or $EepIndex2 = '1.0' or $EepIndex3 = '1.0' or $EepIndex4 = '1.0'"!][!//
    [!INDENT "0"!]
    
    #define EEP_START_SEC_CODE
    /* 
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
     #include "Eep_MemMap.h"
    
    [!LOOP "text:order(text:split(normalize-space(text:join(EepInitConfiguration/EepJobEndNotification | EepInitConfiguration/EepJobErrorNotification | EepInitConfiguration/EepACCallback | EepInitConfiguration/EepStartEepromAccessNotif | EepInitConfiguration/EepFinishedEepromAccessNotif))))"!][!//

    /* Declaration of Eep notification function ([!"."!]())*/
    /*
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_7 An external object or function shall be declared in one and only one file.
    */
    extern FUNC( void, EEP_CODE ) [!"."!]( void );

    [!ENDLOOP!][!//
    #define EEP_STOP_SEC_CODE
    /* 
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Eep_MemMap.h"
    [!ENDINDENT!][!//
[!ENDIF!][!//
[!INDENT "0"!][!//
[!IF "NonAutosar/EepAcLoadOnJobStart != 'true'"!][!//
    #define EEP_START_SEC_CODE_AC
    /* 
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Eep_MemMap.h"

#ifdef _LINARO_C_S32K14x_     
    /* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
    void Eep_Eeprom_AccessCode(   P2FUNC(void, EEP_CODE, CallBack)( void ),VAR(uint8, AUTOMATIC) u8PageSize ) __attribute__ ((section (".aceep_code_rom")));
#else
    /* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
    void Eep_Eeprom_AccessCode(   P2FUNC(void, EEP_CODE, CallBack)( void ),VAR(uint8, AUTOMATIC) u8PageSize );
#endif /* #ifdef _LINARO_C_S32K14x_ */
    
    #define EEP_STOP_SEC_CODE_AC
    /* 
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Eep_MemMap.h"

[!ENDIF!][!//
[!ENDINDENT!][!//
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!IF "NonAutosar/EepAcLoadOnJobStart = 'true'"!][!//

    [!IF "count(text:grep(EepInitConfiguration/EepAcWritePointer | EepInitConfiguration/EepAcWritePointer, '^(\s*NULL_PTR\s*)|(\s*NULL\s*)$')) != count(EepInitConfiguration) * 2"!][!//
    
        [!INDENT "0"!]
        #define EEP_START_SEC_CODE
        /* 
        * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
        * and comments before '#include'
        */
        #include "Eep_MemMap.h"
             
            [!LOOP "text:order(text:split(normalize-space(text:join(EepInitConfiguration/EepAcWritePointer | EepInitConfiguration/EepAcWritePointer))))"!][!//
           
            [!IF ". != 'NULL_PTR' and . != 'NULL'"!][!//
                /* Declaration of Eep Access Code Pointer ([!"."!])*/
                /*
                 * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_6 Re-use of C90 identifier pattern 
                 * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_7 An external object or function shall be declared in one and only one file.
                 */
                extern uint8 [!"."!];
            
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        #define EEP_STOP_SEC_CODE
        /* 
        * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
        * and comments before '#include'
        */
        #include "Eep_MemMap.h"
        [!ENDINDENT!][!//
    [!ENDIF!][!//

[!ENDIF!][!//

[!NOCODE!][!//
[!VAR "EepDemErrorEnable" = "'false'"!][!//
[!IF "NonAutosar/EepDisableDemReportErrorStatus ='false'"!][!//
    [!VAR "EepDemErrorEnable" = "'true'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('EEP_CFG_GENERIC_MACROS_M4'))"!][!//
    [!VAR "EEP_CFG_GENERIC_MACROS_M4"="'true'"!][!//
    [!MACRO "EepAccCrc","EepData32"!][!//
    [!NOCODE!][!//
    [!IF "65535 < $EepData32"!][!//
        [!VAR "EepCrcReminder" = "bit:or(bit:shl($EepCrcReminder,16),bit:shr($EepData32,16))"!][!//
        [!CALL "EepCalcCrcRemainder16bit"!][!//
    [!ENDIF!][!//
    [!IF "255 < $EepData32"!][!//
        [!VAR "EepCrcReminder" = "bit:or(bit:shl($EepCrcReminder,16),bit:and($EepData32,65535))"!][!//
        [!CALL "EepCalcCrcRemainder16bit"!][!//
    [!ELSE!][!//
        [!VAR "EepCrcReminder" = "bit:or(bit:shl($EepCrcReminder,8),bit:and($EepData32,255))"!][!//
        [!CALL "EepCalcCrcRemainder8bit"!][!//    
    [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepFinishCrc"!][!//
    [!NOCODE!][!//
        [!VAR "EepCrcReminder" = "bit:shl($EepCrcReminder,16)"!][!//
        [!CALL "EepCalcCrcRemainder16bit"!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepCalcCrcRemainder16bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem16CrcPolynomSft" = "2282782720"!][!//
        [!VAR "Rem16LeadingOne" = "2147483648"!][!//
        [!FOR "Rem16Counter"="31" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem16LeadingOne,$EepCrcReminder) = $Rem16LeadingOne"!][!//
                [!VAR "EepCrcReminder"="bit:xor($EepCrcReminder,$Rem16CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem16CrcPolynomSft"="bit:shr($Rem16CrcPolynomSft,1)"!][!//
            [!VAR "Rem16LeadingOne"="bit:shr($Rem16LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepCalcCrcRemainder8bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem8CrcPolynomSft" = "8917120"!][!//
        [!VAR "Rem8LeadingOne" = "8388608"!][!//
        [!FOR "Rem8Counter"="23" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem8LeadingOne,$EepCrcReminder) = $Rem8LeadingOne"!][!//
                [!VAR "EepCrcReminder"="bit:xor($EepCrcReminder,$Rem8CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem8CrcPolynomSft"="bit:shr($Rem8CrcPolynomSft,1)"!][!//
            [!VAR "Rem8LeadingOne"="bit:shr($Rem8LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "EepDemEventCfg","EepDemEventName","EepDelimiter"!][!//
        [!NOCODE!][!//
        [!VAR "DemNodeFound" = "'false'"!][!//        
        [!LOOP "./EepDemEventParameterRefs/*"!][!//
            [!IF "node:name(.)=$EepDemEventName"!][!//
                [!VAR "DemNodeFound" = "'true'"!][!//
                [!IF "not(node:empty(.))"!][!//
                    [!IF "node:exists(node:ref(.))"!][!//                
                        [!IF "node:refvalid(.)"!][!//
                            [!VAR "DemRefName" = "(text:split(normalize-space(node:value(.)),'/'))[last()]"!][!//
                            [!CODE!]{(uint32)STD_ON, DemConf_DemEventParameter_[!"$DemRefName"!]}[!"$EepDelimiter"!]    /* [!"node:name(.)"!] parameters */[!CR!][!ENDCODE!]
                        [!ELSE!][!//
                            [!ERROR "Invalid reference for $EepDemEventName"!][!//
                        [!ENDIF!][!//   
                    [!ELSE!][!//
                        [!ERROR "Invalid reference for $EepDemEventName"!]
                    [!ENDIF!][!//                 
                [!ELSE!][!//
                    [!CODE!]{(uint32)STD_OFF, 0U}[!"$EepDelimiter"!]   /* [!"$EepDemEventName"!] parameters */[!CR!][!ENDCODE!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//        
        [!IF "$DemNodeFound='false'"!]
            [!CODE!]{(uint32)STD_OFF, 0U}[!"$EepDelimiter"!]   /* [!"$EepDemEventName"!] parameters */[!CR!][!ENDCODE!]
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
[!ENDIF!][!//
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('EEP_CFG_SPECIFIC_MACROS_M4'))"!][!//
    [!VAR "EEP_CFG_SPECIFIC_MACROS_M4"="'true'"!][!//

    [!MACRO "EepGetMemifModeValue","EepEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$EepEnumName='MEMIF_MODE_SLOW'"!][!//
            [!VAR "OutMemifModeValue" = "0"!][!//
        [!ELSEIF "$EepEnumName='MEMIF_MODE_FAST'"!][!//
            [!VAR "OutMemifModeValue" = "1"!][!//
        [!ELSE!][!//   
            [!VAR "OutMemifModeValue" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
[!ENDIF!][!//


[!INDENT "0"!][!//

[!LOOP "EepInitConfiguration"!][!//

    #define EEP_START_SEC_CONFIG_DATA_UNSPECIFIED
    /* 
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Eep_MemMap.h"
    [!NOCODE!][!//
    [!VAR "EepCrcReminder" = "0"!][!// reset CRC reminder
    // CRC - Accumulate eDefaultMode
    [!CALL "EepGetMemifModeValue","EepEnumName"="./EepDefaultMode"!][!//
    [!CALL "EepAccCrc","EepData32"="$OutMemifModeValue"!][!//
    // CRC - Accumulate u32MaxReadFastMode
    [!CALL "EepAccCrc","EepData32"="./EepFastReadBlockSize"!][!//
    // CRC - Accumulate u32MaxReadNormalMode
    [!CALL "EepAccCrc","EepData32"="./EepNormalReadBlockSize"!][!//
    // CRC - Accumulate u32MaxWriteFastMode
    [!CALL "EepAccCrc","EepData32"="./EepFastWriteBlockSize"!][!//
    // CRC - Accumulate u32MaxWriteNormalMode
    [!CALL "EepAccCrc","EepData32"="./EepNormalWriteBlockSize"!][!//
    [!ENDNOCODE!][!//
    /**
    * @brief        Structure used to set function pointers notification, working mode
    */
    /* Eep module initialization data ([!"node:name(.)"!])*/
    /* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_5 Could be made static */
    
    CONST(Eep_ConfigType, EEP_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        [!WS "4"!]/* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_2 Conversions involing function pointers must be to/from integral types */
        [!WS "4"!]/* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3 Cast from pointer to pointer */
        [!WS "4"!]/* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
        [!WS "4"!](Eep_Eeprom_AcErasePtrType)[!IF "../NonAutosar/EepAcLoadOnJobStart"!][!IF "normalize-space(./EepAcWritePointer) = 'NULL_PTR' or normalize-space(./EepAcWritePointer) = 'NULL'"!][!"normalize-space(./EepAcWrite)"!]U[!ELSE!]&[!"./EepAcWritePointer"!][!ENDIF!][!ELSE!]&Eep_Eeprom_AccessCode[!ENDIF!], /* EepAcWrite */
        [!WS "4"!]/* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_2 Conversions involing function pointers must be to/from integral types */
        [!WS "4"!]/* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3 Cast from pointer to pointer */
        [!WS "4"!]/* @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
        [!WS "4"!](Eep_Eeprom_AcWritePtrType)[!IF "../NonAutosar/EepAcLoadOnJobStart"!][!IF "normalize-space(./EepAcWritePointer) = 'NULL_PTR' or normalize-space(./EepAcWritePointer) = 'NULL'"!][!"normalize-space(./EepAcWrite)"!]U[!ELSE!]&[!"./EepAcWritePointer"!][!ENDIF!][!ELSE!]&Eep_Eeprom_AccessCode[!ENDIF!], /* EepAcWrite */
        [!WS "4"!][!IF "node:exists(EepACCallback)"!]&[!"./EepACCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* EepACCallback */  
        [!WS "4"!][!IF "node:exists(EepJobEndNotification)"!]&[!"./EepJobEndNotification"!][!ELSE!]NULL_PTR[!ENDIF!], /* EepJobEndNotification */
        [!WS "4"!][!IF "node:exists(EepJobErrorNotification)"!]&[!"./EepJobErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!], /* EepJobErrorNotification */  
        [!WS "4"!][!IF "node:exists(EepStartEepromAccessNotif)"!]&[!"./EepStartEepromAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!], /* EepStartEepromAccessNotif */
        [!WS "4"!][!IF "node:exists(EepFinishedEepromAccessNotif)"!]&[!"./EepFinishedEepromAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!], /* EepFinishedEepromAccessNotif */
        [!WS "4"!][!"./EepDefaultMode"!], /* EepDefaultMode */
        [!WS "4"!][!"./EepFastReadBlockSize"!]U, /* EepFastReadBlockSize */
        [!WS "4"!][!"./EepNormalReadBlockSize"!]U, /* EepNormalReadBlockSize */
        [!WS "4"!][!"./EepFastWriteBlockSize"!]U, /* EepFastWriteBlockSize */
        [!WS "4"!][!"./EepNormalWriteBlockSize"!]U, /* EepNormalWriteBlockSize */
    [!IF "$EepDemErrorEnable"!][!//  
        [!WS "4"!]/**
        [!WS "4"!] * @brief   DEM error parameters
        [!WS "4"!] */
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_COMPARE_FAILED'","EepDelimiter"="','"!][!//
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_ERASE_FAILED'","EepDelimiter"="','"!][!//
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_READ_FAILED'","EepDelimiter"="','"!][!//
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_WRITE_FAILED'","EepDelimiter"="','"!][!//
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_BO_MAINTENANCE'","EepDelimiter"="','"!][!//
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_BO_QUICK_WRITES'","EepDelimiter"="','"!][!//
        [!CALL "EepDemEventCfg","EepDemEventName"="'EEP_E_BO_NORMAL_WRITES'","EepDelimiter"="','"!][!//
    [!ENDIF!][!CALL "EepFinishCrc"!][!//
        [!WS "4"!][!"$EepCrcReminder"!]U /* configCrc */
    };
    #define EEP_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /* 
    * @violates @ref eep_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Eep_MemMap.h"
    
[!ENDLOOP!][!//
[!ENDINDENT!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @}*/
