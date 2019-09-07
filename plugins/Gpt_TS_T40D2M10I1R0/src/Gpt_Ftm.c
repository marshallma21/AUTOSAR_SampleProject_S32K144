/**
*   @file    Gpt_Ftm.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Gpt - Ftm driver source file for GPT driver.
*   @details Ftm driver interface.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Ftm
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
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section GPT_FTM_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_FTM_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_FTM_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section GPT_FTM_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_FTM_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section GPT_FTM_C_REF_6
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not be
* implicitly converted to a different underlying type. Integer to pointer conversion, specific to
* the ISR entry / exit code.
*
* @section GPT_FTM_C_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
* @section GPT_FTM_C_REF_8
* Violates MISRA 2004 Required Rule 9.2, Braces shall be used to indicate and match the structure in the 
* non-zero initialisation of arrays and structures. At here, we tend to initialized for whole structure, however, 
* when configure only 1 controller is configured, tool reported as non-zero initialisation. 
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Ftm_Types.h"
#include "Gpt_Ipw_Irq.h"
#include "Gpt_Ftm.h"
#include "Reg_eSys_Ftm.h"
#include "SchM_Gpt.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#endif
#include "SilRegMacros.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Ftm.c
* @{
*/
#define GPT_FTM_VENDOR_ID_C                    43
/** @violates @ref GPT_FTM_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_FTM_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_FTM_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_FTM_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_FTM_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_FTM_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_FTM_SW_MAJOR_VERSION_C             1
#define GPT_FTM_SW_MINOR_VERSION_C             0
#define GPT_FTM_SW_PATCH_VERSION_C             1
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this source file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_FTM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Ftm.c and Std_Types.h are different"
    #endif

    /* Check if this source file and Gpt_Ftm_Types.h file are of the same Autosar version */
    #if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION_C != GPT_FTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_FTM_AR_RELEASE_MINOR_VERSION_C != GPT_FTM_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Ftm.c and Gpt_Ftm_Types.h are different"
    #endif
#endif

