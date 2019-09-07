[!CODE!][!//
/**
*   @file    Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @implements Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all post-build configuration structures.
*
*   @addtogroup FLS
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
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
* 
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions involing function pointers must be to/from integral types.
* This violation is due to FLS213.
* 
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer to object type
* and a different pointer to object type.
* This violation is due to FLS213.
* 
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Fls_Cfg.c or Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c). There is no need to put the declaration into Fls_Cfg.h and made it 
* accessible for all modules which includes Fls.h/Fls_Cfg.h.
* 
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Could be made static.  
* Making FlsConfigSet_0 static would make it unaccessible to the application.
*
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier pattern.
* This is just a matter of a symbol specified in the configuration.
* 
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_7
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
* Possible MISRA error if the same callback function or variable name is used in multiple configuration variants. 
* Callback function/variable name is set by the driver user so this cannot be fixed by updating the driver code.
*
* @section fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* This violation is due to FLS213.
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
*/

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Reg_eSys_QSPI.h"
#include "Reg_eSys_FLASHC.h"
[!ENDINDENT!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       2
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define FLS_SW_MAJOR_VERSION_CFG_C               1
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Fls.h are different"
#endif

/* Check if current file and Reg_eSys_QSPI header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != ESYS_QSPI_VENDOR_ID)
    #error "Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_QSPI.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_QSPI header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != ESYS_QSPI_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != ESYS_QSPI_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != ESYS_QSPI_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_QSPI.h are different"
#endif
/* Check if current file and Reg_eSys_QSPI header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != ESYS_QSPI_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != ESYS_QSPI_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != ESYS_QSPI_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_QSPI.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Reg_eSys_FLASHC.h are different"
#endif

[!INCLUDE "Fls_VersionCheck.m"!][!//

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
[!INDENT "0"!] [!//
[!IF "node:exists(FlsConfigSet/FlsJobEndNotification) or node:exists(FlsConfigSet/FlsJobErrorNotification) or node:exists(FlsConfigSet/FlsACCallback) or node:exists(FlsConfigSet/FlsStartFlashAccessNotif) or node:exists(FlsConfigSet/FlsFinishedFlashAccessNotif) or node:exists(FlsConfigSet/FlsQspiInitCallout) or node:exists(FlsConfigSet/FlsQspiResetCallout) or node:exists(FlsConfigSet/FlsQspiErrorCheckCallout) or node:exists(FlsConfigSet/FlsQspiEccCheckCallout)"!][!//
    #define FLS_START_SEC_CODE
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"        
    [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsJobEndNotification | FlsConfigSet/FlsJobErrorNotification | FlsConfigSet/FlsACCallback | FlsConfigSet/FlsStartFlashAccessNotif | FlsConfigSet/FlsFinishedFlashAccessNotif | FlsConfigSet/FlsQspiInitCallout | FlsConfigSet/FlsQspiResetCallout))))"!][!// 
        /* Declaration of Fls notification function ([!"."!]())*/
        /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
        extern FUNC( void, FLS_CODE ) [!"."!]( void );
    [!ENDLOOP!][!//
    [!IF "node:exists(FlsConfigSet/FlsQspiErrorCheckCallout)"!][!//
        /* Declaration of Fls notification function ([!"."!]())*/
        /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
        extern FUNC(Std_ReturnType, FLS_CODE ) [!"./FlsConfigSet/FlsQspiErrorCheckCallout"!]
               (
                    VAR(Fls_QspiSectorChType, AUTOMATIC) eQspiSectorChannel
               /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_7 External object should be declared in a single file */     
               );
    [!ENDIF!][!//        
    [!IF "node:exists(FlsConfigSet/FlsQspiEccCheckCallout)"!][!//
        /* Declaration of Fls notification function ([!"."!]())*/
        /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
        extern FUNC(Std_ReturnType, FLS_CODE ) [!"./FlsConfigSet/FlsQspiEccCheckCallout"!]
               (
                    VAR(Fls_QspiSectorChType, AUTOMATIC) eQspiSectorChannel,
                    VAR(Fls_AddressType, AUTOMATIC) u32StartAddr,
                    VAR(Fls_LengthType, AUTOMATIC)  u32DataLength
               /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_7 External object should be declared in a single file */
               );
    [!ENDIF!][!//  
    #define FLS_STOP_SEC_CODE
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
[!ENDIF!][!//
[!ENDINDENT!][!//

[!INDENT "0"!][!//
[!IF "FlsGeneral/FlsAcLoadOnJobStart != 'true'"!][!//
    #define FLS_START_SEC_CODE_AC
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
#ifdef _LINARO_C_S32K14x_ 
    #if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort ) __attribute__ ((section (".acfls_code_rom")));
        #else
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC ) __attribute__ ((section (".acfls_code_rom")));
        #else
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#else
    #if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort );
        #else
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC );
        #else
            /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#endif /* #ifdef _LINARO_C_S32K14x_ */
    
    #define FLS_STOP_SEC_CODE_AC
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"

[!ENDIF!][!//
[!ENDINDENT!][!//
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!IF "FlsGeneral/FlsAcLoadOnJobStart = 'true'"!][!//
 
    [!IF "count(text:grep(FlsConfigSet/FlsAcErasePointer | FlsConfigSet/FlsAcWritePointer, '^(\s*NULL_PTR\s*)|(\s*NULL\s*)$')) != count(FlsConfigSet) * 2"!][!//

        [!INDENT "0"!]
        #define FLS_START_SEC_CODE
        /* 
        * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
        * and comments before '#include'
        */
        #include "Fls_MemMap.h"
          
        [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsAcErasePointer | FlsConfigSet/FlsAcWritePointer))))"!][!//            
            [!IF ". != 'NULL_PTR' and . != 'NULL'"!][!//
                /* Declaration of Fls Access Code Pointer ([!"."!])*/
                /*
                 * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_6 Re-use of C90 identifier pattern 
                 * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_7 An external object or function shall be declared in one and only one file.
                 */
                extern uint8 [!"."!];
            
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        #define FLS_STOP_SEC_CODE
        /* 
        * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
        * and comments before '#include'
        */
        #include "Fls_MemMap.h"
        [!ENDINDENT!][!//
    [!ENDIF!][!//

[!ENDIF!][!//

[!NOCODE!][!//
[!VAR "FlsQspiHyperflashEnVar" = "'false'"!][!//
[!IF "NonAutosar/FlsQspiHyperflashEnable ='true'"!][!//
    [!VAR "FlsQspiHyperflashEnVar" = "'true'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('FLS_CFG_GENERIC_MACROS_M4'))"!][!//
    [!VAR "FLS_CFG_GENERIC_MACROS_M4"="'true'"!][!//
    [!MACRO "FlsAccCrc","FlsData32"!][!//
    [!NOCODE!][!//
    [!IF "65535 < $FlsData32"!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,16),bit:shr($FlsData32,16))"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ENDIF!][!//
    [!IF "255 < $FlsData32"!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,16),bit:and($FlsData32,65535))"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ELSE!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,8),bit:and($FlsData32,255))"!][!//
        [!CALL "FlsCalcCrcRemainder8bit"!][!//    
    [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsFinishCrc"!][!//
    [!NOCODE!][!//
        [!VAR "FlsCrcReminder" = "bit:shl($FlsCrcReminder,16)"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsCalcCrcRemainder16bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem16CrcPolynomSft" = "2282782720"!][!//
        [!VAR "Rem16LeadingOne" = "2147483648"!][!//
        [!FOR "Rem16Counter"="31" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem16LeadingOne,$FlsCrcReminder) = $Rem16LeadingOne"!][!//
                [!VAR "FlsCrcReminder"="bit:xor($FlsCrcReminder,$Rem16CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem16CrcPolynomSft"="bit:shr($Rem16CrcPolynomSft,1)"!][!//
            [!VAR "Rem16LeadingOne"="bit:shr($Rem16LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsCalcCrcRemainder8bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem8CrcPolynomSft" = "8917120"!][!//
        [!VAR "Rem8LeadingOne" = "8388608"!][!//
        [!FOR "Rem8Counter"="23" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem8LeadingOne,$FlsCrcReminder) = $Rem8LeadingOne"!][!//
                [!VAR "FlsCrcReminder"="bit:xor($FlsCrcReminder,$Rem8CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem8CrcPolynomSft"="bit:shr($Rem8CrcPolynomSft,1)"!][!//
            [!VAR "Rem8LeadingOne"="bit:shr($Rem8LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsDemEventCfg","FlsDemEventName","FlsDelimiter"!][!//
        [!NOCODE!][!//
        [!VAR "DemNodeFound" = "'false'"!][!//        
        [!LOOP "./FlsDemEventParameterRefs/*"!][!//
            [!IF "node:name(.)=$FlsDemEventName"!][!//
                [!VAR "DemNodeFound" = "'true'"!][!//
                [!IF "not(node:empty(.))"!][!//
                    [!IF "node:exists(node:ref(.))"!][!//                
                        [!IF "node:refvalid(.)"!][!//
                            [!VAR "DemRefName" = "(text:split(normalize-space(node:value(.)),'/'))[last()]"!][!//
                            [!CODE!]{(uint32)STD_ON, DemConf_DemEventParameter_[!"$DemRefName"!]}[!"$FlsDelimiter"!]    /* [!"node:name(.)"!] parameters */[!CR!][!ENDCODE!]
                        [!ELSE!][!//
                            [!ERROR "Invalid reference for $FlsDemEventName"!][!//
                        [!ENDIF!][!//   
                    [!ELSE!][!//
                        [!ERROR "Invalid reference for $FlsDemEventName"!]
                    [!ENDIF!][!//                 
                [!ELSE!][!//
                    [!CODE!]{(uint32)STD_OFF, 0U}[!"$FlsDelimiter"!]   /* [!"$FlsDemEventName"!] parameters */[!CR!][!ENDCODE!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//        
        [!IF "$DemNodeFound='false'"!]
            [!CODE!]{(uint32)STD_OFF, 0U}[!"$FlsDelimiter"!]   /* [!"$FlsDemEventName"!] parameters */[!CR!][!ENDCODE!]
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetSectorHwCh","FlsHwChName"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsHwChName" = "4294967295"!][!//        
        [!IF "$FlsHwChName='FLS_CH_INTERN'"!][!//
            [!VAR "OutFlsHwChName" = "0"!][!//
        [!ELSEIF "$FlsHwChName='FLS_CH_QSPI'"!][!//
            [!VAR "OutFlsHwChName" = "1"!][!//
        [!ELSE!][!//   
            [!VAR "OutFlsHwChName" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetHwUnitName","FlsHwUnitName"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsHwUnitName" = "4294967295"!][!//        
        [!IF "$FlsHwUnitName='FLS_QSPI_0'"!][!//
            [!VAR "OutFlsHwUnitName" = "0"!][!//
        [!ELSEIF "$FlsHwUnitName='FLS_QSPI_1'"!][!//
            [!VAR "OutFlsHwUnitName" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsHwUnitName" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiReadMode","FlsQspiReadMode"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiReadMode" = "4294967295"!][!//        
        [!IF "$FlsQspiReadMode='FLS_SDR'"!][!//
            [!VAR "OutFlsQspiReadMode" = "0"!][!//
        [!ELSEIF "$FlsQspiReadMode='FLS_DDR'"!][!//
            [!VAR "OutFlsQspiReadMode" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiReadMode" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiSamplingMode","FlsQspiSamplingMode"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiSamplingMode" = "4294967295"!][!//        
        [!IF "$FlsQspiSamplingMode='FLS_INTERNAL_DQS'"!][!//
            [!VAR "OutFlsQspiSamplingMode" = "0"!][!//
        [!ELSEIF "$FlsQspiSamplingMode='FLS_EXTERNAL_DQS'"!][!//
            [!VAR "OutFlsQspiSamplingMode" = "1"!][!// 
        [!ELSEIF "$FlsQspiSamplingMode='FLS_INTERNAL_4X'"!][!//
            [!VAR "OutFlsQspiSamplingMode" = "2"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiSamplingMode" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiSamplingEdge","FlsQspiSamplingEdge"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiSamplingEdge" = "4294967295"!][!//        
        [!IF "$FlsQspiSamplingEdge='FLS_RISING'"!][!//
            [!VAR "OutFlsQspiSamplingEdge" = "0"!][!//
        [!ELSEIF "$FlsQspiSamplingEdge='FLS_FALLING'"!][!//
            [!VAR "OutFlsQspiSamplingEdge" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiSamplingEdge" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiSamplingDly","FlsQspiSamplingDly"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiSamplingDly" = "4294967295"!][!//        
        [!IF "$FlsQspiSamplingDly='FLS_1SAMPLE_DLY'"!][!//
            [!VAR "OutFlsQspiSamplingDly" = "0"!][!//
        [!ELSEIF "$FlsQspiSamplingDly='FLS_2SAMPLE_DLY'"!][!//
            [!VAR "OutFlsQspiSamplingDly" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiSamplingDly" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiIntDqsRefClk","FlsQspiIntDqsRefClk"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiIntDqsRefClk" = "4294967295"!][!//        
        [!IF "$FlsQspiIntDqsRefClk='FLS_INVERTED_CLK'"!][!//
            [!VAR "OutFlsQspiIntDqsRefClk" = "0"!][!//
        [!ELSEIF "$FlsQspiIntDqsRefClk='FLS_NONINVERTED_CLK'"!][!//
            [!VAR "OutFlsQspiIntDqsRefClk" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiIntDqsRefClk" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiCoarseDly","FlsQspiCoarseDly"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiCoarseDly" = "4294967295"!][!//        
        [!IF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_0'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "0"!][!//
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_1_PER_2'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "2"!][!// 
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_1_PER_4'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "3"!][!// 
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_1'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "4"!][!// 
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_3_PER_4'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "5"!][!// 
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_3_PER_2'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "6"!][!// 
        [!ELSEIF "$FlsQspiCoarseDly='FLS_CLK_CYCLES_5_PER_4'"!][!//
            [!VAR "OutFlsQspiCoarseDly" = "7"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiCoarseDly" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiTdh","FlsQspiTdh"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiTdh" = "4294967295"!][!//        
        [!IF "$FlsQspiTdh='FLS_ALIGNED_INT_REF_CLK'"!][!//
            [!VAR "OutFlsQspiTdh" = "0"!][!//
        [!ELSEIF "$FlsQspiTdh='FLS_ALIGNED_2X_CLK'"!][!//
            [!VAR "OutFlsQspiTdh" = "1"!][!// 
        [!ELSEIF "$FlsQspiTdh='FLS_ALIGNED_4X_CLK'"!][!//
            [!VAR "OutFlsQspiTdh" = "2"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiTdh" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiEndian","FlsQspiEndian"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiEndian" = "4294967295"!][!//        
        [!IF "$FlsQspiEndian='FLS_BIG_ENDIAN_64'"!][!//
            [!VAR "OutFlsQspiEndian" = "0"!][!//
        [!ELSEIF "$FlsQspiEndian='FLS_LITTLE_ENDIAN_32'"!][!//
            [!VAR "OutFlsQspiEndian" = "1"!][!// 
        [!ELSEIF "$FlsQspiEndian='FLS_BIG_ENDIAN_32'"!][!//
            [!VAR "OutFlsQspiEndian" = "2"!][!//   
        [!ELSEIF "$FlsQspiEndian='FLS_LITTLE_ENDIAN_64'"!][!//
            [!VAR "OutFlsQspiEndian" = "3"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiEndian" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiReadBufferMode","FlsQspiReadBufferMode"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiReadBufferMode" = "4294967295"!][!//        
        [!IF "$FlsQspiReadBufferMode='FLS_AHB_READ_MODE'"!][!//
            [!VAR "OutFlsQspiReadBufferMode" = "0"!][!//
        [!ELSEIF "$FlsQspiReadBufferMode='FLS_IP_READ_MODE'"!][!//
            [!VAR "OutFlsQspiReadBufferMode" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiReadBufferMode" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiRxBufferAccessMode","FlsQspiRxBufferAccessMode"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiRxBufferAccessMode" = "4294967295"!][!//        
        [!IF "$FlsQspiRxBufferAccessMode='FLS_RXBUFFER_AHB_BUS_ACCESS'"!][!//
            [!VAR "OutFlsQspiRxBufferAccessMode" = "0"!][!//
        [!ELSEIF "$FlsQspiRxBufferAccessMode='FLS_RXBUFFER_IP_BUS_ACCESS'"!][!//
            [!VAR "OutFlsQspiRxBufferAccessMode" = "1"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiRxBufferAccessMode" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiAhbBufferInstance","FlsQspiAhbBufferInstance"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiAhbBufferInstance" = "4294967295"!][!//        
        [!IF "$FlsQspiAhbBufferInstance='AHB_BUFFER_0'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "0"!][!//
        [!ELSEIF "$FlsQspiAhbBufferInstance='AHB_BUFFER_1'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "1"!][!// 
        [!ELSEIF "$FlsQspiAhbBufferInstance='AHB_BUFFER_2'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "2"!][!// 
        [!ELSEIF "$FlsQspiAhbBufferInstance='AHB_BUFFER_3'"!][!//
            [!VAR "OutFlsQspiAhbBufferInstance" = "3"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiAhbBufferInstance" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetLUTInstruction","FlsLUTInstruction"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsLUTInstruction" = "4294967295"!][!//        
        [!IF "$FlsLUTInstruction='FLS_LUT_INSTR_STOP'"!][!//
            [!VAR "OutFlsLUTInstruction" = "0"!][!//
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CMD'"!][!//
            [!VAR "OutFlsLUTInstruction" = "1"!][!// 
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_ADDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "2"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_DUMMY'"!][!//
            [!VAR "OutFlsLUTInstruction" = "3"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE'"!][!//
            [!VAR "OutFlsLUTInstruction" = "4"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE2'"!][!//
            [!VAR "OutFlsLUTInstruction" = "5"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE4'"!][!//
            [!VAR "OutFlsLUTInstruction" = "6"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_READ'"!][!//
            [!VAR "OutFlsLUTInstruction" = "7"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_WRITE'"!][!//
            [!VAR "OutFlsLUTInstruction" = "8"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_JMP_ON_CS'"!][!//
            [!VAR "OutFlsLUTInstruction" = "9"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_ADDR_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "10"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "11"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE2_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "12"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_MODE4_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "13"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_READ_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "14"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_WRITE_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "15"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_DATA_LEARN'"!][!//
            [!VAR "OutFlsLUTInstruction" = "16"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CMD_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "17"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CADDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "18"!][!//  
        [!ELSEIF "$FlsLUTInstruction='FLS_LUT_INSTR_CADDR_DDR'"!][!//
            [!VAR "OutFlsLUTInstruction" = "19"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsLUTInstruction" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetLUTPad","FlsLUTPad"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsLUTPad" = "4294967295"!][!//        
        [!IF "$FlsLUTPad='FLS_LUT_PAD_1_PAD'"!][!//
            [!VAR "OutFlsLUTPad" = "0"!][!//
        [!ELSEIF "$FlsLUTPad='FLS_LUT_PAD_2_PADS'"!][!//
            [!VAR "OutFlsLUTPad" = "1"!][!// 
        [!ELSEIF "$FlsLUTPad='FLS_LUT_PAD_4_PADS'"!][!//
            [!VAR "OutFlsLUTPad" = "2"!][!// 
        [!ELSEIF "$FlsLUTPad='FLS_LUT_PAD_8_PADS'"!][!//
            [!VAR "OutFlsLUTPad" = "4"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsLUTPad" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"!][!//
    [!NOCODE!][!//    
        [!VAR "LutSeqIdNodeFound" = "'false'"!][!//        
        [!LOOP "./FlsQspiLutSeqIdRefs/*"!][!//
            [!IF "node:name(.)=$FlsQspiLutSeqIdName"!][!//
                [!VAR "LutSeqIdNodeFound" = "'true'"!][!//
                [!IF "not(node:empty(.))"!][!//
                    [!IF "node:exists(node:ref(.))"!][!//                
                        [!IF "node:refvalid(.)"!][!//
                            [!CODE!][!"as:ref(.)/FlsLUTIndex"!]U[!ENDCODE!]
                        [!ELSE!][!//
                            [!ERROR "Invalid reference for $FlsQspiLutSeqIdName"!][!//
                        [!ENDIF!][!//   
                    [!ELSE!][!//
                        [!ERROR "Invalid reference for $FlsQspiLutSeqIdName"!]
                    [!ENDIF!][!//                 
                [!ELSE!][!//
                    [!CODE!]0U[!ENDCODE!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//        
        [!IF "$LutSeqIdNodeFound='false'"!]
            [!CODE!]0U[!ENDCODE!]
        [!ENDIF!]  
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetLUTsCount","FlsLUTsCount"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsLUTsCount" = "0"!][!//        
        [!IF "node:exists(./FlsQspiLutSeqIdRefs)"!][!//     If node exists(!= Hyperflash mode), then count the LUTs
            [!VAR "OutFlsLUTsCount" = "$FlsLUTsCount"!][!// 
        [!ELSE!][!// 
            [!VAR "OutFlsLUTsCount" = "0"!][!// 
        [!ENDIF!][!// 
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!//
    [!//
    [!MACRO "FlsCalcCrc"!][!//
        [!NOCODE!][!//
        [!VAR "FlsCrcReminder" = "0"!][!// Reset CRC reminder
            
        /* CRC - Accumulate eDefaultMode*/
            [!CALL "FlsGetMemifModeValue","FlsEnumName"="./FlsDefaultMode"!][!//
            [!CALL "FlsAccCrc","FlsData32"="$OutMemifModeValue"!][!//
        /* CRC - Accumulate u32MaxReadFastMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxReadFastMode"!][!//
        /* CRC - Accumulate u32MaxReadNormalMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxReadNormalMode"!][!//
        /* CRC - Accumulate u32MaxWriteFastMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxWriteFastMode"!][!//
        /* CRC - Accumulate u32MaxWriteNormalMode*/
            [!CALL "FlsAccCrc","FlsData32"="./FlsMaxWriteNormalMode"!][!//
        /* CRC - Accumulate u32SectorCount */
            [!CALL "FlsAccCrc","FlsData32"="num:i(count(FlsSectorList/FlsSector/*))"!][!//
                   [!VAR "FlsQspiSectors" = "0"!][!// The configuration contains external QSPI sectors or not.
        [[!IF "ecu:get('Fls.External.Qspi.Available') = 'STD_ON'"!]
                                    [!IF "../NonAutosar/FlsExternalSectorsConfigured"!]
                                        [!VAR "FlsQspiSectors" = "1"!]
                    [!ENDIF!]
        [!ENDIF!] 
             /* Iterate through the sector-dependent params */
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!// Iterate through the sector-dependent params.
            /* CRC - Accumulate paSectorEndAddr */
                [!CALL "FlsAccCrc","FlsData32"="num:i(./FlsSectorSize + ./FlsSectorStartaddress - 1)"!][!//    
            /* CRC - Accumulate pSectorList */
                [!IF "text:contains(string(./FlsPhysicalSector),'FLS_EXT_')"!][!//
                [!ELSE!][!//
                    [!CALL "FlsGetSectorId","FlsEnumName"="./FlsPhysicalSector"!][!//
                    [!CALL "FlsAccCrc","FlsData32"="$OutFlsSectorId"!][!//  
                [!ENDIF!][!// 
            /* CRC - Accumulate paSectorFlags */            
                [!VAR "FlsFlag" = "0"!][!//
                [!IF "./FlsSectorEraseAsynch"!]
                    [!VAR "FlsFlag" = "1"!]
                [!ENDIF!][!//
                
                [!IF "./FlsPageWriteAsynch"!]
                    [!IF "$FlsFlag = 1"!]
                        [!VAR "FlsFlag" = "3"!]
                    [!ELSE!]
                        [!VAR "FlsFlag" = "2"!]
                    [!ENDIF!]
                [!ENDIF!][!//
                
                [!IF "./FlsSectorIrqMode"!]
                    [!IF "$FlsFlag = 0"!]
                        [!VAR "FlsFlag" = "4"!]
                    [!ELSEIF "$FlsFlag = 1"!]
                        [!VAR "FlsFlag" = "5"!]
                    [!ELSEIF "$FlsFlag = 2"!]
                        [!VAR "FlsFlag" = "6"!]
                    [!ELSEIF "$FlsFlag = 3"!]
                        [!VAR "FlsFlag" = "7"!]
                    [!ENDIF!]
                [!ENDIF!][!//                
                [!CALL "FlsAccCrc","FlsData32"="$FlsFlag"!][!//
            /* CRC - Accumulate paSectorProgSize */
                [!CALL "FlsGetWritePageSizeValue","FlsEnumName"="./FlsProgrammingSize"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutWritePageSize"!][!// 
            /* CRC - Accumulate paSectorUnlock */
                [!IF "./FlsPhysicalSectorUnlock"!][!VAR "FlsSectorUnlock"="1"!][!ELSE!][!VAR "FlsSectorUnlock"="0"!][!ENDIF!][!//
                [!CALL "FlsAccCrc","FlsData32"="$FlsSectorUnlock"!][!//
                [!IF " $FlsQspiSectors = 1"!][!//                
            /* CRC - Accumulate paHwCh */
                [!CALL "FlsGetSectorHwCh","FlsHwChName"="./FlsHwCh"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsHwChName"!][!//   
            /* CRC - Accumulate paSectorHwAddress */
                [!CALL "FlsAccCrc","FlsData32"="./FlsSectorHwAddress"!][!// 
                [!ENDIF!][!//
        [!ENDLOOP!][!// 
             
        [!IF " $FlsQspiSectors = 1"!][!//
        [!LOOP "FlsExternalDriver/FlsHwUnit/*"!][!// /* Iterate through the external qspi hw units related params, if any is configured. */           
            /* CRC - Accumulate eHwUnitName */
                [!CALL "FlsGetHwUnitName","FlsHwUnitName"="./FlsHwUnitName"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsHwUnitName"!][!//     
            /* CRC - Accumulate eQspiUnitReadMode*/
                [!CALL "FlsGetQspiReadMode","FlsQspiReadMode"="./FlsHwUnitReadMode"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiReadMode"!][!//
            /* CRC - Accumulate eQspiUnitSamplingEdge */   
                [!CALL "FlsGetQspiSamplingEdge","FlsQspiSamplingEdge"="./FlsHwUnitSamplingEdge"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiSamplingEdge"!][!//
            /* CRC - Accumulate eQspiUnitSamplingDly */   
                [!CALL "FlsGetQspiSamplingDly","FlsQspiSamplingDly"="./FlsHwUnitSamplingDly"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiSamplingDly"!][!//
            /* CRC - Accumulate u8QspiUnitSamplingPoint */
                [!CALL "FlsAccCrc","FlsData32"="./FlsHwUnitSamplingPoint"!][!//
            /* CRC - Accumulate bQspiUnitDqsLatencyEn */   
                [!IF "./FlsHwUnitDqsLatencyEnable"!][!VAR "FlsFlag" = "1"!][!ELSE!][!VAR "FlsFlag" = "0"!][!ENDIF!]
                [!CALL "FlsAccCrc","FlsData32"="$FlsFlag"!][!//
                    /* CRC - Accumulate u8QspiUnitFineDlyA*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsHwUnitFineDelayA"!][!//
            /* CRC - Accumulate u8QspiUnitFineDlyB*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsHwUnitFineDelayB"!][!//
            /* CRC - Accumulate eQspiUnitTdh*/
                [!CALL "FlsGetQspiTdh","FlsQspiTdh"="./FlsHwUnitTdh"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiTdh"!][!//
            /* CRC - Accumulate u8QspiUnitTcsh*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsHwUnitTcsh"!][!//
            /* CRC - Accumulate u8QspiUnitTcss*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsHwUnitTcss"!][!//
            /* CRC - Accumulate eQspiUnitEndian*/
                [!CALL "FlsGetQspiEndian","FlsQspiEndian"="./FlsHwUnitEndianness"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiEndian"!][!//
            /* CRC - Accumulate eQspiUnitReadBufferMode*/
                [!CALL "FlsGetQspiReadBufferMode","FlsQspiReadBufferMode"="./FlsHwUnitReadBufferMode"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiReadBufferMode"!][!//
            /* CRC - Accumulate eQspiUnitRxBufferAccessMode*/
                [!CALL "FlsGetQspiRxBufferAccessMode","FlsQspiRxBufferAccessMode"="./FlsHwUnitRxBufferAccessMode"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiRxBufferAccessMode"!][!//
            [!//            
                [!VAR "FlsAhbBufferCount" = "0"!][!//
                [!VAR "FlsAhbBufferAllMasters" = "'false'"!][!// 
                [!IF "FlsHwUnitReadBufferMode='FLS_AHB_READ_MODE'"!]
                    [!LOOP "./FlsAhbBuffer/*"!][!//
                    /* CRC - Accumulate paQspiUnitAhbBuffer*/
                        [!CALL "FlsGetQspiAhbBufferInstance","FlsQspiAhbBufferInstance"="./FlsAhbBufferInstance"!][!//
                        [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiAhbBufferInstance"!][!//    
                    /* CRC - Accumulate paQspiUnitAhbBufferMasterId*/
                        [!CALL "FlsGetQspiAhbBufferMstId","FlsQspiAhbBufferMstId"="./FlsAhbBufferMasterId"!][!//
                        [!CALL "FlsAccCrc","FlsData32"="$OutFlsQspiAhbBufferMstId"!][!//      
                    /* CRC - Accumulate paQspiUnitAhbBufferSize*/
                        [!CALL "FlsAccCrc","FlsData32"="./FlsAhbBufferSize"!][!//        
                    /* CRC - Accumulate paQspiUnitAhbBufferDataTransferSize*/
                        [!CALL "FlsAccCrc","FlsData32"="./FlsAhbBufferDataTransferSize"!][!//
                        [!//
                        [!VAR "FlsAhbBufferCount" = "$FlsAhbBufferCount + 1"!][!//
                        [!IF "./FlsAhbBufferAllMasters = 'true'"!][!//
                            [!VAR "FlsAhbBufferAllMasters" = "'true'"!][!//
                        [!ENDIF!][!//
                    [!ENDLOOP!][!// 
                    /* CRC - Accumulate bHwUnitAhbBufferAllMasters*/
                        [!IF "$FlsAhbBufferAllMasters = 'true'"!][!VAR "FlsFlag" = "1"!][!ELSE!][!VAR "FlsFlag" = "0"!][!ENDIF!][!//
                        [!CALL "FlsAccCrc","FlsData32"="$FlsFlag"!][!//
                    /* CRC - Accumulate u8QspiUnitAhbBufferCount*/
                        [!CALL "FlsAccCrc","FlsData32"="$FlsAhbBufferCount"!][!//
                [!ENDIF!]
            /* CRC - Accumulate paQspiUnitSerialAddrMapping*/
                [!CALL "FlsAccCrc","FlsData32"="(node:value(./FlsSerialFlashA1TopAddr))"!][!//
                [!CALL "FlsAccCrc","FlsData32"="(node:value(./FlsSerialFlashA2TopAddr))"!][!//
                [!CALL "FlsAccCrc","FlsData32"="(node:value(./FlsSerialFlashB1TopAddr))"!][!//
                [!CALL "FlsAccCrc","FlsData32"="(node:value(./FlsSerialFlashB2TopAddr))"!][!//       
            /* CRC - Accumulate u8QspiUnitColumnAddressWidth*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsHwUnitColumnAddressWidth"!][!//
            /* CRC - Accumulate bQspiUnitWordAddressable */   
                [!IF "./FlsHwUnitWordAddressable"!][!VAR "FlsFlag" = "1"!][!ELSE!][!VAR "FlsFlag" = "0"!][!ENDIF!][!//
                [!CALL "FlsAccCrc","FlsData32"="$FlsFlag"!][!// 
            /* CRC - Accumulate u8QspiUnitRegisterWidth*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsExtUnitRegWidth"!][!//
            /* CRC - Accumulate u8QspiUnitBusyBitValue*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsBusyBitValue"!][!//
            /* CRC - Accumulate u8QspiUnitBusyBitPosOffset*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsBusyBitPositionOffset"!][!//
            /* CRC - Accumulate u8QspiHyperflashLatCycls*/
                [!CALL "FlsAccCrc","FlsData32"="./FlsQspiHyperflashLatencyCycles"!][!//
            [!//
            [!IF "$FlsQspiHyperflashEnVar='false'"!]
                [!LOOP "node:order(FlsLUT/*,'node:value(./FlsLUTIndex)')"!][!//
                    [!LOOP "node:order(FlsInstructionOperandPair/*,'node:value(./FlsInstrOperPairIndex)')"!][!//
                        /* CRC - Accumulate LUT Instruction/Operand pair */
                        [!CALL "FlsGetLUTInstruction","FlsLUTInstruction"="./FlsLUTInstruction"!][!//
                        [!CALL "FlsGetLUTPad","FlsLUTPad"="./FlsLUTPad"!][!//            
                        [!CALL "FlsAccCrc","FlsData32"="bit:or(bit:or(bit:shl($OutFlsLUTInstruction, 10), bit:shl($OutFlsLUTPad, 8)), (./FlsLUTOperand))"!][!//
                    [!ENDLOOP!][!//
                [!ENDLOOP!][!//
            [!ENDIF!]    
            /* CRC - Accumulate u8QspiLUTSeqsCount*/
                [!CALL "FlsGetLUTsCount","FlsLUTsCount"="num:i(count(FlsLUT/*))"!][!//
                [!CALL "FlsAccCrc","FlsData32"="$OutFlsLUTsCount"!][!//
            /* CRC - Accumulate u8QspiLUTGetStatusSeq*/
                [!IF "($FlsQspiHyperflashEnVar='false') and (node:exists(./FlsQspiLutSeqIdRefs))"!]
                    [!CALL "FlsAccCrc","FlsData32"="as:ref(./FlsQspiLutSeqIdRefs/FlsLUTGetStatusSequenceIdRef)/FlsLUTIndex"!][!// 
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32"="0"!][!//
                [!ENDIF!]
            /* CRC - Accumulate u8QspiLUTReadSeq*/
                [!IF "($FlsQspiHyperflashEnVar='false') and (node:exists(./FlsQspiLutSeqIdRefs))"!]
                    [!CALL "FlsAccCrc","FlsData32"="as:ref(./FlsQspiLutSeqIdRefs/FlsLUTReadSequenceIdRef)/FlsLUTIndex"!][!// 
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32"="0"!][!//
                [!ENDIF!]
            /* CRC - Accumulate u8QspiLUTWriteEnSeq*/
                [!IF "($FlsQspiHyperflashEnVar='false') and (node:exists(./FlsQspiLutSeqIdRefs))"!]
                    [!CALL "FlsAccCrc","FlsData32"="as:ref(./FlsQspiLutSeqIdRefs/FlsLUTWriteEnableSequenceIdRef)/FlsLUTIndex"!][!// 
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32"="0"!][!//
                [!ENDIF!]
            /* CRC - Accumulate u8QspiLUTWriteSeq*/
                [!IF "($FlsQspiHyperflashEnVar='false') and (node:exists(./FlsQspiLutSeqIdRefs))"!]
                    [!CALL "FlsAccCrc","FlsData32"="as:ref(./FlsQspiLutSeqIdRefs/FlsLUTWriteSequenceIdRef)/FlsLUTIndex"!][!// 
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32"="0"!][!//
                [!ENDIF!]
            /* CRC - Accumulate u8QspiLUTEraseSeq*/
                [!IF "($FlsQspiHyperflashEnVar='false') and (node:exists(./FlsQspiLutSeqIdRefs))"!]
                    [!CALL "FlsAccCrc","FlsData32"="as:ref(./FlsQspiLutSeqIdRefs/FlsLUTEraseSequenceIdRef)/FlsLUTIndex"!][!// 
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32"="0"!][!//
                [!ENDIF!]
            /* CRC - Accumulate u8QspiLUTReadIdSeq*/
                [!IF "($FlsQspiHyperflashEnVar='false') and (node:exists(./FlsQspiLutSeqIdRefs)) and (node:exists(./FlsQspiLutSeqIdRefs/FlsLUTReadIdSequenceIdRef))"!]
                    [!CALL "FlsAccCrc","FlsData32"="as:ref(./FlsQspiLutSeqIdRefs/FlsLUTReadIdSequenceIdRef)/FlsLUTIndex"!][!// 
                [!ELSE!]
                    [!CALL "FlsAccCrc","FlsData32"="0"!][!//
                [!ENDIF!]
        [!ENDLOOP!][!//
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
[!ENDIF!][!//
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('FLS_CFG_SPECIFIC_MACROS_M4'))"!][!//
    [!VAR "FLS_CFG_SPECIFIC_MACROS_M4"="'true'"!][!//
    [!MACRO "FlsGetWritePageSizeValue","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='FLS_WRITE_DOUBLE_WORD'"!][!//
            [!VAR "OutWritePageSize" = "8"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "32"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_QUAD_PAGE'"!][!//       
            [!VAR "OutWritePageSize" = "128"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_128BYTES_PAGE'"!][!//       
            [!VAR "OutWritePageSize" = "128"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_256BYTES_PAGE'"!][!//       
            [!VAR "OutWritePageSize" = "256"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_512BYTES_PAGE'"!][!//       
            [!VAR "OutWritePageSize" = "512"!][!//
        [!ELSE!][!//   
            [!VAR "OutWritePageSize" = "0"!][!//
        [!ENDIF!][!//   
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsGetSectorId","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!VAR "OutFlsSectorId" = "4294967295"!][!//
        [!VAR "LocationStartCodeSector" = "0"!][!//
        [!VAR "SectorTotal" = "num:i(count(ecu:list('Fls.Sector.Physical.List')))"!][!//
        [!FOR "LocCount" = "1" TO "num:i(count(ecu:list('Fls.Sector.Physical.List')))"!][!//
            [!IF "contains((ecu:list('Fls.Sector.Physical.List')[num:i($LocCount)]), 'DATA') = 'true'"!][!//
                 [!VAR "LocationStartCodeSector" = "$LocationStartCodeSector + 1"!][!//
            [!ENDIF!][!//
            [!IF "(substring-after((ecu:list('Fls.Sector.Physical.List')[num:i($LocCount)]), '_') = $FlsEnumName)"!][!//
                [!VAR "OutFlsSectorId" = "$LocCount - 1"!][!//
            [!ENDIF!][!//
        [!ENDFOR!][//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
[!INDENT "0"!][!//    
    [!MACRO "FlsPhysicalSectorlist","DFlashSizeToTal","PFlashSizeToTal","DFlashSectorSize","PFlashSectorSize"!][!//
    [!IF "contains(./FlsPhysicalSector,'DATA') = 'true'"!][!// DFlash :total size DFlashSizeToTal with each sector size DFlashSectorSize ( DFlashSizeToTal(total size)/8bit(FDPROT)/DFlashSectorSize(each sector) = x (each bit for FDPORT will protect x sectors) )
       [!WS "4"!](volatile uint32*)(D_FLASH_BASE_ADDR + [!"num:inttohex(num:i($OutFlsSectorId * $DFlashSectorSize),6)"!]UL),    /* sectorStartAddressPtr */
        [!WS "4"!][!"num:i($OutFlsSectorId)"!]U  /* Sector location to calculate cfgCRC */              
    [!ELSE!][!// Program Flash: total size PFlashSizeToTal each sector size PFlashSectorSize Kbytes ( PFlashSizeToTal(total size)/32bit(FPROT)/PFlashSectorSize(each sector) = x (each bit for FPROT will protect x sectors) and each FPROT[] will protect x(sectors) *8 bit = 8.x sectors)< - > ($OutFlsSectorId - $LocationStartCodeSector) location start from 0 of the CODE sector in resource file
        [!WS "4"!](volatile uint32*)(P_FLASH_BASE_ADDR + [!"num:inttohex(num:i(($OutFlsSectorId -$LocationStartCodeSector) * $PFlashSectorSize),6)"!]UL),    /* sectorStartAddressPtr */
        [!WS "4"!][!"num:i($OutFlsSectorId)"!]U    /* Sector location to calculate cfgCRC */            
    [!ENDIF!][!//
    [!ENDMACRO!][!//
[!ENDINDENT!][!//
    [!//    
    [!MACRO "FlsGetMemifModeValue","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='MEMIF_MODE_SLOW'"!][!//
            [!VAR "OutMemifModeValue" = "0"!][!//
        [!ELSEIF "$FlsEnumName='MEMIF_MODE_FAST'"!][!//
            [!VAR "OutMemifModeValue" = "1"!][!//
        [!ELSE!][!//   
            [!VAR "OutMemifModeValue" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
    [!MACRO "FlsGetQspiAhbBufferMstId","FlsQspiAhbBufferMstId"!][!//
    [!NOCODE!][!//    
        [!VAR "OutFlsQspiAhbBufferMstId" = "4294967295"!][!//        
        [!IF "$FlsQspiAhbBufferMstId='FLS_CORTEX_M4_CODE'"!][!//
            [!VAR "OutFlsQspiAhbBufferMstId" = "0"!][!//
        [!ELSEIF "$FlsQspiAhbBufferMstId='FLS_CORTEX_M4_SYS'"!][!//
            [!VAR "OutFlsQspiAhbBufferMstId" = "1"!][!// 
        [!ELSEIF "$FlsQspiAhbBufferMstId='FLS_DMA'"!][!//
            [!VAR "OutFlsQspiAhbBufferMstId" = "2"!][!// 
        [!ELSEIF "$FlsQspiAhbBufferMstId='FLS_ENET'"!][!//
            [!VAR "OutFlsQspiAhbBufferMstId" = "3"!][!//        
        [!ELSE!][!//   
            [!VAR "OutFlsQspiAhbBufferMstId" = "4294967295"!][!//
        [!ENDIF!][!//        
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!//
[!ENDIF!][!//


[!INDENT "0"!][!//

[!LOOP "FlsConfigSet"!][!//
[!AUTOSPACING!]
[!VAR "Current_ConfigSet"="@name"!]
[!VAR "FlsAhbBufferCount" = "0"!][!//
[!VAR "FlsLUTSeqsCount" = "0"!][!//
    
    #define FLS_START_SEC_CONFIG_DATA_8
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    /* aFlsSectorFlags[] ([!"node:name(.)"!]) */
    static CONST(uint8, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorFlags[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!VAR "FlsFlag" = "0"!][!//
        [!IF "./FlsSectorEraseAsynch"!][!WS "4"!]FLS_SECTOR_ERASE_ASYNCH[!VAR "FlsFlag" = "1"!][!ENDIF!][!//
        [!IF "./FlsPageWriteAsynch"!][!IF "$FlsFlag = 1"!] | [!ELSE!][!WS "4"!][!VAR "FlsFlag" = "1"!][!ENDIF!]FLS_PAGE_WRITE_ASYNCH[!ENDIF!][!//
        [!IF "./FlsSectorIrqMode"!][!IF "$FlsFlag = 1"!] | [!ELSE!][!WS "4"!][!VAR "FlsFlag" = "1"!][!ENDIF!]FLS_SECTOR_IRQ_MODE[!ENDIF!][!//
        [!IF "$FlsFlag = 0"!][!WS "4"!]0U[!ENDIF!]        
        [!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
    /* aFlsSectorUnlock[] ([!"node:name(.)"!]) */
    static CONST(uint8, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorUnlock[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!][!IF "./FlsPhysicalSectorUnlock"!]1U[!ELSE!]0U[!ENDIF!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
    #define FLS_STOP_SEC_CONFIG_DATA_8
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
    #define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    /* aFlsSectorEndAddr[] ([!"node:name(.)"!]) */
    static CONST(Fls_AddressType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorEndAddr[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_AddressType)[!"num:i(./FlsSectorSize + ./FlsSectorStartaddress - 1)"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* FlsSectorEndAddr ([!"node:name(.)"!])*/
    [!ENDLOOP!][!//
    };
     
    /* paSectorProgSize[] ([!"node:name(.)"!]) */
    static CONST(Fls_LengthType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsProgSize[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_LengthType)[!"./FlsProgrammingSize"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* FlsProgrammingSize ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };

    
    /* paSectorPageSize[] ([!"node:name(.)"!]) */
   static CONST(Fls_LengthType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorPageSize[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
   {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_LengthType)[!"./FlsPageSize"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* FlsPageSize ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
   };
    
    
    [!// /* Create an Info structure(reg prot, ecc trigger, etc) for each internal flash sector. */
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//     /* Loop all configured sectors. */
        [!IF "not(text:contains(string(./FlsPhysicalSector),'FLS_EXT_'))"!][!//                    /* If the current sector is an internal flash one. */
            static CONST(Fls_Flash_InternalSectorInfoType, FLS_CONST) [!"node:name(.)"!]_[!"node:name(./../../..)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_sInternalSectorInfo =
            [!WS "0"!]{
                [!CALL "FlsGetSectorId","FlsEnumName"="./FlsPhysicalSector"!][!//       /* Returns $OutFlsSectorId, which is the flash sector position inside the entire sector list, used for unique identification for CRC calculation. */
                [!WS "4"!]/* 
                [!WS "4"!]* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types 
                [!WS "4"!]* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.
                [!WS "4"!]*/
                [!IF "ecu:has('Fls.k142PhysicalSectorAvailable')"!][!//
                    [!CALL "FlsPhysicalSectorlist","DFlashSizeToTal"="65536","PFlashSizeToTal"="262144","DFlashSectorSize"="2048","PFlashSectorSize"="2048"!][!//DFlash:64kB(65536 byte)     PFlash :256KB(262144 byte)  DFlashSectorSize:2kB (2048 byte) PFlashSectorSize:2kB(2048 byte)   
                [!ELSEIF "ecu:has('Fls.k144PhysicalSectorAvailable')"!][!//
                    [!CALL "FlsPhysicalSectorlist","DFlashSizeToTal"="65536","PFlashSizeToTal"="524288","DFlashSectorSize"="2048","PFlashSectorSize"="4096"!][!//DFlash:64kB(65536 byte)    PFlash :512KB(524288 byte)  DFlashSectorSize:2kB (2048 byte) PFlashSectorSize:2kB(4096 byte)
                [!ELSEIF "ecu:has('Fls.k118PhysicalSectorAvailable')"!][!//
                    [!CALL "FlsPhysicalSectorlist","DFlashSizeToTal"="65536","PFlashSizeToTal"="262144","DFlashSectorSize"="2048","PFlashSectorSize"="2048"!][!//DFlash:64kB(65536 byte)    PFlash :256KB(262144 byte)  DFlashSectorSize:2kB (2048 byte) PFlashSectorSize:2kB(2048 byte)
                [!ELSEIF "ecu:has('Fls.k146PhysicalSectorAvailable')"!][!//
                    [!CALL "FlsPhysicalSectorlist","DFlashSizeToTal"="65536","PFlashSizeToTal"="1048576","DFlashSectorSize"="2048","PFlashSectorSize"="4096"!][!//DFlash:64kB(65536 byte)    PFlash :1 MB (1048576 byte)  DFlashSectorSize:2kB (2048 byte) PFlashSectorSize:2kB(4096 byte)
                [!ELSEIF "ecu:has('Fls.k148PhysicalSectorAvailable')"!][!//
                    [!CALL "FlsPhysicalSectorlist","DFlashSizeToTal"="524288","PFlashSizeToTal"="1572864","DFlashSectorSize"="4096","PFlashSectorSize"="4096"!][!//DFlash:512kB(524288 byte)    PFlash :1.5MB(1572864 byte)  DFlashSectorSize:2kB (4096 byte) PFlashSectorSize:2kB(4096 byte)
                [!ELSEIF "ecu:has('Fls.Flashv2SectorInfoAvailable')"!][!//
                    [!CALL "FlsPhysicalSectorlist"!][!// Returns all the secter information which are configed.
                [!ENDIF!][!//
            [!WS "0"!]};
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    
    /*  FLASH physical sectorization description */
        static CONSTP2CONST(Fls_Flash_InternalSectorInfoType, FLS_VAR, FLS_APPL_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aSectorList[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
        {
        [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!]/* [!"./FlsPhysicalSector"!] */
        [!IF "text:contains(string(./FlsPhysicalSector),'FLS_EXT_')"!][!//
            [!WS "4"!]NULL_PTR
        [!ELSE!][!//
            [!WS "4"!]&[!"node:name(.)"!]_[!"node:name(./../../..)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_sInternalSectorInfo[!// 
        [!ENDIF!][!IF "$FlsLoopIt != 0"!][!WS "4"!],[!ENDIF!][!// 
        [!ENDLOOP!][!//
        };

        
    /* External QSPI flash parameters. */
     
    /* paHwCh[] ([!"node:name(.)"!]) */
    static CONST(Fls_HwChType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paHwCh[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!][!"./FlsHwCh"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
        
    /* paSectorHwAddress[] ([!"node:name(.)"!]) */
    static CONST(Fls_AddressType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paSectorHwAddress[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!WS "4"!](Fls_AddressType)[!"./FlsSectorHwAddress"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
        
    
    [!IF "num:i(count(FlsExternalDriver/FlsHwUnit/*)) != 0"!][!// /* If there is any QSPI hardware unit configured */        
        [!// 
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
            [!ASSERT "../../../FlsMaxWriteNormalMode mod ./FlsPageSize = 0"!][!//
                Error: FlsMaxWriteNormalMode must be set to a value multiple of FlsPageSize
            [!ENDASSERT!][!//
            [!ASSERT "../../../FlsMaxWriteFastMode mod ./FlsPageSize = 0"!][!//
                Error: FlsMaxWriteFastMode must be set to a value multiple of FlsPageSize
            [!ENDASSERT!][!//
        [!ENDLOOP!][!//
        [!// 
        [!LOOP "FlsExternalDriver/FlsHwUnit/*"!][!//        
            [!IF "./FlsHwUnitWordAddressable"!][!//
                [!ASSERT "../../../FlsMaxReadNormalMode mod 2 = 0"!][!//
                    Error: When FlsHwUnitWordAddressable parameter is set, FlsMaxReadNormalMode must be an even number.
                [!ENDASSERT!][!//
                [!ASSERT "../../../FlsMaxReadFastMode mod 2 = 0"!][!//
                    Error: When FlsHwUnitWordAddressable parameter is set, FlsMaxReadFastMode must be an even number.
                [!ENDASSERT!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!//         
        /* paQspiSectCh[] ([!"node:name(.)"!]) */
        static CONST(Fls_QspiSectorChType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiSectCh[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
        {
        [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                [!WS "4"!](Fls_QspiSectorChType)[!"./FlsQspiSectorCh"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
        [!ENDLOOP!][!//
        };
        
        /* paQspiSectChParallel[] ([!"node:name(.)"!]) */
        static CONST(Fls_QspiSectorChParallelType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiSectChParallel[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
        {
        [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                [!WS "4"!][!IF "text:contains(string(./FlsQspiSectorCh),'PARALLEL')"!]FLS_QSPI_CH_PARALLEL[!ELSE!]FLS_QSPI_CH_INDIVIDUAL[!ENDIF!] [!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
        [!ENDLOOP!][!//
        };
        
        /* paQspiUnitSectorAssign[] ([!"node:name(.)"!]) */
        static CONST(Fls_QspiUnitNameType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitSectorAssign[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
        {
        [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
        [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
            [!IF "./FlsHwCh != 'FLS_CH_INTERN'"!][!//
                [!WS "4"!][!"concat('(Fls_QspiUnitNameType)FLS_',substring(./FlsQspiSectorCh,15,6))"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
            [!ELSE!][!//
                [!WS "4"!][!"'(Fls_QspiUnitNameType)0U'"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
            [!ENDIF!][!//    
        [!ENDLOOP!][!//
        };
    
        [!VAR "FlsLoopIt" = "count(FlsExternalDriver/FlsHwUnit/*)"!][!//
        [!LOOP "FlsExternalDriver/FlsHwUnit/*"!][!//
            
            [!IF "$FlsQspiHyperflashEnVar='false'"!][!// /*  */
            
                [!VAR "FlsHwUnitName" = "node:name(.)"!]
                [!LOOP "node:order(FlsLUT/*,'node:value(./FlsLUTIndex)')"!]
                    /* (*paInstrOper)[] */
                    [!WS "0"!]static CONST(Fls_InstructionOperandType, FLS_CONST) [!"$FlsHwUnitName"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(FlsInstructionOperandPair/*))"!]] =
                    [!WS "0"!]{
                        [!VAR "FlsLoopIt3" = "count(FlsInstructionOperandPair/*)"!]
                        [!LOOP "node:order(FlsInstructionOperandPair/*,'node:value(./FlsInstrOperPairIndex)')"!]
                            [!VAR "FlsLoopIt3" = "$FlsLoopIt3 - 1"!]
                            [!WS "4"!](Fls_InstructionOperandType)((Fls_InstructionOperandType)((Fls_InstructionOperandType)[!"./FlsLUTInstruction"!] << 10U) | \[!CR!]
                            [!WS "32"!](Fls_InstructionOperandType)((Fls_InstructionOperandType)[!"./FlsLUTPad"!] << 8U) | \[!CR!]
                            [!WS "32"!][!"./FlsLUTOperand"!]U)[!IF "$FlsLoopIt3 != 0"!],[!ENDIF!][!CR!]
                        [!ENDLOOP!]
                    [!WS "0"!]};
                    
                [!ENDLOOP!][!//
            
            
                /* aFlsLUT[] ([!"node:name(.)"!]) */
                static CONST(Fls_QspiLUTType, FLS_CONST) [!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsLUT[[!"num:i(count(./FlsLUT/*))"!]] =
                {
                    [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!]
                    [!WS "4"!]/* [!"node:name(../../../../*)"!]_[!"node:name(.)"!]_LUT */
                    [!VAR "FlsLoopIt2" = "count(FlsLUT/*)"!]
                    [!LOOP "node:order(FlsLUT/*,'node:value(./FlsLUTIndex)')"!]
                        [!WS "4"!]{
                        [!VAR "FlsLoopIt2" = "$FlsLoopIt2 - 1"!]
                        [!VAR "FlsLoopIt3" = "count(FlsInstructionOperandPair/*)"!]
                        [!WS "8"!]/* [!"node:name(.)"!] */
                        [!WS "8"!][!"num:i($FlsLoopIt3)"!]U, /* INSTRUCTION-OPERAND pairs count. */            
                        [!WS "8"!]&[!"$FlsHwUnitName"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
                        [!WS "4"!]}[!IF "$FlsLoopIt2 != 0"!],[!ENDIF!][!CR!]
                    [!ENDLOOP!]
                };
                
            [!ENDIF!][!//
                
        [!ENDLOOP!][!//        
        
        [!LOOP "FlsExternalDriver/FlsHwUnit/*"!]   
        
            [!IF "FlsHwUnitReadBufferMode='FLS_AHB_READ_MODE'"!][!//
            
                /* paQspiUnitAhbBuffer[] ([!"node:name(.)"!]) */
                static CONST(Fls_AhbBufferType, FLS_CONST) [!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBuffer[[!"num:i(count(./FlsAhbBuffer/*))"!]] =
                {
                    [!VAR "FlsLoopIt" = "count(./FlsAhbBuffer/*)"!][!//
                    [!LOOP "./FlsAhbBuffer/*"!][!//
                        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                            [!WS "4"!][!"./FlsAhbBufferInstance"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
                    [!ENDLOOP!][!//
                };
                /* paQspiUnitAhbBufferMasterId[] ([!"node:name(.)"!]) */
                static CONST(Fls_AhbBufferMasterIdType, FLS_CONST) [!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBufferMasterId[[!"num:i(count(./FlsAhbBuffer/*))"!]] =
                {
                    [!VAR "FlsLoopIt" = "count(./FlsAhbBuffer/*)"!][!//
                    [!LOOP "./FlsAhbBuffer/*"!][!//
                        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                        [!WS "4"!][!"./FlsAhbBufferMasterId"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
                    [!ENDLOOP!][!//
                };
                /* paQspiUnitAhbBufferSize[] ([!"node:name(.)"!]) */
                static CONST(uint32, FLS_CONST) [!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBufferSize[[!"num:i(count(./FlsAhbBuffer/*))"!]] =
                {
                    [!VAR "FlsLoopIt" = "count(./FlsAhbBuffer/*)"!][!//
                    [!LOOP "./FlsAhbBuffer/*"!][!//
                        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                        [!WS "4"!][!"./FlsAhbBufferSize"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
                    [!ENDLOOP!][!//
                };
                /* paQspiUnitAhbBufferDataTransferSize[] ([!"node:name(.)"!]) */
                static CONST(uint32, FLS_CONST) [!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBufferDataTransferSize[[!"num:i(count(./FlsAhbBuffer/*))"!]] =
                {
                    [!VAR "FlsLoopIt" = "count(./FlsAhbBuffer/*)"!][!//
                    [!LOOP "./FlsAhbBuffer/*"!][!//
                        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
                        [!WS "4"!][!"./FlsAhbBufferDataTransferSize"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
                    [!ENDLOOP!][!//
                };  
            
            [!ENDIF!]
            
            /* aFlsSerialAddrMapping[] ([!"node:name(.)"!]) */
            static CONST(uint32, FLS_CONST) [!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSerialAddrMapping[4] =
            {        
                [!WS "4"!][!"num:inttohex(node:value(./FlsSerialFlashA1TopAddr))"!]UL,
                [!WS "4"!][!"num:inttohex(node:value(./FlsSerialFlashA2TopAddr))"!]UL,
                [!WS "4"!][!"num:inttohex(node:value(./FlsSerialFlashB1TopAddr))"!]UL,
                [!WS "4"!][!"num:inttohex(node:value(./FlsSerialFlashB2TopAddr))"!]UL
            };
        
        [!ENDLOOP!][!// LOOP "FlsExternalDriver/FlsHwUnit/*"
        
        /* paQspiUnitCfg[] ([!"node:name(.)"!]) */
        static CONST(Fls_QspiUnitCfgType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitCfg[[!"num:i(count(FlsExternalDriver/FlsHwUnit/*))"!]] =
        {
        [!VAR "FlsLoopIt" = "count(FlsExternalDriver/FlsHwUnit/*)"!][!//
        [!LOOP "FlsExternalDriver/FlsHwUnit/*"!][!//
            [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//        
            [!VAR "FlsAhbBufferCount" = "0"!][!//
            [!VAR "FlsAhbBufferAllMasters" = "'false'"!][!//  
            [!VAR "FlsAhbBufferHighPriority" = "'false'"!][!//  
            [!IF "node:exists(./FlsQspiLutSeqIdRefs)"!][!//
                [!VAR "FlsLUTSeqsCount" = "count(FlsLUT/*)"!][!//
            [!ELSE!][!//
                [!VAR "FlsLUTSeqsCount" = "0"!][!//
            [!ENDIF!][!//
            [!LOOP "./FlsAhbBuffer/*"!][!//
                [!VAR "FlsAhbBufferCount" = "$FlsAhbBufferCount + 1"!][!//
                [!IF "./FlsAhbBufferAllMasters = 'true'"!][!//
                    [!VAR "FlsAhbBufferAllMasters" = "'true'"!][!//
                [!ENDIF!][!//
                [!IF "./FlsAhbBufferHighPriority = 'true'"!][!//
                    [!VAR "FlsAhbBufferHighPriority" = "'true'"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!WS "4"!]{ 
                [!WS "8"!]/* ([!"node:name(.)"!]) */
                [!WS "8"!][!"./FlsHwUnitName"!],                                    /*eHwUnitName*/
                [!WS "8"!][!"./FlsHwUnitReadMode"!],                                /*eQspiUnitReadMode*/
                                        /* Kinetis implementation specific. */
                [!WS "8"!][!IF "./FlsHwUnitDqsMode"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]             /*bQspiUnitDqsMode*/[!CR!] 
                [!WS "8"!][!IF "./FlsHwUnitInputPadsBufferEn"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]   /*bQspiUnitInputPadsBufferEn*/[!CR!] 
                [!WS "8"!][!"./FlsHwUnitInputClockSel"!],                           /*eQspiUnitInputClockSel*/
                [!WS "8"!][!"./FlsHwUnitInternalRefClockSel"!],                     /*eQspiUnitInternalRefClockSel*/
                [!WS "8"!][!"./FlsHwUnitDqsBStage2ClkSource"!],                     /*eQspiUnitDqsBStage2ClkSource*/
                [!WS "8"!][!"./FlsHwUnitDqsBStage1ClkSource"!],                     /*eQspiUnitDqsBStage1ClkSource*/
                [!WS "8"!][!"./FlsHwUnitDqsAStage2ClkSource"!],                     /*eQspiUnitDqsAStage2ClkSource*/
                [!WS "8"!][!"./FlsHwUnitDqsAStage1ClkSource"!],                     /*eQspiUnitDqsAStage1ClkSource*/
                [!WS "8"!][!IF "./FlsHwUnitPendingReadBusGasket"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]            /*bQspiUnitPendingReadBusGasket*/[!CR!] 
                [!WS "8"!][!IF "./FlsHwUnitBurstReadBusGasket"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]              /*bQspiUnitBurstReadBusGasket*/[!CR!] 
                [!WS "8"!][!IF "./FlsHwUnitBurstWriteBusGasket"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]             /*bQspiUnitBurstWriteBusGasket*/[!CR!] 
                [!WS "8"!][!"./FlsHwUnitProgrammableDivider"!],                     /*eQspiUnitProgrammableDivider*/
                [!WS "8"!][!IF "./IdleSignalDriveIOFB3HighLvl"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]             /*bQspiUnitIOFB3HighLvl*/[!CR!] 
                [!WS "8"!][!IF "./IdleSignalDriveIOFB2HighLvl"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]             /*bQspiUnitIOFB2HighLvl*/[!CR!] 
                [!WS "8"!][!IF "./IdleSignalDriveIOFA3HighLvl"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]             /*bQspiUnitIOFA3HighLvl*/[!CR!] 
                [!WS "8"!][!IF "./IdleSignalDriveIOFA2HighLvl"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]             /*bQspiUnitIOFA2HighLvl*/[!CR!] 
                            [!WS "8"!][!"./FlsHwUnitSamplingEdge"!],                            /*eQspiUnitSamplingEdge*/
                [!WS "8"!][!"./FlsHwUnitSamplingDly"!],                             /*eQspiUnitSamplingDly*/
                [!WS "8"!][!"./FlsHwUnitSamplingPoint"!]U,                           /*u8QspiUnitSamplingPoint*/
                [!WS "8"!][!IF "./FlsHwUnitDqsLatencyEnable"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]/*bQspiUnitDqsLatencyEn*/[!CR!] 
                [!WS "8"!][!"./FlsHwUnitFineDelayA"!]U,                      /*u8QspiUnitFineDlyA*/         
                [!WS "8"!][!"./FlsHwUnitFineDelayB"!]U,                      /*u8QspiUnitFineDlyB*/         
                [!WS "8"!][!"./FlsHwUnitTdh"!],                                     /*eQspiUnitTdh*/
                [!WS "8"!][!"./FlsHwUnitTcsh"!]U,                            /*u8QspiUnitTcsh*/
                [!WS "8"!][!"./FlsHwUnitTcss"!]U,                            /*u8QspiUnitTcss*/   
                [!WS "8"!][!"./FlsHwUnitEndianness"!],                              /*eQspiUnitEndian*/
                [!WS "8"!][!"./FlsHwUnitReadBufferMode"!],                          /*eQspiUnitReadBufferMode*/            
                [!WS "8"!][!"./FlsHwUnitRxBufferAccessMode"!],                      /*eQspiUnitRxBufferAccessMode*/ 
            [!IF "FlsHwUnitReadBufferMode='FLS_AHB_READ_MODE'"!][!//        
                [!WS "8"!]&[!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBuffer,                   /*paQspiUnitAhbBuffer*/
                [!WS "8"!]&[!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBufferMasterId,           /*paQspiUnitAhbBufferMasterId*/
                [!WS "8"!]&[!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBufferSize,               /*paQspiUnitAhbBufferSize*/
                [!WS "8"!]&[!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitAhbBufferDataTransferSize,   /*paQspiUnitAhbBufferDataTransferSize*/            
                [!WS "8"!][!IF "$FlsAhbBufferAllMasters = 'true'"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]/*bHwUnitAhbBufferAllMasters*/[!CR!]
                [!WS "8"!][!IF "$FlsAhbBufferHighPriority = 'true'"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]/*bHwUnitAhbBuffeHighPriority*/[!CR!]
                [!WS "8"!][!"num:i($FlsAhbBufferCount)"!]U,                                                   /*u8QspiUnitAhbBufferCount*/
            [!ELSE!]        
                [!WS "8"!]NULL_PTR,             /*paQspiUnitAhbBuffer*/
                [!WS "8"!]NULL_PTR,             /*paQspiUnitAhbBufferMasterId*/
                [!WS "8"!]NULL_PTR,             /*paQspiUnitAhbBufferSize*/
                [!WS "8"!]NULL_PTR,             /*paQspiUnitAhbBufferDataTransferSize*/            
                [!WS "8"!](boolean)FALSE,        /*bHwUnitAhbBufferAllMasters*/
                [!WS "8"!](boolean)FALSE,        /*bHwUnitAhbBufferHighPriority*/
                [!WS "8"!]0U,                   /*u8QspiUnitAhbBufferCount*/
            [!ENDIF!]
                [!WS "8"!]&[!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSerialAddrMapping,           /*paQspiUnitSerialAddrMapping*/
                [!WS "8"!][!"./FlsHwUnitColumnAddressWidth"!]U,                     /*u8QspiUnitColumnAddressWidth*/
                [!WS "8"!][!IF "./FlsHwUnitWordAddressable"!](boolean)TRUE,[!ELSE!](boolean)FALSE,[!ENDIF!]/*bQspiUnitWordAddressable*/[!CR!]
                [!WS "8"!][!"./FlsExtUnitRegWidth"!]U,                                     /*u8QspiUnitRegisterWidth*/
                [!WS "8"!][!"./FlsBusyBitValue"!]U,                                     /*u8QspiUnitBusyBitValue*/
                [!WS "8"!][!"./FlsBusyBitPositionOffset"!]U,                                     /*u8QspiUnitBusyBitPosOffset*/
                [!WS "8"!][!IF "node:exists(./FlsQspiLutSeqIdRefs/FlsLUTReadIdSequenceIdRef)"!][!"./FlsQspiDeviceId"!][!ELSE!]0[!ENDIF!]U, /*u16QspiDeviceId*/[!CR!]                                                 
                [!WS "8"!][!"./FlsQspiHyperflashLatencyCycles"!]U,                                     /*u8QspiHyperflashLatCycls*/
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!]&[!"$Current_ConfigSet"!]_[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsLUT,[!ELSE!]NULL_PTR,[!ENDIF!]     /*paQspiUnitLUT*/
                [!WS "8"!][!"num:i($FlsLUTSeqsCount)"!]U,                    /*u8QspiLUTSeqsCount*/
                [!WS "8"!]/* Index of Fls LUT Get Status Sequence from the LUT array */   
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!][!CALL "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"="'FlsLUTGetStatusSequenceIdRef'"!],[!ELSE!]0U,[!ENDIF!]   /*u8QspiLUTGetStatusSeq*/
                [!WS "8"!]/* Index of Fls LUT Read Sequence from the LUT array */   
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!][!CALL "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"="'FlsLUTReadSequenceIdRef'"!],[!ELSE!]0U,[!ENDIF!]   /*u8QspiLUTReadSeq*/
                [!WS "8"!]/* Index of Fls LUT Write Sequence from the LUT array */  
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!][!CALL "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"="'FlsLUTWriteEnableSequenceIdRef'"!],[!ELSE!]0U,[!ENDIF!]  /*u8QspiLUTWriteEnSeq*/
                [!WS "8"!]/* Index of Fls LUT Write Sequence from the LUT array */  
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!][!CALL "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"="'FlsLUTWriteSequenceIdRef'"!],[!ELSE!]0U,[!ENDIF!]  /*u8QspiLUTWriteSeq*/
                [!WS "8"!]/* Index of Fls LUT Erase Sequence from the LUT array */  
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!][!CALL "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"="'FlsLUTEraseSequenceIdRef'"!],[!ELSE!]0U,[!ENDIF!]   /*u8QspiLUTEraseSeq*/
                [!WS "8"!]/* Index of Fls LUT Read ID Sequence from the LUT array */  
                [!WS "8"!][!IF "$FlsQspiHyperflashEnVar='false'"!][!CALL "FlsGetQspiLutSeqId","FlsQspiLutSeqIdName"="'FlsLUTReadIdSequenceIdRef'"!][!ELSE!]0U[!ENDIF!]   /*u8QspiLUTReadIdSeq*/
            [!WS "4"!]}[!IF "$FlsLoopIt != 0"!],[!ENDIF!][!CR!]
        [!ENDLOOP!][!//
        };

    /* pFlsQspiCfgConfig */
    static CONST(Fls_QspiCfgConfigType, FLS_CONST) Fls_QspiConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        [!WS "4"!][!IF "node:exists(FlsQspiInitCallout)"!]&[!"./FlsQspiInitCallout"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsQspiInitCallout */
        [!WS "4"!][!IF "node:exists(FlsQspiResetCallout)"!]&[!"./FlsQspiResetCallout"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsQspiResetCallout */
        [!WS "4"!][!IF "node:exists(FlsQspiErrorCheckCallout)"!]&[!"./FlsQspiErrorCheckCallout"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsQspiErrorCheckCallout */
        [!WS "4"!][!IF "node:exists(FlsQspiEccCheckCallout)"!]&[!"./FlsQspiEccCheckCallout"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsQspiEccCheckCallout */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiSectCh,                     /* (*paQspiSectCh)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiSectChParallel,             /* (*paQspiSectChParallel)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitSectorAssign,           /* (*paQspiUnitSectorAssign)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paQspiUnitCfg,                    /* (*paQspiUnitCfg)[] */
        [!WS "4"!][!"num:i(count(FlsExternalDriver/FlsHwUnit/*))"!]U    /* u8QspiUnitsCount - Number of available external hardware units */
    };
    
    [!ENDIF!][!// (IF "num:i(count(FlsExternalDriver/FlsHwUnit/*)) != 0")

    [!CALL "FlsCalcCrc"!][!// 
    
    /**
    * @brief        Structure used to set function pointers notification, working mode
    */
    /* Fls module initialization data ([!"node:name(.)"!])*/
    /* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_5 Could be made static */
    
    CONST(Fls_ConfigType, FLS_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        [!WS "4"!]/* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types */
        [!WS "4"!]/* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_3 Cast from pointer to pointer */
        [!WS "4"!]/* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
        [!WS "4"!](Fls_AcErasePtrType)[!IF "ecu:get('Fls.Internal.Flash.Available') = 'STD_ON'"!][!IF "../FlsGeneral/FlsAcLoadOnJobStart"!][!IF "normalize-space(./FlsAcErasePointer) = 'NULL_PTR' or normalize-space(./FlsAcErasePointer) = 'NULL'"!][!"normalize-space(./FlsAcErase)"!]U[!ELSE!]&[!"./FlsAcErasePointer"!][!ENDIF!][!ELSE!]&Fls_Flash_AccessCode[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsAcErase */
        [!WS "4"!]/* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_2 Conversions involing function pointers must be to/from integral types */
        [!WS "4"!]/* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_3 Cast from pointer to pointer */
        [!WS "4"!]/* @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
        [!WS "4"!](Fls_AcWritePtrType)[!IF "ecu:get('Fls.Internal.Flash.Available') = 'STD_ON'"!][!IF "../FlsGeneral/FlsAcLoadOnJobStart"!][!IF "normalize-space(./FlsAcWritePointer) = 'NULL_PTR' or normalize-space(./FlsAcWritePointer) = 'NULL'"!][!"normalize-space(./FlsAcWrite)"!]U[!ELSE!]&[!"./FlsAcWritePointer"!][!ENDIF!][!ELSE!]&Fls_Flash_AccessCode[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsAcWrite */
        [!WS "4"!][!IF "node:exists(FlsACCallback)"!]&[!"./FlsACCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsACCallback */  
        [!WS "4"!][!IF "node:exists(FlsJobEndNotification)"!]&[!"./FlsJobEndNotification"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsJobEndNotification */
        [!WS "4"!][!IF "node:exists(FlsJobErrorNotification)"!]&[!"./FlsJobErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsJobErrorNotification */  
        [!WS "4"!][!IF "node:exists(FlsStartFlashAccessNotif)"!]&[!"./FlsStartFlashAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsStartFlashAccessNotif */
        [!WS "4"!][!IF "node:exists(FlsFinishedFlashAccessNotif)"!]&[!"./FlsFinishedFlashAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsFinishedFlashAccessNotif */
        [!WS "4"!][!"./FlsDefaultMode"!], /* FlsDefaultMode */
        [!WS "4"!][!"./FlsMaxReadFastMode"!]U, /* FlsMaxReadFastMode */
        [!WS "4"!][!"./FlsMaxReadNormalMode"!]U, /* FlsMaxReadNormalMode */
        [!WS "4"!][!"./FlsMaxWriteFastMode"!]U, /* FlsMaxWriteFastMode */
        [!WS "4"!][!"./FlsMaxWriteNormalMode"!]U, /* FlsMaxWriteNormalMode */
        [!WS "4"!][!"num:i(count(FlsSectorList/FlsSector/*))"!]U, /* FlsSectorCount */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorEndAddr,                /* (*paSectorEndAddr)[]  */
            [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aSectorList,                      /* (*pSectorList)[] */
            [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorFlags,                  /* (*paSectorFlags)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsProgSize,                     /* (*paSectorProgSize)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorPageSize,               /* (*paSectorPageSize)[] */    
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorUnlock,                 /* (*paSectorUnlock)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paHwCh,                           /* (*paHwCh)[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_paSectorHwAddress,                /* (*paSectorHwAddress)[] */
            [!WS "4"!][!IF "num:i(count(FlsExternalDriver/FlsHwUnit/*)) != 0"!]&Fls_QspiConfigSet[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!], /* pFlsQspiCfgConfig */
           [!CALL "FlsFinishCrc"!][!//
        [!WS "4"!][!"$FlsCrcReminder"!]U /* configCrc */
    };
    #define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /* 
    * @violates @ref fls[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_pbcfg_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
[!ENDLOOP!][!//
[!ENDINDENT!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @}*/
