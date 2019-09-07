/**
*   @file    CDD_Mcl_PBcfg.c
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
* @section Mcl_PBcfg_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file Mcl_MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
* 
* @section Mcl_PBcfg_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' Mcl_MemMap.h included after each section define in order to set the current memory section
*
* @section Mcl_PBcfg_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcl_PBcfg_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed 
* between a pointer to object type and a different pointer to object type.
*
* @section Mcl_PBcfg_REF_6
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and 
* functions shall not be reused
*
* @section Mcl_PBcfg_REF_7
* Violates MISRA 2004 Required Rule 12.7, Bitwise operators shall not be applied to operands whose
* underlying type is signed.
*
* @section Mcl_PBcfg_REF_8
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*
* @section Mcl_PBcfg_REF_9
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* a preceding &, or with a paranthesised parameter list, which may be empy.
*
* @section Mcl_PBcfg_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope should have internal linkage unless external linkage is required.
*
* @section Mcl_PBcfg_REF_11
* Violates MISRA 2004 Required Rule 8.8, All external objects should be declared in one and only one
* file.
* The declaration used to import definition of user callback function.
*
* @section Mcl_PBcfg_REF_12
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
* @file             CDD_Mcl_PBcfg.c
* @requirements     BSW00374, BSW00318
*/
#define MCL_PBCFG_VENDOR_ID_C                     43
/** @violates @ref Mcl_PBcfg_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Mcl_PBcfg_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Mcl_PBcfg_REF_3 MISRA 2004 Rule 1.4,
*   The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are supported for external identifiers.*/
#define MCL_PBCFG_AR_RELEASE_REVISION_VERSION_C   2
#define MCL_PBCFG_SW_MAJOR_VERSION_C              1
#define MCL_PBCFG_SW_MINOR_VERSION_C              0
#define MCL_PBCFG_SW_PATCH_VERSION_C              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if config source file and MCL header file are of the same vendor */
#if (MCL_PBCFG_VENDOR_ID_C != MCL_VENDOR_ID)
#error "CDD_Mcl_PBcfg.c and CDD_Mcl.h have different vendor IDs"
#endif
/* Check if config source file and MCL header file are of the same Autosar version */
#if ((MCL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_Mcl_PBcfg.c and CDD_Mcl.h are different"
#endif
/* Check if config source file and MCL header file are of the same Software version */
#if ((MCL_PBCFG_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION) || \
     (MCL_PBCFG_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION) || \
     (MCL_PBCFG_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl_PBcfg.c and CDD_Mcl.h are different"
#endif


/* Check if config source file and Mcl_IPW header file are of the same vendor */
#if (MCL_PBCFG_VENDOR_ID_C != MCL_IPW_VENDOR_ID)
#error "CDD_Mcl_PBcfg.c and Mcl_IPW.h have different vendor IDs"
#endif
/* Check if config source file and Mcl_IPW header file are of the same version */
#if ((MCL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCL_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCL_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCL_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCL_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of CDD_Mcl_PBcfg.c and Mcl_IPW.h are different"
#endif
/* Check if config source file and Mcl_IPW header file are of the same Software Version */
#if ((MCL_PBCFG_SW_MAJOR_VERSION_C != MCL_IPW_SW_MAJOR_VERSION) || \
     (MCL_PBCFG_SW_MINOR_VERSION_C != MCL_IPW_SW_MINOR_VERSION) || \
     (MCL_PBCFG_SW_PATCH_VERSION_C != MCL_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_Mcl_PBcfg.c and Mcl_IPW.h are different"
#endif

        
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
#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_PBcfg_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"



#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/* DMA Channel Transfer Completion Notifications */
    
#endif

/* DMA error notifications */
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)

#endif



#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_PBcfg_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"



#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcl_PBcfg_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
*                            statements and comments before '#include'
*/
#include "Mcl_MemMap.h"


            
    /**
  * @brief Number of configured Dma channels
  */
#define MCL_DMA_CONF_CHANNELS_PB   1U


/**
  * @brief Number of configured DmaMux channels
  */
#define MCL_DMAMUX_CONF_CHANNELS  1U


/** @brief Configuration for Dma channels */
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */



static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig[MCL_DMA_CONF_CHANNELS_PB] =

{
    /** @brief DMAChannel_0 - eDMA_0 */
    { 
        /** @brief Enable Channel Preemption */
        (DMA_ECP_DIS_U8) |
        /** @brief Disable Preempt Ability */
        (DMA_DPA_DIS_U8) |
        /** @brief Channel Priority */
        (DMA_PRIORITY_0_U8),
        /** @brief eDMA HW Channel used by the Mcl channel */
        DMA_HW_CHANNEL_0,
        /** @brief Master ID Replication */
                DMA_EMI_DIS_U8

    }
};

/** @brief Configuration for Dma instances */
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */

/** @brief Configuration for Dma instances */

/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig[MCL_DMA_NB_CONTROLLERS] =
 
{
{
    /** @brief Dma Hardware Instance 0*/
    /** @brief Dma CR Register */
    (uint32)((DMA_CANCEL_TRANSFER_DIS_U32) |
    (DMA_ERROR_CANCEL_TRANSFER_DIS_U32) | 
    (DMA_CONT_LINK_MODE_DIS_U32) |
    (DMA_HALT_OPERATIONS_DIS_U32) |
    (DMA_HALT_ON_ERROR_DIS_U32) |    (DMA_ROUND_ROBIN_ARB_DIS_U32) |
    /** @violates @ref Mcl_PB_PC_Cfg_c_REF_11 Boolean operation whose results are invariant shall not be permitted */
    (DMA_DEBUG_DIS_U32)),
    /** @brief Dma Usage in Configuration */

        DMA_INSTANCE_USED
    
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ,
    /** @brief DMA error notification function */    NULL_PTR
#endif
    }

};

/**
* @brief            DMA basic configuration
* @details          Configuration for DMA hw IP.
*                   Include Control Register and Channel Priorities.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */
CONST( Mcl_DmaConfigType, MCL_CONST) Dma_Config =
    {
        /** @brief Number of configured eDMA channels. */
        1U,  
        &Mcl_Dma_InstanceConfig,
        /** @brief Pointer to the structure containing DMA channel configuration */
        &Mcl_Dma_ChannelConfig
    };

/** @brief Configuration for DmaMux channels */

static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig[MCL_DMA_CONF_CHANNELS_PB] =

{

    {
        /** @brief Hardware DMAMUX channel used */
        DMA_MUX_CH_0,
        /** @brief DMAMUX instance used */
        DMA_MUX_0,
        /** @brief DMAMUX_CHCFGn register configuration */
        (uint8)((DMAMUX_CHANNEL_DIS_U32) |
        (DMAMUX_CHANNEL_TRIG_DIS_U32) |
        (0U))
    }

};


/**
* @brief            DMA_MUX basic configuration.
* @details          Configuration for DMA_MUX hw IP.
*                   The DMA_MUX allows to route DMA sources to DMA channels.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */
CONST( Mcl_DmaMuxConfigType, MCL_CONST) DmaMux_Config =
    {
        /** @brief Number of configured DMA channels which are also linked to DMAMUX. */
        MCL_DMAMUX_CONF_CHANNELS,   
        /** @brief Pointer to the structure containing DMAMUX channel configuration */
        &Mcl_DmaMux_ChannelConfig
    };

/** @brief Array of configured Mcl channels */
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */
CONST(Mcl_ChannelConfigType, MCL_CONST) Mcl_ChannelConfig[MCL_DMA_CONF_CHANNELS_PB] =
{
    /** @brief DMAChannel_0 */
    {
        /** @brief Number of configured Mcl channel. */
        DMA_HW_CHANNEL_0,
#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        /** @brief DMA notification function */
        NULL_PTR
#endif
  /**  @violates @ref Mcl_PBcfg_REF_9 MISRA 2004 Rule 16.9, function identifier */
    }
};

/**
* @brief          Initialization data for different hw IPs.
* @details        Configuration realized at statup by calling Mcl_Init() API.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */
CONST( Mcl_DmaHwIpsConfigType, MCL_CONST) Mcl_HwIPs_Config =
    {
        /* Configuration for eDMA (Enhanced Direct Memory Access) hardware IP. */
        &Dma_Config

        ,
        /* Configuration for DMA_MUX (eDMA Channel Mux) hardware IP. */
        &DmaMux_Config
    };
    
/**
* @brief            Dma basic configuration.
* @details          Configuration for Dma.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */

CONST( Mcl_DmaInitConfigType, MCL_CONST) Mcl_Dma_InitConfig=
    {
        /** @brief Number of configured eDMA channels. */
        1U,
        /** @brief Pointer to the structure containing Mcl channel configuration */
        &Mcl_ChannelConfig,
        /**< @brief IPs data generic configuration. */
        &Mcl_HwIPs_Config
        #if ((MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON) || (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON))
        ,
        /** @brief Hw to logic channel map. Array containing a number of elements
        equal to total number of available DMA channels  */
        {
                    (Mcl_ChannelType)MCL_DMA_LOGICAL_CHANNEL_0,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8,
            (Mcl_ChannelType)MCL_DMA_CHANNEL_NOT_CONFIGURED_U8

        }       
        #endif /* MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON || MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON */ 
    };

 

/**
* @brief            Mcl basic configuration.
* @details          Configuration for Mcl.
*
*/
/** @violates @ref Mcl_PBcfg_REF_10 external ... could be made static */

CONST( Mcl_ConfigType, MCL_CONST) MclConfigSet_0 =

{
 
 
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /** Configuration for the Dem errors */
        &Mcl_Dem_Config,
#endif        
        /** Configuration for the Dma and DmaMu IPs */
        &Mcl_Dma_InitConfig
         

    
    };


#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcl_PBcfg_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcl_PBcfg_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
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

