/**
*   @file    Fls_Qspi_Irq.c
*   @implements Fls_Qspi_Irq.c_Artifact 
*   @version 1.0.1
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver interrupt routine code.
*   @details Interrupt routine code.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : IPV_FTFE
*   Dependencies         : 
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
* @page misra_violations MISRA-C:2004 violations
*
* @section fls_qspi_irq_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping.
* 
* @section fls_qspi_irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
* 
* @section fls_qspi_irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_qspi_irq_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* Interrupt service routine exported to upper layers.
*
* @section [global]
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
* 
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Fls_Types.h"
#include "Fls_Qspi.h"
#include "Fls_Qspi_Types.h"
#include "Reg_eSys_QSPI.h"
#include "StdRegMacros.h"

#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON or FLS_RUNTIME_ERROR_DETECT == STD_ON */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_QSPI_IRQ_VENDOR_ID_C                      43
#define FLS_QSPI_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLS_QSPI_IRQ_AR_RELEASE_MINOR_VERSION_C       2
#define FLS_QSPI_IRQ_AR_RELEASE_REVISION_VERSION_C    2
#define FLS_QSPI_IRQ_SW_MAJOR_VERSION_C               1
#define FLS_QSPI_IRQ_SW_MINOR_VERSION_C               0
#define FLS_QSPI_IRQ_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief    Start of Fls section CODE 
*
* @violates @ref fls_qspi_irq_c_REF_1 Violates MISRA 2004 Required Rule 19.15
*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_qspi_irq_c_REF_3 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_qspi_irq_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"


#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE)     
#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)

#if(FLS_USE_INTERRUPTS == STD_ON)
    
ISR(FLS_QSPI_ISR);

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
static FUNC(void, FLS_CODE) Fls_Qspi_ProcessCombinedIrq(void);
#else
static FUNC(void, FLS_CODE) Fls_Qspi_ProcessCombinedHyperIrq(void);
#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */

/*==================================================================================================
                                      GLOBAL FUNCTIONS
==================================================================================================*/ 
/* @violates @ref fls_qspi_irq_c_REF_4 Violates MISRA 2004 Required Rule 8.10, All declarations and definitions should have internal linkage. */
ISR(FLS_QSPI_ISR)
{
    /* Check if the current interrupt job operates on a Hyperflash type of memory. */
    #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
        /* Call the interrupt routine for processing normal quadspi memory types. */
        Fls_Qspi_ProcessCombinedIrq();
    #else
        /* Call the interrupt routine for processing hyperflash memory types. */
        Fls_Qspi_ProcessCombinedHyperIrq();
    #endif
    
    EXIT_INTERRUPT();
} 

#if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF)
    
static FUNC(void, FLS_CODE) Fls_Qspi_ProcessCombinedIrq(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    /* Check the current job type which is in process.*/
    if(FLS_JOB_ERASE == Fls_eJob)
    {
        static VAR(boolean, AUTOMATIC) bMemoryIsBusy    = (boolean)TRUE;   /* Busy status of the first, or only, memory. */
        static VAR(boolean, AUTOMATIC) bMemoryIsBusyPar = (boolean)TRUE;   /* Busy status of the second memory from the parallel pair. */
                    
        /* Check the possible IRQ states for an erase job executed in interrupt context. */
        if(FLASH_IRQ_JOB_ERASE == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqEraseErase(&bMemoryIsBusy, &bMemoryIsBusyPar);
        }
        else if(FLASH_IRQ_JOB_GET_STATUS == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqEraseGetStatus(&bMemoryIsBusy);
        }
        else if(FLASH_IRQ_JOB_GET_STATUS_PAR == Fls_eLLDIrqJob)
        {            
            eRetVal = Fls_Qspi_IrqEraseGetStatusPar(&bMemoryIsBusyPar);
        }
    #if( FLS_ERASE_BLANK_CHECK == STD_ON )    
        else if(FLASH_IRQ_JOB_BLANK_CHECK == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqEraseBlankCheck();
            #if (FLS_DEV_ERROR_DETECT == STD_ON)    
            if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
            {
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                                 FLS_E_VERIFY_ERASE_FAILED 
                                      );
            }
            #endif
        }
    #endif    
        else /* Error, incorrect IRQ state for an erase job. */
        {
            eRetVal = FLASH_E_FAILED;
        } 

        if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                #endif
                    }
        
    }
    else if(FLS_JOB_READ == Fls_eJob)
    {
        /* Check the possible IRQ states for a read job executed in interrupt context. */
        if(FLASH_IRQ_JOB_READ == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqReadRead();
        }   
        else /* Error, incorrect IRQ state for a read job. */
        {
            eRetVal = FLASH_E_FAILED;
        } 

        if(FLASH_E_FAILED == eRetVal)
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_READ_FAILED);
                #endif
                    }
    }
    else if(FLS_JOB_COMPARE == Fls_eJob)   
    {
        /* Check the possible IRQ states for a read job executed in interrupt context. */
        if(FLASH_IRQ_JOB_COMPARE == Fls_eLLDIrqJob)
        {              
            eRetVal = Fls_Qspi_IrqReadCompare();
        }
        else /* Error, incorrect IRQ state for a read job. */
        {
            eRetVal = FLASH_E_FAILED;
        } 

        if(FLASH_E_FAILED == eRetVal)
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_COMPARE_FAILED);
                #endif
                    }
    }
