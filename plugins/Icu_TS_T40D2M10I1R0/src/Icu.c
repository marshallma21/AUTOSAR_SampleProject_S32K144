/**
 *     @file              Icu.c
 *     @implements        Icu_HLD_unit
 *     @version 1.0.1
 *
 *     @brief   AUTOSAR Icu - ICU Driver source file.
 *     @details ICU driver source file, containing the Autosar API specification and other variables
 *              and functions that are exported by the ICU driver.
 *
 *     @addtogroup ICU_MODULE
 *     @{
 */
/*==================================================================================================
 *     Project             : AUTOSAR 4.2 MCAL
 *     Platform            : ARM
 *     Peripheral          : FTM PORT_CI LPIT LPTMR
 *     Dependencies        : none
 *
 *     Autosar Version     : 4.2.2
 *     Autosar Revision    : ASR_REL_4_2_REV_0002
 *     Autosar ConfVariant :
 *     SWVersion           : 1.0.1
 *     BuildVersion        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
 *
 *     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
 *     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif
/**
 *     @file       Icu.c
 *     @implements Icu.c_Artifact
 * */
/**
 * @page misra_violations MISRA-C:2004 violations
 *
 * @section Icu_c_REF_1
 *          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
 *          before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
 *          is as  per Autosar  requirement MEMMAP003.
 *
 * @section Icu_c_REF_2
 *          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
 *          the contents of a header file being included twice
 *          This is not a violation since all header files are protected against multiple inclusions
 *
 * @section Icu_c_REF_3
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
 *          character significance and case sensitivity are supported for external identifiers.
 *          This is not a violation since all the compilers used interpret the identifiers correctly
 *
 * @section Icu_c_REF_4
 *          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
 *          of pointer arithmetic.
 *          The violation occurs because the variables are defined as per Autosar API specifications
 *
 * @section Icu_c_REF_5
 *          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
 *          Middle layer between AUTOSAR and hardware needs a way to map HLD
 *          functions to IP functions.
 *
 * @section Icu_c_REF_6
 *          Violates MISRA 2004 Required Rule 8.10, could be made static
 *          The respective code could not be made static because of layers architecture design of
 *          the driver.
 *
 * @section Icu_c_REF_7
 *          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
 *          pointer to a function and a type other than an integral type. This violation is due to
 *          the pointer arithmetic used to write/ read the data to/from the buffers
 *
 *@section Icu_c_REF_8
 *          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
 *          are only accessed from within a single function.
 *          These objects are used in various parts of the code
 *
 *@section Icu_c_REF_9
 *          Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer
 *          type shall not be implicitly converted to a different underlying type.
 *
 *@section Icu_c_REF_10
 *          Violates MISRA 2004 Required Rule 16.10, Ignore value is ignored as return value
 *          is always the same and the value itself is not needed.
 *
 * @section Icu_c_REF_11
 *          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
 *          and an integral type.
 *
 * @section [global]
 *          Violates MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely
 *          on the significance of more than 31 characters.The used compilers use more than 31 chars
 *          for identifiers.
 *
 */

/*==================================================================================================
 *                                          INCLUDE FILES
 *  1) system and project includes
 *  2) needed interfaces from external units
 *  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"

#include "Icu.h"
#include "Icu_EnvCfg.h"

#include "Icu_Ipw.h"
#include "SchM_Icu.h"
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#include "Icu_Irq.h"

/*==================================================================================================
*                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_VENDOR_ID_C                     43
#define ICU_AR_RELEASE_MAJOR_VERSION_C      4
#define ICU_AR_RELEASE_MINOR_VERSION_C      2
/*
 * @violates @ref Icu_c_REF_3 Identifier clash.
 */
#define ICU_AR_RELEASE_REVISION_VERSION_C   2
#define ICU_SW_MAJOR_VERSION_C              1
#define ICU_SW_MINOR_VERSION_C              0
#define ICU_SW_PATCH_VERSION_C              1

/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_VENDOR_ID)
    #error "Icu.c and Icu.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.c and Icu.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu.h are different"
#endif

/* Check if source file and Icu_EnvCfg header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_ENVCFG_VENDOR_ID)
    #error "Icu.c and Icu_EnvCfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same AutoSar version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.c and Icu_EnvCfg.h are different"
#endif
/* Check if source file and Icu_EnvCfg header file are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_ENVCFG_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_ENVCFG_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_ENVCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_EnvCfg.h are different"
#endif

/* Check if source file and ICU IPW header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
#error "Icu.c and Icu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw header file are of the same version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Icu.c and Icu_Ipw.h are different"
#endif
/* Check if source file and Icu_Ipw header file are of the same Software Version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_Ipw.h are different"
#endif

/* Check if source file and DET header file are of the same version */
#if (ICU_DEV_ERROR_DETECT == STD_ON)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((ICU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu.c and Det.h are different"
        #endif
    #endif
#endif /* ICU_DEV_ERROR_DETECT */

/* Check if source file and ICU IRQ header file are of the same vendor */
#if (ICU_VENDOR_ID_C != ICU_IRQ_VENDOR_ID)
    #error "Icu.c and Icu_Irq.h have different vendor IDs"
#endif
/* Check if source file and ICU IRQ header file are of the same version */
#if ((ICU_AR_RELEASE_MAJOR_VERSION_C != ICU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_AR_RELEASE_MINOR_VERSION_C != ICU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_AR_RELEASE_REVISION_VERSION_C != ICU_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu.c and Icu_Irq.h are different"
#endif
/* Check if source file and ICU IRQ header are of the same Software version */
#if ((ICU_SW_MAJOR_VERSION_C != ICU_IRQ_SW_MAJOR_VERSION) || \
     (ICU_SW_MINOR_VERSION_C != ICU_IRQ_SW_MINOR_VERSION) || \
     (ICU_SW_PATCH_VERSION_C != ICU_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu.c and Icu_Irq.h are different"
#endif

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON))

typedef enum
{
    ICU_STATE_UNINIT = 0x00,
    ICU_STATE_IDLE
} Icu_eGlobalStateType;

#endif /* ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)) */

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
/**
 * @brief      This function ends the validation of calling a function on a channel
 * @details    This service is a non reentrant function on channel used for ending the validation
 *                for the calls for functions that use one channel
 *
 * @param[in]   validation The function call was previously validated
 *
 * @return void
 *
 * @violates @ref Icu_c_REF_5  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 **/
#define Icu_EndValidateCallAndChannel(validation)

#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)*/

/*==================================================================================================
 *                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
 *                                        LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Icu_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of
*                a header file being included twice.
*/
#include "Icu_MemMap.h"

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON))

static VAR(Icu_eGlobalStateType, ICU_VAR) Icu_GlobalState = ICU_STATE_UNINIT;

#endif /* ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)) */

#define ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
 * @violates @ref Icu_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 * and comments before "#include"
 *
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Icu_c_REF_1 MISRA 2004 Required Rule 19.1 only preprocessor statements
*                and comments before "#include"
* @violates @ref Icu_c_REF_2 MISRA 2004 Advisory Rule 19.15 precautions to prevent the contents of
*                a header file being included twice.
*/
#include "Icu_MemMap.h"

#ifdef ICU_PRECOMPILE_SUPPORT
/* @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7 objects shall be
 *           defined at block scope */
extern CONST(Icu_ConfigType, ICU_CONST) Icu_PBCfgVariantPredefined;
#endif /*ICU_PRECOMPILE_SUPPORT*/

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Icu_c_REF_1 MISRA 2004 Required Rule 19.1 only preprocessor statements
*                and comments before "#include"
* @violates @ref Icu_c_REF_2 MISRA 2004 Advisory Rule 19.15 precautions to prevent the contents of
*                a header file being included twice.
*/
#include "Icu_MemMap.h"
/*==================================================================================================
 *                                        GLOBAL VARIABLES
==================================================================================================*/

#define ICU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Icu_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of
*                a header file being included twice.
*/
#include "Icu_MemMap.h"

/**
 * @brief Pointer initialized during init with the address of the received configuration structure.
 * @details Will be used by all functions to access the configuration data.
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 *
 * */
P2CONST(Icu_ConfigType, ICU_VAR, ICU_APPL_CONST) Icu_pCfgPtr = NULL_PTR;

#define ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
 * @violates @ref Icu_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 * and comments before "#include"
 *
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
 * @violates @ref Icu_c_REF_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 * and comments before "#include"
 *
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"

/**
 * @brief Saves the current Icu mode
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 *
 * @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be
 *           defined at block scope
 */
VAR(Icu_ModeType, ICU_VAR) Icu_CurrentMode;


/**
 * @brief   Stores actual state and configuration of ICU Channels
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
volatile VAR(Icu_ChannelStateType, ICU_VAR) Icu_aChannelState[ICU_MAX_CHANNEL];


#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief Pointer to the buffer-array where the timestamp values shall be placed.
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
 P2VAR(Icu_ValueType, ICU_VAR, ICU_APPL_DATA) Icu_aBuffer[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving the size of the external buffer (number of entries)
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
 VAR(Icu_IndexType, ICU_VAR) Icu_aBufferSize[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving Notification interval (number of events).
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
 VAR(Icu_IndexType, ICU_VAR) Icu_aBufferNotify[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving the number of notify counts
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
volatile  VAR(Icu_IndexType, ICU_VAR) Icu_aNotifyCount[ICU_MAX_CHANNEL];


/**
 * @brief Array for saving the time stamp index
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
volatile  VAR(Icu_IndexType, ICU_VAR) Icu_aBufferIndex[ICU_MAX_CHANNEL];

#endif /* ICU_TIMESTAMP_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief Array for saving the period
* @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be
*           defined at block scope
*/
static volatile VAR(Icu_ValueType, ICU_VAR) Icu_aPeriod[ICU_MAX_CHANNEL];


/**
* @brief Array for saving the pulse width of active time
* @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be
*           defined at block scope
*/
static volatile VAR(Icu_ValueType, ICU_VAR) Icu_aActivePulseWidth[ICU_MAX_CHANNEL];

#endif /* ICU_SIGNAL_MEASUREMENT_API */


#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
 * @violates @ref Icu_c_REF_1 only preprocessor statements and
 *        comments before "#include".
 */
/*
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"
/*
 * @violates @ref Icu_c_REF_3 Identifier clash.
 */
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/*
 * @violates @ref Icu_c_REF_1 only preprocessor statements and
 *        comments before "#include".
 */
/*
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/**
* @brief Array for saving value of DMA
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be
*/
volatile VAR(Icu_ValueType,ICU_VAR) Icu_aDmaBuffer[ICU_MAX_CHANNEL][ICU_DMA_MAJORLOOP_COUNT];

/**
* @brief Array for saving the period
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be
*/
volatile VAR(Icu_ValueType, ICU_VAR) Icu_aIsSecondInterrupt[ICU_MAX_CHANNEL];

/**
* @brief Array for saving the period
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* @violates @ref Icu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be
*/
volatile VAR(Icu_ValueType, ICU_VAR) Icu_aFirstEdgeTimeStamp[ICU_MAX_CHANNEL];

