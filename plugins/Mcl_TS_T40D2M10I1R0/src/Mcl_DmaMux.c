/**
*   @file    Mcl_DmaMux.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - DmaMux low level driver.
*   @details contains the low level driver for the DmaMux module.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_DMAMUX_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section Mcl_DMAMUX_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_DMAMUX_c_REF_6
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_DMAMUX_c_REF_9
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions at file scope
* shall have internal linkage unless external linkage is required.
*
* @section Mcl_DMAMUX_c_REF_10
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to 
* a function and any type other than an integral type.
*
* @section Mcl_DMAMUX_c_REF_11
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
* @section Mcl_DMAMUX_c_REF_12
* Violates MISRA 2004 Required Rule 14.2, All non-full statements  shall either:
* have a least one side-effect however excuted or cause control flow to change.
* This violation is due to implementation of MCAL-TRUSTED CALL Macro cause mis-understand
* about statements.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED (MCL_DMAMUX_REG_PROT_AVAILABLE)
#endif
#include "RegLockMacros.h"
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)
#include "Mcl_DmaMux.h"
#endif /* (MCL_ENABLE_DMA == STD_ON) */
#endif /* #ifdef MCL_ENABLE_DMA */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_DmaMux.c
*/
#define MCL_DMAMUX_VENDOR_ID_C                    43
#define MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION_C     4
#define MCL_DMAMUX_AR_RELEASE_MINOR_VERSION_C     2
#define MCL_DMAMUX_AR_RELEASE_REVISION_VERSION_C  2
#define MCL_DMAMUX_SW_MAJOR_VERSION_C             1
#define MCL_DMAMUX_SW_MINOR_VERSION_C             0
#define MCL_DMAMUX_SW_PATCH_VERSION_C             1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

#if (MCL_DMAMUX_VENDOR_ID_C != MCL_DMAMUX_VENDOR_ID)
    #error "Mcl_DmaMux.c and Mcl_DmaMux.h have different vendor IDs"
