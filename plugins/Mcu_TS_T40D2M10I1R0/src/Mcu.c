/**
*   @file    Mcu.c
*   @implements Mcu.c_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Mcu - Implementation of external interface.
*   @details High level validation of the data managed to/from high level.
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


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
** @section Mcu_c_REF_3
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithmetic, to access the channel
* parameters, the indexing of the pointer is taken care and hence the unintended memory location
* will not be accessed
*
* @section Mcu_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
*
* @section Mcu_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_c_REF_7
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Mcu_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.4 , A cast should not be performed between a pointer to object type
* and a different pointer to object type.
*
* @section Mcu_c_REF_9
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour.
* The local address passed as parameter is used in a safe way.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters.The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

/**
* @brief Mcu.c shall include Mcu.h
*/
#include "Mcu.h"

/* Get the prototypes of IPW functions. */
#include "Mcu_IPW.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_VENDOR_ID_C                     43
#define MCU_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Mcu_c_REF_4 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_AR_RELEASE_REVISION_VERSION_C   2
#define MCU_SW_MAJOR_VERSION_C              1
#define MCU_SW_MINOR_VERSION_C              0
#define MCU_SW_PATCH_VERSION_C              1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Mcu.c and Mcal.h are different"
#endif
#endif

/* Check if current file and MCU header file are of the same vendor */
#if (MCU_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Mcu.c and Mcu.h are different"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu.c and Mcu.h are different"
#endif

/* Check if current file and Mcu_IPW header file are of the same vendor */
#if (MCU_VENDOR_ID_C != MCU_IPW_VENDOR_ID)
#error "Mcu.c and Mcu_IPW.h have different vendor ids"
#endif

/* Check if current file and Mcu_IPW header file are of the same Autosar version */
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != MCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_AR_RELEASE_MINOR_VERSION_C != MCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCU_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
#error "AutoSar Version Numbers of Mcu.c and Mcu_IPW.h are different"
#endif

/* Check if current file and Mcu_IPW header file are of the same Software version */
#if ((MCU_SW_MAJOR_VERSION_C != MCU_IPW_SW_MAJOR_VERSION) || \
     (MCU_SW_MINOR_VERSION_C != MCU_IPW_SW_MINOR_VERSION) || \
     (MCU_SW_PATCH_VERSION_C != MCU_IPW_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu.c and Mcu_IPW.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Mcu.c and Det.h are different"
#endif
#endif
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief  This enumerated type contains the Mcu driver's possible states.
*/
typedef enum
{
    MCU_UNINIT = 0x3U,  /**< @brief The Mcu driver is not uninitialized. */
    MCU_IDLE = 0xCU,  /**< @brief = 0xE1 The Mcu driver is currently idle. */
    MCU_BUSY = 0xAU   /**< @brief = 0xD2 The Mcu driver is currently busy. */
} Mcu_StatusType;


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref Mcu_c_REF_2 Only preprocessor statements and comments before '#include' MemMap.h */
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Array for saving the Clock configuration Ids.
*/
static VAR(uint8, MCU_VAR) Mcu_au8ClockConfigIds[MCU_MAX_CLKCONFIGS];
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/**
* @brief            Array for saving the Mode configuration Ids.
*/
static VAR(uint8, MCU_VAR) Mcu_au8ModeConfigIds[MCU_MAX_MODECONFIGS];


/**
* @brief            Array for saving the Ram sectors configuration Ids.
*                   If no ramConfig is defined, remove all usages of that array
*/

#ifndef MCU_MAX_NORAMCONFIGS
static VAR(uint8, MCU_VAR) Mcu_au8RamConfigIds[MCU_MAX_RAMCONFIGS];
#endif /* ( 0 != MCU_MAX_RAMCONFIGS ) */

#define MCU_STOP_SEC_VAR_NO_INIT_8
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_c_REF_2 Only preprocessor statements and comments before '#include' MemMap.h */
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"
/**
*  @brief Variable that indicated the state of the driver
*/
#if ( ( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) || (MCU_DEV_ERROR_DETECT == STD_ON) )
static VAR(Mcu_StatusType, MCU_VAR)  Mcu_eStatus = MCU_UNINIT;
#endif /* ( ( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) || (MCU_DEV_ERROR_DETECT == STD_ON) ) */

/**
* @brief            Local copy of the pointer to the configuration data
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
P2CONST( Mcu_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pConfigPtr = NULL_PTR;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)

/**
* @violates @ref Mcu_c_REF_7 MISRA 2004 Required Rule 8.7, object defined external because of
* autosar
*/
extern CONST(Mcu_ConfigType, MCU_CONST) Mcu_PBCfgVariantPredefined;

#endif

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
P2CONST( Mcu_DemConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_pDemCfgPtr = NULL_PTR;
#endif
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"

#if ( MCU_PARAM_CHECK == STD_ON )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInit(P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */


#ifndef MCU_MAX_NORAMCONFIGS
#if ( MCU_PARAM_CHECK == STD_ON )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitRamSection(VAR( Mcu_RamSectionType, AUTOMATIC) RamSection);
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* ifndef MCU_MAX_NORAMCONFIGS */


#if (MCU_INIT_CLOCK == STD_ON)
#if ( MCU_PARAM_CHECK == STD_ON )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitClock(VAR( Mcu_ClockType, AUTOMATIC) ClockSetting);
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if ( MCU_PARAM_CHECK == STD_ON )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckSetMode( VAR( Mcu_ModeType, AUTOMATIC) McuMode);
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */


#if (MCU_GET_MIDR_API == STD_ON)
#if ( MCU_PARAM_CHECK == STD_ON )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckGetMidrStructure(P2CONST( Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_CONST) pMidr);
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* (MCU_GET_MIDR_API == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
#if ( MCU_PARAM_CHECK == STD_ON )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckDistributePllClock( VAR( void, AUTOMATIC));
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /*(MCU_INIT_CLOCK == STD_ON)*/


#ifdef MCU_CHECK_PERFORM_RESET
#if ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PERFORM_RESET_API == STD_ON) && \
     (MCU_PARAM_CHECK == STD_ON) \
    )
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckPerformReset( VAR( void, AUTOMATIC));
#endif /* ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PERFORM_RESET_API == STD_ON) &&
           (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_CHECK_PERFORM_RESET */


#ifdef MCU_EMIOS_CONFIGURE_GPREN_API
#if ((MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckConfigureGpren(VAR (uint8, AUTOMATIC) u8Module);
#endif /* ((MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_EMIOS_CONFIGURE_GPREN_API */


#ifdef MCU_DISABLE_CMU_API
#if ((MCU_DISABLE_CMU_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckDisableCMU(VAR (uint8, AUTOMATIC) u8IndexCmu);
#endif /* ((MCU_DISABLE_CMU_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_DISABLE_CMU_API */


#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
/* mcu state check, entry point */
static FUNC(Std_ReturnType, MCU_CODE) Mcu_HLDChecksEntry(VAR( uint8, AUTOMATIC) u8McuServiceID);
#endif /* MCU_VALIDATE_GLOBAL_CALL == STD_ON  */


#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
/* mcu state check, exit point */
static FUNC(void, MCU_CODE) Mcu_HLDChecksExit(VAR(Std_ReturnType, AUTOMATIC) retStatus, VAR( uint8, AUTOMATIC) u8McuServiceID);
#endif /* MCU_VALIDATE_GLOBAL_CALL == STD_ON */

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ( MCU_PARAM_CHECK == STD_ON )
/**
* @brief Mcu_CheckInit - checks for Mcu_Init
* @implements Mcu_CheckInit_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInit(P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /* local vars */
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;
    
    /* the check will be available if */
    /* if MCU_DEV_ERROR_DETECT is of the det will be reported*/
#if (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    if ( NULL_PTR == pConfigPtr )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ( (uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INIT_ID, MCU_E_INIT_FAILED);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }
#else
    /* Avoid compiler warning */
    MCU_PARAM_UNUSED(pConfigPtr);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_OFF) */

    return (Std_ReturnType) CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */


#ifndef MCU_MAX_NORAMCONFIGS
#if ( MCU_PARAM_CHECK == STD_ON )
/**
* @brief Mcu_CheckInitRamSection - checks for Mcu_InitRamSection
* @implements Mcu_CheckInitRamSection_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitRamSection(VAR( Mcu_RamSectionType, AUTOMATIC) RamSection)
{
    /* local vars */
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    /* checks */
    if ( RamSection >= (Mcu_pConfigPtr->Mcu_NoRamConfigs))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_RAMSECTION);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }
    else
    {
        /* Check if Ram memory configuration is valid. */
        if ( NULL_PTR == Mcu_pConfigPtr->Mcu_apRamConfig)
        {
            CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
            (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITRAMSECTION_ID, MCU_E_PARAM_RAMSECTION);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
        }
    }
    return (Std_ReturnType) CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* ifndef MCU_MAX_NORAMCONFIGS */