#endif /* ICU_SIGNALMEASUREMENT_USES_DMA */
/*
 * @violates @ref Icu_c_REF_3 Identifier clash.
 */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/*
 * @violates @ref Icu_c_REF_1 only preprocessor statements and
 *        comments before "#include".
 */
/*
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"
/*==================================================================================================
 *                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
 * @violates @ref Icu_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
 *        comments before "#include"
 */
/*
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_SetBitChState(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                    VAR(Icu_ChannelStateType, AUTOMATIC) mask
                                                   );

LOCAL_INLINE FUNC(Icu_ChannelStateType, ICU_CODE) Icu_GetBitChState(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                    VAR(Icu_ChannelStateType, AUTOMATIC) mask
                                                                   );
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_ClearBitChState(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                      VAR(Icu_ChannelStateType, AUTOMATIC) mask
                                                     );
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateGlobalCall(VAR(uint8, AUTOMATIC)u8ServiceId);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_EndValidateGlobalCall(VAR(Std_ReturnType,AUTOMATIC)validation,
                                                            VAR(uint8, AUTOMATIC)u8ServiceId
                                                           );
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && (ICU_SET_MODE_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateCallSetMode(VAR(Icu_ModeType, AUTOMATIC)Mode);
#endif /*((ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) && #if (ICU_SET_MODE_API == STD_ON))*/

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateCallAndChannel(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                       VAR(uint8, AUTOMATIC) u8ModeMask,
                                                                       VAR(uint8, AUTOMATIC) u8ServiceId
                                                                      );
#endif

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON))
#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
LOCAL_INLINE FUNC(boolean, ICU_CODE) Icu_GetOverflow(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                     VAR(uint8, AUTOMATIC) u8ServiceId,
                                                     VAR(uint8, AUTOMATIC) u8Error
                                                    );
#endif
#endif  /* ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON) */

#if (ICU_VALIDATE_PARAMS == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidatePtrInit(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON)*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateMode(VAR(Icu_ModeType, AUTOMATIC) Mode);
#endif /*(ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON*/

#if((ICU_VALIDATE_PARAMS == STD_ON) && \
    ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) || (ICU_ENABLE_WAKEUP_API == STD_ON)|| \
     (ICU_DISABLE_WAKEUP_API == STD_ON)))

LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateWakeupChannel(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                      VAR(uint8, AUTOMATIC) u8ServiceId
                                                                     );
#endif /* ICU_VALIDATE_PARAMS == STD_ON */

#if (ICU_VALIDATE_PARAMS == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateActivation(VAR(Icu_ActivationType, AUTOMATIC) Activation);
#endif /* ICU_VALIDATE_PARAMS == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                  P2CONST(Icu_ValueType, AUTOMATIC, ICU_APPL_CONST) pBufferPtr,
                                                                  VAR(uint16, AUTOMATIC) u16BufferSize,
                                                                  VAR(uint16, AUTOMATIC) u16NotifyInterval
                                                                 );
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON) */


#if ((ICU_VALIDATE_PARAMS == STD_ON) &&(ICU_TIMESTAMP_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateChannelStartState(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) &&(ICU_TIMESTAMP_API == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && \
        ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateSignalMeasurementProperty(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                                  VAR(uint16, AUTOMATIC) u16ModePropertyMask,
                                                                                  VAR(uint8, AUTOMATIC)  u8ServiceId
                                                                                 );
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (...) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidatePtrDutyCycle(P2CONST(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_CONST) DutyCycleValues);
#endif /* ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateVersionInfoCall(P2CONST(Std_VersionInfoType, AUTOMATIC, ICU_APPL_CONST) versioninfo);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON */


#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateClockModeCall(VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateGetInputLevel(VAR(Icu_ChannelType, AUTOMATIC) Channel);
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateModeForSetUpFeature(VAR(uint8, AUTOMATIC) u8ApiId);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateSignalMeasureWithoutInterrupt(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                                     VAR(uint8, AUTOMATIC)  u8ServiceId
                                                                                     );
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_CallNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel);

/*==================================================================================================
 *                                        LOCAL FUNCTIONS
==================================================================================================*/



/**
* @brief      Icu_SetBitChState
* @details    Set the Icu_aChannelState bitfield specified by mask parameter in an atomic way.
*
* @param[in]      Channel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_SetBitChState(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                    VAR(Icu_ChannelStateType, AUTOMATIC) mask
                                                   )
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
    {
        Icu_aChannelState[Channel] |= mask;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
}


/**
 * @brief      Icu_GetBitChState
 * @details    Return the Icu_aChannelState bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]      Channel  - The index of ICU channel for current configuration structure
 * @param[in]      mask    - bitfield mask
 * @return         Bitfield specified by mask parameter
 * @retval         ICU_CHANNEL_STATE_WKUP Wakeup feature is currently enabled
 * @retval         ICU_CHANNEL_STATE_IDLE The current channel status is idle
 * @retval         ICU_CHANNEL_STATE_NOTIFICATION Notification is enabled
 * @retval         ICU_CHANNEL_STATE_RUNNING The current channel state is Running
 *
 */
LOCAL_INLINE FUNC(Icu_ChannelStateType, ICU_CODE) Icu_GetBitChState(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                    VAR(Icu_ChannelStateType, AUTOMATIC) mask
                                                                   )
{
    VAR(Icu_ChannelStateType, AUTOMATIC) value;

    value = Icu_aChannelState[Channel] & mask;

    return value;
}


/**
* @brief      Icu_ClearBitChState
* @details    Clear the Icu_aChannelState bitfield specified by mask parameter in an atomic way.
*
* @param[in]      Channel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_ClearBitChState(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                      VAR(Icu_ChannelStateType, AUTOMATIC) mask
                                                     )
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_01();
    {
        Icu_aChannelState[Channel] &= ((Icu_ChannelStateType)(~mask));
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_01();
}

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for functions
 *                that uses all the channels - Icu_Init, Icu_DeInit, Icu_SetMode.
 *
 * @param[in]  u8ServiceId The service id of the caller function
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Icu_ValidateGlobalCall_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateGlobalCall(VAR(uint8, AUTOMATIC)u8ServiceId)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if (ICU_STATE_UNINIT == Icu_GlobalState)
    {
        if (ICU_INIT_ID != u8ServiceId)
        {
            /*
            * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value
            * is always the same and the value itself is not needed.
            */
            Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_UNINIT);
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        if (ICU_INIT_ID == u8ServiceId)
        {
            /*
            * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value
            * is always the same and the value itself is not needed.
            */
            Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_ALREADY_INITIALIZED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    return valid;
}
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function ends the validation of the global call.
 * @details    This service is a non reentrant function used for end the validation the calls for
 *             functions that uses all the channels - Icu_Init, Icu_DeInit, Icu_SetMode.
 *
 * @param[in]   u8ServiceId  The service id of the caller function
 * @param[in]   validation The function call was previously validated
 * @return void
 *
 * */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_EndValidateGlobalCall(VAR(Std_ReturnType,AUTOMATIC)validation,
                                                            VAR(uint8, AUTOMATIC)u8ServiceId
                                                           )
{
    if ((Std_ReturnType)E_OK == validation)
    {
        if (ICU_DEINIT_ID == u8ServiceId)
        {
            Icu_GlobalState = ICU_STATE_UNINIT;
        }
        else
        {
            Icu_GlobalState = ICU_STATE_IDLE;
        }
    }
}
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
 * @brief      This function checks if running operations are performed while changing the Icu mode
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements Icu_ValidateCallSetMode_Activity
 */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateCallSetMode(VAR(Icu_ModeType, AUTOMATIC) Mode)
{
    VAR(Icu_ChannelType, AUTOMATIC) numChl;
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    /*Check that there is no channel that is running and is not wake-up capable*/
    if (Mode != Icu_CurrentMode)
    {
        VAR(boolean, AUTOMATIC) bChRunning  = (boolean)FALSE;

        for (numChl = 0U; numChl < Icu_pCfgPtr->nNumChannels; numChl++)
        {   /*Call low level function*/

            if((ICU_CHANNEL_STATE_RUNNING == Icu_GetBitChState(numChl, ICU_CHANNEL_STATE_RUNNING|ICU_CHANNEL_STATE_WKUP)))
            {
                bChRunning  = (boolean)TRUE;
                /*
                * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
                */
                Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_SETMODE_ID, ICU_E_BUSY_OPERATION);
                break;
            }

        }
        valid = ((boolean)TRUE == bChRunning)? (Std_ReturnType)E_NOT_OK : (Std_ReturnType)E_OK;
    }

    return valid;

}
#endif /*((ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) && #if (ICU_SET_MODE_API == STD_ON))*/

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
/**
 * @brief       This function validates the call for a specific channel
 * @details     This service is a non reentrant function on channel used for validating the calls
 *              for functions that use one channel
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 * @param[in]   ModeMask         The modes that are valid for the specific channel
 * @param[in]   u8ServiceId        The service id of the caller function
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateCallAndChannel_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateCallAndChannel(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                       VAR(uint8, AUTOMATIC) u8ModeMask,
                                                                       VAR(uint8, AUTOMATIC) u8ServiceId
                                                                      )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_NOT_OK;

    if (ICU_STATE_UNINIT == Icu_GlobalState)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_UNINIT);
    }
    else
    {
        VAR(Icu_MeasurementModeType, AUTOMATIC) tempMode = \
                                   (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Mode;

        if ((Channel > Icu_pCfgPtr->nNumChannels) ||\
                (tempMode != (Icu_MeasurementModeType)( u8ModeMask & (uint8)tempMode))
           )
        {
            /*
            * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
            */
            Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        }
        else
        {
            valid = (Std_ReturnType)E_OK;
        }
    }

    return valid;
}
#endif

#if ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON))
#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
/**
 * @brief      This indicates the overflow status for a specific channel
 * @details    In case the overflow notification is not activated, this service reports the overflow
 *                status on a specific channel
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 * @param[in]   u8ServiceId          The service id of the caller function
 * @param[in]   u8Error            The error id that is reported in case of overflow
 *
 * @return      Status of the overflow flag
 * @retval      true          an overflow event occurred for the given channel
 * @retval      false         an overflow event has not occurred for a given channel
 *
 *
 * */
LOCAL_INLINE FUNC(boolean, ICU_CODE) Icu_GetOverflow(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                     VAR(uint8, AUTOMATIC) u8ServiceId,
                                                     VAR(uint8, AUTOMATIC) u8Error
                                                    )
{
    VAR(boolean, AUTOMATIC) bOverflow = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) bChOverflowState = (boolean)FALSE;

    if (ICU_CHANNEL_STATE_OVERFLOW == Icu_GetBitChState(Channel,ICU_CHANNEL_STATE_OVERFLOW))
    {
        bChOverflowState = (boolean)TRUE;
    }

    if (((boolean)TRUE == Icu_Ipw_Get_Overflow(Channel, &Icu_pCfgPtr->IpConfig)) || \
        ((boolean)TRUE == bChOverflowState)
       )
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, u8ServiceId, u8Error);
        bOverflow = (boolean)TRUE;
    }

    return bOverflow;
}
#endif
#endif  /* ((ICU_OVERFLOW_NOTIFICATION_API == STD_OFF) && (ICU_VALIDATE_PARAMS == STD_ON) */

