/**
*   @file    Mcl_DmaMux_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Exported data outside of the Mcl from DMAMUX.
*   @details Public data types exported outside of the Mcl driver.
*
*   @addtogroup MCL_MODULE
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


#ifndef MCL_DMAMUX_TYPES_H
#define MCL_DMAMUX_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_DMAMUX_Types_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"
#include "Soc_Ips.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_DMAMUX_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCL_DMAMUX_TYPES_VENDOR_ID                       43
#define MCL_DMAMUX_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCL_DMAMUX_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCL_DMAMUX_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCL_DMAMUX_TYPES_SW_MAJOR_VERSION                1
#define MCL_DMAMUX_TYPES_SW_MINOR_VERSION                0
#define MCL_DMAMUX_TYPES_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
 /* Check if header file and MCL configuration header file are of the same vendor */
#if (MCL_DMAMUX_TYPES_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "Mcl_DmaMux_Types.h and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and MCL configuration header file are of the same Autosar version */
#if ((MCL_DMAMUX_TYPES_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_DMAMUX_TYPES_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_DMAMUX_TYPES_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcl_DmaMux_Types.h and CDD_Mcl_Cfg.h are different"
#endif
/* Check if header file and MCL configuration header file are of the same software version */
#if ((MCL_DMAMUX_TYPES_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_DMAMUX_TYPES_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_DMAMUX_TYPES_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcl_DmaMux_Types.h and CDD_Mcl_Cfg.hare different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Soc_Ips.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != MCL_DMAMUX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != MCL_DMAMUX_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Mcl_DmaMux_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

/* Mcl_DmaMuxChannelType possible values. */
#define DMA_MUX_CH_0       (0U)
#define DMA_MUX_CH_1       (1U)
#define DMA_MUX_CH_2       (2U)
#define DMA_MUX_CH_3       (3U)
#define DMA_MUX_CH_4       (4U)
#define DMA_MUX_CH_5       (5U)
#define DMA_MUX_CH_6       (6U)
#define DMA_MUX_CH_7       (7U)
#define DMA_MUX_CH_8       (8U)
#define DMA_MUX_CH_9       (9U)
#define DMA_MUX_CH_10      (10U)
#define DMA_MUX_CH_11      (11U)
#define DMA_MUX_CH_12      (12U)
#define DMA_MUX_CH_13      (13U)
#define DMA_MUX_CH_14      (14U)
#define DMA_MUX_CH_15      (15U)


/* Mcl_DmaMuxInstanceType possible values. */
#define DMA_MUX_0       (0U)
#define DMA_MUX_1       (1U)
#define DMA_MUX_2       (2U)
#define DMA_MUX_3       (3U)
#define DMA_MUX_4       (4U)
#define DMA_MUX_5       (5U)
#define DMA_MUX_6       (6U)
#define DMA_MUX_7       (7U)
#define DMA_MUX_8       (8U)
#define DMA_MUX_9       (9U)

/* DMAMUX_CHCFGn[ENBL] possible values. */
#define DMAMUX_CHANNEL_EN_U32               ((uint32)0x80U)
#define DMAMUX_CHANNEL_DIS_U32              ((uint32)0x00U)

/* DMAMUX_CHCFGn[TRIG] possible values. */
#define DMAMUX_CHANNEL_TRIG_EN_U32          ((uint32)0x40U)
#define DMAMUX_CHANNEL_TRIG_DIS_U32         ((uint32)0x00U)

/* DMAMUX_CHCFGn[SOURCE] possible values. */
/** @violates @ref Mcl_DMAMUX_Types_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define DMAMUX_CHANNEL_DMA_SOURCE(src)  ((src) & (uint8)0x3FU)

/* DMAMUX0_CHCONF  */
/** @violates @ref Mcl_DMAMUX_Types_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define DMAMUX0_CHCONF_ADDR8(channel) ((uint32)DMAMUX0_BASEADDR + (channel))
/* DMAMUX1_CHCONF  */
/** @violates @ref Mcl_DMAMUX_Types_h_REF_4 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define DMAMUX1_CHCONF_ADDR8(channel) ((uint32)DMAMUX1_BASEADDR + (channel))


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   DmaMux channel type
*/
typedef uint8 Mcl_DmaMuxChannelType;
/**
* @brief   DmaMux instance type
*/
typedef uint8 Mcl_DmaMuxInstanceType;

/**
* @brief      DmaMux channel configuration structure
*/
typedef struct
{
    /** @brief DmaMux channel used */
    CONST(Mcl_DmaMuxChannelType,  MCL_CONST) DmaMux_Channel;
    /** @brief DmaMux instance used */
    CONST(Mcl_DmaMuxInstanceType,  MCL_CONST) DmaMux_Instance;    
    /** @brief Channel Enable, Trig and Source */
    CONST(Mcl_DmaMuxChannelType, MCL_CONST)  DmaMux_ChannelConfig;

} Mcl_DmaMuxChannelConfigType;


/**
* @brief      DmaMux configuration structure
*/
typedef struct 
{
    /** @brief Number of DmaMux configured channels */
    CONST(Mcl_DmaMuxChannelType,           MCL_CONST)                     NumChannels;   
    /** @brief Pointer to the list of Dma configured channels */
    CONST(Mcl_DmaMuxChannelConfigType, MCL_CONST)                       (* const pDmaMuxChannelsConfig)[];  

} Mcl_DmaMuxConfigType;


#endif /* (MCL_ENABLE_DMA == STD_ON) */
#endif /* #ifdef MCL_ENABLE_DMA */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCL_DMAMUX_TYPES_H */

/** @} */
