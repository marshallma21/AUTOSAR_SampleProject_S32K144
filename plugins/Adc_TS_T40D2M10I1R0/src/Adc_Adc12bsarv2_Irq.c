/**
*   @file    Adc_Adc12bsarv2_Irq.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - ADC12BSARV2 Interrupt source file.
*   @details  Autosar Adc Interrupt source file.
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
* @section Adc_Adc12bsarv2_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_9
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as an
* unsigned int is passed to a amcro for initializing the pointer with that address.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_11
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation occurs because of the interaction with MCL module or because of  ISR symbols that
* need to be exported
*
* @section Adc_Adc12bsarv2_Irq_c_REF_12
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* This violation cannot be removed due to the interaction with MCL module.
*
* @section Adc_Adc12bsarv2_Irq_c_REF_13
* Violates MISRA 2004 Required Rule 10.3, Cast from unsign interger to sign interger
* This is used for calculate the dma source/destination last
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
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc_Ipw.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#endif
#include "SilRegMacros.h"
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_2 Repeated include file  */
#include "Mcal.h"
#include "SchM_Adc.h"

#ifdef ADC_DMA_SUPPORTED
#include "CDD_Mcl.h"
#endif

#include "Adc_Pdb.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_AR_VENDOR_ID_ADC12BSARV2_IRQ_C                 43
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#define ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C     4
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#define ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C     2
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#define ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_IRQ_C  2
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#define ADC_SW_MAJOR_VERSION_ADC12BSARV2_IRQ_C             1
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#define ADC_SW_MINOR_VERSION_ADC12BSARV2_IRQ_C             0
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#define ADC_SW_PATCH_VERSION_ADC12BSARV2_IRQ_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and ADC IPW header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_IRQ_C != ADC_VENDOR_ID_IPW_H)
    #error "Adc_Adc12bsarv2_Irq.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC IPW header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_IRQ_C != ADC_SW_MAJOR_VERSION_IPW_H) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_IRQ_C != ADC_SW_MINOR_VERSION_IPW_H) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_IRQ_C != ADC_SW_PATCH_VERSION_IPW_H) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if source file and Adc_Pdb header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADC12BSARV2_IRQ_C != ADC_VENDOR_ID_PDB)
    #error "Adc_Adc12bsarv2_Irq.c and Adc_Pdb.h have different vendor ids"
#endif

/* Check if source file and Adc_Pdb header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADC12BSARV2_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION_PDB) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2_Irq.c and Adc_Pdb.h are different"
#endif

/* Check if source file and Adc_Pdb header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADC12BSARV2_IRQ_C != ADC_SW_MAJOR_VERSION_PDB) || \
     (ADC_SW_MINOR_VERSION_ADC12BSARV2_IRQ_C != ADC_SW_MINOR_VERSION_PDB) || \
     (ADC_SW_PATCH_VERSION_ADC12BSARV2_IRQ_C != ADC_SW_PATCH_VERSION_PDB) \
    )
    #error "Software Version Numbers of Adc_Adc12bsarv2_Irq.c and Adc_Pdb.h are different"
#endif
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and SilRegMacros header file are of the same version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2_Irq.c and SilRegMacros.h are different"
#endif

/* Check if source file and Mcal header file are of the same version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2_Irq.c and Mcal.h are different"
#endif


#ifdef ADC_DMA_SUPPORTED
/* Check if source file and CDD_Mcl header file are of the same version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C != MCL_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2_Irq.c and CDD_Mcl.h are different"
#endif

/* Check if source file and Mcl_Types header file are of the same version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADC12BSARV2_IRQ_C != MCL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADC12BSARV2_IRQ_C != MCL_TYPES_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Adc12bsarv2_Irq.c and Mcl_Types.h are different"
#endif

#endif /* ADC_DMA_SUPPORTED */

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON)
    #define ADC12BSARV2_DMA_SERQ_REG_ADDR32  (0x4000801BU)
    #define ADC12BSARV2_DMA_CERQ_REG_ADDR32  (0x4000801AU)
#endif
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

#define ADC_START_SEC_CODE
/**
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"

#ifdef ADC_UNIT_0_ISR_USED
ISR(Adc_Adc12bsarv2_EndGroupConvUnit0);
#endif

#ifdef ADC_UNIT_1_ISR_USED
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
ISR(Adc_Adc12bsarv2_EndGroupConvUnit1);
#endif

#ifdef ADC_DMA_SUPPORTED
#ifdef ADC_UNIT_0
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_12 Function decalration */
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaTransferComplete0(void);
#endif /* ADC_UNIT_0 */
#ifdef ADC_UNIT_1
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash */
/** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_12 Function decalration */
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaTransferComplete1(void);
#endif /* ADC_UNIT_1 */
#endif /* ADC_DMA_SUPPORTED */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)))
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EndPartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bNormalconversion
);
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_CheckPartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_HwSwCheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateLimitCheckFailed
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(uint8, AUTOMATIC) u8NumChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(boolean, AUTOMATIC) bNormalconversion
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StopConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_RestartContinuousConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateSoftwareGroupState
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
);
#if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateHardwareGroupState
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#endif /* ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED))) */

