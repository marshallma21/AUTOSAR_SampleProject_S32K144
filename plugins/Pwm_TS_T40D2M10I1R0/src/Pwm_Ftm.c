/**
*   @file           Pwm_Ftm.c
*   @version        1.0.1
*
*   @brief          AUTOSAR Pwm - Pwm implementation using Ftm.
*   @details        Pwm implementation using Ftm.
*
*   @addtogroup     PWM_MODULE
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
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_Ftm_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before 'include'
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_Ftm_C_REF_2
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer
* This rule can not be avoided because it appears when addressing memory mapped registers or other hardware specific feature
*
* @section Pwm_Ftm_C_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* 
* @section Pwm_Ftm_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_Ftm_C_REF_5
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not be permitted.
* This is not a violation since the same function is called from different places with different parameter values.*
*
* @section Pwm_Ftm_C_REF_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_Ftm_C_REF_7
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type may only be cast to type that is narrower and of the same
* signedness as the underlying type of the expression.
* This is not a violation since the expression is used to access a 32bit register using a 8 bit channel value.
*
* @section Pwm_Ftm_C_REF_8
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_Ftm_C_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, cast from unsigned int to pointer
* This rule can not be avoided because it appears when addressing memory mapped registers or other hardware specific feature
*
* @section Pwm_Ftm_C_REF_10
* Violates MISRA 2004 Advisory Rule 11.4, cast from pointer to pointer
* To typecast the pointer from one data type to other data type
*
* @section Pwm_Ftm_C_REF_11
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
* be implicitly converted to a different underlying type.
*
* @section Pwm_Ftm_C_REF_12
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed from
* within a single function.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*
* @file           Pwm_Ftm.c
*/

#include "Std_Types.h"


#include "Reg_eSys_Ftm.h"

/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Ftm.h"

/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Ipw_Types.h"

/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Ftm_Irq.h"

/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Ipw_Notif.h"


#include "Ftm_Common_Types.h"
#ifndef USER_MODE_REG_PROT_ENABLED
#define USER_MODE_REG_PROT_ENABLED  (PWM_REGISTER_PROTECTION)
#endif
#include "SilRegMacros.h"
#include "SchM_Pwm.h"

/*===============================================================================================
*                            SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Pwm_Ftm.c
*/
#define PWM_FTM_VENDOR_ID_C                     43
#define PWM_FTM_MODULE_ID_C                     121
/** @violates @ref Pwm_Ftm_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
#define PWM_FTM_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Pwm_Ftm_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
#define PWM_FTM_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Pwm_Ftm_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
#define PWM_FTM_AR_RELEASE_REVISION_VERSION_C   2
#define PWM_FTM_SW_MAJOR_VERSION_C              1
#define PWM_FTM_SW_MINOR_VERSION_C              0
#define PWM_FTM_SW_PATCH_VERSION_C              1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same Autosar version */
    #if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm_Ftm.c and Std_Types.h are different"
    #endif
#endif


/* Check if source file and Reg_eSys_Ftm.h are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
    #error "Pwm_Ftm.c and Reg_eSys_Ftm.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_Ftm.h are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c and Reg_eSys_Ftm.h are different"
#endif
/* Check if source file and Reg_eSys_Ftm.h are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION)  || \
     (PWM_FTM_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and Reg_eSys_Ftm.h are different"
#endif

/* Check if source file and Ftm_Common_Types.h are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != FTM_COMMON_TYPES_VENDOR_ID)
    #error "Pwm_Ftm.c and Ftm_Common_Types.h have different vendor ids"
#endif
/* Check if source file and Ftm_Common_Types.h are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c and Ftm_Common_Types.h are different"
#endif
/* Check if source file and Ftm_Common_Types.h are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != FTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != FTM_COMMON_TYPES_SW_MINOR_VERSION)  || \
     (PWM_FTM_SW_PATCH_VERSION_C != FTM_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and Ftm_Common_Types.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Pwm_Ftm.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (PWM_FTM_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and SilRegMacros.h are different"
#endif


/* Check if source file and Pwm_Ftm.h header file are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != PWM_FTM_VENDOR_ID)
    #error "Pwm_Ftm.c and Pwm_Ftm.h have different vendor ids"
#endif
/* Check if source file and Pwm_Ftm.h header file are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != PWM_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != PWM_FTM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != PWM_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c and Pwm_Ftm.h are different"
#endif
/* Check if source file and Pwm_Ftm.h header file are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != PWM_FTM_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != PWM_FTM_SW_MINOR_VERSION) || \
     (PWM_FTM_SW_PATCH_VERSION_C != PWM_FTM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and Pwm_Ftm.h are different"
#endif

/* Check if source file and Pwm_Ftm_Irq.h header file are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != PWM_FTM_IRQ_VENDOR_ID)
    #error "Pwm_Ftm.c and Pwm_Ftm_Irq.h have different vendor ids"
#endif
/* Check if source file and Pwm_Ftm_Irq.h header file are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != PWM_FTM_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != PWM_FTM_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != PWM_FTM_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c and Pwm_Ftm_Irq.h are different"
#endif
/* Check if source file and Pwm_Ftm_Irq.h header file are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != PWM_FTM_IRQ_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != PWM_FTM_IRQ_SW_MINOR_VERSION) || \
     (PWM_FTM_SW_PATCH_VERSION_C != PWM_FTM_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and Pwm_Ftm_Irq.h are different"
#endif

/* Check if source file and Pwm_Ipw_Types.h are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_Ftm.c and Pwm_Ipw_Types.h have different vendor ids"
#endif
/* Check if source file and Pwm_Ipw_Types.h are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c and Pwm_Ipw_Types.h are different"
#endif
/* Check if source file and Pwm_Ipw_Types.h are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != PWM_IPW_TYPES_SW_MINOR_VERSION)  || \
     (PWM_FTM_SW_PATCH_VERSION_C != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and Pwm_Ipw_Types.h are different"
#endif

/* Check if source file and Pwm_Ipw_Notif.h are of the same vendor */
#if (PWM_FTM_VENDOR_ID_C != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Pwm_Ftm.c  and Pwm_Ipw_Notif.h have different vendor ids"
#endif
/* Check if source file and Pwm_Ipw_Notif.h are of the same Autosar version */
#if ((PWM_FTM_AR_RELEASE_MAJOR_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_MINOR_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_FTM_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ftm.c  and Pwm_Ipw_Notif.h are different"
#endif
/* Check if source file and Pwm_Ipw_Notif.h are of the same software version */
#if ((PWM_FTM_SW_MAJOR_VERSION_C != PWM_IPW_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_FTM_SW_MINOR_VERSION_C != PWM_IPW_NOTIF_SW_MINOR_VERSION)  || \
     (PWM_FTM_SW_PATCH_VERSION_C != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ftm.c and Pwm_Ipw_Notif.h are different"
#endif


/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define FTM_FAULT_MAX                                  (4U)
#define PWM_FTM_SWOCTRL_BITS_OFFSET             ((uint16)8U)
#define PWM_FTM_SWOCTRL_BITS_CMB_OFFSET         ((uint16)9U)
/*===============================================================================================
*                                      GLOBAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/


#define PWM_START_SEC_VAR_NO_INIT_16

/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

/**
* @brief Array of values for the period for each module
*/
static VAR(uint16, PWM_VAR) Pwm_Ftm_au16Period[PWM_FTM_MODULE_NO];

#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
/**
* @brief Array of the duty value of the Ftm channels used for variable period API
*/
static VAR(uint16, PWM_VAR) Pwm_Ftm_au16ChannelDuty[PWM_FTM_CHANNELS_MAX_U8];
#endif

#define PWM_STOP_SEC_VAR_NO_INIT_16
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


#define PWM_START_SEC_VAR_NO_INIT_8
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"
#if ((PWM_FAULT_SUPPORTED == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/**
* @brief Array of values used to map possible causes for interrupts to each ftm channel. 
* Possible values: PWM_TOF_MATCH or PWM_CHF_MATCH depending on PWM polarity;
* The value 0 will be interpreted as NO EDGE; value of 1 will be considered match on 
*/
static volatile VAR(Pwm_Ftm_EdgeStateType, PWM_VAR) Pwm_Ftm_aNotifToChannelMap[PWM_FTM_CHANNELS_NO];

#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */



#if ((PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))

/**
* @brief Array of values containing the state of each channel
*/
static VAR(uint8, PWM_VAR) Pwm_Ftm_au8ChannelState[PWM_FTM_CHANNELS_MAX_U8];
#endif

#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief Array of values containing the previos state of each channel
*/
static VAR(uint8, PWM_VAR) Pwm_Ftm_au8PreviosChannelState[PWM_FTM_CHANNELS_MAX_U8];
#endif

#if ((PWM_ENABLE_PHASE_SHIFT == STD_ON)&&(PWM_NOTIFICATION_SUPPORTED == STD_ON))
/**
* @brief Array stores kind of channels, phase shifted or not. 
*/    
static VAR(uint8, PWM_VAR) Pwm_Ftm_aIsPhaseShiftChannel[PWM_FTM_MODULE_NO];

#endif

#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
/**
* @brief Array holding the fault check status of all FTM modules
*/
/*
* @violates @ref Pwm_Ftm_C_REF_12 Objects shall be defined at block scope if they are only 
* accessed from within a single function.
*/
static  VAR(uint8, PWM_VAR) Pwm_Ftm_u8FaultCheck;
#endif
#endif


#define PWM_STOP_SEC_VAR_NO_INIT_8
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) ||\
     (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON ))
/**
* @brief Array holding the configured polarity for all Ftm channels
*/
static  VAR(Pwm_OutputStateType, PWM_VAR) eChannelPolarity[PWM_FTM_CHANNELS_MAX_U8];
#endif

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_DE_INIT_API == STD_ON))
/**
* @brief Array holding the configured polarity for all Ftm channels
*/
static  VAR(Pwm_OutputStateType, PWM_VAR) eChannelIdleState[PWM_FTM_CHANNELS_MAX_U8];
#endif

/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"
/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function disables compare interrupts for the specified channel.
* @details      This function disables compare interrupts and clears flags
                for the specified channel.
*
* @param[in]    nFtmChannel         Ftm channel id
* @param[in]    nFtmChannel         Channel Id
*
* @return       void   
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_DisableCmpIrq
(
    VAR(Pwm_Ftm_ModuleType,  AUTOMATIC) nFtmModule,
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmChannel
);

#endif  /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */



/**
* @brief    This inline function performs the update of the Ftm registers, based on the values computed
*           by the 2 functions above.
* @details  This function can be called from Pwm_Ftm_SetDutyCycle or Pwm_Ftm_SetPeriod and Duty or Init function.
*
* @param[in]    nFtmModule          Ftm channel id
* @param[in]    nFtmChannel         Channel Id
* @param[in]    u16Duty             Duty cycle value
* @param[in]    u16PhaseShiftValue  Phase shift value in ticks
* @param[in]    eSyncUpdate         Load immediately or stay in buffer
* @param[in]    eAlignement         Edge alignment type
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_SetDutyRegs
(
    VAR(Pwm_Ftm_ModuleType,  AUTOMATIC) nFtmModule,
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmChannel,
    VAR(uint16,              AUTOMATIC) u16Duty,
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    VAR(uint16,              AUTOMATIC) u16PhaseShiftValue,
#endif
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    VAR(Pwm_DataUdateType,   AUTOMATIC) eSyncUpdate,
#endif
    VAR(Pwm_AlignmentType,   AUTOMATIC) eAlignment
);



/**
* @brief    This inline function calculates the value of the period depending on the edge alignment mode .
* @details  This function can be called from Pwm_Ftm_SetPeriod and Duty or Init function and will store the 
*           calcualted value in the Pwm_Ftm_au16Period[] array
* @param[in]    Pwm_PeriodType   Raw value of the period
* @param[in]    eAlignement      Edge alignment type
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_CalculatePeriod
(
        VAR(Pwm_Ftm_ModuleType, AUTOMATIC) nFtmModule,
        VAR(Pwm_PeriodType,     AUTOMATIC)  nPeriod,
        VAR(Pwm_AlignmentType,  AUTOMATIC)  eAlignment
);


#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_DE_INIT_API == STD_ON))

/**
* @brief    This inline function performs the update of the SWOCTRL register on request
* @details  This function can be called from Pwm_Ftm_SetOutputToIdle,  Pwm_Ftm_DeInit and Pwm_Ftm_ForceOutputToZero functions
*
* @param[in]    nFtmModule           Ftm channel id
* @param[in]    nFtmChannel          Channel Id
* @param[in]    nFtmOutputLevel      Pwm output level
* @param[in]    eAlignement          Edge alignment type
* @param[in]    bActivationState     Activation state of the Sw output control (true - means sw control is enabled, false - sw control disabled for the given channel)
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_SetSwOutputControl
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
(
    VAR(Pwm_Ftm_ModuleType,  AUTOMATIC) nFtmModule,
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmChannel,
    VAR(Pwm_OutputStateType, AUTOMATIC) nFtmOutputLevel, 
    VAR(Pwm_AlignmentType,   AUTOMATIC) eAlignment,     
    VAR(boolean,             AUTOMATIC) bActivationState 
);
#endif

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        This function disables compare interrupts for the specified channel.
* @details      This function disables compare interrupts and clears flags
                for the specified channel.
*
* @param[in]    nFtmModule         Ftm module id
* @param[in]    nFtmChannel         Channel Id
*
* @return       void   
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_DisableCmpIrq
(
    VAR(Pwm_Ftm_ModuleType,  AUTOMATIC) nFtmModule,
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmChannel
)
{
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmFirstChannelId;
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nChannelLoopIndex;
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nMaxFtmChannels;
    VAR(Pwm_OutputStateType, AUTOMATIC) eChanEdgeEnabled = PWM_LOW;

    VAR(Pwm_Ftm_EdgeStateType, AUTOMATIC) nEdgeState;
    
    /*disable interrupts for the given channel*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    /* @violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(nFtmModule,(uint8)nFtmChannel), FTM_CSC_CHIE_MASK_U32);

    
    /* Clear CHnF bit */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    /* @violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(nFtmModule,(uint8)nFtmChannel), FTM_CSC_CHF_MASK_U32);


    /*get number of channel for given module... it may be that for different platfroms different number of channels are connected to each ftm 
    module*/      
    nFtmFirstChannelId = ((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)nFtmModule);   
    
    nMaxFtmChannels = (nFtmFirstChannelId + (Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO);
    
    /*for all channels of the given module check if it is possible to disable TOIE interrupt - this means that at this stage for all channels
     * the TOF behavior array should have the value  PWM_NO_EDGE. If something else is detected then TOIE can not be disabled.
    */  
    for (nChannelLoopIndex = nFtmFirstChannelId; nChannelLoopIndex < nMaxFtmChannels; nChannelLoopIndex++)
    {
#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
        nEdgeState = Pwm_Ftm_aNotifToChannelMap[nChannelLoopIndex] & (PWM_TOF_IRQ_EDGE | PWM_TOF_IRQ_FAULT_IDLE_STATE);
#endif
#else
        nEdgeState = Pwm_Ftm_aNotifToChannelMap[nChannelLoopIndex] & (PWM_TOF_IRQ_EDGE);
#endif
       
       /*Check if no channel has PWM_TOF_EDGE value set */
        if(nEdgeState != PWM_NO_EDGE)
        {
            eChanEdgeEnabled = PWM_HIGH;

            /*intentional break to optimize run time*/
            break;
        }
        else
        {
            /*do nothing*/
        }
    }

    /*if no channel has edge notifications enabled for TOF then we can safely clear */
    if(PWM_LOW == eChanEdgeEnabled)
    {
        /* disable TOIE interrupt */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_SC_ADDR32(nFtmModule), FTM_SC_TOIE_MASK_U32);
    }
    else
    {
        /*do nothing*/
    }


    /* Clear TOF interrupt flags */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_CLEAR32(FTM_SC_ADDR32(nFtmModule), FTM_SC_TOF_MASK_U32); 
}


