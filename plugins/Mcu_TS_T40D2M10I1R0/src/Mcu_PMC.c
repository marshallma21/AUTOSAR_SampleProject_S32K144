/**
*   @file    Mcu_PMC.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Power Management Controller module functions implementation.
*   @details Specific functions for PMC configuration and control.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723
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
* @section Mcu_PMC_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_PMC_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_PMC_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_PMC_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_PMC_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section Mcu_PMC_c_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_PMC.h"
#include "Mcu.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#endif

#include "SilRegMacros.h"

/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define MCU_PMC_VENDOR_ID_C                      43
/** @violates @ref Mcu_PMC_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_PMC_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_PMC_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_PMC_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_PMC_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_PMC_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_PMC_SW_MAJOR_VERSION_C               1
#define MCU_PMC_SW_MINOR_VERSION_C               0
#define MCU_PMC_SW_PATCH_VERSION_C               1


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if source file and Mcu_PMC header file are of the same vendor. */
#if (MCU_PMC_VENDOR_ID_C != MCU_PMC_VENDOR_ID)
    #error "Mcu_PMC.c and Mcu_PMC.h have different Vendor IDs."
#endif
#ifdef CHECK_AUTOSAR_VERSION
  /* Check if source file and Mcu_PMC header file are of the same Autosar version. */
  #if ( (MCU_PMC_AR_RELEASE_MAJOR_VERSION_C != MCU_PMC_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_PMC_AR_RELEASE_MINOR_VERSION_C != MCU_PMC_AR_RELEASE_MINOR_VERSION) || \
        (MCU_PMC_AR_RELEASE_REVISION_VERSION_C != MCU_PMC_AR_RELEASE_REVISION_VERSION) \
      )
        #error "AutoSar Version Numbers of Mcu_PMC.c and Mcu_PMC.h are different."
  #endif
#endif
/* Check if source file and Mcu_PMC header file are of the same Software version. */
#if ( (MCU_PMC_SW_MAJOR_VERSION_C != MCU_PMC_SW_MAJOR_VERSION) || \
      (MCU_PMC_SW_MINOR_VERSION_C != MCU_PMC_SW_MINOR_VERSION) || \
      (MCU_PMC_SW_PATCH_VERSION_C != MCU_PMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMC.c and Mcu_PMC.h are different."
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PMC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PMC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PMC.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PMC_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PMC_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PMC.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same vendor */
#if (MCU_PMC_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_PMC.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PMC_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_PMC_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_PMC_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_PMC.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_PMC_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_PMC_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_PMC_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_PMC.c and Mcu.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_PMC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PMC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
#if (STD_ON == MCU_PMC_REG_PROT_AVAILABLE)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
* @violates @ref Mcu_PMC_c_REF_5 Global declaration of function
*/
FUNC( void, MCU_CODE) Mcu_PMC_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_PMC_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(PMC_BASEADDR, PMC_PROT_MEM_U32);
}
#endif /* (STD_ON == MCU_PMC_REG_PROT_AVAILABLE) */
#endif /* (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT) */
#endif /* MCU_ENABLE_USER_MODE_SUPPORT */

/**
* @brief            This function configure the Power Management Controller
* @details          The operating voltages are monitored by a set of on-chip supervisory circuits
*                   to ensure that this device works within the correct voltage range.
*                   Called by:
*                       - Mcu_IPW_Init() from IPW.
*
* @param[in]        pConfigPtr   Pointer to PMC configuration structure.
*
* @return           void
*
*/
/** @violates @ref Mcu_PMC_c_REF_5 Global declaration of function */
FUNC( void, MCU_CODE) Mcu_PMC_PowerInit(P2CONST( Mcu_PMC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
#if (IPV_PMC == IPV_PMC_03_00_01_00)
    VAR(uint32, AUTOMATIC) u32Tmp;
#endif

#if (IPV_PMC == IPV_PMC_00_00_01_20)
    /* Control register */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_CR_ADDR32, pConfigPtr->u32ControlConfig | PMC_CR_VM_PMC_ENABLE_MASK32);

    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_CR_ADDR32, pConfigPtr->u32ControlConfig);
    
    /* Reset Event Enable */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_REE_ADDR32, pConfigPtr->u32ResetEventEn | PMC_REE_VM_PMC_RST_EN_MASK32);

    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_REE_ADDR32, pConfigPtr->u32ResetEventEn);
    
    /* Fault Event Enable */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_FEE_ADDR32, pConfigPtr->u32FaultEventEn);

    /* Interrupt Event Enable */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_IEE_ADDR32, pConfigPtr->u32InterruptEventEn);

