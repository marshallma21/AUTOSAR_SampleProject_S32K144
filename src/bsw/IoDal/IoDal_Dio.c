/**
*   @file    IoDal_Dio.c
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component for digital
*                                      input/output channels
*   @details This file implements the IODAL interface to application layer to lower layers                  
*            DIO, ICU, OCU             
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



#ifdef __cplusplus
extern "C"{
#endif

/*===================================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
====================================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"
#include "IoDal_Drv_Cfg.h"
#include "IoDal_Types.h"
#include "IoDal_Cfg.h"
#include "IoDal_Dio.h"
#include "Dio.h"

/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define IODAL_DIO_VENDOR_ID_C                       43

#define IODAL_DIO_AR_RELEASE_MAJOR_VERSION_C        4
#define IODAL_DIO_AR_RELEASE_MINOR_VERSION_C        2
#define IODAL_DIO_AR_RELEASE_REVISION_VERSION_C     2

#define IODAL_DIO_SW_MAJOR_VERSION_C                1
#define IODAL_DIO_SW_MINOR_VERSION_C                0
#define IODAL_DIO_SW_PATCH_VERSION_C                1

/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if source file and IODAL header file are of the same vendor */
#if (IODAL_DIO_VENDOR_ID_C != IODAL_CFG_VENDOR_ID)
    #error "IoDal_Dio.c and IoDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and IODAL header file are of the same Autosar version */
