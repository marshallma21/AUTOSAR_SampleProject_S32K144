/**
*   @file    Icu_Lptmr.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - LPTMR driver source file.
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FTM PORT_CI LPIT LPTMR
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
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section ICU_LPTMR_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section ICU_LPTMR_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section ICU_LPTMR_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section ICU_LPTMR_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section ICU_LPTMR_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section ICU_LPTMR_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Reg_eSys_Lptmr.h"
#include "Icu_Lptmr.h"

#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_LPTMR_VENDOR_ID_C                    43
/** @violates @ref ICU_LPTMR_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref ICU_LPTMR_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref ICU_LPTMR_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define ICU_LPTMR_AR_RELEASE_REVISION_VERSION_C  2
#define ICU_LPTMR_SW_MAJOR_VERSION_C             1
#define ICU_LPTMR_SW_MINOR_VERSION_C             0
#define ICU_LPTMR_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Lptmr.c and Mcal.h are different"
    #endif
#endif

#if (ICU_LPTMR_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Lptmr.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_LPTMR_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Lptmr.c and Icu_Cfg.h are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_LPTMR_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_LPTMR_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_LPTMR_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Lptmr.c and Icu_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Lptmr.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if source file and Reg_eSys_Lptmr.h file are of the same vendor */
#if (ICU_LPTMR_VENDOR_ID_C != REG_ESYS_LPTMR_VENDOR_ID)
#error "Icu_Lptmr.c and Reg_eSys_Lptmr.h have different vendor IDs"
#endif
#if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPTMR_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lptmr.c and Reg_eSys_Lptmr.h are different"
#endif
/* Check if source file and Reg_eSys_Lptmr.h header file are of the same Software version */
#if ((ICU_LPTMR_SW_MAJOR_VERSION_C != REG_ESYS_LPTMR_SW_MAJOR_VERSION) || \
     (ICU_LPTMR_SW_MINOR_VERSION_C != REG_ESYS_LPTMR_SW_MINOR_VERSION) || \
     (ICU_LPTMR_SW_PATCH_VERSION_C != REG_ESYS_LPTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lptmr.c and Reg_eSys_Lptmr.h are different"
#endif

/* Check if source file and Icu_Lptmr.h file are of the same vendor */
#if (ICU_LPTMR_VENDOR_ID_C != ICU_LPTMR_VENDOR_ID)
#error "Icu_Lptmr.c and Icu_Lptmr.h have different vendor IDs"
#endif
    #if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != ICU_LPTMR_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != ICU_LPTMR_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LPTMR_AR_RELEASE_REVISION_VERSION_C != ICU_LPTMR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Lptmr.c and Icu_Lptmr.h are different"
    #endif
/* Check if source file and Icu_Lptmr.h header file are of the same Software version */

#if ((ICU_LPTMR_SW_MAJOR_VERSION_C != ICU_LPTMR_SW_MAJOR_VERSION) || \
     (ICU_LPTMR_SW_MINOR_VERSION_C != ICU_LPTMR_SW_MINOR_VERSION) || \
     (ICU_LPTMR_SW_PATCH_VERSION_C != ICU_LPTMR_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lptmr.c and Icu_Lptmr.h are different"
#endif

#if (ICU_LPTMR_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Lptmr.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lptmr.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_LPTMR_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_LPTMR_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_LPTMR_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lptmr.c and Icu_Ipw_Types.h are different"
#endif

#if (ICU_LPTMR_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
    #error "Icu_Lptmr.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Autosar version */
#if ((ICU_LPTMR_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPTMR_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Lptmr.c and Icu_Ipw_Irq.h are different"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Software version */
#if ((ICU_LPTMR_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (ICU_LPTMR_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
     (ICU_LPTMR_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Lptmr.c and Icu_Ipw_Irq.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef uint8 Icu_Lptmr_ChConfigType;


/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define LPTMR_ICU_MEAS_MODE_MASK_U8            ((uint8)(BIT4|BIT3|BIT2|BIT1))
#define LPTMR_ICU_MEAS_MODE_SHIFT_U8           (1U)

#define LPTMR_ICU_CH_INITIALIZED_MASK_U8       ((uint8)BIT0)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref ICU_LPTMR_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref ICU_LPTMR_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"
static VAR(Icu_Lptmr_ChConfigType, ICU_VAR) Icu_Lptmr_aChConfig[ICU_MAX_LPTMR_CHANNELS]  =
                                                                                      {
                                                                                        (uint8)0U
                                                                                      };

#define ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref ICU_LPTMR_C_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref ICU_LPTMR_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/**
* @violates @ref ICU_LPTMR_C_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*               comments before "#include"
* @violates @ref ICU_LPTMR_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*               contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#if ((ICU_SET_MODE_API == STD_ON)||(ICU_EDGE_DETECT_API == STD_ON))
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Lptmr_EnableInterrupt(void);
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Lptmr_DisableInterrupt(void);
#endif

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Lptmr_SetChConfig( \
                                                    VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel, \
                                                    VAR(Icu_Lptmr_ChConfigType, AUTOMATIC) mask);

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Lptmr_ClearChConfig( \
                                                    VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel, \
                                                    VAR(Icu_Lptmr_ChConfigType, AUTOMATIC) mask);

#if (defined ICU_LPTMR_0_CH_0_ISR_USED)
LOCAL_INLINE FUNC(Icu_Lptmr_ChConfigType, ICU_CODE) Icu_Lptmr_GetChConfig( \
                                                    VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel, \
                                                    VAR(Icu_Lptmr_ChConfigType, AUTOMATIC) mask);
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

#if ((ICU_SET_MODE_API == STD_ON)||(ICU_EDGE_DETECT_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu driver function that enables interrupts on a Lptmr channel
* @details    This function enables Lptmr Channel Interrupt
*
*
* @return void
*
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Lptmr_EnableInterrupt(void)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    {
        /* clear interrupt flag */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
        /* Timer interrupt is enabled */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}
#endif

#if ((ICU_SET_MODE_API == STD_ON)||(ICU_EDGE_DETECT_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu driver function that disables interrupts on a Lptmr channel
* @details    This function disables Lptmr Channel Interrupt
*
*
* @return void
*
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Lptmr_DisableInterrupt(void)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    {
        /* clear interrupt flag */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
        /* Timer interrupt is disabled */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}

#endif
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_SetChConfig
* @details    Set the Icu_Lptmr_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
/*================================================================================================*/
LOCAL_INLINE \
    FUNC(void, ICU_CODE) Icu_Lptmr_SetChConfig(VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel, \
                                               VAR(Icu_Lptmr_ChConfigType, AUTOMATIC) mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18();
    Icu_Lptmr_aChConfig[hwChannel] |= mask;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18();
}

/*================================================================================================*/
/**
* @brief      Icu_Lptmr_ClearChConfig
* @details    Clear the Icu_Lptmr_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
/*================================================================================================*/
LOCAL_INLINE \
    FUNC(void, ICU_CODE) Icu_Lptmr_ClearChConfig(VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel, \
                                                 VAR(Icu_Lptmr_ChConfigType, AUTOMATIC) mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18();
    Icu_Lptmr_aChConfig[hwChannel]  &= ((~mask));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18();
}

#if (defined ICU_LPTMR_0_CH_0_ISR_USED)
/*================================================================================================*/
/**
 * @brief      Icu_Lptmr_GetChConfig
 * @details    Return the Icu_Lptmr_aChConfig bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]      hwChannel  - The index of ICU channel for current configuration structure
 * @param[in]      mask    - bitfield mask
 * @return         Bitfield specified by mask parameter
 */
 /*================================================================================================*/
LOCAL_INLINE \
    FUNC(Icu_Lptmr_ChConfigType, ICU_CODE) Icu_Lptmr_GetChConfig( \
                                                    VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel, \
                                                    VAR(Icu_Lptmr_ChConfigType, AUTOMATIC) mask)
{
    return (Icu_Lptmr_aChConfig[hwChannel] & mask);
}
#endif
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Icu driver initialization function for Lptmr module.
* @details This function is called separately for each LPTMR hw channel corresponding to the configured
*          timer channels, and:
*          - Disables the LPTMR module
*          - Timer Interrupt Enable
*          - Timer Pin Select
*          - Clear pending interrupts
*          - Set Pulse counter mode
*          - Set Clock Source
*          - Set Prescaler
*          - LPTMR is enabled
*
* @return void
*
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_Init
(
    P2CONST(Icu_Lptmr_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pLptmrIpConfig
)
{
    /* @brief Pointer to Lptmr channel specific configuration */
    P2CONST(Icu_Lptmr_ChannelConfigType,      AUTOMATIC,ICU_APPL_CONST) pLptmrChannelConfig;
    P2CONST(Icu_Lptmr_GlobalConfigurationType,AUTOMATIC,ICU_APPL_CONST) pGlobalConfig;
    VAR(Icu_Lptmr_ControlType,                AUTOMATIC)  nCtrlRegVal;
    VAR(uint8,                                AUTOMATIC)  u8PinSelect;
    VAR(uint8,                                AUTOMATIC)  u8ClockSource;
    VAR(uint8,                                AUTOMATIC)  u8Prescaler;
    VAR(uint8,                                AUTOMATIC)  u8HwChannel;
    VAR(uint8,                                AUTOMATIC)  u8PrescalerEnable;
#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
    VAR(Icu_Lptmr_ChannelMeasurementModeType, AUTOMATIC)  nChannelMode;
#endif

    /* only handle Lptmr channels */
    pLptmrChannelConfig = &(*pLptmrIpConfig->pChannelsConfig)[0];
    pGlobalConfig = pLptmrIpConfig->Icu_GlobalConfiguration;
    u8ClockSource = (uint8)((((*pGlobalConfig) & ICU_LPTMR_PSR_PCS_MASK_U32) >> ICU_LPTMR_PSR_PCS_SHIFT_U32) << LPTMR_PSR_PCS_SHIFT);
    u8Prescaler   = (uint8)((((*pGlobalConfig) & ICU_LPTMR_PSR_PRESCALE_MASK_U32) >> ICU_LPTMR_PSR_PRESCALE_SHIFT_U32) << LPTMR_PSR_PRESCALE_SHIFT);
    u8HwChannel   = pLptmrChannelConfig->nHwChannel;
    nCtrlRegVal   = pLptmrChannelConfig->nControlValue;

    u8PinSelect   = (uint8)(((nCtrlRegVal & ICU_LPTMR_CSR_TPS_MASK_U32) >> ICU_LPTMR_CSR_TPS_SHIFT_U32) << LPTMR_CSR_TPS_SHIFT);
    u8PrescalerEnable    = (uint8)((nCtrlRegVal & ICU_LPTMR_PSR_PBYP_MASK_U32) >> ICU_LPTMR_PSR_PBYP_SHIFT_U32);

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
    nChannelMode = (Icu_Lptmr_ChannelMeasurementModeType)(pLptmrChannelConfig->nMeasurementModeType);
#endif

    Icu_Lptmr_ClearChConfig((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(u8HwChannel), \
                (Icu_Lptmr_ChannelType)(LPTMR_ICU_MEAS_MODE_MASK_U8 | LPTMR_ICU_CH_INITIALIZED_MASK_U8));

    /* Stop Channel to Configure Channel. This shall be be executed before any other setup is made */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);

    /* Timer Pin Select  */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPTMR_CSR_ADDR32,LPTMR_CSR_TPS_MASK_U32,((uint32)u8PinSelect));

    /* Timer Interrupt Disable*/
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

    /* Clear pending interrupts */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);

    /* Set Pulse counter mode */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TMS_MASK_U32);

    /* Set Clock Source */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(LPTMR_PSR_ADDR32,LPTMR_PSR_PCS_MASK_U32,((uint32)u8ClockSource));

    if((uint8)1U == u8PrescalerEnable)
    {
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Prescaler/glitch filter is enabled */
        REG_BIT_CLEAR32(LPTMR_PSR_ADDR32, LPTMR_PSR_PBYP_MASK_U32);
        /* Set Prescaler */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(LPTMR_PSR_ADDR32,LPTMR_PSR_PRESCALE_MASK_U32,((uint32)u8Prescaler));
    }
    else
    {
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Prescaler/glitch filter is bypassed */
        REG_BIT_SET32(LPTMR_PSR_ADDR32, LPTMR_PSR_PBYP_MASK_U32);
    }

    /* Set Activation Condition */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    Icu_Lptmr_SetActivationCondition
    (
        u8HwChannel,
        (Icu_Lptmr_ActivationType)(pLptmrChannelConfig->nDefaultStartEdge)
    );
#if (ICU_EDGE_COUNT_API == STD_ON)
    if (LPTMR_CHANNEL_MODE_EDGE_COUNTER == nChannelMode)
    {
        /* CNR is reset on overflow */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TFC_MASK_U32);
    }
#endif
#if (ICU_EDGE_DETECT_API == STD_ON)
    if (LPTMR_CHANNEL_MODE_SIGNAL_EDGE_DETECT == nChannelMode)
    {
        /* CNR is reset whenever TCF is set. */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TFC_MASK_U32);
        /* set the hardware trigger asserts until the next time the CNR increments */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(LPTMR_CMR_ADDR32,(uint32)1U);
    }
