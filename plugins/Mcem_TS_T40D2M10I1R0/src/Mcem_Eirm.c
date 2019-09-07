/**
*   @file    Mcem_Eirm.c
*   @implements     Mcem_Eirm.c_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MEMU IP layer of MCEM
*   @details Implementation if internal MEMU IP API of the MCEM module
*
*   @addtogroup MCEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Eim Erm
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
 *
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Mcem_Eirm_c_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice.
 * This is not a violation since all header files are protected against multiple inclusions.
 *
 * @section Mcem_Eirm_c_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
 * compatibility.
 *
 * @section Mcem_Eirm_c_REF_3
 * Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
 * preprocessor directives or comments.
 * Violated due to AUTOSAR requirement MEMMAP003.
 *
 * @section Mcem_Eirm_c_REF_4
 * Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer...
 * Unvoidable when addressing memory mapped registers.
 *
 * @section Mcem_Eirm_c_REF_5
 * Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
 * Unvoidable when addressing memory mapped registers.
 *
 * @section Mcem_Eirm_c_REF_6
 * Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, a constant, a parenthesised,
 * expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
 * Need wrap naming to a Base function.
 *
 * @section Mcem_Eirm_c_REF_7
 * Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects 
 * or functions at file scope shall have internal linkage unless external linkage is required.
 * Possibly unused public API
 *
 * @section Mcem_Eirm_c_REF_8
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 *
 * @section Mcem_Eirm_c_REF_9
 * Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
 * accessed from within a single function. External declaration required here.
 *
 * @section Mcem_Eirm_c_REF_10
 * Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer type and an integral type
 * Unvoidable when addressing memory mapped registers.
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions shall
 * not be reused. Ipv name start with letter E which is reserved for Error status. However, EIRM is unique. 
 */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


#ifdef Mcem_Eirm_REG_PROT_AVAILABLE
    #define USER_MODE_REG_PROT_ENABLED   MCEM_ENABLE_USER_MODE_SUPPORT
#else
    #define USER_MODE_REG_PROT_ENABLED (STD_OFF)
#endif

#include "SilRegMacros.h"

#include "Reg_eSys_Eirm.h"
#include "CDD_Mcem_Cfg.h"
#include "Mcem_Eirm.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EIRM_VENDOR_ID_C                      43
#define EIRM_AR_RELEASE_MAJOR_VERSION_C       4
#define EIRM_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref Mcem_Eirm_c_REF_2 Exceeds 31 characters */
/* @violates @ref Mcem_Eirm_c_REF_8 Exceeds 31 characters */
#define EIRM_AR_RELEASE_REVISION_VERSION_C    2
#define EIRM_SW_MAJOR_VERSION_C               1
#define EIRM_SW_MINOR_VERSION_C               0
#define EIRM_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcem_Memu.h header file are of the same vendor */
#if (EIRM_VENDOR_ID_C != EIRM_VENDOR_ID)
    #error "Mcem_Memu.c and Mcem_Memu.h have different Vendor ids"
#endif
/* Check if current file and Mcem_Memu.h header file are of the same Autosar version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION_C    != EIRM_AR_RELEASE_MAJOR_VERSION) || \
     (EIRM_AR_RELEASE_MINOR_VERSION_C    != EIRM_AR_RELEASE_MINOR_VERSION) || \
     (EIRM_AR_RELEASE_REVISION_VERSION_C != EIRM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_Memu.c and Mcem_Memu.h are different"
#endif
/* Check if current file and Mcem_Memu.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION_C != EIRM_SW_MAJOR_VERSION) || \
     (EIRM_SW_MINOR_VERSION_C != EIRM_SW_MINOR_VERSION) || \
     (EIRM_SW_PATCH_VERSION_C != EIRM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_Memu.c and Mcem_Memu.h are different"
#endif


/* Check if current file and CDD_Mcem_Cfg.h header file are of the same vendor */
#if (EIRM_VENDOR_ID_C != CDD_MCEM_VENDOR_ID_CFG)
    #error "Mcem_Memu.c and CDD_Mcem_Cfg.h have different Vendor ids"