#if (ICU_VALIDATE_PARAMS == STD_ON)

/**
 * @brief              This function validate the initialization pointer.
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidatePtrInit(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

#ifdef ICU_PRECOMPILE_SUPPORT
    if (NULL_PTR != ConfigPtr)
    {
#else
    if (NULL_PTR == ConfigPtr)
    {
#endif /*ICU_PRECOMPILE_SUPPORT*/
       /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_INIT_ID, ICU_E_INIT_FAILED);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON)*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON))
/**
 * @brief             This function validate the mode that will be set in the driver.
 *
 * @param[in]          Mode        Specifies the operation mode
 *
 * @return             The validity of the function call
 * @retval          E_OK      The function call is valid
 * @retval          E_NOT_OK The function call is invalid
 *
 * @implements         Icu_ValidateMode_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateMode(VAR(Icu_ModeType, AUTOMATIC) Mode)
{
    VAR(Std_ReturnType, AUTOMATIC) valid =  (Std_ReturnType)E_NOT_OK;

    if ((ICU_MODE_SLEEP != Mode) && (ICU_MODE_NORMAL != Mode))
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_SETMODE_ID, ICU_E_PARAM_MODE);
    }
    else
    {
        valid = (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /*(ICU_VALIDATE_PARAMS == STD_ON) && (ICU_SET_MODE_API == STD_ON*/

#if((ICU_VALIDATE_PARAMS == STD_ON) && \
    ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) || (ICU_ENABLE_WAKEUP_API == STD_ON)|| \
     (ICU_DISABLE_WAKEUP_API == STD_ON)))
/**
 * @brief          This function validates a wakeup channel
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 * @param[in]   u8ServiceId        The service id of the caller function
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateWkupChannel_Activity
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateWakeupChannel(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                      VAR(uint8, AUTOMATIC) u8ServiceId
                                                                     )
{
    VAR(Std_ReturnType, AUTOMATIC) valid =  (Std_ReturnType)E_OK;
    VAR(Icu_ParamType, AUTOMATIC) tempParamValue = \
                                    (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_ParamValue;

    if ((Icu_ParamType)ICU_WAKEUP_MASK != (tempParamValue& (Icu_ParamType)ICU_WAKEUP_MASK))
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        valid =  (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ICU_VALIDATE_PARAMS == STD_ON */

#if (ICU_VALIDATE_PARAMS == STD_ON)
/**
 * @brief      This service validates the activation condition.
 *
 * @param[in]   Activation       Type of activation.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateActivation_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateActivation(VAR(Icu_ActivationType, AUTOMATIC) Activation)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if ((ICU_RISING_EDGE != Activation) && (ICU_FALLING_EDGE != Activation) && \
        (ICU_BOTH_EDGES != Activation)
       )
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_SETACTIVATIONCONDITION_ID, ICU_E_PARAM_ACTIVATION);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ICU_VALIDATE_PARAMS == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON))
/**
 * @brief          This function validate of the timestamp parameters.
 * @details        This service validates the timestamp parameters passed to Icu_StartTimestamp.
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 * @param[in]   pBufferPtr        Pointer to the buffer-array where the timestamp values shall be
 *                                 placed.
 * @param[in]   u16BufferSize       Size of the external buffer (number of entries)
 * @param[in]   u16NotifyInterval   Notification interval (number of events).
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Icu_ValidateTimestamp_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                  P2CONST(Icu_ValueType, AUTOMATIC, ICU_APPL_CONST) pBufferPtr,
                                                                  VAR(uint16, AUTOMATIC) u16BufferSize,
                                                                  VAR(uint16, AUTOMATIC) u16NotifyInterval
                                                                 )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_NOT_OK;

    if (NULL_PTR == pBufferPtr)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_POINTER);
    }

    else  if ((uint16)0U == u16BufferSize)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_BUFFER_SIZE);
    }
    else if ((ICU_CHANNEL_STATE_NOTIFICATION == Icu_GetBitChState(Channel,ICU_CHANNEL_STATE_NOTIFICATION)) &&
             (NULL_PTR != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Notification) &&
             ((uint16)0U == u16NotifyInterval)
            )
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STARTTIMESTAMP_ID, ICU_E_PARAM_NOTIFY_INTERVAL);
    }
    else
    {
        valid= (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_TIMESTAMP_API == STD_ON) */


#if ((ICU_VALIDATE_PARAMS == STD_ON) &&(ICU_TIMESTAMP_API == STD_ON))
/**
 * @brief      This function validates the state of timestamp channel
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Icu_ValidateChannelStartState_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateChannelStartState(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if(ICU_CHANNEL_STATE_RUNNING != Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING))
    {
         /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_STOPTIMESTAMP_ID, ICU_E_NOT_STARTED);
         valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) &&(ICU_TIMESTAMP_API == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && \
        ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON)))
/**
 * @brief       This function validates the signal measurement property
 *
 * @param[in]   Channel                 Numeric identifier of the ICU channel
 * @param[in]   u16ModePropertyMask     The mode property valid
 * @param[in]   u8ServiceId             The service id of the caller function
 *
 * @return         The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidateSignalMeasurementProperty_Activity
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateSignalMeasurementProperty(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                                  VAR(uint16, AUTOMATIC) u16ModePropertyMask,
                                                                                  VAR(uint8, AUTOMATIC)  u8ServiceId
                                                                                 )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;
    VAR (Icu_MeasurementSubModeType, AUTOMATIC) tempProperty = \
                               (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Property;

    if((tempProperty) != (u16ModePropertyMask & tempProperty))
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (...) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
/**
 * @brief       This function validates the duty cycle parameter
 *
 * @param[in]   DutyCycleValues  Pointer to a buffer where the results (high time and period time)
 *                                 shall be placed.
 *
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements Icu_ValidatePtrDutyCycle_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidatePtrDutyCycle(P2CONST(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_CONST) DutyCycleValues)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if (NULL_PTR == DutyCycleValues)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_GETDUTYCYCLEVALUES_ID, ICU_E_PARAM_POINTER);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))*/

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON))
/**
 * @brief       This function validates the versionInfo parameter
 *
 * @param[in]   versioninfo  Pointer to a buffer where the results for version shall be saved
 *
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateVersionInfoCall(P2CONST(Std_VersionInfoType, AUTOMATIC, ICU_APPL_CONST) versioninfo)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if (NULL_PTR == versioninfo)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, ICU_GETVERSIONINFO_ID, ICU_E_PARAM_VINFO);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_VERSION_INFO_API == STD_ON */


#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON))
/**
 * @brief       This function validates the Prescaler parameter
 *
 * @param[in]   Prescaler One of the two clock functioning modes
 *
 *
 * @return      The validity of the function call
 * @retval      E_OK     The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateClockModeCall(VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if ((ICU_NORMAL_CLOCK_MODE != Prescaler) && (ICU_ALTERNATE_CLOCK_MODE != Prescaler))
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_SET_CLOCK_MODE_ID, (uint8)ICU_E_PARAM_CLOCK_MODE);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_DUAL_CLOCK_MODE_API == STD_ON) */

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
/**
 * @brief       This function validates the Channel type
 *
 * @param[in]   Channel - the logical channel
 *
 *
 * @return      The validity of the channel type
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateGetInputLevel(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    VAR(Icu_ChannelType, AUTOMATIC) nChannelInput = Icu_Ipw_ValidateGetInputLevel(Channel, &Icu_pCfgPtr->IpConfig);

    if (ICU_VALID_CHANNEL_INPUT_LEVEL <= nChannelInput)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, (uint8)0U, (uint8)ICU_GET_INPUT_LEVEL_ID, (uint8)ICU_E_PARAM_CHANNEL);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief       This function validates mode when Enable feature
 *
 * @param[in]   u8ApiId - the id of function
 *
 *
 * @return      The validity of the channel type
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Icu_ValidateModeForSetUpFeature_Activity
 *
 **/
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateModeForSetUpFeature(VAR(uint8, AUTOMATIC) u8ApiId)
{
    VAR(Std_ReturnType, AUTOMATIC) valid =  (Std_ReturnType)E_NOT_OK;

    if (ICU_MODE_SLEEP == Icu_CurrentMode)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ApiId, ICU_E_FORBIDEN_MODE);
    }
    else
    {
        valid = (Std_ReturnType)E_OK;
    }
    return valid;
}
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
/**
 * @brief       This function validates for SignalMeasurement without interrupt
 *
 * @param[in]   Channel - the logical channel
 * @param[in]   u8ApiId - the id of function
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 **/
LOCAL_INLINE FUNC(Std_ReturnType, ICU_CODE) Icu_ValidateSignalMeasureWithoutInterrupt(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                                                     VAR(uint8, AUTOMATIC)  u8ServiceId
                                                                                     )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;
    valid = Icu_Ipw_ValidateSignalMeasureWithoutInterrupt(Channel, &Icu_pCfgPtr->IpConfig);

    if((Std_ReturnType)E_NOT_OK == valid)
    {
        /*
        * @violates @ref Icu_c_REF_10 Ignore value is ignored as return value is always the same and the value itself is not needed.
        */
        Det_ReportError((uint16)ICU_MODULE_ID, 0U, u8ServiceId, ICU_E_PARAM_CHANNEL);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

/**
 * @brief       This function calls the notification, if available for specific channels
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 *
 * @return      void
 * @pre        Icu_Init must be called before.
 *
 *
 * */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_CallNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    if ((ICU_CHANNEL_STATE_NOTIFICATION == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_NOTIFICATION)) \
        && (NULL_PTR != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Notification)
       )
    {
        (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Notification();
    }
}

/*==================================================================================================
 *                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief          This function initializes the driver.
 * @details        This service is a non reentrant function used for driver initialization.
 *        The  Initialization function  shall initialize  all relevant  registers of  the configured
 *        hardware with the  values of the  structure referenced by  the parameter ConfigPtr.
 *        If  the  hardware  allows  for   only  one  usage   of  the  register,   the  driver
 *        module implementing that functionality is responsible for initializing the register.
 *        The initialization function of this module shall always have a pointer as a parameter,
 *        even though for Variant PC no configuration set shall be given.
 *        Instead a NULL pointer shall be passed to the initialization function.
 *        The Icu  module environment  shall not  call Icu_Init  during a  running operation (e. g.
 *        timestamp measurement or edge counting).
 *
 * @param[in]         ConfigPtr        Pointer to a selected configuration structure.
 *
 * @return             void
 * @implements         Icu_Init_Activity
 *
 * @api
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_Init(P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr)
{
    VAR(Icu_ChannelType, AUTOMATIC) numChl;
#if (ICU_TIMESTAMP_API == STD_ON)
    P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelConfig;
#endif /* ICU_TIMESTAMP_API */
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;

#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Icu_ValidateGlobalCall(ICU_INIT_ID);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_GLOBAL_CALL == STD_ON */
#if (ICU_VALIDATE_PARAMS == STD_ON)
        valid = Icu_ValidatePtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */

#ifdef ICU_PRECOMPILE_SUPPORT
            Icu_pCfgPtr = &Icu_PBCfgVariantPredefined;
            (void)ConfigPtr;