#endif
    /* LPTMR is enabled*/
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);

    /* Record the init */
    Icu_Lptmr_SetChConfig((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(u8HwChannel),LPTMR_ICU_CH_INITIALIZED_MASK_U8);
}


#if (ICU_DE_INIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Icu driver de-initialization function for Lptmr module.
* @details This function is called separately for each LPTMR hw channel corresponding to the configured
*          timer channels, and:
*          - Disables the LPTMR module
*          - Disable Timer Interrupt
*          - Clear pending interrupts
*
* @return void
*
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_DeInit
(
    P2CONST(Icu_Lptmr_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pLptmrIpConfig
)
{

    /* @brief Pointer to Lptmr channel specific configuration */
    P2CONST(Icu_Lptmr_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pLptmrChannelConfig;
    VAR(uint8,                               AUTOMATIC)  u8HwChannel;

    /* only handle Lptmr channels */
    pLptmrChannelConfig = &(*pLptmrIpConfig->pChannelsConfig)[0];
    u8HwChannel   = pLptmrChannelConfig->nHwChannel;

    /* Stop Channel to Configure Channel. This shall be be executed before any other setup is made */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);

    /* Disable Timer Interrupt */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

    /* Clear pending interrupts */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);

    /* Record the deinit */
    Icu_Lptmr_ClearChConfig((Icu_Lptmr_ChannelType)ICU_LPTMR_CHANNELS(u8HwChannel), \
        (Icu_Lptmr_ChannelType)(LPTMR_ICU_MEAS_MODE_MASK_U8 | LPTMR_ICU_CH_INITIALIZED_MASK_U8));
}
#endif

