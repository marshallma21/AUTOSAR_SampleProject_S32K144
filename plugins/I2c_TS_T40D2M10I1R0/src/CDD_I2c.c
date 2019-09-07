/**
*   @file    CDD_I2c.c
*   @version 1.0.1
*
*   @brief   AUTOSAR I2c - High level part of I2C driver.
*   @details This file contains the functions defined by AutoSAR.
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
* @section CDD_I2c_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a file should only be preceded
* by other preprocessor directives or comments. AUTOSAR imposes the specification of the
* sections in which certain parts of the driver must be placed.
*
* @section CDD_I2c_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents
* of a header file being included twice. This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all its dependencies. Header files are
* already protected against double inclusions. The inclusion of MemMap.h is as per Autosar requirement
* MEMMAP003.
*
* @section CDD_I2c_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section CDD_I2c_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar specification.
*
* @section CDD_I2c_c_REF_5
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2c.h"
#include "I2c_Ipw.h"
#if (I2C_DEV_ERROR_DETECT == STD_ON)
  #include "Det.h"
#endif

#include "SchM_I2c.h"

#if(I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_VENDOR_ID_C                      43
#define I2C_AR_RELEASE_MAJOR_VERSION_C       4
#define I2C_AR_RELEASE_MINOR_VERSION_C       2

/**
* @violates @ref CDD_I2c_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for external identifiers.
*/
#define I2C_AR_RELEASE_REVISION_VERSION_C    2
#define I2C_SW_MAJOR_VERSION_C               1
#define I2C_SW_MINOR_VERSION_C               0
#define I2C_SW_PATCH_VERSION_C               1
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c header file are of the same vendor */
#if (I2C_VENDOR_ID_C != I2C_VENDOR_ID)
    #error "CDD_I2c.c and CDD_I2c.h have different vendor ids"
#endif
/* Check if current file and I2c header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_C    != I2C_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_AR_RELEASE_MINOR_VERSION_C    != I2C_AR_RELEASE_MINOR_VERSION) || \
     (I2C_AR_RELEASE_REVISION_VERSION_C != I2C_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_I2c.c and CDD_I2c.h are different"
#endif
/* Check if current file and I2C header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_C != I2C_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_C != I2C_SW_MINOR_VERSION) || \
     (I2C_SW_PATCH_VERSION_C != I2C_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_I2c.c and CDD_I2c.h are different"
#endif
/* Check if current file and I2c_Ipw header file are of the same vendor */
#if (I2C_VENDOR_ID_C != I2C_IPW_VENDOR_ID)
    #error "CDD_I2c.c and I2c_Ipw.h have different vendor ids"
#endif
/* Check if current file and I2c_Ipw header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_C    != I2C_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (I2C_AR_RELEASE_MINOR_VERSION_C    != I2C_AR_RELEASE_MINOR_VERSION_IPW) || \
     (I2C_AR_RELEASE_REVISION_VERSION_C != I2C_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of CDD_I2c.c and I2c_Ipw.h are different"
#endif
/* Check if current file and I2c_Ipw header file are of the same Software version */
#if ((I2C_SW_MAJOR_VERSION_C != I2C_SW_MAJOR_VERSION_IPW) || \
     (I2C_SW_MINOR_VERSION_C != I2C_SW_MINOR_VERSION_IPW) || \
     (I2C_SW_PATCH_VERSION_C != I2C_SW_PATCH_VERSION_IPW)    \
    )
    #error "Software Version Numbers of CDD_I2c.c and I2c_Ipw.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if the source file and Dem header file are of the same version */
        #if ((I2C_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
             (I2C_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_I2c.c and Dem.h are different"
        #endif
    #endif

    #if (I2C_DEV_ERROR_DETECT == STD_ON)
        /* Check if the source file and Det header file are of the same Autosar version */
        #if ((I2C_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (I2C_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION)    \
            )
            #error "AutoSar Version Numbers of CDD_I2c.c and Det.h are different"
        #endif
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define I2C_START_SEC_VAR_INIT_8
/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#if (I2C_DEV_ERROR_DETECT == STD_ON)
/**
* @brief          I2C driver status variable.
* @details        I2C driver state machine.
*/
static VAR(uint8,I2C_VAR)I2c_u8DriverStatus = I2C_UNINIT;
#endif

