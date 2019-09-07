/**
*   @file    IoDal.c
*   @version 1.0.1
*
*   @brief   Integration Framework - IO Driver Abstraction Layer component configuration file
*   @details This file implements the IODAL configuration interface to application layer.
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
*   Project              : AUTOSAR 4.2 MCAL
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


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
 ==================================================================================================*/
#include "IoDal_Drv_Cfg.h"
#include "IoDal_Cfg.h"

/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define IODAL_PBCFG_VENDOR_ID_C                 43

#define IODAL_PBCFG_AR_RELEASE_MAJOR_VERSION_C        4
#define IODAL_PBCFG_AR_RELEASE_MINOR_VERSION_C        2
#define IODAL_PBCFG_AR_RELEASE_REVISION_VERSION_C           2

#define IODAL_PBCFG_SW_MAJOR_VERSION_C                1
#define IODAL_PBCFG_SW_MINOR_VERSION_C                0
#define IODAL_PBCFG_SW_PATCH_VERSION_C                1

/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if source file and IoDal_Cfg.h header file are of the same vendor */
#if (IODAL_PBCFG_VENDOR_ID_C != IODAL_CFG_VENDOR_ID)
    #error "IoDal.c and IoDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and IoDal_Cfg.h header file are of the same Autosar version */
#if ((IODAL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != IODAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_PBCFG_AR_RELEASE_MINOR_VERSION_C != IODAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_PBCFG_AR_RELEASE_REVISION_VERSION_C != IODAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Cfg.h are different"
#endif

