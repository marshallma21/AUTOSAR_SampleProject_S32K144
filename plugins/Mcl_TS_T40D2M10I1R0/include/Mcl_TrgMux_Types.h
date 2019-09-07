/**
*   @file    Mcl_TrgMux_Types.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcl - Exported data outside of the Mcl from TRGMUX.
*   @details Public data types exported outside of the Mcl driver.
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


#ifndef MCL_TRGMUX_TYPES_H
#define MCL_TRGMUX_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_TRGMUX_Types_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_TRGMUX_Types.h
*/
#define MCL_TRGMUX_TYPES_VENDOR_ID                       43
/** @violates @ref Mcl_TRGMUX_Types_h_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked ... */
#define MCL_TRGMUX_TYPES_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Mcl_TRGMUX_Types_h_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked ... */
#define MCL_TRGMUX_TYPES_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Mcl_TRGMUX_Types_h_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked ... */
#define MCL_TRGMUX_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCL_TRGMUX_TYPES_SW_MAJOR_VERSION                1
#define MCL_TRGMUX_TYPES_SW_MINOR_VERSION                0
#define MCL_TRGMUX_TYPES_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            Trigger input encoding.
* @details          
*/
typedef enum
{
    MCL_TRGMUX_INPUT_DISABLED       =0x00U,
    MCL_TRGMUX_VDD                  =0x01U,
    MCL_TRGMUX_INPUT_0              =0x02U,
    MCL_TRGMUX_INPUT_1              =0x03U,
    MCL_TRGMUX_INPUT_2              =0x04U,
    MCL_TRGMUX_INPUT_3              =0x05U,
    MCL_TRGMUX_INPUT_4              =0x06U,
    MCL_TRGMUX_INPUT_5              =0x07U,
    MCL_TRGMUX_INPUT_6              =0x08U,
    MCL_TRGMUX_INPUT_7              =0x09U,
    MCL_TRGMUX_INPUT_8              =0x0AU,
    MCL_TRGMUX_INPUT_9              =0x0BU,
    MCL_TRGMUX_INPUT_10             =0x0CU,
    MCL_TRGMUX_INPUT_11             =0x0DU,
    MCL_TRGMUX_CMP0                 =0x0EU,
    MCL_TRGMUX_LPIT_CH0             =0x11U,
    MCL_TRGMUX_LPIT_CH1             =0x12U,
    MCL_TRGMUX_LPIT_CH2             =0x13U,
    MCL_TRGMUX_LPIT_CH3             =0x14U,
    MCL_TRGMUX_LPTMR0_TRIGGER       =0x15U,
    MCL_TRGMUX_FTM0_INT             =0x16U,
    MCL_TRGMUX_FTM0_EXT             =0x17U,
    MCL_TRGMUX_FTM1_INT             =0x18U,
    MCL_TRGMUX_FTM1_EXT             =0x19U,
    MCL_TRGMUX_FTM2_INT             =0x1AU,
    MCL_TRGMUX_FTM2_EXT             =0x1BU,
    MCL_TRGMUX_FTM3_INT             =0x1CU,
    MCL_TRGMUX_FTM3_EXT             =0x1DU,
    MCL_TRGMUX_ADC0_COCOA           =0x1EU,
    MCL_TRGMUX_ADC0_COCOB           =0x1FU,
    MCL_TRGMUX_ADC1_COCOA           =0x20U,
    MCL_TRGMUX_ADC1_COCOB           =0x21U,
    MCL_TRGMUX_PDB0_CH0             =0x22U,
    MCL_TRGMUX_PDB0_PULSE_OUT       =0x24U,
    MCL_TRGMUX_PDB1_CH0             =0x25U,
    MCL_TRGMUX_PDB1_PULSE_OUT       =0x27U,
    MCL_TRGMUX_RTC_ALARM            =0x2BU,
    MCL_TRGMUX_RTC_SEC_COUNTER      =0x2CU,
    MCL_TRGMUX_FLEXIO_TRIG0         =0x2DU,
    MCL_TRGMUX_FLEXIO_TRIG1         =0x2EU,
    MCL_TRGMUX_FLEXIO_TRIG2         =0x2FU,
    MCL_TRGMUX_FLEXIO_TRIG3         =0x30U,
    MCL_TRGMUX_LPUART0_RX_DATA      =0x31U,
    MCL_TRGMUX_LPUART0_TX_DATA      =0x32U,
    MCL_TRGMUX_LPUART0_RX_IDLE      =0x33U,
    MCL_TRGMUX_LPUART1_RX_DATA      =0x34U,
    MCL_TRGMUX_LPUART1_TX_DATA      =0x35U,
    MCL_TRGMUX_LPUART1_RX_IDLE      =0x36U,
    MCL_TRGMUX_LPI2C0_MASTER_TRIGGER =0x37U,
    MCL_TRGMUX_LPI2C0_SLAVE_TRIGGER  =0x38U,
    MCL_TRGMUX_LPSPI0_FRAME         =0x3BU,
    MCL_TRGMUX_LPSPI0_RX_DATA       =0x3CU,
    MCL_TRGMUX_LPSPI1_FRAME         =0x3DU,
    MCL_TRGMUX_LPSPI1_RX_DATA       =0x3EU,
    MCL_TRGMUX_SIM_SW_TRIGGER       =0x3FU,
    MCL_TRGMUX_LPI2C1_MASTER_TRIGGER =0x43U,
    MCL_TRGMUX_LPI2C1_SLAVE_TRIGGER =0x44U,
    MCL_TRGMUX_FTM4_INT             =0x45U,
    MCL_TRGMUX_FTM4_EXT             =0x46U,
    MCL_TRGMUX_FTM5_INT             =0x47U,
    MCL_TRGMUX_FTM5_EXT             =0x48U,
    MCL_TRGMUX_FTM6_INT             =0x49U,
    MCL_TRGMUX_FTM6_EXT             =0x4AU,
    MCL_TRGMUX_FTM7_INT             =0x4BU,
    MCL_TRGMUX_FTM7_EXT             =0x4CU
} Mcl_TrgMuxTriggerType;

/**
* @brief            Trigger Mux Selection of Input 
* @details          
*/
typedef enum
{
    MCL_TRGMUX_SEL_0                =0U,
    MCL_TRGMUX_SEL_1                =1U,
    MCL_TRGMUX_SEL_2                =2U,
    MCL_TRGMUX_SEL_3                =3U   

}Mcl_TrgMuxSelectionNrType;

/**
* @brief            Trigger Mux Register Index
* @details          The data type contains the index of the register in the TrgMux memory map.It will be used for applying the register offset.
*/
typedef enum
{
    MCL_TRGMUX_DMAMUX_CH0_REG     =0U,
    MCL_TRGMUX_EXT_OUT0_REG      =1U,
    MCL_TRGMUX_EXT_OUT1_REG      =2U,
    MCL_TRGMUX_ADC0_REG           =3U,
    MCL_TRGMUX_ADC1_REG           =4U,
    MCL_TRGMUX_CMP0_REG           =7U,
    MCL_TRGMUX_FTM0_REG           =10U,
    MCL_TRGMUX_FTM1_REG           =11U,
    MCL_TRGMUX_FTM2_REG           =12U,
    MCL_TRGMUX_FTM3_REG           =13U,
    MCL_TRGMUX_PDB0_REG           =14U,
    MCL_TRGMUX_PDB1_REG           =15U,
    MCL_TRGMUX_FLEXIO_REG         =17U,
    MCL_TRGMUX_LPIT_REG           =18U,
    MCL_TRGMUX_LPUART0_REG        =19U,
    MCL_TRGMUX_LPUART1_REG        =20U,
    MCL_TRGMUX_LPI2C0_REG         =21U,
    MCL_TRGMUX_LPSPI0_REG         =23U,
    MCL_TRGMUX_LPSPI1_REG         =24U,
    MCL_TRGMUX_LPTMR0_REG         =25U,
    MCL_TRGMUX_LPI2C1_REG         =26U,
    MCL_TRGMUX_FTM4_REG           =27U,
    MCL_TRGMUX_FTM5_REG           =28U,
    MCL_TRGMUX_FTM6_REG           =29U,
    MCL_TRGMUX_FTM7_REG           =30U
}Mcl_TrgMuxRegisterIndexType;
/**
* @brief            Mcl Trig Mux register type
* @details          Configuration for any Trig Mux register
*
*/
typedef uint32 Mcl_TrgMuxRegisterType;

typedef uint32 Mcl_TrgMuxRegisterValueType;


/**
* @brief      Mcl TrigMux configuration structure
* 
*/
typedef struct 
{
    /** @brief TrigMux DmaMuxCh0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxDmaMuxCh0Config;
    /** @brief TrigMux TRGMUX_XB_OUT0_3 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxXbOut03Config;
    /** @brief TrigMux TRGMUX_XB_OUT4_7 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxXbOut47Config;
    /** @brief TrigMux TRGMUX_ADC_0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxAdc0Config;
    /** @brief TrigMux TRGMUX_ADC_1 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxAdc1Config;
    /** @brief TrigMux TRGMUX_CMP0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxCmp0Config;
    /** @brief TrigMux TRGMUX_FTM0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm0Config;
    /** @brief TrigMux TRGMUX_FTM1 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm1Config;
    /** @brief TrigMux TRGMUX_FTM2 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm2Config;
    /** @brief TrigMux TRGMUX_FTM3 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm3Config;
    /** @brief TrigMux TRGMUX_PDB0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxPdb0Config;
#ifdef  MCL_TRGMUX_PDB1_AVAILABLE
    /** @brief TrigMux TRGMUX_PDB1 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxPdb1Config;
#endif
    /** @brief TrigMux TRGMUX_FLEXIO register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFlexIoConfig;
    /** @brief TrigMux TRGMUX_LPIT register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpitConfig;
    /** @brief TrigMux TRGMUX_LPUART0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpuart0Config;
    /** @brief TrigMux TRGMUX_LPUART1 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpuart1Config;
    /** @brief TrigMux TRGMUX_LPI2C0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpi2c0Config;
    /** @brief TrigMux TRGMUX_LSPI0 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpspi0Config;
    /** @brief TrigMux TRGMUX_LSPI1 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpspi1Config;
    /** @brief TrigMux TRGMUX_LPTMR register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLptmr0Config;
#ifdef  MCL_TRGMUX_LPI2C1_AVAILABLE
    /** @brief TrigMux TRGMUX_LPI2C1 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxLpi2c1Config;
#endif
#ifdef  MCL_TRGMUX_FTM4_AVAILABLE
    /** @brief TrigMux TRGMUX_FTM4 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm4Config;
#endif
#ifdef  MCL_TRGMUX_FTM5_AVAILABLE
    /** @brief TrigMux TRGMUX_FTM5 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm5Config;
#endif
#ifdef  MCL_TRGMUX_FTM6_AVAILABLE
    /** @brief TrigMux TRGMUX_FTM6 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm6Config;
#endif
#ifdef  MCL_TRGMUX_FTM7_AVAILABLE
    /** @brief TrigMux TRGMUX_FTM7 register configuration */
    CONST(Mcl_TrgMuxRegisterType, MCL_CONST) MclTrigMuxFtm7Config;
#endif
} Mcl_TrgMuxConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCL_TRGMUX_TYPES_H */

/** @} */