#else
            Icu_pCfgPtr = ConfigPtr;
#endif /* ICU_PRECOMPILE_SUPPORT */

#ifdef ICU_NONBONDED_WAKEUP_PULLUP
            Icu_Ipw_PullUpNonBondedWakeupPin();
#endif
            Icu_Ipw_Init(&(Icu_pCfgPtr->IpConfig));

            for (numChl = 0U; numChl < Icu_pCfgPtr->nNumChannels; numChl++)
            {
                /* Clear channel internal state */
                Icu_aChannelState[numChl] =  0x00U;
#if (ICU_TIMESTAMP_API == STD_ON)
                ChannelConfig = &((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[numChl]);
                if (ICU_MODE_TIMESTAMP == ChannelConfig->Icu_Channel_Mode)
                {
                    Icu_aBuffer[numChl] = NULL_PTR;
                }
#endif /* ICU_TIMESTAMP_API */
            }

            Icu_CurrentMode = ICU_MODE_NORMAL;
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (STD_ON == ICU_VALIDATE_GLOBAL_CALL)
    }
    Icu_EndValidateGlobalCall(valid, ICU_INIT_ID);
#endif
}

#if (ICU_DE_INIT_API == STD_ON)
/**
* @brief   This function de-initializes the ICU module.
* @details This service is a Non reentrant function used for ICU De-Initialization
*        After the call of this service, the state of the peripherals used by configuration shall be
*        the  same as  after power  on reset.  Values of  registers which  are not  writable  are
*        excluded.
*        This service shall disable all used interrupts and notifications.
*        The Icu module environment shall not  call Icu_DeInit during a running  operation  (e. g.
*        timestamp measurement or edge counting)
*
* @return void
*
* @api
*
* @pre Icu_Init must be called before.
* @implements Icu_DeInit_Activity
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* */
FUNC(void, ICU_CODE) Icu_DeInit(void)
{
    VAR(Icu_ChannelType, AUTOMATIC) numChl;

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid = Icu_ValidateGlobalCall(ICU_DEINIT_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/

        Icu_Ipw_DeInit(&Icu_pCfgPtr->IpConfig);

        for (numChl = 0U; numChl < Icu_pCfgPtr->nNumChannels; numChl++)
        {
            /* Clear channel internal state */
            Icu_aChannelState[numChl] =  0x00U;
        }

        Icu_pCfgPtr = NULL_PTR;
        Icu_CurrentMode = ICU_MODE_NORMAL;
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_DEINIT_ID);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/
}
#endif /* ICU_DE_INIT_API */


#if (ICU_SET_MODE_API == STD_ON)
/**
 * @brief           This function sets the ICU mode.
 * @details     This service is a non reentrant function used for ICU mode  selection.
 *       This service shall  set the  operation mode  to the given mode parameter.
 *       This service  can be  called during  running operations.  If so,  an ongoing operation that
 *       generates interrupts on a wakeup capable  channel like e.g. time stamping or  edge counting
 *       might lead to the  ICU module not being  able to properly enter sleep  mode. This is then a
 *       system or ECU configuration issue not a problem of this specification.
 *
 * @param[in]   Mode        Specifies the operation mode
 * @return         void
 *
 * @pre         Icu_Init must be called before.
 * @implements     Icu_SetMode_Activity
 *
 * @api
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_SetMode(VAR(Icu_ModeType, AUTOMATIC) Mode)
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;

#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)

    valid = Icu_ValidateGlobalCall(ICU_SETMODE_ID);
    if ((Std_ReturnType)E_OK == valid)
    {
        valid = Icu_ValidateCallSetMode(Mode);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON */
#if (ICU_VALIDATE_PARAMS == STD_ON)
            valid = Icu_ValidateMode(Mode);
            if ((Std_ReturnType)E_OK == valid)
            {
#endif /* ICU_VALIDATE_PARAMS == STD_ON */

                if (Icu_CurrentMode != Mode)
                {
                    VAR(Icu_ChannelType, AUTOMATIC) numChl;

                    for (numChl = 0U; numChl < Icu_pCfgPtr->nNumChannels; numChl++)
                    {
                        VAR(boolean, AUTOMATIC) bActive;

                        if (ICU_MODE_SLEEP == Mode)
                        {
                            bActive = (boolean)((Icu_GetBitChState(numChl,ICU_CHANNEL_STATE_WKUP)==\
                                                ICU_CHANNEL_STATE_WKUP)? TRUE : FALSE
                                               );

                            if ((boolean)FALSE == bActive)
                            {
                                Icu_Ipw_SetSleepMode(numChl, &Icu_pCfgPtr->IpConfig);
                            }
                        }
                        else
                        {
                            bActive = (boolean) ((Icu_GetBitChState(numChl,ICU_CHANNEL_STATE_RUNNING)==\
                                                 ICU_CHANNEL_STATE_RUNNING) ? TRUE : FALSE
                                                );
                            if ((boolean)TRUE == bActive)
                            {
                                Icu_Ipw_SetNormalMode(numChl, &Icu_pCfgPtr->IpConfig);
                            }
                        }
                    }
                    Icu_CurrentMode = Mode;
                }
#if (ICU_VALIDATE_PARAMS == STD_ON)
            }
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */

#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
        }
    }
    Icu_EndValidateGlobalCall(valid, ICU_SETMODE_ID);
#endif /* (ICU_VALIDATE_GLOBAL_CALL == STD_ON)*/
}
#endif /* ICU_SET_MODE_API */

#if (ICU_DISABLE_WAKEUP_API == STD_ON)
/**
 * @brief   This function disables the wakeup capability of a single ICU channel.
 * @details This service is reentrant function and shall disable  the wakeup capability of
 *          a single ICU channel.This  service is only feasible for ICU channels configured
 *          statically as wakeup capable true.
 *          The  function  Icu_DisableWakeup shall  be  pre compile  time  configurable On,Off by
 *          the configuration parameter IcuDisableWakeupApi.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 * @implements Icu_DisableWakeup_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_DisableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
                                          (Channel,\
                                           ((uint8)ICU_MODE_EDGE_COUNTER | (uint8)ICU_MODE_SIGNAL_EDGE_DETECT |\
                                           (uint8)ICU_MODE_SIGNAL_MEASUREMENT | (uint8)ICU_MODE_TIMESTAMP), ICU_DISABLEWAKEUP_ID
                                          );

    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */
#if (ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateWakeupChannel(Channel, ICU_DISABLEWAKEUP_ID))
        {
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_WKUP);
#if (ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif /*(ICU_VALIDATE_PARAMS == STD_ON)*/
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif /* (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON) */
}
#endif /* ICU_DISABLE_WAKEUP_API */

#if (ICU_ENABLE_WAKEUP_API == STD_ON)
/**
 * @brief   This function (re-)enables the wakeup capability of the given ICU channel.
 * @details The function is reentrant and re-enable the wake-up capability of a single ICU channel.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured as wakeup capable.
 * @implements Icu_EnableWakeup_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_EnableWakeup(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_ENABLEWAKEUP_ID))
    {
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
                                          (Channel,\
                                           (uint8)ICU_MODE_EDGE_COUNTER | (uint8)ICU_MODE_SIGNAL_EDGE_DETECT |\
                                           (uint8)ICU_MODE_SIGNAL_MEASUREMENT | (uint8)ICU_MODE_TIMESTAMP, ICU_ENABLEWAKEUP_ID
                                          );

    if((Std_ReturnType)E_OK == valid)
    {
#endif
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        if((Std_ReturnType)E_OK == Icu_ValidateWakeupChannel(Channel, ICU_ENABLEWAKEUP_ID))
        {
#endif
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_WKUP);
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* ICU_ENABLE_WAKEUP_API */


#if ((ICU_WAKEUP_FUNCTIONALITY_API == STD_ON) && (ICU_REPORT_WAKEUP_SOURCE == STD_ON) && \
    (ICU_ENABLE_WAKEUP_API == STD_ON))
/**
 * @brief  Checks if a wakeup capable ICU channel is the source for a wakeup event.
 * @details The function calls the ECU state manager service EcuM_SetWakeupEvent
 * in case of a valid ICU channel wakeup event.
 *
 * @param[in]     WakeupSource          Information on wakeup source to be checked.
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured as wakeup capable.
 *
 * @implements Icu_CheckWakeup_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_CheckWakeup(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
#if ( ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateGlobalCall(ICU_CHECKWAKEUP_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/
        VAR(Icu_ChannelType, AUTOMATIC) numChl;
        P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) pTempPtr;

        for (numChl = 0U; numChl < Icu_pCfgPtr->nNumChannels; numChl++)
        {
            pTempPtr = &(*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[numChl];
            if (((ICU_CHANNEL_IS_WAKEUP_SOURCE | ICU_CHANNEL_STATE_WKUP) ==  \
                 Icu_GetBitChState(numChl, ICU_CHANNEL_IS_WAKEUP_SOURCE | ICU_CHANNEL_STATE_WKUP) \
                ) && (WakeupSource == (EcuM_WakeupSourceType)pTempPtr->Icu_Channel_WakeupValue)
               )
            {
                EcuM_SetWakeupEvent(WakeupSource);
                Icu_ClearBitChState(numChl, ICU_CHANNEL_IS_WAKEUP_SOURCE);
                break;
            }
        }
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_CHECKWAKEUP_ID);
#endif /* ICU_VALIDATE_GLOBAL_CALL == STD_ON*/
}
#endif /* ICU_WAKEUP_FUNCTIONALITY_API && ICU_REPORT_WAKEUP_SOURCE  &&  ICU_ENABLE_WAKEUP_API */


/**
 * @brief   This function sets the activation-edge for the given channel.
 * @details This service  is reentrant and shall set  the  activation-edge according to Activation
 *          parameter for the given channel.
 *          This service shall support channels which are configured
 *          for  the following Icu_MeasurementMode:
 *          - ICU_MODE_SIGNAL_EDGE_DETECT
 *          - ICU_MODE_TIMESTAMP
 *          - ICU_MODE_EDGE_COUNTER
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 * @param[in]     Activation       Type of activation.
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be properly configured
 *      (ICU_MODE_SIGNAL_EDGE_DETECT, ICU_MODE_TIMESTAMP, ICU_MODE_EDGE_COUNTER).
 *
 * @implements Icu_SetActivationCondition_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                                VAR(Icu_ActivationType, AUTOMATIC) Activation
                                               )
{
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel
                                         (Channel,\
                                          (uint8)ICU_MODE_EDGE_COUNTER | (uint8)ICU_MODE_SIGNAL_EDGE_DETECT | \
                                          (uint8)ICU_MODE_TIMESTAMP, ICU_SETACTIVATIONCONDITION_ID
                                         );

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateActivation(Activation))
        {
#endif
            /* Clear IDLE status */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_IDLE);

            Icu_Ipw_SetActivationCondition(Channel, Activation,
                                           (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Mode,
                                           &Icu_pCfgPtr->IpConfig
                                           );
#if ( ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}


/**
 * @brief   This function disables the notification of a channel.
 *
 * @details This function is reentrant and disables the notification of a channel.
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_DisableNotification_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_DisableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = \
                Icu_ValidateCallAndChannel(Channel, \
                                           (uint8)ICU_MODE_SIGNAL_EDGE_DETECT | (uint8)ICU_MODE_TIMESTAMP, \
                                           ICU_DISABLENOTIFICATION_ID
                                          );

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* Clear notification enable status */
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_NOTIFICATION);

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_DISABLENOTIFICATION_ID);
#endif
}