#endif
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION_C != CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EIRM_AR_RELEASE_MINOR_VERSION_C != CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EIRM_AR_RELEASE_REVISION_VERSION_C != CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Mcem_Memu.c and CDD_Mcem_Cfg.h are different"
#endif
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION_C != CDD_MCEM_SW_MAJOR_VERSION_CFG) || \
     (EIRM_SW_MINOR_VERSION_C != CDD_MCEM_SW_MINOR_VERSION_CFG) || \
     (EIRM_SW_PATCH_VERSION_C != CDD_MCEM_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Mcem_Memu.c and CDD_Mcem_Cfg.h are different"
#endif

/* Check if current file and Reg_eSys_Memu.h header file are of the same vendor */
#if (EIRM_VENDOR_ID_C != EIRM_REG_VENDOR_ID)
    #error "Mcem_Memu.c and Reg_eSys_Memu.h have different Vendor ids"
#endif
/* Check if current file and Reg_eSys_Memu.h header file are the same Autosar version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION_C != EIRM_REG_AR_RELEASE_MAJOR_VERSION) || \
     (EIRM_AR_RELEASE_MINOR_VERSION_C != EIRM_REG_AR_RELEASE_MINOR_VERSION) || \
     (EIRM_AR_RELEASE_REVISION_VERSION_C != EIRM_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_Memu.c and Reg_eSys_Memu.h are different"
#endif
/* Check if current file and Reg_eSys_Memu.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION_C != EIRM_REG_SW_MAJOR_VERSION) || \
     (EIRM_SW_MINOR_VERSION_C != EIRM_REG_SW_MINOR_VERSION) || \
     (EIRM_SW_PATCH_VERSION_C != EIRM_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_Memu.c and Reg_eSys_Memu.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SilRegMacros.h header file are of the same Autosar version */
    #if ((EIRM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (EIRM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcem_Memu.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define MCEM_START_SEC_CONST_UNSPECIFIED
/* @violates @ref Mcem_Eirm_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"
#if (MCEM_EIRM_CORTEX_M0 == STD_ON)
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
CONST(uint32,MCEM_CONST) Mcem_u32EirmBitPosition[MCEM_EIRM_MAX_NO_FAULTS_M0_U8] = \
                            { \
                                MCEM_EIRM_MEN0_SINGLE_CORRECTION_SHIFT_U8, \
                                MCEM_EIRM_MEN0_NON_CORRECTABLE_SHIFT_U8, \
                            };
#else
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
CONST(uint32,MCEM_CONST) Mcem_u32EirmBitPosition[MCEM_EIRM_MAX_NO_FAULTS_U8] = \
                            { \
                                MCEM_EIRM_MEN0_SINGLE_CORRECTION_SHIFT_U8, \
                                MCEM_EIRM_MEN0_NON_CORRECTABLE_SHIFT_U8, \
                                MCEM_EIRM_MEN1_SINGLE_CORRECTION_SHIFT_U8, \
                                MCEM_EIRM_MEN1_NON_CORRECTABLE_SHIFT_U8, \
                            };
#endif
#define MCEM_STOP_SEC_CONST_UNSPECIFIED
/* @violates @ref Mcem_Eirm_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

#define MCEM_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcem_Eirm_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"
/* @violates @ref Mcem_Eirm_c_REF_9 Block scope */
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
P2CONST(Mcem_Eirm_ConfigType, AUTOMATIC, MCEM_APPL_CONST) Mcem_Eirm_pConfigPtr = NULL_PTR;

#define MCEM_STOP_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref Mcem_Eirm_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCEM_START_SEC_CODE
/* @violates @ref Mcem_Eirm_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief          Memu Init Function
* @details        Memu initialization function shall reset - if configured - all error flags
*
* @param[in]      pConfigPtr   Config pointer
*
* @return         void 
*
* @api           
*
* @note           Additionally, all injected errors are cleared (EIRM_DEBUG)
*
*/
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
FUNC(void, MCEM_CODE) Mcem_Eirm_Init
(
    P2CONST(Mcem_Eirm_ConfigType, AUTOMATIC, MCEM_APPL_CONST) pConfigPtr
)
{
    Mcem_Eirm_pConfigPtr = pConfigPtr;

    /* Configure ERM module */
    /* Clear current error status */
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, EIRM_ERM_STATUS_MASK_U32);
    
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_ERM_CONFIG_REG_ADDR32, pConfigPtr->Erm_IrqConfigReg);
    
    /* Configure EIM module */
    /* Disable global inject fault, make sure it is not enable in somewhere else */
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_CONFIG_REG_ADDR32, MCEM_EIRM_EIM_DISABLE_U32);
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_EICHEN_ADDR32, MCEM_EIRM_EIM_DISABLE_U32);
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_EICH0_WORD0_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_EICH0_WORD1_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
#if (STD_ON == MCEM_EIRM_CORTEX_M4)
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_EICH1_WORD0_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_EICH1_WORD1_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
#endif /* (STD_ON == MCEM_EIRM_CORTEX_M4 */
}

