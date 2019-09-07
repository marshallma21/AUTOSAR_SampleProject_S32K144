/**
*   @file           Reg_eSys_FTM.h
*   @version        1.0.1
*
*   @brief          AUTOSAR Mcl - FTM register and bitfield defines.
*   @details        FTM register and bitfield defines, used by driver that access the FTM resources.
*
*   @addtogroup     FTM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : eDMA
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

#ifndef REG_ESYS_FTM_H
#define REG_ESYS_FTM_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section Reg_eSys_FTM_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Reg_eSys_FTM_H_REF_2
* Violates MISRA 2004 Required Rule 8.12, Array size not defined
* This violation is  due to the fact that this file is shared by multiple drivers: GPT, PWM and ICU.
* The array size depends by the number of eTimer modules used by all drivers. The eTimer common component
* driver doesn't have yet its own plugin which could be used to generate the common parameters.
*
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Reg_eSys.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file         Reg_eSys_Ftm.h
*/
#define REG_ESYS_FTM_VENDOR_ID                    43
#define REG_ESYS_FTM_MODULE_ID                    255

/* @violates @ref Reg_eSys_FTM_H_REF_1 Identifier clash. */
#define REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Reg_eSys_FTM_H_REF_1 Identifier clash. */
#define REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Reg_eSys_FTM_H_REF_1 Identifier clash. */
#define REG_ESYS_FTM_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_FTM_SW_MAJOR_VERSION             1
#define REG_ESYS_FTM_SW_MINOR_VERSION             0
#define REG_ESYS_FTM_SW_PATCH_VERSION             1
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Reg_eSys_Ftm.h file and Reg_eSys.h are of the same Autosar version */
    #if ((REG_ESYS_FTM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_FTM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_Ftm.h and Reg_eSys.h are different"
    #endif
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*==================================================================================================
*                                GLOBAL DEFINES & DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CONST_32

/** @violates @ref Reg_eSys_FTM_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/**
* @brief FTM base address array declaration
* @violates @ref Reg_eSys_FTM_H_REF_2 Array size not defined
*/
extern CONST(uint32, MCL_CONST) FTM_BASE_ADDR32[];

#define MCL_STOP_SEC_CONST_32

/** @violates @ref Reg_eSys_FTM_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief IPV_FTM macro definition.
* @details Generic define for IPV_FTM.
*/
#define IPV_FTM_04_00_29_00  (0x04002900U)
#define IPV_FTM_05_00_04_00  (0x05000400U)

/**
* @brief FTM module decoding
*/

#define FTM_MODULE_INDEX_U8(ch)      ((uint8)(((ch) & FTM_MOD_MASK_U8) >> FTM_MOD_SHIFT))
/**
* @brief FTM channel decoding
*/
#define FTM_CHANNEL_INDEX_U8(ch)     ((uint8)(((ch) & FTM_CH_MASK_U8)  >> FTM_CH_SHIFT))


/**
* @{
* @brief FTM Module Registers - Channel specific registers.
*/
#define FTM_CSC_ADDR32(u8ModuleIdx, u8ChannelIdx) (FTM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(3UL)) + 0xCUL))
#define FTM_CV_ADDR32(u8ModuleIdx, u8ChannelIdx)  (FTM_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(3UL)) + 0x10UL))


/**
* @{
* @brief FTM Module Registers - Configuration registers.
*/
#define FTM_SC_ADDR32(u8ModuleIdx)                                  (FTM_BASE_ADDR32[(u8ModuleIdx)])
#define FTM_CNT_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x4UL)
#define FTM_MOD_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x8UL)
#define FTM_CNTIN_ADDR32(u8ModuleIdx)                               (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x4CUL)
#define FTM_STATUS_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x50UL)           
#define FTM_MODE_ADDR32(u8ModuleIdx)                                (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x54UL)     
#define FTM_SYNC_ADDR32(u8ModuleIdx)                                (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x58UL)
#define FTM_OUTINIT_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x5CUL)
#define FTM_OUTMASK_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x60UL)
#define FTM_COMBINE_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x64UL)
#define FTM_DEADTIME_ADDR32(u8ModuleIdx)                            (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x68UL)
#define FTM_EXTTRIG_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x6CUL)
#define FTM_POL_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x70UL)
#define FTM_FMS_ADDR32(u8ModuleIdx)                                 (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x74UL)
#define FTM_FILTER_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x78UL)   
#define FTM_FLTCTRL_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x7CUL)
#define FTM_QDCTRL_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x80UL)
#define FTM_CONF_ADDR32(u8ModuleIdx)                                (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x84UL)
#define FTM_FLTPOL_ADDR32(u8ModuleIdx)                              (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x88UL)
#define FTM_SYNCONF_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x8CUL)
#define FTM_INVCTRL_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x90UL)
#define FTM_SWOCTRL_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x94UL)
#define FTM_PWMLOAD_ADDR32(u8ModuleIdx)                             (FTM_BASE_ADDR32[(u8ModuleIdx)] + 0x98UL)

/** MASK and SHIFT values for each register field */
/**
@{
* @brief FTMx_SC - Status And Control Register - bitfield mask and shift defines.
*/


#ifdef IPV_FTM
    #if ((IPV_FTM == IPV_FTM_04_00_29_00) || (IPV_FTM == IPV_FTM_05_00_04_00))
        #define FTM_SC_TOF_MASK_U32                 ((uint32)(BIT9))
        #ifndef FTM_SC_TOF_SHIFT
        #define FTM_SC_TOF_SHIFT                    ((uint32)(9U))
        #endif


        #define FTM_SC_TOIE_MASK_U32                ((uint32)(BIT8))
        #ifndef FTM_SC_TOIE_SHIFT
        #define FTM_SC_TOIE_SHIFT                   ((uint32)(8U))
        #endif

        #define FTM_SC_RF_MASK_U32                 ((uint32)(BIT7))
        #ifndef FTM_SC_RF_SHIFT
        #define FTM_SC_RF_SHIFT                    ((uint32)(7U))
        #endif


        #define FTM_SC_RIE_MASK_U32                ((uint32)(BIT6))
        #ifndef FTM_SC_RIE_SHIFT
        #define FTM_SC_RIE_SHIFT                   ((uint32)(6U))
        #endif
    #else
        #define FTM_SC_TOF_MASK_U32                 ((uint32)(BIT7))
        #ifndef FTM_SC_TOF_SHIFT
        #define FTM_SC_TOF_SHIFT                    ((uint32)(7U))
        #endif


        #define FTM_SC_TOIE_MASK_U32                ((uint32)(BIT6))
        #ifndef FTM_SC_TOIE_SHIFT
        #define FTM_SC_TOIE_SHIFT                   ((uint32)(6U))
        #endif
    #endif
#else
    #define FTM_SC_TOF_MASK_U32                 ((uint32)(BIT7))
    #ifndef FTM_SC_TOF_SHIFT
    #define FTM_SC_TOF_SHIFT                    ((uint32)(7U))
    #endif


    #define FTM_SC_TOIE_MASK_U32                ((uint32)(BIT6))
    #ifndef FTM_SC_TOIE_SHIFT
    #define FTM_SC_TOIE_SHIFT                   ((uint32)(6U))
    #endif
#endif

#define FTM_SC_CPWMS_MASK_U32               ((uint32)(BIT5))
#ifndef FTM_SC_CPWMS_SHIFT
#define FTM_SC_CPWMS_SHIFT                  ((uint32)(5U))
#endif

#define FTM_SC_CLKS_MASK_U32                ((uint32)(BIT4|BIT3))
#ifndef FTM_SC_CLKS_SHIFT
#define FTM_SC_CLKS_SHIFT                   ((uint32)(3U))
#endif

#define FTM_SC_PS_MASK_U32                  ((uint32)(BIT2|BIT1|BIT0))

/**
* @{
* @brief FTMx_MOD - Modulo Register - bitfield mask and shift defines.
*/

#define FTM_MOD_MOD_MASK_U32                ((uint32)(0xFFFF))
#define FTM_MOD_MOD_MASK_SHIFT              ((uint32)(0U))
#define FTM_MOD_MOD_MAX_VALUE               ((uint32)(0xFFFF))
/**
* @{
* @brief FTMx_CnSC - Channel Status And Control Register - bitfield mask and shift defines.
*/
#ifdef IPV_FTM
    #if (IPV_FTM == IPV_FTM_05_00_04_00)
        #define FTM_CSC_CHOV_MASK_U32       ((uint32)(BIT10))
        #define FTM_CSC_CHOV_SHIFT          ((uint32)(10U))
        #define FTM_CSC_CHIS_MASK_U32       ((uint32)(BIT9))
        #define FTM_CSC_CHIS_SHIFT          ((uint32)(9U))
    #endif
#endif 

#define FTM_CSC_CHF_MASK_U32               ((uint32)(BIT7))
#define FTM_CSC_CHF_SHIFT                  ((uint32)(7U))

#define FTM_CSC_CHIE_MASK_U32              ((uint32)(BIT6))
#define FTM_CSC_CHIE_SHIFT                 ((uint32)(6U))

#define FTM_CSC_MSB_MASK_U32               ((uint32)(BIT5))
#define FTM_CSC_MSB_SHIFT                  ((uint32)(5U))

#define FTM_CSC_MSA_MASK_U32               ((uint32)(BIT4))
#define FTM_CSC_MSA_SHIFT                  ((uint32)(4U))

#define FTM_CSC_ELSB_MASK_U32              ((uint32)(BIT3))
#define FTM_CSC_ELSB_SHIFT                 ((uint32)(3U))

#define FTM_CSC_ELSA_MASK_U32              ((uint32)(BIT2))
#define FTM_CSC_ELSA_SHIFT                 ((uint32)(2U))

#define FTM_CSC_DMA_MASK_U32               ((uint32)(BIT0))
#define FTM_CSC_DMA_SHIFT                  ((uint32)(0U))


/**
@{
* @brief FTMx_CnV - Channel Value - bitfield mask and shift defines.
*/
#define FTM_CV_VAL_MASK_U32                  ((uint32)(0xFFFFU))


/**
@{
* @brief FTMx_CNT - Counter Value - bitfield mask and shift defines.
*/
   
