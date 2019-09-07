/**
*   @file    Mcem_Eirm_Types.h
*   @implements     Mcem_Eirm_Types.h_Artifact
*
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcem - MEMU IP Types 
*   @details Internal types used in the MEMU IP layer of the MCEM module.
*
*   @addtogroup MCEM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Eim Erm
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

#ifndef MCEM_EIRM_TYPES_H
#define MCEM_EIRM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
 *
 * @page misra_violations MISRA-C:2004 violations
 * 
 * @section Mcem_Eirm_Types_h_REF_1
 * Violates MISRA 2004 Required Rule 5.1, Exceeds 31 characters due to AUTOSAR compatibility
 *
 * @section [global]
 * Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions shall
 * not be reused. Ipv name start with letter E which is reserved for Error status. However, EIRM is unique. 
 *
 */


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define EIRM_TYPES_VENDOR_ID                    43
#define EIRM_TYPES_MODULE_ID                    0
#define EIRM_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define EIRM_TYPES_AR_RELEASE_MINOR_VERSION     2
#define EIRM_TYPES_AR_RELEASE_REVISION_VERSION  2
#define EIRM_TYPES_SW_MAJOR_VERSION             1
#define EIRM_TYPES_SW_MINOR_VERSION             0
#define EIRM_TYPES_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if ((EIRM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EIRM_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcem_EIRM_Types.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define     MCEM_EIRM_LOWER_MAX_U32         1U
#define     MCEM_EIRM_UPPER_MAX_U32         3U
#define     MCEM_EIRM_NO_ERR_BIT_U32        0X00000000U
#define     MCEM_EIRM_SINGLE_BIT_U32        0X00000001U
#define     MCEM_EIRM_MULTIPLE_BIT_U32      0X00000003U

#define     MCEM_EIRM_MEN0_SINGLE_CORRECTION_SHIFT_U8          31U
#define     MCEM_EIRM_MEN0_NON_CORRECTABLE_SHIFT_U8            30U
#define     MCEM_EIRM_MEN1_SINGLE_CORRECTION_SHIFT_U8          27U
#define     MCEM_EIRM_MEN1_NON_CORRECTABLE_SHIFT_U8            26U
#define     MCEM_EIRM_MAX_NO_FAULTS_U8      4U
#define     MCEM_EIRM_MAX_NO_FAULTS_M0_U8      2U

#define     EIRM_FAULT_REGISTER_COUNT_U8    1U

#define MCEM_EIM_CHECK_BIT_0_SHIFT_U8       25U
#define MCEM_EIM_CHECK_BIT_1_SHIFT_U8       26U
#define MCEM_EIM_CHECK_BIT_2_SHIFT_U8       27U
#define MCEM_EIM_CHECK_BIT_3_SHIFT_U8       28U
#define MCEM_EIM_CHECK_BIT_4_SHIFT_U8       29U
#define MCEM_EIM_CHECK_BIT_5_SHIFT_U8       30U
#define MCEM_EIM_CHECK_BIT_6_SHIFT_U8       31U
#define MCEM_EIM_DATA_BIT_0_SHIFT_U8        0U
#define MCEM_EIM_DATA_BIT_1_SHIFT_U8        1U
#define MCEM_EIM_DATA_BIT_2_SHIFT_U8        2U
#define MCEM_EIM_DATA_BIT_3_SHIFT_U8        3U
#define MCEM_EIM_DATA_BIT_4_SHIFT_U8        4U
#define MCEM_EIM_DATA_BIT_5_SHIFT_U8        5U
#define MCEM_EIM_DATA_BIT_6_SHIFT_U8        6U
#define MCEM_EIM_DATA_BIT_7_SHIFT_U8        7U
#define MCEM_EIM_DATA_BIT_8_SHIFT_U8        8U
#define MCEM_EIM_DATA_BIT_9_SHIFT_U8        9U
#define MCEM_EIM_DATA_BIT_10_SHIFT_U8       10U
#define MCEM_EIM_DATA_BIT_11_SHIFT_U8       11U
#define MCEM_EIM_DATA_BIT_12_SHIFT_U8       12U
#define MCEM_EIM_DATA_BIT_13_SHIFT_U8       13U
#define MCEM_EIM_DATA_BIT_14_SHIFT_U8       14U
#define MCEM_EIM_DATA_BIT_15_SHIFT_U8       15U
#define MCEM_EIM_DATA_BIT_16_SHIFT_U8       16U
#define MCEM_EIM_DATA_BIT_17_SHIFT_U8       17U
#define MCEM_EIM_DATA_BIT_18_SHIFT_U8       18U
#define MCEM_EIM_DATA_BIT_19_SHIFT_U8       19U
#define MCEM_EIM_DATA_BIT_20_SHIFT_U8       20U
#define MCEM_EIM_DATA_BIT_21_SHIFT_U8       21U
#define MCEM_EIM_DATA_BIT_22_SHIFT_U8       22U
#define MCEM_EIM_DATA_BIT_23_SHIFT_U8       23U
#define MCEM_EIM_DATA_BIT_24_SHIFT_U8       24U
#define MCEM_EIM_DATA_BIT_25_SHIFT_U8       25U
#define MCEM_EIM_DATA_BIT_26_SHIFT_U8       26U
#define MCEM_EIM_DATA_BIT_27_SHIFT_U8       27U
#define MCEM_EIM_DATA_BIT_28_SHIFT_U8       28U
#define MCEM_EIM_DATA_BIT_29_SHIFT_U8       29U
#define MCEM_EIM_DATA_BIT_30_SHIFT_U8       30U
#define MCEM_EIM_DATA_BIT_31_SHIFT_U8       31U
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief          The type of FaultID.
 *
 * @implements     Mcem_FaultType_typedef
 */
typedef uint8 Mcem_FaultType;
/**
 * @brief          The notification functions shall have one parameter and no return value.
 *
 */
typedef void (*Mcem_ErrorNotifyType)(Mcem_FaultType FaultID, uint32 u32FaultAddr);
/**
* @brief          Eirm configuration struct type
* @details        Ecc_Control value, resets all ECC event flags during Mcem_Init()
*/
typedef struct
{
  VAR(uint32, MCEM_VAR)                 Erm_ConfigReg;          /**< @brief EIRM_ERM configuration register */
  VAR(uint32, MCEM_VAR)                 Erm_IrqConfigReg;       /**< @brief EIRM_ERM configuration register */
  P2VAR(uint32, MCEM_VAR, MCEM_APPL)    M4_Tcm_Lower;           /**< @brief Lower address to inject fail CH0 */
  P2VAR(uint32, MCEM_VAR, MCEM_APPL)    M4_Tcm_upper;           /**< @brief Upper address to inject fail CH1 */
  VAR(uint32, MCEM_VAR)    Eim_SingleInjectWord0;        /**< @brief Value for inject data word 0 - check bits - single ECC */
  VAR(uint32, MCEM_VAR)    Eim_SingleInjectWord1;        /**< @brief Value for inject data word 1 - data bits - single ECC */
  VAR(uint32, MCEM_VAR)    Eim_DoubleInjectWord0;        /**< @brief Value for inject data word 0 - check bits - double error non-correctable */
  VAR(uint32, MCEM_VAR)    Eim_DoubleInjectWord1;        /**< @brief Value for inject data word 1 - data bits - double error non-correctable */
  CONST(Mcem_ErrorNotifyType, AUTOMATIC)     ErrorAddrNotifyApi;     /**< @brief MCEM Notification to notify Error Addr. */
} Mcem_Eirm_ConfigType;



/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*MCEM_EIRM_TYPES_H*/

/** @} */