#if (GPT_FTM_VENDOR_ID_C != GPT_FTM_VENDOR_ID)
    #error "Gpt_Ftm.c and Gpt_Ftm.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION_C != GPT_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION_C != GPT_FTM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION_C != GPT_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ftm.c and Gpt_Ftm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_FTM_SW_MAJOR_VERSION_C != GPT_FTM_SW_MAJOR_VERSION) || \
     (GPT_FTM_SW_MINOR_VERSION_C != GPT_FTM_SW_MINOR_VERSION) || \
     (GPT_FTM_SW_PATCH_VERSION_C != GPT_FTM_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Ftm.c and Gpt_Ftm.h are different"
#endif

#if (GPT_FTM_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Gpt_Ftm.c and Reg_eSys_Ftm.h have different vendor ids"
#endif
/* Check if the source file and Gpt header file are of the same Autosar version */

#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ftm.c and Reg_eSys_Ftm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */

#if ((GPT_FTM_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (GPT_FTM_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (GPT_FTM_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Ftm.c and Reg_eSys_Ftm.h are different"
#endif

#if (GPT_FTM_VENDOR_ID_C != GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_Ftm.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ftm.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_FTM_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_FTM_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_FTM_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Ftm.c and Gpt_Ipw_Irq.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same vendor */
#if (GPT_FTM_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_Ftm.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_FTM_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_FTM_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Pit.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_FTM_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (GPT_FTM_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (GPT_FTM_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ftm.c and SilRegMacros.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/**
* @brief Number of counter cycles missed due to overflow
*/
#define FTM_OVERFLOW_PAD_U32         ((uint32)1U)

/**
* @brief Highest possible value for Ftm channels
*/
#define FTM_CNT_MAX_VALUE_U32              ((uint32)0xFFFFuL)

#define GPT_FTM_MODULE_CHAN_NUM            ((uint32)8U)

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_VAR_INIT_32
/** @violates @ref GPT_FTM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_FTM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/**
* @brief          Local array variable used to store the runtime target time value.
*/
/** @violates @ref GPT_FTM_C_REF_8 MISRA 2004 Rule 9.2, Braces shall be used to indicate and match the structure*/
static VAR(uint32, GPT_VAR) Gpt_Ftm_u32TargetValue[GPT_FTM_MODULES_NUM_U8][GPT_FTM_MODULE_CHAN_NUM_U8] = {{(uint32)0,(uint32)0}};

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/** @violates @ref GPT_FTM_C_REF_8 MISRA 2004 Rule 9.2, Braces shall be used to indicate and match the structure*/
static VAR(uint32, GPT_VAR) Gpt_Ftm_u32NextTargetValue[GPT_FTM_MODULES_NUM_U8][GPT_FTM_MODULE_CHAN_NUM_U8] = {{(uint32)0,(uint32)0}};
#endif

 #define GPT_STOP_SEC_VAR_INIT_32
/** @violates @ref GPT_FTM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_FTM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_FTM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_FTM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


#if (GPT_FTM_USED == STD_ON)

/**
* @brief   Driver routine to process all the interrupts of Ftm.
* @details Support function used by interrupt service routines to implement Ftm specific operations
*          and call the GPT upper layer handler to implement non-hardware specific operations.
*
* @param[in]     u8HwChannel      hardware channel index
*
* @implements   Gpt_Ftm_ProcessCommonInterrupt_Activity
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Ftm_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint32, AUTOMATIC) u32OldCompare;
    VAR(uint32, AUTOMATIC) u32TargetTime;
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned Ftm HW channel index */
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    u32Temp1 = REG_BIT_GET32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    u32Temp2 = REG_BIT_GET32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx),FTM_CSC_CHIE_MASK_U32);

    /*Check for spurious interrupts*/

    if ((FTM_CSC_CHF_EVENT_OCCURED_U32 == u32Temp1) &&
        (FTM_CSC_CHIE_ENABLE_U32 == u32Temp2))
    {
        /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
        u32OldCompare = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));

#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
        if(Gpt_Ftm_u32NextTargetValue[u8ModuleIdx][u8ChannelIdx] != 0x0U)
        {
            Gpt_Ftm_u32TargetValue[u8ModuleIdx][u8ChannelIdx] = Gpt_Ftm_u32NextTargetValue[u8ModuleIdx][u8ChannelIdx];
            Gpt_Ftm_u32NextTargetValue[u8ModuleIdx][u8ChannelIdx] = 0x0U;
        }
#endif

        u32TargetTime = Gpt_Ftm_u32TargetValue[u8ModuleIdx][u8ChannelIdx];

        if ((uint32)(u32OldCompare + u32TargetTime) > FTM_CNT_MAX_VALUE_U32)
        {
            /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx),  (uint32)(u32TargetTime - (FTM_CNT_MAX_VALUE_U32 - u32OldCompare)));
        }
        else
        {
            /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx),  (uint32)(u32OldCompare + u32TargetTime));
        }

        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8ChannelIdx, GPT_FTM_MODULE + ((uint8)GPT_FTM_CHANNELS_PER_MODULE_U8 * u8ModuleIdx));
        /* (uint8)GptFtmChannelsPos[u8ModuleIdx]); */
    }

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17();
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17();
}
#endif


