/**
*   @file    Ocu_Ftm.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Ocu - FTM driver source file for OCU driver.
*   @details FTM driver interface.
*
*   @addtogroup OCU_MODULE
*   @{
*/
/*================================================================================================================
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
==================================================================================================================*/
/*================================================================================================================
==================================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Ocu_Ftm_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before 'include'
* MemMap.h included after each section define in order to set the current memory section
*
* @section Ocu_Ftm_C_REF_2
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer
* This rule can not be avoided because it appears when addressing memory mapped registers or other hardware specific feature
*
* @section Ocu_Ftm_C_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* 
* @section Ocu_Ftm_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Ocu_Ftm_C_REF_5
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted.
* This is not a violation since the same function is called from different places with different parameter values.*
*
* @section Ocu_Ftm_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Ocu_Ftm_C_REF_7
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type may only be cast to type that is narrower and of the same
* signedness as the underlying type of the expression.
* This is not a violation since the expression is used to access a 32bit register using a 8 bit channel value.
*
* @section Ocu_Ftm_C_REF_8
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Ocu_Ftm_C_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, cast from unsigned int to pointer
* This rule can not be avoided because it appears when addressing memory mapped registers or other hardware specific feature
*
* @section Ocu_Ftm_C_REF_10
* Violates MISRA 2004 Advisory Rule 11.4, cast from pointer to pointer
* To typecast the pointer from one data type to other data type
*
* @section Ocu_Ftm_C_REF_11
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*/
/*================================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================================*/
#include "Std_Types.h"
#include "Ocu_Ftm.h"
#include "Ocu_Ipw_Irq.h"
#include "Ocu_Ftm_Irq.h"
#include "SchM_Ocu.h"
#include "Reg_eSys_Ftm.h"
#include "Ftm_Common_Types.h"
#ifndef USER_MODE_REG_PROT_ENABLED
    #define  USER_MODE_REG_PROT_ENABLED  (STD_OFF)
#endif
#include "SilRegMacros.h"

/*================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================================*/


#define OCU_FTM_VENDOR_ID_C                    43
/** @violates @ref Ocu_Ftm_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
/** @violates @ref Ocu_Ftm_C_REF_6 MISRA 2004 Rule 5.1, Identifiers ... more than 31 characters.*/
#define OCU_FTM_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Ocu_Ftm_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
/** @violates @ref Ocu_Ftm_C_REF_6 MISRA 2004 Rule 5.1, Identifiers ... more than 31 characters.*/
#define OCU_FTM_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref Ocu_Ftm_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
/** @violates @ref Ocu_Ftm_C_REF_6 MISRA 2004 Rule 5.1, Identifiers ... more than 31 characters.*/
#define OCU_FTM_AR_RELEASE_REVISION_VERSION_C  2
#define OCU_FTM_SW_MAJOR_VERSION_C             1
#define OCU_FTM_SW_MINOR_VERSION_C             0
#define OCU_FTM_SW_PATCH_VERSION_C             1
/** @} */

/*================================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if this source file and Std_Types.h file are of the same Autosar version */
 #if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (OCU_FTM_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
     )
     #error "AutoSar Version Numbers of Ocu_Ftm.c and Std_Types.h are different"
 #endif
 
 #if (OCU_FTM_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
 #error "Ocu_Ftm.c and Reg_eSys_Ftm.h have different vendor ids"
 #endif
/* Check if the source file and Ocu header file are of the same Autosar version */
 
 #if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION) \
     )
 #error "AutoSar Version Numbers of Ocu_Ftm.c and Reg_eSys_Ftm.h are different"
 #endif
/* Check if source file and OCU header file are of the same Software version */
 
 #if ((OCU_FTM_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (OCU_FTM_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (OCU_FTM_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION) \
     )
 #error "Software Version Numbers of Ocu_Ftm.c and Reg_eSys_Ftm.h are different"
 #endif
 
 #if (OCU_FTM_VENDOR_ID_C != FTM_COMMON_TYPES_VENDOR_ID) 
 #error "Ocu_Ftm.c and Ftm_Common_Types.h have different vendor ids"
 #endif
/* Check if the source file and Ocu header file are of the same Autosar version */
 
 #if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_MINOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_REVISION_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION) \
     )
 #error "AutoSar Version Numbers of Ocu_Ftm.c and Ftm_Common_Types.h are different"
 #endif
/* Check if source file and OCU header file are of the same Software version */
 
 #if ((OCU_FTM_SW_MAJOR_VERSION_C != FTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (OCU_FTM_SW_MINOR_VERSION_C != FTM_COMMON_TYPES_SW_MINOR_VERSION) || \
     (OCU_FTM_SW_PATCH_VERSION_C != FTM_COMMON_TYPES_SW_PATCH_VERSION) \
     )
 #error "Software Version Numbers of Ocu_Ftm.c and Ftm_Common_Types.h are different"
 #endif
 
 /* Check if source file and SilRegMacros.h are of the same vendor */
#if (OCU_FTM_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Ocu_Ftm.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ftm.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((OCU_FTM_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (OCU_FTM_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (OCU_FTM_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ftm.c and SilRegMacros.h are different"
#endif
#endif
#if (OCU_FTM_VENDOR_ID_C != OCU_FTM_VENDOR_ID)
 #error "Ocu_Ftm.c and Ocu_Ftm.h have different vendor ids"
#endif
/* Check if source file and Ocu header file are of the same Autosar version */
#if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION_C != OCU_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_MINOR_VERSION_C != OCU_FTM_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_REVISION_VERSION_C != OCU_FTM_AR_RELEASE_REVISION_VERSION) \
    )
 #error "AutoSar Version Numbers of Ocu_Ftm.c and Ocu_Ftm.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_FTM_SW_MAJOR_VERSION_C != OCU_FTM_SW_MAJOR_VERSION) || \
     (OCU_FTM_SW_MINOR_VERSION_C != OCU_FTM_SW_MINOR_VERSION) || \
     (OCU_FTM_SW_PATCH_VERSION_C != OCU_FTM_SW_PATCH_VERSION) \
    )
 #error "Software Version Numbers of Ocu_Ftm.c and Ocu_Ftm.h are different"
#endif

