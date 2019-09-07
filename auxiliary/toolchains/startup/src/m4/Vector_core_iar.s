/*==================================================================================================
*   @file    Vector_core_iar.s
*   @version 1.0.1
*
*   @brief   Integration Framework - Intrerrupt vector definition for ARM (for IAR).
*   @details Intrerrupt vector definition for ARM (for IAR).
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
    
    MODULE vector_core.s

    SECTION .intc_vector : DATA (2)


    EXTERN undefined_handler
    PUBLIC VTABLE
    EXTERN _Stack_start              /* Top of Stack for Initial Stack Pointer */
    EXTERN Reset_Handler             /* Reset Handler */
    EXTERN NMI_Handler               /* NMI Handler */
    EXTERN HardFault_Handler         /* Hard Fault Handler */
    EXTERN MemManage_Handler         /* Reserved */
    EXTERN BusFault_Handler          /* Bus Fault Handler */
    EXTERN UsageFault_Handler        /* Usage Fault Handler */
    EXTERN SVC_Handler               /* SVCall Handler */
    EXTERN DebugMon_Handler          /* Debug Monitor Handler */
    EXTERN PendSV_Handler            /* PendSV Handler */
    EXTERN SysTick_Handler           /* SysTick Handler */ /* 15*/
    
VTABLE
    DCD _Stack_start              /* Top of Stack for Initial Stack Pointer */
    DCD Reset_Handler             /* Reset Handler */
    DCD NMI_Handler               /* NMI Handler */
    DCD HardFault_Handler         /* Hard Fault Handler */
    DCD MemManage_Handler         /* Reserved */
    DCD BusFault_Handler          /* Bus Fault Handler */
    DCD UsageFault_Handler        /* Usage Fault Handler */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD 0                         /* Reserved */
    DCD SVC_Handler               /* SVCall Handler */
    DCD DebugMon_Handler          /* Debug Monitor Handler */
    DCD 0                         /* Reserved */
    DCD PendSV_Handler            /* PendSV Handler */
    DCD SysTick_Handler           /* SysTick Handler */ /* 15*/
    
    DCD undefined_handler /*0*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*10*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*20*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler 
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*30*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*39*/
    DCD undefined_handler /*40*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*48*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*64*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*80*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*96*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*112*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*112*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*128*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*144*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*160*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*176*/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*192/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    
    /* External interrupts */
    DCD undefined_handler /*208/
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler
    DCD undefined_handler /*223*/

   
  /*  VTABLE DS8 .-VTABLE */
    
    END