#define FTM_CNT_COUNT_MASK_U32              ((uint32)(0xFFFFU))
/**
@{
* @brief FTMx_CNTIN - Counter Initial Value - bitfield mask and shift defines.
*/


#define FTM_CNTIN_INIT_MASK_U32             ((uint32)(0xFFFFU))  

/**
@{
* @brief FTMx_STATUS - Capture and Compare Status Register - bitfield mask and shift defines.
*/

#define FTM_STATUS_CH7F_MASK_U32            ((uint32)(BIT7))
#ifndef FTM_STATUS_CH7F_SHIFT
#define FTM_STATUS_CH7F_SHIFT               ((uint32)(7U))
#endif

#define FTM_STATUS_CH6F_MASK_U32            ((uint32)(BIT6))
#ifndef FTM_STATUS_CH6F_SHIFT
#define FTM_STATUS_CH6F_SHIFT               ((uint32)(6U))
#endif

#define FTM_STATUS_CH5F_MASK_U32            ((uint32)(BIT5))
#ifndef FTM_STATUS_CH5F_SHIFT
#define FTM_STATUS_CH5F_SHIFT               ((uint32)(5U))
#endif

#define FTM_STATUS_CH4F_MASK_U32            ((uint32)(BIT4))
#ifndef FTM_STATUS_CH4F_SHIFT
#define FTM_STATUS_CH4F_SHIFT               ((uint32)(4U))
#endif

#define FTM_STATUS_CH3F_MASK_U32            ((uint32)(BIT3))
#ifndef FTM_STATUS_CH3F_SHIFT
#define FTM_STATUS_CH3F_SHIFT               ((uint32)(3U))
#endif

#define FTM_STATUS_CH2F_MASK_U32            ((uint32)(BIT2))
#ifndef FTM_STATUS_CH2F_SHIFT
#define FTM_STATUS_CH2F_SHIFT               ((uint32)(2U))
#endif

#define FTM_STATUS_CH1F_MASK_U32            ((uint32)(BIT1))
#ifndef FTM_STATUS_CH1F_SHIFT
#define FTM_STATUS_CH1F_SHIFT               ((uint32)(1U))
#endif

#define FTM_STATUS_CH0F_MASK_U32            ((uint32)(BIT0))

/**
@{
* @brief FTMx_MODE - Features Mode Selection Register - bitfield mask and shift defines.
*/

#define FTM_MODE_FAULTIE_MASK_U32           ((uint32)(BIT7))   
#ifndef FTM_MODE_FAULTIE_SHIFT
#define FTM_MODE_FAULTIE_SHIFT              ((uint32)(7U))
#endif

#define FTM_MODE_FAULTM_MASK_U32            ((uint32)(BIT6|BIT5))
#ifndef FTM_MODE_FAULTM_SHIFT
#define FTM_MODE_FAULTM_SHIFT               ((uint32)(5U))
#endif

#define FTM_MODE_CAPTEST_MASK_U32           ((uint32)(BIT4))
#ifndef FTM_MODE_CAPTEST_SHIFT
#define FTM_MODE_CAPTEST_SHIFT              ((uint32)(4U))
#endif

#define FTM_MODE_PWMSYNC_MASK_U32           ((uint32)(BIT3))
#ifndef FTM_MODE_PWMSYNC_SHIFT
#define FTM_MODE_PWMSYNC_SHIFT              ((uint32)(3U))
#endif

#define FTM_MODE_WPDIS_MASK_U32             ((uint32)(BIT2))
#ifndef FTM_MODE_WPDIS_SHIFT
#define FTM_MODE_WPDIS_SHIFT                ((uint32)(2U))
#endif

#define FTM_MODE_INIT_MASK_U32              ((uint32)(BIT1))
#ifndef FTM_MODE_INIT_SHIFT
#define FTM_MODE_INIT_SHIFT                 ((uint32)(1U))
#endif

#define FTM_MODE_FTMEN_MASK_U32             ((uint32)(BIT0))

/**
@{
* @brief FTMx_SYNC - Synchronization Register - bitfield mask and shift defines.
*/

#define FTM_SYNC_SWSYNC_MASK_U32         ((uint32)(BIT7))
#ifndef FTM_SYNC_SWSYNC_SHIFT
#define FTM_SYNC_SWSYNC_SHIFT            ((uint32)(7U))
#endif

#define FTM_SYNC_TRIG2_MASK_U32          ((uint32)(BIT6))
#ifndef FTM_SYNC_TRIG2_SHIFT
#define FTM_SYNC_TRIG2_SHIFT             ((uint32)(6U))
#endif

#define FTM_SYNC_TRIG1_MASK_U32          ((uint32)(BIT5))
#ifndef FTM_SYNC_TRIG1_SHIFT
#define FTM_SYNC_TRIG1_SHIFT             ((uint32)(5U))
#endif

#define FTM_SYNC_TRIG0_MASK_U32          ((uint32)(BIT4))
#ifndef FTM_SYNC_TRIG0_SHIFT
#define FTM_SYNC_TRIG0_SHIFT             ((uint32)(4U))
#endif

#define FTM_SYNC_SYNCHOM_MASK_U32        ((uint32)(BIT3))
#ifndef FTM_SYNC_SYNCHOM_SHIFT
#define FTM_SYNC_SYNCHOM_SHIFT           ((uint32)(3U))
#endif

#define FTM_SYNC_REINIT_MASK_U32         ((uint32)(BIT2))
#ifndef FTM_SYNC_REINIT_SHIFT
#define FTM_SYNC_REINIT_SHIFT            ((uint32)(2U))
#endif

#define FTM_SYNC_CNTMAX_MASK_U32         ((uint32)(BIT1))
#ifndef FTM_SYNC_CNTMAX_SHIFT
#define FTM_SYNC_CNTMAX_SHIFT            ((uint32)(1U))
#endif

#define FTM_SYNC_CNTMIN_MASK_U32         ((uint32)(BIT0))

/**
@{
* @brief FTMx_OUTINIT - Initial State For Channels Output - bitfield mask and shift defines.
*/

#define FTM_OUTINIT_CH7OI_MASK_U32       ((uint32)(BIT7))
#ifndef FTM_OUTINIT_CH7OI_SHIFT
#define FTM_OUTINIT_CH7OI_SHIFT          ((uint32)(7U))
#endif

#define FTM_OUTINIT_CH6OI_MASK_U32       ((uint32)(BIT6))
#ifndef FTM_OUTINIT_CH6OI_SHIFT
#define FTM_OUTINIT_CH6OI_SHIFT          ((uint32)(6U))
#endif

#define FTM_OUTINIT_CH5OI_MASK_U32       ((uint32)(BIT5))
#ifndef FTM_OUTINIT_CH5OI_SHIFT
#define FTM_OUTINIT_CH5OI_SHIFT          ((uint32)(5U))
#endif

#define FTM_OUTINIT_CH4OI_MASK_U32       ((uint32)(BIT4))
#ifndef FTM_OUTINIT_CH4OI_SHIFT
#define FTM_OUTINIT_CH4OI_SHIFT          ((uint32)(4U))
#endif

#define FTM_OUTINIT_CH3OI_MASK_U32       ((uint32)(BIT3))
#ifndef FTM_OUTINIT_CH3OI_SHIFT
#define FTM_OUTINIT_CH3OI_SHIFT          ((uint32)(3U))
#endif

#define FTM_OUTINIT_CH2OI_MASK_U32       ((uint32)(BIT2))
#ifndef FTM_OUTINIT_CH2OI_SHIFT
#define FTM_OUTINIT_CH2OI_SHIFT          ((uint32)(2U))
#endif

#define FTM_OUTINIT_CH1OI_MASK_U32       ((uint32)(BIT1))
#ifndef FTM_OUTINIT_CH1OI_SHIFT
#define FTM_OUTINIT_CH1OI_SHIFT          ((uint32)(1U))
#endif

#define FTM_OUTINIT_CH0OI_MASK_U32       ((uint32)(BIT0))

/**
@{
* @brief FTMx_OUTMASK - Output Mask - bitfield mask and shift defines.
*/

#define FTM_OUTMASK_CH7OM_MASK_U32       ((uint32)(BIT7))
#ifndef FTM_OUTMASK_CH7OM_SHIFT
#define FTM_OUTMASK_CH7OM_SHIFT          ((uint32)(7U))
#endif

#define FTM_OUTMASK_CH6OM_MASK_U32       ((uint32)(BIT6))
#ifndef FTM_OUTMASK_CH6OM_SHIFT
#define FTM_OUTMASK_CH6OM_SHIFT          ((uint32)(6U))
#endif

#define FTM_OUTMASK_CH5OM_MASK_U32       ((uint32)(BIT5))
#ifndef FTM_OUTMASK_CH5OM_SHIFT
#define FTM_OUTMASK_CH5OM_SHIFT          ((uint32)(5U))
#endif

#define FTM_OUTMASK_CH4OM_MASK_U32       ((uint32)(BIT4))
#ifndef FTM_OUTMASK_CH4OM_SHIFT
#define FTM_OUTMASK_CH4OM_SHIFT          ((uint32)(4U))
#endif

#define FTM_OUTMASK_CH3OM_MASK_U32       ((uint32)(BIT3))
#ifndef FTM_OUTMASK_CH3OM_SHIFT
#define FTM_OUTMASK_CH3OM_SHIFT          ((uint32)(3U))
#endif

#define FTM_OUTMASK_CH2OM_MASK_U32       ((uint32)(BIT2))
#ifndef FTM_OUTMASK_CH2OM_SHIFT
#define FTM_OUTMASK_CH2OM_SHIFT          ((uint32)(2U))
#endif

#define FTM_OUTMASK_CH1OM_MASK_U32       ((uint32)(BIT1))
#ifndef FTM_OUTMASK_CH1OM_SHIFT
#define FTM_OUTMASK_CH1OM_SHIFT          ((uint32)(1U))
#endif

#define FTM_OUTMASK_CH0OM_MASK_U32       ((uint32)(BIT0))

/**
@{
* @brief FTMx_COMBINE - Function For Linked Channels - bitfield mask and shift defines.
*/
#define FTM_COMBINE_MCOMBINE3_MASK_U32   ((uint32)(BIT31))
#ifndef FTM_COMBINE_MCOMBINE3_SHIFT
#define FTM_COMBINE_MCOMBINE3_SHIFT      ((uint32)(31U))
#endif