#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that sets Lptmr hardware channel into SLEEP mode.
* @details    This function enables the interrupt if wakeup is enabled for corresponding
*             Lptmr channel
*
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_SetSleepMode(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    (void) hwChannel;
    /* Disable Interrupt */
    Icu_Lptmr_DisableInterrupt();
}

/*================================================================================================*/
/**
* @brief      Driver function that sets the Lptmr hardware channel into NORMAL mode.
* @details    This function enables the interrupt if Notification is enabled for corresponding
*             Lptmr channel
*
*
* @return void
*
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_Lptmr_SetNormalMode(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    (void) hwChannel;
    /* Enable Interrupt */
    Icu_Lptmr_EnableInterrupt();
}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/
/**
* @brief      Driver function that sets activation condition of SIUL2 channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding SIUL channels.
*
* @param[in]  hwChannel -  Hardware channel
* @param[in]  Activation - Activation condition
*
* @return void
*
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Lptmr_SetActivationCondition
(
    VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel,
    VAR(Icu_Lptmr_ActivationType, AUTOMATIC) Activation
)
{
    (void) hwChannel;
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17();
    {
        if(LPTMR_RISING_EDGE == Activation)
        {
            /*  Pulse Counter input source is active-high, and the CNR will increment on the rising-edge */
            /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TPP_MASK_U32);
        }
        else
        {
            /* Pulse Counter input source is active-low, and the CNR will increment on the falling-edge */
            /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TPP_MASK_U32);
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17();
}

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_EnableEdgeDetection
* @details    This function enables the interrupt corresponding to the Lptmr channel.
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_EnableEdgeDetection(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    /* Enable Interrupt */
    Icu_Lptmr_EnableInterrupt();
    /* Set Edge Detect mode for the Lptmr channel in the configuration array */
    Icu_Lptmr_SetChConfig(hwChannel, \
          (Icu_Lptmr_ChannelType)((Icu_Lptmr_ChannelType)LPTMR_CHANNEL_MODE_SIGNAL_EDGE_DETECT \
                                                                << LPTMR_ICU_MEAS_MODE_SHIFT_U8));
}
#endif  /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_DisableEdgeDetection
* @details    This function enables the interrupt corresponding to the Lptmr channel.
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_DisableEdgeDetection(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    /* Disable Interrupt */
    Icu_Lptmr_DisableInterrupt();
    /* Clear mode for the Lptmr channel in the configuration array */
    Icu_Lptmr_ClearChConfig(hwChannel, \
          (Icu_Lptmr_ChannelType)((Icu_Lptmr_ChannelType)LPTMR_CHANNEL_MODE_SIGNAL_EDGE_DETECT \
                                                                << LPTMR_ICU_MEAS_MODE_SHIFT_U8));
}
#endif  /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_ResetEdgeCount
* @details    This function reset the edge counting for an Lptmr channel
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_ResetEdgeCount(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    (void) hwChannel;
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* Disable Lower Power Timer */
    REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    /* LPTMR is enabled*/
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_EnableEdgeCount
* @details    This function starts the edge counting service for an Lptmr channel
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_EnableEdgeCount(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    {
        /* LPTMR is disabled*/
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
        /* LPTMR is enabled*/
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TEN_MASK_U32);
        /* Set Edge Counter mode for the Lptmr channel in the configuration array */
        Icu_Lptmr_SetChConfig(hwChannel, \
            (Icu_Lptmr_ChannelType)((Icu_Lptmr_ChannelType)LPTMR_CHANNEL_MODE_EDGE_COUNTER \
                                                                << LPTMR_ICU_MEAS_MODE_SHIFT_U8));
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_DisableEdgeCount
* @details    This function disable the edge counting service for an Lptmr channel
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Lptmr_DisableEdgeCount(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    /* Clear mode for the Lptmr channel in the configuration array */
    Icu_Lptmr_ClearChConfig(hwChannel, \
          (Icu_Lptmr_ChannelType)((Icu_Lptmr_ChannelType)LPTMR_CHANNEL_MODE_EDGE_COUNTER \
                                                            << LPTMR_ICU_MEAS_MODE_SHIFT_U8));
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_GetEdgeNumbers
* @details    This function get the edge numbers
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(uint16, ICU_CODE) Icu_Lptmr_GetEdgeNumbers(CONST(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(uint16, AUTOMATIC) u16EdgeNumbers;

    (void) hwChannel;
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* write to CNR reg with any value */
    REG_WRITE16(LPTMR_CNR_ADDR32,(uint16)1U);
    /* Get edge numbers */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u16EdgeNumbers = REG_READ16(LPTMR_CNR_ADDR32);

    return u16EdgeNumbers;
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_GetInputState
* @details    This function returns the input state of the corresponding Lptmr channel.
*
* @param[in]  hwChannel
*
* @return void
*
* */
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_Lptmr_GetInputState(VAR(Icu_Lptmr_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(boolean,AUTOMATIC) bStatus = (boolean)FALSE;

    /* Get Interrupt Enable flag */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32LptmrTIECSR = REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

    /* Get Interrupt Status flag */
    /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32LptmrTCFCSR = REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);

    (void) hwChannel;
    /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
    if ((0x0U !=  u32LptmrTCFCSR) && (0x0U == u32LptmrTIECSR))
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
        /* Clear IRQ Flag */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
        bStatus = (boolean)TRUE;
    }

    return bStatus;
}
#endif  /* ICU_GET_INPUT_STATE_API */

#if (defined ICU_LPTMR_0_CH_0_ISR_USED)
/*================================================================================================*/
/**
* @brief      Icu_Lptmr_ProcessInterrupt
*
*
* @return void
*
* @implements Icu_Lptmr_ProcessInterrupt_Activity
* @violates @ref ICU_LPTMR_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
* */
FUNC(void, ICU_CODE) Icu_Lptmr_ProcessInterrupt(void)
{
    VAR(uint32,                               AUTOMATIC) u32Temp1;
    VAR(uint32,                               AUTOMATIC) u32Temp2;
    VAR(Icu_Lptmr_ChannelMeasurementModeType, AUTOMATIC) measMode;

    if (LPTMR_ICU_CH_INITIALIZED_MASK_U8 == Icu_Lptmr_GetChConfig((uint8)0U, LPTMR_ICU_CH_INITIALIZED_MASK_U8))
    {
        /* Get Interrupt Status flag */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32Temp1 = REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);

        /* Get Interrupt Enable flag */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32Temp2 = REG_BIT_GET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TIE_MASK_U32);

        measMode = (Icu_Lptmr_ChannelMeasurementModeType) \
                   (Icu_Lptmr_GetChConfig((uint8)0U,LPTMR_ICU_MEAS_MODE_MASK_U8)>> LPTMR_ICU_MEAS_MODE_SHIFT_U8);

        if ((LPTMR_CSR_TCF_ON_U32 == (u32Temp1 >> LPTMR_CSR_TCF_SHIFT)) && \
            (LPTMR_CSR_TIE_ON_U32 == (u32Temp2 >> LPTMR_CSR_TIE_SHIFT)))
        {
            switch (measMode)
            {
#if (ICU_EDGE_DETECT_API == STD_ON)
                case LPTMR_CHANNEL_MODE_SIGNAL_EDGE_DETECT:
                {
                    Icu_Ipw_ReportEvents(LPTMR_ICU_CHANNEL((uint16)0U), (boolean)FALSE);
                }
                break;
#endif
                default: /* case LPTMR_CHANNEL_MODE_EDGE_COUNTER:*/
#if (ICU_EDGE_COUNT_API == STD_ON)
                {
                    /* Do nothing */
                }
#endif
                break;
            }
        }
    }
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    {
        /* clear interrupt flag */
        /** @violates @ref ICU_LPTMR_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPTMR_C_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPTMR_CSR_ADDR32, LPTMR_CSR_TCF_MASK_U32);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}
#endif

#define ICU_STOP_SEC_CODE
/**
* @violates @ref ICU_LPTMR_C_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref ICU_LPTMR_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
