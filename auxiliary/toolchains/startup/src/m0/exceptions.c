/*================================================================================================*/
/**
*   @file    exceptions.c
*   @version 1.0.1
*
*   @brief   AUTOSAR IntegrationFramework - Interrupts table for M4
*   @details Interrupts table for M4
*            This file contains sample code only. It is not part of the production code deliverables
*   @addtogroup BUILD_ENV
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : ARM
*   Peripheral           : LPit
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : S32K14x_MCAL_1_0_1_RTM_ASR_REL_4_2_REV_0002_20170831
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017-2018 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifdef __cplusplus
void "C" {
#endif


#include "sys_init.h"
#include "Mcal.h"

#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 

#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 

void NMI_Handler(void);               /* NMI Handler */
void HardFault_Handler(void);         /* Hard Fault Handler */
void MemManage_Handler(void);         /* Reserved */
void BusFault_Handler(void);          /* Bus Fault Handler */
void UsageFault_Handler(void);        /* Usage Fault Handler */
void SVC_Handler(void);               /* SVCall Handler */
void DebugMon_Handler(void);          /* Debug Monitor Handler */
void PendSV_Handler(void);            /* PendSV Handler */
void SysTick_Handler(void);           /* SysTick Handler */
void undefined_handler(void);         /* Undefined Handler */
void SVCHandler_main(unsigned int * svc_args);
void NMI_Handler(void)
{
    while(1);
}
void HardFault_Handler(void)
{
    while(1);
}
void MemManage_Handler(void)
{
    while(1);
}
void BusFault_Handler(void)
{
    while(1);
}
void UsageFault_Handler(void)
{
    while(1);
}
void SVC_Handler(void)
{
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    while(1);
#else
    /*Load in R0 the stack pointer (depneding on context from which SVC is called)*/
    ASM_KEYWORD("MOVS r0, #4");
    ASM_KEYWORD("MOV r1, LR");
    ASM_KEYWORD("TST r0, r1");
    ASM_KEYWORD("BEQ stacking_used_MSP \n"
                "MRS R0, PSP \n"
                "b       SVCHandler_main \n"
        "stacking_used_MSP: \n"
                "MRS R0, MSP \n"
                "b       SVCHandler_main"
                );
#endif
}

void SVCHandler_main(unsigned int * svc_args)
{
    unsigned int svc_number;    /* Stack contains:    * r0, r1, r2, r3, r12, r14, the return address and xPSR   */
                                /* First argument (r0) is svc_args[0]  */
    /* svc_args[6] =  SP + 0x18  PC(r15) */
    /* ((char *)svc_args[6])[-2]; = first two bytes, lsb, of the instruction which caused the SVC */
    /* this will nto work if optimization compiler options are changed*/
    svc_number = ((char *)svc_args[6])[-2];
    switch(svc_number)
    {
        case 1:
            /* Handle SVC 01*/
            ASM_KEYWORD("ldr   r0, =0x00000001");   /* Set User mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 0:
            /* Handle SVC 00*/
            ASM_KEYWORD("ldr   r0, =0x00000000");   /* Set Supervisor mode for Thread mode */
            ASM_KEYWORD("msr   CONTROL, r0");
            break;
        case 2:
            /* Handle SVC 02*/
            ASM_KEYWORD(" cpsie i"); /* Resume all interrupts */
            break;
        case 3:
            /* Handle SVC 03*/
            ASM_KEYWORD(" cpsid i"); /* Suspend all interrupts */
            break;
        default:
            /* Unknown SVC*/
            break;
    }
}
void DebugMon_Handler(void)
{
    while(1);
}
void PendSV_Handler(void)
{
    while(1);
}
void SysTick_Handler(void)
{
    while(1);
}
void undefined_handler(void)
{
   while(1);
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes =
#endif

#ifdef __cplusplus
}
#endif



