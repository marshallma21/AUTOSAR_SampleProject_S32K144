/**
*   @file       Pwm_PBcfg.c
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




#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_PBcfg_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
* 
* @section Pwm_PBcfg_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
* 
* @section Pwm_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.*
*
* @section Pwm_PBcfg_C_REF_5
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
* @file           Pwm_PBcfg.c
*/

#define PWM_PBCFG_VENDOR_ID_C                      43
#define PWM_PBCFG_MODULE_ID_C                      121
/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_PBCFG_AR_RELEASE_MAJOR_VERSION_C       4
/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_PBCFG_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_PBCFG_AR_RELEASE_REVISION_VERSION_C    2

#define PWM_PBCFG_SW_MAJOR_VERSION_C               1
#define PWM_PBCFG_SW_MINOR_VERSION_C               0
#define PWM_PBCFG_SW_PATCH_VERSION_C               1
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PWM_PBCFG_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm_PBcfg.c and Pwm.h have different vendor ids"
#endif

#if ((PWM_PBCFG_AR_RELEASE_MAJOR_VERSION_C != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_PBCFG_AR_RELEASE_MINOR_VERSION_C != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM_PBCFG_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif

#if ((PWM_PBCFG_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
        (PWM_PBCFG_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION)  || \
        (PWM_PBCFG_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif

/* Check if header file and Reg_eSys_Ftm.h header file are of the same vendor */
#if (PWM_PBCFG_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Pwm_PBcfg.c and Reg_eSys_Ftm.h have different vendor ids"
#endif
/* Check if header file and Reg_eSys_Ftm.h header file are of the same Autosar version */
#if ((PWM_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_PBCFG_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif
/* Check if header file and Reg_eSys_Ftm.h header file are of the same software version */
#if ((PWM_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (PWM_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (PWM_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_PBcfg.c and Reg_eSys_Ftm.h are different"
#endif

/* Check if header file and Ftm_Common_Types.h header file are of the same vendor */
#if (PWM_PBCFG_VENDOR_ID_C != FTM_COMMON_TYPES_VENDOR_ID)
    #error "Pwm_PBcfg.c and Ftm_Common_Types.h have different vendor ids"
#endif
/* Check if header file and Ftm_Common_Types.h header file are of the same Autosar version */
#if ((PWM_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_PBCFG_AR_RELEASE_MINOR_VERSION_C    != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_PBcfg.c and Ftm_Common_Types.h are different"
#endif
/* Check if header file and Ftm_Common_Types.h header file are of the same software version */
#if ((PWM_PBCFG_SW_MAJOR_VERSION_C != FTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (PWM_PBCFG_SW_MINOR_VERSION_C != FTM_COMMON_TYPES_SW_MINOR_VERSION) || \
     (PWM_PBCFG_SW_PATCH_VERSION_C != FTM_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_PBcfg.c and Ftm_Common_Types.h are different"
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
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_PBcfg_C_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


/** @brief Prototypes of Pwm channels User Notifications */  
  
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_PBcfg_C_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Pwm_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Pwm_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*  contents of a header file being included twice.*/
/* @violates @ref Pwm_PBcfg_C_REF_3 MISRA 2004 Required Rule 19.1, only preprocessor statements 
*  and comments before "#include" */
#include "Pwm_MemMap.h"

 


/** 
* @brief Number of configured Pwm channels 
*/
#define PWM_CONF_CHANNELS_PB            ((uint8) 3U)

/** 
* @brief Number of configured Ftm channels 
*/
#define PWM_FTM_MOD_CONFIGS_PB         ((uint8) 2U)

/** 
* @brief Number of configured Ftm channels 
*/
#define PWM_CONF_FTM_CHANNELS_PB         ((uint8) 3U)



/** @brief Configurations for Pwm channels using Ftm */
static CONST(Pwm_Ftm_ChannelConfigType, PWM_CONST) Pwm_Ftm_ChannelConfig_PB[PWM_CONF_FTM_CHANNELS_PB] =
{
    /** @brief PWM_FTM_CHANNEL_0 */
    {
        /** @brief Pwm channel polarity */
        PWM_HIGH,

        /** @brief Pwm channel idle state */
        PWM_LOW,

        /** @brief Default duty cycle value */
        ((uint16)16384),
        
        /** @brief Ftm Channel Id */
        FTM_0_CH_0,
        
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        /** @brief Default phase shift value */
        ((uint16)0),
#endif
        /** @brief Edge alignment for the current channel  */    
        PWM_EDGE_ALIGNED
    },     
   
    /** @brief PWM_FTM_CHANNEL_1 */
    {
        /** @brief Pwm channel polarity */
        PWM_HIGH,

        /** @brief Pwm channel idle state */
        PWM_LOW,

        /** @brief Default duty cycle value */
        ((uint16)16384),
        
        /** @brief Ftm Channel Id */
        FTM_0_CH_1,
        
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        /** @brief Default phase shift value */
        ((uint16)0),
#endif
        /** @brief Edge alignment for the current channel  */    
        PWM_EDGE_ALIGNED
    },     
   
    /** @brief PWM_FTM_CHANNEL_2 */
    {
        /** @brief Pwm channel polarity */
        PWM_HIGH,

        /** @brief Pwm channel idle state */
        PWM_LOW,

        /** @brief Default duty cycle value */
        ((uint16)16384),
        
        /** @brief Ftm Channel Id */
        FTM_2_CH_0,
        
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        /** @brief Default phase shift value */
        ((uint16)0),
#endif
        /** @brief Edge alignment for the current channel  */    
        PWM_EDGE_ALIGNED
    }
   
};
/** @brief Array of configurations for all Ftm modules supported by the platform */
/*
* @violates @ref Pwm_Cfg_C_REF_2 external ... could be made static
*/
static CONST(Pwm_Ftm_ModuleConfigType, PWM_CONST) Pwm_Ftm_ModuleConfig_PB[PWM_FTM_MOD_CONFIGS_PB] =
{
  
    /* Ftm Module 0 */
    {
        /** @brief FTM_0_CONF */
        (FTM_CONF_BDMMODE_ALLRUN_U32 | ((uint32) 0U) | ((uint32) 0)),
      
        /** @brief FTM_0_SC register */
        (FTM_SC_CLKS_SYS_CLOCK_U32 | FTM_SC_PS_DIV128_U32 |  ((uint32)1U << (FTM_SC_PWMOUTPUTEN_SHIFT + (uint32)1U ))| ((uint32)1U << (FTM_SC_PWMOUTPUTEN_SHIFT + (uint32)0U ))| ((uint32)0)),

        
        /** @brief FTM_0_SYNC register */
        (uint8) (FTM_SYNC_CNTMIN_ENABLE_U32 | ((uint32) 0)),
         
        /** @brief FTM_0_MODE register used to enable other features of the FTM */
        (FTM_MODE_INIT_ENABLE_U32 | FTM_MODE_FTMEN_ENABLE_U32 | FTM_MODE_WPDIS_DISABLE_U32 | ((uint32)0)),    
 
        /** @brief FTM_0_DEADTIME register */
        (FTM_DEADTIME_DTPS_DIV1_U32 | ((uint32) 0U)),

        /** @brief FTM_0_COMBINE register */
        (FTM_COMBINE_SYNCEN0_ENABLE_U32 | ((uint32) 0)),
        
         /** @brief Id of the referenced FTM module: FTM_0 */
        PWM_FTM_0,
        
        /** @brief Default period value: , freq = 100.0 Hz: FTM_0_MOD register*/
        ((Pwm_PeriodType) 6250)
            
#if (PWM_FAULT_SUPPORTED == STD_ON)
        ,

        /** @brief FTM_0_FLTCTRL register */
        ((uint32) 0),

        /** @brief FTM_0_FLTPOL register */
        ((uint32) 0),
        
        /** @brief Fault notification callbacks */
       { NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR }
#endif /* (PWM_FAULT_SUPPORTED == STD_ON) */
    },     
  
    /* Ftm Module 1 */
    {
        /** @brief FTM_2_CONF */
        (FTM_CONF_BDMMODE_ALLSTOP_U32 | ((uint32) 0U) | ((uint32) 0)),
      
        /** @brief FTM_2_SC register */
        (FTM_SC_CLKS_SYS_CLOCK_U32 | FTM_SC_PS_DIV128_U32 |  ((uint32)1U << (FTM_SC_PWMOUTPUTEN_SHIFT + (uint32)0U ))| ((uint32)0)),

        
        /** @brief FTM_2_SYNC register */
        (uint8) (FTM_SYNC_CNTMIN_ENABLE_U32 | ((uint32) 0)),
         
        /** @brief FTM_2_MODE register used to enable other features of the FTM */
        (FTM_MODE_INIT_ENABLE_U32 | FTM_MODE_FTMEN_ENABLE_U32 | FTM_MODE_WPDIS_DISABLE_U32 | ((uint32)0)),    
 
        /** @brief FTM_2_DEADTIME register */
        (FTM_DEADTIME_DTPS_DIV1_U32 | ((uint32) 0U)),

        /** @brief FTM_2_COMBINE register */
        (FTM_COMBINE_SYNCEN0_ENABLE_U32 | ((uint32) 0)),
        
         /** @brief Id of the referenced FTM module: FTM_2 */
        PWM_FTM_2,
        
        /** @brief Default period value: , freq = 400.1280409731114 Hz: FTM_2_MOD register*/
        ((Pwm_PeriodType) 1562)
            
#if (PWM_FAULT_SUPPORTED == STD_ON)
        ,

        /** @brief FTM_2_FLTCTRL register */
        ((uint32) 0),

        /** @brief FTM_2_FLTPOL register */
        ((uint32) 0),
        
        /** @brief Fault notification callbacks */
       { NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR }
#endif /* (PWM_FAULT_SUPPORTED == STD_ON) */
    }
};
/**
@brief Ftm IP configuration
*/
static CONST(Pwm_Ftm_IpConfigType, PWM_CONST) Pwm_Ftm_IpConfig_PB=
{
    /** @brief Number of Ftm channels in each Ftm module used in the current Pwm configuration */
     PWM_CONF_FTM_CHANNELS_PB,
 
    /** @brief Number of Ftm modules in the Pwm configuration */
     PWM_FTM_MOD_CONFIGS_PB,
    
    /** @brief Pointer to the array of Ftm enabled Pwm channel configurations */
    &Pwm_Ftm_ChannelConfig_PB, 

    /** @brief Pointer to the array of Ftm Module configurations */
    &Pwm_Ftm_ModuleConfig_PB 
};

/** @brief Array of configured Pwm channels */
/*
* @violates @ref Pwm_PBcfg_C_REF_2 external ... could be made static
*/
static CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_Channels_PB[PWM_CONF_CHANNELS_PB] =
{
   /** @brief PwmChannel_0 */
    {
        /** @brief Channel class: Variable/Fixed/Fixed_Shifted period */
        PWM_FIXED_PERIOD
        
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        ,
        
        /** @brief Pwm notification function */
        NULL_PTR
#endif
 
    },     

   /** @brief PwmChannel_1 */
    {
        /** @brief Channel class: Variable/Fixed/Fixed_Shifted period */
        PWM_FIXED_PERIOD
        
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        ,
        
        /** @brief Pwm notification function */
        NULL_PTR
#endif
 
    },     

   /** @brief PwmChannel_2 */
    {
        /** @brief Channel class: Variable/Fixed/Fixed_Shifted period */
        PWM_FIXED_PERIOD
        
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        ,
        
        /** @brief Pwm notification function */
        NULL_PTR
#endif
 
    }


};


/**
@brief   Pwm channels IP related configuration array
*/
static CONST(Pwm_IpChannelConfigType, PWM_CONST) Pwm_IpChannelConfig_PB[PWM_CONF_CHANNELS_PB] =
{
    /** @brief PwmChannel_0 */
    ((uint8) 0),    
    
    /** @brief PwmChannel_1 */
    ((uint8) 1),    
    
    /** @brief PwmChannel_2 */
    ((uint8) 2),    
    
};


/**
@brief   Pwm high level configuration structure
*/
/*
* @violates @ref Pwm_PBcfg_C_REF_2 external ... could be made static
*/
CONST(Pwm_ConfigType, Pwm_CONST) PwmChannelConfigSet=
{
   /** @brief Number of configured Pwm channels */
    (Pwm_ChannelType)PWM_CONF_CHANNELS_PB,
    /** @brief Pointer to array of Pwm channels */
    &Pwm_Channels_PB,
    /** @brief IP specific configuration */
    {             
        /** @brief Pointer to the structure containing Ftm configuration */
        &Pwm_Ftm_IpConfig_PB,
         /** @brief Pointer to Array containing channel IP related information */
        &Pwm_IpChannelConfig_PB        
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    ,
    /** @brief Hw to logic channel map. Array containing a number of elements
    equal to total number of available channels on FTM IPV */
    {
        /* Idx of channels 0-7 of Ftm Module 0 in the array of logic Pwm channels */
        (Pwm_ChannelType)0, (Pwm_ChannelType)1, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255,
        /* Idx of channels 0-7 of Ftm Module 1 in the array of logic Pwm channels */
        (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255,
        /* Idx of channels 0-7 of Ftm Module 2 in the array of logic Pwm channels */
        (Pwm_ChannelType)2, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255,
        /* Idx of channels 0-7 of Ftm Module 3 in the array of logic Pwm channels */
        (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255, (Pwm_ChannelType)255
    }
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */ 
};


/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Pwm_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Pwm_PBcfg_C_REF_3 #include statements in a file should
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

