/**
*   @file    Mcu_IPW.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Middle layer implementation.
*   @details Layer that implements the wrapper for routing data from/to external interface
*            to IP layer.
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
* @section Mcu_IPW_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_IPW_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_IPW_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_IPW_c_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Mcu_IPW_c_REF_5
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used.
* The comma is used  to abstract the trusted call function and to determine when the return into user mode is needed.
*
* @section Mcu_IPW_c_REF_6
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall
* not be implicitly converted to a different underlying type. Integer to pointer conversion, specific
* to the ISR entry / exit code .
*
* @section  Mcu_IPW_c_REF_7
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* preceding &, or with a paranthesised parameter list, which may be empy.
*
* @section  Mcu_IPW_c_REF_8
* Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the prototype
* shall be visible at both the function definition and call.
*
* @section  Mcu_IPW_c_REF_9
* Violates MISRA 2004 Required Rule 8.3, For each function parameter the type given in the declaration
* and defnition shall be identical, and the return types shall also be identical
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
/* Header file with prototype functions defines in this layer. */
#include "Mcu_IPW.h"
#include "Mcu_IPW_Irq.h"

/* Header files that are called from IPW layer. */
#include "Mcu_PCC.h"
#include "Mcu_PMC.h"
#include "Mcu_RCM.h"
#include "Mcu_SCG.h"
#include "Mcu_SIM.h"
#include "Mcu_SMC.h"
#include "Mcu_CMU.h"

#include "Reg_eSys_CMU.h"
#include "Reg_eSys_PCC.h"
#include "Reg_eSys_SCG.h"
#include "Mcu_CortexM4.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_VENDOR_ID_C                     43
/** @violates @ref Mcu_IPW_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Mcu_IPW_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Mcu_IPW_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define MCU_IPW_SW_MAJOR_VERSION_C              1
#define MCU_IPW_SW_MINOR_VERSION_C              0
#define MCU_IPW_SW_PATCH_VERSION_C              1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_IPW header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_IPW_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_IPW.h have different vendor ids"
#endif
/* Check if current file and Mcu_IPW header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_IPW.h are different"
#endif
/* Check if current file and Mcu_IPW header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_IPW_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_IPW_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_IPW.h are different"
#endif

/* Check if current file and Mcu_PCC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_PCC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_PCC.h have different vendor ids"
#endif
/* Check if current file and Mcu_PCC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_PCC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_PCC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_PCC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_PCC.h are different"
#endif
/* Check if current file and Mcu_PCC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_PCC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_PCC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_PCC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_PCC.h are different"
#endif

/* Check if current file and Mcu_PMC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_PMC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_PMC.h have different vendor ids"
#endif
/* Check if current file and Mcu_PMC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_PMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_PMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_PMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_PMC.h are different"
#endif
/* Check if current file and Mcu_PMC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_PMC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_PMC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_PMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_PMC.h are different"
#endif

/* Check if current file and Mcu_RCM header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_RCM_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_RCM.h have different vendor ids"
#endif
/* Check if current file and Mcu_RCM header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_RCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_RCM.h are different"
#endif
/* Check if current file and Mcu_RCM header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_RCM_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_RCM_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_RCM.h are different"
#endif

/* Check if current file and Mcu_SCG header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SCG_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SCG.h have different vendor ids"
#endif
/* Check if current file and Mcu_SCG header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SCG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SCG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SCG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SCG.h are different"
#endif
/* Check if current file and Mcu_SCG header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SCG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SCG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SCG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SCG.h are different"
#endif

/* Check if current file and Mcu_SIM header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SIM_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SIM.h have different vendor ids"
#endif
/* Check if current file and Mcu_SIM header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SIM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SIM.h are different"
#endif
/* Check if current file and Mcu_SIM header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SIM_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SIM_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SIM.h are different"
#endif

/* Check if current file and Mcu_SMC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SMC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SMC.h have different vendor ids"
#endif
/* Check if current file and Mcu_SMC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SMC.h are different"
#endif
/* Check if current file and Mcu_SMC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SMC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SMC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SMC.h are different"
#endif

/* Check if source file and Reg_eSys_SCG.h are from the same vendor */
#if (MCU_IPW_VENDOR_ID != REG_ESYS_SCG_VENDOR_ID)
    #error "Mcu_IPW.C and Reg_eSys_SCG.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SCG.h are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION != REG_ESYS_SCG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION != REG_ESYS_SCG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != REG_ESYS_SCG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Reg_eSys_SCG.h are different"
