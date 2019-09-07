/**
*   @file    Adc_Reg_eSys_Pdb.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Pdb module registers, and macrodefinitions used to manipulate the module registers.
*
*   @addtogroup PDB
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
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713;
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef REG_ESYS_PDB_H
#define REG_ESYS_PDB_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_Pdb_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
* 
* @section Reg_eSys_Pdb_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated. All used compielr support 31 character significance case sensitivity for external identifiers.
*
* @section Reg_eSys_Pdb_h_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
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
#include "Reg_eSys.h"
#include "Adc_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_PDB_VENDOR_ID_REG                      43
#define ADC_PDB_AR_RELEASE_MAJOR_VERSION_REG       4
#define ADC_PDB_AR_RELEASE_MINOR_VERSION_REG       2
#define ADC_PDB_AR_RELEASE_REVISION_VERSION_REG    2
#define ADC_PDB_SW_MAJOR_VERSION_REG               1
#define ADC_PDB_SW_MINOR_VERSION_REG               0
#define ADC_PDB_SW_PATCH_VERSION_REG               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/** @violates @ref Reg_eSys_Pdb_h_REF_2 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Reg_eSys.h are of the same Autosar version */
#if ((ADC_PDB_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_PDB_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Reg_eSys_Pdb.h and Reg_eSys.h are different"
#endif
/* Check if source file and Adc_CfgDefines.h are of the same Autosar version */
#if ((ADC_PDB_AR_RELEASE_MAJOR_VERSION_REG != ADC_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES ) || \
     (ADC_PDB_AR_RELEASE_MINOR_VERSION_REG != ADC_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) \
    )
#error "AutoSar Version Numbers of Adc_CfgDefines.h and Reg_eSys.h are different"
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONST_32
/** @violates @ref Reg_eSys_Pdb_h_REF_4 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

extern CONST(uint32, ADC_CONST) PDB_BASE_ADDR32[ADC_PDB_NUM_MODULES];

#define ADC_STOP_SEC_CONST_32
/** @violates @ref Reg_eSys_Pdb_h_REF_4 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief          PDB Base address definition.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_ADDR32(HwUnit)                      (PDB_BASE_ADDR32[(HwUnit)])

/**
* @brief          Status and Control Register (SC).
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_SC_REG_ADDR32(HwUnit)           (PDB_ADDR32(HwUnit) + 0x0000UL)

/**
* @brief          Modulus Register (MOD).
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_MOD_REG_ADDR32(HwUnit)          (PDB_ADDR32(HwUnit) + 0x0004UL)

/**
* @brief          Counter Register (CNT).
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_CNT_REG_ADDR32(HwUnit)          (PDB_ADDR32(HwUnit) + 0x0008UL)

/**
* @brief          Interrupt Delay Register (IDLY).
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_IDLY_REG_ADDR32(HwUnit)         (PDB_ADDR32(HwUnit) + 0x000CUL)

/**
* @brief          There are only 2 channels (0,1) available for this module.
*/

/**
* @brief          Channel n Control Register 1 (CHnC1).
*  
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_CHCn1_REG_ADDR32(HwUnit, chNr)          (PDB_ADDR32(HwUnit) + ((chNr) * 0x0028UL) + 0x0010UL)

/**
* @brief          Channel n Status Register (CHnS).
*
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_CHnS_REG_ADDR32(HwUnit, chNr)           (PDB_ADDR32(HwUnit) + ((chNr) * 0x0028UL) + 0x0014UL)

/**
* @brief        Channel n Delay x Register (CHnDLYx).
*
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_CHnDLYx_REG_ADDR32(HwUnit, chNr, regNr)        (PDB_ADDR32(HwUnit) + ((chNr) * 0x0028UL) + ((regNr) * 0x0004UL) + 0x0018UL)

/**
* @brief          DAC Interval Trigger n Control Register (DACINTCn).
*
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_DACINTCn_REG_ADDR32(HwUnit, chNr)       (PDB_ADDR32(HwUnit) + ((chNr) * 0x0008UL) + 0x0150UL)

/**
* @brief          DAC Interval n Register (DACINTn).
*
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_DACINTn_REG_ADDR32(HwUnit, chNr)        (PDB_ADDR32(HwUnit) + ((chNr) * 0x0008UL) + 0x0154UL)

/**********************************************************************************
***************           Status and Control Register (SC)           **************
**********************************************************************************/
/**
* @brief        LDMOD: Load Mode Select.
* @details      Selects the mode to load the MOD, IDLY, CHnDLYm, INTx, and POyDLY registers, 
*                after 1 is written to LDOK. 
*                      If set to 00 the internal registers are loaded with the values from their 
*                buffers immediately after 1 is written to LDOK;
*                    If set to 01 the internal registers are loaded with the values from their 
*                buffers when the PDB counter reaches the MOD register value after 1 is written 
*                to LDOK.
*                    If set to 10 the internal registers are loaded with the values from their 
*                buffers when a trigger input event is detected after 1 is written to LDOK.
*                    If set to 11 the internal registers are loaded with the values from their 
*                buffers when either the PDB counter reaches the MOD register value or a trigger 
*                input event is detected, after 1 is written to LDOK.
*/
#define PDB_LOADMODE_IMMEDIATE_U32                    (0x0UL)
#define PDB_LOADMODE_COUNTER_U32                      (0x00040000UL)
#define PDB_LOADMODE_TRIGGER_U32                      (0x00080000UL)
#define PDB_LOADMODE_COUNTER_TRIGGER_U32              (0x000C0000UL)

