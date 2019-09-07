/**
*   @file CDD_Mcl_Cfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - contains the configuration data of the MCL driver
*   @details Contains the configuration data of the MCL driver
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




#ifndef CDD_MCL_CFG_H
#define CDD_MCL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif 
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*          contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of configuration sets or for a function define.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcl_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Mcl_EnvCfg.h"
#include "Mcal.h"

    
    
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_VENDOR_ID_CFG                       43

#define MCL_AR_RELEASE_MAJOR_VERSION_CFG        4
#define MCL_AR_RELEASE_MINOR_VERSION_CFG        2
#define MCL_AR_RELEASE_REVISION_VERSION_CFG     2

#define MCL_SW_MAJOR_VERSION_CFG                1
#define MCL_SW_MINOR_VERSION_CFG                0
#define MCL_SW_PATCH_VERSION_CFG                1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (MCL_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Check if header file and Dem.h file are of the same Autosar version */

#if (MCL_VENDOR_ID_CFG != MCL_ENVCFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.h and Mcl_EnvCfg.h have different vendor ids"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same Autosar version */
#if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( MCL_AR_RELEASE_MINOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     ( MCL_AR_RELEASE_REVISION_VERSION_CFG !=  MCL_ENVCFG_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION_CFG != MCL_ENVCFG_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_CFG != MCL_ENVCFG_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_CFG != MCL_ENVCFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
    

#define MCL_PRECOMPILE_SUPPORT (STD_OFF)




/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_DEV_ERROR_DETECT                  (STD_ON)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_GetVersionInfo() from the code.
*        STD_ON: Mcl_GetVersionInfo() can be used. STD_OFF: Mcl_GetVersionInfo() can not be used.
*   
*/
#define MCL_GET_VERSION_INFO_API              (STD_ON)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DeInit() from the code.
*        STD_ON: Mcl_DeInit() can be used. STD_OFF: Mcl_DeInit() can not be used.
*   
*/
#define MCL_DEINIT_API                        (STD_OFF)

/**
*   @brief   Switches DMA features initialization on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_ENABLE_DMA              (STD_ON)

/**
*   @brief  Switches the TRGMUX initialization by MCL on or off
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_ENABLE_TRGMUX                   (STD_OFF)
/**
* @brief define number of trigger mux registers
*/
#define MCL_NUM_TRGMUX_REG                  (25U)
#define MCL_NUM_REG_MISSING_SEL_FIELD       (9U)
#define MCL_MAXIMUM_BIT_FIELD_TRIGGER_VALUE  (0x63U)

#define MCL_TRGMUX_DMAMUX0_AVAILABLE
#define MCL_TRGMUX_EXTOUT0_AVAILABLE
#define MCL_TRGMUX_EXTOUT1_AVAILABLE
#define MCL_TRGMUX_ADC0_AVAILABLE
#define MCL_TRGMUX_ADC1_AVAILABLE
#define MCL_TRGMUX_CMP0_AVAILABLE
#define MCL_TRGMUX_FTM0_AVAILABLE
#define MCL_TRGMUX_FTM1_AVAILABLE
#define MCL_TRGMUX_FTM2_AVAILABLE
#define MCL_TRGMUX_FTM3_AVAILABLE
#define MCL_TRGMUX_PDB0_AVAILABLE
#define MCL_TRGMUX_PDB1_AVAILABLE
#define MCL_TRGMUX_FLEXIO_AVAILABLE
#define MCL_TRGMUX_LPIT0_AVAILABLE
#define MCL_TRGMUX_LPUART0_AVAILABLE
#define MCL_TRGMUX_LPUART1_AVAILABLE
#define MCL_TRGMUX_LPI2C0_AVAILABLE
#define MCL_TRGMUX_LPSPI0_AVAILABLE
#define MCL_TRGMUX_LPSPI1_AVAILABLE
#define MCL_TRGMUX_LPTMR0_AVAILABLE


 
/**
* @brief      This define specifies enable or disable initialization of DCHMID register in DMA
*
*/
#define MCL_DMA_ENABLE_INIT_DCHMID (STD_OFF) 
/**
* @brief      This define specifies the number of eDma Channels available for one eDma instance
*
*/
#define MCL_DMA_NB_CHANNELS                      (0x10U)
/**
* @brief      This define specifies the number of eDma instances
*
*/
#define MCL_DMA_NB_CONTROLLERS                   (0x1U)
/**
* @brief      This define specifies the number of eDma Mux instances
*
*/
#define MCL_DMAMUX_NB_MODULES                    (0x1U)

/**
* @brief      This define specifies the access to registers of dmamux is Little Endian or not
*
*/
#define MCL_DMAMUX_CHCFG_LITTLE_ENDIAN        (STD_OFF)

