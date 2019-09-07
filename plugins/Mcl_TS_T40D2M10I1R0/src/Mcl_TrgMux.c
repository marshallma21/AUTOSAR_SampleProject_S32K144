/**
*   @file    Mcl_TrgMux.c
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - TrgMux low level driver.
*   @details contains the low level driver for the TrgMux module.
*
*   @addtogroup MCL_MODULE
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
*
* @section Mcl_TRGMUX_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section Mcl_TRGMUX_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcl_TRGMUX_c_REF_6
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_TRGMUX_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This violation is generated becuase conversions must not be performed between a pointer 
* to a function and any type other than an integral type. The cast can't be avoided as it is 
* used to access memory mapped registers.
*
* @section Mcl_TRGMUX_c_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
* @section Mcl_TRGMUX_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions at file scope
* shall have internal linkage unless external linkage is required.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section  [global]
*           Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall not
*           be implicitly converted to a different underlying type.
*           This violation due to implementation of MCAL_TRUSTED_CALL function.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"

#ifdef MCL_ENABLE_TRGMUX
#if (MCL_ENABLE_TRGMUX == STD_ON)
#include "Mcl_TrgMux.h"
#endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_TrgMux.c
*/
#define MCL_TRGMUX_VENDOR_ID_C                    43
/** @violates @ref Mcl_TRGMUX_c_REF_4 MISRA 2004 Rule 1.4, Identifier clash */
#define MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Mcl_TRGMUX_c_REF_4 MISRA 2004 Rule 1.4, Identifier clash */
#define MCL_TRGMUX_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref Mcl_TRGMUX_c_REF_4 MISRA 2004 Rule 1.4, Identifier clash */
#define MCL_TRGMUX_AR_RELEASE_REVISION_VERSION_C  2
#define MCL_TRGMUX_SW_MAJOR_VERSION_C             1
#define MCL_TRGMUX_SW_MINOR_VERSION_C             0
#define MCL_TRGMUX_SW_PATCH_VERSION_C             1


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and MCL configuration header file are of the same vendor */
#if (MCL_TRGMUX_VENDOR_ID_C != MCL_VENDOR_ID_CFG)
    #error "Mcl_TrgMux.c and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
/* Check if source file and MCL configuration header file are of the same Autosar version */
#if ((MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_TRGMUX_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_TRGMUX_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcl_TrgMux.c and CDD_Mcl_Cfg.h are different"
#endif
/* Check if source file and MCL configuration header file are of the same software version */
#if ((MCL_TRGMUX_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_TRGMUX_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_TRGMUX_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcl_TrgMux.c and CDD_Mcl_Cfg.hare different"
#endif

#ifdef MCL_ENABLE_TRGMUX
#if (MCL_ENABLE_TRGMUX == STD_ON)
#if (MCL_TRGMUX_VENDOR_ID_C != MCL_TRGMUX_VENDOR_ID)
    #error "Mcl_TrgMux.c and Mcl_TrgMux.h have different vendor IDs"
