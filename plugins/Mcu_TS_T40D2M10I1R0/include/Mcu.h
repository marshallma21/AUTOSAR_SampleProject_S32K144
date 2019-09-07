/**
*   @file    Mcu.h
*   @implements Mcu.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Driver external interface.
*   @details Contains all the public functions and data types that are used by the higher layer.
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


#ifndef MCU_H
#define MCU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Mcu_h_REF_2
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @brief            Import all data types from lower layers that should be exported.
*                   Mcu.h shall include Mcu_Cfg.h for the API pre-compiler switches.
*
*/
#include "Mcu_Cfg.h"
#include "Mcu_EnvCfg.h"
#include "Mcu_IPW_Types.h"
#include "Mcal.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_VENDOR_ID                       43
#define MCU_AR_RELEASE_MAJOR_VERSION        4
#define MCU_AR_RELEASE_MINOR_VERSION        2
#define MCU_AR_RELEASE_REVISION_VERSION     2
#define MCU_SW_MAJOR_VERSION                1
#define MCU_SW_MINOR_VERSION                0
#define MCU_SW_PATCH_VERSION                1


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*
*/
/* Check if current file and MCU configuration header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu.h and Mcu_Cfg.h have different vendor ids"
#endif

/* Check if current file and MCU configuration header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION    != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION    != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and MCU configuration header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu.h and Mcu_Cfg.h are different"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu.h and Mcu_EnvCfg.h have different vendor ids"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION    != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION    != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu.h and Mcu_EnvCfg.h are different"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu.h and Mcu_EnvCfg.h are different"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same vendor */
#if (MCU_VENDOR_ID != MCU_IPW_TYPES_VENDOR_ID)
    #error "Mcu.h and Mcu_IPW_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION    != MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION    != MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION != MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu.h and Mcu_IPW_Types.h are different"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same software version */
#if ((MCU_SW_MAJOR_VERSION != MCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION != MCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION != MCU_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu.h and Mcu_IPW_Types.h are different"
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu.h and Mcal.h are different"
    #endif
#endif


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for
*                 configuration.
* @implements     Mcu_ConfigType_struct
*/
typedef struct
{
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /**< @brief DEM error reporting configuration. */
    P2CONST( Mcu_DemConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pDemConfig;
#endif
    /**< @brief Total number of RAM sections. */
    VAR( Mcu_RamSectionType, MCU_VAR) Mcu_NoRamConfigs;
    /**< @brief Total number of  MCU modes. */
    VAR( Mcu_ModeType, MCU_VAR) Mcu_NoModeConfigs;
#if (MCU_INIT_CLOCK == STD_ON)
    /**< @brief Total number of MCU clock configurations. */
    VAR( Mcu_ClockType, MCU_VAR) Mcu_NoClkConfigs;
#endif /* (MCU_INIT_CLOCK == STD_ON) */
#ifndef MCU_MAX_NORAMCONFIGS
    /**< @brief RAM data configuration. */
    CONST( Mcu_RamConfigType, MCU_CONST) (*Mcu_apRamConfig)[MCU_MAX_RAMCONFIGS];
#endif
    /**< @brief Power Modes data configuration. */
    CONST( Mcu_ModeConfigType, MCU_CONST) (*Mcu_apModeConfig)[MCU_MAX_MODECONFIGS];
#if (MCU_LPU_SUPPORT == STD_ON)
    /**< @brief Low Power Modes data configuration. */
    CONST( Mcu_LPU_LowPowerModeConfigType, MCU_CONST) (*Mcu_apLowPowerModeConfig)[MCU_MAX_MODECONFIGS];
#endif
#if (MCU_INIT_CLOCK == STD_ON)
    /**< @brief Clock data configuration. */
    CONST( Mcu_ClockConfigType, MCU_CONST) (*Mcu_apClockConfig)[MCU_MAX_CLKCONFIGS];
#endif /* (MCU_INIT_CLOCK == STD_ON) */
    /**< @brief IPs data generic configuration. */
    P2CONST( Mcu_HwIPsConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pHwIPsConfig;

} Mcu_ConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Mcu_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
/**
* @brief            Local copy of the pointer to the configuration data
*/
extern P2CONST( Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pConfigPtr;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED

/** @violates @ref Mcu_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"


#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Mcu_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

#if (MCU_PRECOMPILE_SUPPORT == STD_OFF)
/**
* @brief   Export Post-Build configurations.
*/
/** @violates @ref Mcu_h_REF_2 MISRA 2004 Object defined external because of autosar*/
    MCU_CONF_PB
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_OFF) */

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Mcu_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/** @violates @ref Mcu_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

FUNC (void, MCU_CODE) Mcu_Init( P2CONST(Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
FUNC (Std_ReturnType, MCU_CODE) Mcu_InitRamSection( VAR(Mcu_RamSectionType, AUTOMATIC) RamSection);

#if (MCU_INIT_CLOCK == STD_ON)
FUNC (Std_ReturnType, MCU_CODE) Mcu_InitClock( VAR(Mcu_ClockType, AUTOMATIC) ClockSetting);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC (void, MCU_CODE) Mcu_SetMode( VAR(Mcu_ModeType, AUTOMATIC) McuMode);

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
FUNC( Std_ReturnType, MCU_CODE) Mcu_DistributePllClock( VAR( void, AUTOMATIC));
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC( Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus( VAR( void, AUTOMATIC));
FUNC( Mcu_ResetType, MCU_CODE) Mcu_GetResetReason( VAR( void, AUTOMATIC));
FUNC( Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue( VAR( void, AUTOMATIC));

#if MCU_PERFORM_RESET_API == STD_ON
FUNC( void, MCU_CODE) Mcu_PerformReset( VAR( void, AUTOMATIC));
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */


#if (MCU_VERSION_INFO_API == STD_ON)
FUNC (void, MCU_CODE) Mcu_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) pVersionInfo);
#endif /* (MCU_VERSION_INFO_API == STD_ON) */


