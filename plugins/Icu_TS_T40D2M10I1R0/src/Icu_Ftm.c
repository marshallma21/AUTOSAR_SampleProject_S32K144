/**
*     @file          Icu_Ftm.c
*     @version 1.0.1
*
*     @brief   AUTOSAR Icu - Ftm source file support for ICU driver.
*     @details Ftm source file, containing the variables and functions that are exported by the
*              Ftm driver.
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
*     ((c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================

==================================================================================================*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Ftm_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*          "#include"
*          This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar
*          requirement MEMMAP003.
*
* @section Icu_Ftm_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_Ftm_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external
*          identifiers
*          The defines are validated.
*
* @section Icu_Ftm_c_REF_4
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*          pointer to a function and a type other than an integral type. This violation is due to
*          the pointer arithmetic used to write/ read the data to/from the registers
*
* @section Icu_Ftm_c_REF_5
*          Violates MISRA 2004 Required Rule 16.10, If a function returns error information that
*          information must be tested.
*          In this case the function does not return error information  and the information returned
*          is not relevant.
* @section Icu_Ftm_c_REF_6
*          Violates MISRA 2004 Required Rule 8.10, could be made static
*          The respective code could not be made static because of layers architecture design of the
*          driver.
*
* @section Icu_Ftm_c_REF_7
*           Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
*           and an integral type.
*
* @section Icu_Ftm_c_REF_8
*          Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer
*          type shall not be implicitly converted to a different underlying type.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*
*/
#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Compiler.h"
#include "Std_Types.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#ifndef USER_MODE_REG_PROT_ENABLED
    #define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#endif
#include "SilRegMacros.h"

#include "Icu_Ftm.h"
#include "Reg_eSys_Ftm.h"

#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Irq.h"

#include "Ftm_Common_Types.h"

/*==================================================================================================
*                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_FTM_VENDOR_ID_C         43
/* @violates @ref Icu_Ftm_c_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_FTM_AR_RELEASE_MAJOR_VERSION_C  4
/* @violates @ref Icu_Ftm_c_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_FTM_AR_RELEASE_MINOR_VERSION_C  2
/* @violates @ref Icu_Ftm_c_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_FTM_AR_RELEASE_REVISION_VERSION_C  2
#define ICU_FTM_SW_MAJOR_VERSION_C  1
#define ICU_FTM_SW_MINOR_VERSION_C  0
#define ICU_FTM_SW_PATCH_VERSION_C  1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != COMPILER_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Ftm.c and Compiler.h are different"
    #endif
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Ftm.c and Std_Types.h are different"
    #endif
#endif


#if (ICU_FTM_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
#error "Icu_Ftm.c and Icu_Cfg.h have different vendor IDs"
#endif

/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Ftm.c are different"
    #endif

/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_FTM_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_FTM_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_Ftm.c and Icu_Cfg.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Ftm.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if Icu_Ftm.c and Icu_Ftm.h file are of the same vendor */
#if (ICU_FTM_VENDOR_ID_C != ICU_FTM_VENDOR_ID)
#error "Icu_Ftm.c and Icu_Ftm.h have different vendor IDs"
#endif

/* Check if source file and Icu_Ftm header file are of the same Autosar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != ICU_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != ICU_FTM_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION_C != ICU_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.c and Icu_Ftm.h are different"
    #endif

/* Check if source file and Icu_Ftm header file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION_C != ICU_FTM_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION_C != ICU_FTM_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION_C != ICU_FTM_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.c and Icu_Ftm.h are different"
#endif


/* Check if Icu_Ftm.c and Reg_eSys_Ftm.h file are of the same vendor */
#if (ICU_FTM_VENDOR_ID_C != REG_ESYS_FTM_VENDOR_ID)
#error "Icu_Ftm.c and Reg_eSys_Ftm.h have different vendor IDs"
#endif

    /* Check if Icu_Ftm.c and Reg_eSys_Ftm.h file are of the same Autosar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.c and Reg_eSys_Ftm.h are different"
    #endif
/* Check if Icu_Ftm.c and Reg_eSys_Ftm.h file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION_C != REG_ESYS_FTM_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION_C != REG_ESYS_FTM_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION_C != REG_ESYS_FTM_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.c and Reg_eSys_Ftm.h are different"
#endif


/* Check if Icu_Ftm.c and Icu_Ipw_Types.h file are of the same vendor */
#if (ICU_FTM_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
#error "Icu_Ftm.c and Icu_Ipw_Types.h have different vendor IDs"
#endif

/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.c and Icu_Ipw_Types.h are different"
    #endif

/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.c and Icu_Ipw_Types.h are different"
#endif


/* Check if Icu_Ftm.c and Icu_Ipw_Irq.h file are of the same vendor */
#if (ICU_FTM_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
#error "Icu_Ftm.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif

/* Check if source file and Icu_Ipw_Irq header file are of the same Autosar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.c and Icu_Ipw_Irq.h are different"
    #endif

/* Check if source file and Icu_Ipw_Irq header file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.c and Icu_Ipw_Irq.h are different"
#endif


/* Check if Icu_Ftm.c and Ftm_Common_Types.h file are of the same vendor */
#if (ICU_FTM_VENDOR_ID_C != FTM_COMMON_TYPES_VENDOR_ID)
#error "Icu_Ftm.c and Ftm_Common_Types.h have different vendor IDs"
#endif

    /* Check if Icu_Ftm.c and Ftm_Common_Types.h file are of the same Autosar version */
#if ((ICU_FTM_AR_RELEASE_MAJOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_MINOR_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_FTM_AR_RELEASE_REVISION_VERSION_C != FTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Ftm.c and Ftm_Common_Types.h are different"
    #endif
