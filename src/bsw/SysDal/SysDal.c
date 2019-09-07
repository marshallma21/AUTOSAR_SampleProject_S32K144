/**
*   @file           SysDal.c
*   @version        1.0.1
*
*   @brief          Integration Framework - SysDal Abstraction Layer component
*   @details        This file implements the SysDal interface to application layer.
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup SYSDAL
*   @{
*/
/*==================================================================================================
*   Platform             : ARM
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
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
#include "SysDal.h"
#include "SysDal_Cfg.h"
#include "Mcu.h"
#include "sys_init.h"
#include "typedefs.h"
#include "modules.h"
#if defined(AUTOSAR_OS_NOT_USED)
#include "SysDal_IntSch.h"
#include "Gpt.h"
#endif
/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define SYSDAL_VENDOR_ID_C                       43

#define SYSDAL_AR_RELEASE_MAJOR_VERSION_C        4
#define SYSDAL_AR_RELEASE_MINOR_VERSION_C        2
#define SYSDAL_AR_RELEASE_REVISION_VERSION_C     2

#define SYSDAL_SW_MAJOR_VERSION_C                1
#define SYSDAL_SW_MINOR_VERSION_C                0
#define SYSDAL_SW_PATCH_VERSION_C                1
/*===================================================================================================================
*                                     FILE VERSION CHECKS
====================================================================================================================*/
/* Check if source file and SYSDAL header file are of the same vendor */
#if (SYSDAL_VENDOR_ID_C != SYSDAL_VENDOR_ID)
    #error "SysDal.c and SysDal.h have different vendor ids"
#endif

/* Check if source file and SYSDAL header file are of the same Autosar version */
#if ((SYSDAL_AR_RELEASE_MAJOR_VERSION_C != SYSDAL_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_AR_RELEASE_MINOR_VERSION_C != SYSDAL_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_AR_RELEASE_REVISION_VERSION_C != SYSDAL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal.c and SysDal.h are different"
#endif

/* Check if source file and SYSDAL header file are of the same Software version */
#if ((SYSDAL_SW_MAJOR_VERSION_C != SYSDAL_SW_MAJOR_VERSION) || \
     (SYSDAL_SW_MINOR_VERSION_C != SYSDAL_SW_MINOR_VERSION) || \
     (SYSDAL_SW_PATCH_VERSION_C != SYSDAL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal.c and SysDal.h are different"
#endif

/* Check if source file and SYSDAL configuration header file are of the same vendor */
#if (SYSDAL_VENDOR_ID_C != SYSDAL_CFG_VENDOR_ID)
    #error "SysDal.c and SysDal_Cfg.h have different vendor ids"
#endif

/* Check if source file and SYSDAL configuration header file are of the same Autosar version */
#if ((SYSDAL_AR_RELEASE_MAJOR_VERSION_C != SYSDAL_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_AR_RELEASE_MINOR_VERSION_C != SYSDAL_CFG_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_AR_RELEASE_REVISION_VERSION_C != SYSDAL_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal.c and SysDal_Cfg.h are different"
#endif

/* Check if source file and SYSDAL configuration header file are of the same software version */
#if ((SYSDAL_SW_MAJOR_VERSION_C != SYSDAL_CFG_SW_MAJOR_VERSION) || \
     (SYSDAL_SW_MINOR_VERSION_C != SYSDAL_CFG_SW_MINOR_VERSION) || \
     (SYSDAL_SW_PATCH_VERSION_C != SYSDAL_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal.c and SysDal_Cfg.h are different"
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
SysDal_EcuModeType SysDal_State = SYSDAL_STATE_STARTUP;
extern const SysDal_ConfigType SysDal_Config;
SysDal_EcuModeType UserRequest[SYSDAL_USERS];
#if 0
/*Used in future implementation -Sleep/WakeUp*/
Mcu_ResetType ResetReason;
#endif
#if defined(AUTOSAR_OS_NOT_USED)
extern const vuint32_t IntcVectorTableHw[];
#endif

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/
FUNC (void, ICU_CODE) WakeUpNotification(void);
#if 0
FUNC (void, SAMPLE_APP_CODE) SysDal_PrepareGoToSleep(void);
FUNC (void, SAMPLE_APP_CODE) SysDal_ValidateWakeupReason(void);
#endif
/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/
/**
@brief      WakeUpNotification - Notification generated at wakeup
@details    Shall be used to reinitialise the system 
            
@return     None

@pre None
@post None
*/
FUNC (void, ICU_CODE) WakeUpNotification(void)
{
    SysDal_Init();
}

#if 0 
/**
@brief      SysDal_PrepareGoToSleep - Function used to prepare entering the LowPower mode
@details    
            
@return     None

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_PrepareGoToSleep(void)
{
    /*Actions before going to sleep*/
}
#endif

#if 0 
/**
@brief      SysDal_ValidateWakeupReason - Function used to validate a WakeUp
@details    
            
@return     None

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_ValidateWakeupReason(void)
{
    /*Validate WakeUp reason*/
}
#endif
/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
/**
@brief      SysDal_Init - Initialization function for System Driver abstraction module
@details    Shall be used to set all Interrupts used by the system 
            Shall be used to initialize all drivers before starting the system
            
@return     None

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_Init(void)
{
#if 0
    /*Used in future implementation - validation for WakeUp*/
    boolean ValidWakeupReason = TRUE;    
