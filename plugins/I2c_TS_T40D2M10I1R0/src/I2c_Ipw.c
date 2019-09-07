/**
*   @file    I2c_Ipw.c
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - Isolation level file for I2c driver.
*   @details Implementation file for function definition on isolation level between high and low level driver.
*
*   @addtogroup I2c
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section I2c_Ipw_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents of a header 
* file being included twice. This comes from the order of includes in the .c file and from include dependencies. 
* As a safe approach, any file must include all its dependencies. Header files are already protected against double
* inclusions.
*
* @section I2c_Ipw_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded by other preprocessor 
* directives or comments. AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section I2c_Ipw_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character significance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c.h"
#include "I2c_Ipw.h"

#include "I2c_FlexIO.h"
#include "I2c_LPI2C.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           I2c_Ipw.c
*/
#define I2C_IPW_VENDOR_ID_C                    43
/*
* @violates @ref I2c_Ipw_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_MAJOR_VERSION_IPW_C     4
/*
* @violates @ref I2c_Ipw_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_MINOR_VERSION_IPW_C     2
/*
* @violates @ref I2c_Ipw_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define I2C_AR_RELEASE_REVISION_VERSION_IPW_C  2
#define I2C_SW_MAJOR_VERSION_IPW_C             1
#define I2C_SW_MINOR_VERSION_IPW_C             0
#define I2C_SW_PATCH_VERSION_IPW_C             1

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and I2c header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID_C != I2C_VENDOR_ID)
    #error "I2c_Ipw.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and I2c header file are of the same Autosar version */
