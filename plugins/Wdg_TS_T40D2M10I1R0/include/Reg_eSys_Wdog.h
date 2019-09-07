/**
*   @file    Reg_eSys_Wdog.h
*
*   @version 1.0.1
*   @brief   AUTOSAR Wdg - Watchdog Timer (WDOG) Registers
*   @details Contains information about the WDOG's registers
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Wdog
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

#ifndef REG_ESYS_WDOG_H
#define REG_ESYS_WDOG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_Wdog_h_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
*
* @section Reg_eSys_Wdog_h_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Reg_eSys_Wdog_h_REF_3
*          Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*          This violation is due to function like macro defined for register operations.
*          Function like macro are used to reduce code complexity.
* @section Reg_eSys_Wdog_h_REF_4
*          Violates MISRA 2004 Required Rule 8.12, Array size not defined.
*          WDOG_BASE_ADDR16 size is different base on configuration. 
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
/**
* @brief Include Memory mapping specification
* @violates @ref Reg_eSys_Wdog_h_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice*/
#include "Reg_eSys.h"
/**
* @file           Reg_eSys_Wdog.h    
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the driver header file and also in the 
* module's description file
*/
#define REG_ESYS_WDOG_VENDOR_ID                      43
/** @violates @ref Reg_eSys_Wdog_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_WDOG_AR_RELEASE_MAJOR_VERSION       4
/** @violates @ref Reg_eSys_Wdog_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_WDOG_AR_RELEASE_MINOR_VERSION       2
/** @violates @ref Reg_eSys_Wdog_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_WDOG_AR_RELEASE_REVISION_VERSION    2
#define REG_ESYS_WDOG_SW_MAJOR_VERSION               1
#define REG_ESYS_WDOG_SW_MINOR_VERSION               0
#define REG_ESYS_WDOG_SW_PATCH_VERSION               1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_WDOG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_WDOG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Wdog.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Reg_eSys_Wdog_h_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice*/
#include "Wdg_MemMap.h"
/** @violates @ref Reg_eSys_Wdog_h_REF_4 Array size not defined */
extern CONST(uint32, WDG_CONST) WDOG_aBASE_ADDR32[];
#define WDG_STOP_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Reg_eSys_Wdog_h_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief This constant specifies the Watchdog Control and Status Register
* @violates @ref Reg_eSys_Wdog_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_CS_ADDR32(u8ModuleIdx)         (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x00UL)

/**
* @brief This constant specifies the Watchdog Counter Register
* @violates @ref Reg_eSys_Wdog_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_CNT_ADDR32(u8ModuleIdx)        (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x04UL)

/**
* @brief This constant specifies the Watchdog Timeout Value Register
* @violates @ref Reg_eSys_Wdog_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_TOVAL_ADDR32(u8ModuleIdx)      (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x08UL)

/**
* @brief This constant specifies the Watchdog Window Register
* @violates @ref Reg_eSys_Wdog_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define WDOG_WIN_ADDR32(u8ModuleIdx)        (WDOG_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0CUL)

/**
* @brief This constant specifies the value of the unlock sequence
*/
#define WDOG_UNLOCK_SEQ_U32                  ((uint32)0xD928C520UL)
/**
* @brief This constant specifies the value of the sequence needed to refresh the watchdog
*/
#define WDOG_TRIGGER_SEQUENCE_U32            ((uint32)0xB480A602UL)
/**
* @brief This constant specifies the minimum value that will be set in the WDOG timeout register
*/
#define WDOG_MIN_VALUE_TIMEOUT_U32           ((uint32)0x100)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif  /* REG_ESYS_WDOG_H */

/** @} */