/**
* @brief        PDBEIE: PDB Sequence Error Interrupt Enable.
* @details      Enables the PDB sequence error interrupt. When this field is set, any of the 
*                PDB channel sequence error flags generates a PDB sequence error interrupt.
*/
#define PDB_ERROR_INTERRUPT_ENABLED_U32                (0x00020000UL)
#define PDB_ERROR_INTERRUPT_DISABLED_U32               (0x0UL)

/**
* @brief        SWTRIG: Software Trigger.
* @details      When PDB is enabled and the software trigger is selected as the trigger input 
*                source, writing 1 to this field resets and restarts the counter. Writing 0 to 
*                this field has no effect. Reading this field results 0.
*/
#define PDB_SOFTWARE_TRIGGER_RESET_COUNTER_U32         (0x00010000UL)

/**
* @brief        DMAEN: DMA Enable.
* @details      When DMA is enabled, the PDBIF flag generates a DMA request instead of an 
*                interrupt.
*/
#define PDB_DMA_ENABLED_U32                            (0x00008000UL)
#define PDB_DMA_DISABLED_U32                           (0x0UL)

/**
* @brief        PRESCALER: Prescaler Divider Select.
* @details      When DMA is enabled, the PDBIF flag generates a DMA request instead of an 
*                interrupt.
*                000: Counting uses the peripheral clock divided by multiplication factor selected 
*                     by MULT.
*                001: Counting uses the peripheral clock divided by twice of the multiplication 
*                     factor selected by MULT.
*                010: Counting uses the peripheral clock divided by 4 times of the multiplication 
*                     factor selected by MULT.
*                011: Counting uses the peripheral clock divided by 8 times of the multiplication 
*                     factor selected by MULT.
*                100: Counting uses the peripheral clock divided by 16 times of the multiplication 
*                     factor selected by MULT.
*                101: Counting uses the peripheral clock divided by 32 times of the multiplication 
*                     factor selected by MULT.
*                110: Counting uses the peripheral clock divided by 64 times of the multiplication 
*                     factor selected by MULT.
*                111: Counting uses the peripheral clock divided by 128 times of the multiplication 
*                     factor selected by MULT.
*/
#define PDB_PRESCALER_MULT_DIVIDED_1_U32                  (0x0UL)
#define PDB_PRESCALER_MULT_DIVIDED_2_U32                  (0x00001000UL)
#define PDB_PRESCALER_MULT_DIVIDED_4_U32                  (0x00002000UL)
#define PDB_PRESCALER_MULT_DIVIDED_8_U32                  (0x00003000UL)
#define PDB_PRESCALER_MULT_DIVIDED_16_U32                 (0x00004000UL)
#define PDB_PRESCALER_MULT_DIVIDED_32_U32                 (0x00005000UL)
#define PDB_PRESCALER_MULT_DIVIDED_64_U32                 (0x00006000UL)
#define PDB_PRESCALER_MULT_DIVIDED_128_U32                (0x00007000UL)