#if (OCU_FTM_VENDOR_ID_C != OCU_IPW_IRQ_VENDOR_ID)
    #error "Ocu_Ftm.c and Ocu_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Ocu header file are of the same Autosar version */
#if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION_C != OCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_MINOR_VERSION_C != OCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_REVISION_VERSION_C != OCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
 #error "AutoSar Version Numbers of Ocu_Ftm.c and Ocu_Ipw_Irq.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_FTM_SW_MAJOR_VERSION_C != OCU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (OCU_FTM_SW_MINOR_VERSION_C != OCU_IPW_IRQ_SW_MINOR_VERSION) || \
     (OCU_FTM_SW_PATCH_VERSION_C != OCU_IPW_IRQ_SW_PATCH_VERSION) \
    )
 #error "Software Version Numbers of Ocu_Ftm.c and Ocu_Ipw_Irq.h are different"
#endif

#if (OCU_FTM_VENDOR_ID_C != OCU_FTM_IRQ_VENDOR_ID)
    #error "Ocu_Ftm.c and Ocu_Ftm_Irq.h have different vendor ids"
#endif
/* Check if source file and Ocu header file are of the same Autosar version */
#if ((OCU_FTM_AR_RELEASE_MAJOR_VERSION_C != OCU_FTM_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_MINOR_VERSION_C != OCU_FTM_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (OCU_FTM_AR_RELEASE_REVISION_VERSION_C != OCU_FTM_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
 #error "AutoSar Version Numbers of Ocu_Ftm.c and Ocu_Ftm_Irq.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_FTM_SW_MAJOR_VERSION_C != OCU_FTM_IRQ_SW_MAJOR_VERSION) || \
     (OCU_FTM_SW_MINOR_VERSION_C != OCU_FTM_IRQ_SW_MINOR_VERSION) || \
     (OCU_FTM_SW_PATCH_VERSION_C != OCU_FTM_IRQ_SW_PATCH_VERSION) \
    )
 #error "Software Version Numbers of Ocu_Ftm.c and Ocu_Ftm_Irq.h are different"
#endif
/*================================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================================*/

/*================================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* @brief Offet for CHnOCV bits*/
/** @violates @ref Ocu_Ftm_C_REF_4 Identifier exceeds 31 chars.  */
#define OCU_FTM_SWOCTRL_FORCED_VALUE_OFFSET  ((uint8)8U)

/*================================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================================*/
#define OCU_START_SEC_VAR_NO_INIT_8

/*
* @violates @ref Ocu_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Ocu_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

/**
* @brief    This arrays shall be used to store the action information for each Ftm channel
* @details  This array shall be initialized by Ocu_Ftm_Init() and Ocu_Ftm_SetPinAction.
*           This data shall be used by Ocu_Ftm_StartChannel to replace the information erased when
*           Ocu_Ftm_StopChannel was called.
*/
static  VAR(uint8, OCU_VAR) Ocu_Ftm_au8OcuAction[OCU_FTM_HW_CHANNEL_MAX];

#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
* @brief    This arrays shall be used to store the max counter value for each Ftm channel
* @details  This array shall be initialized by Ocu_Ftm_Init().
*           This data shall be used by Ocu_Ftm_GetMaxCountValue and Ocu_Ftm_SetRelativeThreshold
*/
static  VAR(uint16, OCU_VAR) Ocu_Ftm_au16MaxCounterValue[OCU_FTM_HW_CHANNEL_MAX];
#endif

#define OCU_STOP_SEC_VAR_NO_INIT_8
/*
* @violates @ref Ocu_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Ocu_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"
/*================================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================================*/


/*================================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================================*/


/*================================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================================*/
#define OCU_START_SEC_CODE
/*
* @violates @ref Ocu_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Ocu_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

#if ((OCU_SET_ABSOLUTE_THRESHOLD_API  == STD_ON) || \
     (OCU_SET_RELATIVE_THRESHOLD_API  == STD_ON))
static FUNC(Ocu_ReturnType, OCU_CODE) Ocu_Ftm_DetermineNextCmStatus
(
   VAR(Ocu_ValueType,   AUTOMATIC) PostCmWriteValue,
   VAR(Ocu_ValueType,   AUTOMATIC) StartIntervalValue,
   VAR(Ocu_ValueType,   AUTOMATIC) EndIntervalValue
);
#endif


/*================================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================================*/
#if ((OCU_SET_ABSOLUTE_THRESHOLD_API  == STD_ON) || \
     (OCU_SET_RELATIVE_THRESHOLD_API  == STD_ON))

/**
* @brief          This internal function determines status of the compare match after the new threshold
*                 was written.  
* @details        This function compare systematic the input parameter values to determine if the 
*                 compare-match will occur in the given interval or has already occurred. 
*                 The reference interval if composed of all integer value between the StartIntervalValue and 
*                 EndIntervalValue, considering also the possibility of counter over-run.
*                 I.e. considering a 8bit counter if StartIntervalValue = 253 and  EndIntervalValue = 5 than 
*                 the values inside the interval are {253, 254, 255, 0, 1, 2, 3, 4} and all other values are 
*                 outside reference interval.
*
* @param[in]      PostCmWriteValue        Value of the counter after Compare match was written
* @param[in]      StartIntervalValue      Start value of the reference interval
* @param[in]      EndIntervalValue        End value of the reference interval
* @param[in]      eCountDir               Direction of counter
*
* @return         Ocu_ValueType           Compare match was written in or outside the given interval
* @retval         OCU_CM_IN_REF_INTERVAL  Compare match was written inside the reference interval
* @retval         OCU_CM_IN_REF_INTERVAL  Compare match was written outside the reference interval
*
*
* @note           .
*/
static FUNC(Ocu_ReturnType, OCU_CODE) Ocu_Ftm_DetermineNextCmStatus
(
   VAR(Ocu_ValueType,   AUTOMATIC) PostCmWriteValue,
   VAR(Ocu_ValueType,   AUTOMATIC) StartIntervalValue,
   VAR(Ocu_ValueType,   AUTOMATIC) EndIntervalValue
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Ocu_ReturnType, AUTOMATIC)  StatusValue = OCU_CM_OUT_REF_INTERVAL;
        /*check if compare match will happen before counter roll-over*/
    if (StartIntervalValue <= EndIntervalValue)
    {
        /*counter is not expected to roll-over*/
        /*check if post-update value is inside the compare match interval*/
        if((StartIntervalValue <= PostCmWriteValue) && (PostCmWriteValue <= EndIntervalValue))
        {
            StatusValue = OCU_CM_IN_REF_INTERVAL;
        }
        else
        {
            StatusValue = OCU_CM_OUT_REF_INTERVAL;
        }
    }
    else
    {/*counter has rolled-over*/
        
        /*check if post-update value is outside the compare match interval*/
        if((PostCmWriteValue < StartIntervalValue) && (PostCmWriteValue > EndIntervalValue))
        {
            StatusValue = OCU_CM_OUT_REF_INTERVAL;
        }
        else
        {
            StatusValue = OCU_CM_IN_REF_INTERVAL;
        }        
    }

    return StatusValue;      
}
#endif
/*================================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================================*/
/*=================================================================================================================*/


