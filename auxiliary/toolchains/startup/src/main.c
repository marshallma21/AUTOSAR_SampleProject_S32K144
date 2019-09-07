/**
*    @file        main.c
*    @version     1.0.1
*
*    @brief       Integration Framework -  main function
*     
*    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*    All Rights Reserved.
*
*    This file contains sample code only. It is not part of the production code deliverables.
*/       
/*=================================================================================================
*    Platform      :      ARM
*    Build Version :      S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
==================================================================================================*/
/*==================================================================================================
====================================================================================================*/

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

#include "SysDal.h"
#if defined(AUTOSAR_OS_NOT_USED)
#include "SysDal_IntSch.h"
#endif
#include "Mcal.h"


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

/**
@brief This is the global variable that holds all the sample app specific data
*/
/*
extern volatile SampleAppData_T  stSampleAppData;
static SampleAppData_T * p_stSampleAppData = (SampleAppData_T *)&stSampleAppData;
*/

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
@brief   Main function of the sample application using Leds.
@details The sample configures the processor and uses leds and keys from the mainboard the following way:
                LED1 - Light intensity controlled by Potentiometer
                LED2 - Will stay ON while Key1 is pressed and will go OFF when watchdog will run out
                LED3 - Blinking driven by GPT
                LED4 - Always ON
                KEY1 - disable watchdog and switch on the LED2
          The function will never return.
@return Returns ok
@retval 0 - Ok
@pre None
@post None
*/
int main( )
{
#if defined(AUTOSAR_OS_NOT_USED)
    /*Std_ReturnType ret = E_OK;
    uint32 task;*/
#endif  /* AUTOSAR_OS_NOT_USED */
    /* OS/stand-alone initialization - prepare the tasks(for OS), or the threads when no OS is used(uses Timers) */
    
#ifdef D_CACHE_ENABLE  
    /*init Data caches*/
    m4_cache_init(SYS_CACHE);
#endif

#ifdef I_CACHE_ENABLE
    /*init Code caches*/
    m4_cache_init(CODE_CACHE);
#endif

    SysDal_Init();
	
#if defined(AUTOSAR_OS_NOT_USED)
    SysDal_IntSch_TaskScheduler();

   /* CONSOLE_FLUSH();*/
#endif
    return 0;
}

#ifndef AUTOSAR_OS_NOT_USED

/****************************************************************************
 * Hooks (Remember to activate these in the ProOSEK configurator if desired!)
 ****************************************************************************/

void StartupHook(void)
{
    /* can be used to do some initialization before the first task runs */
    /* call Initialization task */
    /*SampleAppInitTask( p_stSampleAppData );*/
}


void ErrorHook(StatusType myError)
{
    if (myError == E_OS_LIMIT) return; /* Can happen after debugger break */
    ShutdownOS(myError);
}

TASK(LoopTask)
{
    while(1)
    {
        ClearEvent(OsEvent_loop); 
#if (USE_DGB_LED_TASK0 ==STD_ON)        
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_HIGH);
#endif    

#if (SAMPLE_APP_USE_FEE == STD_ON)   
#if (USE_FEE_MODULE == STD_ON)  && (USE_FLS_MODULE == STD_ON)
        if (FEE_FINAL_STATE != stSampleAppData.stFeeData.ucState)
        {
            MemIf_StatusType memif_status;

            memif_status = Fee_GetStatus();
            if (MEMIF_IDLE != memif_status)
            {
                Fee_MainFunction();
            }

            memif_status = Fls_GetStatus();
            if (MEMIF_IDLE != memif_status)
            {
                Fls_MainFunction();
            }
        }
#endif  /*USE_FEE_MODULE && USE_FLS_MODULE */
#endif    
        task0++;
#if (USE_DGB_LED_TASK0 ==STD_ON)            
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_LOW);
#endif        

        WaitEvent(OsEvent_loop);    
    }
}



TASK(TASK1)
{   
    while(1)
    {
        ClearEvent(OsEvent_Task1);

#if (USE_DGB_LED_TASK1 ==STD_ON)            
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_HIGH);
#endif            
        SampleAppTask1( p_stSampleAppData );

        task1++;
#if (USE_DGB_LED_TASK1 ==STD_ON)            
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_LOW);
#endif    

        WaitEvent(OsEvent_Task1);
    }
}
TASK(TASK2)
{
    while(1)
    {
        ClearEvent(OsEvent_Task2);

#if (USE_DGB_LED_TASK2 ==STD_ON)        
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_HIGH);
#endif        
        
        SampleAppTask2( p_stSampleAppData );
        
        task2++;
#if (USE_DGB_LED_TASK2 ==STD_ON)            
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_LOW);
#endif        

        WaitEvent(OsEvent_Task2);
        
    }
}
TASK(TASK3)
{
    while(1)
    {
        ClearEvent(OsEvent_Task3);

#if (USE_DGB_LED_TASK3 ==STD_ON)        
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_HIGH);
#endif        
        SampleAppTask3( p_stSampleAppData );
        
        task3++;
#if (USE_DGB_LED_TASK3 ==STD_ON)            
        Dio_WriteChannel((Dio_ChannelType)DioConf_DioChannel_Dio_DbgLed, (Dio_LevelType)STD_LOW);
#endif        

        WaitEvent(OsEvent_Task3);      
    }
}
#endif

#ifdef __cplusplus
}
#endif