#endif /* PWM_NOTIFICATION_SUPPORTED */




/**
* @brief    This inline function performs the update of the Ftm registers, based on the values computed
*           by the 2 functions above.
* @details  This function can be called from Pwm_Ftm_SetDutyCycle or Pwm_Ftm_SetPeriod and Duty or Init function.
*
* @param[in]    nFtmModule          Ftm module id
* @param[in]    nFtmChannel         Channel Id
* @param[in]    u16Duty             Duty cycle value
* @param[in]    u16PhaseShiftValue  Phase shift value in ticks
* @param[in]    eSyncUpdate         Load immediately or stay in buffer
* @param[in]    eAlignement         Edge alignment type
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_SetDutyRegs
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
(
    VAR(Pwm_Ftm_ModuleType,  AUTOMATIC) nFtmModule,
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmChannel,
    VAR(uint16,              AUTOMATIC) u16Duty,
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    VAR(uint16,              AUTOMATIC) u16PhaseShiftValue,
#endif
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    VAR(Pwm_DataUdateType,   AUTOMATIC) eSyncUpdate,
#endif
    VAR(Pwm_AlignmentType,   AUTOMATIC) eAlignment
)
{

    /*calculated duty cycle value: to be stored in CV registers*/
    VAR(uint16, AUTOMATIC) u16RegDutyVal = (((uint8) 0U));
 
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nLogicalChannelIndex = ((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)nFtmModule) + nFtmChannel;
#endif    
    
    /*Scale duty cycle to the current period*/
    u16RegDutyVal = (uint16)(((uint32)Pwm_Ftm_au16Period[nFtmModule] * (uint32)u16Duty) >> ((uint32)15U));

    /*if duty is 100% then increase by 1 the value so it will exceed value of period*/
    if(PWM_FTM_DUTY_100 == u16Duty)
    {
        u16RegDutyVal = u16RegDutyVal + 1U;
    }
  
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)   
    if ((((uint16)0U) == u16Duty) || (((uint16)0x8000U) == u16Duty))
    {
    
        if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex]) & PWM_TOF_IRQ_EDGE))
        {
            /*mark channel index as not using TOF notifications*/
            Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex] |= PWM_TOF_IRQ_NO_EDGE_NOTIF;
        }
        
#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)        
        if (PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex]) & PWM_TOF_IRQ_FAULT_IDLE_STATE))
        {
            /* Clear check fault notification */
            Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex] &= (uint8)~(PWM_TOF_IRQ_FAULT_IDLE_STATE);
        }
#endif
#endif 
        
        /*disable match compare interrupts for each channel*/
        Pwm_FtmInternal_DisableCmpIrq(nFtmModule, nFtmChannel);
        
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    
        /*disable match compare interrupts phase shift channel n+1*/
        if (0U != (Pwm_Ftm_aIsPhaseShiftChannel[nFtmModule] & (uint8)((uint32)1U << nFtmChannel)))
        {
            Pwm_FtmInternal_DisableCmpIrq(nFtmModule, nFtmChannel + (uint8)1U);
        }
#endif
       
    }
    else
    {
            /*enable match compare interrupts for each channel*/
        if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex]) & PWM_TOF_IRQ_EDGE))
        {
            /*mark channel as using tof interrupt with notification*/
            Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex] &= (uint8)~(PWM_TOF_IRQ_NO_EDGE_NOTIF);
            
            /* enable TOIE interrupt */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_SC_ADDR32(nFtmModule), FTM_SC_TOIE_MASK_U32);
        }      
        
#ifdef ERR_IPV_FTM_0002
#if (ERR_IPV_FTM_0002 == STD_ON)        
        if (PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex]) & PWM_TOF_IRQ_FAULT_IDLE_STATE))
        {
            /* Clear check fault notification */
            Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex] &= (uint8)~(PWM_TOF_IRQ_FAULT_IDLE_STATE);
            
            /*disable match compare interrupts for each channel*/
            Pwm_FtmInternal_DisableCmpIrq(nFtmModule, nFtmChannel);
        }
#endif
#endif          
            
        if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex]) & PWM_CHF_IRQ_EDGE))
        {
            /*enable interrupts for the given channel*/
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FTM_CSC_ADDR32(nFtmModule,(uint8)nFtmChannel), FTM_CSC_CHIE_MASK_U32);
        }
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    
        /*enable interrupts for phase shifted channel, both n and n+1*/
        if (0U != (Pwm_Ftm_aIsPhaseShiftChannel[nFtmModule] & (uint8)((uint32)1U << nFtmChannel)))
        {
            if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex]) & PWM_CHF_IRQ_EDGE))
            {
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                REG_BIT_SET32(FTM_CSC_ADDR32(nFtmModule,(uint8)nFtmChannel), FTM_CSC_CHIE_MASK_U32);
            }
            if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[nLogicalChannelIndex + (uint8)1U]) & PWM_CHF_IRQ_EDGE))
            {
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                REG_BIT_SET32(FTM_CSC_ADDR32(nFtmModule, nFtmChannel + (uint8)1U), FTM_CSC_CHIE_MASK_U32);
            }
        }
#endif
         
    }
#endif  
     if((PWM_COMBINE_COMPL == eAlignment) || (PWM_COMBINE_SYNCED == eAlignment))
     {
            /*get CV register address for the duty-cycle */
          /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
          /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
          /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
          /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
          REG_WRITE32(FTM_CV_ADDR32(nFtmModule, (uint8)nFtmChannel), (((uint32)1U)));  
          /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
          /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
          /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
          /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
          REG_WRITE32(FTM_CV_ADDR32(nFtmModule, (uint8)(nFtmChannel + ((uint8)1U))), (uint32)u16RegDutyVal); 
     }
    else
    {
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    if((PWM_PHASE_SHIFTED_COMPLEMENTARY == eAlignment) || (PWM_PHASE_SHIFTED_SYNCED == eAlignment) || (PWM_PHASE_SHIFT_SINGLE == eAlignment))
    {
        if(0x8000U == u16Duty)
        {
            u16RegDutyVal = Pwm_Ftm_au16Period[nFtmModule]+1U;
        }
        else if(0U == u16Duty)
        {
            u16RegDutyVal = u16PhaseShiftValue;
        }
        else
        {
            /* The n+1 match can occur at the nect cycle */
            u16RegDutyVal = (u16PhaseShiftValue + u16RegDutyVal)%(Pwm_Ftm_au16Period[nFtmModule]);
        }
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CV_ADDR32(nFtmModule, (nFtmChannel + ((uint8)1U))), ((uint32)u16RegDutyVal));
    }
    else
    {
#endif  
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */                           
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_WRITE32(FTM_CV_ADDR32(nFtmModule,(uint8)nFtmChannel), (uint32)u16RegDutyVal);        
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        }
#endif    
    }
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    if(PWM_UPDATE_ASYNCHRONOUS == eSyncUpdate)
    {
#endif
        /** use sw sync to udpate CnV registry immediately or at the end of the PWM period arccoding according SWRSTCNT bit*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */        
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SYNC_ADDR32(nFtmModule), FTM_SYNC_SWSYNC_MASK_U32);
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))        
    }
    else
    {
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */        
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SYNC_ADDR32(nFtmModule), FTM_SYNC_SWSYNC_MASK_U32);
        
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_SYNC_ADDR32(nFtmModule), FTM_SYNC_SWSYNC_MASK_U32);
    }
#endif    
}


#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_DE_INIT_API == STD_ON))

/**
* @brief    This inline function performs the update of the SWOCTRL register on request
* @details  This function can be called from Pwm_Ftm_SetOutputToIdle,  Pwm_Ftm_DeInit and Pwm_Ftm_ForceOutputToZero functions
*
* @param[in]    nFtmModule           Ftm channel id
* @param[in]    nFtmChannel          Channel Id
* @param[in]    nFtmOutputLevel      Pwm output level
* @param[in]    eAlignement          Edge alignment type
* @param[in]    bActivationState     Activation state of the Sw output control (true - means sw control is enabled, false - sw control disabled for the given channel)
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_SetSwOutputControl
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
(
    VAR(Pwm_Ftm_ModuleType,  AUTOMATIC) nFtmModule,
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) nFtmChannel,
    VAR(Pwm_OutputStateType, AUTOMATIC) nFtmOutputLevel,
    VAR(Pwm_AlignmentType,   AUTOMATIC) eAlignment,    
    VAR(boolean,             AUTOMATIC) bActivationState 
)
{
    VAR(uint16,             AUTOMATIC) u16SwoCtrlValue = (uint16)0U; 
    VAR(uint16,             AUTOMATIC) u16ChanBitMask = (uint16)1U;    
    VAR(uint16,             AUTOMATIC) u16TempPolVal = (uint16)0U; 
    VAR(uint16,             AUTOMATIC) u16SwoCtrlBitMask = (uint16)0U;
    
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u16SwoCtrlValue = REG_READ16(FTM_SWOCTRL_ADDR32(nFtmModule));

    
    if  (   (PWM_COMBINE_SYNCED == eAlignment) || 
            (PWM_COMBINE_COMPL == eAlignment) || 
            (PWM_PHASE_SHIFTED_SYNCED == eAlignment) ||
            (PWM_PHASE_SHIFTED_COMPLEMENTARY == eAlignment)
        )
    {
         u16ChanBitMask = (uint16)3U;   /*two consecutive bits (n and n +1) */  
    }
    
    /*changing the output using SWOCTRL depends on the given polarity define in POL register. Basically if, for a given channel POL.x bit, is
    set (Pwm polarity is set to LOW) then setting SWOCTRL.x bit will result in an LOW output instead of HIGH as was expected */
            
    /*read FTMn_POL register and get channel polarity*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u16TempPolVal = (REG_READ16(FTM_POL_ADDR32(nFtmModule)) & ((uint16)(((uint32)u16ChanBitMask) << (uint16)nFtmChannel)));
    
    /*shift the polarity bit to match the position would be expected in SWOCTRL*/
    u16TempPolVal = (uint16)((uint32)u16TempPolVal << PWM_FTM_SWOCTRL_BITS_OFFSET);

    /*clear the SWOCTRL bit(s) from the SwCtrlValue for the given channel*/
     u16SwoCtrlValue = u16SwoCtrlValue & ((uint16)(~(((uint32)u16ChanBitMask) << (((uint16)nFtmChannel) + PWM_FTM_SWOCTRL_BITS_OFFSET))));    
    
    if ((boolean)TRUE == bActivationState)
    {                
        if (PWM_HIGH == nFtmOutputLevel)
        {                
            /*Sw control on given channel was requested so corresponding channel bits will be set to "1"*/
            u16SwoCtrlBitMask =  ((uint16)(((uint32)u16ChanBitMask) << (((uint16)nFtmChannel) + PWM_FTM_SWOCTRL_BITS_OFFSET)));   
        }
        else
        {        
           /*do nothing*/    
        }        
            
        /*XOR between polarity bit(s) of the given channel register (shifted left by 8) and the desired sw output value will provide the 
        correct values of the SWOCTRL*/
        u16SwoCtrlValue = ((u16SwoCtrlBitMask ^ u16TempPolVal) | u16SwoCtrlValue);
                    
        /*Sw control on given channel was requested so corresponding channel bit will be set to "1"*/
        u16SwoCtrlValue  = u16SwoCtrlValue | (uint16)(((uint32)u16ChanBitMask) << ((uint16)nFtmChannel));    
    }
    else
    {
        /*Sw control on given channel has to be dezactivated so corresponding channel bits will be set to "0"*/
        u16SwoCtrlValue = u16SwoCtrlValue & ((uint16)(~((uint32)u16ChanBitMask << (uint16)nFtmChannel)));
    }    
        
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_WRITE16(FTM_SWOCTRL_ADDR32(nFtmModule), u16SwoCtrlValue); 

     
    /** use sw sync to udpate CnV registry immediately or at the end of the PWM period arccoding according SWRSTCNT bit*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */        
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_SET32(FTM_SYNC_ADDR32(nFtmModule), FTM_SYNC_SWSYNC_MASK_U32);
}
#endif


/**
* @brief    This inline function calculates the value of the period depending on the edge alignment mode .
* @details  This function can be called from Pwm_Ftm_SetPeriod and Duty or Init function and will store the 
*           calcualted value in the Pwm_Ftm_au16Period[] array
* @param[in]    nFtmModule       Ftm module id 
* @param[in]    Pwm_PeriodType   Raw value of the period
* @param[in]    eAlignement      Edge alignment type
*/
static FUNC(void, PWM_CODE) Pwm_FtmInternal_CalculatePeriod
(
        VAR(Pwm_Ftm_ModuleType, AUTOMATIC)  nFtmModule,
        VAR(Pwm_PeriodType,     AUTOMATIC)  nPeriod,
        VAR(Pwm_AlignmentType,  AUTOMATIC)  eAlignment
)
{
    if (PWM_CENTER_ALIGNED == eAlignment)
    {

        /*for center aligned edges Pwm_period = (FTM_MOD - FTM_CNTIN) x 2*/
        /*assuming FTM_CNTIN a value fixed by configuration (which cannot be changed at run time)  then FTM_MOD = (Pwm_Period/2) - FTM_CNTIN */
        Pwm_Ftm_au16Period[nFtmModule] = ((uint16)((uint16)(nPeriod -  ((uint16)1U)) >> ((uint16)1U)));

    }
    else
    {
        /*for all types of PWM edges (except CENTER_ALIGEND) period = (FTM_MOD - FTM_CNTIN + 1) this means: */
         Pwm_Ftm_au16Period[nFtmModule] = (nPeriod - ((uint16)1U));
    }
 }
 
