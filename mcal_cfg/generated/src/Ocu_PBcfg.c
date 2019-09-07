/**
*   @file       Ocu_PBcfg.c
*   @implements Ocu_PBcfg.c_Artifact
*   @version    1.0.1
*
*   @brief      AUTOSAR Ocu - Ocu post-build configuration file.
*   @details    Post-build configuration structure instances.
*
*   @addtogroup OCU_MODULE
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

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_PBcfg_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Ocu_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
* 
* @section Ocu_PBcfg_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
* 
* @section Ocu_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
* character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly
*
* @section Ocu_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* preceing &, or with a paranhesised parameter list which may be empty.
*
* @section Ocu_PBcfg_C_REF_6
* Violates MISRA 2004 Required Rule 12.8, The right-hand operand of a shift operator shall lie 
* between zero and one less than the width in bits of the underlying type of the left-hand operand.
*
* @section Ocu_PBcfg_C_REF_7
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one 
* and only one file.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Ocu.h"

#include "Reg_eSys_Ftm.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Ocu_PBcfg.c
*/
#define OCU_PBCFG_VENDOR_ID_C                      43
#define OCU_PBCFG_MODULE_ID_C                      121
#define OCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
#define OCU_PBCFG_AR_RELEASE_MINOR_VERSION_C       2
#define OCU_PBCFG_AR_RELEASE_REVISION_VERSION_C    2

#define OCU_PBCFG_SW_MAJOR_VERSION_C               1
#define OCU_PBCFG_SW_MINOR_VERSION_C               0
#define OCU_PBCFG_SW_PATCH_VERSION_C               1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_PBCFG_VENDOR_ID_C != OCU_VENDOR_ID)
    #error "Ocu_PBcfg.c and Ocu.h have different vendor ids"
#endif