#endif
    uint8 UserId = 0;
    SysDal_State = SYSDAL_STATE_STARTUP;        
   
#if (USE_MCU_MODULE == STD_ON)
    Mcu_Init(&McuModuleConfiguration);
    Mcu_InitClock(McuClockSettingConfig_0);
#if(MCU_NO_PLL==STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() ) 
    {
       /* wait until all enabled PLLs are locked */
    }
    /* switch system clock tree to PLL */
    Mcu_DistributePllClock();
#endif
#endif

    for (UserId = 0; UserId < SYSDAL_USERS; UserId++)
    {
        UserRequest[UserId] = SYSDAL_STATE_UP;
    } 
    /*set interrupts priority*/
    SysDal_Config.SetProgrammableInterruptsCallout();   
#if 0
    /*Used in future implementation - validation for WakeUp*/
    SysDal_ValidateWakeupReason();
    if (FALSE == ValidWakeupReason)       
    {
       /*No valid wakeup go  back to configured Sleep Mode*/
#if (SYSDAL_LOW_POWER_MODE == STD_ON)    
       SysDal_Config.SetWakeupEventsCallout();
#endif        
       SysDal_State = SYSDAL_STATE_SLEEP;    
       /*Set MCU to Sleep Mode*/
       Mcu_SetMode((Mcu_ModeType) 1);
#if defined(AUTOSAR_OS_NOT_USED)        
       SysDal_IntSch_StopScheduler();
#else
       StopOS();/*Stop OS*/
#endif                
   }
   else
#endif
   {
       /*Valid wakeup go to Up Mode*/
       SysDal_Config.InitDriversCallout();
#if (SYSDAL_LOW_POWER_MODE == STD_ON)          
       /*Disable all wakeup events -- system is running*/
       SysDal_Config.ClearProgrammableInterruptsCallout();
#endif
 
#if defined(AUTOSAR_OS_NOT_USED)        
       SysDal_IntSch_StartScheduler();
#else
       StartOS();
#endif    
       SysDal_State=SYSDAL_STATE_UP;
       /*Set MCU to Up Mode*/
       Mcu_SetMode((Mcu_ModeType) 0);
    }    
}

/*Call from SWC to change the ECU mode*/
FUNC(void, SAMPLE_APP_CODE) SysDal_WriteModeRequest(SysDal_EcuModeUsersType UserId, SysDal_EcuModeType Mode)
{
    UserRequest[UserId] = Mode;
}

/**
@brief      SysDal_Main - Main function for System Driver abstraction module
@details    Shall be used to compute the request for LowPower mode based on users request (from SWC)
            Shall be used to set the request LowPower 
            
@return     None

@pre None
@post None
*/

FUNC (void, SAMPLE_APP_CODE) SysDal_MainFunction(void)
{
#if (SYSDAL_LOW_POWER_MODE == STD_ON)     
    static SysDal_EcuModeType CurrentEcuMode = SYSDAL_STATE_UP;    
    boolean GoToSlepp = TRUE;
    SysDal_EcuModeUsersType UserId = 0;
     
    GoToSlepp = TRUE;
    for (UserId = 0; UserId < SYSDAL_USERS; UserId++)
    {
        if (SYSDAL_STATE_UP == UserRequest[UserId])
        {
            GoToSlepp = FALSE;
        }
        else
        {
            /*do nothing*/
        }
    }
#if 0   
/*Used in future implementation - Sleep/WakeUp*/
    if (TRUE == GoToSlepp)
    {
        /*Enable all wakeup events -- system is running*/
        SysDal_Config.SetProgrammableInterruptsCallout();
        SysDal_PrepareGoToSleep();
        SysDal_State = SYSDAL_STATE_SLEEP;
        CurrentEcuMode = SysDal_State;
        /*Set Mcu_SleepMode*/
        Mcu_SetMode((Mcu_ModeType) 1);
    }    
    else
#endif
    {
        SysDal_State = SYSDAL_STATE_UP;
        CurrentEcuMode = SysDal_State;
    }
#endif        
}

#ifdef __cplusplus
}
#endif

