/**
*   @file           Mcl_Dma_Irq.c
*   @version        1.0.1
*
*   @brief          AUTOSAR Mcl - Dma interrupt handler driver source file.
*   @details        Dma interrupt handling routines.
*
*   @addtogroup     MCL_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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
* @section MCL_DMA_IRQ_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between 
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
* @section MCL_DMA_IRQ_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section MCL_DMA_IRQ_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section MCL_DMA_IRQ_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section MCL_DMA_IRQ_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcl_IPW_Notif.h"
/** @violates @ref MCL_DMA_IRQ_C_REF_2 Header file being included twice */
#include "Reg_eSys_Dma.h"
#include "StdRegMacros.h"
/*
* @violates @ref Mcl_Dma_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Mcal.h"
/*
* @violates @ref Mcl_Dma_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Mcl_Dma_Types.h"
/*
* @violates @ref Mcl_Dma_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Mcl_Dma.h"
/*
* @violates @ref Mcl_Dma_Irq_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Mcl_IPW.h"
#include "CDD_Mcl_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_DMA_IRQ_VENDOR_ID_C                       43
#define MCL_DMA_IRQ_MODULE_ID_C                       255
#define MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C        2
#define MCL_DMA_IRQ_AR_RELEASE_REVISION_VERSION_C     2
#define MCL_DMA_IRQ_SW_MAJOR_VERSION_C                1
#define MCL_DMA_IRQ_SW_MINOR_VERSION_C                0
#define MCL_DMA_IRQ_SW_PATCH_VERSION_C                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcl_IPW_Notif.h file are of the same vendor */
#if (MCL_DMA_IRQ_VENDOR_ID_C != MCL_IPW_NOTIF_VENDOR_ID)
    #error "Mcl_Dma_Irq.c and Mcl_IPW_Notif.h have different vendor ids"
#endif
/* Check if source file and Mcl_IPW_Notif.h file are of the same Autosar version */
#if ((MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C    != MCL_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C    != MCL_IPW_NOTIF_AR_RELEASE_MINOR_VERSION)|| \
     (MCL_DMA_IRQ_AR_RELEASE_REVISION_VERSION_C != MCL_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Dma_Irq.c and Mcl_IPW_Notif.h are different"
#endif

/* Check if source file and Mcl_IPW_Notif.h file are of the same software version */
#if ((MCL_DMA_IRQ_SW_MAJOR_VERSION_C != MCL_IPW_NOTIF_SW_MAJOR_VERSION) || \
     (MCL_DMA_IRQ_SW_MINOR_VERSION_C != MCL_IPW_NOTIF_SW_MINOR_VERSION)|| \
     (MCL_DMA_IRQ_SW_PATCH_VERSION_C != MCL_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Dma_Irq.c and Mcl_IPW_Notif.h are different"
#endif


/* Check if current file and Reg_sSys_Dma.h file are of the same vendor */
#if (MCL_DMA_IRQ_VENDOR_ID_C != DMA_VENDOR_ID_REG)
    #error "Mcl_Dma_Irq.c and Reg_sSys_Dma.h have different vendor ids"
#endif
/* Check if source file and Reg_sSys_Dma.h file are of the same Autosar version */
#if ((MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C    != DMA_AR_RELEASE_MAJOR_VERSION_REG) || \
     (MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C    != DMA_AR_RELEASE_MINOR_VERSION_REG)|| \
     (MCL_DMA_IRQ_AR_RELEASE_REVISION_VERSION_C != DMA_AR_RELEASE_REVISION_VERSION_REG))
    #error "AutoSar Version Numbers of Mcl_Dma_Irq.c and Reg_sSys_Dma.h are different"
#endif

/* Check if source file and Reg_sSys_Dma.h file are of the same software version */
#if ((MCL_DMA_IRQ_SW_MAJOR_VERSION_C != DMA_SW_MAJOR_VERSION_REG) || \
     (MCL_DMA_IRQ_SW_MINOR_VERSION_C != DMA_SW_MINOR_VERSION_REG)|| \
     (MCL_DMA_IRQ_SW_PATCH_VERSION_C != DMA_SW_PATCH_VERSION_REG))
    #error "Software Version Numbers of Mcl_Dma_Irq.c and Reg_sSys_Dma.h are different"
#endif
/* Check if source file and Mcl_Dma header file are of the same vendor */
#if (MCL_DMA_IRQ_VENDOR_ID_C != MCL_DMA_VENDOR_ID)
    #error "Mcl_Dma_Irq.c and Mcl_Dma.h have different vendor IDs"
#endif
/* Check if source file and Mcl_Dma header file are of the same Autosar version */
#if ((MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCL_DMA_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C != MCL_DMA_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMA_IRQ_AR_RELEASE_REVISION_VERSION_C != MCL_DMA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Dma.h and Mcl_Dma_Irq.c are different"
#endif
/* Check if source file and Mcl_Dma header file are of the same Software version */
#if ((MCL_DMA_IRQ_SW_MAJOR_VERSION_C != MCL_DMA_SW_MAJOR_VERSION) || \
     (MCL_DMA_IRQ_SW_MINOR_VERSION_C != MCL_DMA_SW_MINOR_VERSION) || \
     (MCL_DMA_IRQ_SW_PATCH_VERSION_C != MCL_DMA_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Dma.h and Mcl_Dma_Irq.c are different"
#endif

/* Check if header file and Mcl_Dma_Types.h header file are of the same vendor */
#if (MCL_DMA_IRQ_VENDOR_ID_C != MCL_DMA_TYPES_VENDOR_ID)
    #error "Mcl_Dma_Irq.c and Mcl_Dma_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_Dma_Types.h header file are of the same Autosar version */
#if ((MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C    != MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C    != MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_DMA_IRQ_AR_RELEASE_REVISION_VERSION_C != MCL_DMA_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Dma_Irq.c and Mcl_Dma_Types.h are different"
#endif
/* Check if header file and Mcl_Dma_Types.h header file are of the same software version */
#if ((MCL_DMA_IRQ_SW_MAJOR_VERSION_C != MCL_DMA_TYPES_SW_MAJOR_VERSION) || \
     (MCL_DMA_IRQ_SW_MINOR_VERSION_C != MCL_DMA_TYPES_SW_MINOR_VERSION) || \
     (MCL_DMA_IRQ_SW_PATCH_VERSION_C != MCL_DMA_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Dma_Irq.c and Mcl_Dma_Types.h are different"
#endif

/* Check if source file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_Dma_Irq.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_DMA_IRQ_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_DMA_IRQ_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Mcl_Dma_Irq.cand StdRegMacros.h are different"
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
#ifdef MCL_ENABLE_DMA
#if (MCL_ENABLE_DMA == STD_ON)

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    #if ((MCL_DMA_COMBINED_TR_COMPLETION_ISR == STD_ON) || (MCL_DMA_TR_COMPLETION_MIXED_ISR == STD_ON) || (MCL_DMA_COMBINED_GROUP_COMPLETION_ISR == STD_ON))
    LOCAL_INLINE FUNC (void, MCL_CODE) Mcl_DmaProcessCombinedInterrupt
    (
        VAR(Mcl_DmaInstanceType, AUTOMATIC) DmaHwInstance
    );
    #endif 
    #if (MCL_DMA_TR_SEPARATED_ISR == STD_ON)
    LOCAL_INLINE FUNC (void, MCL_CODE) Mcl_DmaProcessInterrupt
    (
        VAR(Mcl_DmaChannelType, AUTOMATIC) HwChannel
    );
    #endif 
#endif 

#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
LOCAL_INLINE FUNC (void, MCL_CODE) Mcl_DmaProcessErrorInterrupt
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) DmaHwInstance
);
#endif /* ( MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON ) */

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    #if (MCL_DMA_COMBINED_TR_COMPLETION_ISR == STD_ON)
    ISR(MCL_DMA0_CH_COMPLETE_ISR);
    #if (MCL_DMA_NB_CONTROLLERS == 0x02U)
    ISR(MCL_DMA1_CH_COMPLETE_ISR);
    #endif
    #endif
#endif

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    #if (MCL_DMA_COMBINED_GROUP_COMPLETION_ISR == STD_ON)
    #ifdef MCL_DMA_GROUP0_ISR_USED
    ISR(MCL_DMA_GROUP0_COMPLETE_ISR);
    #endif
    #ifdef MCL_DMA_GROUP1_ISR_USED
    ISR(MCL_DMA_GROUP1_COMPLETE_ISR);
    #endif
    #endif
#endif

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    #if (MCL_DMA_TR_COMPLETION_MIXED_ISR == STD_ON)
        ISR(MCL_DMA_CH_MIXED_96_127_COMPLETE_ISR);
    #endif
#endif

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    #if (MCL_DMA_TR_SEPARATED_ISR == STD_ON)

    #ifdef MCL_DMA_CH_0_ISR_USED
    ISR(MCL_DMA_CH_0_ISR);
    #endif
    #ifdef MCL_DMA_CH_1_ISR_USED
    ISR(MCL_DMA_CH_1_ISR);
    #endif
    #ifdef MCL_DMA_CH_2_ISR_USED
    ISR(MCL_DMA_CH_2_ISR);
    #endif
    #ifdef MCL_DMA_CH_3_ISR_USED
    ISR(MCL_DMA_CH_3_ISR);
    #endif
    #ifdef MCL_DMA_CH_4_ISR_USED
    ISR(MCL_DMA_CH_4_ISR);
    #endif
    #ifdef MCL_DMA_CH_5_ISR_USED
    ISR(MCL_DMA_CH_5_ISR);
    #endif
    #ifdef MCL_DMA_CH_6_ISR_USED
    ISR(MCL_DMA_CH_6_ISR);
    #endif
    #ifdef MCL_DMA_CH_7_ISR_USED
    ISR(MCL_DMA_CH_7_ISR);
    #endif
    #ifdef MCL_DMA_CH_8_ISR_USED
    ISR(MCL_DMA_CH_8_ISR);
    #endif
    #ifdef MCL_DMA_CH_9_ISR_USED
    ISR(MCL_DMA_CH_9_ISR);
    #endif
    #ifdef MCL_DMA_CH_10_ISR_USED
    ISR(MCL_DMA_CH_10_ISR);
    #endif
    #ifdef MCL_DMA_CH_11_ISR_USED
    ISR(MCL_DMA_CH_11_ISR);
    #endif
    #ifdef MCL_DMA_CH_12_ISR_USED
    ISR(MCL_DMA_CH_12_ISR);
    #endif
    #ifdef MCL_DMA_CH_13_ISR_USED
    ISR(MCL_DMA_CH_13_ISR);
    #endif
    #ifdef MCL_DMA_CH_14_ISR_USED
    ISR(MCL_DMA_CH_14_ISR);
    #endif
    #ifdef MCL_DMA_CH_15_ISR_USED
    ISR(MCL_DMA_CH_15_ISR);
    #endif
    #ifdef MCL_DMA_CH_16_ISR_USED
    ISR(MCL_DMA_CH_16_ISR);
    #endif
    #ifdef MCL_DMA_CH_17_ISR_USED
    ISR(MCL_DMA_CH_17_ISR);
    #endif
    #ifdef MCL_DMA_CH_18_ISR_USED
    ISR(MCL_DMA_CH_18_ISR);
    #endif
    #ifdef MCL_DMA_CH_19_ISR_USED
    ISR(MCL_DMA_CH_19_ISR);
    #endif
    #ifdef MCL_DMA_CH_20_ISR_USED
    ISR(MCL_DMA_CH_20_ISR);
    #endif
    #ifdef MCL_DMA_CH_21_ISR_USED
    ISR(MCL_DMA_CH_21_ISR);
    #endif
    #ifdef MCL_DMA_CH_22_ISR_USED
    ISR(MCL_DMA_CH_22_ISR);
    #endif
    #ifdef MCL_DMA_CH_23_ISR_USED
    ISR(MCL_DMA_CH_23_ISR);
    #endif
    #ifdef MCL_DMA_CH_24_ISR_USED
    ISR(MCL_DMA_CH_24_ISR);
    #endif
    #ifdef MCL_DMA_CH_25_ISR_USED
    ISR(MCL_DMA_CH_25_ISR);
    #endif
    #ifdef MCL_DMA_CH_26_ISR_USED
    ISR(MCL_DMA_CH_26_ISR);
    #endif
    #ifdef MCL_DMA_CH_27_ISR_USED
    ISR(MCL_DMA_CH_27_ISR);
    #endif
    #ifdef MCL_DMA_CH_28_ISR_USED
    ISR(MCL_DMA_CH_28_ISR);
    #endif
    #ifdef MCL_DMA_CH_29_ISR_USED
    ISR(MCL_DMA_CH_29_ISR);
    #endif
    #ifdef MCL_DMA_CH_30_ISR_USED
    ISR(MCL_DMA_CH_30_ISR);
    #endif
    #ifdef MCL_DMA_CH_31_ISR_USED
    ISR(MCL_DMA_CH_31_ISR);
    #endif
    #ifdef MCL_DMA_CH_32_ISR_USED
    ISR(MCL_DMA_CH_32_ISR);
    #endif
    #ifdef MCL_DMA_CH_33_ISR_USED
    ISR(MCL_DMA_CH_33_ISR);
    #endif
    #ifdef MCL_DMA_CH_34_ISR_USED
    ISR(MCL_DMA_CH_34_ISR);
    #endif
    #ifdef MCL_DMA_CH_35_ISR_USED
    ISR(MCL_DMA_CH_35_ISR);
    #endif
    #ifdef MCL_DMA_CH_36_ISR_USED
    ISR(MCL_DMA_CH_36_ISR);
    #endif
    #ifdef MCL_DMA_CH_37_ISR_USED
    ISR(MCL_DMA_CH_37_ISR);
    #endif
    #ifdef MCL_DMA_CH_38_ISR_USED
    ISR(MCL_DMA_CH_38_ISR);
    #endif
    #ifdef MCL_DMA_CH_39_ISR_USED
    ISR(MCL_DMA_CH_39_ISR);
    #endif
    #ifdef MCL_DMA_CH_40_ISR_USED
    ISR(MCL_DMA_CH_40_ISR);
    #endif
    #ifdef MCL_DMA_CH_41_ISR_USED
    ISR(MCL_DMA_CH_41_ISR);
    #endif
    #ifdef MCL_DMA_CH_42_ISR_USED
    ISR(MCL_DMA_CH_42_ISR);
    #endif
    #ifdef MCL_DMA_CH_43_ISR_USED
    ISR(MCL_DMA_CH_43_ISR);
    #endif
    #ifdef MCL_DMA_CH_44_ISR_USED
    ISR(MCL_DMA_CH_44_ISR);
    #endif
    #ifdef MCL_DMA_CH_45_ISR_USED
    ISR(MCL_DMA_CH_45_ISR);
    #endif
    #ifdef MCL_DMA_CH_46_ISR_USED
    ISR(MCL_DMA_CH_46_ISR);
    #endif
    #ifdef MCL_DMA_CH_47_ISR_USED
    ISR(MCL_DMA_CH_47_ISR);
    #endif
    #ifdef MCL_DMA_CH_48_ISR_USED
    ISR(MCL_DMA_CH_48_ISR);
    #endif
    #ifdef MCL_DMA_CH_49_ISR_USED
    ISR(MCL_DMA_CH_49_ISR);
    #endif
    #ifdef MCL_DMA_CH_50_ISR_USED
    ISR(MCL_DMA_CH_50_ISR);
    #endif
    #ifdef MCL_DMA_CH_51_ISR_USED
    ISR(MCL_DMA_CH_51_ISR);
    #endif
    #ifdef MCL_DMA_CH_52_ISR_USED
    ISR(MCL_DMA_CH_52_ISR);
    #endif
    #ifdef MCL_DMA_CH_53_ISR_USED
    ISR(MCL_DMA_CH_53_ISR);
    #endif
    #ifdef MCL_DMA_CH_54_ISR_USED
    ISR(MCL_DMA_CH_54_ISR);
    #endif
    #ifdef MCL_DMA_CH_55_ISR_USED
    ISR(MCL_DMA_CH_55_ISR);
    #endif
    #ifdef MCL_DMA_CH_56_ISR_USED
    ISR(MCL_DMA_CH_56_ISR);
    #endif
    #ifdef MCL_DMA_CH_57_ISR_USED
    ISR(MCL_DMA_CH_57_ISR);
    #endif
    #ifdef MCL_DMA_CH_58_ISR_USED
    ISR(MCL_DMA_CH_58_ISR);
    #endif
    #ifdef MCL_DMA_CH_59_ISR_USED
    ISR(MCL_DMA_CH_59_ISR);
    #endif
    #ifdef MCL_DMA_CH_60_ISR_USED
    ISR(MCL_DMA_CH_60_ISR);
    #endif
    #ifdef MCL_DMA_CH_61_ISR_USED
    ISR(MCL_DMA_CH_61_ISR);
    #endif
    #ifdef MCL_DMA_CH_62_ISR_USED
    ISR(MCL_DMA_CH_62_ISR);
    #endif
    #ifdef MCL_DMA_CH_63_ISR_USED
    ISR(MCL_DMA_CH_63_ISR);
    #endif
    #ifdef MCL_DMA_CH_64_ISR_USED
    ISR(MCL_DMA_CH_64_ISR);
    #endif
    #ifdef MCL_DMA_CH_65_ISR_USED
    ISR(MCL_DMA_CH_65_ISR);
    #endif
    #ifdef MCL_DMA_CH_66_ISR_USED
    ISR(MCL_DMA_CH_66_ISR);
    #endif
    #ifdef MCL_DMA_CH_67_ISR_USED
    ISR(MCL_DMA_CH_67_ISR);
    #endif
    #ifdef MCL_DMA_CH_68_ISR_USED
    ISR(MCL_DMA_CH_68_ISR);
    #endif
    #ifdef MCL_DMA_CH_69_ISR_USED
    ISR(MCL_DMA_CH_69_ISR);
    #endif
    #ifdef MCL_DMA_CH_70_ISR_USED
    ISR(MCL_DMA_CH_70_ISR);
    #endif
    #ifdef MCL_DMA_CH_71_ISR_USED
    ISR(MCL_DMA_CH_71_ISR);
    #endif
    #ifdef MCL_DMA_CH_72_ISR_USED
    ISR(MCL_DMA_CH_72_ISR);
    #endif
    #ifdef MCL_DMA_CH_73_ISR_USED
    ISR(MCL_DMA_CH_73_ISR);
    #endif
    #ifdef MCL_DMA_CH_74_ISR_USED
    ISR(MCL_DMA_CH_74_ISR);
    #endif
    #ifdef MCL_DMA_CH_75_ISR_USED
    ISR(MCL_DMA_CH_75_ISR);
    #endif
    #ifdef MCL_DMA_CH_76_ISR_USED
    ISR(MCL_DMA_CH_76_ISR);
    #endif
    #ifdef MCL_DMA_CH_77_ISR_USED
    ISR(MCL_DMA_CH_77_ISR);
    #endif
    #ifdef MCL_DMA_CH_78_ISR_USED
    ISR(MCL_DMA_CH_78_ISR);
    #endif
    #ifdef MCL_DMA_CH_79_ISR_USED
    ISR(MCL_DMA_CH_79_ISR);
    #endif
    #ifdef MCL_DMA_CH_80_ISR_USED
    ISR(MCL_DMA_CH_80_ISR);
    #endif
    #ifdef MCL_DMA_CH_81_ISR_USED
    ISR(MCL_DMA_CH_81_ISR);
    #endif
    #ifdef MCL_DMA_CH_82_ISR_USED
    ISR(MCL_DMA_CH_82_ISR);
    #endif
    #ifdef MCL_DMA_CH_83_ISR_USED
    ISR(MCL_DMA_CH_83_ISR);
    #endif
    #ifdef MCL_DMA_CH_84_ISR_USED
    ISR(MCL_DMA_CH_84_ISR);
    #endif
    #ifdef MCL_DMA_CH_85_ISR_USED
    ISR(MCL_DMA_CH_85_ISR);
    #endif
    #ifdef MCL_DMA_CH_86_ISR_USED
    ISR(MCL_DMA_CH_86_ISR);
    #endif
    #ifdef MCL_DMA_CH_87_ISR_USED
    ISR(MCL_DMA_CH_87_ISR);
    #endif
    #ifdef MCL_DMA_CH_88_ISR_USED
    ISR(MCL_DMA_CH_88_ISR);
    #endif
    #ifdef MCL_DMA_CH_89_ISR_USED
    ISR(MCL_DMA_CH_89_ISR);
    #endif
    #ifdef MCL_DMA_CH_90_ISR_USED
    ISR(MCL_DMA_CH_90_ISR);
    #endif
    #ifdef MCL_DMA_CH_91_ISR_USED
    ISR(MCL_DMA_CH_91_ISR);
    #endif
    #ifdef MCL_DMA_CH_92_ISR_USED
    ISR(MCL_DMA_CH_92_ISR);
    #endif
    #ifdef MCL_DMA_CH_93_ISR_USED
    ISR(MCL_DMA_CH_93_ISR);
    #endif
    #ifdef MCL_DMA_CH_94_ISR_USED
    ISR(MCL_DMA_CH_94_ISR);
    #endif
    #ifdef MCL_DMA_CH_95_ISR_USED
    ISR(MCL_DMA_CH_95_ISR);
    #endif
    #ifdef MCL_DMA_CH_96_ISR_USED
    ISR(MCL_DMA_CH_96_ISR);
    #endif
    #ifdef MCL_DMA_CH_97_ISR_USED
    ISR(MCL_DMA_CH_97_ISR);
    #endif
    #ifdef MCL_DMA_CH_98_ISR_USED
    ISR(MCL_DMA_CH_98_ISR);
    #endif
    #ifdef MCL_DMA_CH_99_ISR_USED
    ISR(MCL_DMA_CH_99_ISR);
    #endif
    #ifdef MCL_DMA_CH_100_ISR_USED
    ISR(MCL_DMA_CH_100_ISR);
    #endif
    #ifdef MCL_DMA_CH_101_ISR_USED
    ISR(MCL_DMA_CH_101_ISR);
    #endif
    #ifdef MCL_DMA_CH_102_ISR_USED
    ISR(MCL_DMA_CH_102_ISR);
    #endif
    #ifdef MCL_DMA_CH_103_ISR_USED
    ISR(MCL_DMA_CH_103_ISR);
    #endif
    #ifdef MCL_DMA_CH_104_ISR_USED
    ISR(MCL_DMA_CH_104_ISR);
    #endif
    #ifdef MCL_DMA_CH_105_ISR_USED
    ISR(MCL_DMA_CH_105_ISR);
    #endif
    #ifdef MCL_DMA_CH_106_ISR_USED
    ISR(MCL_DMA_CH_106_ISR);
    #endif
    #ifdef MCL_DMA_CH_107_ISR_USED
    ISR(MCL_DMA_CH_107_ISR);
    #endif
    #ifdef MCL_DMA_CH_108_ISR_USED
    ISR(MCL_DMA_CH_108_ISR);
    #endif
    #ifdef MCL_DMA_CH_109_ISR_USED
    ISR(MCL_DMA_CH_109_ISR);
    #endif
    #ifdef MCL_DMA_CH_110_ISR_USED
    ISR(MCL_DMA_CH_110_ISR);
    #endif
    #ifdef MCL_DMA_CH_111_ISR_USED
    ISR(MCL_DMA_CH_111_ISR);
    #endif
    #ifdef MCL_DMA_CH_112_ISR_USED
    ISR(MCL_DMA_CH_112_ISR);
    #endif
    #ifdef MCL_DMA_CH_113_ISR_USED
    ISR(MCL_DMA_CH_113_ISR);
    #endif
    #ifdef MCL_DMA_CH_114_ISR_USED
    ISR(MCL_DMA_CH_114_ISR);
    #endif
    #ifdef MCL_DMA_CH_115_ISR_USED
    ISR(MCL_DMA_CH_115_ISR);
    #endif
    #ifdef MCL_DMA_CH_116_ISR_USED
    ISR(MCL_DMA_CH_116_ISR);
    #endif
    #ifdef MCL_DMA_CH_117_ISR_USED
    ISR(MCL_DMA_CH_117_ISR);
    #endif
    #ifdef MCL_DMA_CH_118_ISR_USED
    ISR(MCL_DMA_CH_118_ISR);
    #endif
    #ifdef MCL_DMA_CH_119_ISR_USED
    ISR(MCL_DMA_CH_119_ISR);
    #endif
    #ifdef MCL_DMA_CH_120_ISR_USED
    ISR(MCL_DMA_CH_120_ISR);
    #endif
    #ifdef MCL_DMA_CH_121_ISR_USED
    ISR(MCL_DMA_CH_121_ISR);
    #endif
    #ifdef MCL_DMA_CH_122_ISR_USED
    ISR(MCL_DMA_CH_122_ISR);
    #endif
    #ifdef MCL_DMA_CH_123_ISR_USED
    ISR(MCL_DMA_CH_123_ISR);
    #endif
    #ifdef MCL_DMA_CH_124_ISR_USED
    ISR(MCL_DMA_CH_124_ISR);
    #endif
    #ifdef MCL_DMA_CH_125_ISR_USED
    ISR(MCL_DMA_CH_125_ISR);
    #endif
    #ifdef MCL_DMA_CH_126_ISR_USED
    ISR(MCL_DMA_CH_126_ISR);
    #endif
    #ifdef MCL_DMA_CH_127_ISR_USED
    ISR(MCL_DMA_CH_127_ISR);
    #endif
#endif
#endif

#if (MCL_DMA_COMBINED_ERROR_ISR  == STD_OFF)
    #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ISR(MCL_DMA0_ERROR_ISR);
    #if (MCL_DMA_NB_CONTROLLERS == 0x02U)
    ISR(MCL_DMA1_ERROR_ISR);
    #endif
    #endif
#endif

#if (MCL_DMA_COMBINED_ERROR_ISR  == STD_ON)
    #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ISR(MCL_DMA_ERROR_ISR);
    #endif
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/** @violates @ref MCL_DMA_IRQ_C_REF_2 only preprocessor statements and comments before "#include" */
/** @violates @ref MCL_DMA_IRQ_C_REF_3 only preprocessor statements and comments before "#include" */
#include "Mcl_MemMap.h"

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
#if ((MCL_DMA_COMBINED_TR_COMPLETION_ISR == STD_ON) || (MCL_DMA_TR_COMPLETION_MIXED_ISR == STD_ON) || (MCL_DMA_COMBINED_GROUP_COMPLETION_ISR == STD_ON))
    /**
    * @brief          Interrupt service routine to process the Dma interrupt
    * @details        This function:
    *                 - clears the unified channel interrupt flag bit in Control register
    *                 - calls the LLD layer handler
    *
    * @param[in]      DmaHwInstance      Dma Hardware Instance
    * @return void
    *
    * @api
    * @implements  Mcl_DmaProcessInterrupt_Activity
    */
    LOCAL_INLINE FUNC (void, MCL_CODE) Mcl_DmaProcessCombinedInterrupt
    (
        VAR(Mcl_DmaInstanceType, AUTOMATIC) DmaHwInstance
    )
    {   
        /* @brief Variable storing the relative channel number */ 
        VAR(Mcl_DmaChannelType, AUTOMATIC) RelChannel = (uint8)0;
        /* @brief Variable storing the absolute channel */ 
        VAR(Mcl_DmaChannelType, AUTOMATIC) AbsChannel = (uint8)0;
        /* @brief Variable storing content of Status register */
        VAR(uint32, AUTOMATIC) u32InerruptReqValue = (uint32)0;
        /* @brief Variable check the interrupt request already exist or not */
        VAR(boolean, AUTOMATIC) bIsrStatus = (boolean)FALSE;
        #ifdef MCAL_CACHE_RUNTIME_MNGMNT
        #if (STD_ON == MCAL_CACHE_RUNTIME_MNGMNT)
        #if (STD_ON == MCL_SYNCRONIZE_CACHE) 
        /* @brief Return value of the cache operation*/
        VAR(Std_ReturnType, AUTOMATIC) retValCacheOperation = (Std_ReturnType)E_NOT_OK;
        
        /* invalidate DCACHE to synchronize data */
        retValCacheOperation = Mcl_IPW_CacheClear(MCL_LMEM_CACHE_ALL);
        if ((Std_ReturnType)E_NOT_OK == retValCacheOperation)
        {   
            /* memory synchronization failed, notify user */
            #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
            Mcl_IPW_ErrorNotification(DmaHwInstance , MCL_DMA_MEM_SYNC_ERROR);
            #endif
        }
        else
        {
            /* cache memory sync successful */
        }
        #endif
        #endif
        #endif
  
        /* get the interrupt requests for low channels*/
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        u32InerruptReqValue = (uint32)REG_READ32(DMA_INTL_ADDR32(DmaHwInstance));
        /* get the channel for which the ISR was requested*/
        while((RelChannel < 32U) && ((boolean)FALSE == bIsrStatus))
        {
            if(((uint32)0 != (u32InerruptReqValue & (uint32)(((uint32)1u << (uint32)RelChannel)))))
            {
                bIsrStatus = (boolean)TRUE;
            }
            else
            {
                RelChannel = RelChannel + (uint8)1;
            }
        }
#if (MCL_DMA_NB_CHANNELS == 0x40U)
        /* get the interrupt requests for high channels*/
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        u32InerruptReqValue = (uint32)REG_READ32(DMA_INTH_ADDR32(DmaHwInstance));
        /* get the channel for which the ISR was requested*/
        while((RelChannel < (uint8)DMA_CHANNELS_PER_MODULE_U8) && ((boolean)FALSE == bIsrStatus))
        {
            if(((uint32)0 != (u32InerruptReqValue & (uint32)(((uint32)1u << (uint32)((uint32)RelChannel - (uint32)32U))))))
            {
                bIsrStatus = (boolean)TRUE;
            }
            else
            {
                RelChannel = RelChannel + (uint8)1;
            }
        }
#endif
        /* check if any ISR request is set*/
        if((boolean)TRUE == bIsrStatus)
        {
            /* get the absolute hardware channel number from all DMA instances*/
            AbsChannel = RelChannel + (DmaHwInstance * DMA_CHANNELS_PER_MODULE_U8);
            /* reset DMA channel interrupt flag (IRQ ACK) */
            /** @violates @ref MCL_DMA_IRQ_C_REF_1 A cast should not be performed between a pointer type and an integral type. */
            /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            DMA_CLEAR_INT_REQ(AbsChannel);
            /* Check that the interrupt was enabled for the corresponding DMA channel */
            /** @violates @ref MCL_DMA_IRQ_C_REF_1 A cast should not be performed between a pointer type and an integral type. */
            /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            if (((boolean)TRUE == DMA_TCD_GET_INT_MAJ(AbsChannel)) || ((boolean)TRUE == DMA_TCD_GET_INT_HALF(AbsChannel)))
            {
                /* Call Dma channel notification */ 
                Mcl_IPW_DmaChannelNotification(AbsChannel);
            }
            else
            {
              /*Empty else to fix misra*/
            }
         }
         else
         {
            /*Empty else to fix misra*/
         }
    }
#endif
#endif 

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
#if (MCL_DMA_TR_SEPARATED_ISR == STD_ON)
    /**
    * @brief          Interrupt service routine to process the Dma interrupt
    * @details        This function:
    *                 - clears the unified channel interrupt flag bit in Control register
    *                 - calls the LLD layer handler
    *
    * @param[in]      HwChannel      Dma channel ID that triggered the interrupt
    *
    * @return void
    *
    * @api
    * @implements  Mcl_DmaProcessInterrupt_Activity
    */
    LOCAL_INLINE FUNC (void, MCL_CODE) Mcl_DmaProcessInterrupt
    (
        VAR(Mcl_DmaChannelType, AUTOMATIC) HwChannel
    )
    {
        /* @brief Variable storing content of Status register */
        VAR(boolean, AUTOMATIC) bIsrStatus = (boolean)FALSE;

        /* Check that the interrupt was enabled for the corresponding DMA channel */
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 A cast should not be performed between a pointer type and an integral type. */
        /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        if (((boolean)TRUE==DMA_TCD_GET_INT_MAJ(HwChannel)) || ((boolean)TRUE==DMA_TCD_GET_INT_HALF(HwChannel)))
        {
            /* Get the interrupt request for the corresponding DMA channel */
            bIsrStatus = Mcl_Dma_GetMultiRegChInfo(HwChannel, MCL_DMA_GET_INT);
        }
        else
        {
          /*Empty else to fix misra*/
        }
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 A cast should not be performed between a pointer type and an integral type. */
        /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        DMA_CLEAR_INT_REQ(HwChannel);    
        
        /* Check if isr was enabled on the corresponding channel and interrupt request was set */
        if (bIsrStatus)
        {
            /* Call Dma channel notification */ 
            Mcl_IPW_DmaChannelNotification(HwChannel);
        }
        else
        {
          /*Empty else to fix misra*/
        }
    }
#endif 
#endif 

#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
/**
* @brief          Interrupt service routine to process the Dma error interrupt
* @details        This function:
*                 - checks the error type
*                 - calls higher level function to report error
*
* @param[in]
*
* @return void
*
* @api
* @implements  Mcl_DmaProcessErrorInterrupt_Activity
*/
LOCAL_INLINE FUNC(void, MCL_CODE) Mcl_DmaProcessErrorInterrupt
(
    VAR(Mcl_DmaInstanceType, AUTOMATIC) DmaHwInstance
)
{
    /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
    /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    VAR(uint32,AUTOMATIC) u32ErrorStatus = REG_READ32(DMA_ES_ADDR32((uint32)(DmaHwInstance)));
    
    /* Clear all error indicators */
    /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
    /** @violates @ref MCL_DMA_IRQ_C_REF_6 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
    REG_WRITE8(DMA_CERR_ADDR32((uint32)(DmaHwInstance)), DMA_CERR_CAEI_U8);
 
    if ((uint32)0U != u32ErrorStatus )
    {
        #if (MCL_DMA_ECC_REPORTING_ENABLED == STD_ON)    
        if(0U != (u32ErrorStatus & DMA_ES_UCE_U32))
        {
            /* Uncorrectable  ECC error detected */
            Mcl_IPW_ErrorNotification(DmaHwInstance,MCL_DMA_ECC_ERROR);
        }
        else 
        #endif
        if((uint32)0U != (u32ErrorStatus & DMA_ES_BUS_U32)) 
        {
            /* Source or destination bus error detected */
            Mcl_IPW_ErrorNotification(DmaHwInstance,MCL_DMA_BUS_ERROR);
        }
        else if((uint32)0U != (u32ErrorStatus & DMA_ES_DESCRIPTOR_U32)) 
        {
            /* Descriptor error detected */
            Mcl_IPW_ErrorNotification(DmaHwInstance,MCL_DMA_DESCRIPTOR_ERROR);
        }
        else if((uint32)0U != (u32ErrorStatus & (DMA_ES_GPE_U32 | DMA_ES_CPE_U32)))
        {
            /* Priority error detected */
            Mcl_IPW_ErrorNotification(DmaHwInstance,MCL_DMA_PRIORITY_ERROR);
        }
        else
        { 
            /* Unrecognized error detected */ 
            Mcl_IPW_ErrorNotification(DmaHwInstance,MCL_DMA_UNRECOGNIZED_ERROR); 
            
            /* Comment added to workaround MISRA tool check bug, which failed to detect a final 'else'
               block if that block ended with a preprocessing directive.*/
        } 
    }
    else
    {
        /* No errors present */
    }
}
#endif /* ( MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON) */

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
#if (MCL_DMA_COMBINED_TR_COMPLETION_ISR == STD_ON)
    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA module: 0  channel: 0
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA0_CH_COMPLETE_ISR)
    {
        Mcl_DmaProcessCombinedInterrupt(DMA_INSTANCE0);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
  
    #if (MCL_DMA_NB_CONTROLLERS == 0x02U)
    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA module: 0  channel: 0
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA1_CH_COMPLETE_ISR)
    {
        Mcl_DmaProcessCombinedInterrupt(DMA_INSTANCE1);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
#endif
#endif

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
    #if (MCL_DMA_COMBINED_GROUP_COMPLETION_ISR == STD_ON)
    #ifdef MCL_DMA_GROUP0_ISR_USED
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_GROUP0_COMPLETE_ISR)
    {
        /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
        Mcl_DmaProcessCombinedInterrupt(DMA_INSTANCE0);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
    #ifdef MCL_DMA_GROUP1_ISR_USED
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_GROUP1_COMPLETE_ISR)
    {
        /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
        Mcl_DmaProcessCombinedInterrupt(DMA_INSTANCE0);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
    #endif
#endif

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
#if (MCL_DMA_TR_COMPLETION_MIXED_ISR == STD_ON)
    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channels eDMA_96 to eDMA_127
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_MIXED_96_127_COMPLETE_ISR)
    {
        Mcl_DmaProcessCombinedInterrupt(DMA_INSTANCE1);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
#endif
#endif

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
#if (MCL_DMA_TR_SEPARATED_ISR == STD_ON)

    #ifdef MCL_DMA_CH_0_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 0
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_0_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_0);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_0_ISR_USED */
        
    #ifdef MCL_DMA_CH_1_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 1
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_1_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_1);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_1_ISR_USED */
    #ifdef MCL_DMA_CH_2_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 2
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_2_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_2);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_2_ISR_USED */
    #ifdef MCL_DMA_CH_3_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 3
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_3_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_3);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_3_ISR_USED */
    #ifdef MCL_DMA_CH_4_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 4
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_4_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_4);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_4_ISR_USED */
    #ifdef MCL_DMA_CH_5_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 5
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_5_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_5);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_5_ISR_USED */
    #ifdef MCL_DMA_CH_6_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 6
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_6_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_6);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_6_ISR_USED */
    #ifdef MCL_DMA_CH_7_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 7
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_7_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_7);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_7_ISR_USED */
    #ifdef MCL_DMA_CH_8_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 8
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_8_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_8);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_8_ISR_USED */
    #ifdef MCL_DMA_CH_9_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 9
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_9_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_9);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_9_ISR_USED */
    #ifdef MCL_DMA_CH_10_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 10
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_10_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_10);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_10_ISR_USED */
    #ifdef MCL_DMA_CH_11_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 11
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_11_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_11);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_11_ISR_USED */
    #ifdef MCL_DMA_CH_12_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 12
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_12_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_12);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_12_ISR_USED */
    #ifdef MCL_DMA_CH_13_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 13
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_13_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_13);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_13_ISR_USED */
    #ifdef MCL_DMA_CH_14_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 14
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_14_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_14);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_14_ISR_USED */
    #ifdef MCL_DMA_CH_15_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 15
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_15_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_15);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_15_ISR_USED */
    #ifdef MCL_DMA_CH_16_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 16
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_16_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_16);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_16_ISR_USED */
    #ifdef MCL_DMA_CH_17_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 17
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_17_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_17);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_17_ISR_USED */
    #ifdef MCL_DMA_CH_18_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 18
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_18_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_18);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_18_ISR_USED */
    #ifdef MCL_DMA_CH_19_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 19
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_19_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_19);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_19_ISR_USED */
    #ifdef MCL_DMA_CH_20_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 20
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_20_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_20);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_20_ISR_USED */
    #ifdef MCL_DMA_CH_21_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 21
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_21_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_21);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_21_ISR_USED */
    #ifdef MCL_DMA_CH_22_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 22
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_22_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_22);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_22_ISR_USED */
    #ifdef MCL_DMA_CH_23_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 23
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_23_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_23);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_23_ISR_USED */
    #ifdef MCL_DMA_CH_24_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 24
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_24_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_24);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_24_ISR_USED */
    #ifdef MCL_DMA_CH_25_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 25
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_25_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_25);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_25_ISR_USED */
    #ifdef MCL_DMA_CH_26_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 26
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_26_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_26);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_26_ISR_USED */
    #ifdef MCL_DMA_CH_27_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 27
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_27_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_27);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_27_ISR_USED */
    #ifdef MCL_DMA_CH_28_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 28
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_28_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_28);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_28_ISR_USED */
    #ifdef MCL_DMA_CH_29_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 29
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_29_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_29);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_29_ISR_USED */
    #ifdef MCL_DMA_CH_30_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 30
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_30_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_30);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_30_ISR_USED */
    #ifdef MCL_DMA_CH_31_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 31
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_31_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_31);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_31_ISR_USED */
    #ifdef MCL_DMA_CH_32_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 32
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_32_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_32);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_32_ISR_USED */
    #ifdef MCL_DMA_CH_33_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 33
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_33_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_33);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_33_ISR_USED */
    #ifdef MCL_DMA_CH_34_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 34
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_34_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_34);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_34_ISR_USED */
    #ifdef MCL_DMA_CH_35_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 35
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_35_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_35);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_35_ISR_USED */
    #ifdef MCL_DMA_CH_36_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 36
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_36_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_36);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_36_ISR_USED */
    #ifdef MCL_DMA_CH_37_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 37
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_37_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_37);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_37_ISR_USED */
    #ifdef MCL_DMA_CH_38_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 38
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_38_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_38);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_38_ISR_USED */
    #ifdef MCL_DMA_CH_39_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 39
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_39_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_39);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_39_ISR_USED */
    #ifdef MCL_DMA_CH_40_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 40
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_40_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_40);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_40_ISR_USED */
    #ifdef MCL_DMA_CH_41_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 41
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_41_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_41);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_41_ISR_USED */
    #ifdef MCL_DMA_CH_42_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 42
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_42_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_42);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_42_ISR_USED */
    #ifdef MCL_DMA_CH_43_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 43
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_43_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_43);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_43_ISR_USED */
    #ifdef MCL_DMA_CH_44_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 44
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_44_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_44);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_44_ISR_USED */
    #ifdef MCL_DMA_CH_45_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 45
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_45_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_45);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_45_ISR_USED */
    #ifdef MCL_DMA_CH_46_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 46
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_46_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_46);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_46_ISR_USED */
    #ifdef MCL_DMA_CH_47_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 47
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_47_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_47);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_47_ISR_USED */
    #ifdef MCL_DMA_CH_48_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 48
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_48_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_48);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_48_ISR_USED */
    #ifdef MCL_DMA_CH_49_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 49
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_49_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_49);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_49_ISR_USED */
    #ifdef MCL_DMA_CH_50_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 50
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_50_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_50);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_50_ISR_USED */
    #ifdef MCL_DMA_CH_51_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 51
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_51_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_51);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_51_ISR_USED */
    #ifdef MCL_DMA_CH_52_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 52
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_52_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_52);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_52_ISR_USED */
    #ifdef MCL_DMA_CH_53_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 53
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_53_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_53);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    #endif /* MCL_DMA_CH_53_ISR_USED */
    #ifdef MCL_DMA_CH_54_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 54
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_54_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_54);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_54_ISR_USED */
    #ifdef MCL_DMA_CH_55_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 55
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_55_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_55);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_55_ISR_USED */
    #ifdef MCL_DMA_CH_56_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 56
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_56_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_56);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_56_ISR_USED */
    #ifdef MCL_DMA_CH_57_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 57
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_57_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_57);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_57_ISR_USED */
    #ifdef MCL_DMA_CH_58_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 58
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_58_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_58);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_58_ISR_USED */
    #ifdef MCL_DMA_CH_59_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 59
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_59_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_59);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_59_ISR_USED */
    #ifdef MCL_DMA_CH_60_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 60
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_60_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_60);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_60_ISR_USED */
    #ifdef MCL_DMA_CH_61_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 61
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_61_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_61);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_61_ISR_USED */
    #ifdef MCL_DMA_CH_62_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 62
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_62_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_62);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_62_ISR_USED */
    #ifdef MCL_DMA_CH_63_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 63
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_63_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_63);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_63_ISR_USED */
    #ifdef MCL_DMA_CH_64_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 64
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_64_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_64);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_64_ISR_USED */
    #ifdef MCL_DMA_CH_65_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 65
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_65_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_65);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_65_ISR_USED */
    #ifdef MCL_DMA_CH_66_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 66
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_66_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_66);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_66_ISR_USED */
    #ifdef MCL_DMA_CH_67_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 67
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_67_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_67);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_67_ISR_USED */
    #ifdef MCL_DMA_CH_68_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 68
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_68_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_68);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_68_ISR_USED */
    #ifdef MCL_DMA_CH_69_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 69
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_69_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_69);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_69_ISR_USED */
    #ifdef MCL_DMA_CH_70_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 70
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_70_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_70);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_70_ISR_USED */
    #ifdef MCL_DMA_CH_71_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 71
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_71_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_71);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_71_ISR_USED */
    #ifdef MCL_DMA_CH_72_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 72
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_72_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_72);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_72_ISR_USED */
    #ifdef MCL_DMA_CH_73_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 73
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_73_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_73);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_73_ISR_USED */
    #ifdef MCL_DMA_CH_74_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 74
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_74_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_74);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_74_ISR_USED */
    #ifdef MCL_DMA_CH_75_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 75
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_75_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_75);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_75_ISR_USED */
    #ifdef MCL_DMA_CH_76_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 76
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_76_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_76);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_76_ISR_USED */
    #ifdef MCL_DMA_CH_77_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 77
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_77_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_77);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_77_ISR_USED */
    #ifdef MCL_DMA_CH_78_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 78
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_78_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_78);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_78_ISR_USED */
    #ifdef MCL_DMA_CH_79_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 79
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_79_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_79);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_79_ISR_USED */
    #ifdef MCL_DMA_CH_80_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 80
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_80_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_80);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_80_ISR_USED */
    #ifdef MCL_DMA_CH_81_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 81
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_81_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_81);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_81_ISR_USED */
    #ifdef MCL_DMA_CH_82_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 82
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_82_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_82);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_82_ISR_USED */
    #ifdef MCL_DMA_CH_83_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 83
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_83_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_83);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_83_ISR_USED */
    #ifdef MCL_DMA_CH_84_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 84
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_84_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_84);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_84_ISR_USED */
    #ifdef MCL_DMA_CH_85_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 85
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_85_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_85);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_85_ISR_USED */
    #ifdef MCL_DMA_CH_86_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 86
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_86_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_86);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_86_ISR_USED */
    #ifdef MCL_DMA_CH_87_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 87
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_87_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_87);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_87_ISR_USED */
    #ifdef MCL_DMA_CH_88_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 88
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_88_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_88);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_88_ISR_USED */
    #ifdef MCL_DMA_CH_89_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 89
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_89_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_89);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_89_ISR_USED */
    #ifdef MCL_DMA_CH_90_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 90
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_90_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_90);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_90_ISR_USED */
    #ifdef MCL_DMA_CH_91_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 91
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_91_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_91);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_91_ISR_USED */
    #ifdef MCL_DMA_CH_92_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 92
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_92_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_92);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_92_ISR_USED */
    #ifdef MCL_DMA_CH_93_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 93
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_93_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_93);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_93_ISR_USED */
    #ifdef MCL_DMA_CH_94_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 94
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_94_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_94);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_94_ISR_USED */
    #ifdef MCL_DMA_CH_95_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 95
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_95_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_95);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_95_ISR_USED */
    #ifdef MCL_DMA_CH_96_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 96
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_96_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_96);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_96_ISR_USED */
    #ifdef MCL_DMA_CH_97_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 97
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_97_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_97);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_97_ISR_USED */
    #ifdef MCL_DMA_CH_98_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 98
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_98_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_98);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_98_ISR_USED */
    #ifdef MCL_DMA_CH_99_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 99
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_99_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_99);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_99_ISR_USED */
    #ifdef MCL_DMA_CH_100_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 100
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_100_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_100);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_100_ISR_USED */
    #ifdef MCL_DMA_CH_101_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 101
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_101_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_101);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_101_ISR_USED */
    #ifdef MCL_DMA_CH_102_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 102
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_102_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_102);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_102_ISR_USED */
    #ifdef MCL_DMA_CH_103_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 103
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_103_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_103);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_103_ISR_USED */
    #ifdef MCL_DMA_CH_104_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 104
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_104_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_104);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_104_ISR_USED */
    #ifdef MCL_DMA_CH_105_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 105
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_105_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_105);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_105_ISR_USED */
    #ifdef MCL_DMA_CH_106_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 106
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_106_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_106);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_106_ISR_USED */
    #ifdef MCL_DMA_CH_107_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 107
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_107_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_107);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_107_ISR_USED */
    #ifdef MCL_DMA_CH_108_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 108
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_108_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_108);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_108_ISR_USED */
    #ifdef MCL_DMA_CH_109_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 109
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_109_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_109);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_109_ISR_USED */
    #ifdef MCL_DMA_CH_110_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 110
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_110_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_110);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_110_ISR_USED */
    #ifdef MCL_DMA_CH_111_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 111
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_111_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_111);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_111_ISR_USED */
    #ifdef MCL_DMA_CH_112_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 112
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_112_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_112);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_112_ISR_USED */
    #ifdef MCL_DMA_CH_113_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 113
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_113_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_113);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_113_ISR_USED */
    #ifdef MCL_DMA_CH_114_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 114
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_114_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_114);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_114_ISR_USED */
    #ifdef MCL_DMA_CH_115_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 115
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_115_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_115);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_115_ISR_USED */
    #ifdef MCL_DMA_CH_116_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 116
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_116_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_116);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_116_ISR_USED */
    #ifdef MCL_DMA_CH_117_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 117
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_117_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_117);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_117_ISR_USED */
    #ifdef MCL_DMA_CH_118_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 118
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_118_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_118);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_118_ISR_USED */
    #ifdef MCL_DMA_CH_119_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 119
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_119_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_119);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_119_ISR_USED */
    #ifdef MCL_DMA_CH_120_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 120
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_120_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_120);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_120_ISR_USED */
    #ifdef MCL_DMA_CH_121_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 121
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_121_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_121);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_121_ISR_USED */
    #ifdef MCL_DMA_CH_122_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 122
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_122_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_122);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_122_ISR_USED */
    #ifdef MCL_DMA_CH_123_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 123
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_123_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_123);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_123_ISR_USED */
    #ifdef MCL_DMA_CH_124_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 124
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_124_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_124);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_124_ISR_USED */
    #ifdef MCL_DMA_CH_125_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 125
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_125_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_125);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_125_ISR_USED */
    #ifdef MCL_DMA_CH_126_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 126
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_126_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_126);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_126_ISR_USED */
    #ifdef MCL_DMA_CH_127_ISR_USED

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA channel: 127
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_CH_127_ISR)
    {
        Mcl_DmaProcessInterrupt(DMA_HW_CHANNEL_127);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_CH_127_ISR_USED */
#endif
#endif

#if (MCL_DMA_COMBINED_ERROR_ISR  == STD_OFF)
    #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA Combined Error
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA0_ERROR_ISR)
    {
        Mcl_DmaProcessErrorInterrupt(DMA_INSTANCE0);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #if (MCL_DMA_NB_CONTROLLERS == 0x02U)
    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for DMA Combined Error
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA1_ERROR_ISR)
    {
        Mcl_DmaProcessErrorInterrupt(DMA_INSTANCE1);
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif
    #endif /* MCL_DMA_ERROR_INTERRUPTS_USED */
#endif

#if (MCL_DMA_COMBINED_ERROR_ISR  == STD_ON)
    #if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)

    /**
    * @brief          Independent interrupt handler.
    * @details        Interrupt handler for the case when one combined error ISR is availabl for more than 1 DMA controllers
    *
    * @isr
    */
    /** @violates @ref MCL_DMA_IRQ_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
    ISR(MCL_DMA_ERROR_ISR)
    {
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        VAR(uint32,AUTOMATIC) u32ErrorStatus0 = REG_READ32(DMA_ES_ADDR32((uint32)(DMA_INSTANCE0)));
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        VAR(uint32,AUTOMATIC) u32ErrorStatus1 = REG_READ32(DMA_ES_ADDR32((uint32)(DMA_INSTANCE1)));
        
       if ((uint32)0 != u32ErrorStatus0)
       {    
            Mcl_DmaProcessErrorInterrupt(DMA_INSTANCE0);        
       }
       else
       {
            /*Empty else to fix misra*/
       }

       if ((uint32)0 != u32ErrorStatus1)
       {   
            Mcl_DmaProcessErrorInterrupt(DMA_INSTANCE1);
       }
       else
       {
         /*Empty else to fix misra*/
       }
        /** @violates @ref MCL_DMA_IRQ_C_REF_1 cast from unsigned int to pointer */
        EXIT_INTERRUPT();
    }
    #endif /* MCL_DMA_ERROR_INTERRUPTS_USED */
#endif
#define MCL_STOP_SEC_CODE
/** @violates @ref MCL_DMA_IRQ_C_REF_2 only preprocessor statements and comments before "#include" */
/** @violates @ref MCL_DMA_IRQ_C_REF_3 only preprocessor statements and comments before "#include" */
#include "Mcl_MemMap.h"

#endif
#endif

#ifdef __cplusplus
}
#endif

/** @} */
