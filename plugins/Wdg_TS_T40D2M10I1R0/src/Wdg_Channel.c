/**
*   @file     Wdg.c
*   @implements Wdg_Channel.c_Artifact
*   @version  1.0.1
*
*   @brief    AUTOSAR Wdg - Contains the implementation of the Watchdog API
*   @details  It contains the layer requested by autosar. The functions are independent of
*             hardware settings.
*
*   @addtogroup  Wdg
* @{
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before #include. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Wdg_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section Wdg_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
* @section Wdg_c_REF_4
*          Violates MISRA 2004 Required Rule 11.1, Cast from pointer to unsigned long.
*          This violation is due to bitwise operations that need to be performed on pointers.
*          Pointers are casted to integral type uint32 in order for the bitwise operations
*          to be performed.
* @section Wdg_c_REF_5
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          The functions/variables are part of Wdg API
* @section Wdg_c_REF_6
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are 
*          only accessed from within a single function.
*          These objects are used in various parts of the code.
* @section Wdg_c_REF_7
*          Violates MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicilty
*          convert to a different underlying type.
*          Due to GPT use 32 bits integer to store value of elaspe time in ticks and wdg does not use larger than half of this value.
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
* @file           Wdg.c     
*/
#include "Wdg_Channel.h"
#include "Wdg_EnvCfg.h"
#include "Wdg_IPW.h"
#include "SchM_Wdg.h"
#if (WDG_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
/** @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
 *                of a header file being included twice */
#include "Mcal.h"

#include "Wdg_Irq.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CHANNEL_VENDOR_ID_C                      43
/** @violates @ref Wdg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Wdg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Wdg_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C    2
#define WDG_CHANNEL_SW_MAJOR_VERSION_C               1
#define WDG_CHANNEL_SW_MINOR_VERSION_C               0
#define WDG_CHANNEL_SW_PATCH_VERSION_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_Channel.h have different vendor ids"
#endif
/* Check if current file and WDG header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_Channel.h are different"
#endif
/* Check if current file and WDG header file are of the same Software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_CHANNEL_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Channel.c and Wdg_Channel.h are different"
#endif

/* Check if current file and Wdg_Irq header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_IRQ_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg.h have different vendor ids"
#endif
/* Check if current file and WDG header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C    != WDG_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C    != WDG_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_Irq.h are different"
#endif
/* Check if current file and WDG header file are of the same Software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_IRQ_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_IRQ_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_IRQ_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Channel.c and Wdg_Irq.h are different"
#endif

/* Check if current file and DET header file are of the same version */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (WDG_DEV_ERROR_DETECT == STD_ON)
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Wdg_Channel.c and Det.h are different"
        #endif
    #endif
#endif

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Dem header file are of the same Autosar version */
     #if (( WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
          ( WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION)    \
         )
         #error "AutoSar Version Numbers of Wdg_Channel.c and Dem.h are different"
     #endif
 #endif
#endif
 
/* Check if current file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Channel.c and Mcal.h are different"
    #endif
#endif

/* Check if current file and WDG_IPW header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_IPW_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_IPW.h have different vendor ids"
#endif

/* Check if current file and WDG_IPW header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C    != WDG_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C    != WDG_IPW_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_IPW.h are different"
#endif

/* Check if current file and WDG_IPW header file are of the same Software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_IPW_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_IPW_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_IPW_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Channel.c and Wdg_IPW.h are different"
#endif

/* Check if current file and Wdg_EnvCfg header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_ENVCFG_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_EnvCfg.h have different vendor ids"
#endif

/* Check if current file and Wdg_EnvCfg header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C    != WDG_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C    != WDG_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_EnvCfg.h are different"
#endif

/* Check if current file and Wdg_EnvCfg header file are of the same Software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_ENVCFG_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_ENVCFG_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_ENVCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Channel.c and Wdg_EnvCfg.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief  This enumerated type will contain the watchdog driver's possible states
*
* 
*/
typedef enum
{
    WDG_UNINIT         = 0x00,  /**< @brief The watchdog driver is not uninitialized */
    WDG_IDLE           = 0x01,  /**< @brief = 0x01 The watchdog driver is currently idle,
                                                   i.e not being triggered or mode changed */
    WDG_BUSY           = 0x02,   /**< @brief = 0x02 The watchdog driver is currently busy,
                                                   i.e triggered or switched between modes */
    WDG_INITIALIZING   = 0x03   /**< @brief = 0x03 The watchdog driver is currently initializing */

} Wdg_StatusType;


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

