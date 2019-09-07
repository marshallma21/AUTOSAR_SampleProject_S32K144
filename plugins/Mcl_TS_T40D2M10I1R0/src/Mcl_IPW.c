/**
*     @file            Mcl_IPW.c
*     @version 1.0.1
* 
*     @brief   AUTOSAR Mcl - MCL Driver LLD source file.
*     @details MCL driver source file, containing the LLD variables and functions that are used by
*              the MCL driver.
*              
*     @addtogroup MCL_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform ARM
*     Peripheral eDMA
*     Dependencies none
* 
*     Autosar Version 4.2.2
*     Autosar Revision ASR_REL_4_2_REV_0002
*     Autosar ConfVariant
*     SWVersion 1.0.1
*     BuildVersion S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
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
* @section Mcl_IPW_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*          before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
*          is as  per Autosar  requirement MEMMAP003.
* 
* @section Mcl_IPW_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* 
* @section [global]
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Mcl_IPW_c_REF_5
*          Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*          This violation is generated becuase conversions must not be performed between a pointer 
*          to a function and any type other than an integral type. The cast can't be avoided as it is 
*          used to access memory mapped registers.
*
* @section Mcl_IPW_c_REF_6
*          Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
*          be implicitly converted to a different underlying type.
*
* @section Mcl_IPW_c_REF_7
*          Violates MISRA 2004 Required Rule 12.7, Bitwise operators shall not be applied to operands whose
*          underlying type is signed.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_IPW_c_REF_12
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
*
* @section Mcl_IPW_c_REF_13
*          Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
*          a pointer type and an integral type
*          This violation is due to the pointer arithmetic used to write/ read
*          the data to/from the registers.
*
* @section Mcl_IPW_c_REF_14
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initializer, 
*          a constant, a parenthesized expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of a function define.
*
* @section Mcl_IPW_c_REF_15
*          Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used
*          This violation due to implementation of mcal_trusted_call function.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

#include "CDD_Mcl_Cfg.h"
#include "Mcl_IPW.h"
#include "StdRegMacros.h"
#include "Mcl_Notif.h"
#include "SchM_Mcl.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCL_IPW_VENDOR_ID_C                     43
#define MCL_IPW_AR_RELEASE_MAJOR_VERSION_C      4
#define MCL_IPW_AR_RELEASE_MINOR_VERSION_C      2
#define MCL_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define MCL_IPW_SW_MAJOR_VERSION_C              1
#define MCL_IPW_SW_MINOR_VERSION_C              0
#define MCL_IPW_SW_PATCH_VERSION_C              1
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_IPW.c and Mcal.h are different"
    #endif
#endif
/* Check if source file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_IPW.c and StdRegMacros.h are different"
    #endif
#endif
/* Check if source file and Mcl_Cfg header file are of the same vendor */
#if (MCL_IPW_VENDOR_ID_C != MCL_VENDOR_ID_CFG)
#error "Mcl_IPW.c and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Mcl_Cfg header file are of the same Autosar version */
#if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_IPW_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_IPW_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_IPW.c are different"
    #endif
/* Check if source file and Mcl_Cfg header file are of the same Software version */
#if ((MCL_IPW_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_IPW_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_IPW_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_IPW.c are different"
#endif

#if (MCL_IPW_VENDOR_ID_C != MCL_IPW_VENDOR_ID)
    #error "Mcl_IPW.c and Mcl_IPW.h have different vendor IDs"
#endif
/* Check if source file and Mcl_IPW header file are of the same Autosar version */
#if ((MCL_IPW_AR_RELEASE_MAJOR_VERSION_C != MCL_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_AR_RELEASE_MINOR_VERSION_C != MCL_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_AR_RELEASE_REVISION_VERSION_C != MCL_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcl_IPW.c and Mcl_IPW.h are different"
#endif
/* Check if source file and Mcl_IPW header file are of the same Software version */
#if ((MCL_IPW_SW_MAJOR_VERSION_C != MCL_IPW_SW_MAJOR_VERSION) || \
     (MCL_IPW_SW_MINOR_VERSION_C != MCL_IPW_SW_MINOR_VERSION) || \
     (MCL_IPW_SW_PATCH_VERSION_C != MCL_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcl_IPW.c and Mcl_IPW.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                      LOCAL MACROS
==================================================================================================*/

#if (MCL_ENABLE_DMA == STD_ON)
     #if ((STD_ON == MCL_ENABLE_USER_MODE_SUPPORT) && (STD_ON == MCL_DMAMUX_USER_MODE_SUPPORT))
                /** @violates @ref Mcl_IPW_c_REF_12 Function-like macro defined.*/
                #define Call_Mcl_DmaMux_Init(u32ptr) \
                do \
                { \
                Mcal_Trusted_Call1param(Mcl_DmaMux_Init,(u32ptr)); \
                } \
                while(0)
            #if (MCL_DEINIT_API == STD_ON)
                /** @violates @ref Mcl_IPW_c_REF_12 Function-like macro defined.*/
                #define Call_Mcl_DmaMux_DeInit(u32ptr) \
                do \
                { \
                Mcal_Trusted_Call1param(Mcl_DmaMux_DeInit,(u32ptr)); \
                } \
                while(0)
            #endif
        #else
                /** @violates @ref Mcl_IPW_c_REF_12 Function-like macro defined.*/
                #define Call_Mcl_DmaMux_Init(u32ptr) \
                do \
                { \
                Mcl_DmaMux_Init((u32ptr)); \
                } \
                while(0)
            #if (MCL_DEINIT_API == STD_ON)
                /** @violates @ref Mcl_IPW_c_REF_12 Function-like macro defined.*/
                #define Call_Mcl_DmaMux_DeInit(u32ptr) \
                do \
                { \
                Mcl_DmaMux_DeInit((u32ptr)); \
                } \
                while (0)
            #endif
        #endif
#endif
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_IPW_c_REF_2 header file being included twice */
#include "Mcl_MemMap.h"


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCL_ENABLE_DMA == STD_ON)

