/**
*   @file    Reg_eSys_Wdog_defines.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - Register WDOG masks.
*   @details Contains the masks for WDOG registers
*
*   @addtogroup Wdg
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

#ifndef REG_E_SYS_WDOG_DEFINES_H
#define REG_E_SYS_WDOG_DEFINES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations

* @section Reg_eSys_Wdog_defines_h_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
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


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_WDOG_defines.h
*/
#define REG_ESYS_WDOG_DEFINES_VENDOR_ID                    43
#define REG_ESYS_WDOG_DEFINES_MODULE_ID                    102
#define REG_ESYS_WDOG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
/** @violates @ref Reg_eSys_Wdog_defines_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *            that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_WDOG_DEFINES_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref Reg_eSys_Wdog_defines_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *            that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_WDOG_DEFINES_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_WDOG_DEFINES_SW_MAJOR_VERSION             1
#define REG_ESYS_WDOG_DEFINES_SW_MINOR_VERSION             0
#define REG_ESYS_WDOG_DEFINES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief WDOG_CS register
*/

/**
* @brief This constant specifies the value of the WDOG_CS's register Wdg enable bit EN if disabled
*/
#define WDOG_ENABLED_U32                     (0x00000080UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register reserved bit 13
*/
#define WDOG_RESERVED_BIT13_U32              (0x00002000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's Wdg enable bit EN if disabled
*/
#define WDOG_DISABLED_U32                    (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's debug mode control bit DBG if enabled
*/
#define WDOG_STOP_IN_DEBUG_U32               (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's debug mode control bit DBG if disabled
*/
#define WDOG_RUN_IN_DEBUG_U32                (0x00000040UL)

/**
* @brief This constant specifies the value of the WDOG_CS's stop mode control bit STOP if enabled
*/
#define WDOG_STOP_IN_HALT_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's stop mode control bit STOP if disabled
*/
#define WDOG_RUN_IN_HALT_U32                 (0x00000001UL)

/**
* @brief This constant specifies the value of the WDOG_CS's mode control bit WAIT if enabled
*/
#define WDOG_STOP_IN_WAIT_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's  mode control bit WAIT if disabled
*/
#define WDOG_RUN_IN_WAIT_U32                 (0x00000002UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if bus clk selected
*/
#define WDOG_BUS_CLK_U32                      (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if lpo clk selected
*/
#define WDOG_LPO_CLK_U32                      (0x00000100UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if sosc selected
*/
#define WDOG_SOSC_CLK_U32                     (0x00000200UL)

/**
* @brief This constant specifies the value of the WDOG_CS's clock selection bit CLK if sirc selected
*/
#define WDOG_SIRC_CLK_U32                     (0x00000300UL)

/**
* @brief This constant specifies the value of the WDOG_CS's interrupt bit INT if enabled
*/
#define WDOG_INTERRUPT_ENABLED_U32                (0x00000040UL)

/**
* @brief This constant specifies the value of the WDOG_CS's interrupt bit INT if disabled
*/
#define WDOG_INTERRUPT_DISABLED_U32               (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's window mode bit WIN if enabled
*/
#define WDOG_TRIGGER_MODE_WINDOW_U32             (0x00008000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's window mode bit WIN if disabled
*/
#define WDOG_TRIGGER_MODE_REGULAR_U32            (0x00000000UL)

/**
* @brief  This constant specifies the value that clears the flag FLG of WDOG_CS register.
*/
#define WDOG_CLEAR_INT_FLAG_U32                  (0x00004000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register prescaler enable bit PRES if enabled
*/
#define WDOG_PRES_ENABLED_U32                (0x00001000UL)
/**
* @brief This constant specifies the value of the WDOG_CS's prescaler enable bit PRES if disabled
*/
#define WDOG_PRES_DISABLED_U32               (0x00000000UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register UPDATE bit if update is allowed
*/
#define WDOG_UPDATE_ENABLED_U32              (0x00000020UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register UPDATE bit if update is not allowed
*/
#define WDOG_UPDATE_DISABLED_U32             (0x00000000UL)

/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if the test mode is disabled
*/
#define WDOG_TEST_MODE_DISABLED_U32          (0x00000000UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if user mode selected
*/
#define WDOG_USER_MODE_ENABLED_U32           (0x00000008UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if the test mode is low
*/
#define WDOG_TEST_MODE_LOW_U32               (0x00000010UL)
/**
* @brief This constant specifies the value of the WDOG_CS's register TST bit if the test mode is high
*/
#define WDOG_TEST_MODE_HIGH_U32               (0x00000018UL)


/**
* @brief  This variable will indicate the Wdg Prescaler value
*/
#define WDG_PRESCALER_VALUE_U16  ((uint16)256)

/**
* @brief  This variable will indicate the init value for the timeout and window period
*/
#define WDG_TICKS_INIT_VAL_U16   ((uint16)0)
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

#endif /*REG_E_SYS_WDOG_DEFINES_H*/

/** @} */