#define FTM_COMBINE_FAULTEN3_MASK_U32    ((uint32)(BIT30))
#ifndef FTM_COMBINE_FAULTEN3_SHIFT
#define FTM_COMBINE_FAULTEN3_SHIFT       ((uint32)(30U))
#endif

#define FTM_COMBINE_SYNCEN3_MASK_U32     ((uint32)(BIT29))
#ifndef FTM_COMBINE_SYNCEN3_SHIFT
#define FTM_COMBINE_SYNCEN3_SHIFT        ((uint32)(29U))
#endif

#define FTM_COMBINE_DTEN3_MASK_U32       ((uint32)(BIT28))
#ifndef FTM_COMBINE_DTEN3_SHIFT
#define FTM_COMBINE_DTEN3_SHIFT          ((uint32)(28U))
#endif

#define FTM_COMBINE_DECAP3_MASK_U32      ((uint32)(BIT27))
#ifndef FTM_COMBINE_DECAP3_SHIFT
#define FTM_COMBINE_DECAP3_SHIFT         ((uint32)(27U))
#endif

#define FTM_COMBINE_DECAPEN3_MASK_U32    ((uint32)(BIT26))
#ifndef FTM_COMBINE_DECAPEN3_SHIFT
#define FTM_COMBINE_DECAPEN3_SHIFT       ((uint32)(26U))
#endif

#define FTM_COMBINE_COMP3_MASK_U32       ((uint32)(BIT25))
#ifndef FTM_COMBINE_COMP3_SHIFT
#define FTM_COMBINE_COMP3_SHIFT          ((uint32)(25U))
#endif

#define FTM_COMBINE_COMBINE3_MASK_U32    ((uint32)(BIT24))
#ifndef FTM_COMBINE_COMBINE3_SHIFT
#define FTM_COMBINE_COMBINE3_SHIFT       ((uint32)(24U))
#endif


#define FTM_COMBINE_MCOMBINE2_MASK_U32    ((uint32)(BIT23))
#ifndef FTM_COMBINE_MCOMBINE2_SHIFT
#define FTM_COMBINE_MCOMBINE2_SHIFT       ((uint32)(23))
#endif

#define FTM_COMBINE_FAULTEN2_MASK_U32    ((uint32)(BIT22))
#ifndef FTM_COMBINE_FAULTEN2_SHIFT
#define FTM_COMBINE_FAULTEN2_SHIFT       ((uint32)(22U))
#endif

#define FTM_COMBINE_SYNCEN2_MASK_U32     ((uint32)(BIT21))
#ifndef FTM_COMBINE_SYNCEN2_SHIFT
#define FTM_COMBINE_SYNCEN2_SHIFT        ((uint32)(21U))
#endif

#define FTM_COMBINE_DTEN2_MASK_U32       ((uint32)(BIT20))
#ifndef FTM_COMBINE_DTEN2_SHIFT
#define FTM_COMBINE_DTEN2_SHIFT          ((uint32)(20U))
#endif

#define FTM_COMBINE_DECAP2_MASK_U32      ((uint32)(BIT19))
#ifndef FTM_COMBINE_DECAP2_SHIFT
#define FTM_COMBINE_DECAP2_SHIFT         ((uint32)(19U))
#endif

#define FTM_COMBINE_DECAPEN2_MASK_U32    ((uint32)(BIT18))
#ifndef FTM_COMBINE_DECAPEN2_SHIFT
#define FTM_COMBINE_DECAPEN2_SHIFT       ((uint32)(18U))
#endif

#define FTM_COMBINE_COMP2_MASK_U32       ((uint32)(BIT17))
#ifndef FTM_COMBINE_COMP2_SHIFT
#define FTM_COMBINE_COMP2_SHIFT          ((uint32)(17U))
#endif

#define FTM_COMBINE_COMBINE2_MASK_U32    ((uint32)(BIT16))
#ifndef FTM_COMBINE_COMBINE2_SHIFT
#define FTM_COMBINE_COMBINE2_SHIFT       ((uint32)(16U))
#endif


#define FTM_COMBINE_MCOMBINE1_MASK_U32    ((uint32)(BIT15))
#ifndef FTM_COMBINE_MCOMBINE1_SHIFT
#define FTM_COMBINE_MCOMBINE1_SHIFT       ((uint32)(15))
#endif

#define FTM_COMBINE_FAULTEN1_MASK_U32    ((uint32)(BIT14))
#ifndef FTM_COMBINE_FAULTEN1_SHIFT
#define FTM_COMBINE_FAULTEN1_SHIFT       ((uint32)(14U))
#endif

#define FTM_COMBINE_SYNCEN1_MASK_U32     ((uint32)(BIT13))
#ifndef FTM_COMBINE_SYNCEN1_SHIFT
#define FTM_COMBINE_SYNCEN1_SHIFT        ((uint32)(13U))
#endif

#define FTM_COMBINE_DTEN1_MASK_U32       ((uint32)(BIT12))
#ifndef FTM_COMBINE_DTEN1_SHIFT
#define FTM_COMBINE_DTEN1_SHIFT          ((uint32)(12U))
#endif

#define FTM_COMBINE_DECAP1_MASK_U32      ((uint32)(BIT11))
#ifndef FTM_COMBINE_DECAP1_SHIFT
#define FTM_COMBINE_DECAP1_SHIFT         ((uint32)(11U))
#endif

#define FTM_COMBINE_DECAPEN1_MASK_U32    ((uint32)(BIT10))
#ifndef FTM_COMBINE_DECAPEN1_SHIFT
#define FTM_COMBINE_DECAPEN1_SHIFT       ((uint32)(10U))
#endif

#define FTM_COMBINE_COMP1_MASK_U32       ((uint32)(BIT9))
#ifndef FTM_COMBINE_COMP1_SHIFT
#define FTM_COMBINE_COMP1_SHIFT          ((uint32)(9U))
#endif

#define FTM_COMBINE_COMBINE1_MASK_U32    ((uint32)(BIT8))
#ifndef FTM_COMBINE_COMBINE1_SHIFT
#define FTM_COMBINE_COMBINE1_SHIFT       ((uint32)(8U))
#endif


#define FTM_COMBINE_MCOMBINE0_MASK_U32    ((uint32)(BIT7))
#ifndef FTM_COMBINE_MCOMBINE0_SHIFT
#define FTM_COMBINE_MCOMBINE0_SHIFT       ((uint32)(7))
#endif

#define FTM_COMBINE_FAULTEN0_MASK_U32    ((uint32)(BIT6))
#ifndef FTM_COMBINE_FAULTEN0_SHIFT
#define FTM_COMBINE_FAULTEN0_SHIFT       ((uint32)(6U))
#endif

#define FTM_COMBINE_SYNCEN0_MASK_U32     ((uint32)(BIT5))
#ifndef FTM_COMBINE_SYNCEN0_SHIFT
#define FTM_COMBINE_SYNCEN0_SHIFT        ((uint32)(5U))
#endif

#define FTM_COMBINE_DTEN0_MASK_U32       ((uint32)(BIT4))
#ifndef FTM_COMBINE_DTEN0_SHIFT
#define FTM_COMBINE_DTEN0_SHIFT          ((uint32)(4U))
#endif

#define FTM_COMBINE_DECAP0_MASK_U32      ((uint32)(BIT3))
#ifndef FTM_COMBINE_DECAP0_SHIFT
#define FTM_COMBINE_DECAP0_SHIFT         ((uint32)(3U))
#endif

#define FTM_COMBINE_DECAPEN0_MASK_U32    ((uint32)(BIT2))
#ifndef FTM_COMBINE_DECAPEN0_SHIFT
#define FTM_COMBINE_DECAPEN0_SHIFT       ((uint32)(2U))
#endif

#define FTM_COMBINE_COMP0_MASK_U32       ((uint32)(BIT1))
#ifndef FTM_COMBINE_COMP0_SHIFT
#define FTM_COMBINE_COMP0_SHIFT          ((uint32)(1U))
#endif

#define FTM_COMBINE_COMBINE0_MASK_U32    ((uint32)(BIT0))
#ifndef FTM_COMBINE_COMBINE0_SHIFT
#define FTM_COMBINE_COMBINE0_SHIFT       ((uint32)(0U))
#endif

#define FTM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)        ((uint32)((((u8ChannelIdx) >> 1U) * 8U) + 0U))
#define FTM_COMBINE_COMBINEx_MASK_U32(u8ChannelIdx)     ((uint32)(BIT0 << FTM_COMBINE_COMBINEx_SHIFT(u8ChannelIdx)))

#define FTM_COMBINE_DECAPx_SHIFT(u8ChannelIdx)          ((uint32)((((u8ChannelIdx) >> 1U) * 8U) + 3U))
#define FTM_COMBINE_DECAPx_MASK_U32(u8ChannelIdx)       ((uint32)(BIT0 << FTM_COMBINE_DECAPx_SHIFT(u8ChannelIdx)))

#define FTM_COMBINE_DECAPENx_SHIFT(u8ChannelIdx)         ((uint32)((((u8ChannelIdx) >> 1U) * 8U)+ 2U))
#define FTM_COMBINE_DECAPENx_MASK_U32(u8ChannelIdx)      ((uint32)(BIT0 << FTM_COMBINE_DECAPENx_SHIFT(u8ChannelIdx)))

/**
@{
* @brief FTMx_DEADTIME - Deadtime Insertion Control - bitfield mask and shift defines.
*/

#ifdef IPV_FTM
    #if (IPV_FTM == IPV_FTM_05_00_04_00)
        #define FTM_DEADTIME_DTVALEX_MASK_U32  ((uint32)(BIT19|BIT18|BIT17|BIT16))
        #ifndef FTM_DEADTIME_DTVALEX_SHIFT
        #define FTM_DEADTIME_DTVALEX_SHIFT     ((uint32)(16U))
        #endif
    #endif
#endif

#define FTM_DEADTIME_DTPS_MASK_U32      ((uint32)(BIT7|BIT6))
#ifndef FTM_DEADTIME_DTPS_SHIFT
#define FTM_DEADTIME_DTPS_SHIFT         ((uint32)(6U))
#endif