/* Check if Icu_Ftm.c and Ftm_Common_Types.h file are of the same Software version */
#if ((ICU_FTM_SW_MAJOR_VERSION_C != FTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (ICU_FTM_SW_MINOR_VERSION_C != FTM_COMMON_TYPES_SW_MINOR_VERSION) || \
     (ICU_FTM_SW_PATCH_VERSION_C != FTM_COMMON_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ftm.c and Ftm_Common_Types.h are different"
#endif


/**@}*/
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef uint16 Icu_Ftm_ChConfigType;

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/

#define FTM_ICU_MEAS_MODE_MASK_U16            ((uint16)(BIT8|BIT7|BIT6|BIT5|BIT4))
#define FTM_ICU_MEAS_MODE_SHIFT_U16           (4U)

#define FTM_ICU_MEAS_PROPERTY_MASK_U16        ((uint16)(BIT3|BIT2|BIT1|BIT0))
#define FTM_ICU_MEAS_PROPERTY_SHIFT_U16       (0U)

#define FTM_ICU_CH_INITIALIZED_MASK_U16       ((uint16)BIT9)

#define FTM_ICU_EDGE_CAPTURE_MASK_U16         ((uint16)(BIT11|BIT10))
#define FTM_ICU_EDGE_CAPTURE_SHIFT_U16        (10U)

#define FTM_ICU_OVERFLOW_MASK_U16             ((uint16)BIT12)
#define FTM_ICU_OVERFLOW_SHIFT_U16            (12U)

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

#if (ICU_TIMESTAMP_API == STD_ON)
static VAR(Icu_ValueType,ICU_VAR) Icu_Ftm_aBufferPtr[ICU_MAX_FTM_CHANNELS];
#endif /* ICU_TIMESTAMP_API == STD_ON */

#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

static VAR(Icu_Ftm_ChConfigType, ICU_VAR) Icu_Ftm_aChConfig[ICU_MAX_FTM_CHANNELS] =
                                                                               {
                                                                                (uint16)0
                                                                               };

#define ICU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_8
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
static VAR(uint8, ICU_VAR) Icu_Ftm_u8FirstEdge[ICU_MAX_FTM_CHANNELS] =
                                                           {
                                                            (uint8)0
                                                           };
#endif /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

#define ICU_STOP_SEC_VAR_INIT_8
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_16
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

#if (ICU_EDGE_COUNT_API == STD_ON)
static VAR(uint16, ICU_VAR) Icu_Ftm_u16EdgeNumbers[ICU_MAX_FTM_CHANNELS] =
                                                           {
                                                            (uint16)0
                                                           };
#endif  /* ICU_EDGE_COUNT_API */

    
#define ICU_STOP_SEC_VAR_INIT_16
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_SetChConfig(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                VAR(Icu_Ftm_ChConfigType, AUTOMATIC) mask);

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_ClearChConfig(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                  VAR(Icu_Ftm_ChConfigType, AUTOMATIC) mask);

LOCAL_INLINE FUNC(Icu_Ftm_ChConfigType, ICU_CODE) Icu_Ftm_GetChConfig(
                                                    VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                    VAR(Icu_Ftm_ChConfigType, AUTOMATIC) mask);

LOCAL_INLINE FUNC(boolean, ICU_CODE) Icu_Ftm_GetStatusFlags(
                                                    VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_ClearStatusFlags(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_StartChannel(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_StopChannel(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel);

#if (ICU_TIMESTAMP_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_Timestamp(
                                                CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) overflow);
#endif /* #if (ICU_TIMESTAMP_API == STD_ON) */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_SignalMeasurement(
                                                  CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                  VAR(boolean, AUTOMATIC) bOverflow);
#endif /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/**
* @brief      Icu_Ftm_SetChConfig
* @details    Set the Icu_Ftm_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE \
    FUNC(void, ICU_CODE) Icu_Ftm_SetChConfig(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                VAR(Icu_Ftm_ChConfigType, AUTOMATIC) mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13();
    Icu_Ftm_aChConfig[hwChannel] |= mask;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13();
}


/**
* @brief      Icu_Ftm_ClearChConfig
* @details    Clear the Icu_Ftm_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE\
    FUNC(void, ICU_CODE) Icu_Ftm_ClearChConfig(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                  VAR(Icu_Ftm_ChConfigType, AUTOMATIC) mask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13();
    Icu_Ftm_aChConfig[hwChannel]  &= ((Icu_Ftm_ChConfigType)(~mask));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13();
}

/**
 * @brief      Icu_Ftm_GetChConfig
 * @details    Return the Icu_Ftm_aChConfig bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]      hwChannel  - The index of ICU channel for current configuration structure
 * @param[in]      mask    - bitfield mask
 * @return         Bitfield specified by mask parameter
 */
LOCAL_INLINE\
    FUNC(Icu_Ftm_ChConfigType, ICU_CODE) Icu_Ftm_GetChConfig(
                                                    VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                    VAR(Icu_Ftm_ChConfigType, AUTOMATIC) mask)
{
    return (Icu_Ftm_aChConfig[hwChannel] & mask);
}

/**
* @brief      Icu_Ftm_GetStatusFlags
* @details    Returns the flags set only for the enabled interrupts
*
* @param[in]   hwChannel - Ftm Hardware Channel
*
* @return      Flags set for enabled interrupts
*
* */
LOCAL_INLINE FUNC(boolean, ICU_CODE) Icu_Ftm_GetStatusFlags(
                                                    VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);
    VAR(boolean, AUTOMATIC) bInterruptStatus = (boolean)FALSE;

    /* Check if a the Ftm interrupt enable and interrupt active flags are on */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    VAR(uint32, AUTOMATIC) u32RegFtmCSC = \
                            REG_READ32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx));

    if (((uint32)1U == ((u32RegFtmCSC & FTM_CSC_CHF_MASK_U32) >> FTM_CSC_CHF_SHIFT)) &&
        ((uint32)1U == ((u32RegFtmCSC & FTM_CSC_CHIE_MASK_U32) >> FTM_CSC_CHIE_SHIFT)))
    {
        bInterruptStatus = (boolean)TRUE;
    }
    return bInterruptStatus;
}


/**
* @brief      Icu_Ftm_ClearStatusFlags
* @details    Clear the flags set only for selected interrupts that are enabled
*
* @param[in]      hwChannel - Ftm Hardware Channel
* @param[in]      bitMask   - flags to be cleared
*
* @return void
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_ClearStatusFlags(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    /* Clear  the status and interrupt enable flags for the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);
    /* Clear overflow flag */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOF_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}


/**
* @brief      Icu_Ftm_StartChannel
* @details    Start the channel by setting the edge detection
*
* @param[in]      hwChannel - Ftm Hardware Channel
*
* @return void
*
* */
LOCAL_INLINE \
FUNC(void, ICU_CODE) Icu_Ftm_StartChannel(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    /* Start the Ftm channel depending on the given configuration */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), \
              FTM_CSC_ELSA_MASK_U32|FTM_CSC_ELSB_MASK_U32, \
              (((uint32)(Icu_Ftm_GetChConfig(hwChannel, FTM_ICU_EDGE_CAPTURE_MASK_U16)) >> \
              FTM_ICU_EDGE_CAPTURE_SHIFT_U16) << FTM_CSC_ELSA_SHIFT));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}

/**
* @brief      Icu_Ftm_StopChannel
* @details    Start the channel by disable the edge detection
*
* @param[in]      hwChannel - Ftm Hardware Channel
*
* @return void
*
* */
LOCAL_INLINE \
FUNC(void, ICU_CODE) Icu_Ftm_StopChannel(VAR(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    /* Clear the pin for use by the Ftm */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), \
              FTM_CSC_ELSA_MASK_U32|FTM_CSC_ELSB_MASK_U32, \
              0U);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}