#define WDG_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/**
*  @brief Variable that indicate the current configuration set
*/
static P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_apConfigPtr[WDG_NO_OF_INSTANCES];

#define WDG_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
*  @brief Variable that indicated the state of the driver
*/
static VAR(Wdg_StatusType, WDG_VAR) Wdg_aeStatus[WDG_NO_OF_INSTANCES] = {WDG_UNINIT};
#endif

#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_INIT_16
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/**
*  @brief Variable that indicate the watchdog timeout
*/
static VAR(uint16, WDG_VAR) Wdg_au16Timeout[WDG_NO_OF_INSTANCES] = {(uint16)0x0};

/**
*  @brief Variable that indicated the timer value in ms
*/
static VAR(uint16, WDG_VAR) Wdg_au16GptPeriod[WDG_NO_OF_INSTANCES] = {(uint16)0x0};

#define WDG_STOP_SEC_VAR_INIT_16
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONST_8
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

extern CONST(uint8, WDG_CONST) Wdg_au8Index[WDG_NO_OF_INSTANCES];

#define WDG_STOP_SEC_CONST_8
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
/*@violates @ref Wdg_c_REF_6 MISRa Rule 8.7 Objects shall be defined at block scope ..*/
extern CONSTP2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) Wdg_apPBCfgVariantPredefined[WDG_NO_OF_INSTANCES];
#endif

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

LOCAL_INLINE FUNC(void, WDG_CODE)  Wdg_ChannelTrigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);
#ifdef WDG_INSTANCE0
#if (WDG_INSTANCE0 == STD_ON)
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification0(void);
#endif
#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification1(void);
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification2(void);
#endif
#endif

#ifdef WDG_INSTANCE3
#if (WDG_INSTANCE3 == STD_ON)
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification3(void);
#endif
#endif

#ifdef WDG_INSTANCE4
#if (WDG_INSTANCE4 == STD_ON)
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification4(void);
#endif
#endif


#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateGlobalCall(CONST(Wdg_ServiceIdType, AUTOMATIC)uServiceId,
                                                                          CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance 
                                                                         );
#endif

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_ChannelEndValidateGlobalCall(VAR(Std_ReturnType, AUTOMATIC) validation,
                                                                   CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                                   );
#endif

#if (WDG_VALIDATE_PARAMS == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidatePtrInit
                                            (P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                             CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                            );
#endif

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateTrigerCondition(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);
#endif

#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_VERSION_INFO_API == STD_ON))
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidatePtrVersion
                                           (P2CONST(Std_VersionInfoType, AUTOMATIC, WDG_APPL_CONST) pVersioninfo,
                                            CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                           );
#endif


LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateMode(VAR(WdgIf_ModeType, AUTOMATIC) Wdg_Mode,
                                                                    VAR(Wdg_ServiceIdType, AUTOMATIC)uServiceId,
                                                                    VAR(Wdg_ErrorIdType, AUTOMATIC)uErrorId,
                                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                                    );
#ifdef WDG_VALIDATE_CONFIG_UPDATE        
#if (WDG_VALIDATE_CONFIG_UPDATE == STD_ON)                                                              
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateConfigUpdate(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);
#endif
#endif

#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_MAX_TIMEOUT_VALUE != WDG_MAX_VALUE_TYPE16))
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidateTimeout(VAR(uint16, AUTOMATIC)u16Timeout,
                                                                CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                                );
#endif

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"



