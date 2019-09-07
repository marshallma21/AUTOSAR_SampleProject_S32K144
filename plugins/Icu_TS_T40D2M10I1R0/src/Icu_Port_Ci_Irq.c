/**
*     @fileI Icu_Port_Ci_Irq.c
*     @version 1.0.1
* 
*     @brief   AUTOSAR Icu - PORT_CI source file support for ICU driver.
*     @details PORT_CI source file, containing the variables and functions that are exported by the PORT_CI driver.
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


/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_PORT_CI_Irq_c_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
* 
* @section Icu_PORT_CI_Irq_c_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Icu_PORT_CI_Irq_c_3
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*          pointer to a function and a type other than an integral type. This violation is due to
*          the pointer arithmetic used to write/ read the data to/from the registers
*
* @section Icu_PORT_CI_Irq_c_4
*          Violates MISRA 2004 Required Rule 8.10, could be made static
*          The respective code could not be made static because of layers architecture design of the
*          driver.
*
* @section Icu_PORT_CI_Irq_c_5
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

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Icu_Reg_eSys_Port_Ci.h"
#include "Icu_Port_Ci.h"

#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Irq.h"

#include "SchM_Icu.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @{
* @brief          Source file version information
* */
#define ICU_PORT_CI_IRQ_VENDOR_ID_C                      43
#define ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C       2
#define ICU_PORT_CI_IRQ_AR_RELEASE_REVISION_VERSION_C  2
#define ICU_PORT_CI_IRQ_SW_MAJOR_VERSION_C             1
#define ICU_PORT_CI_IRQ_SW_MINOR_VERSION_C               0
#define ICU_PORT_CI_IRQ_SW_PATCH_VERSION_C               1
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Port_Ci_Irq.c and Mcal.h are different"
    #endif
#endif


#if (ICU_PORT_CI_IRQ_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Port_Ci_Irq.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Port_Ci_Irq.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_PORT_CI_IRQ_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_PORT_CI_IRQ_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_PORT_CI_IRQ_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_Port_Ci_Irq.c are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Port_Ci_Irq.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if source file and Icu_Reg_eSys_Port_Ci.h file are of the same vendor */
#if (ICU_PORT_CI_IRQ_VENDOR_ID_C != ICU_REGESYS_PORT_CI_VENDOR_ID)
    #error "Icu_Port_Ci_Irq.c and Icu_Reg_eSys_Port_Ci.h have different vendor IDs"
#endif
#if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Port_Ci_Irq.c and Icu_Reg_eSys_Port_Ci.h are different"
#endif
/* Check if source file and Icu_Port_Ci.h header file are of the same Software version */
#if ((ICU_PORT_CI_IRQ_SW_MAJOR_VERSION_C != ICU_REGESYS_PORT_CI_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_MINOR_VERSION_C != ICU_REGESYS_PORT_CI_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_PATCH_VERSION_C != ICU_REGESYS_PORT_CI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Port_Ci_Irq.c and Icu_Reg_eSys_Port_Ci.h are different"
#endif


/* Check if source file and Icu_Port_Ci.h file are of the same vendor */
#if (ICU_PORT_CI_IRQ_VENDOR_ID_C != ICU_PORT_CI_VENDOR_ID)
    #error "Icu_Port_Ci_Irq.c and Icu_Port_Ci.h have different vendor IDs"
