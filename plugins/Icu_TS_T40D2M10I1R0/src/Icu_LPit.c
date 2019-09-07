/**
*   @file    Icu_LPit.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - LPIT driver source file.
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : FTM PORT_CI LPIT LPTMR
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
* @section ICU_LPIT_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section ICU_LPIT_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section ICU_LPIT_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section ICU_LPIT_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section ICU_LPIT_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section ICU_LPIT_C_REF_6
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type may
* only be cast to a type that is narrower and of the same sightedness as the underlying type of the
* expression. A negative value needs to be converted to an unisgned value.
*
* @section ICU_LPIT_C_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Reg_eSys_LPit.h"
#include "Icu_LPit.h"

#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_LPIT_VENDOR_ID_C                    43
/** @violates @ref ICU_LPIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*   that 31 character significance and case sensitivity are supported for external identifiers.
*/
#define ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref ICU_LPIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*   that 31 character significance and case sensitivity are supported for external identifiers.
*/
#define ICU_LPIT_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref ICU_LPIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
*   that 31 character significance and case sensitivity are supported for external identifiers.
*/
#define ICU_LPIT_AR_RELEASE_REVISION_VERSION_C  2
#define ICU_LPIT_SW_MAJOR_VERSION_C             1
#define ICU_LPIT_SW_MINOR_VERSION_C             0
#define ICU_LPIT_SW_PATCH_VERSION_C             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_LPit.c and Mcal.h are different"
    #endif
#endif

#if (ICU_LPIT_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_LPit.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_LPIT_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_LPit.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_LPIT_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_LPIT_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_LPIT_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_LPit.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_LPit.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if source file and Reg_eSys_LPit.h file are of the same vendor */
#if (ICU_LPIT_VENDOR_ID_C != REG_ESYS_LPIT_VENDOR_ID)
#error "Icu_LPit.c and Reg_eSys_LPit.h have different vendor IDs"
#endif
#if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_LPIT_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_LPit.c and Reg_eSys_LPit.h are different"
#endif
/* Check if source file and Reg_eSys_LPit.h header file are of the same Software version */
#if ((ICU_LPIT_SW_MAJOR_VERSION_C != REG_ESYS_LPIT_SW_MAJOR_VERSION) || \
     (ICU_LPIT_SW_MINOR_VERSION_C != REG_ESYS_LPIT_SW_MINOR_VERSION) || \
     (ICU_LPIT_SW_PATCH_VERSION_C != REG_ESYS_LPIT_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LPit.c and Reg_eSys_LPit.h are different"
#endif

/* Check if source file and Icu_LPit.h file are of the same vendor */
#if (ICU_LPIT_VENDOR_ID_C != ICU_LPIT_VENDOR_ID)
#error "Icu_LPit.c and Icu_LPit.h have different vendor IDs"
#endif
    #if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != ICU_LPIT_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != ICU_LPIT_AR_RELEASE_MINOR_VERSION) || \
         (ICU_LPIT_AR_RELEASE_REVISION_VERSION_C != ICU_LPIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_LPit.c and Icu_LPit.h are different"
    #endif
/* Check if source file and Icu_LPit.h header file are of the same Software version */

#if ((ICU_LPIT_SW_MAJOR_VERSION_C != ICU_LPIT_SW_MAJOR_VERSION) || \
     (ICU_LPIT_SW_MINOR_VERSION_C != ICU_LPIT_SW_MINOR_VERSION) || \
     (ICU_LPIT_SW_PATCH_VERSION_C != ICU_LPIT_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LPit.c and Icu_LPit.h are different"
#endif

#if (ICU_LPIT_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_LPit.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_LPit.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_LPIT_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_LPIT_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_LPIT_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LPit.c and Icu_Ipw_Types.h are different"
#endif

#if (ICU_LPIT_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
    #error "Icu_LPit.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Autosar version */
#if ((ICU_LPIT_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_LPIT_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_LPit.c and Icu_Ipw_Irq.h are different"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Software version */
#if ((ICU_LPIT_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (ICU_LPIT_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
     (ICU_LPIT_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_LPit.c and Icu_Ipw_Irq.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef uint8 Icu_LPit_ChConfigType;

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define LPIT_ICU_MEAS_MODE_MASK_U8            ((uint8)(BIT3|BIT2|BIT1))
#define LPIT_ICU_MEAS_MODE_SHIFT_U8           (1U)

#define LPIT_ICU_CH_INITIALIZED_MASK_U8       ((uint8)BIT0)

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if (ICU_TIMESTAMP_API == STD_ON)
static VAR(Icu_ValueType,ICU_VAR) Icu_LPit_aBufferPtr[ICU_MAX_LPIT_CHANNELS];
#endif /* ICU_TIMESTAMP_API == STD_ON */

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref ICU_LPIT_C_REF_1 Only preprocessor statements and comments before "#include"
* @violates @ref ICU_LPIT_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*/
#include "Icu_MemMap.h"

static VAR(Icu_LPit_ChConfigType, ICU_VAR) Icu_LPit_aChConfig[ICU_MAX_LPIT_CHANNELS] = { (uint8)0U };
#define ICU_STOP_SEC_VAR_INIT_UNSPECIFIED

/**
* @violates @ref ICU_LPIT_C_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref ICU_LPIT_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/**
* @violates @ref ICU_LPIT_C_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*               comments before "#include"
* @violates @ref ICU_LPIT_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*               contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#if ((ICU_SET_MODE_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON)|| (ICU_TIMESTAMP_API == STD_ON))
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_EnableInterrupt(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel);
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_DisableInterrupt(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel);
#endif

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_SetChConfig(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                       VAR(Icu_LPit_ChConfigType,AUTOMATIC) mask
                                                      );

#if ((ICU_DE_INIT_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON)|| (ICU_TIMESTAMP_API == STD_ON))
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_ClearChConfig(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                         VAR(Icu_LPit_ChConfigType,AUTOMATIC) mask
                                                        );
#endif

LOCAL_INLINE FUNC(Icu_LPit_ChConfigType, ICU_CODE) Icu_LPit_GetChConfig(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                                        VAR(Icu_LPit_ChConfigType,AUTOMATIC) mask
                                                                       );

#if (ICU_TIMESTAMP_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_Timestamp(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(boolean,              AUTOMATIC) overflow
                                                    );
#endif

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

#if ((ICU_SET_MODE_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON)|| (ICU_TIMESTAMP_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu driver function that enables interrupts on a LPit channel
* @details    This function enables LPit Channel Interrupt
*
* @param[in]  hwChannel HW Channel
*
* @return void
*
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_EnableInterrupt(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);

    {
        /* Timer Interrupt Flag is enabled */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << (u8ChannelIdx)));
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_29();
        /* Timer Interrupt is enabled */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPIT_MIER_ADDR32(u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << (u8ChannelIdx)));
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_29();
    }

}
#endif


