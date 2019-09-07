/**
*   @file    Mcu_SMC.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - System Mode Controller functions implementation.
*   @details Specific functions for SMC configuration and control.
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
* @section Mcu_SMC_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_SMC_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_SMC_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_SMC_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_SMC_c_REF_5
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
#include "Mcu_SMC.h"

#include "Reg_eSys_SMC.h"

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
#define MCU_SMC_VENDOR_ID_C                      43
/** @violates @ref Mcu_SMC_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SMC_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_SMC_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SMC_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_SMC_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SMC_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_SMC_SW_MAJOR_VERSION_C               1
#define MCU_SMC_SW_MINOR_VERSION_C               0
#define MCU_SMC_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_SMC header file are of the same vendor */
#if (MCU_SMC_VENDOR_ID_C != MCU_SMC_VENDOR_ID)
    #error "Mcu_SMC.c and Mcu_SMC.h have different vendor ids"
#endif
/* Check if current file and Mcu_SMC header file are of the same Autosar version */
#if ((MCU_SMC_AR_RELEASE_MAJOR_VERSION_C    != MCU_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SMC_AR_RELEASE_MINOR_VERSION_C    != MCU_SMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SMC_AR_RELEASE_REVISION_VERSION_C != MCU_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SMC.c and Mcu_SMC.h are different"
#endif
/* Check if current file and Mcu_SMC header file are of the same Software version */
#if ((MCU_SMC_SW_MAJOR_VERSION_C != MCU_SMC_SW_MAJOR_VERSION) || \
     (MCU_SMC_SW_MINOR_VERSION_C != MCU_SMC_SW_MINOR_VERSION) || \
     (MCU_SMC_SW_PATCH_VERSION_C != MCU_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SMC.c and Mcu_SMC.h are different"
#endif

/* Check if source file and Reg_eSys_SMC.h are from the same vendor */
#if (MCU_SMC_VENDOR_ID_C != REG_ESYS_SMC_VENDOR_ID)
    #error "Mcu_SMC.C and Reg_eSys_SMC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_SMC.h are of the same Autosar version */
#if ((MCU_SMC_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SMC_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_SMC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SMC_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SMC.c and Reg_eSys_SMC.h are different"
#endif
/*Check if source file and Reg_eSys_SMC.h are of the same Software version */
#if ((MCU_SMC_SW_MAJOR_VERSION_C != REG_ESYS_SMC_SW_MAJOR_VERSION) || \
     (MCU_SMC_SW_MINOR_VERSION_C != REG_ESYS_SMC_SW_MINOR_VERSION) || \
     (MCU_SMC_SW_PATCH_VERSION_C != REG_ESYS_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SMC.c and Reg_eSys_SMC.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SMC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SMC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SMC.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SMC_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SMC_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SMC.c and SilRegMacros.h are different"
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
* @violates @ref Mcu_SMC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function will configure the allowed modes
*
* @details          This function is only called at Mcu initialization
*
*/
FUNC( void, MCU_CODE) Mcu_SMC_AllowedModesConfig(P2CONST(Mcu_SMC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /** @violates @ref Mcu_SMC_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SMC_PMPROT_ADDR32, (pConfigPtr->u32AllowedModes & SMC_PMPROT_RWBITS_MASK32));
}


/**
* @brief            This function switches the mode by writing SMC_PMCTRL and SMC_STOPCTRL.
* @details          This function configures the mode settings by writing the 
*                   SMC_PMCTRL and SMC_STOPCTRL registers.
*
*                   Called by:
*                       - Mcu_IPW_SetMode() from IPW.
*
* @param[in]        pModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_SMC_ModeConfig(P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) pModeConfigPtr)
{
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode = MCU_RUN_MODE;
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( uint32, AUTOMATIC) eCurrentPowerMode = SMC_PMSTAT_RUN_U32;
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)  
    /* Contains value of latest written register before executing WFI instruction */
    VAR( uint32, AUTOMATIC) u32RegValue = (uint32)0U;
#endif
    
    /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
    eCurrentPowerMode = REG_READ32(SMC_PMSTAT_ADDR32) & SMC_PMSTAT_PMSTAT_MASK32;
    
    ePowerMode = pModeConfigPtr->u32PowerMode;
    
    switch (ePowerMode)
    {
        case (MCU_RUN_MODE):
        {
            /* Set RUN mode */
            /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
            REG_RMW32(SMC_PMCTRL_ADDR32, SMC_PMCTRL_RUNM_MASK32, SMC_PMCTRL_RUN_MODE_U32);

            break;
        }
        case (MCU_HSRUN_MODE):
        {
            if (SMC_PMSTAT_RUN_U32 == eCurrentPowerMode)
            {
                /* Set HSRUN mode. */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_RMW32(SMC_PMCTRL_ADDR32, SMC_PMCTRL_RUNM_MASK32, SMC_PMCTRL_HSRUN_MODE_U32);
            }
            
            break;
        }      
        case (MCU_VLPR_MODE):
        {
            if ((SMC_PMSTAT_RUN_U32 == eCurrentPowerMode) || (SMC_PMSTAT_VLPS_U32 == eCurrentPowerMode))
            {
                /* Set VLPR mode. */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_RMW32(SMC_PMCTRL_ADDR32, SMC_PMCTRL_RUNM_MASK32, SMC_PMCTRL_VLPR_MODE_U32);
            }
            
            break;
        }

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)  
        case (MCU_VLPS_MODE):
        {
            if ((SMC_PMSTAT_RUN_U32 == eCurrentPowerMode) || (SMC_PMSTAT_VLPR_U32 == eCurrentPowerMode))
            {
                /* Set VLPS mode. */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_RMW32(SMC_PMCTRL_ADDR32, SMC_PMCTRL_STOPM_MASK32, SMC_PMCTRL_VLPS_U32);
                /* This read ensure transistion mode successful before executing WFI instruction */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                u32RegValue = REG_READ32(SMC_PMCTRL_ADDR32);
                
                EXECUTE_WAIT();
            }
            break;
        }
        case (MCU_STOP1_MODE):
        {
            if (SMC_PMSTAT_RUN_U32 == eCurrentPowerMode)
            {
                /* Set STOP1 mode. */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_WRITE32(SMC_STOPCTRL_ADDR32, SMC_STOPCTRL_STOP1_U32);
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_RMW32(SMC_PMCTRL_ADDR32, SMC_PMCTRL_STOPM_MASK32, SMC_PMCTRL_STOP_U32);
                /* This read ensures the transition was successful before executing WFI instruction */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                u32RegValue = REG_READ32(SMC_STOPCTRL_ADDR32);
                    
                EXECUTE_WAIT();
            }
            break;
        }
        case (MCU_STOP2_MODE):
        {
            if (SMC_PMSTAT_RUN_U32 == eCurrentPowerMode)
            {
                /* Set STOP2 mode. */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_WRITE32(SMC_STOPCTRL_ADDR32, SMC_STOPCTRL_STOP2_U32);
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_RMW32(SMC_PMCTRL_ADDR32, SMC_PMCTRL_STOPM_MASK32, SMC_PMCTRL_STOP_U32);
                /* This read ensures the transition was successful before executing WFI instruction */
                /** @violates @ref Mcu_SMC_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_SMC_c_REF_5 The cast is used to access memory mapped registers.*/
                u32RegValue = REG_READ32(SMC_STOPCTRL_ADDR32);
            
                EXECUTE_WAIT();
            }
            break;
        }
#endif        
        default:
        {
            /*Only the above modes are allowed when this function is called*/
            break;
        }
    }

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    /* Avoid compiler warning */
    MCU_PARAM_UNUSED(u32RegValue);
#endif
}

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SMC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SMC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