#if( FLS_BLANK_CHECK_API == STD_ON ) 
    else if(FLS_JOB_BLANK_CHECK == Fls_eJob)
    {   
        if(FLASH_IRQ_JOB_BLANK_CHECK == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqReadBlankCheck();
        }   
        else /* Error, incorrect IRQ state for a read job. */
        {
            eRetVal = FLASH_E_FAILED;
        } 

        if(FLASH_E_FAILED == eRetVal)
        {
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_COMPARE_FAILED);
            #endif
        }
    }
#endif /*#if( FLS_BLANK_CHECK_API == STD_ON )*/ 
    else if(FLS_JOB_WRITE == Fls_eJob)
    {
        static VAR(boolean, AUTOMATIC) bMemoryIsBusy = (boolean)TRUE;
        static VAR(boolean, AUTOMATIC) bMemoryIsBusyPar = (boolean)TRUE;   /* Busy status of the second memory from the parallel pair. */
    
        /* Check the possible IRQ states for a write job executed in interrupt context. */
        if(FLASH_IRQ_JOB_WRITE == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteWrite(&bMemoryIsBusy, &bMemoryIsBusyPar);
        } 
        else if(FLASH_IRQ_JOB_WRITE_EN == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteWriteEnable(&bMemoryIsBusy, &bMemoryIsBusyPar);
        }
    #if( FLS_WRITE_BLANK_CHECK == STD_ON ) 
        else if(FLASH_IRQ_JOB_BLANK_CHECK == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqWriteBlankCheck();
            #if (FLS_DEV_ERROR_DETECT == STD_ON)    
            if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
            {
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                                 FLS_E_VERIFY_ERASE_FAILED 
                                      );
            }
            #endif
        }
    #endif
        else if(FLASH_IRQ_JOB_GET_STATUS == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteGetStatus(&bMemoryIsBusy);
        }
        else if(FLASH_IRQ_JOB_GET_STATUS_PAR == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqWriteGetStatusPar(&bMemoryIsBusyPar);
        }
    #if( FLS_WRITE_VERIFY_CHECK == STD_ON )    
        else if(FLASH_IRQ_JOB_COMPARE == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqWriteCompare();
            #if( FLS_DEV_ERROR_DETECT == STD_ON )    
            if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
            {
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                                 FLS_E_VERIFY_WRITE_FAILED 
                                      );
            }
            #endif
        }
    #endif 
        else /* Error, incorrect IRQ state for a write job. */
        {
            eRetVal = FLASH_E_FAILED;
        } 

        if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                #endif
                    }
    }
    else
    {
        eRetVal = FLASH_E_FAILED;
    }

    
    /* Check if there was any error during processing the job in interrupt context. */
    if(FLASH_E_OK != eRetVal)
    {
        /* There was an error somewhere on the IRQ job processing path. */
        
        /* Abort the IRQ job. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
        
        if(FLASH_E_BLOCK_INCONSISTENT == eRetVal)
        {
            Fls_eLLDJobResult = MEMIF_BLOCK_INCONSISTENT;
        }
        else
        {
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
        
        /* Clear all interrupt flags(w1c) and disable all interrupt sources. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, 
                      ( QSPI_FR_TBFF_U32|QSPI_FR_TBUF_U32|QSPI_FR_ILLINE_U32|QSPI_FR_RBOF_U32|
                        QSPI_FR_RBDF_U32|QSPI_FR_ABSEF_U32|QSPI_FR_AITEF_U32|QSPI_FR_AIBSEF_U32|
                        QSPI_FR_ABOF_U32|QSPI_FR_IUEF_U32|QSPI_FR_IPAEF_U32|QSPI_FR_IPIEF_U32|
                        QSPI_FR_IPGEF_U32|QSPI_FR_TFF_U32 
                       ) 
                      );
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, 
                      ( QSPI_RSER_DLPFIE_U32|QSPI_RSER_TBFIE_U32|QSPI_RSER_TBUIE_U32|QSPI_RSER_ILLINIE_U32|
                        QSPI_RSER_RBOIE_U32|QSPI_RSER_RBDIE_U32|QSPI_RSER_ABSEIE_U32|QSPI_RSER_AITIE_U32|
                        QSPI_RSER_AIBSIE_U32|QSPI_RSER_ABOIE_U32|QSPI_RSER_IUEIE_U32|QSPI_RSER_IPAEIE_U32|
                        QSPI_RSER_IPIEIE_U32|QSPI_RSER_IPGEIE_U32|QSPI_RSER_TFIE_U32 
                       )
                        );                
    }
    
    /* Check if the job was canceled by an Fls_Cancel API call. */
    if(MEMIF_JOB_CANCELED == Fls_eLLDJobResult)
    {
        /* Clear all interrupt flags(w1c) and disable all interrupt sources. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, 
                      ( QSPI_FR_TBFF_U32|QSPI_FR_TBUF_U32|QSPI_FR_ILLINE_U32|QSPI_FR_RBOF_U32|
                        QSPI_FR_RBDF_U32|QSPI_FR_ABSEF_U32|QSPI_FR_AITEF_U32|QSPI_FR_AIBSEF_U32|
                        QSPI_FR_ABOF_U32|QSPI_FR_IUEF_U32|QSPI_FR_IPAEF_U32|QSPI_FR_IPIEF_U32|
                        QSPI_FR_IPGEF_U32|QSPI_FR_TFF_U32 
                       ) 
                      );
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, 
                      ( QSPI_RSER_DLPFIE_U32|QSPI_RSER_TBFIE_U32|QSPI_RSER_TBUIE_U32|QSPI_RSER_ILLINIE_U32|
                        QSPI_RSER_RBOIE_U32|QSPI_RSER_RBDIE_U32|QSPI_RSER_ABSEIE_U32|QSPI_RSER_AITIE_U32|
                        QSPI_RSER_AIBSIE_U32|QSPI_RSER_ABOIE_U32|QSPI_RSER_IUEIE_U32|QSPI_RSER_IPAEIE_U32|
                        QSPI_RSER_IPIEIE_U32|QSPI_RSER_IPGEIE_U32|QSPI_RSER_TFIE_U32 
                      )
                       );                   
    }
}

#else /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */

static FUNC(void, FLS_CODE) Fls_Qspi_ProcessCombinedHyperIrq(void)
{
    VAR(Fls_LLDReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    
    if(FLS_JOB_ERASE == Fls_eJob)
    {
        static VAR(boolean, AUTOMATIC) bMemoryIsBusy    = (boolean)TRUE;   /* Busy status of the memory. */
        
        /* Check the possible IRQ states for an erase job executed in interrupt context. */
        if(FLASH_IRQ_JOB_ERASE == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqEraseErase(&bMemoryIsBusy);
        }
        else if(FLASH_IRQ_JOB_HYPER_GET_STATUS_1 == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqEraseHyperGetStatus1();
        }
        else if(FLASH_IRQ_JOB_HYPER_GET_STATUS_2 == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqEraseHyperGetStatus2(&bMemoryIsBusy);
        }
    #if( FLS_ERASE_BLANK_CHECK == STD_ON )    
        else if(FLASH_IRQ_JOB_BLANK_CHECK == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqEraseBlankCheck();
            #if (FLS_DEV_ERROR_DETECT == STD_ON)    
            if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
            {
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                                 FLS_E_VERIFY_ERASE_FAILED 
                                      );
            }
            #endif
        }
    #endif     
        else /* Error, incorrect IRQ state for an erase job. */
        {
            eRetVal = FLASH_E_FAILED;
        }
        
        if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                #endif
                    }
    }
    else if(FLS_JOB_READ == Fls_eJob)
    {
        /* Check the possible IRQ states for a read job executed in interrupt context. */
        if(FLASH_IRQ_JOB_READ == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqReadRead();
        }   
        else /* Error, incorrect IRQ state for a read job. */
        {
            eRetVal = FLASH_E_FAILED;
        }
        
        if(FLASH_E_FAILED == eRetVal)
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_READ_FAILED);
                #endif
                    }
    }
    else if(FLS_JOB_COMPARE == Fls_eJob)   
    {
        /* Check the possible IRQ states for a read job executed in interrupt context. */
        if(FLASH_IRQ_JOB_COMPARE == Fls_eLLDIrqJob)
        {              
            eRetVal = Fls_Qspi_IrqReadCompare();
        }
        else /* Error, incorrect IRQ state for a read job. */
        {
            eRetVal = FLASH_E_FAILED;
        }
        
        if(FLASH_E_FAILED == eRetVal)
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_COMPARE_FAILED);
                #endif
                    }
    }