/*================================================================================================*/
/**
* @brief   Gpt driver initialization function for Ftm module.
* @details This function is called separately for each Ftm hw channel corresponding to the configured
*          timer channels, and:
*          - disables the timer compare interrupts corresponding to Ftm channel
*          - clears the timer compare interrupt flags corresponding to Ftm channel
*          - configures the freeze mode (enabled or disabled)
*          - resets the counter register and counter initial value register.
*          - writes the channel value register and the modulo register with 0xFFFF
*          - sets the prescaler
*
* @param[in]     u8HwChannel             Ftm hw channel ID
* @param[in]     bFreezeEnable           indicates if the Freeze mode is enabled
* @param[in]     u8ClockSource           indicates the source clock for the module
* @param[in]     u8Prescaler             sets the prescaler value
*
*
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Ftm_Init(VAR(uint8, AUTOMATIC) u8HwChannel,
                                                VAR(boolean, AUTOMATIC) bFreezeEnable,
                                                VAR(uint8, AUTOMATIC) u8ClockSource,
                                                VAR(uint8, AUTOMATIC) u8Prescaler
                                                )
{

    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned Ftm HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    /* disable all interrupts on this channel*/
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

    /* clear interrupt flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    /* Clear Fault interrupt flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_FMS_ADDR32(u8ModuleIdx), (FTM_FMS_FAULTF_MASK_U32 | FTM_FMS_FAULTF3_MASK_U32 | FTM_FMS_FAULTF2_MASK_U32 | FTM_FMS_FAULTF1_MASK_U32 | FTM_FMS_FAULTF0_MASK_U32));

    /* Disable TOIE flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_TOIE_MASK_U32);

    /* Disable FAULTM flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(FTM_MODE_ADDR32(u8ModuleIdx), FTM_MODE_FAULTM_MASK_U32);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(FTM_MODE_ADDR32(u8ModuleIdx), FTM_MODE_FTMEN_MASK_U32);

    if ((boolean)TRUE == bFreezeEnable)
    {
        /* enable freeze */
        /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, ((uint32)0x0U << FTM_CONF_BDMMODE_SHIFT));

    }
    else
    {
        /* disable freeze */
        /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, ((uint32)0x3U << FTM_CONF_BDMMODE_SHIFT));
    }

    /* Set Counter register to 0 and Initial Counter Value to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNTIN_ADDR32(u8ModuleIdx), 1U);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNT_ADDR32(u8ModuleIdx), 1U);



    /* Set Compare Value register to 0xFFFF */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx), 0xFFFFU);


    /* write the Ftm Modulo Register with 0xFFFF */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_MOD_ADDR32(u8ModuleIdx), 0xFFFFU);

    /* set the prescaler with the wanted value */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_PS_MASK_U32,(uint32)u8Prescaler);

    /* configure the channel */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_MSA_MASK_U32);

    Gpt_Ftm_u32TargetValue[u8ModuleIdx][u8ChannelIdx] = 0U;

    /* set timer clock */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx) , FTM_SC_CLKS_MASK_U32, ((uint32)u8ClockSource<<FTM_SC_CLKS_SHIFT));

    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver de-initialization function for Ftm module.
* @details This function is called separately for each Ftm hw channel corresponding to the configured
*          timer channels, and:
*          - disables the timer compare interrupts corresponding to Ftm channel
*          - clears the timer compare interrupt flags corresponding to Ftm channel
*          - resets the counter register and the counter initial value register.
*          - resets the channel value register and the modulo register
*          - disables the freeze mode
*
* @param[in]     u8HwChannel        Ftm hw channel ID
*
*
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Ftm_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned Ftm HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);
    /* disable timer channel */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_CLKS_MASK_U32,FTM_SC_CLKS_NO_CLOCKS_U32);

    /* disable interrupts */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

    /* clear interrupt flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_MODE_ADDR32(u8ModuleIdx), FTM_MODE_FTMEN_MASK_U32);

    /*  Set Counter register to 0 and Initial Counter Value to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNTIN_ADDR32(u8ModuleIdx), 0U);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNT_ADDR32(u8ModuleIdx), 0U);

    /* Set Compare Value register to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx), 0U);

    /*  write the Ftm Modulo Register to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_MOD_ADDR32(u8ModuleIdx), 0U);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_MSA_MASK_U32);

    /* disable freeze */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, 0x0U);

    Gpt_Ftm_u32TargetValue[u8ModuleIdx][u8ChannelIdx] = 0U;
    return;
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the Ftm timer channel.
* @details This function:
*          - sets the channel value register to the calculated timeout value.
*          - enables the timer compare interrupts corresponding to Ftm channel
*
* @param[in]     u8HwChannel       Ftm hw channel ID
* @param[in]     u32Value          channel timeout value
*
*
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Ftm_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel,
                                            VAR(uint32, AUTOMATIC) u32Value)
{
    VAR(uint32, AUTOMATIC) u32CounterValue;
    VAR(uint32, AUTOMATIC) u32CompareValue;
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned Ftm HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

     /* To update accurate value for FTM_CV_ADDR32, interrupts is suspended*/
    SuspendAllInterrupts();
    
    /* Configure channel compare register */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32CounterValue = REG_READ32(FTM_CNT_ADDR32(u8ModuleIdx));

    if ((uint32)(u32CounterValue + u32Value) > FTM_CNT_MAX_VALUE_U32)
    {
        u32CompareValue = (uint32)(u32Value - (FTM_CNT_MAX_VALUE_U32 - u32CounterValue));
    }
    else
    {
        u32CompareValue = (uint32)(u32CounterValue + u32Value);
    }
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx),  (uint32)u32CompareValue);

    ResumeAllInterrupts();
    
    Gpt_Ftm_u32TargetValue[u8ModuleIdx][u8ChannelIdx] = u32Value;

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_18();
    /* clear interrupt flag */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    /* enable interrupt */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_18();
    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Ftm timer channel.
