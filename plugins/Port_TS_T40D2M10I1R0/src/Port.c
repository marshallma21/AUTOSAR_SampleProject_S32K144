/**
*   @file    Port.c
*   @implements Port.c_Artifact
*
*   @version 1.0.1
*   @brief   AUTOSAR Port - PORT driver high level driver.
*   @details Implementation of the AutoSar high level PORT driver.
*
*   @addtogroup Port
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : PORT_CI
*   Dependencies         : none
*
*   Autosar Version      : 4.2.
*                          2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20180713
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_C_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*          '#include'. MemMap.h is included after each section define in order to set the current 
*          memory section as defined by AUTOSAR.
*
* @section PORT_C_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_C_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported for external 
*          identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_C_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
*          functions at file scope shall have internal linkage unless external linkage is required. 
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section PORT_C_REF_5
*          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of
*          pointer arithmetic. This violation is due to the use of pointer arithematic, to access 
*          the channel parameters, the indexing of the pointer is taken care and hence the 
*          unintended memory location will not be accessed.
*
* @section PORT_C_REF_6
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
*          accessed from within a single function.
*          These objects are used in various parts of the code.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port.h"

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

#include "Port_Ipw.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
*/
#define PORT_VENDOR_ID_C                    43

/** @violates @ref PORT_C_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MAJOR_VERSION_C     4

/** @violates @ref PORT_C_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_MINOR_VERSION_C     2

/** @violates @ref PORT_C_REF_3 The used compilers use more than 31 chars for identifiers. */
#define PORT_AR_RELEASE_REVISION_VERSION_C  2

#define PORT_SW_MAJOR_VERSION_C             1
#define PORT_SW_MINOR_VERSION_C             0
#define PORT_SW_PATCH_VERSION_C             1


/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if source file and Port header file are of the same vendor */
#if (PORT_VENDOR_ID_C != PORT_VENDOR_ID)
    #error "Port.c and Port.h have different vendor ids"
#endif

/* Check if source file and Port header file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port.c and Port.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port.c and Port.h are different"
#endif

/* Check if source file and Port_Ipw.h file are of the same vendor */
#if (PORT_VENDOR_ID_C != PORT_VENDOR_ID_IPW_H)
    #error "Port.c and Port_Ipw.h have different vendor ids"
#endif

/* Check if the source file and Port_Ipw.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_C    != PORT_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_MINOR_VERSION_C    != PORT_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (PORT_AR_RELEASE_REVISION_VERSION_C != PORT_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
    #error "AutoSar Version Numbers of Port.c and Port_Ipw.h are different"
#endif

/* Check if source file and Port header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_C != PORT_SW_MAJOR_VERSION_IPW_H) || \
     (PORT_SW_MINOR_VERSION_C != PORT_SW_MINOR_VERSION_IPW_H) || \
     (PORT_SW_PATCH_VERSION_C != PORT_SW_PATCH_VERSION_IPW_H)    \
    )
    #error "Software Version Numbers of Port.c and Port_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the source file and Det.h file are of the same Autosar version */
    #if (STD_ON == PORT_DEV_ERROR_DETECT)
        #if ((PORT_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (PORT_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Port.c and Det.h are different"
        #endif
    #endif
#endif

/*=================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"

#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
/** @violates @ref PORT_C_REF_6 Objects shall be defined at block scope */
extern CONST(Port_ConfigType, Port_CONST) Port_PBCfgVariantPredefined; 
#endif

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before "#include".*/
/** @violates @ref PORT_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/
#define PORT_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include'.*/
/** @violates @ref PORT_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"

/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
P2CONST(Port_ConfigType, PORT_VAR, PORT_APPL_CONST) Port_pConfig = NULL_PTR;

#define PORT_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include'.*/
/** @violates @ref PORT_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL FUNCTIONS
=================================================================================================*/

#define PORT_START_SEC_CODE
/** @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include'.*/
/** @violates @ref PORT_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"


/*=================================================================================================
*                                      GLOBAL FUNCTIONS
=================================================================================================*/

/**
* @brief   Initializes the Port Driver module.
* @details The function @p Port_Init() will initialize ALL ports and port pins
*          with the configuration set pointed to by the parameter @p pConfigPtr.
* @post    Port_Init() must be called before all other Port Driver module's functions
*          otherwise no operation can occur on the MCU ports and port pins.
*
* @param[in] ConfigPtr     A pointer to the structure which contains
*                          initialization parameters.
*
* @implements Port_Init_Activity
*
* @api
*/
/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) ConfigPtr 
)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
#if (STD_OFF == PORT_PRECOMPILE_SUPPORT)
    if (NULL_PTR == ConfigPtr)
#else /*(STD_ON == PORT_PRECOMPILE_SUPPORT) */
    if (NULL_PTR != ConfigPtr)
#endif /* (STD_ON == PORT_PRECOMPILE_SUPPORT) */
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, PORT_INSTANCE_ID, (uint8)PORT_INIT_ID, (uint8)PORT_E_INIT_FAILED);
    }
    else
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    {

#if (STD_ON == PORT_PRECOMPILE_SUPPORT)
        ConfigPtr = &Port_PBCfgVariantPredefined;
#endif

        Port_Ipw_Init(ConfigPtr);

        /*  Save configuration pointer in global variable */
        Port_pConfig = ConfigPtr;
    }
}

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/**
* @brief   Sets the port pin direction.
* @details The function @p Port_SetPinDirection() will set the port pin direction
*          during runtime.
* @pre     @p Port_Init() must have been called first. In order to change the
*          pin direction the PortPinDirectionChangeable flag must have been set
*          to @p TRUE.
*
* @param[in] Pin            Pin ID number.
* @param[in] Direction     Port Pin direction.
*
* @implements Port_SetPinDirection_Activity
* @api
*/
/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_SetPinDirection
(
    VAR(Port_PinType,           AUTOMATIC) Pin,
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction
)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* Variable used to store current error status */
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_NOT_OK;

    /* Check if Port module is initialized */
    if (NULL_PTR == Port_pConfig)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_UNINIT);
    }
    /* Check port pin validity */
    else if (Pin >= (Port_PinType)Port_pConfig->u16NumPins)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_PARAM_PIN);
    }
    else
#endif /* PORT_DEV_ERROR_DETECT */
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        ErrStatus = Port_Ipw_SetPinDirection(Pin, (Port_PinDirectionType)Direction, Port_pConfig);
#else
        (void)Port_Ipw_SetPinDirection(Pin, (Port_PinDirectionType)Direction, Port_pConfig);
#endif
                        
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        if ((Std_ReturnType)E_NOT_OK == ErrStatus)
        {
            (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINDIRECTION_ID, (uint8)PORT_E_DIRECTION_UNCHANGEABLE);
        }
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    }
}
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) */


#if defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API)
/**
* @brief   Sets the direction of 2 pins.
* @details The function @p Port_Set2PinsDirection() will set the port pins direction
*          during runtime.
* @pre     @p Port_Init() must have been called first. In order to change the
*          pin direction the PortPinDirectionChangeable flag must have been set
*          to @p TRUE for both pins.
*
* @param[in] Pin1          Pin 1 ID number.
* @param[in] Pin2          Pin 2 ID number.
* @param[in] Direction     Port Pin direction.
*
* Port_Set2PinsDirection_Activity
* @api
*/
/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_Set2PinsDirection
(
    VAR(Port_PinType,           AUTOMATIC) Pin1,
    VAR(Port_PinType,           AUTOMATIC) Pin2,
    VAR(Port_PinDirectionType,  AUTOMATIC) Direction
)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* Variable used to store current error status */
    VAR(Std_ReturnType, AUTOMATIC) ErrStatus = (Std_ReturnType)E_NOT_OK;

    /* Check if Port module is initialized */
    if (NULL_PTR == Port_pConfig)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SET2PINSDIRECTION_ID, (uint8)PORT_E_UNINIT);
    }
    /* Check port pin validity */
    else if ((Pin1 >= (Port_PinType)Port_pConfig->u16NumPins) || (Pin2 >= (Port_PinType)Port_pConfig->u16NumPins))
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SET2PINSDIRECTION_ID, (uint8)PORT_E_PARAM_PIN);
    }
    else