#ifdef ADC_DMA_SUPPORTED
#if defined(ADC_UNIT_0) || defined(ADC_UNIT_1)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaEndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EndDmaPartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bSoftwareConversion
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaCheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaEndNormalConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StopDmaAndConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel
);
#if (ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaEndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaUpdateDaddr
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
LOCAL_INLINE FUNC (Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_TransferToInternalBuffer
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateDmaLimitCheckFailed
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger
);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#endif /* defined(ADC_UNIT_0) || defined(ADC_UNIT_1) */
#endif /* ADC_DMA_SUPPORTED */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || (defined(ADC_DMA_SUPPORTED)))
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
LOCAL_INLINE FUNC(boolean, ADC_CODE) Adc_Adc12bsarv2_CheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateQueue
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)))
/**
* @brief          This function handles the ISR for the conversion.
* @details        The function handles the ISR for the given hardware Unit.
*                 It's used on both ADC Hardware units.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_Adc12bsarv2_EndGroupConversion_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint8, AUTOMATIC) u8ResultReg;
    VAR(uint32, AUTOMATIC) u32SC1Value = 0UL;
    VAR(boolean, AUTOMATIC) bIsSpurious = (boolean)TRUE;

    /* Check if conversion complete interrupt of the last channel to indicate end of chain complete */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    for(u8ResultReg = 0U; u8ResultReg < Adc_aUnitStatus[Unit].u8Sc1Used; u8ResultReg++)
    {
        /* Read SC1n registers */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32SC1Value |= REG_READ32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8ResultReg));

        /* Check interrupt enable bit in SC1 */
        if(ADC12BSARV2_CONV_COMPLETE_INT_EN_U32 == (u32SC1Value & ADC12BSARV2_CONV_COMPLETE_INT_EN_U32))
        {
            break;
        }
    }

    if(NULL_PTR != Adc_pCfgPtr)
    {
        /* If Adc hardware enabled interrupt */
        if (ADC12BSARV2_CONV_COMPLETE_INT_EN_U32 == (u32SC1Value & ADC12BSARV2_CONV_COMPLETE_INT_EN_U32))
        {
#if (ADC_HW_TRIGGER_API == STD_ON)
            /* Check if requests are available in queue */
            if (Adc_aUnitStatus[Unit].HwNormalQueueIndex > (Adc_QueueIndexType)0)
            {
                Adc_Adc12bsarv2_EndPartialConversion(Unit, Adc_aUnitStatus[Unit].HwNormalQueue[0], (boolean)FALSE);

                /* Interrupt is not spurious */
                bIsSpurious = (boolean)FALSE;
            }
            else
#endif
            if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0)
            {
                Adc_Adc12bsarv2_EndPartialConversion(Unit, Adc_aUnitStatus[Unit].SwNormalQueue[0], (boolean)TRUE);

                /* Interrupt is not spurious */
                bIsSpurious = (boolean)FALSE;
            }

#if (ADC_HW_TRIGGER_API == STD_ON)
            else
            {
                /* do nothing for misra */
            }
#endif
        }
    }

    /* If there is no flag enabled, it's a spurious interrupt */
    /* Clear all of COCO flag by reading Rn registers */
    if((boolean)TRUE == bIsSpurious)
    {
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        for(u8ResultReg = 0U; u8ResultReg < ADC_NUM_SC1n_REGISTER; u8ResultReg++)
        {
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer. */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)u8ResultReg));
        }
    }
}

/**
* @brief          This function handles the normal conversion ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_Adc12bsarv2_EndPartialConversion_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EndPartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bNormalconversion
)
{
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    VAR(Adc_ChannelIndexType, AUTOMATIC) NumChannel;
    VAR(uint8, AUTOMATIC) u8LeftChannel;
#endif
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */

    /* Get the group configuration */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);

    /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14();

    /* Limit checking */
    if ((Std_ReturnType)E_OK == Adc_Adc12bsarv2_CheckPartialConversion(Unit, Group, pGroupPtr->NumSamples))
    {
    /* Get the number of channel configured in group */
    #if (ADC_SETCHANNEL_API == STD_ON)
        /* Channels configured at runtime */
        ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
    #else
        /* Channels configured when initializing */
        ChannelCount = pGroupPtr->AssignedChannelCount;
    #endif
    #if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
        /* Following code will not be reduced when oneshot hardware trigger optimization is not enabled */

        /* More channels in group */
        if (Adc_aGroupStatus[Group].CurrentChannel < ChannelCount)
        {
            /* Get left channel */
            NumChannel = ChannelCount - Adc_aGroupStatus[Group].CurrentChannel;

            /* In case of left channels excess maximum allowed channels */
            u8LeftChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(NumChannel);

            /* Configure left channels and Start more conversion */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, pGroupPtr, PDB_SOFTWARE_TRIGGER_U32, u8LeftChannel);

            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
        }
        /* All of channels converted */
        else
    #endif
        {
    #if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
            if (pGroupPtr->ExtraNotification != NULL_PTR)
            {
                /* Extra notification have to invoked out of exclusive area */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();

                /* User notification is used to update registers when using Adc_SetChannel API */
                pGroupPtr->ExtraNotification();

                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14();
            }
    #endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */

    #if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON)
            Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;

        #if (ADC_SETCHANNEL_API == STD_ON)

            /* Check if channels are updated at runtime */
            if ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated)
            {
                Adc_aGroupStatus[Group].CurrentChannel = 0U;

                /* Configure left channels if needed */
                /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, pGroupPtr, (Adc_HwTriggerTimerType)pGroupPtr->pHwResource[0U], (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(ChannelCount));

                /* Reset the update status */
                Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean) FALSE;
            }
        #else

            /* Avoid compiler warning */
            (void)ChannelCount;

        #endif  /* (ADC_SETCHANNEL_API == STD_ON) */

            /* Check notification of a group and call the notification function if needed */
            Adc_Adc12bsarv2_HwSwCheckNotification (Group);

    #else   /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

            /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
            Adc_aGroupStatus[Group].ResultIndex++;

            /* Update state following AutoSar diagrams */
            if ((boolean)TRUE == bNormalconversion)
            {
                Adc_Adc12bsarv2_UpdateSoftwareGroupState(Unit, Group, pGroupPtr->NumSamples);
            }
        #if (ADC_HW_TRIGGER_API == STD_ON)
            else
            {
                Adc_Adc12bsarv2_UpdateHardwareGroupState(Unit, Group, pGroupPtr->NumSamples);
            }
        #endif  /* (ADC_HW_TRIGGER_API == STD_ON) */
    #endif  /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) */
        }
    }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
        Adc_Adc12bsarv2_UpdateLimitCheckFailed(Unit, Group, 1U, pGroupPtr, bNormalconversion);
         /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
    }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    (void)bNormalconversion;
}

LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_CheckPartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) CurrentChannel = Adc_aGroupStatus[Group].CurrentChannel;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Temp;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Index;
    VAR(uint32, AUTOMATIC) u32AdcDataValue;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(uint32, AUTOMATIC) u32AdcDataMask;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    VAR(Adc_ChannelType, AUTOMATIC) HwChannel;
    VAR(boolean, AUTOMATIC) bFlag = (boolean)FALSE;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */

    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#endif
    /* record the result of the Channel conversion and update group status */
#if (ADC_SETCHANNEL_API == STD_ON)
    Index = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Index = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif

    if(CurrentChannel <= Index)
    {
        /* Get the logical id of hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];

        /* Calculate the index of the first channel in the previous configuration */
        Temp = (Adc_ChannelIndexType)ADC_PRE_CHANNEL_INDEX(CurrentChannel);
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        u32AdcDataMask = Adc_pCfgPtr->pAdc[HwIndex].u32AdcDataMask;
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex;
        /* For each of channels in the list of previous configuration, read data and take result into user buffer */
        for(Index = Temp; Index < CurrentChannel; Index++)
        {
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u32AdcDataValue = REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, ((uint32)Index - (uint32)Temp)));
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            HwChannel = Adc_pCfgPtr->pGroups[Group].pAssignment[Index];
            if ((boolean)TRUE == pGroupPtr->bAdcGroupLimitcheck)
            {
                bFlag = (boolean)Adc_CheckConversionValuesInRange((uint16)u32AdcDataValue, Unit, HwChannel);
                if ((boolean)TRUE == bFlag)
                {
                    /**
                    * @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                    */
                    *(pResult+((Index)*(GroupSamples))) = (uint16)(u32AdcDataValue & u32AdcDataMask);
                    Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
                }
                else
                {
                    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
                    Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)TRUE;
                    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_4 Return statement before end of function. */
                    return (Std_ReturnType)E_NOT_OK;
                }
            }
            else
            {
                /**
                * @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                */
                *(pResult + ((Index) * GroupSamples)) = (uint16)(u32AdcDataValue & u32AdcDataMask);
            }
#else
            /**
            * @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            */
            *(pResult + ((Index) * GroupSamples)) = (uint16)(u32AdcDataValue & u32AdcDataMask);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
        }
    }
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_4 Return statement before end of function. */
    return (Std_ReturnType)E_OK;
}

/**
* @brief          Check notification of a group for either hardware or software
* @details        Check notification of a group and call the notification function if needed.
*
* @param[in]      Group            The group number.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_HwSwCheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(boolean, AUTOMATIC)  bCallNotification = (boolean)FALSE;

    /* Check if notification function */
    bCallNotification = Adc_Adc12bsarv2_CheckNotification(Group);
#endif

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    if ((boolean)TRUE == bCallNotification)
    {
        /* Execute notification function */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_pCfgPtr->pGroups[Group].Notification();
    }
#else

    /* Avoid compiler warning */
    (void)Group;
#endif
}

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateLimitCheckFailed
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(uint8, AUTOMATIC) u8NumChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(boolean, AUTOMATIC) bNormalconversion
)
{
    if ((boolean)TRUE == bNormalconversion)
    {
        /* Group configured as one-shot mode and limit checking failed will be stop */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode)
        {
            Adc_Adc12bsarv2_StopConversion(Unit);
        }
        /* Group configured as continuous will be re-configured*/
        else
        {
            Adc_aGroupStatus[Group].CurrentChannel = 0U;
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, pGroupPtr, PDB_SOFTWARE_TRIGGER_U32, u8NumChannel);
        }
    }
}