/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/


/*===============================================================================================*/
/**
* @brief            This function initializes all internals variables of the driver.
* @details          This function will initialize with default values all Ftm submodule registers.
*                   Will loop through all Ftm channels in the configuration structure and will
*                   setup required submodules for each channel
*
*
* @param[in]        pFtmIpConfig  Pointer to Ftm channels configuration structure
*
*
* @return           void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_Init
(   
    CONSTP2CONST(Pwm_Ftm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{
    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

        /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8InternalModuleId;
    
    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8HwModuleId;
    
    
    /*total number of used modules*/
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8NumModules;
   
   /*number of used for each module*/
    VAR    (Pwm_Ftm_ChannelType,          AUTOMATIC) u8NumChannels;
    
    /*index value of the current channel*/
    VAR    (Pwm_Ftm_ChannelType,          AUTOMATIC) u8CurChannel;
   
    /*temporary value to store FTM_CSCregister value*/
    VAR(uint32,              AUTOMATIC) u32TempCscVal =  (uint32)0U;

    /*temporary value to stoare FTM_CSCregister value*/
    VAR(uint32,              AUTOMATIC) u32TempPolVal;
    
    /*temporary value to stoare FTM_CSCregister value*/
    VAR(uint32,              AUTOMATIC) u32CombBitsPolVal =  (uint32)0U;
    
    /*temporary value to store FTM_DEADTIME register value*/
    VAR(uint32,              AUTOMATIC) u32TempDeadtimeVal =  (uint32)0U;
    
    /*calculated edge alignment for current module*/
    VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;

    /*default duty value*/
    VAR(uint16,              AUTOMATIC) u16Duty;

    /*default period value*/
    VAR(uint16,              AUTOMATIC) u16RegPeriodVal;

    /*index value of the current Hw channel*/
    VAR    (Pwm_Ftm_ChannelType,          AUTOMATIC) u8HwChannel;

    /*channel polarity*/
    VAR(Pwm_OutputStateType,   AUTOMATIC) ePolarity;

    
    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Pointer to Ftm Module configuration */
    P2CONST(Pwm_Ftm_ModuleConfigType,    AUTOMATIC, PWM_APPL_CONST) pFtmModuleConfig = NULL_PTR;
    
    
    /*Get number of modules used for the current Ftm module*/
    u8NumModules = pFtmIpConfig->nNumModules;

    /*Get number of channels used for the current Ftm module*/
    u8NumChannels = pFtmIpConfig->nNumChannels;

    /*initialize Array used to store current Duty Cycle value and the arrays used for mapping channels to notifications associated to Ftm channels*/
    for(u8CurChannel = (uint8)0; u8CurChannel < PWM_FTM_CHANNELS_NO; u8CurChannel++)
    {       
#if ((PWM_FAULT_SUPPORTED == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))
        Pwm_Ftm_aNotifToChannelMap[u8CurChannel] = PWM_NO_EDGE;
#endif

    }
    
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))
    for(u8CurChannel = (uint8)0; u8CurChannel < PWM_FTM_CHANNELS_MAX_U8; u8CurChannel++)
    {

        Pwm_Ftm_au16ChannelDuty[u8CurChannel] =  (uint8)0;
    }
#endif

#if ((PWM_ENABLE_PHASE_SHIFT == STD_ON)&&(PWM_NOTIFICATION_SUPPORTED == STD_ON))
    for(u8ModuleId = (uint8)0; u8ModuleId < u8NumModules; u8ModuleId++)
    {
        Pwm_Ftm_aIsPhaseShiftChannel[u8ModuleId] =  0U;
    }    
#endif

#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
    Pwm_Ftm_u8FaultCheck =  ((uint8) 0U);
#endif
#endif

    /*initialize registry for all used modules*/
    for (u8ModuleId = ((uint8)0U);  u8ModuleId < u8NumModules;  u8ModuleId++)
    {
        /*Clear u32TempPolVal to 0 before setting its bits arcording channels*/
        u32TempPolVal =  (uint32)0U;
        /*Get pointer to configuration data of the Ftm module*/
        pFtmModuleConfig = &(*pFtmIpConfig->pModulesConfig)[u8ModuleId];

        /*get FTM Hw module Index*/
        u8HwModuleId = pFtmModuleConfig->u8FtmHwModuleId;

        /*clear WPDIS bit if set so that registers can pe written*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        if ((uint32)0 != REG_BIT_GET32(FTM_FMS_ADDR32(u8HwModuleId), FTM_FMS_WPEN_MASK_U32))
        {
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_WPDIS_MASK_U32);
        }
        else
        {
            /*do nothing*/
        }

        /*write FTMn_MODE register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_MODE_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegMode);

        /*clear FTMEN bit to enable buffer-to-registry transfers*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_FTMEN_MASK_U32);

         /*write FTMn_CONF register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_CONF_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegConf);

#if (PWM_FAULT_SUPPORTED == STD_ON)
        /*read fault bits*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        if ( (uint32)0 != REG_BIT_GET32(FTM_FMS_ADDR32(u8HwModuleId), (FTM_FMS_FAULTF_MASK_U32 | FTM_FMS_FAULTF3_MASK_U32 | FTM_FMS_FAULTF2_MASK_U32 | FTM_FMS_FAULTF1_MASK_U32 | FTM_FMS_FAULTF0_MASK_U32)))
        {
              /* Clear Fault interrupt flags */
              /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
              /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
               REG_BIT_CLEAR32(FTM_FMS_ADDR32(u8HwModuleId), (FTM_FMS_FAULTF_MASK_U32 | FTM_FMS_FAULTF3_MASK_U32 | FTM_FMS_FAULTF2_MASK_U32 | FTM_FMS_FAULTF1_MASK_U32 | FTM_FMS_FAULTF0_MASK_U32));
        }
        else
        {
            /*do nothing*/
        }

        /*Write Fault configuration registers*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_FLTCTRL_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegFctrl);
        /*Write Fault Polarity registers*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_FLTPOL_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegFltpol);        
#endif

        /*write FTMn_SC register to disable clock */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_SC_ADDR32(u8HwModuleId), FTM_SC_CLKS_MASK_U32);
                
        /*write FTMn_COMBINE register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_COMBINE_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegCombine | FTM_COMBINE_SYNCEN3_MASK_U32 | FTM_COMBINE_SYNCEN2_MASK_U32 | FTM_COMBINE_SYNCEN1_MASK_U32 | FTM_COMBINE_SYNCEN0_MASK_U32);
      
        u32TempDeadtimeVal = pFtmModuleConfig->u32RegDeadtime;

#if(defined IPV_FTM)
#if (IPV_FTM != IPV_FTM_05_00_04_00)
        u32TempDeadtimeVal = u32TempDeadtimeVal & ((uint32) (FTM_DEADTIME_DTPS_MASK_U32 | FTM_DEADTIME_DTVAL_MASK_U32));
#endif
#endif
        /*write FTMn_DEADTIME register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_DEADTIME_ADDR32(u8HwModuleId), u32TempDeadtimeVal);
        
        /*write FTMn_INVCTRL register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_INVCTRL_ADDR32(u8HwModuleId),  (uint32)0U); 

#if (PWM_DUTYCYCLE_UPDATED_ENDPERIOD == STD_ON)
        /* Check if update middle period is set */
        if (((uint32)0U) != (((uint32) (pFtmModuleConfig->u8RegSync)) & FTM_SYNC_CNTMIN_MASK_U32))
        {
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_CNTMIN_MASK_U32);
        }
        else
        {
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_CNTMIN_MASK_U32);
        }   
       
        if (((uint32)0U) != (((uint32) (pFtmModuleConfig->u8RegSync)) & FTM_SYNC_CNTMAX_MASK_U32))
        {
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_CNTMAX_MASK_U32);
        }
        else
        {
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_CNTMAX_MASK_U32);
        }
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SYNCONF_ADDR32(u8HwModuleId), FTM_SYNCONF_SYNCMODE_MASK_U32 | FTM_SYNCONF_SWWRBUF_MASK_U32);
#else 
        /* Clear update period */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_RMW32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_CNTMIN_MASK_U32|FTM_SYNC_CNTMAX_MASK_U32,(uint32)0U);
        
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SYNCONF_ADDR32(u8HwModuleId), FTM_SYNCONF_SYNCMODE_MASK_U32 | FTM_SYNCONF_SWWRBUF_MASK_U32|FTM_SYNCONF_SWRSTCNT_MASK_U32);
#endif        

        /* Loop all Ftm channels and perform Init actions for channels beloging to a given module*/
        for (u8CurChannel = ((uint8)0U); u8CurChannel < u8NumChannels; u8CurChannel++)
        {
            /* Get pointer to configuration of Ftm channel */
            pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8CurChannel];

            /*get current hw module Id*/
            u8InternalModuleId = ((Pwm_Ftm_ModuleType)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT));
            
            /*check if the current hw channel belongs to the current hardware FTM module */
            if (u8InternalModuleId == u8HwModuleId)
            {           
                
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))    
                /*update the duty cycle value for each channels in the global array*/
                Pwm_Ftm_au16ChannelDuty[u8CurChannel] = pFtmChannelConfig->u16PwmDefaultDutyCycle;   
#endif    
    
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) ||\
     (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON ))
                /* store polarity of current channel in a global array*/
                eChannelPolarity[u8CurChannel] = pFtmChannelConfig->ePwmPolarity;
#endif

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_DE_INIT_API == STD_ON))
                /* store polarity of current channel in a global array*/
                eChannelIdleState[u8CurChannel] = pFtmChannelConfig->ePwmIdleState;
#endif
                /*get current hw channel Id*/
                u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);
                
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */  
                REG_BIT_CLEAR32(FTM_OUTMASK_ADDR32(u8ModuleId),(uint32)((uint32)1U<<u8HwChannel));
                
 #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)               
                /*disable match compare interrupts for each channel*/
                Pwm_FtmInternal_DisableCmpIrq(u8HwModuleId, u8HwChannel);
#endif        
                /*read Channel configuration register*/
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                u32TempCscVal = REG_READ32(FTM_CSC_ADDR32(u8HwModuleId, (uint8)u8HwChannel));

                /*Set channel configuration Bits: MSB:MSA to 1:1 -> this means that all PWM waveforms types are accepted:*/
                /*Set ELSB bits*/
                u32TempCscVal |= (FTM_CSC_MSB_MASK_U32 | FTM_CSC_MSA_MASK_U32 | FTM_CSC_ELSB_MASK_U32);

                /*clear ELSA bit for non-inverted PWM*/
                u32TempCscVal &= ~(FTM_CSC_ELSA_MASK_U32);
                
                /*get the default period value */
                u16RegPeriodVal = pFtmModuleConfig->u16RegModVal;
                
                /*get default duty value*/
                u16Duty = pFtmChannelConfig->u16PwmDefaultDutyCycle;
                
                /*write FTMn_CSC register*/
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                REG_WRITE32(FTM_CSC_ADDR32(u8HwModuleId,(uint8)u8HwChannel), u32TempCscVal);

                /*get edge alignment*/
                eAlignment = pFtmChannelConfig->eAlingnment;

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))                
                Pwm_FtmInternal_SetSwOutputControl(u8HwModuleId, u8HwChannel,  PWM_LOW, eAlignment, (boolean)FALSE);   
#endif
                Pwm_Ftm_au8ChannelState[u8CurChannel] = PWM_CHANNEL_RUNNING; 
#endif
#if  (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) 
                Pwm_Ftm_au8PreviosChannelState[u8CurChannel] = PWM_CHANNEL_IDLE;
#endif           
    
                /*get edge polarity*/
                ePolarity = pFtmChannelConfig->ePwmPolarity;
                            
                /*for channels in combined mode - polarity of master channel  */
                if (PWM_LOW == ePolarity)
                {
                    /*set POLx bit for inverted PWM*/
                    u32TempPolVal |= (((uint32)1U) << u8HwChannel);
                }                
    
                /*for channels in combined mode - POLxy bits of the two channels must be inverted from their "configured" value */
                if ((PWM_COMBINE_SYNCED == eAlignment) || (PWM_COMBINE_COMPL == eAlignment))
                {
                    /* Get polarity bit of current channel */
                    u32CombBitsPolVal = u32TempPolVal & (uint32)((uint32)1U << u8HwChannel);
                    
                    /* Duplicate polarity bit for odd channel*/
                    u32CombBitsPolVal |= u32CombBitsPolVal << 1U;
                    
                    /* Invert 2 Corresponding bits with 2 combine channels*/
                    /*u32CombBitsPolVal = (~u32CombBitsPolVal) & (uint32)((uint32)3U<<u8HwChannel);*/ 
                    
                    /* Write above 2 bits into u32TempPolVal value */
                    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_10 cast from pointer to pointer */
                    REG_RMW32(&u32TempPolVal, (uint32)((uint32)3U << u8HwChannel),u32CombBitsPolVal);
                    
                    /*write C(n+1)SC register*/
                    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                    /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                    REG_WRITE32(FTM_CSC_ADDR32(u8HwModuleId, (uint8)(u8HwChannel+(uint8)1)), u32TempCscVal);
                }
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
                if ((PWM_PHASE_SHIFT_SINGLE == eAlignment) || (PWM_PHASE_SHIFTED_SYNCED == eAlignment)  || (PWM_PHASE_SHIFTED_COMPLEMENTARY == eAlignment))
                {
                    /* write phase shift value into Cn Val*/
                    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                    REG_WRITE32(FTM_CV_ADDR32(u8HwModuleId, u8HwChannel), (uint32)pFtmChannelConfig->u16PhaseShiftValue);
                    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
                    /* Turn on corresponding bit with phase shifted channel*/
                    Pwm_Ftm_aIsPhaseShiftChannel[u8ModuleId] |= (uint8)((uint32)1U << u8HwChannel);
#endif
                    
                    /* Configure Pol(n+1) bit with the same value with Pol(n) */
                    u32CombBitsPolVal = (uint32)((u32TempPolVal & (uint32)((uint32)1U << u8HwChannel)) << 1U);
                    
                    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                    /*@violates @ref Pwm_Ftm_C_REF_10 cast from pointer to pointer */
                    REG_RMW32(&u32TempPolVal, (uint32)((uint32)1U << ((uint32)u8HwChannel +1U)), u32CombBitsPolVal);

                    /*write C(n+1)SC register*/
                    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                    /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                    /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                    REG_WRITE32(FTM_CSC_ADDR32(u8HwModuleId, (uint8)(u8HwChannel+(uint8)1)), u32TempCscVal);
                }
