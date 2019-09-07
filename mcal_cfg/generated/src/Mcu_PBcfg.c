/**
*   @file    Mcu_PBcfg.c
*   @implements Mcu_PBcfg.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details Postbuild structure configurations for the driver initalization.
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
* @section Mcu_PBcfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_PBcfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_PBcfg_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed
* between a pointer to object type and a different pointer to object type.
*
* @section Mcu_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and
* functions shall not be reused
*
* @section Mcu_PBcfg_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is requiered.
*
* @section Mcu_PBcfg_c_REF_8
* Violates MISRA 2004 Required Rule 8.12, when an array is declared with external linkage, it's size shall be stated explicitly
* or defined implicitly by initialisation
*
* @section Mcu_PBcfg_c_REF_9
* Violates MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*
* @section Mcu_PBcfg_c_REF_10
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"

#include "Reg_eSys_PCC.h"
#include "Reg_eSys_PMC.h"
#include "Reg_eSys_RCM.h"
#include "Reg_eSys_SCG.h"
#include "Reg_eSys_SIM.h"
#include "Reg_eSys_SMC.h"
#include "Reg_eSys_CMU.h"

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_PBCFG_VENDOR_ID_C                     43
#define MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C      2
#define MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C   2
#define MCU_PBCFG_SW_MAJOR_VERSION_C              1
#define MCU_PBCFG_SW_MINOR_VERSION_C              0
#define MCU_PBCFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != MCU_VENDOR_ID)
    #error "Mcu_PBcfg.c and Mcu.h have different vendor ids"
#endif
/* Check if current file and MCU header file are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Mcu.h are different"
#endif
/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Mcu.h are different"
#endif

/* Check if source file and Reg_eSys_PCC.h are from the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != REG_ESYS_PCC_VENDOR_ID)
    #error "Mcu_PBcfg.c and Reg_eSys_PCC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_PCC.h are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PCC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PCC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PCC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Reg_eSys_PCC.h are different"
#endif
/*Check if source file and Reg_eSys_PCC.h are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_PCC_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_PCC_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_PCC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Reg_eSys_PCC.h are different"
#endif

/* Check if source file and Reg_eSys_SMC.h are from the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != REG_ESYS_SMC_VENDOR_ID)
    #error "Mcu_PBcfg.c and Reg_eSys_SMC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SMC.h are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Reg_eSys_SMC.h are different"
#endif
/*Check if source file and Reg_eSys_SMC.h are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_SMC_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_SMC_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Reg_eSys_SMC.h are different"
#endif

/* Check if source file and Reg_eSys_SIM.h are from the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != REG_ESYS_SIM_VENDOR_ID)
    #error "Mcu_PBcfg.c and Reg_eSys_SIM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SIM.h are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SIM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Reg_eSys_SIM.h are different"
#endif
/*Check if source file and Reg_eSys_SIM.h are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_SIM_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_SIM_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Reg_eSys_SIM.h are different"
#endif

/* Check if source file and Reg_eSys_SCG.h are from the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != REG_ESYS_SCG_VENDOR_ID)
    #error "Mcu_PBcfg.c and Reg_eSys_SCG.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SCG.h are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SCG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SCG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SCG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Reg_eSys_SCG.h are different"
#endif
/*Check if source file and Reg_eSys_SCG.h are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_SCG_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_SCG_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_SCG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Reg_eSys_SCG.h are different"
#endif

/* Check if source file and Reg_eSys_RCM.h are from the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != REG_ESYS_RCM_VENDOR_ID)
    #error "Mcu_PBcfg.c and Reg_eSys_RCM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_RCM.h are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Reg_eSys_RCM.h are different"
#endif
/*Check if source file and Reg_eSys_RCM.h are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != REG_ESYS_RCM_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != REG_ESYS_RCM_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != REG_ESYS_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Reg_eSys_RCM.h are different"
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PBcfg.c and Dem.h are different"
    #endif
#endif
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
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
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/









/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitClock() API.
*
*/
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_Ram_ConfigPB0[1] =
{

    {
        /* The ID for Ram Sector configuration. */
        (uint8)0U,

        /* RAM section base address: Start of Mcu_RamConfig[0]. */
        /** @violates @ref Mcu_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu_c_REF_5 MISRA 2004 Advisory Rule 11.4, cast between pointer and object */
        /** @violates @ref Mcu_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        (uint8 (*)[1U])0x1fff8000U,

        /* RAM section size: Section base address (must be aligned to 4 bytes). */
        /** @violates @ref Mcu_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        (uint32)0x00000400U,

        /* RAM default value: Section size in bytes (must be multiple of 4). */
        (uint8)0x00U
    } /* End of Mcu_Ram_ConfigPB[0]. */
                
};