#if ( (I2C_AR_RELEASE_MAJOR_VERSION_IPW_C     != I2C_AR_RELEASE_MAJOR_VERSION)   || \
      (I2C_AR_RELEASE_MINOR_VERSION_IPW_C     != I2C_AR_RELEASE_MINOR_VERSION)   || \
      (I2C_AR_RELEASE_REVISION_VERSION_IPW_C  != I2C_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of I2c_Ipw.c and CDD_I2c.h are different"
#endif
/* Check if current file and I2c header file are of the same Software version */
#if ( (I2C_SW_MAJOR_VERSION_IPW_C != I2C_SW_MAJOR_VERSION) || \
      (I2C_SW_MINOR_VERSION_IPW_C != I2C_SW_MINOR_VERSION) || \
      (I2C_SW_PATCH_VERSION_IPW_C != I2C_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of I2c_Ipw.c and CDD_I2c.h are different"
#endif

/* Check if current file and I2c_Ipw header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID_C != I2C_IPW_VENDOR_ID)
    #error "I2c_Ipw.h and I2c_Ipw.c have different vendor ids"
#endif
/* Check if current file and I2c_Ipw header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_IPW_C != I2C_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (I2C_AR_RELEASE_MINOR_VERSION_IPW_C != I2C_AR_RELEASE_MINOR_VERSION_IPW) || \
     (I2C_AR_RELEASE_REVISION_VERSION_IPW_C != I2C_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of I2c_Ipw.h and I2c_Ipw.c are different"
#endif
/* Check if current file and I2c_Ipw header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_IPW_C != I2C_SW_MAJOR_VERSION_IPW) || \
     (I2C_SW_MINOR_VERSION_IPW_C != I2C_SW_MINOR_VERSION_IPW) || \
     (I2C_SW_PATCH_VERSION_IPW_C != I2C_SW_PATCH_VERSION_IPW) \
    )
#error "Software Version Numbers of I2c_Ipw.h and I2c_Ipw.c are different"
#endif

/* Check if current file and I2c_FlexIO header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID_C != I2C_FLEXIO_VENDOR_ID)
    #error "I2c_FlexIO.h and I2c_Ipw.c have different vendor ids"
#endif
/* Check if current file and I2c_FlexIO header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_IPW_C != I2C_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_AR_RELEASE_MINOR_VERSION_IPW_C != I2C_FLEXIO_AR_RELEASE_MINOR_VERSION) || \
     (I2C_AR_RELEASE_REVISION_VERSION_IPW_C != I2C_FLEXIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_FlexIO.h and I2c_Ipw.c are different"
#endif
/* Check if current file and I2c_FlexIO header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_IPW_C != I2C_FLEXIO_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_IPW_C != I2C_FLEXIO_SW_MINOR_VERSION) || \
     (I2C_SW_PATCH_VERSION_IPW_C != I2C_FLEXIO_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of I2c_FlexIO.h and I2c_Ipw.c are different"
#endif

/* Check if current file and I2c_LPI2C header file are of the same vendor */
#if (I2C_IPW_VENDOR_ID_C != I2C_LPI2C_VENDOR_ID)
    #error "I2c_LPI2C.h and I2c_Ipw.c have different vendor ids"
#endif
/* Check if current file and I2c_LPI2C header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_IPW_C != I2C_LPI2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_AR_RELEASE_MINOR_VERSION_IPW_C != I2C_LPI2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_AR_RELEASE_REVISION_VERSION_IPW_C != I2C_LPI2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_LPI2C.h and I2c_Ipw.c are different"
#endif
/* Check if current file and I2c_LPI2C header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_IPW_C != I2C_LPI2C_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_IPW_C != I2C_LPI2C_SW_MINOR_VERSION) || \
     (I2C_SW_PATCH_VERSION_IPW_C != I2C_LPI2C_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of I2c_LPI2C.h and I2c_Ipw.c are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define I2C_START_SEC_CODE
/** 
* @violates @ref I2c_Ipw_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#if (I2C_DEV_ERROR_DETECT == STD_ON)
/**
* @brief   Checks the data length for a transmission.
* @details Checks if the data length for a transmission is not higher than the maximum allowed.
*
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*              eChannelType     The type of the channel (LPI2C or FlexIO).
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   If the number of bytes is higher than the maximum allowed for that type of channel.
* @retval E_OK       If the number of bytes is ok.
*
*/
FUNC(Std_ReturnType, I2C_CODE) I2c_Ipw_CheckDataLength(P2CONST(I2c_RequestType, AUTOMATIC, I2C_APPL_CONST) pRequest, CONST(I2c_HwChannelType, AUTOMATIC) eChannelType)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;
    
    if (FLEXIO_CHANNEL == eChannelType)
    {
        if (FLEXIO_MAX_NUMBER_OF_BYTES_U32 >= pRequest->u8BufferSize)
        {
            u8TmpReturn = (Std_ReturnType)E_OK;
        }
    }
    else
    {
        u8TmpReturn = (Std_ReturnType)E_OK;
    }
    
    return u8TmpReturn;
}
#endif

/**
* @brief   Initialize a I2c channel.
* @details This function initializes all hardware registers needed to
*          start the I2c functionality on the selected channel.
*
* @param[in] u8Channel  I2c channel to be initialized.
*            pConfigPtr Configuration pointer containing hardware specific settings.
*
* @return            void.
*
*/
FUNC (void, I2C_CODE) I2c_Ipw_InitChannel(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(I2c_Ipw_HwChannelConfigType, AUTOMATIC, I2C_APPL_CONST) pConfigPtr)
{
    if (LPI2C_CHANNEL == (pConfigPtr->I2c_Ipw_eChannelType))
    {
        I2c_LPI2C_InitChannel(u8Channel, (pConfigPtr->I2c_Ipw_LPI2CHwConfig));
    }
    else
    {
        I2c_FlexIO_InitChannel(u8Channel, (pConfigPtr->I2c_Ipw_FlexIOCHwConfig));
    }
}

/**
* @brief   De initialize a I2c channel.
* @details This function de initializes the hardware registers of an I2c channel
*
* @param[in] u8Channel      I2c channel to be de initialized.
*            eChannelType   The type of the channel (LPI2C or FlexIO).
*
* @return            void.
*
*/
FUNC (void, I2C_CODE) I2c_Ipw_DeInitChannel(CONST(uint8, AUTOMATIC) u8Channel, CONST(I2c_HwChannelType, AUTOMATIC) eChannelType)
{
    if (LPI2C_CHANNEL == eChannelType)
    {
        I2c_LPI2C_DeInitChannel(u8Channel);
    }
    else
    {
        I2c_FlexIO_DeInitChannel(u8Channel);
    }
}

/**
* @brief   Sends or receives an I2c message from the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   u8Channel        I2c channel to be addressed.
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*              eChannelType     The type of the channel (LPI2C or FlexIO).
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_Ipw_SyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequest, CONST(I2c_HwChannelType, AUTOMATIC) eChannelType)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;

    if (LPI2C_CHANNEL == eChannelType)
    {
        u8TmpReturn = I2c_LPI2C_SyncTransmit(u8Channel, pRequest);
    }
    else
    {
        u8TmpReturn = I2c_FlexIO_SyncTransmit(u8Channel, pRequest);
    }
    
    return u8TmpReturn;
}

/**
* @brief   Starts sending or receiving an I2c message from the slave.
* @details Generate (repeated) START and send the address of the slave to initiate a transmission.
*
* @param[in]   u8Channel        I2c channel to be addressed.
* @param[in]   pRequestPtr      Pointer to the structure that contains the information necessary to begin the
*                               transmission: the address of the slave, high speed mode, expect NACK, number of bytes
*                               and the data buffer
*              eChannelType     The type of the channel (LPI2C or FlexIO).
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a time out situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_Ipw_AsyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequest, CONST(I2c_HwChannelType, AUTOMATIC) eChannelType)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (Std_ReturnType)E_NOT_OK;

    if (LPI2C_CHANNEL == eChannelType)
    {
        u8TmpReturn = I2c_LPI2C_AsyncTransmit(u8Channel, pRequest);
    }
    else
    {
        u8TmpReturn = I2c_FlexIO_AsyncTransmit(u8Channel, pRequest);
    }
    
    return u8TmpReturn;

}

/**
* @brief   Prepare the RX or TX buffer for a slave channel.
* @details Prepares a RX or TX buffer that will be used to receive data or send data when requested by the master.
*
* @param[in] u8Channel       I2c channel to be addressed.
* @param[in] u8NumberOfBytes Maximum number of bytes.
* @param[in] pDataBuffer     Pointer to data buffer
*
* @return                  void
*/
FUNC(void, I2C_CODE)  I2c_Ipw_PrepareSlaveBuffer(
                                                  VAR(uint8, AUTOMATIC) u8Channel,
                                                  VAR(uint8, AUTOMATIC) u8NumberOfBytes,
                                                  P2VAR(I2c_DataType, AUTOMATIC, I2C_APPL_DATA) pDataBuffer
                                                )
{
    /* Only LPI2C can be configured as a SLAVE channel */
    I2c_LPI2C_PrepareSlaveBuffer(u8Channel, u8NumberOfBytes, pDataBuffer);
}

/**
* @brief   Makes a slave channel available for processing requests (addressings).
* @details When called, the slave channel becomes available for starting incoming or outgoing transfers.
*
* @param[in] u8Channel     I2C channel to be addressed.
*
* @return                  void
*/
FUNC(void, I2C_CODE)  I2c_Ipw_StartListening(VAR(uint8, AUTOMATIC) u8Channel)
{
    I2c_LPI2C_StartListening(u8Channel);
}

/**
* @brief   Gets the status of an I2c channel.
* @details The function will check for error flags and return the status of a channel.
*
* @param[in]   u8Channel        I2c channel to be addressed.
*              eChannelType     The type of the channel (LPI2C or FlexIO).
*
* @return   I2c_StatusType.
* @retval I2C_CH_IDLE           In case the channel was just initialized and not request is pending.
* @retval I2C_CH_SEND           In case the channel is busy sending data.
* @retval I2C_CH_RECEIVE        In case the channel is busy receiving data.
* @retval I2C_CH_FINISHED       In case a transmission or reception of bytes has finished.
* @retval I2C_CH_ERROR_PRESENT  In case an error is present.
*
*/
FUNC (I2c_StatusType, I2C_CODE) I2c_Ipw_GetStatus(CONST(uint8, AUTOMATIC) u8Channel, CONST(I2c_HwChannelType, AUTOMATIC) eChannelType)
{
    VAR(I2c_StatusType, AUTOMATIC) eChannelStatus = I2C_CH_IDLE;

    if (LPI2C_CHANNEL == eChannelType)
    {
        eChannelStatus = I2c_LPI2C_GetStatus(u8Channel);
    }
    else
    {
        eChannelStatus = I2c_FlexIO_GetStatus(u8Channel);
    }
    
    return eChannelStatus;
}


#define I2C_STOP_SEC_CODE
/** 
* @violates @ref I2c_Ipw_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref I2c_Ipw_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