#define I2C_STOP_SEC_VAR_INIT_8

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#if (I2C_PRECOMPILE_SUPPORT == STD_ON)
#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/**
* @violates @ref CDD_I2c_c_REF_5 Object defined external because of autosar
*/

extern CONST(I2c_ConfigType,I2C_CONST)I2c_PBCfgVariantPredefined;

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/* put all I2c variables into defined section */
#define I2C_START_SEC_VAR_NO_INIT_UNSPECIFIED

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/**
* @brief          I2C channel status array.
* @details        The status of the I2C channels.
*/
volatile VAR(I2c_StatusType,I2C_VAR) I2c_aeChannelStatus[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/* put all I2c variables into defined section */
#define I2C_START_SEC_VAR_INIT_UNSPECIFIED

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/**
* @brief          Global configuration pointer.
* @details        Pointer to the configuration structure.
*/
P2CONST(I2c_ConfigType,I2C_VAR,I2C_APPL_CONST) I2c_pConfig = NULL_PTR;

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief          DEM errors configuration pointer.
* @details        This is used to report DEM errors in the I2C driver.
*/
P2CONST( I2c_DemConfigType, I2C_VAR, I2C_APPL_CONST) I2c_pDemCfg = NULL_PTR;
#endif

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"


#define I2C_START_SEC_VAR_NO_INIT_8

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/**
* @brief          I2C channel hardware map variable.
* @details        I2C channel hardware map.
*/
VAR(sint8,I2C_VAR) I2c_as8ChannelHardwareMap[I2C_HW_MAX_MODULES];

#define I2C_STOP_SEC_VAR_NO_INIT_8

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @note put all I2C code into defined section
*/
#define I2C_START_SEC_CODE

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

/**
* @brief   Initializes the I2C module.
* @details This function performs software initialization of I2C
*          driver:
*          - Maps logical channels to hardware channels
*          - Initializes all channels
*          - Sets driver state machine to I2C_INIT.
*
* @param[in] pConfig        Pointer to I2C driver configuration set.
*
* @return  void
*
* @api
*
* @implements I2c_Init_Activity
*
* @note    Service ID: 0x00.
* @note    Synchronous, non re-entrant function.
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(void, I2C_CODE) I2c_Init(P2CONST(I2c_ConfigType, AUTOMATIC, I2C_APPL_CONST) pConfig)
{
    VAR(uint8,AUTOMATIC) u8ChLoop;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_UNINIT state */
    if (I2C_UNINIT != I2c_u8DriverStatus)
    {
        /* I2C driver has been already initialized */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_ALREADY_INITIALIZED);
    }
    else
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