* @details This function:
*          - disables the timer compare interrupts corresponding to Ftm channel
*          - clears the timer compare interrupt flags corresponding to Ftm channel
*
* @param[in]     u8HwChannel        Ftm hw channel ID
*
*
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Ftm_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned Ftm HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_19();
    /* disable interrupt */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

    /* clear interrupt flag */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_19();
    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for getting the time elapsed for an Ftm timer channel.
* @details This function is called for reading the Ftm channel counter register.
*
* @param[in]     u8HwChannel                 Ftm hw channel ID
* @param[out]    pbReturnChannelOverflow     interrupt status flag value of the timer channel
* @param[out]    pu32TargetValue             current target time value
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(uint32, GPT_CODE) Gpt_Ftm_GetTimeElapsed(VAR(uint8, AUTOMATIC) u8HwChannel,
                                                 P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelOverflow,
                                                 P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue)
{
    VAR(uint32, AUTOMATIC)  u32ReturnValue = 0U;
    VAR(uint32, AUTOMATIC) u32CompareValue;
    VAR(uint32, AUTOMATIC) u32CounterValue;

    VAR(uint8, AUTOMATIC)   u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC)   u8ChannelIdx;  /* assigned Ftm HW channel index */

    VAR(uint32,AUTOMATIC) u32Temp1;

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    /* Read compare and counter registers */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    u32CompareValue = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32CounterValue = REG_READ32(FTM_CNT_ADDR32(u8ModuleIdx));

    *pu32TargetValue = Gpt_Ftm_u32TargetValue[u8ModuleIdx][u8ChannelIdx];

    /* Calculate the elapsed time */
    if (u32CounterValue >= u32CompareValue)
    {
        u32ReturnValue = (*pu32TargetValue - ((FTM_CNT_MAX_VALUE_U32 - u32CounterValue) + u32CompareValue)) +
                        FTM_OVERFLOW_PAD_U32;
    }
    else
    {
        u32ReturnValue = *pu32TargetValue - (u32CompareValue - u32CounterValue);
    }

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    u32Temp1 = REG_BIT_GET32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    /*Check interrupt status flag*/
    if (FTM_CSC_CHF_EVENT_OCCURED_U32 == u32Temp1)
    {
        /* Channel counter was rollover */
        *pbReturnChannelOverflow = (boolean)TRUE;
    }
    else
    {
        /* Channel counter was not rollover */
        *pbReturnChannelOverflow = (boolean)FALSE;
    }
    return u32ReturnValue;
}

