/**
*   @file           SysDal_IntSch.c
*   @version        1.0.1
*
*   @brief          Integration Framework - SysDal scheduler implementation.
*   @details        SysDal scheduler implementation.
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
#include "SysDal.h"
#include "SysDal_IntSch.h"
#include "Gpt.h"
#include "sys_init.h"

/*===================================================================================================================
*                              SOURCE FILE VERSION INFORMATION
====================================================================================================================*/
#define SYSDAL_INTSCH_VENDOR_ID_C                       43

#define SYSDAL_INTSCH_AR_RELEASE_MAJOR_VERSION_C        4
#define SYSDAL_INTSCH_AR_RELEASE_MINOR_VERSION_C        2
#define SYSDAL_INTSCH_AR_RELEASE_REVISION_VERSION_C     2

#define SYSDAL_INTSCH_SW_MAJOR_VERSION_C                1
#define SYSDAL_INTSCH_SW_MINOR_VERSION_C                0
#define SYSDAL_INTSCH_SW_PATCH_VERSION_C                1
/*===================================================================================================================
*                                       FILE VERSION CHECKS
====================================================================================================================*/
/**
* @file           SysDal_IntSch.c
*/
/* Check if source file and SYSDAL_INTSCH header file are of the same vendor */
#if (SYSDAL_INTSCH_VENDOR_ID_C != SYSDAL_VENDOR_ID)
    #error "SysDal_IntSch.c and SysDal.h have different vendor ids"
#endif

/* Check if source file and SYSDAL header file are of the same Autosar version */
#if ((SYSDAL_INTSCH_AR_RELEASE_MAJOR_VERSION_C != SYSDAL_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_INTSCH_AR_RELEASE_MINOR_VERSION_C != SYSDAL_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_INTSCH_AR_RELEASE_REVISION_VERSION_C != SYSDAL_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal_IntSch.c and SysDal.h are different"
#endif