#if (I2C_PRECOMPILE_SUPPORT != STD_ON)
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
        /* Check pConfig for not being a null pointer */
        if (NULL_PTR == pConfig)
        {
            /* Invalid pointer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_INVALID_POINTER);
        }
        else
        {
    #endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
            I2c_pConfig = pConfig;
#else /* I2C_PRECOMPILE_SUPPORT == STD_ON */
    #if (I2C_DEV_ERROR_DETECT == STD_ON)
        if (NULL_PTR != pConfig)
        {
            /* Invalid pointer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_INIT_ID, (uint8)I2C_E_INVALID_POINTER);
        }
        else
        {
    #endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                    I2c_pConfig = &I2c_PBCfgVariantPredefined;
                    (void)pConfig;
#endif /* I2C_PRECOMPILE_SUPPORT == STD_ON */

#if (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* Get a local copy of the DEM error reporting structure. */
            I2c_pDemCfg = I2c_pConfig->I2c_pDemConfig;
#endif /* (I2C_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

            for(u8ChLoop=(uint8)0U; u8ChLoop < I2C_HW_MAX_MODULES; u8ChLoop++)
            {
                I2c_as8ChannelHardwareMap[u8ChLoop] = -1;
                I2c_aeChannelStatus[u8ChLoop] = I2C_CH_IDLE;
            }
            for(u8ChLoop=(uint8)0U; u8ChLoop < I2c_pConfig->I2c_MaxHwUnit; u8ChLoop++)
            {
                /* Map configured hardware channel to logical channel */
                I2c_as8ChannelHardwareMap[(*I2c_pConfig->I2c_pHwConfig)[u8ChLoop].I2c_HwUnit] = (sint8)u8ChLoop;
                
                I2c_Ipw_InitChannel((*I2c_pConfig->I2c_pHwConfig)[u8ChLoop].I2c_HwUnit, &(*I2c_pConfig->I2c_pHwConfig)[u8ChLoop].HwChannelConfig);
            }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            /* Update I2C driver status to I2C_INIT */
            I2c_u8DriverStatus = I2C_INIT;
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
}

/**
* @brief   DeInitializes the I2C module.
* @details This function performs software de initialization of I2C modules to reset values.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of I2c_Init()
*          The driver needs to be initialized before calling I2c_DeInit(). Otherwise, the
*          function I2c_DeInit shall raise the development error I2C_E_UNINIT and leave the desired
*          de initialization functionality without any action.
*
* @param[in] void
*
* @return  void
*
* @api
*
* @implements I2c_DeInit_Activity
*
* @note    Service ID: 0x01.
* @note    Synchronous, non re-entrant function.
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(void, I2C_CODE) I2c_DeInit(void)
{
    VAR(uint8,AUTOMATIC) u8ChLoop;

    /* Check whether the I2C driver is in I2C_UNINIT state */
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    if (I2C_INIT != I2c_u8DriverStatus)
    {
        /* I2C driver has been already initialized */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_DEINIT_ID, (uint8)I2C_E_UNINIT);
    }
    else
    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

        for(u8ChLoop=(uint8)0U; u8ChLoop < I2C_HW_MAX_MODULES; u8ChLoop++)
        {
            I2c_as8ChannelHardwareMap[u8ChLoop] = -1;
            I2c_aeChannelStatus[u8ChLoop] = I2C_CH_IDLE;
        }
        for(u8ChLoop=(uint8)0U; u8ChLoop < I2c_pConfig->I2c_MaxHwUnit; u8ChLoop++)
        {
            I2c_Ipw_DeInitChannel((*I2c_pConfig->I2c_pHwConfig)[u8ChLoop].I2c_HwUnit, ((*I2c_pConfig->I2c_pHwConfig)[u8ChLoop].HwChannelConfig).I2c_Ipw_eChannelType);
        }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Update I2C driver status to I2C_UNINIT */
    I2c_u8DriverStatus = I2C_UNINIT;
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
}

/**
* @brief   Prepare the RX or TX buffer for a slave channel.
* @details Prepares a RX or TX buffer that will be used to receive data or send data when requested by the master.
*
* @param[in] u8Channel       I2C channel to be addressed.
* @param[in] u8NumberOfBytes Maximum number of bytes to be sent or received.
* @param[in] pDataBuffer     Pointer to data buffer
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or I2C driver is not initialized or pDataBuffer is NULL or
*                          I2C Channel is a master channel.
* @retval E_OK             Otherwise.
*
* @api
*
* @note    Service ID: 0x05.
* @note    Synchronous, non reentrant function.
*
* @implements I2c_PrepareSlaveBuffer_Activity
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(Std_ReturnType, I2C_CODE) I2c_PrepareSlaveBuffer(VAR(uint8, AUTOMATIC) u8Channel, VAR(uint8, AUTOMATIC) u8NumberOfBytes, P2VAR(I2c_DataType, AUTOMATIC, I2C_APPL_DATA) pDataBuffer)
{
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    VAR(I2c_StatusType, AUTOMATIC) eTempChannelStatus;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_u8DriverStatus)
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_PREPARESLAVEBUFFER_ID, (uint8)I2C_E_UNINIT);
        tempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (u8Channel >= I2c_pConfig->I2c_MaxHwUnit)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_PREPARESLAVEBUFFER_ID, (uint8)I2C_E_INVALID_CHANNEL);
            tempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check pDataBuffer for not being a null pointer */
            if(NULL_PTR == pDataBuffer)
            {
                /* Invalid pointer */
               /* Report error to development error tracer */
               (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_PREPARESLAVEBUFFER_ID, (uint8)I2C_E_INVALID_POINTER);
                tempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Check whether the I2C channel is a slave or master/slave channel */
                if ( I2C_MASTER_MODE != (*I2c_pConfig->I2c_pHwConfig)[u8Channel].eMasterSlaveConfig )
                {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                    eTempChannelStatus = I2c_aeChannelStatus[u8Channel];
                    if ((I2C_CH_SEND != eTempChannelStatus) && (I2C_CH_RECEIVE != eTempChannelStatus))
                    {
                        I2c_Ipw_PrepareSlaveBuffer((*I2c_pConfig->I2c_pHwConfig)[u8Channel].I2c_HwUnit,u8NumberOfBytes, pDataBuffer);
                        tempReturn = (uint8)E_OK;
                    }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
                }
                else
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_PREPARESLAVEBUFFER_ID, (uint8)I2C_E_INVALID_CHANNEL);
                }
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    return tempReturn;
}