/**
* @brief          MEMU inject fault function
* @details        The MEMU can inject some ECC faults. It can be used for self-test the driver.
* param[in]       nFaultId The ID of fault to be injected into MEMU
*
* @return         void
*
* @api            
*
*/
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
FUNC(void, MCEM_CODE) Mcem_Eirm_InjectFault
(
    VAR(Mcem_FaultType, AUTOMATIC) nFaultId
)
{
    if (nFaultId <= MCEM_EIRM_LOWER_MAX)
    {
        SuspendAllInterrupts();
        if (0U == (nFaultId % 2U))
        {
            /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_EIM_EICH0_WORD0_ADDR32, Mcem_Eirm_pConfigPtr->Eim_SingleInjectWord0);
            /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_EIM_EICH0_WORD1_ADDR32, Mcem_Eirm_pConfigPtr->Eim_SingleInjectWord1);
        }
        else
        {
            /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_EIM_EICH0_WORD0_ADDR32, Mcem_Eirm_pConfigPtr->Eim_DoubleInjectWord0);
            /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_EIM_EICH0_WORD1_ADDR32, Mcem_Eirm_pConfigPtr->Eim_DoubleInjectWord1);
        }
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_EICHEN_ADDR32, EIRM_EIM_EICHEN_CH0_U32);
        /* Enable global inject fault */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_CONFIG_REG_ADDR32, MCEM_EIRM_EIM_ENABLE_U32);
#if (STD_ON == MCEM_EIRM_CORTEX_M0)
        /* Read memory to inject error */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_10 Pointer conversion */
        REG_READ32(Mcem_Eirm_pConfigPtr->M4_Tcm_upper);
#else
        /* Read memory to inject error */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_10 Pointer conversion */
        REG_READ32(Mcem_Eirm_pConfigPtr->M4_Tcm_Lower);
#endif
        /* Disable global inject fault */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_CONFIG_REG_ADDR32, MCEM_EIRM_EIM_DISABLE_U32);
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_EICH0_WORD0_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_EICH0_WORD1_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
        ResumeAllInterrupts();
    }
#if (STD_ON == MCEM_EIRM_CORTEX_M4)
    else if (nFaultId <= MCEM_EIRM_UPPER_MAX)
    {
        SuspendAllInterrupts();
        if (0U == (nFaultId % 2U))
        {
            /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_EIM_EICH1_WORD1_ADDR32, MCEM_EIRM_SINGLE_BIT_U32);
        }
        else
        {
            /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_EIM_EICH1_WORD1_ADDR32, MCEM_EIRM_MULTIPLE_BIT_U32);
        }
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_EICHEN_ADDR32, EIRM_EIM_EICHEN_CH1_U32);
        /* Enable global inject fault */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_CONFIG_REG_ADDR32, MCEM_EIRM_EIM_ENABLE_U32);
        
        /* Read memory to inject error */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_10 Pointer conversion */
        REG_READ32(Mcem_Eirm_pConfigPtr->M4_Tcm_upper);

        /* Disable global inject fault */
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_CONFIG_REG_ADDR32, MCEM_EIRM_EIM_DISABLE_U32);
        /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
        REG_WRITE32(EIRM_EIM_EICH1_WORD1_ADDR32, MCEM_EIRM_NO_ERR_BIT_U32);
        ResumeAllInterrupts();
    }
