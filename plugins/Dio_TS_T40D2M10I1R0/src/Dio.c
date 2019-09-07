/**
 *   @file    Dio.c
 *   @implements        Dio_HLD_unit
 *   @version 1.0.1
 *
 *   @brief   AUTOSAR Dio high level code.
 *   @details This file contains the Autosar DIO driver high level code.
 *
 *   @addtogroup DIO_MODULE
 *   @{
 */
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : GPIO
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_C_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section Dio_C_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. 
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Dio_C_REF_3
*          Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of
*          pointer arithmetic. This violation is due to range checks that should be performed
*          on pointers of the same type but which do not belong to an array.
*
* @section Dio_C_REF_4
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. MemMap.h is included after each section define
*          in order to set the current memory section as defined by AUTOSAR.
*
* @section Dio_C_REF_5
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section Dio_C_REF_6
*          Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
*          This macro computes the address of any register by using the hardware offset of the controller. 
*          The address calculated as an unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Dio_C_REF_7
*          Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed from
*          within a single function. These objects are used in various parts of the code.
*
* @section Dio_C_REF_8
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type 
*          and an integral type. The cast is used to access memory mapped registers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for identifiers.
*/


/**
 *   @file    Dio.c
 *   @implements        Dio.c_Artifact
 **/
/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Dio_EnvCfg.h"
#include "Dio.h"
#include "Dio_Ipw.h"

#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #include "Det.h"
#endif

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID_C                      43
#define DIO_AR_RELEASE_MAJOR_VERSION_C       4
#define DIO_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Dio_C_REF_1 The used compilers use more than 31 chars for identifiers. */
#define DIO_AR_RELEASE_REVISION_VERSION_C    2
#define DIO_SW_MAJOR_VERSION_C               1
#define DIO_SW_MINOR_VERSION_C               0
#define DIO_SW_PATCH_VERSION_C               1

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Dio_EnvCfg.h version check start */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_C != DIO_ENVCFG_AR_RELEASE_MAJOR_VERSION)  ||   \
     (DIO_AR_RELEASE_MINOR_VERSION_C != DIO_ENVCFG_AR_RELEASE_MINOR_VERSION)  ||   \
     (DIO_AR_RELEASE_REVISION_VERSION_C != DIO_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AUTOSAR Version Numbers of Dio.c and Dio_EnvCfg.h are different"
#endif

#if ((DIO_SW_MAJOR_VERSION_C != DIO_ENVCFG_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_C != DIO_ENVCFG_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_C != DIO_ENVCFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dio.c and Dio_EnvCfg.h are different"
#endif

#if (DIO_VENDOR_ID_C != DIO_ENVCFG_VENDOR_ID)
    #error "VENDOR ID for Dio.c and Dio_EnvCfg.h is different"
#endif
/* Dio_EnvCfg.h version check end */

/* Check if current file and DIO header file are of the same vendor.*/
#if (DIO_VENDOR_ID_C != DIO_VENDOR_ID)
    #error "Dio.c and Dio.h have different vendor ids"
#endif

/* Check if current file and DIO header file are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_C    != DIO_AR_RELEASE_MAJOR_VERSION) || \
     (DIO_AR_RELEASE_MINOR_VERSION_C    != DIO_AR_RELEASE_MINOR_VERSION) || \
     (DIO_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dio.c and Dio.h are different"
#endif

/* Check if current file and DIO header file are of the same Software version.*/
#if ((DIO_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dio.c and Dio.h are different"
#endif

/* Check if current file and DET header file are of the same version.*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == DIO_DEV_ERROR_DETECT)
        #if ((DIO_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (DIO_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of Dio.c and Det.h are different"
        #endif
    #endif
#endif

/* Dio_Ipw.h version check start */
#if ((DIO_AR_RELEASE_MAJOR_VERSION_C != DIO_AR_RELEASE_MAJOR_VERSION_IPW)   || \
     (DIO_AR_RELEASE_MINOR_VERSION_C != DIO_AR_RELEASE_MINOR_VERSION_IPW)   || \
     (DIO_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION_IPW)\
    )
    #error "AUTOSAR Version Numbers of Dio.c and Dio_Ipw.h are different"
#endif