/*================================================================================================*/
#if (GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON)
/**
* @brief      The function changes the Ftm compare register value.
* @details This function:
*          - Write next timeout to local variable
*
* @param[in]     u8HwChannel        Ftm hw channel ID
* @param[in]     u32Value           Channel timeout value
* @implements    Gpt_Ftm_ChangeNextTimeoutValue_Activity
*/

FUNC(void, GPT_CODE) Gpt_Ftm_ChangeNextTimeoutValue(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned FTM HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned FTM HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    /* Update the target time value to be used on next cycle */
    Gpt_Ftm_u32NextTargetValue[u8ModuleIdx][u8ChannelIdx] = u32Value;
}
#endif /* GPT_CHANGE_NEXT_TIMEOUT_VALUE == STD_ON */

/*================================================================================================*/
#if (GPT_SET_CLOCK_MODE == STD_ON)
/**
* @brief      The function changes the FTM prescaler value.
* @details    This function sets the FTM prescaler based on the input mode.
*
* @param[in]  u8HwChannel      hardware channel
* @param[in]  u8ChPrescaler     prescaler value
*
* @pre     On/Off by the configuration parameter: PWM_SET_CLOCK_MODE_API
*
* @violates @ref GPT_FTM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Ftm_SetClockMode(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint8, AUTOMATIC) u8ChPrescaler)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx = FTM_MODULE_INDEX_U8(u8HwChannel);   /* get Ftm HW module index depending on Hw Channel id*/

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_20();
    /* set the prescaler with the wanted value */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_PS_MASK_U32,(uint32)u8ChPrescaler);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_20();
}
#endif /*PWM_SET_CLOCK_MODE_API */

