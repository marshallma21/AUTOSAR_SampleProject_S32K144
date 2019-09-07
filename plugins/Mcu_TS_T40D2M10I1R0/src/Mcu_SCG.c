/**
*   @file    Mcu_SCG.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - System Clock Generator functions implementation.
*   @details Specific functions for SCG configuration and control.
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
* @section Mcu_SCG_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_SCG_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_SCG_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_SCG_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_SCG_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section Mcu_SCG_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
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
#include "Mcu_SCG.h"
#include "Reg_eSys_SCG.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif

#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#endif

#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_SCG_VENDOR_ID_C                      43
/** @violates @ref Mcu_SCG_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SCG_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_SCG_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SCG_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_SCG_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SCG_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_SCG_SW_MAJOR_VERSION_C               1
#define MCU_SCG_SW_MINOR_VERSION_C               0
#define MCU_SCG_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_SCG header file are of the same vendor */
#if (MCU_SCG_VENDOR_ID_C != MCU_SCG_VENDOR_ID)
    #error "Mcu_SCG.c and Mcu_SCG.h have different vendor ids"
#endif
/* Check if current file and Mcu_SCG header file are of the same Autosar version */
#if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION_C    != MCU_SCG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_MINOR_VERSION_C    != MCU_SCG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_REVISION_VERSION_C != MCU_SCG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SCG.c and Mcu_SCG.h are different"
#endif
/* Check if current file and Mcu_SCG header file are of the same Software version */
#if ((MCU_SCG_SW_MAJOR_VERSION_C != MCU_SCG_SW_MAJOR_VERSION) || \
     (MCU_SCG_SW_MINOR_VERSION_C != MCU_SCG_SW_MINOR_VERSION) || \
     (MCU_SCG_SW_PATCH_VERSION_C != MCU_SCG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SCG.c and Mcu_SCG.h are different"
#endif

/* Check if source file and Reg_eSys_SCG.h are from the same vendor */
#if (MCU_SCG_VENDOR_ID_C != REG_ESYS_SCG_VENDOR_ID)
    #error "Mcu_SCG.C and Reg_eSys_SCG.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SCG.h are of the same Autosar version */
#if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SCG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SCG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SCG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SCG.c and Reg_eSys_SCG.h are different"
#endif
/*Check if source file and Reg_eSys_SCG.h are of the same Software version */
#if ((MCU_SCG_SW_MAJOR_VERSION_C != REG_ESYS_SCG_SW_MAJOR_VERSION) || \
     (MCU_SCG_SW_MINOR_VERSION_C != REG_ESYS_SCG_SW_MINOR_VERSION) || \
     (MCU_SCG_SW_PATCH_VERSION_C != REG_ESYS_SCG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SCG.c and Reg_eSys_SCG.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SCG_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SCG.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SCG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SCG.c and Dem.h are different"
#endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SCG_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SCG_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SCG.c and SilRegMacros.h are different"
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
* @violates @ref Mcu_SCG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_INIT_CLOCK == STD_ON)

/**
* @brief            This function will configure the system clock for all modes
*/
FUNC( void, MCU_CODE) Mcu_SCG_SystemClockInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_RCCR_ADDR32, pConfigPtr->u32RunClockControlConfiguration);
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_VCCR_ADDR32, pConfigPtr->u32VLPRClockControlConfiguration);
#ifdef MCU_HSRUN_MODE_NOT_SUPPORT
#if (MCU_HSRUN_MODE_NOT_SUPPORT == STD_ON)
    /* do nothing */
#else
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_HCCR_ADDR32, pConfigPtr->u32HSRUNClockControlConfiguration);
#endif
#else
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_HCCR_ADDR32, pConfigPtr->u32HSRUNClockControlConfiguration);
#endif
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_CLKOUTCNFG_ADDR32, pConfigPtr->u32ClockOutConfiguration);
}
/**
* @brief            This function will select SIRC as system clock
*/
FUNC( void, MCU_CODE) Mcu_SCG_DropSystemClockToSirc(VAR( void, AUTOMATIC))
{
    VAR(uint32, AUTOMATIC) u32TimeOut = 0U;
    VAR(uint32, AUTOMATIC) u32RegValue = 0U;
    
    /* Disable SIRC so the rest of the register can be configured. */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_SIRCCSR_ADDR32, SCG_SIRCCSR_SIRCEN_MASK32);
    
    /* write some default values for SIRC registers */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_SIRCCSR_ADDR32,SCG_SIRCCSR_LK_UNLOCK_U32);
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_SIRCCFG_ADDR32,SCG_SIRCCFG_HIGH_RANGE_CLOCK_U32);
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SCG_SIRCDIV_ADDR32,SCG_SIRCDIV_SIRCDIV2_U32(1U) |  SCG_SIRCDIV_SIRCDIV1_U32(1U));
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_SET32(SCG_SIRCCSR_ADDR32, SCG_SIRCCSR_SIRCEN_MASK32);
    /*Wait for Valid bit done */
    u32TimeOut = MCU_TIMEOUT_LOOPS;
    do
    {
        u32TimeOut--;
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        u32RegValue = REG_READ32(SCG_SIRCCSR_ADDR32) & SCG_SIRCCSR_SIRCVLD_MASK32;
    }
    while ((SCG_SIRCCSR_SIRCVLD_MASK32 != u32RegValue) && ((uint32)0x00U < u32TimeOut));
    
    if ( (uint32)0x0U == u32TimeOut)
    {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
    /* Set SIRC as system clock */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_RCCR_ADDR32, SCG_RCCR_SCS_MASK32, SCG_SCS_SIRC_U32);
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_VCCR_ADDR32, SCG_VCCR_SCS_MASK32, SCG_SCS_SIRC_U32);
#ifdef MCU_HSRUN_MODE_NOT_SUPPORT
#if (MCU_HSRUN_MODE_NOT_SUPPORT == STD_ON)
    /* do nothing */