/**
 * @brief   This function enables the notification on the given channel.
 * @details This function is reentrant and enables the notification on the given channel. The
 *          notification  will be reported only when the channel measurement property is enabled or
 *          started
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_EnableNotification_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_EnableNotification(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = \
                    Icu_ValidateCallAndChannel(Channel,
                                               (uint8)ICU_MODE_SIGNAL_EDGE_DETECT |(uint8)ICU_MODE_TIMESTAMP,\
                                               ICU_ENABLENOTIFICATION_ID
                                              );

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* Set notification enable status */
        Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_NOTIFICATION);

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_ENABLENOTIFICATION_ID);
#endif
}


#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief   This function returns the status of the ICU input.
 * @details This service is reentrant shall return the status of  the ICU input.
 *          Only channels which are configured for the following Icu_MeasurementMode shall be
 *          supported:
 *          - ICU_MODE_SIGNAL_EDGE_DETECT,
 *          - ICU_MODE_SIGNAL_MEASUREMENT.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return Icu_InputStateType
 * @retval  ICU_ACTIVE     An activation edge has been detected
 * @retval  ICU_IDLE       No activation edge has been detected since the last call of
 * Icu_GetInputState() or Icu_Init().
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_GetInputState_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(Icu_InputStateType, ICU_CODE) Icu_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_InputStateType, AUTOMATIC) tempState = ICU_IDLE;
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = \
                Icu_ValidateCallAndChannel(Channel,
                                           (uint8)ICU_MODE_SIGNAL_EDGE_DETECT | (uint8)ICU_MODE_SIGNAL_MEASUREMENT, \
                                           ICU_GETINPUTSTATE_ID
                                          );

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        if (ICU_CHANNEL_STATE_IDLE == Icu_GetBitChState(Channel, ICU_CHANNEL_STATE_IDLE))
        {
            tempState = ICU_ACTIVE;

            /* Clear IDLE status */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
        }
        else if  (ICU_MODE_SIGNAL_EDGE_DETECT ==
                  (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Mode
                 )

        {
            tempState = Icu_Ipw_GetInputState(Channel, &Icu_pCfgPtr->IpConfig);
        }
        else
        {
            /* does nothing*/
        }

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateGlobalCall(valid, ICU_GETINPUTSTATE_ID);
#endif
    return (tempState);
}
#endif /* ICU_GET_INPUT_STATE_API */


#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief   This function starts the capturing of timer values on the edges.
 * @details This function is reentrant and starts the capturing of timer values on the edges
 *          activated by the service Icu_SetActivationCondition() to an external buffer.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 * @param[in]     BufferPtr        Pointer to the buffer-array where the timestamp values shall be
 *                                 placed.
 * @param[in]     BufferSize       Size of the external buffer (number of entries)
 * @param[in]     NotifyInterval   Notification interval (number of events).
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_StartTimestamp_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_StartTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                        P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA) BufferPtr,
                                        VAR(uint16, AUTOMATIC) BufferSize,
                                        VAR(uint16, AUTOMATIC) NotifyInterval
                                       )
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_STARTTIMESTAMP_ID))
    {
#endif
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
        static VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) tcd_config[ICU_MAX_CHANNEL];
#endif

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
            (Channel, (uint8)ICU_MODE_TIMESTAMP, ICU_STARTTIMESTAMP_ID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
#if ( ICU_VALIDATE_PARAMS == STD_ON)
            if ((Std_ReturnType)E_OK == Icu_ValidateTimestamp(Channel, BufferPtr, BufferSize,\
                NotifyInterval)
               )
            {
#endif
                VAR(boolean, AUTOMATIC) bDmaSupport =  (boolean)FALSE;
                SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_02();
                {
                    /* Time stamp is running */
                    Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
                    Icu_aBuffer[Channel]       = BufferPtr;
                    Icu_aBufferSize[Channel]   = BufferSize;
                    Icu_aBufferNotify[Channel] = NotifyInterval;
                    Icu_aNotifyCount[Channel]  = 0U;
                    Icu_aBufferIndex[Channel]  = 0U;
                }
                SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_02();

                /*Clear the previous overflow status flag (if was the case) */
                Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                if(NoMclDmaChannel != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel)
                {
                    /* initialize the members of the structure */
                    tcd_config[Channel].u32saddr = Icu_Ipw_GetStartAddress (Channel, &Icu_pCfgPtr->IpConfig);
                    /* @violates @ref Icu_c_REF_7 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
                    /* @violates @ref Icu_c_REF_11 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                    /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
                    tcd_config[Channel].u32daddr = (uint32)BufferPtr;
                    tcd_config[Channel].u32ssize = (uint32)ICU_DMA_SIZE;
                    tcd_config[Channel].u32dsize = (uint32)ICU_DMA_SIZE;
                    tcd_config[Channel].u32soff  = (uint32)0;
                    tcd_config[Channel].u32doff  = (uint32)ICU_DMA_OFFSET;
                    tcd_config[Channel].u32smod  = (uint32)0;
                    tcd_config[Channel].u32dmod  = (uint32)0;
                    if ((NotifyInterval >= BufferSize) || (NotifyInterval == (uint16)0))
                    {
                        tcd_config[Channel].u32num_bytes = ICU_DMA_NUM_BYTES;
                        tcd_config[Channel].u32iter = BufferSize;
                    }
                    else if (NotifyInterval < BufferSize)
                    {
                        tcd_config[Channel].u32num_bytes = ICU_DMA_NUM_BYTES;
                        tcd_config[Channel].u32iter = NotifyInterval;
                    }
                    else
                    {
                        /* does nothing*/
                    }
                    Mcl_DmaConfigChannel((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel, &tcd_config[Channel]);
                    Mcl_DmaStartChannel((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel);

                    Mcl_DmaConfigChannel((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel,&tcd_config[Channel]);

                    Mcl_DmaEnableHwRequest((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel);
                    Mcl_DmaEnableNotification((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel, MCL_DMA_TRANSFER_COMPLETE);
                    bDmaSupport = (boolean) TRUE;
                }
#endif
                Icu_Ipw_StartTimestamp(Channel, &Icu_pCfgPtr->IpConfig, bDmaSupport);
#if ( ICU_VALIDATE_PARAMS == STD_ON)
            }
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    Icu_EndValidateGlobalCall(valid, ICU_STARTTIMESTAMP_ID);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* ICU_TIMESTAMP_API == STD_ON*/

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief   This function stops the timestamp measurement of the given channel.
 * @details This function is reentrant and stops the timestamp measurement of the given channel.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_StopTimestamp_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_StopTimestamp(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel(Channel,(uint8)ICU_MODE_TIMESTAMP, ICU_STOPTIMESTAMP_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
        if ((Std_ReturnType)E_OK == Icu_ValidateChannelStartState(Channel))
        {
#endif
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
            if(NoMclDmaChannel != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel)
            {
                Mcl_DmaDisableHwRequest((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel);
            }
#endif
            Icu_Ipw_StopTimestamp(Channel, &Icu_pCfgPtr->IpConfig);
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* ICU_TIMESTAMP_API == STD_ON*/

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief   This function reads the timestamp index of the given channel.
 * @details This function reentrant and reads the timestamp index of the given channel,
 *          which is next to be written.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return Icu_IndexType - Timestamp index of the given channel
 *
 * @api
 *
 * @pre Icu_Init must be called before. Icu_StartTimestamp must be called before.
 *
 * @implements Icu_GetTimestampIndex_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(Icu_IndexType, ICU_CODE) Icu_GetTimestampIndex(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_IndexType, AUTOMATIC) timestampIndex = 0U;

#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel(Channel, (uint8)ICU_MODE_TIMESTAMP, ICU_GETTIMESTAMPINDEX_ID);

    if ((Std_ReturnType)E_OK == valid)
    {

#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if ((boolean)FALSE == Icu_GetOverflow(Channel, ICU_GETTIMESTAMPINDEX_ID, ICU_E_TIMESTAMP_OVERFLOW))
        {
#endif
            if (NULL_PTR == Icu_aBuffer[Channel])
            {
                timestampIndex = 0U;
            }
            else
            {
#endif
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                if(NoMclDmaChannel != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel)
                {
                    VAR(uint16, AUTOMATIC) u16crtIter = \
                            Mcl_DmaGetStartIterCount((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel);

                    u16crtIter = u16crtIter - \
                            Mcl_DmaGetCrtIterCount((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel);
                    timestampIndex =  Icu_aBufferIndex[Channel] + (Icu_IndexType)u16crtIter;
                }
                else
                {
#endif
                    timestampIndex = Icu_aBufferIndex[Channel];
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                }
#endif

#if (ICU_VALIDATE_PARAMS == STD_ON)
            }
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if ( ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return timestampIndex;
}
#endif /* ICU_TIMESTAMP_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
 * @brief   This function resets the value of the counted edges to zero.
 * @details This function is reentrant and resets the value of the counted edges to zero.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel.
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.
 *
 * @implements Icu_ResetEdgeCount_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_ResetEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
                (Channel, (uint8)ICU_MODE_EDGE_COUNTER, ICU_RESETEDGECOUNT_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        /* Clear overflow flag */
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
        Icu_Ipw_ResetEdgeCount(Channel, &Icu_pCfgPtr->IpConfig);

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    Icu_EndValidateCallAndChannel(valid);
    }
#endif
}
#endif /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
 * @brief   This function enables the counting of edges of the given channel.
 * @details This service is reentrant and shall enable the counting of  edges of the given channel.
 *          Note: This  service doesnot do the real counting itself. This is done by the hardware
 *          (capture unit). Only the configured edges shall be counted (rising edge, falling edge or
 *           both edges).
 *
 *          Configuration  of  the  edge  is  done  in  Icu_Init  or  Icu_SetActivationCondition.The
 *          configured edge can be  changed during runtime using  Icu_SetActivationCondition.
 *          Interrupts are not required for edge counting.If interrupts are enabled, the interrupt
 *          service routine
 *          will set the overflow flag if more than 0xFFFFFF edges are measured.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The given channel must be configured in Measurement Mode
 *      Edge Counter.
 * @implements Icu_EnableEdgeCount_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_EnableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_ENABLEEDGECOUNT_ID))
    {
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
            (Channel,(uint8)ICU_MODE_EDGE_COUNTER, ICU_ENABLEEDGECOUNT_ID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
            /*Clear the previous overflow status flag (if was the case) */
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
            /* Clear overflow flag */
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
            Icu_Ipw_EnableEdgeCount(Channel, &Icu_pCfgPtr->IpConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
 * @brief   This function disables the counting of edges of the given channel.
 * @details This function is reentrant and disables the counting of edges of the given channel.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before.The given channel must be configured in Measurement
 *      Mode Edge Counter.
 *
 * @implements Icu_DisableEdgeCount_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_DisableEdgeCount(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)ICU_MODE_EDGE_COUNTER, ICU_DISABLEEDGECOUNT_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        Icu_Ipw_DisableEdgeCount(Channel, &Icu_pCfgPtr->IpConfig);
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
 * @brief   This function reads the number of counted edges.
 * @details This function is reentrant reads the number of counted edges after the last call
 *          of Icu_ResetEdgeCount().
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return Icu_EdgeNumberType - Number of the counted edges.
 *
 * @api
 *
 * @pre Icu_Init must be called before. The given channel must be configured in Measurement
 *      Mode Edge Counter.
 *
 * @implements Icu_GetEdgeNumbers_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_GetEdgeNumbers(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_EdgeNumberType, AUTOMATIC) edgeNumbers = 0U;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)ICU_MODE_EDGE_COUNTER, ICU_GETEDGENUMBERS_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if ((boolean)FALSE == Icu_GetOverflow(Channel, ICU_GETEDGENUMBERS_ID, ICU_E_EDGECOUNTING_OVERFLOW))
        {
#endif
#endif
            edgeNumbers = Icu_Ipw_GetEdgeNumbers(Channel, &Icu_pCfgPtr->IpConfig);
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return edgeNumbers;
}
#endif /* ICU_EDGE_COUNT_API */


#if ( ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief   This function enables or re-enables the detection of edges of the given channel.
 * @details This function is reentrant enables or re-enables the detection of edges of the given
 *          channel.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Edge
 *      Counter
 *
 * @implements Icu_EnableEdgeDetection_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_ENABLEEDGEDETECTION_ID))
    {
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
            (Channel,(uint8)ICU_MODE_SIGNAL_EDGE_DETECT, ICU_ENABLEEDGEDETECTION_ID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
            Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
            Icu_Ipw_EnableEdgeDetection(Channel, &Icu_pCfgPtr->IpConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
        Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /* ICU_EDGE_DETECT_API */


#if ( ICU_EDGE_DETECT_API == STD_ON)
/**
 * @brief   This function disables the detection of edges of the given channel.
 * @details This function is reentrant and disables the detection of edges of the given channel.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Edge
 *      Detection.
 *
 * @implements Icu_DisableEdgeDetection_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
        (Channel,(uint8)ICU_MODE_SIGNAL_EDGE_DETECT, ICU_DISABLEEDGEDETECTION_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        Icu_Ipw_DisableEdgeDetection(Channel, &Icu_pCfgPtr->IpConfig);
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
 * @brief   This function starts the measurement of signals.
 * @details This service is reentrant and starts the measurement of signals beginning with the
 *          configured default start edge which occurs first after the call of this service.
 *          This service shall only be available in Measurement Mode ICU_MODE_SIGNAL_MEASUREMENT.
 *          This service shall reset the state for the given channel to ICU_IDLE.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Signal
 *      Measurement.
 *
 * @implements Icu_StartSignalMeasurement_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_StartSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    if((Std_ReturnType)E_OK == Icu_ValidateModeForSetUpFeature(ICU_STARTSIGNALMEASUREMENT_ID))
    {
#endif
#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
        static VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) tcd_config[ICU_MAX_CHANNEL];
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
            (Channel,(uint8)ICU_MODE_SIGNAL_MEASUREMENT, ICU_STARTSIGNALMEASUREMENT_ID);

        if ((Std_ReturnType)E_OK == valid)
        {
#endif
#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
            VAR(uint8, AUTOMATIC) u8index = 0U;
#endif
            VAR(boolean, AUTOMATIC) bDmaSupport =  (boolean)FALSE;

            P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) Icu_pTempPtr = \
                                                &(*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel];
            VAR(Icu_ActivationType, AUTOMATIC) Activation = \
                        (Icu_ActivationType)((Icu_pTempPtr->Icu_ParamValue) >> ICU_EDGE_PARAM_SHIFT);
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_08();
            {
                Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
                /*Clear the previous overflow status flag (if was the case) */
                Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);

#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
                if(NoMclDmaChannel != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel)
                {
                    /* initialize the members of the structure */
                    tcd_config[Channel].u32saddr = Icu_Ipw_GetStartAddress (Channel, &Icu_pCfgPtr->IpConfig);
                    /* @violates @ref Icu_c_REF_7 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
                    /* @violates @ref Icu_c_REF_11 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                    /* Compiler_Warning: This warning is thrown because of a conversion between a Icu_ValyeType pointer and a uint32 */
                    tcd_config[Channel].u32daddr = (uint32)&Icu_aDmaBuffer[Channel][0];
                    tcd_config[Channel].u32ssize = (uint32)ICU_DMA_SIZE;
                    tcd_config[Channel].u32dsize = (uint32)ICU_DMA_SIZE;
                    tcd_config[Channel].u32soff  = (uint32)0;
                    tcd_config[Channel].u32doff  = (uint32)ICU_DMA_OFFSET;
                    tcd_config[Channel].u32smod  = (uint32)0;
                    tcd_config[Channel].u32dmod  = (uint32)ICU_DMA_MAJORLOOP_COUNT;
                    tcd_config[Channel].u32num_bytes = ICU_DMA_NUM_BYTES;
                    tcd_config[Channel].u32iter = ICU_DMA_MAJORLOOP_FIRST_COUNT;
                    Mcl_DmaConfigChannel((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel, &tcd_config[Channel]);
                    Mcl_DmaEnableHwRequest((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel);
                    Mcl_DmaEnableNotification((*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel, MCL_DMA_TRANSFER_COMPLETE);

                     /*Clear the DMA result buffer for configured DMA channel*/
                    for(u8index = 0U; u8index < ICU_DMA_MAJORLOOP_COUNT; u8index++)
                    {
                        Icu_aDmaBuffer[Channel][u8index] = (uint16)0;
                    }
                    bDmaSupport = (boolean) TRUE;
                }
#endif

#if ((ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
                Icu_aActivePulseWidth[Channel] = 0U;
                Icu_aPeriod[Channel] = 0U;
#endif  /* ICU_GET_TIME_ELAPSED_API || ICU_GET_DUTY_CYCLE_VALUES_API */
            }
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_08();
            Icu_Ipw_StartSignalMeasurement(Channel,
                                           &Icu_pCfgPtr->IpConfig,
                                           (Icu_ActivationType)Activation,
                                           (Icu_SignalMeasurementPropertyType)Icu_pTempPtr->Icu_Channel_Property,
                                           (boolean)bDmaSupport
                                          );
            Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    Icu_EndValidateCallAndChannel(valid);
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif
}
#endif /*ICU_SIGNAL_MEASUREMENT_API == STD_ON*/

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
 * @brief   This function stops the measurement of signals of the given channel.
 * @details This function is reentrant and stops the measurement of signals of the given channel.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Signal
 *       Measurement.
 *
 * @implements Icu_StopSignalMeasurement_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_StopSignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
        (Channel, (uint8)ICU_MODE_SIGNAL_MEASUREMENT, ICU_STOPSIGNALMEASUREMENT_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
        Icu_Ipw_StopSignalMeasurement(Channel, &Icu_pCfgPtr->IpConfig);
        Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_GET_TIME_ELAPSED_API== STD_ON)
/**
 * @brief   This function reads the elapsed Signal Low, High or Period Time for the given channel.
 * @details This service is reentrant and reads the elapsed Signal Low Time for the given channel
 *          that is configured  in Measurement Mode Signal Measurement, Signal Low Time.
 *          The elapsed time is measured between a falling edge and the consecutive rising edge of
 *          the channel.
 *          This service reads the elapsed Signal High Time for the given channel that is configured
 *          in Measurement Mode Signal Measurement,Signal High Time.The elapsed time is measured
 *          between a rising edge and the consecutive falling edge of the channel.
 *          This service reads the elapsed Signal Period Time for the given channel that is
 *          configured in Measurement Mode Signal Measurement,  Signal Period Time.The elapsed time
 *          is measured between consecutive  rising (or falling) edges  of the  channel. The  period
 *          start edge is
 *
 *          configurable.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return Icu_ValueType -  the elapsed Signal Low Time for the given channel that is configured in
 *          Measurement Mode Signal Measurement, Signal Low Time
 *
 * @api
 *
 * @pre Icu_Init must be called before. The channel must be configured in Measurement Mode Signal
 *      Measurement.
 *
 * @implements Icu_GetTimeElapsed_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(Icu_ValueType, ICU_CODE) Icu_GetTimeElapsed(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_ValueType, AUTOMATIC) timeElapsed = (Icu_ValueType)0U;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC) valid = Icu_ValidateCallAndChannel(Channel,\
            (uint8)ICU_MODE_SIGNAL_MEASUREMENT, ICU_GETTIMEELAPSED_ID);

    if ((Std_ReturnType)E_OK == valid)
    {

#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if ((boolean)FALSE == Icu_GetOverflow(Channel, ICU_GETTIMEELAPSED_ID, ICU_E_MEASUREMENT_OVERFLOW))
        {
#endif
            if ((Std_ReturnType)E_OK == Icu_ValidateSignalMeasurementProperty
                    (Channel,\
                     (uint16)ICU_LOW_TIME | (uint16)ICU_HIGH_TIME |\
                     (uint16)ICU_PERIOD_TIME \
                     , ICU_GETTIMEELAPSED_ID
                    )
               )
            {
#endif
                SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_05();
                {
                    P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST)Icu_TempPtr = \
                                                    &(*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel];

                    if (ICU_PERIOD_TIME == (Icu_SignalMeasurementPropertyType)(Icu_TempPtr->Icu_Channel_Property))
                    {
                        timeElapsed = Icu_aPeriod[Channel];
                        Icu_aPeriod[Channel] = (Icu_ValueType)0U;
                        Icu_ClearBitChState(Channel,ICU_CHANNEL_STATE_IDLE);
                    }
                    else
                    {
                        timeElapsed = Icu_aActivePulseWidth[Channel];
                        Icu_aActivePulseWidth[Channel] = (Icu_ValueType)0U;
                        Icu_ClearBitChState(Channel,ICU_CHANNEL_STATE_IDLE);
                    }
                }
                SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_05();

#if (ICU_VALIDATE_PARAMS == STD_ON)
            }
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return timeElapsed;

}
#endif /* ICU_GET_TIME_ELAPSED_API */

#if (ICU_GET_DUTY_CYCLE_VALUES_API== STD_ON)
/**
 * @brief   This function reads the coherent active time and period time for the given ICU Channel.
 * @details The function is reentrant and reads the coherent active time and period time for
 *          the given ICU Channel, if it is configured in Measurement Mode Signal Measurement, Duty
 *          Cycle Values.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 * @param[out]    DutyCycleValues  Pointer to a buffer where the results (high time and period time)
 *                                 shall be placed.
 *
 * @return void
 *
 * @api
 *
 * @pre Icu_Init must be called before. The given channel must be configured in Measurement Mode
 *      Signal Measurement, Duty Cycle Values.
 *
 * @ implements Icu_GetDutyCycleValues_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_GetDutyCycleValues(VAR(Icu_ChannelType, AUTOMATIC) Channel,
                                            P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA) DutyCycleValues
                                           )
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
        (Channel, (uint8)ICU_MODE_SIGNAL_MEASUREMENT, ICU_GETDUTYCYCLEVALUES_ID);

    if ((Std_ReturnType)E_OK == valid)
    {
#endif
#if (ICU_VALIDATE_PARAMS == STD_ON)
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        if ((boolean)FALSE == Icu_GetOverflow(Channel, ICU_GETDUTYCYCLEVALUES_ID, ICU_E_MEASUREMENT_OVERFLOW))
        {
#endif
            if ((Std_ReturnType)E_OK == Icu_ValidateSignalMeasurementProperty
                        (Channel,\
                         (uint16)ICU_DUTY_CYCLE ,\
                         ICU_GETDUTYCYCLEVALUES_ID
                        )
               )
            {

                if ((Std_ReturnType)E_OK == Icu_ValidatePtrDutyCycle(DutyCycleValues))
                {
#endif
                    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_06();
                    {
                        if ((Icu_ValueType)0U != Icu_aPeriod[Channel])
                        {
                            DutyCycleValues->ActiveTime = (Icu_ValueType)\
                                                            Icu_aActivePulseWidth[Channel];
                            DutyCycleValues->PeriodTime = (Icu_ValueType)Icu_aPeriod[Channel];
                            Icu_aActivePulseWidth[Channel] = (Icu_ValueType)0U;
                            Icu_aPeriod[Channel]           = (Icu_ValueType)0U;
                        }
                        else
                        {
                            DutyCycleValues->ActiveTime = (Icu_ValueType)0U;
                            DutyCycleValues->PeriodTime = (Icu_ValueType)0U;
                        }
                    }
                    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_06();

#if (ICU_VALIDATE_PARAMS == STD_ON)
                }
            }
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_OFF)
        }
#endif
#endif
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
}
#endif /* ICU_GET_DUTY_CYCLE_VALUES_API */

#if (ICU_GET_VERSION_INFO_API == STD_ON)
/**
 * @brief   This service returns the version information of this module.
 * @details This  service is Non reentrant and returns the version information of this module.
 *          The version information includes:
 *          - Module Id
 *          - Vendor Id
 *          - Vendor specific version numbers
 *          If source code for caller and callee of this function is available this function should
 *          be realized as a macro. The macro should be defined in the modules header file.
 *
 * @param[out]    versioninfo      Pointer to location to store version info
 *
 * @return void
 *
 * @api
 *
 * @implements Icu_GetVersionInfo_Activity
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 *
 * */
FUNC(void, ICU_CODE) Icu_GetVersionInfo \
                                   (P2VAR(Std_VersionInfoType, AUTOMATIC, ICU_APPL_DATA)versioninfo)
{
#if (ICU_VALIDATE_PARAMS == STD_ON)
    if ((Std_ReturnType)E_OK == Icu_ValidateVersionInfoCall(versioninfo))
    {
#endif
        (versioninfo)->vendorID         = (uint16)ICU_VENDOR_ID;
        (versioninfo)->moduleID         = (uint8)ICU_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)ICU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)ICU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)ICU_SW_PATCH_VERSION;
#if (ICU_VALIDATE_PARAMS == STD_ON)
    }
#endif
}
#endif  /* ICU_GET_VERSION_INFO_API == STD_ON */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/**
* @brief      This function changes the channel prescaler.
* @details    This function sets all channels prescalers based on the input mode.
*
* @param[in]  Prescaler - Prescaler type: Normal or Alternate
*
* @return     void
*
* @pre        Icu_Init must be called before.
*
*
* @implements Icu_SetClockMode_Activity
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, ICU_CODE) Icu_SetClockMode(VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler)
{
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON) || (ICU_VALIDATE_PARAMS == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
#endif
#if (ICU_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Icu_ValidateGlobalCall(ICU_SET_CLOCK_MODE_ID);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (ICU_VALIDATE_GLOBAL_CALL == STD_ON */
#if (ICU_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_OK == Icu_ValidateClockModeCall(Prescaler))
        {
#endif
            Icu_Ipw_SetClockMode(&Icu_pCfgPtr->IpConfig, Prescaler);
#if (ICU_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (STD_ON == ICU_VALIDATE_GLOBAL_CALL)
    }
    Icu_EndValidateGlobalCall(valid, ICU_SET_CLOCK_MODE_ID);
#endif
}
#endif /* ICU_DUAL_CLOCK_MODE_API */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
 * @brief      This function returns the actual status of PIN.

 * @details    This function returns the actual status of PIN.
 *
 * @param[in]     Channel          Numeric identifier of the ICU channel
 *
 * @return  Icu_LevelType
 *
 * @pre        Icu_Init must be called before.
 *
 * @implements Icu_GetInputLevel_Activity
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(Icu_LevelType, ICU_CODE) Icu_GetInputLevel(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_LevelType, AUTOMATIC) level = (Icu_LevelType)ICU_LEVEL_LOW;

#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) valid = Icu_ValidateCallAndChannel \
                    (Channel,(uint8)ICU_MODE_SIGNAL_MEASUREMENT|(uint8)ICU_MODE_SIGNAL_EDGE_DETECT, \
                     ICU_GET_INPUT_LEVEL_ID \
                    );

    if ((Std_ReturnType)E_OK == valid)
    {
        if ((Std_ReturnType)E_OK == Icu_ValidateGetInputLevel(Channel))
        {
#endif
            level = (Icu_LevelType)Icu_Ipw_GetInputLevel(Channel, &Icu_pCfgPtr->IpConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    }
    Icu_EndValidateCallAndChannel(valid);
#endif
    return level;
}
#endif /* ICU_GET_INPUT_LEVEL_API */


/**
 * @brief      This function reports the wakeup and overflow events, if available.
 *
 * @param[in]  Channel          Numeric identifier of the ICU channel
 * @param[in]  bOverflow        Parameter that indicates the source of report is an overflow
 *
 * @return     void
 * @implements Icu_ReportWakeupAndOverflow_Activity
 * @pre        Icu_Init must be called before.
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_ReportWakeupAndOverflow(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                                 VAR(boolean, AUTOMATIC) bOverflow
                                                )
{
    VAR(Icu_ChannelType, AUTOMATIC) Channel = (*(Icu_pCfgPtr->Icu_HwMap))[hwChannel];
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    VAR(boolean, AUTOMATIC) bChWakeupCapable;
    VAR(boolean, AUTOMATIC) bCrtModeSleep;

    bChWakeupCapable = (ICU_CHANNEL_STATE_WKUP == Icu_GetBitChState (Channel, ICU_CHANNEL_STATE_WKUP)) ? \
                       (boolean)TRUE : (boolean)FALSE ;
    bCrtModeSleep    = (ICU_MODE_SLEEP == Icu_CurrentMode)? (boolean)TRUE : (boolean)FALSE ;

    if (((boolean)TRUE == bChWakeupCapable) && ((boolean)TRUE == bCrtModeSleep))
    {
        Icu_SetBitChState(Channel, ICU_CHANNEL_IS_WAKEUP_SOURCE);
        EcuM_CheckWakeup((EcuM_WakeupSourceType)\
                         (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_WakeupValue
                        );
    }
#endif /* ICU_REPORT_WAKEUP_SOURCE == STD_ON */
    if ((boolean)TRUE == bOverflow)
    {
        Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_OVERFLOW);
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        if (NULL_PTR != (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_OverflowNotification)
        {
            (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_OverflowNotification();
        }
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
    }
}

/**
 * @brief     This function reports the wakeup event, overflow event and notification, if available
 *
 * @param[in]   Channel          Numeric identifier of the ICU channel
 * @param[in]      overflow           Parameter that indicates the source of report is an overflow
 *
 * @return      void
 * @implements Icu_ReportEvents_Activity
 * @pre        Icu_Init must be called before.
 *
 *
 * @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
 * */
FUNC(void, ICU_CODE) Icu_ReportEvents(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                      VAR(boolean, AUTOMATIC) bOverflow
                                     )
{
    VAR(Icu_ChannelType, AUTOMATIC) Channel = (*(Icu_pCfgPtr->Icu_HwMap))[hwChannel];

    Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
    Icu_ReportWakeupAndOverflow(hwChannel, bOverflow);
    Icu_CallNotification(Channel);
}

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/**
* @brief      This function saves the value of timestamps in the internal buffer
*
* @param[in]  Channel            Numeric identifier of the ICU channel
* @implements Icu_TimestampDmaProcessing_Activity
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void,ICU_CODE) Icu_TimestampDmaProcessing(VAR(Icu_ChannelType, AUTOMATIC)Channel)
{
    VAR (Mcl_ChannelType, AUTOMATIC) Mcl_DmaChannel =\
            (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel;
    VAR (Icu_IndexType, AUTOMATIC) crtIterCount = \
            (Icu_IndexType) Mcl_DmaGetStartIterCount(Mcl_DmaChannel);
    VAR (Icu_IndexType, AUTOMATIC) noOfBufferElemToFill = 0U;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_03();
    {
        Icu_aBufferIndex[Channel] += crtIterCount;
        noOfBufferElemToFill = Icu_aBufferSize[Channel] - Icu_aBufferIndex[Channel];

        /* Handling notification*/
        if ((Icu_IndexType)0 != Icu_aBufferNotify[Channel])
        {
            Icu_aNotifyCount[Channel] += crtIterCount;
            if  (Icu_aNotifyCount[Channel] == Icu_aBufferNotify[Channel])
            {
                Icu_aNotifyCount[Channel] = 0U;
                /* Call User Notification Function and/or Wakeup Function */
                Icu_CallNotification(Channel);
            }
        }

        if (0U == noOfBufferElemToFill)
        {
            if ((uint8) ICU_CIRCULAR_BUFFER ==  \
                    (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Property
               )
            {
                Icu_aBufferIndex[Channel] = 0U;
                /* @violates @ref Icu_c_REF_7 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
                /* @violates @ref Icu_c_REF_11 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                /* Compiler_Warning: DMA TCD addresses are restricted to 32 bits, so casting from pointer type to uint32 is safe. The application should ensure that only addresses that fit in uint32 are used for configuring DMA.*/
                Mcl_DmaUpdateDestAddress(Mcl_DmaChannel, (uint32)Icu_aBuffer[Channel]);

                if (Icu_aBufferSize[Channel] > (Icu_aBufferNotify[Channel] - Icu_aNotifyCount[Channel]))
                {
                    Mcl_DmaUpdateIterCount(Mcl_DmaChannel, Icu_aBufferNotify[Channel] - Icu_aNotifyCount[Channel]);
                }
            }
            else /* if linear buffer stop the timestamp*/
            {
                Icu_Ipw_StopTimestamp(Channel, &Icu_pCfgPtr->IpConfig);
                Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);
            }
        }
        else
        {
            if (crtIterCount < Icu_aBufferNotify[Channel])
            {
                Mcl_DmaUpdateIterCount(Mcl_DmaChannel, Icu_aBufferNotify[Channel]);
            }
            if (noOfBufferElemToFill < Icu_aBufferNotify[Channel])
            {
                Mcl_DmaUpdateIterCount(Mcl_DmaChannel, noOfBufferElemToFill);
            }
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_03();
}
#endif /* #if (ICU_TIMESTAMP_USES_DMA == STD_ON) */
#if (ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON)
/**
* @brief      This function saves the value of Measurement in the internal buffer
*
* @param[in]  Channel            Numeric identifier of the ICU channel
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void,ICU_CODE) Icu_SignalMeasurementDmaProcessing(VAR(Icu_ChannelType, AUTOMATIC)Channel)
{
    VAR (uint8,                            AUTOMATIC) u8index;
    VAR(Icu_ValueType,                     AUTOMATIC) BufferValue1;
    VAR(Icu_ValueType,                     AUTOMATIC) BufferValue2;
    VAR(Icu_ValueType,                     AUTOMATIC) BufferValue3;
    VAR (Mcl_ChannelType,                  AUTOMATIC) Mcl_DmaChannel =(*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Mcl_DmaChannel;
    VAR(Icu_ActivationType,                AUTOMATIC) Activation = ICU_BOTH_EDGES;

    Mcl_DmaDisableHwRequest(Mcl_DmaChannel);
    if((uint32)1 == Icu_aIsSecondInterrupt[Channel])
    {
        BufferValue1 = Icu_aFirstEdgeTimeStamp[Channel];
        BufferValue2 = Icu_aDmaBuffer[Channel][0];
        BufferValue3 = Icu_aDmaBuffer[Channel][1];
        /* @violates @ref Icu_c_REF_7 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Icu_c_REF_11 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Compiler_Warning: This warning is thrown because of a conversion between a Icu_ValyeType pointer and a uint32 */
        Mcl_DmaUpdateDestAddress(Mcl_DmaChannel, (uint32)&Icu_aDmaBuffer[Channel][0]);

        /* Store the aPeriod value */
        if(BufferValue2 > BufferValue1)
        {
            Icu_aActivePulseWidth[Channel] = BufferValue2 - BufferValue1;
        }
        else
        {
            Icu_aActivePulseWidth[Channel] = (ICU_CAPTURE_REGISTER_MASK - BufferValue1) + BufferValue2;
        }

        /* Store the aPeriod value */
        if(BufferValue3 > BufferValue1)
        {
            Icu_aPeriod[Channel] =  BufferValue3 - BufferValue1;
        }
        else
        {
            Icu_aPeriod[Channel] = (ICU_CAPTURE_REGISTER_MASK - BufferValue1) + BufferValue3;
        }
        /* Reset checking interrupt global variable*/
        Icu_aIsSecondInterrupt[Channel] = (uint32)0;
    }
    else
    {
        Icu_aIsSecondInterrupt[Channel] = (uint32)1;
        Icu_aFirstEdgeTimeStamp[Channel] = Icu_aDmaBuffer[Channel][0];
        /* @violates @ref Icu_c_REF_7 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Icu_c_REF_11 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Compiler_Warning: This warning is thrown because of a conversion between a Icu_ValyeType pointer and a uint32 */
        Mcl_DmaUpdateDestAddress(Mcl_DmaChannel, (uint32)&Icu_aDmaBuffer[Channel][0]);
        Mcl_DmaUpdateIterCount(Mcl_DmaChannel, (uint16)ICU_DMA_MAJORLOOP_COUNT);
        Mcl_DmaEnableHwRequest(Mcl_DmaChannel);
        for(u8index = 0U; u8index < ICU_DMA_MAJORLOOP_COUNT; u8index++)
        {
            Icu_aDmaBuffer[Channel][u8index] = (uint32)0;
        }
        Icu_Ipw_SetActivationCondition( Channel, Activation,
                                        (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Mode,
                                        &Icu_pCfgPtr->IpConfig
                                       );
    }
    Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
}
#endif/* ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON */

#if (ICU_TIMESTAMP_API == STD_ON)
/**
 * @brief      This function saves the value of timestamps in the internal buffer
*
* @param[in]  Channel            Numeric identifier of the ICU channel
* @param[in]  capturedWords      The number of measurements saved
* @param[in]  bufferPtr          buffer with timestamp measurements
* @param[in]  overflow           Parameter that indicates the source of report is an overflow *
 * @return  Icu_LevelType
 *
 * @pre        Icu_Init must be called before.
 *
 * @implements Icu_Timestamp_Activity
 *
 * */
FUNC(void,ICU_CODE) Icu_Timestamp(VAR(Icu_ChannelType, AUTOMATIC)hwChannel,
                                  VAR(uint8, AUTOMATIC) u8CapturedWords,
                                  P2CONST(Icu_ValueType, AUTOMATIC, ICU_APPL_CONST)pBufferPtr,
                                  VAR(boolean, AUTOMATIC) bOverflow
                                 )
{
    VAR(Icu_ChannelType, AUTOMATIC) Channel = (*(Icu_pCfgPtr->Icu_HwMap))[hwChannel];
    VAR(uint8, AUTOMATIC) u8Word;

    Icu_ReportWakeupAndOverflow(hwChannel, bOverflow);
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_04();
    {
        CONST(Icu_IndexType, ICU_CONST) chBufferSize   = Icu_aBufferSize[Channel] ;
        CONST(Icu_IndexType, ICU_CONST) chBufferNotify = Icu_aBufferNotify[Channel] ;

        VAR(boolean, AUTOMATIC) bReturnValue = (boolean)TRUE;

        for (u8Word = 0U; u8Word < u8CapturedWords; u8Word++)
        {
            /*
            * @violates @ref Icu_c_REF_4 Array indexing shall be the only allowed form of
            *                 pointer arithmetic.
            */
            Icu_aBuffer[Channel][Icu_aBufferIndex[Channel]] = *(pBufferPtr + u8Word);
            Icu_aBufferIndex[Channel]++;

            if (Icu_aBufferIndex[Channel] >= chBufferSize)
            {
                /* If circular buffer, loop; if linear buffer, terminate. */
                if ((uint8) ICU_CIRCULAR_BUFFER ==  \
                    (*(Icu_pCfgPtr->Icu_ChannelConfigPtr))[Channel].Icu_Channel_Property
                   )
                {
                    Icu_aBufferIndex[Channel] = 0U;
                }
                else
                {
                    /* Linear buffer is full, stop the channel */
                    Icu_Ipw_StopTimestamp(Channel, &Icu_pCfgPtr->IpConfig);
                    Icu_ClearBitChState(Channel, ICU_CHANNEL_STATE_RUNNING);

                    /* Don't process the rest of the captured time stamps */
                    bReturnValue = (boolean)FALSE;
                }
            }

            if (0U != chBufferNotify)
            {
                Icu_aNotifyCount[Channel]++;
                if (Icu_aNotifyCount[Channel] >= chBufferNotify)
                {
                    Icu_aNotifyCount[Channel] = 0U;
                    /* Call User Notification Function and/or Wakeup Function */
                    Icu_CallNotification(Channel);
                }
            }

            /* Don't process the rest of the captured time stamps */
            if ((boolean)FALSE == bReturnValue)
            {
                break;
            }
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_04();
}
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      This function pass up the information for a signal measurement channel.
* @details    This function pass up the information for a signal measurement channel, after the
*             measurement has occurred.
*
* @param[in]  hwChannel          Numeric identifier of the ICU channel
* @param[in]  activePulseWidth   Active pulse value measured
* @param[in]  period               Period value measured
* @param[in]  overflow           Parameter that indicates the source of report is an overflow
*
* @return     void
* @implements Icu_SignalMeasurement_Activity
* @pre        Icu_Init must be called before.
* */
FUNC(void,ICU_CODE) Icu_SignalMeasurement(VAR(Icu_ChannelType, AUTOMATIC)hwChannel,
                                          VAR(Icu_ValueType, AUTOMATIC)activePulseWidth,
                                          VAR(Icu_ValueType, AUTOMATIC)period,
                                          VAR(boolean, AUTOMATIC) bOverflow
                                         )
{
    VAR(Icu_ChannelType, AUTOMATIC) Channel = (*(Icu_pCfgPtr->Icu_HwMap))[hwChannel];
    CONST(Icu_ChannelType, ICU_CONST) msChannel = Channel;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_07();
    {
        Icu_aActivePulseWidth[msChannel] = activePulseWidth;
        Icu_aPeriod[msChannel] = period;
        Icu_SetBitChState(Channel, ICU_CHANNEL_STATE_IDLE);
        Icu_ReportWakeupAndOverflow(hwChannel, bOverflow);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_07();
}
#endif

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || \
                                                                    (ICU_TIMESTAMP_API == STD_ON)))
/**
* @brief   This function starts the measurement of signals.
* @details. This service returns the value of Capture register.
*   This API is used to measure the time difference  between 2 different timer channels.
*
* @param[in]     Channel : Numeric identifier of the ICU channel
*
* @return Icu_ValueType -  Value of Capture register
* @api
* @pre Icu_Init must be called before.
* @pre The given channel must be configured in SignalMeasurement or in Timestamp mode
* @implements Icu_GetCaptureRegisterValue_Activity
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(Icu_ValueType, ICU_CODE) Icu_GetCaptureRegisterValue(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
    VAR(Icu_ValueType, AUTOMATIC) tempValue = (Icu_ValueType)0U;
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) validchannel = Icu_ValidateCallAndChannel \
                (Channel,((uint8)ICU_MODE_SIGNAL_MEASUREMENT | (uint8)ICU_MODE_TIMESTAMP), ICU_GET_CAPTURE_REGISTER_VALUE_ID);

    if ((Std_ReturnType)E_OK == validchannel)
    {
#endif
        /* @violates @ref Icu_c_REF_9 Violates MISRA 2004 Required Rule 10.1 shall not be implicitly converted */
        tempValue = (Icu_ValueType)Icu_Ipw_GetCaptureRegisterValue(Channel, &Icu_pCfgPtr->IpConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    }
#endif
    return tempValue;
}
#endif

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))

/**
* @brief      This function returns the signals High time, Low time and Period without using the
              channel interrupt.
* @details    This function returns the signals High time, Low time and Period without using the
              channel interrupt.
* @param[in]  Channel       Numeric identifier of the ICU channel
* @pre        Icu_Init must be called before.
* @violates @ref Icu_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, ICU_CODE) Icu_GetPulseWidth(VAR(Icu_ChannelType, AUTOMATIC) Channel)
{
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
    VAR(Std_ReturnType,AUTOMATIC) validchannel1 = Icu_ValidateCallAndChannel \
                (Channel,(uint8)ICU_MODE_SIGNAL_MEASUREMENT, ICU_GET_PULSE_WIDTH_ID);

    if ((Std_ReturnType)E_OK == validchannel1)
    {
        if((Std_ReturnType)E_OK == Icu_ValidateSignalMeasureWithoutInterrupt(Channel, ICU_GET_PULSE_WIDTH_ID))
        {
#endif
            Icu_Ipw_GetPulseWidth(Channel, &Icu_pCfgPtr->IpConfig);
#if (ICU_VALIDATE_CALL_AND_CHANNEL == STD_ON)
        }
    }
#endif
}
#endif

#define ICU_STOP_SEC_CODE
/*
 * @violates @ref Icu_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 * and comments before  "#include".
 */
/*
 * @violates @ref Icu_c_REF_2 precautions to prevent the contents
 *        of a header file being included twice
 */
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif


/* End of file */
/** @} */
