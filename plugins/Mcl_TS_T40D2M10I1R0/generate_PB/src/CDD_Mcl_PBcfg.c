/**
*   @file    CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Data structures for the Mcl driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCL
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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


#ifdef __cplusplus
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file Mcl_MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
* 
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' Mcl_MemMap.h included after each section define in order to set the current memory section
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed 
* between a pointer to object type and a different pointer to object type.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_6
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and 
* functions shall not be reused
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_7
* Violates MISRA 2004 Required Rule 12.7, Bitwise operators shall not be applied to operands whose
* underlying type is signed.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_8
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_9
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* a preceding &, or with a paranthesised parameter list, which may be empy.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope should have internal linkage unless external linkage is required.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_11
* Violates MISRA 2004 Required Rule 8.8, All external objects should be declared in one and only one
* file.
* The declaration used to import definition of user callback function.
*
* @section Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_12
* Violates MISRA 2004 Required Rule 1.4, compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported external indetifier
* The used compilers use more than 31 chars for identifiers
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl.h"
#include "Mcl_IPW.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file             CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c
* @requirements     BSW00374, BSW00318
*/
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C                     43
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C   2
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C              1
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C              0
#define MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if config source file and MCL header file are of the same vendor */
#if (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != MCL_VENDOR_ID)
#error "CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Mcl.h have different vendor IDs"
#endif
/* Check if config source file and MCL header file are of the same Autosar version */
#if ((MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Mcl.h are different"
#endif
/* Check if config source file and MCL header file are of the same Software version */
#if ((MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and CDD_Mcl.h are different"
#endif


