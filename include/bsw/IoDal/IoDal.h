/**
*   @file    IoDal.h
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component
*   @details This header file implements the IODAL interface to application layer.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup IODAL
*   @{
*/
/*=========================================================================================================================
*   Platform             : ARM
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
============================================================================================================================*/
/*============================================================================================================================
==============================================================================================================================*/

#ifndef IODAL_H
#define IODAL_H

#ifdef __cplusplus
extern "C"{
#endif

/*===================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
====================================================================================================================*/
#include "IoDal_Types.h"
#include "IoDal_Cfg.h"
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
/**
* @file           IoDal.h
*/
#define IODAL_VENDOR_ID                           43
#define IODAL_MODULE_ID                           100

#define IODAL_AR_RELEASE_MAJOR_VERSION            4
#define IODAL_AR_RELEASE_MINOR_VERSION            2
#define IODAL_AR_RELEASE_REVISION_VERSION         2

#define IODAL_SW_MAJOR_VERSION                    1
#define IODAL_SW_MINOR_VERSION                    0
#define IODAL_SW_PATCH_VERSION                    1

/*===================================================================================================================
*                                       FILE VERSION CHECKS
====================================================================================================================*/


/* Check if header file and IODAL types header file are of the same vendor */
#if (IODAL_VENDOR_ID != IODAL_TYPES_VENDOR_ID)
    #error "IoDal.c and IoDal_Types.h have different vendor ids"
#endif

/* Check if header file and IODAL types header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION != IODAL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION != IODAL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION != IODAL_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.h and IoDal_Types.h are different"
#endif

/* Check if header file and IODAL types header file are of the same software version */
#if ((IODAL_SW_MAJOR_VERSION != IODAL_TYPES_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION != IODAL_TYPES_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION != IODAL_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.h and IoDal_Types.h are different"
#endif



/* Check if header file and IODAL configuration header file are of the same vendor */
#if (IODAL_VENDOR_ID != IODAL_CFG_VENDOR_ID)
    #error "IoDal.h and IoDal_Cfg.h have different vendor ids"
#endif

/* Check if header file and IODAL configuration header file are of the same Autosar version */
#if ((IODAL_AR_RELEASE_MAJOR_VERSION != IODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_AR_RELEASE_MINOR_VERSION != IODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_AR_RELEASE_REVISION_VERSION != IODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.h and IoDal_Cfg.h are different"
#endif

/* Check if header file and IODAL configuration header file are of the same software version */
#if ((IODAL_SW_MAJOR_VERSION != IODAL_CFG_SW_MAJOR_VERSION) || \
     (IODAL_SW_MINOR_VERSION != IODAL_CFG_SW_MINOR_VERSION) || \
     (IODAL_SW_PATCH_VERSION != IODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.h and IoDal_Cfg.h are different"
#endif



/*===================================================================================================================
*                                          DEFINES AND MACROS
====================================================================================================================*/
/**
*       Development errors.
*       The following errors shall be detectable by the ADC module depending on its 
*       configuration (development / production mode).
*
*       All error codes
*
*/

/**
* @brief   API service used without Adc module initialization
* */
#define IODAL_E_UNINIT                                 ((uint8)0xE0U)


/**
* @brief   The IODAL module is already initilized 
* */
#define IODAL_E_ALREADY_INITIALIZED                    ((uint8)0xE1U)

/**
* @brief   The ADC module is not properly configured 
* */
#define IODAL_E_PARAM_CONFIG                           ((uint8)0xE2U)

/**
* @brief   API service is called using an invalid pointer (e.g. the pointer should not be NULL).
* */
#define IODAL_E_PARAM_POINTER                          ((uint8)0xE3U)

/**
* @brief   API service used with an invalid ADC group.
* */
#define IODAL_E_INVALID_CHANNEL_TYPE                    ((uint8)0xE4U)

/**
* @brief   API service used with an invalid ADC Conversion Mode.
* */
#define IODAL_E_INVALID_CHANNEL_ID                       ((uint8)0xE5U)

/**
* @brief   API service used with an invalid ADC Conversion Mode.
* */
#define IODAL_E_INVALID_BUFFER_SETUP                     ((uint8)0xE6U)

/**
          All AUTOSAR API's service IDs
*/

/**
* @brief API service ID for IoDal_Init function
* */
#define IODAL_INIT_API_ID                                  0x00U

/**
* @brief API service ID for IoDal_DeInit function
* */
#define IODAL_DEINIT_ID                                    0x01U

/**
* @brief API service ID for IoDal_MainFunction function
* */
#define IODAL_MAINFUNCTION_API_ID                          0x02U

/**
* @brief API service ID for IoDal_ReadInputs function
* */
#define IODAL_READINPUTS_API_ID                            0x03U

/**
* @brief API service ID for IoDal_WriteOutputs function
* */
#define IODAL_WRITEOUTPUTS_API_ID                          0x04U
 

/*===================================================================================================================
                          GLOBAL TYPEDEFS
====================================================================================================================*/


/*===================================================================================================================
                                       LOCAL CONSTANTS
====================================================================================================================*/

/*===================================================================================================================
                                       LOCAL VARIABLES
====================================================================================================================*/


/*===================================================================================================================
                                       GLOBAL CONSTANTS
====================================================================================================================*/


/*===================================================================================================================
                                       GLOBAL VARIABLES
====================================================================================================================*/


/*===================================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
====================================================================================================================*/


/*===================================================================================================================
                                       LOCAL FUNCTIONS
====================================================================================================================*/

/*===================================================================================================================
                                       GLOBAL FUNCTIONS
====================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Init(P2CONST(IoDal_BswIoConfigType, AUTOMATIC, IODAL_APP_CONST) ConfigPtr);
FUNC(void, IODAL_APP_CODE) IoDal_DeInit(void);
FUNC(void, IODAL_APP_CODE) IoDal_MainFunction(void);
FUNC(Std_ReturnType, IODAL_APP_CODE) IoDal_ReadInputs(IoDal_BswChannelIdType BswIoChannel, IoDal_BswValueType  * InputValue) ;
FUNC(void, IODAL_APP_CODE) IoDal_WriteOutputs (IoDal_BswChannelIdType BswIoChannel,  IoDal_BswValueType  OutputValue);

/*===================================================================================================================*/
#ifdef __cplusplus
}
#endif

#endif  /* IODAL_H*/

/** @} */