#endif
/* Check if source file and Mcl_Dma header file are of the same Autosar version */
#if ((MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION_C != MCL_TRGMUX_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_TRGMUX_AR_RELEASE_MINOR_VERSION_C != MCL_TRGMUX_AR_RELEASE_MINOR_VERSION) || \
     (MCL_TRGMUX_AR_RELEASE_REVISION_VERSION_C != MCL_TRGMUX_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_TrgMux.h and Mcl_TrgMux.c are different"
#endif
/* Check if source file and Mcl_Dma header file are of the same Software version */
#if ((MCL_TRGMUX_SW_MAJOR_VERSION_C != MCL_TRGMUX_SW_MAJOR_VERSION) || \
     (MCL_TRGMUX_SW_MINOR_VERSION_C != MCL_TRGMUX_SW_MINOR_VERSION) || \
     (MCL_TRGMUX_SW_PATCH_VERSION_C != MCL_TRGMUX_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_TrgMux.h and Mcl_TrgMux.c are different"
#endif
#endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#ifdef MCL_ENABLE_TRGMUX
#if (MCL_ENABLE_TRGMUX == STD_ON)
#if (MCL_DEV_ERROR_DETECT == STD_ON) 
#define MCL_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_TRGMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_TRGMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"

CONST(Mcl_TrgMuxRegisterIndexType, MCL_CONST) Mcl_TrgMux_RegistersOneInput[MCL_NUM_REG_MISSING_SEL_FIELD]=
{
    MCL_TRGMUX_CMP0_REG
    ,MCL_TRGMUX_PDB0_REG
#ifdef  MCL_TRGMUX_PDB1_AVAILABLE
    ,MCL_TRGMUX_PDB1_REG
#endif
    ,MCL_TRGMUX_LPUART0_REG
    ,MCL_TRGMUX_LPUART1_REG
    ,MCL_TRGMUX_LPI2C0_REG
    ,MCL_TRGMUX_LPSPI0_REG
    ,MCL_TRGMUX_LPSPI1_REG
    ,MCL_TRGMUX_LPTMR0_REG
#ifdef  MCL_TRGMUX_LPI2C1_AVAILABLE
    ,MCL_TRGMUX_LPI2C1_REG
#endif
#ifdef  MCL_TRGMUX_FTM4_AVAILABLE
    ,MCL_TRGMUX_FTM4_REG
#endif
#ifdef  MCL_TRGMUX_FTM5_AVAILABLE
    ,MCL_TRGMUX_FTM5_REG
#endif
#ifdef  MCL_TRGMUX_FTM6_AVAILABLE
    ,MCL_TRGMUX_FTM6_REG
#endif
#ifdef  MCL_TRGMUX_FTM7_AVAILABLE
    ,MCL_TRGMUX_FTM7_REG
#endif
};

#define MCL_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_TRGMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice 
*
* @violates @ref Mcl_TRGMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"

#endif
#endif
#endif

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/



/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_TRGMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice 
*
* @violates @ref Mcl_TRGMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"
        
#ifdef MCL_ENABLE_TRGMUX
#if (MCL_ENABLE_TRGMUX == STD_ON)
/**
* @brief        This function initializes the TRGMUX module. 
* @details      Set the configuration register for channel enable, trig and source.
*
* @param[in]    pTrgMuxConfig - pointer to TrgMux configuration structure
*
* @violates @ref Mcl_TRGMUX_c_REF_10 All declarations and definitions shall have internal linkage unless external  
* is required
*/
FUNC(void, MCL_CODE) Mcl_TrgMux_Init( P2CONST(Mcl_TrgMuxConfigType, MCL_VAR, MCL_APPL_VAR)   pTrgMuxConfig)
{
    /* @brief initialize register TRGMUX_TRGMUX_CH0 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_DMAMUX_CH0_REG), pTrgMuxConfig->MclTrigMuxDmaMuxCh0Config);
    /* @brief initialize register TRGMUX_XB_OUT0_3 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_EXT_OUT0_REG), pTrgMuxConfig->MclTrigMuxXbOut03Config);
    /* @brief initialize register TRGMUX_XB_OUT4_7 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_EXT_OUT1_REG), pTrgMuxConfig->MclTrigMuxXbOut47Config);
    /* @brief initialize register TRGMUX_ADC0 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_ADC0_REG), pTrgMuxConfig->MclTrigMuxAdc0Config);
    /* @brief initialize register TRGMUX_ADC1 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_ADC1_REG), pTrgMuxConfig->MclTrigMuxAdc1Config);
    /* @brief initialize register TRGMUX_CMP0
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */    
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_CMP0_REG), pTrgMuxConfig->MclTrigMuxCmp0Config);
    /* @brief initialize register TRGMUX_FTM0 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM0_REG), pTrgMuxConfig->MclTrigMuxFtm0Config);
    /* @brief initialize register TRGMUX_FTM1 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM1_REG), pTrgMuxConfig->MclTrigMuxFtm1Config);
    /* @brief initialize register TRGMUX_FTM2 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM2_REG), pTrgMuxConfig->MclTrigMuxFtm2Config);
    /* @brief initialize register TRGMUX_FTM3 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM3_REG), pTrgMuxConfig->MclTrigMuxFtm3Config);
    /* @brief initialize register TRGMUX_PDB0 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_PDB0_REG), pTrgMuxConfig->MclTrigMuxPdb0Config);
#ifdef  MCL_TRGMUX_PDB1_AVAILABLE
    /* @brief initialize register TRGMUX_PDB1 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_PDB1_REG), pTrgMuxConfig->MclTrigMuxPdb1Config);
#endif
    /* @brief initialize register TRGMUX_FLEXIO 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FLEXIO_REG), pTrgMuxConfig->MclTrigMuxFlexIoConfig);
    /* @brief initialize register TRGMUX_LPIT 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPIT_REG), pTrgMuxConfig->MclTrigMuxLpitConfig);
    /* @brief initialize register TRGMUX_LPUART0 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPUART0_REG), pTrgMuxConfig->MclTrigMuxLpuart0Config);
    /* @brief initialize register TRGMUX_LPUART1_
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPUART1_REG), pTrgMuxConfig->MclTrigMuxLpuart1Config);
    /* @brief initialize register TRGMUX_LPI2C0 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPI2C0_REG), pTrgMuxConfig->MclTrigMuxLpi2c0Config);
    /* @brief initialize register TRGMUX_LPSPI0_ 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPSPI0_REG), pTrgMuxConfig->MclTrigMuxLpspi0Config);
    /* @brief initialize register TRGMUX_LPSPI1 
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPSPI1_REG), pTrgMuxConfig->MclTrigMuxLpspi1Config);
    /* @brief initialize register TRGMUX_LPTMR0_
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPTMR0_REG), pTrgMuxConfig->MclTrigMuxLptmr0Config);
#ifdef  MCL_TRGMUX_LPI2C1_AVAILABLE
    /* @brief initialize register TRGMUX_LPI2C1_REG
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_LPI2C1_REG), pTrgMuxConfig->MclTrigMuxLpi2c1Config);
#endif
#ifdef  MCL_TRGMUX_FTM4_AVAILABLE
    /* @brief initialize register TRGMUX_FTM4_REG
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM4_REG), pTrgMuxConfig->MclTrigMuxFtm4Config);
#endif
#ifdef  MCL_TRGMUX_FTM5_AVAILABLE
    /* @brief initialize register TRGMUX_FTM5_REG
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM5_REG), pTrgMuxConfig->MclTrigMuxFtm5Config);
#endif
#ifdef  MCL_TRGMUX_FTM6_AVAILABLE
    /* @brief initialize register TRGMUX_FTM6_REG
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM6_REG), pTrgMuxConfig->MclTrigMuxFtm6Config);
#endif
#ifdef  MCL_TRGMUX_FTM7_AVAILABLE
    /* @brief initialize register TRGMUX_FTM7_REG
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    REG_WRITE32(TRGMUX_REG_ADDR(MCL_TRGMUX_FTM7_REG), pTrgMuxConfig->MclTrigMuxFtm7Config); 
#endif
}

FUNC(void, MCL_CODE) Mcl_TrgMux_Config_Sel(Mcl_TrgMuxRegisterIndexType TrgMuxRegInput, Mcl_TrgMuxSelectionNrType SelectNum, Mcl_TrgMuxRegisterType Sourceinput)
{
    /* @brief config Trigger Mux source input
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    TRGMUX_CONFIG_SEL(TrgMuxRegInput, SelectNum, Sourceinput);

}
FUNC(void, MCL_CODE) Mcl_TrgMux_Enable_Lock(Mcl_TrgMuxRegisterIndexType TrgMuxRegInput)
{
    /* @brief Set LK bit for Triggermux register
    *  @violates @ref Mcl_TRGMUX_c_REF_8 Conversions shall not be performed between a pointer to 
    *  a function and any type other than an integral type.
    */
    /** @violates @ref Mcl_TRGMUX_c_REF_9 Violates MISRA 2004 Rule 11.3*/
    TRGMUX_ENABLE_LOCK(TrgMuxRegInput);

}
#endif
#endif

#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_TRGMUX_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*       of a header file being included twice 
*
* @violates @ref Mcl_TRGMUX_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
