/**
*    @file        SwcActuators.c
*    @version     1.0.1
*
*    @brief       Integration Framework - Actuators SW component.
*
*    @details     Application handler for all Outputs in the system.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup SWCACTUATORS
*   @{
*
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "typedefs.h"
#include "SwcActuators.h"
#include "SwcRte_Types.h"
#include "SwcRte.h"
#include "SwcRte_Cfg.h"

/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
====================================================================================================*/
#define SWCACTUATORS_VENDOR_ID_C                          43

#define SWCACTUATORS_SW_MAJOR_VERSION_C                   1
#define SWCACTUATORS_SW_MINOR_VERSION_C                   0
#define SWCACTUATORS_SW_PATCH_VERSION_C                   1
/*==================================================================================================
*                                     FILE VERSION CHECKS
===================================================================================================*/
/* Check if SwcActuators.c source file and SwcActuators.h header file are of the same vendor */
#if (SWCACTUATORS_VENDOR_ID_C != SWCACTUATORS_VENDOR_ID)
    #error "SwcActuators.c and SwcActuators.h have different vendor ids"
#endif


/* Check if SwcActuators.c source file and SwcActuators.h header file are of the same Software version */
#if ((SWCACTUATORS_SW_MAJOR_VERSION_C != SWCACTUATORS_SW_MAJOR_VERSION) || \
     (SWCACTUATORS_SW_MINOR_VERSION_C != SWCACTUATORS_SW_MINOR_VERSION) || \
     (SWCACTUATORS_SW_PATCH_VERSION_C != SWCACTUATORS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcActuators.c and SwcActuators.h are different"
#endif

/* Check if SwcActuators.c source file and SwcRte_Types.h header file are of the same vendor */
#if (SWCACTUATORS_VENDOR_ID_C != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcActuators.c and SwcRte_Types.h have different vendor ids"
#endif


/* Check if SwcActuators.c source file and SwcRte_Types.h header file are of the same Software version */
#if ((SWCACTUATORS_SW_MAJOR_VERSION_C != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCACTUATORS_SW_MINOR_VERSION_C != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCACTUATORS_SW_PATCH_VERSION_C != SWCRTE_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcActuators.c and SwcRte_Types.h are different"
#endif


/* Check if SwcActuators.c source file and  SwcRte.h header file are of the same vendor */
#if (SWCACTUATORS_VENDOR_ID_C != SWCRTE_VENDOR_ID)
    #error "SwcActuators.c and SwcRte.h have different vendor ids"
#endif


/* Check if SwcActuators.c source file and SwcRte.h header file are of the same Software version */
#if ((SWCACTUATORS_SW_MAJOR_VERSION_C != SWCRTE_SW_MAJOR_VERSION) || \
     (SWCACTUATORS_SW_MINOR_VERSION_C != SWCRTE_SW_MINOR_VERSION) || \
     (SWCACTUATORS_SW_PATCH_VERSION_C != SWCRTE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcActuators.c and SwcRte.h are different"
#endif


/* Check if SwcActuators.c source file and SwcRte_Cfg.h header file are of the same vendor */
#if (SWCACTUATORS_VENDOR_ID_C != SWCRTE_CFG_VENDOR_ID)
    #error "SwcActuators.c and SwcRte_Cfg.h have different vendor ids"
#endif


/* Check if SwcActuators.c source file and SwcRte_Cfg.h header file are of the same Software version */
#if ((SWCACTUATORS_SW_MAJOR_VERSION_C != SWCRTE_CFG_SW_MAJOR_VERSION) || \
     (SWCACTUATORS_SW_MINOR_VERSION_C != SWCRTE_CFG_SW_MINOR_VERSION) || \
     (SWCACTUATORS_SW_PATCH_VERSION_C != SWCRTE_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SwcActuators.c and SwcRte_Cfg.h are different"
#endif


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

           
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

 
/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static const SwcRte_GlobalConfigType * SwcActuators_ConfigPtr;

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
@brief      SwcActuators_Init - main processing function for SWC Actuators
@details    This function is called periodically by the OS or by the main() function.

@param[in]  ConfigPtr    Pointer to configuration data (this data is shared between all SWC components)

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcActuators_Init( const SwcRte_GlobalConfigType * ConfigPtr )
{    
    SwcActuators_ConfigPtr = ConfigPtr;      
}


/*================================================================================================*/
/**
@brief      SwcActuators_MainRunnable - main processing function for Sensors
@details    This function is called periodically by the OS or by the main() function.
            On each entry, the Sensors runnable will process only the instance that is given as parameter.

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
/*================================================================================================*/
void SwcActuators_MainRunnable()
{
    SwcRte_AppChannelIdType AppChannelId;
    SwcRte_AppInstanceIdType RteAppInstance;
    SwcRte_OutputValueType OutputValue;

#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)    
    AppLightingActuatorValueType  LightingOutputValue;
#endif
#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)    
    AppMotorCtrlActuatorValueType  MotorCtrlOutputValue;
#endif    
    SwcRte_AppInstanceType   AppType;

    for (RteAppInstance = 0; RteAppInstance < SWCRTE_MAX_APP_INSTANCES; RteAppInstance++)
    {
        /*get the sensor channel id base on type of channel  */
        AppType = SwcActuators_ConfigPtr[RteAppInstance].eInstanceType;            

        /*process values differently depending on their type*/
        switch (AppType)
        {
#if (SWCRTE_LIGTHING_APP_ENABLED == SWCRTE_STD_ON)    
            case SWCRTE_LIGHTING:
            {
                /*read output info associated to that current instance*/
                SwcRte_ReadLightingOutputRequest(RteAppInstance,  &LightingOutputValue);

                /*for all available inputs */
                for (AppChannelId = 0; AppChannelId < SwcActuators_ConfigPtr[RteAppInstance].u8NoOutputChannel; AppChannelId++)
                {
                    OutputValue = LightingOutputValue.aLightingOutputIntesity[AppChannelId];
                    
                    SwcRte_WriteOutputs(RteAppInstance, AppChannelId,  OutputValue);
                }
            }
            break;
#endif
            
#if (SWCRTE_MOTORCTRL_APP_ENABLED == SWCRTE_STD_ON)                
            case SWCRTE_MOTORCTRL:
            {    
                SwcRte_ReadMotorCtrlOutputRequest((RteAppInstance - SWCRTE_MOTORCTRL_INSTANCE_OFFSET),  &MotorCtrlOutputValue);
                
            }
            break;
#endif

            default:
               /*DO NOTHING*/
            break;                
        }
    }
}


/*================================================================================================*/
#ifdef __cplusplus
}
#endif