#define FTM_DEADTIME_DTVAL_MASK_U32     ((uint32)(BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))

/**
@{
* @brief FTMx_EXTTRIG - FTM External Trigger - bitfield mask and shift defines.
*/
#define FTM_EXTTRIG_CH7TRIG_MASK_U32          ((uint32)(BIT9))
#ifndef FTM_EXTTRIG_CH7TRIG_SHIFT
#define FTM_EXTTRIG_CH7TRIG_SHIFT             ((uint32)(9U))
#endif

#define FTM_EXTTRIG_CH6TRIG_MASK_U32          ((uint32)(BIT8))
#ifndef FTM_EXTTRIG_CH6TRIG_SHIFT
#define FTM_EXTTRIG_CH6TRIG_SHIFT             ((uint32)(8U))
#endif

#define FTM_EXTTRIG_TRIGF_MASK_U32            ((uint32)(BIT7))
#ifndef FTM_EXTTRIG_TRIGF_SHIFT
#define FTM_EXTTRIG_TRIGF_SHIFT               ((uint32)(7U))
#endif

#define FTM_EXTTRIG_INITTRIGEN_MASK_U32       ((uint32)(BIT6))
#ifndef FTM_EXTTRIG_INITTRIGEN_SHIFT
#define FTM_EXTTRIG_INITTRIGEN_SHIFT          ((uint32)(6U))
#endif

#define FTM_EXTTRIG_CH1TRIG_MASK_U32          ((uint32)(BIT5))
#ifndef FTM_EXTTRIG_CH1TRIG_SHIFT
#define FTM_EXTTRIG_CH1TRIG_SHIFT             ((uint32)(5U))
#endif

#define FTM_EXTTRIG_CH0TRIG_MASK_U32          ((uint32)(BIT4))
#ifndef FTM_EXTTRIG_CH0TRIG_SHIFT
#define FTM_EXTTRIG_CH0TRIG_SHIFT             ((uint32)(4U))
#endif

#define FTM_EXTTRIG_CH5TRIG_MASK_U32          ((uint32)(BIT3))
#ifndef FTM_EXTTRIG_CH5TRIG_SHIFT
#define FTM_EXTTRIG_CH5TRIG_SHIFT             ((uint32)(3U))
#endif

#define FTM_EXTTRIG_CH4TRIG_MASK_U32          ((uint32)(BIT2))
#ifndef FTM_EXTTRIG_CH4TRIG_SHIFT
#define FTM_EXTTRIG_CH4TRIG_SHIFT             ((uint32)(2U))
#endif

#define FTM_EXTTRIG_CH3TRIG_MASK_U32          ((uint32)(BIT1))
#ifndef FTM_EXTTRIG_CH3TRIG_SHIFT
#define FTM_EXTTRIG_CH3TRIG_SHIFT             ((uint32)(1U))
#endif

#define FTM_EXTTRIG_CH2TRIG_MASK_U32          ((uint32)(BIT0))

/**
@{
* @brief FTMx_POL - Channels Polarity - bitfield mask and shift defines.
*/

#define FTM_POL_POL7_MASK_U32               ((uint32)(BIT7))
#ifndef FTM_POL_POL7_SHIFT
#define FTM_POL_POL7_SHIFT                  ((uint32)(7U))
#endif

#define FTM_POL_POL6_MASK_U32               ((uint32)(BIT6))
#ifndef FTM_POL_POL6_SHIFT
#define FTM_POL_POL6_SHIFT                  ((uint32)(6U))
#endif

#define FTM_POL_POL5_MASK_U32               ((uint32)(BIT5))
#ifndef FTM_POL_POL5_SHIFT
#define FTM_POL_POL5_SHIFT                  ((uint32)(5U))
#endif

#define FTM_POL_POL4_MASK_U32               ((uint32)(BIT4))
#ifndef FTM_POL_POL4_SHIFT
#define FTM_POL_POL4_SHIFT                  ((uint32)(4U))
#endif

#define FTM_POL_POL3_MASK_U32               ((uint32)(BIT3))
#ifndef FTM_POL_POL3_SHIFT
#define FTM_POL_POL3_SHIFT                  ((uint32)(3U))
#endif

#define FTM_POL_POL2_MASK_U32               ((uint32)(BIT2))
#ifndef FTM_POL_POL2_SHIFT
#define FTM_POL_POL2_SHIFT                  ((uint32)(2U))
#endif

#define FTM_POL_POL1_MASK_U32               ((uint32)(BIT1))
#ifndef FTM_POL_POL1_SHIFT
#define FTM_POL_POL1_SHIFT                  ((uint32)(1U))
#endif

#define FTM_POL_POL0_MASK_U32               ((uint32)(BIT0))

/**
@{
* @brief FTMx_FMS - Fault Mode Status - bitfield mask and shift defines.
*/

#define FTM_FMS_FAULTF_MASK_U32              ((uint32)(BIT7))
#ifndef FTM_FMS_FAULTF_SHIFT
#define FTM_FMS_FAULTF_SHIFT                 ((uint32)(7U))
#endif

#define FTM_FMS_WPEN_MASK_U32                ((uint32)(BIT6))
#ifndef FTM_FMS_WPEN_SHIFT
#define FTM_FMS_WPEN_SHIFT                   ((uint32)(6U))
#endif

#define FTM_FMS_FAULTIN_MASK_U32             ((uint32)(BIT5))
#ifndef FTM_FMS_FAULTIN_SHIFT
#define FTM_FMS_FAULTIN_SHIFT                ((uint32)(5U))
#endif

#define FTM_FMS_FAULTF3_MASK_U32             ((uint32)(BIT3))
#ifndef FTM_FMS_FAULTF3_SHIFT
#define FTM_FMS_FAULTF3_SHIFT                ((uint32)(3U))
#endif

#define FTM_FMS_FAULTF2_MASK_U32             ((uint32)(BIT2))
#ifndef FTM_FMS_FAULTF2_SHIFT
#define FTM_FMS_FAULTF2_SHIFT                ((uint32)(2U))
#endif

#define FTM_FMS_FAULTF1_MASK_U32             ((uint32)(BIT1))
#ifndef FTM_FMS_FAULTF1_SHIFT
#define FTM_FMS_FAULTF1_SHIFT                ((uint32)(1U))
#endif

#define FTM_FMS_FAULTF0_MASK_U32             ((uint32)(BIT0))

/**
@{
* @brief FTMx_FILTER - Input Capture Filter Control - bitfield mask and shift defines.
*/

#define FTM_FILTER_CH3FVAL_MASK_U32                 ((uint32)(BIT15|BIT14|BIT13|BIT12))
#ifndef FTM_FILTER_CH3FVAL_SHIFT
#define FTM_FILTER_CH3FVAL_SHIFT                    ((uint32)(12U))
#endif

#define FTM_FILTER_CH2FVAL_MASK_U32                 ((uint32)(BIT11|BIT10|BIT9|BIT8))
#ifndef FTM_FILTER_CH2FVAL_SHIFT
#define FTM_FILTER_CH2FVAL_SHIFT                    ((uint32)(8U))
#endif

#define FTM_FILTER_CH1FVAL_MASK_U32                 ((uint32)(BIT7|BIT6|BIT5|BIT4))
#ifndef FTM_FILTER_CH1FVAL_SHIFT
#define FTM_FILTER_CH1FVAL_SHIFT                    ((uint32)(4U))
#endif

#define FTM_FILTER_CH0FVAL_MASK_U32                 ((uint32)(BIT3|BIT2|BIT1|BIT0))
#ifndef FTM_FILTER_CH0FVAL_SHIFT
#define FTM_FILTER_CH0FVAL_SHIFT                    ((uint32)(0U))
#endif

#define FTM_FILTER_CHxFVAL_SHIFT(u8ChannelIdx)      ((uint32)((u8ChannelIdx) << 2UL))
#define FTM_FILTER_CHxFVAL_MASK_U32(u8ChannelIdx)   (FTM_FILTER_CH0FVAL_MASK_U32 << \
                                                    FTM_FILTER_CHxFVAL_SHIFT(u8ChannelIdx))

#define FTM_FILTER_MAX_NO_CH                        ((uint8)(4U))
/**
@{
* @brief FTMx_FLTCTRL - Fault Control - bitfield mask and shift defines.
*/

#define FTM_FLTCTRL_FSTATE_MASK_U32          ((uint32)(BIT15))
#ifndef FTM_FLTCTRL_FSTATE_SHIFT       
#define FTM_FLTCTRL_FSTATE_SHIFT             ((uint32)(15U))
#endif

#define FTM_FLTCTRL_FFVAL_MASK_U32           ((uint32)(BIT11|BIT10|BIT9|BIT8))
#ifndef FTM_FLTCTRL_FFVAL_SHIFT
#define FTM_FLTCTRL_FFVAL_SHIFT              ((uint32)(8U))
#endif

#define FTM_FLTCTRL_FFLTR3EN_MASK_U32        ((uint32)(BIT7))
#ifndef FTM_FLTCTRL_FFLTR3EN_SHIFT
#define FTM_FLTCTRL_FFLTR3EN_SHIFT           ((uint32)(7U))
#endif

#define FTM_FLTCTRL_FFLTR2EN_MASK_U32        ((uint32)(BIT6))
#ifndef FTM_FLTCTRL_FFLTR2EN_SHIFT
#define FTM_FLTCTRL_FFLTR2EN_SHIFT           ((uint32)(6U))
#endif

#define FTM_FLTCTRL_FFLTR1EN_MASK_U32        ((uint32)(BIT5))
#ifndef FTM_FLTCTRL_FFLTR1EN_SHIFT
#define FTM_FLTCTRL_FFLTR1EN_SHIFT           ((uint32)(5U))
#endif

#define FTM_FLTCTRL_FFLTR0EN_MASK_U32        ((uint32)(BIT4))
#ifndef FTM_FLTCTRL_FFLTR0EN_SHIFT
#define FTM_FLTCTRL_FFLTR0EN_SHIFT           ((uint32)(4U))
#endif

#define FTM_FLTCTRL_FAULT3EN_MASK_U32        ((uint32)(BIT3))
#ifndef FTM_FLTCTRL_FAULT3EN_SHIFT
#define FTM_FLTCTRL_FAULT3EN_SHIFT           ((uint32)(3U))
#endif

#define FTM_FLTCTRL_FAULT2EN_MASK_U32        ((uint32)(BIT2))
#ifndef FTM_FLTCTRL_FAULT2EN_SHIFT
#define FTM_FLTCTRL_FAULT2EN_SHIFT           ((uint32)(2U))
#endif

#define FTM_FLTCTRL_FAULT1EN_MASK_U32        ((uint32)(BIT1))
#ifndef FTM_FLTCTRL_FAULT1EN_SHIFT
#define FTM_FLTCTRL_FAULT1EN_SHIFT           ((uint32)(1U))
#endif

#define FTM_FLTCTRL_FAULT0EN_MASK_U32        ((uint32)(BIT0))

/**
@{
* @brief FTMx_QDCTRL - Quadrature Decoder Control And Status - bitfield mask and shift defines.
*/

#define FTM_QDCTRL_PHAFLTREN_MASK_U32        ((uint32)(BIT7))
#ifndef FTM_QDCTRL_PHAFLTREN_SHIFT
#define FTM_QDCTRL_PHAFLTREN_SHIFT           ((uint32)(7U))
#endif

#define FTM_QDCTRL_PHBFLTREN_MASK_U32        ((uint32)(BIT6))
#ifndef FTM_QDCTRL_PHBFLTREN_SHIFT
#define FTM_QDCTRL_PHBFLTREN_SHIFT           ((uint32)(6U))
#endif

#define FTM_QDCTRL_PHAPOL_MASK_U32           ((uint32)(BIT5))
#ifndef FTM_QDCTRL_PHAPOL_SHIFT
#define FTM_QDCTRL_PHAPOL_SHIFT              ((uint32)(5U))
#endif

#define FTM_QDCTRL_PHBPOL_MASK_U32           ((uint32)(BIT4))
#ifndef FTM_QDCTRL_PHBPOL_SHIFT
#define FTM_QDCTRL_PHBPOL_SHIFT              ((uint32)(4U))
#endif

#define FTM_QDCTRL_QUADMODE_MASK_U32         ((uint32)(BIT3))
#ifndef FTM_QDCTRL_QUADMODE_SHIFT
#define FTM_QDCTRL_QUADMODE_SHIFT            ((uint32)(3U))
#endif

#define FTM_QDCTRL_QUADIR_MASK_U32           ((uint32)(BIT2))
#ifndef FTM_QDCTRL_QUADIR_SHIFT
#define FTM_QDCTRL_QUADIR_SHIFT              ((uint32)(2U))
#endif

#define FTM_QDCTRL_TOFDIR_MASK_U32           ((uint32)(BIT1))
#ifndef FTM_QDCTRL_TOFDIR_SHIFT
#define FTM_QDCTRL_TOFDIR_SHIFT              ((uint32)(1U))
#endif

#define FTM_QDCTRL_QUADEN_MASK_U32           ((uint32)(BIT0))

/**
@{
* @brief FTMx_CONF - Configuration - bitfield mask and shift defines.
*/

#define FTM_CONF_GTBEOUT_MASK_U32           ((uint32)(BIT10))
#ifndef FTM_CONF_GTBEOUT_SHIFT
#define FTM_CONF_GTBEOUT_SHIFT              ((uint32)(10U))
#endif

#define FTM_CONF_GTBEEN_MASK_U32            ((uint32)(BIT9))
#ifndef FTM_CONF_GTBEEN_SHIFT
#define FTM_CONF_GTBEEN_SHIFT               ((uint32)(9U))
#endif

#define FTM_CONF_BDMMODE_MASK_U32           ((uint32)(BIT7|BIT6))
#ifndef FTM_CONF_BDMMODE_SHIFT
#define FTM_CONF_BDMMODE_SHIFT              ((uint32)(6U))
#endif

#define FTM_CONF_NUMTOF_MASK_U32            ((uint32)(BIT4|BIT3|BIT2|BIT1|BIT0))


/**
@{
* @brief FTMx_FLTPOL - Fault Input Polarity - bitfield mask and shift defines.
*/

#define FTM_FLTPOL_FLT3POL_MASK_U32         ((uint32)(BIT3))
#ifndef FTM_FLTPOL_FLT3POL_SHIFT
#define FTM_FLTPOL_FLT3POL_SHIFT            ((uint32)(3U))
#endif

#define FTM_FLTPOL_FLT2POL_MASK_U32         ((uint32)(BIT2))
#ifndef FTM_FLTPOL_FLT2POL_SHIFT
#define FTM_FLTPOL_FLT2POL_SHIFT            ((uint32)(2U))
#endif

#define FTM_FLTPOL_FLT1POL_MASK_U32         ((uint32)(BIT1))
#ifndef FTM_FLTPOL_FLT1POL_SHIFT
#define FTM_FLTPOL_FLT1POL_SHIFT            ((uint32)(1U))
#endif

#define FTM_FLTPOL_FLT0POL_MASK_U32         ((uint32)(BIT0))


/**
@{
* @brief FTMx_SYNCONF - Synchronization Configuration - bitfield mask and shift defines.
*/

#define FTM_SYNCONF_HWSOC_MASK_U32          ((uint32)(BIT20))
#ifndef FTM_SYNCONF_HWSOC_SHIFT
#define FTM_SYNCONF_HWSOC_SHIFT             ((uint32)(20U))
#endif

#define FTM_SYNCONF_HWINVC_MASK_U32         ((uint32)(BIT19))
#ifndef FTM_SYNCONF_HWINVC_SHIFT
#define FTM_SYNCONF_HWINVC_SHIFT            ((uint32)(19U))
#endif

#define FTM_SYNCONF_HWOM_MASK_U32           ((uint32)(BIT18))
#ifndef FTM_SYNCONF_HWOM_SHIFT
#define FTM_SYNCONF_HWOM_SHIFT              ((uint32)(18U))
#endif

#define FTM_SYNCONF_HWWRBUF_MASK_U32        ((uint32)(BIT17))
#ifndef FTM_SYNCONF_HWWRBUF_SHIFT
#define FTM_SYNCONF_HWWRBUF_SHIFT           ((uint32)(17U))
#endif

#define FTM_SYNCONF_HWRSTCNT_MASK_U32       ((uint32)(BIT16))
#ifndef FTM_SYNCONF_HWRSTCNT_SHIFT
#define FTM_SYNCONF_HWRSTCNT_SHIFT          ((uint32)(16U))
#endif

#define FTM_SYNCONF_SWSOC_MASK_U32          ((uint32)(BIT12))
#ifndef FTM_SYNCONF_SWSOC_SHIFT
#define FTM_SYNCONF_SWSOC_SHIFT             ((uint32)(12U))
#endif

#define FTM_SYNCONF_SWINVC_MASK_U32         ((uint32)(BIT11))
#ifndef FTM_SYNCONF_SWINVC_SHIFT
#define FTM_SYNCONF_SWINVC_SHIFT            ((uint32)(11U))
#endif

#define FTM_SYNCONF_SWOM_MASK_U32           ((uint32)(BIT10))
#ifndef FTM_SYNCONF_SWOM_SHIFT
#define FTM_SYNCONF_SWOM_SHIFT              ((uint32)(10U))
#endif

#define FTM_SYNCONF_SWWRBUF_MASK_U32        ((uint32)(BIT9))
#ifndef FTM_SYNCONF_SWWRBUF_SHIFT
#define FTM_SYNCONF_SWWRBUF_SHIFT           ((uint32)(9U))
#endif

#define FTM_SYNCONF_SWRSTCNT_MASK_U32       ((uint32)(BIT8))
#ifndef FTM_SYNCONF_SWRSTCNT_SHIFT
#define FTM_SYNCONF_SWRSTCNT_SHIFT          ((uint32)(8U))
#endif

#define FTM_SYNCONF_SYNCMODE_MASK_U32       ((uint32)(BIT7))
#ifndef FTM_SYNCONF_SYNCMODE_SHIFT
#define FTM_SYNCONF_SYNCMODE_SHIFT          ((uint32)(7U))
#endif

#define FTM_SYNCONF_SWOC_MASK_U32           ((uint32)(BIT5))
#ifndef FTM_SYNCONF_SWOC_SHIFT
#define FTM_SYNCONF_SWOC_SHIFT              ((uint32)(5U))
#endif

#define FTM_SYNCONF_INVC_MASK_U32           ((uint32)(BIT4))
#ifndef FTM_SYNCONF_INVC_SHIFT
#define FTM_SYNCONF_INVC_SHIFT              ((uint32)(4U))
#endif

#define FTM_SYNCONF_CNTINC_MASK_U32         ((uint32)(BIT2))
#ifndef FTM_SYNCONF_CNTINC_SHIFT
#define FTM_SYNCONF_CNTINC_SHIFT            ((uint32)(2U))
#endif

#define FTM_SYNCONF_HWTRIGMODE_MASK_U32     ((uint32)(BIT0))


/**
@{
* @brief FTMx_INVCTRL - Inverting Control - bitfield mask and shift defines.
*/

#define FTM_INVCTRL_INV3EN_MASK_U32     ((uint32)(BIT3))
#ifndef FTM_INVCTRL_INV3EN_SHIFT
#define FTM_INVCTRL_INV3EN_SHIFT        ((uint32)(3U))
#endif

#define FTM_INVCTRL_INV2EN_MASK_U32     ((uint32)(BIT2))
#ifndef FTM_INVCTRL_INV2EN_SHIFT
#define FTM_INVCTRL_INV2EN_SHIFT        ((uint32)(2U))
#endif

#define FTM_INVCTRL_INV1EN_MASK_U32     ((uint32)(BIT1))
#ifndef FTM_INVCTRL_INV1EN_SHIFT
#define FTM_INVCTRL_INV1EN_SHIFT        ((uint32)(1U))
#endif

#define FTM_INVCTRL_INV0EN_MASK_U32     ((uint32)(BIT0))

/**
@{
* @brief FTMx_SWOCTRL - Software Output Control - bitfield mask and shift defines.
*/

#define FTM_SWOCTRL_CH7OCV_MASK_U32     ((uint32)(BIT15))
#ifndef FTM_SWOCTRL_CH7OCV_SHIFT
#define FTM_SWOCTRL_CH7OCV_SHIFT        ((uint32)(15U))
#endif