/*=================================================================================================================*/
/**
* @brief            This function initializes all internals variables of the driver.
* @details          This function will initialize with default values all Ftm registers.
*                   Will loop through all Ftm modules and channels in the configuration structure and will
*                   setup required registers for each channel and module
*
* @param[in] pFtmIpConfig - Pointer to configuration structure of Ftm channels
*
*/
FUNC (void, OCU_CODE) Ocu_Ftm_Init
(   
    CONSTP2CONST(Ocu_Ftm_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pFtmIpConfig
)
{
    VAR(Ocu_Ftm_ModuleType,          AUTOMATIC) u8ModuleId; /* Id of Ftm Module this channel belongs to */
    VAR(Ocu_Ftm_ModuleType,          AUTOMATIC) u8HwModuleId;   /* Id of Ftm Module this channel belongs to */
    VAR(Ocu_Ftm_ModuleType,          AUTOMATIC) u8NumModules;   /*total number of used modules*/
    VAR(Ocu_Ftm_ChannelType,          AUTOMATIC) u8NumChannels; /*total number of used channels*/
    VAR(Ocu_Ftm_ChannelType,          AUTOMATIC) u8CurChannel;  /*index value of the current channel*/
    VAR(Ocu_Ftm_ChannelType,          AUTOMATIC) u8HwChannel;   /*index value of the current Hw channel*/
    VAR(Ocu_Ftm_ModuleType,          AUTOMATIC) u8InternalModuleId; /* Id of Ftm Module this channel belongs to */
    VAR(Ocu_Ftm_ChannelControlType,  AUTOMATIC)    u8ChannelControlValue;   /* Store controled values from channel configured data */
    VAR(uint16  ,                       AUTOMATIC)  u16MaxCounterValue; /* Store max counter value from module configured data */
    VAR(uint32 ,    AUTOMATIC)          u8ModuleControlValue = 0U;  /* Store controled values from channel configured data */
    VAR(uint32 ,    AUTOMATIC)          u32RegSwoctrl = 0U; /* Temporary value of SWOCTRL register */
    VAR(uint32 ,    AUTOMATIC)          u32RegSc = 0U;      /* Temporary value of SWOCTRL register */
    VAR(Ocu_PinActionType, AUTOMATIC)   ePinAction; /* Store pin action from configured data */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;   
    /* Pointer to Ftm Module configuration */    
    P2CONST(Ocu_Ftm_ModuleConfigType,    AUTOMATIC, OCU_APPL_CONST) pFtmModuleConfig = NULL_PTR;    
    
    /*Get number of modules used for the current Ftm module*/
    u8NumModules = pFtmIpConfig->u8NumModules;
    /*Get number of channels used for the current Ftm module*/
    u8NumChannels = pFtmIpConfig->u8NumChannels;

    /*initialize Array used to store pin action */
    for(u8CurChannel = (uint8)0; u8CurChannel < u8NumChannels; u8CurChannel++)
    {       
        Ocu_Ftm_au8OcuAction[u8CurChannel] = 0U;
    }    
    /*initialize registry for all used modules*/
    for (u8ModuleId = ((uint8)0U);  u8ModuleId < u8NumModules;  u8ModuleId++)
    {
        /*Get pointer to configuration data of the Ftm module*/
        pFtmModuleConfig = &(*pFtmIpConfig->pModulesConfig)[u8ModuleId];
        /*get FTM Hw module Index*/
        u8HwModuleId = pFtmModuleConfig->u8ModuleId;
        /* Get some module parameters in configured data */
        u8ModuleControlValue = pFtmModuleConfig->u8ModuleControlValue;
        u16MaxCounterValue = pFtmModuleConfig->u16MaxCounterValue;
        /*clear WPDIS bit if set so that registers can pe written*/
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        if ((uint32)0 != REG_BIT_GET32(FTM_FMS_ADDR32(u8HwModuleId), FTM_FMS_WPEN_MASK_U32))
        {
            /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_WPDIS_MASK_U32);
        }
        else
        {
            /*do nothing*/
        }
        
        /* Init Status Controll register for each module */
        u32RegSc = 0UL;

        /* Init Status Controll register for each module */
        u32RegSc = 0UL;
        
        /* Disable clock */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_RMW32(FTM_SC_ADDR32(u8HwModuleId),FTM_SC_CLKS_MASK_U32,FTM_SC_CLKS_NO_CLOCKS_U32);
        /* Setting counter to count up, disable timer overflow */
        u32RegSc |= (uint32)(FTM_SC_CPWMS_UP_COUNTING_U32|FTM_SC_TOIE_DISABLE_U32);
        /* Process clock source and prescale from configured data */
        u32RegSc |= (uint32)((uint32)((u8ModuleControlValue & OCU_FTM_CLOCK_SOURCE_MASK_U8)>>OCU_FTM_CLOCK_SOURCE_SHIFT) << FTM_SC_CLKS_SHIFT);
        u32RegSc |= (uint32)((u8ModuleControlValue & OCU_FTM_CLOCK_DIV_MASK_U8)>>OCU_FTM_CLOCK_DIV_SHIFT);  
        
        /* Reset u32RegSwoctrl*/
        u32RegSwoctrl=0U;
        /* Configure MODE, FTMEN=0 means no buffer mechanism is used*/
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_MODE_ADDR32(u8HwModuleId), 0U);
        /* Configure CONF with debug mode. GTBEOUT,GTBEEN,NUMTOF are zero*/
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        REG_WRITE32(FTM_CONF_ADDR32(u8HwModuleId),((uint32)((pFtmModuleConfig->u8ModuleControlValue) >> OCU_FTM_DBG_INFO_SHIFT) << FTM_CONF_BDMMODE_SHIFT));
        /* Configure SYNCONF with no buffer mechanism enable  */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SYNCONF_ADDR32(u8HwModuleId), ((uint32)0U));
        /* Reset FTMn_CNTIN register*/
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_CNTIN_ADDR32(u8HwModuleId), ((uint32)0U));                       
        /* Write FTMn_MOD register*/
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_MOD_ADDR32(u8HwModuleId), u16MaxCounterValue);
  
        /* Loop all Ftm channels and perform Init actions for channels beloging to a given module*/
        for (u8CurChannel = ((uint8)0U); u8CurChannel < u8NumChannels; u8CurChannel++)
        {
            /* Get pointer to configuration of Ftm channel */
            pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8CurChannel];
            /*get current hw module Id*/
            u8InternalModuleId = ((Ocu_Ftm_ModuleType)(((pFtmChannelConfig->u8EncodedHwChannel) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
            /*get current hw channel Id*/
             u8HwChannel = ((pFtmChannelConfig->u8EncodedHwChannel) & FTM_CH_MASK_U8);
             /* Get channel level control value from configuration data */
             u8ChannelControlValue = pFtmChannelConfig->u8ChannelControlValue;
            /*check if the current hw channel belongs to the current hardware FTM module */
            if (u8InternalModuleId == u8HwModuleId)
            {
                /*
                * write FTMn_CSC register, this should be done before writing CV, in order to be in OCU mode
                * MSB:MSA = 0:1 - output compare mode
                * ELSB:ELSA = 0:0 - disable output action
                * clear Channel Flag CHF and disable Channel Interrupt CHIE
                * Disable DMA
                */
#if(defined IPV_FTM)
#if (IPV_FTM == IPV_FTM_05_00_04_00)
                /* Enable output on the FTM channel */
                u32RegSc |= (uint32)(((uint32)1U)<<(u8HwChannel + OCU_FTM_SC_PWMEN_SHIFT_U8));
#endif
#endif
                /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                REG_WRITE32(FTM_CSC_ADDR32(u8HwModuleId, u8HwChannel), FTM_CSC_MSA_MASK_U32);
                /* write default threshold to CnV */
                /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                REG_WRITE32(FTM_CV_ADDR32(u8HwModuleId, u8HwChannel), ((uint32)pFtmChannelConfig->u16DefaultThreshold));
                /*Configure default PIN Action behaviour*/
                ePinAction =  (Ocu_PinActionType)((u8ChannelControlValue & OCU_FTM_PIN_ACTION_MASK_U8) >> OCU_FTM_PIN_ACTION_SHIFT);                
                switch(ePinAction)
                {
                    case OCU_SET_LOW:
                    {
                        Ocu_Ftm_au8OcuAction[u8CurChannel] = (uint8)OCU_SET_LOW;
                    }
                    break;                    
                    case OCU_SET_HIGH:
                    {
                        Ocu_Ftm_au8OcuAction[u8CurChannel] = (uint8)OCU_SET_HIGH;
                    }
                    break; 
                    case OCU_TOGGLE:
                    {
                        Ocu_Ftm_au8OcuAction[u8CurChannel] = (uint8)OCU_TOGGLE;
                    }
                    break;
                    default:
                    {
                        Ocu_Ftm_au8OcuAction[u8CurChannel] = (uint8)OCU_DISABLE;
                    }
                    break;    
                }
#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
                /* Store the max counter value */
                Ocu_Ftm_au16MaxCounterValue[u8CurChannel] = u16MaxCounterValue;
#endif
                /* If pin is used, it should be enter software control mode */
                if (1U == (uint8)((u8ChannelControlValue & OCU_FTM_OUTPIN_USED_MASK_U8) >> OCU_FTM_OUTPIN_USED_SHIFT))
                {
                    /* Setting forced value for current channel*/
                    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                    u32RegSwoctrl |= (uint32)((uint32)((u8ChannelControlValue & OCU_FTM_PIN_STATE_MASK_U8) >> OCU_FTM_PIN_STATE_SHIFT) << 
                                            (u8HwChannel + OCU_FTM_SWOCTRL_FORCED_VALUE_OFFSET));
                    /* Enable software output control */
                    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                    u32RegSwoctrl |= (uint32)(((uint32)1U) << u8HwChannel);                
                }
                /* 
                 * Write FTMn_COMBINE register for current pair-channel, MCOMBINE,FAULTEN,SYNCEN,DTEN,DECAP,DECAPEN,COMP,COMBINE are zero
                 * Eg. current channel is 5, then pair-channel is 3th, bit field need to be clear: 0x00ff0000
                 */
                /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                REG_RMW32(FTM_COMBINE_ADDR32(u8HwModuleId), (uint32)(((uint32)0xff)<<(((uint8)u8HwChannel)>>1U)),0U);       
            }
        }
        /* FTMEN=1 active buffer mechanism */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_FTMEN_ENABLE_U32);
        /* Write SWOCTRL with calculated value*/
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SWOCTRL_ADDR32(u8HwModuleId), u32RegSwoctrl);
        /* Write SC, btw enable clock */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SC_ADDR32(u8HwModuleId), u32RegSc);
    }
}