#endif /* (STD_ON == MCEM_EIRM_CORTEX_M4 */
    else
    {
        /* Not in range */
    }
}

/**
* @brief          MEMU get errors function
* @details        When an ECC error occurs, the MEMU IP shall log it. This function shal copy the 
*                 error flags into a special container
* @param[out]     pFaultContainer  Error container where the error flags shall be stored
* @param[out]     pFaultAccumulator  Accumulator where all fault bits are aggregated
*
* @return         void
*
* @api            
*
*/
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_Eirm_GetErrors
(
    VAR(uint32,AUTOMATIC) pFaultContainer[]
)
{
    VAR(uint8, AUTOMATIC) u8LoopCounter;
    VAR(uint32, AUTOMATIC) u32TempReg;
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_OK;
    
    pFaultContainer[ 0 ] = 0U;
    /* Store ECC error flags */
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    u32TempReg = REG_READ32(EIRM_ERM_STATUS_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
#if (STD_ON == MCEM_EIRM_CORTEX_M0)
    for (u8LoopCounter = 0U; u8LoopCounter < MCEM_EIRM_MAX_NO_FAULTS_M0_U8; u8LoopCounter++)
#else
    for (u8LoopCounter = 0U; u8LoopCounter < MCEM_EIRM_MAX_NO_FAULTS_U8; u8LoopCounter++)
#endif
    {
        if (0U != (u32TempReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
        {
            pFaultContainer[ 0 ] |= (uint32)1U << u8LoopCounter;
            nReturnValue = (Std_ReturnType)E_NOT_OK;
        }
    }
    
    return(nReturnValue);
}



/**
* @brief          Memu Clear error flags function
* @details        This function shall clear the error in MEMU error flag register
* @param[in]      nFaultId ID of the fault to be cleared.
* @return         Std_ReturnType
* @retval         E_OK if all error flags were cleared
* @retval         E_NOT_OK otherwise
*
* @api            
*  
*/
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
FUNC(Std_ReturnType, MCEM_CODE) Mcem_Eirm_ClearFault ( VAR(Mcem_FaultType, AUTOMATIC) nFaultId )
{
    VAR(Std_ReturnType,MCEM_VAR) nReturnValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, MCEM_VAR)u32RegisterValue;
    
    u32RegisterValue = (uint32)1U << Mcem_u32EirmBitPosition[nFaultId];

    /* Clear ECC fault injection(s) first */     
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, u32RegisterValue);

    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    if ( EIRM_NO_ERRORS_U32 == (u32RegisterValue & (uint32)REG_READ32(EIRM_ERM_STATUS_REG_ADDR32)) )
    {
        nReturnValue = (Std_ReturnType)E_OK;
    }

    return nReturnValue;
}

/**
* @brief          Function to check if faults is not disable
* @details        Function to check if faults is not disable
*
* @param[in]      nFaultId     The ID of the fault to be injected
*                            
* @return         boolean: 
*                           TRUE  : Fault ID is valid (not disable)
*                           FALSE : Fault ID is valid (not disable)
*
* @pre            nFaultId is valid
*
* @api            
*
*/
/* @violates @ref Mcem_Eirm_c_REF_7 external interface is required */
FUNC(boolean, MCEM_CODE)    Mcem_Eirm_CheckValidFault (VAR(Mcem_FaultType, AUTOMATIC)nFaultId)
{
    VAR(boolean,MCEM_VAR) bReturnValue = (boolean)FALSE;
    
    if (0U != (Mcem_Eirm_pConfigPtr->Erm_ConfigReg & ((uint32)1U << Mcem_u32EirmBitPosition[nFaultId])))
    {
        bReturnValue = (boolean)TRUE;
    }
    return bReturnValue;
}
#define MCEM_STOP_SEC_CODE
/* @violates @ref Mcem_Eirm_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
