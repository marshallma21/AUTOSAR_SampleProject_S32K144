/**
*   @file    Mcu_RCM.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Reset Control Module functions implementation.
*   @details Specific functions for RCM configuration and control.
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
* @section Mcu_RCM_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_RCM_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_RCM_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_RCM_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_RCM_c_REF_5
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
#include "Mcu_RCM.h"
#include "Reg_eSys_RCM.h"

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
#define MCU_RCM_VENDOR_ID_C                      43
/** @violates @ref Mcu_RCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_RCM_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_RCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_RCM_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_RCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_RCM_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_RCM_SW_MAJOR_VERSION_C               1
#define MCU_RCM_SW_MINOR_VERSION_C               0
#define MCU_RCM_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_RCM header file are of the same vendor */
#if (MCU_RCM_VENDOR_ID_C != MCU_RCM_VENDOR_ID)
    #error "Mcu_RCM.c and Mcu_RCM.h have different vendor ids"
#endif
/* Check if current file and Mcu_RCM header file are of the same Autosar version */
#if ((MCU_RCM_AR_RELEASE_MAJOR_VERSION_C    != MCU_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_MINOR_VERSION_C    != MCU_RCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_REVISION_VERSION_C != MCU_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_RCM.c and Mcu_RCM.h are different"
#endif
/* Check if current file and Mcu_RCM header file are of the same Software version */
#if ((MCU_RCM_SW_MAJOR_VERSION_C != MCU_RCM_SW_MAJOR_VERSION) || \
     (MCU_RCM_SW_MINOR_VERSION_C != MCU_RCM_SW_MINOR_VERSION) || \
     (MCU_RCM_SW_PATCH_VERSION_C != MCU_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_RCM.c and Mcu_RCM.h are different"
#endif

/* Check if source file and Reg_eSys_RCM.h are from the same vendor */
#if (MCU_RCM_VENDOR_ID_C != REG_ESYS_RCM_VENDOR_ID)
    #error "Mcu_RCM.C and Reg_eSys_RCM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_RCM.h are of the same Autosar version */
#if ((MCU_RCM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_RCM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_RCM.c and Reg_eSys_RCM.h are different"
#endif
/*Check if source file and Reg_eSys_RCM.h are of the same Software version */
#if ((MCU_RCM_SW_MAJOR_VERSION_C != REG_ESYS_RCM_SW_MAJOR_VERSION) || \
     (MCU_RCM_SW_MINOR_VERSION_C != REG_ESYS_RCM_SW_MINOR_VERSION) || \
     (MCU_RCM_SW_PATCH_VERSION_C != REG_ESYS_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_RCM.c and Reg_eSys_RCM.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_RCM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_RCM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_RCM.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_RCM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_RCM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_RCM.c and SilRegMacros.h are different"
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
#define MCU_START_SEC_VAR_INIT_32
/**
 * @violates @ref Mcu_RCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
 */
#include "Mcu_MemMap.h"

static VAR(uint32, MCU_VAR) Mcu_u32ResetStatus = 0x00U;

#define MCU_STOP_SEC_VAR_INIT_32
/**
 * @violates @ref Mcu_RCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
 * @violates @ref Mcu_RCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
 * statements and comments before '#include'
 */
#include "Mcu_MemMap.h"

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
* @violates @ref Mcu_RCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
 * @violates @ref Mcu_RCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
 * statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function initializes the Reset parameters.
* @details          Conigures the threshold reset value.
*                   Called by:
*                       - Mcu_IPW_Init() from IPW.
*
* @param[in]        pConfigPtr   Pointer to the RCM configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_RCM_ResetInit(P2CONST( Mcu_RCM_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(RCM_RPC_ADDR32, (uint32)(pConfigPtr->u32ResetPinControlConfig & RCM_RPC_RWBITS_MASK32));
    
    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(RCM_SRIE_ADDR32, (uint32)(pConfigPtr->u32ResetInterruptEnableConfig & RCM_SRIE_RWBITS_MASK32));
}

/**
* @brief            This function returns the Reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_IPW_GetResetReason() from IPW.
*
* @return           Reason of the Reset event.
*
* @note             The User should ensure that the reset reason is cleared once it has been read
*                   out to avoid multiple reset reasons. The function Mcu_GetResetReason shall
*                   return MCU_RESET_UNDEFINED if this function is called prior to calling of the
*                   function Mcu_Init, and if supported by the hardware.
*/
FUNC( Mcu_ResetType, MCU_CODE) Mcu_RCM_GetResetReason( VAR( void, AUTOMATIC))
{
    /* Code for the Reset event returned by this function. */
    VAR( Mcu_ResetType, AUTOMATIC) eResetReason = MCU_NO_RESET_REASON;
    /* Temporary variable for RCM_RSR register value. */
    VAR( uint32, AUTOMATIC) u32RegValue = 0U;
    VAR( uint32, AUTOMATIC) u32ActiveValue;
    VAR( uint32, AUTOMATIC) u32Index;
    VAR( uint32, AUTOMATIC) u32DynamicMask;
    VAR( uint32, AUTOMATIC) u32Position = (uint32)0x00U;
    VAR( uint32, AUTOMATIC) u32NumberOfFlags = 0U;
    
    /* Check reset reasons from SSRS Status Register. */
    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    u32RegValue = (uint32)REG_READ32(RCM_SSRS_ADDR32) & RCM_SSRS_RWBITS_MASK32;
    
    /* Store the content of RSR */
    if (0x00U != u32RegValue)
    {
        /* Clear the flags if any flag is set */
        /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
        REG_WRITE32(RCM_SSRS_ADDR32, (uint32)(u32RegValue & RCM_SSRS_RWBITS_MASK32));
        
        Mcu_u32ResetStatus = u32RegValue;
    }
    u32ActiveValue = Mcu_u32ResetStatus;

    for (u32Index = 0x00U; u32Index < 0x20U; u32Index++)
    {
        u32DynamicMask = ((uint32)0x80000000U >> u32Index);
        if ((uint32)0x00U != (u32DynamicMask & RCM_SSRS_RWBITS_MASK32))
        {
            if ((uint32)0x00U != (u32DynamicMask & u32ActiveValue))
            {
                eResetReason = (Mcu_ResetType)u32Position;
                u32NumberOfFlags++;
                /* MCU_MULTIPLE_RESET_REASON returned if more than one reset reason in this case use function Mcu_GetRawValue to determine. */
                if (u32NumberOfFlags >= (uint32)2)
                {
                    eResetReason = MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            u32Position++;
        }
    }
    
    return (Mcu_ResetType)eResetReason;
}

/**
* @brief            This function returns the Raw Reset value.
* @details          This routine returns the Raw Reset value that is read from the hardware.
*                   Called by:
*                       - Mcu_IPW_GetResetRawValue() from IPW.
*
* @return           Register value with the Reset status.
* @retval           uint32   Code of the Raw reset value.
*
* @note             The User should ensure that the reset reason is cleared once it has been read
*                   out to avoid multiple reset reasons.
*
*/
FUNC( Mcu_RawResetType, MCU_CODE) Mcu_RCM_GetResetRawValue( VAR( void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32RawReset;
    VAR( uint32, AUTOMATIC) u32RegValue;

    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32(RCM_SSRS_ADDR32) & RCM_SSRS_RWBITS_MASK32;

    if ((uint32)0x00U != u32RegValue)
    {
        /* Clear the flags if any flag is set */
        /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
        REG_WRITE32(RCM_SSRS_ADDR32, (uint32)(u32RegValue & RCM_SSRS_RWBITS_MASK32));
        
        Mcu_u32ResetStatus = u32RegValue;
    }
    
    u32RawReset = Mcu_u32ResetStatus;

    return (Mcu_RawResetType)u32RawReset;
}

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
/**
* @brief    This function returns the value of RCM_SRIE masked configured System Reset Interrupt
*/
FUNC( uint32, MCU_CODE) Mcu_RCM_GetCurrentSystemResetIsrSettings( VAR( void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32SystemResetIsrStatus;
    /* get RCM_SRIE and mask agains what i need */
    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    u32SystemResetIsrStatus = REG_READ32(RCM_SRIE_ADDR32);
    u32SystemResetIsrStatus &= RCM_SRIE_RWBITS_MASK32;

    return ((uint32)u32SystemResetIsrStatus);
}

/**
* @brief    This function Configure all reset sources to be 'Reset' (not as Interrupt) via RCM_SRIE
*/
FUNC( void, MCU_CODE) Mcu_RCM_SystemResetIsrConfig( VAR( void, AUTOMATIC))
{
    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(RCM_SRIE_ADDR32, (uint32)RCM_SRIE_RESET_MASK32);
}

/**
* @brief    This function Restore System Reset Interrupt Config
*/
FUNC(void, MCU_CODE) Mcu_RCM_RestoreSystemResetIsrConfig(VAR(uint32, AUTOMATIC) u32SystemResetIsrConfig)
{
    /** @violates @ref Mcu_RCM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_RCM_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(RCM_SRIE_ADDR32, (uint32)(u32SystemResetIsrConfig & RCM_SRIE_RWBITS_MASK32));
}
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_RCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_RCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