#endif /* PORT_DEV_ERROR_DETECT */
    {
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        ErrStatus = Port_Ipw_Set2PinsDirection(Pin1, Pin2, (Port_PinDirectionType)Direction, Port_pConfig);
#else
        (void)Port_Ipw_Set2PinsDirection(Pin1, Pin2, (Port_PinDirectionType)Direction, Port_pConfig);
#endif
                        
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        if ((Std_ReturnType)E_NOT_OK == ErrStatus)
        {
            (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SET2PINSDIRECTION_ID, (uint8)PORT_E_DIRECTION_UNCHANGEABLE);
        }
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    }
}
#endif /* defined(PORT_SET_2_PINS_DIRECTION_API) && (STD_ON == PORT_SET_2_PINS_DIRECTION_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief   Sets the port pin mode.
* @details The function @p Port_SetPinMode() will set the port pin mode of the
*          referenced pin during runtime.
* @pre     @p Port_Init() must have been called first.
*
* @param[in] Pin       Pin ID number.
* @param[in] Mode      New Port Pin mode to be set on port pin.
*
* @implements  Port_SetPinMode_Activity
* @api
*/
/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_SetPinMode
( 
    VAR(Port_PinType,     AUTOMATIC) Pin,
    VAR(Port_PinModeType, AUTOMATIC) Mode
)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    VAR(uint8, AUTOMATIC) u8PinModeError = (uint8)0U;

    /* Check if port is initialized */
    if (NULL_PTR == Port_pConfig)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_UNINIT);
    }
    /* Check port pin validity */
    else if (Pin >= (Port_PinType)Port_pConfig->u16NumPins)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_PIN);
    }
    /* Check port pin mode Unchangeable */
    /** @violates @ref PORT_C_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
    else if((boolean)FALSE == (boolean) Port_pConfig->pUsedPadConfig[Pin].bMC)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_MODE_UNCHANGEABLE);
    }
    else
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    {
        /* Sets the port pin direction */
#if (STD_ON == PORT_DEV_ERROR_DETECT)
        u8PinModeError = (uint8)Port_Ipw_SetPinMode(Pin, Mode, Port_pConfig);
#else
        (void)Port_Ipw_SetPinMode(Pin, Mode, Port_pConfig);
#endif

#if (STD_ON == PORT_DEV_ERROR_DETECT)
        if (PORT_E_PARAM_INVALID_MODE == u8PinModeError)
        {
            (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_SETPINMODE_ID, (uint8)PORT_E_PARAM_INVALID_MODE);
        }
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    }
}
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

/**
* @brief   Refreshes port direction.
* @details This function will refresh the direction of all configured ports to
*          the configured direction.
*          The PORT driver will exclude from refreshing those port pins that
*          are configured as "pin direction changeable during runtime".
* @pre     @p Port_Init() must have been called first.
*
* @implements Port_RefreshPortDirection_Activity
*
* @api
*/
/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_RefreshPortDirection( void )
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* Check if Port module is initialized */
    if (NULL_PTR == Port_pConfig)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_REFRESHPINDIRECTION_ID, (uint8)PORT_E_UNINIT);
    }
    else
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    {
        Port_Ipw_RefreshPortDirection(Port_pConfig);
    }
}


#if  (STD_ON == PORT_VERSION_INFO_API)
/**
* @brief   Returns the version information of this module.
* @details The function Port_GetVersionInfo() will return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*
* @param[in,out] versioninfo      Pointer to where to store the version
*                                  information of this module.
*
*
* @implements Port_GetVersionInfo_Activity
* @api
*/
/**
* @violates @ref PORT_C_REF_4 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, PORT_CODE) Port_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, PORT_APPL_DATA) versioninfo
)
{
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        (void)Det_ReportError((uint16)PORT_MODULE_ID, (uint8)PORT_INSTANCE_ID, (uint8)PORT_GETVERSIONINFO_ID, (uint8)PORT_E_PARAM_POINTER);
    }
    else
#endif /* (STD_ON == PORT_DEV_ERROR_DETECT) */
    {
        (versioninfo)->vendorID         = (uint16)PORT_VENDOR_ID;
        (versioninfo)->moduleID         = (uint16)PORT_MODULE_ID;
        (versioninfo)->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif /* (STD_ON == PORT_VERSION_INFO_API) */


#define PORT_STOP_SEC_CODE
/** @violates @ref PORT_C_REF_1 Only preprocessor statements and comments before '#include'.*/
/** @violates @ref PORT_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Port_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
