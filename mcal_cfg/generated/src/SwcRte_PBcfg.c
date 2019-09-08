/**
*   @file    SwcRte_PBcfg.c
*   @version 1.0.0
*   @brief   - TBD
*   @details - TBD
*
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : Stm_Pit_Ftm
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : S32V234_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170622
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
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
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "typedefs.h"
#include "SwcRte_Cfg.h"
#include "SwcRte_Types.h"

#if (SWCRTE_USE_IODAL == SWCRTE_STD_ON)
	#include "IoDal_Cfg.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWCRTE_VENDOR_ID_PBCFG_C                      43

#define SWCRTE_SW_MAJOR_VERSION_PBCFG_C               1
#define SWCRTE_SW_MINOR_VERSION_PBCFG_C               0
#define SWCRTE_SW_PATCH_VERSION_PBCFG_C               1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if SwcRte_PBcfg.c file and SwcRte_Types.h header file are of the same vendor */
#if ( SWCRTE_VENDOR_ID_PBCFG_C != SWCRTE_CFG_VENDOR_ID)
    #error "SwcRte_PBcfg.c and SwcRte_Cfg.h have different vendor ids"
#endif

/* Check if SwcRte_PBcfg.c and SwcRte_Cfg.h header files are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_PBCFG_C != SWCRTE_CFG_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_PBCFG_C != SWCRTE_CFG_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_PBCFG_C != SWCRTE_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of SwcRte_PBcfg.c and SwcRte_Cfg.h are different"
#endif

/* Check if SwcRte_PBcfg.c file and SwcRte_Types.h header file are of the same vendor */
#if ( SWCRTE_VENDOR_ID_PBCFG_C != SWCRTE_TYPES_VENDOR_ID)
    #error "SwcRte_PBcfg.c and SwcRte_Types.h have different vendor ids"
#endif

/* Check if SwcRte_PBcfg.c and SwcRte_Types.h header files are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_PBCFG_C != SWCRTE_TYPES_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_PBCFG_C != SWCRTE_TYPES_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_PBCFG_C != SWCRTE_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of SwcRte_PBcfg.c and SwcRte_Types.h are different"
#endif

#if (SWCRTE_USE_IODAL == SWCRTE_STD_ON)
/* Check if SwcRte_PBcfg.c file and SwcRte_Types.h header file are of the same vendor */
#if ( SWCRTE_VENDOR_ID_PBCFG_C != IODAL_CFG_VENDOR_ID)
    #error "SwcRte_PBcfg.c and SwcRte_Types.h have different vendor ids"
#endif

/* Check if SwcRte_PBcfg.c and IoDal_Cfg.h header files are of the same Software version */
#if ((SWCRTE_SW_MAJOR_VERSION_PBCFG_C != IODAL_CFG_SW_MAJOR_VERSION) || \
     (SWCRTE_SW_MINOR_VERSION_PBCFG_C != IODAL_CFG_SW_MINOR_VERSION) || \
     (SWCRTE_SW_PATCH_VERSION_PBCFG_C != IODAL_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of SwcRte_PBcfg.c and IoDal_Cfg.h are different"
#endif
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*array of configuration data containing the configuration for each input channel (sensors and feedback channels) for instance 0*/
const SwcRte_InputChannelConfigType SwcRte_LightingInputChannelMap_0_PB[2] = 
{
    /*Sensor channel*/
    {
        IoDAL_AN_POT,    /*IO Channel ID*/
        SWCRTE_ANALOG_POT_SENS        /*IO Channel Type*/
    },
    
    /*feedback channel for channel 0*/
    {
        IoDAL_AN_FBK_PWM1,        /*IO Channel ID*/
        SWCRTE_ANALOG_FDBK_SENS        /*IO Channel Type*/
    }            
};
            
/*array of configuration data containing the configuration for each input channel (sensors and feedback channels) for instance 1*/
const SwcRte_InputChannelConfigType SwcRte_LightingInputChannelMap_1_PB[3] = 
{
    /*Sensor channel*/
    {
        IoDAL_DIGITAL_KEY2,    /*IO Channel ID*/
        SWCRTE_DIGITAL_SENS        /*IO Channel Type*/
    },
    
    /*feedback channel for channel 0*/
    {
        255,        /*Channel has no configured feedback, thus no input channel*/
        SWCRTE_NO_SENS
    },
    
    /*feedback channel for channel 1*/
    {
        255,        /*Channel has no configured feedback, thus no input channel*/
        SWCRTE_NO_SENS
    }            
};
            
/*array of configuration data containing the configuration for each input channel (sensors and feedback channels) for instance 2*/
const SwcRte_InputChannelConfigType SwcRte_LightingInputChannelMap_2_PB[2] = 
{
    /*Sensor channel*/
    {
        IoDAL_DIGITAL_KEY,    /*IO Channel ID*/
        SWCRTE_DIGITAL_SENS        /*IO Channel Type*/
    },
    
    /*feedback channel for channel 0*/
    {
        255,        /*Channel has no configured feedback, thus no input channel*/
        SWCRTE_NO_SENS
    }            
};
            

const SwcRte_OutputChannelConfigType SwcRte_LightingOutputChannelMap_0_PB[1] = 
{    
    
    /*Output Channel 0*/
    {
        IoDAL_PMW1    /*IO Channel ID*/
    }
};

const SwcRte_OutputChannelConfigType SwcRte_LightingOutputChannelMap_1_PB[2] = 
{    
    
    /*Output Channel 0*/
    {
        IoDAL_DOUT0    /*IO Channel ID*/
    },    
    
    /*Output Channel 1*/
    {
        IoDAL_DOUT1    /*IO Channel ID*/
    }
};

const SwcRte_OutputChannelConfigType SwcRte_LightingOutputChannelMap_2_PB[1] = 
{    
    
    /*Output Channel 0*/
    {
        IoDAL_PWM0    /*IO Channel ID*/
    }
};

const SwcRte_GlobalConfigType SwcRte_AppInstanceMapPB[SWCRTE_MAX_APP_INSTANCES] = 
{
    
    {
        SWCRTE_LIGHTING,        /*Application type*/
        SWCRTE_PWM_OUT,             /*Output signal type*/
        1,        /*Number of input channels*/
        1,    /*Number of output channels*/
        SwcRte_LightingInputChannelMap_0_PB,    /*Input channel map configuration structure*/
        SwcRte_LightingOutputChannelMap_0_PB    /*Output channel map configuration structure*/
    },    
    {
        SWCRTE_LIGHTING,        /*Application type*/
        SWCRTE_DIGITAL_OUT,             /*Output signal type*/
        1,        /*Number of input channels*/
        2,    /*Number of output channels*/
        SwcRte_LightingInputChannelMap_1_PB,    /*Input channel map configuration structure*/
        SwcRte_LightingOutputChannelMap_1_PB    /*Output channel map configuration structure*/
    },    
    {
        SWCRTE_LIGHTING,        /*Application type*/
        SWCRTE_PWM_OUT,             /*Output signal type*/
        1,        /*Number of input channels*/
        1,    /*Number of output channels*/
        SwcRte_LightingInputChannelMap_2_PB,    /*Input channel map configuration structure*/
        SwcRte_LightingOutputChannelMap_2_PB    /*Output channel map configuration structure*/
    }    

};


/*PostBuild configuration structure.*/
/** @violates @ref SWCRTE_PBCFG_C_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
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

#ifdef __cplusplus
}
#endif

/** @} */