/**
* @brief        TRGSEL: Trigger Input Source Select.
* @details      Selects the trigger input source for the PDB. The trigger input source can be 
*                internal or external (EXTRG pin), or the software trigger.
*                0000: Trigger-In 0 is selected.
*                0001: Trigger-In 1 is selected.
*                0010: Trigger-In 2 is selected.
*                0011: Trigger-In 3 is selected.
*                0100: Trigger-In 4 is selected.
*                0101: Trigger-In 5 is selected.
*                0110: Trigger-In 6 is selected.
*                0111: Trigger-In 7 is selected.
*                1000: Trigger-In 8 is selected.
*                1001: Trigger-In 9 is selected.
*                1010: Trigger-In 10 is selected.
*                1011: Trigger-In 11 is selected.
*                1100: Trigger-In 12 is selected.
*                1101: Trigger-In 13 is selected.
*                1110: Trigger-In 14 is selected.
*                1111: Software trigger is selected.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_TRIGGERn_SEL_U32(nrTrg)                      ((nrTrg) << 8U)
#define PDB_SOFTWARE_TRIGGER_U32                         (0xFU) 
#define PDB_SC_TRGSEL_MASK_U32                           (0x00000F00UL)                        

/**
* @brief        PDBEN: PDB Enable.
* @details      0: PDB disabled. Counter is off.
*               1: PDB enabled.
*/
#define PDB_ENABLED_U32                                 (0x00000080UL)
#define PDB_DISABLED_U32                                (0x0UL)

/**
* @brief        PDBIF: PDB Interrupt Flag.
* @details      This field is set when the counter value is equal to the IDLY register. 
*                Writing zero clears this field.
*/
#define PDB_INTERRUPT_FLAG_MASK_U32                     (0x00000040UL)
#define PDB_INTERRUPT_FLAG_RESET_U32                    (0x0UL)

/**
* @brief        PDBIE: PDB Interrupt Enable.
* @details      Enables the PDB interrupt. When this field is set and DMAEN is cleared, 
*                PDBIF generates a PDB interrupt.
*/
#define PDB_INTERRUPT_ENABLED_U32                       (0x00000020UL)
#define PDB_INTERRUPT_DISABLED_U32                      (0x0UL)

/**
* @brief        MULT: Multiplication Factor Select for Prescaler.
* @details      Selects the multiplication factor of the prescaler divider for the counter clock.
*                00: Multiplication factor is 1.
*                01: Multiplication factor is 10.
*                10: Multiplication factor is 20.
*                11: Multiplication factor is 40.
*/
#define PDB_MULT_1_U32                                 (0x0UL)
#define PDB_MULT_10_U32                                (0x00000004UL)
#define PDB_MULT_20_U32                                (0x00000008UL)
#define PDB_MULT_40_U32                                (0x0000000CUL)

/**
* @brief        CONT: Continuous Mode Enable.
* @details      Enables the PDB operation in Continuous mode.
*                0: PDB operation in One-Shot mode.
*                1: PDB operation in Continuous mode.
*/
#define PDB_ONE_SHOT_MODE_U32                           (0x0UL)
#define PDB_CONTINUOUS_MODE_U32                         (0x00000002UL)

/**
* @brief        LDOK: Load OK.
* @details      Writing 1 to this bit updates the internal registers of MOD, IDLY, CHnDLYm, 
*                DACINTx,and POyDLY with the values written to their buffers. The MOD, IDLY, 
*                CHnDLYm, DACINTx, and POyDLY will take effect according to the LDMOD.
*                After 1 is written to the LDOK field, the values in the buffers of above registers 
*                are not effective and the buffers cannot be written until the values in buffers 
*                are loaded into their internal registers.
*                LDOK can be written only when PDBEN is set or it can be written at the same time 
*                with PDBEN being written to 1. It is automatically cleared when the values in 
*                buffers are loaded into the internal registers or the PDBEN is cleared. 
*                Writing 0 to it has no effect.
*/
#define PDB_LOAD_OK_U32                                 (0x00000001UL)
#define PDB_SC_RESET_VALUE_U32                          (0x0UL)

/**
* @brief        ERR: PDB Channel Sequence Error Flags.
* @details      Sequence error detected on PDB channel's corresponding pre-trigger.
*               0: PSequence error not detected.
*               1: Sequence error detected.
*/
#define PDB_ERR_FLAGS_MASK_U32                          (0x000000FFUL)
#define PDB_ERR_FLAGS_CLEAR_U32                         (0x0UL)

/**************************************************************************************************
*************************         Modulus Register (MOD)          *********************************
***************************************************************************************************/
/**
* @brief        MOD: PDB Modulus.
* @details      Specifies the period of the counter. When the counter reaches this value, it will 
*                be reset back to zero. If the PDB is in Continuous mode, the count begins anew. 
*                Reading this field returns the value of the internal register that is effective 
*                for the current cycle of PDB.
*/
#define PDB_MOD_MASK_U32                                (0x0000FFFFUL)
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_COUNTER_PERIOD_U32(Val)                     ((Val) & PDB_MOD_MASK_U32)
#define PDB_MOD_RESET_VALUE_U32                         (0x0000FFFFUL)