#if (MCU_INIT_CLOCK == STD_ON)
#if ( MCU_PARAM_CHECK == STD_ON )
/**
* @brief Mcu_CheckInitClock - checks for Mcu_InitClock
* @implements Mcu_CheckInitClock_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckInitClock( VAR( Mcu_ClockType, AUTOMATIC) ClockSetting )
{
    /* local vars */
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    if ( ClockSetting >= (Mcu_pConfigPtr->Mcu_NoClkConfigs) )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_INITCLOCK_ID, MCU_E_PARAM_CLOCK);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType) CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if ( MCU_PARAM_CHECK == STD_ON )
/**
* @brief Mcu_CheckSetMode - checks for Mcu_SetMode
* @implements Mcu_CheckSetMode_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckSetMode(VAR( Mcu_ModeType, AUTOMATIC) McuMode)
{
    VAR(Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    if (McuMode >= (Mcu_pConfigPtr->Mcu_NoModeConfigs))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError ((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_SETMODE_ID, MCU_E_PARAM_MODE);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType) CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */


#if (MCU_GET_MIDR_API == STD_ON)
#if ( MCU_PARAM_CHECK == STD_ON )
/**
* @brief Mcu_CheckGetMidrStructure - checks for Mcu_GetMidrStructure
* @implements Mcu_CheckGetMidrStructure_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckGetMidrStructure(P2CONST( Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_CONST) pMidr)
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    if ( NULL_PTR == pMidr )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETMIDRSTRUCTURE_ID, MCU_E_PARAM_POINTER);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType) CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* (MCU_GET_MIDR_API == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
#if ( MCU_PARAM_CHECK == STD_ON )
/**
* @brief Mcu_CheckDistributePllClock - checks for Mcu_DistributePllClock
* @implements Mcu_CheckDistributePllClock_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckDistributePllClock( VAR( void, AUTOMATIC))
{
   VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    if ( MCU_PLL_LOCKED != (Mcu_PllStatusType)Mcu_Ipw_GetPllStatus() )
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISTRIBUTEPLLCLOCK_ID, MCU_E_PLL_NOT_LOCKED);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType) CheckStatus;
}
#endif /* ( MCU_PARAM_CHECK == STD_ON ) */
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /*(MCU_INIT_CLOCK == STD_ON)*/


#ifdef MCU_CHECK_PERFORM_RESET
#if ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PERFORM_RESET_API == STD_ON) && \
     (MCU_PARAM_CHECK == STD_ON) \
    )
/**
* @brief Mcu_CheckPerformReset - checks for Mcu_PerformReset
* @implements Mcu_PerformReset_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckPerformReset( VAR( void, AUTOMATIC))
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

#ifdef MCU_CHECK_FIRC_STATE
#if (MCU_CHECK_FIRC_STATE == STD_ON)
    if ((Std_ReturnType)E_NOT_OK == Mcu_IPW_GetFircStatus())
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_PERFORMRESET_ID, MCU_E_PERFORM_RESET);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }
#endif /* (MCU_CHECK_FIRC_STATE == STD_ON) */
#endif /* MCU_CHECK_FIRC_STATE */

    return (Std_ReturnType) CheckStatus;
}
#endif /* ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PERFORM_RESET_API == STD_ON) &&
           (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_CHECK_PERFORM_RESET */


#ifdef MCU_EMIOS_CONFIGURE_GPREN_API
#if ((MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
/**
* @brief Mcu_CheckConfigureGpren - checks for Mcu_EmiosConfigureGpren
* @implements Mcu_CheckConfigureGpren_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckConfigureGpren(VAR (uint8, AUTOMATIC) u8Module)
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

#ifdef MCU_CHECK_EMIOS_STATUS
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
    if ((Std_ReturnType)E_NOT_OK == Mcu_IPW_CheckEmiosStatus(u8Module))
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_EMIOSCONFIGUREGPREN_ID, MCU_E_EMIOS_DEACTIVATED);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
#endif /* MCU_CHECK_EMIOS_STATUS */

    return (Std_ReturnType) CheckStatus;
}
#endif /* ((MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_EMIOS_CONFIGURE_GPREN_API */