/**
* @brief      The defines bellow specify the DMAMUX sources
*
*/
        
/** @brief DMA Channel Sources for DmaMux Instance 0 */
#define MCL_DMA_MUX_0_LPUART0_RX (2U)
#define MCL_DMA_MUX_0_LPUART0_TX (3U)
#define MCL_DMA_MUX_0_LPUART1_RX (4U)
#define MCL_DMA_MUX_0_LPUART1_TX (5U)
#define MCL_DMA_MUX_0_LPUART2_RX (6U)
#define MCL_DMA_MUX_0_LPUART2_TX (7U)
#define MCL_DMA_MUX_0_FLEXIO_SHIFTER0 (10U)
#define MCL_DMA_MUX_0_FLEXIO_SHIFTER1 (11U)
#define MCL_DMA_MUX_0_FLEXIO_SHIFTER2 (12U)
#define MCL_DMA_MUX_0_FLEXIO_SHIFTER3 (13U)
#define MCL_DMA_MUX_0_LPSPI0_RX (14U)
#define MCL_DMA_MUX_0_LPSPI0_TX (15U)
#define MCL_DMA_MUX_0_LPSPI1_RX (16U)
#define MCL_DMA_MUX_0_LPSPI1_TX (17U)
#define MCL_DMA_MUX_0_LPSPI2_RX (18U)
#define MCL_DMA_MUX_0_LPSPI2_TX (19U)
#define MCL_DMA_MUX_0_FTM1_CH_0 (20U)
#define MCL_DMA_MUX_0_FTM1_CH_1 (21U)
#define MCL_DMA_MUX_0_FTM1_CH_2 (22U)
#define MCL_DMA_MUX_0_FTM1_CH_3 (23U)
#define MCL_DMA_MUX_0_FTM1_CH_4 (24U)
#define MCL_DMA_MUX_0_FTM1_CH_5 (25U)
#define MCL_DMA_MUX_0_FTM1_CH_6 (26U)
#define MCL_DMA_MUX_0_FTM1_CH_7 (27U)
#define MCL_DMA_MUX_0_FTM2_CH_0 (28U)
#define MCL_DMA_MUX_0_FTM2_CH_1 (29U)
#define MCL_DMA_MUX_0_FTM2_CH_2 (30U)
#define MCL_DMA_MUX_0_FTM2_CH_3 (31U)
#define MCL_DMA_MUX_0_FTM2_CH_4 (32U)
#define MCL_DMA_MUX_0_FTM2_CH_5 (33U)
#define MCL_DMA_MUX_0_FTM2_CH_6 (34U)
#define MCL_DMA_MUX_0_FTM2_CH_7 (35U)
#define MCL_DMA_MUX_0_FTM0_CH_0_7 (36U)
#define MCL_DMA_MUX_0_FTM3_CH_0_7 (37U)
#define MCL_DMA_MUX_0_ADC0_COCO (42U)
#define MCL_DMA_MUX_0_ADC1_COCO (43U)
#define MCL_DMA_MUX_0_LPI2C0_RX (44U)
#define MCL_DMA_MUX_0_LPI2C0_TX (45U)
#define MCL_DMA_MUX_0_PDB0 (46U)
#define MCL_DMA_MUX_0_PDB1 (47U)
#define MCL_DMA_MUX_0_CMP0 (48U)
#define MCL_DMA_MUX_0_PCM_PORT_A (49U)
#define MCL_DMA_MUX_0_PCM_PORT_B (50U)
#define MCL_DMA_MUX_0_PCM_PORT_C (51U)
#define MCL_DMA_MUX_0_PCM_PORT_D (52U)
#define MCL_DMA_MUX_0_PCM_PORT_E (53U)
#define MCL_DMA_MUX_0_FLEXCAN0 (54U)
#define MCL_DMA_MUX_0_FLEXCAN1 (55U)
#define MCL_DMA_MUX_0_FLEXCAN2 (56U)
#define MCL_DMA_MUX_0_LPTMR0 (59U)
#define MCL_DMA_MUX_0_ALWAYS_ENABLED_0 (62U)
#define MCL_DMA_MUX_0_ALWAYS_ENABLED_1 (63U)
#define MCL_DMA_MUX_0_NOT_USED (64U)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DmaGetChannelErrorStatus() from the code.
*        STD_ON: Mcl_DmaGetChannelErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetChannelErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_CH_ERR_STATUS_API            (STD_OFF)

/**
*   @brief  Adds or removes the service Mcl_DmaGetGlobalErrorStatusApi() from the code.
*        STD_ON: Mcl_DmaGetGlobalErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetGlobalErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_GLOBAL_ERR_STATUS_API            (STD_OFF)

/**
* @brief      This define specifies the number of eTimer channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_NO            (16U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_IN_GROUP            (16U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_DMA_ERROR_INTERRUPTS_USED            (STD_ON)

/**
* @brief      This define specifies if there is only one transfer completion ISR for all DMA channels within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_COMBINED_TR_COMPLETION_ISR (STD_OFF)

/**
* @brief      This define specifies if there is one transfer completion ISR for each group of DMA channels within a DMA instance
*
*/
#define MCL_DMA_COMBINED_GROUP_COMPLETION_ISR (STD_OFF)

#if (MCL_DMA_COMBINED_GROUP_COMPLETION_ISR == STD_ON)


#endif

/**
* @brief      This define specifies if there is only one error ISR for all DMA instances
*             or if there is an error ISR for each DMA instance
*
*/
#define MCL_DMA_COMBINED_ERROR_ISR (STD_OFF)
/**
* @brief      This define specifies if there is Ecc error reporting available          
*
*/
#define MCL_DMA_ECC_REPORTING_ENABLED (STD_OFF)

/** 
* @brief  Switch to globaly enable/disable the production error reporting.
*/
#define MCL_DISABLE_DEM_REPORT_ERROR_STATUS  (STD_ON)



/**
* @brief      This define specifies if there is only one transfer completion ISR for a DMA channel within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_TR_SEPARATED_ISR (STD_OFF)

/**
* @brief      This define specifies if inside a DMA instance some channels have the same transfer completion ISR assigned,
*             and other channels have their own transfer completion ISR.
*
*/
#define MCL_DMA_TR_COMPLETION_MIXED_ISR (STD_OFF)

/** Define to specify if least one transfer completion interrupt and notification is used, 
*      needed for removing at precompile time the code for ISR handling for the transfer 
*      completion notification processing. This define is needed in both combined transfer
*      completion interrupt and single channel mode. */
#define MCL_DMA_NOTIFICATION_SUPPORTED              (STD_OFF)

/* Transfer size options available */
#define MCL_TRANSFER_SIZE_1_BYTE 
#define MCL_TRANSFER_SIZE_2_BYTE 
#define MCL_TRANSFER_SIZE_4_BYTE 
#define MCL_TRANSFER_SIZE_16_BYTE 
#define MCL_TRANSFER_SIZE_32_BYTE 




/**
* @brief            Support for User mode.
*                   STD_ON: the Mcl driver can be executed from both supervisor and user mode. 
*                   STD_OFF: the Mcl driver can be executed only from supervisor mode. 
*/
#define MCL_ENABLE_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_DMAMUX_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_AXBS_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_LMEM_USER_MODE_SUPPORT     (STD_ON)
#define MCL_TRGMUX_USER_MODE_SUPPORT     (STD_ON)
/**
* @brief            Protected Register in User mode
*                   Macro use to enable if IP hw need to configure Reg_Prot to access from user mode
*/

#define MCL_DMAMUX_REG_PROT_AVAILABLE (STD_OFF)


#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Mcl in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif /* (STD_ON == MCL_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */


/*********************************** CACHE SECTION ***********************************/
/* Enable LMEM cache functionality */
#define MCL_LMEM_ENABLE_CACHE_API           (STD_OFF)

/* Enable the use of cache invalidate and flush calls in other drivers */
#define MCL_SYNCRONIZE_CACHE                (STD_OFF)

/* LMEM Cache operations timeout value */
#define MCL_LMEM_CACHE_TIMEOUT_VALUE        (2147483647UL)

/* LMEM Enable also Write Buffer alongside with Cache enable */
#define MCL_LMEM_CACHE_ENABLE_WRITE_BUFFER  (STD_OFF)

/* PS Cache instance hardware availability */
#define MCL_LMEM_CACHE_PS_AVAILABLE         (STD_OFF)

/* PC cache total size, expressed in bytes */
#define MCL_LMEM_CACHE_PC_SIZE              ((uint32)4096UL)

/* PS cache total size, expressed in bytes */
#define MCL_LMEM_CACHE_PS_SIZE              ((uint32)0UL)

/* Cache line size, expressed in bytes */
#define MCL_LMEM_CACHE_LINE_SIZE            ((uint32)16UL)

/*********************************** CACHE SECTION ***********************************/



/** Variant aware structure.c file. */

/** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */  
#define MCL_CONF_PB \
 extern CONST(Mcl_ConfigType, MCL_CONST) MclConfigSet_0;
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Bus;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Descriptor;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Priority;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Unrecognized;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Inconsistency;
} Mcl_DemConfigType;

extern CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config;

#endif


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif    /* CDD_MCL_CFG_H */
/**@}*/