#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for functions
 *             that uses all the channels - Wdg_Init, Wdg_SetTriggerCondition, Wdg_SetMode.
 *
 * @param[in]   uServiceId      The service id of the caller function
 * @param[in]   Wdg_Instance    Harwdware SWT instance
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Wdg_ChannelValidateGlobalCall_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateGlobalCall(CONST(Wdg_ServiceIdType, AUTOMATIC)uServiceId,
                                                                          CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance 
                                                                         )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;
    
    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_04();
    if(((WDG_UNINIT == Wdg_aeStatus[Wdg_Instance]) && (WDG_INIT_ID != uServiceId)) ||\
       (WDG_INITIALIZING == Wdg_aeStatus[Wdg_Instance]) || (WDG_BUSY == Wdg_aeStatus[Wdg_Instance])
      )
    {
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_04();
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)uServiceId, (uint8)WDG_E_DRIVER_STATE);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if (WDG_INIT_ID == uServiceId)
        {
            Wdg_aeStatus[Wdg_Instance] = WDG_INITIALIZING;
        }
        else
        {
            Wdg_aeStatus[Wdg_Instance] = WDG_BUSY;
        }
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_04();
    }
    return valid;
}
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON */

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function ends the validation of the global call.
 * @details    This service is a non reentrant function used for end the validation the calls for
 *             functions that uses all the channels - Wdg_Init, Wdg_SetTriggerCondition, Wdg_SetMode.
 *
 * @param[in]   validation      The function call was previously validated
 * @param[in]   Wdg_Instance    Harwdware SWT instance.
 * @return void
 *
 * @implements  Wdg_ChannelEndValidateGlobalCall_Activity
 * */
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_ChannelEndValidateGlobalCall(VAR(Std_ReturnType, AUTOMATIC) validation,
                                                                   CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                                   )
{
    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_05();
    if ((Std_ReturnType)E_OK == validation)
    {
        Wdg_aeStatus[Wdg_Instance] = WDG_IDLE;
    }
    else
    {
        if (WDG_BUSY == Wdg_aeStatus[Wdg_Instance])
        {
            Wdg_aeStatus[Wdg_Instance] = WDG_IDLE;
        }
        else
        {
            if (NULL_PTR == Wdg_apConfigPtr[Wdg_Instance])
            {
                Wdg_aeStatus[Wdg_Instance] = WDG_UNINIT;
            }
            else
            {
                Wdg_aeStatus[Wdg_Instance] = WDG_IDLE;
            }
        }
    }
    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_05();
}
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON*/
/**
* @brief   Triggers the Watchdog.
* @details The Wdg_Cbk_GptNotification shall trigger the hardware. It is set up
*          as notification function for the Gpt timer that controls the trigger of
*          the watchdog
*
* @pre    This API has to be set up as notification for the Gpt channels that is set up
*         for Wdg
*
* @param[in]   Wdg_Instance  Harwdware SWT instance.
* 
*
* @implements      Wdg_ChannelTrigger_Activity
*
*/
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_ChannelTrigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
    valid = Wdg_ChannelValidateGlobalCall(WDG_TRIGGER_ID, Wdg_Instance);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();
        
        if( Wdg_au16Timeout[Wdg_Instance] < Wdg_au16GptPeriod[Wdg_Instance])
        {
            MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_TG_0);
            SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
            Gpt_StopTimer(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
        }
        else
        {
            VAR(uint16, AUTOMATIC) u16TempTimeout = Wdg_au16Timeout[Wdg_Instance] - Wdg_au16GptPeriod[Wdg_Instance];
            
            Wdg_au16Timeout[Wdg_Instance] = u16TempTimeout;
            SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();          
            Wdg_IPW_Trigger(Wdg_Instance);
        }
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Wdg_ChannelEndValidateGlobalCall(valid, Wdg_Instance);
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
}
#ifdef WDG_INSTANCE0
#if (WDG_INSTANCE0 == STD_ON)
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*   functions at file scope shall have internal linkage unless external linkage is required. 
* @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
*
**/
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification0(void)
{
    Wdg_ChannelTrigger(WDG_IPW_INSTANCE0);
}
#endif
#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. 
 *   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
 *