#endif
/* Check if source file and Mcl_Dma header file are of the same Autosar version */
#if ((MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION_C != MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMAMUX_AR_RELEASE_MINOR_VERSION_C != MCL_DMAMUX_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMAMUX_AR_RELEASE_REVISION_VERSION_C != MCL_DMAMUX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_DmaMux.h and Mcl_DmaMux.c are different"
#endif
/* Check if source file and Mcl_Dma header file are of the same Software version */
#if ((MCL_DMAMUX_SW_MAJOR_VERSION_C != MCL_DMAMUX_SW_MAJOR_VERSION) || \
     (MCL_DMAMUX_SW_MINOR_VERSION_C != MCL_DMAMUX_SW_MINOR_VERSION) || \
     (MCL_DMAMUX_SW_PATCH_VERSION_C != MCL_DMAMUX_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Dma.h and Mcl_Dma.c are different"
#endif

#endif /* (MCL_ENABLE_DMA == STD_ON) */
#endif /* #ifdef MCL_ENABLE_DMA */
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

#define MCL_START_SEC_CONST_32
/**
* @violates @ref Mcl_DMAMUX_c_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice 
* @violates @ref Mcl_DMAMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
*and comments before "#include"
*/
#include "Mcl_MemMap.h"

/**
* @brief base address array for DmaMux
*/
/**
* @violates @ref Mcl_DMAMUX_c_REF_9 All declarations and definitions shall have internal linkage unless external  
* is required
*/
CONST(uint32, MCL_CONST) DMAMUX_BASE_ADDR32[MCL_DMAMUX_NB_MODULES] = {
#ifdef DMAMUX0_BASEADDR
    DMAMUX0_BASEADDR
#endif
#ifdef DMAMUX1_BASEADDR
    ,DMAMUX1_BASEADDR
#endif
#ifdef DMAMUX2_BASEADDR
    ,DMAMUX2_BASEADDR
#endif
#ifdef DMAMUX3_BASEADDR
    ,DMAMUX3_BASEADDR
#endif
#ifdef DMAMUX4_BASEADDR
    ,DMAMUX4_BASEADDR
#endif
#ifdef DMAMUX5_BASEADDR
    ,DMAMUX5_BASEADDR
#endif
#ifdef DMAMUX6_BASEADDR
    ,DMAMUX6_BASEADDR
#endif
#ifdef DMAMUX7_BASEADDR
    ,DMAMUX7_BASEADDR
#endif
#ifdef DMAMUX8_BASEADDR
    ,DMAMUX8_BASEADDR
#endif
#ifdef DMAMUX9_BASEADDR
    ,DMAMUX9_BASEADDR
#endif
};

#define MCL_STOP_SEC_CONST_32
/**
* @violates @ref Mcl_DMAMUX_c_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice 
* @violates @ref Mcl_DMAMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
*and comments before "#include"
*/
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                       LOCAL MACROS
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


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_DMAMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_DMAMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
and comments before "#include"
*/
#include "Mcl_MemMap.h"


#define MCL_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_DMAMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_DMAMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
and comments before "#include"
*/
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_DMAMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*       of a header file being included twice 
*
* @violates @ref Mcl_DMAMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"
#if (MCL_ENABLE_USER_MODE_SUPPORT == STD_ON)
    #if (MCL_DMAMUX_REG_PROT_AVAILABLE == STD_ON)
    /** @violates @ref Mcl_DMAMUX_c_REF_9 MISRA 2004 Required Rule 8.10*/
        FUNC (void, MCL_CODE) Mcl_Dma_Mux_Set_User_Access (void)
        {
        /** @violates @ref Mcl_DMAMUX_c_REF_8 MISRA 2004 Advisory Rule 8.1 */
        #ifdef DMAMUX0_BASEADDR
        /*
        *@violates @ref Mcl_DMAMUX_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type.
        *@violates @ref Mcl_DMAMUX_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type.
        */
            SET_USER_ACCESS_ALLOWED(DMAMUX0_BASEADDR,DMAMUX_REG_PROT_SIZE);
        #endif
        #ifdef DMAMUX1_BASEADDR
        /*
        *@violates @ref Mcl_DMAMUX_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type.
        *@violates @ref Mcl_DMAMUX_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type.
        */
            SET_USER_ACCESS_ALLOWED(DMAMUX1_BASEADDR,DMAMUX_REG_PROT_SIZE);
        #endif
        }
    #endif        
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        This function initializes the DMAMUX module. 
* @details      Set the configuration register for channel enable, trig and source.
*
* @param[in]    pDmaMuxConfig - pointer to DmaMux configuration structure
*/
FUNC(void, MCL_CODE) Mcl_DmaMux_Init( P2CONST(Mcl_DmaMuxConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaMuxConfig)
{
    /* @brief Counter value used in loops */
    VAR(uint8, AUTOMATIC) u8Counter;
    /* @brief Pointer to DMA channel specific configuration */
    P2CONST(Mcl_DmaMuxChannelConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaMuxChannelConfig;
    /*@brief init Reg_prot register to let dmamux register can be accessed from user mode */
    #if (MCL_ENABLE_USER_MODE_SUPPORT == STD_ON)
        #if (MCL_DMAMUX_REG_PROT_AVAILABLE == STD_ON)
        /** @violates @ref Mcl_DMAMUX_c_REF_12 MISRA 2004 Required Rule 14.2*/
        Mcal_Trusted_Call(Mcl_Dma_Mux_Set_User_Access);
        #endif
    #endif
    /* Configuring channels Enable, Trigger and Source */
    for (u8Counter = 0x0U; u8Counter < pDmaMuxConfig->NumChannels; u8Counter++)
    {
        pDmaMuxChannelConfig = &((*(pDmaMuxConfig->pDmaMuxChannelsConfig))[u8Counter]);
        
        /**
        * @violates @ref Mcl_DMAMUX_c_REF_10 Conversions shall not be performed between a pointer to 
        * a function and any type other than an integral type.
        */
        /** @violates @ref Mcl_DMAMUX_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        REG_WRITE8(DMACHMUX_CHCONFIG((uint32)pDmaMuxChannelConfig->DmaMux_Channel, pDmaMuxChannelConfig->DmaMux_Instance), pDmaMuxChannelConfig->DmaMux_ChannelConfig);
        
    }

}

#if (MCL_DEINIT_API == STD_ON)
/**
* @brief        This function deinitializes the DMAMUX module. 
* @details      Set the configuration register for channel enable, trig and source.
*
* @param[in]    pDmaMuxConfig - pointer to DmaMux configuration structure
*/
FUNC(void, MCL_CODE) Mcl_DmaMux_DeInit( P2CONST(Mcl_DmaMuxConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaMuxConfig)
{
    /* Counter value used in loops */
    VAR(uint8, AUTOMATIC) u8Counter;
    /* Pointer to DMA channel specific configuration */
    P2CONST(Mcl_DmaMuxChannelConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaMuxChannelConfig;
    /*@brief init Reg_prot register to let dmamux register can be accessed from user mode */
    #if (MCL_ENABLE_USER_MODE_SUPPORT == STD_ON)
        #if (MCL_DMAMUX_REG_PROT_AVAILABLE == STD_ON)
        /** @violates @ref Mcl_DMAMUX_c_REF_12 MISRA 2004 Required Rule 14.2*/
        Mcal_Trusted_Call(Mcl_Dma_Mux_Set_User_Access);
        #endif
    #endif
    /* Configuring channels Enable, Trigger and Source */
    for (u8Counter = 0x0U; u8Counter < pDmaMuxConfig->NumChannels; u8Counter++)
    {
        pDmaMuxChannelConfig = &((*(pDmaMuxConfig->pDmaMuxChannelsConfig))[u8Counter]);
        
        /**
        * @violates @ref Mcl_DMAMUX_c_REF_10 Conversions shall not be performed between a pointer to 
        * a function and any type other than an integral type.
        */
        /** @violates @ref Mcl_DMAMUX_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        REG_WRITE8(DMACHMUX_CHCONFIG((uint32)pDmaMuxChannelConfig->DmaMux_Channel, pDmaMuxChannelConfig->DmaMux_Instance), DMAMUX_CHCFG_DEFAULT_VAL_U8);
    }

}
#endif
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_DMAMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*       of a header file being included twice 
*
* @violates @ref Mcl_DMAMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"

#endif /* (MCL_ENABLE_DMA == STD_ON) */
#endif /* #ifdef MCL_ENABLE_DMA */

#ifdef __cplusplus
}
#endif
/** @} */