/* Check if config source file and Mcl_IPW header file are of the same vendor */
#if (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_VENDOR_ID_C != MCL_IPW_VENDOR_ID)
#error "CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcl_IPW.h have different vendor IDs"
#endif
/* Check if config source file and Mcl_IPW header file are of the same version */
#if ((MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MAJOR_VERSION_C != MCL_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_MINOR_VERSION_C != MCL_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_AR_RELEASE_REVISION_VERSION_C != MCL_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcl_IPW.h are different"
#endif
/* Check if config source file and Mcl_IPW header file are of the same Software Version */
#if ((MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MAJOR_VERSION_C != MCL_IPW_SW_MAJOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_MINOR_VERSION_C != MCL_IPW_SW_MINOR_VERSION) || \
     (MCL_PBCFG[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_SW_PATCH_VERSION_C != MCL_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_PBcfg.c and Mcl_IPW.h are different"
#endif

[!INCLUDE "CDD_Mcl_PBcfg_c_checks.m"!][!//
[!INCLUDE "CDD_Mcl_PluginMacro.m"!][!//
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                      LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
[!IF "MclGeneral/EnableDMA"!][!//
#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"

[!CALL "NotificationHandler","Suffix" = "''"!]

#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"

[!ENDIF!]

#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"

[!NOCODE!][!//
    [!VAR "TotalNumberOfChannels"           = "ecu:get('Mcl.eDMA.ChannelNumber')"!][!//
    [!VAR "ChannelsPerDmaInstance"          = "ecu:get('Mcl.eDMA.ChannelNumberPerDmaInstance')"!][!//
    [!VAR "ChannelsPerDmaGroup"             = "ecu:get('Mcl.eDMA.ChannelNumberPerGroup')"!][!//
    [!VAR "ChannelsPerDmaMuxSmall"          = "ecu:get('Mcl.DmaMux.ChannelNumberPerDmaMuxSmall')"!][!//
    [!VAR "ChannelsPerDmaMuxLarge"          = "ecu:get('Mcl.DmaMux.ChannelNumberPerDmaMuxLarge')"!][!//
    [!VAR "NumberOfDmaMuxSmallInstances"    = "ecu:get('Mcl.DmaMux.NumberOfSmallDmaMuxInstances')"!][!//
    [!VAR "LastDmaInstanceId"               = "num:i($TotalNumberOfChannels div $ChannelsPerDmaInstance)"!][!//
    [!VAR "LastDmaInstanceId"               = "$LastDmaInstanceId - 1 "!][!//
    [!VAR "DmaMuxInstancesNumber"           = "num:i(ecu:get('Mcl.DmaMux.DmaMuxInstances'))"!][!//
    [!VAR "numeDmaInstances"                = "num:i($TotalNumberOfChannels div $ChannelsPerDmaInstance)"!]
    [!VAR "EccErrorReportingEnabled"        = "ecu:get('Mcl.eDMA.EccErrorReportingEnabled')"!][!//
    [!VAR "DmaPriorityGroup0Exists"         = "ecu:get('Mcl.eDMA.PriorityGroup0Exists')"!][!//
    [!VAR "DmaPriorityGroup1Exists"         = "ecu:get('Mcl.eDMA.PriorityGroup1Exists')"!][!//
    [!VAR "DmaPriorityGroup2Exists"         = "ecu:get('Mcl.eDMA.PriorityGroup2Exists')"!][!//
    [!VAR "DmaPriorityGroup3Exists"         = "ecu:get('Mcl.eDMA.PriorityGroup3Exists')"!][!//
[!ENDNOCODE!][!//

[!LOOP "(MclConfigSet/*)"!][!//
[!IF "../../MclGeneral/EnableDMA"!][!//
    [!VAR "dmaChannelCount"                 = "num:i(count(DMAChannel/*))"!][!//
    [!VAR "comma" = "1"!][!//
    
[!NOCODE!]/***************************** check priorities configuration ********************/[!ENDNOCODE!][!//
    [!NOCODE!][!//
    [!IF "$numeDmaInstances = 1"!][!//
        [!VAR "CheckChannelPrio" = "num:i(0)"!][!//
        [!IF "(MclEDMA_ERCA='false')"!][!//    
            [!VAR "CheckChannelPrio"="num:i(1)"!]
        [!ENDIF!][!//
    [!ELSE!][!// 
            [!VAR "CheckChannelPrio"="num:i(0)"!]            
    [!ENDIF!][!//
                
    [!FOR "varCounter" = "0" TO "num:i(count(DMAChannel/*)) - 1"!][!//
        [!LOOP "DMAChannel/*"!][!//
            [!IF "MclDMAChannelId = $varCounter"!][!//
                [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!]   [!//
                [!VAR "Group" = "num:i($DmaCh div $ChannelsPerDmaGroup)"!][!//
                [!VAR "Priority" = "num:i(node:value(DMAChannelPriority))"!][!//
                [!IF "$numeDmaInstances = 2"!][!//
                    [!VAR "CheckChannelPrio" = "num:i(0)"!][!//
                    [!VAR "CurrentDma" = "num:i($Group div (num:i($ChannelsPerDmaInstance div $ChannelsPerDmaGroup)))"!][!//
                    [!LOOP "../../DmaInstance/*"!][!//"!]
                        [!VAR "DmaInstanceCrt" ="num:i(substring-after(node:value(DmaHwInstance),'eDMA_Instance'))"!][!//
                        [!IF "($DmaInstanceCrt = $CurrentDma) and (MclEDMA_ERCA='false')"!][!//
                            [!VAR "CheckChannelPrio"="num:i(1)"!][!//
                    [!ENDIF!][!//
                    [!ENDLOOP!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!IF "$CheckChannelPrio=1"!][!//
            [!LOOP "DMAChannel/*"!][!//
                [!IF "MclDMAChannelId != $varCounter"!][!//
                    [!VAR "CurrentDmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
                    [!VAR "CurrentGroup" = "num:i($CurrentDmaCh div $ChannelsPerDmaGroup)"!][!//
                    [!VAR "CurrentPriority" = "num:i(node:value(DMAChannelPriority))"!][!//
                    [!IF "($CurrentGroup = $Group) and ($CurrentPriority = $Priority)"!][!//
                        [!ERROR!] [!//
                        "Priority Error! Mcl channel [!"$varCounter"!] and another channel from group [!"num:i($Group)"!] have equal priority."[!//
                        [!ENDERROR!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
    [!ENDFOR!][!//
[!ENDNOCODE!][!//
/**
  * @brief Number of configured Dma channels
  */
#define MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]   [!"num:i(count(DMAChannel/*))"!]U[!CR!]
[!VAR "DmaMuxChannelsNo" = "0"!][!//
[!IF "($DmaMuxInstancesNumber != 0) and ($ChannelsPerDmaMuxSmall = $ChannelsPerDmaMuxLarge) and (DmaMuxInstancesNumber < $TotalNumberOfChannels div $ChannelsPerDmaMuxLarge)"!]
/* @brief Number of configured DmaMux channels if the second DMA is not linked to a DMAMUX
 *        In this case only channels corresponding to the first DMAMUX are count and initialized as part of Dmamux_Init
 */
[!LOOP "DMAChannel/*"!][!//
    [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!]
    [!IF "(num:i($DmaCh))<(num:i($ChannelsPerDmaMuxSmall))"!][!VAR "DmaMuxChannelsNo"="$DmaMuxChannelsNo + 1"!][!ENDIF!][!//
[!ENDLOOP!][!//
#define MCL_DMAMUX_CONF_CHANNELS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]  [!"num:i($DmaMuxChannelsNo)"!]U
[!ELSE!]
[!VAR "DmaMuxChannelsNo" = "num:i($dmaChannelCount)"!][!//
/**
  * @brief Number of configured DmaMux channels
  */
#define MCL_DMAMUX_CONF_CHANNELS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]  [!"num:i($dmaChannelCount)"!]U
[!ENDIF!][!//

[!NOCODE!]/***************************** Configuration for DMA ********************/[!ENDNOCODE!][!//

/** @brief Configuration for Dma channels */
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
[!CALL "DmaChannelConfig","DmaConfigType" = "'PBVariant'"!]
/** @brief Configuration for Dma instances */
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
[!CALL "DmaInstanceConfig","DmaConfigType" = "'PBVariant'"!]
/**
* @brief            DMA basic configuration
* @details          Configuration for DMA hw IP.
*                   Include Control Register and Channel Priorities.
*
*/
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
CONST( Mcl_DmaConfigType, MCL_CONST) Dma_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        /** @brief Number of configured eDMA channels. */
        [!"num:i($dmaChannelCount)"!]U,  
        &Mcl_Dma_InstanceConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        /** @brief Pointer to the structure containing DMA channel configuration */
        &Mcl_Dma_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    };
[!CALL "DmaMuxChannelConfig","DmaConfigType" = "'PBvariant'"!]
[!IF "$DmaMuxInstancesNumber != 0"!]
/**
* @brief            DMA_MUX basic configuration.
* @details          Configuration for DMA_MUX hw IP.
*                   The DMA_MUX allows to route DMA sources to DMA channels.
*
*/
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
CONST( Mcl_DmaMuxConfigType, MCL_CONST) DmaMux_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        /** @brief Number of configured DMA channels which are also linked to DMAMUX. */
        MCL_DMAMUX_CONF_CHANNELS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],   
        /** @brief Pointer to the structure containing DMAMUX channel configuration */
        &Mcl_DmaMux_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    };
[!ENDIF!][!//    
[!VAR "comma" = "1"!][!//
/** @brief Array of configured Mcl channels */
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
CONST(Mcl_ChannelConfigType, MCL_CONST) Mcl_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
[!FOR "varCounter" = "0" TO "num:i(count(DMAChannel/*))"!][!//
[!LOOP "DMAChannel/*"!][!//
[!IF "MclDMAChannelId = $varCounter"!][!//
    /** @brief [!"node:name(.)"!] */
    {
[!/* */!][!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
        /** @brief Number of configured Mcl channel. */
        DMA_HW_CHANNEL_[!"$DmaCh"!],
#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        /** @brief DMA notification function */
[!/* */!][!IF "(MclDmaTransferCompletionNotif = '') or (MclDmaTransferCompletionNotif = 'NULL_PTR') or (MclDmaTransferCompletionNotif = 'NULL')"!][!//
        NULL_PTR
[!/* */!][!ELSE!][!//
        [!"MclDmaTransferCompletionNotif"!]
[!/* */!][!ENDIF!][!//
#endif
  /**  @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_9 MISRA 2004 Rule 16.9, function identifier */
    }[!IF "(num:i($comma))<(num:i($dmaChannelCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};

[!NOCODE!]/*************** Configuration for Mcl_HwIPs_ConfigPB ******************/[!ENDNOCODE!][!//
/**
* @brief          Initialization data for different hw IPs.
* @details        Configuration realized at statup by calling Mcl_Init() API.
*
*/
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
CONST( Mcl_DmaHwIpsConfigType, MCL_CONST) Mcl_HwIPs_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        /* Configuration for eDMA (Enhanced Direct Memory Access) hardware IP. */
        &Dma_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!IF "$DmaMuxInstancesNumber != 0"!]
        ,
        /* Configuration for DMA_MUX (eDMA Channel Mux) hardware IP. */
        &DmaMux_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ENDIF!][!//
    };
    
/**
* @brief            Dma basic configuration.
* @details          Configuration for Dma.
*
*/
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */

CONST( Mcl_DmaInitConfigType, MCL_CONST) Mcl_Dma_InitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
    {
        /** @brief Number of configured eDMA channels. */
        [!"num:i($dmaChannelCount)"!]U,
        /** @brief Pointer to the structure containing Mcl channel configuration */
        &Mcl_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        /**< @brief IPs data generic configuration. */
        &Mcl_HwIPs_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
        #if ((MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) || (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON))
        ,
        /** @brief Hw to logic channel map. Array containing a number of elements
        equal to total number of available DMA channels  */
        {
        [!NOCODE!]
        [!FOR "curModChannel" = "0" TO "$TotalNumberOfChannels - 1"!]
        [!VAR "varChTranslationIndex" = "255"!]
        [!LOOP "DMAChannel/*"!][!//
            [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!]
            [!IF "num:i($DmaCh) = $curModChannel"!]
                [!VAR "varChTranslationIndex" = "MclDMAChannelId"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$varChTranslationIndex = 255"!]
[!CODE!]            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8[!IF "$curModChannel < $TotalNumberOfChannels - 1"!],[!ENDIF!][!CR!][!ENDCODE!]
        [!ELSE!]
[!CODE!]            (Mcl_ChannelType)MCL_DMA_LOGICAL_CHANNEL_[!"num:i($varChTranslationIndex)"!][!IF "$curModChannel < $TotalNumberOfChannels - 1"!],[!ENDIF!][!CR!][!ENDCODE!]
        [!ENDIF!]
        [!ENDFOR!]
        [!ENDNOCODE!]
        }       
        #endif /* MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON || MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON */ 
    };
[!ENDIF!][!//EnableDMA
 
[!IF "../../MclGeneral/MclEnableTrgMux"!][!//   
/**
* @brief            TRG_MUX basic configuration.
* @details          Configuration for TRG_MUX hw IP.
*                   The TRG_MUX allows to route trigger sources to peripherals.
*
*/
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
[!CALL "TrgMuxConfig","TrgMuxConfigType" = "'PBvariant'"!]
[!ENDIF!][!//MclEnableTrgMux
[!NOCODE!]/********************** Configuration for Mcl_ConfigType ***************/[!ENDNOCODE!][!//
/**
* @brief            Mcl basic configuration.
* @details          Configuration for Mcl.
*
*/
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
[!IF "((./../../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (./../../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
CONST( Mcl_ConfigType, MCL_CONST) [!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ELSE!][!//
CONST( Mcl_ConfigType, MCL_CONST) Mcl_Init_PBCfgVariantPredefined =
[!ENDIF!]
{
[!VAR "comma" = "0"!] 
[!IF "../../MclGeneral/EnableDMA"!] 
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /** Configuration for the Dem errors */
        &Mcl_Dem_Config,
#endif        
        /** Configuration for the Dma and DmaMu IPs */
        &Mcl_Dma_InitConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
        [!VAR "comma" = "1"!] 
[!ENDIF!][!//EnableDMA
    [!IF "../../MclGeneral/MclEnableTrgMux"!][!// 
       [!IF "$comma = 1"!]
        ,
        [!ENDIF!]
        /** Configuration for the trigger mux hardware IP */
        &TrgMux_Config[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
        [!VAR "comma" = "1"!] 
    [!ENDIF!][!//MclEnableTrgMux
    };
[!ENDLOOP!]

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */

