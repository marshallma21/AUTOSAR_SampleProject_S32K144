/**
*   @file    Adc_Pdb.c
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
* @section Adc_Pdb_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Pdb_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_Pdb_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as an
* unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Pdb_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters signifiance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Pdb_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation occurs because of the interaction with MCL module or because of  ISR symbols that
* need to be exported
*
* @section Adc_Pdb_c_REF_6
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Pdb_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Pdb_c_REF_8
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope
* if they are only accessed from within a single function.
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
#include "Adc_Cfg.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#endif
#include "SilRegMacros.h"

#include "Adc_Reg_eSys_Pdb.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_AR_VENDOR_ID_PDB_C                 43
/** @violates @ref Adc_Pdb_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MAJOR_VERSION_PDB_C     4
/** @violates @ref Adc_Pdb_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MINOR_VERSION_PDB_C     2
/** @violates @ref Adc_Pdb_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_PDB_C  2
#define ADC_SW_MAJOR_VERSION_PDB_C             1
#define ADC_SW_MINOR_VERSION_PDB_C             0
#define ADC_SW_PATCH_VERSION_PDB_C             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/* Check if source file and Adc_Reg_eSys_Pdb header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_PDB_C != ADC_PDB_VENDOR_ID_REG)
    #error "Adc_Pdb.c and Adc_Reg_eSys_Pdb.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Pdb header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_C != ADC_PDB_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB_C != ADC_PDB_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB_C != ADC_PDB_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Pdb.c and Adc_Reg_eSys_Pdb.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Pdb header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PDB_C != ADC_PDB_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_PDB_C != ADC_PDB_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_PDB_C != ADC_PDB_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Adc_Pdb.c and Adc_Reg_eSys_Pdb.h are different"
#endif



/* Check if source file and Adc_Pdb header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_PDB_C != ADC_VENDOR_ID_PDB)
    #error "Adc_Pdb.c and Adc_Pdb.h have different vendor ids"
#endif

/* Check if source file and Adc_Pdb header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_C != ADC_AR_RELEASE_MAJOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB_C != ADC_AR_RELEASE_MINOR_VERSION_PDB) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB_C != ADC_AR_RELEASE_REVISION_VERSION_PDB) \
    )
    #error "AutoSar Version Numbers of Adc_Pdb.c and Adc_Pdb.h are different"
#endif

/* Check if source file and Adc_Pdb header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PDB_C != ADC_SW_MAJOR_VERSION_PDB) || \
     (ADC_SW_MINOR_VERSION_PDB_C != ADC_SW_MINOR_VERSION_PDB) || \
     (ADC_SW_PATCH_VERSION_PDB_C != ADC_SW_PATCH_VERSION_PDB) \
    )
    #error "Software Version Numbers of Adc_Pdb.c and Adc_Pdb.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_PDB_C != ADC_VENDOR_ID_CFG)
#error "Adc_Pdb.c and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_C != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PDB_C != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PDB_C != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc_Pdb.c and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_PDB_C != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION_PDB_C != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION_PDB_C != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc_Pdb.c and Adc_Cfg.h are different"
#endif

/** @violates @ref Adc_Pdb_c_REF_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_PDB_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Pdb.c and Mcal.h are different"
 #endif
 /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_PDB_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_PDB_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Pdb.c and SilRegMacros.h are different"
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
#define ADC_START_SEC_CONST_32
/** @violates @ref Adc_Pdb_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Pdb_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"
/** @violates @ref Adc_Pdb_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
static CONST(uint32, ADC_CONST) PDB_CHNC1_MASK[] =
{
    0x0U,
    0x1U,
    0x3U,
    0x7U,
    0xFU,
    0x1FU,
    0x3FU,
    0x7FU,
    0xFFU
};
#define ADC_STOP_SEC_CONST_32
/** @violates @ref Adc_Pdb_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Pdb_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_CONST_32
/** @violates @ref Adc_Pdb_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Pdb_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"
/** @violates @ref Adc_Pdb_c_REF_5 External linkage.*/
CONST(uint32, ADC_CONST) PDB_BASE_ADDR32[ADC_PDB_NUM_MODULES] =
{
#ifdef PDB0_BASEADDR
    PDB0_BASEADDR,
#endif
#if (ADC_PDB_NUM_MODULES > 1U)
#ifdef PDB1_BASEADDR
    PDB1_BASEADDR
#endif
#endif
};
#define ADC_STOP_SEC_CONST_32
/** @violates @ref Adc_Pdb_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Pdb_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_Pdb_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Pdb_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          This function initializes PDB module
* @details        This function initializes PDB clock configuration: prescaler, multiplication, channel sequence error
*
* @param[in]      Unit                    the current HW Unit.
* @param[in]      u32PdbClockConfig       Clock configuration for PDB
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Pdb_Init
(
    VAR(Adc_HwUnitType,AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32PdbClockConfig
)
{
    /* Initialize PDB clock registers according to user configuration */
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PDB_SC_REG_ADDR32(Unit), u32PdbClockConfig);
}

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function deinitializes the PDB hardware.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Pdb_DeInit(void)
{
    VAR(uint8, AUTOMATIC) u8UnitIndex = 0U;
    VAR(uint8, AUTOMATIC) u8ChannelIndex = 0U;
    VAR(uint8, AUTOMATIC) u8RegisterIndex = 0U;

    /* De-initialize all units */
    for(u8UnitIndex = (uint8)0U; u8UnitIndex < (uint8)ADC_PDB_NUM_MODULES; u8UnitIndex++)
    {
        /* Reset period of the counter, when the counter reaches this value, it will be reset back to zero */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_MOD_REG_ADDR32(u8UnitIndex), PDB_MOD_RESET_VALUE_U32);

        /* Reset interrupt delay register */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_IDLY_REG_ADDR32(u8UnitIndex), PDB_INTERRUPT_DELAY_RESET_VALUE_U32);

        /* De-initialize for each unit channel */
        for (u8ChannelIndex = 0U; u8ChannelIndex < ADC_PDB_CHANNELS_U8; u8ChannelIndex++)
        {
            /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(PDB_CHCn1_REG_ADDR32(u8UnitIndex, u8ChannelIndex), PDB_CH_CONTROL_RESET_VALUE_U32);
            /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(PDB_CHnS_REG_ADDR32(u8UnitIndex, u8ChannelIndex), PDB_STATUS_CH_FLAGS_CLEAR_ALL_U32);

            /* De-initialize for each pre-trigger */
            for (u8RegisterIndex = 0U; u8RegisterIndex < ADC_PDB_NUM_DELAY_REGISTER; u8RegisterIndex++)
            {
                /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
                /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(PDB_CHnDLYx_REG_ADDR32(u8UnitIndex, u8ChannelIndex, u8RegisterIndex), PDB_CH_DELAY_RESET_VALUE_U32);
            }
        }

        /* Set Load OK bit to update de-initialize configuration */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(PDB_SC_REG_ADDR32(u8UnitIndex), PDB_LOAD_OK_U32);

        /* Reset the SC register */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_SC_REG_ADDR32(u8UnitIndex), PDB_SC_RESET_VALUE_U32);
    }
}
#endif

/**
* @brief          This function configure PDB hardware for each conversion
* @details        This function configure PDB hardware for each conversion
*
* @param[in]      Unit                    the current HW Unit.
* @param[in]      Group                   Channel group
* @param[in]      pGroupPtr               pointer to group configuration
* @param[in]      Trigger                 hardware or software trigger
* @param[in]      u16CurrentChannel       last channel converted
* @param[in]      u8NumChannel            number of channel used for this conversion
*
* @return         void
*
*/
/** @violates @ref Adc_Pdb_c_REF_5 External linkage.*/
FUNC(void, ADC_CODE) Adc_Pdb_ConfigurePartialConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Trigger,
    VAR(uint16, AUTOMATIC) u16CurrentChannel,
    VAR(uint8, AUTOMATIC) u8NumChannel
)
{
    VAR(uint8, AUTOMATIC) u8PdbIndex;
    VAR(uint8, AUTOMATIC) u8PreTriggerCtr;
    VAR(uint8, AUTOMATIC) u8PdbChannelUsed;
    VAR(uint16, AUTOMATIC) u16CurrentCh;
    VAR(uint32, AUTOMATIC) u32ChEnable;
    VAR(uint32, AUTOMATIC) u32ChConfig;
    VAR(uint8, AUTOMATIC) u8LeftChannel;
    VAR(uint8, AUTOMATIC) u8ChUsed;
    VAR(uint16, AUTOMATIC) u16PeriodPdb = 0U;
    VAR(uint16, AUTOMATIC) u16PdbDelay;
    P2CONST(uint16, ADC_VAR, ADC_APPL_CONST) pGroupDelay = NULL_PTR;
#if (ADC_SETCHANNEL_API == STD_ON)
    VAR(uint32, AUTOMATIC) u32TempMask = Adc_aRuntimeGroupChannel[Group].u32Mask;
#endif

    u8LeftChannel = u8NumChannel;

    /* Calculate number of PDB channels depending on the ADC channels used */
    /* Note that 1 PDB channel triggers to 8 ADC channels */
    u8PdbChannelUsed = (uint8)ADC_PDB_CHANNELS_USED(u8NumChannel);

    u16CurrentCh = u16CurrentChannel;
#if (ADC_SETCHANNEL_API == STD_ON)
    /* Get delay configuration of each pre-trigger */
    /* At runtime */
    pGroupDelay = Adc_aRuntimeGroupChannel[Group].pu16Delays;
#else
    /* Follow user configuration */
    pGroupDelay = pGroupPtr->pDelay;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

    /* Select the input trigger source for PDB */
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(PDB_SC_REG_ADDR32(Unit), PDB_SC_TRGSEL_MASK_U32 | PDB_ENABLED_U32, PDB_TRIGGERn_SEL_U32((uint32)Trigger) | PDB_ENABLED_U32);

    /* Configure PDB channels */
    for(u8PdbIndex = 0U; u8PdbIndex < u8PdbChannelUsed; u8PdbIndex++)
    {
        /* Get channels used depending on number of pre-triggers per PDB channel */
        u8ChUsed = ADC_NUM_CHANNELS_USED(u8LeftChannel);

        /* Get mask for enable used channels to CHnC1 register */
        u32ChEnable = (uint32)PDB_CHNC1_MASK[u8ChUsed];

        /* Configuration data for all field in CHnC! register */
        u32ChConfig = u32ChEnable;

        /* If group channel delay, not bypass mode */
        if((uint8)STD_ON == pGroupPtr->u8AdcGroupChannelDelays)
        {
            /* If Back to Back mode is disabled, enable and configure delays for all channels */
            if((uint8)STD_OFF == pGroupPtr->u8AdcGroupBackToBack)
            {
                u32ChConfig |= (u32ChEnable << 8U);
                for(u8PreTriggerCtr = 0U; u8PreTriggerCtr < u8ChUsed; u8PreTriggerCtr++)
                {
            #if (ADC_SETCHANNEL_API == STD_ON)
                    if(1U == (u32TempMask & 1U))
            #endif
                    {
                        /* Configure delay for each pre-trigger */
                        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
                        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
                        /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                        REG_WRITE32(PDB_CHnDLYx_REG_ADDR32(Unit, u8PdbIndex, u8PreTriggerCtr), pGroupDelay[u16CurrentCh + u8PreTriggerCtr]);
                    }
            #if (ADC_SETCHANNEL_API == STD_ON)
                    u32TempMask = u32TempMask >> 1U;
                    if (0U == u32TempMask)
                    {
                        break;
                    }
            #endif
                }
            }
            else /* ((uint8)STD_ON == pGroupPtr->u8AdcGroupBackToBack) */
                /* ((uint8)STD_ON == pGroupPtr->u8AdcGroupChannelDelays) */
            {
                /* Beginning part (8 ADC channels) of group will be configured in PDB channel 0 */
                if(0U == u16CurrentChannel)
                {
                    u32ChConfig |= (1UL << 8U);

                    /* First pre-trigger need to be configured as delay, others will be in back to back mode */
                    /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                    u16PdbDelay = pGroupDelay[0] + ((pGroupPtr->u16PdbDelay)*u8PdbIndex);
                    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
                    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
                    /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                    REG_WRITE32(PDB_CHnDLYx_REG_ADDR32(Unit, u8PdbIndex, (uint8)0), u16PdbDelay);
                }
                else
                {
                    /* The other parts will be configured in following PDB channels */
                    if(u8PdbIndex != 0U)
                    {
                        u32ChConfig |= (1UL << 8U);
                        u16PdbDelay = (pGroupPtr->u16PdbDelay)*u8PdbIndex;
                        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
                        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
                        /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                        REG_WRITE32(PDB_CHnDLYx_REG_ADDR32(Unit, u8PdbIndex, (uint8)0), u16PdbDelay);
                    }
                }
            }
        }
        else    /* ((uint8)STD_OFF == pGroupPtr->u8AdcGroupChannelDelays) */
        {
            /* Configure the delay for the second PDB in case of only back to back used */
            if(u8PdbIndex != 0U)
            {
                u32ChConfig |= (1UL << 8U);
            }
            u16PdbDelay = (pGroupPtr->u16PdbDelay)*u8PdbIndex;
            /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
            /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
            /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
            REG_WRITE32(PDB_CHnDLYx_REG_ADDR32(Unit, u8PdbIndex, (uint8)0), u16PdbDelay);
        }

        /* Update status channel for configuring PDB channel in next loop */
        u8LeftChannel -= u8ChUsed;
        u16CurrentCh += u8ChUsed;

        /* Use back to back mode for all channels but using delay in pre-trigger 0 */
        if((uint8)STD_ON == pGroupPtr->u8AdcGroupBackToBack)
        {
            u32ChConfig |= ((u32ChEnable - 1U) << 16U);
        }

        /* Update configuration to CHnC1 register for pre-trigger */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_CHCn1_REG_ADDR32(Unit, u8PdbIndex), u32ChConfig);
    }

#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
    /* If the continuous group is configured without interrupts then PDB will be configured as continuous mode */
    /* Program the Mode */
    if((ADC_CONV_MODE_CONTINUOUS == pGroupPtr->eMode) && ((uint8)STD_ON == pGroupPtr->u8AdcWithoutInterrupt))
    {
        u16PeriodPdb = pGroupPtr->u16PdbPeriod;
    }
    else
#endif /* ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED */
    {
        /* If group channel delay, not bypass mode */
        if((uint8)STD_ON == pGroupPtr->u8AdcGroupChannelDelays)
        {
            if((uint8)STD_OFF == pGroupPtr->u8AdcGroupBackToBack)
            {
                /* If delay mode for all pre-triggers, PDB period equals to value of last pre-trigger delay (i.e longest delay) */
                /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                u16PeriodPdb = pGroupDelay[(u16CurrentChannel + u8NumChannel) - 1U];
            }
            else    /* ((uint8)STD_ON == pGroupPtr->u8AdcGroupBackToBack) */
            {
                /* Period will be calculated depending on user configuration in back to back mode */
                /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
                u16PeriodPdb = pGroupDelay[0] + (uint16)((pGroupPtr->u16PdbDelay)*((uint16)u8PdbChannelUsed - 1U));
            }
        }
        else    /* ((uint8)STD_OFF == pGroupPtr->u8AdcGroupChannelDelays) */
        {
            /* All pre-trigger configured as user u16PdbDelay */
            /** @violates @ref Adc_Pdb_c_REF_6 Array indexing shall be the only allowed form of pointer arithmetic */
            u16PeriodPdb = (pGroupPtr->u16PdbDelay)*((uint16)u8PdbChannelUsed - 1U);
        }
    }

    /* Configure the period of counter */
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PDB_MOD_REG_ADDR32(Unit), u16PeriodPdb);

    /* Disable others PDB channels to avoid errors when PDB trigger the disabled channels */
    for(; u8PdbIndex < ADC_PDB_NUM_MODULES; u8PdbIndex++)
    {
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(PDB_CHCn1_REG_ADDR32(Unit, u8PdbIndex), 0U);
    }

    /* Load the configuration */
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(PDB_SC_REG_ADDR32(Unit), PDB_LOAD_OK_U32);

    /* Start software trigger */
    /* If trigger is not software trigger, hardware trigger or external trigger will be used */
    if (PDB_SOFTWARE_TRIGGER_U32 == Trigger)
    {
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(PDB_SC_REG_ADDR32(Unit), PDB_SOFTWARE_TRIGGER_RESET_COUNTER_U32);
    }
