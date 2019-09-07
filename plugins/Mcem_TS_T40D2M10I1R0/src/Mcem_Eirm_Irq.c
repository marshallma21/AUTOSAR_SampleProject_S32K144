/**
*   @file    Mcem_Eirm_Irq.c
*   @implements     Mcem_Eirm_Irq.c_Artifact
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
 * @section Mcem_Eirm_Irq_c_REF_1
 * Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
 * contents of a header file being included twice.
 * This is not a violation since all header files are protected against multiple inclusions.
 *
 * @section Mcem_Eirm_Irq_c_REF_2
 * Violates MISRA 2004 Required Rule 1.4, Exceeds 31 characters due to AUTOSAR 
 * compatibility.
 *
 * @section Mcem_Eirm_Irq_c_REF_3
 * Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other
 * preprocessor directives or comments.
 * Violated due to AUTOSAR requirement MEMMAP003.
 *
 * @section Mcem_Eirm_Irq_c_REF_4
 * Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer...
 * Unvoidable when addressing memory mapped registers.
 *
 * @section Mcem_Eirm_Irq_c_REF_5
 * Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type
 * Unvoidable when addressing memory mapped registers.
 *
 * @section Mcem_Eirm_Irq_c_REF_6
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR 
 * compatibility. The compiler can support more than 31 characters. 
 *
 * @section Mcem_Eirm_Irq_c_REF_7
 * Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects 
 * or functions at file scope shall have internal linkage unless external linkage is required.
 * Possibly unused public API
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



#define USER_MODE_REG_PROT_ENABLED (STD_OFF)


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
/* @violates @ref Mcem_Eirm_Irq_c_REF_2 Exceeds 31 characters */
/* @violates @ref Mcem_Eirm_Irq_c_REF_6 Exceeds 31 characters */
#define EIRM_AR_RELEASE_REVISION_VERSION_C    2
#define EIRM_SW_MAJOR_VERSION_C               1
#define EIRM_SW_MINOR_VERSION_C               0
#define EIRM_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcem_Eirm.h header file are of the same vendor */
#if (EIRM_VENDOR_ID_C != EIRM_VENDOR_ID)
    #error "Mcem_Eirm.c and Mcem_Eirm.h have different Vendor ids"
#endif
/* Check if current file and Mcem_Eirm.h header file are of the same Autosar version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION_C    != EIRM_AR_RELEASE_MAJOR_VERSION) || \
     (EIRM_AR_RELEASE_MINOR_VERSION_C    != EIRM_AR_RELEASE_MINOR_VERSION) || \
     (EIRM_AR_RELEASE_REVISION_VERSION_C != EIRM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_Eirm.c and Mcem_Eirm.h are different"
#endif
/* Check if current file and Mcem_Eirm.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION_C != EIRM_SW_MAJOR_VERSION) || \
     (EIRM_SW_MINOR_VERSION_C != EIRM_SW_MINOR_VERSION) || \
     (EIRM_SW_PATCH_VERSION_C != EIRM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_Eirm.c and Mcem_Eirm.h are different"
#endif


/* Check if current file and CDD_Mcem_Cfg.h header file are of the same vendor */
#if (EIRM_VENDOR_ID_C != CDD_MCEM_VENDOR_ID_CFG)
    #error "Mcem_Eirm.c and CDD_Mcem_Cfg.h have different Vendor ids"
