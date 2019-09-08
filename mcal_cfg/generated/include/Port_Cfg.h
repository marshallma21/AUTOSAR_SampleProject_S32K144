/**
* @file    Port_Cfg.h
* @implements Port_Cfg.h_Artifact
*
* @version 1.0.1
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linkershall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers. 
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_CFG_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section PORT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
* These objects are used in various parts of the code.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_EnvCfg.h"
#include "Port_Port_Ci_Types.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_VENDOR_ID_CFG_H                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_H        2
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_H     2
#define PORT_SW_MAJOR_VERSION_CFG_H                1
#define PORT_SW_MINOR_VERSION_CFG_H                0
#define PORT_SW_PATCH_VERSION_CFG_H                1

/*=================================================================================================
*                               FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_Cfg.h and Port_Port_Ci_Types.h file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_PORT_CI_VENDOR_ID_TYPES_H)
    #error "Port_Cfg.h and Port_Port_Ci_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Port_Port_Ci_Types.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_PORT_CI_AR_RELEASE_MAJOR_VERSION_TYPES_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_PORT_CI_AR_RELEASE_MINOR_VERSION_TYPES_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_PORT_CI_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_Port_Ci_Types.h are different"
#endif
/* Check if Port_Cfg.h and Port_Port_Ci_Types.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_PORT_CI_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_PORT_CI_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_PORT_CI_SW_PATCH_VERSION_TYPES_H) \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_Port_Ci_Types.h are different"
#endif

/* Check if Port_Cfg.h file and Port_EnvCfg header file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_ENVCFG_VENDOR_ID)
    #error "Port_Cfg.h and Port_EnvCfg.h have different vendor IDs"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MAJOR_VERSION)      || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MINOR_VERSION)      || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif
/* Check if Port_Cfg.h and PORT header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_ENVCFG_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_ENVCFG_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_ENVCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
/**
* @brief       Ensure better readability of the configuration
* @note 
*
* @violates @ref PORT_CFG_H_REF_3 Function-like macro defined.
*/
#define SHL_PAD_U16(x)                      ((uint16)(((uint16)1) << (x)))

/** @brief Port Alternate 0 Mode */
#define PORT_ALT0_FUNC_MODE             ((Port_PinModeType)0)
/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE             ((Port_PinModeType)7)


    