/**
 * @brief      Mcl_IPW_Dma_Init
 * @details    Initialize the eDMA module
 *
 * @param[in]      Mcl_HwIPs_ConfigPtr - pointer to Mcl top configuration structure
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_Init( P2CONST( Mcl_DmaHwIpsConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_HwIPs_ConfigPtr)
{   
    VAR(uint8, AUTOMATIC) u8Instance = 0U;
    
    /* Initialize the eDMA controllers */
    for (u8Instance=0U; u8Instance<=(MCL_DMA_NB_CONTROLLERS-1U); u8Instance++)
    {
        /* Check if instance is used in the configuration */
        if (DMA_INSTANCE_USED == (*(Mcl_HwIPs_ConfigPtr->pDma_Config->pDmaConfigInstance))[u8Instance].pDmaUsed)
        {
            Mcl_Dma_Init(Mcl_HwIPs_ConfigPtr->pDma_Config, u8Instance);
        }
    }
    /* Initialize the DMA_MUX channels */
    Call_Mcl_DmaMux_Init(Mcl_HwIPs_ConfigPtr->pDmaMux_Config);
}
#if (MCL_DEINIT_API == STD_ON)
/**
 * @brief      Mcl_IPW_DeInit
 * @details    DeInitialize the IPs used for the DMA feature, DMA and DMAMUX
 *
 * @param[in]      
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DeInit( P2CONST( Mcl_DmaHwIpsConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_HwIPs_ConfigPtr)
{   
    VAR(uint8, AUTOMATIC) u8Instance = 0U;
    /* Initialize the DMA_MUX channels */
    Call_Mcl_DmaMux_DeInit(Mcl_HwIPs_ConfigPtr->pDmaMux_Config);
    /* DeInitialize the eDMA controllers */
    for (u8Instance=0U; u8Instance<=(MCL_DMA_NB_CONTROLLERS-1U); u8Instance++)
    {
        /* Check if instance is used in the configuration */
        if (DMA_INSTANCE_USED == (*(Mcl_HwIPs_ConfigPtr->pDma_Config->pDmaConfigInstance))[u8Instance].pDmaUsed)
        {
            Mcl_Dma_DeInit(Mcl_HwIPs_ConfigPtr->pDma_Config, u8Instance);
        }
    }

}
#endif
/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigChannel
 * @details    Mcl_IPW_DmaConfigChannel() performs a basic channel configuration.
 *
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure. 
 * @param[in]      dma_channel          - the number of the channel that will be configured.
 * @param[in]      config_descriptor    - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                        of a  Transfer Control Descriptor (TCD).
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                               VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                               P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor)
{
    /*  Basic channel configuration  */
    Mcl_Dma_ConfigChannel((*(Mcl_DmaConfigPtr->pChannelsConfig))[dma_channel].Dma_Channel, config_descriptor);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigTcd
 * @details    Mcl_IPW_DmaConfigTcd() performs a TCD configuration.
 *
 * @param[in]      pTcdAddress        - pointer to the address of the TCD.
 * @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                      of a  Transfer Control Descriptor (TCD).
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress,
                                           P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor)
{
    /*  Basic TCD configuration  */
    Mcl_Dma_ConfigTcd(pTcdAddress, config_descriptor);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigLinkedChannel
 * @details    Mcl_IPW_DmaConfigLinkedChannel() configures the linkage between two DMA channels.
 * 
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure. 
 * @param[in]      dma_channel          - the Mcl channel that will be configured.
 * @param[in]      config_descriptor    - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                        of a  Transfer Control Descriptor (TCD).
 * @param[in]      next_channel         - the Mcl channel that will be linked.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigLinkedChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                     VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                                     P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                     VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
    /*  Configures the linkange between two DMA channels  */
    Mcl_Dma_ConfigLinkedChannel((*(Mcl_DmaConfigPtr->pChannelsConfig))[dma_channel].Dma_Channel, 
                            config_descriptor,
    (*(Mcl_DmaConfigPtr->pChannelsConfig))[next_channel].Dma_Channel);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigScatterGatherChannel
 * @details    Mcl_IPW_DmaConfigScatterGatherChannel() configures a DMA channel for a scatter/gather operation.
 *
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure.
 * @param[in]      dma_channel          - the number of the channel that will be configured.
 * @param[in]      config_descriptor    - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                        of a  Transfer Control Descriptor (TCD).
 * @param[in]      pNext_tcd            - pointer to the address of the next TCD that will be loaded into the channel.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                            VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                                            P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                            P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd)
{
    /*  Configures a DMA channel for a scatter/gather operation  */
    Mcl_Dma_ConfigScatterGatherChannel((*(Mcl_DmaConfigPtr->pChannelsConfig))[dma_channel].Dma_Channel, config_descriptor, pNext_tcd);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigLinkedTcd
 * @details    Mcl_IPW_DmaConfigLinkedTcd() configures a TCD for a channel-linking operation.
 *
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure.
 * @param[in]      pTcdAddress          - pointer to the address of the TCD.
 * @param[in]      config_descriptor    - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                        of a  Transfer Control Descriptor (TCD).
 * @param[in]      next_channel         - the Mcl channel that will be linked.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigLinkedTcd( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                 P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                 P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                 VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
    /*  Configures a TCD for a channel-linking operation */
    Mcl_Dma_ConfigLinkedTcd(pTcdAddress, config_descriptor, (*(Mcl_DmaConfigPtr->pChannelsConfig))[next_channel].Dma_Channel);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigScatterGatherTcd
 * @details    Mcl_IPW_DmaConfigScatterGatherTcd() configure a TCD linkage through scattere-gather.
 *
 * @param[in]      pTcdAddress        - pointer to the address of the TCD.
 * @param[in]      config_descriptor  - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                      of a  Transfer Control Descriptor (TCD).
 * @param[in]      pNext_tcd          - pointer to the address of the next TCD that will be loaded into the channel.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherTcd( P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                        P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                        P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd)
{
    /*  Configures a TCD linkage through scatter-gather  */
    Mcl_Dma_ConfigScatterGatherTcd(pTcdAddress, config_descriptor, pNext_tcd);

}

/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigScatterGatherLinkedChannel
 * @details    Mcl_IPW_DmaConfigScatterGatherLinkedChannel() configures scatter-gather 
 *             and the linkage between two DMA channels.
 * 
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure. 
 * @param[in]      dma_channel          - the Mcl channel that will be configured.
 * @param[in]      config_descriptor    - a pointer to a structure that contains the necessary data for a basic configuration 
 *                                        of a  Transfer Control Descriptor (TCD).
 * @param[in]      next_channel         - the Mcl channel that will be linked.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherLinkedChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                                  VAR(Mcl_ChannelType, AUTOMATIC) dma_channel, 
                                                                  P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                                  P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                                  VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
    /*  Configures the scatter-gather and linkange between two DMA channels  */
    Mcl_Dma_ConfigScatterGatherLinkedChannel((*(Mcl_DmaConfigPtr->pChannelsConfig))[dma_channel].Dma_Channel, 
                                         config_descriptor,
                                         pNext_tcd,
    (*(Mcl_DmaConfigPtr->pChannelsConfig))[next_channel].Dma_Channel);
}

/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaConfigScatterGatherLinkedTcd
 * @details    Mcl_IPW_DmaConfigScatterGatherLinkedTcd() configures scatter-gather 
 *             and the linkage for a TCD.
 * 
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure. 
 * @param[in]      pTcdAddress          - Tcd address used for configuring SGA with linking.
 * @param[in]      config_descriptor    - a pointer to a structure that contains the necessary data for a basic configuration .
 *                                        of a  Transfer Control Descriptor (TCD).
 * @param[in]      pNext_tcd            - Pointer to the TCD address used for scatter gather
 * @param[in]      next_channel         - the Mcl channel that will be linked.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaConfigScatterGatherLinkedTcd( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                              P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pTcdAddress, 
                                                              P2CONST(Mcl_DmaTcdAttributesType, AUTOMATIC, MCL_APPL_CONST) config_descriptor, 
                                                              P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) pNext_tcd,
                                                              VAR(Mcl_ChannelType, AUTOMATIC) next_channel)
{
    /*  Configures the scatter-gather and linkange for a TCD  */
    Mcl_Dma_ConfigScatterGatherLinkedTcd(pTcdAddress,
                                     config_descriptor,
                                     pNext_tcd,
    (*(Mcl_DmaConfigPtr->pChannelsConfig))[next_channel].Dma_Channel);
}

