/**
*   @file    Mcu_SIM.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - System Mode Controller functions implementation.
*   @details Specific functions for SIM configuration and control.
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
* @section Mcu_SIM_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_SIM_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_SIM_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_SIM_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_SIM_c_REF_5
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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_SIM.h"
#include "Reg_eSys_SIM.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#endif

#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_SIM_VENDOR_ID_C                      43
/** @violates @ref Mcu_SIM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SIM_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_SIM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SIM_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_SIM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SIM_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_SIM_SW_MAJOR_VERSION_C               1
#define MCU_SIM_SW_MINOR_VERSION_C               0
#define MCU_SIM_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_SIM header file are of the same vendor */
#if (MCU_SIM_VENDOR_ID_C != MCU_SIM_VENDOR_ID)
    #error "Mcu_SIM.c and Mcu_SIM.h have different vendor ids"
#endif
/* Check if current file and Mcu_SIM header file are of the same Autosar version */
#if ((MCU_SIM_AR_RELEASE_MAJOR_VERSION_C    != MCU_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIM_AR_RELEASE_MINOR_VERSION_C    != MCU_SIM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIM_AR_RELEASE_REVISION_VERSION_C != MCU_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SIM.c and Mcu_SIM.h are different"
#endif
/* Check if current file and Mcu_SIM header file are of the same Software version */
#if ((MCU_SIM_SW_MAJOR_VERSION_C != MCU_SIM_SW_MAJOR_VERSION) || \
     (MCU_SIM_SW_MINOR_VERSION_C != MCU_SIM_SW_MINOR_VERSION) || \
     (MCU_SIM_SW_PATCH_VERSION_C != MCU_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SIM.c and Mcu_SIM.h are different"
#endif

/* Check if source file and Reg_eSys_SIM.h are from the same vendor */
#if (MCU_SIM_VENDOR_ID != REG_ESYS_SIM_VENDOR_ID)
    #error "Mcu_SIM.C and Reg_eSys_SIM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SIM.h are of the same Autosar version */
#if ((MCU_SIM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SIM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SIM.c and Reg_eSys_SIM.h are different"
#endif
/*Check if source file and Reg_eSys_SIM.h are of the same Software version */
#if ((MCU_SIM_SW_MAJOR_VERSION_C != REG_ESYS_SIM_SW_MAJOR_VERSION) || \
     (MCU_SIM_SW_MINOR_VERSION_C != REG_ESYS_SIM_SW_MINOR_VERSION) || \
     (MCU_SIM_SW_PATCH_VERSION_C != REG_ESYS_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SIM.c and Reg_eSys_SIM.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SIM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SIM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SIM.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SIM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SIM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SIM.c and SilRegMacros.h are different"
    #endif
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
* @violates @ref Mcu_SIM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function configure the System Integration Module (SIM).
* @details          This routine initializes the SIM module that provides system control
*                   and chip configuration registers.
*                   Called by:
*                       - Mcu_IPW_Init() from IPW.
*
* @param[in]        pConfigPtr   Pointer to SIM configuration structure.
*
* @return           void
*
*/

FUNC( void, MCU_CODE) Mcu_SIM_Init(P2CONST(Mcu_SIM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /* Configure SIM_CHIPCTL general settings (COCO_TRG_SEL, PDB_BB_SEL, DAC2CMP_SEL, ADC_INTERLEAVE_SEL) */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SIM_CHIPCTL_ADDR32, SIM_CHIPCTL_INIT_MASK32, (uint32)pConfigPtr->u32ChipControlConfiguration);
    /* Configure SIM_LPOCLKS register that is a write once register */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_LPOCLKS_ADDR32, ((uint32)pConfigPtr->u32LPOClockConfiguration & SIM_LPOCLKS_RWBITS_MASK32));
    /* Configure SIM_ADCOPT register */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_ADCOPT_ADDR32, ((uint32)pConfigPtr->u32AdcOptionsConfiguration & SIM_ADCOPT_RWBITS_MASK32));
    /* Configure SIM_FTMOPT0 and SIM_FTMOPT1 registers */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_FTMOPT0_ADDR32, ((uint32)pConfigPtr->u32FTMOPT0Configuration & SIM_FTMOPT0_RWBITS_MASK32));
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_FTMOPT1_ADDR32, ((uint32)pConfigPtr->u32FTMOPT1Configuration & SIM_FTMOPT1_RWBITS_MASK32));
    /* Configure SIM_MISCTRL0 register */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_MISCTRL0_ADDR32, ((uint32)pConfigPtr->u32MiscellaneousConfiguration0 & SIM_MISCTRL0_RWBITS_MASK32));
    /* Configure SIM_MISCTRL1 register */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_MISCTRL1_ADDR32, ((uint32)pConfigPtr->u32MiscellaneousConfiguration1 & SIM_MISCTRL1_RWBITS_MASK32));
}

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            SIM clock initialization function.
* @details          This function intializes the clock that is controled by SIM module.
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        pClockConfigPtr   Pointer to SIM configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_SIM_ClockConfig(P2CONST(Mcu_SIM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pClockConfigPtr)
{
    /* Configure PLATGC register */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_PLATCGC_ADDR32, ((uint32)pClockConfigPtr->u32ClockGatingConfiguration & SIM_PLATGC_RWBITS_MASK32));
    
    /* Configure SIM_CHIPCTL clock settings (TRACECLK_SEL, CLKOUTEN, CLKOUTDIV, CLKOUT_SEL) */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SIM_CHIPCTL_ADDR32, SIM_CHIPCTL_CLOCK_MASK32, ((uint32)pClockConfigPtr->u32ChipControlClockConfiguration & (~SIM_CHIPCTL_CLKOUTEN_MASK32)));
    /* Enable Clockout */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SIM_CHIPCTL_ADDR32, SIM_CHIPCTL_CLKOUTEN_MASK32, ((uint32)pClockConfigPtr->u32ChipControlClockConfiguration & SIM_CHIPCTL_CLKOUTEN_MASK32));
    
    /* Configure Trace Clock settings */
    /** @violates @ref Mcu_SIM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SIM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SIM_CLKDIV4_ADDR32, ((uint32)pClockConfigPtr->u32TraceClockConfiguration & SIM_CLKDIV4_RWBITS_MASK32));
}
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SIM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SIM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
