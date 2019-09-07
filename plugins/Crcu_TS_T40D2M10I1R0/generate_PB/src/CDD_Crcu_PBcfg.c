[!CODE!][!//
/**
*     @file       CDD_Crcu_PBcfg.c
*     @implements CDD_Crcu_PBcfg.c_Artifact
*     @version    1.0.1
*     
*     @brief      Crcu - contains the data exported by the Crc module
*     @details    Contains the information that will be exported by the module, as requested by Autosar.
*     
*     @addtogroup CRCU_MODULE
*     @{
*/
/*==================================================================================================
*     Project              : AUTOSAR 4.2 MCAL
*     Platform             : ARM
*     Peripheral           : CRCV2
*     Dependencies         : none
*     
*     Autosar Version      : 4.2.2
*     Autosar Revision     : ASR_REL_4_2_REV_0002
*     Autosar Conf.Variant :
*     SW Version           : 1.0.1
*     Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*     
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus  
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Crcu_PBcfg_c_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file, Precautions shall be taken 
*          in order to prevent the contents of a header file being included twice. This violation is 
*          not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Crcu_PBcfg_c_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported for external identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section Crcu_PBcfg_c_REF_3
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. MemMap.h is included after each section define
*          in order to set the current memory section as defined by AUTOSAR.
*
* @section Crcu_PBcfg_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section Crcu_PBcfg_c_REF_5
*          Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one
*          and only one file. This requirement is fulfilled since the function is declared as external in one 
*          and only in one configuration C file (either Crcu_Cfg.c or Crcu_PBcfg.c).
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for
*          identifiers.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
*==================================================================================================*/
#include "CDD_Crcu_Cfg.h"

[!//
[!NOCODE!][!//
    [!INCLUDE "Crcu_VersionCheck_Src_PB.m"!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
*==================================================================================================*/
#define CRCU_PBCFG_VENDOR_ID_C                      43
/** @violates @ref Crcu_PBcfg_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Crcu_PBcfg_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_PBCFG_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Crcu_PBcfg_c_REF_2 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define CRCU_PBCFG_AR_RELEASE_REVISION_VERSION_C    2
#define CRCU_PBCFG_SW_MAJOR_VERSION_C               1
#define CRCU_PBCFG_SW_MINOR_VERSION_C               0
#define CRCU_PBCFG_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
*==================================================================================================*/
/* Check if current file and CDD_Crcu_Cfg.h header file are of the same vendor */
#if (CRCU_PBCFG_VENDOR_ID_C != CRCU_CFG_VENDOR_ID)
    #error "CDD_Crcu_PBcfg.c and CDD_Crcu_Cfg.h have different vendor IDs"
#endif
/* Check if current file and CDD_Crcu_Cfg.h header file are of the same Autosar version */
#if ((CRCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CRCU_CFG_AR_RELEASE_MAJOR_VERSION) ||    \
     (CRCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != CRCU_CFG_AR_RELEASE_MINOR_VERSION) ||    \
     (CRCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != CRCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crcu_PBcfg.c and CDD_Crcu_Cfg.h are different"
#endif
/* Check if current file and CDD_Crcu_Cfg.h header file are of the same Software version */
#if ((CRCU_PBCFG_SW_MAJOR_VERSION_C != CRCU_CFG_SW_MAJOR_VERSION) || \
     (CRCU_PBCFG_SW_MINOR_VERSION_C != CRCU_CFG_SW_MINOR_VERSION) || \
     (CRCU_PBCFG_SW_PATCH_VERSION_C != CRCU_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crcu_PBcfg.c and CDD_Crcu_Cfg.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
*==================================================================================================*/
[!NOCODE!][!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO Crcu_GenerateControlReg                  */!][!//
[!/*****************************************************************************/!][!//
[!/* Generates the Control register for the selected Crc channel */!][!//
[!MACRO "Crcu_GenerateControlReg"!][!//
[!NOCODE!][!//
[!VAR "MacControlReq"="num:i(0)"!][!//
[!/* Check what type of in transpose option is set */!][!//
[!IF "text:match(./Crcu_In_Swap,'CRCU_IN_NOSWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(0,30))"!][!//
[!ELSEIF "text:match(./Crcu_In_Swap,'CRCU_IN_BITSWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(1,30))"!][!//
[!ELSEIF "text:match(./Crcu_In_Swap,'CRCU_IN_BITANDBYTESWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(2,30))"!][!//
[!ELSEIF "text:match(./Crcu_In_Swap,'CRCU_IN_BYTESWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(3,30))"!][!//
[!ENDIF!][!//
[!/* Check what type of out transpose option is set */!][!//
[!IF "text:match(./Crcu_Out_Swap,'CRCU_OUT_NOSWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(0,28))"!][!//
[!ELSEIF "text:match(./Crcu_Out_Swap,'CRCU_OUT_BITSWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(1,28))"!][!//
[!ELSEIF "text:match(./Crcu_Out_Swap,'CRCU_OUT_BITANDBYTESWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(2,28))"!][!//
[!ELSEIF "text:match(./Crcu_Out_Swap,'CRCU_OUT_BYTESWAP')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(3,28))"!][!//
[!ENDIF!][!//
[!/* Check what type of inversion option is set */!][!//
[!IF "text:match(./Crcu_Out_Inversion,'CRCU_OUT_NOINVERSION')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(0,26))"!][!//
[!ELSEIF "text:match(./Crcu_Out_Inversion,'CRCU_OUT_INVERSION')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(1,26))"!][!//
[!ENDIF!][!//
[!/* Check what CRC protocol width is set */!][!//
[!IF "text:match(./Crcu_Width,'CRCU_WIDTH_16')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(0,24))"!][!//
[!ELSEIF "text:match(./Crcu_Width,'CRCU_WIDTH_32')"!][!//
    [!VAR "MacControlReq"="bit:or($MacControlReq,bit:shl(1,24))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacControlReq, 8)"!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!][!//

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
*==================================================================================================*/
#define CRCU_START_SEC_CODE
/** @violates @ref Crcu_PBcfg_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_PBcfg_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Crcu_GenerateNotifications                 */!][!//
[!/*****************************************************************************/!][!//
[!INDENT "0"!][!//
    [!IF "CrcuGeneral/CrcuDmaUsed = 'true'"!][!//
        /**
        * @brief       Prototypes of Crcu channels async crc calculation complete notifications.
        *
        **/
        [!VAR "MacOuterLoopCounter" = "0"!][!//
        [!VAR "MacInnerLoopCounter" = "0"!] [!//
        [!LOOP "CrcuConfig/CrcuChannel/*"!][!//
            [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!][!//
            [!VAR "MacInnerLoopCounter" = "0"!][!//
            [!VAR "MacMatchcounter" = "0"!][!//
            [!IF "node:exists(CrcuDmaChannelRef)"!][!//
                [!VAR "MacNotification" = "CrcuAsyncCalculateCrcCompleteNotification"!][!//
                [!LOOP "../../../*/CrcuChannel/*"!][!//
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!][!//
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!][!//
                        [!IF "($MacNotification = CrcuAsyncCalculateCrcCompleteNotification)"!][!//
                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
            [!IF "$MacMatchcounter = 1"!][!//
                /* @violates @ref Crcu_PBcfg_c_REF_5 Object/function previously declared */            
                extern FUNC(void, CRCU_CODE)[!"CrcuAsyncCalculateCrcCompleteNotification"!](VAR(Crcu_ChannelIdType, AUTOMATIC) channelId, VAR(Crcu_ValueType, AUTOMATIC) crc);
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
[!ENDINDENT!][!//

#define CRCU_STOP_SEC_CODE
/** @violates @ref Crcu_PBcfg_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_PBcfg_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/*==================================================================================================
*                                      LOCAL CONSTANTS
*==================================================================================================*/
#define CRCU_START_SEC_CONST_UNSPECIFIED
/** @violates @ref Crcu_PBcfg_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_PBcfg_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

[!/*****************************************************************************/!][!//
[!/*                          MACRO Crcu_GenerateChannelsList                  */!][!//
[!/*****************************************************************************/!][!//
[!INDENT "0"!][!//
    [!VAR "MacDmaUsed"="CrcuGeneral/CrcuDmaUsed"!][!//
        [!SELECT "CrcuConfig"!][!//
        [!VAR "MacIdx" = "1"!][!//
        [!VAR "MacLoopVar"="0"!][!//
        [!VAR "MacCount" = "count(CrcuChannel/*)"!][!//
        /* List of Crcu channels */
        static CONST(Crcu_ChannelType, CRCU_CONST) CrcuChannels[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($MacCount)"!]] =
        {
        [!FOR "MacX" = "0" TO "num:i(count(CrcuChannel/*))"!][!//
            [!LOOP "CrcuChannel/*"!][!//
                [!VAR "MacLoop"="num:i($MacLoopVar)"!][!//
                [!IF "CrcuChannelId = $MacLoop"!][!//
                    [!WS "4"!]{
                    [!WS "8"!]/* [!"name(.)"!] */
                    [!WS "8"!](Crcu_Crcv2_ChannelType)[!"CrcChannel"!][!IF "$MacDmaUsed = 'true'"!],[!ENDIF!]
                    [!IF "$MacDmaUsed = 'true'"!][!//
                        [!IF "node:exists(CrcuDmaChannelRef)"!][!//
                            [!WS "8"!](Mcl_ChannelType)[!"node:value(node:ref(CrcuDmaChannelRef)/MclDMAChannelId)"!],
                            [!WS "8"!]&[!"CrcuAsyncCalculateCrcCompleteNotification"!]
                        [!ELSE!][!//
                            [!WS "8"!](Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
                            [!WS "8"!]NULL_PTR
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                    [!WS "4"!]}[!IF "$MacIdx!=$MacCount"!],[!ENDIF!]
                    [!VAR "MacIdx" = "$MacIdx + 1"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!VAR "MacLoopVar"="$MacLoopVar + 1"!][!//
        [!ENDFOR!][!//
        };
        [!ENDSELECT!][!//
[!ENDINDENT!][!//

[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO Crcu_GenerateChannelConfigsList            */!][!//
[!/*****************************************************************************/!][!//
[!INDENT "0"!][!//
    [!VAR "MacDmaUsed"="CrcuGeneral/CrcuDmaUsed"!][!//
        [!SELECT "CrcuConfig"!][!//
        [!VAR "MacIdx" = "1"!][!//
        [!VAR "MacLoopVar"="0"!][!//
        [!VAR "MacCount" = "count(CrcuChannelConfig/*)"!][!//
        /* List of Crcu channels configurations */
        static CONST(Crcu_Crcv2_ChannelConfigType, CRCU_CONST) CrcuCrcv2ChannelConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($MacCount)"!]] =
        {
        [!FOR "MacX" = "0" TO "num:i(count(CrcuChannelConfig/*))"!][!//
            [!LOOP "CrcuChannelConfig/*"!][!//
                [!VAR "MacLoop"="num:i($MacLoopVar)"!][!//
                [!IF "CrcuChannelConfigId = $MacLoop"!][!//
                    [!WS "4"!]{
                    [!WS "8"!]/* [!"name(.)"!] */
                    [!WS "8"!]/* Crc channel polynom */
                    [!WS "8"!](Crcu_Crcv2_PolynomType)[!"num:inttohex(Crcu_Polynom,8)"!]U,
                    [!WS "8"!]/* Crc channel control register */
                    [!WS "8"!](Crcu_Crcv2_ControlType)[!CALL "Crcu_GenerateControlReg"!]U
                    [!WS "4"!]}[!IF "$MacIdx!=$MacCount"!],[!ENDIF!]
                [!VAR "MacIdx" = "$MacIdx + 1"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!VAR "MacLoopVar"="$MacLoopVar + 1"!][!//
        [!ENDFOR!][!//
        };
        [!ENDSELECT!][!//
[!ENDINDENT!][!//

#define CRCU_STOP_SEC_CONST_UNSPECIFIED
/** @violates @ref Crcu_PBcfg_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_PBcfg_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/*==================================================================================================
*                                       LOCAL VARIABLES
*==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
*==================================================================================================*/
#define CRCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Crcu_PBcfg_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_PBcfg_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

[!/*****************************************************************************/!][!//
[!/*                          MACRO Crcu_GenerateConfig                        */!][!//
[!/*****************************************************************************/!][!//
[!INDENT "0"!][!//
        /**
        * @brief This structure contains all the Crcu channels and Crcu channel configurations
        *        configured by the tool for the post-build mode.
        * @violates @ref Crcu_PBcfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10
        */
        [!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
        CONST(Crcu_ConfigType, CRCU_CONST) [!"as:name(CrcuConfig)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
        [!ELSE!]
        CONST(Crcu_ConfigType, CRCU_CONST) Crcu_PBCfgVariantPredefined =
        [!ENDIF!]
        {
            [!WS "4"!](Crcu_ChannelIdType)([!"num:i(count(CrcuConfig/CrcuChannel/*))"!]U),
            [!WS "4"!](Crcu_ChannelConfigIdType)([!"num:i(count(CrcuConfig/CrcuChannelConfig/*))"!]U),
            [!WS "4"!]&CrcuChannels[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
            [!WS "4"!]&CrcuCrcv2ChannelConfigs[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
        };
[!ENDINDENT!][!//

#define CRCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Crcu_PBcfg_c_REF_1 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Crcu_PBcfg_c_REF_3 Only preprocessor statements and comments before '#include'.*/
#include "Crcu_MemMap.h"

/*==================================================================================================
*                                       GLOBAL VARIABLES
*==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
*==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
*==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
*==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
