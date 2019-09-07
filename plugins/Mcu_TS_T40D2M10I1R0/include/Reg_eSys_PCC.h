/**
*   @file    Reg_eSys_PCC.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : MC
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_HF1_ASR_REL_4_2_REV_0002_20180723
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef REG_ESYS_PCC_H
#define REG_ESYS_PCC_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_PCC_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_PCC_VENDOR_ID                       43
#define REG_ESYS_PCC_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_PCC_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_PCC_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_PCC_SW_MAJOR_VERSION                1
#define REG_ESYS_PCC_SW_MINOR_VERSION                0
#define REG_ESYS_PCC_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_PCC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_PCC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_PCC.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/********** PCC Registers **********/

/* PCC_FTFC */
#define PCC_FTFC_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x00000080U))
/* PCC_DMAMUX0 */
#define PCC_DMAMUX0_ADDR32                  ((uint32)(PCC_BASEADDR + (uint32)0x00000084U))
/* PCC_FLEXCAN0 */
#define PCC_FLEXCAN0_ADDR32                 ((uint32)(PCC_BASEADDR + (uint32)0x00000090U))
/* PCC_FLEXCAN1 */
#define PCC_FLEXCAN1_ADDR32                 ((uint32)(PCC_BASEADDR + (uint32)0x00000094U))
/* PCC_FLEXTMR3 */
#define PCC_FTM3_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x00000098U))
/* PCC_ADC1 */
#define PCC_ADC1_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x0000009CU))
/* PCC_FLEXCAN2 */
#define PCC_FLEXCAN2_ADDR32                 ((uint32)(PCC_BASEADDR + (uint32)0x000000ACU))
/* PCC_LPSPI0 */
#define PCC_LPSPI0_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x000000B0U))
/* PCC_LPSPI1 */
#define PCC_LPSPI1_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x000000B4U))
/* PCC_LPSPI2 */
#define PCC_LPSPI2_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x000000B8U))
/* PCC_PDB1 */
#define PCC_PDB1_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000C4U))
/* PCC_CRC */
#define PCC_CRC_ADDR32                      ((uint32)(PCC_BASEADDR + (uint32)0x000000C8U))
/* PCC_PDB0 */
#define PCC_PDB0_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000D8U))
/* PCC_LPIT0 */
#define PCC_LPIT_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000DCU))
/* PCC_FLEXTMR0 */
#define PCC_FTM0_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000E0U))
/* PCC_FLEXTMR1 */
#define PCC_FTM1_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000E4U))
/* PCC_FLEXTMR2 */
#define PCC_FTM2_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000E8U))
/* PCC_ADC0 */
#define PCC_ADC0_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000ECU))
/* PCC_RTC */
#define PCC_RTC_ADDR32                      ((uint32)(PCC_BASEADDR + (uint32)0x000000F4U))
/* PCC_LPTMR0 */
#define PCC_LPTMR0_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x00000100U))
/* PCC_PORTA */
#define PCC_PORTA_ADDR32                    ((uint32)(PCC_BASEADDR + (uint32)0x00000124U))
/* PCC_PORTB */
#define PCC_PORTB_ADDR32                    ((uint32)(PCC_BASEADDR + (uint32)0x0000128U))
/* PCC_PORTC */
#define PCC_PORTC_ADDR32                    ((uint32)(PCC_BASEADDR + (uint32)0x0000012CU))
/* PCC_PORTD */
#define PCC_PORTD_ADDR32                    ((uint32)(PCC_BASEADDR + (uint32)0x00000130U))
/* PCC_PORTE */
#define PCC_PORTE_ADDR32                    ((uint32)(PCC_BASEADDR + (uint32)0x00000134U))
/* PCC_SAI0 */
#define PCC_SAI0_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x00000150U))
/* PCC_SAI1 */
#define PCC_SAI1_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x00000154U))
/* PCC_FLEXIO */
#define PCC_FLEXIO_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x00000168U))
/* PCC_EWM */
#define PCC_EWM_ADDR32                      ((uint32)(PCC_BASEADDR + (uint32)0x00000184U))
/* PCC_LPI2C0 */
#define PCC_LPI2C0_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x00000198U))
/* PCC_LPI2C1 */
#define PCC_LPI2C1_ADDR32                   ((uint32)(PCC_BASEADDR + (uint32)0x0000019CU))
/* PCC_LPUART0 */
#define PCC_LPUART0_ADDR32                  ((uint32)(PCC_BASEADDR + (uint32)0x000001A8U))
/* PCC_LPUART1 */
#define PCC_LPUART1_ADDR32                  ((uint32)(PCC_BASEADDR + (uint32)0x000001ACU))
/* PCC_LPUART2 */
#define PCC_LPUART2_ADDR32                  ((uint32)(PCC_BASEADDR + (uint32)0x000001B0U))
/* PCC_FLEXTMR4 */
#define PCC_FTM4_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001B8U))
/* PCC_FLEXTMR5 */
#define PCC_FTM5_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001BCU))
/* PCC_FLEXTMR6 */
#define PCC_FTM6_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001C0U))
/* PCC_FLEXTMR7 */
#define PCC_FTM7_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001C4U))
/* PCC_CMP0 */
#define PCC_CMP0_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001CCU))
/* PCC_QSPI */
#define PCC_QSPI_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001D8U))
/* PCC_ENET */
#define PCC_ENET_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000001E4U))
/* PCC_CMU0 */
#define PCC_CMU0_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000F8U))
/* PCC_CMU1 */
#define PCC_CMU1_ADDR32                     ((uint32)(PCC_BASEADDR + (uint32)0x000000FCU))