#elif (IPV_PMC == IPV_PMC_00_00_00_15)
    /* Temperature Sensor Event interrupt enable */
    /* Write TS_EN bit to enable writing and reading the register at any time */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_BIT_SET32(PMC_TS_IER_ADDR32, PMC_TS_IER_TS_EN_MASK32);

    /* Write the configured value in the register */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_TS_IER_ADDR32, (pConfigPtr->u32TempInterruptEn | PMC_TS_IER_TS_EN_MASK32));

    /* reset event enable */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_REE_TD_ADDR32, pConfigPtr->u32TempResEventEn);

    /* reset event selection */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_RES_TD_ADDR32, pConfigPtr->u32TempResEventSel);

    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_CTL_TD_ADDR32, pConfigPtr->u32TempDetConfig);
    
    /* Enable LVD/HVD interrupts */
    /* Write PMC_ENABLE to enable writing and reading this register */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_BIT_SET32(PMC_LVD_HVD_INTR_ENB_ADDR32, PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32);

    /* Write the configured value in the register */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_LVD_HVD_INTR_ENB_ADDR32, (pConfigPtr->u32LvdHvdInterruptConfig | PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32));
    
    /* Write only ADC_CS field in this register because it is the only one configured in the Mcu plugin */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32(PMC_ADC_CS_ADDR32, PMC_ADC_CS_ADC_CS_MASK32, pConfigPtr->u32AdcChannelSelectConfig);
    
    /* Enable Reset cause by LVD or HVD events. */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_REE_ADDR32, pConfigPtr->u32ResetEventEnableConfig);
    
#elif (IPV_PMC == IPV_PMC_03_00_01_00)
    /* Avoid misaligned access */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Tmp = ((uint32)pConfigPtr->u8Lvdsc1) | ((uint32)pConfigPtr->u8Lvdsc2 << 8) | ((uint32)pConfigPtr->u8Regsc << 16);
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32(PMC_BASEADDR, PMC_REG_RWBITS_MASK32, u32Tmp);
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE8(PMC_LPOTRIM_ADDR32, pConfigPtr->u8LpoTrim);

#elif (IPV_PMC == IPV_PMC_01_00_02_05)
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_MCR_ADDR32, pConfigPtr->u32PowerCtrl);
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_TRIMR_ADDR32, pConfigPtr->u32PowerTrim);
#endif
}

#if (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON)
/**
* @brief            This function handle the voltage error detection.
*
* @return           void
*
* @isr
* @implements Mcu_PMC_VoltageErrorIsr_Activity
*/
/** @violates @ref Mcu_PMC_c_REF_5 Global declaration of function */
FUNC( void, MCU_CODE) Mcu_PMC_VoltageErrorIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32VoltageIsrStatus;
    VAR( uint32, AUTOMATIC) u32VoltageIsrEnabled;

#if (IPV_PMC == IPV_PMC_00_00_01_20)
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_SSR_ADDR32) & PMC_SSR_VOLTAGE_BITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_SSR_ADDR32, u32VoltageIsrStatus);
#elif (IPV_PMC == IPV_PMC_00_00_00_15)
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_LVD_HVD_EVENT_STATUS_ADDR32) & PMC_LVD_HVD_EVENT_STATUS_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_LVD_HVD_EVENT_STATUS_ADDR32, u32VoltageIsrStatus);
#elif (IPV_PMC == IPV_PMC_01_00_02_05)
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_SR_ADDR32) & PMC_SR_LVIS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_SR_ADDR32, u32VoltageIsrStatus);
#elif (IPV_PMC == IPV_PMC_03_00_01_00)
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_BASEADDR) & ((uint32)PMC_LVDSC1_LVDF_MASK8);
    /* clear IRQ flags */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32(PMC_BASEADDR,((uint32)PMC_LVDSC1_LVDACK_MASK8), ((uint32)PMC_LVDSC1_LVDACK_MASK8));