#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu_Ftm_Timestamp - process the timestamp data
*
* @param[in]   hwChannel   - Ftm encoded hardware channel
* @param[in]   overflow    - Parameter that indicates the source of report is an overflow
* @return      void
*
* @return void
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_Timestamp(
                                                CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                VAR(boolean, AUTOMATIC) overflow)
{
    VAR(uint8,   AUTOMATIC) u8CapturedWords = 1U;
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    /* Copy the Counter value in the Timestamp Buffer*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    Icu_Ftm_aBufferPtr[hwChannel]= (uint32)REG_READ32(FTM_CV_ADDR32(u8ModuleIdx,u8ChannelIdx));

    /* saves the value of timestamps in the internal buffer */
    Icu_Ipw_Timestamp(FTM_ICU_CHANNEL(hwChannel), u8CapturedWords ,&Icu_Ftm_aBufferPtr[hwChannel],overflow);
}
#endif /* #if (ICU_TIMESTAMP_API == STD_ON) */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_Ftm_SignalMeasurement - process the signal measurement data
*
* @param[in]   hwChannel   - Ftm encoded hardware channel
* @param[in]   bOverflow   - Parameter that indicates the source of report is an overflow
*
* @return void
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Ftm_SignalMeasurement(
                                                  CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
                                                  VAR(boolean, AUTOMATIC) bOverflow)
{
    static VAR(uint16, ICU_VAR) Icu_Ftm_u16ActivationPulseTemp[ICU_MAX_FTM_CHANNELS] =
                                                                {
                                                                 (uint16)0
                                                                };
    VAR(Ftm_IcuSignalMeasurementPropertyType, AUTOMATIC) measurement_property = \
          (Ftm_IcuSignalMeasurementPropertyType)(Icu_Ftm_GetChConfig(hwChannel,\
          FTM_ICU_MEAS_PROPERTY_MASK_U16) >> FTM_ICU_MEAS_PROPERTY_SHIFT_U16);
    VAR(uint32,AUTOMATIC) u32ActivePulseWidth;
    VAR(uint32,AUTOMATIC) u32Period;
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    if ((FTM_ICU_HIGH_TIME == measurement_property) ||
        (FTM_ICU_LOW_TIME == measurement_property)
       )
    {
        /* Save Channel Value (CV) for the n and n+1 hardware channels */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        VAR(uint32, AUTOMATIC) u32regFtmCnV = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx - 1U));
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        VAR(uint32, AUTOMATIC) u32regFtmCn1V = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));

        /* Calculate Active Pulse Width and call the IPW */
        if(u32regFtmCn1V > u32regFtmCnV)
        {
            u32ActivePulseWidth = (uint32)(u32regFtmCn1V - u32regFtmCnV);
        }
        else
        { /* precessing for overflow */
            u32ActivePulseWidth = (uint32)(FTM_MAX_VAL_COUNTER_U32 - u32regFtmCnV) + u32regFtmCn1V + (uint32)1;
        }
        Icu_Ipw_SignalMeasurement(FTM_ICU_CHANNEL((uint16)(hwChannel) - (Ftm_IcuChannelType)1), u32ActivePulseWidth, \
                                 (boolean)0, bOverflow);
    }
    else if (FTM_ICU_PERIOD_TIME == measurement_property)
    {
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        VAR(uint32, AUTOMATIC) u32regFtmCn1V = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));

        if (Icu_Ftm_u8FirstEdge[hwChannel])
        {
            /* If the edge detected is the second one, reset the counter */
            Icu_Ftm_u16ActivationPulseTemp[hwChannel] = (uint16)u32regFtmCn1V;
            Icu_Ftm_u8FirstEdge[hwChannel] = (uint8)0;
        }
        else
        {
            /* If the edge detected is the first one, compute the Period and call the IPW */
            if(u32regFtmCn1V > Icu_Ftm_u16ActivationPulseTemp[hwChannel])
            {
                u32Period = (uint32)u32regFtmCn1V - Icu_Ftm_u16ActivationPulseTemp[hwChannel];
            }
            else
            { /* precessing for overflow */
                u32Period = (uint32)(FTM_MAX_VAL_COUNTER_U32  - Icu_Ftm_u16ActivationPulseTemp[hwChannel]) + u32regFtmCn1V + (uint32)1;
            }
            Icu_Ftm_u16ActivationPulseTemp[hwChannel] = (uint16)u32regFtmCn1V;
            Icu_Ipw_SignalMeasurement(FTM_ICU_CHANNEL(hwChannel), (uint16)0, u32Period, bOverflow);
        }
    }
    else if (FTM_ICU_DUTY_CYCLE == measurement_property)
    {
        /* if it's the first activation edge remove from queue*/
        if (Icu_Ftm_u8FirstEdge[hwChannel])
        {
            /* Save the Counter Value (CV) for the n and the n+1 channels */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            VAR(uint32, AUTOMATIC) u32edgeChanneln = REG_READ32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx));
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            VAR(uint32, AUTOMATIC) u32edgeChanneln1 = REG_READ32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx + 1U));

            /* Save Activation Pulse Temp */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            Icu_Ftm_u16ActivationPulseTemp[hwChannel] = (uint16)(REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx)));

            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14();
            /* Set the combine mode */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPENx_MASK_U32((uint32)u8ChannelIdx));
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPx_MASK_U32((uint32)u8ChannelIdx));

            /* Set the mode for the n and n+1 Ftm channels */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), \
                            FTM_CSC_MSB_MASK_U32 | FTM_CSC_MSA_MASK_U32, FTM_CSC_MSA_MASK_U32);
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), (FTM_CSC_ELSA_MASK_U32 | FTM_CSC_ELSB_MASK_U32),\
                    u32edgeChanneln1 & (FTM_CSC_ELSA_MASK_U32 | FTM_CSC_ELSB_MASK_U32));
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx + 1U), (FTM_CSC_ELSA_MASK_U32 | FTM_CSC_ELSB_MASK_U32),\
                                u32edgeChanneln & (FTM_CSC_ELSA_MASK_U32 | FTM_CSC_ELSB_MASK_U32));

            /* Clear the flag and enable interrupts for the n+1 channel */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx + 1U), FTM_CSC_CHF_MASK_U32);
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx + 1U), FTM_CSC_CHIE_MASK_U32);
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /* Clear interrupt flag on the n channel */
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14();
            Icu_Ftm_u8FirstEdge[hwChannel] = (uint8)0;
        }
        else
        {
            /* Save the Counter Value (CV) for the n and the n+1 channels */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            VAR(uint32, AUTOMATIC) u32regFtmCnV = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx - 1U));
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            VAR(uint32, AUTOMATIC) u32regFtmCn1V = REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));

            /* At the 2nd edge, compute the Period and Active Pulse Width and call the IPW */
            if(u32regFtmCn1V > Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1])
            {
                u32Period = (uint32)(u32regFtmCn1V - Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1]);
            }
            else
            { /* precessing for overflow */
                u32Period = (uint32)(FTM_MAX_VAL_COUNTER_U32 - Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1]) + u32regFtmCn1V + (uint32)1;
            }

            if(u32regFtmCnV > Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1])
            {
                u32ActivePulseWidth = (uint32)u32regFtmCnV - Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1] ;
            }
            else
            { /* precessing for overflow */
                u32ActivePulseWidth = (uint32)(FTM_MAX_VAL_COUNTER_U32 - Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1]) + u32regFtmCnV +  (uint32)1;
            }

            Icu_Ftm_u16ActivationPulseTemp[hwChannel - (Ftm_IcuChannelType)1] = (uint16)u32regFtmCn1V;
            Icu_Ipw_SignalMeasurement(FTM_ICU_CHANNEL((uint16)hwChannel - (Ftm_IcuChannelType)1),\
                                     u32ActivePulseWidth, u32Period, bOverflow);
        }
    }
    else
    {
        /* do nothing*/
    }
}
#endif /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief      Icu_Ftm_Init
* @details    Ftm function that initialize each Ftm channel
*
* @param[in]      ParamValue  - contains the parameters to initialize the hardware channel
* @param[in]      channelMode - Channel mode
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_Init
(
    P2CONST(Icu_Ftm_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pFtmIpConfig
)
{
    /* @brief Pointer to Ftm channel specific configuration */
    P2CONST(Icu_Ftm_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pFtmChannelConfig;

    VAR(Icu_Ftm_ControlType, AUTOMATIC)   nCtrlRegVal;
    /* logical channel */
    VAR(Ftm_IcuChannelType, AUTOMATIC)   nCounter;

    VAR(uint8,                 AUTOMATIC)   u8ModuleIdx;
    VAR(uint8,                 AUTOMATIC)   u8ChannelIdx;
    VAR(Icu_ActivationType,    AUTOMATIC)   edgeParam;
    VAR(Ftm_IcuActivationType,   AUTOMATIC)  activationEdge;
    VAR(uint8,                   AUTOMATIC)  u8freezeEnable;
    VAR(Ftm_IcuChannelMeasurementModeType, AUTOMATIC)  channelMode;

    VAR(uint32, AUTOMATIC) u32GlobalConfigPrescale;
    VAR(uint16, AUTOMATIC) u16GlobalConfigClkSrc;
    VAR(uint8,  AUTOMATIC) u8hwModuleNo;
    VAR(uint8,  AUTOMATIC) u8srcClk;
    VAR(uint8,  AUTOMATIC) u8prescaler;

    u16GlobalConfigClkSrc = (uint16)((pFtmIpConfig->IcuFtmGlobalConfiguration)->Icu_Ftm_GlobalConfigClkSrc);
    u32GlobalConfigPrescale = (uint32)((pFtmIpConfig->IcuFtmGlobalConfiguration)->Icu_Ftm_GlobalConfigPrescale);

    for (u8hwModuleNo = 0U ; u8hwModuleNo < ICU_NUM_FTM_HW_MODULE_U8 ; u8hwModuleNo++)
    {
        u8srcClk = (uint8)(u16GlobalConfigClkSrc & ICU_FTM_SRC_CLK_MASK_U16 );
        u8prescaler = (uint8)(u32GlobalConfigPrescale & ICU_FTM_PRESCALER_MASK_U32 );
        u16GlobalConfigClkSrc = u16GlobalConfigClkSrc >> ICU_FTM_CLK_CONFIG_WIDTH_U32;
        u32GlobalConfigPrescale = u32GlobalConfigPrescale >> ICU_FTM_PRES_CONFIG_WIDTH_U32;

        /* Filter used modules to configure */
        if (u8srcClk != (uint8)0U)
        {
            /* Sets up the global configuration for the Ftm hardware module */
            Icu_Ftm_GlobalConfiguration(u8hwModuleNo, u8srcClk, u8prescaler);
        }
    }

    /* configuration for each channel at first time*/
    for (nCounter=0U; nCounter < pFtmIpConfig->nNumChannels; nCounter++)
    {
        /* only handle FTM channels */
        pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[nCounter];
        nCtrlRegVal  = pFtmChannelConfig->nControlValue;

        u8ModuleIdx  = (uint8)(FTM_MODULE_INDEX_U8((uint8)pFtmChannelConfig->nHwChannel));
        u8ChannelIdx = (uint8)(FTM_CHANNEL_INDEX_U8((uint8)pFtmChannelConfig->nHwChannel));
        edgeParam = (Icu_ActivationType)(pFtmChannelConfig->nDefaultStartEdge);
        channelMode = (Ftm_IcuChannelMeasurementModeType)(pFtmChannelConfig->nMeasurementModeType);
        activationEdge = (Ftm_IcuActivationType)FTM_RISING_EDGE;
        u8freezeEnable  = (uint8)((nCtrlRegVal & ICU_FTM_FREEZE_MASK_U32) >> ICU_FTM_FREEZE_SHIFT_U32);

        Icu_Ftm_aChConfig[(uint8)pFtmChannelConfig->nHwChannel] = 0U;

        switch (edgeParam)
        {
            case ICU_FALLING_EDGE:
            {
                activationEdge = FTM_FALLING_EDGE;
            }
            break;
            case ICU_RISING_EDGE:
            {
                activationEdge = FTM_RISING_EDGE;
            }
            break;
            case ICU_BOTH_EDGES:
            {
                activationEdge = FTM_BOTH_EDGES;
            }
            break;
            default:
            {
            /* do nothing */
            }
            break;
        }
        Icu_Ftm_ClearChConfig
        (
            pFtmChannelConfig->nHwChannel,
            (Icu_Ftm_ChConfigType)(FTM_ICU_CH_INITIALIZED_MASK_U16| FTM_ICU_MEAS_MODE_MASK_U16 | FTM_ICU_MEAS_PROPERTY_MASK_U16)
        );

        /* Initialize with the reset value the channel status and control register */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), 0x00U);

        if (u8ChannelIdx < FTM_FILTER_MAX_NO_CH)
        {
            VAR(uint8, AUTOMATIC) u8Filt_cnt_per  = (uint8)((nCtrlRegVal & ICU_FTM_FILTER_MASK_U32) >> ICU_FTM_FILTER_SHIFT_U32);
            /* Set input filter */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(FTM_FILTER_ADDR32(u8ModuleIdx), FTM_FILTER_CHxFVAL_MASK_U32((uint32)u8ChannelIdx), \
                      (uint32)u8Filt_cnt_per << FTM_FILTER_CHxFVAL_SHIFT((uint32)u8ChannelIdx));

            /* Set input filter for the 2nd channel*/
            if(FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT == channelMode)
            {
                /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
                /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_RMW32(FTM_FILTER_ADDR32(u8ModuleIdx), FTM_FILTER_CHxFVAL_MASK_U32((uint32)u8ChannelIdx + 1U), \
                          (uint32)u8Filt_cnt_per << FTM_FILTER_CHxFVAL_SHIFT((uint32)u8ChannelIdx));
            }
        }

        /* Reset Counter Register (CNTR) */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(FTM_CNT_ADDR32(u8ModuleIdx), 0x0000U);

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
        /* Set DMA property for the channel*/
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx),FTM_CSC_DMA_MASK_U32, \
                                ((nCtrlRegVal & ICU_FTM_DMA_ENABLE_MASK_U32) >> ICU_FTM_DMA_ENABLE_SHIFT_U32) << FTM_CSC_DMA_SHIFT);