#if ((ICU_SET_MODE_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON)|| (ICU_TIMESTAMP_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu driver function that disables interrupts on a LPit channel
* @details    This function disables LPit Channel Interrupt
*
* @param[in]  hwChannel HW Channel
*
* @return void
*
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_DisableInterrupt(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);


    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_30();
        /* Timer Interrupt is disabled */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_MIER_ADDR32(u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << (u8ChannelIdx)));
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_30();
        /* Timer Interrupt Flag is enabled */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << (u8ChannelIdx)));
    }
}

#endif

/*================================================================================================*/
/**
* @brief      Icu_LPit_SetChConfig
* @details    Set the Icu_LPit_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_SetChConfig(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                       VAR(Icu_LPit_ChConfigType,AUTOMATIC) mask
                                                      )
{
    Icu_LPit_aChConfig[hwChannel] |= mask;
}

#if ((ICU_DE_INIT_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON)|| (ICU_TIMESTAMP_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu_LPit_ClearChConfig
* @details    Clear the Icu_LPit_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_ClearChConfig(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                         VAR(Icu_LPit_ChConfigType, AUTOMATIC) mask
                                                        )
{
    Icu_LPit_aChConfig[hwChannel]  &= ((~mask));
}

#endif
/*================================================================================================*/
/**
 * @brief      Icu_LPit_GetChConfig
 * @details    Return the Icu_LPit_aChConfig bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]      hwChannel  - The index of ICU channel for current configuration structure
 * @param[in]      mask    - bitfield mask
 * @return         Bitfield specified by mask parameter
 */
 /*================================================================================================*/