#if ((IODAL_DIO_AR_RELEASE_MAJOR_VERSION_C != IODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_DIO_AR_RELEASE_MINOR_VERSION_C != IODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_DIO_AR_RELEASE_REVISION_VERSION_C != IODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Dio.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IODAL header file are of the same Software version */
#if ((IODAL_DIO_SW_MAJOR_VERSION_C != IODAL_CFG_SW_MAJOR_VERSION) || \
     (IODAL_DIO_SW_MINOR_VERSION_C != IODAL_CFG_SW_MINOR_VERSION) || \
     (IODAL_DIO_SW_PATCH_VERSION_C != IODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal_Dio.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IODAL IPW header file are from the same vendor */
#if (IODAL_DIO_VENDOR_ID_C != IODAL_DIO_VENDOR_ID)
    #error "IoDal_Dio.c and IoDal_Dio.h have different vendor ids"
#endif

/* Check if source file and IODAL types header file are of the same Autosar version */
#if ((IODAL_DIO_AR_RELEASE_MAJOR_VERSION_C != IODAL_DIO_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_DIO_AR_RELEASE_MINOR_VERSION_C != IODAL_DIO_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_DIO_AR_RELEASE_REVISION_VERSION_C != IODAL_DIO_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal_Dio.c and IoDal_Dio.h are different"
#endif

/* Check if source file and IODAL types header file are of the same Software version */
#if ((IODAL_DIO_SW_MAJOR_VERSION_C != IODAL_DIO_SW_MAJOR_VERSION) || \
     (IODAL_DIO_SW_MINOR_VERSION_C != IODAL_DIO_SW_MINOR_VERSION) || \
     (IODAL_DIO_SW_PATCH_VERSION_C != IODAL_DIO_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of IoDal_Dio.c and IoDal_Dio.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((IODAL_DIO_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
      (IODAL_DIO_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of IoDal_Dio.c and Std_Types.h are different"
 #endif
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((IODAL_DIO_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (IODAL_DIO_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of IoDal_Dio.c and Mcal.h are different"
 #endif 
#endif
/*===================================================================================================================
                                      FILE VERSION CHECKS
====================================================================================================================*/


/*===================================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
====================================================================================================================*/
#if IODAL_MAX_DIO_DESCRIPTORS > 0U

/*===================================================================================================================
                                       LOCAL CONSTANTS
====================================================================================================================*/
/**
* @brief          Global Configuration Pointer for Digital inputs components.
* @details        Data structure containing the set of configuration parameters required for
*                 initializing the IODAL - DIO components.
*
*/
static P2CONST(IoDal_BswIoConfigType, IODAL_VAR,  IODAL_APPL_CONST) IoDal_pDioGlobalCfgPtr=NULL_PTR;

/*===================================================================================================================
                                       LOCAL VARIABLES
====================================================================================================================*/


/**
* @brief          Data array storing the digital level from input value read from asynchronous sources
* @details        Data array hold the level value from asynchronous inputs (inputs which are read from
*                 external devices or from ICU)
*
*/
static VAR(Dio_LevelType, AUTOMATIC) IoDal_DigitalInputLevel[IODAL_MAX_DIO_DESCRIPTORS];

/**
* @brief          Data array storing the request for changing the output level to the value in the 
*                 IoDal_DigitalOutputLevel for the given channel  
*
*/
static VAR(boolean,       AUTOMATIC) IoDal_DioResyncRequest[IODAL_MAX_DIO_DESCRIPTORS];


/**
* @brief          Data array storing the digital output level which was requested by application.
* @details        Data array stores the level value foR asynchronous outputs (outputs which mapped on 
*                 external devices or OCU)
*
*/
static VAR(uint32,        AUTOMATIC) IoDal_DigitalOutputLevel[IODAL_MAX_DIO_DESCRIPTORS];


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
/*==================================================================================================================*/
/**
@brief      IoDal_Dio_Init - Initialize the IODAL DIO components

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all IODAL components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Dio_Init(P2CONST(IoDal_BswIoConfigType, AUTOMATIC, IODAL_APP_CONST) ConfigPtr)
{
    VAR(uint8, AUTOMATIC)                DioDescriptorIndex;    
    VAR(uint8, AUTOMATIC)                BswIoChannel;
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    uint8 MaxIoChannels;
        
    
    IoDal_pDioGlobalCfgPtr = ConfigPtr;
    

    MaxIoChannels =  IoDal_pDioGlobalCfgPtr->AdcDescriptorsCount + IoDal_pDioGlobalCfgPtr->PwmChannelCount + \
                           IoDal_pDioGlobalCfgPtr->DioChannelCount  + IoDal_pDioGlobalCfgPtr->OcuChannelCount + \
                           IoDal_pDioGlobalCfgPtr->IcuChannelCount + 1;
        
    /*initialized digital data array*/
    for(DioDescriptorIndex = 0U; DioDescriptorIndex < IODAL_MAX_DIO_DESCRIPTORS; DioDescriptorIndex++)
    {    
        IoDal_DigitalOutputLevel[DioDescriptorIndex] = STD_LOW;
        IoDal_DigitalInputLevel[DioDescriptorIndex]  = STD_LOW;
        IoDal_DioResyncRequest[DioDescriptorIndex]   = FALSE; 
    }    
        
    for (BswIoChannel = 0U;  BswIoChannel < MaxIoChannels; BswIoChannel++ )
    {    
        ChannelType = ((IoDal_pDioGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
    
        switch (ChannelType)
        {    
            case IODAL_DIO_INPUT:
            break;
            
            case IODAL_DIO_OUTPUT:
            {                    
                DioDescriptorIndex    =  ((IoDal_pDioGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
                
                /*setup all configured channels to their default values*/
                IoDal_DigitalOutputLevel[DioDescriptorIndex] = (Dio_LevelType)(((IoDal_pDioGlobalCfgPtr->pDioChanDescriptor)[DioDescriptorIndex]).ChannelLevel);
                
            }break;    
            
            case IODAL_TIMER_CAPTURE:
            break;            
            
            case IODAL_TIMER_OUTPUT:
            break;
            
            case IODAL_EXT_DEV_INPUT:
            break;
            
            case IODAL_EXT_DEV_OUTPUT:    
            break;
            
            default:
            break;    
        }
    }    
}

/*===================================================================================================================*/
/**
@brief      IoDal_Dio_DeInit - DeInitialize the IODAL _DIO

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Dio_DeInit(void)
{
    VAR(uint8, AUTOMATIC)                DioDescriptorIndex;
    
    for(DioDescriptorIndex = 0U; DioDescriptorIndex < IODAL_MAX_DIO_DESCRIPTORS; DioDescriptorIndex++)
    {    
        IoDal_DigitalOutputLevel[DioDescriptorIndex] = STD_LOW;
        IoDal_DigitalInputLevel[DioDescriptorIndex]  = STD_LOW;
        IoDal_DioResyncRequest[DioDescriptorIndex]   = FALSE; 
    }
    
    IoDal_pDioGlobalCfgPtr = NULL_PTR;
}


/*===================================================================================================================*/
/**
@brief      IoDal_Dio_ReadDigitalInputs - Read the Processed Digital Inputs
@details    For channels connected to DIO  this function shall call the driver directly.
            For external devices this function shall read the internal buffer associated to the BSW channel.
			This buffer shall be cyclically updated by the IODAL main function which handles external devices.

@param[in]  BswIoChannel    Logical BSW input channel id.
@param[out] InputValue      Value read from the assigned digital input channel.

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(Std_ReturnType, IODAL_APP_CODE) IoDal_Dio_ReadInputs(IoDal_BswChannelIdType BswIoChannel, IoDal_BswValueType  * InputValue)
{    
    VAR(uint8, AUTOMATIC)               DioDescriptorIndex;
    VAR(Dio_ChannelType, AUTOMATIC)     ChannelId;
    VAR(Dio_LevelType, AUTOMATIC)       ChannelValue;
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    VAR(Std_ReturnType, AUTOMATIC)       retVal = E_NOT_OK;

    if(NULL_PTR != IoDal_pDioGlobalCfgPtr)
    {        
        DioDescriptorIndex    =  ((IoDal_pDioGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;        
        
        ChannelId    = (((IoDal_pDioGlobalCfgPtr->pDioChanDescriptor))[DioDescriptorIndex]).DioChannel;

        ChannelType = ((IoDal_pDioGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
                
        switch (ChannelType)
        {    
            case IODAL_DIO_INPUT:
                ChannelValue = Dio_ReadChannel((Dio_ChannelType)ChannelId);
                *InputValue = (IoDal_BswValueType)ChannelValue;
                retVal = E_OK;
            break;
                    
            case IODAL_TIMER_CAPTURE:
            break;
                    
            case IODAL_EXT_DEV_INPUT:    
                *InputValue  = IoDal_DigitalInputLevel[DioDescriptorIndex];
                IoDal_DioResyncRequest[DioDescriptorIndex] = TRUE; 
            break;
            
            default:
            break;
        }
    }
    else
    {
        /*do nothing*/
    }    
    
    return retVal;
}

/*===================================================================================================================*/
/**
@brief      IoDal_WriteDigitalOutputs - Write the output requests.
@details    For channels connected to DIO  this function shall call the driver directly.
            For external devices this function shall buffer the requested output value and 
			the handling of the device shall be done on the next call of the Main function.

@param[in]  BswIoChannel    Logical BSW output channel id.
@param[out] OutputValue     Value to be written to a digital output channel.

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Dio_WriteOutputs(IoDal_BswChannelIdType BswIoChannel, IoDal_BswValueType OutputValue)
{
    VAR(uint8, AUTOMATIC)               DioDescriptorIndex;
    VAR(Dio_ChannelType, AUTOMATIC)     ChannelId;
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    
    if(NULL_PTR != IoDal_pDioGlobalCfgPtr)
    {
        DioDescriptorIndex    =  ((IoDal_pDioGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;        
        
        ChannelId    = (((IoDal_pDioGlobalCfgPtr->pDioChanDescriptor))[DioDescriptorIndex]).DioChannel;

        ChannelType = ((IoDal_pDioGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
                
        switch (ChannelType)
        {
            
            case IODAL_DIO_OUTPUT:
                Dio_WriteChannel((Dio_ChannelType)ChannelId, (Dio_LevelType)OutputValue);
            break;
                    
            case IODAL_TIMER_OUTPUT:
            break;
                    
            case IODAL_EXT_DEV_OUTPUT:    
                IoDal_DigitalOutputLevel[DioDescriptorIndex] = OutputValue;
                IoDal_DioResyncRequest[DioDescriptorIndex]   = TRUE; 
            break;    
            
            default:
            break;
        }
    }
}

#if (IODAL_DIO_EXT_DEV == STD_ON)   
/*===================================================================================================================*/
/**
@brief      IoDal_Dio_ExtDevHandler - function handler for external I/O devices.
@details    This function shall be called from IODAL main function and shall be used to handle external (SPI/I2C)
            devices connected to main controller. 

@return     void
@retval     

@pre None
@post None
*/
/*===================================================================================================================*/
FUNC(void, IODAL_APP_CODE) IoDal_Dio_ExtDevHandler(IoDal_BswChannelIdType BswIoChannel)
{        
    VAR(IoDal_BswChannelType, AUTOMATIC) ChannelType;
    VAR(uint8, AUTOMATIC)                DioDescriptorIndex;
    VAR(uint8, AUTOMATIC)                ExtDeviceOutputChannel;

    VAR(IoDal_Dio_UpdateCalloutType, AUTOMATIC)   pfCallout;
    
    if(NULL_PTR != IoDal_pDioGlobalCfgPtr)
    {

        DioDescriptorIndex    =  ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswDescriptorIndex;
        
        if(TRUE == IoDal_PwmResyncRequest[DioDescriptorIndex])
        {    
                
            IoDal_PwmResyncRequest[DioDescriptorIndex] = FALSE;
                        
            /*get external device configuration data*/            
            ExtDeviceOutputChannel    =  (((*(IoDal_pPwmGlobalCfgPtr->pDioChanDescriptor))[DioDescriptorIndex]).DioChannel); 
            
            /*get external device handler function*/    
            pfCallout    =  (*(((*(IoDal_pPwmGlobalCfgPtr->pDioChanDescriptor))[DioDescriptorIndex]).pExtPwmChannelCfg))->pfPwm_ExtDev_UpdateHandler;
                
            if(NULL_PTR != pfCallout)
            {
                ChannelType = ((IoDal_pPwmGlobalCfgPtr->pBswChannelMap))[BswIoChannel].BswChannelType;
                
                if(IODAL_EXT_DEV_OUTPUT == ChannelType)
                {
                    pfCallout(ExtDeviceOutputChannel, &IoDal_DigitalOutputLevel[DioDescriptorIndex]);                      
                }
                else
                {
                    pfCallout(ExtDeviceOutputChannel, &IoDal_DigitalInputLevel[DioDescriptorIndex]);                    
                }                
            }
        }    
    }
}
#endif

#endif
/*===================================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