#ifdef MCU_DISABLE_CMU_API
#if ((MCU_DISABLE_CMU_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
/**
* @brief Mcu_CheckDisableCMU - checks for Mcu_Disable_CMU
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_CheckDisableCMU(VAR (uint8, AUTOMATIC) u8IndexCmu)
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

    if (MCU_CMU_UNITS <= u8IndexCmu)
    {
        CheckStatus = (Std_ReturnType)E_NOT_OK;
#if (MCU_DEV_ERROR_DETECT == STD_ON)
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_DISABLECMU_ID, MCU_E_CMU_INDEX_OUT_OF_RANGE);
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    }

    return (Std_ReturnType) CheckStatus;
}
#endif /* ((MCU_DISABLE_CMU_API == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_DISABLE_CMU_API */


#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
/* mcu state check, entry point */
/**
* @brief Mcu_HLDChecksEntry - checks for invalid mode transitions
* @implements Mcu_HLDChecksEntry_Activity
*/
static FUNC(Std_ReturnType, MCU_CODE) Mcu_HLDChecksEntry(VAR( uint8, AUTOMATIC) u8McuServiceID)
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_OK;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if ( MCU_INIT_ID == u8McuServiceID )
    {
        if ( MCU_UNINIT != Mcu_eStatus) /* if Mcu_Init was already called */
        {
            CheckStatus = (Std_ReturnType)E_NOT_OK;
            (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)u8McuServiceID, MCU_E_ALLREADY_INITIALIZED);
        }
    }
    else
    {
        if ( MCU_UNINIT == Mcu_eStatus) /* if Mcu_Init was not called */
        {
            CheckStatus = (Std_ReturnType)E_NOT_OK;
            (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, (uint8)u8McuServiceID, MCU_E_UNINIT);
        }
    }
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
    return (Std_ReturnType) CheckStatus;
}

#endif /* MCU_VALIDATE_GLOBAL_CALL == STD_ON  */