#if ((DIO_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION_IPW) || \
     (DIO_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION_IPW) || \
     (DIO_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION_IPW)    \
    )
    #error "Software Version Numbers of Dio.c and Dio_Ipw.h are different"
#endif

#if (DIO_VENDOR_ID_C != DIO_VENDOR_ID_IPW)
    #error "VENDOR ID for Dio.c and Dio_Ipw.h is different"
#endif
/* Dio_Ipw.h version check end */

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

#if (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT)) 

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Dio_C_REF_2 Precautions to prevent the contents of a header file being included twice */
#include "Dio_MemMap.h"

/* Local Variable for storing the generated Dio configuration */
/** @violates @ref Dio_C_REF_7 Objects shall be defined at block scope if they are only accessed from within a single function.*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
extern CONST(Dio_ConfigType, DIO_CONST) Dio_ConfigPC;

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Dio_C_REF_2 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Dio_C_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Dio_MemMap.h"

#endif /* (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))  */

/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
#define DIO_START_SEC_CODE
/** @violates @ref Dio_C_REF_2 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Dio_C_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Dio_MemMap.h"

#if (STD_ON == DIO_VALIDATE_PARAMS)
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelLevel
(
    VAR(Dio_LevelType, AUTOMATIC) Level
);

LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelForWrite
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(uint8,           AUTOMATIC) u8ServiceId
);
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelForRead
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(uint8,           AUTOMATIC) u8ServiceId
);

LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidatePortForWrite
(
    VAR(Dio_PortType,   AUTOMATIC) PortId,
    VAR(uint8,          AUTOMATIC) u8ServiceId
);
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidatePortForRead
(
    VAR(Dio_PortType,   AUTOMATIC) PortId,
    VAR(uint8,          AUTOMATIC) u8ServiceId
);

LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelGroupForWrite
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroup,
    VAR    (uint8,                AUTOMATIC)                 u8ServiceId
);
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelGroupForRead
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroup,
    VAR    (uint8,                AUTOMATIC)                 u8ServiceId
);
#endif /* (STD_ON == DIO_VALIDATE_PARAMS) */

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

#if (STD_ON == DIO_VALIDATE_PARAMS)
/**
 * @brief       DIO channel level validation.
 * @details     Checks if the specified channel level is valid (either STD_HIGH or STD_LOW).
 *
 * @param[in]   Level   channel level parameter to be checked
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidateChannelLevel_Activity
 *
 * */
 /** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelLevel
(
    VAR(Dio_LevelType, AUTOMATIC) Level
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    if (((Dio_LevelType)STD_HIGH == Level) || ((Dio_LevelType)STD_LOW == Level))
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITECHANNEL_ID, DIO_E_PARAM_LEVEL);
    }

    return Valid;
}
#endif

#if (STD_ON == DIO_VALIDATE_PARAMS)
/**
 * @brief       DIO channel availability check.
 * @details     Checks if the specified channel is implemented in the current platform package.
 *
 * @param[in]   ChannelId   Identifier of the channel to be checked.
 *              u8ServiceId The service id of the caller function
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidateChannelForWrite_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelForWrite
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(uint8,           AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    if ((((Dio_ChannelType)(ChannelId) < DIO_NUM_CHANNELS_U16)) &&
        ((Dio_PortLevelType)0 != (Dio_aAvailablePinsForWrite[ (ChannelId >> DIO_PORTID_SHIFT_U8 ) ] &
                                     (DIO_CHECK_CHANNEL_VALIDITY((uint16)ChannelId))
                                 )
        )
       )
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, u8ServiceId, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    return Valid;
}

/**
 * @brief       DIO channel availability check.
 * @details     Checks if the specified channel is implemented in the current platform package.
 *
 * @param[in]   ChannelId   Identifier of the channel to be checked.
 *              u8ServiceId The service id of the caller function
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidateChannelForRead_Activity
 *
 * */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelForRead
(
    VAR(Dio_ChannelType, AUTOMATIC) ChannelId,
    VAR(uint8,           AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    if ((((Dio_ChannelType)(ChannelId) < DIO_NUM_CHANNELS_U16)) &&
        ((Dio_PortLevelType)0 != (Dio_aAvailablePinsForRead[ (ChannelId >> DIO_PORTID_SHIFT_U8 ) ] &
                                     (DIO_CHECK_CHANNEL_VALIDITY((uint16)ChannelId))
                                 )
        )
       )
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, u8ServiceId, DIO_E_PARAM_INVALID_CHANNEL_ID);
    }

    return Valid;
}
#endif

 #if (STD_ON == DIO_VALIDATE_PARAMS)