#define    PORT0_ADC0_SE0_CMP0_IN0        (PORT_ALT0_FUNC_MODE)
#define    PORT0_GPIO        (PORT_GPIO_MODE)
#define    PORT0_FTM2_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT0_LPI2C0_SCLS        (PORT_ALT3_FUNC_MODE)
#define    PORT0_FXIO_D2        (PORT_ALT4_FUNC_MODE)
#define    PORT0_FTM2_QD_PHA        (PORT_ALT5_FUNC_MODE)
#define    PORT0_LPUART0_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT0_TRGMUX_OUT3        (PORT_ALT7_FUNC_MODE)
#define    PORT1_ADC0_SE1_CMP0_IN1        (PORT_ALT0_FUNC_MODE)
#define    PORT1_GPIO        (PORT_GPIO_MODE)
#define    PORT1_FTM1_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT1_LPI2C0_SDAS        (PORT_ALT3_FUNC_MODE)
#define    PORT1_FXIO_D3        (PORT_ALT4_FUNC_MODE)
#define    PORT1_FTM1_QD_PHA        (PORT_ALT5_FUNC_MODE)
#define    PORT1_LPUART0_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT1_TRGMUX_OUT0        (PORT_ALT7_FUNC_MODE)
#define    PORT2_ADC1_SE0        (PORT_ALT0_FUNC_MODE)
#define    PORT2_GPIO        (PORT_GPIO_MODE)
#define    PORT2_FTM3_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT2_LPI2C0_SDA        (PORT_ALT3_FUNC_MODE)
#define    PORT2_EWM_OUT_b        (PORT_ALT4_FUNC_MODE)
#define    PORT2_FXIO_D4        (PORT_ALT5_FUNC_MODE)
#define    PORT2_LPUART0_RX        (PORT_ALT6_FUNC_MODE)
#define    PORT3_ADC1_SE1        (PORT_ALT0_FUNC_MODE)
#define    PORT3_GPIO        (PORT_GPIO_MODE)
#define    PORT3_FTM3_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT3_LPI2C0_SCL        (PORT_ALT3_FUNC_MODE)
#define    PORT3_EWM_IN        (PORT_ALT4_FUNC_MODE)
#define    PORT3_FXIO_D5        (PORT_ALT5_FUNC_MODE)
#define    PORT3_LPUART0_TX        (PORT_ALT6_FUNC_MODE)
#define    PORT4_GPIO        (PORT_GPIO_MODE)
#define    PORT4_CMP0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT4_EWM_OUT_b        (PORT_ALT5_FUNC_MODE)
#define    PORT4_JTAG_TMS_SWD_DIO        (PORT_ALT7_FUNC_MODE)
#define    PORT5_GPIO        (PORT_GPIO_MODE)
#define    PORT5_TCLK1        (PORT_ALT3_FUNC_MODE)
#define    PORT5_RESET_b        (PORT_ALT7_FUNC_MODE)
#define    PORT6_ADC0_SE2        (PORT_ALT0_FUNC_MODE)
#define    PORT6_GPIO        (PORT_GPIO_MODE)
#define    PORT6_FTM0_FLT1        (PORT_ALT2_FUNC_MODE)
#define    PORT6_LPSPI1_PCS1        (PORT_ALT3_FUNC_MODE)
#define    PORT6_LPUART1_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT7_ADC0_SE3        (PORT_ALT0_FUNC_MODE)
#define    PORT7_GPIO        (PORT_GPIO_MODE)
#define    PORT7_FTM0_FLT2        (PORT_ALT2_FUNC_MODE)
#define    PORT7_RTC_CLKIN        (PORT_ALT4_FUNC_MODE)
#define    PORT7_LPUART1_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT8_GPIO        (PORT_GPIO_MODE)
#define    PORT8_LPUART2_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT8_LPSPI2_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT8_FXIO_D6        (PORT_ALT4_FUNC_MODE)
#define    PORT8_FTM3_FLT3        (PORT_ALT5_FUNC_MODE)
#define    PORT9_GPIO        (PORT_GPIO_MODE)
#define    PORT9_LPUART2_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT9_LPSPI2_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT9_FXIO_D7        (PORT_ALT4_FUNC_MODE)
#define    PORT9_FTM3_FLT2        (PORT_ALT5_FUNC_MODE)
#define    PORT9_FTM1_FLT3        (PORT_ALT6_FUNC_MODE)
#define    PORT10_GPIO        (PORT_GPIO_MODE)
#define    PORT10_FTM1_CH4        (PORT_ALT2_FUNC_MODE)
#define    PORT10_FXIO_D0        (PORT_ALT4_FUNC_MODE)
#define    PORT10_JTAG_TDO        (PORT_ALT7_FUNC_MODE)
#define    PORT11_GPIO        (PORT_GPIO_MODE)
#define    PORT11_FTM1_CH5        (PORT_ALT2_FUNC_MODE)
#define    PORT11_FXIO_D1        (PORT_ALT4_FUNC_MODE)
#define    PORT11_CMP0_RRT        (PORT_ALT5_FUNC_MODE)
#define    PORT12_GPIO        (PORT_GPIO_MODE)
#define    PORT12_FTM1_CH6        (PORT_ALT2_FUNC_MODE)
#define    PORT12_CAN1_RX        (PORT_ALT3_FUNC_MODE)
#define    PORT12_FTM2_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT13_GPIO        (PORT_GPIO_MODE)
#define    PORT13_FTM1_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT13_CAN1_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT13_FTM2_QD_PHA        (PORT_ALT6_FUNC_MODE)
#define    PORT14_GPIO        (PORT_GPIO_MODE)
#define    PORT14_FTM0_FLT0        (PORT_ALT2_FUNC_MODE)
#define    PORT14_FTM3_FLT1        (PORT_ALT3_FUNC_MODE)
#define    PORT14_EWM_IN        (PORT_ALT4_FUNC_MODE)
#define    PORT14_FTM1_FLT0        (PORT_ALT6_FUNC_MODE)
#define    PORT15_ADC1_SE12        (PORT_ALT0_FUNC_MODE)
#define    PORT15_GPIO        (PORT_GPIO_MODE)
#define    PORT15_FTM1_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT15_LPSPI0_PCS3        (PORT_ALT3_FUNC_MODE)
#define    PORT15_LPSPI2_PCS3        (PORT_ALT4_FUNC_MODE)
#define    PORT16_ADC1_SE13        (PORT_ALT0_FUNC_MODE)
#define    PORT16_GPIO        (PORT_GPIO_MODE)
#define    PORT16_FTM1_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT16_LPSPI1_PCS2        (PORT_ALT3_FUNC_MODE)
#define    PORT17_GPIO        (PORT_GPIO_MODE)
#define    PORT17_FTM0_CH6        (PORT_ALT2_FUNC_MODE)
#define    PORT17_FTM3_FLT0        (PORT_ALT3_FUNC_MODE)
#define    PORT17_EWM_OUT_b        (PORT_ALT4_FUNC_MODE)
#define    PORT32_ADC0_SE4_ADC1_SE14        (PORT_ALT0_FUNC_MODE)
#define    PORT32_GPIO        (PORT_GPIO_MODE)
#define    PORT32_LPUART0_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT32_LPSPI0_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT32_LPTMR0_ALT3        (PORT_ALT4_FUNC_MODE)
#define    PORT32_CAN0_RX        (PORT_ALT5_FUNC_MODE)
#define    PORT33_ADC0_SE5_ADC1_SE15        (PORT_ALT0_FUNC_MODE)
#define    PORT33_GPIO        (PORT_GPIO_MODE)
#define    PORT33_LPUART0_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT33_LPSPI0_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT33_TCLK0        (PORT_ALT4_FUNC_MODE)
#define    PORT33_CAN0_TX        (PORT_ALT5_FUNC_MODE)
#define    PORT34_ADC0_SE6        (PORT_ALT0_FUNC_MODE)
#define    PORT34_GPIO        (PORT_GPIO_MODE)
#define    PORT34_FTM1_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT34_LPSPI0_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT34_FTM1_QD_PHB        (PORT_ALT4_FUNC_MODE)
#define    PORT34_TRGMUX_IN3        (PORT_ALT6_FUNC_MODE)
#define    PORT35_ADC0_SE7        (PORT_ALT0_FUNC_MODE)
#define    PORT35_GPIO        (PORT_GPIO_MODE)
#define    PORT35_FTM1_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT35_LPSPI0_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT35_FTM1_QD_PHA        (PORT_ALT4_FUNC_MODE)
#define    PORT35_TRGMUX_IN2        (PORT_ALT6_FUNC_MODE)
#define    PORT36_GPIO        (PORT_GPIO_MODE)
#define    PORT36_FTM0_CH4        (PORT_ALT2_FUNC_MODE)
#define    PORT36_LPSPI0_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT36_TRGMUX_IN1        (PORT_ALT6_FUNC_MODE)
#define    PORT37_GPIO        (PORT_GPIO_MODE)
#define    PORT37_FTM0_CH5        (PORT_ALT2_FUNC_MODE)
#define    PORT37_LPSPI0_PCS1        (PORT_ALT3_FUNC_MODE)
#define    PORT37_LPSPI0_PCS0        (PORT_ALT4_FUNC_MODE)
#define    PORT37_CLKOUT        (PORT_ALT5_FUNC_MODE)
#define    PORT37_TRGMUX_IN0        (PORT_ALT6_FUNC_MODE)
#define    PORT38_XTAL        (PORT_ALT0_FUNC_MODE)
#define    PORT38_GPIO        (PORT_GPIO_MODE)
#define    PORT38_LPI2C0_SDA        (PORT_ALT2_FUNC_MODE)
#define    PORT39_EXTAL        (PORT_ALT0_FUNC_MODE)
#define    PORT39_GPIO        (PORT_GPIO_MODE)
#define    PORT39_LPI2C0_SCL        (PORT_ALT2_FUNC_MODE)
#define    PORT40_GPIO        (PORT_GPIO_MODE)
#define    PORT40_FTM3_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT41_GPIO        (PORT_GPIO_MODE)
#define    PORT41_FTM3_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT41_LPI2C0_SCLS        (PORT_ALT3_FUNC_MODE)
#define    PORT42_GPIO        (PORT_GPIO_MODE)
#define    PORT42_FTM3_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT42_LPI2C0_SDAS        (PORT_ALT3_FUNC_MODE)
#define    PORT43_GPIO        (PORT_GPIO_MODE)
#define    PORT43_FTM3_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT43_LPI2C0_HREQ        (PORT_ALT3_FUNC_MODE)
#define    PORT44_ADC1_SE7        (PORT_ALT0_FUNC_MODE)
#define    PORT44_GPIO        (PORT_GPIO_MODE)
#define    PORT44_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT44_FTM3_FLT2        (PORT_ALT3_FUNC_MODE)
#define    PORT44_CAN2_RX        (PORT_ALT4_FUNC_MODE)
#define    PORT45_ADC1_SE8_ADC0_SE8        (PORT_ALT0_FUNC_MODE)
#define    PORT45_GPIO        (PORT_GPIO_MODE)
#define    PORT45_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT45_FTM3_FLT1        (PORT_ALT3_FUNC_MODE)
#define    PORT45_CAN2_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT46_ADC1_SE9_ADC0_SE9        (PORT_ALT0_FUNC_MODE)
#define    PORT46_GPIO        (PORT_GPIO_MODE)
#define    PORT46_FTM0_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT46_LPSPI1_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT47_ADC1_SE14        (PORT_ALT0_FUNC_MODE)
#define    PORT47_GPIO        (PORT_GPIO_MODE)
#define    PORT47_FTM0_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT47_LPSPI1_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT48_ADC1_SE15        (PORT_ALT0_FUNC_MODE)
#define    PORT48_GPIO        (PORT_GPIO_MODE)
#define    PORT48_FTM0_CH4        (PORT_ALT2_FUNC_MODE)
#define    PORT48_LPSPI1_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT49_GPIO        (PORT_GPIO_MODE)
#define    PORT49_FTM0_CH5        (PORT_ALT2_FUNC_MODE)
#define    PORT49_LPSPI1_PCS3        (PORT_ALT3_FUNC_MODE)
#define    PORT64_ADC0_SE8        (PORT_ALT0_FUNC_MODE)
#define    PORT64_GPIO        (PORT_GPIO_MODE)
#define    PORT64_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT64_LPSPI2_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT64_FTM1_CH6        (PORT_ALT6_FUNC_MODE)
#define    PORT65_ADC0_SE9        (PORT_ALT0_FUNC_MODE)
#define    PORT65_GPIO        (PORT_GPIO_MODE)
#define    PORT65_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT65_LPSPI2_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT65_FTM1_CH7        (PORT_ALT6_FUNC_MODE)
#define    PORT66_ADC0_SE10_CMP0_IN5        (PORT_ALT0_FUNC_MODE)
#define    PORT66_GPIO        (PORT_GPIO_MODE)
#define    PORT66_FTM0_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT66_CAN0_RX        (PORT_ALT3_FUNC_MODE)
#define    PORT66_LPUART0_RX        (PORT_ALT4_FUNC_MODE)
#define    PORT67_ADC0_SE11_CMP0_IN4        (PORT_ALT0_FUNC_MODE)
#define    PORT67_GPIO        (PORT_GPIO_MODE)
#define    PORT67_FTM0_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT67_CAN0_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT67_LPUART0_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT68_CMP0_IN2        (PORT_ALT0_FUNC_MODE)
#define    PORT68_GPIO        (PORT_GPIO_MODE)
#define    PORT68_FTM1_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT68_RTC_CLKOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT68_EWM_IN        (PORT_ALT5_FUNC_MODE)
#define    PORT68_FTM1_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT68_JTAG_TCLK_SWD_CLK        (PORT_ALT7_FUNC_MODE)
#define    PORT69_GPIO        (PORT_GPIO_MODE)
#define    PORT69_FTM2_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT69_RTC_CLKOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT69_FTM2_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT69_JTAG_TDI        (PORT_ALT7_FUNC_MODE)
#define    PORT70_ADC1_SE4        (PORT_ALT0_FUNC_MODE)
#define    PORT70_GPIO        (PORT_GPIO_MODE)
#define    PORT70_LPUART1_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT70_CAN1_RX        (PORT_ALT3_FUNC_MODE)
#define    PORT70_FTM3_CH2        (PORT_ALT4_FUNC_MODE)
#define    PORT70_FTM1_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT71_ADC1_SE5        (PORT_ALT0_FUNC_MODE)
#define    PORT71_GPIO        (PORT_GPIO_MODE)
#define    PORT71_LPUART1_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT71_CAN1_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT71_FTM3_CH3        (PORT_ALT4_FUNC_MODE)
#define    PORT71_FTM1_QD_PHA        (PORT_ALT6_FUNC_MODE)
#define    PORT72_GPIO        (PORT_GPIO_MODE)
#define    PORT72_LPUART1_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT72_FTM1_FLT0        (PORT_ALT3_FUNC_MODE)
#define    PORT72_LPUART0_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT73_GPIO        (PORT_GPIO_MODE)
#define    PORT73_LPUART1_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT73_FTM1_FLT1        (PORT_ALT3_FUNC_MODE)
#define    PORT73_LPUART0_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT74_GPIO        (PORT_GPIO_MODE)
#define    PORT74_FTM3_CH4        (PORT_ALT2_FUNC_MODE)
#define    PORT74_TRGMUX_IN11        (PORT_ALT6_FUNC_MODE)
#define    PORT75_GPIO        (PORT_GPIO_MODE)
#define    PORT75_FTM3_CH5        (PORT_ALT2_FUNC_MODE)
#define    PORT75_TRGMUX_IN10        (PORT_ALT6_FUNC_MODE)
#define    PORT76_GPIO        (PORT_GPIO_MODE)
#define    PORT76_FTM3_CH6        (PORT_ALT2_FUNC_MODE)
#define    PORT76_FTM2_CH6        (PORT_ALT3_FUNC_MODE)
#define    PORT76_LPUART2_CTS        (PORT_ALT4_FUNC_MODE)
#define    PORT77_GPIO        (PORT_GPIO_MODE)
#define    PORT77_FTM3_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT77_FTM2_CH7        (PORT_ALT3_FUNC_MODE)
#define    PORT77_LPUART2_RTS        (PORT_ALT4_FUNC_MODE)
#define    PORT78_ADC0_SE12        (PORT_ALT0_FUNC_MODE)
#define    PORT78_GPIO        (PORT_GPIO_MODE)
#define    PORT78_FTM1_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT78_LPSPI2_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT78_TRGMUX_IN9        (PORT_ALT6_FUNC_MODE)
#define    PORT79_ADC0_SE13        (PORT_ALT0_FUNC_MODE)
#define    PORT79_GPIO        (PORT_GPIO_MODE)
#define    PORT79_FTM1_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT79_LPSPI2_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT79_TRGMUX_IN8        (PORT_ALT6_FUNC_MODE)
#define    PORT80_ADC0_SE14        (PORT_ALT0_FUNC_MODE)
#define    PORT80_GPIO        (PORT_GPIO_MODE)
#define    PORT80_FTM1_FLT2        (PORT_ALT2_FUNC_MODE)
#define    PORT80_CAN2_RX        (PORT_ALT3_FUNC_MODE)
#define    PORT81_ADC0_SE15        (PORT_ALT0_FUNC_MODE)
#define    PORT81_GPIO        (PORT_GPIO_MODE)
#define    PORT81_FTM1_FLT3        (PORT_ALT2_FUNC_MODE)
#define    PORT81_CAN2_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT96_GPIO        (PORT_GPIO_MODE)
#define    PORT96_FTM0_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT96_LPSPI1_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT96_FTM2_CH0        (PORT_ALT4_FUNC_MODE)
#define    PORT96_FXIO_D0        (PORT_ALT6_FUNC_MODE)
#define    PORT96_TRGMUX_OUT1        (PORT_ALT7_FUNC_MODE)
#define    PORT97_GPIO        (PORT_GPIO_MODE)
#define    PORT97_FTM0_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT97_LPSPI1_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT97_FTM2_CH1        (PORT_ALT4_FUNC_MODE)
#define    PORT97_FXIO_D1        (PORT_ALT6_FUNC_MODE)
#define    PORT97_TRGMUX_OUT2        (PORT_ALT7_FUNC_MODE)
#define    PORT98_ADC1_SE2        (PORT_ALT0_FUNC_MODE)
#define    PORT98_GPIO        (PORT_GPIO_MODE)
#define    PORT98_FTM3_CH4        (PORT_ALT2_FUNC_MODE)
#define    PORT98_LPSPI1_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT98_FXIO_D4        (PORT_ALT4_FUNC_MODE)
#define    PORT98_FXIO_D6        (PORT_ALT5_FUNC_MODE)
#define    PORT98_TRGMUX_IN5        (PORT_ALT6_FUNC_MODE)
#define    PORT99_ADC1_SE3        (PORT_ALT0_FUNC_MODE)
#define    PORT99_GPIO        (PORT_GPIO_MODE)
#define    PORT99_FTM3_CH5        (PORT_ALT2_FUNC_MODE)
#define    PORT99_LPSPI1_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT99_FXIO_D5        (PORT_ALT4_FUNC_MODE)
#define    PORT99_FXIO_D7        (PORT_ALT5_FUNC_MODE)
#define    PORT99_TRGMUX_IN4        (PORT_ALT6_FUNC_MODE)
#define    PORT99_NMI_b        (PORT_ALT7_FUNC_MODE)
#define    PORT100_ADC1_SE6        (PORT_ALT0_FUNC_MODE)
#define    PORT100_GPIO        (PORT_GPIO_MODE)
#define    PORT100_FTM0_FLT3        (PORT_ALT2_FUNC_MODE)
#define    PORT100_FTM3_FLT3        (PORT_ALT3_FUNC_MODE)
#define    PORT101_GPIO        (PORT_GPIO_MODE)
#define    PORT101_FTM2_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT101_LPTMR0_ALT2        (PORT_ALT3_FUNC_MODE)
#define    PORT101_FTM2_FLT1        (PORT_ALT4_FUNC_MODE)
#define    PORT101_TRGMUX_IN7        (PORT_ALT6_FUNC_MODE)
#define    PORT102_CMP0_IN7        (PORT_ALT0_FUNC_MODE)
#define    PORT102_GPIO        (PORT_GPIO_MODE)
#define    PORT102_LPUART2_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT102_FTM2_FLT2        (PORT_ALT4_FUNC_MODE)
#define    PORT103_CMP0_IN6        (PORT_ALT0_FUNC_MODE)
#define    PORT103_GPIO        (PORT_GPIO_MODE)
#define    PORT103_LPUART2_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT103_FTM2_FLT3        (PORT_ALT4_FUNC_MODE)
#define    PORT104_GPIO        (PORT_GPIO_MODE)
#define    PORT104_FTM2_FLT2        (PORT_ALT4_FUNC_MODE)
#define    PORT104_FXIO_D1        (PORT_ALT5_FUNC_MODE)
#define    PORT104_FTM1_CH4        (PORT_ALT6_FUNC_MODE)
#define    PORT105_GPIO        (PORT_GPIO_MODE)
#define    PORT105_FXIO_D0        (PORT_ALT3_FUNC_MODE)
#define    PORT105_FTM2_FLT3        (PORT_ALT4_FUNC_MODE)
#define    PORT105_FTM1_CH5        (PORT_ALT6_FUNC_MODE)
#define    PORT106_GPIO        (PORT_GPIO_MODE)
#define    PORT106_FTM2_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT106_FTM2_QD_PHB        (PORT_ALT3_FUNC_MODE)
#define    PORT107_GPIO        (PORT_GPIO_MODE)
#define    PORT107_FTM2_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT107_FTM2_QD_PHA        (PORT_ALT3_FUNC_MODE)
#define    PORT107_LPUART2_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT108_GPIO        (PORT_GPIO_MODE)
#define    PORT108_FTM2_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT108_LPUART2_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT109_GPIO        (PORT_GPIO_MODE)
#define    PORT109_FTM2_CH4        (PORT_ALT2_FUNC_MODE)
#define    PORT109_LPUART1_RX        (PORT_ALT3_FUNC_MODE)
#define    PORT109_RTC_CLKOUT        (PORT_ALT7_FUNC_MODE)
#define    PORT110_GPIO        (PORT_GPIO_MODE)
#define    PORT110_FTM2_CH5        (PORT_ALT2_FUNC_MODE)
#define    PORT110_LPUART1_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT110_CLKOUT        (PORT_ALT7_FUNC_MODE)
#define    PORT111_GPIO        (PORT_GPIO_MODE)
#define    PORT111_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT111_LPSPI0_SCK        (PORT_ALT4_FUNC_MODE)
#define    PORT112_GPIO        (PORT_GPIO_MODE)
#define    PORT112_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT112_LPSPI0_SIN        (PORT_ALT4_FUNC_MODE)
#define    PORT112_CMP0_RRT        (PORT_ALT5_FUNC_MODE)
#define    PORT113_GPIO        (PORT_GPIO_MODE)
#define    PORT113_FTM0_FLT2        (PORT_ALT2_FUNC_MODE)
#define    PORT113_LPUART2_RX        (PORT_ALT3_FUNC_MODE)
#define    PORT128_GPIO        (PORT_GPIO_MODE)
#define    PORT128_LPSPI0_SCK        (PORT_ALT2_FUNC_MODE)
#define    PORT128_TCLK1        (PORT_ALT3_FUNC_MODE)
#define    PORT128_LPSPI1_SOUT        (PORT_ALT5_FUNC_MODE)
#define    PORT128_FTM1_FLT2        (PORT_ALT6_FUNC_MODE)
#define    PORT129_GPIO        (PORT_GPIO_MODE)
#define    PORT129_LPSPI0_SIN        (PORT_ALT2_FUNC_MODE)
#define    PORT129_LPI2C0_HREQ        (PORT_ALT3_FUNC_MODE)
#define    PORT129_LPSPI1_PCS0        (PORT_ALT5_FUNC_MODE)
#define    PORT129_FTM1_FLT1        (PORT_ALT6_FUNC_MODE)
#define    PORT130_ADC1_SE10        (PORT_ALT0_FUNC_MODE)
#define    PORT130_GPIO        (PORT_GPIO_MODE)
#define    PORT130_LPSPI0_SOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT130_LPTMR0_ALT3        (PORT_ALT3_FUNC_MODE)
#define    PORT130_FTM3_CH6        (PORT_ALT4_FUNC_MODE)
#define    PORT130_LPUART1_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT131_GPIO        (PORT_GPIO_MODE)
#define    PORT131_FTM0_FLT0        (PORT_ALT2_FUNC_MODE)
#define    PORT131_LPUART2_RTS        (PORT_ALT3_FUNC_MODE)
#define    PORT131_FTM2_FLT0        (PORT_ALT4_FUNC_MODE)
#define    PORT131_TRGMUX_IN6        (PORT_ALT6_FUNC_MODE)
#define    PORT131_CMP0_OUT        (PORT_ALT7_FUNC_MODE)
#define    PORT132_GPIO        (PORT_GPIO_MODE)
#define    PORT132_FTM2_QD_PHB        (PORT_ALT3_FUNC_MODE)
#define    PORT132_FTM2_CH2        (PORT_ALT4_FUNC_MODE)
#define    PORT132_CAN0_RX        (PORT_ALT5_FUNC_MODE)
#define    PORT132_FXIO_D6        (PORT_ALT6_FUNC_MODE)
#define    PORT132_EWM_OUT_b        (PORT_ALT7_FUNC_MODE)
#define    PORT133_GPIO        (PORT_GPIO_MODE)
#define    PORT133_TCLK2        (PORT_ALT2_FUNC_MODE)
#define    PORT133_FTM2_QD_PHA        (PORT_ALT3_FUNC_MODE)
#define    PORT133_FTM2_CH3        (PORT_ALT4_FUNC_MODE)
#define    PORT133_CAN0_TX        (PORT_ALT5_FUNC_MODE)
#define    PORT133_FXIO_D7        (PORT_ALT6_FUNC_MODE)
#define    PORT133_EWM_IN        (PORT_ALT7_FUNC_MODE)
#define    PORT134_ADC1_SE11        (PORT_ALT0_FUNC_MODE)
#define    PORT134_GPIO        (PORT_GPIO_MODE)
#define    PORT134_LPSPI0_PCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT134_FTM3_CH7        (PORT_ALT4_FUNC_MODE)
#define    PORT134_LPUART1_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT135_GPIO        (PORT_GPIO_MODE)
#define    PORT135_FTM0_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT135_FTM3_FLT0        (PORT_ALT3_FUNC_MODE)
#define    PORT136_CMP0_IN3        (PORT_ALT0_FUNC_MODE)
#define    PORT136_GPIO        (PORT_GPIO_MODE)
#define    PORT136_FTM0_CH6        (PORT_ALT2_FUNC_MODE)
#define    PORT137_GPIO        (PORT_GPIO_MODE)
#define    PORT137_FTM0_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT137_LPUART2_CTS        (PORT_ALT3_FUNC_MODE)
#define    PORT138_GPIO        (PORT_GPIO_MODE)
#define    PORT138_CLKOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT138_LPSPI2_PCS1        (PORT_ALT3_FUNC_MODE)
#define    PORT138_FTM2_CH4        (PORT_ALT4_FUNC_MODE)
#define    PORT138_FXIO_D4        (PORT_ALT6_FUNC_MODE)
#define    PORT138_TRGMUX_OUT4        (PORT_ALT7_FUNC_MODE)
#define    PORT139_GPIO        (PORT_GPIO_MODE)
#define    PORT139_LPSPI2_PCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT139_LPTMR0_ALT1        (PORT_ALT3_FUNC_MODE)
#define    PORT139_FTM2_CH5        (PORT_ALT4_FUNC_MODE)
#define    PORT139_FXIO_D5        (PORT_ALT6_FUNC_MODE)
#define    PORT139_TRGMUX_OUT5        (PORT_ALT7_FUNC_MODE)
#define    PORT140_GPIO        (PORT_GPIO_MODE)
#define    PORT140_FTM0_FLT3        (PORT_ALT2_FUNC_MODE)
#define    PORT140_LPUART2_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT141_GPIO        (PORT_GPIO_MODE)
#define    PORT141_LPSPI2_PCS2        (PORT_ALT3_FUNC_MODE)
#define    PORT141_FTM2_FLT0        (PORT_ALT4_FUNC_MODE)
#define    PORT142_GPIO        (PORT_GPIO_MODE)
#define    PORT142_FTM0_FLT1        (PORT_ALT2_FUNC_MODE)
#define    PORT142_FTM2_FLT1        (PORT_ALT4_FUNC_MODE)
#define    PORT143_GPIO        (PORT_GPIO_MODE)
#define    PORT143_LPUART1_CTS        (PORT_ALT2_FUNC_MODE)
#define    PORT143_LPSPI2_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT143_FTM2_CH6        (PORT_ALT4_FUNC_MODE)
#define    PORT143_FXIO_D2        (PORT_ALT6_FUNC_MODE)
#define    PORT143_TRGMUX_OUT6        (PORT_ALT7_FUNC_MODE)
#define    PORT144_GPIO        (PORT_GPIO_MODE)
#define    PORT144_LPUART1_RTS        (PORT_ALT2_FUNC_MODE)
#define    PORT144_LPSPI2_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT144_FTM2_CH7        (PORT_ALT4_FUNC_MODE)
#define    PORT144_FXIO_D3        (PORT_ALT6_FUNC_MODE)
#define    PORT144_TRGMUX_OUT7        (PORT_ALT7_FUNC_MODE)