#if( FLS_BLANK_CHECK_API == STD_ON ) 
    else if(FLS_JOB_BLANK_CHECK == Fls_eJob)
    {   
        if(FLASH_IRQ_JOB_BLANK_CHECK == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqReadBlankCheck();
        }   
        else /* Error, incorrect IRQ state for a read job. */
        {
            eRetVal = FLASH_E_FAILED;
        }
        
        if(FLASH_E_FAILED == eRetVal)
        {
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_COMPARE_FAILED);
            #endif 
        }
    }
#endif /*#if( FLS_BLANK_CHECK_API == STD_ON )*/ 
    else if(FLS_JOB_WRITE == Fls_eJob)
    {
        static VAR(boolean, AUTOMATIC) bMemoryIsBusy = (boolean)TRUE;       /* Busy status of the external memory. */
                
        /* Check the possible IRQ states for a write job executed in interrupt context. */
        if(FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_1 == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteHyperUnlock1();
        } 
        else if(FLASH_IRQ_JOB_HYPER_WRITE_UNLOCK_2 == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteHyperUnlock2();
        }
        else if(FLASH_IRQ_JOB_HYPER_WRITE_WORD_ID == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteHyperWordId();
        }
        else if(FLASH_IRQ_JOB_HYPER_WRITE_WORD_DATA == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteHyperWordData(&bMemoryIsBusy);
        }
        else if(FLASH_IRQ_JOB_HYPER_GET_STATUS_1 == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteHyperGetStatus1();
        }
        else if(FLASH_IRQ_JOB_HYPER_GET_STATUS_2 == Fls_eLLDIrqJob)
        {   
            eRetVal = Fls_Qspi_IrqWriteHyperGetStatus2(&bMemoryIsBusy);
        }
    #if( FLS_WRITE_BLANK_CHECK == STD_ON ) 
        else if(FLASH_IRQ_JOB_BLANK_CHECK == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqWriteBlankCheck();
            #if (FLS_DEV_ERROR_DETECT == STD_ON)    
            if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
            {
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                                 FLS_E_VERIFY_ERASE_FAILED 
                                      );
            }
            #endif
        }
    #endif 
    #if( FLS_WRITE_VERIFY_CHECK == STD_ON )    
        else if(FLASH_IRQ_JOB_COMPARE == Fls_eLLDIrqJob)
        {
            eRetVal = Fls_Qspi_IrqWriteCompare();
            #if( FLS_DEV_ERROR_DETECT == STD_ON )    
            if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
            {
                (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                                 FLS_E_VERIFY_WRITE_FAILED 
                                      );
            }
            #endif
        }
    #endif
        else /* Error, incorrect IRQ state for a write job. */
        {
            eRetVal = FLASH_E_FAILED;
        } 

        if( (FLASH_E_FAILED == eRetVal) || (FLASH_E_BLOCK_INCONSISTENT == eRetVal) )
        {
                            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                #endif
                    }
    }
    else /* Error, incorrect FLS job. */
    {
        eRetVal = FLASH_E_FAILED;
    }

    
    /* Check if there was any error during processing the job in interrupt context. */
    if(FLASH_E_OK != eRetVal)
    {
        /* There was an error somewhere on the IRQ job processing path. */
        
        /* Abort the IRQ job. */
        Fls_eLLDIrqJob = FLASH_IRQ_JOB_NONE;
        
        if(FLASH_E_BLOCK_INCONSISTENT == eRetVal)
        {
            Fls_eLLDJobResult = MEMIF_BLOCK_INCONSISTENT;
        }
        else
        {
            Fls_eLLDJobResult = MEMIF_JOB_FAILED;
        }
        
        /* Clear all interrupt flags(w1c) and disable all interrupt sources. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, 
                      ( QSPI_FR_TBFF_U32|QSPI_FR_TBUF_U32|QSPI_FR_ILLINE_U32|QSPI_FR_RBOF_U32|
                        QSPI_FR_RBDF_U32|QSPI_FR_ABSEF_U32|QSPI_FR_AITEF_U32|QSPI_FR_AIBSEF_U32|
                        QSPI_FR_ABOF_U32|QSPI_FR_IUEF_U32|QSPI_FR_IPAEF_U32|QSPI_FR_IPIEF_U32|
                        QSPI_FR_IPGEF_U32|QSPI_FR_TFF_U32 
                       ) 
                      );
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, 
                      ( QSPI_RSER_DLPFIE_U32|QSPI_RSER_TBFIE_U32|QSPI_RSER_TBUIE_U32|QSPI_RSER_ILLINIE_U32|
                        QSPI_RSER_RBOIE_U32|QSPI_RSER_RBDIE_U32|QSPI_RSER_ABSEIE_U32|QSPI_RSER_AITIE_U32|
                        QSPI_RSER_AIBSIE_U32|QSPI_RSER_ABOIE_U32|QSPI_RSER_IUEIE_U32|QSPI_RSER_IPAEIE_U32|
                        QSPI_RSER_IPIEIE_U32|QSPI_RSER_IPGEIE_U32|QSPI_RSER_TFIE_U32 
                      )
                        );                
    }
    
    /* Check if the job was canceled by an Fls_Cancel API call. */
    if(MEMIF_JOB_CANCELED == Fls_eLLDJobResult)
    {
        /* Clear all interrupt flags(w1c) and disable all interrupt sources. */
        REG_BIT_SET32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_FR_OFFSET_U32, 
                      ( QSPI_FR_TBFF_U32|QSPI_FR_TBUF_U32|QSPI_FR_ILLINE_U32|QSPI_FR_RBOF_U32|
                        QSPI_FR_RBDF_U32|QSPI_FR_ABSEF_U32|QSPI_FR_AITEF_U32|QSPI_FR_AIBSEF_U32|
                        QSPI_FR_ABOF_U32|QSPI_FR_IUEF_U32|QSPI_FR_IPAEF_U32|QSPI_FR_IPIEF_U32|
                        QSPI_FR_IPGEF_U32|QSPI_FR_TFF_U32 
                       ) 
                      );
        REG_BIT_CLEAR32(Fls_Qspi_u32HwUnitBaseAddr + QSPI_RSER_OFFSET_U32, 
                      ( QSPI_RSER_DLPFIE_U32|QSPI_RSER_TBFIE_U32|QSPI_RSER_TBUIE_U32|QSPI_RSER_ILLINIE_U32|
                        QSPI_RSER_RBOIE_U32|QSPI_RSER_RBDIE_U32|QSPI_RSER_ABSEIE_U32|QSPI_RSER_AITIE_U32|
                        QSPI_RSER_AIBSIE_U32|QSPI_RSER_ABOIE_U32|QSPI_RSER_IUEIE_U32|QSPI_RSER_IPAEIE_U32|
                        QSPI_RSER_IPIEIE_U32|QSPI_RSER_IPGEIE_U32|QSPI_RSER_TFIE_U32 
                       )
                        );                   
    }    
}

#endif /* #if(FLS_QSPI_HYPERFLASH_MODE == STD_OFF) */

#endif /* #if(FLS_USE_INTERRUPTS == STD_ON) */

#endif /*#if (STD_ON == FLS_QSPI_SECTORS_CONFIGURED)*/
#endif /*#if (STD_ON == FLS_QSPI_FLASH_AVAILABLE) */


/**
* @brief    Stop of Fls section CODE 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_qspi_irq_c_REF_3 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_qspi_irq_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