#define FTM_SWOCTRL_CH6OCV_MASK_U32     ((uint32)(BIT14))
#ifndef FTM_SWOCTRL_CH6OCV_SHIFT
#define FTM_SWOCTRL_CH6OCV_SHIFT        ((uint32)(14U))
#endif

#define FTM_SWOCTRL_CH5OCV_MASK_U32     ((uint32)(BIT13))
#ifndef FTM_SWOCTRL_CH5OCV_SHIFT
#define FTM_SWOCTRL_CH5OCV_SHIFT        ((uint32)(13U))
#endif

#define FTM_SWOCTRL_CH4OCV_MASK_U32     ((uint32)(BIT12))
#ifndef FTM_SWOCTRL_CH4OCV_SHIFT
#define FTM_SWOCTRL_CH4OCV_SHIFT        ((uint32)(12U))
#endif

#define FTM_SWOCTRL_CH3OCV_MASK_U32     ((uint32)(BIT11))
#ifndef FTM_SWOCTRL_CH3OCV_SHIFT
#define FTM_SWOCTRL_CH3OCV_SHIFT        ((uint32)(11U))
#endif

#define FTM_SWOCTRL_CH2OCV_MASK_U32     ((uint32)(BIT10))
#ifndef FTM_SWOCTRL_CH2OCV_SHIFT
#define FTM_SWOCTRL_CH2OCV_SHIFT        ((uint32)(10U))
#endif

#define FTM_SWOCTRL_CH1OCV_MASK_U32     ((uint32)(BIT9))
#ifndef FTM_SWOCTRL_CH1OCV_SHIFT
#define FTM_SWOCTRL_CH1OCV_SHIFT        ((uint32)(9U))
#endif

#define FTM_SWOCTRL_CH0OCV_MASK_U32     ((uint32)(BIT8))
#ifndef FTM_SWOCTRL_CH0OCV_SHIFT
#define FTM_SWOCTRL_CH0OCV_SHIFT        ((uint32)(8U))
#endif

#define FTM_SWOCTRL_CH7OC_MASK_U32     ((uint32)(BIT7))
#ifndef FTM_SWOCTRL_CH7OC_SHIFT
#define FTM_SWOCTRL_CH7OC_SHIFT        ((uint32)(7U))
#endif

#define FTM_SWOCTRL_CH6OC_MASK_U32     ((uint32)(BIT6))
#ifndef FTM_SWOCTRL_CH6OC_SHIFT
#define FTM_SWOCTRL_CH6OC_SHIFT        ((uint32)(6U))
#endif

#define FTM_SWOCTRL_CH5OC_MASK_U32     ((uint32)(BIT5))
#ifndef FTM_SWOCTRL_CH5OC_SHIFT
#define FTM_SWOCTRL_CH5OC_SHIFT        ((uint32)(5U))
#endif

#define FTM_SWOCTRL_CH4OC_MASK_U32     ((uint32)(BIT4))
#ifndef FTM_SWOCTRL_CH4OC_SHIFT
#define FTM_SWOCTRL_CH4OC_SHIFT        ((uint32)(4U))
#endif

#define FTM_SWOCTRL_CH3OC_MASK_U32     ((uint32)(BIT3))
#ifndef FTM_SWOCTRL_CH3OC_SHIFT
#define FTM_SWOCTRL_CH3OC_SHIFT        ((uint32)(3U))
#endif

#define FTM_SWOCTRL_CH2OC_MASK_U32     ((uint32)(BIT2))
#ifndef FTM_SWOCTRL_CH2OC_SHIFT
#define FTM_SWOCTRL_CH2OC_SHIFT        ((uint32)(2U))
#endif

#define FTM_SWOCTRL_CH1OC_MASK_U32     ((uint32)(BIT1))
#ifndef FTM_SWOCTRL_CH1OC_SHIFT
#define FTM_SWOCTRL_CH1OC_SHIFT        ((uint32)(1U))
#endif

#define FTM_SWOCTRL_CH0OC_MASK_U32     ((uint32)(BIT0))

/**
@{
* @brief FTMx_PWMLOAD - PWM Load - bitfield mask and shift defines.
*/

#define FTM_PWMLOAD_LDOK_MASK_U32       ((uint32)(BIT9))
#ifndef FTM_PWMLOAD_LDOK_SHIFT
#define FTM_PWMLOAD_LDOK_SHIFT          ((uint32)(9U))
#endif

#define FTM_PWMLOAD_CH7SEL_MASK_U32     ((uint32)(BIT7))
#ifndef FTM_PWMLOAD_CH7SEL_SHIFT
#define FTM_PWMLOAD_CH7SEL_SHIFT        ((uint32)(7U))
#endif

#define FTM_PWMLOAD_CH6SEL_MASK_U32     ((uint32)(BIT6))
#ifndef FTM_PWMLOAD_CH6SEL_SHIFT
#define FTM_PWMLOAD_CH6SEL_SHIFT        ((uint32)(6U))
#endif

#define FTM_PWMLOAD_CH5SEL_MASK_U32     ((uint32)(BIT5))
#ifndef FTM_PWMLOAD_CH5SEL_SHIFT
#define FTM_PWMLOAD_CH5SEL_SHIFT        ((uint32)(5U))
#endif

#define FTM_PWMLOAD_CH4SEL_MASK_U32     ((uint32)(BIT4))
#ifndef FTM_PWMLOAD_CH4SEL_SHIFT
#define FTM_PWMLOAD_CH4SEL_SHIFT        ((uint32)(4U))
#endif

#define FTM_PWMLOAD_CH3SEL_MASK_U32     ((uint32)(BIT3))
#ifndef FTM_PWMLOAD_CH3SEL_SHIFT
#define FTM_PWMLOAD_CH3SEL_SHIFT        ((uint32)(3U))
#endif

#define FTM_PWMLOAD_CH2SEL_MASK_U32     ((uint32)(BIT2))
#ifndef FTM_PWMLOAD_CH2SEL_SHIFT
#define FTM_PWMLOAD_CH2SEL_SHIFT        ((uint32)(2U))
#endif

#define FTM_PWMLOAD_CH1SEL_MASK_U32     ((uint32)(BIT1))
#ifndef FTM_PWMLOAD_CH1SEL_SHIFT
#define FTM_PWMLOAD_CH1SEL_SHIFT        ((uint32)(1U))
#endif

#define FTM_PWMLOAD_CH0SEL_MASK_U32     ((uint32)(BIT0))


/** Bitfield defines. */
/**
* @{
* @brief FTMx_CnSC - bitfield defines.
*/

#define FTM_CSC_CHF_NO_EVENT_U32         ((uint32)(0U))
#define FTM_CSC_CHF_EVENT_OCCURED_U32    ((uint32)(1U) << FTM_CSC_CHF_SHIFT)
#define FTM_CSC_CHIE_DISABLE_U32         ((uint32)(0U))
#define FTM_CSC_CHIE_ENABLE_U32          ((uint32)(1U) << FTM_CSC_CHIE_SHIFT )

#define FTM_CSC_MSX_PWMFORM_U32          ((uint32)(1U) << FTM_CSC_MSB_SHIFT )

#define FTM_CSC_ELSX_PWMFORM_U32         ((uint32)(1U) << FTM_CSC_ELSB_SHIFT )


#define FTM_CSC_DMA_DISABLE_U32          ((uint32)(0U))
#define FTM_CSC_DMA_ENABLE_U32           ((uint32)(1U))

/**
* @{
* @brief FTMx_SC - bitfield defines.
*/

#define FTM_SC_TOF_NO_OVF_U32                ((uint32)(0U)) 
#define FTM_SC_TOF_OVF_U32                   ((uint32)(1U) << FTM_SC_TOF_SHIFT)
#define FTM_SC_TOIE_DISABLE_U32              ((uint32)(0U))
#define FTM_SC_TOIE_ENABLE_U32               ((uint32)(1U) << FTM_SC_TOIE_SHIFT)
#define FTM_SC_CPWMS_UP_COUNTING_U32         ((uint32)(0U) << FTM_SC_CPWMS_SHIFT)
#define FTM_SC_CPWMS_UP_DOWN_COUNTING_U32    ((uint32)(1U) << FTM_SC_CPWMS_SHIFT)
#define FTM_SC_CLKS_NO_CLOCKS_U32            ((uint32)(0U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_CLKS_SYS_CLOCK_U32            ((uint32)(1U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_CLKS_FIXED_FREQ_CLOCK_U32     ((uint32)(2U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_CLKS_EXTERNAL_CLOCK_U32       ((uint32)(3U) << FTM_SC_CLKS_SHIFT)
#define FTM_SC_PS_DIV1_U32                   ((uint32)(0U))
#define FTM_SC_PS_DIV2_U32                   ((uint32)(1U))
#define FTM_SC_PS_DIV4_U32                   ((uint32)(2U))
#define FTM_SC_PS_DIV8_U32                   ((uint32)(3U))
#define FTM_SC_PS_DIV16_U32                  ((uint32)(4U))
#define FTM_SC_PS_DIV32_U32                  ((uint32)(5U))
#define FTM_SC_PS_DIV64_U32                  ((uint32)(6U))
#define FTM_SC_PS_DIV128_U32                 ((uint32)(7U))
#define FTM_SC_PWMOUTPUTEN_SHIFT             ((uint32)(16U))



/**
* @{
* @brief FTMx_MODE - bitfield defines.
*/

#define FTM_MODE_FAULTIE_DISABLE_U32        ((uint32)(0U))
#define FTM_MODE_FAULTIE_ENABLE_U32         ((uint32)(1U) << FTM_MODE_FAULTIE_SHIFT)
#define FTM_MODE_FAULTM_DISABLED_U32        ((uint32)(0U))
#define FTM_MODE_FAULTM_ENABLE_EVEN_U32     ((uint32)(1U) << FTM_MODE_FAULTM_SHIFT)
#define FTM_MODE_FAULTM_ENABLED_MANUAL_U32  ((uint32)(2U) << FTM_MODE_FAULTM_SHIFT)
#define FTM_MODE_FAULTM_ENABLED_AUTO_U32    ((uint32)(3U) << FTM_MODE_FAULTM_SHIFT)
#define FTM_MODE_CAPTEST_DISABLE_U32        ((uint32)(0U))
#define FTM_MODE_CAPTEST_ENABLE_U32         ((uint32)(1U) << FTM_MODE_CAPTEST_SHIFT)