#define PCC_FTFC_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_DMAMUX0_RWBITS_MASK32                  ((uint32)0x40000000U)
#define PCC_FLEXCAN0_RWBITS_MASK32                 ((uint32)0x40000000U)
#define PCC_FLEXCAN1_RWBITS_MASK32                 ((uint32)0x40000000U)
#define PCC_FTM3_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_ADC1_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FLEXCAN2_RWBITS_MASK32                 ((uint32)0x40000000U)
#define PCC_LPSPI0_RWBITS_MASK32                   ((uint32)0x47000000U)
#define PCC_LPSPI1_RWBITS_MASK32                   ((uint32)0x47000000U)
#define PCC_LPSPI2_RWBITS_MASK32                   ((uint32)0x47000000U)
#define PCC_PDB1_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_CRC_RWBITS_MASK32                      ((uint32)0x40000000U)
#define PCC_PDB0_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_LPIT_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FTM0_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FTM1_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FTM2_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_ADC0_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_RTC_RWBITS_MASK32                      ((uint32)0x40000000U)
#define PCC_LPTMR0_RWBITS_MASK32                   ((uint32)0x4700000FU)
#define PCC_PORTA_RWBITS_MASK32                    ((uint32)0x40000000U)
#define PCC_PORTB_RWBITS_MASK32                    ((uint32)0x40000000U)
#define PCC_PORTC_RWBITS_MASK32                    ((uint32)0x40000000U)
#define PCC_PORTD_RWBITS_MASK32                    ((uint32)0x40000000U)
#define PCC_PORTE_RWBITS_MASK32                    ((uint32)0x40000000U)
#define PCC_SAI0_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_SAI1_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_FLEXIO_RWBITS_MASK32                   ((uint32)0x47000000U)
#define PCC_EWM_RWBITS_MASK32                      ((uint32)0x40000000U)
#define PCC_LPI2C0_RWBITS_MASK32                   ((uint32)0x47000000U)
#define PCC_LPI2C1_RWBITS_MASK32                   ((uint32)0x47000000U)
#define PCC_LPUART0_RWBITS_MASK32                  ((uint32)0x47000000U)
#define PCC_LPUART1_RWBITS_MASK32                  ((uint32)0x47000000U)
#define PCC_LPUART2_RWBITS_MASK32                  ((uint32)0x47000000U)
#define PCC_FTM4_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FTM5_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FTM6_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_FTM7_RWBITS_MASK32                     ((uint32)0x47000000U)
#define PCC_CMP0_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_QSPI_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_ENET_RWBITS_MASK32                     ((uint32)0x4700000FU)
#define PCC_CMU0_RWBITS_MASK32                     ((uint32)0x40000000U)
#define PCC_CMU1_RWBITS_MASK32                     ((uint32)0x40000000U)

#define PCC_PR_MASK32                              ((uint32)0x80000000U)
#define PCC_CGC_MASK32                             ((uint32)0x40000000U)
#define PCC_INUSE_MASK32                           ((uint32)0x20000000U)
#define PCC_PCS_MASK32                             ((uint32)0x07000000U)
#define PCC_FRAC_MASK32                            ((uint32)0x00000008U)
#define PCC_PCD_MASK32                             ((uint32)0x00000007U)

#define PCC_PERIPHERAL_IS_PRESENT_U32              (PCC_PR_MASK32)
#define PCC_PERIPHERAL_IS_NOT_PRESENT_U32          ((uint32)0x00000000U)
       
#define PCC_CLOCK_ENABLED_U32                      (PCC_CGC_MASK32)
#define PCC_CLOCK_DISABLED_U32                     ((uint32)0x00000000U)
       
#define PCC_PERIPHERAL_IN_USE_U32                  (PCC_INUSE_MASK32)
#define PCC_PERIPHERAL_NOT_IN_USE_U32              ((uint32)0x00000000U)
       
#define PCC_FRAC_0_U32                             ((uint32)0x00000000U)
#define PCC_FRAC_1_U32                             ((uint32)PCC_FRAC_MASK32)

/** @violates @ref Reg_eSys_PCC_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macros are used for register operations to improve readability.*/
#define PCC_PCD_U32(value)                         (((value) & PCC_PCD_MASK32))

#define PCC_PCS_EXT_CLK_OR_CLK_OFF_U32             ((uint32)0x00000000U)
#define PCC_PCS_SOSC_U32                           ((uint32)0x01000000U)
#define PCC_PCS_SIRC_U32                           ((uint32)0x02000000U)
#define PCC_PCS_FIRC_U32                           ((uint32)0x03000000U)
#define PCC_PCS_SPLL_U32                           ((uint32)0x06000000U)
#define PCC_PCS_UNAVAILABLE_U32                    (PCC_PCS_MASK32)

/*==================================================================================================
*                                             ENUMS
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



#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_PCC_H */

/** @} */