#if (ADC_SETCHANNEL_API == STD_OFF)
    /* Avoid compiler warning */
    (void)Group;
#endif
}

/**
* @brief          This function start software conversion via PDB
* @details        This function is used when no need to reconfigure PDB channels
*
* @param[in]      Unit                    the current HW Unit.
*
* @return         void
*
*/
/** @violates @ref Adc_Pdb_c_REF_5 External linkage.*/
FUNC(void, ADC_CODE) Adc_Pdb_StartSoftwareConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(PDB_SC_REG_ADDR32(Unit), PDB_SOFTWARE_TRIGGER_RESET_COUNTER_U32);
}

#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
/**
* @brief          This function changes mode of PDB hardware unit
* @details        This function changes PDB hardware unit to continuous trigger mode if ADC converts without interrupt
*
* @param[in]      Unit                    the current HW Unit.
*
* @return         void
*
*/
/** @violates @ref Adc_Pdb_c_REF_5 External linkage.*/
FUNC(void, ADC_CODE) Adc_Pdb_SetPdbMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bContinuous
)
{
    if((boolean)TRUE == bContinuous)
    {
        /* PDB operation in Continuous mode */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(PDB_SC_REG_ADDR32(Unit), PDB_CONTINUOUS_MODE_U32);
    }
    else
    {
        /* PDB operation in One-Shot mode */
        /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
        /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(PDB_SC_REG_ADDR32(Unit), PDB_CONTINUOUS_MODE_U32);
    }
}
#endif