/*=================================================================================================================*/
#if (OCU_DEINIT_API == STD_ON)
/**
* @brief            This function deinitializes the driver.
* @details          This function will set to idle state all Ftm channels. Will stop all
*                   Ftm modules.
*                   Disables all Ftm channels interrupts.
*
* @param[in]        pFtmIpConfig  Pointer to Ftm channels configuration structure
*
*
*/
FUNC (void, OCU_CODE) Ocu_Ftm_DeInit
(   
    CONSTP2CONST(Ocu_Ftm_IpConfigType, AUTOMATIC, OCU_APPL_CONST) pFtmIpConfig
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR; 
    /* Pointer to Ftm Module configuration */
    P2CONST(Ocu_Ftm_ModuleConfigType,    AUTOMATIC, OCU_APPL_CONST) pFtmModuleConfig = NULL_PTR;    
    VAR(Ocu_Ftm_ModuleType,   AUTOMATIC) u8ModuleId;    /* Id of Ftm Module this channel belongs to */
    VAR(Ocu_Ftm_ModuleType,   AUTOMATIC) u8HwModuleId;  /* Id of Ftm Module this channel belongs to */
    VAR(Ocu_Ftm_ChannelType,  AUTOMATIC) u8CurChannel;  /*index value of the current channel*/
    VAR(Ocu_Ftm_ChannelType, AUTOMATIC) u8HwChannel;    /*index value of the current Hw channel*/
    
    /* Loop all Ftm channels and perform deInit actions */
    for (u8CurChannel = 0U; u8CurChannel < pFtmIpConfig->u8NumChannels; u8CurChannel++)
    {
        /* Reset Ocu_Ftm_au8OcuAction */
        Ocu_Ftm_au8OcuAction[u8CurChannel]=0U;
#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
        /* Reset Ocu_Ftm_au16MaxCounterValue */
        Ocu_Ftm_au16MaxCounterValue[u8CurChannel]=0U;
#endif
        /* Get pointer to configuration of Ftm channel */
        pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8CurChannel];    
        /*get current hw channel Id*/
        u8HwChannel = ((pFtmChannelConfig->u8EncodedHwChannel) & FTM_CH_MASK_U8);    
        /*get current hw module Id*/
        u8ModuleId = (((pFtmChannelConfig->u8EncodedHwChannel) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);
        /* Reset CSC and CV */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CSC_ADDR32(u8ModuleId,u8HwChannel), 0U);
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CV_ADDR32(u8ModuleId,u8HwChannel), 0U);
        /* Reset CHOCV and CH0OC for given channel */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        REG_BIT_CLEAR32(FTM_SWOCTRL_ADDR32(u8ModuleId),(uint32)(((uint32)1U)<<(u8HwChannel+OCU_FTM_SWOCTRL_FORCED_VALUE_OFFSET)));
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        REG_BIT_CLEAR32(FTM_SWOCTRL_ADDR32(u8ModuleId),(uint32)(((uint32)1U)<<u8HwChannel));   
    }
    /*de-initialize registers for all used modules*/
    for (u8ModuleId =  ((uint8)0U);  u8ModuleId < (pFtmIpConfig->u8NumModules);  u8ModuleId++)
    {
        /*Get pointer to configuration data of the Ftm module*/
        pFtmModuleConfig = &(*pFtmIpConfig->pModulesConfig)[u8ModuleId];
        /*get FTM Hw module Index*/
        u8HwModuleId = pFtmModuleConfig->u8ModuleId;
        /** Reset MOD */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_MOD_ADDR32(u8HwModuleId), 0U);
        /* Reset FTMEN bit */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_FTMEN_ENABLE_U32);
        /* Clear BDMMODE bits */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_CONF_ADDR32(u8HwModuleId), FTM_CONF_BDMMODE_MASK_U32);
        /*write FTMn_SC register to disable clock */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SC_ADDR32(u8HwModuleId), 0U);
    }
}
#endif /* OCU_DE_INIT_API */

