/**
*   @file    Adc_Pdb_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - low level driver source file.
*   @details This is the low level driver source file,mainly implemented for the ADC12BSAR hardware IP.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Pdb_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Pdb_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_Pdb_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as an
* unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Pdb_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Pdb_Irq_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Pdb_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Pdb_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared 
* in one and only one file.
* These objects are used in several files in the code.
*
* @section Adc_Pdb_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be 
* implicitly converted to a different underlying type
*
* @section Adc_Pdb_Irq_c_REF_9
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Adc_Pdb.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#endif
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_AR_VENDOR_ID_PDB_IRQ_C                 43
/** @violates @ref Adc_Pdb_Irq_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MAJOR_VERSION_PDB_IRQ_C     4
/** @violates @ref Adc_Pdb_Irq_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MINOR_VERSION_PDB_IRQ_C     2
/** @violates @ref Adc_Pdb_Irq_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_PDB_IRQ_C  2
#define ADC_SW_MAJOR_VERSION_PDB_IRQ_C             1
#define ADC_SW_MINOR_VERSION_PDB_IRQ_C             0
#define ADC_SW_PATCH_VERSION_PDB_IRQ_C             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Adc_Pdb header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_PDB_IRQ_C != ADC_PDB_VENDOR_ID_REG)
    #error "Adc_Pdb_Irq.c and Adc_Pdb.h have different vendor ids"
#endif

/* Check if source file and Adc_Pdb header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION_PDB) \
    )
    #error "AutoSar Version Numbers of Adc_Pdb_Irq.c and Adc_Pdb.h are different"
#endif

/* Check if source file and Adc_Pdb header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PDB_IRQ_C != ADC_SW_MAJOR_VERSION_PDB) || \
     (ADC_SW_MINOR_VERSION_PDB_IRQ_C != ADC_SW_MINOR_VERSION_PDB) || \
     (ADC_SW_PATCH_VERSION_PDB_IRQ_C != ADC_SW_PATCH_VERSION_PDB) \
    )
    #error "Software Version Numbers of Adc_Pdb_Irq.c and Adc_Pdb.h are different"
#endif

/** @violates @ref Adc_Pdb_Irq_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_PDB_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Pdb_Irq.c and Mcal.h are different"
 #endif 
 /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_IRQ_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_PDB_IRQ_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Pdb_Irq.c and SilRegMacros.h are different"
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
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Pdb_Irq_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Pdb_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

/**
* @brief          Used to point the configuration structure.
*/
/** @violates @ref Adc_Pdb_Irq_c_REF_7  External object declared more than once*/
extern P2CONST(Adc_ConfigType , ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Pdb_Irq_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Pdb_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_Pdb_Irq_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Pdb_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

#if (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED))
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Pdb_ChannelSequenceError
(
    VAR(uint8, AUTOMATIC) u8Unit
);
#ifdef ADC_DMA_SUPPORTED
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Pdb_ReConfigureDma
(
    VAR(uint8, AUTOMATIC) u8Unit
);
#endif /* ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF */
#endif /* ADC_DMA_SUPPORTED */
#endif


#ifdef ADC_UNIT_0_PDB_ERR_ISR_USED
ISR(Adc_Pdb_ChannelSequenceError0);
#endif

#ifdef ADC_UNIT_1_PDB_ERR_ISR_USED
ISR(Adc_Pdb_ChannelSequenceError1);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (defined(ADC_UNIT_0_PDB_ERR_ISR_USED) || defined(ADC_UNIT_1_PDB_ERR_ISR_USED))
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Pdb_ChannelSequenceError
(
    VAR(uint8, AUTOMATIC) u8Unit
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(uint32, AUTOMATIC) u32TempSC;

    /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    if(REG_READ32(PDB_CHnS_REG_ADDR32(u8Unit, 0U)) & PDB_ERR_FLAGS_MASK_U32)
    {
        /* Restore the value from SC register */
        /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        u32TempSC = REG_READ32(PDB_SC_REG_ADDR32(u8Unit));
        /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_SC_REG_ADDR32(u8Unit), (u32TempSC & (~PDB_ENABLED_U32)));
        /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_CHnS_REG_ADDR32(u8Unit, 0U), PDB_ERR_FLAGS_CLEAR_U32);
        
        if(NULL_PTR != Adc_pCfgPtr)
        {
            #ifdef ADC_DMA_SUPPORTED
              #if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
                if((uint8)ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[u8Unit])
                {
                    Adc_Pdb_ReConfigureDma(u8Unit);
                }
              #endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
            #endif /* ADC_DMA_SUPPORTED */
            
            /* Re-Configure SC register */
            /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(PDB_SC_REG_ADDR32(u8Unit), u32TempSC);
            
            HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[u8Unit];
            /** @violates @ref Adc_Pdb_Irq_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
            if(NULL_PTR != Adc_pCfgPtr->pAdc[HwIndex].pPdbNofitication)
            {
                /** @violates @ref Adc_Pdb_Irq_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                Adc_pCfgPtr->pAdc[HwIndex].pPdbNofitication();
            }
            /** @violates @ref Adc_Pdb_Irq_c_REF_9 Return statement before end of function. */
            return;
        }
        /* Re-Configure SC register */
        /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_SC_REG_ADDR32(u8Unit), u32TempSC);
    }
}

