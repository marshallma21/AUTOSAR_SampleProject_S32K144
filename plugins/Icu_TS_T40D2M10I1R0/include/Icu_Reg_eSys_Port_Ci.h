/**
*   @file Icu_Reg_eSys_Port_Ci.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Icu - PORT_CI low level driver register defines.
*   @details The description of the registers of the PORT_CI module.
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


#ifndef ICU_REG_ESYS_PORT_CI_H
#define ICU_REG_ESYS_PORT_CI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Reg_eSys_PORT_CI_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* @section Icu_Reg_eSys_PORT_CI_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to IP functions.
* @section Icu_Reg_eSys_PORT_CI_h_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
* @section Icu_Reg_eSys_PORT_CI_h_REF_4
*          Violates MISRA 2004 Required Rule 8.12, When an array is declared with external linkage,
*          its size shall be stated explicitly or defined implicitly by initialisation.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_REGESYS_PORT_CI_VENDOR_ID                    43
/* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION     4
/* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_3 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION  2
#define ICU_REGESYS_PORT_CI_SW_MAJOR_VERSION             1
#define ICU_REGESYS_PORT_CI_SW_MINOR_VERSION             0
#define ICU_REGESYS_PORT_CI_SW_PATCH_VERSION             1

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/

#if (ICU_REGESYS_PORT_CI_VENDOR_ID != REG_ESYS_VENDOR_ID)
    #error "Icu_Reg_eSys_Port_Ci.h and Reg_eSys.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Reg_eSys_Port_Ci header file are of the same Autosar version */
#if ((ICU_REGESYS_PORT_CI_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_REGESYS_PORT_CI_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) || \
     (ICU_REGESYS_PORT_CI_AR_RELEASE_REVISION_VERSION != REG_ESYS_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Reg_eSys_Port_Ci.h and Reg_eSys.h are different"
#endif
/* Check if header file and Icu_Reg_eSys_Port_Ci header file are of the same software version */
#if ((ICU_REGESYS_PORT_CI_SW_MAJOR_VERSION != REG_ESYS_SW_MAJOR_VERSION) || \
     (ICU_REGESYS_PORT_CI_SW_MINOR_VERSION != REG_ESYS_SW_MINOR_VERSION) || \
     (ICU_REGESYS_PORT_CI_SW_PATCH_VERSION != REG_ESYS_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Reg_eSys_Port_Ci.h and Reg_eSys.h are different"
#endif

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ICU_START_SEC_CONST_32
/*
* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"
/**
* @brief PIT base address array declaration
*/
/** @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_4 Array size not defined */
extern CONST(uint32, ICU_CONST) PORT_CI_BASE_ADDR32[];

#define ICU_STOP_SEC_CONST_32
/*
* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"
/*==================================================================================================
*                                  DEFINES AND MACROS
==================================================================================================*/

/* @brief Interrupt Status Flag Register address
 * @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_2 Function-like macro defined
 */
#define PORT_CI_ISFR_ADDR32(u8PortIdx)             (PORT_CI_BASE_ADDR32[(u8PortIdx)] + (uint32)0xA0UL)

/* @brief Pin Control Register address
 * @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_2 Function-like macro defined
 */
#define PORT_CI_PCR_ADDR32(u8PortIdx, u8PinIdx)    (PORT_CI_BASE_ADDR32[(u8PortIdx)] + (uint32)((u8PinIdx)<<(2UL)))

/* @brief Interrupt Digital Filter Enable Register address
 * @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_2 Function-like macro defined
 */
#define PORT_CI_DFER_ADDR32(u8PortIdx)         (PORT_CI_BASE_ADDR32[(u8PortIdx)] + (uint32)0xC0UL)

/* @brief Interrupt Digital Filter Clock Register address
 * @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_2 Function-like macro defined
 */
#define PORT_CI_DFCR_ADDR32(u8PortIdx)         (PORT_CI_BASE_ADDR32[(u8PortIdx)] + (uint32)0xC4UL)

/* @brief Interrupt Digital Filter Width Register address
 * @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_2 Function-like macro defined
 */
#define PORT_CI_DFWR_ADDR32(u8PortIdx)         (PORT_CI_BASE_ADDR32[(u8PortIdx)] + (uint32)0xC8UL)

/* @brief Maximum and Minimum Filter Length */
#define PORT_CI_DFWR_MAXFL_U32                          (0x0000001FUL)
#define PORT_CI_DFWR_MINFL_U32                          (0x00000000UL)


/* @brief DMA/Interrupt Status flag mask */
#define PORT_CI_PCR_ISF_U32                             (BIT24)
/* @brief DMA/Interrupt Request rising/falling/either edge masks */
#define PORT_CI_PCR_IREE_U32                            (BIT19|BIT16)
#define PORT_CI_PCR_IFEE_U32                            (BIT19|BIT17)
#define PORT_CI_PCR_IEEE_U32                            (BIT19|BIT17|BIT16)
/* @brief Disable all DMA/Interrupt mask */
#define PORT_CI_PCR_IRQC_U32                            (BIT19|BIT18|BIT17|BIT16)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ICU_START_SEC_CONST_32
/*
* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"
/**
* @brief PIT base address array declaration
*/
/** @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_4 Array size not defined */
extern CONST(uint32, ICU_CONST) PORT_CI_BASE_ADDR32[];

#define ICU_STOP_SEC_CONST_32
/*
* @violates @ref Icu_Reg_eSys_PORT_CI_h_REF_1 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "Icu_MemMap.h"

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/* ICU_REG_ESYS_PORT_CI_H */
#endif
/** @} */