/**
* @brief   Makes a slave channel available for processing requests (addressings).
* @details When called, the slave channel becomes available for starting incoming or outgoing transfers.
*
* @param[in] u8Channel     I2C channel to be addressed.
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or I2C driver is not initialized or I2C Channel is a 
*                          master channel.
* @retval E_OK             Otherwise.
*
* @api
*
* @note    Service ID: 0x06.
* @note    Synchronous, non reentrant function.
*
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(Std_ReturnType, I2C_CODE)  I2c_StartListening(VAR(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    VAR(I2c_StatusType, AUTOMATIC) eTempChannelStatus;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_u8DriverStatus)
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_STARTLISTENING_ID, (uint8)I2C_E_UNINIT);
        tempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (u8Channel >= I2c_pConfig->I2c_MaxHwUnit)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_STARTLISTENING_ID, (uint8)I2C_E_INVALID_CHANNEL);
            tempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check whether the I2C channel is a slave or master/slave channel */
            if ( I2C_MASTER_MODE != (*I2c_pConfig->I2c_pHwConfig)[u8Channel].eMasterSlaveConfig )
            {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                /* Enter critical section */
                SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_02();

                eTempChannelStatus = I2c_aeChannelStatus[u8Channel];
                if ((I2C_CH_SEND != eTempChannelStatus) && (I2C_CH_RECEIVE != eTempChannelStatus))
                {
                    I2c_Ipw_StartListening((*I2c_pConfig->I2c_pHwConfig)[u8Channel].I2c_HwUnit);

                    /* Exit critical section */
                    SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_02();

                    tempReturn = (uint8)E_OK;
                }
                else
                {
                    /* Exit critical section */
                    SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_02();
                }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
            }
            else
            {
                /* Invalid channel */
                /* Report error to development error tracer */
                (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_STARTLISTENING_ID, (uint8)I2C_E_INVALID_CHANNEL);
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return tempReturn;
}

/**
* @brief   Sends or receives an I2C message blocking.
* @details Sends the slave address and based on the direction of the message it sends
*          or receives data by using a blocking mechanism.
*
* @param[in] u8Channel     I2C channel to be addressed.
* @param[in] pRequestPtr   Pointer to data information to be used
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or
*                          I2C driver is not initialized or
*                          pRequestPtr is NULL or
*                          I2C Channel is in busy state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements I2c_SyncTransmit_Activity
*
* @note    Service ID: 0x02.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(Std_ReturnType, I2C_CODE) I2c_SyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    VAR(I2c_StatusType, AUTOMATIC) eTempChannelStatus;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_u8DriverStatus)
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_SYNCTRANSMIT_ID, (uint8)I2C_E_UNINIT);
        tempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (u8Channel >= I2c_pConfig->I2c_MaxHwUnit)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_SYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_CHANNEL);
            tempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check pRequestPtr for not being a null pointer */
            if(NULL_PTR == pRequestPtr)
            {
               /* Invalid pointer */
               /* Report error to development error tracer */
               (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_SYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_POINTER);
               tempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Check whether the I2C channel is a master or master/slave channel */
                if ( I2C_SLAVE_MODE != (*I2c_pConfig->I2c_pHwConfig)[u8Channel].eMasterSlaveConfig )
                {
                    if ((Std_ReturnType)E_OK == I2c_Ipw_CheckDataLength(pRequestPtr, ((*I2c_pConfig->I2c_pHwConfig)[u8Channel].HwChannelConfig).I2c_Ipw_eChannelType))
                    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                        /* Enter critical section */
                        SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_00();
                        
                        /* Check whether the I2C channel is in busy state */
                        eTempChannelStatus = I2c_aeChannelStatus[u8Channel];
                        if ((I2C_CH_SEND != eTempChannelStatus) && (I2C_CH_RECEIVE != eTempChannelStatus))
                        {
                            if (I2C_SEND_DATA == pRequestPtr->eDataDirection)
                            {
                                I2c_aeChannelStatus[u8Channel] = I2C_CH_SEND;
                            }
                            else
                            {
                                I2c_aeChannelStatus[u8Channel] = I2C_CH_RECEIVE;
                            }
                            
                            /* Exit critical section */
                            SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_00();

                            tempReturn = (uint8)I2c_Ipw_SyncTransmit((*I2c_pConfig->I2c_pHwConfig)[u8Channel].I2c_HwUnit,pRequestPtr, ((*I2c_pConfig->I2c_pHwConfig)[u8Channel].HwChannelConfig).I2c_Ipw_eChannelType);
                        }
                        else
                        {
                            /* Exit critical section */
                            SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_00();
                        }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
                    }
                    else
                    {
                        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_SYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_BUFFER_SIZE);
                    }
                }
                else
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_SYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_CHANNEL);
                }
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    return tempReturn;
}