LOCAL_INLINE FUNC(Icu_LPit_ChConfigType, ICU_CODE) Icu_LPit_GetChConfig(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                                        VAR(Icu_LPit_ChConfigType,AUTOMATIC) mask
                                                                       )
{
    return (Icu_LPit_aChConfig[hwChannel] & mask);
}

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_LPit_Timestamp - process the timestamp data
*
* @param[in]   hwChannel   - LPit encoded hardware channel
* @param[in]   overflow    - Parameter that indicates the source of report is an overflow
* @return      void
*
* @return void
*
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_LPit_Timestamp(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(boolean,              AUTOMATIC) overflow
                                                    )
{
    VAR(uint8,   AUTOMATIC) u8CapturedWords = 1U;
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);

    /* Copy the Counter value in the Timestamp Buffer*/
    /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    Icu_LPit_aBufferPtr[hwChannel]= (Icu_ValueType)REG_READ32(LPIT_TVAL_ADDR32((u8ModuleIdx),(u8ChannelIdx)));

    /* saves the value of timestamps in the internal buffer */
    /** @violates @ref ICU_LPIT_C_REF_6 MISRA 2004 Rule 10.3,
     * The value of a complex expression was cast to a type that is not narrower*/
    Icu_Ipw_Timestamp(LPIT_ICU_CHANNEL(hwChannel), u8CapturedWords ,&Icu_LPit_aBufferPtr[hwChannel],overflow);
}
#endif

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief      Icu_LPit_ProcessInterrupt
* @details
*
* @param[in]      hwChannel - HW Channel from the HW group
*
* @return void
*
* @implements Icu_LPit_ProcessInterrupt_Activity
* @violates @ref ICU_LPIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*
* */

FUNC(void, ICU_CODE) Icu_LPit_ProcessInterrupt(CONST(uint8, AUTOMATIC) hwChannel)
{
    VAR(uint32,                                 AUTOMATIC) u32Temp1;
    VAR(uint32,                                 AUTOMATIC) u32Temp2;
    VAR(uint8,                                  AUTOMATIC) u8ModuleIdx;
    VAR(uint8,                                  AUTOMATIC) u8ChannelIdx;
    VAR(Icu_LPit_ChannelMeasurementModeType,    AUTOMATIC) MeasMode;

    /*Checks for spurious interrupts*/
    u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
    u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);

    if (LPIT_ICU_CH_INITIALIZED_MASK_U8 == Icu_LPit_GetChConfig((uint8)u8ChannelIdx,LPIT_ICU_CH_INITIALIZED_MASK_U8))
    {
        /* get Timer Interrupt Flag status */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32Temp1 = (uint32)(REG_BIT_GET32(LPIT_MSR_ADDR32(u8ModuleIdx),(LPIT_MSR_TIF_MASK_U32 << u8ChannelIdx)) >> u8ChannelIdx);
        /* get Timer Interrupt status */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32Temp2 = (uint32)(REG_BIT_GET32(LPIT_MIER_ADDR32(u8ModuleIdx),(LPIT_MIER_TIE_MASK_U32 << u8ChannelIdx)) >> u8ChannelIdx);
        MeasMode = (Icu_LPit_ChannelMeasurementModeType) \
                   (Icu_LPit_GetChConfig((uint8)u8ChannelIdx,LPIT_ICU_MEAS_MODE_MASK_U8)>> LPIT_ICU_MEAS_MODE_SHIFT_U8);

        if ((LPIT_TFLG_TIF_ON_U32 == u32Temp1) && ((uint32)LPIT_TCTRL_TIE_ON_U32 == u32Temp2))
        {
            switch (MeasMode)
            {
#if (ICU_EDGE_DETECT_API == STD_ON)
                case LPIT_CHANNEL_MODE_SIGNAL_EDGE_DETECT:
                {
                    Icu_Ipw_ReportEvents(LPIT_ICU_CHANNEL((uint16)hwChannel), (boolean)FALSE);
                }
                break;
#endif
                default: /* case LPIT_CHANNEL_MODE_TIMESTAMP:*/
#if (ICU_TIMESTAMP_API == STD_ON)
                {
                    Icu_LPit_Timestamp(hwChannel, (boolean)FALSE);
                }
#endif
                break;
            }
        }
    }
    {
        /*Clear interrupt flag*/
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32  << u8ChannelIdx));
    }
}

/*================================================================================================*/
/**
* @brief   Icu driver initialization function for LPit module.
* @details This function is called separately for each LPIT hw channel corresponding to the configured
*          timer channels, and:
*          - enables the LPIT module
*          - configures the freeze mode (enabled or disabled)
*          - enables the IRQ correpsonding to the LPIT channel
*          - clears the (pending) interrupt flag corresponding to LPit channel
*          - Disable channel interrupts
*          - Set Triger Input Capture Mode
*
* @return void
*
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_LPit_Init
(
    P2CONST(Icu_LPit_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pLPitIpConfig
)
{
   /* @brief Pointer to LPit channel specific configuration */
   P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pLPitChannelConfig;
   VAR(Icu_LPit_ControlType,   AUTOMATIC)  nCtrlRegVal;
   VAR(Icu_LPit_ChannelType,   AUTOMATIC)  nCounter;
   VAR(Icu_LPit_ChannelType,   AUTOMATIC)  hwChannel;
   VAR(uint8,                  AUTOMATIC)  u8ModuleIdx;
   VAR(uint8,                  AUTOMATIC)  u8ChannelIdx;
   VAR(uint8,                  AUTOMATIC)  u8freezeEnable;
   VAR(uint8,                  AUTOMATIC)  u8TriggerSource;
   VAR(uint32,                 AUTOMATIC)  u32TriggerSelect;

   for (nCounter=0U; nCounter < pLPitIpConfig->nNumChannels; nCounter++)
    {
        pLPitChannelConfig = &(*pLPitIpConfig->pChannelsConfig)[nCounter];
        nCtrlRegVal  = pLPitChannelConfig->nControlValue;
        u8freezeEnable = (uint8)((nCtrlRegVal & ICU_LPIT_FREEZE_MASK) >> ICU_LPIT_FREEZE_SHIFT);
        u8TriggerSource = (uint8)((nCtrlRegVal & ICU_LPIT_TRG_SRC_MASK) >> ICU_LPIT_TRG_SRC_SHIFT);
        u32TriggerSelect = (uint32)(((nCtrlRegVal & ICU_LPIT_TRG_SEL_MASK) >> ICU_LPIT_TRG_SEL_SHIFT) << LPIT_TCTRL_TRG_SEL_SHIFT);

        /* only handle LPit channels */
        pLPitChannelConfig = &(*pLPitIpConfig->pChannelsConfig)[nCounter];
        hwChannel = (Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(pLPitChannelConfig->nHwChannel);
        u8ModuleIdx = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
        u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);

        /* Enable hardware module clock. This shall be be executed before any other setup is made */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPIT_MCR_ADDR32(u8ModuleIdx), LPIT_MCR_MCEN_MASK_U32);

        /* Enables the LPIT timer channel*/
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPIT_TCTRL_ADDR32((u8ModuleIdx),(u8ChannelIdx)),(uint32)LPIT_TCTRL_TEN_MASK_U32);

        /* Clear pending interrupts */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << (u8ChannelIdx)));

        /* Disable channel interrupts*/
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_MIER_ADDR32(u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << (u8ChannelIdx)));

        if ((uint8)1U == u8freezeEnable)
        {
            /* Enable freeze */
            /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(LPIT_MCR_ADDR32(u8ModuleIdx), LPIT_MCR_FRZ_MASK_U32);
        }
        else
        {
            /* Disable freeze */
            /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(LPIT_MCR_ADDR32(u8ModuleIdx), LPIT_MCR_FRZ_MASK_U32);
        }

        if ((uint8)1U == u8TriggerSource)
        {
            /* Trigger source selected is the internal trigger */
            /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(LPIT_TCTRL_ADDR32((u8ModuleIdx),(u8ChannelIdx)),(uint32)LPIT_TCTRL_TRG_SRC_MASK_U32);
        }
        else
        {
            /* Trigger source selected is the external trigger */
            /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
           REG_BIT_CLEAR32(LPIT_TCTRL_ADDR32((u8ModuleIdx),(u8ChannelIdx)),(uint32)LPIT_TCTRL_TRG_SRC_MASK_U32);
        }

        /* Set Trigger Select*/
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(LPIT_TCTRL_ADDR32((u8ModuleIdx),(u8ChannelIdx)), LPIT_TCTRL_TRG_SEL_MASK_U32, u32TriggerSelect);

        /* Enter Triger Input Capture Mode */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPIT_TCTRL_ADDR32((u8ModuleIdx),(u8ChannelIdx)),(uint32)LPIT_TCTRL_MODE_MASK_U32);

        Icu_LPit_SetChConfig((hwChannel),LPIT_ICU_CH_INITIALIZED_MASK_U8);
    }
}

/*================================================================================================*/
#if (ICU_DE_INIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Icu driver de-initialization function for LPit module.
* @details This function is called separately for each LPIT hw channel corresponding to the configured
*          timer channels, and:
*          - disables the LPIT channel
*          - disables the freeze mode
*          - disables IRQ corresponding to LPit channel
*          - clears the (pending) interrupt flag corresponding to LPit channel
*
* @return void
*
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_LPit_DeInit
(
    P2CONST(Icu_LPit_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pLPitIpConfig
)
{
    /* @brief Pointer to LPit channel specific configuration */
    P2CONST(Icu_LPit_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pLPitChannelConfig;

    /* logical channel */
    VAR(Icu_LPit_ChannelType,   AUTOMATIC)  nCounter;
    VAR(Icu_LPit_ChannelType,   AUTOMATIC)  hwChannel;
    VAR(uint8,                  AUTOMATIC)  u8ModuleIdx;
    VAR(uint8,                  AUTOMATIC)  u8ChannelIdx;

    for (nCounter=0U; nCounter < pLPitIpConfig->nNumChannels; nCounter++)
    {
        pLPitChannelConfig = &(*pLPitIpConfig->pChannelsConfig)[nCounter];
        hwChannel = (Icu_LPit_ChannelType)ICU_LPIT_CHANNELS(pLPitChannelConfig->nHwChannel);
        u8ModuleIdx = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
        u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);

        /* Enable hardware module clock. This shall be be executed before any other setup is made */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(LPIT_MCR_ADDR32(u8ModuleIdx), LPIT_MCR_MCEN_MASK_U32);

        /* Reset Status and Control Register */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_TCTRL_ADDR32((u8ModuleIdx),(u8ChannelIdx)),(uint32)LPIT_TCTRL_TEN_MASK_U32);

        /* Disable channel interrupts*/
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_MIER_ADDR32(u8ModuleIdx), ((uint32)LPIT_MIER_TIE_MASK_U32 << (u8ChannelIdx)));

        /* Clear Interrupt Flag */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << (u8ChannelIdx)));

        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_MCR_ADDR32(u8ModuleIdx), LPIT_MCR_FRZ_MASK_U32);

        /* Disable hardware module clock */
        /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(LPIT_MCR_ADDR32(u8ModuleIdx),LPIT_MCR_MCEN_MASK_U32);

        /* Record the deinit */
        Icu_LPit_ClearChConfig(hwChannel,(Icu_LPit_ChConfigType)(LPIT_ICU_MEAS_MODE_MASK_U8 | LPIT_ICU_CH_INITIALIZED_MASK_U8));
    }
}
#endif

#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that sets LPit hardware channel into SLEEP mode.
* @details    This function enables the interrupt if wakeup is enabled for corresponding
*             LPit channel
*
* @param[in]  hwChannel       -  HW Channel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_LPit_SetSleepMode(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    /* Disable Interrupt */
    Icu_LPit_DisableInterrupt(hwChannel);
}

/*================================================================================================*/
/**
* @brief      Driver function that sets the LPit hardware channel into NORMAL mode.
* @details    This function enables the interrupt if Notification is enabled for corresponding
*             LPit channel
*
* @param[in]  hwChannel - HW Channel
*
* @return void
*
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_LPit_SetNormalMode(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    /* Enable Interrupt */
    Icu_LPit_EnableInterrupt(hwChannel);
}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_LPit_EnableEdgeDetection
* @details    This function enables the interrupt corresponding to the LPit channel.
*
* @param[in]  hwChannel - HW Channel
*
* @return void
*
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_LPit_EnableEdgeDetection(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    /* Enable Interrupt */
    Icu_LPit_EnableInterrupt(hwChannel);
    /* Set Edge Detect mode for the Lpit channel in the configuration array */
    Icu_LPit_SetChConfig(hwChannel,
                         (Icu_LPit_ChConfigType)((Icu_LPit_ChConfigType)LPIT_CHANNEL_MODE_SIGNAL_EDGE_DETECT << LPIT_ICU_MEAS_MODE_SHIFT_U8)
                        );
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_LPit_DisableEdgeDetection
* @details    This function disables the interrupt corresponding to the LPit channel.
*
* @param[in]  hwChannel - HW Channel
*
* @return void
*
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_LPit_DisableEdgeDetection(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    /* Disable  Interrupt */
    Icu_LPit_DisableInterrupt(hwChannel);
    /* Clear mode for the Lpit channel in the configuration array */
    Icu_LPit_ClearChConfig(hwChannel,
                           (Icu_LPit_ChConfigType)((Icu_LPit_ChConfigType)LPIT_CHANNEL_MODE_SIGNAL_EDGE_DETECT << LPIT_ICU_MEAS_MODE_SHIFT_U8)
                          );
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_LPit_StartTimestamp
* @details    LPit IP function that stops the edge detection service for an LPit channel
*
* @param[in]      hwChannel   - LPit encoded hardware channel
* @param[in]      bDmaSupport  - Boolean for enabling/disabling the DMA Support
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_LPit_StartTimestamp
(
    CONST(Icu_LPit_ChannelType, ICU_CONST) hwChannel,
    CONST(boolean, ICU_CONST) bDmaSupport
)
{
    (void) bDmaSupport;
    /* Reset aBufferPtr */
    Icu_LPit_aBufferPtr[hwChannel] = 0U;
    /* Enable Interrupt */
    Icu_LPit_EnableInterrupt(hwChannel);
    /* Configure the Timestamp mode for the LPit channel in the configuration array */
    /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    Icu_LPit_SetChConfig(hwChannel,
                         (Icu_LPit_ChConfigType)((Icu_LPit_ChConfigType)LPIT_CHANNEL_MODE_TIMESTAMP << LPIT_ICU_MEAS_MODE_SHIFT_U8)
                        );
}
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_LPit_StopTimestamp
* @details    LPit IP function that stop the timestamp service for an LPit channel
*
* @param[in]      hwChannel   - LPit encoded hardware channel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_LPit_StopTimestamp(CONST(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    /* Disable Interrupt */
    Icu_LPit_DisableInterrupt(hwChannel);
    /* Clear mode for the Lpit channel in the configuration array */
    Icu_LPit_ClearChConfig(hwChannel,
                           (Icu_LPit_ChConfigType)((Icu_LPit_ChConfigType)LPIT_CHANNEL_MODE_TIMESTAMP << LPIT_ICU_MEAS_MODE_SHIFT_U8)
                          );
}
#endif  /* ICU_TIMESTAMP_API */


#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_LPit_GetInputState
* @details    This function returns the input state of the corresponding LPit channel.
*
* @param[in]  hwChannel - HW Channel
*
* @return void
*
* */
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_LPit_GetInputState(VAR(Icu_LPit_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)LPIT_MODULE_INDEX_U32(hwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)LPIT_CHANNEL_INDEX_U32(hwChannel);
    VAR(boolean, AUTOMATIC) bStatus = (boolean)FALSE;

    /* Get Interrupt Enable flag */
    /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegLPitMIER = REG_BIT_GET32(LPIT_MIER_ADDR32(u8ModuleIdx),((uint32)LPIT_MIER_TIE_MASK_U32 << (u8ChannelIdx)));

    /* Get Interrupt Status flag */
    /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegLPitMSR = REG_BIT_GET32(LPIT_MSR_ADDR32(u8ModuleIdx),(LPIT_MSR_TIF_MASK_U32 << (u8ChannelIdx)));

    /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
    if ((0x0U !=  u32RegLPitMSR) && (0x0U == u32RegLPitMIER))
    {
        {
            /* Clear IRQ Flag */
            /** @violates @ref ICU_LPIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref ICU_LPIT_C_REF_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(LPIT_MSR_ADDR32(u8ModuleIdx), (LPIT_MSR_TIF_MASK_U32 << (u8ChannelIdx)));
        }
        bStatus = (boolean)TRUE;
    }

    return bStatus;
}
#endif  /* ICU_GET_INPUT_STATE_API */

#define ICU_STOP_SEC_CODE
/**
* @violates @ref ICU_LPIT_C_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref ICU_LPIT_C_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