/**
* @brief          Stop conversion of ADC hardware unit
* @details        Stop conversion of ADC hardware unit by disabling all current channels,
*                   reset interrupt mask and flags
*
* @param[in]      Group            The group number.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StopConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint8, AUTOMATIC) u8SCRegister;
    /* Disable Adc hardware unit and clear all of COCO bit by reading Rn registers */
    for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)u8SCRegister));
    }
}
#endif

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function restart conversion
* @details        This function restart conversion in case of streaming access mode is enabled
*
* @param[in]      Unit            ADC hardware unit
* @param[in]      Group           ADC group number
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_RestartContinuousConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(uint8, AUTOMATIC) u8NumChannel;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get channel count in case of changing at runtime */
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /* Get channel count from configuration */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif

    /* Get left channel from channel count */
    u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(ChannelCount);

    /* Incase of the number of channels in group less than the SC1 register used then update group status and start Pdb */
    if(ChannelCount <= ADC_NUM_SC1n_REGISTER_USED)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        /* Configure again Adc hardware unit in case of channels of group configured */
        if ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated)
        {
            Adc_aGroupStatus[Group].CurrentChannel = 0U;

            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */

            /* Re-configure group channels and trigger PDB by software */
            Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, &(Adc_pCfgPtr->pGroups[Group]), PDB_SOFTWARE_TRIGGER_U32, u8NumChannel);

            /* Reset runtime update status */
            Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean) FALSE;
        }
        else
#endif  /* (ADC_SETCHANNEL_API == STD_ON) */
        {
            /* No need to re-configure channels if they are not changed */
            /* End of chain interrupt (if used) is still in last channel (= ChannelCount) */
            Adc_aGroupStatus[Group].CurrentChannel = ChannelCount;

            /* Trigger PDB by software */
            Adc_Pdb_StartSoftwareConversion(Unit);
        }
    }
    /* Incase of the number of channels greater than 8, re-configure Adc hardware unit for the next conversion */
    else
    {
        Adc_aGroupStatus[Group].CurrentChannel = 0U;

        /* Re-configure other segment channels of groups And start next conversion*/
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_Adc12bsarv2_ConfigurePartialConversion(Unit, Group, &(Adc_pCfgPtr->pGroups[Group]), PDB_SOFTWARE_TRIGGER_U32, u8NumChannel);
    }
}

/**
* @brief          This function update state of software conversion according to AutoSar diagrams
* @details        This function update state of software conversion according to AutoSar diagrams
*                   Depending on the configuration, this function might implement other stuff include:
*                    - Start next conversion: in case of continuous conversion mode or update queue
*                    - Implement notification function (if available)
*
* @param[in]      Unit            ADC hardware unit
* @param[in]      Group           ADC group number
* @param[in]      GroupSamples    Number of samples per channel in streaming access mode
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateSoftwareGroupState
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
)
{
    /* At least once the group was converted */
    /* It's already check for validation */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;

    /* Change when configuration is ADC streaming access mode */
    if(ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
    }

    /* If buffer is full of samples */
    if (Adc_aGroupStatus[Group].ResultIndex >= GroupSamples)
    {
        /* Change to stream complete according to AutoSar diagram */
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;

        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode) && \
           (ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode) \
          )
        {
            /* Update queue and execute new start conversion request from queue if available */
            Adc_Adc12bsarv2_UpdateQueue(Unit);

            /* Check user notification function and execute if available */
            Adc_Adc12bsarv2_HwSwCheckNotification(Group);
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
        else
        {
            /* ADC_ACCESS_MODE_STREAMING && ADC_STREAM_BUFFER_CIRCULAR */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if (ADC_CONV_MODE_CONTINUOUS == Adc_pCfgPtr->pGroups[Group].eMode)
            {
                /* Restart new continuous conversion */
                Adc_aGroupStatus[Group].ResultIndex = 0U;
                Adc_Adc12bsarv2_RestartContinuousConversion(Unit, Group);
            }
            else /* (ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode) */
            {
                /* Update queue and execute new request from queue if available */
                Adc_Adc12bsarv2_UpdateQueue(Unit);
            }
        }
    }
    else
    {
        /* Need to restart conversion until buffer is full */
        Adc_Adc12bsarv2_RestartContinuousConversion(Unit, Group);
    }

    /* Implement user notification function if available */
    Adc_Adc12bsarv2_HwSwCheckNotification(Group);
}

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function update state of hardware conversion according to AutoSar diagrams
* @details        This function update state of hardware conversion according to AutoSar diagrams
*                   Depending on the configuration, this function might implement other stuff include:
*                    - Start next conversion: in case of continuous conversion mode or update queue
*                    - Implement notification function (if available)
*
* @param[in]      Unit            ADC hardware unit
* @param[in]      Group           ADC group number
* @param[in]      GroupSamples    Number of samples per channel in streaming access mode
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateHardwareGroupState
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif

    /* At least once the group was converted */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;

    if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
    }

    if (Adc_aGroupStatus[Group].ResultIndex >= GroupSamples)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode) && \
           (ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode)
          )
        {
            Adc_aUnitStatus[Unit].HwNormalQueueIndex = 0U;
            Adc_Adc12bsarv2_HwSwCheckNotification (Group);
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
        Adc_aGroupStatus[Group].ResultIndex = 0U;
    }

    if((ChannelCount > ADC_NUM_SC1n_REGISTER_USED)
    #if (ADC_SETCHANNEL_API == STD_ON)
       || ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated)
    #endif /* (ADC_SETCHANNEL_API == STD_ON) */
      )
    {
        Adc_Adc12bsarv2_StartHwTrigConversion(Unit, Group);
    }

    Adc_Adc12bsarv2_HwSwCheckNotification (Group);
}
#endif
#endif
#endif

#ifdef ADC_DMA_SUPPORTED
#if defined(ADC_UNIT_0) || defined(ADC_UNIT_1)
/**
* @brief          This function handles the ISR processing function for the
*                 DMA conversions.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_Adc12bsarv2_DmaEndGroupConversion_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaEndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Adc_GroupType, AUTOMATIC) Group = (Adc_GroupType)0;

    if(NULL_PTR != Adc_pCfgPtr)
    {
        /* Enter critical region */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();

#if(STD_ON == ADC_HW_TRIGGER_API)
        if (Adc_aUnitStatus[Unit].HwNormalQueueIndex > 0U)
        {
            Group = Adc_aUnitStatus[Unit].HwNormalQueue[0];
            Adc_Adc12bsarv2_EndDmaPartialConversion(Unit, Group, (boolean)FALSE);
        }
        else
#endif
        if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > 0U)
        {
            Group = Adc_aUnitStatus[Unit].SwNormalQueue[0];
            Adc_Adc12bsarv2_EndDmaPartialConversion(Unit, Group, (boolean)TRUE);
        }
        else
        {
            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
        }
    }
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_EndDmaPartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bSoftwareConversion
)
{
#if ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) || ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) && (ADC_SETCHANNEL_API == STD_ON)))
    VAR(Adc_ChannelIndexType, AUTOMATIC) NumChannel;
#endif
#ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
#if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) TcdAddress;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaLinkChannel = 255U; /* Invalid DMA channel*/
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;
#endif
#endif
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)

    VAR(uint16,AUTOMATIC) u16Iter;
#endif
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) || ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) && ((ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) || (ADC_SETCHANNEL_API == STD_ON)))
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr;

    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#endif

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if((Std_ReturnType)E_OK == Adc_Adc12bsarv2_TransferToInternalBuffer(Unit, Group))
    #endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    {
        /*Limit check passed or more channels in group */
    #if (ADC_SETCHANNEL_API == STD_ON)
        NumChannel = Adc_aRuntimeGroupChannel[Group].ChannelCount;
    #else
        NumChannel = pGroupPtr->AssignedChannelCount;
    #endif
        /* More channels in group */
        if (Adc_aGroupStatus[Group].CurrentChannel < NumChannel)
        {
            NumChannel -= Adc_aGroupStatus[Group].CurrentChannel;
            Adc_Adc12bsarv2_ConfigureDmaPartialConversion(Unit, Group, pGroupPtr, PDB_SOFTWARE_TRIGGER_U32, (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(NumChannel), (boolean)TRUE);
            Mcl_DmaEnableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
        }
        else
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)  */
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON)
    {
#endif
        {
    #if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
            if (pGroupPtr->ExtraNotification != NULL_PTR)
            {
                /* Extra notification have to invoked out of exclusive area */
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
                pGroupPtr->ExtraNotification();
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();
            }
    #endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
    #if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON)
            Adc_aGroupStatus[Group].eConversion=ADC_STREAM_COMPLETED;
        #if (ADC_SETCHANNEL_API == STD_ON)
            /* Configure new channel if channels of group updated */
            if ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated)
            {
                Adc_aGroupStatus[Group].CurrentChannel = 0U;
                NumChannel = Adc_aRuntimeGroupChannel[Group].ChannelCount;
                /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                Adc_Adc12bsarv2_ConfigureDmaPartialConversion(Unit, Group, pGroupPtr, (Adc_HwTriggerTimerType)pGroupPtr->pHwResource[0U], (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(NumChannel), (boolean)TRUE);
                Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean) FALSE;
            }
        #endif
            /* Re-enable DMA channel after each transfer completed */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE8(ADC12BSARV2_DMA_SERQ_REG_ADDR32, (0U == Unit) ? ADC_UNIT_0_ASSOCIATED_DMA_HW_CHANNEL : ADC_UNIT_1_ASSOCIATED_DMA_HW_CHANNEL);
            Adc_Adc12bsarv2_DmaCheckNotification(Group);
    #else
        #if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
            if ((boolean) TRUE == pGroupPtr->bAdcDoubleBuffering)
            {
            #ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
            #if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
                if(NumChannel > 1U)
                {
                    DmaLinkChannel=(Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaDoubleBuffer[Unit];
                    TcdAddress=Mcl_DmaGetChannelTcdAddress(DmaLinkChannel);
                    u16Iter=Mcl_DmaTcdGetIterCount(TcdAddress);
                }
                else
            #endif
            #endif
                {
                    u16Iter=Mcl_DmaTcdGetIterCount(Adc_Adc12bsarv2_aTcdAddress[Unit]);
                }
                
                /* Update group status as ADC_COMPLETE when the haft of sample transfered and ADC_STREAM_COMPLETED when all of sample transfered  */
                if(pGroupPtr->NumSamples == u16Iter)
                {
                    Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
                #ifdef ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL
                #if (STD_ON == ADC_DOUBLE_BUFFERING_MORE_THAN_ONE_CHANNEL)
                    if(NumChannel > 1U)
                    {
                        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned long to pointer */
                        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32daddr = (uint32)Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group];
                        DmaChannel = (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit];
                        Mcl_DmaConfigLinkedChannel(DmaChannel,&(Adc_Adc12bsarv2_aDmaTcdConfig[Unit]), DmaLinkChannel );
                        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_13 cast from unsigned int to signed int */
                        Mcl_DmaTcdSetSlast(Adc_Adc12bsarv2_aTcdAddress[Unit], -(sint32)((uint32)NumChannel << 2U));
                        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_13 cast from unsigned int to signed int */
                        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                        Mcl_DmaTcdSetDlast(Adc_Adc12bsarv2_aTcdAddress[Unit], -(sint32)((((uint32)Adc_pCfgPtr->pGroups[Group].NumSamples*(uint32)NumChannel)-1U)<<1));
                    }
                #endif
                #endif
                }
                else
                {
                    Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
                }
                Adc_Adc12bsarv2_DmaCheckNotification(Group);
            }
            else
        #endif
            {
                /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
                Adc_aGroupStatus[Group].ResultIndex++;
                if ((boolean)TRUE == bSoftwareConversion)
                {
                    Adc_Adc12bsarv2_DmaEndNormalConv(Unit, Group, (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit], pGroupPtr);
                }
        #if(STD_ON == ADC_HW_TRIGGER_API)
                else
                {
                    Adc_Adc12bsarv2_DmaEndHardwareConv(Unit, Group, (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit], pGroupPtr);
                }
        #endif
            }
    #endif
            (void)bSoftwareConversion;
        }
    }
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    #if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    else
    {
        Adc_Adc12bsarv2_UpdateDmaLimitCheckFailed(Unit, Group, (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit], pGroupPtr, PDB_SOFTWARE_TRIGGER_U32);
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
    }
    #endif
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaCheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(boolean, AUTOMATIC)  bCallNotification = (boolean)FALSE;

    bCallNotification = Adc_Adc12bsarv2_CheckNotification(Group);
