/*=================================================================================================*/
/**
*   @file    Startup.c
*   @version 1.0.1
*
*   @brief   AUTOSAR IntegrationFramework - Startup file for ARM.
*   @details Startup file for ARM.
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

    MODULE startup.s



    EXTERN VTABLE

/************************************************************************/
/* Autosar synopsis of startup code (See MCU Specification):            */
/*                                                                      */
/*   Before the MCU driver can be initialized, a basic initialization   */
/*   of the MCU has to be executed. This MCU specific initialization is */
/*   typically executed in a start-up code. The start-up code of the    */
/*   MCU shall be executed after power up and any kind of micro-        */
/*   controller reset. It shall perform very basic and microcontroller  */
/*   specific start-up initialization and shall be kept short, because  */
/*   the MCU clock and PLL is not yet initialized. The start-up code    */
/*   shall cover MCU specific initialization, which is not part of      */
/*   other MCU services or other MCAL drivers. The following steps      */
/*   summarizes basic functionality which shall be included in the      */
/*   start-up code. They are listed for guidance, because some          */
/*   functionality might not be supported. No code will be found in     */
/*   case.                                                              */
/************************************************************************/
    PUBLIC Reset_Handler 
    PUBLIC _start
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    PUBLIC startup_getControlRegisterValue
    PUBLIC startup_getAipsRegisterValue
#endif

    EXTERN SystemInit
    EXTERN Scatter_Loading
    EXTERN startup_go_to_user_mode
    EXTERN main
    EXTERN _Stack_start
    EXTERN __STACK_SIZE
    
    
    EXTERN INT_SRAM_START  
    EXTERN INT_SRAM_SIZE   
    EXTERN INT_SRAM_END    

    
VTOR_REG EQU 0xE000ED08
    
  
    SECTION .startup : CODE (2)
    THUMB
    
Reset_Handler
_start    
    
/*****************************************************/
/* Skip normal entry point as nothing is initialized */
/*****************************************************/
    movs   r0, #0
    movs   r1, #0
    movs   r2, #0
    movs   r3, #0
    movs   r4, #0
    movs   r5, #0
    movs   r6, #0
    movs   r7, #0

 
/*******************************************************************/
/* Freescale Guidance 1 - Init registers to avoid lock-step issues */
/* N/A                                                             */
/*******************************************************************/

/*******************************************************************/
/* Freescale Guidance 2 - MMU Initialization for CPU               */
/*  TLB0 - PbridgeB                                                */
/*  TLB1 - Internal Flash                                          */
/*  TLB2 - External SRAM                                           */
/*  TLB3 - Internal SRAM                                           */
/*  TLB4 - PbridgeA                                                */ 
/*******************************************************************/
    
/******************************************************************/
/* Autosar Guidance 1 - The start-up code shall initialize the    */
/* base addresses for interrupt and trap vector tables. These base*/
/* addresses are provided as configuration parameters or          */
/* linker/locator setting.                                        */
/******************************************************************/

    /* relocate vector table to RAM */
    ldr  r0, =VTOR_REG
    ldr  r1, =VTABLE
    /* ;ldr  r2, =(1 << 29)
    ;orr  r1, r2 *//* r1 = r1 | r2 */
    str  r1,[r0]
    
/******************************************************************/
/* Autosar Guidance 2 - The start-up code shall initialize the    */
/* interrupt stack pointer, if an interrupt stack is              */
/* supported by the MCU. The interrupt stack pointer base address */
/* and the stack size are provided as configuration parameter or  */
/* linker/locator setting.                                        */
/*                                                                */
/******************************************************************/


/******************************************************************/
/* Autosar Guidance 3 - The start-up code shall initialize the    */
/* user stack pointer. The user stack pointer base address and    */
/* the stack size are provided as configuration parameter or      */
/* linker/locator setting.                                        */
/******************************************************************/

    /* set up stack; r13 SP*/
    ldr  r0, =_Stack_start
    msr MSP, r0
    
/******************************************************************/
/* Autosar Guidance 4 - If the MCU supports context save          */
/* operation, the start-up code shall initialize the memory which */
/* is used for context save operation. The maximum amount of      */
/* consecutive context save operations is provided as             */
/* configuration parameter or linker/locator setting.             */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 5 - The start-up code shall ensure that the   */
/* MCU internal watchdog shall not be serviced until the watchdog */
/* is initialized from the MCAL watchdog driver. This can be      */
/* done for example by increasing the watchdog service time.      */
/*                                                                */
/******************************************************************/
/* disable WDG */
/* The watchdog has a restrictive timing. It has to be configured and unlocked within a peripod
  of 128 cycles. Therefor the unlock sequence need to be done by a small target program. */
  
    ldr  r0, =0x40052004
    ldr  r1, =0xD928C520
    ldr  r2, =0x40052008
    ldr  r3, =0x0000FFFF
    ldr  r4, =0x40052000
    ldr  r5, =0x00002120

    str  r1, [r0]  /* SD:0x40052004 = 0xD928C520   Unlock */
    str r3, [r2]   /* SD:0x40052008 = 0xFFFF       maximum timeout value*/
    str  r5, [r4]  /* SD:0x40052000 = 0x2120       disable Wdg */