/*=================================================================================================================*/
/**
* @brief   Ocu driver function for starting the FTM timer channel.
* @details This function:
*           Configure ELSB:ELSA
*           Release software control
*           Clear flag and enable interrupt
*
* @param[in]     u8ChannelIndex        Index for Ftm channels config array
*                pFtmIpConfig          Pointer to Ftm IP configuration structure
*/
FUNC(void, OCU_CODE) Ocu_Ftm_StartChannel
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint32, AUTOMATIC) u32RegCsc;   /* Temporary for SC register*/
    VAR(uint8, AUTOMATIC) u8ModuleId;   /* assigned FTM HW module */
    VAR(uint8, AUTOMATIC) u8ChannelId;  /* assigned FTM HW channel*/
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;   /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    /* Get Ftm Module and Channel ID */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    u8ChannelId = (u8EncodedHwChannel & FTM_CH_MASK_U8);
    
    /*enter critical section TODO check*/
    SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_00();
    /*Save previous CSC register*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u32RegCsc = REG_READ32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId));    
    /* Get OcuAction data from Ocu_Ftm_au8OcuAction[] */
    switch(Ocu_Ftm_au8OcuAction[u8ChannelIndex])
    {
        case OCU_SET_LOW:
        {
            u32RegCsc |= FTM_CSC_ELSB_MASK_U32;
            u32RegCsc &= (uint32)(~FTM_CSC_ELSA_MASK_U32);
        }
        break;        
        case OCU_SET_HIGH:
        {
            
            u32RegCsc |= FTM_CSC_ELSA_MASK_U32;
            u32RegCsc |= FTM_CSC_ELSB_MASK_U32;
        }
        break; 
        case OCU_TOGGLE:
        {
            u32RegCsc |= FTM_CSC_ELSA_MASK_U32;
            u32RegCsc &= (uint32)(~FTM_CSC_ELSB_MASK_U32);
        }
        break; 
        default:
        {
            u32RegCsc &= (uint32)(~FTM_CSC_ELSA_MASK_U32);
            u32RegCsc &= (uint32)(~FTM_CSC_ELSB_MASK_U32);
        }
    }
    
    /* write the CSC with appropriate values */    
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CSC_ADDR32(u8ModuleId,u8ChannelId),u32RegCsc);
    /* Release software control */
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_SWOCTRL_ADDR32(u8ModuleId),(uint32)(((uint32)1U) << ((uint8)u8ChannelId)));
    /*clear CHF bit*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId), FTM_CSC_CHF_MASK_U32);    
    /*enable interrupts for the given channel*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId), FTM_CSC_CHIE_MASK_U32);
    /*exit critical section*/
    SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_00();
}

/*=================================================================================================================*/
/**
* @brief   Ocu driver function for stopping the Ftm timer channel.
* @details This function:
*          - stop the timer channel by writing the ELSB:ELSA = 0:0
*          - Clear flag and disable interrupt
*
* @param[in]     u8ChannelIndex        Index for Ftm channels config array
*                pFtmIpConfig          Pointer to Ftm IP configuration structure
*
*/
FUNC(void, OCU_CODE) Ocu_Ftm_StopChannel
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId;              /* assigned FTM HW module */
    VAR(uint8, AUTOMATIC) u8ChannelId;              /* assigned FTM HW channel*/
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;             /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    
    /* Get Ftm Module and Channel of this Ocu channel */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    u8ChannelId = (u8EncodedHwChannel & FTM_CH_MASK_U8);
    /*enter critical section TODO check*/
    SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_01();
    /* write the ELSB:ELSA = 0:0 */
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_RMW32(FTM_CSC_ADDR32(u8ModuleId,u8ChannelId),FTM_CSC_ELSA_MASK_U32|FTM_CSC_ELSB_MASK_U32,(uint32)0U);    
    /*clear CHF bit*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId), FTM_CSC_CHF_MASK_U32);    
    /* Disable interrupts for the given channel*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId), FTM_CSC_CHIE_MASK_U32);
    /*exit critical section*/
    SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_01();
}

/*=================================================================================================================*/
#if (OCU_GET_COUNTER_API == STD_ON)
/**
* @brief   Ocu driver function for getting the current counter value for an Ftm timer channel.
* @details This function is called for reading the Ftm channel counter register.
*
* @param[in]     u8ChannelIndex                Ftm channel
* return         register CNTR current value
*/
FUNC(uint16, OCU_CODE) Ocu_Ftm_GetCounter
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint16, AUTOMATIC)  u16ReturnValue;
    VAR(uint8, AUTOMATIC) u8ModuleId;              /* assigned FTM HW module */
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;             /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    /* Get Ftm Module and Channel of this Ocu channel */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    /*Read the elapsed time*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    u16ReturnValue = (uint16)(REG_READ32(FTM_CNT_ADDR32(u8ModuleId))); 
    return(u16ReturnValue);
}
#endif /*OCU_GET_COUNTER_API == STD_ON*/

/*=================================================================================================================*/ 
#if (OCU_SET_PIN_ACTION_API == STD_ON)
/**
* @brief   Ocu driver function for setting the Pin Action for the current Ftm channel
* @details This function:
*
*
* @param[in]    u8ChannelIndex      Index for Ftm channels config array
*               ePinAction          Type of action: OCU_SET_LOW,OCU_SET_HIGH,OCU_TOGGLE
*               bIsRunning          Is channel running or not?
*               pFtmIpConfig        Pointer to Ftm IP configuration structure
*
*
*/
FUNC(void, OCU_CODE) Ocu_Ftm_SetPinAction
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,
    VAR(Ocu_PinActionType, AUTOMATIC)                               ePinAction,
    VAR(boolean, AUTOMATIC)                                         bIsRunning,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint8, AUTOMATIC) u8ChannelId;             /* assigned FTM HW channel */
    VAR(uint8, AUTOMATIC) u8ModuleId;              /* assigned FTM HW module */
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;             /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32RegCsc;
    
    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    /* Get Ftm Module and Channel of this Ocu channel */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    u8ChannelId = (u8EncodedHwChannel & FTM_CH_MASK_U8);
    /*Save previous u32RegCsc register*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u32RegCsc = REG_READ32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId));
   /* Store OcuAcion value to Ocu_Ftm_au8OcuAction[], config u32RegCsc */ 
    switch(ePinAction)
    {
        case OCU_SET_LOW:
        {
            Ocu_Ftm_au8OcuAction[u8ChannelIndex] = (uint8)OCU_SET_LOW;
            u32RegCsc |= FTM_CSC_ELSB_MASK_U32;
            u32RegCsc &= (uint32)(~FTM_CSC_ELSA_MASK_U32);
        }
        break;        
        case OCU_SET_HIGH:
        {
            Ocu_Ftm_au8OcuAction[u8ChannelIndex] = (uint8)OCU_SET_HIGH;
            u32RegCsc |= FTM_CSC_ELSA_MASK_U32;
            u32RegCsc |= FTM_CSC_ELSB_MASK_U32;
        }
        break;
        case OCU_TOGGLE:
        {
            Ocu_Ftm_au8OcuAction[u8ChannelIndex] = (uint8)OCU_TOGGLE;
            u32RegCsc |= FTM_CSC_ELSA_MASK_U32;
            u32RegCsc &= (uint32)(~FTM_CSC_ELSB_MASK_U32);
        }
        break;
        default:
        {
            u32RegCsc &= (uint32)(~FTM_CSC_ELSA_MASK_U32);
            u32RegCsc &= (uint32)(~FTM_CSC_ELSB_MASK_U32);
            Ocu_Ftm_au8OcuAction[u8ChannelIndex] = (uint8)OCU_DISABLE;
        }
    }    
    if ((boolean)TRUE == bIsRunning)
    {
        /*enter critical section TODO check*/
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_02();
        /* write the FTM_CSC_ADDR32 with appropriate values */
        /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CSC_ADDR32(u8ModuleId,u8ChannelId),u32RegCsc);
        /*exit critical section*/
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_02();
    }
}
#endif /* OCU_SET_PIN_ACTION_API == STD_ON */


/*=================================================================================================================*/
#if (OCU_SET_PIN_STATE_API == STD_ON)
/**
* @brief   Ocu driver function for setting the Pin State for the current Ftm channel
* @details This function:
*
* @param[in]    u8ChannelIndex      Index for Ftm channels config array
*               ePinState           Expectation state of pin:OCU_HIGH,OCU_LOW
*               pFtmIpConfig        Pointer to Ftm IP configuration structure
*
*/
FUNC(void, OCU_CODE) Ocu_Ftm_SetPinState
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,    
    CONST(Ocu_PinStateType, AUTOMATIC)                              ePinState,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint8, AUTOMATIC) u8ChannelId;             /* assigned FTM HW channel  */
    VAR(uint8, AUTOMATIC) u8ModuleId;              /* assigned FTM HW module  */
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;             /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32RegSwoctrl;
        
    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    /* Get Ftm Module and Channel of this Ocu channel */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    u8ChannelId = (u8EncodedHwChannel & FTM_CH_MASK_U8);
    
    /*read current configuration value of SWOCTRL register*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    u32RegSwoctrl = REG_READ32(FTM_SWOCTRL_ADDR32(u8ModuleId));    
    /*set output pin to its configured state*/
    if(OCU_HIGH == ePinState)
    {
    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        u32RegSwoctrl |= (uint32)(((uint32)1U)<<(u8ChannelId+OCU_FTM_SWOCTRL_FORCED_VALUE_OFFSET));
    }
    else
    {
    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        u32RegSwoctrl &= (uint32)(~(uint32)(((uint32)1U)<<(u8ChannelId+OCU_FTM_SWOCTRL_FORCED_VALUE_OFFSET)));
    }    
    /* Enable software control */
    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */    
    u32RegSwoctrl |=  (uint32)(((uint32)1U)<<(u8ChannelId));    
    /*enter critical section TODO check*/
    SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_03();
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_WRITE32(FTM_SWOCTRL_ADDR32(u8ModuleId),u32RegSwoctrl); 
    /*exit critical section*/
    SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_03();
}
#endif /* OCU_SET_PIN_STATE_API == STD_ON */


/*=================================================================================================================*/
#if (OCU_SET_RELATIVE_THRESHOLD_API == STD_ON)
/**
* @brief      The function sets the value of the channel threshold relative to the current value of the counter.
* @details    On entry, the API reads the counter value (ReadValue). Then the new threshold value is computed and written
*             according to the following formula: 
*             NewThresholdValue = ReadValue + RelativeValue or
*             NewThresholdValue = (ReadValue + RelativeValue) - MaxCounterValue if matching occur at next cycle
*
* @param[in]    u8ChannelIndex      Index for Ftm channels config array
*               RelativeValue       Channel timeout value
*               pFtmIpConfig        Pointer to Ftm IP configuration structure
*
* return         Tells the caller whether the compare match will occur (or has already occured) during the current Refence Interval,
*                as a result of setting the new threshold value.
*/

FUNC(Ocu_ReturnType, OCU_CODE) Ocu_Ftm_SetRelativeThreshold
(   
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,    
    VAR(Ocu_ValueType,          AUTOMATIC)                          RelativeValue,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint16, AUTOMATIC) u16CntValuePreUpdate;    /* CNT register value before computing the update */
    VAR(uint16, AUTOMATIC) u16CntValuePostUpdate;   /* CNT register value after computing the update */
    VAR(uint16, AUTOMATIC) u16CmpMatchValue;        /* New CNT register value */
    VAR(Ocu_ReturnType, AUTOMATIC) returnValue;     /* Return value to see if the current counter has overrunned the postupdate CNT */    
    VAR(uint8, AUTOMATIC) u8ModuleId;              /* assigned FTM HW module */
    VAR(uint8, AUTOMATIC) u8ChannelId;              /* assigned FTM HW channel*/
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;             /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    
    /* Get Ftm Module and Channel of this Ocu channel */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    u8ChannelId = (u8EncodedHwChannel & FTM_CH_MASK_U8);
    
    /* Read Counter register */
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u16CntValuePreUpdate = (uint16)REG_READ32(FTM_CNT_ADDR32(u8ModuleId));
    /* Calculate u16CmpMatchValue, matching can occur at current cycle or next cycle */
    /*@violates @ref Ocu_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
    u16CmpMatchValue =  (uint16)((uint32)(u16CntValuePreUpdate + RelativeValue) % Ocu_Ftm_au16MaxCounterValue[u8ChannelIndex]);
    /* Set timeout value to FTM_CV_ADDR32 register*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleId,u8ChannelId),u16CmpMatchValue);
    /* re-Read Counter register */
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    u16CntValuePostUpdate = (uint16)REG_READ32(FTM_CNT_ADDR32(u8ModuleId));
    /*check if compare match will happen before counter roll-over*/
    returnValue = Ocu_Ftm_DetermineNextCmStatus(
                                                    u16CntValuePostUpdate, 
                                                    u16CntValuePreUpdate, 
                                                    u16CmpMatchValue
                                                  );
    return returnValue;
}
#endif /* OCU_SET_RELATIVE_THRESHOLD_API == STD_ON */


/*=================================================================================================================*/
#if (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON)
/**
* @brief      The function set the value of the channel threshold using an absolute input data.
*
* @param[in]     u8ChannelIndex      Index for Ftm channels config array
*                ReferenceValue      Value given by the upper layer and used as a base to determine 
*                                       whether to call the notification before the function exits or not.
*                AbsoluteValue       channel timeout value
*                pFtmIpConfig        Pointer to Ftm IP configuration structur
*
* return         Tells the caller whether the compare match will occur (or has already occured) during the current Refence Interval,
*                as a result of setting the new threshold value.
*/