#endif
/*Check if source file and Reg_eSys_SCG.h are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != REG_ESYS_SCG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != REG_ESYS_SCG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != REG_ESYS_SCG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Reg_eSys_SCG.h are different"
#endif

/* Check if source file and Reg_eSys_CortexM4.h header file have same versions */
#if (MCU_CORTEXM4_VENDOR_ID != MCU_IPW_VENDOR_ID)
#error "Mcu_CortexM4.h and Mcu_IPW.c have different vendor IDs"
#endif
#if ((MCU_CORTEXM4_AR_RELEASE_MAJOR_VERSION != MCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_MINOR_VERSION != MCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CORTEXM4_AR_RELEASE_REVISION_VERSION != MCU_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Mcu_CortexM4.h and Mcu_IPW.c are different"
#endif
#if ((MCU_CORTEXM4_SW_MAJOR_VERSION != MCU_IPW_SW_MAJOR_VERSION) || \
     (MCU_CORTEXM4_SW_MINOR_VERSION != MCU_IPW_SW_MINOR_VERSION) || \
     (MCU_CORTEXM4_SW_PATCH_VERSION != MCU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Mcu_CortexM4.h and Mcu_IPW.c are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
/* Mcu clock configuration structure used at a moment by the MCU driver.
   When the Mcu_InitClock() API is called this pointer will be different from NULL_PTR - used as a
    check trigger by Mcu_DistributePllClock() API.
*/
#if (MCU_INIT_CLOCK == STD_ON)
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/** @violates @ref Mcu_IPW_c_REF_4 MISRA 2004 Required Rule 8.7, these object are used trough the entire MCU code*/
static P2CONST( Mcu_ClockConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pClockConfig = NULL_PTR;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
static FUNC( void, MCU_CODE) Mcu_Ipw_DisableFircClock(VAR( void, AUTOMATIC));
static FUNC( void, MCU_CODE) Mcu_Ipw_DisableSoscClock(VAR( void, AUTOMATIC));
#endif


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
/**
* @brief            This function will disable Firc clock
*/

static FUNC( void, MCU_CODE) Mcu_Ipw_DisableFircClock(VAR( void, AUTOMATIC))
{
    VAR (uint32, AUTOMATIC) u32SystemResetIsrConfig;
    
    /* Configurable SIRC as system clock */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_SCG_DropSysClkToSircInRunMode();

    /* get the current System Reset Interrupt Enable settings */
    u32SystemResetIsrConfig = Mcu_RCM_GetCurrentSystemResetIsrSettings();

    /* Configure all reset sources to be 'Reset' */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_RCM_SystemResetIsrConfig();

    /* Disable Firc Clock */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_SCG_DisableFircClock();
    
    /* Restore System Reset Interrupt Config */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_RCM_RestoreSystemResetIsrConfig(u32SystemResetIsrConfig);
}

/**
* @brief            This function will disable SOSC clock
*/

static FUNC( void, MCU_CODE) Mcu_Ipw_DisableSoscClock(VAR( void, AUTOMATIC))
{
    VAR (uint32, AUTOMATIC) u32SystemResetIsrConfig;
    
    /* Configurable SIRC as system clock */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_SCG_DropSysClkToSircInRunMode();

    /* get the current System Reset Interrupt Enable settings */
    u32SystemResetIsrConfig = Mcu_RCM_GetCurrentSystemResetIsrSettings();

    /* Configure all reset sources to be 'Reset' */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_RCM_SystemResetIsrConfig();

    /* Disable SOSC Clock */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_SCG_DisableSoscClock();
    
    /* Restore System Reset Interrupt Config */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    Call_Mcu_RCM_RestoreSystemResetIsrConfig(u32SystemResetIsrConfig);
}
#endif


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function initializes the MCU module.
* @details          The function initializes the SIM, RCM, PMC, SMC modules.
*                   Called by:
*                       - Mcu_Init() from HLD.
*
* @param[in]        Mcu_pHwIPsConfigPtr   Pointer to IPW configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_Init(P2CONST( Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr)
{
    /* Init SIM settings. */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_8 MISRA 2004 Rule 8.1, Functions shall have prototype */
    Call_Mcu_SIM_Init( Mcu_pHwIPsConfigPtr->SIM_pConfig );
    
    /* Init the RCM module */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    Call_Mcu_RCM_ResetInit(Mcu_pHwIPsConfigPtr->RCM_pResetConfig);

    /* Configure the Power Management Unit. */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    Call_Mcu_PMC_PowerInit( Mcu_pHwIPsConfigPtr->PMC_pConfig);
    
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    Call_Mcu_SMC_AllowedModesConfig(Mcu_pHwIPsConfigPtr->SMC_pConfig);
}


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes the clock structure.
* @details          This function intializes the clock structure by configuring the SIM, SCG, PCC modules.
*                   Called by:
*                       - Mcu_InitClock() from HLD.
*
* @param[in]        Mcu_pClockConfigPtr   Pointer to clock configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_InitClock(P2CONST( Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr)
{
    /* Save configs to global variable for other usage */
    Mcu_pClockConfig = Mcu_pClockConfigPtr;
    
#if (IPV_CMU == IPV_CMU_00_00_00_01)
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
    /* Disable CMU0. */
    if(Mcu_PCC_GetStatus(PCC_CMU0_ADDR32) & PCC_CMU0_RWBITS_MASK32)
    {
        Mcu_CMU_Disable_CMU(CMU0_CHANNEL);
    }
    
    /* Disable CMU1. */
    if(Mcu_PCC_GetStatus(PCC_CMU1_ADDR32) & PCC_CMU1_RWBITS_MASK32)
    {
        Mcu_CMU_Disable_CMU(CMU1_CHANNEL);
    }
#endif
#endif
#endif

    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    Call_Mcu_SIM_ClockConfig(Mcu_pClockConfig->SIM_pClockConfig);

    /* Configure SIRC and then select it as system clock by default. This is needed to apply new configuration for Pll
       in case of the Pll selected as system clock previously. This is possible only when sys clock is under Mcu control.
    */
    if(SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL != Mcu_pClockConfigPtr->SCG_pClockConfig->u32RunClockControlConfiguration)
    {
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        /**  @violates @ref Mcu_IPW_c_REF_8 MISRA 2004 Rule 8.1, Functions shall have prototype */
        Call_Mcu_SCG_DropSystemClockToSirc();
    }
    
    /*After that, configure all parameters here */
    /* Configure FIRC */
    if (MCU_IPW_SIRC_UNDER_MCU_CONTROL == (Mcu_pClockConfig->u8ClockSourcesControl & MCU_IPW_SIRC_UNDER_MCU_CONTROL))
    {
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
        Call_Mcu_SCG_SircInit(Mcu_pClockConfig->SCG_pClockConfig);        
    }   
    
    /* Re-Configure FIRC by user configuration */
    if (MCU_IPW_FIRC_UNDER_MCU_CONTROL == (Mcu_pClockConfig->u8ClockSourcesControl & MCU_IPW_FIRC_UNDER_MCU_CONTROL))
    {
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
        Call_Mcu_SCG_FircInit(Mcu_pClockConfig->SCG_pClockConfig);
    }
    /* Configure SOSC */
    if (MCU_IPW_SOSC_UNDER_MCU_CONTROL == (Mcu_pClockConfig->u8ClockSourcesControl & MCU_IPW_SOSC_UNDER_MCU_CONTROL))
    {
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
        Call_Mcu_SCG_SoscInit(Mcu_pClockConfig->SCG_pClockConfig);
    }    
    
#if (MCU_NO_PLL == STD_OFF)
    /* Configure SPLL */
    if (MCU_IPW_SPLL_UNDER_MCU_CONTROL == (Mcu_pClockConfig->u8ClockSourcesControl & MCU_IPW_SPLL_UNDER_MCU_CONTROL))
    {
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
        Call_Mcu_SCG_SpllInit(Mcu_pClockConfig->SCG_pClockConfig);
    }
#endif  /* MCU_NO_PLL */
    
    /* Configure System Clock */
    if(SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL != Mcu_pClockConfigPtr->SCG_pClockConfig->u32RunClockControlConfiguration)
    {
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
        Call_Mcu_SCG_SystemClockInit(Mcu_pClockConfigPtr->SCG_pClockConfig);
    }
    
    /* set up the clock distribution tree */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    Call_Mcu_PCC_PeripheralConfig( Mcu_pClockConfigPtr->PCC_pConfig ) ;
    
#if (IPV_CMU == IPV_CMU_00_00_00_01)
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
    
    if (
         (MCU_IPW_FIRC_UNDER_MCU_CONTROL == (Mcu_pClockConfig->u8ClockSourcesControl & MCU_IPW_FIRC_UNDER_MCU_CONTROL)) &&
         (((*(Mcu_pClockConfig->SCG_pClockConfig)->apFircClockConfig)[SCG_FIRCCSR_CONFIG_REG].u32RegisterData & SCG_FIRCCSR_FIRCEN_MASK32) == SCG_FIRCCSR_FIRCEN_MASK32)
        )
    {
        /* Configure CMU */
        Mcu_CMU_Init( Mcu_pClockConfigPtr->CMU_pConfig);
    }

#endif
#endif
#endif
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
* @brief              This function activates the main PLL as the system clock source.
* @details            This function sets the PLL as the system clock and also enables monitoring.
*                     Called by:
*                       - Mcu_DistributePllClock() from HLD.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_DistributePllClock( VAR( void, AUTOMATIC) )
{

    if ( NULL_PTR != Mcu_pClockConfig)
    {
        /* if system clock tree is under MCU control */
        if(SCG_SYS_CLK_NOT_UNDER_MCU_CONTROL != Mcu_pClockConfig->SCG_pClockConfig->u32RunClockControlConfiguration)
        {
            /* Select Pll as system clock */
            /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
            /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
            /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
            Call_Mcu_SCG_SystemClockInit(Mcu_pClockConfig->SCG_pClockConfig);
        }
    }
}
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function returns the lock status of the PLL.
* @details          The user takes care that the PLL is locked by executing Mcu_GetPllStatus.
*                   If the MCU_NO_PLL is TRUE the MCU_GetPllStatus has to return
*                   MCU_PLL_STATUS_UNDEFINED.
*                   Called by:
*                       - Mcu_GetPllStatus() from HLD.
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED   PLL Status is unknown.
* @retval           MCU_PLL_LOCKED   PLL is locked.
* @retval           MCU_PLL_UNLOCKED    PLL is unlocked.
*
*/
FUNC( Mcu_PllStatusType, MCU_CODE) Mcu_Ipw_GetPllStatus( VAR( void, AUTOMATIC))
{
    /* Pll status variable. */
    VAR( Mcu_PllStatusType, AUTOMATIC)   ePllStatus = MCU_PLL_STATUS_UNDEFINED;
    VAR( Mcu_SCG_PllStatusType, AUTOMATIC) eSpllStatus ;

    /* get the status from each peripheral */
    eSpllStatus = Mcu_SCG_GetPLLStatus();

    /* if a pll is unlocked return MCU_PLL_UNLOCKED */
    if ( MCU_SPLL_LOCKED == eSpllStatus )
    {
        ePllStatus = MCU_PLL_LOCKED ;
    }
    else
    {
        ePllStatus = MCU_PLL_UNLOCKED ;
    }

    /* Return the PLL status. */
    return (Mcu_PllStatusType)ePllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */

/**
* @brief            This function initializes the mode structure.
* @details          This function intializes the mode structure by configuring the SMC module.
*                   Called by:
*                       - Mcu_SetMode() from HLD.
*
* @param[in]        Mcu_pModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_SetMode(P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr)
{
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    if ((MCU_VLPS_MODE == Mcu_pModeConfigPtr->u32PowerMode) || (MCU_VLPR_MODE == Mcu_pModeConfigPtr->u32PowerMode))
    {
        /*
        * All clock monitors are always disabled when chip in a low power mode.
        * However, to prevent unexpected loss of clock reset events, we should
        * disable them before entering any low power modes, including VLPR and VLPS. */        
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
        Call_Mcu_SCG_DisableClockMonitors();

#if (IPV_CMU == IPV_CMU_00_00_00_01)
#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
        /* Disable CMU before Disable FIRC. */
       /*  Mcu_CMU_DeInit(); */
        if(Mcu_PCC_GetStatus(PCC_CMU0_ADDR32) & PCC_CMU0_RWBITS_MASK32)
        {
            Mcu_CMU_Disable_CMU(CMU0_CHANNEL);
        }
        
        if(Mcu_PCC_GetStatus(PCC_CMU1_ADDR32) & PCC_CMU1_RWBITS_MASK32)
        {
            Mcu_CMU_Disable_CMU(CMU1_CHANNEL);
        }
#endif
#endif
#endif

        /* Disable FIRC in RUN mode before initiating a mode transition request to any low power mode. */
        Mcu_Ipw_DisableFircClock();

        /* Disable SOSC in RUN mode before initiating a mode transition request to any low power mode. */
        Mcu_Ipw_DisableSoscClock();

        if (MCU_VLPS_MODE == Mcu_pModeConfigPtr->u32PowerMode)
        {
            /*This enable chip go into deep sleep mode by setting bit SLEEPDEEP */
            /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
            Call_Mcu_CM4_EnableDeepSleep();
        
#if (MCU_NO_PLL == STD_OFF)
            /* When entering VLPS mode, the PLL must be disabled before making any mode transition. */
            /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
            Call_Mcu_SCG_DisableSpllClock();
#endif /* (MCU_NO_PLL == STD_OFF) */
        }
    }

    if ((MCU_STOP1_MODE == Mcu_pModeConfigPtr->u32PowerMode) || (MCU_STOP2_MODE == Mcu_pModeConfigPtr->u32PowerMode))
    {
        /*This enable chip go into deep sleep mode by setting bit SLEEPDEEP */
        /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
        Call_Mcu_CM4_EnableDeepSleep();
    }
#endif

    /* Request new mode transition to MC_ME. */
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    Call_Mcu_SMC_ModeConfig( Mcu_pModeConfigPtr);
}


#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_Ipw_DisableCmu(VAR (uint8, AUTOMATIC) u8IndexCmu)
{
    Mcu_CMU_Disable_CMU(u8IndexCmu);
}
#endif
#endif


#if (MCU_PERFORM_RESET_API == STD_ON)
/**
* @brief            This function performs a microcontroller reset.
* @details          This function performs a microcontroller reset by using the hardware feature of
*                   the microcontroller.
*                   Called by:
*                       - Mcu_PerformReset() from HLD.
*
* @param[in]        Mcu_pHwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_PerformReset(P2CONST( Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr)
{
    /* Performs a micro controller reset. */
    MCU_PARAM_UNUSED(Mcu_pHwIPsConfigPtr);
    /** @violates @ref Mcu_IPW_c_REF_5 The comma operator shall not be used. */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    Call_Mcu_CM4_SystemReset();
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */



/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_GetResetReason() from HLD.
*
* @param[in]        None
*
* @return           void
*
*/
FUNC( Mcu_ResetType, MCU_CODE) Mcu_Ipw_GetResetReason( VAR( void, AUTOMATIC))
{
    VAR( Mcu_ResetType, AUTOMATIC)   eResetReason = MCU_RESET_UNDEFINED;

    /** @violates @ref Mcu_IPW_c_REF_6 MISRA 2004 Required Rule 10.1, Conversion from integer to pointer */
    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_8 MISRA 2004 Rule 8.1, Functions shall have prototype */
    eResetReason = (Mcu_ResetType)Call_Mcu_RCM_GetResetReason();
    return (Mcu_ResetType) eResetReason;
}


/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_GetResetReason() from HLD.
*
* @param[in]        None
*
* @return           void
*
*/
FUNC( Mcu_RawResetType, MCU_CODE) Mcu_Ipw_GetResetRawValue( VAR( void, AUTOMATIC))
{
    VAR( Mcu_RawResetType, AUTOMATIC) ResetReason;

    /**  @violates @ref Mcu_IPW_c_REF_7 MISRA 2004 Rule 16.9, function identifier */
    /**  @violates @ref Mcu_IPW_c_REF_9 MISRA 2004 Rule 8.3, For each function parameter */
    ResetReason = (Mcu_RawResetType)Call_Mcu_RCM_GetResetRawValue();
    return (Mcu_RawResetType) ResetReason;
}

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