#else
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_HCCR_ADDR32, SCG_HCCR_SCS_MASK32, SCG_SCS_SIRC_U32);
#endif
#else
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_HCCR_ADDR32, SCG_HCCR_SCS_MASK32, SCG_SCS_SIRC_U32);
#endif
}

/**
* @brief            This function will configure the System OSC
*
* @details          This function will configure the SOSC control, divider and trim registers
*
*/
FUNC( void, MCU_CODE) Mcu_SCG_SoscInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter = 0U;
    VAR(uint32, AUTOMATIC) u32TimeOut = 0U;
    VAR(uint32, AUTOMATIC) u32RegValue = 0U;
    
    /* Disable SOSC so the rest of the register can be configured. */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_SOSCCSR_ADDR32, SCG_SOSCCSR_SOSCEN_MASK32);

    /* The last register configured is SOSCCSR so the SOSC will be enabled or disabled, depending on the user configuration. */
    for ( u32Counter = (uint32)0x00U; u32Counter < MCU_NUMBER_OF_SOSC_REGISTERS_U32; u32Counter++)
    {
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        REG_WRITE32((*pConfigPtr->apSoscClockConfig)[u32Counter].u32RegisterAddr, (*pConfigPtr->apSoscClockConfig)[u32Counter].u32RegisterData);
    }
    
    /*Wait for Valid bit done */
    u32TimeOut = MCU_TIMEOUT_LOOPS;
    do
    {
        u32TimeOut--;
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        u32RegValue = REG_READ32(SCG_SOSCCSR_ADDR32) & SCG_SOSCCSR_SOSCVLD_MASK32;
    }
    while ((SCG_SOSCCSR_SOSCVLD_MASK32 != u32RegValue) && ((uint32)0x00U < u32TimeOut));
    
    if ( (uint32)0x0U == u32TimeOut)
    {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
}

/**
* @brief            This function will configure the Slow IRC
*
* @details          This function will configure the SIRC control, divider and trim registers
*
*/
FUNC( void, MCU_CODE) Mcu_SCG_SircInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;
    VAR(uint32, AUTOMATIC) u32TimeOut = 0U;
    VAR(uint32, AUTOMATIC) u32RegValue = 0U;
    
    /* Disable SIRC so the rest of the register can be configured. */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_SIRCCSR_ADDR32, SCG_SIRCCSR_SIRCEN_MASK32);

    /* The last register configured is SIRCCSR so the SIRC will be enabled or disabled, depending on the user configuration. */
    for ( u32Counter = (uint32)0x00U; u32Counter < MCU_NUMBER_OF_SIRC_REGISTERS_U32; u32Counter++)
    {
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        REG_WRITE32((*pConfigPtr->apSircClockConfig)[u32Counter].u32RegisterAddr, (*pConfigPtr->apSircClockConfig)[u32Counter].u32RegisterData);
    }
    /*Wait for Valid bit done */
    u32TimeOut = MCU_TIMEOUT_LOOPS;
    do
    {
        u32TimeOut--;
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        u32RegValue = REG_READ32(SCG_SIRCCSR_ADDR32) & SCG_SIRCCSR_SIRCVLD_MASK32;
    }
    while ((SCG_SIRCCSR_SIRCVLD_MASK32 != u32RegValue) && ((uint32)0x00U < u32TimeOut));
    
    if ( (uint32)0x0U == u32TimeOut)
    {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
}

