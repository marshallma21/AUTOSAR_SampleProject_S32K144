/**
*   @file    Wdg_Channel.h
*   
*   @version 1.0.1
*
*   @brief   AUTOSAR Wdg - contains the data exported by the watchodg module
*   @details Contains the information that will be exported by the module, as requested by Autosar.
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

#ifndef WDG_CHANNEL_H
#define WDG_CHANNEL_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Channel_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section Wdg_Channel_h_REF_2
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
#include "Mcal.h"
#include "Wdg_Cfg.h"
#if (WDG_TYPE == WDG_EXTERNAL_MODULE_SPI)
    #include "Spi.h"
#elif(WDG_TYPE == WDG_EXTERNAL_MODULE_DIO)
    #include "Dio.h"
#endif

#include "Gpt.h"

#include "Wdg_IPW_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Channel.h    
*/
#define WDG_CHANNEL_VENDOR_ID                    43
#define WDG_CHANNEL_MODULE_ID                    102
#define WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION     4
#define WDG_CHANNEL_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref Wdg_Channel_h_REF_2 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define WDG_CHANNEL_AR_RELEASE_REVISION_VERSION  2
#define WDG_CHANNEL_SW_MAJOR_VERSION             1
#define WDG_CHANNEL_SW_MINOR_VERSION             0
#define WDG_CHANNEL_SW_PATCH_VERSION             1

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID != WDG_VENDOR_ID_CFG)
    #error "Wdg_Channel.h and Wdg_Cfg.h have different vendor ids"
#endif

/* Check if current file and WDG configuration header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION    != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION    != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION != WDG_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Wdg_Channel.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and WDG configuration header file are of the same software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Wdg_Channel.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Channel.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Channel.h and Gpt.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Channel.h and Mcal.h are different"
    #endif
#endif

/* Check if source file and WDG external dependencies are of the same Autosar version */
#if (WDG_TYPE == WDG_EXTERNAL_MODULE_SPI)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION) || \
             (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Wdg_Channel.h and Spi.h are different"
        #endif
    #endif
#elif (WDG_TYPE == WDG_EXTERNAL_MODULE_DIO)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) || \
             (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Wdg_Channel.h and Dio.h are different"
        #endif
    #endif  
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief  This enumerated type will contain the service ids for the watchodg functions
*
* @pre To define WDG_GETVERSION_ID, WDG_VERSION_INFO_API has to be equal to STD_ON
*
*/
typedef enum Wdg_ServiceIdType
{
#if (WDG_VERSION_INFO_API == STD_ON)
    WDG_GETVERSION_ID   = 0x04, /*< @brief The service id for the Wdg_GetVersion function,
                                            used when using DET */
#endif
    WDG_INIT_ID                 = 0x00, /*< @brief The service id for the Wdg_Init function, used
                                            when using DET */
    WDG_SETMODE_ID              = 0x01, /*< @brief The service id for the Wdg_SetMode function, used
                                            when using DET */
    WDG_SETTRIGGERCONDITION_ID  = 0x02, /*< @brief The service id for the Wdg_SetTriggerCondition function, used
                                            when using DET */
    WDG_TRIGGER_ID              = 0x03  /*< @brief The service id for the Wdg_Cbk_GptNotification function, used
                                            when using DET */
} Wdg_ServiceIdType;

/**
* @brief  Indicates the aditional det errors used by the watchdog driver
* @implements     Wdg_ErrorIdType_enum
*/
typedef enum Wdg_ErrorIdType
{
    WDG_E_DRIVER_STATE  = 0x10, /*< @brief API service used in wrong context (e.g. driver not
                                            initialized) */
    WDG_E_PARAM_MODE,           /*< @brief = 0x11 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_CONFIG,         /*< @brief = 0x12 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_TIMEOUT,        /*< @brief = 0x13 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_POINTER,        /*< @brief = 0x14 Wdg_GetVersionInfo service called with
                                                   NULL_PTR */
    WDG_E_INIT_FAILED           /*< @brief = 0x15 Invalid configuration set selection */

                                                   
} Wdg_ErrorIdType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*
 * @brief This type shall be chosen in order to implement a callback notification in the Wdg_Isr routine.
 */
typedef P2FUNC(void, WDG_CODE, Wdg_CallbackPtrType)  ( void );

/**
* @brief  Defines the configuration structure
* @implements     Wdg_ConfigType_struct
*/
typedef struct
{
    /**
    @brief The number of configured channels
    */
    CONST(WdgIf_ModeType, WDG_CONST) Wdg_DefaultMode;
    /**
    @brief The instance id
    */
    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance;
    /**
    @brief Gpt Channel configured
    */
    CONST(Gpt_ChannelType, WDG_CONST) Wdg_TimerChannel;

    /**
    @brief The frequency of the configured timer channel
    */
    CONST(uint32, WDG_CONST) Wdg_u32TriggerSourceClock;

    /**
    @brief Pointer to Watchdog Specific implementation details
    */
    P2CONST(Wdg_IPW_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_ModeSettings[3];

    /**
    @brief Pointer to callback notification
    */
    Wdg_CallbackPtrType     Wdg_CallbackPtr;        /**< @brief Call Back notification */
} Wdg_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Channel_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/

#include "Wdg_MemMap.h"

#if (WDG_PRECOMPILE_SUPPORT == STD_OFF)
    WDG_CONF_PB
#endif /* (WDG_PRECOMPILE_SUPPORT == STD_OFF) */

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Wdg_Channel_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Channel_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


/* This function initializes the WDG module.*/
FUNC(void, WDG_CODE) Wdg_ChannelInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr,\
                                     CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                    );

/* Switches the watchdog into the mode Mode.*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelSetMode(WdgIf_ModeType Mode, \
                                                  CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                 );

/*This function triggers the watchdog hardware.*/
FUNC(void, WDG_CODE) Wdg_ChannelSetTriggerCondition(uint16 u16Timeout, \
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                   );

/*Returns the version information of the module.*/
#if (WDG_VERSION_INFO_API == STD_ON)
FUNC(void, WDG_CODE) Wdg_ChannelGetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) pVersioninfo, \
                                               CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                              );

#endif /* WDG_VERSION_INFO_API == STD_ON */

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Channel_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* WDG_CHANNEL_H */
/** @} */
