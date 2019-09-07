/**
*   @file    Mcl_DmaMux.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - DmaMux Low level driver header file.
*   @details DmaMux module low level driver.
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

#ifndef MCL_DMAMUX_H
#define MCL_DMAMUX_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_DMAMUX_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions

* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.

* @section Mcl_DMAMUX_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcl_DmaMux_Types.h"
#include "Reg_eSys_DmaMux.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_DmaMux.h
*/
#define MCL_DMAMUX_VENDOR_ID                      43
#define MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION       4
#define MCL_DMAMUX_AR_RELEASE_MINOR_VERSION       2
#define MCL_DMAMUX_AR_RELEASE_REVISION_VERSION    2
#define MCL_DMAMUX_SW_MAJOR_VERSION               1
#define MCL_DMAMUX_SW_MINOR_VERSION               0
#define MCL_DMAMUX_SW_PATCH_VERSION               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (MCL_DMAMUX_VENDOR_ID != DMAMUX_REG_VENDOR_ID)
    #error "Mcl_DmaMux.h and Reg_eSys_DmaMux.h have different vendor IDs"
#endif
/* Check if Mcl_Dma header file and Reg_eSys are of the same Autosar version */
#if ((MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION != DMAMUX_REG_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMAMUX_AR_RELEASE_MINOR_VERSION != DMAMUX_REG_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMAMUX_AR_RELEASE_REVISION_VERSION != DMAMUX_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_DmaMux.h and Reg_eSys_DmaMux.h are different"
#endif
/* Check if Mcl_Dma header file and Reg_eSys are of the same Software version */
#if ((MCL_DMAMUX_SW_MAJOR_VERSION != DMAMUX_REG_SW_MAJOR_VERSION) || \
     (MCL_DMAMUX_SW_MINOR_VERSION != DMAMUX_REG_SW_MINOR_VERSION) || \
     (MCL_DMAMUX_SW_PATCH_VERSION != DMAMUX_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_DmaMux.h and Reg_eSys_DmaMux.h are different"
#endif

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMAMUX_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcl_DmaMux.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Mcl_DmaMux_Types.h header file are of the same vendor */
#if (MCL_DMAMUX_VENDOR_ID != MCL_DMAMUX_TYPES_VENDOR_ID)
    #error "Mcl_DmaMux.h and Mcl_DmaMux_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same Autosar version */
#if ((MCL_DMAMUX_AR_RELEASE_MAJOR_VERSION    != MCL_DMAMUX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMAMUX_AR_RELEASE_MINOR_VERSION    != MCL_DMAMUX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMAMUX_AR_RELEASE_REVISION_VERSION != MCL_DMAMUX_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_DmaMux.h and Mcl_DmaMux_Types.h are different"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same software version */
#if ((MCL_DMAMUX_SW_MAJOR_VERSION != MCL_DMAMUX_TYPES_SW_MAJOR_VERSION) || \
     (MCL_DMAMUX_SW_MINOR_VERSION != MCL_DMAMUX_TYPES_SW_MINOR_VERSION) || \
     (MCL_DMAMUX_SW_PATCH_VERSION != MCL_DMAMUX_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_DmaMux.h and Mcl_DmaMux_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)
    /**
    * @brief  macros used to update the fields of a CHCONFIG register.
    */  
    /** @brief   before changing the trigger or source settings a DMA channel must be disabled via the CHCONFIG[#n].ENBL bit. */ 
    /** @violates @ref Mcl_DMAMUX_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define DMAMUX_CHANNEL_ENABLE(channel) \
        (REG_BIT_SET8(DMACHMUX_CHCONFIG((channel)), DMACHMUX_CHCONFIG_ENBL_U8))
    /** @violates @ref Mcl_DMAMUX_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define DMAMUX_CHANNEL_DISABLE(channel) \
        (REG_BIT_CLEAR8(DMACHMUX_CHCONFIG((channel)), DMACHMUX_CHCONFIG_ENBL_U8))
    /** @violates @ref Mcl_DMAMUX_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define DMAMUX_TRIGGER_ENABLE(channel) \
        (REG_BIT_SET8(DMACHMUX_CHCONFIG((channel)), DMACHMUX_CHCONFIG_TRIG_U8))
    /** @violates @ref Mcl_DMAMUX_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define DMAMUX_TRIGGER_DISABLE(channel) \
        (REG_BIT_CLEAR8(DMACHMUX_CHCONFIG((channel)), DMACHMUX_CHCONFIG_TRIG_U8))
    /** @violates @ref Mcl_DMAMUX_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. */
    #define DMAMUX_UPDATE_SOURCE(channel, new_source) \
        (REG_RMW8(DMACHMUX_CHCONFIG((channel)), DMACHMUX_CHCONFIG_SOURCE_U8, (new_source)))
        
    #define MODE_SHIFT_MASK (6UL)    
    /** size of register space **/
    #define DMAMUX_REG_PROT_SIZE ((uint32)0x4U)
#endif
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_DMAMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"
        
FUNC(void, MCL_CODE) Mcl_DmaMux_Init( P2CONST(Mcl_DmaMuxConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaMuxConfig);           
#if (MCL_DEINIT_API == STD_ON)
FUNC(void, MCL_CODE) Mcl_DmaMux_DeInit( P2CONST(Mcl_DmaMuxConfigType, AUTOMATIC, MCL_APPL_CONST) pDmaMuxConfig);          
#endif
#if (MCL_ENABLE_USER_MODE_SUPPORT == STD_ON)
    #if (MCL_DMAMUX_REG_PROT_AVAILABLE == STD_ON)
        FUNC(void, MCL_CODE) Mcl_Dma_Mux_Set_User_Access (void);
    #endif
#endif
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_DMAMUX_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Mcl_MemMap.h"

#endif
#endif

#ifdef __cplusplus
}
#endif

#endif /* MCL_DMAMUX_H */

/** @} */