/**************************************************************************************************
*************************         Counter Register (CNT)          *********************************
***************************************************************************************************/
/**
* @brief        CNT: PDB Counter.
* @details      Contains the current value of the counter.
*/
#define PDB_CNT_MASK_U32                                 (0x0000FFFFUL)
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_COUNTER_VALUE_U32(Val)                       ((Val) & PDB_CNT_MASK_U32)
#define PDB_COUNTER_RESET_VALUE_U32                      (0x0UL)

/**************************************************************************************************
*********************         Interrupt Delay Register (IDLY)          ****************************
***************************************************************************************************/
/**
* @brief        IDLY: PDB Interrupt Delay.
* @details      Specifies the delay value to schedule the PDB interrupt. It can be used to schedule 
*                an independent interrupt at some point in the PDB cycle. If enabled, a PDB interrupt 
*                is generated, when the counter is equal to the IDLY. Reading this field returns the 
*                value of internal register that is effective for the current cycle of the PDB.
*/
#define PDB_DLY_MASK_U32                                 (0x0000FFFFUL)
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_INTERRUPT_DELAY_VALUE_U32(Val)               ((Val) & PDB_DLY_MASK_U32)
#define PDB_INTERRUPT_DELAY_RESET_VALUE_U32              (0x0000FFFFUL)

/**************************************************************************************************
******************         Channel n Control Register 1 (CHnC1)          **************************
***************************************************************************************************/
/**
* @brief        BB: PDB Channel Pre-Trigger Back-to-Back Operation Enable.
* @details      These bits enable the PDB ADC pre-trigger operation as back-to-back mode. 
*                Back-to-back operation enables the ADC conversions complete to trigger the next PDB 
*                channel pre-trigger and trigger output, so that the ADC conversions can be triggered 
*                on next set of configuration and results registers. 
*                Application code must only enable the back-to-back operation of the PDB pre-triggers 
*                at the leading of the back-to-back connection chain.
*                0: PDB channel's corresponding pre-trigger back-to-back operation disabled.
*                1: PDB channel's corresponding pre-trigger back-to-back operation enabled.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_PRE_TRIGGER_BB_CH_ENABLED_U32(chNr)         (1UL << (16U + (chNr)))
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_PRE_TRIGGER_BB_CH_MASK_U32(chNr)            (PDB_PRE_TRIGGER_BB_CH_ENABLED_U32(chNr))
#define PDB_PRE_TRIGGER_BB_CH_DISABLED_U32              (0x0UL)

/**
* @brief        TOS: PDB Channel Pre-Trigger Output Select.
* @details      Selects the PDB ADC pre-trigger outputs.
*                0: PDB channel's corresponding pre-trigger is in bypassed mode. The pre-trigger 
*                asserts one peripheral clock cycle after a rising edge is detected on selected 
*                trigger input source or software trigger is selected and SWTRIG is written with 1.
*                1: PDB channel's corresponding pre-trigger asserts when the counter reaches the 
*                channel delay register and one peripheral clock cycle after a rising edge is 
*                detected on selected trigger input source or software trigger is selected and 
*                SETRIG is written with 1.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/

#define PDB_PRE_TRIGGER_OUTPUT_MASK_U32(chNr)            (1UL << (8U + (chNr)))
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_PRE_TRIGGER_OUTPUT_DELAY_U32(chNr)           (PDB_PRE_TRIGGER_OUTPUT_MASK_U32(chNr))
#define PDB_PRE_TRIGGER_OUTPUT_BYPASSED_U32              (0X0UL)
/**
* @brief        EN: PDB Channel Pre-Trigger Enable.
* @details      These bits enable the PDB ADC pre-trigger outputs.
*                0: PDB channel's corresponding pre-trigger disabled.
*                1: PDB channel's corresponding pre-trigger enabled.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_PRE_TRIGGER_CH_ENABLED_MASK_U32(chNr)        (1UL << (chNr))
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_PRE_TRIGGER_CH_ENABLED_U32(chNr)             (PDB_PRE_TRIGGER_CH_ENABLED_MASK_U32(chNr))
#define PDB_PRE_TRIGGER_CH_DISABLED_U32                  (0x0UL)
#define PDB_CH_CONTROL_RESET_VALUE_U32                   (0x0UL)

/**************************************************************************************************
**********************        Channel n Status Register (CHnS)          ***************************
***************************************************************************************************/
/**
* @brief        CF: PDB Channel Flags.
* @details      The CF[m] bit is set when the PDB counter matches the CHnDLYm. 
*                Write 0 to clear these bits.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_STATUS_CH_FLAG_MASK_U32(chNr)                (1UL << (16U + (chNr)))
#define PDB_STATUS_CH_FLAGS_MASK_U32                     (0x00FF0000UL)
#define PDB_STATUS_CH_FLAGS_CLEAR_ALL_U32                (0x0UL)

/**
* @brief        ERR: PDB Channel Sequence Error Flags.
* @details      0: Sequence error not detected on PDB channel's corresponding pre-trigger.
*                1: Sequence error detected on PDB channel's corresponding pre-trigger. 
*                   ADCn block can be triggered for a conversion by one pre-trigger from PDB 
*                   channel n. When one conversion, which is triggered by one of the pre-triggers 
*                   from PDB channel n, is in progress, new trigger from PDB channel's corresponding 
*                   pre-trigger m cannot be accepted by ADCn, and ERR[m] is set. Writing 0’s to 
*                   clear the sequence error flags.
* @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined
*/
#define PDB_STATUS_CH_ERROR_FLAG_U32(chNr)              (1UL << (16U + (chNr)))
#define PDB_STATUS_CH_ERROR_FLAGS_MASK_U32              (0x000000FFUL)
#define PDB_STATUS_CH_ERROR_FLAGS_CLEAR_ALL_U32         (0x0UL)
#define PDB_CH_STATUS_RESET_VALUE_U32                   (0x0UL)