/**
* @brief   Starts an asynchronous transmission on the I2C bus.
* @details Sends the slave address and enables the interrupts that will send
*          or receive data depending on the direction of the message.
*
* @param[in] u8Channel     I2C channel to be addressed.
* @param[in] pRequestPtr   Pointer to data information to be used
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2C Channel is not valid or
*                          I2C driver is not initialized or
*                          pRequestPtr is NULL or
*                          I2C Channel is in busy state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements I2c_AsyncTransmit_Activity
*
* @note    Service ID: 0x03.
* @note    Synchronous, non reentrant function.
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(Std_ReturnType, I2C_CODE) I2c_AsyncTransmit(VAR(uint8, AUTOMATIC) u8Channel, P2VAR(I2c_RequestType, AUTOMATIC, I2C_APPL_DATA) pRequestPtr)
{
    VAR(Std_ReturnType, AUTOMATIC) tempReturn = (uint8)E_NOT_OK;
    VAR(I2c_StatusType, AUTOMATIC) eTempChannelStatus;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_u8DriverStatus)
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_ASYNCTRANSMIT_ID, (uint8)I2C_E_UNINIT);
        tempReturn = (uint8)E_NOT_OK;
    }
    else
    {
        /* Check for invalid channel */
        if (u8Channel >= I2c_pConfig->I2c_MaxHwUnit)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_ASYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_CHANNEL);
            tempReturn = (uint8)E_NOT_OK;
        }
        else
        {
            /* Check pRequestPtr for not being a null pointer */
            if(NULL_PTR == pRequestPtr)
            {
               /* Invalid pointer */
               /* Report error to development error tracer */
               (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_ASYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_POINTER);
               tempReturn = (uint8)E_NOT_OK;
            }
            else
            {
                /* Check whether the I2C channel is a master or master/slave channel */
                if ( I2C_SLAVE_MODE != (*I2c_pConfig->I2c_pHwConfig)[u8Channel].eMasterSlaveConfig )
                {
                    if ((Std_ReturnType)E_OK == I2c_Ipw_CheckDataLength(pRequestPtr, ((*I2c_pConfig->I2c_pHwConfig)[u8Channel].HwChannelConfig).I2c_Ipw_eChannelType))
                    {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
                        /* Enter critical section */
                        SchM_Enter_I2c_I2C_EXCLUSIVE_AREA_01();

                        /* Check whether the I2C channel is in busy state */
                        eTempChannelStatus = I2c_aeChannelStatus[u8Channel];
                        if ((I2C_CH_SEND != eTempChannelStatus) && (I2C_CH_RECEIVE != eTempChannelStatus))
                        {
                            if (I2C_SEND_DATA == pRequestPtr->eDataDirection)
                            {
                                I2c_aeChannelStatus[u8Channel] = I2C_CH_SEND;
                            }
                            else
                            {
                                I2c_aeChannelStatus[u8Channel] = I2C_CH_RECEIVE;
                            }

                            /* Exit critical section */
                            SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_01();

                            tempReturn = (uint8)I2c_Ipw_AsyncTransmit((*I2c_pConfig->I2c_pHwConfig)[u8Channel].I2c_HwUnit,pRequestPtr, ((*I2c_pConfig->I2c_pHwConfig)[u8Channel].HwChannelConfig).I2c_Ipw_eChannelType);
                        }
                        else
                        {
                            /* Exit critical section */
                            SchM_Exit_I2c_I2C_EXCLUSIVE_AREA_01();
                        }
#if (I2C_DEV_ERROR_DETECT == STD_ON)
                    }
                    else
                    {
                        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_ASYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_BUFFER_SIZE);
                    }
                }
                else
                {
                    /* Invalid channel */
                    /* Report error to development error tracer */
                    (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_ASYNCTRANSMIT_ID, (uint8)I2C_E_INVALID_CHANNEL);
                }
            }
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
    return tempReturn;
}
/**
* @brief   Gets the status of an I2C channel.
* @details Gets the status of an I2C channel and checks for errors.
*
* @param[in] u8Channel     I2C channel to be addressed.
*
* @return                  I2C_StatusType.
* @retval I2C_CH_IDLE           If the I2C Channel is in default state.
* @retval I2C_CH_SEND           If the I2C Channel is busy sending data.
* @retval I2C_CH_RECEIVE        If the I2C Channel is busy receiving data.
* @retval I2C_CH_FINISHED       If the I2C Channel finished the last transmission (sending
*                               or receiving data) successfully with no errors.
* @retval I2C_CH_ERROR_PRESENT  If the I2C Channel encountered an error during the last transmission.
*
* @api
*
* @implements I2c_GetStatus_Activity
*
* @note    Service ID: 0x04.
* @note    Synchronous, non re-entrant function.
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(I2c_StatusType, I2C_CODE) I2c_GetStatus(VAR(uint8, AUTOMATIC) u8Channel)
{
    VAR(I2c_StatusType, AUTOMATIC) eChannelStatus = I2C_CH_IDLE;

#if (I2C_DEV_ERROR_DETECT == STD_ON)
    /* Check whether the I2C driver is in I2C_INIT state */
    if (I2C_INIT != I2c_u8DriverStatus)
    {
        /* I2C driver has not been initialized yet */
        /* Report error to development error tracer */
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_GETSTATUS_ID, (uint8)I2C_E_UNINIT);
    }
    else
    {
        /* Check for invalid channel */
        if (u8Channel >= I2c_pConfig->I2c_MaxHwUnit)
        {
            /* Invalid channel */
            /* Report error to development error tracer */
            (void)Det_ReportError((uint16)I2C_MODULE_ID,(uint8)0,(uint8)I2C_GETSTATUS_ID, (uint8)I2C_E_INVALID_CHANNEL);
        }
        else
        {
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */
            eChannelStatus = I2c_Ipw_GetStatus((*I2c_pConfig->I2c_pHwConfig)[u8Channel].I2c_HwUnit, ((*I2c_pConfig->I2c_pHwConfig)[u8Channel].HwChannelConfig).I2c_Ipw_eChannelType);
#if (I2C_DEV_ERROR_DETECT == STD_ON)
        }
    }