#endif

                Pwm_FtmInternal_CalculatePeriod(u8HwModuleId, u16RegPeriodVal, eAlignment);
                
                 /*setup the default duty cycle value for all channels*/
                Pwm_FtmInternal_SetDutyRegs (
                                            u8HwModuleId, 
                                            u8HwChannel,  
                                            u16Duty, 
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
                                            pFtmChannelConfig->u16PhaseShiftValue,
#endif
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
                                            PWM_UPDATE_ASYNCHRONOUS,
#endif
                                            eAlignment
                                            );
            }
        }
        
        /*write FTMn_POL register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_POL_ADDR32(u8HwModuleId),  u32TempPolVal);
        
         /*write FTMn_CNTIN register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_CNTIN_ADDR32(u8HwModuleId), (uint32)0U);
                       
        /*write FTMn_MOD register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_MOD_ADDR32(u8HwModuleId), (uint32)(Pwm_Ftm_au16Period[u8HwModuleId]));

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
        /* OUTMASK register is upadted with the value of its buffer only by the PWM synchronization */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_SYNCHOM_MASK_U32);
        /* The software trigger activates the OUTMASK register synchronization */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SYNCONF_ADDR32(u8HwModuleId), FTM_SYNCONF_SWOM_MASK_U32);
#elif ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
        
        /* OUTMASK register is upadted with the value of its buffer only by the PWM synchronization */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SYNC_ADDR32(u8HwModuleId), FTM_SYNC_SYNCHOM_MASK_U32);
        /* The software trigger activates the OUTMASK register synchronization */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SYNCONF_ADDR32(u8HwModuleId), FTM_SYNCONF_SWOM_MASK_U32);    
#endif
#endif
        
        /*write FTMEN bit to disable buffer-to-registry not-syncronized transfers*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_FTMEN_MASK_U32 | FTM_MODE_PWMSYNC_ENABLE_U32);
#ifdef PWM_FTM_ENABLE_EXT_TRIGGERS
#if (PWM_FTM_ENABLE_EXT_TRIGGERS == STD_ON)         
        /*write FTM_EXTTRIG*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_EXTTRIG_ADDR32(u8HwModuleId),  pFtmModuleConfig->u32RegExtTrigg);
#endif       
#endif       
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_WRITE32(FTM_SC_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegSc);
    }
}


/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief            This function deinitializes the driver.
* @details          This function will set to idle state all Ftm channels. Will stop all
*                   Ftm submodules.
*                   Disables all Ftm interrupts and CTU triggering.
*
* @param[in]        pFtmIpConfig  Pointer to Ftm channels configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_DeInit
(   
    CONSTP2CONST(Pwm_Ftm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;
 
    /* Pointer to Ftm Module configuration */
    P2CONST(Pwm_Ftm_ModuleConfigType,    AUTOMATIC, PWM_APPL_CONST) pFtmModuleConfig = NULL_PTR;

    
    /* Id of Ftm Module this channel belongs to */
    VAR(Pwm_Ftm_ModuleType,   AUTOMATIC) u8ModuleId; 
    
    /*total number of used modules*/
    VAR(Pwm_Ftm_ModuleType,   AUTOMATIC) u8NumModules;
    
    /* Id of Ftm Module this channel belongs to */
    VAR(Pwm_Ftm_ModuleType,   AUTOMATIC) u8HwModuleId;

    /*number of used for each module*/
    VAR(Pwm_Ftm_ChannelType,  AUTOMATIC) u8NumChannels;

    /*index value of the current channel*/
    VAR(Pwm_Ftm_ChannelType,  AUTOMATIC) u8CurChannel;

    /*channel idle state*/
    VAR(Pwm_OutputStateType,  AUTOMATIC) eIdleState;

    /*calculated edge alignment for current module*/
    VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;
 
    /*index value of the current Hw channel*/
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC) u8HwChannel;

    /*Get number of channels used for the current Ftm module*/
    u8NumChannels = pFtmIpConfig->nNumChannels;
    
    /* Loop all Ftm channels and perform deInit actions */
    for (u8CurChannel = ((uint8)0U); u8CurChannel < u8NumChannels; u8CurChannel++)
    {
       /* Get pointer to configuration of Ftm channel */
       pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8CurChannel];

       /*get current hw channel Id*/
       u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

       /*get current hw module Id*/
       u8ModuleId = (((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

       /*get stored Idle state of current channel*/
        eIdleState = eChannelIdleState[u8CurChannel];
       
       /*get edge alignment*/
       eAlignment = pFtmChannelConfig->eAlingnment;
       
       
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)       
       /*disable match compare interrupts for each channel*/
       Pwm_FtmInternal_DisableCmpIrq(u8ModuleId, u8HwChannel);
#endif
       

      /*set current channel channels to IDLE*/
      Pwm_FtmInternal_SetSwOutputControl( u8ModuleId, u8HwChannel,  eIdleState, eAlignment, (boolean)TRUE );

      
      /* Clear SWSYNC bit - has to be cleared to generate SW trigger */
      /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
      /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
      REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8ModuleId),FTM_SYNC_SWSYNC_MASK_U32); 
      
      /* OUTMASK register is upadted with the value of its buffer only by the PWM synchronization */
      /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
      /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
      REG_BIT_SET32(FTM_SYNC_ADDR32(u8ModuleId),FTM_SYNC_SYNCHOM_MASK_U32);
      
      /* The software trigger activates the OUTMASK register synchronization */
      /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
      /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
      REG_BIT_SET32(FTM_SYNCONF_ADDR32(u8ModuleId),FTM_SYNCONF_SWOM_MASK_U32);
     
      /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
      /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */    
      REG_BIT_CLEAR32(FTM_OUTMASK_ADDR32(u8ModuleId),(uint32)((uint32)1U<<u8HwChannel));
     
      /* Create a sofware synchronous event */
      /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
      /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */            
      REG_BIT_SET32(FTM_SYNC_ADDR32(u8ModuleId), FTM_SYNC_SWSYNC_MASK_U32);

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
      Pwm_Ftm_au8ChannelState[u8CurChannel] = PWM_CHANNEL_IDLE;
#endif
      
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))        
      Pwm_Ftm_au16ChannelDuty[u8CurChannel] =  ((uint16)0U);     
#endif
   }
   
    /*Get number of modules used for the current Ftm module*/
    u8NumModules = pFtmIpConfig->nNumModules;

    /*de-initialize registers for all used modules*/
    for (u8ModuleId =  ((uint8)0U);  u8ModuleId < u8NumModules;  u8ModuleId++)
    {

        /*Get pointer to configuration data of the Ftm module*/
        pFtmModuleConfig = &(*pFtmIpConfig->pModulesConfig)[u8ModuleId];

        /*get FTM Hw module Index*/
        u8HwModuleId = pFtmModuleConfig->u8FtmHwModuleId;
        
#if (PWM_FAULT_SUPPORTED == STD_ON)    
        /*write FTMn_MODE register*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_MODE_ADDR32(u8HwModuleId), FTM_MODE_FAULTIE_MASK_U32);


        /*read fault bits*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        if (((uint32)0) != REG_BIT_GET32(FTM_FMS_ADDR32(u8HwModuleId), (FTM_FMS_FAULTF_MASK_U32 | FTM_FMS_FAULTF3_MASK_U32 | FTM_FMS_FAULTF2_MASK_U32 | FTM_FMS_FAULTF1_MASK_U32 | FTM_FMS_FAULTF0_MASK_U32)))
        {
              /* Clear Fault interrupt flags */
              /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
              /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
               REG_BIT_CLEAR32(FTM_FMS_ADDR32(u8HwModuleId), (FTM_FMS_FAULTF_MASK_U32 | FTM_FMS_FAULTF3_MASK_U32 | FTM_FMS_FAULTF2_MASK_U32 | FTM_FMS_FAULTF1_MASK_U32 | FTM_FMS_FAULTF0_MASK_U32));
        }
        else
        {
            /*do nothing*/
        }
#endif

#if (PWM_SELECT_COMMON_TIMEBASE_API == STD_ON)
        /* Clear Global Time Base Enable and Global Time Base Output bits */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_CONF_ADDR32(u8HwModuleId), (FTM_CONF_BDMMODE_MASK_U32 | FTM_CONF_GTBEOUT_MASK_U32 | FTM_CONF_GTBEEN_MASK_U32));
#else
        /* Clear BDMMODE bits */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_CONF_ADDR32(u8HwModuleId), FTM_CONF_BDMMODE_MASK_U32);
#endif
        /*write FTMn_SC register to disable clock */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_CLEAR32(FTM_SC_ADDR32(u8HwModuleId), FTM_SC_CLKS_MASK_U32);
    }
}
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))

/**
* @brief            This function sets the dutycycle and period for the specified Pwm channel.
* @details          If the period is set to zero the setting of the u16Duty-cycle is not relevant.
*                   In this case the output shall be zero (zero percent u16Duty-cycle).
*
* @param[in]        u8IdxChannelConfig   Ftm channel id
* @param[in]        nPeriod              Pwm signal period value
* @param[in]        u16DutyCycle         Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        eSyncUpdate          Load immediately or stay in buffer
* @param[in]        pFtmIpConfig         Pointer to Ftm channels configuration structure
*
* @return           void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_SetPeriodAndDuty
(
    VAR         (uint8,                     AUTOMATIC)                  u8IdxChannelConfig,
    VAR         (Pwm_PeriodType,            AUTOMATIC)                  nPeriod,
    VAR         (uint16,                    AUTOMATIC)                  u16DutyCycle,
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    VAR         (Pwm_DataUdateType,         AUTOMATIC)                  eSyncUpdate,
#endif
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*calculated edge alignment for current module*/
    VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;


    /*index value of the current Hw channel*/
    VAR(Pwm_Ftm_ChannelType,          AUTOMATIC) u8HwChannel;
    
    /*temporary value to store duty*/
    VAR(uint16,                    AUTOMATIC)    u16TempDutyCycle = u16DutyCycle;

    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;
    
    if( ((uint16)0U) == nPeriod)
    {
        u16TempDutyCycle =  ((uint16)0U);
    }
    else
    {
        /*do nothing*/
    }       
 
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();
    
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
     
    if(PWM_CHANNEL_IDLE == Pwm_Ftm_au8ChannelState[u8IdxChannelConfig])
    {
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)) 
        /*setup the idle value for all channels*/
        Pwm_FtmInternal_SetSwOutputControl(u8ModuleId, u8HwChannel,  PWM_LOW, eAlignment, (boolean)FALSE);          
#endif
        Pwm_Ftm_au8ChannelState[u8IdxChannelConfig] = PWM_CHANNEL_RUNNING;

#if  (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) 
         Pwm_Ftm_au8PreviosChannelState[u8IdxChannelConfig] = PWM_CHANNEL_IDLE;
#endif
    } 
#endif  

    /*calculate new period for each FTM module based on the alignement of the module*/
    Pwm_FtmInternal_CalculatePeriod(u8ModuleId, nPeriod, eAlignment);
        
    /*write FTMn_MOD register*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_WRITE32(FTM_MOD_ADDR32(u8ModuleId), (uint32)(Pwm_Ftm_au16Period[u8ModuleId]));

    /*setup the duty cycle value for all channels*/
    Pwm_FtmInternal_SetDutyRegs(
                                u8ModuleId, 
                                u8HwChannel, 
                                u16TempDutyCycle, 
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
                                pFtmChannelConfig->u16PhaseShiftValue,
#endif
                                
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
                                eSyncUpdate,
#endif
                                eAlignment
                                );
    
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))    
    /*update the duty cycle value for current channels in the global array*/
    Pwm_Ftm_au16ChannelDuty[u8IdxChannelConfig] = u16TempDutyCycle;   
#endif

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();
}

#endif /* (PWM_SET_PERIOD_AND_DUTY_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) */

#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            This function sets the dutycycle for the specified Pwm channel.
*
* @param[in]        u8IdxChannelConfig   Ftm channel id
* @param[in]        u16DutyCycle         Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        eSyncUpdate         Load immediately or stay in buffer
* @param[in]        pFtmIpConfig        Pointer to Ftm channels configuration structure
*
* @return           void
*
*
* @note This IP function will always be available because it is called by Pwm_Init()
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_SetDutyCycle
(
    VAR         (uint8,                     AUTOMATIC)                  u8IdxChannelConfig,
    VAR         (uint16,                    AUTOMATIC)                  u16DutyCycle,
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
    VAR         (Pwm_DataUdateType,         AUTOMATIC)                  eSyncUpdate,
#endif
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*calculated edge alignment for current module*/
     VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;

    /*index value of the current Hw channel*/
    VAR    (Pwm_Ftm_ChannelType,          AUTOMATIC) u8HwChannel;  
    
    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01();
    
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
   
    if(PWM_CHANNEL_IDLE == Pwm_Ftm_au8ChannelState[u8IdxChannelConfig])
    {
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))
        /*setup the idle value for all channels*/
        Pwm_FtmInternal_SetSwOutputControl(u8ModuleId, u8HwChannel,  PWM_LOW, eAlignment, (boolean)FALSE);
#endif
        Pwm_Ftm_au8ChannelState[u8IdxChannelConfig] = PWM_CHANNEL_RUNNING;
        
#if  (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) 
         Pwm_Ftm_au8PreviosChannelState[u8IdxChannelConfig] = PWM_CHANNEL_IDLE;
#endif
    } 
#endif    

    /*setup the duty cycle value for all channels*/
    Pwm_FtmInternal_SetDutyRegs(
                                u8ModuleId, 
                                u8HwChannel, 
                                u16DutyCycle, 
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
                                pFtmChannelConfig->u16PhaseShiftValue,
#endif
                                
#if ((PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) || (PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON))
                                eSyncUpdate,
#endif
                                eAlignment
                                ); 
    
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))    
    /*update the duty cycle value for current channels in the global array*/
    Pwm_Ftm_au16ChannelDuty[u8IdxChannelConfig] = u16DutyCycle;   
#endif

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01();
}

#endif /* (PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON) */

