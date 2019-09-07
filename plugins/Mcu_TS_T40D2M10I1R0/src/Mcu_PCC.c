/**
*   @file    Mcu_PCC.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Peripheral Clock Control functions implementation.
*   @details Specific functions for PCC configuration and control.
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
* @section Mcu_PCC_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_PCC_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_PCC_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_PCC_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_PCC_c_REF_5
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
#include "Mcu_PCC.h"

#include "Reg_eSys_PCC.h"

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
#define MCU_PCC_VENDOR_ID_C                      43
/** @violates @ref Mcu_PCC_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_PCC_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_PCC_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_PCC_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_PCC_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_PCC_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_PCC_SW_MAJOR_VERSION_C               1
#define MCU_PCC_SW_MINOR_VERSION_C               0
#define MCU_PCC_SW_PATCH_VERSION_C               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_PCC header file are of the same vendor */
#if (MCU_PCC_VENDOR_ID_C != MCU_PCC_VENDOR_ID)
    #error "Mcu_PCC.c and Mcu_PCC.h have different vendor ids"
#endif
/* Check if current file and Mcu_PCC header file are of the same Autosar version */
#if ((MCU_PCC_AR_RELEASE_MAJOR_VERSION_C    != MCU_PCC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PCC_AR_RELEASE_MINOR_VERSION_C    != MCU_PCC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PCC_AR_RELEASE_REVISION_VERSION_C != MCU_PCC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PCC.c and Mcu_PCC.h are different"
#endif
/* Check if current file and Mcu_PCC header file are of the same Software version */
#if ((MCU_PCC_SW_MAJOR_VERSION_C != MCU_PCC_SW_MAJOR_VERSION) || \
     (MCU_PCC_SW_MINOR_VERSION_C != MCU_PCC_SW_MINOR_VERSION) || \
     (MCU_PCC_SW_PATCH_VERSION_C != MCU_PCC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PCC.c and Mcu_PCC.h are different"
#endif

/* Check if source file and Reg_eSys_PCC.h are from the same vendor */
#if (MCU_PCC_VENDOR_ID_C != REG_ESYS_PCC_VENDOR_ID)
    #error "Mcu_PCC.C and Reg_eSys_PCC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_PCC.h are of the same Autosar version */
#if ((MCU_PCC_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PCC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PCC_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PCC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PCC_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PCC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PCC.c and Reg_eSys_PCC.h are different"
#endif
/*Check if source file and Reg_eSys_PCC.h are of the same Software version */
#if ((MCU_PCC_SW_MAJOR_VERSION_C != REG_ESYS_PCC_SW_MAJOR_VERSION) || \
     (MCU_PCC_SW_MINOR_VERSION_C != REG_ESYS_PCC_SW_MINOR_VERSION) || \
     (MCU_PCC_SW_PATCH_VERSION_C != REG_ESYS_PCC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PCC.c and Reg_eSys_PCC.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PCC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PCC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PCC.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PCC_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PCC_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PCC.c and SilRegMacros.h are different"
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
* @violates @ref Mcu_PCC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#if (MCU_INIT_CLOCK == STD_ON)

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function will configure the peripherals
*
* @details          This function will configure the peripherals
*
*/
FUNC( void, MCU_CODE) Mcu_PCC_PeripheralConfig(P2CONST(Mcu_PCC_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;
    VAR(uint32, AUTOMATIC) u8PeripheralIsPresent;
        
    for ( u32Counter = (uint32)0x00U; u32Counter < (uint32)(pConfigPtr->u32NumberOfPccRegisters); u32Counter++)
    {
        /** @violates @ref Mcu_PCC_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_PCC_c_REF_5 The cast is used to access memory mapped registers.*/
        u8PeripheralIsPresent = REG_READ32((*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterAddr) & PCC_PR_MASK32;
        
        if (PCC_PERIPHERAL_IS_PRESENT_U32 == u8PeripheralIsPresent)
        {
            if(PCC_PCS_UNAVAILABLE_U32 != ((*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterData & PCC_PCS_UNAVAILABLE_U32))
            {
                /* Disable Peripheral clock first */
                /** @violates @ref Mcu_PCC_c_REF_4 Conversion from pointer to integer */
                /** @violates @ref Mcu_PCC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_BIT_CLEAR32((*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterAddr,PCC_CGC_MASK32);
                /* Configure all parameters */
                /** @violates @ref Mcu_PCC_c_REF_4 Conversion from pointer to integer */
                /** @violates @ref Mcu_PCC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_WRITE32((*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterAddr, (*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterData);
                
            }
            else
            {
                /** @violates @ref Mcu_PCC_c_REF_4 Conversion from pointer to integer */
                /** @violates @ref Mcu_PCC_c_REF_5 The cast is used to access memory mapped registers.*/
                REG_WRITE32((*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterAddr, (*pConfigPtr->apPeripheralConfig)[u32Counter].u32RegisterData);
            }
        }
    }
    
}
#endif

#ifdef MCU_ENABLE_CMU_PERIPHERAL
#if(MCU_ENABLE_CMU_PERIPHERAL == STD_ON)
/** @violates @ref Mcu_CMU_c_REF_4 Global declaration of function*/
FUNC( uint32, MCU_CODE) Mcu_PCC_GetStatus(VAR(uint32, AUTOMATIC) u32RegisterAddr)
{
    /** @violates @ref Mcu_PCC_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PCC_c_REF_5 The cast is used to access memory mapped registers.*/
    return REG_READ32(u32RegisterAddr);
}
#endif
#endif
    
#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_PCC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PCC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