/**
 * @brief       DIO port availability check.
 * @details     Checks if the specified port is implemented in the current platform package.
 *
 * @param[in]   PortId      Identifier of the port to be checked.
 *              u8ServiceId The service id of the caller function
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidatePortForWrite_Activity
 *
 * */
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidatePortForWrite
(
    VAR(Dio_PortType, AUTOMATIC) PortId,
    VAR(uint8,        AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    if (((uint8)(PortId) < DIO_NUM_PORTS_U16) &&
        (Dio_aAvailablePinsForWrite[(uint8)(PortId)] != DIO_NO_AVAILABLE_CHANNELS_U16)
       )
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, u8ServiceId, DIO_E_PARAM_INVALID_PORT_ID);
    }

    return Valid;
}

/**
 * @brief       DIO port availability check.
 * @details     Checks if the specified port is implemented in the current platform package.
 *
 * @param[in]   PortId      Identifier of the port to be checked.
 *              u8ServiceId The service id of the caller function
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidatePortForRead_Activity
 *
 * */
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidatePortForRead
(
    VAR(Dio_PortType, AUTOMATIC) PortId,
    VAR(uint8,        AUTOMATIC) u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    if (((uint8)(PortId) < DIO_NUM_PORTS_U16) &&
        (Dio_aAvailablePinsForRead[(uint8)(PortId)] != DIO_NO_AVAILABLE_CHANNELS_U16)
       )
    {
        Valid = ( Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, u8ServiceId, DIO_E_PARAM_INVALID_PORT_ID);
    }

    return Valid;
}
#endif


 #if (STD_ON == DIO_VALIDATE_PARAMS)
/**
 * @brief       DIO channel group validity check.
 * @details     Checks if the parameter matches one of the channel group pointers in
 *              the configuration.
 *
 * @param[in]   pChannelGroup  The channel group to be validated.
 *              u8ServiceId    The service id of the caller function
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidateChannelGroupForWrite_Activity
 *
 * */
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelGroupForWrite
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroup,
    VAR    (uint8,                AUTOMATIC)                 u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    /* Compiler_Warning: Pointer to channel group is converted to unsigned long in order for it to
                          be compared with the boundaries of the channel group list. */
    /** @violates @ref Dio_C_REF_6 Cast from unsigned long to pointer. */
    /** @violates @ref Dio_C_REF_3 Array indexing shall be the only allowed form of pointer arithmetic */
    /** @violates @ref Dio_C_REF_8 A cast should not be performed between a pointer type and an integral type. */
    if ((((pointerSizeType)(pChannelGroup)) >= ((pointerSizeType)Dio_ConfigPC.pChannelGroupList))                                  &&  \
        (((pointerSizeType)(pChannelGroup)) < (pointerSizeType)(Dio_ConfigPC.pChannelGroupList + Dio_ConfigPC.u8NumChannelGroups)) &&  \
        ((uint8)(pChannelGroup->port) < DIO_NUM_PORTS_U16)                                                       &&  \
        (Dio_aAvailablePinsForWrite[(uint8)(pChannelGroup->port)] != DIO_NO_AVAILABLE_CHANNELS_U16)              &&  \
        ((uint8)(pChannelGroup->u8offset) <= DIO_MAX_VALID_OFFSET_U8)
       )
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, u8ServiceId, DIO_E_PARAM_INVALID_GROUP_ID);
    }

    return Valid;
}

/**
 * @brief       DIO channel group validity check.
 * @details     Checks if the parameter matches one of the channel group pointers in
 *              the configuration.
 *
 * @param[in]   pChannelGroup  The channel group to be validated.
 *              u8ServiceId    The service id of the caller function
 *
 * @return      Std_ReturnType
 *
 * @api
 *
 * @implements  Dio_ValidateChannelGroupForRead_Activity
 *
 * */
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
LOCAL_INLINE FUNC(Std_ReturnType, DIO_CODE) Dio_ValidateChannelGroupForRead
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroup,
    VAR    (uint8,                AUTOMATIC)                 u8ServiceId
)
{
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_NOT_OK;

    /* Compiler_Warning: Pointer to channel group is converted to unsigned long in order for it to
                          be compared with the boundaries of the channel group list. */
    /** @violates @ref Dio_C_REF_6 Cast from unsigned long to pointer. */
    /** @violates @ref Dio_C_REF_3 Array indexing shall be the only allowed form of pointer arithmetic */
    /** @violates @ref Dio_C_REF_8 A cast should not be performed between a pointer type and an integral type. */
    if ((((pointerSizeType)(pChannelGroup)) >= ((pointerSizeType)Dio_ConfigPC.pChannelGroupList))                                  &&  \
        (((pointerSizeType)(pChannelGroup)) < (pointerSizeType)(Dio_ConfigPC.pChannelGroupList + Dio_ConfigPC.u8NumChannelGroups)) &&  \
        ((uint8)(pChannelGroup->port) < DIO_NUM_PORTS_U16)                                                       &&  \
        (Dio_aAvailablePinsForRead[(uint8)(pChannelGroup->port)] != DIO_NO_AVAILABLE_CHANNELS_U16)               &&  \
        ((uint8)(pChannelGroup->u8offset) <= DIO_MAX_VALID_OFFSET_U8)
       )
    {
        Valid = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, u8ServiceId, DIO_E_PARAM_INVALID_GROUP_ID);
    }

    return Valid;
}
#endif

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

/*================================================================================================*/

#if (STD_ON == DIO_VERSION_INFO_API)
/*================================================================================================*/
/**
* @brief          Service to get the version information of this module.
* @details        The @p Dio_GetVersionInfo() function shall return the version
*                 information of this module. The version information includes:
*                 - Module Id.
*                 - Vendor Id.
*                 - Vendor specific version numbers.
*                 .
*
* @param[in,out]  VersionInfo Pointer to where to store the version
*                             information of this module.
*
* @pre            This function can be used only if @p DIO_VERSION_INFO_API
*                 has been enabled.
*
* @implements     Dio_GetVersionInfo_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(void, DIO_CODE) Dio_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) VersionInfo
)
{
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GETVERSIONINFO_ID, DIO_E_PARAM_POINTER);
    }
    else
#endif /* (STD_ON == DIO_DEV_ERROR_DETECT) */
    {
        VersionInfo->vendorID         = (uint16)DIO_VENDOR_ID;
        VersionInfo->moduleID         = (uint16)DIO_MODULE_ID;
        VersionInfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
    }
}
#endif /* (STD_ON == DIO_DEV_ERROR_DETECT) */

/*================================================================================================*/
/**
* @brief          Returns the value of the specified DIO channel.
* @details        This function returns the value of the specified DIO channel.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*
* @implements     Dio_ReadChannel_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) ChannelLevel = (Dio_LevelType)STD_LOW;

#if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidateChannelForRead(ChannelId, DIO_READCHANNEL_ID);
    
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
        ChannelLevel = Dio_Ipw_ReadChannel(ChannelId);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif

    return ChannelLevel;
}

/*================================================================================================*/
/**
* @brief          Sets the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall set the specified level on the
*                 specified channel. If the specified channel is configured
*                 as an input channel, this function shall have no influence
*                 on the physical output and on the result of the next read
*                 service.
*
* @param[in]      ChannelId   Specifies the required channel id.
* @param[in]      Level       Specifies the channel desired level.
*
* @implements     Dio_WriteChannel_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType,  AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,    AUTOMATIC) Level
)
{
#if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidateChannelForWrite(ChannelId, DIO_WRITECHANNEL_ID);
    
    if ((Std_ReturnType) E_OK == Valid)
    {
        Valid = Dio_ValidateChannelLevel(Level);
        if ((Std_ReturnType) E_OK == Valid)
        {
#endif
            Dio_Ipw_WriteChannel(ChannelId, Level);
#if (STD_ON == DIO_VALIDATE_PARAMS)
        }
    }
#endif

}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/*================================================================================================*/
/**
* @brief          Inverts the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall invert the level of the specified
*                 channel. If the specified channel is configured as an
*                 input channel, this function shall have no influence
*                 on the physical output and on the result of the next
*                 read service.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*
* @pre            This function can be used only if @p DIO_FLIP_CHANNEL_API
*                 has been enabled.
*
* @implements     Dio_FlipChannel_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
)
{
    VAR(Dio_LevelType, AUTOMATIC) ChannelLevel = (Dio_LevelType)STD_LOW;

#if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidateChannelForWrite(ChannelId, DIO_FLIPCHANNEL_ID);
    
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
        ChannelLevel = Dio_Ipw_FlipChannel(ChannelId);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif

   return ChannelLevel;
}
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

/*================================================================================================*/
/**
* @brief        Returns the level of all channels of specified port.
* @details      This function will return the level of all channels
*               belonging to the specified port.
*
* @param[in]    PortId      Specifies the required port id.
*
* @return       Levels of all channels of specified port.
*
* @implements   Dio_ReadPort_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) PortLevel = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidatePortForRead(PortId, DIO_READPORT_ID);
    
    if ((Std_ReturnType) E_OK == Valid)
    {
#endif
        PortLevel = Dio_Ipw_ReadPort(PortId);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif

    return PortLevel;
}

/*================================================================================================*/
/**
* @brief          Sets the value of a port.
* @details        This function will set the specified value on the specified
*                 port.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
*
* @implements     Dio_WritePort_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
)
{
 #if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidatePortForWrite(PortId, DIO_WRITEPORT_ID);
    
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
        Dio_Ipw_WritePort(PortId, Level);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif
}

/*================================================================================================*/
/**
* @brief          This service reads a subset of the adjoining bits of a port.
* @details        This function will read a subset of adjoining bits of a
*                 port (channel group).
*
* @param[in]      ChannelGroupIdPtr Pointer to the channel group.
*
* @return         The channel group levels.
*
* @implements     Dio_ReadChannelGroup_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
)
{
    VAR(Dio_PortLevelType, AUTOMATIC) PortLevel = (Dio_PortLevelType)STD_LOW;

#if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType,AUTOMATIC) Valid = Dio_ValidateChannelGroupForRead(ChannelGroupIdPtr, DIO_READCHANNELGROUP_ID);
    
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
        PortLevel = Dio_Ipw_ReadChannelGroup(ChannelGroupIdPtr);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif

    return PortLevel;
}

/*================================================================================================*/
/**
* @brief          Sets a subset of the adjoining bits of a port to the
*                 specified levels.
* @details        This function will set a subset of adjoining bits of a port
*                 (channel group) to the specified levels without changing
*                 the remaining channels of the port and channels that
*                 are configured as input.
*                 This function will do the masking of the channels and will
*                 do the shifting so that the values written by the function
*                 are aligned to the LSB.
*
* @param[in]      ChannelGroupIdPtr Pointer to the channel group.
* @param[in]      Level       Desired levels for the channel group.
*
* @implements     Dio_WriteChannelGroup_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
)
{
 #if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidateChannelGroupForWrite(ChannelGroupIdPtr, DIO_WRITECHANNELGROUP_ID);
    
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
        Dio_Ipw_WriteChannelGroup(ChannelGroupIdPtr, Level);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif
}

#if (STD_ON == DIO_MASKEDWRITEPORT_API)
/*================================================================================================*/
/**
* @brief          DIO Mask write port using mask.
* @details        Writes a DIO port with masked value.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
* @param[in]      Mask        Specifies the Mask value of the port.
*
* @pre            This function can be used only if @p DIO_MASKEDWRITEPORT_API
*                 has been enabled.
*
* @implements     Dio_MaskedWritePort_Activity
*
* @api
*/
/** @violates @ref Dio_C_REF_5 This warning appears when defining functions or objects that will be used by the upper layers. */
FUNC(void, DIO_CODE) Dio_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
)
{
#if (STD_ON == DIO_VALIDATE_PARAMS)
    VAR(Std_ReturnType, AUTOMATIC) Valid = Dio_ValidatePortForWrite(PortId, DIO_MASKEDWRITEPORT_ID);
    
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
        Dio_Ipw_MaskedWritePort(PortId, Level, Mask);
#if (STD_ON == DIO_VALIDATE_PARAMS)
    }
#endif
}
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) */

#define DIO_STOP_SEC_CODE
/** @violates @ref Dio_C_REF_2 Precautions to prevent the contents of a header file being included twice */
/** @violates @ref Dio_C_REF_4 Only preprocessor statements and comments before '#include'.*/
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