/******************************************************************/
/* Autosar Guidance 6 - If the MCU supports cache memory for data */
/* and/or code, it shall be initialized and enabled in the        */
/* start-up code.                                                 */
/*                                                                */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 7 - The start-up code shall initialize MCU    */
/* specific features of internal memory like memory protection.   */
/*                                                                */
/******************************************************************/
 
/******************************************************************/
/* Autosar Guidance 8 - If external memory is used, the memory    */
/* shall be initialized in the start-up code. The start-up code   */
/* shall be prepared to support different memory configurations   */
/* depending on code location. Different configuration options    */
/* shall be taken into account for code execution from            */
/* external/internal memory.                                      */
/* N/A - external memory is not used                              */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 9 - The settings of the different memories    */
/* shall be provided to the start-up code as configuration        */
/* parameters.                                                    */
/* N/A - all memories are already configured                      */
/******************************************************************/
 
/******************************************************************/
/* Autosar Guidance 10 - In the start-up code a default           */
/* initialization of the MCU clock system shall be performed      */
/* including global clock prescalers.                             */
/******************************************************************/
    bl SystemInit

/******************************************************************/
/* Autosar Guidance 11 - The start-up code shall enable           */
/* protection mechanisms for special function registers(SFR’s),   */
/* if supported by the MCU.                                       */
/* N/A - will be handled by Autosar OS                            */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 12 - The start-up code shall initialize all   */
/* necessary write once registers or registers common to several  */
/* drivers where one write, rather than repeated writes, to the   */
/* register is required or highly desirable.                      */
/******************************************************************/

/******************************************************************/
/* Autosar Guidance 13 - The start-up code shall initialize a     */
/* minimum amount of RAM in order to allow proper execution of    */
/* the MCU driver services and the caller of these services.      */
/******************************************************************/
/* MPC574xP - internal ram must be initialized for error correction*/
/******************************************************************/
#ifndef SINTRAM  /* SINTRAM defined by compiler option -DSINTRAM only for INTRAM build */
/************************/
/* Erase "RAM Sections" */
/************************/


/* Zero fill the bss segment */
  ldr  r2, =INT_SRAM_START
  ldr  r4, =INT_SRAM_END

  movs   r5, #0
  movs   r3, #0
FillZerobss
  str   r5, [r2]
  movs   r3, #4
  add   r2, r2, r3
  cmp   r2, r4
  bcc   FillZerobss

/* initialize all RAM functions and DATA sections */
    bl Scatter_Loading

#endif


/*********************************/
/* Set the small ro data pointer */
/*********************************/
 

/*********************************/
/* Set the small rw data pointer */
/*********************************/

/******************************************************************/
/* Call Main Routine                                              */
/******************************************************************/
    bl startup_go_to_user_mode
    bl main

/******************************************************************/
/* Init runtime check data space                                  */
/******************************************************************/


MCAL_LTB_TRACE_OFF:
    nop
    
#ifdef CCOV_ENABLE
    /* code coverage is requested */
    bl ccov_main
#endif
  
    BKPT #1 /* last instruction for the debugger to dump results data */

    b . 
    
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
startup_getControlRegisterValue:
 MRS r0, CONTROL
 BX r14


startup_getAipsRegisterValue:
 MRS r0, IPSR
 BX r14
#endif

     SECTION .stack_main : DATA (4)
#ifdef __STACK_SIZE
Stack_Size EQU __STACK_SIZE
#else
Stack_Size EQU 0x0400
#endif
    DS8 Stack_Size

#ifndef SINTRAM 
    SECTION .rcw: DATA (4)
/* configure boot */
    DC32    0x00001000	  /* 0x00 stacksize*/
    DC32    _start		  /* 0x10 start address */
  
    SECTION .flash_config: DATA (4)
    PUBLIC __FlashConfig
__FlashConfig:
    DC32	0xFFFFFFFF /* 8 bytes backdoor comparison key*/
    DC32	0xFFFFFFFF 
    DC32	0xFFFFFFFF /* 4 bytes program flash protection bytes */
    DC32	0xFFFFFFFE /* FDPROT:FEPROT:FOPT:FSEC */    
#endif
    end