**/
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification1(void)
{
    Wdg_ChannelTrigger(WDG_IPW_INSTANCE1);
}
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*   functions at file scope shall have internal linkage unless external linkage is required. 
*   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
*
**/
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification2(void)
{
    Wdg_ChannelTrigger(WDG_IPW_INSTANCE2);
}
#endif
#endif

#ifdef WDG_INSTANCE3
#if (WDG_INSTANCE3 == STD_ON)
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*   functions at file scope shall have internal linkage unless external linkage is required. 
*   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
*
**/
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification3(void)
{
    Wdg_ChannelTrigger(WDG_IPW_INSTANCE3);
}
#endif
#endif


#ifdef WDG_INSTANCE4
#if (WDG_INSTANCE4 == STD_ON)
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*   functions at file scope shall have internal linkage unless external linkage is required. 
*   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
*
**/
FUNC(void, WDG_CODE) Wdg_Cbk_GptNotification4(void)
{
    Wdg_ChannelTrigger(WDG_IPW_INSTANCE4);
}
#endif
#endif

#if (WDG_VALIDATE_PARAMS == STD_ON)
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   ConfigPtr        Pointer to a selected configuration structure
 * @param[in]   Wdg_Instance     Harwdware SWT instance
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ValidatePtrInit_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidatePtrInit
                                            (P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                             CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                            )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;
    
#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif /*#if (WDG_PRECOMPILE_SUPPORT == STD_ON)*/
        {
            (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)WDG_INIT_ID, (uint8)WDG_E_INIT_FAILED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
#if (WDG_PRECOMPILE_SUPPORT == STD_OFF)
        else 
        {
            if (Wdg_Instance != ConfigPtr->Wdg_Instance)
            {
                (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)WDG_INIT_ID, (uint8)WDG_E_PARAM_POINTER);
                valid = (Std_ReturnType)E_NOT_OK;
            }       
            else
            {
                /* do nothing */
            }
        }      
#endif /*WDG_PRECOMPILE_SUPPORT == STD_OFF*/
        return valid;
}
#endif /* (WDG_VALIDATE_PARAMS == STD_ON)*/

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the call of Wdg_ChannelSetTriggerCondition function
 * @details    This service is a function used for validating the calls for 
               Wdg_ChannelSetTriggerCondition.
 *
 * @param[in]   Wdg_Instance    Harwdware SWT instance
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Wdg_ChannelSetTriggerCondition_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateTrigerCondition(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if ((WDG_UNINIT == Wdg_aeStatus[Wdg_Instance]) ||(WDG_INITIALIZING == Wdg_aeStatus[Wdg_Instance]))
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)WDG_SETTRIGGERCONDITION_ID, (uint8)WDG_E_DRIVER_STATE);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON */

#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_VERSION_INFO_API == STD_ON))
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   pVersioninfo        Pointer to a selected configuration structure.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ValidatePtrVersion_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidatePtrVersion
                                           (P2CONST(Std_VersionInfoType, AUTOMATIC, WDG_APPL_CONST) pVersioninfo,
                                            CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                           )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if (NULL_PTR == pVersioninfo)
    {

        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance],(uint8)WDG_GETVERSION_ID,(uint8)WDG_E_PARAM_POINTER);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (WDG_VALIDATE_PARAMS == STD_ON)*/