#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC( Mcu_RamStateType, MCU_CODE) Mcu_GetRamState( VAR( void, AUTOMATIC));
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */


#if (MCU_GET_PERIPH_STATE_API == STD_ON)
FUNC( Std_ReturnType, MCU_CODE) Mcu_GetPeripheralState(VAR( Mcu_PeripheralIdType, AUTOMATIC) McuPeriphId);
#endif /* (MCU_GET_PERIPH_STATE_API == STD_ON) */


#if (MCU_GET_SYSTEM_STATE_API == STD_ON)
FUNC( uint32, MCU_CODE) Mcu_GetSystemState( VAR( void, AUTOMATIC));
#endif /* (MCU_GET_SYSTEM_STATE_API == STD_ON) */


#if (MCU_POWERMODE_STATE_API == STD_ON)
FUNC( Mcu_PowerModeStateType, MCU_CODE) Mcu_GetPowerModeState( VAR( void, AUTOMATIC));
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */


#if (MCU_GET_POWER_DOMAIN_API == STD_ON)
FUNC( Std_ReturnType, MCU_CODE ) Mcu_GetPowerDomainState( VAR( void, AUTOMATIC));
#endif /* (MCU_GET_POWER_DOMAIN_API == STD_ON) */


#if (MCU_GET_MEM_CONFIG_API == STD_ON)
FUNC( Mcu_SSCM_MemConfigType, MCU_CODE ) Mcu_SscmGetMemConfig( VAR( void, AUTOMATIC) );
#endif /* (MCU_GET_MEM_CONFIG_API == STD_ON) */


#if (MCU_SSCM_GET_STATUS_API == STD_ON)
FUNC( Mcu_SSCM_StatusType, MCU_CODE ) Mcu_SscmGetStatus( VAR( void, AUTOMATIC) );
#endif /* (MCU_SSCM_GET_STATUS_API == STD_ON) */


#ifdef MCU_SSCM_GET_UOPS_API
#if (MCU_SSCM_GET_UOPS_API == STD_ON)
FUNC( Mcu_SSCM_UopsType, MCU_CODE ) Mcu_SscmGetUops( VAR( void, AUTOMATIC) );
#endif /* (MCU_SSCM_GET_UOPS_API == STD_ON) */
#endif /* MCU_SSCM_GET_UOPS_API */


#if (MCU_GET_MIDR_API == STD_ON)
FUNC( void, MCU_CODE) Mcu_GetMidrStructure(P2VAR( Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_DATA) pMidr);
#endif /* (MCU_GET_MIDR_API == STD_ON) */


#ifdef MCU_EMIOS_CONFIGURE_GPREN_API
#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_EmiosConfigureGpren(VAR (uint8, AUTOMATIC) u8Module, VAR (uint8, AUTOMATIC) u8Value);
#endif /* (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) */
#endif /* MCU_EMIOS_CONFIGURE_GPREN_API */


#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_DisableCmu(VAR (uint8, AUTOMATIC) u8IndexCmu);
#endif
#endif

#define MCU_STOP_SEC_CODE
/** @violates @ref Mcu_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_H */

/** @} */