#endif
#if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_PORT_CI_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_PORT_CI_AR_RELEASE_MINOR_VERSION) || \
         (ICU_PORT_CI_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_PORT_CI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Port_Ci_Irq.c and Icu_Port_Ci.h are different"
#endif
/* Check if source file and Icu_PORT_CI_Types.h file are of the same Software version */
#if ((ICU_PORT_CI_IRQ_SW_MAJOR_VERSION_C != ICU_PORT_CI_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_MINOR_VERSION_C != ICU_PORT_CI_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_PATCH_VERSION_C != ICU_PORT_CI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Port_Ci_Irq.c and Icu_Port_Ci.h are different"
#endif


#if (ICU_PORT_CI_IRQ_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Port_Ci_Irq.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Port_Ci_Irq.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_PORT_CI_IRQ_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Ci_Irq.c and Icu_Ipw_Types.h are different"
#endif


#if (ICU_PORT_CI_IRQ_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
    #error "Icu_Port_Ci_Irq.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Autosar version */
#if ((ICU_PORT_CI_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Port_Ci_Irq.c and Icu_Ipw_Irq.h are different"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Software version */
#if ((ICU_PORT_CI_IRQ_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
     (ICU_PORT_CI_IRQ_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Port_Ci_Irq.c and Icu_Ipw_Irq.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (ICU_IRQ_SINGLE_INTERRUPT == STD_ON)
    
ISR(ICU_EXT_IRQ_SINGLE_INTERRUPT);
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_ProcessSingleInterrupt(void);
#else
    
#if ((defined ICU_PORT_0_ISR_USED) || (defined ICU_PORT_1_ISR_USED) || \
     (defined ICU_PORT_2_ISR_USED) || (defined ICU_PORT_3_ISR_USED) || \
     (defined ICU_PORT_4_ISR_USED) || (defined ICU_PORT_5_ISR_USED) || \
     (defined ICU_PORT_6_ISR_USED) || (defined ICU_PORT_7_ISR_USED) || \
     (defined ICU_PORT_9_ISR_USED) || (defined ICU_PORT_10_ISR_USED) || \
     (defined ICU_PORT_11_ISR_USED))
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_ProcessInterrupt(CONST(uint8, AUTOMATIC) u8portNo);
#endif


#if (defined ICU_PORT_0_ISR_USED)
    ISR(ICU_PORT_CI_A_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_1_ISR_USED)
    ISR(ICU_PORT_CI_B_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_2_ISR_USED)
    ISR(ICU_PORT_CI_C_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_3_ISR_USED)
    ISR(ICU_PORT_CI_D_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_4_ISR_USED)
    ISR(ICU_PORT_CI_E_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_5_ISR_USED)
    ISR(ICU_PORT_CI_F_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_6_ISR_USED)
    ISR(ICU_PORT_CI_G_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_7_ISR_USED)
    ISR(ICU_PORT_CI_H_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_9_ISR_USED)
    ISR(ICU_PORT_CI_J_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_10_ISR_USED)
    ISR(ICU_PORT_CI_K_EXT_IRQ_ISR);
#endif

#if (defined ICU_PORT_11_ISR_USED)
    ISR(ICU_PORT_CI_L_EXT_IRQ_ISR);
#endif

#endif /* ICU_IRQ_SINGLE_INTERRUPT */


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @brief Include Memory mapping specification
* @violates @ref Icu_PORT_CI_Irq_c_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_PORT_CI_Irq_c_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Icu_MemMap.h"
#if (ICU_IRQ_SINGLE_INTERRUPT == STD_ON)
    
/**
* @brief      Icu_Port_Ci_ProcessSingleInterrupt
* @details
*
*
* @return void
*
*
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_ProcessSingleInterrupt(void)
{
    VAR(uint8, AUTOMATIC) u8portNo = 0U;
    VAR(uint32, ICU_CONST) u32port = 0U;
    VAR(uint32,   AUTOMATIC) u32Port_CiPCR;
    VAR(uint32,   AUTOMATIC) u32Port_CiPCRTemp = 0x0U;
    VAR(uint32,   AUTOMATIC) u32RegIrqMask = 0x0U;
    VAR(uint32,   AUTOMATIC) u32pin;
    VAR(uint32,   AUTOMATIC) u32pinMask;
    VAR(uint32, ICU_CONST) u32RegPort_CiISFR;

    for (u8portNo = 0; u8portNo < ICU_NUM_PORT_CI_HW_MODULE_U8; u8portNo++)
    {
        u32port = (uint32)u8portNo << 5U;
        u32Port_CiPCRTemp = 0x0U;
        u32pinMask = (uint32)BIT0;
        /** @violates @ref Icu_PORT_CI_Irq_c_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32RegPort_CiISFR = REG_READ32(PORT_CI_ISFR_ADDR32(u8portNo));
        
        if (0U != u32RegPort_CiISFR)
        {
            for (u32pin=0U; u32pin<32U; u32pin++)
            {
                /** @violates @ref Icu_PORT_CI_Irq_c_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                /** @violates @ref Icu_PORT_CI_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                u32Port_CiPCR = REG_BIT_GET32(PORT_CI_PCR_ADDR32(u8portNo,u32pin), PORT_CI_PCR_IRQC_U32);
                
                if ((PORT_CI_PCR_IREE_U32 == u32Port_CiPCR) || (PORT_CI_PCR_IFEE_U32 == u32Port_CiPCR) \
                        || (PORT_CI_PCR_IEEE_U32 == u32Port_CiPCR))
                {
                    u32Port_CiPCRTemp |= u32pinMask;
                }
                
                /* Get only IRQ's activated with the enabled flag set */
                u32RegIrqMask = u32pinMask & u32RegPort_CiISFR & u32Port_CiPCRTemp ;
                
                if ((0x0U != u32RegIrqMask) && \
                       ((boolean)TRUE == Icu_Port_Ci_GetChInit((Icu_Port_Ci_ChannelType)(u32port + u32pin))))
                {
                    /* Clear pending interrupt serviced */
                    /** @violates @ref Icu_PORT_CI_Irq_c_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
                    /** @violates @ref Icu_PORT_CI_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/                    
                    REG_WRITE32(PORT_CI_ISFR_ADDR32(u8portNo), u32RegIrqMask);
                    
                    Icu_Ipw_ReportEvents(((Icu_Port_Ci_ChannelType)(ICU_PORT_0_CH_0 + u32port + u32pin)), \
                       (boolean)FALSE);
                }
                u32pinMask <<= (uint32)1U;
            }
        }
    }
}

#else

#if ((defined ICU_PORT_0_ISR_USED) || (defined ICU_PORT_1_ISR_USED) || \
     (defined ICU_PORT_2_ISR_USED) || (defined ICU_PORT_3_ISR_USED) || \
     (defined ICU_PORT_4_ISR_USED) || (defined ICU_PORT_5_ISR_USED) || \
     (defined ICU_PORT_6_ISR_USED) || (defined ICU_PORT_7_ISR_USED) || \
     (defined ICU_PORT_9_ISR_USED) || (defined ICU_PORT_10_ISR_USED) || \
     (defined ICU_PORT_11_ISR_USED))

/**
* @brief      Icu_Port_Ci_ProcessInterrupt
* @details
* 
* @param[in]      u8portNo - first IRQ HW Channel from the HW group
* 
* @return void
*
* @implements Icu_Port_Ci_ProcessInterrupt_Activity
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Port_Ci_ProcessInterrupt(CONST(uint8, AUTOMATIC) u8portNo)
{
    CONST(uint32, ICU_CONST) u32port = (uint32)u8portNo << 5U;
    VAR(uint32,   AUTOMATIC) u32Port_CiPCR;
    VAR(uint32,   AUTOMATIC) u32Port_CiPCRTemp = 0x0U;
    VAR(uint32,   AUTOMATIC) u32RegIrqMask = 0x0U;
    VAR(uint32,   AUTOMATIC) u32pin;
    VAR(uint32,   AUTOMATIC) u32pinMask = (uint32)BIT0;

    /** @violates @ref Icu_PORT_CI_Irq_c_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref Icu_PORT_CI_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegPort_CiISFR = REG_READ32(PORT_CI_ISFR_ADDR32(u8portNo));


    
    for (u32pin=0U; u32pin<32U; u32pin++)
    {
        /** @violates @ref Icu_PORT_CI_Irq_c_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref Icu_PORT_CI_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32Port_CiPCR = REG_BIT_GET32(PORT_CI_PCR_ADDR32(u8portNo,u32pin), PORT_CI_PCR_IRQC_U32);
        
        if ((PORT_CI_PCR_IREE_U32 == u32Port_CiPCR) || (PORT_CI_PCR_IFEE_U32 == u32Port_CiPCR) \
                || (PORT_CI_PCR_IEEE_U32 == u32Port_CiPCR))
        {
            u32Port_CiPCRTemp |= u32pinMask;
        }
        
        /* Get only IRQ's activated with the enabled flag set */
        u32RegIrqMask = u32pinMask & u32RegPort_CiISFR & u32Port_CiPCRTemp ;
        
        if ((0x0U != u32RegIrqMask) && \
               ((boolean)TRUE == Icu_Port_Ci_GetChInit((Icu_Port_Ci_ChannelType)(u32port + u32pin))))
        {
            /* Clear pending interrupt serviced */
            /** @violates @ref Icu_PORT_CI_Irq_c_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
            /** @violates @ref Icu_PORT_CI_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(PORT_CI_ISFR_ADDR32(u8portNo), u32RegIrqMask);
            Icu_Ipw_ReportEvents(((Icu_Port_Ci_ChannelType)(ICU_PORT_0_CH_0 + u32port + u32pin)), \
               (boolean)FALSE);
        }
        u32pinMask <<= (uint32)1U;
    }
    
}
#endif
#endif /* ICU_IRQ_SINGLE_INTERRUPT */

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (ICU_IRQ_SINGLE_INTERRUPT == STD_ON)
/*================================================================================================*/
/**
* @brief     Interrupt handler for Port
* @details   Process the interrupt of Port of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_EXT_IRQ_SINGLE_INTERRUPT)
{
    Icu_Port_Ci_ProcessSingleInterrupt();
    EXIT_INTERRUPT();
}

#else
    
#if (defined ICU_PORT_0_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port A
* @details   Process the interrupt of Port A of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port A is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_A_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_A_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTA */

#if (defined ICU_PORT_1_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port B
* @details   Process the interrupt of Port B of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port B is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_B_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_B_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTB */


#if (defined ICU_PORT_2_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port C
* @details   Process the interrupt of Port C of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port C is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_C_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_C_CH_0);
    EXIT_INTERRUPT();
}
#endif    /* IRQ PORTC */


#if (defined ICU_PORT_3_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port D
* @details   Process the interrupt of Port D of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port D is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_D_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_D_CH_0);
    EXIT_INTERRUPT();
}