/**
 * @brief       This function validate the mode that will be set up.
 *
 * @param[in]   Wdg_Mode      The watchdog mode that will be set up.
 * @param[in]   uServiceId    The service id of the caller function
 * @param[in]   uErrorId      The function call was previously validated
 * @param[in]   Wdg_Instance  Harwdware SWT instance.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ChannelValidateMode_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateMode(VAR(WdgIf_ModeType, AUTOMATIC) Wdg_Mode,
                                                                    VAR(Wdg_ServiceIdType, AUTOMATIC)uServiceId,
                                                                    VAR(Wdg_ErrorIdType, AUTOMATIC)uErrorId,
                                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                                    )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;
    VAR(boolean, AUTOMATIC) disableRejectedErrActive  = (boolean)FALSE;
    VAR(boolean, AUTOMATIC) modeFailedErrActive  = (boolean)FALSE;

#if (WDG_DISABLE_ALLOWED == STD_OFF)
    if (WDGIF_OFF_MODE == Wdg_Mode)
    {
        disableRejectedErrActive  = (boolean)TRUE;
        valid = (Std_ReturnType)E_NOT_OK;
    }
#endif  /* (WDG_DISABLE_ALLOWED == STD_OFF) */
    if (FALSE == ((WDGIF_OFF_MODE  == Wdg_Mode)||(WDGIF_FAST_MODE == Wdg_Mode)||(WDGIF_SLOW_MODE == Wdg_Mode)))
    {
#if (WDG_VALIDATE_PARAMS == STD_ON)

        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)uServiceId, (uint8)uErrorId);
#else 
        (void)uServiceId;
        (void)uErrorId;
#endif
         modeFailedErrActive  = (boolean)TRUE;
         valid = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if ((Std_ReturnType)E_NOT_OK == Wdg_IPW_CheckHwSettings(Wdg_apConfigPtr[Wdg_Instance]->Wdg_ModeSettings[Wdg_Mode], Wdg_Instance))
        {

#if (WDG_VALIDATE_PARAMS == STD_ON)
            (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)uServiceId, (uint8)uErrorId);
#endif
            modeFailedErrActive  = (boolean)TRUE;
            valid = (Std_ReturnType)E_NOT_OK;
        }
    }
    
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if((uint32)STD_ON == Wdg_E_Disable_Rejected.state)
    {
#if (WDG_DISABLE_ALLOWED == STD_OFF)
        if((boolean)TRUE == disableRejectedErrActive)
        {
                              Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Disable_Rejected.id, DEM_EVENT_STATUS_FAILED);
                    }
        else
        {
                              Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Disable_Rejected.id, DEM_EVENT_STATUS_PASSED);
                    }
#else
    (void)disableRejectedErrActive;
#endif     /*WDG_DISABLE_ALLOWED == STD_OFF*/
    }
    if((uint32)STD_ON == Wdg_E_Mode_Failed.state)
    {
        if((boolean)TRUE == modeFailedErrActive)
        {
                              Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
                    }
        else
        {
                              Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
                    }
    }
#else
    (void)modeFailedErrActive;
    (void)disableRejectedErrActive;
#endif  /* (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

    return valid;
}


#ifdef WDG_VALIDATE_CONFIG_UPDATE        
#if (WDG_VALIDATE_CONFIG_UPDATE == STD_ON)
/**
 * @brief       This function validate the usage of the Wdg_SetMode API considering if the WDG configuration update is allowed
 *
 * @param[in]   Wdg_Mode      The watchdog mode that will be set up.
 * @param[in]   uServiceId    The service id of the caller function
 * @param[in]   uErrorId      The function call was previously validated
 * @param[in]   Wdg_Instance  Harwdware SWT instance.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ChannelValidateMode_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelValidateConfigUpdate(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if ((Std_ReturnType)E_OK != Wdg_IPW_ValidateConfigUpdate(Wdg_Instance))
    {

#if (WDG_VALIDATE_PARAMS == STD_ON)

        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance], (uint8)WDG_SETMODE_ID, (uint8)WDG_E_PARAM_MODE);
#endif

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if((uint32)STD_ON == Wdg_E_Mode_Failed.state)
        {
            /* Report production error */
                              Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
                    }
#endif /* (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
     valid = (Std_ReturnType)E_NOT_OK;
            
    }
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    else
    {
        if((uint32)STD_ON == Wdg_E_Mode_Failed.state)
        {
                              Dem_ReportErrorStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
                    }
    }
#endif

    return valid;
}
#endif
#endif