#define FTM_MODE_PWMSYNC_ENABLE_U32         ((uint32)(1U) << FTM_MODE_PWMSYNC_SHIFT)
#define FTM_MODE_PWMSYNC_DISABLE_U32        ((uint32)(0U))

#define FTM_MODE_WPDIS_ENABLE_U32           ((uint32)(0U)) 
#define FTM_MODE_WPDIS_DISABLE_U32          ((uint32)(1U) << FTM_MODE_WPDIS_SHIFT)

#define FTM_MODE_INIT_ENABLE_U32            ((uint32)(1U) << FTM_MODE_INIT_SHIFT) 
#define FTM_MODE_INIT_DISABLE_U32           ((uint32)(0U))

#define FTM_MODE_FTMEN_ENABLE_U32           ((uint32)(1U)) 
#define FTM_MODE_FTMEN_DISABLE_U32          ((uint32)(0U))


/**
* @{
* @brief FTMx_SYNC - bitfield defines.
*/
#define FTM_SYNC_SWSYNC_SELECTED_U32        ((uint32)(1U))
#define FTM_SYNC_SWSYNC_NOT_SELECTED_U32    ((uint32)(0U))
#define FTM_SYNC_TRIG2_DISABLE_U32          ((uint32)(0U))
#define FTM_SYNC_TRIG2_ENABLE_U32           ((uint32)(1U))
#define FTM_SYNC_TRIG1_DISABLE_U32          ((uint32)(0U))
#define FTM_SYNC_TRIG1_ENABLE_U32           ((uint32)(1U))
#define FTM_SYNC_TRIG0_DISABLE_U32          ((uint32)(0U))
#define FTM_SYNC_TRIG0_ENABLE_U32           ((uint32)(1U))
#define FTM_SYNC_SYNCHOM_RISING_EDGE_U32    ((uint32)(0U))
#define FTM_SYNC_SYNCHOM_SYNC_U32           ((uint32)(1U))

#define FTM_SYNC_REINIT_DISABLE_U32         ((uint32)(0U))
#define FTM_SYNC_REINIT_ENABLE_U32          ((uint32)(1U))

#define FTM_SYNC_CNTMAX_DISABLE_U32         ((uint32)(0U))
#define FTM_SYNC_CNTMAX_ENABLE_U32          ((uint32)(1U))
#define FTM_SYNC_CNTMIN_DISABLE_U32         ((uint32)(0U))
#define FTM_SYNC_CNTMIN_ENABLE_U32          ((uint32)(1U))


/**
* @{
* @brief FTMx_COMBINE - bitfield defines.
*/
#define FTM_COMBINE_MCOMBINE3_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE3_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_MCOMBINE3_SHIFT)
#define FTM_COMBINE_FAULTEN3_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN3_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN3_SHIFT)
#define FTM_COMBINE_SYNCEN3_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN3_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN3_SHIFT)
#define FTM_COMBINE_DTEN3_DISABLE_U32        ((uint32)(0U)) 
#define FTM_COMBINE_DTEN3_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN3_SHIFT)
#define FTM_COMBINE_DECAP3_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP3_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP3_SHIFT)
#define FTM_COMBINE_COMP3_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP3_COMPLEMENT_U32     ((uint32)(1U) << FTM_COMBINE_COMP3_SHIFT)
#define FTM_COMBINE_COMBINE3_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE3_COMBINED_U32    ((uint32)(1U)  << FTM_COMBINE_COMBINE3_SHIFT)

#define FTM_COMBINE_MCOMBINE2_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE2_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_MCOMBINE2_SHIFT)
#define FTM_COMBINE_FAULTEN2_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN2_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN2_SHIFT)
#define FTM_COMBINE_SYNCEN2_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN2_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN2_SHIFT)
#define FTM_COMBINE_DTEN2_DISABLE_U32        ((uint32)(0U))
#define FTM_COMBINE_DTEN2_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN2_SHIFT)
#define FTM_COMBINE_DECAP2_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP2_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP2_SHIFT)
#define FTM_COMBINE_COMP2_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP2_COMPLEMENT_U32     ((uint32)(1U)  << FTM_COMBINE_COMP2_SHIFT)
#define FTM_COMBINE_COMBINE2_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE2_COMBINED_U32    ((uint32)(1U) << FTM_COMBINE_COMBINE2_SHIFT)

#define FTM_COMBINE_MCOMBINE1_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE1_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_MCOMBINE1_SHIFT)
#define FTM_COMBINE_FAULTEN1_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN1_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN1_SHIFT)
#define FTM_COMBINE_SYNCEN1_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN1_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN1_SHIFT)
#define FTM_COMBINE_DTEN1_DISABLE_U32        ((uint32)(0U))
#define FTM_COMBINE_DTEN1_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN1_SHIFT)
#define FTM_COMBINE_DECAP1_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP1_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP1_SHIFT)
#define FTM_COMBINE_COMP1_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP1_COMPLEMENT_U32     (((uint32)(1U)) << FTM_COMBINE_COMP1_SHIFT)
#define FTM_COMBINE_COMBINE1_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE1_COMBINED_U32    ((uint32)(1U) << FTM_COMBINE_COMBINE1_SHIFT)

#define FTM_COMBINE_MCOMBINE0_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_MCOMBINE0_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_MCOMBINE0_SHIFT)
#define FTM_COMBINE_FAULTEN0_DISABLE_U32     ((uint32)(0U))
#define FTM_COMBINE_FAULTEN0_ENABLE_U32      ((uint32)(1U) << FTM_COMBINE_FAULTEN0_SHIFT)
#define FTM_COMBINE_SYNCEN0_DISABLE_U32      ((uint32)(0U))
#define FTM_COMBINE_SYNCEN0_ENABLE_U32       ((uint32)(1U) << FTM_COMBINE_SYNCEN0_SHIFT)
#define FTM_COMBINE_DTEN0_DISABLE_U32        ((uint32)(0U))
#define FTM_COMBINE_DTEN0_ENABLE_U32         ((uint32)(1U) << FTM_COMBINE_DTEN0_SHIFT)
#define FTM_COMBINE_DECAP0_INACTIVE_U32      ((uint32)(0U))
#define FTM_COMBINE_DECAP0_ACTIVE_U32        ((uint32)(1U) << FTM_COMBINE_DECAP0_SHIFT)
#define FTM_COMBINE_COMP0_SAME_U32           ((uint32)(0U))
#define FTM_COMBINE_COMP0_COMPLEMENT_U32     ((uint32)(1U) << FTM_COMBINE_COMP0_SHIFT)
#define FTM_COMBINE_COMBINE0_INDEPENDENT_U32 ((uint32)(0U))
#define FTM_COMBINE_COMBINE0_COMBINED_U32    ((uint32)(1U))


/**
* @{
* @brief FTMx_DEADTIME - bitfield defines.
*/

#define FTM_DEADTIME_DTPS_DIV1_U32          ((uint32)(0U)) 
#define FTM_DEADTIME_DTPS_DIV4_U32          (((uint32)(2U)) << FTM_DEADTIME_DTPS_SHIFT)
#define FTM_DEADTIME_DTPS_DIV16_U32         (((uint32)(3U)) << FTM_DEADTIME_DTPS_SHIFT)



/**
* @{
* @brief FTMx_EXTTRIG - bitfield defines.
*/
#define FTM_EXTTRIG_TRIGF_TRIGGER_U32       ((uint32)(1U))
#define FTM_EXTTRIG_TRIGF_NO_TRIGGER_U32    ((uint32)(0U))
#define FTM_EXTTRIG_INITTRIGEN_ENABLE_U32   ((uint32)(1U))
#define FTM_EXTTRIG_INITTRIGEN_DISABLE_U32  ((uint32)(0U))
#define FTM_EXTTRIG_CH1TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH1TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH0TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH0TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH5TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH5TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH4TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH4TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH3TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH3TRIG_ENABLE_U32      ((uint32)(1U))
#define FTM_EXTTRIG_CH2TRIG_DISABLE_U32     ((uint32)(0U))
#define FTM_EXTTRIG_CH2TRIG_ENABLE_U32      ((uint32)(1U))

/**
* @{
* @brief FTMx_POL - bitfield defines.
*/
#define FTM_POL_POL7_LOW_U32            ((uint32)(1U) << FTM_POL_POL7_SHIFT)
#define FTM_POL_POL7_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL6_LOW_U32            ((uint32)(1U) << FTM_POL_POL6_SHIFT)
#define FTM_POL_POL6_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL5_LOW_U32            ((uint32)(1U) << FTM_POL_POL5_SHIFT)
#define FTM_POL_POL5_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL4_LOW_U32            ((uint32)(1U) << FTM_POL_POL4_SHIFT)
#define FTM_POL_POL4_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL3_LOW_U32            ((uint32)(1U) << FTM_POL_POL3_SHIFT)
#define FTM_POL_POL3_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL2_LOW_U32            ((uint32)(1U) << FTM_POL_POL2_SHIFT)
#define FTM_POL_POL2_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL1_LOW_U32            ((uint32)(1U) << FTM_POL_POL1_SHIFT)
#define FTM_POL_POL1_HIGH_U32           ((uint32)(0U))
#define FTM_POL_POL0_LOW_U32            ((uint32)(1U))
#define FTM_POL_POL0_HIGH_U32           ((uint32)(0U))

/**
* @{
* @brief FTMx_FMS - bitfield defines.
*/
#define FTM_FMS_FAULTF_FAULT_U32            ((uint32)(1U) << FTM_FMS_FAULTF_SHIFT)
#define FTM_FMS_FAULTF_NO_FAULT_U32         ((uint32)(0U))
#define FTM_FMS_WPEN_ENABLE_U32             (((uint32)(1U)) << FTM_FMS_WPEN_SHIFT)
#define FTM_FMS_WPEN_DISABLE_U32            ((uint32)(0U))
#define FTM_FMS_FAULTIN_LOGIC_OR_IS_0_U32   ((uint32)(0U)) /*TO DO: check again*/
#define FTM_FMS_FAULTIN_LOGIC_OR_IS_1_U32   ((uint32)(1U) << FTM_FMS_FAULTIN_SHIFT)
#define FTM_FMS_FAULTF3_FAULT_U32           ((uint32)(1U) << FTM_FMS_FAULTF3_SHIFT)
#define FTM_FMS_FAULTF3_NO_FAULT_U32        ((uint32)(0U))  
#define FTM_FMS_FAULTF2_FAULT_U32           ((uint32)(1U) << FTM_FMS_FAULTF2_SHIFT)
#define FTM_FMS_FAULTF2_NO_FAULT_U32        ((uint32)(0U))  
#define FTM_FMS_FAULTF1_FAULT_U32           ((uint32)(1U) << FTM_FMS_FAULTF1_SHIFT)
#define FTM_FMS_FAULTF1_NO_FAULT_U32        ((uint32)(0U))  
#define FTM_FMS_FAULTF0_FAULT_U32           ((uint32)(1U))
#define FTM_FMS_FAULTF0_NO_FAULT_U32        ((uint32)(0U))  

/**
* @{
* @brief FTMx_FLTCTRL - bitfield defines.
*/
#define FTM_FLTCTRL_FLTSTATE_SAFEVALUE_U32  ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR3EN_TRISTATE_U32   ((uint32)(1U) << FTM_FLTCTRL_FSTATE_SHIFT)
#define FTM_FLTCTRL_FFVAL_U32(value)        (((uint32)(value)) << FTM_FLTCTRL_FFVAL_SHIFT)
#define FTM_FLTCTRL_FFLTR3EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR3EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR3EN_SHIFT)
#define FTM_FLTCTRL_FFLTR2EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR2EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR2EN_SHIFT)
#define FTM_FLTCTRL_FFLTR1EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR1EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR1EN_SHIFT)
#define FTM_FLTCTRL_FFLTR0EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FFLTR0EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FFLTR0EN_SHIFT)
#define FTM_FLTCTRL_FAULT3EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT3EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FAULT3EN_SHIFT)
#define FTM_FLTCTRL_FAULT2EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT2EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FAULT2EN_SHIFT)
#define FTM_FLTCTRL_FAULT1EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT1EN_ENABLE_U32     ((uint32)(1U) << FTM_FLTCTRL_FAULT1EN_SHIFT)
#define FTM_FLTCTRL_FAULT0EN_DISABLE_U32    ((uint32)(0U))
#define FTM_FLTCTRL_FAULT0EN_ENABLE_U32     ((uint32)(1U))

/**
* @{
* @brief FTMx_QDCTRL - bitfield defines.
*/

#define FTM_QDCTRL_PHAFLTREN_ENABLE_U32     ((uint32)(1U))
#define FTM_QDCTRL_PHAFLTREN_DISABLE_U32    ((uint32)(0U))
#define FTM_QDCTRL_PHBFLTREN_ENABLE_U32     ((uint32)(1U))
#define FTM_QDCTRL_PHBFLTREN_DISABLE_U32    ((uint32)(0U))
#define FTM_QDCTRL_PHAPOL_NORMAL_U32        ((uint32)(0U))
#define FTM_QDCTRL_PHAPOL_INVERTED_U32      ((uint32)(1U))
#define FTM_QDCTRL_PHBPOL_NORMAL_U32        ((uint32)(0U))
#define FTM_QDCTRL_PHBPOL_INVERTED_U32      ((uint32)(1U))
#define FTM_QDCTRL_PHA_PHB_MODE_U32         ((uint32)(0U))
#define FTM_QDCTRL_COUNT_DIRECTION_MODE_U32 ((uint32)(1U))
#define FTM_QDCTRL_QUADIR_DECREMENT_U32     ((uint32)(0U))
#define FTM_QDCTRL_QUADIR_INCREMENT_U32     ((uint32)(1U))
#define FTM_QDCTRL_TOFDIR_BOTTOM_U32        ((uint32)(0U))
#define FTM_QDCTRL_TOFDIR_TOP_U32           ((uint32)(1U))
#define FTM_QDCTRL_QUADEN_DISABLE_U32       ((uint32)(0U))
#define FTM_QDCTRL_QUADEN_ENABLE_U32        ((uint32)(1U))

/**
* @{
* @brief FTMx_CONF - bitfield defines.
*/

#define FTM_CONF_GTBEOUT_ENABLE_U32         (((uint32)(1U)) << FTM_CONF_GTBEOUT_SHIFT)
#define FTM_CONF_GTBEOUT_DISABLE_U32        ((uint32)(0U))
#define FTM_CONF_GTBEN_ENABLE_U32           (((uint32)(1U)) << FTM_CONF_GTBEN_SHIFT)
#define FTM_CONF_GTBEEN_DISABLE_U32         ((uint32)(0U))
#define FTM_CONF_BDMMODE_ALLSTOP_U32        ((uint32)(0U))
#define FTM_CONF_BDMMODE_OUTPUTSSAFE_U32    ((uint32)(1U) <<  FTM_CONF_BDMMODE_SHIFT)
#define FTM_CONF_BDMMODE_OUTPUTSRUN_U32     ((uint32)(2U) <<  FTM_CONF_BDMMODE_SHIFT)
#define FTM_CONF_BDMMODE_ALLRUN_U32         ((uint32)(3U) <<  FTM_CONF_BDMMODE_SHIFT)

/**
* @{
* @brief FTMx_FLTPOL - bitfield defines.
*/

#define FTM_FLTPOL_FLT3POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT3POL_HIGH_U32     (((uint32)(1U)) << FTM_FLTPOL_FLT3POL_SHIFT)
#define FTM_FLTPOL_FLT2POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT2POL_HIGH_U32     (((uint32)(1U)) << FTM_FLTPOL_FLT2POL_SHIFT)
#define FTM_FLTPOL_FLT1POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT1POL_HIGH_U32     (((uint32)(1U)) << FTM_FLTPOL_FLT1POL_SHIFT)
#define FTM_FLTPOL_FLT0POL_LOW_U32      ((uint32)(0U))
#define FTM_FLTPOL_FLT0POL_HIGH_U32     ((uint32)(1U))


/**
* @{
* @brief FTMx_SYNCONF - bitfield defines.
*/


/**
* @{
* @brief FTMx_INVCTRL - bitfield defines.
*/
#define FTM_INVCTRL_INV3EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV3EN_ENABLE_U32       (((uint32)(1U)) << FTM_INVCTRL_INV3EN_SHIFT)
#define FTM_INVCTRL_INV2EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV2EN_ENABLE_U32       (((uint32)(1U)) << FTM_INVCTRL_INV2EN_SHIFT)
#define FTM_INVCTRL_INV1EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV1EN_ENABLE_U32       (((uint32)(1U)) << FTM_INVCTRL_INV1EN_SHIFT)
#define FTM_INVCTRL_INV0EN_DISABLE_U32      ((uint32)(0U))
#define FTM_INVCTRL_INV0EN_ENABLE_U32       ((uint32)(1U))

/**
* @{
* @brief FTMx_SWOCTRL - bitfield defines.
*/
#define FTM_SWOCTRL_CH7OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH7OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH7OCV_SHIFT)
#define FTM_SWOCTRL_CH6OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH6OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH6OCV_SHIFT)
#define FTM_SWOCTRL_CH5OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH5OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH5OCV_SHIFT)
#define FTM_SWOCTRL_CH4OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH4OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH4OCV_SHIFT)
#define FTM_SWOCTRL_CH3OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH3OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH3OCV_SHIFT)
#define FTM_SWOCTRL_CH2OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH2OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH2OCV_SHIFT)
#define FTM_SWOCTRL_CH1OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH1OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH1OCV_SHIFT)
#define FTM_SWOCTRL_CH0OCV_FORCE_0_U32      ((uint32)(0U))
#define FTM_SWOCTRL_CH0OCV_FORCE_1_U32      ((uint32)(1U) << FTM_SWOCTRL_CH0OCV_SHIFT)

#define FTM_SWOCTRL_CH7OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH7OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH7OC_SHIFT)
#define FTM_SWOCTRL_CH6OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH6OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH6OC_SHIFT)
#define FTM_SWOCTRL_CH5OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH5OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH5OC_SHIFT)
#define FTM_SWOCTRL_CH4OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH4OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH4OC_SHIFT)
#define FTM_SWOCTRL_CH3OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH3OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH3OC_SHIFT)
#define FTM_SWOCTRL_CH2OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH2OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH2OC_SHIFT)
#define FTM_SWOCTRL_CH1OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH1OC_ENABLE_U32        ((uint32)(1U) << FTM_SWOCTRL_CH1OC_SHIFT)
#define FTM_SWOCTRL_CH0OC_DISABLE_U32       ((uint32)(0U))
#define FTM_SWOCTRL_CH0OC_ENABLE_U32        ((uint32)(1U))
/**
* @{
* @brief FTMx_PWMLOAD - bitfield defines.
*/
#define FTM_PWMLOAD_LDOK_DISABLE_U32       ((uint32)(0U))
#define FTM_PWMLOAD_LDOK_ENABLE_U32        (((uint32)(1U)) << FTM_PWMLOAD_LDOK_SHIFT)
#define FTM_PWMLOAD_CH7SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH7SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH7SEL_SHIFT)
#define FTM_PWMLOAD_CH6SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH6SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH6SEL_SHIFT)
#define FTM_PWMLOAD_CH5SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH5SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH5SEL_SHIFT)
#define FTM_PWMLOAD_CH4SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH4SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH4SEL_SHIFT)
#define FTM_PWMLOAD_CH3SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH3SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH3SEL_SHIFT)
#define FTM_PWMLOAD_CH2SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH2SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH2SEL_SHIFT)
#define FTM_PWMLOAD_CH1SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH1SEL_ENABLE_U32      (((uint32)(1U)) << FTM_PWMLOAD_CH1SEL_SHIFT)
#define FTM_PWMLOAD_CH0SEL_DISABLE_U32     ((uint32)(0U))
#define FTM_PWMLOAD_CH0SEL_ENABLE_U32      ((uint32)(1U))


/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif



#endif /* REG_ESYS_FTM_H */

/** @} */