/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_ON)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
#define PORT_SET_PIN_DIRECTION_API      (STD_ON)

/**
* @brief Use/remove Port_Set2PinsDirection function from the compiled driver
*
* PORT_SET_2_PINS_DIRECTION_API_define
*/
#define PORT_SET_2_PINS_DIRECTION_API   (STD_OFF)

/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
#define PORT_SET_PIN_MODE_API           (STD_ON)

/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the PORT driver code can be executed from both supervisor and user mode.
*/

#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)


#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef PORT_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
   #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Port in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef PORT_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           (STD_ON)


/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*/
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_ADC0_SE12  6
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_ADC0_SE6  7
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_ADC0_SE7  8
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_DBG  15
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_DIG_KEY  13
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_DOUT0  11
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_DOUT1  12
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_EXTAL  4
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_JTAG_TCLK  0
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_JTAG_TDI  1
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_JTAG_TDO  2
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_JTAG_TMS  3
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_PWM0  9
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_PWM1  10
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_PWM2  14
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_XTAL  5
/** @violates @ref PORT_CFG_H_REF_1 The used compilers use more than 31 chars for identifiers. */
#define PortConfigSet_PortContainer_0_PortPin_DIG_KEY2  16


/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)8)
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO_U8           ((uint8)10)
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)144)

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16                        ((uint16)17)