/*===============================================================================================*/
#if(PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief            This function sets the generated pwm signal to the idle value configured.
* @details          If the polarity and the idle state are the same the signal is set to HIGH.
*                   In a critical section PWM generator parameters are updated, then notifications
*                   for this channel are disabled,
*                   the output trigger bits are cleared and output control bits are cleared.
*
* @param[in]        u8IdxChannelConfig   Ftm Channel Id in the configuration
* @param[in]        pFtmIpConfig   Pointer to Ftm channels configuration structure
*
*
* @return           void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_SetOutputToIdle
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*channel idle state*/
    VAR(Pwm_OutputStateType,   AUTOMATIC) eIdleState;

    /*calculated edge alignment for current module*/
     VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;

    /*index value of the current Hw channel*/
    VAR    (Pwm_Ftm_ChannelType,          AUTOMATIC) u8HwChannel;

    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);


    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

    /*get channel idle state*/
    eIdleState = eChannelIdleState[u8IdxChannelConfig];

    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02();
    
    /*set channel to idle is channel is in running mode*/ 
    if (PWM_CHANNEL_RUNNING == Pwm_Ftm_au8ChannelState[u8IdxChannelConfig])
    {

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)  
    
#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
        /* Notify that given FTM module enable TOF interrupt to check fault */
        Pwm_Ftm_aNotifToChannelMap[((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)u8ModuleId) + u8HwChannel] 
        |= PWM_TOF_IRQ_FAULT_IDLE_STATE;
        /* TOF is enable for related faut errata */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        REG_BIT_SET32(FTM_SC_ADDR32(u8ModuleId), FTM_SC_TOIE_MASK_U32);
#endif
#endif
        /*disable match compare interrupts for each channel*/
        Pwm_FtmInternal_DisableCmpIrq(u8ModuleId, u8HwChannel);
#endif    
    
        /*setup the idle value for all channels*/
        Pwm_FtmInternal_SetSwOutputControl( u8ModuleId, u8HwChannel,  eIdleState, eAlignment, (boolean)TRUE);

#if  (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) 
         Pwm_Ftm_au8PreviosChannelState[u8IdxChannelConfig] = PWM_CHANNEL_IDLE;
#endif
        Pwm_Ftm_au8ChannelState[u8IdxChannelConfig] = PWM_CHANNEL_IDLE;       

#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))        
        Pwm_Ftm_au16ChannelDuty[u8IdxChannelConfig] = PWM_FTM_DUTY_0;    
#endif        
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02();
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API*/


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This function disables the user notifications
* @details          This function disables the user notifications
*
* @param[in]        u8IdxChannelConfig   Ftm Channel Id in the configuration
* @param[in]        pFtmIpConfig   Pointer to Ftm channels configuration structure
*
* @return           void
*
*/

FUNC (void, PWM_CODE) Pwm_Ftm_DisableNotification
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{
    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*index value of the current Hw channel*/
    VAR    (Pwm_Ftm_ChannelType,   AUTOMATIC) u8HwChannel;

    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

    Pwm_Ftm_aNotifToChannelMap[((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)u8ModuleId) + u8HwChannel] = PWM_NO_EDGE;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03();
    
    /*disable match compare interrupts for each channel*/
    Pwm_FtmInternal_DisableCmpIrq(u8ModuleId, u8HwChannel);
    
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    
    /* disable interrupt for phase shifted channel */
    if (0U != (Pwm_Ftm_aIsPhaseShiftChannel[u8ModuleId] & (uint8)((uint32)1U << u8HwChannel)))
    {    
        Pwm_Ftm_aNotifToChannelMap[((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)u8ModuleId) + u8HwChannel + (uint8)1U] = PWM_NO_EDGE;
        
        Pwm_FtmInternal_DisableCmpIrq(u8ModuleId, u8HwChannel + (uint8)1U);
    }
#endif
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03();

}


/*===============================================================================================*/
/**
* @brief            This function enables the user notifications
* @details          This function enables the user notifications
*
* @param[in]        u8IdxChannelConfig  Ftm Channel Id in the configuration
* @param[in]        eNotification       Notification type
* @param[in]        pFtmIpConfig    Pointer to Ftm channels configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_EnableNotification
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{
    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*channel polarity*/
    VAR(Pwm_OutputStateType,   AUTOMATIC) ePolarity;

    /*index value of the current Hw channel*/
    VAR    (Pwm_Ftm_ChannelType,   AUTOMATIC) u8HwChannel;

    /*number of used for each module*/
    VAR    (Pwm_Ftm_ChannelType,          AUTOMATIC) u8ChannelsModOffset;
    
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    /*calculated edge alignment for current module*/
    VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;
#endif

    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;    
#endif
    
    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

    /*get stored Polarity of current channel*/
    ePolarity = eChannelPolarity[u8IdxChannelConfig];
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04();
    
    /* Clear CHnF bit */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, (uint8)u8HwChannel), FTM_CSC_CHF_MASK_U32);
    
    /* Clear TOF bit */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8ModuleId), FTM_SC_TOF_MASK_U32);
    
    u8ChannelsModOffset = ((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)u8ModuleId) + u8HwChannel;   
    /* Clear notification type bit field */
    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] &= (uint8)(~(uint32)(PWM_CHF_IRQ_EDGE|PWM_TOF_IRQ_EDGE));
    
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    /* Clear notification type bit field for (channel + 1) */
    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset + 1U] &= (uint8)(~(uint32)(PWM_CHF_IRQ_EDGE|PWM_TOF_IRQ_EDGE));
    
    if((PWM_PHASE_SHIFTED_COMPLEMENTARY == eAlignment) || (PWM_PHASE_SHIFTED_SYNCED == eAlignment) || (PWM_PHASE_SHIFT_SINGLE == eAlignment))
    {
        
        /* Clear CH(n+1)F bit */
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
        /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
        REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, (uint8)(u8HwChannel + (uint8)1U)), FTM_CSC_CHF_MASK_U32);
    
        switch(eNotification)
        {
            case PWM_BOTH_EDGES:
            {           
                Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_CHF_IRQ_EDGE;
                Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset + 1U] |= PWM_CHF_IRQ_EDGE;            
            }break;
    
            case PWM_RISING_EDGE:
            {
                if (PWM_HIGH == ePolarity)
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_CHF_IRQ_EDGE;
                }
                else
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset + 1U] |= PWM_CHF_IRQ_EDGE;
                }
            }break;
    
            default:
            {
                if (PWM_LOW == ePolarity)
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset + 1U] |= PWM_CHF_IRQ_EDGE;
                }
                else
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_CHF_IRQ_EDGE;
                }
            }break;
        }  
    }
    else
    {
#endif
        switch(eNotification)
        {
            case PWM_BOTH_EDGES:
            {           
                Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_TOF_IRQ_EDGE | PWM_CHF_IRQ_EDGE;            
            }break;
    
            case PWM_RISING_EDGE:
            {
                if (PWM_HIGH == ePolarity)
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_TOF_IRQ_EDGE;
                }
                else
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_CHF_IRQ_EDGE;
                }
            }break;
    
            default:
            {
                if (PWM_LOW == ePolarity)
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_TOF_IRQ_EDGE;
                }
                else
                {
                    Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_CHF_IRQ_EDGE;
                }
            }break;
        }
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
    }    
#endif

    /*if duty is not 0% or 100%*/
    if (((uint16)0U) != (Pwm_Ftm_au16ChannelDuty[u8IdxChannelConfig] & PWM_FTM_UPPER_LIMIT_DUTY_MASK))
    {
        /*TOIE is requested*/
        if(PWM_TOF_IRQ_EDGE == (Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] & PWM_TOF_IRQ_EDGE))     
        {
                /* enable TOIE interrupt */
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                REG_BIT_SET32(FTM_SC_ADDR32(u8ModuleId), FTM_SC_TOIE_MASK_U32);
        }
        else
        {
                /*do nothing*/
        }
        
        /*if combined mode is used*/
        if(PWM_CHF_IRQ_EDGE == (Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] & PWM_CHF_IRQ_EDGE)) 
        {
            /*enable interrupts for the given channel*/
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleId,(uint8)u8HwChannel), FTM_CSC_CHIE_MASK_U32);
        }
        else
        {
                /*disable interrupts for the given channel*/
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
                REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId,(uint8)u8HwChannel), FTM_CSC_CHIE_MASK_U32);
        }
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        /* If Phase shifted mode is used then the n+1 channnel will generate interrupt*/
        if((PWM_PHASE_SHIFTED_COMPLEMENTARY == eAlignment) || (PWM_PHASE_SHIFTED_SYNCED == eAlignment) || (PWM_PHASE_SHIFT_SINGLE == eAlignment))
        {
            if(PWM_CHF_IRQ_EDGE == (Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset + 1U] & PWM_CHF_IRQ_EDGE)) 
            {
                /*enable interrupts for the given channel*/
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleId, (uint8)(u8HwChannel + (uint8)1U)), FTM_CSC_CHIE_MASK_U32);
            }
            else
            {
                /*disable interrupts for the given channel*/
                /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
                /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
                REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId, (uint8)(u8HwChannel + (uint8)1U)), FTM_CSC_CHIE_MASK_U32);
            }
        }
#endif
    }
    else
    {
        
        /*disable match compare interrupts for each channel*/
        Pwm_FtmInternal_DisableCmpIrq(u8ModuleId, u8HwChannel);
        /* Duty is in limited state */
        Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] |= PWM_TOF_IRQ_NO_EDGE_NOTIF;
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04();
}
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */


/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief            This function read the dutycycle value from the array Pwm_Ftm_au16ChannelDuty[] and returns this value.
*
* @param[in]        u8IdxChannelConfig      pwm channel id
* @param[in]        pFtmIpConfig            Pointer to Ftm channels configuration structure
*
* @return           uint16
*
*
*
*/
FUNC(uint16, PWM_CODE) Pwm_Ftm_GetChannelState
( 
    VAR         (uint8,                     AUTOMATIC)             u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{      
    VAR(uint16,   AUTOMATIC) u16Duty;

    /* Avoid compiler warning*/
    (void)pFtmIpConfig;
    
    u16Duty = Pwm_Ftm_au16ChannelDuty[u8IdxChannelConfig];    
    
    return u16Duty;
}
#endif /* PWM_GET_CHANNEL_STATE_API */



#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief            Ftm low level get output state function used to get the current state of the output pwm pin
* @param[in]        u8IdxChannelConfig       Pwm channel id
* @param[in]        pFtmIpConfig            Pointer to Ftm channels configuration structure
*
* @return           Pwm_OutputStateType     pwm signal output logic value
*
* @retval PWM_LOW   The output pin is in LOW logic level
* @retval PWM_HIGH  The output pin is in HIGH logic level
*/

FUNC (Pwm_OutputStateType, PWM_CODE) Pwm_Ftm_GetOutputState
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)     pFtmIpConfig
)
{
   /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR(Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*index value of the current Hw channel*/
    VAR(Pwm_Ftm_ChannelType,   AUTOMATIC) u8HwChannel;
    
    /*calculated edge alignment for current module*/
    VAR(Pwm_OutputStateType,  AUTOMATIC) eOutputVal = PWM_LOW;
    
    VAR(uint32, AUTOMATIC) u32Temp1;
    
    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);

    /* Reading FTM_CnSC_CHOV bit */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u32Temp1 = REG_BIT_GET32(FTM_CSC_ADDR32(u8ModuleId, u8HwChannel), FTM_CSC_CHOV_MASK_U32);

    if ((uint32)0U != u32Temp1)
    {
        eOutputVal = PWM_HIGH;
    }
    else
    {
        eOutputVal = PWM_LOW;
    }

    return eOutputVal;
}

#endif /*PWM_GET_OUTPUT_STATE_API*/

/*==================================================================================================*/
#if (PWM_SYNC_UPDATE_API == STD_ON)
/**
* @brief            This function updates the dutycycle and-or period for the specified Pwm channel.
*                   buffer register. The value written does not take effect until calling
*                   SynchUpdate API.
*                   
*
* @param[in]        u8HwModule             Ftm module id.
*
* @return           void
*
*/
FUNC(void, PWM_CODE) Pwm_Ftm_SyncUpdate
( 
    VAR(uint8,              AUTOMATIC) u8HwModule
)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08();
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */        
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_SET32(FTM_SYNC_ADDR32(u8HwModule), FTM_SYNC_SWSYNC_MASK_U32);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08();
}
#endif /* PWM_SYNC_UPDATE_API */



#if (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON)
/**
* @brief            Ftm low level function used to set the output to LOW or HIGH
* @details          Ftm low level function used to  set output state of a pin depending on the value of bForce
*                   parameter.
*
* @param[in]        u8IdxChannelConfig      Pwm channel id
* @param[in]        bForce                  Expected new state of the output pin
* @param[in]        pFtmIpConfig            Pointer to Ftm channels configuration structure
*
* @return           void
*
* @implements     Pwm_Ftm_ForceOutputToZero_Activity
*/

FUNC(void, PWM_CODE) Pwm_Ftm_ForceOutputToZero
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (boolean,                   AUTOMATIC)                 bForce,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId;

    /*channel polarity*/
    VAR(Pwm_OutputStateType,   AUTOMATIC) ePolarity;

    /*calculated edge alignment for current module*/
    VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;

    /*default duty value*/
    VAR(Pwm_OutputStateType, AUTOMATIC) nFtmOutputLevel = (Pwm_OutputStateType)PWM_LOW; 


    /*index value of the current Hw channel*/
    VAR(Pwm_Ftm_ChannelType,          AUTOMATIC) u8HwChannel;

    /*current state of the Hw channel*/
    VAR(boolean,          AUTOMATIC) bOutputEnable;

    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];


    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);


    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);


    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;

    /*get stored Polarity of current channel*/
    ePolarity = eChannelPolarity[u8IdxChannelConfig];

    
    /*calculate duty value depending on the value of the polarity and expected output state */
    /*if polarity is HIGH then Output level should be LOW otherwise output level should be HIGH*/
    /*else duty is set to 0%*/
    nFtmOutputLevel = (Pwm_OutputStateType)((uint8)ePolarity ^ (uint8)PWM_HIGH);
    
    bOutputEnable = bForce;
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05();
    
    /*get the previos state of the channel current channel state is not FORCED OUTPUT*/
    if (PWM_CHANNEL_OUTPUT_FORCED !=  Pwm_Ftm_au8ChannelState[u8IdxChannelConfig])
    { 

        Pwm_Ftm_au8PreviosChannelState[u8IdxChannelConfig] =  Pwm_Ftm_au8ChannelState[u8IdxChannelConfig];
         
        /*if Forced output was requested */
        if ((boolean)TRUE == bForce)
        {
            Pwm_Ftm_au8ChannelState[u8IdxChannelConfig] = PWM_CHANNEL_OUTPUT_FORCED;       
            
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)  
            /*disable match compare interrupts for each channel*/
            Pwm_FtmInternal_DisableCmpIrq(u8ModuleId, u8HwChannel);
#endif       
        }
    }
    else
    {
        /*if resume normal operation was requested */
        if ((boolean)FALSE == bForce)
        {
            Pwm_Ftm_au8ChannelState[u8IdxChannelConfig] = Pwm_Ftm_au8PreviosChannelState[u8IdxChannelConfig];
       
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)          
           /*disable match compare interrupts for each channel*/
           /*disable match compare interrupts for each channel*/
           if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * u8ModuleId) + u8HwChannel])
               & PWM_TOF_IRQ_EDGE))
           {
               /* enable TOIE interrupt */
               /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
               /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
               REG_BIT_SET32(FTM_SC_ADDR32(u8ModuleId), FTM_SC_TOIE_MASK_U32);
           }
            
           if(PWM_NO_EDGE != ((Pwm_Ftm_aNotifToChannelMap[((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * u8ModuleId) + u8HwChannel])
               & PWM_CHF_IRQ_EDGE))
           {
               /*enable interrupts for the given channel*/
               /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
               /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
               /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
               REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleId,(uint8)u8HwChannel), FTM_CSC_CHIE_MASK_U32);
           } 