#endif /* (I2C_DEV_ERROR_DETECT == STD_ON) */

    return eChannelStatus;
}

#if (I2C_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[in,out] pVersionInfo   Pointer for storing the version information
*                               of this module.
*
* @return                  void.
*
* @api
*
* @implements I2c_GetVersionInfo_Activity
*
* @pre            Preconditions as text description. Optional tag.
*
* @note    Service ID: 0x0A.
* @note    Synchronous, non re-entrant function.
*
*/
/**
* @violates @ref CDD_I2c_c_REF_4 All declarations and definitions of objects
* or functions at file scope shall have internal Linkage unless external Linkage is required.
*/
FUNC(void, I2C_CODE) I2c_GetVersionInfo (P2VAR(Std_VersionInfoType, AUTOMATIC,I2C_APPL_DATA) pVersionInfo)
{
#if( I2C_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == pVersionInfo )
    {
        (void)Det_ReportError((uint16)I2C_MODULE_ID, (uint8)0, (uint8)I2C_GETVERSIONINFO_ID, (uint8) I2C_E_INVALID_POINTER);
    }
    else
    {
#endif /* I2C_DEV_ERROR_DETECT == STD_ON */
        (pVersionInfo)->vendorID = (uint16) I2C_VENDOR_ID;
        (pVersionInfo)->moduleID = (uint8) I2C_MODULE_ID;
        (pVersionInfo)->sw_major_version = (uint8) I2C_SW_MAJOR_VERSION;
        (pVersionInfo)->sw_minor_version = (uint8) I2C_SW_MINOR_VERSION;
        (pVersionInfo)->sw_patch_version = (uint8) I2C_SW_PATCH_VERSION;
#if( I2C_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* I2C_DEV_ERROR_DETECT == STD_ON */
}
#endif /* I2C_VERSION_INFO_API == STD_ON */

#define I2C_STOP_SEC_CODE

/**
* @violates @ref CDD_I2c_c_REF_1 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*
* @violates @ref CDD_I2c_c_REF_2 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "I2c_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