#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
/* mcu state check, exit point */
/**
* @brief Mcu_HLDChecksExit - checks for invalid mode transitions
* @implements Mcu_HLDChecksExit_Activity
*/
static FUNC(void, MCU_CODE) Mcu_HLDChecksExit(VAR( Std_ReturnType, AUTOMATIC) retStatus, VAR( uint8, AUTOMATIC) u8McuServiceID)
{
    if (MCU_INIT_ID == u8McuServiceID)
    {
        if ((Std_ReturnType)E_OK == (Std_ReturnType)retStatus)
        {
            Mcu_eStatus = MCU_IDLE;
        }
        else
        {
            Mcu_eStatus = MCU_UNINIT;
        }
    }
    else
    {
        Mcu_eStatus = MCU_IDLE;
    }
}
#endif /* MCU_VALIDATE_GLOBAL_CALL == STD_ON */
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            MCU driver initialization function.
* @details          This routine initializes the MCU Driver.
*                   The intention of this function is to make the configuration setting for power
*                   down, clock and Ram sections visible within the MCU Driver.
*
* @param[in]        pConfigPtr   Pointer to configuration structure.
*
* @return           void
*
* @api
*
* @implements Mcu_Init_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(void, MCU_CODE) Mcu_Init( P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /* Temporary variable for looping all the configurations. */
    VAR(uint32, AUTOMATIC) u32NoConfigs;
#if ( ( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) || ( MCU_PARAM_CHECK==STD_ON ) )
    VAR(Std_ReturnType, AUTOMATIC ) checkStatus;
#endif /*( ( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) || ( MCU_PARAM_CHECK==STD_ON ) )*/

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    checkStatus = (Std_ReturnType)Mcu_HLDChecksEntry(MCU_INIT_ID);
    if((Std_ReturnType)E_OK == checkStatus)
    {
        /* check status is now E_OK */
#endif /* ( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) */
        /* Get a local copy of the driver initialization structure. */

#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
        Mcu_pConfigPtr = &Mcu_PBCfgVariantPredefined;
        MCU_PARAM_UNUSED(pConfigPtr);
#else
        Mcu_pConfigPtr = pConfigPtr ;
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */


        /* When Post-Build is used the input parameter 'pConfigPtr' is mandatory to be different than
         * NULL_PTR. */
        /* check the config. in case of error, do nothing. the Check function will report errors */
#if ( MCU_PARAM_CHECK==STD_ON )
        checkStatus = Mcu_CheckInit(Mcu_pConfigPtr);
        if ((Std_ReturnType)E_OK == checkStatus)
        {
#endif /* (MCU_PARAM_CHECK==STD_ON) */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* Get a local copy of the DEM error reporting structure. */
            Mcu_pDemCfgPtr = Mcu_pConfigPtr->Mcu_pDemConfig;
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

            /* Save the Mcu Mode IDs configurations. */
            for(u32NoConfigs = (uint32)0U; u32NoConfigs < Mcu_pConfigPtr->Mcu_NoModeConfigs; u32NoConfigs++)
            {
                Mcu_au8ModeConfigIds[(*Mcu_pConfigPtr->Mcu_apModeConfig)[u32NoConfigs].Mcu_ModeConfigId] = (uint8)u32NoConfigs;
            }

#if (MCU_INIT_CLOCK == STD_ON)
            /* Save the Mcu Clock IDs configurations. */
            for(u32NoConfigs = (uint32)0U; u32NoConfigs < Mcu_pConfigPtr->Mcu_NoClkConfigs; u32NoConfigs++)
            {
                Mcu_au8ClockConfigIds[(*Mcu_pConfigPtr->Mcu_apClockConfig)[u32NoConfigs].Mcu_ClkConfigId] = (uint8)u32NoConfigs;
            }
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
            /* Save the Mcu Ram Sector IDs configurations. */
            for(u32NoConfigs = (uint32)0U; u32NoConfigs < Mcu_pConfigPtr->Mcu_NoRamConfigs; u32NoConfigs++)
            {
                Mcu_au8RamConfigIds[(*Mcu_pConfigPtr->Mcu_apRamConfig)[u32NoConfigs].Mcu_RamSectorId] = (uint8)u32NoConfigs;
            }
#endif /*( 0 != MCU_MAX_RAMCONFIGS )*/
            Mcu_Ipw_Init( Mcu_pConfigPtr->Mcu_pHwIPsConfig);
            /* the driver was initialized, set the proper status */

#if (MCU_PARAM_CHECK==STD_ON)
        }
        else
        {
            /* clean the init pointer in case of an error */
            Mcu_pConfigPtr = NULL_PTR;
        }
#endif /* (MCU_PARAM_CHECK==STD_ON) */


#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit(checkStatus,MCU_INIT_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
}


/**
* @brief            MCU driver initialization of Ram sections.
* @details          Function initializes the ram section selected by RamSection parameter.
*                   The section base address, size and value to be written are provided from
*                   the configuration structure.
*                   The function will write the value specified in the configuration structure
*                   indexed by RamSection.
*                   After the write it will read back the RAM to verify that the requested value was
*                   written.
*
* @param[in]        RamSection   Index of ram section from config structure to be initialized.
*
* @return           Command has or has not been accepted.
* @retval           E_OK        Valid parameter, the driver state allowed execution and the RAM
*                               check was successful
* @retval           E_NOT_OK    Invalid parameter, the driver state did not allowed execution or
*                               the RAM check was not successful
*
* @api
*
* @implements Mcu_InitRamSection_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( Std_ReturnType, MCU_CODE) Mcu_InitRamSection( VAR( Mcu_RamSectionType, AUTOMATIC) RamSection)
{
    /* Result of the operation. */
    VAR(Std_ReturnType, AUTOMATIC) RamStatus = (Std_ReturnType)E_NOT_OK;

#ifndef MCU_MAX_NORAMCONFIGS
    /* Variable for indexinf RAM sections. */
    VAR(Mcu_RamIndexType, AUTOMATIC) RamCounter;
    /* Pointer to RAM configuration: base addr, size, default value. */
    P2CONST( Mcu_RamConfigType, AUTOMATIC, MCU_APPL_CONST) pRamConfigPtr;
#endif

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_INITRAMSECTION_ID))
    {
#endif /*(MCU_VALIDATE_GLOBAL_CALL == STD_ON)*/
        /* Check if the driver is initialized. */
/* if no ramConfig is defined, the function will do nothing */
#ifndef MCU_MAX_NORAMCONFIGS
#if (MCU_PARAM_CHECK==STD_ON)
        /* Check if Ram memory configuration is valid. */
        if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckInitRamSection(RamSection))
        {
#endif /*(MCU_PARAM_CHECK==STD_ON)*/
            /* Get Ram settings from the configuration structure. */
            pRamConfigPtr = &(*Mcu_pConfigPtr->Mcu_apRamConfig)[Mcu_au8RamConfigIds[RamSection]];
            
            for(RamCounter = (Mcu_RamIndexType)0UL; RamCounter < ((Mcu_RamSizeType)(pRamConfigPtr->Mcu_RamSize)); RamCounter++)
            {
                (*pRamConfigPtr->Mcu_pu8RamBaseAddr)[RamCounter] = pRamConfigPtr->Mcu_u8RamDefaultValue;
            }

            RamStatus = (Std_ReturnType)E_OK;

            MCAL_FAULT_INJECTION_POINT(MCU_FIP_01_START);

            /* Check if RAM was initialized correctly. */
            for(RamCounter = (Mcu_RamIndexType)0UL; RamCounter < ((Mcu_RamSizeType)(pRamConfigPtr->Mcu_RamSize)); RamCounter++)
            {
                if ((*pRamConfigPtr->Mcu_pu8RamBaseAddr)[RamCounter] != pRamConfigPtr->Mcu_u8RamDefaultValue)
                {
                    RamStatus = (Std_ReturnType)E_NOT_OK;
                }
            }

            MCAL_FAULT_INJECTION_POINT(MCU_FIP_02_STOP);
#if (MCU_PARAM_CHECK==STD_ON)
        }
#endif /*(MCU_PARAM_CHECK==STD_ON)*/

#else
    /* To avoid compiler warning */
    MCU_PARAM_UNUSED(RamSection);
#endif /* #ifndef MCU_MAX_NORAMCONFIGS */

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_INITRAMSECTION_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
    return (Std_ReturnType)RamStatus;
}


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            MCU driver clock initialization function.
* @details          This function initializes the PLL and MCU specific clock options. The clock
*                       setting is provided from the configuration structure.
*
* @param[in]        ClockSetting   Clock setting ID from config structure to be used.
*
* @return           Command has or has not been accepted.
* @retval           E_OK        The driver state allowed the execution of the function and the
*                                   provided parameter was in range
* @retval           E_NOT_OK    The driver state did not allowed execution or the parameter was
*                                   invalid
*
* @api
*
* @implements Mcu_InitClock_Activity
*
*/
/** @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of
  * function */
FUNC( Std_ReturnType, MCU_CODE) Mcu_InitClock( VAR( Mcu_ClockType, AUTOMATIC) ClockSetting)
{
    /* Return the success of the clock initialization operation. */
#if (( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) || (MCU_PARAM_CHECK==STD_ON))
    VAR(Std_ReturnType, AUTOMATIC) ClockStatus = (Std_ReturnType)E_NOT_OK;
#else
    VAR(Std_ReturnType, AUTOMATIC) ClockStatus;
#endif
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_INITCLOCK_ID))
    {
#endif /*(MCU_VALIDATE_GLOBAL_CALL == STD_ON)*/
        /* Check if Clock configuration is valid. */
#if (MCU_PARAM_CHECK==STD_ON)
        if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckInitClock(ClockSetting))
        {
#endif /*(MCU_PARAM_CHECK==STD_ON)*/
            Mcu_Ipw_InitClock(&(*Mcu_pConfigPtr->Mcu_apClockConfig)[Mcu_au8ClockConfigIds[ClockSetting]]);
            /* Command has been accepted. */
            ClockStatus = (Std_ReturnType)E_OK;
#if (MCU_PARAM_CHECK==STD_ON)
        }