#if ((OCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != OCU_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != OCU_AR_RELEASE_MINOR_VERSION) || \
     (OCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != OCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_PBcfg.c and Ocu.h are different"
#endif

#if ((OCU_PBCFG_SW_MAJOR_VERSION_C != OCU_SW_MAJOR_VERSION) || \
     (OCU_PBCFG_SW_MINOR_VERSION_C != OCU_SW_MINOR_VERSION)  || \
     (OCU_PBCFG_SW_PATCH_VERSION_C != OCU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_PBcfg.c and Ocu.h are different"
#endif

#if (OCU_PBCFG_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Ocu_PBcfg.c and Reg_eSys_Ftm.h have different vendor ids"
#endif

#if ((OCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (OCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION ))
    #error "AutoSar Version Numbers of Ocu_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif

#if ((OCU_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (OCU_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (OCU_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_PBcfg.c and Reg_eSys_Ftm.h are different"
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

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Ocu_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
#include "Ocu_MemMap.h"

/** 
* @brief Number of configured Ocu channels 
*/
#define OCU_CONF_CHANNELS_PB           1

/** 
* @brief Number of configured FTM channels
*/
#define OCU_FTM_CONF_CHANNELS_PB     1
/** 
* @brief Number of configured FTM modules
*/
#define OCU_FTM_CONF_MODULES_PB     1

/***************************** Configuration for Ftm ********************/

/* @brief Configurations for Ocu channels using FTM 
 * @violates @ref Ocu_PBcfg_C_REF_2 external ... could be made static
 * @violates @ref Ocu_PBcfg_C_REF_4 violates Misra 1.4 Identifier clash
 */
static CONST(Ocu_Ftm_ChannelConfigType, OCU_CONST) Ocu_Ftm_ChannelConfig_PB[OCU_FTM_CONF_CHANNELS_PB] =
{
    /* @brief OcuChannel_0 -> FTM_1_CH_0 */
    {
        /** @brief Ocu Hw Channel */
        (Ocu_Ftm_ChannelType)FTM_1_CH_0,
        /** @brief Ocu Default treshold: 10000 */
        (uint16)0x2710U,
        /** @brief Ftm Control Value */
        (Ocu_Ftm_ChannelControlType)
        (
            (OCU_FTM_OUTPUTDISABLED) |  /*Output Pin Enable and default state */
            (uint8)((uint32)(OCU_DISABLE) << OCU_FTM_PIN_ACTION_SHIFT)  /*Output Pin default action*/  
        )
    }
};


/* @brief Configurations for Ocu channels using FTM 
 * @violates @ref Ocu_PBcfg_C_REF_2 external ... could be made static
 * @violates @ref Ocu_PBcfg_C_REF_4 violates Misra 1.4 Identifier clash
 */
static CONST(Ocu_Ftm_ModuleConfigType, OCU_CONST) Ocu_Ftm_ModuleConfig_PB[OCU_FTM_CONF_MODULES_PB] =
{
    /* @brief OcuHWSpecificSettings_0 -> FTM_1 */
    {
        /** @brief Assigned Ftm module id*/
        (uint8)1U,
        /** @brief Ocu Max Counter Value */
        (uint16)65535U,
        /** @brief Ftm Control Value */
        (Ocu_Ftm_ModuleControlType) 
        (
            (FTM_SC_CLKS_SYS_CLOCK_U32 >> FTM_SC_CLKS_SHIFT) |  /* Clock source */
            (uint8)((uint32)(FTM_SC_PS_DIV1_U32) << OCU_FTM_CLOCK_DIV_SHIFT)  | /*Timer clock prescaler configuration*/   
            (uint8)((FTM_CONF_BDMMODE_ALLRUN_U32 >>FTM_CONF_BDMMODE_SHIFT)  << OCU_FTM_DBG_INFO_SHIFT) /*Timer debug config*/
        )
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
        ,
        /** @brief prescale alternate */
        (uint8)(FTM_SC_PS_DIV1_U32)
#endif
    }
};
/**
@brief FTM IP configuration
*/
static CONST(Ocu_Ftm_IpConfigType, OCU_CONST) Ocu_Ftm_IpConfig_PB
=
{
    /** @brief Number of FTM channels in the Ocu configuration */
    (uint8)1U,
    /** @brief Number of FTM modules in the Ocu configuration */
    (uint8)1U,
    /** @brief Pointer to the array of FTM channel enabled Ocu channel configurations */
    &Ocu_Ftm_ChannelConfig_PB,
    /** @brief Pointer to the array of FTM module enabled Ocu channel configurations */
    &Ocu_Ftm_ModuleConfig_PB
};
/** 
 *  @violates @ref Ocu_PBcfg_C_REF_7 violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, OCU_CODE) IoDal_Ani_AdcSwTriggerTable(void);

/* @brief Array of configured Ocu channels */
static CONST(Ocu_ChannelConfigType, OCU_CONST) Ocu_Channels_PB
[OCU_CONF_CHANNELS_PB] =
{
    /* @brief OcuChannel_0 */
    {    
        /* @brief OcuOuptutPinUsed */
        (boolean)FALSE,
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
        /** @brief Ocu notification function */
        /* @violates @ref Ocu_PBcfg_C_REF_5 Callback definition */
        &IoDal_Ani_AdcSwTriggerTable
#endif

    }
};
/**
@brief   Ocu channels IP related configuration array
*/
static CONST(Ocu_IpChannelConfigType, OCU_CONST) Ocu_IpChannelConfig_PB
[OCU_CONF_CHANNELS_PB] =
{
    /** @brief OcuChannel_0 */
    {(uint8)0U}
};

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
static CONST(Ocu_ChannelType, OCU_CONST)  Ocu_InitHWMap_PB[OCU_HW_CHANNELS_NO]=
    /** @brief Hw to logic channel map. Array containing a number of elements
    equal to total number of available channels on FTM IPV */
    {
        /* Idx of channels 0 - 7 of Ftm Module 0 in the array of logic Ocu channels */
        (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255,
        /* Idx of channels 0 - 7 of Ftm Module 1 in the array of logic Ocu channels */
        (Ocu_ChannelType)0, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255,
        /* Idx of channels 0 - 7 of Ftm Module 2 in the array of logic Ocu channels */
        (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255,
        /* Idx of channels 0 - 7 of Ftm Module 3 in the array of logic Ocu channels */
        (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255, (Ocu_ChannelType)255
    };
#endif
/**
@brief   Ocu high level configuration structure
*/
/*
* @violates @ref Ocu_PBcfg_C_REF_2 external ... could be made static
*/
CONST(Ocu_ConfigType, OCU_CONST) OcuConfigSet=
{
    /** @brief Number of configured Ocu channels */
    (Ocu_ChannelType)OCU_CONF_CHANNELS_PB,
    /** @brief Pointer to array of Ocu channels */
    &Ocu_Channels_PB
,
    /** @brief IP specific configuration */
    {
        /* @brief Pointer to the structure containing Ftm configuration */
        &Ocu_Ftm_IpConfig_PB
,
        /* @brief Pointer to Array containing channe IP related information */
        &Ocu_IpChannelConfig_PB
    }
    /** @brief counter direction */
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
    ,
    &Ocu_InitHWMap_PB
#endif /* (OCU_NOTIFICATION_SUPPORTED == STD_ON) */  
};
#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Ocu_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Ocu_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Ocu_MemMap.h"


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