/* Check if source file and IoDal_Cfg.h header file are of the same Software version */
#if ((IODAL_PBCFG_SW_MAJOR_VERSION_C != IODAL_CFG_SW_MAJOR_VERSION) || \
     (IODAL_PBCFG_SW_MINOR_VERSION_C != IODAL_CFG_SW_MINOR_VERSION) || \
     (IODAL_PBCFG_SW_PATCH_VERSION_C != IODAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.c and IoDal_Cfg.h are different"
#endif


/* Check if source file and IoDal_Drv_Cfg.h header file are of the same vendor */
#if (IODAL_PBCFG_VENDOR_ID_C != IODAL_DRV_CFG_VENDOR_ID)
    #error "IoDal.c and IoDal_Drv_Cfg.h have different vendor ids"
#endif

/* Check if source file and IoDal_Drv_Cfg.h header file are of the same Autosar version */
#if ((IODAL_PBCFG_AR_RELEASE_MAJOR_VERSION_C != IODAL_DRV_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (IODAL_PBCFG_AR_RELEASE_MINOR_VERSION_C != IODAL_DRV_CFG_AR_RELEASE_MINOR_VERSION) || \
     (IODAL_PBCFG_AR_RELEASE_REVISION_VERSION_C != IODAL_DRV_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of IoDal.c and IoDal_Drv_Cfg.h are different"
#endif

/* Check if source file and IoDal_Drv_Cfg.h header file are of the same Software version */
#if ((IODAL_PBCFG_SW_MAJOR_VERSION_C != IODAL_DRV_CFG_SW_MAJOR_VERSION) || \
     (IODAL_PBCFG_SW_MINOR_VERSION_C != IODAL_DRV_CFG_SW_MINOR_VERSION) || \
     (IODAL_PBCFG_SW_PATCH_VERSION_C != IODAL_DRV_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of IoDal.c and IoDal_Drv_Cfg.h are different"
#endif



/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

#define    IODAL_MAX_CHANNELS_HW_VAR_0                10U

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
static Adc_ValueGroupType IoDal_AniDescriptor_AdcLedFdbkGroup0_HW_VAR_0[1]    =    {0};
static Adc_ValueGroupType IoDal_AniDescriptor_AdcLedFdbkGroup1_HW_VAR_0[1]    =    {0};
static Adc_ValueGroupType IoDal_AniDescriptor_AdcPotGroup_HW_VAR_0[1]    =    {0};

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*Critical Note: A BSW analog input using SW trigger can only reference TT elements FROM ONE TABLE... 
               if analog inputs use different OCU channels/TT Table than the generation tool should report an Error.
            
                The  Time-Triggered Table used by Analog input has the exact size determined by the number of inputs that have as referees
                entries in the TT Tab
                Basically if a user defines 10 entries and only uses 5 inputs than the size of the OcuTimeTable will be 5 and only the entries referenced will be printed in the Table; all other will be ignored.
 */
           

/*Entries for TimeTriggerTable_0 scheduling points used as SW trigger by ADC*/
static CONST(uint16, IODAL_CONST) IoDal_OcuTimeTable_TimeTriggerTable_0_HW_VAR_0[3] = {6250, 12500, 3000};

/*SYNC PWM HW CONFIGURATIONS*/


#if IODAL_MAX_DIO_CHANNELS_HW_VAR_0 > 0U
/*DIO Channel descriptor*/
static CONST(IoDal_DigitalDescriptorType, IODAL_CONST) IoDal_DioChannelDescriptor_HW_VAR_0[IODAL_MAX_DIO_CHANNELS_HW_VAR_0] =
{ 
    {
        DioConf_DioChannel_Dio_Key1,        /*DIO Channel ID*/
        STD_LOW,
        NULL_PTR                /*External Device*/
    },
 
    {
        DioConf_DioChannel_DioChannel_1,        /*DIO Channel ID*/
        STD_LOW,
        NULL_PTR                /*External Device*/
    },
 
    {
        DioConf_DioChannel_DioChannel_2,        /*DIO Channel ID*/
        STD_LOW,
        NULL_PTR                /*External Device*/
    }
};
#endif
#if IODAL_MAX_PWM_CHANNELS_HW_VAR_0 > 0U
/*PWM Channel descriptor*/
static CONST(IoDal_PwmDescriptorType, IODAL_CONST) IoDal_PwmChannelDescriptor_HW_VAR_0[IODAL_MAX_PWM_CHANNELS_HW_VAR_0] =
{ 
    {
        PwmChannel_1,        /*PWM Channel ID*/ 
        NULL_PTR,                /*Sync FTM not used. No additional configuration required*/
        NULL_PTR                /*External Device*/
    },
 
    {
        PwmChannel_2,        /*PWM Channel ID*/ 
        NULL_PTR,                /*Sync FTM not used. No additional configuration required*/
        NULL_PTR                /*External Device*/
    },
 
    {
        PwmChannel_0,        /*PWM Channel ID*/ 
        NULL_PTR,                /*Sync FTM not used. No additional configuration required*/
        NULL_PTR                /*External Device*/
    }
};
#endif

#if IODAL_MAX_ANALOG_CHANNELS_HW_VAR_0 > 0U
/*Analog Channel descriptor*/
static CONST(IoDal_AnalogDescriptorType, IODAL_CONST) IoDal_AdcChannelDescriptor_HW_VAR_0[IODAL_MAX_ANALOG_CHANNELS_HW_VAR_0] =
{ 
    {
        AdcLedFdbkGroup0,        /*ADC Group ID*/     
        0,         /*ADC Channel Position in the ADC AdcLedFdbkGroup0 Group definition*/
        50,        /*ADC Conversion Time(in ticks)*/
        IoDal_AniDescriptor_AdcLedFdbkGroup0_HW_VAR_0,    /**ADC result data array */
        1    /*Time trigger entry index within IoDal_OcuTimeTable_*_HW_VAR_0*/            
    },
 
    {
        AdcLedFdbkGroup1,        /*ADC Group ID*/     
        0,         /*ADC Channel Position in the ADC AdcLedFdbkGroup1 Group definition*/
        50,        /*ADC Conversion Time(in ticks)*/
        IoDal_AniDescriptor_AdcLedFdbkGroup1_HW_VAR_0,    /**ADC result data array */
        2    /*Time trigger entry index within IoDal_OcuTimeTable_*_HW_VAR_0*/            
    },
 
    {
        AdcPotGroup,        /*ADC Group ID*/     
        0,         /*ADC Channel Position in the ADC AdcPotGroup Group definition*/
        50,        /*ADC Conversion Time(in ticks)*/
        IoDal_AniDescriptor_AdcPotGroup_HW_VAR_0,    /**ADC result data array */
        0    /*Time trigger entry index within IoDal_OcuTimeTable_*_HW_VAR_0*/            
    }

};
#endif

#if  IODAL_MAX_ICU_CHANNELS_HW_VAR_0 > 0U
/*ICU Channel descriptor*/
static CONST(IoDal_IcuDescriptorType, IODAL_CONST) IoDal_IcuChannelDescriptor_HW_VAR_0[IODAL_MAX_ICU_CHANNELS_HW_VAR_0] =
{};
#endif

#if  IODAL_MAX_OCU_CHANNELS_HW_VAR_0 > 0U
/*OCU Channel descriptor*/
static CONST(IoDal_OcuDescriptorType, IODAL_CONST) IoDal_OcuChannelDescriptor_HW_VAR_0[IODAL_MAX_OCU_CHANNELS_HW_VAR_0] =
{ 
    {
        OcuChannel_0,        /*OCU Channel ID*/
        3,        /*Size of the timetable*/
        IoDal_OcuTimeTable_TimeTriggerTable_0_HW_VAR_0
    }
};
#endif

/*Mapping of BSW Channels to Specific Channel Descriptors*/
static CONST(IoDal_BswChannelMapType, IODAL_CONST) IoDal_BswChannelMap_HW_VAR_0[IODAL_MAX_CHANNELS_HW_VAR_0] = 
{    /*IoDAL_ADCTRIGGER*/
    {
        IODAL_TIMER_OUTPUT,        /*Datatype of current channel*/
        0        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_AN_FBK_PWM0*/
    {
        IODAL_ANALOG_SW_TRIG,        /*Datatype of current channel*/
        0        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_AN_FBK_PWM1*/
    {
        IODAL_ANALOG_SW_TRIG,        /*Datatype of current channel*/
        1        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_AN_POT*/
    {
        IODAL_ANALOG_SW_TRIG,        /*Datatype of current channel*/
        2        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_DIGITAL_KEY*/
    {
        IODAL_DIO_INPUT,        /*Datatype of current channel*/
        0        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_DOUT0*/
    {
        IODAL_DIO_OUTPUT,        /*Datatype of current channel*/
        1        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_DOUT1*/
    {
        IODAL_DIO_OUTPUT,        /*Datatype of current channel*/
        2        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_PMW1*/
    {
        IODAL_PWM_FIXED_PERIOD_OUTPUT,        /*Datatype of current channel*/
        0        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_PMW2*/
    {
        IODAL_PWM_FIXED_PERIOD_OUTPUT,        /*Datatype of current channel*/
        1        /*Index of current channel in own Datatype Channel Descriptor*/
    },    
    /*IoDAL_PWM0*/
    {
        IODAL_PWM_FIXED_PERIOD_OUTPUT,        /*Datatype of current channel*/
        2        /*Index of current channel in own Datatype Channel Descriptor*/
    }    
};
/*=====================================================================================================================*/
/**
@brief      IoDal_AdcBufferSetup - callout to initialize ADC buffers
@details    This function is used to setup external buffers for ADC results for each configured ADC group

@return     void

@pre None
@post None
*/
/*=====================================================================================================================*/
FUNC(void, SAMPLE_APP_CODE) IoDal_AdcBufferSetup(void)
{
    (void)Adc_SetupResultBuffer(AdcLedFdbkGroup0, &IoDal_AniDescriptor_AdcLedFdbkGroup0_HW_VAR_0[0]);
    (void)Adc_SetupResultBuffer(AdcLedFdbkGroup1, &IoDal_AniDescriptor_AdcLedFdbkGroup1_HW_VAR_0[0]);
    (void)Adc_SetupResultBuffer(AdcPotGroup, &IoDal_AniDescriptor_AdcPotGroup_HW_VAR_0[0]);
}

CONST(IoDal_BswIoConfigType, IODAL_CONST) IoDal_Config[IODAL_MAX_HW_VARIANTS] = 
{    
    {
        3, /*Number of Analog channels*/
        0,    /*Index of Analog SW Trigger descriptor*/
        3, /*Number of Pwm channels*/
        3, /*Number of Digital channels*/
        1, /*Number of Output Compare  channels*/
        0, /*Number of input Capture channels*/
#if IODAL_MAX_ANALOG_CHANNELS_HW_VAR_0 > 0U
        IoDal_AdcChannelDescriptor_HW_VAR_0,
        &IoDal_AdcBufferSetup,
#endif
#if IODAL_MAX_PWM_CHANNELS_HW_VAR_0 > 0U
        IoDal_PwmChannelDescriptor_HW_VAR_0,
#endif
#if IODAL_MAX_DIO_CHANNELS_HW_VAR_0 > 0U        
        IoDal_DioChannelDescriptor_HW_VAR_0,
#endif
#if IODAL_MAX_OCU_CHANNELS_HW_VAR_0 > 0U        
        IoDal_OcuChannelDescriptor_HW_VAR_0,
#endif
#if IODAL_MAX_ICU_CHANNELS_HW_VAR_0 > 0U        
        IoDal_IcuChannelDescriptor_HW_VAR_0,
#endif        
        IoDal_BswChannelMap_HW_VAR_0
    }    
};
