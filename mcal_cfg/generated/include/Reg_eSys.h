/**
*   @file    Reg_eSys.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Base - BIP Memory and DMA mapping.
*   @details Memory mapping of the IP modules and DMA channels present on the S32K14X 
*            hardware platform.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : S32K14X
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

/** 
* @page misra_violations MISRA-C:2004 violations
* 
* @section Reg_eSys_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file 
* This comes from the order of includes in the .c file and from include dependencies. As a safe 
* approach, any file must include all its dependencies. Header files are already protected against 
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*/

#ifndef REG_ESYS_H
#define REG_ESYS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** 
* @file        Reg_eSys.h
* @brief Include platform types
* @violates @ref Reg_eSys_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Platform_Types.h"

/** 
* @file        Reg_eSys.h
* @brief Include IP module versions
*/
#include "Soc_Ips.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REG_ESYS_VENDOR_ID                    43
#define REG_ESYS_MODULE_ID                    0
#define REG_ESYS_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_AR_RELEASE_MINOR_VERSION     2
#define REG_ESYS_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_SW_MAJOR_VERSION             1
#define REG_ESYS_SW_MINOR_VERSION             0
#define REG_ESYS_SW_PATCH_VERSION             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys.h and Platform_Types.h are different"
    #endif
#endif

/* Check if source file and Soc_Ips.h header file have same versions */
#if (REG_ESYS_VENDOR_ID != SOC_IPS_VENDOR_ID)
#error "Reg_eSys.h and Soc_Ips.h have different vendor IDs"
#endif
#if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_REVISION_VERSION != SOC_IPS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Reg_eSys.h and Soc_Ips.h are different"
#endif
#if ((REG_ESYS_SW_MAJOR_VERSION != SOC_IPS_SW_MAJOR_VERSION) || \
     (REG_ESYS_SW_MINOR_VERSION != SOC_IPS_SW_MINOR_VERSION) || \
     (REG_ESYS_SW_PATCH_VERSION != SOC_IPS_SW_PATCH_VERSION))
#error "Software Version Numbers of Reg_eSys.h and Soc_Ips.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
@brief  ADC0 (ADC_0)
@details S32K14X System Memory Map
*/
#define ADC0_BASEADDR              ((uint32)0x4003B000)
/**
@brief  ADC1 (ADC_1)
@details S32K14X System Memory Map
*/
#define ADC1_BASEADDR              ((uint32)0x40027000)
/**
@brief  AIPS (AIPS)
@details S32K14X System Memory Map
*/
#define AIPS_BASEADDR              ((uint32)0x40000000)

/**
@brief  FlexCAN 0(CAN0)
@details S32K14X System Memory Map
*/
#define FLEXCAN0_BASEADDR          ((uint32)0x40024000)
/**
@brief  FlexCAN 1(CAN1)
@details S32K14X System Memory Map
*/
#define FLEXCAN1_BASEADDR          ((uint32)0x40025000)
/**
@brief  FlexCAN 2(CAN2)
@details S32K14X System Memory Map
*/
#define FLEXCAN2_BASEADDR          ((uint32)0x4002B000)
/**
@brief  CMP (CMP0)
@details S32K14X System Memory Map
*/
#define CMP0_BASEADDR              ((uint32)0x40073000)
/**
@brief  CRC (CRC)
@details S32K14X System Memory Map
*/
#define CRC_BASEADDR               ((uint32)0x40032000)
/**
@brief  DMA (DMA)
@details S32K14X System Memory Map
*/
#define DMA_BASEADDR               ((uint32)0x40008000)
/**
@brief  DMAMUX (DMAMUX)
@details S32K14X System Memory Map
*/
#define DMAMUX0_BASEADDR            ((uint32)0x40021000)
/**
@brief  EWM (EWM0)
@details S32K14X System Memory Map
*/
#define EWM_BASEADDR               ((uint32)0x40061000)

/**
@brief  EIM (EIM)
@details S32K14X System Memory Map
*/
#define EIM_BASEADDR               ((uint32)0x40019000)

/**
@brief  ERM (ERM)
@details S32K14X System Memory Map
*/
#define ERM_BASEADDR               ((uint32)0x40018000)

/**
@brief  ENET (ENET)
@details S32K14X System Memory Map
*/
#define ENET_0_BASEADDR               ((uint32)0x40079000)

/**
@brief  FLEXIO (FLEXIO)
@details S32K14X System Memory Map
*/
#define FLEXIO_BASEADDR            ((uint32)0x4005A000)

/**
@brief  FLEXRAM (FLEXRAM)
@details S32K14X System Memory Map
*/
#define FLEXRAM_BASEADDR           ((uint32)0x14000000)