/**
* @brief            This function will configure the Fast IRC
*
* @details          This function will configure the FIRC control, divider and trim registers
*
*/
FUNC( void, MCU_CODE) Mcu_SCG_FircInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;
    VAR(uint32, AUTOMATIC) u32TimeOut = MCU_TIMEOUT_LOOPS;
    VAR(uint32, AUTOMATIC) u32RegValue = 0U;
    
    /* Disable FIRC so the rest of the register can be configured. */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_FIRCCSR_ADDR32, SCG_FIRCCSR_FIRCEN_MASK32);

    /* The last register configured is FIRCCSR so the FIRC will be enabled or disabled, depending on the user configuration. */
    for ( u32Counter = (uint32)0x00U; u32Counter < MCU_NUMBER_OF_FIRC_REGISTERS_U32; u32Counter++)
    {
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        REG_WRITE32((*pConfigPtr->apFircClockConfig)[u32Counter].u32RegisterAddr, (*pConfigPtr->apFircClockConfig)[u32Counter].u32RegisterData);
    }
    
    /* Check whether the mode FIRC is enable or not. */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    if((REG_READ32(SCG_FIRCCSR_ADDR32) & SCG_FIRCCSR_FIRCEN_MASK32) == SCG_FIRCCSR_FIRCEN_MASK32)
    {
        /* wait for valid bit done. */
        do
        {
            u32TimeOut--;
            /** @violates @ref Mcu_SCG_c_REF_4 Conversion from int to pointer */
            /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
            u32RegValue = REG_READ32(SCG_FIRCCSR_ADDR32) & SCG_FIRCCSR_FIRCVLD_MASK32; 
        }
        while ((SCG_FIRCCSR_FIRCVLD_MASK32 != u32RegValue) && ((uint32)0x00U < u32TimeOut));
    }
    
    if ( (uint32)0x0U == u32TimeOut)
    {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
}

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function will configure the System PLL
*
* @details          This function will configure the SPLL control, divider and configuration registers
*
*/
FUNC( void, MCU_CODE) Mcu_SCG_SpllInit(P2CONST(Mcu_SCG_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;

    /* Disable SPLL so the rest of the register can be configured. */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_SPLLCSR_ADDR32, SCG_SPLLCSR_SPLLEN_MASK32);

    /* The last register configured is SCG_SPLLCSR so the SPLL will be enabled or disabled, depending on the user configuration. */
    for ( u32Counter = (uint32)0x00U; u32Counter < MCU_NUMBER_OF_SPLL_REGISTERS_U32; u32Counter++)
    {
        /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
        REG_WRITE32((*pConfigPtr->apSpllClockConfig)[u32Counter].u32RegisterAddr, (*pConfigPtr->apSpllClockConfig)[u32Counter].u32RegisterData);
    }
}
#endif  /* MCU_NO_PLL */

#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function gets the status of the PLL
*
* @details          This function will return the PLL status
*
*/
FUNC( Mcu_SCG_PllStatusType, MCU_CODE) Mcu_SCG_GetPLLStatus(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SCG_PllStatusType, AUTOMATIC) ePllStatus = (Mcu_SCG_PllStatusType)MCU_SPLL_STATUS_UNDEFINED;
    VAR(uint32, AUTOMATIC) u32PllStatus;

    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    u32PllStatus = REG_READ32( SCG_SPLLCSR_ADDR32 ) & SCG_SPLLCSR_SPLLVLD_MASK32;
    /* The last register configured is SCG_SPLLCSR so the SPLL will be enabled or disabled, depending on the user configuration. */
    if ( SCG_SPLLCSR_SPLLVLD_MASK32 == u32PllStatus)
    {
        ePllStatus = MCU_SPLL_LOCKED;
    }
    else
    {
        ePllStatus = MCU_SPLL_UNLOCKED;
    }
    
    return ePllStatus;
}
#endif

/**
* @brief            This function will disable all clock monitors
* @violates @ref Mcu_SCG_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( void, MCU_CODE) Mcu_SCG_DisableClockMonitors(VAR( void, AUTOMATIC))
{
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_SOSCCSR_ADDR32,SCG_SOSCCSR_SOSCCM_MASK32,SCG_SOSCCSR_SOSCCM_DIS_U32);
#if (MCU_NO_PLL == STD_OFF)
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_SPLLCSR_ADDR32,SCG_SPLLCSR_SPLLCM_MASK32,SCG_SPLLCSR_SPLLCM_DIS_U32);    
#endif  /* MCU_NO_PLL */
}

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function will disable PLL clock
* @violates @ref Mcu_SCG_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( void, MCU_CODE) Mcu_SCG_DisableSpllClock(VAR( void, AUTOMATIC))
{
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_SPLLCSR_ADDR32,SCG_SPLLCSR_SPLLEN_MASK32,SCG_SPLLCSR_SPLL_DISABLE_U32);    
}
#endif  /* MCU_NO_PLL */

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
/**
* @brief            This function will configurable SIRC as system clock.
*/
FUNC( void, MCU_CODE) Mcu_SCG_DropSysClkToSircInRunMode(VAR( void, AUTOMATIC))
{
    /* Set SIRC as system clock in Run mode */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(SCG_RCCR_ADDR32, SCG_RCCR_SCS_MASK32, SCG_SCS_SIRC_U32);
}

/**
* @brief            This function will disable FIRC clock.
*/
FUNC( void, MCU_CODE) Mcu_SCG_DisableFircClock(VAR( void, AUTOMATIC))
{
    /* Disable FIRC clock */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_FIRCCSR_ADDR32, SCG_FIRCCSR_FIRCEN_MASK32);
}

/**
* @brief            This function will disable SOSC clock.
*/
FUNC( void, MCU_CODE) Mcu_SCG_DisableSoscClock(VAR( void, AUTOMATIC))
{
    /* Disable SOSC clock */
    /** @violates @ref Mcu_SCG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SCG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(SCG_SOSCCSR_ADDR32, SCG_SOSCCSR_SOSCEN_MASK32);
}
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SCG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SCG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