#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_MAX_TIMEOUT_VALUE != WDG_MAX_VALUE_TYPE16))
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   u16Timeout    timeout window
 * @param[in]   Wdg_Instance  Harwdware SWT instance.
 
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ValidateTimeout_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ValidateTimeout(VAR(uint16, AUTOMATIC)u16Timeout,
                                                                CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                                )
{
    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    if (u16Timeout > WDG_MAX_TIMEOUT_U16)
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Wdg_au8Index[Wdg_Instance],(uint8)WDG_SETTRIGGERCONDITION_ID,(uint8)WDG_E_PARAM_TIMEOUT);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* WDG_VALIDATE_PARAMS == STD_ON */

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief   Detects missed trigger of the hardware
* @details The Wdg_Isr is used to detect missed trigger of the hardware
*
* @param[in]   Wdg_Instance  Harwdware SWT instance.
* *
* @implements      Wdg_ProcessInterrupt_Activity
*
* @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required. **/
FUNC(void, WDG_CODE) Wdg_ProcessInterrupt(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    if (NULL_PTR != Wdg_apConfigPtr[Wdg_Instance])
    {
        if  (NULL_PTR != Wdg_apConfigPtr[Wdg_Instance]->Wdg_CallbackPtr)
        {
            Wdg_apConfigPtr[Wdg_Instance]->Wdg_CallbackPtr();
        }
    }
}