/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaSetChannelPriority
 * @details    Mcl_IPW_DmaSetChannelPriority() sets the priority for the DMA channel passed as parameter.
 *
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure.
 * @param[in]      nChannel             - the channel number for which the priority is changed.
 * @param[in]      nPriority            -  the priority that is assigned to the specified channel.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetChannelPriority( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                    VAR(Mcl_ChannelType, AUTOMATIC) nChannel, 
                                                    VAR(Mcl_DmaPriorityType, AUTOMATIC) nPriority)
{
    /*  Set the priority for the DMA channel passed as parameter.  */
    /* Compiler_Warning: This is a cast from uint32 to pointer type (can be 32bit or 64 bit). There is no loss of information, no functional problem. */
    Mcl_Dma_SetChannelPriority((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel, nPriority);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaStartChannel
 * @details    Mcl_IPW_DmaStartChannel() starts a transfer on a DMA channel.
 *
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure.
 * @param[in]      nChannel             - the DMA channel to be started.
 *
 * @return void
 *
 * @pre
 *
 */
FUNC(void, MCL_CODE) Mcl_IPW_DmaStartChannel( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                              VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
    /*  Start a transfer on a DMA channel.  */
    Mcl_Dma_StartChannel((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel);
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaIsTransferCompleted
 * @details    Mcl_IPW_DmaIsTransferCompleted() indicates if a DMA channel transfer is completed.
 *
 * @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure.
 * @param[in]      nChannel             - the Mcl channel for checking the transfer status.
 *
 * @return boolean
 *
 * @pre
 *
 */
FUNC(boolean, MCL_CODE) Mcl_IPW_DmaIsTransferCompleted( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                        VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
   /* Returns TRUE if transfer is completed, FALSE otherwise */
    return (Mcl_Dma_IsTransferCompleted((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel));
}


/*================================================================================================*/
 /**
 * @brief      Mcl_IPW_DmaIsTransferActive
 * @details    Mcl_IPW_DmaIsTransferActive() indicates if eDMA transfer corresponding to the DMA channel 
 *                                            passed as parameter is in execution.
 *
 * @param[in]       Mcl_DmaConfigPtr     - Pointer to the Dma config structure
 * @param[in]       nChannel             - the Mcl channel for checking the transfer status.
 *
 * @return boolean
 *
 * @pre
 *
 */
FUNC(boolean, MCL_CODE) Mcl_IPW_DmaIsTransferActive( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                     VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
    /* Returns TRUE if transfer is in execution, FALSE otherwise */
    return (Mcl_Dma_IsTransferActive((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel));
}


#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/*===============================================================================================*/
/**
* @brief            Mcl_IPW_EnableNotification
* @details          This function will call EnableNotification function for the corresponding IP of MclChannel
*
* @param[in]      Mcl_DmaConfigPtr     - Pointer to the Dma config structure
* @param[in]      ChannelNumber        - Mcl channel id
* @param[in]      Notification         - notification type to be enabled
*
*/
FUNC (void, MCL_CODE) Mcl_IPW_EnableNotification
(
    P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST)       Mcl_DmaConfigPtr,
    VAR         (Mcl_ChannelType,        AUTOMATIC)            ChannelNumber,
    VAR         (Mcl_DmaTransferNotifType,  AUTOMATIC)         Notification
)
{
    /* Call Dma IP enable notification function */
    Mcl_Dma_EnableNotification((*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel, Notification);
}

/*===============================================================================================*/
/**
* @brief            Mcl_IPW_DisableNotification
* @details          This function will call DisableNotification function for the corresponding IP of MclChannel
*
* @param[in]      Mcl_DmaConfigPtr           - Pointer to the Dma config structure
* @param[in]      ChannelNumber              - Mcl channel id
*
*/
FUNC (void, MCL_CODE) Mcl_IPW_DisableNotification
(
    P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST)   Mcl_DmaConfigPtr,
    VAR  (Mcl_ChannelType,        AUTOMATIC)               ChannelNumber
)
{    
    /* Call Dma IP disable notification function */
    Mcl_Dma_DisableNotification((*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel);
}

/*===============================================================================================*/
/**
* @brief            Mcl_IPW_DmaAcknowledgeInterrupt
* @details          This function acknowledges the interrupt for the channel passed as parameter.
*
* @param[in]      Mcl_DmaConfigPtr           - Pointer to the Dma config structure
* @param[in]      ChannelNumber              - Mcl channel id
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaAcknowledgeInterrupt( P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                      VAR(Mcl_ChannelType,AUTOMATIC) ChannelNumber)
{    
    /* Call Dma acknowledge interrupt macro */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_CLEAR_INT_REQ((*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel);
}

#endif /* MCL_DMA_NOTIFICATION_SUPPORTED */


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetChannelTcdAddress.
* @details  This function is used for getting the translation between a Mcl channel and 
*           the adress for the corresponding tcd.
*
* @param[in]      Mcl_DmaConfigPtr           - Pointer to the Dma config structure
* @param[in]      ChannelNumber              - Mcl channel id
*
* @return   The adress of the TCD for the channel given as parameter.
*
* @api
*
*/
FUNC(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA), MCL_CODE) Mcl_IPW_DmaGetChannelTcdAddress
(
    P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST)             Mcl_DmaConfigPtr,
    VAR      (Mcl_ChannelType,        AUTOMATIC)                     ChannelNumber
)
{
    /* Return the TCD address for the hw channel corresponding to ChannelNumber */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    /** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    return ((Mcl_DmaTcdType*)DMA_TCD((uint32)(*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel));
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetSaddr.
* @details  This function is used for setting the SADDR for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Saddr - Address to set in SADDR.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(uint32, AUTOMATIC) Saddr)
{
    /* Call the DMA macro for setting the SADDR */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_SADDR((uint32)(TcdAddr), (uint32)(Saddr));
}  


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetSoff.
* @details  This function is used for setting the SOFF for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Soff - Source address offset.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSoff(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                        VAR(sint16, AUTOMATIC) Soff)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18();
    
    /* Call the DMA macro for setting the SOFF */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    /** @violates @ref Mcl_IPW_c_REF_7 MISRA 2004 Rule 12.7, Bitwise operators */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. Also the cast is needed to access only 2 bytes of the word without accessing the flags. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_SOFF((uint32)(TcdAddr), (sint16)Soff);
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18();
}                                        


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetSga.
* @details  This function is used for setting the DLASTSGA for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Sga - Scatter Gather Address.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSga(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                       VAR(uint32, AUTOMATIC) Sga)
{
    /* Call the DMA macro for setting the DLASTSGA */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    /** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Required Rule 10.1, Implicit conversion */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_DLAST_SGA((uint32)(TcdAddr), (sint32)(Sga));
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetDlast.
* @details  This function is used for setting the DLASTSGA for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Dlast - Adjustment value added to the destination address at the completion of the major iteration count.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDlast(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(sint32, AUTOMATIC) Dlast)
{
    /* Call the DMA macro for setting the DLASTSGA */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    /** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Required Rule 10.1, Implicit conversion */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_DLAST_SGA((uint32)(TcdAddr), (sint32)(Dlast));
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetDaddr.
* @details  This function is used for setting the DADDR for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Daddr - Destination Address.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(uint32, AUTOMATIC) Daddr)
{
    /* Call the DMA macro for setting the DADDR */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_DADDR((uint32)(TcdAddr), (uint32)(Daddr));
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetDoff.
* @details  This function is used for setting the DOFF for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Doff - Destination Address Offset.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDoff(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                        VAR(sint16, AUTOMATIC) Doff)
{   
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_21();
    
    /* Call the DMA macro for setting the DOFF */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    /** @violates @ref Mcl_IPW_c_REF_7 MISRA 2004 Rule 12.7, Bitwise operators */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/  
    DMA_TCD_UPDATE_DOFF((uint32)(TcdAddr), (sint16)(Doff));
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_21();    
}                                        

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetCiter.
* @details  This function is used for setting the CITER for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Citer - Value for major iteration count.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetCiter(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(uint16, AUTOMATIC) Citer)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_19();
    
    /* Call the DMA macro for setting the CITER */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. Also the cast is needed to access only 2 bytes of the word without accessing the flags. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    if((0U) != (uint16)DMA_TCD_GET_CITER_ELINK((uint32)(TcdAddr)))
    {
         /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
         /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
        DMA_TCD_SET_CITER_ELINK_ON((uint32)(TcdAddr), (uint32)(Citer));
    }
    else
    {   
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
        DMA_TCD_SET_CITER_ELINK_OFF((uint32)(TcdAddr), (uint32)(Citer));
    }
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_19();
}        


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetBiter.
* @details  This function is used for setting the BITER for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Biter - Value for major iteration count.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetBiter(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(uint16, AUTOMATIC) Biter)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_25();
    
    /* Call the DMA macro for setting the BITER */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: The cast is needed to access only 2 bytes of the word without accessing the flags. */
    if((0U) != (uint16)DMA_TCD_GET_BITER_ELINK((uint32)(TcdAddr)))
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
        DMA_TCD_SET_BITER_ELINK_ON((uint32)(TcdAddr), (uint32)(Biter));       
    }
    else
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        /* Compiler_Warning: The cast is needed to access only 2 bytes of the word without accessing the flags. */
        DMA_TCD_SET_BITER_ELINK_OFF((uint32)(TcdAddr), (uint32)(Biter));
    }
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_25();
} 

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetLinkAndIterCount.
* @details  This function is used for enabling channel-to-channel linking (ELINK field set),
*           setting  the linked channel number (LINKCH field) and the major iteration count 
*           (CITER & BITER fields) for a TCD based on the address of the TCD.
*
* @param[in]    pTcdAddress - Address for the TCD.
* @param[in]    LinkCh - Linked DMA channel number.
* @param[in]    Iter - Is the value for major iteration count.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetLinkAndIterCount(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                    P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                                    VAR(Mcl_ChannelType, AUTOMATIC) LinkCh,
                                                    VAR(uint16, AUTOMATIC) Iter)
{

    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_20();
    
    /* Call the DMA macro for setting the ELINK, LINKCH, CITER */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */ 
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_CITER((uint32)(TcdAddr),(DMA_TCD_ITER_ELINK_U32 | \
                                           ((((uint32)(*(Mcl_DmaConfigPtr->pChannelsConfig))[LinkCh].Dma_Channel) & DMA_TCD_MAX_LINKCH_MASK_U32) << 25) | \
                                            (((uint32)Iter & DMA_TCD_MAX_ITER_MASK_U32) << 16)));
    
     /* Call the DMA macro for setting the ELINK, LINKCH, BITER */    
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. Also the cast is needed to access only 2 bytes of the word without accessing the flags. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_BITER((uint32)(TcdAddr), (uint16)(DMA_TCD_ITER_ELINK_U16 | \
                                                    ((((*(Mcl_DmaConfigPtr->pChannelsConfig))[LinkCh].Dma_Channel) & DMA_TCD_MAX_LINKCH_MASK_U32) << 9)| \
                                                    ((uint32)Iter & DMA_TCD_MAX_ITER_MASK_U32)));

    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_20();
}  

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetSModSize.
* @details  This function is used for setting the SMOD and SSIZE for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    SModSize - Source Address Modulo.
* @param[in]    SSize - Source data transfer size.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSModSize(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                            VAR(uint8, AUTOMATIC) SModSize,
                                            VAR(Mcl_DmaSizeType, AUTOMATIC) SSize)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16();
    
    /* Call the DMA macro for setting the SMOD and SSIZE */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    /** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_SMOD((uint32)TcdAddr, (uint32)(SModSize));
    /** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_SSIZE((uint32)TcdAddr, (uint32)(SSize));
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16();
} 


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetDModSize.
* @details  This function is used for setting the DMOD and DSIZE for a TCD based
*           on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    DModSize - Destination Address Modulo.
* @param[in]    DSize - Destination data transfer size.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetDModSize(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                            VAR(uint8, AUTOMATIC) DModSize,
                                            VAR(Mcl_DmaSizeType, AUTOMATIC) DSize)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17();
    
    /* Call the DMA macro for setting the DMOD and DSIZE */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_DMOD((uint32)TcdAddr, (uint32)(DModSize));
    /** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
    DMA_TCD_UPDATE_DSIZE((uint32)TcdAddr, (uint32)(DSize));
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17();
} 
   

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetMlnoNBytes.
* @details  This function is used for setting the Minor Byte Transfer Count when minor loop is disabled,
*           for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    MlnoNBytes - Minor Byte Transfer Count.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetMlnoNBytes(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                              VAR(uint32, AUTOMATIC) MlnoNBytes)
{
    /* Call the DMA macro for setting the NBytes for Mlno */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_NBYTES((uint32)(TcdAddr), MlnoNBytes);
} 


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetMloffdis.
* @details  This function is called when offset is enabled for setting the Source minor loop offset enable, 
*           Destination minor loop offset enable, Offset applied to the source or destination address
*           and Minor Byte Transfer Count for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Smloe - Source minor loop offset enable.
* @param[in]    Dmloe - Destination minor loop offset enable.
* @param[in]    Mloff - Offset applied to the source or destination address.
* @param[in]    NBytes - Minor Byte Transfer Count.
*
* @return
*
* @api
*
*/
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetMloffen(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                           VAR(boolean, AUTOMATIC) Smloe,
                                           VAR(boolean, AUTOMATIC) Dmloe,
                                           VAR(sint32, AUTOMATIC) Mloff,
                                           VAR(uint32, AUTOMATIC) NBytes)
{
    /* Call the DMA macro for setting the fields when offset is enabled and minor loop is enabled */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Required Rule 10.1, Implicit conversion */
    /** @violates @ref Mcl_IPW_c_REF_7 MISRA 2004 Required Rule 12.7, Bitwise operators */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_MLOFFYES((uint32)(TcdAddr), (uint32)(((uint32)(Smloe) << 31) | ((uint32)(Dmloe) << 30) | (((Mloff) & DMA_TCD_MAX_MLOFF_MASK_U32) << 10) | ((NBytes) & DMA_TCD_MAX_MLOFF_NBYTES_MASK_U16)));
}                                            
   

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetSlast.
* @details  This function is used for setting the SLAST for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Slast - Last Source Address Adjustment.
*
* @return
*
* @api
*
*/   
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetSlast(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(sint32, AUTOMATIC) Slast)
{
    /* Call the DMA macro for setting the SLAST  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_UPDATE_SLAST((uint32)(TcdAddr), (uint32)(Slast));
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetFlags.
* @details  This function is used for setting the Channel Done, Channel Active, 
*           Enable channel-to-channel linking on major loop complete,
*           Enable Scatter/Gather Processing, Disable Request, 
*           Enable an interrupt when major counter is half complete,
*           Enable an interrupt when major iteration count completes,
*           Channel Start flags for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
* @param[in]    Flags - Flags to be set.
*
* @return
*
* @api
*
*/   
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetFlags(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr,
                                         VAR(uint8, AUTOMATIC) Flags)
{

    
    #ifdef MCAL_CACHE_RUNTIME_MNGMNT
    #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)
    #if (STD_ON == MCL_SYNCRONIZE_CACHE) 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
        
    if (DMA_TCD_START_U32  == ((uint32)Flags & DMA_TCD_START_U32))
    {
        /* Flush DCACHE to synchronize data */
        retVal = Mcl_IPW_CacheFlush(MCL_LMEM_CACHE_ALL);
        if ((Std_ReturnType)E_NOT_OK == retVal)
        {   
            #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
                /* TcdAddr may reside in RAM, affected instance is unknown */
                /* call error notifications of both instances */
                Mcl_ErrorNotification((Mcl_DmaInstanceType)DMA_INSTANCE0, MCL_DMA_MEM_SYNC_ERROR);
                #if (MCL_DMA_NB_CONTROLLERS == 0x02U)
                Mcl_ErrorNotification((Mcl_DmaInstanceType)DMA_INSTANCE1, MCL_DMA_MEM_SYNC_ERROR);
                #endif
            #endif
        }
        else
        {
            /* cache memory sync successful */
        }
    }
    #endif
    #endif
    #endif
    
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_24();
    
    /* Call the DMA macro for setting the flags  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_SET_FLAGS((uint32)(TcdAddr), (uint32)(Flags));
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_24();
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetFlags.
* @details  This function is used for getting the Channel Done, Channel Active, 
*           Enable channel-to-channel linking on major loop complete,
*           Enable Scatter/Gather Processing, Disable Request, 
*           Enable an interrupt when major counter is half complete,
*           Enable an interrupt when major iteration count completes,
*           Channel Start flags for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
*
* @return   Value for all the flags.
*
* @api
*/   
FUNC(uint8, MCL_CODE) Mcl_IPW_DmaGetFlags(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr)
{
    /* Call the DMA macro for getting the flags  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    return (uint8)DMA_TCD_GET_FLAGS((uint32)(TcdAddr));
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaClearIntMaj.
* @details  This function disables the interrupts when major iteration count completes
*           for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
*
* @return
*
* @api
*
*/   
FUNC(void, MCL_CODE) Mcl_IPW_DmaClearIntMaj(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_23();
    
    /* Call the DMA macro for clearing the enable interrupt on major iteration count complete  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_CLR_INT_MAJ((uint32)(TcdAddr));
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_23();
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaSetIntMaj.
* @details  This function enables the interrupts when major iteration count completes
*           for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
*
* @return
*
* @api
*
*/   
FUNC(void, MCL_CODE) Mcl_IPW_DmaSetIntMaj(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr)
{
    /* Enter exclusive area to protect TCD words 2,6,8 */
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_22();
    
    /* Call the DMA macro for enabling interrupt on major iteration count complete  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    DMA_TCD_SET_INT_MAJ((uint32)(TcdAddr));
    
    /* Exit exclusive area to protect TCD words 2,6,8 */
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_22();
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaTcdGetIntMaj.
* @details  This function returns TRUE if the interrupts were enabled and FALSE if interrupts were 
*           disabled for the corresponding channel.
*
* @param[in]      Mcl_DmaConfigPtr           - Pointer to the Dma config structure
* @param[in]      ChannelNumber              - Mcl channel id
*
* @return  boolean
*
* @api
*
*/   
FUNC(boolean, MCL_CODE) Mcl_IPW_DmaTcdGetIntMaj(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
    /* Call the DMA macro for getting interrupt state  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    return (DMA_TCD_GET_INT_MAJ((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel));  
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaClearDone.
* @details  This function is used for clearing done bit for the channel passed as parameter.
*
* @param[in]      Mcl_DmaConfigPtr           - Pointer to the Dma config structure
* @param[in]      nChannel                   - Mcl channel number
*
* @return 
*
* @api
*
*/   
FUNC(void, MCL_CODE) Mcl_IPW_DmaClearDone(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                          VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{

    /* Call the DMA macro for clearing DONE bit for nChannel  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_CLR_DONE((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel);
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetCiter.
* @details  This function is used for getting the CITER field
*           for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
*
* @return   Value for CITER.
*
* @api
*/   
FUNC(uint16, MCL_CODE) Mcl_IPW_DmaGetCiter(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr)
{
    VAR(uint16, AUTOMATIC) returnValue = 0U;
    /* Call the DMA macro for getting the flags  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    if((0U)!=(uint16)DMA_TCD_GET_CITER_ELINK((uint32)(TcdAddr)))
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. Also the cast is needed to access only 2 bytes of the word without accessing the flags. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
        returnValue = (uint16)DMA_TCD_GET_CITER_ON((uint32)(TcdAddr)); 
    }
    else
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. Also the cast is needed to access only 2 bytes of the word without accessing the flags. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
        returnValue = (uint16)DMA_TCD_GET_CITER_OFF((uint32)(TcdAddr));
    }
    
    return returnValue;
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetSaddr.
* @details  This function is used for getting the SADDR field
*           for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
*
* @return   Value for SADDR.
*
* @api
*/   
FUNC(uint32, MCL_CODE) Mcl_IPW_DmaGetSaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr)
{
    /* Call the DMA macro for getting the SADDR field  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    return (DMA_GET_SADDR((uint32)(TcdAddr))); 
}
     

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetDaddr.
* @details  This function is used for getting the DADDR field
*           for a TCD based on the address of the TCD.
*
* @param[in]    TcdAddr - Address for the TCD.
*
* @return   Value for DADDR.
*
* @api
*/   
FUNC(uint32, MCL_CODE) Mcl_IPW_DmaGetDaddr(P2VAR(Mcl_DmaTcdType, AUTOMATIC, MCL_APPL_DATA) TcdAddr)
{
    /* Call the DMA macro for getting the DADDR field  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
    return (DMA_GET_DADDR((uint32)(TcdAddr)));  
}


/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetInterruptRequest.
* @details  This function is used for getting the interrupt request for the 
*           specified channel. If it is set, the return value is TRUE, otherwise 
*           the return value is FALSE.
*
* @param[in]  nChannel                   - Mcl channel number
*
* @return   boolean
*
* @api
*
*/   
FUNC(boolean, MCL_CODE) Mcl_IPW_DmaGetInterruptRequest(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                       VAR(Mcl_ChannelType, AUTOMATIC) nChannel)
{
    /* Call the DMA function for getting the interrupt request for the specified channel  */
    return Mcl_Dma_GetMultiRegChInfo((*(Mcl_DmaConfigPtr->pChannelsConfig))[nChannel].Dma_Channel, MCL_DMA_GET_INT);    
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaEnableHwRequest.
* @details  This function is used for enabling the hardware request for a given
*           Mcl channel.
*
* @param[in]  ChannelNumber - Mcl Channel for getting the physical DMA channel.
*
* @return
*
* @api
*
*/  
FUNC(void, MCL_CODE) Mcl_IPW_DmaEnableHwRequest(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber)
{

    #ifdef MCAL_CACHE_RUNTIME_MNGMNT
    #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)
    #if (STD_ON == MCL_SYNCRONIZE_CACHE) 
        VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_NOT_OK;
    
        /* Invalidate DCACHE to synchronize data */
        retVal = Mcl_IPW_CacheClear(MCL_LMEM_CACHE_ALL);
        if ((Std_ReturnType)E_NOT_OK == retVal)
        {  
            /* memory synchronization failed, notify user */
            #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
            /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            Mcl_ErrorNotification(DMA_MOD_IDX_U8((uint32)(*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel) , MCL_DMA_MEM_SYNC_ERROR);
            #endif
        }
        else
        {
            /* cache memory sync successful */
        }
    #endif
    #endif
    #endif
    
    /* Call the DMA macro for enabling the hardware request for ChannelNumber  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_ENABLE_REQUEST((uint32)(*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel);  
}
/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaDisableHwRequest.
* @details  This function is used for disabling the hardware request for a given
*           Mcl channel.
*
* @param[in]  ChannelNumber - Mcl Channel for getting the physical DMA channel.
*
* @return
*
* @api
*
*/  
FUNC(void, MCL_CODE) Mcl_IPW_DmaDisableHwRequest(P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
                                                VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber)
{

    /* Call the DMA macro for disabling the hardware request for ChannelNumber  */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    DMA_DISABLE_REQUEST((uint32)(*(Mcl_DmaConfigPtr->pChannelsConfig))[ChannelNumber].Dma_Channel);  
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaUpdateDestAddress.
* @details  This function is used for updating the destination address for a given
*           Mcl channel.
*
* @param[in]  channel - Dma Channel for setting up the daddr.
*             daddr   - New address to update
*
* @return
*
* @api
*
*/  
FUNC(void, MCL_CODE)Mcl_IPW_DmaUpdateDestAddress(VAR(uint32, AUTOMATIC)channel, VAR(uint32, AUTOMATIC) daddr)
{

    /* Call the DMA macro for updating the destination address for channel  */
    /** @violates @ref Mcl_IPW_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic. */
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    /** @violates @ref Mcl_IPW_c_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    DMA_UPDATE_DADDR(channel,daddr);  
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetChannelErrorStatus.
* @details  This function iProvide the error information about the logical channel logicalChannel 
*           specified as parameter from the DMA_ES and DMA_ERR register
*
* @param[in]  logicalChannel - Mcl Channel for getting the physical DMA channel.
*             Mcl_DmaConfigPtr - Mcl Configuration Stucture.
* @return   Mcl_DmaChannelErrorStatusType
*
* @api
*
*/       
#if (MCL_DMA_GET_GLOBAL_ERR_STATUS_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_IPW_DmaGetGlobalErrorStatus
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) dmaInstance,
    P2VAR(Mcl_DmaGlobalErrorStatusType, AUTOMATIC, MCL_APPL_DATA) dmaGlobalErrorStatus
)
{
    Mcl_Dma_GetGlobalErrorStatus((dmaInstance), (dmaGlobalErrorStatus));
}
#endif
#if (MCL_DMA_GET_CH_ERR_STATUS_API == STD_ON)
/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetChannelErrorStatus.
* @details  This function iProvide the error information about the logical channel logicalChannel 
*           specified as parameter from the DMA_ES and DMA_ERR register
*
* @param[in]  logicalChannel - Mcl Channel for getting the physical DMA channel.
*             Mcl_DmaConfigPtr - Mcl Configuration Stucture.
* @return   Mcl_DmaChannelErrorStatusType
*
* @api
*
*/                                                        
FUNC(Mcl_DmaChannelErrorStatusType, MCL_CODE) Mcl_IPW_DmaGetChannelErrorStatus
(
    P2CONST(Mcl_DmaConfigType, AUTOMATIC, MCL_APPL_CONST) Mcl_DmaConfigPtr,
    VAR(Mcl_ChannelType, AUTOMATIC) logicalChannel
)
{
    return Mcl_Dma_GetChannelErrorStatus((*(Mcl_DmaConfigPtr->pChannelsConfig))[logicalChannel].Dma_Channel);
}
#endif

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetChBiter.
* @details  This function is used for getting the BITER field
*           
*
* @param[in]    ChannelNumber - Mcl Channel.
*
* @return   Value for BITER.
*
* @api
*/   
FUNC(uint16, MCL_CODE) Mcl_IPW_DmaGetChBiter (VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber)
{
    VAR(uint16, AUTOMATIC) returnValue = 0U;
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    if((0U) != (uint16)DMA_TCD_GET_BITER_ELINK((uint32)(DMA_TCD(ChannelNumber))))
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        returnValue = (uint16)(DMA_GET_CH_BITER(ChannelNumber) & DMA_TCD_BITER_ELINK_YES_MASK_U16);    
    }
    else
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        returnValue = (uint16)(DMA_GET_CH_BITER(ChannelNumber) & DMA_TCD_BITER_ELINK_NO_MASK_U16);
    }
    return returnValue;
}

/*================================================================================================*/
/**
* @brief    Mcl_IPW_DmaGetChCiter.
* @details  This function is used for getting the CITER field
*           
*
* @param[in]    ChannelNumber - Mcl Channel.
*
* @return   Value for CITER.
*
* @api
*/   
FUNC(uint16, MCL_CODE) Mcl_IPW_DmaGetChCiter (VAR(Mcl_ChannelType, AUTOMATIC) ChannelNumber)
{
    VAR(uint16, AUTOMATIC) returnValue = 0U;
    /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    if((0U) != (uint16)DMA_TCD_GET_CITER_ELINK((uint32)(DMA_TCD(ChannelNumber))))
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        returnValue = (uint16)(DMA_GET_CH_CITER(ChannelNumber) & DMA_TCD_BITER_ELINK_YES_MASK_U16);    
    }
    else
    {
        /** @violates @ref Mcl_IPW_c_REF_5 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */ 
/** @violates @ref Mcl_IPW_c_REF_13 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        returnValue = (uint16)(DMA_GET_CH_CITER(ChannelNumber) & DMA_TCD_BITER_ELINK_NO_MASK_U16);
    }
    return returnValue;
}


#endif /* (MCL_ENABLE_DMA == STD_ON) */
/*================================================================================================*/

#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_IPW_c_REF_1 only preprocessor statements and comments before "#include". */
/** @violates @ref Mcl_IPW_c_REF_2 header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */


