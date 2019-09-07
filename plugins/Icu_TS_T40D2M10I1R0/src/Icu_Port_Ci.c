/**
*     @file          Icu_Port_Ci.c
*     @implements    Icu_Port_Ci_unit
*     @version 1.0.1
* 
*     @brief   AUTOSAR Icu - Port_Ci source file support for ICU driver.
*     @details Port_Ci source file, containing the variables and functions that are exported by the Port_Ci driver.
* 
*     *     @addtogroup ICU_MODULE
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
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_PORT_CI_c_REF_1
*         Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*         '#include'
*         This is an Autosar requirement about the memory management (Autosar requirement MEMMAP003)
* 
* @section Icu_PORT_CI_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15,Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* 
* @section Icu_PORT_CI_c_REF_3
*         Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*         that 31 character significance and case sensitivity are supported for external identifiers
*         The defines are validated.
* 
* @section Icu_PORT_CI_c_REF_4
*         Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*         pointer to a function and a type other than an integral type. This violation is due to the
*         pointer arithmetic used to write/ read the data to/from the registers
*
* @section Icu_PORT_CI_c_REF_5
*          Violates MISRA 2004 Required Rule 8.10, could be made static
*          The respective code could not be made static because of layers architecture design of the
*          driver.
*
* @section Icu_PORT_CI_c_REF_6
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
*          and an integral type.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
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
#include "Mcal.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"

#include "Icu_Reg_eSys_Port_Ci.h"
#include "Icu_Port_Ci.h"

#include "Icu_Ipw_Types.h"


/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_PORT_CI_VENDOR_ID_C                    43
/** @violates @ref Icu_PORT_CI_c_REF_3 MISRA 2004 Rule 1.4, Identifier clash */
#define ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Icu_PORT_CI_c_REF_3 MISRA 2004 Rule 1.4, Identifier clash */
#define ICU_PORT_CI_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref Icu_PORT_CI_c_REF_3 MISRA 2004 Rule 1.4, Identifier clash */
#define ICU_PORT_CI_AR_RELEASE_REVISION_VERSION_C  2
#define ICU_PORT_CI_SW_MAJOR_VERSION_C             1
#define ICU_PORT_CI_SW_MINOR_VERSION_C             0
#define ICU_PORT_CI_SW_PATCH_VERSION_C             1


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_PORT_CI_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Port_Ci.c and Mcal.h are different"
    #endif
#endif

#if (ICU_PORT_CI_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Port_Ci.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_PORT_CI_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_PORT_CI_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Port_Ci.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_PORT_CI_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_PORT_CI_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_PORT_CI_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_Port_Ci.c are different"
#endif

/* Check if source file and Icu_Reg_eSys_Port_Ci.h file are of the same vendor */
#if (ICU_PORT_CI_VENDOR_ID_C != ICU_REGESYS_PORT_CI_VENDOR_ID)
#error "Icu_Port_Ci.c and Icu_Reg_eSys_Port_Ci.h have different vendor IDs"
#endif
#if ((ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != ICU_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_CI_AR_RELEASE_MINOR_VERSION_C != ICU_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_CI_AR_RELEASE_REVISION_VERSION_C != ICU_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Port_Ci.c and Icu_Reg_eSys_Port_Ci.h are different"
#endif
/* Check if source file and Icu_Reg_eSys_Port_Ci.h header file are of the same Software version */
#if ((ICU_PORT_CI_SW_MAJOR_VERSION_C != ICU_REGESYS_PORT_CI_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_SW_MINOR_VERSION_C != ICU_REGESYS_PORT_CI_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_SW_PATCH_VERSION_C != ICU_REGESYS_PORT_CI_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Ci.c and Icu_Reg_eSys_Port_Ci.h are different"
#endif

/* Check if source file and Icu_Port_Ci.h file are of the same vendor */
#if (ICU_PORT_CI_VENDOR_ID_C != ICU_PORT_CI_VENDOR_ID)
#error "Icu_Port_Ci.c and Icu_Port_Ci.h have different vendor IDs"
#endif
    #if ((ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_PORT_CI_AR_RELEASE_MINOR_VERSION_C != ICU_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
         (ICU_PORT_CI_AR_RELEASE_REVISION_VERSION_C != ICU_PORT_CI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Port_Ci.c and Icu_Port_Ci.h are different"
    #endif
/* Check if source file and Icu_Port_Ci.h header file are of the same Software version */

#if ((ICU_PORT_CI_SW_MAJOR_VERSION_C != ICU_PORT_CI_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_SW_MINOR_VERSION_C != ICU_PORT_CI_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_SW_PATCH_VERSION_C != ICU_PORT_CI_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Ci.c and Icu_Port_Ci.h are different"
#endif

#if (ICU_PORT_CI_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Port_Ci.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_CI_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_CI_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Port_Ci.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_PORT_CI_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Ci.c and Icu_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define ICU_PORT_CI_CH_NEITHER_EDGE_U8       ((uint8)(0U))
#define ICU_PORT_CI_CH_RISING_EDGE_U8        ((uint8)(1U))
#define ICU_PORT_CI_CH_FALLING_EDGE_U8       ((uint8)(2U))
#define ICU_PORT_CI_CH_EITHER_EDGE_U8        ((uint8)(3U))

/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/

#define ICU_START_SEC_CONST_32
/*
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"
/**
* @brief base address array for Port_Ci
* @violates @ref Icu_PORT_CI_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
CONST(uint32, ICU_CONST) PORT_CI_BASE_ADDR32[] = 
{
#ifdef PORTA_MULTIPLEX_BASEADDR
    PORTA_MULTIPLEX_BASEADDR
#endif
#ifdef PORTB_MULTIPLEX_BASEADDR
    ,PORTB_MULTIPLEX_BASEADDR
#endif
#ifdef PORTC_MULTIPLEX_BASEADDR
    ,PORTC_MULTIPLEX_BASEADDR
#endif
#ifdef PORTD_MULTIPLEX_BASEADDR
    ,PORTD_MULTIPLEX_BASEADDR
#endif
#ifdef PORTE_MULTIPLEX_BASEADDR
    ,PORTE_MULTIPLEX_BASEADDR
#endif
#ifdef PORTF_MULTIPLEX_BASEADDR
    ,PORTF_MULTIPLEX_BASEADDR
#endif
#ifdef PORTG_MULTIPLEX_BASEADDR
    ,PORTG_MULTIPLEX_BASEADDR
#endif
#ifdef PORTH_MULTIPLEX_BASEADDR
    ,PORTH_MULTIPLEX_BASEADDR
#endif
#ifdef DUMMY_PORTI_MULTIPLEX_BASEADDR
    ,0U
#endif
#ifdef PORTJ_MULTIPLEX_BASEADDR
    ,PORTJ_MULTIPLEX_BASEADDR
#endif
#ifdef PORTK_MULTIPLEX_BASEADDR
    ,PORTK_MULTIPLEX_BASEADDR
#endif
#ifdef PORTL_MULTIPLEX_BASEADDR
    ,PORTL_MULTIPLEX_BASEADDR
#endif
};

#define ICU_STOP_SEC_CONST_32
/**
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_INIT_32
/**
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*           contents of a header file being included twice
*/
#include "Icu_MemMap.h"

static VAR(uint32, ICU_VAR) Icu_Port_Ci_u32PortInit[11U] = {(uint32)0U};

#define ICU_STOP_SEC_VAR_INIT_32
/**
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#define ICU_START_SEC_VAR_INIT_8
/**
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*           contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
static VAR(uint8, ICU_VAR) Icu_Port_Ci_aChActivationMode[ICU_MAX_PORT_CI_CHANNELS] = 
                                                           {
                                                            (uint8)ICU_PORT_CI_CH_NEITHER_EDGE_U8
                                                           };
#endif

#define ICU_STOP_SEC_VAR_INIT_8
/**
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
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
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*               comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*               contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#if ((ICU_SET_MODE_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON))
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_EnableInterrupt \
                                                (CONST(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);
#endif

LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_DisableInterrupt \
                                                (CONST(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel);

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

#if ((ICU_SET_MODE_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu driver function that enables interrupts on a Port_Ci channel
* @details    This function enables Port_Ci Channel Interrupt
* 
* @param[in]  hwChannel IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_EnableInterrupt \
                                                (CONST(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint16, ICU_CONST) u16port = PORT_CI_PORT_MASK(hwChannel);
    CONST(uint16, ICU_CONST) u16pin  = PORT_CI_PIN_MASK(hwChannel);
    CONST(uint32, ICU_CONST) u32pinMask = (uint32)(BIT0 << u16pin);
        
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
    {

         /* Enable interrupt and set mode*/
        if (Icu_Port_Ci_aChActivationMode[hwChannel] == ICU_PORT_CI_CH_FALLING_EDGE_U8)
        {
            /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IREE_U32, (uint32)0U); 
            /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IFEE_U32, PORT_CI_PCR_IFEE_U32);
        }
        else if (Icu_Port_Ci_aChActivationMode[hwChannel] == ICU_PORT_CI_CH_RISING_EDGE_U8)
        {
            /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IFEE_U32, (uint32)0U);
            /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IREE_U32, PORT_CI_PCR_IREE_U32);
        }
        else
        {
            /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IEEE_U32, PORT_CI_PCR_IEEE_U32);
        }
        
        /* Clear pending flag */
        /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(PORT_CI_ISFR_ADDR32(u16port), u32pinMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16(); 
}
#endif

/*================================================================================================*/
/**
* @brief      Icu driver function that disables interrupts on a Port_Ci channel
* @details    This function disables Port_Ci Channel Interrupt
* 
* @param[in]  hwChannel IRQ HW Channel
*
* @return void
* 
* */
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_DisableInterrupt \
                                                (CONST(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint16, ICU_CONST) u16port = PORT_CI_PORT_MASK(hwChannel);
    CONST(uint16, ICU_CONST) u16pin  = PORT_CI_PIN_MASK(hwChannel);
    CONST(uint32, ICU_CONST) u32pinMask = (uint32)(BIT0 << u16pin);
        
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
    {
        /* Disable interrupt */
        /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IRQC_U32, (uint32)0U);
        
        /* Clear pending flag */
        /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(PORT_CI_ISFR_ADDR32(u16port), u32pinMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16();   
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

#if ((defined ICU_PORT_0_ISR_USED) || (defined ICU_PORT_1_ISR_USED) || \
     (defined ICU_PORT_2_ISR_USED) || (defined ICU_PORT_3_ISR_USED) || \
     (defined ICU_PORT_4_ISR_USED) || (defined ICU_PORT_5_ISR_USED) || \
     (defined ICU_PORT_6_ISR_USED) || (defined ICU_PORT_7_ISR_USED) || \
     (defined ICU_PORT_9_ISR_USED) || (defined ICU_PORT_10_ISR_USED) || \
     (defined ICU_PORT_11_ISR_USED)|| (defined ICU_IRQ_SINGLE_INTERRUPT))
/*================================================================================================*/
/**
* @brief      Icu_Port_Ci_GetChInit
* @details    Returns if the current channel was initialized or not
*
* @param[in]      Channel  - The index of ICU channel for current configuration structure
*
* @return         Channel state initialization
* @retval         TRUE  channel was initialized
* @retval         FALSE channel was not initialized
* @violates @ref Icu_PORT_CI_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
FUNC(boolean, ICU_CODE) Icu_Port_Ci_GetChInit(CONST(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel) 
{
    CONST(uint16, ICU_CONST) u16port = PORT_CI_PORT_MASK(hwChannel);
    CONST(uint16, ICU_CONST) u16pin  = PORT_CI_PIN_MASK(hwChannel);
    CONST(uint32, ICU_CONST) u32pinMask = (uint32)(BIT0 << u16pin);
    
    return ((Icu_Port_Ci_u32PortInit[u16port]  & u32pinMask) == u32pinMask) ? \
                                               (boolean)TRUE : (boolean)FALSE;
}
#endif

/*================================================================================================*/
/**
* @brief      Driver function that initializes Port_Ci hardware channel.
* @details    This function:
*              - Disables interrupt.
*              - Sets Interrupt Filter Enable Register
*              - Sets Activation Condition
* 
* @param[in]  ParamValue IRQ Param value
* @param[in]  hwChannel IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/ 
FUNC(void, ICU_CODE) Icu_Port_Ci_Init
(
    P2CONST(Icu_Port_Ci_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pPort_CiIpConfig    
)
{
    /* @brief Pointer to Port_Ci channel specific configuration */
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pPort_CiChannelConfig;
    /* logical channel */
    VAR(Icu_Port_Ci_ChannelType, AUTOMATIC)   nCounter;
    VAR(Icu_Port_Ci_ChannelType, AUTOMATIC)   hwChannel;
    VAR(uint16,                  AUTOMATIC)   u16port;
    VAR(uint16,                  AUTOMATIC)   u16pin;
    VAR(uint32,                  AUTOMATIC)   u32pinMask;

    for (nCounter=0U; nCounter < pPort_CiIpConfig->nNumChannels; nCounter++)
    {
        /* only handle Port_Ci channels */
        pPort_CiChannelConfig = &(*pPort_CiIpConfig->pChannelsConfig)[nCounter];
        hwChannel = (Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(pPort_CiChannelConfig->nHwChannel);
        u16port = (uint16)(PORT_CI_PORT_MASK((uint16)hwChannel));
        u16pin  = (uint16)(PORT_CI_PIN_MASK((uint16)hwChannel));
        u32pinMask = (uint32)(BIT0 << u16pin);

        /* Disable IRQ Interrupt */
        Icu_Port_Ci_DisableInterrupt(hwChannel);

        /* Set Activation Condition */
        Icu_Port_Ci_SetActivationCondition 
        (
            hwChannel, 
            (Icu_Port_Ci_ActivationType)(pPort_CiChannelConfig->nDefaultStartEdge)
        );

        Icu_Port_Ci_u32PortInit[u16port] |= (uint32)(u32pinMask);
    }
}

#if (ICU_DE_INIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that de-initializes Icu Port.
* @details    This function:
*              - Disables interrupt.
*              - Clears edge event enable registers
*              - Clears Interrupt Filter Enable Register
* 
* @param[in]  hwChannel  - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Port_Ci_DeInit
(
    P2CONST(Icu_Port_Ci_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pPort_CiIpConfig
)
{
    /* @brief Pointer to Port_Ci channel specific configuration */
    P2CONST(Icu_Port_Ci_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pPort_CiChannelConfig;
    
    /* logical channel */
    VAR(Icu_Port_Ci_ChannelType, AUTOMATIC)   nCounter;
    VAR(Icu_Port_Ci_ChannelType, AUTOMATIC)   hwChannel;
    VAR(uint16,                  AUTOMATIC)   u16port; 
    VAR(uint16,                  AUTOMATIC)   u16pin;
    VAR(uint32,                  AUTOMATIC)   u32pinMask; 
    
    for (nCounter=0U; nCounter < pPort_CiIpConfig->nNumChannels; nCounter++)
    {
        /* only handle Port_Ci channels */
        pPort_CiChannelConfig = &(*pPort_CiIpConfig->pChannelsConfig)[nCounter];
        hwChannel = (Icu_Port_Ci_ChannelType)ICU_PORT_CI_CHANNELS(pPort_CiChannelConfig->nHwChannel);
        u16port = (uint16)(PORT_CI_PORT_MASK((uint16)hwChannel));
        u16pin  = (uint16)(PORT_CI_PIN_MASK((uint16)hwChannel));
        u32pinMask = (uint32)(BIT0 << u16pin);
        
        /* Disable IRQ Interrupt */
        Icu_Port_Ci_DisableInterrupt(hwChannel);
        
        /* Clear edge event enable registers */
        /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IRQC_U32, (uint32)0U); 
            
        /* Clear Interrupt Filter Enable Register */
        /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(PORT_CI_DFER_ADDR32(u16port), u32pinMask, (uint32)0U);
        
        /* Record the deinit */
        Icu_Port_Ci_u32PortInit[u16port] &= (uint32)(~u32pinMask);
#if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
        Icu_Port_Ci_aChActivationMode[hwChannel] = ICU_PORT_CI_CH_NEITHER_EDGE_U8;
#endif
    }
}
#endif


#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that sets Port_Ci hardware channel into SLEEP mode.
* @details    This function enables the interrupt if wakeup is enabled for corresponding 
*             Port_Ci channel
* 
* @param[in]  hwChannel       - IRQ HW Channel
* @param[in]  WakeUpEnabled   - channel wakeup feature is enabled
* 
* @return void
* 
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_Port_Ci_SetSleepMode(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{
    /* Disable IRQ Interrupt */
    Icu_Port_Ci_DisableInterrupt(hwChannel);
}

/*================================================================================================*/
/**
* @brief      Driver function that sets the Port_Ci hardware channel into NORMAL mode.
* @details    This function enables the interrupt if Notification is enabled for corresponding
*             Port_Ci channel
* 
* @param[in]  hwChannel - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_Port_Ci_SetNormalMode(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{
    /* Enable IRQ Interrupt */
    Icu_Port_Ci_EnableInterrupt(hwChannel);
}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/
/**
* @brief      Driver function that sets activation condition of Port_Ci channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding Port_Ci channels.
* 
* @param[in]  hwChannel -  IRQ HW Channel
* @param[in]  Activation - Activation condition
* 
* @return void
* 
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_Port_Ci_SetActivationCondition(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) \
                              hwChannel,VAR(Icu_Port_Ci_ActivationType, AUTOMATIC) Activation)
{
    CONST(uint16, ICU_CONST) u16port = PORT_CI_PORT_MASK(hwChannel);
    CONST(uint16, ICU_CONST) u16pin  = PORT_CI_PIN_MASK(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
    {
        switch (Activation)
        {
            case PORT_CI_RISING_EDGE:
            {
                /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IFEE_U32, (uint32)0U);
                /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IREE_U32, PORT_CI_PCR_IREE_U32);
    #if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
                Icu_Port_Ci_aChActivationMode[hwChannel] = ICU_PORT_CI_CH_RISING_EDGE_U8;
    #endif
            }
            break;
    
            case PORT_CI_FALLING_EDGE:
            {
                /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IREE_U32, (uint32)0U); 
                /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IFEE_U32, PORT_CI_PCR_IFEE_U32);
    #if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
                Icu_Port_Ci_aChActivationMode[hwChannel] = ICU_PORT_CI_CH_FALLING_EDGE_U8;
    #endif            
            }
            break;
    
            default:
            {
                /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_RMW32(PORT_CI_PCR_ADDR32(u16port,(uint32)u16pin), PORT_CI_PCR_IEEE_U32, PORT_CI_PCR_IEEE_U32);
    #if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))            
                Icu_Port_Ci_aChActivationMode[hwChannel] = ICU_PORT_CI_CH_EITHER_EDGE_U8;
    #endif
            }
            break;
        }
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16();
}

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Port_Ci_EnableEdgeDetection
* @details    This function enables the interrupt corresponding to the Port_Ci channel.
* 
* @param[in]  hwChannel - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_Port_Ci_EnableEdgeDetection(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{
    /* Enable IRQ Interrupt */
    Icu_Port_Ci_EnableInterrupt(hwChannel);
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Port_Ci_DisableEdgeDetection
* @details    This function disables the interrupt corresponding to the Port_Ci channel.
* 
* @param[in]  hwChannel - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/

FUNC(void, ICU_CODE) Icu_Port_Ci_DisableEdgeDetection(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{   
    /* Disable IRQ Interrupt */
    Icu_Port_Ci_DisableInterrupt(hwChannel);
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Port_Ci_GetInputState
* @details    This function returns the input state of the corresponding Port_Ci channel.
* 
* @param[in]  hwChannel - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_Port_Ci_GetInputState(VAR(Icu_Port_Ci_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint16, ICU_CONST) u16port = PORT_CI_PORT_MASK(hwChannel);
    CONST(uint16, ICU_CONST) u16pin  = PORT_CI_PIN_MASK(hwChannel);
    CONST(uint32, ICU_CONST) u32pinMask = (uint32)(BIT0 << u16pin);
    VAR(boolean,  AUTOMATIC) bStatus = (boolean)FALSE;
    
    /* Get Interrupt Enable flag */
    /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegPort_ciPCR = REG_BIT_GET32(PORT_CI_PCR_ADDR32(u16port, (uint32)u16pin), PORT_CI_PCR_IRQC_U32);
    
    /* Get Interrupt Status flag */
    /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegPort_ciISFR = REG_BIT_GET32(PORT_CI_ISFR_ADDR32(u16port), u32pinMask);
    
    /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
    if ((0x0U !=  u32RegPort_ciISFR) && (0x0U == u32RegPort_ciPCR))
    {
        /* Clear IRQ Flag */
        /** @violates @ref Icu_PORT_CI_c_REF_4 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(PORT_CI_ISFR_ADDR32(u16port), u32pinMask);

        bStatus = (boolean)TRUE;
    }

    return bStatus;
}
#endif  /* ICU_GET_INPUT_STATE_API */


#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_PORT_CI_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_PORT_CI_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