/**
* @brief        Definition of MCU mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST( Mcu_ModeConfigType, MCU_CONST) Mcu_Mode_ConfigPB0[1] =
{

    /* Start of Mcu_ModeConfig[0]*/
    {
        /* The ID for Power Mode configuration. */
        (uint8)0U,
        
        /* Power Mode */
        (Mcu_PowerModeType)MCU_RUN_MODE
    }
    /* end of Mcu_Mode_ConfigPB0[0]. */

};




#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Clock settings from the SIM IP.
* @details      Configures SIM_CHIPCTL[TRACECLK_SEL], SIM_CHIPCTL[CLKOUTSEL] bits and SIM_PLATGC and SIM_CLKDIV4 registers.
*               Configuration set by calling Mcu_InitClock API.
*/
static CONST( Mcu_SIM_ClockConfigType, MCU_CONST) SIM_ClockConfigPB0_0 =
{
    /* SIM_CHIPCTL settings. */
    (
        SIM_CHIPCTL_TRACECLK_CORE_CLK_U32 |
        SIM_CHIPCTL_CLKOUT_ENABLE_U32 |
        SIM_CHIPCTL_CLKOUTDIV_U32((uint32)0U) |
        SIM_CHIPCTL_CLKOUTSEL_SOSC_DIV2_U32
    ),
    /* SIM_CLKDIV4 settings. */
    (
        SIM_DEBUG_TRACE_DIVIDER_ENABLED_U32 | 
        SIM_CLKDIV4_TRACEDIV_U32((uint32)1U) |
        SIM_CLKDIV4_TRACEFRAC_0_U32
    ),
    /* SIM_PLATGC settings. */
    (
        SIM_PLATGC_EIM_CLK_ENABLE_U32 |
        SIM_PLATGC_ERM_CLK_ENABLE_U32 |
        SIM_PLATGC_DMA_CLK_ENABLE_U32 |
        SIM_PLATGC_MPU_CLK_ENABLE_U32 |
        SIM_PLATGC_MSCM_CLK_ENABLE_U32 |
        SIM_PLATGC_GPIO_CLK_DISABLE_U32
    )
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */




#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SOSC_ClockConfigPB0_0[MCU_NUMBER_OF_SOSC_REGISTERS_U32] =
{
    /* SCG_SOSCCFG settings. */
    {
        SCG_SOSCCFG_ADDR32,
        (
            SCG_SOSCCFG_HIGH_FREQ_RANGE_U32 |
            SCG_SOSCCFG_INTERNAL_OSCILLATOR_U32 |
            SCG_SOSCCFG_LOW_POWER_OPERATION_U32
        )
    },
    /* SCG_SOSCDIV settings. */
    {
        SCG_SOSCDIV_ADDR32,
        (
            SCG_SOSCDIV_SOSCDIV2_U32((uint32)2U) |
            SCG_SOSCDIV_SOSCDIV1_U32((uint32)1U)
        )
    },
    /* SCG_SOSCCSR settings. */
    {
        SCG_SOSCCSR_ADDR32,
        (
             SCG_SOSCCSR_SOSC_ENABLE_U32 |
             SCG_SOSCCSR_SOSCCMRE_ISR_U32 |
             SCG_SOSCCSR_SOSCCM_DIS_U32
         )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SIRC_ClockConfigPB0_0[MCU_NUMBER_OF_SIRC_REGISTERS_U32] =
{
    /* SCG_SIRCCFG settings. */
    {
        SCG_SIRCCFG_ADDR32,
        (
            SCG_SIRCCFG_HIGH_RANGE_CLOCK_U32
        )
    },
    /* SCG_SIRCDIV settings. */
    {
        SCG_SIRCDIV_ADDR32,
        (
            SCG_SIRCDIV_SIRCDIV2_U32((uint32)2U) |
            SCG_SIRCDIV_SIRCDIV1_U32((uint32)1U)
        )
    },
    /* SCG_SIRCCSR settings. */
    {
        SCG_SIRCCSR_ADDR32,
        (
             SCG_SIRCCSR_SIRC_ENABLE_U32 |
             SCG_SIRCCSR_SIRCLPEN_VLP_DIS_U32 |
             SCG_SIRCCSR_SIRCSTEN_STOP_DIS_U32
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) FIRC_ClockConfigPB0_0[MCU_NUMBER_OF_FIRC_REGISTERS_U32] =
{
    /* SCG_FIRCCFG settings. */
    {
        SCG_FIRCCFG_ADDR32,
        (
            SCG_FIRCCFG_48MHZ_U32
        )
    },
    /* SCG_FIRCDIV settings. */
    {
        SCG_FIRCDIV_ADDR32,
        (
            SCG_FIRCDIV_FIRCDIV2_U32((uint32)2U) |
            SCG_FIRCDIV_FIRCDIV1_U32((uint32)1U)
        )
    },
    /* SCG_FIRCCSR settings. */
    {
        SCG_FIRCCSR_ADDR32,
        (
             SCG_FIRCCSR_FIRC_ENABLE_U32 |
             SCG_FIRCCSR_REGULATOR_DISABLE_U32
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */






#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_RegisterConfigType, MCU_CONST) SPLL_ClockConfigPB0_0[MCU_NUMBER_OF_SPLL_REGISTERS_U32] =
{
    /* SCG_SPLLCFG settings. */
    {
        SCG_SPLLCFG_ADDR32,
        (
            SCG_SPLLCFG_PREDIV_U32((uint32)0U) |
            SCG_SPLLCFG_MULT_U32((uint32)24U)
        )
    },
    /* SCG_SPLLDIV settings. */
    {
        SCG_SPLLDIV_ADDR32,
        (
            SCG_SPLLDIV_SPLLDIV2_U32((uint32)4U) |
            SCG_SPLLDIV_SPLLDIV1_U32((uint32)3U)
        )
    },
    /* SCG_SPLLCSR settings. */
    {
        SCG_SPLLCSR_ADDR32,
        (
             SCG_SPLLCSR_SPLL_ENABLE_U32 |
             SCG_SPLLCSR_SPLLCMRE_ISR_U32 |
             SCG_SPLLCSR_SPLLCM_DIS_U32
        )
    }
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            SCG clock configuration.
* @details          This structure contains information for SOSC, SIRC, FIRC, SPLL, ClockOut and System Clock
*
*/
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SCG_ClockConfigType, MCU_CONST) SCG_ClockConfigPB0_0 =
{

    /* Run Clock Config(SCG_RCCR) */
    (
        SCG_SCS_SPLL_U32 |
        SCG_DIVCORE_U32((uint32)1U) |
        SCG_DIVBUS_U32((uint32)1U) |
        SCG_DIVSLOW_U32((uint32)3U)
    ),
    /* VLPR Clock Config(SCG_VCCR) */
    (
        SCG_SCS_SIRC_U32 |
        SCG_DIVCORE_U32((uint32)1U) |
        SCG_DIVBUS_U32((uint32)0U) |
        SCG_DIVSLOW_U32((uint32)3U)
    ),
    /* High Speed Run Clock Config(SCG_HCCR) */
    (
        SCG_SCS_SPLL_U32 |
        SCG_DIVCORE_U32((uint32)1U) |
        SCG_DIVBUS_U32((uint32)1U) |
        SCG_DIVSLOW_U32((uint32)3U)
    ),


    /* SCG ClockOut Config */
    SCG_CLKOUTCNFG_CLKOUTSEL_SOSC_U32,

    /* SOSC Config */
   &SOSC_ClockConfigPB0_0,

    /* SIRC Config */
    &SIRC_ClockConfigPB0_0,

    /* FIRC Config */
    &FIRC_ClockConfigPB0_0,

    /* SPLL Config */
    &SPLL_ClockConfigPB0_0

};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            CMU configuration.
* @details          This structure contains information for CMU[n]. 
*                   The number of CMU's is defined in the resource files, 
*
*/
static CONST( Mcu_CMU_ConfigType, MCU_CONST) Mcu_CMU_ConfigPB0_0 =
{
    {

    },
    {

    },
    {

    },
    {

    }
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
#endif
#endif




#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PCC_RegisterConfigType, MCU_CONST) PCC_aRegistersConfigPB0_0[MCU_NUMBER_OF_PCC_REGISTERS_U32] =
{

    
    {
        PCC_FTFC_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_DMAMUX0_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PDB1_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_CRC_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PDB0_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_LPIT_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_FTM0_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_FTM1_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_FTM2_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_ADC0_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_RTC_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_LPTMR0_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
             |
            PCC_FRAC_0_U32 |
            PCC_PCD_U32((uint32)0)
            
        )
    }

    ,
    {
        PCC_FLEXCAN0_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PORTA_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PORTB_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PORTC_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PORTD_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_PORTE_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_FLEXIO_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_EWM_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_LPI2C0_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
            
        )
    }

    ,
    {
        PCC_LPUART0_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
            
        )
    }

    ,
    {
        PCC_LPUART1_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_FLEXCAN1_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_LPUART2_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
            
        )
    }

    ,
    {
        PCC_CMP0_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_FTM3_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_ADC1_ADDR32,
        (
            PCC_CLOCK_ENABLED_U32
             | PCC_PCS_SOSC_U32
            
        )
    }

    ,
    {
        PCC_FLEXCAN2_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_UNAVAILABLE_U32
            
        )
    }

    ,
    {
        PCC_LPSPI0_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
            
        )
    }

    ,
    {
        PCC_LPSPI1_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
            
        )
    }

    ,
    {
        PCC_LPSPI2_ADDR32,
        (
            PCC_CLOCK_DISABLED_U32
             | PCC_PCS_EXT_CLK_OR_CLK_OFF_U32
            
        )
    }

};
#endif /* (MCU_INIT_CLOCK == STD_ON) */




#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PCC_ConfigType, MCU_CONST) PCC_ClockConfigPB0_0 =
{
    /* Number of PCC Registers */
    MCU_NUMBER_OF_PCC_REGISTERS_U32,
    /* Register Configuration */
    &PCC_aRegistersConfigPB0_0
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */




#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Initialization clock data.
* @details        Static configuration realized by calling Mcu_InitClock() API.
*
*/
static CONST( Mcu_ClockConfigType, MCU_CONST) Mcu_ClockConfigPB0[1] =  
{

    /* Start of Mcu_ClockConfig[0]. */
    {

        /* ID Clock Configuration. */
        (uint8)0U,

        /* SIM IP Clock settings. */
        &SIM_ClockConfigPB0_0,

        /* SCG IP Clock settings. */
        &SCG_ClockConfigPB0_0,
        
        /* PCC IP Clock settings. */
        &PCC_ClockConfigPB0_0,

#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
        /* CMU IP Clock settings. */
        &Mcu_CMU_ConfigPB0_0,
#endif
#endif
        (MCU_IPW_SOSC_UNDER_MCU_CONTROL |
         MCU_IPW_SIRC_UNDER_MCU_CONTROL |
         MCU_IPW_FIRC_UNDER_MCU_CONTROL |
         MCU_IPW_SPLL_UNDER_MCU_CONTROL)

    } /* end of Mcu_ClockConfig[0] */

};
#endif /* (MCU_INIT_CLOCK == STD_ON) */




/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST(Mcu_RCM_ConfigType, MCU_CONST) RCM_ResetConfigPB0 =
{
    /* Reset Pin Control register (RCM_RPC) */
    (
        RCM_RPC_STOP_ALL_FILTERING_DISABLE_U32 |
        RCM_RPC_NORMAL_ALL_FILTERING_DISABLE_U32 |
        RCM_RPC_RSTFLTSEL_U32((uint32)(0U))
    ),
    /* System Reset Interrupt Enable Register (RCM_SRIE) */
    (
        RCM_SRIE_SACKERR_INT_DIS_U32 |
        RCM_SRIE_MDM_AP_INT_DIS_U32 |
        RCM_SRIE_SSW_INT_DIS_U32 |
        RCM_SRIE_LOCKUP_INT_DIS_U32 |
        RCM_SRIE_JTAG_INT_DIS_U32 |
        RCM_SRIE_GIE_INT_EN_U32 |
        RCM_SRIE_PIN_INT_DIS_U32 |
        RCM_SRIE_WDOG_INT_EN_U32 |
        RCM_SRIE_CMU_INT_DIS_U32 |
        RCM_SRIE_LOL_INT_DIS_U32 |
        RCM_SRIE_LOC_INT_DIS_U32 |
        RCM_SRIE_DELAY_10_LPO_CYCLES_U32
    )
    
};




/**
* @brief          Initialization data for RCM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST(Mcu_SIM_ConfigType, MCU_CONST) SIM_ConfigPB0 =
{
    /* SIM ChipControlConfiguration */
    (
        SIM_CHIPCTL_ENABLE_ADC_SUPPLY_MON_U32 |
        SIM_CHIPCTL_ADC_SUPPLY_VDDA_U32 |        
        
        
        
        
        SIM_CHIPCTL_NO_INTERLEAVE_CHANNEL_U32
    ),
    /* SIM LPOClocks config */
    (
        SIM_RTCCLKSEL_LPO_CLK_32K_U32 |
        SIM_LPOCLKSEL_LPO_CLK_128K_U32 |
        SIM_ENABLE_32KHZ_LPO_CLK_U32 |
        SIM_ENABLE_1KHZ_LPO_CLK_U32
    ),
    /* SIM ADC Configuration */
    (        
        SIM_ADC1_PDB_PRE_TRIGGER_U32 |
        SIM_ADC1_SW_PRE_TRIGGER_DISABLE_U32 |
        SIM_ADC1_PDB_TRIGGER_SOURCE_U32 |
        SIM_ADC0_PDB_PRE_TRIGGER_U32 |
        SIM_ADC0_SW_PRE_TRIGGER_DISABLE_U32 |
        SIM_ADC0_PDB_TRIGGER_SOURCE_U32
    ),
    /* SIM FTMOPT0 Config */
    (
        SIM_FTM3CLKSEL_NO_CLOCK_U32 |
        SIM_FTM2CLKSEL_NO_CLOCK_U32 |
        SIM_FTM1CLKSEL_TCLK0_PIN_U32 |
        SIM_FTM0CLKSEL_NO_CLOCK_U32 |        SIM_FTM3_FLT0_PIN_FLT0_U32 |
        SIM_FTM3_FLT1_PIN_FLT1_U32 |
        SIM_FTM3_FLT2_PIN_FLT2_U32 |
        SIM_FTM2_FLT0_PIN_FLT0_U32 |
        SIM_FTM2_FLT1_PIN_FLT1_U32 |
        SIM_FTM2_FLT2_PIN_FLT2_U32 |
        SIM_FTM1_FLT0_PIN_FLT0_U32 |
        SIM_FTM1_FLT1_PIN_FLT1_U32 |
        SIM_FTM1_FLT2_PIN_FLT2_U32 |
        SIM_FTM0_FLT0_PIN_FLT0_U32 |
        SIM_FTM0_FLT1_PIN_FLT1_U32 |
        SIM_FTM0_FLT2_PIN_FLT2_U32
    ),
    /* SIM FTMOPT1 Config */
    (
        SIM_FTMOPT1_FTM3OUTSEL_U32
        (   (0x00U)
            
            
            
            
            
            
            
            
        ) |
        SIM_FTMOPT1_FTM0OUTSEL_U32
        (   (0x00U)
            
            
            
            
            
            
            
            
        ) |
        SIM_FTM_GLOBAL_LOAD_DISABLED_U32 |        
        
        SIM_FTMOPT1_FTM1SYNCBIT_MASK32 |
        SIM_FTMOPT1_FTM0SYNCBIT_MASK32 |
        SIM_FTM2CH1SEL_FTM2_CH1_U32 |
        SIM_FTM2CH0SEL_FTM2_CH0_INPUT_U32 |
        SIM_FTM1CH0SEL_FTM1_CH0_INPUT_U32
    ),
    /* SIM Miscellaneous Control configuration 0 */
    (
                SIM_FTM3_OUTPUT_SAFE_STATE_U32 |
        SIM_FTM2_OUTPUT_SAFE_STATE_U32 |
        SIM_FTM1_OUTPUT_SAFE_STATE_U32 |
        SIM_FTM0_OUTPUT_SAFE_STATE_U32 |
        SIM_FTM_GTB_SPLIT_EN_U32
    ),
    /* SIM Miscellaneous Control configuration 1 */
    (
        (0x0U)
    )
};




/**
* @brief          Initialization data for PMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_PMC_ConfigType, MCU_CONST) PMC_ConfigPB0 =
{
    /* Low Voltage Detect Status and Control 1 Register (PMC_LVDSC1) */
    (
        PMC_LVDSC1_LVD_DISABLE_U8 |
        PMC_LVDSC1_LVDRE_DISABLE_U8
    ),
    /* Low Voltage Detect Status and Control 2 Register (PMC_LVDSC2) */
    (
        PMC_LVDSC2_LVW_DISABLE_U8
    ),
    /* Regulator Status and Control Register (PMC_REGSC) */
    (
        PMC_REGSC_LPO_ENABLE_U8 |
        PMC_REGSC_CLKBIAS_ENABLE_U8 |
        PMC_REGSC_BIAS_DISABLE_U8
    ),
    /* Regulator Status and Control Register (PMC_LPOTRIM) */
    (
        PMC_LPOTRIM_LPOTRIM_U8((uint8)0U)
    )
};




/**
* @brief          Initialization data for SMC hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_SMC_ConfigType, MCU_CONST) SMC_ConfigPB0 =
{
    /* Allowed modes */
    (
        SMC_PMPROT_HSRUN_ALLOWED_U32 |
        SMC_PMPROT_VLP_NOT_ALLOWED_U32
    ),
};