#endif /*(MCU_PARAM_CHECK==STD_ON)*/
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit((Std_ReturnType)E_OK, MCU_INITCLOCK_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
    return (Std_ReturnType)ClockStatus;
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/**
* @brief            This function sets the MCU power mode.
* @details          This function activates MCU power mode from config structure selected by McuMode
*                       parameter.
*                   If the driver state is invalid or McuMode is not in range the function will skip
*                       changing the mcu mode.
*
* @param[in]        McuMode   MCU mode setting ID from config structure to be set.
*
* @return           void
*
* @api
*
* @implements Mcu_SetMode_Activity
*
*/
/** @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of
* function
*/
FUNC(void, MCU_CODE) Mcu_SetMode(VAR(Mcu_ModeType, AUTOMATIC) McuMode)
{
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_SETMODE_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
#if (MCU_PARAM_CHECK==STD_ON)
        /* Check if Mode configuration is valid. */
        if ( (Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckSetMode(McuMode) )
        {
#endif /*(MCU_PARAM_CHECK==STD_ON)*/

#if (MCU_LPU_SUPPORT == STD_ON)
            if (NULL_PTR != Mcu_pConfigPtr->Mcu_apLowPowerModeConfig)
            {
                Mcu_IPW_LpuSetMode(&(*Mcu_pConfigPtr->Mcu_apLowPowerModeConfig)[Mcu_au8ModeConfigIds[McuMode]]);
            }
#endif

            Mcu_Ipw_SetMode( &(*Mcu_pConfigPtr->Mcu_apModeConfig)[Mcu_au8ModeConfigIds[McuMode]] );
#if (MCU_PARAM_CHECK==STD_ON)
        }
#endif /*(MCU_PARAM_CHECK==STD_ON)*/
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_SETMODE_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
}


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function activates the PLL clock to the MCU clock distribution.
* @details          Function completes the PLL configuration and then activates the PLL clock to
*                       MCU. If the MCU_NO_PLL is TRUE the Mcu_DistributePllClock has to be
*                       disabled.
*                   The function will not distribute the PLL clock if the driver state does not
*                       allow it, or the PLL is not stable.
*
* @return           Std_ReturnType
* @retval           E_OK        Command has been accepted.
* @retval           E_NOT_OK    Command has not been accepted.
*
* @api
*
* @implements Mcu_DistributePllClock_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of
* function
*/
FUNC( Std_ReturnType, MCU_CODE) Mcu_DistributePllClock(VAR( void, AUTOMATIC))
{
    /* Return variable */
    VAR(Std_ReturnType, AUTOMATIC) PllStatus = (Std_ReturnType)E_NOT_OK;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_DISTRIBUTEPLLCLOCK_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        /* Check if the PLL is locked. */

#if ( MCU_PARAM_CHECK==STD_ON )
        PllStatus = (Std_ReturnType)Mcu_CheckDistributePllClock();
        if((Std_ReturnType)E_OK == PllStatus)
        {
#endif /* ( MCU_PARAM_CHECK==STD_ON ) */

            /* Set the PLL as System Clock if it is locked and enabled by the current mode.
            If the PLL0 is already selected as system clock, then this function will return without
            doing anything. */
            Mcu_Ipw_DistributePllClock();

#if ( MCU_PARAM_CHECK==STD_ON )
        }
#endif /* ( MCU_PARAM_CHECK==STD_ON ) */


#if(MCU_VALIDATE_GLOBAL_CALL == STD_ON)
        Mcu_HLDChecksExit((Std_ReturnType)E_OK ,MCU_DISTRIBUTEPLLCLOCK_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

        return (Std_ReturnType)PllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/**
* @brief            This function returns the lock status of the PLL.
* @details          The user takes care that the PLL is locked by executing Mcu_GetPllStatus.
*                       If the MCU_NO_PLL is TRUE the MCU_GetPllStatus has to return
*                       MCU_PLL_STATUS_UNDEFINED.
*                   It will also return MCU_PLL_STATUS_UNDEFINED if the driver state was invalid
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED    PLL Status is unknown.
* @retval           MCU_PLL_LOCKED              PLL is locked.
* @retval           MCU_PLL_UNLOCKED            PLL is unlocked.
*
* @api
*
* @implements Mcu_GetPllStatus_Activity
*
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( Mcu_PllStatusType, MCU_CODE) Mcu_GetPllStatus( VAR( void, AUTOMATIC))
{
    /* Return variable */
#if (( MCU_VALIDATE_GLOBAL_CALL == STD_ON ) || (MCU_NO_PLL == STD_ON))
    VAR(Mcu_PllStatusType, AUTOMATIC) ePllStatus = MCU_PLL_STATUS_UNDEFINED;
#else
    VAR(Mcu_PllStatusType, AUTOMATIC) ePllStatus;
#endif
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETPLLSTATUS_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
#if (MCU_NO_PLL == STD_OFF)
    /* if the PLL is not used in the configuration return MCU_PLL_STATUS_UNDEFINED */
        /* Get status of the PLL (if enabled in current mode).
           At this point the return value can be only MCU_PLL_LOCKED or MCU_PLL_UNLOCKED. */
        ePllStatus = Mcu_Ipw_GetPllStatus();
#endif /* (MCU_NO_PLL == STD_OFF) */
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit((Std_ReturnType)E_OK ,MCU_GETPLLSTATUS_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (Mcu_PllStatusType)ePllStatus;
}


/**
* @brief            This function returns the Reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*
*
* @return           Reason of the Reset event.
* @retval           MCU_POR_RESET           Power on event.
* @retval           MCU_SOFT_DEST_RESET     Software destructive reset.
* @retval           MCU_FFRR_RESET          FCCU failure to react reset.
* @retval           MCU_EDR_RESET           Functional reset escalation.
* @retval           MCU_TSR_DEST_RESET      Temperature sensor destructive reset.
* @retval           MCU_VOR_DEST_RESET      Voltage out of range destructive reset.
* @retval           MCU_EXR_RESET           External reset event.
* @retval           MCU_ST_DONE_RESET       Self-test completed event.
* @retval           MCU_SOFT_FUNC_RESET     Software destructive event.
* @retval           MCU_FCCU_HARD_RESET     FCCU hard reaction request event.
* @retval           MCU_FCCU_SOFT_RESET     FCCU soft reaction request event.
* @retval           MCU_JTAG_RESET          JTAG initiated reset event.
* @retval           MCU_TSR_FUNC_RESET      Temperature sensor functional reset.
* @retval           MCU_VOR_FUNC_RESET      Voltage out of range functional reset.
*
* @api
*
* @implements Mcu_GetResetReason_Activity
*
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(Mcu_ResetType, MCU_CODE) Mcu_GetResetReason(VAR( void, AUTOMATIC))
{
    /* Return value of the function. */
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    VAR(Mcu_ResetType, AUTOMATIC) eResetReason = MCU_RESET_UNDEFINED;
#else
    VAR(Mcu_ResetType, AUTOMATIC) eResetReason;
#endif

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETRESETREASON_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        /* Get the reset reason. */
        eResetReason = (Mcu_ResetType)Mcu_Ipw_GetResetReason();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETRESETREASON_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (Mcu_ResetType)eResetReason;
}


/**
* @brief            This function returns the Raw Reset value.
* @details          This routine returns the Raw Reset value that is read from the hardware.
*
* @return           Description of the returned value.
* @retval           uint32   Code of the Raw reset value.
*                   The bit order in the returned value is:
*                   [ 0] - MC_RGM_FES_F_EXR_MASK32
*                   [ 1] - MC_RGM_FES_F_ST_DONE_MASK32
*                   [ 2] - MC_RGM_FES_F_SOFT_FUNC_MASK32
*                   [ 3] - MC_RGM_FES_F_FCCU_HARD_MASK32
*                   [ 4] - MC_RGM_FES_F_FCCU_SOFT_MASK32
*                   [ 5] - MC_RGM_FES_F_JTAG_FUNC_MASK32
*                   [ 6] - MC_RGM_FES_F_TSR_FUNC_MASK32
*                   [ 7] - MC_RGM_FES_F_VOR_FUNC_MASK32
*                   [16] - MC_RGM_DES_F_POR_MASK32
*                   [17] - MC_RGM_DES_F_SOFT_DEST_MASK32
*                   [18] - MC_RGM_DES_F_FFRR_MASK32
*                   [19] - MC_RGM_DES_F_EDR_MASK32
*                   [20] - MC_RGM_DES_F_TSR_DEST_MASK32
*                   [21] - MC_RGM_DES_F_VOR_DEST_MASK32
*
* @api
*
* @implements Mcu_GetResetRawValue_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( Mcu_RawResetType, MCU_CODE) Mcu_GetResetRawValue( VAR( void, AUTOMATIC))
{
    /* Return value of the function. */
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    VAR( Mcu_RawResetType, AUTOMATIC) RawResetValue = MCU_RAW_RESET_DEFAULT;
#else
    VAR( Mcu_RawResetType, AUTOMATIC) RawResetValue;
#endif

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if ( (Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETRESETRAWVALUE_ID) )
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        RawResetValue = (Mcu_RawResetType)Mcu_Ipw_GetResetRawValue();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETRESETRAWVALUE_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
    return (Mcu_RawResetType)RawResetValue;
}


#if (MCU_PERFORM_RESET_API == STD_ON)
/**
* @brief            This function performs a micro-controller reset.
* @details          This function performs a micro-controller reset by using the hardware feature of
*                   the micro-controller. In case the function returns, the user must reset the
*                   platform using an alternate reset mechanism
*
* @return           void
*
* @api
*
* @implements Mcu_PerformReset_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( void, MCU_CODE) Mcu_PerformReset( VAR( void, AUTOMATIC))
{
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if ( (Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_PERFORMRESET_ID) )
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
#ifdef MCU_CHECK_PERFORM_RESET
#if ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
        if ( (Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckPerformReset() )
        {
#endif /* ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_CHECK_PERFORM_RESET */
#if (MCU_RESET_CALLOUT_USED == STD_ON)
            /* User callout */
            MCU_RESET_CALLOUT();
#endif /* (MCU_RESET_CALLOUT_USED == STD_ON) */
            Mcu_Ipw_PerformReset( Mcu_pConfigPtr->Mcu_pHwIPsConfig);
            /* we should not get here */
            /* it's the app. responsibility to detect if the reset failed */
#ifdef MCU_CHECK_PERFORM_RESET
#if ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PARAM_CHECK == STD_ON))
        }
#endif /* ((MCU_CHECK_PERFORM_RESET == STD_ON) && (MCU_PARAM_CHECK == STD_ON)) */
#endif /* MCU_CHECK_PERFORM_RESET */
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_PERFORMRESET_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */


#if (MCU_VERSION_INFO_API == STD_ON)
/**
* @brief            This function returns the Version Information for the MCU module.
* @details          This function returns the vendor id, module id, major, minor and patch version.
*
* @param[in,out]    pVersionInfo   A pointer to a variable to store version info.
*
* @return           void
*
* @api
*
* @implements Mcu_GetVersionInfo_Activity
*
*
*/
/** @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( void, MCU_CODE) Mcu_GetVersionInfo(P2VAR( Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) pVersionInfo)
{
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    if(NULL_PTR == pVersionInfo )
    {
        (void) Det_ReportError((uint16)MCU_MODULE_ID, MCU_INSTANCE_ID, MCU_GETVERSIONINFO_ID, MCU_E_PARAM_POINTER);
    }
    else
    {
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
        (pVersionInfo)->vendorID = (uint16)MCU_VENDOR_ID;
        (pVersionInfo)->moduleID = (uint8)MCU_MODULE_ID;
        (pVersionInfo)->sw_major_version = (uint8)MCU_SW_MAJOR_VERSION;
        (pVersionInfo)->sw_minor_version = (uint8)MCU_SW_MINOR_VERSION;
        (pVersionInfo)->sw_patch_version = (uint8)MCU_SW_PATCH_VERSION;

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */
}
#endif /* (MCU_VERSION_INFO_API == STD_ON) */


#if (MCU_GET_MIDR_API == STD_ON)
/**
* @brief            This function returns the value of the MIDR registers.
* @details          This function returns the platform dependent Mcu_MidrReturnType structure witch
*                   contains the MIDRn registers.
*
* @param[in,out]    pMidr   A pointer to a variable to store the Mcu_MidrReturnType structure.
*
* @return           void
*
* @api
*
* @implements Mcu_GetMidrStructure_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( void, MCU_CODE) Mcu_GetMidrStructure(P2VAR( Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_DATA) pMidr)
{
#if (MCU_PARAM_CHECK==STD_ON)
    /* Check if Mode configuration is valid. */
    if ( (Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckGetMidrStructure(pMidr) )
    {
#endif /*(MCU_PARAM_CHECK==STD_ON)*/
        Mcu_Ipw_GetMidrStructure( pMidr );
#if (MCU_PARAM_CHECK==STD_ON)
    }
#endif /*(MCU_PARAM_CHECK==STD_ON)*/
}
#endif /* (MCU_GET_MIDR_API == STD_ON) */

#if (MCU_GET_RAM_STATE_API == STD_ON)
/**
* @brief            This function returns the actual state of the RAM.
* @details          This function returns if the Ram Status is valid after a reset.
*                   The report is get from STCU as a result of MBIST (Memory Built-In Self Tests).
*
* @return           Status of the Ram Content.
*
* @retval           MCU_RAMSTATE_INVALID    Ram state is not valid or unknown (default),
*                                               or the driver state does not allow this call.
* @retval           MCU_RAMSTATE_VALID      Ram state is valid.
*
* @api
*
* @implements Mcu_GetRamState_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( Mcu_RamStateType, MCU_CODE) Mcu_GetRamState( VAR( void, AUTOMATIC))
{

    /* Return value of this function. */
    VAR( Mcu_RamStateType, AUTOMATIC) eRamState = MCU_RAMSTATE_INVALID;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETRAMSTATE_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        eRamState = (Mcu_RamStateType)Mcu_Ipw_GetRamState();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETRAMSTATE_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (Mcu_RamStateType)eRamState;
}