#endif
    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    if ((boolean)TRUE == bCallNotification)
    {
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_pCfgPtr->pGroups[Group].Notification();
    }
#else
    (void)Group;
#endif
}

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function handles the normal conversion via DMA ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion DMA ISR is called, this function takes care about
*                 the driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
* @param[in]      Group       the handled group.
*
* @return         void
*
* @api
*
* @implements     Adc_Adc12bsarv2_DmaEndNormalConv_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaEndNormalConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
)
{
    VAR(uint8, AUTOMATIC) u8NumChannel;

    /* At least once the group was converted */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;

    /* At least once the group was converted */

    if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
    }

    /* If all samples completed, wrap to 0 */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (Adc_aGroupStatus[Group].ResultIndex >= pGroupPtr->NumSamples)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if ((ADC_STREAM_BUFFER_LINEAR == pGroupPtr->eBufferMode) && \
            (ADC_ACCESS_MODE_STREAMING == pGroupPtr->eAccessMode) \
           )
        {
            Adc_Adc12bsarv2_StopDmaAndConversion(Unit, DmaChannel);

            Adc_Adc12bsarv2_UpdateQueue(Unit);

            Adc_Adc12bsarv2_DmaCheckNotification(Group);
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
        Adc_aGroupStatus[Group].ResultIndex = 0U;
    }
    /* If group configured as one-shot mode then stop and update as ADC_STREAM_COMPLETED else re-configure for the next converstion */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (ADC_CONV_MODE_CONTINUOUS == pGroupPtr->eMode)
    {
    #if (ADC_SETCHANNEL_API == STD_ON)
        u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(Adc_aRuntimeGroupChannel[Group].ChannelCount);
    #else
        u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(pGroupPtr->AssignedChannelCount);
    #endif
        Adc_aGroupStatus[Group].CurrentChannel = 0U;
        Adc_Adc12bsarv2_ConfigureDmaPartialConversion(Unit, Group, pGroupPtr, PDB_SOFTWARE_TRIGGER_U32, u8NumChannel, (boolean)TRUE);

        /* Start the DMA Channel */
        Mcl_DmaEnableHwRequest(DmaChannel);
        #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_Adc12bsarv2_DmaCheckNotification(Group);
        #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    else if (ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode)
    {
        Adc_Adc12bsarv2_StopDmaAndConversion(Unit, DmaChannel);

        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;

        Adc_Adc12bsarv2_UpdateQueue(Unit);

        #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_Adc12bsarv2_DmaCheckNotification(Group);
        #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
    }
    else
    {
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
    }
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_StopDmaAndConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel
)
{
    VAR(uint8, AUTOMATIC) u8SCRegister;

    /* Disable Adc hardware unit and clear all of COCO bit by reading Rn registers */
    for(u8SCRegister = 0U; u8SCRegister < Adc_aUnitStatus[Unit].u8Sc1Used; u8SCRegister++)
    {
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)u8SCRegister), ADC12BSARV2_CONV_COMPLETE_INT_DIS_U32 | ADC12BSARV2_ADCH_CONVERSION_DISABLE_U32);
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        (void)REG_READ32(ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)u8SCRegister));
    }

    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
    {
        Mcl_DmaDisableHwRequest(DmaChannel);
    #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        Mcl_DmaDisableNotification(DmaChannel);
    #endif
    }
}

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function handles the normal conversion via DMA ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion DMA ISR is called, this function takes care about
*                 the driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
* @param[in]      Group       the handled group.
*
* @return         void
*
* @api
*
* @implements     Adc_Adc12bsarv2_DmaEndHardwareConv_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaEndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
)
{
    VAR(uint8, AUTOMATIC) u8NumChannel;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif
    /* At least once the group was converted */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
    /* Update ADC for first channel in group */
    Adc_aGroupStatus[Group].CurrentChannel = 0U;
    if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
    }
    /* If all samples completed, wrap to 0 */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (Adc_aGroupStatus[Group].ResultIndex >= pGroupPtr->NumSamples)
    {
        Adc_aGroupStatus[Group].eConversion=ADC_STREAM_COMPLETED;
        Adc_aGroupStatus[Group].ResultIndex = 0U;
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if ((ADC_ACCESS_MODE_STREAMING == pGroupPtr->eAccessMode) && \
            (ADC_STREAM_BUFFER_LINEAR == pGroupPtr->eBufferMode) \
           )
        {
            /* Stop conversion and DMA*/
            Adc_Adc12bsarv2_StopDmaAndConversion(Unit, DmaChannel);

            Adc_aUnitStatus[Unit].HwNormalQueueIndex = (Adc_QueueIndexType)0;

            Adc_Adc12bsarv2_DmaCheckNotification(Group);
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
    }
    if((ChannelCount > ADC_NUM_SC1n_REGISTER_USED)
    #if (ADC_SETCHANNEL_API == STD_ON)
       || ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated)
    #endif /* (ADC_SETCHANNEL_API == STD_ON) */
      )
    {
        u8NumChannel = (uint8)ADC_ADC12BSARV2_GET_LEFT_CHANNEL(ChannelCount);
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_Adc12bsarv2_ConfigureDmaPartialConversion(Unit, Group, pGroupPtr, (Adc_HwTriggerTimerType)pGroupPtr->pHwResource[0], u8NumChannel, (boolean)TRUE);
        #if (ADC_SETCHANNEL_API == STD_ON)
        Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean)FALSE;
        #endif /* (ADC_SETCHANNEL_API == STD_ON) */
        Adc_Adc12bsarv2_DmaUpdateDaddr(Group);
    }
    else
    {
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32saddr = (uint32)ADC12BSARV2_Rn_REG_ADDR32(Unit, (uint32)0);
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer. */
        Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32daddr = (uint32)(Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex);
        Mcl_DmaConfigTcd(Adc_Adc12bsarv2_aTcdAddress[Unit], &(Adc_Adc12bsarv2_aDmaTcdConfig[Unit]));
        Mcl_DmaTcdSetFlags(Adc_Adc12bsarv2_aTcdAddress[Unit], (uint8)(DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_INT_MAJOR_U8));
        Adc_aGroupStatus[Group].CurrentChannel += ChannelCount;
    }

    Mcl_DmaEnableHwRequest(DmaChannel);
    Adc_Adc12bsarv2_DmaCheckNotification(Group);
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaUpdateDaddr
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */

    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Unit = Adc_pCfgPtr->pGroups[(Group)].HwUnit;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if ((boolean)FALSE == pGroupPtr->bAdcGroupLimitcheck)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    {
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex;
        /* Configure the destination result address in TCD of the DMA channels */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        /** Compiler_Warning : It is intended for the address of the element to be passed
        to the function as an unsigned integer*/
        Mcl_DmaTcdSetDaddr(Adc_Adc12bsarv2_aTcdAddress[Unit], (uint32)pResult);
    }
}
#endif
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
LOCAL_INLINE FUNC (Std_ReturnType, ADC_CODE) Adc_Adc12bsarv2_TransferToInternalBuffer
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
    VAR(Std_ReturnType, AUTOMATIC) ReadGroupRet = (Std_ReturnType)E_OK;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
    VAR(boolean, AUTOMATIC) bFlag = (boolean)TRUE;
    VAR(uint16, AUTOMATIC) u16ResultValue;

    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */

    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + (Adc_aGroupStatus[Group].ResultIndex);
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChIndex = Adc_pCfgPtr->pGroups[Group].pAssignment[0];
    if ((boolean)TRUE == pGroupPtr->bAdcGroupLimitcheck)
    {
        /* Get the result value from internal buffer */
        u16ResultValue = Adc_Adc12bsarv2_aDmaInternalResultBuffer[Unit];
        (bFlag) = (boolean)Adc_CheckConversionValuesInRange(u16ResultValue,Unit,ChIndex);
        if((boolean)FALSE==(bFlag))
        {
            Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;
            Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)TRUE;
        }
        else
        {
            Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
            *(pResult) = u16ResultValue;
        }
    }

    return ReadGroupRet;
}

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateDmaLimitCheckFailed
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger
)
{
    /* Group with limit checking failed and one-shot mode will be stop */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode)
    {
        Adc_Adc12bsarv2_StopDmaAndConversion(Unit, DmaChannel);
    }
    /* For the group configured as continuous mode */
    else
    {
        /* Re-configure DMA incase of limit checking failed */
        Mcl_DmaTcdSetDaddr(Adc_Adc12bsarv2_aTcdAddress[Unit], (uint32)(Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32daddr));
        Mcl_DmaTcdSetSaddr(Adc_Adc12bsarv2_aTcdAddress[Unit], (uint32)(Adc_Adc12bsarv2_aDmaTcdConfig[Unit].u32saddr));
        if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
        {
            Adc_Pdb_StopConversion(Unit);
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADC12BSARV2_SC1_REG_ADDR32(Unit, (uint32)0), ADC12BSARV2_CONV_COMPLETE_INT_EN_U32);
            Mcl_DmaEnableHwRequest(DmaChannel);
            /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_Pdb_ConfigurePartialConversion(Unit, Group, pGroupPtr, Trigger, 0U, 1U);
        }
    }
}
#endif
#endif
#endif
#endif

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || (defined(ADC_DMA_SUPPORTED)))
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/**
* @brief          This function checks if notification function is available or not
* @details        This function checks if notification function is available or not
*
* @param[in]      Group           The ADC channel group
*
* @return         boolean         TRUE or FALSE
* @retval         TRUE            In case of notification function is available
* @retval         FALSE           In case of notification function is NOT available
*
*/
LOCAL_INLINE FUNC(boolean, ADC_CODE) Adc_Adc12bsarv2_CheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(boolean, AUTOMATIC) bCallNotification = (boolean) FALSE;

    /* If group notification enabled and notification function available, return true */
    /** @violates @ref Adc_Adc12bsarv2_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((ADC_NOTIFICATION_ENABLED == Adc_aGroupStatus[Group].eNotification) && \
        (Adc_pCfgPtr->pGroups[Group].Notification != NULL_PTR)
       )
    {
        bCallNotification = (boolean)TRUE;
    }
    return bCallNotification;
}
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
/**
* @brief          This function updates queue
* @details        This function updates queue elements after a conversion
*                   and start conversion if requests are still available in queue
*
* @param[in]      Unit         The ADC hardware unit
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adc12bsarv2_UpdateQueue
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#if (ADC_ENABLE_QUEUING == STD_ON)
    /* Remove current request element in queue */
    Adc_RemoveFromQueue(Unit,(uint8)0U);
    if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
        /* Start conversion if request elements are still available in queue */
        Adc_Adc12bsarv2_StartNormalConversion((Adc_HwUnitType)Unit);
    }