#endif
        if ((uint8)1U == u8freezeEnable)
        {
            /* Enable freeze */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, ((uint32)0x0U << FTM_CONF_BDMMODE_SHIFT));
        }
        else
        {
            /* Disable freeze */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, ((uint32)0x3U << FTM_CONF_BDMMODE_SHIFT));
        }

        Icu_Ftm_SetActivationCondition((Ftm_IcuChannelType)pFtmChannelConfig->nHwChannel, activationEdge);

        if(FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT == channelMode)
        {
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            /* Set continuous capture mode - dual edge capture*/
            REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), \
                    FTM_CSC_MSB_MASK_U32 | FTM_CSC_MSA_MASK_U32, FTM_CSC_MSA_MASK_U32);
            /* Dual Edge Capture Mode Enable */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPENx_MASK_U32((uint32)u8ChannelIdx));
            /* The dual edge captures are active */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPx_MASK_U32((uint32)u8ChannelIdx));
            Icu_Ftm_aChConfig[pFtmChannelConfig->nHwChannel + (Ftm_IcuChannelType)1] = 0U;
            Icu_Ftm_SetChConfig(pFtmChannelConfig->nHwChannel + (Ftm_IcuChannelType)1, FTM_ICU_CH_INITIALIZED_MASK_U16);
        }
        else
        {
#if (ICU_EDGE_COUNT_API == STD_ON)
            if (FTM_CHANNEL_MODE_EDGE_COUNTER == channelMode)
            {
                Icu_Ftm_u16EdgeNumbers[pFtmChannelConfig->nHwChannel] = 0U;
            }
#endif
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_MSB_MASK_U32 | FTM_CSC_MSA_MASK_U32, 0U);
        }

        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Clears Combine bit for channels */
        REG_BIT_CLEAR32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_COMBINEx_MASK_U32((uint32)u8ChannelIdx));

        Icu_Ftm_SetChConfig(pFtmChannelConfig->nHwChannel, FTM_ICU_CH_INITIALIZED_MASK_U16);
    }
}

#if (ICU_DE_INIT_API == STD_ON)
/**
* @brief      Icu_Ftm_DeInit
* @details    Ftm IP function that de-initialize an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_DeInit
(
    P2CONST(Icu_Ftm_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pFtmIpConfig
)
{
    /* @brief Pointer to Ftm channel specific configuration */
    P2CONST(Icu_Ftm_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pFtmChannelConfig;

    /* logical channel */
    VAR(Ftm_IcuChannelType,    AUTOMATIC)   nCounter;

    VAR(uint8,                 AUTOMATIC)   u8ModuleIdx;
    VAR(uint8,                 AUTOMATIC)   u8ChannelIdx;
    VAR(uint8,                 AUTOMATIC)   u8hwModuleNo;
    VAR(uint16,                AUTOMATIC)   u16GlobalConfigClkSrc;
    VAR(uint8,                 AUTOMATIC)   u8srcClk;

    u16GlobalConfigClkSrc = (uint16)((pFtmIpConfig->IcuFtmGlobalConfiguration)->Icu_Ftm_GlobalConfigClkSrc);
    
    for (u8hwModuleNo = 0U ; u8hwModuleNo < ICU_NUM_FTM_HW_MODULE_U8 ; u8hwModuleNo++)
    {
        u8srcClk = (uint8)(u16GlobalConfigClkSrc & ICU_FTM_SRC_CLK_MASK_U16 );
        u16GlobalConfigClkSrc = u16GlobalConfigClkSrc >> ICU_FTM_CLK_CONFIG_WIDTH_U32;
        
        /* Filter used modules to configure */
        if (u8srcClk != (uint8)0U)
        {
            /* Sets up the global configuration for the Ftm hardware module */
            Icu_Ftm_GlobalConfiguration((uint8)u8hwModuleNo, (uint8)0, (uint8)0);
        }
    }

    for (nCounter=0U; nCounter < pFtmIpConfig->nNumChannels; nCounter++)
    {
        /* only handle FTM channels */
        pFtmChannelConfig = &(*pFtmIpConfig->pChannelsConfig)[nCounter];

        u8ModuleIdx  = (uint8)(FTM_MODULE_INDEX_U8((uint8)pFtmChannelConfig->nHwChannel));
        u8ChannelIdx = (uint8)(FTM_CHANNEL_INDEX_U8((uint8)pFtmChannelConfig->nHwChannel));

        if (u8ChannelIdx < FTM_FILTER_MAX_NO_CH)
        {
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(FTM_FILTER_ADDR32(u8ModuleIdx), FTM_FILTER_CHxFVAL_MASK_U32((uint32)u8ChannelIdx), 0U);
        }

        /* Reset Channel Value, Channel Status And Control and Counter Registers (CV, CSC, CNT) */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx), 0x0000U);
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_WRITE32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx),0x0000U);
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(FTM_CNT_ADDR32(u8ModuleIdx),0x0000U);

        /* Reset BDMMODE bits*/
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(FTM_CONF_ADDR32(u8ModuleIdx), FTM_CONF_BDMMODE_MASK_U32, 0x0U);

        /* Clear Combine bit for the Ftm channel */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_COMBINEx_MASK_U32((uint32)u8ChannelIdx));
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/

        Icu_Ftm_ClearChConfig
        (
            pFtmChannelConfig->nHwChannel,
            (Icu_Ftm_ChConfigType)(FTM_ICU_CH_INITIALIZED_MASK_U16 | FTM_ICU_MEAS_MODE_MASK_U16 | \
                                    FTM_ICU_MEAS_PROPERTY_MASK_U16 | FTM_ICU_EDGE_CAPTURE_MASK_U16)
        );
   }
}
#endif /* ICU_DE_INIT_API == STD_ON */

#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief      Icu_Ftm_SetSleepMode
* @details
*
* @param[in]     hwChannel     - Ftm encoded hardware channel
* @param[in]     WakeUpEnabled - specifies if channel is wake-up enabled
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_SetSleepMode(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    /* Disable Ftm mod on the output pin */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), \
                    FTM_CSC_ELSA_MASK_U32|FTM_CSC_ELSB_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}

/**
* @brief      Icu_Ftm_SetNormalMode
* @details
*
* @param[in]     hwChannel          - Ftm encoded hardware channel
* @param[in]     NotificationActive - specifies if channel has notification activated
*
* @return void
*
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_SetNormalMode(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    if (Icu_Ftm_GetChConfig(hwChannel, FTM_ICU_MEAS_MODE_MASK_U16) != 0x0U)
    {
        /* Set the Ftm channel to the configured activation type */
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), \
                FTM_CSC_ELSA_MASK_U32|FTM_CSC_ELSB_MASK_U32, \
                (((uint32)(Icu_Ftm_GetChConfig(hwChannel, FTM_ICU_EDGE_CAPTURE_MASK_U16)) >> FTM_ICU_EDGE_CAPTURE_SHIFT_U16) << FTM_CSC_ELSA_SHIFT));
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
    }
}
#endif  /* ICU_SET_MODE_API */


/**
* @brief      Icu_Ftm_SetActivationCondition
* @details    Ftm IP function that sets up the activation condition
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
* @param[in]      channelMode - Ftm channel mode
* @param[in]      Activation  - edge activation type
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_SetActivationCondition
(
    CONST(Ftm_IcuChannelType,    AUTOMATIC) hwChannel,
    CONST(Ftm_IcuActivationType, AUTOMATIC) Activation
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    /* Set activation condition in the configuration array */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    Icu_Ftm_ClearChConfig(hwChannel, (Icu_Ftm_ChConfigType)FTM_ICU_EDGE_CAPTURE_MASK_U16);
    Icu_Ftm_SetChConfig(hwChannel, (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)Activation << FTM_ICU_EDGE_CAPTURE_SHIFT_U16));

    if (Icu_Ftm_GetChConfig(hwChannel, FTM_ICU_MEAS_MODE_MASK_U16) != 0x0U)
    {
        /* Set activation condition in the Channel Status and Control Register (CSCR) */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), \
                FTM_CSC_ELSA_MASK_U32|FTM_CSC_ELSB_MASK_U32, \
                ((uint32)Activation << FTM_CSC_ELSA_SHIFT));
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}


#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief      Icu_Ftm_EnableEdgeDetection
* @details    Ftm IP function that starts the edge detection service for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_EnableEdgeDetection(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    Icu_Ftm_StartChannel(hwChannel);

    /* Clear pending interrupt serviced*/
    Icu_Ftm_ClearStatusFlags(hwChannel);

    /* Set Edge Detect mode for the Ftm channel in the configuration array */
    Icu_Ftm_SetChConfig(hwChannel, \
          (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT\
                                                         << FTM_ICU_MEAS_MODE_SHIFT_U16));

    /* Enable interrupts on the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief      Icu_Ftm_DisbleEdgeDetection
* @details    Ftm IP function that starts the timestamp service for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_DisableEdgeDetection(CONST(Ftm_IcuChannelType, AUTOMATIC)hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    /* Disable interrupts on the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
    Icu_Ftm_StopChannel(hwChannel);

    /* Clear mode for the Ftm channel in the configuration array */
    Icu_Ftm_ClearChConfig(hwChannel, \
          (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT\
                                                             << FTM_ICU_MEAS_MODE_SHIFT_U16));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu_Ftm_StartTimestamp
* @details    Ftm IP function that stops the edge detection service for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
* @param[in]      bDmaSupport  - Boolean for enabling/disabling the DMA Support
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_StartTimestamp
(
    CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
    CONST(boolean, AUTOMATIC) bDmaSupport
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    /* Reset aBufferPtr */
    Icu_Ftm_aBufferPtr[hwChannel] = 0U;
    Icu_Ftm_StartChannel(hwChannel);
    /* Clear previous flag */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), FTM_CSC_CHF_MASK_U32);
    /* Configure the Timestamp mode for the Ftm channel in the configuration array */
    if ((boolean)FALSE == bDmaSupport)
    {
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        Icu_Ftm_SetChConfig(hwChannel,  (Icu_Ftm_ChConfigType)\
                            ((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA
                                                            << FTM_ICU_MEAS_MODE_SHIFT_U16));
    }
    else
    {
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        Icu_Ftm_SetChConfig(hwChannel,  (Icu_Ftm_ChConfigType)\
                                    ((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA
                                                                    << FTM_ICU_MEAS_MODE_SHIFT_U16));
    }
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Set Timer Overflow Interrupt Enable*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOIE_MASK_U32, (uint32)1U << FTM_SC_TOIE_SHIFT);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    /* Enable interrupts on the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu_Ftm_StopTimestamp
* @details    Ftm IP function that stop the timestamp service for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_StopTimestamp(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    Icu_Ftm_StopChannel(hwChannel);

    /* Disable Interrupts on the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

 #if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Timer Overflow Interrupt*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOIE_MASK_U32, 0U);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    /* Clear the Icu_Ftm_aChConfig bitfield specified by mask parameter in an atomic way */
    Icu_Ftm_ClearChConfig(hwChannel, (Icu_Ftm_ChConfigType)\
             (((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA | \
              (Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA) \
                                                  << FTM_ICU_MEAS_MODE_SHIFT_U16));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}
#endif  /* ICU_TIMESTAMP_API */


#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/**
* @brief      Icu_Ftm_GetStartAddress
* @details    Ftm IP function that gets the source register for the DMA transfer
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(uint32, ICU_CODE) Icu_Ftm_GetStartAddress(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    return (FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));
}
#endif


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu_Ftm_ResetEdgeCount
* @details    Ftm IP function that reset the edge counting for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_ResetEdgeCount(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    /* Reset Counter Register (CNTR) */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    Icu_Ftm_u16EdgeNumbers[hwChannel] = 0U;
}
#endif  /* ICU_EDGE_COUNT_API */


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu_Ftm_EnableEdgeCount
* @details    Ftm IP function that starts the edge counting service for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_EnableEdgeCount(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    Icu_Ftm_u16EdgeNumbers[hwChannel] = 0U;
    Icu_Ftm_StartChannel(hwChannel);

#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Set Timer Overflow Interrupt Enable*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOIE_MASK_U32, (uint32)1U << FTM_SC_TOIE_SHIFT);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    Icu_Ftm_SetChConfig(hwChannel,\
                (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_EDGE_COUNTER\
                                                                   << FTM_ICU_MEAS_MODE_SHIFT_U16));

    /* Enable Interrupts on the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu_Ftm_DisableEdgeCount
* @details    Ftm IP function that disable the edge counting service for an Ftm channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_DisableEdgeCount(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    Icu_Ftm_StopChannel(hwChannel);

    /* Disable Interrupts on the Ftm channel */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

 #if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Timer Overflow Interrupt*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOIE_MASK_U32, 0U);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    Icu_Ftm_ClearChConfig(hwChannel,
                          (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_EDGE_COUNTER << FTM_ICU_MEAS_MODE_SHIFT_U16)
                         );
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu_Ftm_GetEdgeNumbers
* @details    Ftm IP function that get the edge numbers
*
* @param[in]   hwChannel   - Ftm encoded hardware channel
*
* @return      Counted edges number
*
* */
FUNC(uint16, ICU_CODE) Icu_Ftm_GetEdgeNumbers(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    return Icu_Ftm_u16EdgeNumbers[hwChannel];
}
#endif  /* ICU_EDGE_COUNT_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_Ftm_StartSignalMeasurement
* @details    Ftm IP function that start the signal measurement for an Ftm channel
*
* @param[in]     hwChannel  - Ftm encoded hardware channel
* @param[in]     Activation - edge activation type
* @param[in]     measProperty - property of signal measurement
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_StartSignalMeasurement
(
    CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel,
    CONST(Ftm_IcuActivationType, AUTOMATIC) Activation,
    CONST(Ftm_IcuSignalMeasurementPropertyType, AUTOMATIC) measProperty,
    CONST(boolean, AUTOMATIC)bDmaSupport
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    if (FTM_ICU_PERIOD_TIME == measProperty)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
        /* Set continuous capture mode - single edge capture*/
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_RMW32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), \
                FTM_CSC_MSB_MASK_U32 | FTM_CSC_MSA_MASK_U32, 0U);
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPENx_MASK_U32((uint32)u8ChannelIdx));
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPx_MASK_U32((uint32)u8ChannelIdx));
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
        REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);

        /* Check DMA support */
        if ((boolean)FALSE == bDmaSupport)
        {
            Icu_Ftm_ClearChConfig(hwChannel + (Ftm_IcuChannelType)1, FTM_ICU_CH_INITIALIZED_MASK_U16);
        }
        Icu_Ftm_u8FirstEdge[hwChannel] = (uint8)1;
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
    }
    else
    {
        /* Set activation condition for the second Ftm channel */
        switch (Activation)
        {
            case FTM_FALLING_EDGE:
            {
                Icu_Ftm_SetActivationCondition(hwChannel + (Ftm_IcuChannelType)1, FTM_RISING_EDGE);
            }
            break;
            case FTM_RISING_EDGE:
            {
                Icu_Ftm_SetActivationCondition(hwChannel + (Ftm_IcuChannelType)1, FTM_FALLING_EDGE);
            }
            break;
            case FTM_BOTH_EDGES:
            {
                Icu_Ftm_SetActivationCondition(hwChannel + (Ftm_IcuChannelType)1, FTM_BOTH_EDGES);
            }
            break;
            default:
            {
                 /* do nothing */
            }
            break;
        }
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
        if (FTM_ICU_DUTY_CYCLE == measProperty)
        {
            /* Enable interrupt on the first channel */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
            Icu_Ftm_u8FirstEdge[hwChannel] = (uint8)1;
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx), \
                    FTM_CSC_MSB_MASK_U32 | FTM_CSC_MSA_MASK_U32);

            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPENx_MASK_U32((uint32)u8ChannelIdx));
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(FTM_COMBINE_ADDR32(u8ModuleIdx), FTM_COMBINE_DECAPx_MASK_U32((uint32)u8ChannelIdx));
        }
        else
        {
            /* Set Interrupt enable flag */
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_SET32(FTM_CSC_ADDR32(u8ModuleIdx,(uint32)u8ChannelIdx + 1U), FTM_CSC_CHIE_MASK_U32);
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
        Icu_Ftm_SetChConfig(hwChannel + (Ftm_IcuChannelType)1,(Icu_Ftm_ChConfigType)\
                ((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT<< FTM_ICU_MEAS_MODE_SHIFT_U16) |\
                (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)measProperty <<FTM_ICU_MEAS_PROPERTY_SHIFT_U16));

        Icu_Ftm_StartChannel(hwChannel + (Ftm_IcuChannelType)1);
    }

    Icu_Ftm_SetChConfig(hwChannel,(Icu_Ftm_ChConfigType)\
            ((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT<< FTM_ICU_MEAS_MODE_SHIFT_U16) |\
             (Icu_Ftm_ChConfigType)((Icu_Ftm_ChConfigType)measProperty <<FTM_ICU_MEAS_PROPERTY_SHIFT_U16));

#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
    /* Set Timer Overflow Interrupt Enable*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOIE_MASK_U32, (uint32)1U << FTM_SC_TOIE_SHIFT);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    Icu_Ftm_StartChannel(hwChannel);
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu_Ftm_GetInputState
* @details    Ftm IP function that gets the input state for a channel
*
* @param[in]  hwChannel   - Ftm encoded hardware channel
*
* @return     boolean      The active/inactive state:
* @retval     true         channel is active
* @retval     false        channel is idle
*
* */
FUNC(boolean, ICU_CODE) Icu_Ftm_GetInputState(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    CONST(uint32, ICU_CONST) u32regFtmCSC = REG_BIT_GET32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx),\
                                                           FTM_CSC_CHIE_MASK_U32 | FTM_CSC_CHF_MASK_U32 );

    /* Interrupt not enabled, flag bit was set */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if (FTM_CSC_CHIE_MASK_U32 != (u32regFtmCSC & FTM_CSC_CHIE_MASK_U32))
    {
        if (FTM_CSC_CHF_MASK_U32 == (u32regFtmCSC & FTM_CSC_CHF_MASK_U32))
        {
            bResult = (boolean)TRUE;
            /* Clear interrupt flag */
            SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
            /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
            REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHF_MASK_U32);
            SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
        }
    }
    return bResult;
}
#endif  /* ICU_GET_INPUT_STATE_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_Ftm_StopSignalMeasurement
* @details    Ftm function that stops the signal measurement service for an etimer channel
*
* @param[in]      hwChannel   - Ftm encoded hardware channel
*
* @return void
*
* */
FUNC(void, ICU_CODE) Icu_Ftm_StopSignalMeasurement(
                                    CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_12();
    /* Stop both channels for Signal Measurement Mode */
    Icu_Ftm_StopChannel(hwChannel);
    Icu_Ftm_StopChannel(hwChannel + (Ftm_IcuChannelType)1);

    /*Clear interrupt and status flags for both channels */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHIE_MASK_U32);
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx + 1U), FTM_CSC_CHIE_MASK_U32);
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx,u8ChannelIdx), FTM_CSC_CHF_MASK_U32);
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    REG_BIT_CLEAR32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx + 1U), FTM_CSC_CHF_MASK_U32);

 #if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
    /* Disable Timer Overflow Interrupt*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOIE_MASK_U32, 0U);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    /* Clear the channel config for the first channel */
    Icu_Ftm_ClearChConfig(hwChannel,(Icu_Ftm_ChConfigType)\
                ((Icu_Ftm_ChConfigType)FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT << FTM_ICU_MEAS_MODE_SHIFT_U16) \
                                          | FTM_ICU_MEAS_PROPERTY_MASK_U16);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_12();
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

/**
* @brief      Icu_Ftm_GetOverflow
* @details    Ftm IP function that get the state of the overflow flag
*
* @param[in]   hwChannel   - Ftm encoded hardware channel
*
* @return      boolean      the state of the overflow flag
* @retval      true         the overflow flag is set
* @retval      false        the overflow flag is not set
*
* @return void
* @violates @ref Icu_Ftm_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* */
FUNC(boolean, ICU_CODE) Icu_Ftm_GetOverflow(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);

    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;

    VAR(uint32,  AUTOMATIC) u32regFtmSC;

    /* Get timer overflow flag */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32regFtmSC = REG_BIT_GET32(FTM_SC_ADDR32(u8ModuleIdx),FTM_SC_TOF_MASK_U32);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
    /* Clear overflow flag */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8ModuleIdx), FTM_SC_TOF_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();

    /* Get and return the state of the overflow flag */
    bResult = (FTM_SC_TOF_MASK_U32 == (u32regFtmSC & FTM_SC_TOF_MASK_U32)) ? \
            (boolean)TRUE : (boolean)FALSE;

    return bResult;
}

/**
* @brief      Icu_Ftm_ProcessInterrupt
* @details    Process the common part for Ftm interrupts
*
* @param[in]      hwChannel - Ftm hardware channel
*
* @return void
* @implements Icu_Ftm_ProcessInterrupt_Activity
* @violates @ref Icu_Ftm_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* */

FUNC(void, ICU_CODE) Icu_Ftm_ProcessInterrupt(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    VAR(uint16, AUTOMATIC) u16FtmStatusFlags = (uint16)0x0000U;
    VAR(Ftm_IcuChannelMeasurementModeType, AUTOMATIC) measMode;
    VAR(boolean, AUTOMATIC) bOverflow;

    if (FTM_ICU_CH_INITIALIZED_MASK_U16 == Icu_Ftm_GetChConfig(hwChannel, FTM_ICU_CH_INITIALIZED_MASK_U16))
    {
        /* Read Channel Status Registers : interrupt active or not*/
        u16FtmStatusFlags = Icu_Ftm_GetStatusFlags(hwChannel);
        bOverflow = Icu_Ftm_GetOverflow(hwChannel);

        /* Get Measurement Mode of channel corresponding to hwChannel */
        measMode = (Ftm_IcuChannelMeasurementModeType)\
                  (Icu_Ftm_GetChConfig(hwChannel,FTM_ICU_MEAS_MODE_MASK_U16) >> \
                                          FTM_ICU_MEAS_MODE_SHIFT_U16);

        if ((uint16)0x0 != u16FtmStatusFlags)
        {
            switch (measMode)
            {
#if (ICU_EDGE_DETECT_API == STD_ON)
                case FTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT:
                {
                    /* reports the wakeup event, overflow event and notification, if available*/
                    Icu_Ipw_ReportEvents(FTM_ICU_CHANNEL(hwChannel),bOverflow);
                }
                break;
#endif
#if (ICU_TIMESTAMP_API == STD_ON)
                case FTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA:
                {
                    /* process the timestamp data */
                    Icu_Ftm_Timestamp(hwChannel,bOverflow);
                }
                break;
#endif /* ICU_TIMESTAMP_API == STD_ON */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
                case FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT:
                {
                    Icu_Ftm_SignalMeasurement(hwChannel,bOverflow);
                }
                break;
#endif
                default: /* case FTM_CHANNEL_MODE_EDGE_COUNTER:*/
#if (ICU_EDGE_COUNT_API == STD_ON)
                {
                    Icu_Ftm_u16EdgeNumbers[hwChannel]++;
                    if (0U == Icu_Ftm_u16EdgeNumbers[hwChannel])
                    {
                        bOverflow = (boolean)TRUE;
                    }
                    else
                    {
                        bOverflow = (boolean)FALSE;  
                    }
                    Icu_Ipw_ReportWakeupAndOverflow(FTM_ICU_CHANNEL(hwChannel), bOverflow);
                }
#endif
                break;
            }
        }
    }

    /* Clear pending interrupt serviced*/
    Icu_Ftm_ClearStatusFlags(hwChannel);
}

/**
* @brief      Icu_Ftm_ProcessTofInterrupt
* @details    Processes the overflow interrupt on the Ftm Module
*
* @param[in]      u8hwModuleNo - Ftm hardware module
*
* @return void
* @violates @ref Icu_Ftm_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* */

FUNC(void, ICU_CODE) Icu_Ftm_ProcessTofInterrupt(CONST(uint8, AUTOMATIC) u8hwModuleNo)
{
    VAR(uint32, AUTOMATIC) u32TofStatus;
    VAR(uint32, AUTOMATIC) u32ToieStatus;
    VAR(uint8, AUTOMATIC) u8ChannelId;

    /*get TOF and TOIE status bit*/
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32ToieStatus = (REG_READ32(FTM_SC_ADDR32(u8hwModuleNo))) & FTM_SC_TOIE_ENABLE_U32;
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32TofStatus  = (REG_READ32(FTM_SC_ADDR32(u8hwModuleNo))) & FTM_SC_TOF_OVF_U32;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09();
    /* Clear timer overflow flag */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8hwModuleNo), FTM_SC_TOF_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09();

    /* Check FTM counter has overflowed and  TOF interrupts has enabled
    * True  : report wake-up overflow for channel in measurement mode
    * False : Nope
    */
    if((((uint32)0U) != u32TofStatus) && (((uint32)0U)  != u32ToieStatus))
    {
        for (u8ChannelId = (uint8)(u8hwModuleNo<<FTM_MOD_SHIFT); \
            u8ChannelId < ((uint8)(u8hwModuleNo<<FTM_MOD_SHIFT) + 8U); u8ChannelId++)
        {
            VAR(Ftm_IcuChannelMeasurementModeType, AUTOMATIC) measMode;

            /* Get Measurement Mode of channel corresponding to u8ChannelId */
            measMode = (Ftm_IcuChannelMeasurementModeType)\
                       (Icu_Ftm_GetChConfig(u8ChannelId, FTM_ICU_MEAS_MODE_MASK_U16) >> \
                                          FTM_ICU_MEAS_MODE_SHIFT_U16);

            if ((FTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA == measMode) ||
                (FTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA == measMode) ||
                ((FTM_CHANNEL_MODE_SIGNAL_MEASUREMENT == measMode)&& (0U == (u8ChannelId % 2U))))

            {
                Icu_Ipw_ReportWakeupAndOverflow(FTM_ICU_CHANNEL(u8ChannelId), (boolean)TRUE);
            }
        }
    }
}

/**
* @brief      Icu_Ftm_GlobalConfiguration
* @details    Sets up the global configuration for the Ftm hardware module
*
* @param[in]      u8hwModuleNo - Ftm hardware module
* @param[in]      u8srcClk - Clock source for the Ftm module
* @param[in]      u8prescaler - Clock prescaler for the Ftm module
*
* @return void
* @violates @ref Icu_Ftm_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* */
FUNC(void, ICU_CODE) Icu_Ftm_GlobalConfiguration(CONST(uint8, AUTOMATIC) u8hwModuleNo,\
                                                 CONST(uint8, AUTOMATIC) u8srcClk, \
                                                 CONST(uint8, AUTOMATIC) u8prescaler)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10();
    /* Check write protection is enabling or not 
    *  True  : If write protection is enabled, then disable it
    *  False : Nope
    */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    if ((uint32)0 != REG_BIT_GET32(FTM_FMS_ADDR32(u8hwModuleNo), FTM_FMS_WPEN_MASK_U32))
    {
        /* Disable write protection */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(FTM_MODE_ADDR32(u8hwModuleNo), FTM_MODE_WPDIS_MASK_U32);
    }
            
    /* Check module is initializing or de-initializing
    * True  : If u8srcClk different 0U, modulo is initializing
    * False : modulo is de-initializing
    */
    if (u8srcClk != (uint8)0U)
    {
        /* Reset modulo register -after reaching the maximum value the overflow flag will be set */
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(FTM_MOD_ADDR32(u8hwModuleNo),FTM_MOD_MOD_MAX_VALUE);
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Enable Ftm module */
        REG_BIT_SET32(FTM_MODE_ADDR32(u8hwModuleNo), FTM_MODE_FTMEN_MASK_U32);
    }
    else
    {
        /* Reset modulo register*/
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(FTM_MOD_ADDR32(u8hwModuleNo),0x0000U);
        /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Disable Ftm module */
        REG_BIT_CLEAR32(FTM_MODE_ADDR32(u8hwModuleNo), FTM_MODE_FTMEN_MASK_U32);
    }
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* Clear Interrupt */
    REG_BIT_CLEAR32(FTM_SC_ADDR32(u8hwModuleNo), FTM_SC_TOF_MASK_U32);
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* Set Prescaler */
    REG_RMW32(FTM_SC_ADDR32(u8hwModuleNo), FTM_SC_PS_MASK_U32, u8prescaler);
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* Set Clock Source */
    REG_RMW32(FTM_SC_ADDR32(u8hwModuleNo), FTM_SC_CLKS_MASK_U32, (uint32)u8srcClk << FTM_SC_CLKS_SHIFT);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10();
    
}

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief      This function returns the actual status of PIN.
* @details     This function returns the actual status of PIN.
*
* @param[in]     hwChannel          Numeric identifier of the ETIMER channel
*
* @return      uint16    the state of the eTimer pin
* @retval      true             the pin state is HIGH
* @retval      false            the pin state is LOW
*
* */
FUNC(uint8, ICU_CODE) Icu_Ftm_GetInputLevel(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    return (uint8)((REG_BIT_GET32(FTM_CSC_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), \
                   FTM_CSC_CHIS_MASK_U32) == FTM_CSC_CHIS_MASK_U32 )? 1U : 0U \
                  );

}
/* ICU_GET_INPUT_LEVEL_API == STD_ON */
#endif

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/**
* @brief      The function changes the FTM prescaler value.
* @details    This function sets the FTM prescaler based on the input mode.
*
* @param[in]  hwChannel         hardware channel
* @param[in]  u8ChPrescaler     prescaler value
*
* @pre     On/Off by the configuration parameter: ICU_DUAL_CLOCK_MODE_API
*
*
*/
FUNC(void, ICU_CODE) Icu_Ftm_SetPrescaler (CONST(uint8, AUTOMATIC) u8hwModuleNo, VAR(uint8, AUTOMATIC) u8ChPrescaler)
{
    /* set the prescaler with the wanted value */
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09();
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_RMW32(FTM_SC_ADDR32(u8hwModuleNo),FTM_SC_PS_MASK_U32,(uint32)u8ChPrescaler);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09();
}
#endif /*ICU_DUAL_CLOCK_MODE_API */


#if (ICU_CAPTURERGISTER_API == STD_ON)
/**
* @brief      Icu_Ftm_GetCaptureRegisterValue
* @details    Ftm IP function that returns the Capture Register Value
*
* @param[in]  hwChannel   - Ftm encoded hardware channel
*
* @return     uint16      - Value of the capture register
* @violates @ref Icu_Ftm_c_REF_6 Violates MISRA 2004 Required Rule 8.10 could be made static
* */
FUNC(uint16, ICU_CODE) Icu_Ftm_GetCaptureRegisterValue(CONST(Ftm_IcuChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)FTM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)FTM_CHANNEL_INDEX_U8(hwChannel);

    /* reads and returns the CV (capture value) */
    /** @violates @ref Icu_Ftm_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_Ftm_c_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /** @violates @ref Icu_Ftm_c_REF_8 MISRA 2004 Rule 10.1, Implicit conversion */
    return (uint16)REG_READ32(FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx));
}
#endif

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_Ftm_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_Ftm_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice.
*/
#include "Icu_MemMap.h"


#ifdef __cplusplus
}

#endif
/** @} */