/* Check if source file and SYSDAL header file are of the same Software version */
#if ((SYSDAL_INTSCH_SW_MAJOR_VERSION_C != SYSDAL_SW_MAJOR_VERSION) || \
     (SYSDAL_INTSCH_SW_MINOR_VERSION_C != SYSDAL_SW_MINOR_VERSION) || \
     (SYSDAL_INTSCH_SW_PATCH_VERSION_C != SYSDAL_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal_IntSch.c and SysDal.h are different"
#endif

/* Check if source file and SYSDAL_INTSCH header file are of the same vendor */
#if (SYSDAL_INTSCH_VENDOR_ID_C != SYSDAL_INTSCH_VENDOR_ID)
    #error "SysDal_IntSch.c and SysDal_IntSch.h have different vendor ids"
#endif

/* Check if source file and SYSDAL header file are of the same Autosar version */
#if ((SYSDAL_INTSCH_AR_RELEASE_MAJOR_VERSION_C != SYSDAL_INTSCH_AR_RELEASE_MAJOR_VERSION) || \
     (SYSDAL_INTSCH_AR_RELEASE_MINOR_VERSION_C != SYSDAL_INTSCH_AR_RELEASE_MINOR_VERSION) || \
     (SYSDAL_INTSCH_AR_RELEASE_REVISION_VERSION_C != SYSDAL_INTSCH_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of SysDal_IntSch.c and SysDal_IntSch.h are different"
#endif

/* Check if source file and SYSDAL header file are of the same Software version */
#if ((SYSDAL_INTSCH_SW_MAJOR_VERSION_C != SYSDAL_INTSCH_SW_MAJOR_VERSION) || \
     (SYSDAL_INTSCH_SW_MINOR_VERSION_C != SYSDAL_INTSCH_SW_MINOR_VERSION) || \
     (SYSDAL_INTSCH_SW_PATCH_VERSION_C != SYSDAL_INTSCH_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of SysDal_IntSch.c and SysDal_IntSch.h are different"
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
#if defined(AUTOSAR_OS_NOT_USED)

#if (INTAPP_TASK_1_ENABLE == STD_ON)    
volatile uint16  SysDal_IntSch_Task1_Time = 0U;
volatile boolean SysDal_IntSch_Task1_isActive = FALSE;
#endif

#if (INTAPP_TASK_2_ENABLE == STD_ON)    
volatile uint16  SysDal_IntSch_Task2_Time = 0U;
volatile boolean SysDal_IntSch_Task2_isActive = FALSE;
#endif

#if (INTAPP_TASK_3_ENABLE == STD_ON)    
volatile uint16  SysDal_IntSch_Task3_Time = 0U;
volatile boolean SysDal_IntSch_Task3_isActive = FALSE;
#endif

#if (INTAPP_TASK_4_ENABLE == STD_ON)    
volatile uint16  SysDal_IntSch_Task4_Time = 0U;
volatile boolean SysDal_IntSch_Task4_isActive = FALSE;
#endif

#if (INTAPP_TASK_5_ENABLE == STD_ON)    
volatile uint16  SysDal_IntSch_Task5_Time = 0U;
volatile boolean SysDal_IntSch_Task5_isActive = FALSE;
#endif

#if (INTAPP_TASK_6_ENABLE == STD_ON)    
volatile uint16  SysDal_IntSch_Task6_Time = 0U;
volatile boolean SysDal_IntSch_Task6_isActive = FALSE;
#endif

#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/**
@brief This is the global variable that holds all the sample app specific data
*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if defined(AUTOSAR_OS_NOT_USED)
/**
@brief      SysDal_IntSch_StopScheduler - Start Internal scheduler
@details    

@return     none
@retval     none

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_IntSch_StartScheduler(void)
{
    Gpt_EnableNotification(SYSDAL_SCH_GPT_TIMER_CHANNEL);
    Gpt_StartTimer(SYSDAL_SCH_GPT_TIMER_CHANNEL, GPT_SCH_TICKS);
}


/**
@brief      SysDal_IntSch_StopScheduler - Stop Internal scheduler
@details    

@return     none
@retval     none

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_IntSch_StopScheduler(void)
{
    Gpt_StopTimer(SYSDAL_SCH_GPT_TIMER_CHANNEL);
    Gpt_DisableNotification(SYSDAL_SCH_GPT_TIMER_CHANNEL);    
}


/**
@brief      SysDal_IntSch_TaskActivationIsr - Interrupt handler for round-robin scheduler
@details    

@return     none
@retval     none

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_IntSch_TaskActivationIsr(void)
{
    /* Setup all the needed interrupts(and their priorities) */
    sys_disableAllInterrupts();

#if (INTAPP_TASK_1_ENABLE == STD_ON)    
    SysDal_IntSch_Task1_Time++;
#endif

#if (INTAPP_TASK_2_ENABLE == STD_ON)    
    SysDal_IntSch_Task2_Time++;
#endif

#if (INTAPP_TASK_3_ENABLE == STD_ON)    
    SysDal_IntSch_Task3_Time++;     
#endif

#if (INTAPP_TASK_4_ENABLE == STD_ON)    
    SysDal_IntSch_Task4_Time++;
#endif

#if (INTAPP_TASK_5_ENABLE == STD_ON)    
    SysDal_IntSch_Task5_Time++;
#endif

#if (INTAPP_TASK_6_ENABLE == STD_ON)    
    SysDal_IntSch_Task6_Time++;     
#endif     
  
#if (INTAPP_TASK_1_ENABLE == STD_ON)      
    if (SysDal_IntSch_Task1_Time >= INTAPP_TASK_1_ACTIVATION_TIME)
    {
       SysDal_IntSch_Task1_Time = 0U;       
       SysDal_IntSch_Task1_isActive = TRUE;
    }
#endif 

#if (INTAPP_TASK_2_ENABLE == STD_ON)     
    if (SysDal_IntSch_Task2_Time >= INTAPP_TASK_2_ACTIVATION_TIME)
    {
       SysDal_IntSch_Task2_Time = 0U;       
       SysDal_IntSch_Task2_isActive = TRUE;
    }
#endif 

#if (INTAPP_TASK_3_ENABLE == STD_ON)    
    if (SysDal_IntSch_Task3_Time >= INTAPP_TASK_3_ACTIVATION_TIME)
    {
        SysDal_IntSch_Task3_Time = 0U;       
        SysDal_IntSch_Task3_isActive = TRUE;
    }
#endif 

#if (INTAPP_TASK_4_ENABLE == STD_ON)   
    if (SysDal_IntSch_Task4_Time >= INTAPP_TASK_4_ACTIVATION_TIME)
    {
        SysDal_IntSch_Task4_Time = 0U;       
        SysDal_IntSch_Task4_isActive = TRUE;
    }
#endif 

#if (INTAPP_TASK_5_ENABLE == STD_ON)    
    if (SysDal_IntSch_Task5_Time >= INTAPP_TASK_5_ACTIVATION_TIME)
    {
        SysDal_IntSch_Task5_Time = 0U;       
        SysDal_IntSch_Task5_isActive = TRUE;
    }
#endif 

#if (INTAPP_TASK_6_ENABLE == STD_ON)   
    if (SysDal_IntSch_Task6_Time >= INTAPP_TASK_6_ACTIVATION_TIME)
    {
        SysDal_IntSch_Task6_Time = 0U;       
        SysDal_IntSch_Task6_isActive = TRUE;
    }
#endif   
    
    /* Enable external Interrupts */
    sys_enableAllInterrupts();
}



/**
@brief      SysDal_IntSch_TaskScheduler - Interal round-robin scheduler
@details    

@return     Returns the value of success
@retval     E_OK or E_NOT_OK

@pre None
@post None
*/
FUNC (void, SAMPLE_APP_CODE) SysDal_IntSch_TaskScheduler(void)
{
    /* local variables here */
    INTAPP_PREHOOK_TASK();
    
    while (1)
    {

#if (INTAPP_TASK_1_ENABLE == STD_ON) /**/
        if (TRUE == SysDal_IntSch_Task1_isActive)
        {
            SysDal_IntSch_Task1_isActive = FALSE;  
            /* call Task 1 */
            INTAPP_TASK_1();
        }
#endif 

#if (INTAPP_TASK_2_ENABLE == STD_ON)  
        if (TRUE == SysDal_IntSch_Task2_isActive)
        {
            SysDal_IntSch_Task2_isActive = FALSE;  
            /* call Task 2 */
            INTAPP_TASK_2();
        }
#endif      
     
#if (INTAPP_TASK_3_ENABLE == STD_ON)      
        if (TRUE == SysDal_IntSch_Task3_isActive)
        {
            SysDal_IntSch_Task3_isActive = FALSE;  
            /* call Task 3 */
            INTAPP_TASK_3();
        }
#endif 


#if (INTAPP_TASK_4_ENABLE == STD_ON) 
        if (TRUE == SysDal_IntSch_Task4_isActive)
        {
            SysDal_IntSch_Task4_isActive = FALSE;  
            /* call Task 4 */
            INTAPP_TASK_4();
        }
#endif 

#if (INTAPP_TASK_5_ENABLE == STD_ON)  
        if (TRUE == SysDal_IntSch_Task5_isActive)
        {
            SysDal_IntSch_Task5_isActive = FALSE;  
            /* call Task 5 */
            INTAPP_TASK_5();
        }
#endif      
     
#if (INTAPP_TASK_6_ENABLE == STD_ON)      
        if (TRUE == SysDal_IntSch_Task6_isActive)
        {
            SysDal_IntSch_Task6_isActive = FALSE;  
            /* call Task 6 */
            INTAPP_TASK_6();
        }
#endif         
    }
}
#endif

/*================================================================================================*/

#ifdef __cplusplus
}
#endif