#endif

    if(NULL_PTR != Mcu_pConfigPtr)
    {
#if (IPV_PMC == IPV_PMC_00_00_01_20)
        /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
        u32VoltageIsrEnabled = REG_READ32(PMC_IEE_ADDR32) & PMC_IEE_RWBITS_MASK32;
#elif (IPV_PMC == IPV_PMC_00_00_00_15)
        /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
        u32VoltageIsrEnabled = REG_READ32(PMC_LVD_HVD_INTR_ENB_ADDR32) & PMC_LVD_HVD_INTR_ENB_RWBITS_USR_MASK32;
#elif (IPV_PMC == IPV_PMC_01_00_02_05)
        /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
        u32VoltageIsrEnabled = REG_READ32(PMC_MCR_ADDR32) & PMC_MCR_LVIE_MASK32;
#elif (IPV_PMC == IPV_PMC_03_00_01_00)
        /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
        u32VoltageIsrEnabled = REG_READ32(PMC_BASEADDR) & ((uint32)PMC_LVDSC1_LVDIE_MASK8);
#endif

        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != u32VoltageIsrEnabled))
        {
#ifdef MCU_ERROR_ISR_NOTIFICATION
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_VOLTAGE_ERROR);
#endif
        }
    }
}


/**
* @brief            This function get status voltage error
*
* @return           void
*
* @isr
* @implements Mcu_PMC_GetInterruptStatus
* @violates @ref Mcu_PMC_c_REF_5 Global declaration of function
*/
FUNC( uint32, MCU_CODE) Mcu_PMC_GetInterruptStatus(VAR( void, AUTOMATIC))
{
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    return ( REG_READ32(PMC_BASEADDR) & ((uint32)PMC_LVDSC1_LVDF_MASK8) );
}

#endif /* (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON) */

#if ( MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON )
/**
* @brief            This function handle the voltage error detection.
* @details          PMC_ESR_0 bits acivate an interrupt only if corresponding bit from
*                   PMC_IER is set.
*
* @return           void
*
* @isr
* @implements Mcu_PMC_TemperatureErrorIsr_Activity
*/
/** @violates @ref Mcu_PMC_c_REF_5 Global declaration of function */
FUNC( void, MCU_CODE) Mcu_PMC_TemperatureErrorIsr( VAR( void, AUTOMATIC) )
{
    VAR(uint32, AUTOMATIC) u32TempSenseStatus;
    VAR(uint32, AUTOMATIC) u32TempSenseEnabled;

    /* get the status flags */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    u32TempSenseStatus = REG_READ32(PMC_ESR_TD_ADDR32) & PMC_ESR_TD_RWBITS_MASK32;
    /* clean the enabled status flags */
    /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PMC_ESR_TD_ADDR32, u32TempSenseStatus);
    
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_PMC_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_PMC_c_REF_6 The cast is used to access memory mapped registers.*/
        u32TempSenseEnabled = REG_READ32(PMC_TS_IER_ADDR32) & PMC_TS_IER_RWBITS_USR_MASK32;

        if((uint32)0x00000000U != (PMC_ESR_TD_RWBITS_MASK32 & u32TempSenseStatus))
        {
            if((uint32)0x00000000U != (PMC_TS_IER_RWBITS_USR_MASK32 & u32TempSenseEnabled))
            {
                /* report */
#ifdef MCU_ERROR_ISR_NOTIFICATION
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_TEMPERATURE_MONITOR_ERROR);
#endif
            }
        }
    }
}
#endif /* ( MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON ) */


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_PMC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PMC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