/**
* @brief          This function stops PDB hardware unit
* @details        This function disables PDB module and make control registers to reset value
*
* @param[in]      Unit                    the current HW Unit.
*
* @return         void
*
*/
/** @violates @ref Adc_Pdb_c_REF_5 External linkage.*/
FUNC(void, ADC_CODE) Adc_Pdb_StopConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(PDB_SC_REG_ADDR32(Unit), PDB_ENABLED_U32);
#ifdef ADC_CONTINUOUS_NO_INTERRUPT_SUPPORTED
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(PDB_SC_REG_ADDR32(Unit), PDB_CONTINUOUS_MODE_U32);
#endif
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PDB_CHCn1_REG_ADDR32(Unit, (uint8)0), PDB_CH_CONTROL_RESET_VALUE_U32);
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PDB_CHCn1_REG_ADDR32(Unit, (uint8)1), PDB_CH_CONTROL_RESET_VALUE_U32);
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PDB_CHnS_REG_ADDR32(Unit, (uint8)0), PDB_CH_STATUS_RESET_VALUE_U32);
    /** @violates @ref Adc_Pdb_c_REF_3 cast from unsigned long to pointer */
    /** @violates @ref Adc_Pdb_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(PDB_CHnS_REG_ADDR32(Unit, (uint8)1), PDB_CH_STATUS_RESET_VALUE_U32);
}

#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_Pdb_c_REF_2 Repeated include file MemMap.h
 * @violates @ref Adc_Pdb_c_REF_1 Only preprocessor statements and comments before "#include"
 */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