#else
    /* No element will be present in the queue */
    Adc_aUnitStatus[Unit].SwNormalQueueIndex = (Adc_QueueIndexType)0;
#endif /* ADC_ENABLE_QUEUING == STD_ON */
}
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef ADC_UNIT_0_ISR_USED
/*==================================================================================================
                                          ADC HW UNIT 0
==================================================================================================*/
/**
* @brief          This function handles the ISR for the conversion done of
*                 the ADC Hardware Unit 0.
* @details        The function handles the ISR for the ADC Hardware Unit 0.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_11 External linkage.
*/
ISR(Adc_Adc12bsarv2_EndGroupConvUnit0)
{
    Adc_Adc12bsarv2_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_0);

    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_0_ISR_USED */

#if defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0)
/**
* @brief          This function handles internal ADC updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the ADC Hardware Unit 0.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_11 External linkage.
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaTransferComplete0()
{
    Adc_Adc12bsarv2_DmaEndGroupConversion((Adc_HwUnitType)ADC_UNIT_0);
}
#endif /* (ADC_DMA_SUPPORTED) && (ADC_UNIT_0) */

#ifdef ADC_UNIT_1_ISR_USED
/*==================================================================================================
                                          ADC HW UNIT 1
==================================================================================================*/
/**
* @brief          This function handles the ISR for the conversion done of
*                 the ADC Hardware Unit 1
* @details        The function handles the ISR for the ADC Hardware Unit 1.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_11 External linkage.
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash.
*/
ISR(Adc_Adc12bsarv2_EndGroupConvUnit1)
{
    Adc_Adc12bsarv2_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_1);

    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_1_ISR_USED */

#if defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1)
/**
* @brief          This function handles internal ADC updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the ADC Hardware Unit 1.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_11 External linkage.
* @violates @ref Adc_Adc12bsarv2_Irq_c_REF_7 Identifier clash.
*/
FUNC(void, ADC_CODE) Adc_Adc12bsarv2_DmaTransferComplete1()
{
    Adc_Adc12bsarv2_DmaEndGroupConversion((Adc_HwUnitType)ADC_UNIT_1);
}
#endif /* (ADC_DMA_SUPPORTED) && (ADC_UNIT_1) */

#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_Adc12bsarv2_Irq_c_REF_1 only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adc12bsarv2_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
