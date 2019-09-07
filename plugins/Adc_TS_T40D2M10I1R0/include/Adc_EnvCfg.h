/**
*   @file    Adc_EnvCfg.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Adc - contains the configuration data of the sADC driver
*   @details contains the configuration data of the sADC driver
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : ADC12BSARV2
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

#ifndef ADC_ENVCFG_H
#define ADC_ENVCFG_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_EnvCfg_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, 
* The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
*
* @section Adc_EnvCfg_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, 
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**  @violates @ref Adc_EnvCfg_h_REF_2 Repeated include file */
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_EnvCfg.h
*/
#define ADC_VENDOR_ID_ENVCFG                    43
#define ADC_AR_RELEASE_MAJOR_VERSION_ENVCFG     4
#define ADC_AR_RELEASE_MINOR_VERSION_ENVCFG     2
/** @violates @ref Adc_EnvCfg_h_REF_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_ENVCFG  2
#define ADC_SW_MAJOR_VERSION_ENVCFG             1
#define ADC_SW_MINOR_VERSION_ENVCFG             0
#define ADC_SW_PATCH_VERSION_ENVCFG             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
* @file           Adc_EnvCfg.h
*/
/** @violates @ref Adc_EnvCfg_h_REF_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Std_Types.h file and Adc_EnvCfg header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ENVCFG != STD_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ENVCFG != STD_AR_RELEASE_MINOR_VERSION)    \
    )
    #error "AutoSar Version Numbers of Adc_EnvCfg.h and Std_Types.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define ADC_QM      (STD_OFF)
#define ADC_FTE     (STD_ON)
#define ADC_GTE     (STD_OFF)
#define ADC_NTE     (STD_OFF)

#define ADC_PERIODIC_CHECK                   (ADC_FTE)
#define ADC_REGISTER_PROTECTION              (ADC_FTE)
#define ADC_HARDWARE_MONITORING              (ADC_FTE)

#define ADC_VALIDATE_GLOBAL_CALL         (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_CALL_AND_GROUP      (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_CALL_AND_UNIT       (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_PARAMS              (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_STATE               (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_NOTIFY_CAPABILITY   (ADC_DEV_ERROR_DETECT)
#define ADC_VALIDATE_THRESHOLD_VALUE     (ADC_DEV_ERROR_DETECT)

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

#endif /* ADC_ENVCFG_H */

/** @} */