/**************************************************************************************************
*******************         Channel n Delay m Register (CHnDLYm)          *************************
***************************************************************************************************/
/**
* @brief        DLY: PDB Channel Delay.
* @details      Specifies the delay value for the channel's corresponding pre-trigger. 
*                The pre-trigger asserts when the counter is equal to DLY. Reading this field 
*                returns the value of internal register that is effective for the current PDB cycle.
*/
#define PDB_CHANNEL_DELAY_MASK_U32                      (0x0000FFFFUL)
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_CHANNEL_DELAY_VALUE_U32(Val)                ((Val) & PDB_CHANNEL_DELAY_MASK_U32)
#define PDB_CH_DELAY_RESET_VALUE_U32                    (0x0UL)

/**************************************************************************************************
*****************        DAC Interval Trigger n Control Register (DACINTCn)        ****************
***************************************************************************************************/
/**
* @brief        EXT: DAC External Trigger Input Enable.
* @details      Enables the external trigger for DAC interval counter. 
*                0: DAC external trigger input disabled. DAC interval counter is reset and counting 
*                   starts when a rising edge is detected on selected trigger input source or software 
*                   trigger is selected and SWTRIG is written with 1.
*                1: DAC external trigger input enabled. DAC interval counter is bypassed and DAC 
*                   external trigger input triggers the DAC interval trigger.
*/
#define PDB_DAC_EXT_TRIGGER_INPUT_ENABLED_U32          (0x00000002UL)
#define PDB_DAC_EXT_TRIGGER_INPUT_DISABLED_U32         (0x0UL)

/**
* @brief        TOE: DAC Interval Trigger Enable.
* @details      This bit enables the DAC interval trigger.
*                0: DAC interval trigger disabled.
*                1: DAC interval trigger enabled.
*/
#define PDB_DAC_INTERVAL_TRIGGER_ENABLED_U32           (0x00000001UL)
#define PDB_DAC_INTERVAL_TRIGGER_DISABLED_U32          (0x0UL)
#define PDB_DACINTCn_RESET_VALUE_U32                   (0x0UL)

/**************************************************************************************************
*******************         DAC Interval n Register (DACINTn)          ****************************
***************************************************************************************************/
/**
* @brief        INT: DAC Interval.
* @details      Specifies the interval value for DAC interval trigger. DAC interval trigger 
*                triggers DAC[1:0] update when the DAC interval counter is equal to the DACINT. 
*                Reading this field returns the value of internal register that is effective for 
*                the current PDB cycle.
*/
#define PDB_DAC_INTERVAL_MASK_U32                      (0x0000FFFFUL)
/** @violates @ref Reg_eSys_Pdb_h_REF_1 Function-like macro defined */
#define PDB_DAC_INTERVAL_VALUE_U32(Val)                ((Val) & PDB_DAC_INTERVAL_MASK_U32)
#define PDB_DACINTn_RESET_VALUE_U32                    (0x0UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_PDB_H */

/** @} */