#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief      The function start the FTM channel in Free-Running Mode.
* @details    This function start the FTM channel...
*             - Disable the FTM channel (by unslelecting clock source)
*             - Clears all interrupt flag and disable all interrupts for the channel
*             - Configures FTM channel as a Free-Running Timer by one of two cases:
*                               +) FTMEN=0 and (MOD=0x0000 or MOD=0xFFFF)
*                               +) FTMEN=1, MOD=0xFFFF, CNTIN=0, QUADEN=0, CPWMS=0
*             - Configures FTM prescaler, selects clock source, enables/disables freeze bit
*             - Enable the FTM channel (by enabling clock source)
*             - Initialize FTM counter by writing to CTN register any value, then FTM reloads the CNTIN value and starts counting
*
* @param[in]  u8hwChannel      hardware channel
* @param[in]  bFreezeEnable    Freeze value
* @param[in]  u8ClockSource    Select clock source
* @param[in]  u8Prescaler      prescaler value
*
*/
FUNC(void, GPT_CODE) Gpt_Ftm_StartPredefTimer
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(boolean, AUTOMATIC) bFreezeEnable,
    VAR(uint8, AUTOMATIC) u8ClockSource,
    VAR(uint8, AUTOMATIC) u8Prescaler
)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned Ftm HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_21();
    /* disable the FTM timer */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_CLKS_MASK_U32, FTM_SC_CLKS_NO_CLOCKS_U32);

    /* disable all interrupts on this channel */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

    /* clear interrupt flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    /* Clear Fault interrupt flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_FMS_ADDR32(u8ModuleIdx), (FTM_FMS_FAULTF_MASK_U32 | FTM_FMS_FAULTF3_MASK_U32 | FTM_FMS_FAULTF2_MASK_U32 | FTM_FMS_FAULTF1_MASK_U32 | FTM_FMS_FAULTF0_MASK_U32));

    /* Disable TOIE flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_TOIE_MASK_U32);

    /* Disable FAULTM flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(FTM_MODE_ADDR32(u8ModuleIdx), FTM_MODE_FAULTM_MASK_U32);

    /* Configute FTM as a Free-Running Timer by setting FTMEN=1, CTNIN=0, MOD=0xFFFF, QUADEN=0, CPWMS=0*/
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(FTM_MODE_ADDR32(u8ModuleIdx), FTM_MODE_FTMEN_MASK_U32);

    /* Initial Counter Value to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNTIN_ADDR32(u8ModuleIdx), 0U);

    /* write the Ftm Modulo Register with 0xFFFF */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_MOD_ADDR32(u8ModuleIdx), 0xFFFFU);

    /* Set Compare Value register to 0xFFFF */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx), 0xFFFFU);

    /* Clear bit QUADEN */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_QDCTRL_ADDR32(u8ModuleIdx), FTM_QDCTRL_QUADEN_MASK_U32);

    /* Clear bit CPWMS */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_CPWMS_MASK_U32);

    if ((boolean)TRUE == bFreezeEnable)
    {
        /* enable freeze */
        /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, ((uint32)0x0U << FTM_CONF_BDMMODE_SHIFT));
    }
    else
    {
        /* disable freeze */
        /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, ((uint32)0x3U << FTM_CONF_BDMMODE_SHIFT));
    }

    /* set the prescaler with the wanted value */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_PS_MASK_U32,(uint32)u8Prescaler);

    /* set timer clock */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx) , FTM_SC_CLKS_MASK_U32, ((uint32)u8ClockSource<<FTM_SC_CLKS_SHIFT));

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_21();
    /* Intialize FTM timer by writing any value to CNT register when CLKS not equal 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNT_ADDR32(u8ModuleIdx), 1U);
}

/*================================================================================================*/
/**
* @brief      The function get time elapsed of the FTM predefined timer channel.
* @details    The function get time elapsed of the FTM predefined timer channel.
*
* @param[in]  u8hwChannel       hardware channel
* @param[in]  ePredefTimerType  Types of predef timer
*
*/
FUNC(uint32, GPT_CODE) Gpt_Ftm_GetPredefTimerValue (VAR(uint8, AUTOMATIC) u8HwChannel, VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType)
{
    VAR(uint32, AUTOMATIC)  u32ReturnValue;
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u32ReturnValue = 0U;

    switch(ePredefTimerType)
    {
        case GPT_PREDEF_TIMER_1US_16BIT:
            /* Read counter registers */
            /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            u32ReturnValue = REG_READ32(FTM_CNT_ADDR32(u8ModuleIdx));
            break;
        case GPT_PREDEF_TIMER_1US_24BIT:
        case GPT_PREDEF_TIMER_1US_32BIT:
        case GPT_PREDEF_TIMER_100US_32BIT:
            break;
        default:
            /* 32bit timer */
            break;
    }

    return  u32ReturnValue;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the FTM timer channel.
* @details This function:
*          - stop the FTM timer by unselecting clock source
*          --> This will stop the shared counter and stop other channels in the same FTM module
*
* @param[in]     u8HwChannel        FTM hw channel ID
*
*/
FUNC(void, GPT_CODE) Gpt_Ftm_StopPredefTimer (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /* assigned Ftm HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /* assigned Ftm HW channel index */

    u8ModuleIdx  = FTM_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = FTM_CHANNEL_INDEX_U8(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_22();
    /* disable timer channel */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_CLKS_MASK_U32,FTM_SC_CLKS_NO_CLOCKS_U32);

    /* disable interrupts */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

    /* clear interrupt flags */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_MODE_ADDR32(u8ModuleIdx), FTM_MODE_FTMEN_MASK_U32);

    /*  Set Counter register to 0 and Initial Counter Value to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNTIN_ADDR32(u8ModuleIdx), 0U);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_CNT_ADDR32(u8ModuleIdx), 0U);

    /* Set Compare Value register to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx), 0U);

    /*  write the Ftm Modulo Register to 0 */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(FTM_MOD_ADDR32(u8ModuleIdx), 0U);

    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref GPT_FTM_C_REF_6 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_MSA_MASK_U32);

    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_22();
    /* disable freeze */
    /** @violates @ref GPT_FTM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_FTM_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, 0x0U);
}
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_FTM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_FTM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