#ifdef ADC_DMA_SUPPORTED
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Pdb_ReConfigureDma
(
    VAR(uint8, AUTOMATIC) u8Unit
)
{
    VAR(Adc_GroupType, AUTOMATIC) Group;
    VAR(uint8, AUTOMATIC) u8ScRegister;
    VAR(uint32, AUTOMATIC) u8ScValue;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;
    VAR(Adc_ChannelIndexType, AUTOMATIC) CurrentChannel;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32Timeout = ADC_DMA_TRANSFER_TIMEOUT;
    
#if (ADC_HW_TRIGGER_API == STD_ON)
    if (Adc_aUnitStatus[u8Unit].HwNormalQueueIndex > 0U)
    {
        Group = Adc_aUnitStatus[u8Unit].HwNormalQueue[0];
    }
    else
#endif
    {
        Group = Adc_aUnitStatus[u8Unit].SwNormalQueue[0];
    }

    /** @violates @ref Adc_Pdb_Irq_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
    if((uint8)STD_ON == Adc_pCfgPtr->pGroups[Group].u8AdcGroupChannelDelays)
    {
        for(u8ScRegister = 0U; u8ScRegister < Adc_aUnitStatus[u8Unit].u8Sc1Used; u8ScRegister++)
        {
            /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            u8ScValue = REG_READ32(ADC12BSARV2_SC1_REG_ADDR32(u8Unit, (uint32)u8ScRegister));
            /* Aborts the current conversion */
            /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(u8Unit, (uint32)u8ScRegister), u8ScValue);
            /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(u8Unit, (uint32)u8ScRegister));
        }        
    }
    
    CurrentChannel = (Adc_ChannelIndexType)ADC_PRE_CHANNEL_INDEX(Adc_aGroupStatus[Group].CurrentChannel);
    DmaChannel = (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[u8Unit];
    /** @violates @ref Adc_Pdb_Irq_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
    pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex + (CurrentChannel * Adc_pCfgPtr->pGroups[Group].NumSamples);
    
    /* waiting dma transfering finished before update new setting */
    while((boolean)TRUE == Mcl_DmaIsTransferActive(DmaChannel))
    {
        if(u32Timeout > 0UL)
        {
            u32Timeout--;
        }
        else
        {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            /** @violates @ref Adc_Pdb_Irq_c_REF_9 Return statement before end of function. */
            return;
        }
    }
    /** @violates @ref Adc_Pdb_Irq_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_Irq_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    Mcl_DmaTcdSetDaddr(Adc_Adc12bsarv2_aTcdAddress[u8Unit], (uint32)pResult);
    Mcl_DmaTcdSetSaddr(Adc_Adc12bsarv2_aTcdAddress[u8Unit], (uint32)(Adc_Adc12bsarv2_aDmaTcdConfig[u8Unit].u32saddr));
    /** @violates @ref Adc_Pdb_Irq_c_REF_8 the value of an expression of integer is converted to a different type */
    Mcl_DmaUpdateIterCount(DmaChannel, Adc_Adc12bsarv2_aDmaTcdConfig[u8Unit].u32iter);
}
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#endif /* ADC_DMA_SUPPORTED */
#endif
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef ADC_UNIT_0_PDB_ERR_ISR_USED
ISR(Adc_Pdb_ChannelSequenceError0)
{
    Adc_Pdb_ChannelSequenceError(0U);
}
#endif

#ifdef ADC_UNIT_1_PDB_ERR_ISR_USED
ISR(Adc_Pdb_ChannelSequenceError1)
{
    Adc_Pdb_ChannelSequenceError(1U);
}
#endif

#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_Pdb_Irq_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Pdb_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