#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */


#if (MCU_GET_PERIPH_STATE_API == STD_ON)
/**
* @brief            This function returns the peripheral clock state.
* @details          This function returns one peripheral is frozen or active from MC_ME hw IP.
*
* @param[in]        McuPeriphId   Peripheral ID based ME_PSx registers.
*
* @return           Status of the peripheral clock.
* @retval           E_OK        Peripheral is active (clocked).
* @retval           E_NOT_OK    Peripheral is not active (not clocked) or the driver state did not
*                               allow the call.
*
* @api
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC( Std_ReturnType, MCU_CODE) Mcu_GetPeripheralState(VAR( Mcu_PeripheralIdType, AUTOMATIC) McuPeriphId)
{
    /* Result of the operation. */
    VAR(Std_ReturnType, AUTOMATIC) PeripheralStatus = (Std_ReturnType)E_NOT_OK;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETPERIPHERALSTATE_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        PeripheralStatus = (Std_ReturnType)Mcu_Ipw_GetPeripheralState( McuPeriphId);
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit((Std_ReturnType)E_OK ,MCU_GETPERIPHERALSTATE_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
    return (Std_ReturnType)PeripheralStatus;
}
#endif /* (MCU_GET_PERIPH_STATE_API == STD_ON) */


#if (MCU_GET_SYSTEM_STATE_API == STD_ON)
/**
* @brief            This function returns the System Status and Configuration Module information.
* @details          This function returns information about execution mode, security, vle, jtag id.
*
* @return           Status read from SSCM module - STATUS and MEMCONFIG registers.
* @retval           uint32   Platform register specific.
*
* @api
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(uint32, MCU_CODE) Mcu_GetSystemState(VAR(void, AUTOMATIC))
{
    VAR(uint32, AUTOMATIC) u32SystemStatus = 0U;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETSYSTEMSTATE_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        u32SystemStatus = Mcu_Ipw_GetSystemState();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETSYSTEMSTATE_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (u32SystemStatus);

}
#endif /* (MCU_GET_SYSTEM_STATE_API == STD_ON) */


#if (MCU_GET_MEM_CONFIG_API == STD_ON)
/**
* @brief            This function returns the System Memory and ID register from SSCM.
* @details          This function returns the value of the SSCM_MEMCONFIG register.
*
* @return           Value read from SSCM_MEMCONFIG register.
* @retval           Mcu_SSCM_MemConfigType   Platform register specific.
*
* @api
*
* @implements Mcu_SscmGetMemConfig_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(Mcu_SSCM_MemConfigType, MCU_CODE) Mcu_SscmGetMemConfig(VAR(void, AUTOMATIC))
{
    VAR( Mcu_SSCM_MemConfigType, AUTOMATIC) MemConfig = (Mcu_SSCM_MemConfigType)0U;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETMEMCONFIG_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        MemConfig = Mcu_Ipw_SscmGetMemConfig();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit((Std_ReturnType)E_OK ,MCU_GETMEMCONFIG_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (MemConfig);
}
#endif /* (MCU_GET_MEM_CONFIG_API == STD_ON) */


#if (MCU_SSCM_GET_STATUS_API == STD_ON)
/**
* @brief            This function returns the value of the SSCM_STATUS register..
* @details          Return information about execution mode, security, vle.
*
* @return           Value read from SSCM_STATUS register.
* @retval           Mcu_SSCM_StatusType   Platform register specific.
*
* @api
*
* @implements Mcu_SscmGetStatus_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(Mcu_SSCM_StatusType, MCU_CODE) Mcu_SscmGetStatus(VAR( void, AUTOMATIC))
{
    VAR( Mcu_SSCM_StatusType, AUTOMATIC) Status = (Mcu_SSCM_StatusType)0U;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if ( (Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_SSCMGETSTATUS_ID) )
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        Status = Mcu_Ipw_SscmGetStatus();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_SSCMGETSTATUS_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (Status);
}
#endif /* (MCU_SSCM_GET_STATUS_API == STD_ON) */


#ifdef MCU_SSCM_GET_UOPS_API
#if (MCU_SSCM_GET_UOPS_API == STD_ON)
/**
* @brief            This function returns the value of the SSCM_UOPS register.
* @details          Return information about User Option Bits, HSM Boot Configuration.
*
* @return           Value read from SSCM_UOPS register.
* @retval           Mcu_SSCM_UopsType   Platform register specific.
*
* @api
*
* @implements Mcu_SscmGetUops_Activity
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(Mcu_SSCM_UopsType, MCU_CODE) Mcu_SscmGetUops(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SSCM_UopsType, AUTOMATIC) Status = (Mcu_SSCM_UopsType)0U;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_SSCMGETUOPS_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        Status = Mcu_Ipw_SscmGetUops();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit((Std_ReturnType)E_OK ,MCU_SSCMGETUOPS_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

    return (Status);
}
#endif /* (MCU_SSCM_GET_UOPS_API == STD_ON) */
#endif /* MCU_SSCM_GET_UOPS_API */


#if (MCU_POWERMODE_STATE_API == STD_ON)
/**
* @brief            This function returns the System Status (power mode, clock settings) from MC_ME
*                   hw IP.
* @details          The return value is the content register read from hardware (ME_GS). The return
*                   value shall evidentiate the current running mode, clock settings and activation,
*                   etc.
*
* @return           Get the state of the power mode.
* @retval           uint32   Content of ME_GS register.
*
* @api
*
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(Mcu_PowerModeStateType, MCU_CODE) Mcu_GetPowerModeState(VAR( void, AUTOMATIC))
{
    /* Return value of this function. */
    VAR(Mcu_PowerModeStateType, AUTOMATIC) PowerModeState = (Mcu_PowerModeStateType)0U;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETPOWERMODESTATE_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        PowerModeState = (Mcu_PowerModeStateType)Mcu_Ipw_GetPowerModeState();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETPOWERMODESTATE_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
    return (Mcu_PowerModeStateType)PowerModeState;
}
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */


#if (MCU_GET_POWER_DOMAIN_API == STD_ON)
/**
* @brief            This function returns the power status of all available power domains.
* @details          This function returns if power domain is operable or inoperable form MC_PCU hw
*                   IP.
*
* @return           Get the state of Power Control Unit
* @retval           E_OK        Power domain is operable.
* @retval           E_NOT_OK    Power domain is inoperable or the driver state did not allowed the
*                               function all.
*
* @api
*
*
*/
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(Std_ReturnType, MCU_CODE) Mcu_GetPowerDomainState(VAR( void, AUTOMATIC))
{
    /* Result of the operation. */
    VAR(Std_ReturnType, AUTOMATIC) PowerStatus = (Std_ReturnType)E_NOT_OK;

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_GETPOWERDOMAIN_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
        PowerStatus = (Std_ReturnType)Mcu_Ipw_GetPowerDomainState();
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_GETPOWERDOMAIN_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
    return (Std_ReturnType)PowerStatus;
}
#endif /* (MCU_GET_POWER_DOMAIN_API == STD_ON) */


#ifdef MCU_EMIOS_CONFIGURE_GPREN_API
#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
/**
 * @brief   eMios Global Prescaler Enable.
 * @details This function enables or disables the GPREN bit of the EMIOSMCR register of an
 *          addressed eMIOS instance.
 * @pre     Function requires an execution of Mcu_Init() before it can be used,
 *otherwise it reports error to DET.
 *
 * @param[in] u8Module    MCU_EMIOS_MODULE_0 --> Select eMios 0
 *                           MCU_EMIOS_MODULE_1 --> Select eMios 1
 *                           MCU_EMIOS_MODULE_2 --> Select eMios 2
 *
 * @param[in] u8Value        MCU_EMIOS_GPREN_BIT_ENABLE   --> Global Prescaler Enabled
 *                           MCU_EMIOS_GPREN_BIT_DISABLE  --> Global Prescaler Disabled
 *
 * @return                   void
 *
 * @api
 * @implements Mcu_EmiosConfigureGpren_Activity
 */
 /**
 * @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
 */
FUNC(void, MCU_CODE ) Mcu_EmiosConfigureGpren(VAR (uint8, AUTOMATIC) u8Module, VAR (uint8, AUTOMATIC) u8Value)
{
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_EMIOSCONFIGUREGPREN_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

#if (MCU_PARAM_CHECK == STD_ON)
        if ((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckConfigureGpren(u8Module))
        {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
            Mcu_IPW_EmiosConfigureGpren(u8Module, u8Value);
#if (MCU_PARAM_CHECK == STD_ON)
        }
#endif /* (MCU_PARAM_CHECK == STD_ON) */

#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_EMIOSCONFIGUREGPREN_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
}
#endif /* (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) */
#endif /* MCU_EMIOS_CONFIGURE_GPREN_API */


#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
/**
 * @brief   Disable clock monitoring unit.
 * @details This function disables the selected clock monitoring unit.
 * @pre     Function requires an execution of Mcu_Init() before it can be used.
 *
 * @param[in] u8IndexCmu    The index of the CMU that must be disabled.
 *
 * @return                   void
 *
 * @api
 * @implements Mcu_DisableCmu_Activity
 */
/**
* @violates @ref Mcu_c_REF_6 Violates MISRA 2004 Required Rule 8.10, global declaration of function
*/
FUNC(void, MCU_CODE ) Mcu_DisableCmu(VAR (uint8, AUTOMATIC) u8IndexCmu)
{
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
    if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_HLDChecksEntry(MCU_DISABLECMU_ID))
    {
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/

#if (MCU_PARAM_CHECK == STD_ON)
        if((Std_ReturnType)E_OK == (Std_ReturnType)Mcu_CheckDisableCMU(u8IndexCmu))
        {
#endif /* (MCU_PARAM_CHECK == STD_ON) */
            Mcu_Ipw_DisableCmu(u8IndexCmu);
#if (MCU_PARAM_CHECK == STD_ON)
        }
#endif /* (MCU_PARAM_CHECK == STD_ON) */
#if ( MCU_VALIDATE_GLOBAL_CALL == STD_ON )
        Mcu_HLDChecksExit( (Std_ReturnType)E_OK ,MCU_DISABLECMU_ID);
    }
#endif /*( MCU_VALIDATE_GLOBAL_CALL == STD_ON )*/
}
#endif
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include' MemMap.h
*/
/** @violates @ref Mcu_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files.*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