/**
@brief  FTFE (FTFE0)
@details S32K14X System Memory Map
*/
#define FTFE_BASEADDR              ((uint32)0x40020000)
/**
@brief  FTM (FTM0)
@details S32K14X System Memory Map
*/
#define FTM_0_BASEADDR              ((uint32)0x40038000)
#define FTM_1_BASEADDR              ((uint32)0x40039000)
#define FTM_2_BASEADDR              ((uint32)0x4003A000)
#define FTM_3_BASEADDR              ((uint32)0x40026000)
#define FTM_4_BASEADDR              ((uint32)0x4006E000)
#define FTM_5_BASEADDR              ((uint32)0x4006F000)
#define FTM_6_BASEADDR              ((uint32)0x40070000)
#define FTM_7_BASEADDR              ((uint32)0x40071000)
/**
@brief  GPIO 
@details S32K14X System Memory Map
*/
#define GPIO_BASEADDR              ((uint32)0x400FF000)
/**
@brief  LMEM
@details S32K14X System Memory Map
*/
#define LMEM_BASEADDR              ((uint32)0xE0082000U)
/**
@brief  LPI2C
@details S32K14X System Memory Map
*/
#define LPI2C0_BASEADDR            ((uint32)0x40066000)
#define LPI2C1_BASEADDR            ((uint32)0x40067000)
/**
@brief  LPIT 
@details S32K14X System Memory Map
*/
#define LPIT0_BASEADDR             ((uint32)0x40037000)
/**
@brief  LPSPI 
@details S32K14X System Memory Map
*/
#define LPSPI0_BASEADDR            ((uint32)0x4002C000)
#define LPSPI1_BASEADDR            ((uint32)0x4002D000)
#define LPSPI2_BASEADDR            ((uint32)0x4002E000)
/**
@brief  LPTMR (LPTMR0)
@details S32K14X System Memory Map
*/
#define LPTMR0_BASEADDR            ((uint32)0x40040000)
/**
@brief  LPUART
@details S32K14X System Memory Map
*/
#define LPUART0_BASEADDR           ((uint32)0x4006A000)
#define LPUART1_BASEADDR           ((uint32)0x4006B000)
#define LPUART2_BASEADDR           ((uint32)0x4006C000)
#define LPUART3_BASEADDR           ((uint32)0x4006D000)
/**
@brief  MCM
@details S32K14X System Memory Map
*/
#define MCM_BASEADDR               ((uint32)0xE0080000U)
/**
@brief  MPU
@details S32K14X System Memory Map
*/
#define MPU_BASEADDR               ((uint32)0x4000D000)
/**
@brief  MSCM 
@details S32K14X System Memory Map
*/
#define MSCM_BASEADDR              ((uint32)0x40001000)
/**
@brief  OSC (OSC32)
@details S32K14X System Memory Map
*/
#define OSC32_BASEADDR             ((uint32)0x40060000)
/**
@brief  PCC (PCC)
@details S32K14X System Memory Map
*/
#define PCC_BASEADDR               ((uint32)0x40065000)
/**
@brief  PDB
@details S32K14X System Memory Map
*/
#define PDB0_BASEADDR              ((uint32)0x40036000)
#define PDB1_BASEADDR              ((uint32)0x40031000)
/**
@brief  PMC
@details S32K14X System Memory Map
*/
#define PMC_BASEADDR               ((uint32)0x4007D000)
/**
@brief   PORT
@details S32K14X System Memory Map
*/
#define PORT_BASEADDR              ((uint32)0x40049000)

/**
@brief  PORTA_MULTIPLEX (Port A multiplexing control)
@details S32K14X System Memory Map
*/
#define PORTA_MULTIPLEX_BASEADDR                ((uint32)0x40049000U)

/**
@brief  PORTB_MULTIPLEX (Port B multiplexing control)
@details S32K14X System Memory Map
*/
#define PORTB_MULTIPLEX_BASEADDR                ((uint32)0x4004A000U)

/**
@brief  PORTC_MULTIPLEX (Port C multiplexing control)
@details S32K14X System Memory Map
*/
#define PORTC_MULTIPLEX_BASEADDR                ((uint32)0x4004B000U)

/**
@brief  PORTD_MULTIPLEX (Port D multiplexing control)
@details S32K14X System Memory Map
*/
#define PORTD_MULTIPLEX_BASEADDR                ((uint32)0x4004C000U)

/**
@brief  PORTE_MULTIPLEX (Port E multiplexing control)
@details S32K14X System Memory Map
*/
#define PORTE_MULTIPLEX_BASEADDR                ((uint32)0x4004D000U)

/**
@brief  PRAM (PRAM)
@details S32K14X System Memory Map
*/
#define PRAM_BASEADDR                ((uint32)0x14001000)


/**
@brief  QSPI (QSPI
@details S32K14X System Memory Map
*/
#define QSPI_0_BASEADDR              ((uint32)0x40076000)

/**
@brief  RCM 
@details S32K14X System Memory Map
*/
#define RCM_BASEADDR               ((uint32)0x4007F000)
/**
@brief  RTC 
@details S32K14X System Memory Map
*/
#define RTC_BASEADDR               ((uint32)0x4003D000)
/**
@brief  SGC
@details S32K14X System Memory Map
*/
#define SCG_BASEADDR               ((uint32)0x40064000)
/**
@brief  SAI
@details S32K14X System Memory Map
*/
#define SAI_0_BASEADDR               ((uint32)0x40054000)
#define SAI_1_BASEADDR               ((uint32)0x40055000)

/**
@brief  SIM
@details S32K14X System Memory Map
*/
#define SIM_BASEADDR               ((uint32)0x40048000)
/**
@brief  SMC
@details S32K14X System Memory Map
*/
#define SMC_BASEADDR               ((uint32)0x4007E000)
/**
@brief  TRGMUX 
@details S32K14X System Memory Map
*/
#define TRGMUX_BASEADDR            ((uint32)0x40063000)
/**
@brief  WDG
@details S32K14X System Memory Map
*/
#define WDOG_BASEADDR              ((uint32)0x40052000)
/**
@brief  CMU
@details S32K14X System Memory Map
*/
#define CMU0_BASEADDR              ((uint32)0x4003E000)
#define CMU1_BASEADDR              ((uint32)0x4003F000)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef REG_ESYS_H*/

/** @} */