#endif
        
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) 
           if(PWM_CHANNEL_IDLE == Pwm_Ftm_au8ChannelState[u8IdxChannelConfig])
           {
                /*get channel idle state*/
                nFtmOutputLevel = eChannelIdleState[u8IdxChannelConfig];
    
                bOutputEnable = (boolean)TRUE;
           } 
#endif
        }    
    }    

    /*enable or disable forced output*/
    Pwm_FtmInternal_SetSwOutputControl(u8ModuleId, u8HwChannel,  (Pwm_OutputStateType)nFtmOutputLevel, eAlignment, bOutputEnable);
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05();
}
#endif


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            This function is a interrupt service routine used to proccess compare events for each Ftm module
* @details          This function will call notification functions configured. If a null pointer
*                   was configured, an error will be reported.
*
* @param[in]        u8FtmChannel - Ftm Channel
*
* @return           void
*
* @implements       Pwm_Ftm_ProcessCommonInterrupt_Activity
*/
/*@violates @ref Pwm_Ftm_C_REF_8 cast from unsigned int to pointer */
FUNC(void,PWM_CODE) Pwm_Ftm_ProcessCommonInterrupt
(
    CONST(uint8, AUTOMATIC) u8FtmChannel
)
{
   VAR   (Pwm_Ftm_ModuleType, AUTOMATIC) u8ChannelId;
   VAR   (Pwm_Ftm_ModuleType, AUTOMATIC) u8ModuleId;
   VAR    (uint32,            AUTOMATIC) u32ChfStatus;
   VAR    (uint32,            AUTOMATIC) u32ChieStatus;
   VAR   (Pwm_Ftm_EdgeStateType,    AUTOMATIC) u8EdgeState;    
   VAR    (Pwm_Ftm_ChannelType,     AUTOMATIC) u8ChannelsModOffset;
   
   /*get module Id for current Hw channel and the channel index*/
   u8ChannelId =   ((u8FtmChannel) & FTM_CH_MASK_U8);
   u8ModuleId  =   (((u8FtmChannel) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);


    /*get Channel flag status*/
   /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
   /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
   /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u32ChieStatus = ((REG_READ32(FTM_CSC_ADDR32(u8ModuleId,(uint8)u8ChannelId))) & FTM_CSC_CHIE_ENABLE_U32);

    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    u32ChfStatus = ((REG_READ32(FTM_CSC_ADDR32(u8ModuleId,(uint8)u8ChannelId))) & FTM_CSC_CHF_MASK_U32);

    /*clear CHF bit*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_11 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleId,(uint8)u8ChannelId), FTM_CSC_CHF_MASK_U32);

    u8ChannelsModOffset = ((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)u8ModuleId) + u8ChannelId;
    
    u8EdgeState = ((Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset]) & PWM_CHF_IRQ_EDGE);

    if((((uint32)0U)!= u32ChieStatus) && (((uint32)0U)  != u32ChfStatus) && (PWM_NO_EDGE != u8EdgeState))
    {
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        if (0U != (Pwm_Ftm_aIsPhaseShiftChannel[u8ModuleId] & (uint8)((uint32)1U << (u8ChannelId - (uint8)1U))))
        {
            /* Channel in phase shifted mode, if this is odd channel, assign notification to even channel*/
            Pwm_Ipw_FtmChannelNotification(u8ChannelsModOffset - (uint8)1U );
        }
        else
        {
#endif
            Pwm_Ipw_FtmChannelNotification(u8ChannelsModOffset);
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
        }
#endif
    }
}



/**
* @brief            This function is a interrupt service routine used to proccess timer overflow events for a FTM module
* @details          This function will call notification functions configured. If a null pointer
*                   was configured, an error will be reported.
*
* @param[in]        u8FtmModule - Ftm Module
*
* @return           void
*
* @implements       Pwm_Ftm_ProcessTofInterrupt_Activity
*/
/*@violates @ref Pwm_Ftm_C_REF_8 cast from unsigned int to pointer */
FUNC(void,PWM_CODE) Pwm_Ftm_ProcessTofInterrupt
(
    CONST(uint8, AUTOMATIC) u8FtmModule
)
{
    VAR   (uint32,  AUTOMATIC) u32TofStatus;
    VAR   (uint32,  AUTOMATIC) u32ToieStatus;
    VAR   (uint8,   AUTOMATIC) u8ChannelId;
    VAR   (Pwm_Ftm_EdgeStateType,    AUTOMATIC) u8EdgeState;
    VAR   (Pwm_Ftm_EdgeStateType,    AUTOMATIC) u8NoTofEdgeState;
    VAR    (Pwm_Ftm_ChannelType,     AUTOMATIC) u8ChannelsModOffset;

#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
    VAR     (uint8,                 AUTOMATIC) nFaultCheckEnable = ((uint8) 0U);
    VAR     (uint32,                AUTOMATIC) u32TempRegVal;
#endif
#endif
    
    /*get TOF and TOIE status bit*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u32ToieStatus = (REG_READ32(FTM_SC_ADDR32(u8FtmModule))) & FTM_SC_TOIE_ENABLE_U32;
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u32TofStatus  = (REG_READ32(FTM_SC_ADDR32(u8FtmModule))) & FTM_SC_TOF_OVF_U32;


    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8FtmModule), FTM_SC_TOF_MASK_U32);
    
       
    if ((((uint32)0U) != u32TofStatus) && (((uint32)0U)  != u32ToieStatus))
    {
        for (u8ChannelId = ((uint8)0U); u8ChannelId < PWM_FTM_MODULE_CHANNELS_NO; u8ChannelId++)
        {
            u8ChannelsModOffset = ((Pwm_Ftm_ChannelType)PWM_FTM_MODULE_CHANNELS_NO * (Pwm_Ftm_ChannelType)u8FtmModule) + u8ChannelId;
            
#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
            /* Check if there are any channel in given module using TOF notification to check fault */
            if (PWM_NO_EDGE != (Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset] & PWM_TOF_IRQ_FAULT_IDLE_STATE))
            {
                nFaultCheckEnable = ((uint8) 1U);
            }
#endif
#endif

#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
            /* Only non-PhaseShifted channel is assigned notification */
            if (0U == (Pwm_Ftm_aIsPhaseShiftChannel[u8FtmModule] & (uint8)((uint32)1U << u8ChannelId)))
            {
#endif                
                u8EdgeState = ((Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset]) & PWM_TOF_IRQ_EDGE);
    
                u8NoTofEdgeState =  ((Pwm_Ftm_aNotifToChannelMap[u8ChannelsModOffset]) & PWM_TOF_IRQ_NO_EDGE_NOTIF);   
                
                if((PWM_NO_EDGE != u8EdgeState) && (PWM_NO_EDGE == u8NoTofEdgeState))
                {
                    Pwm_Ipw_FtmChannelNotification(u8ChannelsModOffset);
                }
#if (PWM_ENABLE_PHASE_SHIFT == STD_ON)
            }
#endif
        }
    }
    else
    {
       /*do nothing*/
    }

#if ((defined ERR_IPV_FTM_0002) && (PWM_FAULT_SUPPORTED == STD_ON))
#if (ERR_IPV_FTM_0002 == STD_ON)
    /* If no fault detected */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    if (((uint32) 0U) == REG_BIT_GET32(FTM_FMS_ADDR32(u8FtmModule), FTM_FMS_FAULTF_MASK_U32))
    {
        /* Check if the last notification detected a fault */
        if ((((uint8) 0U) != nFaultCheckEnable) && (((uint8) 0U) != (Pwm_Ftm_u8FaultCheck & ((uint8)((uint32) 1U << u8FtmModule)))))
        {
            /* Clear detect */
            Pwm_Ftm_u8FaultCheck &= (uint8)(~((uint32)((uint32) 1U << u8FtmModule)));
            
            /* Clear SWSYNC */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8FtmModule), FTM_SYNC_SWSYNC_MASK_U32);
            
            /* Clear the FTM_SWOCTRL by writing all zeroes to it then write FTM_SWOCTRL with the desired value again. */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            u32TempRegVal = (REG_READ32(FTM_SWOCTRL_ADDR32(u8FtmModule)));
            
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_SWOCTRL_ADDR32(u8FtmModule), ((uint32) 0U));
            
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_SWOCTRL_ADDR32(u8FtmModule), u32TempRegVal);
            
            /* Clear the FTM_OUTMASK bits that were set in last notification */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            u32TempRegVal = (REG_READ32(FTM_OUTMASK_ADDR32(u8FtmModule)));
            
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            u32TempRegVal &= ~(REG_READ32(FTM_SWOCTRL_ADDR32(u8FtmModule)));
            
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_OUTMASK_ADDR32(u8FtmModule), u32TempRegVal);
            
            /* Set SWSYNC to synchronize */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_SYNC_ADDR32(u8FtmModule), FTM_SYNC_SWSYNC_MASK_U32);
        }
    }
#endif
#endif
}


#endif /* (PWM_NOTIFICATION_SUPPORTED */



/*===============================================================================================*/
#if (PWM_FAULT_SUPPORTED == STD_ON)
/**
* @brief            This function is a interrupt service routine used to proccess faults for each Ftm submodule
* @details          This function will call fault notification functions configured. If a null pointer
*                   was configured, an error will be reported.
*
* @param[in]        u8FaultChannel - Ftm Fault Channel
*
* @return           void
*
* @implements       Pwm_Ftm_ProcessFaultInterrupt_Activity
*/
/*@violates @ref Pwm_Ftm_C_REF_8 cast from unsigned int to pointer */
FUNC(void,PWM_CODE) Pwm_Ftm_ProcessFaultInterrupt
(
    CONST(uint8, AUTOMATIC) u8FaultChannelId
)
{

   /*get module Id for current Hw hannel and the channel index*/
    VAR   (Pwm_Ftm_ModuleType,          AUTOMATIC) u8FaultChannel = ((uint8)0U);
    VAR   (Pwm_Ftm_ModuleType,          AUTOMATIC) u8ModuleId =   (((u8FaultChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);
    VAR    (Pwm_Ftm_FaultNotifyType,    AUTOMATIC) pfFaultNotify;
    VAR    (uint32,                 AUTOMATIC) u32FaultStatus;
    P2CONST(Pwm_Ftm_IpConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig;    
#ifdef ERR_IPV_FTM_0002    
#if (ERR_IPV_FTM_0002 == STD_ON)
    VAR     (uint8,                 AUTOMATIC) u8ChannelId;
    VAR     (Pwm_Ftm_ChannelType,   AUTOMATIC) nFtmFirstChannelId;
    VAR     (uint8,                 AUTOMATIC) nFaultCheckEnable = ((uint8) 0U);
    VAR     (uint32,                AUTOMATIC) u32TempRegVal;
    
    nFtmFirstChannelId = ((Pwm_Ftm_ChannelType) PWM_FTM_MODULE_CHANNELS_NO) * (Pwm_Ftm_ChannelType)u8ModuleId;
#endif
#endif

    /*get FAULTF  bit and each possible Fault Channel Flag*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u32FaultStatus = (REG_READ32(FTM_FMS_ADDR32(u8ModuleId))) & (FTM_FMS_FAULTF_FAULT_U32 | FTM_FMS_FAULTF0_FAULT_U32 | FTM_FMS_FAULTF1_FAULT_U32 | FTM_FMS_FAULTF2_FAULT_U32 | FTM_FMS_FAULTF3_FAULT_U32);
    
#ifdef ERR_IPV_FTM_0002
#if (ERR_IPV_FTM_0002 == STD_ON)
    /* Check if there are any channel in given module using TOF notification to check fault */
    for (u8ChannelId = ((uint8)0U); u8ChannelId < PWM_FTM_MODULE_CHANNELS_NO; u8ChannelId++)
    {
        if (PWM_NO_EDGE != (Pwm_Ftm_aNotifToChannelMap[nFtmFirstChannelId + u8ChannelId] & PWM_TOF_IRQ_FAULT_IDLE_STATE))
        {
            nFaultCheckEnable = ((uint8) 1U);
        }
    }
    
    /* If fault detected */
    if (((uint32) 0) != (u32FaultStatus & FTM_FMS_FAULTF_FAULT_U32))
    {
        /* Check if there are any channels using TOF notification to check fault and first time detected*/
        if ((((uint8) 0U) != nFaultCheckEnable) && (((uint8) 0U) == (Pwm_Ftm_u8FaultCheck & (uint8)((uint32) 1U << u8ModuleId))))
        {
            /* Mark as detected */
            Pwm_Ftm_u8FaultCheck |= (uint8)((uint32) 1U << u8ModuleId);
            
            /* Clear SWSYNC */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8ModuleId), FTM_SYNC_SWSYNC_MASK_U32);
            
            /* Write the FTM_OUTMASK register to set the bit or bits corresponding to any channels that
                are controlled by FTM_SWOCTRL to temporarily inactivate the channel output. */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            u32TempRegVal = (REG_READ32(FTM_SWOCTRL_ADDR32(u8ModuleId)) & (FTM_SWOCTRL_CH7OC_MASK_U32|FTM_SWOCTRL_CH6OC_MASK_U32|FTM_SWOCTRL_CH5OC_MASK_U32|FTM_SWOCTRL_CH4OC_MASK_U32|FTM_SWOCTRL_CH3OC_MASK_U32|FTM_SWOCTRL_CH2OC_MASK_U32|FTM_SWOCTRL_CH1OC_MASK_U32|FTM_SWOCTRL_CH0OC_MASK_U32));
            
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            u32TempRegVal |= REG_READ32(FTM_OUTMASK_ADDR32(u8ModuleId));
            
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_OUTMASK_ADDR32(u8ModuleId), u32TempRegVal); 

            /* Set SWSYNC to synchronize */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_SYNC_ADDR32(u8ModuleId), FTM_SYNC_SWSYNC_MASK_U32);
        }
    }