#endif    /* IRQ PORTD */


#if (defined ICU_PORT_4_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port E
* @details   Process the interrupt of Port E of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port E is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_E_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_E_CH_0);
    EXIT_INTERRUPT();
}

#endif    /* IRQ PORTE */


#if (defined ICU_PORT_5_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port F
* @details   Process the interrupt of Port F of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port F is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_F_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_F_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTF */


#if (defined ICU_PORT_6_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port G
* @details   Process the interrupt of Port G of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port G is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_G_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_G_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTG */


#if (defined ICU_PORT_7_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port H
* @details   Process the interrupt of Port H of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port H is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_H_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_H_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTH */


#if (defined ICU_PORT_9_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port J
* @details   Process the interrupt of Port J of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port J is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_J_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_J_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTJ */


#if (defined ICU_PORT_10_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port K
* @details   Process the interrupt of Port K of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port K is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_K_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_K_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTK */


#if (defined ICU_PORT_11_ISR_USED)

/*================================================================================================*/
/**
* @brief     Interrupt handler for Port L
* @details   Process the interrupt of Port L of Port_Ci IP
* 
* @isr
* 
* *
* @note   This will be defined only if any channel on Port L is configured
* @violates @ref Icu_PORT_CI_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_PORT_CI_L_EXT_IRQ_ISR)
{
    Icu_Port_Ci_ProcessInterrupt(PORT_CI_IRQ_L_CH_0);
    EXIT_INTERRUPT();
}
#endif  /* IRQ PORTL */

#endif /* ICU_IRQ_SINGLE_INTERRUPT */

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_PORT_CI_Irq_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*               and comments before "#include"
*     
* @violates @ref Icu_PORT_CI_Irq_c_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*               contents of a header file being included twice
*/
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */

