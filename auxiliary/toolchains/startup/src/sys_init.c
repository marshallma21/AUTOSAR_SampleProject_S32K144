/*================================================================================================*/
/**
*    @file        sys_init.c
*    @version     1.0.1
*
*    @brief       Integration Framework - System initialization code
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
extern "C" {
#endif

    
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "typedefs.h"
#include "StdRegMacros.h"
#ifdef S32K118
    #include "s32k118.h"
#endif
#ifdef S32K142
    #include "s32k142.h"
#endif
#ifdef S32K144
    #include "s32k144.h"
#endif
#ifdef S32K146
    #include "s32k146.h"
#endif
#ifdef S32K148
    #include "s32k148.h"
#endif

#include "nvic.h"
#include "sys_init.h"
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
uint32_t  DummyVar=0x56788765;
/*==================================================================================================
*                                       GLOBAL VARIABLES
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
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    extern uint32_t startup_getControlRegisterValue(void);
    extern uint32_t startup_getAipsRegisterValue(void);
#endif
void startup_go_to_user_mode(void);

/*================================================================================================*/
/**
* @brief    startup_go_to_user_mode
* @details  Function called from startup.s to switch to user mode if MCAL_ENABLE_USER_MODE_SUPPORT
*           is defined
*/
/*================================================================================================*/
void startup_go_to_user_mode(void)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    ASM_KEYWORD("svc 0x1");
#endif
}

/*================================================================================================*/
/**
* @brief Sys_GoToSypervisor
* @details function used to enter to supervisor mode.
            check if it's needed to switch to supervisor mode and make the switch.
            Return 1 if switch was done
*/
/*================================================================================================*/

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT

/* check if it's needed to switch to supervisor mode and make the switch.
Return 1 if switch was done */
uint8_t Sys_GoToSupervisor(void)
{
    uint32_t u32ControlRegValue;
    uint32_t u32AipsRegValue;
    uint8_t  u8SwithcToSupervisor;
    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();
    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0UL == (u32ControlRegValue & 1)) || (0 < (u32AipsRegValue & 0xFF)))
    {
        u8SwithcToSupervisor = 0U;
    }
    else
    {
        u8SwithcToSupervisor = 1U;
        Mcal_goToSupervisor();
    }
    return u8SwithcToSupervisor;
}

/*================================================================================================*/
/**
* @brief Sys_ToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32_t value passed as parameter
*/
/*================================================================================================*/
uint32_t Sys_GoToUser_Return(uint8_t u8SwithcToSupervisor, uint32_t u32returnValue)
{
      if(1UL == u8SwithcToSupervisor)
      {
        Mcal_goToUser();
      }
      return u32returnValue;
}

/*make the switch back to user mode for Thread mode, return 0. */
 uint32_t Sys_GoToUser(void)
{
        Mcal_goToUser();
        return 0UL;
}
#endif
/*=================================================================================================*/

/* To Initialize both caches, make these two function calls
 *  m4_cache_init(CODE_CACHE);
 *  m4_cache_init(SYS_CACHE);
 */

uint8_t m4_cache_init(uint8_t cache)
{

  if (cache == CODE_CACHE)
  {
      /* Code Cache Init */

      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      LMEM->PCCCR = 0x05000000;

      /* set ccr[go] bit to initiate command to invalidate cache */
      LMEM->PCCCR |= LMEM_PCCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((LMEM->PCCCR & LMEM_PCCCR_GO_MASK) == LMEM_PCCCR_GO_MASK);

      /* enable cache */
      LMEM->PCCCR |= LMEM_PCCCR_ENCACHE(1);

  }else if (cache == SYS_CACHE)
  {
#if 0
      /* System Cache Init */

      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      LMEM->PSCCR = 0x05000000;

      /* set ccr[go] bit to initiate command to invalidate cache */
      LMEM->PSCCR |= LMEM_PSCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((LMEM->PSCCR & LMEM_PSCCR_GO_MASK) == LMEM_PSCCR_GO_MASK);

      /* enable write buffer */
      LMEM->PSCCR |= LMEM_PSCCR_ENWRBUF(1);

      /* enable cache */
      LMEM->PSCCR |= LMEM_PSCCR_ENCACHE(1);
#endif
  } else
  {
     return CACHE_INVALID_PARAM;
  }

  return CACHE_OK;
}


uint8_t m4_cache_disable(uint8_t cache)
{

  if (cache == CODE_CACHE)
  {
       /* Disable code cache */
       LMEM->PCCCR = 0;

  }else if (cache == SYS_CACHE)
  {
       /* Disable system cache */
       /*LMEM->PSCCR = 0; */

  } else
  {
     return CACHE_INVALID_PARAM;
  }

  return CACHE_OK;
}


uint8_t m4_cache_invalidate(uint8_t cache)
{

  if (cache == CODE_CACHE)
  {
      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      LMEM->PCCCR = 0x05000000; /* set INVW0 and INVW1 */

      /* set ccr[go] bit to initiate command to invalidate cache */
      LMEM->PCCCR |= LMEM_PCCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((LMEM->PCCCR & LMEM_PCCCR_GO_MASK) == LMEM_PCCCR_GO_MASK);

  }else if (cache == SYS_CACHE)
  {
#if 0
      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      LMEM.PSCCR.R = 0x05000000; /* set INVW0 and INVW1 */

      /* set ccr[go] bit to initiate command to invalidate cache */
      LMEM->PSCCR |= LMEM_PSCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((LMEM->PSCCR & LMEM_PSCCR_GO_MASK) == LMEM_PSCCR_GO_MASK);
#endif
  } else
  {
     return CACHE_INVALID_PARAM;
  }

  return CACHE_OK;

}

uint8_t m4_cache_flush(uint8_t cache)
{

  if (cache == CODE_CACHE)
  {
      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      LMEM->PCCCR = 0x0A000000; /* set INVW0 and INVW1 */

      /* set ccr[go] bit to initiate command to invalidate cache */
      LMEM->PCCCR |= LMEM_PCCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((LMEM->PCCCR & LMEM_PCCCR_GO_MASK) == LMEM_PCCCR_GO_MASK);

  }else if (cache == SYS_CACHE)
  {
#if 0     
      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      LMEM->PSCCR = 0x0A000000; /* set INVW0 and INVW1 */

      /* set ccr[go] bit to initiate command to invalidate cache */
      LMEM->PSCCR |= LMEM_PSCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((LMEM->PSCCR & LMEM_PSCCR_GO_MASK) == LMEM_PSCCR_GO_MASK);
#endif      
  } else
  {
     return CACHE_INVALID_PARAM;
  }

  return CACHE_OK;
}

uint8_t m4_cache_invalidate_buffer(uint32_t start_addr, long size)
{
  /* 32B line size => number of loops = size to invalidate divided by line size in bits plus 1 */
  uint32_t loops = size/32;
  uint32_t addr = start_addr;
  uint32_t i;
  
  for (i=0; i<loops; i++,addr+=32){
    /* LACC 27        - Read:             0x0  */
    /* LADSEL 26      - Physical Address: 0x1  */
    /* LCMD 25-24     - Invalidate:       0x01 */
    /* TDSEL 16       - Data:             0x0  */
    /* WSEL 14        - Way 0:            0x0  */
    LMEM->PCCLCR = 0x05000000;
    
    /* set physical address as start address with 2 LSB dropped */
    LMEM->PCCSAR = addr&0xFFFFFFFC;
    
    /* set csar[lgo] to initiate command indicated by bits 27-24 in clcr */
    LMEM->PCCSAR |= LMEM_PCCSAR_LGO(1);
    
    /* wait until the csar[lgo] bit clears to indicate command complete */
    while((LMEM->PCCSAR & LMEM_PCCSAR_LGO_MASK) == LMEM_PCCSAR_LGO_MASK);
  }
  
  return CACHE_OK;
}

uint8_t m4_cache_flush_buffer(uint32_t start_addr, long size)
{
  /* 32B line size => number of loops = size to invalidate divided by line size in bits plus 1 */
  uint32_t loops = size/32;
  uint32_t addr = start_addr;
  uint32_t i;
  
  for (i=0; i<loops; i++,addr+=32){
    /* LACC 27        - Read:             0x0  */
    /* LADSEL 26      - Physical Address: 0x1  */
    /* LCMD 25-24     - Push:             0x10 */
    /* TDSEL 16       - Data:             0x0  */
    /* WSEL 14        - Way 0:            0x0  */
    LMEM->PCCLCR = 0x06000000;
    
    /* set physical address as start address with 2 LSB dropped */
    LMEM->PCCSAR = addr&0xFFFFFFFC;
    
    /* set csar[lgo] to initiate command indicated by bits 27-24 in clcr */ 
    LMEM->PCCSAR |= LMEM_PCCSAR_LGO(1);
    
    /* wait until the csar[lgo] bit clears to indicate command complete */
    while((LMEM->PCCSAR & LMEM_PCCSAR_LGO_MASK) == LMEM_PCCSAR_LGO_MASK);
  }
  
  return CACHE_OK;
}

/** 
* @brief sys_init
* @details function used to enable all interrupts
*/
void sys_enableAllInterrupts(void)
{
    ResumeAllInterrupts();
}
/** 
* @brief sys_init
* @details function used to disable all interrupts
*/
void sys_disableAllInterrupts(void)
{
    SuspendAllInterrupts();
}
/** 
* @brief sys_init
* @details function used to disable the interrupt number id
*/
void sys_disableIsrSource(uint8_t id)
{
    NVIC_DisableIRQ(id);
}
/** 
* @brief sys_init
* @details function used to enable the interrupt number id and set up the priority
*/
void sys_enableIsrSource(uint8_t id, uint8_t prio)
{
    NVIC_SetPriority(id, prio);
    NVIC_EnableIRQ(id);
}
/** 
* @brief sys_init
* @details function used to register the interrupt handler in the interrupt vector
*/
void  sys_registerIsrHandler(uint8_t irq_id, uint32_t isr_handler)
{

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
	Mcal_goToSupervisor();
#endif
   REG_WRITE32(S32_SCB->VTOR + ((16 + irq_id) << 2), isr_handler);
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
	Mcal_goToUser();
#endif   

}
    
#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 

#ifdef __ICCARM__ 
/* Initialize RAM variables and RAM functions */
void Scatter_Loading(void)
{

    volatile char * from; 
    volatile char * to;     
    volatile uint32_t length;   

#pragma language=extended 
    /* Relocate the INT Vect table */
    #pragma section = "AppIntVec_Init"
    #pragma section = "AppIntVec"
    from = (char *)__segment_begin("AppIntVec_Init");
    to = (char *)__segment_begin("AppIntVec");
    length = __segment_size("AppIntVec");

     while(length--)
    {
        *to++ = *from++;

    }
    
    /* Relocate the  RAM code */
    #pragma section = "AppRAMCode"
    #pragma section = "AppRAMCode_Init"
    from = (char *)__segment_begin("AppRAMCode_Init");
    to = (char *)__segment_begin("AppRAMCode");
    length = __segment_size("AppRAMCode");
    while(length--)
    {
        *to++ = *from++;
    }
        
    /* Init DATA section */
    #pragma section = "AppData"
    #pragma section = "AppData_Init"
    from = (char *)__segment_begin("AppData_Init");
    to = (char *)__segment_begin("AppData");
    length = __segment_size("AppData");
    while(length--)
    {
        *to++ = *from++;
    }
    
    /* Init DATA NO_CACHE section */
    #pragma section = "AppData_NO_CACHE"
    #pragma section = "AppData_NO_CACHE_Init"
    from = (char *)__segment_begin("AppData_NO_CACHE_Init");
    to = (char *)__segment_begin("AppData_NO_CACHE");
    length = __segment_size("AppData_NO_CACHE");
    while(length--)
    {
        *to++ = *from++;
    }
    #pragma language=default
}
#endif /* #ifdef __ICCARM__ */


/*
 * system initialization : system clock, interrupt router ...
 */
void SystemInit(void)
{

    NVIC_SetPriorityGrouping(0); /* 0 means 7 bits for prio, 1 for sub-prio */

    S32_SCB->CCR    |=  1;       /**< processor can enter Thread mode from any level under the 
                                   control of an EXC_RETURN value, PendSV priority set to 0*/
    REG_BIT_CLEAR32(&(S32_SCB->SHPR3), S32_SCB_SHPR3_PRI_14_MASK); 
    
    /* enable the AIPS */
    AIPS->MPRA = 0x77777777;      
    AIPS->PACR[0]  = 0x0; 
    AIPS->PACR[1]  = 0x0; 
    AIPS->PACR[2]  = 0x0;  
    AIPS->PACR[3]  = 0x0; 
    AIPS->OPACR[0] = 0x0; 
    AIPS->OPACR[1] = 0x0; 
    AIPS->OPACR[2] = 0x0; 
    AIPS->OPACR[3] = 0x0; 
    AIPS->OPACR[4] = 0x0; 
    AIPS->OPACR[5] = 0x0; 
    AIPS->OPACR[6] = 0x0; 
    AIPS->OPACR[7] = 0x0; 
    AIPS->OPACR[8] = 0x0; 
    AIPS->OPACR[9] = 0x0; 
    AIPS->OPACR[10] = 0x0;
    AIPS->OPACR[11] = 0x0;
   
  
#if 0
    /* Enable speculative prefetching for program flash (flash bank 0) */
	MSCM->OCMDR[0] |= MSCM_OCMDR_OCMC1(2);
	/* Enable speculative prefetching for data flash (flash bank 1) */
	MSCM->OCMDR[1] |= MSCM_OCMDR_OCMC1(2);
#endif
	/* Configure slave ports to fixed-priority arbitration (default after reset) */
	MCM->CPCR &= ~MCM_CPCR_CBRR_MASK;

	/* Configure the SRAM_L and SRAM_U arbitration scheme to fixed priority (processor has highest, backdoor has lowest) */
	MCM->CPCR = MCM_CPCR_SRAMLAP(2) | MCM_CPCR_SRAMUAP(2); 
 
    
#ifdef D_CACHE_ENABLE    
    /*init Data caches*/
    m4_cache_init(SYS_CACHE);
#endif

#ifdef I_CACHE_ENABLE  
    /*init Code caches*/
    m4_cache_init(CODE_CACHE);
#endif

    
}


/*================================================================================================*/
/**
* @brief sys_halt
* @details function used to enter halt mode
*/
/*================================================================================================*/
void sys_halt(void)
{
 
    EXECUTE_WAIT();
}
/*================================================================================================*/
/**
* @brief sys_stop
* @details function used to enter stop mode
*/
/*================================================================================================*/
void sys_stop(void)
{
    EXECUTE_WAIT();
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes =
#endif

#ifdef __cplusplus
}
#endif