#endif
#endif

    /* Get pointer to Ftm Ip configuration */
    pFtmIpConfig = Pwm_Ipw_GetFtmIpConfigPtr();
    /* If FTM IP is configured, loop through all fault channels and call
    the notification handler */
    if(NULL_PTR != pFtmIpConfig)
    {
        /*loop all fault channels*/
        while(u8FaultChannel < PWM_FTM_MODULE_FAULT_NO)
        {
            /* Check current status of fault channels */
            if(((uint32)0U) != (u32FaultStatus & (uint32)FTM_FMS_FAULTF0_FAULT_U32))
            {
                /* Get the configured notification handler pointer */
                pfFaultNotify = (*pFtmIpConfig->pModulesConfig)[u8ModuleId].pfFaultNotification[u8FaultChannel];
                /* Call notification if pointer not NULL */
                if(NULL_PTR != pfFaultNotify)
                {
                    pfFaultNotify(u8ModuleId, u8FaultChannel);
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                    /* Do nothing */
            }

            /* Get next channel's status bitfield */
            u32FaultStatus >>= ((uint32)1U);

            /* Pass to next fault channel */
            u8FaultChannel++;             
        }
    }
    else
    {
        /*do nothing*/
    }

    /*get FAULTF  bit and each possible Fault Channel Flag*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    u32FaultStatus = REG_READ32(FTM_FMS_ADDR32(u8ModuleId));

    /*clear FAULTF bit*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_CLEAR32(FTM_FMS_ADDR32(u8ModuleId), FTM_FMS_FAULTF_MASK_U32);

}
#endif /* (PWM_NOTIFICATION_SUPPORTED */



#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        This function sets the value of the prescaler on all FTM modules
* @details      This function sets the  prescaler depending on the value ePrescaler parameter. 
*               - ePrescaler value is either PWM_PRIMARY_PRESCALER or PWM_ALTERNATIVE_PRESCALER
*               - the values associated to either types are configured by tooling and the phisical values 
                  associated are written to hardware registry.
*
* @param[in]    ePrescaler - prescaler logical values selectable between PWM_PRIMARY_PRESCALER or PWM_ALTERNATIVE_PRESCALER
* @param[in]    pFtmIpConfig  - Pointer to configuration structure of Ftm channels
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_SetClockMode
(
    VAR         (Pwm_PrescalerType,        AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{
  
    VAR   (Pwm_Ftm_ModuleType, AUTOMATIC) u8ModuleIndex;
    VAR   (Pwm_Ftm_ModuleType, AUTOMATIC) u8HwModuleId;
    /*total number of used modules*/
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC) u8NumModules;
    /* Pointer to Ftm Module configuration */
    P2CONST(Pwm_Ftm_ModuleConfigType,    AUTOMATIC, PWM_APPL_CONST) pFtmModuleConfig = NULL_PTR;
        
   /*Get number of modules used for the current Ftm module*/
    u8NumModules = pFtmIpConfig->nNumModules;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06();
    
    /*initialize registry for all used modules*/
    for (u8ModuleIndex =  ((uint8)0U);  u8ModuleIndex < u8NumModules;  u8ModuleIndex++)
    {
        /*Get pointer to configuration data of the Ftm module*/
        pFtmModuleConfig  = &(*pFtmIpConfig->pModulesConfig)[u8ModuleIndex];
        u8HwModuleId      = pFtmModuleConfig->u8FtmHwModuleId;
               
        if (PWM_ALTERNATIVE_PRESCALER == ePrescaler)
        {
            /*write FTMn_SC register to set prescaler and start clock */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_SC_ADDR32(u8HwModuleId), pFtmModuleConfig->u32AlternateRegSc);
        }
        else 
        {
            /*write FTMn_SC register to set prescaler and start clock */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_SC_ADDR32(u8HwModuleId), pFtmModuleConfig->u32RegSc);          
        }  
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06();
}
#endif /*PWM_SET_CLOCK_MODE_API */

#if (PWM_SELECT_COMMON_TIMEBASE_API == STD_ON)
/**
* @brief        This function synchronises the timebase for a selection of FTM modules
*
* @details      Sets the module to provide the common timebase then the modules that use that
*               timebase. While this is done the timers are stopped, then they are restarted
*               in order to be synchronized
*
* @param[in]    u8FtmModule - module that sets the common timebase by setting the GTBEOUT bit
* @param[in]    u16ElementSyncList  - 16 bit variable that has, from right to left, the bits
*                                     for each module to have the same timebase as u8FtmModule
*
* @return       void
*/
FUNC(void, PWM_CODE) Pwm_Ftm_SelectCommonTimebase
(
    VAR (uint8,                 AUTOMATIC)         u8FtmModule,
    VAR (uint16,                AUTOMATIC)         u16ElementSyncList
)
{
    VAR (uint32, AUTOMATIC) u8SyncModuleIndex;
    VAR (uint32, AUTOMATIC) u8FtmClkConfig[PWM_HW_MODULES_CFG_U8];
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07();
    
    for(u8SyncModuleIndex = 0U; u8SyncModuleIndex < PWM_HW_MODULES_CFG_U8; u8SyncModuleIndex++)
    {
        /*get index value for modules that need to be synchronized*/
        if ((uint8)((uint8)u16ElementSyncList & (uint8)(1U << u8SyncModuleIndex)) == (uint8)(1U << u8SyncModuleIndex))
        {
            /* save used clock source */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            u8FtmClkConfig[u8SyncModuleIndex] = REG_READ32(FTM_SC_ADDR32(u8SyncModuleIndex)) & FTM_SC_CLKS_SYS_CLOCK_U32;
            
            /* stop clock */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_CLEAR32(FTM_SC_ADDR32(u8SyncModuleIndex), FTM_SC_CLKS_MASK_U32);
            
            /* clear counter register */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_WRITE32(FTM_CNT_ADDR32(u8SyncModuleIndex), 0U);
            
            /* set sync bit for the driven modules */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_SET32(FTM_CONF_ADDR32(u8SyncModuleIndex), FTM_CONF_GTBEEN_MASK_U32);
            
            /* start clock again */
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_RMW32(FTM_SC_ADDR32(u8SyncModuleIndex), FTM_SC_CLKS_MASK_U32, u8FtmClkConfig[u8SyncModuleIndex]);
        }
    }
    
    /* set global sync bit for the source module */
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_BIT_SET32(FTM_CONF_ADDR32(u8FtmModule), FTM_CONF_GTBEOUT_MASK_U32);
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07();
}
#endif  /* PWM_SELECT_COMMON_TIMEBASE_API */

/*===============================================================================================*/
#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
/**
* @brief        This function set phase shift value and also force duty cycle to 50%
*
* @details      In order to have Phase-Shifted Full-Bridge controller, Pwm_SetPhaseShift is introduced.
*               This function bases on FTM Combine mode with Cn and C(n+1) combine to generate leading 
*               edge and trailing edge. Pwm_SetPhaseShift allows to set both phase shift value and period,
*               the duty value is fixed to 50%.
* @param[in]    u8IdxChannelConfig -    Ftm Channel Id in the configuration
* @param[in]    u16Period               Pwm signal period value
* @param[in]    u16PhaseShift           Phase shift value
* @param[in]    pFtmIpConfig            Pointer to Ftm channels configuration structure
* @param[in]    bLoad                   Buffer value be loaded or not, TRUE -> load.
*
* @return       void
*/
FUNC (void, PWM_CODE) Pwm_Ftm_SetPhaseShift
(
    VAR         (uint8,                     AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (uint16,                    AUTOMATIC)                 u16Period,
    VAR         (uint16,                    AUTOMATIC)                 u16PhaseShift,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)     pFtmIpConfig,
    VAR         (boolean,                   AUTOMATIC)                 bLoad
)
{

    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig = NULL_PTR;

    /* Id of Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,                          AUTOMATIC) u8ModuleId;

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))
    /*calculated edge alignment for current module*/
    VAR(Pwm_AlignmentType,                               AUTOMATIC) eAlignment;
#endif

    /*index value of the current Hw channel*/
    VAR    (Pwm_Ftm_ChannelType,                         AUTOMATIC) u8HwChannel;  

    /* Store calculated duty*/
    VAR(uint16,                                          AUTOMATIC) u16RegDutyVal;
    
    /* Store calculated Phase shift*/
    VAR(uint16,                                          AUTOMATIC) u16RegShiftVal;
    
    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get current hw channel Id*/
    u8HwChannel = ((pFtmChannelConfig->nHwChannelId) & FTM_CH_MASK_U8);

    /*get current hw module Id*/
    u8ModuleId = (uint8)(((pFtmChannelConfig->nHwChannelId) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT);
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))
    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;
#endif
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09();
    

#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) || (PWM_POWER_STATE_SUPPORTED == STD_ON))
    if(PWM_CHANNEL_IDLE == Pwm_Ftm_au8ChannelState[u8IdxChannelConfig])
    {
#if ((PWM_SET_OUTPUT_TO_IDLE_API == STD_ON) || (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON))
        /*setup the idle value for all channels*/
        Pwm_FtmInternal_SetSwOutputControl(u8ModuleId, u8HwChannel,  PWM_LOW, eAlignment, (boolean)FALSE);
#endif
        Pwm_Ftm_au8ChannelState[u8IdxChannelConfig] = PWM_CHANNEL_RUNNING;
        
#if  (PWM_FORCE_OUTPUT_TO_ZERO_API == STD_ON) 
         Pwm_Ftm_au8PreviosChannelState[u8IdxChannelConfig] = PWM_CHANNEL_IDLE;
#endif
    } 
#endif    

    if(0U == u16Period)
    {
        Pwm_Ftm_au16Period[u8ModuleId] = u16Period ;
    } 
    else
    {
        Pwm_Ftm_au16Period[u8ModuleId] = (u16Period - ((uint16)1U));
    }

    /*write FTMn_MOD register*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */ 
    REG_WRITE32(FTM_MOD_ADDR32(u8ModuleId), (uint32)(Pwm_Ftm_au16Period[u8ModuleId]));
    
    /* Calculate and write CnV, which handles phase shift value. The duty is fixed at 50%*/
    u16RegShiftVal = (uint16)((((uint32)Pwm_Ftm_au16Period[u8ModuleId] * (uint32)u16PhaseShift) >> ((uint32)15U)) + (uint32)1);
     
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */   
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */    
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleId, u8HwChannel), (uint32)u16RegShiftVal);
    
    /*Fix duty to 50%*/
    u16RegDutyVal = (uint16)((uint32)Pwm_Ftm_au16Period[u8ModuleId]  >> 1U);
  
    /*Write C(n+1)V register*/
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
    /*@violates @ref Pwm_Ftm_C_REF_7 access to 32 bit register using 8 bit channel */
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
    REG_WRITE32(FTM_CV_ADDR32(u8ModuleId, (u8HwChannel + ((uint8)1U))), (uint32)(u16RegShiftVal + u16RegDutyVal));
    
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */ 
    if((boolean)TRUE == bLoad)
    {    
        /* The reason that we use SWSYNC instead of LDOK is SWSYNC allow sellect
          the loading point to update, end of period or immediately update, by configuration PwmDutycycleUpdatedEndperiod*/
        /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */   
        /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */ 
        REG_BIT_SET32(FTM_SYNC_ADDR32(u8ModuleId), FTM_SYNC_SWSYNC_MASK_U32);
    }
    
#if ((PWM_GET_CHANNEL_STATE_API == STD_ON) || (PWM_NOTIFICATION_SUPPORTED == STD_ON))    

    /*update duty cycle value 50%*/
    Pwm_Ftm_au16ChannelDuty[u8IdxChannelConfig] = (uint16)0x4000U;   
#endif    

    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09();
 
}

#endif /* PWM_SET_PHASE_SHIFT_API  */
/*==============================================================================================*/
#if (PWM_ENABLE_TRIGEER_API == STD_ON)
/**
* @brief        This function enable trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*       Bit 0   Channel 2 Trigger Enable
*       Bit 1   Channel 3 Trigger Enable
*       Bit 2   Channel 4 Trigger Enable
*       Bit 3   Channel 5 Trigger Enable
*       Bit 4   Channel 0 Trigger Enable
*       Bit 5   Channel 1 Trigger Enable
*       Bit 6   Initialization Trigger Enable
*       Bit 8   Channel 6 Trigger Enable
*       Bit 9   Channel 7 Trigger Enable
*
* @param[in]    u8TriggerHostId - FTM module
* @param[in]    u16TriggerMask - bit mask will be clear for FTM_EXTTRIG. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_EnableTrigger 
(
    VAR(uint8, AUTOMATIC)              u8TriggerHostId,
    VAR(uint16,AUTOMATIC)              u16TriggerMask
)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_10();
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */ 
    REG_BIT_SET32(FTM_EXTTRIG_ADDR32(u8TriggerHostId),(uint32)u16TriggerMask);
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_10();
}
#endif /*#if (PWM_ENABLE_TRIGEER_API == STD_ON)*/

#if (PWM_DISABLE_TRIGEER_API == STD_ON)
/**
* @brief        This function disable trigger generation for specific source
* @details      Corresponding bits with trigger source as bellow:
*       Bit 0   Channel 2 Trigger Enable
*       Bit 1   Channel 3 Trigger Enable
*       Bit 2   Channel 4 Trigger Enable
*       Bit 3   Channel 5 Trigger Enable
*       Bit 4   Channel 0 Trigger Enable
*       Bit 5   Channel 1 Trigger Enable
*       Bit 6   Initialization Trigger Enable
*       Bit 8   Channel 6 Trigger Enable
*       Bit 9   Channel 7 Trigger Enable
*
* @param[in]    u8TriggerHostId - FTM module
* @param[in]    u16TriggerMask - bit mask will be cleared for FTM_EXTTRIG. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_DisableTrigger 
(
    VAR(uint8, AUTOMATIC)              u8TriggerHostId,
    VAR(uint16,AUTOMATIC)              u16TriggerMask
)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_11();
    /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
    /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */  
    REG_BIT_CLEAR32(FTM_EXTTRIG_ADDR32(u8TriggerHostId),(uint32)u16TriggerMask);
    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_11();
}
#endif /*PWM_DISABLE_TRIGEER_API*/





#if (PWM_RESET_COUNTER_API == STD_ON)
/**
* @brief          This function enables counter reset by Pwm_SyncUpdate() call
* @details
*
*
* @param[in]     u8ModuleId - FTM module
*
* @return         void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_ResetCounterEnable
(
     VAR(uint8, AUTOMATIC) u8ModuleId
)
{
     /* The software trigger activates the FTM counter synchronization */
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
     REG_BIT_SET32(FTM_SYNCONF_ADDR32(u8ModuleId),FTM_SYNCONF_SWRSTCNT_MASK_U32);
}

