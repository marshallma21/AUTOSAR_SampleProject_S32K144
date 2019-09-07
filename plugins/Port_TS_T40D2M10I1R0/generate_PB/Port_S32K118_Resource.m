/**
*   @ file    S32K14x_Resource.m
*   @ version 1.0.1
*
*   @ brief   AUTOSAR Port - Resource for this platform
*   @ details Resource for this platform
*/
/*==================================================================================================
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
==================================================================================================*/
[!IF "not(var:defined('PORT_RESOURCE_M'))"!]
[!VAR "PORT_RESOURCE_M"="'true'"!]
[!VAR "PinMap"!]
ADC0_SE0_CMP0_IN0_PORT0;0:[!//
LPI2C0_SCLS_PORT0;3:[!//
FXIO_D2_PORT0;4:[!//
LPUART0_CTS_PORT0;6:[!//
TRGMUX_OUT3_PORT0;7:[!//
ADC0_SE1_CMP0_IN1_PORT1;0:[!//
FTM1_CH1_PORT1;2:[!//
LPI2C0_SDAS_PORT1;3:[!//
FXIO_D3_PORT1;4:[!//
FTM1_QD_PHA_PORT1;5:[!//
LPUART0_RTS_PORT1;6:[!//
TRGMUX_OUT0_PORT1;7:[!//
LPI2C0_SDA_PORT2;3:[!//
FXIO_D4_PORT2;5:[!//
LPUART0_RX_PORT2;6:[!//
LPI2C0_SCL_PORT3;3:[!//
FXIO_D5_PORT3;5:[!//
LPUART0_TX_PORT3;6:[!//
CMP0_OUT_PORT4;4:[!//
JTAG_TMS_SWD_DIO_PORT4;7:[!//
TCLK1_PORT5;3:[!//
RESET_b_PORT5;7:[!//
ADC0_SE2_PORT6;0:[!//
FTM0_FLT1_PORT6;2:[!//
LPSPI1_PCS1_PORT6;3:[!//
LPUART1_CTS_PORT6;6:[!//
ADC0_SE3_PORT7;0:[!//
FTM0_FLT2_PORT7;2:[!//
RTC_CLKIN_PORT7;4:[!//
LPUART1_RTS_PORT7;6:[!//
FTM1_CH4_PORT10;2:[!//
FXIO_D0_PORT10;4:[!//
JTAG_TDO_PORT10;7:[!//
FTM1_CH5_PORT11;2:[!//
FXIO_D1_PORT11;4:[!//
CMP0_RRT_PORT11;5:[!//
FTM1_CH6_PORT12;2:[!//
FTM1_CH7_PORT13;2:[!//
ADC0_SE4_PORT32;0:[!//
LPUART0_RX_PORT32;2:[!//
LPSPI0_PCS0_PORT32;3:[!//
LPTMR0_ALT3_PORT32;4:[!//
CAN0_RX_PORT32;5:[!//
ADC0_SE5_PORT33;0:[!//
LPUART0_TX_PORT33;2:[!//
LPSPI0_SOUT_PORT33;3:[!//
TCLK0_PORT33;4:[!//
CAN0_TX_PORT33;5:[!//
ADC0_SE6_PORT34;0:[!//
FTM1_CH0_PORT34;2:[!//
LPSPI0_SCK_PORT34;3:[!//
FTM1_QD_PHB_PORT34;4:[!//
TRGMUX_IN3_PORT34;6:[!//
ADC0_SE7_PORT35;0:[!//
FTM1_CH1_PORT35;2:[!//
LPSPI0_SIN_PORT35;3:[!//
FTM1_QD_PHA_PORT35;4:[!//
TRGMUX_IN2_PORT35;6:[!//
FTM0_CH4_PORT36;2:[!//
LPSPI0_SOUT_PORT36;3:[!//
TRGMUX_IN1_PORT36;6:[!//
FTM0_CH5_PORT37;2:[!//
LPSPI0_PCS1_PORT37;3:[!//
LPSPI0_PCS0_PORT37;4:[!//
CLKOUT_PORT37;5:[!//
TRGMUX_IN0_PORT37;6:[!//
XTAL_PORT38;0:[!//
LPI2C0_SDA_PORT38;2:[!//
EXTAL_PORT39;0:[!//
LPI2C0_SCL_PORT39;2:[!//
FTM0_CH0_PORT44;2:[!//
FTM0_CH1_PORT45;2:[!//
ADC0_SE8_PORT64;0:[!//
FTM0_CH0_PORT64;2:[!//
FTM1_CH6_PORT64;6:[!//
ADC0_SE9_PORT65;0:[!//
FTM0_CH1_PORT65;2:[!//
FTM1_CH7_PORT65;6:[!//
ADC0_SE10_CMP0_IN5_PORT66;0:[!//
FTM0_CH2_PORT66;2:[!//
CAN0_RX_PORT66;3:[!//
LPUART0_RX_PORT66;4:[!//
ADC0_SE11_CMP0_IN4_PORT67;0:[!//
FTM0_CH3_PORT67;2:[!//
CAN0_TX_PORT67;3:[!//
LPUART0_TX_PORT67;4:[!//
CMP0_IN2_PORT68;0:[!//
FTM1_CH0_PORT68;2:[!//
RTC_CLKOUT_PORT68;3:[!//
FTM1_QD_PHB_PORT68;6:[!//
JTAG_TCLK_SWD_CLK_PORT68;7:[!//
RTC_CLKOUT_PORT69;3:[!//
JTAG_TDI_PORT69;7:[!//
LPUART1_RX_PORT70;2:[!//
FTM1_QD_PHB_PORT70;6:[!//
LPUART1_TX_PORT71;2:[!//
FTM1_QD_PHA_PORT71;6:[!//
LPUART1_RX_PORT72;2:[!//
FTM1_FLT0_PORT72;3:[!//
LPUART0_CTS_PORT72;6:[!//
LPUART1_TX_PORT73;2:[!//
FTM1_FLT1_PORT73;3:[!//
LPUART0_RTS_PORT73;6:[!//
ADC0_SE12_PORT78;0:[!//
FTM1_CH2_PORT78;2:[!//
TRGMUX_IN9_PORT78;6:[!//
ADC0_SE13_PORT79;0:[!//
FTM1_CH3_PORT79;2:[!//
TRGMUX_IN8_PORT79;6:[!//
ADC0_SE14_PORT80;0:[!//
FTM1_FLT2_PORT80;2:[!//
ADC0_SE15_PORT81;0:[!//
FTM1_FLT3_PORT81;2:[!//
FTM0_CH2_PORT96;2:[!//
LPSPI1_SCK_PORT96;3:[!//
FXIO_D0_PORT96;6:[!//
TRGMUX_OUT1_PORT96;7:[!//
FTM0_CH3_PORT97;2:[!//
LPSPI1_SIN_PORT97;3:[!//
FXIO_D1_PORT97;6:[!//
TRGMUX_OUT2_PORT97;7:[!//
LPSPI1_SOUT_PORT98;3:[!//
FXIO_D4_PORT98;4:[!//
FXIO_D6_PORT98;5:[!//
TRGMUX_IN5_PORT98;6:[!//
LPSPI1_PCS0_PORT99;3:[!//
FXIO_D5_PORT99;4:[!//
FXIO_D7_PORT99;5:[!//
TRGMUX_IN4_PORT99;6:[!//
NMI_b_PORT99;7:[!//
FTM0_FLT3_PORT100;2:[!//
LPTMR0_ALT2_PORT101;3:[!//
TRGMUX_IN7_PORT101;6:[!//
CMP0_IN7_PORT102;0:[!//
CMP0_IN6_PORT103;0:[!//
FTM0_CH0_PORT111;2:[!//
LPSPI0_SCK_PORT111;4:[!//
FTM0_CH1_PORT112;2:[!//
LPSPI0_SIN_PORT112;4:[!//
CMP0_RRT_PORT112;5:[!//
LPSPI0_SCK_PORT128;2:[!//
TCLK1_PORT128;3:[!//
LPSPI1_SOUT_PORT128;5:[!//
FTM1_FLT2_PORT128;6:[!//
LPSPI0_SIN_PORT129;2:[!//
LPI2C0_HREQ_PORT129;3:[!//
LPSPI1_PCS0_PORT129;5:[!//
FTM1_FLT1_PORT129;6:[!//
LPSPI0_SOUT_PORT130;2:[!//
LPTMR0_ALT3_PORT130;3:[!//
LPUART1_CTS_PORT130;6:[!//
FTM0_FLT0_PORT131;2:[!//
TRGMUX_IN6_PORT131;6:[!//
CMP0_OUT_PORT131;7:[!//
CAN0_RX_PORT132;5:[!//
FXIO_D6_PORT132;6:[!//
TCLK2_PORT133;2:[!//
CAN0_TX_PORT133;5:[!//
FXIO_D7_PORT133;6:[!//
LPSPI0_PCS2_PORT134;2:[!//
LPUART1_RTS_PORT134;6:[!//
FTM0_CH7_PORT135;2:[!//
CMP0_IN3_PORT136;0:[!//
FTM0_CH6_PORT136;2:[!//
FTM0_CH7_PORT137;2:[!//
CLKOUT_PORT138;2:[!//
FXIO_D4_PORT138;6:[!//
TRGMUX_OUT4_PORT138;7:[!//
LPTMR0_ALT1_PORT139;3:[!//
FXIO_D5_PORT139;6:[!//
TRGMUX_OUT5_PORT139;7:[!//
[!ENDVAR!]

[!VAR "PinAbstractionModes_1"!]

#define    PORT0_ADC0_SE0_CMP0_IN0        (PORT_ALT0_FUNC_MODE)
#define    PORT0_GPIO        (PORT_GPIO_MODE)
#define    PORT0_LPI2C0_SCLS        (PORT_ALT3_FUNC_MODE)
#define    PORT0_FXIO_D2        (PORT_ALT4_FUNC_MODE)
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
#define    PORT2_GPIO        (PORT_GPIO_MODE)
#define    PORT2_LPI2C0_SDA        (PORT_ALT3_FUNC_MODE)
#define    PORT2_FXIO_D4        (PORT_ALT5_FUNC_MODE)
#define    PORT2_LPUART0_RX        (PORT_ALT6_FUNC_MODE)
#define    PORT3_GPIO        (PORT_GPIO_MODE)
#define    PORT3_LPI2C0_SCL        (PORT_ALT3_FUNC_MODE)
#define    PORT3_FXIO_D5        (PORT_ALT5_FUNC_MODE)
#define    PORT3_LPUART0_TX        (PORT_ALT6_FUNC_MODE)
#define    PORT4_GPIO        (PORT_GPIO_MODE)
#define    PORT4_CMP0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT4_JTAG_TMS_SWD_DIO        (PORT_ALT7_FUNC_MODE)
#define    PORT5_GPIO        (PORT_GPIO_MODE)
#define    PORT5_TCLK1        (PORT_ALT3_FUNC_MODE)
#define    PORT5_RESET_b        (PORT_ALT7_FUNC_MODE)
#define    PORT7_ADC0_SE3        (PORT_ALT0_FUNC_MODE)
#define    PORT7_GPIO        (PORT_GPIO_MODE)
#define    PORT7_FTM0_FLT2        (PORT_ALT2_FUNC_MODE)
#define    PORT7_RTC_CLKIN        (PORT_ALT4_FUNC_MODE)
#define    PORT7_LPUART1_RTS        (PORT_ALT6_FUNC_MODE)
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
#define    PORT13_GPIO        (PORT_GPIO_MODE)
#define    PORT13_FTM1_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT32_ADC0_SE4        (PORT_ALT0_FUNC_MODE)
#define    PORT32_GPIO        (PORT_GPIO_MODE)
#define    PORT32_LPUART0_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT32_LPSPI0_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT32_LPTMR0_ALT3        (PORT_ALT4_FUNC_MODE)
#define    PORT32_CAN0_RX        (PORT_ALT5_FUNC_MODE)
#define    PORT33_ADC0_SE5        (PORT_ALT0_FUNC_MODE)
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
#define    PORT45_GPIO        (PORT_GPIO_MODE)
#define    PORT45_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT65_ADC0_SE9        (PORT_ALT0_FUNC_MODE)
#define    PORT65_GPIO        (PORT_GPIO_MODE)
#define    PORT65_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
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
#define    PORT68_FTM1_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT68_JTAG_TCLK_SWD_CLK        (PORT_ALT7_FUNC_MODE)
#define    PORT69_GPIO        (PORT_GPIO_MODE)
#define    PORT69_RTC_CLKOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT69_JTAG_TDI        (PORT_ALT7_FUNC_MODE)
#define    PORT70_GPIO        (PORT_GPIO_MODE)
#define    PORT70_LPUART1_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT70_FTM1_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT71_GPIO        (PORT_GPIO_MODE)
#define    PORT71_LPUART1_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT71_FTM1_QD_PHA        (PORT_ALT6_FUNC_MODE)
#define    PORT72_GPIO        (PORT_GPIO_MODE)
#define    PORT72_LPUART1_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT72_FTM1_FLT0        (PORT_ALT3_FUNC_MODE)
#define    PORT72_LPUART0_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT73_GPIO        (PORT_GPIO_MODE)
#define    PORT73_LPUART1_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT73_FTM1_FLT1        (PORT_ALT3_FUNC_MODE)
#define    PORT73_LPUART0_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT78_ADC0_SE12        (PORT_ALT0_FUNC_MODE)
#define    PORT78_GPIO        (PORT_GPIO_MODE)
#define    PORT78_FTM1_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT78_TRGMUX_IN9        (PORT_ALT6_FUNC_MODE)
#define    PORT79_ADC0_SE13        (PORT_ALT0_FUNC_MODE)
#define    PORT79_GPIO        (PORT_GPIO_MODE)
#define    PORT79_FTM1_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT79_TRGMUX_IN8        (PORT_ALT6_FUNC_MODE)
#define    PORT80_ADC0_SE14        (PORT_ALT0_FUNC_MODE)
#define    PORT80_GPIO        (PORT_GPIO_MODE)
#define    PORT80_FTM1_FLT2        (PORT_ALT2_FUNC_MODE)
#define    PORT96_GPIO        (PORT_GPIO_MODE)
#define    PORT96_FTM0_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT96_LPSPI1_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT96_FXIO_D0        (PORT_ALT6_FUNC_MODE)
#define    PORT96_TRGMUX_OUT1        (PORT_ALT7_FUNC_MODE)
#define    PORT97_GPIO        (PORT_GPIO_MODE)
#define    PORT97_FTM0_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT97_LPSPI1_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT97_FXIO_D1        (PORT_ALT6_FUNC_MODE)
#define    PORT97_TRGMUX_OUT2        (PORT_ALT7_FUNC_MODE)
#define    PORT98_GPIO        (PORT_GPIO_MODE)
#define    PORT98_LPSPI1_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT98_FXIO_D4        (PORT_ALT4_FUNC_MODE)
#define    PORT98_FXIO_D6        (PORT_ALT5_FUNC_MODE)
#define    PORT98_TRGMUX_IN5        (PORT_ALT6_FUNC_MODE)
#define    PORT99_GPIO        (PORT_GPIO_MODE)
#define    PORT99_LPSPI1_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT99_FXIO_D5        (PORT_ALT4_FUNC_MODE)
#define    PORT99_FXIO_D7        (PORT_ALT5_FUNC_MODE)
#define    PORT99_TRGMUX_IN4        (PORT_ALT6_FUNC_MODE)
#define    PORT99_NMI_b        (PORT_ALT7_FUNC_MODE)
#define    PORT101_GPIO        (PORT_GPIO_MODE)
#define    PORT101_LPTMR0_ALT2        (PORT_ALT3_FUNC_MODE)
#define    PORT101_TRGMUX_IN7        (PORT_ALT6_FUNC_MODE)
#define    PORT111_GPIO        (PORT_GPIO_MODE)
#define    PORT111_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT111_LPSPI0_SCK        (PORT_ALT4_FUNC_MODE)
#define    PORT112_GPIO        (PORT_GPIO_MODE)
#define    PORT112_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT112_LPSPI0_SIN        (PORT_ALT4_FUNC_MODE)
#define    PORT112_CMP0_RRT        (PORT_ALT5_FUNC_MODE)
#define    PORT132_GPIO        (PORT_GPIO_MODE)
#define    PORT132_CAN0_RX        (PORT_ALT5_FUNC_MODE)
#define    PORT132_FXIO_D6        (PORT_ALT6_FUNC_MODE)
#define    PORT133_GPIO        (PORT_GPIO_MODE)
#define    PORT133_TCLK2        (PORT_ALT2_FUNC_MODE)
#define    PORT133_CAN0_TX        (PORT_ALT5_FUNC_MODE)
#define    PORT133_FXIO_D7        (PORT_ALT6_FUNC_MODE)
#define    PORT136_CMP0_IN3        (PORT_ALT0_FUNC_MODE)
#define    PORT136_GPIO        (PORT_GPIO_MODE)
#define    PORT136_FTM0_CH6        (PORT_ALT2_FUNC_MODE)
#define    PORT137_GPIO        (PORT_GPIO_MODE)
#define    PORT137_FTM0_CH7        (PORT_ALT2_FUNC_MODE)
[!ENDVAR!]




[!VAR "PinAbstractionModes_2"!]

#define    PORT0_ADC0_SE0_CMP0_IN0        (PORT_ALT0_FUNC_MODE)
#define    PORT0_GPIO        (PORT_GPIO_MODE)
#define    PORT0_LPI2C0_SCLS        (PORT_ALT3_FUNC_MODE)
#define    PORT0_FXIO_D2        (PORT_ALT4_FUNC_MODE)
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
#define    PORT2_GPIO        (PORT_GPIO_MODE)
#define    PORT2_LPI2C0_SDA        (PORT_ALT3_FUNC_MODE)
#define    PORT2_FXIO_D4        (PORT_ALT5_FUNC_MODE)
#define    PORT2_LPUART0_RX        (PORT_ALT6_FUNC_MODE)
#define    PORT3_GPIO        (PORT_GPIO_MODE)
#define    PORT3_LPI2C0_SCL        (PORT_ALT3_FUNC_MODE)
#define    PORT3_FXIO_D5        (PORT_ALT5_FUNC_MODE)
#define    PORT3_LPUART0_TX        (PORT_ALT6_FUNC_MODE)
#define    PORT4_GPIO        (PORT_GPIO_MODE)
#define    PORT4_CMP0_OUT        (PORT_ALT4_FUNC_MODE)
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
#define    PORT13_GPIO        (PORT_GPIO_MODE)
#define    PORT13_FTM1_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT32_ADC0_SE4        (PORT_ALT0_FUNC_MODE)
#define    PORT32_GPIO        (PORT_GPIO_MODE)
#define    PORT32_LPUART0_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT32_LPSPI0_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT32_LPTMR0_ALT3        (PORT_ALT4_FUNC_MODE)
#define    PORT32_CAN0_RX        (PORT_ALT5_FUNC_MODE)
#define    PORT33_ADC0_SE5        (PORT_ALT0_FUNC_MODE)
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
#define    PORT44_GPIO        (PORT_GPIO_MODE)
#define    PORT44_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT45_GPIO        (PORT_GPIO_MODE)
#define    PORT45_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT64_ADC0_SE8        (PORT_ALT0_FUNC_MODE)
#define    PORT64_GPIO        (PORT_GPIO_MODE)
#define    PORT64_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT64_FTM1_CH6        (PORT_ALT6_FUNC_MODE)
#define    PORT65_ADC0_SE9        (PORT_ALT0_FUNC_MODE)
#define    PORT65_GPIO        (PORT_GPIO_MODE)
#define    PORT65_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
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
#define    PORT68_FTM1_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT68_JTAG_TCLK_SWD_CLK        (PORT_ALT7_FUNC_MODE)
#define    PORT69_GPIO        (PORT_GPIO_MODE)
#define    PORT69_RTC_CLKOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT69_JTAG_TDI        (PORT_ALT7_FUNC_MODE)
#define    PORT70_GPIO        (PORT_GPIO_MODE)
#define    PORT70_LPUART1_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT70_FTM1_QD_PHB        (PORT_ALT6_FUNC_MODE)
#define    PORT71_GPIO        (PORT_GPIO_MODE)
#define    PORT71_LPUART1_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT71_FTM1_QD_PHA        (PORT_ALT6_FUNC_MODE)
#define    PORT72_GPIO        (PORT_GPIO_MODE)
#define    PORT72_LPUART1_RX        (PORT_ALT2_FUNC_MODE)
#define    PORT72_FTM1_FLT0        (PORT_ALT3_FUNC_MODE)
#define    PORT72_LPUART0_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT73_GPIO        (PORT_GPIO_MODE)
#define    PORT73_LPUART1_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT73_FTM1_FLT1        (PORT_ALT3_FUNC_MODE)
#define    PORT73_LPUART0_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT78_ADC0_SE12        (PORT_ALT0_FUNC_MODE)
#define    PORT78_GPIO        (PORT_GPIO_MODE)
#define    PORT78_FTM1_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT78_TRGMUX_IN9        (PORT_ALT6_FUNC_MODE)
#define    PORT79_ADC0_SE13        (PORT_ALT0_FUNC_MODE)
#define    PORT79_GPIO        (PORT_GPIO_MODE)
#define    PORT79_FTM1_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT79_TRGMUX_IN8        (PORT_ALT6_FUNC_MODE)
#define    PORT80_ADC0_SE14        (PORT_ALT0_FUNC_MODE)
#define    PORT80_GPIO        (PORT_GPIO_MODE)
#define    PORT80_FTM1_FLT2        (PORT_ALT2_FUNC_MODE)
#define    PORT81_ADC0_SE15        (PORT_ALT0_FUNC_MODE)
#define    PORT81_GPIO        (PORT_GPIO_MODE)
#define    PORT81_FTM1_FLT3        (PORT_ALT2_FUNC_MODE)
#define    PORT96_GPIO        (PORT_GPIO_MODE)
#define    PORT96_FTM0_CH2        (PORT_ALT2_FUNC_MODE)
#define    PORT96_LPSPI1_SCK        (PORT_ALT3_FUNC_MODE)
#define    PORT96_FXIO_D0        (PORT_ALT6_FUNC_MODE)
#define    PORT96_TRGMUX_OUT1        (PORT_ALT7_FUNC_MODE)
#define    PORT97_GPIO        (PORT_GPIO_MODE)
#define    PORT97_FTM0_CH3        (PORT_ALT2_FUNC_MODE)
#define    PORT97_LPSPI1_SIN        (PORT_ALT3_FUNC_MODE)
#define    PORT97_FXIO_D1        (PORT_ALT6_FUNC_MODE)
#define    PORT97_TRGMUX_OUT2        (PORT_ALT7_FUNC_MODE)
#define    PORT98_GPIO        (PORT_GPIO_MODE)
#define    PORT98_LPSPI1_SOUT        (PORT_ALT3_FUNC_MODE)
#define    PORT98_FXIO_D4        (PORT_ALT4_FUNC_MODE)
#define    PORT98_FXIO_D6        (PORT_ALT5_FUNC_MODE)
#define    PORT98_TRGMUX_IN5        (PORT_ALT6_FUNC_MODE)
#define    PORT99_GPIO        (PORT_GPIO_MODE)
#define    PORT99_LPSPI1_PCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT99_FXIO_D5        (PORT_ALT4_FUNC_MODE)
#define    PORT99_FXIO_D7        (PORT_ALT5_FUNC_MODE)
#define    PORT99_TRGMUX_IN4        (PORT_ALT6_FUNC_MODE)
#define    PORT99_NMI_b        (PORT_ALT7_FUNC_MODE)
#define    PORT100_GPIO        (PORT_GPIO_MODE)
#define    PORT100_FTM0_FLT3        (PORT_ALT2_FUNC_MODE)
#define    PORT101_GPIO        (PORT_GPIO_MODE)
#define    PORT101_LPTMR0_ALT2        (PORT_ALT3_FUNC_MODE)
#define    PORT101_TRGMUX_IN7        (PORT_ALT6_FUNC_MODE)
#define    PORT102_CMP0_IN7        (PORT_ALT0_FUNC_MODE)
#define    PORT102_GPIO        (PORT_GPIO_MODE)
#define    PORT103_CMP0_IN6        (PORT_ALT0_FUNC_MODE)
#define    PORT103_GPIO        (PORT_GPIO_MODE)
#define    PORT111_GPIO        (PORT_GPIO_MODE)
#define    PORT111_FTM0_CH0        (PORT_ALT2_FUNC_MODE)
#define    PORT111_LPSPI0_SCK        (PORT_ALT4_FUNC_MODE)
#define    PORT112_GPIO        (PORT_GPIO_MODE)
#define    PORT112_FTM0_CH1        (PORT_ALT2_FUNC_MODE)
#define    PORT112_LPSPI0_SIN        (PORT_ALT4_FUNC_MODE)
#define    PORT112_CMP0_RRT        (PORT_ALT5_FUNC_MODE)
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
#define    PORT130_GPIO        (PORT_GPIO_MODE)
#define    PORT130_LPSPI0_SOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT130_LPTMR0_ALT3        (PORT_ALT3_FUNC_MODE)
#define    PORT130_LPUART1_CTS        (PORT_ALT6_FUNC_MODE)
#define    PORT131_GPIO        (PORT_GPIO_MODE)
#define    PORT131_FTM0_FLT0        (PORT_ALT2_FUNC_MODE)
#define    PORT131_TRGMUX_IN6        (PORT_ALT6_FUNC_MODE)
#define    PORT131_CMP0_OUT        (PORT_ALT7_FUNC_MODE)
#define    PORT132_GPIO        (PORT_GPIO_MODE)
#define    PORT132_CAN0_RX        (PORT_ALT5_FUNC_MODE)
#define    PORT132_FXIO_D6        (PORT_ALT6_FUNC_MODE)
#define    PORT133_GPIO        (PORT_GPIO_MODE)
#define    PORT133_TCLK2        (PORT_ALT2_FUNC_MODE)
#define    PORT133_CAN0_TX        (PORT_ALT5_FUNC_MODE)
#define    PORT133_FXIO_D7        (PORT_ALT6_FUNC_MODE)
#define    PORT134_GPIO        (PORT_GPIO_MODE)
#define    PORT134_LPSPI0_PCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT134_LPUART1_RTS        (PORT_ALT6_FUNC_MODE)
#define    PORT135_GPIO        (PORT_GPIO_MODE)
#define    PORT135_FTM0_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT136_CMP0_IN3        (PORT_ALT0_FUNC_MODE)
#define    PORT136_GPIO        (PORT_GPIO_MODE)
#define    PORT136_FTM0_CH6        (PORT_ALT2_FUNC_MODE)
#define    PORT137_GPIO        (PORT_GPIO_MODE)
#define    PORT137_FTM0_CH7        (PORT_ALT2_FUNC_MODE)
#define    PORT138_GPIO        (PORT_GPIO_MODE)
#define    PORT138_CLKOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT138_FXIO_D4        (PORT_ALT6_FUNC_MODE)
#define    PORT138_TRGMUX_OUT4        (PORT_ALT7_FUNC_MODE)
#define    PORT139_GPIO        (PORT_GPIO_MODE)
#define    PORT139_LPTMR0_ALT1        (PORT_ALT3_FUNC_MODE)
#define    PORT139_FXIO_D5        (PORT_ALT6_FUNC_MODE)
#define    PORT139_TRGMUX_OUT5        (PORT_ALT7_FUNC_MODE)
[!ENDVAR!]




[!VAR "PinAbstractionModes_"!]

[!ENDVAR!]




[!VAR "CHECK_1"!]

/*  Mode PORT_ALT0_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_ADC0_SE0_CMP0_IN0 |
PORT1_ADC0_SE1_CMP0_IN1 |
PORT7_ADC0_SE3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(7)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_ADC0_SE4 |
PORT33_ADC0_SE5 |
PORT34_ADC0_SE6 |
PORT35_ADC0_SE7 |
PORT38_XTAL |
PORT39_EXTAL */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT65_ADC0_SE9 |
PORT66_ADC0_SE10_CMP0_IN5 |
PORT67_ADC0_SE11_CMP0_IN4 |
PORT68_CMP0_IN2 |
PORT78_ADC0_SE12 |
PORT79_ADC0_SE13 */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_ADC0_SE14 */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 96 ... 111 */
  (uint16)0x0000,
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT136_CMP0_IN3 */
  (uint16)( SHL_PAD_U16(8)
          )
}
,
/*  Mode PORT_GPIO_MODE: */
{
/* Pads   0 ...  15 : PORT0_GPIO |
PORT1_GPIO |
PORT2_GPIO |
PORT3_GPIO |
PORT4_GPIO |
PORT5_GPIO |
PORT7_GPIO |
PORT10_GPIO |
PORT11_GPIO |
PORT12_GPIO |
PORT13_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_GPIO |
PORT33_GPIO |
PORT34_GPIO |
PORT35_GPIO |
PORT36_GPIO |
PORT37_GPIO |
PORT38_GPIO |
PORT39_GPIO |
PORT45_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT65_GPIO |
PORT66_GPIO |
PORT67_GPIO |
PORT68_GPIO |
PORT69_GPIO |
PORT70_GPIO |
PORT71_GPIO |
PORT72_GPIO |
PORT73_GPIO |
PORT78_GPIO |
PORT79_GPIO */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_GPIO */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads  96 ... 111 : PORT96_GPIO |
PORT97_GPIO |
PORT98_GPIO |
PORT99_GPIO |
PORT101_GPIO |
PORT111_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_GPIO */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT132_GPIO |
PORT133_GPIO |
PORT136_GPIO |
PORT137_GPIO */
  (uint16)( SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9)
          )
}
,
/*  Mode PORT_ALT2_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT1_FTM1_CH1 |
PORT7_FTM0_FLT2 |
PORT10_FTM1_CH4 |
PORT11_FTM1_CH5 |
PORT12_FTM1_CH6 |
PORT13_FTM1_CH7 */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPUART0_RX |
PORT33_LPUART0_TX |
PORT34_FTM1_CH0 |
PORT35_FTM1_CH1 |
PORT36_FTM0_CH4 |
PORT37_FTM0_CH5 |
PORT38_LPI2C0_SDA |
PORT39_LPI2C0_SCL |
PORT45_FTM0_CH1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT65_FTM0_CH1 |
PORT66_FTM0_CH2 |
PORT67_FTM0_CH3 |
PORT68_FTM1_CH0 |
PORT70_LPUART1_RX |
PORT71_LPUART1_TX |
PORT72_LPUART1_RX |
PORT73_LPUART1_TX |
PORT78_FTM1_CH2 |
PORT79_FTM1_CH3 */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_FTM1_FLT2 */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads  96 ... 111 : PORT96_FTM0_CH2 |
PORT97_FTM0_CH3 |
PORT111_FTM0_CH0 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_FTM0_CH1 */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT133_TCLK2 |
PORT136_FTM0_CH6 |
PORT137_FTM0_CH7 */
  (uint16)( SHL_PAD_U16(5) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9)
          )
}
,
/*  Mode PORT_ALT3_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPI2C0_SCLS |
PORT1_LPI2C0_SDAS |
PORT2_LPI2C0_SDA |
PORT3_LPI2C0_SCL |
PORT5_TCLK1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPSPI0_PCS0 |
PORT33_LPSPI0_SOUT |
PORT34_LPSPI0_SCK |
PORT35_LPSPI0_SIN |
PORT36_LPSPI0_SOUT |
PORT37_LPSPI0_PCS1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT66_CAN0_RX |
PORT67_CAN0_TX |
PORT68_RTC_CLKOUT |
PORT69_RTC_CLKOUT |
PORT72_FTM1_FLT0 |
PORT73_FTM1_FLT1 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_LPSPI1_SCK |
PORT97_LPSPI1_SIN |
PORT98_LPSPI1_SOUT |
PORT99_LPSPI1_PCS0 |
PORT101_LPTMR0_ALT2 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 */
  (uint16)0x0000
}
,
/*  Mode PORT_ALT4_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_FXIO_D2 |
PORT1_FXIO_D3 |
PORT4_CMP0_OUT |
PORT7_RTC_CLKIN |
PORT10_FXIO_D0 |
PORT11_FXIO_D1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPTMR0_ALT3 |
PORT33_TCLK0 |
PORT34_FTM1_QD_PHB |
PORT35_FTM1_QD_PHA |
PORT37_LPSPI0_PCS0 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT66_LPUART0_RX |
PORT67_LPUART0_TX */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT98_FXIO_D4 |
PORT99_FXIO_D5 |
PORT111_LPSPI0_SCK */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_LPSPI0_SIN */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 */
  (uint16)0x0000
}
,
/*  Mode PORT_ALT5_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT1_FTM1_QD_PHA |
PORT2_FXIO_D4 |
PORT3_FXIO_D5 |
PORT11_CMP0_RRT */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(11)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_CAN0_RX |
PORT33_CAN0_TX |
PORT37_CLKOUT */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads 64 ... 79 */
  (uint16)0x0000,
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT98_FXIO_D6 |
PORT99_FXIO_D7 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3)
          ),
/* Pads 112 ... 127 : PORT112_CMP0_RRT */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT132_CAN0_RX |
PORT133_CAN0_TX */
  (uint16)( SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          )
}
,
/*  Mode PORT_ALT6_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPUART0_CTS |
PORT1_LPUART0_RTS |
PORT2_LPUART0_RX |
PORT3_LPUART0_TX |
PORT7_LPUART1_RTS */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(7)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT34_TRGMUX_IN3 |
PORT35_TRGMUX_IN2 |
PORT36_TRGMUX_IN1 |
PORT37_TRGMUX_IN0 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT65_FTM1_CH7 |
PORT68_FTM1_QD_PHB |
PORT70_FTM1_QD_PHB |
PORT71_FTM1_QD_PHA |
PORT72_LPUART0_CTS |
PORT73_LPUART0_RTS |
PORT78_TRGMUX_IN9 |
PORT79_TRGMUX_IN8 */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_FXIO_D0 |
PORT97_FXIO_D1 |
PORT98_TRGMUX_IN5 |
PORT99_TRGMUX_IN4 |
PORT101_TRGMUX_IN7 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT132_FXIO_D6 |
PORT133_FXIO_D7 */
  (uint16)( SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          )
}
,
/*  Mode PORT_ALT7_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_TRGMUX_OUT3 |
PORT1_TRGMUX_OUT0 |
PORT4_JTAG_TMS_SWD_DIO |
PORT5_RESET_b |
PORT10_JTAG_TDO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(10)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads 32 ... 47 */
  (uint16)0x0000,
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT68_JTAG_TCLK_SWD_CLK |
PORT69_JTAG_TDI */
  (uint16)( SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_TRGMUX_OUT1 |
PORT97_TRGMUX_OUT2 |
PORT99_NMI_b */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(3)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 */
  (uint16)0x0000
}

[!ENDVAR!]




[!VAR "CHECK_2"!]

/*  Mode PORT_ALT0_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_ADC0_SE0_CMP0_IN0 |
PORT1_ADC0_SE1_CMP0_IN1 |
PORT6_ADC0_SE2 |
PORT7_ADC0_SE3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_ADC0_SE4 |
PORT33_ADC0_SE5 |
PORT34_ADC0_SE6 |
PORT35_ADC0_SE7 |
PORT38_XTAL |
PORT39_EXTAL */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_ADC0_SE8 |
PORT65_ADC0_SE9 |
PORT66_ADC0_SE10_CMP0_IN5 |
PORT67_ADC0_SE11_CMP0_IN4 |
PORT68_CMP0_IN2 |
PORT78_ADC0_SE12 |
PORT79_ADC0_SE13 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_ADC0_SE14 |
PORT81_ADC0_SE15 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT102_CMP0_IN7 |
PORT103_CMP0_IN6 */
  (uint16)( SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT136_CMP0_IN3 */
  (uint16)( SHL_PAD_U16(8)
          )
}
,
/*  Mode PORT_GPIO_MODE: */
{
/* Pads   0 ...  15 : PORT0_GPIO |
PORT1_GPIO |
PORT2_GPIO |
PORT3_GPIO |
PORT4_GPIO |
PORT5_GPIO |
PORT6_GPIO |
PORT7_GPIO |
PORT10_GPIO |
PORT11_GPIO |
PORT12_GPIO |
PORT13_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_GPIO |
PORT33_GPIO |
PORT34_GPIO |
PORT35_GPIO |
PORT36_GPIO |
PORT37_GPIO |
PORT38_GPIO |
PORT39_GPIO |
PORT44_GPIO |
PORT45_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_GPIO |
PORT65_GPIO |
PORT66_GPIO |
PORT67_GPIO |
PORT68_GPIO |
PORT69_GPIO |
PORT70_GPIO |
PORT71_GPIO |
PORT72_GPIO |
PORT73_GPIO |
PORT78_GPIO |
PORT79_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_GPIO |
PORT81_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT96_GPIO |
PORT97_GPIO |
PORT98_GPIO |
PORT99_GPIO |
PORT100_GPIO |
PORT101_GPIO |
PORT102_GPIO |
PORT103_GPIO |
PORT111_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_GPIO */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT128_GPIO |
PORT129_GPIO |
PORT130_GPIO |
PORT131_GPIO |
PORT132_GPIO |
PORT133_GPIO |
PORT134_GPIO |
PORT135_GPIO |
PORT136_GPIO |
PORT137_GPIO |
PORT138_GPIO |
PORT139_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT2_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT1_FTM1_CH1 |
PORT6_FTM0_FLT1 |
PORT7_FTM0_FLT2 |
PORT10_FTM1_CH4 |
PORT11_FTM1_CH5 |
PORT12_FTM1_CH6 |
PORT13_FTM1_CH7 */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPUART0_RX |
PORT33_LPUART0_TX |
PORT34_FTM1_CH0 |
PORT35_FTM1_CH1 |
PORT36_FTM0_CH4 |
PORT37_FTM0_CH5 |
PORT38_LPI2C0_SDA |
PORT39_LPI2C0_SCL |
PORT44_FTM0_CH0 |
PORT45_FTM0_CH1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_FTM0_CH0 |
PORT65_FTM0_CH1 |
PORT66_FTM0_CH2 |
PORT67_FTM0_CH3 |
PORT68_FTM1_CH0 |
PORT70_LPUART1_RX |
PORT71_LPUART1_TX |
PORT72_LPUART1_RX |
PORT73_LPUART1_TX |
PORT78_FTM1_CH2 |
PORT79_FTM1_CH3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads  80 ...  95 : PORT80_FTM1_FLT2 |
PORT81_FTM1_FLT3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          ),
/* Pads  96 ... 111 : PORT96_FTM0_CH2 |
PORT97_FTM0_CH3 |
PORT100_FTM0_FLT3 |
PORT111_FTM0_CH0 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_FTM0_CH1 */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT128_LPSPI0_SCK |
PORT129_LPSPI0_SIN |
PORT130_LPSPI0_SOUT |
PORT131_FTM0_FLT0 |
PORT133_TCLK2 |
PORT134_LPSPI0_PCS2 |
PORT135_FTM0_CH7 |
PORT136_FTM0_CH6 |
PORT137_FTM0_CH7 |
PORT138_CLKOUT */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(10)
          )
}
,
/*  Mode PORT_ALT3_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPI2C0_SCLS |
PORT1_LPI2C0_SDAS |
PORT2_LPI2C0_SDA |
PORT3_LPI2C0_SCL |
PORT5_TCLK1 |
PORT6_LPSPI1_PCS1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPSPI0_PCS0 |
PORT33_LPSPI0_SOUT |
PORT34_LPSPI0_SCK |
PORT35_LPSPI0_SIN |
PORT36_LPSPI0_SOUT |
PORT37_LPSPI0_PCS1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT66_CAN0_RX |
PORT67_CAN0_TX |
PORT68_RTC_CLKOUT |
PORT69_RTC_CLKOUT |
PORT72_FTM1_FLT0 |
PORT73_FTM1_FLT1 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_LPSPI1_SCK |
PORT97_LPSPI1_SIN |
PORT98_LPSPI1_SOUT |
PORT99_LPSPI1_PCS0 |
PORT101_LPTMR0_ALT2 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT128_TCLK1 |
PORT129_LPI2C0_HREQ |
PORT130_LPTMR0_ALT3 |
PORT139_LPTMR0_ALT1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT4_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_FXIO_D2 |
PORT1_FXIO_D3 |
PORT4_CMP0_OUT |
PORT7_RTC_CLKIN |
PORT10_FXIO_D0 |
PORT11_FXIO_D1 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_LPTMR0_ALT3 |
PORT33_TCLK0 |
PORT34_FTM1_QD_PHB |
PORT35_FTM1_QD_PHA |
PORT37_LPSPI0_PCS0 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT66_LPUART0_RX |
PORT67_LPUART0_TX */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT98_FXIO_D4 |
PORT99_FXIO_D5 |
PORT111_LPSPI0_SCK */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(15)
          ),
/* Pads 112 ... 127 : PORT112_LPSPI0_SIN */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 */
  (uint16)0x0000
}
,
/*  Mode PORT_ALT5_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT1_FTM1_QD_PHA |
PORT2_FXIO_D4 |
PORT3_FXIO_D5 |
PORT11_CMP0_RRT */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(11)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT32_CAN0_RX |
PORT33_CAN0_TX |
PORT37_CLKOUT */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads 64 ... 79 */
  (uint16)0x0000,
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT98_FXIO_D6 |
PORT99_FXIO_D7 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3)
          ),
/* Pads 112 ... 127 : PORT112_CMP0_RRT */
  (uint16)( SHL_PAD_U16(0)
          ),
/* Pads 128 ... 143 : PORT128_LPSPI1_SOUT |
PORT129_LPSPI1_PCS0 |
PORT132_CAN0_RX |
PORT133_CAN0_TX */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          )
}
,
/*  Mode PORT_ALT6_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPUART0_CTS |
PORT1_LPUART0_RTS |
PORT2_LPUART0_RX |
PORT3_LPUART0_TX |
PORT6_LPUART1_CTS |
PORT7_LPUART1_RTS */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads  32 ...  47 : PORT34_TRGMUX_IN3 |
PORT35_TRGMUX_IN2 |
PORT36_TRGMUX_IN1 |
PORT37_TRGMUX_IN0 */
  (uint16)( SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT64_FTM1_CH6 |
PORT65_FTM1_CH7 |
PORT68_FTM1_QD_PHB |
PORT70_FTM1_QD_PHB |
PORT71_FTM1_QD_PHA |
PORT72_LPUART0_CTS |
PORT73_LPUART0_RTS |
PORT78_TRGMUX_IN9 |
PORT79_TRGMUX_IN8 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_FXIO_D0 |
PORT97_FXIO_D1 |
PORT98_TRGMUX_IN5 |
PORT99_TRGMUX_IN4 |
PORT101_TRGMUX_IN7 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT128_FTM1_FLT2 |
PORT129_FTM1_FLT1 |
PORT130_LPUART1_CTS |
PORT131_TRGMUX_IN6 |
PORT132_FXIO_D6 |
PORT133_FXIO_D7 |
PORT134_LPUART1_RTS |
PORT138_FXIO_D4 |
PORT139_FXIO_D5 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}
,
/*  Mode PORT_ALT7_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_TRGMUX_OUT3 |
PORT1_TRGMUX_OUT0 |
PORT4_JTAG_TMS_SWD_DIO |
PORT5_RESET_b |
PORT10_JTAG_TDO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(10)
          ),
/* Pads 16 ... 31 */
  (uint16)0x0000,
/* Pads 32 ... 47 */
  (uint16)0x0000,
/* Pads 48 ... 63 */
  (uint16)0x0000,
/* Pads  64 ...  79 : PORT68_JTAG_TCLK_SWD_CLK |
PORT69_JTAG_TDI */
  (uint16)( SHL_PAD_U16(4) |
            SHL_PAD_U16(5)
          ),
/* Pads 80 ... 95 */
  (uint16)0x0000,
/* Pads  96 ... 111 : PORT96_TRGMUX_OUT1 |
PORT97_TRGMUX_OUT2 |
PORT99_NMI_b */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(3)
          ),
/* Pads 112 ... 127 */
  (uint16)0x0000,
/* Pads 128 ... 143 : PORT131_CMP0_OUT |
PORT138_TRGMUX_OUT4 |
PORT139_TRGMUX_OUT5 */
  (uint16)( SHL_PAD_U16(3) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11)
          )
}

[!ENDVAR!]




[!VAR "CHECK_"!]

/*  Mode PORT_ALT0_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_ADC0_SE0_CMP0_IN0 |
PORT1_ADC0_SE1_CMP0_IN1 |
PORT6_ADC0_SE2 |
PORT7_ADC0_SE3 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          )
}
,
/*  Mode PORT_GPIO_MODE: */
{
/* Pads   0 ...  15 : PORT0_GPIO |
PORT1_GPIO |
PORT2_GPIO |
PORT3_GPIO |
PORT4_GPIO |
PORT5_GPIO |
PORT6_GPIO |
PORT7_GPIO |
PORT10_GPIO |
PORT11_GPIO |
PORT12_GPIO |
PORT13_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          )
}
,
/*  Mode PORT_ALT2_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT1_FTM1_CH1 |
PORT6_FTM0_FLT1 |
PORT7_FTM0_FLT2 |
PORT10_FTM1_CH4 |
PORT11_FTM1_CH5 |
PORT12_FTM1_CH6 |
PORT13_FTM1_CH7 |
PORT32_ADC0_SE4 |
PORT33_ADC0_SE5 |
PORT34_ADC0_SE6 |
PORT35_ADC0_SE7 |
PORT38_XTAL |
PORT39_EXTAL */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          )
}
,
/*  Mode PORT_ALT3_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPI2C0_SCLS |
PORT1_LPI2C0_SDAS |
PORT2_LPI2C0_SDA |
PORT3_LPI2C0_SCL |
PORT5_TCLK1 |
PORT6_LPSPI1_PCS1 |
PORT32_GPIO |
PORT33_GPIO |
PORT34_GPIO |
PORT35_GPIO |
PORT36_GPIO |
PORT37_GPIO |
PORT38_GPIO |
PORT39_GPIO |
PORT44_GPIO |
PORT45_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13)
          )
}
,
/*  Mode PORT_ALT4_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_FXIO_D2 |
PORT1_FXIO_D3 |
PORT4_CMP0_OUT |
PORT7_RTC_CLKIN |
PORT10_FXIO_D0 |
PORT11_FXIO_D1 |
PORT32_LPUART0_RX |
PORT33_LPUART0_TX |
PORT34_FTM1_CH0 |
PORT35_FTM1_CH1 |
PORT36_FTM0_CH4 |
PORT37_FTM0_CH5 |
PORT38_LPI2C0_SDA |
PORT39_LPI2C0_SCL |
PORT44_FTM0_CH0 |
PORT45_FTM0_CH1 |
PORT64_ADC0_SE8 |
PORT65_ADC0_SE9 |
PORT66_ADC0_SE10_CMP0_IN5 |
PORT67_ADC0_SE11_CMP0_IN4 |
PORT68_CMP0_IN2 |
PORT78_ADC0_SE12 |
PORT79_ADC0_SE13 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(12) |
            SHL_PAD_U16(13) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15)
          )
}
,
/*  Mode PORT_ALT5_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT1_FTM1_QD_PHA |
PORT2_FXIO_D4 |
PORT3_FXIO_D5 |
PORT11_CMP0_RRT |
PORT32_LPSPI0_PCS0 |
PORT33_LPSPI0_SOUT |
PORT34_LPSPI0_SCK |
PORT35_LPSPI0_SIN |
PORT36_LPSPI0_SOUT |
PORT37_LPSPI0_PCS1 |
PORT64_GPIO |
PORT65_GPIO |
PORT66_GPIO |
PORT67_GPIO |
PORT68_GPIO |
PORT69_GPIO |
PORT70_GPIO |
PORT71_GPIO |
PORT72_GPIO |
PORT73_GPIO |
PORT78_GPIO |
PORT79_GPIO |
PORT80_ADC0_SE14 |
PORT81_ADC0_SE15 */
  (uint16)( SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(11) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1)
          )
}
,
/*  Mode PORT_ALT6_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_LPUART0_CTS |
PORT1_LPUART0_RTS |
PORT2_LPUART0_RX |
PORT3_LPUART0_TX |
PORT6_LPUART1_CTS |
PORT7_LPUART1_RTS |
PORT32_LPTMR0_ALT3 |
PORT33_TCLK0 |
PORT34_FTM1_QD_PHB |
PORT35_FTM1_QD_PHA |
PORT37_LPSPI0_PCS0 |
PORT64_FTM0_CH0 |
PORT65_FTM0_CH1 |
PORT66_FTM0_CH2 |
PORT67_FTM0_CH3 |
PORT68_FTM1_CH0 |
PORT70_LPUART1_RX |
PORT71_LPUART1_TX |
PORT72_LPUART1_RX |
PORT73_LPUART1_TX |
PORT78_FTM1_CH2 |
PORT79_FTM1_CH3 |
PORT80_GPIO |
PORT81_GPIO |
PORT102_CMP0_IN7 |
PORT103_CMP0_IN6 */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(14) |
            SHL_PAD_U16(15) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7)
          )
}
,
/*  Mode PORT_ALT7_FUNC_MODE: */
{
/* Pads   0 ...  15 : PORT0_TRGMUX_OUT3 |
PORT1_TRGMUX_OUT0 |
PORT4_JTAG_TMS_SWD_DIO |
PORT5_RESET_b |
PORT10_JTAG_TDO |
PORT32_CAN0_RX |
PORT33_CAN0_TX |
PORT37_CLKOUT |
PORT66_CAN0_RX |
PORT67_CAN0_TX |
PORT68_RTC_CLKOUT |
PORT69_RTC_CLKOUT |
PORT72_FTM1_FLT0 |
PORT73_FTM1_FLT1 |
PORT80_FTM1_FLT2 |
PORT81_FTM1_FLT3 |
PORT96_GPIO |
PORT97_GPIO |
PORT98_GPIO |
PORT99_GPIO |
PORT100_GPIO |
PORT101_GPIO |
PORT102_GPIO |
PORT103_GPIO |
PORT111_GPIO */
  (uint16)( SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(10) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(8) |
            SHL_PAD_U16(9) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(0) |
            SHL_PAD_U16(1) |
            SHL_PAD_U16(2) |
            SHL_PAD_U16(3) |
            SHL_PAD_U16(4) |
            SHL_PAD_U16(5) |
            SHL_PAD_U16(6) |
            SHL_PAD_U16(7) |
            SHL_PAD_U16(15)
          )
}

[!ENDVAR!]



[!ENDIF!][!//avoid multiple inclusion