/**
 * @brief Number of UnUsed pin array
*/
#define PORT_MAX_UNUSED_PADS_U16   (72U)

/**
* @brief Port driver Post-build configuration switch
*/
#define PORT_PRECOMPILE_SUPPORT     (STD_OFF)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*
* @api
*/
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;                                                           /**< @brief Number of used pads (to be configured) */
    VAR(uint16, AUTOMATIC) u16NumUnusedPins;                                                     /**< @brief Number of unused pads */
    P2CONST(uint16, AUTOMATIC, PORT_APPL_CONST) au16UnusedPads;                                  /**< @brief Unused pad id's array */
    P2CONST(Port_Port_Ci_UnUsedPinConfigType, AUTOMATIC, PORT_APPL_CONST) pUnusedPadConfig;      /**< @brief Unused pad configuration */
    P2CONST(Port_Port_Ci_PinConfigType,       AUTOMATIC, PORT_APPL_CONST) pUsedPadConfig;        /**< @brief Used pads data configuration */
    VAR(uint8, AUTOMATIC)  u8NumDigitalFilterPorts;                                              /**< @brief Number of configured digital filter ports */
    P2CONST(Port_DigitalFilter_ConfigType, AUTOMATIC, PORT_APPL_CONST) pDigitalFilterConfig;     /**< @brief Digital filter ports configuration */
} Port_ConfigType;

/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief External declaration of the Port pin description array
*/
/** @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed from within a single function. */
extern CONST(uint16, PORT_CONST) Port_au16PinDescription[8][10];

#endif

#define PORT_STOP_SEC_CONST_16
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"


/** @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope */
extern CONST(Port_ConfigType, PORT_CONST) PortConfigSet;


#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_CFG_H_REF_2 Precautions to prevent the contents of a header file being included twice. */
#include "Port_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */
