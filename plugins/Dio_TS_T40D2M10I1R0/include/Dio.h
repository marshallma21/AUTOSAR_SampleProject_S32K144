/**
*   @file    Dio.h
*   @implements Dio.h_Artifact
*   @version 1.0.1
*
*   @brief   AUTOSAR Dio high level header.
*   @details DIO driver header file, containing the Autosar API specification and other variables
*              and functions that are exported by the DIO driver.
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

#ifndef DIO_H
#define DIO_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_H_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to 
*          prevent the contents of a header file being included twice.
*          This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
* 
* @section Dio_H_REF_2
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
*          that 31 character significance and case sensitivity are supported forexternal identifiers. 
*          The used compilers/linkers allow more than 31 characters significance for external identifiers. 
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Std_Types.h"
#include "Mcal.h"
#include "Dio_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID                    43
#define DIO_MODULE_ID                    120
#define DIO_AR_RELEASE_MAJOR_VERSION     4
#define DIO_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref Dio_H_REF_2 The used compilers use more than 31 chars for identifiers. */
#define DIO_AR_RELEASE_REVISION_VERSION  2
#define DIO_SW_MAJOR_VERSION             1
#define DIO_SW_MINOR_VERSION             0
#define DIO_SW_PATCH_VERSION             1


/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((DIO_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (DIO_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Dio.h and Std_Types.h are different"
    #endif
    /* Check if source file and Mcal.h header file are of the same Autosar version */
    #if ((DIO_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (DIO_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Dio.h and Mcal.h are different"
    #endif
#endif
 
/* Check if current file and DIO configuration header file are of the
   same vendor.*/
#if (DIO_VENDOR_ID != DIO_VENDOR_ID_CFG)
  #error "Dio.h and Dio_Cfg.h have different vendor ids"
#endif

/* Check if current file and DIO configuration header file are of the
   same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION    != DIO_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_MINOR_VERSION    != DIO_AR_RELEASE_MINOR_VERSION_CFG) || \
     (DIO_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif

/* Check if current file and DIO configuration header file are of the
   same software version.*/
#if ((DIO_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION_CFG) || \
     (DIO_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION_CFG) || \
     (DIO_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Dio.h and Dio_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/**
* @brief          Invalid channel name requested.
*
* @implements     Dio_ErrorCodes_define
*
* @api
*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID          ((uint8)0x0A)


/**
* @brief          API service called with "NULL pointer" parameter.
*
* @implements     Dio_ErrorCodes_define
*
* @api
*/
#define DIO_E_PARAM_CONFIG                      ((uint8)0x10)

/**
* @brief          Invalid port name requested.
*
* @implements     Dio_ErrorCodes_define
*
* @api
*/
#define DIO_E_PARAM_INVALID_PORT_ID             ((uint8)0x14)

/**
* @brief          Invalid ChannelGroup id passed.
*
* @implements     Dio_ErrorCodes_define
*
* @api
*/
#define DIO_E_PARAM_INVALID_GROUP_ID            ((uint8)0x1F)

/**
* @brief          API service called with a NULL pointer.
* @details        In case of this error, the API service shall return
*                 immediately without any further action, beside reporting
*                 this development error.
*
* @implements     Dio_ErrorCodes_define
*
* @api
*/
#define DIO_E_PARAM_POINTER                     ((uint8)0x20)

/**
* @brief          API service called with invalid channel level value.
* @details        In case of this error, the API service shall return
*                 immediately without any further action, beside reporting
*                 this development error.
*
* @implements     Dio_ErrorCodes_define
*
* @api
*/
#define DIO_E_PARAM_LEVEL                       ((uint8)0x21)


/**
* @brief          API service ID for @p Dio_ReadChannel() function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_READCHANNEL_ID                      ((uint8)0x00)

/**
* @brief          API service ID for @p Dio_WriteChannel() function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/

#define DIO_WRITECHANNEL_ID                     ((uint8)0x01)

/**
* @brief          API service ID for @p Dio_FlipChannel() function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_FLIPCHANNEL_ID                      ((uint8)0x11)

/**
* @brief          API service ID for @p Dio_ReadPort() function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_READPORT_ID                         ((uint8)0x02)

/**
* @brief          API service ID for @p Dio_WritePort() function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_WRITEPORT_ID                        ((uint8)0x03)

/**
* @brief          API service ID for @p Dio_ReadChannel() Group function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_READCHANNELGROUP_ID                 ((uint8)0x04)

/**
* @brief          API service ID for @p Dio_WriteChannel() Group function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_WRITECHANNELGROUP_ID                ((uint8)0x05)

/**
* @brief          API service ID for DIO Get Version() Info function.
* @details        Parameters used when raising an error/exception.
*
* @api
*/
#define DIO_GETVERSIONINFO_ID                   ((uint8)0x12)

/**
* @brief          API service ID for @p Dio_MaskedWritePort() function.
* @details        Parameters used when raising an error/exception.
*
* @api
*
*/
#define DIO_MASKEDWRITEPORT_ID                  ((uint8)0x20)

/**
* @brief          Instance ID of the Dio driver.
*
* @implements     .
*
* @api
*/
#define DIO_INSTANCE_ID                         ((uint8)0x00)


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

#ifdef CPU_TYPE
#if (CPU_TYPE == CPU_TYPE_64)
/** 
* @brief size of pointer type. on CPU_TYPE_32, the size is 32bits.
*/
typedef uint64 pointerSizeType;

#elif (CPU_TYPE == CPU_TYPE_32)
/** 
* @brief size of pointer type. on CPU_TYPE_32, the size is 32bits.
*/
typedef uint32 pointerSizeType;
    
#elif (CPU_TYPE == CPU_TYPE_16)
/** 
* @brief size of pointer type. on CPU_TYPE_16, the size is 16bits.
*/
typedef uint16 pointerSizeType;
#endif
#endif

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#define DIO_START_SEC_CODE
/** @violates @ref Dio_H_REF_1 Precautions to prevent the contents of a header file being included twice */
#include "Dio_MemMap.h"


#if (STD_ON == DIO_VERSION_INFO_API)
FUNC(void, DIO_CODE) Dio_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, DIO_APPL_DATA) VersionInfo
);
#endif /* (STD_ON == DIO_VERSION_INFO_API) */

FUNC(Dio_LevelType, DIO_CODE) Dio_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

FUNC(void, DIO_CODE) Dio_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,   AUTOMATIC) Level
);

#if (STD_ON == DIO_FLIP_CHANNEL_API)
FUNC(Dio_LevelType, DIO_CODE) Dio_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

FUNC(void, DIO_CODE) Dio_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

FUNC(Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup
(
  P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr
);

FUNC(void, DIO_CODE) Dio_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) ChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
);

#if (STD_ON == DIO_MASKEDWRITEPORT_API)
FUNC(void, DIO_CODE) Dio_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
);
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) */

#define DIO_STOP_SEC_CODE
/** @violates @ref Dio_H_REF_1 Precautions to prevent the contents of a header file being included twice */
#include "Dio_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* DIO_H */

/** @} */