/**
* @brief   This function initializes the WDG module.
* @details The @p Wdg_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in]   pConfigPtr     Pointer to configuration set.
* @param[in]   Wdg_Instance  Harwdware SWT instance.
*
* @implements      Wdg_ChannelInit_Activity
*
* 
*/
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(void, WDG_CODE) Wdg_ChannelInit(P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr,
                                     CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                    )
{
    VAR(uint32 , AUTOMATIC) u32TimerValue;
    VAR(Std_ReturnType, AUTOMATIC)valid;
    
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Wdg_ChannelValidateGlobalCall(WDG_INIT_ID,Wdg_Instance);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */

#if (WDG_VALIDATE_PARAMS == STD_ON)
        valid = Wdg_ValidatePtrInit(pConfigPtr, Wdg_Instance);
        if ((Std_ReturnType)E_OK == valid)
        {
#else

        (void)pConfigPtr;
#endif
#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
            /** @violates @ref Wdg_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from pointer to unsigned long.*/
            Wdg_apConfigPtr[Wdg_Instance] = Wdg_apPBCfgVariantPredefined[Wdg_Instance];
            (void)pConfigPtr;
#else
            Wdg_apConfigPtr[Wdg_Instance] = pConfigPtr;
#endif /*(WDG_PRECOMPILE_SUPPORT == STD_ON)*/

            valid = Wdg_ChannelValidateMode(Wdg_apConfigPtr[Wdg_Instance]->Wdg_DefaultMode, WDG_INIT_ID, WDG_E_PARAM_CONFIG, Wdg_Instance);
            if ((Std_ReturnType)E_OK == valid)
            {
                Gpt_StopTimer(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
                u32TimerValue = Wdg_IPW_Init(Wdg_apConfigPtr[Wdg_Instance]->Wdg_ModeSettings[Wdg_apConfigPtr[Wdg_Instance]->Wdg_DefaultMode], Wdg_Instance);
                Wdg_au16GptPeriod[Wdg_Instance] = (uint16)(u32TimerValue/ (Wdg_apConfigPtr[Wdg_Instance]->Wdg_ModeSettings[Wdg_apConfigPtr[Wdg_Instance]->Wdg_DefaultMode])->Wdg_u32InternalTimerClock);
                Gpt_EnableNotification(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
                /* start the timer channel only if the mode is not off mode */
                if (WDGIF_OFF_MODE != Wdg_apConfigPtr[Wdg_Instance]->Wdg_DefaultMode)
                {
                    Gpt_StartTimer(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel, \
                    (u32TimerValue / Wdg_apConfigPtr[Wdg_Instance]->Wdg_ModeSettings[Wdg_apConfigPtr[Wdg_Instance]->Wdg_DefaultMode]->Wdg_u32InternalTimerClock) * Wdg_apConfigPtr[Wdg_Instance]->Wdg_u32TriggerSourceClock);
                }
                SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_01();
                Wdg_au16Timeout[Wdg_Instance] = WDG_INITIAL_TIMEOUT_U16;
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_01();
            }
            else
            {
                Wdg_apConfigPtr[Wdg_Instance] = NULL_PTR;
            }
#if (WDG_VALIDATE_PARAMS == STD_ON)
        }
#endif
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Wdg_ChannelEndValidateGlobalCall(valid, Wdg_Instance);
#endif
}

/**
* @brief   Switches the watchdog into the mode Mode.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p Wdg_SetMode
*          function:<br>
*          - WDGIF_OFF_MODE,
*          - WDGIF_SLOW_MODE,
*          - WDGIF_FAST_MODE.
*          .
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      -# WDGIF_OFF_MODE,
*                      -# WDGIF_SLOW_MODE,
*                      -# WDGIF_FAST_MODE.
*
* @param[in]   Wdg_Instance  Harwdware SWT instance.
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* @implements      Wdg_ChannelSetMode_Activity
*
* 
*/
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(Std_ReturnType, WDG_CODE) Wdg_ChannelSetMode(WdgIf_ModeType Mode,
                                                  CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                  )
{
    VAR(Std_ReturnType, AUTOMATIC) ret = (Std_ReturnType)E_NOT_OK;
    VAR(Std_ReturnType, AUTOMATIC)valid;

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Wdg_ChannelValidateGlobalCall(WDG_SETMODE_ID, Wdg_Instance);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
        MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_START);
        valid = Wdg_ChannelValidateMode(Mode, WDG_SETMODE_ID, WDG_E_PARAM_MODE, Wdg_Instance);
        if ((Std_ReturnType)E_OK == valid)
        {
            #ifdef WDG_VALIDATE_CONFIG_UPDATE        
            #if (WDG_VALIDATE_CONFIG_UPDATE == STD_ON)
            valid = Wdg_ChannelValidateConfigUpdate(Wdg_Instance);
            if ((Std_ReturnType)E_OK == valid)
            {
            #endif
            #endif
                VAR(uint32, AUTOMATIC) u32TimerValue = Wdg_IPW_SetMode(Wdg_apConfigPtr[Wdg_Instance]->Wdg_ModeSettings[Mode], Wdg_Instance);
                VAR(Gpt_ValueType, AUTOMATIC) uElapsedTime;
                VAR(uint16, AUTOMATIC) u16Temp;  
                
                Gpt_StopTimer(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
                uElapsedTime =  Gpt_GetTimeElapsed(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
                /* update timeout */
                SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_02();
                u16Temp = Wdg_au16Timeout[Wdg_Instance] - (uint16)(uElapsedTime/Wdg_apConfigPtr[Wdg_Instance]->Wdg_u32TriggerSourceClock);
                Wdg_au16Timeout[Wdg_Instance] =  u16Temp;
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_02();
                Wdg_au16GptPeriod[Wdg_Instance] = (uint16)(u32TimerValue / (Wdg_apConfigPtr[Wdg_Instance]->Wdg_ModeSettings[Mode])->Wdg_u32InternalTimerClock);

                /* Start the timer only if the mode is not off mode*/
                if (WDGIF_OFF_MODE != Mode)
                {
                    Gpt_StartTimer(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel,Wdg_au16GptPeriod[Wdg_Instance]* Wdg_apConfigPtr[Wdg_Instance]->Wdg_u32TriggerSourceClock);
                }
                ret = (Std_ReturnType)E_OK;
                
            #ifdef WDG_VALIDATE_CONFIG_UPDATE        
            #if (WDG_VALIDATE_CONFIG_UPDATE == STD_ON)
            }
            #endif
            #endif
        }
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    }
    Wdg_ChannelEndValidateGlobalCall(valid, Wdg_Instance);
#endif
    MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_STOP);
    return ret;
}

/**
 * @brief   Reset the watchdog timeout counter according to the timeout value passed.
 * @details 
 *
 * @param[in]   u16Timeout value (milliseconds) for setting the trigger counter.
 * @param[in]   Wdg_Instance  Harwdware SWT instance.
 * 
 * @implements      Wdg_ChannelSetTriggerCondition_Activity
 *
 * 
 */
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(void, WDG_CODE) Wdg_ChannelSetTriggerCondition(uint16 u16Timeout,
                                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                                   )
{
    VAR(Gpt_ValueType, AUTOMATIC) uElapsedTime = (Gpt_ValueType)0;
#if ((WDG_VALIDATE_GLOBAL_CALL == STD_ON) || (WDG_VALIDATE_PARAMS == STD_ON))
    VAR(Std_ReturnType, AUTOMATIC)valid;
#endif

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    valid = Wdg_ChannelValidateTrigerCondition(Wdg_Instance);
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_MAX_TIMEOUT_VALUE != WDG_MAX_VALUE_TYPE16))
        valid = Wdg_ValidateTimeout(u16Timeout, Wdg_Instance);
        if ((Std_ReturnType)E_OK == valid)
        {
#endif
            SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_03();
            /** @violates @ref Wdg_c_REF_7 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicilty */
            uElapsedTime =  Gpt_GetTimeElapsed(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
            if (((uint16)(uElapsedTime/Wdg_apConfigPtr[Wdg_Instance]->Wdg_u32TriggerSourceClock) > Wdg_au16Timeout[Wdg_Instance]) || ((uint16)0 == u16Timeout))
            {
                Wdg_au16Timeout[Wdg_Instance] = (uint16)0;
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_03();
                Gpt_StopTimer(Wdg_apConfigPtr[Wdg_Instance]->Wdg_TimerChannel);
            }
            else
            {
                /** @violates @ref Wdg_c_REF_7 MISRA 2004 Required Rule 10.1, The value of expression of integer type shall not be implicilty */
                Wdg_au16Timeout[Wdg_Instance] = u16Timeout + (uint16)(uElapsedTime / Wdg_apConfigPtr[Wdg_Instance]->Wdg_u32TriggerSourceClock);
                SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_03();
            }
#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_MAX_TIMEOUT_VALUE != WDG_MAX_VALUE_TYPE16))
        }
#endif
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    }
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
}


