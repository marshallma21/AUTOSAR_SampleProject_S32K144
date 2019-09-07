/**
*   @file    I2c_LPI2C.h
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - Low level driver header file.
*   @details This file includes the function prototypes defined in the I2C low level driver for LPI2C.
*
*   @addtogroup I2C
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPI2C
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

#ifndef I2C_LPI2C_H
#define I2C_LPI2C_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section I2c_LPI2C_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions.
*
* @section I2c_LPI2C_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section I2c_LPI2C_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded
* by other preprocessor directives or comments. AUTOSAR imposes the specification of the
* sections in which certain parts of the driver must be placed.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "I2c_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           I2c_LPI2C.h
*/
#define I2C_LPI2C_VENDOR_ID                    43
#define I2C_LPI2C_AR_RELEASE_MAJOR_VERSION     4
#define I2C_LPI2C_AR_RELEASE_MINOR_VERSION     2
/**
* @violates @ref I2c_LPI2C_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_LPI2C_AR_RELEASE_REVISION_VERSION  2
#define I2C_LPI2C_SW_MAJOR_VERSION             1
#define I2C_LPI2C_SW_MINOR_VERSION             0
#define I2C_LPI2C_SW_PATCH_VERSION             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c_Types header file are of the same vendor */
#if (I2C_LPI2C_VENDOR_ID != I2C_TYPES_VENDOR_ID)
    #error "I2c_LPI2C.h and I2c_Types.h have different vendor ids"
#endif

/* Check if current file and I2c_Types.h header file are of the same Autosar version */
#if ((I2C_LPI2C_AR_RELEASE_MAJOR_VERSION    != I2C_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_LPI2C_AR_RELEASE_MINOR_VERSION    != I2C_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_LPI2C_AR_RELEASE_REVISION_VERSION != I2C_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_LPI2C.h and I2c_Types.h are different"
#endif
/* Check if current file and I2c_Types.h header file are of the same Software version */
#if ((I2C_LPI2C_SW_MAJOR_VERSION != I2C_TYPES_SW_MAJOR_VERSION) || \
     (I2C_LPI2C_SW_MINOR_VERSION != I2C_TYPES_SW_MINOR_VERSION) || \
     (I2C_LPI2C_SW_PATCH_VERSION != I2C_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of I2c_LPI2C.h and I2c_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
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

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define I2C_START_SEC_CODE
/**
* @violates @ref I2c_LPI2C_h_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


FUNC (void, I2C_CODE) I2c_LPI2C_MasterInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel);

FUNC (void, I2C_CODE) I2c_LPI2C_SlaveInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel);

FUNC (void, I2C_CODE) I2c_LPI2C_InitChannel(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(I2c_LPI2C_HwChannelConfigType, AUTOMATIC, I2C_APPL_CONST) pConfigPtr);

FUNC (void, I2C_CODE) I2c_LPI2C_DeInitChannel(CONST(uint8, AUTOMATIC) u8Channel);

FUNC(Std_ReturnType, I2C_CODE)  I2c_LPI2C_SyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequest);

FUNC(Std_ReturnType, I2C_CODE)  I2c_LPI2C_AsyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequest);

FUNC(void, I2C_CODE)  I2c_LPI2C_PrepareSlaveBuffer(
                                                    VAR(uint8, AUTOMATIC) u8Channel,
                                                    VAR(uint8, AUTOMATIC) u8NumberOfBytes,
                                                    P2VAR(I2c_DataType, AUTOMATIC, I2C_APPL_DATA) pDataBuffer
                                                  );

FUNC(void, I2C_CODE)  I2c_LPI2C_StartListening(VAR(uint8, AUTOMATIC) u8Channel);

FUNC (I2c_StatusType, I2C_CODE) I2c_LPI2C_GetStatus(CONST(uint8, AUTOMATIC) u8Channel);

#if (STD_ON == I2C_DMA_USED)
    #if defined(LPI2C_0)
FUNC (void, I2C_CODE) I2c_LPI2C0_DmaRxCompleteNotification(VAR( void, AUTOMATIC));

FUNC (void, I2C_CODE) I2c_LPI2C0_DmaTxCompleteNotification(VAR( void, AUTOMATIC));
    #endif
    
    #if defined(LPI2C_1)
FUNC (void, I2C_CODE) I2c_LPI2C1_DmaRxCompleteNotification(VAR( void, AUTOMATIC));

FUNC (void, I2C_CODE) I2c_LPI2C1_DmaTxCompleteNotification(VAR( void, AUTOMATIC));
    #endif
#endif

#define I2C_STOP_SEC_CODE
/**
* @violates @ref I2c_LPI2C_h_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_LPI2C_h_REF_3 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* I2C_LPI2C_H */

/** @} */