/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_HwIPsConfigType, MCU_CONST) Mcu_HwIPsConfigPB0 =
{
    /* Configuration for RCM Reset. */
    &RCM_ResetConfigPB0,

    /* Configuration for PMC (Power Management Control) hardware IP. */
    &PMC_ConfigPB0,

    /* Configuration for SIM hardware IP. */
    &SIM_ConfigPB0,
    
    /* Configuration for SIM hardware IP. */
    &SMC_ConfigPB0
};




/**
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for configuration.
*
*/
/** @violates @ref Mcu_c_REF_7 MISRA 2004 Required Rule 8.10, external linkage ... */
CONST(Mcu_ConfigType, MCU_CONST) McuModuleConfiguration =
{
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &Mcu_Dem_Config,
#endif

    /* Number of RAM Sections configurations. */
    (Mcu_RamSectionType)1U,

    /* Number of Power Modes configurations. */
    (Mcu_ModeType)1U,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Number of Clock Setting configurations. */
    (Mcu_ClockType)1U,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
    /* Pointer to RAM Section configurations. */
    &Mcu_Ram_ConfigPB0,
#endif

    /* Pointer to Power Mode configurations. */
    &Mcu_Mode_ConfigPB0,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Pointer to Clock configurations. */
    &Mcu_ClockConfigPB0,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    /* Pointer to Low Level Mcu driver configuration. */
    &Mcu_HwIPsConfigPB0
};





#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

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