#endif
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION_C != CDD_MCEM_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (EIRM_AR_RELEASE_MINOR_VERSION_C != CDD_MCEM_AR_RELEASE_MINOR_VERSION_CFG) || \
     (EIRM_AR_RELEASE_REVISION_VERSION_C != CDD_MCEM_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Mcem_Eirm.c and CDD_Mcem_Cfg.h are different"
#endif
/* Check if current file and CDD_Mcem_Cfg.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION_C != CDD_MCEM_SW_MAJOR_VERSION_CFG) || \
     (EIRM_SW_MINOR_VERSION_C != CDD_MCEM_SW_MINOR_VERSION_CFG) || \
     (EIRM_SW_PATCH_VERSION_C != CDD_MCEM_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Mcem_Eirm.c and CDD_Mcem_Cfg.h are different"
#endif

/* Check if current file and Reg_eSys_Memu.h header file are of the same vendor */
#if (EIRM_VENDOR_ID_C != EIRM_REG_VENDOR_ID)
    #error "Mcem_Eirm.c and Reg_eSys_Memu.h have different Vendor ids"
#endif
/* Check if current file and Reg_eSys_Memu.h header file are the same Autosar version */
#if ((EIRM_AR_RELEASE_MAJOR_VERSION_C != EIRM_REG_AR_RELEASE_MAJOR_VERSION) || \
     (EIRM_AR_RELEASE_MINOR_VERSION_C != EIRM_REG_AR_RELEASE_MINOR_VERSION) || \
     (EIRM_AR_RELEASE_REVISION_VERSION_C != EIRM_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcem_Eirm.c and Reg_eSys_Memu.h are different"
#endif
/* Check if current file and Reg_eSys_Memu.h header file are of the same Software version */
#if ((EIRM_SW_MAJOR_VERSION_C != EIRM_REG_SW_MAJOR_VERSION) || \
     (EIRM_SW_MINOR_VERSION_C != EIRM_REG_SW_MINOR_VERSION) || \
     (EIRM_SW_PATCH_VERSION_C != EIRM_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcem_Eirm.c and Reg_eSys_Memu.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SilRegMacros.h header file are of the same Autosar version */
    #if ((EIRM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (EIRM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcem_Eirm.c and SilRegMacros.h are different"
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
/* @violates @ref Mcem_Eirm_Irq_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_Irq_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"
#if (MCEM_EIRM_CORTEX_M0 == STD_ON)
ISR(MCEM_EIRM_FAULT_ISR);
ISR(MCEM_EIRM_HARD_FAULT_DOUBLEBIT_ISR);
#else
#if (MCEM_EIRM_FAULT_SINGLEBIT_ISR_ENABLE == STD_ON)
ISR(MCEM_EIRM_FAULT_SINGLEBIT_ISR);
#endif
#if (MCEM_EIRM_FAULT_DOUBLEBIT_ISR_ENABLE == STD_ON)
ISR(MCEM_EIRM_FAULT_DOUBLEBIT_ISR);
#endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if (MCEM_EIRM_CORTEX_M0 == STD_ON)
ISR(MCEM_EIRM_FAULT_ISR)
{
    VAR(uint32, AUTOMATIC) u32TempReg;
    VAR(uint32, AUTOMATIC) u32TempMaskReg;
    VAR(uint32, AUTOMATIC) u32ErrorAddr;
    VAR(uint8, AUTOMATIC) u8LoopCounter;
    
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    u32TempReg = REG_READ32(EIRM_ERM_STATUS_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
    if ((uint32)0U != u32TempReg)
    {
        /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
        u32TempMaskReg = REG_READ32(EIRM_ERM_CONFIG_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
        if (NULL_PTR != Mcem_Eirm_pConfigPtr)
        {
            for (u8LoopCounter = 0U; u8LoopCounter < MCEM_EIRM_MAX_NO_FAULTS_M0_U8; u8LoopCounter+=1U)
            {
                if (0U != (u32TempReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
                {
                    if (0U != (u32TempMaskReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
                    {
                        if (NULL_PTR != Mcem_Eirm_pConfigPtr->ErrorAddrNotifyApi)
                        {
                            /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                            /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                            u32ErrorAddr = REG_READ32(EIRM_ERM_ERR_ADDR0_ADDR32);
                            Mcem_Eirm_pConfigPtr->ErrorAddrNotifyApi(u8LoopCounter, u32ErrorAddr);
                        }
                    }
                    /* Clear the error flag to prevent spurious IRQ */
                    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                    REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter]));
                }
            }
        }
        else
        {
            /* Only clear the interrupt flag when driver is not initialized, otherwise error will not report to user in other API */
            /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, u32TempReg);
        }
    }
    /* Exit the interrupt */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    EXIT_INTERRUPT();
}
#if (MCEM_EIRM_FAULT_DOUBLEBIT_ISR_ENABLE == STD_ON)
/**
* @brief          ISR for Double bit error non-correctable
* @details        ISR for Double bit error non-correctable
* @implements     MCEM_EIRM_FAULT_X_Activity
* @violates @ref Mcem_Eirm_Irq_c_REF_7 external interface is required
*/
ISR(MCEM_EIRM_HARD_FAULT_DOUBLEBIT_ISR)
{
    /* Disable global inject fault*/
    /* @violates @ref Mcem_Eirm_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_c_REF_5 Pointer conversion */
    REG_WRITE32(EIRM_EIM_CONFIG_REG_ADDR32, MCEM_EIRM_EIM_DISABLE_U32);
    /* Exit the interrupt */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    EXIT_INTERRUPT();
}
#endif
#else
#if (MCEM_EIRM_FAULT_SINGLEBIT_ISR_ENABLE == STD_ON)
/**
* @brief          ISR for Single bit error correction
* @details        ISR for Single bit error correction
* @implements     MCEM_EIRM_FAULT_X_Activity
* @violates @ref Mcem_Eirm_Irq_c_REF_7 external interface is required
*/
ISR(MCEM_EIRM_FAULT_SINGLEBIT_ISR)
{
    VAR(uint32, AUTOMATIC) u32TempReg;
    VAR(uint32, AUTOMATIC) u32TempMaskReg;
    VAR(uint32, AUTOMATIC) u32ErrorAddr;
    VAR(uint8, AUTOMATIC) u8LoopCounter;
    
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    u32TempReg = REG_READ32(EIRM_ERM_STATUS_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
    if ((uint32)0U != u32TempReg)
    {
        /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
        u32TempMaskReg = REG_READ32(EIRM_ERM_CONFIG_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
        if (NULL_PTR != Mcem_Eirm_pConfigPtr)
        {
            for (u8LoopCounter = 0U; u8LoopCounter < MCEM_EIRM_MAX_NO_FAULTS_U8; u8LoopCounter+=2U)
            {
                if (0U != (u32TempReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
                {
                    if (0U != (u32TempMaskReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
                    {
                        if (NULL_PTR != Mcem_Eirm_pConfigPtr->ErrorAddrNotifyApi)
                        {
                            if (u8LoopCounter < 2U)
                            {
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                                u32ErrorAddr = REG_READ32(EIRM_ERM_ERR_ADDR0_ADDR32);
                            }
                            else
                            {
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                                u32ErrorAddr = REG_READ32(EIRM_ERM_ERR_ADDR1_ADDR32);
                            }
                            Mcem_Eirm_pConfigPtr->ErrorAddrNotifyApi(u8LoopCounter, u32ErrorAddr);
                        }
                    }
                    /* Clear the error flag to prevent spurious IRQ */
                    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                    REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter]));
                }
            }
        }
        else
        {
            /* Only clear the interrupt flag when driver is not initialized, otherwise error will not report to user in other API */
            /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, u32TempReg);
        }
    }
    /* Exit the interrupt */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    EXIT_INTERRUPT();
}
#endif

#if (MCEM_EIRM_FAULT_DOUBLEBIT_ISR_ENABLE == STD_ON)
/**
* @brief          ISR for Double bit error non-correctable
* @details        ISR for Double bit error non-correctable
* @implements     MCEM_EIRM_FAULT_X_Activity
* @violates @ref Mcem_Eirm_Irq_c_REF_7 external interface is required
*/
ISR(MCEM_EIRM_FAULT_DOUBLEBIT_ISR)
{
    VAR(uint32, AUTOMATIC) u32TempReg;
    VAR(uint32, AUTOMATIC) u32TempMaskReg;
    VAR(uint32, AUTOMATIC) u32ErrorAddr;
    VAR(uint8, AUTOMATIC) u8LoopCounter;
    
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    u32TempReg = REG_READ32(EIRM_ERM_STATUS_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
    if ((uint32)0U != u32TempReg)
    {
        /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
        /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
        u32TempMaskReg = REG_READ32(EIRM_ERM_CONFIG_REG_ADDR32) & EIRM_ERM_STATUS_MASK_U32;
        if (NULL_PTR != Mcem_Eirm_pConfigPtr)
        {
            for (u8LoopCounter = 1U; u8LoopCounter < MCEM_EIRM_MAX_NO_FAULTS_U8; u8LoopCounter+=2U)
            {
                if (0U != (u32TempReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
                {
                    if (0U != (u32TempMaskReg & ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter])))
                    {
                        if (NULL_PTR != Mcem_Eirm_pConfigPtr->ErrorAddrNotifyApi)
                        {
                            if (u8LoopCounter < 2U)
                            {
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                                u32ErrorAddr = REG_READ32(EIRM_ERM_ERR_ADDR0_ADDR32);
                            }
                            else
                            {
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                                /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                                u32ErrorAddr = REG_READ32(EIRM_ERM_ERR_ADDR1_ADDR32);
                            }
                            Mcem_Eirm_pConfigPtr->ErrorAddrNotifyApi(u8LoopCounter, u32ErrorAddr);
                        }
                    }
                    /* Clear the error flag to prevent spurious IRQ */
                    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
                    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
                    REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, ((uint32)1U << Mcem_u32EirmBitPosition[u8LoopCounter]));
                }
            }
        }
        else
        {
            /* Only clear the interrupt flag when driver is not initialized, otherwise error will not report to user in other API */
            /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
            /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
            REG_WRITE32(EIRM_ERM_STATUS_REG_ADDR32, u32TempReg);
        }
    }
    /* Exit the interrupt */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_4 Pointer conversion */
    /* @violates @ref Mcem_Eirm_Irq_c_REF_5 Pointer conversion */
    EXIT_INTERRUPT();
}
#endif
#endif

#define MCEM_STOP_SEC_CODE
/* @violates @ref Mcem_Eirm_Irq_c_REF_1 precautions to prevent the contents of a header file being included twice */
/* @violates @ref Mcem_Eirm_Irq_c_REF_3 only preprocessor statements and comments before "#include". */
#include "Mcem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