/**
* @brief          This function disabled counter reset by Pwm_SyncUpdate() call
* @details
*
*
* @param[in]     u8ModuleId - FTM module
*
* @return         void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_ResetCounterDisable
(
     VAR(uint8, AUTOMATIC) u8ModuleId
)
{
     /* The software trigger does not activate the FTM counter synchronization */
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
     REG_BIT_CLEAR32(FTM_SYNCONF_ADDR32(u8ModuleId),FTM_SYNCONF_SWRSTCNT_MASK_U32);
}
#endif /*PWM_RESET_COUNTER_API*/

#if (PWM_ENABLE_MASKING_OPERATIONS == STD_ON)
/**
* @brief        This function force channels output to their inactive state
* @details      Corresponding bits with channel will be masked:
*       Bit 0   Channel 0 Output Mask
*       Bit 1   Channel 1 Output Mask
*       Bit 2   Channel 2 Output Mask
*       Bit 3   Channel 3 Output Mask
*       Bit 4   Channel 4 Output Mask
*       Bit 5   Channel 5 Output Mask
*       Bit 6   Channel 6 Output Mask
*       Bit 7   Channel 7 Output Mask
*
* @param[in]    u8ModuleId - FTM module
* @param[in]    u8ChannelMask - bit mask will be set for FTM_OUTMASK. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_MaskOutputs 
(
    VAR(uint8 , AUTOMATIC)      u8ModuleId,
    VAR(uint8 , AUTOMATIC)     u8ChannelMask
)
{
     SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_12();
     
     /* Both code lines below could be probably moved somewhere to Pwm_Ftm_Init() */
     /* Clear SWSYNC bit - has to be cleared to generate SW trigger */
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */ 
     REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8ModuleId),FTM_SYNC_SWSYNC_MASK_U32); 
     
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */ 
     REG_BIT_SET32(FTM_OUTMASK_ADDR32(u8ModuleId),(uint32)u8ChannelMask);
     
     /* Create a sofware synchronous event */
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */        
     REG_BIT_SET32(FTM_SYNC_ADDR32(u8ModuleId), FTM_SYNC_SWSYNC_MASK_U32);
     
     SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_12();
}

/**
* @brief        This function puts channels output to normal operation state
* @details      Corresponding bits with channel will be masked:
*       Bit 0   Channel 0 Output Mask
*       Bit 1   Channel 1 Output Mask
*       Bit 2   Channel 2 Output Mask
*       Bit 3   Channel 3 Output Mask
*       Bit 4   Channel 4 Output Mask
*       Bit 5   Channel 5 Output Mask
*       Bit 6   Channel 6 Output Mask
*       Bit 7   Channel 7 Output Mask
*
* @param[in]    u8ModuleId - FTM module
* @param[in]    u8ChannelMask - bit mask will be cleared for FTM_OUTMASK. 
*
* @return       void
*
*/
FUNC (void, PWM_CODE) Pwm_Ftm_UnMaskOutputs 
(
    VAR(uint8 , AUTOMATIC)      u8ModuleId,
    VAR(uint8 , AUTOMATIC)     u8ChannelMask
)
{
     SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_13();
     
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */    
     REG_BIT_CLEAR32(FTM_OUTMASK_ADDR32(u8ModuleId),(uint32)u8ChannelMask);

     /* Both code lines below could be probably moved somewhere to Pwm_Ftm_Init() */
     /* Clear SWSYNC bit - has to be cleared to generate SW trigger */
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */    
     REG_BIT_CLEAR32(FTM_SYNC_ADDR32(u8ModuleId),FTM_SYNC_SWSYNC_MASK_U32);
     
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */    
     REG_BIT_CLEAR32(FTM_OUTMASK_ADDR32(u8ModuleId),(uint32)u8ChannelMask);
     
     /* Create a sofware synchronous event */
     /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */  
     /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */            
     REG_BIT_SET32(FTM_SYNC_ADDR32(u8ModuleId), FTM_SYNC_SWSYNC_MASK_U32);
     
     SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_13();
}
#endif /*PWM_ENABLE_MASKING_OPERATIONS*/

#if (PWM_PARAM_CHECK == STD_ON)
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ftm_ValidateNotification
* @details          This function will check given channel with notification supported
*
* @param[in]        u8IdxChannelConfig  Ftm Channel Id in the configuration
* @param[in]        pFtmIpConfig  Pointer to Ftm channels configuration structure
* @param[out]       u8RetVal          E_NOT_OK            Notification handler is not valid
*/
/*@violates @ref Pwm_Ftm_C_REF_8 cast from unsigned int to pointer */
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ftm_ValidateNotification
(
    VAR         (uint8,                   AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
)
{
    VAR(Std_ReturnType, AUTOMATIC)                                  u8RetVal = (Std_ReturnType)E_OK;    
    
    /* Pointer to Ftm channel configuration */
    P2CONST(Pwm_Ftm_ChannelConfigType,   AUTOMATIC, PWM_APPL_CONST) pFtmChannelConfig;    
    
    VAR(Pwm_AlignmentType,  AUTOMATIC) eAlignment;
    
    /* Get pointer to configuration of Ftm channel */
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;    


    if (
        (PWM_CENTER_ALIGNED == eAlignment)
#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
        || (PWM_COMBINE_SYNCED == eAlignment)
        || (PWM_COMBINE_COMPL == eAlignment)
#endif
       )
    {
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    return u8RetVal;
}
#endif
/*===============================================================================================*/
#if( (PWM_SET_PHASE_SHIFT_API == STD_ON) || (PWM_SET_PHASE_SHIFT_NO_UPDATE_API == STD_ON))
/**
* @brief            Pwm_Ftm_ValidateChannelSetPhaseShift
* @details          This function will check given channel with Pwm_SetPhaseShift supported
*
* @param[in]        u8IdxChannelConfig  Ftm Channel Id in the configuration
* @param[in]        pFtmIpConfig  Pointer to Ftm channels configuration structure
* @param[out]       u8RetVal          E_NOT_OK  Pwm_SetPhaseShift is not supported this channel
*/
FUNC(uint8, PWM_CODE) Pwm_Ftm_ValidateChannelSetPhaseShift
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
(
    VAR         (uint8,                   AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
)
{
    /* Pwm channel Ftm specific parameters from config structure */
    P2CONST(Pwm_Ftm_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST)     pFtmChannelConfig;
    
    VAR(Std_ReturnType, AUTOMATIC)                                  u8RetVal = (Std_ReturnType)E_OK;   

    VAR(Pwm_AlignmentType,                              AUTOMATIC)  eAlignment;    
    
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;
    
    if ((PWM_COMBINE_SYNCED != eAlignment) && (PWM_COMBINE_COMPL != eAlignment))
    {
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return u8RetVal;
}
#endif
/*===============================================================================================*/
#if ((PWM_SET_PERIOD_AND_DUTY_NO_UPDATE_API == STD_ON) || (PWM_SET_DUTY_CYCLE_NO_UPDATE_API == STD_ON))
/**
* @brief            Pwm_Ftm_ValidateChannelSync
* @details          This function will check given channel with FTM Synchronization supported
*                   DutyCycle always updates immediately 
* @param[in]        u8IdxChannelConfig  Ftm Channel Id in the configuration
* @param[in]        pFtmIpConfig  Pointer to Ftm channels configuration structure
* @param[out]       u8RetVal          E_NOT_OK  FTM Synchronization is not supported this channel
*/
FUNC(uint8, PWM_CODE) Pwm_Ftm_ValidateChannelSync
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
(
    VAR         (uint8,                   AUTOMATIC)                    u8IdxChannelConfig,
    CONSTP2CONST(Pwm_Ftm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)      pFtmIpConfig
)
{
    /* Pwm channel Ftm specific parameters from config structure */
    P2CONST(Pwm_Ftm_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST)     pFtmChannelConfig;
    
    VAR(Std_ReturnType, AUTOMATIC)                                  u8RetVal = (Std_ReturnType)E_OK;      

    VAR(Pwm_AlignmentType,                              AUTOMATIC)  eAlignment;        
    
    pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    /*get edge alignment*/
    eAlignment = pFtmChannelConfig->eAlingnment;
    
    if ((PWM_PHASE_SHIFTED_SYNCED == eAlignment) || (PWM_PHASE_SHIFTED_COMPLEMENTARY == eAlignment))
    {
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return u8RetVal;
}
#endif

/*===============================================================================================*/
#if ((PWM_DISABLE_TRIGEER_API == STD_ON) || (PWM_ENABLE_TRIGEER_API == STD_ON))
/**
* @brief            This function will check bit mask.
* @details          Bis mask will be process at lower layer has to be compatible with  hardware register 
*
* @param[in]        u32TriggerMask    Trigger mask value
*
* @retVal           u8RetVal          E_NOT_OK  Bit mask is not compatible.
*/
FUNC(uint8, PWM_CODE) Pwm_Ftm_ValidateTriggerMask
/* @violates @ref Pwm_Ftm_C_REF_6 Identifier exceeds 31 chars. */
(
    VAR(uint32,                         AUTOMATIC) u32TriggerMask
)
{
    
    VAR(Std_ReturnType, AUTOMATIC)          u8RetVal = (Std_ReturnType)E_OK;      
    
    if  ((uint32)0U !=  (   
                            u32TriggerMask & 
                            (~(uint32)(FTM_EXTTRIG_CH0TRIG_MASK_U32|FTM_EXTTRIG_CH1TRIG_MASK_U32|FTM_EXTTRIG_CH2TRIG_MASK_U32|
                            FTM_EXTTRIG_CH3TRIG_MASK_U32|FTM_EXTTRIG_CH4TRIG_MASK_U32|FTM_EXTTRIG_CH5TRIG_MASK_U32|
                            FTM_EXTTRIG_CH6TRIG_MASK_U32|FTM_EXTTRIG_CH7TRIG_MASK_U32|FTM_EXTTRIG_INITTRIGEN_MASK_U32))
                        )
        )
        {
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }

    return u8RetVal;
}
#endif

#endif /*(PWM_PARAM_CHECK == STD_ON)*/
/**
* @brief            This function validate the state of pwm channel is idle or not, and the notification
*                   is enabled or not
*
* @param[in]        pStd_ReturnTypeIpConfig       Structure of FTM channels configuration
*
* @return           Std_ReturnType
*
*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ftm_ValidateIdleState
(
    P2CONST(Pwm_Ftm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pFtmIpConfig
)
{
    /* counter for loop FTM channels and */
    VAR(Pwm_Ftm_ChannelType, AUTOMATIC)                             u8channelid;
   /* store return value*/
    VAR(Std_ReturnType, AUTOMATIC)                                  nRetVal = (Std_ReturnType)E_OK;  
    /*  Avoid compiler warning */
    (void)pFtmIpConfig;

    /* loop all FTM channels, make sure there are not any channels in the different states than IDLE state */
    for (u8channelid = (uint8)0; u8channelid < (uint8)PWM_FTM_CHANNELS_MAX_U8; u8channelid++)
    {        
        if(PWM_CHANNEL_RUNNING == Pwm_Ftm_au8ChannelState[u8channelid])
        {
            nRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* loop all FTM channels, make sure there are not any channels which have notification enabled */
    for (u8channelid = (uint8)0; u8channelid < (uint8)PWM_FTM_CHANNELS_NO; u8channelid++)
    {    
#ifdef ERR_IPV_FTM_0002
#if (ERR_IPV_FTM_0002 == STD_ON)
        if (PWM_NO_EDGE != (Pwm_Ftm_aNotifToChannelMap[u8channelid] & (Pwm_Ftm_EdgeStateType)(~PWM_TOF_IRQ_FAULT_IDLE_STATE)))
#else
        if (PWM_NO_EDGE != Pwm_Ftm_aNotifToChannelMap[u8channelid])
#endif
#else
        if (PWM_NO_EDGE != Pwm_Ftm_aNotifToChannelMap[u8channelid])
#endif            
        {
            nRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
#endif
    return nRetVal;
}

/**
* @brief        Put pwm channel based on FTM to target power mode.
* @details      This function will disable clock if target power mode is Low power, and enable clock
*               if target power mode is full power
*               - nPowerState value is either PWM_LOW_POWER or PWM_FULL_POWER
*               - the values associated to either types are configured by tooling and the phisical values 
                  associated are written to hardware registry.
*
* @param[in]    nPowerState - target mode value selectable between PWM_LOW_POWER or PWM_FULL_POWER
* @param[in]    pFtmConfig  - Pointer to configuration structure of FTM channels
*                 
* @return         none
*
* @implements     Pwm_Ftm_SetPowerState_Activity
*/
FUNC(void, PWM_CODE) Pwm_Ftm_SetPowerState
(
    P2CONST(Pwm_Ftm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST)   pFtmIpConfig,
    VAR    (Pwm_PowerStateType,          AUTOMATIC)                 nPowerState
)
{
    /* Pointer to Ftm Module configuration */
    P2CONST(Pwm_Ftm_ModuleConfigType,    AUTOMATIC, PWM_APPL_CONST) pFtmModuleConfig;    
    /* Id of logic Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC)                 u8ModuleId;
    /* Id of hardware Ftm Module this channel belongs to */
    VAR    (Pwm_Ftm_ModuleType,          AUTOMATIC)                 u8HwModuleId;
    
    for (u8ModuleId = (uint8)0U;  u8ModuleId < (pFtmIpConfig->nNumModules);  u8ModuleId++)
    {
        /*Get pointer to configuration data of the Ftm module*/
        pFtmModuleConfig = &(*pFtmIpConfig->pModulesConfig)[u8ModuleId];
        /*get FTM Hw module Index*/
        u8HwModuleId = pFtmModuleConfig->u8FtmHwModuleId;
        if(PWM_LOW_POWER == nPowerState)
        {
            /*@violates @ref Pwm_Ftm_C_REF_2 cast from unsigned int to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_BIT_CLEAR32(FTM_SC_ADDR32(u8HwModuleId), FTM_SC_CLKS_MASK_U32);
        }
        else
        {
            /* @violates @ref Pwm_Ftm_C_REF_2 Cast from unsigned long to pointer */
            /*@violates @ref Pwm_Ftm_C_REF_9 cast from unsigned int to pointer */
            REG_RMW32(FTM_SC_ADDR32(u8HwModuleId), FTM_SC_CLKS_MASK_U32, pFtmModuleConfig->u32RegSc);
        }
    }
}
#endif
#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_Ftm_C_REF_1 Only preprocessor statements and comments before 'include'
*/
/*
* @violates @ref Pwm_Ftm_C_REF_3 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