FUNC(Ocu_ReturnType, OCU_CODE) Ocu_Ftm_SetAbsoluteThreshold
(
    CONST(uint8, AUTOMATIC)                                         u8ChannelIndex,    
    VAR(Ocu_ValueType,  AUTOMATIC)                                  ReferenceValue,
    VAR(Ocu_ValueType,  AUTOMATIC)                                  AbsoluteValue,
    CONSTP2CONST(Ocu_Ftm_IpConfigType, OCU_CONST, OCU_APPL_CONST)   pFtmIpConfig
)
{
    VAR(uint16, AUTOMATIC) u16CntValuePostUpdate;          /* CNT register value after computing the update */
    VAR(Ocu_ReturnType, AUTOMATIC) returnValue;            /* Return value to see if the current counter has overrunned the postupdate CNT */
    
    VAR(uint8, AUTOMATIC) u8ModuleId;              /* assigned FTM HW module */
    VAR(uint8, AUTOMATIC) u8ChannelId;              /* assigned FTM HW channel*/
    VAR(uint8, AUTOMATIC) u8EncodedHwChannel;             /* index of pFtmIpConfig->pChannelsConfig */
    /* Pointer to Ftm channel configuration */
    P2CONST(Ocu_Ftm_ChannelConfigType,   AUTOMATIC, OCU_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    pFtmChannelConfig = &((*(pFtmIpConfig->pChannelsConfig))[u8ChannelIndex]);
    u8EncodedHwChannel = pFtmChannelConfig->u8EncodedHwChannel;
    
    /* Get Ftm Module and Channel of this Ocu channel */
    u8ModuleId = ((Ocu_Ftm_ModuleType)((u8EncodedHwChannel & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
    u8ChannelId = (u8EncodedHwChannel & FTM_CH_MASK_U8);
    
    /* Set timeout value to FTM_CV_ADDR32 register*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleId,u8ChannelId),AbsoluteValue);
    
    /* Read Counter value post update and a constant configurable delay to PostUpdate value to compensate for the execution of the API*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    u16CntValuePostUpdate = (uint16)REG_READ32(FTM_CNT_ADDR32(u8ModuleId));
    
    returnValue = Ocu_Ftm_DetermineNextCmStatus(
                                                    u16CntValuePostUpdate, 
                                                    ReferenceValue, 
                                                    AbsoluteValue
                                                  );
    return returnValue;
}
#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON */

/*=================================================================================================================*/
#if (OCU_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief      The function changes the prescaler of Ftm channel.
* @details This function:
*          - Change value prescaler in SC registers
*
* @param[in]     pFtmIpConfig       Pointer to configuration structure of Ftm channels
* @param[in]     ePrescaler         Prescaler type: normal or alternative
*
*/
FUNC(void, OCU_CODE) Ocu_Ftm_SetClockMode
(
    CONSTP2CONST(Ocu_Ftm_IpConfigType,        AUTOMATIC, OCU_APPL_CONST)  pFtmIpConfig,
    VAR         (Ocu_Ftm_SelectPrescalerType, AUTOMATIC) ePrescaler
)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;          /* assigned FTM HW module  index */
    VAR(uint8, AUTOMATIC) u8Counter;
    P2CONST(Ocu_Ftm_ModuleConfigType, AUTOMATIC, OCU_APPL_CONST) pFtmModuleConfig;
    
    for (u8Counter = 0x0U; u8Counter < pFtmIpConfig->u8NumModules; u8Counter++)
    {
        pFtmModuleConfig = &(*pFtmIpConfig->pModulesConfig)[u8Counter];
        /* Get Ftm Module and Channel of this Ocu channel */
        u8ModuleIdx = pFtmModuleConfig->u8ModuleId;              
        
        if (FTM_OCU_ALTERNATE_CLOCK_MODE == ePrescaler)
        { 
            /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */    
            REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_PS_MASK_U32,(uint32)pFtmModuleConfig->u8AltControlValue);                                  
        }
        else
        {
            /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */          
            REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_PS_MASK_U32,(uint32)(((uint32)(pFtmModuleConfig->u8ModuleControlValue))&OCU_FTM_CLOCK_DIV_MASK_U8)>>OCU_FTM_CLOCK_DIV_SHIFT);
        }
    }    
}
#endif /* OCU_DUAL_CLOCK_MODE == STD_ON */
/*===============================================================================================*/
#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON))
/**
* @brief            Ocu_Ftm_GetMaxCountValue
* @details          This function will return max counter value for given channel
*
* @param[in]        u8IdxChannelConfig -    Index of channel in (*pChannelsConfig)[]
* @return           Ocu_ValueType   - Max counter value for given channel
*/

FUNC (Ocu_ValueType, OCU_CODE) Ocu_Ftm_GetMaxCountValue
(
    VAR(Ocu_ChannelType,    AUTOMATIC)  u8IdxChannelConfig
)
{
    VAR(Ocu_ValueType, AUTOMATIC)  ReturnMaxCountValue;
    
    ReturnMaxCountValue = Ocu_Ftm_au16MaxCounterValue[u8IdxChannelConfig];
    return ReturnMaxCountValue;
}
#endif
/*=================================================================================================================*/
#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This function is a interrupt service routine used to proccess compare events for each Ftm module
* @details          This function will call notification functions configured. If a null pointer
*                   was configured, an error will be reported.
*
* @param[in]        u8FtmChannel - Ftm Channel
*
* @return           void
*
* @implements       Ocu_Ftm_ProcessCommonInterrupt_Activity
*/
/*@violates @ref Ocu_Ftm_C_REF_8 external ... could be made static */
FUNC(void,OCU_CODE) Ocu_Ftm_ProcessCommonInterrupt
(
    CONST(uint8, AUTOMATIC) u8FtmChannel
)
{
    VAR   (Ocu_Ftm_ModuleType, AUTOMATIC) u8ChannelId;
    VAR   (Ocu_Ftm_ModuleType, AUTOMATIC) u8ModuleId;
    VAR    (uint32,            AUTOMATIC) u32ChfStatus;  /* Status of channel flag bit*/
    VAR    (uint32,            AUTOMATIC) u32ChieStatus; /* Status of channel interrupt enable bit */
    VAR    (Ocu_Ftm_ChannelType,     AUTOMATIC) u8ChannelsModOffset; /* Encode channel ID and module ID to a u8 variable */
   
    /*get module Id for current Hw channel and the channel index*/
    u8ChannelId =   ((u8FtmChannel) & FTM_CH_MASK_U8);
    u8ModuleId  =   (((u8FtmChannel) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);
    /*get Channel flag status*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u32ChieStatus = ((REG_READ32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId))) & FTM_CSC_CHIE_ENABLE_U32);
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u32ChfStatus = ((REG_READ32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId))) & FTM_CSC_CHF_MASK_U32);
    /*enter critical section TODO check*/
    SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_04();
    /*clear CHF bit*/
    /*@violates @ref Ocu_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Ocu_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, u8ChannelId), FTM_CSC_CHF_MASK_U32);
    /*exit critical section*/
    SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_04();
    u8ChannelsModOffset = ((Ocu_Ftm_ChannelType)OCU_FTM_MODULE_CHANNELS_NO * (Ocu_Ftm_ChannelType)u8ModuleId) + u8ChannelId;
    if((((uint32)0U)!= u32ChieStatus) && (((uint32)0U)  != u32ChfStatus))
    {
        Ocu_Ipw_ProcessCommonInterrupt(u8ChannelsModOffset);
    }
}


#endif /* OCU_NOTIFICATION_SUPPORTED == STD_ON */

#define OCU_STOP_SEC_CODE
/*
* @violates @ref Ocu_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Ocu_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