#if (WDG_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of the module.
* @details The  Wdg_ChannelGetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This ISR is only required if the WDG_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] pVersioninfo   Pointer to where to store the version
*                              information of this module.
*
* 
*
* @implements      Wdg_ChannelGetVersionInfo_Activity
*
*/
/** @violates @ref Wdg_c_REF_5 MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */
FUNC(void, WDG_CODE) Wdg_ChannelGetVersionInfo
                    (P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) pVersioninfo,
                     CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                    )
{
#if (WDG_VALIDATE_PARAMS == STD_ON)
    VAR(Std_ReturnType, AUTOMATIC)valid=(Std_ReturnType)E_NOT_OK;
#endif

    (void)Wdg_Instance;
#if (WDG_VALIDATE_PARAMS == STD_ON)
    valid = Wdg_ValidatePtrVersion(pVersioninfo, Wdg_Instance);
    
    if ((Std_ReturnType)E_OK == valid)
    {
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/
        (pVersioninfo)->vendorID         = (uint16)WDG_CHANNEL_VENDOR_ID;
        (pVersioninfo)->moduleID         = (uint8)WDG_CHANNEL_MODULE_ID;
        (pVersioninfo)->sw_major_version = (uint8)WDG_CHANNEL_SW_MAJOR_VERSION;
        (pVersioninfo)->sw_minor_version = (uint8)WDG_CHANNEL_SW_MINOR_VERSION;
        (pVersioninfo)->sw_patch_version = (uint8)WDG_CHANNEL_SW_PATCH_VERSION;
#if (WDG_VALIDATE_PARAMS == STD_ON)
    }
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/

}
#endif /* WDG_VERSION_INFO_API == STD_ON */

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before #include
* @violates @ref Wdg_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
